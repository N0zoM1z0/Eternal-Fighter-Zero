# Current handoff — 2026-11-06

## Task state

The operator resumed exact reconstruction on 2026-11-06 and requested focused
new/affected comparisons without full CI/cold cohorts or redundant tests.
The current checkpoints complete the preserved PatternReader and Audio owners,
then DirectInput, Audio playback controls and Context input/audio transitions.
The full game remains incomplete; continue from the accepted src/ baseline and reviewed ledgers. Never infer whole-game completion from
these owner-level successes.

Use Bash and local Ghidra; no REA or subagents. Keep code, comments, documentation
and metadata English. Commit verified progress with prefix `gpt-6.1-sol: `.
The public repository is https://github.com/N0zoM1z0/Eternal-Fighter-Zero;
checkpoints remain local until the operator explicitly requests a push.

## Accepted baseline

| Fact | Accepted result |
| --- | ---: |
| Authored complete exact functions | 102 |
| Authored exact instruction bytes | 41,296 |
| Associated exact local-table bytes | 191 |
| Reviewed boundaries / origins | 117 / 117 |
| Compiler-generated auxiliary helpers | 11 functions / 406 bytes |
| Standard-library auxiliary wrappers | 4 functions / 90 bytes |
| Automatic non-external candidates | 950 |

config/matches.csv and docs/evidence/ are the acceptance authority. Candidate
counts are not an authored-code denominator. No runnable replacement or
whole-game completion percentage is claimed.

The largest owner is Context::UpdateEffect (0x401C20): 14,114 instruction bytes
and 191 local-table bytes, compared as the complete 14,305-byte contribution
through 0x405401. All 301 relocations and 36 compiler-local offset bindings
remain checked. The Context header update refreshed compiler-local symbol IDs
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

The DirectInput checkpoint f5a0259 adds nine DirectInput functions (4,552 bytes), two Audio
playback members (268 bytes), and two generated Input global wrappers (43
auxiliary bytes). Input.h now owns the provisional DirectInput 7 layout and
Engine.h includes it; all 76 existing Engine.h recipes track that transitive
dependency. The Initialize return type and startup relocation symbol were
corrected to int at the same destination 0x40C6F0. Nineteen cold source/profile
artifacts cover 13 new bodies and 76 affected existing units: all 89 complete
comparisons are strict exact. Config and reader were not involved. Private final
replay is .analysis/exact/input-and-affected.json; new public proofs are
input-exact.json, input-global-exact.json and audio-playback-exact.json. Existing
affected-owner proofs were refreshed. All fifteen authored Audio members in the
contiguous original region are now exact (3,508 bytes).

The latest checkpoint adds six Context input/audio members (1,232 bytes):
PollInput, Initialize, PlayEffectSound, LoadMusic, ReleaseMusic and FadeMusic.
Context's former unknown 0xC..0x37 storage now exposes direction/pulse/held arrays
without changing size. Startup's Initialize is the 65-file sound-effect loader;
PollInput translates two packed Input states; music switching retains all
original paths, sentinel checks and looping exceptions. The volume ramp remains
in the already accepted UpdateFrameControls. All 31 new relocations were reviewed.
Eighteen cold source/profile artifacts cover six new and 78 Engine.h-dependent
existing units: all 84 complete comparisons are strict exact. Standalone Input,
reader and Config sources were untouched. Public proof is context-io-exact.json;
private final replay is .analysis/exact/context-io-and-affected.json. The complete
dispatcher and its 36 local-offset bindings remain exact after symbol-ID refresh.

Important retained limits:

- Context direction/pulse arrays occupy 0xC..0x17 and four two-int held arrays
  occupy 0x18..0x37. Initialize loads wave\\se\\00.wav..64.wav and sets volume -500
  even on a failed load. LoadMusic calls marker parsing even when loading fails,
  and disables looping for IDs 2,3,4,9. audioMode is a provisional name for the
  current music buffer slot. No new bounds/failure checks were added.
- Input's minimum view is 0x1F4, not a proven 0x1F8 class from the global gap.
  It owns keyboard state, two DIJOYSTATE records, sixteen bindings and four
  DirectInput interfaces. Only successful enumeration increments the global
  byte count; partial failures remain unreleased. Initialize deliberately checks
  a stale HRESULT after keyboard creation. Defaults reads the first key.ini
  binding record; Configure uses unchecked profile * 39 indexing. All original
  transfer checks, axis/button evaluation order and cleanup behavior are retained.
- StopSound/StartSound preserve the original buffer-before-sentinel check and
  boolean looping argument. Their title at 0x7879D4 includes text following DS.
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
The first private ContextIO compile missed the transitive Input.h, then timed
out after its C1083 error; its log and timeout summary are retained. Copy required
headers when using a private Engine.h. The required post-failure --execute
compiler/linker/resource/execution smoke passed before native work resumed.

For each future source change, replay only new/changed/header-dependent units
with explicit selection. Identical source/profile/dependency recipes may share
one cold artifact with explicit per-unit receipts. Preserve complete strict
comparisons after scope/name changes; update ledgers, proofs, progress, durable
knowledge and this handoff before a local checkpoint.

The reader/audio/Input backlog and Context input/audio transitions are complete
at function-codegen level. Next inspect a coherent scene owner: Scene0 constructor
0x775D60 (460 bytes), its adjacent lifetime body, and Step 0x775FB0 (1,239 bytes).
Target-attested local decompiles completed in this session and are retained
under .analysis/ghidra/decompile-00775d60.txt / decompile-00775fb0.txt. Check their
complete boundaries, actual vtable/base-class shape and normal C++ feasibility
before editing declarations. The constructor calls shared base owner 0x759C10;
Step also calls virtual slot +8, so the current two-slot opaque Scene declaration
is incomplete. Review the base and vtable before selecting a source model.
Existing scene views remain opaque/provisional;
linked vtables/data are not an accepted lane. Scene1 Step 0x7539F0 (6,908 bytes)
and neighboring scene/resource methods offer larger follow-up owners.
Startup's scene constructors are still explicit external destinations. Do not
optimize for small-function counts or accept decompiler hypotheses as ABI proof.

The Draw implementations 0x409A90/0x40A0B0 were inspected completely. Like the
865-byte 0x40A440 kernel, they have body-local ESI/EDI push/pop and AH/AL pixel
loops consistent with handwritten assembly. No permitted natural-C++ exact
strategy is proven, so no prefix/assembly-wrapper credit was accepted. The
blended callee's last argument is loaded as a signed byte; existing caller
names/types remain provisional. Retain .analysis/probes/draw-*-review.txt and
the Ghidra decompile for future evidence-driven work.

Timing thread 0x401850 has a complete 157-byte body with two initialized locals
that are never read. Its logic is documented in KNOWLEDGE_BASE.md; it remains
open rather than adding inert source to force those stores. No target-specific
roadblock prevents work on the Context/scene owners.

Production TU partitioning, linked data/resources/imports, callee closure, the
runnable Windows product, original/reconstructed runtime comparison and
portability are independently tracked later phases.
