"""Validate the 387-byte dash follow-up cancel selector 0x58."""
import csv
import re
import subprocess
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
    if value == 0x58:
        blocks[value] = lines[i:starts[n + 1][0]]
assert set(blocks) == {0x58}
block = "\n".join(blocks[0x58])

row = next(
    row for row in csv.DictReader((ROOT / "workbench/character19-slot06/case-map.csv").open())
    if int(row["case_index"], 16) == 0x58
)
assert row["native_entry"] == "0x006720E4"
assert int(row["native_code_bytes"]) == 387
assert [int(x) for x in row["state_ids"].split(";") if x] == [211]

for expression in (
    "*(char *)((int)param_1 + 0x189) == -1",
    "*(short *)((int)param_1 + 10) != 0",
    "param_1[0x57] < 3",
    "1 < param_1[0x5a]",
    "*(undefined2 *)(param_1 + 2) = 4;",
    "*(undefined2 *)(param_1 + 2) = 5;",
    "*(undefined2 *)(param_1 + 2) = 6;",
    "param_1[0x5a] = 0;",
    "*(short *)((int)param_1 + 10) == 0",
    "((short)param_1[3] == 0)",
    "*(double *)(param_1 + 0xc) = _DAT_007872f8;",
    "*(double *)(param_1 + 0xe) = _DAT_007872f8;",
    "*(short *)((int)param_1 + 10) == 3",
    "*(short *)(param_1 + 0x52) = (short)param_1[0x52] + 0x1e;",
    "*(undefined1 *)((int)param_1 + 0x2c9) = 0x14;",
    "*(undefined2 *)(param_1 + 0x5b) = 1;",
    "*(short *)(param_1 + 3) = (short)param_1[3] + 1;",
    "*(undefined2 *)(param_1 + 2) = 0;",
    "FUN_0040e630();",
):
    assert expression in block, expression
assert "FUN_00407100();" not in block
assert "*(double *)(param_1 + 0x12)" not in block

disasm = subprocess.run(
    [
        "objdump", "-D", "-Mintel",
        "--start-address=0x006720E4",
        "--stop-address=0x00672267",
        str(ROOT / "resources/EFZ.exe"),
    ],
    cwd=ROOT, check=True, capture_output=True, text=True,
).stdout
assert "call   0x40e630" in disasm
assert "mov    WORD PTR [edx+0x8],0x0" in disasm

source = (ROOT / "workbench/character19-slot06/Character19Slot06Cases.cpp").read_text()
start = source.index("void Character19::Slot06UpdateDashFollowupCancel")
end = source.index("\n}\n", start) + 3
helper = source[start:end]
for expression in (
    "inputY == -1",
    "field000a > 0",
    "field015c < 3",
    "attackCollisionResult > 1",
    "field0008 = 4;",
    "field0008 = 5;",
    "field0008 = 6;",
    "attackCollisionResult = 0;",
    "ResetPose();",
    "field000a == 0",
    "velocityX = 0.0;",
    "velocityY = 0.0;",
    "field000a == 3",
    "meter = meter + 30;",
    "pendingContextSoundSlot = 0x14;",
    "remainingHitCount = 1;",
    "field000c = field000c + 1;",
    "field0008 = 0;",
    "FaceOpponent();",
):
    assert expression in helper, expression
assert "gravity" not in helper
assert "positionY" not in helper

dispatcher = (ROOT / "workbench/character19-slot06/Character19Slot06.cpp").read_text()
assert_selector_case(dispatcher, 211)
assert "Slot06UpdateDashFollowupCancel(" in dispatcher
print({"selector": "0x58", "native_bytes": 387, "state_id": 211, "meter_gain": 30, "cancel_states": [4,5,6], "gravity_integration": False})
