# EFZ reconstruction — receiving-agent handoff (2026-11-10)

**Start here:** [AGENTS.md](../AGENTS.md) defines the working agreement;
[PROGRESS.md](PROGRESS.md) is generated from the accepted ledgers;
[KNOWLEDGE_BASE.md](KNOWLEDGE_BASE.md) preserves prior investigations.
The former 680-line historical handoff is available through Git history
(`git log -- docs/RE_HANDOFF.md`); it is not a current task list.

## Repository and nonnegotiable constraints

- Repository ID: `efz`. Work in the existing `main` worktree. **Inspect
  dirty and untracked files and continue them**; the operator reports no
  concurrent writer. Commit meaningful progress as `gpt-web: ...`, several
  commits per substantive session. Never push unless explicitly requested.
- **Canonical target:** ignored `resources/EFZ.exe`, 3,743,744 bytes,
  SHA-256 `3a1616d6c76d2eea08a95bb198d853e96cb6b9b3266e277ca1d167426dd66481`.
  Other archive executables are not interchangeable.
- **Toolchain:** pinned VC7.1 13.10.3077, `vc71-od-static`, isolated
  EFZ Wine prefix. Use `scripts/repo-python`; compile/compare only the
  affected units and real consumers. **Do not run a full cold replay.**
- **Preserve** the canonical executable, source, accepted exact receipts,
  original analysis, Ghidra project, compiler and Wine prefix. Archived
  historical experiments have precise restore instructions in
  [RE_ARTIFACTS.md](RE_ARTIFACTS.md).

## Ground truth at this handoff

`config/implemented.csv`, `config/matches.csv` and the generated
[PROGRESS.md](PROGRESS.md) currently report **363 exact functions,
1,093,926 exact code bytes and 7,655 associated exact local-table
bytes**; 395 reviewed complete boundaries and 390 reviewed origins out
of 950 Ghidra candidate functions. These are **ledger counts**, not a
whole executable, a runtime-equivalence claim, or a fresh replay of every
historical certificate. The last clean checkpoint before this handoff
was `91318b6` on local `main`, 118 commits ahead of `origin/main`;
**check `git status`/`git log` rather than trusting that snapshot.**

Historical public receipts include stale shared-header dependency hashes.
`scripts/repo-python scripts/validate-tracking.py --require-target`
was known to fail for this reason; the old claim of *296* stale receipts
is **not** a current count. Rebuild and refresh only actually affected
selected units when changing their inputs. Never forge a proof by editing
hashes. Ordinary Markdown cleanup requires no compiler replay.

## Accepted substantial owners — do not mistakenly reopen

| Owner | Full matched extent | Selected unit / source | Proof |
| --- | ---: | --- | --- |
| Makoto `Character03::Slot06` `0x005E85F0` | **59,292 bytes**, including 500-byte jump table and 310-byte selector, 1,386 relocations | `character-03-state-slot06` / `src/Character03State.cpp` | [Full Exact](evidence/makoto-state-slot06-exact.json) |
| Nagamori `Character06::Slot04` `0x004AE2E0` | **12,277 bytes**, 100 relocations, 3,092 instructions | `character-06-slot04` / `src/Character06Input.cpp` | [Full Exact](evidence/nagamori-slot04-exact.json) |
| Nagamori `Character06::Slot02` `0x004B1780` | **4,917 bytes**, 15 input scans, 2 relocations | `character-06-slot02` / `src/Character06Commands.cpp` | [Full Exact](evidence/nagamori-slot02-exact.json) |
| Ikumi `Character14::Slot02` `0x006AB7E0` | **5,153 bytes**, 15 input scans, zero relocations | `character-14-slot02` / `src/Character14Commands.cpp` | [Full Exact](evidence/ikumi-slot02-exact.json) |
| `Scene3::ResolvePushboxes` `0x00766B50` | **2,727 bytes**, 35 relocations | `scene-battle-resolve-pushboxes` / `src/SceneBattlePushboxes.cpp` | [Full local Exact](evidence/scene-pushboxes-exact.json) |

