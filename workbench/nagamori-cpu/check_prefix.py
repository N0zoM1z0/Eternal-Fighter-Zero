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

START, END = 0x004B2AC0, 0x004B3891
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
    # The complete target owner ends at 0x4B667C. This is a deliberately
    # partial native source; only the audited opening range can match.
    assert len(original) == 3537 and len(target) == 974
    assert len(code) == 3529 and len(built) == 976 and len(relocs) == 86
    assert target[2] == 'sub    esp,0xe8' and built[2] == 'sub    esp,0xa8'
    assert all(t == b for i, (t, b) in
               enumerate(zip(target[:-1], built[:-3])) if i != 2)
    assert target[-1] == 'jmp DEST'
    assert built[-3:] == ['mov    esp,ebp', 'pop    ebp', 'ret']
    print('Nagamori Slot05 original opening: 972/973 aligned instruction')
    print('forms and operands match (normalizing branch/call destinations')
    print('and original FP constant addresses); final target JMP absent')
    print('because the candidate is a partial owner.')
    print('Original reviewed 3537-byte prefix / 974 instructions;')
    print('compiled candidate 3529 bytes / 976 incl. temporary epilogue;')
    print('15,292-byte whole owner remains incomplete.')
    print('Stack: target sub esp,0xE8; partial sub esp,0xA8.')
    print('Original prefix SHA256:', hashlib.sha256(original).hexdigest())



if __name__ == '__main__':
    main()
