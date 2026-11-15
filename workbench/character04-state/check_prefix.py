#!/usr/bin/env python3
"""Canonical original-bound opening of Character04's 59kB Slot06 boss.

Only native default plus authored cases 1-9, 13-16, 47, 50-77,
81-87, 96-99, 150-158, 161-171, 180, 200-216, 220-221,
230-232, 240-241, 249-266 are reviewed. The probe's 22 other live-case marker branches are not source and earn no credit.
This is a selected code prefix, NOT complete function Exact.
"""
from pathlib import Path
from collections import Counter
import hashlib,re,struct,sys
ROOT=Path(__file__).resolve().parents[2]
sys.path.insert(0,str(ROOT/'scripts'))
from common import verify_target,target_bytes
from probe_prefix import BASE,CODE_SIZE,TABLE_BASE,SELECTOR_BASE,run,disasm,normalized

END=0x006134F0
NATIVE_CODE_SHA='200261f2d50fa04663e62d285dd09cd0eeaf601fdee46e08b2798e8cf95b02a1'
NATIVE_PREFIX_SHA='b7d2e182f6f1a2d2d6065b80fb1b4878f91eb40e4fd09bcd46fb5064df55973e'
EXTERNAL_CALLS={
    '??0EffectSpawn@@QAE@XZ':0x00405490,
    '?ResetLocalEffectSpawn@Secondary@@QAEXPAUSecondaryEffectSpawn@@@Z':0x00413090,
    '?FaceOpponent@Secondary@@QAEHXZ':0x0040E630,
    '?CollisionSide@Secondary@@QAEDXZ':0x0040FF70,
    '?EmitEffect@Context@@QAEXPAUEffectSpawn@@@Z':0x00407100,
    '__ftol2':0x007783B8,
    '?SetVerticalShake@Secondary@@QAEXHH@Z':0x00410A10,
    '?ResetFrame@Secondary@@QAEXXZ':0x0040F1E0,
    '?StartTrail@Secondary@@QAEXE@Z':0x004109D0,
    '?SetTint@Secondary@@QAEXEH@Z':0x00410B10,
    '?SetHorizontalOffset@Secondary@@QAEXHH@Z':0x00410A40,
    '?SetHorizontalShake@Secondary@@QAEXHH@Z':0x00410A80,
    '?ApplyDamage@Secondary@@QAEXHN@Z':0x004105A0,
}
REAL_CASES={1:0x00607A4D,2:0x00607ABE,3:0x00607B2F,
            4:0x00607BA8,5:0x00607CD8,6:0x00607E14,
            7:0x00607F50,8:0x00607FD3,9:0x00608056,
            13:0x00608103,14:0x0060819E,15:0x006082BC,16:0x006083DA,47:0x006084F8,
            50:0x00608628,51:0x0060880F,52:0x006089F6,
            53:0x00608BDD,54:0x00608DC4,55:0x00608FAB,
            56:0x00609192,57:0x00609361,58:0x00609530,
            59:0x006096FF,60:0x006098FE,61:0x00609AFD,
            62:0x00609CFC,63:0x00609EB3,64:0x0060A05E,65:0x0060A28F,
            66:0x0060A4C0,67:0x0060A6A9,68:0x0060A886,
            69:0x0060A9C2,70:0x0060AAD7,71:0x0060ACB7,
            72:0x0060AE62,73:0x0060AFAD,74:0x0060B0F8,
            75:0x0060B22B,76:0x0060B41E,77:0x0060B611,
            81:0x0060B7EC,82:0x0060B9D1,83:0x0060BBF3,
            84:0x0060BE38,85:0x0060C07D,86:0x0060C250,87:0x0060C432,
            96:0x0060C4E5,97:0x0060C57A,98:0x0060C672,99:0x0060C76A,
            150:0x0060C81F,151:0x0060C9C1,152:0x0060CB63,
            153:0x0060CD05,154:0x0060CE8F,155:0x0060D019,
            156:0x0060D1A3,157:0x0060D2B3,158:0x0060D3FF,
            161:0x0060D54B,162:0x0060D65F,163:0x0060D84A,
            164:0x0060D9F1,165:0x0060DB54,166:0x0060DD05,
            167:0x0060DEBA,168:0x0060E0A2,169:0x0060E1E2,
            170:0x0060E322,171:0x0060E4EB,180:0x0060E73D,
            200:0x0060E88E,201:0x0060EA07,202:0x0060EB96,203:0x0060ED46,
            204:0x0060EE5D,205:0x0060EFEE,206:0x0060F17F,
            207:0x0060F331,208:0x0060F508,209:0x0060F6F9,
            210:0x0060F8F1,211:0x0060FB12,212:0x0060FC9A,
            213:0x0060FE22,214:0x0061004F,215:0x0061027C,216:0x006104A9,
            220:0x006105D8,221:0x006107B4,
            230:0x00610A47,231:0x00610B78,232:0x00610CA9,240:0x00610DDA,241:0x00610FCC,249:0x0061129C,250:0x006113DC,251:0x00611590,252:0x00611767,253:0x00611A7D,254:0x00611B49,255:0x00611DB0,256:0x00612093,257:0x0061237E,258:0x00612569,259:0x00612757,260:0x0061294C,261:0x00612BEE,262:0x00612CDD,263:0x00612DFD,264:0x00612F90,265:0x00613123,266:0x006133B5}
