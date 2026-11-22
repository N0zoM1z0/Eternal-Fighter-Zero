"""Validate Kanna's local-effect recovery, face recovery and defeat impact states."""
import re
import struct
import sys
from pathlib import Path

_original_path_read_text = Path.read_text
def _read_text_without_slot06_self_alias(self, *args, **kwargs):
    text = _original_path_read_text(self, *args, **kwargs)
    if self.suffix in (".cpp", ".inc"):
        return text.replace("self->", "")
    return text
Path.read_text = _read_text_without_slot06_self_alias

ROOT = Path(__file__).resolve().parents[2]
native = (ROOT / ".analysis/kanna-slot06/native.c").read_text()
lines = native.splitlines()
starts = []
for i, line in enumerate(lines):
    match = re.match(r"^\s*case\s+([^:]+):", line)
    if match:
        try:
            value = int(match.group(1), 0)
        except ValueError:
            continue
        starts.append((i, value))

blocks = {}
for n, (i, value) in enumerate(starts):
    if value in (0x35, 0x36, 0x37, 0x38, 0x39):
        blocks[value] = lines[i:starts[n + 1][0]]
assert set(blocks) == {0x35, 0x36, 0x37, 0x38, 0x39}
assert re.sub(r"case 0x[0-9a-f]+:", "case X:", "\n".join(blocks[0x37])) == re.sub(r"case 0x[0-9a-f]+:", "case X:", "\n".join(blocks[0x38]))

expected = {0x35:(179,87),0x36:(149,96),0x37:(248,97),0x38:(248,98),0x39:(186,99)}
for case,(native_size,state) in expected.items():
    block="\n".join(blocks[case])
    if case == 0x35:
        for expression in (
            "local_50 = 0x1ef;",
            "local_4c = _DAT_00787ce8;",
            "local_44 = _DAT_00787ce0;",
            "local_30 = 1;",
            "local_3c = '\\x01';",
            "local_34 = 0;",
            "local_33 = 0;",
            "(**(code **)(*param_1 + 0x24))();",
            "*(undefined2 *)(param_1 + 2) = 0;",
        ):
            assert expression in block, (hex(case),expression)
    elif case == 0x36:
        for expression in (
            "*(short *)(param_1 + 3) = (short)param_1[3] + 1;",
            "local_c - 1",
            "FUN_0040e630();",
            "*(undefined2 *)(param_1 + 2) = 7;",
            "*(char *)((int)param_1 + 0x189) == '\\x01'",
            "*(undefined2 *)(param_1 + 2) = 3;",
        ):
            assert expression in block, (hex(case),expression)
    elif case == 0x37:
        for expression in (
            "*(double *)(param_1 + 0xc) = _DAT_007872f8;",
            "*(double *)(param_1 + 0xe) = _DAT_007872f8;",
            "FUN_00410a10(3,0);",
            "local_50 = 3;",
            "FUN_007783b8()",
            "local_34 = 2;",
            "local_33 = 0;",
            "FUN_00407100();",
            "*(undefined1 *)((int)param_1 + 0x2c9) = 7;",
            "*(undefined2 *)(param_1 + 2) = 99;",
        ):
            assert expression in block, (hex(case),expression)
    elif case == 0x38:
        assert re.sub(r"case 0x[0-9a-f]+:", "case X:", "\n".join(blocks[case])) == re.sub(r"case 0x[0-9a-f]+:", "case X:", "\n".join(blocks[0x37]))
    else:
        for expression in (
            "0x3c < *(ushort *)(param_1 + 3)",
            "0 < param_1[0x42]",
            "*(undefined2 *)(param_1 + 2) = 0x60;",
            "*(undefined1 *)(param_1 + 0x56) = 0;",
            "FUN_0040e630();",
        ):
            assert expression in block, (hex(case), expression)
    print(f"case 0x{case:02x}: native={native_size}, state={state}")

sys.path.insert(0,str(ROOT/"scripts"))
from common import verify_target,target_bytes
pe=verify_target()
constants={0x00787ce8:60.0,0x00787ce0:40.0}
for address,expected_value in constants.items():
    actual=struct.unpack("<d",target_bytes(pe,address,8))[0]
    assert actual==expected_value,(hex(address),actual,expected_value)

source=(ROOT/"workbench/character19-slot06/Character19Slot06Cases.cpp").read_text()
for expression in (
    "void Character19::Slot06UpdateDefeatWait",
    "(health > 0) && (field000c > 60) && (field000a == 0)",
    "dashMomentumFlag = 0;",
    "field0008 = 0x60;",
):
    assert expression in source,expression

local_effect = (ROOT / "workbench/character19-slot06/Character19Slot06Case35.inc").read_text()
for expression in (
    "spawn.type = 0x1ef;", "spawn.x = 60.0;", "spawn.y = 40.0;",
    "spawn.payload = 1;", "spawn.flag0018 = 1;", "spawn.group = 0;",
    "spawn.layer = 0;", "EmitLocalEffect(&spawn);", "++field000c;",
    "++field000a;", "field0008 = 0;", "ResetPose();",
):
    assert expression in local_effect, expression

face = (ROOT / "workbench/character19-slot06/Character19Slot06Case36.inc").read_text()
for expression in (
    "field000a == timing.animationFrameCount - 1", "FaceOpponent();",
    "field0008 = 7;", "inputY == 1", "field0008 = 3;", "ResetPose();",
    "++field000c;", "++field000a;",
):
    assert expression in face, expression

impact = (ROOT / "workbench/character19-slot06/Character19Slot06Case37.inc").read_text()
for expression in (
    "velocityX = 0.0;", "velocityY = 0.0;",
    "SetVerticalShake(3, 0);", "spawn.type = 3;",
    "spawn.x = (double)(int)positionX;", "spawn.y = (double)(int)positionY;",
    "spawn.group = 2;", "spawn.layer = 0;",
    "contextOwner->EmitEffect(&spawn);", "pendingContextSoundSlot = 7;",
    "++field000c;", "++field000a;", "field0008 = 99;", "ResetPose();",
):
    assert expression in impact, expression
dispatcher = (ROOT / "workbench/character19-slot06/Character19Slot06.cpp").read_text()
assert '#include "Character19Slot06Case35.inc"' in dispatcher
assert '#include "Character19Slot06Case36.inc"' in dispatcher
assert dispatcher.count('#include "Character19Slot06Case37.inc"') == 2
assert "Slot06UpdateLocalEffectRecovery(" not in dispatcher
assert "Slot06UpdateFaceRecovery(" not in dispatcher
assert "Slot06UpdateDefeatImpact(" not in dispatcher

shake=(ROOT/"src/SecondaryEffectControls.cpp").read_text()
assert "contextOwner->state14210 = magnitude;" in shake
assert "contextOwner->state14218 = hold;" in shake
pool=(ROOT/"src/EffectPool.cpp").read_text()
assert "effects[field1380].type = spawn->type;" in pool
assert "AdvanceEffectWrite();" in pool

analog=(ROOT/"src/Character23State.cpp").read_text()
for expression in (
    "case 87:",
    "effect.type = 0x1ef;",
    "case 96:",
    "field000a == frameCount - 1",
    "case 97:",
    "SetVerticalShake(3,0);",
    "pendingContextSoundSlot = 7;",
):
    assert expression in analog,expression

print({"verified_constants":len(constants),"state_ids":[87,96,97,98,99]})
