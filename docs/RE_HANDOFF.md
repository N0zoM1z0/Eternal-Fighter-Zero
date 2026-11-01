# Current handoff — 2026-11-01

## Checkpoint

Initial EFZ repository prepared using the TH10 organization. Use Bash and the
local Ghidra wrapper directly; the operator explicitly requested no REA.

The canonical supplied target, its complete PE mapping, VC7.1 RTM toolchain,
isolated Wine execution, strict COFF oracle and private Ghidra project are in
place. Exact target identity is in `config/target.toml`; upstream release
provenance is still open. Do not substitute a presumed clean release silently.

Local Ghidra 12.1.3 imported/analyzed the target and passed independent input,
entrypoint and all four file-backed section hash checks. Its inventory has
950 non-external candidates, kept separate from reviewed boundaries/origins.

`src/Config.cpp` recovers two complete authored functions:

| Unit | Address | Exact bytes |
| --- | --- | ---: |
| `config-read-byte` | `0x405A20` | 180 |
| `config-write-byte` | `0x405AE0` | 254 |

Cold replay has zero differences across 434 bytes and all 20 relocation fields.
The public report is `docs/evidence/config-exact.json`; exact/source/origin/
boundary ledgers are independent. The original TU and source names are unknown.
The three string bindings and allocator/deallocator destinations remain original
external bindings, not a closed reconstructed product graph.

## Resume commands

```bash
git status --short --branch
scripts/repo-python scripts/verify-target.py
scripts/repo-python scripts/verify-toolchain.py --check
scripts/repo-python scripts/report-reconstruction-status.py
scripts/repo-python scripts/ghidra.py verify
scripts/repo-python scripts/replay-exact-units.py \
  --unit config-read-byte --unit config-write-byte
scripts/repo-python scripts/ci.py
```

For a documentation-only pass, the target/tool/Ghidra commands are unnecessary.
The compiler execution smoke already passed C/C++, Windows headers, resources,
linking, CRT and execution of its own binary. Repeat it only on setup/toolchain
changes or a compiler/Wine failure.

## Next work

1. Review the adjacent `0x405BE0` 268-byte object/file helper. Its stack cookie,
   object field ownership and string/CRT bindings require their own manifest.
2. Review a representative larger owner to test whether the `/Od` candidate
   profile extends beyond these configuration leaves. Keep the first complete
   comparison early and record unknown production settings honestly.
3. Establish original game/CRT/library boundaries and subsystem ownership from
   EFZ evidence. Use TH105 only for concrete engine-family hypotheses.
4. Corroborate the supplied executable's upstream release/modification status
   without changing the canonical input. Any alternate target needs a separate
   comparison scope.

LTCG/linked EH/data lanes, production linking, runnable reconstructed game,
runtime dual-oracle comparison and portability remain open. No original-game
execution has been claimed. See `RE_ARTIFACTS.md` for private recovery paths.
