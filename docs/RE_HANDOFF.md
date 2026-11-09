# Current handoff — 2026-11-09

This is the receiving agent's entry point. It supersedes the older notes saying
that reconstruction had stopped or that the pushbox owner had no source.
Reconstruction is active; the operator is preparing a handoff to another agent.

## Operator workflow

- Work on substantial/boss functions and small/leaf functions. Do not optimize
  for leaf count or avoid difficult owners.
- Use natural C/C++ and test falsifiable hypotheses against the canonical target.
  Earlier documents, decompiles and assumptions are leads, not authorities.
- The operator confirms there is no concurrent session editing this worktree.
  Inspect and reconcile existing dirty/untracked work; do not reset or discard it
  blindly.
- After substantive verified increments, commit with prefix gpt-web:. Make
  several coherent commits during a productive session. Never push without
  explicit permission.
- Replay only changed functions and actual affected consumers. Do not run a
  full cold replay/cohort merely for reassurance.
- Keep source, comments and documentation in English. Do not copy target bytes,
  add assembly wrappers, padding or fake ABI declarations to force a match.

## Repository and accepted baseline

- Repository: N0zoM1z0/Eternal-Fighter-Zero, branch main.
- Latest source-bearing checkpoint: 362b123 (gpt-web: clean pushbox source
  indentation). Later handoff/cleanup commits are documentation and artifact
  maintenance only. No push has been performed.
- Canonical read-only input: resources/EFZ.exe, 3,743,744 bytes, SHA-256
  3a1616d6c76d2eea08a95bb198d853e96cb6b9b3266e277ca1d167426dd66481.
- Generated docs/PROGRESS.md currently records 328 exact functions,
  1,000,341 exact code bytes, 6,845 associated local-table bytes, 371 reviewed
  complete boundaries and 365 reviewed origins out of 950 automatic candidates.
  These are ledger counts, not a fresh dependency-validation attestation.
  The Windows product, original-vs-native runtime comparison and portability
  remain open.
- Proof-freshness blocker: scripts/repo-python scripts/validate-tracking.py
  --require-target fails because 296 exact-unit certificates have stale source
  dependencies. The only stale path is src/Engine.h. Certificates record SHA-256
  33ba6c7d2b60fe5ad92c45d30952e09ef652e181547fb47be3bec4963d68496e; the current
  header is 6a561f046e674c673a089ed3b5c7aa2dabea99d8e803b39466036b1f739d0a3e.
  Commit 17edf49 changed SecondaryPose::field000c from short to unsigned short
  to match target MOVZX reads. A focused audit reconfirmed 296 stale certificates.
  Do not hand-edit receipt/dependency hashes or treat the ledger count as fresh.
- A focused scan found 18 source files / 35 exact units with direct field000c
  references. These are the first targeted replay candidates:
  secondary-construct, secondary-destruct, secondary-sequence-construct,
  secondary-sequence-destruct, secondary-input-construct, secondary-input-finish,
  secondary-reset-pose, secondary-reset-frame, secondary-initialize-state,
  secondary-emit-local-effect, secondary-remove-local-effect,
  secondary-advance-local-effect, secondary-clear-local-effects,
  character-08-cpu-input, character-08-update-local-effects,
  secondary-effect-set-polar-velocity, scene-battle-step,
  scene-battle-update-round, scene-battle-update-round-exit, scene-battle-render,
  scene-battle-clip-frame, scene-battle-render-background,
  character-24-cpu-input, character-24-update-local-effects,
  character-24-update-state, character-23-cpu-input, character-23-update-state,
  character-23-update-local-effects, character-15-cpu-input,
  character-15-update-state, character-07-cpu-input, character-07-update-state,
  character-05-cpu-input, character-05-update-state and character-03-cpu-input.
  Replay only changed/affected units and real consumers; separate codegen impact
  from a dependency-only freshness mismatch.
- Reader/audio integration is complete. Do not reapply workbench/reader-audio
  over accepted src files.
- Pinned native compiler: VC7.1 RTM 13.10.3077, profile vc71-od-static. Keep the
  EFZ Wine prefix and Ghidra project isolated. Use scripts/repo-python.

## Immediate substantial owner: Scene3::ResolvePushboxes

