#!/usr/bin/env python3
"""Selected Kano Slot06 original prefix, with unaccepted neutral marker cases."""
import argparse
import re
import struct
import subprocess
import sys
from pathlib import Path
ROOT=Path(__file__).resolve().parents[2]
sys.path.insert(0,str(ROOT/'scripts'))
from common import verify_target,target_bytes
from native_build import compile_source
from coff import object_function
BASE=0x006429C0
CODE_SIZE=68853
SOURCE=ROOT/'workbench/kano-state/Character20State.cpp'
PROBE=ROOT/'workbench/kano-state/__prefix_probe.cpp'
OBJECT=ROOT/'build/kano-state/KanoPrefix.obj'

def disasm(buf):
    z=subprocess.run(['ndisasm','-b32','-o0','-'],input=buf,check=True,capture_output=True).stdout.decode()
    return [(int(a,16),bytes.fromhex(h),op) for a,h,op in re.findall(r'^([0-9A-F]+)\s+([0-9A-F]+)\s+(.+)$',z,re.M)]

def normalized(op):
    if re.match(r'^movzx eax,byte \[edx\+0x[0-9a-f]+\]$',op):return 'movzx eax,byte [edx+SWITCH_INDEX]'
    if op.startswith('jmp [eax*4+'):return 'jmp [eax*4+SWITCH_TARGET]'
    if re.match(r'^(?:j\w+|call)\b',op):
        return re.sub(r'^(\w+)\s+(?:(?:near|short)\s+)?0x[0-9a-f]+$',r'\1 CANONICAL_BRANCH',op)
    return re.sub(r'\[dword 0x[0-9a-f]+\]','[dword FLOAT_LITERAL]',op)

def make_source(through):
    source=SOURCE.read_text()
    matches=list(re.finditer(r'^    case (0x[0-9a-fA-F]+|[0-9]+):',source,re.M))
    stop=source.rfind('\n    }\n}')
    assert len(matches)>=3 and stop>matches[-1].start()
    cases={int(m[1],0):source[m.start():matches[i+1].start() if i+1<len(matches) else stop]
           for i,m in enumerate(matches)}
    image=verify_target();selectors=target_bytes(image,0x006538D9,316)
    destinations=target_bytes(image,0x006536B5,137*4)
    live=[i+1 for i,s in enumerate(selectors) if s!=136]
    assert len(live)==136 and len([x for x in selectors if x==136])==180
    assert set(cases).issubset(live)
    order=sorted(live,key=lambda n:struct.unpack_from('<I',destinations,selectors[n-1]*4)[0])
    used={n for n in order if n<=through and n in cases}
    output=source[:matches[0].start()]
    output+=''.join(cases[n] if n in used else
                    f'    case {n}:\n        field000a = (unsigned short)(field000a + {n});\n        return;\n\n'
                    for n in order)
    output+='    }\n}\n';PROBE.write_text(output)
    return used

def main():
    parser=argparse.ArgumentParser();parser.add_argument('--through',type=int,default=3)
    parser.add_argument('--context',type=int,default=10);a=parser.parse_args()
    used=make_source(a.through)
    compile_source(PROBE,OBJECT,['/Od','/G6','/MT','/Gy','/W3'],
                   ROOT/'.analysis/build/kano-state-prefix.log')
    code,rels=object_function(OBJECT,'?Slot06@Character20@@UAEXXZ')
    original=target_bytes(verify_target(),BASE,CODE_SIZE)
    target,cand=disasm(original),disasm(code)
    max_ok=0
    # Before the final big state bodies exist the compiler chooses a
    # three-byte short stack allocation instead of the original six-byte
    # long allocation. Check exact instruction structure at original
    # offsets AFTER NORMALIZING ONLY THIS ONE KNOWN THREE-BYTE SHIFT.
    shifted=len(cand[2][1])==3 and len(target[2][1])==6
    shift=3 if shifted else 0
    for i,(x,y) in enumerate(zip(target,cand)):
        if i==2:continue # provisional stack size; no Exact claim
        adjust=0 if i<3 else shift
        if normalized(x[2])!=normalized(y[2]) or x[0]!=y[0]+adjust or len(x[1])!=len(y[1]):
            print(f'FIRST at 0x{BASE+x[0]:08X}, offset 0x{x[0]:X}, ordinal {i}')
            for j in range(max(0,i-a.context),min(len(target),len(cand),i+a.context+1)):
                print(f'{j:5} {target[j][0]:05X} {target[j][2]:52s} | {cand[j][0]:05X} {cand[j][2]}')
            break
        max_ok=x[0]+len(x[1])
    else:print('NO discrepancy in paired instructions')
    print('Reviewed real cases',sorted(used),'matching prefix',max_ok,
          'original total',len(original),'candidate',len(code),'relo',len(rels),
          'candidate frame',cand[2][2])
if __name__=='__main__':
    try:main()
    finally:PROBE.unlink(missing_ok=True)
