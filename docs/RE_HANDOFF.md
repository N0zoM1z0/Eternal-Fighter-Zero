# EFZ reconstruction handoff

Follow [AGENTS.md](../AGENTS.md). Current accepted source is `src/`; counts
come from [PROGRESS.md](PROGRESS.md) and the canonical ledgers. Search the
relevant sections of [KNOWLEDGE_BASE.md](KNOWLEDGE_BASE.md) for target facts
and failed hypotheses. Inspect current Git changes before starting.

## Receiving agent — Nayuki state boss completed (2026-11-11)

**Character10::Slot06 now has a COMPLETE original-bound Exact codegen
certificate**, not just a selected prefix. Its authored source is
`src/Character10State.cpp` with 62,693 canonical code bytes plus
all 858 local switch-table bytes, **63,551 / 63,551 matched** and
**1,433 original-bound COFF relocations independently verified**.
All 137 original live case IDs, original physical code order, complete
0x2B4 stack frame, both native switch tables and shared return are
closed. Formal evidence:
`docs/evidence/character-10-state-slot06-exact.json`.
Read [the full reconstruction record](../workbench/nayuki-state/README.md)
for the original incremental state and repair history.

Run ONLY selected checks when working on this owner:

    git status --short --branch
    scripts/repo-python scripts/replay-exact-units.py --unit character-10-state-slot06
    scripts/repo-python scripts/validate-tracking.py --check-proofs --unit character-10-state-slot06
    scripts/repo-python scripts/ci.py

Do not run all-unit cold replay, do not push without permission.
Continue attacking other substantial unimplemented functions and
small exact leaf owners. Preserve dirty edits (single writer).
Native codegen Exact is *not* a whole-product/runtime completion claim.

## Active next boss: Kano Character20::Slot06 (partial)

Original Kano `Character20::Slot06` owns **68,853 native code bytes**;
its authored C++ `workbench/kano-state/Character20State.cpp` now
reproduces selected original `[0x006429C0,0x0064C750)`, **40,336
bytes / 11,096 x86 instructions**. Default plus **102 live cases**
reviewed. The strict checker binds **1,032 internal / 136 outbound
original branch targets**, **906 native-bound nonlocal COFF calls/
IEEE-754 references** and two original switch addresses.

The new **822-byte state249** implements a long original airborne
throw: opponent facing/position and animation changes on frames0–5,
damage `ApplyDamage(1200,500.0)`, opponent knockback (-1.0,-2.3),
original horizontal shake and offset, strict landing threshold,
frame12 gravity and frame-loop exit. **Next case250 starts at
`0x0064C750`**. Candidate stack0x148 vs original0x4A4 uses equal
six-byte allocation width without offset normalization.
**34 missing native case bodies**, original full frame, local switch
DATA and shared return are OPEN; NOT whole Exact. Markers unaccepted.
Only scoped Kano checker, no full all-unit cold replay or push.

The next Kano state250 at `0x0064C750` has authored exploratory
charge/dual-effect C++ but is **not native-reviewed yet**. The local
probe first differs in register assignment at `0x0064C955` during
the animation rewind tail; the original 585-byte case is not accepted.
See `workbench/kano-state/README.md`; preserve and refine this work.

Kano experimental case251 has also been authored in
`workbench/kano-state/Character20State.cpp`, including the original
500/250 resource reduction and two local effects. The new scoped
`workbench/kano-state/check_case251_shape.py` checks all 454 native
bytes' instruction locations/widths, 117 register-abstracted opcode
forms, 7 original internal jump edges and 7 independently bound
native COFF operands. It is **NOT Exact** because scratch registers
and one equivalent ADD encoding differ; original case250's tail also
remains open. No new complete function or selected-prefix credit.
See the Kano README for the precise scope and mismatch evidence.

Kano case254 now also has **835 bytes / 223 original instruction
positions and register-abstracted shapes** from authored natural C++.
The separate `workbench/kano-state/check_case254_shape.py` verifies
20 native internal branches, 3 shared-return jumps and 10 independently
original-bound COFF call/float operands. This is **NOT Exact**:
concrete register bytes still differ after the unresolved case250.
The contiguous selected prefix remains 40,336 bytes; Kano state251
and state254 are structural islands, not formally accepted owners.
Real original code correction included grouped facing/input offset
arithmetic and the `owner` (not `field0028`) effect field.

