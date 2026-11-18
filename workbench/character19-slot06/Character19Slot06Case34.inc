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

    if (field3138 == 0) {
    if (field0120 != 0) {
        field0118 = field0118 - 30.0;
    }
    pendingContextSoundSlot = 0x21;
    velocityX = knockbackVelocityX;
    velocityY = knockbackVelocityY;
    meter = meter + 30;
    field3138 = field3138 + 1;
}
}

velocityY = velocityY + 0.06;
field000c = field000c + 1;
if (timing.frameDuration <= field000c) {
    field000c = 0;
    field000a = field000a + 1;
    if (timing.animationFrameCount <= field000a) {
        field000a = 0;
    }
}

if ((positionY + velocityY) >= 0.0) {
    positionY = 0.0;
    if (knockdownOnLanding != 0) {
        field0008 = 0x61;
    } else {
        field0008 = 0x62;
    }
    ResetPose();
}
