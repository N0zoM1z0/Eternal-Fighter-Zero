velocityY = velocityY + gravity;

if ((field000a == 0) && (field000c == 0)) {
    meter = meter + 30;
    pendingContextSoundSlot = 0x14;
    remainingHitCount = 1;
    velocityX = velocityX / 2.0;
    gravity = 0.07;
}

if (attackCollisionResult > 1) {
    field0008 = 0xd5;
    ResetPose();
    ResetFrame();
    return;
}

if ((positionY + velocityY) >= 0.0) {
    positionY = 0.0;
    ResetFrame();
    velocityY = 0.0;
    SetVerticalShake(3, 0);

    spawn.type = 3;
    spawn.x = (double)(int)positionX;
    spawn.y = (double)(int)positionY;
    spawn.group = 2;
    spawn.layer = 0;
    spawn.palette = 7;
    contextOwner->EmitEffect(&spawn);

    pendingContextSoundSlot = 7;
    field0008 = 0xd6;
    ResetPose();
    return;
}

field000c = field000c + 1;
if (timing.frameDuration <= field000c) {
    field000c = 0;
    field000a = field000a + 1;
    attackCollisionResult = 0;
    if (timing.animationFrameCount <= field000a) {
        field000a = field000a - 2;
    }
}
