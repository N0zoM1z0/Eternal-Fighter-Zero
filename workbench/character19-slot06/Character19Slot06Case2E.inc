if (field0120 != 0) {
        field0118 = field0118 - 0.6;
    }

    dashMomentumFlag = 0;
    if ((field000a == 0) && (field000c == 0)) {
        meter = meter + 30;
        if (field0120 != 0) {
            field0118 = field0118 - 30.0;
        }
        velocityX = 2.2;
    }

    velocityY = 0.0;
    positionY = 0.0;
    gravity = 0.0;
    horizontalDeceleration = 0.06;
    velocityX = velocityX - horizontalDeceleration;
    if (velocityX < 0.0) {
        velocityX = 0.0;
    }

    if ((positionX - 20.0 <= 0.0) || (639.0 <= positionX + 20.0)) {
        outgoingPushbackVelocityX =
            (1.0 - (double)((*opponentSlot)->positionY < 0.0) * 0.25) *
            velocityX;
    } else {
        outgoingPushbackVelocityX = 0.0;
    }

    field000c = field000c + 1;
    if (timing.frameDuration <= field000c) {
        field000c = 0;
        field000a = field000a + 1;
        if (timing.animationFrameCount <= field000a) {
            field0008 = 3;
            ResetPose();
        }
    }
