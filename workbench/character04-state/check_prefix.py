#!/usr/bin/env python3
"""Canonical original-bound opening of Character04's 59kB Slot06 boss.

Only native default plus authored cases 1-9, 13-16, 47, 50-61 are reviewed.
The probe's 112 other live-case marker branches are not source and earn no credit.
This is a selected code prefix, NOT complete function Exact.
"""
from pathlib import Path
from collections import Counter
import hashlib,re,struct,sys
ROOT=Path(__file__).resolve().parents[2]
sys.path.insert(0,str(ROOT/'scripts'))
from common import verify_target,target_bytes
from probe_prefix import BASE,CODE_SIZE,TABLE_BASE,SELECTOR_BASE,run,disasm,normalized

END=0x00609CFC
NATIVE_CODE_SHA='200261f2d50fa04663e62d285dd09cd0eeaf601fdee46e08b2798e8cf95b02a1'
NATIVE_PREFIX_SHA='66d1c474b7798910b95479eacaea5599977129a5302dd38db24413ab08209352'
EXTERNAL_CALLS={
    '??0EffectSpawn@@QAE@XZ':0x00405490,
    '?ResetLocalEffectSpawn@Secondary@@QAEXPAUSecondaryEffectSpawn@@@Z':0x00413090,
    '?FaceOpponent@Secondary@@QAEHXZ':0x0040E630,
}
REAL_CASES={1:0x00607A4D,2:0x00607ABE,3:0x00607B2F,
            4:0x00607BA8,5:0x00607CD8,6:0x00607E14,
            7:0x00607F50,8:0x00607FD3,9:0x00608056,
            13:0x00608103,14:0x0060819E,15:0x006082BC,16:0x006083DA,47:0x006084F8,
            50:0x00608628,51:0x0060880F,52:0x006089F6,
            53:0x00608BDD,54:0x00608DC4,55:0x00608FAB,
            56:0x00609192,57:0x00609361,58:0x00609530,
            59:0x006096FF,60:0x006098FE,61:0x00609AFD}
BRANCH=re.compile(r'^j\w+\s+(?:(?:near|short)\s+)?0x([0-9a-f]+)$')

