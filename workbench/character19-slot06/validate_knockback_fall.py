"""Validate Kanna's four hit-knockback airborne fall variants."""
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

blocks = {}
for position, (start, value) in enumerate(starts):
    if 0x1C <= value <= 0x1F:
        end = starts[position + 1][0] if position + 1 < len(starts) else len(lines)
        blocks[value] = lines[start:end]
assert set(blocks) == set(range(0x1C, 0x20))

expected = {
    0x1C: (-2.0, 1, 511, 59),
    0x1D: (-4.0, 1, 511, 60),
    0x1E: (-6.0, 1, 511, 61),
    0x1F: (0.0, 0, 439, 62),
}
renderer = (ROOT / "workbench/character19-slot06/render_partial_slot06.py").read_text()
for case, (lower, clamp, size, state) in expected.items():
    block = "\n".join(blocks[case])
    assert len(blocks[case]) == (50 if case != 0x1F else 42)
    assert f"0x{case:02x}, ({lower}, {clamp})" in renderer
    assert "*(short *)(param_1 + 0x52) = (short)param_1[0x52] + 0x1e;" in block
    assert "*(undefined8 *)(param_1 + 0x12) = _DAT_00787d60;" in block
    assert "*(undefined2 *)(param_1 + 2) = 0x62;" in block
    assert "*(undefined2 *)(param_1 + 2) = 0x61;" in block
    if clamp:
        assert "_DAT_00787d68 < *(double *)(param_1 + 0xe)" in block
        assert f"_DAT_00787d{ {0x1C:'70',0x1D:'58',0x1E:'50'}[case] } <= *(double *)(param_1 + 0xe)" in block
    else:
        assert "_DAT_00787d68 < *(double *)(param_1 + 0xe)" not in block
    print(f"case 0x{case:02x}: lower clamp {lower}, clamp={clamp}, native bytes={size}, state={state}")

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
}
for address, expected_value in constants.items():
    actual = struct.unpack("<d", target_bytes(pe, address, 8))[0]
    assert actual == expected_value, (hex(address), actual, expected_value)

source = (ROOT / "workbench/character19-slot06/Character19Slot06Cases.cpp").read_text()
for expression in (
    "field0118 = field0118 - 0.8",
    "meter = meter + 30",
    "velocityX = knockbackVelocityX",
    "velocityY = velocityY * 0.75 + knockbackVelocityY",
    "gravity = 0.032",
    "((velocityY < 0.0) != (velocityY == 0.0))",
    "if (knockdownOnLanding == 0)",
):
    assert expression in source, expression

print({
    "native_variants": len(blocks),
    "verified_constants": len(constants),
    "state_ids": [59, 60, 61, 62],
    "clamp_modes": {"0x1c-0x1e":"lower and upper", "0x1f":"unclamped"},
})
