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
- **First committed candidate (`0300bec`):** 4,260 bytes, the original
  `0x98` frame and 39 COFF relocations. Its first 122 position-aligned bytes
  matched after excluding the *three real COFF relocation operands*, not as
  an acceptance claim.
- **Subsequent source experiments:** reordered the zero-mode winner path and
  tested direct `delete` lifetimes and signed player-index semantics. These can
  change the compiled size and stack frame; consult the live script output for
  the current measurements rather than treating the original 636-byte deficit
  as permanently fixed.
- The old first difference `0x0077155A` was an internal long-jump displacement
  to a later branch whose absolute location remains under reconstruction.

This is meaningful source coverage but **not codegen Exact**, does not add to
`config/matches.csv`, and carries no factory acceptance credit. Continue by
recovering the precise lifetime of the scene-exit pointer temporary and the
remaining original conditional branch/sound dispatch shapes. The accepted
3,151-byte `Scene9::PrepareResults` callee is developed separately under
`src/` and is not counted again here.
