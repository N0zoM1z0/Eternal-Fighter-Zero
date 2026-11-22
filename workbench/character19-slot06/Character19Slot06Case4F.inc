if (self->dashMomentumFlag == 0) {
    self->velocityX = 0.0;
    self->velocityY = 0.0;
}

if ((self->velocityX > 0.0) && (self->dashMomentumFlag == 1)) {
    self->velocityX = self->velocityX - 0.06;
} else {
    self->velocityX = 0.0;
    self->dashMomentumFlag = 0;
}





if ((self->field000a == 4) && (self->field000c == 0)) {
    self->meter = self->meter + 15;
    self->pendingContextSoundSlot = (char)20;
    self->remainingHitCount = 1;
}



if ((self->field000a == 3) && (self->field000c == 0)) {
    if ((self->field000a == 3) && (self->field000c == 0)) {
    spawn.owner = 1;
        spawn.type = 0x1a5;
        spawn.x = (double)(int)self->positionX;
        spawn.y = (double)(int)self->positionY;
        spawn.flag0018 = (unsigned char)self->facing;
        spawn.group = 2;
        spawn.layer = 1;
        self->EmitLocalEffect(&spawn);
}
}

self->field000c = self->field000c + 1;
if (timing.frameDuration <= self->field000c) {
    self->field000c = 0;
    self->field000a = self->field000a + 1;
    if (self->field000a < 3) {
        self->attackCollisionResult = 0;
    }
    if (timing.animationFrameCount <= self->field000a) {
        self->field0008 = 0;

        self->FaceOpponent();
        self->ResetPose();
    }
}
