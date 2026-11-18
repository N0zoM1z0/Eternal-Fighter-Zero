if ((field000a == 0) && (field000c == 0)) {
    ResetFrame();
}

if ((field000a == 7) && (field000c == 0)) {
    spawn.owner = 1;
    spawn.type = 0x195;
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
    spawn.owner = 1;
    spawn.type = 0x196;
    spawn.x = (double)((int)positionX + (int)facing * 0x50);
    spawn.y = (double)((int)positionY - 0x3f);
    spawn.group = 2;
    spawn.layer = 1;
    spawn.facing = (facing != 1);
    spawn.flag0018 = (unsigned char)facing;
    spawn.field0028 = 0;
    EmitLocalEffect(&spawn);

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
