// First natural-C++ cases of the still-open Makoto state dispatcher.
//
// This is a compileable reconstruction WORKBENCH, not linked into the accepted
// game sources. Cases 1-9, 13-16, 47 and 50-72 are implemented so far.
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

    default:
        // This draft deliberately does not provide a fake implementation for
        // the other 98 explicit cases. The target's true default path also
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
