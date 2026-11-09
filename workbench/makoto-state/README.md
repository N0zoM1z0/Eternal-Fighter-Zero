# Makoto Slot06 — natural C++ reconstruction in progress

The original Character03::Slot06 is an authored 58,482-byte function at
0x005E85F0, followed by a 500-byte 125-entry jump table and 310-byte
animation selector table. The full owned extent is
[0x005E85F0, 0x005F6D8C), 59,292 bytes. It is still open.

Character03State.cpp is a **partial, isolated source draft**. It is **not**
linked into src/, does not implement all mapped states, and is not an exact
candidate. In particular, its default return is only a marker for unfinished
work, not the original behavior for valid unimplemented animations.

## Recovered natural C++ paths

- Entry: return on nonzero self hitstop or opponent hitstun.
- Initialize EffectSpawn, read PatternFrame::duration and
  PatternSequence::count, call ResetLocalEffectSpawn.
- Animation ID 1: clear dashMomentumFlag, set velocity (0.7, 0.0).
- Animation ID 2: clear dashMomentumFlag, set velocity (-0.7, 0.0).
- Animation ID 3: set velocity (0.0, 0.0), clear dashMomentumFlag,
  and invoke FaceOpponent.
- Animation ID 13 (block 0x005E8E7A): grounded landing recovery zeros
  both velocity components, clears dashMomentumFlag, faces the opponent,
  then advances the pose. When it finishes, it selects state 0 except when
  inputY (+0x189) is 1, in which case it selects state 3, then ResetPose.
- Animation IDs 15/16 (blocks 0x005E902E and 0x005E913B):
  paired forward/backward aerial launches. Set gravity=0.042 every tick;
  on pose 0/tick 0 set vertical speed=-2.9, clear dashMomentumFlag, and
  set horizontal speed to +0.7/-0.7 respectively. Their final two
  pose frames loop in the air. Landing after pose 3 requests sound 9,
  faces the opponent, and transitions to state 13.
- Animation ID 14 (block 0x005E8F1F): applies gravity=0.042 every tick.
  On pose 0/tick 0 it initializes vertical speed=-2.9 and horizontal speed=0,
  clearing dashMomentumFlag. Pose exhaustion selects animation 9; landing
  after pose 3 requests sound 9, faces the opponent, and selects state 13.
- Animation ID 9 (block 0x005E8DC3): applies vertical acceleration each
  tick, clears dashMomentumFlag, and loops the pose index at animationFrameCount.
  Landing is checked without the pose>3 restriction of jump states 4-6:
  positionY+velocityY >=0 sets positionY=0, requests context sound 9,
  switches to animation 13, and calls ResetPose. No FaceOpponent call occurs
  on this transition.
- Animation IDs 7 and 8 (blocks 0x005E8CA9 and 0x005E8D36): each
  zeroes both velocity components, clears dashMomentumFlag, calls
  FaceOpponent every tick, then advances the unsigned pose timers. On the
  end of the animation, state 7 selects animation 0 and state 8 selects
  animation 3; both call ResetPose. These are distinct fallbacks, not one
  shared terminal state.
- Animation ID 6 (block 0x005E8B61): backward counterpart of state 5,
  using gravity=0.042, vertical speed=-2.9, and horizontal speed=-0.7 at
  pose 3/tick 0. It has no 1.1 dash-speed override or momentum-flag reset
  in this entry block. Its final two pose frames loop and landing uses the
  same sound-9 / animation-13 transition.
- Animation ID 5 (block 0x005E89F4): repeat the first-tick face/zero
  behavior, then on pose 3's first tick set gravity=0.042, vertical speed=-2.9,
  horizontal speed=0.7, with dashMomentumFlag==1 upgrading horizontal speed
  to 1.1 and clearing that flag. Gravity accumulates past pose 2. On frame
  exhaustion, subtract 2 from the advanced frame index rather than switching
  animations. Landing after pose 3 requests context sound 9 and selects
  animation 13.
- Animation ID 4 (block 0x005E8891): on the first tick, face the opponent
  when not carrying dash momentum and clear horizontal speed. On pose 3's
  first tick set gravity=0.042 and vertical speed=-2.9. If dash momentum
  equals 1, replace horizontal speed with 0.4 and clear the flag. Gravity
  accumulates after pose 2. The frame counter advances using the captured
  duration; on animation exhaustion, select animation 9 and ResetPose.
  Landing at pose >3 with positionY+velocityY >=0 requests context sound 9,
  faces the opponent, selects animation 13, and ResetPose.
- Animation ID 47 (block 0x005E9248): a low aerial strike starts with
  horizontal velocity 0.6 and gravity 0.035. Ground contact with pose index
  below 2 switches directly to pose 2, requests context sound 7 and clears
  all motion and gravity. Its pose counter has a special 2-to-0 loop before
  the ordinary end-of-sequence clamp. This behavior is checked against the
  original x87 tests, immediate values and unsigned pose-counter instructions.
- Animation IDs 50–52 (blocks 0x005E9378, 0x005E9569, 0x005E975A)
  implement three strengths of grounded recoil. Each removes 0.6 from
  field0118 per tick when field0120 is set, clears dash momentum, and on
  frame 0/tick 0 grants 10/15/20 meter and initializes horizontal velocity
  from the opponent's combo damage scale with factors -1.1/-1.5/-1.8.
  The optional resource deductions are 10/20/30. Every tick resets vertical
  position/velocity, slows the negative horizontal motion by 0.06 (clamping
  positive speed to zero), and conditionally writes edge pushback at the
  20/639 stage bounds. On animation exhaustion, inputY=1 selects state 3;
  otherwise state 0 is selected before ResetPose. Independent target case
  ranges all occupy 497 bytes, with distinct original immediates/operands.
- Animation IDs 53–55 (blocks 0x005E994B, 0x005E9B3C, 0x005E9D2D)
  independently repeat the 10/15/20 meter, -1.1/-1.5/-1.8 recoil and
  10/20/30 optional resource deductions in separate target blocks. Each
  original block is 497 bytes and has the same stage-edge correction and
  inputY-dependent 0-or-3 recovery as 50–52. Keeping distinct switch arms
  preserves their independent dispatch targets and code-generation structure.
