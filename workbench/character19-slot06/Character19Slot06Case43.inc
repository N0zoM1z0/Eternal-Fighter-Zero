if ((field000a == 0) && (field000c == 0)) {
    StartTrail(3);
    ResetFrame();
}

if ((field000a == 3) && (field000c == 0)) {
    velocityX = 2.0;
    velocityY = -1.0;
    gravity = 0.02;
    pendingCharacterSoundSlot = 0;
}

int continueAirborne = (positionY >= 0.0);
if (!continueAirborne) {
    velocityY = velocityY + gravity;
    continueAirborne = (positionY + velocityY <= 0.0);
}

if (continueAirborne) {
    if (field000a > 6) {
    velocityX = velocityX - 0.04;
    if (velocityX < 0.0) {
        velocityX = 0.0;
    }
}

    field000c = field000c + 1;
    if (timing.frameDuration <= field000c) {
        field000c = 0;
        field000a = field000a + 1;
        if (field000a == 7) {
    field000a = field000a - 2;
}
        if (timing.animationFrameCount <= field000a) {
            field0008 = 0;
ResetPose();
        }
    }
} else {
    positionY = 0.0;
    velocityY = 0.0;
field000c = 0;
field000a = 7;
}
