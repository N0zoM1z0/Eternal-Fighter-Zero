velocityY = velocityY + gravity;
dashMomentumFlag = 0;
if (field3148 == 0) {
    velocityX = velocityX * 0.3;
    field3148 = field3148 + 1;
}
if (velocityY > 0.4) {
    velocityY = 0.4;
}

if ((inputY == -1) && (field015c < 3) && (airActionCount < 2)) {
    airActionCount = airActionCount + 1;
    field0008 = 0x0e;
    if (inputX == facing) {
        field0008 = 0x0f;
    }
    if (inputX == -facing) {
        field0008 = 0x10;
    }
    attackCollisionResult = 0;
    ResetPose();
} else {
    if (inputY == 1) {
        field0008 = 9;
        ResetPose();
        if ((airActionCount < 2) && (inputX != 0) &&
            (field015c < 3)) {
            airActionCount = airActionCount + 1;
            if (inputX == facing) {
                field0008 = 0x12;
            }
            if (inputX == -facing) {
                field0008 = 0x14;
            }
            attackCollisionResult = 0;
            ResetPose();
            return;
        }
    }

    if ((airActionCount < 2) && (field015c < 3)) {
        if (inputX == facing) {
            field0008 = 0x11;
            airActionCount = airActionCount + 1;
            ResetPose();
            attackCollisionResult = 0;
            return;
        }
        if (inputX == -facing) {
            field0008 = 0x13;
            airActionCount = airActionCount + 1;
            ResetPose();
            attackCollisionResult = 0;
            return;
        }
    }

    field000c = field000c + 1;
    if (timing.frameDuration <= field000c) {
        field000c = 0;
        field000a = field000a + 1;
        if (timing.animationFrameCount <= field000a) {
            field000a = 0;
        }
    }

    if (positionY + velocityY >= 0.0) {
        positionY = 0.0;
        pendingContextSoundSlot = 9;
        field0008 = 0x0d;
        ResetPose();
    }
}
