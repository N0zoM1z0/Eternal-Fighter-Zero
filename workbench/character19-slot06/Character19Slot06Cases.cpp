// Workbench reconstruction of Character19::Slot06 switch case 0x73.
// This is an isolated natural-C++ state handler, not yet wired into Slot06.
#include "CharacterViews.h"

void Character19::Slot06Case73()
{
    unsigned short frameDuration;
    unsigned short frameCount;
    EffectSpawn spawn;

    frameDuration = patterns[field0008].frames[field000a].duration;
    frameCount = patterns[field0008].count;
    ResetLocalEffectSpawn(&spawn);

    if ((field000a == 0) && (field000c == 0)) {
        velocityX = 0.0;
        velocityY = 0.0;
        horizontalDeceleration = 0.0;
        gravity = 0.0;
        outgoingPushbackVelocityX = 0.0;
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
        field000c = field000c + 1;
        if (frameDuration <= field000c) {
            field000c = 0;
            field000a = field000a + 1;

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

                if (frameCount <= field000a) {
                    field000a = field000a - 2;
                }
            }
        }
    } else {
        velocityX = 0.0;
        velocityY = 0.0;
        horizontalDeceleration = 0.0;
        gravity = 0.0;
        outgoingPushbackVelocityX = 0.0;
        ResetPose();
        positionY = 0.0;
        field0008 = 0x0d;
    }
}

void Character19::Slot06Case72()
{
    unsigned short frameDuration;
    unsigned short frameCount;
    EffectSpawn spawn;

    frameDuration = patterns[field0008].frames[field000a].duration;
    frameCount = patterns[field0008].count;
    ResetLocalEffectSpawn(&spawn);

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
    if (frameDuration <= field000c) {
        field000c = 0;
        field000a = field000a + 1;
        attackCollisionResult = 0;
        if (frameCount <= field000a) {
            field0008 = 9;
            FaceOpponent();
            ResetPose();
        }
    }
}

void Character19::Slot06Case74()
{
    unsigned short frameDuration;
    unsigned short frameCount;

    frameDuration = patterns[field0008].frames[field000a].duration;
    frameCount = patterns[field0008].count;

    if ((field000a == 0) && (field000c == 0)) {
        velocityX = 0.0;
        velocityY = 0.0;
        gravity = 0.0;
    }

    field000c = field000c + 1;
    if (frameDuration <= field000c) {
        field000c = 0;
        field000a = field000a + 1;
        attackCollisionResult = 0;
        if (frameCount <= field000a) {
            field0008 = 0;
            FaceOpponent();
            ResetPose();
        }
    }
}

void Character19::Slot06Case71()
{
    unsigned short frameDuration;
    unsigned short frameCount;
    EffectSpawn spawn;

    frameDuration = patterns[field0008].frames[field000a].duration;
    frameCount = patterns[field0008].count;
    ResetLocalEffectSpawn(&spawn);

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
    if (frameDuration <= field000c) {
        field000c = 0;
        field000a = field000a + 1;
        attackCollisionResult = 0;

        if ((field3138 < 0x0d) && (field000a == 0x11)) {
            field000a = field000a - 3;
            field3138 = field3138 + 1;
        } else if (frameCount <= field000a) {
            FaceOpponent();
            ResetPose();
            field0008 = 0;
        }
    }
}

void Character19::Slot06Case70()
{
    unsigned short frameDuration;
    unsigned short frameCount;
    unsigned short randomValue;
    EffectSpawn spawn;

    frameDuration = patterns[field0008].frames[field000a].duration;
    frameCount = patterns[field0008].count;
    ResetLocalEffectSpawn(&spawn);

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
    if (frameDuration <= field000c) {
        field000c = 0;
        field000a = field000a + 1;
        attackCollisionResult = 0;

        if ((field3138 < 0x0d) && (field000a == 0x11)) {
            field000a = field000a - 3;
            field3138 = field3138 + 1;
        } else if (frameCount <= field000a) {
            FaceOpponent();
            ResetPose();
            field0008 = 0;
            if (positionY < 0.0) {
                field0008 = 9;
                gravity = 0.035;
            }
        }
    }
}


