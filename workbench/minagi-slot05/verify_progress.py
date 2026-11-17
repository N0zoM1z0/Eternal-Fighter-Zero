#!/usr/bin/env python3
"""Target-bound local proof of Minagi Slot05 natural-C++ CPU decision candidate.

No Exact claim: validates native vtable identity, 111 directly called helpers,
and all 207 canonical x87 float/double constant references by value/multiplicity.
"""
from __future__ import annotations
import argparse
import collections
from difflib import SequenceMatcher
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

def calls_with_random_bounds(data:bytes, name:str,
                             call_targets:list[tuple[int,int]], base:int=0):
    """Track call order *and* original RandomRange immediate upper bounds.

    Every source/original RandomRange here pushes an immediate upper bound and
    lower bound zero immediately before ECX=this and the direct E8 call.
    Comparing targets alone misses random-reordering regressions.
    """
    instructions=[]
    for line in disasm(data,name,base):
        entry=re.match(r'^\s*([0-9a-f]+):\s+((?:[0-9a-f]{2}\s+)+)\s+(.+)$',
                       line)
        if entry:
            instructions.append((int(entry.group(1),16)-base,
                                 entry.group(3).strip()))
    by_offset={off:i for i,(off,asm) in enumerate(instructions)}
    result=[]
    for offset,target in call_targets:
        if offset not in by_offset:
            raise AssertionError(('direct helper call missing from disassembly',
                                  name,hex(offset)))
        i=by_offset[offset]
        if not instructions[i][1].startswith('call '):
            raise AssertionError(('not an E8 call instruction',name,offset))
        limit=None
        if target==0x004108A0:
            # The two argument pushes must be the last two preceding
            # immediate pushes (the lower bound is always zero in this owner).
            pushes=[]
            for _,asm in instructions[max(0,i-10):i]:
                match=re.fullmatch(r'push\s+(0x[0-9a-f]+|[0-9]+)',asm)
                if match:
                    pushes.append(int(match.group(1),0))
            if len(pushes)<2 or pushes[-1]!=0:
                raise AssertionError(('cannot verify RandomRange arguments',
                                      name,hex(offset),pushes))
            limit=pushes[-2]
        result.append((target,limit))
    return result



def native_fp_operation_window(code: bytes, name: str, offset: int,
                               *, after_call: bool) -> list[str]:
    """Disassemble original/candidate x87 operation signatures around a
    known, real helper call site. Ignore register allocation and local offsets.
    """
    rows=[]
    for line in disasm(code,name):
        m=re.match(r'^\s*([0-9a-f]+):\s+((?:[0-9a-f]{2}\s+)+)\s+(.+)',line)
        if m:rows.append((int(m.group(1),16),m.group(3).strip()))
    lookup={at:i for i,(at,_) in enumerate(rows)}
    if offset not in lookup:
        raise AssertionError(('missing native/candidate x87 anchor',name,offset))
    idx=lookup[offset]
    if not rows[idx][1].startswith('call '):
        raise AssertionError(('x87 anchor not at call instruction',name,offset))
    if after_call:
        selected=rows[idx+1:idx+38]
    else:
        selected=rows[max(0,idx-35):idx]
    floating=[]
    for at,op in selected:
        mnemonic=op.split()[0]
        if mnemonic not in {'fld','fsub','fild','fmul','fadd','fmulp',
                            'fstp','fcompp','fiadd'}:continue
        if 'QWORD PTR' in op and '+0x20]' in op:
            floating.append(mnemonic+':x')
        elif 'QWORD PTR' in op and '+0x28]' in op:
            floating.append(mnemonic+':y')
        elif 'DWORD PTR' in op and '+0xa8]' in op:
            floating.append(mnemonic+':cpu-scale')
        else:
            floating.append(mnemonic)
        if after_call and floating[-1]=='fcompp':
            break
    if after_call and (not floating or floating[-1]!='fcompp'):
        raise AssertionError(('second native CPU guard comparison not found',name,offset,floating))
    return floating

