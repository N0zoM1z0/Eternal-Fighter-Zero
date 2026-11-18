// Natural-C++ reconstruction of Kanna's long multi-phase super state 0x73.
// The native state includes opponent hitstop/KO control and multiple local effects.
#include "CharacterViews.h"
























// Shared input recovery used by native selector cases 0x0b-0x11.
// Return nonzero when the original case returns early after changing state.
int Character19::Slot06TryAirAction()
{
    if ((inputY == -1) && (field015c < 3) && (airActionCount < 2)) {
        airActionCount = airActionCount + 1;
        field0008 = 0x0e;
        if (inputX == facing) {
            field0008 = 0x0f;
        }
        if (inputX == -facing) {
            field0008 = 0x10;
        }
        attackCollisionResult = 0;
        ResetPose();
        return 1;
    }

    if (inputY == 1) {
        field0008 = 9;
        ResetPose();
        if (airActionCount > 1) {
            return 1;
        }
        if (inputX == 0) {
            return 1;
        }
        if (field015c > 2) {
            return 1;
        }

        airActionCount = airActionCount + 1;
        if (inputX == facing) {
            field0008 = 0x12;
        }
        if (inputX == -facing) {
            field0008 = 0x14;
        }
        attackCollisionResult = 0;
        ResetPose();
        return 1;
    }

    if ((airActionCount < 2) && (field015c < 3)) {
        if (inputX == facing) {
            field0008 = 0x11;
            airActionCount = airActionCount + 1;
            ResetPose();
            attackCollisionResult = 0;
            return 1;
        }
        if (inputX == -facing) {
            field0008 = 0x13;
            airActionCount = airActionCount + 1;
            ResetPose();
            attackCollisionResult = 0;
            return 1;
        }
    }

    return 0;
}

// Cases 0x0b-0x11 are seven variants of the same airborne motion.
// The native switch differs only in launch frame, initial velocity and
// whether vertical acceleration reads gravity or the fixed 0.01 constant.
void Character19::Slot06UpdateAirMovement(
    unsigned short frameDuration,
    unsigned short frameCount,
    unsigned short launchFrame,
    double launchVelocityX,
    double launchVelocityY,
    unsigned short accelerationStartFrame,
    int fixedAcceleration)
{
    if ((field000a == 0) && (field000c == 0)) {
        velocityX = 0.0;
        velocityY = 0.0;
    }

    field3140 = field3140 + 1;
    if (field3148 < field3140) {
        if (Slot06TryAirAction()) {
            return;
        }
    }

    if ((field000a == launchFrame) && (field000c == 0)) {
        gravity = 0.045;
        velocityY = launchVelocityY;
        velocityX = launchVelocityX;
        reinterpret_cast<unsigned char *>(&soundSlots[49])[0] = 0;
    }

    if (field000a > accelerationStartFrame) {
        if (fixedAcceleration) {
            velocityY = velocityY + 0.01;
        } else {
            velocityY = velocityY + gravity;
        }
    }

    field000c = field000c + 1;
    if (frameDuration <= field000c) {
        field000c = 0;
        field000a = field000a + 1;
        if (frameCount <= field000a) {
            field0008 = 10;
            ResetPose();
        }
    }

    if ((positionY + velocityY >= 0.0) && (field000a > 3)) {
        positionY = 0.0;
        reinterpret_cast<unsigned char *>(&soundSlots[49])[1] = 9;
        FaceOpponent();
        field0008 = 0x0d;
        ResetPose();
    }
}


// Shared counter-movement sequence for native selector cases 0x13-0x17.
void Character19::Slot06UpdateCounterMove(
    unsigned short frameDuration,
    unsigned short frameCount,
    short meterGain,
    double launchScale,
    double fieldDecay,
    int forceStandingState)
{
    if (field0120 != 0) {
        field0118 = field0118 - 0.6;
    }
    dashMomentumFlag = 0;

    if ((field000a == 0) && (field000c == 0)) {
        meter = meter + meterGain;
        velocityX = (2.0 - (*opponentSlot)->comboDamageScale / 10000.0) *
                    launchScale;
        if (field0120 != 0) {
            field0118 = field0118 - fieldDecay;
        }
    }

    velocityY = 0.0;
    positionY = 0.0;
    velocityX = velocityX + 0.06;
    if (velocityX > 0.0) {
        velocityX = 0.0;
    }

    if (((positionX - 20.0 <= 0.0) || (639.0 <= positionX + 20.0))) {
        outgoingPushbackVelocityX =
            (1.0 - (double)(positionY < 0.0) * 0.2) * velocityX;
    } else {
        outgoingPushbackVelocityX = 0.0;
    }

    field000c = field000c + 1;
    if (frameDuration <= field000c) {
        field000c = 0;
        field000a = field000a + 1;
        if (frameCount <= field000a) {
            if (forceStandingState) {
                field0008 = 3;
            } else {
                field0008 = 0;
                if (inputY == 1) {
                    field0008 = 3;
                }
            }
            ResetPose();
        }
    }
}


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

