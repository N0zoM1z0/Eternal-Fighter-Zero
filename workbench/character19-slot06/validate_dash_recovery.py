"""Validate Kanna's 312-byte horizontal dash-recovery selector 0x4c."""
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
    if value == 0x4C:
        blocks[value] = lines[i:starts[n + 1][0]]
assert set(blocks) == {0x4C}
block = "\n".join(blocks[0x4C])

row = next(
    row for row in csv.DictReader((ROOT / "workbench/character19-slot06/case-map.csv").open())
    if int(row["case_index"], 16) == 0x4C
)
assert row["native_entry"] == "0x006706ED"
assert int(row["native_code_bytes"]) == 312
assert [int(x) for x in row["state_ids"].split(";") if x] == [178]

for expression in (
    "*(double *)(param_1 + 0xc) = *(double *)(param_1 + 0xc) - _DAT_00787ca0;",
    "if (*(double *)(param_1 + 0xc) < _DAT_007872f8)",
    "*(double *)(param_1 + 0xc) = _DAT_007872f8;",
    "*(undefined1 *)(param_1 + 0x56) = 0;",
    "*(char *)((int)param_1 + 0x189) == -1",
    "*(short *)((int)param_1 + 10) != 0",
    "param_1[0x57] < 3",
    "*(undefined2 *)(param_1 + 2) = 4;",
    "*(undefined2 *)(param_1 + 2) = 5;",
    "*(undefined2 *)(param_1 + 2) = 6;",
    "param_1[0x5a] = 0;",
    "*(short *)(param_1 + 3) = (short)param_1[3] + 1;",
    "*(undefined2 *)(param_1 + 2) = 0;",
):
    assert expression in block, expression
assert "FUN_0040e630();" not in block

sys.path.insert(0, str(ROOT / "scripts"))
from common import verify_target, target_bytes
pe = verify_target()
actual = struct.unpack("<d", target_bytes(pe, 0x00787ca0, 8))[0]
assert actual == 0.03, actual

source = (ROOT / "workbench/character19-slot06/Character19Slot06Cases.cpp").read_text()
start = source.index("void Character19::Slot06UpdateDashRecovery")
end = source.index("\n}\n", start) + 3
helper = source[start:end]
for expression in (
    "velocityX = velocityX - 0.03;",
    "if (velocityX < 0.0)",
    "velocityX = 0.0;",
    "dashMomentumFlag = 0;",
    "inputY == -1",
    "field000a != 0",
    "field015c < 3",
    "field0008 = 4;",
    "field0008 = 5;",
    "field0008 = 6;",
    "attackCollisionResult = 0;",
    "ResetPose();",
    "field000c = field000c + 1;",
    "field0008 = 0;",
):
    assert expression in helper, expression

analog = (ROOT / "src/Character15State.cpp").read_text()
assert "case 178:" in analog
assert "velocityX = velocityX - 0.03;" in analog
assert "dashMomentumFlag = 0;" in analog

dispatcher = (ROOT / "workbench/character19-slot06/Character19Slot06.cpp").read_text()
assert_selector_case(dispatcher, 178)
assert "Slot06UpdateDashRecovery(" in dispatcher
print({"selector": "0x4C", "native_bytes": 312, "state_id": 178, "deceleration": actual, "cancel_states": [4,5,6]})
