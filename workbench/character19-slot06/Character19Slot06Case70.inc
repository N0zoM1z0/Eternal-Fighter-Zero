if ((self->field000a == 0) && (self->field000c == 0)) {
    self->velocityX = 0.0;
    self->velocityY = 0.0;
    self->gravity = 0.0;
}

if ((self->field000a == 0) && (self->field000c == 0)) {
    self->hitstunFrames = 0xc6;
    self->meter = self->meter - 3000;
    self->SetTint(0xb0, 3);

    spawn.type = 0x46;
    spawn.x = (double)((int)self->positionX + (char)self->facing * 0x1d);
    spawn.y = (double)((int)self->positionY - 0x3f);
    spawn.palette = 0x40;
    spawn.group = 2;
    spawn.owner = 1;
    spawn.layer = 1;
    self->contextOwner->EmitEffect(&spawn);
    self->remainingHitCount = 99;
    self->pendingContextSoundSlot = 0x25;
}

if (self->field000a > 2) {
    self->contextOwner->SetSceneTimer(0x0f);
}

if ((self->field000a == 7) && (self->field000c == 0)) {
    spawn.type = 0x19f;
    spawn.x = self->positionX - (double)((char)self->facing * 0x23);
    spawn.y = self->positionY - 67.0;
    spawn.flag0018 = self->facing;
    spawn.group = 2;
    spawn.layer = 0;
    spawn.palette = 0xff;
    spawn.field0030 = 1;
    spawn.owner = 1;
    self->EmitLocalEffect(&spawn);
}

if (self->field000a > 3) {
    self->SetHorizontalShake(0x32, 3);
}

if ((self->field000a == 0x0d) && (self->field000c == 0)) {
    self->pendingCharacterSoundSlot = 5;
}

if ((self->field000a > 0x0d) && (self->field000a < 0x11)) {
    self->field313c = self->field313c + 1;
    randomValue = (unsigned short)self->RandomRange(0, 100);
    if (((double)self->field313c * 0.08 + 60.0) < (double)randomValue) {
        spawn.type = 0x1a1;
        spawn.layer = 1;
        spawn.owner = 1;

        randomValue = (unsigned short)self->RandomRange(0, 100);
        if (0x32 < randomValue) {
            spawn.type = 0x1a0;
            spawn.layer = 0;
        }

        spawn.x = self->positionX - (double)((char)self->facing * 300);
        spawn.y = (double)(int)((unsigned short)self->RandomRange(0, 0x140) - 0x140);
        spawn.flag0018 = self->facing;
        spawn.group = 2;
        self->EmitLocalEffect(&spawn);
    }
}

self->field000c = self->field000c + 1;
if (timing.frameDuration <= self->field000c) {
    self->field000c = 0;
    self->field000a = self->field000a + 1;
    self->attackCollisionResult = 0;

    if ((self->field3138 < 0x0d) && (self->field000a == 0x11)) {
        self->field000a = self->field000a - 3;
        self->field3138 = self->field3138 + 1;
    } else if (timing.animationFrameCount <= self->field000a) {
        self->FaceOpponent();
        self->ResetPose();
        self->field0008 = 0;
        if (self->positionY < 0.0) {
            self->field0008 = 9;
            self->gravity = 0.035;
        }
    }
}
