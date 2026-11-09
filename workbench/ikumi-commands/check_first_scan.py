"""Check exact native instructions of recovered Ikumi command-scan prefix.

This verifies ONLY the prefix, not the full 5153-byte Slot02 owner.
No whole-repository build or cold replay runs.
"""
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
]
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
            inst.append(re.sub(r'\b(j\w+)\s+(?:0x)?[0-9a-f]+',
                               r'\1 TARGET', match[2]))
    return inst


def main():
    assert SCANS[0][0] == ORIGIN
    assert all(a[1] == b[0] for a, b in zip(SCANS, SCANS[1:]))
    full = target_bytes(verify_target(), ORIGIN, SCANS[-1][1] - ORIGIN)
    compile_source(SOURCE, OBJECT, ['/Od', '/G6', '/MT', '/Gy', '/W3'],
                   ROOT / '.analysis/build/ikumi-commands-workbench.log')
    built, relocs = object_function(OBJECT, '?Slot02@Character14@@UAEXXZ')
    original_inst = disasm(full, ROOT / 'build/ikumi-commands/scans.original.bin')
    compiled_inst = disasm(built, ROOT / 'build/ikumi-commands/scans.compiled.bin')
    expected_instructions = sum(s[2] for s in SCANS)
    assert len(original_inst) == expected_instructions
    assert len(built) >= len(full) and len(compiled_inst) == expected_instructions + 3
    assert not relocs and original_inst == compiled_inst[:expected_instructions]
    assert compiled_inst[-3:] == ['mov    esp,ebp', 'pop    ebp', 'ret']
    print(f'Ikumi first {len(SCANS)} command scans: {expected_instructions}/{expected_instructions}'
          f' original instructions match, normalizing only jump destinations; {len(full)} target bytes')
    print(f'Whole owner 5153 bytes remains NOT Exact; partial source {len(built)} bytes')
    for i, (start, stop, instruction_count) in enumerate(SCANS, 1):
        data = target_bytes(verify_target(), start, stop-start)
        print(f'Scan {i}: {len(data)} target bytes, {instruction_count} instructions,'
              f' SHA256 {hashlib.sha256(data).hexdigest()}')


if __name__ == '__main__':
    main()
