#!/usr/bin/env python3
"""Focused original-bound structural island for Kano state270, NOT Exact.

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

BEGIN=0x0064FD61
END=0x00650140
SHA256='4b6c89fa0b1f03b0679e5d93ac001b93484ca454472cc69d625d989ce80e08df'
REFS=[
 (54215,'DIR32','__real@3fe0000000000000',0x00787C50),
 (54233,'DIR32','__real@3fe0000000000000',0x00787C50),
 (54248,'DIR32','__real@3f847ae147ae147b',0x00787CF0),
 (54316,'DIR32','__real@407f400000000000',0x00787C30),
 (54342,'DIR32','__real@406f400000000000',0x00787C70),
 (54372,'REL32','__ftol2',0x007783B8),
 (54398,'REL32','__ftol2',0x007783B8),
 (54439,'REL32','?EmitEffect@Context@@QAEXPAUEffectSpawn@@@Z',0x00407100),
 (54497,'REL32','__ftol2',0x007783B8),
 (54535,'REL32','__ftol2',0x007783B8),
 (54647,'REL32','__ftol2',0x007783B8),
 (54685,'REL32','__ftol2',0x007783B8),
 (54764,'REL32','__ftol2',0x007783B8),
 (54802,'REL32','__ftol2',0x007783B8),
 (54881,'REL32','__ftol2',0x007783B8),
 (54919,'REL32','__ftol2',0x007783B8),
 (55156,'DIR32','__real@3fa1eb851eb851ec',0x00787DD8),
]
def main():
    image=verify_target();lo=BEGIN-BASE;hi=END-BASE
    target=target_bytes(image,BASE,hi)
    native=target[lo:hi]
    assert len(native)==991 and hashlib.sha256(native).hexdigest()==SHA256
    used=make_source(270)
    assert {250,251,254,255,256,257,258,259,260,261,262,263,264,265,266,267,268,269,270}.issubset(used)
    assert 252 not in used and 253 not in used
    try:
        compile_source(PROBE,OBJECT,['/Od','/G6','/MT','/Gy','/W3'],
                       ROOT/'.analysis/build/kano-state-case270-diagnostic.log')
        code,rels=object_function(OBJECT,'?Slot06@Character20@@UAEXXZ')
    finally:
        PROBE.unlink(missing_ok=True)
    assert len(code)>hi
    orig=[x for x in disasm(target) if lo<=x[0]<hi]
    cand=[x for x in disasm(code) if lo<=x[0]<hi]
    assert len(orig)==len(cand)==265,(len(orig),len(cand))
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
    assert (internal,outbound)==(14,2),(internal,outbound)
    selected=[r for r in rels if lo<=r['offset']<hi]
    assert len(selected)==len(REFS)==17
    for r,(off,typ,symbol,dst) in zip(selected,REFS):
        assert (r['offset'],r['type'],r['symbol'])==(off,typ,symbol),(r,off,typ,symbol)
        native_dst=(struct.unpack_from('<I',target,off)[0] if typ=='DIR32'
                    else (BASE+off+4+struct.unpack_from('<i',target,off)[0])&0xffffffff)
        assert native_dst==dst,(r,hex(native_dst),hex(dst))
        assert struct.unpack_from('<I',code,off)[0]==0
        if typ=='DIR32':
            assert bytes.fromhex(symbol[len('__real@'):])[::-1]==target_bytes(image,dst,8)
    print(f'Kano state270: 991 original code bytes / 265 original instructions; {internal} native internal jumps, {outbound} shared-return jumps')
    print('17 original-bound COFF / IEEE-754 operands verified, all instruction offsets/widths/register-abstracted opcode shapes match.')
    print('NOT Exact: concrete-register bytes and case250 compiler phase remain unverified; strict contiguous prefix 40,336 original bytes.')

if __name__=='__main__':main()
