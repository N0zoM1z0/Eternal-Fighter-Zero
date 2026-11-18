"""Validate paired type-8 knockback impact finishers 0x48 and 0x49."""
import csv
import re
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
    if value in (0x48, 0x49):
        blocks[value] = lines[i:starts[n + 1][0]]
assert set(blocks) == {0x48, 0x49}

def normalize(block):
    text = "\n".join(block)
    text = re.sub(r"case 0x[0-9a-f]+:", "case X:", text)
    text = re.sub(
        r"\*\(undefined2 \*\)\(param_1 \+ 2\) = (?:0|3);",
        "STATE;",
        text,
    )
    return text
assert normalize(blocks[0x48]) == normalize(blocks[0x49])

case_rows = {
    int(row["case_index"], 16): row
    for row in csv.DictReader((ROOT / "workbench/character19-slot06/case-map.csv").open())
}
renderer = (ROOT / "workbench/character19-slot06/render_partial_slot06.py").read_text()
for case, state, size, completion in ((0x48,168,330,0),(0x49,169,330,3)):
    row = case_rows[case]
    assert int(row["native_code_bytes"]) == size
    assert [int(x) for x in row["state_ids"].split(";") if x] == [state]
    assert f"({hex(case)}, {completion})" in renderer
    block = "\n".join(blocks[case])
    for expression in (
        "*(undefined1 *)(param_1 + 0x56) = 0;",
        "*(double *)(param_1 + 0xc) = _DAT_007872f8;",
        "*(double *)(param_1 + 0xe) = _DAT_007872f8;",
        "*(double *)(param_1 + 10) = _DAT_007872f8;",
        "*(double *)(param_1 + 0x12) = _DAT_007872f8;",
        "*(undefined2 *)((int)param_1 + 0x14e) = 0;",
        "*(double *)(param_1 + 0x2e) = _DAT_007872f8;",
        "*(double *)(param_1 + 0x10) = _DAT_007872f8;",
        "local_50 = 8;",
        "FUN_007783b8()",
        "local_34 = 2;",
        "local_33 = 1;",
        "FUN_00407100();",
        "FUN_0040e630();",
        "(**(code **)*param_1)();",
    ):
        assert expression in block, (hex(case), expression)
    if completion == 0:
        assert "*(undefined2 *)(param_1 + 2) = 0;" in block
    else:
        assert "*(undefined2 *)(param_1 + 2) = 3;" in block
    print(f"case 0x{case:02x}: native={size}, state={state}, effect=8, group=2, layer=1, completion={completion}")

source = (ROOT / "workbench/character19-slot06/Character19Slot06Cases.cpp").read_text()
for expression in (
    "void Character19::Slot06UpdateKnockbackImpactFinish",
    "dashMomentumFlag = 0;",
    "ResetFrame();",
    "positionY = 0.0;",
    "guardInputFrames = 0;",
    "spawn->type = 8;",
    "spawn->x = (double)(int)positionX;",
    "spawn->y = (double)(int)positionY;",
    "spawn->group = 2;",
    "spawn->layer = 1;",
    "contextOwner->EmitEffect(spawn);",
    "if (field000a == frameCount)",
    "FaceOpponent();",
    "field0008 = completionState;",
    "ResetPose();",
):
    assert expression in source, expression

reset = (ROOT / "src/SecondaryState.cpp").read_text()
for expression in (
    "void Secondary::ResetFrame()",
    "velocityX = 0.0;",
    "velocityY = 0.0;",
    "horizontalDeceleration = 0.0;",
    "gravity = 0.0;",
    "outgoingPushbackVelocityX = 0.0;",
):
    assert expression in reset, expression

effect_pool = (ROOT / "src/EffectPool.cpp").read_text()
for expression in (
    "effects[field1380].type = spawn->type;",
    "effects[field1380].group = spawn->group;",
    "effects[field1380].layer = spawn->layer;",
    "AdvanceEffectWrite();",
):
    assert expression in effect_pool, expression

analog = (ROOT / "src/Character23State.cpp").read_text()
for expression in (
    "case 168:",
    "effect.type = 8;",
    "effect.group = 2;",
    "effect.layer = 1;",
    "case 169:",
    "field0008 = 3;",
):
    assert expression in analog, expression

dispatcher = (ROOT / "workbench/character19-slot06/Character19Slot06.cpp").read_text()
assert "case 168:" in dispatcher and "case 169:" in dispatcher
print({"variants":2,"normalized_native_bodies_equal":True,"state_ids":[168,169]})