void Character19::Slot06UpdateKnockbackFall(
    unsigned short frameDuration,
    unsigned short frameCount,
    double minimumVerticalVelocity,
    int clampVerticalVelocity,
    double velocityBlend,
    double gravityValue,
    int interruptOutsideRange)
{
    if (field0120 != 0) {
        field0118 = field0118 - 0.8;
    }

    if (interruptOutsideRange && (field000a != 0) &&
        !Slot06OpponentWithinKnockbackRange()) {
        field0008 = 0x46;
        ResetPose();
        return;
    }

    if ((field000a == 0) && (field000c == 0)) {
        meter = meter + 30;
        velocityX = knockbackVelocityX;
        if (velocityBlend == 0.0) {
            velocityY = knockbackVelocityY;
        } else {
            velocityY = velocityY * velocityBlend + knockbackVelocityY;
        }
        if (clampVerticalVelocity) {
            if (minimumVerticalVelocity <= velocityY) {
                if (-0.5 < velocityY) {
                    velocityY = -0.5;
                }
            } else {
                velocityY = minimumVerticalVelocity;
            }
        }
        gravity = gravityValue;
    }

    if (((velocityY < 0.0) != (velocityY == 0.0)) &&
        (field000a < 2)) {
        field000a = 1;
        field000c = 0;
    }

    if ((0.0 <= velocityY) && (field000a < 2)) {
        field000a = 2;
        field000c = 0;
    }

    velocityY = velocityY + gravity;
    field000c = field000c + 1;
    if (frameDuration <= field000c) {
        field000c = 0;
        field000a = field000a + 1;
        if (frameCount <= field000a) {
            field000a = field000a - 2;
        }
    }

    if (((positionY + velocityY) >= 0.0) && (field000a > 1)) {
        positionY = 0.0;
        if (knockdownOnLanding == 0) {
            field0008 = 0x62;
        } else {
            field0008 = 0x61;
        }
        ResetPose();
    }
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
void Character19::Slot06UpdateGroundRecovery(
    unsigned short frameDuration,
    unsigned short frameCount,
    int forceStandingState)
{
    if (field0120 != 0) {
        field0118 = field0118 - 0.8;
    }

    dashMomentumFlag = 0;
    velocityX = 0.0;
    velocityY = 0.0;

    if ((positionX - 20.0 <= 0.0) || (639.0 <= positionX + 20.0)) {
        outgoingPushbackVelocityX =
            (1.0 - (double)((*opponentSlot)->positionY < 0.0) * 0.25) *
            velocityX;
    } else {
        outgoingPushbackVelocityX = 0.0;
    }

    field000c = field000c + 1;
    if (frameDuration <= field000c) {
        field000c = 0;
        field000a = field000a + 1;
        if (frameCount <= field000a) {
            field0008 = 7;
            if (forceStandingState || (inputY == 1)) {
                field0008 = 3;
            }
            ResetPose();
        }
    }
}


// Three native recovery skids share the same horizontal braking sequence.
void Character19::Slot06UpdateGroundSkid(
    unsigned short frameDuration,
    unsigned short frameCount,
    int forceStandingState)
{
    if (field0120 != 0) {
        field0118 = field0118 - 0.6;
    }

    dashMomentumFlag = 0;
    if ((field000a == 0) && (field000c == 0)) {
        meter = meter + 30;
        if (field0120 != 0) {
            field0118 = field0118 - 30.0;
        }
        velocityX = 2.2;
    }

    velocityY = 0.0;
    positionY = 0.0;
    gravity = 0.0;
    horizontalDeceleration = 0.06;
    velocityX = velocityX - horizontalDeceleration;
    if (velocityX < 0.0) {
        velocityX = 0.0;
    }

    if ((positionX - 20.0 <= 0.0) || (639.0 <= positionX + 20.0)) {
        outgoingPushbackVelocityX =
            (1.0 - (double)((*opponentSlot)->positionY < 0.0) * 0.25) *
            velocityX;
    } else {
        outgoingPushbackVelocityX = 0.0;
    }

    field000c = field000c + 1;
    if (frameDuration <= field000c) {
        field000c = 0;
        field000a = field000a + 1;
        if (frameCount <= field000a) {
            field0008 = 7;
            if (forceStandingState || (inputY == 1)) {
                field0008 = 3;
            }
            ResetPose();
        }
    }
}


// Airborne recoil with the native local type-499 hit effect (selector 0x2f).
void Character19::Slot06UpdateAirKnockback(
    unsigned short frameDuration,
    unsigned short frameCount,
    SecondaryEffectSpawn *spawn)
{
    if (field0120 != 0) {
        field0118 = field0118 - 0.8;
    }

    if ((field000a == 0) && (field000c == 0)) {
        spawn->type = 499;
        spawn->x = (double)(int)positionX;
        spawn->y = (double)(int)positionY;
        spawn->flag0018 = (unsigned char)facing;
        spawn->layer = 1;
        EmitLocalEffect(spawn);

        meter = meter + 30;
        velocityX = knockbackVelocityX;
        velocityY = knockbackVelocityY;
        gravity = 0.032;
    }

    velocityX = velocityX + 0.02;
    velocityY = velocityY + gravity;
    if (velocityX > 0.0) {
        velocityX = 0.0;
    }

    field000c = field000c + 1;
    if (frameDuration <= field000c) {
        field000c = 0;
        field000a = field000a + 1;
        if (frameCount <= field000a) {
            field000a = field000a - 1;
        }
    }

    if (((positionY + velocityY) >= 0.0) && (field000a == 1)) {
        positionY = 0.0;
        if (knockdownOnLanding != 0) {
            field0008 = 0x61;
        } else {
            field0008 = 0x62;
        }
        ResetPose();
    }
}


// Repeated airborne knockback loop for native selector case 0x30.
void Character19::Slot06UpdateRepeatedAirKnockback(
    unsigned short frameDuration,
    unsigned short frameCount)
{
    if (field0120 != 0) {
        field0118 = field0118 - 0.8;
    }

    if ((field000a == 0) && (field000c == 0) && (field3138 == 0)) {
        pendingContextSoundSlot = 0x1e;
        velocityY = -0.45;
        velocityX = -0.1;
        field3138 = field3138 + 1;
        meter = meter + 30;
    }

    if ((field000a == 4) && (field000c == 0)) {
        velocityX = knockbackVelocityX;
        velocityY = knockbackVelocityY;
        gravity = 0.032;
    }

    if ((velocityY > 0.0) && (field000a == 4)) {
        field000a = 5;
        field000c = 0;
    }

    if (field000a > 3) {
        velocityY = velocityY + gravity;
    }

    field000c = field000c + 1;
    if (frameDuration <= field000c) {
        field000c = 0;
        field000a = field000a + 1;
        if ((field000a == 4) && (field3138 < 8)) {
            field000a = 0;
            field3138 = field3138 + 1;
        }
        if (frameCount <= field000a) {
            field000a = field000a - 2;
        }
    }

    if (((positionY + velocityY) >= 0.0) && (field000a > 4)) {
        positionY = 0.0;
        if (knockdownOnLanding != 0) {
            field0008 = 0x61;
        } else {
            field0008 = 0x62;
        }
        ResetPose();
    }
}


// Airborne rebound/slide sequence shared by native selectors 0x31 and 0x32.
void Character19::Slot06UpdateAirborneRebound(
    unsigned short frameDuration,
    unsigned short frameCount,
    SecondaryEffectSpawn *spawn)
{
    if ((field000a == 0) && (field000c == 0)) {
        if (field3144 == 0) {
            spawn->type = 0x1f0;
            spawn->x = (double)(int)positionX;
            spawn->y = (double)(int)positionY;
            spawn->group = 0;
            spawn->layer = 0;
            spawn->owner = 1;
            spawn->flag0018 = (unsigned char)facing;
            EmitLocalEffect(spawn);
            field3144 = 1;
        }

        if (field0120 != 0) {
            field0118 = field0118 - 30.0;
        }
        pendingContextSoundSlot = 0x21;
        velocityY = -1.5;
        velocityX = -0.8;
        meter = meter + 30;
    }

    velocityY = velocityY + 0.04;
    if ((field000a != 0) || ((positionY + velocityY) <= 0.0)) {
        if (field000a == 1) {
            velocityX = velocityX + 0.01;
        }
        if ((field000a == 2) && (field000c == 0)) {
            velocityX = -2.0;
        }
        if (field000a > 1) {
            velocityX = velocityX + 0.06;
        }
        if (velocityX > 0.0) {
            velocityX = 0.0;
        }

        field000c = field000c + 1;
        if (frameDuration <= field000c) {
            field000c = 0;
            field000a = field000a + 1;
            if (frameCount <= field000a) {
                field0008 = 0;
                ResetPose();
                FaceOpponent();
            }
        }
    } else {
        positionY = 0.0;
        velocityY = 0.0;
        field000c = 0;
        field000a = 1;
    }
}


// Shared airborne knockback landing for native selector cases 0x33 and 0x34.
void Character19::Slot06UpdateAirborneKnockbackLanding(
    unsigned short frameDuration,
    unsigned short frameCount,
    SecondaryEffectSpawn *spawn,
    unsigned short soundSlot,
    double verticalAcceleration,
    int gateFirstHit,
    int finishNeutral)
{
    if ((field000a == 0) && (field000c == 0)) {
        if (field3144 == 0) {
            spawn->type = 0x1f0;
            spawn->x = (double)(int)positionX;
            spawn->y = (double)(int)positionY;
            spawn->group = 0;
            spawn->layer = 0;
            spawn->owner = 1;
            spawn->flag0018 = (unsigned char)facing;
            EmitLocalEffect(spawn);
            field3144 = 1;
        }

        if (!gateFirstHit || (field3138 == 0)) {
            if (field0120 != 0) {
                field0118 = field0118 - 30.0;
            }
            pendingContextSoundSlot = soundSlot;
            velocityX = knockbackVelocityX;
            velocityY = knockbackVelocityY;
            meter = meter + 30;
            if (gateFirstHit) {
                field3138 = field3138 + 1;
            }
        }
    }

    velocityY = velocityY + verticalAcceleration;
    field000c = field000c + 1;
    if (frameDuration <= field000c) {
        field000c = 0;
        field000a = field000a + 1;
        if (frameCount <= field000a) {
            if (finishNeutral) {
                field0008 = 0;
                ResetPose();
                FaceOpponent();
            } else {
                field000a = 0;
            }
        }
    }

    if ((positionY + velocityY) >= 0.0) {
        positionY = 0.0;
        if (knockdownOnLanding != 0) {
            field0008 = 0x61;
        } else {
            field0008 = 0x62;
        }
        ResetPose();
    }
}


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
void Character19::Slot06UpdateHorizontalRecovery(
    unsigned short frameDuration,
    unsigned short frameCount,
    short meterGain,
    double initialVelocityX,
    int forceStandingState)
{
    if ((field000a == 0) && (field000c == 0)) {
        dashMomentumFlag = 0;
        meter = meter + meterGain;
        velocityX = initialVelocityX;
        velocityY = 0.0;
        positionY = 0.0;
    }

    velocityY = 0.0;
    velocityX = velocityX + 0.06;
    if (velocityX > 0.0) {
        velocityX = 0.0;
    }

    if ((positionX - 20.0 <= 0.0) || (639.0 <= positionX + 20.0)) {
        outgoingPushbackVelocityX = velocityX;
    } else {
        outgoingPushbackVelocityX = 0.0;
    }

    field000c = field000c + 1;
    if (frameDuration <= field000c) {
        field000c = 0;
        field000a = field000a + 1;
        if (field000a == frameCount) {
            FaceOpponent();
        }
        if (frameCount <= field000a) {
            field0008 = 0;
            if (forceStandingState || (inputY == 1)) {
                field0008 = 3;
            }
            ResetPose();
        }
    }
}


// Airborne knockback/impact variants for native selectors 0x40-0x42.
void Character19::Slot06UpdateAirborneKnockdown(
    unsigned short frameDuration,
    unsigned short frameCount,
    EffectSpawn *spawn,
    double horizontalVelocity,
    double initialVerticalVelocity,
    double gravityValue,
    short meterGain,
    int effectType,
    int clearDashMomentumFlag,
    int gravitySetEveryFrame,
    int skipGravityOnFirstFrame)
{
    const int firstFrame = (field000a == 0) && (field000c == 0);

    velocityX = horizontalVelocity;
    if (clearDashMomentumFlag) {
        dashMomentumFlag = 0;
    }
    if (gravitySetEveryFrame) {
        gravity = gravityValue;
    }

    if (firstFrame) {
        velocityY = initialVerticalVelocity;
        if (meterGain != 0) {
            meter = meter + meterGain;
        }
        if (!gravitySetEveryFrame) {
            gravity = gravityValue;
        }
        if (effectType != 0) {
            spawn->type = (unsigned short)effectType;
            spawn->x = (double)(int)positionX;
            spawn->y = (double)(int)positionY;
            spawn->group = 2;
            spawn->layer = 0;
            contextOwner->EmitEffect(spawn);
        }
    }

    if (!firstFrame || !skipGravityOnFirstFrame) {
        velocityY = velocityY + gravity;
    }

    field000c = field000c + 1;
    if (frameDuration <= field000c) {
        field000c = 0;
        field000a = field000a + 1;
        if (frameCount <= field000a) {
            field0008 = 9;
            ResetPose();
        }
    }

    if ((positionY + velocityY) >= 0.0) {
        positionY = 0.0;
        pendingContextSoundSlot = 9;
        FaceOpponent();
        field0008 = 0x0d;
        ResetPose();
    }
}


// Trail-assisted airborne bounce/recovery for native selectors 0x43 and 0x44.
void Character19::Slot06UpdateAirborneBounce(
    unsigned short frameDuration,
    unsigned short frameCount,
    unsigned char trailSpacing,
    unsigned short launchFrame,
    double launchVelocityX,
    double launchVelocityY,
    double launchGravity,
    double lateHorizontalDeceleration,
    int loopAfterFrameSeven,
    int landingState)
{
    if ((field000a == 0) && (field000c == 0)) {
        StartTrail(trailSpacing);
        ResetFrame();
    }

    if ((field000a == launchFrame) && (field000c == 0)) {
        velocityX = launchVelocityX;
        velocityY = launchVelocityY;
        gravity = launchGravity;
        pendingCharacterSoundSlot = 0;
    }

    int continueAirborne = (positionY >= 0.0);
    if (!continueAirborne) {
        velocityY = velocityY + gravity;
        continueAirborne = (positionY + velocityY <= 0.0);
    }

    if (continueAirborne) {
        if ((field000a > 6) && (lateHorizontalDeceleration != 0.0)) {
            velocityX = velocityX - lateHorizontalDeceleration;
            if (velocityX < 0.0) {
                velocityX = 0.0;
            }
        }

        field000c = field000c + 1;
        if (frameDuration <= field000c) {
            field000c = 0;
            field000a = field000a + 1;
            if (loopAfterFrameSeven && (field000a == 7)) {
                field000a = field000a - 2;
            }
            if (frameCount <= field000a) {
                if (landingState == 0) {
                    field0008 = 0;
                    ResetPose();
                } else {
                    field000a = field000a - 1;
                }
            }
        }
    } else {
        positionY = 0.0;
        if (landingState == 0) {
            velocityY = 0.0;
            field000c = 0;
            field000a = 7;
        } else {
            ResetPose();
            ResetFrame();
            field0008 = (unsigned short)landingState;
        }
    }
}


// Long airborne follow-up/counter state machine shared by selectors 0x45/0x46.
void Character19::Slot06UpdateAirborneFollowup(
    unsigned short frameDuration,
    unsigned short frameCount,
    unsigned short launchFrame,
    double launchVelocityX)
{
    if ((field000a == 0) && (field000c == 0)) {
        velocityX = 0.0;
        velocityY = 0.0;
    }

    field3140 = field3140 + 1;
    if (field3148 < field3140) {
        if ((inputY == -1) && (field015c < 3) && (airActionCount < 2)) {
            airActionCount = airActionCount + 1;
            field0008 = 14;
            if (inputX == facing) {
                field0008 = 15;
            }
            if (inputX == -facing) {
                field0008 = 16;
            }
            attackCollisionResult = 0;
            ResetPose();
            return;
        }

        if (inputY == 1) {
            field0008 = 9;
            ResetPose();
            if (airActionCount > 1) {
                return;
            }
            if (inputX == 0) {
                return;
            }
            if (field015c > 2) {
                return;
            }
            airActionCount = airActionCount + 1;
            if (inputX == facing) {
                field0008 = 18;
            }
            if (inputX == -facing) {
                field0008 = 20;
            }
            attackCollisionResult = 0;
            ResetPose();
            return;
        }

        if ((airActionCount < 2) && (field015c < 3)) {
            if (inputX == facing) {
                field0008 = 17;
                airActionCount = airActionCount + 1;
                ResetPose();
                attackCollisionResult = 0;
                return;
            }
            if (inputX == -facing) {
                field0008 = 19;
                airActionCount = airActionCount + 1;
                ResetPose();
                attackCollisionResult = 0;
                return;
            }
        }
    }

    if ((field000a == launchFrame) && (field000c == 0)) {
        gravity = 0.045;
        velocityY = -0.5;
        velocityX = launchVelocityX;
        pendingCharacterSoundSlot = 0;
    }

    if (field000a >= launchFrame) {
        velocityY = velocityY + 0.01;
    }

    field000c = field000c + 1;
    if (frameDuration <= field000c) {
        field000c = 0;
        field000a = field000a + 1;
        if (frameCount <= field000a) {
            field0008 = 10;
            ResetPose();
        }
    }

    if (((positionY + velocityY) >= 0.0) && (field000a > 3)) {
        positionY = 0.0;
        pendingContextSoundSlot = 9;
        FaceOpponent();
        field0008 = 0x0d;
        ResetPose();
    }
}


// Defeat-impact sequence with a one-frame tint and two context effects (0x47).
void Character19::Slot06UpdateDefeatImpactEffect(
    unsigned short frameDuration,
    unsigned short frameCount,
    EffectSpawn *spawn)
{
    if ((field000a == 0) && (field000c == 0)) {
        dashMomentumFlag = 0;
        velocityX = 0.0;
        velocityY = 0.0;
        if (field0120 == 1) {
            comboDamageScale = comboDamageScale + (field0118 * 5.0);
        }
        field0118 = 0.0;
        hitstunFrames = 90;
        SetTint(0xb0, 3);
    }

    if ((field000a == 1) && (field000c == 0)) {
        pendingContextSoundSlot = 0x12;
        spawn->type = 1;
        spawn->x = (double)(int)positionX;
        spawn->y = (double)(int)positionY;
        spawn->group = 2;
        spawn->layer = 1;
        contextOwner->EmitEffect(spawn);
    }

    if ((field000a == 2) && (field000c == 0)) {
        spawn->type = 4;
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
        attackCollisionResult = 0;
        if (frameCount <= field000a) {
            field0008 = 0;
            FaceOpponent();
            ResetPose();
        }
    }
}


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
void Character19::Slot06UpdateAirborneHitstunRestore(
    unsigned short frameDuration,
    unsigned short frameCount)
{
    if ((field000a == 0) && (field000c == 0)) {
        field3138 = (int)(velocityX * 100.0);
        field313c = (int)(velocityY * 100.0);
        velocityX = 0.0;
        velocityY = 0.0;
        if (gravity == 0.0) {
            gravity = 0.035;
        }
        guardInputFrames = 0;
        outgoingPushbackVelocityX = 0.0;
        hitstunFrames = 60;
    }

    if ((hitstunFrames == 0) && (field3140 == 0)) {
        field3140 = 1;
        velocityX = (double)field3138 * 0.01;
        velocityY = (double)field313c * 0.01;
    }

    if (hitstunFrames == 0) {
        velocityY = velocityY + gravity;
    }

    if ((positionY + velocityY) > 0.0) {
        ResetFrame();
        positionY = 0.0;
        field0008 = 0xa9;
    } else {
        field000c = field000c + 1;
        if (frameDuration <= field000c) {
            field000c = 0;
            field000a = field000a + 1;
            if (frameCount <= field000a) {
                field0008 = 9;
                ResetPose();
            }
        }
    }
}

// Defeat impact flash followed by restoration of the stored launch velocity (0x4b).
void Character19::Slot06UpdateDefeatImpactVelocityRestore(
    unsigned short frameDuration,
    unsigned short frameCount,
    EffectSpawn *spawn)
{
    if ((field000a == 0) && (field000c == 0)) {
        field3138 = (int)(velocityX * 100.0);
        field313c = (int)(velocityY * 100.0);
        velocityX = 0.0;
        velocityY = 0.0;
        if (field0120 == 1) {
            comboDamageScale = comboDamageScale + (field0118 * 5.0);
        }
        field0118 = 0.0;
        hitstunFrames = 90;
        SetTint(0xb0, 3);
    }

    if ((field000a == 1) && (field000c == 0)) {
        pendingContextSoundSlot = 0x12;
        spawn->type = 1;
        spawn->x = (double)(int)positionX;
        spawn->y = (double)(int)positionY;
        spawn->group = 2;
        spawn->layer = 1;
        contextOwner->EmitEffect(spawn);
    }

    if ((field000a == 2) && (field000c == 0)) {
        spawn->type = 4;
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
        attackCollisionResult = 0;
        if (frameCount <= field000a) {
            field0008 = 9;
            velocityX = (double)field3138 * 0.01;
            velocityY = (double)field313c * 0.01;
            gravity = 0.035;
            ResetPose();
        }
    }
}


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
void Character19::Slot06UpdateDashAttack(
    unsigned short frameDuration,
    unsigned short frameCount,
    EffectSpawn *spawn,
    double horizontalDeceleration,
    int cancelMode,
    unsigned short meterFrame,
    short meterGain,
    unsigned short soundSlot,
    unsigned short effectFrame,
    unsigned short effectType,
    int effectBeforeCancel,
    int finishStanding)
{
    if (dashMomentumFlag == 0) {
        velocityX = 0.0;
        velocityY = 0.0;
    }

    if ((velocityX > 0.0) && (dashMomentumFlag == 1)) {
        velocityX = velocityX - horizontalDeceleration;
    } else {
        velocityX = 0.0;
        dashMomentumFlag = 0;
    }

    if (effectBeforeCancel && (effectFrame != 0) &&
        (field000a == effectFrame) && (field000c == 0)) {
        spawn->owner = 1;
        spawn->type = effectType;
        spawn->x = (double)(int)positionX;
        spawn->y = (double)(int)positionY;
        spawn->flag0018 = (unsigned char)facing;
        spawn->group = 2;
        spawn->layer = 1;
        EmitLocalEffect(spawn);
    }

    int cancel = 0;
    if ((cancelMode != 0) && (inputY == -1) &&
        (field000a > 0) && (field015c < 3)) {
        if ((cancelMode == 1) && (attackCollisionResult > 1)) {
            cancel = 1;
        } else if ((cancelMode == 2) && (attackCollisionResult == 3)) {
            cancel = 1;
        }
    }

    if (cancel) {
        field0008 = 4;
        if (inputX == facing) {
            field0008 = 5;
        }
        if (inputX == -facing) {
            field0008 = 6;
        }
        attackCollisionResult = 0;
        ResetPose();
        return;
    }

    if ((field000a == meterFrame) && (field000c == 0)) {
        meter = meter + meterGain;
        pendingContextSoundSlot = (char)soundSlot;
        remainingHitCount = 1;
    }

    if (!effectBeforeCancel && (effectFrame != 0) &&
        (field000a == effectFrame) && (field000c == 0)) {
        spawn->owner = 1;
        spawn->type = effectType;
        spawn->x = (double)(int)positionX;
        spawn->y = (double)(int)positionY;
        spawn->flag0018 = (unsigned char)facing;
        spawn->group = 2;
        spawn->layer = 1;
        EmitLocalEffect(spawn);
    }

    field000c = field000c + 1;
    if (frameDuration <= field000c) {
        field000c = 0;
        field000a = field000a + 1;
        if (field000a < 3) {
            attackCollisionResult = 0;
        }
        if (frameCount <= field000a) {
            field0008 = 0;
            if (finishStanding && (inputY == 1)) {
                field0008 = 3;
            }
            FaceOpponent();
            ResetPose();
        }
    }
}


// Sustained dash-attack state 206: momentum lasts through phase 2, then only the
// one-shot phase-3 meter event and animation completion remain.
void Character19::Slot06UpdateDashAttackSustain(
    unsigned short frameDuration,
    unsigned short frameCount)
{
    if ((dashMomentumFlag == 0) && (field000a == 0) && (field000c == 0)) {
        velocityX = 0.0;
        velocityY = 0.0;
    }

    if ((velocityX <= 0.0) || (dashMomentumFlag != 1) || (field000a > 2)) {
        dashMomentumFlag = 0;
    } else {
        velocityX = velocityX - 0.03;
    }

    if (velocityX < 0.0) {
        velocityX = 0.0;
    }

    if ((field000a == 1) && (field000c == 0)) {
        remainingHitCount = 1;
    }

    if ((field000a == 3) && (field000c == 0) && (field3138 == 0)) {
        meter = meter + 25;
        pendingContextSoundSlot = 0x14;
        field3138 = field3138 + 1;
    }

    field000c = field000c + 1;
    if (frameDuration <= field000c) {
        field000c = 0;
        field000a = field000a + 1;
        attackCollisionResult = 0;
        if (frameCount <= field000a) {
            field0008 = 0;
            if (inputY == 1) {
                field0008 = 3;
            }
            FaceOpponent();
            ResetPose();
        }
    }
}


// Airborne follow-up family with both down-cancel and neutral-horizontal follow-up routes.
void Character19::Slot06UpdateAirborneDashFollowup(
    unsigned short frameDuration,
    unsigned short frameCount,
    EffectSpawn *spawn,
    unsigned short meterFrame,
    short meterGain,
    unsigned short soundSlot,
    unsigned short effectFrame,
    unsigned short effectType,
    unsigned short attackCollisionClearFrame)
{
    velocityY = velocityY + gravity;

    if ((inputY == -1) && (field000a > 0) && (field015c < 3) &&
        (attackCollisionResult > 1) && (airActionCount < 2)) {
        airActionCount = airActionCount + 1;
        field0008 = 14;
        if (inputX == facing) {
            field0008 = 15;
        }
        if (inputX == -facing) {
            field0008 = 16;
        }
        attackCollisionResult = 0;
        ResetPose();
        return;
    }

    if ((inputY == 0) && (inputX != 0) && (field000a > 0) &&
        (attackCollisionResult > 1) && (airActionCount < 2) &&
        (field015c < 3)) {
        airActionCount = airActionCount + 1;
        if (inputX == facing) {
            field0008 = 0xa5;
        }
        if (inputX == -facing) {
            field0008 = 0xa6;
        }
        attackCollisionResult = 0;
        ResetPose();
        return;
    }

    if ((field000a == meterFrame) && (field000c == 0)) {
        meter = meter + meterGain;
        pendingContextSoundSlot = (char)soundSlot;
        remainingHitCount = 1;
    }

    if ((effectFrame != 0) && (field000a == effectFrame) && (field000c == 0)) {
        spawn->owner = 1;
        spawn->type = effectType;
        spawn->x = (double)(int)positionX;
        spawn->y = (double)(int)positionY;
        spawn->flag0018 = (unsigned char)facing;
        spawn->group = 2;
        spawn->layer = 1;
        EmitLocalEffect(spawn);
    }

    if ((positionY + velocityY) >= 0.0) {
        positionY = 0.0;
        field0008 = 13;
        ResetPose();
        return;
    }

    field000c = field000c + 1;
    if (frameDuration <= field000c) {
        field000c = 0;
        field000a = field000a + 1;
        if (field000a < attackCollisionClearFrame) {
            attackCollisionResult = 0;
        }
        if (frameCount <= field000a) {
            field0008 = 9;
            ResetPose();
        }
    }
}


// Multi-phase aerial launch: hold at phase 4 until the phase-5 ground test succeeds.
void Character19::Slot06UpdateAerialLaunchLanding(
    unsigned short frameDuration,
    unsigned short frameCount)
{
    if ((field000a == 0) && (field000c == 0)) {
        velocityX = 0.0;
        velocityY = 0.0;
    }

    if ((field000a == 1) && (field000c == 0)) {
        velocityX = 1.4;
        velocityY = -1.5;
        gravity = 0.08;
    }

    if ((field000a == 2) && (field000c == 0)) {
        meter = meter + 15;
        pendingContextSoundSlot = 0x14;
        remainingHitCount = 1;
    }

    if ((field000a == 5) && (field000c == 0)) {
        velocityX = 0.0;
        velocityY = 0.0;
        gravity = 0.0;
    }

    if (field000a > 0) {
        velocityY = velocityY + gravity;
    }

    field000c = field000c + 1;
    if (frameDuration <= field000c) {
        field000c = 0;
        field000a = field000a + 1;
        attackCollisionResult = 0;

        if (field000a == 5) {
            if ((positionY + velocityY) < 0.0) {
                field000a = field000a - 1;
            } else {
                positionY = 0.0;
            }
        }

        if (frameCount <= field000a) {
            field0008 = 0;
            FaceOpponent();
            ResetPose();
        }
    }
}

// Ground dash follow-up with a down-input cancel window and a late meter event.
void Character19::Slot06UpdateDashFollowupCancel(
    unsigned short frameDuration,
    unsigned short frameCount)
{
    if ((inputY == -1) && (field000a > 0) &&
        (field015c < 3) && (attackCollisionResult > 1)) {
        field0008 = 4;
        if (inputX == facing) {
            field0008 = 5;
        }
        if (inputX == -facing) {
            field0008 = 6;
        }
        attackCollisionResult = 0;
        ResetPose();
        return;
    }

    if ((field000a == 0) && (field000c == 0)) {
        velocityX = 0.0;
        velocityY = 0.0;
    }

    if ((field000a == 3) && (field000c == 0)) {
        meter = meter + 30;
        pendingContextSoundSlot = 0x14;
        remainingHitCount = 1;
    }

    field000c = field000c + 1;
    if (frameDuration <= field000c) {
        field000c = 0;
        field000a = field000a + 1;
        attackCollisionResult = 0;
        if (frameCount <= field000a) {
            field0008 = 0;
            FaceOpponent();
            ResetPose();
        }
    }
}


// Repeating aerial ground-slam: collision can force the D5 exit; landing emits
// the context-owned impact effect and transitions to D6.
void Character19::Slot06UpdateAerialGroundSlam(
    unsigned short frameDuration,
    unsigned short frameCount,
    EffectSpawn *spawn)
{
    velocityY = velocityY + gravity;

    if ((field000a == 0) && (field000c == 0)) {
        meter = meter + 30;
        pendingContextSoundSlot = 0x14;
        remainingHitCount = 1;
        velocityX = velocityX / 2.0;
        gravity = 0.07;
    }

    if (attackCollisionResult > 1) {
        field0008 = 0xd5;
        ResetPose();
        ResetFrame();
        return;
    }

    if ((positionY + velocityY) >= 0.0) {
        positionY = 0.0;
        ResetFrame();
        velocityY = 0.0;
        SetVerticalShake(3, 0);

        spawn->type = 3;
        spawn->x = (double)(int)positionX;
        spawn->y = (double)(int)positionY;
        spawn->group = 2;
        spawn->layer = 0;
        spawn->palette = 7;
        contextOwner->EmitEffect(spawn);

        pendingContextSoundSlot = 7;
        field0008 = 0xd6;
        ResetPose();
        return;
    }

    field000c = field000c + 1;
    if (frameDuration <= field000c) {
        field000c = 0;
        field000a = field000a + 1;
        attackCollisionResult = 0;
        if (frameCount <= field000a) {
            field000a = field000a - 2;
        }
    }
}

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
void Character19::Slot06UpdateGroundImpactRecovery(
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
        spawn->palette = 7;
        contextOwner->EmitEffect(spawn);
    }

    field000c = field000c + 1;
    if (frameDuration <= field000c) {
        field000c = 0;
        field000a = field000a + 1;
        attackCollisionResult = 0;
        if (frameCount <= field000a) {
            field0008 = 7;
            if (inputY == 1) {
                field0008 = 3;
            }
            FaceOpponent();
            ResetPose();
        }
    }
}


