if ((self->field000a == 0) && (self->field000c == 0)) {
    self->field3138 = (int)(self->velocityX * 100.0);
    self->field313c = (int)(self->velocityY * 100.0);
    self->velocityX = 0.0;
    self->velocityY = 0.0;
    if (self->field0120 == 1) {
        self->comboDamageScale = self->comboDamageScale + (self->field0118 * 5.0);
    }
    self->field0118 = 0.0;
    self->hitstunFrames = 90;
    self->SetTint(0xb0, 3);
}

if ((self->field000a == 1) && (self->field000c == 0)) {
    self->pendingContextSoundSlot = 0x12;
    spawn.type = 1;
    spawn.x = (double)(int)self->positionX;
    spawn.y = (double)(int)self->positionY;
    spawn.group = 2;
    spawn.layer = 1;
    self->contextOwner->EmitEffect(&spawn);
}

if ((self->field000a == 2) && (self->field000c == 0)) {
    spawn.type = 4;
    spawn.x = (double)(int)self->positionX;
    spawn.y = (double)(int)self->positionY;
    spawn.group = 2;
    spawn.layer = 1;
    self->contextOwner->EmitEffect(&spawn);
}

self->field000c = self->field000c + 1;
if (timing.frameDuration <= self->field000c) {
    self->field000c = 0;
    self->field000a = self->field000a + 1;
    self->attackCollisionResult = 0;
    if (timing.animationFrameCount <= self->field000a) {
        self->field0008 = 9;
        self->velocityX = (double)self->field3138 * 0.01;
        self->velocityY = (double)self->field313c * 0.01;
        self->gravity = 0.035;
        self->ResetPose();
    }
}
