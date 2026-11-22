self->velocityX = 0.0;
    self->velocityY = 0.0;
    if ((self->field000a == 0) && (self->field000c == 0)) {
        self->SetVerticalShake(3, 0);
        spawn.type = 3;
        spawn.x = (double)(int)self->positionX;
        spawn.y = (double)(int)self->positionY;
        spawn.group = 2;
        spawn.layer = 0;
        self->contextOwner->EmitEffect(&spawn);
        self->pendingContextSoundSlot = 7;
    }

    ++self->field000c;
    if (self->field000c >= timing.frameDuration) {
        self->field000c = 0;
        ++self->field000a;
        if (self->field000a >= timing.animationFrameCount) {
            self->field0008 = 99;
            self->ResetPose();
        }
    }
