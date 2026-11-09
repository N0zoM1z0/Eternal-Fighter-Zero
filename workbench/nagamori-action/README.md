# Nagamori `Character06::Slot04` — historical source reconstruction workbench

The major **12,277-byte** action-selection boss has been **fully
accepted Strict Exact**. The production natural C++ source now lives in
`src/Character06Input.cpp`, selected pinned VC7.1 unit
`character-06-slot04`, and independent full-source/100-relocation
certificate `docs/evidence/nagamori-slot04-exact.json`.

The original Nagamori vtable slot 4 at `0x0078840C` points to
`0x004AE2E0`; original complete code spans
`[0x004AE2E0,0x004B12D5)` followed by 11 bytes of external `CC`
alignment padding. All **12,277/12,277 bytes**, the complete **3,092
x86 instructions** and **100/100 original-bound relocation sites**
strictly match the selected natural C++ source with zero differences.
The original full code SHA-256 is
`bd59aef64acf8b517eb8075e1a43d4250ef28b95973f47e0132289979f0fe26f`.

## Historical, independently useful prefix draft

The *separate* `workbench/nagamori-action/Character06Input.cpp` preserves
the early, deliberately incomplete **32-action** reconstruction.
`check_prefix.py` still compiles this partial unit and verifies all
**2,201 original instruction forms** of the first **8,824 original
code bytes**, after normalizing branch/direct-call targets and PE x87
constant addresses. Its 8,828-byte temporary output is not a full
owner. This early checkpoint is *not* an additional Exact function:
`docs/evidence/nagamori-slot04-first-actions-boundary.json` records
its original bytes and original hash as historical evidence.

The completion came from testing a full source-level candidate against
the original Nagamori x86, not from assuming another character's
code is identical. Differences in the final four button scans included
Nagamori's original **special 0xD8** action (sequence ceiling 216),
its **airborne 0xD1** fallback (ceiling 209, with no sibling-only
input-Y alternate), and the **0xCE/0xD7** conditional action variant
(`field3148 > 0`). Removing an extra copied 0xD2 branch and restoring
these real source guards produced the exact native code layout,
including the original 20-byte compiler stack frame, long branch
destinations, constant operands and common epilogue.

## Focused rebuild and strict original comparison

```bash
scripts/repo-python scripts/build-match-unit.py --unit character-06-slot04
scripts/repo-python scripts/compare-coff-function.py --unit character-06-slot04
```

These commands check only this TU against canonical EFZ.exe; they do
not perform a whole-game cold replay. All 100 COFF relocations were
independently bound to canonical target calls or verified original
IEEE-754 constants. No byte masking, code padding or overall Windows
linkage/runtime equivalence is implied by the exact owner proof.