def main():
    image=verify_target()
    assert struct.unpack('<I',target_bytes(image,0x00788B94,4))[0]==BASE
    whole=target_bytes(image,BASE,CODE_SIZE)
    assert len(whole)==59143 and hashlib.sha256(whole).hexdigest()==NATIVE_CODE_SHA
    assert target_bytes(image,0x00616033,4)==bytes.fromhex('8be55dc3')
    orig=whole[:END-BASE]
    assert len(orig)==9164 and hashlib.sha256(orig).hexdigest()==NATIVE_PREFIX_SHA
    table=target_bytes(image,TABLE_BASE,556)
    selectors=target_bytes(image,SELECTOR_BASE,325)
    assert Counter(selectors)[138]==187 and sum(x!=138 for x in selectors)==138
    assert len(table)==139*4
    for case,addr in REAL_CASES.items():
        ordinal=selectors[case-1]
        assert ordinal!=138 and struct.unpack_from('<I',table,4*ordinal)[0]==addr
    assert [struct.unpack_from('<I',table,i*4)[0] for i in range(27)]==[
        REAL_CASES[i] for i in list(range(1,10))+[13,14,15,16,47]+list(range(50,62))]+[0x00609CFC]
    used,original,compiled,relocs=run(61)
    assert used==set(REAL_CASES)
    target_ins=disasm(orig)
    candidate_ins=disasm(compiled)
    assert len(target_ins)==2529 and len(candidate_ins)>len(target_ins)
    assert target_ins[2][2]=='sub esp,0x2e8'
    assert candidate_ins[2][2]=='sub esp,byte +0x7c'
    shift=3
    assert len(target_ins[2][1])-len(candidate_ins[2][1])==shift
    assert target_ins[-1][0]+len(target_ins[-1][1])==len(orig)
    assert candidate_ins[len(target_ins)][0]==len(orig)-shift
    original_offsets={x[0] for x in target_ins}
    candidate_offsets={x[0] for x in candidate_ins}
    ignore_candidate_bytes={}
    internal=outbound=0
    for i,(a,b) in enumerate(zip(target_ins,candidate_ins)):
        if i==2:continue  # only incomplete stack size is allowed
        assert a[0]==b[0]+(shift if i>2 else 0),(i,a,b)
        assert len(a[1])==len(b[1]),(i,a,b)
        assert normalized(a[2])==normalized(b[2]),(i,a,b)
        native_branch=BRANCH.fullmatch(a[2]);compiled_branch=BRANCH.fullmatch(b[2])
        if native_branch is None:continue
        assert compiled_branch,(i,a,b)
        dst=int(native_branch[1],16);got=int(compiled_branch[1],16)
        if dst<len(orig):
            assert dst in original_offsets and got in candidate_offsets
            assert dst==got+shift,(i,a,b)
            internal+=1
        else:
            assert BASE+dst==0x00616033,(i,a,hex(BASE+dst))
            assert got>=len(orig)-shift,(i,a,b)
            assert a[1][0]==b[1][0]==0xe9 and len(a[1])==5,(i,a,b)
            ignore_candidate_bytes.update({b[0]+k:'shared return displacement'
                                           for k in range(1,5)})
            outbound+=1
    assert (internal,outbound)==(233,28),(internal,outbound)
    relocations=[r for r in relocs if r['offset']<len(orig)-shift]
    local=[r for r in relocations if 'local_target_offset' in r]
    external=[r for r in relocations if 'local_target_offset' not in r]
    assert len(relocations)==269 and len(local)==2 and len(external)==267
    candidate_table=len(compiled)-556-325
    expected_locals={SELECTOR_BASE:candidate_table+556,TABLE_BASE:candidate_table}
    for r in relocations:
        off=r['offset'];pos=off+shift
        assert struct.unpack_from('<I',compiled,off)[0]==0,(r,hex(off))
        ignore_candidate_bytes.update({off+k:'COFF operand' for k in range(4)})
        native_raw=struct.unpack_from('<I',orig,pos)[0]
        if r in local:
            assert r['type']=='DIR32' and r['local_target_offset']==expected_locals[native_raw],r
            assert native_raw in (TABLE_BASE,SELECTOR_BASE),(r,hex(native_raw))
        elif r['type']=='DIR32':
            assert r['symbol'].startswith('__real@'),r
            payload=bytes.fromhex(r['symbol'][len('__real@'):])[::-1]
            assert target_bytes(image,native_raw,len(payload))==payload,(r,hex(native_raw))
        else:
            assert r['type']=='REL32' and r['symbol'] in EXTERNAL_CALLS,r
            native_dst=(BASE+pos+4+struct.unpack_from('<i',orig,pos)[0])&0xffffffff
            assert native_dst==EXTERNAL_CALLS[r['symbol']],(r,hex(native_dst))
    raw=[]
    for i,(a,b) in enumerate(zip(target_ins,candidate_ins)):
        if i==2:continue
        for k in range(len(a[1])):
            if b[0]+k in ignore_candidate_bytes:continue
            if orig[a[0]+k]!=compiled[b[0]+k]:
                raw.append((hex(BASE+a[0]+k),a[2],b[2]))
    assert not raw,raw[:15]
    print('Character04 Slot06 selected original-bound prefix PASS (NOT full Exact):')
    print('  native original 59,143-byte boss; 138 live IDs + 187 defaults; reviewed real states 1-9, 13-16, 47, 50-61 + default')
    print(f'  {len(orig)} original code bytes, {len(target_ins)} x86 instructions, {internal} native internal + {outbound} shared-return branches')
    print(f'  {len(external)} original-bound calls / IEEE-754 operands + {len(local)} native-local selector/table pointers')
    print('  Every remaining code byte exact after ONLY 3-byte provisional stack shrink, outbound-return displacement and COFF sites.')
    print('  Still OPEN: remaining 112 real cases, original 0x2E8 stack and full original table/shared return; NOT Exact.')
if __name__=='__main__':main()
