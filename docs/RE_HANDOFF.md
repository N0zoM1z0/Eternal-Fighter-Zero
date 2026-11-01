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
| `context-activate` | `0x406AA0` | 775 |
| `context-load-object` | `0x406DB0` | 173 |
| `context-load-patterns` | `0x406E60` | 668 |
| `video-load-bitmap` | `0x408D00` | 905 |
| `video-decode-packed` | `0x409470` | 711 |
| `surface-make-rect` | `0x40C590` | 69 |
| `pattern-construct` | `0x408310` | 24 |
| `pattern-destruct` | `0x408270` | 43 |
| `pattern-allocate` | `0x4082D0` | 56 |
| `config-read-byte` | `0x405A20` | 180 |
| `config-write-byte` | `0x405AE0` | 254 |

Total authored exact code is **6,934 bytes** in fifteen complete functions.
Additional 44-byte scalar-deleting helpers at `0x4018F0` and `0x401920` have
strict zero-difference proofs, but are classified compiler-generated and excluded
from authored match totals. Three additional generated array helpers have
189 compared bytes, also excluded. Candidate inventory remains 950 non-external entries.

## Latest surface transfer checkpoint

`src/Surface.cpp` closes the complete raw loader (905 bytes), packed decoder
(711 bytes) and rectangle factory (69 bytes). All three pass strict complete
comparison. Engine.h now includes the observed DirectDraw pointer at 0x20808
and historical SDK types; the complete Video object extent is still open.

The raw path retains byte-wise low-16-bit BMP fields, signed modulo correction
blocks, rounded allocation/return width, reversed rows and original early-return
cleanup behavior. Packed decoding preserves uncompressed reversed rows versus
forward RLE rows, persistent repeat/current-pixel state, exact cursor updates,
byte palette truncation, and the unused Unlock HRESULT assignment. The rectangle
factory is cdecl returning a four-integer value, not a member constructor.

First complete comparisons were early (902/905 and 708/711). Normal scope/
aggregate choices and exact branch/store recovery produced full zero-difference
bodies. These source declarations are not claimed as unique original source.
Public proof is `docs/evidence/surface-exact.json`; original disassembly and
named bindings remain private under `.analysis/`. Shared-header revalidation
used four cold source/profile artifacts reused across their selected functions;
configuration units were not rebuilt. Five generated helpers remain excluded
from authored totals. Thirteen focused oracle self-tests and metadata CI pass.

## Latest effect activation checkpoint

`src/Activation.cpp` recovers complete activation at `0x406AA0` (775 bytes)
and object-file loading at `0x406DB0` (173 bytes). Both are strict exact.
Activation retains the packed path, the inactive raw-BMP branch omitted by
Ghidra, two hidden 16-byte structure return temporaries, and the original
compiler-generated cookie/check. A dedicated `/MT /GS` profile records that
setting without changing existing source profiles.

The first complete activation build was 820 bytes. Natural state/buffer scopes
and the chosen 100-byte source error buffer resolved the length and stack
layout differences. The helper initially matched size but still had eight
stack differences; those were corrected before acceptance. Read full original
disassembly rather than adopting the decompile's buffer-size guesses.

The shared Video API declarations are now explicit in Engine.h. Revalidation
used one cold artifact per source/profile recipe, reusing its unchanged COFF
bytes for other selected functions: three translation-unit builds checked the
new bodies and 13 dependent bodies. Final source cleanup rebuilt only activation.
Configuration units were not replayed. Public proof is
`docs/evidence/activation-exact.json`, with refreshed dependent certificates.
Private optimized replay recipe/logs are retained under `.analysis/probes/`
and `.analysis/exact/`; the public standard explicit replay remains reproducible.

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

1. Recover packed/raw palette loaders at `0x40B760` (316-byte candidate) and
   `0x40B640` (284-byte candidate), plus final surface-property access. Review
   the full data path against actual file resources; do not infer palette
   semantics solely from names.
2. Continue into a substantial rendering owner alongside useful leaves, after
   examining native boundaries and COM/data dependencies. The surface code is
   recovered, but device initialization and rendering closure are still open.
3. Close the external tail subobject lifetime `0x405E60`/`0x405F80`, context
   InitializeState/ResetState `0x408100`/`0x406440`, and pattern reader/decoder.
4. Review timing thread `0x401850` and plan larger character-dispatch owners
   from full control flow; keep pursuing representative owners and useful leaves.

Production TU partitioning, complete linked global data/resources, remaining
callee closure, runnable product, original/reconstructed runtime comparison
and portability remain open. The original game has not been executed.
