"""Validate the airborne dash-follow-up/cancel family selectors 0x54-0x56."""
import csv
import re
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
    if value in (0x54, 0x55, 0x56):
        blocks[value] = lines[i:starts[n + 1][0]]
assert set(blocks) == {0x54, 0x55, 0x56}

expected = {
    0x54: (675, 207, 0x00671641, 2, 5, 0x15, 0, 0, 3),
    0x55: (797, 208, 0x006718E4, 2, 13, 0x14, 3, 0x1A7, 4),
    0x56: (797, 209, 0x00671C01, 1, 30, 0x14, 1, 0x1A9, 3),
}
rows = {
    int(row["case_index"], 16): row
    for row in csv.DictReader((ROOT / "workbench/character19-slot06/case-map.csv").open())
}
for case, values in expected.items():
    native_size, state, entry, meter_frame, meter_gain, sound, effect_frame, effect_type, clear_frame = values
    row = rows[case]
    assert int(row["native_entry"], 16) == entry
    assert int(row["native_code_bytes"]) == native_size
    assert [int(x) for x in row["state_ids"].split(";") if x] == [state]
    block = "\n".join(blocks[case])
    for expression in (
        "*(double *)(param_1 + 0xe) = *(double *)(param_1 + 0xe) + *(double *)(param_1 + 0x12);",
        "*(char *)((int)param_1 + 0x189) == -1",
        "*(short *)((int)param_1 + 10) != 0",
        "param_1[0x57] < 3",
        "1 < param_1[0x5a]",
        "*(byte *)((int)param_1 + 0x15a) < 2",
        "*(undefined2 *)(param_1 + 2) = 0xe;",
        "*(undefined2 *)(param_1 + 2) = 0xf;",
        "*(undefined2 *)(param_1 + 2) = 0x10;",
        "*(char *)((int)param_1 + 0x189) == '\\0'",
        "param_1[0x5a] = 0;",
        "*(double *)(param_1 + 10) + *(double *)(param_1 + 0xe) < _DAT_007872f8",
        "*(undefined2 *)(param_1 + 2) = 0xd;",
        "*(short *)(param_1 + 3) = (short)param_1[3] + 1;",
        "*(undefined2 *)(param_1 + 2) = 9;",
    ):
        assert expression in block, (hex(case), expression)
    assert f"*(short *)((int)param_1 + 10) == {meter_frame}" in block
    meter_literal = str(meter_gain) if meter_gain < 10 else hex(meter_gain)
    assert f"*(short *)(param_1 + 0x52) = (short)param_1[0x52] + {meter_literal};" in block
    assert f"*(undefined1 *)((int)param_1 + 0x2c9) = {hex(sound)};" in block
    assert f"*(ushort *)((int)param_1 + 10) < {clear_frame}" in block
    assert "param_1[0xc4e]" not in block
    if effect_type:
        assert f"local_50 = {hex(effect_type)};" in block
        assert f"*(short *)((int)param_1 + 10) == {effect_frame}" in block
        for expression in (
            "local_54 = 1;",
            "local_34 = 2;",
            "local_33 = 1;",
            "local_3c = (char)param_1[0x14];",
            "(**(code **)(*param_1 + 0x24))();",
        ):
            assert expression in block, (hex(case), expression)
    else:
        assert "local_50 =" not in block
        assert "FUN_00407100();" not in block
    print(
        f"case 0x{case:02x}: native={native_size}, state={state}, "
        f"meter=+{meter_gain}@{meter_frame}, effect={hex(effect_type) if effect_type else 'none'}, "
        f"collision-clear-before={clear_frame}"
    )

# Confirm native effect coordinates are loaded from character X/Y and passed
# through the target's truncating x87-to-long helper.
def disassemble(start, end):
    return subprocess.run(
        ["objdump", "-D", "-Mintel", f"--start-address={start:#x}",
         f"--stop-address={end:#x}", str(ROOT / "resources/EFZ.exe")],
        cwd=ROOT, check=True, capture_output=True, text=True,
    ).stdout

for case, (start, end, effect_type) in {
    0x55: (0x006718E4, 0x00671C01, 0x1A7),
    0x56: (0x00671C01, 0x00671F1E, 0x1A9),
}.items():
    text = disassemble(start, end)
    for expression in (
        f"mov    WORD PTR [ebp-0x4c],0x{effect_type:x}",
        "fld    QWORD PTR [ecx+0x20]",
        "fld    QWORD PTR [edx+0x28]",
        "call   0x7783b8",
        "call   DWORD PTR [edx+0x24]",
    ):
        assert expression in text, (hex(case), expression)

source = (ROOT / "workbench/character19-slot06/Character19Slot06Cases.cpp").read_text()
start = source.index("void Character19::Slot06UpdateAirborneDashFollowup")
end = source.index("\n}\n", start) + 3
helper = source[start:end]
for expression in (
    "velocityY = velocityY + gravity;",
    "inputY == -1",
    "field000a > 0",
    "field015c < 3",
    "attackCollisionResult > 1",
    "airActionCount < 2",
    "airActionCount = airActionCount + 1;",
    "field0008 = 14;",
    "field0008 = 15;",
    "field0008 = 16;",
    "inputY == 0",
    "inputX != 0",
    "field0008 = 0xa5;",
    "field0008 = 0xa6;",
    "attackCollisionResult = 0;",
    "meter = meter + meterGain;",
    "pendingContextSoundSlot = (char)soundSlot;",
    "remainingHitCount = 1;",
    "spawn->owner = 1;",
    "spawn->type = effectType;",
    "spawn->x = (double)(int)positionX;",
    "spawn->y = (double)(int)positionY;",
    "spawn->flag0018 = (unsigned char)facing;",
    "spawn->group = 2;",
    "spawn->layer = 1;",
    "EmitLocalEffect(spawn);",
    "(positionY + velocityY) >= 0.0",
    "field0008 = 13;",
    "field000a < attackCollisionClearFrame",
    "field0008 = 9;",
    "ResetPose();",
):
    assert expression in helper, expression
assert "repeatFrame" not in helper
assert "repeatBack" not in helper
assert "repeatLimit" not in helper
assert "field3138" not in helper

renderer = (ROOT / "workbench/character19-slot06/render_partial_slot06.py").read_text()
assert "(0x54, (2, 5, 0x15, 0, 0, 3))" in renderer
assert "(0x55, (2, 13, 0x14, 3, 0x1a7, 4))" in renderer
assert "(0x56, (1, 30, 0x14, 1, 0x1a9, 3))" in renderer

dispatcher = (ROOT / "workbench/character19-slot06/Character19Slot06.cpp").read_text()
for state in (207, 208, 209):
    assert f"case {state}:" in dispatcher
assert dispatcher.count("Slot06UpdateAirborneDashFollowup(") == 3
print({"variants": 3, "state_ids": [207,208,209], "effect_types": [0x1A7,0x1A9]})
