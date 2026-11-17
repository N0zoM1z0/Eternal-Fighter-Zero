#!/usr/bin/env python3
"""Locally verify the full natural C++ frame-rectangle candidate, not Exact."""
from __future__ import annotations
from pathlib import Path
import hashlib
import json
import re
import subprocess
import sys
from difflib import SequenceMatcher

ROOT=Path(__file__).resolve().parents[2]
sys.path.insert(0,str(ROOT/'scripts'))
from common import sha256, verify_target, target_bytes
from native_build import compile_source
from coff import object_function

ADDRESS=0x0040B110
SIZE=485
SOURCE=ROOT/'workbench/video-frame-rectangle/VideoFrameRectangle-natural.cpp'
OBJECT=ROOT/'build/video-frame-rectangle/VideoFrameRectangle-natural.obj'
LOG=ROOT/'.analysis/build/video-frame-rectangle-natural.log'
SYMBOL='?FrameRectangle@Video@@QAEHUSurfaceRect@@E@Z'
EVIDENCE=ROOT/'docs/evidence/video-frame-rectangle-natural-progress.json'

def disassemble(data:bytes, name:str):
    path=ROOT/'.analysis/probes/video-frame-rectangle'/f'{name}-natural-verification.bin'
    path.parent.mkdir(parents=True,exist_ok=True)
    path.write_bytes(data)
    text=subprocess.run(['objdump','-w','-z','-D','-b','binary','-m','i386','-Mintel',str(path)],
                        capture_output=True,text=True,check=True).stdout
    rows=[]
    for line in text.splitlines():
        match=re.match(r'^\s*([0-9a-f]+):\s+((?:[0-9a-f]{2}\s+)+)\s+(.+)',line)
        if match:rows.append((int(match[1],16),bytes.fromhex(match[2]),match[3].strip()))
    if sum(len(row[1]) for row in rows)!=len(data):
        raise AssertionError(('incomplete instruction-boundary decode',name))
    return rows

def virtual_calls(rows):
    result=[]
    for _offset,_raw,ins in rows:
        m=re.fullmatch(r'call\s+DWORD PTR \[[a-z]{3}\+0x([0-9a-f]+)\]',ins)
        if m:result.append(int(m[1],16))
    return result

def normalized(ins):
    name,*rest=ins.split(None,1)
    operand=rest[0] if rest else ''
    if name.startswith('j') or name=='call':operand='<relative-target>'
    operand=re.sub(r'ebp(?:\+|-)(?:0x[0-9a-f]+|[0-9]+)','ebp+LOCAL',operand)
    operand=re.sub(r'0x[0-9a-f]+','<constant>',operand)
    return name+' '+operand

def main():
    src=SOURCE.read_text()
    for token in ('__asm','_emit','__emit','PADDING','goto ','FUN_','param_1'):
        if token in src:raise AssertionError(('forbidden non-natural C++',token))
    for item in ('FrameRectangle','DDSURFACEDESC','backSurface->Lock',
                 'backSurface->Unlock','description.lPitch','pixels['):
        if item not in src:raise AssertionError(('missing semantic operation',item))
    native=target_bytes(verify_target(),ADDRESS,SIZE)
    compile_source(SOURCE,OBJECT,['/Od','/G6','/MT','/Gy','/W3'],LOG)
    candidate,relocs=object_function(OBJECT,SYMBOL)
    if relocs:raise AssertionError(('unexpected external relocation',relocs))
    nr,cr=disassemble(native,'original'),disassemble(candidate,'candidate')
    if virtual_calls(nr)!=[0x64,0x80] or virtual_calls(cr)!=[0x64,0x80]:
        raise AssertionError(('DirectDraw Lock/Unlock order differs',virtual_calls(nr),virtual_calls(cr)))
    if len(nr)!=125 or len(cr)!=125:
        raise AssertionError(('native/candidate instruction count',len(nr),len(cr)))
    original_ops=[normalized(row[2]) for row in nr]
    candidate_ops=[normalized(row[2]) for row in cr]
    equal=sum(a2-a1 for kind,a1,a2,b1,b2 in
              SequenceMatcher(None,original_ops,candidate_ops,autojunk=False).get_opcodes()
              if kind=='equal')
    if equal<124:
        raise AssertionError(('frame-rectangle codegen structure unexpectedly diverged',equal))
    if native==candidate:
        raise AssertionError('Unexpected Exact: promote through authored formal oracle first')
    receipt=json.loads(OBJECT.with_suffix('.build.json').read_text())
    if receipt['object_sha256']!=sha256(OBJECT) or receipt['source_sha256']!=sha256(SOURCE):
        raise AssertionError('candidate build receipt mismatch')
    record={
      'schema_version':1,
      'status':'video-frame-rectangle-natural-cpp-prototype-not-exact',
      'original':{'address':hex(ADDRESS),'function_bytes':SIZE,
                  'sha256':hashlib.sha256(native).hexdigest(),
                  'instructions':len(nr),
                  'ordered_directdraw_vtable_calls':['Lock +0x64','Unlock +0x80']},
      'candidate':{'source':str(SOURCE.relative_to(ROOT)),'source_sha256':sha256(SOURCE),
                   'function_bytes':len(candidate),
                   'native_size_delta':len(candidate)-SIZE,
                   'sha256':hashlib.sha256(candidate).hexdigest(),
                   'instructions':len(cr),
                   'normalized_instruction_matches':equal,
                   'coff_relocations':len(relocs),
                   'ordered_directdraw_vtable_calls':['Lock +0x64','Unlock +0x80'],
                   'toolchain_lock_sha256':receipt['toolchain_lock_sha256']},
      'source_contains_inline_assembly_or_padding':False,
      'strict_function_exact':False,
      'qualification':(
        'Native source-level clipping and pitch-aware 8-bit border writes are '
        'reconstructed as ordinary C++. All 125 instructions are decoded and '
        '124 match structurally after hiding stack slots, literal widths and '
        'branches; the remaining source-level expression and stack layout '
        'are not yet proven identical. No authored Exact ledger claim.'
      )
    }
    EVIDENCE.parent.mkdir(parents=True,exist_ok=True)
    EVIDENCE.write_text(json.dumps(record,indent=2)+'\n')
    print(json.dumps({'original_bytes':SIZE,'candidate_bytes':len(candidate),
          'size_delta':len(candidate)-SIZE,'native_instructions':len(nr),
          'candidate_instructions':len(cr),'normalized_matches':equal,
          'exact':False},indent=2))

if __name__=='__main__':main()
