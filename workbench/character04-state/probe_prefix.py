#!/usr/bin/env python3
"""Compile only the authored Character04 boss opening; unreviewed states are markers.

Never use synthetic marker bodies to claim original matching or Exact.
"""
import argparse,re,struct,subprocess,sys
from pathlib import Path
ROOT=Path(__file__).resolve().parents[2]
sys.path.insert(0,str(ROOT/'scripts'))
from common import verify_target,target_bytes
from native_build import compile_source
from coff import object_function
BASE=0x00607930
CODE_SIZE=59143
TABLE_BASE=0x00616037
SELECTOR_BASE=0x00616263
SOURCE=ROOT/'workbench/character04-state/Character04State.cpp'
PROBE=ROOT/'workbench/character04-state/__case_probe.cpp'
OBJECT=ROOT/'build/character04-state/Character04Prefix.obj'
def disasm(buf):
    s=subprocess.run(['ndisasm','-b32','-o0','-'],input=buf,capture_output=True,check=True).stdout.decode()
    return [(int(a,16),bytes.fromhex(h),v) for a,h,v in re.findall(r'^([0-9A-F]+)\s+([0-9A-F]+)\s+(.+)$',s,re.M)]
def normalized(op):
    if op.startswith('jmp [eax*4+'):return 'jmp [eax*4+TABLE]'
    if re.match(r'^movzx eax,byte \[edx\+0x[0-9a-f]+\]$',op):return 'movzx eax,byte [edx+SELECTOR]'
    if re.match(r'^(?:j\w+|call)\b',op):
        return re.sub(r'^(\w+)\s+(?:(?:near|short)\s+)?0x[0-9a-f]+$',r'\1 TARGET',op)
    return re.sub(r'\[dword 0x[0-9a-f]+\]','[dword FLOAT]',op)
def make_source(through):
    image=verify_target()
    selector=target_bytes(image,SELECTOR_BASE,325)
    table=target_bytes(image,TABLE_BASE,139*4)
    live=[i+1 for i,x in enumerate(selector) if x!=138]
    assert len(live)==138 and selector.count(138)==187
    source=SOURCE.read_text()
    matches=list(re.finditer(r'^    case ([0-9]+):',source,re.M))
    end=source.rfind('\n    }\n}')
    cases={int(m[1]):source[m.start():matches[i+1].start() if i+1<len(matches) else end]
           for i,m in enumerate(matches)}
    assert set(cases).issubset(live)
    order=sorted(live,key=lambda n:struct.unpack_from('<I',table,selector[n-1]*4)[0])
    used={n for n in order if n<=through and n in cases}
    data=source[:matches[0].start()]
    data+=''.join(cases[n] if n in used else
                  f'    case {n}:\n        field000a = (unsigned short)(field000a + {n});\n        return;\n\n'
                  for n in order)
    data+='    }\n}\n'
    PROBE.write_text(data)
    return used

def run(through):
    used=make_source(through)
    try:
        compile_source(PROBE,OBJECT,['/Od','/G6','/MT','/Gy','/W3'],
                       ROOT/'.analysis/build/character04-state-probe.log')
        code,relocs=object_function(OBJECT,'?Slot06@Character04@@UAEXXZ')
    finally:PROBE.unlink(missing_ok=True)
    original=target_bytes(verify_target(),BASE,CODE_SIZE)
    return used,original,code,relocs

def main():
    pa=argparse.ArgumentParser();pa.add_argument('--through',type=int,default=3);pa.add_argument('--context',type=int,default=8);a=pa.parse_args()
    used,original,code,relocs=run(a.through)
    ori=disasm(original);compiled=disasm(code)
    shift=len(ori[2][1])-len(compiled[2][1])
    print('original frame',ori[2][2],'candidate frame',compiled[2][2],'prologue size shift',shift)
    okay=0
    for i,(o,c) in enumerate(zip(ori,compiled)):
        if i==2:continue
        if o[0]!=c[0]+(shift if i>2 else 0) or len(o[1])!=len(c[1]) or normalized(o[2])!=normalized(c[2]):
            print('FIRST DIFFERENCE',hex(BASE+o[0]),'ordinal',i,'native',o,'candidate',c)
            for j in range(max(0,i-a.context),min(len(ori),len(compiled),i+a.context+1)):
                print(j,hex(ori[j][0]),ori[j][2], '|',hex(compiled[j][0]),compiled[j][2])
            break
        okay=o[0]+len(o[1])
    print('REAL_CASES',sorted(used),'VERIFIED_INSTRUCTION_SHAPE_PREFIX',okay,'NATIVE',len(original),'COMPILED',len(code),'RELOCS',len(relocs))
if __name__=='__main__':main()
