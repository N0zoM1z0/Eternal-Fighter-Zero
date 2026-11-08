# Current handoff — 2026-11-07

> Current workflow: follow the **Highest priority** section in `AGENTS.md`.
> Prefer affected exact comparisons and useful Markdown knowledge. Ordinary
> notes do not require full CI, native replay or document-hash/pin refreshes.
> Older broad validation instructions apply only when their impact is relevant.


## Operator state

The operator cleared the reconstruction goal and requested cleanup and handoff
on 2026-11-07. **No autonomous reconstruction task is active.** The in-flight
Makoto local-effect verification was completed before this handoff; no further
owner was started. Leads below are possibilities for a newly authorized task.

Work in this repository. Start with `git status --short --branch`, the diff,
AGENTS.md, this file and the selected source/ledger rows. Preserve unrelated work.
Local checkpoints have not been pushed. Never push without an explicit instruction.
Repository: https://github.com/N0zoM1z0/Eternal-Fighter-Zero.
Use Bash and local `scripts/ghidra.py`; no REA, Factory prerequisites or subagents.
Code/comments/docs/metadata stay English. Commit prefix: `gpt-6.1-sol: `.

## Accepted baseline

| Fact | Current result |
| --- | ---: |
| Authored complete exact functions | 327 |
| Authored exact instruction bytes | 1,000,184 |
| Associated exact local-table bytes | 6,845 |
| Reviewed boundaries / origins | 362 / 362 |
| Per-unit proof recipes | 345 |
| Compiler-generated auxiliary helpers | 14 functions / 579 bytes |
| Standard-library auxiliary wrappers | 4 functions / 90 bytes |
| Automatic non-external candidates | 950 |

[PROGRESS.md](PROGRESS.md) is generated from live ledgers. Acceptance authority:
config/matches.csv, docs/evidence/ and config/match-units.toml. Auxiliary helpers
are excluded from authored totals; automatic candidates are not a denominator.
A runnable product, linked data/resources, original TU partitioning, runtime
comparison and portability remain independently open.

Accepted sources include reader/Audio/Input/Context, title/selection/loading,
substantial shared Secondary code, battle controls/collision/display, four
concrete background owners and seven character constructors with substantial
child bodies: Shiori, Mizuka, Misuzu, Mishio, Misaki, Mayu and Makoto. This is
partial game reconstruction. Historical facts/checkpoints remain in
[KNOWLEDGE_BASE.md](KNOWLEDGE_BASE.md); older totals and next-work statements
are historical, not today's task queue.

## Latest exact checkpoints

- Mayu state: `d6cd8d9`, Character05::Slot06 at 0x5C8580,87,209 code + 954 table bytes,
  total 88,163;2,059 reviewed relocation fields. All 13 actual Mayu virtual
  destinations have exact proofs. Source:src/Character05State.cpp;
  proof:docs/evidence/mayu-state-exact.json; private:.analysis/probes/mayu-state/.
- Makoto construction/input/commands: `72df266`, ten bodies/17,018 code bytes.
  ID 3 allocates 0x3450,uses canonical "makoto"788AC0 and table788AC8. Character03
  alone gained five scalar ints,three64-int arrays and retained opaque bytes
  344C..344F. Final89-unit comparison used 41 cold artifacts:ten new and 79 actual
  CharacterViews.h consumers. Other 254 units retained prior proofs. All 1,074
  generated symbol renames and 1,069 local offsets were independently checked.
  Proof:docs/evidence/makoto-exact.json; private:.analysis/probes/makoto/.
- Makoto CPU: `3e6619d`, Slot05 at 0x5FB040,17,531 code bytes,no tables;329 reviewed
  fields. Preserve120 AX zero extensions/two direct AL stores,actual expression
  order and contradictory far-distance>800&&<80 guard. Proof:
  docs/evidence/makoto-cpu-exact.json; private:.analysis/probes/makoto-cpu/.
- Final Makoto effects: Slot07 at 0x5FF4C0,33,673 code + 224 table bytes,total 33,897,
  exclusive end607929. All 308 fields are reviewed:73 calls,202 doubles,33 local
  bindings. Complete31-address/100-selector switch covers30 explicit types and
  70 defaults. Source:src/Character03Effects.cpp;
  proof:docs/evidence/makoto-effects-exact.json;
  private:.analysis/probes/makoto-effects/README.md. Preserve vertical-before-
  horizontal wall-bounce exits,word updates,removal exits and CRT sample order.

The last two owners each passed their own final selected cold replay after
formatting. Their public headers and previous recipes/sources are unchanged;
no old/full cohort was replayed. Current single-unit reports are live under
.analysis/exact/character-03-*.json. Latest header replay:
.analysis/exact/makoto-and-affected.json. Native logs:
.analysis/build/makoto-formal-replay.log,makoto-cpu-formal-replay.log and
makoto-effects-formal-replay.log. Focused target-required tracking,
ledgers/progress CI and whitespace checks pass. No full CI or runtime matrix ran.

## Retained work and optional leads

