#!/usr/bin/env python3
"""Verify Video::FillRectangle typed C++ without an unsupported Exact claim."""
from pathlib import Path
import json,struct,sys,hashlib,re,subprocess
ROOT=Path(__file__).resolve().parents[2]
sys.path.insert(0,str(ROOT/'scripts'))
from common import verify_target,target_bytes,sha256
from native_build import compile_source
from coff import object_function
SOURCE=ROOT/'workbench/video-fill/VideoFill-natural.cpp'
OBJ=ROOT/'build/video-fill/VideoFill-natural.obj'
LOG=ROOT/'.analysis/build/video-fill-natural.log'
EVIDENCE=ROOT/'docs/evidence/video-fill-natural-progress.json'
SYMBOL='?FillRectangle@Video@@QAEHUSurfaceRect@@E@Z'
START=0x0040B300
NATIVE_SIZE=308
def decode(code,tag):
    bin=ROOT/'.analysis/probes/video-fill'/f'{tag}-verification.bin'
    bin.parent.mkdir(parents=True,exist_ok=True)
    bin.write_bytes(code)
    text=subprocess.run(['objdump','-w','-z','-D','-b','binary','-m','i386','-Mintel',str(bin)],
                        text=True,capture_output=True,check=True).stdout
    results=[]
    for line in text.splitlines():
        m=re.match(r'^\s*([0-9a-f]+):\s+((?:[0-9a-f]{2}\s+)+)\s+(.+)',line)
        if m:results.append((int(m.group(1),16),bytes.fromhex(m.group(2)),m.group(3).strip()))
    if sum(len(x[1]) for x in results)!=len(code):
        raise AssertionError('incomplete disassembly of expected function extent')
    return results
def main():
    source=SOURCE.read_text()
    for name in ('__asm','_emit','__emit','PADDING','FUN_','param_1'):
        if name in source:raise AssertionError(('not natural typed C++',name))
    for token in ('Video::FillRectangle','DDSURFACEDESC','backSurface->Lock',
                  'backSurface->Unlock','description.lPitch','fillColor'):
        if token not in source:raise AssertionError(('missing native semantic operation',token))
    native=target_bytes(verify_target(),START,NATIVE_SIZE)
    if native[-3:]!=bytes.fromhex('c21400'):
        raise AssertionError('original function extent or cleanup size mismatch')
    compile_source(SOURCE,OBJ,['/Od','/G6','/MT','/Gy','/W3'],LOG)
    code,relocs=object_function(OBJ,SYMBOL)
    if relocs:raise AssertionError(('unexpected direct/external relocations',relocs))
    n,c=decode(native,'native'),decode(code,'candidate')
    def virtual_calls(rows):
        return [int(m.group(1),16)
                for _,_,asm in rows
                if (m:=re.fullmatch(r'call\s+DWORD PTR \[[a-z]{3}\+0x([0-9a-f]+)\]',asm))]
    native_com=candidate_com=None
    native_com=virtual_calls(n);candidate_com=virtual_calls(c)
    if native_com!=candidate_com or native_com!=[0x64,0x80]:
        raise AssertionError(('DirectDraw Lock/Unlock dispatch changed',native_com,candidate_com))
    if len(n)!=93 or len(c)!=93:
        raise AssertionError(('native or candidate instruction count unexpected',len(n),len(c)))
    if len(code)==NATIVE_SIZE and code==native:
        raise AssertionError('unexpected Exact candidate: promote through strict oracle instead')
    receipt=json.loads(OBJ.with_suffix('.build.json').read_text())
    if receipt['source_sha256']!=sha256(SOURCE) or receipt['object_sha256']!=sha256(OBJ):
        raise AssertionError('stale compiler receipt')
    report={
        'schema_version':1,
        'status':'video-fill-clipped-directdraw-rect-natural-cpp-prototype-not-exact',
        'original':{'address':hex(START),'size':NATIVE_SIZE,
                    'sha256':hashlib.sha256(native).hexdigest(),
                    'instruction_count':len(n),
                    'ordered_com_vtable_offsets':[hex(x) for x in native_com]},
        'candidate':{'source':str(SOURCE.relative_to(ROOT)),'source_sha256':sha256(SOURCE),
                     'code_sha256':hashlib.sha256(code).hexdigest(),'size':len(code),
                     'native_size_delta':len(code)-NATIVE_SIZE,
                     'instruction_count':len(c),
                     'relocation_count':len(relocs),
                     'ordered_com_vtable_offsets':[hex(x) for x in candidate_com],
                     'toolchain_lock_sha256':receipt['toolchain_lock_sha256']},
        'source_contains_inline_assembly_or_padding':False,
        'strict_function_exact':False,
        'strict_whole_owner_exact':False,
        'qualification':(
            'Complete ordinary C++ rectangle clipping, DirectDraw Lock/Unlock, '
            'and 8-bit pitch-sensitive row-fill candidate for 308-byte Video '
            'owner. All virtual COM call offsets and full candidate compilation '
            'are verified; original loop uses EDI register codegen that has not '
            'yet been recovered. Machine bytes and equivalence remain unproven. '
            'Keep outside the implemented/Exact ledger until strict oracle proof.'
        )
    }
    EVIDENCE.parent.mkdir(parents=True,exist_ok=True)
    EVIDENCE.write_text(json.dumps(report,indent=2)+'\n')
    print('Video FillRectangle:',NATIVE_SIZE,'native bytes,',len(code),
          'candidate bytes, EDI-loop difference; 2/2 COM calls; provisional')
if __name__=='__main__':main()
