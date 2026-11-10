"""Focused original-bound Nayuki Character10 Slot05 native prefix comparison.

This script intentionally does not claim whole-function Exact acceptance.
"""
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

START = 0x004654A0
FULL_SIZE = 13259
END = 0x00466D6E
FULL_SHA = "fdff7abd73f6c362272c3360eab5da1473255c978572d685d02810e32f1472ce"
PREFIX_SHA = "c277b4472010e301dcc8f6a5909c399d27d2a98a65d3aa2c6240131090c42e73"
SOURCE = ROOT / "workbench/nayuki-cpu/Character10Cpu.cpp"
OBJECT = ROOT / "build/nayuki-cpu/Character10.partial.obj"


def instructions(data):
    text = subprocess.run(
        ["ndisasm", "-b32", "-o0", "-"], input=data,
        capture_output=True, check=True,
    ).stdout.decode()
    return [(int(addr, 16), bytes.fromhex(raw), opcode)
            for addr, raw, opcode in re.findall(
                r"^([0-9A-F]+)\s+([0-9A-F]+)\s+(.+)$", text, re.M)]


def normalized(op):
    if re.match(r"^(?:j\w+|call)\s+(?:(?:short|near)\s+)?0x[0-9a-f]+$", op):
        return re.sub(
            r"^(\S+)\s+(?:(?:short|near)\s+)?0x[0-9a-f]+$",
            r"\1 DEST", op)
    return re.sub(r"\[dword 0x[0-9a-f]+\]", "[dword CONST]", op)


def main():
    im = verify_target()
    assert struct.unpack("<I", target_bytes(im, 0x00788284, 4))[0] == START
    full = target_bytes(im, START, FULL_SIZE)
    assert hashlib.sha256(full).hexdigest() == FULL_SHA
    assert full[-4:] == bytes.fromhex("8be55dc3")
    partial = full[:END - START]
    assert hashlib.sha256(partial).hexdigest() == PREFIX_SHA

    compile_source(
        SOURCE, OBJECT, ["/Od", "/G6", "/MT", "/Gy", "/W3"],
        ROOT / ".analysis/build/nayuki-cpu-workbench.log")
    code, rels = object_function(OBJECT, "?Slot05@Character10@@UAEXXZ")
    target = instructions(partial)
    candidate = instructions(code)
    assert (len(partial), len(target), len(code), len(candidate), len(rels)) == (
        6350, 1650, 6343, 1652, 101)
    assert target[2][2] == "sub esp,0xc0"
    assert candidate[2][2] == "sub esp,0x94"
    assert target[-1][2] == "jmp 0x33c7"
    assert [x[2] for x in candidate[-3:]] == ["mov esp,ebp", "pop ebp", "ret"]
    widths = [(i, t[2], c[2]) for i, (t, c) in enumerate(
        zip(target[:-1], candidate[:-3])) if len(t[1]) != len(c[1])]
    assert widths == [(1618, "jmp 0x33c7", "jmp short 0x18c3"), (1634, "jmp 0x33c7", "jmp short 0x18c3")]
    for i, (t, c) in enumerate(zip(target[:-1], candidate[:-3])):
        if i == 2:
            continue
        assert normalized(t[2]) == normalized(c[2]), (i, t, c)

    target_positions = {x[0]: i for i, x in enumerate(target)}
    candidate_positions = {x[0]: i for i, x in enumerate(candidate)}
    full_positions = {x[0] for x in instructions(full)}
    inside, outside = 0, 0
    for t, c in zip(target[:-1], candidate[:-3]):
        a = re.search(r"^j\w+\s+(?:(?:short|near)\s+)?0x([0-9a-f]+)$", t[2])
        if not a:
            continue
        b = re.search(r"^j\w+\s+(?:(?:short|near)\s+)?0x([0-9a-f]+)$", c[2])
        assert b is not None, (t, c)
        ta, ca = int(a[1], 16), int(b[1], 16)
        assert ta in full_positions, t
        if ta in target_positions and target_positions[ta] < len(target) - 1:
            inside += 1
            assert target_positions[ta] == candidate_positions.get(ca), (
                t, c, target_positions[ta], candidate_positions.get(ca))
        else:
            outside += 1
    assert (inside, outside) == (223, 62)

    symbols = defaultdict(set)
    original_calls = {
        "?RandomRange@Secondary@@QAEFFF@Z": 0x004108A0,
        "_fabs": 0x0077842D,
    }
    starts = [ins[0] for ins in candidate]
    for rel in rels:
        idx = bisect_right(starts, rel["offset"]) - 1
        assert 0 <= idx < len(target) - 1
        pos = target[idx][0] + rel["offset"] - candidate[idx][0]
        assert pos + 4 <= target[idx][0] + len(target[idx][1])
        value = struct.unpack_from("<I", partial, pos)[0]
        dest = (value if rel["type"] == "DIR32" else
                (START + pos + 4 +
                 struct.unpack_from("<i", partial, pos)[0]) & 0xffffffff)
        if rel["symbol"].startswith("__real@"):
            assert rel["type"] == "DIR32"
            bits = bytes.fromhex(rel["symbol"][len("__real@"):])[::-1]
            assert target_bytes(im, dest, len(bits)) == bits, (rel, dest)
        else:
            assert rel["type"] == "REL32"
            assert original_calls[rel["symbol"]] == dest, (rel, dest)
        symbols[(rel["symbol"], rel["type"])].add(dest)
    assert len(symbols) == 27
    assert all(len(v) == 1 for v in symbols.values())

    print("Nayuki Slot05: 6350/13259 reviewed original bytes,")
    print("1648/1649 aligned forms, one incomplete original 0xC0 frame,")
    print("223 original internal edges and 62 valid outbound edges,")
    print("all 101 original-bound relocations with 27 distinct symbols.")
    print("Last original JMP and complete shared return remain open: NOT Exact.")


if __name__ == "__main__":
    main()
