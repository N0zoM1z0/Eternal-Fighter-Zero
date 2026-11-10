# Nayuki Character10::Slot02 command interpreter — reviewed partial boss

The original Nayuki vtable at 0x00788270 slot02 entry 0x00788278
points to 0x004641C0. The full canonical function boundary is
[0x004641C0, 0x0046549B), **4,827 bytes**, followed by five
CC padding bytes; full SHA-256:
0fed5a3c7f5af912bee361dd49a78286b10d147ef9ec10589627b5785213d6c6.

Natural workbench C++ currently reconstructs the **3,347-byte /
984-instruction** first eight input-history scan priorities,
[0x004641C0,0x00464ED3), SHA-256
a16fce268f4681f9e6e96b650ab8d212ee5fdef05c5aa3e5b2f13bdfc0df0ecf.
The recovered commands are 0x6E, 0x64, 0x61,
0x46, 0x14, 0x0A, 0x28 and 0x1E. Each scan retains the
original 180-frame circular-history wrap, stage progression,
direction-dependent tests, meter and button input priorities.
The first 0x6E and second 0x64 scans require opposite
orientation expressions. The 0x61 scan uses a 0x40 held
button and exact meter 3000; the Nayuki 0x28 initial
guard does NOT require airborne positionY, unlike Sayuri.

Run the selected native workbench only:

    scripts/repo-python workbench/nayuki-commands/check_prefix.py

Pinned VC7.1 /Od /G6 /MT /Gy /W3 emits 3,352 bytes
including the temporary stage reset and 3-instruction return.
All **984/984 original instruction forms and operands** match,
with **115 exact internal branch destinations and 16 valid
outbound original targets**. No COFF relocations occur in
this prefix. One original near JMP shortens because the
shared full-function return is still absent.

Continue original 0x00464ED3 (button 6 and final input
history patterns). **Not Exact**: 1,480 original bytes,
the full return and any remaining relocation bindings
are open. No full cold replay was run.
