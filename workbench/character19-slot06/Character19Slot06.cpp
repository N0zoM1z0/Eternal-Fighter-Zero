// Natural-C++ reconstruction of Character19::Slot06.
// State IDs are grouped using the native 310-byte selector table.
// All 310 native state IDs map through 118 selector cases; 193 use shared 0x75.
// The 0x70-0x74 super/KO handlers share the native dispatcher frame.
#include "CharacterViews.h"

static const unsigned char Character19Slot06SelectorCases[0x136] = {
    0x00, 0x01, 0x02, 0x03, 0x04, 0x05, 0x06, 0x07, 0x08, 0x09, 0x75, 0x75, 0x0a, 0x0b, 0x0c, 0x0d,
    0x0e, 0x0f, 0x10, 0x11, 0x75, 0x75, 0x75, 0x75, 0x75, 0x75, 0x75, 0x75, 0x75, 0x75, 0x75, 0x75,
    0x75, 0x75, 0x75, 0x75, 0x75, 0x75, 0x75, 0x75, 0x75, 0x75, 0x75, 0x75, 0x75, 0x75, 0x12, 0x75,
    0x75, 0x13, 0x14, 0x15, 0x16, 0x17, 0x18, 0x19, 0x1a, 0x1b, 0x1c, 0x1d, 0x1e, 0x1f, 0x20, 0x21,
    0x22, 0x23, 0x24, 0x25, 0x26, 0x27, 0x28, 0x29, 0x2a, 0x2b, 0x2c, 0x2d, 0x2e, 0x75, 0x75, 0x75,
    0x2f, 0x30, 0x31, 0x32, 0x33, 0x34, 0x35, 0x75, 0x75, 0x75, 0x75, 0x75, 0x75, 0x75, 0x75, 0x36,
    0x37, 0x38, 0x39, 0x75, 0x75, 0x75, 0x75, 0x75, 0x75, 0x75, 0x75, 0x75, 0x75, 0x75, 0x75, 0x75,
    0x75, 0x75, 0x75, 0x75, 0x75, 0x75, 0x75, 0x75, 0x75, 0x75, 0x75, 0x75, 0x75, 0x75, 0x75, 0x75,
    0x75, 0x75, 0x75, 0x75, 0x75, 0x75, 0x75, 0x75, 0x75, 0x75, 0x75, 0x75, 0x75, 0x75, 0x75, 0x75,
    0x75, 0x75, 0x75, 0x75, 0x75, 0x3a, 0x3b, 0x3c, 0x3d, 0x3e, 0x3f, 0x40, 0x41, 0x42, 0x75, 0x75,
    0x75, 0x75, 0x43, 0x44, 0x45, 0x46, 0x47, 0x48, 0x49, 0x4a, 0x4b, 0x75, 0x75, 0x75, 0x75, 0x75,
    0x75, 0x4c, 0x75, 0x75, 0x75, 0x75, 0x75, 0x75, 0x75, 0x75, 0x75, 0x75, 0x75, 0x75, 0x75, 0x75,
    0x75, 0x75, 0x75, 0x75, 0x75, 0x75, 0x75, 0x4d, 0x4e, 0x4f, 0x50, 0x51, 0x52, 0x53, 0x54, 0x55,
    0x56, 0x57, 0x58, 0x59, 0x5a, 0x5b, 0x75, 0x75, 0x75, 0x75, 0x75, 0x5c, 0x5d, 0x75, 0x75, 0x75,
    0x75, 0x75, 0x75, 0x75, 0x75, 0x5e, 0x5f, 0x60, 0x61, 0x62, 0x63, 0x75, 0x75, 0x75, 0x75, 0x75,
    0x75, 0x75, 0x75, 0x75, 0x75, 0x75, 0x75, 0x75, 0x64, 0x65, 0x66, 0x75, 0x67, 0x75, 0x75, 0x68,
    0x69, 0x75, 0x6a, 0x75, 0x75, 0x75, 0x6b, 0x6c, 0x6d, 0x6e, 0x6f, 0x75, 0x75, 0x75, 0x75, 0x75,
    0x75, 0x75, 0x75, 0x75, 0x75, 0x75, 0x75, 0x75, 0x75, 0x75, 0x75, 0x75, 0x75, 0x75, 0x75, 0x75,
    0x75, 0x75, 0x75, 0x75, 0x75, 0x75, 0x75, 0x75, 0x75, 0x75, 0x75, 0x70, 0x75, 0x75, 0x71, 0x75,
    0x75, 0x72, 0x75, 0x75, 0x73, 0x74,
};