The target body begins at 0x766B50, spans 2,727 bytes and contains 708
instructions. It is called by Scene3::Step at 0x764137. The earlier handoff
claim that no source or match-unit existed is wrong: the natural C++ owner is
src/SceneBattlePushboxes.cpp and the focused unit is
scene-battle-resolve-pushboxes in config/match-units.toml. Its reviewed boundary
is 0x766B50..0x7675F7; the unit binds 35 original relocations.

The current VC7.1 /Od build is
build/match-units/scene-battle-resolve-pushboxes/SceneBattlePushboxes.obj.
Its source SHA-256 is 86987a06a3c9d57bc892d126cb9fc10e377073196849868a0f834a6d4dc9566b;
the current focused build receipt is
.analysis/build/scene-battle-resolve-pushboxes.build.json. The object is
exactly 2,727 bytes with 35 relocations, but it is not exact. The strict
compare rejects it because its relocation offsets differ from the target.
A relocation-normalized diagnostic comparison matches 1,652/2,727 bytes and
reports 1,075 differences; this is a research metric, not an acceptance result.

The candidate has the target 0x148 frame, but the stack layout still differs:
- Candidate this is at [ebp-0x70]; target this is at [ebp-0x60].
- Candidate pose pointers are at -0x74/-0x78; target pointers are at -0x64/-0x68.
- Candidate TransformPoseBox output rectangles are at -0x5c/-0x6c; target
  output buffers are at -0x4c/-0x5c.
- The target materializes four x87 boundary predicates as 32-bit stores at
  -0x6c, -0x70, -0xdc and -0xe0. The current source stores its branch flags in
  different slots. volatile bool is not equivalent because it emits byte stores.

### Target facts to preserve

- The first horizontal branch is
  (first.left + first.right) - (second.left + second.right) > 0; the other is
  <= 0, matching target sub/test/jle at 0x766CAA..0x766CAE.
- CollisionSide signs are fighter 0 -1 / fighter 1 +1 in the first branch,
  then fighter 0 +1 / fighter 1 -1 in the opposite branch. Preserve the order
  in which both velocity locals are masked before comparison.
- The four boundary comparisons are fighter 0 X <=160 before and >160 after
  the first correction; fighter 1 X >=479 before and <479 after the opposite
  correction. Their 32-bit stores are real compiler-visible effects even though
  later source code does not consume their values.
- TransformPoseBox at 0x767600 receives ECX=this, stack +8 output SurfaceRect*,
  +0xC SecondaryPose* and +0x10 source-box pointer; EAX returns the output
  pointer and the callee uses RET 0xC.
- BoxesOverlap at 0x767930 is exact (128 bytes, no relocations).
  Secondary::CollisionSide at 0x40FF70 is exact across 222 bytes and six
  reviewed DIR32 fields.

The older 150, 174, 236, 259, 265–271, 276 and 277 probes are historical
controls, not the current best implementation. Recent focused experiments
varied frame records, explicit pose-pointer lifetimes, local aggregate order,
function/branch scopes, flag
declaration order and /O1-/O2 settings. None improved the current 1,652-byte
diagnostic match. Their generated source/object/build artifacts were archived
during the 2026-11-09 cleanup; restore only a specific candidate if a new
hypothesis justifies it.

Next, focus on the target's local lifetimes and x87 boundary predicates. Recover
the target this/pose/output stack homes while retaining the four 32-bit
predicate stores. Compare the entire 2,727-byte function and all relocation
bindings after each focused build. Do not infer exactness from size, instruction
histograms or the normalized diagnostic score.

## Video character pixel kernels

All five target bodies now have reviewed complete boundaries, focused
match-units and natural C++ semantic owners in src/VideoCharacterDraw.cpp.
None has passed a complete strict comparison:

| Owner | Target | Size |
| --- | ---: | ---: |
| DrawSurface | 0x409A90 | 799 |
| DrawBlendedSurface | 0x40A0B0 | 897 |
| DrawCharacterTint | 0x40A440 | 865 |
| DrawShadowSurface | 0x40A7B0 | 806 |
| DrawCharacterSpecial | 0x40AAE0 | 808 |

The target loops use body-local ESI/EDI saves and AH/AL operations. The current
C++ implementations preserve semantic clipping, lock/error paths, keys,
mirroring and palette operations, but their code generation remains open.
Important findings:
- DrawShadowSurface reads a bottom-up source mask, advances three source pitches
  per destination row, skips key pixels and blends through
  meanBlend[destinationPixel][colorIndex].
