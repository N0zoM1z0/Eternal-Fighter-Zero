"""Validate the large paired airborne follow-up/counter handlers 0x45/0x46."""
import csv
import difflib
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
    if value in (0x45, 0x46):
        blocks[value] = lines[i:starts[n + 1][0]]
assert set(blocks) == {0x45, 0x46}
assert len(blocks[0x45]) == len(blocks[0x46]) == 88

def normalize(block):
    text = "\n".join(block)
    text = re.sub(r"case 0x[0-9a-f]+:", "case X:", text)
    text = re.sub(r"local_[0-9a-f]+", "local_tmp", text)
    text = text.replace("== 3)", "== LAUNCH)")
    text = text.replace("== 2)", "== LAUNCH)")
    text = text.replace("2 < *(ushort *)((int)param_1 + 10)", "LAUNCH_START")
    text = text.replace("1 < *(ushort *)((int)param_1 + 10)", "LAUNCH_START")
    text = text.replace("_DAT_00787328", "INITIAL_VX")
    text = text.replace("_DAT_00787d70", "INITIAL_VX")
    return text
assert normalize(blocks[0x45]) == normalize(blocks[0x46])

expected = {
    0x45: (932, 165, 3, 2.0),
    0x46: (931, 166, 2, -2.0),
}
case_rows = {
    int(row["case_index"], 16): row
    for row in csv.DictReader((ROOT / "workbench/character19-slot06/case-map.csv").open())
}
renderer = (ROOT / "workbench/character19-slot06/render_partial_slot06.py").read_text()
for case, (native_size, state, launch_frame, initial_vx) in expected.items():
    row = case_rows[case]
    assert int(row["native_code_bytes"]) == native_size
    assert [int(x) for x in row["state_ids"].split(";") if x] == [state]
    assert f"({hex(case)}, {launch_frame}, {initial_vx})" in renderer
    block = "\n".join(blocks[case])
    for expression in (
        "param_1[0xc50] = param_1[0xc50] + 1;",
        "param_1[0xc52] < param_1[0xc50]",
        "*(char *)((int)param_1 + 0x189) == -1",
        "param_1[0x57] < 3",
        "*(byte *)((int)param_1 + 0x15a) < 2",
        "*(undefined2 *)(param_1 + 2) = 0xe;",
        "*(undefined2 *)(param_1 + 2) = 0xf;",
        "*(undefined2 *)(param_1 + 2) = 0x10;",
        "*(undefined2 *)(param_1 + 2) = 9;",
        "*(undefined2 *)(param_1 + 2) = 0x12;",
        "*(undefined2 *)(param_1 + 2) = 0x14;",
        "*(undefined2 *)(param_1 + 2) = 0x11;",
        "*(undefined2 *)(param_1 + 2) = 0x13;",
        "*(undefined1 *)(param_1 + 0xb2) = 0;",
        "*(undefined2 *)(param_1 + 2) = 10;",
        "*(undefined1 *)((int)param_1 + 0x2c9) = 9;",
        "FUN_0040e630();",
        "*(undefined2 *)(param_1 + 2) = 0xd;",
    ):
        assert expression in block, (hex(case), expression)
    print(f"case 0x{case:02x}: native={native_size}, state={state}, launch={launch_frame}, vx={initial_vx}")

sys.path.insert(0, str(ROOT / "scripts"))
from common import verify_target, target_bytes
pe = verify_target()
constants = {
    0x00787cc0: 0.045,
    0x00787d68: -0.5,
    0x00787328: 2.0,
    0x00787d70: -2.0,
    0x00787cf0: 0.01,
}
for address, expected_value in constants.items():
    actual = struct.unpack("<d", target_bytes(pe, address, 8))[0]
    assert actual == expected_value, (hex(address), actual, expected_value)

source = (ROOT / "workbench/character19-slot06/Character19Slot06Cases.cpp").read_text()
for expression in (
    "void Character19::Slot06UpdateAirborneFollowup",
    "field000a == 0",
    "velocityX = 0.0;",
    "velocityY = 0.0;",
    "field3140 = field3140 + 1;",
    "field3148 < field3140",
    "inputY == -1",
    "field015c < 3",
    "airActionCount < 2",
    "field0008 = 14;",
    "field0008 = 15;",
    "field0008 = 16;",
    "inputY == 1",
    "field0008 = 9;",
    "field0008 = 18;",
    "field0008 = 20;",
    "field0008 = 17;",
    "field0008 = 19;",
    "attackCollisionResult = 0;",
    "field000a == launchFrame",
    "gravity = 0.045;",
    "velocityY = -0.5;",
    "velocityX = launchVelocityX;",
    "pendingCharacterSoundSlot = 0;",
    "field000a >= launchFrame",
    "velocityY = velocityY + 0.01;",
    "field0008 = 10;",
    "pendingContextSoundSlot = 9;",
    "FaceOpponent();",
    "field0008 = 0x0d;",
):
    assert expression in source, expression

dispatcher = (ROOT / "workbench/character19-slot06/Character19Slot06.cpp").read_text()
assert_selector_case(dispatcher, 165)
assert_selector_case(dispatcher, 166)
print({"native_variants": 2, "normalized_bodies_equal": True, "verified_constants": len(constants), "state_ids": [165,166]})
