# Scene9::Step — 4,896-byte results transition boss (provisional)

`Scene9::Step` is the native virtual at `0x007714E0`. Its full reviewed body
is **4,896 bytes**, not a fixed-length prologue or padding. This workbench
contains a 260-line, natural VC7.1 C++ candidate recovering the round-result
transition logic. The standalone `Engine.h`/`Input.h` are provisional
layout views and deliberately do **not** replace the accepted headers under
`src/` while this function remains unmatched.

The source implements startup resource preparation and fade-in, cleanup of
character/background/replay resources on exit, winner-dependent scoring and
next-match selection, winning character frame updates and sound playback,
result-screen choices, and UI animation/easing. The observed results-scene
fields through offset `0x470` are represented as ordinary typed C++ members.
There is no inline assembler, emitted opcode, fake branch padding, or target
byte patching.

## Reproduce only this owner

Run `scripts/repo-python workbench/scene9-step/check_step.py` from repo root.
It compiles only this translation unit with the pinned `/Od /G6 /MT /Gy /GS /W3`
profile and compares against canonical `EFZ.exe`. Current measurements:

- **Native owner:** 4,896 bytes, initial `0x98` stack frame.
- **Candidate:** 4,260 bytes, same `0x98` frame, 39 COFF relocations.
- **First 122 position-aligned bytes:** agree when their *three actual COFF
  operands* are independently ignored for this diagnostic, not acceptance.
- **Unresolved deficit:** 636 bytes. The first differing position
  `0x0077155A` is an internal jump displacement to a later branch that has
  not yet achieved identical native layout.

This is meaningful source coverage but **not codegen Exact**, does not add to
`config/matches.csv`, and carries no factory acceptance credit. Continue by
recovering the precise lifetime of the scene-exit pointer temporary and the
remaining original conditional branch/sound dispatch shapes. The accepted
3,151-byte `Scene9::PrepareResults` callee is developed separately under
`src/` and is not counted again here.
