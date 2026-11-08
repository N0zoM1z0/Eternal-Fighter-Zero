# Current handoff — 2026-11-08

This handoff supersedes the 2026-11-07 statement that reconstruction had stopped.
The operator now requests that another agent continue the EFZ reconstruction.

## Current operator instructions

- Reconstruct both substantial/boss functions and small/leaf functions. Do not
  optimize for leaf count or avoid difficult owners.
- Use natural C/C++ and explore multiple falsifiable source hypotheses. Recheck
  earlier documents, decompiles and assumptions against the original target;
  none is automatically authoritative.
- The operator confirms there is no concurrent session or other agent editing
  this worktree. Inspect and reconcile existing dirty/untracked work as part of
  the task; do not avoid it, reset it, or discard it blindly.
- After each substantive verified increment, commit with prefix
  `gpt-web: `. Make several meaningful commits during a productive session;
  do not stop after one commit. Never push without explicit permission.
- Replay only the changed/affected functions and their actual consumers. Do not
  run a full cold replay/cohort merely for reassurance.
- Keep source, comments and documentation in English. Do not use copied target
  bytes, handwritten assembly, padding or fake ABI declarations to force a match.

## Repository and accepted baseline

- Repository: `N0zoM1z0/Eternal-Fighter-Zero`, branch `main`.
- Handoff checkpoint: `4754cc2b5e4b487cb738a2c7eb7e846910847d57`;
  the worktree was clean and `main` was in sync with `origin/main` when checked.
- Canonical ignored/read-only input: `resources/EFZ.exe`, 3,743,744 bytes,
  SHA-256 `3a1616d6c76d2eea08a95bb198d853e96cb6b9b3266e277ca1d167426dd66481`.
- `docs/PROGRESS.md` was regenerated and the canonical ledgers currently record
  328 exact claims, 1,000,341 code bytes, 6,845 associated local-table bytes,
  365 reviewed boundaries and 365 reviewed origins. This is the ledger count,
  not a fresh dependency-validation attestation for every claim. The Windows
  product, original-vs-native runtime comparison and portability remain open.
- **Existing proof-freshness blocker:**
  `scripts/repo-python scripts/validate-tracking.py --require-target` currently
  fails with `public comparison certificate has stale source dependencies` for
  296 exact-unit certificates. The only mismatched dependency path is
  `src/Engine.h`: certificates record SHA-256
  `33ba6c7d2b60fe5ad92c45d30952e09ef652e181547fb47be3bec4963d68496e`, while the
  current header is `6a561f046e674c673a089ed3b5c7aa2dabea99d8e803b39466036b1f739d0a3e`.
  This originates in commit `17edf49` (`gpt-web: correct Makoto frame counter
  and receivers`), which changed `SecondaryPose::field000c` from `short` to
  `unsigned short` to match the target's MOVZX reads. No receipts were edited or
  refreshed during this handoff, and no 296-unit cold replay was run.
- A focused source scan finds 18 source files / 35 exact units with direct
  `field000c` references. These are the first targeted replay candidates:
  `secondary-construct`, `secondary-destruct`, `secondary-sequence-construct`,
  `secondary-sequence-destruct`, `secondary-input-construct`,
  `secondary-input-finish`, `secondary-reset-pose`, `secondary-reset-frame`,
  `secondary-initialize-state`, `secondary-emit-local-effect`,
  `secondary-remove-local-effect`, `secondary-advance-local-effect`,
  `secondary-clear-local-effects`, `character-08-cpu-input`,
  `character-08-update-local-effects`, `secondary-effect-set-polar-velocity`,
  `scene-battle-step`, `scene-battle-update-round`,
  `scene-battle-update-round-exit`, `scene-battle-render`,
  `scene-battle-clip-frame`, `scene-battle-render-background`,
  `character-24-cpu-input`, `character-24-update-local-effects`,
  `character-24-update-state`, `character-23-cpu-input`,
  `character-23-update-state`, `character-23-update-local-effects`,
  `character-15-cpu-input`, `character-15-update-state`,
  `character-07-cpu-input`, `character-07-update-state`,
  `character-05-cpu-input`, `character-05-update-state`, and
  `character-03-cpu-input`. Other stale certificates still need triage; do not
  hand-edit their dependency hashes. Replay only affected units/consumers and
  distinguish codegen impact from a dependency-only freshness mismatch.
