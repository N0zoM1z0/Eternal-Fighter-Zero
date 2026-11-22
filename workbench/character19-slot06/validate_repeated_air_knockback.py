"""Validate the repeated airborne knockback selector case 0x30."""
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

from selector_support import assert_selector_case, selector_case_for_state

ROOT = Path(__file__).resolve().parents[2]
native = (ROOT / ".analysis/kanna-slot06/native.c").read_text()
match = re.search(r"^\s*case 0x30:(.*?)(?=^\s*case )", native, re.M | re.S)
assert match is not None
block = match.group(1)
for expression in (
    "*(double *)(param_1 + 0x46) = *(double *)(param_1 + 0x46) - _DAT_00787d80;",
    "*(undefined1 *)((int)param_1 + 0x2c9) = 0x1e;",
    "*(undefined8 *)(param_1 + 0xe) = _DAT_00787d10;",
    "*(undefined8 *)(param_1 + 0xc) = _DAT_00787d08;",
    "param_1[0xc4e] = param_1[0xc4e] + 1;",
    "*(short *)(param_1 + 0x52) = (short)param_1[0x52] + 0x1e;",
    "*(undefined8 *)(param_1 + 0xc) = *(undefined8 *)(param_1 + 0x30);",
    "*(undefined8 *)(param_1 + 0xe) = *(undefined8 *)(param_1 + 0x32);",
    "*(undefined8 *)(param_1 + 0x12) = _DAT_00787d60;",
    "*(undefined2 *)((int)param_1 + 10) = 5;",
    "3 < *(ushort *)((int)param_1 + 10)",
    "*(short *)((int)param_1 + 10) == 4",
    "param_1[0xc4e] < 8",
    "param_1[0xc4e] = param_1[0xc4e] + 1;",
    "*(short *)((int)param_1 + 10) = *(short *)((int)param_1 + 10) + -2;",
    "4 < *(ushort *)((int)param_1 + 10)",
    "*(undefined2 *)(param_1 + 2) = 0x62;",
    "*(undefined2 *)(param_1 + 2) = 0x61;",
):
    assert expression in block, expression

sys.path.insert(0, str(ROOT / "scripts"))
from common import verify_target, target_bytes
pe = verify_target()
constants = {
    0x00787d80: 0.8,
    0x00787d10: -0.45,
    0x00787d08: -0.1,
    0x00787d60: 0.032,
}
for address, expected in constants.items():
    actual = struct.unpack("<d", target_bytes(pe, address, 8))[0]
    assert actual == expected, (hex(address), actual, expected)

source = (ROOT / "workbench/character19-slot06/Character19Slot06Cases.cpp").read_text()
assert "Slot06UpdateRepeatedAirKnockback" not in source
fragment = (ROOT / "workbench/character19-slot06/Character19Slot06Case30.inc").read_text()
for expression in (
    "field0118 = field0118 - 0.8",
    "pendingContextSoundSlot = 0x1e;",
    "velocityY = -0.45;",
    "velocityX = -0.1;",
    "field3138 = field3138 + 1;",
    "meter = meter + 30;",
    "if ((field000a == 4) && (field000c == 0))",
    "velocityX = knockbackVelocityX;",
    "velocityY = knockbackVelocityY;",
    "gravity = 0.032;",
    "if ((velocityY > 0.0) && (field000a == 4))",
    "field000a = 5;",
    "if (field000a > 3)",
    "if ((field000a == 4) && (field3138 < 8))",
    "field3138 = field3138 + 1;",
    "field000a = field000a - 2;",
    "(positionY + velocityY) >= 0.0",
    "field000a > 4",
    "field0008 = 0x61;",
    "field0008 = 0x62;",
    "timing.frameDuration",
    "timing.animationFrameCount",
):
    assert expression in fragment, expression

dispatcher = (ROOT / "workbench/character19-slot06/Character19Slot06.cpp").read_text()
assert_selector_case(dispatcher, 82)
assert '#include "Character19Slot06Case30.inc"' in dispatcher
assert "Slot06UpdateRepeatedAirKnockback(" not in dispatcher

analog = (ROOT / "src/Character23State.cpp").read_text()
for expression in (
    "case 82:",
    "pendingContextSoundSlot = 0x1e;",
    "velocityY = -0.45;",
    "velocityX = -0.1;",
    "field3138 < 8",
    "(4 < field000a)",
):
    assert expression in analog, expression

print({
    "selector_case": "0x30",
    "native_bytes": 546,
    "state_id": 82,
    "repeat_limit": 8,
    "sound_request": 0x1e,
    "verified_constants": len(constants),
})
