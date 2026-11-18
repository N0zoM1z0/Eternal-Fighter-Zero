"""Validate Kanna's airborne recoil/local-effect selector case 0x2f."""
import re
import struct
import sys
from pathlib import Path

from selector_support import assert_selector_case, selector_case_for_state

ROOT = Path(__file__).resolve().parents[2]
native = (ROOT / ".analysis/kanna-slot06/native.c").read_text()
match = re.search(r"^\s*case 0x2f:(.*?)(?=^\s*case )", native, re.M | re.S)
assert match is not None
block = match.group(1)
for expression in (
    "*(double *)(param_1 + 0x46) = *(double *)(param_1 + 0x46) - _DAT_00787d80;",
    "*(short *)(param_1 + 0x52) = (short)param_1[0x52] + 0x1e;",
    "FUN_007783b8()",
    "local_3c = (char)param_1[0x14];",
    "local_33 = 1;",
    "(**(code **)(*param_1 + 0x24))();",
    "*(undefined8 *)(param_1 + 0x12) = _DAT_00787d60;",
    "*(double *)(param_1 + 0xc) = *(double *)(param_1 + 0xc) + _DAT_00787d18;",
    "*(double *)(param_1 + 0xe) = *(double *)(param_1 + 0xe) + *(double *)(param_1 + 0x12);",
    "if (_DAT_007872f8 < *(double *)(param_1 + 0xc))",
    "*(short *)((int)param_1 + 10) = *(short *)((int)param_1 + 10) + -1;",
    "*(double *)(param_1 + 10) + *(double *)(param_1 + 0xe)",
    "*(short *)((int)param_1 + 10) == 1",
    "*(undefined2 *)(param_1 + 2) = 0x62;",
    "*(undefined2 *)(param_1 + 2) = 0x61;",
):
    assert expression in block, expression

sys.path.insert(0, str(ROOT / "scripts"))
from common import verify_target, target_bytes
pe = verify_target()
constants = {
    0x00787d80: 0.8,
    0x00787d18: 0.02,
    0x00787d60: 0.032,
}
for address, expected in constants.items():
    actual = struct.unpack("<d", target_bytes(pe, address, 8))[0]
    assert actual == expected, (hex(address), actual, expected)

source = (ROOT / "workbench/character19-slot06/Character19Slot06Cases.cpp").read_text()
assert "Slot06UpdateAirKnockback" not in source
fragment = (ROOT / "workbench/character19-slot06/Character19Slot06Case2F.inc").read_text()
for expression in (
    "field0118 = field0118 - 0.8;",
    "field000a == 0",
    "spawn.type = 499;",
    "spawn.x = (double)(int)positionX;",
    "spawn.y = (double)(int)positionY;",
    "spawn.flag0018 = (unsigned char)facing;",
    "spawn.layer = 1;",
    "EmitLocalEffect(&spawn);",
    "meter = meter + 30;",
    "velocityX = knockbackVelocityX;",
    "velocityY = knockbackVelocityY;",
    "gravity = 0.032;",
    "velocityX = velocityX + 0.02;",
    "velocityY = velocityY + gravity;",
    "if (velocityX > 0.0)",
    "field000a = field000a - 1;",
    "(positionY + velocityY) >= 0.0",
    "field000a == 1",
    "field0008 = 0x61;",
    "field0008 = 0x62;",
    "timing.frameDuration",
    "timing.animationFrameCount",
):
    assert expression in fragment, expression

dispatcher = (ROOT / "workbench/character19-slot06/Character19Slot06.cpp").read_text()
assert_selector_case(dispatcher, 81)
assert '#include "Character19Slot06Case2F.inc"' in dispatcher
assert "Slot06UpdateAirKnockback(" not in dispatcher
assert dispatcher.index("ResetLocalEffectSpawn(&spawn);") < dispatcher.index("switch (selectorCase)")

# Independently recovered characters share the same state-81 semantics.
analog = (ROOT / "src/Character23State.cpp").read_text()
for expression in (
    "case 81:",
    "effect.type = 499;",
    "effect.flag0018 = (unsigned char)facing;",
    "meter = meter + 0x1e;",
    "velocityX = knockbackVelocityX;",
    "velocityY = knockbackVelocityY;",
    "velocityX = velocityX + 0.02;",
    "field000a == 1",
):
    assert expression in analog, expression

emit = (ROOT / "src/Character19Lifecycle.cpp").read_text()
assert "RemoveLocalEffect(effectWrite);" in emit
assert "Secondary::EmitLocalEffect(effect);" in emit

print({
    "selector_case": "0x2f",
    "native_bytes": 485,
    "state_id": 81,
    "effect_type": 499,
    "verified_constants": len(constants),
    "landing_states": [0x61, 0x62],
})
