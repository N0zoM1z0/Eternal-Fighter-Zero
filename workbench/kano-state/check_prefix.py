#!/usr/bin/env python3
"""Kano boss: strict selected-prefix instruction and original reference audit.

This is not a complete-function Exact oracle. Provisional stack allocation,
case-marker data, distant targets and the remaining ~66KB are NOT accepted.
"""
from collections import Counter,defaultdict
from pathlib import Path
import hashlib,re,struct,sys
ROOT=Path(__file__).resolve().parents[2]
sys.path.insert(0,str(ROOT/'scripts'))
from common import verify_target,target_bytes
from native_build import compile_source
from coff import object_function
from probe_prefix import BASE,CODE_SIZE,PROBE,OBJECT,disasm,normalized,make_source

END=0x00643682 # first instruction of native case13, after nine full authored cases
NATIVE_CODE_SHA='c3ec6e125d3da52249b6111f22c5e719ae86a3d664b5d2d10a38898cd552f1ae'
CALLS={
'??0EffectSpawn@@QAE@XZ':0x00405490,
'?ResetLocalEffectSpawn@Secondary@@QAEXPAUSecondaryEffectSpawn@@@Z':0x00413090,
'?FaceOpponent@Secondary@@QAEHXZ':0x0040E630,
}

def main():
    image=verify_target()
    assert struct.unpack('<I',target_bytes(image,0x00788C90,4))[0]==BASE
    prefix=target_bytes(image,BASE,END-BASE)
    original=target_bytes(image,BASE,CODE_SIZE)
    assert len(prefix)==3266 and len(original)==68853
    assert hashlib.sha256(prefix).hexdigest()==NATIVE_CODE_SHA
    used=make_source(16)
    assert used==set(range(1,10))|{13,14,15,16},used
    try:
        compile_source(PROBE,OBJECT,['/Od','/G6','/MT','/Gy','/W3'],
                       ROOT/'.analysis/build/kano-state-selected-prefix.log')
        code,rels=object_function(OBJECT,'?Slot06@Character20@@UAEXXZ')
    finally:
        PROBE.unlink(missing_ok=True)
    target,compiled=disasm(prefix),disasm(code)
    assert len(compiled)>len(target)
    assert target[2][2]=='sub esp,0x4a4'
    assert compiled[2][2]=='sub esp,byte +0x58'
    assert target[2][0]==compiled[2][0]==3
    # The 6-byte native frame uses a 32-bit immediate. The unreviewed markers
    # reduce the compiler's provisional frame to a 3-byte 8-bit immediate.
    # Restore only that known 3-byte position offset for selected comparisons.
    for i,(a,b) in enumerate(zip(target,compiled)):
        assert a[0]==b[0]+(3 if i>=3 else 0),(i,a,b)
        if i==2:continue
        assert len(a[1])==len(b[1]),(i,a,b)
        assert normalized(a[2])==normalized(b[2]),(i,a,b)
    assert compiled[len(target)][0]+3==len(prefix)
    assert len(target)==927,len(target)

    original_pos={x[0]:i for i,x in enumerate(target)}
    compiled_pos={x[0]:i for i,x in enumerate(compiled)}
    whole_inst={x[0] for x in disasm(original)}
    internal=outbound=0
    for a,b in zip(target,compiled):
        m=re.search(r'^j\w+\s+(?:(?:short|near)\s+)?0x([0-9a-f]+)$',a[2])
        if not m:continue
        q=re.search(r'^j\w+\s+(?:(?:short|near)\s+)?0x([0-9a-f]+)$',b[2])
        assert q,(a,b)
        dst=int(m[1],16);local=int(q[1],16)
        assert dst in whole_inst,(a,hex(dst))
        if dst in original_pos:
            internal+=1
            assert original_pos[dst]==compiled_pos.get(local),(a,b)
        else:outbound+=1
    assert (internal,outbound)==(74,15),(internal,outbound)
    refs=defaultdict(set);local_refs={};n=0
    for r in rels:
        off=r['offset']
        # Compiler's first two dispatch relocations are located after the
        # 3-byte-shorter stack instruction; no padding/field masking.
        actual_off=off+3
        if actual_off>=len(prefix):continue
        assert actual_off+4<=len(prefix),(r,hex(actual_off))
        value=struct.unpack_from('<I',prefix,actual_off)[0]
        dest=(value if r['type']=='DIR32' else
              (BASE+actual_off+4+struct.unpack_from('<i',prefix,actual_off)[0])&0xffffffff)
        symbol=r['symbol'];n+=1
        if symbol.startswith('$L'):
            assert r['type']=='DIR32';local_refs[actual_off]=dest
        elif symbol.startswith('__real@'):
            assert r['type']=='DIR32'
            value=bytes.fromhex(symbol[len('__real@'):])[::-1]
            assert value==target_bytes(image,dest,len(value)),(r,hex(dest))
            refs[(symbol,r['type'])].add(dest)
        else:
            assert r['type']=='REL32' and symbol in CALLS,(r,hex(dest))
            assert CALLS[symbol]==dest,(r,hex(dest))
            refs[(symbol,r['type'])].add(dest)
    assert local_refs=={0xA1:0x006538D9,0xA8:0x006536B5},local_refs
    assert all(len(values)==1 for values in refs.values()),refs
    assert n==69 and len(local_refs)==2 and len(refs)==13,(n,len(local_refs),len(refs))
    print(f'Kano Slot06: {len(prefix)} / {CODE_SIZE} native code bytes; 13 real states + default, NO complete Exact.')
    print('native instructions',len(target),'internal branches',internal,'outbound targets',outbound)
    print('original-bound external/float operands',n-len(local_refs),'local switch address operands',len(local_refs),'distinct symbols',len(refs))
    print('native frame 0x4A4 vs incomplete candidate 0x58; full local data, return and other 123 state bodies OPEN.')

if __name__=='__main__':main()
