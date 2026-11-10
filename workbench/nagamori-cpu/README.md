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

The reviewed opening [0x004B2AC0,0x004B3C74) covers
**4,532 original bytes / 1,230 instructions**, target prefix SHA-256
394daf5e635d55eae9333e6c6e9d3d80ce52b563aca9ffe7f288232dbb035617.
Under pinned VC7.1, the partial source emits **4,531 bytes / 1,232
instructions (including the three-instruction temporary epilogue)** and
103 COFF relocations. The first **1,228 of 1,229 comparable instruction
forms** match after normalizing original direct branch/call destinations
and FP constant addresses; the incomplete stack allocation is 0xB4
versus the original 0xE8. The original final jump to the shared exit
is not present until the full owner is restored.

The focused audit additionally checks **141 internal branch targets**
against their corresponding instruction ordinals, not just mnemonics.
It rejects the old incorrect implementation that allowed the second
60-120 forward-range attack outside its shared opponent guard: original
0x004B3172 must jump over both choices on failure.

The recovered decision trees include original defensive choices,
0xAA aerial-opening five-chance responses from 0x004B35F2,
grounded opponent-action randomized command selection from 0x004B3891,
an airborne response tree from 0x004B3A75, and the 0x34 meter/air-combo
special from 0x004B3B84. The original last aerial 2x chance generates
x87 fadd st(0),st(0) from field00a8 * 2.0f, not
field00a8 + field00a8.

Run the single-owner native check:

    scripts/repo-python workbench/nagamori-cpu/check_prefix.py

The next original block starts at 0x004B3C74. This is a partial
natural C++ draft, **not complete Exact**. Exit branches, the original
full stack frame, remaining 10,760 owner bytes and external
relocation bindings are still open. A matching normalized prefix
must not be promoted to the exact ledger.
