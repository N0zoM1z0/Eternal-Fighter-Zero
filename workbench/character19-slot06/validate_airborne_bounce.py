"""Validate trail-assisted airborne bounce/recovery selectors 0x43 and 0x44."""
import csv
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
    if value in (0x43, 0x44):
        blocks[value] = lines[i:starts[n + 1][0]]
assert set(blocks) == {0x43, 0x44}

expected = {
    0x43: (412, 163, 3, 3, 2.0, -1.0, 0.02, 0.04, 1, 0),
    0x44: (317, 164, 2, 2, -2.0, -1.0, 0.035, 0.0, 0, 13),
}
case_rows = {
    int(row["case_index"], 16): row
    for row in csv.DictReader((ROOT / "workbench/character19-slot06/case-map.csv").open())
}
for case, values in expected.items():
    native_size, state, spacing, launch_frame, vx, vy, gravity, brake, loop7, landing_state = values
    row = case_rows[case]
    assert int(row["native_code_bytes"]) == native_size
    assert [int(x) for x in row["state_ids"].split(";") if x] == [state]
    block = "\n".join(blocks[case])
    for expression in (
        "FUN_004109d0();",
        "FUN_0040f1e0();",
        "*(undefined1 *)(param_1 + 0xb2) = 0;",
        "*(short *)(param_1 + 3) = (short)param_1[3] + 1;",
        "*(double *)(param_1 + 10) + *(double *)(param_1 + 0xe)",
    ):
        assert expression in block, (hex(case), expression)
    assert (
        "*(double *)(param_1 + 0xe) = _DAT_00787cb8;" in block
        or "*(undefined8 *)(param_1 + 0xe) = _DAT_00787cb8;" in block
    )
    if case == 0x43:
        for expression in (
            "*(double *)(param_1 + 0xc) = _DAT_00787328;",
            "*(double *)(param_1 + 0x12) = _DAT_00787d18;",
            "6 < *(ushort *)((int)param_1 + 10)",
            "*(double *)(param_1 + 0xc) = *(double *)(param_1 + 0xc) - _DAT_00787cf8",
            "*(short *)((int)param_1 + 10) == 7",
            "*(short *)((int)param_1 + 10) = *(short *)((int)param_1 + 10) + -2;",
            "*(undefined2 *)(param_1 + 2) = 0;",
        ):
            assert expression in block, (hex(case), expression)
    else:
        for expression in (
            "*(double *)(param_1 + 0xc) = _DAT_00787d70;",
            "*(undefined8 *)(param_1 + 0x12) = _DAT_00787dd8;",
            "*(short *)((int)param_1 + 10) = *(short *)((int)param_1 + 10) + -1;",
            "(**(code **)*param_1)();",
            "*(undefined2 *)(param_1 + 2) = 0xd;",
        ):
            assert expression in block, (hex(case), expression)
    print(
        f"case 0x{case:02x}: native={native_size}, state={state}, "
        f"trail={spacing}, launch-frame={launch_frame}, "
        f"vx={vx}, vy={vy}, gravity={gravity}, landing={landing_state}"
    )

sys.path.insert(0, str(ROOT / "scripts"))
from common import verify_target, target_bytes
pe = verify_target()
constants = {
    0x00787328: 2.0,
    0x00787cb8: -1.0,
    0x00787d18: 0.02,
    0x00787d70: -2.0,
    0x00787dd8: 0.035,
    0x00787cf8: 0.04,
}
for address, expected_value in constants.items():
    actual = struct.unpack("<d", target_bytes(pe, address, 8))[0]
    assert actual == expected_value, (hex(address), actual, expected_value)

source = (ROOT / "workbench/character19-slot06/Character19Slot06Cases.cpp").read_text()
assert "Slot06UpdateAirborneBounce" not in source
for case, values in expected.items():
    native_size, state, spacing, launch_frame, vx, vy, gravity, brake, loop7, landing_state = values
    fragment = (ROOT / f"workbench/character19-slot06/Character19Slot06Case{case:02X}.inc").read_text()
    for expression in (
        f"StartTrail({spacing});",
        "ResetFrame();",
        f"field000a == {launch_frame}",
        f"velocityX = {vx};",
        f"velocityY = {vy};",
        f"gravity = {gravity};",
        "pendingCharacterSoundSlot = 0;",
        "int continueAirborne = (positionY >= 0.0);",
        "velocityY = velocityY + gravity;",
        "positionY + velocityY <= 0.0",
        "field000c = field000c + 1;",
        "timing.frameDuration",
        "timing.animationFrameCount",
    ):
        assert expression in fragment, (hex(case), expression)
    if brake:
        assert f"velocityX = velocityX - {brake};" in fragment
    else:
        assert "velocityX = velocityX - " not in fragment
    if loop7:
        assert "if (field000a == 7)" in fragment
        assert "field000a = field000a - 2;" in fragment
    else:
        assert "field000a = field000a - 2;" not in fragment
    if landing_state == 0:
        assert "field0008 = 0;" in fragment
        assert "field000a = 7;" in fragment
        assert "field0008 = 13;" not in fragment
    else:
        assert "field0008 = 13;" in fragment
        assert "ResetPose();" in fragment
        assert "ResetFrame();" in fragment
        assert "field000a = 7;" not in fragment

# Native FUN_004109d0 is the trail begin wrapper, while FUN_0040f1e0 is
# Secondary::ResetFrame (zeroes all four motion fields and outgoing pushback).
trail = (ROOT / "src/SecondaryInput.cpp").read_text()
for expression in (
    "void Secondary::StartTrail(unsigned char spacing)",
    "trail.Begin(this, spacing);",
    "void SecondaryTrail::Begin(const SecondaryPose *pose, unsigned char spacing)",
    "for (int i = 0; i < 60; ++i)",
    "x[i] = pose->positionX;",
    "y[i] = pose->positionY;",
):
    assert expression in trail, expression
reset = (ROOT / "src/SecondaryState.cpp").read_text()
for expression in (
    "void Secondary::ResetFrame()",
    "velocityX = 0.0;",
    "velocityY = 0.0;",
    "horizontalDeceleration = 0.0;",
    "gravity = 0.0;",
    "outgoingPushbackVelocityX = 0.0;",
):
    assert expression in reset, expression

analog = (ROOT / "src/Character23State.cpp").read_text()
for expression in (
    "case 163:",
    "StartTrail(3);",
    "case 164:",
    "StartTrail(2);",
):
    assert expression in analog, expression

dispatcher = (ROOT / "workbench/character19-slot06/Character19Slot06.cpp").read_text()
for state in (163, 164):
    assert_selector_case(dispatcher, state)
assert "Slot06UpdateAirborneBounce(" not in dispatcher
print({"variants": 2, "verified_constants": len(constants), "state_ids": [163,164]})
