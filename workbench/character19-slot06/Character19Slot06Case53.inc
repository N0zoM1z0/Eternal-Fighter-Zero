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
if (timing.frameDuration <= field000c) {
    field000c = 0;
    field000a = field000a + 1;
    attackCollisionResult = 0;
    if (timing.animationFrameCount <= field000a) {
        field0008 = 0;
        if (inputY == 1) {
            field0008 = 3;
        }
        FaceOpponent();
        ResetPose();
    }
}
