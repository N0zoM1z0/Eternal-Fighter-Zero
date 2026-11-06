# Current handoff — 2026-11-06

## Operator state and starting point

The operator stopped further reconstruction, cleared the active goal and asked
for code/document cleanup, storage cleanup and handoff to another agent.
The last in-flight native comparison was completed and recorded; no additional
reconstruction task is active. Suggested follow-ups below are a backlog, not
an instruction to resume automatically.

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
| Authored complete exact functions | 220 |
| Authored exact instruction bytes | 221,678 |
| Associated exact local-table bytes | 667 |
| Reviewed boundaries / origins | 258 / 258 |
| Compiler-generated auxiliary helpers | 12 functions / 512 bytes |
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

## Final in-flight checkpoint

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

Choose substantial owners and useful small functions when reconstruction is
explicitly resumed. Review complete boundaries and compile a complete source
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
- Scene2 is the random system\\nl loading interlude returning scene ID3; its
  constructor/table/decompiles are retained in .analysis/probes/scene-battle/.
  Scene6 and concrete background owners are also possible follow-ups.
- DrawSurface409A90, blended40A0B0 and kernel40A440 have reviewed body-local
  ESI/EDI saves and AH/AL pixel loops consistent with handwritten assembly.
  No permitted natural-C++ exact strategy is established. Read
  .analysis/probes/draw-*-review.txt; do not use naked/assembly/byte wrappers.
  Other open Video owners include DrawShadowSurface40A7B0 /806,
  FillRectangle40B300 /308, SaveScreenshot40C1C0 /962 and buffer conversion.

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
