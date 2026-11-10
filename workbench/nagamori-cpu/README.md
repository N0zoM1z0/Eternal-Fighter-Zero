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

The reviewed original prefix [0x004B2AC0,0x004B4EE0) is
**9,248 bytes / 2,369 instructions**, with SHA-256
79edb44825253ede8658dc0e1b936a26670f954a3268580c9047f1ce0dca9bc9.

Selected VC7.1 emits an **9,244-byte partial COFF function**,
2,371 instructions including the temporary return, and 167
relocations. **2,367 of the first 2,368 comparable original
instruction forms** agree after branch/call/FP-address normalization.
The incomplete stack allocation is 0xC0 rather than target 0xE8;
the final original prefix jump reaches the unimplemented shared exit.
The diagnostic also verifies **310 internal branch destinations**
by instruction ordinal and all **107 original float/double
literal payloads** at corresponding source relocation sites.

This audit caught five previously hidden source-value errors even
though their machine instruction forms had matched: original
distance 40.0 rather than 45.0 or 60.0, two original 3x
probabilities rather than 1x, and the 0xCC distance limit
135.0 rather than 70.0. A deliberately wrong 70.0 compile
was rejected; restoring 135.0 passed the focused native check.

The source has complete natural-code forms for the recovered
defensive, grounded, aerial-start, CPU state 4..11 and
collision-follow-up action 0xC8/0xC9/0xCA/0xCB/0xCC/0xCD branches.
The new 0xCD decision tree retains the original random, grounded,
distance and meter checks and ends in a guaranteed shared return.
The original 0x004B3172 guarded jump spans both nearby attacks.
Keep the original random and x87 expression evaluation order.

Reproduce just the partial owner with:

    scripts/repo-python workbench/nagamori-cpu/check_prefix.py

The next original block is 0x004B4EE0 (action 0xCE).
This remains unfinished; **do not claim Exact** until all
15,292 bytes, complete relocations, and the shared return match.
