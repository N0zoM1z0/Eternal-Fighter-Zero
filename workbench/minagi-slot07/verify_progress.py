#!/usr/bin/env python3
"""Target-bound, locally scoped provisional verification for Minagi Slot07.

Checks original vtable, all 68 native effect dispatch IDs, pinned compiler
output, and independently resolved *direct* call counts. Not an Exact proof.
"""
from __future__ import annotations
import argparse
import collections
import hashlib
import json
import re
import struct
import subprocess
import sys
from pathlib import Path

ROOT = Path(__file__).resolve().parents[2]
sys.path.insert(0, str(ROOT/'scripts'))
from native_build import compile_source
from common import verify_target, target_bytes, sha256
from coff import object_function

ORIGINAL_START = 0x005B2D10
ORIGINAL_SIZE = 87798
ORIGINAL_VTABLE_SLOT = 0x0078895C
SOURCE = ROOT/'workbench/minagi-slot07/Character21Effects-natural.cpp'
OBJECT = ROOT/'build/minagi-slot07/Character21Effects-natural.obj'
EVIDENCE = ROOT/'docs/evidence/minagi-slot07-natural-progress.json'
SYMBOL = '?Slot07@Character21@@UAEXXZ'
FLAGS = ['/Od','/G6','/MT','/Gy','/W3']

# Obtained by native Ghidra switch-dispatch review; this set is not inferred
# from the candidate's source or its COFF data.
EXPECTED_TYPES = (
    list(range(400, 433)) + [436,437,440,441,442,443] +
    list(range(446, 470)) + list(range(495, 500))
)
assert len(EXPECTED_TYPES) == 68
EXPECTED_CALLS = {
    ('??0EffectSpawn@@QAE@XZ', 0x00405490): 1,
    ('?EmitEffect@Context@@QAEXPAUEffectSpawn@@@Z', 0x00407100): 7,
    ('?SetSceneTimer@Context@@QAEXH@Z', 0x004080C0): 4,
    ('?ApplyDamage@Secondary@@QAEXHN@Z', 0x004105A0): 1,
    ('?RandomRange@Secondary@@QAEFFF@Z', 0x004108A0): 18,
    ('?SetVerticalShake@Secondary@@QAEXHH@Z', 0x00410A10): 1,
    ('?SetHorizontalShake@Secondary@@QAEXHH@Z', 0x00410A80): 8,
    ('?ResetLocalEffectSpawn@Secondary@@QAEXPAUSecondaryEffectSpawn@@@Z', 0x00413090): 1,
    ('_rand', 0x00777D61): 16,
    ('__ftol2', 0x007783B8): 37
}


def native_direct_calls(code: bytes) -> collections.Counter:
    # Decode E8 calls at instruction boundaries (not arbitrary byte patterns).
    p = ROOT/'.analysis/probes/minagi-slot07/original-verify.bin'
    p.parent.mkdir(parents=True, exist_ok=True)
    p.write_bytes(code)
    disassembly = subprocess.run([
        'objdump','-w','-D','-b','binary','-m','i386','-Mintel',
        f'--adjust-vma={ORIGINAL_START}',str(p)
    ],text=True,capture_output=True,check=True).stdout
    result: collections.Counter = collections.Counter()
    for line in disassembly.splitlines():
        match = re.search(r'\bcall\s+0x([0-9a-fA-F]+)\b',line)
        if match: result[int(match.group(1),16)] += 1
    return result


def ordered_call_sites(code: bytes, name: str, original_address: int = 0):
    binary = ROOT/('.analysis/probes/minagi-slot07/'+name+'-call-sites.bin')
    binary.parent.mkdir(parents=True,exist_ok=True)
    binary.write_bytes(code)
    lines=subprocess.run([
        'objdump','-w','-D','-b','binary','-m','i386','-Mintel',
        f'--adjust-vma={original_address}',str(binary)
    ],text=True,capture_output=True,check=True).stdout.splitlines()
    direct=[]
    virtual=[]
    for line in lines:
        match=re.search(r'^\s*([0-9a-f]+):.*\bcall\s+0x([0-9a-f]+)\b',line)
        if match:
            direct.append((int(match.group(1),16)-original_address,
                           int(match.group(2),16)))
            continue
        match=re.search(r'^\s*([0-9a-f]+):.*\bcall\s+(?:DWORD PTR )?\[[a-z]{3}\+0x(24|28)\]',line)
        if match:
            virtual.append((int(match.group(1),16)-original_address,
                            int(match.group(2),16)))
    return direct,virtual