// Opponent capture impact: on the confirmed hit, reset both fighters, lock the
// opponent's air actions, and emit the native type-0 scene effect.
void Character19::Slot06UpdateOpponentCaptureImpact(
    unsigned short frameDuration,
    unsigned short frameCount,
    EffectSpawn *spawn)
{
    Secondary *target = *opponentSlot;
    velocityX = 0.0;
    velocityY = 0.0;

    if ((field000a == 1) && (field000c == 0) &&
        (target->positionY == 0.0)) {
        remainingHitCount = 1;
    } else {
        remainingHitCount = 0;
    }

    if ((field000a == 1) && (attackCollisionResult == 3)) {
        velocityX = 0.0;
        velocityY = 0.0;
        outgoingPushbackVelocityX = 0.0;
        ResetPose();
        ResetFrame();
        target->ResetFrame();
        target->ResetPose();
        field0008 = 0xdd;
        target->airActionDisabled = 1;

        spawn->type = 0;
        spawn->x = (double)((int)positionX + (int)facing * 0x25);
        spawn->y = (double)((int)positionY - 0x2a);
        spawn->group = 2;
        spawn->layer = 1;
        contextOwner->EmitEffect(spawn);
        return;
    }

    field000c = field000c + 1;
    if (frameDuration <= field000c) {
        field000c = 0;
        field000a = field000a + 1;
        attackCollisionResult = 0;
        if (frameCount <= field000a) {
            field0008 = 0;
            if (inputY == 1) {
                field0008 = 3;
            }
            FaceOpponent();
            ResetPose();
        }
    }
}

