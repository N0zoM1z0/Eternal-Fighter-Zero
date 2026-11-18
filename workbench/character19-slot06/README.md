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


## Defeat wait: selector case 0x39

State ID 99 is a short defeat-wait handler. If health remains positive after the native strict 60-frame timeout while frame index is zero, it transitions to state 0x60, resets pose, and clears dashMomentumFlag. Independently, it advances the animation timer, faces the opponent exactly when the frame index reaches frameCount, and transitions to state 0x60 again once the animation completes. The target uses 60 here (not the 100-frame threshold found in another character's analogous state), which is retained explicitly.


## Horizontal recovery variants: selector cases 0x3a-0x3f

These six native branches share the same braking and stage-edge pushback body. On their first frame they clear dashMomentumFlag, add 10/15/20/10/15/20 meter, seed velocityX to -1.5/-1.8/-2.3/-1.5/-1.8/-2.3, and zero vertical position/velocity. Every update adds 0.06 horizontal acceleration, clamps positive velocity to zero, and copies the resulting velocity into outgoingPushbackVelocityX only at the stage edges. At the frame-count boundary they call the native facing helper (reconstructed by FaceOpponent), then finish in state 0 or state 3 according to inputY. Variants 0x3d-0x3f always select state 3. The shared Slot06UpdateHorizontalRecovery helper preserves each variant's meter gain, launch speed, and forced-standing flag.


## Knockback effect follow-ups: selector cases 0x42-0x43

Case 0x42 (state 162) is a knockback-fall variant guarded by field313c. Its first frame applies the 0.8 field0118 decay, adds 30 meter, seeds knockback velocity with 0.032 gravity, requests sound 0x1f, increments field313c, and emits local effect 0x1f0 (owner 1, group/layer 0, facing flag). It then uses the common airborne phase and landing logic. Case 0x43 (state 163) instead gates the launch on field3144, applies the 30-point field0118 decay, requests sound 0x21, adds 30 meter, and uses 0.04 vertical acceleration without emitting a local effect. Animation completion returns to state 0 and faces the opponent; ground crossing selects 0x61/0x62. Both are implemented as natural C++ helpers with separate one-shot guards.


## Field3144-gated knockback: selector cases 0x43-0x45

These three airborne knockback variants share the same one-shot launch guard. On the first frame while field3144 is zero they apply the 30-point field0118 decay when enabled, request sound 0x21, copy knockbackVelocityX/knockbackVelocityY, add 30 meter, and increment field3144. Case 0x43 uses direct 0.04 vertical acceleration, 0x44 uses direct 0.06, and 0x45 stores 0.032 in gravity and accumulates through that member. Each returns to state 0 and faces the opponent at animation completion; ground crossing selects 0x61/0x62. The shared helper keeps direct-acceleration and stored-gravity semantics distinct.


## Airborne knockdown and impact variants: selector cases 0x40-0x42

The three native branches share a landing transition but differ in launch setup. Case 0x40 seeds horizontal/vertical velocity (-1.2,-2.6), adds 15 meter, and stores 0.06 gravity on the first frame; gravity is then applied immediately on that same update. Cases 0x41/0x42 use horizontal velocities +1.0/-1.0, initial vertical velocity -2.3 and 0.045 gravity; they clear dashMomentumFlag every update and emit a context-owned type-8 impact effect at the integer-truncated character position (group 2, layer 0) on the first frame. The latter two defer gravity integration until the following update. All three advance to state 9 when the animation completes; ground crossing clamps positionY, requests context sound 9, faces the opponent, and transitions to state 0x0d. The shared natural-C++ helper preserves the distinct first-frame integration rules and uses Context::EmitEffect for the type-8 event.


## Trail-assisted airborne bounce: selector cases 0x43-0x44

Both branches initialize the trail and reset the motion frame, then launch at a later animation phase and clear pendingCharacterSoundSlot. Case 0x43 starts trail spacing 3 at phase 3 with velocity (2.0,-1.0) and gravity 0.02. While airborne it integrates gravity; after phase 6 it brakes horizontal velocity by 0.04, loops phase 7 back to 5, and finishes in state 0. A ground crossing instead clamps Y/vertical velocity and jumps to phase 7. Case 0x44 starts trail spacing 2 at phase 2 with velocity (-2.0,-1.0) and gravity 0.035. It holds its final animation frame until ground crossing, then resets pose and motion and enters state 0x0d. The native helper FUN_004109d0 maps to StartTrail; FUN_0040f1e0 maps exactly to ResetFrame.


## Long airborne follow-up/counter state machine: selector cases 0x45-0x46

These 932/931-byte native branches are almost identical; their only structural differences are the launch phase (3 versus 2), initial horizontal velocity (+2.0 versus -2.0), and the matching start phase for gravity integration. Each update increments field3140 and, once it passes field3148, routes directional input into states 9, 14-20 according to inputY, inputX versus facing, field015c, and airActionCount. Those transitions preserve the native attackCollisionResult reset and ResetPose ordering. If no follow-up input consumes the state, the launch phase seeds velocityY=-0.5, gravity=0.045, clears pendingCharacterSoundSlot, and starts horizontal movement. From the launch phase onward vertical velocity gains 0.01 each update. Animation completion selects state 10; ground crossing after phase 3 clamps Y, requests context sound 9, faces the opponent, and selects state 0x0d. The shared Slot06UpdateAirborneFollowup helper preserves both phase variants without duplicating the large input/state-routing block.


## Paired type-8 knockback impact finishers: selector cases 0x48-0x49

Both 330-byte native branches clear dash momentum and reset motion, Y position and guard-input frames, then emit context effect type 8 at the integer-truncated character position (group 2, layer 1). They advance the animation timer, face the opponent on the exact frame-count boundary, and finish in state 0 (0x48) or state 3 (0x49). The shared helper uses ResetFrame for the native motion-field clearing and Context::EmitEffect for the impact flash.


## Airborne hitstun velocity restore: selector case 0x4a

The 457-byte state 170 stores the incoming horizontal and vertical velocities as 100x integer components in field3138/field313c, then freezes both velocities. It defaults gravity to 0.035 only when gravity was zero, clears guard-input frames and outgoing pushback, and starts 60 frames of hitstun. Once hitstun reaches zero, field3140 gates a one-time restoration of the stored velocities at 0.01 scale; gravity is then integrated each update. A strict ground crossing (positionY + velocityY > 0) resets motion, clamps Y, and enters state 0xa9. Otherwise the animation timer continues and finishes in state 9. This handler intentionally does not clear dashMomentumFlag.

## Defeat impact with velocity restore: selector case 0x4b

The 584-byte state 171 stores the incoming velocities in field3138/field313c at 100x scale and freezes them. When field0120 is set, it adds field0118 * 5.0 to comboDamageScale, then clears field0118, starts 90 frames of hitstun, and applies tint 0xb0 for 3 frames. At animation frame 1 it requests context sound 0x12 and emits context effect type 1; at frame 2 it emits type 4. Both effects use integer-truncated character coordinates, group 2, layer 1. Every completed animation frame clears attackCollisionResult. At animation completion it enters state 9, restores field3138/field313c at 0.01 scale, sets gravity 0.035, then resets pose. The implementation uses the correct native velocity fields rather than adjacent Character19 extension fields.


## Horizontal dash recovery: selector case 0x4c

The 312-byte state 178 reduces velocityX by 0.03 each update and clamps it to zero; dashMomentumFlag is cleared only when the strict negative-velocity test fires. While the animation has advanced beyond frame zero, down input can cancel into states 4, 5, or 6 according to inputX versus facing, but only while field015c is below 3. That cancel clears attackCollisionResult and resets pose. Otherwise the frame timer advances and the handler completes in state 0 with ResetPose; unlike several later dash attacks, this branch does not call the facing helper at completion.


## Dash-attack follow-through family: selector cases 0x4d-0x51

Five handlers share the native dash-momentum decay and frame/cancel state machine, but retain their distinct timing and side effects. Cases 0x4d/0x4e/0x4f/0x50/0x51 use horizontal deceleration 0.06/0.03/0.06/0.06/0.03. The cancel gate requires down input, a nonzero animation frame and field015c<3; cases 0x4d/0x4e/0x51 require attackCollisionResult>1, 0x50 requires exactly 3, and 0x4f has no cancel branch. The cancel routes to states 4/5/6 according to inputX versus facing. Meter/sound events occur at frames 2 (+5, sound 0x15), 3 (+15, sound 0x14), 4 (+15, sound 0x14), 4 (+35, sound 0x23), and 1 (+5, sound 0x15), respectively. Cases 0x4e/0x4f/0x50 also emit local effects 0x1a4/0x1a5/0x1a8 at frames 1/3/6, using integer-truncated current coordinates, owner 1, facing flag, group 2 and layer 1. The 0x4e effect is emitted before the cancel check; the 0x50 effect is emitted only after the cancel check. Case 0x51 finishes in state 3 when inputY==1, otherwise state 0; the others finish in state 0. All normal completions face the opponent and reset pose.


## Extended dash follow-through: selector case 0x52

The 611-byte state 205 reuses the shared dash-attack state machine with 0.03 horizontal decay and the down-input/attackCollisionResult>1 cancel gate. It emits local effect 0x1a6 at frame 1, then grants 13 meter and requests sound 0x14 at frame 2. The effect uses current integer-truncated X/Y, owner 1, the facing flag, group 2 and layer 1. Normal completion chooses state 3 when inputY==1, otherwise state 0, then faces the opponent and resets pose.