- Animation ID 56 (block 0x005E9F1E) uses the first recoil strength,
  but its 473-byte target owner is 24 bytes shorter than the 50–55 variants:
  when the sequence expires, it always selects crouching state 3 and calls
  ResetPose. It does not read inputY or select state 0 on this exit.
- Animation IDs 57 and 58 (blocks 0x005EA0F7 and 0x005EA2D0) are
  stronger variants of animation 56. Their exact 473-byte target branches
  use 15/20 additional meter, -1.5/-1.8 horizontal recoil, and optional
  20/30 resource deductions. Like state 56, they always end in crouching
  state 3 without reading inputY. Original branch bytes independently
  confirm the per-strength immediates and state-3 termination.
- Animation ID 59 (block 0x005EA4A9, 511 bytes) is a distinct airborne
  hit reaction: it deducts 0.8 from field0118 when enabled and grants 30
  meter on the initial tick. Initial horizontal speed comes from
  knockbackVelocityX. Initial vertical speed is the previous speed scaled
  by 0.75 plus knockbackVelocityY, clamped to [-2.0, -0.5], then gravity
  is set to 0.032. On each tick, the rising/falling signs select pose 1
  or pose 2, with a two-pose loop at animation exhaustion. Landing after
  pose 1 selects animation 0x61 when knockdownOnLanding is set, else
  0x62. Both transitions invoke ResetPose. The original 511-byte block
  was checked independently for constants, branch destinations and
  field offsets rather than copied from an older unverified draft.
- Animation IDs 60 and 61 (blocks 0x005EA6A8 and 0x005EA8A7,
  511 bytes each) preserve the airborne hit reaction from state 59 but
  strengthen the initial downward-to-upward clamp to -4.0 and -6.0.
  Target instruction-by-instruction comparison of all 144 instructions
  per branch shows only the two references to the lower-clamp constant
  differ from state 59. The meter award, airborne frame transitions,
  gravity, and 0x61/0x62 landing outcomes are otherwise the same.
- Animation ID 62 (block 0x005EAAA6, 439 bytes) continues the airborne
  hit-reaction family without any vertical-speed clamp. On pose 0/tick 0,
  it grants 30 meter, copies knockbackVelocityX, computes
  velocityY = velocityY * 0.75 + knockbackVelocityY, and sets gravity=0.032.
  The velocity sign transitions, two-pose end loop and landing-to-0x61/0x62
  rule are independently present in the original 0x005EAAA6..0x005EAC5D
  instructions. Unlike cases 59-61, no -2/-4/-6 or -0.5 clamp is executed.

- Animation ID 63 (block 0x005EAC5D, 427 bytes) differs from case 62
  only in its initial vertical-speed assignment: on pose 0/tick 0 it takes
  knockbackVelocityY directly, without combining it with the previous speed.
  It still grants 30 meter, copies knockbackVelocityX, uses gravity=0.032,
  and preserves the same sign-based poses, two-frame loop and 0x61/0x62
  landing choice. The removed x87 multiply/add accounts for the target
  block being 12 bytes shorter than animation 62.

- Animation ID 64 (block 0x005EAE08, 561 bytes) introduces an
  early wall-contact exit: once the pose index is positive, a nonzero
  CollisionSide() result selects animation 70 (0x46) and calls ResetPose
  before updating gravity or animation counters. At frame 0/tick 0 it
  grants 30 meter, copies knockbackVelocityX, blends old vertical speed
  by 0.75 with knockbackVelocityY, clamps velocityY to [-2.0, -0.5],
  and sets gravity=0.032. Otherwise it retains the original two-pose
  airborne loop and knockdown-dependent landing selection.

- Animation ID 65 (block 0x005EB039, 561 bytes) is the stronger
  wall-contact variant of 64. Both target blocks contain 160 instructions
  and independently dispatch to state 70 after a nonzero CollisionSide()
  past pose zero. The vertical lower clamp references -4.0 at 0x00787D58
  instead of -2.0 at 0x00787D70; the upper -0.5 clamp, meter award, velocity
  blend, gravity, frame advance and landing outcomes are unchanged.

- Animation ID 66 (block 0x005EB26A, 489 bytes) retains state 64's
  positive-pose wall collision exit to animation 70 and its 30-meter first
  tick. Its vertical speed is still the prior value scaled by 0.75 plus
  knockbackVelocityY, but there is no upper/lower clamp. Disassembly
  comparison shows case 66 omits the 19 clamp instructions (72 bytes)
  from the 561-byte case 64; gravity, pose cycle and landing branches remain.

- Animation ID 67 (block 0x005EB453, 477 bytes) is the direct-vertical
  counterpart of case 66. The initial speed is taken directly from
  knockbackVelocityY instead of old velocityY * 0.75 + knockbackVelocityY.
  The target removes the three x87 instructions for that blending
  operation (12 bytes). The collision-side escape to state 70, meter award,
  gravity, two-pose loop and knockdown landing behavior are preserved.

- Animation ID 68 (block 0x005EB630, 316 bytes) uses a different
  airborne recovery rhythm. While field0120 is set it deducts 1.5 from
  field0118, then it adds 3 meter, copies both stored knockback velocities
  directly and increments the pose tick counter on every update (not
  only the first frame). A nonzero CollisionSide() immediately switches
  to animation 70 and ResetPose. Otherwise the frame index wraps by
  subtracting 2 at exhaustion. Landing is checked without any pose-index
  threshold, setting positionY=0 and selecting 0x61/0x62 by knockdownOnLanding.
  No gravity or velocity-clamp operation appears in the target block.

- Animation ID 69 (block 0x005EB76C, 277 bytes) shares case 68's
  recurring 3-meter reward, direct horizontal/vertical knockback velocities,
  1.5 resource deduction when field0120 is set, two-pose rollover, and
  immediate landing decision to 0x61/0x62. It omits the CollisionSide()
  call and the transition to animation 70. Original block 68 spans 316 bytes;
  block 69 spans 277 bytes, accounting for this separate collision branch.

- Animation ID 70 (block 0x005EB881, 480 bytes) handles the wall-hit
  recovery reached from cases 64-68. On its first frame/tick only, when
  field3138 is zero, it grants 30 meter, increments field3138, adds
  120 airActionLockFrames, sets velocity (0.5, -2.5) and gravity 0.025,
  requests context sound 31, and emits global effect type 0 at truncated
  character position with group 2 and layer 1. Unlike normal aerial
  reactions it rolls an expired frame index back to zero rather than
  subtracting 2. Ground contact after pose 1 still selects state 0x61/0x62
  according to knockdownOnLanding. All constants and side effects are
  cross-checked against the original target instructions and the existing
  independent Character23 state-70 implementation.

