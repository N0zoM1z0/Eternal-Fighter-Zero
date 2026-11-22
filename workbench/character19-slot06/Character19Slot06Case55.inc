self->velocityY = self->velocityY + self->gravity;

if ((self->inputY == -1) && (self->field000a > 0) && (self->field015c < 3) &&
    (self->attackCollisionResult > 1) && (self->airActionCount < 2)) {
    self->airActionCount = self->airActionCount + 1;
    self->field0008 = 14;
    if (self->inputX == self->facing) {
        self->field0008 = 15;
    }
    if (self->inputX == -self->facing) {
        self->field0008 = 16;
    }
    self->attackCollisionResult = 0;
    self->ResetPose();
    return;
}

if ((self->inputY == 0) && (self->inputX != 0) && (self->field000a > 0) &&
    (self->attackCollisionResult > 1) && (self->airActionCount < 2) &&
    (self->field015c < 3)) {
    self->airActionCount = self->airActionCount + 1;
    if (self->inputX == self->facing) {
        self->field0008 = 0xa5;
    }
    if (self->inputX == -self->facing) {
        self->field0008 = 0xa6;
    }
    self->attackCollisionResult = 0;
    self->ResetPose();
    return;
}

if ((self->field000a == 2) && (self->field000c == 0)) {
    self->meter = self->meter + 13;
    self->pendingContextSoundSlot = (char)0x14;
    self->remainingHitCount = 1;
}



if ((self->field000a == 3) && (self->field000c == 0)) {
    spawn.owner = 1;
    spawn.type = 0x1a7;
    spawn.x = (double)(int)self->positionX;
    spawn.y = (double)(int)self->positionY;
    spawn.flag0018 = (unsigned char)self->facing;
    spawn.group = 2;
    spawn.layer = 1;
    self->EmitLocalEffect(&spawn);
}

if ((self->positionY + self->velocityY) >= 0.0) {
    self->positionY = 0.0;
    self->field0008 = 13;
    self->ResetPose();
    return;
}

self->field000c = self->field000c + 1;
if (timing.frameDuration <= self->field000c) {
    self->field000c = 0;
    self->field000a = self->field000a + 1;
    if (self->field000a < 4) {
        self->attackCollisionResult = 0;
    }
    if (timing.animationFrameCount <= self->field000a) {
        self->field0008 = 9;
        self->ResetPose();
    }
}
