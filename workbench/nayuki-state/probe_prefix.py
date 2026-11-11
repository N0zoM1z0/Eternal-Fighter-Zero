#!/usr/bin/env python3
"""Compile a targeted Nayuki Slot06 boss prefix with original selector IDs.

The unreviewed later branches are neutral marker bodies, never full Exact.
The additional authentic states 300..306 retain ESI/frame shape in VC7.1.
"""
from pathlib import Path
import argparse
import re
import struct
import subprocess
import sys

ROOT=Path(__file__).resolve().parents[2]
sys.path.insert(0,str(ROOT/"scripts"))
from common import verify_target,target_bytes
from native_build import compile_source
from coff import object_function

BASE=0x00451850
CODE_SIZE=62693
SOURCE=ROOT/"workbench/nayuki-state/Character10State.cpp"
PROBE=ROOT/"workbench/nayuki-state/__prefix_probe.cpp"
OBJECT=ROOT/"build/nayuki-state/NayukiPrefix.probe.obj"

def disasm(buf):
    out=subprocess.run(["ndisasm","-b32","-o0","-"],input=buf,
                       check=True,capture_output=True).stdout.decode()
    return [(int(a,16),bytes.fromhex(h),op)
            for a,h,op in re.findall(
                r"^([0-9A-F]+)\s+([0-9A-F]+)\s+(.+)$",out,re.M)]

def normalized(op):
    if op.startswith("movzx eax,byte [edx+") and op.endswith("]"):
        return "movzx eax,byte [edx+SWITCH_INDEX]"
    if op.startswith("jmp [eax*4+"):
        return "jmp [eax*4+SWITCH_TARGET]"
    if re.match(r"^(?:j\w+|call)\b",op):
        return re.sub(r"^(\w+)\s+(?:(?:near|short)\s+)?0x[0-9a-f]+$",
                      r"\1 CANONICAL_BRANCH",op)
    return re.sub(r"\[dword 0x[0-9a-f]+\]","[dword FLOAT_LITERAL]",op)

def make_source(last_real):
    body=SOURCE.read_text()
    matches=list(re.finditer(r"^    case (0x[0-9a-fA-F]+|[0-9]+):",body,re.M))
    stop=body.rfind("\n    }\n}")
    # More original Nayuki states are added as their native bodies are recovered.
    # Do not freeze the old count of 116 copied sibling branches.
    assert 116<=len(matches)<=137 and stop>matches[-1].start()
    parts={int(m[1],0):body[m.start():matches[i+1].start() if i+1<len(matches) else stop]
           for i,m in enumerate(matches)}
    im=verify_target()
    sel=target_bytes(im,0x00460F5D,306)
    live=[i+1 for i,x in enumerate(sel) if x!=137]
    assert len(live)==137 and live[-1]==306
    original=set(live)
    assert set(parts).issubset(original)
    # The original switch bodies are not strictly sorted by numeric ID:
    # state300 at 0x45F293 precedes state279 at 0x45F4E9. Retain the
    # canonical physical address order when emitting real bodies and test
    # markers; numeric-order output falsely breaks the native prefix.
    destinations=target_bytes(im,0x00460D35,138*4)
    body_address={n:struct.unpack_from('<I',destinations,4*sel[n-1])[0]
                  for n in live}
    emission_order=sorted(live,key=lambda n:(body_address[n],n))
    # Include selected authentic early cases and selected complex late ones to
    # recover the real VC7.1 ESI register use, without compiling 150 KB every edit.
    force=set(range(300,307))
    used={x for x in live if (x<=last_real or x in force) and x in parts}
    output=body[:matches[0].start()]
    output+=''.join(parts[x] if x in used
                    else f"    case {x}:\n        field000a = (unsigned short)(field000a + {x});\n        return;\n\n"
                    for x in emission_order)
    output+="    }\n}\n"
    PROBE.write_text(output)
    return used

def main():
    parser=argparse.ArgumentParser()
    parser.add_argument("--through",type=int,default=9)
    parser.add_argument("--context",type=int,default=5)
    args=parser.parse_args()
    used=make_source(args.through)
    compile_source(PROBE,OBJECT,["/Od","/G6","/MT","/Gy","/W3"],
                   ROOT/".analysis/build/nayuki-state-prefix.log")
    candidate,reloc=object_function(OBJECT,"?Slot06@Character10@@UAEXXZ")
    original=target_bytes(verify_target(),BASE,CODE_SIZE)
    T,C=disasm(original),disasm(candidate)
    max_ok=0
    for i,(a,b) in enumerate(zip(T,C)):
        if i==2:
            continue
        if normalized(a[2])!=normalized(b[2]):
            print(f"FIRST at original 0x{BASE+a[0]:08X} (offset 0x{a[0]:X}) "
                  f"ordinal={i}; target {a[2]}, candidate {b[2]}")
            for j in range(max(i-args.context,0),min(i+args.context+1,len(T),len(C))):
                print(f"{j:5} {T[j][0]:05X} {T[j][2]:57s} | {C[j][0]:05X} {C[j][2]}")
            break
        max_ok=a[0]+len(a[1])
    else:
        print("NO normalized form disagreement in entire paired candidate")
    print("Authentic cases:",sorted(used))
    print(f"Reviewed candidate opcode forms until offset 0x{max_ok:X}; "
          f"target {len(original)} bytes, candidate {len(candidate)} bytes, "
          f"{len(reloc)} COFF relocations; candidate frame {C[2][2]}.")
if __name__=="__main__":
    try:
        main()
    finally:
        PROBE.unlink(missing_ok=True)
