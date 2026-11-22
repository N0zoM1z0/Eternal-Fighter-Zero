if ((self->field000a == 0) && (self->field000c == 0)) {
        self->velocityX = self->velocityX * 0.3;
        self->velocityY = self->velocityY * 0.3;
    }

    self->velocityY = self->velocityY + 0.01;
    if (self->velocityY > 0.3) {
        self->velocityY = 0.3;
    }

    if ((self->field000a == 4) && (self->field000c == 0)) {
        self->remainingHitCount = 1;
        self->meter = self->meter + 45;
        self->pendingCharacterSoundSlot = 1;
    }

    if ((self->field000a == 4) && (self->field000c == 0)) {
        spawn.type = 0x194;
        spawn.x = (double)((int)self->positionX - (int)self->facing * 0x50);
        spawn.y = (double)((int)self->positionY - 0x28);
        spawn.group = 2;
        spawn.layer = 1;
        spawn.owner = 1;
        spawn.flag0018 = (unsigned char)self->facing;
        self->EmitLocalEffect(&spawn);
    }

    ++self->field000c;
    if (self->field000c >= timing.frameDuration) {
        self->field000c = 0;
        ++self->field000a;
        if (self->field000a < 5) {
            self->attackCollisionResult = 0;
        }
        if (self->field000a >= timing.animationFrameCount) {
            self->field0008 = 9;
            self->ResetPose();
        }
    }
