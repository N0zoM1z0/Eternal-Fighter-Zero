++self->field000c;
    if (self->field000c >= timing.frameDuration) {
        self->field000c = 0;
        ++self->field000a;
        if (self->field000a == timing.animationFrameCount - 1) {
            self->FaceOpponent();
        }
        if (self->field000a >= timing.animationFrameCount) {
            self->field0008 = 7;
            if (self->inputY == 1) {
                self->field0008 = 3;
            }
            self->ResetPose();
        }
    }