def normalized_instruction_progress(native:bytes, candidate:bytes)->dict:
    """207-float-anchor structural diagnostic; never an Exact certificate.

    A compiler-private register or stack allocation may differ despite
    restored C++ semantics. Branch operands and data-reference addresses are
    intentionally masked, but instruction widths and mnemonics are retained.
    """
    def decode(data:bytes, name:str):
        instructions=[]
        constants=[]
        for line in disasm(data,f'{name}-shape.bin'):
            m=re.match(r'^\s*[0-9a-f]+:\s+((?:[0-9a-f]{2}\s+)+)\s+(.+)',line)
            if m is None:continue
            asm=m[2].strip()
            if 'ds:0x' in asm:constants.append(len(instructions))
            parts=asm.lower().split(None,1)
            op=parts[0]
            operand=parts[1] if len(parts)>1 else ''
            if op in ('call','jmp','je','jne','jz','jnz','jg','jge','jl','jle',
                      'ja','jae','jb','jbe','jo','jno','js','jns','jp','jnp','jecxz'):
                operand='<rel>'
            operand=re.sub(r'0x[0-9a-f]+','<hex>',operand)
            operand=re.sub(r'\[ebp(?:-|\+)0x[0-9a-f]+\]','[ebp+LOCAL]',operand)
            instructions.append(op+' '+operand)
        if len(constants)!=207:
            raise AssertionError(('native 207 constant anchors changed',name,len(constants)))
        return instructions,constants
    na,nn=decode(native,'original')
    ca,cc=decode(candidate,'candidate')
    a=[-1]+nn+[len(na)]
    b=[-1]+cc+[len(ca)]
    equal=0
    changed=0
    for i in range(208):
        lhs=na[a[i]+1:a[i+1]]
        rhs=ca[b[i]+1:b[i+1]]
        common=sum(x2-x1 for kind,x1,x2,y1,y2 in
                   SequenceMatcher(None,lhs,rhs,autojunk=False).get_opcodes()
                   if kind=='equal')
        equal+=common
        if common!=len(lhs) or common!=len(rhs):changed+=1
    return {
        'native_decoded_instructions':len(na),
        'candidate_decoded_instructions':len(ca),
        'normalized_instructions_matching_between_207_float_anchors':equal,
        'changed_float_anchor_regions':changed,
        'float_anchor_regions_compared':208,
        'provisional_structural_diagnostic_only':True,
    }


