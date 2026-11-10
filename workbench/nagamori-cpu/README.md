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

The reviewed target prefix [0x004B2AC0,0x004B44BA) covers
**6,650 original bytes / 1,745 instructions**, with SHA-256
36ac9b4431122a619058eb5acc943b1c6cb492e80a28bbd50efbbda9138abc40.

The pinned VC7.1 candidate is **6,646 bytes / 1,747
instructions** including the temporary return, with 124 COFF
relocations. Its first **1,743 / 1,744 comparable original
instruction forms and operands** match after normalization of
branch/call destinations and FP constant addresses. The one
differing form is the partial 0xB8 stack frame (target 0xE8).
The final original instruction jumps to the missing shared exit.
The targeted checker also validates **215 in-prefix branch
destinations by instruction index** and the original 0x004B3172
opponent guard. This is diagnostic, not a strict byte comparison.

The source covers previous CPU-state 4..11 branches and the
new 0x004B3FB6..0x004B44BA collision follow-up decision tree for
actions 0xC8 and 0xC9. Preserve the observed FP order
field00a8 * 25.0f and the 0xC9 last random branch's genuine
fall-through when the result is nonzero.

To reproduce *only this owner*, run:

    scripts/repo-python workbench/nagamori-cpu/check_prefix.py

The next original block starts at 0x004B44BA (action 0xCA).
The remaining 8,642 bytes and complete native/relocation
comparison are unfinished. Do not claim complete-function Exact.
