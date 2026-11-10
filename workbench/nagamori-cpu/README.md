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

The reviewed original prefix [0x004B2AC0,0x004B5C25)
covers **12,645 original bytes / 3,211 instructions**,
SHA-256 baff0e79b3f6aeee3840f1c8b0091439056cff4a65795cdce0be1c20d5fba08b.

Selected pinned VC7.1 yields a **12,641-byte partial
COFF candidate** (3,213 instructions including temporary
epilogue, 228 relocations). **3,209 / 3,210 comparable
forms** agree; only the unfinished stack frame 0xD0
versus original 0xE8 differs. The target prefix ends in
a shared-exit jump absent from the incomplete source.
All **445 internal branch destinations** and **148 original
float/double literal payloads** match this selected source.

The source includes action-specific defensive/movement
decisions and 0xC8..0xE7 collision reactions. It now
also restores the 25x-probability generic ground-vs-ground
decisions through 0x004B5C25: distance windows,
attack inputs, meter commands, rare CPU states and one
original unreachable roll window. The original x87 compare
at 0x004B5B75 requires opponentY > positionY to obtain
the correct instruction order/branch polarity.

Run only:

    scripts/repo-python workbench/nagamori-cpu/check_prefix.py

Continue at 0x004B5C25 (airborne-opponent branch), then
0x004B5E6E (self-airborne), 0x004B6294 (chance fallback).
**Not Exact** until remaining 2,647 bytes, complete
stack and all original relocation bindings are closed.