Kano cases255/256 are now also authored as full separate tiered
charged attack bodies (858 bytes each). Their dedicated original-bound
`check_case255_256_shape.py` audit verifies **456 x86 original
instruction offsets and register-abstracted forms**, **40 native
internal and 6 canonical shared-return jumps**, **20 independently
bound original COFF call/float operands**. Correct distinct full-
charge fallback values 5000/2500, launch types 0x1BC/0x1BD, meter
spend 20/50, and effect owner/coordinate grouping are coded.
**NOT Exact**: concrete native registers still differ due unresolved
state250. The strict Kano selected prefix remains 40,336 bytes.
See Kano README. No cold all-unit replay.

Kano case257 is now also authored as a **899-byte complete natural
C++ state body** with dedicated original-bound *structural* diagnostic
`workbench/kano-state/check_case257_shape.py`: all 241 x86 native
instruction offsets/register-abstracted forms, 22 internal branches,
3 shared-return targets and 10 original-bound native COFF call/float
operands match. Its frame17 0x191 effect differs from other charged
tiers, as does frame19 rewind and `field316c` counter.
**NOT Exact**: the contiguous strict prefix remains 40,336 bytes
because state250's concrete-register mismatch is still open. This
work is documented and committed, not added to Exact ledgers.

Kano state257 adds another **899 bytes of natural C++ source** with
original native structural proof: 241 instruction positions/forms,
22 internal and 3 canonical return branches, ten original-bound COFF
call/float references. The tier-specific frame17 effect0x191 and
frame19 repeat differ substantially from prior tiers. The dedicated
`workbench/kano-state/check_case257_shape.py` passes and documents
the exact canonical extent/SHA. **This is NOT Exact**: concrete
register bytes still differ after original case250, so the strict
selected prefix remains **40,336 bytes**. See Kano README. No cold
all-unit replay.

Kano charged state258 now also has actual authored natural C++,
**1,254 native original bytes / 330 original instruction positions**
with a dedicated `check_case258_shape.py` audit. It independently
validates **23 native internal branches, 3 shared return paths,
14 original-bound COFF/IEEE-754 operands**, and all register-abstracted
instruction forms. Three impact effects have distinct Y offsets,
resource deduction, sound and facing/owner write order. The
**state250 register divergence remains open**, so case258 is an
unaccepted structural island, NOT complete Exact; strict contiguous
Boss prefix remains 40,336 original bytes. No cold all-unit replay.

## Additional newly accepted leaf owners

Kaori `Character13` now has seven complete strict Exact normal-C++
virtual/lifecycle owners in `src/Character13Lifecycle.cpp`: full
283-byte initializer, 58-byte reset, 80-byte effect removal,
19-byte Slot03, two 11-byte delegates and 47-byte emitter.
All **509/509 original bytes**, five original-bound direct call
relocations, seven vtable targets and reviewed function boundaries
are confirmed by selected replay. Evidence:
`docs/evidence/character-13-lifecycle-exact.json`. No shared header
or accepted constructor was edited. Targeted unit IDs start with
`character-13-`; no full cold replay was run.

MizukaB `Character18` now also has **seven complete native Exact
functions / 670 bytes**, including the nontrivial 179-byte Slot08
resource timer in `src/Character18Lifecycle.cpp`. Eight original-
bound COFF calls/float references and seven vtable targets were
independently checked. Public selected proof:
`docs/evidence/character-18-lifecycle-exact.json`. The strict replay
ran only these seven new functions, not a whole repository cold replay.

Kanna `Character19` additionally has **six complete Exact lifecycle/
virtual owners / 490 machine-code bytes** in
`src/Character19Lifecycle.cpp`. The six canonical vtable targets and
four base-method calls were independently verified, with strict
selected receipts at `docs/evidence/character-19-lifecycle-exact.json`.
No full all-unit cold replay was run; no whole-game claim.