// Multi-frame opponent stage combo. All opponent repositioning is tied to
// animation-frame boundaries; damage is applied at frame 4 before that frame
// advances, matching the native 0x4e2 / 750.0 damage request.
void Character19::Slot06UpdateOpponentStageCombo(
    unsigned short frameDuration,
    unsigned short frameCount)
{
    Secondary *target = *opponentSlot;

    if ((field000a == 4) && (field000c == 0)) {
        ApplyDamage(0x4e2, 750.0);
    }

    field000c = field000c + 1;
    if (frameDuration <= field000c) {
        field000c = 0;
        field000a = field000a + 1;
        attackCollisionResult = 0;

        if (field000a == 1) {
            target->field0008 = 0x67;
            target->ResetFrame();
            target->ResetPose();
            target->positionY = -86.0;
            target->positionX = positionX + (double)((int)facing * 0x29);
        }

        if (field000a == 2) {
            target->positionY = -97.0;
            target->positionX = positionX + (double)((int)facing * 0x24);
        }

        if (field000a == 3) {
            target->positionY = -97.0;
            target->positionX = positionX + (double)((int)facing * 0x22);
            target->facing = -facing;
        }

        if (field000a == 4) {
            target->positionY = 0.0;
            target->positionX = positionX + (double)((int)facing * 0x24);
            target->facing = -facing;
            SetVerticalShake(3, 0);
            target->field0008 = 0x61;
            target->ResetFrame();
            target->ResetPose();
        }

        if (frameCount <= field000a) {
            field0008 = 0;
            FaceOpponent();
            ResetPose();
        }
    }
}


