if (self->field0120 != 0) {
        self->field0118 = self->field0118 - 0.6;
    }

    self->dashMomentumFlag = 0;
    if ((self->field000a == 0) && (self->field000c == 0)) {
        self->meter = self->meter + 30;
        if (self->field0120 != 0) {
            self->field0118 = self->field0118 - 30.0;
        }
        self->velocityX = 2.2;
    }

    self->velocityY = 0.0;
    self->positionY = 0.0;
    self->gravity = 0.0;
    self->horizontalDeceleration = 0.06;
    self->velocityX = self->velocityX - self->horizontalDeceleration;
    if (self->velocityX < 0.0) {
        self->velocityX = 0.0;
    }

    if ((self->positionX - 20.0 <= 0.0) || (639.0 <= self->positionX + 20.0)) {
        self->outgoingPushbackVelocityX =
            (1.0 - (double)((*self->opponentSlot)->positionY < 0.0) * 0.25) *
            self->velocityX;
    } else {
        self->outgoingPushbackVelocityX = 0.0;
    }

    self->field000c = self->field000c + 1;
    if (timing.frameDuration <= self->field000c) {
        self->field000c = 0;
        self->field000a = self->field000a + 1;
        if (timing.animationFrameCount <= self->field000a) {
            self->field0008 = 7;
            if (self->inputY == 1) {
                self->field0008 = 3;
            }
            self->ResetPose();
        }
    }