- Animation ID 71 (block 0x005EBA61, 427 bytes) is the higher-gravity
  direct-speed airborne reaction. On initial pose 0/tick 0 it grants 30
  meter, copies both knockback velocities, and sets gravity to 0.072
  (original double at 0x00787D30). Case 63 instead uses gravity 0.032.
  The two-pose rising/falling cycle, unsigned frame progression, and
  knockdown-dependent landing outcomes match the original 71 block.

- Animation ID 72 (block 0x005EBC0C, 341 bytes) is a grounded
  recoil state. It deducts 0.8 from field0118 when enabled, clears the
  dash-momentum flag and sets both velocities to zero. The stage-edge
  condition is (positionX - 20 <= 0) OR (positionX + 20 >= 639).
  Inside the edge branch it still evaluates the opponent's airborne
  status and assigns (1 - 0.25 * airborne) * velocityX to outgoingPushbackVelocityX;
  otherwise the correction is zero. The x87 expression is preserved even
  though velocityX was just zeroed, because the original executes it.
  On frame exhaustion, inputY==1 selects crouch state 3, else state 7;
  both reset pose. These operations were checked against the target
  0x005EBC0C..0x005EBD61 and a separate authored Character23 variant.

- Animation ID 73 (block 0x005EBD61, 341 bytes) is an independently
  dispatched copy of the grounded recoil state 72. It clears both
  velocities and dash momentum, evaluates the same edge-pushback
  expression, advances unsigned pose counters, and selects state 3
  when inputY==1 or state 7 otherwise at sequence exhaustion. Both
  original instruction blocks were inspected separately; their
  registers differ, but the operations and constants agree. Keep
  separate switch cases to retain the distinct original dispatch.

- Animation ID 74 (block 0x005EBEB6, 317 bytes) shares the original
  case 72/73 grounded recoil and stage-edge pushback calculation but
  always exits to crouch animation 3 and ResetPose when the final
  frame elapses. The original 0x005EBFDB..0x005EBFEE branch has no inputY
  test and no state-7 assignment, unlike cases 72/73.

- Animation IDs 75 and 76 (0x005EBFF3..0x005EC1F0 and
  0x005EC1F0..0x005EC3ED, 509 bytes each) are separate grounded
  forward-recoil entries. At every tick, if field0120 is set they deduct 0.6
  from field0118, then clear dash momentum. Only at pose/tick zero do they
  award 30 meter, optionally deduct another 30 from field0118, and set
  velocityX=2.2. Each tick resets positionY, velocityY and gravity to zero,
  sets horizontalDeceleration=0.06, subtracts it from velocityX and clamps
  nonpositive speed to zero. At x-20 <= 0 or x+20 >= 639, pushback is
  (1 - 0.25 * (opponent Y < 0)) * velocityX; elsewhere it is zero.
  Animation exhaustion selects state 7 or state 3 when inputY==1, then
  ResetPose. Both target blocks contain 134 instructions. The only
  normalized instruction differences are independent x87 predicate scratch
  slots (75 uses EBP-0x94 and 76 EBP-0x98), not arithmetic or branch behavior.
  Their C++ arms are deliberately independent, not one grouped switch label.

- Animation ID 77 (0x005EC3ED..0x005EC5D2, 485 bytes) preserves
  state 75/76's every-tick 0.6 resource drain, 30-meter/30-resource
  first-tick exchange, horizontal 2.2 launch and 0.06 deceleration,
  gravity/vertical reset, and edge pushback. Its distinct animation
  exhaustion is unconditional: field0008=3 followed by ResetPose, with
  no inputY test and no state-7 assignment. The target has 128 instructions,
  six fewer than 75/76; the eliminated instructions match the conditional
  terminal-state selection. The independent x87 scratch home is EBP-0x9C.

- Animation ID 81 (0x005EC5D2..0x005EC7B7, 485 bytes, 135
  instructions) is a distinct airborne recoil and local-effect state.
  If field0120 is set it drains 0.8 from field0118 per tick. On pose/tick
  zero it emits effect 499 with truncated X/Y, facing and layer 1 through
  the virtual local-effect slot; awards 30 meter; copies both incoming
  knockback velocities; and sets gravity=0.032. Every tick adds 0.02 to
  horizontal speed (clamped back to zero if positive), applies gravity,
  advances the unsigned pose counter and holds the last animation frame.
  Landing at positionY+velocityY >= 0 while pose==1 selects 0x61 or
  0x62 depending on knockdownOnLanding and calls ResetPose. The target
  contains two calls to the VC7.1 x87-to-integer helper for effect X/Y,
  and independently accesses virtual effect slot +0x24; this case must
  not be folded into the previous grounded recoil family.

- Animation ID 82 (0x005EC7B7..0x005EC9D9, 546 bytes, 154
  instructions) is a repeated airborne lift before restoring stored
  knockback. A first tick with field3138==0 requests context sound 30,
  sets vertical speed -0.45 and horizontal speed -0.1, increments
  field3138 and grants 30 meter. At pose 4/tick zero it restores
  knockbackVelocityX/Y and gravity 0.032; if descending while still at
  pose 4 it switches immediately to pose 5 with the tick reset.
  Gravity applies only past pose 3. On frame expiration a newly reached
  pose 4 loops to pose 0 while field3138 is below 8, incrementing that
  counter. Otherwise the end-of-animation frame is reduced by two.
  Landing at pose>4 selects knockdown state 0x61 or 0x62 and ResetPose.
  The original case includes a separate 0.8 resource drain each tick.
  Its loop, sound, stored-velocity, and landing paths were independently
  checked against the target instead of assuming another character's
  similar implementation must be correct.

