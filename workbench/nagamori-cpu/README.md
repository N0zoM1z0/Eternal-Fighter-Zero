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

The reviewed opening prefix [0x004B2AC0,0x004B4AD5)
contains **8,213 original bytes / 2,120 instructions**. Original
SHA-256 is
1ca08326f2aa05578177d2edb456da8bdcbf7369a9691bc025753152c5413509.

Pinned VC7.1 builds a **8,206-byte partial COFF function** with
2,122 instructions (including its temporary epilogue) and 150
relocations. Of the first 2,119 comparable target instruction
forms/operands, **2,118 match** with branch/call destinations and
floating constants normalized; the incomplete stack frame is 0xBC
rather than target 0xE8. The final target instruction jumps into
the not-yet-reconstructed shared exit. **276 internal branch
targets** agree by destination instruction ordinal, including the
original shared guard at 0x004B3172. These are diagnostic results,
not strict byte-exact acceptance.

The partial source contains defensive, distance, aerial action
and CPU state 4..11 decision paths, plus the collision-based
random follow-up choices for action IDs 0xC8, 0xC9, 0xCA and 0xCB.
The 0xCB branch adds the meter-gated random 0x0A/0x0C\ncommands and 0x14/0x1F/0x34/0x48/0x64/0x6E tiers.\nThe 0xCA branch includes the original mixed floating-point
permission and integer random-command expression. Keep natural
float-multiplication operand order and preserve fall-through
when the final random choice is nonzero.

Run only:

    scripts/repo-python workbench/nagamori-cpu/check_prefix.py

The next branch is original 0x004B4AD5 (action 0xCC).
The remaining 7,079 original bytes and their relocations,
shared return, and full owner comparison are still open.
Do not register this partial candidate as Exact.
