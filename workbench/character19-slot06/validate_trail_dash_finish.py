"""Validate trail-backed dash finish selectors 0x5e and 0x5f."""
import csv
import re
import struct
import subprocess
import sys
from pathlib import Path

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
    if value in (0x5E, 0x5F):
        blocks[value] = lines[i:starts[n + 1][0]]
assert set(blocks) == {0x5E, 0x5F}

expected = {
    0x5E: (307, 230, 0x00672A2F, 5, 0x15, 0),
    0x5F: (307, 231, 0x00672B62, 10, 0x14, 1),
}
rows = {
    int(row["case_index"], 16): row
    for row in csv.DictReader((ROOT / "workbench/character19-slot06/case-map.csv").open())
}
for case, (size, state, entry, meter_gain, sound, reverse_init_order) in expected.items():
    row = rows[case]
    assert int(row["native_entry"], 16) == entry
    assert int(row["native_code_bytes"]) == size
    assert [int(x) for x in row["state_ids"].split(";") if x] == [state]
    block = "\n".join(blocks[case])
    for expression in (
        "FUN_004109d0();",
        "*(undefined1 *)(param_1 + 0x56) = 0;",
        "*(double *)(param_1 + 0xc) = *(double *)(param_1 + 0xc) - _DAT_00787ca0;",
        "*(double *)(param_1 + 0xc) < _DAT_007872f8",
        "*(double *)(param_1 + 0xc) = _DAT_007872f8;",
        "*(short *)((int)param_1 + 10) == 0",
        "((short)param_1[3] == 0)",
        "*(double *)(param_1 + 0xc) = _DAT_00787328;",
        "*(double *)(param_1 + 0xe) = _DAT_007872f8;",
        "*(short *)((int)param_1 + 10) == 2",
        f"*(short *)(param_1 + 0x52) = (short)param_1[0x52] + {meter_gain};",
        f"*(undefined1 *)((int)param_1 + 0x2c9) = {hex(sound)};",
        "*(undefined2 *)(param_1 + 0x5b) = 1;",
        "*(short *)(param_1 + 3) = (short)param_1[3] + 1;",
        "param_1[0x5a] = 0;",
        "*(undefined2 *)(param_1 + 2) = 0;",
    ):
        assert expression in block, (hex(case), expression)
    assert "*(undefined2 *)(param_1 + 2) = 3;" not in block

# Native FUN_004109d0(3) is the wrapper for Secondary::StartTrail(3).
wrapper = (ROOT / ".analysis/kanna-slot06/helpers/4109d0.c").read_text()
assert "FUN_00412a10(local_c,param_2);" in wrapper
trail = (ROOT / "src/SecondaryInput.cpp").read_text()
for expression in (
    "void Secondary::StartTrail(unsigned char spacing)",
    "trail.Begin(this, spacing);",
    "void SecondaryTrail::Begin(const SecondaryPose *pose, unsigned char spacing)",
    "if (pending == 0 && held == 0)",
    "x[i] = pose->positionX;",
    "y[i] = pose->positionY;",
    "facing[i] = pose->facing;",
    "type[i] = pose->field0008;",
    "frame[i] = pose->field000a;",
    "pending = spacing;",
    "stride = spacing;",
):
    assert expression in trail, expression

sys.path.insert(0, str(ROOT / "scripts"))
from common import verify_target, target_bytes
pe = verify_target()
for address, expected_value in ((0x00787CA0, 0.03), (0x00787328, 2.0)):
    actual = struct.unpack("<d", target_bytes(pe, address, 8))[0]
    assert actual == expected_value, (hex(address), actual, expected_value)

disasm = subprocess.run(
    [
        "objdump", "-D", "-Mintel",
        "--start-address=0x00672A2F",
        "--stop-address=0x00672C95",
        str(ROOT / "resources/EFZ.exe"),
    ],
    cwd=ROOT, check=True, capture_output=True, text=True,
).stdout
for expression in (
    "push   0x3",
    "call   0x4109d0",
    "fsub   QWORD PTR ds:0x787ca0",
    "fld    QWORD PTR ds:0x787328",
    "mov    BYTE PTR [eax+0x158],0x0",
):
    assert expression in disasm, expression

source = (ROOT / "workbench/character19-slot06/Character19Slot06Cases.cpp").read_text()
start = source.index("void Character19::Slot06UpdateTrailDashFinish")
end = source.index("\n}\n", start) + 3
helper = source[start:end]
for expression in (
    "StartTrail(3);",
    "dashMomentumFlag = 0;",
    "velocityX = velocityX - 0.03;",
    "if (velocityX < 0.0)",
    "velocityX = 0.0;",
    "field000a == 0",
    "velocityX = 2.0;",
    "velocityY = 0.0;",
    "field000a == 2",
    "meter = meter + meterGain;",
    "pendingContextSoundSlot = (char)soundSlot;",
    "remainingHitCount = 1;",
    "attackCollisionResult = 0;",
    "field0008 = 0;",
    "ResetPose();",
):
    assert expression in helper, expression
assert "FaceOpponent" not in helper

renderer = (ROOT / "workbench/character19-slot06/render_partial_slot06.py").read_text()
assert "(0x5e, (5, 0x15))" in renderer
assert "(0x5f, (10, 0x14))" in renderer
dispatcher = (ROOT / "workbench/character19-slot06/Character19Slot06.cpp").read_text()
assert "case 230:" in dispatcher and "Slot06UpdateTrailDashFinish(" in dispatcher
assert "case 231:" in dispatcher and "Slot06UpdateTrailDashFinish(" in dispatcher
print({"variants": 2, "native_bytes": [307,307], "state_ids": [230,231], "trail_spacing": 3, "meter": [5,10]})
