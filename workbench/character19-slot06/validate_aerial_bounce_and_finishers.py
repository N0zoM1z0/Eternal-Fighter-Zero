"""Validate Kanna's looping aerial bounces and local-effect finishers 0x68-0x6d."""
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
    if 0x68 <= value <= 0x6D:
        blocks[value] = lines[i:starts[n + 1][0]]
assert set(blocks) == {0x68, 0x69, 0x6A, 0x6B, 0x6C, 0x6D}

expected = {
    0x68: (361, 256, 0x00673A17),
    0x69: (704, 257, 0x00673B80),
    0x6A: (120, 259, 0x00673E40),
    0x6B: (355, 263, 0x00673EB8),
    0x6C: (355, 264, 0x0067401B),
    0x6D: (355, 265, 0x0067417E),
}
rows = {
    int(row["case_index"], 16): row
    for row in csv.DictReader((ROOT / "workbench/character19-slot06/case-map.csv").open())
}
for case, (size, state, entry) in expected.items():
    row = rows[case]
    assert int(row["native_entry"], 16) == entry
    assert int(row["native_code_bytes"]) == size
    assert [int(x) for x in row["state_ids"].split(";") if x] == [state]

bounce = "\n".join(blocks[0x68])
for expression in (
    "FUN_0040f1e0();",
    "*(undefined2 *)(param_1 + 0x5b) = 2;",
    "_DAT_007872f8 <= *(double *)(param_1 + 10)",
    "*(double *)(param_1 + 0xe) = *(double *)(param_1 + 0xe) + *(double *)(param_1 + 0x12)",
    "*(short *)((int)param_1 + 10) == 3",
    "*(undefined8 *)(param_1 + 0xe) = _DAT_00787d40;",
    "*(undefined8 *)(param_1 + 0x12) = _DAT_00787cc0;",
    "local_50 = 0x1b9;",
    "local_54 = 1;",
    "local_3c = (char)param_1[0x14];",
    "local_34 = 2;",
    "local_33 = 1;",
    "(**(code **)(*param_1 + 0x24))();",
    "param_1[0x5a] = 0;",
    "*(short *)((int)param_1 + 10) = *(short *)((int)param_1 + 10) + -2;",
    "*(double *)(param_1 + 10) = _DAT_007872f8;",
    "FUN_0040f1e0();",
    "*(undefined2 *)(param_1 + 2) = 0x103;",
):
    assert expression in bounce, expression

combo = "\n".join(blocks[0x69])
for expression in (
    "FUN_004109d0();",
    "param_1[0xc4f] == 0",
    "FUN_0040f1e0();",
    "*(double *)(param_1 + 0x46) = *(double *)(param_1 + 0x46) - _DAT_00787c30;",
    "*(double *)(param_1 + 0x46) = *(double *)(param_1 + 0x46) - _DAT_00787c70;",
    "local_50 = 0x21;",
    "local_28 = 0xb;",
    "local_34 = 2;",
    "local_33 = 1;",
    "FUN_00407100();",
    "param_1[0xc4f] = param_1[0xc4f] + 1;",
    "*(undefined2 *)(param_1 + 0x5b) = 1;",
    "*(short *)((int)param_1 + 10) == 1",
    "local_50 = 0x1b9;",
    "local_54 = 1;",
    "local_3c = (char)param_1[0x14];",
    "(**(code **)(*param_1 + 0x24))();",
    "*(double *)(param_1 + 0xe) = *(double *)(param_1 + 0xe) + *(double *)(param_1 + 0x12)",
    "*(short *)((int)param_1 + 10) == 3",
    "param_1[0xc4f] == 1",
    "*(undefined8 *)(param_1 + 0xe) = _DAT_00787c60;",
    "*(undefined8 *)(param_1 + 0x12) = _DAT_00788250;",
    "param_1[0xc4f] = param_1[0xc4f] + 1;",
    "*(short *)((int)param_1 + 10) == 8",
    "param_1[0xc4e] < 5",
    "param_1[0xc4e] = param_1[0xc4e] + 1;",
    "*(short *)((int)param_1 + 10) == 9",
    "*(undefined2 *)(param_1 + 2) = 0x103;",
    "*(undefined2 *)(param_1 + 2) = 9;",
):
    assert expression in combo, expression

face = "\n".join(blocks[0x6A])
for expression in (
    "*(short *)(param_1 + 3) = (short)param_1[3] + 1;",
    "param_1[0x5a] = 0;",
    "*(undefined2 *)(param_1 + 2) = 3;",
    "FUN_0040e630();",
    "(**(code **)*param_1)();",
):
    assert expression in face, expression

expected_types = {0x6B: 0x190, 0x6C: 0x191, 0x6D: 0x192}
for case, effect_type in expected_types.items():
    block = "\n".join(blocks[case])
    for expression in (
        "FUN_0040f1e0();",
        f"local_50 = {effect_type if case == 0x6B else hex(effect_type)};",
        "local_4c = (double)(iVar4 + (char)param_1[0x14] * 0x1e);",
        "local_44 = (double)(iVar4 + -0x28);",
        "local_34 = 0;",
        "local_33 = 1;",
        "local_38 = (uint)((char)param_1[0x14] != '\\x01');",
        "local_3c = (char)param_1[0x14];",
        "local_2c = 1;",
        "local_54 = 1;",
        "(**(code **)(*param_1 + 0x24))();",
        "*(short *)(param_1 + 0x52) = (short)param_1[0x52] + 0x2d;",
        "*(undefined1 *)(param_1 + 0xb2) = 2;",
        "9 < *(ushort *)((int)param_1 + 10)",
        "param_1[0x5a] = 0;",
        "*(undefined2 *)(param_1 + 2) = 0;",
    ):
        assert expression in block, (hex(case), expression)

