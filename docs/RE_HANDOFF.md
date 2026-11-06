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
followed by character input/replay, visual trail ownership and the complete body/trail renderer,
then common state dispatch, movement and timer updates with their supporting predicates/buffer clears,
followed by guard decisions, damage/combo factors, scoring and replay-aware random ranges,
then the complete local-effect renderer/reset and the Shiori constructor,
followed by Shiori command/state control, meter, initialization/effect ownership,
and the shared facing/grounded locomotion owners, then the complete Shiori
input-history recognizer and CPU command/movement owner, followed by the complete
local-effect dispatcher and its shared controls, followed by battle scene
construction, camera tracking/shake composition, sound consumption and intro events.
The full game remains incomplete; continue from the accepted src/ baseline and reviewed ledgers. Never infer whole-game completion from
these owner-level successes.

Use Bash and local Ghidra; no REA or subagents. Keep code, comments, documentation
and metadata English. Commit verified progress with prefix `gpt-6.1-sol: `.
The public repository is https://github.com/N0zoM1z0/Eternal-Fighter-Zero;
checkpoints remain local until the operator explicitly requests a push.

## Accepted baseline

| Fact | Accepted result |
| --- | ---: |
| Authored complete exact functions | 196 |
| Authored exact instruction bytes | 168,890 |
| Associated exact local-table bytes | 667 |
| Reviewed boundaries / origins | 234 / 234 |
| Compiler-generated auxiliary helpers | 12 functions / 512 bytes |
| Standard-library auxiliary wrappers | 4 functions / 90 bytes |
| Automatic non-external candidates | 950 |

config/matches.csv and docs/evidence/ are the acceptance authority. Candidate
counts are not an authored-code denominator. No runnable replacement or
whole-game completion percentage is claimed.

The largest accepted individual body is Character08::Slot07 (0x42B190):
36,135 code bytes and 332 associated table bytes, compared as the complete
36,467-byte contribution through exclusive end 0x434003. All 426 relocations,
including 60 compiler-local destination/offset bindings, are independently checked.
Context::UpdateEffect (0x401C20) remains exact as a complete 14,305-byte
contribution with its 301 relocations and 36 local offsets intact.

## Latest exact progress

The latest checkpoint adds five complete Scene3 battle functions: constructor
0x7633A0 /2129, UpdateCamera 0x7647B0 /1530, PlayCharacterSounds 0x764DB0 /337,
PlayEffectSounds 0x764F10 /296 and UpdateIntro 0x766070 /292. All 4,584 instruction
bytes and 45 explicitly reviewed relocation fields compare strict exact. The
Scene3 table at 0x7895DC independently identifies renderer 0x7642A0, Step 0x763C20
and keyboard 0x765660; those entries remain open. Source is SceneBattle.cpp.
Context exposes short 1352, ints 14238/14240 and SurfaceRect 14248 in previously
unknown storage. Five new and 174 shared-header-dependent existing units are
exact from 46 serial cold artifacts; all 135 existing local offsets are checked.
Proof is scene-battle-exact.json; final private replay is
.analysis/exact/scene-battle-and-affected.json. Only involved units and focused
ledger/progress/whitespace checks ran. No full CI or runtime matrix ran.

Next pursue the battle owner from .analysis/probes/scene-battle/. Read its README
and target-attested decompiles before editing. The complete Step at 0x763C20
connects the newly accepted helpers to character update, round control and
collision. Substantial open bodies include collision dispatch 0x766480 /1734,
pushbox resolution 0x766B50 /2727, hit processing 0x767F60 /6245 and 0x7697D0
/6334. Inspect real receivers and complete helper signatures before defining new
methods. The camera and event source can remain accepted while those owners are
recovered. Scene2 is the random system\nl loading interlude that returns scene
ID 3, not the battle owner. Its constructor/table/decompiles are retained too.

The Shiori slot-6 first-divergence audit found no new falsifiable explanation
from slot-7 operand-order evidence: animation 303's scalar tick increment at
0x41FC1E has no analogous indexed/random expression. No new slot-6 build or
comparison was run; it remains parked without acceptance. See
.analysis/probes/shiori-state/new-operand-order-audit.md.

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

Checkpoint 6acd870 adds six authored functions for 3,700 instruction bytes:
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

