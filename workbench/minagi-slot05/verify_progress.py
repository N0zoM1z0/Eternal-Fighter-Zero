#!/usr/bin/env python3
"""Target-bound local proof of Minagi Slot05 natural-C++ CPU decision candidate.

No Exact claim: validates native vtable identity, 111 directly called helpers,
and all 207 canonical x87 float/double constant references by value/multiplicity.
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

ROOT=Path(__file__).resolve().parents[2]
sys.path.insert(0,str(ROOT/'scripts'))
from common import verify_target,target_bytes,sha256
from native_build import compile_source
from coff import object_function

SOURCE=ROOT/'workbench/minagi-slot05/Character21Cpu-natural.cpp'
OBJECT=ROOT/'build/minagi-slot05/Character21Cpu-natural.obj'
EVIDENCE=ROOT/'docs/evidence/minagi-slot05-natural-progress.json'
ORIGINAL=0x005AEA20
NATIVE_SIZE=17127
VTABLE_ENTRY=0x00788954
SYMBOL='?Slot05@Character21@@UAEXXZ'
FLAGS=['/Od','/G6','/MT','/Gy','/W3']
CALLEES={
    '?RandomRange@Secondary@@QAEFFF@Z':(0x004108A0,108),
    '?CollisionSide@Secondary@@QAEDXZ':(0x0040FF70,2),
    '_fabs':(0x0077842D,1),
}
FLOAT32=4
FLOAT64=8

def disasm(data:bytes, filename:str, address:int=0):
    binary=ROOT/'.analysis/probes/minagi-slot05'/filename
    binary.parent.mkdir(parents=True,exist_ok=True)
    binary.write_bytes(data)
    return subprocess.run([
        'objdump','-w','-D','-b','binary','-m','i386','-Mintel',
        f'--adjust-vma={address}',str(binary)
    ],capture_output=True,text=True,check=True).stdout.splitlines()

def native_calls_and_literals(image, native:bytes):
    calls=[]
    floats=[]
    for line in disasm(native,'original-verify.bin',ORIGINAL):
        call=re.search(r'^\s*([0-9a-f]+):.*\bcall\s+0x([0-9a-f]+)',line)
        if call:
            calls.append((int(call.group(1),16)-ORIGINAL,int(call.group(2),16)))
        literal=re.search(r'\b(DWORD|QWORD)\s+PTR\s+ds:0x([0-9a-f]+)',line)
        if literal:
            address=int(literal.group(2),16)
            if 0x00787000 <= address < 0x00789000:
                size=FLOAT32 if literal.group(1)=='DWORD' else FLOAT64
                value=int.from_bytes(target_bytes(image,address,size),'little')
                floats.append((size,value,address))
    return calls,floats

def candidate_calls_and_literals(relocs:list[dict], candidate:bytes):
    floats=[]
    called=[]
    for reloc in sorted(relocs,key=lambda r:r['offset']):
        sym=reloc['symbol']
        if sym.startswith('__real@'):
            if reloc['type']!='DIR32':
                raise AssertionError(('literal is not DIR32',reloc))
            hex_bits=sym.split('@',1)[1]
            if not re.fullmatch(r'(?:[0-9a-fA-F]{8}|[0-9a-fA-F]{16})',hex_bits):
                raise AssertionError(('unexpected constant encoding',sym))
            floats.append((len(hex_bits)//2,int(hex_bits,16)))
        elif sym in CALLEES:
            if reloc['type']!='REL32' or candidate[reloc['offset']-1]!=0xE8:
                raise AssertionError(('helper is not a real direct E8 call',reloc))
            called.append((reloc['offset']-1,CALLEES[sym][0],sym))
        else:
            raise AssertionError(('unexpected external COFF relocation',reloc))
    return called,floats

def main():
    parser=argparse.ArgumentParser(description=__doc__)
    parser.add_argument('--rebuild',action='store_true')
    opts=parser.parse_args()
    text=SOURCE.read_text()
    if 'void Character21::Slot05()' not in text:
        raise AssertionError('missing natural C++ Minagi CPU Slot05 owner')
    for name in ['__asm','_emit','__emit','reinterpret_cast','PADDING',
                 'param_1','FUN_','_DAT_']:
        if name in text:
            raise AssertionError(('unconverted decompiler/ASM marker',name))
    image=verify_target()
    if struct.unpack('<I',target_bytes(image,VTABLE_ENTRY,4))[0]!=ORIGINAL:
        raise AssertionError('Minagi vtable Slot05 target changed')
    native=target_bytes(image,ORIGINAL,NATIVE_SIZE)
    if len(native)!=NATIVE_SIZE:raise AssertionError('incomplete native owner')
    native_calls,native_literals=native_calls_and_literals(image,native)
    original_counts=collections.Counter(target for _,target in native_calls)
    expected_counts=collections.Counter({addr:n for addr,n in CALLEES.values()})
    if original_counts!=expected_counts:
        raise AssertionError(('unexpected original helper call counts',
                              original_counts,expected_counts))
    if opts.rebuild:
        compile_source(SOURCE,OBJECT,FLAGS,ROOT/'.analysis/build/minagi-slot05-natural.log')
    receipt_path=OBJECT.with_suffix('.build.json')
    if not OBJECT.exists() or not receipt_path.exists():
        raise AssertionError('missing compiled candidate or build receipt')
    receipt=json.loads(receipt_path.read_text())
    if receipt['source_sha256']!=sha256(SOURCE) or receipt['object_sha256']!=sha256(OBJECT):
        raise AssertionError('compiled candidate stale: --rebuild required')
    candidate,relocs=object_function(OBJECT,SYMBOL)
    called,candidate_literals=candidate_calls_and_literals(relocs,candidate)
    counted=collections.Counter(addr for _,addr,_ in called)
    if counted!=expected_counts or len(called)!=111:
        raise AssertionError(('candidate helper-call counts mismatch',
                              counted,expected_counts))
    native_call_order=[addr for _,addr in native_calls]
    candidate_call_order=[addr for _,addr,_ in called]
    call_in_order=sum(a==b for a,b in zip(native_call_order,candidate_call_order))
    if len(native_literals)!=207 or len(candidate_literals)!=207:
        raise AssertionError(('unexpected native/candidate static literals',
                              len(native_literals),len(candidate_literals)))
    original_values=collections.Counter((width,bits) for width,bits,_ in native_literals)
    candidate_values=collections.Counter(candidate_literals)
    if original_values!=candidate_values:
        raise AssertionError(('original vs candidate literal values differ',
                              original_values-candidate_values,
                              candidate_values-original_values))
    literal_order_matches=sum((width,bits)==given
                              for (width,bits,_),given in zip(native_literals,candidate_literals))
    hist=[{'bits':f'{bits:0{2*width}x}','bytes':width,'count':count}
          for (width,bits),count in sorted(original_values.items())]
    histogram_sha=hashlib.sha256(
        json.dumps(hist,sort_keys=True,separators=(',',':')).encode()
    ).hexdigest()
    evidence={
        'schema_version':1,
        'status':'minagi-slot05-typed-natural-cpp-cpu-boss-prototype-not-exact',
        'authority':'provisional-native-vtable-and-pinned-compiler-local-evidence',
        'original':{
            'address':hex(ORIGINAL),
            'vtable_entry':hex(VTABLE_ENTRY),
            'bytes':NATIVE_SIZE,
            'sha256':hashlib.sha256(native).hexdigest(),
            'direct_call_sites':len(native_calls),
            'direct_call_targets':{hex(a):n for a,n in sorted(original_counts.items())},
            'static_floating_literal_refs':len(native_literals),
            'static_floating_literal_histogram_sha256':histogram_sha,
        },
        'candidate':{
            'source':str(SOURCE.relative_to(ROOT)),
            'source_sha256':sha256(SOURCE),
            'object':str(OBJECT.relative_to(ROOT)),
            'function_body_sha256':hashlib.sha256(candidate).hexdigest(),
            'toolchain_lock_sha256':receipt['toolchain_lock_sha256'],
            'compiler_flags':FLAGS,
            'bytes':len(candidate),
            'native_size_delta':len(candidate)-NATIVE_SIZE,
            'coff_relocations':len(relocs),
            'direct_call_sites':len(called),
            'direct_call_targets':{hex(a):n for a,n in sorted(counted.items())},
            'direct_calls_in_original_order':call_in_order,
            'direct_calls_out_of_original_order':len(native_calls)-call_in_order,
            'static_floating_literal_refs':len(candidate_literals),
            'static_floating_literals_values_match_native':True,
            'static_floating_literals_in_original_order':literal_order_matches,
            'static_floating_literals_out_of_original_order':len(native_literals)-literal_order_matches,
            'static_floating_literal_histogram_sha256':histogram_sha,
        },
        'source_contains_inline_asm_or_padding':False,
        'strict_function_exact':False,
        'strict_whole_owner_exact':False,
        'qualification':(
            'This is a full natural-C++ CPU decision candidate, with 111 native '
            'external helper calls matched by target multiplicity and 207 x87 '
            'static floating references matched by IEEE-754 value and count. '
            'Some native/candidate call and literal reference order differs; '
            'code size, instruction identity, side-effect order, and full '
            'branch equivalence remain unproven. This source stays outside '
            'accepted Exact and implemented-function ledgers.'
        )
    }
    EVIDENCE.parent.mkdir(parents=True,exist_ok=True)
    EVIDENCE.write_text(json.dumps(evidence,indent=2)+'\n')
    print(json.dumps({
        'original_bytes':NATIVE_SIZE,
        'candidate_bytes':len(candidate),
        'size_delta':len(candidate)-NATIVE_SIZE,
        'direct_helper_calls':len(called),
        'direct_calls_in_native_order':call_in_order,
        'static_literal_values_matched':len(candidate_literals),
        'static_literals_in_native_order':literal_order_matches,
        'exact':False
    },indent=2))

if __name__=='__main__': main()
