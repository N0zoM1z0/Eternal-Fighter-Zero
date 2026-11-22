// Natural-C++ reconstruction of Kanna's long multi-phase super state 0x73.
// The native state includes opponent hitstop/KO control and multiple local effects.
#include "CharacterViews.h"
























// Shared input recovery used by native selector cases 0x0b-0x11.
// Return nonzero when the original case returns early after changing state.


// Cases 0x0b-0x11 are seven variants of the same airborne motion.
// The native switch differs only in launch frame, initial velocity and
// whether vertical acceleration reads gravity or the fixed 0.01 constant.



// Shared counter-movement sequence for native selector cases 0x13-0x17.



// Shared hit-knockback fall sequence for native selector cases 0x1c-0x1f.
// Natural-C++ reconstruction of the 0x0040ff70 opponent-range predicate.
// The native helper returns zero only while the two characters are within
// 280 units and both have the required 20-unit stage-edge clearance.
int Character19::Slot06OpponentWithinKnockbackRange()
{
    double opponentX = (*opponentSlot)->positionX;
    double leftEdgeAdjustment = (opponentX <= 20.0) ? 1.0 : 0.0;
    if (!(leftEdgeAdjustment < positionX - 20.0)) {
        return 0;
    }
    if (opponentX - positionX > 280.0) {
        return 0;
    }

    double rightEdgeLimit = 639.0 - ((opponentX >= 619.0) ? 1.0 : 0.0);
    if (!(rightEdgeLimit > positionX + 20.0)) {
        return 0;
    }
    if (positionX - opponentX > 280.0) {
        return 0;
    }
    return 1;
}




// Follow-up knockback landing path for native selector cases 0x25 and 0x26.
void Character19::Slot06UpdateKnockbackLanding(
    unsigned short frameDuration,
    unsigned short frameCount,
    int interruptOutsideRange)
{
    if (field0120 != 0) {
        field0118 = field0118 - 1.5;
    }

    meter = meter + 3;
    velocityX = knockbackVelocityX;
    velocityY = knockbackVelocityY;
    field000c = field000c + 1;

    if (interruptOutsideRange && !Slot06OpponentWithinKnockbackRange()) {
        field0008 = 0x46;
        ResetPose();
        return;
    }

    if (frameDuration <= field000c) {
        field000c = 0;
        field000a = field000a + 1;
        if (frameCount <= field000a) {
            field000a = field000a - 2;
        }
    }

    if ((positionY + velocityY) >= 0.0) {
        positionY = 0.0;
        if (knockdownOnLanding == 0) {
            field0008 = 0x62;
        } else {
            field0008 = 0x61;
        }
        ResetPose();
    }
}


// Shared end-of-recovery transition for native selector cases 0x29-0x2b.



// Three native recovery skids share the same horizontal braking sequence.



// Airborne recoil with the native local type-499 hit effect (selector 0x2f).



// Repeated airborne knockback loop for native selector case 0x30.



// Airborne rebound/slide sequence shared by native selectors 0x31 and 0x32.



// Shared airborne knockback landing for native selector cases 0x33 and 0x34.



// Local effect 0x1ef and short animation recovery (selector 0x35).
void Character19::Slot06UpdateLocalEffectRecovery(
    unsigned short frameDuration,
    unsigned short frameCount,
    SecondaryEffectSpawn *spawn)
{
    if ((field000a == 0) && (field000c == 0)) {
        spawn->type = 0x1ef;
        spawn->x = 60.0;
        spawn->y = 40.0;
        spawn->payload = 1;
        spawn->flag0018 = 1;
        spawn->group = 0;
        spawn->layer = 0;
        EmitLocalEffect(spawn);
    }

    field000c = field000c + 1;
    if (frameDuration <= field000c) {
        field000c = 0;
        field000a = field000a + 1;
        if (frameCount <= field000a) {
            field0008 = 0;
            ResetPose();
        }
    }
}

