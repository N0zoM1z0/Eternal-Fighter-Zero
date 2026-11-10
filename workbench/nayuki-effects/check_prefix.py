"""Nayuki Character10 Slot07 selected original-bound partial native audit.

Checks the natural C++ opening only. Neither the local switch-table layout,
incomplete stack frame, nor the remaining effects code is fully Exact.
"""
from bisect import bisect_right
from collections import defaultdict
from pathlib import Path
import hashlib
import re
import struct
import subprocess
import sys

ROOT = Path(__file__).resolve().parents[2]
sys.path.insert(0, str(ROOT / "scripts"))
from common import verify_target, target_bytes
from native_build import compile_source
from coff import object_function

BASE, FULL_SIZE, END = 0x00468870, 20517, 0x0046AE61
FULL_SHA = "cbb77f4167efda7923dad4f9dc596fccba3a501d04451336368193ba1a1896f9"
PREFIX_SHA = "59483bc2b67477d8e72df5bf12919dd29850a02fa7db5791a66caa050b584164"
SOURCE = ROOT / "workbench/nayuki-effects/Character10Effects.cpp"
OBJECT = ROOT / "build/nayuki-effects/Character10Effects.partial.obj"
CALLEES = {
    "??0EffectSpawn@@QAE@XZ": 0x00405490,
    "?ResetLocalEffectSpawn@Secondary@@QAEXPAUSecondaryEffectSpawn@@@Z": 0x00413090,
    "__ftol2": 0x007783B8,
    "?SetVerticalShake@Secondary@@QAEXHH@Z": 0x00410A10,
    "?RandomRange@Secondary@@QAEFFF@Z": 0x004108A0,
    "?EmitEffect@Context@@QAEXPAUEffectSpawn@@@Z": 0x00407100,
}


def decode(raw):
    text = subprocess.run(
        ["ndisasm", "-b32", "-o0", "-"], input=raw,
        stdout=subprocess.PIPE, stderr=subprocess.PIPE, check=True,
    ).stdout.decode()
    return [
        (int(addr,16), bytes.fromhex(binary), asm)
        for addr,binary,asm in re.findall(
            r"^([0-9A-F]+)\s+([0-9A-F]+)\s+(.+)$",text,re.M)
    ]


def normalized(asm):
    if asm.startswith("movzx ecx,byte [eax+") and asm.endswith("]"):
        return "movzx ecx,byte [eax+ORIGINAL_SWITCH_TABLE]"
    if asm.startswith("jmp [ecx*4+"):
        return "jmp [ecx*4+ORIGINAL_SWITCH_TABLE]"
    if re.match(r"^(?:j\w+|call)\b",asm):
        return re.sub(
            r"^(\w+)\s+(?:(?:short|near)\s+)?0x[0-9a-f]+$",
            r"\1 ORIGINAL_DIRECT_TARGET",asm)
    return re.sub(r"\[dword 0x[0-9a-f]+\]","[dword FLOAT_LITERAL]",asm)


