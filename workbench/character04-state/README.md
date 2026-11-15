# Character04::Slot06 — original-bound 59,143-byte state boss

**PARTIAL: not whole-function Exact.** Authored C++ (with narrowly
scoped VC7.1 inline assembly for register-sensitive x87 code) covers
the original default and **133 genuine live cases**: 1–9,13–16,
47,50–77,81–87,96–99,150–158,161–171,180,200–216,220–221,
230–232,240–241,249–269,303–309,312,315–320. The other **5** native live case IDs remain OPEN.
Throwaway compilation markers never earn original source credit.

## Original PE ownership and dispatch

- Original vtable pointer `0x00788B94` selects `0x00607930`
- Native owner `[0x00607930,0x00616037)` **59,143 code bytes**, SHA-256
  `200261f2d50fa04663e62d285dd09cd0eeaf601fdee46e08b2798e8cf95b02a1`
- Native pointer table `[0x00616037,0x00616263)`: **139 DWORD
  destinations**, one for each of 138 live states plus default
- Original selectors `[0x00616263,0x006163A8)`: **325 bytes**,
  138 live IDs, 187 default IDs
- Original full stack allocation is `sub esp,0x2E8`; the native
  shared epilogue at `0x00616033` is `mov esp,ebp; pop ebp; ret`

## Current audited continuous prefix

