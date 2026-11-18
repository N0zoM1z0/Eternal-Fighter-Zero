"""Validate Kanna's four native horizontal-recovery selectors 0x3a-0x3d."""
import csv
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
    if 0x3A <= value <= 0x3D:
        blocks[value] = lines[i:starts[n + 1][0]]
assert set(blocks) == {0x3A, 0x3B, 0x3C, 0x3D}

expected = {
    0x3A: (380, 150, 10, -1.5, "_DAT_00787d98", False),
    0x3B: (380, 151, 15, -1.8, "_DAT_00787d90", False),
    0x3C: (380, 152, 20, -2.3, "_DAT_00787cd8", False),
    0x3D: (356, 153, 10, -1.5, "_DAT_00787d98", True),
}
case_rows = {
    int(row["case_index"], 16): row
    for row in csv.DictReader((ROOT / "workbench/character19-slot06/case-map.csv").open())
}
renderer = (ROOT / "workbench/character19-slot06/render_partial_slot06.py").read_text()
for case, (native_size, state, meter_gain, initial_velocity, constant_name, force_standing) in expected.items():
    row = case_rows[case]
    assert int(row["native_code_bytes"]) == native_size, (hex(case), row)
    assert [int(x) for x in row["state_ids"].split(";") if x] == [state]
    assert f"(0x{case:02x}, {meter_gain}, {initial_velocity}, {int(force_standing)})" in renderer

    block = "\n".join(blocks[case])
    for expression in (
        "*(undefined1 *)(param_1 + 0x56) = 0;",
        "*(double *)(param_1 + 0xe) = _DAT_007872f8;",
        "*(double *)(param_1 + 10) = _DAT_007872f8;",
        "*(double *)(param_1 + 0xc) = *(double *)(param_1 + 0xc) + _DAT_00787da8;",
        "if (_DAT_007872f8 < *(double *)(param_1 + 0xc))",
        "*(double *)(param_1 + 0xc) = _DAT_007872f8;",
        "*(undefined8 *)(param_1 + 0x2e) = *(undefined8 *)(param_1 + 0xc);",
        "*(double *)(param_1 + 0x2e) = _DAT_007872f8;",
        "*(short *)(param_1 + 3) = (short)param_1[3] + 1;",
        "FUN_0040e630();",
    ):
        assert expression in block, (hex(case), expression)

    assert f"*(short *)(param_1 + 0x52) = (short)param_1[0x52] + {('10' if meter_gain == 10 else hex(meter_gain))};" in block
    assert (
        f"*(double *)(param_1 + 0xc) = {constant_name};" in block
        or f"*(undefined8 *)(param_1 + 0xc) = {constant_name};" in block
    )
    assert "*(double *)(param_1 + 0xc) = _DAT_007872f8;" in block
    assert "*(double *)(param_1 + 0x2e) = _DAT_007872f8;" in block
    assert "*(double *)(param_1 + 0xc) = *(double *)(param_1 + 0xc) + _DAT_00787da8;" in block
    assert "639.0" not in block  # native uses the verified constant at 0x787da0

    if force_standing:
        assert "*(undefined2 *)(param_1 + 2) = 3;" in block
        assert "*(char *)((int)param_1 + 0x189)" not in block
    else:
        assert "*(undefined2 *)(param_1 + 2) = 0;" in block
        assert "*(char *)((int)param_1 + 0x189) == '\\x01'" in block
        assert "*(undefined2 *)(param_1 + 2) = 3;" in block

    print(
        f"case 0x{case:02x}: native={native_size}, state={state}, "
        f"meter=+{meter_gain}, initial-vx={initial_velocity}, "
        f"force-standing={force_standing}"
    )

sys.path.insert(0, str(ROOT / "scripts"))
from common import verify_target, target_bytes
pe = verify_target()
constants = {
    0x00787d98: -1.5,
    0x00787d90: -1.8,
    0x00787cd8: -2.3,
    0x00787da8: 0.06,
    0x00787c10: 20.0,
    0x00787da0: 639.0,
}
for address, expected_value in constants.items():
    actual = struct.unpack("<d", target_bytes(pe, address, 8))[0]
    assert actual == expected_value, (hex(address), actual, expected_value)

source = (ROOT / "workbench/character19-slot06/Character19Slot06Cases.cpp").read_text()
for expression in (
    "void Character19::Slot06UpdateHorizontalRecovery",
    "short meterGain",
    "double initialVelocityX",
    "int forceStandingState",
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
    "FaceOpponent();",
    "forceStandingState || (inputY == 1)",
    "field0008 = 3;",
):
    assert expression in source, expression

# FUN_0040e630 compares the two X coordinates and writes facing; this is
# precisely the existing FaceOpponent implementation, including equal-X no-op.
facing_helper = (ROOT / ".analysis/kanna-slot06/helpers/40e630.c").read_text()
for expression in (
    "*(double *)(**(int **)(param_1 + 0x78) + 0x20)",
    "*(double *)(param_1 + 0x20)",
    "*(undefined1 *)(param_1 + 0x50) = 0xff;",
    "*(undefined1 *)(param_1 + 0x50) = 1;",
):
    assert expression in facing_helper, expression
facing_source = (ROOT / "src/SecondaryFacing.cpp").read_text()
for expression in (
    "if (positionX < (*opponentSlot)->positionX)",
    "facing = 1;",
    "if (positionX > (*opponentSlot)->positionX)",
    "facing = -1;",
):
    assert expression in facing_source, expression

# Character23's independently reconstructed states 150-153 confirm all four
# launch/meter values and the common 0.06 braking / edge-pushback sequence.
analog = (ROOT / "src/Character23State.cpp").read_text()
for expression in (
    "case 150:",
    "meter = meter + 10;",
    "velocityX = -1.5;",
    "case 151:",
    "meter = meter + 0xf;",
    "velocityX = -1.8;",
    "case 152:",
    "meter = meter + 0x14;",
    "velocityX = -2.3;",
    "case 153:",
    "velocityX = velocityX + 0.06;",
    "outgoingPushbackVelocityX = velocityX;",
):
    assert expression in analog, expression

def at_stage_edge(x):
    return x - 20.0 <= 0.0 or 639.0 <= x + 20.0
assert at_stage_edge(20.0)
assert not at_stage_edge(20.001)
assert not at_stage_edge(618.999)
assert at_stage_edge(619.0)

dispatcher = (ROOT / "workbench/character19-slot06/Character19Slot06.cpp").read_text()
for state in (150, 151, 152, 153):
    assert f"case {state}:" in dispatcher

print({
    "native_bodies": 4,
    "verified_constants": len(constants),
    "stage_edge_boundary_probes": 4,
    "state_ids": [150, 151, 152, 153],
})
