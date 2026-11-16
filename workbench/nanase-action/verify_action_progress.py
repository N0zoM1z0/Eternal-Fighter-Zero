#!/usr/bin/env python3
"""Focused natural-C++ progress audit of Nanase Slot04; never whole-owner Exact."""
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
from common import verify_target,target_bytes,sha256
from coff import object_function
from native_build import compile_source

SOURCE=ROOT/'workbench/nanase-action/Character00Action-natural.cpp'
OBJECT=ROOT/'build/nanase-action/Character00Action-natural.obj'
OUT=ROOT/'docs/evidence/nanase-slot04-natural-progress.json'
ADDRESS=0x0048ACA0
LENGTH=11424
SYMBOL='?Slot04@Character00@@UAEXXZ'
FLAGS=['/Od','/G6','/MT','/Gy','/W3']
PATTERN=re.compile(r'^\s*([0-9a-f]+):\s+((?:[0-9a-f]{2}\s+)+)\s*\t(.+)$')


def decode(code:bytes,kind:str):
    path=ROOT/'.analysis/probes/nanase-action'
    path.mkdir(parents=True,exist_ok=True)
    binary=path/f'{kind}.bin'
    binary.write_bytes(code)
    output=subprocess.run(['objdump','-w','-D','-b','binary','-m','i386','-Mintel',str(binary)],
                          capture_output=True,text=True,check=True).stdout
    rows=[]
    for line in output.splitlines():
        match=PATTERN.match(line)
        if match:rows.append((int(match[1],16),bytes.fromhex(match[2]),match[3].strip()))
    if sum(len(bytes_) for _,bytes_,_ in rows)!=len(code):
        raise AssertionError(f'Incomplete {kind} disassembly')
    return rows


def native_clear_calls(rows):
    result=[]
    for i,(offset,instr,asm) in enumerate(rows):
        if len(instr)==5 and instr[0]==0xE8:
            target=ADDRESS+offset+5+struct.unpack_from('<i',instr,1)[0]
            if target==0x0040F170:
                result.append((i,offset))
    return result


def stored_state(rows,position):
    for offset,bytes_,asm in rows[position+1:position+13]:
        # After ClearBufferedButtons the first state write is always a WORD
        # to Secondary::field0008; later conditional writes are separate.
        if re.search(r'\bmov\s+WORD PTR \[[a-z]+\+0x8\],0x([0-9a-f]+)',asm):
            return int(re.search(r',0x([0-9a-f]+)',asm)[1],16)
    raise AssertionError(f'ClearBufferedButtons site with no following state write, instruction {position}')


