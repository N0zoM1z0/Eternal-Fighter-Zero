"""Validate native airborne knockback landing selectors 0x33 and 0x34."""
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
    if value in (0x33, 0x34):
        blocks[value] = lines[i:starts[n + 1][0]]
assert set(blocks) == {0x33, 0x34}

expected = {
    0x33: (467, 85, 0.04, 0, 1),
    0x34: (482, 86, 0.06, 1, 0),
}
for case, (native_size, state, acceleration, gate_first_hit, finish_neutral) in expected.items():
    block = "\n".join(blocks[case])
    assert "param_1[0xc51] == 0" in block
    assert "local_50 = 0x1f0;" in block
    assert "local_34 = 0;" in block
    assert "local_33 = 0;" in block
    assert "local_54 = 1;" in block
    assert "local_3c = (char)param_1[0x14];" in block
    assert "(**(code **)(*param_1 + 0x24))();" in block
    assert "param_1[0xc51] = 1;" in block
    assert "*(double *)(param_1 + 0xe) = *(double *)(param_1 + 0xe) + " in block
    assert "*(short *)(param_1 + 0x52) = (short)param_1[0x52] + 0x1e;" in block
    assert "*(undefined1 *)((int)param_1 + 0x2c9) = 0x21;" in block
    assert "*(undefined2 *)(param_1 + 2) = 0x61;" in block
    assert "*(undefined2 *)(param_1 + 2) = 0x62;" in block
    if gate_first_hit:
        assert "param_1[0xc4e] == 0" in block
        assert "param_1[0xc4e] = param_1[0xc4e] + 1;" in block
        assert "*(undefined2 *)((int)param_1 + 10) = 0;" in block
    else:
        assert "param_1[0xc4e] == 0" not in block
        assert "*(undefined2 *)(param_1 + 2) = 0;" in block
        assert "FUN_0040e630();" in block
    print(f"case 0x{case:02x}: native={native_size}, state={state}, acceleration={acceleration}, gate={gate_first_hit}, finish-neutral={finish_neutral}")

sys.path.insert(0, str(ROOT / "scripts"))
from common import verify_target, target_bytes
pe = verify_target()
constants = {
    0x00787d88: 30.0,
    0x00787cf8: 0.04,
    0x00787da8: 0.06,
}
for address, expected_value in constants.items():
    actual = struct.unpack("<d", target_bytes(pe, address, 8))[0]
    assert actual == expected_value, (hex(address), actual, expected_value)

source = (ROOT / "workbench/character19-slot06/Character19Slot06Cases.cpp").read_text()
assert "Slot06UpdateAirborneKnockbackLanding" not in source
dispatcher = (ROOT / "workbench/character19-slot06/Character19Slot06.cpp").read_text()
for case, (native_size, state, acceleration, gate_first_hit, finish_neutral) in expected.items():
    fragment = (ROOT / f"workbench/character19-slot06/Character19Slot06Case{case:02X}.inc").read_text()
    for expression in (
        "if (field3144 == 0)",
        "spawn.type = 0x1f0;",
        "spawn.owner = 1;",
        "spawn.group = 0;",
        "spawn.layer = 0;",
        "spawn.flag0018 = (unsigned char)facing;",
        "EmitLocalEffect(&spawn);",
        "field3144 = 1;",
        "if (field0120 != 0)",
        "field0118 = field0118 - 30.0;",
        "pendingContextSoundSlot = 0x21;",
        "velocityX = knockbackVelocityX;",
        "velocityY = knockbackVelocityY;",
        "meter = meter + 30;",
        f"velocityY = velocityY + {acceleration};",
        "field000c = field000c + 1;",
        "if (timing.frameDuration <= field000c)",
        "if (timing.animationFrameCount <= field000a)",
        "if ((positionY + velocityY) >= 0.0)",
        "positionY = 0.0;",
        "field0008 = 0x61;",
        "field0008 = 0x62;",
    ):
        assert expression in fragment, (hex(case), expression)
    if gate_first_hit:
        assert "if (field3138 == 0)" in fragment
        assert "field3138 = field3138 + 1;" in fragment
    else:
        assert "if (field3138 == 0)" not in fragment
        assert "field3138 = field3138 + 1;" not in fragment
    if finish_neutral:
        assert "field0008 = 0;" in fragment
        assert "FaceOpponent();" in fragment
        assert "field000a = 0;" not in fragment
    else:
        assert "field000a = 0;" in fragment
        assert "FaceOpponent();" not in fragment
        assert "field0008 = 0;" not in fragment
    assert f'#include "Character19Slot06Case{case:02X}.inc"' in dispatcher
assert "Slot06UpdateAirborneKnockbackLanding(" not in dispatcher

analog = (ROOT / "src/Character23State.cpp").read_text()
for expression in (
    "case 85:",
    "case 86:",
    "effect.type = 0x1f0;",
    "field3144 == 0",
    "pendingContextSoundSlot = 0x21;",
    "velocityY = velocityY + 0.04;",
    "velocityY = velocityY + 0.06;",
    "field3138 == 0",
):
    assert expression in analog, expression

print({"verified_constants": len(constants), "state_ids": [85,86]})
