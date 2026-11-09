# EFZ reconstruction handoff — 2026-11-09

Start with [AGENTS.md](../AGENTS.md), then the specific source and evidence
linked below. The live workbench now covers selected Makoto states through
210 and the pushbox resolver has a fresh exact-ledger certificate. Recheck
`git status` and the newest commits when resuming.

## Working agreement

- Prioritize both boss functions and small useful leaves. Test natural C/C++
  hypotheses against the canonical target, not inherited documentation.
- The operator reports no concurrent writer. Inspect and reconcile existing
  dirty or untracked work; do not reset or discard it blindly.
- Commit substantive verified increments on `main` as `gpt-web: ...`. More than
  one meaningful commit per working session is welcome. Never push without an
  explicit instruction.
- Run targeted builds and complete strict comparisons for changed functions
  and real consumers. No routine full cold replay.
- Keep source/docs in English and preserve the original executable, toolchain,
  Wine prefix, analyzer project and useful evidence. See
  [artifact recovery](RE_ARTIFACTS.md) before cleaning ignored outputs.

## Current source and proof status

- Repository: `N0zoM1z0/Eternal-Fighter-Zero`. This session added local
  `gpt-web:` checkpoints on `main` without pushing; the remote is behind.
- Canonical private target: `resources/EFZ.exe`, 3,743,744 bytes; SHA-256
  `3a1616d6c76d2eea08a95bb198d853e96cb6b9b3266e277ca1d167426dd66481`.
  `verify-target.py` passed again on 2026-11-09.
- Selected compiler/profile: VC7.1 RTM 13.10.3077, `vc71-od-static`,
  EFZ-specific Wine environment.
- `scripts/repo-python scripts/progress.py --check` passes. The reviewed
  ledgers currently count **331 exact functions**, **1,003,847 code bytes**,
  **6,845 associated table bytes**, 371 reviewed complete boundaries and 366
  reviewed origins out of 950 automatic Ghidra candidates. These are **ledger
  counts**, not a fresh replay of every certificate or a whole-game percentage.
- `scripts/repo-python scripts/validate-tracking.py --require-target` still
  fails on stale source dependencies in public comparison certificates.
  Earlier figures of *296* stale certificates and prior `Engine.h` SHA-256s
  are **historical, not a newly audited count**; this shared header has changed
  again. Inspect the actual affected dependency graph, run only affected
  replays where needed, and never edit receipts or hashes by hand.
- Whole Windows product/link/data/resource closure, independent native runtime
  comparison and portability are not complete.

## Immediate boss: Makoto / Character03::Slot06

The active substantial work is the **partial, isolated** draft
[`workbench/makoto-state/Character03State.cpp`](../workbench/makoto-state/Character03State.cpp).
Its [case-by-case README](../workbench/makoto-state/README.md) is the current
detailed record. Commits `13e9199`, `6871f0b`, `0e58464`, and `6325ad5`
reconstruct states 86–87, 96–99, 150–155 and 156–158 after the earlier
state-85 work. Later `gpt-web:` commits reconstruct 161–171, 178, 180 and 200–210;
the independent recheck removed a stray dash-momentum clear from state 178.
All remain in an isolated partial C++ owner, not in the exact ledger.

- Target function `0x005E85F0`: **58,482 bytes of code** plus 500-byte jump
  table and 310-byte selector table (**59,292 owned bytes**).
- The workbench implements **86 of 124 explicit dispatch IDs**, spread
  across selected states through 210. Its default branch is an unfinished
  marker, not real behavior; this file is not integrated into `src/` or ledgered exact.
- **Next task: implement case 211 onward**, one branch at a time from target
  instructions. Preserve unsigned pose/frame arithmetic, x87 operations,
  distinct switch dispatches, sound/effect calls, and table ownership. Do not
  blindly copy equivalent-looking cases from another character.
- Starting evidence: the workbench README, ignored
  `.analysis/probes/makoto/state-case-map.csv` and
  `.analysis/probes/makoto/state-code-005e85f0.txt`, tracked
  `docs/evidence/makoto-state-case-map.csv` and the Makoto state section of
  [KNOWLEDGE_BASE.md](KNOWLEDGE_BASE.md).
- Preserve current `build/makoto-state/Character03State.obj` and
  `Character03State.HEAD-verify.obj`. Earlier named trial objects and
  disassemblies were archived losslessly under
  `.analysis/cleanup/2026-11-09/retired-makoto-trial-disassemblies-and-objects.tar.gz`;
  [RE_ARTIFACTS.md](RE_ARTIFACTS.md) gives the manifest and restore command.
- Do **not** ledger this state owner until its full function, relocations and
  810 associated table bytes match. Makoto CPU Slot05 and effects Slot07 are
  separate, previously ledgered exact owners.

## Pushbox status: complete local codegen exact and ledgered

`Scene3::ResolvePushboxes` at `0x00766B50` is **not** a still-failing
12-byte relocation candidate. Commit `cabe2d9` repaired the natural source
in [`src/SceneBattlePushboxes.cpp`](../src/SceneBattlePushboxes.cpp); `4085f80`
records the source-level breakthrough in KNOWLEDGE_BASE.md.

On 2026-11-09 a fresh targeted build and strict comparison of
`scene-battle-resolve-pushboxes` returned **exact**: 2,727/2,727 bytes,
zero differences and all **35 relocation bindings** at their target offsets.

The solution uses standalone conditional expressions `(condition) ? 1 : 0;`
for four otherwise-unused boundary predicates. VC7.1 `/Od` still generates
the original 32-bit stores while assigning the correct stack homes to `this`,
pose pointers and both hidden `SurfaceRect` returns. Two early returns
must remain in their `CollisionSide()` branches but outside the nested
velocity tests. Old notes claiming relocation 617→629 or an unmatched 2,727
bytes are **superseded historical probes**, not the current defect.

