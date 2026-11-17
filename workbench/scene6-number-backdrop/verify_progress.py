#!/usr/bin/env python3
"""Selected native/VC7.1 PE comparison for the non-Exact Scene6 615-byte owner.

No full cold replay; rejects stale builds and any invented relocation targets.
"""
from pathlib import Path
import hashlib, json, sys
ROOT=Path(__file__).resolve().parents[2]
sys.path.insert(0,str(ROOT/'scripts'))
from native_build import compile_source
from common import verify_target, target_bytes, sha256
from coff import object_function
from oracle import complete_compare

SOURCE=ROOT/'src/Scene6NumberBackdrop.cpp'
STRINGS=ROOT/'src/Scene6BackdropPaths.cpp'
OBJ=ROOT/'build/scene6-number-backdrop/Scene6NumberBackdrop.obj'
LOG=ROOT/'.analysis/build/Scene6NumberBackdrop.log'
PROOF=ROOT/'docs/evidence/scene6-number-backdrop-natural-progress.json'
NATIVE_VA=0x0075D660
NATIVE_SIZE=615
SYMBOL='?TransitionNumberBackdrop@Scene6@@QAEXXZ'
TARGETS={
 '___security_cookie':0x0078F050,
 '__imp__timeGetTime@0':0x007871E0,
 '?DarkenPalette@Video@@QAEXPBEEEE@Z':0x0040BE20,
 '?scene6BackdropNumberPrefix@@3QBDB':0x00789580,
 '_strcpy':0x00778080,
 '?scene6BackdropHundredsZero@@3QBDB':0x00789590,
 '?scene6BackdropTensZero@@3QBDB':0x00789594,
 '_strcat':0x00778090,
 '__itoa':0x00777F55,
 '?scene6BackdropPackedExtension@@3QBDB':0x00789598,
 '?LoadObjectFile@Context@@QAEXPAPAUIUnknown@@PBDEE@Z':0x00406DB0,
 '?LoadPalette@Video@@QAEHPAEPBDHHH@Z':0x0040B760,
 '?scene6BackdropBitmapExtension@@3QBDB':0x007895A0,
 '?LoadSurface@Video@@QAE?AUSurfaceRect@@PAPAUIUnknown@@PBDE@Z':0x00408D00,
 '?LoadBitmapPalette@Video@@QAEHPAEPBDHHH@Z':0x0040B640,
 '@__security_check_cookie@4':0x007781DC,
}
STRING_DATA=[
 (0x00789580,b'system\\nl\\nl\x00'),
 (0x00789590,b'0\x00'),
 (0x00789594,b'0\x00'),
 (0x00789598,b'.dat\x00'),
 (0x007895A0,b'.bmp\x00'),
]

def main():
    source=SOURCE.read_text()
    for forbidden in ('__asm','__emit','_emit','PADDING','FUN_','param_1'):
        if forbidden in source:
            raise AssertionError(('non-natural C++ token',forbidden))
    for needed in (
        'void Scene6::TransitionNumberBackdrop()',
        'frame = 10', 'frame >= 0','frame = 0','frame <= 10',
        'clock.lastTick = timeGetTime()', 'clock.alternateDelay',
        'std::strcat(filename, scene6BackdropPackedExtension)',
        'std::strcat(filename, scene6BackdropBitmapExtension)',
        'numberBackdrop->Release()', 'videoOwner->DarkenPalette(',
        'contextOwner->LoadObjectFile(&numberBackdrop',
        'videoOwner->LoadBitmapPalette(', 'numberBackdropPhase = 2'):
        if needed not in source:raise AssertionError(('missing native behavior',needed))
    image=verify_target()
    for addr,data in STRING_DATA:
        if target_bytes(image,addr,len(data))!=data:
            raise AssertionError(('native asset filename differs',hex(addr)))
    native=target_bytes(image,NATIVE_VA,NATIVE_SIZE)
    compile_source(SOURCE,OBJ,['/Od','/G6','/MT','/Gy','/W3','/GS'],LOG)
    c,rs=object_function(OBJ,SYMBOL)
    if len(rs)!=25:raise AssertionError(('native COFF references changed',rs))
    expected=[
        {'offset':r['offset'],'type':r['type'],'symbol':r['symbol'],
         'target':TARGETS[r['symbol']],
         'evidence':'complete original PE instruction operand '+hex(NATIVE_VA+r['offset'])}
        for r in rs
    ]
    report=complete_compare(c,native,rs,expected,NATIVE_VA)
    if len(c)!=NATIVE_SIZE or report['difference_count']>36 or report['result']=='exact':
        raise AssertionError(('unexpected native branch/body status',
                              len(c),report['difference_count'],report['result']))
    receipt=json.loads(OBJ.with_suffix('.build.json').read_text())
    if receipt['source_sha256']!=sha256(SOURCE) or receipt['object_sha256']!=sha256(OBJ):
        raise AssertionError('stale object against source or compiler receipt')
    PROOF.write_text(json.dumps({
        'schema_version':1,
        'status':'scene6-timed-background-preview-natural-cpp-prototype-not-exact',
        'original':{'address':hex(NATIVE_VA),'extent_bytes':NATIVE_SIZE,
                    'sha256':hashlib.sha256(native).hexdigest(),
                    'resource_string_addresses':[hex(a) for a,_ in STRING_DATA],
                    'named_relocations':[{'symbol':r['symbol'],
                                          'native_pe_target':hex(TARGETS[r['symbol']])}
                                         for r in rs]},
        'candidate':{'source':str(SOURCE.relative_to(ROOT)),
                     'resource_data':str(STRINGS.relative_to(ROOT)),
                     'source_sha256':sha256(SOURCE),
                     'source_resource_sha256':sha256(STRINGS),
                     'function_bytes':len(c),
                     'native_size_delta':len(c)-NATIVE_SIZE,
                     'native_bytes_matching_after_binding':report['matched_bytes'],
                     'native_machine_differing_bytes':report['difference_count'],
                     'reconstructed_local_scene_fields':[
                         'numberBackdrop@0x444','numberBackdropPhase@0x44d',
                         'numberBackdropIndex@0x758'],
                     'compiler_profile':'vc71-od-static-gs',
                     'toolchain_lock_sha256':receipt['toolchain_lock_sha256'],
                     'native_relocation_count':len(rs)},
        'strict_function_exact':False,
        'source_contains_inline_asm_or_padding':False,
        'qualification':(
            'Ordinary C++ recovers both 11-frame WINMM timed palette fades, '
            'three-digit filename from original PE strings, live IUnknown release, '
            'packed .dat and alternate .bmp asset loads and native 0x44D flag. '
            'The original 615-byte owner and all 25 relocation targets are '
            'bound; 36 byte-level differences remain in compiler-local stack '
            'positions and frame-lifetime codegen. Not promoted to authored Exact.'
        ),
    },indent=2)+'\n')
    print('Scene6 number transition:',report['result'],
          report['matched_bytes'],'/',NATIVE_SIZE,
          'differences',report['difference_count'],'relocs',len(rs),
          'strict Exact',False)

if __name__=='__main__':main()
