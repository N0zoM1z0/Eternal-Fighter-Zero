# Current handoff — 2026-11-06

## Task state

The operator resumed exact reconstruction on 2026-11-06 and requested focused
new/affected comparisons without full CI/cold cohorts or redundant tests.
The current checkpoints complete the preserved PatternReader and Audio owners,
then DirectInput, Audio playback controls, Context input/audio transitions and
the complete title scene with its shared base/fades and palette/frame wrappers,
and substantial character-selection update/entry/resource functions plus the
complete selection renderer and character creation dispatcher, followed by the
shared character lifetime/state/local-effect/resource-reuse owner and statistics I/O,
then all three character resource loaders and both character image-transfer methods,
followed by character input/replay, visual trail ownership and the complete body/trail renderer.
The full game remains incomplete; continue from the accepted src/ baseline and reviewed ledgers. Never infer whole-game completion from
these owner-level successes.

Use Bash and local Ghidra; no REA or subagents. Keep code, comments, documentation
and metadata English. Commit verified progress with prefix `gpt-6.1-sol: `.
The public repository is https://github.com/N0zoM1z0/Eternal-Fighter-Zero;
checkpoints remain local until the operator explicitly requests a push.

## Accepted baseline

| Fact | Accepted result |
| --- | ---: |
| Authored complete exact functions | 151 |
| Authored exact instruction bytes | 85,573 |
| Associated exact local-table bytes | 335 |
| Reviewed boundaries / origins | 190 / 190 |
| Compiler-generated auxiliary helpers | 12 functions / 512 bytes |
| Standard-library auxiliary wrappers | 4 functions / 90 bytes |
| Automatic non-external candidates | 950 |

config/matches.csv and docs/evidence/ are the acceptance authority. Candidate
counts are not an authored-code denominator. No runnable replacement or
whole-game completion percentage is claimed.

The largest accepted individual body is Context::UpdateEffect (0x401C20):
14,114 instruction bytes and 191 local-table bytes, compared as the complete 14,305-byte contribution
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

Checkpoint 1b1978d adds six Context input/audio members (1,232 bytes):
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

