"""Validate the repeated defeat-impact state and defeat-wait state 0x38-0x39."""
import re
from pathlib import Path

_original_path_read_text = Path.read_text
def _read_text_without_slot06_self_alias(self, *args, **kwargs):
    text = _original_path_read_text(self, *args, **kwargs)
    if self.suffix in (".cpp", ".inc"):
        return text.replace("self->", "")
    return text
Path.read_text = _read_text_without_slot06_self_alias

from selector_support import assert_selector_case, selector_case_for_state

ROOT = Path(__file__).resolve().parents[2]
native = (ROOT / ".analysis/kanna-slot06/native.c").read_text()
lines = native.splitlines()
starts=[]
for i,line in enumerate(lines):
    m=re.match(r"^\s*case\s+([^:]+):",line)
    if m:
        try:v=int(m.group(1),0)
        except ValueError:continue
        starts.append((i,v))
blocks={}
for n,(i,v) in enumerate(starts):
    if v in (0x37,0x38,0x39):
        blocks[v]=lines[i:starts[n+1][0]]
assert set(blocks)=={0x37,0x38,0x39}

def norm(block):
    return re.sub(r"case 0x[0-9a-f]+:","case X:","\n".join(block))
assert norm(blocks[0x37])==norm(blocks[0x38])
assert len(blocks[0x38])==len(blocks[0x37])

wait="\n".join(blocks[0x39])
for expression in (
    "0x3c < *(ushort *)(param_1 + 3)",
    "0 < param_1[0x42]",
    "*(short *)((int)param_1 + 10) == 0",
    "*(undefined2 *)(param_1 + 2) = 0x60;",
    "*(undefined1 *)(param_1 + 0x56) = 0;",
    "*(short *)(param_1 + 3) = (short)param_1[3] + 1;",
    "FUN_0040e630();",
    "*(undefined2 *)(param_1 + 2) = 0x60;",
):
    assert expression in wait,expression

source=(ROOT/"workbench/character19-slot06/Character19Slot06Cases.cpp").read_text()
for expression in (
):
    assert expression in source,expression

wait=(ROOT/"workbench/character19-slot06/Character19Slot06Case39.inc").read_text()
for expression in (
    "(health > 0) && (field000c > 60) && (field000a == 0)",
    "field0008 = 0x60;", "ResetPose();", "dashMomentumFlag = 0;",
    "++field000c;", "++field000a;",
    "field000a == timing.animationFrameCount", "FaceOpponent();",
):
    assert expression in wait, expression

impact=(ROOT/"workbench/character19-slot06/Character19Slot06Case37.inc").read_text()
for expression in (
    "SetVerticalShake(3, 0);", "spawn.type = 3;",
    "spawn.x = (double)(int)positionX;", "spawn.y = (double)(int)positionY;",
    "spawn.group = 2;", "spawn.layer = 0;",
    "contextOwner->EmitEffect(&spawn);", "pendingContextSoundSlot = 7;",
    "field0008 = 99;", "++field000c;", "++field000a;",
):
    assert expression in impact, expression

dispatcher=(ROOT/"workbench/character19-slot06/Character19Slot06.cpp").read_text()
assert_selector_case(dispatcher, 98)
assert_selector_case(dispatcher, 99)
assert dispatcher.count('#include "Character19Slot06Case37.inc"') == 2
assert "Slot06UpdateDefeatImpact(" not in dispatcher
assert '#include "Character19Slot06Case39.inc"' in dispatcher
assert "Slot06UpdateDefeatWait(" not in dispatcher

print({
    "case_0x38":{"native_bytes":248,"state_id":98,"same_body_as":"0x37"},
    "case_0x39":{"native_bytes":186,"state_id":99,"health_timeout_frames":60,"transition_state":0x60},
})
