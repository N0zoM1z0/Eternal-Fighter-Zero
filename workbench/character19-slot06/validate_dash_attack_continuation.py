"""Validate the 611-byte extended dash follow-through selector 0x52."""
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
    if value == 0x52:
        blocks[value] = lines[i:starts[n + 1][0]]
assert set(blocks) == {0x52}
block = "\n".join(blocks[0x52])

row = next(
    row for row in csv.DictReader((ROOT / "workbench/character19-slot06/case-map.csv").open())
    if int(row["case_index"], 16) == 0x52
)
assert row["native_entry"] == "0x0067122B"
assert int(row["native_code_bytes"]) == 611
assert [int(x) for x in row["state_ids"].split(";") if x] == [205]

for expression in (
    "if ((char)param_1[0x56] == '\\0')",
    "*(double *)(param_1 + 0xc) = _DAT_007872f8;",
    "*(double *)(param_1 + 0xe) = _DAT_007872f8;",
    "*(double *)(param_1 + 0xc) = *(double *)(param_1 + 0xc) - _DAT_00787ca0;",
    "*(undefined1 *)(param_1 + 0x56) = 0;",
    "*(char *)((int)param_1 + 0x189) == -1",
    "param_1[0x57] < 3",
    "1 < param_1[0x5a]",
    "*(undefined2 *)(param_1 + 2) = 4;",
    "*(undefined2 *)(param_1 + 2) = 5;",
    "*(undefined2 *)(param_1 + 2) = 6;",
    "param_1[0x5a] = 0;",
    "*(short *)(param_1 + 0x52) = (short)param_1[0x52] + 0xd;",
    "*(undefined1 *)((int)param_1 + 0x2c9) = 0x14;",
    "*(undefined2 *)(param_1 + 0x5b) = 1;",
    "local_50 = 0x1a6;",
    "local_34 = 2;",
    "local_33 = 1;",
    "local_54 = 1;",
    "local_3c = (char)param_1[0x14];",
    "(**(code **)(*param_1 + 0x24))();",
    "*(short *)(param_1 + 3) = (short)param_1[3] + 1;",
    "*(undefined2 *)(param_1 + 2) = 0;",
    "*(undefined2 *)(param_1 + 2) = 3;",
    "FUN_0040e630();",
):
    assert expression in block, expression

# Machine code confirms the effect uses integer-truncated current position,
# not random coordinates or a fixed screen location.
disasm = subprocess.run(
    [
        "objdump", "-D", "-Mintel",
        "--start-address=0x0067122B",
        "--stop-address=0x0067148E",
        str(ROOT / "resources/EFZ.exe"),
    ],
    cwd=ROOT,
    check=True,
    capture_output=True,
    text=True,
).stdout
for expression in (
    "fld    QWORD PTR [ecx+0x20]",
    "fld    QWORD PTR [edx+0x28]",
    "call   0x7783b8",
    "mov    WORD PTR [ebp-0x4c],0x1a6",
    "mov    BYTE PTR [ebp-0x30],0x2",
    "mov    BYTE PTR [ebp-0x2f],0x1",
    "mov    DWORD PTR [ebp-0x50],0x1",
    "call   DWORD PTR [edx+0x24]",
):
    assert expression in disasm, expression

sys.path.insert(0, str(ROOT / "scripts"))
from common import verify_target, target_bytes
pe = verify_target()
actual = struct.unpack("<d", target_bytes(pe, 0x00787CA0, 8))[0]
assert actual == 0.03, actual

renderer = (ROOT / "workbench/character19-slot06/render_partial_slot06.py").read_text()
assert "(0x52, (0.03, 1, 2, 13, 0x14, 1, 0x1a6, 0, 1))" in renderer
dispatcher = (ROOT / "workbench/character19-slot06/Character19Slot06.cpp").read_text()
assert_selector_case(dispatcher, 205)
assert "Slot06UpdateDashAttack(" in dispatcher
print({
    "selector": "0x52",
    "native_bytes": 611,
    "state_id": 205,
    "deceleration": actual,
    "meter_gain": 13,
    "effect_type": "0x1a6",
    "effect_frame": 1,
})
