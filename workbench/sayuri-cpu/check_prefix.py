"""Review native Sayuri Slot05 CPU prefix only, with no full-owner Exact claim."""
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

START, FULL_SIZE = 0x0044AB30, 12330
END = 0x0044CC86
FULL_SHA = "359e3d5a58dcae61c77acdcfdd0b70bb247f8b497880c8317d75f8ad78c2acc5"
PREFIX_SHA = "51d0973f6f6c87a843d5f7fa4ae686c377b2a7c69f6b576124f03e580fa90847"
SOURCE = ROOT / "workbench/sayuri-cpu/Character09Cpu.cpp"
OBJECT = ROOT / "build/sayuri-cpu/Character09Cpu.partial.obj"


def disasm(data):
    output = subprocess.run(
        ["ndisasm", "-b32", "-o0", "-"], input=data,
        stdout=subprocess.PIPE, stderr=subprocess.PIPE, check=True,
    ).stdout.decode()
    return [(int(addr, 16), bytes.fromhex(raw), opcode)
            for addr, raw, opcode in re.findall(
                r"^([0-9A-F]+)\s+([0-9A-F]+)\s+(.+)$", output, re.M)]


def form(opcode):
    if re.match(r"^(?:j\w+|call)\s+(?:(?:short|near)\s+)?0x[0-9a-f]+$", opcode):
        return re.sub(
            r"^(\S+)\s+(?:(?:short|near)\s+)?0x[0-9a-f]+$",
            r"\1 DEST", opcode)
    return re.sub(r"\[dword 0x[0-9a-f]+\]", "[dword CONST]", opcode)


def main():
    im = verify_target()
    assert struct.unpack("<I", target_bytes(im, 0x0078814C, 4))[0] == START
    original = target_bytes(im, START, FULL_SIZE)
    assert hashlib.sha256(original).hexdigest() == FULL_SHA
    assert original[-4:] == bytes.fromhex("8b e5 5d c3")
    assert target_bytes(im, START + FULL_SIZE, 6) == b"\xcc" * 6
    prefix = original[:END - START]
    assert hashlib.sha256(prefix).hexdigest() == PREFIX_SHA

    compile_source(SOURCE, OBJECT, ["/Od", "/G6", "/MT", "/Gy", "/W3"],
                   ROOT / ".analysis/build/sayuri-cpu-workbench.log")
    code, rels = object_function(OBJECT, "?Slot05@Character09@@UAEXXZ")
    target, compiled = disasm(prefix), disasm(code)
    assert (len(prefix), len(target), len(code), len(compiled), len(rels)) == (
        8534, 2157, 8527, 2159, 146)
    assert target[2][2] == "sub esp,0xd8"
    assert compiled[2][2] == "sub esp,0xc4"
    assert [x[2] for x in compiled[-3:]] == ["mov esp,ebp", "pop ebp", "ret"]
    assert target[-1][2] == "jmp 0x3026"
    for i, (a, b) in enumerate(zip(target[:-1], compiled[:-3])):
        if i != 2:
            assert form(a[2]) == form(b[2]), (i, a, b)
    widths = [(i, a[2], b[2]) for i, (a, b) in enumerate(
        zip(target[:-1], compiled[:-3])) if len(a[1]) != len(b[1])]
    assert widths == [(2131, "jmp 0x3026", "jmp short 0x214b"), (2150, "jmp 0x3026", "jmp short 0x214b")]

    originals = {row[0]: i for i, row in enumerate(target)}
    drafts = {row[0]: i for i, row in enumerate(compiled)}
    all_original_positions = {row[0] for row in disasm(original)}
    inside, outside = 0, 0
    for a, b in zip(target[:-1], compiled[:-3]):
        am = re.search(r"^j\w+\s+(?:(?:short|near)\s+)?0x([0-9a-f]+)$", a[2])
        if not am:
            continue
        bm = re.search(r"^j\w+\s+(?:(?:short|near)\s+)?0x([0-9a-f]+)$", b[2])
        assert bm is not None, (a, b)
        orig_dest, draft_dest = int(am[1], 16), int(bm[1], 16)
        assert orig_dest in all_original_positions, a
        if orig_dest in originals and originals[orig_dest] < len(target) - 1:
            inside += 1
            assert originals[orig_dest] == drafts.get(draft_dest), (a, b)
        else:
            outside += 1
    assert (inside, outside) == (276, 91)

    starts = [insn[0] for insn in compiled]
    bindings = defaultdict(set)
    for r in rels:
        idx = bisect_right(starts, r["offset"]) - 1
        assert 0 <= idx < len(target) - 1
        field = target[idx][0] + r["offset"] - compiled[idx][0]
        assert field + 4 <= target[idx][0] + len(target[idx][1]), r
        raw = struct.unpack_from("<I", prefix, field)[0]
        if r["type"] == "DIR32":
            addr = raw
            assert r["symbol"].startswith("__real@"), r
            bits = bytes.fromhex(r["symbol"][len("__real@"):])[::-1]
            assert target_bytes(im, addr, len(bits)) == bits, (r, hex(addr))
        else:
            assert r["type"] == "REL32"
            addr = (START + field + 4 +
                    struct.unpack_from("<i", prefix, field)[0]) & 0xffffffff
            assert (r["symbol"], addr) in {
                ("?RandomRange@Secondary@@QAEFFF@Z", 0x004108A0),
                ("_fabs", 0x0077842D),
            }
        bindings[(r["symbol"], r["type"])].add(addr)
    assert len(bindings) == 29 and all(len(x) == 1 for x in bindings.values())
    print("Sayuri Slot05 CPU: 8534 / 12330 original code bytes,")
    print("2155/2156 comparable instruction forms, one incomplete stack frame,")
    print("276 original in-prefix jump targets, 91 reviewed outbound jumps,")
    print("146 independently original-bound COFF relocations (29 symbols).")
    print("This is a PARTIAL diagnostic, NEVER a complete Exact receipt.")


if __name__ == "__main__":
    main()
