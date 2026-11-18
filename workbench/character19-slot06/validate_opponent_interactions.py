"""Validate Kanna's native opponent-capture and stage-combo selectors 0x5c/0x5d."""
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
    if value in (0x5C, 0x5D):
        blocks[value] = lines[i:starts[n + 1][0]]
assert set(blocks) == {0x5C, 0x5D}

expected = {
    0x5C: (480, 220, 0x006725FD),
    0x5D: (594, 221, 0x006727DD),
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

capture = "\n".join(blocks[0x5C])
for expression in (
    "*(double *)(param_1 + 0xc) = _DAT_007872f8;",
    "*(double *)(param_1 + 0xe) = _DAT_007872f8;",
    "*(short *)((int)param_1 + 10) == 1",
    "((short)param_1[3] == 0)",
    "*(double *)(*(int *)param_1[0x1e] + 0x28) == _DAT_007872f8",
    "*(undefined2 *)(param_1 + 0x5b) = 1;",
    "*(undefined2 *)(param_1 + 0x5b) = 0;",
    "param_1[0x5a] == 3",
    "(**(code **)*param_1)();",
    "FUN_0040f1e0();",
    "(**(code **)**(undefined4 **)param_1[0x1e])();",
    "*(undefined2 *)(param_1 + 2) = 0xdd;",
    "*(undefined4 *)(*(int *)param_1[0x1e] + 0x128) = 1;",
    "local_50 = 0;",
    "local_34 = 2;",
    "local_33 = 1;",
    "FUN_00407100();",
    "*(undefined2 *)(param_1 + 2) = 0;",
    "*(undefined2 *)(param_1 + 2) = 3;",
    "FUN_0040e630();",
):
    assert expression in capture, expression
assert capture.count("FUN_0040f1e0();") == 2
assert "*(undefined2 *)(*(int *)param_1[0x1e] + 8) = 0x6e;" not in capture

stage = "\n".join(blocks[0x5D])
for expression in (
    "*(short *)((int)param_1 + 10) == 4",
    "((short)param_1[3] == 0)",
    "FUN_004105a0(0x4e2,_DAT_00787c80);",
    "*(undefined2 *)(*(int *)param_1[0x1e] + 8) = 0x67;",
    "FUN_0040f1e0();",
    "(**(code **)**(undefined4 **)param_1[0x1e])();",
    "*(undefined8 *)(*(int *)param_1[0x1e] + 0x28) = _DAT_007887f0;",
    "*(double *)(*(int *)param_1[0x1e] + 0x20) =",
    "*(undefined8 *)(*(int *)param_1[0x1e] + 0x28) = _DAT_00788028;",
    "*(char *)(*(int *)param_1[0x1e] + 0x50) = -(char)param_1[0x14];",
    "FUN_00410a10(3,0);",
    "*(undefined2 *)(*(int *)param_1[0x1e] + 8) = 0x61;",
    "*(undefined2 *)(param_1 + 2) = 0;",
    "FUN_0040e630();",
):
    assert expression in stage, expression
assert "*(undefined2 *)(*(int *)param_1[0x1e] + 8) = 0x3b;" not in stage
assert "airActionDisabled" not in stage
assert "knockbackVelocity" not in stage

def disassemble(start, end):
    return subprocess.run(
        [
            "objdump", "-D", "-Mintel",
            f"--start-address={start:#x}",
            f"--stop-address={end:#x}",
            str(ROOT / "resources/EFZ.exe"),
        ],
        cwd=ROOT, check=True, capture_output=True, text=True,
    ).stdout

capture_disasm = disassemble(0x006725FD, 0x006727DD)
for expression in (
    "call   0x40f1e0",
    "mov    WORD PTR [ecx+0x8],0xdd",
    "mov    DWORD PTR [ecx+0x128],0x1",
    "call   0x7783b8",
    "imul   edx,edx,0x25",
    "sub    eax,0x2a",
    "call   0x407100",
):
    assert expression in capture_disasm, expression

stage_disasm = disassemble(0x006727DD, 0x00672A2F)
for expression in (
    "fld    QWORD PTR ds:0x787c80",
    "push   0x4e2",
    "call   0x4105a0",
    "mov    WORD PTR [ecx+0x8],0x67",
    "fld    QWORD PTR ds:0x7887f0",
    "fld    QWORD PTR ds:0x788028",
    "call   0x410a10",
    "mov    WORD PTR [eax+0x8],0x61",
):
    assert expression in stage_disasm, expression

sys.path.insert(0, str(ROOT / "scripts"))
from common import verify_target, target_bytes
pe = verify_target()
constants = {
    0x00787C80: 750.0,
    0x007887F0: -86.0,
    0x00788028: -97.0,
}
for address, expected_value in constants.items():
    actual = struct.unpack("<d", target_bytes(pe, address, 8))[0]
    assert actual == expected_value, (hex(address), actual, expected_value)

source = (ROOT / "workbench/character19-slot06/Character19Slot06Cases.cpp").read_text()
assert "Slot06UpdateOpponentCaptureImpact" not in source
assert "Slot06UpdateOpponentStageCombo" not in source
capture_helper = (ROOT / "workbench/character19-slot06/Character19Slot06Case5C.inc").read_text()
for expression in (
    "Secondary *target = *opponentSlot;",
    "velocityX = 0.0;",
    "velocityY = 0.0;",
    "target->positionY == 0.0",
    "remainingHitCount = 1;",
    "remainingHitCount = 0;",
    "attackCollisionResult == 3",
    "outgoingPushbackVelocityX = 0.0;",
    "ResetPose();",
    "ResetFrame();",
    "target->ResetFrame();",
    "target->ResetPose();",
    "field0008 = 0xdd;",
    "target->airActionDisabled = 1;",
    "spawn.type = 0;",
    "spawn.x = (double)((int)positionX + (int)facing * 0x25);",
    "spawn.y = (double)((int)positionY - 0x2a);",
    "spawn.group = 2;",
    "spawn.layer = 1;",
    "contextOwner->EmitEffect(&spawn);",
    "timing.frameDuration",
    "timing.animationFrameCount",
):
    assert expression in capture_helper, expression
assert "target->field0008 = 0x6e" not in capture_helper
assert "spawn.owner = 1;" not in capture_helper

stage_helper = (ROOT / "workbench/character19-slot06/Character19Slot06Case5D.inc").read_text()
for expression in (
    "Secondary *target = *opponentSlot;",
    "field000a == 4",
    "ApplyDamage(0x4e2, 750.0);",
    "target->field0008 = 0x67;",
    "target->ResetFrame();",
    "target->ResetPose();",
    "target->positionY = -86.0;",
    "facing * 0x29",
    "target->positionY = -97.0;",
    "facing * 0x24",
    "facing * 0x22",
    "target->facing = -facing;",
    "SetVerticalShake(3, 0);",
    "target->field0008 = 0x61;",
    "target->positionY = 0.0;",
    "field0008 = 0;",
    "FaceOpponent();",
    "ResetPose();",
    "timing.frameDuration",
    "timing.animationFrameCount",
):
    assert expression in stage_helper, expression
for wrong in ("SetHorizontalShake", "airActionDisabled", "knockbackVelocity", "field0008 = 0x3b"):
    assert wrong not in stage_helper, wrong

damage = (ROOT / "src/SecondaryCombat.cpp").read_text()
assert "void Secondary::ApplyDamage(int damage, double scaling)" in damage
for expression in (
    "(*opponentSlot)->health -=",
    "comboDamageScale = (scaling / 1000.0) * comboDamageScale;",
    "++comboHitCount;",
    "comboDisplayHitCount = comboHitCount;",
):
    assert expression in damage, expression

reset = (ROOT / "src/SecondaryState.cpp").read_text()
assert "void Secondary::ResetFrame()" in reset
shake = (ROOT / "src/SecondaryEffectControls.cpp").read_text()
assert "void Secondary::SetVerticalShake(int magnitude, int hold)" in shake

dispatcher = (ROOT / "workbench/character19-slot06/Character19Slot06.cpp").read_text()
assert_selector_case(dispatcher, 220)
assert '#include "Character19Slot06Case5C.inc"' in dispatcher
assert "Slot06UpdateOpponentCaptureImpact(" not in dispatcher
assert_selector_case(dispatcher, 221)
assert '#include "Character19Slot06Case5D.inc"' in dispatcher
assert "Slot06UpdateOpponentStageCombo(" not in dispatcher
print({
    "variants": 2,
    "native_bytes": [480, 594],
    "state_ids": [220, 221],
    "damage": {"base": 0x4e2, "scale": constants[0x00787C80]},
    "verified_opponent_effect": True,
})
