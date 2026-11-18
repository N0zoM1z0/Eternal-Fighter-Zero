# Character19::Slot06 workbench

Native virtual owner: Character19::Slot06, selected by the Character19 vtable at 0x00788CE0 + 0x18 = 0x00667570.

Reviewed native code extent: [0x00667570, 0x0067596B), 58,363 bytes. Ghidra reports a complete non-thunk body. The native switch tables are outside that code extent:
- 118 four-byte case targets at 0x0067596B (472 bytes)
- 310 one-byte state selectors at 0x00675B43 (310 bytes)

The state selector maps 310 animation-state IDs onto 118 case handlers. 193 states use the shared fallback handler (case 0x75). The generated case-map.csv records each selector state, native case entry, and native case interval. Regenerate it from the pinned target with scripts/repo-python workbench/character19-slot06/generate_case_map.py.

## First natural-C++ subunit: case 0x73

Case 0x73 handles state ID 309 and occupies native interval [0x00674F5A, 0x006758BA), 2,400 bytes. It contains the Kanna multi-hit finisher: staged hitstop and hitstun, meter/tint changes, two context effects, a sequence of local effects, opponent position/hitstop/KO-delay changes, camera shake/offset, gravity/velocity transitions, and the final reset/face-opponent transitions.

Character19Slot06Case73.cpp is an isolated natural-C++ translation of that case. It compiles with the pinned VC7.1 /Od /G6 /MT /Gy /W3 profile to a 2,438-byte COFF member with 53 relocations. The helper is intentionally not wired into the production vtable owner yet: the native function constructs and resets one shared EffectSpawn in its common prologue, while this isolated handler currently owns its own local spawn. Inline it into the complete Slot06 reconstruction when the surrounding state handlers are restored. This is a semantic workbench artifact, not an Exact claim.

The local CharacterViews.h copy adds only the non-virtual draft method declaration required to compile the isolated handler; it does not modify production headers or vtable layout.

Next: reconstruct the adjacent cases and the common prologue/epilogue in natural C++, then inline the staged handler and compare the selected Slot06 owner. Do not use ASM, padding, or byte patching.

The isolated candidate is 38 bytes larger than the native case interval. That comparison includes its own helper prologue, EffectSpawn construction/reset, and epilogue; the production owner will share those pieces through Slot06's common frame. It is not a byte-match certificate.
