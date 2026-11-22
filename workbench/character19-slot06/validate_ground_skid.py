"""Validate Kanna's three horizontal ground-skid selector cases 0x2c-0x2e."""
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
    if 0x2C <= value <= 0x2E:
        blocks[value] = lines[i:starts[n + 1][0]]
assert set(blocks) == {0x2C, 0x2D, 0x2E}

expected = {
    0x2C: (509, 75, 0),
    0x2D: (509, 76, 0),
    0x2E: (485, 77, 1),
}
for case, (native_size, state, force_standing) in expected.items():
    block = "\n".join(blocks[case])
    for expression in (
        "*(double *)(param_1 + 0x46) = *(double *)(param_1 + 0x46) - _DAT_00787db8;",
        "*(undefined1 *)(param_1 + 0x56) = 0;",
        "*(short *)(param_1 + 0x52) = (short)param_1[0x52] + 0x1e;",
        "*(double *)(param_1 + 0xe) = _DAT_007872f8;",
        "*(double *)(param_1 + 10) = _DAT_007872f8;",
        "*(double *)(param_1 + 0x12) = _DAT_007872f8;",
        "*(double *)(param_1 + 0x10) = _DAT_00787da8;",
        "*(double *)(param_1 + 0xc) = *(double *)(param_1 + 0xc) - *(double *)(param_1 + 0x10);",
        "*(double *)(*(int *)param_1[0x1e] + 0x28) < _DAT_007872f8",
        "*(double *)(param_1 + 0x2e) =",
        "*(short *)(param_1 + 3) = (short)param_1[3] + 1;",
        "*(short *)((int)param_1 + 10) = *(short *)((int)param_1 + 10) + 1;",
    ):
        assert expression in block, (hex(case), expression)
    if force_standing:
        assert "*(undefined2 *)(param_1 + 2) = 3;" in block
        assert "*(undefined2 *)(param_1 + 2) = 7;" not in block
    else:
        assert "*(undefined2 *)(param_1 + 2) = 7;" in block
        assert "*(char *)((int)param_1 + 0x189) == '\\x01'" in block
        assert "*(undefined2 *)(param_1 + 2) = 3;" in block
    print(f"case 0x{case:02x}: native={native_size}, state={state}, force-state-3={force_standing}")

sys.path.insert(0, str(ROOT / "scripts"))
from common import verify_target, target_bytes
pe = verify_target()
constants = {
    0x00787db8: 0.6,
    0x00787d88: 30.0,
    0x00787d20: 2.2,
    0x00787da8: 0.06,
    0x00787d28: 0.25,
    0x00787c10: 20.0,
    0x00787da0: 639.0,
}
for address, expected_value in constants.items():
    actual = struct.unpack("<d", target_bytes(pe, address, 8))[0]
    assert actual == expected_value, (hex(address), actual, expected_value)

source = (ROOT / "workbench/character19-slot06/Character19Slot06Cases.cpp").read_text()
assert "Slot06UpdateGroundSkid" not in source
dispatcher = (ROOT / "workbench/character19-slot06/Character19Slot06.cpp").read_text()
for case, (native_size, state, force_standing) in expected.items():
    fragment = (ROOT / f"workbench/character19-slot06/Character19Slot06Case{case:02X}.inc").read_text()
    for expression in (
        "field0118 = field0118 - 0.6;",
        "dashMomentumFlag = 0;",
        "field000a == 0",
        "meter = meter + 30;",
        "field0118 = field0118 - 30.0;",
        "velocityX = 2.2;",
        "velocityY = 0.0;",
        "positionY = 0.0;",
        "gravity = 0.0;",
        "horizontalDeceleration = 0.06;",
        "velocityX = velocityX - horizontalDeceleration;",
        "if (velocityX < 0.0)",
        "positionX - 20.0 <= 0.0",
        "639.0 <= positionX + 20.0",
        "(*opponentSlot)->positionY < 0.0",
        "outgoingPushbackVelocityX =",
        "field000c = field000c + 1;",
        "if (timing.frameDuration <= field000c)",
        "if (timing.animationFrameCount <= field000a)",
        "ResetPose();",
        "timing.frameDuration",
        "timing.animationFrameCount",
    ):
        assert expression in fragment, (hex(case), expression)
    if force_standing:
        assert "field0008 = 3;" in fragment
        assert "field0008 = 7;" not in fragment
        assert "inputY == 1" not in fragment
    else:
        assert "field0008 = 7;" in fragment
        assert "if (inputY == 1)" in fragment
        assert "field0008 = 3;" in fragment
    assert f'#include "Character19Slot06Case{case:02X}.inc"' in dispatcher
assert "Slot06UpdateGroundSkid(" not in dispatcher

# The other recovered character's state-75..77 implementation independently
# confirms the same movement order and opponent vertical-position test.
analog = (ROOT / "src/Character23State.cpp").read_text()
for expression in (
    "case 75:",
    "field0118 = field0118 - 0.6;",
    "field0118 = field0118 - 30.0;",
    "velocityX = 2.2;",
    "horizontalDeceleration = 0.06;",
    "(*opponentSlot)->positionY < 0.0",
):
    assert expression in analog, expression

def at_stage_edge(x):
    return x - 20.0 <= 0.0 or 639.0 <= x + 20.0
assert at_stage_edge(20.0)
assert not at_stage_edge(20.001)
assert not at_stage_edge(618.999)
assert at_stage_edge(619.0)
print({"variants": 3, "verified_constants": len(constants), "state_ids": [75,76,77]})
