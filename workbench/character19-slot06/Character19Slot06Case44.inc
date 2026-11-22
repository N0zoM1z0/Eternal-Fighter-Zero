if ((self->field000a == 0) && (self->field000c == 0)) {
    self->StartTrail(2);
    self->ResetFrame();
}

if ((self->field000a == 2) && (self->field000c == 0)) {
    self->velocityX = -2.0;
    self->velocityY = -1.0;
    self->gravity = 0.035;
    self->pendingCharacterSoundSlot = 0;
}

int continueAirborne = (self->positionY >= 0.0);
if (!continueAirborne) {
    self->velocityY = self->velocityY + self->gravity;
    continueAirborne = (self->positionY + self->velocityY <= 0.0);
}

if (continueAirborne) {
    

    self->field000c = self->field000c + 1;
    if (timing.frameDuration <= self->field000c) {
        self->field000c = 0;
        self->field000a = self->field000a + 1;
        
        if (timing.animationFrameCount <= self->field000a) {
            self->field000a = self->field000a - 1;
        }
    }
} else {
    self->positionY = 0.0;
    self->ResetPose();
self->ResetFrame();
self->field0008 = 13;
}
