"""Selected canonical Nayuki Character10 Slot04 input/action prefix native audit.

A partial workbench comparison, never a full-function Exact certificate.
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

START, FULL_SIZE, END = 0x00461460, 10605, 0x0046235F
FULL_SHA = "9b36e02745b63428693a1fd39258d2fbbbccfdc120f2d16d915073fedde5806d"
PREFIX_SHA = "ddfa95a85b9fa949c7aba50bf072feedd0f86a2129c9b276aa2295dd505fc821"
SOURCE = ROOT / "workbench/nayuki-action/Character10Action.cpp"
OBJECT = ROOT / "build/nayuki-action/Character10Action.partial.obj"


def disasm(data):
    text = subprocess.run(
        ["ndisasm", "-b32", "-o0", "-"], input=data,
        capture_output=True, check=True,
    ).stdout.decode()
    return [(int(a, 16), bytes.fromhex(bits), ins)
            for a, bits, ins in re.findall(
                r"^([0-9A-F]+)\s+([0-9A-F]+)\s+(.+)$", text, re.M)]


def normalized(ins):
    if re.match(r"^(?:j\w+|call)\s+(?:(?:short|near)\s+)?0x[0-9a-f]+$", ins):
        return re.sub(
            r"^(\S+)\s+(?:(?:short|near)\s+)?0x[0-9a-f]+$",
            r"\1 DEST", ins)
    return re.sub(r"\[dword 0x[0-9a-f]+\]", "[dword LITERAL]", ins)


def main():
    im = verify_target()
    assert struct.unpack("<I", target_bytes(im, 0x00788280, 4))[0] == START
    full = target_bytes(im, START, FULL_SIZE)
    assert hashlib.sha256(full).hexdigest() == FULL_SHA
    assert full[-5:] == bytes.fromhex("5b 8b e5 5d c3")
    assert target_bytes(im, START + FULL_SIZE, 3) == b"\xcc"*3

    prefix = full[:END - START]
    assert len(prefix) == 3839
    assert hashlib.sha256(prefix).hexdigest() == PREFIX_SHA
    compile_source(SOURCE, OBJECT, ["/Od", "/G6", "/MT", "/Gy", "/W3"],
                   ROOT / ".analysis/build/nayuki-action-prefix.log")
    code, reloc = object_function(OBJECT, "?Slot04@Character10@@UAEXXZ")
    original, candidate = disasm(prefix), disasm(code)
    assert len(original) == 962 and len(candidate) >= len(original)
    original_pos = {v[0]:i for i,v in enumerate(original)}
    candidate_pos = {v[0]:i for i,v in enumerate(candidate)}
    full_pos = {v[0] for v in disasm(full)}
    for i, (t, c) in enumerate(zip(original, candidate)):
        assert t[0] == c[0], (i, t, c)
        assert t[1] == c[1] or normalized(t[2]) == normalized(c[2]), (i,t,c)
        assert len(t[1]) == len(c[1]), (i, t, c)
        assert normalized(t[2]) == normalized(c[2]), (i,t,c)
    assert candidate[len(original)][0] == len(prefix)

    inside=outside=0
    for t,c in zip(original,candidate):
        a = re.search(r"^j\w+\s+(?:(?:short|near)\s+)?0x([0-9a-f]+)$", t[2])
        if not a:
            continue
        b = re.search(r"^j\w+\s+(?:(?:short|near)\s+)?0x([0-9a-f]+)$", c[2])
        assert b
        target, draft = int(a[1], 16), int(b[1], 16)
        assert target in full_pos, t
        if target in original_pos:
            inside += 1
            assert original_pos[target] == candidate_pos.get(draft), (t,c)
        else:
            outside += 1
    assert (inside, outside) == (147, 16)

    starts=[i[0] for i in candidate]
    symbols=defaultdict(set)
    nrel=0
    for r in reloc:
        if r["offset"] >= len(prefix):
            continue
        nrel += 1
        idx=bisect_right(starts,r["offset"])-1
        field = original[idx][0] + r["offset"] - candidate[idx][0]
        assert field + 4 <= original[idx][0] + len(original[idx][1])
        raw=struct.unpack_from("<I",prefix,field)[0]
        target=(raw if r["type"]=="DIR32" else
                (START+field+4+struct.unpack_from("<i",prefix,field)[0])&0xffffffff)
        if r["symbol"].startswith("__real@"):
            assert r["type"]=="DIR32"
            bits=bytes.fromhex(r["symbol"][len("__real@"):])[::-1]
            assert target_bytes(im,target,len(bits))==bits,(r,hex(target))
        else:
            assert r["type"]=="REL32" and target==0x0040F170,(r,hex(target))
        symbols[(r["symbol"],r["type"])].add(target)
    assert nrel==33 and len(symbols)==3
    assert all(len(v)==1 for v in symbols.values())
    print("Nayuki Slot04: 3839 / 10605 original bytes,")
    print("962/962 instruction forms, 147 internal original branches,")
    print("16 valid outbound branches, and 33 target-bound relocations.")
    print("This is a PARTIAL native source checkpoint, not complete Exact.")


if __name__=="__main__":
    main()
