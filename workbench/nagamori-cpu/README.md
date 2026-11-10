# Nagamori Slot05 CPU boss — partial natural C++

Original vtable slot 5 at `0x00788410` points to
`Character06::Slot05` at `[0x004B2AC0,0x004B667C)`, **15,292 code
bytes**, followed by four `CC` bytes. The complete original SHA-256 is
`14a83398918558355cd4ae747fa313b60f62771f1758ba870a593d29f596bfb9`.

`Character06Cpu.cpp` reconstructs original CPU input initialization,
random defensive decisions, opponent distance and the first close-
and medium-range offensive choices. The shape was tested initially
using another accepted character's CPU source, but every retained
instruction is compared against Nagamori's own executable.

The reviewed original prefix [0x004B2AC0,0x004B3A75) now contains
**4,021 bytes / 1,096 x86 instructions**. With the pinned VC7.1,
**1,095 of 1,096 original instruction forms and operands match**,
normalizing original branch/call destinations and floating literal
addresses. The only form mismatch is the incomplete stack frame
(0xE8 in the original). **117 internal branch targets have also been
checked against their corresponding instruction ordinals**, rather
than indiscriminately masked. This catches semantically incorrect
control flow despite identical instruction mnemonics.

A recovered C++ opponent-state condition formerly let the fallback
60–120 forward-range attack execute after its shared grounded/no-hit
guard failed. Reparenthesizing the two choices under the original
opponent guard restores the six-byte near JNZ at original 0x004B3172
to 0x004B324E. The previous normalized-only prefix audit could not
detect this semantic discrepancy; the upgraded test now rejects it.

The source also reconstructs the aerial opening state 0xAA/pose 1
decisions beginning at 0x004B35F2: five independent chance checks,
height bands -50/-40/-30/0/50 and distance cutoffs 50–120.
The last chance is intentionally field00a8 * 2.0f, generating the
original fld plus x87 fadd st(0),st(0), unlike two separate field
reads. At 0x004B3891, another opponent 0xA8/0xA9/0xAA
grounded-response tree selects 0x48/0x0C/0x14/0x16 or meter specials.
The draft continues beyond the audited boundary with provisional
additional opponent aerial and 0x34 special conditions.

Original 4,021-byte prefix SHA-256:
21c9a1823c8a544065573a3a112a4393d0e485f0d897d8301ffcdc21023465df.
This remains a **partial native candidate**, not byte-exact or a
whole-owner implementation; the 15,292-byte original CPU boss and
all original relocation bindings remain open.

Reproduce by compiling only this workbench TU:

```bash
scripts/repo-python workbench/nagamori-cpu/check_prefix.py
```

The audited original branch boundary is 0x004B3A75. Continue
reviewing additional source decisions and full-body codegen against the
original Nagamori binary; do not treat the provisional remainder of
the draft as an accepted match. This audit compiles only this owner,
not the entire game.
