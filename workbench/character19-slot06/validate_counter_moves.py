"""Validate the five native counter-movement variants and their parameters."""
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
    if 0x13 <= value <= 0x17:
        end = starts[position + 1][0] if position + 1 < len(starts) else len(lines)
        blocks[value] = lines[start:end]
assert set(blocks) == set(range(0x13, 0x18))

def normalize(block):
    text = "\n".join(block)
    text = re.sub(r"case 0x[0-9a-f]+:", "case X:", text)
    text = re.sub(r"local_[0-9a-f]+", "local_tmp", text)
    for name in ("_DAT_00787db0", "_DAT_00787d98", "_DAT_00787d90"):
        text = text.replace(name, "_LAUNCH_SCALE_")
    for name in ("_DAT_00787c28", "_DAT_00787c10", "_DAT_00787d88"):
        text = text.replace(name, "_FIELD_DECAY_")
    text = re.sub(r"\+ (?:10|0xf|0x14);", "+ METER_GAIN;", text)
    return text

normalized = [normalize(block) for block in blocks.values()]
assert all(item == normalized[0] for item in normalized[1:])

expected = {
    0x13: (10, -1.1, 10.0),
    0x14: (15, -1.5, 20.0),
    0x15: (20, -1.8, 30.0),
    0x16: (10, -1.1, 10.0),
    0x17: (15, -1.5, 20.0),
}
config_source = (ROOT / "workbench/character19-slot06/render_partial_slot06.py").read_text()
for case, (meter_gain, launch_scale, decay) in expected.items():
    assert len(blocks[case]) == 43
    assert f"0x{case:02x}, ({meter_gain}, {launch_scale}, {decay})" in config_source
    print(f"case 0x{case:02x}: meter +{meter_gain}, launch scale {launch_scale}, field0118 decay {decay}")

# Verify every native constant used by the parameterized source.
sys.path.insert(0, str(ROOT / "scripts"))
from common import verify_target, target_bytes
pe = verify_target()
constants = {
    0x00787db8: 0.6,
    0x00787328: 2.0,
    0x00787c00: 10000.0,
    0x00787db0: -1.1,
    0x00787d98: -1.5,
    0x00787d90: -1.8,
    0x00787c28: 10.0,
    0x00787c10: 20.0,
    0x00787d88: 30.0,
    0x00787da8: 0.06,
    0x00787da0: 639.0,
    0x007875c0: 1.0,
    0x00787300: 0.2,
}
for address, expected_value in constants.items():
    actual = struct.unpack("<d", target_bytes(pe, address, 8))[0]
    assert actual == expected_value, (hex(address), actual, expected_value)

source = (ROOT / "workbench/character19-slot06/Character19Slot06Cases.cpp").read_text()
for expression in (
    "field0118 = field0118 - 0.6",
    "(*opponentSlot)->comboDamageScale / 10000.0",
    "velocityX = velocityX + 0.06",
    "positionX - 20.0 <= 0.0",
    "639.0 <= positionX + 20.0",
    "outgoingPushbackVelocityX",
    "field0008 = 0",
    "if (inputY == 1)",
):
    assert expression in source, expression

print({
    "native_variants": len(blocks),
    "native_lines_per_variant": len(blocks[0x13]),
    "normalized_body_identical": True,
    "verified_constants": len(constants),
    "state_ids": [50, 51, 52, 53, 54],
})
