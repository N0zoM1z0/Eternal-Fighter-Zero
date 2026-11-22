if (self->field0120 != 0) {
    self->field0118 = self->field0118 - 0.8;
}

if ((self->field000a == 0) && (self->field000c == 0) && (self->field3138 == 0)) {
    self->pendingContextSoundSlot = 0x1e;
    self->velocityY = -0.45;
    self->velocityX = -0.1;
    self->field3138 = self->field3138 + 1;
    self->meter = self->meter + 30;
}

if ((self->field000a == 4) && (self->field000c == 0)) {
    self->velocityX = self->knockbackVelocityX;
    self->velocityY = self->knockbackVelocityY;
    self->gravity = 0.032;
}

if ((self->velocityY > 0.0) && (self->field000a == 4)) {
    self->field000a = 5;
    self->field000c = 0;
}

if (self->field000a > 3) {
    self->velocityY = self->velocityY + self->gravity;
}

self->field000c = self->field000c + 1;
if (timing.frameDuration <= self->field000c) {
    self->field000c = 0;
    self->field000a = self->field000a + 1;
    if ((self->field000a == 4) && (self->field3138 < 8)) {
        self->field000a = 0;
        self->field3138 = self->field3138 + 1;
    }
    if (timing.animationFrameCount <= self->field000a) {
        self->field000a = self->field000a - 2;
    }
}

if (((self->positionY + self->velocityY) >= 0.0) && (self->field000a > 4)) {
    self->positionY = 0.0;
    if (self->knockdownOnLanding != 0) {
        self->field0008 = 0x61;
    } else {
        self->field0008 = 0x62;
    }
    self->ResetPose();
}
