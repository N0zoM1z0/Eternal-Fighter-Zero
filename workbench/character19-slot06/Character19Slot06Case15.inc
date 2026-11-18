if (field0120 != 0) {
    field0118 = field0118 - 0.6;
}
dashMomentumFlag = 0;

if ((field000a == 0) && (field000c == 0)) {
    meter = meter + 20;
    velocityX = (2.0 - (*opponentSlot)->comboDamageScale / 10000.0) *
                -1.8;
    if (field0120 != 0) {
        field0118 = field0118 - 30.0;
    }
}

velocityY = 0.0;
positionY = 0.0;
velocityX = velocityX + 0.06;
if (velocityX > 0.0) {
    velocityX = 0.0;
}

if (((positionX - 20.0 <= 0.0) || (639.0 <= positionX + 20.0))) {
    outgoingPushbackVelocityX =
        (1.0 - (double)(positionY < 0.0) * 0.2) * velocityX;
} else {
    outgoingPushbackVelocityX = 0.0;
}

field000c = field000c + 1;
if (timing.frameDuration <= field000c) {
    field000c = 0;
    field000a = field000a + 1;
    if (timing.animationFrameCount <= field000a) {
                field0008 = 0;
        if (inputY == 1) {
            field0008 = 3;
        }
        ResetPose();
    }
}
