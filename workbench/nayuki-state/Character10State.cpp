// Nayuki Character10::Slot06 state boss — selected native partial reconstruction.
// Original owner at 0x00451850 contains 62,693 code bytes and two adjacent
// 552/306-byte switch tables. Only the opening states are reviewed.
// Remaining states use Makoto-derived experimental scaffolding and are NOT Exact.
// The 19 missing Nayuki-specific states must still be authored, not bypassed.
#include "../../src/CharacterViews.h"

void Character10::Slot06()
{
    // Nayuki target entry 0x00451850: stop this tick if either fighter freezes it.
    if (hitstopFrames > 0 || (*opponentSlot)->hitstunFrames > 0) return;

    // 0x00451883: construct the effect spawn, snapshot this frame's duration
    // and the animation's frame count, then initialize the spawn's defaults.
    EffectSpawn effect;
    // Original VC7.1 frame cache uses two separate, four-byte-aligned
    // 16-bit stack homes at [ebp-0x8] and [ebp-0x4]. Keeping these
    // together restores EffectSpawn's [ebp-0x50] home and the frame size.
    struct FrameTiming {
        __declspec(align(4)) unsigned short animationFrameCount;
        __declspec(align(4)) unsigned short frameDuration;
    } timing;
    timing.frameDuration = patterns[field0008].frames[field000a].duration;
    timing.animationFrameCount = patterns[field0008].count;
    ResetLocalEffectSpawn(&effect);

    // The original selector at 0x00460F5D is an animation-ID-to-case map.
    // Do not treat a sibling character's normalized case labels as Nayuki IDs.
    switch (field0008) {
    default: // Original Nayuki fallback at 0x004518FD for 169 unmapped IDs
        // The original selector maps 169 IDs here; the default is not a no-op.
        velocityX = 0.0;
        velocityY = 0.0;
        ++field000c;
        if (field000c >= timing.frameDuration) {
            field000c = 0;
            ++field000a;
            if (field000a >= timing.animationFrameCount) {
                field000a = 0;
            }
        }
        return;

    case 1: // Reviewed Nayuki state at 0x0045196E
        dashMomentumFlag = 0;
        velocityX = (double)field3148 * 0.02 + 0.6;
        velocityY = 0.0;
        ++field000c;
        if (field000c >= timing.frameDuration) {
            field000c = 0;
            ++field000a;
            if (field000a >= timing.animationFrameCount) {
                field000a = 0;
            }
        }
        return;

    case 2: // Reviewed Nayuki state at 0x004519F8
        dashMomentumFlag = 0;
        velocityX = -0.6 - (double)field3148 * 0.02;
        velocityY = 0.0;
        ++field000c;
        if (field000c >= timing.frameDuration) {
            field000c = 0;
            ++field000a;
            if (field000a >= timing.animationFrameCount) {
                field000a = 0;
            }
        }
        return;

    case 3: // Reviewed Nayuki state at 0x00451A82
        velocityX = 0.0;
        velocityY = 0.0;
        FaceOpponent();
        ++field000c;
        if (field000c >= timing.frameDuration) {
            field000c = 0;
            ++field000a;
            if (field000a >= timing.animationFrameCount) {
                field000a = 0;
            }
        }
        return;

    case 4: // Reviewed Nayuki state at 0x00451AFB
        if (field000a == 0 && field000c == 0) {
            FaceOpponent();
            velocityX = 0.0;
        }
        if (field000a == 3 && field000c == 0) {
            gravity = 0.024;
            velocityY = -2.0;
            if ((unsigned char)dashMomentumFlag == 1) {
                velocityX = 0.4;
                dashMomentumFlag = 0;
            }
        }
        if (field000a > 3) velocityY += gravity;

        ++field000c;
        if (field000c >= timing.frameDuration) {
            field000c = 0;
            ++field000a;
            if (field000a >= timing.animationFrameCount) {
                field0008 = 9;
                ResetPose();
            }
        }

        // Landing is checked after the animation counters advance.
        // On the original path the sound request precedes FaceOpponent.
        if (positionY + velocityY >= 0.0 && field000a > 4) {
            positionY = 0.0;
            pendingContextSoundSlot = 9;
            FaceOpponent();
            field0008 = 13;
            ResetPose();
        }
        return;

    case 5: // Reviewed Nayuki state at 0x00451C50
        if (field000a == 0 && field000c == 0) {
            FaceOpponent();
            velocityX = 0.0;
        }
        if (field000a == 3 && field000c == 0) {
            gravity = 0.024;
            velocityY = -2.0;
            velocityX = 0.5;
            if ((unsigned char)dashMomentumFlag == 1) {
                velocityX = 0.7;
                dashMomentumFlag = 0;
            }
        }
        if (field000a > 3) velocityY += gravity;

        ++field000c;
        if (field000c >= timing.frameDuration) {
            field000c = 0;
            ++field000a;
            if (field000a >= timing.animationFrameCount) {
                // Unlike case 4, do not change animation or ResetPose here.
                // The last two pose frames repeat while airborne.
                field0008 = 9;
                ResetPose();
            }
        }

        if (positionY + velocityY >= 0.0 && field000a > 4) {
            positionY = 0.0;
            pendingContextSoundSlot = 9;
            FaceOpponent();
            field0008 = 13;
            ResetPose();
        }
        return;

    case 6: // Reviewed Nayuki state at 0x00451DB1
        if (field000a == 0 && field000c == 0) {
            FaceOpponent();
            velocityX = 0.0;
        }
        if (field000a == 3 && field000c == 0) {
            gravity = 0.024;
            velocityY = -2.0;
            velocityX = -0.5;
            // Unlike case 5, this direction has no dashMomentumFlag override.
        }
        if (field000a > 3) velocityY += gravity;

        ++field000c;
        if (field000c >= timing.frameDuration) {
            field000c = 0;
            ++field000a;
            if (field000a >= timing.animationFrameCount) {
                field0008 = 9;
                ResetPose();
            }
        }

        if (positionY + velocityY >= 0.0 && field000a > 4) {
            positionY = 0.0;
            pendingContextSoundSlot = 9;
            FaceOpponent();
            field0008 = 13;
            ResetPose();
        }
        return;

    case 7: // Reviewed Nayuki state at 0x00451EED
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

    case 8: // Reviewed Nayuki state at 0x00451F70
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

    case 9: // Reviewed Nayuki state at 0x00451FF3
        velocityY += gravity;
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

    case 13: // Reviewed Nayuki state at 0x004520A0
        velocityX = 0.0;
        velocityY = 0.0;
        FaceOpponent();
        ++field000c;
        if (field000c >= timing.frameDuration) {
            field000c = 0;
            ++field000a;
            if (field000a >= timing.animationFrameCount) {
                // The original tests inputY (+0x189) after selecting state 0.
                field0008 = 7;
                if (inputY == 1) field0008 = 3;
                ResetPose();
            }
        }
        return;

    case 14: // Reviewed Nayuki state at 0x0045213B
        gravity = 0.024;
        if (field000a == 0 && field000c == 0) {
            velocityY = -2.0;
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

    case 15: // Reviewed Nayuki state at 0x00452265
        gravity = 0.024;
        if (field000a == 0 && field000c == 0) {
            velocityY = -2.0;
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

    case 16: // Reviewed Nayuki state at 0x0045238F
        gravity = 0.024;
        if (field000a == 0 && field000c == 0) {
            velocityY = -2.0;
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

    case 47: // Reviewed Nayuki state at 0x004524AD
        if (field000a == 0 && field000c == 0) {
            velocityX = 0.6;
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

    case 50: // Reviewed Nayuki state at 0x004525DD
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

    case 51: // Reviewed Nayuki state at 0x004527C4
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

    case 52: // Reviewed Nayuki state at 0x004529AB
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

    case 53: // Reviewed Nayuki state at 0x00452B92
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

    case 54: // Reviewed Nayuki state at 0x00452D79
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

    case 55: // Reviewed Nayuki state at 0x00452F60
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

    case 56: // Reviewed Nayuki state at 0x00453147
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

    case 57: // Reviewed Nayuki state at 0x00453316
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

    case 58: // Reviewed Nayuki state at 0x004534E5
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

    case 59: // Reviewed Nayuki state at 0x004536B4
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

    case 60: // Reviewed Nayuki state at 0x004538B3
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

    case 61: // Reviewed Nayuki state at 0x00453AB2
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

    case 62: // Reviewed Nayuki state at 0x00453CB1
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

    case 63: // Reviewed Nayuki state at 0x00453E68
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

    case 64: // Reviewed Nayuki state at 0x00454013
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

    case 65: // Reviewed Nayuki state at 0x00454244
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

    case 66: // Reviewed Nayuki state at 0x00454475
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

    case 67: // Reviewed Nayuki state at 0x0045465E
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

    case 68: // Reviewed Nayuki state at 0x0045483B
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

    case 69: // Reviewed Nayuki state at 0x00454977
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

    case 70: // Reviewed Nayuki state at 0x00454A8C
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

    case 71: // Reviewed Nayuki state at 0x00454C6C
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

    case 72: // Reviewed Nayuki state at 0x00454E17
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

    case 73: // Reviewed Nayuki state at 0x00454F62
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

    case 74: // Reviewed Nayuki state at 0x004550AD
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

    case 75: // Reviewed Nayuki state at 0x004551E0
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

    case 76: // Reviewed Nayuki state at 0x004553D3
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

    case 77: // Reviewed Nayuki state at 0x004555C6
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

    case 81: // Reviewed Nayuki state at 0x004557A1
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

    case 82: // Reviewed Nayuki state at 0x00455986
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

    case 83: // Reviewed Nayuki state at 0x00455BA8
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

    case 84: // Reviewed Nayuki state at 0x00455DED
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

    case 85: // Reviewed Nayuki state at 0x00456032
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

    case 86: // Reviewed Nayuki state at 0x00456205
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

    case 87: // Reviewed Nayuki state at 0x004563E7
        if (field000a == 0 && field000c == 0) {
            effect.type = 0x1ef;
            effect.x = 60.0;
            effect.y = 40.0;
            effect.payload = 1;
            effect.flag0018 = 1;
            effect.group = 0;
            effect.layer = 1;
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

    case 96: // Reviewed Nayuki state at 0x0045649A
        if (field000a == 1 && field000c == 0 && field3148 > 0)
            --field3148;
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

    case 97: // Reviewed Nayuki state at 0x00456567
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

    case 98: // Reviewed Nayuki state at 0x0045665F
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

    case 99: // Reviewed Nayuki state at 0x00456757
        // The target deliberately checks the tick count without a pose gate.
        if (health > 0 && field000c > 99) {
            field0008 = 96;
            ResetPose();
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

    case 123: // Reviewed Nayuki state at 0x004567FC
        velocityX = 0.0;
        velocityY = 0.0;
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

    case 150: // Reviewed Nayuki state at 0x00456877
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

    case 151: // Reviewed Nayuki state at 0x004569E9
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

    case 152: // Reviewed Nayuki state at 0x00456B5B
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

    case 153: // Reviewed Nayuki state at 0x00456CCD
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

    case 154: // Reviewed Nayuki state at 0x00456E27
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

    case 155: // Reviewed Nayuki state at 0x00456F81
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

    case 156: // Reviewed Nayuki state at 0x004570DB
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

    case 157: // Reviewed Nayuki state at 0x004571EB
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

    case 158: // Reviewed Nayuki state at 0x00457337
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

    case 161: // Reviewed Nayuki state at 0x00457483
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

    case 162: // Reviewed Nayuki state at 0x00457597
        if (field000a == 0 && field000c == 0) {
            ResetFrame();
        }
        if (field000a == 3 && field000c == 0) {
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
            if (field000a == 13) {
                gravity = 0.035;
            }
            if (field000a >= timing.animationFrameCount) {
                field000a = (unsigned short)(field000a - 2);
            }
        }
        return;

    case 163: // Reviewed Nayuki state at 0x00457782
        if (field000a == 0 && field000c == 0) {
            StartTrail(1);
            ResetFrame();
        }
        if (field000a < 11 && field000a > 4)
            velocityY += gravity;
        if (positionY + velocityY > 0.0 && field000a < 11) {
            field000c = 0;
            ResetFrame();
            field000a = 11;
            positionY = 0.0;
            return;
        }
        ++field000c;
        if (field000c >= timing.frameDuration) {
            field000c = 0;
            ++field000a;
            if (field000a == 5) {
                velocityX = 1.4;
                velocityY = -0.75;
                gravity = 0.015;
            }
            if (field000a == 11)
                field000a = (unsigned short)(field000a - 4);
            if (field000a >= timing.animationFrameCount) {
                field0008 = 3;
                ResetPose();
                return;
            }
        }
        return;

    case 164: // Reviewed Nayuki state at 0x004578DD
        StartTrail(2);
        if (field000a == 0 && field000c == 0)
            ResetFrame();
        if (field000a > 3) {
            velocityX += 0.02;
            velocityY += 0.035;
        }
        if (velocityX > 0.0)
            velocityX = 0.0;
        if (positionY + velocityY > 0.0 && field000a < 11) {
            positionY = 0.0;
            ResetFrame();
            field000c = 0;
            field000a = 11;
            return;
        }
        ++field000c;
        if (field000c >= timing.frameDuration) {
            field000c = 0;
            ++field000a;
            if (field000a == 4) {
                velocityX = -2.0 - (double)field3148 * 0.1;
                velocityY = -1.2;
            }
            if (field000a == 11)
                field000a = (unsigned short)(field000a - 2);
            if (field000a >= timing.animationFrameCount) {
                ResetPose();
                field0008 = 3;
            }
        }
        return;

    case 165: // Reviewed Nayuki state at 0x00457A5B
        if (field000a == 0 && field000c == 0) {
            if (field3148 > 7)
                remainingHitCount = 1;
            else
                remainingHitCount = 0;
            ResetFrame();
            effect.type = 0x190;
            effect.x = (double)((int)positionX - (int)facing * 36);
            effect.y = (double)((int)positionY - 62);
            effect.flag0018 = (unsigned char)facing;
            effect.layer = 0;
            effect.group = 0;
            EmitLocalEffect(&effect);
        }
        if (field3138 == 1 && field000a == 0) {
            velocityX = 1.9;
            velocityY = -0.2;
            gravity = 0.035;
            field000c = 0;
            field000a = 1;
            return;
        }
        if (field000a > 0)
            velocityY += gravity;
        if (velocityY + positionY > 0.0) {
            positionY = 0.0;
            ResetFrame();
            ResetPose();
            field0008 = 0xb3;
            return;
        }
        ++field000c;
        if (field000c >= timing.frameDuration) {
            field000c = 0;
            ++field000a;
            if (field000a >= timing.animationFrameCount)
                field000a = (unsigned short)(field000a - 2);
        }
        return;

    case 166: // Reviewed Nayuki state at 0x00457C25
        if (field000a == 0 && field000c == 0) {
            ResetFrame();
            if (field3148 > 4)
                remainingHitCount = 1;
            else
                remainingHitCount = 0;
            effect.type = 0x190;
            effect.x = (double)((int)positionX + (int)facing * 36);
            effect.y = (double)((int)positionY - 62);
            effect.flag0018 = -(int)facing;
            effect.layer = 1;
            effect.group = 0;
            EmitLocalEffect(&effect);
        }
        if (field3138 == 1 && field000a == 0) {
            velocityX = -1.9;
            velocityY = -0.2;
            gravity = 0.035;
            field000c = 0;
            field000a = 1;
            return;
        }
        if (field000a > 0)
            velocityY += gravity;
        if (velocityY + positionY > 0.0) {
            positionY = 0.0;
            ResetFrame();
            ResetPose();
            field0008 = 0xb3;
            return;
        }
        ++field000c;
        if (field000c >= timing.frameDuration) {
            field000c = 0;
            ++field000a;
            if (field000a >= timing.animationFrameCount)
                field000a = (unsigned short)(field000a - 2);
        }
        return;

    case 167: // Reviewed Nayuki state at 0x00457DF2
        if (field000a == 0 && field000c == 0) {
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

    case 168: // Reviewed Nayuki state at 0x00457FCC
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

    case 169: // Reviewed Nayuki state at 0x0045810C
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

    case 170: // Reviewed Nayuki state at 0x0045824C
        if (field000a == 0 && field000c == 0) {
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

    case 171: // Reviewed Nayuki state at 0x00458415
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
        // The first impact effect occurs at frame 1, not on entry frame 0.
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
                FaceOpponent();
                velocityX = (double)field3138 * 0.01;
                velocityY = (double)field313c * 0.01;
                gravity = 0.035;
                ResetPose();
            }
        }
        return;

    case 178: // Reviewed Nayuki state at 0x00458665
        velocityX -= 0.03;
        velocityX = velocityX;
        if (velocityX < 0.0) {
            velocityX = 0.0;
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

    case 179: // Reviewed Nayuki state at 0x00458787
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
            if (field000a == timing.animationFrameCount - 1)
                FaceOpponent();
            if (field000a >= timing.animationFrameCount) {
                field0008 = 7;
                if (inputY == 1)
                    field0008 = 3;
                ResetPose();
            }
        }
        return;

    case 180: // Reviewed Nayuki state at 0x004588B1
        if (field000a == 0 && field000c == 0) {
            StartTrail(2);
            velocityX = 0.0;
            velocityY = 0.0;
            gravity = 0.0;
        }
        if (positionY < 0.0) {
            velocityY += gravity;
        }
        if (positionY + velocityY > 0.0 && field000a < 11) {
            ResetFrame();
            positionY = 0.0;
            field000c = 0;
            field000a = 11;
            pendingContextSoundSlot = 9;
        }
        ++field000c;
        if (field000c >= timing.frameDuration) {
            field000c = 0;
            ++field000a;
            if (field000a == 4) {
                velocityX = -0.5;
                velocityY = -1.0;
                gravity = 0.028;
            }
            if (field000a == 11) {
                field000a = (unsigned short)(field000a - 2);
            }
            if (field000a >= timing.animationFrameCount) {
                ResetPose();
                field0008 = 0;
            }
        }
        return;

    case 200: // Reviewed Nayuki state at 0x00458A23
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
            meter = (short)(meter + 5);
            pendingContextSoundSlot = 21;
            remainingHitCount = 1;
        }
        ++field000c;
        if (field000c >= timing.frameDuration) {
            field000c = 0;
            ++field000a;
            if (field000a < 2) {
                attackCollisionResult = 0;
            }
            if (field000a >= timing.animationFrameCount) {
                field0008 = 0;
                FaceOpponent();
                ResetPose();
            }
        }
        return;

    case 201: // Reviewed Nayuki state at 0x00458BF6
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
            meter = (short)(meter + 15);
            pendingContextSoundSlot = 20;
            remainingHitCount = 1;
        }
        ++field000c;
        if (field000c >= timing.frameDuration ||
            (field000c >= timing.frameDuration - 3 &&
             field000a == 2 && field3148 > 4)) {
            field000c = 0;
            ++field000a;
            if (field000a == 3)
                field000a = 4;
            if (field000a == 2 && field3148 > 3)
                field000a = 3;
            if (field000a < 2) {
                attackCollisionResult = 0;
            }
            if (field000a >= timing.animationFrameCount) {
                field0008 = 0;
                FaceOpponent();
                ResetPose();
            }
        }
        return;

    case 202: // Original Nayuki 0x00458E35: airborne multi-hit, rebound and landing impact
        if (field000a == 0 && field000c == 0)
            ResetFrame();
        if (field000a == 3 && field000c == 0)
            remainingHitCount = 0;
        if (field000a == 4 && field000c == 0) {
            meter = (short)(meter + 15);
            pendingContextSoundSlot = 20;
            if (field3148 > 5)
                remainingHitCount = 1;
        }
        if (field000a == 5 && field000c == 0)
            remainingHitCount = 8;
        if (field000a < 10 && field000a > 5)
            velocityY += gravity;
        if (velocityY + positionY > 0.0) {
            positionY = 0.0;
            field000c = 0;
            if (field000a < 10 && field000a > 5) {
                field000a = 10;
                SetVerticalShake(3, 0);
                effect.type = 3;
                effect.x = (double)((int)positionX + (int)facing * 30);
                effect.y = (double)(int)positionY;
                effect.group = 2;
                effect.layer = 0;
                contextOwner->EmitEffect(&effect);
                pendingContextSoundSlot = 7;
            }
            velocityY = 0.0;
        }
        if (field000a >= 10) {
            velocityX -= 0.035;
            if (velocityX < 0.0)
                velocityX = 0.0;
        }
        ++field000c;
        if (field000c >= timing.frameDuration) {
            field000c = 0;
            ++field000a;
            if (field000a == 5) {
                velocityY = -1.5;
                velocityX = (double)field3148 * 0.05 + 1.0;
                gravity = 0.06;
            }
            if (field000a == 10)
                field000a = (unsigned short)(field000a - 4);
            if (field000a == 11) {
                if (field3148 > 4)
                    remainingHitCount = 1;
                else
                    remainingHitCount = 0;
            }
            if (field000a == 4 || field000a == 5 || field000a == 7 ||
                field000a == 9 || field000a == 11)
                attackCollisionResult = 0;
            if (field000a >= timing.animationFrameCount) {
                field0008 = 0;
                FaceOpponent();
                ResetPose();
            }
        }
        return;

    case 203: // Nayuki original 0x0045916C: airborne cancel, delayed recoil and launch
        if (field000a == 0 && field000c == 0) {
            ResetFrame();
            remainingHitCount = 0;
        }
        if (inputY == -1 && field000a > 0 && field3148 > 4 &&
            positionY == 0.0 && field015c < 3 &&
            attackCollisionResult >= 2 && field3148 > 6) {
            field0008 = 4;
            if (inputX == facing)
                field0008 = 5;
            if ((int)inputX == -(int)facing)
                field0008 = 6;
            attackCollisionResult = 0;
            ResetPose();
            return;
        }
        if (field000a == 8 && field000c == 0) {
            meter = (short)(meter + 35);
            pendingContextSoundSlot = 20;
            if (field3148 > 5)
                remainingHitCount = 1;
        }
        if (field000a == 10 && field000c == 0)
            remainingHitCount = 1;
        if (field000a > 13)
            velocityY += gravity;
        if (field000a > 13 && velocityY + positionY > 0.0) {
            ResetPose();
            field0008 = 13;
            return;
        }
        ++field000c;
        if (field000c >= timing.frameDuration) {
            field000c = 0;
            ++field000a;
            if (field000a == 10)
                pendingCharacterSoundSlot = 3;
            if (field000a < 9)
                attackCollisionResult = 0;
            if (field000a == 8 || field000a == 9 || field000a == 10)
                positionX += (double)((int)facing * 40);
            if (field000a == 14) {
                velocityY = -1.0;
                velocityX = 0.7;
                gravity = 0.033;
            }
            if (field000a >= timing.animationFrameCount)
                --field000a;
        }
        return;

    case 204: // Reviewed Nayuki original 0x00459441: recovery and state3148 gate
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
            meter = (short)(meter + 5);
            pendingContextSoundSlot = 21;
            remainingHitCount = 1;
        }
        ++field000c;
        if (field000c >= timing.frameDuration) {
            field000c = 0;
            ++field000a;
            if (field000a == 3)
                field000a = 4;
            if (field000a == 2 && field3148 > 4)
                field000a = 3;
            if (field000a < 2) {
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

    case 205: // Original Nayuki 0x00459666: accelerated frame gates and dash shift
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
            meter = (short)(meter + 13);
            pendingContextSoundSlot = 20;
            remainingHitCount = 1;
        }
        ++field000c;
        if (field000c >= timing.frameDuration ||
            (field000c >= 3 &&
             ((field000a == 1 && field3148 > 0) ||
              (field000a == 2 && field3148 > 1) ||
              (field000a == 3 && field3148 > 3) ||
              (field000a == 4 && field3148 > 5)))) {
            field000c = 0;
            ++field000a;
            attackCollisionResult = 0;
            if (field000a == 1)
                positionX += (double)((int)facing * 15);
            if (field000a == 2)
                positionX += (double)((int)facing * 15);
            if (field000a >= timing.animationFrameCount) {
                field0008 = 3;
                FaceOpponent();
                ResetPose();
            }
        }
        return;

    case 206: // Reviewed Nayuki 0x00459901: dash cancel, meter gain and adaptive frame skip
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
        ++field000c;
        if (field000c >= timing.frameDuration ||
            (field000c >= timing.frameDuration - 3 &&
             field000a < field3148 - 4 && field000a < 4)) {
            field000c = 0;
            ++field000a;
            if (field000a < 2)
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

    case 207: // Reviewed Nayuki state at 0x00459B29
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
            if (field000a < 2) {
                attackCollisionResult = 0;
            }
            if (field000a >= timing.animationFrameCount) {
                field0008 = 9;
                ResetPose();
            }
        }
        return;

    case 208: // Reviewed Nayuki 0x00459CFF: scaled multi-hit count for aerial attack
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
            meter = (short)(meter + 13);
            pendingContextSoundSlot = 20;
            remainingHitCount = (short)(field3148 / 2 + 2);
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
            if (field000a < 6) {
                attackCollisionResult = 0;
            }
            if (field000a >= timing.animationFrameCount) {
                field0008 = 9;
                ResetPose();
            }
        }
        return;

    case 209: // Reviewed Nayuki 0x00459EE4: accelerated aerial timing and landing
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
            meter = (short)(meter + 30);
            pendingContextSoundSlot = 20;
            remainingHitCount = 3;
        }
        if (positionY + velocityY >= 0.0) {
            positionY = 0.0;
            field0008 = 13;
            ResetPose();
            return;
        }
        ++field000c;
        if (field000c >= timing.frameDuration ||
            (field000c >= timing.frameDuration - 3 &&
             field000a < field3148 - 3 && field000a < 4)) {
            field000c = 0;
            ++field000a;
            if (field000a < 2)
                attackCollisionResult = 0;
            if (field000a >= timing.animationFrameCount) {
                field0008 = 9;
                ResetPose();
            }
        }
        return;

    case 210: // Reviewed Nayuki original 0x0045A0F0: four-frame launcher and landing recovery
        if (field000a == 0 && field000c == 0)
            ResetFrame();
        if (field000a == 4 && field000c == 0) {
            gravity = 0.055;
            velocityY = -1.7;
            velocityX = 0.5;
            remainingHitCount = 1;
        }
        if (field000a > 4)
            velocityY += gravity;
        if (field000a == 8 && field000c == 0)
            pendingContextSoundSlot = 20;
        ++field000c;
        if (field000c >= timing.frameDuration) {
            field000c = 0;
            ++field000a;
            if (field000a >= timing.animationFrameCount) {
                ResetPose();
                field0008 = 3;
                FaceOpponent();
                return;
            }
        }
        if (positionY + velocityY >= 0.0 && field000a > 4 &&
            field000a < 11) {
            positionY = 0.0;
            pendingContextSoundSlot = 9;
            field000a = 11;
            field000c = 0;
            ResetFrame();
        }
        return;

    case 211: // Reviewed Nayuki 0x0045A265: grounded cancel and frame-3 activation
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
        if (field000a == 3 && field000c == 0) {
            meter = (short)(meter + 30);
            pendingContextSoundSlot = 20;
            remainingHitCount = 1;
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

    case 212: // Reviewed Nayuki 0x0045A3E8: aerial rebound, counter transition and landing effect
        if (field000a == 2 && field000c == 0) {
            meter = (short)(meter + 15);
            pendingContextSoundSlot = 20;
            remainingHitCount = 1;
            velocityY -= -1.0;
            gravity = 0.035;
        }
        velocityY += gravity;
        if (attackCollisionResult > 1) {
            field000c = 0;
            field000a = 0;
            field0008 = 257;
            velocityX = -velocityX;
            velocityY = -2.5;
            gravity = 0.025;
            return;
        }
        if (velocityY + positionY > 0.0 && field000a < 5 &&
            field000a > 1) {
            positionY = 0.0;
            field000c = 0;
            field000a = 5;
            SetVerticalShake(3, 0);
            effect.type = 3;
            effect.x = (double)((int)positionX + (int)facing * 30);
            effect.y = (double)(int)positionY;
            effect.group = 2;
            effect.layer = 0;
            contextOwner->EmitEffect(&effect);
            pendingContextSoundSlot = 7;
            velocityX = 0.0;
            velocityY = 0.0;
            return;
        }
        ++field000c;
        if (field000c >= timing.frameDuration) {
            field000c = 0;
            ++field000a;
            if (field000a == 5)
                --field000a;
            attackCollisionResult = 0;
            if (field000a >= timing.animationFrameCount) {
                field0008 = 7;
                FaceOpponent();
                ResetPose();
            }
        }
        return;

    case 213: // Reviewed Nayuki original 0x0045A62F: airborne recovery and grounded wakeup
        gravity = 0.04;
        velocityX = 0.0;
        velocityY += gravity;
        if (field000a == 3 && field000c == 0) {
            meter = (short)(meter + 30);
            pendingContextSoundSlot = 20;
            remainingHitCount = 1;
        }
        if (positionY + velocityY >= 0.0) {
            positionY = 0.0;
            field0008 = 97;
            ResetFrame();
            ResetPose();
            return;
        }
        ++field000c;
        if (field000c >= timing.frameDuration) {
            field000c = 0;
            ++field000a;
            attackCollisionResult = 0;
            if (field000a >= timing.animationFrameCount)
                field000a = (unsigned short)(field000a - 2);
        }
        return;

    case 214: // Reviewed Nayuki original 0x0045A750: airborne slam and landing frame skip
        velocityY += gravity;
        if (field000a == 2 && field000c == 0) {
            meter = (short)(meter + 30);
            pendingContextSoundSlot = 20;
            remainingHitCount = 3;
        }
        if (positionY + velocityY > 0.0) {
            positionY = 0.0;
            field000c = 0;
            ResetFrame();
            field000a = 10;
            return;
        }
        ++field000c;
        if (field000c >= timing.frameDuration) {
            field000c = 0;
            ++field000a;
            attackCollisionResult = 0;
            if (field000a >= timing.animationFrameCount) {
                field0008 = 7;
                ResetPose();
            }
        }
        return;

    case 220: // Reviewed Nayuki 0x0045A85A: grounded grab, wall clamp and impact effect
        velocityX = 0.0;
        velocityY = 0.0;
        if (field000a == 1 && field000c == 0 &&
            (*opponentSlot)->positionY == 0.0) {
            remainingHitCount = 1;
        } else {
            remainingHitCount = 0;
        }
        if (field000a == 1 && attackCollisionResult == 3) {
            if (positionX > 600.0)
                positionX = 600.0;
            if (positionX < 40.0)
                positionX = 40.0;
            velocityX = 0.0;
            velocityY = 0.0;
            outgoingPushbackVelocityX = 0.0;
            ResetPose();
            (*opponentSlot)->ResetPose();
            (*opponentSlot)->ResetFrame();
            field0008 = 221;
            (*opponentSlot)->field0008 = 107;
            (*opponentSlot)->positionX = positionX + (double)((int)facing * 15);
            effect.type = 0;
            effect.x = (double)((int)positionX + (int)facing * 37);
            effect.y = (double)((int)positionY - 22);
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
            if (field000a >= timing.animationFrameCount) {
                field0008 = 0;
                FaceOpponent();
                ResetPose();
            }
        }
        return;

    case 221: // Reviewed Nayuki 0x0045AA88: throw impact, opponent trajectory and drag
        if (field000a == 4 && field000c == 0) {
            ApplyDamage(1000, 750.0);
            (*opponentSlot)->field0008 = 63;
            (*opponentSlot)->ResetPose();
            (*opponentSlot)->ResetFrame();
            (*opponentSlot)->knockbackVelocityX = 1.0;
            (*opponentSlot)->knockbackVelocityY = -2.5;
            (*opponentSlot)->positionY = -50.0;
            (*opponentSlot)->positionX = positionX;
        }
        ++field000c;
        if (field000c >= timing.frameDuration) {
            field000c = 0;
            ++field000a;
            attackCollisionResult = 0;
            if (field000a == 1)
                (*opponentSlot)->positionX -= (double)(int)facing;
            if (field000a == 2)
                (*opponentSlot)->positionX -= (double)(int)facing;
            if (field000a == 3)
                (*opponentSlot)->positionX -= (double)(int)facing;
            if (field000a >= timing.animationFrameCount) {
                field0008 = 0;
                ResetPose();
                FaceOpponent();
            }
        }
        return;

    case 230: // Reviewed Nayuki 0x0045AC54: aerial action cancel, frame2 hit
        velocityY += gravity;
        if (inputY == -1 && field000a > 0 &&
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
            if (field000a < 2) {
                attackCollisionResult = 0;
            }
            if (field000a >= timing.animationFrameCount) {
                field0008 = 9;
                ResetPose();
            }
        }
        return;

    case 231: // Reviewed Nayuki 0x0045AE1B: aerial cancel and tier-scaled hit
        velocityY += gravity;
        if (inputY == -1 && field000a > 0 &&
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
            meter = (short)(meter + 13);
            pendingContextSoundSlot = 20;
            remainingHitCount = (short)(field3148 / 2 + 2);
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
            if (field000a < 6) {
                attackCollisionResult = 0;
            }
            if (field000a >= timing.animationFrameCount) {
                field0008 = 9;
                ResetPose();
            }
        }
        return;

    case 232: // Reviewed Nayuki 0x0045AFF0: airborne chained attack with accelerated frame gate
        velocityY += gravity;
        if (inputY == -1 && field000a > 0 &&
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
            meter = (short)(meter + 30);
            pendingContextSoundSlot = 20;
            remainingHitCount = 3;
        }
        if (positionY + velocityY >= 0.0) {
            positionY = 0.0;
            field0008 = 13;
            ResetPose();
            return;
        }
        ++field000c;
        if (field000c >= timing.frameDuration ||
            (field000c >= timing.frameDuration - 3 &&
             field000a < field3148 - 3 && field000a < 4)) {
            field000c = 0;
            ++field000a;
            if (field000a < 2)
                attackCollisionResult = 0;
            if (field000a >= timing.animationFrameCount) {
                field0008 = 9;
                ResetPose();
            }
        }
        return;

    case 248: // Reviewed Nayuki 0x0045B1EB: aerial grab and opponent impact positioning
        velocityY += gravity;
        if (field000a == 1 && attackCollisionResult == 3) {
            (*opponentSlot)->ResetFrame();
            (*opponentSlot)->ResetPose();
            ResetPose();
            ResetFrame();
            field0008 = 249;
            (*opponentSlot)->field0008 = 100;
            effect.type = 0;
            effect.x = (double)((int)positionX + (int)facing * 33);
            effect.y = (double)((int)positionY - 51);
            effect.group = 2;
            effect.layer = 1;
            contextOwner->EmitEffect(&effect);
            (*opponentSlot)->positionX = positionX + (double)((int)facing * 33);
            (*opponentSlot)->positionY = positionY - 61.0;
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

    case 249: // Reviewed Nayuki 0x0045B3DD: airborne grapple carry and opponent launch
        if (field000a < 7)
            SetHorizontalOffset(50, 3);
        if (field000a < 7)
            SetHorizontalShake(50, 3);
        if (field000a == 0 && field000c == 1)
            (*opponentSlot)->facing = (char)-(int)facing;
        velocityY += gravity;
        if (velocityY + positionY > 0.0 && field000a > 5) {
            ResetFrame();
            positionY = 0.0;
            ResetPose();
            field0008 = 13;
            return;
        }
        if (field000a == 1) {
            (*opponentSlot)->positionY = positionY - 66.0;
            (*opponentSlot)->positionX = positionX + (double)((int)facing * 23);
        }
        if (field000a == 2) {
            (*opponentSlot)->positionY = positionY - 69.0;
            (*opponentSlot)->positionX = positionX + (double)((int)facing * 21);
        }
        if (field000a == 3) {
            (*opponentSlot)->positionY = positionY - 73.0;
            (*opponentSlot)->positionX = positionX + (double)((int)facing * 19);
        }
        if (field000a == 4) {
            (*opponentSlot)->positionY = positionY - 74.0;
            (*opponentSlot)->positionX = positionX + (double)((int)facing * 19);
        }
        if (field000a == 5) {
            (*opponentSlot)->positionY = positionY - 71.0;
            (*opponentSlot)->positionX = positionX + (double)((int)facing * 17);
        }
        if (field000a == 6) {
            (*opponentSlot)->positionY = positionY - 70.0;
            (*opponentSlot)->positionX = positionX + (double)((int)facing * 16);
        }
        if (field000a == 7 && field000c == 0) {
            (*opponentSlot)->facing = facing;
            (*opponentSlot)->positionY = positionY - 60.0;
            (*opponentSlot)->positionX = positionX - (double)((int)facing * 37);
            (*opponentSlot)->field0008 = 63;
            ApplyDamage(1300, 500.0);
            (*opponentSlot)->ResetPose();
            (*opponentSlot)->knockbackVelocityX = -2.0;
            (*opponentSlot)->knockbackVelocityY = -1.0;
        }
        if (field000a == 11 && field000c == 0)
            gravity = 0.035;
        ++field000c;
        if (field000c >= timing.frameDuration) {
            field000c = 0;
            ++field000a;
            attackCollisionResult = 0;
            if (field000a == 11)
                facing = (char)-(int)facing;
            if (field000a >= timing.animationFrameCount)
                field000a = (unsigned short)(field000a - 2);
        }
        return;

    case 250: // Reviewed original Nayuki 0x0045B7D4: tiered multi-frame effect 401
        if (field000a == 0 && field000c == 0)
            ResetFrame();
        if (field000a == 3 && field000c == 0) {
            effect.type = 0x191;
            effect.x = (double)((int)positionX + (int)facing * 14);
            effect.y = (double)((int)positionY - 41);
            effect.group = 0;
            effect.field0028 = 1;
            effect.layer = 0;
            effect.flag0018 = (unsigned char)facing;
            EmitLocalEffect(&effect);
            pendingCharacterSoundSlot = 0;
            meter = (short)(meter + 45);
        }
        ++field000c;
        if (field000c >= timing.frameDuration - (field000a == 4) * field3148 * 3) {
            field000c = 0;
            ++field000a;
            attackCollisionResult = 3;
            if (field000a >= timing.animationFrameCount) {
                field0008 = 0;
                ResetPose();
            }
        }
        return;

    case 251: // Reviewed original Nayuki 0x0045B930: tiered multi-frame effect 402
        if (field000a == 0 && field000c == 0)
            ResetFrame();
        if (field000a == 3 && field000c == 0) {
            effect.type = 0x192;
            effect.x = (double)((int)positionX + (int)facing * 14);
            effect.y = (double)((int)positionY - 41);
            effect.group = 0;
            effect.field0028 = 1;
            effect.layer = 0;
            effect.flag0018 = (unsigned char)facing;
            EmitLocalEffect(&effect);
            pendingCharacterSoundSlot = 0;
            meter = (short)(meter + 45);
        }
        ++field000c;
        if (field000c >= timing.frameDuration - (field000a == 4) * field3148 * 3) {
            field000c = 0;
            ++field000a;
            attackCollisionResult = 3;
            if (field000a >= timing.animationFrameCount) {
                field0008 = 0;
                ResetPose();
            }
        }
        return;

    case 252: // Reviewed original Nayuki 0x0045BA8C: resource-costly area effect plus tiered hit
        if (field000a == 0 && field000c == 0) {
            if (field0120 == 0)
                field0118 -= 500.0;
            else
                field0118 -= 250.0;
            effect.type = 33;
            effect.palette = 11;
            effect.x = (double)(int)positionX;
            effect.y = (double)((int)positionY - 50);
            effect.group = 2;
            effect.layer = 1;
            contextOwner->EmitEffect(&effect);
        }
        if (field000a == 0 && field000c == 0)
            ResetFrame();
        if (field000a == 3 && field000c == 0) {
            effect.type = 0x193;
            effect.x = (double)((int)positionX + (int)facing * 14);
            effect.y = (double)((int)positionY - 41);
            effect.field0028 = 1;
            effect.group = 0;
            effect.layer = 0;
            effect.flag0018 = (unsigned char)facing;
            EmitLocalEffect(&effect);
            pendingCharacterSoundSlot = 0;
            meter = (short)(meter + 45);
        }
        ++field000c;
        if (field000c >= timing.frameDuration - (field000a == 4) * field3148 * 3) {
            field000c = 0;
            ++field000a;
            attackCollisionResult = 3;
            if (field000a >= timing.animationFrameCount) {
                field0008 = 0;
                ResetPose();
            }
        }
        return;

    case 253: // Reviewed Nayuki 0x0045BC9E: aerial retreat launch and conditional landing
        if (field000a == 0 && field000c == 0) {
            velocityX = 0.0;
            velocityY = 0.0;
            horizontalDeceleration = 0.0;
            remainingHitCount = 2;
        }
        if (positionY < 0.0) {
            velocityY += gravity;
            velocityX -= 0.035;
            if (velocityX < 0.0)
                velocityX = 0.0;
        }
        ++field000c;
        if (field000c >= timing.frameDuration) {
            field000c = 0;
            ++field000a;
            attackCollisionResult = 0;
            if (field000a == 4) {
                pendingContextSoundSlot = 20;
                meter = (short)(meter + 45);
                velocityX = 1.2;
                velocityY = -2.5;
                gravity = 0.03;
            }
            if (field000a >= timing.animationFrameCount) {
                field0008 = 256;
                if (inputY == 1)
                    field0008 = 258;
                ResetPose();
            }
        }
        return;

    case 254: // Reviewed Nayuki 0x0045BE17: frame-four launcher and local effect 404
        if (field000a == 0 && field000c == 0) {
            velocityX = 0.0;
            velocityY = 0.0;
            horizontalDeceleration = 0.0;
            remainingHitCount = 1;
        }
        ++field000c;
        if (field000c >= timing.frameDuration) {
            field000c = 0;
            ++field000a;
            attackCollisionResult = 0;
            if (field000a == 4) {
                pendingContextSoundSlot = 20;
                meter = (short)(meter + 45);
                velocityX = 1.7;
                velocityY = -1.7;
                effect.type = 0x194;
                effect.x = (double)(int)positionX;
                effect.y = (double)(int)positionY;
                effect.group = 0;
                effect.layer = 1;
                effect.flag0018 = (unsigned char)facing;
                EmitLocalEffect(&effect);
            }
            if (field000a >= timing.animationFrameCount) {
                field0008 = 258;
                ResetPose();
            }
        }
        return;

    case 256: // Reviewed Nayuki 0x0045BF74: wall collision and rebound transition
        if (field000a == 0 && field000c == 0) {
            velocityX = 2.4;
            remainingHitCount = 1;
            velocityY = 0.0;
        }
        if (CollisionSide() != 0 && field313c == 0) {
            velocityX = -0.7;
            velocityY = -2.0;
            gravity = 0.035;
            field0008 = 257;
            pendingContextSoundSlot = 31;
            effect.type = 0;
            effect.x = (double)(int)positionX;
            effect.y = (double)(int)positionY;
            effect.group = 2;
            effect.layer = 1;
            contextOwner->EmitEffect(&effect);
            ++field313c;
            return;
        }
        if (remainingHitCount == 0) {
            velocityX = -0.7;
            velocityY = -2.0;
            gravity = 0.035;
            field0008 = 257;
            return;
        }
        ++field000c;
        if (positionY == 0.0 && velocityY >= 0.0)
            velocityY = 0.0;
        if (field000c >= timing.frameDuration) {
            field000c = 0;
            ++field000a;
            attackCollisionResult = 0;
            if (field000a >= timing.animationFrameCount)
                field000a = (unsigned short)(field000a - 4);
        }
        return;

    case 257: // Reviewed Nayuki 0x0045C155: clear buffered buttons during bounce recovery
        velocityY += gravity;
        ClearBufferedButtons();
        ++field000c;
        if (field000c >= timing.frameDuration) {
            field000c = 0;
            ++field000a;
            attackCollisionResult = 3;
            if (field000a >= timing.animationFrameCount) {
                ResetPose();
                field0008 = 9;
            }
        }
        return;

    case 258: // Reviewed Nayuki 0x0045C1DF: aerial glide and landing state 97
        gravity = 0.04;
        velocityY += gravity;
        if (field000a == 0 && field000c == 0)
            velocityX *= 0.5;
        if (field000a == 3 && field000c == 0)
            remainingHitCount = 1;
        if (positionY + velocityY >= 0.0) {
            positionY = 0.0;
            field0008 = 97;
            ResetFrame();
            ResetPose();
            return;
        }
        ++field000c;
        if (field000c >= timing.frameDuration) {
            field000c = 0;
            ++field000a;
            attackCollisionResult = 0;
            if (field000a >= timing.animationFrameCount)
                field000a = (unsigned short)(field000a - 2);
        }
        return;

    case 259: // Reviewed Nayuki 0x0045C2FB: tier counter increase with audio cues
        ResetFrame();
        if (field000a == 0 && field000c == 0)
            pendingCharacterSoundSlot = 4;
        if (field000a == 10 && field000c == 0)
            ++field3148;
        if (field000a == 10 && field000c == 0)
            pendingCharacterSoundSlot = 5;
        if (field3148 > 9)
            field3148 = 9;
        ++field000c;
        if (field000c >= timing.frameDuration) {
            field000c = 0;
            ++field000a;
            attackCollisionResult = 3;
            if (field000a >= timing.animationFrameCount) {
                ResetPose();
                field0008 = 7;
            }
        }
        return;

    case 260: // Reviewed Nayuki 0x0045C3F9: grounded launcher and tier-scaled airborne sequence
        if (field000a == 0 && field000c == 0) {
            velocityX = 0.0;
            velocityY = 0.0;
            horizontalDeceleration = 0.0;
            gravity = 0.035;
            remainingHitCount = 1;
        }
        if (positionY < 0.0)
            velocityY += gravity;
        if (field000a > 8 && velocityY + positionY > 0.0) {
            positionY = 0.0;
            ResetFrame();
            field000c = 0;
            field000a = 12;
        }
        if (field000a > 4 && field000a < 9)
            velocityX -= 0.025;
        ++field000c;
        if (field000c >= timing.frameDuration) {
            field000c = 0;
            ++field000a;
            ++field313c;
            attackCollisionResult = 0;
            if (field000a == 4) {
                meter = (short)(meter + 45);
                velocityX = 1.8;
                velocityY = -1.9;
                if (field3148 > 2) {
                    velocityX = 2.1;
                    velocityY = -2.0;
                }
                if (field3148 > 5) {
                    velocityX = 2.4;
                    velocityY = -2.1;
                }
                if (field3148 > 8) {
                    velocityX = 3.0;
                    velocityY = -2.2;
                }
            }
            if (field000a == 5) {
                if (field3148 > 2)
                    field000a = 6;
                if (field3148 > 5)
                    field000a = 7;
                if (field3148 > 8)
                    field000a = 8;
                return;
            }
            if (field000a > 5 && field000a < 9)
                field000a = 9;
            if (field000a == 9) {
                gravity = 0.035;
                velocityX *= 0.3;
            }
            if (field000a >= timing.animationFrameCount) {
                field0008 = 7;
                ResetFrame();
                ResetPose();
                return;
            }
        }
        return;

    case 261: // Reviewed Nayuki 0x0045C6C1: aerial chained launcher with tiered follow-through
        if (field000a == 0 && field000c == 0) {
            velocityX = 0.0;
            velocityY = 0.0;
            horizontalDeceleration = 0.0;
            remainingHitCount = 3;
        }
        if (positionY < 0.0)
            velocityY += gravity;
        if (field000a > 5 && velocityY + positionY > 0.0) {
            positionY = 0.0;
            ResetFrame();
            field000c = 0;
            field000a = 16;
        }
        ++field000c;
        if (field000c >= timing.frameDuration) {
            field000c = 0;
            ++field000a;
            ++field313c;
            if (field000a == 5 || field000a == 9 || field000a == 13)
                attackCollisionResult = 0;
            if (field000a == 4) {
                meter = (short)(meter + 45);
                velocityX = 1.2;
                velocityY = -1.2;
                gravity = 0.03;
                if (field3148 > 6)
                    velocityY = -2.2;
            }
            if ((field000a == 8 && field3148 < 5) ||
                (field000a == 11 && field3148 < 7))
                field000a = 15;
            if (field000a == 15) {
                if (velocityY < 0.0)
                    velocityY *= 0.5;
                velocityX *= 0.5;
            }
            if (field000a >= timing.animationFrameCount) {
                field0008 = 7;
                ResetFrame();
                ResetPose();
                return;
            }
        }
        return;

    case 262: // Reviewed Nayuki 0x0045C90C: resource-costly looping aerial special
        if (field000a == 0 && field000c == 0) {
            if (field0120 == 0)
                field0118 -= 500.0;
            else
                field0118 -= 250.0;
            effect.type = 33;
            effect.palette = 11;
            effect.x = (double)(int)positionX;
            effect.y = (double)((int)positionY - 50);
            effect.group = 2;
            effect.layer = 1;
            contextOwner->EmitEffect(&effect);
            velocityX = 0.0;
            velocityY = 0.0;
            horizontalDeceleration = 0.0;
            remainingHitCount = (short)(field3148 + 1);
        }
        if (field000a == 0 && field000c == 0) {
            velocityX = 0.0;
            velocityY = 0.0;
            horizontalDeceleration = 0.0;
            remainingHitCount = 99;
        }
        velocityY += gravity;
        if (field000a > 11 && velocityY + positionY > 0.0) {
            positionY = 0.0;
            ResetFrame();
            field000c = 0;
            field000a = 16;
        }
        ++field000c;
        if (field000c >= timing.frameDuration) {
            field000c = 0;
            ++field000a;
            ++field313c;
            if (field000a == 5 || field000a == 9 || field000a == 13)
                attackCollisionResult = 0;
            if (field000a == 4) {
                meter = (short)(meter + 45);
                velocityX = 0.8;
                velocityY = -1.5;
                gravity = 0.035;
                hitInvulnerabilityFrames = (short)(field3148 * 12 + 30);
            }
            if (field000a == 7 || field000a == 11)
                velocityY = -1.4;
            if (field000a == 12)
                field000a = 4;
            if (field000a == 11 || field000a == 8) {
                if (field3138 > field3148)
                    field000a = 12;
            }
            if (field000a == 11 || field000a == 8)
                ++field3138;
            if (field000a == 15 && velocityY < 0.0)
                velocityY *= 0.5;
            if (field000a >= timing.animationFrameCount) {
                field0008 = 7;
                ResetFrame();
                ResetPose();
                return;
            }
        }
        return;

    case 263: // Reviewed Nayuki 0x0045CC85: original airborne multi-hit rebound, missing from sibling source
        if (field000a == 0 && field000c == 0) {
            velocityX = 0.0;
            velocityY = 0.0;
            horizontalDeceleration = 0.0;
            remainingHitCount = (short)(field3148 + 6);
        }
        if (positionY < 0.0)
            velocityY += gravity;
        if (field000a > 15) {
            velocityX -= 0.028;
            if (velocityX < 0.0)
                velocityX = 0.0;
        }
        if ((field000a == 6 || field000a == 11) && field000c == 0)
            pendingContextSoundSlot = 20;
        if (positionY + velocityX > 0.0 && field000a > 5 && field000a < 16) {
            field000c = 0;
            positionY = 0.0;
            velocityY = 0.0;
            field000a = 16;
            return;
        }
        ++field000c;
        if (field000c >= timing.frameDuration) {
            field000c = 0;
            ++field000a;
            ++field313c;
            if (field313c > 2) {
                attackCollisionResult = 0;
                field313c = 0;
            }
            if (field000a == 5) {
                meter = (short)(meter + 45);
                velocityX = 1.8;
                velocityY = -1.7;
                gravity = 0.035;
                if (field3138 == 1) {
                    velocityX = 0.6;
                    velocityY = -3.2;
                    gravity = 0.024;
                }
            }
            if (field000a == 16)
                field000a = 5;
            if (field000a >= timing.animationFrameCount) {
                field0008 = 7;
                ResetFrame();
                ResetPose();
            }
        }
        return;

    case 264: // Reviewed Nayuki 0x0045CEFA: tiered long-frame aerial special with branch-gated loops
        if (field000a == 0 && field000c == 0) {
            velocityX = 0.0;
            velocityY = 0.0;
            horizontalDeceleration = 0.0;
            remainingHitCount = 2;
        }
        if (field000a > 9) {
            velocityX -= 0.08;
            if (velocityX < 0.0)
                velocityX = 0.0;
        }
        if ((field000a == 4 || field000a == 6) && field000c == 0)
            pendingContextSoundSlot = 21;
        ++field000c;
        if (field000c >= 24 && field3148 > 3 && field000a == 11) {
            ++field000a;
            field000c = 0;
            attackCollisionResult = 0;
        }
        if (field000c >= timing.frameDuration ||
            (field000c >= timing.frameDuration - field3148 * 3 && field000a == 11) ||
            (field000c >= timing.frameDuration - 3 && field000a == 1 && field3148 > 2) ||
            (field000c >= timing.frameDuration - 3 && field000a == 2 && field3148 > 4)) {
            field000c = 0;
            ++field000a;
            if (field000a < 11)
                attackCollisionResult = 0;
            if (field000a == 4) {
                meter = (short)(meter + 45);
                velocityX = 2.2;
                if (field3138 == 1)
                    velocityX = 3.4;
            }
            if (field000a == 7 && field313c < 2) {
                field000a = 4;
                ++field313c;
            }
            if (field000a == 7 && field3138 == 1 && field313c < 4) {
                field000a = 4;
                ++field313c;
            }
            if (field000a >= timing.animationFrameCount) {
                field0008 = 7;
                ResetFrame();
                ResetPose();
                return;
            }
        }
        return;

    case 265: // Reviewed Nayuki 0x0045D1CB: reverse-motion timed special with tier-gated repeats
        if (field000a == 0 && field000c == 0) {
            velocityX = 0.0;
            velocityY = 0.0;
            horizontalDeceleration = 0.0;
            remainingHitCount = 2;
        }
        if (field000a > 9) {
            velocityX += 0.08;
            if (velocityX > 0.0)
                velocityX = 0.0;
        }
        if ((field000a == 4 || field000a == 6) && field000c == 0)
            pendingContextSoundSlot = 21;
        ++field000c;
        if (field000c >= 24 && field3148 > 3 && field000a == 11) {
            ++field000a;
            field000c = 0;
            attackCollisionResult = 0;
        }
        if (field000c >= timing.frameDuration ||
            (field000c >= timing.frameDuration - field3148 * 3 && field000a == 11) ||
            (field000c >= timing.frameDuration - 3 && field000a == 1 && field3148 > 2) ||
            (field000c >= timing.frameDuration - 3 && field000a == 2 && field3148 > 4)) {
            field000c = 0;
            ++field000a;
            if (field000a < 11)
                attackCollisionResult = 0;
            if (field000a == 4) {
                meter = (short)(meter + 45);
                velocityX = -2.2;
            }
            if (field000a == 7 && field313c < 2) {
                field000a = 4;
                ++field313c;
            }
            if (field000a == 7 && field3138 == 1 && field313c < 4) {
                field000a = 4;
                ++field313c;
            }
            if (field000a >= timing.animationFrameCount) {
                field0008 = 7;
                ResetFrame();
                ResetPose();
                return;
            }
        }
        return;

    case 266: // Reviewed Nayuki 0x0045D484: resource-consuming tiered attack with in-flight one-hit clamp
        if (field000a == 0 && field000c == 0) {
            if (field0120 == 0)
                field0118 -= 500.0;
            else
                field0118 -= 250.0;
            effect.type = 33;
            effect.palette = 11;
            effect.x = (double)(int)positionX;
            effect.y = (double)((int)positionY - 50);
            effect.group = 2;
            effect.layer = 1;
            contextOwner->EmitEffect(&effect);
            velocityX = 0.0;
            velocityY = 0.0;
            horizontalDeceleration = 0.0;
            remainingHitCount = (short)(field3148 + 1);
        }
        if (field000a > 9) {
            velocityX -= 0.3;
            remainingHitCount = 1;
            if (velocityX < 0.0)
                velocityX = 0.0;
        }
        if ((field000a == 4 || field000a == 6) && field000c == 0)
            pendingContextSoundSlot = 21;
        ++field000c;
        if (field000c >= timing.frameDuration ||
            (field000c >= timing.frameDuration - field3148 * 3 && field000a == 11) ||
            (field000c >= timing.frameDuration - 3 && field000a == 1 && field3148 > 2) ||
            (field000c >= timing.frameDuration - 3 && field000a == 2 && field3148 > 4)) {
            field000c = 0;
            ++field000a;
            if (field000a < 11)
                attackCollisionResult = 0;
            if (field000a == 4) {
                meter = (short)(meter + 45);
                velocityX = 2.5;
            }
            if (field000a == 7 && field313c < 2) {
                field000a = 4;
                ++field313c;
            }
            if (field000a == 7 && field3138 == 1 && field313c < 4) {
                field000a = 4;
                ++field313c;
            }
            if (field000a >= timing.animationFrameCount) {
                field0008 = 7;
                ResetFrame();
                ResetPose();
                return;
            }
        }
        return;

    case 267: // Reviewed Nayuki 0x0045D7A7: resource-consuming frame-loop attack with 99 hits
        if (field000a == 0 && field000c == 0) {
            if (field0120 == 0)
                field0118 -= 500.0;
            else
                field0118 -= 250.0;
            effect.type = 33;
            effect.palette = 11;
            effect.x = (double)(int)positionX;
            effect.y = (double)((int)positionY - 50);
            effect.group = 2;
            effect.layer = 1;
            contextOwner->EmitEffect(&effect);
            velocityX = 0.0;
            velocityY = 0.0;
            horizontalDeceleration = 0.0;
            remainingHitCount = 99;
        }
        if (field000a > 9) {
            velocityX -= 0.3;
            if (velocityX < 0.0)
                velocityX = 0.0;
        }
        if ((field000a == 4 || field000a == 6) && field000c == 0)
            pendingContextSoundSlot = 21;
        ++field000c;
        if (field000c >= timing.frameDuration) {
            field000c = 0;
            ++field000a;
            if (field000a < 11)
                attackCollisionResult = 0;
            if (field000a == 4) {
                meter = (short)(meter + 45);
                velocityX = 2.8;
            }
            if (field000a == 7 && field313c < 2) {
                field000a = 4;
                ++field313c;
            }
            if (field000a == 7 && field3138 == 1 && field313c < 4) {
                field000a = 4;
                ++field313c;
            }
            if (field000a >= timing.animationFrameCount) {
                field0008 = 7;
                ResetFrame();
                ResetPose();
                return;
            }
        }
        return;

    case 268: // Reviewed Nayuki 0x0045DA2B: command history and button-gated super selection
        if (field000a == 0 && field000c == 0)
            ResetFrame();
        if (field000a == 7) {
            if (recognizedCommand == 1) {
                ResetPose();
                ClearBufferedButtons();
                field0008 = 0xA3;
                if (facing == -1)
                    field0008 = 0xA4;
                return;
            }
            if (recognizedCommand == 0) {
                ResetPose();
                ClearBufferedButtons();
                field0008 = 0xA4;
                if (facing == -1)
                    field0008 = 0xA3;
                return;
            }
            if (recognizedCommand == 10 && field3148 > 0) {
                ResetPose();
                ClearBufferedButtons();
                field0008 = 250;
                return;
            }
            if (recognizedCommand == 11 && field3148 > 0) {
                ResetPose();
                ClearBufferedButtons();
                field0008 = 251;
                return;
            }
            if (recognizedCommand == 20 && field3148 > 0) {
                ResetPose();
                ClearBufferedButtons();
                field0008 = 260;
                return;
            }
            if (buttonPulse[0] == 1) {
                ResetPose();
                ClearBufferedButtons();
                field0008 = 275;
                if (field3148 > 4)
                    field0008 = 269;
                return;
            }
            if (buttonPulse[1] == 1) {
                ResetPose();
                ClearBufferedButtons();
                field0008 = 274;
                return;
            }
            if (buttonPulse[2] == 1) {
                ResetPose();
                ClearBufferedButtons();
                field0008 = 276;
                if (inputY == 1)
                    field0008 = 281;
                return;
            }
            if (buttonPulse[3] == 1) {
                if (inputX == facing) {
                    ResetPose();
                    ClearBufferedButtons();
                    field0008 = 277;
                    if (field3148 > 4)
                        field0008 = 277;
                    return;
                }
                if ((int)inputX == -(int)facing) {
                    ResetPose();
                    ClearBufferedButtons();
                    field0008 = 278;
                    if (field3148 > 4)
                        field0008 = 278;
                    return;
                }
                ResetPose();
                ClearBufferedButtons();
                field0008 = 271;
                if (inputY == 1)
                    field0008 = 280;
                if (field3148 == 9) {
                    field0008 = 268;
                    field000a = 8;
                }
                return;
            }
        }
        ++field000c;
        if (field000c >= timing.frameDuration) {
            field000c = 0;
            ++field000a;
            ++field313c;
            if (field000a >= timing.animationFrameCount) {
                field0008 = 0;
                ResetFrame();
                ResetPose();
                return;
            }
        }
        return;

    case 269: // Reviewed Nayuki 0x0045DDCF: aerial impact, rebound launcher and frame loop
        if (field000a == 0 && field000c == 0) {
            ResetFrame();
            remainingHitCount = 1;
        }
        if (positionY < 0.0)
            velocityY += gravity;
        if (positionY + velocityX > 0.0 && field000a > 2 && field000a < 8) {
            field000c = 0;
            positionY = 0.0;
            ResetFrame();
            field000a = 8;
            SetVerticalShake(3, 0);
            effect.type = 3;
            effect.x = (double)((int)positionX + (int)facing * 30);
            effect.y = (double)(int)positionY;
            effect.group = 2;
            effect.layer = 0;
            contextOwner->EmitEffect(&effect);
            pendingContextSoundSlot = 7;
            return;
        }
        ++field000c;
        if (field000c >= timing.frameDuration) {
            field000c = 0;
            ++field000a;
            if (field000a == 3) {
                meter = (short)(meter + 45);
                velocityX = 1.4;
                velocityY = -2.1;
                gravity = 0.045;
            }
            if (field000a == 8)
                --field000a;
            if (field000a >= timing.animationFrameCount) {
                field0008 = 0;
                FaceOpponent();
                ResetFrame();
                ResetPose();
            }
        }
        return;

    case 270: // Reviewed Nayuki 0x0045DFD5: tracking dash attack and delayed airborne retreat
        if (field000a == 0 && field000c == 0) {
            ResetFrame();
            remainingHitCount = 0;
        }
        if (field000a == 3 && field000c == 0) {
            meter = (short)(meter + 35);
            pendingContextSoundSlot = 20;
        }
        if (field000a > 8)
            velocityY += gravity;
        if (field000a > 8 && velocityY + positionY > 0.0) {
            ResetPose();
            field0008 = 13;
            return;
        }
        ++field000c;
        if (field000c >= timing.frameDuration) {
            field000c = 0;
            ++field000a;
            if (field000a == 5) {
                pendingCharacterSoundSlot = 3;
                remainingHitCount = 1;
            }
            if (field000a < 3)
                attackCollisionResult = 0;
            if (field000a == 3 || field000a == 4 || field000a == 5)
                positionX += (double)((int)facing * 40);
            if (field000a == 9) {
                velocityY = -1.0;
                velocityX = 0.7;
                gravity = 0.033;
            }
            if (field000a >= timing.animationFrameCount)
                --field000a;
        }
        return;

    case 271: // Reviewed Nayuki 0x0045E1A9: charge meter tier and state7 exit
        ResetFrame();
        if (field000a == 5 && field000c == 0)
            pendingCharacterSoundSlot = 5;
        if (field000a == 5 && field000c == 0)
            ++field3148;
        if (field3148 > 9)
            field3148 = 9;
        ++field000c;
        if (field000c >= timing.frameDuration) {
            field000c = 0;
            ++field000a;
            attackCollisionResult = 3;
            if (field000a >= timing.animationFrameCount) {
                ResetPose();
                field0008 = 7;
            }
        }
        return;

    case 272: // Reviewed Nayuki 0x0045E287: level-gated charge movement and button cancel
        if (field000a == 0 && field000c == 0) {
            velocityX = 1.4;
            velocityY = 0.0;
            horizontalDeceleration = 0.0;
        }
        if (field000a > 3) {
            velocityX -= 0.08;
            if (velocityX < 0.0)
                velocityX = 0.0;
        }
        if ((field000a == 1 || field000a == 3) && field000c == 0)
            pendingContextSoundSlot = 21;
        if (field000a < 4) {
            if (buttonPulse[0] == 1) {
                ResetPose();
                ClearBufferedButtons();
                field0008 = 275;
                if (field3148 > 4)
                    field0008 = 269;
                return;
            }
            if (buttonPulse[1] == 1) {
                ResetPose();
                ClearBufferedButtons();
                field0008 = 274;
                return;
            }
            if (buttonPulse[2] == 1) {
                ResetPose();
                ClearBufferedButtons();
                field0008 = 276;
                if (inputY == 1)
                    field0008 = 281;
                return;
            }
            if (buttonPulse[3] == 1) {
                ResetPose();
                ClearBufferedButtons();
                field0008 = 271;
                if (inputY == 1)
                    field0008 = 280;
                if (field3148 == 9) {
                    field0008 = 268;
                    field000a = 8;
                }
                return;
            }
        }
        ++field000c;
        if (field000c >= timing.frameDuration) {
            field000c = 0;
            ++field000a;
            attackCollisionResult = 3;
            if (field000a == 4 && field313c < 3) {
                field000a = (unsigned short)(field000a - 4);
                ++field313c;
            }
            if (field000a >= timing.animationFrameCount) {
                field0008 = 268;
                ResetFrame();
                ResetPose();
                field000a = 8;
                return;
            }
        }
        return;

    case 273: // Reviewed Nayuki 0x0045E522: reverse level-gated movement and button cancel
        if (field000a == 0 && field000c == 0) {
            velocityX = -1.4;
            velocityY = 0.0;
            horizontalDeceleration = 0.0;
        }
        if (field000a > 3) {
            velocityX -= 0.08;
            if (velocityX < 0.0)
                velocityX = 0.0;
        }
        if ((field000a == 1 || field000a == 3) && field000c == 0)
            pendingContextSoundSlot = 21;
        if (field000a < 4) {
            if (buttonPulse[0] == 1) {
                ResetPose();
                ClearBufferedButtons();
                field0008 = 275;
                if (field3148 > 4)
                    field0008 = 269;
                return;
            }
            if (buttonPulse[1] == 1) {
                ResetPose();
                ClearBufferedButtons();
                field0008 = 274;
                return;
            }
            if (buttonPulse[2] == 1) {
                ResetPose();
                ClearBufferedButtons();
                field0008 = 276;
                if (inputY == 1)
                    field0008 = 281;
                return;
            }
            if (buttonPulse[3] == 1) {
                ResetPose();
                ClearBufferedButtons();
                field0008 = 271;
                if (inputY == 1)
                    field0008 = 280;
                if (field3148 == 9) {
                    field0008 = 268;
                    field000a = 8;
                }
                return;
            }
        }
        ++field000c;
        if (field000c >= timing.frameDuration) {
            field000c = 0;
            ++field000a;
            attackCollisionResult = 3;
            if (field000a == 4 && field313c < 3) {
                field000a = (unsigned short)(field000a - 4);
                ++field313c;
            }
            if (field000a >= timing.animationFrameCount) {
                field0008 = 268;
                ResetFrame();
                ResetPose();
                field000a = 8;
                return;
            }
        }
        return;

    case 274: // Reviewed Nayuki 0x0045E7BD: direction-selected local attack and tier-gated frame9
        if (field000a == 0 && field000c == 0)
            ResetFrame();
        ++field000c;
        if (field000c >= timing.frameDuration - (field000a == 9) * field3148 * 3) {
            field000c = 0;
            ++field000a;
            attackCollisionResult = 0;
            if (field000a == 7 && field000c == 0) {
                effect.type = 0x1AC;
                if (inputX == facing)
                    effect.type = 0x1AD;
                if ((int)inputX == -(int)facing)
                    effect.type = 0x1AB;
                effect.x = (double)((int)positionX + (int)facing * 30);
                effect.y = (double)((int)positionY - 50);
                effect.group = 0;
                effect.field0028 = 1;
                effect.layer = 0;
                effect.flag0018 = (unsigned char)facing;
                EmitLocalEffect(&effect);
                pendingCharacterSoundSlot = 0;
                meter = (short)(meter + 45);
            }
            if (field000a >= timing.animationFrameCount) {
                field0008 = 0;
                ResetPose();
            }
        }
        return;

    case 275: // Reviewed Nayuki 0x0045E955: second aerial impact and rebound launcher
        if (field000a == 0 && field000c == 0) {
            ResetFrame();
            remainingHitCount = 1;
        }
        if (positionY < 0.0)
            velocityY += gravity;
        if (positionY + velocityX > 0.0 && field000a > 2 && field000a < 8) {
            field000c = 0;
            positionY = 0.0;
            ResetFrame();
            field000a = 8;
            SetVerticalShake(3, 0);
            effect.type = 3;
            effect.x = (double)((int)positionX + (int)facing * 30);
            effect.y = (double)(int)positionY;
            effect.group = 2;
            effect.layer = 0;
            contextOwner->EmitEffect(&effect);
            pendingContextSoundSlot = 7;
            return;
        }
        ++field000c;
        if (field000c >= timing.frameDuration) {
            field000c = 0;
            ++field000a;
            if (field000a == 3) {
                meter = (short)(meter + 45);
                velocityX = 1.4;
                velocityY = -2.1;
                gravity = 0.045;
            }
            if (field000a == 8)
                --field000a;
            if (field000a >= timing.animationFrameCount) {
                field0008 = 0;
                FaceOpponent();
                ResetFrame();
                ResetPose();
            }
        }
        return;

    case 276: // Reviewed Nayuki 0x0045EB5B: dash attack with tiered frame1 advance
        if (field000a == 0 && field000c == 0) {
            ResetFrame();
            remainingHitCount = 0;
        }
        if (field000a == 3 && field000c == 0) {
            meter = (short)(meter + 35);
            pendingContextSoundSlot = 20;
        }
        if (field000a > 8)
            velocityY += gravity;
        if (field000a > 8 && velocityY + positionY > 0.0) {
            ResetPose();
            field0008 = 13;
            return;
        }
        ++field000c;
        if (field000c >= timing.frameDuration ||
            (field000a == 1 && field000c == 39 - field3148 * 3)) {
            field000c = 0;
            ++field000a;
            if (field000a == 5) {
                pendingCharacterSoundSlot = 3;
                remainingHitCount = 1;
            }
            if (field000a < 3)
                attackCollisionResult = 0;
            if (field000a == 3 || field000a == 4 || field000a == 5)
                positionX += (double)((int)facing * 40);
            if (field000a == 9) {
                velocityY = -0.7;
                velocityX = 0.7;
                gravity = 0.033;
            }
            if (field000a >= timing.animationFrameCount)
                --field000a;
        }
        return;

    case 277: // Reviewed Nayuki 0x0045ED5D: second positive-direction charge movement
        if (field000a == 0 && field000c == 0) {
            velocityX = 1.4;
            velocityY = 0.0;
            horizontalDeceleration = 0.0;
        }
        if (field000a > 3) {
            velocityX -= 0.08;
            if (velocityX < 0.0)
                velocityX = 0.0;
        }
        if ((field000a == 1 || field000a == 3) && field000c == 0)
            pendingContextSoundSlot = 21;
        if (field000a < 4) {
            if (buttonPulse[0] == 1) {
                ResetPose();
                ClearBufferedButtons();
                field0008 = 275;
                if (field3148 > 4)
                    field0008 = 269;
                return;
            }
            if (buttonPulse[1] == 1) {
                ResetPose();
                ClearBufferedButtons();
                field0008 = 274;
                return;
            }
            if (buttonPulse[2] == 1) {
                ResetPose();
                ClearBufferedButtons();
                field0008 = 276;
                if (inputY == 1)
                    field0008 = 281;
                return;
            }
            if (buttonPulse[3] == 1) {
                ResetPose();
                ClearBufferedButtons();
                field0008 = 271;
                if (inputY == 1)
                    field0008 = 280;
                if (field3148 == 9) {
                    field0008 = 268;
                    field000a = 8;
                }
                return;
            }
        }
        ++field000c;
        if (field000c >= timing.frameDuration) {
            field000c = 0;
            ++field000a;
            attackCollisionResult = 3;
            if (field000a == 4 && field313c < 3) {
                field000a = (unsigned short)(field000a - 4);
                ++field313c;
            }
            if (field000a >= timing.animationFrameCount) {
                field0008 = 268;
                ResetFrame();
                ResetPose();
                field000a = 8;
                return;
            }
        }
        return;

    case 278: // Reviewed Nayuki 0x0045EFF8: third reverse level-gated cancel state
        if (field000a == 0 && field000c == 0) {
            velocityX = -1.4;
            velocityY = 0.0;
            horizontalDeceleration = 0.0;
        }
        if (field000a > 3) {
            velocityX -= 0.08;
            if (velocityX < 0.0)
                velocityX = 0.0;
        }
        if ((field000a == 1 || field000a == 3) && field000c == 0)
            pendingContextSoundSlot = 21;
        if (field000a < 4) {
            if (buttonPulse[0] == 1) {
                ResetPose();
                ClearBufferedButtons();
                field0008 = 275;
                if (field3148 > 4)
                    field0008 = 269;
                return;
            }
            if (buttonPulse[1] == 1) {
                ResetPose();
                ClearBufferedButtons();
                field0008 = 274;
                return;
            }
            if (buttonPulse[2] == 1) {
                ResetPose();
                ClearBufferedButtons();
                field0008 = 276;
                if (inputY == 1)
                    field0008 = 281;
                return;
            }
            if (buttonPulse[3] == 1) {
                ResetPose();
                ClearBufferedButtons();
                field0008 = 271;
                if (inputY == 1)
                    field0008 = 280;
                if (field3148 == 9) {
                    field0008 = 268;
                    field000a = 8;
                }
                return;
            }
        }
        ++field000c;
        if (field000c >= timing.frameDuration) {
            field000c = 0;
            ++field000a;
            attackCollisionResult = 3;
            if (field000a == 4 && field313c < 3) {
                field000a = (unsigned short)(field000a - 4);
                ++field313c;
            }
            if (field000a >= timing.animationFrameCount) {
                field0008 = 268;
                ResetFrame();
                ResetPose();
                field000a = 8;
                return;
            }
        }
        return;

    case 279: // Reviewed Nayuki 0x0045F4E9: tiered local strike with effect 0x191
        if (field000a == 0 && field000c == 0)
            ResetFrame();
        if (field000a == 3 && field000c == 0) {
            effect.type = 0x191;
            effect.x = (double)((int)positionX + (int)facing * 14);
            effect.y = (double)((int)positionY - 41);
            effect.group = 0;
            effect.field0028 = 1;
            effect.layer = 0;
            effect.flag0018 = (unsigned char)facing;
            EmitLocalEffect(&effect);
            pendingCharacterSoundSlot = 0;
            meter = (short)(meter + 45);
        }
        ++field000c;
        if (field000c >= timing.frameDuration - (field000a == 4) * field3148 * 3) {
            field000c = 0;
            ++field000a;
            attackCollisionResult = 3;
            if (field000a >= timing.animationFrameCount) {
                field0008 = 0;
                ResetPose();
            }
        }
        return;

    case 280: // Reviewed Nayuki 0x0045F645: ground stance entry with early sound cue
        ResetFrame();
        if (field000a == 0 && field000c == 0)
            pendingCharacterSoundSlot = 4;
        ++field000c;
        if (field000c >= timing.frameDuration) {
            field000c = 0;
            ++field000a;
            attackCollisionResult = 3;
            if (field000a >= timing.animationFrameCount) {
                ResetPose();
                field0008 = 0;
            }
        }
        return;

    case 281: // Reviewed Nayuki 0x0045F6DD: forward dash momentum and finishing pose
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
        if (field000a == 3 && field000c == 0) {
            meter = (short)(meter + 25);
            pendingContextSoundSlot = 20;
            remainingHitCount = 1;
        }
        ++field000c;
        if (field000c >= timing.frameDuration) {
            field000c = 0;
            ++field000a;
            if (field000a < 2)
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

    case 300: // Reviewed Nayuki original 0x0045F293: super entry, delayed local hit, tier timer
        if (field000a == 0 && field000c == 0) {
            velocityX = 0.0;
            velocityY = 0.0;
            gravity = 0.0;
        }
        if (field000a < 3)
            SetHorizontalShake(50, 3);
        if (field000a == 2 && field000c == 0) {
            hitstunFrames = 120;
            meter = (short)(meter - 1000);
            SetTint(0xb0, 3);
            effect.type = 0x44;
            effect.palette = 0x13;
            effect.x = (double)(int)positionX;
            effect.y = (double)((int)positionY - 40);
            effect.group = 2;
            effect.owner = 1;
            effect.layer = 1;
            contextOwner->EmitEffect(&effect);
        }
        if (field000a >= 2)
            reinterpret_cast<short&>(unknown_00df[0x13]) = 10;
        if (field000a == 4 && field000c == 0) {
            effect.owner = 1;
            effect.type = 0x196;
            effect.x = (double)((int)positionX + (int)facing * 14);
            effect.y = (double)((int)positionY - 41);
            effect.group = 0;
            effect.layer = 0;
            effect.field0028 = 1;
            effect.flag0018 = (unsigned char)facing;
            EmitLocalEffect(&effect);
            pendingCharacterSoundSlot = 0;
        }
        ++field000c;
        if (field000c >= timing.frameDuration ||
            (field000a == 5 && field000c == timing.frameDuration - field3148 * 6)) {
            field000c = 0;
            ++field000a;
            attackCollisionResult = 0;
            if (field000a >= timing.animationFrameCount) {
                field0008 = 0;
                ResetPose();
            }
        }
        return;

    case 301: // UNVERIFIED: sibling-derived hypothesis, not a Nayuki match
        if (field000a == 0 && field000c == 0) {
            dashMomentumFlag = 0;
            velocityX = 0.0;
            velocityY = 0.0;
            gravity = 0.0;
        }
        if (field000a < 5) {
            SetHorizontalShake(50, 3);
        }
        if (field000a >= 1) {
            // This two-byte member is not yet named in the shared view.
            reinterpret_cast<short&>(unknown_00df[0x13]) = 10;
        }
        if (field000a == 5 && field000c == 0 && field3138 == 0) {
            effect.type = 419;
            effect.x = (double)((int)positionX + (int)facing * 77);
            effect.y = (double)((int)positionY - 43);
            effect.group = 2;
            effect.owner = 1;
            effect.layer = 1;
            effect.flag0018 = (unsigned char)facing;
            EmitLocalEffect(&effect);
        }
        ++field000c;
        if (field000c >= timing.frameDuration) {
            field000c = 0;
            ++field000a;
            if (field000a == 2) {
                hitstunFrames = 120;
                meter = (short)(meter - 1000);
                SetTint(0xb0, 3);
                effect.type = 0x44;
                effect.palette = 0x13;
                effect.x = (double)((int)positionX + (int)facing * 47);
                effect.y = (double)((int)positionY - 43);
                effect.group = 2;
                effect.owner = 1;
                effect.layer = 1;
                contextOwner->EmitEffect(&effect);
            }
            if (field000a == 5 && hitstunFrames > 0) {
                field000a = (unsigned short)(field000a - 3);
            }
            if (field000a == 8 && field3138 < 3) {
                field000a = (unsigned short)(field000a - 3);
                ++field3138;
            }
            attackCollisionResult = 0;
            if (field000a >= timing.animationFrameCount) {
                field0008 = 0;
                ResetPose();
            }
        }
        return;

    case 302: // UNVERIFIED: sibling-derived hypothesis, not a Nayuki match
        if (field000a == 0 && field000c == 0) {
            dashMomentumFlag = 0;
            velocityX = 0.0;
            velocityY = 0.0;
            gravity = 0.0;
        }
        if (field000a < 5) {
            SetHorizontalShake(50, 3);
        }
        if (field000a >= 1) {
            // This two-byte member is not yet named in the shared view.
            reinterpret_cast<short&>(unknown_00df[0x13]) = 10;
        }
        if (field000a == 5 && field000c == 0 && field3138 == 0) {
            effect.type = 420;
            effect.x = (double)((int)positionX + (int)facing * 77);
            effect.y = (double)((int)positionY - 43);
            effect.group = 2;
            effect.owner = 1;
            effect.layer = 1;
            effect.flag0018 = (unsigned char)facing;
            EmitLocalEffect(&effect);
        }
        ++field000c;
        if (field000c >= timing.frameDuration) {
            field000c = 0;
            ++field000a;
            if (field000a == 2) {
                hitstunFrames = 120;
                meter = (short)(meter - 1000);
                SetTint(0xb0, 3);
                effect.type = 0x44;
                effect.palette = 0x13;
                effect.x = (double)((int)positionX + (int)facing * 47);
                effect.y = (double)((int)positionY - 43);
                effect.group = 2;
                effect.owner = 1;
                effect.layer = 1;
                contextOwner->EmitEffect(&effect);
            }
            if (field000a == 5 && hitstunFrames > 0) {
                field000a = (unsigned short)(field000a - 3);
            }
            if (field000a == 8 && field3138 < 3) {
                field000a = (unsigned short)(field000a - 3);
                ++field3138;
            }
            attackCollisionResult = 0;
            if (field000a >= timing.animationFrameCount) {
                field0008 = 0;
                ResetPose();
            }
        }
        return;

    case 303: // UNVERIFIED: sibling-derived hypothesis, not a Nayuki match
        if (field000a == 0 && field000c == 0) {
            dashMomentumFlag = 0;
            ResetFrame();
            remainingHitCount = 99;
        }
        if (field000a == 3 && field000c == 0) {
            velocityY = -2.4;
            velocityX = -0.4;
            gravity = 0.029;
            remainingHitCount = 99;
        }
        if (field000a == 3) {
            SetHorizontalShake(50, 3);
        }
        if (field000a > 11) {
            (*opponentSlot)->SetHorizontalShake(50, 3);
        }
        if (field000a == 3 && field000c == 0) {
            hitstunFrames = 120;
            meter = (short)(meter - 1000);
            SetTint(0xb0, 3);
            effect.type = 0x44;
            effect.palette = 0x13;
            effect.x = (double)(int)positionX;
            effect.y = (double)((int)positionY - 40);
            effect.group = 2;
            effect.owner = 1;
            effect.layer = 1;
            contextOwner->EmitEffect(&effect);
        }
        if (field000a == 11 && field000c == 0) {
            ResetFrame();
        }
        if (field000a == 12 && field000c == 0) {
            velocityX = -0.2;
            velocityY = -0.8;
            gravity = 0.015;
        }
        if (field000a == 14 && field000c == 0) {
            effect.type = 3;
            effect.x = (double)(int)(positionX + (double)((int)facing *
                       (unsigned short)RandomRange(0, 180)));
            effect.y = 0.0;
            effect.group = 2;
            effect.layer = 1;
            contextOwner->EmitEffect(&effect);

            effect.owner = 1;
            effect.type = 0x19f;
            effect.x = (double)(int)positionX;
            effect.y = 0.0;
            effect.flag0018 = (unsigned char)facing;
            effect.group = 2;
            effect.layer = 1;
            EmitLocalEffect(&effect);

            effect.type = 0x191;
            effect.x = (double)((int)positionX + (int)facing * 27);
            effect.y = (double)((int)positionY - 28);
            effect.flag0018 = (unsigned char)facing;
            effect.layer = 1;
            effect.group = 2;
            EmitLocalEffect(&effect);

            effect.type = 0x1a5;
            effect.x = (double)((int)positionX + (int)facing * 16);
            effect.y = (double)((int)positionY - 43);
            effect.layer = 1;
            effect.group = 0;
            EmitLocalEffect(&effect);

            effect.x = (double)((int)positionX + (int)facing * 21);
            effect.y = (double)((int)positionY - 51);
            effect.layer = 0;
            EmitLocalEffect(&effect);
            pendingCharacterSoundSlot = 0;
        }
        if (field000a == 18 && field000c == 0) {
            effect.owner = 0;
            effect.type = 3;
            effect.x = (double)(int)(positionX + (double)((int)facing *
                       (unsigned short)RandomRange(0, 180)));
            effect.y = 0.0;
            effect.group = 2;
            effect.layer = 1;
            contextOwner->EmitEffect(&effect);

            effect.type = 0x191;
            effect.x = (double)((int)positionX + (int)facing * 27);
            effect.y = (double)((int)positionY - 28);
            effect.flag0018 = (unsigned char)facing;
            effect.layer = 1;
            effect.group = 2;
            EmitLocalEffect(&effect);

            effect.type = 0x1a5;
            effect.x = (double)((int)positionX + (int)facing * 16);
            effect.y = (double)((int)positionY - 43);
            effect.layer = 1;
            effect.group = 0;
            EmitLocalEffect(&effect);

            effect.x = (double)((int)positionX + (int)facing * 21);
            effect.y = (double)((int)positionY - 51);
            effect.layer = 0;
            EmitLocalEffect(&effect);
            pendingCharacterSoundSlot = 0;
        }
        velocityY += gravity;
        if (field000a < 20 && velocityY > 0.15) {
            velocityY = 0.15;
        }
        if (field000a > 14 && field000a < 22 && velocityY + positionY > 0.0) {
            positionY = 0.0;
            ResetFrame();
            field000a = 22;
            field000c = 0;
        }
        ++field000c;
        if (field000c >= timing.frameDuration) {
            field000c = 0;
            ++field000a;
            attackCollisionResult = 0;
            if (field000a == 20 && field3138 < 8) {
                ++field3138;
                field000a = (unsigned short)(field000a - 3);
            }
            if (field000a == 22) {
                field000a = (unsigned short)(field000a - 2);
            }
            if (field000a >= timing.animationFrameCount) {
                field0008 = 7;
                ResetPose();
            }
        }
        return;

    case 304: // UNVERIFIED: sibling-derived hypothesis, not a Nayuki match
        if (field000a == 0 && field000c == 0) {
            dashMomentumFlag = 0;
            ResetFrame();
            remainingHitCount = 99;
        }
        if (field000a == 3 && field000c == 0) {
            velocityY = -2.4;
            velocityX = -0.4;
            gravity = 0.029;
            remainingHitCount = 99;
        }
        if (field000a == 3) {
            SetHorizontalShake(50, 3);
        }
        if (field000a > 11) {
            (*opponentSlot)->SetHorizontalShake(50, 3);
        }
        if (field000a == 3 && field000c == 0) {
            hitstunFrames = 120;
            meter = (short)(meter - 2000);
            SetTint(0xb0, 3);
            effect.type = 0x45;
            effect.palette = 5;
            effect.x = (double)(int)positionX;
            effect.y = (double)((int)positionY - 40);
            effect.group = 2;
            effect.owner = 1;
            effect.layer = 1;
            contextOwner->EmitEffect(&effect);
        }
        if (field000a == 11 && field000c == 0) {
            ResetFrame();
        }
        if (field000a == 12 && field000c == 0) {
            velocityX = -0.2;
            velocityY = -0.8;
            gravity = 0.015;
        }
        if (field000a == 14 && field000c == 0) {
            effect.owner = 0;
            effect.type = 3;
            effect.x = (double)(int)(positionX + (double)((int)facing *
                       (unsigned short)RandomRange(0, 240)));
            effect.y = 0.0;
            effect.group = 2;
            effect.layer = 1;
            contextOwner->EmitEffect(&effect);

            effect.owner = 1;
            effect.type = 0x1a0;
            effect.x = (double)(int)positionX;
            effect.y = 0.0;
            effect.flag0018 = (unsigned char)facing;
            effect.group = 2;
            effect.layer = 1;
            EmitLocalEffect(&effect);

            effect.type = 0x191;
            effect.x = (double)((int)positionX + (int)facing * 27);
            effect.y = (double)((int)positionY - 28);
            effect.flag0018 = (unsigned char)facing;
            effect.layer = 1;
            effect.group = 2;
            EmitLocalEffect(&effect);

            effect.type = 0x1a5;
            effect.x = (double)((int)positionX + (int)facing * 16);
            effect.y = (double)((int)positionY - 43);
            effect.layer = 1;
            effect.group = 0;
            EmitLocalEffect(&effect);

            effect.x = (double)((int)positionX + (int)facing * 21);
            effect.y = (double)((int)positionY - 51);
            effect.layer = 0;
            EmitLocalEffect(&effect);
            pendingCharacterSoundSlot = 0;
        }
        if (field000a == 18 && field000c == 0) {
            effect.owner = 0;
            effect.type = 3;
            effect.x = (double)(int)(positionX + (double)((int)facing *
                       (unsigned short)RandomRange(0, 240)));
            effect.y = 0.0;
            effect.group = 2;
            effect.layer = 1;
            contextOwner->EmitEffect(&effect);

            effect.type = 0x191;
            effect.x = (double)((int)positionX + (int)facing * 27);
            effect.y = (double)((int)positionY - 28);
            effect.flag0018 = (unsigned char)facing;
            effect.layer = 1;
            effect.group = 2;
            EmitLocalEffect(&effect);

            effect.type = 0x1a5;
            effect.x = (double)((int)positionX + (int)facing * 16);
            effect.y = (double)((int)positionY - 43);
            effect.layer = 1;
            effect.group = 0;
            EmitLocalEffect(&effect);

            effect.x = (double)((int)positionX + (int)facing * 21);
            effect.y = (double)((int)positionY - 51);
            effect.layer = 0;
            EmitLocalEffect(&effect);
            pendingCharacterSoundSlot = 0;
        }
        velocityY += gravity;
        if (field000a < 20 && velocityY > 0.15) {
            velocityY = 0.15;
        }
        if (field000a > 14 && field000a < 22 && velocityY + positionY > 0.0) {
            positionY = 0.0;
            ResetFrame();
            field000a = 22;
            field000c = 0;
        }
        ++field000c;
        if (field000c >= timing.frameDuration) {
            field000c = 0;
            ++field000a;
            attackCollisionResult = 0;
            if (field000a == 20 && field3138 < 15) {
                ++field3138;
                field000a = (unsigned short)(field000a - 3);
            }
            if (field000a == 22) {
                field000a = (unsigned short)(field000a - 2);
            }
            if (field000a >= timing.animationFrameCount) {
                field0008 = 7;
                ResetPose();
            }
        }
        return;

    case 305: // UNVERIFIED: sibling-derived hypothesis, not a Nayuki match
        if (field000a == 0 && field000c == 0) {
            dashMomentumFlag = 0;
            ResetFrame();
            remainingHitCount = 99;
        }
        if (field000a == 3 && field000c == 0) {
            velocityY = -2.4;
            velocityX = -0.4;
            gravity = 0.029;
            remainingHitCount = 99;
        }
        if (field000a == 3) {
            SetHorizontalShake(50, 3);
        }
        if (field000a > 11) {
            (*opponentSlot)->SetHorizontalShake(50, 3);
        }
        if (field000a == 3 && field000c == 0) {
            hitstunFrames = 120;
            meter = (short)(meter - 3000);
            SetTint(0xb0, 3);
            effect.type = 0x46;
            effect.palette = 0x40;
            effect.x = (double)(int)positionX;
            effect.y = (double)((int)positionY - 40);
            effect.group = 2;
            effect.owner = 1;
            effect.layer = 1;
            contextOwner->EmitEffect(&effect);
            pendingContextSoundSlot = 37;
        }
        if (field000a == 11 && field000c == 0) {
            ResetFrame();
        }
        if (field000a > 10) {
            contextOwner->SetSceneTimer(15);
        }
        if (field000a == 12 && field000c == 0) {
            velocityX = -0.2;
            velocityY = -0.8;
            gravity = 0.015;
        }
        if (field000a == 14 && field000c == 0) {
            effect.owner = 0;
            effect.type = 3;
            effect.x = (double)(int)(positionX + (double)((int)facing *
                       (unsigned short)RandomRange(0, 320)));
            effect.y = 0.0;
            effect.group = 2;
            effect.layer = 1;
            contextOwner->EmitEffect(&effect);

            effect.owner = 1;
            effect.type = 0x1a1;
            effect.x = (double)(int)positionX;
            effect.y = 0.0;
            effect.flag0018 = (unsigned char)facing;
            effect.group = 2;
            effect.layer = 1;
            EmitLocalEffect(&effect);

            effect.type = 0x191;
            effect.x = (double)((int)positionX + (int)facing * 27);
            effect.y = (double)((int)positionY - 28);
            effect.flag0018 = (unsigned char)facing;
            effect.layer = 1;
            effect.group = 2;
            EmitLocalEffect(&effect);

            effect.type = 0x1a5;
            effect.x = (double)((int)positionX + (int)facing * 16);
            effect.y = (double)((int)positionY - 43);
            effect.layer = 1;
            effect.group = 0;
            EmitLocalEffect(&effect);

            effect.x = (double)((int)positionX + (int)facing * 21);
            effect.y = (double)((int)positionY - 51);
            effect.layer = 0;
            EmitLocalEffect(&effect);
            pendingCharacterSoundSlot = 0;
        }
        if (field000a == 18 && field000c == 0) {
            effect.owner = 0;
            effect.type = 3;
            effect.x = (double)(int)(positionX + (double)((int)facing *
                       (unsigned short)RandomRange(0, 320)));
            effect.y = 0.0;
            effect.group = 2;
            effect.layer = 1;
            contextOwner->EmitEffect(&effect);

            effect.type = 0x191;
            effect.x = (double)((int)positionX + (int)facing * 27);
            effect.y = (double)((int)positionY - 28);
            effect.flag0018 = (unsigned char)facing;
            effect.layer = 1;
            effect.group = 2;
            EmitLocalEffect(&effect);

            effect.type = 0x1a5;
            effect.x = (double)((int)positionX + (int)facing * 16);
            effect.y = (double)((int)positionY - 43);
            effect.layer = 1;
            effect.group = 0;
            EmitLocalEffect(&effect);

            effect.x = (double)((int)positionX + (int)facing * 21);
            effect.y = (double)((int)positionY - 51);
            effect.layer = 0;
            EmitLocalEffect(&effect);
            pendingCharacterSoundSlot = 0;
        }
        velocityY += gravity;
        if (field000a < 20 && velocityY > 0.15) {
            velocityY = 0.15;
        }
        if (field000a > 14 && field000a < 22 && velocityY + positionY > 0.0) {
            positionY = 0.0;
            ResetFrame();
            field000a = 22;
            field000c = 0;
        }
        ++field000c;
        if (field000c >= timing.frameDuration) {
            field000c = 0;
            ++field000a;
            attackCollisionResult = 0;
            if (field000a == 20 && field3138 < 25) {
                ++field3138;
                field000a = (unsigned short)(field000a - 3);
            }
            if (field000a == 22) {
                field000a = (unsigned short)(field000a - 2);
            }
            if (field000a >= timing.animationFrameCount) {
                field0008 = 7;
                ResetPose();
            }
        }
        return;

    case 306: // UNVERIFIED: sibling-derived hypothesis, not a Nayuki match
        dashMomentumFlag = 0;
        if (field000a == 0 && field000c == 0) {
            if (field3138 == 0) {
                hitstunFrames = 120;
                meter = (short)(meter - 1000);
                SetTint(0xb0, 3);
                effect.type = 0x44;
                effect.palette = 0x13;
                effect.x = (double)((int)positionX + (int)facing * 5);
                effect.y = (double)((int)positionY - 43);
                effect.group = 2;
                effect.owner = 1;
                effect.layer = 1;
                contextOwner->EmitEffect(&effect);
                ++field3138;
                remainingHitCount = 5;
            }
            velocityX = 0.0;
            velocityY = 0.0;
            gravity = 0.0;
        }
        if (field000a == 4 && field000c == 0) {
            effect.type = 0x1a7;
            effect.x = (double)((int)positionX + (int)facing * 45);
            effect.y = (double)((int)positionY - 43);
            effect.group = 2;
            effect.owner = 1;
            effect.layer = 0;
            effect.flag0018 = (unsigned char)(-facing);
            EmitLocalEffect(&effect);
        }
        if (field000a < 5) {
            SetHorizontalShake(50, 3);
        }
        if (field000a == 5) {
            velocityY += 0.01;
        }
        if (field000a == 5 && positionY + velocityY > 0.0) {
            field000a = 6;
            field000c = 0;
            positionY = 0.0;
            velocityY = 0.0;
        }
        if (field000a > 5) {
            velocityX -= 0.025;
            if (velocityX < 0.0) {
                velocityX = 0.0;
            }
        }
        if (field000a >= 1) {
            reinterpret_cast<short&>(unknown_00df[0x13]) = 10;
        }
        ++field000c;
        if (field000c >= timing.frameDuration) {
            field000c = 0;
            ++field000a;
            if (field000a == 2 && field313c < 9) {
                field000a = (unsigned short)(field000a - 2);
                ++field313c;
            }
            if (field000a == 5) {
                velocityX = 1.9;
                velocityY = -0.4;
                positionX += (double)((int)facing * 30);
                pendingCharacterSoundSlot = 4;
            }
            if (field000a == 6) {
                --field000a;
            }
            attackCollisionResult = 0;
            if (field000a >= timing.animationFrameCount) {
                field0008 = 0;
                ResetPose();
            }
        }
        return;

    }
}
