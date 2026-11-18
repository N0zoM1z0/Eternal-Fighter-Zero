Secondary *target = *opponentSlot;

if ((field000a == 4) && (field000c == 0)) {
    ApplyDamage(0x4e2, 750.0);
}

field000c = field000c + 1;
if (timing.frameDuration <= field000c) {
    field000c = 0;
    field000a = field000a + 1;
    attackCollisionResult = 0;

    if (field000a == 1) {
        target->field0008 = 0x67;
        target->ResetFrame();
        target->ResetPose();
        target->positionY = -86.0;
        target->positionX = positionX + (double)((int)facing * 0x29);
    }

    if (field000a == 2) {
        target->positionY = -97.0;
        target->positionX = positionX + (double)((int)facing * 0x24);
    }

    if (field000a == 3) {
        target->positionY = -97.0;
        target->positionX = positionX + (double)((int)facing * 0x22);
        target->facing = -facing;
    }

    if (field000a == 4) {
        target->positionY = 0.0;
        target->positionX = positionX + (double)((int)facing * 0x24);
        target->facing = -facing;
        SetVerticalShake(3, 0);
        target->field0008 = 0x61;
        target->ResetFrame();
        target->ResetPose();
    }

    if (timing.animationFrameCount <= field000a) {
        field0008 = 0;
        FaceOpponent();
        ResetPose();
    }
}
