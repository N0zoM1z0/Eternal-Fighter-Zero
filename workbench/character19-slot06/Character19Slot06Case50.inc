if (dashMomentumFlag == 0) {
    velocityX = 0.0;
    velocityY = 0.0;
}

if ((velocityX > 0.0) && (dashMomentumFlag == 1)) {
    velocityX = velocityX - 0.06;
} else {
    velocityX = 0.0;
    dashMomentumFlag = 0;
}



int cancel = 0;
if ((inputY == -1) && (field000a > 0) && (field015c < 3) &&
    (attackCollisionResult == 3)) {
    cancel = 1;
}

if (cancel) {
    field0008 = 4;
    if (inputX == facing) {
        field0008 = 5;
    }
    if (inputX == -facing) {
        field0008 = 6;
    }
    attackCollisionResult = 0;
    ResetPose();
    return;
}

if ((field000a == 4) && (field000c == 0)) {
    meter = meter + 35;
    pendingContextSoundSlot = (char)35;
    remainingHitCount = 1;
}



if ((field000a == 6) && (field000c == 0)) {
    if ((field000a == 6) && (field000c == 0)) {
    spawn.owner = 1;
        spawn.type = 0x1a8;
        spawn.x = (double)(int)positionX;
        spawn.y = (double)(int)positionY;
        spawn.flag0018 = (unsigned char)facing;
        spawn.group = 2;
        spawn.layer = 1;
        EmitLocalEffect(&spawn);
}
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

        FaceOpponent();
        ResetPose();
    }
}
