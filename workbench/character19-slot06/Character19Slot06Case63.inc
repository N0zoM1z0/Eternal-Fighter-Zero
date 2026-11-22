self->StartTrail(3);
    self->dashMomentumFlag = 0;

    if (self->field000a < 3) {
        if ((unsigned char)self->dashMomentumFlag == 0) {
            self->velocityX = 0.0;
        }
        if ((self->velocityX > 0.0) &&
            ((unsigned char)self->dashMomentumFlag == 1)) {
            self->velocityX = self->velocityX - 0.07;
        } else {
            self->velocityX = 0.0;
            self->dashMomentumFlag = 0;
        }
    }

    if ((self->field000a > 2) && (self->field000a < 0xf)) {
        self->velocityY = self->velocityY + self->gravity;
        if ((self->positionY + self->velocityY) > 0.0) {
            self->field000c = 0;
            self->ResetFrame();
            self->positionY = 0.0;
            self->field000a = 0xf;
        }
    }

    if ((self->field000a == 7) && (self->field000c == 0)) {
        self->pendingContextSoundSlot = 0x14;
        self->remainingHitCount = 1;
        self->meter = self->meter + 35;
    }

    ++self->field000c;
    if (self->field000c >= timing.frameDuration) {
        self->field000c = 0;
        ++self->field000a;
        if (self->field000a < 3) {
            self->attackCollisionResult = 0;
        }
        if (self->field000a == 3) {
            self->velocityX = 1.5;
            self->velocityY = -1.5;
            self->gravity = 0.032;
        }
        if (self->field000a >= timing.animationFrameCount) {
            self->field0008 = 0;
            self->ResetPose();
        }
    }