Checkpoint 873e981 adds nine authored functions for 3,895 instruction bytes:
DispatchState 0x40F230 (575), CheckAirAction 0x40F470 (262), UpdateMovement
0x40F580 (1,012), UpdateTimers 0x40F980 (1,509), CollisionSide 0x40FF70 (222),
two numeric state-group predicates 0x410340/0x4103A0 (91/126), and the buffered-
button/history clears 0x40F170/0x40F190 (31/67). Full canonical review covers
1,047 instructions, 144 internal branches, all returns/alignment successors and
46 explicit relocations. Source is SecondaryFrame.cpp; no auxiliary/table credit
is added. State-group names are numeric/provisional, not inferred gameplay labels.

The substantial owners recover state dispatch and two virtual calls, airborne
ID 157/158 transitions, body and 64-slot effect movement, edge tests, timed flags,
float-state decay/growth, suppression/countdowns and final clamps. Original ECX
setup corrects hidden decompiler receiver assumptions: movement edge predicates
and the later timer group query use the opponent. CollisionSide returns signed
byte +1/-1/0 and uses the actual 280.0 distance constant. Original FPU operand
order, float conversion and the 0.0*slot70 operation are retained. Float field
134 replaces the old zero-store-only int view, while InitializeState still
matches all 795 bytes. Counters 30D0/E0/E4 and frame flags AA/B0 are unsigned from
explicit reads/tests. Object offsets/extents remain unchanged.

