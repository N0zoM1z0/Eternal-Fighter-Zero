# EFZ reconstruction handoff — 2026-11-09

Start with [AGENTS.md](../AGENTS.md), then the specific source and evidence
linked below. The full Makoto state boss is now accepted as exact source,
and the pushbox resolver also has a fresh strict-ledger certificate. Recheck
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
  ledgers currently count **343 exact functions**, **1,067,344 code bytes**,
  **7,655 associated table bytes**, 374 reviewed complete boundaries and 369
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

## Accepted major boss: Makoto / Character03::Slot06

The formerly open 59,292-byte Makoto state dispatcher is now an
**accepted strict-Exact source owner**, in
[`src/Character03State.cpp`](../src/Character03State.cpp). Its target
function at `0x005E85F0` owns **58,482 code bytes**, followed by a
**500-byte (125-entry) jump table** and a **310-byte selector table**.
The selected VC7.1 `character-03-state-slot06` unit matches the **entire
59,292/59,292 bytes**, with **zero differences** and **1,386/1,386
relocations** explicitly bound to reviewed original targets.
All 127 source-local branch/table relocations match their compiled
offsets, all 220 distinct symbol target values are consistent across
references and the full relocated SHA-256 equals the original:
`430e18ae01c539e7b2b93228261cba667760633e16e0a10769910ece8aea3d2d`.

Original source reconstruction is natural C++, including all **124
explicit animation IDs and the true default**. The final stack-layout
breakthrough groups two four-byte-aligned `unsigned short` frame cache
members inside a local `FrameTiming` structure, recovering original
`[ebp-0x8]` and `[ebp-0x4]` values, the EffectSpawn home at
`[ebp-0x50]`, `this` at `[ebp-0x54]` and the `0x378`-byte stack frame.
No disassembly bytes were inserted or masked. Earlier workbench probes
and their case-by-case explanations remain in
[`workbench/makoto-state/`](../workbench/makoto-state/); older notes
claiming the case-70 6-byte mismatch are superseded by the accepted
proof [`makoto-state-slot06-exact.json`](evidence/makoto-state-slot06-exact.json).

Focused reproduction, with no global cold replay:

```bash
scripts/repo-python scripts/verify-target.py
scripts/repo-python scripts/build-match-unit.py --unit character-03-state-slot06
scripts/repo-python scripts/compare-coff-function.py --unit character-03-state-slot06
scripts/repo-python scripts/progress.py --check
```

Next substantial owner: **Shiori Slot06** (`0x004136D0`, 63,132
owned bytes including tables), plus other listed open work below.
Acceptance of this individual Makoto source is **not** equivalent to
a fully linked Windows product, runtime equivalence or an overall
clean historical certificate graph. The old broad proof-freshness
debt remains separately open.

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

## New exact Kanna constructor and actual creation callers

`Character19::Character19` at `0x00675C80` is accepted Exact:
**403/403 code bytes**, zero mismatches, four reviewed relocated
operands, authored source `src/Character19Frame.cpp`, selected unit
`character-19-constructor` and certificate
`docs/evidence/kanna-constructor-exact.json`. Its updated
`CharacterViews.h` class stays 0x3458 bytes. The two direct consumers
`scene-create-character` and `scene-loading-character` were rebuilt
and fully reverified with **3,495/3,495 (97 relocations)** and
**2,651/2,651 (76 relocations)**, respectively, including the complete
owned jump tables. Original relocation positions and target values
were retained; 25/26 compiler-local labels received a verified +8
renumbering with *simultaneous* substitutions. Certificate:
`docs/evidence/kanna-creation-consumers-exact.json`.
Only the three affected units were recompiled and strictly compared.
Other stale source-dependency certificates remain open; no full cold
replay, runtime equivalence or whole-image completion is claimed.

## Newly accepted NayukiB constructor and affected callers

`Character17::Character17` at `0x0073E790` is exact for the entire
**472-byte** function and all **4** relocations. Natural C++:
`src/Character17Frame.cpp`; selected unit `character-17-constructor`;
public proof `docs/evidence/nayukib-constructor-exact.json`. The
original 0x3458 object view now exposes eight state integers and three
64-element scratch arrays. An actual original-code mismatch in command
indices was fixed rather than ignored.

The two direct constructor consumers were rebuilt after the header
change: `scene-create-character` remains **3495/3495 Exact** with
**97** original-bound relocations; `scene-loading-character` remains
**2651/2651 Exact** with **76**. All 25/26 changed compiler-local
jump-table label names shifted by +9 and were rebound to the same
canonical branch destinations by simultaneous substitution. Proof:
`docs/evidence/nayukib-creation-consumers-exact.json`. No full cold
replay occurred; unrelated stale dependency proofs remain open.

## Newly accepted Kano constructor and affected callers

`Character20::Character20` at `0x00653A20` is fully Exact for **523
code bytes** with zero differences and four reviewed relocations.
Natural source `src/Character20Frame.cpp`, selected unit
`character-20-constructor`, and public proof
`docs/evidence/kano-constructor-exact.json`. The 0x3478 character
view has 15 zeroed child-state integers and three 64-int arrays;
the final four unknown bytes remain unwritten.

