if ((self->field000a == 0) && (self->field000c == 0)) {
        self->field00dc = 4;
        self->field00de = 0xec;
        self->velocityX = 0.0;
        self->remainingHitCount = 1;
        self->guardInputFrames = 0;
        self->hitstunFrames = 60;

        spawn.type = 0x28;
        spawn.x = (double)((int)self->positionX + (int)self->facing * 10);
        spawn.y = (double)((int)self->positionY - 0x28);
        spawn.group = 2;
        spawn.layer = 1;
        spawn.palette = 0x13;
        self->contextOwner->EmitEffect(&spawn);
    }

    ++self->field000c;
    if (self->field000c >= timing.frameDuration) {
        self->field000c = 0;
        ++self->field000a;
        self->attackCollisionResult = 0;
        if (self->field000a >= timing.animationFrameCount) {
            self->field0008 = 0;
            self->FaceOpponent();
            self->ResetPose();
        }
    }
