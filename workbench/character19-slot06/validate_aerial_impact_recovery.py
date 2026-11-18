"""Validate Kanna's aerial slam, kickback and ground-impact selectors 0x59-0x5b."""
import csv
import re
import struct
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
    if 0x59 <= value <= 0x5B:
        blocks[value] = lines[i:starts[n + 1][0]]
assert set(blocks) == {0x59, 0x5A, 0x5B}

expected = {
    0x59: (443, 212, 0x00672267),
    0x5A: (188, 213, 0x00672422),
    0x5B: (287, 214, 0x006724DE),
}
rows = {
    int(row["case_index"], 16): row
    for row in csv.DictReader((ROOT / "workbench/character19-slot06/case-map.csv").open())
}
for case, (native_size, state, entry) in expected.items():
    row = rows[case]
    assert int(row["native_entry"], 16) == entry
    assert int(row["native_code_bytes"]) == native_size
    assert [int(x) for x in row["state_ids"].split(";") if x] == [state]

slam = "\n".join(blocks[0x59])
for expression in (
    "*(double *)(param_1 + 0xe) = *(double *)(param_1 + 0xe) + *(double *)(param_1 + 0x12);",
    "*(short *)((int)param_1 + 10) == 0",
    "((short)param_1[3] == 0)",
    "*(short *)(param_1 + 0x52) = (short)param_1[0x52] + 0x1e;",
    "*(undefined1 *)((int)param_1 + 0x2c9) = 0x14;",
    "*(undefined2 *)(param_1 + 0x5b) = 1;",
    "*(double *)(param_1 + 0xc) = *(double *)(param_1 + 0xc) / _DAT_00787328;",
    "*(double *)(param_1 + 0x12) = _DAT_00788308;",
    "param_1[0x5a] < 2",
    "*(double *)(param_1 + 10) + *(double *)(param_1 + 0xe) < _DAT_007872f8",
    "*(short *)((int)param_1 + 10) = *(short *)((int)param_1 + 10) + -2;",
    "FUN_00410a10(3,0);",
    "local_50 = 3;",
    "local_34 = 2;",
    "local_33 = 0;",
    "local_28 = 7;",
    "FUN_00407100();",
    "*(undefined2 *)(param_1 + 2) = 0xd6;",
    "*(undefined2 *)(param_1 + 2) = 0xd5;",
    "FUN_0040f1e0();",
):
    assert expression in slam, expression

kickback = "\n".join(blocks[0x5A])
for expression in (
    "*(undefined8 *)(param_1 + 0x12) = _DAT_00788118;",
    "*(double *)(param_1 + 0xe) = *(double *)(param_1 + 0xe) + *(double *)(param_1 + 0x12);",
    "*(short *)((int)param_1 + 10) == 0",
    "((short)param_1[3] == 0)",
    "*(undefined8 *)(param_1 + 0xc) = _DAT_00787cb8;",
    "*(undefined8 *)(param_1 + 0xe) = _DAT_00788110;",
    "*(short *)(param_1 + 3) = (short)param_1[3] + 1;",
    "param_1[0x5a] = 0;",
    "*(undefined2 *)(param_1 + 2) = 9;",
):
    assert expression in kickback, expression

ground = "\n".join(blocks[0x5B])
for expression in (
    "*(double *)(param_1 + 0xc) = _DAT_007872f8;",
    "*(double *)(param_1 + 0xe) = _DAT_007872f8;",
    "*(short *)((int)param_1 + 10) == 0",
    "((short)param_1[3] == 0)",
    "FUN_00410a10(3,0);",
    "local_50 = 3;",
    "local_34 = 2;",
    "local_33 = 0;",
    "local_28 = 7;",
    "FUN_00407100();",
    "*(short *)(param_1 + 3) = (short)param_1[3] + 1;",
    "*(undefined2 *)(param_1 + 2) = 7;",
    "*(undefined2 *)(param_1 + 2) = 3;",
    "FUN_0040e630();",
):
    assert expression in ground, expression

sys.path.insert(0, str(ROOT / "scripts"))
from common import verify_target, target_bytes
pe = verify_target()
constants = {
    0x00787328: 2.0,
    0x00788308: 0.07,
    0x00788118: 0.042,
    0x00788110: -2.4,
    0x00787CB8: -1.0,
}
for address, expected_value in constants.items():
    actual = struct.unpack("<d", target_bytes(pe, address, 8))[0]
    assert actual == expected_value, (hex(address), actual, expected_value)

source = (ROOT / "workbench/character19-slot06/Character19Slot06Cases.cpp").read_text()
helpers = {
    "slam": "Slot06UpdateAerialGroundSlam",
    "kickback": "Slot06UpdateAerialKickback",
    "ground": "Slot06UpdateGroundImpactRecovery",
}
helper_text = {}
for key, name in helpers.items():
    start = source.index(f"void Character19::{name}")
    end = source.index("\n}\n", start) + 3
    helper_text[key] = source[start:end]

