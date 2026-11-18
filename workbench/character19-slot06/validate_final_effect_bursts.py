"""Validate the final Kanna Slot06 effect pair and trail burst selectors 0x6e/0x6f."""
import csv
import re
import struct
import subprocess
import sys
from pathlib import Path

from selector_support import assert_selector_case, selector_case_for_state

ROOT = Path(__file__).resolve().parents[2]
lines = (ROOT / ".analysis/kanna-slot06/native.c").read_text().splitlines()
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
    if value in (0x6E, 0x6F):
        blocks[value] = lines[i:starts[n + 1][0]]
assert set(blocks) == {0x6E, 0x6F}

expected = {
    0x6E: (500, 266, 0x006742E1),
    0x6F: (524, 267, 0x006744D5),
}
rows = {
    int(row["case_index"], 16): row
    for row in csv.DictReader((ROOT / "workbench/character19-slot06/case-map.csv").open())
}
for case, (size, state, entry) in expected.items():
    row = rows[case]
    assert int(row["native_entry"], 16) == entry
    assert int(row["native_code_bytes"]) == size
    assert [int(x) for x in row["state_ids"].split(";") if x] == [state]

pair = "\n".join(blocks[0x6E])
for expression in (
    "FUN_0040f1e0();",
    "*(short *)((int)param_1 + 10) == 7",
    "local_50 = 0x195;",
    "local_4c = (double)(iVar4 + (char)param_1[0x14] * 0x23);",
    "local_44 = (double)(iVar4 + -0x3f);",
    "local_34 = 2;",
    "local_33 = 1;",
    "local_38 = (uint)((char)param_1[0x14] != '\\x01');",
    "local_3c = (char)param_1[0x14];",
    "local_2c = 0;",
    "local_54 = 1;",
    "(**(code **)(*param_1 + 0x24))();",
    "*(short *)((int)param_1 + 10) == 8",
    "local_50 = 0x196;",
    "local_4c = (double)(iVar4 + (char)param_1[0x14] * 0x50);",
    "*(short *)(param_1 + 0x52) = (short)param_1[0x52] + 0x2d;",
    "*(undefined1 *)(param_1 + 0xb2) = 2;",
    "*(short *)(param_1 + 3) = (short)param_1[3] + 1;",
    "*(undefined2 *)(param_1 + 2) = 0;",
):
    assert expression in pair, expression
assert "param_1[0x5a] = 0;" not in pair

trail = "\n".join(blocks[0x6F])
for expression in (
    "FUN_0040f1e0();",
    "FUN_004109d0();",
    "*(double *)(param_1 + 0x46) = *(double *)(param_1 + 0x46) - _DAT_00787c30;",
    "*(double *)(param_1 + 0x46) = *(double *)(param_1 + 0x46) - _DAT_00787c70;",
    "local_50 = 0x21;",
    "local_28 = 0xb;",
    "local_34 = 2;",
    "local_33 = 1;",
    "FUN_00407100();",
    "*(short *)((int)param_1 + 10) == 7",
    "local_50 = 0x1ad;",
    "local_4c = (double)(iVar4 + (char)param_1[0x14] * 0x23);",
    "local_44 = (double)(iVar4 + -0x3f);",
    "local_38 = (uint)((char)param_1[0x14] != '\\x01');",
    "local_3c = (char)param_1[0x14];",
    "local_2c = 0;",
    "local_54 = 1;",
    "(**(code **)(*param_1 + 0x24))();",
    "*(short *)((int)param_1 + 10) == 8",
    "*(short *)(param_1 + 0x52) = (short)param_1[0x52] + 0x2d;",
    "*(undefined1 *)(param_1 + 0xb2) = 2;",
    "*(undefined2 *)(param_1 + 2) = 0;",
):
    assert expression in trail, expression
assert "param_1[0x5a] = 0;" not in trail

sys.path.insert(0, str(ROOT / "scripts"))
from common import verify_target, target_bytes
pe = verify_target()
for address, expected_value in (
    (0x00787C30, 500.0),
    (0x00787C70, 250.0),
):
    actual = struct.unpack("<d", target_bytes(pe, address, 8))[0]
    assert actual == expected_value, (hex(address), actual, expected_value)

