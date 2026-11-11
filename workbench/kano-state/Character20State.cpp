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

    }
}
