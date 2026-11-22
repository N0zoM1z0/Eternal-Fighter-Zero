if ((self->field000a == 0) && (self->field000c == 0)) {
    self->StartTrail(1);
    if (self->field313c == 0) {
        self->ResetFrame();
        if (self->field0120 == 0) {
            self->field0118 = self->field0118 - 500.0;
        } else {
            self->field0118 = self->field0118 - 250.0;
        }

        spawn.type = 0x21;
        spawn.x = (double)(int)self->positionX;
        spawn.y = (double)((int)self->positionY - 0x32);
        spawn.group = 2;
        spawn.layer = 1;
        spawn.palette = 0xb;
        self->contextOwner->EmitEffect(&spawn);
        self->field313c = self->field313c + 1;
    }
    self->remainingHitCount = 1;
}

if ((self->field000a == 1) && (self->field000c == 0)) {
    spawn.owner = 1;
    spawn.type = 0x1b9;
    spawn.x = self->positionX;
    spawn.y = self->positionY;
    spawn.flag0018 = (unsigned char)self->facing;
    spawn.group = 2;
    spawn.layer = 1;
    self->EmitLocalEffect(&spawn);
}

if (self->positionY < 0.0) {
    self->velocityY = self->velocityY + self->gravity;
}

if ((self->positionY >= 0.0) || ((self->positionY + self->velocityY) < 0.0)) {
    self->field000c = self->field000c + 1;
    if (timing.frameDuration <= self->field000c) {
        self->field000c = 0;
        self->field000a = self->field000a + 1;
        self->attackCollisionResult = 0;

        if ((self->field000a == 3) && (self->field313c == 1)) {
            self->velocityY = -3.5;
            self->gravity = 0.015;
            self->field313c = self->field313c + 1;
        }

        if ((self->field000a == 8) && (self->field3138 < 5)) {
            self->field000a = 0;
            self->field3138 = self->field3138 + 1;
        }

        if (self->field000a == 9) {
            self->remainingHitCount = 1;
        }

        if (timing.animationFrameCount <= self->field000a) {
            self->ResetPose();
            self->field0008 = 9;
        }
    }
} else {
    self->positionY = 0.0;
    self->ResetPose();
    self->ResetFrame();
    self->field0008 = 0x103;
}
