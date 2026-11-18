"""Validate Kanna's native airborne knockdown selectors 0x40-0x42."""
import csv
import re
import struct
import sys
from pathlib import Path

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
    if value in (0x40, 0x41, 0x42):
        blocks[value] = lines[i:starts[n + 1][0]]
assert set(blocks) == {0x40, 0x41, 0x42}

expected = {
    0x40: (272, 156, -1.2, -2.6, 0.06, 15, 0, 0, 0, 0),
    0x41: (342, 157, 1.0, -2.3, 0.045, 0, 8, 1, 1, 1),
    0x42: (342, 158, -1.0, -2.3, 0.045, 0, 8, 1, 1, 1),
}
case_rows = {
    int(row["case_index"], 16): row
    for row in csv.DictReader((ROOT / "workbench/character19-slot06/case-map.csv").open())
}
renderer = (ROOT / "workbench/character19-slot06/render_partial_slot06.py").read_text()
for case, values in expected.items():
    native_size, state, vx, vy, gravity, meter, effect, clear_dash, gravity_each, skip_first = values
    row = case_rows[case]
    assert int(row["native_code_bytes"]) == native_size, (hex(case), row)
    assert [int(x) for x in row["state_ids"].split(";") if x] == [state]
    config = (
        f"({hex(case)}, ({vx}, {vy}, {gravity}, {meter}, {effect}, "
        f"{clear_dash}, {gravity_each}, {skip_first}))"
    )
    assert config in renderer, (hex(case), config)

    block = "\n".join(blocks[case])
    for expression in (
        "*(short *)(param_1 + 3) = (short)param_1[3] + 1;",
        "*(undefined2 *)(param_1 + 2) = 9;",
        "*(undefined1 *)((int)param_1 + 0x2c9) = 9;",
        "FUN_0040e630();",
        "*(undefined2 *)(param_1 + 2) = 0xd;",
    ):
        assert expression in block, (hex(case), expression)

    if case == 0x40:
        for expression in (
            "*(undefined8 *)(param_1 + 0xe) = _DAT_00787cd0;",
            "*(short *)(param_1 + 0x52) = (short)param_1[0x52] + 0xf;",
            "*(double *)(param_1 + 0x12) = _DAT_00787da8;",
            "*(undefined8 *)(param_1 + 0xc) = _DAT_00787cc8;",
            "*(double *)(param_1 + 0xe) = *(double *)(param_1 + 0xe) + *(double *)(param_1 + 0x12);",
        ):
            assert expression in block, (hex(case), expression)
    else:
        for expression in (
            "*(undefined1 *)(param_1 + 0x56) = 0;",
            "local_50 = 8;",
            "FUN_007783b8()",
            "local_34 = 2;",
            "local_33 = 0;",
            "FUN_00407100();",
            "*(undefined8 *)(param_1 + 0x12) = _DAT_00787cc0;",
        ):
            assert expression in block, (hex(case), expression)
        if case == 0x41:
            assert "*(double *)(param_1 + 0xc) = _DAT_007875c0;" in block
        else:
            assert "*(undefined8 *)(param_1 + 0xc) = _DAT_00787cb8;" in block

    print(
        f"case 0x{case:02x}: native={native_size}, state={state}, "
        f"vx={vx}, vy={vy}, gravity={gravity}, effect={effect}"
    )

sys.path.insert(0, str(ROOT / "scripts"))
from common import verify_target, target_bytes
pe = verify_target()
constants = {
    0x00787cd0: -2.6,
    0x00787cc8: -1.2,
    0x00787cd8: -2.3,
    0x00787cc0: 0.045,
    0x00787cb8: -1.0,
    0x007875c0: 1.0,
    0x00787da8: 0.06,
}
for address, expected_value in constants.items():
    actual = struct.unpack("<d", target_bytes(pe, address, 8))[0]
    assert actual == expected_value, (hex(address), actual, expected_value)

source = (ROOT / "workbench/character19-slot06/Character19Slot06Cases.cpp").read_text()
for expression in (
    "void Character19::Slot06UpdateAirborneKnockdown",
    "velocityX = horizontalVelocity;",
    "if (clearDashMomentumFlag)",
    "dashMomentumFlag = 0;",
    "if (gravitySetEveryFrame)",
    "velocityY = initialVerticalVelocity;",
    "meter = meter + meterGain;",
    "spawn->type = (unsigned short)effectType;",
    "spawn->x = (double)(int)positionX;",
    "spawn->y = (double)(int)positionY;",
    "spawn->group = 2;",
    "spawn->layer = 0;",
    "contextOwner->EmitEffect(spawn);",
    "velocityY = velocityY + gravity;",
    "field0008 = 9;",
    "pendingContextSoundSlot = 9;",
    "FaceOpponent();",
    "field0008 = 0x0d;",
):
    assert expression in source, expression

context_emit = (ROOT / "src/EffectPool.cpp").read_text()
for expression in (
    "effects[field1380].type = spawn->type;",
    "effects[field1380].x = spawn->x;",
    "effects[field1380].y = spawn->y;",
    "effects[field1380].group = spawn->group;",
    "effects[field1380].layer = spawn->layer;",
    "AdvanceEffectWrite();",
):
    assert expression in context_emit, expression

analog = (ROOT / "src/Character23State.cpp").read_text()
for expression in (
    "case 156:",
    "velocityY = -2.6;",
    "meter = meter + 0xf;",
    "gravity = 0.06;",
    "velocityX = -1.2;",
    "case 157:",
    "velocityX = 1.0;",
    "velocityY = -2.3;",
    "gravity = 0.045;",
    "effect.type = 8;",
    "case 158:",
    "velocityX = -1.0;",
    "pendingContextSoundSlot = 9;",
):
    assert expression in analog, expression

dispatcher = (ROOT / "workbench/character19-slot06/Character19Slot06.cpp").read_text()
for state in (156, 157, 158):
    assert_selector_case(dispatcher, state)
print({"variants": 3, "verified_constants": len(constants), "state_ids": [156, 157, 158]})
