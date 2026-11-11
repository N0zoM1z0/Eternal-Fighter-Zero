#!/usr/bin/env python3
"""Full-size Kano Slot06 original-bound structural audit, NOT Exact.

All 136 native live cases are actual C++ source, not probe markers.
Check original 68,853 executable bytes and 864 table bytes end-to-end,
including stack, every x86 instruction position/form, direct-call/float
bindings, local relocations, original branch destinations and selectors.
Report concrete-register differences: NEVER accept or mask them as Exact.
"""
from collections import Counter
from pathlib import Path
import hashlib,re,struct,sys
ROOT=Path(__file__).resolve().parents[2]
sys.path.insert(0,str(ROOT/'scripts'))
from common import verify_target,target_bytes
from coff import object_function
from native_build import compile_source
from probe_prefix import BASE,CODE_SIZE,PROBE,OBJECT,SOURCE,disasm,make_source
from check_case251_shape import BRANCH,norm
from check_prefix import CALLS

TABLE_WORDS=137
TABLE_BYTES=TABLE_WORDS*4
SELECTOR_BYTES=316
ALL_BYTES=CODE_SIZE+TABLE_BYTES+SELECTOR_BYTES
NATIVE_CODE_SHA='5234c38fdcb848ec03ec79da67561630bb2787d1f40aff855e1aea0dbd41f0b1'
NATIVE_FRAME='sub esp,0x4a4'
NATIVE_MISMATCH_STATES={250:17,251:79,254:27}


