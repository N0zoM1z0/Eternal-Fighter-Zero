if ((self->field000a == 0) && (self->field000c == 0)) {
    self->ResetFrame();
}

if ((self->field000a == 4) && (self->field000c == 0)) {
    self->hitstunFrames = 0x78;
    self->meter = self->meter - 3000;
    self->SetTint(0xb0, 3);

    spawn.type = 0x46;
    spawn.x = (double)(int)self->positionX;
    spawn.y = (double)((int)self->positionY - 0x28);
    spawn.palette = 0x40;
    spawn.group = 2;
    spawn.layer = 1;
    spawn.owner = 1;
    self->contextOwner->EmitEffect(&spawn);

    spawn.type = 0x47;
    self->contextOwner->EmitEffect(&spawn);
    self->remainingHitCount = 99;
}

if ((self->field000a == 5) && (self->field000c == 0)) {
    spawn.type = 0x1b2;
    spawn.x = (double)(int)self->positionX;
    spawn.y = (double)(int)self->positionY;
    spawn.flag0018 = self->facing;
    spawn.group = 2;
    spawn.layer = 1;
    spawn.owner = 1;
    self->EmitLocalEffect(&spawn);
}

if ((self->field000a == 0x10) && (self->field000c == 0)) {
    spawn.type = 0x1b3;
    spawn.x = (double)(int)self->positionX;
    spawn.y = (double)(int)self->positionY;
    spawn.flag0018 = self->facing;
    spawn.group = 2;
    spawn.layer = 1;
    spawn.owner = 1;
    self->EmitLocalEffect(&spawn);
}

if (((self->field000a == 8) || (self->field000a == 0x12)) &&
    (self->attackCollisionResult == 3)) {
    (*self->opponentSlot)->hitstopFrames = 0x10e;
}

if ((self->field000a == 0x20) && (self->field000c == 0)) {
    spawn.type = 0x1b0;
    spawn.x = (double)(int)self->positionX;
    spawn.y = (double)(int)self->positionY;
    spawn.flag0018 = self->facing;
    spawn.group = 2;
    spawn.layer = 1;
    spawn.owner = 1;
    self->EmitLocalEffect(&spawn);
    (*self->opponentSlot)->koDelayFrames = 30000;
}

if ((self->field000a == 0x2c) && (self->field000c == 0)) {
    self->hitstunFrames = 0x23a;
    self->SetTint(0xb0, 3000);

    spawn.type = 9;
    spawn.x = (double)(int)self->positionX;
    spawn.y = (double)((int)self->positionY - 0x28);
    spawn.palette = 5;
    spawn.group = 2;
    spawn.layer = 1;
    spawn.owner = 1;
    self->contextOwner->EmitEffect(&spawn);

    self->remainingHitCount = 99;
    (*self->opponentSlot)->positionX = self->positionX;
    self->pendingCharacterSoundSlot = 10;
    self->contextOwner->state1420e = 30000;
}

if ((self->field000a == 0x33) && (self->field000c == 0)) {
    self->velocityY = -7.5;
    self->gravity = 0.035;

    spawn.type = 0x1b4;
    spawn.x = 0.0;
    spawn.y = 0.0;
    spawn.group = 2;
    spawn.layer = 0;
    spawn.owner = 1;
    spawn.payload = 1;
    spawn.flag0018 = 1;
    spawn.field0030 = 1;
    self->EmitLocalEffect(&spawn);

    spawn.type = 0x1b5;
    self->EmitLocalEffect(&spawn);

    spawn.type = 0x1b6;
    spawn.layer = 1;
    self->EmitLocalEffect(&spawn);
    self->pendingCharacterSoundSlot = 11;
}

