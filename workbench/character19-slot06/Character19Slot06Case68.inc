if ((self->field000a == 0) && (self->field000c == 0)) {
    self->ResetFrame();
    self->remainingHitCount = 2;
}

if ((self->positionY < 0.0) &&
    ((self->velocityY = self->velocityY + self->gravity),
     ((self->positionY + self->velocityY) >= 0.0))) {
    self->positionY = 0.0;
    self->ResetPose();
    self->ResetFrame();
    self->field0008 = 0x103;
} else {
    ++self->field000c;
    if (self->field000c >= timing.frameDuration) {
        self->field000c = 0;
        ++self->field000a;
        self->attackCollisionResult = 0;

        if (self->field000a == 3) {
            self->velocityY = -2.5;
            self->gravity = 0.045;

            spawn.type = 0x1b9;
            spawn.x = self->positionX;
            spawn.y = self->positionY;
            spawn.owner = 1;
            spawn.flag0018 = (unsigned char)self->facing;
            spawn.group = 2;
            spawn.layer = 1;
            self->EmitLocalEffect(&spawn);
        }

        if (self->field000a >= timing.animationFrameCount) {
            self->field000a = self->field000a - 2;
        }
    }
}
