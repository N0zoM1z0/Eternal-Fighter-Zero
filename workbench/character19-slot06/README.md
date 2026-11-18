# Character19::Slot06 workbench

Native virtual owner: Character19::Slot06, selected by the Character19 vtable at 0x00788CE0 + 0x18 = 0x00667570.

Reviewed native code extent: [0x00667570, 0x0067596B), 58,363 bytes. Ghidra reports a complete non-thunk body. The native switch data is outside the code owner:
- 118 four-byte case targets at 0x0067596B (472 bytes)
- 310 one-byte state selectors at 0x00675B43 (310 bytes)

The state selector maps 310 animation-state IDs onto 118 shared case handlers. 193 states use the shared fallback handler (selector case 0x75). The generated case-map.csv records each state ID, selector case, native case entry, and native case interval. Regenerate it with scripts/repo-python workbench/character19-slot06/generate_case_map.py.

## Current natural-C++ work

Character19Slot06.cpp is a partial natural-C++ reconstruction of the common prologue and switch dispatch. It has the original hitstop/opponent-hitstun early exits, constructs and resets the local EffectSpawn, snapshots PatternSequence frame timing, and groups the real 310 state IDs according to the recovered selector table.

Currently implemented state coverage:
- selector cases 0-10: state IDs 1-11 except 12, plus state 13
- selector cases 0x70-0x74: state IDs 300, 303, 306, 309, 310, dispatched to isolated C++ handlers
- selector case 0x75: all 193 native fallback state IDs
- remaining 71 valid state IDs: explicitly marked TODO, not silently routed to the fallback

Character19Slot06Cases.cpp contains ten isolated natural-C++ handlers plus two shared airborne-state helpers for selector cases 0x70-0x74. The native intervals and candidate member sizes are:

| Selector | State ID | Native bytes | Candidate bytes |
|---|---:|---:|---:|
| 0x03 | 4 | 905 | 974 |
| 0x04 | 5 | 912 | 992 |
| 0x05 | 6 | 912 | 992 |
| 0x08 | 9 | 767 | 847 |
| 0x09 | 10 | 822 | 891 |
| 0x70 | 300 | 970 | 1,023 |
| 0x71 | 303 | 698 | 759 |
| 0x72 | 306 | 501 | 573 |
| 0x73 | 309 | 2,400 | 2,438 |
| 0x74 | 310 | 177 | 241 |

The candidate members include separate helper prologues/epilogues and local spawn/timing setup; the native function shares those through its common frame. These are semantic workbench results, not Exact claims.

## Airborne movement family: selector cases 0x0b-0x11

The seven 931-byte native branches (state IDs 14-20) share the same 56-line input/recovery state machine and 17-line frame/landing tail. The validator script checks those identical native sections against the target-attested Ghidra decompilation, then validates each branch's launch-frame and velocity/acceleration tuple.

The natural-C++ implementation factors that common behavior into:
- Slot06TryAirAction: 616-byte VC7.1 member, handling up/down/left/right air-action transitions and the original early-return behavior
- Slot06UpdateAirMovement: 420-byte VC7.1 member, handling launch, gravity/fixed-0.01 acceleration, frame advance, and landing

The seven dispatch variants preserve their distinct launch parameters:
- 0x0b: frame 3, (vx=0, vy=-3.5), gravity acceleration
- 0x0c: frame 3, (vx=1.5, vy=-2.5), gravity acceleration
- 0x0d: frame 2, (vx=-1.5, vy=-2.5), gravity acceleration
- 0x0e: frame 3, (vx=2, vy=-0.5), fixed 0.01 acceleration
- 0x0f: frame 3, (vx=1.5, vy=-0.5), gravity acceleration
- 0x10: frame 2, (vx=-2, vy=-0.5), fixed 0.01 acceleration
- 0x11: frame 2, (vx=-1.5, vy=-0.5), gravity acceleration

The two one-byte native writes at Secondary offsets 0x2c8 and 0x2c9 are represented as byte accesses to the final soundSlots[49] storage. This preserves the observed layout without falsely assigning a semantic name to the bytes. This family is compiled and semantically mapped, not yet Exact; the full Slot06 owner remains incomplete. The partial Slot06 object and the helper object both compile with the pinned VC7.1 /Od /G6 /MT /Gy /W3 profile.

The local CharacterViews.h copy adds only non-virtual draft helper declarations; production headers and vtable layout are unchanged. No assembly, padding, or byte patching is used.

Next: translate the remaining selector cases, replace the temporary helper calls with inline case bodies, and compare the complete 58,363-byte owner. Do not promote Slot06 as Exact while any valid state remains a TODO.


## Short hop / landing correction: selector case 0x12