if ((self->field000a == 0x35) && (self->attackCollisionResult == 3)) {
    self->field000c = 0;
    self->field000a = 0x36;
    (*self->opponentSlot)->hitstopFrames = 3000;
    self->velocityY = -0.05;
    self->gravity = 0.0;
    self->SetTint(0xb0, 3);
    self->pendingCharacterSoundSlot = 12;

    spawn.type = 0x1b7;
    spawn.x = self->positionX;
    spawn.y = self->positionY - 160.0;
    spawn.group = 2;
    spawn.layer = 1;
    spawn.owner = 1;
    spawn.flag0018 = 1;
    spawn.field0030 = 1;
    self->EmitLocalEffect(&spawn);
    (*self->opponentSlot)->contextOwner->state1420e = 0;
}

if ((self->field000a == 0x37) && (self->field000c == 0)) {
    self->velocityY = -7.0;
    self->gravity = 0.03;

    spawn.type = 0x1c0;
    spawn.x = self->positionX;
    spawn.y = self->positionY - 150.0;
    spawn.group = 2;
    spawn.layer = 1;
    spawn.owner = 1;
    spawn.flag0018 = 1;
    spawn.field0030 = 1;
    self->EmitLocalEffect(&spawn);

    spawn.x = self->positionX + 40.0;
    spawn.y = self->positionY - 140.0;
    self->EmitLocalEffect(&spawn);

    spawn.x = self->positionX - 50.0;
    spawn.y = self->positionY - 150.0;
    self->EmitLocalEffect(&spawn);

    spawn.type = 0x1b8;
    spawn.x = self->positionX;
    spawn.y = self->positionY - 150.0;
    self->EmitLocalEffect(&spawn);
}

if ((self->field000a == 0x37) && (self->attackCollisionResult == 3)) {
    (*self->opponentSlot)->koDelayFrames = 0;
}

if ((self->field000a != 0) && (self->field000a < 0x37)) {
    self->SetHorizontalShake(0x32, 3);
}

if ((self->field000a > 0x25) && (self->field000a < 0x37)) {
    self->SetHorizontalOffset(0x32, 3);
}

if (self->positionY < 0.0) {
    self->velocityY = self->velocityY + self->gravity;
}

if ((self->field000a == 0x35) && (self->velocityY > 1.0)) {
    self->velocityY = 1.0;
}

if ((self->field000a < 0x38) || (self->positionY + self->velocityY <= 0.0)) {
    ++self->field000c;
    if (self->field000c >= timing.frameDuration) {
        self->field000c = 0;
        ++self->field000a;

        if ((self->field000a < 0x12) || (self->field000a == 0x23) ||
            (self->field000a > 0x32)) {
            self->attackCollisionResult = 0;
        }

        if ((self->field000a == 0x0e) && (self->field3138 > 0)) {
            self->field000a = self->field000a - 2;
            self->field3138 = self->field3138 - 1;
        }

        if ((self->field000a == 0x1b) &&
            ((self->attackCollisionResult != 3) ||
             ((*self->opponentSlot)->health < 1))) {
            self->ResetPose();
            self->FaceOpponent();
            self->field0008 = 0;
        } else {
            if ((self->field000a == 0x24) && (self->attackCollisionResult != 3)) {
                self->ResetPose();
                self->field0008 = 0x136;
            }

            if (self->field000a == 0x2b) {
                spawn.type = 0x1b1;
                spawn.x = (double)(int)self->positionX;
                spawn.y = (double)(int)self->positionY;
                spawn.group = 2;
                spawn.layer = 1;
                spawn.owner = 1;
                spawn.flag0018 = self->facing;
                spawn.field0030 = 1;
                self->EmitLocalEffect(&spawn);
            }

            if (self->field000a == 0x35) {
                self->pendingCharacterSoundSlot = 9;
            }

            if (self->field000a == 0x36) {
                self->field000a = self->field000a - 1;
            }

            if (self->field000a >= timing.animationFrameCount) {
                self->field000a = self->field000a - 2;
            }
        }
    }
} else {
    self->ResetFrame();
    self->ResetPose();
    self->positionY = 0.0;
    self->field0008 = 0x0d;
}
