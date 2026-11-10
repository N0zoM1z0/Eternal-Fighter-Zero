"""Compare only the reviewed Sayuri Slot04 native-source prefix; not Exact."""
from bisect import bisect_right
from collections import defaultdict
from pathlib import Path
import hashlib
import re
import struct
import subprocess
import sys

ROOT = Path(__file__).resolve().parents[2]
sys.path.insert(0, str(ROOT / "scripts"))
from common import verify_target, target_bytes
from native_build import compile_source
from coff import object_function

START = 0x00446780
FULL_SIZE = 11119
END = 0x00447CB0
ORIGINAL_SHA = "fd248e424f2ebcdddb59462a3101f653e9931e4053d53eb2af9a067e2c0bb286"
PREFIX_SHA = "5ba50c91574ca5fbc4642c0a5c508201209c4ed6effb95bc793df4df4d8d952d"
SOURCE = ROOT / "workbench/sayuri-action/Character09Input.cpp"
OBJECT = ROOT / "build/sayuri-action/Character09Input.partial.obj"


def instructions(data):
    result = subprocess.run(
        ["ndisasm", "-b32", "-o0", "-"], input=data,
        stdout=subprocess.PIPE, stderr=subprocess.PIPE, check=True,
    ).stdout.decode()
    return [(int(offset, 16), bytes.fromhex(raw), asm)
            for offset, raw, asm in re.findall(
                r"^([0-9A-F]+)\s+([0-9A-F]+)\s+(.+)$", result, re.M)]


def compare_text(s):
    if re.match(r"^(?:j\w+|call)\s+(?:(?:short|near)\s+)?0x[0-9a-f]+$", s):
        return re.sub(r"0x[0-9a-f]+$", "DEST", s)
    return re.sub(r"\[dword 0x[0-9a-f]+\]", "[dword CONST]", s)


def main():
    exe = verify_target()
    assert struct.unpack("<I", target_bytes(exe, 0x00788148, 4))[0] == START
    full = target_bytes(exe, START, FULL_SIZE)
    assert hashlib.sha256(full).hexdigest() == ORIGINAL_SHA
    assert full[-4:] == bytes.fromhex("8b e5 5d c3")
    assert target_bytes(exe, START + FULL_SIZE, 4) == bytes.fromhex("cc 55 8b ec")
    original = full[:END - START]
    assert hashlib.sha256(original).hexdigest() == PREFIX_SHA
    compile_source(SOURCE, OBJECT, ["/Od", "/G6", "/MT", "/Gy", "/W3"],
                   ROOT / ".analysis/build/sayuri-action-workbench.log")
    candidate, relocations = object_function(OBJECT, "?Slot04@Character09@@UAEXXZ")
    target_instr = instructions(original)
    draft_instr = instructions(candidate)
    assert (len(original), len(target_instr), len(candidate),
            len(draft_instr), len(relocations)) == (5424, 1354, 5421, 1356, 47)
    assert target_instr[2][2] == "sub esp,byte +0x14"
    assert draft_instr[2][2] == "push ecx"
    assert target_instr[-1][2] == "jmp 0x2b6b"
    assert [x[2] for x in draft_instr[-3:]] == ["mov esp,ebp", "pop ebp", "ret"]
    for i, (target, draft) in enumerate(zip(target_instr[:-1], draft_instr[:-3])):
        if i != 2:
            assert compare_text(target[2]) == compare_text(draft[2]), (
                i, hex(target[0]), target[2], draft[2])
    by_target = {v[0]: i for i, v in enumerate(target_instr)}
    by_draft = {v[0]: i for i, v in enumerate(draft_instr)}
    inside = outside = 0
    for i, (target, draft) in enumerate(zip(target_instr[:-1], draft_instr[:-3])):
        a = re.match(r"^j\w+\s+(?:(?:short|near)\s+)?0x([0-9a-f]+)$", target[2])
        b = re.match(r"^j\w+\s+(?:(?:short|near)\s+)?0x([0-9a-f]+)$", draft[2])
        if not a:
            continue
        assert b is not None, i
        ta, ca = int(a[1], 16), int(b[1], 16)
        if ta in by_target and by_target[ta] < len(target_instr)-1:
            inside += 1
            assert by_draft.get(ca) == by_target[ta], (
                i, target[2], draft[2], by_target[ta], by_draft.get(ca))
        else:
            outside += 1
    assert (inside, outside) == (206, 26)

    starts = [v[0] for v in draft_instr]
    observed = defaultdict(set)
    for row in relocations:
        off = row["offset"]
        i = bisect_right(starts, off) - 1
        assert 0 <= i < len(target_instr)-1
        field = target_instr[i][0] + off - draft_instr[i][0]
        assert field + 4 <= target_instr[i][0] + len(target_instr[i][1])
        raw = struct.unpack_from("<I", original, field)[0]
        if row["type"] == "DIR32":
            address = raw
            assert row["symbol"].startswith("__real@")
            expected = bytes.fromhex(row["symbol"].split("@")[1])[::-1]
            assert target_bytes(exe, address, len(expected)) == expected
        else:
            assert row["type"] == "REL32"
            address = (START + field + 4 +
                       struct.unpack_from("<i", original, field)[0]) & 0xffffffff
            assert (row["symbol"], address) in {
                ("?SetCharacterTint@Secondary@@QAEXEH@Z", 0x00410AC0),
                ("?ClearBufferedButtons@Secondary@@QAEXXZ", 0x0040F170),
            }
        observed[(row["symbol"], row["type"])].add(address)
    assert len(observed) == 4 and all(len(v) == 1 for v in observed.values())
    print("Sayuri Slot04: reviewed 5424 / 11119 original code bytes,")
    print("1352/1353 comparable forms, one incomplete frame and shared-exit jump;")
    print(inside, "in-prefix branches and", len(relocations),
          "independently verified original-bound relocation fields.")
    print("This diagnostic is partial and NEVER a complete Exact certificate.")


if __name__ == "__main__":
    main()
