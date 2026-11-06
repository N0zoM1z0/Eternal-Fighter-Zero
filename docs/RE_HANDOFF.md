# Current handoff — 2026-11-06

## Task state

The operator resumed exact reconstruction on 2026-11-06 and requested focused
new/affected comparisons without a full CI/cold cohort or redundant tests.
The current local checkpoint integrates the complete PatternReader owner.
The full game remains incomplete; Audio is the next preserved owner to finish.

Use Bash and local Ghidra; no REA. Code, comments, documentation and metadata
must be English. Conversation with the operator may be Chinese. Do not spawn
subagents without an explicit delegation request. Use commit prefix
`gpt-6.1-sol: `. The public repository is
`https://github.com/N0zoM1z0/Eternal-Fighter-Zero`; later checkpoints remain local
until the operator requests a push. The local directory retains its historical
`Eternal-Fight-Zero` spelling; the game and remote name are Eternal Fighter Zero.

## Accepted baseline

The accepted baseline includes the frame checkpoint and the 2026-11-06 reader
integration. Exact acceptance is recorded in the independent ledgers and public
certificates; no whole-product/runtime completion is claimed.

| Fact | Accepted result |
| --- | ---: |
| Authored complete exact functions | 73 |
| Authored exact instruction bytes | 32,085 |
| Associated exact local-table bytes | 191 |
| Reviewed boundaries / origins | 84 / 84 |
| Compiler-generated auxiliary helpers | 7 functions / 320 bytes |
| Standard-library auxiliary wrappers | 4 functions / 90 bytes |
| Automatic non-external candidates | 950 |

`config/matches.csv` and `docs/evidence/` are the acceptance authority. Candidate
counts are not an authored-code denominator. Drafts below add no accepted credit.
No runnable replacement or whole-game completion percentage is claimed.

The largest owner is Context::UpdateEffect (`0x401C20`): 14,114 instruction bytes
and 191 local-table bytes, compared as the complete 14,305-byte contribution
through `0x405401`. All 301 relocations and 36 compiled local-offset bindings
are checked. Attribution never shortens comparison.

The last accepted frame checkpoint added 19 functions / 4,537 instruction bytes
across EffectFrame, ContextState, WordFile, PaletteFade and AudioVolume. Its
selected replay used 14 cold source/profile artifacts for 62 affected functions;
configuration units were untouched. See `docs/evidence/frame-exact.json` and
`docs/KNOWLEDGE_BASE.md#effect-frame-and-word-files` for the durable findings.
The final private report is `.analysis/exact/frame-and-affected.json`.

## Preserved unfinished work

Read [the reader/audio workbench](../workbench/reader-audio/README.md) first.
It contains four draft source/header files, an integration patch for three
accepted files, and a source-hash manifest. Only its Context.cpp hunk has been
applied.
The original dirty integration was preserved before restoring accepted sources.

The twenty PatternReader bodies are now accepted in src/PatternReader.cpp/.h,
with complete target-bound zero-difference proofs for 1,370 bytes. All 41
relocations were checked against original operands and PE imports/CRT bodies.
Context.cpp now shares the corrected int-returning Read declaration, and every
Context recipe includes PatternReader.h. Two cold source/profile artifacts
covered 20 new reader bodies and nine affected Context bodies (three generated
helpers remain auxiliary). Public proofs are reader-exact.json and the refreshed
context-exact.json; private replay is .analysis/exact/reader-and-affected.json.

Audio was deliberately deferred so this reader checkpoint does not change
Engine.h or replay its other dependents. Seven of twelve Audio bodies had zero
differences in old scratch diagnostics; five still differ. AudioGlobal helpers
remain unaccepted. Preserve these drafts and finish them before broad new-owner
exploration. The original patch's Context hunk is already applied; use the
Audio-only restore commands in the workbench README.

Corrections to carry into integration:

- ReadInt is a raw four-byte read, not a custom decoder. Read returns a byte
  count; the accepted caller's old provisional `void` declaration was
  corrected together with its relocation symbol and all affected certificates.