def main():
    parser=argparse.ArgumentParser(description=__doc__)
    parser.add_argument('--rebuild',action='store_true')
    args=parser.parse_args()
    source=SOURCE.read_text()
    if 'void Character21::Slot07()' not in source:
        raise AssertionError('missing full Minagi vtable owner')
    forbidden=('__asm', '_emit', '__emit', 'reinterpret_cast',
               'param_1', 'FUN_', '_DAT_', 'PADDING', 'goto ', 'LAB_')
    for token in forbidden:
        if token in source:
            raise AssertionError(('not a natural typed C++ candidate',token))
    ids=[int(x,0) for x in re.findall(
        r'^\s*case\s+((?:0x[0-9a-fA-F]+|[0-9]+))\s*:',source,re.M)]
    if len(ids)!=68 or set(ids)!=set(EXPECTED_TYPES):
        raise AssertionError(('Minagi effect dispatch IDs differ from native',
                              len(ids),sorted(set(EXPECTED_TYPES)-set(ids)),
                              sorted(set(ids)-set(EXPECTED_TYPES))))
    # Real entry and return bounds, independent from candidate object.
    image=verify_target()
    if struct.unpack('<I',target_bytes(image,ORIGINAL_VTABLE_SLOT,4))[0]!=ORIGINAL_START:
        raise AssertionError('Minagi canonical vtable Slot07 mismatch')
    native=target_bytes(image,ORIGINAL_START,ORIGINAL_SIZE)
    if len(native)!=ORIGINAL_SIZE:raise AssertionError('incomplete native body')
    calls=native_direct_calls(native)
    expected_counts=collections.Counter({va:count for (_,va),count in EXPECTED_CALLS.items()})
    if calls!=expected_counts:
        raise AssertionError(('unexpected original call targets',calls,expected_counts))
    if args.rebuild:
        compile_source(SOURCE,OBJECT,FLAGS,ROOT/'.analysis/build/minagi-slot07-natural.log')
    receipt_path=OBJECT.with_suffix('.build.json')
    if not OBJECT.is_file() or not receipt_path.is_file():
        raise AssertionError('missing candidate object/receipt, rerun --rebuild')
    receipt=json.loads(receipt_path.read_text())
    if receipt['source_sha256']!=sha256(SOURCE) or receipt['object_sha256']!=sha256(OBJECT):
        raise AssertionError('stale candidate, rerun --rebuild')
    candidate,relocations=object_function(OBJECT,SYMBOL)
    actual_relocations=collections.Counter(r['symbol'] for r in relocations)
    for (symbol,target),count in EXPECTED_CALLS.items():
        if actual_relocations[symbol]!=count:
            raise AssertionError(('candidate direct-call count differs',
                                  symbol,target,count,actual_relocations[symbol]))

    # The 94 bound REL32 call sites must be present in *the same order* as
    # the original's 94 direct calls. Compare 42 indirect vtable calls as
    # ordered semantic operations (0x24 emit and 0x28 remove), too.
    symbol_to_address={symbol:target for symbol,target in EXPECTED_CALLS}
    original_direct,original_virtual=ordered_call_sites(
        native,'original',ORIGINAL_START)
    candidate_direct,candidate_virtual=ordered_call_sites(
        candidate,'candidate')
    candidate_bound_calls=[]
    for relocation in sorted(relocations,key=lambda r:r['offset']):
        symbol=relocation['symbol']
        if symbol not in symbol_to_address:
            continue
        if relocation['type']!='REL32' or candidate[relocation['offset']-1]!=0xe8:
            raise AssertionError(('helper relocation is not an E8 call',relocation))
        candidate_bound_calls.append(
            (relocation['offset']-1,symbol_to_address[symbol]))
    if len(candidate_bound_calls)!=len(original_direct) or [
        address for _,address in original_direct
    ]!=[address for _,address in candidate_bound_calls]:
        raise AssertionError(('native/candidate direct call order diverged',
                              original_direct,candidate_bound_calls))
    if [offset for _,offset in candidate_virtual]!=[
        offset for _,offset in original_virtual
    ] or len(original_virtual)!=42:
        raise AssertionError(('native/candidate virtual call order diverged',
                              original_virtual,candidate_virtual))
    if len(candidate_direct)!=len(candidate_bound_calls):
        raise AssertionError(('unbound candidate direct call sites',
                              candidate_direct,candidate_bound_calls))

    evidence={
        'schema_version':1,
        'status':'minagi-slot07-full-68-case-natural-cpp-prototype-not-exact',
        'authority':'partial-semantic-and-compiler-evidence-only',
        'original':{
            'address':hex(ORIGINAL_START),
            'vtable_slot_address':hex(ORIGINAL_VTABLE_SLOT),
            'function_bytes':ORIGINAL_SIZE,
            'sha256':hashlib.sha256(native).hexdigest(),
            'native_dispatch_cases':len(EXPECTED_TYPES),
            'native_dispatch_type_ids':[hex(x) for x in EXPECTED_TYPES],
            'native_direct_call_targets':{
                hex(addr):count for addr,count in sorted(calls.items())
            },
            'ordered_direct_helper_targets':[hex(address)
                                             for _,address in original_direct],
            'ordered_virtual_slots':[hex(slot) for _,slot in original_virtual]
        },
        'candidate':{
            'source':str(SOURCE.relative_to(ROOT)),
            'source_sha256':sha256(SOURCE),
            'object':str(OBJECT.relative_to(ROOT)),
            'object_sha256':sha256(OBJECT),
            'compiler_flags':FLAGS,
            'toolchain_lock_sha256':receipt['toolchain_lock_sha256'],
            'compiled_function_bytes':len(candidate),
            'native_size_delta':len(candidate)-ORIGINAL_SIZE,
            'dispatch_cases':len(ids),
            'dispatch_ids_match_original':True,
            'coff_relocations':len(relocations),
            'direct_helper_calls_match_original':True,
            'all_94_direct_helper_calls_match_in_order':True,
            'all_42_virtual_emit_remove_calls_match_in_order':True,
            'virtual_effect_emits':sum(slot==0x24 for _,slot in candidate_virtual),
            'virtual_effect_removals':sum(slot==0x28 for _,slot in candidate_virtual),
            'direct_helper_calls':[
                {'symbol':symbol,'native_target':hex(target),'count':count}
                for (symbol,target),count in EXPECTED_CALLS.items()
            ]
        },
        'source_contains_inline_assembly_or_padding':False,
        'strict_function_exact':False,
        'strict_whole_owner_exact':False,
        'qualification':(
            'All 68 distinct native effect types are represented in a complete '
            'typed C++ Slot07 candidate, and pinned VC7.1 compilation reproduces '
            'all ten classes of direct helper call in identical order, plus the '
            '42 virtual emit/remove calls in identical order. This does not '
            'certify branch-level equivalence, COFF relocation targets, '
            'function byte identity or full-game integration. Do not register '
            'this prototype as complete or add it to accepted exact ledgers.'
        )
    }
    EVIDENCE.parent.mkdir(parents=True,exist_ok=True)
    EVIDENCE.write_text(json.dumps(evidence,indent=2)+'\n')
    print(json.dumps({
        'status':evidence['status'],
        'original_bytes':ORIGINAL_SIZE,
        'candidate_bytes':len(candidate),
        'size_delta':len(candidate)-ORIGINAL_SIZE,
        'cases':len(ids),
        'direct_call_sites':sum(expected_counts.values()),
        'ordered_virtual_calls':len(candidate_virtual),
        'relocations':len(relocations),
        'strict_function_exact':False
    },indent=2))


if __name__=='__main__':
    main()
