# Nagamori `Character06::Slot04` — 12,277-byte original action boss

**Actual partial C++ source, not yet whole-function Exact.** Original
Nagamori vtable slot 4 at `0x0078840C` points to `0x004AE2E0`. Its
complete unpadded owner spans `[0x004AE2E0,0x004B12D5)` (12,277 code
bytes), followed by 11 `CC` alignment bytes. The exact original SHA
and the currently matched prefix are in
`docs/evidence/nagamori-slot04-first-actions-boundary.json`.

## Reconstructed source

`Character06Input.cpp` is isolated natural C++, not accepted in `src/`.
The first **32 priority-ordered action guards** now match the original
**8,824-byte / 2,201-instruction prefix**, ending before the far jump
at `0x004B0558`. This includes buffer/timer updates, special-meter
tiers, grounded and airborne action variants, direction and collision
windows, and four air/ground dash transitions.

The original action gates include command tiers `0x34`, `0x5B`,
`0x7A`, `0x79`, `0x78`, `0x70`, `0x6F`, `0x6E`, `0x66`, `0x65`,
`0x64`, `0x2A`, `0x29`, `0x28`, `0x16`, `0x15`, `0x14`, `0x20`,
`0x1F`, `0x1E`, `0x0C`, `0x0B`, `0x0A`, `0x06` and commands 0/1.
Duplicate command IDs at different priorities select distinct action
animations and conditions; they must not be collapsed.

Original action x87 guards were checked instruction by instruction.
The airborne 0x0C/0x0B/0x0A group requires `positionY < 0.0`, not
zero or positive Y. The later 0x0C variants require zero Y, with
`field3148` selecting between results; their sequence caps must
remain in original order. The first `0x06` air action increments the
`airActionCount` byte and chooses 0x0E/0x0F/0x10 from `inputX`
(original object offset +0x188) compared to `facing`.

The four later direction actions compare the opponent's X coordinate
with this character's X and a signed input-derived multiplier. The
two airborne branches choose 0xA5 or 0xA6 and increment dash/action
counts. Two ground branches choose 0xA3 or 0xA4. These expressions
were initially adapted from another *already exact* character source,
but **Nagamori's own canonical x86** independently confirms every
one of the **2,201 instruction forms**, with only numeric local jumps,
original external call targets, and x87 PE constant addresses
normalized. All register choices, stack operands and frame size now
match. Two genuine local FP temporaries naturally caused VC7.1 to
emit the original **`sub esp,0x14`** prologue; no inert stack padding
or inserted machine bytes were used.

## Focused replay (only this translation unit)

```bash
scripts/repo-python workbench/nagamori-action/check_prefix.py
```

The source presently compiles to **8,828 bytes** with 73 COFF
relocations, including a *temporary four-byte local epilogue*. The
target prefix is 8,824 bytes and must eventually jump to the original
shared exit at `0x004B12D1`. The **remaining 3,453 code bytes** and
later actions are still missing. Complete 12,277-byte bytes/relocations
have **not** been selected/accepted Exact, and the code has deliberately
not been integrated into production `src/`.

Next original action group begins at `0x004B055D`. Continue the
original branch priority and preserve source-level expression order
because it determines VC7.1 register allocation and x87 codegen.
No broad cold replay is needed for these focused experiments.
