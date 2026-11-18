"""Validate native hitstun/velocity restoration selectors 0x4a and 0x4b."""
import csv
import re
import struct
import subprocess
import sys
from pathlib import Path

from selector_support import assert_selector_case, selector_case_for_state

ROOT = Path(__file__).resolve().parents[2]
TARGET = ROOT / "resources/EFZ.exe"
NATIVE = (ROOT / ".analysis/kanna-slot06/native.c").read_text()
lines = NATIVE.splitlines()
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
    if value in (0x4A, 0x4B):
        blocks[value] = lines[i:starts[n + 1][0]]
assert set(blocks) == {0x4A, 0x4B}

case_rows = {
    int(row["case_index"], 16): row
    for row in csv.DictReader((ROOT / "workbench/character19-slot06/case-map.csv").open())
}
expected = {0x4A: (457, 170, 0x006702DC), 0x4B: (584, 171, 0x006704A5)}
for case, (native_size, state, entry) in expected.items():
    row = case_rows[case]
    assert int(row["native_code_bytes"]) == native_size
    assert int(row["native_entry"], 16) == entry
    assert [int(x) for x in row["state_ids"].split(";") if x] == [state]

# Check the actual i386 instructions which store the two launch components.
def disassemble(start, end):
    return subprocess.run(
        [
            "objdump", "-D", "-Mintel",
            f"--start-address={start:#x}",
            f"--stop-address={end:#x}",
            str(TARGET),
        ],
        cwd=ROOT,
        check=True,
        capture_output=True,
        text=True,
    ).stdout

disasm_4a = disassemble(0x006702DC, 0x006704A5)
disasm_4b = disassemble(0x006704A5, 0x006706ED)
for text, label in ((disasm_4a, "0x4a"), (disasm_4b, "0x4b")):
    for expression in (
        "fld    QWORD PTR [ecx+0x30]",
        "fmul   QWORD PTR ds:0x7875d0",
        "call   0x7783b8",
        "mov    DWORD PTR [edx+0x3138],eax",
        "fld    QWORD PTR [eax+0x38]",
        "mov    DWORD PTR [ecx+0x313c],eax",
    ):
        assert expression in text, (label, expression)

block_4a = "\n".join(blocks[0x4A])
for expression in (
    "param_1[0xc4e] = iVar4;",
    "param_1[0xc4f] = iVar4;",
    "*(double *)(param_1 + 0xc) = _DAT_007872f8;",
    "*(double *)(param_1 + 0xe) = _DAT_007872f8;",
    "*(undefined8 *)(param_1 + 0x12) = _DAT_00787dd8;",
    "*(undefined2 *)((int)param_1 + 0x14e) = 0;",
    "*(double *)(param_1 + 0x2e) = _DAT_007872f8;",
    "*(undefined2 *)(param_1 + 0x53) = 0x3c;",
    "param_1[0xc50] == 0",
    "param_1[0xc50] = param_1[0xc50] + 1;",
    "(double)param_1[0xc4e] * _DAT_00787cf0",
    "(double)param_1[0xc4f] * _DAT_00787cf0",
    "*(double *)(param_1 + 0xe) = *(double *)(param_1 + 0xe) + *(double *)(param_1 + 0x12);",
    "*(double *)(param_1 + 0xe) + *(double *)(param_1 + 10) <= _DAT_007872f8",
    "FUN_0040f1e0();",
    "*(undefined2 *)(param_1 + 2) = 0xa9;",
    "*(undefined2 *)(param_1 + 2) = 9;",
):
    assert expression in block_4a, expression
assert "*(undefined1 *)(param_1 + 0x56) = 0;" not in block_4a

block_4b = "\n".join(blocks[0x4B])
for expression in (
    "param_1[0xc4e] = iVar4;",
    "param_1[0xc4f] = iVar4;",
    "*(double *)(param_1 + 0xc) = _DAT_007872f8;",
    "*(double *)(param_1 + 0xe) = _DAT_007872f8;",
    "*(undefined1 *)((int)param_1 + 0x2c9) = 0x12;",
    "*(double *)(param_1 + 0x5e) =",
    "*(double *)(param_1 + 0x46) = _DAT_007872f8;",
    "*(undefined2 *)(param_1 + 0x53) = 0x5a;",
    "FUN_00410b10(0xb0,3);",
    "local_50 = 1;",
    "local_50 = 4;",
    "local_34 = 2;",
    "local_33 = 1;",
    "FUN_00407100();",
    "param_1[0x5a] = 0;",
    "(double)param_1[0xc4e] * _DAT_00787cf0",
    "(double)param_1[0xc4f] * _DAT_00787cf0",
    "*(undefined8 *)(param_1 + 0x12) = _DAT_00787dd8;",
    "*(undefined2 *)(param_1 + 2) = 9;",
):
    assert expression in block_4b, expression

# The conversion helper is the target's x87 float-to-long routine, not RNG.
ftol = (ROOT / ".analysis/kanna-slot06/helpers/7783b8.c").read_text()
assert "ROUND(in_ST0)" in ftol
assert "CONCAT44" in ftol
assert "0x80000000 < (uint)" in ftol
assert "uVar1 = uVar1 + (0x80000000 <" in ftol
assert "local_20 - uVar2" in ftol

