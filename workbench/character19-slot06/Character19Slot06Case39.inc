if ((self->health > 0) && (self->field000c > 60) && (self->field000a == 0)) {
        self->field0008 = 0x60;
        self->ResetPose();
        self->dashMomentumFlag = 0;
    }

    ++self->field000c;
    if (self->field000c >= timing.frameDuration) {
        self->field000c = 0;
        ++self->field000a;
        if (self->field000a == timing.animationFrameCount) {
            self->FaceOpponent();
        }
        if (self->field000a >= timing.animationFrameCount) {
            self->field0008 = 0x60;
            self->ResetPose();
        }
    }
