// First natural-C++ cases of the still-open Makoto state dispatcher.
//
// This is a compileable reconstruction WORKBENCH, not linked into the accepted
// game sources. Animations outside cases 1-5 have not yet been reconstructed.
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

    default:
        // This draft deliberately does not provide a fake implementation for
        // the other 121 explicit cases. The target's true default path also
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
