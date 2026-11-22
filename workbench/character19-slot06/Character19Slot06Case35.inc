if ((self->field000a == 0) && (self->field000c == 0)) {
        spawn.type = 0x1ef;
        spawn.x = 60.0;
        spawn.y = 40.0;
        spawn.payload = 1;
        spawn.flag0018 = 1;
        spawn.group = 0;
        spawn.layer = 0;
        self->EmitLocalEffect(&spawn);
    }

    ++self->field000c;
    if (self->field000c >= timing.frameDuration) {
        self->field000c = 0;
        ++self->field000a;
        if (self->field000a >= timing.animationFrameCount) {
            self->field0008 = 0;
            self->ResetPose();
        }
    }
