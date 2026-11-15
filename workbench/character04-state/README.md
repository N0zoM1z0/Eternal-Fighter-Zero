# Character04::Slot06 — original-bound 59,143-byte state boss

**PARTIAL: not whole-function Exact.** Authored C++ (with narrowly
scoped VC7.1 inline assembly for register-sensitive x87 code) covers
the original default and **105 genuine live cases**: 1–9,13–16,
47,50–77,81–87,96–99,150–158,161–171,180,200–216,220–221,
230–232,240–241,249–255. The other **33** native live case IDs remain OPEN.
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

The original code `[0x00607930,0x00612093)` now has **42,851
original executable bytes**, canonical SHA-256
`56a0be7f803fb0ccdba22532b829e0aed63bcd2a56b26d03bc79e31c4efb08b5`.
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


Focused canonical selected-prefix check:

```bash
scripts/repo-python workbench/character04-state/check_prefix.py
```

It verifies **11,761 original x86 instruction widths/positions and
register-abstracted forms**, **1,064 original internal +142 native
shared-return branch targets**, **921 independently original-bound
COFF call/IEEE-754 references**, and two original local dispatch
addresses. The only explicit differences are the provisional six-byte
stack immediate (`0x1B8` vs native `0x2E8`), the two low bytes of the
frame-6 x87 scratch-slot displacements (`EBP-0x1BC` native vs
`EBP-0x1B8` provisional), shared-return routing (including the single
verified in-prefix jump trampoline), and original-bound COFF fields.
No arbitrary branch-target differences or source padding are accepted.

**Next live native state256 starts `0x00612093`**. The remaining
33 original live case bodies, full stack, 139-entry jump table,
325 selector bytes and shared return remain OPEN. This certificate
is **selected-prefix only, NOT whole Exact**; no all-unit cold replay.