State ID 47 is a standalone 304-byte native branch. The C++ dispatcher now preserves its 0.035 gravity, strict predicted-ground-crossing test, frame-2 clamp, native marker-byte write (Secondary offset 0x2c9 = 7), and the unusual frame-index wrap/decrement sequence. The target-backed validator checks the constant and all of these control-flow operations. This case is compiled as part of the partial Slot06 dispatcher; it is not an Exact owner claim.

## Counter-movement family: selector cases 0x13-0x1b

The nine native branches (state IDs 50-58) share one 43-line body after normalizing only local temporary names and three per-case constants. The target-backed validator checks that equivalence and verifies all 13 numeric constants used by the source.

Slot06UpdateCounterMove is a 502-byte VC7.1 member. It preserves the per-frame field0118 decay, per-case meter gain, opponent combo-scale-dependent horizontal launch, horizontal velocity damping/clamp, stage-edge outgoing pushback calculation, frame progression, and the inputY==1 return to the standing state.

Per-case parameters:
- 0x13: meter +10, launch scale -1.1, field0118 first-frame decay 10
- 0x14: meter +15, launch scale -1.5, decay 20
- 0x15: meter +20, launch scale -1.8, decay 30
- 0x16: meter +10, launch scale -1.1, decay 10
- 0x17: meter +15, launch scale -1.5, decay 20
- 0x18: meter +20, launch scale -1.8, decay 30
- 0x19: meter +10, launch scale -1.1, decay 10; always finish in state 3
- 0x1a: meter +15, launch scale -1.5, decay 20; always finish in state 3
- 0x1b: meter +20, launch scale -1.8, decay 30; always finish in state 3

The first six branches (0x13-0x18) choose state 0 or 3 on completion based on inputY; the last three (0x19-0x1b) always choose state 3. The boundary test is expressed as positionX <= 20 or positionX >= 619, equivalent to the original pair of floating-point comparisons. The source retains the positionY-dependent 0.2 factor when writing outgoingPushbackVelocityX; positionY is reset to zero earlier in the same handler, as in the native sequence. This family is compiled and semantically mapped, not Exact.


## Hit-knockback fall family: selector cases 0x1c-0x1f

The ten native branches (0x1c-0x24 and 0x28) use the same airborne knockback progression. They decay field0118 while its enable byte is set, add 30 meter on the first frame, seed horizontal velocity from knockbackVelocityX, blend vertical velocity as velocityY * 0.75 + knockbackVelocityY, and use 0.032 gravity. The vertical sign selects frame 1 or 2, then the frame timer and predicted ground crossing choose the landing transition. knockdownOnLanding selects state 0x62 or 0x61.

Cases 0x1c-0x1e clamp vertical velocity to [-2,-0.5], [-4,-0.5], and [-6,-0.5], respectively. Case 0x1f deliberately has no vertical clamp. Cases 0x20 and 0x28 take the unblended knockback vertical velocity directly and use gravity 0.032 and 0.072, respectively. Slot06UpdateKnockbackFall is a 664-byte VC7.1 member and keeps blend, gravity, and clamp differences as explicit parameters. Cases 0x21-0x24 also call the recovered opponent-range predicate before continuing: it requires a 280-unit horizontal range and 20-unit stage-edge clearance, otherwise transitioning to state 0x46. The predicate is a separate 226-byte natural-C++ helper. The target-backed validator checks the eight movement constants, all case-specific clamp/blend/gravity modes, and boundary probes for the opponent-range predicate. This family is compiled and semantically mapped, not Exact.


## Follow-up knockback landing: selector cases 0x25-0x26

These two branches restore the final knockback landing phase. Both apply the 1.5 field0118 decay, add 3 meter per update, copy the pending knockback X/Y velocities, advance the frame timer, and choose state 0x62 or 0x61 from knockdownOnLanding when ground is reached. Case 0x25 performs the recovered opponent-range guard after incrementing the tick and switches to state 0x46 when outside the valid range; case 0x26 deliberately omits that guard. Slot06UpdateKnockbackLanding is a 315-byte VC7.1 helper. The target-backed validator confirms the different native extents (316 and 277 bytes) and the guard's ordering.


## Special knockback effect: selector case 0x27

State ID 70 is a 480-byte native branch. On its first frame, guarded by field3138==0, it adds 30 meter, increments field3138, adds 120 air-action-lock frames, sets velocityX=0.5, velocityY=-2.5 and gravity=0.025, and writes marker byte 0x2c9=0x1f.

It also emits a context effect at the character's rounded world position. The call to 0x007783B8 is not random-number generation: the native helper is an x87 double-to-integer conversion using the active nearest-even rounding mode. The C++ dispatcher now uses a small explicit nearest-even helper for both coordinates and reuses the common EffectSpawn initialized in the Slot06 prologue. The effect has type 0, owner 0, group 2, layer 1, and the default palette from ResetLocalEffectSpawn.

The effect is emitted through the reconstructed Context::EmitEffect method. The case then advances the animation, applies gravity, and selects the normal/knockdown landing state. This is compiled and semantically validated, not an Exact owner claim.