sys.path.insert(0, str(ROOT / "scripts"))
from common import verify_target, target_bytes
pe = verify_target()
for address, expected_value in (
    (0x00787D40, -2.5),
    (0x00787CC0, 0.045),
    (0x00787C60, -3.5),
    (0x00788250, 0.015),
    (0x00787C30, 500.0),
    (0x00787C70, 250.0),
):
    actual = struct.unpack("<d", target_bytes(pe, address, 8))[0]
    assert actual == expected_value, (hex(address), actual, expected_value)

source = (ROOT / "workbench/character19-slot06/Character19Slot06Cases.cpp").read_text()
helpers = {
    "bounce": ("Slot06UpdateLoopingAerialBounce", (
        "ResetFrame();", "remainingHitCount = 2;", "positionY < 0.0",
        "velocityY = velocityY + gravity;", "(positionY >= 0.0)",
        "(positionY + velocityY) < 0.0", "field000a == 3",
        "velocityY = -2.5;", "gravity = 0.045;", "spawn->owner = 1;",
        "spawn->type = 0x1b9;", "spawn->flag0018 = (unsigned char)facing;",
        "spawn->group = 2;", "spawn->layer = 1;", "EmitLocalEffect(spawn);",
        "attackCollisionResult = 0;", "field000a = field000a - 2;",
        "positionY = 0.0;", "ResetPose();", "ResetFrame();", "field0008 = 0x103;",
    )),
    "combo": ("Slot06UpdateComboAerialBounce", (
        "StartTrail(1);", "field313c == 0", "ResetFrame();",
        "field0118 = field0118 - 500.0;", "field0118 = field0118 - 250.0;",
        "spawn->type = 0x21;", "spawn->y = (double)((int)positionY - 0x32);",
        "spawn->group = 2;", "spawn->layer = 1;", "spawn->palette = 0xb;",
        "contextOwner->EmitEffect(spawn);", "field313c = field313c + 1;",
        "remainingHitCount = 1;", "field000a == 1", "spawn->owner = 1;",
        "spawn->type = 0x1b9;", "EmitLocalEffect(spawn);",
        "velocityY = velocityY + gravity;", "field000a == 3",
        "field313c == 1", "velocityY = -3.5;", "gravity = 0.015;",
        "field3138 < 5", "field000a = 0;", "field3138 = field3138 + 1;",
        "field000a == 9", "ResetPose();", "field0008 = 9;",
        "field0008 = 0x103;",
    )),
    "face": ("Slot06UpdateFinalFaceTransition", (
        "field000c = field000c + 1;", "field000a = field000a + 1;",
        "attackCollisionResult = 0;", "field0008 = 3;",
        "FaceOpponent();", "ResetPose();",
    )),
    "local": ("Slot06UpdateLocalEffectFinish", (
        "ResetFrame();", "EffectSpawn effect;", "effect.owner = 1;",
        "effect.type = effectType;", "effect.x = (double)((int)positionX + (int)facing * 0x1e);",
        "effect.y = (double)((int)positionY - 0x28);", "effect.group = 0;",
        "effect.layer = 1;", "effect.facing = (facing != 1);",
        "effect.flag0018 = (unsigned char)facing;", "effect.field0028 = 1;",
        "EmitLocalEffect(&effect);", "meter = meter + 45;",
        "pendingCharacterSoundSlot = 2;", "field000a > 9",
        "attackCollisionResult = 0;", "field0008 = 0;", "ResetPose();",
    )),
}
for key, (name, expressions) in helpers.items():
    start = source.index(f"void Character19::{name}")
    end = source.index("\n}\n", start) + 3
    helper = source[start:end]
    for expression in expressions:
        assert expression in helper, (key, expression)

# Native FUN_00405490 zeroes the shared 0x48-byte spawn record before dispatch.
native_init = (ROOT / ".analysis/kanna-slot06/helpers/405490.c").read_text()
assert "_memset(param_1,0,0x48);" in native_init
cpp_init = (ROOT / "src/EffectPool.cpp").read_text()
assert "std::memset(this, 0, sizeof(*this));" in cpp_init

dispatcher = (ROOT / "workbench/character19-slot06/Character19Slot06.cpp").read_text()
for state, name in (
    (256, "Slot06UpdateLoopingAerialBounce"),
    (257, "Slot06UpdateComboAerialBounce"),
    (259, "Slot06UpdateFinalFaceTransition"),
    (263, "Slot06UpdateLocalEffectFinish"),
    (264, "Slot06UpdateLocalEffectFinish"),
    (265, "Slot06UpdateLocalEffectFinish"),
):
    assert f"case {state}:" in dispatcher
    assert name in dispatcher

print({
    "variants": 6,
    "native_bytes": [361, 704, 120, 355, 355, 355],
    "state_ids": [256, 257, 259, 263, 264, 265],
    "verified_constants": 6,
    "local_effects": 6,
})
