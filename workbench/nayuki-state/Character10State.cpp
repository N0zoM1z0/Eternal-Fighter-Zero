// Nayuki Character10::Slot06 state boss — selected native partial reconstruction.
// Original owner at 0x00451850 contains 62,693 code bytes and two adjacent
// 552/306-byte switch tables. Only the opening states are reviewed.
// Remaining states use Makoto-derived experimental scaffolding and are NOT Exact.
// The 21 missing Nayuki-specific states must still be authored, not bypassed.
#include "../../src/CharacterViews.h"

void Character10::Slot06()
{
    // Nayuki target entry 0x00451850: stop this tick if either fighter freezes it.
    if (hitstopFrames > 0 || (*opponentSlot)->hitstunFrames > 0) return;

    // 0x005E8623: construct the effect spawn, snapshot this frame's duration
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
    // Do not use sibling Ghidra's normalized 0..124 case numbers as animation IDs.
    switch (field0008) {
    default: // Original Nayuki fallback at 0x004518FD for 169 unmapped IDs
        // The selector table sends 186 IDs here; it is not a no-op.
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

    case 1: // Original Nayuki state at 0x0045196E
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

    case 2: // Original Nayuki state at 0x004519F8
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

    case 3: // Original Nayuki state at 0x00451A82
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

    case 4: // Original Nayuki state at 0x00451AFB
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

    case 5: // Original Nayuki state at 0x00451C50
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

    case 6: // Original Nayuki state at 0x00451DB1
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

    case 7: // Original Nayuki state at 0x00451EED
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

    case 8: // Original Nayuki state at 0x00451F70
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

    case 9: // Original Nayuki state at 0x00451FF3
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

    case 13: // Original Nayuki state at 0x004520A0
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

    case 14: // Original Nayuki state at 0x0045213B
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

    case 15: // Original Nayuki state at 0x00452265
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

    case 16: // Original Nayuki state at 0x0045238F
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

    case 47: // Original Nayuki state at 0x004524AD
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

    case 50: // Original Nayuki recoil at 0x004525DD
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

    case 51: // Original Nayuki recoil at 0x004527C4
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

    case 52: // Original Nayuki recoil at 0x004529AB
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

    case 53: // Original Nayuki recoil at 0x00452B92
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

    case 54: // Original Nayuki recoil at 0x00452D79
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

    case 55: // Original Nayuki recoil at 0x00452F60
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

    case 56: // Unreviewed inherited sibling logic, Makoto address 0x005: recoil returning directly to crouch
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

    case 57: // Original block 0x5ea0f7: stronger recoil returning to crouch
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

    case 58: // Original block 0x5ea2d0: stronger recoil returning to crouch
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

    case 59: // Unreviewed inherited sibling logic, Makoto address 0x005: airborne hit reaction
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

    case 60: // Original block 0x5ea6a8: stronger airborne hit reaction
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

    case 61: // Original block 0x5ea8a7: stronger airborne hit reaction
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

    case 62: // Unreviewed inherited sibling logic, Makoto address 0x005: unclamped airborne hit reaction
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

    case 63: // Unreviewed inherited sibling logic, Makoto address 0x005: direct-velocity aerial hit reaction
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

    case 64: // Unreviewed inherited sibling logic, Makoto address 0x005: wall-aware airborne reaction
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

    case 65: // Unreviewed inherited sibling logic, Makoto address 0x005: stronger wall-aware airborne reaction
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

    case 66: // Unreviewed inherited sibling logic, Makoto address 0x005: unclamped wall-aware airborne reaction
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

    case 67: // Unreviewed inherited sibling logic, Makoto address 0x005: direct-speed wall-contact reaction
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

    case 68: // Unreviewed inherited sibling logic, Makoto address 0x005: collision-cancelled airborne recovery
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

    case 69: // Unreviewed inherited sibling logic, Makoto address 0x005: airborne recovery without wall cancel
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

    case 70: // Unreviewed inherited sibling logic, Makoto address 0x005: wall recovery with global effect
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

    case 71: // Unreviewed inherited sibling logic, Makoto address 0x005: high-gravity direct-speed air reaction
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

    case 72: // Unreviewed inherited sibling logic, Makoto address 0x005: grounded recoil with stage pushback
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

    case 73: // Unreviewed inherited sibling logic, Makoto address 0x005: separate grounded recoil continuation
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

    case 74: // Unreviewed inherited sibling logic, Makoto address 0x005: grounded recoil to crouch
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

    case 75: // Unreviewed inherited sibling logic, Makoto address 0x005: forward grounded recoil
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

    case 76: // Unreviewed inherited sibling logic, Makoto address 0x005: independent duplicate of recoil 75
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

    case 77: // Unreviewed inherited sibling logic, Makoto address 0x005: recoil ends in crouch
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

    case 81: // Unreviewed inherited sibling logic, Makoto address 0x005: airborne recoil and local hit effect
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

    case 82: // Unreviewed inherited sibling logic, Makoto address 0x005: repeated airborne lift and knockback
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

    case 83: // Unreviewed inherited sibling logic, Makoto address 0x005: airborne ground-impact recovery
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

    case 84: // Unreviewed inherited sibling logic, Makoto address 0x005: independent ground-impact recovery
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

    case 85: // Unreviewed inherited sibling logic, Makoto address 0x005: direct airborne knockback and landing
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

    case 86: // Unreviewed inherited sibling logic, Makoto address 0x005: one-shot lift and landing recoil
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

    case 87: // Unreviewed inherited sibling logic, Makoto address 0x005: fixed-position effect and idle return
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

    case 96: // Unreviewed inherited sibling logic, Makoto address 0x005: stand/crouch wakeup timing
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

    case 97: // Unreviewed inherited sibling logic, Makoto address 0x005: first impact flash
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

    case 98: // Unreviewed inherited sibling logic, Makoto address 0x005: separately dispatched impact flash
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

    case 99: // Unreviewed inherited sibling logic, Makoto address 0x005: end of knockout recovery
        dashMomentumFlag = 0;
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

    case 150: // Unreviewed inherited sibling logic, Makoto address 0x005: {'stand/crouch' if terminal == 0 else 'crouching'} recoil
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

    case 151: // Unreviewed inherited sibling logic, Makoto address 0x005: {'stand/crouch' if terminal == 0 else 'crouching'} recoil
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

    case 152: // Unreviewed inherited sibling logic, Makoto address 0x005: {'stand/crouch' if terminal == 0 else 'crouching'} recoil
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

    case 153: // Unreviewed inherited sibling logic, Makoto address 0x005: {'stand/crouch' if terminal == 0 else 'crouching'} recoil
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

    case 154: // Unreviewed inherited sibling logic, Makoto address 0x005: {'stand/crouch' if terminal == 0 else 'crouching'} recoil
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

    case 155: // Unreviewed inherited sibling logic, Makoto address 0x005: {'stand/crouch' if terminal == 0 else 'crouching'} recoil
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

    case 156: // Unreviewed inherited sibling logic, Makoto address 0x005: forward airborne knockback
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

    case 157: // Unreviewed inherited sibling logic, Makoto address 0x005: aerial effect with two-frame loop
        velocityX = 1.0;
        gravity = 0.045;
        dashMomentumFlag = 0;
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
                field000a = (unsigned short)(field000a - 2);
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

    case 158: // Unreviewed inherited sibling logic, Makoto address 0x005: opposite-direction aerial effect
        velocityX = -1.0;
        gravity = 0.045;
        dashMomentumFlag = 0;
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
                field000a = (unsigned short)(field000a - 2);
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

    case 161: // Unreviewed inherited sibling logic, Makoto address 0x005: aerial impact and trail reset
        if (field000a == 0 && field000c == 0) {
            ResetFrame();
            effect.type = 9;
            effect.x = (double)(int)positionX;
            effect.y = (double)((int)positionY - 60);
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

    case 162: // Unreviewed inherited sibling logic, Makoto address 0x005: staged aerial launch and impact
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
            effect.y = (double)((int)positionY - 60);
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
            if (field000a == 18) {
                gravity = 0.035;
            }
            if (field000a >= timing.animationFrameCount) {
                field000a = (unsigned short)(field000a - 2);
            }
        }
        return;

    case 163: // Unreviewed inherited sibling logic, Makoto address 0x005: cancellable forward dash
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
        velocityX = 2.2;
        dashMomentumFlag = 1;
        ++field000c;
        ++field3138;
        ++field313c;
        if (field000c >= timing.frameDuration) {
            field000c = 0;
            ++field000a;
            if (field000a >= timing.animationFrameCount) {
                field000a = (unsigned short)(field000a - 6);
                return;
            }
        }
        if (inputX == facing && field313c >= 80 && field000a < 4) {
            field0008 = 178;
            ResetPose();
        }
        if (inputX != facing && field3138 >= 60 && field000a < 4) {
            field0008 = 178;
            ResetPose();
        }
        return;

    case 164: // Unreviewed inherited sibling logic, Makoto address 0x005: decelerating ground dash
        StartTrail(3);
        dashMomentumFlag = 0;
        if (field000a == 0 && field000c == 0) {
            velocityX = 0.0;
            velocityY = 0.0;
        }
        if (field000a == 1 && field000c == 0) {
            velocityX = -2.2;
        }
        velocityX += 0.02;
        if (velocityX > 0.0) {
            velocityX = 0.0;
        }
        ++field000c;
        if (field000c >= timing.frameDuration) {
            field000c = 0;
            ++field000a;
            if (field000a == 4 && field3138 < 2) {
                field000a = (unsigned short)(field000a - 2);
                ++field3138;
            }
            if (field000a >= timing.animationFrameCount) {
                FaceOpponent();
                field0008 = 0;
                ResetPose();
                ResetFrame();
            }
        }
        return;

    case 165: // Unreviewed inherited sibling logic, Makoto address 0x005: sustained airborne momentum
        if (field000a == 0 && field000c == 0 && field3138 == 0) {
            velocityX = 1.9;
            velocityY = 1.3;
            StartTrail(3);
            horizontalDeceleration = -0.015;
            gravity = -0.038;
            pendingContextSoundSlot = 17;
        }
        velocityY += gravity;
        velocityX += horizontalDeceleration;
        if (velocityX < 0.5) {
            velocityX = 0.5;
        }
        if (velocityY < -1.5) {
            velocityY = -1.5;
        }
        ++field000c;
        ++field3138;
        ++field313c;
        if (field000c >= timing.frameDuration) {
            field000c = 0;
            ++field000a;
            if (field000a >= timing.animationFrameCount) {
                field000a = (unsigned short)(field000a - 2);
            }
        }
        if (inputX == facing && field313c >= 120) {
            field0008 = 9;
            ResetPose();
            gravity = 0.03;
            if (FaceOpponent() != 0) {
                velocityX = -velocityX;
            }
        }
        if (inputX != facing && field3138 >= 48) {
            field0008 = 9;
            ResetPose();
            gravity = 0.03;
            if (FaceOpponent() != 0) {
                velocityX = -velocityX;
            }
        }
        return;

    case 166: // Unreviewed inherited sibling logic, Makoto address 0x005: sustained airborne momentum
        if (field000a == 0 && field000c == 0 && field3138 == 0) {
            velocityX = -1.9;
            velocityY = 1.3;
            StartTrail(3);
            horizontalDeceleration = 0.015;
            gravity = -0.038;
            pendingContextSoundSlot = 17;
        }
        velocityY += gravity;
        velocityX += horizontalDeceleration;
        if (velocityX > -0.5) {
            velocityX = -0.5;
        }
        if (velocityY < -1.5) {
            velocityY = -1.5;
        }
        ++field000c;
        ++field3138;
        ++field313c;
        if (field000c >= timing.frameDuration) {
            field000c = 0;
            ++field000a;
            if (field000a >= timing.animationFrameCount) {
                field000a = (unsigned short)(field000a - 2);
            }
        }
        if ((int)inputX == -(int)facing && field313c >= 120) {
            field0008 = 9;
            ResetPose();
            gravity = 0.03;
            if (FaceOpponent() != 0) {
                velocityX = -velocityX;
            }
        }
        if ((int)inputX != -(int)facing && field3138 >= 48) {
            field0008 = 9;
            ResetPose();
            gravity = 0.03;
            if (FaceOpponent() != 0) {
                velocityX = -velocityX;
            }
        }
        return;

    case 167: // Unreviewed inherited sibling logic, Makoto address 0x005: stunned recovery with two effects
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

    case 168: // Unreviewed inherited sibling logic, Makoto address 0x005: grounded impact to state 0
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

    case 169: // Unreviewed inherited sibling logic, Makoto address 0x005: grounded impact to state 3
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

    case 170: // Unreviewed inherited sibling logic, Makoto address 0x005: delayed stored-velocity release
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

    case 171: // Unreviewed inherited sibling logic, Makoto address 0x005: frozen hit, one immediate effect
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
                gravity = 0.035;
                ResetPose();
            }
        }
        return;

    case 178: // Unreviewed inherited sibling logic, Makoto address 0x005: dash slide and jump cancel
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
                field0008 = 7;
                ResetPose();
                return;
            }
        }
        return;

    case 180: // Unreviewed inherited sibling logic, Makoto address 0x005: trailing aerial landing
        if (field000a == 0 && field000c == 0) {
            StartTrail(2);
            velocityX = 0.0;
            velocityY = 0.0;
            gravity = 0.0;
        }
        if (positionY < 0.0) {
            velocityY += gravity;
        }
        if (positionY + velocityY > 0.0 && field000a < 10) {
            ResetFrame();
            positionY = 0.0;
            field000c = 0;
            field000a = 10;
            pendingContextSoundSlot = 9;
        }
        ++field000c;
        if (field000c >= timing.frameDuration) {
            field000c = 0;
            ++field000a;
            if (field000a == 1) {
                velocityX = -0.5;
                velocityY = -1.0;
                gravity = 0.028;
            }
            if (field000a == 10) {
                field000a = (unsigned short)(field000a - 2);
            }
            if (field000a >= timing.animationFrameCount) {
                ResetPose();
                field0008 = 0;
            }
        }
        return;

    case 200: // Unreviewed inherited sibling logic, Makoto address 0x005: dash-momentum attack
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

    case 201: // Unreviewed inherited sibling logic, Makoto address 0x005: dash-momentum attack
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

    case 202: // Unreviewed inherited sibling logic, Makoto address 0x005: local hit effect on advanced pose
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
            meter = (short)(meter + 15);
            pendingContextSoundSlot = 20;
            remainingHitCount = 1;
        }
        ++field000c;
        if (field000c >= timing.frameDuration) {
            field000c = 0;
            ++field000a;
            if (field000a < 2) {
                attackCollisionResult = 0;
            }
            if (field000a == 4) {
                pendingCharacterSoundSlot = 0;
                effect.type = 0x19d;
                effect.x = (double)((int)positionX + (int)facing * 34);
                effect.y = (double)((int)positionY - 31);
                effect.flag0018 = (unsigned char)facing;
                effect.layer = 1;
                effect.group = 2;
                EmitLocalEffect(&effect);
            }
            if (field000a >= timing.animationFrameCount) {
                field0008 = 0;
                FaceOpponent();
                ResetPose();
            }
        }
        return;

    case 203: // Unreviewed inherited sibling logic, Makoto address 0x005: repeatable charged hit
        if ((unsigned char)dashMomentumFlag == 0) {
            velocityX = 0.0;
            velocityY = 0.0;
        }
        if (velocityX > 0.0 && (unsigned char)dashMomentumFlag == 1) {
            velocityX -= 0.06;
        } else {
            velocityX = 0.0;
            dashMomentumFlag = 0;
        }
        if (field000a == 0 && field000c == 0) {
            remainingHitCount = 1;
        }
        if (field000a == 10 && buttonPulse[2] == 1 && field3138 < 2) {
            pendingCharacterSoundSlot = 0;
            field000c = 0;
            field000a = 6;
            pendingCharacterSoundSlot = 0;
            attackCollisionResult = 0;
            remainingHitCount = 1;
            meter = (short)(meter + 15);
            ++field3138;
            effect.type = 400;
            effect.x = (double)((int)positionX + (int)facing * 90);
            effect.y = (double)((int)positionY - 50);
            effect.flag0018 = (unsigned char)facing;
            effect.layer = 1;
            effect.group = 2;
            EmitLocalEffect(&effect);
        }
        ++field000c;
        if (field000c >= timing.frameDuration) {
            field000c = 0;
            ++field000a;
            if (field000a < 7) {
                attackCollisionResult = 0;
            }
            if (field000a == 6) {
                remainingHitCount = 1;
                pendingCharacterSoundSlot = 0;
                effect.type = 400;
                effect.x = (double)((int)positionX + (int)facing * 90);
                effect.y = (double)((int)positionY - 50);
                effect.flag0018 = (unsigned char)facing;
                effect.layer = 1;
                effect.group = 2;
                EmitLocalEffect(&effect);
            }
            if (field000a >= timing.animationFrameCount) {
                field0008 = 0;
                FaceOpponent();
                ResetPose();
            }
        }
        return;

    case 204: // Unreviewed inherited sibling logic, Makoto address 0x005: grounded dash cancel and recovery
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

    case 205: // Unreviewed inherited sibling logic, Makoto address 0x005: grounded dash cancel and recovery
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
        if (field000c >= timing.frameDuration) {
            field000c = 0;
            ++field000a;
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

    case 206: // Unreviewed inherited sibling logic, Makoto address 0x005: accelerating repeatable dash strike
        if (field000a < 2) {
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
        if (velocityX > 0.0) {
            dashMomentumFlag = 0;
            velocityX -= 0.02;
            if (velocityX < 0.0) {
                velocityX = 0.0;
            }
        }
        if (field000a == 2 && field000c == 0) {
            meter = (short)(meter + 25);
            pendingContextSoundSlot = 20;
            remainingHitCount = 1;
        }
        ++field000c;
        if (field000c >= timing.frameDuration) {
            field000c = 0;
            ++field000a;
            if (field000a == 1) {
                attackCollisionResult = 0;
            }
            if (field000a == 2) {
                velocityX = 1.9;
            }
            if (field000a == 6 && field3138 < 4) {
                field000a = (unsigned short)(field000a - 3);
                ++field3138;
                if (field3138 > 2) {
                    remainingHitCount = 0;
                }
            }
            if (field000a >= timing.animationFrameCount) {
                field0008 = 3;
                FaceOpponent();
                ResetPose();
            }
        }
        return;

    case 207: // Unreviewed inherited sibling logic, Makoto address 0x005: aerial attack with jump cancel
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

    case 208: // Unreviewed inherited sibling logic, Makoto address 0x005: aerial attack with jump cancel
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
            meter = (short)(meter + 13);
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
            if (field000a < 2) {
                attackCollisionResult = 0;
            }
            if (field000a >= timing.animationFrameCount) {
                field0008 = 9;
                ResetPose();
            }
        }
        return;

    case 209: // Unreviewed inherited sibling logic, Makoto address 0x005: repeated aerial local attack
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
        if (field000a > 4 && buttonPulse[2] == 1 && field3138 < 2) {
            field000c = 0;
            field000a = 3;
            ++field3138;
            attackCollisionResult = 0;
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
            if (field000a == 4) {
                meter = (short)(meter + 15);
                pendingContextSoundSlot = 20;
                remainingHitCount = 1;
                pendingCharacterSoundSlot = 0;
                effect.type = 0x191;
                effect.x = (double)((int)positionX + (int)facing * 27);
                effect.y = (double)((int)positionY - 28);
                effect.flag0018 = (unsigned char)facing;
                effect.layer = 1;
                effect.group = 2;
                EmitLocalEffect(&effect);
            }
            if (field000a < 2) {
                attackCollisionResult = 0;
            }
            if (field000a >= timing.animationFrameCount) {
                field000a = (unsigned short)(field000a - 2);
            }
        }
        return;

    case 210: // Unreviewed inherited sibling logic, Makoto address 0x005: impact-driven crouch recovery
        if (field000a == 0 && field000c == 0) {
            dashMomentumFlag = 0;
            ResetFrame();
        }
        if (field000a == 3 && field000c == 0) {
            velocityX = 0.6;
            velocityY = -1.4;
            gravity = 0.036;
        }
        if (field000a == 6 && field000c == 0) {
            meter = (short)(meter + 20);
            pendingContextSoundSlot = 20;
            remainingHitCount = 1;
        }
        if (field000a > 2) {
            velocityY += gravity;
        }
        if (positionY + velocityY > 0.0 && field000a < 9 && field000a > 3) {
            positionY = 0.0;
            ResetFrame();
            field000c = 0;
            field000a = 9;
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
                field0008 = 3;
                FaceOpponent();
                ResetPose();
            }
        }
        return;

    case 211: // Unreviewed inherited sibling logic, Makoto address 0x005: airborne pose-5 local hit effect
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
        ++field000c;
        if (field000c >= timing.frameDuration) {
            field000c = 0;
            ++field000a;
            if (field000a == 5) {
                meter = (short)(meter + 15);
                pendingContextSoundSlot = 20;
                remainingHitCount = 1;
                pendingCharacterSoundSlot = 0;
                effect.type = 400;
                effect.x = (double)((int)positionX + (int)facing * 45);
                effect.y = (double)((int)positionY - 62);
                effect.flag0018 = (unsigned char)facing;
                effect.layer = 1;
                effect.group = 2;
                EmitLocalEffect(&effect);
            }
            if (field000a < 2) {
                attackCollisionResult = 0;
            }
            if (field000a >= timing.animationFrameCount) {
                field000a = (unsigned short)(field000a - 2);
            }
        }
        return;

    case 212: // Unreviewed inherited sibling logic, Makoto address 0x005: aerial bounce and landing flash
        velocityY += gravity;
        if (field000a == 0 && field000c == 0) {
            meter = (short)(meter + 30);
            pendingContextSoundSlot = 20;
            remainingHitCount = 1;
            velocityX /= 2.0;
            gravity = 0.07;
        }
        if (attackCollisionResult > 1) {
            field0008 = 213;
            ResetPose();
            ResetFrame();
            return;
        }
        if (positionY + velocityY >= 0.0) {
            positionY = 0.0;
            velocityY = 0.0;
            SetVerticalShake(3, 0);
            effect.type = 3;
            effect.x = (double)(int)positionX;
            effect.y = (double)(int)positionY;
            effect.group = 2;
            effect.layer = 0;
            effect.palette = 7;
            contextOwner->EmitEffect(&effect);
            pendingContextSoundSlot = 7;
            field0008 = 214;
            ResetPose();
            return;
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

    case 213: // Unreviewed inherited sibling logic, Makoto address 0x005: upward hit recoil
        gravity = 0.042;
        velocityY += gravity;
        if (field000a == 0 && field000c == 0) {
            velocityX = -1.0;
            velocityY = -2.4;
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

    case 214: // Unreviewed inherited sibling logic, Makoto address 0x005: grounded hit flash and recovery
        velocityX = 0.0;
        velocityY = 0.0;
        if (field000a == 0 && field000c == 0) {
            SetVerticalShake(3, 0);
            effect.type = 3;
            effect.x = (double)(int)positionX;
            effect.y = (double)(int)positionY;
            effect.group = 2;
            effect.layer = 0;
            effect.palette = 7;
            contextOwner->EmitEffect(&effect);
        }
        ++field000c;
        if (field000c >= timing.frameDuration) {
            field000c = 0;
            ++field000a;
            attackCollisionResult = 0;
            if (field000a >= timing.animationFrameCount) {
                field0008 = 7;
                if (inputY == 1) {
                    field0008 = 3;
                }
                FaceOpponent();
                ResetPose();
            }
        }
        return;

    case 220: // Unreviewed inherited sibling logic, Makoto address 0x005: opponent grab and impact effect
        velocityX = 0.0;
        velocityY = 0.0;
        dashMomentumFlag = 0;
        if (field000a == 1 && field000c == 0 &&
            (*opponentSlot)->positionY == 0.0) {
            remainingHitCount = 1;
        } else {
            remainingHitCount = 0;
        }
        if (field000a == 1 && attackCollisionResult == 3) {
            velocityX = 0.0;
            velocityY = 0.0;
            outgoingPushbackVelocityX = 0.0;
            ResetPose();
            (*opponentSlot)->ResetPose();
            (*opponentSlot)->ResetFrame();
            field0008 = 221;
            (*opponentSlot)->field0008 = 107;
            effect.type = 0;
            effect.x = (double)((int)positionX + (int)facing * 25);
            effect.y = (double)((int)positionY - 51);
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
                field0008 = 0;
                FaceOpponent();
                ResetPose();
            }
        }
        return;

    case 221: // Unreviewed inherited sibling logic, Makoto address 0x005: follow-through after opponent grab
        if (field000a == 1 && field000c == 0) {
            (*opponentSlot)->ResetPose();
            (*opponentSlot)->ResetFrame();
            (*opponentSlot)->field0008 = 50;
        }
        if (field000a > 2) {
            velocityY += gravity;
            velocityX -= 0.045;
            if (velocityX < 0.0) {
                velocityX = 0.0;
            }
        }
        if (field000a < 9 && field000a > 2 &&
            velocityY + positionY > 0.0) {
            field000a = 9;
            field000c = 0;
            positionY = 0.0;
            ResetFrame();
            return;
        }
        ++field000c;
        if (field000c >= timing.frameDuration) {
            field000c = 0;
            ++field000a;
            attackCollisionResult = 0;
            if (field000a == 2) {
                velocityX = 1.5;
                velocityY = -1.6;
                gravity = 0.05;
                effect.type = 31;
                effect.x = (double)(int)positionX;
                effect.y = 0.0;
                effect.group = 0;
                effect.layer = 0;
                effect.facing = facing != 1;
                contextOwner->EmitEffect(&effect);
            }
            if (field000a == 4) {
                pendingContextSoundSlot = 21;
                remainingHitCount = 1;
                meter = (short)(meter + 30);
            }
            if (field000a >= timing.animationFrameCount) {
                field0008 = 0;
                ResetPose();
            }
        }
        return;

    case 230: // Unreviewed inherited sibling logic, Makoto address 0x005: grounded trail strike
        StartTrail(3);
        dashMomentumFlag = 0;
        if (velocityX > 0.0) {
            velocityX -= 0.03;
        } else {
            velocityX = 0.0;
            dashMomentumFlag = 0;
        }
        if (velocityX < 0.0) {
            velocityX = 0.0;
        }
        if (field000a == 0 && field000c == 0) {
            velocityY = 0.0;
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
            attackCollisionResult = 0;
            if (field000a >= timing.animationFrameCount) {
                field0008 = 0;
                ResetPose();
            }
        }
        return;

    case 231: // Unreviewed inherited sibling logic, Makoto address 0x005: grounded trail strike
        StartTrail(3);
        dashMomentumFlag = 0;
        if (velocityX > 0.0) {
            velocityX -= 0.03;
        } else {
            velocityX = 0.0;
            dashMomentumFlag = 0;
        }
        if (velocityX < 0.0) {
            velocityX = 0.0;
        }
        if (field000a == 0 && field000c == 0) {
            velocityY = 0.0;
        }
        if (field000a == 2 && field000c == 0) {
            meter = (short)(meter + 10);
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
                ResetPose();
            }
        }
        return;

    case 232: // Unreviewed inherited sibling logic, Makoto address 0x005: launched strike with landing shortcut
        dashMomentumFlag = 0;
        StartTrail(3);
        if (field000a == 0 && field000c == 0) {
            horizontalDeceleration = 0.0;
            remainingHitCount = 1;
        }
        if (field000a < 3) {
            velocityX -= 0.035;
            if (velocityX < 0.0) {
                velocityX = 0.0;
            }
        }
        if (field000a == 3 && field000c == 0) {
            meter = (short)(meter + 25);
            pendingContextSoundSlot = 20;
        }
        if (field000a == 3) {
            velocityY += gravity;
            if (positionY + velocityY > 0.0) {
                positionY = 0.0;
                ResetFrame();
                field000c = 0;
                field000a = 4;
                return;
            }
        }
        ++field000c;
        if (field000c >= timing.frameDuration) {
            field000c = 0;
            ++field000a;
            if (field000a == 3) {
                velocityX = 1.8;
                velocityY = -1.5;
                gravity = 0.045;
            }
            if (field000a >= timing.animationFrameCount) {
                field0008 = 0;
                FaceOpponent();
                ResetPose();
            }
        }
        return;

    case 248: // Unreviewed inherited sibling logic, Makoto address 0x005: airborne grab and opponent capture
        velocityY += gravity;
        if (field000a == 1 && attackCollisionResult == 3) {
            (*opponentSlot)->ResetFrame();
            (*opponentSlot)->ResetPose();
            ResetFrame();
            (*opponentSlot)->airActionDisabled = 1;
            field000a = 0;
            field000c = 0;
            field0008 = 249;
            (*opponentSlot)->field0008 = 110;
            (*opponentSlot)->positionY = positionY;
            (*opponentSlot)->positionX = positionX + (double)((int)facing * 19);
            return;
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
                field0008 = 211;
                field000a = 1;
            }
        }
        return;

    case 249: // Unreviewed inherited sibling logic, Makoto address 0x005: airborne throw and landing impact
        field013e = 30;
        (*opponentSlot)->field013e = 30;
        dashMomentumFlag = 0;
        if (field000a == 0 && field000c == 0) {
            velocityX = -2.5;
            velocityY = -4.5;
            gravity = 0.045;
        }
        velocityY += gravity;
        if (field000a < 8) {
            velocityX += 0.035;
            if (velocityX > 0.0) {
                velocityX = 0.0;
            }
            (*opponentSlot)->positionY = positionY;
            (*opponentSlot)->positionX = positionX + (double)((int)facing * 19);
            if (velocityY + positionY > 0.0) {
                positionY = 0.0;
                (*opponentSlot)->positionY = 0.0;
                (*opponentSlot)->positionX = positionX;
                field000c = 0;
                field000a = 8;
                effect.type = 0;
                effect.palette = 2;
                effect.x = (double)(int)positionX;
                effect.y = (double)(int)positionY;
                effect.group = 2;
                effect.layer = 1;
                contextOwner->EmitEffect(&effect);
                (*opponentSlot)->ResetPose();
                (*opponentSlot)->field0008 = 98;
                return;
            }
        }
        if (field000a == 8 && field000c == 0) {
            hitstopFrames = 60;
            (*opponentSlot)->hitstopFrames = 60;
            ApplyDamage(1100, 500.0);
        }
        if (field000a == 9 && field000c == 0) {
            velocityY = -1.5;
            velocityX = -1.3;
            gravity = 0.035;
        }
        if (field000a > 9 && positionY + velocityY > 0.0) {
            ResetPose();
            ResetFrame();
            positionY = 0.0;
            field0008 = 13;
            return;
        }
        ++field000c;
        if (field000c >= timing.frameDuration) {
            field000c = 0;
            ++field000a;
            attackCollisionResult = 0;
            if (field000a == 3) {
                (*opponentSlot)->field0008 = 121;
            }
            if (field000a >= timing.animationFrameCount) {
                field000a = (unsigned short)(field000a - 2);
            }
        }
        return;

    case 250: // Unreviewed inherited sibling logic, Makoto address 0x005: local special-effect finisher
        if (field000a == 0 && field000c == 0) {
            dashMomentumFlag = 0;
            ResetFrame();
            meter = (short)(meter + 45);
        }
        ++field000c;
        if (field000c >= timing.frameDuration) {
            field000c = 0;
            ++field000a;
            attackCollisionResult = 3;
            if (field000a == 3) {
                effect.type = 403;
                effect.x = (double)((int)positionX + (int)facing * 23);
                effect.y = (double)((int)positionY - 76);
                effect.group = 0;
                effect.owner = 1;
                effect.layer = 1;
                effect.flag0018 = (unsigned char)facing;
                EmitLocalEffect(&effect);
                pendingContextSoundSlot = 21;
                pendingCharacterSoundSlot = 5;
            }
            if (field000a >= timing.animationFrameCount) {
                field0008 = 0;
                ResetPose();
            }
        }
        return;

    case 251: // Unreviewed inherited sibling logic, Makoto address 0x005: local special-effect finisher
        if (field000a == 0 && field000c == 0) {
            dashMomentumFlag = 0;
            ResetFrame();
            meter = (short)(meter + 45);
        }
        ++field000c;
        if (field000c >= timing.frameDuration) {
            field000c = 0;
            ++field000a;
            attackCollisionResult = 3;
            if (field000a == 3) {
                effect.type = 404;
                effect.x = (double)((int)positionX + (int)facing * 23);
                effect.y = (double)((int)positionY - 76);
                effect.group = 0;
                effect.owner = 1;
                effect.layer = 1;
                effect.flag0018 = (unsigned char)facing;
                EmitLocalEffect(&effect);
                pendingContextSoundSlot = 21;
                pendingCharacterSoundSlot = 5;
            }
            if (field000a >= timing.animationFrameCount) {
                field0008 = 0;
                ResetPose();
            }
        }
        return;

    case 252: // Unreviewed inherited sibling logic, Makoto address 0x005: two-phase special effect finisher
        if (field000a == 0 && field000c == 0) {
            dashMomentumFlag = 0;
            ResetFrame();
            meter = (short)(meter + 45);
            if (field0120 == 0) {
                field0118 -= 500.0;
            } else {
                field0118 -= 250.0;
            }
            effect.type = 33;
            effect.palette = 11;
            effect.x = (double)(int)positionX;
            effect.y = (double)((int)positionY - 50);
            effect.group = 2;
            effect.layer = 1;
            contextOwner->EmitEffect(&effect);
        }
        if (field000a == 3) {
            effect.type = 0x195;
            effect.x = (double)((int)positionX + (int)facing * 23);
            effect.y = (double)((int)positionY - 76);
            effect.group = 0;
            effect.owner = 1;
            effect.layer = 1;
            effect.flag0018 = (unsigned char)facing;
            EmitLocalEffect(&effect);
            pendingContextSoundSlot = 21;
            pendingCharacterSoundSlot = 5;
        }
        ++field000c;
        if (field000c >= timing.frameDuration) {
            field000c = 0;
            ++field000a;
            attackCollisionResult = 3;
            if (field000a == 3) {
                effect.type = 0x195;
                effect.x = (double)((int)positionX + (int)facing * 23);
                effect.y = (double)((int)positionY - 76);
                effect.group = 0;
                effect.owner = 1;
                effect.layer = 1;
                effect.flag0018 = (unsigned char)facing;
                EmitLocalEffect(&effect);
                pendingContextSoundSlot = 21;
            }
            if (field000a >= timing.animationFrameCount) {
                field0008 = 0;
                ResetPose();
            }
        }
        return;

    case 253: // Unreviewed inherited sibling logic, Makoto address 0x005: pose-4 local impact finisher
        if (field000a == 0 && field000c == 0) {
            dashMomentumFlag = 0;
            ResetFrame();
            meter = (short)(meter + 45);
        }
        ++field000c;
        if (field000c >= timing.frameDuration) {
            field000c = 0;
            ++field000a;
            attackCollisionResult = 3;
            if (field000a == 4) {
                effect.type = 406;
                effect.x = (double)((int)positionX + (int)facing * 17);
                effect.y = (double)((int)positionY - 26);
                effect.group = 0;
                effect.owner = 1;
                effect.layer = 1;
                effect.flag0018 = (unsigned char)facing;
                effect.field0028 = 1;
                EmitLocalEffect(&effect);
                pendingContextSoundSlot = 21;
            }
            if (field000a >= timing.animationFrameCount) {
                field0008 = 0;
                ResetPose();
            }
        }
        return;

    case 254: // Unreviewed inherited sibling logic, Makoto address 0x005: pose-4 local impact finisher
        if (field000a == 0 && field000c == 0) {
            dashMomentumFlag = 0;
            ResetFrame();
            meter = (short)(meter + 45);
        }
        ++field000c;
        if (field000c >= timing.frameDuration) {
            field000c = 0;
            ++field000a;
            attackCollisionResult = 3;
            if (field000a == 4) {
                effect.type = 407;
                effect.x = (double)((int)positionX + (int)facing * 17);
                effect.y = (double)((int)positionY - 26);
                effect.group = 0;
                effect.owner = 1;
                effect.layer = 1;
                effect.flag0018 = (unsigned char)facing;
                effect.field0028 = 1;
                EmitLocalEffect(&effect);
                pendingContextSoundSlot = 21;
            }
            if (field000a >= timing.animationFrameCount) {
                field0008 = 0;
                ResetPose();
            }
        }
        return;

    case 256: // Unreviewed inherited sibling logic, Makoto address 0x005: aerial launcher and hit flash
        if (field000a == 0 && field000c == 0) {
            dashMomentumFlag = 0;
            ResetFrame();
        }
        if (field000a > 1) {
            velocityY += gravity;
            velocityX -= 0.045;
            if (velocityX < 0.0) {
                velocityX = 0.0;
            }
        }
        if (field000a < 8 && field000a > 1 &&
            velocityY + positionY > 0.0) {
            field000a = 8;
            field000c = 0;
            positionY = 0.0;
            ResetFrame();
            return;
        }
        ++field000c;
        if (field000c >= timing.frameDuration) {
            field000c = 0;
            ++field000a;
            if (field000a < 2) {
                attackCollisionResult = 0;
            }
            if (field000a == 1) {
                velocityX = 1.5;
                velocityY = -1.5;
                gravity = 0.05;
                effect.type = 31;
                effect.x = (double)(int)positionX;
                effect.y = 0.0;
                effect.group = 0;
                effect.layer = 0;
                effect.facing = facing != 1;
                contextOwner->EmitEffect(&effect);
            }
            if (field000a == 3) {
                pendingContextSoundSlot = 21;
                remainingHitCount = 1;
                meter = (short)(meter + 30);
            }
            if (field000a >= timing.animationFrameCount) {
                field0008 = 0;
                ResetPose();
            }
        }
        return;

    case 257: // Unreviewed inherited sibling logic, Makoto address 0x005: aerial launcher and hit flash
        if (field000a == 0 && field000c == 0) {
            dashMomentumFlag = 0;
            ResetFrame();
        }
        if (field000a > 1) {
            velocityY += gravity;
            velocityX -= 0.045;
            if (velocityX < 0.0) {
                velocityX = 0.0;
            }
        }
        if (field000a < 8 && field000a > 1 &&
            velocityY + positionY > 0.0) {
            field000a = 8;
            field000c = 0;
            positionY = 0.0;
            ResetFrame();
            return;
        }
        ++field000c;
        if (field000c >= timing.frameDuration) {
            field000c = 0;
            ++field000a;
            if (field000a < 2) {
                attackCollisionResult = 0;
            }
            if (field000a == 1) {
                velocityX = 1.5;
                velocityY = -1.8;
                gravity = 0.05;
                effect.type = 31;
                effect.x = (double)(int)positionX;
                effect.y = 0.0;
                effect.group = 0;
                effect.layer = 0;
                effect.facing = facing != 1;
                contextOwner->EmitEffect(&effect);
            }
            if (field000a == 3) {
                pendingContextSoundSlot = 21;
                remainingHitCount = 1;
                meter = (short)(meter + 30);
            }
            if (field000a >= timing.animationFrameCount) {
                field0008 = 0;
                ResetPose();
            }
        }
        return;

    case 258: // Unreviewed inherited sibling logic, Makoto address 0x005: two-wave aerial impact sequence
        if (field000a == 0 && field000c == 0) {
            dashMomentumFlag = 0;
            ResetFrame();
            if (field0120 == 0) {
                field0118 -= 500.0;
            } else {
                field0118 -= 250.0;
            }
            effect.type = 33;
            effect.palette = 11;
            effect.x = (double)(int)positionX;
            effect.y = (double)((int)positionY - 50);
            effect.group = 2;
            effect.layer = 1;
            contextOwner->EmitEffect(&effect);
        }
        if (field000a > 1) {
            velocityY += gravity;
            velocityX -= 0.045;
            if (velocityX < 0.0) {
                velocityX = 0.0;
            }
        }
        if (field000a < 8 && field000a > 1 &&
            velocityY + positionY > 0.0) {
            field000a = 8;
            field000c = 0;
            positionY = 0.0;
            ResetFrame();
            return;
        }
        if (field000a < 19 && field000a > 12 &&
            velocityY + positionY > 0.0) {
            field000a = 19;
            field000c = 0;
            positionY = 0.0;
            ResetFrame();
            return;
        }
        ++field000c;
        if (field000c >= timing.frameDuration) {
            field000c = 0;
            ++field000a;
            if (field000a < 2) {
                attackCollisionResult = 0;
            }
            if (field000a == 1) {
                velocityX = 0.9;
                velocityY = -1.0;
                gravity = 0.05;
                effect.type = 31;
                effect.x = (double)(int)positionX;
                effect.y = 0.0;
                effect.group = 0;
                effect.layer = 0;
                effect.facing = facing != 1;
                contextOwner->EmitEffect(&effect);
            }
            if (field000a == 3) {
                pendingContextSoundSlot = 21;
                remainingHitCount = 1;
                meter = (short)(meter + 30);
            }
            if (field000a == 12) {
                velocityX = 1.4;
                velocityY = -2.9;
                gravity = 0.05;
                attackCollisionResult = 0;
                effect.type = 31;
                effect.x = (double)(int)positionX;
                effect.y = 0.0;
                effect.group = 0;
                effect.layer = 0;
                effect.facing = facing != 1;
                contextOwner->EmitEffect(&effect);
            }
            if (field000a == 13) {
                pendingContextSoundSlot = 21;
                remainingHitCount = 1;
                meter = (short)(meter + 30);
            }
            if (field000a >= timing.animationFrameCount) {
                field0008 = 0;
                ResetPose();
            }
        }
        return;

    case 259: // Unreviewed inherited sibling logic, Makoto address 0x005: paired local impact effects
        if (field000a == 0 && field000c == 0) {
            dashMomentumFlag = 0;
            ResetFrame();
        }
        if (field000a == 4 && field000c == 0) {
            effect.type = 410;
            effect.x = (double)((int)positionX + (int)facing * 36);
            effect.y = (double)((int)positionY - 78);
            effect.flag0018 = (unsigned char)facing;
            effect.layer = 1;
            effect.owner = 1;
            effect.group = 2;
            EmitLocalEffect(&effect);
            effect.type = 0x192;
            effect.x = (double)((int)positionX + (int)facing * 36);
            effect.y = (double)((int)positionY - 78);
            effect.flag0018 = (unsigned char)facing;
            effect.layer = 1;
            effect.group = 2;
            EmitLocalEffect(&effect);
            pendingCharacterSoundSlot = 0;
            field3148 = 1;
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

    case 260: // Unreviewed inherited sibling logic, Makoto address 0x005: paired local impact effects
        if (field000a == 0 && field000c == 0) {
            dashMomentumFlag = 0;
            ResetFrame();
        }
        if (field000a == 4 && field000c == 0) {
            effect.type = 411;
            effect.x = (double)((int)positionX - (int)facing * 36);
            effect.y = (double)((int)positionY - 78);
            effect.flag0018 = (unsigned char)facing;
            effect.layer = 1;
            effect.owner = 1;
            effect.group = 2;
            EmitLocalEffect(&effect);
            effect.type = 0x192;
            effect.x = (double)((int)positionX - (int)facing * 36);
            effect.y = (double)((int)positionY - 78);
            effect.flag0018 = (unsigned char)(-facing);
            effect.layer = 1;
            effect.group = 2;
            EmitLocalEffect(&effect);
            pendingCharacterSoundSlot = 0;
            field3148 = 1;
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

    case 261: // Unreviewed inherited sibling logic, Makoto address 0x005: resource-backed paired effects
        if (field000a == 0 && field000c == 0) {
            dashMomentumFlag = 0;
            ResetFrame();
            if (field0120 == 0) {
                field0118 -= 500.0;
            } else {
                field0118 -= 250.0;
            }
            effect.type = 33;
            effect.palette = 11;
            effect.x = (double)(int)positionX;
            effect.y = (double)((int)positionY - 50);
            effect.group = 2;
            effect.layer = 1;
            contextOwner->EmitEffect(&effect);
        }
        if (field000a == 4 && field000c == 0) {
            effect.type = 0x19c;
            effect.x = (double)((int)positionX + (int)facing * 36);
            effect.y = (double)((int)positionY - 78);
            effect.owner = 1;
            effect.flag0018 = (unsigned char)facing;
            effect.layer = 1;
            effect.group = 2;
            EmitLocalEffect(&effect);
            effect.type = 0x192;
            effect.x = (double)((int)positionX + (int)facing * 36);
            effect.y = (double)((int)positionY - 78);
            effect.flag0018 = (unsigned char)facing;
            effect.layer = 1;
            effect.group = 2;
            EmitLocalEffect(&effect);
            pendingCharacterSoundSlot = 0;
            field3148 = 1;
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

    case 262: // Unreviewed inherited sibling logic, Makoto address 0x005: slowed aerial local finisher
        if (field000a == 0 && field000c == 0) {
            velocityX *= 0.25;
            velocityY *= 0.25;
        }
        ++field000c;
        if (field000c >= timing.frameDuration) {
            field000c = 0;
            ++field000a;
            attackCollisionResult = 3;
            if (field000a == 4) {
                meter = (short)(meter + 45);
                effect.type = 0x196;
                effect.x = (double)((int)positionX + (int)facing * 14);
                effect.y = (double)((int)positionY - 35);
                effect.group = 0;
                effect.owner = 1;
                effect.layer = 1;
                effect.flag0018 = (unsigned char)facing;
                effect.field0028 = 1;
                EmitLocalEffect(&effect);
                pendingContextSoundSlot = 21;
            }
            if (field000a >= timing.animationFrameCount) {
                field0008 = 9;
                ResetPose();
            }
        }
        return;

    case 300: // Unreviewed inherited sibling logic, Makoto address 0x005: super sequence with frozen impact
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
            effect.type = 418;
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

    case 301: // Unreviewed inherited sibling logic, Makoto address 0x005: super sequence with frozen impact
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

    case 302: // Unreviewed inherited sibling logic, Makoto address 0x005: super sequence with frozen impact
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

    case 303: // Unreviewed inherited sibling logic, Makoto address 0x005: extended super and repeated hit bursts
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

    case 304: // Unreviewed inherited sibling logic, Makoto address 0x005: extended super and repeated hit bursts
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

    case 305: // Unreviewed inherited sibling logic, Makoto address 0x005: extended super and repeated hit bursts
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

    case 306: // Unreviewed inherited sibling logic, Makoto address 0x005: sustained super impact and rise
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
