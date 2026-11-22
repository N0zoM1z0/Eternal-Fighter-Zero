if ((self->field000a == 0) && (self->field000c == 0)) {
    if (self->field3144 == 0) {
        spawn.type = 0x1f0;
        spawn.x = (double)(int)self->positionX;
        spawn.y = (double)(int)self->positionY;
        spawn.group = 0;
        spawn.layer = 0;
        spawn.owner = 1;
        spawn.flag0018 = (unsigned char)self->facing;
        self->EmitLocalEffect(&spawn);
        self->field3144 = 1;
    }

    if (self->field0120 != 0) {
    self->field0118 = self->field0118 - 30.0;
}
self->pendingContextSoundSlot = 0x21;
self->velocityX = self->knockbackVelocityX;
self->velocityY = self->knockbackVelocityY;
self->meter = self->meter + 30;

}

self->velocityY = self->velocityY + 0.04;
self->field000c = self->field000c + 1;
if (timing.frameDuration <= self->field000c) {
    self->field000c = 0;
    self->field000a = self->field000a + 1;
    if (timing.animationFrameCount <= self->field000a) {
        self->field0008 = 0;
self->ResetPose();
self->FaceOpponent();
    }
}

if ((self->positionY + self->velocityY) >= 0.0) {
    self->positionY = 0.0;
    if (self->knockdownOnLanding != 0) {
        self->field0008 = 0x61;
    } else {
        self->field0008 = 0x62;
    }
    self->ResetPose();
}
