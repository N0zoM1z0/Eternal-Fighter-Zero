# Nagamori CPU decision boss — original Slot05 (partial)

Nagamori's original virtual slot 5 at `0x00788410` points to
`Character06::Slot05` at `0x004B2AC0`. The complete original
function occupies `[0x004B2AC0,0x004B667C)`, **15,292 bytes**,
followed by four `CC` alignment bytes. Its full original SHA-256 is
`14a83398918558355cd4ae747fa313b60f62771f1758ba870a593d29f596bfb9`.

`Character06Cpu.cpp` is a **natural C++ source draft**, not a selected
whole-function Exact. It implements the verified opening command reset,
CPU directional countdowns, button clearing, random guard choices,
opponent distance calculations, first attack-selection guards, and the
first close-range follow-ups. Its source form originated as a comparison
hypothesis using Misaki's already accepted CPU source, but was checked
against **Nagamori's own executable** and corrected: the first
close-range random threshold uses `field00a8 * 3.0f` (original x87
`fmul dword ptr [0x787ee8]`), not Misaki's multiplier 2.

The canonical original opening `[0x004B2AC0,0x004B31E3)` spans
**1,827 bytes and 502 x86 instructions**. Its first 501 instruction
forms and operands match the pinned VC7.1 draft with only numeric
branch/call destinations and external constant operands normalized.
The remaining position is the prologue frame allocation:
`sub esp,0xE8` in the full original versus `sub esp,0x60` in this
truncated translation unit, whose subsequent AI locals are absent.
The compiled partial body has 1,820 bytes and a temporary return;
this is **not byte-level/full-function Exact**.

Focused check (compiles only this TU):

```bash
scripts/repo-python workbench/nagamori-cpu/check_prefix.py
```

The next original instruction at `0x004B31E3` branches to the shared
function exit. The next unimplemented path starts at `0x004B31E8`.
Continue by independently deriving Nagamori's conditions rather than
assuming the sibling's remaining 15KB behavior is correct. A rejected
complete sibling-source hypothesis is retained privately in
`.analysis/probes/nagamori-slot05-sibling-candidate.cpp` for comparison.
