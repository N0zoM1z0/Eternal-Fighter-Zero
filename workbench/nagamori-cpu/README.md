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

Current original prefix [0x004B2AC0,0x004B6294):
**14,292 bytes / 3,640 instructions**, SHA-256
47897f4117416f2806f0bc2bd0ed47f77e116f2001940140141be758a3c6aaea.

Pinned VC7.1 emits a **14,288-byte candidate**
(3,642 instructions including temporary return,
273 relocations). **3,638/3,639 comparable forms**,
**516 internal branches** and **187 IEEE-754
literal bindings** match the target. Incomplete
stack frame: 0xE0 versus original 0xE8.

Generic AI now covers both opponent-airborne and
self-airborne reactions as well as the earlier
grounded decisions. Inline permission expressions
preserve target EBP-0x14 this-pointer home and deep
EBP-0xD8/-0xE0 local scratch slots.

Only this TU is rebuilt for workbench validation:

    scripts/repo-python workbench/nagamori-cpu/check_prefix.py

Next original block: 0x004B6294, final 1,000
bytes and the complete shared exit. **Not Exact**
until all code and original relocations match.
