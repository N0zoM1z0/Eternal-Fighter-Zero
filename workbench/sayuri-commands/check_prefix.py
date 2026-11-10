"""Target-bound native comparison of the reviewed Sayuri Slot02 opening, not Exact."""
from bisect import bisect_right
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

START = 0x004493C0
FULL_SIZE = 5995
END = 0x00449BA3
FULL_SHA = "e4aa3f06f35134fcecf1fc29caee30cacfc38fcad71244148689c41e17212436"
PREFIX_SHA = "5c06b95f6afa3c924b9255dc94cd3be8709e3845e373f429c9591b073e4aa742"
SOURCE = ROOT / "workbench/sayuri-commands/Character09Commands.cpp"
OBJECT = ROOT / "build/sayuri-commands/Character09Commands.partial.obj"


def instructions(data):
    output = subprocess.run(
        ["ndisasm", "-b32", "-o0", "-"], input=data,
        stdout=subprocess.PIPE, stderr=subprocess.PIPE, check=True,
    ).stdout.decode()
    return [(int(offset, 16), bytes.fromhex(raw), asm)
            for offset, raw, asm in re.findall(
                r"^([0-9A-F]+)\s+([0-9A-F]+)\s+(.+)$", output, re.M)]


def normalized(asm):
    return re.sub(r"0x[0-9a-f]+$", "DEST", asm) if re.match(
        r"^(?:j\w+|call)\s+(?:(?:short|near)\s+)?0x[0-9a-f]+$", asm
    ) else re.sub(r"\[dword 0x[0-9a-f]+\]", "[dword CONST]", asm)


def main():
    im = verify_target()
    assert struct.unpack("<I", target_bytes(im, 0x00788140, 4))[0] == START
    original = target_bytes(im, START, FULL_SIZE)
    assert hashlib.sha256(original).hexdigest() == FULL_SHA
    assert original[-4:] == bytes.fromhex("8be55dc3")
    assert target_bytes(im, START + FULL_SIZE, 8) == bytes.fromhex("cccccccccc558bec")
    prefix = original[:END - START]
    assert hashlib.sha256(prefix).hexdigest() == PREFIX_SHA

    compile_source(SOURCE, OBJECT, ["/Od", "/G6", "/MT", "/Gy", "/W3"],
                   ROOT / ".analysis/build/sayuri-command-workbench.log")
    code, rels = object_function(OBJECT, "?Slot02@Character09@@UAEXXZ")
    orig_instr, code_instr = instructions(prefix), instructions(code)
    assert (len(prefix), len(orig_instr), len(code), len(code_instr), len(rels)) == (
        2019, 607, 2023, 610, 4)
    assert orig_instr[2][2] == code_instr[2][2] == "sub esp,byte +0xc"
    assert [x[2] for x in code_instr[-3:]] == ["mov esp,ebp", "pop ebp", "ret"]
    assert all(normalized(a[2]) == normalized(b[2])
               for a, b in zip(orig_instr, code_instr[:-3]))

    target_positions = {a[0]: idx for idx, a in enumerate(orig_instr)}
    candidate_positions = {a[0]: idx for idx, a in enumerate(code_instr)}
    entire_positions = {x[0] for x in instructions(original)}
    inside = outside = 0
    for t, c in zip(orig_instr, code_instr[:-3]):
        a = re.search(r"^j\w+\s+(?:(?:short|near)\s+)?0x([0-9a-f]+)$", t[2])
        if a is None:
            continue
        b = re.search(r"^j\w+\s+(?:(?:short|near)\s+)?0x([0-9a-f]+)$", c[2])
        assert b is not None, (t, c)
        td, cd = int(a[1], 16), int(b[1], 16)
        assert td in entire_positions, ("not a canonical original boundary", hex(td))
        if td in target_positions:
            inside += 1
            assert target_positions[td] == candidate_positions.get(cd), (t, c)
        else:
            outside += 1
    assert (inside, outside) == (80, 7)

    starts = [a[0] for a in code_instr]
    for rel in rels:
        assert rel["type"] == "DIR32"
        assert rel["symbol"] == "__real@0000000000000000"
        idx = bisect_right(starts, rel["offset"]) - 1
        assert 0 <= idx < len(orig_instr)
        delta = rel["offset"] - code_instr[idx][0]
        off = orig_instr[idx][0] + delta
        assert off + 4 <= orig_instr[idx][0] + len(orig_instr[idx][1])
        address = struct.unpack_from("<I", prefix, off)[0]
        assert address == 0x007872F8
        assert target_bytes(im, address, 8) == b"\0"*8
    print("Sayuri Slot02: 2019 / 5995 original bytes, 607/607 instruction")
    print("forms/operands, 80 internal branches, 7 valid outbound destinations")
    print("and 4 original IEEE-754 double relocations verified. Not Exact.")


if __name__ == "__main__":
    main()