- Reader/audio integration is complete. Do not reapply the historical
  `workbench/reader-audio/` patch over accepted `src/` files.
- Pinned native compiler: VC7.1 RTM 13.10.3077, profile `vc71-od-static`.
  Keep the EFZ Wine prefix and Ghidra project isolated. Use the repository's
  `scripts/repo-python` wrapper for Python commands.

## Immediate large owner: `Scene3::ResolvePushboxes`

The target body begins at `0x766B50`, spans 2,727 bytes and contains 708
instructions. It is called by `Scene3::Step` at `0x764137`. `src/SceneBattle.h`
contains only the declaration; `src/SceneBattleLoop.cpp` contains the call.
The `scene-battle-step` relocation at unit offset 1303 is accepted evidence for
the caller, not for the pushbox body. There is no pushbox implementation in
`src/`, no dedicated match-unit recipe and no exact receipt.

### Target facts that must survive reconstruction

- The first horizontal branch is
  `(first.left + first.right) - (second.left + second.right) > 0`; the other
  branch is `<= 0`, matching target `sub; test; jle` at `0x766CAA..0x766CAE`.
- The four `CollisionSide()` signs are fighter 0 `-1`, fighter 1 `+1` in the
  first branch, then fighter 0 `+1`, fighter 1 `-1` in the opposite branch.
  Both velocity locals are masked in the original order before comparison.
- Four x87 boundary comparisons materialize values that are never read later:
  first-fighter X `<=160.0` before and `>160.0` after the first correction;
  second-fighter X `>=479.0` before and `<479.0` after the opposite correction.
  The target writes four 32-bit values to `[ebp-0x6c]`, `[ebp-0x70]`,
  `[ebp-0xdc]` and `[ebp-0xe0]`. They are real code-generation effects, not
  padding. A C++ `volatile bool` is not equivalent: it emits byte stores.
- `TransformPoseBox` at `0x767600` is called with ECX=`this`, stack `+8`
  output `SurfaceRect *`, `+0xC` `SecondaryPose *`, and `+0x10` source-box
  pointer; EAX returns the output pointer and the callee uses `RET 0xC`.
- `BoxesOverlap` at `0x767930` is already exact (128 bytes, no relocations).
  `Secondary::CollisionSide` at `0x40FF70` is independently exact across all
  222 bytes and six reviewed DIR32 fields.

### Latest natural-C++ probes — verified against the live objects

| Probe | `.text` | Frame | Instructions | Interpretation |
| --- | ---: | ---: | ---: | --- |
| 150 | 2,725 | `0x148` | 708 | Full target mnemonic histogram; 35 relocations; stack slots differ |
| 174 | 2,729 | `0x148` | 708 | Full target mnemonic histogram; 35 relocations; stack slots differ |
| 259 | 2,535 | `0x140` | 708 | Better rectangle/velocity result slots; only 276 `mov`, 16 `jmp`, 8 `jp`; four boundary comparisons absent |
| 276 | 2,711 | `0x148` | 708 | Full target mnemonic histogram; one reused volatile Boolean, wrong byte stores |
| 277 | 2,726 | `0x150` | 708 | Full target mnemonic histogram; 35 relocations; four volatile Booleans, wrong store widths/slots and frame |