Kano `Character20` now additionally has **five complete native Exact
lifecycle/local-effect owners / 617 code bytes** in
`src/Character20Lifecycle.cpp`, including a 413-byte initializer
and five independently reviewed original vtable/call bindings.
Evidence: `docs/evidence/character-20-lifecycle-exact.json`.
Only those five units were replayed, not an all-unit cold replay.

Minagi `Character21` now has **seven complete Exact lifecycle
and local-effect functions / 666 original code bytes** in
`src/Character21Lifecycle.cpp`. The 440-byte initializer constructs
and emits real effect0x190 after clearing original state/arrays.
All nine original REL32 calls and vtable targets were reviewed; formal
selected proof `docs/evidence/character-21-lifecycle-exact.json`.
Only these seven units were replayed, not a repository-wide cold replay.

NayukiB `Character17` has **six complete exact lifecycle/timer
owners / 767 original machine-code bytes** in
`src/Character17Lifecycle.cpp`. The meaningful 241-byte `Slot08`
countdown has the original surprising 50–149 state gate; all five
base-method call operands and six canonical vtable locations are
verified. Certificate: `docs/evidence/character-17-lifecycle-exact.json`.
Only these six units were replayed, not all-unit cold replay.

Akiko `Character16` now has **five complete Exact lifecycle and
local-effect owners / 565 native code bytes** in
`src/Character16Lifecycle.cpp`. Each original vtable and five base
calls were independently checked; strict selected replay proved
565/565 and zero differences. Certificate:
`docs/evidence/character-16-lifecycle-exact.json`. Only these five
units were replayed, never full all-unit cold replay.

Mio `Character11` now has **six complete Exact lifecycle and effect
owners / 506 original code bytes** in `src/Character11Lifecycle.cpp`.
Nine reviewed original-bound COFF operands include four double-zero
DIR32 literals and five direct base calls. Six complete owners pass
strict selected replay 506/506, zero differences. Proof:
`docs/evidence/character-11-lifecycle-exact.json`.
Only these six units were replayed; no full cold replay.

EX Nanase `Character12` now has **six complete native Exact
lifecycle/effect owners / 537 original code bytes** in
`src/Character12Lifecycle.cpp`. Five original base method direct
calls and six canonical original vtable pointers are reviewed;
selected strict replay gives 537/537 bytes with zero differences.
Evidence `docs/evidence/character-12-lifecycle-exact.json`.
Only the six selected units were replayed, not all-unit cold.

EX Nanase `Character12::Slot08` has also been reconstructed as a
**complete original 789-byte Exact virtual**, not a partial prefix,
in `src/Character12Slot08.cpp`. It builds an EffectSpawn, gates special
state0x140, cycles eight tint stages and emits randomized effects.
Its **18 independently original-bound relocations**, all complete
789 native code bytes, and real original vtable slot0x788E04
pass selected strict replay with zero differences.
Evidence: `docs/evidence/character-12-slot08-exact.json`.
Only this unit was replayed, no all-unit cold replay.

Mio `Character11::Slot01` is now a **complete native Exact
975-byte dual sprite-gauge render function** in
`src/Character11Render.cpp`. It reads original pattern 43/44 frame0,
computes real source/destination rectangles and draws to Video using
the original two direct calls. All **8 original COFF REL32 targets**
(six MakeSurfaceRect and two DrawSurface) are independently bound;
975/975 native code bytes match, no differences. The called Video
render routine remains separately unaccepted. Proof:
`docs/evidence/character-11-slot01-exact.json`.
Selected one-unit replay only; no cold all-unit replay.

## Tools and checks

Canonical target: ignored `resources/EFZ.exe`, SHA-256
`3a1616d6c76d2eea08a95bb198d853e96cb6b9b3266e277ca1d167426dd66481`.
Use pinned VC7.1 RTM 13.10.3077, the EFZ Wine prefix and existing Ghidra project.
See [SHARED_TOOLS.md](SHARED_TOOLS.md) for local runtime access.