After updating the original-size class view, both actual direct
construction callers were rebuilt and strictly reverified:
`scene-create-character` stays **3495/3495** Exact (97 bound
relocations) and `scene-loading-character` stays **2651/2651** Exact
(76 bound relocations), including the complete owned jump tables.
25/26 compiler-local switch labels shifted by +17; each binding was
reviewed at its unchanged relocation position and original target
jump destination. Proof `docs/evidence/kano-creation-consumers-exact.json`.
No full cold replay or whole-linked-product claim follows from this.

## Newly accepted Akiko constructor and actual creation callers

`Character16::Character16` at `0x007219A0` now has a native strict
**511/511-byte Exact** source function with **4/4** original-bound
relocations. Selected unit `character-16-constructor`; natural source
`src/Character16Frame.cpp`; public proof
`docs/evidence/akiko-constructor-exact.json`. The 0x3468 character
view contains eleven state integers and three 64-slot arrays,
original collision and command defaults, and an unwritten four-byte
tail. Only the two actual direct creation callers were rebuilt:
`scene-create-character` remains **3495/3495 Exact** with 97
relocations, `scene-loading-character` **2651/2651 Exact** with 76.
All 25/26 compiler-local symbol changes (+13) were bound to unchanged
original jump destinations before complete code/table comparison.
`docs/evidence/akiko-creation-consumers-exact.json` retains this
focused proof. No full cold replay or whole-game linkage is claimed.

## New exact Minagi constructor and affected callers

`Character21::Character21` at `0x005A9FA0` is newly strict-Exact,
**469/469 bytes** with all **four** canonical relocation bindings.
Selected unit `character-21-constructor`, source
`src/Character21Frame.cpp`, public proof
`docs/evidence/minagi-constructor-exact.json`. The original-size
0x3458 class view exposes seven state fields, three arrays of 64
integers and a deliberately unwritten 4-byte tail.

Three actual source dependents were selectively recompiled and
independently verified: the scene creation function remains
**3495/3495 Exact** (97 bindings), the scene loading function remains
**2651/2651 Exact** (76), and the **full Makoto Slot06 remains
59292/59292 Exact** (1,386 bindings). Their 25/26/127 compiler-local
labels shifted by +9 with unchanged canonical branch targets; all
new symbol bindings were verified before accepting the receipts.
`docs/evidence/minagi-creation-consumers-exact.json` contains all
three renewed reports. No full cold replay or runtime-equivalence
claim is implied. Other historical proof freshness remains open.

## New EX Nanase constructor and full dependent exact comparisons

`Character12::Character12` at `0x006CFBB0` is now **452/452 Exact**
with four original-bound relocations. Source `src/Character12Frame.cpp`,
selected unit `character-12-constructor`, receipt
`docs/evidence/exnanase-constructor-exact.json`. Source uses the true
0x3468 child size, including the separately initialized byte at
+0x3460; sparse command fields were verified at original offsets.

Three real affected units were recompiled with the changed shared
class view and all remain Exact: `scene-create-character` 3,495
bytes/97 relocations, `scene-loading-character` 2,651/76, and
**Makoto Slot06 59,292/1,386**, including all local tables.
Their 25/26/127 compiler-local labels shifted +12 but retained
original jump target and relocation offsets; the simultaneous mapping
and full byte proofs are in
`docs/evidence/exnanase-creation-consumers-exact.json` and the fresh
Makoto receipt. No unrelated replay or linked-product/runtime claim.

## New Sayuri constructor and direct dependents accepted Exact

`Character09::Character09` at `0x004463E0` is newly strict
**419/419-byte Exact** with four independently reviewed original
relocation destinations. Natural source `src/Character09Frame.cpp`,
selected unit `character-09-constructor`, public proof
`docs/evidence/sayuri-constructor-exact.json`. The 0x3458 class view
retains seven initial state fields, three 64-int scratch arrays and
unknown trailing bytes; field3150 is 999, not zero, and the command
indices are sparse.

After updating the shared class view, the three actual dependent Exact
functions were selectively rebuilt: `scene-create-character` remains
**3495/3495** (97 relocations), `scene-loading-character` **2651/2651**
(76), and **Makoto Slot06 remains 59292/59292** (1,386), tables
included. All changed compiler-local references (25/26/127 symbols)
were rebound to the same original destinations with a +9 label shift
and independently compared in
`docs/evidence/sayuri-creation-consumers-exact.json`. This is not a
fresh replay of unrelated certificates or whole-game runtime proof.

## New Ikumi vector-array constructor is fully Exact

`Character14::Character14` at `0x006A59C0` is newly **647/647 exact**
with **11** reviewed relocations, including two real C++ `new[505]`
vector constructions and the original mode-switch call
`SetAlternateMode(0)` at `0x006AB6A0`. That called function has since
also been accepted as an independent strict Exact owner. Natural source:
`src/Character14Frame.cpp`; selected unit `character-14-constructor`;
proof `docs/evidence/ikumi-constructor-exact.json`. The original 0x3478
class view includes two new pattern/sequence arrays, two saved pointers
and the separate +0x3460 byte. The called mode-switch function is a separate owner, now also
independently strict-Exact (details immediately below).

