"""Compile only Nagamori Slot05's recovered opening AI decision prefix.

This is a target instruction comparison, not full-function Exact.
"""
from pathlib import Path
import hashlib
import re
import subprocess
import sys

ROOT = Path(__file__).resolve().parents[2]
sys.path.insert(0, str(ROOT / 'scripts'))
from common import verify_target, target_bytes
from coff import object_function
from native_build import compile_source

START, END = 0x004B2AC0, 0x004B31E3
SOURCE = ROOT / 'workbench/nagamori-cpu/Character06Cpu.cpp'
OBJECT = ROOT / 'build/nagamori-cpu/Character06Cpu.partial.obj'


def instructions(data, path):
    path.write_bytes(data)
    result = subprocess.run([
        'objdump', '-D', '-b', 'binary', '-m', 'i386', '-Mintel',
        '--adjust-vma=' + hex(START), str(path)],
        capture_output=True, check=True, text=True).stdout
    parsed = []
    for line in result.splitlines():
        match = re.match(r'^\s*([0-9a-f]+):\s+(?:[0-9a-f]{2}\s+)+\s*\t(.+)', line)
        if match:
            op = match[2]
            op = re.sub(r'\b(j\w+)\s+(?:0x)?[0-9a-f]+', r'\1 DEST', op)
            op = re.sub(r'\bcall\s+(?:0x)?[0-9a-f]+', 'call TARGET', op)
            op = re.sub(r'(QWORD|DWORD) PTR ds:0x[0-9a-f]+',
                        r'\1 PTR ds:CONST', op)
            parsed.append(op)
    return parsed


def main():
    original = target_bytes(verify_target(), START, END-START)
    compile_source(SOURCE, OBJECT, ['/Od', '/G6', '/MT', '/Gy', '/W3'],
                   ROOT / '.analysis/build/nagamori-cpu-workbench.log')
    code, relocs = object_function(OBJECT, '?Slot05@Character06@@UAEXXZ')
    target = instructions(original, ROOT / 'build/nagamori-cpu/target-prefix.bin')
    built = instructions(code, ROOT / 'build/nagamori-cpu/draft-prefix.bin')
    assert len(original) == 1827 and len(target) == 502
    assert len(code) == 1820 and len(built) == 505 and len(relocs) == 30
    assert target[2] == 'sub    esp,0xe8' and built[2] == 'sub    esp,0x60'
    assert all(t == b for i, (t, b) in enumerate(zip(target, built)) if i != 2)
    assert built[-3:] == ['mov    esp,ebp', 'pop    ebp', 'ret']
    print('Nagamori Slot05 original opening: 501/502 instruction forms match')
    print('Original 1827-byte prefix; 15292-byte whole owner remains incomplete')
    print('Stack: target sub esp,0xE8; partial sub esp,0x60 (remaining original locals absent)')
    print('Prefix SHA256:', hashlib.sha256(original).hexdigest())


if __name__ == '__main__':
    main()