void Character19::Slot06Case03()
{
    struct FrameTiming {
        __declspec(align(4)) unsigned short animationFrameCount;
        __declspec(align(4)) unsigned short frameDuration;
    } timing;

    timing.frameDuration = patterns[field0008].frames[field000a].duration;
    timing.animationFrameCount = patterns[field0008].count;

    if ((field000a == 0) && (field000c == 0)) {
        FaceOpponent();
        velocityX = 0.0;
    }

    field3140 = field3140 + 1;
    if (field3148 < field3140) {
        if ((inputY == -1) && (airActionCount < 2)) {
            airActionCount = airActionCount + 1;
            field0008 = 0x0e;
            if (inputX == facing) {
                field0008 = 0x0f;
            }
            if (inputX == -facing) {
                field0008 = 0x10;
            }
            attackCollisionResult = 0;
            ResetPose();
            return;
        }

        if (inputY == 1) {
            field0008 = 9;
            if ((airActionCount < 2) && (inputX != 0) &&
                (field015c < 3)) {
                airActionCount = airActionCount + 1;
                if (inputX == facing) {
                    field0008 = 0x12;
                }
                if (inputX == -facing) {
                    field0008 = 0x14;
                }
                attackCollisionResult = 0;
                ResetPose();
                return;
            }
            ResetPose();
            return;
        }

        if ((airActionCount < 2) && (field015c < 3)) {
            if (inputX == facing) {
                field0008 = 0x11;
                airActionCount = airActionCount + 1;
                ResetPose();
                attackCollisionResult = 0;
                return;
            }
            if (inputX == -facing) {
                field0008 = 0x13;
                airActionCount = airActionCount + 1;
                ResetPose();
                attackCollisionResult = 0;
                return;
            }
        }
    }

    if ((field000a == 3) && (field000c == 0)) {
        gravity = 0.045;
        velocityY = -2.5;
        pendingCharacterSoundSlot = 0;
    }

    if (field000a > 4) {
        velocityY = velocityY + gravity;
    }

    field000c = field000c + 1;
    if (timing.frameDuration <= field000c) {
        field000c = 0;
        field000a = field000a + 1;
        if (timing.animationFrameCount <= field000a) {
            field0008 = 0x0a;
            ResetPose();
        }
    }

    if ((positionY + velocityY >= 0.0) && (field000a > 3)) {
        positionY = 0.0;
        pendingContextSoundSlot = 9;
        FaceOpponent();
        field0008 = 0x0d;
        ResetPose();
    }
}

void Character19::Slot06Case04()
{
    struct FrameTiming {
        __declspec(align(4)) unsigned short animationFrameCount;
        __declspec(align(4)) unsigned short frameDuration;
    } timing;

    timing.frameDuration = patterns[field0008].frames[field000a].duration;
    timing.animationFrameCount = patterns[field0008].count;

    if ((field000a == 0) && (field000c == 0)) {
        FaceOpponent();
        velocityX = 0.0;
    }

    field3140 = field3140 + 1;
    if (field3148 < field3140) {
        if ((inputY == -1) && (airActionCount < 2)) {
            airActionCount = airActionCount + 1;
            field0008 = 0x0e;
            if (inputX == facing) {
                field0008 = 0x0f;
            }
            if (inputX == -facing) {
                field0008 = 0x10;
            }
            attackCollisionResult = 0;
            ResetPose();
            return;
        }

        if (inputY == 1) {
            field0008 = 9;
            ResetPose();
            if (airActionCount > 1) {
                return;
            }
            if (inputX == 0) {
                return;
            }
            if (field015c > 2) {
                return;
            }
            airActionCount = airActionCount + 1;
            if (inputX == facing) {
                field0008 = 0x12;
            }
            if (inputX == -facing) {
                field0008 = 0x14;
            }
            attackCollisionResult = 0;
            ResetPose();
            return;
        }

        if ((airActionCount < 2) && (field015c < 3)) {
            if (inputX == facing) {
                field0008 = 0x11;
                airActionCount = airActionCount + 1;
                ResetPose();
                attackCollisionResult = 0;
                return;
            }
            if (inputX == -facing) {
                field0008 = 0x13;
                airActionCount = airActionCount + 1;
                ResetPose();
                attackCollisionResult = 0;
                return;
            }
        }
    }

    if ((field000a == 3) && (field000c == 0)) {
        gravity = 0.045;
        velocityY = -2.5;
        velocityX = 1.5;
        pendingCharacterSoundSlot = 0;
    }

    if (field000a > 6) {
        velocityY = velocityY + gravity;
    }

    field000c = field000c + 1;
    if (timing.frameDuration <= field000c) {
        field000c = 0;
        field000a = field000a + 1;
        if (timing.animationFrameCount <= field000a) {
            field0008 = 0x0a;
            ResetPose();
        }
    }

    if ((positionY + velocityY >= 0.0) && (field000a > 3)) {
        positionY = 0.0;
        pendingContextSoundSlot = 9;
        FaceOpponent();
        field0008 = 0x0d;
        ResetPose();
    }
}
