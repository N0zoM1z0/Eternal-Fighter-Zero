#!/usr/bin/env python3
"""Scoped pinned-compiler and target-bound Minagi Slot02 recognizer check.

Not an Exact claim: this validates the complete 16-scan priority structure,
vtable identity, absence of external calls and a reproducible VC7.1 object.
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

SOURCE=ROOT/'workbench/minagi-commands/Character21Commands-natural.cpp'
OBJECT=ROOT/'build/minagi-commands/Character21Commands-natural.obj'
EVIDENCE=ROOT/'docs/evidence/minagi-slot02-natural-progress.json'
ADDRESS=0x005AD550
SIZE=5314
VTABLE_SLOT=0x00788948
SYMBOL='?Slot02@Character21@@UAEXXZ'
FLAGS=['/Od','/G6','/MT','/Gy','/W3']
SCAN_OFFSETS=[0x5a,100,0x5a,0x5a,0x6e,0x87,0x78,0x87,0x87,
              0xaf,0x5a,0x5a,0x87,0x87,0x87,0x87]
SCAN_COMMANDS=['0x5c', '0xaa and 0xa0', '0x6e', '100',
               '0x50','0x46','0x14','10','0x1e','6',
               '0x35','0x34','0x33','0x32','1','0']


def count_native_calls(body:bytes,name:str):
    out=ROOT/('.analysis/probes/minagi-commands/'+name+'-verify.bin')
    out.parent.mkdir(parents=True,exist_ok=True)
    out.write_bytes(body)
    text=subprocess.run([
        'objdump','-w','-D','-b','binary','-m','i386','-Mintel',str(out)
    ],capture_output=True,text=True,check=True).stdout
    return len(re.findall(r'\bcall\s+',text)),len(re.findall(
        r'^\s*[0-9a-f]+:\s+(?:[0-9a-f]{2}\s+)+\s*\t',text,re.M))


def main():
    parser=argparse.ArgumentParser(description=__doc__)
    parser.add_argument('--rebuild',action='store_true')
    args=parser.parse_args()
    source=SOURCE.read_text()
    if 'void Character21::Slot02()' not in source:
        raise AssertionError('Minagi typed Slot02 owner is absent')
    forbidden=['__asm','_emit','__emit','PADDING','reinterpret_cast',
               'param_1','FUN_','_DAT_','goto ','LAB_','while( true )']
    for word in forbidden:
        if word in source:
            raise AssertionError(('unstructured or byte-injection code',word))
    starts=[int(x,0) for x in re.findall(
        r'for \(index = inputHistoryWriteIndex \+ (0x[0-9a-fA-F]+|\d+);',
        source)]
    if starts!=SCAN_OFFSETS:
        raise AssertionError(('Minagi command priority/ranges changed',
                              starts,SCAN_OFFSETS))
    # The D-button-release scan uses heldRelease rather than stage.
    if (source.count('stage = 0;') +
            source.count("stage = '\\0';")) != 15:
        raise AssertionError('all 15 staged scans must reset stage')
    if source.count('history[index - (index >= 180) * 180]')!=16:
        raise AssertionError('all 16 scans must use circular 180-frame history')
    if source.count('recognizedCommand = 99;')!=1:
        raise AssertionError('missing unknown-command default')
    image=verify_target()
    if struct.unpack('<I',target_bytes(image,VTABLE_SLOT,4))[0]!=ADDRESS:
        raise AssertionError('original Minagi vtable Slot02 mismatch')
    native=target_bytes(image,ADDRESS,SIZE)
    if len(native)!=SIZE:raise AssertionError('native function extent incomplete')
    if args.rebuild:
        compile_source(SOURCE,OBJECT,FLAGS,
                       ROOT/'.analysis/build/minagi-commands-natural.log')
    receipt_path=OBJECT.with_suffix('.build.json')
    if not OBJECT.is_file() or not receipt_path.is_file():
        raise AssertionError('missing candidate or receipt: use --rebuild')
    receipt=json.loads(receipt_path.read_text())
    if (receipt['source_sha256']!=sha256(SOURCE) or
            receipt['object_sha256']!=sha256(OBJECT)):
        raise AssertionError('stale compiler result: use --rebuild')
    candidate,relocs=object_function(OBJECT,SYMBOL)
    if len(relocs)!=2 or any(
            r['type']!='DIR32' or r['symbol']!='__real@0000000000000000'
            for r in relocs):
        raise AssertionError(('unexpected candidate relocations',relocs))
    for r in relocs:
        if r['offset']<0 or r['offset']+4>len(candidate):
            raise AssertionError(('out of body relocation',r))
    native_calls,native_instructions=count_native_calls(native,'native')
    candidate_calls,candidate_instructions=count_native_calls(candidate,'candidate')
    if native_calls or candidate_calls:
        raise AssertionError(('unexpected nonlocal direct calls',
                              native_calls,candidate_calls))
    data={
        'schema_version':1,
        'status':'minagi-slot02-all-16-priority-scans-natural-cpp-not-exact',
        'authority':'pinned-compiler-and-provisional-native-vtable-comparison',
        'original':{
            'vtable_slot':hex(VTABLE_SLOT),
            'address':hex(ADDRESS),
            'bytes':SIZE,
            'sha256':hashlib.sha256(native).hexdigest(),
            'direct_calls':native_calls,
            'instructions':native_instructions
        },
        'candidate':{
            'source':str(SOURCE.relative_to(ROOT)),
            'source_sha256':sha256(SOURCE),
            'object':str(OBJECT.relative_to(ROOT)),
            'object_sha256':sha256(OBJECT),
            'toolchain_lock_sha256':receipt['toolchain_lock_sha256'],
            'compiler_flags':FLAGS,
            'compiled_bytes':len(candidate),
            'native_size_delta':len(candidate)-SIZE,
            'instructions':candidate_instructions,
            'direct_calls':candidate_calls,
            'relocations':len(relocs),
            'circular_history_scans':16,
            'scan_start_offsets':[hex(x) for x in starts],
            'priority_command_families':SCAN_COMMANDS
        },
        'no_inline_asm_or_byte_padding':True,
        'strict_function_exact':False,
        'strict_whole_owner_exact':False,
        'qualification':(
            'A complete, natural C++ 16-scan command recognizer has been compiled '
            'with the pinned VC7.1 toolchain and its vtable, scan ordering and '
            'ring-buffer accesses have been checked against the original. This '
            'does not prove branch-by-branch equivalence or byte-exact codegen. '
            'Keep outside accepted Exact source ledgers until independently proven.'
        )
    }
    EVIDENCE.parent.mkdir(parents=True,exist_ok=True)
    EVIDENCE.write_text(json.dumps(data,indent=2)+'\n')
    print(json.dumps({'status':data['status'],
                      'original_bytes':SIZE,
                      'candidate_bytes':len(candidate),
                      'delta':len(candidate)-SIZE,
                      'history_scans':16,
                      'original_instructions':native_instructions,
                      'candidate_instructions':candidate_instructions,
                      'strict_function_exact':False},indent=2))


if __name__=='__main__':main()
