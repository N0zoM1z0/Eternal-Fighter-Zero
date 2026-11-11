// Character04::Slot06 original native state boss, authored real opening cases.
// This is an incomplete workbench. Unreviewed live states are NOT source.
#include "../../src/CharacterViews.h"

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


    }
}
