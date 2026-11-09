// First natural-C++ cases of the still-open Makoto state dispatcher.
//
// This is a compileable reconstruction WORKBENCH, not linked into the accepted
// game sources. Cases 1-9, 13-16, 47, 50-77, 81-87, 96-99, 150-158, 161-171, 178, 180 and 200-202 are implemented so far.
// The canonical owner's full code and local tables remain open.
#include "../../src/CharacterViews.h"

void Character03::Slot06()
{
    // Target entry 0x005E85F0: stop this tick if either fighter freezes it.
    if (hitstopFrames > 0 || (*opponentSlot)->hitstunFrames > 0) return;

    // 0x005E8623: construct the effect spawn, snapshot this frame's duration
    // and the animation's frame count, then initialize the spawn's defaults.
    EffectSpawn effect;
    unsigned short frameDuration = patterns[field0008].frames[field000a].duration;
    unsigned short animationFrameCount = patterns[field0008].count;
    ResetLocalEffectSpawn(&effect);

    // The original selector at 0x005F6C56 is an animation-ID-to-case map.
    // Do not use Ghidra's normalized 0..124 case numbers as animation IDs.
    switch (field0008) {
    case 1: // Original block 0x005E8718
        dashMomentumFlag = 0;
        velocityX = 0.7;
        velocityY = 0.0;
        break;

    case 2: // Original block 0x005E8793
        dashMomentumFlag = 0;
        velocityX = -0.7;
        velocityY = 0.0;
        break;

    case 3: // Original block 0x005E880E
        velocityX = 0.0;
        velocityY = 0.0;
        dashMomentumFlag = 0;
        FaceOpponent();
        break;

    case 4: // Original block 0x005E8891: jump with optional dash follow-through
        if (field000a == 0 && field000c == 0) {
            if (dashMomentumFlag == 0) FaceOpponent();
            velocityX = 0.0;
        }
        if (field000a == 3 && field000c == 0) {
            gravity = 0.042;
            velocityY = -2.9;
            if (dashMomentumFlag == 1) {
                velocityX = 0.4;
                dashMomentumFlag = 0;
            }
        }
        if (field000a > 2) velocityY += gravity;

        ++field000c;
        if (field000c >= frameDuration) {
            field000c = 0;
            ++field000a;
            if (field000a >= animationFrameCount) {
                field0008 = 9;
                ResetPose();
            }
        }

        // Landing is checked after the animation counters advance.
        // On the original path the sound request precedes FaceOpponent.
        if (positionY + velocityY >= 0.0 && field000a > 3) {
            positionY = 0.0;
            pendingContextSoundSlot = 9;
            FaceOpponent();
            field0008 = 13;
            ResetPose();
        }
        return;

    case 5: // Original block 0x005E89F4: forward jump with a two-frame loop
        if (field000a == 0 && field000c == 0) {
            if (dashMomentumFlag == 0) FaceOpponent();
            velocityX = 0.0;
        }
        if (field000a == 3 && field000c == 0) {
            gravity = 0.042;
            velocityY = -2.9;
            velocityX = 0.7;
            if (dashMomentumFlag == 1) {
                velocityX = 1.1;
                dashMomentumFlag = 0;
            }
        }
        if (field000a > 2) velocityY += gravity;

        ++field000c;
        if (field000c >= frameDuration) {
            field000c = 0;
            ++field000a;
            if (field000a >= animationFrameCount) {
                // Unlike case 4, do not change animation or ResetPose here.
                // The last two pose frames repeat while airborne.
                field000a = (unsigned short)(field000a - 2);
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

    case 6: // Original block 0x005E8B61: backward jump with a two-frame loop
        if (field000a == 0 && field000c == 0) {
            if (dashMomentumFlag == 0) FaceOpponent();
            velocityX = 0.0;
        }
        if (field000a == 3 && field000c == 0) {
            gravity = 0.042;
            velocityY = -2.9;
            velocityX = -0.7;
            // Unlike case 5, this direction has no dashMomentumFlag override.
        }
        if (field000a > 2) velocityY += gravity;

        ++field000c;
        if (field000c >= frameDuration) {
            field000c = 0;
            ++field000a;
            if (field000a >= animationFrameCount) {
                field000a = (unsigned short)(field000a - 2);
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

    case 7: // Original block 0x005E8CA9: neutral recovery to animation 0
        velocityX = 0.0;
        velocityY = 0.0;
        dashMomentumFlag = 0;
        FaceOpponent();
        ++field000c;
        if (field000c >= frameDuration) {
            field000c = 0;
            ++field000a;
            if (field000a >= animationFrameCount) {
                field0008 = 0;
                ResetPose();
            }
        }
        return;

    case 8: // Original block 0x005E8D36: neutral recovery to animation 3
        velocityX = 0.0;
        velocityY = 0.0;
        dashMomentumFlag = 0;
        FaceOpponent();
        ++field000c;
        if (field000c >= frameDuration) {
            field000c = 0;
            ++field000a;
            if (field000a >= animationFrameCount) {
                field0008 = 3;
                ResetPose();
            }
        }
        return;

    case 9: // Original block 0x005E8DC3: airborne fall and landing reset
        velocityY += gravity;
        dashMomentumFlag = 0;
        ++field000c;
        if (field000c >= frameDuration) {
            field000c = 0;
            ++field000a;
            if (field000a >= animationFrameCount) {
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

    case 13: // Original block 0x005E8E7A: grounded landing recovery
        velocityX = 0.0;
        velocityY = 0.0;
        dashMomentumFlag = 0;
        FaceOpponent();
        ++field000c;
        if (field000c >= frameDuration) {
            field000c = 0;
            ++field000a;
            if (field000a >= animationFrameCount) {
                // The original tests inputY (+0x189) after selecting state 0.
                field0008 = 0;
                if (inputY == 1) field0008 = 3;
                ResetPose();
            }
        }
        return;

    case 14: // Original block 0x005E8F1F: upward launch and landing recovery
        gravity = 0.042;
        if (field000a == 0 && field000c == 0) {
            velocityY = -2.9;
            velocityX = 0.0;
            dashMomentumFlag = 0;
        }
        velocityY += gravity;
        ++field000c;
        if (field000c >= frameDuration) {
            field000c = 0;
            ++field000a;
            if (field000a >= animationFrameCount) {
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

    case 15: // Original block 0x005E902E: forward aerial launch
        gravity = 0.042;
        if (field000a == 0 && field000c == 0) {
            velocityY = -2.9;
            velocityX = 0.7;
            dashMomentumFlag = 0;
        }
        velocityY += gravity;
        ++field000c;
        if (field000c >= frameDuration) {
            field000c = 0;
            ++field000a;
            if (field000a >= animationFrameCount) {
                field000a = (unsigned short)(field000a - 2);
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

    case 16: // Original block 0x005E913B: backward aerial launch
        gravity = 0.042;
        if (field000a == 0 && field000c == 0) {
            velocityY = -2.9;
            velocityX = -0.7;
            dashMomentumFlag = 0;
        }
        velocityY += gravity;
        ++field000c;
        if (field000c >= frameDuration) {
            field000c = 0;
            ++field000a;
            if (field000a >= animationFrameCount) {
                field000a = (unsigned short)(field000a - 2);
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

    case 47: // Original block 0x005E9248: low aerial strike / ground contact
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
        if (field000c >= frameDuration) {
            field000c = 0;
            ++field000a;
            if (field000a == 2) {
                field000a = (unsigned short)(field000a - 2);
            }
            if (field000a >= animationFrameCount) {
                --field000a;
            }
        }
        return;

    case 50: // Original block 0x005E9378: grounded recoil level 1
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
        if (field000c >= frameDuration) {
            field000c = 0;
            ++field000a;
            if (field000a >= animationFrameCount) {
                field0008 = 0;
                if (inputY == 1) field0008 = 3;
                ResetPose();
            }
        }
        return;

    case 51: // Original block 0x005E9569: grounded recoil level 2
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
        if (field000c >= frameDuration) {
            field000c = 0;
            ++field000a;
            if (field000a >= animationFrameCount) {
                field0008 = 0;
                if (inputY == 1) field0008 = 3;
                ResetPose();
            }
        }
        return;

    case 52: // Original block 0x005E975A: grounded recoil level 3
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
        if (field000c >= frameDuration) {
            field000c = 0;
            ++field000a;
            if (field000a >= animationFrameCount) {
                field0008 = 0;
                if (inputY == 1) field0008 = 3;
                ResetPose();
            }
        }
        return;

    case 53: // Original block 0x005e994b: grounded recoil continuation 1
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
        if (field000c >= frameDuration) {
            field000c = 0;
            ++field000a;
            if (field000a >= animationFrameCount) {
                field0008 = 0;
                if (inputY == 1) field0008 = 3;
                ResetPose();
            }
        }
        return;

    case 54: // Original block 0x005e9b3c: grounded recoil continuation 2
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
        if (field000c >= frameDuration) {
            field000c = 0;
            ++field000a;
            if (field000a >= animationFrameCount) {
                field0008 = 0;
                if (inputY == 1) field0008 = 3;
                ResetPose();
            }
        }
        return;

    case 55: // Original block 0x005e9d2d: grounded recoil continuation 3
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
        if (field000c >= frameDuration) {
            field000c = 0;
            ++field000a;
            if (field000a >= animationFrameCount) {
                field0008 = 0;
                if (inputY == 1) field0008 = 3;
                ResetPose();
            }
        }
        return;

    case 56: // Original block 0x005E9F1E: recoil returning directly to crouch
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
        if (field000c >= frameDuration) {
            field000c = 0;
            ++field000a;
            if (field000a >= animationFrameCount) {
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
        if (field000c >= frameDuration) {
            field000c = 0;
            ++field000a;
            if (field000a >= animationFrameCount) {
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
        if (field000c >= frameDuration) {
            field000c = 0;
            ++field000a;
            if (field000a >= animationFrameCount) {
                // Unlike cases 50-55, this recovery always chooses crouch.
                field0008 = 3;
                ResetPose();
            }
        }
        return;

    case 59: // Original block 0x005EA4A9: airborne hit reaction
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
        if (field000c >= frameDuration) {
            field000c = 0;
            ++field000a;
            if (field000a >= animationFrameCount) {
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
        if (field000c >= frameDuration) {
            field000c = 0;
            ++field000a;
            if (field000a >= animationFrameCount) {
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
        if (field000c >= frameDuration) {
            field000c = 0;
            ++field000a;
            if (field000a >= animationFrameCount) {
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

    case 62: // Original block 0x005EAAA6: unclamped airborne hit reaction
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
        if (field000c >= frameDuration) {
            field000c = 0;
            ++field000a;
            if (field000a >= animationFrameCount) {
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

    case 63: // Original block 0x005EAC5D: direct-velocity aerial hit reaction
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
        if (field000c >= frameDuration) {
            field000c = 0;
            ++field000a;
            if (field000a >= animationFrameCount) {
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

    case 64: // Original block 0x005EAE08: wall-aware airborne reaction
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
        if (field000c >= frameDuration) {
            field000c = 0;
            ++field000a;
            if (field000a >= animationFrameCount) {
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

    case 65: // Original block 0x005EB039: stronger wall-aware airborne reaction
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
        if (field000c >= frameDuration) {
            field000c = 0;
            ++field000a;
            if (field000a >= animationFrameCount) {
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

    case 66: // Original block 0x005EB26A: unclamped wall-aware airborne reaction
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
        if (field000c >= frameDuration) {
            field000c = 0;
            ++field000a;
            if (field000a >= animationFrameCount) {
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

    case 67: // Original block 0x005EB453: direct-speed wall-contact reaction
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
        if (field000c >= frameDuration) {
            field000c = 0;
            ++field000a;
            if (field000a >= animationFrameCount) {
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

    case 68: // Original block 0x005EB630: collision-cancelled airborne recovery
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
        if (field000c >= frameDuration) {
            field000c = 0;
            ++field000a;
            if (field000a >= animationFrameCount) {
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

    case 69: // Original block 0x005EB76C: airborne recovery without wall cancel
        if (field0120 != 0) {
            field0118 -= 1.5;
        }
        meter = (short)(meter + 3);
        velocityX = knockbackVelocityX;
        velocityY = knockbackVelocityY;
        ++field000c;
        if (field000c >= frameDuration) {
            field000c = 0;
            ++field000a;
            if (field000a >= animationFrameCount) {
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

    case 70: // Original block 0x005EB881: wall recovery with global effect
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
        if (field000c >= frameDuration) {
            field000c = 0;
            ++field000a;
            if (field000a >= animationFrameCount) {
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

    case 71: // Original block 0x005EBA61: high-gravity direct-speed air reaction
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
        if (field000c >= frameDuration) {
            field000c = 0;
            ++field000a;
            if (field000a >= animationFrameCount) {
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

    case 72: // Original block 0x005EBC0C: grounded recoil with stage pushback
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
        if (field000c >= frameDuration) {
            field000c = 0;
            ++field000a;
            if (field000a >= animationFrameCount) {
                field0008 = 7;
                if (inputY == 1) {
                    field0008 = 3;
                }
                ResetPose();
            }
        }
        return;

    case 73: // Original block 0x005EBD61: separate grounded recoil continuation
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
        if (field000c >= frameDuration) {
            field000c = 0;
            ++field000a;
            if (field000a >= animationFrameCount) {
                field0008 = 7;
                if (inputY == 1) {
                    field0008 = 3;
                }
                ResetPose();
            }
        }
        return;

    case 74: // Original block 0x005EBEB6: grounded recoil to crouch
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
        if (field000c >= frameDuration) {
            field000c = 0;
            ++field000a;
            if (field000a >= animationFrameCount) {
                field0008 = 3;
                ResetPose();
            }
        }
        return;

    case 75: // Original block 0x005EBFF3: forward grounded recoil
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
        if (velocityX <= 0.0) {
            velocityX = 0.0;
        }
        if (positionX - 20.0 <= 0.0 || positionX + 20.0 >= 639.0) {
            outgoingPushbackVelocityX =
                (1.0 - (double)((*opponentSlot)->positionY < 0.0) * 0.25) * velocityX;
        } else {
            outgoingPushbackVelocityX = 0.0;
        }
        ++field000c;
        if (field000c >= frameDuration) {
            field000c = 0;
            ++field000a;
            if (field000a >= animationFrameCount) {
                field0008 = 7;
                if (inputY == 1) {
                    field0008 = 3;
                }
                ResetPose();
            }
        }
        return;

    case 76: // Original block 0x005EC1F0: independent duplicate of recoil 75
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
        if (velocityX <= 0.0) {
            velocityX = 0.0;
        }
        if (positionX - 20.0 <= 0.0 || positionX + 20.0 >= 639.0) {
            outgoingPushbackVelocityX =
                (1.0 - (double)((*opponentSlot)->positionY < 0.0) * 0.25) * velocityX;
        } else {
            outgoingPushbackVelocityX = 0.0;
        }
        ++field000c;
        if (field000c >= frameDuration) {
            field000c = 0;
            ++field000a;
            if (field000a >= animationFrameCount) {
                field0008 = 7;
                if (inputY == 1) {
                    field0008 = 3;
                }
                ResetPose();
            }
        }
        return;

    case 77: // Original block 0x005EC3ED: recoil ends in crouch
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
        if (velocityX <= 0.0) {
            velocityX = 0.0;
        }
        if (positionX - 20.0 <= 0.0 || positionX + 20.0 >= 639.0) {
            outgoingPushbackVelocityX =
                (1.0 - (double)((*opponentSlot)->positionY < 0.0) * 0.25) * velocityX;
        } else {
            outgoingPushbackVelocityX = 0.0;
        }
        ++field000c;
        if (field000c >= frameDuration) {
            field000c = 0;
            ++field000a;
            if (field000a >= animationFrameCount) {
                field0008 = 3;
                ResetPose();
            }
        }
        return;

    case 81: // Original block 0x005EC5D2: airborne recoil and local hit effect
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
        if (field000c >= frameDuration) {
            field000c = 0;
            ++field000a;
            if (field000a >= animationFrameCount) {
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

    case 82: // Original block 0x005EC7B7: repeated airborne lift and knockback
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
        if (field000c >= frameDuration) {
            field000c = 0;
            ++field000a;
            if (field000a == 4 && field3138 < 8) {
                field000a = 0;
                ++field3138;
            }
            if (field000a >= animationFrameCount) {
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

    case 83: // Original block 0x005EC9D9: airborne ground-impact recovery
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
        if (field000a == 0 && positionY + velocityY > 0.0) {
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
        if (field000c >= frameDuration) {
            field000c = 0;
            ++field000a;
            if (field000a >= animationFrameCount) {
                field0008 = 0;
                ResetPose();
                FaceOpponent();
            }
        }
        return;

    case 84: // Original block 0x005ECC1E: independent ground-impact recovery
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
        if (field000a == 0 && positionY + velocityY > 0.0) {
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
        if (field000c >= frameDuration) {
            field000c = 0;
            ++field000a;
            if (field000a >= animationFrameCount) {
                field0008 = 0;
                ResetPose();
                FaceOpponent();
            }
        }
        return;

    case 85: // Original block 0x005ECE63: direct airborne knockback and landing
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
        if (field000c >= frameDuration) {
            field000c = 0;
            ++field000a;
            if (field000a >= animationFrameCount) {
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

    case 86: // Original block 0x005ED036: one-shot lift and landing recoil
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
        if (field000c >= frameDuration) {
            field000c = 0;
            ++field000a;
            if (field000a >= animationFrameCount) {
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

    case 87: // Original block 0x005ED218: fixed-position effect and idle return
        if (field000a == 0 && field000c == 0) {
            effect.type = 0x1ef;
            effect.x = 60.0;
            effect.y = 40.0;
            effect.palette = 1;
            effect.flag0018 = 1;
            effect.group = 0;
            effect.layer = 0;
            EmitLocalEffect(&effect);
        }
        ++field000c;
        if (field000c >= frameDuration) {
            field000c = 0;
            ++field000a;
            if (field000a >= animationFrameCount) {
                field0008 = 0;
                ResetPose();
            }
        }
        return;

    case 96: // Original block 0x005ED2CB: stand/crouch wakeup timing
        ++field000c;
        if (field000c >= frameDuration) {
            field000c = 0;
            ++field000a;
            // Face one frame before the animation ends, not at the end.
            if (field000a == animationFrameCount - 1) {
                FaceOpponent();
            }
            if (field000a >= animationFrameCount) {
                field0008 = 7;
                if (inputY == 1) {
                    field0008 = 3;
                }
                ResetPose();
            }
        }
        return;

    case 97: // Original block 0x005ED360: first impact flash
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
        if (field000c >= frameDuration) {
            field000c = 0;
            ++field000a;
            if (field000a >= animationFrameCount) {
                field0008 = 99;
                ResetPose();
            }
        }
        return;

    case 98: // Original block 0x005ED458: separately dispatched impact flash
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
        if (field000c >= frameDuration) {
            field000c = 0;
            ++field000a;
            if (field000a >= animationFrameCount) {
                field0008 = 99;
                ResetPose();
            }
        }
        return;

    case 99: // Original block 0x005ED550: end of knockout recovery
        dashMomentumFlag = 0;
        // The target deliberately checks the tick count without a pose gate.
        if (health > 0 && field000c > 99) {
            field0008 = 96;
            ResetPose();
        }
        ++field000c;
        if (field000c >= frameDuration) {
            field000c = 0;
            ++field000a;
            if (field000a == animationFrameCount) {
                FaceOpponent();
            }
            if (field000a >= animationFrameCount) {
                field0008 = 96;
                ResetPose();
            }
        }
        return;

    case 150: // Original block 0x005ED5FF: {'stand/crouch' if terminal == 0 else 'crouching'} recoil
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
        if (field000c >= frameDuration) {
            field000c = 0;
            ++field000a;
            if (field000a == animationFrameCount) {
                FaceOpponent();
            }
            if (field000a >= animationFrameCount) {
                field0008 = 0;
                if (inputY == 1) {
                    field0008 = 3;
                }
                ResetPose();
            }
        }
        return;

    case 151: // Original block 0x005ED7AB: {'stand/crouch' if terminal == 0 else 'crouching'} recoil
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
        if (field000c >= frameDuration) {
            field000c = 0;
            ++field000a;
            if (field000a == animationFrameCount) {
                FaceOpponent();
            }
            if (field000a >= animationFrameCount) {
                field0008 = 0;
                if (inputY == 1) {
                    field0008 = 3;
                }
                ResetPose();
            }
        }
        return;

    case 152: // Original block 0x005ED957: {'stand/crouch' if terminal == 0 else 'crouching'} recoil
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
        if (field000c >= frameDuration) {
            field000c = 0;
            ++field000a;
            if (field000a == animationFrameCount) {
                FaceOpponent();
            }
            if (field000a >= animationFrameCount) {
                field0008 = 0;
                if (inputY == 1) {
                    field0008 = 3;
                }
                ResetPose();
            }
        }
        return;

    case 153: // Original block 0x005EDB03: {'stand/crouch' if terminal == 0 else 'crouching'} recoil
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
        if (field000c >= frameDuration) {
            field000c = 0;
            ++field000a;
            if (field000a == animationFrameCount) {
                FaceOpponent();
            }
            if (field000a >= animationFrameCount) {
                field0008 = 3;
                ResetPose();
            }
        }
        return;

    case 154: // Original block 0x005EDC97: {'stand/crouch' if terminal == 0 else 'crouching'} recoil
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
        if (field000c >= frameDuration) {
            field000c = 0;
            ++field000a;
            if (field000a == animationFrameCount) {
                FaceOpponent();
            }
            if (field000a >= animationFrameCount) {
                field0008 = 3;
                ResetPose();
            }
        }
        return;

    case 155: // Original block 0x005EDE2B: {'stand/crouch' if terminal == 0 else 'crouching'} recoil
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
        if (field000c >= frameDuration) {
            field000c = 0;
            ++field000a;
            if (field000a == animationFrameCount) {
                FaceOpponent();
            }
            if (field000a >= animationFrameCount) {
                field0008 = 3;
                ResetPose();
            }
        }
        return;

    case 156: // Original block 0x005EDFBF: forward airborne knockback
        if (field000a == 0 && field000c == 0) {
            velocityY = -2.6;
            meter = (short)(meter + 15);
            gravity = 0.06;
        }
        velocityX = -1.2;
        velocityY += gravity;
        ++field000c;
        if (field000c >= frameDuration) {
            field000c = 0;
            ++field000a;
            if (field000a >= animationFrameCount) {
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

    case 157: // Original block 0x005EE0CF: aerial effect with two-frame loop
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
        if (field000c >= frameDuration) {
            field000c = 0;
            ++field000a;
            if (field000a >= animationFrameCount) {
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

    case 158: // Original block 0x005EE223: opposite-direction aerial effect
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
        if (field000c >= frameDuration) {
            field000c = 0;
            ++field000a;
            if (field000a >= animationFrameCount) {
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

    case 161: // Original block 0x005EE377: aerial impact and trail reset
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
        if (field000c >= frameDuration) {
            field000c = 0;
            ++field000a;
            if (field000a >= animationFrameCount) {
                field0008 = 9;
                ResetPose();
                gravity = 0.035;
            }
        }
        return;

    case 162: // Original block 0x005EE48B: staged aerial launch and impact
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
        if (field000c >= frameDuration) {
            field000c = 0;
            ++field000a;
            if (field000a == 18) {
                gravity = 0.035;
            }
            if (field000a >= animationFrameCount) {
                field000a = (unsigned short)(field000a - 2);
            }
        }
        return;

    case 163: // Original block 0x005EE676: cancellable forward dash
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
        if (field000c >= frameDuration) {
            field000c = 0;
            ++field000a;
            if (field000a >= animationFrameCount) {
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

    case 164: // Original block 0x005EE867: decelerating ground dash
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
        if (field000c >= frameDuration) {
            field000c = 0;
            ++field000a;
            if (field000a == 4 && field3138 < 2) {
                field000a = (unsigned short)(field000a - 2);
                ++field3138;
            }
            if (field000a >= animationFrameCount) {
                FaceOpponent();
                field0008 = 0;
                ResetPose();
                ResetFrame();
            }
        }
        return;

    case 165: // Original block 0x005EE9B2: sustained airborne momentum
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
        if (field000c >= frameDuration) {
            field000c = 0;
            ++field000a;
            if (field000a >= animationFrameCount) {
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

    case 166: // Original block 0x005EEBB9: sustained airborne momentum
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
        if (field000c >= frameDuration) {
            field000c = 0;
            ++field000a;
            if (field000a >= animationFrameCount) {
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

    case 167: // Original block 0x005EEDC4: stunned recovery with two effects
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
        if (field000c >= frameDuration) {
            field000c = 0;
            ++field000a;
            attackCollisionResult = 0;
            if (field000a >= animationFrameCount) {
                field0008 = 0;
                FaceOpponent();
                ResetPose();
            }
        }
        return;

    case 168: // Original block 0x005EEFAC: grounded impact to state 0
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
        if (field000c >= frameDuration) {
            field000c = 0;
            ++field000a;
            if (field000a == animationFrameCount) {
                FaceOpponent();
            }
            if (field000a >= animationFrameCount) {
                field0008 = 0;
                ResetPose();
            }
        }
        return;

    case 169: // Original block 0x005EF0F6: grounded impact to state 3
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
        if (field000c >= frameDuration) {
            field000c = 0;
            ++field000a;
            if (field000a == animationFrameCount) {
                FaceOpponent();
            }
            if (field000a >= animationFrameCount) {
                field0008 = 3;
                ResetPose();
            }
        }
        return;

    case 170: // Original block 0x005EF240: delayed stored-velocity release
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
        if (positionY + velocityY > 0.0) {
            ResetFrame();
            positionY = 0.0;
            field0008 = 169;
            return;
        }
        ++field000c;
        if (field000c >= frameDuration) {
            field000c = 0;
            ++field000a;
            if (field000a >= animationFrameCount) {
                field0008 = 9;
                ResetPose();
            }
        }
        return;

    case 171: // Original block 0x005EF409: frozen hit, one immediate effect
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
        if (field000c >= frameDuration) {
            field000c = 0;
            ++field000a;
            attackCollisionResult = 0;
            if (field000a >= animationFrameCount) {
                field0008 = 9;
                velocityX = (double)field3138 * 0.01;
                velocityY = (double)field313c * 0.01;
                gravity = 0.035;
                ResetPose();
            }
        }
        return;

    case 178: // Original block 0x005EF5E8: dash slide and jump cancel
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
        if (field000c >= frameDuration) {
            field000c = 0;
            ++field000a;
            if (field000a >= animationFrameCount) {
                field0008 = 7;
                ResetPose();
            }
        }
        return;

    case 180: // Original block 0x005EF70A: trailing aerial landing
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
        if (field000c >= frameDuration) {
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
            if (field000a >= animationFrameCount) {
                ResetPose();
                field0008 = 0;
            }
        }
        return;

    case 200: // Original block 0x005EF87C: dash-momentum attack
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
        if (field000c >= frameDuration) {
            field000c = 0;
            ++field000a;
            if (field000a < 2) {
                attackCollisionResult = 0;
            }
            if (field000a >= animationFrameCount) {
                field0008 = 0;
                FaceOpponent();
                ResetPose();
            }
        }
        return;

    case 201: // Original block 0x005EFA4F: dash-momentum attack
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
        if (field000c >= frameDuration) {
            field000c = 0;
            ++field000a;
            if (field000a < 2) {
                attackCollisionResult = 0;
            }
            if (field000a >= animationFrameCount) {
                field0008 = 0;
                FaceOpponent();
                ResetPose();
            }
        }
        return;

    case 202: // Original block 0x005EFC22: local hit effect on advanced pose
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
        if (field000c >= frameDuration) {
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
            if (field000a >= animationFrameCount) {
                field0008 = 0;
                FaceOpponent();
                ResetPose();
            }
        }
        return;

    default:
        // This draft deliberately does not provide a fake implementation for
        // the other 46 explicit cases. The target's true default path also
        // clears motion, but that path must not replace any mapped case.
        return;
    }

    // The first three reviewed cases share the same frame-advance tail:
    // target 0x005E873A..0x005E878E (and equivalent case 2/3 tails).
    ++field000c;
    if (field000c >= frameDuration) {
        field000c = 0;
        ++field000a;
        if (field000a >= animationFrameCount) field000a = 0;
    }
}