sys.path.insert(0, str(ROOT / "scripts"))
from common import verify_target, target_bytes
pe = verify_target()
constants = {
    0x007875D0: 100.0,
    0x00787CF0: 0.01,
    0x00787DD8: 0.035,
    0x007872C0: 5.0,
}
for address, expected_value in constants.items():
    actual = struct.unpack("<d", target_bytes(pe, address, 8))[0]
    assert actual == expected_value, (hex(address), actual, expected_value)

source = (ROOT / "workbench/character19-slot06/Character19Slot06Cases.cpp").read_text()
start = source.index("void Character19::Slot06UpdateAirborneHitstunRestore")
mid = source.index("\n}\n", start) + 3
hitstun_source = source[start:mid]
for expression in (
    "field3138 = (int)(velocityX * 100.0);",
    "field313c = (int)(velocityY * 100.0);",
    "velocityX = 0.0;",
    "velocityY = 0.0;",
    "if (gravity == 0.0)",
    "gravity = 0.035;",
    "guardInputFrames = 0;",
    "outgoingPushbackVelocityX = 0.0;",
    "hitstunFrames = 60;",
    "if ((hitstunFrames == 0) && (field3140 == 0))",
    "field3140 = 1;",
    "velocityX = (double)field3138 * 0.01;",
    "velocityY = (double)field313c * 0.01;",
    "if (hitstunFrames == 0)",
    "velocityY = velocityY + gravity;",
    "if ((positionY + velocityY) > 0.0)",
    "ResetFrame();",
    "positionY = 0.0;",
    "field0008 = 0xa9;",
    "field0008 = 9;",
):
    assert expression in hitstun_source, expression
assert "dashMomentumFlag" not in hitstun_source

assert "Slot06UpdateDefeatImpactVelocityRestore" not in source
defeat_source = (ROOT / "workbench/character19-slot06/Character19Slot06Case4B.inc").read_text()
for expression in (
    "field3138 = (int)(velocityX * 100.0);",
    "field313c = (int)(velocityY * 100.0);",
    "velocityX = 0.0;",
    "velocityY = 0.0;",
    "comboDamageScale = comboDamageScale + (field0118 * 5.0);",
    "field0118 = 0.0;",
    "hitstunFrames = 90;",
    "SetTint(0xb0, 3);",
    "pendingContextSoundSlot = 0x12;",
    "spawn.type = 1;",
    "spawn.type = 4;",
    "spawn.group = 2;",
    "spawn.layer = 1;",
    "contextOwner->EmitEffect(&spawn);",
    "attackCollisionResult = 0;",
    "field0008 = 9;",
    "velocityX = (double)field3138 * 0.01;",
    "velocityY = (double)field313c * 0.01;",
    "gravity = 0.035;",
    "ResetPose();",
    "timing.frameDuration",
    "timing.animationFrameCount",
):
    assert expression in defeat_source, expression
assert defeat_source.count("contextOwner->EmitEffect(&spawn);") == 2
for wrong in ("field3144", "field3148", "field314c", "dashMomentumFlag"):
    assert wrong not in defeat_source, wrong

# Shared leaf functions used by the two handlers are independently reconstructed.
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
set_tint = (ROOT / "src/SecondaryEffectControls.cpp").read_text()
assert "void Secondary::SetTint(unsigned char value, int duration)" in set_tint
assert "field30c4 = field30c4 / 2;" in set_tint
emit = (ROOT / "src/EffectPool.cpp").read_text()
for expression in (
    "effects[field1380].type = spawn->type;",
    "effects[field1380].x = spawn->x;",
    "effects[field1380].y = spawn->y;",
    "effects[field1380].group = spawn->group;",
    "effects[field1380].layer = spawn->layer;",
    "AdvanceEffectWrite();",
):
    assert expression in emit, expression

analog = (ROOT / "src/Character23State.cpp").read_text()
for expression in (
    "case 170:",
    "field3138 = (int(velocityX * 100.0));",
    "field313c = (int(velocityY * 100.0));",
    "hitstunFrames = 0x3c;",
    "case 171:",
    "hitstunFrames = 0x5a;",
    "SetTint(0xb0,3);",
    "pendingContextSoundSlot = 0x12;",
    "effect.type = 1;",
    "effect.type = 4;",
    "velocityX = (double)field3138 * 0.01;",
    "velocityY = (double)field313c * 0.01;",
):
    assert expression in analog, expression

renderer = (ROOT / "workbench/character19-slot06/render_partial_slot06.py").read_text()
assert "(0x4a" in renderer
dispatcher = (ROOT / "workbench/character19-slot06/Character19Slot06.cpp").read_text()
assert_selector_case(dispatcher, 170)
assert_selector_case(dispatcher, 171)
assert "Slot06UpdateAirborneHitstunRestore" in dispatcher
assert '#include "Character19Slot06Case4B.inc"' in dispatcher
assert "Slot06UpdateDefeatImpactVelocityRestore" not in dispatcher

print({
    "variants": 2,
    "native_bytes": {"0x4a": 457, "0x4b": 584},
    "state_ids": [170, 171],
    "verified_constants": len(constants),
    "stored_velocity_fields": ["field3138", "field313c"],
})
