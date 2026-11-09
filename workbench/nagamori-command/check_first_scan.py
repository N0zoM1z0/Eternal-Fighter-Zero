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
    original = target_bytes(verify_target(), START, SECOND_END - START)
    compile_source(SOURCE, OBJECT, ['/Od', '/G6', '/MT', '/Gy', '/W3'],
                   ROOT / '.analysis/build/nagamori-command-workbench.log')
    built, relocations = object_function(OBJECT, '?Slot02@Character06@@UAEXXZ')
    original_ins = original_instructions(original, ROOT / 'build/nagamori-command/target.bin')
    compiled_ins = original_instructions(built, ROOT / 'build/nagamori-command/partial.bin')
    assert len(original) == 855 and len(original_ins) == 253
    assert len(built) == 859 and len(compiled_ins) == 256 and len(relocations) == 1
    assert compiled_ins[:253] == original_ins
    assert compiled_ins[253:] == ['mov    esp,ebp', 'pop    ebp', 'ret']
    print('Nagamori first two priority command scans: 253/253 original x86 instructions match,')
    print('normalizing ONLY forward branch targets and PE constant addresses.')
    print('Original two scans: 855 bytes; partial source: 859 with temporary local epilogue.')
    print('Two-scan prefix SHA256:', hashlib.sha256(original).hexdigest())
    print('Entire Nagamori Slot02: 4917 bytes — NOT accepted Exact.')


if __name__ == '__main__':
    main()
