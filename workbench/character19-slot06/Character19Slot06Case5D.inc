Secondary *target = *self->opponentSlot;

if ((self->field000a == 4) && (self->field000c == 0)) {
    ApplyDamage(0x4e2, 750.0);
}

self->field000c = self->field000c + 1;
if (timing.frameDuration <= self->field000c) {
    self->field000c = 0;
    self->field000a = self->field000a + 1;
    self->attackCollisionResult = 0;

    if (self->field000a == 1) {
        target->field0008 = 0x67;
        target->ResetFrame();
        target->ResetPose();
        target->positionY = -86.0;
        target->positionX = self->positionX + (double)((int)self->facing * 0x29);
    }

    if (self->field000a == 2) {
        target->positionY = -97.0;
        target->positionX = self->positionX + (double)((int)self->facing * 0x24);
    }

    if (self->field000a == 3) {
        target->positionY = -97.0;
        target->positionX = self->positionX + (double)((int)self->facing * 0x22);
        target->facing = -self->facing;
    }

    if (self->field000a == 4) {
        target->positionY = 0.0;
        target->positionX = self->positionX + (double)((int)self->facing * 0x24);
        target->facing = -self->facing;
        self->SetVerticalShake(3, 0);
        target->field0008 = 0x61;
        target->ResetFrame();
        target->ResetPose();
    }

    if (timing.animationFrameCount <= self->field000a) {
        self->field0008 = 0;
        self->FaceOpponent();
        self->ResetPose();
    }
}
