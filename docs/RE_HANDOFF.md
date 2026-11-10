# EFZ reconstruction handoff

Follow [AGENTS.md](../AGENTS.md). Current accepted source is `src/`; counts
come from [PROGRESS.md](PROGRESS.md) and the canonical ledgers. Search the
relevant sections of [KNOWLEDGE_BASE.md](KNOWLEDGE_BASE.md) for target facts
and failed hypotheses. Inspect current Git changes before starting.

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

Keep necessary inputs, current results and useful knowledge. Historical cleanup
archives, duplicate certificates, integrated drafts and superseded private
outputs have been removed. Recreate needed analysis from the canonical target
and selected recipes. No cleanup archive, deletion manifest or receipt refresh
is required for later housekeeping. Commit coherent increments as `gpt-web: `;
never push unless explicitly instructed.