// Trail-backed dash finishers 0x5e/0x5f share movement and frame timing; only
// the frame-2 meter/sound event differs.
void Character19::Slot06UpdateTrailDashFinish(
    unsigned short frameDuration,
    unsigned short frameCount,
    unsigned short meterFrame,
    short meterGain,
    unsigned char soundSlot,
    unsigned short collisionClearFrame,
    unsigned short completionState)
{
    StartTrail(3);
    dashMomentumFlag = 0;

    velocityX = velocityX - 0.03;
    if (velocityX < 0.0) {
        velocityX = 0.0;
    }

    if ((field000a == 0) && (field000c == 0)) {
        velocityX = 2.0;
        velocityY = 0.0;
    }

    if ((field000a == meterFrame) && (field000c == 0)) {
        meter = meter + meterGain;
        pendingContextSoundSlot = (char)soundSlot;
        remainingHitCount = 1;
    }

    field000c = field000c + 1;
    if (frameDuration <= field000c) {
        field000c = 0;
        field000a = field000a + 1;
        if (field000a < collisionClearFrame) {
            attackCollisionResult = 0;
        }
        if (frameCount <= field000a) {
            field0008 = completionState;
            ResetPose();
        }
    }
}


// Trail-backed dash strike with a frame-3 speed burst and sustained 0.07 decay.
void Character19::Slot06UpdateDashTrailCharge(
    unsigned short frameDuration,
    unsigned short frameCount)
{
    StartTrail(3);
    dashMomentumFlag = 0;

    if (field000a < 3) {
        velocityX = 0.0;
    }

    if ((field000a == 3) && (field000c == 0)) {
        pendingContextSoundSlot = 0x14;
        velocityX = 3.0;
        remainingHitCount = 1;
        meter = meter + 35;
    }

    if (velocityX > 0.0) {
        velocityX = velocityX - 0.07;
    }
    if (velocityX < 0.0) {
        velocityX = 0.0;
    }

    field000c = field000c + 1;
    if (frameDuration <= field000c) {
        field000c = 0;
        field000a = field000a + 1;
        if (field000a < 3) {
            attackCollisionResult = 0;
        }
        if (frameCount <= field000a) {
            field0008 = 0;
            ResetPose();
        }
    }
}

