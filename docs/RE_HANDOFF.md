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
| `config-read-byte` | `0x405A20` | 180 |
| `config-write-byte` | `0x405AE0` | 254 |

Total authored exact code is **2,540 bytes** in four complete functions.
Additional 44-byte scalar-deleting helpers at `0x4018F0` and `0x401920` have
strict zero-difference proofs, but are classified compiler-generated and excluded
from authored match totals. Candidate inventory remains 950 non-external entries.

## Verified startup result

`src/Startup.cpp` covers full window/device initialization, eight scene
allocations in nine slots, message/frame dispatch and window-destruction cleanup.
The original unreachable scene-zeroing block is preserved; Ghidra pseudocode
omitted it. Independent IAT inspection corrected a misleading literal-only
reading: destruction calls `timeEndPeriod(1)` and `PostQuitMessage(1000)`.

Startup uses its own `/MT` profile because original CRT calls are direct.
Do not transplant that profile globally: prior configuration units retain their
verified `/MD` recipe. The first whole startup build was compared early and the
remaining 33 local stack-displacement differences were resolved with natural
MSG/WNDCLASS/HWND scope and names. No byte arrays for code, padding or fake ABI
were used. Class names and opaque storage types remain provisional.

Selected cold replay passed all four new units: 2,194 compared bytes and 198
relocations, with zero differences. Public proof: `docs/evidence/startup-exact.json`.
The unchanged configuration cohort was not rebuilt. Public progress counts only
the two new authored owners (2,106 bytes), not the compiler-generated helpers.

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

1. Close context lifetime/data ownership from constructor `0x406070` (493-byte
   candidate) and destructor `0x406260` (477-byte candidate). Their implementations
   remain original external bindings despite exact startup callers.
2. Attack context activation `0x406AA0` (775-byte candidate) and load
   `0x406E60` (668-byte candidate), alongside useful small owners. Review actual
   boundaries/types and compare the first complete source early.
3. Review the 157-byte timing thread at `0x401850` to connect frame events to
   the recovered main loop; review `0x405BE0` file helper when its owner is selected.
4. Plan larger character dispatch owners from actual control-flow evidence;
   automatic 60–88 KB bodies and decompiler warnings require careful review.

Production TU partitioning, linked global data/resources, callee closure,
runnable product, original/reconstructed runtime comparison and portability
remain open. The original game has not been executed by this workflow.