The original code `[0x00607930,0x0061579D)` now has **56,941
original executable bytes**, canonical SHA-256
`5bf56be09459acb1202fe09793a88abbeb318b061223833644db49cc5edec569`.
New real C++ cases220–221 reconstruct an actual two-character
grab and four-stage throw. Case220 zeroes both speeds, transitions
own pose221 and opponent pose108, triggers original effect0 at
X+facing×49/Y−43, and immediately returns from successful grab.
At frame advance it clears `remainingHitCount` whenever not on
pose1 or the opponent is airborne; this condition was independently
caught by native branch-target validation, not inferred from length.
Case221 shakes screen `(50,3)`, clamps owner X, positions the
opponent in successive native states103/117/97 at original
Y−150/−100/−81/0, sets the opponent's facing, applies native
`ApplyDamage(1200,750.0)` and calls opponent ResetPose/ResetFrame.
New airborne cases230–232 use original gravity0.03 and velocityX0.5,
grants meter5/10/10 at poses1/2/1, requests sound21/21/20, and
returns to state13 upon landing or state9 at animation completion.
State240 (`0x00610DDA`, 498 bytes) adds the collision-result-3 grab
handoff: it resets both fighters' frame/pose state, advances the owner
to state241 and the opponent to state100, emits effect0 at the native
integer-truncated X+facing×31/Y−82 point, and positions the opponent
at the corresponding live X/Y offsets. On frame advance it derives
`remainingHitCount` from the opponent's airborne position and whether
the opponent state is outside 50–149, clears the collision result, and
hands off to state209/frame1 when the animation ends.
State241 (`0x00610FCC`, 720 bytes) completes the airborne throw sequence.
It applies horizontal offset and shake `(50,3)` through frame3, flips
the opponent's facing on tick1, and advances the opponent through states
103/104/69 at the native `(X+facing×29,Y−80)`,
`(X+facing×11,Y−71)`, and `(X−facing×37,Y−60)` placements. The frame3
impact applies `ApplyDamage(1300,500.0)`, resets the opponent pose, and
sets knockback velocities `(-3.0,3.0)`. Frame5 installs gravity0.035;
the animation loops its final two frames until the landing predicate
fails, then resets the owner and transitions to state13.
State249 (`0x0061129C`, 320 bytes) initializes the special-move hitstun
and effect only on frame0/tick0: it sets `field00dc=4`, `field00de=0xEC`,
zeroes horizontal velocity, sets `remainingHitCount=1`, clears guard-input
frames, and sets hitstun to60. It emits effect `0x28` at the native
integer-truncated `(X+facing×10,Y−40)` position with group2/layer1/palette
`0x13`. Each animation-frame advance clears the collision result; at
completion it clears the state, faces the opponent, and resets the pose.
State250 (`0x006113DC`, 436 bytes) handles the airborne startup and
frame loop. On frame0/tick0 it zeroes gravity (and horizontal velocity
when grounded) and records `field3138=1` when already airborne. On
frame1/tick0 it adds 25 meter, sets `remainingHitCount=1`, halves both
velocity components, and installs gravity0.025. Frames0–1 always advance;
airborne frames can advance three ticks early when `field3138==1`. Every
advance clears the collision result and the animation wraps to frame11.
Once frame>=2 and `positionY+velocityY` is nonnegative, it clears tick
and frame and transitions to state253.
State251 (`0x00611590`, 471 bytes) is the second airborne startup variant.
It uses the same ground/air startup latch and frame1 meter/velocity setup,
but frame1 gravity is0.035. Its landing handoff additionally sets the
private `field313c=1` before leaving for state253. Unlike state250's frame11
loop, state251 clears `attackCollisionResult` only when the animation
advances into frame1; at animation completion it sets state0 and invokes
the virtual `ResetPose` slot, which clears the Character04 private counters.
State252 (`0x00611767`, 790 bytes) is the charged airborne special.
At frame0/tick0 it latches airborne startup, emits effect `0x21` at
integer-truncated `(X,Y−20)` with palette `0x0B`, and starts trail3. It
then consumes 1000 from `field3148` (clamped at zero) when `field3144==4`,
otherwise subtracts 500 or 250 from `field0118` according to `field0120`.
Frame1/tick0 adds25 meter, sets two remaining hits, halves both velocity
components and installs gravity0.025. Frame7/tick0 emits local effect
`0x1A2` at `(X+facing×37,Y−40)`. Its airborne early-frame gate and landing
handoff to state253 remain active through the frame-counter update; animation
completion sets state0 and calls virtual `ResetPose`.
State253 (`0x00611A7D`, 204 bytes) is the post-landing recovery bridge.
It zeroes both velocity components, faces the opponent every tick, and
normally advances by the current frame duration. If frame2 inherits
`field313c==1`, tick21 is an additional early-advance point. Each advance
clears the collision result; when the animation completes it selects state3
if `inputY==1`, otherwise state7, then invokes virtual `ResetPose`.
State254 (`0x00611B49`, 615 bytes) is the held-input charge/launch
sequence. It sets `attackCollisionResult=2` each tick and increments
`field313c` while `buttonHeld[0]` is held. Frame2/tick0 clears byte0x2C8
and emits effect0x20 at `(X+facing×60,Y)` with the opposite facing.
Frame5/tick0 resets the frame and latches `field3138` once the charge
counter exceeds30. Horizontal velocity accumulates `horizontalDeceleration`
and clamps at zero; frame5/tick20 uses `-3.0` if the charge flag is still
clear, while frame6/tick0 sets velocity1.5 and deceleration−0.05. At the
frame6 advance it either hands off to state261 when charged, or repositions
at opponentX−facing×60; normal animation completion faces the opponent and
resets the pose.

State255 (`0x00611DB0`, 739 bytes) is the alternate held-input charge
and aerial launch. It sets `attackCollisionResult=2` each tick and counts
`buttonHeld[1]` in `field313c`. Frame2/tick0 clears byte0x2C8 and emits
effect0x20 at integer-truncated `(X+facing×60,Y)` with opposite facing.
Frame5/tick0 calls `ResetFrame`; charge above30 latches `field3138=1`.
Horizontal velocity accumulates deceleration and clamps at zero. At
frame5/tick20, an uncharged branch positions X at opponentX−facing×180.
Frame6/tick0 sets velocity1.5 and deceleration−0.05. On frame6 advance,
a charged launch enters state0x106, positions X at opponentX−facing×100,
clamps to540/100 for facing±1, and sets Y=−100. Otherwise it clears the
collision result and uses the normal animation-completion FaceOpponent /
ResetPose path. The register-sensitive x87 launch block is emitted with
narrow inline assembly to retain the native instruction order.