def main():
    parser=argparse.ArgumentParser(description=__doc__)
    parser.add_argument('--rebuild',action='store_true')
    opts=parser.parse_args()
    text=SOURCE.read_text()
    if 'void Character21::Slot05()' not in text:
        raise AssertionError('missing natural C++ Minagi CPU Slot05 owner')
    if text.count('field0118 > 500.0')!=14 or '500.0 < field0118' in text:
        raise AssertionError('native CPU distance/load first x87 comparisons regressed')
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
    native_signatures=calls_with_random_bounds(
        native,'original-direct-arg-audit.bin',native_calls,ORIGINAL)
    candidate_signatures=calls_with_random_bounds(
        candidate,'candidate-direct-arg-audit.bin',
        [(off,target) for off,target,_ in called])
    call_bounds_in_order=sum(a==b for a,b in zip(
        native_signatures,candidate_signatures))
    # Record honest positional ordering as a progress metric; no false
    # "all in order" assertion before the original CPU branch layout is solved.
    # Stronger invariant: every native helper target and every RandomRange
    # upper bound occurs with the same multiplicity in the compiled candidate.
    native_signature_counts=collections.Counter(native_signatures)
    candidate_signature_counts=collections.Counter(candidate_signatures)
    if native_signature_counts!=candidate_signature_counts:
        raise AssertionError(('CPU native/candidate helper target and random bounds differ',
                              native_signature_counts-candidate_signature_counts,
                              candidate_signature_counts-native_signature_counts))
    if call_bounds_in_order!=len(native_calls):
        raise AssertionError(('CPU helper target / RandomRange argument order differs',
                              call_bounds_in_order,len(native_calls)))
    # The original 2000-range guard builds the airborne factor *first*,
    # scales it by 8 and CPU difficulty, and multiplies the state factor last.
    # The original distance path subtracts opponent/owner X, converts facing
    # using FILD and FMULP, then subtracts the two Y values before CRT fabs.
    # Check x87 operations, not arbitrary compiler register/local choices.
    native_guard_site=[off for off,target in native_calls if target==0x004108A0][1]
    candidate_guard_site=[off for off,target,_ in called if target==0x004108A0][1]
    native_guard_fp=native_fp_operation_window(
        native,'guard-original-x87.bin',native_guard_site,after_call=True)
    candidate_guard_fp=native_fp_operation_window(
        candidate,'guard-candidate-x87.bin',candidate_guard_site,after_call=True)
    if native_guard_fp!=candidate_guard_fp:
        raise AssertionError(('guard probability x87 arithmetic order diverged',
                              native_guard_fp,candidate_guard_fp))
    # Five distinct native guard/defense RNG decisions consume the random
    # draw *before* x87 computes its CPU difficulty-scaled threshold.
    # Inverted comparisons in source intentionally preserve unordered (NaN)
    # behavior as compiled by original VC7.1 test ah,0x41 branches.
    rng_first_sites=[4,36,95,96,99]
    rng_first_x87=['fild','fld','fmul:cpu-scale','fcompp']
    for order in rng_first_sites:
        native_rng_at,native_target=native_calls[order]
        candidate_rng_at,candidate_target,_=called[order]
        if native_target!=0x004108A0 or candidate_target!=native_target:
            raise AssertionError(('RNG-first site is not the bound RNG',
                                  order,native_target,candidate_target))
        orig_fp=native_fp_operation_window(
            native,f'rng-first-original-{order}.bin',native_rng_at,after_call=True)
        cand_fp=native_fp_operation_window(
            candidate,f'rng-first-candidate-{order}.bin',candidate_rng_at,after_call=True)
        if orig_fp!=rng_first_x87 or cand_fp!=rng_first_x87:
            raise AssertionError(('RNG-first x87 order differs',
                                  order,rng_first_x87,orig_fp,cand_fp))
    native_fabs_site=[off for off,target in native_calls if target==0x0077842D][0]
    candidate_fabs_site=[off for off,target,_ in called if target==0x0077842D][0]
    native_distance_fp=native_fp_operation_window(
        native,'distance-original-x87.bin',native_fabs_site,after_call=False)[-8:]
    candidate_distance_fp=native_fp_operation_window(
        candidate,'distance-candidate-x87.bin',candidate_fabs_site,after_call=False)[-8:]
    expected_distance=['fld:x','fsub:x','fild','fmulp','fstp','fld:y','fsub:y','fstp']
    if native_distance_fp!=expected_distance or candidate_distance_fp!=native_distance_fp:
        raise AssertionError(('opponent distance x87 arithmetic shape diverged',
                              expected_distance,native_distance_fp,candidate_distance_fp))
    fp_operation_hash=hashlib.sha256(json.dumps(
        [native_guard_fp,native_distance_fp],separators=(',',':')
    ).encode()).hexdigest()
    call_signature_sha=hashlib.sha256(json.dumps(
        native_signatures,separators=(',',':')).encode()).hexdigest()
    candidate_call_signature_sha=hashlib.sha256(json.dumps(
        candidate_signatures,separators=(',',':')).encode()).hexdigest()
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
    if literal_order_matches!=len(native_literals):
        raise AssertionError(('CPU original static float reference order differs',
                              literal_order_matches,len(native_literals)))
    structural_progress=normalized_instruction_progress(native,candidate)
    if structural_progress['normalized_instructions_matching_between_207_float_anchors']<2807:
        raise AssertionError(('Minagi CPU 500.0 x87 instruction order regression',
                              structural_progress))
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
            'direct_call_with_rng_bound_order_sha256':call_signature_sha,
            'static_floating_literal_refs':len(native_literals),
            'cpu_guard_x87_operations':native_guard_fp,
            'rng_first_scaled_float_call_indices':rng_first_sites,
            'rng_first_scaled_float_x87_operations':rng_first_x87,
            'cpu_forward_and_vertical_x87_operations':native_distance_fp,
            'cpu_guard_and_distance_x87_sequence_sha256':fp_operation_hash,
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
            'direct_calls_with_rng_bounds_in_original_order':call_bounds_in_order,
            'direct_calls_with_rng_bounds_out_of_original_order':len(native_calls)-call_bounds_in_order,
            'direct_calls_and_rng_bounds_multiset_match_original':True,
            'direct_call_with_rng_bound_order_sha256':candidate_call_signature_sha,
            'static_floating_literal_refs':len(candidate_literals),
            'static_floating_literals_values_match_native':True,
            'static_floating_literals_in_original_order':literal_order_matches,
            'static_floating_literals_out_of_original_order':len(native_literals)-literal_order_matches,
            'cpu_guard_and_distance_x87_operation_order_matches_original':True,
            'five_rng_first_scaled_float_comparisons_match_native':True,
            'fourteen_native_cpu_distance_threshold_comparisons_restored':True,
            'instruction_shape_audit':structural_progress,
            'cpu_guard_and_distance_x87_sequence_sha256':fp_operation_hash,
            'static_floating_literal_histogram_sha256':histogram_sha,
        },
        'source_contains_inline_asm_or_padding':False,
        'strict_function_exact':False,
        'strict_whole_owner_exact':False,
        'qualification':(
            'This is a full natural-C++ CPU decision candidate, with 111 native '
            'external helper calls matched by target multiplicity and 207 x87 '
            'static floating references matched by IEEE-754 value and count. '
            'All 111 helper targets and all 108 RandomRange immediate bounds '
            'match the original in instruction order. All 207 original static '
            'floating references match value, width and order. The full '
            'code size, instruction identity, branch-specific side-effect '
            'ordering and '
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
        'direct_calls_with_rng_bounds_in_native_order':call_bounds_in_order,
        'static_literal_values_matched':len(candidate_literals),
        'static_literals_in_native_order':literal_order_matches,
        'cpu_guard_and_distance_x87_order_matches_original':True,
        'rng_first_scaled_float_sites_verified':len(rng_first_sites),
        'native_order_cpu_distance_threshold_compares':14,
        'structural_instruction_alignment':structural_progress['normalized_instructions_matching_between_207_float_anchors'],
        'exact':False
    },indent=2))

if __name__=='__main__': main()
