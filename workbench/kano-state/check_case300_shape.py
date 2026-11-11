#!/usr/bin/env python3
"""Focused original-bound structural island for Kano state300, NOT Exact.

This audits one *real* authored source state at its original address.
It checks every instruction size/offset and register-abstracted form,
original internal and return branches and independent native float/call
bindings. Concrete machine-register bytes differ upstream at case250.
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

BEGIN=0x00650140
END=0x006505D0
SHA256='9773fc66dde7c1b53a78b118c26031eb45a4d7e4f88691fed2774fa61b07367e'
REFS=[
 (55204,'REL32','?ResetFrame@Secondary@@QAEXXZ',0x0040F1E0),
 (55297,'REL32','?SetTint@Secondary@@QAEXEH@Z',0x00410B10),
 (55318,'REL32','__ftol2',0x007783B8),
 (55344,'REL32','__ftol2',0x007783B8),
 (55392,'REL32','?EmitEffect@Context@@QAEXPAUEffectSpawn@@@Z',0x00407100),
 (55412,'REL32','?ResetFrame@Secondary@@QAEXXZ',0x0040F1E0),
 (55453,'REL32','?ResetFrame@Secondary@@QAEXXZ',0x0040F1E0),
 (55621,'REL32','__ftol2',0x007783B8),
 (55647,'REL32','__ftol2',0x007783B8),
 (55711,'REL32','__ftol2',0x007783B8),
 (55737,'REL32','__ftol2',0x007783B8),
 (55987,'REL32','__ftol2',0x007783B8),
 (56020,'DIR32','__real@0000000000000000',0x007872F8),
]
def main():
    image=verify_target();lo=BEGIN-BASE;hi=END-BASE
    target=target_bytes(image,BASE,hi)
    native=target[lo:hi]
    assert len(native)==1168 and hashlib.sha256(native).hexdigest()==SHA256
    used=make_source(300)
    assert {250,251,254,255,256,257,258,259,260,261,262,263,264,265,266,267,268,269,270,300}.issubset(used)
    assert 252 not in used and 253 not in used
    try:
        compile_source(PROBE,OBJECT,['/Od','/G6','/MT','/Gy','/W3'],
                       ROOT/'.analysis/build/kano-state-case300-diagnostic.log')
        code,rels=object_function(OBJECT,'?Slot06@Character20@@UAEXXZ')
    finally:
        PROBE.unlink(missing_ok=True)
    assert len(code)>hi
    orig=[x for x in disasm(target) if lo<=x[0]<hi]
    cand=[x for x in disasm(code) if lo<=x[0]<hi]
    assert len(orig)==len(cand)==305,(len(orig),len(cand))
    assert orig[0][0]==cand[0][0]==lo
    assert orig[-1][0]+len(orig[-1][1])==hi
    assert cand[-1][0]+len(cand[-1][1])==hi
    for i,(a,b) in enumerate(zip(orig,cand)):
        assert a[0]==b[0] and len(a[1])==len(b[1]),(i,a,b)
        assert norm(a[2])==norm(b[2]),(i,a,b)
    orig_offsets={x[0] for x in orig};compiled_offsets={x[0] for x in cand}
    internal=outbound=0
    for a,b in zip(orig,cand):
        x=BRANCH.fullmatch(a[2]);y=BRANCH.fullmatch(b[2])
        if not x:continue
        assert y,(a,b)
        orig_target=int(x[1],16);compiled_target=int(y[1],16)
        if lo<=orig_target<hi:
            assert orig_target==compiled_target and orig_target in orig_offsets and compiled_target in compiled_offsets,(a,b)
            internal+=1
        else:
            assert BASE+orig_target==0x006536B1,(a,hex(BASE+orig_target))
            outbound+=1
    selected=[r for r in rels if lo<=r['offset']<hi]
    assert len(selected)==len(REFS)==13
    for r,(off,typ,symbol,dst) in zip(selected,REFS):
        assert (r['offset'],r['type'],r['symbol'])==(off,typ,symbol),(r,off,typ,symbol)
        native_dst=(struct.unpack_from('<I',target,off)[0] if typ=='DIR32'
                    else (BASE+off+4+struct.unpack_from('<i',target,off)[0])&0xffffffff)
        assert native_dst==dst,(r,hex(native_dst),hex(dst))
        assert struct.unpack_from('<I',code,off)[0]==0
        if typ=='DIR32':
            assert bytes.fromhex(symbol[len('__real@'):])[::-1]==target_bytes(image,dst,8)
    print(f'Kano state300: 1168 original code bytes / 305 original instructions; {internal} native internal jumps, {outbound} shared-return jumps')
    print('13 original-bound COFF / IEEE-754 operands verified, all instruction offsets/widths/register-abstracted opcode shapes match.')
    print('NOT Exact: concrete-register bytes and case250 compiler phase remain unverified; strict contiguous prefix 40,336 original bytes.')

if __name__=='__main__':main()