- Makoto has 12/13 actual virtual destinations exact. State5E85F0 is the
  authored Character03::Slot06 owner. Its complete target boundary is now
  reviewed:58,482 code +500 jump-table +310 selector-map bytes =59,292 bytes;
  124 animation IDs have explicit cases and186 map to the default. Four CC
  bytes precede the next constructor at5F6D90. The vtable slot6 operand788AE0
  points to5E85F0. Fresh evidence and the complete animation-to-case map are in
  .analysis/probes/makoto/state-boundary-review.json and state-case-map.csv.
  Source reconstruction, relocation ownership and exact code generation remain
  open. The 0x7783B8 leaf is the compiler-generated x87-to-integer helper (178
  calls in Slot06); source should use natural conversions, not call it. The
  Ghidra warning about03020100 remains provisional.
- Shiori Slot06 at4136D0 is unaccepted. Read
  .analysis/probes/shiori-state/README.md and parked-best/ first. Complete target:
  63,132 bytes =62,273 code + 540 addresses + 319 selectors,end422D6C. Best complete
  draft:63,133 bytes; this is an extent delta,not one remaining different byte.
  First divergence41FC1E in animation303. Repeated scope/increment/signedness
  controls were neutral. Private headers predate accepted changes and must not
  overwrite src/. All parked drafts and attempts remain live.
- PrepareBattle76CA50 is unaccepted:4,029 complete bytes =3,893 code+136 tables,
  end76DA0D. Read .analysis/probes/scene-loading/README.md and parked-best/.
  Best4,031-byte draft is not a two-byte-difference claim. The real-background
  control in .analysis/probes/loading-owner/README.md was neutral. Do not repeat
  pointer/type/case controls without a new falsifiable target prediction.
- Pushbox766B50/2727 remains open. The fresh audit identifies four write-only
  x87 comparisons: first fighter X `<=160` before and `>160` after the first
  correction; second fighter X `>=479` before and `<479` after the opposite
  correction. Raw assembly also reverses all four CollisionSide signs relative
  to provisional Ghidra: first branch fighter 0 `-1`, fighter 1 `+1`; opposite
  branch fighter 0 `+1`, fighter 1 `-1`. See KNOWLEDGE_BASE.md and the full
  .analysis/probes/scene-battle/pushbox-target.txt. The transform helper's
  caller ABI uses an explicit output buffer and returns its pointer in EAX;
  aggregate-return assignment introduces extra copies. Best corrected-sign C++
  candidate is 3447/2727 bytes with 37 relocation sites, not accepted. Keep
  exploring local lifetimes and VC7.1 codegen; no padding, masks, assembly, or
  byte wrappers. Pixel owners 409A90/40A0B0/40A440 remain open.
- Reader/audio integration is complete. `workbench/reader-audio/` preserves
  historical drafts and an already-integrated patch; it is not unfinished work.
  Read its README; never apply the old patch or copy drafts over accepted src/.

Do not run private make/refine/prepare/publish scripts over accepted source.
They are one-time derivation records and may contain superseded draft controls.
A successful unit does not close character resources, production TU structure,
runtime or the game.

## Storage cleanup and recovery

The 2026-11-07 cleanup losslessly archived 1,246 older trial/build/report files
before removing redundant live copies. Every file was checked by size and
SHA-256. Archive:
.analysis/cleanup/2026-11-07/retired-trials-and-reports.tar.gz;
manifest.json beside it records original paths and hashes. About 94.4 MiB of
allocated file storage was reclaimed after archive/manifest accounting.

Forty latest successful source/object snapshot roots,current accepted objects /
receipts,all current per-unit reports,the latest Makoto affected report,all native
logs and all parked Shiori/PrepareBattle evidence remain live. Original target,
RAR,toolchain links/installations,EFZ Wine prefix and Ghidra database are retained.
See [RE_ARTIFACTS.md](RE_ARTIFACTS.md) before following an older aggregate-report
or trial path; restore only the needed member. No original bytes or generated
analysis text were added to Git.

## Verification for a newly authorized task

Canonical ignored,read-only input:resources/EFZ.exe,3,743,744 bytes,SHA-256
`3a1616d6c76d2eea08a95bb198d853e96cb6b9b3266e277ca1d167426dd66481`.
Release/modification provenance remains open. Do not substitute EFZ.OLD,netplay
binaries or another release.

```bash
scripts/repo-python scripts/verify-target.py
scripts/repo-python scripts/verify-toolchain.py --check
# Only when Ghidra analysis is needed:
scripts/repo-python scripts/ghidra.py verify
# Replay only the new/changed/header-dependent units actually selected:
scripts/repo-python scripts/replay-exact-units.py --unit ACTUAL_UNIT_ID
scripts/repo-python scripts/validate-tracking.py --require-target
scripts/repo-python scripts/progress.py
scripts/repo-python scripts/ci.py --only ledgers
scripts/repo-python scripts/ci.py --only progress
git diff --check
```

Pinned VC7.1 RTM13.10.3077; EFZ's own Wine prefix; serial CPU1,nice10,bounded
native commands with retained exits. Run --execute only for setup/tool changes
or compiler/Wine failures. All observed draft source failures were corrected and
followed by successful required smoke checks. No compiler/Wine issue remains.
All Ghidra/headless jobs are terminal; annotations were read-only and unsaved.
Custom large-function decompiles used a verified 128 MiB response limit.
