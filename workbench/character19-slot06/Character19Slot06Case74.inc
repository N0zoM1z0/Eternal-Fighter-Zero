if ((field000a == 0) && (field000c == 0)) {
    velocityX = 0.0;
    velocityY = 0.0;
    gravity = 0.0;
}

field000c = field000c + 1;
if (timing.frameDuration <= field000c) {
    field000c = 0;
    field000a = field000a + 1;
    attackCollisionResult = 0;
    if (timing.animationFrameCount <= field000a) {
        field0008 = 0;
        FaceOpponent();
        ResetPose();
    }
}