Nagamori's `Character06::MarkEffectCollision` at `0x004AE1D0` is also
**231/231 exact bytes** with two original `fabs` relocations, in
`src/Character06Collision.cpp`. Its selected unit
`character-06-effect-proximity` deliberately compiles against the
**isolated, same-size class declaration** in
`workbench/nagamori-helper/CharacterViews.h`; this proves that owner,
not full-program header integration. See
[its certificate](evidence/nagamori-effect-proximity-exact.json).
Other exact constructors, scene owners, battle helpers and effects are
listed in the source and match ledgers; the older handoff's long list of
completed tasks is no longer repeated here.

## Active unfinished work — actual next steps

### 1. Nagamori `Character06::Slot05` CPU AI (large boss)

- Canonical full owner: `[0x004B2AC0,0x004B667C)`, **15,292 bytes**.
  Vtable slot 5 at `0x00788410`; four trailing `CC` bytes are padding.
- Natural C++ **partial** source:
  `workbench/nagamori-cpu/Character06Cpu.cpp`; run
  `scripts/repo-python workbench/nagamori-cpu/check_prefix.py`.
- The first **2,861 original bytes / 784 instruction positions** are
  represented: 783 forms match after only numeric jump/call/literal
  normalization. The one prologue difference is `sub esp,0xE8` in the
  complete target versus `sub esp,0x94` in the partial TU; later locals
  are genuinely absent. The temporary return is not the original exit.
- Recovered CPU behaviors: original 3x chance, 60–120 forward input,
  0x0C/0x48/random 0x14-or-0x16, meter 0x65/0x66, and 160/220 distance
  tiers. **Next original decision at `0x004B35F2`**. Derive it from
  Nagamori bytes, not the sibling character's CPU code. An older,
  unaccepted full sibling hypothesis is privately parked at
  `.analysis/probes/nagamori-slot05-sibling-candidate.cpp`.

### 2. Shiori `Character08::Slot06` large animation-state boss

- Original `0x004136D0`, **63,132 total bytes**: 62,273 code + 540
  switch table + 319 selector bytes. Full original boundary proof:
  [Shiori boundary](evidence/shiori-state-boundary-review.json).
- Complete **non-Exact** C++ candidate:
  `workbench/shiori-state/ShioriState.cpp` and private header views.
  Native output is **63,133 bytes**, not the 63,132-byte target.
  Focused diagnostic:
  `scripts/repo-python workbench/shiori-state/audit_case_codegen.py --rebuild`.
  Known register-width differences include 307, 308, 315; prior source
  experiments are hypotheses, not guaranteed correct. Do not replace
  accepted `src/` headers with the provisional Shiori views.

### 3. `Scene2::PrepareBattle`

- Original `0x0076CA50`, **4,029 bytes total** (3,893 code + 100/20
  switch-table bytes + 16 selector bytes). [Boundary and tables](evidence/prepare-battle-boundary-review.json).
- Complete **non-Exact** natural candidate in `workbench/prepare-battle/`;
  it compiles to **4,031 bytes**, 115 relocation sites. Compare the
  background-allocation register lifetime around `0x0076D743` and the
  later virtual load call. Both switch tables and selector must match.

### 4. Ikumi `Character14::Slot08` effects

- Original `0x006AB060`, **1,592 bytes**, verified as virtual slot 8
  (not slot 7). The partial `workbench/ikumi-effects/Character14Effects.cpp`
  generates **1,537 bytes** and 33 relocations. Its five hit-effect
  branches lack an x87 opponent-X load before each CRT `rand()`;
  naive `volatile`, comma and multiplication changes did **not** prove
  correct original codegen. Continue from the original five opcode
  deletion sites without faking instructions. [Boundary](evidence/ikumi-slot08-boundary-review.json).

Other open substantial owners include Nagamori `Slot07` and Video
pixel kernels. Choose a useful leaf when it unblocks a caller, but
keep prioritizing complete boss functions.

## Short, targeted commands

```bash
git status --short --branch
git log -5 --oneline
scripts/repo-python scripts/verify-target.py
scripts/repo-python scripts/progress.py --check
# For a complete selected owner ONLY:
scripts/repo-python scripts/build-match-unit.py --unit character-06-slot02
scripts/repo-python scripts/compare-coff-function.py --unit character-06-slot02
# For an unfinished owner use its workbench checker instead.
```

Use the actual selected unit ID instead of running the entire native
cohort. Do not treat success of the progress or ledger commands as a
new byte-level proof. If a historical private probe is absent, consult
[RE_ARTIFACTS.md](RE_ARTIFACTS.md) and restore just that archived member.
