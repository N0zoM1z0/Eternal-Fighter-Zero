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

The reviewed prefix [0x004B2AC0,0x004B3FB6) covers
**5,366 original bytes / 1,441 instructions**. Canonical SHA-256:
6079a74ebf39350db98311a79d3ae2fa4b2c358226856d95e94ce56256cd4d1c.

Pinned VC7.1 emits a **5,362-byte partial COFF function**, 1,443
instructions including the temporary epilogue, and 104 relocations.
Of the 1,440 comparable original instruction forms/operands,
**1,439 match** with branch/call destinations and FP literal addresses
normalized. The still-incomplete stack frame is 0xB4 rather than
the original 0xE8. The final original prefix instruction jumps to
the full shared exit rather than the draft's temporary return.

Crucially, the diagnostic also verifies **176 validated internal branch
destinations by instruction ordinal**. This detected a formerly
incorrect opponent-state guard: the near conditional jump at original
0x004B3172 must bypass both attack branches, not one. A
matching opcode sequence alone did not establish correct flow.

The candidate reconstructs defensive choices, close/midrange attacks,
the 0xAA aerial decision sequence, opponent A8/A9/AA responses,
special command 0x34, and newly recovered AI states 4..11 with
direction steering and independent button pulses. Repeated action
checks that seem redundant are preserved from the target. Float
expressions match the original x87 operand ordering.

Run the targeted check only:

    scripts/repo-python workbench/nagamori-cpu/check_prefix.py

The next original block begins at 0x004B3FB6. This is an unfinished
native-source boss; **do not register Exact** without completing and
strictly comparing the full 15,292 bytes and all relocations.
