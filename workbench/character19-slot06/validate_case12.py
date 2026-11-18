"""Validate the isolated native selector case 0x12 / animation state 47."""
import re
import struct
import sys
from pathlib import Path

ROOT = Path(__file__).resolve().parents[2]
native = (ROOT / ".analysis/kanna-slot06/native.c").read_text()
match = re.search(
    r"^\s*case 0x12:(.*?)(?=^\s*case )",
    native,
    re.M | re.S,
)
assert match is not None
block = match.group(1)
for expression in (
    "*(double *)(param_1 + 0xc) = _DAT_007872f8;",
    "*(undefined8 *)(param_1 + 0x12) = _DAT_00787dd8;",
    "*(double *)(param_1 + 0xe) = *(double *)(param_1 + 0xe) + *(double *)(param_1 + 0x12);",
    "*(undefined1 *)((int)param_1 + 0x2c9) = 7;",
    "*(double *)(param_1 + 10) = _DAT_007872f8;",
    "*(double *)(param_1 + 0xe) = _DAT_007872f8;",
    "*(double *)(param_1 + 0x12) = _DAT_007872f8;",
    "*(short *)((int)param_1 + 10) = *(short *)((int)param_1 + 10) + -2;",
    "*(short *)((int)param_1 + 10) = *(short *)((int)param_1 + 10) + -1;",
):
    assert expression in block, expression

sys.path.insert(0, str(ROOT / "scripts"))
from common import verify_target, target_bytes
pe = verify_target()
gravity = struct.unpack("<d", target_bytes(pe, 0x00787dd8, 8))[0]
assert gravity == 0.035

source = (ROOT / "workbench/character19-slot06/Character19Slot06.cpp").read_text()
for expression in (
    "case 47:",
    "gravity = 0.035;",
    "velocityY = velocityY + gravity;",
    "(positionY + velocityY) > 0.0",
    "field000a < 2",
    "field000a = 2;",
    "reinterpret_cast<unsigned char *>(&soundSlots[49])[1] = 7;",
    "field000a = field000a - 2;",
    "field000a = field000a - 1;",
):
    assert expression in source, expression

print({
    "selector_case": "0x12",
    "state_id": 47,
    "native_code_bytes": 304,
    "gravity": gravity,
    "strict_ground_crossing": True,
    "marker_byte_offset": "0x2c9",
})
