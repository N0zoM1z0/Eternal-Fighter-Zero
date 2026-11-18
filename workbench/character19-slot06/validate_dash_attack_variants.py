"""Validate the five native dash-attack follow-through selectors 0x4d-0x51."""
import csv
import re
import struct
import subprocess
import sys
from pathlib import Path

from selector_support import assert_selector_case, selector_case_for_state

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
    if 0x4D <= value <= 0x51:
        blocks[value] = lines[i:starts[n + 1][0]]
assert set(blocks) == {0x4D, 0x4E, 0x4F, 0x50, 0x51}

expected = {
    0x4D: (467, 200, 0.06, 1, 2, 5, 0x15, 0, 0, 0),
    0x4E: (587, 201, 0.03, 1, 3, 15, 0x14, 1, 0x1A4, 1),
    0x4F: (434, 202, 0.06, 0, 4, 15, 0x14, 3, 0x1A5, 0),
    0x50: (587, 203, 0.06, 2, 4, 35, 0x23, 6, 0x1A8, 0),
    0x51: (491, 204, 0.03, 1, 1, 5, 0x15, 0, 0, 0),
}
case_rows = {
    int(row["case_index"], 16): row
    for row in csv.DictReader((ROOT / "workbench/character19-slot06/case-map.csv").open())
}
for case, values in expected.items():
    native_size, state, decel, cancel_mode, meter_frame, meter_gain, sound, effect_frame, effect_type, effect_before_cancel = values
    row = case_rows[case]
    assert int(row["native_code_bytes"]) == native_size
    assert [int(x) for x in row["state_ids"].split(";") if x] == [state]
    block = "\n".join(blocks[case])
    for expression in (
        "param_1[0x56]",
        "*(short *)((int)param_1 + 10)",
        "*(double *)(param_1 + 0xc) = *(double *)(param_1 + 0xc) - ",
        "*(short *)(param_1 + 3) = (short)param_1[3] + 1;",
        "*(undefined2 *)(param_1 + 2) = 0;",
        "FUN_0040e630();",
    ):
        assert expression in block, (hex(case), expression)
    if cancel_mode:
        for expression in (
            "*(char *)((int)param_1 + 0x189)",
            "param_1[0x57] < 3",
            "*(undefined2 *)(param_1 + 2) = 4;",
            "*(undefined2 *)(param_1 + 2) = 5;",
            "*(undefined2 *)(param_1 + 2) = 6;",
            "param_1[0x5a] = 0;",
        ):
            assert expression in block, (hex(case), expression)
    else:
        assert "*(char *)((int)param_1 + 0x189)" not in block
    if effect_type:
        assert f"local_50 = {hex(effect_type)};" in block
        assert "local_54 = 1;" in block
        assert "local_34 = 2;" in block
        assert "local_33 = 1;" in block
        assert "local_3c = (char)param_1[0x14];" in block
        assert "(**(code **)(*param_1 + 0x24))();" in block
    meter_literal = str(meter_gain) if meter_gain < 10 else hex(meter_gain)
    assert f"*(short *)(param_1 + 0x52) = (short)param_1[0x52] + {meter_literal};" in block
    assert f"*(short *)((int)param_1 + 10) == {meter_frame}" in block
    if effect_type:
        assert f"*(short *)((int)param_1 + 10) == {effect_frame}" in block
    print(
        f"case 0x{case:02x}: native={native_size}, state={state}, "
        f"deceleration={decel}, cancel={cancel_mode}, meter=+{meter_gain}, "
        f"effect={hex(effect_type) if effect_type else 'none'}"
    )

# The native 0x4e branch emits before checking the cancel input, while 0x50
# checks cancellation first and suppresses its late effect when cancelled.
block_4e = "\n".join(blocks[0x4E])
block_50 = "\n".join(blocks[0x50])
assert block_4e.index("local_50 = 0x1a4;") < block_4e.index("*(char *)((int)param_1 + 0x189)")
assert block_50.index("*(char *)((int)param_1 + 0x189)") < block_50.index("local_50 = 0x1a8;")

# Verify that the local effects use integer-truncated current X/Y, then the
# native ftol helper, with the expected type byte in the spawn record.
def disassemble(start, end):
    return subprocess.run(
        ["objdump", "-D", "-Mintel", f"--start-address={start:#x}",
         f"--stop-address={end:#x}", str(ROOT / "resources/EFZ.exe")],
        cwd=ROOT, check=True, capture_output=True, text=True,
    ).stdout

