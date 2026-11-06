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
| Authored complete exact functions | 254 |
| Authored exact instruction bytes | 246,620 |
| Associated exact local-table bytes | 783 |
| Reviewed boundaries / origins | 294 / 294 |
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

## Latest Mizuka action checkpoint

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

Mizuka Slot02 command scanner4FAF70/11423 has a fresh decompile but no source
credit. Slot05 CPU4FDC10/16912, shared slot06 at4E7EC0/65782 and slot07 local
effects501E20/42279 remain available; inspect complete boundaries/local tables.
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
