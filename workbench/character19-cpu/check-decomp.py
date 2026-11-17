from pathlib import Path
import sys
ROOT=Path(__file__).resolve().parents[2]
sys.path.insert(0,str(ROOT/'scripts'))
from native_build import compile_source
from coff import object_function
from common import verify_target,target_bytes
src=ROOT/'workbench/character19-cpu/Character19Cpu-decomp.cpp'
source=src.read_text()
for forbidden in ('__asm', '_emit', '__emit', 'PADDING', 'FUN_', 'param_1'):
    if forbidden in source: raise AssertionError(('not natural C++',forbidden))
obj=ROOT/'build/character19-cpu/Character19Cpu-decomp.obj'
compile_source(src.resolve(),obj.resolve(),['/Od','/G6','/MT','/Gy','/W3'],ROOT/'.analysis/build/character19-cpu-decomp.log')
code,relocs=object_function(obj.resolve(),'?Slot05@Character19@@UAEXXZ')
native=target_bytes(verify_target(),0x00678c30,17176)
Path(ROOT/'.analysis/character19-slot05-decomp-candidate.bin').write_bytes(code)
if code[:12] != native[:12]: raise AssertionError(('entry/frame differs',code[:12].hex(),native[:12].hex()))
print('native',len(native),'candidate',len(code),'delta',len(code)-len(native),'relocations',len(relocs),'prologue',code[:24].hex(' '))
