if ((field000a == 0) && (field000c == 0)) {
    velocityX = 0.0;
    velocityY = 0.0;
    gravity = 0.0;
}

if ((field000a == 0) && (field000c == 0)) {
    hitstunFrames = 0xc6;
    meter = meter - 3000;
    SetTint(0xb0, 3);

    spawn.type = 0x46;
    spawn.x = (double)((int)positionX + (char)facing * 0x1d);
    spawn.y = (double)((int)positionY - 0x3f);
    spawn.palette = 0x40;
    spawn.group = 2;
    spawn.owner = 1;
    spawn.layer = 1;
    contextOwner->EmitEffect(&spawn);
    remainingHitCount = 99;
    pendingContextSoundSlot = 0x25;
}

if (field000a > 2) {
    contextOwner->SetSceneTimer(0x0f);
}

if ((field000a == 7) && (field000c == 0)) {
    spawn.type = 0x19f;
    spawn.x = positionX - (double)((char)facing * 0x23);
    spawn.y = positionY - 67.0;
    spawn.flag0018 = facing;
    spawn.group = 2;
    spawn.layer = 0;
    spawn.palette = 0xff;
    spawn.field0030 = 1;
    spawn.owner = 1;
    EmitLocalEffect(&spawn);
}

if (field000a > 3) {
    SetHorizontalShake(0x32, 3);
}

if ((field000a == 0x0d) && (field000c == 0)) {
    pendingCharacterSoundSlot = 5;
}

if ((field000a > 0x0d) && (field000a < 0x11)) {
    field313c = field313c + 1;
    randomValue = (unsigned short)RandomRange(0, 100);
    if (((double)field313c * 0.08 + 60.0) < (double)randomValue) {
        spawn.type = 0x1a1;
        spawn.layer = 1;
        spawn.owner = 1;

        randomValue = (unsigned short)RandomRange(0, 100);
        if (0x32 < randomValue) {
            spawn.type = 0x1a0;
            spawn.layer = 0;
        }

        spawn.x = positionX - (double)((char)facing * 300);
        spawn.y = (double)(int)((unsigned short)RandomRange(0, 0x140) - 0x140);
        spawn.flag0018 = facing;
        spawn.group = 2;
        EmitLocalEffect(&spawn);
    }
}

field000c = field000c + 1;
if (timing.frameDuration <= field000c) {
    field000c = 0;
    field000a = field000a + 1;
    attackCollisionResult = 0;

    if ((field3138 < 0x0d) && (field000a == 0x11)) {
        field000a = field000a - 3;
        field3138 = field3138 + 1;
    } else if (timing.animationFrameCount <= field000a) {
        FaceOpponent();
        ResetPose();
        field0008 = 0;
        if (positionY < 0.0) {
            field0008 = 9;
            gravity = 0.035;
        }
    }
}
