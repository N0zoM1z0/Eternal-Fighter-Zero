// Kano Character20::Slot06: workbench reconstruction of full-size native boss.
// Only explicitly reviewed cases are real source; generated neutral marker
// cases in the temporary probe are NOT accepted and have no proof credit.
#include "../../src/CharacterViews.h"
void Character20::Slot06()
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
    default: // Native 0x00642A6C, first 123-byte default handler
        dashMomentumFlag = 0;
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

    case 1: // Native 0x00642AE7: forward motion
        dashMomentumFlag = 0;
        velocityX = 0.6;
        velocityY = 0.0;
        ++field000c;
        if (field000c >= timing.frameDuration) {
            field000c = 0;
            ++field000a;
            if (field000a >= timing.animationFrameCount)
                field000a = 0;
        }
        return;

    case 2: // Native 0x00642B62: reverse motion
        dashMomentumFlag = 0;
        velocityX = -0.6;
        velocityY = 0.0;
        ++field000c;
        if (field000c >= timing.frameDuration) {
            field000c = 0;
            ++field000a;
            if (field000a >= timing.animationFrameCount)
                field000a = 0;
        }
        return;

    case 3: // Native 0x00642BDD: face opponent on neutral recovery
        velocityX = 0.0;
        velocityY = 0.0;
        dashMomentumFlag = 0;
        FaceOpponent();
        ++field000c;
        if (field000c >= timing.frameDuration) {
            field000c = 0;
            ++field000a;
            if (field000a >= timing.animationFrameCount)
                field000a = 0;
        }
        return;

    case 4: // Kano original 0x00642C60: jump and distinct dash-carry timing
        if (field000a == 0 && field000c == 0) {
            if ((unsigned char)dashMomentumFlag == 0)
                FaceOpponent();
            velocityX = 0.0;
        }
        if (field000a == 2 && field000c == 0) {
            gravity = 0.025;
            velocityY = -2.2;
            if ((unsigned char)dashMomentumFlag == 1) {
                velocityX = 0.3;
                dashMomentumFlag = 0;
            }
        }
        if (field000a > 2)
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

    case 5: // Native-checked Kano from original block 0x005E89F4: forward jump with a two-frame loop
        if (field000a == 0 && field000c == 0) {
            if ((unsigned char)dashMomentumFlag == 0) FaceOpponent();
            velocityX = 0.0;
        }
        if (field000a == 2 && field000c == 0) {
            gravity = 0.025;
            velocityY = -2.2;
            velocityX = 0.7;
            if ((unsigned char)dashMomentumFlag == 1) {
                velocityX = 1.1;
                dashMomentumFlag = 0;
            }
        }
        if (field000a > 2) velocityY += gravity;

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

    case 6: // Native-checked Kano from original block 0x005E8B61: backward jump with a two-frame loop
        if (field000a == 0 && field000c == 0) {
            if ((unsigned char)dashMomentumFlag == 0) FaceOpponent();
            velocityX = 0.0;
        }
        if (field000a == 2 && field000c == 0) {
            gravity = 0.025;
            velocityY = -2.2;
            velocityX = -0.7;
            // Unlike case 5, this direction has no dashMomentumFlag override.
        }
        if (field000a > 2) velocityY += gravity;

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

    case 7: // Native-checked Kano from sibling pattern 0x005E8CA9: neutral recovery to animation 0
        velocityX = 0.0;
        velocityY = 0.0;
        dashMomentumFlag = 0;
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

    case 8: // Native-checked Kano from sibling pattern 0x005E8D36: neutral recovery to animation 3
        velocityX = 0.0;
        velocityY = 0.0;
        dashMomentumFlag = 0;
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

    case 9: // Native-checked Kano from sibling pattern 0x005E8DC3: airborne fall and landing reset
        velocityY += gravity;
        dashMomentumFlag = 0;
        ++field000c;
        if (field000c >= timing.frameDuration) {
            field000c = 0;
            ++field000a;
            if (field000a >= timing.animationFrameCount) {
                field000a = 0; // Repeat this animation while in the air.
            }
        }
        if (positionY + velocityY >= 0.0) {
            positionY = 0.0;
            pendingContextSoundSlot = 9;
            field0008 = 13;
            ResetPose();
        }
        return;

    case 13: // Native-checked Kano state from original disassembly 0x005E8E7A: grounded landing recovery
        velocityX = 0.0;
        velocityY = 0.0;
        dashMomentumFlag = 0;
        FaceOpponent();
        ++field000c;
        if (field000c >= timing.frameDuration) {
            field000c = 0;
            ++field000a;
            if (field000a >= timing.animationFrameCount) {
                // The original tests inputY (+0x189) after selecting state 0.
                field0008 = 0;
                if (inputY == 1) field0008 = 3;
                ResetPose();
            }
        }
        return;

    case 14: // Native-checked Kano aerial state based on original disassembly 0x005E8F1F: upward launch and landing recovery
        dashMomentumFlag = 0;
        if (field000a == 0 && field000c == 0) {
            gravity = 0.025;
            velocityY = -2.2;
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
        if (positionY + velocityY >= 0.0 && field000a > 3) {
            positionY = 0.0;
            pendingContextSoundSlot = 9;
            FaceOpponent();
            field0008 = 13;
            ResetPose();
        }
        return;

    case 15: // Native-checked Kano aerial state based on original disassembly 0x005E902E: forward aerial launch
        dashMomentumFlag = 0;
        if (field000a == 0 && field000c == 0) {
            gravity = 0.025;
            velocityY = -2.2;
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
        if (positionY + velocityY >= 0.0 && field000a > 3) {
            positionY = 0.0;
            pendingContextSoundSlot = 9;
            FaceOpponent();
            field0008 = 13;
            ResetPose();
        }
        return;

    case 16: // Native-checked Kano aerial state based on original disassembly 0x005E913B: backward aerial launch
        dashMomentumFlag = 0;
        if (field000a == 0 && field000c == 0) {
            gravity = 0.025;
            velocityY = -2.2;
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

    case 47: // Kano native branch based on original block 0x005E9248: low aerial strike / ground contact
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

    case 50: // Native-checked Kano recoil level 1 0x005E9378: grounded recoil level 1
        if (field0120 != 0) {
            field0118 -= 0.6;
        }
        dashMomentumFlag = 0;
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

    case 51: // Native-checked Kano level 2 recoil 0x005E9569: grounded recoil level 2
        if (field0120 != 0) {
            field0118 -= 0.6;
        }
        dashMomentumFlag = 0;
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

    case 52: // Native-checked Kano level 3 recoil 0x005E975A: grounded recoil level 3
        if (field0120 != 0) {
            field0118 -= 0.6;
        }
        dashMomentumFlag = 0;
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

    case 53: // Native-checked Kano level 4 recoil 0x005e994b: grounded recoil continuation 1
        if (field0120 != 0) {
            field0118 -= 0.6;
        }
        dashMomentumFlag = 0;
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

    case 54: // Native-checked Kano level 5 recoil 0x005e9b3c: grounded recoil continuation 2
        if (field0120 != 0) {
            field0118 -= 0.6;
        }
        dashMomentumFlag = 0;
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

    case 55: // Native-checked Kano recoil and edge pushback 0x005e9d2d: grounded recoil continuation 3
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

    case 56: // Native-checked Kano level recoil 0x005E9F1E: recoil returning directly to crouch
        if (field0120 != 0) {
            field0118 -= 0.6;
        }
        dashMomentumFlag = 0;
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

    case 57: // Native-checked Kano level recoil 0x5ea0f7: stronger recoil returning to crouch
        if (field0120 != 0) {
            field0118 -= 0.6;
        }
        dashMomentumFlag = 0;
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

    case 58: // Native-checked Kano level recoil 0x5ea2d0: stronger recoil returning to crouch
        if (field0120 != 0) {
            field0118 -= 0.6;
        }
        dashMomentumFlag = 0;
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

    case 59: // Native-checked Kano recoil 0x005EA4A9: airborne hit reaction
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

    case 60: // Native-checked Kano recoil 0x5ea6a8: stronger airborne hit reaction
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

    case 61: // Native-checked Kano recoil 0x5ea8a7: stronger airborne hit reaction
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

    case 62: // Native-reviewed Kano: aerial knockback 0x005EAAA6: unclamped airborne hit reaction
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

    case 63: // Native-reviewed Kano: aerial knockback 0x005EAC5D: direct-velocity aerial hit reaction
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

    case 64: // Native-reviewed Kano: aerial knockback 0x005EAE08: wall-aware airborne reaction
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

    case 65: // Native-reviewed Kano: aerial knockback 0x005EB039: stronger wall-aware airborne reaction
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

    case 66: // Native-reviewed Kano: aerial knockback 0x005EB26A: unclamped wall-aware airborne reaction
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

    case 67: // Native-reviewed Kano: aerial knockback 0x005EB453: direct-speed wall-contact reaction
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

    case 68: // Native-reviewed Kano airborne recoil 0x005EB630: collision-cancelled airborne recovery
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

    case 69: // Native-reviewed Kano airborne recoil 0x005EB76C: airborne recovery without wall cancel
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

    case 70: // Native-reviewed Kano original wall/ground recovery 0x005EB881: wall recovery with global effect
        if (field0120 != 0) {
            field0118 -= 0.8;
        }
        if (field000a == 0 && field000c == 0 && field3138 == 0) {
            meter = (short)(meter + 30);
            ++field3138;
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

    case 71: // Native-reviewed Kano original wall/ground recovery 0x005EBA61: high-gravity direct-speed air reaction
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

    case 72: // Native-reviewed Kano original wall/ground recovery 0x005EBC0C: grounded recoil with stage pushback
        if (field0120 != 0) {
            field0118 -= 0.8;
        }
        dashMomentumFlag = 0;
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

    case 73: // Native-reviewed Kano original wall/ground recovery 0x005EBD61: separate grounded recoil continuation
        if (field0120 != 0) {
            field0118 -= 0.8;
        }
        dashMomentumFlag = 0;
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

    case 74: // Native-reviewed Kano original wall/ground recovery 0x005EBEB6: grounded recoil to crouch
        if (field0120 != 0) {
            field0118 -= 0.8;
        }
        dashMomentumFlag = 0;
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

    case 75: // Native-reviewed Kano: recoil and meter recovery 0x005EBFF3: forward grounded recoil
        if (field0120 != 0) {
            field0118 -= 0.6;
        }
        dashMomentumFlag = 0;
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

    case 76: // Native-reviewed Kano: recoil and meter recovery 0x005EC1F0: independent duplicate of recoil 75
        if (field0120 != 0) {
            field0118 -= 0.6;
        }
        dashMomentumFlag = 0;
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

    case 77: // Native-reviewed Kano: recoil and meter recovery 0x005EC3ED: recoil ends in crouch
        if (field0120 != 0) {
            field0118 -= 0.6;
        }
        dashMomentumFlag = 0;
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

    case 81: // Native-reviewed Kano: special hit reaction 0x005EC5D2: airborne recoil and local hit effect
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

    case 82: // Native-reviewed Kano: special hit reaction 0x005EC7B7: repeated airborne lift and knockback
        if (field0120 != 0) {
            field0118 -= 0.8;
        }
        if (field000a == 0 && field000c == 0 && field3138 == 0) {
            pendingContextSoundSlot = 30;
            velocityY = -0.45;
            velocityX = -0.1;
            ++field3138;
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
            if (field000a == 4 && field3138 < 8) {
                field000a = 0;
                ++field3138;
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

    case 83: // Native-reviewed Kano: special hit reaction 0x005EC9D9: airborne ground-impact recovery
        if (field000a == 0 && field000c == 0) {
            if (field3144 == 0) {
                effect.type = 0x1f0;
                effect.x = (double)(int)positionX;
                effect.y = (double)(int)positionY;
                effect.group = 0;
                effect.layer = 0;
                effect.owner = 1;
                effect.flag0018 = (unsigned char)facing;
                EmitLocalEffect(&effect);
                field3144 = 1;
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

    case 84: // Native-reviewed Kano: special hit reaction 0x005ECC1E: independent ground-impact recovery
        if (field000a == 0 && field000c == 0) {
            if (field3144 == 0) {
                effect.type = 0x1f0;
                effect.x = (double)(int)positionX;
                effect.y = (double)(int)positionY;
                effect.group = 0;
                effect.layer = 0;
                effect.owner = 1;
                effect.flag0018 = (unsigned char)facing;
                EmitLocalEffect(&effect);
                field3144 = 1;
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

    case 85: // Native-reviewed Kano: special hit reaction 0x005ECE63: direct airborne knockback and landing
        if (field000a == 0 && field000c == 0) {
            if (field3144 == 0) {
                effect.type = 0x1f0;
                effect.x = (double)(int)positionX;
                effect.y = (double)(int)positionY;
                effect.group = 0;
                effect.layer = 0;
                effect.owner = 1;
                effect.flag0018 = (unsigned char)facing;
                EmitLocalEffect(&effect);
                field3144 = 1;
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

    case 86: // Native-reviewed Kano: special hit reaction 0x005ED036: one-shot lift and landing recoil
        if (field000a == 0 && field000c == 0) {
            if (field3144 == 0) {
                effect.type = 0x1f0;
                effect.x = (double)(int)positionX;
                effect.y = (double)(int)positionY;
                effect.group = 0;
                effect.layer = 0;
                effect.owner = 1;
                effect.flag0018 = (unsigned char)facing;
                EmitLocalEffect(&effect);
                field3144 = 1;
            }
            // Unlike state 85, this launch is suppressed after its first use.
            if (field3138 == 0) {
                if (field0120 != 0) {
                    field0118 -= 30.0;
                }
                pendingContextSoundSlot = 33;
                velocityX = knockbackVelocityX;
                velocityY = knockbackVelocityY;
                meter = (short)(meter + 30);
                ++field3138;
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

    case 87: // Native-reviewed Kano: special hit reaction 0x005ED218: fixed-position effect and idle return
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

    case 96: // Native-reviewed Kano wake-up or impact 0x005ED2CB: stand/crouch wakeup timing
        ++field000c;
        if (field000c >= timing.frameDuration) {
            field000c = 0;
            ++field000a;
            // Face one frame before the animation ends, not at the end.
            if (field000a == timing.animationFrameCount - 1) {
                FaceOpponent();
            }
            if (field000a >= timing.animationFrameCount) {
                field0008 = 7;
                if (inputY == 1) {
                    field0008 = 3;
                }
                ResetPose();
            }
        }
        return;

    case 97: // Native-reviewed Kano wake-up or impact 0x005ED360: first impact flash
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

    case 98: // Native-reviewed Kano wake-up or impact 0x005ED458: separately dispatched impact flash
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

    case 99: // Native-reviewed Kano 0x00647980: timed wake-up with conditional health gate
        ++field000c;
        dashMomentumFlag = 0;
        if (health > 0 && field000c > 99 && field000a == 0) {
            field0008 = 96;
            ResetPose();
        }
        if (field000c >= timing.frameDuration) {
            field000c = 0;
            ++field000a;
            if (field000a == timing.animationFrameCount)
                FaceOpponent();
            if (field000a >= timing.animationFrameCount) {
                field0008 = 96;
                ResetPose();
            }
        }
        return;

    case 150: // Native-reviewed Kano original attack/recoil 0x005ED5FF: {'stand/crouch' if terminal == 0 else 'crouching'} recoil
        if (inputY == 1) {
            field0008 = 153;
        }
        if (inputY != 1) {
            field0008 = 150;
        }
        if (field000a == 0 && field000c == 0) {
            dashMomentumFlag = 0;
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

    case 151: // Native-reviewed Kano original attack/recoil 0x005ED7AB: {'stand/crouch' if terminal == 0 else 'crouching'} recoil
        if (inputY == 1) {
            field0008 = 154;
        }
        if (inputY != 1) {
            field0008 = 151;
        }
        if (field000a == 0 && field000c == 0) {
            dashMomentumFlag = 0;
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

    case 152: // Native-reviewed Kano original attack/recoil 0x005ED957: {'stand/crouch' if terminal == 0 else 'crouching'} recoil
        if (inputY == 1) {
            field0008 = 155;
        }
        if (inputY != 1) {
            field0008 = 152;
        }
        if (field000a == 0 && field000c == 0) {
            dashMomentumFlag = 0;
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

    case 153: // Native-reviewed Kano original attack/recoil 0x005EDB03: {'stand/crouch' if terminal == 0 else 'crouching'} recoil
        if (inputY == 1) {
            field0008 = 153;
        }
        if (inputY != 1) {
            field0008 = 150;
        }
        if (field000a == 0 && field000c == 0) {
            dashMomentumFlag = 0;
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

    case 154: // Native-reviewed Kano original attack/recoil 0x005EDC97: {'stand/crouch' if terminal == 0 else 'crouching'} recoil
        if (inputY == 1) {
            field0008 = 154;
        }
        if (inputY != 1) {
            field0008 = 151;
        }
        if (field000a == 0 && field000c == 0) {
            dashMomentumFlag = 0;
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

    case 155: // Native-reviewed Kano original attack/recoil 0x005EDE2B: {'stand/crouch' if terminal == 0 else 'crouching'} recoil
        if (inputY == 1) {
            field0008 = 155;
        }
        if (inputY != 1) {
            field0008 = 152;
        }
        if (field000a == 0 && field000c == 0) {
            dashMomentumFlag = 0;
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

    case 156: // Native-reviewed Kano original attack/recoil 0x005EDFBF: forward airborne knockback
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

    case 157: // Native-reviewed Kano original attack/recoil 0x005EE0CF: aerial effect with two-frame loop
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

    case 158: // Native-reviewed Kano original attack/recoil 0x005EE223: opposite-direction aerial effect
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

    case 161: // Native-reviewed Kano original 0x005EE377: aerial impact and trail reset
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
            ++field3138;
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

    case 162: // Native-reviewed Kano original 0x005EE48B: staged aerial launch and impact
        if (field000a == 0 && field000c == 0) {
            ResetFrame();
        }
        if (field000a == 3 && field000c == 0) {
            velocityY = -1.5;
            gravity = 0.025;
            remainingHitCount = 1;
        }
        if (field000a == 4 && field000c == 0) {
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
            ++field3138;
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
            if (field000a == 15) {
                gravity = 0.035;
            }
            if (field000a >= timing.animationFrameCount) {
                field000a = (unsigned short)(field000a - 2);
            }
        }
        return;

    case 163: // Native-reviewed Kano original 0x005EE676: cancellable forward dash
        if (field000a == 0 && field000c == 0) {
            StartTrail(3);
        }
        if (inputY == -1 && field000a > 0) {
            field0008 = 4;
            if (inputX == facing) {
                field0008 = 5;
            }
            if ((int)inputX == -(int)facing) {
                field0008 = 6;
            }
            attackCollisionResult = 0;
            ResetPose();
            return;
        }
        if (field000a == 0 && field000c == 0) {
            velocityY = 0.0;
            gravity = 0.0;
        }
        if (field000a > 3)
            velocityX = 1.5;
        dashMomentumFlag = 1;
        ++field000c;
        ++field3138;
        ++field313c;
        if (field000c >= timing.frameDuration) {
            field000c = 0;
            ++field000a;
            if (field000a >= timing.animationFrameCount) {
                field000a = (unsigned short)(field000a - 3);
                return;
            }
        }
        if (inputX == facing && field313c >= 80) {
            field0008 = 178;
            ResetPose();
        }
        if (inputX != facing && field3138 >= 60) {
            field0008 = 178;
            ResetPose();
        }
        return;

    case 164: // Native-reviewed Kano 0x00648C86 reverse dash with momentum recovery
        StartTrail(2);
        dashMomentumFlag = 0;
        if (field000a == 0 && field000c == 0 && field3138 == 0) {
            ResetFrame();
            velocityX = -3.1;
            velocityY = 0.0;
            gravity = 0.0;
            field3138 = 1;
            pendingContextSoundSlot = 17;
        }
        if (field000a > -1)
            velocityX += 0.04;
        if (velocityX >= 0.0 && field000a > -1) {
            velocityX = 0.0;
            velocityY = 0.0;
            field0008 = 0;
            ResetPose();
            return;
        }
        ++field000c;
        if (field000c >= timing.frameDuration) {
            field000c = 0;
            ++field000a;
            if (field000a >= timing.animationFrameCount)
                field000a = 0;
        }
        return;

    case 165: // Native-reviewed Kano 0x00648DC5 forward sustained dash and delayed recovery
        if (field000a == 0 && field000c == 0 && field3138 == 0) {
            velocityX = 1.1;
            StartTrail(3);
            velocityY = 0.0;
            gravity = 0.0;
            pendingContextSoundSlot = 17;
        }
        ++field000c;
        ++field3138;
        ++field313c;
        if (field000c >= timing.frameDuration) {
            field000c = 0;
            ++field000a;
            if (field000a >= timing.animationFrameCount)
                field000a = 0;
        }
        if (inputX == facing && field313c >= 120) {
            field0008 = 9;
            ResetPose();
            velocityX = 0.9;
            gravity = 0.02;
            if (FaceOpponent() != 0)
                velocityX = -velocityX;
        }
        if (inputX != facing && field3138 >= 48) {
            field0008 = 9;
            ResetPose();
            velocityX = 0.9;
            gravity = 0.02;
            if (FaceOpponent() != 0)
                velocityX = -velocityX;
        }
        return;

    case 166: // Native-reviewed Kano 0x00648F6E backward sustained dash and recovery
        if (field000a == 0 && field000c == 0 && field3138 == 0) {
            velocityX = -1.1;
            velocityY = 0.0;
            gravity = 0.0;
            StartTrail(3);
            pendingContextSoundSlot = 17;
        }
        ++field000c;
        ++field3138;
        ++field313c;
        if (field000c >= timing.frameDuration) {
            field000c = 0;
            ++field000a;
            if (field000a >= timing.animationFrameCount)
                field000a = 0;
        }
        if ((int)inputX == -(int)facing && field313c >= 120) {
            field0008 = 9;
            ResetPose();
            velocityX = -0.9;
            gravity = 0.02;
            if (FaceOpponent() != 0)
                velocityX = -velocityX;
        }
        if ((int)inputX != -(int)facing && field3138 >= 48) {
            field0008 = 9;
            ResetPose();
            velocityX = -0.9;
            gravity = 0.03;
            if (FaceOpponent() != 0)
                velocityX = -velocityX;
        }
        return;

    case 167: // Native-reviewed Kano original 0x005EEDC4: stunned recovery with two effects
        if (field000a == 0 && field000c == 0) {
            dashMomentumFlag = 0;
            velocityX = 0.0;
            velocityY = 0.0;
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

    case 168: // Native-reviewed Kano original 0x005EEFAC: grounded impact to state 0
        if (field000a == 0 && field000c == 0) {
            dashMomentumFlag = 0;
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

    case 169: // Native-reviewed Kano original 0x005EF0F6: grounded impact to state 3
        if (field000a == 0 && field000c == 0) {
            dashMomentumFlag = 0;
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

    case 170: // Native-reviewed Kano original 0x005EF240: delayed stored-velocity release
        if (field000a == 0 && field000c == 0) {
            field3138 = (int)(velocityX * 100.0);
            field313c = (int)(velocityY * 100.0);
            if (gravity == 0.0) {
                gravity = 0.035;
            }
            velocityX = 0.0;
            velocityY = 0.0;
            guardInputFrames = 0;
            outgoingPushbackVelocityX = 0.0;
            hitstunFrames = 60;
        }
        if (hitstunFrames == 0 && field3140 == 0) {
            ++field3140;
            velocityX = (double)field3138 * 0.01;
            velocityY = (double)field313c * 0.01;
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

    case 171: // Native-reviewed Kano original 0x005EF409: frozen hit, one immediate effect
        if (field000a == 0 && field000c == 0) {
            field3138 = (int)(velocityX * 100.0);
            field313c = (int)(velocityY * 100.0);
            velocityX = 0.0;
            velocityY = 0.0;
            if (field0120 == 1) {
                comboDamageScale += field0118 * 5.0;
            }
            field0118 = 0.0;
            hitstunFrames = 90;
            SetTint(0xb0, 3);
        }
        // This effect is also on pose zero, unlike reference characters.
        if (field000a == 0 && field000c == 0) {
            pendingContextSoundSlot = 18;
            effect.type = 1;
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
                velocityX = (double)field3138 * 0.01;
                velocityY = (double)field313c * 0.01;
                if (gravity == 0.0)
                    gravity = 0.02;
                ResetPose();
            }
        }
        return;

    case 178: // Native-reviewed Kano original 0x005EF5E8: dash slide and jump cancel
        velocityX -= 0.03;
        velocityX = velocityX;
        if (velocityX < 0.0) {
            velocityX = 0.0;
            dashMomentumFlag = 0;
        }
        if (inputY == -1 && field000a > 0) {
            field0008 = 4;
            if (inputX == facing) {
                field0008 = 5;
            }
            if ((int)inputX == -(int)facing) {
                field0008 = 6;
            }
            attackCollisionResult = 0;
            ResetPose();
            return;
        }
        ++field000c;
        if (field000c >= timing.frameDuration) {
            field000c = 0;
            ++field000a;
            if (field000a >= timing.animationFrameCount) {
                field0008 = 0;
                ResetPose();
                return;
            }
        }
        return;

    case 180: // Native-reviewed Kano original 0x005EF70A: trailing aerial landing
        if (field000a == 0 && field000c == 0) {
            StartTrail(2);
            velocityX = 0.0;
            velocityY = 0.0;
            gravity = 0.0;
        }
        if (positionY < 0.0) {
            velocityY += gravity;
        }
        if (positionY + velocityY > 0.0 && field000a < 9) {
            ResetFrame();
            positionY = 0.0;
            field000c = 0;
            field000a = 9;
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
            if (field000a == 9) {
                field000a = (unsigned short)(field000a - 2);
            }
            if (field000a >= timing.animationFrameCount) {
                ResetPose();
                field0008 = 0;
            }
        }
        return;

    case 200: // Native-reviewed Kano original 0x005EF87C: dash-momentum attack
        if ((unsigned char)dashMomentumFlag == 0) {
            velocityX = 0.0;
            velocityY = 0.0;
        }
        if (velocityX > 0.0 && (unsigned char)dashMomentumFlag == 1) {
            velocityX -= 0.03;
        } else {
            velocityX = 0.0;
            dashMomentumFlag = 0;
        }
        if (inputY == -1 && field000a > 0 && field015c < 3 &&
            attackCollisionResult >= 2) {
            field0008 = 4;
            if (inputX == facing) {
                field0008 = 5;
            }
            if ((int)inputX == -(int)facing) {
                field0008 = 6;
            }
            attackCollisionResult = 0;
            ResetPose();
            return;
        }
        if (field000a == 2 && field000c == 0) {
            pendingContextSoundSlot = 21;
            remainingHitCount = 1;
        }
        ++field000c;
        if (field000c >= timing.frameDuration) {
            field000c = 0;
            ++field000a;
            if (field000a < 3) {
                attackCollisionResult = 0;
            }
            if (field000a >= timing.animationFrameCount) {
                field0008 = 0;
                FaceOpponent();
                ResetPose();
            }
        }
        return;

    case 201: // Native-reviewed Kano original 0x005EFA4F: dash-momentum attack
        if ((unsigned char)dashMomentumFlag == 0) {
            velocityX = 0.0;
            velocityY = 0.0;
        }
        if (velocityX > 0.0 && (unsigned char)dashMomentumFlag == 1) {
            velocityX -= 0.03;
        } else {
            velocityX = 0.0;
            dashMomentumFlag = 0;
        }
        if (inputY == -1 && field000a > 0 && field015c < 3 &&
            attackCollisionResult > 0 && attackCollisionResult != 6) {
            field0008 = 4;
            if (inputX == facing) {
                field0008 = 5;
            }
            if ((int)inputX == -(int)facing) {
                field0008 = 6;
            }
            attackCollisionResult = 0;
            ResetPose();
            return;
        }
        if (field000a == 1 && field000c == 0) {
            pendingContextSoundSlot = 20;
            remainingHitCount = 1;
        }
        ++field000c;
        if (field000c >= timing.frameDuration) {
            field000c = 0;
            ++field000a;
            if (field000a < 4) {
                attackCollisionResult = 0;
            }
            if (field000a >= timing.animationFrameCount) {
                field0008 = 0;
                FaceOpponent();
                ResetPose();
            }
        }
        return;

    case 202: // Native-reviewed Kano original 0x005EFC22: local hit effect on advanced pose
        if ((unsigned char)dashMomentumFlag == 0) {
            velocityX = 0.0;
            velocityY = 0.0;
        }
        if (velocityX > 0.0 && (unsigned char)dashMomentumFlag == 1) {
            velocityX -= 0.03;
        } else {
            velocityX = 0.0;
            dashMomentumFlag = 0;
        }
        if (field000a == 4 && field000c == 0) {
            pendingContextSoundSlot = 20;
            remainingHitCount = 1;
        }
        ++field000c;
        if (field000c >= timing.frameDuration) {
            field000c = 0;
            ++field000a;
            if (field000a < 6) {
                attackCollisionResult = 0;
            }
            if (field000a >= timing.animationFrameCount) {
                field0008 = 0;
                FaceOpponent();
                ResetPose();
            }
        }
        return;

    case 203: // Native-reviewed Kano 0x0064A09D: exact collision-gated dash and frame4 activation
        if ((unsigned char)dashMomentumFlag == 0) {
            velocityX = 0.0;
            velocityY = 0.0;
        }
        if (velocityX > 0.0 && (unsigned char)dashMomentumFlag == 1) {
            velocityX -= 0.03;
        } else {
            velocityX = 0.0;
            dashMomentumFlag = 0;
        }
        if (inputY == -1 && field000a > 0 && field015c < 3 &&
            attackCollisionResult == 3) {
            field0008 = 4;
            if (inputX == facing) {
                field0008 = 5;
            }
            if ((int)inputX == -(int)facing) {
                field0008 = 6;
            }
            attackCollisionResult = 0;
            ResetPose();
            return;
        }
        if (field000a == 4 && field000c == 0) {
            pendingContextSoundSlot = 20;
            remainingHitCount = 1;
        }
        ++field000c;
        if (field000c >= timing.frameDuration) {
            field000c = 0;
            ++field000a;
            if (field000a < 6) {
                attackCollisionResult = 0;
            }
            if (field000a >= timing.animationFrameCount) {
                field0008 = 0;
                FaceOpponent();
                ResetPose();
            }
        }
        return;

    case 204: // Native-reviewed Kano original 0x005F008D: grounded dash cancel and recovery
        if ((unsigned char)dashMomentumFlag == 0) {
            velocityX = 0.0;
            velocityY = 0.0;
        }
        if (velocityX > 0.0 && (unsigned char)dashMomentumFlag == 1) {
            velocityX -= 0.03;
        } else {
            velocityX = 0.0;
            dashMomentumFlag = 0;
        }
        if (inputY == -1 && field000a > 0 && field015c < 3 &&
            attackCollisionResult >= 2) {
            field0008 = 4;
            if (inputX == facing) {
                field0008 = 5;
            }
            if ((int)inputX == -(int)facing) {
                field0008 = 6;
            }
            attackCollisionResult = 0;
            ResetPose();
            return;
        }
        if (field000a == 1 && field000c == 0) {
            pendingContextSoundSlot = 21;
            remainingHitCount = 1;
        }
        ++field000c;
        if (field000c >= timing.frameDuration) {
            field000c = 0;
            ++field000a;
            if (field000a < 3) {
                attackCollisionResult = 0;
            }
            if (field000a >= timing.animationFrameCount) {
                field0008 = 0;
                if (inputY == 1) {
                    field0008 = 3;
                }
                FaceOpponent();
                ResetPose();
            }
        }
        return;

    case 205: // Native-reviewed Kano original 0x005F0278: grounded dash cancel and recovery
        if ((unsigned char)dashMomentumFlag == 0) {
            velocityX = 0.0;
            velocityY = 0.0;
        }
        if (velocityX > 0.0 && (unsigned char)dashMomentumFlag == 1) {
            velocityX -= 0.03;
        } else {
            velocityX = 0.0;
            dashMomentumFlag = 0;
        }
        if (inputY == -1 && field000a > 0 && field015c < 3 &&
            attackCollisionResult >= 2) {
            field0008 = 4;
            if (inputX == facing) {
                field0008 = 5;
            }
            if ((int)inputX == -(int)facing) {
                field0008 = 6;
            }
            attackCollisionResult = 0;
            ResetPose();
            return;
        }
        if (field000a == 2 && field000c == 0) {
            pendingContextSoundSlot = 20;
            remainingHitCount = 1;
        }
        ++field000c;
        if (field000c >= timing.frameDuration) {
            field000c = 0;
            ++field000a;
            if (field000a < 4) {
                attackCollisionResult = 0;
            }
            if (field000a >= timing.animationFrameCount) {
                field0008 = 0;
                if (inputY == 1) {
                    field0008 = 3;
                }
                FaceOpponent();
                ResetPose();
            }
        }
        return;

    case 206: // Native-reviewed Kano 0x0064A601: crouch-capable frame1 strike, native dash friction
        if ((unsigned char)dashMomentumFlag == 0) {
            velocityX = 0.0;
            velocityY = 0.0;
        }
        if (velocityX > 0.0 && (unsigned char)dashMomentumFlag == 1) {
            velocityX -= 0.03;
        } else {
            velocityX = 0.0;
            dashMomentumFlag = 0;
        }
        if (field000a == 1 && field000c == 0) {
            pendingContextSoundSlot = 21;
            remainingHitCount = 1;
        }
        ++field000c;
        if (field000c >= timing.frameDuration) {
            field000c = 0;
            ++field000a;
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

    case 207: // Native-reviewed Kano 0x0064A730 natural aerial jump cancel 0x005F0669: aerial attack with jump cancel
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
        if (field000a == 2 && field000c == 0) {
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

    case 208: // Native-reviewed Kano 0x0064A8EF natural aerial jump cancel 0x005F0840: aerial attack with jump cancel
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
        if (field000a == 3 && field000c == 0) {
            pendingContextSoundSlot = 20;
            remainingHitCount = 2;
        }
        if (field000a == 8 && field000c == 0)
            pendingContextSoundSlot = 20;
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
            if (field000a == 4 || field000a == 9) {
                attackCollisionResult = 0;
            }
            if (field000a >= timing.animationFrameCount) {
                field0008 = 9;
                ResetPose();
            }
        }
        return;

    case 209: // Native-reviewed Kano 0x0064AADB: repeatable airborne multi-hit combo
        velocityY += gravity;
        if (inputY == -1 && field000a > 0 && field015c < 3 &&
            attackCollisionResult >= 2 && airActionCount == 0) {
            ++airActionCount;
            field0008 = 14;
            if (inputX == facing)
                field0008 = 15;
            if ((int)inputX == -(int)facing)
                field0008 = 16;
            attackCollisionResult = 0;
            ResetPose();
            return;
        }
        if (field000a == 2 && field000c == 0)
            remainingHitCount = 5;
        if (field000a == 7 && field000c == 0)
            pendingContextSoundSlot = 20;
        if (field000a == 10 && field000c == 0)
            pendingContextSoundSlot = 20;
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
            if (field000a == 7 || field000a == 9 ||
                field000a == 11 || field000a == 13)
                attackCollisionResult = 0;
            if (field000a == 14 && field3138 < 1) {
                ++field3138;
                field000a = (unsigned short)(field000a - 7);
            }
            if (field000a >= timing.animationFrameCount) {
                field0008 = 9;
                ResetPose();
            }
        }
        return;

    case 210: // Native-reviewed Kano 0x0064AD38: meter-consuming flying local-effect attack
        if (field000a == 0 && field000c == 0) {
            dashMomentumFlag = 0;
            ResetFrame();
        }
        if (field000a == 8 && field000c == 0) {
            effect.type = 0x199;
            effect.x = (double)((int)positionX + (int)facing * 150);
            effect.y = -40.0;
            effect.group = 2;
            effect.layer = 1;
            effect.flag0018 = (unsigned char)facing;
            EmitLocalEffect(&effect);
            ++field3138;
            pendingCharacterSoundSlot = 2;
            meter = (short)(meter - 20);
        }
        ++field000c;
        if (field000c >= timing.frameDuration) {
            field000c = 0;
            ++field000a;
            if (field000a < 8)
                attackCollisionResult = 0;
            if (field000a >= timing.animationFrameCount) {
                field0008 = 0;
                ResetPose();
            }
        }
        return;

    case 211: // Native-reviewed Kano 0x0064AE89: short aerial hit and landing reset
        if (field000a == 0 && field000c == 0) {
            velocityX = 0.0;
            velocityY = 0.0;
        }
        if (field000a == 3 && field000c == 0) {
            velocityX = 1.2;
            velocityY = 1.2;
        }
        if (field000a == 1 && field000c == 0)
            remainingHitCount = 1;
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
            if (field000a >= timing.animationFrameCount)
                field000a = (unsigned short)(field000a - 1);
        }
        return;

    case 212: // Native-reviewed Kano 0x0064AFA7: native multi-cycle grounded dash and pose exit
        if (field000a == 0) {
            if ((unsigned char)dashMomentumFlag == 0) {
                velocityX = 0.0;
                velocityY = 0.0;
            }
            if (velocityX > 0.0 && (unsigned char)dashMomentumFlag == 1) {
                velocityX -= 0.03;
            } else {
                velocityX = 0.0;
                dashMomentumFlag = 0;
            }
        }
        if (field000a == 1 && field000c == 0) {
            velocityX = 2.6;
            pendingContextSoundSlot = 20;
            remainingHitCount = 1;
        }
        if (field000a > 0)
            velocityX -= 0.03;
        if (velocityX < 0.0)
            velocityX = 0.0;
        ++field000c;
        if (field000c >= timing.frameDuration) {
            field000c = 0;
            ++field000a;
            if (field000a < 2)
                attackCollisionResult = 0;
            if (field000a == 4 && field3138 < 3) {
                ++field3138;
                field000a = (unsigned short)(field000a - 2);
            }
            if (field000a >= timing.animationFrameCount) {
                field0008 = 7;
                if (inputY == 1)
                    field0008 = 3;
                FaceOpponent();
                ResetPose();
            }
        }
        return;

    case 213: // Native-reviewed Kano 0x0064B177: native aerial bounce and polar-velocity hit
        if (field000a == 0 && field000c == 0) {
            velocityX = 0.0;
            velocityY = 0.0;
        }
        if (field000a == 1 && field000c == 0)
            remainingHitCount = 1;
        if (positionY + velocityY >= 0.0 && field000a < 5) {
            positionY = 0.0;
            ResetFrame();
            field000c = 0;
            field000a = 5;
            return;
        }
        ++field000c;
        if (field000c >= timing.frameDuration) {
            field000c = 0;
            ++field000a;
            if (field000a == 1)
                attackCollisionResult = 0;
            if (field000a == 3)
                reinterpret_cast<SecondaryEffectSlot *>(&field0008)->SetVelocityPolar(30.0,2.2);
            if (field000a == 5)
                field000a = (unsigned short)(field000a - 2);
            if (field000a >= timing.animationFrameCount) {
                ResetPose();
                field0008 = 7;
                FaceOpponent();
            }
        }
        return;

    case 214: // Native-reviewed Kano 0x0064B2EC: native aerial bounce and polar-velocity hit
        if (field000a == 0 && field000c == 0) {
            velocityX = 0.0;
            velocityY = 0.0;
        }
        if (field000a == 1 && field000c == 0)
            remainingHitCount = 1;
        if (positionY + velocityY >= 0.0 && field000a < 5) {
            positionY = 0.0;
            ResetFrame();
            field000c = 0;
            field000a = 5;
            return;
        }
        ++field000c;
        if (field000c >= timing.frameDuration) {
            field000c = 0;
            ++field000a;
            if (field000a == 1)
                attackCollisionResult = 0;
            if (field000a == 3)
                reinterpret_cast<SecondaryEffectSlot *>(&field0008)->SetVelocityPolar(45.0,1.7);
            if (field000a == 5)
                field000a = (unsigned short)(field000a - 2);
            if (field000a >= timing.animationFrameCount) {
                ResetPose();
                field0008 = 7;
                FaceOpponent();
            }
        }
        return;

    case 215: // Native-reviewed Kano 0x0064B461: native aerial bounce and polar-velocity hit
        if (field000a == 0 && field000c == 0) {
            velocityX = 0.0;
            velocityY = 0.0;
        }
        if (field000a == 1 && field000c == 0)
            remainingHitCount = 1;
        if (positionY + velocityY >= 0.0 && field000a < 5) {
            positionY = 0.0;
            ResetFrame();
            field000c = 0;
            field000a = 5;
            return;
        }
        ++field000c;
        if (field000c >= timing.frameDuration) {
            field000c = 0;
            ++field000a;
            if (field000a == 1)
                attackCollisionResult = 0;
            if (field000a == 3)
                reinterpret_cast<SecondaryEffectSlot *>(&field0008)->SetVelocityPolar(60.0,1.5);
            if (field000a == 5)
                field000a = (unsigned short)(field000a - 2);
            if (field000a >= timing.animationFrameCount) {
                ResetPose();
                field0008 = 7;
                FaceOpponent();
            }
        }
        return;

    case 217: // Native-reviewed Kano 0x0064B5D6: momentum-friction frame4 grounded strike
        if ((unsigned char)dashMomentumFlag == 0) {
            velocityX = 0.0;
            velocityY = 0.0;
        }
        if (velocityX > 0.0 && (unsigned char)dashMomentumFlag == 1) {
            velocityX -= 0.03;
        } else {
            velocityX = 0.0;
            dashMomentumFlag = 0;
        }
        if (field000a == 4 && field000c == 0) {
            pendingContextSoundSlot = 20;
            remainingHitCount = 1;
        }
        ++field000c;
        if (field000c >= timing.frameDuration) {
            field000c = 0;
            ++field000a;
            if (field000a < 6)
                attackCollisionResult = 0;
            if (field000a >= timing.animationFrameCount) {
                field0008 = 0;
                FaceOpponent();
                ResetPose();
            }
        }
        return;

    case 220: // Native-reviewed Kano candidate from original attack grab semantics 0x005F1440: opponent grab and impact effect
        velocityX = 0.0;
        velocityY = 0.0;
        dashMomentumFlag = 0;
        if (field000a == 2 && field000c == 0 &&
            (*opponentSlot)->positionY == 0.0) {
            remainingHitCount = 1;
        } else {
            remainingHitCount = 0;
        }
        if (field000a == 2 && attackCollisionResult == 3) {
            velocityX = 0.0;
            velocityY = 0.0;
            outgoingPushbackVelocityX = 0.0;
            ResetPose();
            (*opponentSlot)->ResetPose();
            (*opponentSlot)->ResetFrame();
            field0008 = 221;
            (*opponentSlot)->field0008 = 107;
            effect.type = 0;
            effect.y = -52.0;
            effect.x = (double)(int)(positionX + (double)((int)facing * 35));
            effect.group = 2;
            effect.layer = 1;
            contextOwner->EmitEffect(&effect);
            // Original proceeds to the frame counter even after a grab.
        }
        ++field000c;
        if (field000c >= timing.frameDuration) {
            field000c = 0;
            ++field000a;
            attackCollisionResult = 0;
            if (field000a >= timing.animationFrameCount) {
                field0008 = 7;
                if (inputY == 1)
                    field0008 = 3;
                FaceOpponent();
                ResetPose();
            }
        }
        return;

    case 221: // Native-reviewed Kano 0x0064B8D5: post-grab damage, opponent launch and recovery
        if (field000a == 2 && field000c == 0) {
            (*opponentSlot)->hitstopFrames = 30;
            effect.type = 0;
            effect.x = (double)((int)positionX + (int)facing * 74);
            effect.y = (double)((int)positionY - 54);
            effect.group = 2;
            effect.palette = 2;
            effect.layer = 1;
            contextOwner->EmitEffect(&effect);
            ApplyDamage(1000,750.0);
            (*opponentSlot)->ResetPose();
            (*opponentSlot)->field0008 = 63;
            (*opponentSlot)->knockbackVelocityX = -2.0;
            (*opponentSlot)->knockbackVelocityY = -1.5;
        }
        ++field000c;
        if (field000c >= timing.frameDuration) {
            field000c = 0;
            ++field000a;
            attackCollisionResult = 3;
            if (field000a >= timing.animationFrameCount) {
                field0008 = 0;
                ResetPose();
                FaceOpponent();
            }
        }
        return;

    case 230: // Native-reviewed Kano 0x0064BA44: trail start and friction-based grounded strike
        StartTrail(3);
        dashMomentumFlag = 0;
        velocityX -= 0.01;
        if (velocityX < 0.0)
            velocityX = 0.0;
        if (field000a == 0 && field000c == 0) {
            velocityY = 0.0;
            velocityX = 1.2;
        }
        if (field000a == 1 && field000c == 0) {
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
                ResetPose();
            }
        }
        return;

    case 231: // Native-reviewed Kano original 0x0064BB60: jumping dash cancel and guarded hit
        StartTrail(3);
        dashMomentumFlag = 0;
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
        velocityX -= 0.01;
        if (velocityX < 0.0)
            velocityX = 0.0;
        if (field000a == 0 && field000c == 0) {
            velocityY = 0.0;
            velocityX = 1.2;
        }
        if (field000a == 4 && field000c == 0) {
            pendingContextSoundSlot = 20;
            remainingHitCount = 1;
        }
        ++field000c;
        if (field000c >= timing.frameDuration) {
            field000c = 0;
            ++field000a;
            if (field000a < 6)
                attackCollisionResult = 0;
            if (field000a >= timing.animationFrameCount) {
                field0008 = 0;
                ResetPose();
            }
        }
        return;

    case 232: // Native-reviewed Kano original 0x0064BD15: jumping dash cancel and guarded hit
        StartTrail(3);
        dashMomentumFlag = 0;
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
        velocityX -= 0.01;
        if (velocityX < 0.0)
            velocityX = 0.0;
        if (field000a == 0 && field000c == 0) {
            velocityY = 0.0;
            velocityX = 1.2;
        }
        if (field000a == 2 && field000c == 0) {
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
                ResetPose();
            }
        }
        return;

    case 233: // Kano original 0x0064BECA: native grounded trail strike
        StartTrail(3);
        dashMomentumFlag = 0;
        velocityX -= 0.01;
        if (velocityX < 0.0)
            velocityX = 0.0;
        if (field000a == 0 && field000c == 0) {
            velocityY = 0.0;
            velocityX = 1.2;
        }
        if (field000a == 1 && field000c == 0) {
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
                field0008 = 3;
                ResetPose();
            }
        }
        return;

    case 234: // Kano original 0x0064BFE6: native grounded trail strike
        StartTrail(3);
        dashMomentumFlag = 0;
        velocityX -= 0.01;
        if (velocityX < 0.0)
            velocityX = 0.0;
        if (field000a == 0 && field000c == 0) {
            velocityY = 0.0;
            velocityX = 1.2;
        }
        if (field000a == 2 && field000c == 0) {
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
                field0008 = 3;
                ResetPose();
            }
        }
        return;

    case 235: // Kano original 0x0064C102: native grounded trail strike
        StartTrail(3);
        dashMomentumFlag = 0;
        velocityX -= 0.01;
        if (velocityX < 0.0)
            velocityX = 0.0;
        if (field000a == 0 && field000c == 0) {
            velocityY = 0.0;
            velocityX = 1.2;
        }
        if (field000a == 2 && field000c == 0) {
            pendingContextSoundSlot = 21;
            remainingHitCount = 6;
        }
        ++field000c;
        if (field000c >= timing.frameDuration) {
            field000c = 0;
            ++field000a;
            attackCollisionResult = 0;
            if (field000a >= timing.animationFrameCount) {
                field0008 = 3;
                ResetPose();
            }
        }
        return;

    case 248: // Native-reviewed Kano 0x0064C212: native aerial opponent catch and reposition
        velocityY += gravity;
        if (field000a == 1 && attackCollisionResult == 3) {
            (*opponentSlot)->ResetFrame();
            (*opponentSlot)->ResetPose();
            ResetPose();
            ResetFrame();
            field0008 = 249;
            (*opponentSlot)->field0008 = 100;
            effect.type = 0;
            effect.x = (double)((int)positionX + (int)facing * 29);
            effect.y = (double)((int)positionY - 62);
            effect.group = 2;
            effect.layer = 1;
            contextOwner->EmitEffect(&effect);
            (*opponentSlot)->positionX = positionX + (double)((int)facing * 29);
            (*opponentSlot)->positionY = positionY - 62.0;
            SetHorizontalOffset(50, 3);
            SetHorizontalShake(50, 3);
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
                field0008 = 209;
                field000a = 2;
            }
        }
        return;

    case 249: // Native-reviewed Kano 0x0064C41A: staged aerial throw and opponent tracking
        if (field000a < 5)
            SetHorizontalOffset(50, 3);
        if (field000a < 5)
            SetHorizontalShake(50, 3);
        if (field000a == 0 && field000c == 1)
            (*opponentSlot)->facing = -facing;
        velocityY += gravity;
        if (velocityY + positionY > 0.0 && field000a > 5) {
            ResetFrame();
            positionY = 0.0;
            ResetPose();
            field0008 = 13;
            return;
        }
        if (field000a == 2) {
            (*opponentSlot)->positionY = positionY - 47.0;
            (*opponentSlot)->positionX = positionX + (double)((int)facing * 28);
            (*opponentSlot)->field0008 = 101;
        }
        if (field000a == 3) {
            (*opponentSlot)->positionY = positionY - 38.0;
            (*opponentSlot)->positionX = positionX + (double)((int)facing * 20);
            (*opponentSlot)->field0008 = 101;
            (*opponentSlot)->facing = facing;
        }
        if (field000a == 4) {
            (*opponentSlot)->positionY = positionY - 62.0;
            (*opponentSlot)->positionX = positionX + (double)((int)facing * 29);
            (*opponentSlot)->field0008 = 100;
            (*opponentSlot)->facing = facing;
        }
        if (field000a == 5 && field000c == 0) {
            (*opponentSlot)->positionY = positionY - 72.0;
            (*opponentSlot)->positionX = positionX;
            (*opponentSlot)->field0008 = 63;
            (*opponentSlot)->facing = facing;
            ApplyDamage(1200, 500.0);
            (*opponentSlot)->ResetPose();
            (*opponentSlot)->knockbackVelocityX = -1.0;
            (*opponentSlot)->knockbackVelocityY = -2.3;
        }
        if (field000a == 12 && field000c == 0)
            gravity = 0.035;
        ++field000c;
        if (field000c >= timing.frameDuration) {
            field000c = 0;
            ++field000a;
            attackCollisionResult = 0;
            if (field000a >= timing.animationFrameCount)
                field000a = (unsigned short)(field000a - 2);
        }
        return;

    case 250: // EXPERIMENTAL Kano 0x0064C750: charged dual-effect special; tail codegen OPEN
        if (field000a == 0 && field000c == 0) {
            dashMomentumFlag = 0;
            ResetFrame();
            pendingCharacterSoundSlot = 0;
        }
        if (field000a > 2 && field000a < 7) {
            field3150 += 75;
            ++field3138;
            if (field3150 > 10000)
                field3150 = 10000;
        }
        if ((field000a > 2 && field000a < 7 && buttonPulse[3] == 1) ||
            (field3150 >= 10000 && field000a < 7)) {
            field000c = 0;
            field000a = 7;
            return;
        }
        if (field000a == 3 && field000c == 0) {
            effect.type = 0x196;
            effect.x = (double)(int)positionX;
            effect.y = (double)(int)positionY;
            effect.group = 2;
            effect.layer = 1;
            effect.flag0018 = (unsigned char)facing;
            EmitLocalEffect(&effect);
            effect.type = 0x197;
            effect.x = (double)(int)positionX;
            effect.y = (double)(int)positionY;
            effect.group = 2;
            effect.layer = 0;
            effect.flag0018 = (unsigned char)facing;
            EmitLocalEffect(&effect);
        }
        ++field000c;
        if (field000c >= timing.frameDuration) {
            field000c = 0;
            ++field000a;
            attackCollisionResult = 0;
            if (field000a == 7)
                field000a = (unsigned short)(field000a - 4);
            if (field000a >= timing.animationFrameCount) {
                field0008 = 0;
                ResetPose();
            }
        }
        return;

    case 251: // EXPERIMENTAL Kano 0x0064C999: special resource drain and dual effect
        if (field000a == 0 && field000c == 0) {
            dashMomentumFlag = 0;
            ResetFrame();
        }
        ++field000c;
        if (field000c >= timing.frameDuration) {
            field000c = 0;
            ++field000a;
            attackCollisionResult = 0;
            if (field000a == 3) {
                remainingHitCount = 1;
                if (field0120 == 0)
                    field0118 -= 500.0;
                else
                    field0118 -= 250.0;
                field3150 = 10000;
                effect.type = 0x198;
                effect.x = (double)(int)positionX;
                effect.y = (double)((int)positionY - 40);
                effect.group = 2;
                effect.layer = 1;
                effect.flag0018 = (unsigned char)facing;
                EmitLocalEffect(&effect);
                effect.type = 0x197;
                effect.x = (double)(int)positionX;
                effect.y = (double)(int)positionY;
                effect.group = 2;
                effect.layer = 0;
                effect.flag0018 = (unsigned char)facing;
                EmitLocalEffect(&effect);
                pendingCharacterSoundSlot = 1;
            }
            if (field000a >= timing.animationFrameCount) {
                field0008 = 0;
                ResetPose();
            }
        }
        return;

    case 254: // EXPERIMENTAL Kano 0x0064CB5F: charged dual-effect finisher and cancellable launcher
        if (field000a == 0 && field000c == 0) {
            dashMomentumFlag = 0;
            ResetFrame();
            pendingCharacterSoundSlot = 0;
        }
        if (field000a == 3 && field000c == 0) {
            effect.type = 0x196;
            effect.x = (double)(int)positionX;
            effect.y = (double)(int)positionY;
            effect.group = 2;
            effect.layer = 1;
            effect.flag0018 = (unsigned char)facing;
            EmitLocalEffect(&effect);
            effect.type = 0x197;
            effect.x = (double)(int)positionX;
            effect.y = (double)(int)positionY;
            effect.group = 2;
            effect.layer = 0;
            effect.flag0018 = (unsigned char)facing;
            EmitLocalEffect(&effect);
        }
        if (field000a == 7 && field000c == 0) {
            dashMomentumFlag = 0;
            ResetFrame();
        }
        if (field000a > 2 && field000a < 7)
            field3150 += 75;
        if (field000a > 2 && field000a < 7 && field3150 >= 10000) {
            field3150 = 7500;
            field000a = 7;
            field000c = 0;
            return;
        }
        if (field000a > 15 && recognizedCommand == 13 &&
            (field0118 >= 500.0 || field0120 > 0)) {
            ResetPose();
            ResetFrame();
            field0008 = 251;
            return;
        }
        ++field000c;
        if (field000c >= timing.frameDuration) {
            field000c = 0;
            ++field000a;
            attackCollisionResult = 3;
            if (field000a == 7)
                field000a = (unsigned short)(field000a - 4);
            if (field000a == 16 && field3138 < 1) {
                effect.type = 0x1bb;
                effect.x = (double)((int)positionX +
                   ((int)facing * 150 + (int)inputX * 70));
                effect.y = 0.0;
                effect.group = 2;
                effect.layer = 1;
                effect.owner = 1;
                effect.flag0018 = (unsigned char)facing;
                EmitLocalEffect(&effect);
                pendingCharacterSoundSlot = 3;
                ++field3170;
            }
            if (field000a >= timing.animationFrameCount) {
                field0008 = 0;
                ResetPose();
            }
        }
        return;

    }
}
