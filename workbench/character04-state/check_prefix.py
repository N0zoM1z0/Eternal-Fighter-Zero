#!/usr/bin/env python3
"""Canonical original-bound opening of Character04's 59kB Slot06 boss.

Only native default plus authored cases 1-9, 13-16, 47, 50-77,
81-87, 96-99, 150-158, 161-171, 180, 200-216, 220-221,
230-232, 240-241, 249-269,303-309,312,315-325 are reviewed. All 138 real live cases are source; no live-case marker branches remain.
This is a selected code prefix, NOT complete function Exact.
"""
from pathlib import Path
from collections import Counter
import hashlib,json,re,struct,sys
ROOT=Path(__file__).resolve().parents[2]
sys.path.insert(0,str(ROOT/'scripts'))
from common import verify_target,target_bytes
from probe_prefix import BASE,CODE_SIZE,TABLE_BASE,SELECTOR_BASE,run,disasm,normalized

END=0x00616033
NATIVE_CODE_SHA='200261f2d50fa04663e62d285dd09cd0eeaf601fdee46e08b2798e8cf95b02a1'
NATIVE_PREFIX_SHA='59784e3e7df3098d6ecc0874fc5bd88e9a0e4c97824438319e94e67ca2671011'
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
    '?SetSceneTimer@Context@@QAEXH@Z':0x004080C0,
    '?ApplyDamage@Secondary@@QAEXHN@Z':0x004105A0,
    '?SetCharacterTint@Secondary@@QAEXEH@Z':0x00410AC0,
}
LEAF_DEPENDENCIES={
    'effect-spawn-construct':('??0EffectSpawn@@QAE@XZ',0x00405490,30),
    'secondary-reset-local-effect-spawn':('?ResetLocalEffectSpawn@Secondary@@QAEXPAUSecondaryEffectSpawn@@@Z',0x00413090,106),
    'secondary-face-opponent':('?FaceOpponent@Secondary@@QAEHXZ',0x0040E630,130),
    'secondary-collision-side':('?CollisionSide@Secondary@@QAEDXZ',0x0040FF70,222),
    'context-emit-effect':('?EmitEffect@Context@@QAEXPAUEffectSpawn@@@Z',0x00407100,406),
    'secondary-set-vertical-shake':('?SetVerticalShake@Secondary@@QAEXHH@Z',0x00410A10,43),
    'secondary-reset-frame':('?ResetFrame@Secondary@@QAEXXZ',0x0040F1E0,74),
    'secondary-start-trail':('?StartTrail@Secondary@@QAEXE@Z',0x004109D0,61),
    'secondary-set-tint':('?SetTint@Secondary@@QAEXEH@Z',0x00410B10,96),
    'secondary-horizontal-offset':('?SetHorizontalOffset@Secondary@@QAEXHH@Z',0x00410A40,63),
    'secondary-set-horizontal-shake':('?SetHorizontalShake@Secondary@@QAEXHH@Z',0x00410A80,63),
    'context-scene-timer':('?SetSceneTimer@Context@@QAEXH@Z',0x004080C0,60),
    'secondary-apply-damage':('?ApplyDamage@Secondary@@QAEXHN@Z',0x004105A0,489),
    'secondary-set-character-tint':('?SetCharacterTint@Secondary@@QAEXEH@Z',0x00410AC0,75),
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
            230:0x00610A47,231:0x00610B78,232:0x00610CA9,240:0x00610DDA,241:0x00610FCC,249:0x0061129C,250:0x006113DC,251:0x00611590,252:0x00611767,253:0x00611A7D,254:0x00611B49,255:0x00611DB0,256:0x00612093,257:0x0061237E,258:0x00612569,259:0x00612757,260:0x0061294C,261:0x00612BEE,262:0x00612CDD,263:0x00612DFD,264:0x00612F90,265:0x00613123,266:0x006133B5,267:0x006134F0,268:0x00613632,269:0x00613774,303:0x00613824,304:0x00613B1F,305:0x00613E1A,306:0x006141C6,307:0x006144B9,308:0x006147FD,309:0x00614B6A,312:0x00614D70,315:0x006150C3,316:0x0061519F,317:0x0061527B,318:0x00615357,319:0x0061552B,320:0x006155C9,321:0x0061579D,322:0x0061583B,323:0x00615A0F,324:0x00615AAD,325:0x00615D30}
