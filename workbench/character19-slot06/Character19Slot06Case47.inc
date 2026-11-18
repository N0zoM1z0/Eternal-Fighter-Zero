if ((field000a == 0) && (field000c == 0)) {
    dashMomentumFlag = 0;
    velocityX = 0.0;
    velocityY = 0.0;
    if (field0120 == 1) {
        comboDamageScale = comboDamageScale + (field0118 * 5.0);
    }
    field0118 = 0.0;
    hitstunFrames = 90;
    SetTint(0xb0, 3);
}

if ((field000a == 1) && (field000c == 0)) {
    pendingContextSoundSlot = 0x12;
    spawn.type = 1;
    spawn.x = (double)(int)positionX;
    spawn.y = (double)(int)positionY;
    spawn.group = 2;
    spawn.layer = 1;
    contextOwner->EmitEffect(&spawn);
}

if ((field000a == 2) && (field000c == 0)) {
    spawn.type = 4;
    spawn.x = (double)(int)positionX;
    spawn.y = (double)(int)positionY;
    spawn.group = 2;
    spawn.layer = 1;
    contextOwner->EmitEffect(&spawn);
}

field000c = field000c + 1;
if (timing.frameDuration <= field000c) {
    field000c = 0;
    field000a = field000a + 1;
    attackCollisionResult = 0;
    if (timing.animationFrameCount <= field000a) {
        field0008 = 0;
        FaceOpponent();
        ResetPose();
    }
}
