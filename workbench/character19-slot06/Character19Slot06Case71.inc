velocityX = 0.0;
velocityY = 0.0;

if ((field000a == 0) && (field000c == 0)) {
    velocityX = 0.0;
    velocityY = 0.0;
    gravity = 0.0;
    field3138 = 10;
}

if ((field000a == 0) && (field000c == 0)) {
    hitstunFrames = 0x78;
    meter = meter - 3000;
    SetTint(0xb0, 3);

    spawn.type = 0x46;
    spawn.x = (double)(int)positionX;
    spawn.y = (double)((int)positionY - 0x28);
    spawn.palette = 0x40;
    spawn.group = 2;
    spawn.layer = 1;
    spawn.owner = 1;
    contextOwner->EmitEffect(&spawn);
    remainingHitCount = 99;
}

if ((field000a > 6) && (field000a < 0x0c)) {
    SetHorizontalShake(0x32, 3);
}

if ((field000a == 8) && (field000c == 0)) {
    SetVerticalShake(3, 0x14);

    spawn.type = 0x1a2;
    spawn.x = positionX - 30.0;
    spawn.y = positionY;
    spawn.flag0018 = facing;
    spawn.group = 2;
    spawn.layer = 1;
    spawn.owner = 1;
    EmitLocalEffect(&spawn);

    spawn.x = (positionX - (double)((char)facing * 0x28)) - 30.0;
    spawn.flag0018 = (char)-facing;
    EmitLocalEffect(&spawn);
    pendingContextSoundSlot = 0x12;
}

field000c = field000c + 1;
if (timing.frameDuration <= field000c) {
    field000c = 0;
    field000a = field000a + 1;
    attackCollisionResult = 0;

    if ((field000a == 0x0d) && (field3138 > 0)) {
        field000a = field000a - 2;
        field3138 = field3138 - 1;
    }
    if (timing.animationFrameCount <= field000a) {
        FaceOpponent();
        ResetPose();
        field0008 = 0;
    }
}
