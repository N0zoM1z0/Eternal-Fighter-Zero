if ((field000a == 0) && (field000c == 0)) {
    StartTrail(2);
    ResetFrame();
}

if ((field000a == 2) && (field000c == 0)) {
    velocityX = -2.0;
    velocityY = -1.0;
    gravity = 0.035;
    pendingCharacterSoundSlot = 0;
}

int continueAirborne = (positionY >= 0.0);
if (!continueAirborne) {
    velocityY = velocityY + gravity;
    continueAirborne = (positionY + velocityY <= 0.0);
}

if (continueAirborne) {
    

    field000c = field000c + 1;
    if (timing.frameDuration <= field000c) {
        field000c = 0;
        field000a = field000a + 1;
        
        if (timing.animationFrameCount <= field000a) {
            field000a = field000a - 1;
        }
    }
} else {
    positionY = 0.0;
    ResetPose();
ResetFrame();
field0008 = 13;
}
