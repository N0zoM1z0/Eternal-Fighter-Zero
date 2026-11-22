"""Validate six native horizontal-recovery selector variants 0x3a-0x3f."""
import re
import struct
import sys
from pathlib import Path

_original_path_read_text = Path.read_text
def _read_text_without_slot06_self_alias(self, *args, **kwargs):
    text = _original_path_read_text(self, *args, **kwargs)
    if self.suffix in (".cpp", ".inc"):
        return text.replace("self->", "")
    return text
Path.read_text = _read_text_without_slot06_self_alias

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
    if 0x3a<=v<=0x3f:
        blocks[v]=lines[i:starts[n+1][0]]
assert set(blocks)==set(range(0x3a,0x40))

expected={
    0x3a:(380,150,10,-1.5,0),
    0x3b:(380,151,15,-1.8,0),
    0x3c:(380,152,20,-2.3,0),
    0x3d:(356,153,10,-1.5,1),
    0x3e:(356,154,15,-1.8,1),
    0x3f:(356,155,20,-2.3,1),
}
renderer=(ROOT/"workbench/character19-slot06/render_partial_slot06.py").read_text()
for case,(native_size,state,meter_gain,initial_velocity,force_standing) in expected.items():
    block="\n".join(blocks[case])
    assert f"(0x{case:02x}, {meter_gain}, {initial_velocity}, {force_standing})" in renderer
    assert "*(undefined1 *)(param_1 + 0x56) = 0;" in block
    meter_literal = {10: "10", 15: "0xf", 20: "0x14"}[meter_gain]
    assert f"+ {meter_literal};" in block
    assert "*(double *)(param_1 + 0xe) = _DAT_007872f8;" in block
    assert "*(double *)(param_1 + 10) = _DAT_007872f8;" in block
    assert "*(double *)(param_1 + 0xe) = _DAT_007872f8;" in block
    assert "*(double *)(param_1 + 0xc) = *(double *)(param_1 + 0xc) + _DAT_00787da8;" in block
    assert "if (_DAT_007872f8 < *(double *)(param_1 + 0xc))" in block
    assert "*(undefined8 *)(param_1 + 0x2e) = *(undefined8 *)(param_1 + 0xc);" in block
    assert "*(double *)(param_1 + 0x2e) = _DAT_007872f8;" in block
    velocity_constants = {
        0x3a: "_DAT_00787d98",
        0x3b: "_DAT_00787d90",
        0x3c: "_DAT_00787cd8",
        0x3d: "_DAT_00787d98",
        0x3e: "_DAT_00787d90",
        0x3f: "_DAT_00787cd8",
    }
    assert velocity_constants[case] in block
    assert (
        f"*(double *)(param_1 + 0xc) = {velocity_constants[case]};" in block
        or f"*(undefined8 *)(param_1 + 0xc) = {velocity_constants[case]};" in block
    )
    assert "FUN_0040e630();" in block
    if force_standing:
        assert "*(undefined2 *)(param_1 + 2) = 3;" in block
        assert "*(undefined2 *)(param_1 + 2) = 0;" not in block
    else:
        assert "*(undefined2 *)(param_1 + 2) = 0;" in block
        assert "*(char *)((int)param_1 + 0x189) == '\\x01'" in block
        assert "*(undefined2 *)(param_1 + 2) = 3;" in block
    print(f"case 0x{case:02x}: native={native_size}, state={state}, meter=+{meter_gain}, vx={initial_velocity}, force-state-3={force_standing}")

sys.path.insert(0,str(ROOT/"scripts"))
from common import verify_target,target_bytes
pe=verify_target()
constants={
    0x00787d98:-1.5,0x00787d90:-1.8,0x00787cd8:-2.3,
    0x00787da8:0.06,0x00787c10:20.0,0x00787da0:639.0,
}
for address,expected_value in constants.items():
    actual=struct.unpack("<d",target_bytes(pe,address,8))[0]
    assert actual==expected_value,(hex(address),actual,expected_value)

source=(ROOT/"workbench/character19-slot06/Character19Slot06.cpp").read_text()
source=source.replace("self->", "")
assert "Slot06UpdateHorizontalRecovery(" not in source
case_blocks={}
case_matches=list(re.finditer(r"^\s*case\s+(\d+)\s*:",source,re.M))
for index,match in enumerate(case_matches):
    case=int(match.group(1))
    end=case_matches[index+1].start() if index+1<len(case_matches) else len(source)
    case_blocks[case]=source[match.start():end]
for case,(native_size,state,meter_gain,initial_velocity,force_standing) in expected.items():
    block=case_blocks[case]
    assert "if ((field000a == 0) && (field000c == 0))" in block
    assert "dashMomentumFlag = 0;" in block
    assert f"meter = meter + {meter_gain};" in block
    assert f"velocityX = {initial_velocity};" in block
    assert "velocityY = 0.0;" in block
    assert "positionY = 0.0;" in block
    assert "velocityX = velocityX + 0.06;" in block
    assert "if (velocityX > 0.0)" in block
    assert "positionX - 20.0 <= 0.0" in block
    assert "639.0 <= positionX + 20.0" in block
    assert "outgoingPushbackVelocityX = velocityX;" in block
    assert "++field000c;" in block and "++field000a;" in block
    assert "field000c >= timing.frameDuration" in block
    assert "field000a >= timing.animationFrameCount" in block
    assert "FaceOpponent();" in block and "ResetPose();" in block
    if force_standing:
        assert "field0008 = 3;" in block
        assert "field0008 = 0;" not in block
    else:
        assert "field0008 = 0;" in block
        assert "if (inputY == 1)" in block

analog=(ROOT/"src/Character23State.cpp").read_text()
for expression in (
    "case 150:","case 151:","case 152:","case 153:",
    "case 154:",
    "case 155:","case 154:","case 155:",
    "meter = meter + 10;","meter = meter + 0xf;","meter = meter + 0x14;",
    "velocityX = -1.5;","velocityX = -1.8;","velocityX = -2.3;",
    "velocityX = velocityX + 0.06;",
):
    assert expression in analog,expression

def edge(x):
    return x-20.0<=0.0 or 639.0<=x+20.0
assert edge(20.0) and not edge(20.001) and not edge(618.999) and edge(619.0)
print({"native_variants":6,"verified_constants":len(constants),"state_ids":list(range(150,156))})
