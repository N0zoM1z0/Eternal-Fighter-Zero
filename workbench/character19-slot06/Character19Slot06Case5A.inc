self->gravity = 0.042;
    self->velocityY = self->velocityY + self->gravity;

    if ((self->field000a == 0) && (self->field000c == 0)) {
        self->velocityX = -1.0;
        self->velocityY = -2.4;
    }

    ++self->field000c;
    if (self->field000c >= timing.frameDuration) {
        self->field000c = 0;
        ++self->field000a;
        self->attackCollisionResult = 0;
        if (self->field000a >= timing.animationFrameCount) {
            self->field0008 = 9;
            self->ResetPose();
        }
    }