State256 (`0x00612093`, 747 bytes) is the aerial special follow-through.
Frame0/tick0 emits effect0x21 at integer-truncated `(X,Y−20)`, starts
trail3, applies the same field3144/field3148 or field0120/field0118 cost
branch, and sets one remaining hit. Frame2/tick0 emits effect0x20 at
`(X+facing×60,Y)`. Frame4 with `attackCollisionResult==2` resets tick and
jumps directly to frame6 (there is no tick==0 requirement). Otherwise
frame5/tick0 calls `ResetFrame`; horizontal velocity accumulates
`horizontalDeceleration` and clamps at zero, frame5/tick20 sets velocityX
8.0, and frame6/tick0 sets velocityX 3.5 plus horizontalDeceleration
−0.05. Each frame advance clears the collision result only when the new
frame is below2; animation completion faces the opponent and resets pose.


State257 (`0x0061237E`, 491 bytes) is the special-effect follow-through.
It sets `attackCollisionResult=2` each tick and calls `ResetFrame` at
frame0/tick0. At frame2/tick0 it chooses the local effect from
`field3144`: value4 spends1000 from `field3148` (clamped at zero) and emits
effect0x1A8 at integer-truncated `(X+facing×80,Y)`; otherwise it sets
`field3144=2` and emits effect0x19C at `(X+facing×40,Y)`. Both local effects
use owner1, group2, current facing and layer1. Every frame advance sets
`attackCollisionResult=3`; at animation completion it clears state, calls
the virtual ResetPose slot, and faces the opponent. The two cost/effect
arms and the final frame-counter/virtual-reset sequence use narrow inline
assembly to preserve the native VC7.1 register and instruction order.


State258 (`0x00612569`, 494 bytes) is the wider local-effect follow-through.
It sets `attackCollisionResult=2` each tick and calls `ResetFrame` at
frame0/tick0. At frame2/tick0, `field3144==4` spends1000 from
`field3148` (clamped at zero) and emits local effect0x1A8 at
integer-truncated `(X+facing×160,Y)`; otherwise it sets `field3144=2` and
emits effect0x19C at `(X+facing×120,Y)`. Both effects use owner1, group2,
current facing and layer1. Every frame advance sets
`attackCollisionResult=3`; animation completion clears state, invokes the
virtual ResetPose slot and faces the opponent. The state is expressed in
narrow inline assembly so both local-effect branches, the frame counter,
and the virtual reset retain the native instruction/register sequence.


State259 (`0x00612757`, 501 bytes) is the longest local-effect variant in
this sequence. It sets `attackCollisionResult=2` each tick and calls
`ResetFrame` at frame0/tick0. At frame2/tick0, `field3144==4` spends1000
from `field3148` (clamped at zero) and emits local effect0x1A8 at
integer-truncated `(X+facing×240,Y)`; otherwise it sets `field3144=2` and
emits effect0x19C at `(X+facing×200,Y)`. Both effects use owner1, group2,
current facing and layer1. Every frame advance sets
`attackCollisionResult=3`; animation completion clears state, invokes the
virtual ResetPose slot and faces the opponent. The source preserves the
native branch order, x87 integer conversions and frame-counter sequence.


State260 (0x0061294C, 674 bytes) initializes an aerial capture and two
effects on frame0/tick0. It zeroes both velocities, sets byte0x2C8 to5,
initializes field3148=10000, field314c=1, and field3150=1, then emits
global effect0x1F at integer-truncated (X,Y) with facing flag facing==-1.
It next emits local effect0x191 at integer-truncated (X,Y−17):
field3140==1 offsets X by facing×60, while value2 offsets by −facing×60;
either path clamps X to40–600. The local effect uses owner1, group2,
current facing and layer1. Every frame advance clears the collision
result; animation completion clears state, invokes virtual ResetPose and
faces the opponent.


State261 (`0x00612BEE`, 239 bytes) initializes horizontal deceleration to
2.0 and sets one remaining hit on frame0/tick0. After frame6 it subtracts
0.055 from horizontal deceleration and clamps the result at zero. Every
frame advance increments the frame; when the new frame is1 it clears the
collision result. At animation completion it clears the state, faces the
opponent, and invokes virtual ResetPose.


