if ((field000a == 0) && (field000c == 0)) {
    ResetFrame();
}

if ((field000a == 4) && (field000c == 0)) {
    spawn.type = 0x1f;
    spawn.x = (double)(int)positionX;
    spawn.y = (double)(int)positionY;
    spawn.group = 0;
    spawn.layer = 1;
    spawn.facing = (facing != 1);
    contextOwner->EmitEffect(&spawn);

    remainingHitCount = 1;
    meter = meter + 45;
    pendingCharacterSoundSlot = 1;

    spawn.owner = 1;
    spawn.type = 0x194;
    spawn.x = (double)((int)positionX - (int)facing * 0x50);
    spawn.y = (double)((int)positionY - 0x28);
    spawn.group = 2;
    spawn.layer = 1;
    spawn.flag0018 = (unsigned char)facing;
    EmitLocalEffect(&spawn);
}

field000c = field000c + 1;
if (timing.frameDuration <= field000c) {
    field000c = 0;
    field000a = field000a + 1;
    if (field000a < 5) {
        attackCollisionResult = 0;
    }
    if (timing.animationFrameCount <= field000a) {
        field0008 = 0;
        ResetPose();
    }
}
