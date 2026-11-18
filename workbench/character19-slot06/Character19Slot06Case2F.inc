if (field0120 != 0) {
    field0118 = field0118 - 0.8;
}

if ((field000a == 0) && (field000c == 0)) {
    spawn.type = 499;
    spawn.x = (double)(int)positionX;
    spawn.y = (double)(int)positionY;
    spawn.flag0018 = (unsigned char)facing;
    spawn.layer = 1;
    EmitLocalEffect(&spawn);

    meter = meter + 30;
    velocityX = knockbackVelocityX;
    velocityY = knockbackVelocityY;
    gravity = 0.032;
}

velocityX = velocityX + 0.02;
velocityY = velocityY + gravity;
if (velocityX > 0.0) {
    velocityX = 0.0;
}

field000c = field000c + 1;
if (timing.frameDuration <= field000c) {
    field000c = 0;
    field000a = field000a + 1;
    if (timing.animationFrameCount <= field000a) {
        field000a = field000a - 1;
    }
}

if (((positionY + velocityY) >= 0.0) && (field000a == 1)) {
    positionY = 0.0;
    if (knockdownOnLanding != 0) {
        field0008 = 0x61;
    } else {
        field0008 = 0x62;
    }
    ResetPose();
}
