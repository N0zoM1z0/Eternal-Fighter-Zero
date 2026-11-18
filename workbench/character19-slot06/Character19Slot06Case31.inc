if ((field000a == 0) && (field000c == 0)) {
    if (field3144 == 0) {
        spawn.type = 0x1f0;
        spawn.x = (double)(int)positionX;
        spawn.y = (double)(int)positionY;
        spawn.group = 0;
        spawn.layer = 0;
        spawn.owner = 1;
        spawn.flag0018 = (unsigned char)facing;
        EmitLocalEffect(&spawn);
        field3144 = 1;
    }

    if (field0120 != 0) {
        field0118 = field0118 - 30.0;
    }
    pendingContextSoundSlot = 0x21;
    velocityY = -1.5;
    velocityX = -0.8;
    meter = meter + 30;
}

velocityY = velocityY + 0.04;
if ((field000a != 0) || ((positionY + velocityY) <= 0.0)) {
    if (field000a == 1) {
        velocityX = velocityX + 0.01;
    }
    if ((field000a == 2) && (field000c == 0)) {
        velocityX = -2.0;
    }
    if (field000a > 1) {
        velocityX = velocityX + 0.06;
    }
    if (velocityX > 0.0) {
        velocityX = 0.0;
    }

    field000c = field000c + 1;
    if (timing.frameDuration <= field000c) {
        field000c = 0;
        field000a = field000a + 1;
        if (timing.animationFrameCount <= field000a) {
            field0008 = 0;
            ResetPose();
            FaceOpponent();
        }
    }
} else {
    positionY = 0.0;
    velocityY = 0.0;
    field000c = 0;
    field000a = 1;
}
