velocityX = 0.0;
velocityY = 0.0;

if ((field000a == 0) && (field000c == 0)) {
    velocityX = 0.0;
    velocityY = 0.0;
    gravity = 0.035;
}

if ((field000a == 0) && (field000c == 0)) {
    hitstunFrames = 0x78;
    meter = meter - 3000;
    SetTint(0xb0, 0x21);

    spawn.type = 0x46;
    spawn.x = (double)(int)positionX;
    spawn.y = (double)((int)positionY - 0x28);
    spawn.palette = 0x40;
    spawn.group = 2;
    spawn.layer = 1;
    spawn.owner = 1;
    contextOwner->EmitEffect(&spawn);
}

if ((field000a > 6) && (field000a < 0x0c)) {
    SetHorizontalShake(0x32, 3);
}

if ((field000a == 8) && (field000c == 0)) {
    spawn.type = 0x1aa;
    spawn.x = positionX;
    spawn.y = positionY;
    spawn.flag0018 = facing;
    spawn.group = 2;
    spawn.layer = 1;
    spawn.owner = 1;
    EmitLocalEffect(&spawn);
}

field000c = field000c + 1;
if (timing.frameDuration <= field000c) {
    field000c = 0;
    field000a = field000a + 1;
    attackCollisionResult = 0;
    if (timing.animationFrameCount <= field000a) {
        field0008 = 9;
        FaceOpponent();
        ResetPose();
    }
}
