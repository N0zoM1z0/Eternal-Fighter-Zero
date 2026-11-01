# Reconstruction workflow

## Recover and select

Read `AGENTS.md`, the current handoff, Git changes and the selected source rows.
Verify the target. Run `verify-toolchain.py --check` when doing native work;
run the execution smoke on setup/tool changes or failures.

Use `ghidra.py import` once to initialize the private EFZ project. Later commands
attest the input and mapped sections and use `-readOnly -noanalysis`:

```bash
scripts/repo-python scripts/ghidra.py verify
scripts/repo-python scripts/ghidra.py inventory
scripts/repo-python scripts/ghidra.py function 0x405A20
scripts/repo-python scripts/ghidra.py decompile 0x405A20
scripts/repo-python scripts/ghidra.py disasm 0x405A20
scripts/repo-python scripts/ghidra.py callers 0x405A20
scripts/repo-python scripts/ghidra.py xrefs 0x787378
```

An inventory remains a set of automatic candidates. Review ranges, internal
control flow, callers, returns and padding before adding a complete boundary
row. Review origin separately before adding authored exact progress. Never
turn auto-detected library/thunk names into source ownership without evidence.

## Recover a complete unit

Write a natural C/C++ body and compare it early. Record a recipe under
`config/match-units.toml` with source, profile, complete extent and exhaustive
reviewed relocation bindings. Consult `config/build.toml` for candidate flags;
do not infer all production settings from a small exact seed.

```bash
scripts/repo-python scripts/build-match-unit.py --unit config-read-byte
scripts/repo-python scripts/compare-coff-function.py --unit config-read-byte
scripts/repo-python scripts/replay-exact-units.py --unit config-read-byte
```

Classify a mismatch by complete extent, code, local branch, ABI or bound address.
Change one supported hypothesis at a time. Keep useful logs under `.analysis/`;
remove superseded probe sources after retaining the relevant result.

## Record a checkpoint

Update source presence only when a complete reviewed function is represented.
Update exact matches only after a cold zero-difference report. Keep target,
source and manifest identities in the ledger and durable compact evidence.

```bash
scripts/repo-python scripts/validate-tracking.py --require-target
scripts/repo-python scripts/progress.py
scripts/repo-python scripts/ci.py
git diff --check
```

Default CI is target-free. Its metadata checks do not run the original game,
Ghidra or proprietary compiler. Native comparison is a distinct selected action.
Do not count candidate sizes or source files as global reconstruction progress.

## Later phases

Close the Windows i386 product graph only after sufficient exact ownership is
established: original TU boundaries, global data, static initialization,
libraries, linker settings, resources and assets must all be addressed. Then
compare original and reconstructed runtime behavior. Portability follows a
trustworthy native semantic baseline.
