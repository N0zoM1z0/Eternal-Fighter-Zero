if (self->field0120 != 0) {
        self->field0118 = self->field0118 - 1.5;
    }

    self->meter = self->meter + 3;
    self->velocityX = self->knockbackVelocityX;
    self->velocityY = self->knockbackVelocityY;
    ++self->field000c;
    if (self->Slot06OpponentWithinKnockbackRange()) {
        self->field0008 = 0x46;
        self->ResetPose();
    } else {
if (self->field000c >= timing.frameDuration) {
        self->field000c = 0;
        ++self->field000a;
        if (self->field000a >= timing.animationFrameCount) {
            self->field000a = self->field000a - 2;
        }
    }

    if ((self->positionY + self->velocityY) >= 0.0) {
        self->positionY = 0.0;
        if (self->knockdownOnLanding != 0) {
            self->field0008 = 0x61;
            self->ResetPose();
        } else {
            self->field0008 = 0x62;
            self->ResetPose();
        }
    }
    }

