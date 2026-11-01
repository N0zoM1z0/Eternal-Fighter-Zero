# EFZ reconstruction rules

## Session recovery

Work in this repository. Inspect `git status --short --branch` and the diff,
then read `docs/RE_HANDOFF.md` and the relevant source/ledger rows. Preserve
unrelated work. Never push without an explicit user instruction. The operator
authorized creating and publishing the initial public
`N0zoM1z0/Eternal-Fighter-Zero` repository on 2026-11-01. Keep code, comments,
documentation and repository metadata in English; conversation may be Chinese.

Use `scripts/repo-python` for Python. Run `scripts/verify-target.py` before
target-dependent work. Use Bash and local `scripts/ghidra.py` directly; the
operator explicitly requested no REA. Do not introduce Factory provider
protocols or receipts as prerequisites.

The only canonical target is ignored, read-only `resources/EFZ.exe`, SHA-256
`3a1616d6c76d2eea08a95bb198d853e96cb6b9b3266e277ca1d167426dd66481`.
Do not substitute `EFZ.OLD`, netplay binaries or another release. New targets
require an explicit scope change, a separate identity and separate evidence.

## Active reconstruction direction

Recover both substantial owners and useful small functions; do not optimize
for leaf count. Recheck prior documentation/hypotheses against target evidence.
The operator says this is the only working session: recover and continue dirty
work rather than avoiding it. Commit substantive verified progress using the
English prefix `gpt-6.1-sol: `. Replay only changed/involved units, never an
unrequested full cold cohort. Continue the full reconstruction objective across
checkpoints; a successful unit does not complete the game reconstruction.

## Exact work

Use the pinned VC7.1 RTM 13.10.3077 toolchain and explicit per-unit profiles.
Run `scripts/verify-toolchain.py --check` for tool identity; `--execute` is
needed for setup, toolchain changes or compiler/Wine failures, not every unit.
Native builds are serial, one CPU, nice 10, bounded, and retain exit logs.
Never reuse another game's Wine prefix for EFZ builds.

Review complete target boundaries before acceptance. Ghidra candidates, names,
types, calling conventions and inferred origins are provisional. Keep candidate
inventory, boundary review, origin, source mapping and exact codegen separate.
Inventory export is private and cannot overwrite reviewed ledgers.

Write natural C/C++. Provisional offset/numeric names are acceptable. Do not
copy original bytes into source, patch target code, use naked/assembly byte
wrappers, add inert padding, fake ABI declarations, or conceal incorrect
relocation fields. Normal source scope and local names can affect VC7.1 /Od
stack allocation; retain a complete cold comparison after any such change.

Only complete, target-bound, zero-difference strict comparisons may enter
`config/matches.csv`. Every relocation must have an explicit reviewed symbol,
destination and evidence. No masked address acceptance, size-only matches or
prefix comparisons. `compare_size` overrides are forbidden. Unsupported LTCG,
EH and linked-data cases remain open rather than receiving approximate credit.

Build and compare the first complete source early. Prefer coherent owners over
large speculative flag/name sweeps. Park byte-neutral controls unless new
evidence gives a falsifiable prediction. Replay only new and affected exact
units with explicit `--unit` selectors.

## Evidence and checkpoints

Record durable target facts in `docs/KNOWLEDGE_BASE.md` and current next steps
in `docs/RE_HANDOFF.md`. TH10 is an infrastructure reference; TH105 engine
similarity suggests hypotheses but proves no EFZ bytes, flags, layout or ABI.

Keep original executables/data, downloaded toolchains, databases, generated
decompiler text and credentials out of Git. Scratch belongs in `.analysis/`,
builds in `build/`, tool links/Wine state in `.tools/`, private Ghidra state in
`ghidra-project/`.

Source changes finish with the affected native exact comparison. Infrastructure
changes need the relevant focused oracle checks. Run `scripts/ci.py` and
`git diff --check` before a checkpoint; regenerate progress after ledger changes.
Do not require broad runtime/failure-injection/sanitizer matrices for ordinary
exact units. Product closure, original/reconstructed runtime comparison and
portability are later, independently tracked phases.
