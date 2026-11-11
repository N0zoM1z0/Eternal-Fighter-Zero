#!/usr/bin/env python3
"""Diagnostic original-bound cases261/262, NOT full-function Exact.

The strict contiguous Kano prefix still ends before unresolved case250.
This independent audit checks real authored native islands against
original case boundaries, register-abstracted opcode forms and
independently original-bound relocation/callee targets. It does not
claim exact concrete register allocations or accepted owner bytes.
"""
from pathlib import Path
import hashlib,struct,sys
ROOT=Path(__file__).resolve().parents[2]
sys.path.insert(0,str(ROOT/'scripts'))
from common import verify_target,target_bytes
from native_build import compile_source
from coff import object_function
from probe_prefix import BASE,OBJECT,PROBE,disasm,make_source
from check_case251_shape import BRANCH,norm

CASES=[
 (261,0x0064E726,0x0064EA72,
  '6c4022125cf45bd4f28071a6d57cdee55c198e029bcdbdad92d0dd4804331e64',
  [48522, 48573, 48735, 48774, 48836, 48862, 48926, 48952, 49157]),
 (262,0x0064EA72,0x0064EDBE,
  '4b85f852339cdc18e61d04e52a03380092fa9e4f53b1ce27a8474724b57e698b',
  [49366, 49417, 49579, 49618, 49680, 49706, 49770, 49796, 50001]),
]# Original instrumented call/float operands in nine original positions
# of both 844-byte state blocks, checked independently against EFZ.exe.
REF_SPEC=[
 ('REL32','?ResetFrame@Secondary@@QAEXXZ',0x0040F1E0),
 ('REL32','?ResetFrame@Secondary@@QAEXXZ',0x0040F1E0),
 ('DIR32','__real@407f400000000000',0x00787C30),
 ('REL32','?ResetFrame@Secondary@@QAEXXZ',0x0040F1E0),
 ('REL32','__ftol2',0x007783B8),
 ('REL32','__ftol2',0x007783B8),
 ('REL32','__ftol2',0x007783B8),
 ('REL32','__ftol2',0x007783B8),
 ('DIR32','__real@c054000000000000',0x007880D8),
]
def main():
    image=verify_target()
    end=CASES[-1][2]-BASE
    native_bytes=target_bytes(image,BASE,end)
    used=make_source(262)
    assert {250,251,254,255,256,257,258,259,260,261,262}.issubset(used)
    assert 252 not in used and 253 not in used
    try:
        compile_source(PROBE,OBJECT,['/Od','/G6','/MT','/Gy','/W3'],
                       ROOT/'.analysis/build/kano-state-case261-262-diagnostic.log')
        code,relocs=object_function(OBJECT,'?Slot06@Character20@@UAEXXZ')
    finally:
        PROBE.unlink(missing_ok=True)
    assert len(code)>end
    original_inst=disasm(native_bytes)
    compiled_inst=disasm(code)
    total_internal=total_outbound=0
    for n,start,finish,sha,ref_offsets in CASES:
        lo=start-BASE;hi=finish-BASE
        original_island=native_bytes[lo:hi]
        assert len(original_island)==844 and hashlib.sha256(original_island).hexdigest()==sha
        orig=[i for i in original_inst if lo<=i[0]<hi]
        cand=[i for i in compiled_inst if lo<=i[0]<hi]
        assert len(orig)==len(cand)==225,(n,len(orig),len(cand))
        assert orig[0][0]==cand[0][0]==lo
        assert orig[-1][0]+len(orig[-1][1])==hi
        assert cand[-1][0]+len(cand[-1][1])==hi
        for i,(a,b) in enumerate(zip(orig,cand)):
            assert a[0]==b[0] and len(a[1])==len(b[1]),(n,i,a,b)
            assert norm(a[2])==norm(b[2]),(n,i,a,b)
        offsets={x[0] for x in orig};candidates={x[0] for x in cand}
        internal=outbound=0
        for a,b in zip(orig,cand):
            x=BRANCH.fullmatch(a[2]);y=BRANCH.fullmatch(b[2])
            if not x:continue
            assert y,(n,a,b)
            original_target=int(x[1],16);candidate_target=int(y[1],16)
            if lo<=original_target<hi:
                assert original_target==candidate_target
                assert original_target in offsets and candidate_target in candidates
                internal+=1
            else:
                assert BASE+original_target==0x006536B1,(n,a)
                outbound+=1
        assert (internal,outbound)==(20,3),(n,internal,outbound)
        refs=[r for r in relocs if lo<=r['offset']<hi]
        assert len(refs)==len(REF_SPEC)==len(ref_offsets)==9,(n,len(refs))
        for r,off,(kind,sym,dst) in zip(refs,ref_offsets,REF_SPEC):
            assert (r['offset'],r['type'],r['symbol'])==(off,kind,sym),(n,r,off,kind,sym)
            actual=struct.unpack_from('<I',native_bytes,off)[0] if kind=='DIR32' else (
                BASE+off+4+struct.unpack_from('<i',native_bytes,off)[0])&0xffffffff
            assert actual==dst,(n,r,hex(actual),hex(dst))
            assert struct.unpack_from('<I',code,off)[0]==0
            if kind=='DIR32':
                assert bytes.fromhex(sym[len('__real@'):])[::-1]==target_bytes(image,dst,8)
        total_internal+=internal;total_outbound+=outbound
        print(f'Kano state{n}: {len(original_island)} original bytes / {len(orig)} x86 instructions; {internal} internal branches / {outbound} original shared-return branches / 9 original relocation bindings.')
    print(f'TOTAL: 1688 native bytes / 450 original native instructions, {total_internal} internal, {total_outbound} outbound, 18 original call/float bindings.')
    print('All original instruction positions, widths, register-abstracted forms and internal branch targets checked.')
    print('NOT Exact: concrete registers mismatch due to original case250 phase. Strict contiguous prefix remains 40,336 bytes.')

if __name__=='__main__':main()