```bash
git status --short --branch
scripts/repo-python scripts/verify-target.py
scripts/repo-python scripts/verify-toolchain.py --check
scripts/repo-python scripts/ci.py
# Compile/compare only a selected complete owner and actual affected consumers:
scripts/repo-python scripts/replay-exact-units.py --unit character-06-slot02
```

Daily CI checks basic consistency without private tools. Historical source and
header hashes in some certificates are stale. Audit a specific certificate with
`validate-tracking.py --check-proofs --unit NAME` when useful; establish current
exactness through its native comparison. Do not hand-edit historical hashes or
run a full cold cohort to tidy documentation.

## Accepted owners to leave accepted

Makoto Slot06, Nagamori Slot05/Slot04/Slot02, Ikumi Slot02 and Scene3 pushboxes are
complete Exact owners. The match ledger identifies their current certificates
and source recipes. Do not reopen them from obsolete partial-draft measurements.
Reader/audio integration is complete in `src/`.

Nayuki Character10::Slot07, its 20,517-byte native
effect-state boss, is **complete strict Exact**
with original 4,644 x86 code instructions and
both 112/100-byte local switch tables. Original
contribution 20,729/20,729 exact bytes, all
264 independently original-bound COFF relocations,
zero differences and full original 0x1D4 frame.
Source src/Character10Effects.cpp; proof
docs/evidence/character-10-slot07-exact.json.
Selected replay only:
scripts/repo-python scripts/replay-exact-units.py --unit character-10-slot07.
The prior dirty workbench and extra sibling-only cases
were reconciled before retirement. Do not claim
whole-game runtime/linkage from this single Exact
native codegen unit; Nayuki Slot06 remains open.


Nayuki Character10::Slot01 render overlay is also strict
Exact: 939/939 bytes, 280 x86 instructions and 8/8
original-bound MakeSurfaceRect/Video::DrawSurface calls.
Accepted natural source src/Character10Render.cpp,
evidence docs/evidence/character-10-slot01-exact.json,
selected replay character-10-slot01. This is not
whole-game runtime/linkage equivalence.


Nayuki Character10::Slot04 action boss is now **complete
strict Exact native codegen**: 10,605 original bytes
/ 2,690 x86 instructions, original 0x14 frame/EBX
push-pop and full shared return, 86/86 original-bound
COFF relocations, zero differences. Complete source
src/Character10Action.cpp, acceptance evidence
docs/evidence/character-10-slot04-exact.json.
Run only:
scripts/repo-python scripts/replay-exact-units.py --unit character-10-slot04.
The Nayuki action workbench was entirely reconciled
and retired; whole-game runtime/linkage is separate.


Nayuki Character10::Slot05 CPU boss is now **complete
native strict Exact**: 13,259/13,259 original code
bytes, 3,391 original x86 instructions, full 0xC0
stack frame/shared return, **232/232 original-bound
COFF relocations**, zero differences. Accepted natural
source src/Character10Cpu.cpp with proof
docs/evidence/character-10-slot05-exact.json.
Reproduce with the selected-only unit:
scripts/repo-python scripts/replay-exact-units.py --unit character-10-slot05.
The formerly dirty Slot05 workbench was reconciled
into accepted source before retirement. Nayuki Slot04
was separately completed and accepted as Exact; the
remaining major Nayuki state boss is Slot06. Whole-game
linkage and runtime equivalence remain open.


Nayuki Character10::Slot02 is now full native strict
Exact: 4,827/4,827 code bytes, all 1,395 original
instructions, zero relocations/differences.
Full natural source src/Character10Commands.cpp,
proof docs/evidence/character-10-slot02-exact.json.
Run only selected replay:
scripts/repo-python scripts/replay-exact-units.py --unit character-10-slot02.
The dirty prefix workbench was reconciled into
accepted source before removal; no full cold replay.


