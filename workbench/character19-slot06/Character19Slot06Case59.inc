self->velocityY = self->velocityY + self->gravity;

if ((self->field000a == 0) && (self->field000c == 0)) {
    self->meter = self->meter + 30;
    self->pendingContextSoundSlot = 0x14;
    self->remainingHitCount = 1;
    self->velocityX = self->velocityX / 2.0;
    self->gravity = 0.07;
}

if (self->attackCollisionResult > 1) {
    self->field0008 = 0xd5;
    self->ResetPose();
    self->ResetFrame();
    return;
}

if ((self->positionY + self->velocityY) >= 0.0) {
    self->positionY = 0.0;
    self->ResetFrame();
    self->velocityY = 0.0;
    self->SetVerticalShake(3, 0);

    spawn.type = 3;
    spawn.x = (double)(int)self->positionX;
    spawn.y = (double)(int)self->positionY;
    spawn.group = 2;
    spawn.layer = 0;
    spawn.palette = 7;
    self->contextOwner->EmitEffect(&spawn);

    self->pendingContextSoundSlot = 7;
    self->field0008 = 0xd6;
    self->ResetPose();
    return;
}

self->field000c = self->field000c + 1;
if (timing.frameDuration <= self->field000c) {
    self->field000c = 0;
    self->field000a = self->field000a + 1;
    self->attackCollisionResult = 0;
    if (timing.animationFrameCount <= self->field000a) {
        self->field000a = self->field000a - 2;
    }
}
