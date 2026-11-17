#!/usr/bin/env python3
"""Original-vtable scoped verification of Akane natural C++ Slot04 prototype.

This is not a full-owner Exact certificate. Compile only the candidate TU.
"""
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

SOURCE=ROOT/'workbench/akane-action/Character02Action-natural.cpp'
OBJECT=ROOT/'build/akane-action/Character02Action-natural.obj'
OUT=ROOT/'docs/evidence/akane-slot04-natural-progress.json'
ADDRESS=0x00703D40
SIZE=11584
VTABLE=0x00788EC0
SYMBOL='?Slot04@Character02@@UAEXXZ'
FLAGS=['/Od','/G6','/MT','/Gy','/W3']
INST=re.compile(r'^\s*([0-9a-f]+):\s+((?:[0-9a-f]{2}\s+)+)\s*\t(.+)$')
STATE=re.compile(r'mov\s+WORD PTR \[\w+\+0x8\],0x([0-9a-f]+)')
CLEAR='?ClearBufferedButtons@Secondary@@QAEXXZ'
EXPECTED=[0xa7,0x135,0x134,0x133,0x132,0x12e,0x12d,0x12c,
          0x12f,0x130,0x131,0x111,0x110,0x10f,0xff,0xfe,
          0xfd,0x102,0x101,0x100,0x105,0x104,0x103,0xfc,
          0xfb,0xfa,0xe,0xe6,0xcf,0xcc,0xc8,0xe7,0xd0,
          0xcd,0xc9,0xca,0xe8,0xf0,0xd3,0xd1,0xce,0xdc,0xcb]

def decode(code:bytes,name:str):
    binary=ROOT/f'.analysis/probes/akane-action/{name}.bin'
    binary.parent.mkdir(parents=True,exist_ok=True)
    binary.write_bytes(code)
    text=subprocess.run(['objdump','-w','-D','-b','binary','-m','i386','-Mintel',str(binary)],
                        capture_output=True,text=True,check=True).stdout
    instructions=[]
    for line in text.splitlines():
        match=INST.match(line)
        if match:
            instructions.append((int(match[1],16),bytes.fromhex(match[2]),match[3].strip()))
    if sum(len(raw) for _,raw,_ in instructions)!=len(code):
        raise AssertionError(f'incomplete {name} disassembly')
    return instructions

def native_clear_calls(rows):
    sites=[]
    for i,(offset,raw,_) in enumerate(rows):
        if len(raw)==5 and raw[0]==0xE8:
            target=(ADDRESS+offset+5+struct.unpack_from('<i',raw,1)[0])&0xFFFFFFFF
            if target==0x0040F170:sites.append((i,offset))
    return sites

def first_state(rows,index):
    for _,_,asm in rows[index+1:index+13]:
        match=STATE.search(asm)
        if match:return int(match[1],16)
    raise AssertionError(('missing first post-call state assignment',index))

def main():
    parser=argparse.ArgumentParser(description=__doc__)
    parser.add_argument('--rebuild',action='store_true')
    args=parser.parse_args()
    text=SOURCE.read_text()
    if 'void Character02::Slot04()' not in text or any(t in text for t in ('__asm','_emit','__emit')):
        raise AssertionError('expected natural Akane C++ with no opcode injection')
    if args.rebuild:
        compile_source(SOURCE,OBJECT,FLAGS,ROOT/'.analysis/build/akane-action-natural.log')
    receipt_path=OBJECT.with_suffix('.build.json')
    if not receipt_path.exists():raise AssertionError('missing pinned TU receipt, rerun --rebuild')
    receipt=json.loads(receipt_path.read_text())
    if receipt['source_sha256']!=sha256(SOURCE) or receipt['object_sha256']!=sha256(OBJECT):
        raise AssertionError('stale object, rerun --rebuild')
    image=verify_target()
    if struct.unpack('<I',target_bytes(image,VTABLE,4))[0]!=ADDRESS:
        raise AssertionError('Akane native Slot04 vtable mismatch')
    native=target_bytes(image,ADDRESS,SIZE)
    candidate,relocs=object_function(OBJECT,SYMBOL)
    n=decode(native,'original')
    c=decode(candidate,'candidate')
    nc=native_clear_calls(n)
    cand_off={r['offset']-1 for r in relocs if r['symbol']==CLEAR}
    cc=[(i,off) for i,(off,_,_) in enumerate(c) if off in cand_off]
    if len(nc)!=43 or len(cc)!=len(nc):
        raise AssertionError(('unexpected call counts',len(nc),len(cc)))
    native_states=[first_state(n,i) for i,_ in nc]
    cand_states=[first_state(c,i) for i,_ in cc]
    if native_states!=EXPECTED or cand_states!=EXPECTED:
        raise AssertionError(('Akane native/candidate action state sequence differs',native_states,cand_states))
    row=[]
    for k,(native_call,candidate_call) in enumerate(zip(nc,cc)):
        row.append({'index':k+1,'original_va':hex(ADDRESS+native_call[1]),
                    'candidate_offset':hex(candidate_call[1]),
                    'offset_delta':candidate_call[1]-native_call[1],
                    'original_state':hex(native_states[k]),'candidate_state':hex(cand_states[k])})
    evidence={
        'schema_version':1,'status':'natural-cpp-Akane-action-boss-progress-not-exact',
        'original':{'address':hex(ADDRESS),'owner_bytes':len(native),
                    'vtable_slot4':hex(VTABLE),'sha256':hashlib.sha256(native).hexdigest(),
                    'instructions':len(n),'clear_calls':len(nc)},
        'candidate':{'source':str(SOURCE.relative_to(ROOT)),
                     'source_sha256':sha256(SOURCE),
                     'object':str(OBJECT.relative_to(ROOT)),
                     'object_sha256':sha256(OBJECT),
                     'compiler_flags':FLAGS,'bytes':len(candidate),
                     'size_delta':len(candidate)-SIZE,
                     'instructions':len(c),'clear_calls':len(cc),
                     'coff_relocations':len(relocs),
                     'toolchain_lock_sha256':receipt['toolchain_lock_sha256']},
        'all_43_original_clear_call_state_ids_match':True,
        'all_43_transitions':row,
        'source_contains_inline_asm_or_emitted_opcodes':False,
        'strict_whole_owner_exact':False,
        'qualification':('All 43 native ClearBufferedButtons call sites now lead to the '
                         'same action-state IDs in the same order in natural C++. '
                         'This is a control-flow milestone, not whole-owner Exact: '
                         'candidate byte count, instruction layout, branch-level '
                         'semantics, and COFF destinations still require closure. '
                         'Keep this candidate outside all accepted ledgers.'),
    }
    OUT.parent.mkdir(parents=True,exist_ok=True)
    OUT.write_text(json.dumps(evidence,indent=2)+'\n')
    print(json.dumps({'status':evidence['status'],'original_bytes':len(native),
                      'candidate_bytes':len(candidate),'original_clear_calls':len(nc),
                      'candidate_clear_calls':len(cc),'original_instructions':len(n),
                      'candidate_instructions':len(c),'original_clear_call_states_matched':len(EXPECTED)},indent=2))

if __name__=='__main__':main()