State262 (`0x00612CDD`, 288 bytes) initializes velocityX=1.0,
velocityY=0.0 and one remaining hit on frame0/tick0. After frame2 it
adds gravity0.035 to velocityY. If positionY+velocityY is still above
zero and the frame is below12, it jumps to frame12, clears tick, sets
positionY=0 and calls ResetFrame. Otherwise it advances the normal frame
counter and clears the collision result on each advance. Animation
completion clears state, faces the opponent and invokes virtual ResetPose.


State263 (`0x00612DFD`, 403 bytes) calls ResetFrame at frame0/tick0.
At frame3/tick0 it sets field3144=2 and byte0x2C8=5, emits global
effect0x1F at integer-truncated (X,Y) with facing flag facing==-1, then
emits local effect0x1AC at integer-truncated (X,Y−20) using owner1,
group2, current facing and layer1. Every frame advance sets
attackCollisionResult=3; animation completion clears state, invokes virtual
ResetPose and faces the opponent.


State264 (`0x00612F90`, 403 bytes) repeats the state263 capture sequence
with local effect0x1AD instead of 0x1AC. It calls ResetFrame at frame0/
tick0; frame3/tick0 sets field3144=2 and byte0x2C8=5, emits global
effect0x1F at integer-truncated (X,Y), then local effect0x1AD at
integer-truncated (X,Y−20) using owner1, group2, current facing and layer1.
Every frame advance sets attackCollisionResult=3; animation completion
clears state, invokes virtual ResetPose and faces the opponent.


State265 (`0x00613123`, 658 bytes) initializes a charge capture at
frame0/tick0. It emits global effect0x21 at integer-truncated `(X,Y−40)`
with palette0x0B, group2 and layer1, then starts trail3. If `field3144==4`
it spends1000 from `field3148` and clamps at zero; otherwise it subtracts
500.0 or250.0 from `field0118` according to `field0120`. At frame3/tick0
it sets `field3144=2` and byte0x2C8=5, emits global effect0x1F at `(X,Y)`
with facing flag `facing==-1`, then local effect0x1AE at `(X,Y−20)` using
owner1, group2, current facing and layer1. Every frame advance sets
`attackCollisionResult=3`; animation completion clears state, invokes
virtual ResetPose and faces the opponent. The two x87 resource constants
are pinned to original absolute addresses 0x787C30 (500.0) and 0x787C70
(250.0), with both original data values independently checked.


State266 (`0x006133B5`, 315 bytes) sets `attackCollisionResult=2` each
tick and calls ResetFrame at frame0/tick0. At frame3/tick0 it sets
`field3144=2` and emits local effect0x1B0 at integer-truncated
`(X+facing×80,Y−20)` using owner1, group2, current facing and layer1.
Every frame advance sets `attackCollisionResult=3`; animation completion
clears state, invokes virtual ResetPose and faces the opponent.


State267 (`0x006134F0`, 322 bytes) repeats state266's effect0x1B0
follow-through with a wider horizontal offset. It sets
`attackCollisionResult=2` each tick, calls ResetFrame at frame0/tick0,
and at frame3/tick0 sets `field3144=2` and emits local effect0x1B0 at
integer-truncated `(X+facing×160,Y−20)` using owner1, group2, current
facing and layer1. Its longer `imul` and near conditional branch retain
the native instruction widths. Every frame advance sets
`attackCollisionResult=3`; animation completion clears state, invokes
virtual ResetPose and faces the opponent.


State268 (`0x00613632`, 322 bytes) repeats the effect0x1B0 follow-through
with a 240-pixel horizontal offset. It sets `attackCollisionResult=2` each
tick, calls ResetFrame at frame0/tick0, and at frame3/tick0 sets
`field3144=2` and emits local effect0x1B0 at integer-truncated
`(X+facing×240,Y−20)` using owner1, group2, current facing and layer1.
Every frame advance sets `attackCollisionResult=3`; animation completion
clears state, invokes virtual ResetPose and faces the opponent.


