#!/usr/bin/env python3
"""Original-bound diagnostic Kano 257: native shape, NOT Exact acceptance.

This is physically separate from the strict selected-prefix end 0x64C750;
case250's concrete-register mismatch has not been resolved. Only the
actual authored source body is checked, never synthetic case markers.
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

BEGIN=0x0064D556
END=0x0064D8D9
SHA='7f13ea29ee1f9c768e845bb8f412b7c6919bcc00bbe9e25cf3ed278e940d4013'
REFS=[
 (43962,'REL32','?ResetFrame@Secondary@@QAEXXZ',0x0040F1E0),
 (44013,'REL32','?ResetFrame@Secondary@@QAEXXZ',0x0040F1E0),
 (44175,'DIR32','__real@407f400000000000',0x00787C30),
 (44214,'REL32','?ResetFrame@Secondary@@QAEXXZ',0x0040F1E0),
 (44276,'REL32','__ftol2',0x007783B8),
 (44302,'REL32','__ftol2',0x007783B8),
 (44366,'REL32','__ftol2',0x007783B8),
 (44392,'REL32','__ftol2',0x007783B8),
 (44594,'REL32','__ftol2',0x007783B8),
 (44632,'REL32','__ftol2',0x007783B8),
]

def main():
    target=verify_target();lo=BEGIN-BASE;hi=END-BASE
    native_all=target_bytes(target,BASE,hi)
    island=native_all[lo:hi]
    assert len(island)==899 and hashlib.sha256(island).hexdigest()==SHA
    used=make_source(257)
    assert {250,251,254,255,256,257}.issubset(used)
    assert 252 not in used and 253 not in used
    try:
        compile_source(PROBE,OBJECT,['/Od','/G6','/MT','/Gy','/W3'],
                       ROOT/'.analysis/build/kano-state-case257-diagnostic.log')
        code,relocs=object_function(OBJECT,'?Slot06@Character20@@UAEXXZ')
    finally:
        PROBE.unlink(missing_ok=True)
    assert len(code)>hi
    orig=[x for x in disasm(native_all) if lo<=x[0]<hi]
    cand=[x for x in disasm(code) if lo<=x[0]<hi]
    assert len(orig)==len(cand)==241,(len(orig),len(cand))
    assert orig[0][0]==cand[0][0]==lo
    assert orig[-1][0]+len(orig[-1][1])==hi
    assert cand[-1][0]+len(cand[-1][1])==hi
    for i,(a,b) in enumerate(zip(orig,cand)):
        assert a[0]==b[0] and len(a[1])==len(b[1]),(i,a,b)
        assert norm(a[2])==norm(b[2]),(i,a,b)
    orig_offsets={x[0] for x in orig};cand_offsets={x[0] for x in cand}
    internal=outbound=0
    for a,b in zip(orig,cand):
        x=BRANCH.fullmatch(a[2]);y=BRANCH.fullmatch(b[2])
        if not x:continue
        assert y,(a,b)
        addr=int(x[1],16);dest=int(y[1],16)
        if lo<=addr<hi:
            assert addr==dest and addr in orig_offsets and dest in cand_offsets,(a,b)
            internal+=1
        else:
            assert BASE+addr==0x006536B1,(a,hex(BASE+addr))
            outbound+=1
    assert (internal,outbound)==(22,3),(internal,outbound)
    local=[r for r in relocs if lo<=r['offset']<hi]
    assert len(local)==len(REFS)==10
    for r,(off,typ,name,dst) in zip(local,REFS):
        assert (r['offset'],r['type'],r['symbol'])==(off,typ,name),r
        original_addr=(struct.unpack_from('<I',native_all,off)[0] if typ=='DIR32'
                       else (BASE+off+4+struct.unpack_from('<i',native_all,off)[0])&0xffffffff)
        assert original_addr==dst,(r,hex(original_addr),hex(dst))
        assert struct.unpack_from('<I',code,off)[0]==0
        if typ=='DIR32':
            assert bytes.fromhex(name[len('__real@'):])[::-1]==target_bytes(target,dst,8)
    print(f'Kano case257: 899 native bytes / 241 original instructions; {internal} internal branches, {outbound} original return branches')
    print('10 original-bound COFF/IEEE-754 operands and all instruction positions, widths, register-abstracted forms match.')
    print('NOT EXACT: concrete x86 registers differ; selected contiguous prefix remains 40,336 bytes ending before case250.')

if __name__=='__main__':main()