Three real callers/header dependents were selectively rebuilt:
`scene-create-character` is still 3495/3495 exact (97 relocs),
`scene-loading-character` 2651/2651 exact (76 relocs), and Makoto
Slot06 59292/59292 exact (1386 relocs). Their 25/26/127 internal label
references shifted +20 but retained all original canonical target
values and relocation fields; full selected evidence is in
`docs/evidence/ikumi-creation-consumers-exact.json`. No cold replay.

## New exact Ikumi mode-switch helper

`Character14::SetAlternateMode(char)` at `0x006AB6A0` is now
**257/257 strict Exact** with zero relocations, natural source
`src/Character14Mode.cpp`, selected unit `character-14-alternate-mode`
and public proof `docs/evidence/ikumi-alternate-mode-exact.json`.
The original constructor calls this exact function with argument zero.
Two branch-specific loops update 64 pattern pointers in 0x98-byte
records; the function switches pattern/sequence bank pointers and the
+0x3460 mode flag in the exact original order. Reviewed thiscall
`RET 4` at the function end and complete boundary were added to the
provenance ledgers. No additional header changes or broad replays.

## Mio constructor Exact with two original x87 doubles

`Character11::Character11` at `0x00588310` is now a natural C++
**407/407-byte strict Exact** function with six original-bound
relocations, including two reads of the 0.0 double constant at
`0x7872F8`. Source: `src/Character11Frame.cpp`; selected unit:
`character-11-constructor`; receipt:
`docs/evidence/mio-constructor-exact.json`. The class view preserves
original size 0x3458, initializes doubles at +0x3140/+0x3148 and
leaves the four bytes at +0x313C unknown rather than writing zero.

The three actual shared-header consumers were selectively rebuilt:
`scene-create-character` remains **3495/3495** Exact with 97
relocations, `scene-loading-character` **2651/2651** with 76 and
Makoto `Slot06` **59292/59292** with 1,386. All 25/26/127 compiler-
local symbols shifted +7 and were mapped simultaneously at their
unchanged canonical target offsets. Focused proof:
`docs/evidence/mio-creation-consumers-exact.json`; no full replay.

## Nayuki original constructor Exact, separately from NayukiB

`Character10::Character10` at `0x00461090` is newly **455/455-byte
Exact** with **four** original-bound relocations, natural source
`src/Character10Frame.cpp`, selected unit `character-10-constructor`
and public proof `docs/evidence/nayuki-constructor-exact.json`.
Original 0x3460 class size, the nonzero +0x3148 state value 3, sparse
commands and three 64-slot arrays are all source-level, not stubs.

The three actual dependent units were selectively rebuilt and strictly
reverified after the class view change: `scene-create-character` is
**3495/3495** (97 relocations), `scene-loading-character` is
**2651/2651** (76), and Makoto Slot06 is **59292/59292** (1,386).
All 25/26/127 compiler-local references shifted +11 with unchanged
original relocation positions/targets. Proof:
`docs/evidence/nayuki-creation-consumers-exact.json`. No full cold
replay or whole-product runtime claim.

## Other open substantial work

- **Shiori Slot06**, target `0x004136D0`: newly **reviewed authored
  63,132-byte owner** with 62,273 code, 540 address-table and 319
  selector bytes. The complete unaccepted natural candidate is tracked
  at `workbench/shiori-state/ShioriState.cpp`, with private provisional
  header views and a reproducible focused VC7.1 build. Its current
  63,133-byte output is **not Exact**; differences concentrate in
  cases 303–309 and 312–318. Independently verified original boundary
  evidence lives in `docs/evidence/shiori-state-boundary-review.json`.
  A new tracked diagnostic `workbench/shiori-state/audit_case_codegen.py`
  and `case-codegen-audit.json` pinpoint the three original register-width
  drifts: 307 (`sub eax,0x7D0` target vs `edx`), 308 (`eax,0xBB8`
  vs `edx`), 315 (`edx,0x3E8` vs `eax`), with deltas +1/+1/-1.
  Normalized opcode sequences for states 300–319 are 20/20, **not**
  strict byte Exact. About three dozen natural source-form trials did
  not fix the register choices; investigate original register lifetime
  rather than removing/adding unrelated instructions.
  Do not overwrite accepted `src/` headers with the old views;
  preserved private experiments remain in `.analysis/probes/shiori-state/`.
- **Scene2::PrepareBattle** at `0x0076CA50`: now a **reviewed
  authored 4,029-byte owner** (3,893 code plus 100/20 address-table
  bytes and 16 selector bytes). The complete unaccepted C++ draft,
  isolated headers and focused VC7.1 diagnostics are tracked in
  `workbench/prepare-battle/`. Current compiled contribution is 4,031
  bytes and 115 relocation sites, not Exact. Original direct Step
  caller and complete byte/table proof:
  `docs/evidence/prepare-battle-boundary-review.json`.
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
