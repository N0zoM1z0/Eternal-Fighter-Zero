"""Target-bound diagnostic for first eleven Nagamori Slot04 priority actions.

This is not a whole-function Exact match. Normalize only original local
branch destinations, direct call addresses, x87 external constant operands,
and one compiler stack-frame width affected by the missing later actions.
"""
import hashlib
import re
import subprocess
import sys
from pathlib import Path

ROOT = Path(__file__).resolve().parents[2]
sys.path.insert(0, str(ROOT / "scripts"))
from common import verify_target, target_bytes
from coff import object_function
from native_build import compile_source

START = 0x004AE2E0
PREFIX_END = 0x004AEE7E
SOURCE = ROOT / "workbench/nagamori-action/Character06Input.cpp"
OBJECT = ROOT / "build/nagamori-action/Character06Input.partial.obj"


def disassemble(data: bytes, out_file: Path):
    out_file.write_bytes(data)
    output = subprocess.run(
        ["objdump", "-D", "-b", "binary", "-m", "i386", "-Mintel",
         "--adjust-vma=" + hex(START), str(out_file)],
        capture_output=True, text=True, check=True,
    ).stdout
    results = []
    for line in output.splitlines():
        match = re.match(r"^\s*([0-9a-f]+):\s+(?:[0-9a-f]{2}\s+)+\s*\t(.+)", line)
        if match:
            results.append((int(match[1], 16), match[2]))
    return results


def normalize_instruction(text: str) -> str:
    text = re.sub(r"\b(j\w+)\s+(?:0x)?[0-9a-f]+", r"\1 DEST", text)
    text = re.sub(r"\bcall\s+(?:0x)?[0-9a-f]+", "call DIRECT", text)
    text = re.sub(r"(QWORD|DWORD) PTR ds:0x[0-9a-f]+", r"\1 PTR ds:CONSTANT", text)
    return text


def main():
    original = target_bytes(verify_target(), START, PREFIX_END-START)
    compile_source(SOURCE, OBJECT, ["/Od", "/G6", "/MT", "/Gy", "/W3"],
                   ROOT / ".analysis/build/nagamori-action-probe.log")
    compiled, relocations = object_function(OBJECT, "?Slot04@Character06@@UAEXXZ")
    expected = disassemble(original, ROOT / "build/nagamori-action/verified-prefix.target.bin")
    actual = disassemble(compiled, ROOT / "build/nagamori-action/verified-prefix.compiled.bin")
    assert len(original) == 2974 and len(expected) == 731
    assert len(actual) == 734 and len(compiled) == 2976 and len(relocations) == 24
    assert expected[2][1] == "sub    esp,0x14" and actual[2][1] == "push   ecx"
    assert actual[-3:] == [(START+len(compiled)-4,"mov    esp,ebp"),
                           (START+len(compiled)-2,"pop    ebp"),
                           (START+len(compiled)-1,"ret")]
    mismatch = []
    for i,(a,b) in enumerate(zip(expected,actual)):
        if i == 2:continue  # later cases restore the 20-byte frame; not present yet
        if normalize_instruction(a[1]) != normalize_instruction(b[1]):
            mismatch.append((i,a,b))
    assert not mismatch, mismatch[:5]
    print("Nagamori Slot04 first 11 actions: 730/730 checked native"
          " instructions and operands match, aside from 1 incomplete frame size")
    print("Canonical original prefix:", len(original), "bytes,", len(expected), "instructions")
    print("Current partial function:", len(compiled), "bytes,", len(relocations), "COFF relocations; NOT full Exact")
    print("Canonical prefix SHA-256:", hashlib.sha256(original).hexdigest())


if __name__ == "__main__":
    main()
