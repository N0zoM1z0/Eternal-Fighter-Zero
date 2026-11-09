"""Focused full-owner native build of Ikumi Slot02, no whole-game cold replay."""
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
SCANS = [
    (0x006AB7E0, 0x006AB9D3, 153),
    (0x006AB9D3, 0x006ABC42, 193),
    (0x006ABC42, 0x006ABE3C, 148),
    (0x006ABE3C, 0x006AC046, 157),
    (0x006AC046, 0x006AC1D8, 119),
    (0x006AC1D8, 0x006AC350, 109),
    (0x006AC350, 0x006AC4CB, 109),
    (0x006AC4CB, 0x006AC64E, 113),
    (0x006AC64E, 0x006AC6E3, 40),
    (0x006AC6E3, 0x006AC7C6, 63),
    (0x006AC7C6, 0x006AC8A6, 63),
    (0x006AC8A6, 0x006AC987, 63),
    (0x006AC987, 0x006ACA68, 63),
    (0x006ACA68, 0x006ACB34, 56),
    (0x006ACB34, 0x006ACBFD, 56),
]
SIZE = 5153
SOURCE = ROOT / 'workbench/ikumi-commands/Character14Commands.cpp'
OBJECT = ROOT / 'build/ikumi-commands/Character14Commands.partial.obj'


def disasm(code, file):
    file.write_bytes(code)
    output = subprocess.run(
        ['objdump', '-D', '-b', 'binary', '-m', 'i386', '-Mintel',
         '--adjust-vma=' + hex(ORIGIN), str(file)],
        capture_output=True, text=True, check=True,
    ).stdout
    ins = []
    for line in output.splitlines():
        m = re.match(r'^\s*([0-9a-f]+):\s+(?:[0-9a-f]{2}\s+)+\s*\t(.+)', line)
        if m:
            ins.append(m[2])
    return ins


def main():
    assert len(SCANS) == 15 and SCANS[0][0] == ORIGIN
    assert all(x[1] == y[0] for x, y in zip(SCANS, SCANS[1:]))
    assert SCANS[-1][1] == ORIGIN + SIZE - 4
    target = target_bytes(verify_target(), ORIGIN, SIZE)
    compile_source(SOURCE, OBJECT, ['/Od', '/G6', '/MT', '/Gy', '/W3'],
                   ROOT / '.analysis/build/ikumi-commands-workbench.log')
    compiled, relocs = object_function(OBJECT, '?Slot02@Character14@@UAEXXZ')
    assert len(target) == len(compiled) == SIZE and not relocs
    assert compiled == target
    target_ins = disasm(target, ROOT / 'build/ikumi-commands/scans.original.bin')
    compiled_ins = disasm(compiled, ROOT / 'build/ikumi-commands/scans.compiled.bin')
    assert target_ins == compiled_ins
    assert len(target_ins) == sum(n for _, _, n in SCANS) + 3 == 1508
    print('Ikumi Slot02: full original 5153/5153 bytes EXACT, 1508/1508 instructions')
    print('All 15 input scans plus shared epilogue have exact native assembly;'
          ' zero relocations and zero masks.')
    print('SHA256:', hashlib.sha256(target).hexdigest())


if __name__ == '__main__':
    main()