for expression in (
    "velocityY = velocityY + gravity;",
    "meter = meter + 30;",
    "pendingContextSoundSlot = 0x14;",
    "remainingHitCount = 1;",
    "velocityX = velocityX / 2.0;",
    "gravity = 0.07;",
    "attackCollisionResult > 1",
    "field0008 = 0xd5;",
    "ResetPose();",
    "ResetFrame();",
    "(positionY + velocityY) >= 0.0",
    "positionY = 0.0;",
    "SetVerticalShake(3, 0);",
    "spawn->type = 3;",
    "spawn->x = (double)(int)positionX;",
    "spawn->y = (double)(int)positionY;",
    "spawn->group = 2;",
    "spawn->layer = 0;",
    "spawn->palette = 7;",
    "contextOwner->EmitEffect(spawn);",
    "pendingContextSoundSlot = 7;",
    "field0008 = 0xd6;",
    "field000a = field000a - 2;",
):
    assert expression in helper_text["slam"], expression

for expression in (
    "gravity = 0.042;",
    "velocityY = velocityY + gravity;",
    "velocityX = -1.0;",
    "velocityY = -2.4;",
    "attackCollisionResult = 0;",
    "field0008 = 9;",
    "ResetPose();",
):
    assert expression in helper_text["kickback"], expression

slam_start = source.index("void Character19::Slot06UpdateAerialGroundSlam")
slam_end = source.index("\n}\n", slam_start) + 3
assert "spawn->owner = 1;" not in source[slam_start:slam_end]
ground_start = source.index("void Character19::Slot06UpdateGroundImpactRecovery")
ground_end = source.index("\n}\n", ground_start) + 3
assert "spawn->owner = 1;" not in source[ground_start:ground_end]

for expression in (
    "velocityX = 0.0;",
    "velocityY = 0.0;",
    "SetVerticalShake(3, 0);",
    "spawn->type = 3;",
    "spawn->x = (double)(int)positionX;",
    "spawn->y = (double)(int)positionY;",
    "spawn->group = 2;",
    "spawn->layer = 0;",
    "spawn->palette = 7;",
    "contextOwner->EmitEffect(spawn);",
    "attackCollisionResult = 0;",
    "field0008 = 7;",
    "if (inputY == 1)",
    "field0008 = 3;",
    "FaceOpponent();",
    "ResetPose();",
):
    assert expression in helper_text["ground"], expression

# Shared leaf implementations are the direct C++ mappings of the native helpers.
shake = (ROOT / "src/SecondaryEffectControls.cpp").read_text()
assert "void Secondary::SetVerticalShake(int magnitude, int hold)" in shake
assert "contextOwner->state14210 = magnitude;" in shake
assert "contextOwner->state14218 = hold;" in shake
reset = (ROOT / "src/SecondaryState.cpp").read_text()
for expression in (
    "void Secondary::ResetFrame()",
    "velocityX = 0.0;",
    "velocityY = 0.0;",
    "gravity = 0.0;",
    "outgoingPushbackVelocityX = 0.0;",
):
    assert expression in reset, expression
emit = (ROOT / "src/EffectPool.cpp").read_text()
for expression in (
    "void Context::EmitEffect(EffectSpawn *spawn)",
    "effectOwner[field1380] = spawn->owner;",
    "effects[field1380].type = spawn->type;",
    "effects[field1380].x = spawn->x;",
    "effects[field1380].y = spawn->y;",
    "effects[field1380].group = spawn->group;",
    "effects[field1380].layer = spawn->layer;",
    "effects[field1380].palette = spawn->palette;",
    "AdvanceEffectWrite();",
):
    assert expression in emit, expression
native_emit = (ROOT / ".analysis/kanna-slot06/helpers/407100.c").read_text()
for expression in (
    "*(undefined4 *)(param_1 + 0x1384",
    "*(undefined4 *)(param_1 + 0x1d84",
    "*(undefined8 *)(param_1 + 0x2a20",
    "*(undefined8 *)(param_1 + 0x2a28",
    "*(undefined1 *)(param_1 + 0x2a74",
):
    assert expression in native_emit, expression

dispatcher = (ROOT / "workbench/character19-slot06/Character19Slot06.cpp").read_text()
for state, helper in (
    (212, "Slot06UpdateAerialGroundSlam"),
    (213, "Slot06UpdateAerialKickback"),
    (214, "Slot06UpdateGroundImpactRecovery"),
):
    assert f"case {state}:" in dispatcher
    assert helper in dispatcher

print({
    "variants": 3,
    "native_bytes": [443, 188, 287],
    "state_ids": [212, 213, 214],
    "verified_constants": len(constants),
    "context_effects": 2,
})
