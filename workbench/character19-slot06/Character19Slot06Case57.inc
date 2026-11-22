if ((self->field000a == 0) && (self->field000c == 0)) {
        self->velocityX = 0.0;
        self->velocityY = 0.0;
    }

    if ((self->field000a == 1) && (self->field000c == 0)) {
        self->velocityX = 1.4;
        self->velocityY = -1.5;
        self->gravity = 0.08;
    }

    if ((self->field000a == 2) && (self->field000c == 0)) {
        self->meter = self->meter + 15;
        self->pendingContextSoundSlot = 0x14;
        self->remainingHitCount = 1;
    }

    if ((self->field000a == 5) && (self->field000c == 0)) {
        self->velocityX = 0.0;
        self->velocityY = 0.0;
        self->gravity = 0.0;
    }

    if (self->field000a > 0) {
        self->velocityY = self->velocityY + self->gravity;
    }

    ++self->field000c;
    if (self->field000c >= timing.frameDuration) {
        self->field000c = 0;
        ++self->field000a;
        self->attackCollisionResult = 0;

        if (self->field000a == 5) {
            if ((self->positionY + self->velocityY) < 0.0) {
                self->field000a = self->field000a - 1;
            } else {
                self->positionY = 0.0;
            }
        }

        if (self->field000a >= timing.animationFrameCount) {
            self->field0008 = 0;
            self->FaceOpponent();
            self->ResetPose();
        }
    }
