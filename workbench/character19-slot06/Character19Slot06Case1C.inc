if (field0120 != 0) {
    field0118 = field0118 - 0.8;
}



if ((field000a == 0) && (field000c == 0)) {
    meter = meter + 30;
    velocityX = knockbackVelocityX;
    velocityY = velocityY * 0.75 + knockbackVelocityY;
    if (-2.0 <= velocityY) {
    if (-0.5 < velocityY) {
        velocityY = -0.5;
    }
} else {
    velocityY = -2.0;
}
    gravity = 0.032;
}

if (((velocityY < 0.0) != (velocityY == 0.0)) &&
    (field000a < 2)) {
    field000a = 1;
    field000c = 0;
}

if ((0.0 <= velocityY) && (field000a < 2)) {
    field000a = 2;
    field000c = 0;
}

velocityY = velocityY + gravity;
field000c = field000c + 1;
if (timing.frameDuration <= field000c) {
    field000c = 0;
    field000a = field000a + 1;
    if (timing.animationFrameCount <= field000a) {
        field000a = field000a - 2;
    }
}

if (((positionY + velocityY) >= 0.0) && (field000a > 1)) {
    positionY = 0.0;
    if (knockdownOnLanding == 0) {
        field0008 = 0x62;
    } else {
        field0008 = 0x61;
    }
    ResetPose();
}
