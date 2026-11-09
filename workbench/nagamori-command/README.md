# Nagamori `Character06::Slot02` — command-history recognizer

**Partial natural C++ workbench only; NOT an accepted full-function Exact source.**
Original Nagamori vtable slot 2 at `0x00788404` points to
`[0x004B1780,0x004B2AB5)` (**4,917 bytes**), followed by 11 `CC`
alignment bytes. Original target SHA and reviewed boundaries are in
`docs/evidence/nagamori-slot02-first-scan-boundary.json`.

The first priority scan has been reconstructed in
`Character06Command.cpp`, matching all **120 original x86 instruction
forms and operands** for original `[0x004B1780,0x004B191C)` (412
bytes) when normalizing numeric forward-jump destinations and the
original 0.0 x87 constant address. The local translation unit compiles
to **416 bytes** because it ends in a temporary 3-instruction epilogue.

Crucially, the scan begins only after a **3000 meter and exact-ground
position** requirement and recognizes command `0x5B` after a
five-stage history pattern. Several button combinations terminate
this scan without setting a command, leaving later priority scans to
run. Nagamori's actual original conditions, not assumptions from
Ikumi's similar scanner, define all branch order and signed facing
expressions. The first scan includes one original external constant
reference, not an accepted complete relocation set.

Reproduce with *only* the named C++ source and canonical executable:

```bash
scripts/repo-python workbench/nagamori-command/check_first_scan.py
```

Next: original second scan begins at `0x004B191C`, includes a
100–179-tick window and high-nibble button finishes. Subsequent
scans remain missing, so this code stays in `workbench/`, not
production `src/` or the Exact ledger.
