# Current handoff — 2026-11-06

## Operator state and starting point

The operator explicitly resumed active EFZ reconstruction on 2026-11-06,
requesting fast, careful exact recovery with focused checks and selected cold
replays only. Continue from accepted sources and reviewed target evidence;
never infer game completion from a successful unit.

Start with `git status --short --branch`, the diff, this file and AGENTS.md.
Use accepted `src/` and the reviewed ledgers. Preserve unrelated changes and
unfinished private drafts. Local checkpoints have not been pushed; never push
without an explicit instruction. Repository:
https://github.com/N0zoM1z0/Eternal-Fighter-Zero.

Use Bash and local `scripts/ghidra.py`; no REA, Factory prerequisites or subagents.
Keep code, comments, documentation and metadata English. Commit prefix:
`gpt-6.1-sol: `. Conversation may be Chinese.

## Accepted baseline

| Fact | Accepted result at this handoff |
| --- | ---: |
| Authored complete exact functions | 275 |
| Authored exact instruction bytes | 477,115 |
| Associated exact local-table bytes | 2,820 |
| Reviewed boundaries / origins | 314 / 314 |
| Compiler-generated auxiliary helpers | 14 functions / 579 bytes |
| Standard-library auxiliary wrappers | 4 functions / 90 bytes |
| Automatic non-external candidates | 950 |

[PROGRESS.md](PROGRESS.md) is generated from the live ledgers. Acceptance authority
is config/matches.csv plus docs/evidence/ and the per-unit recipes. Auxiliary
helpers are excluded from authored totals; candidates are not a coverage
denominator. A runnable product, linked data/resources, original TU partitioning,
original/reconstructed runtime comparison and portability remain open.

Accepted source covers reader/Audio/Input/Context owners, title and selection
scenes, substantial shared Secondary character code, the Shiori constructor and
ten child virtual bodies, and substantial battle scene control/collision/display.
Do not interpret this as full character, renderer or game closure. Historical
checkpoint facts and detailed target findings live in
[KNOWLEDGE_BASE.md](KNOWLEDGE_BASE.md); its older totals/open statements describe
those checkpoints, not today's queue.

## Latest Misuzu state checkpoint

