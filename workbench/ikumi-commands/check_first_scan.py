"""Focused VC7.1 check of Ikumi command scans 1 and 2 (NOT whole Exact)."""
import hashlib
import re
import subprocess
import sys
from pathlib import Path

ROOT = Path(__file__).resolve().parents[2]
sys.path.insert(0, str(ROOT / 'scripts'))
from common import verify_target, target_bytes
from coff import object_function
from native_build import compile_source

ORIGIN = 0x006AB7E0
FIRST_SCAN_END = 0x006AB9D3
SECOND_SCAN_END = 0x006ABC42
SOURCE = ROOT / 'workbench/ikumi-commands/Character14Commands.cpp'
OBJECT = ROOT / 'build/ikumi-commands/Character14Commands.partial.obj'


def disasm(code, file):
    file.write_bytes(code)
    out = subprocess.run(
        ['objdump', '-D', '-b', 'binary', '-m', 'i386', '-Mintel',
         '--adjust-vma=' + hex(ORIGIN), str(file)],
        capture_output=True, text=True, check=True,
    ).stdout
    inst = []
    for line in out.splitlines():
        match = re.match(r'^\s*([0-9a-f]+):\s+(?:[0-9a-f]{2}\s+)+\s*\t(.+)', line)
        if match:
            text = re.sub(r'\b(j\w+)\s+(?:0x)?[0-9a-f]+', r'\1 TARGET', match[2])
            inst.append(text)
    return inst


def main():
    original = target_bytes(verify_target(), ORIGIN, SECOND_SCAN_END - ORIGIN)
    compile_source(SOURCE, OBJECT, ['/Od', '/G6', '/MT', '/Gy', '/W3'],
                   ROOT / '.analysis/build/ikumi-commands-workbench.log')
    built, relocs = object_function(OBJECT, '?Slot02@Character14@@UAEXXZ')
    target_ins = disasm(original, ROOT / 'build/ikumi-commands/first-scan.original.bin')
    built_ins = disasm(built, ROOT / 'build/ikumi-commands/first-scan.compiled.bin')
    assert len(original) == 1122 and len(target_ins) == 346
    assert len(built) == 1126 and len(built_ins) == 349 and not relocs
    assert target_ins == built_ins[:346]
    assert built_ins[-3:] == ['mov    esp,ebp', 'pop    ebp', 'ret']
    first = target_bytes(verify_target(), ORIGIN, FIRST_SCAN_END - ORIGIN)
    second = target_bytes(verify_target(), FIRST_SCAN_END, SECOND_SCAN_END - FIRST_SCAN_END)
    assert len(first) == 499 and len(second) == 623
    print('Ikumi command scans 1 and 2: 346/346 original x86 instructions'
          ' match after normalizing only branch destinations; 1,122 target bytes')
    print('Full owner is 5,153 bytes; this 1,126-byte partial TU is NOT Exact.')
    print('Scan 1 SHA256:', hashlib.sha256(first).hexdigest())
    print('Scan 2 SHA256:', hashlib.sha256(second).hexdigest())


if __name__ == '__main__':
    main()
