if ((field000a == 0) && (field000c == 0)) {
    ResetFrame();
}

if ((field000a == 4) && (field000c == 0)) {
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

    spawn.type = 0x47;
    contextOwner->EmitEffect(&spawn);
    remainingHitCount = 99;
}

if ((field000a == 5) && (field000c == 0)) {
    spawn.type = 0x1b2;
    spawn.x = (double)(int)positionX;
    spawn.y = (double)(int)positionY;
    spawn.flag0018 = facing;
    spawn.group = 2;
    spawn.layer = 1;
    spawn.owner = 1;
    EmitLocalEffect(&spawn);
}

if ((field000a == 0x10) && (field000c == 0)) {
    spawn.type = 0x1b3;
    spawn.x = (double)(int)positionX;
    spawn.y = (double)(int)positionY;
    spawn.flag0018 = facing;
    spawn.group = 2;
    spawn.layer = 1;
    spawn.owner = 1;
    EmitLocalEffect(&spawn);
}

if (((field000a == 8) || (field000a == 0x12)) &&
    (attackCollisionResult == 3)) {
    (*opponentSlot)->hitstopFrames = 0x10e;
}

if ((field000a == 0x20) && (field000c == 0)) {
    spawn.type = 0x1b0;
    spawn.x = (double)(int)positionX;
    spawn.y = (double)(int)positionY;
    spawn.flag0018 = facing;
    spawn.group = 2;
    spawn.layer = 1;
    spawn.owner = 1;
    EmitLocalEffect(&spawn);
    (*opponentSlot)->koDelayFrames = 30000;
}

if ((field000a == 0x2c) && (field000c == 0)) {
    hitstunFrames = 0x23a;
    SetTint(0xb0, 3000);

    spawn.type = 9;
    spawn.x = (double)(int)positionX;
    spawn.y = (double)((int)positionY - 0x28);
    spawn.palette = 5;
    spawn.group = 2;
    spawn.layer = 1;
    spawn.owner = 1;
    contextOwner->EmitEffect(&spawn);

    remainingHitCount = 99;
    (*opponentSlot)->positionX = positionX;
    pendingCharacterSoundSlot = 10;
    contextOwner->state1420e = 30000;
}

if ((field000a == 0x33) && (field000c == 0)) {
    velocityY = -7.5;
    gravity = 0.035;

    spawn.type = 0x1b4;
    spawn.x = 0.0;
    spawn.y = 0.0;
    spawn.group = 2;
    spawn.layer = 0;
    spawn.owner = 1;
    spawn.payload = 1;
    spawn.flag0018 = 1;
    spawn.field0030 = 1;
    EmitLocalEffect(&spawn);

    spawn.type = 0x1b5;
    EmitLocalEffect(&spawn);

    spawn.type = 0x1b6;
    spawn.layer = 1;
    EmitLocalEffect(&spawn);
    pendingCharacterSoundSlot = 11;
}

if ((field000a == 0x35) && (attackCollisionResult == 3)) {
    field000c = 0;
    field000a = 0x36;
    (*opponentSlot)->hitstopFrames = 3000;
    velocityY = -0.05;
    gravity = 0.0;
    SetTint(0xb0, 3);
    pendingCharacterSoundSlot = 12;

    spawn.type = 0x1b7;
    spawn.x = positionX;
    spawn.y = positionY - 160.0;
    spawn.group = 2;
    spawn.layer = 1;
    spawn.owner = 1;
    spawn.flag0018 = 1;
    spawn.field0030 = 1;
    EmitLocalEffect(&spawn);
    (*opponentSlot)->contextOwner->state1420e = 0;
}

if ((field000a == 0x37) && (field000c == 0)) {
    velocityY = -7.0;
    gravity = 0.03;

    spawn.type = 0x1c0;
    spawn.x = positionX;
    spawn.y = positionY - 150.0;
    spawn.group = 2;
    spawn.layer = 1;
    spawn.owner = 1;
    spawn.flag0018 = 1;
    spawn.field0030 = 1;
    EmitLocalEffect(&spawn);

    spawn.x = positionX + 40.0;
    spawn.y = positionY - 140.0;
    EmitLocalEffect(&spawn);

    spawn.x = positionX - 50.0;
    spawn.y = positionY - 150.0;
    EmitLocalEffect(&spawn);

    spawn.type = 0x1b8;
    spawn.x = positionX;
    spawn.y = positionY - 150.0;
    EmitLocalEffect(&spawn);
}

if ((field000a == 0x37) && (attackCollisionResult == 3)) {
    (*opponentSlot)->koDelayFrames = 0;
}

if ((field000a != 0) && (field000a < 0x37)) {
    SetHorizontalShake(0x32, 3);
}

if ((field000a > 0x25) && (field000a < 0x37)) {
    SetHorizontalOffset(0x32, 3);
}

if (positionY < 0.0) {
    velocityY = velocityY + gravity;
}

if ((field000a == 0x35) && (velocityY > 1.0)) {
    velocityY = 1.0;
}

if ((field000a < 0x38) || (positionY + velocityY <= 0.0)) {
    ++field000c;
    if (field000c >= timing.frameDuration) {
        field000c = 0;
        ++field000a;

        if ((field000a < 0x12) || (field000a == 0x23) ||
            (field000a > 0x32)) {
            attackCollisionResult = 0;
        }

        if ((field000a == 0x0e) && (field3138 > 0)) {
            field000a = field000a - 2;
            field3138 = field3138 - 1;
        }

        if ((field000a == 0x1b) &&
            ((attackCollisionResult != 3) ||
             ((*opponentSlot)->health < 1))) {
            ResetPose();
            FaceOpponent();
            field0008 = 0;
        } else {
            if ((field000a == 0x24) && (attackCollisionResult != 3)) {
                ResetPose();
                field0008 = 0x136;
            }

            if (field000a == 0x2b) {
                spawn.type = 0x1b1;
                spawn.x = (double)(int)positionX;
                spawn.y = (double)(int)positionY;
                spawn.group = 2;
                spawn.layer = 1;
                spawn.owner = 1;
                spawn.flag0018 = facing;
                spawn.field0030 = 1;
                EmitLocalEffect(&spawn);
            }

            if (field000a == 0x35) {
                pendingCharacterSoundSlot = 9;
            }

            if (field000a == 0x36) {
                field000a = field000a - 1;
            }

            if (field000a >= timing.animationFrameCount) {
                field000a = field000a - 2;
            }
        }
    }
} else {
    ResetFrame();
    ResetPose();
    positionY = 0.0;
    field0008 = 0x0d;
}