Nayuki Character10 now has six newly accepted native strict Exact
virtual/lifecycle functions from the original 0x00788270 vtable:
InitializeState (335 bytes), ResetPose (58), RemoveLocalEffect (80),
Slot03 (19), Slot08 (11) and EmitLocalEffect (47).
They are full natural C++ in src/Character10Lifecycle.cpp
and reproduce **550 original bytes, five canonical call relocations,
zero byte differences**. Each character-10-* unit was replayed
separately and has proof under docs/evidence/. Their addition
does not change class layout or imply whole-product linkage.


Sayuri Character09::Slot05 CPU is **complete native strict Exact**:
12,330 original bytes / 3,172 i386 instructions,
original 0xD8 frame and shared return, 237/237
original-bound relocations, zero byte differences.
Full natural C++ source src/Character09Cpu.cpp,
evidence docs/evidence/character-09-slot05-exact.json.
Reproduce just the selected unit:
scripts/repo-python scripts/replay-exact-units.py --unit character-09-slot05.
The original workbench was reconciled and retired;
whole-product linkage/runtime remains a separate task.


Sayuri Character09::Slot02 input-history command interpreter is now
complete native strict Exact: 5,995 bytes / 1,752 x86 instructions,
the original 0xC stack frame, 8/8 original-bound floating relocations,
zero differing bytes. Accepted full source is
src/Character09Commands.cpp, with proof
docs/evidence/character-09-slot02-exact.json.
Rebuild only using
scripts/repo-python scripts/replay-exact-units.py --unit character-09-slot02.
The original workbench candidate was reconciled into accepted source,
then retired. No full-game cold replay or runtime proof is claimed.


Sayuri Character09 now also has complete strict Exact
ResetPose (58 bytes at 0x004466D0) and InitializeState
(309 bytes at 0x00446590). Both source owners are in
src/Character09Lifecycle.cpp, with one original-bound
base-method relocation each. Selected replay units:
character-09-reset-pose and character-09-initialize-state.
The initializer includes all original signed short offsets
and the 64-entry effect-bank reset; no full cold replay was run.


Three more Sayuri Character09 virtual owners are complete native
strict Exact: Slot01 at 0x004492F0 (11 bytes, no relocations),
Slot03 at 0x00446760 (19 bytes, one original UpdateLocomotionState
call), and EmitLocalEffect at 0x00449390 (47 bytes, one original
direct base emitter call after virtual removal). Accepted sources
src/Character09Delegates.cpp and src/Character09EmitEffects.cpp;
selected units character-09-slot01, character-09-slot03,
character-09-emit-local-effect, with independent proof JSON under
docs/evidence/. No common headers or existing acceptance owners
were modified.


Sayuri Character09::Slot04 is now **complete native strict Exact**:
11,119/11,119 code bytes, 2,815 instructions, the full
0x14 native stack frame and 95/95 original-bound relocations,
zero differences. Its source is src/Character09Input.cpp;
certificate docs/evidence/character-09-slot04-exact.json.
Run only:
scripts/repo-python scripts/replay-exact-units.py --unit character-09-slot04.
The old partial workbench was retired and its dirty source
reconciled into accepted src/ prior to removal.


Sayuri Character09 now has two newly accepted native Exact owners:
Slot08 at 0x00449300 (131 bytes) and RemoveLocalEffect at 0x00446710
(80 bytes). Natural source is src/Character09Effects.cpp; each has
one original-bound REL32 and zero byte differences. Rebuild only
character-09-slot08 or character-09-remove-local-effect. No shared
class-layout changes were needed.


The explicit-X facing member Secondary::FacePosition(double) at
0x0040E6C0 is complete native Exact (116 bytes / zero relocations),
with source src/SecondaryFacePosition.cpp and proof
docs/evidence/secondary-face-position-exact.json. Its nonvirtual
declaration in Engine.h does not change object layout; selected
neighbor owners FaceOpponent and UpdateLocomotionState remain exact.


Ikumi Character14::Slot08 effects is now **complete native strict Exact**,
1,592 bytes / 434 instructions and 33/33 original-bound relocations.
Its old five rand() calls were replaced with the real x87
opponent-X to integer conversions before storing effect.x.
Accepted source is src/Character14Effects.cpp, proof is
docs/evidence/ikumi-slot08-exact.json; rebuild only
scripts/repo-python scripts/replay-exact-units.py --unit character-14-slot08.
The old partial workbench is retired.