The origin of `0x00766B50` was reviewed as **authored** from its scene
simulation caller `0x00763C20` and collision-specific callees at
`0x0040FF70`, `0x00767600`, and `0x00767930`. It now has a source row, an
exact-ledger row, and the fresh standalone certificate
[`scene-pushboxes-exact.json`](evidence/scene-pushboxes-exact.json).
The public ledger count therefore increases to 329. This is local complete
codegen evidence, not a Factory-accepted replay or a whole-game result;
old unrelated certificate dependencies still need selective refresh.

Focused reproduction (no full cohort):

```bash
scripts/repo-python scripts/verify-target.py
scripts/repo-python scripts/build-match-unit.py --unit scene-battle-resolve-pushboxes
scripts/repo-python scripts/compare-coff-function.py --unit scene-battle-resolve-pushboxes
```

The neighboring collision dispatch, body/effect hit and geometry helpers are
already ledgered exact. Avoid reopening them without target evidence.

## Newly accepted Kaori constructor and affected creation callers

Character13/Kaori constructor at `0x00638D90` is **Exact** for the complete
383-byte function under `vc71-od-static`; all four target relocations and
the original 13-slot vtable/string operands were reviewed. Accepted natural
source: `src/Character13Frame.cpp`, selected unit
`character-13-constructor`, certificate
`docs/evidence/kaori-constructor-exact.json`. The class view in
`src/CharacterViews.h` now exposes five initialization integers and three
64-element scratch arrays with unchanged 0x3450 object size.

Because this view changes compiler-local labels, both actual constructor
callers were rebuilt and strictly compared, not assumed unchanged:
`scene-create-character` remained **3495/3495 Exact** with 97 bound
relocations, and `scene-loading-character` remained **2651/2651 Exact**
with 76 relocations (both include full switch table ownership). New
proof: `docs/evidence/kaori-creation-consumers-exact.json`. The 25/26
rebound internal label names were individually checked by original
jump destinations and complete bytes. Reproduce only these three units
with `build-match-unit.py --unit ...` then `compare-coff-function.py`.
The remaining historical `CharacterViews.h` certificate staleness is
not cleared; do not relabel proofs or invoke a full cold replay.

## Newly accepted MizukaB constructor and direct creation callers

`Character18::Character18` at `0x004D2850` is now a complete
**396/396 exact** source function in `src/Character18Frame.cpp`.
The selected unit is `character-18-constructor`, with four independently
reviewed relocation destinations; public certificate:
`docs/evidence/mizukab-constructor-exact.json`. Its `CharacterViews.h`
child view preserves the original 0x3460 size with four state integers,
three 64-int scratch arrays, and six trailing state fields.

This type-view update changes *compiler-local* symbols in the two actual
construction callers. Rebuilt `scene-create-character` remains
**3,495/3,495 exact** with 97 relocations; `scene-loading-character`
remains **2,651/2,651 exact** with 76 relocations, including their
96/100-byte internal jump tables. All 25/26 shifted local-label
operands were matched by original relocation offsets and target
jump destinations and strict code bytes, not by invented masks.
Certificate: `docs/evidence/mizukab-creation-consumers-exact.json`.
Targeted reproduction: `scripts/repo-python scripts/build-match-unit.py
--unit <name>` followed by `scripts/repo-python
scripts/compare-coff-function.py --unit <name>` for only these three
names. Do not claim this refreshes other stale `CharacterViews.h`
certificates or the unbuilt Windows product.

## Other open substantial work

- **Shiori Slot06**, target `0x004136D0`: 63,132 owned bytes including tables;
  unfinished natural-C++ candidate. Start at
  `.analysis/probes/shiori-state/README.md` and its parked-best evidence.
  Do not overwrite newer shared headers from a parked snapshot.
- **Scene2::PrepareBattle** at `0x0076CA50`: 3,893 code bytes plus 136
  selector/address bytes; read `.analysis/probes/scene-loading/README.md`.
- **Video pixel kernels** in `src/VideoCharacterDraw.cpp`:
  `DrawSurface` (799 bytes), `DrawBlendedSurface` (897),
  `DrawCharacterTint` (865), `DrawShadowSurface` (806),
  `DrawCharacterSpecial` (808). Reviewed units/natural C++ exist, but no
  accepted complete strict match. Clipping correction `03dc557` is
  semantic progress, not an Exact verdict. See KNOWLEDGE_BASE.md.
- Explore other substantial owners as evidence warrants, and smaller leaves
  where they unblock callers; this is not an exhaustive queue.

## Minimal operational loop

```bash
git status --short --branch
git log -5 --oneline
scripts/repo-python scripts/verify-target.py
scripts/repo-python scripts/verify-toolchain.py --check
# For an existing COMPLETE unit after a source edit:
scripts/repo-python scripts/build-match-unit.py --unit ACTUAL_UNIT_ID
scripts/repo-python scripts/compare-coff-function.py --unit ACTUAL_UNIT_ID
# Metadata freshness only; currently expected to report stale dependencies:
scripts/repo-python scripts/validate-tracking.py --require-target
```

A complete local comparison is not a substitute for reviewed origin and
accepted evidence. For a partial owner (Makoto Slot06), inspect the workbench
and target instructions first. Check `progress.py --check` after ledger edits.
Historical reader/audio drafts in `workbench/reader-audio` are already
integrated; do not reapply their patch. Archived experiments are recoverable
via RE_ARTIFACTS.md.
