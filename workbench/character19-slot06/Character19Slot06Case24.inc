if (self->field0120 != 0) {
    self->field0118 = self->field0118 - 0.8;
}

if ((self->field000a != 0) &&
    self->Slot06OpponentWithinKnockbackRange()) {
    self->field0008 = 0x46;
    self->ResetPose();
    return;
}

if ((self->field000a == 0) && (self->field000c == 0)) {
    self->meter = self->meter + 30;
    self->velocityX = self->knockbackVelocityX;
    self->velocityY = self->knockbackVelocityY;
    
    self->gravity = 0.032;
}

if (((self->velocityY < 0.0) != (self->velocityY == 0.0)) &&
    (self->field000a < 2)) {
    self->field000a = 1;
    self->field000c = 0;
}

if ((0.0 <= self->velocityY) && (self->field000a < 2)) {
    self->field000a = 2;
    self->field000c = 0;
}

self->velocityY = self->velocityY + self->gravity;
self->field000c = self->field000c + 1;
if (timing.frameDuration <= self->field000c) {
    self->field000c = 0;
    self->field000a = self->field000a + 1;
    if (timing.animationFrameCount <= self->field000a) {
        self->field000a = self->field000a - 2;
    }
}

if (((self->positionY + self->velocityY) >= 0.0) && (self->field000a > 1)) {
    self->positionY = 0.0;
    if (self->knockdownOnLanding == 0) {
        self->field0008 = 0x62;
    } else {
        self->field0008 = 0x61;
    }
    self->ResetPose();
}
