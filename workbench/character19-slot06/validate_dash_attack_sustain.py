"""Validate Kanna's 435-byte sustained dash attack selector 0x53."""
import csv
import re
import struct
import sys
from pathlib import Path

from selector_support import assert_selector_case, selector_case_for_state

ROOT = Path(__file__).resolve().parents[2]
lines = (ROOT / ".analysis/kanna-slot06/native.c").read_text().splitlines()
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
    if value == 0x53:
        blocks[value] = lines[i:starts[n + 1][0]]
assert set(blocks) == {0x53}
block = "\n".join(blocks[0x53])

row = next(
    row for row in csv.DictReader((ROOT / "workbench/character19-slot06/case-map.csv").open())
    if int(row["case_index"], 16) == 0x53
)
assert row["native_entry"] == "0x0067148E"
assert int(row["native_code_bytes"]) == 435
assert [int(x) for x in row["state_ids"].split(";") if x] == [206]

for expression in (
    "((char)param_1[0x56] == '\\0')",
    "*(short *)((int)param_1 + 10) == 0",
    "((short)param_1[3] == 0)",
    "*(double *)(param_1 + 0xc) = _DAT_007872f8;",
    "*(double *)(param_1 + 0xe) = _DAT_007872f8;",
    "*(double *)(param_1 + 0xc) <= _DAT_007872f8",
    "((char)param_1[0x56] != '\\x01')",
    "2 < *(ushort *)((int)param_1 + 10)",
    "*(undefined1 *)(param_1 + 0x56) = 0;",
    "*(double *)(param_1 + 0xc) = *(double *)(param_1 + 0xc) - _DAT_00787ca0;",
    "*(double *)(param_1 + 0xc) < _DAT_007872f8",
    "*(undefined2 *)(param_1 + 0x5b) = 1;",
    "*(short *)((int)param_1 + 10) == 3",
    "param_1[0xc4e] == 0",
    "*(short *)(param_1 + 0x52) = (short)param_1[0x52] + 0x19;",
    "*(undefined1 *)((int)param_1 + 0x2c9) = 0x14;",
    "param_1[0xc4e] = param_1[0xc4e] + 1;",
    "*(short *)(param_1 + 3) = (short)param_1[3] + 1;",
    "param_1[0x5a] = 0;",
    "*(undefined2 *)(param_1 + 2) = 0;",
    "*(undefined2 *)(param_1 + 2) = 3;",
    "FUN_0040e630();",
):
    assert expression in block, expression
assert "*(char *)((int)param_1 + 0x189) == -1" not in block
assert "FUN_00407100();" not in block
assert "(**(code **)(*param_1 + 0x24))();" not in block

sys.path.insert(0, str(ROOT / "scripts"))
from common import verify_target, target_bytes
pe = verify_target()
actual = struct.unpack("<d", target_bytes(pe, 0x00787CA0, 8))[0]
assert actual == 0.03, actual

source = (ROOT / "workbench/character19-slot06/Character19Slot06Cases.cpp").read_text()
start = source.index("void Character19::Slot06UpdateDashAttackSustain")
end = source.index("\n}\n", start) + 3
helper = source[start:end]
for expression in (
    "if ((dashMomentumFlag == 0) && (field000a == 0) && (field000c == 0))",
    "velocityX = 0.0;",
    "velocityY = 0.0;",
    "(velocityX <= 0.0) || (dashMomentumFlag != 1) || (field000a > 2)",
    "dashMomentumFlag = 0;",
    "velocityX = velocityX - 0.03;",
    "if (velocityX < 0.0)",
    "remainingHitCount = 1;",
    "field000a == 3",
    "field3138 == 0",
    "meter = meter + 25;",
    "pendingContextSoundSlot = 0x14;",
    "field3138 = field3138 + 1;",
    "attackCollisionResult = 0;",
    "field0008 = 0;",
    "if (inputY == 1)",
    "field0008 = 3;",
    "FaceOpponent();",
    "ResetPose();",
):
    assert expression in helper, expression

dispatcher = (ROOT / "workbench/character19-slot06/Character19Slot06.cpp").read_text()
assert_selector_case(dispatcher, 206)
assert "Slot06UpdateDashAttackSustain(" in dispatcher
print({
    "selector": "0x53",
    "native_bytes": 435,
    "state_id": 206,
    "deceleration": actual,
    "meter_gain": 25,
    "one_shot_gate": "field3138==0",
})
