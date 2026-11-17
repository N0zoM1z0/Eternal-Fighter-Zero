#!/usr/bin/env python3
"""Selected VC7.1 proof for natural 320x240->640x480 conversion candidate.

This is NOT an Exact claim; the whole native owner remains 403 bytes.
"""
from pathlib import Path
import hashlib,json,re,subprocess,sys
ROOT=Path(__file__).resolve().parents[2]
sys.path.insert(0,str(ROOT/'scripts'))
from common import verify_target,target_bytes,sha256
from coff import object_function
from native_build import compile_source

SRC=ROOT/'workbench/video-convert-backbuffer/VideoConvert-natural.cpp'
OBJ=ROOT/'build/video-convert-backbuffer/VideoConvert-natural.obj'
LOG=ROOT/'.analysis/build/video-convert-backbuffer-natural.log'
EVIDENCE=ROOT/'docs/evidence/video-convert-backbuffer-natural-progress.json'
ADDR=0x0040B440
ORIGINAL_SIZE=403
SYMBOL='?ConvertBackBuffer@Video@@QAEHXZ'
MAKE_RECT='?MakeSurfaceRect@@YA?AUSurfaceRect@@HHHH@Z'

def instruction_rows(code: bytes, suffix: str):
    binary=ROOT/'.analysis/probes/video-convert-backbuffer'/f'{suffix}-verified.bin'
    binary.parent.mkdir(parents=True,exist_ok=True)
    binary.write_bytes(code)
    result=subprocess.run(
        ['objdump','-w','-z','-D','-b','binary','-m','i386','-Mintel',str(binary)],
        text=True,capture_output=True,check=True).stdout
    rows=[]
    for line in result.splitlines():
        match=re.match(r'^\s*([0-9a-f]+):\s+((?:[0-9a-f]{2}\s+)+)\s+(.+)',line)
        if match:
            rows.append((int(match.group(1),16),bytes.fromhex(match.group(2)),
                         match.group(3).strip()))
    if sum(len(row[1]) for row in rows)!=len(code):
        raise AssertionError(('partial native function disassembly',suffix))
    return rows

def com_calls(rows):
    result=[]
    for _offset,_bytes,asm in rows:
        match=re.fullmatch(r'call\s+(?:DWORD PTR )?\[[a-z]{3}\+0x([0-9a-f]+)\]',asm)
        if match:result.append(int(match.group(1),16))
    return result

def verify():
    source=SRC.read_text()
    for bad in ('__asm','__emit','_emit','PADDING','FUN_','param_1'):
        if bad in source:raise AssertionError(('non-natural source',bad))
    for required in ('Video::ConvertBackBuffer()', 'MakeSurfaceRect(0, 0, 640, 480)',
                     'sourceRow[x]','destinationRow[x * 2]','destinationRow[x * 2 + 1]',
                     'destinationRow[x * 2 + pitch]','destinationRow[x * 2 + pitch + 1]',
                     'sourceRow -= pitch','destinationRow -= pitch * 2',
                     'backSurface->Lock','backSurface->Unlock'):
        if required not in source:
            raise AssertionError(('missing in-place 2x2 expansion operation',required))
    original=target_bytes(verify_target(),ADDR,ORIGINAL_SIZE)
    compile_source(SRC,OBJ,['/Od','/G6','/MT','/Gy','/W3'],LOG)
    candidate,relocations=object_function(OBJ,SYMBOL)
    if len(relocations)!=1 or relocations[0]['symbol']!=MAKE_RECT or relocations[0]['type']!='REL32':
        raise AssertionError(('unbound original native rectangle helper',relocations))
    native_rows=instruction_rows(original,'original')
    candidate_rows=instruction_rows(candidate,'candidate')
    native_com=com_calls(native_rows)
    candidate_com=com_calls(candidate_rows)
    if native_com!=candidate_com or native_com!=[0x64,0x80]:
        raise AssertionError(('DirectDraw Lock/Unlock COM dispatch changed',
                              native_com,candidate_com))
    if candidate==original:
        raise AssertionError('Unexpected byte Exact; complete native proof and formal ledger required')
    receipt=json.loads(OBJ.with_suffix('.build.json').read_text())
    if receipt['source_sha256']!=sha256(SRC) or receipt['object_sha256']!=sha256(OBJ):
        raise AssertionError('stale pinned compiler receipt')
    report={
      'schema_version':1,
      'status':'video-convert-backbuffer-320x240-to-640x480-natural-cpp-prototype-not-exact',
      'original':{'address':hex(ADDR),'full_function_bytes':ORIGINAL_SIZE,
                  'sha256':hashlib.sha256(original).hexdigest(),
                  'instruction_count':len(native_rows),
                  'ordered_com_vtable_offsets':[hex(x) for x in native_com],
                  'native_make_surface_rect_address':'0x0040C590'},
      'candidate':{'source':str(SRC.relative_to(ROOT)), 'source_sha256':sha256(SRC),
                   'code_sha256':hashlib.sha256(candidate).hexdigest(),
                   'full_function_bytes':len(candidate),
                   'native_size_delta':len(candidate)-ORIGINAL_SIZE,
                   'instruction_count':len(candidate_rows),
                   'coff_relocations':relocations,
                   'ordered_com_vtable_offsets':[hex(x) for x in candidate_com],
                   'toolchain_lock_sha256':receipt['toolchain_lock_sha256']},
      'source_contains_inline_assembly_or_padding':False,
      'strict_function_exact':False,
      'strict_whole_owner_exact':False,
      'qualification':(
        'Full ordinary C++ algorithm for bottom-up/right-to-left in-place '
        '8-bit 2x2 pixel expansion. The native SurfaceRect sret helper and '
        'both DirectDraw Lock/Unlock virtual dispatch positions were verified '
        'by original PE disassembly and compiled COFF. Original machine body '
        'is 403 bytes but current candidate differs in stack and pixel-loop '
        'register/codegen; no native runtime or full byte equivalence is claimed. '
        'Remain outside implemented/matches Exact ledger.'
      )
    }
    EVIDENCE.parent.mkdir(parents=True,exist_ok=True)
    EVIDENCE.write_text(json.dumps(report,indent=2)+'\n')
    print('Video::ConvertBackBuffer:',ORIGINAL_SIZE,'native bytes,',
          len(candidate),'natural C++ bytes, 1 native-bound helper,',
          len(native_com),'COM calls, STRICT Exact false')

if __name__=='__main__':verify()
