if ((field000a == 0) && (field000c == 0)) {
    velocityX = 0.0;
    velocityY = 0.0;
}

field3140 = field3140 + 1;
if (field3148 < field3140) {
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
        return;
    }

    if (inputY == 1) {
        field0008 = 9;
        ResetPose();
        if (airActionCount > 1) {
            return;
        }
        if (inputX == 0) {
            return;
        }
        if (field015c > 2) {
            return;
        }

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

}

if ((field000a == 3) && (field000c == 0)) {
    gravity = 0.045;
    velocityY = -3.5;
    velocityX = 0.0;
    reinterpret_cast<unsigned char *>(&soundSlots[49])[0] = 0;
}

if (field000a > 2) {
    velocityY = velocityY + gravity;
}

field000c = field000c + 1;
if (timing.frameDuration <= field000c) {
    field000c = 0;
    field000a = field000a + 1;
    if (timing.animationFrameCount <= field000a) {
        field0008 = 10;
        ResetPose();
    }
}

if ((positionY + velocityY >= 0.0) && (field000a > 3)) {
    positionY = 0.0;
    reinterpret_cast<unsigned char *>(&soundSlots[49])[1] = 9;
    FaceOpponent();
    field0008 = 0x0d;
    ResetPose();
}
