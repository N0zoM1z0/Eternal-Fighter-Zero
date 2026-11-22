"""Validate the paired airborne rebound/slide states 0x31 and 0x32."""
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
    if value in (0x31, 0x32):
        blocks[value] = lines[i:starts[n + 1][0]]
assert set(blocks) == {0x31, 0x32}
assert len(blocks[0x31]) == len(blocks[0x32]) == 56

def normalize(block):
    text = "\n".join(block)
    text = re.sub(r"case 0x[0-9a-f]+:", "case X:", text)
    text = re.sub(r"local_[0-9a-f]+", "local_tmp", text)
    return text
assert normalize(blocks[0x31]) == normalize(blocks[0x32])

for case, state in ((0x31, 83), (0x32, 84)):
    block = "\n".join(blocks[case])
    for expression in (
        "param_1[0xc51] == 0",
        "local_50 = 0x1f0;",
        "local_34 = 0;",
        "local_33 = 0;",
        "local_54 = 1;",
        "local_3c = (char)param_1[0x14];",
        "(**(code **)(*param_1 + 0x24))();",
        "param_1[0xc51] = 1;",
        "*(double *)(param_1 + 0x46) = *(double *)(param_1 + 0x46) - _DAT_00787d88;",
        "*(undefined1 *)((int)param_1 + 0x2c9) = 0x21;",
        "*(double *)(param_1 + 0xe) = _DAT_00787d98;",
        "*(undefined8 *)(param_1 + 0xc) = _DAT_00787d00;",
        "*(short *)(param_1 + 0x52) = (short)param_1[0x52] + 0x1e;",
        "*(double *)(param_1 + 0xe) = *(double *)(param_1 + 0xe) + _DAT_00787cf8;",
        "*(double *)(param_1 + 0xc) = *(double *)(param_1 + 0xc) + _DAT_00787cf0;",
        "*(double *)(param_1 + 0xc) = _DAT_00787d70;",
        "*(double *)(param_1 + 0xc) = *(double *)(param_1 + 0xc) + _DAT_00787da8;",
        "*(undefined2 *)(param_1 + 2) = 0;",
        "FUN_0040e630();",
    ):
        assert expression in block, (hex(case), expression)
    print(f"case 0x{case:02x}: state={state}, bytes=581")

sys.path.insert(0, str(ROOT / "scripts"))
from common import verify_target, target_bytes
pe = verify_target()
constants = {
    0x00787d88: 30.0,
    0x00787d98: -1.5,
    0x00787d00: -0.8,
    0x00787cf8: 0.04,
    0x00787cf0: 0.01,
    0x00787d70: -2.0,
    0x00787da8: 0.06,
}
for address, expected in constants.items():
    actual = struct.unpack("<d", target_bytes(pe, address, 8))[0]
    assert actual == expected, (hex(address), actual, expected)

source = (ROOT / "workbench/character19-slot06/Character19Slot06Cases.cpp").read_text()
assert "Slot06UpdateAirborneRebound" not in source
for case in (0x31, 0x32):
    fragment = (ROOT / f"workbench/character19-slot06/Character19Slot06Case{case:02X}.inc").read_text()
    for expression in (
        "if (field3144 == 0)",
        "spawn.type = 0x1f0;",
        "spawn.owner = 1;",
        "spawn.group = 0;",
        "spawn.layer = 0;",
        "spawn.flag0018 = (unsigned char)facing;",
        "EmitLocalEffect(&spawn);",
        "field3144 = 1;",
        "field0118 = field0118 - 30.0",
        "pendingContextSoundSlot = 0x21;",
        "velocityY = -1.5;",
        "velocityX = -0.8;",
        "meter = meter + 30;",
        "velocityY = velocityY + 0.04;",
        "(positionY + velocityY) <= 0.0",
        "velocityX = velocityX + 0.01;",
        "velocityX = -2.0;",
        "velocityX = velocityX + 0.06;",
        "if (velocityX > 0.0)",
        "ResetPose();",
        "FaceOpponent();",
        "timing.frameDuration",
        "timing.animationFrameCount",
    ):
        assert expression in fragment, (hex(case), expression)
    assert f'#include "Character19Slot06Case{case:02X}.inc"' in (ROOT / "workbench/character19-slot06/Character19Slot06.cpp").read_text()

analog = (ROOT / "src/Character23State.cpp").read_text()
for expression in (
    "case 83:",
    "case 84:",
    "effect.type = 0x1f0;",
    "effect.owner = 1;",
    "pendingContextSoundSlot = 0x21;",
    "velocityY = -1.5;",
    "velocityX = -0.8;",
    "velocityX = velocityX + 0.01;",
    "velocityX = -2.0;",
    "velocityX = velocityX + 0.06;",
):
    assert expression in analog, expression

print({"native_bodies_identical": True, "verified_constants": len(constants), "state_ids": [83,84]})