// Trail-backed airborne dash: frame 3 launches, then gravity runs until a
// strict ground crossing moves the animation to its terminal frame 15.
void Character19::Slot06UpdateAirborneTrailDash(
    unsigned short frameDuration,
    unsigned short frameCount)
{
    StartTrail(3);
    dashMomentumFlag = 0;

    if (field000a < 3) {
        velocityX = 0.0;
    }

    if ((field000a > 2) && (field000a < 0xf)) {
        velocityY = velocityY + gravity;
        if ((positionY + velocityY) > 0.0) {
            field000c = 0;
            ResetFrame();
            positionY = 0.0;
            field000a = 0xf;
        }
    }

    if ((field000a == 7) && (field000c == 0)) {
        pendingContextSoundSlot = 0x14;
        remainingHitCount = 1;
        meter = meter + 35;
    }

    field000c = field000c + 1;
    if (frameDuration <= field000c) {
        field000c = 0;
        field000a = field000a + 1;
        if (field000a < 3) {
            attackCollisionResult = 0;
        }
        if (field000a == 3) {
            velocityX = 1.5;
            velocityY = -1.5;
            gravity = 0.032;
        }
        if (frameCount <= field000a) {
            field0008 = 0;
            ResetPose();
        }
    }
}


// Stun/effect recovery: configure the short invulnerability and guard windows,
// then emit the native palette-0x13 context effect on the opening frame.
void Character19::Slot06UpdateStunEffectRecovery(
    unsigned short frameDuration,
    unsigned short frameCount,
    EffectSpawn *spawn)
{
    if ((field000a == 0) && (field000c == 0)) {
        field00dc = 4;
        field00de = 0xec;
        velocityX = 0.0;
        remainingHitCount = 1;
        guardInputFrames = 0;
        hitstunFrames = 60;

        spawn->type = 0x28;
        spawn->x = (double)((int)positionX + (int)facing * 10);
        spawn->y = (double)((int)positionY - 0x28);
        spawn->group = 2;
        spawn->layer = 1;
        spawn->palette = 0x13;
        contextOwner->EmitEffect(spawn);
    }

    field000c = field000c + 1;
    if (frameDuration <= field000c) {
        field000c = 0;
        field000a = field000a + 1;
        attackCollisionResult = 0;
        if (frameCount <= field000a) {
            field0008 = 0;
            FaceOpponent();
            ResetPose();
        }
    }
}

