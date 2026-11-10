# EFZ reconstruction rules

## Working loop

Work in this repository. Inspect `git status --short --branch` and the diff,
then read `docs/RE_HANDOFF.md` and the relevant source/ledger rows. The operator
confirms no concurrent writer: inspect and reconcile dirty/untracked work.
Do not discard it blindly. Do not spawn agents unless separately requested.
Keep code, comments, docs and commit messages in English; chat may be Chinese.

Prioritize exact reconstruction of substantial owners and useful small functions;
do not optimize for leaf count. Check old assumptions against target bytes.
Use the shortest useful loop: inspect, analyze/edit, compile and compare the
involved scope, record useful findings, commit a coherent checkpoint with
`gpt-web: `. Make several commits when progress warrants them. Never push
without an explicit instruction.

Use existing scripts and composable Bash. Add only what an observed problem
needs. Avoid new frameworks, registries, reporting processes and routine audits.
Use `scripts/repo-python` for Python and local `scripts/ghidra.py` for analysis.
The operator explicitly requested no REA.

## Inputs and isolation

The only canonical target is ignored, read-only `resources/EFZ.exe`, SHA-256
`3a1616d6c76d2eea08a95bb198d853e96cb6b9b3266e277ca1d167426dd66481`.
Run `scripts/verify-target.py` before target-dependent work. Do not substitute
`EFZ.OLD`, a netplay binary or another release. New targets need an explicit
scope change and separate identity/evidence.

Use pinned VC7.1 RTM 13.10.3077 and explicit per-unit profiles. Run
`scripts/verify-toolchain.py --check` for native work; `--execute` is for setup,
toolchain changes or compiler/Wine failures. Native builds are serial, one CPU,
nice 10, bounded, with exit logs. Never borrow another game's Wine prefix.

Follow [docs/SHARED_TOOLS.md](docs/SHARED_TOOLS.md). Ghidra/JDK and Wine come
from the shared runtime; use `scripts/shared_runtime.py` and the existing
frontends. Keep EFZ's prefix, analyzer project, Java state, target and compiler
profile isolated. Do not install duplicate tools or inherit ambient WINEPREFIX.

Through Reconstruction Factory, select repository `efz` and provider
`efz-ghidra`. Live Bash exposes this worktree, Python, VC7.1 and the EFZ prefix.
Factory protocols/receipts are not prerequisites for local scripts. Other
registered trees at `/references/<repository_id>` are read-only. TH10 is an
infrastructure reference; TH105 similarity supplies hypotheses, not EFZ proof.
Recover bounded analysis output from its artifact path when needed.

## Exact acceptance

Review complete target boundaries before acceptance. Ghidra names, types,
calling conventions, inferred origins and candidate extents are provisional.
Keep inventory, boundary review, origin, source mapping and exact codegen
separate. Inventory export is private and cannot overwrite reviewed ledgers.

Write natural C/C++. Provisional numeric/offset names are acceptable. Do not
copy target bytes into source, patch target code, use assembly/naked byte
wrappers, add inert padding, fake ABI declarations or conceal wrong relocations.
Unsupported LTCG, EH and linked-data cases remain open.

Build a complete source early. Test falsifiable source/codegen hypotheses;
park byte-neutral controls until new evidence predicts a different result.
Only complete, target-bound, zero-difference strict comparisons may enter
`config/matches.csv`. Include all owned tables and relocations, each with an
explicit reviewed symbol, destination and evidence. No masking, prefix/size-only
acceptance or `compare_size` overrides.

Source edits require a complete native comparison of the affected functions
and actual consumers, including shared-header and local-scope/name changes
that can affect VC7.1 /Od stack allocation. Select explicit `--unit` values.
Do not run an unrequested full cold cohort. `src/` is the current baseline;
`workbench/` contains active unfinished candidates and the isolated Nagamori
helper header required by one accepted unit. Do not copy provisional workbench
headers over accepted shared headers.

## Checks and knowledge

`scripts/ci.py` runs fast target-free basic checks: syntax, tool declarations,
ledger structure, generated progress and whitespace. Use `--only NAME` when
appropriate. Oracle tests are opt-in for oracle changes. Historical certificate
freshness is a separate optional audit:
`validate-tracking.py --check-proofs --unit NAME`. Daily CI passing is not a
new exact comparison. Never edit old hashes to manufacture a pass.

Tool changes need relevant positive/negative cases and a bounded real smoke.
Source changes finish with affected native exact comparisons. Broaden checks
only for an explicit request or an observed impact that cannot be narrowed;
state that reason first. Do not add routine runtime/failure-injection/sanitizer
matrices. Whole-product closure, runtime comparison and portability are later
phases. A successful unit does not complete the game.

Documentation-only changes need diff review and `git diff --check`, without
compiler/analyzer replay, proof refresh or full CI. Check syntax for changed
machine inputs. Regenerate progress after ledger changes; do not duplicate
counts manually. Plain Markdown is sufficient: keep verified findings, current
blockers, useful failed approaches and the next action concise in
`docs/KNOWLEDGE_BASE.md` and `docs/RE_HANDOFF.md`. No prose-hash gates, source-pin
tables, promotion process or test per note.

## Retention and cleanup

Keep necessary inputs (original program, toolchain, Ghidra project and isolated
runtime state), current source/ledgers/build-and-compare scripts, and useful
knowledge. Keep an unfinished candidate's unusual compilation context only
when it is needed to reproduce the problem.

Delete obsolete archives, duplicate evidence, completed drafts, old experiment
outputs and cleanup reports when they no longer help reconstruction. Remove
their references too. A document mentioning a file is not a retention reason.
No lossless re-archive, per-file deletion manifest or new cleanup audit is
required. Exactness comes from reproducible complete comparisons.

Keep original executables/data, tools, databases, generated decompiler text and
credentials out of Git. Use `.analysis/` for disposable analysis output,
`build/` for regenerable products, `.tools/` for tool links/Wine state and
`ghidra-project/` for the private analyzer project. Never delete shared tool
installations or necessary inputs as cache cleanup.
