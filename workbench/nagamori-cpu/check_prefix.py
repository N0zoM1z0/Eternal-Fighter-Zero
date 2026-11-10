"""Compile only Nagamori Slot05's recovered opening AI decision prefix.

This is a target instruction comparison, not full-function Exact.
"""
from pathlib import Path
from bisect import bisect_right
import hashlib
import re
import subprocess
import sys

ROOT = Path(__file__).resolve().parents[2]
sys.path.insert(0, str(ROOT / 'scripts'))
from common import verify_target, target_bytes
from coff import object_function
from native_build import compile_source

START, END = 0x004B2AC0, 0x004B5C25
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
    assert checked == 445, checked
    return checked


def verify_float_literals(image, original, target_records, built_records, relocations):
    """Check original IEEE-754 bytes for every source COFF float relocation.

    A normalized instruction can hide a wrong constant (for example, 70.0
    vs the target's 135.0). Map relocation fields by instruction ordinal so
    branch-width changes in the partial source do not shift the lookup.
    This is still only a prefix diagnostic, not full relocation closure.
    """
    built_addresses = [address for address, _ in built_records]
    verified = 0
    for relocation in relocations:
        symbol = relocation["symbol"]
        if not symbol.startswith("__real@"):
            continue
        assert relocation["type"] == "DIR32", relocation
        bits = symbol.removeprefix("__real@")
        assert len(bits) in (8, 16), symbol
        expected = bytes.fromhex(bits)[::-1]
        field_address = START + relocation["offset"]
        index = bisect_right(built_addresses, field_address) - 1
        assert 0 <= index < len(target_records) - 1, relocation
        compiled_start = built_addresses[index]
        original_start = target_records[index][0]
        original_next = target_records[index + 1][0]
        compiled_next = built_addresses[index + 1]
        displacement = field_address - compiled_start
        assert (0 <= displacement and
                displacement + 4 <= compiled_next - compiled_start and
                displacement + 4 <= original_next - original_start), relocation
        target_offset = original_start - START + displacement
        address = int.from_bytes(original[target_offset:target_offset + 4], "little")
        actual = target_bytes(image, address, len(expected))
        assert actual == expected, (
            f"float literal mismatch @ {original_start + displacement:#x}: "
            f"{symbol} != target {address:#x} "
            f"({actual[::-1].hex()})")
        verified += 1
    return verified


def main():
    image = verify_target()
    original = target_bytes(image, START, END-START)
    compile_source(SOURCE, OBJECT, ['/Od', '/G6', '/MT', '/Gy', '/W3'],
                   ROOT / '.analysis/build/nagamori-cpu-workbench.log')
    code, relocs = object_function(OBJECT, '?Slot05@Character06@@UAEXXZ')
    target_records, original_edges = instructions(original, ROOT / 'build/nagamori-cpu/target-prefix.bin')
    built_records, built_edges = instructions(code, ROOT / 'build/nagamori-cpu/draft-prefix.bin')
    target = [op for _, op in target_records]
    built = [op for _, op in built_records]
    # The current original prefix ends in a shared-exit jump that the partial
    # C++ source cannot emit until the whole owner is reconstructed. Compare
    # the recoverable prefix and its internal control-flow destinations.
    assert len(original) == 12645 and len(target) == 3211
    assert hashlib.sha256(original).hexdigest() == 'baff0e79b3f6aeee3840f1c8b0091439056cff4a65795cdce0be1c20d5fba08b'
    assert len(code) == 12641 and len(built) == 3213 and len(relocs) == 228
    assert target[2] == 'sub    esp,0xe8'
    assert built[2] == 'sub    esp,0xd0'
    assert all(t == b for i, (t, b) in
               enumerate(zip(target[:-1], built[:-3])) if i != 2)
    edges = verify_internal_branches(target_records, built_records, original_edges, built_edges)
    assert edges == 445, edges
    literal_count = verify_float_literals(image, original, target_records, built_records, relocs)
    assert literal_count == 148, literal_count
    # Catch the previous bug: both attack choices must be covered by this
    # six-byte near JNZ, not a short jump into the second choice.
    assert original[0x6b2:0x6b8] == code[0x6b2:0x6b8]
    assert target[-1] == 'jmp DEST'
    assert built[-3:] == ['mov    esp,ebp', 'pop    ebp', 'ret']
    print('Nagamori Slot05 original opening: 3209/3210 aligned instruction')
    print('forms and operands match, normalizing direct call/branch targets')
    print('and original FP constant addresses. Only the unfinished stack')
    print('allocation differs. This is NOT complete-function Exact.')
    print('Internal branch destinations verified:', edges)
    print('Original IEEE-754 float literal bindings verified:', literal_count)
    print('Original prefix: 12645 bytes / 3211 instructions.')
    print('Partial compiled owner:',len(code),'bytes /',len(built),'instructions,',
          len(relocs),'COFF relocations; target whole owner is 15292 bytes.')
    print('Stack: original 0xE8, candidate',built[2])
    print('Original prefix SHA256:', hashlib.sha256(original).hexdigest())



if __name__ == '__main__':
    main()
