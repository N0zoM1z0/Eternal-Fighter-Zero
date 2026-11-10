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

The reviewed original prefix [0x004B2AC0,0x004B5163) spans
**9,891 bytes / 2,523 instructions**, canonical SHA-256
84b29c132a73c4f8a2ef6e24b8c6ad6aebad1edc8ee677cda0e82f338899e65f.

Selected pinned VC7.1 emits a **9,887-byte partial candidate**
(2,525 instructions including temporary return, 178 relocations).
**2,521 / 2,522** comparable forms agree after normalizing
branch/call destinations and floating-point literal addresses;
the incomplete stack frame is 0xC4 versus original 0xE8.
All **335 internal jump destinations** and **112 IEEE-754 literal
payloads** match their original instruction/relocation counterparts.

The source now covers the ordered collision-reaction decision
trees for actions 0xC8 through 0xCE, along with the earlier
defense, movement and CPU state 4..11 logic. The 0xCE branch
adds distinct meter, distance and random intervals and the
state 1/6/8 transition. The original near branch at
0x004B3172 correctly skips both guarded attacks. Normalized
instruction agreement does not establish complete byte-exactness.

Only build/audit this active workbench TU:

    scripts/repo-python workbench/nagamori-cpu/check_prefix.py

Continue at 0x004B5163 (action 0xCF). **Do not register Exact**:
5,401 target bytes, the full stack frame/shared exit and complete
target-bound relocation comparison are still open.
