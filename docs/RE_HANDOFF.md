# Current handoff — 2026-11-01

## Task state

The operator cleared the prior autonomous reconstruction goal and requested
cleanup and handoff to another agent. This checkpoint organizes existing work;
it does not authorize an indefinite reconstruction loop. The full game remains
incomplete. Resume reconstruction when the operator assigns it.

Use Bash and local Ghidra; no REA. Code, comments, documentation and metadata
must be English. Conversation with the operator may be Chinese. Do not spawn
subagents without an explicit delegation request. Use commit prefix
`gpt-6.1-sol: `. The public repository is
`https://github.com/N0zoM1z0/Eternal-Fighter-Zero`; later checkpoints remain local
until the operator requests a push. The local directory retains its historical
`Eternal-Fight-Zero` spelling; the game and remote name are Eternal Fighter Zero.

## Accepted baseline

The accepted reconstruction is commit `4540d24` plus this documentation/workbench
cleanup. Its `src/`, recipes, ledgers and public certificates are unchanged.

| Fact | Accepted result |
| --- | ---: |
| Authored complete exact functions | 53 |
| Authored exact instruction bytes | 30,715 |
| Associated exact local-table bytes | 191 |
| Reviewed boundaries / origins | 64 / 64 |
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
accepted files, and a source-hash manifest. The patch has not been applied.
The original dirty integration was preserved before restoring accepted sources.

Twenty PatternReader bodies have equal complete lengths and zero-byte-difference
private diagnostics. Seven of twelve Audio bodies have the same diagnostic
result; five still differ. These diagnostics are not formal cold oracle
certificates. No new reviewed rows, recipes, source mappings or matches were
published. AudioGlobal's generated helpers remain unaccepted too.

Corrections to carry into integration:

- ReadInt is a raw four-byte read, not a custom decoder. Read returns a byte
  count; the accepted caller's old `void` declaration is provisional and must be
  replaced together with its relocation symbol and affected certificates.
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

## Resume checks

```bash
git status --short --branch
scripts/repo-python scripts/verify-target.py
scripts/repo-python scripts/verify-toolchain.py --check
scripts/repo-python scripts/report-reconstruction-status.py
scripts/repo-python scripts/validate-tracking.py --require-target
scripts/repo-python scripts/ci.py
```

Cleanup changed no accepted source, profile, recipe, ledger or certificate;
therefore it requires no native cold replay. Future integration does: select
only new/changed/header-dependent units, group identical source/profile/dependency
recipes where receipts remain explicit, and retain complete strict comparisons.
Never launch an unrequested full cold cohort. `--execute` toolchain smoke is for
setup/tool changes or actual native failures, not every replay.

For future reconstruction, finish or explicitly defer the preserved reader/audio
work before starting another owner. Draw implementations `0x409A90`/`0x40A0B0`,
the 865-byte pixel candidate `0x40A440`, Input lifetime, timing thread `0x401850`
and larger scene owners remain open. Production TU partitioning, linked data,
resources/imports, callee closure, the runnable Windows product, original/native
runtime comparison and portability are separate unfinished phases. The original
game has not been launched.
