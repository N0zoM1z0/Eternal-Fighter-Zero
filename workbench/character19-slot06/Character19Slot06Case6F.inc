if ((field000a == 0) && (field000c == 0)) {
    ResetFrame();
    StartTrail(3);

    if (field0120 == 0) {
        field0118 = field0118 - 500.0;
    } else {
        field0118 = field0118 - 250.0;
    }

    spawn.type = 0x21;
    spawn.x = (double)(int)positionX;
    spawn.y = (double)((int)positionY - 0x32);
    spawn.group = 2;
    spawn.layer = 1;
    spawn.palette = 0xb;
    contextOwner->EmitEffect(&spawn);
}

if ((field000a == 7) && (field000c == 0)) {
    spawn.owner = 1;
    spawn.type = 0x1ad;
    spawn.x = (double)((int)positionX + (int)facing * 0x23);
    spawn.y = (double)((int)positionY - 0x3f);
    spawn.group = 2;
    spawn.layer = 1;
    spawn.facing = (facing != 1);
    spawn.flag0018 = (unsigned char)facing;
    spawn.field0028 = 0;
    EmitLocalEffect(&spawn);
}

if ((field000a == 8) && (field000c == 0)) {
    meter = meter + 45;
    pendingCharacterSoundSlot = 2;
}

field000c = field000c + 1;
if (timing.frameDuration <= field000c) {
    field000c = 0;
    field000a = field000a + 1;
    if (timing.animationFrameCount <= field000a) {
        field0008 = 0;
        ResetPose();
    }
}
