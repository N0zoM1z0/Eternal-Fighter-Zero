Secondary *target = *self->opponentSlot;
self->velocityX = 0.0;
self->velocityY = 0.0;

if ((self->field000a == 1) && (self->field000c == 0) &&
    (target->positionY == 0.0)) {
    self->remainingHitCount = 1;
} else {
    self->remainingHitCount = 0;
}

if ((self->field000a == 1) && (self->attackCollisionResult == 3)) {
    self->velocityX = 0.0;
    self->velocityY = 0.0;
    self->outgoingPushbackVelocityX = 0.0;
    self->ResetPose();
    self->ResetFrame();
    target->ResetFrame();
    target->ResetPose();
    self->field0008 = 0xdd;
    target->airActionDisabled = 1;

    spawn.type = 0;
    spawn.x = (double)((int)self->positionX + (int)self->facing * 0x25);
    spawn.y = (double)((int)self->positionY - 0x2a);
    spawn.group = 2;
    spawn.layer = 1;
    self->contextOwner->EmitEffect(&spawn);
    return;
}

self->field000c = self->field000c + 1;
if (timing.frameDuration <= self->field000c) {
    self->field000c = 0;
    self->field000a = self->field000a + 1;
    self->attackCollisionResult = 0;
    if (timing.animationFrameCount <= self->field000a) {
        self->field0008 = 0;
        if (self->inputY == 1) {
            self->field0008 = 3;
        }
        self->FaceOpponent();
        self->ResetPose();
    }
}
