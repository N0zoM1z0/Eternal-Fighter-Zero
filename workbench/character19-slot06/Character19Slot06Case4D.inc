if (self->dashMomentumFlag == 0) {
    self->velocityX = 0.0;
    self->velocityY = 0.0;
}

if ((self->velocityX > 0.0) && (self->dashMomentumFlag == 1)) {
    self->velocityX = self->velocityX - 0.06;
} else {
    self->velocityX = 0.0;
    self->dashMomentumFlag = 0;
}



int cancel = 0;
if ((self->inputY == -1) && (self->field000a > 0) && (self->field015c < 3) &&
    (self->attackCollisionResult > 1)) {
    cancel = 1;
}

if (cancel) {
    self->field0008 = 4;
    if (self->inputX == self->facing) {
        self->field0008 = 5;
    }
    if (self->inputX == -self->facing) {
        self->field0008 = 6;
    }
    self->attackCollisionResult = 0;
    self->ResetPose();
    return;
}

if ((self->field000a == 2) && (self->field000c == 0)) {
    self->meter = self->meter + 5;
    self->pendingContextSoundSlot = (char)21;
    self->remainingHitCount = 1;
}



self->field000c = self->field000c + 1;
if (timing.frameDuration <= self->field000c) {
    self->field000c = 0;
    self->field000a = self->field000a + 1;
    if (self->field000a < 3) {
        self->attackCollisionResult = 0;
    }
    if (timing.animationFrameCount <= self->field000a) {
        self->field0008 = 0;

        self->FaceOpponent();
        self->ResetPose();
    }
}
