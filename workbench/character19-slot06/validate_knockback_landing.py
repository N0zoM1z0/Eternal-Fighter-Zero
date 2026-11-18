"""Validate selector cases 0x25 and 0x26, the post-launch knockback landing path."""
import re
import struct
import sys
from pathlib import Path

ROOT = Path(__file__).resolve().parents[2]
native = (ROOT / ".analysis/kanna-slot06/native.c").read_text()
lines = native.splitlines()
starts = []
for i,line in enumerate(lines):
    m=re.match(r"^\s*case\s+([^:]+):",line)
    if m:
        try:v=int(m.group(1),0)
        except ValueError:continue
        starts.append((i,v))
blocks={}
for n,(i,v) in enumerate(starts):
    if v in (0x25,0x26):
        blocks[v]=lines[i:starts[n+1][0]]
assert set(blocks)=={0x25,0x26}

expected={0x25:(316,68,1),0x26:(277,69,0)}
for case,(native_bytes,state,interrupt) in expected.items():
    block="\n".join(blocks[case])
    assert len(blocks[case]) == (34 if case==0x25 else 27)
    assert "*(double *)(param_1 + 0x46) = *(double *)(param_1 + 0x46) - _DAT_00787d48;" in block
    assert "*(short *)(param_1 + 0x52) = (short)param_1[0x52] + 3;" in block
    assert "*(undefined8 *)(param_1 + 0xc) = *(undefined8 *)(param_1 + 0x30);" in block
    assert "*(undefined8 *)(param_1 + 0xe) = *(undefined8 *)(param_1 + 0x32);" in block
    assert "*(short *)(param_1 + 3) = (short)param_1[3] + 1;" in block
    assert "*(short *)((int)param_1 + 10) = *(short *)((int)param_1 + 10) + -2;" in block
    assert "if (param_1[0x4b] == 0)" in block
    assert "*(undefined2 *)(param_1 + 2) = 0x62;" in block
    assert "*(undefined2 *)(param_1 + 2) = 0x61;" in block
    assert ("FUN_0040ff70()" in block) == bool(interrupt)
    if interrupt:
        assert block.index("*(short *)(param_1 + 3) = (short)param_1[3] + 1;") < block.index("FUN_0040ff70()")
    print(f"case 0x{case:02x}: native={native_bytes}, state={state}, guarded={bool(interrupt)}")

sys.path.insert(0,str(ROOT/"scripts"))
from common import verify_target,target_bytes
pe=verify_target()
value=struct.unpack("<d",target_bytes(pe,0x00787d48,8))[0]
assert value==1.5

source=(ROOT/"workbench/character19-slot06/Character19Slot06Cases.cpp").read_text()
for expression in (
 "field0118 = field0118 - 1.5",
 "meter = meter + 3",
 "velocityX = knockbackVelocityX",
 "velocityY = knockbackVelocityY",
 "field000c = field000c + 1",
 "if (interruptOutsideRange && !Slot06OpponentWithinKnockbackRange())",
 "if (frameDuration <= field000c)",
 "if ((positionY + velocityY) >= 0.0)",
 "if (knockdownOnLanding == 0)",
):
 assert expression in source,expression

print({"variants":2,"decay_constant":value,"state_ids":[68,69]})
