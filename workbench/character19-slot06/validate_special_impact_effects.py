"""Validate Kanna's special-effect states 0x64-0x67 against native selector code."""
import csv
import re
import struct
import subprocess
import sys
from pathlib import Path

from selector_support import assert_selector_case, selector_case_for_state

ROOT = Path(__file__).resolve().parents[2]
native_lines = (ROOT / ".analysis/kanna-slot06/native.c").read_text().splitlines()
starts = []
for i, line in enumerate(native_lines):
    match = re.match(r"^\s*case\s+([^:]+):", line)
    if match:
        try:
            value = int(match.group(1), 0)
        except ValueError:
            continue
        starts.append((i, value))
blocks = {}
for n, (i, value) in enumerate(starts):
    if 0x64 <= value <= 0x67:
        blocks[value] = native_lines[i:starts[n + 1][0]]
assert set(blocks) == {0x64, 0x65, 0x66, 0x67}

expected = {
    0x64: (320, 249, 0x00673290),
    0x65: (465, 250, 0x006733D0),
    0x66: (708, 251, 0x006735A1),
    0x67: (434, 253, 0x00673865),
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

stun = "\n".join(blocks[0x64])
for expression in (
    "*(undefined2 *)(param_1 + 0x37) = 4;",
    "*(undefined1 *)((int)param_1 + 0xde) = 0xec;",
    "*(double *)(param_1 + 0xc) = _DAT_007872f8;",
    "*(undefined2 *)(param_1 + 0x5b) = 1;",
    "*(undefined2 *)((int)param_1 + 0x14e) = 0;",
    "*(undefined2 *)(param_1 + 0x53) = 0x3c;",
    "local_50 = 0x28;",
    "local_4c = (double)(iVar4 + (char)param_1[0x14] * 10);",
    "local_44 = (double)(iVar4 + -0x28);",
    "local_34 = 2;",
    "local_33 = 1;",
    "local_28 = 0x13;",
    "FUN_00407100();",
    "*(undefined2 *)(param_1 + 2) = 0;",
    "FUN_0040e630();",
):
    assert expression in stun, expression

pair = "\n".join(blocks[0x65])
for expression in (
    "FUN_0040f1e0();",
    "*(short *)((int)param_1 + 10) == 4",
    "local_50 = 0x1f;",
    "local_4c = (double)iVar4;",
    "local_44 = (double)iVar4;",
    "local_34 = 0;",
    "local_33 = 1;",
    "local_38 = (uint)((char)param_1[0x14] != '\\x01');",
    "FUN_00407100();",
    "*(undefined2 *)(param_1 + 0x5b) = 1;",
    "*(short *)(param_1 + 0x52) = (short)param_1[0x52] + 0x2d;",
    "*(undefined1 *)(param_1 + 0xb2) = 1;",
    "local_50 = 0x194;",
    "local_4c = (double)(iVar4 + (char)param_1[0x14] * -0x50);",
    "local_44 = (double)(iVar4 + -0x28);",
    "local_54 = 1;",
    "local_3c = (char)param_1[0x14];",
    "(**(code **)(*param_1 + 0x24))();",
    "param_1[0x5a] = 0;",
    "*(undefined2 *)(param_1 + 2) = 0;",
):
    assert expression in pair, expression

combo = "\n".join(blocks[0x66])
for expression in (
    "FUN_0040f1e0();",
    "FUN_004109d0();",
    "*(double *)(param_1 + 0x46) = *(double *)(param_1 + 0x46) - _DAT_00787c30;",
    "*(double *)(param_1 + 0x46) = *(double *)(param_1 + 0x46) - _DAT_00787c70;",
    "*(undefined2 *)(param_1 + 0x5b) = 1;",
    "local_50 = 0x21;",
    "local_28 = 0xb;",
    "local_34 = 2;",
    "local_33 = 1;",
    "FUN_00407100();",
    "*(double *)(param_1 + 0xc) = _DAT_007872f8;",
    "*(double *)(param_1 + 0xe) = _DAT_007872f8;",
    "*(double *)(param_1 + 0x10) = _DAT_007872f8;",
    "*(double *)(param_1 + 10) < _DAT_007872f8",
    "*(undefined2 *)((int)param_1 + 10) = 6;",
    "local_50 = 0x1f;",
    "local_38 = (uint)((char)param_1[0x14] != '\\x01');",
    "*(short *)(param_1 + 0x52) = (short)param_1[0x52] + 0x2d;",
    "local_50 = 0x1ab;",
    "local_54 = 1;",
    "local_3c = (char)param_1[0x14];",
    "(**(code **)(*param_1 + 0x24))();",
    "param_1[0x5a] = 0;",
    "*(undefined2 *)(param_1 + 2) = 0;",
):
    assert expression in combo, expression

damped = "\n".join(blocks[0x67])
for expression in (
    "*(double *)(param_1 + 0xc) = *(double *)(param_1 + 0xc) * _DAT_007872f0;",
    "*(double *)(param_1 + 0xe) = *(double *)(param_1 + 0xe) * _DAT_007872f0;",
    "*(double *)(param_1 + 0xe) = *(double *)(param_1 + 0xe) + _DAT_00787cf0;",
    "_DAT_007872f0 < *(double *)(param_1 + 0xe)",
    "*(double *)(param_1 + 0xe) = _DAT_007872f0;",
    "*(undefined2 *)(param_1 + 0x5b) = 1;",
    "*(short *)(param_1 + 0x52) = (short)param_1[0x52] + 0x2d;",
    "*(undefined1 *)(param_1 + 0xb2) = 1;",
    "local_50 = 0x194;",
    "local_54 = 1;",
    "local_3c = (char)param_1[0x14];",
    "(**(code **)(*param_1 + 0x24))();",
    "param_1[0x5a] = 0;",
    "*(undefined2 *)(param_1 + 2) = 9;",
):
    assert expression in damped, expression

sys.path.insert(0, str(ROOT / "scripts"))
from common import verify_target, target_bytes
pe = verify_target()
for address, expected_value in (
    (0x00787C30, 500.0),
    (0x00787C70, 250.0),
    (0x007872F0, 0.3),
    (0x00787CF0, 0.01),
):
    actual = struct.unpack("<d", target_bytes(pe, address, 8))[0]
    assert actual == expected_value, (hex(address), actual, expected_value)

source = (ROOT / "workbench/character19-slot06/Character19Slot06Cases.cpp").read_text()
helpers = {
    "stun": ("Slot06UpdateStunEffectRecovery", (
        "field00dc = 4;", "field00de = 0xec;", "velocityX = 0.0;",
        "remainingHitCount = 1;", "guardInputFrames = 0;", "hitstunFrames = 60;",
        "spawn->type = 0x28;", "spawn->x = (double)((int)positionX + (int)facing * 10);",
        "spawn->y = (double)((int)positionY - 0x28);", "spawn->group = 2;",
        "spawn->layer = 1;", "spawn->palette = 0x13;", "contextOwner->EmitEffect(spawn);",
        "attackCollisionResult = 0;", "FaceOpponent();", "ResetPose();",
    )),
    "pair": ("Slot06UpdateImpactEffectPair", (
        "ResetFrame();", "field000a == 4", "spawn->type = 0x1f;",
        "spawn->group = 0;", "spawn->layer = 1;", "spawn->facing = (facing != 1);",
        "contextOwner->EmitEffect(spawn);", "meter = meter + 45;",
        "pendingCharacterSoundSlot = 1;", "spawn->type = 0x194;",
        "spawn->x = (double)((int)positionX - (int)facing * 0x50);",
        "spawn->y = (double)((int)positionY - 0x28);", "spawn->flag0018 = (unsigned char)facing;",
        "EmitLocalEffect(spawn);", "field000a < 5)", "field0008 = 0;", "ResetPose();",
    )),
    "combo": ("Slot06UpdateComboImpactBurst", (
        "ResetFrame();", "StartTrail(3);", "field0120 == 0",
        "field0118 = field0118 - 500.0;", "field0118 = field0118 - 250.0;",
        "spawn->type = 0x21;", "spawn->y = (double)((int)positionY - 0x32);",
        "spawn->group = 2;", "spawn->layer = 1;", "spawn->palette = 0xb;",
        "contextOwner->EmitEffect(spawn);", "remainingHitCount = 1;",
        "velocityX = 0.0;", "velocityY = 0.0;", "horizontalDeceleration = 0.0;",
        "positionY < 0.0", "field000a = 6;", "spawn->type = 0x1f;",
        "spawn->facing = (facing != 1);", "meter = meter + 45;",
        "pendingCharacterSoundSlot = 1;", "spawn->type = 0x194;",
        "EmitLocalEffect(spawn);", "field000a == 2", "spawn->type = 0x1ab;",
        "field000a < 5)", "field0008 = 0;", "ResetPose();",
    )),
    "damped": ("Slot06UpdateDampedImpactFinish", (
        "velocityX = velocityX * 0.3;", "velocityY = velocityY * 0.3;",
        "velocityY = velocityY + 0.01;", "velocityY > 0.3", "velocityY = 0.3;",
        "field000a == 4", "meter = meter + 45;", "pendingCharacterSoundSlot = 1;",
        "spawn->type = 0x194;", "spawn->x = (double)((int)positionX - (int)facing * 0x50);",
        "spawn->y = (double)((int)positionY - 0x28);", "spawn->group = 2;",
        "spawn->layer = 1;", "spawn->flag0018 = (unsigned char)facing;",
        "EmitLocalEffect(spawn);", "field000a < 5)", "field0008 = 9;", "ResetPose();",
    )),
}
for key, (name, expressions) in helpers.items():
    start = source.index(f"void Character19::{name}")
    end = source.index("\n}\n", start) + 3
    helper = source[start:end]
    for expression in expressions:
        assert expression in helper, (key, expression)

# The native stack EffectSpawn is zeroed once by FUN_00405490. Thus context
# effects that do not overwrite owner stay owner 0; only local effects explicitly
# set owner 1 before calling EmitLocalEffect.
native_spawn_init = (ROOT / ".analysis/kanna-slot06/helpers/405490.c").read_text()
assert "_memset(param_1,0,0x48);" in native_spawn_init
cpp_spawn_init = (ROOT / "src/EffectPool.cpp").read_text()
assert "std::memset(this, 0, sizeof(*this));" in cpp_spawn_init
stun_start = source.index("void Character19::Slot06UpdateStunEffectRecovery")
stun_end = source.index("\n}\n", stun_start) + 3
assert "spawn->owner = 1;" not in source[stun_start:stun_end]
pair_start = source.index("void Character19::Slot06UpdateImpactEffectPair")
pair_end = source.index("\n}\n", pair_start) + 3
pair_helper = source[pair_start:pair_end]
assert pair_helper.count("spawn->owner = 1;") == 1
assert pair_helper.index("contextOwner->EmitEffect(spawn);") < pair_helper.index("spawn->owner = 1;")
combo_start = source.index("void Character19::Slot06UpdateComboImpactBurst")
combo_end = source.index("\n}\n", combo_start) + 3
combo_helper = source[combo_start:combo_end]
assert combo_helper.count("spawn->owner = 1;") == 2
assert combo_helper.count("contextOwner->EmitEffect(spawn);") == 2

# Confirm the shared C++ leaf functions that replace the native helpers.
reset = (ROOT / "src/SecondaryState.cpp").read_text()
for expression in (
    "void Secondary::ResetFrame()",
    "velocityX = 0.0;",
    "velocityY = 0.0;",
    "horizontalDeceleration = 0.0;",
    "gravity = 0.0;",
):
    assert expression in reset, expression
trail = (ROOT / "src/SecondaryInput.cpp").read_text()
assert "void Secondary::StartTrail(unsigned char spacing)" in trail
assert "trail.Begin(this, spacing);" in trail
local_emit = (ROOT / "src/SecondaryState.cpp").read_text()
assert "void Secondary::EmitLocalEffect(SecondaryEffectSpawn *spawn)" in local_emit
context_emit = (ROOT / "src/EffectPool.cpp").read_text()
assert "void Context::EmitEffect(EffectSpawn *spawn)" in context_emit

disasm = subprocess.run(
    [
        "objdump", "-D", "-Mintel",
        "--start-address=0x00673290",
        "--stop-address=0x00673A17",
        str(ROOT / "resources/EFZ.exe"),
    ],
    cwd=ROOT, check=True, capture_output=True, text=True,
).stdout
for expression in (
    "call   0x407100",
    "call   0x40f1e0",
    "call   0x4109d0",
    "fsub   QWORD PTR ds:0x787c30",
    "fsub   QWORD PTR ds:0x787c70",
    "fmul   QWORD PTR ds:0x7872f0",
    "fadd   QWORD PTR ds:0x787cf0",
):
    assert expression in disasm, expression

dispatcher = (ROOT / "workbench/character19-slot06/Character19Slot06.cpp").read_text()
for state, name in (
    (249, "Slot06UpdateStunEffectRecovery"),
    (250, "Slot06UpdateImpactEffectPair"),
    (251, "Slot06UpdateComboImpactBurst"),
    (253, "Slot06UpdateDampedImpactFinish"),
):
    assert_selector_case(dispatcher, state)
    assert f"{name}(" in dispatcher

print({
    "variants": 4,
    "native_bytes": [320, 465, 708, 434],
    "state_ids": [249, 250, 251, 253],
    "verified_constants": 4,
    "context_effects": 4,
    "local_effects": 4,
})
