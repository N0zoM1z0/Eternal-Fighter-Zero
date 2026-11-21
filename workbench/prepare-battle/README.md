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

The selected `SceneLoading.cpp` form sets backgroundScale to 1.0 first, then
overrides it to 0.125 for stage 16. A second, separately retained natural-C++
form is `SceneLoading-ifelse.cpp`; it uses the target's condition-first
if/else scale assignment. Its focused driver is:

    scripts/repo-python workbench/prepare-battle/compare_prepare_battle_ifelse.py

This alternate compiles to a **4,031-byte owner** (3,895 code bytes), exactly
two bytes larger than native. All 115 relocations are materialized and both
switch tables/selector are exact. It contains one explicit candidate-only
`mov ecx, edx` at candidate offset `0xE33` / target VA `0x0076D883`. For
structural diagnosis only, the verifier removes exactly that two-byte
instruction, rebases local branch/table targets, and then measures **48 byte
differences in 48 runs** across the native 3,893-byte code range. The move is
still a real mismatch; this normalization is not Exact and the alternate is
not accepted. The prior note's 45-byte diagnostic count was superseded by the
corrected relocation/local-target rebasing audit (48 bytes).

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

Two additional syntax/type hypotheses were tested on 2026-11-16 and rejected
by a complete scoped rebuild: (1) forward-declaring `BattleBackground`, typing
`Context::blob` as `BattleBackground *`, and assigning each derived `new`
expression without a cast; (2) spelling the first virtual call as
`secondarySlotA[0]->LoadResources()` rather than `(*secondarySlotA)->LoadResources()`.
Both retained the 4,029-byte owner, all 115 relocations and the same 87-byte /
37-run code mismatch. The original opaque `unsigned char *` field and call
syntax are restored. Do not repeat these no-effect forms.

## Focused source-level scale lowering sweep, 2026-11-17

Nine additional source-level formulations of the stage-16 scale selection were
compiled with pinned VC7.1, always as a *complete* `Scene2::PrepareBattle`
owner with 115 COFF relocations. Plain/reversed `if/else` and explicit braces
all yielded 4,031 bytes; `?:` versions yielded 4,036; a `switch` yielded
4,042; a two-independent-if form yielded 4,047; a pair of local doubles
yielded 4,090. None met the complete 4,029-byte original owner boundary.
The current 4,029-byte default-first candidate is unchanged and still differs
in 87 code bytes / 37 runs; do not grant Exact credit for these variants.
Experiment receipt: ignored `.analysis/prepare-scale-hypotheses.json`.

## Focused compiler-register experiments, 2026-11-21

The strict-extent default-first source and the condition-first if/else source
were both rebuilt again from the current pinned compiler. The default-first
receipt remains 4,029/4,029 bytes with 87 code mismatches in 37 runs. The
if/else alternative remains 4,031 bytes (+2); its diagnostic-only deletion of
the candidate `mov ecx, edx` at 0x0076D883 and local-target rebasing still
leaves 48 code mismatches in 48 runs. The 48-byte figure is not a strict
comparison or Exact certificate.

The native constructor argument register pairs for the four cases are
(ECX,EDX), (EAX,ECX), (EDX,EAX), (ECX,EDX); the selected default-first
candidate emits (EDX,EAX), (ECX,EDX), (EAX,ECX), (EDX,EAX). The allocation
pointers, constructor call destinations, null paths, result temporaries and
Context137C stores otherwise line up. The first LoadResources call also
retains a register shuffle; the second call sequence is exact. This narrows the
remaining constructor work to the `videoOwner` argument's scratch-register
selection rather than missing behavior or object layout.

Additional complete-owner experiments were rejected:

- Typing Context::blob as `BattleBackground *` or `void *` and assigning the
  derived `new` expressions directly retained the 4,029-byte / 87-run result.
- Explicit `this->videoOwner` retained the same result.
- A per-case `Video *backgroundVideo` local expanded the owner to 4,094 bytes.
- On the if/else candidate, `secondarySlotA[0]->LoadResources()` retained the
  same 4,031-byte extent and the same extra receiver instruction.
- A ternary scale assignment expanded the owner to 4,036 bytes; inverted
  predicate and explicit goto scale forms expanded it to 4,031 and 4,033 bytes.

All variants were compiled as isolated normal COFF owners with the same locked
VC7.1 profile; no variant changed the selected tracked source. The updated
relocation-bound receipts are in
`docs/evidence/prepare-battle-natural-cpp-progress-v2.json` and
`docs/evidence/prepare-battle-ifelse-natural-progress.json`.