BRANCH=re.compile(r'^j\w+\s+(?:(?:near|short)\s+)?0x([0-9a-f]+)$')

def verify_leaf_dependencies():
    path=ROOT/'docs/evidence/character04-slot06-leaf-dependencies-exact.json'
    evidence=json.loads(path.read_text())
    assert evidence['schema_version']==1
    assert evidence['owner']['symbol']=='?Slot06@Character04@@UAEXXZ'
    reports={r['unit']:r for r in evidence['reports']}
    assert set(reports)==set(LEAF_DEPENDENCIES)
    for unit,(symbol,address,size) in LEAF_DEPENDENCIES.items():
        report=reports[unit]
        assert report['result']=='exact' and report['acceptance_authority']=='complete-function-codegen',unit
        assert report['symbol']==symbol and int(report['target_address'],16)==address,unit
        assert report['size']==report['matched_bytes']==size and report['difference_count']==0,unit
        assert report['first_differences']==[],unit
        assert EXTERNAL_CALLS[symbol]==address,unit
    return sum(size for _,_,size in LEAF_DEPENDENCIES.values())

def main():
    leaf_bytes=verify_leaf_dependencies()
    image=verify_target()
    assert struct.unpack('<I',target_bytes(image,0x00788B94,4))[0]==BASE
    whole=target_bytes(image,BASE,CODE_SIZE)
    assert len(whole)==59143 and hashlib.sha256(whole).hexdigest()==NATIVE_CODE_SHA
    assert target_bytes(image,0x00616033,4)==bytes.fromhex('8be55dc3')
    orig=whole[:END-BASE]
    assert len(orig)==59139 and hashlib.sha256(orig).hexdigest()==NATIVE_PREFIX_SHA
    # The two state265 x87 resource costs are pinned raw absolute operands;
    # verify both instruction bytes and the original 500/250 constants.
    assert target_bytes(image,0x00787C30,8)==struct.pack('<d',500.0)
    assert target_bytes(image,0x00787C70,8)==struct.pack('<d',250.0)
    for va,raw in ((0x00613217,bytes.fromhex('dc25307c7800')),
                   (0x00613231,bytes.fromhex('dc25707c7800'))):
        assert orig[va-BASE:va-BASE+len(raw)]==raw,(hex(va),orig[va-BASE:va-BASE+len(raw)].hex())
    assert target_bytes(image,0x007872F8,8)==struct.pack('<d',0.0)
    for va in (0x0061378D,0x00613799):
        raw=bytes.fromhex('dd05f8727800')
        assert orig[va-BASE:va-BASE+len(raw)]==raw,(hex(va),orig[va-BASE:va-BASE+len(raw)].hex())
    # State303's launch, friction and zero-floor constants are original PE
    # operands, not reconstructed decimal approximations.
    for va,value in ((0x007872C0,5.0),(0x007880A8,1.8),(0x007885B0,-0.05)):
        assert target_bytes(image,va,8)==struct.pack('<d',value),(hex(va),target_bytes(image,va,8).hex())
    for va,raw in ((0x0061383D,'dd05f8727800'),(0x00613849,'dd05f8727800'),
                   (0x00613855,'dd05f8727800'),(0x00613970,'dd05c0727800'),
                   (0x00613993,'dd05a8807800'),(0x0061399F,'dd05b0857800'),
                   (0x006139CC,'dc1df8727800'),(0x006139DC,'dd05f8727800'),
                   (0x00613A67,'dd05f8727800'),
                   (0x00613B38,'dd05f8727800'),(0x00613B44,'dd05f8727800'),
                   (0x00613B50,'dd05f8727800'),(0x00613C6B,'dd05508b7800'),
                   (0x00613C8E,'dd05a8807800'),(0x00613C9A,'dd05b0857800'),
                   (0x00613CC7,'dc1df8727800'),(0x00613CD7,'dd05f8727800'),
                   (0x00613D62,'dd05f8727800')):
        raw=bytes.fromhex(raw)
        assert orig[va-BASE:va-BASE+len(raw)]==raw,(hex(va),orig[va-BASE:va-BASE+len(raw)].hex())
    assert target_bytes(image,0x00788B50,8)==struct.pack('<d',7.0)
    # State306's opponent reposition, launch and effect-height constants.
    for va,value in ((0x007872F0,0.3),(0x00787D58,-4.0),(0x00787CE0,40.0),(0x00788B48,400.0)):
        assert target_bytes(image,va,8)==struct.pack('<d',value),(hex(va),target_bytes(image,va,8).hex())
    for va,raw in ((0x006141DF,'dd05f0727800'),(0x00614239,'dc05f8727800'),
                   (0x00614248,'dd05f8727800'),(0x006142DA,'dd05f8727800'),
                   (0x006142EE,'dd05587d7800'),(0x00614307,'dd05488b7800'),
                   (0x00614343,'dc25e07c7800')):
        raw=bytes.fromhex(raw)
        assert orig[va-BASE:va-BASE+len(raw)]==raw,(hex(va),orig[va-BASE:va-BASE+len(raw)].hex())
    # State307 reuses the throw constants but has its own native operand sites.
    for va,raw in ((0x006144DF,'dd05f0727800'),(0x00614539,'dc05f8727800'),
                   (0x00614548,'dd05f8727800'),(0x006145E9,'dd05f8727800'),
                   (0x006145FD,'dd05587d7800'),(0x00614616,'dd05488b7800'),
                   (0x00614652,'dc25e07c7800')):
        raw=bytes.fromhex(raw)
        assert orig[va-BASE:va-BASE+len(raw)]==raw,(hex(va),orig[va-BASE:va-BASE+len(raw)].hex())
    # State315 zeros both movement components with original absolute 0.0 loads.
    assert target_bytes(image,0x007872F8,8)==struct.pack('<d',0.0)
    for va in (0x006150DC,0x006150E8):
        assert orig[va-BASE:va-BASE+6]==bytes.fromhex('dd05f8727800'),hex(va)
    # State316 is the sibling zero-velocity recovery and uses the same PE 0.0.
    for va in (0x006151B8,0x006151C4):
        assert orig[va-BASE:va-BASE+6]==bytes.fromhex('dd05f8727800'),hex(va)
    # State317 is the third native register-allocation variant of the same reset.
    for va in (0x00615294,0x006152A0):
        assert orig[va-BASE:va-BASE+6]==bytes.fromhex('dd05f8727800'),hex(va)
    # State318's frame-0 movement reset uses the same original 0.0 operand.
    for va in (0x00615370,0x0061537C):
        assert orig[va-BASE:va-BASE+6]==bytes.fromhex('dd05f8727800'),hex(va)
    # State319's frame-0 velocity reset uses the same original 0.0 loads.
    for va in (0x00615544,0x00615550):
        assert orig[va-BASE:va-BASE+6]==bytes.fromhex('dd05f8727800'),hex(va)
    # State320 is the alternate-cost/effect variant and starts with the same 0.0 loads.
    for va in (0x006155E2,0x006155EE):
        assert orig[va-BASE:va-BASE+6]==bytes.fromhex('dd05f8727800'),hex(va)
    # State321 and322 have their own original frame-0 0.0 operand sites.
    for va in (0x006157B6,0x006157C2,0x00615854,0x00615860):
        assert orig[va-BASE:va-BASE+6]==bytes.fromhex('dd05f8727800'),hex(va)
    # State323 is the third simple-reset variant with independent operand sites.
    for va in (0x00615A28,0x00615A34):
        assert orig[va-BASE:va-BASE+6]==bytes.fromhex('dd05f8727800'),hex(va)
    # State324's frame-4 reset/zero comparison loads are original absolute 0.0.
    for va in (0x00615BD5,0x00615BE1,0x00615BED,0x00615CDD):
        assert orig[va-BASE:va-BASE+6]==bytes.fromhex('dd05f8727800'),hex(va)
    # State325 pins the partner launch and meter-scaled damage constants.
    for va,value in ((0x00787F50,-5.0),(0x00787C30,500.0),
                     (0x00787FB8,0.15),(0x00788B40,3500.0)):
        assert target_bytes(image,va,8)==struct.pack('<d',value),(hex(va),target_bytes(image,va,8).hex())
    for va,raw in ((0x00615DB9,'dd05f8727800'),(0x00615DC2,'dd05f8727800'),
                   (0x00615E6F,'dd05f8727800'),(0x00615E83,'dd05507f7800'),
                   (0x00615EBD,'dd05307c7800'),(0x00615ED2,'dc0db87f7800'),
                   (0x00615ED8,'dc05408b7800')):
        raw=bytes.fromhex(raw)
        assert orig[va-BASE:va-BASE+len(raw)]==raw,(hex(va),orig[va-BASE:va-BASE+len(raw)].hex())
    # State309's third local effect uses the original absolute zero Y operand.
    assert target_bytes(image,0x007872F8,8)==struct.pack('<d',0.0)
    assert orig[0x00614C85-BASE:0x00614C85-BASE+6]==bytes.fromhex('dd05f8727800')
    # State312's higher launch and damage constants are pinned to the PE.
    for va,value in ((0x007889B0,-8.0),(0x00787C80,750.0)):
        assert target_bytes(image,va,8)==struct.pack('<d',value),(hex(va),target_bytes(image,va,8).hex())
    for va,raw in ((0x00614D96,'dd05f0727800'),(0x00614DE3,'dc05f8727800'),
                   (0x00614DF2,'dd05f8727800'),(0x00614E93,'dd05f8727800'),
                   (0x00614EA7,'dd05b0897800'),(0x00614EB3,'dd05807c7800'),
                   (0x00614ECF,'dd05707e7800'),(0x00614ED5,'dc8a78010000'),
                   (0x00614EDB,'dc35007c7800'),(0x00614F18,'dc25e07c7800')):
        raw=bytes.fromhex(raw)
        assert orig[va-BASE:va-BASE+len(raw)]==raw,(hex(va),orig[va-BASE:va-BASE+len(raw)].hex())
    # State308 additionally scales the opponent's post-hit property from
    # this owner's comboDamageScale (200 * scale / 10000).
    for va,value in ((0x00787E70,200.0),(0x00787C00,10000.0)):
        assert target_bytes(image,va,8)==struct.pack('<d',value),(hex(va),target_bytes(image,va,8).hex())
    for va,raw in ((0x00614823,'dd05f0727800'),(0x0061487D,'dc05f8727800'),
                   (0x0061488C,'dd05f8727800'),(0x0061492D,'dd05f8727800'),
                   (0x00614941,'dd05587d7800'),(0x0061495A,'dd05488b7800'),
                   (0x00614976,'dd05707e7800'),(0x00614982,'dc35007c7800'),
                   (0x006149BF,'dc25e07c7800')):
        raw=bytes.fromhex(raw)
        assert orig[va-BASE:va-BASE+len(raw)]==raw,(hex(va),orig[va-BASE:va-BASE+len(raw)].hex())
    # State305's capture/throw operands and both post-hit local-effect Y
    # coordinates are independently pinned to original PE data.
    for va,value in ((0x00787C28,10.0),(0x00787C10,20.0),(0x00788530,38.0)):
        assert target_bytes(image,va,8)==struct.pack('<d',value),(hex(va),target_bytes(image,va,8).hex())
    for va,raw in ((0x00613E5A,'dd05f8727800'),(0x00613E66,'dd05f8727800'),
                   (0x00613E72,'dd05f8727800'),(0x00613F91,'dd05287c7800'),
                   (0x00613FB4,'dd05a8807800'),(0x00613FC0,'dd05b0857800'),
                   (0x00613FED,'dc1df8727800'),(0x00613FFD,'dd05f8727800'),
                   (0x0061408C,'dd05f8727800'),(0x006140B2,'dd05f8727800'),
                   (0x006140BB,'dd05107c7800'),(0x006140F3,'dd05f8727800'),
                   (0x006140FC,'dd0530857800')):
        raw=bytes.fromhex(raw)
        assert orig[va-BASE:va-BASE+len(raw)]==raw,(hex(va),orig[va-BASE:va-BASE+len(raw)].hex())
    table=target_bytes(image,TABLE_BASE,556)
    selectors=target_bytes(image,SELECTOR_BASE,325)
    assert Counter(selectors)[138]==187 and sum(x!=138 for x in selectors)==138
    assert len(table)==139*4
    for case,addr in REAL_CASES.items():
        ordinal=selectors[case-1]
        assert ordinal!=138 and struct.unpack_from('<I',table,4*ordinal)[0]==addr
    assert [struct.unpack_from('<I',table,i*4)[0] for i in range(138)]==[
        REAL_CASES[i] for i in list(range(1,10))+[13,14,15,16,47]+list(range(50,78))+list(range(81,88))+list(range(96,100))+list(range(150,159))+list(range(161,172))+[180]+list(range(200,217))+[220,221,230,231,232,240,241,249,250,251,252,253,254,255,256,257,258,259,260,261,262,263,264,265,266,267,268,269,303,304,305,306,307,308,309,312,315,316,317,318,319,320,321,322,323,324,325]]
    used,original,compiled,relocs=run(325)
    assert used==set(REAL_CASES)
    target_ins=disasm(orig)
    candidate_ins=disasm(compiled)
    assert len(target_ins)==16127 and len(candidate_ins)>len(target_ins)
    assert target_ins[2][2]=='sub esp,0x2e8'
    assert candidate_ins[2][2]=='sub esp,0x1c8'
    # VC7.1's generated locals retain their native EBP offsets; reserve the
    # remaining 0x120 bytes immediately after its 0x1C8 compiler prologue.
    assert candidate_ins[4][2]=='sub esp,0x120'
    assert 0x1c8+0x120==0x2e8
    code_shift=-6  # one explicit six-byte tail reservation after native insn 3
    assert len(target_ins[2][1])==len(candidate_ins[2][1])
    assert target_ins[-1][0]+len(target_ins[-1][1])==len(orig)
    assert candidate_ins[len(target_ins)+1][0]==len(orig)-code_shift
    original_offsets={x[0] for x in target_ins}
    candidate_offsets={x[0] for x in candidate_ins}
    target_by_offset={x[0]:x for x in target_ins}
    candidate_by_offset={x[0]:x for x in candidate_ins}
    candidate_table=len(compiled)-556-325
    candidate_selector=candidate_table+556
    candidate_epilogue=candidate_table-4
    # The compiler-generated 325-byte selector is byte-identical. Its 139
    # jump-table relocations target the exact original case-entry ordering.
    assert compiled[candidate_selector:candidate_selector+325]==selectors
    candidate_table_relocs=sorted(
        (r for r in relocs if candidate_table<=r['offset']<candidate_table+556),
        key=lambda r:r['offset'])
    assert len(candidate_table_relocs)==139
    for i,r in enumerate(candidate_table_relocs):
        native_va=struct.unpack_from('<I',table,4*i)[0]
        assert r['offset']==candidate_table+4*i and r['type']=='DIR32'
        assert r.get('local_target_offset')==native_va-BASE-code_shift,(i,r,hex(native_va))
    assert candidate_by_offset[candidate_epilogue][2]=='mov esp,ebp'
    assert candidate_by_offset[candidate_epilogue+2][2]=='pop ebp'
    assert candidate_by_offset[candidate_epilogue+3][2]=='ret'
    ignore_candidate_bytes={}
    stack_temp_displacements={
        # Four state256 int-to-double conversions each use two instructions;
        # VC7.1's scratch slots remain four bytes above the native slots.
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
        candidate_off=off-code_shift
        assert orig[off:off+4]==native_disp,(hex(BASE+off),orig[off:off+4])
        assert compiled[candidate_off:candidate_off+4]==candidate_disp,(hex(BASE+off),compiled[candidate_off:candidate_off+4])
    ignore_candidate_bytes.update({off-code_shift:'state256 x87 scratch-slot displacement'
                                   for off in stack_temp_disp_offsets})
    internal=outbound=0
    for i,a in enumerate(target_ins):
        # The explicit native-tail reservation is the sole extra prologue
        # instruction; all remaining candidate instructions shift by +6.
        b=candidate_ins[i if i<4 else i+1]
        if i==2:continue
        assert a[0]==b[0]+(code_shift if i>=4 else 0),(i,a,b)
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
            assert dst==got+code_shift,(i,a,b)
            internal+=1
        else:
            assert BASE+dst==0x00616033,(i,a,hex(BASE+dst))
            if a[1][0]==0xe9:
                assert b[1][0]==0xe9 and len(a[1])==len(b[1])==5,(i,a,b)
                if got < len(orig)-code_shift:
                    # VC7.1 may route a return through an original in-prefix
                    # shared-return trampoline before the common epilogue.
                    native_got=got+code_shift
                    assert native_got in target_by_offset and got in candidate_by_offset,(i,a,b)
                    native_trampoline=target_by_offset[native_got]
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
            elif a[1][0]==0x0f and 0x80<=a[1][1]<=0x8f:
                # The final case has native near conditional exits directly
                # to the shared epilogue; their candidate targets are pinned
                # to the epilogue after the single fallthrough trampoline.
                assert b[1][:2]==a[1][:2] and len(a[1])==len(b[1])==6,(i,a,b)
                assert got==candidate_epilogue,(i,a,b,hex(candidate_epilogue))
                ignore_candidate_bytes.update({b[0]+k:'shared conditional-return displacement'
                                               for k in range(2,6)})
            elif 0x70<=a[1][0]<=0x7f:
                assert b[1][0]==a[1][0] and len(a[1])==len(b[1])==2,(i,a,b)
                assert got==candidate_epilogue,(i,a,b,hex(candidate_epilogue))
                ignore_candidate_bytes[b[0]+1]='shared conditional-return displacement'
            else:
                raise AssertionError(('unsupported shared-return branch',i,a,b))
            outbound+=1
    assert (internal,outbound)==(1417,187),(internal,outbound)
    relocations=[r for r in relocs if r['offset']<len(orig)-code_shift]
    local=[r for r in relocations if 'local_target_offset' in r]
    external=[r for r in relocations if 'local_target_offset' not in r]
    assert len(relocations)==1089 and len(local)==2 and len(external)==1087
    expected_locals={SELECTOR_BASE:candidate_table+556,TABLE_BASE:candidate_table}
    for r in relocations:
        off=r['offset'];pos=off+code_shift
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
    for i,a in enumerate(target_ins):
        b=candidate_ins[i if i<4 else i+1]
        if i==2:continue
        for k in range(len(a[1])):
            if b[0]+k in ignore_candidate_bytes:continue
            if orig[a[0]+k]!=compiled[b[0]+k]:
                raw.append((hex(BASE+a[0]+k),a[2],b[2]))
    assert not raw,raw[:15]
    print('Character04 Slot06 selected original-bound prefix PASS (NOT full Exact):')
    print('  native original 59,143-byte boss; 138 live IDs + 187 defaults; reviewed real states 1-9, 13-16, 47, 50-77, 81-87, 96-99, 150-158, 161-171, 180, 200-216, 220-221, 230-232, 240-241, 249-269,303-309,312,315-325 + default')
    print(f'  {len(orig)} original code bytes, {len(target_ins)} x86 instructions, {internal} native internal + {outbound} shared-return branches')
    print(f'  {len(external)} original-bound calls / IEEE-754 operands + {len(local)} native-local selector/table pointers')
    print(f'  {len(LEAF_DEPENDENCIES)} boss leaf dependencies independently Exact: {leaf_bytes} bytes, zero differences')
    print(f'  Exact dispatch data: 139-entry table target order + 325 selector bytes; {len(candidate_table_relocs)} table labels bound to original case order')
    print('  Exact scratch slots: both state255 EBP-0x1BC references match native.')
    print('  Remaining explicit byte differences: split 0x2E8 prologue (0x1C8 + 0x120), eight state256 x87 scratch displacement bytes, shared-return routing and target-bound COFF fields.')
    print('  All 138 live cases and dispatch data are covered; one-instruction prologue, eight x87 scratch bytes and shared-return layout remain NOT Exact.')
if __name__=='__main__':main()