- Animation ID 83 (0x005EC9D9..0x005ECC1E, 581 bytes,
  157 instructions) is the first distinct airborne ground-impact recovery
  entry. Its pose/tick-zero gate emits local effect 0x1F0 once while
  field3144 is clear, using truncated position, group/layer zero,
  owner 1, and the signed facing byte, then marks field3144.
  It conditionally deducts 30 resource, requests context sound 33,
  sets velocity (-0.8,-1.5), and grants 30 meter. Each tick applies
  vertical acceleration 0.04. Early ground contact on pose zero clears
  vertical motion and sets pose 1/tick 0; on pose 1 horizontal speed rises
  by 0.01. Pose 2/tick zero sets horizontal speed -2, and poses past
  one apply 0.06 friction, clamped to nonpositive speed.
  On frame exhaustion the function returns to animation 0, calls
  ResetPose then FaceOpponent. The original contains both x87-to-int
  helper calls, the local effect virtual call and the explicit
  FaceOpponent call. These controls were independently reviewed at
  the original address; no whole-owner Exact assertion is made.

- Animation ID 84 (0x005ECC1E..0x005ECE63, another 581-byte
  157-instruction body) is not an alias of 83: it has its own original
  switch destination and independent statements. Both blocks contain
  the same calls, constants, field accesses and branch decisions, with
  different register allocation near the facing byte move; their
  register-and-EBP-normalized instruction similarity is 155/157
  (98.7%). The independent C++ case preserves the local-effect
  guard, 30-meter startup, ground impact, -2.0 horizontal transition,
  ResetPose/FaceOpponent termination and original virtual call.
  Retaining both arms is necessary until the whole dispatch and
  selector table have been reconstructed.

- Animation ID 85 (0x005ECE63..0x005ED036, 467 bytes) differs
  materially from 83/84. It has the same guarded one-time effect 0x1F0
  producer, 30 resource drain, sound 33 and +30 meter, but copies the
  stored knockbackVelocityX/Y rather than hard-coding -0.8/-1.5.
  Every frame adds 0.04 to velocityY, advances the animation and
  calls ResetPose/FaceOpponent if the animation ends. A separate
  positionY+velocityY >= 0 check (with no pose gate) then resets
  positionY and chooses 0x61/0x62 based on knockdownOnLanding.
  Both independent state transitions remain in the natural C++ arm,
  matching the observed original order instead of merging the
  cases by their common effect prefix.

- Animation ID 86 (0x005ED036..0x005ED218, 482 bytes) has a
  guarded first-tick effect identical to the local 0x1F0 producer in 85,
  but its movement setup is additionally conditional on field3138==0.
  Only then does it subtract 30 resource when enabled, request sound 33,
  take knockbackVelocityX/Y, award 30 meter and increment field3138.
  Subsequent ticks add **0.06** to velocityY (0x00787DA8, checked in
  EFZ.exe; not the 0.04 in state 85). Expired frames wrap the pose to
  zero without resetting the animation. Landing at any pose selects
  0x61/0x62 from knockdownOnLanding. The original branch was checked at
  0x005ED036..0x005ED213; the isolated draft builds with VC7.1.

- Animation ID 87 (0x005ED218..0x005ED2CB, 179 bytes) is a short,
  independent first-tick effect owner. It emits local type 0x1EF at fixed
  coordinates (60.0, 40.0), with palette=1, flag0018=1, group=0 and
  layer=0. These are actual target data constants and field stores,
  not character-position calculations. Its unsigned pose counter returns
  to animation 0 and calls ResetPose on exhaustion. The effect event is
  only on pose/tick zero; neither velocity nor gravity is written.

- Animation ID 96 (0x005ED2CB..0x005ED360, 149 bytes) only
  advances pose timers. At exactly animationFrameCount-1 it calls
  FaceOpponent, then on exhaustion requests state 7 or state 3 when
  inputY==1 and resets the pose. It does not reset gravity or velocity.

- Animation IDs 97 and 98 (0x005ED360..0x005ED458 and
  0x005ED458..0x005ED550, 248 bytes each) are separate impact-flash
  arms. Both clear velocityX/Y each tick; on pose/tick zero they call
  SetVerticalShake(3,0), emit **global/context effect** type 3 at
  truncated character coordinates with group 2 and layer 0, and request
  sound 7. Both advance to animation 99 after frame exhaustion. The
  target's direct call at 0x00407100 is Context::EmitEffect, not the
  virtual per-character local-effect call. These instructions were
  reviewed independently, including distinct target stack scratch slots.

- Animation ID 99 (0x005ED550..0x005ED5FF, 175 bytes) clears dash
  momentum every tick. If health>0 and its unsigned frame tick is
  greater than 99, it switches to animation 96 and calls ResetPose,
  **without** requiring pose 0 (unlike superficially similar characters).
  After normal frame advancement it calls FaceOpponent exactly when the
  advanced pose equals animationFrameCount and then returns to state 96
  on exhaustion. Target instructions were checked independently.

- Animation IDs 150–152 (0x005ED5FF..0x005EDB03, 1,284 bytes)
  implement three grounded recoil strengths, and 153–155
  (0x005EDB03..0x005EDFBF, 1,212 bytes) are their crouch-terminal
  counterparts. Each **reselects its stand/crouch ID every tick** from
  inputY (150/153, 151/154 or 152/155). On pose/tick zero it clears
  dash momentum, adds 10/15/20 meter, initializes velocityX to
  -1.5/-1.8/-2.3 and grounds position/velocityY. Every tick it holds
  velocityY at zero, adds 0.06 to horizontal speed (clamped at zero),
  and only writes horizontal pushback near x<=20 or x>=619. Both
  three-case families call FaceOpponent when the frame reaches the
  sequence count. The 150–152 end paths select idle 0 or crouch 3
  based on inputY, whereas 153–155 **always** select crouch 3.
  Original constants, independently dispatched blocks, exact direct
  FaceOpponent calls and all 2,496 instruction bytes were checked
  against the current EFZ.exe. The partial draft compiles with VC7.1.

- Animation ID 156 (0x005EDFBF..0x005EE0CF, 272 bytes) starts
  with velocityY=-2.6, meter+15, gravity=0.06, then enforces
  velocityX=-1.2 and adds gravity every tick. On pose exhaustion it
  enters state 9 and resets; on grounded contact it requests sound 9,
  faces the opponent and enters animation 13 instead.

