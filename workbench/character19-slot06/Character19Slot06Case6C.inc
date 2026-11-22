if ((self->field000a == 0) && (self->field000c == 0)) {
        self->ResetFrame();
    }

    if ((self->field000a == 0) && (self->field000c == 0)) {
        
        spawn.type = 0x191;
        
        spawn.x = (double)((int)self->positionX + (int)self->facing * 0x1e);
        spawn.y = (double)((int)self->positionY - 0x28);
        spawn.group = 0;
        spawn.layer = 1;
        spawn.facing = (self->facing != 1);
        spawn.flag0018 = (unsigned char)self->facing;
        spawn.field0028 = 1;
        spawn.owner = 1;
        self->EmitLocalEffect(&spawn);

        self->meter = self->meter + 45;
        self->pendingCharacterSoundSlot = 2;
    }

    ++self->field000c;
    if (self->field000c >= timing.frameDuration) {
        self->field000c = 0;
        ++self->field000a;
        if (self->field000a > 9) {
            self->attackCollisionResult = 0;
        }
        if (self->field000a >= timing.animationFrameCount) {
            self->field0008 = 0;
            self->ResetPose();
        }
    }
