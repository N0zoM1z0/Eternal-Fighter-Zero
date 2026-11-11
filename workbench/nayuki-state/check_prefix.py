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

END=BASE+0xCCD2
PREFIX_SHA="13dafd7fcfc2c3e076888ceca3f3cbe98704626de847d4a575f2d67e508ac110"
FULL_SHA="4f34b8ffc35b76fec25b63082e0333e1b0ed3c82a76ddf5157df66db3ba949d9"
KNOWN_CALLS={
    "??0EffectSpawn@@QAE@XZ":0x00405490,
    "?ResetLocalEffectSpawn@Secondary@@QAEXPAUSecondaryEffectSpawn@@@Z":0x00413090,
    "?FaceOpponent@Secondary@@QAEHXZ":0x0040E630,
    "?CollisionSide@Secondary@@QAEDXZ":0x0040FF70,
    "__ftol2":0x007783B8,
    "?EmitEffect@Context@@QAEXPAUEffectSpawn@@@Z":0x00407100,
    "?SetVerticalShake@Secondary@@QAEXHH@Z":0x00410A10,
    "?ResetFrame@Secondary@@QAEXXZ":0x0040F1E0,
    "?StartTrail@Secondary@@QAEXE@Z":0x004109D0,
    "?SetTint@Secondary@@QAEXEH@Z":0x00410B10,
    "?ApplyDamage@Secondary@@QAEXHN@Z":0x004105A0,
    "?SetHorizontalOffset@Secondary@@QAEXHH@Z":0x00410A40,
    "?SetHorizontalShake@Secondary@@QAEXHH@Z":0x00410A80,
    "?ClearBufferedButtons@Secondary@@QAEXXZ":0x0040F170,
}
REVIEWED_IDS=[1, 2, 3, 4, 5, 6, 7, 8, 9, 13, 14, 15, 16, 47, 50, 51, 52, 53, 54, 55, 56, 57, 58, 59, 60, 61, 62, 63, 64, 65, 66, 67, 68, 69, 70, 71, 72, 73, 74, 75, 76, 77, 81, 82, 83, 84, 85, 86, 87, 96, 97, 98, 99, 123, 150, 151, 152, 153, 154, 155, 156, 157, 158, 161, 162, 163, 164, 165, 166, 167, 168, 169, 170, 171, 178, 179, 180, 200, 201, 202, 203, 204, 205, 206, 207, 208, 209, 210, 211, 212, 213, 214, 220, 221, 230, 231, 232, 248, 249, 250, 251, 252, 253, 254, 256, 257, 258, 259, 260, 261, 262, 263, 264, 265, 266, 267, 268, 269, 270, 271, 272]
REVIEWED_OFFSETS=[286, 424, 562, 683, 1024, 1377, 1693, 1824, 1955, 2128, 2283, 2581, 2879, 3165, 3469, 3956, 4443, 4930, 5417, 5904, 6391, 6854, 7317, 7780, 8291, 8802, 9313, 9752, 10179, 10740, 11301, 11790, 12267, 12583, 12860, 13340, 13767, 14098, 14429, 14736, 15235, 15734, 16209, 16694, 17240, 17821, 18402, 18869, 19351, 19530, 19735, 19983, 20231, 20396, 20519, 20889, 21259, 21629, 21975, 22321, 22667, 22939, 23271, 23603, 23879, 24370, 24717, 25099, 25557, 26018, 26492, 26812, 27132, 27589, 28181, 28471, 28769, 29139, 29606, 30181, 31004, 31729, 32278, 32945, 33497, 33967, 34452, 34976, 35349, 35736, 36319, 36608, 36874, 37432, 37892, 38347, 38816, 39323, 39821, 40836, 41184, 41532, 42062, 42439, 42788, 43269, 43407, 43691, 43945, 44657, 45244, 46133, 46762, 47483, 48180, 48983, 49627, 50559, 51077, 51545, 51767]

def main():
    image=verify_target()
    assert struct.unpack("<I",target_bytes(image,0x00788288,4))[0]==BASE
    original=target_bytes(image,BASE,CODE_SIZE)
    assert hashlib.sha256(original).hexdigest()==FULL_SHA
    prefix=original[:END-BASE]
    assert len(prefix)==52434 and hashlib.sha256(prefix).hexdigest()==PREFIX_SHA
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
    # The workbench now authors 128 of 137 live case labels; others use diagnostic markers.
    # Only reviewed prefix cases are accepted. Later sibling-derived cases
    # and generated marker branches are explicitly UNVERIFIED.
    used=make_source(272)
    assert set(REVIEWED_IDS).issubset(used)
    try:
        compile_source(PROBE,OBJECT,["/Od","/G6","/MT","/Gy","/W3"],
                       ROOT/".analysis/build/nayuki-state-selected-prefix.log")
        code,relocs=object_function(OBJECT,"?Slot06@Character10@@UAEXXZ")
    finally:
        PROBE.unlink(missing_ok=True)
    target,compiled=disasm(prefix),disasm(code)
    assert len(target)==14384 and len(compiled)>len(target)
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
    assert (internal,outbound)==(1349,199),(internal,outbound)

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
    assert n==1104,n
    assert len(refs)==104 and all(len(v)==1 for v in refs.values()),len(refs)
    print("Nayuki Slot06: selected 52,434 / 62,693 original code bytes;")
    print("14,384 original same-width/offset x86 instructions (only incomplete frame differs).")
    print("1349 verified in-prefix original branches, 199 valid original outbound targets;")
    print("1102 exact original-bound external/float relocations, 2 local switch references.")
    print("Original dispatch: 137 live + 169 default IDs; 121 original case targets reviewed.")
    print("NOT full Exact: 10,259 code bytes, real 0x2B4 frame, 9 missing states,")
    print("full switch layout, shared return and remaining relocation closure OPEN.")

if __name__=="__main__":
    main()