- Animation IDs 157 and 158 (0x005EE0CF..0x005EE223 and
  0x005EE223..0x005EE377, 340 bytes each) implement a mirrored
  air-effect launch. They set velocityX to +1.0/-1.0, gravity=0.045
  and clear dash momentum each tick. On their first pose/tick they set
  vertical speed -2.3 and emit context effect 8 with group 2/layer 0
  at truncated character position; otherwise they add gravity. When
  the pose expires, **both subtract two from the advanced pose** rather
  than returning to state 9. This differs from the accepted Character07
  implementation and was verified against Makoto's own instructions.
  Landing uses the same sound-9, FaceOpponent, animation-13 transition.
  All three original 952-byte blocks and constants were checked against
  EFZ.exe and the partial source compiled under VC7.1.

- Animation ID 161 (0x005EE377..0x005EE48B, 276 bytes) resets its
  current frame on pose/tick zero and emits global effect type 9 at the
  character's truncated X and truncated Y minus 60, group 2/layer 1.
  It grants one remaining hit, requests context sound 62 and advances
  field3138. The animation finishes by switching to state 9,
  resetting the pose, then setting gravity to 0.035 in that order.

- Animation ID 162 (0x005EE48B..0x005EE676, 491 bytes) is a staged
  airborne attack: first-tick ResetFrame; at pose 3/tick zero it sets
  vertical speed -1.5, gravity 0.025 and one remaining hit; at pose
  7/tick zero it resets the frame again, emits the same type-9 global
  effect, requests sound 62, consumes 1,000 meter and increments
  field3138. Gravity is added every tick. Positive ground penetration
  triggers **two** ResetPose calls before setting positionY to zero;
  do not collapse these calls to one. On advancing to pose 18, gravity
  changes to 0.035; the final pose loops backward by two frames.
  The raw 767-byte target range was checked against the canonical
  executable and the draft was rebuilt under VC7.1.

- Animation ID 163 (0x005EE676..0x005EE867, 497 bytes) is Makoto's
  cancellable dash, **not** the generic Character07 dash. Its first
  tick starts trail 3. Down+jump after pose zero selects states 4/5/6
  by facing and inputX, clears attackCollisionResult, and resets pose.
  Otherwise its first tick clears vertical speed/gravity, every tick
  enforces velocityX=2.2 and dashMomentumFlag=1, then advances
  field3138 and field313c. Frame exhaustion rolls back **six** poses;
  it does not return to idle. A late state-178 transition requires
  either same-facing input with field313c>=80 or opposite-facing input
  with field3138>=60, with pose below 4. The current target contains
  no call to ResetFrame or first-tick context sound in this branch.

- Animation ID 164 (0x005EE867..0x005EE9B2, 331 bytes) starts trail 3
  on every tick and clears dashMomentumFlag. The first tick zeroes
  velocities; pose 1/tick zero sets velocityX=-2.2. It then applies
  +0.02 horizontal deceleration and clamps positive speed to zero.
  When the advanced pose equals 4 with field3138<2, it subtracts
  two poses and increments field3138. At sequence exhaustion, it
  calls FaceOpponent, enters idle state 0, ResetPose, then ResetFrame
  in that order. This is distinct from Character07's -3.1/+0.04
  and threshold-driven early exit. Both original blocks (828 bytes)
  were checked byte-for-byte in EFZ.exe; the partial owner builds.

- Animation IDs 165 and 166 (0x005EE9B2..0x005EEDC4, 519 and
  523 bytes respectively) are sustained air-momentum variants with
  separate dispatches and opposite horizontal motion. Only at the
  initial pose/tick with field3138==0 do they start trail 3 and sound
  17, set velocityX to +1.9/-1.9, velocityY=+1.3, horizontal
  deceleration=-0.015/+0.015 and gravity=-0.038. Each tick adds
  gravity/deceleration, clamps horizontal speed to >=0.5/<=-0.5,
  and clamps vertical speed to >=-1.5. Both increment field3138/313c,
  advance the unsigned pose and loop its final two frames.
  Same-direction input after 120 ticks (field313c) or other input after
  48 ticks (field3138) transitions to state 9, ResetPose and gravity
  0.03. FaceOpponent may negate the **current** velocityX, not a
  newly assigned constant. State 166 compares inputX to -facing,
  while 165 compares to facing. These are two independent checks in
  each case and must not be combined into else-if. The original
  1,042-byte target range and every named x87 constant were verified
  against EFZ.exe; the partial draft builds with VC7.1. The related
  Character07 cases have different initial velocities and thus cannot
  be copied as equivalent source.

- Animation ID 167 (0x005EEDC4..0x005EEFAC, 488 bytes) performs a
  stunned recovery with independent pose-based effects. On the first
  pose/tick it clears dash momentum and movement, adds field0118*5.0
  to comboDamageScale only when field0120==1, clears field0118,
  sets hitstunFrames=90, and calls SetTint(0xB0,3). Pose 1/tick
  zero requests sound 18 and emits global effect type 1, while pose
  2/tick zero emits global type 4. Both effects are placed at the
  independently truncated character coordinates with group 2/layer
  1. After duration expiry, every pose advance clears
  attackCollisionResult. On sequence exhaustion it requests idle,
  faces the opponent, and resets the pose. The entire 488-byte
  original range was checked in canonical EFZ.exe; VC7.1 builds the
  added natural C++ branch.

- Animation IDs 168 and 169 (0x005EEFAC..0x005EF0F6 and
  0x005EF0F6..0x005EF240; 330 bytes each) are independently dispatched
  grounded impacts with the same first-tick cleanup: clear dash
  momentum, horizontal/vertical speed, vertical position, gravity,
  guardInputFrames, outgoingPushbackVelocityX and
  horizontalDeceleration. The first tick also emits context effect 8
  with truncated character coordinates, group 2 and layer 1. Frame
  exhaustion calls FaceOpponent on the **exact** final pose, then
  enters idle state 0 for 168 or crouch state 3 for 169 and calls
  ResetPose. Both ranges (660 bytes total) were rechecked against
  EFZ.exe; the draft compiles with VC7.1. The shared source body
  does not imply a shared jump destination or identical terminal ID.

- Animation ID 170 (0x005EF240..0x005EF409, 457 bytes) saves
  (int)(velocityX*100) and (int)(velocityY*100) into field3138/313c
  on the first tick, clears both velocities, conditionally initializes
  gravity=0.035 if it was zero, clears guardInputFrames and outgoing
  pushback, and assigns hitstunFrames=60. When hitstun reaches zero
  and field3140 is still zero, it increments field3140 and restores
  both velocities at *0.01; until the freeze ends there is no gravity
  integration. Positive ground penetration calls **ResetFrame**, sets
  positionY=0 and switches to state 169 without calling ResetPose.
  Otherwise the pose advances and returns to animation 9 on expiry.