// Frame-4 impact pair: a context-owned flash followed by the character-local
// 0x194 strike effect, with the meter and character-sound request in between.
void Character19::Slot06UpdateImpactEffectPair(
    unsigned short frameDuration,
    unsigned short frameCount,
    EffectSpawn *spawn)
{
    if ((field000a == 0) && (field000c == 0)) {
        ResetFrame();
    }

    if ((field000a == 4) && (field000c == 0)) {
        spawn->type = 0x1f;
        spawn->x = (double)(int)positionX;
        spawn->y = (double)(int)positionY;
        spawn->group = 0;
        spawn->layer = 1;
        spawn->facing = (facing != 1);
        contextOwner->EmitEffect(spawn);

        remainingHitCount = 1;
        meter = meter + 45;
        pendingCharacterSoundSlot = 1;

        spawn->owner = 1;
        spawn->type = 0x194;
        spawn->x = (double)((int)positionX - (int)facing * 0x50);
        spawn->y = (double)((int)positionY - 0x28);
        spawn->group = 2;
        spawn->layer = 1;
        spawn->flag0018 = (unsigned char)facing;
        EmitLocalEffect(spawn);
    }

    field000c = field000c + 1;
    if (frameDuration <= field000c) {
        field000c = 0;
        field000a = field000a + 1;
        if (field000a < 5) {
            attackCollisionResult = 0;
        }
        if (frameCount <= field000a) {
            field0008 = 0;
            ResetPose();
        }
    }
}

// Combo impact burst with a one-time trail capture, combo-scale decay and
// three distinct effect timings (opening context, frame-2 local, frame-4 pair).
void Character19::Slot06UpdateComboImpactBurst(
    unsigned short frameDuration,
    unsigned short frameCount,
    EffectSpawn *spawn)
{
    if ((field000a == 0) && (field000c == 0)) {
        ResetFrame();
        StartTrail(3);
        if (field0120 == 0) {
            field0118 = field0118 - 500.0;
        } else {
            field0118 = field0118 - 250.0;
        }

        spawn->type = 0x21;
        spawn->x = (double)(int)positionX;
        spawn->y = (double)((int)positionY - 0x32);
        spawn->group = 2;
        spawn->layer = 1;
        spawn->palette = 0xb;
        contextOwner->EmitEffect(spawn);

        remainingHitCount = 1;
        velocityX = 0.0;
        velocityY = 0.0;
        horizontalDeceleration = 0.0;
        if (positionY < 0.0) {
            field000a = 6;
        }
    }

    if ((field000a == 4) && (field000c == 0)) {
        spawn->type = 0x1f;
        spawn->x = (double)(int)positionX;
        spawn->y = (double)(int)positionY;
        spawn->group = 0;
        spawn->layer = 1;
        spawn->facing = (facing != 1);
        contextOwner->EmitEffect(spawn);

        remainingHitCount = 1;
        meter = meter + 45;
        pendingCharacterSoundSlot = 1;

        spawn->owner = 1;
        spawn->type = 0x194;
        spawn->x = (double)((int)positionX - (int)facing * 0x50);
        spawn->y = (double)((int)positionY - 0x28);
        spawn->group = 2;
        spawn->layer = 1;
        spawn->flag0018 = (unsigned char)facing;
        EmitLocalEffect(spawn);
    }

    if ((field000a == 2) && (field000c == 0)) {
        spawn->owner = 1;
        spawn->type = 0x1ab;
        spawn->x = (double)(int)positionX;
        spawn->y = (double)(int)positionY;
        spawn->group = 2;
        spawn->layer = 1;
        spawn->flag0018 = (unsigned char)facing;
        EmitLocalEffect(spawn);
    }

    field000c = field000c + 1;
    if (frameDuration <= field000c) {
        field000c = 0;
        field000a = field000a + 1;
        if (field000a < 5) {
            attackCollisionResult = 0;
        }
        if (frameCount <= field000a) {
            field0008 = 0;
            ResetPose();
        }
    }
}

// Damped impact finish: attenuate the launch once, then cap positive vertical
// drift while the frame-4 meter/effect event completes the animation.
void Character19::Slot06UpdateDampedImpactFinish(
    unsigned short frameDuration,
    unsigned short frameCount,
    EffectSpawn *spawn)
{
    if ((field000a == 0) && (field000c == 0)) {
        velocityX = velocityX * 0.3;
        velocityY = velocityY * 0.3;
    }

    velocityY = velocityY + 0.01;
    if (velocityY > 0.3) {
        velocityY = 0.3;
    }

    if ((field000a == 4) && (field000c == 0)) {
        remainingHitCount = 1;
        meter = meter + 45;
        pendingCharacterSoundSlot = 1;

        spawn->owner = 1;
        spawn->type = 0x194;
        spawn->x = (double)((int)positionX - (int)facing * 0x50);
        spawn->y = (double)((int)positionY - 0x28);
        spawn->group = 2;
        spawn->layer = 1;
        spawn->flag0018 = (unsigned char)facing;
        EmitLocalEffect(spawn);
    }

    field000c = field000c + 1;
    if (frameDuration <= field000c) {
        field000c = 0;
        field000a = field000a + 1;
        if (field000a < 5) {
            attackCollisionResult = 0;
        }
        if (frameCount <= field000a) {
            field0008 = 9;
            ResetPose();
        }
    }
}


