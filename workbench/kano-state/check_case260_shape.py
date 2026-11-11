#!/usr/bin/env python3
"""Focused original-bound structural island for Kano state260, NOT Exact.

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

BEGIN=0x0064E3F1
END=0x0064E726
SHA256='969f7e5aa8c2ac6f4ece7f972603f627cd1d5bfae4b85375632f276a9e9707c9'
REFS=[
 (47701,'REL32','?ResetFrame@Secondary@@QAEXXZ',0x0040F1E0),
 (47752,'REL32','?ResetFrame@Secondary@@QAEXXZ',0x0040F1E0),
 (47914,'DIR32','__real@407f400000000000',0x00787C30),
 (47953,'REL32','?ResetFrame@Secondary@@QAEXXZ',0x0040F1E0),
 (48015,'REL32','__ftol2',0x007783B8),
 (48041,'REL32','__ftol2',0x007783B8),
 (48105,'REL32','__ftol2',0x007783B8),
 (48131,'REL32','__ftol2',0x007783B8),
 (48336,'DIR32','__real@c054000000000000',0x007880D8),
]

def main():
    image=verify_target();lo=BEGIN-BASE;hi=END-BASE
    target=target_bytes(image,BASE,hi)
    native=target[lo:hi]
    assert len(native)==821 and hashlib.sha256(native).hexdigest()==SHA256
    used=make_source(260)
    assert {250,251,254,255,256,257,258,259,260}.issubset(used)
    assert 252 not in used and 253 not in used
    try:
        compile_source(PROBE,OBJECT,['/Od','/G6','/MT','/Gy','/W3'],
                       ROOT/'.analysis/build/kano-state-case258-diagnostic.log')
        code,rels=object_function(OBJECT,'?Slot06@Character20@@UAEXXZ')
    finally:
        PROBE.unlink(missing_ok=True)
    assert len(code)>hi
    orig=[x for x in disasm(target) if lo<=x[0]<hi]
    cand=[x for x in disasm(code) if lo<=x[0]<hi]
    assert len(orig)==len(cand)==220,(len(orig),len(cand))
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
    assert (internal,outbound)==(20,3),(internal,outbound)
    selected=[r for r in rels if lo<=r['offset']<hi]
    assert len(selected)==len(REFS)==9
    for r,(off,typ,symbol,dst) in zip(selected,REFS):
        assert (r['offset'],r['type'],r['symbol'])==(off,typ,symbol),(r,off,typ,symbol)
        native_dst=(struct.unpack_from('<I',target,off)[0] if typ=='DIR32'
                    else (BASE+off+4+struct.unpack_from('<i',target,off)[0])&0xffffffff)
        assert native_dst==dst,(r,hex(native_dst),hex(dst))
        assert struct.unpack_from('<I',code,off)[0]==0
        if typ=='DIR32':
            assert bytes.fromhex(symbol[len('__real@'):])[::-1]==target_bytes(image,dst,8)
    print(f'Kano state260: 821 original code bytes / 220 original instructions; {internal} native internal jumps, {outbound} shared-return jumps')
    print('9 original-bound COFF / IEEE-754 operands verified, all instruction offsets/widths/register-abstracted opcode shapes match.')
    print('NOT Exact: concrete-register bytes and case250 compiler phase remain unverified; strict contiguous prefix 40,336 original bytes.')

if __name__=='__main__':main()
