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


def ordered_ftol_sources(code: bytes, name: str, ftol_calls: list[tuple[int,int]],
                         original_address: int = 0) -> list[str]:
    """Trace each x87 float-to-int's actual operand, not only its call site.

    The native function uses either a typed local effect x/y position or the
    owner position x/y. This checks the exact 37-source order via decoded
    instructions so a accidentally swapped position can never pass call counts.
    """
    binary = ROOT/'.analysis/probes/minagi-slot07'/f'{name}-ftol-source.bin'
    binary.parent.mkdir(parents=True,exist_ok=True)
    binary.write_bytes(code)
    asm=subprocess.run([
        'objdump','-w','-z','-D','-b','binary','-m','i386','-Mintel',
        f'--adjust-vma={original_address}',str(binary)
    ],text=True,capture_output=True,check=True).stdout
    rows=[]
    for line in asm.splitlines():
        m=re.match(r'^\s*([0-9a-f]+):\s+((?:[0-9a-f]{2}\s+)+)\s+(.+)',line)
        if m:rows.append((int(m.group(1),16)-original_address,m.group(3).strip()))
    indexed={offset:index for index,(offset,operation) in enumerate(rows)}
    names={0x4e8:'local-effect-x',0x4f0:'local-effect-y',
           0x20:'character-x',0x28:'character-y'}
    results=[]
    for offset,target in ftol_calls:
        if target!=0x007783B8:raise AssertionError(('non-ftol2 call',offset,target))
        if offset not in indexed:raise AssertionError(('undecoded ftol2 call',offset))
        i=indexed[offset]
        if not rows[i][1].startswith('call '):raise AssertionError(('invalid ftol2 instruction',rows[i]))
        loads=[]
        for position,operation in rows[max(0,i-24):i]:
            match=re.search(r'\bfld\s+QWORD PTR \[[a-z]{3}(?:\+[a-z]{3}\*[1248])?\+0x([0-9a-fA-F]+)\]$',operation)
            if match:
                displacement=int(match.group(1),16)
                if displacement in names:loads.append((position,names[displacement]))
        if not loads:
            raise AssertionError(('float-to-int has no grounded position load',name,offset))
        results.append(loads[-1][1])
    return results


def original_float_literal_values(image, native: bytes):
    """Read each original x87 f64 memory operand, in instruction order.

    The PE data are inspected directly: a candidate relocation cannot invent
    which value was stored at an original absolute-address operand. The source
    function is self-contained except for the native section's static doubles.
    """
    binary=ROOT/'.analysis/probes/minagi-slot07/original-literals-verify.bin'
    binary.parent.mkdir(parents=True,exist_ok=True)
    binary.write_bytes(native)
    result=subprocess.run([
        'objdump','-w','-D','-b','binary','-m','i386','-Mintel',
        f'--adjust-vma={ORIGINAL_START}',str(binary)
    ],text=True,capture_output=True,check=True).stdout
    values=[]
    addresses=[]
    for line in result.splitlines():
        match=re.search(r'^\s*[0-9a-f]+:.*\bds:0x([0-9a-fA-F]+)',line)
        if match:
            address=int(match.group(1),16)
            if 0x00787000<=address<0x00789000:
                value=int.from_bytes(target_bytes(image,address,8),'little')
                values.append(value)
                addresses.append(address)
    return values,addresses