BRANCH=re.compile(r'^j\w+\s+(?:(?:near|short)\s+)?0x([0-9a-f]+)$')

def main():
    image=verify_target()
    assert struct.unpack('<I',target_bytes(image,0x00788B94,4))[0]==BASE
    whole=target_bytes(image,BASE,CODE_SIZE)
    assert len(whole)==59143 and hashlib.sha256(whole).hexdigest()==NATIVE_CODE_SHA
    assert target_bytes(image,0x00616033,4)==bytes.fromhex('8be55dc3')
    orig=whole[:END-BASE]
    assert len(orig)==48064 and hashlib.sha256(orig).hexdigest()==NATIVE_PREFIX_SHA
    # The two state265 x87 resource costs are pinned raw absolute operands;
    # verify both instruction bytes and the original 500/250 constants.
    assert target_bytes(image,0x00787C30,8)==struct.pack('<d',500.0)
    assert target_bytes(image,0x00787C70,8)==struct.pack('<d',250.0)
    for va,raw in ((0x00613217,bytes.fromhex('dc25307c7800')),
                   (0x00613231,bytes.fromhex('dc25707c7800'))):
        assert orig[va-BASE:va-BASE+len(raw)]==raw,(hex(va),orig[va-BASE:va-BASE+len(raw)].hex())
    table=target_bytes(image,TABLE_BASE,556)
    selectors=target_bytes(image,SELECTOR_BASE,325)
    assert Counter(selectors)[138]==187 and sum(x!=138 for x in selectors)==138
    assert len(table)==139*4
    for case,addr in REAL_CASES.items():
        ordinal=selectors[case-1]
        assert ordinal!=138 and struct.unpack_from('<I',table,4*ordinal)[0]==addr
    assert [struct.unpack_from('<I',table,i*4)[0] for i in range(116)]==[
        REAL_CASES[i] for i in list(range(1,10))+[13,14,15,16,47]+list(range(50,78))+list(range(81,88))+list(range(96,100))+list(range(150,159))+list(range(161,172))+[180]+list(range(200,217))+[220,221,230,231,232,240,241,249,250,251,252,253,254,255,256,257,258,259,260,261,262,263,264,265,266]]
    used,original,compiled,relocs=run(266)
    assert used==set(REAL_CASES)
    target_ins=disasm(orig)
    candidate_ins=disasm(compiled)
    assert len(target_ins)==13140 and len(candidate_ins)>len(target_ins)
    assert target_ins[2][2]=='sub esp,0x2e8'
    assert candidate_ins[2][2]=='sub esp,0x1c8'
    shift=0  # full six-byte opcode form restored; only stack-imm operand differs
    assert len(target_ins[2][1])-len(candidate_ins[2][1])==shift
    assert target_ins[-1][0]+len(target_ins[-1][1])==len(orig)
    assert candidate_ins[len(target_ins)][0]==len(orig)-shift
    original_offsets={x[0] for x in target_ins}
    candidate_offsets={x[0] for x in candidate_ins}
    target_by_offset={x[0]:x for x in target_ins}
    candidate_by_offset={x[0]:x for x in candidate_ins}
    candidate_table=len(compiled)-556-325
    candidate_epilogue=candidate_table-4
    assert candidate_by_offset[candidate_epilogue][2]=='mov esp,ebp'
    assert candidate_by_offset[candidate_epilogue+2][2]=='pop ebp'
    assert candidate_by_offset[candidate_epilogue+3][2]=='ret'
    ignore_candidate_bytes={}
    stack_temp_displacements={
        0x00611FDD-BASE:(bytes.fromhex('44feffff'),bytes.fromhex('48feffff')),
        0x00611FE3-BASE:(bytes.fromhex('44feffff'),bytes.fromhex('48feffff')),
        0x006120C8-BASE:(bytes.fromhex('40feffff'),bytes.fromhex('44feffff')),
        0x006120CE-BASE:(bytes.fromhex('40feffff'),bytes.fromhex('44feffff')),
        0x006120E5-BASE:(bytes.fromhex('3cfeffff'),bytes.fromhex('40feffff')),
        0x006120EB-BASE:(bytes.fromhex('3cfeffff'),bytes.fromhex('40feffff')),
        0x006121DE-BASE:(bytes.fromhex('38feffff'),bytes.fromhex('3cfeffff')),
        0x006121E4-BASE:(bytes.fromhex('38feffff'),bytes.fromhex('3cfeffff')),
        0x006121F8-BASE:(bytes.fromhex('34feffff'),bytes.fromhex('38feffff')),
        0x006121FE-BASE:(bytes.fromhex('34feffff'),bytes.fromhex('38feffff')),
    }
    stack_temp_disp_offsets=set(stack_temp_displacements)
    stack_temp_instruction_offsets={off-2 for off in stack_temp_disp_offsets}
    for off,(native_disp,candidate_disp) in stack_temp_displacements.items():
        assert orig[off:off+4]==native_disp,(hex(BASE+off),orig[off:off+4])
        assert compiled[off:off+4]==candidate_disp,(hex(BASE+off),compiled[off:off+4])
    ignore_candidate_bytes.update({off:'provisional x87 scratch-slot displacement'
                                   for off in stack_temp_disp_offsets})
    internal=outbound=0
    for i,(a,b) in enumerate(zip(target_ins,candidate_ins)):
        if i==2:continue  # only incomplete stack size is allowed
        assert a[0]==b[0]+(shift if i>2 else 0),(i,a,b)
        assert len(a[1])==len(b[1]),(i,a,b)
        if a[0] in stack_temp_instruction_offsets:
            assert a[1][:2]==b[1][:2] and a[1][3:]==b[1][3:],(i,a,b)
            disp_off=a[0]+2
            assert a[1][2:6]==stack_temp_displacements[disp_off][0],(i,a,b)
            assert b[1][2:6]==stack_temp_displacements[disp_off][1],(i,a,b)
            continue
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
            assert a[1][0]==b[1][0]==0xe9 and len(a[1])==5,(i,a,b)
            if got < len(orig)-shift:
                # VC7.1 may route one return through the same native
                # shared-return jump instruction before the common epilogue.
                assert got in target_by_offset and got in candidate_by_offset,(i,a,b)
                native_trampoline=target_by_offset[got]
                candidate_trampoline=candidate_by_offset[got]
                native_target=BRANCH.fullmatch(native_trampoline[2])
                candidate_target=BRANCH.fullmatch(candidate_trampoline[2])
                assert native_target and candidate_target,(i,native_trampoline,candidate_trampoline)
                assert native_trampoline[1][0]==candidate_trampoline[1][0]==0xe9
                assert len(native_trampoline[1])==len(candidate_trampoline[1])==5
                assert BASE+int(native_target[1],16)==0x00616033
                assert int(candidate_target[1],16)==candidate_epilogue
            else:
                assert got==candidate_epilogue,(i,a,b,hex(candidate_epilogue))
            ignore_candidate_bytes.update({b[0]+k:'shared return displacement'
                                           for k in range(1,5)})
            outbound+=1
    assert (internal,outbound)==(1167,155),(internal,outbound)
    relocations=[r for r in relocs if r['offset']<len(orig)-shift]
    local=[r for r in relocations if 'local_target_offset' in r]
    external=[r for r in relocations if 'local_target_offset' not in r]
    assert len(relocations)==1001 and len(local)==2 and len(external)==999
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
    print('  native original 59,143-byte boss; 138 live IDs + 187 defaults; reviewed real states 1-9, 13-16, 47, 50-77, 81-87, 96-99, 150-158, 161-171, 180, 200-216, 220-221, 230-232, 240-241, 249-266 + default')
    print(f'  {len(orig)} original code bytes, {len(target_ins)} x86 instructions, {internal} native internal + {outbound} shared-return branches')
    print(f'  {len(external)} original-bound calls / IEEE-754 operands + {len(local)} native-local selector/table pointers')
    print('  Remaining explicit exceptions: provisional stack size, ten x87 scratch-slot displacement bytes, shared returns and native-bound COFF fields.')
    print('  Still OPEN: remaining 22 real cases, original 0x2E8 stack and full original table/shared return; NOT Exact.')
if __name__=='__main__':main()
