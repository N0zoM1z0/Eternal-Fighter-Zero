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

Current original prefix [0x004B2AC0,0x004B5E6E):
**13,230 bytes / 3,366 instructions**, SHA-256
a214eec93cdb6105bde7f9e5c0a4532e00309f43a00c277d0ec2c55c6ec6ce3c.

Pinned VC7.1 generates a **13,226-byte partial candidate**
with 3,368 instructions including temporary return, 245
relocations. **3,364/3,365 comparable forms**, **470
internal branch targets**, and **164 IEEE-754 literal
payloads** match the original with normalized call/
branch/constant references. The remaining frame-size
difference is 0xD4 vs target 0xE8.

The generic AI now has both ground-vs-ground and
ground-vs-airborne decision trees. The latter distinguishes
opponent rising/falling velocities, forward/vertical distance
windows and jump/meter commands. Writing the permission
factor inline rather than as a named int recovers the original
EBP-0x14 this pointer and EBP-0xD4 scratch word;
several other natural formulations failed.

Rebuild and audit only this owner:

    scripts/repo-python workbench/nagamori-cpu/check_prefix.py

Continue at 0x004B5E6E (self airborne), then
0x004B6294 (probability fallback). **Not complete Exact**
until 2,062 remaining bytes, full stack lifetime,
the shared exit and all original relocation bindings match.