def candidate_float_literal_values(relocations: list[dict]):
    """Inspect the actual COFF floating literal relocations, without masking."""
    values=[]
    for reloc in sorted(relocations,key=lambda r:r['offset']):
        symbol=reloc['symbol']
        if not symbol.startswith('__real@'):
            continue
        if reloc['type']!='DIR32':
            raise AssertionError(('floating constant has non-DIR32 relocation',reloc))
        bits=symbol.split('@',1)[1]
        if not re.fullmatch(r'[0-9a-fA-F]{16}',bits):
            raise AssertionError(('unexpected floating literal symbol encoding',reloc))
        values.append(int(bits,16))
    return values


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

    # Stronger semantic binding: all 37 __ftol2 conversions must read
    # the same x/y source field in the same call order as the native PE.
    native_ftol_calls=[item for item in original_direct if item[1]==0x007783B8]
    candidate_ftol_calls=[item for item in candidate_bound_calls if item[1]==0x007783B8]
    if len(native_ftol_calls)!=37 or len(candidate_ftol_calls)!=37:
        raise AssertionError(('unexpected native/candidate ftol2 sites',
                              len(native_ftol_calls),len(candidate_ftol_calls)))
    native_ftol_fields=ordered_ftol_sources(
        native,'original',native_ftol_calls,ORIGINAL_START)
    candidate_ftol_fields=ordered_ftol_sources(
        candidate,'candidate',candidate_ftol_calls)
    if native_ftol_fields!=candidate_ftol_fields:
        raise AssertionError(('wrong position feed into C++ float-to-int conversion',
                              native_ftol_fields,candidate_ftol_fields))
    ftol_fields_digest=hashlib.sha256(
        json.dumps(native_ftol_fields,separators=(',',':')).encode()
    ).hexdigest()

    # Every x87 double referenced by the 87,798-byte native boss must appear
    # with the same value and multiplicity among the compiled C++ relocations.
    # This is strictly weaker than ordered identity: the remaining out-of-order
    # literal accesses identify unfinished branch/codegen reconstruction.
    native_floats,native_literal_addresses=original_float_literal_values(image,native)
    candidate_floats=candidate_float_literal_values(relocations)
    if len(native_floats)!=789 or len(candidate_floats)!=789:
        raise AssertionError(('unexpected native/candidate floating literal counts',
                              len(native_floats),len(candidate_floats)))
    original_histogram=collections.Counter(native_floats)
    candidate_histogram=collections.Counter(candidate_floats)
    if original_histogram!=candidate_histogram:
        raise AssertionError(('native/candidate floating constants differ',
                              original_histogram-candidate_histogram,
                              candidate_histogram-original_histogram))
    floats_in_native_order=sum(a==b for a,b in zip(native_floats,candidate_floats))
    histogram_rows=[{'ieee754_bits':f'{bits:016x}','count':count}
                    for bits,count in sorted(original_histogram.items())]
    histogram_hash=hashlib.sha256(
        json.dumps(histogram_rows,sort_keys=True,separators=(',',':')).encode()
    ).hexdigest()
    body_hash=hashlib.sha256(candidate).hexdigest()

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
            'floating_literal_references':len(native_floats),
            'ordered_ftol2_position_sources':native_ftol_fields,
            'ordered_ftol2_source_sha256':ftol_fields_digest,
            'distinct_floating_literal_values':len(original_histogram),
            'floating_literal_histogram_sha256':histogram_hash,
            'ordered_direct_helper_targets':[hex(address)
                                             for _,address in original_direct],
            'ordered_virtual_slots':[hex(slot) for _,slot in original_virtual]
        },
        'candidate':{
            'source':str(SOURCE.relative_to(ROOT)),
            'source_sha256':sha256(SOURCE),
            'object':str(OBJECT.relative_to(ROOT)),
            # Whole-COFF object hashes can change with compiler-local symbols,
            # even when function code and relocations are unchanged. Verify
            # the receipt above but publish a deterministic function-code hash.
            'function_body_sha256':body_hash,
            'compiler_flags':FLAGS,
            'toolchain_lock_sha256':receipt['toolchain_lock_sha256'],
            'compiled_function_bytes':len(candidate),
            'native_size_delta':len(candidate)-ORIGINAL_SIZE,
            'dispatch_cases':len(ids),
            'dispatch_ids_match_original':True,
            'coff_relocations':len(relocations),
            'ftol2_position_sources_in_original_order':len(candidate_ftol_fields),
            'ordered_ftol2_source_sha256':ftol_fields_digest,
            'floating_literal_relocations':len(candidate_floats),
            'floating_literal_value_multiset_matches_original':True,
            'float_literal_values_matching_native_order':floats_in_native_order,
            'float_literal_values_out_of_native_order':len(native_floats)-floats_in_native_order,
            'distinct_floating_literal_values':len(candidate_histogram),
            'floating_literal_histogram_sha256':histogram_hash,
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
            '42 virtual emit/remove calls in identical order. All 789 original '
            'floating literal references match the candidate values and native '
            'access order. All 37 x87 float-to-int calls load the corresponding '
            'character or local-effect position axis in original order. This '
            'does not certify branch-level equivalence, COFF relocation targets, '
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
        'ftol2_position_sources_in_order':len(candidate_ftol_fields),
        'relocations':len(relocations),
        'float_literals_value_matched':len(native_floats),
        'float_literals_in_native_order':floats_in_native_order,
        'strict_function_exact':False
    },indent=2))


if __name__=='__main__':
    main()
