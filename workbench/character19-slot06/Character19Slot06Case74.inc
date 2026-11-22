if ((self->field000a == 0) && (self->field000c == 0)) {
    self->velocityX = 0.0;
    self->velocityY = 0.0;
    self->gravity = 0.0;
}

self->field000c = self->field000c + 1;
if (timing.frameDuration <= self->field000c) {
    self->field000c = 0;
    self->field000a = self->field000a + 1;
    self->attackCollisionResult = 0;
    if (timing.animationFrameCount <= self->field000a) {
        self->field0008 = 0;
        self->FaceOpponent();
        self->ResetPose();
    }
}