# The native function zeroes the complete spawn record at entry. Context
# effect 0x21 therefore retains owner 0; only the local frame-7 effect sets 1.
native_init = (ROOT / ".analysis/kanna-slot06/helpers/405490.c").read_text()
assert "_memset(param_1,0,0x48);" in native_init
cpp_init = (ROOT / "src/EffectPool.cpp").read_text()
assert "std::memset(this, 0, sizeof(*this));" in cpp_init

source = (ROOT / "workbench/character19-slot06/Character19Slot06Cases.cpp").read_text()
assert "Slot06UpdateFinalEffectPair" not in source
pair_helper = (ROOT / "workbench/character19-slot06/Character19Slot06Case6E.inc").read_text()
for expression in (
    "field000a == 0",
    "ResetFrame();",
    "field000a == 7",
    "spawn.owner = 1;",
    "spawn.type = 0x195;",
    "spawn.x = (double)((int)positionX + (int)facing * 0x23);",
    "spawn.y = (double)((int)positionY - 0x3f);",
    "spawn.group = 2;",
    "spawn.layer = 1;",
    "spawn.facing = (facing != 1);",
    "spawn.flag0018 = (unsigned char)facing;",
    "spawn.field0028 = 0;",
    "EmitLocalEffect(&spawn);",
    "field000a == 8",
    "spawn.type = 0x196;",
    "spawn.x = (double)((int)positionX + (int)facing * 0x50);",
    "meter = meter + 45;",
    "pendingCharacterSoundSlot = 2;",
    "field0008 = 0;",
    "ResetPose();",
    "timing.frameDuration",
    "timing.animationFrameCount",
):
    assert expression in pair_helper, expression
assert pair_helper.count("spawn.owner = 1;") == 2

trail_start = source.index("void Character19::Slot06UpdateTrailEffectFinish")
trail_end = source.index("\n}\n", trail_start) + 3
trail_helper = source[trail_start:trail_end]
for expression in (
    "field000a == 0",
    "ResetFrame();",
    "StartTrail(3);",
    "field0120 == 0",
    "field0118 = field0118 - 500.0;",
    "field0118 = field0118 - 250.0;",
    "spawn->type = 0x21;",
    "spawn->x = (double)(int)positionX;",
    "spawn->y = (double)((int)positionY - 0x32);",
    "spawn->group = 2;",
    "spawn->layer = 1;",
    "spawn->palette = 0xb;",
    "contextOwner->EmitEffect(spawn);",
    "field000a == 7",
    "spawn->owner = 1;",
    "spawn->type = 0x1ad;",
    "spawn->x = (double)((int)positionX + (int)facing * 0x23);",
    "spawn->y = (double)((int)positionY - 0x3f);",
    "spawn->facing = (facing != 1);",
    "spawn->flag0018 = (unsigned char)facing;",
    "spawn->field0028 = 0;",
    "EmitLocalEffect(spawn);",
    "field000a == 8",
    "meter = meter + 45;",
    "pendingCharacterSoundSlot = 2;",
    "field0008 = 0;",
    "ResetPose();",
):
    assert expression in trail_helper, expression
assert trail_helper.count("spawn->owner = 1;") == 1
assert trail_helper.index("contextOwner->EmitEffect(spawn);") < trail_helper.index("spawn->owner = 1;")

dispatcher = (ROOT / "workbench/character19-slot06/Character19Slot06.cpp").read_text()
assert_selector_case(dispatcher, 266)
assert '#include "Character19Slot06Case6E.inc"' in dispatcher
assert "Slot06UpdateFinalEffectPair(" not in dispatcher
assert_selector_case(dispatcher, 267) and "Slot06UpdateTrailEffectFinish(" in dispatcher

disasm = subprocess.run(
    [
        "objdump", "-D", "-Mintel",
        "--start-address=0x006742E1",
        "--stop-address=0x006746E1",
        str(ROOT / "resources/EFZ.exe"),
    ],
    cwd=ROOT, check=True, capture_output=True, text=True,
).stdout
for expression in (
    "mov    WORD PTR [ebp-0x4c],0x195",
    "mov    WORD PTR [ebp-0x4c],0x196",
    "mov    WORD PTR [ebp-0x4c],0x1ad",
    "call   0x4109d0",
    "call   0x407100",
):
    assert expression in disasm, expression

print({
    "variants": 2,
    "native_bytes": [500, 524],
    "state_ids": [266, 267],
    "verified_constants": 2,
    "local_effect_types": [0x195, 0x196, 0x1ad],
    "context_owner": 0,
    "local_owner": 1,
})
