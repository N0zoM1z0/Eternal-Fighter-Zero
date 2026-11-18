"""Validate the 483-byte airborne trail dash selector 0x63."""
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
    m = re.match(r"^\s*case\s+([^:]+):", line)
    if m:
        try:
            v = int(m.group(1), 0)
        except ValueError:
            continue
        starts.append((i, v))
blocks = {}
for n, (i, v) in enumerate(starts):
    if v == 0x63:
        blocks[v] = lines[i:starts[n + 1][0]]
assert set(blocks) == {0x63}
block = "\n".join(blocks[0x63])

row = next(
    r for r in csv.DictReader((ROOT / "workbench/character19-slot06/case-map.csv").open())
    if int(r["case_index"], 16) == 0x63
)
assert row["native_entry"] == "0x006730AD"
assert int(row["native_code_bytes"]) == 483
assert [int(x) for x in row["state_ids"].split(";") if x] == [235]

for expression in (
    "FUN_004109d0();",
    "*(undefined1 *)(param_1 + 0x56) = 0;",
    "*(ushort *)((int)param_1 + 10) < 3",
    "*(double *)(param_1 + 0xc) = _DAT_007872f8;",
    "2 < *(ushort *)((int)param_1 + 10)",
    "*(ushort *)((int)param_1 + 10) < 0xf",
    "*(double *)(param_1 + 0xe) = *(double *)(param_1 + 0xe) + *(double *)(param_1 + 0x12)",
    "_DAT_007872f8 < *(double *)(param_1 + 0xe) + *(double *)(param_1 + 10)",
    "FUN_0040f1e0();",
    "*(undefined2 *)((int)param_1 + 10) = 0xf;",
    "*(short *)((int)param_1 + 10) == 7",
    "*(undefined1 *)((int)param_1 + 0x2c9) = 0x14;",
    "*(short *)(param_1 + 0x52) = (short)param_1[0x52] + 0x23;",
    "*(double *)(param_1 + 0xc) = _DAT_00787d48;",
    "*(double *)(param_1 + 0xe) = _DAT_00787d98;",
    "*(undefined8 *)(param_1 + 0x12) = _DAT_00787d60;",
    "*(undefined2 *)(param_1 + 2) = 0;",
):
    assert expression in block, expression

sys.path.insert(0, str(ROOT / "scripts"))
from common import verify_target, target_bytes
pe = verify_target()
for address, expected in (
    (0x00787DA8, 0.06),
    (0x00787D48, 1.5),
    (0x00787D98, -1.5),
    (0x00787D60, 0.032),
):
    actual = struct.unpack("<d", target_bytes(pe, address, 8))[0]
    assert actual == expected, (hex(address), actual, expected)

source = (ROOT / "workbench/character19-slot06/Character19Slot06Cases.cpp").read_text()
start = source.index("void Character19::Slot06UpdateAirborneTrailDash")
end = source.index("\n}\n", start) + 3
helper = source[start:end]
for expression in (
    "StartTrail(3);",
    "dashMomentumFlag = 0;",
    "if (field000a < 3)",
    "velocityX = 0.0;",
    "(field000a > 2) && (field000a < 0xf)",
    "velocityY = velocityY + gravity;",
    "(positionY + velocityY) > 0.0",
    "field000c = 0;",
    "ResetFrame();",
    "positionY = 0.0;",
    "field000a = 0xf;",
    "field000a == 7",
    "pendingContextSoundSlot = 0x14;",
    "meter = meter + 35;",
    "field000a == 3",
    "velocityX = 1.5;",
    "velocityY = -1.5;",
    "gravity = 0.032;",
    "field0008 = 0;",
    "ResetPose();",
):
    assert expression in helper, expression
assert "FaceOpponent" not in helper
dispatcher = (ROOT / "workbench/character19-slot06/Character19Slot06.cpp").read_text()
assert_selector_case(dispatcher, 235)
assert "Slot06UpdateAirborneTrailDash(" in dispatcher
print({"selector":"0x63","native_bytes":483,"state_id":235,"launch":[1.5,-1.5],"gravity":0.032,"landing_frame":15})