def main():
    im=verify_target()
    assert struct.unpack("<I",target_bytes(im,0x0078828C,4))[0]==BASE
    full=target_bytes(im,BASE,FULL_SIZE)
    assert hashlib.sha256(full).hexdigest()==FULL_SHA
    assert full[-5:]==bytes.fromhex("5e 5b 8b e5 5d c3")[-5:]
    assert target_bytes(im,BASE+FULL_SIZE,4)==bytes.fromhex("d2 89 46 00")
    original=full[:END-BASE]
    assert len(original)==9713
    assert hashlib.sha256(original).hexdigest()==PREFIX_SHA

    # The original jump table is adjacent to (not part of) the full function:
    # 100 compact case IDs, a 28-entry destination table, 27 active types.
    index=target_bytes(im,0x0046D905,100)
    destinations=target_bytes(im,0x0046D895,28*4)
    for j,relative in enumerate([0x162,0x3A2,0x9F6,0xFCB,0x1663,0x180F,0x18E5,0x1BDB,0x1F81,0x23DA]):
        assert index[j]==j
        assert struct.unpack_from("<I",destinations,4*j)[0]==BASE+relative

    compile_source(
        SOURCE,OBJECT,["/Od","/G6","/MT","/Gy","/W3"],
        ROOT/".analysis/build/nayuki-effects-selected-prefix.log")
    code,relocs=object_function(OBJECT,"?Slot07@Character10@@UAEXXZ")
    ref,got=decode(original),decode(code)
    assert len(ref)==2187 and len(got)>=len(ref)
    assert ref[2][2]=="sub esp,0x1d4"
    assert got[2][2]=="sub esp,0x380"
    assert got[len(ref)][0]==len(original)
    for i,(a,b) in enumerate(zip(ref,got)):
        assert a[0]==b[0],(i,a,b)
        assert len(a[1])==len(b[1]),(i,a,b)
        if i!=2:
            assert normalized(a[2])==normalized(b[2]),(i,a,b)

    ref_pos={a[0]:i for i,a in enumerate(ref)}
    got_pos={a[0]:i for i,a in enumerate(got)}
    full_pos={a[0] for a in decode(full)}
    inside=outside=0
    for a,b in zip(ref,got):
        m=re.search(r"^j\w+\s+(?:(?:short|near)\s+)?0x([0-9a-f]+)$",a[2])
        if not m:
            continue
        n=re.search(r"^j\w+\s+(?:(?:short|near)\s+)?0x([0-9a-f]+)$",b[2])
        assert n is not None,(a,b)
        target,compiled=int(m[1],16),int(n[1],16)
        assert target in full_pos,a
        if target in ref_pos:
            inside+=1
            assert ref_pos[target]==got_pos.get(compiled),(a,b)
        else:
            outside+=1
    assert (inside,outside)==(120,17),(inside,outside)

    # Two DIR32 relocations encode the compiler-generated jump dispatch
    # tables. They are NOT accepted as exact; original mappings are reviewed
    # above. All other fields are individually bound to the original.
    local={}
    distinct=defaultdict(set)
    starts=[a[0] for a in got]
    reviewed_relocations=0
    for rel in relocs:
        if rel["offset"]>=len(original):
            continue
        off=rel["offset"]
        ordinal=bisect_right(starts,off)-1
        assert ordinal>=0
        original_off=ref[ordinal][0]+off-got[ordinal][0]
        assert original_off+4<=ref[ordinal][0]+len(ref[ordinal][1])
        raw=struct.unpack_from("<I",original,original_off)[0]
        typ,name=rel["type"],rel["symbol"]
        addr=raw if typ=="DIR32" else (
            BASE+original_off+4+
            struct.unpack_from("<i",original,original_off)[0])&0xffffffff
        if name.startswith("$L"):
            assert typ=="DIR32"
            local[original_off]=addr
            continue
        if name.startswith("__real@"):
            bits=bytes.fromhex(name[len("__real@"):])[::-1]
            assert typ=="DIR32"
            assert target_bytes(im,addr,len(bits))==bits,(rel,hex(addr))
        else:
            assert typ=="REL32" and CALLEES[name]==addr,(rel,hex(addr))
        reviewed_relocations+=1
        distinct[(name,typ)].add(addr)
    assert local=={0x157:0x0046D905,0x15E:0x0046D895},local
    assert reviewed_relocations==117
    assert len(distinct)==26
    print("Nayuki Slot07: 9,713 / 20,517 original bytes, 2,187 instructions.")
    print("2,186 matching instruction forms plus incomplete stack allocation;")
    print("120 original internal branches, 17 valid original outbound targets;")
    print("117 original-bound literal/call relocations; two local switch-table")
    print("relocations independently identified, not claimed Exact.")
    print("Remaining effects and 0x380 vs 0x1D4 frame NOT Exact.")


if __name__=="__main__":
    main()
