if ((self->dashMomentumFlag == 0) && (self->field000a == 0) && (self->field000c == 0)) {
    self->velocityX = 0.0;
    self->velocityY = 0.0;
}

if ((self->velocityX <= 0.0) || (self->dashMomentumFlag != 1) || (self->field000a > 2)) {
    self->dashMomentumFlag = 0;
} else {
    self->velocityX = self->velocityX - 0.03;
}

if (self->velocityX < 0.0) {
    self->velocityX = 0.0;
}

if ((self->field000a == 1) && (self->field000c == 0)) {
    self->remainingHitCount = 1;
}

if ((self->field000a == 3) && (self->field000c == 0) && (self->field3138 == 0)) {
    self->meter = self->meter + 25;
    self->pendingContextSoundSlot = 0x14;
    self->field3138 = self->field3138 + 1;
}

self->field000c = self->field000c + 1;
if (timing.frameDuration <= self->field000c) {
    self->field000c = 0;
    self->field000a = self->field000a + 1;
    self->attackCollisionResult = 0;
    if (timing.animationFrameCount <= self->field000a) {
        self->field0008 = 0;
        if (self->inputY == 1) {
            self->field0008 = 3;
        }
        self->FaceOpponent();
        self->ResetPose();
    }
}
