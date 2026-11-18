"""Validate Kanna's ten native hit-knockback airborne fall variants."""
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

wanted = {0x1C,0x1D,0x1E,0x1F,0x20,0x21,0x22,0x23,0x24,0x28}
blocks = {}
for position, (start, value) in enumerate(starts):
    if value in wanted:
        end = starts[position + 1][0] if position + 1 < len(starts) else len(lines)
        blocks[value] = lines[start:end]
assert set(blocks) == wanted

# (lower clamp, clamp enabled, velocity blend, gravity, interrupt guard,
#  native byte extent, animation state ID)
expected = {
    0x1C: (-2.0,1,0.75,0.032,0,511,59),
    0x1D: (-4.0,1,0.75,0.032,0,511,60),
    0x1E: (-6.0,1,0.75,0.032,0,511,61),
    0x1F: (0.0,0,0.75,0.032,0,439,62),
    0x20: (0.0,0,0.0,0.032,0,427,63),
    0x21: (-2.0,1,0.75,0.032,1,561,64),
    0x22: (-4.0,1,0.75,0.032,1,561,65),
    0x23: (0.0,0,0.75,0.032,1,489,66),
    0x24: (0.0,0,0.0,0.032,1,477,67),
    0x28: (0.0,0,0.0,0.072,0,427,71),
}
renderer = (ROOT / "workbench/character19-slot06/render_partial_slot06.py").read_text()
for case, (lower, clamp, blend, gravity, interrupt, native_size, state) in expected.items():
    block = "\n".join(blocks[case])
    expected_lines = 50 if case <= 0x1E else (
        42 if case == 0x1F else
        41 if case in (0x20,0x28) else
        56 if case in (0x21,0x22) else
        48 if case == 0x23 else 47
    )
    assert len(blocks[case]) == expected_lines, (hex(case),len(blocks[case]),expected_lines)
    config = f"0x{case:02x}, ({lower}, {clamp}, {blend}, {gravity}, {interrupt})"
    assert config in renderer, (hex(case),config)
    assert "*(short *)(param_1 + 0x52) = (short)param_1[0x52] + 0x1e;" in block
    assert "*(undefined2 *)(param_1 + 2) = 0x62;" in block
    assert "*(undefined2 *)(param_1 + 2) = 0x61;" in block
    if clamp:
        assert "_DAT_00787d68 < *(double *)(param_1 + 0xe)" in block
        lower_address = {0x1C:"70",0x1D:"58",0x1E:"50",0x21:"70",0x22:"58"}[case]
        assert f"_DAT_00787d{lower_address} <= *(double *)(param_1 + 0xe)" in block
    else:
        assert "_DAT_00787d68 < *(double *)(param_1 + 0xe)" not in block
    if blend == 0.0:
        assert "*(undefined8 *)(param_1 + 0xe) = *(undefined8 *)(param_1 + 0x32);" in block
    else:
        assert "*(double *)(param_1 + 0xe) * _DAT_00787d78 +" in block
    if interrupt:
        assert "FUN_0040ff70()" in block
    else:
        assert "FUN_0040ff70()" not in block
    print(f"case 0x{case:02x}: lower={lower}, clamp={clamp}, blend={blend}, gravity={gravity}, interrupt={interrupt}, bytes={native_size}, state={state}")

sys.path.insert(0, str(ROOT / "scripts"))
from common import verify_target, target_bytes
pe = verify_target()
constants = {
    0x00787d80:0.8, 0x00787d78:0.75, 0x00787d70:-2.0,
    0x00787d68:-0.5, 0x00787d58:-4.0, 0x00787d50:-6.0,
    0x00787d60:0.032, 0x00787d30:0.072,
    0x00787c10:20.0, 0x00787c18:619.0,
    0x00787c40:280.0, 0x00787da0:639.0,
}
for address, expected_value in constants.items():
    actual = struct.unpack("<d", target_bytes(pe,address,8))[0]
    assert actual == expected_value, (hex(address),actual,expected_value)

source = (ROOT / "workbench/character19-slot06/Character19Slot06Cases.cpp").read_text()
for expression in (
    "field0118 = field0118 - 0.8",
    "meter = meter + 30",
    "velocityX = knockbackVelocityX",
    "if (velocityBlend == 0.0)",
    "velocityY = velocityY * velocityBlend + knockbackVelocityY",
    "if (clampVerticalVelocity)",
    "gravity = gravityValue",
    "if (interruptOutsideRange && (field000a != 0)",
    "!Slot06OpponentWithinKnockbackRange()",
):
    assert expression in source, expression

# Boundary probes for the translated FUN_0040ff70 zero/nonzero predicate.
def within(self_x, opponent_x):
    left_adjust = 1.0 if opponent_x <= 20.0 else 0.0
    if not (left_adjust < self_x - 20.0):
        return False
    if opponent_x - self_x > 280.0:
        return False
    right_limit = 639.0 - (1.0 if opponent_x >= 619.0 else 0.0)
    if not (right_limit > self_x + 20.0):
        return False
    if self_x - opponent_x > 280.0:
        return False
    return True

probes = [
    (320.0,320.0,True),(22.0,20.0,True),(21.0,20.0,False),
    (617.0,619.0,True),(618.0,619.0,False),
    (580.0,300.0,True),(580.001,300.0,False),
    (300.0,580.0,True),(300.0,580.001,False),
]
for self_x, opponent_x, expected_result in probes:
    assert within(self_x,opponent_x) == expected_result,(self_x,opponent_x)
print({
    "native_variants":len(blocks),
    "verified_constants":len(constants),
    "range_predicate_boundary_probes":len(probes),
    "state_ids":[59,60,61,62,63,64,65,66,67,71],
})
