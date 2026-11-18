"""Validate Kanna's native ground-recovery selectors 0x29-0x2b."""
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
    if 0x29 <= value <= 0x2B:
        blocks[value] = lines[i:starts[n + 1][0]]
assert set(blocks) == {0x29, 0x2A, 0x2B}

expected = {
    0x29: (341, 72, 0),
    0x2A: (341, 73, 0),
    0x2B: (317, 74, 1),
}
renderer = (ROOT / "workbench/character19-slot06/render_partial_slot06.py").read_text()
for case, (native_size, state, force_standing) in expected.items():
    block = "\n".join(blocks[case])
    assert f"(0x{case:02x}, {force_standing})" in renderer
    assert "*(double *)(param_1 + 0x46) = *(double *)(param_1 + 0x46) - _DAT_00787d80;" in block
    assert "*(undefined1 *)(param_1 + 0x56) = 0;" in block
    assert "*(double *)(param_1 + 0xc) = _DAT_007872f8;" in block
    assert "*(double *)(param_1 + 0xe) = _DAT_007872f8;" in block
    assert "*(double *)(param_1 + 0x2e) =" in block
    assert "*(short *)(param_1 + 3) = (short)param_1[3] + 1;" in block
    assert "*(short *)((int)param_1 + 10) = *(short *)((int)param_1 + 10) + 1;" in block
    if force_standing:
        assert "*(undefined2 *)(param_1 + 2) = 3;" in block
        assert "*(undefined2 *)(param_1 + 2) = 7;" not in block
        assert "*(char *)((int)param_1 + 0x189)" not in block
    else:
        assert "*(undefined2 *)(param_1 + 2) = 7;" in block
        assert "*(char *)((int)param_1 + 0x189) == '\\x01'" in block
        assert "*(undefined2 *)(param_1 + 2) = 3;" in block
    print(f"case 0x{case:02x}: native={native_size}, state={state}, force-state-3={force_standing}")

sys.path.insert(0, str(ROOT / "scripts"))
from common import verify_target, target_bytes
pe = verify_target()
constants = {
    0x00787d80: 0.8,
    0x00787c10: 20.0,
    0x00787da0: 639.0,
    0x007875c0: 1.0,
    0x00787d28: 0.25,
}
for address, expected_value in constants.items():
    actual = struct.unpack("<d", target_bytes(pe, address, 8))[0]
    assert actual == expected_value, (hex(address), actual, expected_value)

source = (ROOT / "workbench/character19-slot06/Character19Slot06Cases.cpp").read_text()
for expression in (
    "void Character19::Slot06UpdateGroundRecovery",
    "dashMomentumFlag = 0;",
    "velocityX = 0.0;",
    "velocityY = 0.0;",
    "positionX - 20.0 < 0.0",
    "639.0 <= positionX + 20.0",
    "outgoingPushbackVelocityX =",
    "(*opponentSlot)->positionX < 0.0",
    "(*opponentSlot)->positionX < 0.0) * 0.25",
    "field000c = field000c + 1;",
    "field0008 = 7;",
    "forceStandingState || (inputY == 1)",
    "field0008 = 3;",
):
    assert expression in source, expression

# Native state selection is inputY==1 for 0x29/0x2a and unconditional
# state 3 for 0x2b. Boundary predicates retain their strict/inclusive edges.
def edge(x):
    return x - 20.0 < 0.0 or 639.0 <= x + 20.0
assert edge(19.999)
assert not edge(20.0)
assert not edge(618.999)
assert edge(619.0)
print({"variants": 3, "verified_constants": len(constants), "state_ids": [72,73,74]})
