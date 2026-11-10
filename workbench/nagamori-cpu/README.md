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

The reviewed original prefix [0x004B2AC0,0x004B57B4)
contains **11,508 bytes / 2,915 instructions**, target SHA-256
1846fda259370ce1a13b5e0da195d6247bad897a81f41b42d6224e4d26516977.

The pinned VC7.1 build emits **11,509 bytes / 2,918 instructions**
including the three-instruction temporary return, with 203
COFF relocations. **2,914 / 2,915 target instruction forms**
agree after normalization; only the unfinished stack frame
differs (0xC8 versus target 0xE8). The focused test also
compares **401 intra-prefix branch destinations** and
**128 literal IEEE-754 payload bindings** against the original.

The reconstructed conditional decisions cover state 4..11,
defense/movement and collision reaction actions 0xC8..0xD1
plus 0xE7. The 0xE7 branch leaves the function *without* a
return on its final failed/random-miss path, falling into
the later generic decision logic at 0x004B57B4. The test
now compares every original prefix instruction including
its last natural fall-through rather than assuming an exit jump.

Only this source owner is rebuilt:

    scripts/repo-python workbench/nagamori-cpu/check_prefix.py

Continue at 0x004B57B4. This is **not Exact**: 3,784
target bytes plus the complete original frame and
relocation closure still remain.
