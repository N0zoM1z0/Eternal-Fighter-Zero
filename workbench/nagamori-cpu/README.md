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

The reviewed opening prefix [0x004B2AC0,0x004B475D)
contains **7,325 original bytes / 1,909 instructions**. Original
SHA-256 is
3da33c37a348518b0680252be3ca43a36cba72881fb11490952f96e90635f85a.

Pinned VC7.1 builds a **7,321-byte partial COFF function** with
1,911 instructions (including its temporary epilogue) and 136
relocations. Of the first 1,908 comparable target instruction
forms/operands, **1,907 match** with branch/call destinations and
floating constants normalized; the incomplete stack frame is 0xBC
rather than target 0xE8. The final target instruction jumps into
the not-yet-reconstructed shared exit. **239 internal branch
targets** agree by destination instruction ordinal, including the
original shared guard at 0x004B3172. These are diagnostic results,
not strict byte-exact acceptance.

The partial source contains defensive, distance, aerial action
and CPU state 4..11 decision paths, plus the collision-based
random follow-up choices for action IDs 0xC8, 0xC9 and 0xCA.
The 0xCA branch includes the original mixed floating-point
permission and integer random-command expression. Keep natural
float-multiplication operand order and preserve fall-through
when the final random choice is nonzero.

Run only:

    scripts/repo-python workbench/nagamori-cpu/check_prefix.py

The next branch is original 0x004B475D (action 0xCB).
The remaining 7,967 original bytes and their relocations,
shared return, and full owner comparison are still open.
Do not register this partial candidate as Exact.
