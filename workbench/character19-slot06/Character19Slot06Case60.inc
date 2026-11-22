self->StartTrail(3);
self->dashMomentumFlag = 0;

if (self->field000a < 3) {
    if ((unsigned char)self->dashMomentumFlag == 0) {
        self->velocityX = 0.0;
    }

    if ((self->velocityX > 0.0) &&
        ((unsigned char)self->dashMomentumFlag == 1)) {
        self->velocityX = self->velocityX - 0.06;
    } else {
        self->velocityX = 0.0;
        self->dashMomentumFlag = 0;
    }
}

if ((self->field000a == 3) && (self->field000c == 0)) {
    self->pendingContextSoundSlot = 0x14;
    self->velocityX = 3.0;
    self->remainingHitCount = 1;
    self->meter = self->meter + 35;
}

self->velocityX = self->velocityX -
    (double)(self->velocityX > 0.0) * 0.07;
if (self->velocityX < 0.0) {
    self->velocityX = 0.0;
}

++self->field000c;
if (self->field000c >= timing.frameDuration) {
    self->field000c = 0;
    ++self->field000a;
    if (self->field000a < 3) {
        self->attackCollisionResult = 0;
    }
    if (self->field000a >= timing.animationFrameCount) {
        self->field0008 = 0;
        self->ResetPose();
    }
}
