"""Selected original Nayuki Slot02 prefix native audit; NOT a full Exact proof."""
from pathlib import Path
import hashlib
import re
import subprocess
import struct
import sys

ROOT = Path(__file__).resolve().parents[2]
sys.path.insert(0, str(ROOT / "scripts"))
from common import verify_target, target_bytes
from native_build import compile_source
from coff import object_function

START, FULL_SIZE, END = 0x004641C0, 4827, 0x00464ED3
FULL_SHA = "0fed5a3c7f5af912bee361dd49a78286b10d147ef9ec10589627b5785213d6c6"
PREFIX_SHA = "a16fce268f4681f9e6e96b650ab8d212ee5fdef05c5aa3e5b2f13bdfc0df0ecf"
SOURCE = ROOT / "workbench/nayuki-commands/Character10Commands.cpp"
OBJECT = ROOT / "build/nayuki-commands/Character10Commands.partial.obj"


def disasm(data):
    output = subprocess.run(
        ["ndisasm", "-b32", "-o0", "-"],
        input=data, stdout=subprocess.PIPE, stderr=subprocess.PIPE, check=True,
    ).stdout.decode()
    return [(int(a, 16), bytes.fromhex(raw), op)
            for a, raw, op in re.findall(
                r"^([0-9A-F]+)\s+([0-9A-F]+)\s+(.+)$", output, re.M)]


def form(op):
    if re.match(r"^(?:j\w+|call)\s+(?:(?:short|near)\s+)?0x[0-9a-f]+$", op):
        return re.sub(
            r"^(\S+)\s+(?:(?:short|near)\s+)?0x[0-9a-f]+$",
            r"\1 DEST", op)
    return op


def main():
    im = verify_target()
    assert struct.unpack("<I", target_bytes(im, 0x00788278, 4))[0] == START
    full = target_bytes(im, START, FULL_SIZE)
    assert hashlib.sha256(full).hexdigest() == FULL_SHA
    assert full[-4:] == bytes.fromhex("8b e5 5d c3")
    assert target_bytes(im, START + FULL_SIZE, 5) == b"\xcc"*5
    orig = full[:END-START]
    assert hashlib.sha256(orig).hexdigest() == PREFIX_SHA

    compile_source(SOURCE, OBJECT, ["/Od", "/G6", "/MT", "/Gy", "/W3"],
                   ROOT / ".analysis/build/nayuki-commands-workbench.log")
    code, rel = object_function(OBJECT, "?Slot02@Character10@@UAEXXZ")
    T, C = disasm(orig), disasm(code)
    assert (len(orig), len(T), len(code), len(C), len(rel)) == (
        3347, 984, 3352, 988, 0)
    assert T[2][2] == C[2][2] == "sub esp,byte +0xc"
    assert [v[2] for v in C[-4:]] == [
        "mov byte [ebp-0x6],0x0", "mov esp,ebp", "pop ebp", "ret"]
    for i, (a, b) in enumerate(zip(T, C)):
        assert form(a[2]) == form(b[2]), (i, a[2], b[2])
    widths = [(i, a[2], b[2]) for i, (a, b) in enumerate(zip(T, C))
              if len(a[1]) != len(b[1])]
    assert widths == [(957, "jmp 0x12d7", "jmp short 0xd14")]

    ti = {a[0]:i for i, a in enumerate(T)}
    ci = {a[0]:i for i, a in enumerate(C)}
    full_positions = {a[0] for a in disasm(full)}
    inside, outside = 0, 0
    for a, b in zip(T, C):
        ma = re.search(r"^j\w+\s+(?:(?:short|near)\s+)?0x([0-9a-f]+)$", a[2])
        if ma is None:
            continue
        mb = re.search(r"^j\w+\s+(?:(?:short|near)\s+)?0x([0-9a-f]+)$", b[2])
        assert mb is not None, (a, b)
        ta, cb = int(ma[1], 16), int(mb[1], 16)
        assert ta in full_positions, a
        if ta in ti:
            inside += 1
            assert ti[ta] == ci.get(cb), (a, b, ti[ta], ci.get(cb))
        else:
            outside += 1
    assert (inside, outside) == (115, 16)
    print("Nayuki Slot02: 3347 / 4827 original code bytes,")
    print("984 / 984 original instruction forms, 115 in-prefix jumps,")
    print("16 canonical outbound destinations, zero COFF relocations.")
    print("One near jump shortens due to the temporary return; NOT full Exact.")


if __name__ == "__main__":
    main()
