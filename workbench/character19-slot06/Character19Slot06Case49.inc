if ((self->field000a == 0) && (self->field000c == 0)) {
        self->dashMomentumFlag = 0;
        self->velocityX = 0.0;
        self->velocityY = 0.0;
        self->positionY = 0.0;
        self->gravity = 0.0;
        self->guardInputFrames = 0;
        self->outgoingPushbackVelocityX = 0.0;
        self->horizontalDeceleration = 0.0;

        spawn.type = 8;
        spawn.x = (double)(int)self->positionX;
        spawn.y = (double)(int)self->positionY;
        spawn.group = 2;
        spawn.layer = 1;
        self->contextOwner->EmitEffect(&spawn);
    }

    ++self->field000c;
    if (self->field000c >= timing.frameDuration) {
        self->field000c = 0;
        ++self->field000a;
        if (self->field000a == timing.animationFrameCount) {
            self->FaceOpponent();
        }
        if (self->field000a >= timing.animationFrameCount) {
            self->field0008 = 3;
            self->ResetPose();
        }
    }
