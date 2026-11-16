# Character00 / Nanase constructor natural-C++ experiment

This is an independent source-level reconstruction experiment for the reviewed
constructor at `0x0048A720` (642 native bytes, selection ID0, resource `nanase`,
vtable `0x00788334`, object allocation size `0x3470`). The source is
`Character00Constructor-natural.cpp`; it is ordinary C++ and contains no inline
assembly, emitted opcodes or padding.

The current implementation preserves the constructor's observed behavior:

- calls the `Secondary` base constructor, installs the child vtable and copies
  the `nanase` resource string;
- sets `surfaceCount` to `0x29C` and initializes the five collision X/Y pairs;
- initializes the child counters at `0x3138..0x3148`, the three 64-entry integer
  arrays at `0x314C`, `0x324C`, `0x334C`, and the three integers at
  `0x344C..0x3454`;
- allocates two distinct arrays of 505 eight-byte entries, stores their pointers
  at `0x345C` and `0x3460`, and invokes the original vector-constructor helper
  semantics for each array;
- writes command count 5 and the observed command bytes, then calls the natural
  `Character00ObjectView::SetMode(0)` helper.

## Current build observations

The selected VC7.1 `/Od /G6 /MT /Gy /W3` build compiles the main constructor to
684 bytes versus 642 native bytes, with 11 COFF relocation sites. It is **not**
Exact and is deliberately not in `implemented.csv` or the Exact ledger. The
257-byte `SetMode` helper has the correct extent but currently retains one raw
instruction-byte difference at `0x0048E156`. The two element-constructor bodies
and all call/data operands still require independent original binding before
any acceptance claim.

A first high-level `new[]` attempt did not preserve both independent arrays in
the emitted object. The current version therefore uses explicit C++ allocation,
array-cookie initialization and the native vector-constructor helper call; it
keeps both arrays distinct without assembly or hand-authored bytes. Continue by
matching compiler lifetimes/register allocation and binding every relocation,
not by masking or padding the object.

The target helper at `0x0048E140` toggles the primary/alternate pattern and
secondary sequence pointers and copies the selected pattern pointer into 64
records at stride `0x98`. Its current C++ implementation is kept local to this
workbench so the provisional shared class views are not widened prematurely.