The best current instruction-inventory/size probe is
`.analysis/probes/scene-battle/Pushboxes-twohundredseventyseventh.cpp`.
Its object is `build/scene-battle/Pushboxes-twohundredseventyseventh.obj` and
its disassembly is `Pushboxes-twohundredseventyseventh.txt` beside the other
private scene-battle probes. It is one byte shorter than the target and matches
the complete 708-instruction mnemonic histogram, but it is not byte-exact:
frame `0x150` vs target `0x148`, `this` at `[ebp-0x78]` vs `[ebp-0x60]`, and
four byte stores at `-0x79/-0x7a/-0xe5/-0xe6` vs target 32-bit stores at
`-0x6c/-0x70/-0xdc/-0xe0`. Pose-pointer and output-temporary stack slots also
differ. Probe 276 has the target frame but reuses one volatile Boolean and is
16 bytes short. Probe 259's initial velocity slots (`-0x10/-0x18`) and rectangle
result slots align more closely, but its frame and pointer slots do not, and it
omits the four boundary comparisons.

The `WorkScratch` union in 276/277 shares only `displacement` and `facing`, whose
live ranges do not overlap. This is not the withdrawn 2,898-byte bug where one
union member overwrote a still-live displacement with a boundary Boolean before
both position updates consumed it.

**Next experiment:** start from 277 and try branch-local `volatile int` boundary
locals (not `volatile bool`) to produce the target's 32-bit stores. Recover the
four target stack slots, `this` at `-0x60`, pose pointers at `-0x64/-0x68`, and
the `0x148` frame while retaining the complete instruction histogram. Compare
the entire 2,727-byte function and every relocation binding after each focused
build. Do not infer exactness from byte size or mnemonic counts, and do not
promote any probe into `src/` until a strict complete match exists.

### Other open substantial owners

- Makoto/Character03 still has three substantial open owners: CPU at
  `0x5FB040` / 17,531 bytes, state Slot06 at `0x5E85F0` / 58,482 bytes, and
  effects at `0x5FF4C0` / 33,673 bytes. The state/effects associated tables
  still need review. Ten other Character03 construction/input/command bodies
  are accepted. See `.analysis/probes/makoto/README.md`,
  `state-boundary-review.json` and `state-case-map.csv`.
- Shiori Slot06 at `0x4136D0` remains unaccepted. Its target contribution is
  63,132 bytes including code and both tables; the parked natural-C++ draft is
  63,133 bytes and has a known register divergence. No part of this function is
  accepted. Read `.analysis/probes/shiori-state/README.md` and `parked-best/`
  first; do not overwrite current shared headers from the parked snapshot.
- `PrepareBattle` at `0x76CA50` / 4,029 bytes remains open. Read
  `.analysis/probes/scene-loading/README.md` and parked evidence.
- The battle-scene renderer at `0x7642A0` / 1,285 bytes and pixel owners
  `0x409A90`, `0x40A0B0` and `0x40A440` remain open.

Do not let this list limit exploration: inspect the current ledgers and choose
both high-value owners and useful leaves based on evidence.

## Focused startup and verification

```bash
scripts/repo-python scripts/verify-target.py
scripts/repo-python scripts/verify-toolchain.py --check
# Only if Ghidra analysis is needed:
scripts/repo-python scripts/ghidra.py verify
# Replay only the new/changed unit and actual consumers:
scripts/repo-python scripts/replay-exact-units.py --unit ACTUAL_UNIT_ID
scripts/repo-python scripts/validate-tracking.py --require-target
scripts/repo-python scripts/progress.py
git diff --check
```

Documentation-only changes do not need compiler, Ghidra, cold replay or full CI.
For source changes, compare the complete affected function and recheck actual
consumers of changed shared inputs. Do not run an unrelated full cold cohort.
Never push without explicit permission.

## Storage cleanup and recovery

On 2026-11-08, 1,095 superseded Pushboxes probe/source/disassembly/object/build
files (10,749,392 logical bytes) were archived and SHA-256 verified before the
live copies were removed. Archive:
`.analysis/cleanup/2026-11-08/retired-pushbox-variants.tar.gz`; manifest and
restore commands are in `docs/RE_ARTIFACTS.md` and the archive's `README.md`.
The target dump and selected controls 150, 174, 236, 259, 265–271 and 276–277
remain live. The canonical executable, toolchain, EFZ Wine prefix, Ghidra
project, accepted objects/receipts and unrelated parked evidence were untouched.
