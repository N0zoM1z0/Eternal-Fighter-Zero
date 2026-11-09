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
.analysis/probes/makoto/state-case-map.csv; the original 58 KB disassembly
is in .analysis/probes/makoto/state-code-005e85f0.txt.
The evidence and extent are documented under
docs/KNOWLEDGE_BASE.md#makoto-state-dispatch-boundary-and-selector-mapping.

## Next implementation work

Extend cases 72 and onward directly from reviewed target instructions,
retaining each case's distinct frame behavior. Once a complete owner exists,
add its selected match unit with correct internal jump/selector table
ownership and run the strict VC7.1 COFF comparison. Do not add it to the
exact-function ledger until the entire 59,292-byte owned extent matches.
