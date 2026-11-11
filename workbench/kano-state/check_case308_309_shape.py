#!/usr/bin/env python3
"""Strict original-bound structural audit for two real Kano state cases.

Unlike a full Exact certificate, this registers neither function nor
prefix progress: original case250 still changes concrete register allocation.
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
 (308,0x00652002,0x00652361,'1063e9b09a6b85285a106a63b7a0921d17a1fab6cb7d02469f912b3903c5bc03',218,[
  (63078,'?ResetFrame@Secondary@@QAEXXZ',0x0040F1E0),
  (63113,'?SetSceneTimer@Context@@QAEXH@Z',0x004080C0),
  (63196,'?SetTint@Secondary@@QAEXEH@Z',0x00410B10),
  (63217,'__ftol2',0x007783B8),
  (63243,'__ftol2',0x007783B8),
  (63291,'?EmitEffect@Context@@QAEXPAUEffectSpawn@@@Z',0x00407100),
  (63311,'?ResetFrame@Secondary@@QAEXXZ',0x0040F1E0),
  (63362,'?ResetFrame@Secondary@@QAEXXZ',0x0040F1E0),
  (63570,'__ftol2',0x007783B8),
  (63608,'__ftol2',0x007783B8),
 ]),
 (309,0x00652361,0x006526DF,'b49fa77e314487a9b516154fabcda63580b31c4dd0798f16f0d1e29f8488acd2',236,[
  (63941,'?ResetFrame@Secondary@@QAEXXZ',0x0040F1E0),
  (64034,'?SetTint@Secondary@@QAEXEH@Z',0x00410B10),
  (64055,'__ftol2',0x007783B8),
  (64093,'__ftol2',0x007783B8),
  (64141,'?EmitEffect@Context@@QAEXPAUEffectSpawn@@@Z',0x00407100),
  (64149,'?ResetFrame@Secondary@@QAEXXZ',0x0040F1E0),
  (64190,'?ResetFrame@Secondary@@QAEXXZ',0x0040F1E0),
  (64361,'__ftol2',0x007783B8),
  (64387,'__ftol2',0x007783B8),
  (64451,'__ftol2',0x007783B8),
  (64477,'__ftol2',0x007783B8),
  (64564,'__ftol2',0x007783B8),
  (64590,'__ftol2',0x007783B8),
 ]),
]

def main():
    image=verify_target()
    end=CASES[-1][2]-BASE
    native=target_bytes(image,BASE,end)
    used=make_source(312)
    assert {308,309,312}.issubset(used)
    assert 310 not in used and 311 not in used
    try:
        compile_source(PROBE,OBJECT,['/Od','/G6','/MT','/Gy','/W3'],
                       ROOT/'.analysis/build/kano-state-308-309-diagnostic.log')
        compiled,relocs=object_function(OBJECT,'?Slot06@Character20@@UAEXXZ')
    finally:
        PROBE.unlink(missing_ok=True)
    assert len(compiled)>end
    original_inst=disasm(native);candidate_inst=disasm(compiled)
    total_b=total_r=total_i=0
    for n,start,finish,sha,ninst,bindings in CASES:
        lo=start-BASE;hi=finish-BASE
        raw=native[lo:hi]
        assert hashlib.sha256(raw).hexdigest()==sha and len(raw)==finish-start
        orig=[x for x in original_inst if lo<=x[0]<hi]
        cand=[x for x in candidate_inst if lo<=x[0]<hi]
        assert len(orig)==len(cand)==ninst,(n,len(orig),len(cand))
        assert orig[0][0]==cand[0][0]==lo
        assert orig[-1][0]+len(orig[-1][1])==hi
        assert cand[-1][0]+len(cand[-1][1])==hi
        for i,(a,b) in enumerate(zip(orig,cand)):
            assert a[0]==b[0] and len(a[1])==len(b[1]) and norm(a[2])==norm(b[2]),(n,i,a,b)
        original_offsets={x[0] for x in orig};compiled_offsets={x[0] for x in cand}
        internal=outbound=0
        for a,b in zip(orig,cand):
            m=BRANCH.fullmatch(a[2]);c=BRANCH.fullmatch(b[2])
            if m is None:continue
            assert c,(n,a,b)
            destination=int(m[1],16);actual=int(c[1],16)
            if lo<=destination<hi:
                assert destination==actual and destination in original_offsets and actual in compiled_offsets,(n,a,b)
                internal+=1
            else:
                assert BASE+destination==0x006536B1,(n,a)
                outbound+=1
        selected=[r for r in relocs if lo<=r['offset']<hi]
        assert len(selected)==len(bindings),(n,len(selected),len(bindings))
        for r,(off,symbol,dest) in zip(selected,bindings):
            assert (r['offset'],r['type'],r['symbol'])==(off,'REL32',symbol),(n,r,off,symbol)
            original_dest=(BASE+off+4+struct.unpack_from('<i',native,off)[0])&0xffffffff
            assert original_dest==dest,(n,r,hex(original_dest),hex(dest))
            assert struct.unpack_from('<I',compiled,off)[0]==0
        print(f'Kano {n}: {finish-start} original bytes, {ninst} instruction positions, {internal} internal branches, {outbound} shared-return branches, {len(bindings)} original-bound REL32 calls')
        total_b+=internal;total_r+=outbound;total_i+=ninst
    print(f'TOTAL {total_i} original x86 instructions / {total_b} internal branches / {total_r} shared-return branches; NOT full Exact, prefix remains 40,336 bytes.')

if __name__=='__main__':main()
