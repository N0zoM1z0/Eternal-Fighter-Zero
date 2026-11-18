"""Validate Kanna's 488-byte defeat-impact selector 0x47 / state 167."""
import csv
import re
import struct
import sys
from pathlib import Path

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
    if value == 0x47:
        blocks[value] = lines[i:starts[n + 1][0]]
assert set(blocks) == {0x47}
block = "\n".join(blocks[0x47])

row = next(
    row for row in csv.DictReader((ROOT / "workbench/character19-slot06/case-map.csv").open())
    if int(row["case_index"], 16) == 0x47
)
assert row["native_entry"] == "0x0066FE60"
assert int(row["native_code_bytes"]) == 488
assert [int(x) for x in row["state_ids"].split(";") if x] == [167]

for expression in (
    "*(undefined1 *)(param_1 + 0x56) = 0;",
    "*(double *)(param_1 + 0xc) = _DAT_007872f8;",
    "*(double *)(param_1 + 0xe) = _DAT_007872f8;",
    "*(double *)(param_1 + 0x46) * _DAT_007872c0",
    "*(double *)(param_1 + 0x46) = _DAT_007872f8;",
    "*(undefined2 *)(param_1 + 0x53) = 0x5a;",
    "FUN_00410b10(0xb0,3);",
    "*(undefined1 *)((int)param_1 + 0x2c9) = 0x12;",
    "local_50 = 1;",
    "local_50 = 4;",
    "local_34 = 2;",
    "local_33 = 1;",
    "FUN_00407100();",
    "*(short *)(param_1 + 3) = (short)param_1[3] + 1;",
    "param_1[0x5a] = 0;",
    "*(undefined2 *)(param_1 + 2) = 0;",
    "FUN_0040e630();",
):
    assert expression in block, expression
assert block.count("FUN_00407100();") == 2

source = (ROOT / "workbench/character19-slot06/Character19Slot06Cases.cpp").read_text()
for expression in (
    "void Character19::Slot06UpdateDefeatImpactEffect",
    "dashMomentumFlag = 0;",
    "velocityX = 0.0;",
    "velocityY = 0.0;",
    "if (field0120 == 1)",
    "comboDamageScale = comboDamageScale + (field0118 * 5.0);",
    "field0118 = 0.0;",
    "hitstunFrames = 90;",
    "SetTint(0xb0, 3);",
    "field000a == 1",
    "pendingContextSoundSlot = 0x12;",
    "spawn->type = 1;",
    "spawn->group = 2;",
    "spawn->layer = 1;",
    "contextOwner->EmitEffect(spawn);",
    "field000a == 2",
    "spawn->type = 4;",
    "field000c = field000c + 1;",
    "attackCollisionResult = 0;",
    "field0008 = 0;",
    "FaceOpponent();",
    "ResetPose();",
):
    assert expression in source, expression

# FUN_00410b10 is the native tint setter and maps to Secondary::SetTint.
tint_helper = (ROOT / ".analysis/kanna-slot06/helpers/410b10.c").read_text()
for expression in (
    "param_1 + 0x30c0",
    "param_1 + 0x30c4",
    "*(int *)(param_1 + 0x30c4) / 2",
    "*(undefined1 *)(*(int *)(param_1 + 0x7c) + 0xf33)",
):
    assert expression in tint_helper, expression
set_tint = (ROOT / "src/SecondaryEffectControls.cpp").read_text()
for expression in (
    "void Secondary::SetTint(unsigned char value, int duration)",
    "field30c0 = value;",
    "field30c4 = duration;",
    "field30c4 = field30c4 / 2;",
    "contextOwner->field0f33 = player;",
):
    assert expression in set_tint, expression

context_emit = (ROOT / "src/EffectPool.cpp").read_text()
for expression in (
    "effects[field1380].type = spawn->type;",
    "effects[field1380].x = spawn->x;",
    "effects[field1380].y = spawn->y;",
    "effects[field1380].group = spawn->group;",
    "effects[field1380].layer = spawn->layer;",
    "AdvanceEffectWrite();",
):
    assert expression in context_emit, expression

analog = (ROOT / "src/Character23State.cpp").read_text()
for expression in (
    "case 167:",
    "comboDamageScale =",
    "field0118 * 5.0",
    "hitstunFrames = 0x5a;",
    "SetTint(0xb0,3);",
    "pendingContextSoundSlot = 0x12;",
    "effect.type = 1;",
    "effect.type = 4;",
    "FaceOpponent();",
):
    assert expression in analog, expression

sys.path.insert(0, str(ROOT / "scripts"))
from common import verify_target, target_bytes
pe = verify_target()
actual = struct.unpack("<d", target_bytes(pe, 0x007872c0, 8))[0]
assert actual == 5.0, actual

dispatcher = (ROOT / "workbench/character19-slot06/Character19Slot06.cpp").read_text()
assert "case 167:" in dispatcher
assert "Slot06UpdateDefeatImpactEffect(" in dispatcher
assert "case 167:" not in dispatcher[dispatcher.index("case 168:"):]
print({
    "selector": "0x47",
    "native_bytes": 488,
    "state_id": 167,
    "context_effects": [1, 4],
    "verified_combo_multiplier": actual,
})
