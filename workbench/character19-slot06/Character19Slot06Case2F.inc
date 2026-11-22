if (self->field0120 != 0) {
    self->field0118 = self->field0118 - 0.8;
}

if ((self->field000a == 0) && (self->field000c == 0)) {
    spawn.type = 499;
    spawn.x = (double)(int)self->positionX;
    spawn.y = (double)(int)self->positionY;
    spawn.flag0018 = (unsigned char)self->facing;
    spawn.layer = 1;
    self->EmitLocalEffect(&spawn);

    self->meter = self->meter + 30;
    self->velocityX = self->knockbackVelocityX;
    self->velocityY = self->knockbackVelocityY;
    self->gravity = 0.032;
}

self->velocityX = self->velocityX + 0.02;
self->velocityY = self->velocityY + self->gravity;
if (self->velocityX > 0.0) {
    self->velocityX = 0.0;
}

self->field000c = self->field000c + 1;
if (timing.frameDuration <= self->field000c) {
    self->field000c = 0;
    self->field000a = self->field000a + 1;
    if (timing.animationFrameCount <= self->field000a) {
        self->field000a = self->field000a - 1;
    }
}

if (((self->positionY + self->velocityY) >= 0.0) && (self->field000a == 1)) {
    self->positionY = 0.0;
    if (self->knockdownOnLanding != 0) {
        self->field0008 = 0x61;
    } else {
        self->field0008 = 0x62;
    }
    self->ResetPose();
}