State269 (`0x00613774`, 176 bytes) zeroes horizontal and vertical
velocity on frame0/tick0 and sets byte0x2C8 to5. Each frame advance clears
`attackCollisionResult` to zero; animation completion clears state, invokes
virtual ResetPose and faces the opponent. Both x87 zero constants are
pinned to original address 0x7872F8 and checked against the original data.


State303 (`0x00613824`, 763 bytes) is a multi-stage aerial capture throw.
At frame0/tick0 it zeroes three movement fields. Frame2 applies horizontal
shake `(50,3)`; frame2/tick0 sets field0x16C=1 and field0x14C=120,
subtracts1000 from field0x148, applies tint0xB0 for3 ticks, and emits
global effect0x44 at integer-truncated `(X,Y−40)` with palette0x13,
group2 and layer1. Frame4/tick0 clears byte0x2C8. Frame8/tick0 sets
velocityX=5.0; frame9/tick0 sets velocityX=1.8 and horizontal
acceleration−0.05. After frame8 it integrates that acceleration and clamps
velocityX at zero. At frame8, collision result2 or5 resets tick and advances
to frame9; result3 sets opponent hitstop9999, resets both poses, sets the
opponent to Y=0/state0x6C and the owner to state0x132. Frames1–17 retain
the horizontal shake. Frame advances clear collision result; animation
completion clears state and invokes virtual ResetPose.

State304 (`0x00613B1F`, 763 bytes) is the alternate capture-throw variant.
It shares state303's frame gates and collision-result branches, but
subtracts2000 from field0x148, emits effect0x45 with palette0x05, starts
frame8 at velocityX=7.0, and hands the owner to state0x133 on a successful
frame8 hit. It retains frame9 velocityX=1.8, acceleration−0.05, the
zero-floor integration, opponent hitstop9999 and opponent state0x6C.
Both 763-byte states match all 212 native x86 instructions, and their
absolute 0.0/5.0/7.0/1.8/−0.05 operands are pinned to original PE data.


State305 (`0x00613E1A`, 940 bytes) is the aerial capture that branches into
a two-effect throw. Frame0/tick0 calls ResetFrame. Frame2/tick0 zeroes
three movement fields, sets field0x16C=1 and field0x14C=120, subtracts
3000 from field0x148, applies tint0xB0 for3 ticks, and emits global
effect0x46 at integer-truncated `(X,Y−40)` with palette0x40, group2 and
layer1. It also sets byte0x2C9=0x25. Frames above1 call
`Context::SetSceneTimer(15)`; frames below3 apply horizontal shake
`(50,3)`. Frame4/tick0 clears byte0x2C8. Frame8/tick0 sets velocityX=10.0
and one remaining hit; frame9/tick0 sets velocityX=1.8 and horizontal
acceleration−0.05, which is integrated after frame8 with a zero floor.
At frame8, collision result2 or5 advances to frame9; result3 sets opponent
hitstop9999, resets both poses, sets opponent Y=0/state0x6C and owner
state0x134, then emits local effects0x1A3 at `(0,20)` and0x1A4 at `(0,38)`
with owner1 and layer1. Frame advances clear collision result; animation
completion clears state and invokes virtual ResetPose. The 10.0, 1.8,
−0.05, 20.0 and38.0 operands are pinned to original PE data.


State306 (`0x006141C6`, 755 bytes) is a multi-loop aerial throw with
opponent repositioning. Frame0/tick0 sets velocityX=0.3, places the owner
at `opponentX+facing×30`, and clears attackCollisionResult. Frame9/tick0
adds the original zero constant to owner X and sets velocityX=0. Frame11/
tick0 sets byte0x2C9=0x14; frame15/tick0 sets byte0x2C8=2. At frame15/
tick90 it puts the opponent in state0x47, clears opponent hitstop, sets
opponent fields0xC0=0 and0xC8=−4.0, sets attackCollisionResult=2, applies
`ApplyDamage(2400,400.0)`, and emits effect0x34 at `(opponentX,
opponentY−40)` with palette0x16, group2 and layer1. Frames1–14 apply
horizontal shake `(50,10)`. On frame advances, frame6 loops backward by2
while field0x3138 is below9; frame9 adds `facing×80` to owner X and clears
the loop counter; frame13 loops backward by2 while the counter is below12.
Animation completion clears state, faces the opponent and invokes virtual
ResetPose. All 208 native instructions match.


