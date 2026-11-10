"""Selected original-bound Nayuki Character10::Slot06 partial native audit.

Builds a small reproducible C++ workbench containing the exact reviewed opening
and the authentic 137-ID selector shape. Marker branches are unreviewed and
must never count as full Exact or be installed in the accepted src/ directory.
"""
from collections import defaultdict, Counter
from pathlib import Path
import hashlib
import re
import struct
import sys

ROOT=Path(__file__).resolve().parents[2]
sys.path.insert(0,str(ROOT/"scripts"))
sys.path.insert(0,str(Path(__file__).resolve().parent))

from common import verify_target,target_bytes
from native_build import compile_source
from coff import object_function
from probe_prefix import BASE,CODE_SIZE,PROBE,OBJECT,make_source,disasm,normalized

END=BASE+0x18F7
PREFIX_SHA="d392f15f0e2611a4adffa4424266d4d2b62c8da99d51bea691840c03a47d848f"
FULL_SHA="4f34b8ffc35b76fec25b63082e0333e1b0ed3c82a76ddf5157df66db3ba949d9"
KNOWN_CALLS={
    "??0EffectSpawn@@QAE@XZ":0x00405490,
    "?ResetLocalEffectSpawn@Secondary@@QAEXPAUSecondaryEffectSpawn@@@Z":0x00413090,
    "?FaceOpponent@Secondary@@QAEHXZ":0x0040E630,
}
REVIEWED_IDS=[1,2,3,4,5,6,7,8,9,13,14,15,16,47,50,51,52,53,54,55]
REVIEWED_OFFSETS=[0x11e,0x1a8,0x232,0x2ab,0x400,0x561,
                  0x69d,0x720,0x7a3,0x850,0x8eb,0xa15,0xb3f,0xc5d,0xd8d,0xf74,0x115b,0x1342,0x1529,0x1710]

def main():
    image=verify_target()
    assert struct.unpack("<I",target_bytes(image,0x00788288,4))[0]==BASE
    original=target_bytes(image,BASE,CODE_SIZE)
    assert hashlib.sha256(original).hexdigest()==FULL_SHA
    prefix=original[:END-BASE]
    assert len(prefix)==6391 and hashlib.sha256(prefix).hexdigest()==PREFIX_SHA
    # Data owner beyond the 62,693 code bytes: 138 addresses, 306 selectors.
    labels=target_bytes(image,0x00460D35,138*4)
    indices=target_bytes(image,0x00460F5D,306)
    assert len(labels)==552 and len(indices)==306
    assert Counter(indices)[137]==169
    for identifier,offset in zip(REVIEWED_IDS,REVIEWED_OFFSETS):
        ordinal=indices[identifier-1]
        assert ordinal!=137
        assert struct.unpack_from("<I",labels,ordinal*4)[0]==BASE+offset
    assert sum(n!=137 for n in indices)==137
    # The original source has only 116 of the 137 active cases implemented
    # in this workbench; the experimental placeholder cases are NOT accepted.
    used=make_source(55)
    assert set(REVIEWED_IDS).issubset(used)
    try:
        compile_source(PROBE,OBJECT,["/Od","/G6","/MT","/Gy","/W3"],
                       ROOT/".analysis/build/nayuki-state-selected-prefix.log")
        code,relocs=object_function(OBJECT,"?Slot06@Character10@@UAEXXZ")
    finally:
        PROBE.unlink(missing_ok=True)
    target,compiled=disasm(prefix),disasm(code)
    assert len(target)==1765 and len(compiled)>len(target)
    assert target[2][2]=="sub esp,0x2b4"
    assert compiled[2][2].startswith("sub esp,") and compiled[2][2]!="sub esp,0x2b4"
    assert compiled[len(target)][0]==len(prefix)
    for i,(a,b) in enumerate(zip(target,compiled)):
        assert a[0]==b[0],(i,a,b)
        assert len(a[1])==len(b[1]),(i,a,b)
        if i!=2:
            assert normalized(a[2])==normalized(b[2]),(i,a,b)

    original_pos={v[0]:i for i,v in enumerate(target)}
    compiled_pos={v[0]:i for i,v in enumerate(compiled)}
    fullpos={v[0] for v in disasm(original)}
    internal=outbound=0
    for a,b in zip(target,compiled):
        left=re.search(r"^j\w+\s+(?:(?:short|near)\s+)?0x([0-9a-f]+)$",a[2])
        if not left:continue
        right=re.search(r"^j\w+\s+(?:(?:short|near)\s+)?0x([0-9a-f]+)$",b[2])
        assert right is not None,(a,b)
        dst,local=int(left[1],16),int(right[1],16)
        assert dst in fullpos,(a,dst)
        if dst in original_pos:
            internal+=1
            assert original_pos[dst]==compiled_pos.get(local),(a,b)
        else:
            outbound+=1
    assert (internal,outbound)==(156,22),(internal,outbound)

    refs=defaultdict(set)
    locals={}
    n=0
    for row in relocs:
        off=row["offset"]
        if off>=len(prefix):continue
        assert off+4<=len(prefix)
        raw=struct.unpack_from("<I",prefix,off)[0]
        dst=raw if row["type"]=="DIR32" else (
            BASE+off+4+struct.unpack_from("<i",prefix,off)[0])&0xffffffff
        name=row["symbol"]
        n+=1
        if name.startswith("$L"):
            assert row["type"]=="DIR32"
            locals[off]=dst
            continue
        if name.startswith("__real@"):
            assert row["type"]=="DIR32"
            value=bytes.fromhex(name[len("__real@"):])[::-1]
            assert value==target_bytes(image,dst,len(value)),(row,hex(dst))
        else:
            assert row["type"]=="REL32"
            assert KNOWN_CALLS[name]==dst,(row,hex(dst))
        refs[(name,row["type"])].add(dst)
    assert locals=={0xA2:0x00460F5D,0xA9:0x00460D35},locals
    assert n==186
    assert len(refs)==28 and all(len(v)==1 for v in refs.values()),len(refs)
    print("Nayuki Slot06: selected 6,391 / 62,693 original code bytes;")
    print("1,765 original same-width/offset x86 instructions (only incomplete frame differs).")
    print("156 verified in-prefix original branches, 22 valid original outbound targets;")
    print("184 exact original-bound external/float relocations, 2 local switch references.")
    print("Original dispatch: 137 live + 169 default IDs; 20 original case targets reviewed.")
    print("NOT full Exact: 56,302 code bytes, real 0x2B4 frame, 21 missing states,")
    print("full switch layout, shared return and remaining relocation closure OPEN.")

if __name__=="__main__":
    main()
