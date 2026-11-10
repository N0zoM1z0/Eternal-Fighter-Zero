# Sayuri Character09::Slot04 — in-progress command/action boss

This is a real **partial natural C++ reconstruction**, not an Exact owner.
The original Character09 vtable at 0x00788138 has Slot04 at
0x00788148 pointing to the 11,119-byte original function 0x00446780.
The complete canonical code extent is [0x00446780,0x004492EF),
SHA-256 fd248e424f2ebcdddb59462a3101f653e9931e4053d53eb2af9a067e2c0bb286.
All 2,815 original instructions decode contiguously and all 460
direct jumps stay on original instruction starts inside the function.
The shared return is at 0x004492EB. One CC byte separates the function
from the next prologue at 0x004492F0.

The current natural C++ source Character09Input.cpp reconstructs
**6,215 original bytes / 1,551 instructions** of the full owner,
through the next guard at 0x00447FC7, prefix SHA-256
7a79a6757eff05a9a25fc96f4ff488e0cb601053116e09a9d0da188e930d289b.

Source covers the original high-priority command state transitions,
the 150–155 opponent action gate, meter-tier upgrades, aerial
0x28–0x2A, grounded 0x14–0x16 and 0x1E–0x20, and 0x46–0x48
command groups. Newly restored 0x0C/0x0B/0x0A branches
preserve EX-state suppression and air/ground action selection;
0x0C additionally permits already-airborne operation in the
absence of primary/secondary meter permission. The exact
original order of action buffering, meter checks, sequence
frame flags and attackCollisionResult conditions is retained.

Reproduce only this selected owner:

    scripts/repo-python workbench/sayuri-action/check_prefix.py

Pinned VC7.1 /Od /G6 /MT /Gy /W3 emits **6,212 bytes /
1,553 instructions** including a temporary epilogue, with
**55 COFF relocations**. The first 1,549 of 1,550
comparable original body instructions match in form and
operands after normalizing direct branch/call destinations
and floating-point literal addresses; the only differing
form is the incomplete stack frame (sub esp,0x14 original,
push ecx partial source). The original final prefix JMP
targets the full shared return, absent from partial C++.
**236 in-prefix branch targets and all 55 original-bound
relocation operands** agree; original double bit patterns
are checked at their executable locations.

Next original block begins at 0x00447FC7 (low-priority
special/grounded movement decisions). **Not Exact**:
4,904 original bytes, full stack/return and complete
original relocation bindings remain to reconstruct.
No full-game cold replay is relevant to this draft.
