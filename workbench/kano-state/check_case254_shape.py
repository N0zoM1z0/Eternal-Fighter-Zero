#!/usr/bin/env python3
"""Original-bound diagnostic of Kano case254; NOT complete function Exact.

Distinct from the strict selected prefix (which ends before case250).
This checks the authored 835-byte native *island*: full x86 instruction
positions/widths, register-abstracted forms, local flow and native COFF
operands. It does not mask/accept the actual differing register bytes.
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

ORIGINAL_BEGIN=0x0064CB5F
ORIGINAL_END=0x0064CEA2
EXPECTED_SHA='77afeef263e2e92f5601f26e9dd92f44d17ddfc4f14b5f80e143790cc34a64bf'
# Independently resolved against original EFZ.exe; not merely copied
# from the generated candidate's declared relocation symbols.
EXPECTED_REFS=[
 (41411,'REL32','?ResetFrame@Secondary@@QAEXXZ',0x0040F1E0),
 (41469,'REL32','__ftol2',0x007783B8),
 (41495,'REL32','__ftol2',0x007783B8),
 (41559,'REL32','__ftol2',0x007783B8),
 (41585,'REL32','__ftol2',0x007783B8),
 (41673,'REL32','?ResetFrame@Secondary@@QAEXXZ',0x0040F1E0),
 (41835,'DIR32','__real@407f400000000000',0x00787C30),
 (41874,'REL32','?ResetFrame@Secondary@@QAEXXZ',0x0040F1E0),
 (42043,'REL32','__ftol2',0x007783B8),
 (42094,'DIR32','__real@0000000000000000',0x007872F8),
]

def main():
    image=verify_target();lo=ORIGINAL_BEGIN-BASE;hi=ORIGINAL_END-BASE
    original=target_bytes(image,BASE,hi)
    native=original[lo:hi]
    assert len(native)==835 and hashlib.sha256(native).hexdigest()==EXPECTED_SHA
    used=make_source(254)
    assert {250,251,254}.issubset(used) and 252 not in used and 253 not in used
    try:
        compile_source(PROBE,OBJECT,['/Od','/G6','/MT','/Gy','/W3'],
                       ROOT/'.analysis/build/kano-state-case254-diagnostic.log')
        code,relocs=object_function(OBJECT,'?Slot06@Character20@@UAEXXZ')
    finally:
        PROBE.unlink(missing_ok=True)
    assert len(code)>hi
    ori=[x for x in disasm(original) if lo<=x[0]<hi]
    cand=[x for x in disasm(code) if lo<=x[0]<hi]
    assert len(ori)==len(cand)==223,(len(ori),len(cand))
    assert ori[0][0]==cand[0][0]==lo
    assert ori[-1][0]+len(ori[-1][1])==hi
    assert cand[-1][0]+len(cand[-1][1])==hi
    for i,(a,b) in enumerate(zip(ori,cand)):
        assert a[0]==b[0] and len(a[1])==len(b[1]),(i,a,b)
        assert norm(a[2])==norm(b[2]),(i,a,b)
    original_offsets={x[0] for x in ori}
    candidate_offsets={x[0] for x in cand}
    internal=outbound=0
    for a,b in zip(ori,cand):
        orig_jump=BRANCH.fullmatch(a[2]);candidate_jump=BRANCH.fullmatch(b[2])
        if not orig_jump:continue
        assert candidate_jump,(a,b)
        dst=int(orig_jump[1],16);v=int(candidate_jump[1],16)
        if lo<=dst<hi:
            internal+=1
            assert dst==v and dst in original_offsets and v in candidate_offsets,(a,b)
        else:
            outbound+=1
            assert BASE+dst==0x006536B1,(a,hex(BASE+dst))
    assert (internal,outbound)==(20,3),(internal,outbound)
    actual=[r for r in relocs if lo<=r['offset']<hi]
    assert len(actual)==len(EXPECTED_REFS)==10
    for r,(off,typ,sym,dst) in zip(actual,EXPECTED_REFS):
        assert (r['offset'],r['type'],r['symbol'])==(off,typ,sym),r
        raw=struct.unpack_from('<I',original,off)[0]
        native_dst=(raw if typ=='DIR32'
                    else (BASE+off+4+struct.unpack_from('<i',original,off)[0])&0xffffffff)
        assert native_dst==dst,(r,hex(native_dst),hex(dst))
        assert struct.unpack_from('<I',code,off)[0]==0,(r,hex(off))
        if typ=='DIR32':
            assert bytes.fromhex(sym[7:])[::-1]==target_bytes(image,dst,8)
    print(f'Kano case254: independently original-bound 835 bytes / {len(ori)} x86 instructions')
    print(f'{internal} internal branch destinations, {outbound} shared-return branches, 10 original COFF/IEEE-754 bindings verified')
    print('Complete instruction offsets, widths and register-abstracted forms checked; concrete register choices NOT matching.')
    print('NOT EXACT. Strict continuous prefix remains 40,336 bytes ending before case250 at 0x0064C750.')

if __name__=='__main__':main()
