# PrepareBattle reconstruction frontier

## Current best natural-C++ candidate

Source: `SceneLoading.cpp`; target: `Scene2::PrepareBattle` at `0x0076D050` (owner extent from the function ledger). The current scoped comparison reports **4029 owner bytes**, **3893 code bytes**, **{'total': 115, 'external': 82, 'local': 33, 'code': 85, 'tables': 30, 'all_candidate_relocations_resolved': True} relocations**, **87 differing code bytes** across **37 mismatch runs**; first differing VA: `0x76d744`. These are local comparison metrics, not an acceptance receipt.

The source remains ordinary C++: `new BackgroundXX(videoOwner)`, virtual `LoadResources()` calls, a selector `switch`, and explicit scale selection. No assembly stubs, padding, or byte-level substitution are used.

## Semantic recovery

The background selector values are 1, 10, 12, and 16, selecting `Background01`, `Background10`, `Background12`, and `Background16`. Background 16 uses scale `0.125f`; the other three use `1.0f`. The context payload stores the selected background instance and is later consumed as a `BattleBackground` object.

## Code-generation experiments

- The default-first scale expression preserves the 4,029-byte owner extent but leaves 87 differing bytes in the current comparison.
- The explicit `if/else` scale variant reduces the normalized mismatch count to 48 bytes, but its owner is 4,031 bytes: a two-byte receiver move remains at the first `Secondary::LoadResources` dispatch, so it is not an exact boundary match.
- Introducing a local `Secondary*` receiver changes stack allocation and is rejected.
- Calling through an object-reference expression (`(**secondarySlotA).LoadResources()`) does not improve the virtual-call sequence.
- Viewing the context payload as `void*` and assigning the newly allocated background directly does not change the receiver-register sequence.
- Materializing the selector into the existing `choice` local before the `switch` preserves the function extent but does not change the constructor receiver-register cycle.

## Remaining boss work

The main unresolved region is the register allocation around the four `new BackgroundXX(videoOwner)` branches and the first virtual receiver load. The next iteration should focus on the original member/temporary types and expression tree while preserving the established stack frame, owner extent, and relocation map. Do not treat a smaller raw mismatch count with an oversized owner as exact.
