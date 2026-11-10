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

Makoto Slot06, Nagamori Slot04/Slot02, Ikumi Slot02 and Scene3 pushboxes are
complete Exact owners. The match ledger identifies their current certificates
and source recipes. Do not reopen them from obsolete partial-draft measurements.
Reader/audio integration is complete in `src/`.

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
| Nagamori `Character06::Slot05` CPU | `[0x004B2AC0,0x004B667C)`, 15,292 bytes | `workbench/nagamori-cpu/`: prefix covers 13,230 original bytes / 3,366 instructions; 3,364/3,365 comparable forms, 470 internal jumps, 164 float bindings. Incomplete stack 0xD4 vs original 0xE8. Continue self-airborne at `0x004B5E6E` and generic fallback at `0x004B6294`; 2,062 target bytes remain, no full-owner Exact. |
| Shiori `Character08::Slot06` | `0x004136D0`, 63,132 bytes including both tables | `workbench/shiori-state/`: complete candidate emits 63,133 bytes. First register divergence is case 303 at `0x0041FC1E`; instruction-width deltas are +1 in 307/308 and -1 in 315. Recover original register lifetimes. |
| `Scene2::PrepareBattle` | `0x0076CA50`, 4,029 bytes including two address tables and selector | `workbench/prepare-battle/`: complete candidate emits 4,031 bytes / 115 relocations. Investigate first-background allocation at `0x0076D743` and later virtual-load receiver move. Casts, named pointer locals and real background layouts did not fix it. |
| Ikumi `Character14::Slot08` | `0x006AB060`, 1,592 bytes; verified vtable slot 8 | `workbench/ikumi-effects/`: partial output is 1,537 bytes / 33 relocations. Five spawn branches need the original opponent-X x87 load before `rand()`. Volatile/comma/multiplication variants did not reproduce it. |

Focused diagnostic commands:

```bash
scripts/repo-python workbench/nagamori-cpu/check_prefix.py
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