- DrawCharacterSpecial is a rightward in-place three-pixel back-surface shift,
  gated by a source mask when the key is nonzero. Mirror reverses the mask read,
  not the destination shift; the descending column loop preserves source pixels.
- DrawCharacterTint uses the signed-byte tint parameter and sumBlend lookup.
- DrawBlendedSurface accepts only signed-byte modes 0/1 and selects meanBlend or
  sumBlend. DrawSurface is the normal keyed/unkeyed pixel copy.

Use the five focused unit IDs from config/match-units.toml. Rebuild and compare
only the owner being changed; do not use a full cold replay. The detailed target
semantics and earlier candidate-size experiments are in docs/KNOWLEDGE_BASE.md.

## Accepted scene owners — do not reopen

- Scene2 constructor (0x76C6F0), Step (0x76C790), Slot0 renderer (0x76C980)
  and PollKeyboard (0x76DA10) are complete strict exact in
  src/SceneLoading.cpp. PrepareBattle is a separate open callee.
- Scene3 Step, Slot0 renderer, UpdateRound/Exit, ClipFrame, RenderBackground,
  PollKeyboard and replay-control owners are accepted strict exact.
- The Scene3 collision chain is accepted strict exact at DispatchCollisions
  0x766480, TestBodyInteraction 0x7679B0, ResolveBodyHit 0x767F60,
  ResolveEffectHit 0x7697D0, ResolveEffectPair 0x76B090,
  ResolveEffectClash 0x76BAB0 and ResolveBodyEffect 0x76BD40. The smaller
  TransformPoseBox, TransformSnapshotBox and BoxesOverlap helpers are also
  accepted strict exact in src/SceneCollision.cpp. The large ResolvePushboxes
  owner at 0x766B50 is the remaining open boss in this chain.

## Other open substantial owners

- Makoto/Character03: Slot05 CPU at 0x5FB040 / 17,531 code bytes and Slot07
  effects at 0x5FF4C0 / 33,673 code bytes are already complete strict exact;
  do not reopen them. Slot06 at 0x5E85F0 remains open: 58,482 code bytes plus
  its reviewed 810-byte tables, 59,292 bytes total. Continue from
  .analysis/probes/makoto/README.md and its state-boundary/case-map evidence.
- Shiori Slot06 at 0x4136D0 remains unaccepted; its target contribution is
  63,132 bytes including code and both tables. The parked natural-C++ draft is
  63,133 bytes with a known register divergence. Read
  .analysis/probes/shiori-state/README.md and parked-best/ first; do not
  overwrite current shared headers from that snapshot.
- PrepareBattle at 0x76CA50 remains open: 3,893 code bytes plus 136 bytes of
  address/selector data, 4,029 bytes total. Read
  .analysis/probes/scene-loading/README.md and parked evidence.
- Scene3::Slot0 renderer at 0x7642A0 / 1,285 bytes, Scene3::Step at 0x763C20,
  and the associated battle-loop keyboard/control owners are complete strict
  exact in src/SceneBattleLoop.cpp. Do not reopen that accepted group.
- Do not let this list limit exploration; inspect current ledgers and choose
  substantial owners and useful leaves based on evidence.

## Focused startup and verification

    scripts/repo-python scripts/verify-target.py
    scripts/repo-python scripts/verify-toolchain.py --check
    scripts/repo-python scripts/progress.py
    scripts/repo-python scripts/build-match-unit.py --unit ACTUAL_UNIT_ID
    scripts/repo-python scripts/compare-coff-function.py --unit ACTUAL_UNIT_ID
    scripts/repo-python scripts/validate-tracking.py --require-target

The last command is currently expected to fail on the 296 stale Engine.h
dependencies. Documentation-only changes do not need compiler, Ghidra, cold
replay or full CI. For source changes, compare the complete affected function
and recheck actual consumers of changed shared inputs. Never push without
explicit permission.

## Storage and private artifacts

The canonical target, .tools toolchain links/installations, EFZ Wine prefix,
Ghidra project, accepted build/match-units objects and public evidence must be
preserved. Scratch builds and probes may be restored from the lossless archives
described in docs/RE_ARTIFACTS.md. Do not delete the original RAR, target,
toolchain, Wine state or Ghidra database as routine cache cleanup.
