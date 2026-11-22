self->velocityX = 0.0;
self->velocityY = 0.0;

if ((self->field000a == 0) && (self->field000c == 0)) {
    self->velocityX = 0.0;
    self->velocityY = 0.0;
    self->gravity = 0.035;
}

if ((self->field000a == 0) && (self->field000c == 0)) {
    self->hitstunFrames = 0x78;
    self->meter = self->meter - 3000;
    self->SetTint(0xb0, 0x21);

    spawn.type = 0x46;
    spawn.x = (double)(int)self->positionX;
    spawn.y = (double)((int)self->positionY - 0x28);
    spawn.palette = 0x40;
    spawn.group = 2;
    spawn.layer = 1;
    spawn.owner = 1;
    self->contextOwner->EmitEffect(&spawn);
}

if ((self->field000a > 6) && (self->field000a < 0x0c)) {
    self->SetHorizontalShake(0x32, 3);
}

if ((self->field000a == 8) && (self->field000c == 0)) {
    spawn.type = 0x1aa;
    spawn.x = self->positionX;
    spawn.y = self->positionY;
    spawn.flag0018 = self->facing;
    spawn.group = 2;
    spawn.layer = 1;
    spawn.owner = 1;
    self->EmitLocalEffect(&spawn);
}

self->field000c = self->field000c + 1;
if (timing.frameDuration <= self->field000c) {
    self->field000c = 0;
    self->field000a = self->field000a + 1;
    self->attackCollisionResult = 0;
    if (timing.animationFrameCount <= self->field000a) {
        self->field0008 = 9;
        self->FaceOpponent();
        self->ResetPose();
    }
}