def main():
    target=verify_target()
    assert struct.unpack('<I',target_bytes(target,0x00788C90,4))[0]==BASE
    original=target_bytes(target,BASE,ALL_BYTES)
    assert len(original)==69717 and hashlib.sha256(original[:CODE_SIZE]).hexdigest()==NATIVE_CODE_SHA
    table=original[CODE_SIZE:CODE_SIZE+TABLE_BYTES]
    selectors=original[CODE_SIZE+TABLE_BYTES:]
    live={n+1 for n,index in enumerate(selectors) if index!=136}
    assert len(live)==136 and len(selectors)==316 and selectors.count(136)==180
    source=SOURCE.read_text()
    authored={int(m.group(1),0) for m in re.finditer(r'^    case (0x[0-9A-Fa-f]+|\d+):',source,re.M)}
    assert authored==live,(sorted(live-authored),sorted(authored-live))
    used=make_source(316)
    assert used==live
    try:
        compile_source(PROBE,OBJECT,['/Od','/G6','/MT','/Gy','/W3'],
                       ROOT/'.analysis/build/kano-state-full-shape.log')
        compiled,relocs=object_function(OBJECT,'?Slot06@Character20@@UAEXXZ')
    finally:
        PROBE.unlink(missing_ok=True)
    assert len(compiled)==ALL_BYTES
    assert bytes(compiled[CODE_SIZE+TABLE_BYTES:])==selectors
    target_ins=disasm(original[:CODE_SIZE]);candidate_ins=disasm(compiled[:CODE_SIZE])
    assert len(target_ins)==len(candidate_ins)==18634
    assert target_ins[-1][0]+len(target_ins[-1][1])==CODE_SIZE
    assert candidate_ins[-1][0]+len(candidate_ins[-1][1])==CODE_SIZE
    assert target_ins[2][2]==candidate_ins[2][2]==NATIVE_FRAME
    table_offsets={struct.unpack_from('<I',table,4*index)[0]-BASE for index in range(TABLE_WORDS)}
    by_start={struct.unpack_from('<I',table,index*4)[0]-BASE:n for n in live for index in [selectors[n-1]]}
    starts=sorted(by_start)
    inst_mismatch=Counter()
    for i,(a,b) in enumerate(zip(target_ins,candidate_ins)):
        assert a[0]==b[0] and len(a[1])==len(b[1]),(i,a,b)
        assert norm(a[2])==norm(b[2]),(i,a,b)
    branch_count=0
    for a,b in zip(target_ins,candidate_ins):
        m=BRANCH.fullmatch(a[2]);q=BRANCH.fullmatch(b[2])
        if m is None:continue
        assert q,(a,b)
        native_dst=int(m[1],16);compiled_dst=int(q[1],16)
        assert native_dst==compiled_dst,(a,b)
        branch_count+=1
    assert branch_count==1810,branch_count
    assert len(relocs)==1410
    local=[r for r in relocs if 'local_target_offset' in r]
    external=[r for r in relocs if 'local_target_offset' not in r]
    assert len(local)==139 and len(external)==1271
    assert [r['offset'] for r in local[:2]]==[0xA1,0xA8]
    assert [r['offset'] for r in local[2:]]==list(range(CODE_SIZE,CODE_SIZE+TABLE_BYTES,4))
    assert all(r['type']=='DIR32' and r['symbol'].startswith('$L') for r in local)
    for r in local:
        off=r['offset'];dst=struct.unpack_from('<I',original,off)[0]
        assert dst==BASE+r['local_target_offset'],(r,hex(dst))
        assert struct.unpack_from('<I',compiled,off)[0]==0,(off,r)
    original_entry_offsets={struct.unpack_from('<I',table,i*4)[0]-BASE for i in range(137)}
    assert all(0<=x<CODE_SIZE for x in original_entry_offsets)
    assert table_offsets==original_entry_offsets
    callmap={**CALLS,'?SetSceneTimer@Context@@QAEXH@Z':0x004080C0}
    for r in external:
        off=r['offset'];assert off<CODE_SIZE
        assert struct.unpack_from('<I',compiled,off)[0]==0,(r,off)
        if r['type']=='DIR32':
            assert r['symbol'].startswith('__real@'),r
            dst=struct.unpack_from('<I',original,off)[0]
            payload=bytes.fromhex(r['symbol'][len('__real@'):])[::-1]
            assert payload==target_bytes(target,dst,len(payload)),(r,hex(dst))
        else:
            assert r['type']=='REL32' and r['symbol'] in callmap,r
            dst=(BASE+off+4+struct.unpack_from('<i',original,off)[0])&0xffffffff
            assert dst==callmap[r['symbol']],(r,hex(dst),hex(callmap[r['symbol']]))
    relocation_bytes={k for r in relocs if r['offset']<CODE_SIZE for k in range(r['offset'],r['offset']+4)}
    raw_diff=[off for off in range(CODE_SIZE) if off not in relocation_bytes and compiled[off]!=original[off]]
    assert len(raw_diff)==125,len(raw_diff)
    ranges={}
    for off in raw_diff:
        # 125 actual unmasked differences are in the three named cases.
        region=max((start for start in starts if start<=off),default=None)
        state=by_start.get(region,0)
        ranges[state]=ranges.get(state,0)+1
    assert set(ranges)=={250,251,254},ranges
    # The stricter native machine-register instruction-form comparison
    # also differs only in these cases, never counted as Exact.
    from probe_prefix import normalized
    case_instruction_diff=Counter()
    for a,b in zip(target_ins,candidate_ins):
        if normalized(a[2])!=normalized(b[2]):
            region=max((start for start in starts if start<=a[0]),default=None)
            case_instruction_diff[by_start.get(region,0)]+=1
    assert dict(case_instruction_diff)==NATIVE_MISMATCH_STATES,case_instruction_diff
    print('Kano Slot06 FULL-OWNER structural audit PASS (NOT Exact):')
    print(f'  {len(live)} original live cases; native 0x4A4 frame; {CODE_SIZE} code + {TABLE_BYTES} pointers + {SELECTOR_BYTES} selectors')
    print(f'  {len(target_ins)} original x86 instruction offsets/widths/abstracted forms; {branch_count} exact native relative jumps')
    print(f'  {len(external)} externally original-bound calls/floats, {len(local)} exact native-local pointers, 316 identical selector bytes')
    print(f'  Still OPEN: {len(raw_diff)} nonrelocation byte differences in cases 250/251/254, {sum(case_instruction_diff.values())} concrete-register instruction differences; full Exact NOT accepted')

if __name__=='__main__':main()
