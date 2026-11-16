#!/usr/bin/env python3
"""Selected-only original-target audit of Nanase's natural-C++ CPU prototype.

This is an *open*, nonexact Slot05 workbench. Do not write matching ledgers.
"""
from __future__ import annotations
import argparse
import hashlib
import json
import struct
import sys
from pathlib import Path
ROOT=Path(__file__).resolve().parents[2]
sys.path.insert(0,str(ROOT/'scripts'))
from native_build import compile_source
from coff import object_function
from common import verify_target,target_bytes,sha256

SOURCE=ROOT/'workbench/nanase-cpu/Character00Cpu-natural.cpp'
OBJECT=ROOT/'build/nanase-cpu/Character00Cpu-natural.obj'
REPORT=ROOT/'docs/evidence/nanase-slot05-cpu-natural-progress.json'
SYMBOL='?Slot05@Character00@@UAEXXZ'
ADDRESS=0x0048F690
ORIGINAL_SIZE=14102
VTABLE_SLOT=0x00788348
FLAGS=['/Od','/G6','/MT','/Gy','/W3']
FLOAT_ORIGINALS={
    0x00788370:-280.0,
    0x00788368:-220.0,
    0x00787FA0:-20.0,
    0x007875C8:-100.0,
    0x00787CE0:40.0,
    0x00787CE8:60.0,
    0x00787EE0:80.0,
    0x00787368:120.0,
    0x007875D0:100.0,
    0x00787370:160.0,
    0x00787ED0:220.0,
    0x007882B8:-60.0,
    0x00787EF0:150.0,
}


def main():
    parser=argparse.ArgumentParser(description=__doc__)
    parser.add_argument('--rebuild',action='store_true')
    args=parser.parse_args()
    text=SOURCE.read_text()
    assert 'void Character00::Slot05()' in text
    assert not any(token in text for token in ('__asm','_emit','__emit'))
    required=(
        'field0008 == 0xfb', 'C00->field344c == 0',
        '(*opponentSlot)->velocityX > 0.0',
        '(*opponentSlot)->positionY > -280.0',
        '(*opponentSlot)->positionY > -220.0',
        '(*opponentSlot)->positionY < -20.0',
        'recognizedCommand = 10;', 'recognizedCommand = 0xb;',
        'recognizedCommand = 0xc;',
        'field0008 == 0xa8',
        'recognizedCommand = 0x46;',
        'C00->field344c == 1',
        'buttonPulse[2] = 1;',
        'buttonPulse[0] = 1;',
        'buttonPulse[1] = 1;',
        'buttonPulse[2] = 1;',
    )
    missing=[value for value in required if value not in text]
    if missing:
        raise AssertionError(('native-grounded selection branch missing',missing))
    if args.rebuild:
        compile_source(SOURCE,OBJECT,FLAGS,ROOT/'.analysis/build/nanase-cpu-natural.log')
    manifest=OBJECT.with_suffix('.build.json')
    if not manifest.exists():
        raise AssertionError('CPU selected build missing; use --rebuild')
    receipt=json.loads(manifest.read_text())
    if receipt['source_sha256']!=sha256(SOURCE) or receipt['object_sha256']!=sha256(OBJECT):
        raise AssertionError('CPU selected build stale; use --rebuild')
    image=verify_target()
    vtable=struct.unpack('<I',target_bytes(image,VTABLE_SLOT,4))[0]
    if vtable!=ADDRESS:
        raise AssertionError(('unexpected native vtable owner',hex(vtable)))
    literal_bindings=[]
    for address,value in FLOAT_ORIGINALS.items():
        stored=struct.unpack('<d',target_bytes(image,address,8))[0]
        if stored!=value:
            raise AssertionError(('native literal mismatch',hex(address),value,stored))
        literal_bindings.append({'address':hex(address),'native_double':stored})
    native=target_bytes(image,ADDRESS,ORIGINAL_SIZE)
    candidate,relocs=object_function(OBJECT,SYMBOL)
    original_frame=struct.unpack('<I',native[5:9])[0]
    candidate_frame=struct.unpack('<I',candidate[5:9])[0]
    report={
      'schema_version':1,
      'status':'natural-cpp-cpu-prototype-not-exact',
      'owner':'Character00::Slot05',
      'original':{'address':hex(ADDRESS),'vtable_slot':hex(VTABLE_SLOT),
                  'bytes':len(native),'sha256':hashlib.sha256(native).hexdigest(),
                  'stack_frame_bytes':original_frame},
      'candidate':{'source':str(SOURCE.relative_to(ROOT)),
                   'source_sha256':sha256(SOURCE),
                   'object':str(OBJECT.relative_to(ROOT)),
                   'object_sha256':sha256(OBJECT),
                   'compiler_flags':FLAGS,'bytes':len(candidate),
                   'size_delta':len(candidate)-len(native),
                   'stack_frame_bytes':candidate_frame,
                   'coff_relocations':len(relocs),
                   'toolchain_lock_sha256':receipt['toolchain_lock_sha256']},
      'native_double_operand_sites_verified':literal_bindings,
      'prototype_has_original_bank0_air_intercept':True,
      'prototype_has_original_a8_startup_pulse_choices':True,
      'source_has_inline_asm_or_emitted_opcodes':False,
      'whole_owner_byte_exact':False,
      'qualification':(
        'The original native 0xFB bank0 velocity/height/air-intercept and 0xA8 '
        'startup button/command decisions were reconstructed as C++. The '
        'rest of the owner is still based on the Mayu CPU architecture and '
        'contains unresolved Nanase-specific decisions. Neither 14,102-byte '
        'codegen nor frame layout nor original bound COFF relocations currently '
        'match. This is a workbench only, not a formal Exact receipt.'),
    }
    REPORT.parent.mkdir(parents=True,exist_ok=True)
    REPORT.write_text(json.dumps(report,indent=2)+'\n')
    print(json.dumps({'status':report['status'],
                      'native_bytes':len(native),'candidate_bytes':len(candidate),
                      'native_frame':original_frame,'candidate_frame':candidate_frame,
                      'relocations':len(relocs),'verified_original_literals':len(literal_bindings),
                      'byte_exact':False},indent=2))

if __name__=='__main__':main()
