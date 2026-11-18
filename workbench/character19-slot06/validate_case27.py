"""Validate the Kanna special knockback effect in selector case 0x27."""
import re
import struct
import sys
from pathlib import Path

ROOT = Path(__file__).resolve().parents[2]
native = (ROOT / ".analysis/kanna-slot06/native.c").read_text()
match = re.search(r"^\s*case 0x27:(.*?)(?=^\s*case )", native, re.M | re.S)
assert match is not None
block = match.group(1)
for expression in (
    "*(double *)(param_1 + 0x46) = *(double *)(param_1 + 0x46) - _DAT_00787d80;",
    "param_1[0xc4e] == 0",
    "*(short *)(param_1 + 0x52) = (short)param_1[0x52] + 0x1e;",
    "param_1[0xc4e] = param_1[0xc4e] + 1;",
    "*(short *)(param_1 + 0x49) = (short)param_1[0x49] + 0x78;",
    "*(undefined1 *)((int)param_1 + 0x2c9) = 0x1f;",
    "FUN_007783b8()",
    "FUN_00407100()",
    "*(undefined8 *)(param_1 + 0x12) = _DAT_00787d38;",
    "*(double *)(param_1 + 0xe) = *(double *)(param_1 + 0xe) + *(double *)(param_1 + 0x12);",
    "*(undefined2 *)(param_1 + 2) = 0x62;",
    "*(undefined2 *)(param_1 + 2) = 0x61;",
):
    assert expression in block, expression

sys.path.insert(0, str(ROOT / "scripts"))
from common import verify_target, target_bytes
pe = verify_target()
constants = {
    0x00787d80: 0.8,
    0x00787c50: 0.5,
    0x00787d40: -2.5,
    0x00787d38: 0.025,
}
for address, expected in constants.items():
    actual = struct.unpack("<d", target_bytes(pe, address, 8))[0]
    assert actual == expected, (hex(address), actual, expected)

source = (ROOT / "workbench/character19-slot06/Character19Slot06.cpp").read_text()
for expression in (
    "case 70:",
    "field3138 == 0",
    "meter = meter + 30",
    "field3138 = field3138 + 1",
    "airActionLockFrames = airActionLockFrames + 0x78",
    "velocityX = 0.5",
    "velocityY = -2.5",
    "gravity = 0.025",
    "ResetLocalEffectSpawn(&spawn);",
    "pendingContextSoundSlot = 0x1f;",
    "spawn.type = 0;",
    "spawn.x = (double)(int)positionX;",
    "spawn.y = (double)(int)positionY;",
    "spawn.group = 2;",
    "spawn.layer = 1;",
    "contextOwner->EmitEffect(&spawn);",
):
    assert expression in source, expression

# FUN_007783b8 is the VC floating-to-integer helper: it corrects the
# x87 rounded FISTP result toward zero for both signs.
helper_asm = (ROOT / ".analysis/kanna-slot06/helpers/7783b8.asm").read_text()
for instruction in ("FISTP qword ptr", "FSUBP", "ADC EAX", "SBB EAX"):
    assert instruction in helper_asm, instruction

for value, expected in [
    (1.4,1),(1.5,1),(1.9,1),(2.5,2),(3.9,3),
    (-1.4,-1),(-1.5,-1),(-1.9,-1),(-2.5,-2),(-3.9,-3),
]:
    assert int(value) == expected

assert source.index("timing.animationFrameCount = patterns[field0008].count;") < source.index("ResetLocalEffectSpawn(&spawn);") < source.index("switch (selectorCase)")
spawn_reset = (ROOT / "src/SecondarySpawn.cpp").read_text()
for expression in (
    "spawn->owner = 0;",
    "spawn->group = 0;",
    "spawn->palette = 255;",
    "spawn->payload = 0;",
    "spawn->field0028 = 0;",
    "spawn->field0030 = 0;",
    "spawn->bounds.left = 0;",
    "spawn->bounds.top = 0;",
    "spawn->bounds.right = 0;",
    "spawn->bounds.bottom = 0;",
):
    assert expression in spawn_reset, expression

effect_pool = (ROOT / "src/EffectPool.cpp").read_text()
for expression in (
    "effects[field1380].type = spawn->type;",
    "effects[field1380].x = spawn->x;",
    "effects[field1380].y = spawn->y;",
    "effects[field1380].group = spawn->group;",
    "effects[field1380].layer = spawn->layer;",
    "effects[field1380].palette = spawn->palette;",
    "AdvanceEffectWrite();",
):
    assert expression in effect_pool, expression

print({
    "selector_case":"0x27",
    "state_id":70,
    "native_bytes":480,
    "verified_constants":len(constants),
    "conversion":"truncate-toward-zero",
    "effect": "Context::EmitEffect with integer-truncated character position",
})
