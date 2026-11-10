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

START, END = 0x004B2AC0, 0x004B44BA
SOURCE = ROOT / 'workbench/nagamori-cpu/Character06Cpu.cpp'
OBJECT = ROOT / 'build/nagamori-cpu/Character06Cpu.partial.obj'


def instructions(data, path):
    """Original/candidate disassembly retaining branch edges as well as forms."""
    path.write_bytes(data)
    result = subprocess.run([
        'objdump', '-D', '-b', 'binary', '-m', 'i386', '-Mintel',
        '--adjust-vma=' + hex(START), str(path)],
        capture_output=True, check=True, text=True).stdout
    parsed = []
    edges = {}
    for line in result.splitlines():
        match = re.match(r'^\s*([0-9a-f]+):\s+(?:[0-9a-f]{2}\s+)+\s*\t(.+)', line)
        if not match:
            continue
        addr = int(match[1], 16)
        op = match[2]
        branch = re.match(r'^(j\w+)\s+(?:0x)?([0-9a-f]+)\b', op)
        if branch:
            edges[addr] = int(branch[2], 16)
        op = re.sub(r'\b(j\w+)\s+(?:0x)?[0-9a-f]+', r'\1 DEST', op)
        op = re.sub(r'\bcall\s+(?:0x)?[0-9a-f]+', 'call TARGET', op)
        op = re.sub(r'(QWORD|DWORD) PTR ds:0x[0-9a-f]+',
                    r'\1 PTR ds:CONST', op)
        parsed.append((addr, op))
    return parsed, edges


def verify_internal_branches(target, candidate, original_edges, built_edges):
    """Check destinations by instruction ordinal, allowing size shifts.

    Target branches beyond the recovered prefix intentionally have no verified
    candidate destination: they can point to the unreconstructed shared exit.
    """
    target_index = {address: i for i, (address, _) in enumerate(target)}
    candidate_index = {address: i for i, (address, _) in enumerate(candidate)}
    checked = 0
    for i, (address, _) in enumerate(target[:-1]):
        destination = original_edges.get(address)
        target_ordinal = target_index.get(destination)
        if target_ordinal is None or target_ordinal >= len(target) - 1:
            continue
        draft_addr = candidate[i][0]
        draft_target = built_edges.get(draft_addr)
        draft_ordinal = candidate_index.get(draft_target)
        if draft_ordinal != target_ordinal:
            raise AssertionError(
                f'branch at source instruction {i}, original {address:#x} '
                f'jumped to instruction {target_ordinal}, but draft '
                f'{draft_addr:#x} jumped to {draft_ordinal}')
        checked += 1
    assert checked >= 215, checked
    return checked


def main():
    original = target_bytes(verify_target(), START, END-START)
    compile_source(SOURCE, OBJECT, ['/Od', '/G6', '/MT', '/Gy', '/W3'],
                   ROOT / '.analysis/build/nagamori-cpu-workbench.log')
    code, relocs = object_function(OBJECT, '?Slot05@Character06@@UAEXXZ')
    target_records, original_edges = instructions(original, ROOT / 'build/nagamori-cpu/target-prefix.bin')
    built_records, built_edges = instructions(code, ROOT / 'build/nagamori-cpu/draft-prefix.bin')
    target = [op for _, op in target_records]
    built = [op for _, op in built_records]
    # The target prefix is stable even when additional, still-incomplete
    # source branches are appended. Only its aligned original instructions
    # and in-prefix control-flow edges are audited.
    assert len(original) == 6650 and len(target) == 1745
    assert hashlib.sha256(original).hexdigest() == '36ac9b4431122a619058eb5acc943b1c6cb492e80a28bbd50efbbda9138abc40'
    assert len(code) == 6646 and len(built) == 1747 and len(relocs) == 124
    assert target[2] == 'sub    esp,0xe8'
    assert built[2] == 'sub    esp,0xb8'
    assert all(t == b for i, (t, b) in
               enumerate(zip(target[:-1], built[:-3])) if i != 2)
    edges = verify_internal_branches(target_records, built_records, original_edges, built_edges)
    assert edges == 215, edges
    # Catch the previous bug: both attack choices must be covered by this
    # six-byte near JNZ, not a short jump into the second choice.
    assert original[0x6b2:0x6b8] == code[0x6b2:0x6b8]
    assert target[-1] == 'jmp DEST'
    assert built[-3:] == ['mov    esp,ebp', 'pop    ebp', 'ret']
    print('Nagamori Slot05 original opening: 1743/1744 aligned instruction')
    print('forms and operands match, normalizing direct call/branch targets')
    print('and original FP constant addresses. Only the unfinished stack')
    print('allocation differs. This is NOT complete-function Exact.')
    print('Internal branch destinations verified:', edges)
    print('Original prefix: 6650 bytes / 1745 instructions.')
    print('Partial compiled owner:',len(code),'bytes /',len(built),'instructions,',
          len(relocs),'COFF relocations; target whole owner is 15292 bytes.')
    print('Stack: original 0xE8, candidate',built[2])
    print('Original prefix SHA256:', hashlib.sha256(original).hexdigest())



if __name__ == '__main__':
    main()
