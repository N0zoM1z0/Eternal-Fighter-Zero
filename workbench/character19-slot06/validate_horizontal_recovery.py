"""Validate the paired horizontal recovery selectors 0x3a and 0x3b."""
import re
import struct
import sys
from pathlib import Path

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
    if value in (0x3A, 0x3B):
        blocks[value] = lines[i:starts[n + 1][0]]
assert set(blocks) == {0x3A, 0x3B}

def normalize(block):
    text = "\n".join(block)
    text = re.sub(r"case 0x[0-9a-f]+:", "case X:", text)
    text = text.replace("_DAT_00787d98", "_INITIAL_VX_")
    text = text.replace("_DAT_00787d90", "_INITIAL_VX_")
    text = re.sub(r"\+ (?:10|0xf);", "+ METER_GAIN;", text)
    return text
assert normalize(blocks[0x3A]) == normalize(blocks[0x3B])

expected = {
    0x3A: (380,150,10,-1.5),
    0x3B: (380,151,15,-1.8),
}
renderer = (ROOT / "workbench/character19-slot06/render_partial_slot06.py").read_text()
for case,(native_size,state,meter_gain,initial_velocity) in expected.items():
    block = "\n".join(blocks[case])
    assert f"(0x{case:02x}, {meter_gain}, {initial_velocity})" in renderer
    for expression in (
        "*(undefined1 *)(param_1 + 0x56) = 0;",
        "*(short *)(param_1 + 0x52) = (short)param_1[0x52] +",
        "*(double *)(param_1 + 0xe) = _DAT_007872f8;",
        "*(double *)(param_1 + 10) = _DAT_007872f8;",
        "*(double *)(param_1 + 0xc) = *(double *)(param_1 + 0xc) + _DAT_00787da8;",
        "if (_DAT_007872f8 < *(double *)(param_1 + 0xc))",
        "*(undefined8 *)(param_1 + 0x2e) = *(undefined8 *)(param_1 + 0xc);",
        "*(double *)(param_1 + 0x2e) = _DAT_007872f8;",
        "*(short *)(param_1 + 3) = (short)param_1[3] + 1;",
        "FUN_0040e630();",
        "*(undefined2 *)(param_1 + 2) = 0;",
        "*(char *)((int)param_1 + 0x189) == '\\x01'",
        "*(undefined2 *)(param_1 + 2) = 3;",
    ):
        assert expression in block,(hex(case),expression)
    print(f"case 0x{case:02x}: native={native_size}, state={state}, meter=+{meter_gain}, initial-vx={initial_velocity}")

sys.path.insert(0,str(ROOT/"scripts"))
from common import verify_target,target_bytes
pe=verify_target()
constants={0x00787d98:-1.5,0x00787d90:-1.8,0x00787da8:0.06,0x00787c10:20.0,0x00787da0:639.0}
for address,expected_value in constants.items():
    actual=struct.unpack("<d",target_bytes(pe,address,8))[0]
    assert actual==expected_value,(hex(address),actual,expected_value)

source=(ROOT/"workbench/character19-slot06/Character19Slot06Cases.cpp").read_text()
for expression in (
    "void Character19::Slot06UpdateHorizontalRecovery",
    "dashMomentumFlag = 0;",
    "meter = meter + meterGain;",
    "velocityX = initialVelocityX;",
    "velocityY = 0.0;",
    "positionY = 0.0;",
    "velocityX = velocityX + 0.06;",
    "if (velocityX > 0.0)",
    "positionX - 20.0 <= 0.0",
    "639.0 <= positionX + 20.0",
    "outgoingPushbackVelocityX = velocityX;",
    "if (field000a == frameCount)",
    "field0008 = 0;",
    "if (inputY == 1)",
    "field0008 = 3;",
):
    assert expression in source,expression

analog=(ROOT/"src/Character23State.cpp").read_text()
for expression in (
    "case 150:",
    "meter = meter + 10;",
    "velocityX = -1.5;",
    "case 151:",
    "meter = meter + 0xf;",
    "velocityX = -1.8;",
    "velocityX = velocityX + 0.06;",
    "outgoingPushbackVelocityX = velocityX;",
):
    assert expression in analog,expression

print({"native_bodies_normalized_identical":True,"verified_constants":len(constants),"state_ids":[150,151]})
