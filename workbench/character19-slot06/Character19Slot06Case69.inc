if ((field000a == 0) && (field000c == 0)) {
    StartTrail(1);
    if (field313c == 0) {
        ResetFrame();
        if (field0120 == 0) {
            field0118 = field0118 - 500.0;
        } else {
            field0118 = field0118 - 250.0;
        }

        spawn.type = 0x21;
        spawn.x = (double)(int)positionX;
        spawn.y = (double)((int)positionY - 0x32);
        spawn.group = 2;
        spawn.layer = 1;
        spawn.palette = 0xb;
        contextOwner->EmitEffect(&spawn);
        field313c = field313c + 1;
    }
    remainingHitCount = 1;
}

if ((field000a == 1) && (field000c == 0)) {
    spawn.owner = 1;
    spawn.type = 0x1b9;
    spawn.x = positionX;
    spawn.y = positionY;
    spawn.flag0018 = (unsigned char)facing;
    spawn.group = 2;
    spawn.layer = 1;
    EmitLocalEffect(&spawn);
}

if (positionY < 0.0) {
    velocityY = velocityY + gravity;
}

if ((positionY >= 0.0) || ((positionY + velocityY) < 0.0)) {
    field000c = field000c + 1;
    if (timing.frameDuration <= field000c) {
        field000c = 0;
        field000a = field000a + 1;
        attackCollisionResult = 0;

        if ((field000a == 3) && (field313c == 1)) {
            velocityY = -3.5;
            gravity = 0.015;
            field313c = field313c + 1;
        }

        if ((field000a == 8) && (field3138 < 5)) {
            field000a = 0;
            field3138 = field3138 + 1;
        }

        if (field000a == 9) {
            remainingHitCount = 1;
        }

        if (timing.animationFrameCount <= field000a) {
            ResetPose();
            field0008 = 9;
        }
    }
} else {
    positionY = 0.0;
    ResetPose();
    ResetFrame();
    field0008 = 0x103;
}