State307 (`0x006144B9`, 836 bytes) is the looping variant of state306.
Frame0/tick0 clears field0x3138, sets velocityX=0.3, places owner X at
`opponentX+facing×30`, and clears attackCollisionResult. Frame9/tick0 adds
zero to owner X and sets velocityX=0. Frame11/tick0 sets byte0x2C9=0x14;
frame14/tick0 sets byte0x2C8=2. At frame15/tick0, only when field0x3138
is exactly7, it puts the opponent in state0x47, clears opponent hitstop,
sets opponent fields0xC0=0 and0xC8=−4.0, sets attackCollisionResult=2,
applies `ApplyDamage(3200,400.0)`, and emits effect0x34 at
`(opponentX,opponentY−40)` with palette0x16, group2 and layer1. Frames1–14
apply horizontal shake `(50,10)`. Frame6 loops back to4 while the counter
is below9; frame9 adds `facing×80` to owner X and clears the counter; frame13
loops back to11 while the counter is below12; frame14 latches the counter
at12. At animation completion, a nonzero counter loops back two frames
and decrements; only a zero counter clears state and invokes virtual
ResetPose. All 225 native instructions match.


State308 (`0x006147FD`, 877 bytes) is the higher-damage, meter-scaled
hitstun variant of state307. It preserves the frame0 repositioning, frame9
velocity stop, frame11/14 setup, frames1–14 horizontal shake and the
field0x3138-driven frame6/9/13/14 loops. At frame15/tick0, only when
field0x3138==7, it puts the opponent in state0x47, clears opponent hitstop,
sets opponent fields0xC0=0 and0xC8=−4.0, sets attackCollisionResult=2,
applies `ApplyDamage(4500,400.0)`, then calculates opponent field0x124 as
`ftol2(200.0 × field0x178 / 10000.0)`. It emits effect0x34 at
`(opponentX,opponentY−40)` with palette0x16, group2 and layer1. The
looping animation only clears state and invokes virtual ResetPose after
field0x3138 reaches zero. All 234 native instructions match.


State309 (`0x00614B6A`, 518 bytes) is a triple-effect capture with a
frame-6 hitstun loop. Every invocation applies horizontal shake `(50,3)`.
At frame0/tick0 it sets byte0x2C8=3, calls ResetFrame, sets field0x14C=120,
subtracts3000 from field0x148, applies tint0xB0 for3 ticks, and emits global
effects0x46 and0x47 at integer-truncated `(X,Y−40)` with palette0x40,
group2 and layer1. It then sets byte0x2C9=0x25 and emits local effect
0x1AB at `(X+facing×20,0)` using owner1, current facing, group2 and layer1.
On frame advance, frame6 loops back four frames while field0x14C remains
positive and increments field0x3138. Animation completion clears state
and invokes the native virtual reset. All 133 native instructions match.


State312 (`0x00614D70`, 851 bytes) is the scaled-damage looping throw
variant of states307/308. Frame0/tick0 clears field0x3138, sets velocityX
0.3, places owner X at `opponentX+facing×30`, and clears
attackCollisionResult. Frame9/tick0 sets velocityX=0; frame11/tick0 sets
byte0x2C9=0x14; frame14/tick0 sets byte0x2C8=2. At frame15/tick0, only
when field0x3138==7, it puts the opponent in state0x47, clears opponent
hitstop, sets opponent X=0 and Y=−8.0, sets attackCollisionResult=2,
applies `ApplyDamage(4200,750.0)`, then writes opponent field0x124 as
`ftol2(200.0×comboDamageScale/10000.0)`. It emits effect0x34 at
`(opponentX,opponentY−40)` with palette0x16, group2 and layer1. Frames1–14
apply horizontal shake `(50,10)`. Frame6 loops back to4 while the counter
is below9; frame9 adds `facing×80` to owner X and clears the counter;
frame13 loops back to11 while the counter is below12; frame14 latches12.
At animation completion, a nonzero counter loops back two frames and
decrements; only zero clears state and invokes virtual ResetPose. All 230
native instructions match.


