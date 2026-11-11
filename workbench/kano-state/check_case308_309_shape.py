#!/usr/bin/env python3
"""Native-anchored structural islands for original Kano 308/309, NOT Exact."""
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
 (308,0x00652002,0x00652361,218,
  '1063e9b09a6b85285a106a63b7a0921d17a1fab6cb7d02469f912b3903c5bc03',
  [63078,63113,63196,63217,63243,63291,63311,63362,63570,63608]),
 (309,0x00652361,0x006526DF,236,
  'b49fa77e314487a9b516154fabcda63580b31c4dd0798f16f0d1e29f8488acd2',
  [63941,64034,64055,64093,64141,64149,64190,64361,64387,64451,64477,64564,64590]),
]
REFS={
 308:[
  ('?ResetFrame@Secondary@@QAEXXZ',0x0040F1E0),
  ('?SetSceneTimer@Context@@QAEXH@Z',0x004080C0),
  ('?SetTint@Secondary@@QAEXEH@Z',0x00410B10),
  ('__ftol2',0x007783B8),('__ftol2',0x007783B8),
  ('?EmitEffect@Context@@QAEXPAUEffectSpawn@@@Z',0x00407100),
  ('?ResetFrame@Secondary@@QAEXXZ',0x0040F1E0),
  ('?ResetFrame@Secondary@@QAEXXZ',0x0040F1E0),
  ('__ftol2',0x007783B8),('__ftol2',0x007783B8),
 ],
 309:[
  ('?ResetFrame@Secondary@@QAEXXZ',0x0040F1E0),
  ('?SetTint@Secondary@@QAEXEH@Z',0x00410B10),
  ('__ftol2',0x007783B8),('__ftol2',0x007783B8),
  ('?EmitEffect@Context@@QAEXPAUEffectSpawn@@@Z',0x00407100),
  ('?ResetFrame@Secondary@@QAEXXZ',0x0040F1E0),
  ('?ResetFrame@Secondary@@QAEXXZ',0x0040F1E0),
  ('__ftol2',0x007783B8),('__ftol2',0x007783B8),
  ('__ftol2',0x007783B8),('__ftol2',0x007783B8),
  ('__ftol2',0x007783B8),('__ftol2',0x007783B8),
 ],
}

def main():
    image=verify_target();end=CASES[-1][2]-BASE
    original=target_bytes(image,BASE,end)
    used=make_source(312)
    assert {308,309,312}.issubset(used)
    try:
        compile_source(PROBE,OBJECT,['/Od','/G6','/MT','/Gy','/W3'],
                       ROOT/'.analysis/build/kano-state-case308-309-diagnostic.log')
        code,rels=object_function(OBJECT,'?Slot06@Character20@@UAEXXZ')
    finally:PROBE.unlink(missing_ok=True)
    assert len(code)>end
    native_is=disasm(original);cand_is=disasm(code)
    total_i=total_out=0
    for n,start,finish,count,sha,offsets in CASES:
        lo=start-BASE;hi=finish-BASE
        assert hashlib.sha256(original[lo:hi]).hexdigest()==sha
        left=[x for x in native_is if lo<=x[0]<hi]
        right=[x for x in cand_is if lo<=x[0]<hi]
        assert len(left)==len(right)==count,(n,len(left),len(right))
        assert left[0][0]==right[0][0]==lo
        assert left[-1][0]+len(left[-1][1])==hi
        assert right[-1][0]+len(right[-1][1])==hi
        for j,(a,b) in enumerate(zip(left,right)):
            assert a[0]==b[0] and len(a[1])==len(b[1]),(n,j,a,b)
            assert norm(a[2])==norm(b[2]),(n,j,a,b)
        addresses={x[0] for x in left};caddresses={x[0] for x in right}
        internal=outbound=0
        for a,b in zip(left,right):
            x=BRANCH.fullmatch(a[2]);y=BRANCH.fullmatch(b[2])
            if not x:continue
            assert y,(n,a,b)
            dst=int(x[1],16);v=int(y[1],16)
            if lo<=dst<hi:
                internal+=1
                assert dst==v and dst in addresses and v in caddresses,(n,a,b)
            else:
                outbound+=1
                # Original target must be the canonical shared return.
                # The partial probe has diagnostic marker cases afterward,
                # so its generated tail can end in a *local* epilogue.
                # Never call that compiled target exact or hide the gap.
                assert BASE+dst==0x006536B1,(n,a,b)
        local=[r for r in rels if lo<=r['offset']<hi]
        spec=REFS[n]
        assert len(local)==len(offsets)==len(spec),(n,len(local))
        for r,off,(symbol,target) in zip(local,offsets,spec):
            assert (r['offset'],r['type'],r['symbol'])==(off,'REL32',symbol),(n,r,off,symbol)
            dest=(BASE+off+4+struct.unpack_from('<i',original,off)[0])&0xffffffff
            assert dest==target,(n,r,hex(dest),hex(target))
            assert struct.unpack_from('<I',code,off)[0]==0
        total_i+=internal;total_out+=outbound
        print(f'Kano case{n}: {finish-start} native bytes / {count} x86 instructions; {internal} in-case and {outbound} shared-return jumps; {len(local)} original-bound calls.')
    print(f'TOTAL: 1757 original code bytes / 454 x86 instructions; {total_i} internal and {total_out} return branches; 23 original REL32 calls.')
    print('NOT EXACT; selected continuous prefix remains 40,336 bytes before case250.')

if __name__=='__main__':main()