- The provisional reader view remains 12 bytes for the accepted loader's stack
  layout. Only handle/buffer fields at 0/4 are currently identified. Do not claim
  that an extra four-byte field, inheritance or a unique class size is proven.
  `0x405970` resets state and returns 1; it is not a proven base constructor.
- `0x40E4D0` maintains loop playback. The accepted `SetMode(short)` name/type is
  provisional and misleading; the draft uses MaintainLoop(unsigned short).
- Audio's draft offsets are loopStart 0, loopEnd 4, window 8, DirectSound 0xC,
  samples 0x10, sizes 0x268 and buffers 0x4C0, yielding a minimum view of 0x718.
  Original initialization and failure behavior must not be silently hardened.
- A scratch memcpy binding guessed as `0x778410` was incorrect. Both original
  FillBuffer calls target `0x778600`; the retained diagnostic script is corrected.

Do not run the old `write-*-first.py` generators over current sources. They are
historical scratch. Keep their raw disassembly, comparisons and build receipts
for the next agent. The workbench lists the remaining differences and integration
checks; do not repeat completed broad exploration or count projected totals.

## Input, tools and retained state

Canonical ignored/read-only target: `resources/EFZ.exe`, 3,743,744 bytes, SHA-256
`3a1616d6c76d2eea08a95bb198d853e96cb6b9b3266e277ca1d167426dd66481`.
Release/modification provenance is unresolved. Do not substitute EFZ.OLD,
netplay binaries or an archive/version label for this identity.

Use `scripts/repo-python` (CPython 3.13.5, standard-library control plane).
Host Python pefile/capstone support private scratch diagnostics only. VC7.1 RTM
13.10.3077 / linker 7.10.3077 are pinned in `config/tools.lock.toml`. Native jobs
are serial, isolated win32 Wine, one CPU, nice 10, bounded and logged. Ghidra
12.1.3 queries are serialized, read-only/noanalysis and target-attested.
Tool links currently point to sibling reconstruction tool installations; preserve
them and the EFZ-owned Wine prefix. See `docs/TOOLS.md` for bootstrap/recovery.

The original RAR remains in `../game_exe/`. Its redundant extraction was removed
only after archive integrity and all extracted file sizes/CRCs were verified;
no extra files were present. Recover assets on demand using the commands in
`docs/RE_ARTIFACTS.md`. The canonical executable, Ghidra database, Wine state,
private analysis evidence, build receipts and latest draft objects are retained.
Browser preview caches and superseded exploratory build objects were removed.

## Focused verification and next work

The reader checkpoint uses only selected native comparisons, target-bound ledger
validation, generated progress checks and git diff --check. Full CI and an
unrequested cold cohort were omitted per the operator's latest instruction.
No toolchain setup/--execute smoke was needed. For future source changes, replay
only new/changed/header-dependent units with explicit selectors and retain
complete strict comparisons. Identical source/profile/dependency recipes may
share one cold artifact with explicit per-unit receipts.

1. Review the pending Audio workbench README, retained full target disassembly
   and existing mismatches; do not rerun old source generators.
2. Resolve FillBuffer/CreateBuffer local allocation, LoadWave scope/stack layout,
   ReadLoopMarkers byte assembly and MaintainLoop branch ordering. Build a
   complete source early and retain complete comparisons after scope changes.
3. Integrate Audio only after complete comparisons/boundary/relocation review.
   Engine.h changes affect 62 accepted units; reader and Config are independent.
   Refresh dispatcher local-symbol identities without changing destinations,
   complete extent or local-offset checks. Classify AudioGlobal as generated.
4. Update ledgers, proofs, progress, durable knowledge and this handoff; commit
   verified progress locally with the required prefix. Never push implicitly.

Draw implementations 0x409A90/0x40A0B0, the 865-byte pixel candidate 0x40A440,
Input lifetime, timing thread 0x401850 and larger scene owners remain open.
Production TU partitioning, linked data, resources/imports, callee closure,
the runnable Windows product, original/native runtime comparison and portability
are separate unfinished phases. The original game has not been launched.
