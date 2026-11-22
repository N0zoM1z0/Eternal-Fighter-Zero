self->velocityY = self->velocityY + self->gravity;
self->dashMomentumFlag = 0;
if (self->field3148 == 0) {
    self->velocityX = self->velocityX * 0.3;
    self->field3148 = self->field3148 + 1;
}
if (self->velocityY > 0.4) {
    self->velocityY = 0.4;
}

if ((self->inputY == -1) && (self->field015c < 3) && (self->airActionCount < 2)) {
    self->airActionCount = self->airActionCount + 1;
    self->field0008 = 0x0e;
    if (self->inputX == self->facing) {
        self->field0008 = 0x0f;
    }
    if (self->inputX == -self->facing) {
        self->field0008 = 0x10;
    }
    self->attackCollisionResult = 0;
    self->ResetPose();
} else {
    if (self->inputY == 1) {
        self->field0008 = 9;
        self->ResetPose();
        if ((self->airActionCount < 2) && (self->inputX != 0) &&
            (self->field015c < 3)) {
            self->airActionCount = self->airActionCount + 1;
            if (self->inputX == self->facing) {
                self->field0008 = 0x12;
            }
            if (self->inputX == -self->facing) {
                self->field0008 = 0x14;
            }
            self->attackCollisionResult = 0;
            self->ResetPose();
            return;
        }
    }

    if ((self->airActionCount < 2) && (self->field015c < 3)) {
        if (self->inputX == self->facing) {
            self->field0008 = 0x11;
            self->airActionCount = self->airActionCount + 1;
            self->ResetPose();
            self->attackCollisionResult = 0;
            return;
        }
        if (self->inputX == -self->facing) {
            self->field0008 = 0x13;
            self->airActionCount = self->airActionCount + 1;
            self->ResetPose();
            self->attackCollisionResult = 0;
            return;
        }
    }

    self->field000c = self->field000c + 1;
    if (timing.frameDuration <= self->field000c) {
        self->field000c = 0;
        self->field000a = self->field000a + 1;
        if (timing.animationFrameCount <= self->field000a) {
            self->field000a = 0;
        }
    }

    if (self->positionY + self->velocityY >= 0.0) {
        self->positionY = 0.0;
        self->pendingContextSoundSlot = 9;
        self->field0008 = 0x0d;
        self->ResetPose();
    }
}
