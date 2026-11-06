# Current handoff — 2026-11-06

## Task state

The operator resumed exact reconstruction on 2026-11-06 and requested focused
new/affected comparisons without full CI/cold cohorts or redundant tests.
This session completed the preserved PatternReader and Audio owners in two
local checkpoints. The full game remains incomplete; continue from the accepted
src/ baseline and reviewed ledgers. Never infer whole-game completion from
these owner-level successes.

Use Bash and local Ghidra; no REA or subagents. Keep code, comments, documentation
and metadata English. Commit verified progress with prefix `gpt-6.1-sol: `.
The public repository is https://github.com/N0zoM1z0/Eternal-Fighter-Zero;
checkpoints remain local until the operator explicitly requests a push.

## Accepted baseline

| Fact | Accepted result |
| --- | ---: |
| Authored complete exact functions | 85 |
| Authored exact instruction bytes | 35,244 |
| Associated exact local-table bytes | 191 |
| Reviewed boundaries / origins | 98 / 98 |
| Compiler-generated auxiliary helpers | 9 functions / 363 bytes |
| Standard-library auxiliary wrappers | 4 functions / 90 bytes |
| Automatic non-external candidates | 950 |

config/matches.csv and docs/evidence/ are the acceptance authority. Candidate
counts are not an authored-code denominator. No runnable replacement or
whole-game completion percentage is claimed.

The largest owner is Context::UpdateEffect (0x401C20): 14,114 instruction bytes
and 191 local-table bytes, compared as the complete 14,305-byte contribution
through 0x405401. All 301 relocations and 36 compiler-local offset bindings
remain checked. The Audio header update refreshed compiler-local symbol IDs
without changing destinations, extents or offset checks.

## Latest exact progress

Reader checkpoint b811817 accepts twenty complete PatternReader members for
1,370 bytes. Context.cpp now shares the int-returning Read declaration and all
nine Context recipes depend on PatternReader.h. Two cold source/profile artifacts
covered 20 new bodies and nine affected Context bodies. Proofs are
reader-exact.json and context-exact.json; private replay is
.analysis/exact/reader-and-affected.json.

The subsequent Audio checkpoint accepts twelve members for 3,159 bytes:
construction/destruction, initialization/shutdown, buffer creation/fill/release,
slot selection, PCM WAV loading, loop-marker parsing and loop maintenance.
The two AudioGlobal lifetime wrappers add 43 auxiliary bytes only. All 91 new
relocations were independently reviewed against original operands/imports/data.
Sixteen cold source/profile artifacts covered these 14 bodies plus the 62
existing Engine.h-dependent units. Every complete comparison is strict exact;
reader and Config were unaffected and were not replayed. Public proofs include
audio-exact.json/audio-global-exact.json and refreshed affected-owner proofs.
Private final replay is .analysis/exact/audio-and-affected.json.

The five old Audio mismatches are resolved. Natural local scopes fixed
FillBuffer/CreateBuffer/LoadWave stack allocation; explicit RIFF field zeroing
recovered LoadWave's original instructions. ReadLoopMarkers uses repeated shifts
by eight and the original early return. MaintainLoop uses four early returns.
Complete comparisons were retained after each trial. See
[the knowledge base](KNOWLEDGE_BASE.md#audio-resource-and-loop-owner).

Important retained limits:

- Reader fields at 0/4 are known; its provisional 12-byte caller view does not
  establish a third field or full original size/alignment. Reset is not a proven
  base constructor. ReadInt reads four raw bytes; no custom decoder is present.
- Audio's minimum view is 0x718: loopStart/loopEnd at 0/4, window/DirectSound at
  8/0xC, samples/sizes/buffers at 0x10/0x268/0x4C0, 150 entries each. Constructor
  leaves window/DirectSound/sizes untouched. BSS/data placement closure is open.
- Startup now calls MaintainLoop(unsigned short), replacing the provisional
  SetMode(short) name/type at the same target 0x40E4D0. Original unchecked paths,
  leaks, buffer failures, marker bounds and byte conversion are preserved.
- Both FillBuffer memcpy calls bind to 0x778600. The old scratch guess 0x778410
  was wrong. No masked relocations, padded source or partial extents are accepted.

## Preserved archive and tool state

[The reader/audio workbench](../workbench/reader-audio/README.md) preserves the
original four draft files, integration patch and snapshot manifest unchanged.
All patch hunks are now integrated. Do not copy archived drafts over accepted
src/ or rerun historical write-*-first.py generators. Corrected trials, original
raw disassembly, Ghidra output and comparisons remain in .analysis/; none of
this generated/private evidence belongs in Git.

Canonical ignored/read-only target: resources/EFZ.exe, 3,743,744 bytes, SHA-256
3a1616d6c76d2eea08a95bb198d853e96cb6b9b3266e277ca1d167426dd66481.
Release/modification provenance is unresolved. Do not substitute EFZ.OLD,
netplay binaries or an archive/version label for this identity.

Use scripts/repo-python (CPython 3.13.5, standard-library control plane).
VC7.1 RTM 13.10.3077 / linker 7.10.3077 are pinned. Native jobs are serial,
EFZ-owned win32 Wine, one CPU, nice 10, bounded and logged. Ghidra 12.1.3 queries
are serialized, read-only/noanalysis and target-attested. Preserve .tools/ links,
Wine state, ghidra-project/, build receipts and analysis evidence. See TOOLS.md
for setup/recovery. --execute smoke is needed for setup/tool changes or native
failures, not routine unit replay.

The original RAR remains in ../game_exe/. Redundant extraction was removed only
after archive integrity and extracted file sizes/CRCs were verified. Recover
assets on demand using RE_ARTIFACTS.md; the original game has not been launched.

## Focused checks and next work

This session used target/tool identity verification, selected exact native
comparisons, target-bound ledger validation, generated progress checks and
git diff --check. Full CI and an unrequested cold cohort were omitted per the
operator's latest instruction. No infrastructure or oracle implementation changed.

For each future source change, replay only new/changed/header-dependent units
with explicit selection. Identical source/profile/dependency recipes may share
one cold artifact with explicit per-unit receipts. Preserve complete strict
comparisons after scope/name changes; update ledgers, proofs, progress, durable
knowledge and this handoff before a local checkpoint.

The reader/audio backlog is complete at function-codegen level. Next coherent
candidates include the timing thread 0x401850, Input lifetime, Draw implementations
0x409A90/0x40A0B0 and the 865-byte pixel candidate 0x40A440. Recheck complete target
boundaries and callers before accepting inferred names/types. Larger scene
owners remain open; do not optimize solely for small-function counts.

Production TU partitioning, linked data/resources/imports, callee closure, the
runnable Windows product, original/reconstructed runtime comparison and
portability are independently tracked later phases.
