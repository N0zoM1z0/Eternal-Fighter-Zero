# Nayuki Character10::Slot05 CPU boss — original-bound partial C++

The original Nayuki vtable slot05 at 0x00788284 selects 0x004654A0.
Its complete authored code extent [0x004654A0,0x0046886B)
is **13,259 original x86 bytes**, with five trailing CC padding
bytes and whole-owner SHA-256
fdff7abd73f6c362272c3360eab5da1473255c978572d685d02810e32f1472ce.

Natural C++ workbench Character10Cpu.cpp now covers
[0x004654A0,0x00467686), **8,678 original bytes /
2,179 instructions**, prefix SHA-256
bf76edc73efa3598127e2c87066c97cc067fc24fc110721c4d370a2ea54c739b.

The authored CPU policy covers Nayuki-specific A8/A9
and AA reactions, CPU state 4–10 recovery, FA/FC
counterattacks, 0x10C timed four-button sequence and
complete C8/C9/CA/CB/CC/CD/CE collision follow-ups.
Original RandomRange call order, overlapping timer
windows, meter gates and directional input assignments
are preserved. The 0xCC random boolean requires
the ternary RandomRange(0,2) ? 0 : 1 to produce the
original 32-bit SBB/INC; normal equality operators
instead generate an 8-bit CL instruction pair.

Run only this selected candidate:

    scripts/repo-python workbench/nayuki-cpu/check_prefix.py

Pinned VC7.1 /Od /G6 /MT /Gy /W3 emits **8,674 bytes
/ 2,181 instructions**, including temporary return
and **124 COFF relocations**. Of 2,178 comparable
original body instructions, **2,177 agree** after
branch/call/literal normalization. The incomplete
stack frame remains 0x98 versus original 0xC0.
One original near JMP shortens because the true
shared return is missing. **310 internal branches,
96 canonical outbound branch targets, and all
124 original-bound relocations** agree, spanning
27 uniquely bound symbols with exact float payloads.

Continue at 0x00467686 (CF/D0). **Not full Exact**:
4,581 original bytes and complete frame/return and
relocations remain open. The unverified Nayuki Slot04
experiment is retained. No all-unit cold replay.
