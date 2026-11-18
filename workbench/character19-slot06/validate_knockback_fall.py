"""Validate the six native hit-knockback airborne fall variants."""
import re
import struct
import sys
from pathlib import Path

ROOT = Path(__file__).resolve().parents[2]
native_path = ROOT / ".analysis/kanna-slot06/native.c"
if not native_path.is_file():
    raise SystemExit("missing target-attested .analysis/kanna-slot06/native.c")

lines = native_path.read_text().splitlines()
starts = []
for index, line in enumerate(lines):
    match = re.match(r"^\s*case\s+([^:]+):", line)
    if match:
        try:
            value = int(match.group(1), 0)
        except ValueError:
            continue
        starts.append((index, value))

wanted = {0x1C, 0x1D, 0x1E, 0x1F, 0x20, 0x28}
blocks = {}
for position, (start, value) in enumerate(starts):
    if value in wanted:
        end = starts[position + 1][0] if position + 1 < len(starts) else len(lines)
        blocks[value] = lines[start:end]
assert set(blocks) == wanted

expected = {
    0x1C: (-2.0, 1, 0.75, 0.032, 511, 59),
    0x1D: (-4.0, 1, 0.75, 0.032, 511, 60),
    0x1E: (-6.0, 1, 0.75, 0.032, 511, 61),
    0x1F: (0.0, 0, 0.75, 0.032, 439, 62),
    0x20: (0.0, 0, 0.0, 0.032, 427, 63),
    0x28: (0.0, 0, 0.0, 0.072, 427, 71),
}
renderer = (ROOT / "workbench/character19-slot06/render_partial_slot06.py").read_text()
for case, (lower, clamp, blend, gravity, native_size, state) in expected.items():
    block = "\n".join(blocks[case])
    assert len(blocks[case]) == (50 if case <= 0x1E else (42 if case == 0x1F else 41))
    assert f"0x{case:02x}, ({lower}, {clamp}, {blend}, {gravity})" in renderer
    assert "*(short *)(param_1 + 0x52) = (short)param_1[0x52] + 0x1e;" in block
    assert "*(undefined2 *)(param_1 + 2) = 0x62;" in block
    assert "*(undefined2 *)(param_1 + 2) = 0x61;" in block
    if clamp:
        assert "_DAT_00787d68 < *(double *)(param_1 + 0xe)" in block
        lower_address = {0x1C:"70",0x1D:"58",0x1E:"50"}[case]
        assert f"_DAT_00787d{lower_address} <= *(double *)(param_1 + 0xe)" in block
    else:
        assert "_DAT_00787d68 < *(double *)(param_1 + 0xe)" not in block
    if blend == 0.0:
        assert "*(undefined8 *)(param_1 + 0xe) = *(undefined8 *)(param_1 + 0x32);" in block
    else:
        assert "*(double *)(param_1 + 0xe) * _DAT_00787d78 +" in block
    print(f"case 0x{case:02x}: lower={lower}, clamp={clamp}, blend={blend}, gravity={gravity}, bytes={native_size}, state={state}")

sys.path.insert(0, str(ROOT / "scripts"))
from common import verify_target, target_bytes
pe = verify_target()
constants = {
    0x00787d80: 0.8,
    0x00787d78: 0.75,
    0x00787d70: -2.0,
    0x00787d68: -0.5,
    0x00787d58: -4.0,
    0x00787d50: -6.0,
    0x00787d60: 0.032,
    0x00787d30: 0.072,
}
for address, expected_value in constants.items():
    actual = struct.unpack("<d", target_bytes(pe, address, 8))[0]
    assert actual == expected_value, (hex(address), actual, expected_value)

source = (ROOT / "workbench/character19-slot06/Character19Slot06Cases.cpp").read_text()
for expression in (
    "field0118 = field0118 - 0.8",
    "meter = meter + 30",
    "velocityX = knockbackVelocityX",
    "if (velocityBlend == 0.0)",
    "velocityY = velocityY * velocityBlend + knockbackVelocityY",
    "if (clampVerticalVelocity)",
    "if (minimumVerticalVelocity <= velocityY)",
    "gravity = gravityValue",
    "((velocityY < 0.0) != (velocityY == 0.0))",
    "if (knockdownOnLanding == 0)",
):
    assert expression in source, expression

print({
    "native_variants": len(blocks),
    "verified_constants": len(constants),
    "state_ids": [59, 60, 61, 62, 63, 71],
    "clamp_modes": {"0x1c-0x1e":"lower and upper", "0x1f/0x20/0x28":"unclamped"},
})
