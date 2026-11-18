Secondary *target = *opponentSlot;
velocityX = 0.0;
velocityY = 0.0;

if ((field000a == 1) && (field000c == 0) &&
    (target->positionY == 0.0)) {
    remainingHitCount = 1;
} else {
    remainingHitCount = 0;
}

if ((field000a == 1) && (attackCollisionResult == 3)) {
    velocityX = 0.0;
    velocityY = 0.0;
    outgoingPushbackVelocityX = 0.0;
    ResetPose();
    ResetFrame();
    target->ResetFrame();
    target->ResetPose();
    field0008 = 0xdd;
    target->airActionDisabled = 1;

    spawn.type = 0;
    spawn.x = (double)((int)positionX + (int)facing * 0x25);
    spawn.y = (double)((int)positionY - 0x2a);
    spawn.group = 2;
    spawn.layer = 1;
    contextOwner->EmitEffect(&spawn);
    return;
}

field000c = field000c + 1;
if (timing.frameDuration <= field000c) {
    field000c = 0;
    field000a = field000a + 1;
    attackCollisionResult = 0;
    if (timing.animationFrameCount <= field000a) {
        field0008 = 0;
        if (inputY == 1) {
            field0008 = 3;
        }
        FaceOpponent();
        ResetPose();
    }
}
