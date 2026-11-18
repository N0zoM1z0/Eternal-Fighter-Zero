"""Validate the five large native Kanna Slot06 super/KO state machines 0x70-0x74."""
import csv
import re
import struct
import subprocess
import sys
from pathlib import Path

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
    if 0x70 <= value <= 0x74:
        end = starts[n + 1][0] if n + 1 < len(starts) else len(native_lines)
        blocks[value] = native_lines[i:end]
assert set(blocks) == {0x70, 0x71, 0x72, 0x73, 0x74}

expected = {
    0x70: (970, 300, 0x006746E1),
    0x71: (698, 303, 0x00674AAB),
    0x72: (501, 306, 0x00674D65),
    0x73: (2400, 309, 0x00674F5A),
    0x74: (177, 310, 0x006758BA),
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

native = {case: "\n".join(block) for case, block in blocks.items()}

for expression in (
    "*(undefined2 *)(param_1 + 0x53) = 0xc6;",
    "*(short *)(param_1 + 0x52) = (short)param_1[0x52] + -3000;",
    "FUN_00410b10(0xb0,3);",
    "local_50 = 0x46;",
    "local_28 = 0x40;",
    "local_4c = (double)(iVar4 + (char)param_1[0x14] * 0x1d);",
    "local_44 = (double)(iVar4 + -0x3f);",
    "local_54 = 1;",
    "FUN_00407100();",
    "*(undefined2 *)(param_1 + 0x5b) = 99;",
    "*(undefined1 *)((int)param_1 + 0x2c9) = 0x25;",
    "FUN_004080c0();",
    "local_50 = 0x19f;",
    "local_44 = *(double *)(param_1 + 10) - _DAT_007887e0;",
    "FUN_00410a80(0x32,3);",
    "*(undefined1 *)(param_1 + 0xb2) = 5;",
    "param_1[0xc4f] = param_1[0xc4f] + 1;",
    "FUN_004108a0(0,100);",
    "local_50 = 0x1a1;",
    "local_50 = 0x1a0;",
    "FUN_004108a0(0,0x140);",
    "param_1[0xc4e] < 0xd",
    "*(short *)((int)param_1 + 10) = *(short *)((int)param_1 + 10) + -3;",
    "*(undefined2 *)(param_1 + 2) = 9;",
):
    assert expression in native[0x70], expression

for expression in (
    "param_1[0xc4e] = 10;",
    "*(undefined2 *)(param_1 + 0x53) = 0x78;",
    "*(short *)(param_1 + 0x52) = (short)param_1[0x52] + -3000;",
    "FUN_00410b10(0xb0,3);",
    "local_50 = 0x46;",
    "local_28 = 0x40;",
    "local_34 = 2;",
    "local_54 = 1;",
    "FUN_00407100();",
    "6 < *(ushort *)((int)param_1 + 10)",
    "FUN_00410a80(0x32,3);",
    "FUN_00410a10(3,0x14);",
    "local_50 = 0x1a2;",
    "local_3c = (char)param_1[0x14];",
    "local_4c = (*(double *)(param_1 + 8) + _DAT_007872f8) - _DAT_00787d88",
    "local_3c = -(char)param_1[0x14];",
    "*(undefined1 *)((int)param_1 + 0x2c9) = 0x12;",
    "*(short *)((int)param_1 + 10) == 0xd",
    "0 < param_1[0xc4e]",
    "*(short *)((int)param_1 + 10) = *(short *)((int)param_1 + 10) + -2;",
    "param_1[0xc4e] = param_1[0xc4e] + -1;",
    "*(undefined2 *)(param_1 + 2) = 0;",
):
    assert expression in native[0x71], expression

for expression in (
    "*(undefined8 *)(param_1 + 0x12) = _DAT_00787dd8;",
    "*(undefined2 *)(param_1 + 0x53) = 0x78;",
    "*(short *)(param_1 + 0x52) = (short)param_1[0x52] + -3000;",
    "FUN_00410b10(0xb0,0x21);",
    "local_50 = 0x46;",
    "local_28 = 0x40;",
    "FUN_00407100();",
    "FUN_00410a80(0x32,3);",
    "local_50 = 0x1aa;",
    "local_3c = (char)param_1[0x14];",
    "*(undefined2 *)(param_1 + 2) = 9;",
    "FUN_0040e630();",
):
    assert expression in native[0x72], expression

for expression in (
    "FUN_0040f1e0();",
    "*(undefined2 *)(param_1 + 0x53) = 0x78;",
    "*(short *)(param_1 + 0x52) = (short)param_1[0x52] + -3000;",
    "FUN_00410b10(0xb0,3);",
    "local_50 = 0x46;",
    "local_50 = 0x47;",
    "*(undefined2 *)(param_1 + 0x5b) = 99;",
    "local_50 = 0x1b2;",
    "local_50 = 0x1b3;",
    "*(undefined2 *)(*(int *)param_1[0x1e] + 0x14a) = 0x10e;",
    "local_50 = 0x1b0;",
    "*(undefined2 *)(*(int *)param_1[0x1e] + 0x140) = 30000;",
    "*(undefined2 *)(param_1 + 0x53) = 0x23a;",
    "FUN_00410b10(0xb0,3000);",
    "local_50 = 9;",
    "*(undefined1 *)(param_1 + 0xb2) = 10;",
    "*(undefined2 *)(param_1[0x1f] + 0x1420e) = 30000;",
    "*(undefined8 *)(param_1 + 0xe) = _DAT_00788cd0;",
    "*(undefined8 *)(param_1 + 0x12) = _DAT_00787dd8;",
    "local_50 = 0x1b4;",
    "local_50 = 0x1b5;",
    "local_50 = 0x1b6;",
    "*(undefined1 *)(param_1 + 0xb2) = 0xb;",
    "*(undefined2 *)(*(int *)param_1[0x1e] + 0x14a) = 3000;",
    "*(undefined8 *)(param_1 + 0xe) = _DAT_007885b0;",
    "local_50 = 0x1b7;",
    "*(undefined1 *)(param_1 + 0xb2) = 0xc;",
    "local_50 = 0x1c0;",
    "*(undefined8 *)(param_1 + 0xe) = _DAT_00788498;",
    "local_50 = 0x1b8;",
    "FUN_00410a80(0x32,3);",
    "FUN_00410a40(0x32,3);",
    "*(undefined2 *)(param_1 + 2) = 0x136;",
    "*(undefined2 *)(param_1 + 2) = 0xd;",
):
    assert expression in native[0x73], expression

for expression in (
    "*(double *)(param_1 + 0xc) = _DAT_007872f8;",
    "*(double *)(param_1 + 0xe) = _DAT_007872f8;",
    "*(double *)(param_1 + 0x12) = _DAT_007872f8;",
    "*(short *)(param_1 + 3) = (short)param_1[3] + 1;",
    "param_1[0x5a] = 0;",
    "FUN_0040e630();",
    "(**(code **)*param_1)();",
    "*(undefined2 *)(param_1 + 2) = 0;",
):
    assert expression in native[0x74], expression

sys.path.insert(0, str(ROOT / "scripts"))
from common import verify_target, target_bytes
pe = verify_target()
for address, expected_value in (
    (0x00787CE8, 60.0),
    (0x007881D0, 0.08),
    (0x007887E0, 67.0),
    (0x00787DD8, 0.035),
    (0x00787D88, 30.0),
    (0x00787370, 160.0),
    (0x007875C0, 1.0),
    (0x00787CE0, 40.0),
    (0x00787E78, 140.0),
    (0x00787EB8, 50.0),
    (0x00787EF0, 150.0),
    (0x00788498, -7.0),
    (0x007885B0, -0.05),
    (0x00788CD0, -7.5),
    (0x00787CA0, 0.03),
):
    actual = struct.unpack("<d", target_bytes(pe, address, 8))[0]
    assert actual == expected_value, (hex(address), actual, expected_value)

source = (ROOT / "workbench/character19-slot06/Character19Slot06Cases.cpp").read_text()
source_helpers = {
    0x70: (
        "Slot06Case70",
        ("hitstunFrames = 0xc6;", "meter = meter - 3000;", "SetTint(0xb0, 3);",
         "spawn.type = 0x46;", "spawn.owner = 1;", "contextOwner->EmitEffect(&spawn);",
         "remainingHitCount = 99;", "pendingContextSoundSlot = 0x25;",
         "contextOwner->SetSceneTimer(0x0f);", "spawn.type = 0x19f;",
         "spawn.y = positionY - 67.0;", "SetHorizontalShake(0x32, 3);",
         "pendingCharacterSoundSlot = 5;", "field313c = field313c + 1;",
         "RandomRange(0, 100)", "field313c * 0.08 + 60.0",
         "RandomRange(0, 0x140)", "spawn.type = 0x1a1;", "spawn.type = 0x1a0;",
         "field3138 < 0x0d", "field000a = field000a - 3;", "FaceOpponent();",
         "ResetPose();", "field0008 = 9;", "gravity = 0.035;")),
    0x71: (
        "Slot06Case71",
        ("velocityX = 0.0;", "velocityY = 0.0;", "field3138 = 10;",
         "hitstunFrames = 0x78;", "meter = meter - 3000;", "SetTint(0xb0, 3);",
         "spawn.type = 0x46;", "remainingHitCount = 99;",
         "SetHorizontalShake(0x32, 3);", "SetVerticalShake(3, 0x14);",
         "spawn.type = 0x1a2;", "spawn.x = positionX - 30.0;",
         "spawn.x = (positionX - (double)((char)facing * 0x28)) - 30.0;",
         "spawn.flag0018 = (char)-facing;", "pendingContextSoundSlot = 0x12;",
         "field000a == 0x0d", "field3138 > 0", "field000a = field000a - 2;", "field3138 = field3138 - 1;", "FaceOpponent();", "ResetPose();")),
    0x72: (
        "Slot06Case72",
        ("velocityX = 0.0;", "velocityY = 0.0;", "gravity = 0.035;",
         "hitstunFrames = 0x78;", "meter = meter - 3000;", "SetTint(0xb0, 0x21);",
         "spawn.type = 0x46;", "SetHorizontalShake(0x32, 3);",
         "spawn.type = 0x1aa;", "spawn.x = positionX;", "spawn.y = positionY;",
         "attackCollisionResult = 0;", "field0008 = 9;", "FaceOpponent();", "ResetPose();")),
    0x73: (
        None,
        ("ResetFrame();", "hitstunFrames = 0x78;", "meter = meter - 3000;",
         "SetTint(0xb0, 3);", "spawn.type = 0x46;", "spawn.type = 0x47;",
         "spawn.type = 0x1b2;", "spawn.type = 0x1b3;",
         "(*opponentSlot)->hitstopFrames = 0x10e;", "spawn.type = 0x1b0;",
         "(*opponentSlot)->koDelayFrames = 30000;", "hitstunFrames = 0x23a;",
         "SetTint(0xb0, 3000);", "spawn.type = 9;", "pendingCharacterSoundSlot = 10;",
         "contextOwner->state1420e = 30000;", "velocityY = -7.5;", "gravity = 0.035;",
         "spawn.type = 0x1b4;", "spawn.type = 0x1b5;", "spawn.type = 0x1b6;",
         "velocityY = -0.05;", "pendingCharacterSoundSlot = 12;",
         "spawn.type = 0x1b7;", "velocityY = -7.0;", "gravity = 0.03;",
         "spawn.type = 0x1c0;", "spawn.type = 0x1b8;",
         "SetHorizontalShake(0x32, 3);", "SetHorizontalOffset(0x32, 3);",
         "field000a == 0x35", "field000a == 0x37", "field000a == 0x2b",
         "field000a == 0x24", "field0008 = 0x136;", "field0008 = 0x0d;")),
    0x74: (
        "Slot06Case74",
        ("velocityX = 0.0;", "velocityY = 0.0;", "gravity = 0.0;",
         "attackCollisionResult = 0;", "field0008 = 0;", "FaceOpponent();", "ResetPose();")),
}
for case, (name, expressions) in source_helpers.items():
    if case in (0x70, 0x71, 0x72, 0x73, 0x74):
        body = (ROOT / f"workbench/character19-slot06/Character19Slot06Case{case:02X}.inc").read_text()
    else:
        start = source.index(f"void Character19::{name}")
        end = source.index("\n}\n", start) + 3
        body = source[start:end]
    for expression in expressions:
        assert expression in body, (hex(case), expression)

for case in (0x70, 0x71, 0x72, 0x73):
    body = (ROOT / f"workbench/character19-slot06/Character19Slot06Case{case:02X}.inc").read_text()
    assert "ResetLocalEffectSpawn" not in body
    assert "EffectSpawn spawn" not in body
    assert "timing.frameDuration" in body
    assert "timing.animationFrameCount" in body

inline73 = (ROOT / "workbench/character19-slot06/Character19Slot06Case73.inc").read_text()
assert inline73.count("ResetFrame();") == 2
landing_reset = inline73.rindex("ResetFrame();")
landing_pose = inline73.rindex("ResetPose();")
landing_y = inline73.rindex("positionY = 0.0;")
landing_state = inline73.rindex("field0008 = 0x0d;")
assert landing_reset < landing_pose < landing_y < landing_state

dispatcher_source = (ROOT / "workbench/character19-slot06/Character19Slot06.cpp").read_text()
assert "EffectSpawn spawn;" in dispatcher_source
assert "unsigned short randomValue;" in dispatcher_source
assert "ResetLocalEffectSpawn(&spawn);" in dispatcher_source
for case in (0x70, 0x71, 0x72, 0x73, 0x74):
    assert f'#include "Character19Slot06Case{case:02X}.inc"' in dispatcher_source

# Validate the natural leaf functions used by these bosses.
random_source = (ROOT / "src/SecondaryCombat.cpp").read_text()
for expression in (
    "short Secondary::RandomRange(short low, short high)",
    "unsigned short value = std::rand();",
    "contextOwner->replayFile.ReadWord()",
    "contextOwner->replayFile.WriteWord(value)",
    "result = low + (high - low) * value / 32768;",
):
    assert expression in random_source, expression
scene = (ROOT / "src/MizukaStateSupport.cpp").read_text()
assert "void Context::SetSceneTimer(int duration)" in scene
assert "state14278 = duration;" in scene
assert "state14278 = state14278 / 2;" in scene
controls = (ROOT / "src/SecondaryEffectControls.cpp").read_text()
for expression in (
    "void Secondary::SetHorizontalShake(int magnitude, int hold)",
    "void Secondary::SetTint(unsigned char value, int duration)",
    "void Secondary::SetVerticalShake(int magnitude, int hold)",
):
    assert expression in controls, expression
offset = (ROOT / "src/MizukaStateSupport.cpp").read_text()
assert "void Secondary::SetHorizontalOffset(int magnitude, int hold)" in offset
reset = (ROOT / "src/SecondaryState.cpp").read_text()
assert "void Secondary::ResetFrame()" in reset

renderer = (ROOT / "workbench/character19-slot06/Character19Slot06.cpp").read_text()
for selector_case in (0x70, 0x71, 0x72, 0x73, 0x74):
    assert f"case {selector_case}:" in renderer
    assert f'#include "Character19Slot06Case{selector_case:02X}.inc"' in renderer

# The native RandomRange helper consumes the same CRT/replay word and scales by 32768.
random_disasm = subprocess.run(
    ["objdump", "-D", "-Mintel", "--start-address=0x004108A0", "--stop-address=0x00410934",
     str(ROOT / "resources/EFZ.exe")],
    cwd=ROOT, check=True, capture_output=True, text=True,
).stdout
for expression in (
    "call   0x777d61",
    "call   0x405fb0",
    "call   0x406020",
    "imul   eax,edx",
    "sar    eax,0xf",
):
    assert expression in random_disasm, expression

print({
    "variants": 5,
    "native_bytes": [970, 698, 501, 2400, 177],
    "state_ids": [300, 303, 306, 309, 310],
    "verified_constants": 15,
    "shared_leafs": 7,
    "largest_native_handler_bytes": 2400,
})