- Animation ID 171 (0x005EF409..0x005EF5E8, 479 bytes) also saves the
  scaled velocities on initial pose/tick, zeroes speed, transfers the
  5.0*field0118 resource component to comboDamageScale when enabled,
  clears field0118, sets hitstunFrames=90 and SetTint(0xB0,3).
  It **immediately emits effect type 1 at pose 0/tick 0** (with sound
  18, context/group 2/layer 1). Unlike the superficially similar
  Character07 case, Makoto has no separate pose-1/pose-2 effect block.
  Every duration expiry advances the pose and clears
  attackCollisionResult; sequence exhaustion enters state 9, restores
  stored velocities with factor 0.01, initializes gravity=0.035 and
  calls ResetPose. This entire 936-byte target range and the x87
  100.0/0.01 constants were checked against EFZ.exe. The partial
  owner compiles under VC7.1.

- Animation ID 178 (0x005EF5E8..0x005EF70A, 290 bytes) slows
  velocityX by 0.03 every tick, retains the source's otherwise
  redundant self-assignment, and clamps negative horizontal speed
  to zero. **No write to dashMomentumFlag** occurs in Makoto's target
  block (unlike Character07): a copied momentum clear was removed
  after independently inspecting every instruction. Down+jump from a nonzero pose
  chooses states 4/5/6 by inputX and facing, clears the attack collision
  result and resets pose. Ordinary sequence exhaustion chooses
  **state 7**, not state 0 as in the comparable Character07 branch.

- Animation ID 180 (0x005EF70A..0x005EF87C, 370 bytes) first starts
  trail 2 and clears velocity/gravity. While airborne (positionY<0),
  it adds gravity. If next-position Y is strictly positive before
  pose 10, ResetFrame forces pose 10, clears tick/Y and requests sound
  9; the duration counter still advances this update. On advancing
  to **pose 1**, it assigns velocity (-0.5,-1.0) and gravity 0.028,
  not on pose 3 as in the Character07 implementation. Pose 10 loops
  backward by two; on sequence exhaustion it calls ResetPose
  **before** selecting animation 0. The original 660-byte span and
  all four x87 constants were checked against EFZ.exe; the draft
  compiles with VC7.1.

- Animation IDs 200 and 201 (0x005EF87C..0x005EFA4F and
  0x005EFA4F..0x005EFC22, 467 bytes each) preserve momentum-based
  attacks with independent switch targets. When dashMomentumFlag is
  zero they clear both velocities. Positive velocity with flag 1
  applies a **0.03** horizontal loss each tick; other conditions
  zero velocityX and clear the flag. Both permit a jump cancel after
  pose zero if inputY=-1, field015c<3 and attackCollisionResult>=2,
  choosing states 4/5/6 by facing/inputX and resetting the collision
  result. State 200 rewards 5 meter, sound 21 and one remaining hit at
  **pose 2/tick zero**; state 201 instead awards 15 meter, sound 20
  and one hit at **pose 1/tick zero**. On duration expiration both
  clear attackCollisionResult only while the advanced pose is below
  **2**, and return to idle through FaceOpponent/ResetPose at sequence
  exhaustion. These pose gates and the 0.03 constant differ from the
  analogous Character07 cases. All 934 target instruction bytes were
  verified against EFZ.exe and the isolated draft was rebuilt.

- Animation ID 202 (0x005EFC22..0x005EFDDF, 445 bytes) starts
  with the same momentum gate/0.03 friction as states 200/201 but
  does not permit their down+jump cancel. At pose 3/tick zero it
  grants 15 meter, requests sound 20 and one remaining hit. On
  advancing the pose it clears attackCollisionResult only while the
  new pose is below 2. On the **advance to pose 4** (not at an
  independent pose-4 first-tick gate), it clears
  pendingCharacterSoundSlot, emits character-local effect type 0x19D
  at truncated X+34*facing and truncated Y-31 with facing,
  group 2/layer 1, then checks animation exhaustion. The effect is a
  virtual local-effect call, not Context::EmitEffect. Expiration
  returns to idle, FaceOpponent and ResetPose. The complete original
  445-byte range was independently rechecked against EFZ.exe and
  the C++ draft compiles under VC7.1.

- Animation ID 203 (0x005EFDDF..0x005F008D, 686 bytes) is an
  input-repeatable charged hit, not the superficially similar
  Character07 pose-4 local effect. It applies momentum friction 0.06
  every tick when velocityX is positive and dashMomentumFlag==1,
  otherwise clears horizontal momentum and flag. At pose/tick zero
  it sets remainingHitCount=1. If pose==10, buttonPulse[2]==1 and
  field3138<2, it clears pendingCharacterSoundSlot, resets tick and
  pose to 0/6, clears that sound slot a second time and the collision
  result, grants 15 meter, increments field3138 and emits **local**
  effect 400 at truncated X+90*facing, truncated Y-50 with facing,
  group 2/layer 1. Independently, after frame expiration advances
  the pose, it clears the collision result below pose 7 and emits
  the same local effect when the new pose equals 6. Both paths are
  required to retain their ordering. At sequence exhaustion it
  enters idle, FaceOpponent then ResetPose. The full 686 bytes of
  original instructions were rechecked against the canonical target
  and the natural C++ owner compiles with VC7.1.

- Animation IDs 204 and 205 (0x005F008D..0x005F0278 and
  0x005F0278..0x005F0463, 491 bytes each) retain the 0.03
  dash-momentum friction and allow a downward jump cancel only after
  pose zero with field015c<3 and attackCollisionResult>=2. State 204
  awards 5 meter, sound 21 and one hit on pose 1/tick zero; state 205
  awards 13 meter, sound 20 and one hit on pose 2/tick zero. Both
  clear attackCollisionResult after frame expiration only while the
  advanced pose is below 2. On exhaustion, they choose state 0 or
  crouch 3 from inputY, then call FaceOpponent and ResetPose. The
  original instructions independently confirm their pose gates,
  immediates and distinct destinations. All 982 target bytes were
  rechecked against EFZ.exe, and the VC7.1 partial owner compiles.

