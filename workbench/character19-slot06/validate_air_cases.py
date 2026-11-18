"""Validate the seven airborne variants against the pinned native decompilation."""
import re
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
    if not match:
        continue
    try:
        value = int(match.group(1), 0)
    except ValueError:
        continue
    starts.append((index, value))

blocks = {}
for position, (start, value) in enumerate(starts):
    if 0x0B <= value <= 0x11:
        end = starts[position + 1][0] if position + 1 < len(starts) else len(lines)
        blocks[value] = lines[start:end]

assert set(blocks) == set(range(0x0B, 0x12)), sorted(blocks)

def section(block, begin, end):
    first = next(i for i, line in enumerate(block) if begin in line)
    last = next(i for i in range(first + 1, len(block)) if end in block[i])
    return block[first:last]

# The input/recovery state machine and frame-timer tail are byte-for-byte
# identical in all seven native branches. Only launch and acceleration
# parameters vary.
input_sections = [
    section(block, "param_1[0xc50] = param_1[0xc50] + 1;",
            "if ((*(short *)((int)param_1 + 10) ==")
    for block in blocks.values()
]
timer_sections = [
    section(block, "*(short *)(param_1 + 3) =",
            "break;")
    for block in blocks.values()
]
assert all(x == input_sections[0] for x in input_sections[1:])
assert all(x == timer_sections[0] for x in timer_sections[1:])

expected = {
    0x0B: (3, 0.0, -3.5, 2, "gravity"),
    0x0C: (3, 1.5, -2.5, 2, "gravity"),
    0x0D: (2, -1.5, -2.5, 1, "gravity"),
    0x0E: (3, 2.0, -0.5, 2, "fixed-0.01"),
    0x0F: (3, 1.5, -0.5, 2, "gravity"),
    0x10: (2, -2.0, -0.5, 1, "fixed-0.01"),
    0x11: (2, -1.5, -0.5, 1, "gravity"),
}
configs = {
    0x0B: (3, 0.0, -3.5, 2, 0),
    0x0C: (3, 1.5, -2.5, 2, 0),
    0x0D: (2, -1.5, -2.5, 1, 0),
    0x0E: (3, 2.0, -0.5, 2, 1),
    0x0F: (3, 1.5, -0.5, 2, 0),
    0x10: (2, -2.0, -0.5, 1, 1),
    0x11: (2, -1.5, -0.5, 1, 0),
}
renderer = (ROOT / "workbench/character19-slot06/render_partial_slot06.py").read_text()
for case, config in expected.items():
    block = blocks[case]
    assert f"case 0x{case:x}:" in block[0]
    launch_frame, vx, vy, acceleration_frame, acceleration = config
    assert f"== {launch_frame})" in "\n".join(block)
    assert f"= _DAT_" in "\n".join(block)
    assert (f"0x{case:02x}, ({launch_frame}, {vx}, {vy}, "
            f"{acceleration_frame}, {1 if acceleration == 'fixed-0.01' else 0})") in renderer
    print(f"case 0x{case:02x}: {config}")

air_source = (ROOT / "workbench/character19-slot06/Character19Slot06Cases.cpp").read_text()
assert "Slot06TryAirAction" not in air_source
assert "Slot06UpdateAirMovement" not in air_source
for case in range(0x0b, 0x12):
    body = (ROOT / f"workbench/character19-slot06/Character19Slot06Case{case:02X}.inc").read_text()
    assert "airActionCount < 2" in body
    assert "field015c < 3" in body
    assert "inputY == -1" in body
    assert "inputY == 1" in body
    assert "reinterpret_cast<unsigned char *>(&soundSlots[49])[0] = 0;" in body
    assert "reinterpret_cast<unsigned char *>(&soundSlots[49])[1] = 9;" in body
    assert "timing.frameDuration" in body
    assert "timing.animationFrameCount" in body
    assert "Slot06TryAirAction" not in body
    assert "Slot06UpdateAirMovement" not in body
    assert "if (0)" not in body and "if (1)" not in body
    if case in (0x0e, 0x10):
        assert "velocityY = velocityY + 0.01;" in body
        assert "velocityY = velocityY + gravity;" not in body
    else:
        assert "velocityY = velocityY + gravity;" in body
        assert "velocityY = velocityY + 0.01;" not in body

# The five legacy aerial state handlers now live inside the common native
# dispatcher and reuse its one PatternSequence frame-timing snapshot.
dispatcher = (ROOT / "workbench/character19-slot06/Character19Slot06.cpp").read_text()
helper_source = (ROOT / "workbench/character19-slot06/Character19Slot06Cases.cpp").read_text()
legacy_cases = {
    0x03: ("gravity = 0.045;", "velocityY = -2.5;"),
    0x04: ("gravity = 0.045;", "velocityX = 1.5;"),
    0x05: ("gravity = 0.045;", "velocityX = -1.5;"),
    0x08: ("velocityY = velocityY + gravity;", "field3140 = field3140 + 1;"),
    0x09: ("velocityY > 0.4", "velocityX = velocityX * 0.3;"),
}
for case, expressions in legacy_cases.items():
    body = (ROOT / f"workbench/character19-slot06/Character19Slot06Case{case:02X}.inc").read_text()
    assert f'#include "Character19Slot06Case{case:02X}.inc"' in dispatcher
    assert "timing.frameDuration" in body
    assert "timing.animationFrameCount" in body
    assert "struct FrameTiming" not in body
    assert "patterns[" not in body
    for expression in expressions:
        assert expression in body, (hex(case), expression)
    assert f"Slot06Case{case:02X}" not in helper_source
    print(f"selector 0x{case:02x}: inlined shared-frame body ({len(body)} source bytes)")

print({
    "native_variants": len(blocks),
    "shared_input_lines": len(input_sections[0]),
    "shared_timer_lines": len(timer_sections[0]),
    "launch_variants": len(expected),
    "state_ids": list(range(14, 21)),
})