Checkpoint 44d09cb adds twelve complete functions: Scene base construction,
FadeOut/FadeIn, Scene0 construction/destruction/Step/render/keyboard, and Video
palette submission/range/RGB clearing/presentation. They add 3,769 instruction
bytes and 28 local-table bytes. The complete title Step contribution is 1,267
bytes: 1,239 code bytes through RET at 0x776486 and all seven switch entries at
0x776487..0x7764A3. All 79 new relocations, including eight local-offset bindings,
were independently reviewed against canonical original operands. Scene's three
pure virtual slots and Scene0's concrete table are now represented naturally;
linked vtable/data acceptance remains open. Context exposes menu state within
existing storage. Twenty-three cold source/profile/dependency artifacts cover
12 new and 95 Engine.h/Input.h-dependent units: all 107 complete comparisons
are strict exact. Reader and Config were unaffected and omitted. Public proofs
are scene-base-exact.json, scene-title-exact.json and video-frame-exact.json;
affected-owner proofs are refreshed. Private replay is
.analysis/exact/scene-and-affected.json. See the knowledge base's
[scene owner facts](KNOWLEDGE_BASE.md#title-scene-and-shared-scene-base).

Checkpoint 9302c66 adds seven complete Scene1 functions (10,780 instruction
bytes plus 20 local-table bytes): construction/destruction, Step, LoadStage,
LoadPlayerPalette, PollKeyboard and Enter. The complete Step contribution is
6,928 bytes through 0x755500, including its five-case table after RET at
0x7554EB. All 199 new relocation operands were independently reviewed. The
provisional 0x560 Scene1 layout exposes surface slots, animation state, character
grid/order/offsets and selection flags without changing startup allocations.
Context byte signedness now follows actual Scene1 MOVSX/MOVZX reads; the shared
Secondary pointer pair is a natural array with identical base-constructor code.
Twenty-four cold source/profile/dependency artifacts cover seven new and 107
shared-header-dependent units, all 114 full comparisons strict exact. Reader
and Config were unaffected. Public proof is scene-select-exact.json; affected
proofs were refreshed. Private replay is
.analysis/exact/scene-select-and-affected.json. The effect and title dispatchers
retain every original destination and offset check after 44 local-symbol-ID
refreshes. Full CI/cold cohorts and redundant tests were omitted as requested.
See [the character-selection facts](KNOWLEDGE_BASE.md#character-selection-scene).
At that checkpoint render and character construction were open. The following
checkpoint accepts rendering; the following creation checkpoint accepts the
dispatcher, while its called constructors still prevent full closure.

Checkpoint 5ee3b32 accepts the complete Scene1 renderer at 0x755500 for
12,720 instruction bytes, with all 175 relocations explicitly bound. Independent
review covers 3,294 instructions, 63 internal direct branches, 61 rectangle
constructions, 35 draw calls and one presentation. All 489 bytes missing from
Ghidra's candidate body are ordinary loop code and are included in the strict
comparison. Natural rectangle scopes, multiplication order and zero-minus
coordinate expressions recover the complete 0x820 frame and all code. Shared
headers and existing source units were unchanged: only the new renderer was
cold compiled/replayed. Public proof is scene-select-render-exact.json; private
strict result is .analysis/exact/scene-select-render.json. See
[rendering facts](KNOWLEDGE_BASE.md#character-selection-rendering). The pixel
kernels and character construction remain explicit external calls.

Checkpoint 4d148b3 accepts Scene1::LoadCharacter at 0x7586B0: 3,399 complete
instruction bytes plus all 96 switch-table bytes, ending at 0x759457. The first
complete source and final integrated source are strict exact. All 97 relocations,
including 25 original local-offset bindings, were independently reviewed. The
24 allocation cases actually use 23 constructors: IDs 10 and 22 share 0x461090
and size 0x3460. CharacterViews.h records observed extents and external direct
constructor declarations. The following shared-base checkpoint adds observed
virtual overrides, while child constructor bodies and original class names remain open. Separate complete-boundary/common-base/argument/allocation
reviews add 23 reviewed constructor rows only, with no implementation credit.

The nine Scene1 contributions now total 26,899 instruction bytes and 116 local
table bytes. Called character constructors, rendering kernels and linked data
remain open. Secondary's minimum view now exposes character ID 8D, palette byte
8E, a resource-name view at 94..A4 and int CPU flag A4. Scene1 color keys 44C/44D
are an array; renderer's two reads remain exact. Twenty-four cold artifacts cover
one new and 104 Engine.h-dependent existing units, all 105 complete comparisons
strict exact. Standalone Input, reader and Config were unaffected and omitted.
The three old dispatchers retain every local offset/destination after 50 symbol
identity refreshes. Public proof is character-create-exact.json; private final
replay is .analysis/exact/character-create-and-affected.json. See
[creation facts](KNOWLEDGE_BASE.md#character-creation-dispatch) and the separate
[external constructor review](KNOWLEDGE_BASE.md#character-constructor-allocation-review).

Checkpoint 0adebca accepts sixteen authored shared-character/statistics
functions for 5,156 instruction bytes, plus a 106-byte generated sequence-delete
helper with auxiliary credit only. Secondary construction/destruction, embedded
trail/sequence lifetime, ResetPose/ResetFrame/InitializeState, all four local
effect-pool methods, LoadResources and statistics Read/Write are complete strict
exact. All seventeen extents and 117 relocation operands were independently
reviewed. Source is SecondaryLifetime.cpp, SecondaryState.cpp,
SecondaryResources.cpp and CharacterStatistics.cpp. Natural thirteen-slot
virtual declarations produce the base table writes; no manual vptr stores,
packing or fake front gap are used. The provisional base view extends to 3138,
including eight statistics words at 3118. Both base arrays contain 505 elements,
correcting the earlier 501-element note. The original statistics file contains
nine words, including a reserved zero word. Failure/unchecked paths are retained.

Twenty-eight cold artifacts cover 17 new and 105 existing shared-header-dependent
units: all 122 complete comparisons are strict exact. Four dispatchers retain
all 75 original local offsets/destinations after compiler-local identity refresh.
Standalone Input, reader and Config are unaffected and omitted. Public new proofs
are secondary-lifetime-exact.json, secondary-state-exact.json,
secondary-resources-exact.json and character-statistics-exact.json; affected
proofs were refreshed. Private replay is
.analysis/exact/secondary-base-and-affected.json and complete trial/review evidence
is .analysis/probes/secondary-base/. See
[the shared-character facts](KNOWLEDGE_BASE.md#shared-character-base).
The final trailing-blank-line cleanup in CharacterStatistics.cpp was followed by
one selected cold artifact and both complete statistics comparisons (268/357
bytes), again strict exact; final source hashes and proofs were refreshed.
Private cleanup replay is .analysis/exact/character-statistics-eof.json.

Checkpoint a08605c adds six authored functions (4,753 instruction bytes):
Secondary LoadImages 0x411080 (1,560), LoadPatterns 0x4116A0 (1,079), LoadSounds
0x411AE0 (241), SecondarySequence::Allocate 0x412AD0 (51), and Video's character
BMP/packed transfer methods 0x409090 (980) / 0x409740 (842). All complete target
boundaries and 133 relocation operands were independently reviewed. No new
auxiliary or local-table credit is included. Source is SecondaryLoaders.cpp and
VideoCharacterSurface.cpp. Full body review corrects the previously swapped
LoadSounds/LoadPatterns names, preserving original LoadResources destinations.

The three loaders now recover the DAT and unreachable BMP image alternatives,
the complete animation/rectangle record schema, fifty WAV paths and volume
calls. The extra animation records have 0xC8 stride; local effect record offset
8 receives the PatternSequence pointer. Both image-transfer methods retain the
original <40 versus +135 character color mapping and raw/BMP versus RLE row
order. Their first complete sources compare exact. PatternReader's unknown
four-byte tail is a word placeholder now: the old character-array placeholder
incorrectly triggered VC7.1 /GS stack reordering in LoadPatterns. Its original
semantics and complete type/alignment remain unresolved. Context::Load and all
twenty reader members remain exact after that refinement.

Thirty cold source/profile/dependency artifacts cover four new loader units and
142 existing Engine.h/PatternReader.h-dependent units; one additional artifact
covers the two Video methods. All 148 complete comparisons are strict exact.
The four dispatchers preserve all 75 local bindings/destinations after identity
refresh. Standalone Input and Config are unaffected and omitted. New proofs are
secondary-loaders-exact.json and character-surfaces-exact.json; affected-owner
proofs were refreshed. Private aggregate replay is
.analysis/exact/secondary-loaders-and-affected.json, with the final Video stage
also retained at .analysis/exact/character-surfaces.json. See
[the loader facts](KNOWLEDGE_BASE.md#character-resource-loaders).

The latest checkpoint adds six authored functions for 3,700 instruction bytes:
UpdateInput 0x411BE0 (1,467), Render 0x4121A0 (1,649), SecondaryTrail Capture
0x412930 (212) / Begin 0x412A10 (177), and Secondary AdvanceTrail 0x410940 (134) /
StartTrail 0x4109D0 (61). Full review covers 1,052 instructions, 82 internal
branches, all six final returns/alignment successors and 19 explicit relocations.
No local-table or auxiliary credit is added. Source is SecondaryInput.cpp and
SecondaryRender.cpp. The 1,649-byte body is rendering, correcting the previous
handoff's control label. Its first complete source was strict exact; UpdateInput
needed the observed training-CPU early return to resolve its three-byte delta.

The 2BC0 owner is visual trail history, now named SecondaryTrail/trail. Its
previously accepted constructor/FinishSample retain their historical unit IDs
and receive no duplicate credit. It has 60-entry coordinate, facing, animation
and frame arrays, plus pending/stride/held bytes and position. The two wrappers'
original null-preserving +8 conversion is naturally reproduced by inheriting
SecondaryPose at Secondary+8 (current 0x70-byte base view). The existing fields
keep all offsets, including opponent slot 78 and complete minimum view 3138.
The full 463-byte constructor remains exact; no manual pointer adjustment/vptr stores or
unique original source-graph claim are used. Input fields 188..19F and byte 1AA
are now explicit. Animation/frame indices 8/A are unsigned from target reads.
Human/CPU/training/replay/suppression paths and full normal/blended/tint/special,
trail and offscreen-fallback rendering paths are retained. Pixel kernels and
child virtual bodies remain unimplemented.

Thirty-two cold artifacts cover six new and 128 Engine.h-dependent existing
units: all 134 complete comparisons are strict exact. All 75 local bindings
and destinations remain checked. Standalone Input, Reader and Config are
unaffected and omitted. New proofs are secondary-input-exact.json and
secondary-render-exact.json; affected-owner proofs and source mapping symbols
are refreshed. Private final replay is
.analysis/exact/secondary-control-and-affected.json. See
[the input/trail/rendering facts](KNOWLEDGE_BASE.md#character-input-trails-and-rendering).
A missing-method declaration in the first private renderer compile caused C2039;
the required post-failure --execute compiler/linker/resource/execution smoke
passed before work resumed. All logs/trials are retained in .analysis/.

Important retained limits:

- Scene base is a provisional 0x430 minimum view, with palette at 0x2E;
  Scene0's startup allocation remains 0x44C. Other scene allocations and startup
  dispatch/delete bodies remain exact. No unique original class/type grouping
  or linked vtable placement is claimed. Direction-held fields are unsigned
  bytes; CPU flags are unsigned from Scene1 MOVZX reads. All four button-pulse
  arrays and mode1364 are signed bytes from explicit MOVSX evidence.
- Title inactivity increments per quiet player, twice per fully quiet frame;
  do not infer 30 seconds from threshold 1800. Keyboard failure still reaches
  the original buffer test. Fades preserve 16/15 ms busy waits. ApplyPalette
  submits 255 entries; Present returns zero only for surface loss and does not
  implement restoration. Its converter and DrawSurface remain open externals.
- Scene1 Step's table is 20 bytes at 0x7554EC, with all six original-offset
  bindings checked. Integer branch bounds and the nested path/digits scope are
  codegen evidence; do not flatten/rewrite them without a full comparison.
  Secondary's exposed fields through A4 are a minimum view, not a complete class
  size/name capacity/virtual-layout claim. Character allocation extents are
  separately observed 0x3448..0x34B0 values. Their constructor bodies remain open;
  the complete selection renderer and creation dispatcher are now exact.
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

The reader/audio/Input backlog, Context input/audio transitions and the title
scene/shared fade owner are complete at function-codegen level. Their successful
units do not complete the game. The Scene base has three reviewed virtual slots,
so subsequent scene work can use that shape while keeping per-owner fields and
ABI provisional. The nine Scene1 contributions, including the full creation switch/table,
are exact. The coherent shared Secondary base is now substantially recovered:
lifetime, state initialization, local effect management, resource reuse and
statistics are accepted. Its three resource loaders and both character image
transfer methods are exact too, followed by character input/replay, trail
capture/wrappers and the full body/trail renderer. Continue through the common
character frame/state routines: provisional candidates 0x40F230 (575 bytes),
0x40F470 (262), 0x40F580 (1,012) and 0x40F980 (1,509). Target-attested decompiles
are retained under .analysis/ghidra/; verify complete boundaries and actual
semantics before naming/acceptance, then build the first complete source early.
The recovered pose-base conversion and unsigned animation/frame indices support
that work. Related smaller helpers remain useful when they close the owner.
Do not treat the old input/pattern scratch labels as actual semantics.

The base table at 0x787BCC has thirteen observed slots and no virtual destructor.
Child override sets are modeled from all 23 tables. Slot01..Slot08 names and the
no-stack-argument/unused-result source view are provisional. Separate interface
review from body recovery and linked-data placement; no child override body is
accepted by these declarations. All 23 called character constructors still have
reviewed boundary/origin rows but remain unimplemented. Their allocation and
common-base evidence is .analysis/probes/character-create/. Do not count reviewed
declarations as exact functions. Two 505-element arrays at base offsets 10/164,
embedded trail history at 2BC0, the 64-record local pool at 4D0 and statistics at
3118 are target-backed. Keep unobserved bytes and original failure behavior.

The selection renderer's full evidence remains in .analysis/probes/scene-render/;
all 489 Ghidra-omitted instruction bytes are accepted in its complete 12,720-byte
comparison. The factory's 96-byte table and all failure paths are also retained.
Scene6 offers another larger follow-up owner after the shared character base.
Startup's other scene constructors remain explicit external destinations. Do not
optimize for small-function counts or treat decompiler hypotheses as ABI proof.
Preserve private trials and avoid overwriting src/ with archived workbench drafts.

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