Nagamori Character06::Slot05 CPU is now **complete native strict Exact**,
15,292 original bytes / 3,924 instructions, 300/300 original-bound
relocations and zero differences. The source is
`src/Character06Cpu.cpp` and the certificate
`docs/evidence/nagamori-slot05-exact.json`.
Rebuild only with
`scripts/repo-python scripts/replay-exact-units.py --unit character-06-slot05`.
The old partial workbench and prefix test are retired.

Legacy bitmap-to-object conversion at original `0x004019B0` is now
complete strict Exact (614 bytes, all 37 relocations); source is
`src/LegacyObjectConverter.cpp`, proof
`docs/evidence/legacy-object-converter-exact.json`. The original fixed
file paths and file-size-minus-ten behavior have been preserved. This helper
has no known incoming direct calls; do not infer that it is a runtime path.

Nagamori `MarkEffectCollision` at `0x004AE1D0` is an accepted 231-byte owner.
Its `character-06-effect-proximity` recipe uses the isolated declaration in
`workbench/nagamori-helper/CharacterViews.h`, included by
`src/Character06Collision.cpp`. Keep this header: whole-program integration
with the common class declaration remains a separate task.

## Active unfinished owners

| Owner | Canonical extent | Current candidate / next action |
| --- | --- | --- |
| Nayuki Character10::Slot06 state boss | 0x00451850, 62,693 code bytes + 552/306 local data | selected 32,945 code bytes / 9,056 original instructions, 83 reviewed cases; 842 internal jumps, 109 canonical outbound targets, 793 nonlocal original-bound COFF relocs and 2 local table refs. Incomplete stack 0x278 vs 0x2B4. Next state206 at 0x00459901, mismatch 0x00459904. 35 later existing unreviewed cases plus 19 absent 263–281. 29,748 bytes remain OPEN, NOT full Exact. |
| Shiori `Character08::Slot06` | `0x004136D0`, 63,132 bytes including both tables | `workbench/shiori-state/`: complete candidate emits 63,133 bytes. First register divergence is case 303 at `0x0041FC1E`; instruction-width deltas are +1 in 307/308 and -1 in 315. Recover original register lifetimes. |
| `Scene2::PrepareBattle` | `0x0076CA50`, 4,029 bytes including two address tables and selector | `workbench/prepare-battle/`: complete candidate emits 4,031 bytes / 115 relocations. Investigate first-background allocation at `0x0076D743` and later virtual-load receiver move. Casts, named pointer locals and real background layouts did not fix it. |

Focused diagnostic commands:

```bash
scripts/repo-python workbench/shiori-state/audit_case_codegen.py --rebuild
```

These normalized diagnostics do not grant Exact credit. Other workbench READMEs
contain their selected compilation commands. Preserve each candidate's local
headers until its original codegen is resolved. Nagamori Slot07 and the Video
pixel kernels also remain open; current Video candidates are in `src/`.

## Retention

As of 2026-11-11, cleanup removed **365 stale root-level Wine reg*.tmp
registry snapshots**, totaling 398,450,169 bytes (about 380 MiB), after
checking for active Wine/compiler processes. The authoritative system.reg,
user.reg, userdef.reg, pinned VC7.1 toolchain, Ghidra project, original EFZ.exe,
tracked source/evidence and Git history were kept. Untracked build/ and
.analysis/ caches plus Python bytecode were also cleared; subsequent
verify-target, toolchain --check, selected Nayuki Slot06 native rebuild and
lightweight CI all passed. If the next agent needs an ignored artifact, rerun
the selected script rather than restoring the deleted cache.

Keep necessary inputs, current results and useful knowledge. Historical cleanup
archives, duplicate certificates, integrated drafts and superseded private
outputs have been removed. Recreate needed analysis from the canonical target
and selected recipes. No cleanup archive, deletion manifest or receipt refresh
is required for later housekeeping. Commit coherent increments as `gpt-web: `;
never push unless explicitly instructed.
