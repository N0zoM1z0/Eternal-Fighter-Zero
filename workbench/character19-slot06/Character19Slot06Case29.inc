if (self->field0120 != 0) {
        self->field0118 = self->field0118 - 0.8;
    }

    self->dashMomentumFlag = 0;
    self->velocityX = 0.0;
    self->velocityY = 0.0;

    if ((self->positionX - 20.0 <= 0.0) || (639.0 <= self->positionX + 20.0)) {
        self->outgoingPushbackVelocityX =
            (1.0 - (double)((*self->opponentSlot)->positionY < 0.0) * 0.25) *
            self->velocityX;
    } else {
        self->outgoingPushbackVelocityX = 0.0;
    }

    ++self->field000c;
    if (self->field000c >= timing.frameDuration) {
        self->field000c = 0;
        ++self->field000a;
        if (self->field000a >= timing.animationFrameCount) {
            self->field0008 = 7;
            if (self->inputY == 1) {
                self->field0008 = 3;
            }
            self->ResetPose();
        }
    }
