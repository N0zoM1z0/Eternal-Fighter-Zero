velocityY = velocityY + gravity;

if ((inputY == -1) && (field000a > 0) && (field015c < 3) &&
    (attackCollisionResult > 1) && (airActionCount < 2)) {
    airActionCount = airActionCount + 1;
    field0008 = 14;
    if (inputX == facing) {
        field0008 = 15;
    }
    if (inputX == -facing) {
        field0008 = 16;
    }
    attackCollisionResult = 0;
    ResetPose();
    return;
}

if ((inputY == 0) && (inputX != 0) && (field000a > 0) &&
    (attackCollisionResult > 1) && (airActionCount < 2) &&
    (field015c < 3)) {
    airActionCount = airActionCount + 1;
    if (inputX == facing) {
        field0008 = 0xa5;
    }
    if (inputX == -facing) {
        field0008 = 0xa6;
    }
    attackCollisionResult = 0;
    ResetPose();
    return;
}

if ((field000a == 2) && (field000c == 0)) {
    meter = meter + 13;
    pendingContextSoundSlot = (char)0x14;
    remainingHitCount = 1;
}



if ((field000a == 3) && (field000c == 0)) {
    spawn.owner = 1;
    spawn.type = 0x1a7;
    spawn.x = (double)(int)positionX;
    spawn.y = (double)(int)positionY;
    spawn.flag0018 = (unsigned char)facing;
    spawn.group = 2;
    spawn.layer = 1;
    EmitLocalEffect(&spawn);
}

if ((positionY + velocityY) >= 0.0) {
    positionY = 0.0;
    field0008 = 13;
    ResetPose();
    return;
}

field000c = field000c + 1;
if (timing.frameDuration <= field000c) {
    field000c = 0;
    field000a = field000a + 1;
    if (field000a < 4) {
        attackCollisionResult = 0;
    }
    if (timing.animationFrameCount <= field000a) {
        field0008 = 9;
        ResetPose();
    }
}
