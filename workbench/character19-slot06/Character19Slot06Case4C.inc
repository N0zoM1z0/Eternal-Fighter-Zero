self->velocityX = self->velocityX - 0.03;
    self->velocityX = self->velocityX;
    if (self->velocityX < 0.0) {
        self->velocityX = 0.0;
        self->dashMomentumFlag = 0;
    }

    if ((self->inputY == -1) && (self->field000a > 0) && (self->field015c < 3)) {
        self->field0008 = 4;
        if (self->inputX == self->facing) {
            self->field0008 = 5;
        }
        if (self->inputX == -self->facing) {
            self->field0008 = 6;
        }
        self->attackCollisionResult = 0;
        self->ResetPose();
        break;
    } else {
        ++self->field000c;
        if (self->field000c >= timing.frameDuration) {
            self->field000c = 0;
            ++self->field000a;
            if (self->field000a >= timing.animationFrameCount) {
                self->field0008 = 0;
                self->ResetPose();
                break;
            }
        }
        break;
    }