States315 and316 (`0x006150C3` and `0x0061519F`, 220 bytes each) are
separate zero-velocity hitstun-recovery variants. Both zero velocityX and
velocityY at frame0/tick0, clear field0x3148 at frame1/tick0, and advance
the native frame/tick counters. At animation completion, if field0x3144==1
they reset the frame to0 and return while retaining the current state;
otherwise they clear the state and invoke the native virtual reset. Their
register allocation and shared-return trampoline bytes differ, so both
blocks are independently reconstructed and checked: 61 native
instructions each.


State317 (`0x0061527B`, 220 bytes) is the third zero-velocity hitstun
recovery variant. It zeros velocityX/Y at frame0/tick0, clears field0x3148
at frame1/tick0, and advances frame/tick counters. At animation completion,
field0x3144==1 resets frame to0 and returns while retaining the current
state; otherwise it clears state and invokes the native virtual reset.
Its register allocation and shared-return trampoline are distinct from
315/316. All 61 native instructions match.

State318 (`0x00615357`, 468 bytes) is a two-effect aerial hitstun launch.
Frame0/tick0 zeros velocityX/Y. Frame3/tick0 sets field0x14C=120,
subtracts1000 from field0x148, applies tint0xB0 for3 ticks, and emits global
effect0x44 at integer-truncated `(X−facing×13,Y−51)` with palette0x13,
group2 and layer1. It then emits local effect0x1B6 at `(X,Y−15)` with
owner1, current facing, group2, layer0 and lifetime300, and sets
field0x3144=2. Animation completion clears state and invokes the native
virtual reset. All 120 native instructions match.


State319 (`0x0061552B`, 158 bytes) is a simple aerial recovery reset.
At frame0/tick0 it zeros velocityX and velocityY. It then advances the
native tick/frame counters; when animation completes it clears the state
and invokes the native virtual reset. All 45 native instructions match.


State320 (`0x006155C9`, 468 bytes) is the alternate-cost/effect variant
of state318. Frame0/tick0 zeros velocityX/Y. Frame3/tick0 sets
field0x14C=120, subtracts2000 from field0x148, applies tint0xB0 for3 ticks,
and emits global effect0x45 at integer-truncated `(X−facing×13,Y−51)`
with palette0x05, group2 and layer1. It then emits local effect0x1BA at
`(X,Y−15)` with owner1, current facing, group2, layer0 and lifetime300,
and sets field0x3144=2. Animation completion clears state and invokes the
native virtual reset. All 120 native instructions match.


Focused canonical selected-prefix check:

```bash
scripts/repo-python workbench/character04-state/check_prefix.py
```

It verifies **15,537 original x86 instruction widths/positions and
register-abstracted forms**, **1,378 original internal +181 native
shared-return branch targets**, **1,063 independently original-bound
COFF call/IEEE-754 references**, and two original local dispatch
addresses. The only explicit differences are the provisional six-byte
stack immediate (`0x1C8` vs native `0x2E8`), ten low bytes of the
frame-6/launch x87 integer-conversion scratch-slot displacements (native
slots `EBP-0x1BC` through `EBP-0x1CC`, provisional slots shifted by four
bytes), shared-return routing (including the verified in-prefix return
trampoline), and original-bound COFF fields. No arbitrary branch-target
differences or source padding are accepted.

**Next live native state321 starts `0x0061579D`**. The remaining
5 original live case bodies, full stack, 139-entry jump table,
325 selector bytes and shared return remain OPEN. This certificate
is **selected-prefix only, NOT whole Exact**; no all-unit cold replay.
