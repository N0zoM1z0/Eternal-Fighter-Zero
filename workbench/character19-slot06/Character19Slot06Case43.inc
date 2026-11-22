if ((self->field000a == 0) && (self->field000c == 0)) {
    self->StartTrail(3);
    self->ResetFrame();
}

if ((self->field000a == 3) && (self->field000c == 0)) {
    self->velocityX = 2.0;
    self->velocityY = -1.0;
    self->gravity = 0.02;
    self->pendingCharacterSoundSlot = 0;
}

int continueAirborne = (self->positionY >= 0.0);
if (!continueAirborne) {
    self->velocityY = self->velocityY + self->gravity;
    continueAirborne = (self->positionY + self->velocityY <= 0.0);
}

if (continueAirborne) {
    if (self->field000a > 6) {
    self->velocityX = self->velocityX - 0.04;
    if (self->velocityX < 0.0) {
        self->velocityX = 0.0;
    }
}

    self->field000c = self->field000c + 1;
    if (timing.frameDuration <= self->field000c) {
        self->field000c = 0;
        self->field000a = self->field000a + 1;
        if (self->field000a == 7) {
    self->field000a = self->field000a - 2;
}
        if (timing.animationFrameCount <= self->field000a) {
            self->field0008 = 0;
self->ResetPose();
        }
    }
} else {
    self->positionY = 0.0;
    self->velocityY = 0.0;
self->field000c = 0;
self->field000a = 7;
}
