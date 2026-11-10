"""Focused original-PE verification of Nagamori command scans 1-2, not whole Exact."""
import hashlib
import re
import subprocess
import sys
from pathlib import Path

ROOT = Path(__file__).resolve().parents[2]
sys.path.insert(0, str(ROOT / 'scripts'))
from common import verify_target, target_bytes
from native_build import compile_source
from coff import object_function

START = 0x004B1780
FIRST_END = 0x004B191C
SECOND_END = 0x004B1AD7
THIRD_END = 0x004B1CE1
FOURTH_END = 0x004B1EEB
SOURCE = ROOT / 'workbench/nagamori-command/Character06Command.cpp'
OBJECT = ROOT / 'build/nagamori-command/Character06Command.partial.obj'


def original_instructions(data, path):
    path.write_bytes(data)
    out = subprocess.run(
        ['objdump', '-D', '-b', 'binary', '-m', 'i386', '-Mintel',
         '--adjust-vma=' + hex(START), str(path)],
        check=True, capture_output=True, text=True).stdout
    instructions = []
    for line in out.splitlines():
        match = re.match(r'^\s*([0-9a-f]+):\s+(?:[0-9a-f]{2}\s+)+\s*\t(.+)', line)
        if match:
            ins = match[2]
            ins = re.sub(r'\b(j\w+)\s+(?:0x)?[0-9a-f]+', r'\1 BRANCH', ins)
            ins = re.sub(r'(QWORD|DWORD) PTR ds:0x[0-9a-f]+',
                         r'\1 PTR ds:ORIGINAL_LITERAL', ins)
            instructions.append(ins)
    return instructions


def main():
    original = target_bytes(verify_target(), START, FOURTH_END - START)
    compile_source(SOURCE, OBJECT, ['/Od', '/G6', '/MT', '/Gy', '/W3'],
                   ROOT / '.analysis/build/nagamori-command-workbench.log')
    built, relocations = object_function(OBJECT, '?Slot02@Character06@@UAEXXZ')
    original_ins = original_instructions(original, ROOT / 'build/nagamori-command/target.bin')
    compiled_ins = original_instructions(built, ROOT / 'build/nagamori-command/partial.bin')
    assert len(original) == 1899 and len(original_ins) == 566
    assert len(built) == 1903 and len(compiled_ins) == 569 and len(relocations) == 2
    assert compiled_ins[:566] == original_ins
    assert compiled_ins[566:] == ['mov    esp,ebp', 'pop    ebp', 'ret']
    print('Nagamori first four priority command scans: 566/566 original x86 instructions match,')
    print('normalizing ONLY forward branch targets and PE constant addresses.')
    print('Original four scans: 1899 bytes; partial source: 1903 with temporary local epilogue.')
    print('Four-scan prefix SHA256:', hashlib.sha256(original).hexdigest())
    print('Entire Nagamori Slot02: 4917 bytes — NOT accepted Exact.')


if __name__ == '__main__':
    main()
