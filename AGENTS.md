# EFZ reconstruction rules

## Highest priority: lightweight exact reconstruction and useful knowledge

These are the user's current workflow requirements. They override older
instructions that mandate broad CI, repeated preflights, document/source-pin
refreshes, per-checkpoint audits or extra workflow machinery. Preserve the
actual exactness, target identity, natural-source and state-isolation rules.

- Prioritize exact reconstruction and reusable knowledge. Use the shortest
  useful loop: inspect relevant state, analyze/edit, compile and compare the
  affected scope, retain useful learning, and create a coherent checkpoint.
- Use existing repository scripts and composable Bash. Add only the smallest
  change needed for an observed problem. Do not introduce a framework, schema,
  registry, state machine, generalized validator, test family or reporting
  process merely to make a local reconstruction task look more engineered.
- Documentation, knowledge and handoff edits require no compiler, analyzer,
  full CI, cold replay or receipt refresh. Inspect the diff. Check syntax only
  for machine-readable inputs actually changed.
- Source changes need the complete affected exact comparison, including its
  owned extents and relocations. Recheck known consumers of changed shared
  inputs. Tool changes need relevant positive/negative cases and a bounded
  real smoke. Run a broad suite only for an explicit request or a demonstrated
  impact that cannot be narrowed; state that reason first.
- Do not add tests or live freshness gates for prose hashes, prompt wording,
  progress totals, handoff source-SHA tables or ordinary source spelling.
  Bind exact evidence to executable inputs and relevant verification settings.
  Keep Git metadata as provenance. A document genuinely consumed by a build
  remains a build input. Never edit historical receipts to manufacture a pass.
- Plain Markdown is sufficient for knowledge: record the finding, applicable
  target/compiler/scope, evidence links, useful failed attempts and open
  questions. No mandatory JSON conversion, promotion workflow or test per note.
  Search relevant sections; do not read an entire large knowledge journal.
- Write documentation and knowledge in natural, fluent English. Lead with the
  concrete finding and connect the evidence and next action clearly. Remove
  filler, circular restatements, repeated conclusions and unnecessary jargon.
  Do not add defensive-claim boilerplate. State a real uncertainty or scope
  limit once when it changes a decision; do not repeat disclaimers about what
  a note does not prove, certify or authorize. Prefer a small useful note over
  an exhaustive report that is difficult to read.
- Keep handoff focused on current work, evidence references, blockers and the
  next useful action. Generate progress from canonical ledgers; avoid manual
  duplicate counts, recurring full reports and unrelated documentation chores.
- Preserve dirty/untracked work, targets, useful evidence, game-specific Wine
  prefixes and analyzer projects. Exactness still requires a complete strict
  comparison; knowledge and successful commands alone confer no exact credit.


## Factory access

When working through the shared Reconstruction Factory, select repository
`efz` and analysis provider `efz-ghidra`. The live Bash tool exposes this
worktree, its ignored `resources/EFZ.exe`, repository Python, VC7.1 tools and
EFZ-only Wine prefix. Use the existing repository build and oracle scripts for
explicit selected-unit verification; Factory receipts are not prerequisites.
Other registered source trees are read-only at `/references/<repository_id>`.
Cross-game code is hypothesis material, not EFZ evidence. Native analysis
previews are bounded; recover complete output from the returned artifact path
through live Bash. The local `scripts/ghidra.py` workflow remains available.

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

## Reconstruction policy

Recover both substantial owners and useful small functions; do not optimize
for leaf count. Recheck prior documentation/hypotheses against target evidence.
Preserve unfinished work and inspect its handoff before integrating it. Commit
substantive verified progress using the English prefix `gpt-6.1-sol: `. Replay
only changed/involved units, never an unrequested full cold cohort. A successful
unit does not complete the game reconstruction. The operator cleared the active
goal and requested cleanup and handoff on 2026-11-07. No autonomous reconstruction
task is active. Do not infer one from historical notes or suggested follow-ups.
Do not spawn
subagents unless the operator explicitly requests delegation.

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
changes need the relevant focused oracle checks. Run the applicable
`scripts/ci.py --only ...` checks and `git diff --check` before a checkpoint;
regenerate progress after ledger changes. The operator requested no routine
full CI or full cold cohort; select only new and affected native units.
Do not require broad runtime/failure-injection/sanitizer matrices for ordinary
exact units. Product closure, original/reconstructed runtime comparison and
portability are later, independently tracked phases.

`src/` is the accepted baseline. Reader/audio integration is complete;
`workbench/reader-audio/` preserves historical drafts and the already-integrated
patch. Those scratch comparisons confer no independent progress credit. Read
its README before consulting the archive; do not reapply it over `src/`.
Do not delete retained
analysis evidence or the toolchain/Wine/Ghidra state as routine cache cleanup.
The verified lossless cleanup archives and restore instructions are recorded in
`docs/RE_ARTIFACTS.md`; restore an archived historical artifact before using it.

## Shared Factory runtime

Follow [the shared tools instructions](docs/SHARED_TOOLS.md). Ghidra/JDK and
Wine executables are shared through Factory; repository scripts also work
without MCP. Use `scripts/shared_runtime.py` and the existing compiler/analysis
frontends. Keep this game's prefix, analyzer project, Java home/cache, target
and compiler profile isolated. Do not install duplicate tools or inherit
another game's `WINEPREFIX`. This shared-runtime procedure supersedes older
per-repository installation instructions; pinned versions/hashes still apply.
