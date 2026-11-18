if (field0120 != 0) {
    field0118 = field0118 - 0.8;
}

if ((field000a == 0) && (field000c == 0) && (field3138 == 0)) {
    pendingContextSoundSlot = 0x1e;
    velocityY = -0.45;
    velocityX = -0.1;
    field3138 = field3138 + 1;
    meter = meter + 30;
}

if ((field000a == 4) && (field000c == 0)) {
    velocityX = knockbackVelocityX;
    velocityY = knockbackVelocityY;
    gravity = 0.032;
}

if ((velocityY > 0.0) && (field000a == 4)) {
    field000a = 5;
    field000c = 0;
}

if (field000a > 3) {
    velocityY = velocityY + gravity;
}

field000c = field000c + 1;
if (timing.frameDuration <= field000c) {
    field000c = 0;
    field000a = field000a + 1;
    if ((field000a == 4) && (field3138 < 8)) {
        field000a = 0;
        field3138 = field3138 + 1;
    }
    if (timing.animationFrameCount <= field000a) {
        field000a = field000a - 2;
    }
}

if (((positionY + velocityY) >= 0.0) && (field000a > 4)) {
    positionY = 0.0;
    if (knockdownOnLanding != 0) {
        field0008 = 0x61;
    } else {
        field0008 = 0x62;
    }
    ResetPose();
}
