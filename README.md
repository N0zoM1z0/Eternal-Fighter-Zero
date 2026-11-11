# Eternal Fighter Zero -Memorial-

Agent workflow: follow the highest-priority requirements in [AGENTS.md](AGENTS.md). Use affected exact checks and searchable Markdown knowledge; ordinary notes do not require full CI or replay.

<p align="center">
  <img
    src="resources/title-card.svg"
    width="640"
    alt="Eternal Fighter Zero -Memorial- source reconstruction">
</p>

<p align="center">
  <img src="resources/progress.svg" alt="EFZ reconstruction progress">
</p>

Source reconstruction of the executable supplied in the Memorial archive.
Exactness is established by reproducible complete-function comparisons.
[TH105](https://github.com/N0zoM1z0/th105)
is an engine-family research reference; its VC8 compiler and recovered layouts
are not EFZ evidence.

This is a partial reconstruction, not a runnable replacement game.
See [progress](docs/PROGRESS.md) and the [current handoff](docs/RE_HANDOFF.md).

## Exact target

| Property | Locked value |
| --- | --- |
| Canonical private input | `resources/EFZ.exe` |
| Size | 3,743,744 bytes |
| SHA-256 | `3a1616d6c76d2eea08a95bb198d853e96cb6b9b3266e277ca1d167426dd66481` |
| MD5 | `9ac51d746d2ad288de8fe705e5b119c4` |
| Image base / entry | `0x00400000` / `0x00778A4A` |
| PE timestamp | 2005-11-25 04:56:47 UTC |
| Linker header | 7.10 |

Both archive members `EFZ.exe` and `EFZ/EFZ.exe` have this identity. `EFZ.OLD`
is different and is rejected. Archive labels and bundled readmes mix version
descriptions and modifications; official release provenance remains open. The
input is identified by its bytes, rather than an unverified version label.
See [target evidence](docs/KNOWLEDGE_BASE.md#target-identity).

## Current status

The [generated progress report](docs/PROGRESS.md) and card above derive current
counts from the reviewed ledgers. Each ledgered exact claim has a complete
strict comparison with explicit relocation bindings at its last recorded replay.
Compiler-generated helpers and standard-library wrappers are recorded separately
and excluded from authored progress. Automatic Ghidra candidates are not an
authored-code denominator.

Historical exact certificates can have stale source or header hashes. Daily CI
checks ledger structure; current exactness comes from rebuilding and comparing
the affected units. Optional certificate audits use
`validate-tracking.py --check-proofs --unit NAME`. See the
[workflow](docs/RE_WORKFLOW.md).

Accepted sources cover configuration, file reading, DirectInput, Audio,
Context, title/selection/loading scenes, substantial shared character code,
battle simulation/collision/display/keyboard/replay controls and four concrete
background owners. Seven characters have exact constructors and substantial
child bodies: Shiori, Mizuka, Misuzu, Mishio, Misaki, Mayu and Makoto.
Kaori (383 bytes), MizukaB (396 bytes), Kanna (403 bytes),
NayukiB (472 bytes), Kano (523 bytes), Akiko (511 bytes), Minagi
(469 bytes), EX Nanase (452 bytes), Sayuri (419 bytes) and Ikumi
(647 bytes, including two 505-element vector allocations), Mio
(407 bytes, including two x87 double fields), Nayuki (455 bytes)
and Nagamori (517 bytes, including byte flags plus three 64-int banks)
also have independently exact natural constructors. Ikumi's separate
257-byte `SetAlternateMode`, 949-byte second pattern-bank parser and
60-byte resource wrapper now have independent strict Exact receipts.
Ikumi's 163-byte derived destructor is also strict Exact, including the
original double base teardown and two vector-array deletes.
Other child owners, including Ikumi Slot08 effects, remain open.
Ikumi's independent 5,153-byte `Slot02` command recognizer is strict
Exact in `src/Character14Commands.cpp`; Nagamori's 12,277-byte
`Slot04` action selection and 4,917-byte `Slot02` input recognizer
are also fully Exact in `src/Character06Input.cpp` and
`src/Character06Commands.cpp`. Their historical partial workbench
probes are not the current source of truth. Shiori's 63,132-byte
`Slot06`, Nayuki's 62,693-byte state `Slot06`,
`Scene2::PrepareBattle` and Ikumi `Slot08` remain substantive
unfinished owners. See [handoff](docs/RE_HANDOFF.md) for exact
candidate paths, measurements and targeted next steps.

Reader/audio integration is complete; accepted code lives in `src/`.

Recent completed **large** owners include Nayuki Slot07
(20,517 code bytes plus 212 switch-data bytes), Nayuki Slot05
(13,259 bytes), Nayuki Slot04 (10,605 bytes), Makoto `Slot06`
(59,292 bytes including tables), Nagamori `Slot04` (12,277 bytes) and
`Slot02` (4,917 bytes), and Ikumi `Slot02` (5,153 bytes); each has a
complete target-bound exact receipt in `docs/evidence/`. The
`Scene3::ResolvePushboxes` local owner is also ledgered Exact for
2,727 bytes. More functions, linked data and runtime semantics are
still open. For current next actions and blockers, use the concise
[receiving-agent handoff](docs/RE_HANDOFF.md), not historical session
summaries. Nayuki Slot06 currently has a selected 29,139-byte native
prefix, but remains NOT Exact; 19 live case labels 263–281 are missing.

The last recorded compiler, linker, resource and native execution smoke checks
passed. The original
translation-unit graph, linked data/resources, full executable and runtime
comparison remain open. No whole-game completion percentage is claimed.

## Setup

Use CPython 3.13.5. The control plane, oracle and CI use the standard library.
The proprietary compiler, game files and analysis tools are not distributed.

```bash
uv venv --python 3.13.5 .venv
scripts/repo-python scripts/import-target.py /path/to/EFZ.exe
scripts/bootstrap-tools.sh \
  --msvc /path/to/msvc710 \
  --ghidra /path/to/ghidra_12.1.3_PUBLIC \
  --jdk /path/to/jdk-21.0.12.1+1
scripts/repo-python scripts/verify-target.py
scripts/repo-python scripts/verify-toolchain.py --execute
scripts/repo-python scripts/ci.py
```

The selected VC7.1 RTM compiler is **13.10.3077**, linker **7.10.3077**. This
matches the dominant Rich build records; it does not establish all original
compiler flags. Component, header and library identities are pinned separately.
Native jobs use a repository-owned win32 Wine prefix, Xvfb, one CPU, nice 10,
timeouts and retained exit logs. [Tool details](docs/TOOLS.md).

## Reconstruction loop

```bash
scripts/repo-python scripts/ghidra.py import
scripts/repo-python scripts/ghidra.py inventory
scripts/repo-python scripts/ghidra.py decompile 0x405A20
scripts/repo-python scripts/ghidra.py disasm 0x405A20
scripts/repo-python scripts/replay-exact-units.py \
  --unit config-read-byte --unit config-write-byte
scripts/repo-python scripts/validate-tracking.py --require-target
```

Import once; use `verify` for an existing project. Subsequent analysis queries
are read-only and do not rerun auto-analysis. The local wrapper checks the
imported target identity and all file-backed PE section bytes before queries.
Analysis and pseudocode remain provisional. Use Bash and this local Ghidra
workflow directly; REA is not part of this repository's workflow.

The exact oracle compares complete COFF function extents after replaying every
explicitly bound DIR32/REL32 field. It does not mask addresses or accept matching
prefixes. Normal COFF is supported initially; LTCG and linked EH/data closure
are open. [Oracle contract](docs/ORACLES.md), [workflow](docs/RE_WORKFLOW.md).

## Required phase order

1. Review EFZ boundaries/origins and recover complete exact VC7.1 authored units.
2. Close and exercise the faithful Windows i386 product, including data owners,
   initializers, resources, libraries and runtime scenarios.
3. Compare runtime semantics with two independent Oracles: the original target
   and the reconstructed native i386 product.
4. Begin portability after establishing a trustworthy native semantic baseline.

## Project map

| Path | Purpose |
| --- | --- |
| `config/` | target/tool locks, build recipes and independent progress ledgers |
| `src/` | handwritten natural C/C++ reconstruction |
| `workbench/` | active unfinished candidates and one required isolated header |
| `probes/` | compiler/linker/resource smoke inputs |
| `scripts/` | verification, Ghidra, build, exact comparison and reporting |
| `docs/` | handoff, durable findings, workflow and comparison evidence |
| `resources/` | ignored read-only original executable |
| `.tools/` | ignored tool links and isolated Wine state |
| `.analysis/` | disposable logs, analysis exports and comparison reports |
| `_reference/` | ignored extraction of the supplied archive |
| `build/`, `ghidra-project/` | ignored products and local database |

## License

Repository-authored code and documentation are provided under the
[MIT License](LICENSE). This does not grant rights to the original game,
its assets or proprietary tools.
