if ((self->field000a == 0) && (self->field000c == 0)) {
    self->ResetFrame();
}

if ((self->field000a == 7) && (self->field000c == 0)) {
    spawn.owner = 1;
    spawn.type = 0x195;
    spawn.x = (double)((int)self->positionX + (int)self->facing * 0x23);
    spawn.y = (double)((int)self->positionY - 0x3f);
    spawn.group = 2;
    spawn.layer = 1;
    spawn.facing = (self->facing != 1);
    spawn.flag0018 = (unsigned char)self->facing;
    spawn.field0028 = 0;
    self->EmitLocalEffect(&spawn);
}

if ((self->field000a == 8) && (self->field000c == 0)) {
    spawn.owner = 1;
    spawn.type = 0x196;
    spawn.x = (double)((int)self->positionX + (int)self->facing * 0x50);
    spawn.y = (double)((int)self->positionY - 0x3f);
    spawn.group = 2;
    spawn.layer = 1;
    spawn.facing = (self->facing != 1);
    spawn.flag0018 = (unsigned char)self->facing;
    spawn.field0028 = 0;
    self->EmitLocalEffect(&spawn);

    self->meter = self->meter + 45;
    self->pendingCharacterSoundSlot = 2;
}

self->field000c = self->field000c + 1;
if (timing.frameDuration <= self->field000c) {
    self->field000c = 0;
    self->field000a = self->field000a + 1;
    if (timing.animationFrameCount <= self->field000a) {
        self->field0008 = 0;
        self->ResetPose();
    }
}
