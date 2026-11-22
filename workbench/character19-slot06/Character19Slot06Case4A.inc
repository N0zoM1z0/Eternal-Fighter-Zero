if ((self->field000a == 0) && (self->field000c == 0)) {
        self->field3138 = (int)(self->velocityX * 100.0);
        self->field313c = (int)(self->velocityY * 100.0);
        self->velocityX = 0.0;
        self->velocityY = 0.0;
        if (self->gravity == 0.0) {
            self->gravity = 0.035;
        }
        self->guardInputFrames = 0;
        self->outgoingPushbackVelocityX = 0.0;
        self->hitstunFrames = 60;
    }

    if ((self->hitstunFrames == 0) && (self->field3140 == 0)) {
        self->field3140 = self->field3140 + 1;
        self->velocityX = (double)self->field3138 * 0.01;
        self->velocityY = (double)self->field313c * 0.01;
    }

    if (self->hitstunFrames == 0) {
        self->velocityY = self->velocityY + self->gravity;
    }

    if ((self->positionY + self->velocityY) > 0.0) {
        self->ResetFrame();
        self->positionY = 0.0;
        self->field0008 = 0xa9;
    } else {
        ++self->field000c;
        if (self->field000c >= timing.frameDuration) {
            self->field000c = 0;
            ++self->field000a;
            if (self->field000a >= timing.animationFrameCount) {
                self->field0008 = 9;
                self->ResetPose();
            }
        }
    }
