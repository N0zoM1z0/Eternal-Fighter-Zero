if ((self->field000a == 0) && (self->field000c == 0)) {
    self->FaceOpponent();
    self->velocityX = 0.0;
}

self->field3140 = self->field3140 + 1;
if (self->field3148 < self->field3140) {
    if ((self->inputY == -1) && (self->airActionCount < 2)) {
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
        return;
    }

    if (self->inputY == 1) {
        self->field0008 = 9;
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
        self->ResetPose();
        return;
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
}

if ((self->field000a == 3) && (self->field000c == 0)) {
    self->gravity = 0.045;
    self->velocityY = -2.5;
    self->pendingCharacterSoundSlot = 0;
}

if (self->field000a > 4) {
    self->velocityY = self->velocityY + self->gravity;
}

self->field000c = self->field000c + 1;
if (timing.frameDuration <= self->field000c) {
    self->field000c = 0;
    self->field000a = self->field000a + 1;
    if (timing.animationFrameCount <= self->field000a) {
        self->field0008 = 0x0a;
        self->ResetPose();
    }
}

if ((self->positionY + self->velocityY >= 0.0) && (self->field000a > 3)) {
    self->positionY = 0.0;
    self->pendingContextSoundSlot = 9;
    self->FaceOpponent();
    self->field0008 = 0x0d;
    self->ResetPose();
}
