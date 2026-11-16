# Scene2::PrepareBattle — unaccepted natural-C++ workbench

This directory contains a complete, isolated C++ candidate for
Scene2::PrepareBattle, the resource/background/replay preparation owner at
0x0076CA50. Its local SceneLoading.cpp, Engine.h, Input.h and Backgrounds.h
preserve the provisional compilation context. They are not accepted src/
headers; do not copy these views into production source wholesale.
The candidate is not linked and is not codegen Exact. It contains no inline
assembly, emitted opcodes or target-byte patches.

## Canonical target extent

The canonical resources/EFZ.exe owner is exactly 4,029 bytes:

- 3,893 code bytes: [0x0076CA50, 0x0076D985)
- 100-byte switch table: [0x0076D985, 0x0076D9E9), 25 destinations
- 20-byte switch table: [0x0076D9E9, 0x0076D9FD), five destinations
- 16-byte selector: [0x0076D9FD, 0x0076DA0D)

The complete owner SHA-256 is
1b529588799198f4fd6d913e877c029fe53e129cccb391a928cea0a1dae03d99.
Three CC bytes align the following loading keyboard owner at 0x0076DA10.
The boundary/origin review is separately recorded in
docs/evidence/prepare-battle-boundary-review.json; it does not establish
source or codegen Exact.

## Rebuild and compare

Run the scoped comparison driver:

    scripts/repo-python workbench/prepare-battle/compare_prepare_battle.py

It compiles only this owner twice: the tracked default-first candidate and a
historical if/else comparison form. It resolves all 115 candidate COFF
relocations, compares all 3,893 code bytes and all 136 table/selector bytes,
and refreshes docs/evidence/prepare-battle-natural-cpp-progress-v2.json.
It does not run the all-unit cold replay. The two comparison objects are
retained under ignored build/scene-loading/; transient logs are under
.analysis/build/.

## Current candidate status

The tracked candidate compiles to the exact 4,029-byte owner extent:
3,893 code bytes plus 136 table/selector bytes. It has 115 relocations
(82 external, 33 local; 85 in code and 30 in the tables). After materializing
all relocations, both tables and the selector match the canonical target.

The code is not Exact: 87 bytes differ across 37 runs, with the first
differing byte at 0x0076D744 (the first constructor setup starts at
0x0076D743). The four constructor branches use the correct constructor
targets and stack temporaries, but the scratch-register assignment rotates
relative to native. At the first LoadResources dispatch, the candidate emits
mov ecx, edx at 0x0076D881 where native emits mov eax, [eax]; the indirect
call remains at 0x0076D883. The second dispatch instruction sequence matches.

The selected source form sets backgroundScale to 1.0 first, then overrides
it to 0.125 for stage 16. The older condition-first if/else form emits a
4,031-byte owner. Removing its extra two-byte receiver move for diagnostic
alignment still leaves 45 differing code bytes; that alignment is not an
accepted comparison and the larger candidate is not retained.

## Completed dependencies

- The four direct background constructors are strict-exact:
  1,561/1,561 bytes, 44 relocations, zero differences.
  Evidence: docs/evidence/prepare-battle-background-constructors-exact.json.
- The four-stage constructor/destructor/update/render family is byte-exact
  after relocation binding: 16 functions, 7,687/7,687 bytes, 123 relocations.
  Fifteen units use strict replay; Background16::Update has a separately
  reviewed local-label-name normalization.
  Evidence: docs/evidence/prepare-battle-background-family-exact.json.

## Next work

1. Run the comparison driver and inspect the 37 remaining ranges in the v2
   evidence file.
2. Compare native and candidate disassembly around 0x0076D743–0x0076D882.
3. Form a falsifiable natural-C++ hypothesis for the constructor register
   rotation or first virtual-call receiver. Rebuild only this owner.
4. Keep the full 4,029-byte extent and resolve all 115 relocations after every
   source change. Compare every code byte and both tables; do not infer Exact
   from size, selected instructions or table equality.

Prior experiments with base qualification, pointer/reference aliases,
const/volatile member qualifiers, local lifetime changes, register hints,
placement new, alternate case order, scale spellings and compiler flags did
not improve the relocation-bound result. Do not repeat them without new
evidence. Do not add assembly, _emit, byte patches, inert padding or arbitrary
normalization. Preserve accepted src/ files and avoid a full all-unit replay.