// Looping aerial bounce. A confirmed ground crossing exits to the native
// landing state 0x103; otherwise frame 3 re-launches and the animation loops.
void Character19::Slot06UpdateLoopingAerialBounce(
    unsigned short frameDuration,
    unsigned short frameCount,
    EffectSpawn *spawn)
{
    if ((field000a == 0) && (field000c == 0)) {
        ResetFrame();
        remainingHitCount = 2;
    }

    if (positionY < 0.0) {
        velocityY = velocityY + gravity;
    }

    if ((positionY >= 0.0) || ((positionY + velocityY) < 0.0)) {
        if ((field000a == 3) && (field000c == 0)) {
            velocityY = -2.5;
            gravity = 0.045;

            spawn->owner = 1;
            spawn->type = 0x1b9;
            spawn->x = positionX;
            spawn->y = positionY;
            spawn->flag0018 = (unsigned char)facing;
            spawn->group = 2;
            spawn->layer = 1;
            EmitLocalEffect(spawn);
        }

        field000c = field000c + 1;
        if (frameDuration <= field000c) {
            field000c = 0;
            field000a = field000a + 1;
            attackCollisionResult = 0;
            if (frameCount <= field000a) {
                field000a = field000a - 2;
            }
        }
    } else {
        positionY = 0.0;
        ResetPose();
        ResetFrame();
        field0008 = 0x103;
    }
}

// The combo version adds a one-shot context burst, a frame-1 local marker,
// and a five-cycle launch loop driven by the two persistent Character19 counters.
void Character19::Slot06UpdateComboAerialBounce(
    unsigned short frameDuration,
    unsigned short frameCount,
    EffectSpawn *spawn)
{
    if ((field000a == 0) && (field000c == 0)) {
        StartTrail(1);
        if (field313c == 0) {
            ResetFrame();
            if (field0120 == 0) {
                field0118 = field0118 - 500.0;
            } else {
                field0118 = field0118 - 250.0;
            }

            spawn->type = 0x21;
            spawn->x = (double)(int)positionX;
            spawn->y = (double)((int)positionY - 0x32);
            spawn->group = 2;
            spawn->layer = 1;
            spawn->palette = 0xb;
            contextOwner->EmitEffect(spawn);
            field313c = field313c + 1;
        }
        remainingHitCount = 1;
    }

    if ((field000a == 1) && (field000c == 0)) {
        spawn->owner = 1;
        spawn->type = 0x1b9;
        spawn->x = positionX;
        spawn->y = positionY;
        spawn->flag0018 = (unsigned char)facing;
        spawn->group = 2;
        spawn->layer = 1;
        EmitLocalEffect(spawn);
    }

    if (positionY < 0.0) {
        velocityY = velocityY + gravity;
    }

    if ((positionY >= 0.0) || ((positionY + velocityY) < 0.0)) {
        field000c = field000c + 1;
        if (frameDuration <= field000c) {
            field000c = 0;
            field000a = field000a + 1;
            attackCollisionResult = 0;

            if ((field000a == 3) && (field313c == 1)) {
                velocityY = -3.5;
                gravity = 0.015;
                field313c = field313c + 1;
            }

            if ((field000a == 8) && (field3138 < 5)) {
                field000a = 0;
                field3138 = field3138 + 1;
            }

            if (field000a == 9) {
                remainingHitCount = 1;
            }

            if (frameCount <= field000a) {
                ResetPose();
                field0008 = 9;
            }
        }
    } else {
        positionY = 0.0;
        ResetPose();
        ResetFrame();
        field0008 = 0x103;
    }
}

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
void Character19::Slot06UpdateLocalEffectFinish(
    unsigned short frameDuration,
    unsigned short frameCount,
    unsigned short effectType)
{
    if ((field000a == 0) && (field000c == 0)) {
        ResetFrame();

        EffectSpawn effect;
        effect.owner = 1;
        effect.type = effectType;
        effect.x = (double)((int)positionX + (int)facing * 0x1e);
        effect.y = (double)((int)positionY - 0x28);
        effect.group = 0;
        effect.layer = 1;
        effect.facing = (facing != 1);
        effect.flag0018 = (unsigned char)facing;
        effect.field0028 = 1;
        EmitLocalEffect(&effect);

        meter = meter + 45;
        pendingCharacterSoundSlot = 2;
    }

    field000c = field000c + 1;
    if (frameDuration <= field000c) {
        field000c = 0;
        field000a = field000a + 1;
        if (field000a > 9) {
            attackCollisionResult = 0;
        }
        if (frameCount <= field000a) {
            field0008 = 0;
            ResetPose();
        }
    }
}


// Two-stage local-effect finisher: distinct frame-7 and frame-8 resources,
// with meter and character sound coupled only to the second burst.
void Character19::Slot06UpdateFinalEffectPair(
    unsigned short frameDuration,
    unsigned short frameCount,
    EffectSpawn *spawn)
{
    if ((field000a == 0) && (field000c == 0)) {
        ResetFrame();
    }

    if ((field000a == 7) && (field000c == 0)) {
        spawn->owner = 1;
        spawn->type = 0x195;
        spawn->x = (double)((int)positionX + (int)facing * 0x23);
        spawn->y = (double)((int)positionY - 0x3f);
        spawn->group = 2;
        spawn->layer = 1;
        spawn->facing = (facing != 1);
        spawn->flag0018 = (unsigned char)facing;
        spawn->field0028 = 0;
        EmitLocalEffect(spawn);
    }

    if ((field000a == 8) && (field000c == 0)) {
        spawn->owner = 1;
        spawn->type = 0x196;
        spawn->x = (double)((int)positionX + (int)facing * 0x50);
        spawn->y = (double)((int)positionY - 0x3f);
        spawn->group = 2;
        spawn->layer = 1;
        spawn->facing = (facing != 1);
        spawn->flag0018 = (unsigned char)facing;
        spawn->field0028 = 0;
        EmitLocalEffect(spawn);

        meter = meter + 45;
        pendingCharacterSoundSlot = 2;
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

// Trail-backed final burst: the opening context flash is unowned (the native
// zero-initialized spawn record), while the frame-7 local effect belongs to us.
void Character19::Slot06UpdateTrailEffectFinish(
    unsigned short frameDuration,
    unsigned short frameCount,
    EffectSpawn *spawn)
{
    if ((field000a == 0) && (field000c == 0)) {
        ResetFrame();
        StartTrail(3);

        if (field0120 == 0) {
            field0118 = field0118 - 500.0;
        } else {
            field0118 = field0118 - 250.0;
        }

        spawn->type = 0x21;
        spawn->x = (double)(int)positionX;
        spawn->y = (double)((int)positionY - 0x32);
        spawn->group = 2;
        spawn->layer = 1;
        spawn->palette = 0xb;
        contextOwner->EmitEffect(spawn);
    }

    if ((field000a == 7) && (field000c == 0)) {
        spawn->owner = 1;
        spawn->type = 0x1ad;
        spawn->x = (double)((int)positionX + (int)facing * 0x23);
        spawn->y = (double)((int)positionY - 0x3f);
        spawn->group = 2;
        spawn->layer = 1;
        spawn->facing = (facing != 1);
        spawn->flag0018 = (unsigned char)facing;
        spawn->field0028 = 0;
        EmitLocalEffect(spawn);
    }

    if ((field000a == 8) && (field000c == 0)) {
        meter = meter + 45;
        pendingCharacterSoundSlot = 2;
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