void Character19::Slot06()
{
    Character19 *self = this;
    if (self->hitstopFrames > 0) {
        return;
    }
    if ((*self->opponentSlot)->hitstunFrames > 0) {
        return;
    }

    EffectSpawn spawn;
    unsigned int stateIndex;
    unsigned char selectorCase;
    struct FrameTiming {
        __declspec(align(4)) unsigned short animationFrameCount;
        __declspec(align(4)) unsigned short frameDuration;
    } timing;

    timing.frameDuration = self->patterns[self->field0008].frames[self->field000a].duration;
    timing.animationFrameCount = self->patterns[self->field0008].count;
    self->ResetLocalEffectSpawn(&spawn);
    selectorCase = 0x75;
    stateIndex = self->field0008;
    if (stateIndex != 0) {
        --stateIndex;
        if (stateIndex <= 0x135) {
            selectorCase = Character19Slot06SelectorCases[stateIndex];
        }
    }

    switch (selectorCase) {
    case 0:
        self->dashMomentumFlag = 0;
        self->velocityX = 0.8;
        self->velocityY = 0.0;
        ++self->field000c;
        if (self->field000c >= timing.frameDuration) {
            self->field000c = 0;
            ++self->field000a;
            if (self->field000a >= timing.animationFrameCount) {
                self->field000a = 0;
            }
        }
        break;
    case 1:
        self->dashMomentumFlag = 0;
        self->velocityX = -0.8;
        self->velocityY = 0.0;
        ++self->field000c;
        if (self->field000c >= timing.frameDuration) {
            self->field000c = 0;
            ++self->field000a;
            if (self->field000a >= timing.animationFrameCount) {
                self->field000a = 0;
            }
        }
        break;
    case 2:
        self->velocityX = 0.0;
        self->velocityY = 0.0;
        self->dashMomentumFlag = 0;
        self->FaceOpponent();
        ++self->field000c;
        if (self->field000c >= timing.frameDuration) {
            self->field000c = 0;
            ++self->field000a;
            if (self->field000a >= timing.animationFrameCount) {
                self->field000a = 0;
            }
        }
        break;
    case 6:
        self->velocityX = 0.0;
        self->velocityY = 0.0;
        self->dashMomentumFlag = 0;
        self->FaceOpponent();
        self->field000c = self->field000c + 1;
        if (timing.frameDuration <= self->field000c) {
            self->field000c = 0;
            self->field000a = self->field000a + 1;
            if (timing.animationFrameCount <= self->field000a) {
                self->field000a = 0;
                self->field0008 = 0;
                self->ResetPose();
            }
        }
        break;

    case 7:
        self->velocityX = 0.0;
        self->velocityY = 0.0;
        self->dashMomentumFlag = 0;
        self->FaceOpponent();
        self->field000c = self->field000c + 1;
        if (timing.frameDuration <= self->field000c) {
            self->field000c = 0;
            self->field000a = self->field000a + 1;
            if (timing.animationFrameCount <= self->field000a) {
                self->field000a = 0;
                self->field0008 = 3;
                self->ResetPose();
            }
        }
        break;

    case 10:
        self->velocityX = 0.0;
        self->velocityY = 0.0;
        self->dashMomentumFlag = 0;
        self->FaceOpponent();
        self->field000c = self->field000c + 1;
        if (timing.frameDuration <= self->field000c) {
            self->field000c = 0;
            self->field000a = self->field000a + 1;
            if (timing.animationFrameCount <= self->field000a) {
                self->field000a = 0;
                self->field0008 = 7;
                if (self->inputY == 1) {
                    self->field0008 = 3;
                }
                self->ResetPose();
            }
        }
        break;

    case 11:
        {
#include "Character19Slot06Case0B.inc"
        }
        break;

    case 12:
        {
#include "Character19Slot06Case0C.inc"
        }
        break;

    case 13:
        {
#include "Character19Slot06Case0D.inc"
        }
        break;

    case 14:
        {
#include "Character19Slot06Case0E.inc"
        }
        break;

    case 15:
        {
#include "Character19Slot06Case0F.inc"
        }
        break;

    case 16:
        {
#include "Character19Slot06Case10.inc"
        }
        break;

    case 17:
        {
#include "Character19Slot06Case11.inc"
        }
        break;

    case 18:
        if ((self->field000a == 0) && (self->field000c == 0)) {
            self->velocityX = 0.0;
            self->gravity = 0.035;
        }
        self->velocityY = self->velocityY + self->gravity;
        if (((self->positionY + self->velocityY) > 0.0) && (self->field000a < 2)) {
            self->field000c = 0;
            self->field000a = 2;
            reinterpret_cast<unsigned char *>(&self->soundSlots[49])[1] = 7;
            self->positionY = 0.0;
            self->velocityY = 0.0;
            self->gravity = 0.0;
            self->velocityX = 0.0;
        }
        self->field000c = self->field000c + 1;
        if (timing.frameDuration <= self->field000c) {
            self->field000c = 0;
            self->field000a = self->field000a + 1;
            if (self->field000a == 2) {
                self->field000a = self->field000a - 2;
            }
            if (timing.animationFrameCount <= self->field000a) {
                self->field000a = self->field000a - 1;
            }
        }
        break;

    case 37:
        self->Slot06UpdateKnockbackLanding(
            timing.frameDuration, timing.animationFrameCount,
            1);
        break;

    case 38:
        self->Slot06UpdateKnockbackLanding(
            timing.frameDuration, timing.animationFrameCount,
            0);
        break;

    case 41:
        self->Slot06UpdateGroundRecovery(
            timing.frameDuration, timing.animationFrameCount,
            0);
        break;

    case 42:
        self->Slot06UpdateGroundRecovery(
            timing.frameDuration, timing.animationFrameCount,
            0);
        break;

    case 43:
        self->Slot06UpdateGroundRecovery(
            timing.frameDuration, timing.animationFrameCount,
            1);
        break;

    case 44:
        {
#include "Character19Slot06Case2C.inc"
        }
        break;

    case 45:
        {
#include "Character19Slot06Case2D.inc"
        }
        break;

    case 46:
        {
#include "Character19Slot06Case2E.inc"
        }
        break;

    case 47:
        {
#include "Character19Slot06Case2F.inc"
        }
        break;

    case 48:
        {
#include "Character19Slot06Case30.inc"
        }
        break;

    case 49:
        {
#include "Character19Slot06Case31.inc"
        }
        break;

    case 50:
        {
#include "Character19Slot06Case32.inc"
        }
        break;

    case 51:
        {
#include "Character19Slot06Case33.inc"
        }
        break;

    case 52:
        {
#include "Character19Slot06Case34.inc"
        }
        break;

    case 53:
        self->Slot06UpdateLocalEffectRecovery(
            timing.frameDuration, timing.animationFrameCount, &spawn);
        break;

    case 54:
        self->Slot06UpdateFaceRecovery(
            timing.frameDuration, timing.animationFrameCount);
        break;

    case 55:
        self->Slot06UpdateDefeatImpact(
            timing.frameDuration, timing.animationFrameCount, &spawn);
        break;

    case 56:
        self->Slot06UpdateDefeatImpact(
            timing.frameDuration, timing.animationFrameCount, &spawn);
        break;

    case 57:
        self->Slot06UpdateDefeatWait(
            timing.frameDuration, timing.animationFrameCount);
        break;

    case 58:
        if ((self->field000a == 0) && (self->field000c == 0)) {
            self->dashMomentumFlag = 0;
            self->meter = self->meter + 10;
            self->velocityX = -1.5;
            self->velocityY = 0.0;
            self->positionY = 0.0;
        }
        self->velocityY = 0.0;
        self->velocityX = self->velocityX + 0.06;
        if (self->velocityX > 0.0) {
            self->velocityX = 0.0;
        }
        if ((self->positionX - 20.0 <= 0.0) || (639.0 <= self->positionX + 20.0)) {
            self->outgoingPushbackVelocityX = self->velocityX;
        } else {
            self->outgoingPushbackVelocityX = 0.0;
        }
        ++self->field000c;
        if (self->field000c >= timing.frameDuration) {
            self->field000c = 0;
            ++self->field000a;
            if (self->field000a == timing.animationFrameCount) {
                self->FaceOpponent();
            }
            if (self->field000a >= timing.animationFrameCount) {
                self->field0008 = 0;
                if (self->inputY == 1) {
                    self->field0008 = 3;
                }
                self->ResetPose();
            }
        }
        break;

    case 59:
        if ((self->field000a == 0) && (self->field000c == 0)) {
            self->dashMomentumFlag = 0;
            self->meter = self->meter + 15;
            self->velocityX = -1.8;
            self->velocityY = 0.0;
            self->positionY = 0.0;
        }
        self->velocityY = 0.0;
        self->velocityX = self->velocityX + 0.06;
        if (self->velocityX > 0.0) {
            self->velocityX = 0.0;
        }
        if ((self->positionX - 20.0 <= 0.0) || (639.0 <= self->positionX + 20.0)) {
            self->outgoingPushbackVelocityX = self->velocityX;
        } else {
            self->outgoingPushbackVelocityX = 0.0;
        }
        ++self->field000c;
        if (self->field000c >= timing.frameDuration) {
            self->field000c = 0;
            ++self->field000a;
            if (self->field000a == timing.animationFrameCount) {
                self->FaceOpponent();
            }
            if (self->field000a >= timing.animationFrameCount) {
                self->field0008 = 0;
                if (self->inputY == 1) {
                    self->field0008 = 3;
                }
                self->ResetPose();
            }
        }
        break;

    case 60:
        if ((self->field000a == 0) && (self->field000c == 0)) {
            self->dashMomentumFlag = 0;
            self->meter = self->meter + 20;
            self->velocityX = -2.3;
            self->velocityY = 0.0;
            self->positionY = 0.0;
        }
        self->velocityY = 0.0;
        self->velocityX = self->velocityX + 0.06;
        if (self->velocityX > 0.0) {
            self->velocityX = 0.0;
        }
        if ((self->positionX - 20.0 <= 0.0) || (639.0 <= self->positionX + 20.0)) {
            self->outgoingPushbackVelocityX = self->velocityX;
        } else {
            self->outgoingPushbackVelocityX = 0.0;
        }
        ++self->field000c;
        if (self->field000c >= timing.frameDuration) {
            self->field000c = 0;
            ++self->field000a;
            if (self->field000a == timing.animationFrameCount) {
                self->FaceOpponent();
            }
            if (self->field000a >= timing.animationFrameCount) {
                self->field0008 = 0;
                if (self->inputY == 1) {
                    self->field0008 = 3;
                }
                self->ResetPose();
            }
        }
        break;

    case 61:
        if ((self->field000a == 0) && (self->field000c == 0)) {
            self->dashMomentumFlag = 0;
            self->meter = self->meter + 10;
            self->velocityX = -1.5;
            self->velocityY = 0.0;
            self->positionY = 0.0;
        }
        self->velocityY = 0.0;
        self->velocityX = self->velocityX + 0.06;
        if (self->velocityX > 0.0) {
            self->velocityX = 0.0;
        }
        if ((self->positionX - 20.0 <= 0.0) || (639.0 <= self->positionX + 20.0)) {
            self->outgoingPushbackVelocityX = self->velocityX;
        } else {
            self->outgoingPushbackVelocityX = 0.0;
        }
        ++self->field000c;
        if (self->field000c >= timing.frameDuration) {
            self->field000c = 0;
            ++self->field000a;
            if (self->field000a == timing.animationFrameCount) {
                self->FaceOpponent();
            }
            if (self->field000a >= timing.animationFrameCount) {
                self->field0008 = 3;
                self->ResetPose();
            }
        }
        break;

    case 62:
        if ((self->field000a == 0) && (self->field000c == 0)) {
            self->dashMomentumFlag = 0;
            self->meter = self->meter + 15;
            self->velocityX = -1.8;
            self->velocityY = 0.0;
            self->positionY = 0.0;
        }
        self->velocityY = 0.0;
        self->velocityX = self->velocityX + 0.06;
        if (self->velocityX > 0.0) {
            self->velocityX = 0.0;
        }
        if ((self->positionX - 20.0 <= 0.0) || (639.0 <= self->positionX + 20.0)) {
            self->outgoingPushbackVelocityX = self->velocityX;
        } else {
            self->outgoingPushbackVelocityX = 0.0;
        }
        ++self->field000c;
        if (self->field000c >= timing.frameDuration) {
            self->field000c = 0;
            ++self->field000a;
            if (self->field000a == timing.animationFrameCount) {
                self->FaceOpponent();
            }
            if (self->field000a >= timing.animationFrameCount) {
                self->field0008 = 3;
                self->ResetPose();
            }
        }
        break;

    case 63:
        if ((self->field000a == 0) && (self->field000c == 0)) {
            self->dashMomentumFlag = 0;
            self->meter = self->meter + 20;
            self->velocityX = -2.3;
            self->velocityY = 0.0;
            self->positionY = 0.0;
        }
        self->velocityY = 0.0;
        self->velocityX = self->velocityX + 0.06;
        if (self->velocityX > 0.0) {
            self->velocityX = 0.0;
        }
        if ((self->positionX - 20.0 <= 0.0) || (639.0 <= self->positionX + 20.0)) {
            self->outgoingPushbackVelocityX = self->velocityX;
        } else {
            self->outgoingPushbackVelocityX = 0.0;
        }
        ++self->field000c;
        if (self->field000c >= timing.frameDuration) {
            self->field000c = 0;
            ++self->field000a;
            if (self->field000a == timing.animationFrameCount) {
                self->FaceOpponent();
            }
            if (self->field000a >= timing.animationFrameCount) {
                self->field0008 = 3;
                self->ResetPose();
            }
        }
        break;

    case 39:
        if (self->field0120 != 0) {
            self->field0118 = self->field0118 - 0.8;
        }
        if ((self->field000a == 0) && (self->field000c == 0) && (self->field3138 == 0)) {
            self->meter = self->meter + 30;
            self->field3138 = self->field3138 + 1;
            self->airActionLockFrames = self->airActionLockFrames + 0x78;
            self->velocityX = 0.5;
            self->velocityY = -2.5;
            self->gravity = 0.025;
            self->pendingContextSoundSlot = 0x1f;
            spawn.type = 0;
            spawn.x = (double)(int)self->positionX;
            spawn.y = (double)(int)self->positionY;
            spawn.group = 2;
            spawn.layer = 1;
            self->contextOwner->EmitEffect(&spawn);
        }
        self->velocityY = self->velocityY + self->gravity;
        self->field000c = self->field000c + 1;
        if (timing.frameDuration <= self->field000c) {
            self->field000c = 0;
            self->field000a = self->field000a + 1;
            if (timing.animationFrameCount <= self->field000a) {
                self->field000a = 0;
            }
        }
        if (((self->positionY + self->velocityY) >= 0.0) && (self->field000a > 1)) {
            self->positionY = 0.0;
            if (self->knockdownOnLanding == 0) {
                self->field0008 = 0x62;
            } else {
                self->field0008 = 0x61;
            }
            self->ResetPose();
        }
        break;

    case 64:
        self->Slot06UpdateAirborneKnockdown(
            timing.frameDuration, timing.animationFrameCount, &spawn,
            -1.2, -2.6, 0.06,
            15, 0, 0, 0, 0);
        break;

    case 65:
        self->Slot06UpdateAirborneKnockdown(
            timing.frameDuration, timing.animationFrameCount, &spawn,
            1.0, -2.3, 0.045,
            0, 8, 1, 1, 1);
        break;

    case 66:
        self->Slot06UpdateAirborneKnockdown(
            timing.frameDuration, timing.animationFrameCount, &spawn,
            -1.0, -2.3, 0.045,
            0, 8, 1, 1, 1);
        break;

    case 67:
        {
#include "Character19Slot06Case43.inc"
        }
        break;

    case 68:
        {
#include "Character19Slot06Case44.inc"
        }
        break;

    case 69:
        {
#include "Character19Slot06Case45.inc"
        }
        break;

    case 70:
        {
#include "Character19Slot06Case46.inc"
        }
        break;

    case 71:
        {
#include "Character19Slot06Case47.inc"
        }
        break;

    case 72:
        self->Slot06UpdateKnockbackImpactFinish(
            timing.frameDuration, timing.animationFrameCount, &spawn,
            0);
        break;

    case 73:
        self->Slot06UpdateKnockbackImpactFinish(
            timing.frameDuration, timing.animationFrameCount, &spawn,
            3);
        break;

    case 74:
        self->Slot06UpdateAirborneHitstunRestore(
            timing.frameDuration, timing.animationFrameCount);
        break;

    case 75:
        {
#include "Character19Slot06Case4B.inc"
        }
        break;

    case 76:
        self->Slot06UpdateDashRecovery(
            timing.frameDuration, timing.animationFrameCount);
        break;

    case 77:
        {
#include "Character19Slot06Case4D.inc"
        }
        break;

    case 78:
        {
#include "Character19Slot06Case4E.inc"
        }
        break;

    case 79:
        {
#include "Character19Slot06Case4F.inc"
        }
        break;

    case 80:
        {
#include "Character19Slot06Case50.inc"
        }
        break;

    case 81:
        {
#include "Character19Slot06Case51.inc"
        }
        break;

    case 82:
        {
#include "Character19Slot06Case52.inc"
        }
        break;

    case 83:
        {
#include "Character19Slot06Case53.inc"
        }
        break;

    case 84:
        {
#include "Character19Slot06Case54.inc"
        }
        break;

    case 85:
        {
#include "Character19Slot06Case55.inc"
        }
        break;

    case 86:
        {
#include "Character19Slot06Case56.inc"
        }
        break;

    case 87:
        self->Slot06UpdateAerialLaunchLanding(
            timing.frameDuration, timing.animationFrameCount);
        break;

    case 88:
        self->Slot06UpdateDashFollowupCancel(
            timing.frameDuration, timing.animationFrameCount);
        break;

    case 89:
        {
#include "Character19Slot06Case59.inc"
        }
        break;

    case 90:
        self->Slot06UpdateAerialKickback(
            timing.frameDuration, timing.animationFrameCount);
        break;

    case 91:
        self->Slot06UpdateGroundImpactRecovery(
            timing.frameDuration, timing.animationFrameCount, &spawn);
        break;

    case 92:
        {
#include "Character19Slot06Case5C.inc"
        }
        break;

    case 93:
        {
#include "Character19Slot06Case5D.inc"
        }
        break;

    case 94:
        {
#include "Character19Slot06Case5E.inc"
        }
        break;

    case 95:
        {
#include "Character19Slot06Case5F.inc"
        }
        break;

    case 97:
        {
#include "Character19Slot06Case61.inc"
        }
        break;

    case 98:
        {
#include "Character19Slot06Case62.inc"
        }
        break;

    case 96:
        self->Slot06UpdateDashTrailCharge(
            timing.frameDuration, timing.animationFrameCount);
        break;

    case 99:
        self->Slot06UpdateAirborneTrailDash(
            timing.frameDuration, timing.animationFrameCount);
        break;

    case 100:
        self->Slot06UpdateStunEffectRecovery(
            timing.frameDuration, timing.animationFrameCount, &spawn);
        break;

    case 101:
        {
#include "Character19Slot06Case65.inc"
        }
        break;

    case 102:
        {
#include "Character19Slot06Case66.inc"
        }
        break;

    case 103:
        self->Slot06UpdateDampedImpactFinish(
            timing.frameDuration, timing.animationFrameCount, &spawn);
        break;

    case 104:
        self->Slot06UpdateLoopingAerialBounce(
            timing.frameDuration, timing.animationFrameCount, &spawn);
        break;

    case 105:
        {
#include "Character19Slot06Case69.inc"
        }
        break;

    case 106:
        self->Slot06UpdateFinalFaceTransition(
            timing.frameDuration, timing.animationFrameCount);
        break;

    case 107:
        self->Slot06UpdateLocalEffectFinish(
            timing.frameDuration, timing.animationFrameCount, 400);
        break;

    case 108:
        self->Slot06UpdateLocalEffectFinish(
            timing.frameDuration, timing.animationFrameCount, 401);
        break;

    case 109:
        self->Slot06UpdateLocalEffectFinish(
            timing.frameDuration, timing.animationFrameCount, 402);
        break;

    case 110:
        {
#include "Character19Slot06Case6E.inc"
        }
        break;

    case 111:
        {
#include "Character19Slot06Case6F.inc"
        }
        break;

    case 28:
        {
#include "Character19Slot06Case1C.inc"
        }
        break;

    case 29:
        {
#include "Character19Slot06Case1D.inc"
        }
        break;

    case 30:
        {
#include "Character19Slot06Case1E.inc"
        }
        break;

    case 31:
        {
#include "Character19Slot06Case1F.inc"
        }
        break;

    case 32:
        {
#include "Character19Slot06Case20.inc"
        }
        break;

    case 33:
        {
#include "Character19Slot06Case21.inc"
        }
        break;

    case 34:
        {
#include "Character19Slot06Case22.inc"
        }
        break;

    case 35:
        {
#include "Character19Slot06Case23.inc"
        }
        break;

    case 36:
        {
#include "Character19Slot06Case24.inc"
        }
        break;

    case 40:
        {
#include "Character19Slot06Case28.inc"
        }
        break;

    case 19:
        {
#include "Character19Slot06Case13.inc"
        }
        break;

    case 20:
        {
#include "Character19Slot06Case14.inc"
        }
        break;

    case 21:
        {
#include "Character19Slot06Case15.inc"
        }
        break;

    case 22:
        {
#include "Character19Slot06Case16.inc"
        }
        break;

    case 23:
        {
#include "Character19Slot06Case17.inc"
        }
        break;

    case 24:
        {
#include "Character19Slot06Case18.inc"
        }
        break;

    case 25:
        {
#include "Character19Slot06Case19.inc"
        }
        break;

    case 26:
        {
#include "Character19Slot06Case1A.inc"
        }
        break;

    case 27:
        {
#include "Character19Slot06Case1B.inc"
        }
        break;

    case 3:
        {
#include "Character19Slot06Case03.inc"
        }
        break;

    case 4:
        {
#include "Character19Slot06Case04.inc"
        }
        break;

    case 5:
        {
#include "Character19Slot06Case05.inc"
        }
        break;

    case 8:
        {
#include "Character19Slot06Case08.inc"
        }
        break;

    case 9:
        {
#include "Character19Slot06Case09.inc"
        }
        break;

    case 112:
        {
            unsigned short randomValue;
#include "Character19Slot06Case70.inc"
        }
        break;

    case 113:
        {
#include "Character19Slot06Case71.inc"
        }
        break;

    case 114:
        {
#include "Character19Slot06Case72.inc"
        }
        break;

    case 115:
        {
#include "Character19Slot06Case73.inc"
        }
        break;

    case 116:
        {
#include "Character19Slot06Case74.inc"
        }
        break;

    case 117:
        self->dashMomentumFlag = 0;
        self->velocityX = 0.0;
        self->velocityY = 0.0;
        ++self->field000c;
        if (self->field000c >= timing.frameDuration) {
            self->field000c = 0;
            ++self->field000a;
            if (self->field000a >= timing.animationFrameCount) {
                self->field000a = 0;
            }
        }
        break;

    default:
        // Native out-of-range states use the same 0x75 fallback.
        self->dashMomentumFlag = 0;
        self->velocityX = 0.0;
        self->velocityY = 0.0;
        ++self->field000c;
        if (self->field000c >= timing.frameDuration) {
            self->field000c = 0;
            ++self->field000a;
            if (self->field000a >= timing.animationFrameCount) {
                self->field000a = 0;
            }
        }
        break;
    }
}
