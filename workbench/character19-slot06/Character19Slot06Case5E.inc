StartTrail(3);
dashMomentumFlag = 0;

velocityX = velocityX - 0.03;
if (velocityX < 0.0) {
    velocityX = 0.0;
}

if ((field000a == 0) && (field000c == 0)) {
    velocityX = 2.0;
    velocityY = 0.0;
}

if ((field000a == 2) && (field000c == 0)) {
    meter = meter + 5;
    pendingContextSoundSlot = (char)0x15;
    remainingHitCount = 1;
}

field000c = field000c + 1;
if (timing.frameDuration <= field000c) {
    field000c = 0;
    field000a = field000a + 1;
    if (field000a < 3) {
        attackCollisionResult = 0;
    }
    if (timing.animationFrameCount <= field000a) {
        field0008 = 0;
        ResetPose();
    }
}