- Animation ID 206 (0x005F0463..0x005F0669, 518 bytes) has a
  two-phase dash/attack loop that is not the Character07 reference
  behavior. Below pose 2 it runs the 0.03 dash-momentum gate; after
  that, every tick with *positive* horizontal velocity clears the
  momentum flag, subtracts an additional 0.02 and clamps negative
  speed to zero. Pose 2/tick zero grants 25 meter, sound 20 and one
  hit. Only on frame expiry does pose 1 clear attackCollisionResult,
  pose 2 set velocityX=1.9, and pose 6 loop back three poses while
  field3138<4. Each loop increments field3138; when it exceeds two,
  remainingHitCount is cleared. Sequence exhaustion chooses crouch
  state 3, calls FaceOpponent, then ResetPose. The original 518-byte
  instruction range, x87 0.02 and 1.9 constants, and the separate
  pose gates were checked against EFZ.exe; the partial VC7.1 build
  succeeds. This owner is still partial, not an Exact function.

- Animation IDs 207 and 208 (0x005F0669..0x005F0840 and
  0x005F0840..0x005F0A17, 471 bytes each) are separate aerial attacks.
  Each adds gravity to velocityY before checking an air-jump cancel:
  inputY=-1, nonzero pose, field015c<3, attackCollisionResult>=2,
  and airActionCount==0. A successful cancel increments airActionCount,
  selects 14/15/16 from inputX/facing, clears attackCollisionResult
  and resets pose. State 207 grants 5 meter, sound 21 and one hit on
  pose 2/tick zero; state 208 grants 13 meter, sound 20 and one hit
  on pose 3/tick zero. Their *independent* original blocks both land
  at positionY+velocityY>=0 into state 13 and ResetPose without
  playing sound or calling FaceOpponent. Otherwise they advance the
  unsigned pose, clear attackCollisionResult below pose 2 and switch
  to airborne state 9 on sequence exhaustion. All 942 target bytes,
  immediate values and the 0x15A airActionCount gate were checked
  directly; the partial owner compiles with VC7.1.

- Animation ID 209 (0x005F0A17..0x005F0CB7, 672 bytes) is a
  repeatable aerial local attack with the same jump-cancel gate as
  207/208 but an additional pose>4, buttonPulse[2]==1 and
  field3138<2 loop: it rewinds to pose 3/tick zero, increments
  field3138 and clears the hit result. Ground contact goes directly
  to animation 13 and ResetPose. When frame advancement reaches
  pose 4, it grants 15 meter, requests sound 20 and one remaining hit,
  clears pendingCharacterSoundSlot, then emits local effect type
  0x191 at truncated X+27*facing and truncated Y-28, group 2/layer 1.
  This is an *advanced-pose* event, not a pose-4 initial-tick event.
  Only below pose 2 does the advance clear attackCollisionResult;
  an expired sequence rewinds the pose by two, remaining airborne.

- Animation ID 210 (0x005F0CB7..0x005F0E5C, 421 bytes) starts
  by clearing dash momentum and calling ResetFrame on pose/tick zero.
  At pose 3/tick zero it starts motion (velocityX=0.6,
  velocityY=-1.4, gravity=0.036); at pose 6/tick zero it awards
  20 meter, sound 20 and one remaining hit. Gravity only advances
  past pose 2. A nonnegative projected Y while pose is 4..8 resets
  the frame, zeros tick/Y and forces pose 9 **without** ResetPose or
  sound. Ordinary expiry resets the hit result below pose 2 and ends
  in crouch state 3 through FaceOpponent and ResetPose. Constants
  and the distinct event gates were checked against original target
  instructions rather than copying the Character07 case. Both
  branches compile under VC7.1; all 1,093 bytes of their source
  instruction ranges were independently rechecked in EFZ.exe.

- Animation ID 211 (0x005F0E5C..0x005F10A0, 580 bytes) is an
  airborne strike with the same one-time jump-cancel condition as
  207–209. Gravity is integrated first; a legal down+jump cancel
  increments airActionCount, chooses states 14/15/16 by facing and
  resets pose. Nonnegative projected Y switches to landing state 13.
  When the duration counter advances the pose to **5**, it grants
  15 meter, requests context sound 20 and one remaining hit, clears
  pendingCharacterSoundSlot, and emits character-local effect 400 at
  truncated X+45*facing, truncated Y-62 (group 2/layer 1, facing
  byte). It clears attackCollisionResult when the new pose is below
  2 and loops the last two pose frames rather than returning to
  state 9. The 580 original instructions/code bytes were checked
  against the current target and the natural C++ branch compiles.

- Animation ID 212 (0x005F10A0..0x005F1265, 453 bytes) first
  integrates the *old* gravity, then on pose/tick zero gives 30 meter,
  sound 20, one hit, halves velocityX and sets gravity=0.07. A hit
  result above 1 immediately enters state 213, calls ResetPose and
  then ResetFrame. Ground contact instead clears Y/vertical speed,
  calls SetVerticalShake(3,0), emits context effect type 3 with
  palette 7/group 2/layer 0 at truncated position, requests sound 7
  and enters state 214. Otherwise the unsigned pose advances,
  clearing attackCollisionResult after each duration; end-of-sequence
  poses loop backward by two.

- Animation ID 213 (0x005F1265..0x005F1321, 188 bytes) sets gravity
  0.042 every tick and adds it to velocityY *before* its initial
  pose/tick-zero velocity assignment (-1.0,-2.4). Each duration
  expiration clears attackCollisionResult; exhaustion enters airborne
  state 9 through ResetPose. No landing or effect branch appears.

- Animation ID 214 (0x005F1321..0x005F1440, 287 bytes) zeroes both
  velocities each tick. Pose/tick zero shakes the screen (3,0) and
  emits a palette-7 global effect type 3 (group 2/layer 0). Frame
  advancement clears attackCollisionResult. End-of-sequence recovery
  selects state 7 or crouch state 3 from inputY, FaceOpponent and
  ResetPose in that order. These three independently dispatched
  original blocks cover 928 bytes, checked along with every x87
  constant and effect call directly in EFZ.exe; the C++ draft builds.

