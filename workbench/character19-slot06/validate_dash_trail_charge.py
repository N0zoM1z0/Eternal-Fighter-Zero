"""Validate the 434-byte trail dash charge selector 0x60."""
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
    if v == 0x60:
        blocks[v] = lines[i:starts[n + 1][0]]
assert set(blocks) == {0x60}
block = "\n".join(blocks[0x60])

row = next(
    r for r in csv.DictReader((ROOT / "workbench/character19-slot06/case-map.csv").open())
    if int(r["case_index"], 16) == 0x60
)
assert row["native_entry"] == "0x00672C95"
assert int(row["native_code_bytes"]) == 434
assert [int(x) for x in row["state_ids"].split(";") if x] == [232]

for expression in (
    "FUN_004109d0();",
    "*(undefined1 *)(param_1 + 0x56) = 0;",
    "*(ushort *)((int)param_1 + 10) < 3",
    "*(double *)(param_1 + 0xc) = _DAT_007872f8;",
    "*(double *)(param_1 + 0xc) = *(double *)(param_1 + 0xc) - _DAT_00787da8;",
    "*(short *)((int)param_1 + 10) == 3",
    "((short)param_1[3] == 0)",
    "*(undefined1 *)((int)param_1 + 0x2c9) = 0x14;",
    "*(undefined8 *)(param_1 + 0xc) = _DAT_00787338;",
    "*(undefined2 *)(param_1 + 0x5b) = 1;",
    "*(short *)(param_1 + 0x52) = (short)param_1[0x52] + 0x23;",
    "(_DAT_007872f8 < *(double *)(param_1 + 0xc))",
    "*(double *)(param_1 + 0xc) = *(double *)(param_1 + 0xc) - (double)local_174 * _DAT_00788308;",
    "*(double *)(param_1 + 0xc) < _DAT_007872f8",
    "*(short *)(param_1 + 3) = (short)param_1[3] + 1;",
    "param_1[0x5a] = 0;",
    "*(undefined2 *)(param_1 + 2) = 0;",
):
    assert expression in block, expression

sys.path.insert(0, str(ROOT / "scripts"))
from common import verify_target, target_bytes
pe = verify_target()
for address, expected in (
    (0x00787DA8, 0.06),
    (0x00788308, 0.07),
    (0x00787338, 3.0),
):
    actual = struct.unpack("<d", target_bytes(pe, address, 8))[0]
    assert actual == expected, (hex(address), actual, expected)

source = (ROOT / "workbench/character19-slot06/Character19Slot06Cases.cpp").read_text()
start = source.index("void Character19::Slot06UpdateDashTrailCharge")
end = source.index("\n}\n", start) + 3
helper = source[start:end]
for expression in (
    "StartTrail(3);",
    "dashMomentumFlag = 0;",
    "if (field000a < 3)",
    "velocityX = 0.0;",
    "field000a == 3",
    "pendingContextSoundSlot = 0x14;",
    "velocityX = 3.0;",
    "remainingHitCount = 1;",
    "meter = meter + 35;",
    "if (velocityX > 0.0)",
    "velocityX = velocityX - 0.07;",
    "if (velocityX < 0.0)",
    "attackCollisionResult = 0;",
    "field0008 = 0;",
    "ResetPose();",
):
    assert expression in helper, expression
assert "FaceOpponent" not in helper
dispatcher = (ROOT / "workbench/character19-slot06/Character19Slot06.cpp").read_text()
assert_selector_case(dispatcher, 232) and "Slot06UpdateDashTrailCharge(" in dispatcher
print({"selector":"0x60","native_bytes":434,"state_id":232,"trail_spacing":3,"burst":3.0,"meter":35})