def main():
    parser=argparse.ArgumentParser()
    parser.add_argument('--rebuild',action='store_true')
    args=parser.parse_args()
    source=SOURCE.read_text()
    if any(x in source for x in ('__asm','_emit','__emit')):
        raise AssertionError('Inline assembly or emitted opcode found in source')
    if 'void Character00::Slot04()' not in source:
        raise AssertionError('Unexpected owner declaration')
    if args.rebuild:
        compile_source(SOURCE,OBJECT,FLAGS,ROOT/'.analysis/build/nanase-action-natural.log')
    receipt=OBJECT.with_suffix('.build.json')
    if not receipt.exists() or not OBJECT.exists():
        raise AssertionError('Selected object missing; rerun with --rebuild')
    build=json.loads(receipt.read_text())
    if build['source_sha256']!=sha256(SOURCE) or build['object_sha256']!=sha256(OBJECT):
        raise AssertionError('Stale selected compile; rerun with --rebuild')
    image=verify_target()
    vtable_target=struct.unpack('<I',target_bytes(image,0x00788344,4))[0]
    assert vtable_target==ADDRESS
    original=target_bytes(image,ADDRESS,LENGTH)
    candidate,relocs=object_function(OBJECT,SYMBOL)
    native_rows=decode(original,'native');candidate_rows=decode(candidate,'candidate')
    native_calls=native_clear_calls(native_rows)
    clear_relocs=sorted((r for r in relocs if r['symbol']=='?ClearBufferedButtons@Secondary@@QAEXXZ'),key=lambda r:r['offset'])
    candidate_index={offset:i for i,(offset,_,_) in enumerate(candidate_rows)}
    candidate_calls=[(candidate_index[r['offset']-1],r['offset']-1) for r in clear_relocs]
    native_states=[stored_state(native_rows,i) for i,_ in native_calls]
    candidate_states=[stored_state(candidate_rows,i) for i,_ in candidate_calls]
    if native_states!=candidate_states:
        raise AssertionError(('Native/candidate first post-clear state transition sequences diverge',native_states,candidate_states))
    if len(native_states)!=39 or len(candidate_states)!=39:
        raise AssertionError('Expected all 39 original action transitions')
    relocs_by_symbol={}
    for r in relocs:relocs_by_symbol[r['symbol']]=relocs_by_symbol.get(r['symbol'],0)+1
    if relocs_by_symbol.get('?FaceOpponent@Secondary@@QAEHXZ')!=4:
        raise AssertionError('Expected four natural FaceOpponent calls')
    transition_rows=[
        {'ordinal':i+1,'native_call_va':hex(ADDRESS+native_calls[i][1]),
         'candidate_call_offset':hex(candidate_calls[i][1]),
         'candidate_minus_native_offset':candidate_calls[i][1]-native_calls[i][1],
         'native_state':hex(n),'candidate_state':hex(c)}
        for i,(n,c) in enumerate(zip(native_states,candidate_states))]
    evidence={
        'schema_version':1,
        'status':'natural-cpp-boss-progress-not-exact',
        'owner':'Character00::Slot04',
        'original':{'address':hex(ADDRESS),'code_bytes':LENGTH,'vtable_slot4':hex(0x00788344),
                    'sha256':hashlib.sha256(original).hexdigest(),
                    'instruction_count':len(native_rows)},
        'candidate':{'source':str(SOURCE.relative_to(ROOT)),'source_sha256':sha256(SOURCE),
                     'object':str(OBJECT.relative_to(ROOT)),'object_sha256':sha256(OBJECT),
                     'compiler_flags':FLAGS,'code_bytes':len(candidate),
                     'code_size_delta':len(candidate)-LENGTH,
                     'instruction_count':len(candidate_rows),
                     'instruction_count_delta':len(candidate_rows)-len(native_rows),
                     'coff_relocations':len(relocs),
                     'coff_symbols':relocs_by_symbol,
                     'toolchain_lock_sha256':build['toolchain_lock_sha256']},
        'native_action_clear_calls':len(native_calls),
        'candidate_action_clear_calls':len(candidate_calls),
        'all_39_first_action_state_targets_match_in_order':True,
        'transitions':transition_rows,
        'source_has_asm_or_emitted_opcodes':False,
        'whole_owner_exact':candidate==original,
        'qualification':(
            'All 39 native first post-ClearBufferedButtons action destinations now match '
            'in their original order. The candidate is 2 bytes longer and 5 '
            'instructions different in total. Its COFF calls/data still need '
            'individual target binding and full byte equivalence. This is an '
            'unaccepted natural-C++ boss workbench, never an Exact receipt.'),
    }
    OUT.parent.mkdir(parents=True,exist_ok=True)
    OUT.write_text(json.dumps(evidence,indent=2)+'\n')
    print(json.dumps({'status':evidence['status'],'code_bytes':len(candidate),
                      'native_bytes':LENGTH,'instruction_count':len(candidate_rows),
                      'native_instruction_count':len(native_rows),
                      'action_transitions':len(transition_rows),
                      'code_size_delta':len(candidate)-LENGTH,
                      'whole_owner_exact':evidence['whole_owner_exact']},indent=2))

if __name__=='__main__':main()
