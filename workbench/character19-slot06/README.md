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
- remaining 68 valid state IDs: explicitly marked TODO, not silently routed to the fallback

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

It also emits a context effect at the character's integer-truncated world position. The call to 0x007783B8 is not random-number generation: it is the VC floating-to-integer helper, which corrects the x87 FISTP result toward zero for both signs. The C++ dispatcher uses ordinary int casts for both coordinates, which compile through the same conversion helper, and reuses the common EffectSpawn initialized in the Slot06 prologue. The effect has type 0, owner 0, group 2, layer 1, and the default palette from ResetLocalEffectSpawn.

The effect is emitted through the reconstructed Context::EmitEffect method. The case then advances the animation, applies gravity, and selects the normal/knockdown landing state. This is compiled and semantically validated, not an Exact owner claim.


## Ground recovery family: selector cases 0x29-0x2b

These three states share the same end-of-recovery sequence. Each update applies the 0.8 field0118 decay when enabled, clears dashMomentumFlag, zeros velocityX/velocityY, and advances the animation timer. At the stage edges, the native code also computes outgoingPushbackVelocityX using whether the opponent is airborne (positionY < 0) and the exact 0.25 multiplier; because velocityX has just been zeroed, the resulting pushback remains zero. Cases 0x29 and 0x2a finish in state 7, except inputY==1 selects state 3. Case 0x2b always finishes in state 3. These branches do not apply gravity, request a sound, face the opponent, or use a ground-crossing test. The 346-byte shared helper is compiled as natural C++ and validated against all three native blocks.


## Horizontal ground-skid family: selector cases 0x2c-0x2e

The three native branches (state IDs 75-77) share the same horizontal braking sequence. When field0120 is enabled they decay field0118 by 0.6 each update and apply an additional 30-point decay on the first frame. The first frame adds 30 meter and seeds velocityX=2.2. Every frame then zeros vertical motion, sets gravity to zero, applies 0.06 horizontal deceleration, clamps velocityX at zero, and updates edge pushback using the opponent's vertical position and the native 0.25 multiplier. The timer advances to state 7 (or state 3 when inputY==1) for cases 0x2c/0x2d; case 0x2e always completes into state 3. The three native bodies are identical apart from their local temporary names and final state selection. Slot06UpdateGroundSkid is a shared natural-C++ implementation.


## Airborne recoil and local hit effect: selector case 0x2f

State ID 81 is a 485-byte native branch. On its first frame it emits local effect type 499 at the integer-truncated character position, copies the character facing into the effect flag, sets layer 1, adds 30 meter, and seeds velocity from knockbackVelocityX/knockbackVelocityY with 0.032 gravity. Each frame adds 0.02 horizontal acceleration and gravity to vertical velocity, clamps positive horizontal velocity to zero, and advances the animation timer. At the animation limit it backs the frame index up by one; when the predicted ground crossing occurs on frame 1, it selects state 0x61 or 0x62 according to knockdownOnLanding. Slot06UpdateAirKnockback is a shared natural-C++ helper using the already-reset EffectSpawn and the existing Character19::EmitLocalEffect path.


## Repeated airborne knockback: selector case 0x30

State ID 82 is a 546-byte repeated-launch sequence. It decays field0118 by 0.8 when enabled. Its first frame requests context sound 0x1e, launches with velocity (-0.1, -0.45), increments field3138, and adds 30 meter. At frame 4 it reloads the knockback velocities and 0.032 gravity; positive vertical velocity advances to phase 5. The frame timer loops back to phase 0 while field3138 is below 8, then applies the native frame-count correction. Ground crossing after phase 4 selects state 0x61 or 0x62 based on knockdownOnLanding. Slot06UpdateRepeatedAirKnockback is compiled as natural C++ and cross-checked against Character23's independently recovered state 82.


## Paired airborne rebound/slide: selector cases 0x31-0x32

These two 581-byte native branches are identical after normalizing local temporary names. On the first frame they emit local effect type 0x1f0 once (owner 1, group/layer 0, facing copied into the effect flag), subtract 30 from field0118 when enabled, request context sound 0x21, set velocity to (-0.8,-1.5), and add 30 meter. Vertical velocity gains 0.04 per update. If the initial upward movement immediately crosses the ground plane, the handler clamps position/velocity and advances to phase 1. Otherwise phase 1 adds 0.01 horizontal acceleration; phase 2 seeds -2.0; later phases add 0.06. Positive horizontal velocity is clamped to zero. At animation completion the state returns to 0, resets pose, and faces the opponent. Slot06UpdateAirborneRebound is cross-checked against Character23's matching states 83/84.


## Airborne knockback landing variants: selector cases 0x33-0x34

These branches reuse the one-time local effect type 0x1f0 (owner 1, group/layer 0, facing flag) and the 0x21 context sound. Both seed knockbackVelocityX/knockbackVelocityY and add 30 meter; when field0120 is enabled they subtract 30 from field0118. Case 0x33 applies 0.04 vertical acceleration, then on animation completion returns to state 0 and faces the opponent; the subsequent ground-crossing check selects 0x61/0x62. Case 0x34 gates its first launch on field3138==0, increments that counter, applies 0.06 vertical acceleration, and wraps the animation frame index to zero instead of changing state at frame-count completion. Both preserve the same knockdownOnLanding branch. The shared helper is cross-checked against Character23's matching states 85/86.


## Final transition effects: selector cases 0x35-0x37

Three short but distinct end-state handlers are now restored. Case 0x35 (state 87) emits local effect 0x1ef at fixed coordinates (60,40), with payload and flag set, then advances to state 0 at animation completion. Case 0x36 (state 96) has no effect; it faces the opponent on the penultimate frame and finishes in state 7 or 3 according to inputY. Case 0x37 (state 97) zeros movement, requests vertical shake (3,0), emits context effect type 3 at the integer-truncated character position, requests sound 7, and transitions to state 99 at the end of its animation. The implementation uses the existing local-effect, context-effect and shake methods rather than duplicating their internals.
