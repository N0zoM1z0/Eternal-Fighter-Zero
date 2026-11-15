// Character04::Slot06 original native state boss, authored real opening cases.
// This is an incomplete workbench. Unreviewed live states are NOT source.
#include "../../src/CharacterViews.h"

extern "C" int __cdecl _ftol2(void);

// Source-local offsets only, to keep accepted shared CharacterViews.h stable.
struct Character04StateFields {
    unsigned char base[0x3138];
    int field3138, field313c, field3140, field3144;
    int field3148, field314c, field3150, field3154;
};

// The accepted shared Character04 header has provisional child layout.
// Use this private offset view without changing accepted owner recipes.
struct Character04StatePrivate {
    unsigned char base[0x3138];
    int field3138, field313c;
};

void Character04::Slot06()
{
    if (hitstopFrames > 0 || (*opponentSlot)->hitstunFrames > 0) return;
    EffectSpawn effect;
    struct FrameTiming {
        __declspec(align(4)) unsigned short animationFrameCount;
        __declspec(align(4)) unsigned short frameDuration;
    } timing;
    timing.frameDuration = patterns[field0008].frames[field000a].duration;
    timing.animationFrameCount = patterns[field0008].count;
    ResetLocalEffectSpawn(&effect);
    switch (field0008) {
    default: // Native 0x006079DC: unmapped animation IDs
        velocityX = 0.0;
        velocityY = 0.0;
        ++field000c;
        if (field000c >= timing.frameDuration) {
            field000c = 0;
            ++field000a;
            if (field000a >= timing.animationFrameCount)
                field000a = 0;
        }
        return;

    case 1: // Native 0x00607A4D: forward motion
        velocityX = 0.5;
        velocityY = 0.0;
        ++field000c;
        if (field000c >= timing.frameDuration) {
            field000c = 0;
            ++field000a;
            if (field000a >= timing.animationFrameCount)
                field000a = 0;
        }
        return;

    case 2: // Native 0x00607ABE: reverse motion
        velocityX = -0.5;
        velocityY = 0.0;
        ++field000c;
        if (field000c >= timing.frameDuration) {
            field000c = 0;
            ++field000a;
            if (field000a >= timing.animationFrameCount)
                field000a = 0;
        }
        return;

    case 3: // Native 0x00607B2F: grounded neutral facing
        velocityX = 0.0;
        velocityY = 0.0;
        FaceOpponent();
        ++field000c;
        if (field000c >= timing.frameDuration) {
            field000c = 0;
            ++field000a;
            if (field000a >= timing.animationFrameCount)
                field000a = 0;
        }
        return;

    case 4: // Native 0x00607BA8: grounded-to-aerial jump with landing recovery
        if (field000a == 0 && field000c == 0) {
            FaceOpponent();
            velocityX = 0.0;
        }
        if (field000a == 2 && field000c == 0) {
            gravity = 0.035;
            velocityY = -2.7;
        }
        if (field000a > 1)
            velocityY += gravity;
        ++field000c;
        if (field000c >= timing.frameDuration) {
            field000c = 0;
            ++field000a;
            if (field000a >= timing.animationFrameCount) {
                field0008 = 9;
                ResetPose();
            }
        }
        if (positionY + velocityY >= 0.0 && field000a > 2) {
            positionY = 0.0;
            pendingContextSoundSlot = 9;
            FaceOpponent();
            field0008 = 13;
            ResetPose();
        }
        return;

    case 5: // Native 0x00607CD8: forward aerial jump with native momentum
        if (field000a == 0 && field000c == 0) {
            FaceOpponent();
            velocityX = 0.0;
        }
        if (field000a == 2 && field000c == 0) {
            gravity = 0.035;
            velocityY = -2.7;
            velocityX = 0.6;
        }
        if (field000a > 1)
            velocityY += gravity;
        ++field000c;
        if (field000c >= timing.frameDuration) {
            field000c = 0;
            ++field000a;
            if (field000a >= timing.animationFrameCount) {
                field0008 = 9;
                ResetPose();
            }
        }
        if (positionY + velocityY >= 0.0 && field000a > 2) {
            positionY = 0.0;
            pendingContextSoundSlot = 9;
            FaceOpponent();
            field0008 = 13;
            ResetPose();
        }
        return;

    case 6: // Native 0x00607E14: backward aerial jump with native momentum
        if (field000a == 0 && field000c == 0) {
            FaceOpponent();
            velocityX = 0.0;
        }
        if (field000a == 2 && field000c == 0) {
            gravity = 0.035;
            velocityY = -2.7;
            velocityX = -0.6;
        }
        if (field000a > 1)
            velocityY += gravity;
        ++field000c;
        if (field000c >= timing.frameDuration) {
            field000c = 0;
            ++field000a;
            if (field000a >= timing.animationFrameCount) {
                field0008 = 9;
                ResetPose();
            }
        }
        if (positionY + velocityY >= 0.0 && field000a > 2) {
            positionY = 0.0;
            pendingContextSoundSlot = 9;
            FaceOpponent();
            field0008 = 13;
            ResetPose();
        }
        return;

    case 7: // Native 0x00607F50: neutral recovery and animation reset
        velocityX = 0.0;
        velocityY = 0.0;
        FaceOpponent();
        ++field000c;
        if (field000c >= timing.frameDuration) {
            field000c = 0;
            ++field000a;
            if (field000a >= timing.animationFrameCount) {
                field0008 = 0;
                ResetPose();
            }
        }
        return;

    case 8: // Native 0x00607FD3: recovery to grounded neutral pose
        velocityX = 0.0;
        velocityY = 0.0;
        FaceOpponent();
        ++field000c;
        if (field000c >= timing.frameDuration) {
            field000c = 0;
            ++field000a;
            if (field000a >= timing.animationFrameCount) {
                field0008 = 3;
                ResetPose();
            }
        }
        return;

    case 9: // Native 0x00608056: falling physics and landing transition
        velocityY += gravity;
        ++field000c;
        if (field000c >= timing.frameDuration) {
            field000c = 0;
            ++field000a;
            if (field000a >= timing.animationFrameCount)
                field000a = 0;
        }
        if (positionY + velocityY >= 0.0) {
            positionY = 0.0;
            pendingContextSoundSlot = 9;
            field0008 = 13;
            ResetPose();
        }
        return;


    case 13: // Native 0x00608103: landing to neutral directional recovery
        velocityX = 0.0;
        velocityY = 0.0;
        FaceOpponent();
        ++field000c;
        if (field000c >= timing.frameDuration) {
            field000c = 0;
            ++field000a;
            if (field000a >= timing.animationFrameCount) {
                field0008 = 7;
                if (inputY == 1)
                    field0008 = 3;
                ResetPose();
            }
        }
        return;

    case 14: // Native 0x0060819E: neutral aerial launch with dash carry
        gravity = 0.035;
        if (field000a == 0 && field000c == 0) {
            velocityY = -2.7;
            velocityX = 0.0;
            if ((unsigned char)dashMomentumFlag == 1) {
                velocityX = 0.4;
                dashMomentumFlag = 0;
            }
        }
        velocityY += gravity;
        ++field000c;
        if (field000c >= timing.frameDuration) {
            field000c = 0;
            ++field000a;
            if (field000a >= timing.animationFrameCount) {
                field0008 = 9;
                ResetPose();
            }
        }
        if (positionY + velocityY >= 0.0) {
            positionY = 0.0;
            pendingContextSoundSlot = 9;
            FaceOpponent();
            field0008 = 13;
            ResetPose();
        }
        return;

    case 15: // Native 0x006082BC: forward aerial launch with alternate dash
        gravity = 0.035;
        if (field000a == 0 && field000c == 0) {
            velocityY = -2.7;
            velocityX = 0.7;
            if ((unsigned char)dashMomentumFlag == 1) {
                velocityX = 1.1;
                dashMomentumFlag = 0;
            }
        }
        velocityY += gravity;
        ++field000c;
        if (field000c >= timing.frameDuration) {
            field000c = 0;
            ++field000a;
            if (field000a >= timing.animationFrameCount) {
                field0008 = 9;
                ResetPose();
            }
        }
        if (positionY + velocityY >= 0.0) {
            positionY = 0.0;
            pendingContextSoundSlot = 9;
            FaceOpponent();
            field0008 = 13;
            ResetPose();
        }
        return;

    case 16: // Native 0x006083DA: reverse launch and late landing recovery
        gravity = 0.035;
        if (field000a == 0 && field000c == 0) {
            velocityY = -2.7;
            velocityX = -0.7;
            if ((unsigned char)dashMomentumFlag == 1)
                dashMomentumFlag = 0;
        }
        velocityY += gravity;
        ++field000c;
        if (field000c >= timing.frameDuration) {
            field000c = 0;
            ++field000a;
            if (field000a >= timing.animationFrameCount) {
                field0008 = 9;
                ResetPose();
            }
        }
        if (positionY + velocityY >= 0.0 && field000a > 3) {
            positionY = 0.0;
            pendingContextSoundSlot = 9;
            FaceOpponent();
            field0008 = 13;
            ResetPose();
        }
        return;


    case 47: // Native 0x006084F8: aerial knockback with early-ground impact
        if (field000a == 0 && field000c == 0) {
            velocityX = 0.0;
            gravity = 0.035;
        }
        velocityY += gravity;
        if (positionY + velocityY > 0.0 && field000a < 2) {
            field000c = 0;
            field000a = 2;
            pendingContextSoundSlot = 7;
            positionY = 0.0;
            velocityY = 0.0;
            gravity = 0.0;
            velocityX = 0.0;
        }
        ++field000c;
        if (field000c >= timing.frameDuration) {
            field000c = 0;
            ++field000a;
            if (field000a == 2) {
                field000a = (unsigned short)(field000a - 2);
            }
            if (field000a >= timing.animationFrameCount) {
                --field000a;
            }
        }
        return;

    case 50: // Native 0x00608628: grounded recoil and wall pushback
        if (field0120 != 0) {
            field0118 -= 0.6;
        }
        if (field000a == 0 && field000c == 0) {
            meter = (short)(meter + 10);
            velocityX = (2.0 - (*opponentSlot)->comboDamageScale / 10000.0) * -1.1;
            if (field0120 != 0) {
                field0118 -= 10.0;
            }
        }
        velocityY = 0.0;
        positionY = 0.0;
        velocityX += 0.06;
        if (velocityX > 0.0) {
            velocityX = 0.0;
        }
        if (positionX - 20.0 <= 0.0 || positionX + 20.0 >= 639.0) {
            // Preserve the original signed ground-height test even though
            // positionY has just been set to zero in this branch.
            outgoingPushbackVelocityX =
                (1.0 - (double)(positionY < 0.0) * 0.2) * velocityX;
        } else {
            outgoingPushbackVelocityX = 0.0;
        }
        ++field000c;
        if (field000c >= timing.frameDuration) {
            field000c = 0;
            ++field000a;
            if (field000a >= timing.animationFrameCount) {
                field0008 = 0;
                if (inputY == 1) field0008 = 3;
                ResetPose();
            }
        }
        return;


    case 51: // Native 0x0060880F: second grounded recoil tier
        if (field0120 != 0) {
            field0118 -= 0.6;
        }
        if (field000a == 0 && field000c == 0) {
            meter = (short)(meter + 15);
            velocityX = (2.0 - (*opponentSlot)->comboDamageScale / 10000.0) * -1.5;
            if (field0120 != 0) {
                field0118 -= 20.0;
            }
        }
        velocityY = 0.0;
        positionY = 0.0;
        velocityX += 0.06;
        if (velocityX > 0.0) {
            velocityX = 0.0;
        }
        if (positionX - 20.0 <= 0.0 || positionX + 20.0 >= 639.0) {
            // Preserve the original signed ground-height test even though
            // positionY has just been set to zero in this branch.
            outgoingPushbackVelocityX =
                (1.0 - (double)(positionY < 0.0) * 0.2) * velocityX;
        } else {
            outgoingPushbackVelocityX = 0.0;
        }
        ++field000c;
        if (field000c >= timing.frameDuration) {
            field000c = 0;
            ++field000a;
            if (field000a >= timing.animationFrameCount) {
                field0008 = 0;
                if (inputY == 1) field0008 = 3;
                ResetPose();
            }
        }
        return;


    case 52: // Native 0x006089F6: original grounded recoil tier
        if (field0120 != 0) {
            field0118 -= 0.6;
        }
        if (field000a == 0 && field000c == 0) {
            meter = (short)(meter + 20);
            velocityX = (2.0 - (*opponentSlot)->comboDamageScale / 10000.0) * -1.8;
            if (field0120 != 0) {
                field0118 -= 30.0;
            }
        }
        velocityY = 0.0;
        positionY = 0.0;
        velocityX += 0.06;
        if (velocityX > 0.0) {
            velocityX = 0.0;
        }
        if (positionX - 20.0 <= 0.0 || positionX + 20.0 >= 639.0) {
            // Preserve the original signed ground-height test even though
            // positionY has just been set to zero in this branch.
            outgoingPushbackVelocityX =
                (1.0 - (double)(positionY < 0.0) * 0.2) * velocityX;
        } else {
            outgoingPushbackVelocityX = 0.0;
        }
        ++field000c;
        if (field000c >= timing.frameDuration) {
            field000c = 0;
            ++field000a;
            if (field000a >= timing.animationFrameCount) {
                field0008 = 0;
                if (inputY == 1) field0008 = 3;
                ResetPose();
            }
        }
        return;

    case 53: // Native 0x00608BDD: original grounded recoil tier
        if (field0120 != 0) {
            field0118 -= 0.6;
        }
        if (field000a == 0 && field000c == 0) {
            meter = (short)(meter + 10);
            velocityX = (2.0 - (*opponentSlot)->comboDamageScale / 10000.0) * -1.1;
            if (field0120 != 0) {
                field0118 -= 10.0;
            }
        }
        velocityY = 0.0;
        positionY = 0.0;
        velocityX += 0.06;
        if (velocityX > 0.0) {
            velocityX = 0.0;
        }
        if (positionX - 20.0 <= 0.0 || positionX + 20.0 >= 639.0) {
            outgoingPushbackVelocityX =
                (1.0 - (double)(positionY < 0.0) * 0.2) * velocityX;
        } else {
            outgoingPushbackVelocityX = 0.0;
        }
        ++field000c;
        if (field000c >= timing.frameDuration) {
            field000c = 0;
            ++field000a;
            if (field000a >= timing.animationFrameCount) {
                field0008 = 0;
                if (inputY == 1) field0008 = 3;
                ResetPose();
            }
        }
        return;

    case 54: // Native 0x00608DC4: original grounded recoil tier
        if (field0120 != 0) {
            field0118 -= 0.6;
        }
        if (field000a == 0 && field000c == 0) {
            meter = (short)(meter + 15);
            velocityX = (2.0 - (*opponentSlot)->comboDamageScale / 10000.0) * -1.5;
            if (field0120 != 0) {
                field0118 -= 20.0;
            }
        }
        velocityY = 0.0;
        positionY = 0.0;
        velocityX += 0.06;
        if (velocityX > 0.0) {
            velocityX = 0.0;
        }
        if (positionX - 20.0 <= 0.0 || positionX + 20.0 >= 639.0) {
            outgoingPushbackVelocityX =
                (1.0 - (double)(positionY < 0.0) * 0.2) * velocityX;
        } else {
            outgoingPushbackVelocityX = 0.0;
        }
        ++field000c;
        if (field000c >= timing.frameDuration) {
            field000c = 0;
            ++field000a;
            if (field000a >= timing.animationFrameCount) {
                field0008 = 0;
                if (inputY == 1) field0008 = 3;
                ResetPose();
            }
        }
        return;


    case 55: // Native Character04 0x00608FAB: distinct crouch/ground recoil
        if (field0120 != 0) {
            field0118 -= 0.6;
        }
        if (field000a == 0 && field000c == 0) {
            meter = (short)(meter + 20);
            velocityX = (2.0 - (*opponentSlot)->comboDamageScale / 10000.0) * -1.8;
            if (field0120 != 0) {
                field0118 -= 30.0;
            }
        }
        velocityY = 0.0;
        positionY = 0.0;
        velocityX += 0.06;
        if (velocityX > 0.0) {
            velocityX = 0.0;
        }
        if (positionX - 20.0 <= 0.0 || positionX + 20.0 >= 639.0) {
            outgoingPushbackVelocityX =
                (1.0 - (double)(positionY < 0.0) * 0.2) * velocityX;
        } else {
            outgoingPushbackVelocityX = 0.0;
        }
        ++field000c;
        if (field000c >= timing.frameDuration) {
            field000c = 0;
            ++field000a;
            if (field000a >= timing.animationFrameCount) {
                field0008 = 0;
                if (inputY == 1) field0008 = 3;
                ResetPose();
            }
        }
        return;

    case 56: // Native Character04 0x00609192: distinct crouch/ground recoil
        if (field0120 != 0) {
            field0118 -= 0.6;
        }
        if (field000a == 0 && field000c == 0) {
            meter = (short)(meter + 10);
            velocityX = (2.0 - (*opponentSlot)->comboDamageScale / 10000.0) * -1.1;
            if (field0120 != 0) {
                field0118 -= 10.0;
            }
        }
        velocityY = 0.0;
        positionY = 0.0;
        velocityX += 0.06;
        if (velocityX > 0.0) {
            velocityX = 0.0;
        }
        if (positionX - 20.0 <= 0.0 || positionX + 20.0 >= 639.0) {
            outgoingPushbackVelocityX =
                (1.0 - (double)(positionY < 0.0) * 0.2) * velocityX;
        } else {
            outgoingPushbackVelocityX = 0.0;
        }
        ++field000c;
        if (field000c >= timing.frameDuration) {
            field000c = 0;
            ++field000a;
            if (field000a >= timing.animationFrameCount) {
                // Unlike cases 50-55, this recovery always chooses crouch.
                field0008 = 3;
                ResetPose();
            }
        }
        return;

    case 57: // Native Character04 0x00609361: distinct crouch/ground recoil
        if (field0120 != 0) {
            field0118 -= 0.6;
        }
        if (field000a == 0 && field000c == 0) {
            meter = (short)(meter + 15);
            velocityX = (2.0 - (*opponentSlot)->comboDamageScale / 10000.0) * -1.5;
            if (field0120 != 0) {
                field0118 -= 20.0;
            }
        }
        velocityY = 0.0;
        positionY = 0.0;
        velocityX += 0.06;
        if (velocityX > 0.0) {
            velocityX = 0.0;
        }
        if (positionX - 20.0 <= 0.0 || positionX + 20.0 >= 639.0) {
            outgoingPushbackVelocityX =
                (1.0 - (double)(positionY < 0.0) * 0.2) * velocityX;
        } else {
            outgoingPushbackVelocityX = 0.0;
        }
        ++field000c;
        if (field000c >= timing.frameDuration) {
            field000c = 0;
            ++field000a;
            if (field000a >= timing.animationFrameCount) {
                // Unlike cases 50-55, this recovery always chooses crouch.
                field0008 = 3;
                ResetPose();
            }
        }
        return;

    case 58: // Native Character04 0x00609530: distinct crouch/ground recoil
        if (field0120 != 0) {
            field0118 -= 0.6;
        }
        if (field000a == 0 && field000c == 0) {
            meter = (short)(meter + 20);
            velocityX = (2.0 - (*opponentSlot)->comboDamageScale / 10000.0) * -1.8;
            if (field0120 != 0) {
                field0118 -= 30.0;
            }
        }
        velocityY = 0.0;
        positionY = 0.0;
        velocityX += 0.06;
        if (velocityX > 0.0) {
            velocityX = 0.0;
        }
        if (positionX - 20.0 <= 0.0 || positionX + 20.0 >= 639.0) {
            outgoingPushbackVelocityX =
                (1.0 - (double)(positionY < 0.0) * 0.2) * velocityX;
        } else {
            outgoingPushbackVelocityX = 0.0;
        }
        ++field000c;
        if (field000c >= timing.frameDuration) {
            field000c = 0;
            ++field000a;
            if (field000a >= timing.animationFrameCount) {
                // Unlike cases 50-55, this recovery always chooses crouch.
                field0008 = 3;
                ResetPose();
            }
        }
        return;


    case 59: // Native C04 0x006096FF: original airborne hit and collision recovery
        if (field0120 != 0) {
            field0118 -= 0.8;
        }
        if (field000a == 0 && field000c == 0) {
            meter = (short)(meter + 30);
            velocityX = knockbackVelocityX;
            velocityY = velocityY * 0.75 + knockbackVelocityY;
            if (velocityY < -2.0) {
                velocityY = -2.0;
            } else if (velocityY > -0.5) {
                velocityY = -0.5;
            }
            gravity = 0.032;
        }
        if (velocityY <= 0.0) {
            field000a = 1;
            field000c = 0;
        }
        if (velocityY >= 0.0 && field000a <= 1) {
            field000a = 2;
            field000c = 0;
        }
        velocityY += gravity;
        ++field000c;
        if (field000c >= timing.frameDuration) {
            field000c = 0;
            ++field000a;
            if (field000a >= timing.animationFrameCount) {
                field000a = (unsigned short)(field000a - 2);
            }
        }
        if (positionY + velocityY >= 0.0 && field000a > 1) {
            positionY = 0.0;
            if (knockdownOnLanding != 0) {
                field0008 = 0x61;
                ResetPose();
            } else {
                field0008 = 0x62;
                ResetPose();
            }
        }
        return;

    case 60: // Native C04 0x006098FE: original airborne hit and collision recovery
        if (field0120 != 0) {
            field0118 -= 0.8;
        }
        if (field000a == 0 && field000c == 0) {
            meter = (short)(meter + 30);
            velocityX = knockbackVelocityX;
            velocityY = velocityY * 0.75 + knockbackVelocityY;
            if (velocityY < -4.0) {
                velocityY = -4.0;
            } else if (velocityY > -0.5) {
                velocityY = -0.5;
            }
            gravity = 0.032;
        }
        if (velocityY <= 0.0) {
            field000a = 1;
            field000c = 0;
        }
        if (velocityY >= 0.0 && field000a <= 1) {
            field000a = 2;
            field000c = 0;
        }
        velocityY += gravity;
        ++field000c;
        if (field000c >= timing.frameDuration) {
            field000c = 0;
            ++field000a;
            if (field000a >= timing.animationFrameCount) {
                field000a = (unsigned short)(field000a - 2);
            }
        }
        if (positionY + velocityY >= 0.0 && field000a > 1) {
            positionY = 0.0;
            if (knockdownOnLanding != 0) {
                field0008 = 0x61;
                ResetPose();
            } else {
                field0008 = 0x62;
                ResetPose();
            }
        }
        return;

    case 61: // Native C04 0x00609AFD: original airborne hit and collision recovery
        if (field0120 != 0) {
            field0118 -= 0.8;
        }
        if (field000a == 0 && field000c == 0) {
            meter = (short)(meter + 30);
            velocityX = knockbackVelocityX;
            velocityY = velocityY * 0.75 + knockbackVelocityY;
            if (velocityY < -6.0) {
                velocityY = -6.0;
            } else if (velocityY > -0.5) {
                velocityY = -0.5;
            }
            gravity = 0.032;
        }
        if (velocityY <= 0.0) {
            field000a = 1;
            field000c = 0;
        }
        if (velocityY >= 0.0 && field000a <= 1) {
            field000a = 2;
            field000c = 0;
        }
        velocityY += gravity;
        ++field000c;
        if (field000c >= timing.frameDuration) {
            field000c = 0;
            ++field000a;
            if (field000a >= timing.animationFrameCount) {
                field000a = (unsigned short)(field000a - 2);
            }
        }
        if (positionY + velocityY >= 0.0 && field000a > 1) {
            positionY = 0.0;
            if (knockdownOnLanding != 0) {
                field0008 = 0x61;
                ResetPose();
            } else {
                field0008 = 0x62;
                ResetPose();
            }
        }
        return;


    case 62: // Native Character04 0x00609CFC: airborne landing and wall recovery
        if (field0120 != 0) {
            field0118 -= 0.8;
        }
        if (field000a == 0 && field000c == 0) {
            meter = (short)(meter + 30);
            velocityX = knockbackVelocityX;
            velocityY = velocityY * 0.75 + knockbackVelocityY;
            gravity = 0.032;
        }
        if (velocityY <= 0.0) {
            field000a = 1;
            field000c = 0;
        }
        if (velocityY >= 0.0 && field000a <= 1) {
            field000a = 2;
            field000c = 0;
        }
        velocityY += gravity;
        ++field000c;
        if (field000c >= timing.frameDuration) {
            field000c = 0;
            ++field000a;
            if (field000a >= timing.animationFrameCount) {
                field000a = (unsigned short)(field000a - 2);
            }
        }
        if (positionY + velocityY >= 0.0 && field000a > 1) {
            positionY = 0.0;
            if (knockdownOnLanding != 0) {
                field0008 = 0x61;
                ResetPose();
            } else {
                field0008 = 0x62;
                ResetPose();
            }
        }
        return;

    case 63: // Native Character04 0x00609EB3: airborne landing and wall recovery
        if (field0120 != 0) {
            field0118 -= 0.8;
        }
        if (field000a == 0 && field000c == 0) {
            meter = (short)(meter + 30);
            velocityX = knockbackVelocityX;
            velocityY = knockbackVelocityY;
            gravity = 0.032;
        }
        if (velocityY <= 0.0) {
            field000a = 1;
            field000c = 0;
        }
        if (velocityY >= 0.0 && field000a <= 1) {
            field000a = 2;
            field000c = 0;
        }
        velocityY += gravity;
        ++field000c;
        if (field000c >= timing.frameDuration) {
            field000c = 0;
            ++field000a;
            if (field000a >= timing.animationFrameCount) {
                field000a = (unsigned short)(field000a - 2);
            }
        }
        if (positionY + velocityY >= 0.0 && field000a > 1) {
            positionY = 0.0;
            if (knockdownOnLanding != 0) {
                field0008 = 0x61;
                ResetPose();
            } else {
                field0008 = 0x62;
                ResetPose();
            }
        }
        return;

    case 64: // Native Character04 0x0060A05E: airborne landing and wall recovery
        if (field0120 != 0) {
            field0118 -= 0.8;
        }
        if (field000a > 0 && CollisionSide() != 0) {
            field0008 = 70;
            ResetPose();
            return;
        }
        if (field000a == 0 && field000c == 0) {
            meter = (short)(meter + 30);
            velocityX = knockbackVelocityX;
            velocityY = velocityY * 0.75 + knockbackVelocityY;
            if (velocityY < -2.0) {
                velocityY = -2.0;
            } else if (velocityY > -0.5) {
                velocityY = -0.5;
            }
            gravity = 0.032;
        }
        if (velocityY <= 0.0) {
            field000a = 1;
            field000c = 0;
        }
        if (velocityY >= 0.0 && field000a <= 1) {
            field000a = 2;
            field000c = 0;
        }
        velocityY += gravity;
        ++field000c;
        if (field000c >= timing.frameDuration) {
            field000c = 0;
            ++field000a;
            if (field000a >= timing.animationFrameCount) {
                field000a = (unsigned short)(field000a - 2);
            }
        }
        if (positionY + velocityY >= 0.0 && field000a > 1) {
            positionY = 0.0;
            if (knockdownOnLanding != 0) {
                field0008 = 0x61;
                ResetPose();
            } else {
                field0008 = 0x62;
                ResetPose();
            }
        }
        return;

    case 65: // Native Character04 0x0060A28F: airborne landing and wall recovery
        if (field0120 != 0) {
            field0118 -= 0.8;
        }
        if (field000a > 0 && CollisionSide() != 0) {
            field0008 = 70;
            ResetPose();
            return;
        }
        if (field000a == 0 && field000c == 0) {
            meter = (short)(meter + 30);
            velocityX = knockbackVelocityX;
            velocityY = velocityY * 0.75 + knockbackVelocityY;
            if (velocityY < -4.0) {
                velocityY = -4.0;
            } else if (velocityY > -0.5) {
                velocityY = -0.5;
            }
            gravity = 0.032;
        }
        if (velocityY <= 0.0) {
            field000a = 1;
            field000c = 0;
        }
        if (velocityY >= 0.0 && field000a <= 1) {
            field000a = 2;
            field000c = 0;
        }
        velocityY += gravity;
        ++field000c;
        if (field000c >= timing.frameDuration) {
            field000c = 0;
            ++field000a;
            if (field000a >= timing.animationFrameCount) {
                field000a = (unsigned short)(field000a - 2);
            }
        }
        if (positionY + velocityY >= 0.0 && field000a > 1) {
            positionY = 0.0;
            if (knockdownOnLanding != 0) {
                field0008 = 0x61;
                ResetPose();
            } else {
                field0008 = 0x62;
                ResetPose();
            }
        }
        return;


    case 66: // Native Character04 0x0060A4C0: wall collision / landing special
        if (field0120 != 0) {
            field0118 -= 0.8;
        }
        if (field000a > 0 && CollisionSide() != 0) {
            field0008 = 70;
            ResetPose();
            return;
        }
        if (field000a == 0 && field000c == 0) {
            meter = (short)(meter + 30);
            velocityX = knockbackVelocityX;
            velocityY = velocityY * 0.75 + knockbackVelocityY;
            gravity = 0.032;
        }
        if (velocityY <= 0.0) {
            field000a = 1;
            field000c = 0;
        }
        if (velocityY >= 0.0 && field000a <= 1) {
            field000a = 2;
            field000c = 0;
        }
        velocityY += gravity;
        ++field000c;
        if (field000c >= timing.frameDuration) {
            field000c = 0;
            ++field000a;
            if (field000a >= timing.animationFrameCount) {
                field000a = (unsigned short)(field000a - 2);
            }
        }
        if (positionY + velocityY >= 0.0 && field000a > 1) {
            positionY = 0.0;
            if (knockdownOnLanding != 0) {
                field0008 = 0x61;
                ResetPose();
            } else {
                field0008 = 0x62;
                ResetPose();
            }
        }
        return;

    case 67: // Native Character04 0x0060A6A9: wall collision / landing special
        if (field0120 != 0) {
            field0118 -= 0.8;
        }
        if (field000a > 0 && CollisionSide() != 0) {
            field0008 = 70;
            ResetPose();
            return;
        }
        if (field000a == 0 && field000c == 0) {
            meter = (short)(meter + 30);
            velocityX = knockbackVelocityX;
            velocityY = knockbackVelocityY;
            gravity = 0.032;
        }
        if (velocityY <= 0.0) {
            field000a = 1;
            field000c = 0;
        }
        if (velocityY >= 0.0 && field000a <= 1) {
            field000a = 2;
            field000c = 0;
        }
        velocityY += gravity;
        ++field000c;
        if (field000c >= timing.frameDuration) {
            field000c = 0;
            ++field000a;
            if (field000a >= timing.animationFrameCount) {
                field000a = (unsigned short)(field000a - 2);
            }
        }
        if (positionY + velocityY >= 0.0 && field000a > 1) {
            positionY = 0.0;
            if (knockdownOnLanding != 0) {
                field0008 = 0x61;
                ResetPose();
            } else {
                field0008 = 0x62;
                ResetPose();
            }
        }
        return;

    case 68: // Native Character04 0x0060A886: wall collision / landing special
        if (field0120 != 0) {
            field0118 -= 1.5;
        }
        meter = (short)(meter + 3);
        velocityX = knockbackVelocityX;
        velocityY = knockbackVelocityY;
        ++field000c;
        if (CollisionSide() != 0) {
            field0008 = 70;
            ResetPose();
            return;
        }
        if (field000c >= timing.frameDuration) {
            field000c = 0;
            ++field000a;
            if (field000a >= timing.animationFrameCount) {
                field000a = (unsigned short)(field000a - 2);
            }
        }
        if (positionY + velocityY >= 0.0) {
            positionY = 0.0;
            if (knockdownOnLanding != 0) {
                field0008 = 0x61;
                ResetPose();
            } else {
                field0008 = 0x62;
                ResetPose();
            }
        }
        return;

    case 69: // Native Character04 0x0060A9C2: wall collision / landing special
        if (field0120 != 0) {
            field0118 -= 1.5;
        }
        meter = (short)(meter + 3);
        velocityX = knockbackVelocityX;
        velocityY = knockbackVelocityY;
        ++field000c;
        if (field000c >= timing.frameDuration) {
            field000c = 0;
            ++field000a;
            if (field000a >= timing.animationFrameCount) {
                field000a = (unsigned short)(field000a - 2);
            }
        }
        if (positionY + velocityY >= 0.0) {
            positionY = 0.0;
            if (knockdownOnLanding != 0) {
                field0008 = 0x61;
                ResetPose();
            } else {
                field0008 = 0x62;
                ResetPose();
            }
        }
        return;

    case 70: // Native Character04 0x0060AAD7: wall collision / landing special
        if (field0120 != 0) {
            field0118 -= 0.8;
        }
        if (field000a == 0 && field000c == 0 && reinterpret_cast<Character04StatePrivate *>(this)->field3138 == 0) {
            meter = (short)(meter + 30);
            ++reinterpret_cast<Character04StatePrivate *>(this)->field3138;
            airActionLockFrames = (short)(airActionLockFrames + 120);
            velocityX = 0.5;
            velocityY = -2.5;
            gravity = 0.025;
            pendingContextSoundSlot = 31;

            effect.type = 0;
            effect.x = (double)(int)positionX;
            effect.y = (double)(int)positionY;
            effect.group = 2;
            effect.layer = 1;
            contextOwner->EmitEffect(&effect);
        }
        velocityY += gravity;
        ++field000c;
        if (field000c >= timing.frameDuration) {
            field000c = 0;
            ++field000a;
            if (field000a >= timing.animationFrameCount) {
                field000a = 0;
            }
        }
        if (positionY + velocityY >= 0.0 && field000a > 1) {
            positionY = 0.0;
            if (knockdownOnLanding != 0) {
                field0008 = 0x61;
                ResetPose();
            } else {
                field0008 = 0x62;
                ResetPose();
            }
        }
        return;


    case 71: // Native Character04 0x0060ACB7: authentic air or grounded recoil
        if (field0120 != 0) {
            field0118 -= 0.8;
        }
        if (field000a == 0 && field000c == 0) {
            meter = (short)(meter + 30);
            velocityX = knockbackVelocityX;
            velocityY = knockbackVelocityY;
            gravity = 0.072;
        }
        if (velocityY <= 0.0) {
            field000a = 1;
            field000c = 0;
        }
        if (velocityY >= 0.0 && field000a <= 1) {
            field000a = 2;
            field000c = 0;
        }
        velocityY += gravity;
        ++field000c;
        if (field000c >= timing.frameDuration) {
            field000c = 0;
            ++field000a;
            if (field000a >= timing.animationFrameCount) {
                field000a = (unsigned short)(field000a - 2);
            }
        }
        if (positionY + velocityY >= 0.0 && field000a > 1) {
            positionY = 0.0;
            if (knockdownOnLanding != 0) {
                field0008 = 0x61;
                ResetPose();
            } else {
                field0008 = 0x62;
                ResetPose();
            }
        }
        return;

    case 72: // Native Character04 0x0060AE62: authentic air or grounded recoil
        if (field0120 != 0) {
            field0118 -= 0.8;
        }
        velocityX = 0.0;
        velocityY = 0.0;
        if (positionX - 20.0 <= 0.0 || 639.0 <= positionX + 20.0) {
            outgoingPushbackVelocityX =
                (1.0 - (double)((*opponentSlot)->positionY < 0.0) * 0.25) * velocityX;
        } else {
            outgoingPushbackVelocityX = 0.0;
        }
        ++field000c;
        if (field000c >= timing.frameDuration) {
            field000c = 0;
            ++field000a;
            if (field000a >= timing.animationFrameCount) {
                field0008 = 7;
                if (inputY == 1) {
                    field0008 = 3;
                }
                ResetPose();
            }
        }
        return;

    case 73: // Native Character04 0x0060AFAD: authentic air or grounded recoil
        if (field0120 != 0) {
            field0118 -= 0.8;
        }
        velocityX = 0.0;
        velocityY = 0.0;
        if (positionX - 20.0 <= 0.0 || 639.0 <= positionX + 20.0) {
            outgoingPushbackVelocityX =
                (1.0 - (double)((*opponentSlot)->positionY < 0.0) * 0.25) * velocityX;
        } else {
            outgoingPushbackVelocityX = 0.0;
        }
        ++field000c;
        if (field000c >= timing.frameDuration) {
            field000c = 0;
            ++field000a;
            if (field000a >= timing.animationFrameCount) {
                field0008 = 7;
                if (inputY == 1) {
                    field0008 = 3;
                }
                ResetPose();
            }
        }
        return;

    case 74: // Native Character04 0x0060B0F8: authentic air or grounded recoil
        if (field0120 != 0) {
            field0118 -= 0.8;
        }
        velocityX = 0.0;
        velocityY = 0.0;
        if (positionX - 20.0 <= 0.0 || 639.0 <= positionX + 20.0) {
            outgoingPushbackVelocityX =
                (1.0 - (double)((*opponentSlot)->positionY < 0.0) * 0.25) * velocityX;
        } else {
            outgoingPushbackVelocityX = 0.0;
        }
        ++field000c;
        if (field000c >= timing.frameDuration) {
            field000c = 0;
            ++field000a;
            if (field000a >= timing.animationFrameCount) {
                field0008 = 3;
                ResetPose();
            }
        }
        return;


    case 75: // Native Character04 0x0060B22B: grounded pushback tier
        if (field0120 != 0) {
            field0118 -= 0.6;
        }
        if (field000a == 0 && field000c == 0) {
            meter = (short)(meter + 30);
            if (field0120 != 0) {
                field0118 -= 30.0;
            }
            velocityX = 2.2;
        }
        velocityY = 0.0;
        positionY = 0.0;
        gravity = 0.0;
        horizontalDeceleration = 0.06;
        velocityX -= horizontalDeceleration;
        if (velocityX < 0.0) {
            velocityX = 0.0;
        }
        if (positionX - 20.0 <= 0.0 || positionX + 20.0 >= 639.0) {
            outgoingPushbackVelocityX =
                (1.0 - (double)((*opponentSlot)->positionY < 0.0) * 0.25) * velocityX;
        } else {
            outgoingPushbackVelocityX = 0.0;
        }
        ++field000c;
        if (field000c >= timing.frameDuration) {
            field000c = 0;
            ++field000a;
            if (field000a >= timing.animationFrameCount) {
                field0008 = 7;
                if (inputY == 1) {
                    field0008 = 3;
                }
                ResetPose();
            }
        }
        return;

    case 76: // Native Character04 0x0060B41E: grounded pushback tier
        if (field0120 != 0) {
            field0118 -= 0.6;
        }
        if (field000a == 0 && field000c == 0) {
            meter = (short)(meter + 30);
            if (field0120 != 0) {
                field0118 -= 30.0;
            }
            velocityX = 2.2;
        }
        velocityY = 0.0;
        positionY = 0.0;
        gravity = 0.0;
        horizontalDeceleration = 0.06;
        velocityX -= horizontalDeceleration;
        if (velocityX < 0.0) {
            velocityX = 0.0;
        }
        if (positionX - 20.0 <= 0.0 || positionX + 20.0 >= 639.0) {
            outgoingPushbackVelocityX =
                (1.0 - (double)((*opponentSlot)->positionY < 0.0) * 0.25) * velocityX;
        } else {
            outgoingPushbackVelocityX = 0.0;
        }
        ++field000c;
        if (field000c >= timing.frameDuration) {
            field000c = 0;
            ++field000a;
            if (field000a >= timing.animationFrameCount) {
                field0008 = 7;
                if (inputY == 1) {
                    field0008 = 3;
                }
                ResetPose();
            }
        }
        return;

    case 77: // Native Character04 0x0060B611: grounded pushback tier
        if (field0120 != 0) {
            field0118 -= 0.6;
        }
        if (field000a == 0 && field000c == 0) {
            meter = (short)(meter + 30);
            if (field0120 != 0) {
                field0118 -= 30.0;
            }
            velocityX = 2.2;
        }
        velocityY = 0.0;
        positionY = 0.0;
        gravity = 0.0;
        horizontalDeceleration = 0.06;
        velocityX -= horizontalDeceleration;
        if (velocityX < 0.0) {
            velocityX = 0.0;
        }
        if (positionX - 20.0 <= 0.0 || positionX + 20.0 >= 639.0) {
            outgoingPushbackVelocityX =
                (1.0 - (double)((*opponentSlot)->positionY < 0.0) * 0.25) * velocityX;
        } else {
            outgoingPushbackVelocityX = 0.0;
        }
        ++field000c;
        if (field000c >= timing.frameDuration) {
            field000c = 0;
            ++field000a;
            if (field000a >= timing.animationFrameCount) {
                field0008 = 3;
                ResetPose();
            }
        }
        return;


    case 81: // Native Character04 0x0060b7ec: aerial and landing transition
        if (field0120 != 0) {
            field0118 -= 0.8;
        }
        if (field000a == 0 && field000c == 0) {
            effect.type = 499;
            effect.x = (double)(int)positionX;
            effect.y = (double)(int)positionY;
            effect.flag0018 = (unsigned char)facing;
            effect.layer = 1;
            EmitLocalEffect(&effect);
            meter = (short)(meter + 30);
            velocityX = knockbackVelocityX;
            velocityY = knockbackVelocityY;
            gravity = 0.032;
        }
        velocityX += 0.02;
        velocityY += gravity;
        if (velocityX > 0.0) {
            velocityX = 0.0;
        }
        ++field000c;
        if (field000c >= timing.frameDuration) {
            field000c = 0;
            ++field000a;
            if (field000a >= timing.animationFrameCount) {
                --field000a;
            }
        }
        if (positionY + velocityY >= 0.0 && field000a == 1) {
            positionY = 0.0;
            if (knockdownOnLanding != 0) {
                field0008 = 0x61;
                ResetPose();
            } else {
                field0008 = 0x62;
                ResetPose();
            }
        }
        return;

    case 82: // Native Character04 0x0060b9d1: aerial and landing transition
        if (field0120 != 0) {
            field0118 -= 0.8;
        }
        if (field000a == 0 && field000c == 0 && reinterpret_cast<Character04StateFields *>(this)->field3138 == 0) {
            pendingContextSoundSlot = 30;
            velocityY = -0.45;
            velocityX = -0.1;
            ++reinterpret_cast<Character04StateFields *>(this)->field3138;
            meter = (short)(meter + 30);
        }
        if (field000a == 4 && field000c == 0) {
            velocityX = knockbackVelocityX;
            velocityY = knockbackVelocityY;
            gravity = 0.032;
        }
        if (velocityY > 0.0 && field000a == 4) {
            field000a = 5;
            field000c = 0;
        }
        if (field000a > 3) {
            velocityY += gravity;
        }
        ++field000c;
        if (field000c >= timing.frameDuration) {
            field000c = 0;
            ++field000a;
            if (field000a == 4 && reinterpret_cast<Character04StateFields *>(this)->field3138 < 8) {
                field000a = 0;
                ++reinterpret_cast<Character04StateFields *>(this)->field3138;
            }
            if (field000a >= timing.animationFrameCount) {
                field000a = (unsigned short)(field000a - 2);
            }
        }
        if (positionY + velocityY >= 0.0 && field000a > 4) {
            positionY = 0.0;
            if (knockdownOnLanding != 0) {
                field0008 = 0x61;
                ResetPose();
            } else {
                field0008 = 0x62;
                ResetPose();
            }
        }
        return;

    case 83: // Native Character04 0x0060bbf3: aerial and landing transition
        if (field000a == 0 && field000c == 0) {
            if (reinterpret_cast<Character04StateFields *>(this)->field3154 == 0) {
                effect.type = 0x1f0;
                effect.x = (double)(int)positionX;
                effect.y = (double)(int)positionY;
                effect.group = 0;
                effect.layer = 0;
                effect.owner = 1;
                effect.flag0018 = (unsigned char)facing;
                EmitLocalEffect(&effect);
                reinterpret_cast<Character04StateFields *>(this)->field3154 = 1;
            }
            if (field0120 != 0) {
                field0118 -= 30.0;
            }
            pendingContextSoundSlot = 33;
            velocityY = -1.5;
            velocityX = -0.8;
            meter = (short)(meter + 30);
        }
        velocityY += 0.04;
        if (field000a == 0 && velocityY + positionY > 0.0) {
            positionY = 0.0;
            velocityY = 0.0;
            field000c = 0;
            field000a = 1;
            return;
        }
        if (field000a == 1) {
            velocityX += 0.01;
        }
        if (field000a == 2 && field000c == 0) {
            velocityX = -2.0;
        }
        if (field000a > 1) {
            velocityX += 0.06;
        }
        if (velocityX > 0.0) {
            velocityX = 0.0;
        }
        ++field000c;
        if (field000c >= timing.frameDuration) {
            field000c = 0;
            ++field000a;
            if (field000a >= timing.animationFrameCount) {
                field0008 = 0;
                ResetPose();
                FaceOpponent();
            }
        }
        return;

    case 84: // Native Character04 0x0060be38: aerial and landing transition
        if (field000a == 0 && field000c == 0) {
            if (reinterpret_cast<Character04StateFields *>(this)->field3154 == 0) {
                effect.type = 0x1f0;
                effect.x = (double)(int)positionX;
                effect.y = (double)(int)positionY;
                effect.group = 0;
                effect.layer = 0;
                effect.owner = 1;
                effect.flag0018 = (unsigned char)facing;
                EmitLocalEffect(&effect);
                reinterpret_cast<Character04StateFields *>(this)->field3154 = 1;
            }
            if (field0120 != 0) {
                field0118 -= 30.0;
            }
            pendingContextSoundSlot = 33;
            velocityY = -1.5;
            velocityX = -0.8;
            meter = (short)(meter + 30);
        }
        velocityY += 0.04;
        if (field000a == 0 && velocityY + positionY > 0.0) {
            positionY = 0.0;
            velocityY = 0.0;
            field000c = 0;
            field000a = 1;
            return;
        }
        if (field000a == 1) {
            velocityX += 0.01;
        }
        if (field000a == 2 && field000c == 0) {
            velocityX = -2.0;
        }
        if (field000a > 1) {
            velocityX += 0.06;
        }
        if (velocityX > 0.0) {
            velocityX = 0.0;
        }
        ++field000c;
        if (field000c >= timing.frameDuration) {
            field000c = 0;
            ++field000a;
            if (field000a >= timing.animationFrameCount) {
                field0008 = 0;
                ResetPose();
                FaceOpponent();
            }
        }
        return;

    case 85: // Native Character04 0x0060c07d: aerial and landing transition
        if (field000a == 0 && field000c == 0) {
            if (reinterpret_cast<Character04StateFields *>(this)->field3154 == 0) {
                effect.type = 0x1f0;
                effect.x = (double)(int)positionX;
                effect.y = (double)(int)positionY;
                effect.group = 0;
                effect.layer = 0;
                effect.owner = 1;
                effect.flag0018 = (unsigned char)facing;
                EmitLocalEffect(&effect);
                reinterpret_cast<Character04StateFields *>(this)->field3154 = 1;
            }
            if (field0120 != 0) {
                field0118 -= 30.0;
            }
            pendingContextSoundSlot = 33;
            velocityX = knockbackVelocityX;
            velocityY = knockbackVelocityY;
            meter = (short)(meter + 30);
        }
        velocityY += 0.04;
        ++field000c;
        if (field000c >= timing.frameDuration) {
            field000c = 0;
            ++field000a;
            if (field000a >= timing.animationFrameCount) {
                field0008 = 0;
                ResetPose();
                FaceOpponent();
            }
        }
        if (positionY + velocityY >= 0.0) {
            positionY = 0.0;
            if (knockdownOnLanding != 0) {
                field0008 = 0x61;
                ResetPose();
            } else {
                field0008 = 0x62;
                ResetPose();
            }
        }
        return;

    case 86: // Native Character04 0x0060c250: aerial and landing transition
        if (field000a == 0 && field000c == 0) {
            if (reinterpret_cast<Character04StateFields *>(this)->field3154 == 0) {
                effect.type = 0x1f0;
                effect.x = (double)(int)positionX;
                effect.y = (double)(int)positionY;
                effect.group = 0;
                effect.layer = 0;
                effect.owner = 1;
                effect.flag0018 = (unsigned char)facing;
                EmitLocalEffect(&effect);
                reinterpret_cast<Character04StateFields *>(this)->field3154 = 1;
            }
            // Unlike state 85, this launch is suppressed after its first use.
            if (reinterpret_cast<Character04StateFields *>(this)->field3138 == 0) {
                if (field0120 != 0) {
                    field0118 -= 30.0;
                }
                pendingContextSoundSlot = 33;
                velocityX = knockbackVelocityX;
                velocityY = knockbackVelocityY;
                meter = (short)(meter + 30);
                ++reinterpret_cast<Character04StateFields *>(this)->field3138;
            }
        }
        // 0x00787DA8 holds 0.06, not the 0.04 used by state 85.
        velocityY += 0.06;
        ++field000c;
        if (field000c >= timing.frameDuration) {
            field000c = 0;
            ++field000a;
            if (field000a >= timing.animationFrameCount) {
                field000a = 0;
            }
        }
        if (positionY + velocityY >= 0.0) {
            positionY = 0.0;
            if (knockdownOnLanding != 0) {
                field0008 = 0x61;
                ResetPose();
            } else {
                field0008 = 0x62;
                ResetPose();
            }
        }
        return;

    case 87: // Native Character04 0x0060c432: aerial and landing transition
        if (field000a == 0 && field000c == 0) {
            effect.type = 0x1ef;
            effect.x = 60.0;
            effect.y = 40.0;
            effect.payload = 1;
            effect.flag0018 = 1;
            effect.group = 0;
            effect.layer = 0;
            EmitLocalEffect(&effect);
        }
        ++field000c;
        if (field000c >= timing.frameDuration) {
            field000c = 0;
            ++field000a;
            if (field000a >= timing.animationFrameCount) {
                field0008 = 0;
                ResetPose();
            }
        }
        return;


    case 96: // Native C04 0x0060C4E5: original knockout and reset
        ++field000c;
        if (field000c >= timing.frameDuration) {
            field000c = 0;
            ++field000a;
            // Face one frame before the animation ends, not at the end.
            if (field000a == timing.animationFrameCount - 1) {
                FaceOpponent();
            }
            if (field000a >= timing.animationFrameCount) {
                field0008 = 0;
                if (inputY == 1) {
                    field0008 = 3;
                }
                ResetPose();
            }
        }
        return;

    case 97: // Native C04 0x0060C57A: original knockout and reset
        velocityX = 0.0;
        velocityY = 0.0;
        if (field000a == 0 && field000c == 0) {
            SetVerticalShake(3, 0);
            effect.type = 3;
            effect.x = (double)(int)positionX;
            effect.y = (double)(int)positionY;
            effect.group = 2;
            effect.layer = 0;
            contextOwner->EmitEffect(&effect);
            pendingContextSoundSlot = 7;
        }
        ++field000c;
        if (field000c >= timing.frameDuration) {
            field000c = 0;
            ++field000a;
            if (field000a >= timing.animationFrameCount) {
                field0008 = 99;
                ResetPose();
            }
        }
        return;

    case 98: // Native C04 0x0060C672: original knockout and reset
        velocityX = 0.0;
        velocityY = 0.0;
        if (field000a == 0 && field000c == 0) {
            SetVerticalShake(3, 0);
            effect.type = 3;
            effect.x = (double)(int)positionX;
            effect.y = (double)(int)positionY;
            effect.group = 2;
            effect.layer = 0;
            contextOwner->EmitEffect(&effect);
            pendingContextSoundSlot = 7;
        }
        ++field000c;
        if (field000c >= timing.frameDuration) {
            field000c = 0;
            ++field000a;
            if (field000a >= timing.animationFrameCount) {
                field0008 = 99;
                ResetPose();
            }
        }
        return;

    case 99: // Native C04 0x0060C76A: original knockout and reset
        // The target deliberately checks the tick count without a pose gate.
        if (health > 0 && field000c > 99 && field000a == 0) {
            field0008 = 96;
            ResetPose();
            return;
        }
        ++field000c;
        if (field000c >= timing.frameDuration) {
            field000c = 0;
            ++field000a;
            if (field000a == timing.animationFrameCount) {
                FaceOpponent();
            }
            if (field000a >= timing.animationFrameCount) {
                field0008 = 96;
                ResetPose();
            }
        }
        return;


    case 150: // Native Character04 0x0060C81F: original ground reaction and crouch/standing selector
        if (inputY == 1) {
            field0008 = 153;
        }
        if (inputY != 1) {
            field0008 = 150;
        }
        if (field000a == 0 && field000c == 0) {
            meter = (short)(meter + 10);
            velocityX = -1.5;
            velocityY = 0.0;
            positionY = 0.0;
        }
        velocityY = 0.0;
        velocityX += 0.06;
        if (velocityX > 0.0) {
            velocityX = 0.0;
        }
        if (positionX - 20.0 <= 0.0 || positionX + 20.0 >= 639.0) {
            outgoingPushbackVelocityX = velocityX;
        } else {
            outgoingPushbackVelocityX = 0.0;
        }
        ++field000c;
        if (field000c >= timing.frameDuration) {
            field000c = 0;
            ++field000a;
            if (field000a == timing.animationFrameCount) {
                FaceOpponent();
            }
            if (field000a >= timing.animationFrameCount) {
                field0008 = 0;
                if (inputY == 1) {
                    field0008 = 3;
                }
                ResetPose();
            }
        }
        return;

    case 151: // Native Character04 0x0060C9C1: original ground reaction and crouch/standing selector
        if (inputY == 1) {
            field0008 = 154;
        }
        if (inputY != 1) {
            field0008 = 151;
        }
        if (field000a == 0 && field000c == 0) {
            meter = (short)(meter + 15);
            velocityX = -1.8;
            velocityY = 0.0;
            positionY = 0.0;
        }
        velocityY = 0.0;
        velocityX += 0.06;
        if (velocityX > 0.0) {
            velocityX = 0.0;
        }
        if (positionX - 20.0 <= 0.0 || positionX + 20.0 >= 639.0) {
            outgoingPushbackVelocityX = velocityX;
        } else {
            outgoingPushbackVelocityX = 0.0;
        }
        ++field000c;
        if (field000c >= timing.frameDuration) {
            field000c = 0;
            ++field000a;
            if (field000a == timing.animationFrameCount) {
                FaceOpponent();
            }
            if (field000a >= timing.animationFrameCount) {
                field0008 = 0;
                if (inputY == 1) {
                    field0008 = 3;
                }
                ResetPose();
            }
        }
        return;

    case 152: // Native Character04 0x0060CB63: original ground reaction and crouch/standing selector
        if (inputY == 1) {
            field0008 = 155;
        }
        if (inputY != 1) {
            field0008 = 152;
        }
        if (field000a == 0 && field000c == 0) {
            meter = (short)(meter + 20);
            velocityX = -2.3;
            velocityY = 0.0;
            positionY = 0.0;
        }
        velocityY = 0.0;
        velocityX += 0.06;
        if (velocityX > 0.0) {
            velocityX = 0.0;
        }
        if (positionX - 20.0 <= 0.0 || positionX + 20.0 >= 639.0) {
            outgoingPushbackVelocityX = velocityX;
        } else {
            outgoingPushbackVelocityX = 0.0;
        }
        ++field000c;
        if (field000c >= timing.frameDuration) {
            field000c = 0;
            ++field000a;
            if (field000a == timing.animationFrameCount) {
                FaceOpponent();
            }
            if (field000a >= timing.animationFrameCount) {
                field0008 = 0;
                if (inputY == 1) {
                    field0008 = 3;
                }
                ResetPose();
            }
        }
        return;

    case 153: // Native Character04 0x0060CD05: original ground reaction and crouch/standing selector
        if (inputY == 1) {
            field0008 = 153;
        }
        if (inputY != 1) {
            field0008 = 150;
        }
        if (field000a == 0 && field000c == 0) {
            meter = (short)(meter + 10);
            velocityX = -1.5;
            velocityY = 0.0;
            positionY = 0.0;
        }
        velocityY = 0.0;
        velocityX += 0.06;
        if (velocityX > 0.0) {
            velocityX = 0.0;
        }
        if (positionX - 20.0 <= 0.0 || positionX + 20.0 >= 639.0) {
            outgoingPushbackVelocityX = velocityX;
        } else {
            outgoingPushbackVelocityX = 0.0;
        }
        ++field000c;
        if (field000c >= timing.frameDuration) {
            field000c = 0;
            ++field000a;
            if (field000a == timing.animationFrameCount) {
                FaceOpponent();
            }
            if (field000a >= timing.animationFrameCount) {
                field0008 = 3;
                ResetPose();
            }
        }
        return;

    case 154: // Native Character04 0x0060CE8F: original ground reaction and crouch/standing selector
        if (inputY == 1) {
            field0008 = 154;
        }
        if (inputY != 1) {
            field0008 = 151;
        }
        if (field000a == 0 && field000c == 0) {
            meter = (short)(meter + 15);
            velocityX = -1.8;
            velocityY = 0.0;
            positionY = 0.0;
        }
        velocityY = 0.0;
        velocityX += 0.06;
        if (velocityX > 0.0) {
            velocityX = 0.0;
        }
        if (positionX - 20.0 <= 0.0 || positionX + 20.0 >= 639.0) {
            outgoingPushbackVelocityX = velocityX;
        } else {
            outgoingPushbackVelocityX = 0.0;
        }
        ++field000c;
        if (field000c >= timing.frameDuration) {
            field000c = 0;
            ++field000a;
            if (field000a == timing.animationFrameCount) {
                FaceOpponent();
            }
            if (field000a >= timing.animationFrameCount) {
                field0008 = 3;
                ResetPose();
            }
        }
        return;

    case 155: // Native Character04 0x0060D019: original ground reaction and crouch/standing selector
        if (inputY == 1) {
            field0008 = 155;
        }
        if (inputY != 1) {
            field0008 = 152;
        }
        if (field000a == 0 && field000c == 0) {
            meter = (short)(meter + 20);
            velocityX = -2.3;
            velocityY = 0.0;
            positionY = 0.0;
        }
        velocityY = 0.0;
        velocityX += 0.06;
        if (velocityX > 0.0) {
            velocityX = 0.0;
        }
        if (positionX - 20.0 <= 0.0 || positionX + 20.0 >= 639.0) {
            outgoingPushbackVelocityX = velocityX;
        } else {
            outgoingPushbackVelocityX = 0.0;
        }
        ++field000c;
        if (field000c >= timing.frameDuration) {
            field000c = 0;
            ++field000a;
            if (field000a == timing.animationFrameCount) {
                FaceOpponent();
            }
            if (field000a >= timing.animationFrameCount) {
                field0008 = 3;
                ResetPose();
            }
        }
        return;


    case 156: // Native Character04 0x0060d1a3: original aerial knockback
        if (field000a == 0 && field000c == 0) {
            velocityY = -2.6;
            meter = (short)(meter + 15);
            gravity = 0.06;
        }
        velocityX = -1.2;
        velocityY += gravity;
        ++field000c;
        if (field000c >= timing.frameDuration) {
            field000c = 0;
            ++field000a;
            if (field000a >= timing.animationFrameCount) {
                field0008 = 9;
                ResetPose();
            }
        }
        if (positionY + velocityY >= 0.0) {
            positionY = 0.0;
            pendingContextSoundSlot = 9;
            FaceOpponent();
            field0008 = 13;
            ResetPose();
        }
        return;

    case 157: // Native Character04 0x0060d2b3: original aerial knockback
        velocityX = 1.0;
        gravity = 0.045;
        if (field000a == 0 && field000c == 0) {
            velocityY = -2.3;
            effect.type = 8;
            effect.x = (double)(int)positionX;
            effect.y = (double)(int)positionY;
            effect.group = 2;
            effect.layer = 0;
            contextOwner->EmitEffect(&effect);
        } else {
            velocityY += gravity;
        }
        ++field000c;
        if (field000c >= timing.frameDuration) {
            field000c = 0;
            ++field000a;
            if (field000a >= timing.animationFrameCount) {
                field0008 = 9;
                ResetPose();
            }
        }
        if (positionY + velocityY >= 0.0) {
            positionY = 0.0;
            pendingContextSoundSlot = 9;
            FaceOpponent();
            field0008 = 13;
            ResetPose();
        }
        return;

    case 158: // Native Character04 0x0060d3ff: original aerial knockback
        velocityX = -1.0;
        gravity = 0.045;
        if (field000a == 0 && field000c == 0) {
            velocityY = -2.3;
            effect.type = 8;
            effect.x = (double)(int)positionX;
            effect.y = (double)(int)positionY;
            effect.group = 2;
            effect.layer = 0;
            contextOwner->EmitEffect(&effect);
        } else {
            velocityY += gravity;
        }
        ++field000c;
        if (field000c >= timing.frameDuration) {
            field000c = 0;
            ++field000a;
            if (field000a >= timing.animationFrameCount) {
                field0008 = 9;
                ResetPose();
            }
        }
        if (positionY + velocityY >= 0.0) {
            positionY = 0.0;
            pendingContextSoundSlot = 9;
            FaceOpponent();
            field0008 = 13;
            ResetPose();
        }
        return;


    case 161: // Native Character04 0x0060D54B: aerial impact and repeated launch
        if (field000a == 0 && field000c == 0) {
            ResetFrame();
            effect.type = 9;
            effect.x = (double)(int)positionX;
            effect.y = (double)((int)positionY - 70);
            effect.group = 2;
            effect.layer = 1;
            contextOwner->EmitEffect(&effect);
            remainingHitCount = 1;
            pendingContextSoundSlot = 62;
            ++reinterpret_cast<Character04StateFields *>(this)->field3138;
        }
        ++field000c;
        if (field000c >= timing.frameDuration) {
            field000c = 0;
            ++field000a;
            if (field000a >= timing.animationFrameCount) {
                field0008 = 9;
                ResetPose();
                gravity = 0.035;
            }
        }
        return;

    case 162: // Native Character04 0x0060D65F: aerial impact and repeated launch
        if (field000a == 0 && field000c == 0) {
            ResetFrame();
        }
        if (field000a == 2 && field000c == 0) {
            velocityY = -1.5;
            gravity = 0.025;
            remainingHitCount = 1;
        }
        if (field000a == 7 && field000c == 0) {
            ResetFrame();
            effect.type = 9;
            effect.x = (double)(int)positionX;
            effect.y = (double)((int)positionY - 70);
            effect.group = 2;
            effect.layer = 1;
            contextOwner->EmitEffect(&effect);
            remainingHitCount = 1;
            pendingContextSoundSlot = 62;
            meter = (short)(meter - 1000);
            ++reinterpret_cast<Character04StateFields *>(this)->field3138;
        }
        velocityY += gravity;
        if (positionY + velocityY > 0.0) {
            field0008 = 13;
            ResetPose();
            ResetPose();
            positionY = 0.0;
            return;
        }
        ++field000c;
        if (field000c >= timing.frameDuration) {
            field000c = 0;
            ++field000a;
            if (field000a == 12) {
                gravity = 0.035;
            }
            if (field000a >= timing.animationFrameCount) {
                field000a = (unsigned short)(field000a - 2);
            }
        }
        return;


    case 163: // Native 0x0060D84A: original double-speed jump with state-specific physics
        if (field000a == 0 && field000c == 0) {
            velocityX = 0.0;
            velocityY = 0.0;
            StartTrail(3);
        }
        if (field000a == 2 && field000c == 0) {
            velocityX = 2.5;
            velocityY = -0.3;
            gravity = 0.02;
            if (reinterpret_cast<Character04StateFields *>(this)->field3144 == 4) {
                velocityX = 3.2;
                velocityY = -0.25;
                gravity = 0.025;
            }
        }
        velocityY += (double)(field000a > 2) * gravity;
        if (positionY + velocityY >= 0.0 && field000a > 2 && field000a < 5) {
            positionY = 0.0;
            field000a = 5;
            field000c = 0;
            ResetFrame();
        }
        ++field000c;
        if (field000c >= timing.frameDuration) {
            field000c = 0;
            ++field000a;
            if (field000a == 5)
                field000a = 3;
            if (field000a >= timing.animationFrameCount) {
                FaceOpponent();
                field0008 = 3;
                ResetPose();
            }
        }
        return;


    case 164: // Native 0x0060D9F1: forward recovery leap and pose-seven landing
        if (field000a == 0 && field000c == 0) {
            StartTrail(2);
            velocityX = 0.0;
            velocityY = 0.0;
        }
        if (field000a == 2 && field000c == 0) {
            velocityX = -2.0;
            velocityY = -1.0;
        }
        if (field000a > 1)
            velocityY += 0.04;
        if (field000a > 3 && field000a < 7 && velocityY + positionY >= 0.0) {
            velocityX = 0.0;
            velocityY = 0.0;
            horizontalDeceleration = 0.0;
            positionY = 0.0;
            field000a = 7;
            field000c = 0;
        }
        ++field000c;
        if (field000c >= timing.frameDuration) {
            field000c = 0;
            ++field000a;
            if (field000a >= timing.animationFrameCount) {
                FaceOpponent();
                field0008 = 3;
                ResetPose();
            }
        }
        return;


    case 165: // Native 0x0060DB54: forward grounded launch with timed air recovery
        if (field000a == 0 && field000c == 0 &&
            reinterpret_cast<Character04StateFields *>(this)->field3138 == 0) {
            velocityX = 1.3;
            StartTrail(3);
            velocityY = 0.0;
            gravity = 0.0;
            pendingContextSoundSlot = 17;
        }
        ++field000c;
        ++reinterpret_cast<Character04StateFields *>(this)->field3138;
        ++reinterpret_cast<Character04StateFields *>(this)->field313c;
        if (field000c >= timing.frameDuration) {
            field000c = 0;
            ++field000a;
            if (field000a >= timing.animationFrameCount)
                field000a = (unsigned short)(field000a - 2);
        }
        if (inputX == facing &&
            reinterpret_cast<Character04StateFields *>(this)->field313c >= 120) {
            field0008 = 9;
            ResetPose();
            velocityX = 1.1;
            gravity = 0.03;
            if (FaceOpponent() != 0)
                velocityX = -velocityX;
        }
        if (inputX != facing &&
            reinterpret_cast<Character04StateFields *>(this)->field3138 >= 48) {
            field0008 = 9;
            ResetPose();
            velocityX = 1.1;
            gravity = 0.03;
            if (FaceOpponent() != 0)
                velocityX = -velocityX;
        }
        return;

    case 166: // Native 0x0060DD05: reverse grounded launch and facing-aware cooldown
        if (field000a == 0 && field000c == 0 &&
            reinterpret_cast<Character04StateFields *>(this)->field3138 == 0) {
            velocityX = -1.3;
            velocityY = 0.0;
            gravity = 0.0;
            StartTrail(3);
            pendingContextSoundSlot = 17;
        }
        ++field000c;
        ++reinterpret_cast<Character04StateFields *>(this)->field3138;
        ++reinterpret_cast<Character04StateFields *>(this)->field313c;
        if (field000c >= timing.frameDuration) {
            field000c = 0;
            ++field000a;
            if (field000a >= timing.animationFrameCount)
                field000a = (unsigned short)(field000a - 2);
        }
        if ((int)inputX == -(int)facing &&
            reinterpret_cast<Character04StateFields *>(this)->field313c >= 120) {
            field0008 = 9;
            ResetPose();
            velocityX = -0.9;
            gravity = 0.03;
            if (FaceOpponent() != 0)
                velocityX = -velocityX;
        }
        if ((int)inputX != -(int)facing &&
            reinterpret_cast<Character04StateFields *>(this)->field3138 >= 48) {
            field0008 = 9;
            ResetPose();
            velocityX = -0.9;
            gravity = 0.03;
            if (FaceOpponent() != 0)
                velocityX = -velocityX;
        }
        return;


    case 167: // Native Character04 0x0060DEBA: original staged hit effects
        if (field000a == 0 && field000c == 0) {
            velocityX = 0.0;
            velocityY = 0.0;
            StartTrail(10);
            if (field0120 == 1) {
                comboDamageScale += field0118 * 5.0;
            }
            field0118 = 0.0;
            hitstunFrames = 90;
            SetTint(0xb0, 3);
        }
        if (field000a == 1 && field000c == 0) {
            pendingContextSoundSlot = 18;
            effect.type = 1;
            effect.x = (double)(int)positionX;
            effect.y = (double)(int)positionY;
            effect.group = 2;
            effect.layer = 1;
            contextOwner->EmitEffect(&effect);
        }
        if (field000a == 2 && field000c == 0) {
            effect.type = 4;
            effect.x = (double)(int)positionX;
            effect.y = (double)(int)positionY;
            effect.group = 2;
            effect.layer = 1;
            contextOwner->EmitEffect(&effect);
        }
        ++field000c;
        if (field000c >= timing.frameDuration) {
            field000c = 0;
            ++field000a;
            attackCollisionResult = 0;
            if (field000a >= timing.animationFrameCount) {
                field0008 = 0;
                FaceOpponent();
                ResetPose();
            }
        }
        return;

    case 168: // Native Character04 0x0060E0A2: original staged hit effects
        if (field000a == 0 && field000c == 0) {
            velocityX = 0.0;
            velocityY = 0.0;
            positionY = 0.0;
            gravity = 0.0;
            guardInputFrames = 0;
            outgoingPushbackVelocityX = 0.0;
            horizontalDeceleration = 0.0;
            effect.type = 8;
            effect.x = (double)(int)positionX;
            effect.y = (double)(int)positionY;
            effect.group = 2;
            effect.layer = 1;
            contextOwner->EmitEffect(&effect);
        }
        ++field000c;
        if (field000c >= timing.frameDuration) {
            field000c = 0;
            ++field000a;
            if (field000a == timing.animationFrameCount) {
                FaceOpponent();
            }
            if (field000a >= timing.animationFrameCount) {
                field0008 = 0;
                ResetPose();
            }
        }
        return;

    case 169: // Native Character04 0x0060E1E2: original staged hit effects
        if (field000a == 0 && field000c == 0) {
            velocityX = 0.0;
            velocityY = 0.0;
            positionY = 0.0;
            gravity = 0.0;
            guardInputFrames = 0;
            outgoingPushbackVelocityX = 0.0;
            horizontalDeceleration = 0.0;
            effect.type = 8;
            effect.x = (double)(int)positionX;
            effect.y = (double)(int)positionY;
            effect.group = 2;
            effect.layer = 1;
            contextOwner->EmitEffect(&effect);
        }
        ++field000c;
        if (field000c >= timing.frameDuration) {
            field000c = 0;
            ++field000a;
            if (field000a == timing.animationFrameCount) {
                FaceOpponent();
            }
            if (field000a >= timing.animationFrameCount) {
                field0008 = 3;
                ResetPose();
            }
        }
        return;


    case 170: // Native Character04 0x0060E322: stored velocity and delayed recovery
        if (field000a == 0 && field000c == 0) {
            reinterpret_cast<Character04StateFields *>(this)->field3138 = (int)(velocityX * 100.0);
            reinterpret_cast<Character04StateFields *>(this)->field313c = (int)(velocityY * 100.0);
            velocityX = 0.0;
            velocityY = 0.0;
            if (gravity == 0.0) {
                gravity = 0.035;
            }
            guardInputFrames = 0;
            outgoingPushbackVelocityX = 0.0;
            hitstunFrames = 60;
        }
        if (hitstunFrames == 0 && reinterpret_cast<Character04StateFields *>(this)->field3140 == 0) {
            ++reinterpret_cast<Character04StateFields *>(this)->field3140;
            velocityX = (double)reinterpret_cast<Character04StateFields *>(this)->field3138 * 0.01;
            velocityY = (double)reinterpret_cast<Character04StateFields *>(this)->field313c * 0.01;
        }
        if (hitstunFrames == 0) {
            velocityY += gravity;
        }
        if (velocityY + positionY > 0.0) {
            ResetFrame();
            positionY = 0.0;
            field0008 = 169;
            return;
        }
        ++field000c;
        if (field000c >= timing.frameDuration) {
            field000c = 0;
            ++field000a;
            if (field000a >= timing.animationFrameCount) {
                field0008 = 9;
                ResetPose();
            }
        }
        return;

    case 171: // Native Character04 0x0060E4EB: stored velocity and delayed recovery
        if (field000a == 0 && field000c == 0) {
            reinterpret_cast<Character04StateFields *>(this)->field3138 = (int)(velocityX * 100.0);
            reinterpret_cast<Character04StateFields *>(this)->field313c = (int)(velocityY * 100.0);
            velocityX = 0.0;
            velocityY = 0.0;
            StartTrail(10);
            if (field0120 == 1) {
                comboDamageScale += field0118 * 5.0;
            }
            field0118 = 0.0;
            hitstunFrames = 90;
            SetTint(0xb0, 3);
        }
        // Original effect1 occurs on pose1; effect4 follows on pose2.
        if (field000a == 1 && field000c == 0) {
            pendingContextSoundSlot = 18;
            effect.type = 1;
            effect.x = (double)(int)positionX;
            effect.y = (double)(int)positionY;
            effect.group = 2;
            effect.layer = 1;
            contextOwner->EmitEffect(&effect);
        }
        if (field000a == 2 && field000c == 0) {
            effect.type = 4;
            effect.x = (double)(int)positionX;
            effect.y = (double)(int)positionY;
            effect.group = 2;
            effect.layer = 1;
            contextOwner->EmitEffect(&effect);
        }
        ++field000c;
        if (field000c >= timing.frameDuration) {
            field000c = 0;
            ++field000a;
            attackCollisionResult = 0;
            if (field000a >= timing.animationFrameCount) {
                field0008 = 9;
                velocityX = (double)reinterpret_cast<Character04StateFields *>(this)->field3138 * 0.01;
                velocityY = (double)reinterpret_cast<Character04StateFields *>(this)->field313c * 0.01;
                gravity = 0.035;
                ResetPose();
            }
        }
        return;


    case 180: // Native 0x0060E73D: trailing aerial with pose7 landing interruption
        if (field000a == 0 && field000c == 0) {
            StartTrail(2);
            velocityX = 0.0;
            velocityY = 0.0;
            gravity = 0.0;
        }
        if (positionY < 0.0)
            velocityY += gravity;
        if (positionY + velocityY > 0.0 && field000a < 7) {
            ResetFrame();
            positionY = 0.0;
            field000c = 0;
            field000a = 7;
            pendingContextSoundSlot = 9;
        }
        ++field000c;
        if (field000c >= timing.frameDuration) {
            field000c = 0;
            ++field000a;
            if (field000a == 2) {
                velocityX = -0.5;
                velocityY = -1.0;
                gravity = 0.028;
            }
            if (field000a >= timing.animationFrameCount) {
                ResetPose();
                field0008 = 0;
            }
        }
        return;


    case 200: // Native 0x0060E88E: dash-cancel attack and posture-specific hit meter
        velocityX = 0.0;
        velocityY = 0.0;
        if (inputY == -1 && field000a > 0 && field015c < 3 &&
            attackCollisionResult >= 2) {
            field0008 = 4;
            if (inputX == facing)
                field0008 = 5;
            if ((int)inputX == -(int)facing)
                field0008 = 6;
            attackCollisionResult = 0;
            ResetPose();
            return;
        }
        if (field000a == 1 && field000c == 0) {
            meter = (short)(meter + 5);
            pendingContextSoundSlot = 21;
            remainingHitCount = 1;
        }
        ++field000c;
        if (field000c >= timing.frameDuration) {
            field000c = 0;
            ++field000a;
            if (field000a < 3)
                attackCollisionResult = 0;
            if (field000a >= timing.animationFrameCount) {
                field0008 = 0;
                FaceOpponent();
                ResetPose();
            }
        }
        return;

    case 201: // Native 0x0060EA07: separate early-meter dash-cancel attack
        if (inputY == -1 && field000a > 0 && field015c < 3 &&
            attackCollisionResult >= 2) {
            field0008 = 4;
            if (inputX == facing)
                field0008 = 5;
            if ((int)inputX == -(int)facing)
                field0008 = 6;
            attackCollisionResult = 0;
            ResetPose();
            return;
        }
        if (field000a == 0 && field000c == 0) {
            velocityX = 0.0;
            velocityY = 0.0;
        }
        if (field000a == 1 && field000c == 0) {
            meter = (short)(meter + 15);
            pendingContextSoundSlot = 20;
            remainingHitCount = 1;
        }
        ++field000c;
        if (field000c >= timing.frameDuration) {
            field000c = 0;
            ++field000a;
            if (field000a < 3)
                attackCollisionResult = 0;
            if (field000a >= timing.animationFrameCount) {
                field0008 = 0;
                FaceOpponent();
                ResetPose();
            }
        }
        return;


    case 202: // Native 0x0060EB96: dash cancellation with pose-nine special marker
        if (inputY == -1 && field000a > 0 && field015c < 3 &&
            attackCollisionResult == 3) {
            field0008 = 4;
            if (inputX == facing)
                field0008 = 5;
            if ((int)inputX == -(int)facing)
                field0008 = 6;
            attackCollisionResult = 0;
            ResetPose();
            return;
        }
        if (field000a == 0 && field000c == 0) {
            velocityX = 0.0;
            velocityY = 0.0;
        }
        if (field000a == 2 && field000c == 0) {
            meter = (short)(meter + 15);
            pendingContextSoundSlot = 20;
            remainingHitCount = 1;
        }
        if (field000a == 9 && field000c == 0)
            pendingCharacterSoundSlot = 2;
        ++field000c;
        if (field000c >= timing.frameDuration) {
            field000c = 0;
            ++field000a;
            if (field000a < 3)
                attackCollisionResult = 0;
            if (field000a >= timing.animationFrameCount) {
                field0008 = 0;
                FaceOpponent();
                ResetPose();
            }
        }
        return;

    case 203: // Native 0x0060ED46: grounded meter and delayed hit marker
        if (field000a == 0 && field000c == 0) {
            velocityX = 0.0;
            velocityY = 0.0;
        }
        if (field000a == 2 && field000c == 0) {
            meter = (short)(meter + 35);
            pendingContextSoundSlot = 20;
            remainingHitCount = 1;
        }
        if (field000a == 10 && field000c == 0)
            pendingCharacterSoundSlot = 2;
        ++field000c;
        if (field000c >= timing.frameDuration) {
            field000c = 0;
            ++field000a;
            if (field000a < 3)
                attackCollisionResult = 0;
            if (field000a >= timing.animationFrameCount) {
                field0008 = 0;
                FaceOpponent();
                ResetPose();
            }
        }
        return;


    case 204: // EXPERIMENTAL C04 0x0060EE5D: grounded action and dash-cancel
        velocityX = 0.0;
        velocityY = 0.0;
        if (inputY == -1 && field000a > 0 && field015c < 3 &&
            attackCollisionResult >= 2) {
            field0008 = 4;
            if (inputX == facing)
                field0008 = 5;
            if ((int)inputX == -(int)facing)
                field0008 = 6;
            attackCollisionResult = 0;
            ResetPose();
            return;
        }
        if (field000a == 1 && field000c == 0) {
            meter = (short)(meter + 5);
            pendingContextSoundSlot = 21;
            remainingHitCount = 1;
        }
        ++field000c;
        if (field000c >= timing.frameDuration) {
            field000c = 0;
            ++field000a;
            if (field000a < 3)
                attackCollisionResult = 0;
            if (field000a >= timing.animationFrameCount) {
                field0008 = 0;
                if (inputY == 1)
                    field0008 = 3;
                FaceOpponent();
                ResetPose();
            }
        }
        return;


    case 205: // EXPERIMENTAL C04 0x0060EFEE: grounded action and dash-cancel
        velocityX = 0.0;
        velocityY = 0.0;
        if (inputY == -1 && field000a > 0 && field015c < 3 &&
            attackCollisionResult == 3) {
            field0008 = 4;
            if (inputX == facing)
                field0008 = 5;
            if ((int)inputX == -(int)facing)
                field0008 = 6;
            attackCollisionResult = 0;
            ResetPose();
            return;
        }
        if (field000a == 1 && field000c == 0) {
            meter = (short)(meter + 13);
            pendingContextSoundSlot = 20;
            remainingHitCount = 1;
        }
        ++field000c;
        if (field000c >= timing.frameDuration) {
            field000c = 0;
            ++field000a;
            if (field000a < 3)
                attackCollisionResult = 0;
            if (field000a >= timing.animationFrameCount) {
                field0008 = 0;
                if (inputY == 1)
                    field0008 = 3;
                FaceOpponent();
                ResetPose();
            }
        }
        return;


    case 206: // EXPERIMENTAL C04 0x0060F17F: pose-three charge and pose-ten sound
        velocityX = 0.0;
        velocityY = 0.0;
        if (inputY == -1 && field000a > 0 && field015c < 3 &&
            attackCollisionResult == 3) {
            field0008 = 4;
            if (inputX == facing)
                field0008 = 5;
            if ((int)inputX == -(int)facing)
                field0008 = 6;
            attackCollisionResult = 0;
            ResetPose();
            return;
        }
        if (field000a == 3 && field000c == 0) {
            meter = (short)(meter + 25);
            pendingContextSoundSlot = 20;
            remainingHitCount = 1;
        }
        if (field000a == 10 && field000c == 0)
            pendingCharacterSoundSlot = 2;
        ++field000c;
        if (field000c >= timing.frameDuration) {
            field000c = 0;
            ++field000a;
            if (field000a < 3)
                attackCollisionResult = 0;
            if (field000a >= timing.animationFrameCount) {
                field0008 = 0;
                if (inputY == 1)
                    field0008 = 3;
                FaceOpponent();
                ResetPose();
            }
        }
        return;


    case 207: // EXPERIMENTAL Character04 0x0060F331: aerial cancel and pose-two charge
        velocityY += gravity;
        if (inputY == -1 && field000a > 0 && field015c < 3 &&
            attackCollisionResult >= 2 && airActionCount == 0) {
            ++airActionCount;
            field0008 = 14;
            if (inputX == facing) {
                field0008 = 15;
            }
            if ((int)inputX == -(int)facing) {
                field0008 = 16;
            }
            attackCollisionResult = 0;
            ResetPose();
            return;
        }
        if (field000a == 1 && field000c == 0) {
            meter = (short)(meter + 5);
            pendingContextSoundSlot = 21;
            remainingHitCount = 1;
        }
        if (positionY + velocityY >= 0.0) {
            positionY = 0.0;
            field0008 = 13;
            ResetPose();
            return;
        }
        ++field000c;
        if (field000c >= timing.frameDuration) {
            field000c = 0;
            ++field000a;
            if (field000a < 3) {
                attackCollisionResult = 0;
            }
            if (field000a >= timing.animationFrameCount) {
                field0008 = 9;
                ResetPose();
            }
        }
        return;


    case 208: // EXPERIMENTAL Character04 0x0060F508: aerial cancel, pose-four sound and post-frame charge
        velocityY += gravity;
        if (inputY == -1 && field000a > 0 && field015c < 3 &&
            attackCollisionResult >= 2 && airActionCount == 0) {
            ++airActionCount;
            field0008 = 14;
            if (inputX == facing) {
                field0008 = 15;
            }
            if ((int)inputX == -(int)facing) {
                field0008 = 16;
            }
            attackCollisionResult = 0;
            ResetPose();
            return;
        }
        if (positionY + velocityY >= 0.0) {
            positionY = 0.0;
            field0008 = 13;
            ResetPose();
            return;
        }
        if (field000a == 4 && field000c == 0)
            pendingCharacterSoundSlot = 2;
        ++field000c;
        if (field000c >= timing.frameDuration) {
            field000c = 0;
            ++field000a;
            if (field000a < 3) {
                attackCollisionResult = 0;
            }
            if (field000a == 1) {
                meter = (short)(meter + 13);
                pendingContextSoundSlot = 20;
                remainingHitCount = 1;
            }
            if (field000a >= timing.animationFrameCount) {
                field0008 = 9;
                ResetPose();
            }
        }
        return;


    case 209: // EXPERIMENTAL Character04 0x0060F6F9: aerial cancel, pose-one 30-meter charge
        velocityY += gravity;
        if (inputY == -1 && field000a > 0 && field015c < 3 &&
            attackCollisionResult >= 2 && airActionCount == 0) {
            ++airActionCount;
            field0008 = 14;
            if (inputX == facing) {
                field0008 = 15;
            }
            if ((int)inputX == -(int)facing) {
                field0008 = 16;
            }
            attackCollisionResult = 0;
            ResetPose();
            return;
        }
        if (field000a == 1 && field000c == 0) {
            meter = (short)(meter + 30);
            pendingContextSoundSlot = 20;
            remainingHitCount = 1;
        }
        if (field000a == 4 && field000c == 0)
            pendingCharacterSoundSlot = 2;
        if (positionY + velocityY >= 0.0) {
            positionY = 0.0;
            field0008 = 13;
            ResetPose();
            return;
        }
        ++field000c;
        if (field000c >= timing.frameDuration) {
            field000c = 0;
            ++field000a;
            if (field000a < 3) {
                attackCollisionResult = 0;
            }
            if (field000a >= timing.animationFrameCount) {
                field0008 = 9;
                ResetPose();
            }
        }
        return;


    case 210: // EXPERIMENTAL Character04 0x0060F8F1: special cancel and mirrored local hit
        if (inputY == -1 && field000a > 0 && field015c < 3 &&
            attackCollisionResult == 3) {
            field0008 = 4;
            if (inputX == facing)
                field0008 = 5;
            if ((int)inputX == -(int)facing)
                field0008 = 6;
            attackCollisionResult = 0;
            ResetPose();
            return;
        }
        if (field000a == 0 && field000c == 0) {
            velocityX = 0.0;
            velocityY = 0.0;
            remainingHitCount = 1;
        }
        if (field000a == 2 && field000c == 0) {
            pendingCharacterSoundSlot = 1;
            meter = (short)(meter + 25);
            effect.type = 0x19f;
            effect.x = (double)((int)positionX - (int)facing * 28);
            effect.y = (double)((int)positionY - 44);
            effect.group = 2;
            effect.layer = 1;
            effect.flag0018 = (unsigned char)facing;
            EmitLocalEffect(&effect);
        }
        if (field000a == 6 && field000c == 0)
            pendingCharacterSoundSlot = 2;
        ++field000c;
        if (field000c >= timing.frameDuration) {
            field000c = 0;
            ++field000a;
            if (field000a < 3)
                attackCollisionResult = 0;
            if (field000a >= timing.animationFrameCount) {
                field0008 = 0;
                FaceOpponent();
                ResetPose();
            }
        }
        return;



    case 211: // EXPERIMENTAL Character04 0x0060FB12: uncancelled local hit level two
        if (field000a == 0 && field000c == 0) {
            velocityX = 0.0;
            velocityY = 0.0;
            remainingHitCount = 1;
        }
        if (field000a == 2 && field000c == 0) {
            pendingCharacterSoundSlot = 1;
            meter = (short)(meter + 25);
            effect.type = 0x1a0;
            effect.x = (double)((int)positionX - (int)facing * 21);
            effect.y = (double)((int)positionY - 63);
            effect.group = 2;
            effect.layer = 1;
            effect.flag0018 = (unsigned char)facing;
            EmitLocalEffect(&effect);
        }
        if (field000a == 6 && field000c == 0)
            pendingCharacterSoundSlot = 2;
        ++field000c;
        if (field000c >= timing.frameDuration) {
            field000c = 0;
            ++field000a;
            if (field000a < 3)
                attackCollisionResult = 0;
            if (field000a >= timing.animationFrameCount) {
                field0008 = 0;
                FaceOpponent();
                ResetPose();
            }
        }
        return;



    case 212: // EXPERIMENTAL Character04 0x0060FC9A: uncancelled local hit level three
        if (field000a == 0 && field000c == 0) {
            velocityX = 0.0;
            velocityY = 0.0;
            remainingHitCount = 1;
        }
        if (field000a == 2 && field000c == 0) {
            pendingCharacterSoundSlot = 1;
            meter = (short)(meter + 25);
            effect.type = 0x1a1;
            effect.x = (double)((int)positionX - (int)facing * 5);
            effect.y = (double)((int)positionY - 61);
            effect.group = 2;
            effect.layer = 1;
            effect.flag0018 = (unsigned char)facing;
            EmitLocalEffect(&effect);
        }
        if (field000a == 6 && field000c == 0)
            pendingCharacterSoundSlot = 2;
        ++field000c;
        if (field000c >= timing.frameDuration) {
            field000c = 0;
            ++field000a;
            if (field000a < 2)
                attackCollisionResult = 0;
            if (field000a >= timing.animationFrameCount) {
                field0008 = 0;
                FaceOpponent();
                ResetPose();
            }
        }
        return;


    case 213: // Character04 native 0x0060FE22: meter-cost local hit tier 1
        if (inputY == -1 && field000a > 0 && field015c < 3 &&
            attackCollisionResult >= 2) {
            field0008 = 4;
            if (inputX == facing)
                field0008 = 5;
            if ((int)inputX == -(int)facing)
                field0008 = 6;
            attackCollisionResult = 0;
            ResetPose();
            return;
        }
        if (field000a == 0 && field000c == 0) {
            velocityX = 0.0;
            velocityY = 0.0;
            remainingHitCount = 1;
            reinterpret_cast<Character04StateFields *>(this)->field3148 -= 1000;
        }
        if (field000a == 2 && field000c == 0) {
            pendingCharacterSoundSlot = 1;
            meter = (short)(meter + 25);
            effect.type = 0x19f;
            effect.x = (double)((int)positionX - (int)facing * 28);
            effect.y = (double)((int)positionY - 44);
            effect.group = 2;
            effect.layer = 1;
            effect.flag0018 = (unsigned char)facing;
            EmitLocalEffect(&effect);
        }
        if (field000a == 6 && field000c == 0)
            pendingCharacterSoundSlot = 2;
        ++field000c;
        if (field000c >= timing.frameDuration) {
            field000c = 0;
            ++field000a;
            attackCollisionResult = 0;
            if (field000a >= timing.animationFrameCount) {
                field0008 = 0;
                FaceOpponent();
                ResetPose();
            }
        }
        return;




    case 214: // Character04 native 0x0061004F: meter-cost local hit tier 2
        if (inputY == -1 && field000a > 0 && field015c < 3 &&
            attackCollisionResult >= 2) {
            field0008 = 4;
            if (inputX == facing)
                field0008 = 5;
            if ((int)inputX == -(int)facing)
                field0008 = 6;
            attackCollisionResult = 0;
            ResetPose();
            return;
        }
        if (field000a == 0 && field000c == 0) {
            velocityX = 0.0;
            velocityY = 0.0;
            remainingHitCount = 1;
            reinterpret_cast<Character04StateFields *>(this)->field3148 -= 1000;
        }
        if (field000a == 2 && field000c == 0) {
            pendingCharacterSoundSlot = 1;
            meter = (short)(meter + 25);
            effect.type = 0x1a0;
            effect.x = (double)((int)positionX - (int)facing * 21);
            effect.y = (double)((int)positionY - 63);
            effect.group = 2;
            effect.layer = 1;
            effect.flag0018 = (unsigned char)facing;
            EmitLocalEffect(&effect);
        }
        if (field000a == 6 && field000c == 0)
            pendingCharacterSoundSlot = 2;
        ++field000c;
        if (field000c >= timing.frameDuration) {
            field000c = 0;
            ++field000a;
            attackCollisionResult = 0;
            if (field000a >= timing.animationFrameCount) {
                field0008 = 0;
                FaceOpponent();
                ResetPose();
            }
        }
        return;



    case 215: // Character04 native 0x0061027C: meter-cost local hit tier 3
        if (inputY == -1 && field000a > 0 && field015c < 3 &&
            attackCollisionResult >= 2) {
            field0008 = 4;
            if (inputX == facing)
                field0008 = 5;
            if ((int)inputX == -(int)facing)
                field0008 = 6;
            attackCollisionResult = 0;
            ResetPose();
            return;
        }
        if (field000a == 0 && field000c == 0) {
            velocityX = 0.0;
            velocityY = 0.0;
            remainingHitCount = 1;
            reinterpret_cast<Character04StateFields *>(this)->field3148 -= 1000;
        }
        if (field000a == 2 && field000c == 0) {
            pendingCharacterSoundSlot = 1;
            meter = (short)(meter + 25);
            effect.type = 0x1a1;
            effect.x = (double)((int)positionX - (int)facing * 5);
            effect.y = (double)((int)positionY - 61);
            effect.group = 2;
            effect.layer = 1;
            effect.flag0018 = (unsigned char)facing;
            EmitLocalEffect(&effect);
        }
        if (field000a == 6 && field000c == 0)
            pendingCharacterSoundSlot = 2;
        ++field000c;
        if (field000c >= timing.frameDuration) {
            field000c = 0;
            ++field000a;
            attackCollisionResult = 0;
            if (field000a >= timing.animationFrameCount) {
                field0008 = 0;
                FaceOpponent();
                ResetPose();
            }
        }
        return;




    case 216: // Character04 native 0x006104A9: horizontal speed drag and timed charge
        if (field000a == 0 && field000c == 0) {
            ResetFrame();
            remainingHitCount = 1;
        }
        if (velocityX > 0.0)
            velocityX -= 0.08;
        if (velocityX < 0.0)
            velocityX = 0.0;
        ++field000c;
        if (field000c >= timing.frameDuration) {
            field000c = 0;
            ++field000a;
            if (field000a == 1)
                attackCollisionResult = 0;
            if (field000a == 3) {
                pendingContextSoundSlot = 21;
                meter = (short)(meter + 25);
                velocityX = 3.0;
            }
            if (field000a >= timing.animationFrameCount) {
                field0008 = 0;
                FaceOpponent();
                ResetPose();
            }
        }
        return;


    case 220: // Character04 native 0x006105D8: grab, opponent pose and impact effect
        velocityX = 0.0;
        velocityY = 0.0;
        if (field000a == 1 && attackCollisionResult == 3) {
            velocityX = 0.0;
            velocityY = 0.0;
            outgoingPushbackVelocityX = 0.0;
            ResetPose();
            (*opponentSlot)->ResetFrame();
            (*opponentSlot)->ResetPose();
            (*opponentSlot)->field0008 = 108;
            field0008 = 221;
            effect.type = 0;
            effect.x = (double)((int)positionX + (int)facing * 49);
            effect.y = (double)((int)positionY - 43);
            effect.group = 2;
            effect.layer = 1;
            contextOwner->EmitEffect(&effect);
            return;
        }
        ++field000c;
        if (field000c >= timing.frameDuration) {
            field000c = 0;
            ++field000a;
            attackCollisionResult = 0;
            if (field000a == 1 && (*opponentSlot)->positionY == 0.0)
                remainingHitCount = 1;
            else
                remainingHitCount = 0;
            if (field000a >= timing.animationFrameCount) {
                field0008 = 0;
                if (inputY == 1)
                    field0008 = 3;
                FaceOpponent();
                ResetPose();
            }
        }
        return;


    case 221: // Character04 native 0x006107B4: four-step opponent throw and impact
        SetHorizontalShake(50, 3);
        ++field000c;
        if (field000c >= timing.frameDuration) {
            field000c = 0;
            ++field000a;
            attackCollisionResult = 0;
            if (field000a == 1) {
                if (facing == 1) {
                    if (positionX + 20.0 < 40.0)
                        positionX = 40.0;
                }
                if (facing == -1) {
                    if (positionX > 620.0)
                        positionX = 620.0;
                }
                (*opponentSlot)->field0008 = 103;
                (*opponentSlot)->positionY = -150.0;
                (*opponentSlot)->positionX = positionX + (double)((int)facing * 41);
            }
            if (field000a == 2) {
                (*opponentSlot)->positionY = -100.0;
                (*opponentSlot)->positionX = positionX + (double)((int)facing * 47);
            }
            if (field000a == 3) {
                (*opponentSlot)->positionY = -81.0;
                (*opponentSlot)->positionX = positionX - (double)((int)facing * 92);
                (*opponentSlot)->facing = (char)-(int)facing;
                (*opponentSlot)->field0008 = 117;
            }
            if (field000a == 4) {
                (*opponentSlot)->positionY = 0.0;
                (*opponentSlot)->positionX = positionX - (double)((int)facing * 97);
                ApplyDamage(1200, 750.0);
                (*opponentSlot)->field0008 = 97;
                (*opponentSlot)->knockdownOnLanding = 1;
                attackCollisionResult = 3;
                (*opponentSlot)->ResetPose();
                (*opponentSlot)->ResetFrame();
            }
            if (field000a >= timing.animationFrameCount) {
                field0008 = 0;
                FaceOpponent();
                ResetPose();
            }
        }
        return;


    case 230: // Character04 native 0x00610A47: airborne meter-action variant
        velocityY += gravity;
        if (field000a == 0 && field000c == 0) {
            velocityX = 0.5;
            gravity = 0.03;
        }
        if (field000a == 1 && field000c == 0) {
            meter = (short)(meter + 5);
            pendingContextSoundSlot = 21;
            remainingHitCount = 1;
        }
        if (positionY + velocityY >= 0.0) {
            positionY = 0.0;
            field0008 = 13;
            ResetPose();
            return;
        }
        ++field000c;
        if (field000c >= timing.frameDuration) {
            field000c = 0;
            ++field000a;
            attackCollisionResult = 0;
            if (field000a >= timing.animationFrameCount) {
                field0008 = 9;
                ResetPose();
            }
        }
        return;

    case 231: // Character04 native 0x00610B78: airborne meter-action variant
        velocityY += gravity;
        if (field000a == 0 && field000c == 0) {
            velocityX = 0.5;
            gravity = 0.03;
        }
        if (field000a == 2 && field000c == 0) {
            meter = (short)(meter + 10);
            pendingContextSoundSlot = 21;
            remainingHitCount = 1;
        }
        if (positionY + velocityY >= 0.0) {
            positionY = 0.0;
            field0008 = 13;
            ResetPose();
            return;
        }
        ++field000c;
        if (field000c >= timing.frameDuration) {
            field000c = 0;
            ++field000a;
            attackCollisionResult = 0;
            if (field000a >= timing.animationFrameCount) {
                field0008 = 9;
                ResetPose();
            }
        }
        return;

    case 232: // Character04 native 0x00610CA9: airborne meter-action variant
        velocityY += gravity;
        if (field000a == 0 && field000c == 0) {
            velocityX = 0.5;
            gravity = 0.03;
        }
        if (field000a == 1 && field000c == 0) {
            meter = (short)(meter + 10);
            pendingContextSoundSlot = 20;
            remainingHitCount = 1;
        }
        if (positionY + velocityY >= 0.0) {
            positionY = 0.0;
            field0008 = 13;
            ResetPose();
            return;
        }
        ++field000c;
        if (field000c >= timing.frameDuration) {
            field000c = 0;
            ++field000a;
            attackCollisionResult = 0;
            if (field000a >= timing.animationFrameCount) {
                field0008 = 9;
                ResetPose();
            }
        }
        return;

    case 240: // Character04 native 0x00610DDA: throw capture and opponent positioning
        velocityY += gravity;
        if (field000a == 1 && attackCollisionResult == 3) {
            (*opponentSlot)->ResetFrame();
            (*opponentSlot)->ResetPose();
            ResetPose();
            ResetFrame();
            field0008 = 241;
            (*opponentSlot)->field0008 = 100;
            effect.type = 0;
            effect.x = (double)((int)positionX + (int)facing * 31);
            effect.y = (double)((int)positionY - 82);
            effect.group = 2;
            effect.layer = 1;
            contextOwner->EmitEffect(&effect);
            (*opponentSlot)->positionX = positionX + (double)((int)facing * 31);
            (*opponentSlot)->positionY = positionY - 82.0;
        }
        ++field000c;
        if (field000c >= timing.frameDuration) {
            field000c = 0;
            ++field000a;
            if (field000a == 1 && (*opponentSlot)->positionY < 0.0 &&
                ((*opponentSlot)->field0008 < 50 ||
                 (*opponentSlot)->field0008 > 149)) {
                remainingHitCount = 1;
            } else {
                remainingHitCount = 0;
            }
            attackCollisionResult = 0;
            if (field000a >= timing.animationFrameCount) {
                field0008 = 0xd1;
                field000a = 1;
            }
        }
        return;

    case 241: // Character04 native 0x00610FCC: airborne multi-stage throw
        if (field000a < 4) {
            SetHorizontalOffset(50, 3);
        }
        if (field000a < 4) {
            SetHorizontalShake(50, 3);
        }
        if (field000a == 0 && field000c == 1) {
            (*opponentSlot)->facing = -facing;
        }
        velocityY += gravity;
        if (velocityY + positionY > 0.0 && field000a > 5) {
            ResetFrame();
            positionY = 0.0;
            ResetPose();
            field0008 = 13;
            return;
        }
        if (field000a == 1) {
            (*opponentSlot)->positionY = positionY - 80.0;
            (*opponentSlot)->positionX = positionX + (double)((int)facing * 29);
            (*opponentSlot)->field0008 = 0x67;
        }
        if (field000a == 2) {
            (*opponentSlot)->positionY = positionY - 71.0;
            (*opponentSlot)->positionX = positionX + (double)((int)facing * 11);
            (*opponentSlot)->field0008 = 0x68;
            (*opponentSlot)->facing = facing;
        }
        if (field000a == 3 && field000c == 0) {
            (*opponentSlot)->positionY = positionY - 60.0;
            (*opponentSlot)->positionX = positionX - (double)((int)facing * 37);
            (*opponentSlot)->field0008 = 0x45;
            ApplyDamage(0x514, 500.0);
            (*opponentSlot)->ResetPose();
            (*opponentSlot)->knockbackVelocityX = -3.0;
            (*opponentSlot)->knockbackVelocityY = 3.0;
        }
        if (field000a == 5 && field000c == 0) {
            gravity = 0.035;
        }
        ++field000c;
        if (field000c >= timing.frameDuration) {
            field000c = 0;
            ++field000a;
            attackCollisionResult = 0;
            if (field000a >= timing.animationFrameCount) {
                field000a = (unsigned short)(field000a - 2);
            }
        }
        return;

    case 249: // Character04 native 0x0061129C: opening special-move effect and hitstun setup
        if (field000a == 0 && (unsigned short)field000c == 0) {
            field00dc = 4;
            field00de = 0xec;
            velocityX = 0.0;
            remainingHitCount = 1;
            guardInputFrames = 0;
            hitstunFrames = 0x3c;
            effect.type = 0x28;
            effect.x = (double)((int)positionX + (int)facing * 10);
            effect.y = (double)((int)positionY - 0x28);
            effect.group = 2;
            effect.layer = 1;
            effect.palette = 0x13;
            contextOwner->EmitEffect(&effect);
        }
        ++field000c;
        if ((unsigned short)field000c >= timing.frameDuration) {
            field000c = 0;
            ++field000a;
            attackCollisionResult = 0;
            if (field000a >= timing.animationFrameCount) {
                field0008 = 0;
                FaceOpponent();
                ResetPose();
            }
        }
        return;

    case 250: // Character04 native 0x006113DC: airborne startup and frame-loop control
        if (field000a == 0 && field000c == 0) {
            if (positionY == 0.0) {
                velocityX = 0.0;
                gravity = 0.0;
            }
            if (positionY < 0.0) {
                reinterpret_cast<Character04StatePrivate *>(this)->field3138 = 1;
            }
            gravity = 0.0;
        }
        if (field000a == 1 && field000c == 0) {
            meter = (short)(meter + 0x19);
            remainingHitCount = 1;
            velocityX *= 0.5;
            velocityY *= 0.5;
            gravity = 0.025;
        }
        if (field000a > 1 && velocityY + positionY >= 0.0) {
            field000c = 0;
            field000a = 0;
            field0008 = 0xfd;
            return;
        }
        ++field000c;
        velocityY += gravity;
        if (field000c >= timing.frameDuration ||
            (field000c >= timing.frameDuration - 3 &&
             reinterpret_cast<Character04StatePrivate *>(this)->field3138 == 1)) {
            field000c = 0;
            ++field000a;
            attackCollisionResult = 0;
            if (field000a >= timing.animationFrameCount) {
                field000a = 11;
            }
        }
        return;

    case 251: // Character04 native 0x00611590: second airborne throw with pose-reset completion
        if (field000a == 0 && field000c == 0) {
            if (positionY == 0.0) {
                velocityX = 0.0;
                gravity = 0.0;
            }
            if (positionY < 0.0) {
                reinterpret_cast<Character04StatePrivate *>(this)->field3138 = 1;
            }
            gravity = 0.0;
        }
        if (field000a == 1 && field000c == 0) {
            meter = (short)(meter + 0x19);
            remainingHitCount = 1;
            velocityX *= 0.5;
            velocityY *= 0.5;
            gravity = 0.035;
        }
        if (field000a > 1 && velocityY + positionY >= 0.0) {
            field000c = 0;
            field000a = 0;
            field0008 = 0xfd;
            reinterpret_cast<Character04StatePrivate *>(this)->field313c = 1;
            return;
        }
        ++field000c;
        velocityY += gravity;
        if (field000c >= timing.frameDuration ||
            (field000c >= timing.frameDuration - 3 &&
             reinterpret_cast<Character04StatePrivate *>(this)->field3138 == 1)) {
            field000c = 0;
            ++field000a;
            if (field000a == 1) {
                attackCollisionResult = 0;
            }
            if (field000a >= timing.animationFrameCount) {
                field0008 = 0;
                ResetPose();
            }
        }
        return;

    case 252: // Character04 native 0x00611767: charged airborne special with launch effects
        if (field000a == 0 && field000c == 0) {
            if (positionY < 0.0) {
                reinterpret_cast<Character04StateFields *>(this)->field3138 = 1;
            }
            if (positionY == 0.0) {
                velocityX = 0.0;
                gravity = 0.0;
            }
            effect.type = 0x21;
            effect.palette = 0x0b;
            effect.x = (double)(int)positionX;
            effect.y = (double)((int)positionY - 0x14);
            effect.group = 2;
            effect.layer = 1;
            contextOwner->EmitEffect(&effect);
            StartTrail(3);
            if (reinterpret_cast<Character04StateFields *>(this)->field3144 == 4) {
                reinterpret_cast<Character04StateFields *>(this)->field3148 -= 1000;
                if (reinterpret_cast<Character04StateFields *>(this)->field3148 < 0) {
                    reinterpret_cast<Character04StateFields *>(this)->field3148 = 0;
                }
            } else if (field0120 == 0) {
                field0118 -= 500.0;
            } else {
                field0118 -= 250.0;
            }
        }
        if (field000a == 1 && field000c == 0) {
            meter = (short)(meter + 0x19);
            remainingHitCount = 2;
            velocityX *= 0.5;
            velocityY *= 0.5;
            gravity = 0.025;
        }
        if (field000a == 7 && field000c == 0) {
            effect.type = 0x1a2;
            effect.x = (double)((int)positionX + (int)facing * 0x25);
            effect.y = (double)((int)positionY - 0x28);
            effect.group = 2;
            effect.flag0018 = (unsigned char)facing;
            effect.layer = 1;
            EmitLocalEffect(&effect);
        }
        if (field000a > 1 && velocityY + positionY >= 0.0) {
            field000a = 0;
            field000c = 0;
            field0008 = 0xfd;
        }
        velocityY += gravity;
        ++field000c;
        if (field000c >= timing.frameDuration ||
            (field000c >= timing.frameDuration - 3 &&
             reinterpret_cast<Character04StateFields *>(this)->field3138 == 1)) {
            field000c = 0;
            ++field000a;
            attackCollisionResult = 0;
            if (field000a >= timing.animationFrameCount) {
                field0008 = 0;
                ResetPose();
            }
        }
        return;

    case 253: // Character04 native 0x00611A7D: post-landing recovery and input branch
        velocityX = 0.0;
        velocityY = 0.0;
        FaceOpponent();
        ++field000c;
        if (field000c >= timing.frameDuration ||
            (field000a == 2 &&
             reinterpret_cast<Character04StateFields *>(this)->field313c == 1 &&
             field000c == 0x15)) {
            field000c = 0;
            ++field000a;
            attackCollisionResult = 0;
            if (field000a >= timing.animationFrameCount) {
                field0008 = 7;
                if (inputY == 1) {
                    field0008 = 3;
                }
                ResetPose();
            }
        }
        return;

    case 254: // Character04 native 0x00611B49: held-input charge and launch
        attackCollisionResult = 2;
        if (buttonHeld[0] > 0) {
            ++reinterpret_cast<Character04StateFields *>(this)->field313c;
        }
        if (field000a == 2 && field000c == 0) {
            reinterpret_cast<unsigned char *>(this)[0x2c8] = 0;
            effect.type = 0x20;
            effect.x = (double)((int)positionX + (int)facing * 60);
            effect.y = (double)(int)positionY;
            effect.group = 0;
            effect.flag0018 = (unsigned char)-facing;
            effect.layer = 1;
            contextOwner->EmitEffect(&effect);
        }
        if (field000a == 5 && field000c == 0) {
            ResetFrame();
            if (reinterpret_cast<Character04StateFields *>(this)->field313c > 30) {
                reinterpret_cast<Character04StateFields *>(this)->field3138 = 1;
            }
        }
        velocityX += horizontalDeceleration;
        if (velocityX < 0.0) {
            velocityX = 0.0;
        }
        if (field000a == 5 && field000c == 0x14 &&
            reinterpret_cast<Character04StateFields *>(this)->field3138 == 0) {
            velocityX = -3.0;
        }
        if (field000a == 6 && field000c == 0) {
            velocityX = 1.5;
            horizontalDeceleration = -0.05;
        }
        ++field000c;
        if (field000c >= timing.frameDuration) {
            field000c = 0;
            ++field000a;
            if (field000a == 6 &&
                reinterpret_cast<Character04StateFields *>(this)->field3138 == 1) {
                field000a = 0;
                field000c = 0;
                field0008 = 0x105;
                return;
            }
            if (field000a == 6) {
                positionX = (*opponentSlot)->positionX - (double)((int)facing * 60);
            }
            attackCollisionResult = 0;
            if (field000a >= timing.animationFrameCount) {
                field0008 = 0;
                FaceOpponent();
                ResetPose();
            }
        }
        return;

    case 255: // Character04 native 0x00611DB0: alternate held-input charge and aerial launch
        // VC7.1 rotates the frame-6 register allocation in C++; keep the exact
        // native compare/x87 launch path explicit. The two scratch operands
        // use the bottom of this provisional frame (see check_prefix.py).
        attackCollisionResult = 2;
        if (buttonHeld[1] > 0) {
            ++reinterpret_cast<Character04StateFields *>(this)->field313c;
        }
        if (field000a == 2 && field000c == 0) {
            reinterpret_cast<unsigned char *>(this)[0x2c8] = 0;
            effect.type = 0x20;
            effect.x = (double)((int)positionX + (int)facing * 60);
            effect.y = (double)(int)positionY;
            effect.group = 0;
            effect.flag0018 = (unsigned char)-facing;
            effect.layer = 1;
            contextOwner->EmitEffect(&effect);
        }
        if (field000a == 5 && field000c == 0) {
            ResetFrame();
            if (reinterpret_cast<Character04StateFields *>(this)->field313c > 30) {
                reinterpret_cast<Character04StateFields *>(this)->field3138 = 1;
            }
        }
        velocityX += horizontalDeceleration;
        if (velocityX < 0.0) {
            velocityX = 0.0;
        }
        if (field000a == 5 && field000c == 0x14 &&
            reinterpret_cast<Character04StateFields *>(this)->field3138 == 0) {
            positionX = (*opponentSlot)->positionX - (double)((int)facing * 180);
        }
        if (field000a == 6 && field000c == 0) {
            velocityX = 1.5;
            horizontalDeceleration = -0.05;
        }
        ++field000c;
        if (field000c >= timing.frameDuration) {
            field000c = 0;
            ++field000a;
            __asm {
                mov edx, dword ptr [ebp-54h]
                movzx eax, word ptr [edx+0Ah]
                cmp eax, 6
                jne state255_skip_charge
                mov ecx, dword ptr [ebp-54h]
                cmp dword ptr [ecx+3138h], 1
                jne state255_skip_charge
            }
            __asm {
                mov edx, dword ptr [ebp-54h]
                mov word ptr [edx+0Ah], 0
                mov eax, dword ptr [ebp-54h]
                mov word ptr [eax+0Ch], 0
                mov ecx, dword ptr [ebp-54h]
                mov word ptr [ecx+08h], 0106h
                mov edx, dword ptr [ebp-54h]
                mov eax, dword ptr [edx+78h]
                mov ecx, dword ptr [eax]
                mov edx, dword ptr [ebp-54h]
                movsx eax, byte ptr [edx+50h]
                imul eax, eax, 064h
                mov dword ptr [ebp-1B8h], eax
                fild dword ptr [ebp-1B8h]
                fsubr qword ptr [ecx+20h]
                mov ecx, dword ptr [ebp-54h]
                fstp qword ptr [ecx+20h]
                mov edx, dword ptr [ebp-54h]
                fld qword ptr [edx+20h]
                _emit 0DCh
                _emit 01Dh
                _emit 058h
                _emit 08Bh
                _emit 078h
                _emit 000h
                fnstsw ax
                test ah, 041h
                jnz state255_no_right_clamp
                mov eax, dword ptr [ebp-54h]
                movsx ecx, byte ptr [eax+50h]
                cmp ecx, 1
                jnz state255_no_right_clamp
                mov edx, dword ptr [ebp-54h]
                _emit 0DDh
                _emit 005h
                _emit 058h
                _emit 08Bh
                _emit 078h
                _emit 000h
                fstp qword ptr [edx+20h]
            state255_no_right_clamp:
                mov eax, dword ptr [ebp-54h]
                fld qword ptr [eax+20h]
                _emit 0DCh
                _emit 01Dh
                _emit 0D0h
                _emit 075h
                _emit 078h
                _emit 000h
                fnstsw ax
                test ah, 05h
                jpe state255_no_left_clamp
                mov ecx, dword ptr [ebp-54h]
                movsx edx, byte ptr [ecx+50h]
                cmp edx, -1
                jnz state255_no_left_clamp
                mov eax, dword ptr [ebp-54h]
                _emit 0DDh
                _emit 005h
                _emit 0D0h
                _emit 075h
                _emit 078h
                _emit 000h
                fstp qword ptr [eax+20h]
            state255_no_left_clamp:
                mov ecx, dword ptr [ebp-54h]
                _emit 0DDh
                _emit 005h
                _emit 0C8h
                _emit 075h
                _emit 078h
                _emit 000h
                fstp qword ptr [ecx+28h]
            }
            return;
            __asm {
            state255_skip_charge:
            }
            __asm {
            mov edx, dword ptr [ebp-54h]
            mov dword ptr [edx+168h], 0
            mov eax, dword ptr [ebp-54h]
            movzx ecx, word ptr [eax+0Ah]
            movzx edx, word ptr [ebp-08h]
            cmp ecx, edx
            jl state255_skip_reset
            mov eax, dword ptr [ebp-54h]
            mov word ptr [eax+08h], 0
        }
        FaceOpponent();
        __asm {
            mov ecx, dword ptr [ebp-54h]
            mov edx, dword ptr [ecx]
            mov ecx, dword ptr [ebp-54h]
            call dword ptr [edx]
        state255_skip_reset:
        }
        }
        return;

    case 256: // Character04 native 0x00612093: aerial special follow-through
        if (field000a == 0 && field000c == 0) {
            effect.type = 0x21;
            effect.palette = 0x0b;
            effect.x = (double)(int)positionX;
            effect.y = (double)((int)positionY - 0x14);
            effect.group = 2;
            effect.layer = 1;
            contextOwner->EmitEffect(&effect);
            StartTrail(3);
            if (reinterpret_cast<Character04StateFields *>(this)->field3144 == 4) {
                reinterpret_cast<Character04StateFields *>(this)->field3148 -= 1000;
                if (reinterpret_cast<Character04StateFields *>(this)->field3148 < 0) {
                    reinterpret_cast<Character04StateFields *>(this)->field3148 = 0;
                }
            } else if (field0120 == 0) {
                field0118 -= 500.0;
            } else {
                field0118 -= 250.0;
            }
            remainingHitCount = 1;
        }
        if (field000a == 2 && field000c == 0) {
            reinterpret_cast<unsigned char *>(this)[0x2c8] = 0;
            effect.type = 0x20;
            effect.x = (double)((int)positionX + (int)facing * 60);
            effect.y = (double)(int)positionY;
            effect.group = 0;
            effect.flag0018 = (unsigned char)-facing;
            effect.layer = 1;
            contextOwner->EmitEffect(&effect);
        }
        if (field000a == 4 && attackCollisionResult == 2) {
            field000c = 0;
            field000a = 6;
            return;
        }
        if (field000a == 5 && field000c == 0) {
            ResetFrame();
        }
        velocityX += horizontalDeceleration;
        if (velocityX < 0.0) {
            velocityX = 0.0;
        }
        if (field000a == 5 && field000c == 0x14) {
            velocityX = 8.0;
        }
        if (field000a == 6 && field000c == 0) {
            velocityX = 3.5;
            horizontalDeceleration = -0.05;
        }
        ++field000c;
        if (field000c >= timing.frameDuration) {
            field000c = 0;
            ++field000a;
            if (field000a < 2) {
                attackCollisionResult = 0;
            }
            if (field000a >= timing.animationFrameCount) {
                FaceOpponent();
                field0008 = 0;
                ResetPose();
            }
        }
        return;

    case 257: // Character04 native 0x0061237E: special effect follow-through
        attackCollisionResult = 2;
        if (field000a == 0 && field000c == 0) {
            ResetFrame();
        }
        if (field000a == 2 && field000c == 0) {
            __asm {
                mov ecx, dword ptr [ebp-54h]
                cmp dword ptr [ecx+3144h], 4
                jz state257_high_cost
                mov edx, dword ptr [ebp-54h]
                mov dword ptr [edx+3144h], 2
                mov word ptr [ebp-4Ch], 019Ch
                mov eax, dword ptr [ebp-54h]
                fld qword ptr [eax+20h]
                call _ftol2
                mov ecx, dword ptr [ebp-54h]
                movsx edx, byte ptr [ecx+50h]
                imul edx, edx, 028h
                add eax, edx
                mov dword ptr [ebp-1D0h], eax
                fild dword ptr [ebp-1D0h]
                fstp qword ptr [ebp-48h]
                mov eax, dword ptr [ebp-54h]
                fld qword ptr [eax+28h]
                call _ftol2
                mov dword ptr [ebp-1D4h], eax
                fild dword ptr [ebp-1D4h]
                fstp qword ptr [ebp-40h]
                mov dword ptr [ebp-50h], 1
                mov byte ptr [ebp-30h], 2
                mov ecx, dword ptr [ebp-54h]
                mov dl, byte ptr [ecx+50h]
                mov byte ptr [ebp-38h], dl
                mov byte ptr [ebp-2Fh], 1
                lea eax, [ebp-50h]
                push eax
                mov ecx, dword ptr [ebp-54h]
                mov edx, dword ptr [ecx]
                mov ecx, dword ptr [ebp-54h]
                call dword ptr [edx+24h]
                jmp state257_effect_done
            state257_high_cost:
                mov eax, dword ptr [ebp-54h]
                mov ecx, dword ptr [eax+3148h]
                sub ecx, 03E8h
                mov edx, dword ptr [ebp-54h]
                mov dword ptr [edx+3148h], ecx
                mov eax, dword ptr [ebp-54h]
                cmp dword ptr [eax+3148h], 0
                jnl state257_high_cost_ready
                mov ecx, dword ptr [ebp-54h]
                mov dword ptr [ecx+3148h], 0
            state257_high_cost_ready:
                mov word ptr [ebp-4Ch], 01A8h
                mov edx, dword ptr [ebp-54h]
                fld qword ptr [edx+20h]
                call _ftol2
                mov ecx, dword ptr [ebp-54h]
                movsx edx, byte ptr [ecx+50h]
                imul edx, edx, 050h
                add eax, edx
                mov dword ptr [ebp-1D8h], eax
                fild dword ptr [ebp-1D8h]
                fstp qword ptr [ebp-48h]
                mov eax, dword ptr [ebp-54h]
                fld qword ptr [eax+28h]
                call _ftol2
                mov dword ptr [ebp-1DCh], eax
                fild dword ptr [ebp-1DCh]
                fstp qword ptr [ebp-40h]
                mov dword ptr [ebp-50h], 1
                mov byte ptr [ebp-30h], 2
                mov ecx, dword ptr [ebp-54h]
                mov dl, byte ptr [ecx+50h]
                mov byte ptr [ebp-38h], dl
                mov byte ptr [ebp-2Fh], 1
                lea eax, [ebp-50h]
                push eax
                mov ecx, dword ptr [ebp-54h]
                mov edx, dword ptr [ecx]
                mov ecx, dword ptr [ebp-54h]
                call dword ptr [edx+24h]
            state257_effect_done:
            }
        }
        __asm {
            mov eax, dword ptr [ebp-54h]
            mov cx, word ptr [eax+0Ch]
            add cx, 1
            mov edx, dword ptr [ebp-54h]
            mov word ptr [edx+0Ch], cx
            mov eax, dword ptr [ebp-54h]
            movzx ecx, word ptr [eax+0Ch]
            movzx edx, word ptr [ebp-04h]
            cmp ecx, edx
            jl state257_tick_done
            mov eax, dword ptr [ebp-54h]
            mov word ptr [eax+0Ch], 0
            mov ecx, dword ptr [ebp-54h]
            mov dx, word ptr [ecx+0Ah]
            add dx, 1
            mov eax, dword ptr [ebp-54h]
            mov word ptr [eax+0Ah], dx
            mov ecx, dword ptr [ebp-54h]
            mov dword ptr [ecx+168h], 3
            mov edx, dword ptr [ebp-54h]
            movzx eax, word ptr [edx+0Ah]
            movzx ecx, word ptr [ebp-08h]
            cmp eax, ecx
            jl state257_tick_done
            mov edx, dword ptr [ebp-54h]
            mov word ptr [edx+08h], 0
            mov eax, dword ptr [ebp-54h]
            mov edx, dword ptr [eax]
            mov ecx, dword ptr [ebp-54h]
            call dword ptr [edx]
        }
        FaceOpponent();
        __asm {
        state257_tick_done:
        }
        return;

    case 258: // Character04 native 0x00612569: wide local-effect follow-through
        __asm {
            mov eax, dword ptr [ebp-54h]
            mov dword ptr [eax+168h], 2
            mov ecx, dword ptr [ebp-54h]
            movzx edx, word ptr [ecx+0Ah]
            test edx, edx
            jnz state258_skip_frame0_reset
            mov eax, dword ptr [ebp-54h]
            movzx ecx, word ptr [eax+0Ch]
            test ecx, ecx
            jnz state258_skip_frame0_reset
        }
        ResetFrame();
        __asm {
        state258_skip_frame0_reset:
            mov edx, dword ptr [ebp-54h]
            movzx eax, word ptr [edx+0Ah]
            cmp eax, 2
            jnz state258_skip_effect
            mov ecx, dword ptr [ebp-54h]
            movzx edx, word ptr [ecx+0Ch]
            test edx, edx
            jnz state258_skip_effect
            mov eax, dword ptr [ebp-54h]
            cmp dword ptr [eax+3144h], 4
            jz state258_high_cost
            mov ecx, dword ptr [ebp-54h]
            mov dword ptr [ecx+3144h], 2
            mov word ptr [ebp-4Ch], 019Ch
            mov edx, dword ptr [ebp-54h]
            fld qword ptr [edx+20h]
            call _ftol2
            mov ecx, dword ptr [ebp-54h]
            movsx edx, byte ptr [ecx+50h]
            imul edx, edx, 078h
            add eax, edx
            mov dword ptr [ebp-1E0h], eax
            fild dword ptr [ebp-1E0h]
            fstp qword ptr [ebp-48h]
            mov eax, dword ptr [ebp-54h]
            fld qword ptr [eax+28h]
            call _ftol2
            mov dword ptr [ebp-1E4h], eax
            fild dword ptr [ebp-1E4h]
            fstp qword ptr [ebp-40h]
            mov dword ptr [ebp-50h], 1
            mov byte ptr [ebp-30h], 2
            mov ecx, dword ptr [ebp-54h]
            mov dl, byte ptr [ecx+50h]
            mov byte ptr [ebp-38h], dl
            mov byte ptr [ebp-2Fh], 1
            lea eax, [ebp-50h]
            push eax
            mov ecx, dword ptr [ebp-54h]
            mov edx, dword ptr [ecx]
            mov ecx, dword ptr [ebp-54h]
            call dword ptr [edx+24h]
            jmp state258_skip_effect
        state258_high_cost:
            mov word ptr [ebp-4Ch], 01A8h
            mov eax, dword ptr [ebp-54h]
            mov ecx, dword ptr [eax+3148h]
            sub ecx, 03E8h
            mov edx, dword ptr [ebp-54h]
            mov dword ptr [edx+3148h], ecx
            mov eax, dword ptr [ebp-54h]
            cmp dword ptr [eax+3148h], 0
            jnl state258_high_cost_ready
            mov ecx, dword ptr [ebp-54h]
            mov dword ptr [ecx+3148h], 0
        state258_high_cost_ready:
            mov edx, dword ptr [ebp-54h]
            fld qword ptr [edx+20h]
            call _ftol2
            mov ecx, dword ptr [ebp-54h]
            movsx edx, byte ptr [ecx+50h]
            imul edx, edx, 0A0h
            add eax, edx
            mov dword ptr [ebp-1E8h], eax
            fild dword ptr [ebp-1E8h]
            fstp qword ptr [ebp-48h]
            mov eax, dword ptr [ebp-54h]
            fld qword ptr [eax+28h]
            call _ftol2
            mov dword ptr [ebp-1ECh], eax
            fild dword ptr [ebp-1ECh]
            fstp qword ptr [ebp-40h]
            mov dword ptr [ebp-50h], 1
            mov byte ptr [ebp-30h], 2
            mov ecx, dword ptr [ebp-54h]
            mov dl, byte ptr [ecx+50h]
            mov byte ptr [ebp-38h], dl
            mov byte ptr [ebp-2Fh], 1
            lea eax, [ebp-50h]
            push eax
            mov ecx, dword ptr [ebp-54h]
            mov edx, dword ptr [ecx]
            mov ecx, dword ptr [ebp-54h]
            call dword ptr [edx+24h]
        state258_skip_effect:
            mov eax, dword ptr [ebp-54h]
            mov cx, word ptr [eax+0Ch]
            add cx, 1
            mov edx, dword ptr [ebp-54h]
            mov word ptr [edx+0Ch], cx
            mov eax, dword ptr [ebp-54h]
            movzx ecx, word ptr [eax+0Ch]
            movzx edx, word ptr [ebp-04h]
            cmp ecx, edx
            jl state258_tick_done
            mov eax, dword ptr [ebp-54h]
            mov word ptr [eax+0Ch], 0
            mov ecx, dword ptr [ebp-54h]
            mov dx, word ptr [ecx+0Ah]
            add dx, 1
            mov eax, dword ptr [ebp-54h]
            mov word ptr [eax+0Ah], dx
            mov ecx, dword ptr [ebp-54h]
            mov dword ptr [ecx+168h], 3
            mov edx, dword ptr [ebp-54h]
            movzx eax, word ptr [edx+0Ah]
            movzx ecx, word ptr [ebp-08h]
            cmp eax, ecx
            jl state258_tick_done
            mov edx, dword ptr [ebp-54h]
            mov word ptr [edx+08h], 0
            mov eax, dword ptr [ebp-54h]
            mov edx, dword ptr [eax]
            mov ecx, dword ptr [ebp-54h]
            call dword ptr [edx]
        }
        FaceOpponent();
        __asm {
        state258_tick_done:
        }
        return;



    case 259: // Character04 native 0x00612757: farther-reaching local-effect follow-through
        __asm {
            mov eax, dword ptr [ebp-54h]
            mov dword ptr [eax+168h], 2
            mov ecx, dword ptr [ebp-54h]
            movzx edx, word ptr [ecx+0Ah]
            test edx, edx
            jnz state259_skip_frame0_reset
            mov eax, dword ptr [ebp-54h]
            movzx ecx, word ptr [eax+0Ch]
            test ecx, ecx
            jnz state259_skip_frame0_reset
        }
        ResetFrame();
        __asm {
        state259_skip_frame0_reset:
            mov edx, dword ptr [ebp-54h]
            movzx eax, word ptr [edx+0Ah]
            cmp eax, 2
            jnz state259_skip_effect
            mov ecx, dword ptr [ebp-54h]
            movzx edx, word ptr [ecx+0Ch]
            test edx, edx
            jnz state259_skip_effect
            mov eax, dword ptr [ebp-54h]
            cmp dword ptr [eax+3144h], 4
            jz state259_high_cost
            mov ecx, dword ptr [ebp-54h]
            mov dword ptr [ecx+3144h], 2
            mov word ptr [ebp-4Ch], 019Ch
            mov edx, dword ptr [ebp-54h]
            fld qword ptr [edx+20h]
            call _ftol2
            mov ecx, dword ptr [ebp-54h]
            movsx edx, byte ptr [ecx+50h]
            imul edx, edx, 0C8h
            add eax, edx
            mov dword ptr [ebp-1F0h], eax
            fild dword ptr [ebp-1F0h]
            fstp qword ptr [ebp-48h]
            mov eax, dword ptr [ebp-54h]
            fld qword ptr [eax+28h]
            call _ftol2
            mov dword ptr [ebp-1F4h], eax
            fild dword ptr [ebp-1F4h]
            fstp qword ptr [ebp-40h]
            mov dword ptr [ebp-50h], 1
            mov byte ptr [ebp-30h], 2
            mov ecx, dword ptr [ebp-54h]
            mov dl, byte ptr [ecx+50h]
            mov byte ptr [ebp-38h], dl
            mov byte ptr [ebp-2Fh], 1
            lea eax, [ebp-50h]
            push eax
            mov ecx, dword ptr [ebp-54h]
            mov edx, dword ptr [ecx]
            mov ecx, dword ptr [ebp-54h]
            call dword ptr [edx+24h]
            jmp state259_skip_effect
        state259_high_cost:
            mov word ptr [ebp-4Ch], 01A8h
            mov eax, dword ptr [ebp-54h]
            mov ecx, dword ptr [eax+3148h]
            sub ecx, 03E8h
            mov edx, dword ptr [ebp-54h]
            mov dword ptr [edx+3148h], ecx
            mov eax, dword ptr [ebp-54h]
            cmp dword ptr [eax+3148h], 0
            jnl state259_high_cost_ready
            mov ecx, dword ptr [ebp-54h]
            mov dword ptr [ecx+3148h], 0
        state259_high_cost_ready:
            mov edx, dword ptr [ebp-54h]
            fld qword ptr [edx+20h]
            call _ftol2
            mov ecx, dword ptr [ebp-54h]
            movsx edx, byte ptr [ecx+50h]
            imul edx, edx, 0F0h
            add eax, edx
            mov dword ptr [ebp-1F8h], eax
            fild dword ptr [ebp-1F8h]
            fstp qword ptr [ebp-48h]
            mov eax, dword ptr [ebp-54h]
            fld qword ptr [eax+28h]
            call _ftol2
            mov dword ptr [ebp-1FCh], eax
            fild dword ptr [ebp-1FCh]
            fstp qword ptr [ebp-40h]
            mov dword ptr [ebp-50h], 1
            mov byte ptr [ebp-30h], 2
            mov ecx, dword ptr [ebp-54h]
            mov dl, byte ptr [ecx+50h]
            mov byte ptr [ebp-38h], dl
            mov byte ptr [ebp-2Fh], 1
            lea eax, [ebp-50h]
            push eax
            mov ecx, dword ptr [ebp-54h]
            mov edx, dword ptr [ecx]
            mov ecx, dword ptr [ebp-54h]
            call dword ptr [edx+24h]
        state259_skip_effect:
            mov eax, dword ptr [ebp-54h]
            mov cx, word ptr [eax+0Ch]
            add cx, 1
            mov edx, dword ptr [ebp-54h]
            mov word ptr [edx+0Ch], cx
            mov eax, dword ptr [ebp-54h]
            movzx ecx, word ptr [eax+0Ch]
            movzx edx, word ptr [ebp-04h]
            cmp ecx, edx
            jl state259_tick_done
            mov eax, dword ptr [ebp-54h]
            mov word ptr [eax+0Ch], 0
            mov ecx, dword ptr [ebp-54h]
            mov dx, word ptr [ecx+0Ah]
            add dx, 1
            mov eax, dword ptr [ebp-54h]
            mov word ptr [eax+0Ah], dx
            mov ecx, dword ptr [ebp-54h]
            mov dword ptr [ecx+168h], 3
            mov edx, dword ptr [ebp-54h]
            movzx eax, word ptr [edx+0Ah]
            movzx ecx, word ptr [ebp-08h]
            cmp eax, ecx
            jl state259_tick_done
            mov edx, dword ptr [ebp-54h]
            mov word ptr [edx+08h], 0
            mov eax, dword ptr [ebp-54h]
            mov edx, dword ptr [eax]
            mov ecx, dword ptr [ebp-54h]
            call dword ptr [edx]
        }
        FaceOpponent();
        __asm {
        state259_tick_done:
        }
        return;


    case 260: // Character04 native 0x0061294C: aerial capture and dual-effect setup
        __asm {
            mov eax, dword ptr [ebp-54h]
            movzx ecx, word ptr [eax+0Ah]
            test ecx, ecx
            jnz state260_skip_setup
            mov edx, dword ptr [ebp-54h]
            movzx eax, word ptr [edx+0Ch]
            test eax, eax
            jnz state260_skip_setup
            mov ecx, dword ptr [ebp-54h]
            _emit 0DDh
            _emit 005h
            _emit 0F8h
            _emit 072h
            _emit 078h
            _emit 000h
            fstp qword ptr [ecx+30h]
            mov edx, dword ptr [ebp-54h]
            _emit 0DDh
            _emit 005h
            _emit 0F8h
            _emit 072h
            _emit 078h
            _emit 000h
            fstp qword ptr [edx+38h]
            mov eax, dword ptr [ebp-54h]
            mov byte ptr [eax+2C8h], 5
            mov ecx, dword ptr [ebp-54h]
            mov dword ptr [ecx+3148h], 02710h
            mov edx, dword ptr [ebp-54h]
            mov dword ptr [edx+314Ch], 1
            mov eax, dword ptr [ebp-54h]
            mov dword ptr [eax+3150h], 1
            mov word ptr [ebp-4Ch], 01Fh
            mov ecx, dword ptr [ebp-54h]
            fld qword ptr [ecx+20h]
            call _ftol2
            mov dword ptr [ebp-200h], eax
            fild dword ptr [ebp-200h]
            fstp qword ptr [ebp-48h]
            mov edx, dword ptr [ebp-54h]
            fld qword ptr [edx+28h]
            call _ftol2
            mov dword ptr [ebp-204h], eax
            fild dword ptr [ebp-204h]
            fstp qword ptr [ebp-40h]
            mov byte ptr [ebp-30h], 0
            mov byte ptr [ebp-2Fh], 1
            mov eax, dword ptr [ebp-54h]
            movsx ecx, byte ptr [eax+50h]
            sub ecx, -1
            neg ecx
            sbb ecx, ecx
            inc ecx
            mov dword ptr [ebp-34h], ecx
            lea edx, [ebp-50h]
            push edx
            mov eax, dword ptr [ebp-54h]
            mov ecx, dword ptr [eax+7Ch]
            call Context::EmitEffect
            mov word ptr [ebp-4Ch], 0191h
            mov ecx, dword ptr [ebp-54h]
            fld qword ptr [ecx+20h]
            call _ftol2
            mov dword ptr [ebp-208h], eax
            fild dword ptr [ebp-208h]
            fstp qword ptr [ebp-48h]
            mov edx, dword ptr [ebp-54h]
            cmp dword ptr [edx+3140h], 1
            jnz state260_skip_right_offset
            mov eax, dword ptr [ebp-54h]
            fld qword ptr [eax+20h]
            call _ftol2
            mov ecx, dword ptr [ebp-54h]
            movsx edx, byte ptr [ecx+50h]
            imul edx, edx, 03Ch
            add eax, edx
            mov dword ptr [ebp-20Ch], eax
            fild dword ptr [ebp-20Ch]
            fstp qword ptr [ebp-48h]
            mov eax, dword ptr [ebp-54h]
            fld qword ptr [eax+20h]
            call _ftol2
            mov ecx, dword ptr [ebp-54h]
            movsx edx, byte ptr [ecx+50h]
            imul edx, edx, 03Ch
            add eax, edx
            cmp eax, 0258h
            jng state260_right_no_top_clamp
            _emit 0DDh
            _emit 005h
            _emit 0C0h
            _emit 080h
            _emit 078h
            _emit 000h
            fstp qword ptr [ebp-48h]
        state260_right_no_top_clamp:
            mov eax, dword ptr [ebp-54h]
            fld qword ptr [eax+20h]
            call _ftol2
            mov ecx, dword ptr [ebp-54h]
            movsx edx, byte ptr [ecx+50h]
            imul edx, edx, 03Ch
            add eax, edx
            cmp eax, 028h
            jnl state260_right_no_bottom_clamp
            _emit 0DDh
            _emit 005h
            _emit 0E0h
            _emit 07Ch
            _emit 078h
            _emit 000h
            fstp qword ptr [ebp-48h]
        state260_right_no_bottom_clamp:
        state260_skip_right_offset:
            mov eax, dword ptr [ebp-54h]
            cmp dword ptr [eax+3140h], 2
            jnz state260_skip_left_offset
            mov ecx, dword ptr [ebp-54h]
            fld qword ptr [ecx+20h]
            call _ftol2
            mov edx, dword ptr [ebp-54h]
            movsx ecx, byte ptr [edx+50h]
            imul ecx, ecx, 03Ch
            sub eax, ecx
            mov dword ptr [ebp-210h], eax
            fild dword ptr [ebp-210h]
            fstp qword ptr [ebp-48h]
            mov edx, dword ptr [ebp-54h]
            fld qword ptr [edx+20h]
            call _ftol2
            mov ecx, dword ptr [ebp-54h]
            movsx edx, byte ptr [ecx+50h]
            imul edx, edx, 03Ch
            sub eax, edx
            cmp eax, 0258h
            jng state260_left_no_top_clamp
            _emit 0DDh
            _emit 005h
            _emit 0C0h
            _emit 080h
            _emit 078h
            _emit 000h
            fstp qword ptr [ebp-48h]
        state260_left_no_top_clamp:
            mov eax, dword ptr [ebp-54h]
            fld qword ptr [eax+20h]
            call _ftol2
            mov ecx, dword ptr [ebp-54h]
            movsx edx, byte ptr [ecx+50h]
            imul edx, edx, 03Ch
            sub eax, edx
            cmp eax, 028h
            jnl state260_left_no_bottom_clamp
            _emit 0DDh
            _emit 005h
            _emit 0E0h
            _emit 07Ch
            _emit 078h
            _emit 000h
            fstp qword ptr [ebp-48h]
        state260_left_no_bottom_clamp:
        state260_skip_left_offset:
            mov eax, dword ptr [ebp-54h]
            fld qword ptr [eax+28h]
            call _ftol2
            sub eax, 011h
            mov dword ptr [ebp-214h], eax
            fild dword ptr [ebp-214h]
            fstp qword ptr [ebp-40h]
            mov ecx, dword ptr [ebp-54h]
            mov dl, byte ptr [ecx+50h]
            mov byte ptr [ebp-38h], dl
            mov byte ptr [ebp-30h], 2
            mov byte ptr [ebp-2Fh], 1
            mov dword ptr [ebp-50h], 1
            lea eax, [ebp-50h]
            push eax
            mov ecx, dword ptr [ebp-54h]
            mov edx, dword ptr [ecx]
            mov ecx, dword ptr [ebp-54h]
            call dword ptr [edx+24h]
        state260_skip_setup:
            mov eax, dword ptr [ebp-54h]
            mov cx, word ptr [eax+0Ch]
            add cx, 1
            mov edx, dword ptr [ebp-54h]
            mov word ptr [edx+0Ch], cx
            mov eax, dword ptr [ebp-54h]
            movzx ecx, word ptr [eax+0Ch]
            movzx edx, word ptr [ebp-04h]
            cmp ecx, edx
            jl state260_tick_done
            mov eax, dword ptr [ebp-54h]
            mov word ptr [eax+0Ch], 0
            mov ecx, dword ptr [ebp-54h]
            mov dx, word ptr [ecx+0Ah]
            add dx, 1
            mov eax, dword ptr [ebp-54h]
            mov word ptr [eax+0Ah], dx
            mov ecx, dword ptr [ebp-54h]
            mov dword ptr [ecx+168h], 0
            mov edx, dword ptr [ebp-54h]
            movzx eax, word ptr [edx+0Ah]
            movzx ecx, word ptr [ebp-08h]
            cmp eax, ecx
            jl state260_tick_done
            mov edx, dword ptr [ebp-54h]
            mov word ptr [edx+08h], 0
            mov eax, dword ptr [ebp-54h]
            mov edx, dword ptr [eax]
            mov ecx, dword ptr [ebp-54h]
            call dword ptr [edx]
        }
        FaceOpponent();
        __asm {
        state260_tick_done:
        }
        return;

    case 261: // Character04 native 0x00612BEE: aerial deceleration recovery
        __asm {
            mov eax, dword ptr [ebp-54h]
            movzx ecx, word ptr [eax+0Ah]
            test ecx, ecx
            jnz state261_skip_startup
            mov edx, dword ptr [ebp-54h]
            movzx eax, word ptr [edx+0Ch]
            test eax, eax
            jnz state261_skip_startup
            mov ecx, dword ptr [ebp-54h]
            _emit 0DDh
            _emit 005h
            _emit 028h
            _emit 073h
            _emit 078h
            _emit 000h
            fstp qword ptr [ecx+30h]
            mov edx, dword ptr [ebp-54h]
            mov word ptr [edx+16Ch], 1
        state261_skip_startup:
            mov eax, dword ptr [ebp-54h]
            movzx ecx, word ptr [eax+0Ah]
            cmp ecx, 6
            jng state261_skip_decay
            mov edx, dword ptr [ebp-54h]
            fld qword ptr [edx+30h]
            _emit 0DCh
            _emit 025h
            _emit 088h
            _emit 07Fh
            _emit 078h
            _emit 000h
            mov eax, dword ptr [ebp-54h]
            fstp qword ptr [eax+30h]
        state261_skip_decay:
            mov ecx, dword ptr [ebp-54h]
            fld qword ptr [ecx+30h]
            _emit 0DCh
            _emit 01Dh
            _emit 0F8h
            _emit 072h
            _emit 078h
            _emit 000h
            fnstsw ax
            test ah, 05h
            jpe state261_no_floor
            mov edx, dword ptr [ebp-54h]
            _emit 0DDh
            _emit 005h
            _emit 0F8h
            _emit 072h
            _emit 078h
            _emit 000h
            fstp qword ptr [edx+30h]
        state261_no_floor:
            mov eax, dword ptr [ebp-54h]
            mov cx, word ptr [eax+0Ch]
            add cx, 1
            mov edx, dword ptr [ebp-54h]
            mov word ptr [edx+0Ch], cx
            mov eax, dword ptr [ebp-54h]
            movzx ecx, word ptr [eax+0Ch]
            movzx edx, word ptr [ebp-04h]
            cmp ecx, edx
            jl state261_tick_done
            mov eax, dword ptr [ebp-54h]
            mov word ptr [eax+0Ch], 0
            mov ecx, dword ptr [ebp-54h]
            mov dx, word ptr [ecx+0Ah]
            add dx, 1
            mov eax, dword ptr [ebp-54h]
            mov word ptr [eax+0Ah], dx
            mov ecx, dword ptr [ebp-54h]
            movzx edx, word ptr [ecx+0Ah]
            cmp edx, 1
            jnz state261_skip_collision_clear
            mov eax, dword ptr [ebp-54h]
            mov dword ptr [eax+168h], 0
        state261_skip_collision_clear:
            mov ecx, dword ptr [ebp-54h]
            movzx edx, word ptr [ecx+0Ah]
            movzx eax, word ptr [ebp-08h]
            cmp edx, eax
            jl state261_tick_done
            mov ecx, dword ptr [ebp-54h]
            mov word ptr [ecx+08h], 0
        }
        FaceOpponent();
        __asm {
            mov edx, dword ptr [ebp-54h]
            mov eax, dword ptr [edx]
            mov ecx, dword ptr [ebp-54h]
            call dword ptr [eax]
        state261_tick_done:
        }
        return;

    case 262: // Character04 native 0x00612CDD: aerial fall and landing reset
        __asm {
            mov ecx, dword ptr [ebp-54h]
            movzx edx, word ptr [ecx+0Ah]
            test edx, edx
            jnz state262_skip_startup
            mov eax, dword ptr [ebp-54h]
            movzx ecx, word ptr [eax+0Ch]
            test ecx, ecx
            jnz state262_skip_startup
            mov edx, dword ptr [ebp-54h]
            _emit 0DDh
            _emit 005h
            _emit 0C0h
            _emit 075h
            _emit 078h
            _emit 000h
            fstp qword ptr [edx+30h]
            mov eax, dword ptr [ebp-54h]
            _emit 0DDh
            _emit 005h
            _emit 0F8h
            _emit 072h
            _emit 078h
            _emit 000h
            fstp qword ptr [eax+38h]
            mov ecx, dword ptr [ebp-54h]
            mov word ptr [ecx+16Ch], 1
        state262_skip_startup:
            mov eax, dword ptr [ebp-54h]
            movzx ecx, word ptr [eax+0Ah]
            cmp ecx, 2
            jng state262_skip_gravity
            mov edx, dword ptr [ebp-54h]
            fld qword ptr [edx+38h]
            _emit 0DCh
            _emit 005h
            _emit 0D8h
            _emit 07Dh
            _emit 078h
            _emit 000h
            mov eax, dword ptr [ebp-54h]
            fstp qword ptr [eax+38h]
        state262_skip_gravity:
            mov ecx, dword ptr [ebp-54h]
            mov edx, dword ptr [ebp-54h]
            fld qword ptr [ecx+28h]
            fadd qword ptr [edx+38h]
            _emit 0DCh
            _emit 01Dh
            _emit 0F8h
            _emit 072h
            _emit 078h
            _emit 000h
            fnstsw ax
            test ah, 041h
            jnz state262_normal_advance
            mov eax, dword ptr [ebp-54h]
            movzx ecx, word ptr [eax+0Ah]
            cmp ecx, 0Ch
            jnl state262_normal_advance
            mov edx, dword ptr [ebp-54h]
            mov word ptr [edx+0Ah], 0Ch
            mov eax, dword ptr [ebp-54h]
            mov word ptr [eax+0Ch], 0
            mov ecx, dword ptr [ebp-54h]
            _emit 0DDh
            _emit 005h
            _emit 0F8h
            _emit 072h
            _emit 078h
            _emit 000h
            fstp qword ptr [ecx+28h]
            mov ecx, dword ptr [ebp-54h]
            call Secondary::ResetFrame
            _emit 0E9h
            _emit 073h
            _emit 000h
            _emit 000h
            _emit 000h
        state262_normal_advance:
            mov edx, dword ptr [ebp-54h]
            mov ax, word ptr [edx+0Ch]
            add ax, 1
            mov ecx, dword ptr [ebp-54h]
            mov word ptr [ecx+0Ch], ax
            mov edx, dword ptr [ebp-54h]
            movzx eax, word ptr [edx+0Ch]
            movzx ecx, word ptr [ebp-04h]
            cmp eax, ecx
            jl state262_tick_done
            mov edx, dword ptr [ebp-54h]
            mov word ptr [edx+0Ch], 0
            mov eax, dword ptr [ebp-54h]
            mov cx, word ptr [eax+0Ah]
            add cx, 1
            mov edx, dword ptr [ebp-54h]
            mov word ptr [edx+0Ah], cx
            mov eax, dword ptr [ebp-54h]
            mov dword ptr [eax+168h], 0
            mov ecx, dword ptr [ebp-54h]
            movzx edx, word ptr [ecx+0Ah]
            movzx eax, word ptr [ebp-08h]
            cmp edx, eax
            jl state262_tick_done
            mov ecx, dword ptr [ebp-54h]
            mov word ptr [ecx+08h], 0
        }
        FaceOpponent();
        __asm {
            mov edx, dword ptr [ebp-54h]
            mov eax, dword ptr [edx]
            mov ecx, dword ptr [ebp-54h]
            call dword ptr [eax]
        state262_tick_done:
        }
        return;

    case 263: // Character04 native 0x00612DFD: aerial capture effect pair
        __asm {
            mov ecx, dword ptr [ebp-54h]
            movzx edx, word ptr [ecx+0Ah]
            test edx, edx
            jnz state263_skip_frame0_reset
            mov eax, dword ptr [ebp-54h]
            movzx ecx, word ptr [eax+0Ch]
            test ecx, ecx
            jnz state263_skip_frame0_reset
        }
        ResetFrame();
        __asm {
        state263_skip_frame0_reset:
            mov edx, dword ptr [ebp-54h]
            movzx eax, word ptr [edx+0Ah]
            cmp eax, 3
            jnz state263_skip_effect
            mov ecx, dword ptr [ebp-54h]
            movzx edx, word ptr [ecx+0Ch]
            test edx, edx
            jnz state263_skip_effect
            mov eax, dword ptr [ebp-54h]
            mov dword ptr [eax+3144h], 2
            mov ecx, dword ptr [ebp-54h]
            mov byte ptr [ecx+2C8h], 5
            mov word ptr [ebp-4Ch], 01Fh
            mov edx, dword ptr [ebp-54h]
            fld qword ptr [edx+20h]
            call _ftol2
            mov dword ptr [ebp-218h], eax
            fild dword ptr [ebp-218h]
            fstp qword ptr [ebp-48h]
            mov eax, dword ptr [ebp-54h]
            fld qword ptr [eax+28h]
            call _ftol2
            mov dword ptr [ebp-21Ch], eax
            fild dword ptr [ebp-21Ch]
            fstp qword ptr [ebp-40h]
            mov byte ptr [ebp-30h], 0
            mov byte ptr [ebp-2Fh], 1
            mov ecx, dword ptr [ebp-54h]
            movsx edx, byte ptr [ecx+50h]
            sub edx, -1
            neg edx
            sbb edx, edx
            inc edx
            mov dword ptr [ebp-34h], edx
            lea eax, [ebp-50h]
            push eax
            mov ecx, dword ptr [ebp-54h]
            mov ecx, dword ptr [ecx+7Ch]
            call Context::EmitEffect
            mov word ptr [ebp-4Ch], 01ACh
            mov edx, dword ptr [ebp-54h]
            fld qword ptr [edx+20h]
            call _ftol2
            mov dword ptr [ebp-220h], eax
            fild dword ptr [ebp-220h]
            fstp qword ptr [ebp-48h]
            mov eax, dword ptr [ebp-54h]
            fld qword ptr [eax+28h]
            call _ftol2
            sub eax, 014h
            mov dword ptr [ebp-224h], eax
            fild dword ptr [ebp-224h]
            fstp qword ptr [ebp-40h]
            mov ecx, dword ptr [ebp-54h]
            mov dl, byte ptr [ecx+50h]
            mov byte ptr [ebp-38h], dl
            mov byte ptr [ebp-30h], 2
            mov byte ptr [ebp-2Fh], 1
            mov dword ptr [ebp-50h], 1
            lea eax, [ebp-50h]
            push eax
            mov ecx, dword ptr [ebp-54h]
            mov edx, dword ptr [ecx]
            mov ecx, dword ptr [ebp-54h]
            call dword ptr [edx+24h]
        state263_skip_effect:
            mov eax, dword ptr [ebp-54h]
            mov cx, word ptr [eax+0Ch]
            add cx, 1
            mov edx, dword ptr [ebp-54h]
            mov word ptr [edx+0Ch], cx
            mov eax, dword ptr [ebp-54h]
            movzx ecx, word ptr [eax+0Ch]
            movzx edx, word ptr [ebp-04h]
            cmp ecx, edx
            jl state263_tick_done
            mov eax, dword ptr [ebp-54h]
            mov word ptr [eax+0Ch], 0
            mov ecx, dword ptr [ebp-54h]
            mov dx, word ptr [ecx+0Ah]
            add dx, 1
            mov eax, dword ptr [ebp-54h]
            mov word ptr [eax+0Ah], dx
            mov ecx, dword ptr [ebp-54h]
            mov dword ptr [ecx+168h], 3
            mov edx, dword ptr [ebp-54h]
            movzx eax, word ptr [edx+0Ah]
            movzx ecx, word ptr [ebp-08h]
            cmp eax, ecx
            jl state263_tick_done
            mov edx, dword ptr [ebp-54h]
            mov word ptr [edx+08h], 0
            mov eax, dword ptr [ebp-54h]
            mov edx, dword ptr [eax]
            mov ecx, dword ptr [ebp-54h]
            call dword ptr [edx]
        }
        FaceOpponent();
        __asm {
        state263_tick_done:
        }
        return;


    case 264: // Character04 native 0x00612F90: alternate aerial capture effect
        __asm {
            mov eax, dword ptr [ebp-54h]
            movzx ecx, word ptr [eax+0Ah]
            test ecx, ecx
            jnz state264_skip_frame0_reset
            mov edx, dword ptr [ebp-54h]
            movzx eax, word ptr [edx+0Ch]
            test eax, eax
            jnz state264_skip_frame0_reset
        }
        ResetFrame();
        __asm {
        state264_skip_frame0_reset:
            mov ecx, dword ptr [ebp-54h]
            movzx edx, word ptr [ecx+0Ah]
            cmp edx, 3
            jnz state264_skip_effect
            mov eax, dword ptr [ebp-54h]
            movzx ecx, word ptr [eax+0Ch]
            test ecx, ecx
            jnz state264_skip_effect
            mov edx, dword ptr [ebp-54h]
            mov dword ptr [edx+3144h], 2
            mov eax, dword ptr [ebp-54h]
            mov byte ptr [eax+2C8h], 5
            mov word ptr [ebp-4Ch], 01Fh
            mov ecx, dword ptr [ebp-54h]
            fld qword ptr [ecx+20h]
            call _ftol2
            mov dword ptr [ebp-228h], eax
            fild dword ptr [ebp-228h]
            fstp qword ptr [ebp-48h]
            mov edx, dword ptr [ebp-54h]
            fld qword ptr [edx+28h]
            call _ftol2
            mov dword ptr [ebp-22Ch], eax
            fild dword ptr [ebp-22Ch]
            fstp qword ptr [ebp-40h]
            mov byte ptr [ebp-30h], 0
            mov byte ptr [ebp-2Fh], 1
            mov eax, dword ptr [ebp-54h]
            movsx ecx, byte ptr [eax+50h]
            sub ecx, -1
            neg ecx
            sbb ecx, ecx
            inc ecx
            mov dword ptr [ebp-34h], ecx
            lea edx, [ebp-50h]
            push edx
            mov eax, dword ptr [ebp-54h]
            mov ecx, dword ptr [eax+7Ch]
            call Context::EmitEffect
            mov word ptr [ebp-4Ch], 01ADh
            mov ecx, dword ptr [ebp-54h]
            fld qword ptr [ecx+20h]
            call _ftol2
            mov dword ptr [ebp-230h], eax
            fild dword ptr [ebp-230h]
            fstp qword ptr [ebp-48h]
            mov edx, dword ptr [ebp-54h]
            fld qword ptr [edx+28h]
            call _ftol2
            sub eax, 014h
            mov dword ptr [ebp-234h], eax
            fild dword ptr [ebp-234h]
            fstp qword ptr [ebp-40h]
            mov eax, dword ptr [ebp-54h]
            mov cl, byte ptr [eax+50h]
            mov byte ptr [ebp-38h], cl
            mov byte ptr [ebp-30h], 2
            mov byte ptr [ebp-2Fh], 1
            mov dword ptr [ebp-50h], 1
            lea edx, [ebp-50h]
            push edx
            mov eax, dword ptr [ebp-54h]
            mov edx, dword ptr [eax]
            mov ecx, dword ptr [ebp-54h]
            call dword ptr [edx+24h]
        state264_skip_effect:
            mov eax, dword ptr [ebp-54h]
            mov cx, word ptr [eax+0Ch]
            add cx, 1
            mov edx, dword ptr [ebp-54h]
            mov word ptr [edx+0Ch], cx
            mov eax, dword ptr [ebp-54h]
            movzx ecx, word ptr [eax+0Ch]
            movzx edx, word ptr [ebp-04h]
            cmp ecx, edx
            jl state264_tick_done
            mov eax, dword ptr [ebp-54h]
            mov word ptr [eax+0Ch], 0
            mov ecx, dword ptr [ebp-54h]
            mov dx, word ptr [ecx+0Ah]
            add dx, 1
            mov eax, dword ptr [ebp-54h]
            mov word ptr [eax+0Ah], dx
            mov ecx, dword ptr [ebp-54h]
            mov dword ptr [ecx+168h], 3
            mov edx, dword ptr [ebp-54h]
            movzx eax, word ptr [edx+0Ah]
            movzx ecx, word ptr [ebp-08h]
            cmp eax, ecx
            jl state264_tick_done
            mov edx, dword ptr [ebp-54h]
            mov word ptr [edx+08h], 0
            mov eax, dword ptr [ebp-54h]
            mov edx, dword ptr [eax]
            mov ecx, dword ptr [ebp-54h]
            call dword ptr [edx]
        }
        FaceOpponent();
        __asm {
        state264_tick_done:
        }
        return;

    case 265: // Character04 native 0x00613123: charge capture and dual local effects
        __asm {
            mov eax, dword ptr [ebp-54h]
            movzx ecx, word ptr [eax+0Ah]
            test ecx, ecx
            jnz state265_skip_frame0_reset
            mov edx, dword ptr [ebp-54h]
            movzx eax, word ptr [edx+0Ch]
            test eax, eax
            jnz state265_skip_frame0_reset
        }
        ResetFrame();
        __asm {
        state265_skip_frame0_reset:
            mov ecx, dword ptr [ebp-54h]
            movzx edx, word ptr [ecx+0Ah]
            test edx, edx
            jnz state265_skip_frame0_effect
            mov eax, dword ptr [ebp-54h]
            movzx ecx, word ptr [eax+0Ch]
            test ecx, ecx
            jnz state265_skip_frame0_effect
            mov word ptr [ebp-4Ch], 021h
            mov byte ptr [ebp-24h], 0Bh
            mov edx, dword ptr [ebp-54h]
            fld qword ptr [edx+20h]
            call _ftol2
            mov dword ptr [ebp-238h], eax
            fild dword ptr [ebp-238h]
            fstp qword ptr [ebp-48h]
            mov eax, dword ptr [ebp-54h]
            fld qword ptr [eax+28h]
            call _ftol2
            sub eax, 028h
            mov dword ptr [ebp-23Ch], eax
            fild dword ptr [ebp-23Ch]
            fstp qword ptr [ebp-40h]
            mov byte ptr [ebp-30h], 2
            mov byte ptr [ebp-2Fh], 1
            lea ecx, [ebp-50h]
            push ecx
            mov edx, dword ptr [ebp-54h]
            mov ecx, dword ptr [edx+7Ch]
            call Context::EmitEffect
        }
        StartTrail(3);
        __asm {
            mov eax, dword ptr [ebp-54h]
            cmp dword ptr [eax+3144h], 4
            jnz state265_alternate_cost
            mov ecx, dword ptr [ebp-54h]
            mov edx, dword ptr [ecx+3148h]
            sub edx, 03E8h
            mov eax, dword ptr [ebp-54h]
            mov dword ptr [eax+3148h], edx
            mov ecx, dword ptr [ebp-54h]
            cmp dword ptr [ecx+3148h], 0
            jnl state265_cost_ready
            mov edx, dword ptr [ebp-54h]
            mov dword ptr [edx+3148h], 0
        state265_cost_ready:
            jmp state265_cost_merge
        state265_alternate_cost:
            mov eax, dword ptr [ebp-54h]
            movsx ecx, byte ptr [eax+120h]
            test ecx, ecx
            jnz state265_alternate_cost_250
            mov edx, dword ptr [ebp-54h]
            fld qword ptr [edx+118h]
            _emit 0DCh
            _emit 025h
            _emit 030h
            _emit 07Ch
            _emit 078h
            _emit 000h
            mov eax, dword ptr [ebp-54h]
            fstp qword ptr [eax+118h]
            jmp state265_cost_merge
        state265_alternate_cost_250:
            mov ecx, dword ptr [ebp-54h]
            fld qword ptr [ecx+118h]
            _emit 0DCh
            _emit 025h
            _emit 070h
            _emit 07Ch
            _emit 078h
            _emit 000h
            mov edx, dword ptr [ebp-54h]
            fstp qword ptr [edx+118h]
        state265_cost_merge:
        }
        __asm {
        state265_skip_frame0_effect:
            mov eax, dword ptr [ebp-54h]
            movzx ecx, word ptr [eax+0Ah]
            cmp ecx, 3
            jnz state265_skip_frame3_effect
            mov edx, dword ptr [ebp-54h]
            movzx eax, word ptr [edx+0Ch]
            test eax, eax
            jnz state265_skip_frame3_effect
            mov ecx, dword ptr [ebp-54h]
            mov dword ptr [ecx+3144h], 2
            mov edx, dword ptr [ebp-54h]
            mov byte ptr [edx+2C8h], 5
            mov word ptr [ebp-4Ch], 01Fh
            mov eax, dword ptr [ebp-54h]
            fld qword ptr [eax+20h]
            call _ftol2
            mov dword ptr [ebp-240h], eax
            fild dword ptr [ebp-240h]
            fstp qword ptr [ebp-48h]
            mov ecx, dword ptr [ebp-54h]
            fld qword ptr [ecx+28h]
            call _ftol2
            mov dword ptr [ebp-244h], eax
            fild dword ptr [ebp-244h]
            fstp qword ptr [ebp-40h]
            mov byte ptr [ebp-30h], 0
            mov byte ptr [ebp-2Fh], 1
            mov edx, dword ptr [ebp-54h]
            movsx eax, byte ptr [edx+50h]
            sub eax, -1
            neg eax
            sbb eax, eax
            inc eax
            mov dword ptr [ebp-34h], eax
            lea ecx, [ebp-50h]
            push ecx
            mov edx, dword ptr [ebp-54h]
            mov ecx, dword ptr [edx+7Ch]
            call Context::EmitEffect
            mov word ptr [ebp-4Ch], 01AEh
            mov eax, dword ptr [ebp-54h]
            fld qword ptr [eax+20h]
            call _ftol2
            mov dword ptr [ebp-248h], eax
            fild dword ptr [ebp-248h]
            fstp qword ptr [ebp-48h]
            mov ecx, dword ptr [ebp-54h]
            fld qword ptr [ecx+28h]
            call _ftol2
            sub eax, 014h
            mov dword ptr [ebp-24Ch], eax
            fild dword ptr [ebp-24Ch]
            fstp qword ptr [ebp-40h]
            mov edx, dword ptr [ebp-54h]
            mov al, byte ptr [edx+50h]
            mov byte ptr [ebp-38h], al
            mov byte ptr [ebp-30h], 2
            mov byte ptr [ebp-2Fh], 1
            mov dword ptr [ebp-50h], 1
            lea ecx, [ebp-50h]
            push ecx
            mov edx, dword ptr [ebp-54h]
            mov eax, dword ptr [edx]
            mov ecx, dword ptr [ebp-54h]
            call dword ptr [eax+24h]
        state265_skip_frame3_effect:
            mov ecx, dword ptr [ebp-54h]
            mov dx, word ptr [ecx+0Ch]
            add dx, 1
            mov eax, dword ptr [ebp-54h]
            mov word ptr [eax+0Ch], dx
            mov ecx, dword ptr [ebp-54h]
            movzx edx, word ptr [ecx+0Ch]
            movzx eax, word ptr [ebp-04h]
            cmp edx, eax
            jl state265_tick_done
            mov ecx, dword ptr [ebp-54h]
            mov word ptr [ecx+0Ch], 0
            mov edx, dword ptr [ebp-54h]
            mov ax, word ptr [edx+0Ah]
            add ax, 1
            mov ecx, dword ptr [ebp-54h]
            mov word ptr [ecx+0Ah], ax
            mov edx, dword ptr [ebp-54h]
            mov dword ptr [edx+168h], 3
            mov eax, dword ptr [ebp-54h]
            movzx ecx, word ptr [eax+0Ah]
            movzx edx, word ptr [ebp-08h]
            cmp ecx, edx
            jl state265_tick_done
            mov eax, dword ptr [ebp-54h]
            mov word ptr [eax+08h], 0
            mov ecx, dword ptr [ebp-54h]
            mov edx, dword ptr [ecx]
            mov ecx, dword ptr [ebp-54h]
            call dword ptr [edx]
        }
        FaceOpponent();
        __asm {
        state265_tick_done:
        }
        return;

    case 266: // Character04 native 0x006133B5: effect1B0 aerial follow-through
        __asm {
            mov eax, dword ptr [ebp-54h]
            mov dword ptr [eax+168h], 2
            mov ecx, dword ptr [ebp-54h]
            movzx edx, word ptr [ecx+0Ah]
            test edx, edx
            jnz state266_skip_frame0_reset
            mov eax, dword ptr [ebp-54h]
            movzx ecx, word ptr [eax+0Ch]
            test ecx, ecx
            jnz state266_skip_frame0_reset
        }
        ResetFrame();
        __asm {
        state266_skip_frame0_reset:
            mov edx, dword ptr [ebp-54h]
            movzx eax, word ptr [edx+0Ah]
            cmp eax, 3
            jnz state266_skip_effect
            mov ecx, dword ptr [ebp-54h]
            movzx edx, word ptr [ecx+0Ch]
            test edx, edx
            jnz state266_skip_effect
            mov eax, dword ptr [ebp-54h]
            mov dword ptr [eax+3144h], 2
            mov word ptr [ebp-4Ch], 01B0h
            mov ecx, dword ptr [ebp-54h]
            fld qword ptr [ecx+20h]
            call _ftol2
            mov edx, dword ptr [ebp-54h]
            movsx ecx, byte ptr [edx+50h]
            imul ecx, ecx, 050h
            add eax, ecx
            mov dword ptr [ebp-250h], eax
            fild dword ptr [ebp-250h]
            fstp qword ptr [ebp-48h]
            mov edx, dword ptr [ebp-54h]
            fld qword ptr [edx+28h]
            call _ftol2
            sub eax, 014h
            mov dword ptr [ebp-254h], eax
            fild dword ptr [ebp-254h]
            fstp qword ptr [ebp-40h]
            mov dword ptr [ebp-50h], 1
            mov byte ptr [ebp-30h], 2
            mov eax, dword ptr [ebp-54h]
            mov cl, byte ptr [eax+50h]
            mov byte ptr [ebp-38h], cl
            mov byte ptr [ebp-2Fh], 1
            lea edx, [ebp-50h]
            push edx
            mov eax, dword ptr [ebp-54h]
            mov edx, dword ptr [eax]
            mov ecx, dword ptr [ebp-54h]
            call dword ptr [edx+24h]
        state266_skip_effect:
            mov eax, dword ptr [ebp-54h]
            mov cx, word ptr [eax+0Ch]
            add cx, 1
            mov edx, dword ptr [ebp-54h]
            mov word ptr [edx+0Ch], cx
            mov eax, dword ptr [ebp-54h]
            movzx ecx, word ptr [eax+0Ch]
            movzx edx, word ptr [ebp-04h]
            cmp ecx, edx
            jl state266_tick_done
            mov eax, dword ptr [ebp-54h]
            mov word ptr [eax+0Ch], 0
            mov ecx, dword ptr [ebp-54h]
            mov dx, word ptr [ecx+0Ah]
            add dx, 1
            mov eax, dword ptr [ebp-54h]
            mov word ptr [eax+0Ah], dx
            mov ecx, dword ptr [ebp-54h]
            mov dword ptr [ecx+168h], 3
            mov edx, dword ptr [ebp-54h]
            movzx eax, word ptr [edx+0Ah]
            movzx ecx, word ptr [ebp-08h]
            cmp eax, ecx
            jl state266_tick_done
            mov edx, dword ptr [ebp-54h]
            mov word ptr [edx+08h], 0
            mov eax, dword ptr [ebp-54h]
            mov edx, dword ptr [eax]
            mov ecx, dword ptr [ebp-54h]
            call dword ptr [edx]
        }
        FaceOpponent();
        __asm {
        state266_tick_done:
        }
        return;


    case 267: // Character04 native 0x006134F0: effect1B0 aerial follow-through
        __asm {
            mov eax, dword ptr [ebp-54h]
            mov dword ptr [eax+168h], 2
            mov ecx, dword ptr [ebp-54h]
            movzx edx, word ptr [ecx+0Ah]
            test edx, edx
            jnz state267_skip_frame0_reset
            mov eax, dword ptr [ebp-54h]
            movzx ecx, word ptr [eax+0Ch]
            test ecx, ecx
            jnz state267_skip_frame0_reset
        }
        ResetFrame();
        __asm {
        state267_skip_frame0_reset:
            mov edx, dword ptr [ebp-54h]
            movzx eax, word ptr [edx+0Ah]
            cmp eax, 3
            jnz state267_skip_effect
            mov ecx, dword ptr [ebp-54h]
            movzx edx, word ptr [ecx+0Ch]
            test edx, edx
            jnz state267_skip_effect
            mov eax, dword ptr [ebp-54h]
            mov dword ptr [eax+3144h], 2
            mov word ptr [ebp-4Ch], 01B0h
            mov ecx, dword ptr [ebp-54h]
            fld qword ptr [ecx+20h]
            call _ftol2
            mov edx, dword ptr [ebp-54h]
            movsx ecx, byte ptr [edx+50h]
            imul ecx, ecx, 0A0h
            add eax, ecx
            mov dword ptr [ebp-258h], eax
            fild dword ptr [ebp-258h]
            fstp qword ptr [ebp-48h]
            mov edx, dword ptr [ebp-54h]
            fld qword ptr [edx+28h]
            call _ftol2
            sub eax, 014h
            mov dword ptr [ebp-25Ch], eax
            fild dword ptr [ebp-25Ch]
            fstp qword ptr [ebp-40h]
            mov dword ptr [ebp-50h], 1
            mov byte ptr [ebp-30h], 2
            mov eax, dword ptr [ebp-54h]
            mov cl, byte ptr [eax+50h]
            mov byte ptr [ebp-38h], cl
            mov byte ptr [ebp-2Fh], 1
            lea edx, [ebp-50h]
            push edx
            mov eax, dword ptr [ebp-54h]
            mov edx, dword ptr [eax]
            mov ecx, dword ptr [ebp-54h]
            call dword ptr [edx+24h]
        state267_skip_effect:
            mov eax, dword ptr [ebp-54h]
            mov cx, word ptr [eax+0Ch]
            add cx, 1
            mov edx, dword ptr [ebp-54h]
            mov word ptr [edx+0Ch], cx
            mov eax, dword ptr [ebp-54h]
            movzx ecx, word ptr [eax+0Ch]
            movzx edx, word ptr [ebp-04h]
            cmp ecx, edx
            jl state267_tick_done
            mov eax, dword ptr [ebp-54h]
            mov word ptr [eax+0Ch], 0
            mov ecx, dword ptr [ebp-54h]
            mov dx, word ptr [ecx+0Ah]
            add dx, 1
            mov eax, dword ptr [ebp-54h]
            mov word ptr [eax+0Ah], dx
            mov ecx, dword ptr [ebp-54h]
            mov dword ptr [ecx+168h], 3
            mov edx, dword ptr [ebp-54h]
            movzx eax, word ptr [edx+0Ah]
            movzx ecx, word ptr [ebp-08h]
            cmp eax, ecx
            jl state267_tick_done
            mov edx, dword ptr [ebp-54h]
            mov word ptr [edx+08h], 0
            mov eax, dword ptr [ebp-54h]
            mov edx, dword ptr [eax]
            mov ecx, dword ptr [ebp-54h]
            call dword ptr [edx]
        }
        FaceOpponent();
        __asm {
        state267_tick_done:
        }
        return;


    case 268: // Character04 native 0x00613632: effect1B0 aerial follow-through
        __asm {
            mov eax, dword ptr [ebp-54h]
            mov dword ptr [eax+168h], 2
            mov ecx, dword ptr [ebp-54h]
            movzx edx, word ptr [ecx+0Ah]
            test edx, edx
            jnz state268_skip_frame0_reset
            mov eax, dword ptr [ebp-54h]
            movzx ecx, word ptr [eax+0Ch]
            test ecx, ecx
            jnz state268_skip_frame0_reset
        }
        ResetFrame();
        __asm {
        state268_skip_frame0_reset:
            mov edx, dword ptr [ebp-54h]
            movzx eax, word ptr [edx+0Ah]
            cmp eax, 3
            jnz state268_skip_effect
            mov ecx, dword ptr [ebp-54h]
            movzx edx, word ptr [ecx+0Ch]
            test edx, edx
            jnz state268_skip_effect
            mov eax, dword ptr [ebp-54h]
            mov dword ptr [eax+3144h], 2
            mov word ptr [ebp-4Ch], 01B0h
            mov ecx, dword ptr [ebp-54h]
            fld qword ptr [ecx+20h]
            call _ftol2
            mov edx, dword ptr [ebp-54h]
            movsx ecx, byte ptr [edx+50h]
            imul ecx, ecx, 0F0h
            add eax, ecx
            mov dword ptr [ebp-260h], eax
            fild dword ptr [ebp-260h]
            fstp qword ptr [ebp-48h]
            mov edx, dword ptr [ebp-54h]
            fld qword ptr [edx+28h]
            call _ftol2
            sub eax, 014h
            mov dword ptr [ebp-264h], eax
            fild dword ptr [ebp-264h]
            fstp qword ptr [ebp-40h]
            mov dword ptr [ebp-50h], 1
            mov byte ptr [ebp-30h], 2
            mov eax, dword ptr [ebp-54h]
            mov cl, byte ptr [eax+50h]
            mov byte ptr [ebp-38h], cl
            mov byte ptr [ebp-2Fh], 1
            lea edx, [ebp-50h]
            push edx
            mov eax, dword ptr [ebp-54h]
            mov edx, dword ptr [eax]
            mov ecx, dword ptr [ebp-54h]
            call dword ptr [edx+24h]
        state268_skip_effect:
            mov eax, dword ptr [ebp-54h]
            mov cx, word ptr [eax+0Ch]
            add cx, 1
            mov edx, dword ptr [ebp-54h]
            mov word ptr [edx+0Ch], cx
            mov eax, dword ptr [ebp-54h]
            movzx ecx, word ptr [eax+0Ch]
            movzx edx, word ptr [ebp-04h]
            cmp ecx, edx
            jl state268_tick_done
            mov eax, dword ptr [ebp-54h]
            mov word ptr [eax+0Ch], 0
            mov ecx, dword ptr [ebp-54h]
            mov dx, word ptr [ecx+0Ah]
            add dx, 1
            mov eax, dword ptr [ebp-54h]
            mov word ptr [eax+0Ah], dx
            mov ecx, dword ptr [ebp-54h]
            mov dword ptr [ecx+168h], 3
            mov edx, dword ptr [ebp-54h]
            movzx eax, word ptr [edx+0Ah]
            movzx ecx, word ptr [ebp-08h]
            cmp eax, ecx
            jl state268_tick_done
            mov edx, dword ptr [ebp-54h]
            mov word ptr [edx+08h], 0
            mov eax, dword ptr [ebp-54h]
            mov edx, dword ptr [eax]
            mov ecx, dword ptr [ebp-54h]
            call dword ptr [edx]
        }
        FaceOpponent();
        __asm {
        state268_tick_done:
        }
        return;

    case 269: // Character04 native 0x00613774: zero-velocity aerial recovery
        __asm {
            mov eax, dword ptr [ebp-54h]
            movzx ecx, word ptr [eax+0Ah]
            test ecx, ecx
            jnz state269_skip_startup
            mov edx, dword ptr [ebp-54h]
            movzx eax, word ptr [edx+0Ch]
            test eax, eax
            jnz state269_skip_startup
            mov ecx, dword ptr [ebp-54h]
            _emit 0DDh
            _emit 005h
            _emit 0F8h
            _emit 072h
            _emit 078h
            _emit 000h
            fstp qword ptr [ecx+30h]
            mov edx, dword ptr [ebp-54h]
            _emit 0DDh
            _emit 005h
            _emit 0F8h
            _emit 072h
            _emit 078h
            _emit 000h
            fstp qword ptr [edx+38h]
            mov eax, dword ptr [ebp-54h]
            mov byte ptr [eax+2C8h], 5
        state269_skip_startup:
            mov ecx, dword ptr [ebp-54h]
            mov dx, word ptr [ecx+0Ch]
            add dx, 1
            mov eax, dword ptr [ebp-54h]
            mov word ptr [eax+0Ch], dx
            mov ecx, dword ptr [ebp-54h]
            movzx edx, word ptr [ecx+0Ch]
            movzx eax, word ptr [ebp-04h]
            cmp edx, eax
            jl state269_tick_done
            mov ecx, dword ptr [ebp-54h]
            mov word ptr [ecx+0Ch], 0
            mov edx, dword ptr [ebp-54h]
            mov ax, word ptr [edx+0Ah]
            add ax, 1
            mov ecx, dword ptr [ebp-54h]
            mov word ptr [ecx+0Ah], ax
            mov edx, dword ptr [ebp-54h]
            mov dword ptr [edx+168h], 0
            mov eax, dword ptr [ebp-54h]
            movzx ecx, word ptr [eax+0Ah]
            movzx edx, word ptr [ebp-08h]
            cmp ecx, edx
            jl state269_tick_done
            mov eax, dword ptr [ebp-54h]
            mov word ptr [eax+08h], 0
            mov ecx, dword ptr [ebp-54h]
            mov edx, dword ptr [ecx]
            mov ecx, dword ptr [ebp-54h]
            call dword ptr [edx]
        }
        FaceOpponent();
        __asm {
        state269_tick_done:
        }
        return;

    case 303: // Character04 native 0x00613824: multi-stage aerial capture throw
        __asm {
            mov eax, dword ptr [ebp-54h]
            movzx ecx, word ptr [eax+0Ah]
            test ecx, ecx
            jnz state303_skip_frame0
            mov edx, dword ptr [ebp-54h]
            movzx eax, word ptr [edx+0Ch]
            test eax, eax
            jnz state303_skip_frame0
            mov ecx, dword ptr [ebp-54h]
            _emit 0DDh
            _emit 005h
            _emit 0F8h
            _emit 072h
            _emit 078h
            _emit 000h
            fstp qword ptr [ecx+30h]
            mov edx, dword ptr [ebp-54h]
            _emit 0DDh
            _emit 005h
            _emit 0F8h
            _emit 072h
            _emit 078h
            _emit 000h
            fstp qword ptr [edx+38h]
            mov eax, dword ptr [ebp-54h]
            _emit 0DDh
            _emit 005h
            _emit 0F8h
            _emit 072h
            _emit 078h
            _emit 000h
            fstp qword ptr [eax+48h]
        state303_skip_frame0:
            mov ecx, dword ptr [ebp-54h]
            movzx edx, word ptr [ecx+0Ah]
            cmp edx, 2
            jnz state303_skip_frame2_shake
            push 3
            push 032h
            mov ecx, dword ptr [ebp-54h]
            call SetHorizontalShake
        state303_skip_frame2_shake:
            mov eax, dword ptr [ebp-54h]
            movzx ecx, word ptr [eax+0Ah]
            cmp ecx, 2
            jnz state303_skip_frame2_effect
            mov edx, dword ptr [ebp-54h]
            movzx eax, word ptr [edx+0Ch]
            test eax, eax
            jnz state303_skip_frame2_effect
            mov ecx, dword ptr [ebp-54h]
            mov word ptr [ecx+16Ch], 1
            mov edx, dword ptr [ebp-54h]
            mov word ptr [edx+14Ch], 078h
            mov eax, dword ptr [ebp-54h]
            movsx ecx, word ptr [eax+148h]
            sub ecx, 03E8h
            mov edx, dword ptr [ebp-54h]
            mov word ptr [edx+148h], cx
            push 3
            push 0B0h
            mov ecx, dword ptr [ebp-54h]
            call SetTint
            mov word ptr [ebp-4Ch], 044h
            mov byte ptr [ebp-24h], 013h
            mov eax, dword ptr [ebp-54h]
            fld qword ptr [eax+20h]
            call _ftol2
            mov dword ptr [ebp-268h], eax
            fild dword ptr [ebp-268h]
            fstp qword ptr [ebp-48h]
            mov ecx, dword ptr [ebp-54h]
            fld qword ptr [ecx+28h]
            call _ftol2
            sub eax, 028h
            mov dword ptr [ebp-26Ch], eax
            fild dword ptr [ebp-26Ch]
            fstp qword ptr [ebp-40h]
            mov byte ptr [ebp-30h], 2
            mov dword ptr [ebp-50h], 1
            mov byte ptr [ebp-2Fh], 1
            lea edx, [ebp-50h]
            push edx
            mov eax, dword ptr [ebp-54h]
            mov ecx, dword ptr [eax+7Ch]
            call Context::EmitEffect
        state303_skip_frame2_effect:
            mov ecx, dword ptr [ebp-54h]
            movzx edx, word ptr [ecx+0Ah]
            cmp edx, 4
            jnz state303_skip_frame4
            mov eax, dword ptr [ebp-54h]
            movzx ecx, word ptr [eax+0Ch]
            test ecx, ecx
            jnz state303_skip_frame4
            mov edx, dword ptr [ebp-54h]
            mov byte ptr [edx+2C8h], 0
        state303_skip_frame4:
            mov eax, dword ptr [ebp-54h]
            movzx ecx, word ptr [eax+0Ah]
            cmp ecx, 8
            jnz state303_skip_frame8_velocity
            mov edx, dword ptr [ebp-54h]
            movzx eax, word ptr [edx+0Ch]
            test eax, eax
            jnz state303_skip_frame8_velocity
            mov ecx, dword ptr [ebp-54h]
            _emit 0DDh
            _emit 005h
            _emit 0C0h
            _emit 072h
            _emit 078h
            _emit 000h
            fstp qword ptr [ecx+30h]
        state303_skip_frame8_velocity:
            mov edx, dword ptr [ebp-54h]
            movzx eax, word ptr [edx+0Ah]
            cmp eax, 9
            jnz state303_skip_frame9_velocity
            mov ecx, dword ptr [ebp-54h]
            movzx edx, word ptr [ecx+0Ch]
            test edx, edx
            jnz state303_skip_frame9_velocity
            mov eax, dword ptr [ebp-54h]
            _emit 0DDh
            _emit 005h
            _emit 0A8h
            _emit 080h
            _emit 078h
            _emit 000h
            fstp qword ptr [eax+30h]
            mov ecx, dword ptr [ebp-54h]
            _emit 0DDh
            _emit 005h
            _emit 0B0h
            _emit 085h
            _emit 078h
            _emit 000h
            fstp qword ptr [ecx+40h]
        state303_skip_frame9_velocity:
            mov edx, dword ptr [ebp-54h]
            movzx eax, word ptr [edx+0Ah]
            cmp eax, 8
            jng state303_skip_horizontal_integrate
            mov ecx, dword ptr [ebp-54h]
            mov edx, dword ptr [ebp-54h]
            fld qword ptr [ecx+30h]
            fadd qword ptr [edx+40h]
            mov eax, dword ptr [ebp-54h]
            fstp qword ptr [eax+30h]
            mov ecx, dword ptr [ebp-54h]
            fld qword ptr [ecx+30h]
            _emit 0DCh
            _emit 01Dh
            _emit 0F8h
            _emit 072h
            _emit 078h
            _emit 000h
            fnstsw ax
            test ah, 5
            jpe state303_skip_horizontal_integrate
            mov edx, dword ptr [ebp-54h]
            _emit 0DDh
            _emit 005h
            _emit 0F8h
            _emit 072h
            _emit 078h
            _emit 000h
            fstp qword ptr [edx+30h]
        state303_skip_horizontal_integrate:
            mov eax, dword ptr [ebp-54h]
            movzx ecx, word ptr [eax+0Ah]
            cmp ecx, 8
            jnz state303_skip_frame8_result
            mov edx, dword ptr [ebp-54h]
            cmp dword ptr [edx+168h], 2
            jz state303_frame8_skip
            mov eax, dword ptr [ebp-54h]
            cmp dword ptr [eax+168h], 5
            jnz state303_frame8_check_hit
        state303_frame8_skip:
            mov ecx, dword ptr [ebp-54h]
            mov word ptr [ecx+0Ch], 0
            mov edx, dword ptr [ebp-54h]
            mov word ptr [edx+0Ah], 9
            jmp state303_exit
        state303_frame8_check_hit:
            mov eax, dword ptr [ebp-54h]
            cmp dword ptr [eax+168h], 3
            jnz state303_skip_frame8_result
            mov ecx, dword ptr [ebp-54h]
            mov edx, dword ptr [ecx+78h]
            mov eax, dword ptr [edx]
            mov word ptr [eax+14Ah], 0270Fh
            mov ecx, dword ptr [ebp-54h]
            mov edx, dword ptr [ecx]
            mov ecx, dword ptr [ebp-54h]
            call dword ptr [edx]
            mov eax, dword ptr [ebp-54h]
            mov ecx, dword ptr [eax+78h]
            mov edx, dword ptr [ecx]
            mov eax, dword ptr [ebp-54h]
            mov ecx, dword ptr [eax+78h]
            mov ecx, dword ptr [ecx]
            mov edx, dword ptr [edx]
            call dword ptr [edx]
            mov eax, dword ptr [ebp-54h]
            mov ecx, dword ptr [eax+78h]
            mov edx, dword ptr [ecx]
            _emit 0DDh
            _emit 005h
            _emit 0F8h
            _emit 072h
            _emit 078h
            _emit 000h
            fstp qword ptr [edx+28h]
            mov eax, dword ptr [ebp-54h]
            mov ecx, dword ptr [eax+78h]
            mov edx, dword ptr [ecx]
            mov word ptr [edx+8], 06Ch
            mov eax, dword ptr [ebp-54h]
            mov word ptr [eax+8], 0132h
            jmp state303_exit
        state303_skip_frame8_result:
            mov ecx, dword ptr [ebp-54h]
            movzx edx, word ptr [ecx+0Ah]
            test edx, edx
            jng state303_skip_horizontal_shake
            mov eax, dword ptr [ebp-54h]
            movzx ecx, word ptr [eax+0Ah]
            cmp ecx, 12h
            jnl state303_skip_horizontal_shake
            push 3
            push 32h
            mov ecx, dword ptr [ebp-54h]
            call SetHorizontalShake
        state303_skip_horizontal_shake:
            mov edx, dword ptr [ebp-54h]
            mov ax, word ptr [edx+0Ch]
            add ax, 1
            mov ecx, dword ptr [ebp-54h]
            mov word ptr [ecx+0Ch], ax
            mov edx, dword ptr [ebp-54h]
            movzx eax, word ptr [edx+0Ch]
            movzx ecx, word ptr [ebp-04h]
            cmp eax, ecx
            jl state303_exit
            mov edx, dword ptr [ebp-54h]
            mov word ptr [edx+0Ch], 0
            mov eax, dword ptr [ebp-54h]
            mov cx, word ptr [eax+0Ah]
            add cx, 1
            mov edx, dword ptr [ebp-54h]
            mov word ptr [edx+0Ah], cx
            mov eax, dword ptr [ebp-54h]
            mov dword ptr [eax+168h], 0
            mov ecx, dword ptr [ebp-54h]
            movzx edx, word ptr [ecx+0Ah]
            movzx eax, word ptr [ebp-08h]
            cmp edx, eax
            jl state303_exit
            mov ecx, dword ptr [ebp-54h]
            mov word ptr [ecx+08h], 0
            mov edx, dword ptr [ebp-54h]
            mov eax, dword ptr [edx]
            mov ecx, dword ptr [ebp-54h]
            call dword ptr [eax]
        state303_exit:
        }
        return;
    case 304: // Character04 native 0x00613B1F: alternate multi-stage aerial capture throw
        __asm {
            mov ecx,[ebp-54h]
            movzx edx,word ptr [ecx+0Ah]
            test edx,edx
            jnz state304_00613B59
            mov eax,[ebp-54h]
            movzx ecx,word ptr [eax+0Ch]
            test ecx,ecx
            jnz state304_00613B59
            mov edx,[ebp-54h]
            _emit 0DDh
            _emit 005h
            _emit 0F8h
            _emit 072h
            _emit 078h
            _emit 000h
            fstp qword ptr [edx+30h]
            mov eax,[ebp-54h]
            _emit 0DDh
            _emit 005h
            _emit 0F8h
            _emit 072h
            _emit 078h
            _emit 000h
            fstp qword ptr [eax+38h]
            mov ecx,[ebp-54h]
            _emit 0DDh
            _emit 005h
            _emit 0F8h
            _emit 072h
            _emit 078h
            _emit 000h
            fstp qword ptr [ecx+48h]
        state304_00613B59:
            mov edx,[ebp-54h]
            movzx eax,word ptr [edx+0Ah]
            cmp eax,2h
            jnz state304_00613B71
            push 3h
            push 32h
            mov ecx,[ebp-54h]
            call SetHorizontalShake
        state304_00613B71:
            mov ecx,[ebp-54h]
            movzx edx,word ptr [ecx+0Ah]
            cmp edx,2h
            jnz state304_00613C30
            mov eax,[ebp-54h]
            movzx ecx,word ptr [eax+0Ch]
            test ecx,ecx
            jnz state304_00613C30
            mov edx,[ebp-54h]
            mov word ptr [edx+16Ch],1h
            mov eax,[ebp-54h]
            mov word ptr [eax+14Ch],78h
            mov ecx,[ebp-54h]
            movsx edx,word ptr [ecx+148h]
            sub edx,7D0h
            mov eax,[ebp-54h]
            mov [eax+148h],dx
            push 3h
            push 0B0h
            mov ecx,[ebp-54h]
            call SetTint
            mov word ptr [ebp-4Ch],45h
            mov byte ptr [ebp-24h],5h
            mov ecx,[ebp-54h]
            fld qword ptr [ecx+20h]
            call _ftol2
            mov [ebp-270h],eax
            fild dword ptr [ebp-270h]
            fstp qword ptr [ebp-48h]
            mov edx,[ebp-54h]
            fld qword ptr [edx+28h]
            call _ftol2
            sub eax,28h
            mov [ebp-274h],eax
            fild dword ptr [ebp-274h]
            fstp qword ptr [ebp-40h]
            mov byte ptr [ebp-30h],2h
            mov dword ptr [ebp-50h],1h
            mov byte ptr [ebp-2Fh],1h
            lea eax,[ebp-50h]
            push eax
            mov ecx,[ebp-54h]
            mov ecx,[ecx+7Ch]
            call Context::EmitEffect
        state304_00613C30:
            mov edx,[ebp-54h]
            movzx eax,word ptr [edx+0Ah]
            cmp eax,4h
            jnz state304_00613C51
            mov ecx,[ebp-54h]
            movzx edx,word ptr [ecx+0Ch]
            test edx,edx
            jnz state304_00613C51
            mov eax,[ebp-54h]
            mov byte ptr [eax+2C8h],0
        state304_00613C51:
            mov ecx,[ebp-54h]
            movzx edx,word ptr [ecx+0Ah]
            cmp edx,8h
            jnz state304_00613C74
            mov eax,[ebp-54h]
            movzx ecx,word ptr [eax+0Ch]
            test ecx,ecx
            jnz state304_00613C74
            mov edx,[ebp-54h]
            _emit 0DDh
            _emit 005h
            _emit 050h
            _emit 08Bh
            _emit 078h
            _emit 000h
            fstp qword ptr [edx+30h]
        state304_00613C74:
            mov eax,[ebp-54h]
            movzx ecx,word ptr [eax+0Ah]
            cmp ecx,9h
            jnz state304_00613CA3
            mov edx,[ebp-54h]
            movzx eax,word ptr [edx+0Ch]
            test eax,eax
            jnz state304_00613CA3
            mov ecx,[ebp-54h]
            _emit 0DDh
            _emit 005h
            _emit 0A8h
            _emit 080h
            _emit 078h
            _emit 000h
            fstp qword ptr [ecx+30h]
            mov edx,[ebp-54h]
            _emit 0DDh
            _emit 005h
            _emit 0B0h
            _emit 085h
            _emit 078h
            _emit 000h
            fstp qword ptr [edx+40h]
        state304_00613CA3:
            mov eax,[ebp-54h]
            movzx ecx,word ptr [eax+0Ah]
            cmp ecx,8h
            jng state304_00613CE0
            mov edx,[ebp-54h]
            mov eax,[ebp-54h]
            fld qword ptr [edx+30h]
            fadd qword ptr [eax+40h]
            mov ecx,[ebp-54h]
            fstp qword ptr [ecx+30h]
            mov edx,[ebp-54h]
            fld qword ptr [edx+30h]
            _emit 0DCh
            _emit 01Dh
            _emit 0F8h
            _emit 072h
            _emit 078h
            _emit 000h
            fnstsw ax
            test ah,5h
            jpe state304_00613CE0
            mov eax,[ebp-54h]
            _emit 0DDh
            _emit 005h
            _emit 0F8h
            _emit 072h
            _emit 078h
            _emit 000h
            fstp qword ptr [eax+30h]
        state304_00613CE0:
            mov ecx,[ebp-54h]
            movzx edx,word ptr [ecx+0Ah]
            cmp edx,8h
            jnz state304_00613D87
            mov eax,[ebp-54h]
            cmp dword ptr [eax+168h],2h
            jz state304_00613D08
            mov ecx,[ebp-54h]
            cmp dword ptr [ecx+168h],5h
            jnz state304_00613D1F
        state304_00613D08:
            mov edx,[ebp-54h]
            mov word ptr [edx+0Ch],0
            mov eax,[ebp-54h]
            mov word ptr [eax+0Ah],9h
            jmp state304_exit
        state304_00613D1F:
            mov ecx,[ebp-54h]
            cmp dword ptr [ecx+168h],3h
            jnz state304_00613D87
            mov edx,[ebp-54h]
            mov eax,[edx+78h]
            mov ecx,[eax]
            mov word ptr [ecx+14Ah],270Fh
            mov edx,[ebp-54h]
            mov eax,[edx]
            mov ecx,[ebp-54h]
            call dword ptr [eax]
            mov ecx,[ebp-54h]
            mov edx,[ecx+78h]
            mov eax,[edx]
            mov ecx,[ebp-54h]
            mov edx,[ecx+78h]
            mov ecx,[edx]
            mov eax,[eax]
            call dword ptr [eax]
            mov ecx,[ebp-54h]
            mov edx,[ecx+78h]
            mov eax,[edx]
            _emit 0DDh
            _emit 005h
            _emit 0F8h
            _emit 072h
            _emit 078h
            _emit 000h
            fstp qword ptr [eax+28h]
            mov ecx,[ebp-54h]
            mov edx,[ecx+78h]
            mov eax,[edx]
            mov word ptr [eax+8h],6Ch
            mov ecx,[ebp-54h]
            mov word ptr [ecx+8h],133h
            jmp state304_exit
        state304_00613D87:
            mov edx,[ebp-54h]
            movzx eax,word ptr [edx+0Ah]
            test eax,eax
            jng state304_00613DAA
            mov ecx,[ebp-54h]
            movzx edx,word ptr [ecx+0Ah]
            cmp edx,12h
            jnl state304_00613DAA
            push 3h
            push 32h
            mov ecx,[ebp-54h]
            call SetHorizontalShake
        state304_00613DAA:
            mov eax,[ebp-54h]
            mov cx,[eax+0Ch]
            add cx,1h
            mov edx,[ebp-54h]
            mov [edx+0Ch],cx
            mov eax,[ebp-54h]
            movzx ecx,word ptr [eax+0Ch]
            movzx edx,word ptr [ebp-4h]
            cmp ecx,edx
            jl state304_exit
            mov eax,[ebp-54h]
            mov word ptr [eax+0Ch],0
            mov ecx,[ebp-54h]
            mov dx,[ecx+0Ah]
            add dx,1h
            mov eax,[ebp-54h]
            mov [eax+0Ah],dx
            mov ecx,[ebp-54h]
            mov dword ptr [ecx+168h],0
            mov edx,[ebp-54h]
            movzx eax,word ptr [edx+0Ah]
            movzx ecx,word ptr [ebp-8h]
            cmp eax,ecx
            jl state304_exit
            mov edx,[ebp-54h]
            mov word ptr [edx+8h],0
            mov eax,[ebp-54h]
            mov edx,[eax]
            mov ecx,[ebp-54h]
            call dword ptr [edx]
        state304_exit:
        }
        return;
    case 305: // Character04 native 0x00613E1A: aerial capture into two-effect throw
        __asm {
            mov eax,[ebp-54h]
            movzx ecx,word ptr [eax+0Ah]
            test ecx,ecx
            jnz state305_00613E38
            mov edx,[ebp-54h]
            movzx eax,word ptr [edx+0Ch]
            test eax,eax
            jnz state305_00613E38
            mov ecx,[ebp-54h]
            call ResetFrame
        state305_00613E38:
            mov ecx,[ebp-54h]
            movzx edx,word ptr [ecx+0Ah]
            cmp edx,2h
            jnz state305_00613F25
            mov eax,[ebp-54h]
            movzx ecx,word ptr [eax+0Ch]
            test ecx,ecx
            jnz state305_00613F25
            mov edx,[ebp-54h]
            _emit 0DDh
            _emit 005h
            _emit 0F8h
            _emit 072h
            _emit 078h
            _emit 000h
            fstp qword ptr [edx+30h]
            mov eax,[ebp-54h]
            _emit 0DDh
            _emit 005h
            _emit 0F8h
            _emit 072h
            _emit 078h
            _emit 000h
            fstp qword ptr [eax+38h]
            mov ecx,[ebp-54h]
            _emit 0DDh
            _emit 005h
            _emit 0F8h
            _emit 072h
            _emit 078h
            _emit 000h
            fstp qword ptr [ecx+48h]
            mov edx,[ebp-54h]
            mov word ptr [edx+16Ch],1h
            mov eax,[ebp-54h]
            mov word ptr [eax+14Ch],78h
            mov ecx,[ebp-54h]
            movsx edx,word ptr [ecx+148h]
            sub edx,0BB8h
            mov eax,[ebp-54h]
            mov [eax+148h],dx
            push 3h
            push 0B0h
            mov ecx,[ebp-54h]
            call SetTint
            mov word ptr [ebp-4Ch],46h
            mov byte ptr [ebp-24h],40h
            mov ecx,[ebp-54h]
            fld qword ptr [ecx+20h]
            call _ftol2
            mov [ebp-278h],eax
            fild dword ptr [ebp-278h]
            fstp qword ptr [ebp-48h]
            mov edx,[ebp-54h]
            fld qword ptr [edx+28h]
            call _ftol2
            sub eax,28h
            mov [ebp-27Ch],eax
            fild dword ptr [ebp-27Ch]
            fstp qword ptr [ebp-40h]
            mov byte ptr [ebp-30h],2h
            mov dword ptr [ebp-50h],1h
            mov byte ptr [ebp-2Fh],1h
            lea eax,[ebp-50h]
            push eax
            mov ecx,[ebp-54h]
            mov ecx,[ecx+7Ch]
            call Context::EmitEffect
            mov edx,[ebp-54h]
            mov byte ptr [edx+2C9h],25h
        state305_00613F25:
            mov eax,[ebp-54h]
            movzx ecx,word ptr [eax+0Ah]
            cmp ecx,1h
            jng state305_00613F3E
            push 0Fh
            mov edx,[ebp-54h]
            mov ecx,[edx+7Ch]
            call Context::SetSceneTimer
        state305_00613F3E:
            mov eax,[ebp-54h]
            movzx ecx,word ptr [eax+0Ah]
            cmp ecx,2h
            jg state305_00613F56
            push 3h
            push 32h
            mov ecx,[ebp-54h]
            call SetHorizontalShake
        state305_00613F56:
            mov edx,[ebp-54h]
            movzx eax,word ptr [edx+0Ah]
            cmp eax,4h
            jnz state305_00613F77
            mov ecx,[ebp-54h]
            movzx edx,word ptr [ecx+0Ch]
            test edx,edx
            jnz state305_00613F77
            mov eax,[ebp-54h]
            mov byte ptr [eax+2C8h],0
        state305_00613F77:
            mov ecx,[ebp-54h]
            movzx edx,word ptr [ecx+0Ah]
            cmp edx,8h
            jnz state305_00613F9A
            mov eax,[ebp-54h]
            movzx ecx,word ptr [eax+0Ch]
            test ecx,ecx
            jnz state305_00613F9A
            mov edx,[ebp-54h]
            _emit 0DDh
            _emit 005h
            _emit 028h
            _emit 07Ch
            _emit 078h
            _emit 000h
            fstp qword ptr [edx+30h]
        state305_00613F9A:
            mov eax,[ebp-54h]
            movzx ecx,word ptr [eax+0Ah]
            cmp ecx,9h
            jnz state305_00613FC9
            mov edx,[ebp-54h]
            movzx eax,word ptr [edx+0Ch]
            test eax,eax
            jnz state305_00613FC9
            mov ecx,[ebp-54h]
            _emit 0DDh
            _emit 005h
            _emit 0A8h
            _emit 080h
            _emit 078h
            _emit 000h
            fstp qword ptr [ecx+30h]
            mov edx,[ebp-54h]
            _emit 0DDh
            _emit 005h
            _emit 0B0h
            _emit 085h
            _emit 078h
            _emit 000h
            fstp qword ptr [edx+40h]
        state305_00613FC9:
            mov eax,[ebp-54h]
            movzx ecx,word ptr [eax+0Ah]
            cmp ecx,8h
            jng state305_00614006
            mov edx,[ebp-54h]
            mov eax,[ebp-54h]
            fld qword ptr [edx+30h]
            fadd qword ptr [eax+40h]
            mov ecx,[ebp-54h]
            fstp qword ptr [ecx+30h]
            mov edx,[ebp-54h]
            fld qword ptr [edx+30h]
            _emit 0DCh
            _emit 01Dh
            _emit 0F8h
            _emit 072h
            _emit 078h
            _emit 000h
            fnstsw ax
            test ah,5h
            jpe state305_00614006
            mov eax,[ebp-54h]
            _emit 0DDh
            _emit 005h
            _emit 0F8h
            _emit 072h
            _emit 078h
            _emit 000h
            fstp qword ptr [eax+30h]
        state305_00614006:
            mov ecx,[ebp-54h]
            movzx edx,word ptr [ecx+0Ah]
            cmp edx,8h
            jnz state305_00614133
            mov eax,[ebp-54h]
            cmp dword ptr [eax+168h],2h
            jz state305_0061402E
            mov ecx,[ebp-54h]
            cmp dword ptr [ecx+168h],5h
            jnz state305_00614045
        state305_0061402E:
            mov edx,[ebp-54h]
            mov word ptr [edx+0Ch],0
            mov eax,[ebp-54h]
            mov word ptr [eax+0Ah],9h
            jmp state305_exit
        state305_00614045:
            mov ecx,[ebp-54h]
            cmp dword ptr [ecx+168h],3h
            jnz state305_00614133
            mov edx,[ebp-54h]
            mov eax,[edx+78h]
            mov ecx,[eax]
            mov word ptr [ecx+14Ah],270Fh
            mov edx,[ebp-54h]
            mov eax,[edx]
            mov ecx,[ebp-54h]
            call dword ptr [eax]
            mov ecx,[ebp-54h]
            mov edx,[ecx+78h]
            mov eax,[edx]
            mov ecx,[ebp-54h]
            mov edx,[ecx+78h]
            mov ecx,[edx]
            mov eax,[eax]
            call dword ptr [eax]
            mov ecx,[ebp-54h]
            mov edx,[ecx+78h]
            mov eax,[edx]
            _emit 0DDh
            _emit 005h
            _emit 0F8h
            _emit 072h
            _emit 078h
            _emit 000h
            fstp qword ptr [eax+28h]
            mov ecx,[ebp-54h]
            mov edx,[ecx+78h]
            mov eax,[edx]
            mov word ptr [eax+8h],6Ch
            mov ecx,[ebp-54h]
            mov word ptr [ecx+8h],134h
            mov word ptr [ebp-4Ch],1A3h
            _emit 0DDh
            _emit 005h
            _emit 0F8h
            _emit 072h
            _emit 078h
            _emit 000h
            fstp qword ptr [ebp-48h]
            _emit 0DDh
            _emit 005h
            _emit 010h
            _emit 07Ch
            _emit 078h
            _emit 000h
            fstp qword ptr [ebp-40h]
            mov byte ptr [ebp-30h],0
            mov dword ptr [ebp-50h],1h
            mov byte ptr [ebp-38h],1h
            mov byte ptr [ebp-2Fh],0
            mov dword ptr [ebp-20h],1h
            lea edx,[ebp-50h]
            push edx
            mov eax,[ebp-54h]
            mov edx,[eax]
            mov ecx,[ebp-54h]
            call dword ptr [edx+24h]
            mov word ptr [ebp-4Ch],1A4h
            _emit 0DDh
            _emit 005h
            _emit 0F8h
            _emit 072h
            _emit 078h
            _emit 000h
            fstp qword ptr [ebp-48h]
            _emit 0DDh
            _emit 005h
            _emit 030h
            _emit 085h
            _emit 078h
            _emit 000h
            fstp qword ptr [ebp-40h]
            mov byte ptr [ebp-30h],0
            mov dword ptr [ebp-50h],1h
            mov byte ptr [ebp-38h],1h
            mov byte ptr [ebp-2Fh],1h
            mov dword ptr [ebp-20h],1h
            lea eax,[ebp-50h]
            push eax
            mov ecx,[ebp-54h]
            mov edx,[ecx]
            mov ecx,[ebp-54h]
            call dword ptr [edx+24h]
            jmp state305_exit
        state305_00614133:
            mov eax,[ebp-54h]
            movzx ecx,word ptr [eax+0Ah]
            test ecx,ecx
            jng state305_00614156
            mov edx,[ebp-54h]
            movzx eax,word ptr [edx+0Ah]
            cmp eax,12h
            jnl state305_00614156
            push 3h
            push 32h
            mov ecx,[ebp-54h]
            call SetHorizontalShake
        state305_00614156:
            mov ecx,[ebp-54h]
            mov dx,[ecx+0Ch]
            add dx,1h
            mov eax,[ebp-54h]
            mov [eax+0Ch],dx
            mov ecx,[ebp-54h]
            movzx edx,word ptr [ecx+0Ch]
            movzx eax,word ptr [ebp-4h]
            cmp edx,eax
            jl state305_exit
            mov ecx,[ebp-54h]
            mov word ptr [ecx+0Ch],0
            mov edx,[ebp-54h]
            mov ax,[edx+0Ah]
            add ax,1h
            mov ecx,[ebp-54h]
            mov [ecx+0Ah],ax
            mov edx,[ebp-54h]
            mov dword ptr [edx+168h],0
            mov eax,[ebp-54h]
            movzx ecx,word ptr [eax+0Ah]
            movzx edx,word ptr [ebp-8h]
            cmp ecx,edx
            jl state305_exit
            mov eax,[ebp-54h]
            mov word ptr [eax+8h],0
            mov ecx,[ebp-54h]
            mov edx,[ecx]
            mov ecx,[ebp-54h]
            call dword ptr [edx]
        state305_exit:
        }
        return;
    case 306: // Character04 native 0x006141C6: multi-loop aerial throw with opponent reposition
        __asm {
            mov eax,[ebp-54h]
            movzx ecx,word ptr [eax+0Ah]
            test ecx,ecx
            jnz state306_0061421C
            mov edx,[ebp-54h]
            movzx eax,word ptr [edx+0Ch]
            test eax,eax
            jnz state306_0061421C
            mov ecx,[ebp-54h]
            _emit 0DDh
            _emit 005h
            _emit 0F0h
            _emit 072h
            _emit 078h
            _emit 000h
            fstp qword ptr [ecx+30h]
            mov edx,[ebp-54h]
            mov eax,[edx+78h]
            mov ecx,[eax]
            mov edx,[ebp-54h]
            movsx eax,byte ptr [edx+50h]
            imul eax,eax,1Eh
            mov [ebp-280h],eax
            fild dword ptr [ebp-280h]
            fadd qword ptr [ecx+20h]
            mov ecx,[ebp-54h]
            fstp qword ptr [ecx+20h]
            mov edx,[ebp-54h]
            mov dword ptr [edx+168h],0
        state306_0061421C:
            mov eax,[ebp-54h]
            movzx ecx,word ptr [eax+0Ah]
            cmp ecx,9h
            jnz state306_00614251
            mov edx,[ebp-54h]
            movzx eax,word ptr [edx+0Ch]
            test eax,eax
            jnz state306_00614251
            mov ecx,[ebp-54h]
            fld qword ptr [ecx+20h]
            _emit 0DCh
            _emit 005h
            _emit 0F8h
            _emit 072h
            _emit 078h
            _emit 000h
            mov edx,[ebp-54h]
            fstp qword ptr [edx+20h]
            mov eax,[ebp-54h]
            _emit 0DDh
            _emit 005h
            _emit 0F8h
            _emit 072h
            _emit 078h
            _emit 000h
            fstp qword ptr [eax+30h]
        state306_00614251:
            mov ecx,[ebp-54h]
            movzx edx,word ptr [ecx+0Ah]
            cmp edx,0Bh
            jnz state306_00614272
            mov eax,[ebp-54h]
            movzx ecx,word ptr [eax+0Ch]
            test ecx,ecx
            jnz state306_00614272
            mov edx,[ebp-54h]
            mov byte ptr [edx+2C9h],14h
        state306_00614272:
            mov eax,[ebp-54h]
            movzx ecx,word ptr [eax+0Ah]
            cmp ecx,0Fh
            jnz state306_00614293
            mov edx,[ebp-54h]
            movzx eax,word ptr [edx+0Ch]
            test eax,eax
            jnz state306_00614293
            mov ecx,[ebp-54h]
            mov byte ptr [ecx+2C8h],2h
        state306_00614293:
            mov edx,[ebp-54h]
            movzx eax,word ptr [edx+0Ah]
            cmp eax,0Fh
            jnz state306_00614363
            mov ecx,[ebp-54h]
            movzx edx,word ptr [ecx+0Ch]
            cmp edx,5Ah
            jnz state306_00614363
            mov eax,[ebp-54h]
            mov ecx,[eax+78h]
            mov edx,[ecx]
            mov word ptr [edx+8h],47h
            mov eax,[ebp-54h]
            mov ecx,[eax+78h]
            mov edx,[ecx]
            mov word ptr [edx+14Ah],0
            mov eax,[ebp-54h]
            mov ecx,[eax+78h]
            mov edx,[ecx]
            _emit 0DDh
            _emit 005h
            _emit 0F8h
            _emit 072h
            _emit 078h
            _emit 000h
            fstp qword ptr [edx+0C0h]
            mov eax,[ebp-54h]
            mov ecx,[eax+78h]
            mov edx,[ecx]
            _emit 0DDh
            _emit 005h
            _emit 058h
            _emit 07Dh
            _emit 078h
            _emit 000h
            fstp qword ptr [edx+0C8h]
            mov eax,[ebp-54h]
            mov dword ptr [eax+168h],2h
            _emit 0DDh
            _emit 005h
            _emit 048h
            _emit 08Bh
            _emit 078h
            _emit 000h
            sub esp,8h
            fstp qword ptr [esp]
            push 960h
            mov ecx,[ebp-54h]
            call ApplyDamage
            mov word ptr [ebp-4Ch],34h
            mov ecx,[ebp-54h]
            mov edx,[ecx+78h]
            mov eax,[edx]
            fld qword ptr [eax+20h]
            fstp qword ptr [ebp-48h]
            mov byte ptr [ebp-24h],16h
            mov ecx,[ebp-54h]
            mov edx,[ecx+78h]
            mov eax,[edx]
            fld qword ptr [eax+28h]
            _emit 0DCh
            _emit 025h
            _emit 0E0h
            _emit 07Ch
            _emit 078h
            _emit 000h
            fstp qword ptr [ebp-40h]
            mov byte ptr [ebp-30h],2h
            mov byte ptr [ebp-2Fh],1h
            lea ecx,[ebp-50h]
            push ecx
            mov edx,[ebp-54h]
            mov ecx,[edx+7Ch]
            call Context::EmitEffect
        state306_00614363:
            mov eax,[ebp-54h]
            movzx ecx,word ptr [eax+0Ah]
            test ecx,ecx
            jng state306_00614386
            mov edx,[ebp-54h]
            movzx eax,word ptr [edx+0Ah]
            cmp eax,0Fh
            jnl state306_00614386
            push 0Ah
            push 32h
            mov ecx,[ebp-54h]
            call SetHorizontalShake
        state306_00614386:
            mov ecx,[ebp-54h]
            mov dx,[ecx+0Ch]
            add dx,1h
            mov eax,[ebp-54h]
            mov [eax+0Ch],dx
            mov ecx,[ebp-54h]
            movzx edx,word ptr [ecx+0Ch]
            movzx eax,word ptr [ebp-4h]
            cmp edx,eax
            jl state306_exit
            mov ecx,[ebp-54h]
            mov word ptr [ecx+0Ch],0
            mov edx,[ebp-54h]
            mov ax,[edx+0Ah]
            add ax,1h
            mov ecx,[ebp-54h]
            mov [ecx+0Ah],ax
            mov edx,[ebp-54h]
            mov dword ptr [edx+168h],0
            mov eax,[ebp-54h]
            movzx ecx,word ptr [eax+0Ah]
            cmp ecx,6h
            jnz state306_00614411
            mov edx,[ebp-54h]
            cmp dword ptr [edx+3138h],9h
            jnl state306_00614411
            mov eax,[ebp-54h]
            movzx ecx,word ptr [eax+0Ah]
            sub ecx,2h
            mov edx,[ebp-54h]
            mov [edx+0Ah],cx
            mov eax,[ebp-54h]
            mov ecx,[eax+3138h]
            add ecx,1h
            mov edx,[ebp-54h]
            mov [edx+3138h],ecx
        state306_00614411:
            mov eax,[ebp-54h]
            movzx ecx,word ptr [eax+0Ah]
            cmp ecx,9h
            jnz state306_0061444C
            mov edx,[ebp-54h]
            movsx eax,byte ptr [edx+50h]
            imul eax,eax,50h
            mov [ebp-284h],eax
            fild dword ptr [ebp-284h]
            mov ecx,[ebp-54h]
            fadd qword ptr [ecx+20h]
            mov edx,[ebp-54h]
            fstp qword ptr [edx+20h]
            mov eax,[ebp-54h]
            mov dword ptr [eax+3138h],0
        state306_0061444C:
            mov ecx,[ebp-54h]
            movzx edx,word ptr [ecx+0Ah]
            cmp edx,0Dh
            jnz state306_0061448A
            mov eax,[ebp-54h]
            cmp dword ptr [eax+3138h],0Ch
            jnl state306_0061448A
            mov ecx,[ebp-54h]
            movzx edx,word ptr [ecx+0Ah]
            sub edx,2h
            mov eax,[ebp-54h]
            mov [eax+0Ah],dx
            mov ecx,[ebp-54h]
            mov edx,[ecx+3138h]
            add edx,1h
            mov eax,[ebp-54h]
            mov [eax+3138h],edx
        state306_0061448A:
            mov ecx,[ebp-54h]
            movzx edx,word ptr [ecx+0Ah]
            movzx eax,word ptr [ebp-8h]
            cmp edx,eax
            jl state306_exit
            mov ecx,[ebp-54h]
            mov word ptr [ecx+8h],0
            mov ecx,[ebp-54h]
            call FaceOpponent
            mov edx,[ebp-54h]
            mov eax,[edx]
            mov ecx,[ebp-54h]
            call dword ptr [eax]
        state306_exit:
        }
        return;
    case 307: // Character04 native 0x006144B9: looping multi-stage aerial throw variant
        __asm {
            mov ecx,[ebp-54h]
            movzx edx,word ptr [ecx+0Ah]
            test edx,edx
            jnz state307_0061451C
            mov eax,[ebp-54h]
            movzx ecx,word ptr [eax+0Ch]
            test ecx,ecx
            jnz state307_0061451C
            mov edx,[ebp-54h]
            mov dword ptr [edx+3138h],0
            mov eax,[ebp-54h]
            _emit 0DDh
            _emit 005h
            _emit 0F0h
            _emit 072h
            _emit 078h
            _emit 000h
            fstp qword ptr [eax+30h]
            mov ecx,[ebp-54h]
            mov edx,[ecx+78h]
            mov eax,[edx]
            mov ecx,[ebp-54h]
            movsx edx,byte ptr [ecx+50h]
            imul edx,edx,1Eh
            mov [ebp-288h],edx
            fild dword ptr [ebp-288h]
            fadd qword ptr [eax+20h]
            mov eax,[ebp-54h]
            fstp qword ptr [eax+20h]
            mov ecx,[ebp-54h]
            mov dword ptr [ecx+168h],0
        state307_0061451C:
            mov edx,[ebp-54h]
            movzx eax,word ptr [edx+0Ah]
            cmp eax,9h
            jnz state307_00614551
            mov ecx,[ebp-54h]
            movzx edx,word ptr [ecx+0Ch]
            test edx,edx
            jnz state307_00614551
            mov eax,[ebp-54h]
            fld qword ptr [eax+20h]
            _emit 0DCh
            _emit 005h
            _emit 0F8h
            _emit 072h
            _emit 078h
            _emit 000h
            mov ecx,[ebp-54h]
            fstp qword ptr [ecx+20h]
            mov edx,[ebp-54h]
            _emit 0DDh
            _emit 005h
            _emit 0F8h
            _emit 072h
            _emit 078h
            _emit 000h
            fstp qword ptr [edx+30h]
        state307_00614551:
            mov eax,[ebp-54h]
            movzx ecx,word ptr [eax+0Ah]
            cmp ecx,0Bh
            jnz state307_00614572
            mov edx,[ebp-54h]
            movzx eax,word ptr [edx+0Ch]
            test eax,eax
            jnz state307_00614572
            mov ecx,[ebp-54h]
            mov byte ptr [ecx+2C9h],14h
        state307_00614572:
            mov edx,[ebp-54h]
            movzx eax,word ptr [edx+0Ah]
            cmp eax,0Eh
            jnz state307_00614593
            mov ecx,[ebp-54h]
            movzx edx,word ptr [ecx+0Ch]
            test edx,edx
            jnz state307_00614593
            mov eax,[ebp-54h]
            mov byte ptr [eax+2C8h],2h
        state307_00614593:
            mov ecx,[ebp-54h]
            movzx edx,word ptr [ecx+0Ah]
            cmp edx,0Fh
            jnz state307_00614672
            mov eax,[ebp-54h]
            movzx ecx,word ptr [eax+0Ch]
            test ecx,ecx
            jnz state307_00614672
            mov edx,[ebp-54h]
            cmp dword ptr [edx+3138h],7h
            jnz state307_00614672
            mov eax,[ebp-54h]
            mov ecx,[eax+78h]
            mov edx,[ecx]
            mov word ptr [edx+8h],47h
            mov eax,[ebp-54h]
            mov ecx,[eax+78h]
            mov edx,[ecx]
            mov word ptr [edx+14Ah],0
            mov eax,[ebp-54h]
            mov ecx,[eax+78h]
            mov edx,[ecx]
            _emit 0DDh
            _emit 005h
            _emit 0F8h
            _emit 072h
            _emit 078h
            _emit 000h
            fstp qword ptr [edx+0C0h]
            mov eax,[ebp-54h]
            mov ecx,[eax+78h]
            mov edx,[ecx]
            _emit 0DDh
            _emit 005h
            _emit 058h
            _emit 07Dh
            _emit 078h
            _emit 000h
            fstp qword ptr [edx+0C8h]
            mov eax,[ebp-54h]
            mov dword ptr [eax+168h],2h
            _emit 0DDh
            _emit 005h
            _emit 048h
            _emit 08Bh
            _emit 078h
            _emit 000h
            sub esp,8h
            fstp qword ptr [esp]
            push 0C80h
            mov ecx,[ebp-54h]
            call ApplyDamage
            mov word ptr [ebp-4Ch],34h
            mov ecx,[ebp-54h]
            mov edx,[ecx+78h]
            mov eax,[edx]
            fld qword ptr [eax+20h]
            fstp qword ptr [ebp-48h]
            mov byte ptr [ebp-24h],16h
            mov ecx,[ebp-54h]
            mov edx,[ecx+78h]
            mov eax,[edx]
            fld qword ptr [eax+28h]
            _emit 0DCh
            _emit 025h
            _emit 0E0h
            _emit 07Ch
            _emit 078h
            _emit 000h
            fstp qword ptr [ebp-40h]
            mov byte ptr [ebp-30h],2h
            mov byte ptr [ebp-2Fh],1h
            lea ecx,[ebp-50h]
            push ecx
            mov edx,[ebp-54h]
            mov ecx,[edx+7Ch]
            call Context::EmitEffect
        state307_00614672:
            mov eax,[ebp-54h]
            movzx ecx,word ptr [eax+0Ah]
            test ecx,ecx
            jng state307_00614695
            mov edx,[ebp-54h]
            movzx eax,word ptr [edx+0Ah]
            cmp eax,0Fh
            jnl state307_00614695
            push 0Ah
            push 32h
            mov ecx,[ebp-54h]
            call SetHorizontalShake
        state307_00614695:
            mov ecx,[ebp-54h]
            mov dx,[ecx+0Ch]
            add dx,1h
            mov eax,[ebp-54h]
            mov [eax+0Ch],dx
            mov ecx,[ebp-54h]
            movzx edx,word ptr [ecx+0Ch]
            movzx eax,word ptr [ebp-4h]
            cmp edx,eax
            jl state307_006147A2
            mov ecx,[ebp-54h]
            mov word ptr [ecx+0Ch],0
            mov edx,[ebp-54h]
            mov ax,[edx+0Ah]
            add ax,1h
            mov ecx,[ebp-54h]
            mov [ecx+0Ah],ax
            mov edx,[ebp-54h]
            mov dword ptr [edx+168h],0
            mov eax,[ebp-54h]
            movzx ecx,word ptr [eax+0Ah]
            cmp ecx,6h
            jnz state307_00614718
            mov edx,[ebp-54h]
            cmp dword ptr [edx+3138h],9h
            jnl state307_00614718
            mov eax,[ebp-54h]
            mov word ptr [eax+0Ah],4h
            mov ecx,[ebp-54h]
            mov edx,[ecx+3138h]
            add edx,1h
            mov eax,[ebp-54h]
            mov [eax+3138h],edx
        state307_00614718:
            mov ecx,[ebp-54h]
            movzx edx,word ptr [ecx+0Ah]
            cmp edx,9h
            jnz state307_00614753
            mov eax,[ebp-54h]
            movsx ecx,byte ptr [eax+50h]
            imul ecx,ecx,50h
            mov [ebp-28Ch],ecx
            fild dword ptr [ebp-28Ch]
            mov edx,[ebp-54h]
            fadd qword ptr [edx+20h]
            mov eax,[ebp-54h]
            fstp qword ptr [eax+20h]
            mov ecx,[ebp-54h]
            mov dword ptr [ecx+3138h],0
        state307_00614753:
            mov edx,[ebp-54h]
            movzx eax,word ptr [edx+0Ah]
            cmp eax,0Dh
            jnz state307_00614789
            mov ecx,[ebp-54h]
            cmp dword ptr [ecx+3138h],0Ch
            jnl state307_00614789
            mov edx,[ebp-54h]
            mov word ptr [edx+0Ah],0Bh
            mov eax,[ebp-54h]
            mov ecx,[eax+3138h]
            add ecx,1h
            mov edx,[ebp-54h]
            mov [edx+3138h],ecx
        state307_00614789:
            mov eax,[ebp-54h]
            movzx ecx,word ptr [eax+0Ah]
            cmp ecx,0Eh
            jnz state307_006147A2
            mov edx,[ebp-54h]
            mov dword ptr [edx+3138h],0Ch
        state307_006147A2:
            mov eax,[ebp-54h]
            movzx ecx,word ptr [eax+0Ah]
            movzx edx,word ptr [ebp-8h]
            cmp ecx,edx
            jl state307_exit
            mov eax,[ebp-54h]
            cmp dword ptr [eax+3138h],0
            jng state307_006147E5
            mov ecx,[ebp-54h]
            movzx edx,word ptr [ecx+0Ah]
            sub edx,2h
            mov eax,[ebp-54h]
            mov [eax+0Ah],dx
            mov ecx,[ebp-54h]
            mov edx,[ecx+3138h]
            sub edx,1h
            mov eax,[ebp-54h]
            mov [eax+3138h],edx
            jmp state307_exit
        state307_006147E5:
            mov ecx,[ebp-54h]
            mov word ptr [ecx+8h],0
            mov edx,[ebp-54h]
            mov eax,[edx]
            mov ecx,[ebp-54h]
            call dword ptr [eax]
        state307_exit:
        }
        return;
    case 308: // Character04 native 0x006147FD: scaled-damage multi-loop aerial throw
        __asm {
            mov ecx,[ebp-54h]
            movzx edx,word ptr [ecx+0Ah]
            test edx,edx
            jnz state308_00614860
            mov eax,[ebp-54h]
            movzx ecx,word ptr [eax+0Ch]
            test ecx,ecx
            jnz state308_00614860
            mov edx,[ebp-54h]
            mov dword ptr [edx+3138h],0
            mov eax,[ebp-54h]
            _emit 0DDh
            _emit 005h
            _emit 0F0h
            _emit 072h
            _emit 078h
            _emit 000h
            fstp qword ptr [eax+30h]
            mov ecx,[ebp-54h]
            mov edx,[ecx+78h]
            mov eax,[edx]
            mov ecx,[ebp-54h]
            movsx edx,byte ptr [ecx+50h]
            imul edx,edx,1Eh
            mov [ebp-290h],edx
            fild dword ptr [ebp-290h]
            fadd qword ptr [eax+20h]
            mov eax,[ebp-54h]
            fstp qword ptr [eax+20h]
            mov ecx,[ebp-54h]
            mov dword ptr [ecx+168h],0
        state308_00614860:
            mov edx,[ebp-54h]
            movzx eax,word ptr [edx+0Ah]
            cmp eax,9h
            jnz state308_00614895
            mov ecx,[ebp-54h]
            movzx edx,word ptr [ecx+0Ch]
            test edx,edx
            jnz state308_00614895
            mov eax,[ebp-54h]
            fld qword ptr [eax+20h]
            _emit 0DCh
            _emit 005h
            _emit 0F8h
            _emit 072h
            _emit 078h
            _emit 000h
            mov ecx,[ebp-54h]
            fstp qword ptr [ecx+20h]
            mov edx,[ebp-54h]
            _emit 0DDh
            _emit 005h
            _emit 0F8h
            _emit 072h
            _emit 078h
            _emit 000h
            fstp qword ptr [edx+30h]
        state308_00614895:
            mov eax,[ebp-54h]
            movzx ecx,word ptr [eax+0Ah]
            cmp ecx,0Bh
            jnz state308_006148B6
            mov edx,[ebp-54h]
            movzx eax,word ptr [edx+0Ch]
            test eax,eax
            jnz state308_006148B6
            mov ecx,[ebp-54h]
            mov byte ptr [ecx+2C9h],14h
        state308_006148B6:
            mov edx,[ebp-54h]
            movzx eax,word ptr [edx+0Ah]
            cmp eax,0Eh
            jnz state308_006148D7
            mov ecx,[ebp-54h]
            movzx edx,word ptr [ecx+0Ch]
            test edx,edx
            jnz state308_006148D7
            mov eax,[ebp-54h]
            mov byte ptr [eax+2C8h],2h
        state308_006148D7:
            mov ecx,[ebp-54h]
            movzx edx,word ptr [ecx+0Ah]
            cmp edx,0Fh
            jnz state308_006149DF
            mov eax,[ebp-54h]
            movzx ecx,word ptr [eax+0Ch]
            test ecx,ecx
            jnz state308_006149DF
            mov edx,[ebp-54h]
            cmp dword ptr [edx+3138h],7h
            jnz state308_006149DF
            mov eax,[ebp-54h]
            mov ecx,[eax+78h]
            mov edx,[ecx]
            mov word ptr [edx+8h],47h
            mov eax,[ebp-54h]
            mov ecx,[eax+78h]
            mov edx,[ecx]
            mov word ptr [edx+14Ah],0
            mov eax,[ebp-54h]
            mov ecx,[eax+78h]
            mov edx,[ecx]
            _emit 0DDh
            _emit 005h
            _emit 0F8h
            _emit 072h
            _emit 078h
            _emit 000h
            fstp qword ptr [edx+0C0h]
            mov eax,[ebp-54h]
            mov ecx,[eax+78h]
            mov edx,[ecx]
            _emit 0DDh
            _emit 005h
            _emit 058h
            _emit 07Dh
            _emit 078h
            _emit 000h
            fstp qword ptr [edx+0C8h]
            mov eax,[ebp-54h]
            mov dword ptr [eax+168h],2h
            _emit 0DDh
            _emit 005h
            _emit 048h
            _emit 08Bh
            _emit 078h
            _emit 000h
            sub esp,8h
            fstp qword ptr [esp]
            push 1194h
            mov ecx,[ebp-54h]
            call ApplyDamage
            // Project comboDamageScale (owner+0x178) onto opponent+0x124:
            // native integer conversion of 200.0 * scale / 10000.0.
            mov ecx,[ebp-54h]
            _emit 0DDh
            _emit 005h
            _emit 070h
            _emit 07Eh
            _emit 078h
            _emit 000h
            fmul qword ptr [ecx+178h]
            _emit 0DCh
            _emit 035h
            _emit 000h
            _emit 07Ch
            _emit 078h
            _emit 000h
            call _ftol2
            mov edx,[ebp-54h]
            mov ecx,[edx+78h]
            mov edx,[ecx]
            mov [edx+124h],ax
            mov word ptr [ebp-4Ch],34h
            mov eax,[ebp-54h]
            mov ecx,[eax+78h]
            mov edx,[ecx]
            fld qword ptr [edx+20h]
            fstp qword ptr [ebp-48h]
            mov byte ptr [ebp-24h],16h
            mov eax,[ebp-54h]
            mov ecx,[eax+78h]
            mov edx,[ecx]
            fld qword ptr [edx+28h]
            _emit 0DCh
            _emit 025h
            _emit 0E0h
            _emit 07Ch
            _emit 078h
            _emit 000h
            fstp qword ptr [ebp-40h]
            mov byte ptr [ebp-30h],2h
            mov byte ptr [ebp-2Fh],1h
            lea eax,[ebp-50h]
            push eax
            mov ecx,[ebp-54h]
            mov ecx,[ecx+7Ch]
            call Context::EmitEffect
        state308_006149DF:
            mov edx,[ebp-54h]
            movzx eax,word ptr [edx+0Ah]
            test eax,eax
            jng state308_00614A02
            mov ecx,[ebp-54h]
            movzx edx,word ptr [ecx+0Ah]
            cmp edx,0Fh
            jnl state308_00614A02
            push 0Ah
            push 32h
            mov ecx,[ebp-54h]
            call SetHorizontalShake
        state308_00614A02:
            mov eax,[ebp-54h]
            mov cx,[eax+0Ch]
            add cx,1h
            mov edx,[ebp-54h]
            mov [edx+0Ch],cx
            mov eax,[ebp-54h]
            movzx ecx,word ptr [eax+0Ch]
            movzx edx,word ptr [ebp-4h]
            cmp ecx,edx
            jl state308_00614B0F
            mov eax,[ebp-54h]
            mov word ptr [eax+0Ch],0
            mov ecx,[ebp-54h]
            mov dx,[ecx+0Ah]
            add dx,1h
            mov eax,[ebp-54h]
            mov [eax+0Ah],dx
            mov ecx,[ebp-54h]
            mov dword ptr [ecx+168h],0
            mov edx,[ebp-54h]
            movzx eax,word ptr [edx+0Ah]
            cmp eax,6h
            jnz state308_00614A85
            mov ecx,[ebp-54h]
            cmp dword ptr [ecx+3138h],9h
            jnl state308_00614A85
            mov edx,[ebp-54h]
            mov word ptr [edx+0Ah],4h
            mov eax,[ebp-54h]
            mov ecx,[eax+3138h]
            add ecx,1h
            mov edx,[ebp-54h]
            mov [edx+3138h],ecx
        state308_00614A85:
            mov eax,[ebp-54h]
            movzx ecx,word ptr [eax+0Ah]
            cmp ecx,9h
            jnz state308_00614AC0
            mov edx,[ebp-54h]
            movsx eax,byte ptr [edx+50h]
            imul eax,eax,50h
            mov [ebp-294h],eax
            fild dword ptr [ebp-294h]
            mov ecx,[ebp-54h]
            fadd qword ptr [ecx+20h]
            mov edx,[ebp-54h]
            fstp qword ptr [edx+20h]
            mov eax,[ebp-54h]
            mov dword ptr [eax+3138h],0
        state308_00614AC0:
            mov ecx,[ebp-54h]
            movzx edx,word ptr [ecx+0Ah]
            cmp edx,0Dh
            jnz state308_00614AF6
            mov eax,[ebp-54h]
            cmp dword ptr [eax+3138h],0Ch
            jnl state308_00614AF6
            mov ecx,[ebp-54h]
            mov word ptr [ecx+0Ah],0Bh
            mov edx,[ebp-54h]
            mov eax,[edx+3138h]
            add eax,1h
            mov ecx,[ebp-54h]
            mov [ecx+3138h],eax
        state308_00614AF6:
            mov edx,[ebp-54h]
            movzx eax,word ptr [edx+0Ah]
            cmp eax,0Eh
            jnz state308_00614B0F
            mov ecx,[ebp-54h]
            mov dword ptr [ecx+3138h],0Ch
        state308_00614B0F:
            mov edx,[ebp-54h]
            movzx eax,word ptr [edx+0Ah]
            movzx ecx,word ptr [ebp-8h]
            cmp eax,ecx
            jl state308_exit
            mov edx,[ebp-54h]
            cmp dword ptr [edx+3138h],0
            jng state308_00614B52
            mov eax,[ebp-54h]
            movzx ecx,word ptr [eax+0Ah]
            sub ecx,2h
            mov edx,[ebp-54h]
            mov [edx+0Ah],cx
            mov eax,[ebp-54h]
            mov ecx,[eax+3138h]
            sub ecx,1h
            mov edx,[ebp-54h]
            mov [edx+3138h],ecx
            jmp state308_exit
        state308_00614B52:
            mov eax,[ebp-54h]
            mov word ptr [eax+8h],0
            mov ecx,[ebp-54h]
            mov edx,[ecx]
            mov ecx,[ebp-54h]
            call dword ptr [edx]
        state308_exit:
        }
        return;
    case 309: // Character04 native 0x00614B6A: triple-effect capture with looping hitstun
        // Frame 0 launches global effects 0x46/0x47 at (X,Y-40), then local
        // effect 0x1AB at (X+facing*20,0). Frame 6 revisits frame 2 while
        // the 120-frame capture timer remains positive; preserve field3138
        // as the native loop counter rather than collapsing this into a timer.
        __asm {
            push 3h
            push 32h
            mov ecx,[ebp-54h]
            call SetHorizontalShake
            mov eax,[ebp-54h]
            movzx ecx,word ptr [eax+0Ah]
            test ecx,ecx
            jnz state309_00614CBC
            mov edx,[ebp-54h]
            movzx eax,word ptr [edx+0Ch]
            test eax,eax
            jnz state309_00614CBC
            mov ecx,[ebp-54h]
            mov byte ptr [ecx+2C8h],3h
            mov ecx,[ebp-54h]
            call ResetFrame
            mov edx,[ebp-54h]
            mov word ptr [edx+14Ch],78h
            mov eax,[ebp-54h]
            movsx ecx,word ptr [eax+148h]
            sub ecx,0BB8h
            mov edx,[ebp-54h]
            mov [edx+148h],cx
            push 3h
            push 0B0h
            mov ecx,[ebp-54h]
            call SetTint
            mov word ptr [ebp-4Ch],46h
            mov byte ptr [ebp-24h],40h
            mov eax,[ebp-54h]
            fld qword ptr [eax+20h]
            call _ftol2
            mov [ebp-298h],eax
            fild dword ptr [ebp-298h]
            fstp qword ptr [ebp-48h]
            mov ecx,[ebp-54h]
            fld qword ptr [ecx+28h]
            call _ftol2
            sub eax,28h
            mov [ebp-29Ch],eax
            fild dword ptr [ebp-29Ch]
            fstp qword ptr [ebp-40h]
            mov byte ptr [ebp-30h],2h
            mov dword ptr [ebp-50h],1h
            mov byte ptr [ebp-2Fh],1h
            lea edx,[ebp-50h]
            push edx
            mov eax,[ebp-54h]
            mov ecx,[eax+7Ch]
            call Context::EmitEffect
            mov word ptr [ebp-4Ch],47h
            lea ecx,[ebp-50h]
            push ecx
            mov edx,[ebp-54h]
            mov ecx,[edx+7Ch]
            call Context::EmitEffect
            mov eax,[ebp-54h]
            mov byte ptr [eax+2C9h],25h
            mov word ptr [ebp-4Ch],1ABh
            mov ecx,[ebp-54h]
            fld qword ptr [ecx+20h]
            call _ftol2
            mov edx,[ebp-54h]
            movsx ecx,byte ptr [edx+50h]
            imul ecx,ecx,14h
            add eax,ecx
            mov [ebp-2A0h],eax
            fild dword ptr [ebp-2A0h]
            fstp qword ptr [ebp-48h]
            _emit 0DDh
            _emit 005h
            _emit 0F8h
            _emit 072h
            _emit 078h
            _emit 000h
            fstp qword ptr [ebp-40h]
            mov dword ptr [ebp-20h],1h
            mov edx,[ebp-54h]
            mov al,[edx+50h]
            mov [ebp-38h],al
            mov byte ptr [ebp-30h],2h
            mov dword ptr [ebp-50h],1h
            mov byte ptr [ebp-2Fh],1h
            lea ecx,[ebp-50h]
            push ecx
            mov edx,[ebp-54h]
            mov eax,[edx]
            mov ecx,[ebp-54h]
            call dword ptr [eax+24h]
        state309_00614CBC:
            mov ecx,[ebp-54h]
            mov dx,[ecx+0Ch]
            add dx,1h
            mov eax,[ebp-54h]
            mov [eax+0Ch],dx
            mov ecx,[ebp-54h]
            movzx edx,word ptr [ecx+0Ch]
            movzx eax,word ptr [ebp-4h]
            cmp edx,eax
            jl state309_exit
            mov ecx,[ebp-54h]
            mov word ptr [ecx+0Ch],0
            mov edx,[ebp-54h]
            mov ax,[edx+0Ah]
            add ax,1h
            mov ecx,[ebp-54h]
            mov [ecx+0Ah],ax
            mov edx,[ebp-54h]
            mov dword ptr [edx+168h],0
            mov eax,[ebp-54h]
            movzx ecx,word ptr [eax+0Ah]
            cmp ecx,6h
            jnz state309_00614D49
            mov edx,[ebp-54h]
            movsx eax,word ptr [edx+14Ch]
            test eax,eax
            jng state309_00614D49
            mov ecx,[ebp-54h]
            movzx edx,word ptr [ecx+0Ah]
            sub edx,4h
            mov eax,[ebp-54h]
            mov [eax+0Ah],dx
            mov ecx,[ebp-54h]
            mov edx,[ecx+3138h]
            add edx,1h
            mov eax,[ebp-54h]
            mov [eax+3138h],edx
        state309_00614D49:
            mov ecx,[ebp-54h]
            movzx edx,word ptr [ecx+0Ah]
            movzx eax,word ptr [ebp-8h]
            cmp edx,eax
            jl state309_exit
            mov ecx,[ebp-54h]
            mov word ptr [ecx+8h],0
            mov edx,[ebp-54h]
            mov eax,[edx]
            mov ecx,[ebp-54h]
            call dword ptr [eax]
        state309_exit:
        }
        return;
    case 312: // Character04 native 0x00614D70: scaled-damage looping aerial throw variant
        // This sibling of states 307/308 keeps their field3138 frame loops,
        // but launches with -8 vertical opponent velocity, deals 4200/750,
        // and writes ftol2(200*comboDamageScale/10000) to opponent+0x124.
        __asm {
            mov ecx,[ebp-54h]
            movzx edx,word ptr [ecx+0Ah]
            test edx,edx
            jnz state312_00614DC6
            mov eax,[ebp-54h]
            movzx ecx,word ptr [eax+0Ch]
            test ecx,ecx
            jnz state312_00614DC6
            mov edx,[ebp-54h]
            mov dword ptr [edx+3138h],0
            mov eax,[ebp-54h]
            _emit 0DDh
            _emit 005h
            _emit 0F0h
            _emit 072h
            _emit 078h
            _emit 000h
            fstp qword ptr [eax+30h]
            mov ecx,[ebp-54h]
            mov edx,[ecx+78h]
            mov eax,[edx]
            mov ecx,[ebp-54h]
            movsx edx,byte ptr [ecx+50h]
            imul edx,edx,1Eh
            mov [ebp-2A4h],edx
            fild dword ptr [ebp-2A4h]
            fadd qword ptr [eax+20h]
            mov eax,[ebp-54h]
            fstp qword ptr [eax+20h]
        state312_00614DC6:
            mov ecx,[ebp-54h]
            movzx edx,word ptr [ecx+0Ah]
            cmp edx,9h
            jnz state312_00614DFB
            mov eax,[ebp-54h]
            movzx ecx,word ptr [eax+0Ch]
            test ecx,ecx
            jnz state312_00614DFB
            mov edx,[ebp-54h]
            fld qword ptr [edx+20h]
            _emit 0DCh
            _emit 005h
            _emit 0F8h
            _emit 072h
            _emit 078h
            _emit 000h
            mov eax,[ebp-54h]
            fstp qword ptr [eax+20h]
            mov ecx,[ebp-54h]
            _emit 0DDh
            _emit 005h
            _emit 0F8h
            _emit 072h
            _emit 078h
            _emit 000h
            fstp qword ptr [ecx+30h]
        state312_00614DFB:
            mov edx,[ebp-54h]
            movzx eax,word ptr [edx+0Ah]
            cmp eax,0Bh
            jnz state312_00614E1C
            mov ecx,[ebp-54h]
            movzx edx,word ptr [ecx+0Ch]
            test edx,edx
            jnz state312_00614E1C
            mov eax,[ebp-54h]
            mov byte ptr [eax+2C9h],14h
        state312_00614E1C:
            mov ecx,[ebp-54h]
            movzx edx,word ptr [ecx+0Ah]
            cmp edx,0Eh
            jnz state312_00614E3D
            mov eax,[ebp-54h]
            movzx ecx,word ptr [eax+0Ch]
            test ecx,ecx
            jnz state312_00614E3D
            mov edx,[ebp-54h]
            mov byte ptr [edx+2C8h],2h
        state312_00614E3D:
            mov eax,[ebp-54h]
            movzx ecx,word ptr [eax+0Ah]
            cmp ecx,0Fh
            jnz state312_00614F38
            mov edx,[ebp-54h]
            movzx eax,word ptr [edx+0Ch]
            test eax,eax
            jnz state312_00614F38
            mov ecx,[ebp-54h]
            cmp dword ptr [ecx+3138h],7h
            jnz state312_00614F38
            mov edx,[ebp-54h]
            mov eax,[edx+78h]
            mov ecx,[eax]
            mov word ptr [ecx+8h],47h
            mov edx,[ebp-54h]
            mov eax,[edx+78h]
            mov ecx,[eax]
            mov word ptr [ecx+14Ah],0
            mov edx,[ebp-54h]
            mov eax,[edx+78h]
            mov ecx,[eax]
            _emit 0DDh
            _emit 005h
            _emit 0F8h
            _emit 072h
            _emit 078h
            _emit 000h
            fstp qword ptr [ecx+0C0h]
            mov edx,[ebp-54h]
            mov eax,[edx+78h]
            mov ecx,[eax]
            _emit 0DDh
            _emit 005h
            _emit 0B0h
            _emit 089h
            _emit 078h
            _emit 000h
            fstp qword ptr [ecx+0C8h]
            _emit 0DDh
            _emit 005h
            _emit 080h
            _emit 07Ch
            _emit 078h
            _emit 000h
            sub esp,8h
            fstp qword ptr [esp]
            push 1068h
            mov ecx,[ebp-54h]
            call ApplyDamage
            mov edx,[ebp-54h]
            _emit 0DDh
            _emit 005h
            _emit 070h
            _emit 07Eh
            _emit 078h
            _emit 000h
            fmul qword ptr [edx+178h]
            _emit 0DCh
            _emit 035h
            _emit 000h
            _emit 07Ch
            _emit 078h
            _emit 000h
            call _ftol2
            mov ecx,[ebp-54h]
            mov edx,[ecx+78h]
            mov ecx,[edx]
            mov [ecx+124h],ax
            mov word ptr [ebp-4Ch],34h
            mov edx,[ebp-54h]
            mov eax,[edx+78h]
            mov ecx,[eax]
            fld qword ptr [ecx+20h]
            fstp qword ptr [ebp-48h]
            mov byte ptr [ebp-24h],16h
            mov edx,[ebp-54h]
            mov eax,[edx+78h]
            mov ecx,[eax]
            fld qword ptr [ecx+28h]
            _emit 0DCh
            _emit 025h
            _emit 0E0h
            _emit 07Ch
            _emit 078h
            _emit 000h
            fstp qword ptr [ebp-40h]
            mov byte ptr [ebp-30h],2h
            mov byte ptr [ebp-2Fh],1h
            lea edx,[ebp-50h]
            push edx
            mov eax,[ebp-54h]
            mov ecx,[eax+7Ch]
            call Context::EmitEffect
        state312_00614F38:
            mov ecx,[ebp-54h]
            movzx edx,word ptr [ecx+0Ah]
            test edx,edx
            jng state312_00614F5B
            mov eax,[ebp-54h]
            movzx ecx,word ptr [eax+0Ah]
            cmp ecx,0Fh
            jnl state312_00614F5B
            push 0Ah
            push 32h
            mov ecx,[ebp-54h]
            call SetHorizontalShake
        state312_00614F5B:
            mov edx,[ebp-54h]
            mov ax,[edx+0Ch]
            add ax,1h
            mov ecx,[ebp-54h]
            mov [ecx+0Ch],ax
            mov edx,[ebp-54h]
            movzx eax,word ptr [edx+0Ch]
            movzx ecx,word ptr [ebp-4h]
            cmp eax,ecx
            jl state312_00615068
            mov edx,[ebp-54h]
            mov word ptr [edx+0Ch],0
            mov eax,[ebp-54h]
            mov cx,[eax+0Ah]
            add cx,1h
            mov edx,[ebp-54h]
            mov [edx+0Ah],cx
            mov eax,[ebp-54h]
            mov dword ptr [eax+168h],0
            mov ecx,[ebp-54h]
            movzx edx,word ptr [ecx+0Ah]
            cmp edx,6h
            jnz state312_00614FDE
            mov eax,[ebp-54h]
            cmp dword ptr [eax+3138h],9h
            jnl state312_00614FDE
            mov ecx,[ebp-54h]
            mov word ptr [ecx+0Ah],4h
            mov edx,[ebp-54h]
            mov eax,[edx+3138h]
            add eax,1h
            mov ecx,[ebp-54h]
            mov [ecx+3138h],eax
        state312_00614FDE:
            mov edx,[ebp-54h]
            movzx eax,word ptr [edx+0Ah]
            cmp eax,9h
            jnz state312_00615019
            mov ecx,[ebp-54h]
            movsx edx,byte ptr [ecx+50h]
            imul edx,edx,50h
            mov [ebp-2A8h],edx
            fild dword ptr [ebp-2A8h]
            mov eax,[ebp-54h]
            fadd qword ptr [eax+20h]
            mov ecx,[ebp-54h]
            fstp qword ptr [ecx+20h]
            mov edx,[ebp-54h]
            mov dword ptr [edx+3138h],0
        state312_00615019:
            mov eax,[ebp-54h]
            movzx ecx,word ptr [eax+0Ah]
            cmp ecx,0Dh
            jnz state312_0061504F
            mov edx,[ebp-54h]
            cmp dword ptr [edx+3138h],0Ch
            jnl state312_0061504F
            mov eax,[ebp-54h]
            mov word ptr [eax+0Ah],0Bh
            mov ecx,[ebp-54h]
            mov edx,[ecx+3138h]
            add edx,1h
            mov eax,[ebp-54h]
            mov [eax+3138h],edx
        state312_0061504F:
            mov ecx,[ebp-54h]
            movzx edx,word ptr [ecx+0Ah]
            cmp edx,0Eh
            jnz state312_00615068
            mov eax,[ebp-54h]
            mov dword ptr [eax+3138h],0Ch
        state312_00615068:
            mov ecx,[ebp-54h]
            movzx edx,word ptr [ecx+0Ah]
            movzx eax,word ptr [ebp-8h]
            cmp edx,eax
            jl state312_exit
            mov ecx,[ebp-54h]
            cmp dword ptr [ecx+3138h],0
            jng state312_006150AB
            mov edx,[ebp-54h]
            movzx eax,word ptr [edx+0Ah]
            sub eax,2h
            mov ecx,[ebp-54h]
            mov [ecx+0Ah],ax
            mov edx,[ebp-54h]
            mov eax,[edx+3138h]
            sub eax,1h
            mov ecx,[ebp-54h]
            mov [ecx+3138h],eax
            jmp state312_exit
        state312_006150AB:
            mov edx,[ebp-54h]
            mov word ptr [edx+8h],0
            mov eax,[ebp-54h]
            mov edx,[eax]
            mov ecx,[ebp-54h]
            call dword ptr [edx]
        state312_exit:
        }
        return;
    case 315: // Character04 native 0x006150C3: zero-velocity hitstun recovery
        __asm {
            mov eax,[ebp-54h]
            movzx ecx,word ptr [eax+0Ah]
            test ecx,ecx
            jnz state315_006150F1
            mov edx,[ebp-54h]
            movzx eax,word ptr [edx+0Ch]
            test eax,eax
            jnz state315_006150F1
            mov ecx,[ebp-54h]
            _emit 0DDh
            _emit 005h
            _emit 0F8h
            _emit 072h
            _emit 078h
            _emit 000h
            fstp qword ptr [ecx+30h]
            mov edx,[ebp-54h]
            _emit 0DDh
            _emit 005h
            _emit 0F8h
            _emit 072h
            _emit 078h
            _emit 000h
            fstp qword ptr [edx+38h]
        state315_006150F1:
            mov eax,[ebp-54h]
            movzx ecx,word ptr [eax+0Ah]
            cmp ecx,1h
            jnz state315_00615115
            mov edx,[ebp-54h]
            movzx eax,word ptr [edx+0Ch]
            test eax,eax
            jnz state315_00615115
            mov ecx,[ebp-54h]
            mov dword ptr [ecx+3148h],0
        state315_00615115:
            mov edx,[ebp-54h]
            mov ax,[edx+0Ch]
            add ax,1h
            mov ecx,[ebp-54h]
            mov [ecx+0Ch],ax
            mov edx,[ebp-54h]
            movzx eax,word ptr [edx+0Ch]
            movzx ecx,word ptr [ebp-4h]
            cmp eax,ecx
            jl state315_exit
            mov edx,[ebp-54h]
            mov word ptr [edx+0Ch],0
            mov eax,[ebp-54h]
            mov cx,[eax+0Ah]
            add cx,1h
            mov edx,[ebp-54h]
            mov [edx+0Ah],cx
            mov eax,[ebp-54h]
            mov dword ptr [eax+168h],0
            mov ecx,[ebp-54h]
            movzx edx,word ptr [ecx+0Ah]
            movzx eax,word ptr [ebp-8h]
            cmp edx,eax
            jl state315_exit
            mov ecx,[ebp-54h]
            cmp dword ptr [ecx+3144h],1h
            jnz state315_00615187
            mov edx,[ebp-54h]
            mov word ptr [edx+0Ah],0
            jmp near ptr state315_exit
        state315_00615187:
            mov eax,[ebp-54h]
            mov word ptr [eax+8h],0
            mov ecx,[ebp-54h]
            mov edx,[ecx]
            mov ecx,[ebp-54h]
            call dword ptr [edx]
        state315_exit:
        }
        return;

    }
}
