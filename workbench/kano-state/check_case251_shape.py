#!/usr/bin/env python3
"""Original-bound *diagnostic* for unaccepted Kano case251, not Exact.

Original code and VC7.1 code have identical case offsets, instruction
lengths and register-abstracted forms. This deliberately DOES NOT
accept a function or change the strict contiguous-prefix checkpoint:
case250 has unresolved register assignment, and so does case251.
"""
from pathlib import Path
import re,struct,sys,hashlib
ROOT=Path(__file__).resolve().parents[2]
sys.path.insert(0,str(ROOT/'scripts'))
from common import verify_target,target_bytes
from native_build import compile_source
from coff import object_function
from probe_prefix import BASE,OBJECT,PROBE,disasm,normalized,make_source

ORIGINAL_BEGIN=0x0064C999
ORIGINAL_END=0x0064CB5F
# Only the actual case251 body; 0x0040F1E0 and 0x007783B8 are
# separately reviewed original callee entrypoints, not guesses.
EXPECTED_REFS=[
 (40957,'REL32','?ResetFrame@Secondary@@QAEXXZ',0x0040F1E0),
 (41091,'DIR32','__real@407f400000000000',0x00787C30),
 (41117,'DIR32','__real@406f400000000000',0x00787C70),
 (41156,'REL32','__ftol2',0x007783B8),
 (41182,'REL32','__ftol2',0x007783B8),
 (41249,'REL32','__ftol2',0x007783B8),
 (41275,'REL32','__ftol2',0x007783B8),
]
REGS=re.compile(r'\b(?:eax|ebx|ecx|edx|esi|edi|ax|bx|cx|dx|si|di|al|bl|cl|dl|ah|bh|ch|dh)\b')
BRANCH=re.compile(r'^j\w+\s+(?:(?:short|near)\s+)?0x([0-9a-f]+)$')

def norm(op):
    op=normalized(op)
    def register_kind(m):
        x=m.group()
        if len(x)==3 and x[1] in 'abcd' and x[-1] in 'hl':return 'reg8'
        if len(x)==2 and x[-1] in 'hl':return 'reg8'
        return 'reg16' if len(x)==2 else 'reg32'
    op=REGS.sub(register_kind,op)
    # ABI compiler emits either 66 83 C?/01 or 66 05 01 00 for
    # the same 16-bit +1, depending on scratch register selection.
    return op.replace('add reg16,0x1','add reg16,byte +0x1')

def main():
    image=verify_target();lo=ORIGINAL_BEGIN-BASE;hi=ORIGINAL_END-BASE
    target=target_bytes(image,BASE,hi)
    native=target[lo:hi]
    assert len(native)==454
    used=make_source(251)
    assert 250 in used and 251 in used
    try:
        compile_source(PROBE,OBJECT,['/Od','/G6','/MT','/Gy','/W3'],
                       ROOT/'.analysis/build/kano-state-case251-diagnostic.log')
        code,relocs=object_function(OBJECT,'?Slot06@Character20@@UAEXXZ')
    finally:
        PROBE.unlink(missing_ok=True)
    assert len(code)>hi
    orig_ins=[x for x in disasm(target) if lo<=x[0]<hi]
    cand_ins=[x for x in disasm(code) if lo<=x[0]<hi]
    assert len(orig_ins)==len(cand_ins)==117,(len(orig_ins),len(cand_ins))
    assert orig_ins[-1][0]+len(orig_ins[-1][1])==hi
    assert cand_ins[-1][0]+len(cand_ins[-1][1])==hi
    for i,(orig,cand) in enumerate(zip(orig_ins,cand_ins)):
        assert orig[0]==cand[0] and len(orig[1])==len(cand[1]),(i,orig,cand)
        assert norm(orig[2])==norm(cand[2]),(i,orig,cand)
    original_offsets={x[0] for x in orig_ins}
    compiled_offsets={x[0] for x in cand_ins}
    local_branches=0
    for orig,cand in zip(orig_ins,cand_ins):
        x=BRANCH.fullmatch(orig[2]);y=BRANCH.fullmatch(cand[2])
        if not x:continue
        assert y,(orig,cand)
        original_target=int(x[1],16)
        if lo<=original_target<hi:
            local_branches+=1
            assert original_target==int(y[1],16)
            assert original_target in original_offsets and int(y[1],16) in compiled_offsets
    cand_refs=[r for r in relocs if lo<=r['offset']<hi]
    assert len(cand_refs)==len(EXPECTED_REFS)==7
    for r,(offset,kind,symbol,dst) in zip(cand_refs,EXPECTED_REFS):
        assert (r['offset'],r['type'],r['symbol'])==(offset,kind,symbol),r
        found=(struct.unpack_from('<I',target,offset)[0] if kind=='DIR32'
               else (BASE+offset+4+struct.unpack_from('<i',target,offset)[0])&0xffffffff)
        assert found==dst,(r,hex(found),hex(dst))
        if kind=='DIR32':
            payload=bytes.fromhex(symbol[len('__real@'):])[::-1]
            assert payload==target_bytes(image,dst,len(payload))
    print(f'Kano case251: original {len(native)} code bytes / {len(orig_ins)} x86 instructions;')
    print(f'  all original offsets, lengths and register-abstracted forms checked; {local_branches} local branches;')
    print('  seven original-bound COFF operands (two IEEE-754 constants and five calls).')
    print('  NOT Exact: case250 register phase, case251 concrete registers and one 16-bit ADD encoding OPEN.')
    print('  Contiguous strict selected prefix remains at 0x0064C750 (40,336 bytes).')

if __name__=='__main__':main()