Thirty-three cold artifacts cover nine new and 134 existing Engine.h-dependent
units: all 143 complete comparisons are strict exact. All 75 local bindings and
original destinations remain checked. Standalone Input, Reader and Config are
unaffected and omitted. New proof is secondary-frame-exact.json; involved owner
proofs are refreshed. Private final replay is
.analysis/exact/secondary-frame-and-affected.json, with complete trials/reviews
and the initialization diagnostic under .analysis/probes/secondary-frame/.
See [the frame/movement facts](KNOWLEDGE_BASE.md#character-frame-state-and-movement).
No compiler/Wine failure occurred; routine --execute smoke was not repeated.

The latest checkpoint adds eleven authored Secondary functions for exactly
2,000 instruction bytes: CanGuard/GuardInput 0x410050/0x4100F0 (149/494),
AirActionReady/group-C predicate 0x4102E0/0x410420 (89/91), three double-returning
damage/health/combo factors 0x410480/0x410530/0x410560 (163/47/62), ApplyDamage
0x4105A0 (489), AwardComboScore 0x410790 (172), AddScore 0x410840 (96), and
short-returning RandomRange 0x4108A0 (148). Complete review covers 567
instructions, 72 internal branches and 41 explicit relocations. Score's complete
extent ends at the adjacent random routine entry; no padding/table credit is
added. Source is SecondaryCombat.cpp, with no auxiliary credit.

Human/CPU/training guard branches, frame flags, actual floating return/receiver
contracts, three-factor damage with truncation, original repeated scaling,
unsigned maxima/counts and 100,000,000 score carry are retained. A8 is a float;
100 and score/record words 30C8/30CC/30D4/30D8 are unsigned from target accesses. The
random range always calls rand before replay substitution/recording and returns
a short after signed division by 32,768. Guard uses its separate direct rand
path. The first damage/factor/score sources were complete strict exact; guard
operand order, conditional-result form and an actually used short result local
resolved the remaining differences without padding or ABI tricks.

Thirty-four cold artifacts cover eleven new and 143 Engine.h-dependent existing
units: all 154 complete comparisons are strict exact. All 75 original local
bindings/destinations remain checked. Standalone Input, Reader and Config are
unaffected and omitted. New proof is secondary-combat-exact.json; involved owner
proofs and ledgers are refreshed. Private final replay is
.analysis/exact/secondary-combat-and-affected.json, with full trials/reviews under
.analysis/probes/secondary-combat/. See
[the guard/damage/score facts](KNOWLEDGE_BASE.md#character-guard-damage-and-score).
No compiler/Wine failure occurred; routine --execute smoke was not repeated.

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
capture/wrappers and the full body/trail renderer. Common state dispatch,
air-action transitions, movement, timer updates, numeric state predicates and
input-buffer clears are exact too, followed by guard/damage/combo/score/random
owners. Move into substantial remaining owners rather than accumulating leaf
counts. The local-effect renderer 0x413100 /1,488 bytes, reset 0x413090 /106 bytes,
and Shiori constructor 0x422D70 /462 bytes are now accepted. Full new/affected
replay covers 157 strict complete units in 37 cold source/profile artifacts;
standalone Input, Reader and Config units were omitted. New source is
SecondaryLocalRender.cpp, SecondarySpawn.cpp and Character08.cpp. New proofs are
secondary-local-render-exact.json and character-08-exact.json. The constructor
preserves the original command-slot overwrite and 0x3458 extent; 22 other called
constructors remain reviewed but unimplemented.

The preceding checkpoint adds nine authored complete exact bodies /13,965 bytes:
Shiori slot-4 command/state dispatch 0x423140 /11,306, slot-1 meter rendering
0x425D70 /1,080, initializer 0x422F40 /322, pose reset 0x423090 /58, local effect
removal/emission 0x4230D0 /80 and 0x4261C0 /47, slot-3 locomotion wrapper
0x423120 /19, shared facing 0x40E630 /130 and grounded locomotion 0x40E740 /923.
Seven child virtual bodies plus the preceding constructor are accepted; this does
not establish linked table placement, all character behavior or whole-game closure.
Source is Character08State.cpp, Character08Frame.cpp, SecondaryFacing.cpp and
SecondaryLocomotion.cpp. Proofs are character-08-exact.json and
secondary-locomotion-exact.json. All 166 new/affected comparisons are strict exact
from 41 cold source/profile/dependency artifacts; 75 local destination/offset
checks and the independently checked constructor literal remain explicit. No
standalone Input, Reader or Config cohort was replayed. Private complete reviews,
first sources and trials are .analysis/probes/shiori-command/; final replay is
.analysis/exact/shiori-command-and-affected.json.

Checkpoint 92a602e accepts Shiori slot 2, Character08::Slot02 at 0x4261F0:
all 5,299 bytes through the final RET at 0x4276A2, followed by thirteen INT3 bytes.
Source is Character08Input.cpp. Sixteen priority-ordered scans recognize commands
from the 180-byte history ring and write field0262 for the accepted slot-4
consumer. Full review covers 1,536 instructions and 246 internal branches; no
calls, relocations or local tables are present. The target uses a single
conditional history wrap, signed facing and history index, unsigned sample/stage,
and separate consecutive stage checks. The second scan intentionally retains
different late/same-sample token bases 0xAA and 0xA0. See the knowledge base's
Shiori input-history section for all sixteen windows and output tokens.

One new formal cold source artifact compares strict exact; existing source and
shared headers are unchanged and no old unit was replayed. The new report joins
character-08-exact.json while preserving all eight previous reports. There are
now eight accepted child virtual bodies plus the constructor. Private full
trials and boundary review are .analysis/probes/shiori-input/; formal comparison
is .analysis/exact/shiori-input.json. Focused ledger/progress checks and whitespace
validation pass; no full CI/cold cohort or runtime matrix is needed.

Checkpoint 5b64e6d accepts Shiori slot 5, Character08::Slot05 at 0x4276B0:
15,066 complete code bytes through RET at 0x42B189, followed by six INT3 bytes.
Source is Character08Cpu.cpp. This is the CPU input/command and strategy/movement
owner. Full review covers 3,883 instructions, 722 internal jumps and 93 calls;
no local tables are present. All 297 relocations were independently reviewed,
including 204 floating operands and 38 distinct COFF/target literal payloads.
All ninety random calls retain original unsigned AX caller conversions. The
external fabs binding is reviewed, without claiming its implementation as exact.

Engine.h replaces existing padding with signed short field016C and four signed
ints at 1A0/1A4/3110/3114, retaining all extents. One new and 167 Engine.h-dependent
existing units compare strict exact from 43 cold source/profile/dependency
artifacts. All 75 local offsets/destinations remain explicit; changed local or
constructor-string identities are reviewed before per-unit receipt finalization.
Standalone Input, Reader and Config were omitted. Public involved proofs are
refreshed; formal reports are .analysis/exact/shiori-cpu-and-affected.json.
Private complete trials and original boundary/operand/constant reviews are
.analysis/probes/shiori-cpu/. Nine Shiori child virtual bodies plus the
constructor are accepted, totaling 33,739 instruction bytes. Focused ledger,
progress and whitespace checks pass; no full CI/cold cohort or runtime matrix.

The latest checkpoint accepts Shiori slot 7, Character08::Slot07 at 0x42B190:
36,135 complete code bytes through RET at 0x433EB6, then a 232-byte address table
and 100-byte selector map. The FULL accepted contribution is 36,467 bytes ending
at 0x434003; thirteen INT3 bytes precede the next helper. Review covers 8,192
instructions, 516 direct branches, one indirect switch, 57 explicit types,
43 default selector entries and all 58 address destinations. All 426 operands
are reviewed: 60 local bindings, 141 calls and 225 floating references. Source
restores original case order 441/443/442, direct switch exits and random-call
coefficient order; do not rely on numerically sorted decompiler cases.

Five independent complete support functions add 317 code bytes: polar velocity
0x434010 /77, vertical shake 0x410A10 /43, horizontal shake 0x410A80 /63,
byte/timer tint request 0x410B10 /96, and Context request 0x407CE0 /38. Behavioral
names remain provisional; exact offsets/arguments/bytes are established.
EffectSpawn now uses the reviewed common 72-byte descriptor base naturally.
Secondary C0/C8/30C0 and Context F33/1423C/14244/14280 views replace existing
unknown storage without shifting extents. The descriptor constructor/reset and
both emitter kinds receive the same original address. No fake ABI or padding.

All six new and 168 shared-header-dependent old units compare strict exact from
45 cold artifacts. All 135 selected compiler-local offsets and constructor
literal bindings remain explicit. Standalone Input, Reader and Config were
omitted. Public proofs are character-08-exact.json and the new independent
secondary-effect-controls-exact.json, plus refreshed involved earlier proofs.
Formal reports are .analysis/exact/shiori-effects-and-affected.json; private
full trials and independent reviews are .analysis/probes/shiori-effects/.
Focused ledger/progress and whitespace checks pass; no full CI/cold cohort or
runtime matrix ran. Two draft member-renaming compiler errors were corrected,
and the required toolchain execution checks passed afterward.

Shiori now has ten accepted child virtual bodies plus the constructor, totaling
69,874 code bytes. Slot 6 is still unaccepted as described below; slot 8 is the
small empty body at 0x4261B0. Fresh exact compiler evidence from slot 7 shows
how indexed/member addition order and center+(random-40) grouping affect GPR
allocation. Before resuming slot 6, inspect its FIRST divergence at 0x41FC1E
and formulate a specific instruction prediction using that evidence; do not
repeat parked byte-neutral scope/name/increment trials. If it supplies no such
prediction, move to another substantial shared/character owner. Do not prioritize
the tiny slot-8 body over substantive remaining owners.

The Shiori / Character08 slot-6 animation dispatcher at 0x4136D0 now has a complete
private C++ draft and a reviewed full extent: 62,273 code bytes, 540 address-table
bytes and 319 selector bytes, ending at 0x422D6C before alignment and the constructor.
Do not mistake the Ghidra code-only candidate for the complete contribution.
Owning table is 0x787DF8, slot operand 0x787E10, resource ID 8 /shiori. The byte map
has 134 explicit branches plus default over IDs 1..319. Actual reset-call receiver
and same-descriptor ownership are reviewed. Private helper/header views beyond
the accepted code are provisional; read .analysis/probes/shiori-state/README.md
before resuming. Its parked-best/ preserves the full source, private headers,
cold object and complete comparison, including both switch tables.

The best full draft is 63,133 bytes versus target 63,132, NOT one remaining byte
difference and NOT accepted progress. First register/instruction divergence is
0x41FC1E in animation 303. Remaining case diagnostics differ at 303..309 and
312..318, with extent deltas +1 in 307/308 and -1 in 315. No prefix/size-only/
masked acceptance or compare_size override is permitted. Pre/post increments,
extra normal scopes, combined tick comparisons, nested tests, signed tick storage
with unsigned reads, and signed/unsigned RandomRange caller views did not fix the
site and are parked. Revisit only with a falsifiable target/compiler prediction;
otherwise pursue another substantial character state/command owner. Do not blindly
rerun the retained derivation scripts against the evolving baseline. Keep the
existing signed RandomRange declaration and use explicit unsigned caller reads
when the original operand demands them. The current baseline accepts ten other Shiori virtual
bodies; this large slot-6 method remains absent from accepted match/source rows.

The base table at 0x787BCC has thirteen observed slots and no virtual destructor.
Child override sets are modeled from all 23 tables. Slot01..Slot08 names and the
no-stack-argument/unused-result source view are provisional. Separate interface
review from body recovery and linked-data placement; declarations alone confer
no child-body credit. Ten Shiori overrides now have separate complete exact proofs. All 23 called character constructors have
reviewed boundary/origin rows; Shiori is accepted and the other 22 remain unimplemented. Their allocation and
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