for case, (start, end, effect_type) in {
    0x4E: (0x006709F8, 0x00670C43, 0x1A4),
    0x4F: (0x00670C43, 0x00670DF5, 0x1A5),
    0x50: (0x00670DF5, 0x00671040, 0x1A8),
}.items():
    text = disassemble(start, end)
    assert f"mov    WORD PTR [ebp-0x4c],0x{effect_type:x}" in text
    assert "fld    QWORD PTR [ecx+0x20]" in text
    assert "fld    QWORD PTR [edx+0x28]" in text
    assert text.count("call   0x7783b8") >= 2

sys.path.insert(0, str(ROOT / "scripts"))
from common import verify_target, target_bytes
pe = verify_target()
constants = {0x00787DA8: 0.06, 0x00787CA0: 0.03}
for address, expected_value in constants.items():
    actual = struct.unpack("<d", target_bytes(pe, address, 8))[0]
    assert actual == expected_value, (hex(address), actual, expected_value)

helper_source = (ROOT / "workbench/character19-slot06/Character19Slot06Cases.cpp").read_text()
assert "Slot06UpdateDashAttack(" not in helper_source
dispatcher = (ROOT / "workbench/character19-slot06/Character19Slot06.cpp").read_text()
for case, values in expected.items():
    native_size, state, decel, cancel_mode, meter_frame, meter_gain, sound, effect_frame, effect_type, effect_before_cancel = values
    fragment = (ROOT / f"workbench/character19-slot06/Character19Slot06Case{case:02X}.inc").read_text()
    assert f"velocityX = velocityX - {decel};" in fragment
    assert "if (dashMomentumFlag == 0)" in fragment
    assert "velocityY = 0.0;" in fragment
    assert f"field000a == {meter_frame}" in fragment
    assert f"meter = meter + {meter_gain};" in fragment
    assert f"pendingContextSoundSlot = (char){sound};" in fragment
    assert "remainingHitCount = 1;" in fragment
    assert "timing.frameDuration" in fragment
    assert "timing.animationFrameCount" in fragment
    if cancel_mode:
        predicate = "attackCollisionResult > 1" if cancel_mode == 1 else "attackCollisionResult == 3"
        assert "int cancel = 0;" in fragment
        assert "(inputY == -1)" in fragment
        assert "(field000a > 0)" in fragment
        assert "(field015c < 3)" in fragment
        assert predicate in fragment
        assert "field0008 = 4;" in fragment
        assert "field0008 = 5;" in fragment
        assert "field0008 = 6;" in fragment
        assert "attackCollisionResult = 0;" in fragment
        assert "ResetPose();" in fragment
    else:
        assert "int cancel = 0;" not in fragment
        assert "field0008 = 4;" not in fragment
    if effect_type:
        assert f"if ((field000a == {effect_frame}) && (field000c == 0))" in fragment
        assert f"spawn.type = {hex(effect_type)};" in fragment
        assert "spawn.owner = 1;" in fragment
        assert "spawn.x = (double)(int)positionX;" in fragment
        assert "spawn.y = (double)(int)positionY;" in fragment
        assert "spawn.flag0018 = (unsigned char)facing;" in fragment
        assert "spawn.group = 2;" in fragment
        assert "spawn.layer = 1;" in fragment
        assert "EmitLocalEffect(&spawn);" in fragment
    else:
        assert "spawn.type" not in fragment
    if case in (0x51, 0x52):
        assert "if (inputY == 1)" in fragment
        assert "field0008 = 3;" in fragment
    else:
        assert "field0008 = 3;" not in fragment
    assert f'#include "Character19Slot06Case{case:02X}.inc"' in dispatcher

# The native 0x4e branch emits before checking the cancel input, while 0x50
# checks cancellation first and suppresses its late effect when cancelled.
fragment_4e = (ROOT / "workbench/character19-slot06/Character19Slot06Case4E.inc").read_text()
fragment_50 = (ROOT / "workbench/character19-slot06/Character19Slot06Case50.inc").read_text()
assert fragment_4e.index("spawn.type = 0x1a4;") < fragment_4e.index("int cancel = 0;")
assert fragment_50.index("int cancel = 0;") < fragment_50.index("spawn.type = 0x1a8;")

analog15 = (ROOT / "src/Character15State.cpp").read_text()
for expression in (
    "case 200:",
    "dashMomentumFlag == 1",
    "velocityX = velocityX - 0.03;",
    "case 201:",
    "case 202:",
    "case 203:",
    "case 204:",
    "pendingContextSoundSlot = 0x15;",
):
    assert expression in analog15, expression

assert "ResetLocalEffectSpawn(&spawn);" in dispatcher
for state in (200, 201, 202, 203, 204, 205):
    assert_selector_case(dispatcher, state)
assert dispatcher.count("Slot06UpdateDashAttack(") == 0
print({"variants": 6, "native_bytes": [467, 587, 434, 587, 491, 611], "state_ids": [200,201,202,203,204,205], "verified_constants": len(constants)})
