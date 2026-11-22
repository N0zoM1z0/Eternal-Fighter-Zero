if ((self->inputY == -1) && (self->field000a > 0) && (self->field015c < 3) && (self->attackCollisionResult >= 2)) {
self->field0008 = 4;
        if (self->inputX == self->facing) {
            self->field0008 = 5;
        }
        if (self->inputX == -self->facing) {
            self->field0008 = 6;
        }
        self->attackCollisionResult = 0;
        self->ResetPose();
} else {
if ((self->field000a == 0) && (self->field000c == 0)) {
        self->velocityX = 0.0;
        self->velocityY = 0.0;
    }

    if ((self->field000a == 3) && (self->field000c == 0)) {
        self->meter = self->meter + 30;
        self->pendingContextSoundSlot = 0x14;
        self->remainingHitCount = 1;
    }

    ++self->field000c;
    if (self->field000c >= timing.frameDuration) {
        self->field000c = 0;
        ++self->field000a;
        self->attackCollisionResult = 0;
        if (self->field000a >= timing.animationFrameCount) {
            self->field0008 = 0;
            self->FaceOpponent();
            self->ResetPose();
        }
    }
}
