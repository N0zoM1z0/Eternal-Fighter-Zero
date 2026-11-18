# Character19::Slot06 workbench

Native virtual owner: Character19::Slot06, selected by the Character19 vtable at 0x00788CE0 + 0x18 = 0x00667570.

Reviewed native code extent: [0x00667570, 0x0067596B), 58,363 bytes. Ghidra reports a complete non-thunk body. The native switch data is outside the code owner:
- 118 four-byte case targets at 0x0067596B (472 bytes)
- 310 one-byte state selectors at 0x00675B43 (310 bytes)

The state selector maps 310 animation-state IDs onto 118 shared case handlers. 193 states use the shared fallback handler (selector case 0x75). The generated case-map.csv records each state ID, selector case, native case entry, and native case interval. Regenerate it with scripts/repo-python workbench/character19-slot06/generate_case_map.py.

## Current natural-C++ work

Character19Slot06.cpp is a partial natural-C++ reconstruction of the common prologue and switch dispatch. It has the original hitstop/opponent-hitstun early exits, constructs and resets the local EffectSpawn, snapshots PatternSequence frame timing, and groups the real 310 state IDs according to the recovered selector table.

Currently implemented state coverage:
- selector cases 0, 1, 2: state IDs 1, 2, 3
- selector cases 0x70-0x74: state IDs 300, 303, 306, 309, 310, dispatched to isolated C++ handlers
- selector case 0x75: all 193 native fallback state IDs
- remaining 109 valid state IDs: explicitly marked TODO, not silently routed to the fallback

Character19Slot06Cases.cpp contains five isolated natural-C++ handlers for selector cases 0x70-0x74. The native intervals and candidate member sizes are:

| Selector | State ID | Native bytes | Candidate bytes |
|---|---:|---:|---:|
| 0x70 | 300 | 970 | 1,023 |
| 0x71 | 303 | 698 | 759 |
| 0x72 | 306 | 501 | 573 |
| 0x73 | 309 | 2,400 | 2,438 |
| 0x74 | 310 | 177 | 241 |

The candidate members include separate helper prologues/epilogues and local spawn/timing setup; the native function shares those through its common frame. These are semantic workbench results, not Exact claims. The partial Slot06 object and the helper object both compile with the pinned VC7.1 /Od /G6 /MT /Gy /W3 profile.

The local CharacterViews.h copy adds only non-virtual draft helper declarations; production headers and vtable layout are unchanged. No assembly, padding, or byte patching is used.

Next: translate the remaining selector cases, replace the temporary helper calls with inline case bodies, and compare the complete 58,363-byte owner. Do not promote Slot06 as Exact while any valid state remains a TODO.
