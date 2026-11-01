# Tool identities and execution

## Compiler and Wine

`.tools/msvc710` selects the operator-supplied VC7.1 RTM tree. The source
reference is `archaic-msvc/msvc710`, commit
`2932d76fe417b0bc49010b26d4be2e5b743cc4be`. `config/tools.lock.toml` pins actual
local executable/DLL contents and deterministic name/content tree digests of
VC and Platform SDK headers/libraries. No compiler is vendored.

Compiler/linker banners are 13.10.3077 / 7.10.3077. The initial `/Od /G6 /MD /Gy
/W3` recipe is a reproducible unit profile. It is not a claim that every original
EFZ TU used these settings. `/GS` and `/Zi` did not change the initial reader's
stack mismatch; this does not establish their production selection.

Native builds use `.tools/wine-msvc710`, `WINEARCH=win32`, Xvfb, CPU affinity to
one available CPU and nice 10. An advisory file lock serializes compiler/linker/
resource jobs. Each process has a deadline and retained command, exit code and
log. Ambient `CL`, `LINK` and related variables are removed. Source paths are
converted directly through Wine's default Z drive.

The Wine 9.0 Ubuntu launcher and i386 loader are hash-pinned. This is a selected
execution-surface lock, not an attestation of every system Wine DLL or host
component. The smoke exercises C/C++, Windows SDK headers, CRT linkage,
resources and execution of the newly built smoke binary. It does not launch
the original game.

## Ghidra

`.tools/ghidra` selects Ghidra 12.1.3; `.tools/jdk` selects Temurin
21.0.12.1+1. `config/analysis-tools.lock.json` records the selected analysis
surfaces. `scripts/ghidra.py tools` verifies them without the game input.

`ghidra-project/EFZ` is private. Import performs bounded full default analysis
with `-max-cpu 1`; later queries are read-only with no new auto-analysis.
Each query first verifies imported SHA-256, module name, image base, x86/Windows
language/compiler specification, actual external entrypoint and all initialized
file-backed section bytes. Completion markers are mandatory: an exit code
alone is not evidence of successful script execution.

All custom Java scripts use an EFZ prefix to avoid collisions with installed
Ghidra scripts. Output is bounded, stored below `.analysis/`, and published
only after the corresponding completion marker. Truncation is explicit.
Full memory-byte attestation does not validate inferred function boundaries.

The initial default analysis logs include warnings about reads at `0x03020100`
while decompiling some large functions. The import completed; those warnings
are retained and automatic results remain provisional. Do not treat the
candidate inventory as an exhaustive reviewed function census.

## Python and public CI

`scripts/repo-python` enforces CPython 3.13.5. The initial workflow uses no pip
dependencies. `scripts/ci.py` checks syntax, declarations, ledger consistency,
generated progress, focused oracle tests and whitespace without private tools
or game assets. Diagnostic experiments must not silently become dependencies.
