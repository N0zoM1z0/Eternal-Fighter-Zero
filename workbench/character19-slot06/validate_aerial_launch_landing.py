"""Validate the 454-byte multi-phase aerial launch selector 0x57."""
import csv
import re
import struct
import subprocess
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
    if value == 0x57:
        blocks[value] = lines[i:starts[n + 1][0]]
assert set(blocks) == {0x57}
block = "\n".join(blocks[0x57])

row = next(
    row for row in csv.DictReader((ROOT / "workbench/character19-slot06/case-map.csv").open())
    if int(row["case_index"], 16) == 0x57
)
assert row["native_entry"] == "0x00671F1E"
assert int(row["native_code_bytes"]) == 454
assert [int(x) for x in row["state_ids"].split(";") if x] == [210]

for expression in (
    "*(short *)((int)param_1 + 10) == 0",
    "((short)param_1[3] == 0)",
    "*(double *)(param_1 + 0xc) = _DAT_007872f8;",
    "*(double *)(param_1 + 0xe) = _DAT_007872f8;",
    "*(short *)((int)param_1 + 10) == 1",
    "*(undefined8 *)(param_1 + 0xc) = _DAT_00787f18;",
    "*(double *)(param_1 + 0xe) = _DAT_00787d98;",
    "*(double *)(param_1 + 0x12) = _DAT_007881d0;",
    "*(short *)((int)param_1 + 10) == 2",
    "*(short *)(param_1 + 0x52) = (short)param_1[0x52] + 0xf;",
    "*(undefined1 *)((int)param_1 + 0x2c9) = 0x14;",
    "*(undefined2 *)(param_1 + 0x5b) = 1;",
    "*(short *)((int)param_1 + 10) == 5",
    "*(double *)(param_1 + 0x12) = _DAT_007872f8;",
    "*(double *)(param_1 + 0xe) = *(double *)(param_1 + 0xe) + *(double *)(param_1 + 0x12);",
    "*(short *)(param_1 + 3) = (short)param_1[3] + 1;",
    "param_1[0x5a] = 0;",
    "*(short *)((int)param_1 + 10) == 5",
    "*(double *)(param_1 + 10) + *(double *)(param_1 + 0xe)",
    "*(short *)((int)param_1 + 10) = *(short *)((int)param_1 + 10) + -1;",
    "*(undefined2 *)(param_1 + 2) = 0;",
    "FUN_0040e630();",
):
    assert expression in block, expression

sys.path.insert(0, str(ROOT / "scripts"))
from common import verify_target, target_bytes
pe = verify_target()
constants = {
    0x00787F18: 1.4,
    0x00787D98: -1.5,
    0x007881D0: 0.08,
}
for address, expected in constants.items():
    actual = struct.unpack("<d", target_bytes(pe, address, 8))[0]
    assert actual == expected, (hex(address), actual, expected)

disasm = subprocess.run(
    [
        "objdump", "-D", "-Mintel",
        "--start-address=0x00671F1E",
        "--stop-address=0x006720E4",
        str(ROOT / "resources/EFZ.exe"),
    ],
    cwd=ROOT, check=True, capture_output=True, text=True,
).stdout
for expression in (
    "fld    QWORD PTR ds:0x787f18",
    "fld    QWORD PTR ds:0x787d98",
    "fld    QWORD PTR ds:0x7881d0",
    "call   0x40e630",
):
    assert expression in disasm, expression

source = (ROOT / "workbench/character19-slot06/Character19Slot06Cases.cpp").read_text()
start = source.index("void Character19::Slot06UpdateAerialLaunchLanding")
end = source.index("\n}\n", start) + 3
helper = source[start:end]
for expression in (
    "field000a == 0",
    "velocityX = 0.0;",
    "velocityY = 0.0;",
    "field000a == 1",
    "velocityX = 1.4;",
    "velocityY = -1.5;",
    "gravity = 0.08;",
    "field000a == 2",
    "meter = meter + 15;",
    "pendingContextSoundSlot = 0x14;",
    "remainingHitCount = 1;",
    "field000a == 5",
    "gravity = 0.0;",
    "if (field000a > 0)",
    "velocityY = velocityY + gravity;",
    "attackCollisionResult = 0;",
    "if (field000a == 5)",
    "(positionY + velocityY) < 0.0",
    "field000a = field000a - 1;",
    "positionY = 0.0;",
    "field0008 = 0;",
    "FaceOpponent();",
    "ResetPose();",
):
    assert expression in helper, expression

dispatcher = (ROOT / "workbench/character19-slot06/Character19Slot06.cpp").read_text()
assert_selector_case(dispatcher, 210)
assert "Slot06UpdateAerialLaunchLanding(" in dispatcher
print({"selector": "0x57", "native_bytes": 454, "state_id": 210, "launch": [1.4,-1.5], "gravity": 0.08, "meter": 15})