Character23::Slot06 at 50C4B0 is complete exact: 54,769 instruction bytes plus
853 associated local-table bytes, total contribution 55,622. Code ends 519AA1;
the 134-destination address table ends 519CB9 and the 317-byte selector ends
519DF6. Ten following CC bytes precede accepted constructor 519E00 and are
excluded. Source: src/Character23State.cpp, profile vc71-od-static. Public proof:
docs/evidence/misuzu-state-exact.json; durable facts:
[Misuzu animation and state owner](KNOWLEDGE_BASE.md#misuzu-animation-and-state-owner).
Private attempts and full review: .analysis/probes/misuzu-state/README.md.

Independent review covers 14,960 contiguous instructions, 1,430 internal branches,
133 explicit animation cases and all 1,300 relocation fields: 343 direct calls,
821 typed floating operands and 136 local table bindings. All 77 literal
payloads and every original table destination agree. There are 217 real virtual
calls. The used 72-byte descriptor and ordinary duration/count locals recover
frame2B4, receiver EBP-54, descriptor EBP-50 and duration/count EBP-4/-8 without
padding or fake ABI declarations.

Preserve unsigned tick reads, actual byte/word updates, positive landing/collision
and cancel exits, original threshold immediates, frame rollback and integer
particle subtraction. Animation211's velocity update belongs inside its positive
airborne guard; animation212's positive hit exit precedes normal work. Specials
300..302/304 and repeat owners310..312 jump directly out of the dispatch. The
cutscene writes real Context state1420c/state1420e fields through actual owners;
do not reintroduce scaled pointer arithmetic from provisional decompiler text.

Formatted source passed one final selected cold complete strict zero-difference
native replay, including both complete tables. Public headers and all prior
source/recipes are unchanged; no old native unit needed replay. Focused tracking,
ledger/progress CI and whitespace checks passed. No native compiler/Wine failure,
full CI/cohort or runtime matrix occurred during this checkpoint.

Twelve of the 13 original table788650 destinations now have exact source proofs,
including inherited LoadResources. Next: local effects 5236D0/54139. Review its
complete code/table extent before acceptance and build a complete first natural
source early. Fresh canonical read-only decompile remains at
.analysis/probes/misuzu/calls-annotated-005236d0.txt; it confers no progress credit.
Keep the parked PrepareBattle/Shiori controls until new target evidence supplies
a falsifiable instruction prediction. This is not character/runtime or game
closure.

## Previous Misuzu CPU checkpoint

Character23::Slot05 at 51F3E0 is complete exact /17,127 instruction bytes,
exclusive end 5236C7. Nine following CC alignment bytes precede local effects
5236D0 and are excluded. No local tables occur. Source: src/Character23Cpu.cpp,
profile vc71-od-static. Public proof: docs/evidence/misuzu-cpu-exact.json;
durable facts:
[Misuzu CPU command and movement owner](KNOWLEDGE_BASE.md#misuzu-cpu-command-and-movement-owner).
Private full attempts and independent review: .analysis/probes/misuzu-cpu/README.md.

Review covers 4,399 contiguous instructions, 809 internal branches and all 318
relocation fields: 108 RandomRange calls, two CollisionSide calls, one external
fabs call and 207 typed floating operands. All 39 literal payloads match the
native COFF and canonical target. The used forward/vertical distance record
recovers EBP-10/-8, receiver EBP-14 and complete frame FC without padding.
Preserve physical decision priority, positive conditional tails, integer
constant-minus-boolean products, all random draws and unsigned AX conversions.
The original late condition really requires distance.forward >800 and <120;
do not simplify or repair its apparently contradictory source conditions.

Final formatted public source passed one selected cold complete zero-difference
native replay. No public header or existing source changed, so no prior native
unit required replay. Tracking, ledger/progress CI and whitespace checks passed;
no full CI/cohort or runtime matrix ran. One initial generated-source syntax
failure was corrected; the required toolchain --execute smoke passed before
subsequent builds. All compiler exits and attempts remain retained.

Eleven of 13 original table 788650 destinations had exact proofs at this
checkpoint, including the shared resource loader. State50C4B0/54769 has since
been accepted above; local effects5236D0/54139 remains open. Review complete
extents before
acceptance and build the first complete natural source early. Fresh read-only
decompiles remain under .analysis/probes/misuzu/; they confer no progress credit.
Preserve parked PrepareBattle/Shiori controls without a new falsifiable target
instruction prediction. This checkpoint does not establish character/runtime
or game closure.

## Previous Misuzu construction, input and indicators checkpoint

Ten complete exact functions add 21,917 instruction bytes without local tables.
Sources: src/Character23Frame.cpp, Character23Input.cpp and Character23Commands.cpp.
The canonical constructor 519E00/615, resource literal "misuzu" at 788648,
allocation 3488 and vtable 788650 establish Character23 ownership. Public proof:
docs/evidence/misuzu-exact.json; durable facts:
[Misuzu construction input and indicator owners](KNOWLEDGE_BASE.md#misuzu-construction-input-and-indicator-owners).
Private complete attempts and reviews: .analysis/probes/misuzu/README.md.

Accepted bodies include InitializeState 51A070/555, ResetPose 51A2A0/58,
RemoveLocalEffect 51A2E0/80, locomotion 51A330/19, action input 51A350/12340,
HUD indicators 51D390/2631, frame control 51DDE0/330, EmitLocalEffect 51DF30/47
and command scanning 51DF60/5242. Complete review covers 5,766 instructions,
780 internal branches and all 136 relocation fields. All boundaries exclude
following padding; no local-table or partial-function acceptance is used.

Preserve opponent ownership of frame-control tint, field345c * frame.width
operand order in the gauge, constructor/initializer store order, actual byte
increments, positive air-action branches, unsigned command stages and every
scan's single-wrap 180-entry history indexing. The ordinary 72-byte effect
descriptor, real shared methods and natural class alignment retain the target
ABIs without padding or fake declarations. Only Character23's existing opaque
tail in CharacterViews.h is expanded; Engine.h and Input.h are unchanged.

Formal replay selected the ten new units and 27 actual CharacterViews.h
consumers from 17 serial cold artifacts. All 37 complete comparisons passed
strict zero differences. Refreshed local-symbol identities preserve reviewed
offsets, destinations and literal bytes. The other 254 existing units retain
their prior evidence. Focused tracking, ledger/progress CI and whitespace checks
passed; no full CI/cohort or runtime matrix ran.

Ten of the 13 original vtable destinations had exact proofs at this checkpoint,
including the inherited shared resource loader. CPU 51F3E0/17127 has since been
accepted above; state 50C4B0/54769 and local effects 5236D0/54139 remain open.
Fresh read-only decompiles are retained under the private Misuzu probe;
they confer no progress credit. Preserve parked PrepareBattle/Shiori
controls unless new evidence gives a falsifiable instruction prediction.

## Previous Mizuka state checkpoint

Four complete exact units add65,964 instruction bytes plus836 local-table bytes:
Character24::Slot06 at4E7EC0/65782 code, Secondary::SetHorizontalOffset410A40/63,
Context::StartReverseFade408080/59 and Context::SetSceneTimer4080C0/60. Source:
src/Character24State.cpp and src/MizukaStateSupport.cpp. Main complete contribution
66618 bytes ends4F82FA, including130-destination /316-selector tables; six CC
bytes precede the accepted constructor4F8300. Public proof:
docs/evidence/mizuka-state-exact.json; durable facts:
[Mizuka animation and state owner](KNOWLEDGE_BASE.md#mizuka-animation-and-state-owner).
Private full attempts/review: .analysis/probes/mizuka-state/README.md.

Complete review covers17,962 instructions,1,636 internal branches,129 animation
cases and1,454 relocation fields:442 calls,880 typed floating operands and132
local bindings. Preserve explicit unsigned tick/0158 reads, positive landing/
slide tests, direct state exits, animation178's separate completed-frame exit,
integer particle subtraction, all random draws and exact floating operand order.
The real used72-byte descriptor and ordinary duration/count locals yield frame42C,
receiverEBP-54, descriptorEBP-50 and duration/countEBP-4/-8 without padding.

Three nonvirtual method declarations and two canonical word/byte stores refine
Engine.h; remaining layout and existing method bodies are unchanged. Formal
replay selected4 new units plus244 actual Engine.h consumers from67 serial cold
artifacts; all248 strict whole-contribution comparisons passed. Local-symbol
identities were checked against unchanged offsets/destinations/literal bytes.
Thirty-three unrelated old units retained earlier evidence. Focused tracking,
ledger/progress CI and whitespace checks passed; no full CI/cohort/runtime matrix.

All13 original table7885D0 destinations now have complete exact source proofs,
including the inherited resource loader. This is a virtual-entry inventory
milestone, not linked-data/resource, runtime or game closure. The next character
is now target-bound to Misuzu/Character23 above, with accepted constructor and
nine child virtuals. Its state body50C4B0/54769 remains open; recheck the live
ledgers before selecting further owners.
Do not retry parked PrepareBattle/Shiori-state controls without a new target-
backed instruction prediction.

## Previous Mizuka local-effect checkpoint

Three complete exact units add42,383 instruction bytes plus348 local-table bytes:
Character24::Slot07 at501E20/42279 code, SecondaryPose::VectorAngle4C0480/45 and
Context::StartFade408040/59. Sources: src/Character24Effects.cpp and
src/MizukaEffectSupport.cpp. Main complete contribution42627 bytes ends at50C4A3,
with its full62-destination address table and100-byte selector; thirteen CC bytes
precede next function50C4B0. Public proof: docs/evidence/mizuka-effects-exact.json;
durable facts: [Mizuka local effect dispatch and controls](KNOWLEDGE_BASE.md#mizuka-local-effect-dispatch-and-controls).
Private attempts/review: .analysis/probes/mizuka-effects/README.md.

Review covers9,600 main instructions,715 direct branches, one indirect switch,
61 explicit effect cases and505 total new relocation fields. Preserve type437
between420 and421, positive hit/cancel/bounce branches, word frame arithmetic,
actual random-sample coefficient order and direct switch exits440/497/498.
Whole-contribution strict comparison includes all348 table bytes; normalized
branch/case diagnostics never confer acceptance. VectorAngle uses the real pose
receiver atthis+8; the external CRT descriptor78F220 explicitly names atan2.

Only two nonvirtual Engine.h declarations change; public data layout and old
method bodies are unchanged. Formal affected replay selected3 new units plus241
Engine.h consumers from65 serial cold source/profile/dependency artifacts; all
244 complete comparisons passed strict zero-difference. Generated local-symbol
identities were reviewed against unchanged offsets/destinations or literal bytes.
Thirty-three unrelated old units retain prior evidence. Focused tracking, ledger/
progress CI and whitespace checks passed; no full CI/cohort/runtime matrix ran.

Slot06 state4E7EC0/65782 has since been accepted above, completing the exact
virtual-entry code inventory for table7885D0. Linked data/resources, runtime and
game remain open. Preserve neutral parked PrepareBattle/Shiori-state controls.

## Previous Mizuka CPU checkpoint

Character24::Slot05 at4FDC10 is complete exact /16,912 instruction bytes,
exclusive end501E20; no local tables or following padding. Source:
src/Character24Cpu.cpp, profile vc71-od-static. Public proof:
docs/evidence/mizuka-cpu-exact.json; durable facts:
[Mizuka CPU command and movement owner](KNOWLEDGE_BASE.md#mizuka-cpu-command-and-movement-owner).
Private complete attempts and independent review: .analysis/probes/mizuka-cpu/README.md.
Review covers4,368 instructions,818 internal branches and341 relocation operands:
109 direct calls plus232 typed floating operands from38 distinct payloads.

The final formatted public source passed one selected cold strict complete
zero-difference native comparison. Public headers and existing sources are
unchanged; no old native unit replay was needed. Tracking, ledger/progress CI
and whitespace checks passed; no full CI/cohort or runtime matrix ran.
Preserve unsigned AX random conversions, x87 operand order, used distance record,
positive special-state timer priority, active movement timer exits and the
separate successful-choice/outer state204 exits. Original vtable is7885D0 slot5.

Slot07 local effects501E20/42279 and slot06 state4E7EC0/65782 have since been
accepted above. Existing exact owners do not establish runtime/character closure.

## Previous Mizuka command checkpoint

Character24::Slot02 at4FAF70 is now complete exact /11,423 instruction bytes,
exclusive end4FDC0F; no calls, relocations or local tables. Source:
src/Character24Commands.cpp, profile vc71-od-static. Public proof:
docs/evidence/mizuka-command-exact.json; durable facts:
[Mizuka circular command recognition](KNOWLEDGE_BASE.md#mizuka-circular-command-recognition).
Private full attempts and independent review: .analysis/probes/mizuka-command/README.md.
Review covers3352 instructions,547 internal branches and32 ordered scans.

One final selected cold artifact passed strict complete zero-difference
comparison after numeric-stage/whitespace formatting. Existing source and
headers are unchanged; no old unit replay was needed. Tracking, ledger/progress
CI and diff whitespace checks passed; no full cohort/CI/runtime matrix ran.
Preserve single-wrap history indexing, every scan window, sequential state
advancement, gate-mask !=0 versus positive command-ID terms, stage6/7 store
order and the short release/press scan's actual unsigned byte ==1/==0 checks.

Slot05 CPU4FDC10/16912, slot06 state4E7EC0/65782 and slot07 local
effects501E20/42279 have since been accepted above. Inspect the live ledgers
before selecting further units;
existing accepted virtuals do not imply a complete runnable character.

## Previous Mizuka action checkpoint

Eight new complete Character24/Mizuka virtuals add10,953 instruction bytes,
without local tables. Source: src/Character24.h, Character24Input.cpp and
Character24Frame.cpp. The partial view moved out of SceneLoadingCharacter.cpp;
Engine.h and CharacterViews.h are unchanged. Members: InitializeState4F8480/263,
ResetPose4F8590/58, RemoveLocalEffect4F85D0/80, Slot034F8620/19,
Slot04 action selection4F8640/10464, Slot014FAF20/11, Slot084FAF30/11,
EmitLocalEffect4FAF40/47. The original vtable remains7885D0.

Public proof: docs/evidence/mizuka-exact.json; durable findings:
[Mizuka action selection and lifetime](KNOWLEDGE_BASE.md#mizuka-action-selection-and-lifetime).
Private attempts and reviews: .analysis/probes/mizuka/README.md.
All ten selected complete strict native comparisons passed from three serial
cold artifacts: eight new functions and the two actual creation-source consumers.
All26 local table/destination bindings were independently checked; the original
25-entry character creation table is still compared completely. Focused tracking,
ledger/progress CI and diff whitespace checks passed. No full cohort or CI ran.

Keep original unsigned latch/countdown checks and byte increments/decrements,
positive frame-permission masks, >= meter thresholds, x87 operand order and
structured air-attack branches. Whole-function comparison after any source
change is essential. The large action selector alone reviews2655 instructions,
430 internal branches,42 direct calls,42 real virtual calls and87 relocations.

Mizuka Slot02 command scanner4FAF70/11423 has since been accepted above.
Slot05 CPU4FDC10/16912, slot06 state4E7EC0/65782 and slot07 local
effects501E20/42279 have since been accepted above. Inspect complete boundaries
and associated local tables for new owners.
A full target-bound character constructor and selected virtuals do not complete
that character's runtime implementation.

PrepareBattle was retested once with real accepted Backgrounds.h declarations,
base inheritance and layout. The full4031-byte compiled result against4029
remained unchanged, including first non-table GPR divergence76D743. Evidence:
.analysis/probes/loading-owner/README.md. That control is parked; no repeated
type/layout experiments without a new falsifiable prediction.

## Previous background checkpoint

All four animated background owners for stages1/10/12/16 now have complete
constructors, destructors, Update and Render implementations, plus both shared
resource loaders. Eighteen authored functions add9,248 instruction bytes and
16 local address-table bytes. The implicit abstract-base constructor /23 and
PatternSequence scalar-deleting helper /44 are auxiliary, without authored credit.
Source: src/Backgrounds.h, src/Backgrounds.cpp, src/BackgroundResources.cpp.
SceneBattleLoop now includes the real shared two-slot/28-byte declaration;
Engine.h and the other existing source owners are unchanged.

Public proof: docs/evidence/backgrounds-exact.json; target findings:
[Animated background owners](KNOWLEDGE_BASE.md#animated-background-owners).
Private full attempts, target dumps and reviews: .analysis/probes/backgrounds/README.md.
Final20 new and six actual SceneBattleLoop source consumers passed all26
complete strict comparisons from only three serial cold artifacts. All five
local table/destination bindings were independently checked before symbol-name
refresh. Tracking, ledger/progress CI and diff whitespace checks passed.
No whole cohort or runtime matrix ran.

Preserve the signed Render layer byte, stage01/10 different early returns,
stage12 switch fallthrough, stage16 type3 clamp to947, unconditional metadata
reads and full disabled BMP branch. The constructor's initial patterns array
is overwritten by LoadPatterns; the destructor uses scalar delete on the final
array pointer. These original behaviors are preserved, with no runtime repair.
Background16::Update is complete604 bytes (588 code +16 table), end752DBC.
The base implicit constructor has only a vptr store and receives auxiliary
compiler-generated origin rather than authored progress credit.

PrepareBattle remains open. This checkpoint supplies real background layout,
implicit-base and ownership evidence; any resumed experiment must make a
specific prediction from that evidence, not repeat its parked pointer/case controls.
Read both the background and scene-loading private READMEs before reuse.

## Previous loading checkpoint

Seven new complete authored functions add 3,779 instruction bytes and100 local
address-table bytes: Scene2 constructor76C6F0/74, destructor76C740/69,
Step76C790/488, renderer76C980/203, keyboard76DA10/11,
LoadCharacter76DA20/2551+100, and Mizuka/Character24 constructor4F8300/383.
Sources: src/SceneLoading.cpp and src/SceneLoadingCharacter.cpp. Scene2 now
exposes its genuine +434 loading surface while keeping allocation size438.
Character24's partial view has since moved into Character24.h; CharacterViews.h
is unchanged. Scene1 ID22 and Scene2 ID22 both create Character10; the loading
dispatch also handles the additional Mizuka ID24, allocation3460.

Public proof: docs/evidence/scene-loading-exact.json; durable findings:
[Loading scene and Mizuka creation](KNOWLEDGE_BASE.md#loading-scene-and-mizuka-creation).
Private evidence and parked substantial owner: .analysis/probes/scene-loading/README.md.
Final seven new and204 existing Engine.h consumers passed all211 complete strict
comparisons from57 selected serial cold source/profile/dependency artifacts.
All161 compiler-local destination/offset bindings and four original string
payloads were independently checked before any symbol-name refresh. The replay
resumed the existing cold artifacts after its initial inventory guard stopped on
three additional replay literals; no source/compiler failure or native restart.
Focused tracking, ledger/progress CI and diff whitespace checks passed.

PrepareBattle76CA50 remains OPEN. Complete target4029 bytes includes3893 code
and136 local address/selector bytes. parked-best preserves the complete4031-byte
draft and its full source/header/object context; this is not a two-byte-away
exact claim. First non-table operand mismatch is76D743 (background constructor
argument GPR choice); a later extra ECX receiver move adds2 bytes. Pointer
views/casts, destructor declarations and case scopes were byte-neutral and are
parked. Do not overwrite src with those private headers. Preserve full disabled
BMP branches and the independently confirmed stage16 scale0.125 and divisor1.5f.

## Previous screenshot checkpoint

`Video::SaveScreenshot` at 0x40C1C0 /962 is now complete exact in
`src/VideoScreenshot.cpp`, profile vc71-od-static-gs. One final selected cold
artifact passed with zero differences and twenty explicit relocation bindings.
Public proof: docs/evidence/video-screenshot-exact.json; complete target facts:
[Video screenshot writer](KNOWLEDGE_BASE.md#video-screenshot-writer).
Private attempts and audits: .analysis/probes/video-output/README.md.
No common header or accepted source changed, so no old units required replay.
Focused tracking, ledger/progress CI and diff whitespace checks passed.

Preserve its original palette/header overwrite order, stride calculation and
unchecked error behavior. Local scope or work-record changes require a complete
cold comparison. FillRectangle40B300 is also now confirmed to have a body-local
EDI save/restore around a handwritten-looking pixel loop; park it alongside the
other assembly-style blitters unless a permitted natural C++ strategy emerges.

## Previous battle checkpoint

Four complete authored members add 4,998 instruction bytes, with no local tables:

| Member | Entry | Bytes | Source / profile |
| --- | --- | ---: | --- |
| Scene3::DrawNumber | 0x75DB70 | 466 | SceneBattleVisuals.cpp / vc71-od-static |
| Scene3::RenderShadows | 0x762C50 | 1,440 | SceneBattleVisuals.cpp / vc71-od-static |
| Scene3::PollKeyboard | 0x765660 | 2,358 | SceneBattleInput.cpp / vc71-od-static-gs |
| Scene3::ResetReplay | 0x7661A0 | 734 | SceneBattleInput.cpp / vc71-od-static-gs |

The misleading RenderMeters declaration is now RenderShadows. The constructor's
17 adjacent font rectangles are represented as `numberStyles[17]` at +464,
without moving subsequent fields. Context exposes actual signed bytes 1340,
14281 and 14282; WordFile/Input grant the genuine Scene3 access. Video declares
the reviewed DrawShadowSurface callee at 40A7B0, whose implementation stays open.

Complete review covers 1,209 instructions, 93 internal direct branches,
38 direct calls, five actual virtual/COM calls and all 54 relocation fields.
Preserve the original disabled keyboard controls, F8 latch store, unsigned digit
arithmetic, signed replay-name bytes and actor/effect shadow-coordinate
asymmetry. These are target facts, not cleanup opportunities. See
[the durable findings](KNOWLEDGE_BASE.md#battle-number-shadows-and-keyboard-replay-control).

Final public sources, including their formatting edits, passed strict complete
comparison for four new and 210 actual Engine/Input/SceneBattle header consumers
from 55 serial cold source/profile/dependency artifacts. All 135 existing local
destination/offset bindings and the Shiori literal refresh were independently
checked. No full cold cohort or runtime test matrix ran.

- Public new proof: docs/evidence/battle-controls-exact.json; involved older
  owner certificates are refreshed, while unaffected reports retain prior proof.
- Private final reports: .analysis/exact/battle-controls-and-affected.json.
- Private target dumps, derivation attempts, boundary/operand review and replay
  selection: .analysis/probes/battle-controls/; read its README before reuse.
- Native log: .analysis/build/battle-controls-formal-replay.log and individual
  battle-controls-cold-* logs. Current accepted objects/receipts: build/match-units/.

Earlier accepted battle/display/collision checkpoints are documented under the
corresponding KNOWLEDGE_BASE headings. Their proof files include
battle-display-exact.json, battle-loop-exact.json, effect-collision-exact.json,
body-hit-exact.json, scene-collision-exact.json and scene-battle-exact.json.
Do not rerun private make/refine/add/prepare/publish/update-docs mutators on the
current baseline. They are retained derivation records, not idempotent tools.

## Parked work and possible follow-ups

Choose substantial owners and useful small functions as reconstruction continues.
Review complete boundaries and compile a complete source
before speculative flag/name sweeps. No future owner has acceptance merely
because its callers or declarations match.

- Shiori slot 6 at 0x4136D0 remains unaccepted. Read
  .analysis/probes/shiori-state/README.md and parked-best/ first. The full target
  is 63,132 bytes: 62,273 code +540 address-table +319 selector bytes, ending at
  0x422D6C. The best complete draft is 63,133 bytes; this is an extent delta,
  not one remaining byte difference. First divergence is 0x41FC1E, animation303.
  Repeated scope/increment/signedness controls were byte-neutral and are parked;
  the later slot-7 operand-order audit supplied no new falsifiable explanation.
  Its private headers predate accepted changes and must not overwrite src/.
- Pushbox 0x766B50 /2727 remains open. Four write-only temporary slots have
  immediate stores but no observed reads. Preserve
  .analysis/probes/scene-collision/pushbox-write-only-audit.json; do not invent
  dummy Booleans or padding to force bytes. Timing thread401850 /157 has a
  similar unresolved pair of initialized unused locals.
- Shiori's constructor is accepted; the 22 other called character constructors
  have reviewed boundaries/origins but no implementation credit. Constructor,
  allocation and 23-table evidence: .analysis/probes/character-create/.
  Other substantial character behavior remains available for recovery.
- Scene2 interlude and creation dispatcher are accepted, while PrepareBattle
  remains open as described above. Scene6 and other character behaviors remain
  possible follow-ups; the four concrete background owners listed above are now
  accepted, while unrelated owners still need their own complete proof.
- DrawSurface409A90, blended40A0B0 and kernel40A440 have reviewed body-local
  ESI/EDI saves and AH/AL pixel loops consistent with handwritten assembly.
  No permitted natural-C++ exact strategy is established. Read
  .analysis/probes/draw-*-review.txt; do not use naked/assembly/byte wrappers.
  Other open Video owners include DrawShadowSurface40A7B0 /806,
  FillRectangle40B300 /308 and buffer conversion.

The accepted Shiori slot7 contribution is 36,467 bytes including 332 table bytes,
ending at 0x434003; retain all 60 local bindings and the complete table comparison.
Context::UpdateEffect is a complete 14,305-byte contribution with 36 local-offset
bindings. Never substitute their Ghidra code-only candidates or normalized
case diagnostics for the accepted complete contribution.

## Verification when work resumes

Canonical ignored/read-only input: resources/EFZ.exe, 3,743,744 bytes, SHA-256
`3a1616d6c76d2eea08a95bb198d853e96cb6b9b3266e277ca1d167426dd66481`.
Release/modification provenance remains unresolved. EFZ.OLD, netplay binaries
and archive labels cannot substitute for this identity.

```bash
scripts/repo-python scripts/verify-target.py
scripts/repo-python scripts/verify-toolchain.py --check
scripts/repo-python scripts/ghidra.py verify
# Select only new/changed/header-dependent units; replace with actual unit IDs.
scripts/repo-python scripts/replay-exact-units.py --unit config-read-byte
scripts/repo-python scripts/validate-tracking.py --require-target
scripts/repo-python scripts/progress.py
scripts/repo-python scripts/ci.py --only ledgers
scripts/repo-python scripts/ci.py --only progress
git diff --check
```

Use CPython3.13.5 via scripts/repo-python. The pinned VC7.1 RTM compiler/linker
are 13.10.3077 /7.10.3077. Native builds are serial, CPU1, nice10, bounded/logged
and use EFZ's own win32 Wine prefix. Run --execute smoke for setup/tool changes
or actual compiler/Wine failures, not every unit. Ghidra12.1.3 queries are
serialized, read-only/noanalysis and target-attested. Keep per-unit profiles
and all explicit relocation symbols/destinations/evidence. No masked fields,
prefix/size-only comparisons, compare_size overrides or fake ABI declarations.

## Retained evidence and cleanup

The final cleanup corrected stale status/next-work claims, condensed this handoff
and retained durable historical findings. It did not reformat accepted function
bodies after their final native comparisons. The progress card's obsolete
"Initial checkpoint" label was removed. Only focused checks accompany this work.

[RE_ARTIFACTS.md](RE_ARTIFACTS.md) records storage cleanup, compressed evidence
recovery and private cleanup manifests. Preserve the canonical target, original
RAR, tool installations/links, Wine prefix, Ghidra database, analysis attempts,
logs, exact certificates and unfinished drafts. The reader/audio workbench is
historical and fully integrated; read its README before any reuse. Never apply
its old integration.patch or copy its drafts over accepted src/.