// Brief face-opponent recovery with an input-dependent landing state (0x36).
void Character19::Slot06UpdateFaceRecovery(
    unsigned short frameDuration,
    unsigned short frameCount)
{
    field000c = field000c + 1;
    if (frameDuration <= field000c) {
        field000c = 0;
        field000a = field000a + 1;
        if (field000a == frameCount - 1) {
            FaceOpponent();
        }
        if (frameCount <= field000a) {
            field0008 = 7;
            if (inputY == 1) {
                field0008 = 3;
            }
            ResetPose();
        }
    }
}

// Defeat-impact transition with a camera shake and a context-owned effect (0x37).
void Character19::Slot06UpdateDefeatImpact(
    unsigned short frameDuration,
    unsigned short frameCount,
    EffectSpawn *spawn)
{
    velocityX = 0.0;
    velocityY = 0.0;
    if ((field000a == 0) && (field000c == 0)) {
        SetVerticalShake(3, 0);
        spawn->type = 3;
        spawn->x = (double)(int)positionX;
        spawn->y = (double)(int)positionY;
        spawn->group = 2;
        spawn->layer = 0;
        contextOwner->EmitEffect(spawn);
        pendingContextSoundSlot = 7;
    }

    field000c = field000c + 1;
    if (frameDuration <= field000c) {
        field000c = 0;
        field000a = field000a + 1;
        if (frameCount <= field000a) {
            field0008 = 99;
            ResetPose();
        }
    }
}


// Post-impact defeat wait; transitions to the standing recovery state 0x60.
void Character19::Slot06UpdateDefeatWait(
    unsigned short frameDuration,
    unsigned short frameCount)
{
    if ((health > 0) && (field000c > 60) && (field000a == 0)) {
        field0008 = 0x60;
        ResetPose();
        dashMomentumFlag = 0;
    }

    field000c = field000c + 1;
    if (frameDuration <= field000c) {
        field000c = 0;
        field000a = field000a + 1;
        if (field000a == frameCount) {
            FaceOpponent();
        }
        if (frameCount <= field000a) {
            field0008 = 0x60;
            ResetPose();
        }
    }
}


// Shared horizontal recovery/braking for native selectors 0x3a-0x3d.
// Trail-assisted airborne bounce/recovery for native selectors 0x43 and 0x44.



// Long airborne follow-up/counter state machine shared by selectors 0x45/0x46.



// Defeat-impact sequence with a one-frame tint and two context effects (0x47).



// Paired type-8 knockback impact finishers (selectors 0x48/0x49).
void Character19::Slot06UpdateKnockbackImpactFinish(
    unsigned short frameDuration,
    unsigned short frameCount,
    EffectSpawn *spawn,
    unsigned short completionState)
{
    if ((field000a == 0) && (field000c == 0)) {
        dashMomentumFlag = 0;
        ResetFrame();
        positionY = 0.0;
        guardInputFrames = 0;

        spawn->type = 8;
        spawn->x = (double)(int)positionX;
        spawn->y = (double)(int)positionY;
        spawn->group = 2;
        spawn->layer = 1;
        contextOwner->EmitEffect(spawn);
    }

    field000c = field000c + 1;
    if (frameDuration <= field000c) {
        field000c = 0;
        field000a = field000a + 1;
        if (field000a == frameCount) {
            FaceOpponent();
        }
        if (frameCount <= field000a) {
            field0008 = completionState;
            ResetPose();
        }
    }
}


// Airborne hitstun release with scaled velocity restoration (selector 0x4a).


// Defeat impact flash followed by restoration of the stored launch velocity (0x4b).



// Horizontal dash recovery with the native down-input cancel window (selector 0x4c).
void Character19::Slot06UpdateDashRecovery(
    unsigned short frameDuration,
    unsigned short frameCount)
{
    velocityX = velocityX - 0.03;
    if (velocityX < 0.0) {
        velocityX = 0.0;
        dashMomentumFlag = 0;
    }

    if ((inputY == -1) && (field000a != 0) && (field015c < 3)) {
        field0008 = 4;
        if (inputX == facing) {
            field0008 = 5;
        }
        if (inputX == -facing) {
            field0008 = 6;
        }
        attackCollisionResult = 0;
        ResetPose();
    } else {
        field000c = field000c + 1;
        if (frameDuration <= field000c) {
            field000c = 0;
            field000a = field000a + 1;
            if (frameCount <= field000a) {
                field0008 = 0;
                ResetPose();
            }
        }
    }
}


