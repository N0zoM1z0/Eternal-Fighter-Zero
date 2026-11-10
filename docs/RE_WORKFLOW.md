# Reconstruction workflow

> Current workflow: follow the **Highest priority** section in `AGENTS.md`.
> Prefer affected exact comparisons and useful Markdown knowledge. Ordinary
> notes do not require full CI, native replay or document-hash/pin refreshes.


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
Change one supported hypothesis at a time. Keep useful logs under `.analysis/`.
Retain the current unfinished candidate and any unusual build context needed
to reproduce it. Record useful failed approaches briefly; delete obsolete
attempts and generated output when they no longer help.

## Record a checkpoint

Update source presence only when a complete reviewed function is represented.
Update exact matches only after a cold zero-difference report. Keep target,
source and manifest identities in the ledger and durable compact evidence.

```bash
scripts/repo-python scripts/validate-tracking.py --require-target
scripts/repo-python scripts/progress.py
scripts/repo-python scripts/ci.py --only ledgers --only progress
git diff --check
```

Default CI is a fast, target-free basic check. Ledger validation checks structure
and recorded target identity; it does not audit historical source/header hashes.
Use `validate-tracking.py --check-proofs --unit NAME` for that optional audit.
Current exactness requires the selected native comparison above.
Use only the relevant CI selectors for ordinary checkpoints. Add syntax or
focused oracle checks when the corresponding infrastructure changes; do not
run a full CI/cold cohort as a routine function-acceptance prerequisite.
Do not count candidate sizes or source files as global reconstruction progress.

## Later phases

Close the Windows i386 product graph only after sufficient exact ownership is
established: original TU boundaries, global data, static initialization,
libraries, linker settings, resources and assets must all be addressed. Then
compare original and reconstructed runtime behavior. Portability follows a
trustworthy native semantic baseline.
