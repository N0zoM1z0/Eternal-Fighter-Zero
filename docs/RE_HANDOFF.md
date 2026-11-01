# Current handoff — 2026-11-01

## Active checkpoint

The full EFZ reconstruction goal remains active. Work on substantial owners and
small functions, recheck hypotheses against original evidence, handle dirty work,
and commit substantive progress with `gpt-6.1-sol: `. Use Bash/local Ghidra only.

The canonical target remains SHA-256
`3a1616d6c76d2eea08a95bb198d853e96cb6b9b3266e277ca1d167426dd66481`.
Upstream release/modification provenance remains open. The public repository is
`N0zoM1z0/Eternal-Fighter-Zero`; initial publication was authorized, but ordinary
later checkpoints are local unless the operator requests a push.

| Authored exact unit | Address | Bytes |
| --- | --- | ---: |
| `startup-main` | `0x401000` | 1,638 |
| `startup-window-procedure` | `0x401670` | 468 |
| `context-construct` | `0x406070` | 493 |
| `context-destruct` | `0x406260` | 477 |
| `context-load-patterns` | `0x406E60` | 668 |
| `pattern-construct` | `0x408310` | 24 |
| `pattern-destruct` | `0x408270` | 43 |
| `pattern-allocate` | `0x4082D0` | 56 |
| `config-read-byte` | `0x405A20` | 180 |
| `config-write-byte` | `0x405AE0` | 254 |

Total authored exact code is **4,301 bytes** in ten complete functions.
Additional 44-byte scalar-deleting helpers at `0x4018F0` and `0x401920` have
strict zero-difference proofs, but are classified compiler-generated and excluded
from authored match totals. Three additional generated array helpers have
189 compared bytes, also excluded. Candidate inventory remains 950 non-external entries.

## Verified context and pattern result

`src/Context.cpp` now closes the 493-byte context constructor, 477-byte
context destructor and 668-byte pattern loader. Three pattern members add
24-byte construction, 43-byte destruction and 56-byte allocation bodies.
Shared layout definitions moved from Startup.cpp into `src/Engine.h`; this
header is an explicit dependency of both groups' exact recipes.

Constructor/member cleanup at offset 0x14284, 920 COM-style interface slots,
65 audio IDs, optional blob and counted pattern-array lifetime are represented
by natural C++. The pattern loader preserves all integer-decoder calls,
original field order, unused type read/store and ten 16-byte reads per frame.
The source does not silently initialize the original uninitialized count byte.

The previous Ghidra ATL/Concurrency names were re-evaluated against pattern
allocation/loader consumers and compiler-generated array cleanup. Three array
helpers (106, 48 and 35 bytes) have separate generated-origin proofs, not
extra authored credit. Source names and unknown data regions stay provisional.

The first whole loader comparison had 63 stack-offset differences; explicit
natural parsing lifetimes resolved them. Startup's four involved units were
replayed after the shared-header extraction. The configuration source includes
neither changed file and was not rebuilt. Public proofs are
`docs/evidence/context-exact.json` and refreshed `docs/evidence/startup-exact.json`.

## Earlier startup result

The complete 1,638-byte startup and 468-byte callback retain the unreachable
scene-zeroing branch omitted by decompilation. Destruction uses
`timeEndPeriod(1)` and `PostQuitMessage(1000)` per independent PE IAT inspection.
The original `/MT` startup profile remains local to those codegen recipes;
configuration's verified `/MD` recipe was not globally changed.

## Resume

```bash
git status --short --branch
scripts/repo-python scripts/verify-target.py
scripts/repo-python scripts/verify-toolchain.py --check
scripts/repo-python scripts/report-reconstruction-status.py
scripts/repo-python scripts/ghidra.py verify
```

Select only changed/involved units for subsequent native work. For startup edits:

```bash
scripts/repo-python scripts/replay-exact-units.py \
  --unit startup-main --unit startup-window-procedure \
  --unit startup-context-delete --unit startup-secondary-delete
scripts/repo-python scripts/ci.py
```

Current exact reports depend on complete source/selected recipe identities, not
the current hash of the entire manifest. Adding unrelated units does not require
replaying historical units. Documentation-only work needs no native rebuild.

## Next evidence-driven owners

1. Attack context activation `0x406AA0` (775-byte candidate). Its decompile
   removes multiple unreachable branches and injects the stack-cookie check;
   recover the full original disassembly before writing complete source.
2. Close the newly exposed external member lifetime at `0x405E60`/`0x405F80`,
   context InitializeState/ResetState at `0x408100`/`0x406440`, and the
   12-byte pattern reader's constructor/destructor and integer decoder.
3. Review the 157-byte timing thread at `0x401850` to connect frame events to
   the recovered main loop. Continue both representative owners and useful leaves.
4. Plan larger character dispatch owners from actual control-flow evidence;
   automatic 60–88 KB bodies and decompiler warnings require careful review.

Production TU partitioning, complete linked global data/resources, remaining
callee closure, runnable product, original/reconstructed runtime comparison
and portability remain open. The original game has not been executed.