- Animation ID 220 (0x005F1440..0x005F160E, 462 bytes) is Makoto's
  opponent grab entry. Every tick it zeroes X/Y velocity and dash
  momentum. Pose 1/tick zero gives one hit only if the opponent Y is
  exactly zero; otherwise the remaining hit count is cleared. A
  pose-1 attackCollisionResult==3 grab clears horizontal pushback,
  calls self ResetPose, then opponent ResetPose and ResetFrame, enters
  own state 221, and sets the opponent state to **107**. It emits
  **context** effect 0 at truncated X+25*facing and truncated Y-51,
  group 2/layer 1. The target does *not* set the opponent's
  airActionDisabled flag here (unlike the Character07 reference),
  and it still executes the normal frame counter after the grab.
  Each elapsed frame clears attackCollisionResult; exhaustion enters
  idle state 0 through FaceOpponent/ResetPose, without an inputY
  crouch branch. Original call order, 462 bytes and target constants
  were rechecked in EFZ.exe; the C++ draft builds with VC7.1.

- Animation ID 221 (0x005F160E..0x005F182F, 545 bytes) is Makoto's
  grab follow-through, which is not the Character07 damage-script
  owner. On pose 1/tick zero it invokes opponent ResetPose, opponent
  ResetFrame, then changes the opponent state to **50**. Past pose 2
  it integrates gravity and removes 0.045 horizontal speed, clamping
  negative velocityX to zero. Ground contact during poses 3..8
  forces pose 9, tick zero, Y zero, and calls self ResetFrame without
  resetting the animation ID. On each expired frame it advances pose
  and clears attackCollisionResult. The advance to pose 2 sets
  velocity (1.5,-1.6), gravity 0.05 and emits a **global** effect 31
  with truncated X, Y=0, group/layer zero and facing=(facing!=1).
  The advance to pose 4 grants 30 meter, one remaining hit and sound
  21. Normal exhaustion enters idle state 0 with ResetPose only;
  there is no FaceOpponent call. The independent 545-byte target
  block, all four doubles and effect field stores were rechecked
  against EFZ.exe, and the partial owner compiled under VC7.1.

- Animation IDs 230 and 231 (0x005F182F..0x005F1975 and
  0x005F1975..0x005F1ABB, 326 bytes each) are independent grounded
  trail attacks. Each calls StartTrail(3) and clears dash momentum on
  *every* tick, subtracts 0.03 from positive horizontal speed (or
  clears it otherwise), and clamps negative horizontal speed to zero.
  Their pose/tick-zero entry only zeroes velocityY: Makoto does **not**
  assign the first-tick horizontal speed 2.0 used by the analogous
  Character07 arms. State 230 awards 5 meter, sound 21 and one hit on
  pose 1/tick zero; state 231 awards 10 meter, sound 20 and one hit on
  pose 2/tick zero. Every expired frame clears attackCollisionResult,
  and sequence exhaustion enters idle with ResetPose, without a
  FaceOpponent call. Both target blocks independently matched the
  private original disassembly for all 652 bytes; the partial C++
  owner builds under VC7.1 (not whole-owner Exact).

- Animation ID 232 (0x005F1ABB..0x005F1C6F, 436 bytes) is a
  three-phase launched strike, not the generic momentum attack in
  Character07. Every tick clears dashMomentumFlag and starts trail
  3. The first pose/tick sets horizontalDeceleration=0 and one hit.
  While pose<3, it removes 0.035 from horizontal speed and clamps
  negative speed to zero. Pose 3/tick zero grants 25 meter and sound
  20, but does not separately rearm the remaining-hit field. During
  pose 3 it applies gravity, and a nonnegative projected Y forces
  Y=0, ResetFrame, tick=0, pose=4 *before* ordinary frame advance.
  A normal frame advance into pose 3 initializes horizontal speed
  1.8, vertical speed -1.5 and gravity 0.045; expiry selects state 0,
  calls FaceOpponent, then ResetPose. All 436 original bytes and four
  double constants were checked directly in EFZ.exe; the complete
  partial dispatcher compiled under VC7.1.

- Animation IDs 233 and 234 (0x005F1C6F..0x005F1DB5 and
  0x005F1DB5..0x005F1EFB, 326 bytes each) are independently
  dispatched crouch-terminal trail strikes. The first arm clears
  dash momentum *before* StartTrail(3), while the second starts the
  trail first. Both preserve the 0.03 positive-horizontal-speed
  friction and clamp negative speed to zero, and only the initial
  pose/tick zeroes velocityY. State 233 grants 5 meter, sound 21 and
  one hit on pose 1/tick zero; state 234 grants 10 meter, sound 20 and
  one hit on pose 2/tick zero. Every expired frame clears
  attackCollisionResult; both finish in **state 3**, followed by
  ResetPose without FaceOpponent. They must not be grouped with
  states 230/231, which finish in state 0. All 652 original bytes
  were compared against EFZ.exe, and the partial VC7.1 owner builds.

- For these cases, increment field000c, wrapping to zero and advancing
  field000a once the frame's duration is reached, then wrap the frame index
  at the animation's frame count. These are unsigned 16-bit members in the
  original load/stores.

The constants at target 0x00787DE8 and 0x00787DE0 decode to 0.7 and
-0.7 as IEEE-754 double. 0x00405490 is EffectSpawn::EffectSpawn,
0x00413090 is Secondary::ResetLocalEffectSpawn, and 0x0040E630
is Secondary::FaceOpponent.

The selector contains 124 explicit animation IDs and 186 defaulted IDs.
The reviewed mapping is in the ignored
.analysis/probes/makoto/state-case-map.csv; the 58,482-byte target code
extent has a longer text disassembly in
.analysis/probes/makoto/state-code-005e85f0.txt.
The evidence and extent are documented under
docs/KNOWLEDGE_BASE.md#makoto-state-dispatch-boundary-and-selector-mapping.

## Next implementation work

The 2026-11-09 handoff storage cleanup archived 61 historical candidate
disassemblies and 67 named trial objects without deleting the current
workbench source, target case map or latest objects. See
`docs/RE_ARTIFACTS.md` for the exact archive and restore paths.

Extend case 235 and onward directly from reviewed target instructions,
retaining each case's distinct frame behavior. Once a complete owner exists,
add its selected match unit with correct internal jump/selector table
ownership and run the strict VC7.1 COFF comparison. Do not add it to the
exact-function ledger until the entire 59,292-byte owned extent matches.
