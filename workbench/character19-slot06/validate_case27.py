"""Validate the Kanna special knockback effect in selector case 0x27."""
import re
import struct
import sys
from pathlib import Path

ROOT = Path(__file__).resolve().parents[2]
native = (ROOT / ".analysis/kanna-slot06/native.c").read_text()
match = re.search(r"^\s*case 0x27:(.*?)(?=^\s*case )", native, re.M | re.S)
assert match is not None
block = match.group(1)
for expression in (
    "*(double *)(param_1 + 0x46) = *(double *)(param_1 + 0x46) - _DAT_00787d80;",
    "param_1[0xc4e] == 0",
    "*(short *)(param_1 + 0x52) = (short)param_1[0x52] + 0x1e;",
    "param_1[0xc4e] = param_1[0xc4e] + 1;",
    "*(short *)(param_1 + 0x49) = (short)param_1[0x49] + 0x78;",
    "*(undefined1 *)((int)param_1 + 0x2c9) = 0x1f;",
    "FUN_007783b8()",
    "FUN_00407100()",
    "*(undefined8 *)(param_1 + 0x12) = _DAT_00787d38;",
    "*(double *)(param_1 + 0xe) = *(double *)(param_1 + 0xe) + *(double *)(param_1 + 0x12);",
    "*(undefined2 *)(param_1 + 2) = 0x62;",
    "*(undefined2 *)(param_1 + 2) = 0x61;",
):
    assert expression in block, expression

sys.path.insert(0, str(ROOT / "scripts"))
from common import verify_target, target_bytes
pe = verify_target()
constants = {
    0x00787d80: 0.8,
    0x00787c50: 0.5,
    0x00787d40: -2.5,
    0x00787d38: 0.025,
}
for address, expected in constants.items():
    actual = struct.unpack("<d", target_bytes(pe, address, 8))[0]
    assert actual == expected, (hex(address), actual, expected)

source = (ROOT / "workbench/character19-slot06/Character19Slot06.cpp").read_text()
for expression in (
    "case 70:",
    "field3138 == 0",
    "meter = meter + 30",
    "field3138 = field3138 + 1",
    "airActionLockFrames = airActionLockFrames + 0x78",
    "velocityX = 0.5",
    "velocityY = -2.5",
    "gravity = 0.025",
    "reinterpret_cast<unsigned char *>(&soundSlots[49])[1] = 0x1f;",
    "spawn.owner = 0;",
    "spawn.type = 0;",
    "spawn.group = 2;",
    "spawn.layer = 1;",
    "contextOwner->EmitEffect(&spawn);",
    "Slot06RoundToNearestEven(positionX)",
    "Slot06RoundToNearestEven(positionY)",
):
    assert expression in source, expression

def round_nearest_even(value):
    integral = int(value)
    fraction = value - integral
    if fraction > 0.5 or (fraction == 0.5 and integral % 2 != 0):
        return integral + 1
    if fraction < -0.5 or (fraction == -0.5 and integral % 2 != 0):
        return integral - 1
    return integral

for value, expected in [
    (1.4,1),(1.5,2),(2.5,2),(3.5,4),
    (-1.4,-1),(-1.5,-2),(-2.5,-2),(-3.5,-4),
]:
    assert round_nearest_even(value) == expected

print({
    "selector_case":"0x27",
    "state_id":70,
    "native_bytes":480,
    "verified_constants":len(constants),
    "rounding":"nearest-even",
    "effect": "Context::EmitEffect with rounded character position",
})
