#!/usr/bin/env python3
"""Focused Ayu natural-C++ Slot04 action-priority audit (unaccepted boss)."""
from __future__ import annotations
import argparse
import hashlib
import json
import re
import struct
import subprocess
import sys
from pathlib import Path
ROOT=Path(__file__).resolve().parents[2]
sys.path.insert(0,str(ROOT/'scripts'))
from native_build import compile_source
from coff import object_function
from common import verify_target,target_bytes,sha256

SOURCE=ROOT/'workbench/ayu-action/Character01Action-natural.cpp'
OBJECT=ROOT/'build/ayu-action/Character01Action-natural.obj'
REPORT=ROOT/'docs/evidence/ayu-slot04-natural-progress.json'
ADDRESS=0x006E84D0
SIZE=10923
VTABLE=0x00788E5C
SYMBOL='?Slot04@Character01@@UAEXXZ'
FLAGS=['/Od','/G6','/MT','/Gy','/W3']
PATTERN=re.compile(r'^\s*([0-9a-f]+):\s+((?:[0-9a-f]{2}\s+)+)\s*\t(.+)$')
CLEAR='?ClearBufferedButtons@Secondary@@QAEXXZ'

def decode(code:bytes,label:str):
    path=ROOT/'.analysis/probes/ayu-action'
    path.mkdir(parents=True,exist_ok=True)
    dest=path/f'{label}.bin'
    dest.write_bytes(code)
    output=subprocess.run(['objdump','-w','-D','-b','binary','-m','i386','-Mintel',str(dest)],
                          capture_output=True,text=True,check=True).stdout
    rows=[]
    for line in output.splitlines():
        m=PATTERN.match(line)
        if m: rows.append((int(m[1],16),bytes.fromhex(m[2]),m[3].strip()))
    if sum(len(b) for _,b,_ in rows)!=len(code):
        raise AssertionError(('nonexhaustive disassembly',label))
    return rows

def native_clear_calls(rows):
    positions=[]
    for i,(offset,b,asm) in enumerate(rows):
        if len(b)==5 and b[0]==0xE8:
            dest=(ADDRESS+offset+5+struct.unpack_from('<i',b,1)[0])&0xffffffff
            if dest==0x0040F170:positions.append((i,offset))
    return positions

def state(rows,index):
    for off,b,asm in rows[index+1:index+12]:
        m=re.search(r'mov\s+WORD PTR \[\w+\+0x8\],0x([0-9a-f]+)',asm)
        if m:return int(m[1],16)
    raise AssertionError(('missing post-call field0008 assignment',index))

def main():
    parser=argparse.ArgumentParser(description=__doc__)
    parser.add_argument('--rebuild',action='store_true')
    args=parser.parse_args()
    text=SOURCE.read_text()
    if 'void Character01::Slot04()' not in text or any(x in text for x in ('__asm','_emit','__emit')):
        raise AssertionError('must have real natural Ayu C++ action owner')
    if args.rebuild:
        compile_source(SOURCE,OBJECT,FLAGS,ROOT/'.analysis/build/ayu-action-natural.log')
    manifest=OBJECT.with_suffix('.build.json')
    if not manifest.exists():
        raise AssertionError('missing build receipt; rerun --rebuild')
    receipt=json.loads(manifest.read_text())
    if receipt['source_sha256']!=sha256(SOURCE) or receipt['object_sha256']!=sha256(OBJECT):
        raise AssertionError('stale compiled candidate; rerun --rebuild')
    image=verify_target()
    if struct.unpack('<I',target_bytes(image,VTABLE,4))[0]!=ADDRESS:
        raise AssertionError('Ayu original vtable Slot04 mismatch')
    native=target_bytes(image,ADDRESS,SIZE)
    candidate,relocs=object_function(OBJECT,SYMBOL)
    n=decode(native,'original');c=decode(candidate,'natural')
    native_calls=native_clear_calls(n)
    reloc_sites={r['offset']-1 for r in relocs if r['symbol']==CLEAR}
    candidate_calls=[(i,off) for i,(off,_,_) in enumerate(c) if off in reloc_sites]
    if len(native_calls)!=38 or len(candidate_calls)!=38:
        raise AssertionError(('unexpected original/candidate clear sites',len(native_calls),len(candidate_calls)))
    nstates=[state(n,i) for i,_ in native_calls]
    cstates=[state(c,i) for i,_ in candidate_calls]
    expected=[
        0xa7,0x13e,0x134,0x133,0x132,0x12e,0x12d,0x12c,0x13d,0x13c,0x13b,
        0x132,0xfb,0xfc,0xfa,0x102,0x101,0x100,0x106,0x105,0x104,
        0xe,0xcf,0xcc,0xc8,0xd0,0xcd,0xd2,0xc9,0xca,0xf0,0xd4,0xd1,
        0xce,0xdc,0xd3,0xcb,0x28,
    ]
    if nstates[:len(expected)]!=expected or cstates[:len(expected)]!=expected:
        raise AssertionError(('native high-priority transition order mismatch',nstates[:11],cstates[:11]))
    rows=[{'ordinal':i+1,'native_call_va':hex(ADDRESS+native_calls[i][1]),
           'candidate_call_offset':hex(candidate_calls[i][1]),
           'candidate_minus_original':candidate_calls[i][1]-native_calls[i][1],
           'native_first_state':hex(nstates[i]),'candidate_first_state':hex(cstates[i])}
          for i in range(len(expected))]
    evidence={
        'schema_version':1,
        'status':'natural-cpp-ayu-action-workbench-not-exact',
        'original':{'owner':'Character01::Slot04','address':hex(ADDRESS),
                    'vtable_slot4':hex(VTABLE),'bytes':len(native),
                    'sha256':hashlib.sha256(native).hexdigest(),
                    'instruction_count':len(n),'clear_calls':len(native_calls)},
        'candidate':{'source':str(SOURCE.relative_to(ROOT)),
                     'source_sha256':sha256(SOURCE),
                     'object':str(OBJECT.relative_to(ROOT)),
                     'object_sha256':sha256(OBJECT),
                     'compiler_flags':FLAGS,
                     'bytes':len(candidate),'size_delta':len(candidate)-SIZE,
                     'instruction_count':len(c),
                     'coff_relocations':len(relocs),
                     'clear_calls':len(candidate_calls),
                     'toolchain_lock_sha256':receipt['toolchain_lock_sha256']},
        'all_38_native_action_state_targets_match_in_order':True,
        'all_38_action_transitions':rows,
        'source_has_asm_or_emitted_opcodes':False,
        'whole_owner_exact':False,
        'qualification':('All 38 native ClearBufferedButtons action call '
                         'sites and their first post-call state IDs are '
                         'reproduced in the original order, including the '
                         'Ayu-only 0xF0/0xD4/0x28 air/button transitions. '
                         'The candidate differs in actual machine instructions '
                         '(2758 vs 2765), code extent (10904 vs 10923), '
                         'local branch edges and relocation targets. This '
                         'is a natural C++ workbench checkpoint, not an '
                         'accepted whole-owner Exact receipt.'),
    }
    REPORT.parent.mkdir(parents=True,exist_ok=True)
    REPORT.write_text(json.dumps(evidence,indent=2)+'\n')
    print(json.dumps({'status':evidence['status'],'original_bytes':len(native),
                      'candidate_bytes':len(candidate),
                      'native_clear_calls':len(native_calls),
                      'candidate_clear_calls':len(candidate_calls),
                      'all_38_state_codes':[hex(v) for v in expected],
                      'relocations':len(relocs)},indent=2))

if __name__=='__main__':main()