// Shared dash-attack follow-through, hit-cancel and local-effect sequencing for selectors 0x4d-0x51.







// Airborne follow-up family with both down-cancel and neutral-horizontal follow-up routes.



// Multi-phase aerial launch: hold at phase 4 until the phase-5 ground test succeeds.


// Ground dash follow-up with a down-input cancel window and a late meter event.



// Repeating aerial ground-slam: collision can force the D5 exit; landing emits
// the context-owned impact effect and transitions to D6.


// Short descending aerial kickback with fixed launch velocity and gravity.
void Character19::Slot06UpdateAerialKickback(
    unsigned short frameDuration,
    unsigned short frameCount)
{
    gravity = 0.042;
    velocityY = velocityY + gravity;

    if ((field000a == 0) && (field000c == 0)) {
        velocityX = -1.0;
        velocityY = -2.4;
    }

    field000c = field000c + 1;
    if (frameDuration <= field000c) {
        field000c = 0;
        field000a = field000a + 1;
        attackCollisionResult = 0;
        if (frameCount <= field000a) {
            field0008 = 9;
            ResetPose();
        }
    }
}

// Stationary ground impact with camera shake and a one-shot context effect.



// Opponent capture impact: on the confirmed hit, reset both fighters, lock the
// opponent's air actions, and emit the native type-0 scene effect.


// Multi-frame opponent stage combo. All opponent repositioning is tied to
// animation-frame boundaries; damage is applied at frame 4 before that frame
// advances, matching the native 0x4e2 / 750.0 damage request.



// Trail-backed dash finishers 0x5e/0x5f share movement and frame timing; only
// the frame-2 meter/sound event differs.



// Trail-backed dash strike with a frame-3 speed burst and sustained 0.07 decay.


// Trail-backed airborne dash: frame 3 launches, then gravity runs until a
// strict ground crossing moves the animation to its terminal frame 15.



// Stun/effect recovery: configure the short invulnerability and guard windows,
// then emit the native palette-0x13 context effect on the opening frame.


// Frame-4 impact pair: a context-owned flash followed by the character-local
// 0x194 strike effect, with the meter and character-sound request in between.


// Combo impact burst with a one-time trail capture, combo-scale decay and
// three distinct effect timings (opening context, frame-2 local, frame-4 pair).


// Damped impact finish: attenuate the launch once, then cap positive vertical
// drift while the frame-4 meter/effect event completes the animation.



// Looping aerial bounce. A confirmed ground crossing exits to the native
// landing state 0x103; otherwise frame 3 re-launches and the animation loops.


// The combo version adds a one-shot context burst, a frame-1 local marker,
// and a five-cycle launch loop driven by the two persistent Character19 counters.


// Short face/pose transition: no extra setup, just the native animation timer.
void Character19::Slot06UpdateFinalFaceTransition(
    unsigned short frameDuration,
    unsigned short frameCount)
{
    field000c = field000c + 1;
    if (frameDuration <= field000c) {
        field000c = 0;
        field000a = field000a + 1;
        attackCollisionResult = 0;
        if (frameCount <= field000a) {
            field0008 = 3;
            FaceOpponent();
            ResetPose();
        }
    }
}

// Three finishers share the same local-effect setup and timer. Their only
// native difference is the effect resource: 0x190, 0x191 or 0x192.



// Two-stage local-effect finisher: distinct frame-7 and frame-8 resources,
// with meter and character sound coupled only to the second burst.


// Trail-backed final burst: the opening context flash is unowned (the native
// zero-initialized spawn record), while the frame-7 local effect belongs to us.
