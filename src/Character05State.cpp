// Mayu complete animation and state update dispatch.
#include "CharacterViews.h"
void Character05::Slot06()
{
    if (hitstopFrames > 0 || (*opponentSlot)->hitstunFrames > 0) {
        return;
    }
    unsigned short frameDuration, frameCount;
    EffectSpawn effect;
    frameDuration = patterns[field0008].frames[field000a].duration;
    frameCount = patterns[field0008].count;
    ResetLocalEffectSpawn(&effect);
    switch (field0008) {
    default:
        velocityX = 0.0;
        velocityY = 0.0;
        ++field000c;
        if ((unsigned short)field000c >= frameDuration) {
            field000c = 0;
            ++field000a;
            if (field000a >= frameCount) {
                field000a = 0;
            }
        }
        break;
    case 1:
        velocityX = 0.9;
        velocityY = 0.0;
        ++field000c;
        if ((unsigned short)field000c >= frameDuration) {
            field000c = 0;
            ++field000a;
            if (field000a >= frameCount) {
                field000a = 0;
            }
        }
        break;
    case 2:
        velocityX = -0.9;
        velocityY = 0.0;
        ++field000c;
        if ((unsigned short)field000c >= frameDuration) {
            field000c = 0;
            ++field000a;
            if (field000a >= frameCount) {
                field000a = 0;
            }
        }
        break;
    case 3:
        velocityX = 0.0;
        velocityY = 0.0;
        FaceOpponent();
        ++field000c;
        if ((unsigned short)field000c >= frameDuration) {
            field000c = 0;
            ++field000a;
            if (field000a >= frameCount) {
                field000a = 0;
            }
        }
        break;
    case 4:
        if ((field000a == 0) && ((unsigned short)field000c == 0)) {
            FaceOpponent();
            velocityX = 0.0;
        }
        if ((field000a == 3) && ((unsigned short)field000c == 0)) {
            gravity = 0.055;
            velocityY = -2.8;
            pendingCharacterSoundSlot = 1;
        }
        if (4 < field000a) {
            velocityY = velocityY + gravity;
        }
        ++field000c;
        if ((unsigned short)field000c >= frameDuration) {
            field000c = 0;
            ++field000a;
            if (field000a >= frameCount) {
                field000a = field000a + -4;
            }
        }
        if ((0.0 <= positionY + velocityY) &&
            (3 < field000a)) {
            positionY = 0.0;
            pendingContextSoundSlot = 9;
            FaceOpponent();
            field0008 = 0xd;
            ResetPose();
        }
        break;
    case 5:
        if ((field000a == 0) && ((unsigned short)field000c == 0)) {
            FaceOpponent();
            velocityX = 0.0;
        }
        if ((field000a == 3) && ((unsigned short)field000c == 0)) {
            gravity = 0.055;
            velocityY = -2.8;
            velocityX = 1.0;
            pendingCharacterSoundSlot = 1;
        }
        if (4 < field000a) {
            velocityY = velocityY + gravity;
        }
        ++field000c;
        if ((unsigned short)field000c >= frameDuration) {
            field000c = 0;
            ++field000a;
            if (field000a >= frameCount) {
                field000a = field000a + -4;
            }
        }
        if ((0.0 <= positionY + velocityY) &&
            (3 < field000a)) {
            positionY = 0.0;
            pendingContextSoundSlot = 9;
            FaceOpponent();
            field0008 = 0xd;
            ResetPose();
        }
        break;
    case 6:
        if ((field000a == 0) && ((unsigned short)field000c == 0)) {
            FaceOpponent();
            velocityX = 0.0;
        }
        if ((field000a == 3) && ((unsigned short)field000c == 0)) {
            gravity = 0.055;
            velocityY = -2.8;
            velocityX = -1.0;
            pendingCharacterSoundSlot = 1;
        }
        if (4 < field000a) {
            velocityY = velocityY + gravity;
        }
        ++field000c;
        if ((unsigned short)field000c >= frameDuration) {
            field000c = 0;
            ++field000a;
            if (field000a >= frameCount) {
                field000a = field000a + -4;
            }
        }
        if ((0.0 <= positionY + velocityY) &&
            (3 < field000a)) {
            positionY = 0.0;
            pendingContextSoundSlot = 9;
            FaceOpponent();
            field0008 = 0xd;
            ResetPose();
        }
        break;
    case 7:
        velocityX = 0.0;
        velocityY = 0.0;
        FaceOpponent();
        ++field000c;
        if ((unsigned short)field000c >= frameDuration) {
            field000c = 0;
            ++field000a;
            if (field000a >= frameCount) {
                field0008 = 0;
                ResetPose();
            }
        }
        break;
    case 8:
        velocityX = 0.0;
        velocityY = 0.0;
        FaceOpponent();
        ++field000c;
        if ((unsigned short)field000c >= frameDuration) {
            field000c = 0;
            ++field000a;
            if (field000a >= frameCount) {
                field0008 = 3;
                ResetPose();
            }
        }
        break;
    case 9:
        velocityY = velocityY + gravity;
        ++field000c;
        if ((unsigned short)field000c >= frameDuration) {
            field000c = 0;
            ++field000a;
            if (field000a >= frameCount) {
                field000a = 0;
            }
        }
        if (0.0 <= positionY + velocityY) {
            positionY = 0.0;
            pendingContextSoundSlot = 9;
            field0008 = 0xd;
            ResetPose();
        }
        break;
    case 10:
        velocityY = velocityY + gravity;
        ++field000c;
        if ((unsigned short)field000c >= frameDuration) {
            field000c = 0;
            ++field000a;
            if (field000a >= frameCount) {
                field000a = 0;
            }
        }
        if (0.0 <= positionY + velocityY) {
            positionY = 0.0;
            pendingContextSoundSlot = 9;
            field0008 = 0xd;
            ResetPose();
        }
        break;
    case 13:
        velocityX = 0.0;
        velocityY = 0.0;
        FaceOpponent();
        ++field000c;
        if ((unsigned short)field000c >= frameDuration) {
            field000c = 0;
            ++field000a;
            if (field000a >= frameCount) {
                field0008 = 7;
                if (inputY == '\x01') {
                    field0008 = 3;
                }
                ResetPose();
            }
        }
        break;
    case 14:
        gravity = 0.055;
        if ((field000a == 0) && ((unsigned short)field000c == 0)) {
            velocityY = -3.2;
            velocityX = 0.0;
        }
        velocityY = velocityY + gravity;
        ++field000c;
        if ((unsigned short)field000c >= frameDuration) {
            field000c = 0;
            ++field000a;
            if (field000a >= frameCount) {
                field000a = field000a + -4;
            }
        }
        if ((0.0 <= positionY + velocityY) &&
            (3 < field000a)) {
            positionY = 0.0;
            pendingContextSoundSlot = 9;
            FaceOpponent();
            field0008 = 0xd;
            ResetPose();
        }
        break;
    case 15:
        gravity = 0.055;
        if ((field000a == 0) && ((unsigned short)field000c == 0)) {
            velocityY = -3.2;
            velocityX = 1.0;
        }
        velocityY = velocityY + gravity;
        ++field000c;
        if ((unsigned short)field000c >= frameDuration) {
            field000c = 0;
            ++field000a;
            if (field000a >= frameCount) {
                field000a = field000a + -4;
            }
        }
        if ((0.0 <= positionY + velocityY) &&
            (3 < field000a)) {
            positionY = 0.0;
            pendingContextSoundSlot = 9;
            FaceOpponent();
            field0008 = 0xd;
            ResetPose();
        }
        break;
    case 16:
        gravity = 0.055;
        if ((field000a == 0) && ((unsigned short)field000c == 0)) {
            velocityY = -3.2;
            velocityX = -1.0;
        }
        velocityY = velocityY + gravity;
        ++field000c;
        if ((unsigned short)field000c >= frameDuration) {
            field000c = 0;
            ++field000a;
            if (field000a >= frameCount) {
                field000a = field000a + -4;
            }
        }
        if ((0.0 <= positionY + velocityY) &&
            (3 < field000a)) {
            positionY = 0.0;
            pendingContextSoundSlot = 9;
            FaceOpponent();
            field0008 = 0xd;
            ResetPose();
        }
        break;
    case 47:
        if ((field000a == 0) && ((unsigned short)field000c == 0)) {
            velocityX = 0.0;
            gravity = 0.035;
        }
        velocityY = velocityY + gravity;
        if ((0.0 < positionY + velocityY) &&
            (field000a < 2)) {
            field000c = 0;
            field000a = 2;
            pendingContextSoundSlot = 7;
            positionY = 0.0;
            velocityY = 0.0;
            gravity = 0.0;
            velocityX = 0.0;
        }
        ++field000c;
        if ((unsigned short)field000c >= frameDuration) {
            field000c = 0;
            ++field000a;
            if (field000a == 2) {
                field000a = field000a + -2;
            }
            if (field000a >= frameCount) {
                --field000a;
            }
        }
        break;
    case 50:
        if (field0120 != '\0') {
            field0118 = field0118 - 0.6;
        }
        if ((field000a == 0) && ((unsigned short)field000c == 0)) {
            meter = meter + 10;
            velocityX =
            (2.0 - (*opponentSlot)->field0178 / 10000.0) * -1.1;
            if (field0120 != '\0') {
                field0118 = field0118 - 10.0;
            }
        }
        velocityY = 0.0;
        positionY = 0.0;
        velocityX = velocityX + 0.06;
        if (velocityX > 0.0) {
            velocityX = 0.0;
        }
        if ((positionX - 20.0 <= 0.0) ||
            (639.0 <= positionX + 20.0)) {
            outgoingPushbackVelocityX = (1.0 - (double)((positionY < 0.0)) * 0.2) * velocityX;
        }
        else {
            outgoingPushbackVelocityX = 0.0;
        }
        ++field000c;
        if ((unsigned short)field000c >= frameDuration) {
            field000c = 0;
            ++field000a;
            if (field000a >= frameCount) {
                field0008 = 0;
                if (inputY == '\x01') {
                    field0008 = 3;
                }
                ResetPose();
            }
        }
        break;
    case 51:
        if (field0120 != '\0') {
            field0118 = field0118 - 0.6;
        }
        if ((field000a == 0) && ((unsigned short)field000c == 0)) {
            meter = meter + 0xf;
            velocityX =
            (2.0 - (*opponentSlot)->field0178 / 10000.0) * -1.5;
            if (field0120 != '\0') {
                field0118 = field0118 - 20.0;
            }
        }
        velocityY = 0.0;
        positionY = 0.0;
        velocityX = velocityX + 0.06;
        if (velocityX > 0.0) {
            velocityX = 0.0;
        }
        if ((positionX - 20.0 <= 0.0) ||
            (639.0 <= positionX + 20.0)) {
            outgoingPushbackVelocityX = (1.0 - (double)((positionY < 0.0)) * 0.2) * velocityX;
        }
        else {
            outgoingPushbackVelocityX = 0.0;
        }
        ++field000c;
        if ((unsigned short)field000c >= frameDuration) {
            field000c = 0;
            ++field000a;
            if (field000a >= frameCount) {
                field0008 = 0;
                if (inputY == '\x01') {
                    field0008 = 3;
                }
                ResetPose();
            }
        }
        break;
    case 52:
        if (field0120 != '\0') {
            field0118 = field0118 - 0.6;
        }
        if ((field000a == 0) && ((unsigned short)field000c == 0)) {
            meter = meter + 0x14;
            velocityX =
            (2.0 - (*opponentSlot)->field0178 / 10000.0) * -1.8;
            if (field0120 != '\0') {
                field0118 = field0118 - 30.0;
            }
        }
        velocityY = 0.0;
        positionY = 0.0;
        velocityX = velocityX + 0.06;
        if (velocityX > 0.0) {
            velocityX = 0.0;
        }
        if ((positionX - 20.0 <= 0.0) ||
            (639.0 <= positionX + 20.0)) {
            outgoingPushbackVelocityX = (1.0 - (double)((positionY < 0.0)) * 0.2) * velocityX;
        }
        else {
            outgoingPushbackVelocityX = 0.0;
        }
        ++field000c;
        if ((unsigned short)field000c >= frameDuration) {
            field000c = 0;
            ++field000a;
            if (field000a >= frameCount) {
                field0008 = 0;
                if (inputY == '\x01') {
                    field0008 = 3;
                }
                ResetPose();
            }
        }
        break;
    case 53:
        if (field0120 != '\0') {
            field0118 = field0118 - 0.6;
        }
        if ((field000a == 0) && ((unsigned short)field000c == 0)) {
            meter = meter + 10;
            velocityX =
            (2.0 - (*opponentSlot)->field0178 / 10000.0) * -1.1;
            if (field0120 != '\0') {
                field0118 = field0118 - 10.0;
            }
        }
        velocityY = 0.0;
        positionY = 0.0;
        velocityX = velocityX + 0.06;
        if (velocityX > 0.0) {
            velocityX = 0.0;
        }
        if ((positionX - 20.0 <= 0.0) ||
            (639.0 <= positionX + 20.0)) {
            outgoingPushbackVelocityX = (1.0 - (double)((positionY < 0.0)) * 0.2) * velocityX;
        }
        else {
            outgoingPushbackVelocityX = 0.0;
        }
        ++field000c;
        if ((unsigned short)field000c >= frameDuration) {
            field000c = 0;
            ++field000a;
            if (field000a >= frameCount) {
                field0008 = 0;
                if (inputY == '\x01') {
                    field0008 = 3;
                }
                ResetPose();
            }
        }
        break;
    case 54:
        if (field0120 != '\0') {
            field0118 = field0118 - 0.6;
        }
        if ((field000a == 0) && ((unsigned short)field000c == 0)) {
            meter = meter + 0xf;
            velocityX =
            (2.0 - (*opponentSlot)->field0178 / 10000.0) * -1.5;
            if (field0120 != '\0') {
                field0118 = field0118 - 20.0;
            }
        }
        velocityY = 0.0;
        positionY = 0.0;
        velocityX = velocityX + 0.06;
        if (velocityX > 0.0) {
            velocityX = 0.0;
        }
        if ((positionX - 20.0 <= 0.0) ||
            (639.0 <= positionX + 20.0)) {
            outgoingPushbackVelocityX = (1.0 - (double)((positionY < 0.0)) * 0.2) * velocityX;
        }
        else {
            outgoingPushbackVelocityX = 0.0;
        }
        ++field000c;
        if ((unsigned short)field000c >= frameDuration) {
            field000c = 0;
            ++field000a;
            if (field000a >= frameCount) {
                field0008 = 0;
                if (inputY == '\x01') {
                    field0008 = 3;
                }
                ResetPose();
            }
        }
        break;
    case 55:
        if (field0120 != '\0') {
            field0118 = field0118 - 0.6;
        }
        if ((field000a == 0) && ((unsigned short)field000c == 0)) {
            meter = meter + 0x14;
            velocityX =
            (2.0 - (*opponentSlot)->field0178 / 10000.0) * -1.8;
            if (field0120 != '\0') {
                field0118 = field0118 - 30.0;
            }
        }
        velocityY = 0.0;
        positionY = 0.0;
        velocityX = velocityX + 0.06;
        if (velocityX > 0.0) {
            velocityX = 0.0;
        }
        if ((positionX - 20.0 <= 0.0) ||
            (639.0 <= positionX + 20.0)) {
            outgoingPushbackVelocityX = (1.0 - (double)((positionY < 0.0)) * 0.2) * velocityX;
        }
        else {
            outgoingPushbackVelocityX = 0.0;
        }
        ++field000c;
        if ((unsigned short)field000c >= frameDuration) {
            field000c = 0;
            ++field000a;
            if (field000a >= frameCount) {
                field0008 = 0;
                if (inputY == '\x01') {
                    field0008 = 3;
                }
                ResetPose();
            }
        }
        break;
    case 56:
        if (field0120 != '\0') {
            field0118 = field0118 - 0.6;
        }
        if ((field000a == 0) && ((unsigned short)field000c == 0)) {
            meter = meter + 10;
            velocityX =
            (2.0 - (*opponentSlot)->field0178 / 10000.0) * -1.1;
            if (field0120 != '\0') {
                field0118 = field0118 - 10.0;
            }
        }
        velocityY = 0.0;
        positionY = 0.0;
        velocityX = velocityX + 0.06;
        if (velocityX > 0.0) {
            velocityX = 0.0;
        }
        if ((positionX - 20.0 <= 0.0) ||
            (639.0 <= positionX + 20.0)) {
            outgoingPushbackVelocityX = (1.0 - (double)((positionY < 0.0)) * 0.2) * velocityX;
        }
        else {
            outgoingPushbackVelocityX = 0.0;
        }
        ++field000c;
        if ((unsigned short)field000c >= frameDuration) {
            field000c = 0;
            ++field000a;
            if (field000a >= frameCount) {
                field0008 = 3;
                ResetPose();
            }
        }
        break;
    case 57:
        if (field0120 != '\0') {
            field0118 = field0118 - 0.6;
        }
        if ((field000a == 0) && ((unsigned short)field000c == 0)) {
            meter = meter + 0xf;
            velocityX =
            (2.0 - (*opponentSlot)->field0178 / 10000.0) * -1.5;
            if (field0120 != '\0') {
                field0118 = field0118 - 20.0;
            }
        }
        velocityY = 0.0;
        positionY = 0.0;
        velocityX = velocityX + 0.06;
        if (velocityX > 0.0) {
            velocityX = 0.0;
        }
        if ((positionX - 20.0 <= 0.0) ||
            (639.0 <= positionX + 20.0)) {
            outgoingPushbackVelocityX = (1.0 - (double)((positionY < 0.0)) * 0.2) * velocityX;
        }
        else {
            outgoingPushbackVelocityX = 0.0;
        }
        ++field000c;
        if ((unsigned short)field000c >= frameDuration) {
            field000c = 0;
            ++field000a;
            if (field000a >= frameCount) {
                field0008 = 3;
                ResetPose();
            }
        }
        break;
    case 58:
        if (field0120 != '\0') {
            field0118 = field0118 - 0.6;
        }
        if ((field000a == 0) && ((unsigned short)field000c == 0)) {
            meter = meter + 0x14;
            velocityX =
            (2.0 - (*opponentSlot)->field0178 / 10000.0) * -1.8;
            if (field0120 != '\0') {
                field0118 = field0118 - 30.0;
            }
        }
        velocityY = 0.0;
        positionY = 0.0;
        velocityX = velocityX + 0.06;
        if (velocityX > 0.0) {
            velocityX = 0.0;
        }
        if ((positionX - 20.0 <= 0.0) ||
            (639.0 <= positionX + 20.0)) {
            outgoingPushbackVelocityX = (1.0 - (double)((positionY < 0.0)) * 0.2) * velocityX;
        }
        else {
            outgoingPushbackVelocityX = 0.0;
        }
        ++field000c;
        if ((unsigned short)field000c >= frameDuration) {
            field000c = 0;
            ++field000a;
            if (field000a >= frameCount) {
                field0008 = 3;
                ResetPose();
            }
        }
        break;
    case 59:
        if (field0120 != '\0') {
            field0118 = field0118 - 0.8;
        }
        if ((field000a == 0) && ((unsigned short)field000c == 0)) {
            meter = meter + 0x1e;
            velocityX = knockbackVelocityX;
            velocityY = velocityY * 0.75 + knockbackVelocityY;
            if (velocityY < -2.0) {
                velocityY = -2.0;
            } else if (velocityY > -0.5) {
                velocityY = -0.5;
            }
            gravity = 0.032;
        }
        if (velocityY <= 0.0) {
            field000a = 1;
            field000c = 0;
        }
        if ((velocityY >= 0.0) && (field000a <= 1)) {
            field000a = 2;
            field000c = 0;
        }
        velocityY = velocityY + gravity;
        ++field000c;
        if ((unsigned short)field000c >= frameDuration) {
            field000c = 0;
            ++field000a;
            if (field000a >= frameCount) {
                field000a = field000a + -2;
            }
        }
        if ((0.0 <= positionY + velocityY) &&
            (1 < field000a)) {
            positionY = 0.0;
            if (field012c != 0) {
                field0008 = 0x61;
                ResetPose();
            } else {
                field0008 = 0x62;
                ResetPose();
            }
        }
        break;
    case 60:
        if (field0120 != '\0') {
            field0118 = field0118 - 0.8;
        }
        if ((field000a == 0) && ((unsigned short)field000c == 0)) {
            meter = meter + 0x1e;
            velocityX = knockbackVelocityX;
            velocityY = velocityY * 0.75 + knockbackVelocityY;
            if (velocityY < -4.0) {
                velocityY = -4.0;
            } else if (velocityY > -0.5) {
                velocityY = -0.5;
            }
            gravity = 0.032;
        }
        if (velocityY <= 0.0) {
            field000a = 1;
            field000c = 0;
        }
        if ((velocityY >= 0.0) && (field000a <= 1)) {
            field000a = 2;
            field000c = 0;
        }
        velocityY = velocityY + gravity;
        ++field000c;
        if ((unsigned short)field000c >= frameDuration) {
            field000c = 0;
            ++field000a;
            if (field000a >= frameCount) {
                field000a = field000a + -2;
            }
        }
        if ((0.0 <= positionY + velocityY) &&
            (1 < field000a)) {
            positionY = 0.0;
            if (field012c != 0) {
                field0008 = 0x61;
                ResetPose();
            } else {
                field0008 = 0x62;
                ResetPose();
            }
        }
        break;
    case 61:
        if (field0120 != '\0') {
            field0118 = field0118 - 0.8;
        }
        if ((field000a == 0) && ((unsigned short)field000c == 0)) {
            meter = meter + 0x1e;
            velocityX = knockbackVelocityX;
            velocityY = velocityY * 0.75 + knockbackVelocityY;
            if (velocityY < -6.0) {
                velocityY = -6.0;
            } else if (velocityY > -0.5) {
                velocityY = -0.5;
            }
            gravity = 0.032;
        }
        if (velocityY <= 0.0) {
            field000a = 1;
            field000c = 0;
        }
        if ((velocityY >= 0.0) && (field000a <= 1)) {
            field000a = 2;
            field000c = 0;
        }
        velocityY = velocityY + gravity;
        ++field000c;
        if ((unsigned short)field000c >= frameDuration) {
            field000c = 0;
            ++field000a;
            if (field000a >= frameCount) {
                field000a = field000a + -2;
            }
        }
        if ((0.0 <= positionY + velocityY) &&
            (1 < field000a)) {
            positionY = 0.0;
            if (field012c != 0) {
                field0008 = 0x61;
                ResetPose();
            } else {
                field0008 = 0x62;
                ResetPose();
            }
        }
        break;
    case 62:
        if (field0120 != '\0') {
            field0118 = field0118 - 0.8;
        }
        if ((field000a == 0) && ((unsigned short)field000c == 0)) {
            meter = meter + 0x1e;
            velocityX = knockbackVelocityX;
            velocityY = velocityY * 0.75 + knockbackVelocityY;
            gravity = 0.032;
        }
        if (velocityY <= 0.0) {
            field000a = 1;
            field000c = 0;
        }
        if ((velocityY >= 0.0) && (field000a <= 1)) {
            field000a = 2;
            field000c = 0;
        }
        velocityY = velocityY + gravity;
        ++field000c;
        if ((unsigned short)field000c >= frameDuration) {
            field000c = 0;
            ++field000a;
            if (field000a >= frameCount) {
                field000a = field000a + -2;
            }
        }
        if ((0.0 <= positionY + velocityY) &&
            (1 < field000a)) {
            positionY = 0.0;
            if (field012c != 0) {
                field0008 = 0x61;
                ResetPose();
            } else {
                field0008 = 0x62;
                ResetPose();
            }
        }
        break;
    case 63:
        if (field0120 != '\0') {
            field0118 = field0118 - 0.8;
        }
        if ((field000a == 0) && ((unsigned short)field000c == 0)) {
            meter = meter + 0x1e;
            velocityX = knockbackVelocityX;
            velocityY = knockbackVelocityY;
            gravity = 0.032;
        }
        if (velocityY <= 0.0) {
            field000a = 1;
            field000c = 0;
        }
        if ((velocityY >= 0.0) && (field000a <= 1)) {
            field000a = 2;
            field000c = 0;
        }
        velocityY = velocityY + gravity;
        ++field000c;
        if ((unsigned short)field000c >= frameDuration) {
            field000c = 0;
            ++field000a;
            if (field000a >= frameCount) {
                field000a = field000a + -2;
            }
        }
        if ((0.0 <= positionY + velocityY) &&
            (1 < field000a)) {
            positionY = 0.0;
            if (field012c != 0) {
                field0008 = 0x61;
                ResetPose();
            } else {
                field0008 = 0x62;
                ResetPose();
            }
        }
        break;
    case 64:
        if (field0120 != '\0') {
            field0118 = field0118 - 0.8;
        }
        if (field000a > 0 && CollisionSide() != 0) {
            field0008 = 0x46;
            ResetPose();
            break;
        }
        if ((field000a == 0) && ((unsigned short)field000c == 0)) {
            meter = meter + 0x1e;
            velocityX = knockbackVelocityX;
            velocityY = velocityY * 0.75 + knockbackVelocityY;
            if (velocityY < -2.0) {
                velocityY = -2.0;
            } else if (velocityY > -0.5) {
                velocityY = -0.5;
            }
            gravity = 0.032;
        }
        if (velocityY <= 0.0) {
            field000a = 1;
            field000c = 0;
        }
        if ((velocityY >= 0.0) && (field000a <= 1)) {
            field000a = 2;
            field000c = 0;
        }
        velocityY = velocityY + gravity;
        ++field000c;
        if ((unsigned short)field000c >= frameDuration) {
            field000c = 0;
            ++field000a;
            if (field000a >= frameCount) {
                field000a = field000a + -2;
            }
        }
        if ((0.0 <= positionY + velocityY) &&
            (1 < field000a)) {
            positionY = 0.0;
            if (field012c != 0) {
                field0008 = 0x61;
                ResetPose();
            } else {
                field0008 = 0x62;
                ResetPose();
            }
        }
        break;
    case 65:
        if (field0120 != '\0') {
            field0118 = field0118 - 0.8;
        }
        if (field000a > 0 && CollisionSide() != 0) {
            field0008 = 0x46;
            ResetPose();
            break;
        }
        if ((field000a == 0) && ((unsigned short)field000c == 0)) {
            meter = meter + 0x1e;
            velocityX = knockbackVelocityX;
            velocityY = velocityY * 0.75 + knockbackVelocityY;
            if (velocityY < -4.0) {
                velocityY = -4.0;
            } else if (velocityY > -0.5) {
                velocityY = -0.5;
            }
            gravity = 0.032;
        }
        if (velocityY <= 0.0) {
            field000a = 1;
            field000c = 0;
        }
        if ((velocityY >= 0.0) && (field000a <= 1)) {
            field000a = 2;
            field000c = 0;
        }
        velocityY = velocityY + gravity;
        ++field000c;
        if ((unsigned short)field000c >= frameDuration) {
            field000c = 0;
            ++field000a;
            if (field000a >= frameCount) {
                field000a = field000a + -2;
            }
        }
        if ((0.0 <= positionY + velocityY) &&
            (1 < field000a)) {
            positionY = 0.0;
            if (field012c != 0) {
                field0008 = 0x61;
                ResetPose();
            } else {
                field0008 = 0x62;
                ResetPose();
            }
        }
        break;
    case 66:
        if (field0120 != '\0') {
            field0118 = field0118 - 0.8;
        }
        if (field000a > 0 && CollisionSide() != 0) {
            field0008 = 0x46;
            ResetPose();
            break;
        }
        if ((field000a == 0) && ((unsigned short)field000c == 0)) {
            meter = meter + 0x1e;
            velocityX = knockbackVelocityX;
            velocityY = velocityY * 0.75 + knockbackVelocityY;
            gravity = 0.032;
        }
        if (velocityY <= 0.0) {
            field000a = 1;
            field000c = 0;
        }
        if ((velocityY >= 0.0) && (field000a <= 1)) {
            field000a = 2;
            field000c = 0;
        }
        velocityY = velocityY + gravity;
        ++field000c;
        if ((unsigned short)field000c >= frameDuration) {
            field000c = 0;
            ++field000a;
            if (field000a >= frameCount) {
                field000a = field000a + -2;
            }
        }
        if ((0.0 <= positionY + velocityY) &&
            (1 < field000a)) {
            positionY = 0.0;
            if (field012c != 0) {
                field0008 = 0x61;
                ResetPose();
            } else {
                field0008 = 0x62;
                ResetPose();
            }
        }
        break;
    case 67:
        if (field0120 != '\0') {
            field0118 = field0118 - 0.8;
        }
        if (field000a > 0 && CollisionSide() != 0) {
            field0008 = 0x46;
            ResetPose();
            break;
        }
        if ((field000a == 0) && ((unsigned short)field000c == 0)) {
            meter = meter + 0x1e;
            velocityX = knockbackVelocityX;
            velocityY = knockbackVelocityY;
            gravity = 0.032;
        }
        if (velocityY <= 0.0) {
            field000a = 1;
            field000c = 0;
        }
        if ((velocityY >= 0.0) && (field000a <= 1)) {
            field000a = 2;
            field000c = 0;
        }
        velocityY = velocityY + gravity;
        ++field000c;
        if ((unsigned short)field000c >= frameDuration) {
            field000c = 0;
            ++field000a;
            if (field000a >= frameCount) {
                field000a = field000a + -2;
            }
        }
        if ((0.0 <= positionY + velocityY) &&
            (1 < field000a)) {
            positionY = 0.0;
            if (field012c != 0) {
                field0008 = 0x61;
                ResetPose();
            } else {
                field0008 = 0x62;
                ResetPose();
            }
        }
        break;
    case 68:
        if (field0120 != '\0') {
            field0118 = field0118 - 1.5;
        }
        meter = meter + 3;
        velocityX = knockbackVelocityX;
        velocityY = knockbackVelocityY;
        ++field000c;
        if (CollisionSide() != 0) {
            field0008 = 0x46;
            ResetPose();
            break;
        }
        if ((unsigned short)field000c >= frameDuration) {
            field000c = 0;
            ++field000a;
            if (field000a >= frameCount) {
                field000a = field000a + -2;
            }
        }
        if (0.0 <= positionY + velocityY) {
            positionY = 0.0;
            if (field012c != 0) {
                field0008 = 0x61;
                ResetPose();
            } else {
                field0008 = 0x62;
                ResetPose();
            }
        }
        break;
    case 69:
        if (field0120 != '\0') {
            field0118 = field0118 - 1.5;
        }
        meter = meter + 3;
        velocityX = knockbackVelocityX;
        velocityY = knockbackVelocityY;
        ++field000c;
        if ((unsigned short)field000c >= frameDuration) {
            field000c = 0;
            ++field000a;
            if (field000a >= frameCount) {
                field000a = field000a + -2;
            }
        }
        if (0.0 <= positionY + velocityY) {
            positionY = 0.0;
            if (field012c != 0) {
                field0008 = 0x61;
                ResetPose();
            } else {
                field0008 = 0x62;
                ResetPose();
            }
        }
        break;
    case 70:
        if (field0120 != '\0') {
            field0118 = field0118 - 0.8;
        }
        if (((field000a == 0) && ((unsigned short)field000c == 0)) && (field3138 == 0))
        {
            meter = meter + 0x1e;
            ++field3138;
            field0124 = field0124 + 0x78;
            velocityX = 0.5;
            velocityY = -2.5;
            gravity = 0.025;
            pendingContextSoundSlot = 0x1f;
            effect.type = 0;
            effect.x = (double)(int(positionX));
            effect.y = (double)(int(positionY));
            effect.group = 2;
            effect.layer = 1;
            contextOwner->EmitEffect(&effect);
        }
        velocityY = velocityY + gravity;
        ++field000c;
        if ((unsigned short)field000c >= frameDuration) {
            field000c = 0;
            ++field000a;
            if (field000a >= frameCount) {
                field000a = 0;
            }
        }
        if ((0.0 <= positionY + velocityY) &&
            (1 < field000a)) {
            positionY = 0.0;
            if (field012c != 0) {
                field0008 = 0x61;
                ResetPose();
            } else {
                field0008 = 0x62;
                ResetPose();
            }
        }
        break;
    case 71:
        if (field0120 != '\0') {
            field0118 = field0118 - 0.8;
        }
        if ((field000a == 0) && ((unsigned short)field000c == 0)) {
            meter = meter + 0x1e;
            velocityX = knockbackVelocityX;
            velocityY = knockbackVelocityY;
            gravity = 0.072;
        }
        if (velocityY <= 0.0) {
            field000a = 1;
            field000c = 0;
        }
        if ((velocityY >= 0.0) && (field000a <= 1)) {
            field000a = 2;
            field000c = 0;
        }
        velocityY = velocityY + gravity;
        ++field000c;
        if ((unsigned short)field000c >= frameDuration) {
            field000c = 0;
            ++field000a;
            if (field000a >= frameCount) {
                field000a = field000a + -2;
            }
        }
        if ((0.0 <= positionY + velocityY) &&
            (1 < field000a)) {
            positionY = 0.0;
            if (field012c != 0) {
                field0008 = 0x61;
                ResetPose();
            } else {
                field0008 = 0x62;
                ResetPose();
            }
        }
        break;
    case 72:
        if (field0120 != '\0') {
            field0118 = field0118 - 0.8;
        }
        velocityX = 0.0;
        velocityY = 0.0;
        if ((positionX - 20.0 <= 0.0) ||
            (639.0 <= positionX + 20.0)) {
            outgoingPushbackVelocityX = (1.0 - (double)(((*opponentSlot)->positionY < 0.0)) * 0.25) * velocityX;
        }
        else {
            outgoingPushbackVelocityX = 0.0;
        }
        ++field000c;
        if ((unsigned short)field000c >= frameDuration) {
            field000c = 0;
            ++field000a;
            if (field000a >= frameCount) {
                field0008 = 7;
                if (inputY == '\x01') {
                    field0008 = 3;
                }
                ResetPose();
            }
        }
        break;
    case 73:
        if (field0120 != '\0') {
            field0118 = field0118 - 0.8;
        }
        velocityX = 0.0;
        velocityY = 0.0;
        if ((positionX - 20.0 <= 0.0) ||
            (639.0 <= positionX + 20.0)) {
            outgoingPushbackVelocityX = (1.0 - (double)(((*opponentSlot)->positionY < 0.0)) * 0.25) * velocityX;
        }
        else {
            outgoingPushbackVelocityX = 0.0;
        }
        ++field000c;
        if ((unsigned short)field000c >= frameDuration) {
            field000c = 0;
            ++field000a;
            if (field000a >= frameCount) {
                field0008 = 7;
                if (inputY == '\x01') {
                    field0008 = 3;
                }
                ResetPose();
            }
        }
        break;
    case 74:
        if (field0120 != '\0') {
            field0118 = field0118 - 0.8;
        }
        velocityX = 0.0;
        velocityY = 0.0;
        if ((positionX - 20.0 <= 0.0) ||
            (639.0 <= positionX + 20.0)) {
            outgoingPushbackVelocityX = (1.0 - (double)(((*opponentSlot)->positionY < 0.0)) * 0.25) * velocityX;
        }
        else {
            outgoingPushbackVelocityX = 0.0;
        }
        ++field000c;
        if ((unsigned short)field000c >= frameDuration) {
            field000c = 0;
            ++field000a;
            if (field000a >= frameCount) {
                field0008 = 3;
                ResetPose();
            }
        }
        break;
    case 75:
        if (field0120 != '\0') {
            field0118 = field0118 - 0.6;
        }
        if ((field000a == 0) && ((unsigned short)field000c == 0)) {
            meter = meter + 0x1e;
            if (field0120 != '\0') {
                field0118 = field0118 - 30.0;
            }
            velocityX = 2.2;
        }
        velocityY = 0.0;
        positionY = 0.0;
        gravity = 0.0;
        horizontalDeceleration = 0.06;
        velocityX = velocityX - horizontalDeceleration;
        if (velocityX < 0.0) {
            velocityX = 0.0;
        }
        if ((positionX - 20.0 <= 0.0) ||
            (639.0 <= positionX + 20.0)) {
            outgoingPushbackVelocityX = (1.0 - (double)(((*opponentSlot)->positionY < 0.0)) * 0.25) * velocityX;
        }
        else {
            outgoingPushbackVelocityX = 0.0;
        }
        ++field000c;
        if ((unsigned short)field000c >= frameDuration) {
            field000c = 0;
            ++field000a;
            if (field000a >= frameCount) {
                field0008 = 7;
                if (inputY == '\x01') {
                    field0008 = 3;
                }
                ResetPose();
            }
        }
        break;
    case 76:
        if (field0120 != '\0') {
            field0118 = field0118 - 0.6;
        }
        if ((field000a == 0) && ((unsigned short)field000c == 0)) {
            meter = meter + 0x1e;
            if (field0120 != '\0') {
                field0118 = field0118 - 30.0;
            }
            velocityX = 2.2;
        }
        velocityY = 0.0;
        positionY = 0.0;
        gravity = 0.0;
        horizontalDeceleration = 0.06;
        velocityX = velocityX - horizontalDeceleration;
        if (velocityX < 0.0) {
            velocityX = 0.0;
        }
        if ((positionX - 20.0 <= 0.0) ||
            (639.0 <= positionX + 20.0)) {
            outgoingPushbackVelocityX = (1.0 - (double)(((*opponentSlot)->positionY < 0.0)) * 0.25) * velocityX;
        }
        else {
            outgoingPushbackVelocityX = 0.0;
        }
        ++field000c;
        if ((unsigned short)field000c >= frameDuration) {
            field000c = 0;
            ++field000a;
            if (field000a >= frameCount) {
                field0008 = 7;
                if (inputY == '\x01') {
                    field0008 = 3;
                }
                ResetPose();
            }
        }
        break;
    case 77:
        if (field0120 != '\0') {
            field0118 = field0118 - 0.6;
        }
        if ((field000a == 0) && ((unsigned short)field000c == 0)) {
            meter = meter + 0x1e;
            if (field0120 != '\0') {
                field0118 = field0118 - 30.0;
            }
            velocityX = 2.2;
        }
        velocityY = 0.0;
        positionY = 0.0;
        gravity = 0.0;
        horizontalDeceleration = 0.06;
        velocityX = velocityX - horizontalDeceleration;
        if (velocityX < 0.0) {
            velocityX = 0.0;
        }
        if ((positionX - 20.0 <= 0.0) ||
            (639.0 <= positionX + 20.0)) {
            outgoingPushbackVelocityX = (1.0 - (double)(((*opponentSlot)->positionY < 0.0)) * 0.25) * velocityX;
        }
        else {
            outgoingPushbackVelocityX = 0.0;
        }
        ++field000c;
        if ((unsigned short)field000c >= frameDuration) {
            field000c = 0;
            ++field000a;
            if (field000a >= frameCount) {
                field0008 = 3;
                ResetPose();
            }
        }
        break;
    case 81:
        if (field0120 != '\0') {
            field0118 = field0118 - 0.8;
        }
        if ((field000a == 0) && ((unsigned short)field000c == 0)) {
            effect.type = 499;
            effect.x = (double)(int(positionX));
            effect.y = (double)(int(positionY));
            effect.flag0018 = (unsigned char)facing;
            effect.layer = 1;
            EmitLocalEffect(&effect);
            meter = meter + 0x1e;
            velocityX = knockbackVelocityX;
            velocityY = knockbackVelocityY;
            gravity = 0.032;
        }
        velocityX = velocityX + 0.02;
        velocityY = velocityY + gravity;
        if (velocityX > 0.0) {
            velocityX = 0.0;
        }
        ++field000c;
        if ((unsigned short)field000c >= frameDuration) {
            field000c = 0;
            ++field000a;
            if (field000a >= frameCount) {
                --field000a;
            }
        }
        if ((0.0 <= positionY + velocityY) &&
            (field000a == 1)) {
            positionY = 0.0;
            if (field012c != 0) {
                field0008 = 0x61;
                ResetPose();
            } else {
                field0008 = 0x62;
                ResetPose();
            }
        }
        break;
    case 82:
        if (field0120 != '\0') {
            field0118 = field0118 - 0.8;
        }
        if (((field000a == 0) && ((unsigned short)field000c == 0)) && (field3138 == 0))
        {
            pendingContextSoundSlot = 0x1e;
            velocityY = -0.45;
            velocityX = -0.1;
            ++field3138;
            meter = meter + 0x1e;
        }
        if ((field000a == 4) && ((unsigned short)field000c == 0)) {
            velocityX = knockbackVelocityX;
            velocityY = knockbackVelocityY;
            gravity = 0.032;
        }
        if ((velocityY > 0.0) && (field000a == 4)) {
            field000a = 5;
            field000c = 0;
        }
        if (3 < field000a) {
            velocityY = velocityY + gravity;
        }
        ++field000c;
        if ((unsigned short)field000c >= frameDuration) {
            field000c = 0;
            ++field000a;
            if ((field000a == 4) && (field3138 < 8)) {
                field000a = 0;
                ++field3138;
            }
            if (field000a >= frameCount) {
                field000a = field000a + -2;
            }
        }
        if ((0.0 <= positionY + velocityY) &&
            (4 < field000a)) {
            positionY = 0.0;
            if (field012c != 0) {
                field0008 = 0x61;
                ResetPose();
            } else {
                field0008 = 0x62;
                ResetPose();
            }
        }
        break;
    case 83:
        if ((field000a == 0) && ((unsigned short)field000c == 0)) {
            if (field3144 == 0) {
                effect.type = 0x1f0;
                effect.x = (double)(int(positionX));
                effect.y = (double)(int(positionY));
                effect.group = 0;
                effect.layer = 0;
                effect.owner = 1;
                effect.flag0018 = (unsigned char)facing;
                EmitLocalEffect(&effect);
                field3144 = 1;
            }
            if (field0120 != '\0') {
                field0118 = field0118 - 30.0;
            }
            pendingContextSoundSlot = 0x21;
            velocityY = -1.5;
            velocityX = -0.8;
            meter = meter + 0x1e;
        }
        velocityY = velocityY + 0.04;
        if (field000a == 0 && velocityY + positionY > 0.0) {
            positionY = 0.0;
            velocityY = 0.0;
            field000c = 0;
            field000a = 1;
            break;
        }
        if (field000a == 1) {
            velocityX = velocityX + 0.01;
        }
        if ((field000a == 2) && ((unsigned short)field000c == 0)) {
            velocityX = -2.0;
        }
        if (1 < field000a) {
            velocityX = velocityX + 0.06;
        }
        if (velocityX > 0.0) {
            velocityX = 0.0;
        }
        ++field000c;
        if ((unsigned short)field000c >= frameDuration) {
            field000c = 0;
            ++field000a;
            if (field000a >= frameCount) {
                field0008 = 0;
                ResetPose();
                FaceOpponent();
            }
        }
        break;
    case 84:
        if ((field000a == 0) && ((unsigned short)field000c == 0)) {
            if (field3144 == 0) {
                effect.type = 0x1f0;
                effect.x = (double)(int(positionX));
                effect.y = (double)(int(positionY));
                effect.group = 0;
                effect.layer = 0;
                effect.owner = 1;
                effect.flag0018 = (unsigned char)facing;
                EmitLocalEffect(&effect);
                field3144 = 1;
            }
            if (field0120 != '\0') {
                field0118 = field0118 - 30.0;
            }
            pendingContextSoundSlot = 0x21;
            velocityY = -1.5;
            velocityX = -0.8;
            meter = meter + 0x1e;
        }
        velocityY = velocityY + 0.04;
        if (field000a == 0 && velocityY + positionY > 0.0) {
            positionY = 0.0;
            velocityY = 0.0;
            field000c = 0;
            field000a = 1;
            break;
        }
        if (field000a == 1) {
            velocityX = velocityX + 0.01;
        }
        if ((field000a == 2) && ((unsigned short)field000c == 0)) {
            velocityX = -2.0;
        }
        if (1 < field000a) {
            velocityX = velocityX + 0.06;
        }
        if (velocityX > 0.0) {
            velocityX = 0.0;
        }
        ++field000c;
        if ((unsigned short)field000c >= frameDuration) {
            field000c = 0;
            ++field000a;
            if (field000a >= frameCount) {
                field0008 = 0;
                ResetPose();
                FaceOpponent();
            }
        }
        break;
    case 85:
        if ((field000a == 0) && ((unsigned short)field000c == 0)) {
            if (field3144 == 0) {
                effect.type = 0x1f0;
                effect.x = (double)(int(positionX));
                effect.y = (double)(int(positionY));
                effect.group = 0;
                effect.layer = 0;
                effect.owner = 1;
                effect.flag0018 = (unsigned char)facing;
                EmitLocalEffect(&effect);
                field3144 = 1;
            }
            if (field0120 != '\0') {
                field0118 = field0118 - 30.0;
            }
            pendingContextSoundSlot = 0x21;
            velocityX = knockbackVelocityX;
            velocityY = knockbackVelocityY;
            meter = meter + 0x1e;
        }
        velocityY = velocityY + 0.04;
        ++field000c;
        if ((unsigned short)field000c >= frameDuration) {
            field000c = 0;
            ++field000a;
            if (field000a >= frameCount) {
                field0008 = 0;
                ResetPose();
                FaceOpponent();
            }
        }
        if (0.0 <= positionY + velocityY) {
            positionY = 0.0;
            if (field012c != 0) {
                field0008 = 0x61;
                ResetPose();
            } else {
                field0008 = 0x62;
                ResetPose();
            }
        }
        break;
    case 86:
        if ((field000a == 0) && ((unsigned short)field000c == 0)) {
            if (field3144 == 0) {
                effect.type = 0x1f0;
                effect.x = (double)(int(positionX));
                effect.y = (double)(int(positionY));
                effect.group = 0;
                effect.layer = 0;
                effect.owner = 1;
                effect.flag0018 = (unsigned char)facing;
                EmitLocalEffect(&effect);
                field3144 = 1;
            }
            if (field3138 == 0) {
                if (field0120 != '\0') {
                    field0118 = field0118 - 30.0;
                }
                pendingContextSoundSlot = 0x21;
                velocityX = knockbackVelocityX;
                velocityY = knockbackVelocityY;
                meter = meter + 0x1e;
                ++field3138;
            }
        }
        velocityY = velocityY + 0.06;
        ++field000c;
        if ((unsigned short)field000c >= frameDuration) {
            field000c = 0;
            ++field000a;
            if (field000a >= frameCount) {
                field000a = 0;
            }
        }
        if (0.0 <= positionY + velocityY) {
            positionY = 0.0;
            if (field012c != 0) {
                field0008 = 0x61;
                ResetPose();
            } else {
                field0008 = 0x62;
                ResetPose();
            }
        }
        break;
    case 87:
        if ((field000a == 0) && ((unsigned short)field000c == 0)) {
            effect.type = 0x1ef;
            effect.x = 60.0;
            effect.y = 40.0;
            effect.payload = 1;
            effect.flag0018 = 1;
            effect.group = 0;
            effect.layer = 0;
            EmitLocalEffect(&effect);
        }
        ++field000c;
        if ((unsigned short)field000c >= frameDuration) {
            field000c = 0;
            ++field000a;
            if (field000a >= frameCount) {
                field0008 = 0;
                ResetPose();
            }
        }
        break;
    case 96:
        if (field000a < 9) {
            velocityY = velocityY + gravity;
        }
        ++field000c;
        if ((unsigned short)field000c >= frameDuration) {
            field000c = 0;
            ++field000a;
            if (field000a == 3) {
                velocityY = -1.8;
                gravity = 0.05;
            }
            if (field000a == 9) {
                field000a = field000a + -4;
            }
            if (((field000a < 9) && (4 < field000a)) &&
                (0.0 < positionY + velocityY)) {
                positionY = 0.0;
                velocityY = 0.0;
                field000a = 9;
            }
            if (field000a == frameCount - 1) {
                FaceOpponent();
            }
            if (field000a >= frameCount) {
                field0008 = 7;
                if (inputY == '\x01') {
                    field0008 = 3;
                }
                ResetPose();
            }
        }
        break;
    case 97:
        velocityX = 0.0;
        velocityY = 0.0;
        if ((field000a == 0) && ((unsigned short)field000c == 0)) {
            SetVerticalShake(3,0);
            effect.type = 3;
            effect.x = (double)(int(positionX));
            effect.y = (double)(int(positionY));
            effect.group = 2;
            effect.layer = 0;
            contextOwner->EmitEffect(&effect);
            pendingContextSoundSlot = 7;
        }
        ++field000c;
        if ((unsigned short)field000c >= frameDuration) {
            field000c = 0;
            ++field000a;
            if (field000a >= frameCount) {
                field0008 = 99;
                ResetPose();
            }
        }
        break;
    case 98:
        velocityX = 0.0;
        velocityY = 0.0;
        if ((field000a == 0) && ((unsigned short)field000c == 0)) {
            SetVerticalShake(3,0);
            effect.type = 3;
            effect.x = (double)(int(positionX));
            effect.y = (double)(int(positionY));
            effect.group = 2;
            effect.layer = 0;
            contextOwner->EmitEffect(&effect);
            pendingContextSoundSlot = 7;
        }
        ++field000c;
        if ((unsigned short)field000c >= frameDuration) {
            field000c = 0;
            ++field000a;
            if (field000a >= frameCount) {
                field0008 = 99;
                ResetPose();
            }
        }
        break;
    case 99:
        ++field000c;
        if (((0 < field0108) && (0x45 < (unsigned short)field000c)) &&
            (field000a == 0)) {
            field0008 = 0x60;
            ResetPose();
        }
        if ((unsigned short)field000c >= frameDuration) {
            field000c = 0;
            ++field000a;
            if (field000a == frameCount) {
                FaceOpponent();
            }
            if (field000a >= frameCount) {
                field0008 = 0x60;
                ResetPose();
            }
        }
        break;
    case 150:
        if (inputY == '\x01') {
            field0008 = 0x99;
        }
        if (inputY != '\x01') {
            field0008 = 0x96;
        }
        if ((field000a == 0) && ((unsigned short)field000c == 0)) {
            meter = meter + 10;
            velocityX = -1.5;
            velocityY = 0.0;
            positionY = 0.0;
        }
        velocityY = 0.0;
        velocityX = velocityX + 0.06;
        if (velocityX > 0.0) {
            velocityX = 0.0;
        }
        if ((positionX - 20.0 <= 0.0) ||
            (639.0 <= positionX + 20.0)) {
            outgoingPushbackVelocityX = velocityX;
        }
        else {
            outgoingPushbackVelocityX = 0.0;
        }
        ++field000c;
        if ((unsigned short)field000c >= frameDuration) {
            field000c = 0;
            ++field000a;
            if (field000a == frameCount) {
                FaceOpponent();
            }
            if (field000a >= frameCount) {
                field0008 = 0;
                if (inputY == '\x01') {
                    field0008 = 3;
                }
                ResetPose();
            }
        }
        break;
    case 151:
        if (inputY == '\x01') {
            field0008 = 0x9a;
        }
        if (inputY != '\x01') {
            field0008 = 0x97;
        }
        if ((field000a == 0) && ((unsigned short)field000c == 0)) {
            meter = meter + 0xf;
            velocityX = -1.8;
            velocityY = 0.0;
            positionY = 0.0;
        }
        velocityY = 0.0;
        velocityX = velocityX + 0.06;
        if (velocityX > 0.0) {
            velocityX = 0.0;
        }
        if ((positionX - 20.0 <= 0.0) ||
            (639.0 <= positionX + 20.0)) {
            outgoingPushbackVelocityX = velocityX;
        }
        else {
            outgoingPushbackVelocityX = 0.0;
        }
        ++field000c;
        if ((unsigned short)field000c >= frameDuration) {
            field000c = 0;
            ++field000a;
            if (field000a == frameCount) {
                FaceOpponent();
            }
            if (field000a >= frameCount) {
                field0008 = 0;
                if (inputY == '\x01') {
                    field0008 = 3;
                }
                ResetPose();
            }
        }
        break;
    case 152:
        if (inputY == '\x01') {
            field0008 = 0x9b;
        }
        if (inputY != '\x01') {
            field0008 = 0x98;
        }
        if ((field000a == 0) && ((unsigned short)field000c == 0)) {
            meter = meter + 0x14;
            velocityX = -2.3;
            velocityY = 0.0;
            positionY = 0.0;
        }
        velocityY = 0.0;
        velocityX = velocityX + 0.06;
        if (velocityX > 0.0) {
            velocityX = 0.0;
        }
        if ((positionX - 20.0 <= 0.0) ||
            (639.0 <= positionX + 20.0)) {
            outgoingPushbackVelocityX = velocityX;
        }
        else {
            outgoingPushbackVelocityX = 0.0;
        }
        ++field000c;
        if ((unsigned short)field000c >= frameDuration) {
            field000c = 0;
            ++field000a;
            if (field000a == frameCount) {
                FaceOpponent();
            }
            if (field000a >= frameCount) {
                field0008 = 0;
                if (inputY == '\x01') {
                    field0008 = 3;
                }
                ResetPose();
            }
        }
        break;
    case 153:
        if (inputY == '\x01') {
            field0008 = 0x99;
        }
        if (inputY != '\x01') {
            field0008 = 0x96;
        }
        if ((field000a == 0) && ((unsigned short)field000c == 0)) {
            meter = meter + 10;
            velocityX = -1.5;
            velocityY = 0.0;
            positionY = 0.0;
        }
        velocityY = 0.0;
        velocityX = velocityX + 0.06;
        if (velocityX > 0.0) {
            velocityX = 0.0;
        }
        if ((positionX - 20.0 <= 0.0) ||
            (639.0 <= positionX + 20.0)) {
            outgoingPushbackVelocityX = velocityX;
        }
        else {
            outgoingPushbackVelocityX = 0.0;
        }
        ++field000c;
        if ((unsigned short)field000c >= frameDuration) {
            field000c = 0;
            ++field000a;
            if (field000a == frameCount) {
                FaceOpponent();
            }
            if (field000a >= frameCount) {
                field0008 = 3;
                ResetPose();
            }
        }
        break;
    case 154:
        if (inputY == '\x01') {
            field0008 = 0x9a;
        }
        if (inputY != '\x01') {
            field0008 = 0x97;
        }
        if ((field000a == 0) && ((unsigned short)field000c == 0)) {
            meter = meter + 0xf;
            velocityX = -1.8;
            velocityY = 0.0;
            positionY = 0.0;
        }
        velocityY = 0.0;
        velocityX = velocityX + 0.06;
        if (velocityX > 0.0) {
            velocityX = 0.0;
        }
        if ((positionX - 20.0 <= 0.0) ||
            (639.0 <= positionX + 20.0)) {
            outgoingPushbackVelocityX = velocityX;
        }
        else {
            outgoingPushbackVelocityX = 0.0;
        }
        ++field000c;
        if ((unsigned short)field000c >= frameDuration) {
            field000c = 0;
            ++field000a;
            if (field000a == frameCount) {
                FaceOpponent();
            }
            if (field000a >= frameCount) {
                field0008 = 3;
                ResetPose();
            }
        }
        break;
    case 155:
        if (inputY == '\x01') {
            field0008 = 0x9b;
        }
        if (inputY != '\x01') {
            field0008 = 0x98;
        }
        if ((field000a == 0) && ((unsigned short)field000c == 0)) {
            meter = meter + 0x14;
            velocityX = -2.3;
            velocityY = 0.0;
            positionY = 0.0;
        }
        velocityY = 0.0;
        velocityX = velocityX + 0.06;
        if (velocityX > 0.0) {
            velocityX = 0.0;
        }
        if ((positionX - 20.0 <= 0.0) ||
            (639.0 <= positionX + 20.0)) {
            outgoingPushbackVelocityX = velocityX;
        }
        else {
            outgoingPushbackVelocityX = 0.0;
        }
        ++field000c;
        if ((unsigned short)field000c >= frameDuration) {
            field000c = 0;
            ++field000a;
            if (field000a == frameCount) {
                FaceOpponent();
            }
            if (field000a >= frameCount) {
                field0008 = 3;
                ResetPose();
            }
        }
        break;
    case 156:
        if ((field000a == 0) && ((unsigned short)field000c == 0)) {
            velocityY = -2.6;
            meter = meter + 0xf;
            gravity = 0.06;
        }
        velocityX = -1.2;
        velocityY = velocityY + gravity;
        ++field000c;
        if ((unsigned short)field000c >= frameDuration) {
            field000c = 0;
            ++field000a;
            if (field000a >= frameCount) {
                field0008 = 9;
                ResetPose();
            }
        }
        if (0.0 <= positionY + velocityY) {
            positionY = 0.0;
            pendingContextSoundSlot = 9;
            FaceOpponent();
            field0008 = 0xd;
            ResetPose();
        }
        break;
    case 157:
        velocityX = 1.0;
        gravity = 0.045;
        if ((field000a == 0) && ((unsigned short)field000c == 0)) {
            velocityY = -2.3;
            effect.type = 8;
            effect.x = (double)(int(positionX));
            effect.y = (double)(int(positionY));
            effect.group = 2;
            effect.layer = 0;
            contextOwner->EmitEffect(&effect);
        }
        else {
            velocityY = velocityY + gravity;
        }
        ++field000c;
        if ((unsigned short)field000c >= frameDuration) {
            field000c = 0;
            ++field000a;
            if (field000a >= frameCount) {
                field0008 = 9;
                ResetPose();
            }
        }
        if (0.0 <= positionY + velocityY) {
            positionY = 0.0;
            pendingContextSoundSlot = 9;
            FaceOpponent();
            field0008 = 0xd;
            ResetPose();
        }
        break;
    case 158:
        velocityX = -1.0;
        gravity = 0.045;
        if ((field000a == 0) && ((unsigned short)field000c == 0)) {
            velocityY = -2.3;
            effect.type = 8;
            effect.x = (double)(int(positionX));
            effect.y = (double)(int(positionY));
            effect.group = 2;
            effect.layer = 0;
            contextOwner->EmitEffect(&effect);
        }
        else {
            velocityY = velocityY + gravity;
        }
        ++field000c;
        if ((unsigned short)field000c >= frameDuration) {
            field000c = 0;
            ++field000a;
            if (field000a >= frameCount) {
                field0008 = 9;
                ResetPose();
            }
        }
        if (0.0 <= positionY + velocityY) {
            positionY = 0.0;
            pendingContextSoundSlot = 9;
            FaceOpponent();
            field0008 = 0xd;
            ResetPose();
        }
        break;
    case 161:
        if ((field000a == 0) && ((unsigned short)field000c == 0)) {
            ResetFrame();
            effect.type = 9;
            effect.x = (double)(int(positionX));
            effect.y = (double)((int(positionY)) + -0x3c);
            effect.group = 2;
            effect.layer = 1;
            contextOwner->EmitEffect(&effect);
            remainingHitCount = 1;
            pendingContextSoundSlot = 0x3e;
            ++field3138;
        }
        ++field000c;
        if ((unsigned short)field000c >= frameDuration) {
            field000c = 0;
            ++field000a;
            if (field000a >= frameCount) {
                field0008 = 9;
                ResetPose();
                gravity = 0.035;
            }
        }
        break;
    case 162:
        if ((field000a == 0) && ((unsigned short)field000c == 0)) {
            ResetFrame();
        }
        if ((field000a == 3) && ((unsigned short)field000c == 0)) {
            velocityY = -1.5;
            gravity = 0.025;
            remainingHitCount = 1;
        }
        if ((field000a == 6) && ((unsigned short)field000c == 0)) {
            ResetFrame();
            effect.type = 9;
            effect.x = (double)(int(positionX));
            effect.y = (double)((int(positionY)) + -0x3c);
            effect.group = 2;
            effect.layer = 1;
            contextOwner->EmitEffect(&effect);
            remainingHitCount = 1;
            pendingContextSoundSlot = 0x3e;
            meter = meter + -1000;
            ++field3138;
        }
        velocityY = velocityY + gravity;
        if (positionY + velocityY > 0.0) {
            field0008 = 0xd;
            ResetPose();
            ResetPose();
            positionY = 0.0;
            break;
        }
        ++field000c;
        if ((unsigned short)field000c >= frameDuration) {
            field000c = 0;
            ++field000a;
            if (field000a == 0xc) {
                gravity = 0.035;
            }
            if (field000a >= frameCount) {
                field000a = field000a + -4;
            }
        }
        break;
    case 163:
        if ((field000a == 0) && ((unsigned short)field000c == 0)) {
            velocityY = 0.0;
            gravity = 0.0;
        }
        velocityY = velocityY + gravity;
        if ((field000a == 6) &&
            (velocityX = velocityX - 0.05,
            velocityX < 0.5)) {
            velocityX = 0.5;
        }
        if ((field000a == 2) && ((unsigned short)field000c == 0)) {
            velocityX = 2.5;
            velocityY = -1.6;
            gravity = 0.05;
        }
        if ((field000a == 6) && ((unsigned short)field000c == 0)) {
            gravity = 0.08;
        }
        if (positionY + velocityY > 0.0) {
            field0008 = 0xb2;
            ResetPose();
            break;
        }
        ++field000c;
        if ((unsigned short)field000c >= frameDuration) {
            field000c = 0;
            ++field000a;
            if (field000a == 6) {
                if ((int)inputX == -(int)facing) {
                    gravity = 0.08;
                    break;
                }
                ++field3138;
                if (field3138 < 7) {
                    field000a = field000a + -2;
                    ++field3138;
                }
            }
        }
        break;
    case 164:
        if ((field000a == 0) && ((unsigned short)field000c == 0)) {
            StartTrail(2);
            velocityX = 0.0;
            velocityY = 0.0;
        }
        if (field000a > 0) {
            velocityX = velocityX + 0.055;
        }
        if (velocityX > 0.0) {
            velocityX = 0.0;
        }
        if (positionY + velocityY > 0.0) {
            ResetFrame();
            positionY = 0.0;
            ResetPose();
            field0008 = 0xd;
            break;
        }
        velocityY = velocityY + gravity;
        ++field000c;
        if ((unsigned short)field000c >= frameDuration) {
            field000c = 0;
            ++field000a;
            if (field000a == 3) {
                velocityX = -3.5;
                velocityY = -1.5;
                gravity = 0.05;
            }
            if (field000a >= frameCount) {
                field000a = field000a + -4;
            }
        }
        break;
    case 165:
        if ((field000a == 0) && ((unsigned short)field000c == 0)) {
            velocityX = 1.8;
            StartTrail(3);
            velocityY = 0.0;
            gravity = 0.0;
            if (field3138 == 0) {
                pendingContextSoundSlot = 0x11;
            }
        }
        ++field000c;
        ++field3138;
        ++field313c;
        if ((unsigned short)field000c >= frameDuration) {
            field000c = 0;
            ++field000a;
            if (field000a >= frameCount) {
                field000a = field000a + -2;
            }
        }
        if ((inputX == facing) && (field313c >= 120)) {
            field0008 = 9;
            ResetPose();
            velocityX = 1.3;
            gravity = 0.03;
            if ((FaceOpponent()) != 0) {
                velocityX = -velocityX;
            }
        }
        if ((inputX != facing) && (field3138 >= 48)) {
            field0008 = 9;
            ResetPose();
            velocityX = 1.3;
            gravity = 0.03;
            if ((FaceOpponent()) != 0) {
                velocityX = -velocityX;
            }
        }
        break;
    case 166:
        if ((field000a == 0) && ((unsigned short)field000c == 0)) {
            velocityX = -1.8;
            velocityY = 0.0;
            gravity = 0.0;
            StartTrail(3);
            if (field3138 == 0) {
                pendingContextSoundSlot = 0x11;
            }
        }
        ++field000c;
        ++field3138;
        ++field313c;
        if ((unsigned short)field000c >= frameDuration) {
            field000c = 0;
            ++field000a;
            if (field000a >= frameCount) {
                field000a = field000a + -2;
            }
        }
        if (((int)inputX == -(int)facing) && (field313c >= 120)) {
            field0008 = 9;
            ResetPose();
            velocityX = -0.9;
            gravity = 0.03;
            if ((FaceOpponent()) != 0) {
                velocityX = -velocityX;
            }
        }
        if (((int)inputX != -(int)facing) && (field3138 >= 48)) {
            field0008 = 9;
            ResetPose();
            velocityX = -0.9;
            gravity = 0.03;
            if ((FaceOpponent()) != 0) {
                velocityX = -velocityX;
            }
        }
        break;
    case 167:
        if ((field000a == 0) && ((unsigned short)field000c == 0)) {
            velocityX = 0.0;
            velocityY = 0.0;
            if (field0120 == '\x01') {
                field0178 = field0118 * 5.0 + field0178
                ;
            }
            field0118 = 0.0;
            hitstunFrames = 0x5a;
            SetTint(0xb0,3);
        }
        if ((field000a == 1) && ((unsigned short)field000c == 0)) {
            pendingContextSoundSlot = 0x12;
            effect.type = 1;
            effect.x = (double)(int(positionX));
            effect.y = (double)(int(positionY));
            effect.group = 2;
            effect.layer = 1;
            contextOwner->EmitEffect(&effect);
        }
        if ((field000a == 2) && ((unsigned short)field000c == 0)) {
            effect.type = 4;
            effect.x = (double)(int(positionX));
            effect.y = (double)(int(positionY));
            effect.group = 2;
            effect.layer = 1;
            contextOwner->EmitEffect(&effect);
        }
        ++field000c;
        if ((unsigned short)field000c >= frameDuration) {
            field000c = 0;
            ++field000a;
            field0168 = 0;
            if (field000a >= frameCount) {
                field0008 = 0;
                FaceOpponent();
                ResetPose();
            }
        }
        break;
    case 168:
        if ((field000a == 0) && ((unsigned short)field000c == 0)) {
            velocityX = 0.0;
            velocityY = 0.0;
            positionY = 0.0;
            gravity = 0.0;
            guardInputFrames = 0;
            outgoingPushbackVelocityX = 0.0;
            horizontalDeceleration = 0.0;
            effect.type = 8;
            effect.x = (double)(int(positionX));
            effect.y = (double)(int(positionY));
            effect.group = 2;
            effect.layer = 1;
            contextOwner->EmitEffect(&effect);
        }
        ++field000c;
        if ((unsigned short)field000c >= frameDuration) {
            field000c = 0;
            ++field000a;
            if (field000a == frameCount) {
                FaceOpponent();
            }
            if (field000a >= frameCount) {
                field0008 = 0;
                ResetPose();
            }
        }
        break;
    case 169:
        if ((field000a == 0) && ((unsigned short)field000c == 0)) {
            velocityX = 0.0;
            velocityY = 0.0;
            positionY = 0.0;
            gravity = 0.0;
            guardInputFrames = 0;
            outgoingPushbackVelocityX = 0.0;
            horizontalDeceleration = 0.0;
            effect.type = 8;
            effect.x = (double)(int(positionX));
            effect.y = (double)(int(positionY));
            effect.group = 2;
            effect.layer = 1;
            contextOwner->EmitEffect(&effect);
        }
        ++field000c;
        if ((unsigned short)field000c >= frameDuration) {
            field000c = 0;
            ++field000a;
            if (field000a == frameCount) {
                FaceOpponent();
            }
            if (field000a >= frameCount) {
                field0008 = 3;
                ResetPose();
            }
        }
        break;
    case 170:
        if ((field000a == 0) && ((unsigned short)field000c == 0)) {
            field3138 = (int(velocityX * 100.0));
            field313c = (int(velocityY * 100.0));
            velocityX = 0.0;
            velocityY = 0.0;
            guardInputFrames = 0;
            outgoingPushbackVelocityX = 0.0;
            hitstunFrames = 0x3c;
        }
        if ((hitstunFrames == 0) && (field3140 == 0)) {
            ++field3140;
            velocityX = (double)field3138 * 0.01;
            velocityY = (double)field313c * 0.01;
        }
        if (hitstunFrames == 0) {
            velocityY = velocityY + gravity;
        }
        if (velocityY + positionY > 0.0) {
            ResetFrame();
            positionY = 0.0;
            field0008 = 0xa9;
            break;
        }
        ++field000c;
        if ((unsigned short)field000c >= frameDuration) {
            field000c = 0;
            ++field000a;
            if (field000a >= frameCount) {
                field0008 = 9;
                ResetPose();
            }
        }
        break;
    case 171:
        if ((field000a == 0) && ((unsigned short)field000c == 0)) {
            field3138 = (int(velocityX * 100.0));
            field313c = (int(velocityY * 100.0));
            velocityX = 0.0;
            velocityY = 0.0;
            if (gravity == 0.0) {
                gravity = 0.035;
            }
            if (field0120 == '\x01') {
                field0178 = field0118 * 5.0 + field0178
                ;
            }
            field0118 = 0.0;
            hitstunFrames = 0x5a;
            SetTint(0xb0,3);
        }
        if ((field000a == 0) && ((unsigned short)field000c == 0)) {
            pendingContextSoundSlot = 0x12;
            effect.type = 1;
            effect.x = (double)(int(positionX));
            effect.y = (double)(int(positionY));
            effect.group = 2;
            effect.layer = 1;
            contextOwner->EmitEffect(&effect);
        }
        ++field000c;
        if ((unsigned short)field000c >= frameDuration) {
            field000c = 0;
            ++field000a;
            field0168 = 0;
            if (field000a >= frameCount) {
                field0008 = 9;
                velocityX = (double)field3138 * 0.01;
                velocityY = (double)field313c * 0.01;
                if (gravity == 0.0) {
                    gravity = 0.035;
                }
                ResetPose();
            }
        }
        break;
    case 178:
        velocityX = velocityX - 0.08;
        if (velocityX < 0.0) {
            velocityX = 0.0;
        }
        ++field000c;
        if ((unsigned short)field000c >= frameDuration) {
            field000c = 0;
            ++field000a;
            if (field000a >= frameCount) {
                field0008 = 7;
                if (inputY == '\x01') {
                    field0008 = 3;
                }
                ResetPose();
                break;
            }
        }
        break;
    case 180:
        if ((field000a == 0) && ((unsigned short)field000c == 0)) {
            StartTrail(2);
            velocityX = 0.0;
            velocityY = 0.0;
            gravity = 0.0;
        }
        if (positionY < 0.0) {
            velocityY = velocityY + gravity;
        }
        if ((0.0 < positionY + velocityY) &&
            (field000a < 0xc)) {
            ResetFrame();
            positionY = 0.0;
            field000c = 0;
            field000a = 0xc;
            pendingContextSoundSlot = 9;
        }
        ++field000c;
        if ((unsigned short)field000c >= frameDuration) {
            field000c = 0;
            ++field000a;
            if (field000a == 3) {
                velocityX = -0.5;
                velocityY = -1.0;
                gravity = 0.028;
            }
            if (field000a == 0xc) {
                field000a = field000a + -4;
            }
            if (field000a >= frameCount) {
                ResetPose();
                field0008 = 0;
            }
        }
        break;
    case 200:
        velocityX = 0.0;
        velocityY = 0.0;
        if ((((inputY == -1) && (field000a > 0)) &&
            (field015c < 3)) && (field0168 >= 2)) {
            field0008 = 4;
            if (inputX == facing) {
                field0008 = 5;
            }
            if ((int)inputX == -(int)facing) {
                field0008 = 6;
            }
            field0168 = 0;
            ResetPose();
            break;
        }
        if ((field000a == 1) && ((unsigned short)field000c == 0)) {
            meter = meter + 5;
            pendingContextSoundSlot = 0x15;
            remainingHitCount = 1;
        }
        ++field000c;
        if ((unsigned short)field000c >= frameDuration) {
            field000c = 0;
            ++field000a;
            if (field000a < 3) {
                field0168 = 0;
            }
            if (field000a >= frameCount) {
                field0008 = 0;
                FaceOpponent();
                ResetPose();
            }
        }
        break;
    case 201:
        if ((((inputY == -1) && (field000a > 0)) &&
            (field015c < 3)) && (field0168 >= 2)) {
            field0008 = 4;
            if (inputX == facing) {
                field0008 = 5;
            }
            if ((int)inputX == -(int)facing) {
                field0008 = 6;
            }
            field0168 = 0;
            ResetPose();
            break;
        }
        if ((field000a == 0) && ((unsigned short)field000c == 0)) {
            velocityX = 0.0;
            velocityY = 0.0;
        }
        if ((field000a == 2) && ((unsigned short)field000c == 0)) {
            meter = meter + 0xf;
            pendingContextSoundSlot = 0x14;
            remainingHitCount = 1;
        }
        ++field000c;
        if ((unsigned short)field000c >= frameDuration) {
            field000c = 0;
            ++field000a;
            if (field000a < 4) {
                field0168 = 0;
            }
            if (field000a >= frameCount) {
                field0008 = 0;
                FaceOpponent();
                ResetPose();
            }
        }
        break;
    case 202:
        velocityX = velocityX - 0.02;
        if (velocityX <= 0.0) {
            velocityX = 0.0;
        }
        if ((field000a == 0) && ((unsigned short)field000c == 0)) {
            velocityX = 0.0;
            velocityY = 0.0;
        }
        if ((field000a == 2) && ((unsigned short)field000c == 0)) {
            meter = meter + 0xf;
            pendingContextSoundSlot = 0x14;
            remainingHitCount = 1;
            velocityX = 1.2;
        }
        ++field000c;
        if ((unsigned short)field000c >= frameDuration) {
            field000c = 0;
            ++field000a;
            if (field000a < 4) {
                field0168 = 0;
            }
            if (field000a >= frameCount) {
                field0008 = 0;
                FaceOpponent();
                ResetPose();
            }
        }
        break;
    case 203:
        if ((field000a == 0) && ((unsigned short)field000c == 0)) {
            velocityX = 0.0;
            velocityY = 0.0;
            remainingHitCount = 2;
        }
        if ((field000a == 1) && ((unsigned short)field000c == 0)) {
            meter = meter + 0x23;
            pendingContextSoundSlot = 0x14;
        }
        ++field000c;
        if ((unsigned short)field000c >= frameDuration) {
            field000c = 0;
            ++field000a;
            if (field000a < 6) {
                field0168 = 0;
            }
            if (field000a >= frameCount) {
                field0008 = 0;
                FaceOpponent();
                ResetPose();
            }
        }
        break;
    case 204:
        velocityX = 0.0;
        velocityY = 0.0;
        if ((((inputY == -1) && (field000a > 0)) &&
            (field015c < 3)) && (field0168 >= 2)) {
            field0008 = 4;
            if (inputX == facing) {
                field0008 = 5;
            }
            if ((int)inputX == -(int)facing) {
                field0008 = 6;
            }
            field0168 = 0;
            ResetPose();
            break;
        }
        if ((field000a == 1) && ((unsigned short)field000c == 0)) {
            meter = meter + 5;
            pendingContextSoundSlot = 0x15;
            remainingHitCount = 1;
        }
        ++field000c;
        if ((unsigned short)field000c >= frameDuration) {
            field000c = 0;
            ++field000a;
            if (field000a < 3) {
                field0168 = 0;
            }
            if (field000a >= frameCount) {
                field0008 = 0;
                if (inputY == '\x01') {
                    field0008 = 3;
                }
                FaceOpponent();
                ResetPose();
            }
        }
        break;
    case 205:
        if ((field000a == 0) && ((unsigned short)field000c == 0)) {
            ResetFrame();
        }
        if ((((inputY == -1) && (field000a > 0)) &&
            (field015c < 3)) && (field0168 >= 2)) {
            field0008 = 4;
            if (inputX == facing) {
                field0008 = 5;
            }
            if ((int)inputX == -(int)facing) {
                field0008 = 6;
            }
            field0168 = 0;
            ResetPose();
            break;
        }
        if ((field000a == 2) && ((unsigned short)field000c == 0)) {
            meter = meter + 0xd;
            pendingContextSoundSlot = 0x14;
            remainingHitCount = 1;
        }
        if ((velocityX > 0.0) &&
            (velocityX = velocityX - 0.025,
            velocityX < 0.0)) {
            velocityX = 0.0;
        }
        ++field000c;
        if ((unsigned short)field000c >= frameDuration) {
            field000c = 0;
            ++field000a;
            if (field000a == 3) {
                velocityX = 1.5;
            }
            if ((field000a == 6) && (field3138 < 1)) {
                field000a = field000a + -2;
                ++field3138;
            }
            if (field000a < 2) {
                field0168 = 0;
            }
            if (field000a >= frameCount) {
                field0008 = 0;
                if (inputY == '\x01') {
                    field0008 = 3;
                }
                FaceOpponent();
                ResetPose();
            }
        }
        break;
    case 206:
        if ((field000a == 0) && ((unsigned short)field000c == 0)) {
            ResetFrame();
        }
        if ((field000a == 3) && ((unsigned short)field000c == 0)) {
            meter = meter + 0x19;
            velocityX = 3.0;
        }
        if (1 < field000a) {
            velocityX = velocityX - 0.07;
            if (velocityX < 0.0) {
                velocityX = 0.0;
            }
            if (velocityX == 0.0) {
                remainingHitCount = 0;
            }
        }
        ++field000c;
        if ((unsigned short)field000c >= frameDuration) {
            field000c = 0;
            ++field000a;
            field0168 = 0;
            if (field000a == 3) {
                pendingContextSoundSlot = 0x14;
                remainingHitCount = 1;
            }
            if (field000a >= frameCount) {
                field0008 = 0;
                if (inputY == '\x01') {
                    field0008 = 3;
                }
                FaceOpponent();
                ResetPose();
            }
        }
        break;
    case 207:
        velocityY = velocityY + gravity;
        if ((((inputY == -1) && (field000a > 0)) &&
            (field015c < 3)) && ((field0168 >= 2 && (field015a < 1)))) {
            field0008 = 0xe;
            ++field015a;
            if (inputX == facing) {
                field0008 = 0xf;
            }
            if ((int)inputX == -(int)facing) {
                field0008 = 0x10;
            }
            field0168 = 0;
            ResetPose();
            break;
        }
        if ((field000a == 1) && ((unsigned short)field000c == 0)) {
            meter = meter + 5;
            pendingContextSoundSlot = 0x15;
            remainingHitCount = 1;
        }
        if (positionY + velocityY >= 0.0) {
            positionY = 0.0;
            field0008 = 0xd;
            ResetPose();
            break;
        }
        ++field000c;
        if ((unsigned short)field000c >= frameDuration) {
            field000c = 0;
            ++field000a;
            if (field000a < 3) {
                field0168 = 0;
            }
            if (field000a >= frameCount) {
                ResetPose();
                field0008 = 9;
            }
        }
        break;
    case 208:
        velocityY = velocityY + gravity;
        if (((inputY == -1) && (field000a > 0)) &&
            ((field015c < 3 && ((field0168 >= 2 && (field015a < 1)))))) {
            ++field015a;
            field0008 = 0xe;
            if (inputX == facing) {
                field0008 = 0xf;
            }
            if ((int)inputX == -(int)facing) {
                field0008 = 0x10;
            }
            field0168 = 0;
            ResetPose();
            break;
        }
        if ((field000a == 3) && ((unsigned short)field000c == 0)) {
            meter = meter + 0xd;
            remainingHitCount = 1;
            pendingContextSoundSlot = 0x14;
        }
        if (positionY + velocityY >= 0.0) {
            positionY = 0.0;
            field0008 = 0xd;
            ResetPose();
            break;
        }
        ++field000c;
        if ((unsigned short)field000c >= frameDuration) {
            field000c = 0;
            ++field000a;
            if (field000a < 2) {
                field0168 = 0;
            }
            if (field000a >= frameCount) {
                field0008 = 9;
                ResetPose();
            }
        }
        break;
    case 209:
        velocityY = velocityY + gravity;
        if ((((inputY == -1) && (field000a > 0)) &&
            (field015c < 3)) && ((field0168 >= 2 && (field015a < 1)))) {
            ++field015a;
            field0008 = 0xe;
            if (inputX == facing) {
                field0008 = 0xf;
            }
            if ((int)inputX == -(int)facing) {
                field0008 = 0x10;
            }
            field0168 = 0;
            ResetPose();
            break;
        }
        if ((field000a == 4) && ((unsigned short)field000c == 0)) {
            meter = meter + 0x1e;
            pendingContextSoundSlot = 0x14;
            remainingHitCount = 1;
        }
        if (positionY + velocityY >= 0.0) {
            positionY = 0.0;
            field0008 = 0xd;
            ResetPose();
            break;
        }
        ++field000c;
        if ((unsigned short)field000c >= frameDuration) {
            field000c = 0;
            ++field000a;
            if (field000a < 4) {
                field0168 = 0;
            }
            if (field000a >= frameCount) {
                field0008 = 9;
                ResetPose();
            }
        }
        break;
    case 210:
        if (velocityX <= 0.0) {
            velocityX = 0.0;
        }
        if ((field000a == 0) && ((unsigned short)field000c == 0)) {
            velocityX = 0.0;
            velocityY = 0.0;
        }
        if (positionY < 0.0 && (velocityY = velocityY + gravity, positionY + velocityY > 0.0)) {
            positionY = 0.0;
            velocityY = 0.0;
            field000c = 0;
            field000a = 5;
            break;
        }
        if ((4 < field000a) &&
            (velocityX = velocityX - 0.036,
            velocityX < 0.0)) {
            velocityX = 0.0;
        }
        if ((field000a == 2) && ((unsigned short)field000c == 0)) {
            meter = meter + 0xf;
            pendingContextSoundSlot = 0x14;
            remainingHitCount = 1;
        }
        ++field000c;
        if ((unsigned short)field000c >= frameDuration) {
            field000c = 0;
            ++field000a;
            if (field000a == 1) {
                velocityX = 1.0;
                velocityY = -2.6;
                gravity = 0.065;
            }
            if (field000a < 4) {
                field0168 = 0;
            }
            if (field000a >= frameCount) {
                field0008 = 0;
                FaceOpponent();
                ResetPose();
            }
        }
        break;
    case 211:
        if ((field000a == 0) && ((unsigned short)field000c == 0)) {
            ResetFrame();
        }
        if (((inputY == -1) && (field000a > 0)) &&
            ((field015c < 3 && (field0168 >= 2)))) {
            field0008 = 4;
            if (inputX == facing) {
                field0008 = 5;
            }
            if ((int)inputX == -(int)facing) {
                field0008 = 6;
            }
            field0168 = 0;
            ResetPose();
            break;
        }
        if ((field000a == 2) && ((unsigned short)field000c == 0)) {
            meter = meter + 0xd;
            pendingContextSoundSlot = 0x14;
            remainingHitCount = 1;
        }
        ++field000c;
        if ((unsigned short)field000c >= frameDuration) {
            field000c = 0;
            ++field000a;
            if (field000a < 2) {
                field0168 = 0;
            }
            if (field000a >= frameCount) {
                field0008 = 0;
                if (inputY == '\x01') {
                    field0008 = 3;
                }
                FaceOpponent();
                ResetPose();
            }
        }
        break;
    case 220:
        velocityX = 0.0;
        velocityY = 0.0;
        if ((field000a == 1) && (field0168 == 3)) {
            ResetFrame();
            ResetPose();
            (*opponentSlot)->ResetFrame();
            (*opponentSlot)->ResetPose();
            field0008 = 0xdd;
            (*opponentSlot)->field0008 = 0x6b;
            effect.type = 0;
            effect.x = (double)((int(positionX)) + facing * 0x25);
            effect.y = (double)((int(positionY)) + -0x30);
            effect.group = 2;
            effect.layer = 1;
            contextOwner->EmitEffect(&effect);
            break;
        }
        ++field000c;
        if ((unsigned short)field000c >= frameDuration) {
            field000c = 0;
            ++field000a;
            field0168 = 0;
            if (((field000a == 1) && ((unsigned short)field000c == 0)) &&
                ((*opponentSlot)->positionY == 0.0)) {
                remainingHitCount = 1;
            }
            else {
                remainingHitCount = 0;
            }
            if (field000a >= frameCount) {
                field0008 = 0;
                FaceOpponent();
                ResetPose();
            }
        }
        break;
    case 221:
        if ((field000a == 0) && ((unsigned short)field000c == 0)) {
            positionX =
            (*opponentSlot)->positionX -
            (double)((int)(*opponentSlot)->field2ad0[0] * (int)facing);
            positionY = (double)((*opponentSlot)->field2af8[0] + 0x1e);
        }
        if ((field000a == 3) && ((unsigned short)field000c == 0)) {
            (*opponentSlot)->field0008 = 0x3b;
            (*opponentSlot)->ResetPose();
            (*opponentSlot)->knockbackVelocityX = -2.5;
            (*opponentSlot)->knockbackVelocityY = -1.0;
            (*opponentSlot)->gravity = 0.035;
            velocityX = -1.8;
            velocityY = -1.9;
            gravity = 0.04;
            effect.type = 0;
            effect.palette = 2;
            effect.x = (double)(int(positionX));
            effect.y = (double)((int(positionY)) + -0x2d);
            effect.group = 2;
            effect.layer = 1;
            contextOwner->EmitEffect(&effect);
            ApplyDamage(1000,750.0);
        }
        if (2 < field000a) {
            velocityY = velocityY + gravity;
        }
        ++field000c;
        if ((unsigned short)field000c >= frameDuration) {
            field000c = 0;
            ++field000a;
            field0168 = 0;
            if (field000a >= frameCount) {
                field0008 = 9;
                FaceOpponent();
                ResetPose();
            }
        }
        break;
    case 230:
        velocityY = velocityY + gravity;
        StartTrail(3);
        if ((((inputY == -1) && (field000a > 0)) &&
            (field015c < 3)) && ((field0168 >= 2 && (field015a < 1)))) {
            ++field015a;
            field0008 = 0xe;
            if (inputX == facing) {
                field0008 = 0xf;
            }
            if ((int)inputX == -(int)facing) {
                field0008 = 0x10;
            }
            field0168 = 0;
            ResetPose();
            break;
        }
        if ((field000a == 0) && ((unsigned short)field000c == 0)) {
            velocityX = 0.5;
        }
        if ((field000a == 1) && ((unsigned short)field000c == 0)) {
            meter = meter + 5;
            pendingContextSoundSlot = 0x15;
            remainingHitCount = 1;
        }
        if (positionY + velocityY >= 0.0) {
            positionY = 0.0;
            field0008 = 0xe9;
            ResetPose();
            field000a = 2;
            break;
        }
        ++field000c;
        if ((unsigned short)field000c >= frameDuration) {
            field000c = 0;
            ++field000a;
            if (field000a < 3) {
                field0168 = 0;
            }
            if (field000a >= frameCount) {
                field0008 = 10;
                ResetPose();
            }
        }
        break;
    case 231:
        velocityY = velocityY + gravity;
        StartTrail(3);
        if ((((inputY == -1) && (field000a > 0)) &&
            (field015c < 3)) && ((field0168 >= 2 && (field015a < 1)))) {
            ++field015a;
            field0008 = 0xe;
            if (inputX == facing) {
                field0008 = 0xf;
            }
            if ((int)inputX == -(int)facing) {
                field0008 = 0x10;
            }
            field0168 = 0;
            ResetPose();
            break;
        }
        if ((field000a == 0) && ((unsigned short)field000c == 0)) {
            velocityX = 0.5;
        }
        if ((field000a == 1) && ((unsigned short)field000c == 0)) {
            meter = meter + 0xd;
            remainingHitCount = 2;
            pendingContextSoundSlot = 0x14;
        }
        if (positionY + velocityY >= 0.0) {
            positionY = 0.0;
            field0008 = 0xe9;
            ResetPose();
            field000a = 1;
            break;
        }
        ++field000c;
        if ((unsigned short)field000c >= frameDuration) {
            field000c = 0;
            ++field000a;
            if (field000a < 5) {
                field0168 = 0;
            }
            if (field000a >= frameCount) {
                field0008 = 10;
                ResetPose();
            }
        }
        break;
    case 232:
        velocityY = velocityY + gravity;
        StartTrail(3);
        if ((((inputY == -1) && (field000a > 0)) &&
            (field015c < 3)) && ((field0168 >= 2 && (field015a < 1)))) {
            ++field015a;
            field0008 = 0xe;
            if (inputX == facing) {
                field0008 = 0xf;
            }
            if ((int)inputX == -(int)facing) {
                field0008 = 0x10;
            }
            field0168 = 0;
            ResetPose();
            break;
        }
        if ((field000a == 0) && ((unsigned short)field000c == 0)) {
            velocityX = 0.5;
        }
        if ((field000a == 1) && ((unsigned short)field000c == 0)) {
            meter = meter + 10;
            pendingContextSoundSlot = 0x14;
            remainingHitCount = 1;
        }
        if (positionY + velocityY >= 0.0) {
            positionY = 0.0;
            field0008 = 0xe9;
            ResetPose();
            field000a = 1;
            break;
        }
        ++field000c;
        if ((unsigned short)field000c >= frameDuration) {
            field000c = 0;
            ++field000a;
            if (field000a < 4) {
                field0168 = 0;
            }
            if (field000a >= frameCount) {
                field0008 = 10;
                ResetPose();
            }
        }
        break;
    case 233:
        velocityX = 0.0;
        velocityY = 0.0;
        FaceOpponent();
        ++field000c;
        if ((unsigned short)field000c >= frameDuration) {
            field000c = 0;
            field0168 = 3;
            ++field000a;
            if (field000a >= frameCount) {
                field0008 = 7;
                if (inputY == '\x01') {
                    field0008 = 3;
                }
                ResetPose();
            }
        }
        break;
    case 248:
        velocityY = velocityY + gravity;
        if ((field000a == 2) && (field0168 == 3)) {
            (*opponentSlot)->ResetFrame();
            (*opponentSlot)->ResetPose();
            (*opponentSlot)->field0128 = 1;
            effect.type = 0;
            effect.x = (double)((int(positionX)) + facing * 0x16);
            effect.y = (double)((int(positionY)) + -0x36);
            effect.group = 2;
            effect.layer = 1;
            contextOwner->EmitEffect(&effect);
            field000a = 0;
            field000c = 0;
            field0008 = 0xf9;
            (*opponentSlot)->field0008 = 0x67;
            (*opponentSlot)->positionX =
            (double)(facing * 0x16) + positionX;
            (*opponentSlot)->positionY = positionY - 52.0;
            break;
        }
        ++field000c;
        if ((unsigned short)field000c >= frameDuration) {
            field000c = 0;
            ++field000a;
            if (field000a == 2 && (*opponentSlot)->positionY < 0.0 &&
                ((*opponentSlot)->field0008 < 50 || (*opponentSlot)->field0008 > 149)) {
                remainingHitCount = 1;
            } else { remainingHitCount = 0; }
            field0168 = 0;
            if (field000a >= frameCount) {
                field0008 = 0xd1;
                field000a = 2;
            }
        }
        break;
    case 249:
        field013e = 2;
        if (field000a < 0xb) {
            if ((positionX > 6100.0) && (facing == '\x01')) {
                positionX = 6100.0;
                velocityX = 0.0;
            }
            if ((positionX < 30.0) && (facing == -1)) {
                positionX = 30.0;
                velocityX = 0.0;
            }
            SetHorizontalOffset(0x32,3);
            SetHorizontalShake(0x32,3);
        }
        if (((field000a < 10) ||
            ((0xb < field000a && (field000a < 0xf)))) &&
            (velocityY = velocityY + gravity,
            0.0 < velocityY + positionY)) {
            if (field000a < 10) {
                positionY = 0.0;
                ResetFrame();
                (*opponentSlot)->ResetPose();
                (*opponentSlot)->field0008 = 0x62;
                (*opponentSlot)->positionY = 0;
                (*opponentSlot)->positionX =
                (double)(int)facing + positionX;
                (*opponentSlot)->facing = -facing;
                (*opponentSlot)->ResetFrame();
                ApplyDamage(1000,500.0);
                effect.type = 0;
                effect.x = (double)(int(positionX));
                effect.y = (double)(int(positionY));
                effect.group = 2;
                effect.layer = 1;
                contextOwner->EmitEffect(&effect);
                field000c = 0;
                field000a = 10;
                pendingContextSoundSlot = 2;
                return;
            }
            if (field000a == 0xe) {
                positionY = 0.0;
                ResetFrame();
                field000c = 0;
                field000a = 0xf;
                return;
            }
        }
        if (field000a < 1) {
            (*opponentSlot)->field0008 = 0x67;
            (*opponentSlot)->positionX =
            (double)(facing * 0x16) + positionX;
            (*opponentSlot)->positionY = positionY - 52.0;
        }
        if (field000a == 1) {
            (*opponentSlot)->field0008 = 0x67;
            (*opponentSlot)->positionX =
            (15.0 + velocityX) * facing +
            positionX;
            (*opponentSlot)->positionY =
            -70.0 + velocityY + positionY;
        }
        if (field000a == 2) {
            (*opponentSlot)->field0008 = 0x76;
            (*opponentSlot)->positionX =
            (-25.0 + velocityX) * facing +
            positionX;
            (*opponentSlot)->positionY =
            -65.0 + velocityY + positionY;
            (*opponentSlot)->facing = facing;
        }
        if (field000a == 3) {
            (*opponentSlot)->field0008 = 0x75;
            (*opponentSlot)->positionX =
            (-28.0 + velocityX) * facing +
            positionX;
            (*opponentSlot)->positionY =
            -43.0 + velocityY + positionY;
            (*opponentSlot)->facing = facing;
        }
        if (field000a == 4) {
            (*opponentSlot)->field0008 = 0x75;
            (*opponentSlot)->positionX =
            (-12.0 + velocityX) * facing +
            positionX;
            (*opponentSlot)->positionY =
            -29.0 + velocityY + positionY;
            (*opponentSlot)->facing = facing;
        }
        if (field000a == 5) {
            (*opponentSlot)->field0008 = 0x68;
            (*opponentSlot)->positionX =
            (12.0 + velocityX) * facing +
            positionX;
            (*opponentSlot)->positionY =
            -23.0 + velocityY + positionY;
            (*opponentSlot)->facing = -facing;
        }
        if (field000a == 6) {
            (*opponentSlot)->field0008 = 0x68;
            (*opponentSlot)->positionX =
            (23.0 + velocityX) * facing +
            positionX;
            (*opponentSlot)->positionY =
            -36.0 + velocityY + positionY;
            (*opponentSlot)->facing = -facing;
        }
        if (field000a == 7) {
            (*opponentSlot)->field0008 = 0x67;
            (*opponentSlot)->positionX =
            (28.0 + velocityX) * facing +
            positionX;
            (*opponentSlot)->positionY =
            -58.0 + velocityY + positionY;
            (*opponentSlot)->facing = -facing;
        }
        if (field000a == 8) {
            (*opponentSlot)->field0008 = 0x67;
            (*opponentSlot)->positionX =
            (14.0 + velocityX) * facing +
            positionX;
            (*opponentSlot)->positionY =
            -73.0 + velocityY + positionY;
            (*opponentSlot)->facing = -facing;
        }
        if (field000a == 9) {
            (*opponentSlot)->field0008 = 0x76;
            (*opponentSlot)->positionX =
            (-12.0 + velocityX) * facing +
            positionX;
            (*opponentSlot)->positionY =
            -78.0 + velocityY + positionY;
            (*opponentSlot)->facing = facing;
        }
        ++field000c;
        if ((unsigned short)field000c >= frameDuration) {
            field000c = 0;
            ++field000a;
            field0168 = 0;
            if (field000a == 10) {
                field000a = field000a + -8;
            }
            if (field000a == 0xc) {
                velocityX = -0.8;
                velocityY = -1.0;
                gravity = 0.035;
            }
            if (field000a >= frameCount) {
                ResetPose();
                FaceOpponent();
                field0008 = 3;
            }
        }
        break;
    case 250:
        if ((field000a == 0) && ((unsigned short)field000c == 0)) {
            ResetFrame();
            remainingHitCount = 0;
        }
        if (field000a > 2 && field000a < 8 && field0168 == 3) {
            (*opponentSlot)->ResetPose();
            (*opponentSlot)->ResetFrame();
            (*opponentSlot)->field0008 = 0x6b;
            ResetPose();
            field0008 = 0xfd;
            positionY = (double)(field2af8[0] + 0x32);
            positionX =
            (*opponentSlot)->positionX + (-field2ad0[0] - 0x14) * facing;
            effect.type = 0;
            effect.x = (double)((int(positionX)) + facing * 7);
            effect.y = (double)((int(positionY)) + -0x2c);
            effect.group = 2;
            effect.layer = 1;
            contextOwner->EmitEffect(&effect);
            break;
        }
        if ((2 < field000a) && (field000a < 8)) {
            if ((*opponentSlot)->positionY == 0.0) {
                remainingHitCount = 1;
            }
            else {
                remainingHitCount = 0;
            }
        }
        if (field000a == 6) {
            field3140 = 1;
        }
        if ((7 < field000a) &&
            (velocityX = velocityX - 0.035,
            velocityX < 0.0)) {
            velocityX = 0.0;
        }
        ++field000c;
        if ((unsigned short)field000c >= frameDuration) {
            field000c = 0;
            ++field000a;
            field0168 = 0;
            if (field000a == 1) {
                remainingHitCount = 0;
            }
            if (field000a == 3) {
                velocityX = 1.8;
            }
            if (field000a == 8) {
                field000a = 3;
                ++field3138;
            }
            if ((field000a == 6) && (1 < field3138)) {
                field000a = 8;
            }
            if (field000a >= frameCount) {
                ResetPose();
                field0008 = 3;
                FaceOpponent();
            }
        }
        break;
    case 251:
        if ((field000a == 0) && ((unsigned short)field000c == 0)) {
            ResetFrame();
            remainingHitCount = 0;
        }
        if (field000a > 2 && field000a < 8 && field0168 == 3) {
            (*opponentSlot)->ResetPose();
            (*opponentSlot)->ResetFrame();
            (*opponentSlot)->field0008 = 0x6b;
            ResetPose();
            field0008 = 0xfd;
            positionY = (double)(field2af8[0] + 0x32);
            positionX =
            (*opponentSlot)->positionX + (-field2ad0[0] - 0x14) * facing;
            effect.type = 0;
            effect.x = (double)((int(positionX)) + facing * 7);
            effect.y = (double)((int(positionY)) + -0x2c);
            effect.group = 2;
            effect.layer = 1;
            contextOwner->EmitEffect(&effect);
            break;
        }
        if (((2 < field000a) && (field000a < 8)) &&
            (0 < field3140)) {
            if ((*opponentSlot)->positionY == 0.0) {
                remainingHitCount = 1;
            }
            else {
                remainingHitCount = 0;
            }
        }
        if (field000a == 6) {
            field3140 = 1;
        }
        if ((7 < field000a) &&
            (velocityX = velocityX - 0.035,
            velocityX < 0.0)) {
            velocityX = 0.0;
        }
        ++field000c;
        if ((unsigned short)field000c >= frameDuration) {
            field000c = 0;
            ++field000a;
            field0168 = 0;
            if (field000a == 1) {
                remainingHitCount = 0;
            }
            if (field000a == 3) {
                velocityX = 2.4;
            }
            if (field000a == 8) {
                field000a = 3;
                ++field3138;
            }
            if ((field000a == 6) && (2 < field3138)) {
                field000a = 8;
            }
            if (field000a >= frameCount) {
                ResetPose();
                field0008 = 3;
                FaceOpponent();
            }
        }
        break;
    case 252:
        if ((field000a == 0) && ((unsigned short)field000c == 0)) {
            remainingHitCount = 0;
            ResetFrame();
            if (field0120 == '\0') {
                field0118 = field0118 - 500.0;
            }
            else {
                field0118 = field0118 - 250.0;
            }
            effect.type = 0x21;
            effect.palette = 0xb;
            effect.x = (double)((int(positionX)) + facing * 0x14);
            effect.y = (double)((int(positionY)) + -0x32);
            effect.group = 2;
            effect.layer = 1;
            contextOwner->EmitEffect(&effect);
        }
        if (field000a > 2 && field000a < 8 && field0168 == 3) {
            (*opponentSlot)->ResetPose();
            (*opponentSlot)->ResetFrame();
            (*opponentSlot)->field0008 = 0x6b;
            ResetPose();
            ResetFrame();
            field0008 = 0xfe;
            positionY = (double)(field2af8[0] + 0x32);
            positionX =
            (*opponentSlot)->positionX + (-field2ad0[0] - 0x14) * facing;
            effect.type = 0;
            effect.x = (double)((int(positionX)) + facing * 7);
            effect.y = (double)((int(positionY)) + -0x2c);
            effect.group = 2;
            effect.layer = 1;
            contextOwner->EmitEffect(&effect);
            break;
        }
        if ((2 < field000a) && (field000a < 8)) {
            if ((*opponentSlot)->positionY == 0.0) {
                remainingHitCount = 1;
            }
            else {
                remainingHitCount = 0;
            }
        }
        if (field000a == 6) {
            field3140 = 1;
        }
        if ((7 < field000a) &&
            (velocityX = velocityX - 0.035,
            velocityX < 0.0)) {
            velocityX = 0.0;
        }
        ++field000c;
        if ((unsigned short)field000c >= frameDuration) {
            field000c = 0;
            ++field000a;
            field0168 = 0;
            if (field000a == 1) {
                remainingHitCount = 0;
            }
            if (field000a == 3) {
                velocityX = 1.8;
            }
            if (field000a == 8) {
                field000a = 3;
                ++field3138;
            }
            if ((field000a == 6) && (1 < field3138)) {
                field000a = 8;
            }
            if (field000a >= frameCount) {
                ResetPose();
                field0008 = 3;
                FaceOpponent();
            }
        }
        break;
    case 253:
        if (field000a < 3) {
            velocityX = velocityX - 0.035;
            if (velocityX < 0.0) {
                velocityX = 0.0;
            }
            if (((*opponentSlot)->CollisionSide()) != '\0') {
                ResetFrame();
                (*opponentSlot)->ResetFrame();
            }
            if (((*opponentSlot)->CollisionSide()) == '\0') {
                (*opponentSlot)->positionX =
                (double)((field2ad0[0] + 0x14) * (int)facing) +
                positionX;
            }
        }
        if (field000a == 3) {
            (*opponentSlot)->field0008 = 0x76;
            (*opponentSlot)->positionX =
            (15.0 + velocityX) * facing +
            positionX;
            (*opponentSlot)->positionY =
            -69.0 + velocityY + positionY;
        }
        if (2 < field000a) {
            velocityY = velocityY + gravity;
        }
        if (field000a > 3 && velocityY + positionY > 0.0) {
            ResetPose();
            ResetFrame();
            field0008 = 3;
            positionY = 0.0;
            break;
        }
        if ((field000a == 4) && ((unsigned short)field000c == 0)) {
            (*opponentSlot)->ResetPose();
            (*opponentSlot)->field0008 = 0x3f;
            (*opponentSlot)->positionX =
            (-31.0 + velocityX) * facing +
            positionX;
            (*opponentSlot)->positionY =
            -33.0 + velocityY + positionY;
            ApplyDamage(500,750.0);
            --field0174;
            --field00f4;
            (*opponentSlot)->knockbackVelocityX = 0.8;
            (*opponentSlot)->knockbackVelocityY = -3.2;
        }
        if (field000a < 4) {
            SetHorizontalOffset(0x32,3);
            SetHorizontalShake(0x32,3);
        }
        ++field000c;
        if ((unsigned short)field000c >= frameDuration) {
            field000c = 0;
            ++field000a;
            field0168 = 3;
            if (field000a == 3) {
                velocityX = -1.0;
                velocityY = -1.3;
                gravity = 0.03;
            }
            if (field000a >= frameCount) {
                field0008 = 0;
                ResetPose();
            }
        }
        break;
    case 254:
        if (field000a < 3) {
            velocityX = velocityX - 0.035;
            if (velocityX < 0.0) {
                velocityX = 0.0;
            }
            if (((*opponentSlot)->CollisionSide()) != '\0') {
                ResetFrame();
                (*opponentSlot)->ResetFrame();
            }
            if (((*opponentSlot)->CollisionSide()) == '\0') {
                (*opponentSlot)->positionX =
                (double)((field2ad0[0] + 0x14) * (int)facing) +
                positionX;
            }
        }
        if (field000a == 3) {
            (*opponentSlot)->field0008 = 0x76;
            (*opponentSlot)->positionX =
            (15.0 + velocityX) * facing +
            positionX;
            (*opponentSlot)->positionY =
            -69.0 + velocityY + positionY;
        }
        if (2 < field000a) {
            velocityY = velocityY + gravity;
        }
        if (field000a > 3 && velocityY + positionY > 0.0) {
            ResetPose();
            ResetFrame();
            field0008 = 3;
            positionY = 0.0;
            break;
        }
        if ((field000a == 4) && ((unsigned short)field000c == 0)) {
            (*opponentSlot)->ResetPose();
            (*opponentSlot)->field0008 = 0x43;
            (*opponentSlot)->positionX =
            (-41.0 + velocityX) * facing +
            positionX;
            (*opponentSlot)->positionY =
            -43.0 + velocityY + positionY;
            ApplyDamage(1000,800.0);
            --field0174;
            --field00f4;
            (*opponentSlot)->facing = facing;
            (*opponentSlot)->knockbackVelocityX = -4.0;
            (*opponentSlot)->knockbackVelocityY = -0.8;
        }
        if (field000a < 4) {
            SetHorizontalOffset(0x32,3);
            SetHorizontalShake(0x32,3);
        }
        ++field000c;
        if ((unsigned short)field000c >= frameDuration) {
            field000c = 0;
            ++field000a;
            field0168 = 0;
            if (field000a == 3) {
                velocityX = -1.0;
                velocityY = -2.1;
                gravity = 0.025;
            }
            if (field000a >= frameCount) {
                field0008 = 0;
                ResetPose();
            }
        }
        break;
    case 255:
        if ((field000a == 0) && ((unsigned short)field000c == 0)) {
            velocityX = velocityX * 0.3;
            velocityY = velocityY * 0.5;
            gravity = 0.035;
            remainingHitCount = 9;
        }
        if ((((field000a == 1) || (field000a == 3)) ||
            (field000a == 7)) && ((unsigned short)field000c == 0)) {
            pendingContextSoundSlot = 0x15;
        }
        if (10 < field000a) {
            velocityY = velocityY + gravity;
        }
        if (positionY + velocityY > 0.0) {
            ResetPose();
            ResetFrame();
            field0008 = 0x102;
            positionY = 0.0;
            break;
        }
        ++field000c;
        if ((unsigned short)field000c >= frameDuration) {
            field000c = 0;
            ++field000a;
            field0168 = 0;
            if ((field000a == 5) && (field3138 < 3)) {
                ++field3138;
                field000a = 0;
            }
        }
        if (field000a >= frameCount) {
            field000a = field000a + -4;
        }
        break;
    case 256:
        if ((field000a == 0) && ((unsigned short)field000c == 0)) {
            FaceOpponent();
            ResetFrame();
        }
        if ((field000a == 3) && ((unsigned short)field000c == 0)) {
            velocityX = 0.5;
            velocityY = 3.0;
            remainingHitCount = 1;
            pendingContextSoundSlot = 0x23;
            meter = meter + 0x23;
        }
        if (positionY + velocityY > 0.0 && field000a > 2) {
            field000c = 0;
            field000a = 0;
            positionY = 0.0;
            ResetFrame();
            field0008 = 0x101;
            break;
        }
        ++field000c;
        if ((unsigned short)field000c >= frameDuration) {
            field000c = 0;
            ++field000a;
            if (0 < remainingHitCount) {
                field0168 = 0;
            }
            if (field000a >= frameCount) {
                field000a = field000a + -2;
            }
        }
        break;
    case 257:
        velocityX = velocityX - 0.04;
        if (velocityX < 0.0) {
            velocityX = 0.0;
        }
        ++field000c;
        if ((unsigned short)field000c >= frameDuration) {
            field000c = 0;
            ++field000a;
            if (field000a >= frameCount) {
                field0008 = 3;
                ResetPose();
            }
        }
        break;
    case 258:
        velocityX = velocityX - 0.04;
        if (velocityX < 0.0) {
            velocityX = 0.0;
        }
        ++field000c;
        if ((unsigned short)field000c >= frameDuration) {
            field000c = 0;
            ++field000a;
            if (field000a >= frameCount) {
                field0008 = 3;
                ResetPose();
            }
        }
        break;
    case 259:
        if (field000a > 8 && field000a < 15 && buttonHeld[0] > 0) {
            ResetPose();
            field0008 = 0x106;
            break;
        }
        if (field000a > 8 && field000a < 15 && buttonHeld[1] > 0) {
            ResetPose();
            field0008 = 0x107;
            break;
        }
        if ((field000a == 0) && ((unsigned short)field000c == 0)) {
            ResetFrame();
        }
        if ((7 < field000a) &&
            (velocityX = velocityX - 0.02,
            velocityX < 0.0)) {
            velocityX = 0.0;
        }
        if ((field000a == 7) && ((unsigned short)field000c == 0)) {
            remainingHitCount = 1;
            velocityX = 3.0;
        }
        ++field000c;
        if ((unsigned short)field000c >= frameDuration) {
            field000c = 0;
            ++field000a;
            if (0 < remainingHitCount) {
                field0168 = 0;
            }
            if ((field000a == 0xc) && (field3138 < 3)) {
                field000a = field000a + -4;
                ++field3138;
            }
            if (field000a >= frameCount) {
                field0008 = 3;
                ResetPose();
                FaceOpponent();
            }
        }
        break;
    case 260:
        if ((field000a == 0) && ((unsigned short)field000c == 0)) {
            ResetFrame();
        }
        velocityY = velocityY + gravity;
        if ((0xd < field000a) &&
            (velocityX = velocityX - 0.03,
            velocityX < 0.0)) {
            velocityX = 0.0;
        }
        if ((field0262 == 10) && (0xd < field000a)) {
            ResetPose();
            field0008 = 0x122;
            break;
        }
        if (positionY < 0.0 && velocityY > 0.0 && buttonPulse[0] == 1) {
            ResetPose();
            ResetFrame();
            field0008 = 0x100;
            break;
        }
        if (velocityY + positionY > 0.0 && field000a > 5 && field000a < 10) {
            field000a = 0xe;
            field000c = 0;
            positionY = 0.0;
            velocityY = 0.0;
            gravity = 0.0;
            break;
        }
        if (velocityY + positionY > 0.0 && field000a > 9 && field000a < 14) {
            field000a = 0xe;
            field000c = 0;
            positionY = 0.0;
            velocityY = 0.0;
            gravity = 0.0;
            break;
        }
        ++field000c;
        if ((unsigned short)field000c >= frameDuration) {
            field000c = 0;
            ++field000a;
            if (field000a == 1) {
                field0168 = 0;
            }
            if (field000a == 3) {
                velocityX = 1.2;
                velocityY = -3.3;
                gravity = 0.055;
                remainingHitCount = 1;
            }
            if (field000a == 10) {
                field000a = field000a + -4;
            }
            if (field000a == 0xe) {
                field000a = field000a + -4;
            }
            if (field000a >= frameCount) {
                field0008 = 3;
                ResetPose();
                FaceOpponent();
            }
        }
        break;
    case 261:
        if ((field000a == 0) && ((unsigned short)field000c == 0)) {
            ResetFrame();
            if (field0120 == '\0') {
                field0118 = field0118 - 500.0;
            }
            else {
                field0118 = field0118 - 250.0;
            }
            effect.type = 0x21;
            effect.palette = 0xb;
            effect.x = (double)((int(positionX)) + facing * 0x14);
            effect.y = (double)((int(positionY)) + -0x32);
            effect.group = 2;
            effect.layer = 1;
            contextOwner->EmitEffect(&effect);
            positionY = positionY - 25.0;
            velocityX = 3.0;
            remainingHitCount = 1;
        }
        velocityY = velocityY + gravity;
        if ((9 < field000a) &&
            (velocityX = velocityX - 0.03,
            velocityX < 0.0)) {
            velocityX = 0.0;
        }
        if (field0168 > 1 && field000a > 1 && field000a < 6) {
            field000a = 6;
            field000c = 0;
            velocityX = -velocityX * 0.1;
            velocityY = -1.5;
            gravity = 0.036;
            break;
        }
        if (velocityY + positionY > 0.0 && field000a > 5 && field000a < 10) {
            field000a = 10;
            field000c = 0;
            positionY = 0.0;
            velocityY = 0.0;
            gravity = 0.0;
            break;
        }
        ++field000c;
        if ((unsigned short)field000c >= frameDuration) {
            field000c = 0;
            ++field000a;
            if (0 < remainingHitCount) {
                field0168 = 0;
            }
            if (field000a == 6) {
                if (field3138 < 4) {
                    field000a = field000a + -4;
                    ++field3138;
                } else {
                    field000a = 10;
                    positionY = 0.0;
                    return;
                }
            }
            if (field000a == 10) {
                field000a = field000a + -4;
            }
            if (field000a >= frameCount) {
                field0008 = 3;
                ResetPose();
                FaceOpponent();
            }
        }
        break;
    case 262:
        velocityX = velocityX - 0.035;
        if (velocityX < 0.0) {
            velocityX = 0.0;
        }
        if (positionY < 0.0) {
            gravity = 0.055;
            velocityY = velocityY + gravity;
        }
        if (field000a > 4 && field000a < 15 && positionY + velocityY > 0.0) {
            field000c = 0;
            field000a = 0xf;
            positionY = 0.0;
            ResetFrame();
            break;
        }
        ++field000c;
        if ((unsigned short)field000c >= frameDuration) {
            field000c = 0;
            ++field000a;
            if (field000a < 7) {
                field0168 = 0;
            }
            if (field000a == 4) {
                velocityY = -3.3;
                remainingHitCount = 3;
            }
            if (field000a == 0xf) {
                field000a = field000a + -4;
            }
            if (field000a >= frameCount) {
                ResetPose();
                field0008 = 3;
            }
        }
        break;
    case 263:
        if ((field000a == 0) && ((unsigned short)field000c == 0)) {
            ResetFrame();
        }
        velocityY = velocityY + gravity;
        if ((10 < field000a) &&
            (velocityX = velocityX - 0.03,
            velocityX < 0.0)) {
            velocityX = 0.0;
        }
        if (positionY < 0.0 && velocityY > 0.0 && buttonPulse[0] == 1) {
            ResetPose();
            ResetFrame();
            field0008 = 0x100;
            break;
        }
        if (velocityY + positionY > 0.0 && field000a > 2 && field000a < 10) {
            ResetPose();
            ResetFrame();
            positionY = 0.0;
            field0008 = 0x102;
            break;
        }
        ++field000c;
        if ((unsigned short)field000c >= frameDuration) {
            field000c = 0;
            ++field000a;
            if (field000a == 1) {
                field0168 = 0;
            }
            if (field000a == 3) {
                velocityX = 0.8;
                velocityY = -3.1;
                gravity = 0.055;
                remainingHitCount = 1;
            }
            if (field000a >= frameCount) {
                field000a = field000a + -4;
            }
        }
        break;
    case 264:
        velocityX = velocityX - 0.05;
        if (velocityX < 0.0) {
            velocityX = 0.0;
        }
        ++field000c;
        if ((unsigned short)field000c >= frameDuration) {
            field000c = 0;
            ++field000a;
            field0168 = 0;
            if (field000a >= frameCount) {
                ResetPose();
                field0008 = 3;
                ResetFrame();
            }
        }
        break;
    case 265:
        velocityX = velocityX - 0.05;
        if (velocityX < 0.0) {
            velocityX = 0.0;
        }
        ++field000c;
        if ((unsigned short)field000c >= frameDuration) {
            field000c = 0;
            ++field000a;
            field0168 = 0;
            if (field000a >= frameCount) {
                ResetPose();
                field0008 = 3;
                ResetFrame();
            }
        }
        break;
    case 266:
        if ((field000a == 0) && ((unsigned short)field000c == 0)) {
            velocityX = 0.0;
            velocityY = 0.0;
            remainingHitCount = 1;
        }
        if ((field000a == 2) && ((unsigned short)field000c == 0)) {
            pendingContextSoundSlot = 0x15;
            meter = meter + 0x23;
            remainingHitCount = 1;
        }
        if (1 < field000a) {
            velocityY = velocityY + gravity;
            velocityX = velocityX - 0.06;
            if (velocityX < 0.0) {
                velocityX = 0.0;
            }
        }
        if ((0.0 < positionY + velocityY) &&
            (field000a == 7)) {
            field000a = 8;
            field000c = 0;
            positionY = 0.0;
            ResetFrame();
        }
        ++field000c;
        if ((unsigned short)field000c >= frameDuration) {
            field000c = 0;
            ++field000a;
            field0168 = 0;
            if (field000a == 2) {
                gravity = 0.09;
                velocityY = -3.0;
                velocityX = 3.0;
            }
            if ((field000a == 6) && (field3138 < 1)) {
                field000a = field000a + -2;
                ++field3138;
            }
            if (field000a >= frameCount) {
                field0008 = 0;
                FaceOpponent();
                ResetPose();
            }
        }
        break;
    case 267:
        if ((field000a == 0) && ((unsigned short)field000c == 0)) {
            velocityX = 0.0;
            velocityY = 0.0;
            remainingHitCount = 1;
        }
        if ((field000a == 2) && ((unsigned short)field000c == 0)) {
            pendingContextSoundSlot = 0x15;
            meter = meter + 0x23;
            remainingHitCount = 1;
        }
        if (1 < field000a) {
            velocityY = velocityY + gravity;
            velocityX = velocityX - 0.06;
            if (velocityX < 0.0) {
                velocityX = 0.0;
            }
        }
        if ((0.0 < positionY + velocityY) &&
            (field000a == 7)) {
            field000a = 8;
            field000c = 0;
            positionY = 0.0;
            ResetFrame();
        }
        ++field000c;
        if ((unsigned short)field000c >= frameDuration) {
            field000c = 0;
            ++field000a;
            field0168 = 0;
            if (field000a == 2) {
                gravity = 0.11;
                velocityY = -4.5;
                velocityX = 4.0;
            }
            if ((field000a == 6) && (field3138 < 1)) {
                field000a = field000a + -2;
                ++field3138;
            }
            if (field000a >= frameCount) {
                field0008 = 0;
                FaceOpponent();
                ResetPose();
            }
        }
        break;
    case 268:
        if ((field000a == 0) && ((unsigned short)field000c == 0)) {
            velocityX = 0.0;
            velocityY = 0.0;
            remainingHitCount = 1;
            if (field0120 == '\0') {
                field0118 = field0118 - 500.0;
            }
            else {
                field0118 = field0118 - 250.0;
            }
            effect.type = 0x21;
            effect.palette = 0xb;
            effect.x = (double)((int(positionX)) + facing * 0x14);
            effect.y = (double)((int(positionY)) + -0x32);
            effect.group = 2;
            effect.layer = 1;
            contextOwner->EmitEffect(&effect);
        }
        if ((field000a == 2) && ((unsigned short)field000c == 0)) {
            pendingContextSoundSlot = 0x15;
            meter = meter + 0x23;
            remainingHitCount = 1;
        }
        if (1 < field000a) {
            velocityY = velocityY + gravity;
            velocityX = velocityX - 0.04;
            if (velocityX < 0.0) {
                velocityX = 0.0;
            }
        }
        if (((0.0 < positionY + velocityY) &&
            (8 < field000a)) && (field000a < 0xd)) {
            field000a = 0xd;
            field000c = 0;
            positionY = 0.0;
            ResetFrame();
        }
        ++field000c;
        if ((unsigned short)field000c >= frameDuration) {
            field000c = 0;
            ++field000a;
            if (field000a == 1) {
                field0168 = 0;
            }
            if (field000a == 2) {
                gravity = 0.09;
                velocityY = -4.0;
                velocityX = 2.0;
            }
            if ((field000a == 6) && (field3138 < 1)) {
                field000a = field000a + -2;
                ++field3138;
            }
            if (field000a == 0xd) {
                field000a = field000a + -4;
            }
            if (field000a >= frameCount) {
                ResetPose();
                field0008 = 0;
            }
        }
        break;
    case 269:
        if ((field000a == 0) && ((unsigned short)field000c == 0)) {
            ResetFrame();
        }
        if ((field000a == 3) && ((unsigned short)field000c == 0)) {
            velocityX = 0.5;
            velocityY = 3.0;
            remainingHitCount = 1;
            pendingContextSoundSlot = 0x23;
            meter = meter + 0x23;
        }
        if (positionY + velocityY > 0.0 && field000a > 2) {
            field000c = 0;
            field000a = 0;
            positionY = 0.0;
            ResetFrame();
            field0008 = 0x108;
            break;
        }
        ++field000c;
        if ((unsigned short)field000c >= frameDuration) {
            field000c = 0;
            ++field000a;
            if (0 < remainingHitCount) {
                field0168 = 0;
            }
            if (field000a >= frameCount) {
                field000a = field000a + -2;
            }
        }
        break;
    case 270:
        if ((field000a == 0) && ((unsigned short)field000c == 0)) {
            ResetFrame();
        }
        if ((field000a == 3) && ((unsigned short)field000c == 0)) {
            velocityX = 2.2;
            velocityY = 2.2;
            remainingHitCount = 1;
            pendingContextSoundSlot = 0x23;
            meter = meter + 0x23;
        }
        if (positionY + velocityY > 0.0 && field000a > 2) {
            field000c = 0;
            field000a = 0;
            positionY = 0.0;
            ResetFrame();
            field0008 = 0x108;
            break;
        }
        ++field000c;
        if ((unsigned short)field000c >= frameDuration) {
            field000c = 0;
            ++field000a;
            if (0 < remainingHitCount) {
                field0168 = 0;
            }
            if (field000a >= frameCount) {
                field000a = field000a + -2;
            }
        }
        break;
    case 271:
        if ((field000a == 0) && ((unsigned short)field000c == 0)) {
            meter = meter + 0x28;
            remainingHitCount = 4;
        }
        if (field000a > 9 && field000a < 14 && (velocityY = velocityY + gravity, velocityY + positionY > 0.0)) {
            positionY = 0.0;
            ResetFrame();
            ResetPose();
            field000a = 0xe;
            break;
        }
        if (field000a < 7 && (velocityY = velocityY + gravity, velocityY + positionY > 0.0)) {
            positionY = 0.0;
            velocityY = 0.0;
            ResetPose();
            field3138 = (int(velocityX * 100.0));
            velocityX = 0.0;
            field000a = 7;
            break;
        }
        ++field000c;
        if ((unsigned short)field000c >= frameDuration) {
            field000c = 0;
            ++field000a;
            field0168 = 0;
            if ((field000a == 7) || (field000a == 0xe)) {
                field000a = field000a + -4;
                ++field3138;
            }
            if (field000a == 9) {
                velocityX = (double)field3138 * 0.005;
                velocityY = -0.8;
            }
            if (field000a >= frameCount) {
                field0008 = 3;
                ResetPose();
            }
        }
        break;
    case 272:
        if ((field000a == 0) && ((unsigned short)field000c == 0)) {
            ResetFrame();
        }
        if (field000a > 19 && field0262 == 10) {
            ResetPose();
            field0008 = 0x106;
            break;
        }
        if ((field000a == 4) && ((unsigned short)field000c == 0)) {
            gravity = 0.03;
            velocityY = -2.0;
            velocityX = -3.0;
        }
        if ((0xf < field000a) && (field000a < 0x14)) {
            if (inputX == facing) {
                velocityX = velocityX + 0.015;
            }
            if ((int)inputX == -(int)facing) {
                velocityX = velocityX - 0.015;
            }
            if (velocityX < -2.5) { velocityX = -2.5; } else if (velocityX > 2.5) { velocityX = 2.5; }
            if (buttonPulse[0] == '\x01') {
                ResetPose();
                field0008 = 0x10d;
                if ((int)inputX == -(int)facing) { facing = -facing; }
                return;
            }
            if (buttonPulse[1] == '\x01') {
                ResetPose();
                field0008 = 0x10e;
                if ((int)inputX == -(int)facing) { facing = -facing; }
                return;
            }
            if (buttonPulse[2] == '\x01') {
                ResetPose();
                field0008 = 0x10f;
                if ((int)inputX == -(int)facing) { facing = -facing; }
                return;
            }
        }
        if (((4 < field000a) && (field000a < 0xc)) ||
            ((0xf < field000a && (field000a < 0x14)))) {
            velocityY = velocityY + gravity;
        }
        if ((0xb < field000a) && (field000a < 0x10)) {
            if (facing == '\x01') {
                positionX = (double)(contextOwner->cameraBounds.left + 0xf);
            }
            if (facing == -1) {
                positionX = (double)(contextOwner->cameraBounds.right + -0xf);
            }
        }
        if (positionY + velocityY >= 0.0 && field000a > 4 && field000a < 20) {
            positionY = 0.0;
            ResetFrame();
            field000a = 0x14;
            field000c = 0;
            break;
        }
        if (CollisionSide() != 0 && field000a > 4 && field000a < 12) {
            velocityX = 0.0;
            velocityY = 0.0;
            field000a = 0xc;
            field000c = 0;
            pendingContextSoundSlot = 0x1a;
            break;
        }
        ++field000c;
        if ((unsigned short)field000c >= frameDuration) {
            field000c = 0;
            ++field000a;
            if (field000a == 0xc) {
                field000a = field000a + -4;
            }
            if (field000a == 0x10) {
                velocityX = 1.5;
                velocityY = -2.5;
                gravity = 0.035;
            }
            if (field000a == 0x14) {
                field000a = field000a + -4;
            }
            if (field000a >= frameCount) {
                field0008 = 3;
                ResetPose();
                FaceOpponent();
            }
        }
        break;
    case 273:
        if ((field000a == 0) && ((unsigned short)field000c == 0)) {
            ResetFrame();
        }
        if ((field000a == 4) && ((unsigned short)field000c == 0)) {
            gravity = 0.03;
            velocityY = -1.5;
            velocityX = -3.0;
        }
        if ((field000a == 0x12) &&
            ((*opponentSlot)->positionY == 0.0)) {
            remainingHitCount = 1;
        }
        else {
            remainingHitCount = 0;
        }
        if ((field000a == 0x12) && (field0168 == 3)) {
            (*opponentSlot)->ResetPose();
            (*opponentSlot)->ResetFrame();
            (*opponentSlot)->field0008 = 0x6b;
            ResetPose();
            ResetFrame();
            field0008 = 0x113;
            positionY = (double)(field2af8[0] + 0x32);
            positionX =
            (*opponentSlot)->positionX + (-field2ad0[0] - 0x14) * facing;
            effect.type = 0;
            effect.x = (double)((int(positionX)) + facing * 7);
            effect.y = (double)((int(positionY)) + -0x2c);
            effect.group = 2;
            effect.layer = 1;
            contextOwner->EmitEffect(&effect);
            break;
        }
        if (((4 < field000a) && (field000a < 0xc)) ||
            ((0xf < field000a && (field000a < 0x13)))) {
            velocityY = velocityY + gravity;
        }
        if ((0xb < field000a) && (field000a < 0x10)) {
            if (facing == '\x01') {
                positionX = (double)(contextOwner->cameraBounds.left + 0xf);
            }
            if (facing == -1) {
                positionX = (double)(contextOwner->cameraBounds.right + -0xf);
            }
        }
        if (positionY + velocityY >= 0.0 && field000a > 15 && field000a < 19) {
            positionY = 0.0;
            ResetFrame();
            field000a = 0x14;
            field000c = 0;
            break;
        }
        if (CollisionSide() != 0 && field000a > 4 && field000a < 12) {
            velocityX = 0.0;
            velocityY = 0.0;
            field000a = 0xc;
            field000c = 0;
            pendingContextSoundSlot = 0x1a;
            break;
        }
        ++field000c;
        if ((unsigned short)field000c >= frameDuration) {
            field000c = 0;
            ++field000a;
            if (field000a == 0xc) {
                field000a = field000a + -4;
            }
            if (field000a == 0x10) {
                velocityX = 2.2;
                velocityY = -0.5;
                gravity = 0.035;
            }
            if (field000a == 0x13) {
                --field000a;
            }
            if (field000a >= frameCount) {
                field0008 = 3;
                ResetPose();
                FaceOpponent();
            }
        }
        break;
    case 274:
        if ((field000a == 0) && ((unsigned short)field000c == 0)) {
            ResetFrame();
        }
        if (field000a > 19 && field0262 == 10) {
            ResetPose();
            field0008 = 0x106;
            break;
        }
        if ((field000a == 4) && ((unsigned short)field000c == 0)) {
            gravity = 0.03;
            velocityY = -2.0;
            velocityX = 3.0;
        }
        if ((0xf < field000a) && (field000a < 0x14)) {
            if (inputX == facing) {
                velocityX = velocityX + 0.015;
            }
            if ((int)inputX == -(int)facing) {
                velocityX = velocityX - 0.015;
            }
            if (velocityX < -2.5) { velocityX = -2.5; } else if (velocityX > 2.5) { velocityX = 2.5; }
            if (buttonPulse[0] == '\x01') {
                ResetPose();
                field0008 = 0x10d;
                if ((int)inputX == -(int)facing) { facing = -facing; }
                return;
            }
            if (buttonPulse[1] == '\x01') {
                ResetPose();
                field0008 = 0x10e;
                if ((int)inputX == -(int)facing) { facing = -facing; }
                return;
            }
            if (buttonPulse[2] == '\x01') {
                ResetPose();
                field0008 = 0x10f;
                if ((int)inputX == -(int)facing) { facing = -facing; }
                return;
            }
        }
        if (((4 < field000a) && (field000a < 0xc)) ||
            ((0xf < field000a && (field000a < 0x14)))) {
            velocityY = velocityY + gravity;
        }
        if ((0xb < field000a) && (field000a < 0x10)) {
            if (facing == '\x01') {
                positionX = (double)(contextOwner->cameraBounds.left + 0xf);
            }
            if (facing == -1) {
                positionX = (double)(contextOwner->cameraBounds.right + -0xf);
            }
        }
        if (positionY + velocityY >= 0.0 && field000a > 4 && field000a < 20) {
            positionY = 0.0;
            ResetFrame();
            field000a = 0x14;
            field000c = 0;
            break;
        }
        if (CollisionSide() != 0 && field000a > 4 && field000a < 12) {
            velocityX = 0.0;
            velocityY = 0.0;
            facing = -facing;
            field000a = 0xc;
            field000c = 0;
            pendingContextSoundSlot = 0x1a;
            break;
        }
        ++field000c;
        if ((unsigned short)field000c >= frameDuration) {
            field000c = 0;
            ++field000a;
            if (field000a == 0xc) {
                field000a = field000a + -4;
            }
            if (field000a == 0x10) {
                velocityX = 1.5;
                velocityY = -2.5;
                gravity = 0.035;
            }
            if (field000a == 0x14) {
                field000a = field000a + -4;
            }
            if (field000a >= frameCount) {
                field0008 = 3;
                ResetPose();
                FaceOpponent();
            }
        }
        break;
    case 275:
        SetHorizontalOffset(0x32,3);
        SetHorizontalShake(0x32,3);
        if (field000a == 4) {
            (*opponentSlot)->field0008 = 0x67;
            (*opponentSlot)->positionX =
            (23.0 + velocityX) * facing +
            positionX;
            (*opponentSlot)->positionY =
            -54.0 + velocityY + positionY;
        }
        if (field000a == 5) {
            (*opponentSlot)->field0008 = 0x67;
            (*opponentSlot)->positionX =
            (15.0 + velocityX) * facing +
            positionX;
            (*opponentSlot)->positionY =
            -70.0 + velocityY + positionY;
        }
        if (field000a == 6) {
            (*opponentSlot)->field0008 = 0x76;
            (*opponentSlot)->positionX =
            (-31.0 + velocityX) * facing +
            positionX;
            (*opponentSlot)->positionY =
            -62.0 + velocityY + positionY;
            (*opponentSlot)->facing = facing;
        }
        if (field000a == 7) {
            (*opponentSlot)->field0008 = 0x75;
            (*opponentSlot)->positionX =
            (-34.0 + velocityX) * facing +
            positionX;
            (*opponentSlot)->positionY =
            -34.0 + velocityY + positionY;
            (*opponentSlot)->facing = facing;
        }
        if (field000a == 8) {
            (*opponentSlot)->field0008 = 0x68;
            (*opponentSlot)->positionX =
            (-6.0 + velocityX) * facing +
            positionX;
            (*opponentSlot)->positionY =
            -3.0 + velocityY + positionY;
            (*opponentSlot)->facing = -facing;
        }
        if (field000a == 9) {
            (*opponentSlot)->field0008 = 0x68;
            (*opponentSlot)->positionX =
            (-4.0 + velocityX) * facing +
            positionX;
            (*opponentSlot)->positionY =
            -2.0 + velocityY + positionY;
            (*opponentSlot)->facing = -facing;
        }
        if ((field000a == 10) && ((unsigned short)field000c == 0)) {
            (*opponentSlot)->ResetFrame();
            (*opponentSlot)->ResetPose();
            (*opponentSlot)->field0008 = 0x62;
            (*opponentSlot)->positionY = 0;
            (*opponentSlot)->positionX = positionX;
            ApplyDamage(0x4b0,960.0);
            effect.type = 0;
            effect.x = (double)(int(positionX));
            effect.y = (double)(int(positionY));
            effect.palette = 2;
            effect.group = 2;
            effect.layer = 1;
            contextOwner->EmitEffect(&effect);
        }
        if (field000a == 19 && positionY + velocityY > 0.0) {
            ResetPose();
            ResetFrame();
            positionY = 0.0;
            field0008 = 0xd;
            break;
        }
        if (0xf < field000a) {
            velocityY = velocityY + gravity;
        }
        if ((0xd < field000a) && ((*opponentSlot)->field0008 == 99)) {
            (*opponentSlot)->field000c = 0;
        }
        ++field000c;
        if ((unsigned short)field000c >= frameDuration) {
            field000c = 0;
            ++field000a;
            field0168 = 0;
            if (field000a == 0x10) {
                velocityX = -0.5;
                velocityY = -1.3;
                gravity = 0.05;
            }
            if (field000a >= frameCount) {
                --field000a;
            }
        }
        break;
    case 280:
        if ((field000a == 0) && ((unsigned short)field000c == 0)) {
            FaceOpponent();
            ResetFrame();
            remainingHitCount = 1;
        }
        if (positionY + velocityY > 0.0 && field000a > 4) {
            field000c = 0;
            field000a = 0xc;
            positionY = 0.0;
            ResetFrame();
            break;
        }
        if ((field000a == 5) && (field0168 == 3)) {
            velocityX = velocityX * 0.15;
            velocityY = velocityY * 0.15;
            ResetPose();
            field0008 = 0x123;
            break;
        }
        ++field000c;
        if ((unsigned short)field000c >= frameDuration) {
            field000c = 0;
            ++field000a;
            field0168 = 0;
            if (field000a == 5) {
                velocityX = 0.7;
                velocityY = 2.0;
            }
            if (field000a == 6) {
                --field000a;
            }
            if (field000a == 0xc) {
                field000a = field000a + -6;
            }
            if (field000a >= frameCount) {
                ResetPose();
                FaceOpponent();
                field0008 = 3;
            }
        }
        break;
    case 281:
        if ((field000a == 0) && ((unsigned short)field000c == 0)) {
            FaceOpponent();
            ResetFrame();
            remainingHitCount = 1;
        }
        if (positionY + velocityY > 0.0 && field000a > 4) {
            field000c = 0;
            field000a = 0xc;
            positionY = 0.0;
            ResetFrame();
            break;
        }
        if ((field000a == 5) && (field0168 == 3)) {
            velocityX = velocityX * 0.15;
            velocityY = velocityY * 0.15;
            ResetPose();
            field0008 = 0x123;
            break;
        }
        ++field000c;
        if ((unsigned short)field000c >= frameDuration) {
            field000c = 0;
            ++field000a;
            field0168 = 0;
            if (field000a == 5) {
                velocityX = 2.0;
                velocityY = 2.0;
            }
            if (field000a == 6) {
                --field000a;
            }
            if (field000a == 0xc) {
                field000a = field000a + -6;
            }
            if (field000a >= frameCount) {
                ResetPose();
                FaceOpponent();
                field0008 = 3;
            }
        }
        break;
    case 282:
        if ((field000a == 0) && ((unsigned short)field000c == 0)) {
            FaceOpponent();
            ResetFrame();
            if (field0120 == '\0') {
                field0118 = field0118 - 500.0;
            }
            else {
                field0118 = field0118 - 250.0;
            }
            effect.type = 0x21;
            effect.palette = 0xb;
            effect.x = (double)((int(positionX)) + facing * 0x14);
            effect.y = (double)((int(positionY)) + -0x32);
            effect.group = 2;
            effect.layer = 1;
            contextOwner->EmitEffect(&effect);
            ++field3138;
        }
        if ((field000a == 0) && ((unsigned short)field000c == 0)) {
            ResetFrame();
            remainingHitCount = 1;
        }
        if (positionY + velocityY > 0.0 && field000a > 4) {
            field000c = 0;
            field000a = 0xc;
            positionY = 0.0;
            ResetFrame();
            break;
        }
        if ((field000a == 5) && (field0168 == 3)) {
            field000c = 0;
            field000a = 8;
            remainingHitCount = 99;
            break;
        }
        ++field000c;
        if ((unsigned short)field000c >= frameDuration) {
            field000c = 0;
            ++field000a;
            field0168 = 0;
            if (field000a == 5) {
                velocityX = 2.0;
                velocityY = 2.0;
            }
            if (field000a == 6) {
                --field000a;
            }
            if (field000a == 0xc) {
                field000a = field000a + -6;
            }
            if (field000a >= frameCount) {
                ResetPose();
                FaceOpponent();
                field0008 = 3;
            }
        }
        break;
    case 283:
        velocityX = 0.0;
        velocityY = 0.0;
        if ((field000a == 2) && (field0168 == 3)) {
            ResetFrame();
            ResetPose();
            (*opponentSlot)->ResetFrame();
            (*opponentSlot)->ResetPose();
            field0008 = 0x11c;
            (*opponentSlot)->field0008 = 0x6b;
            break;
        }
        ++field000c;
        if ((unsigned short)field000c >= frameDuration) {
            field000c = 0;
            ++field000a;
            field0168 = 0;
            if ((((field000a == 2) && ((unsigned short)field000c == 0)) &&
                ((*opponentSlot)->positionY == 0.0)) &&
                (((*opponentSlot)->field0008 < 0x32 ||
                (0x95 < (*opponentSlot)->field0008)))) {
                remainingHitCount = 1;
            }
            else {
                remainingHitCount = 0;
            }
            if (field000a == 2) {
                meter = meter + 0x19;
            }
            if (field000a >= frameCount) {
                field0008 = 0;
                FaceOpponent();
                ResetPose();
            }
        }
        break;
    case 284:
        SetHorizontalShake(-0x32,3);
        (*opponentSlot)->hitstopFrames = 3;
        ++field000c;
        if (3 < field000a) {
            velocityX = 1.0;
            velocityY = velocityY + 0.025;
        }
        if (field000a > 3 && velocityY + positionY > 0.0) {
            ResetFrame();
            positionY = 0.0;
            ResetPose();
            (*opponentSlot)->ResetPose();
            field0008 = 0xd;
            (*opponentSlot)->field0008 = 0x48;
            break;
        }
        if ((unsigned short)field000c >= frameDuration) {
            field000c = 0;
            ++field000a;
            field0168 = 0;
            if (field000a == 1) {
                positionX =
                (*opponentSlot)->positionX -
                (double)((int)(*opponentSlot)->field2ad0[0] * (int)facing);
                positionY =
                ((*opponentSlot)->positionY + (double)(int)(*opponentSlot)->field2af8[0]) - 20.0;
            }
            if (field000a >= frameCount) {
                field000a = field000a + -2;
            }
        }
        break;
    case 285:
        if ((field000a == 0) && ((unsigned short)field000c == 0)) {
            ResetFrame();
        }
        if ((field000a == 3) && ((unsigned short)field000c == 0)) {
            velocityX = 0.5;
            velocityY = 3.0;
            remainingHitCount = 1;
            pendingContextSoundSlot = 0x23;
            meter = meter + 0x23;
        }
        if (field0168 > 0) {
            ResetPose();
            ResetFrame();
            field0008 = 0x120;
            break;
        }
        if (positionY + velocityY > 0.0 && field000a > 2) {
            field000c = 0;
            field000a = 0;
            positionY = 0.0;
            ResetFrame();
            field0008 = 0x109;
            break;
        }
        ++field000c;
        if ((unsigned short)field000c >= frameDuration) {
            field000c = 0;
            ++field000a;
            if (0 < remainingHitCount) {
                field0168 = 0;
            }
            if (field000a >= frameCount) {
                field000a = field000a + -2;
            }
        }
        break;
    case 286:
        if ((field000a == 0) && ((unsigned short)field000c == 0)) {
            ResetFrame();
        }
        if ((field000a == 3) && ((unsigned short)field000c == 0)) {
            velocityX = 2.2;
            velocityY = 2.2;
            remainingHitCount = 1;
            pendingContextSoundSlot = 0x23;
            meter = meter + 0x23;
        }
        if (field0168 > 0) {
            ResetPose();
            ResetFrame();
            field0008 = 0x120;
            break;
        }
        if (positionY + velocityY > 0.0 && field000a > 2) {
            field000c = 0;
            field000a = 0;
            positionY = 0.0;
            ResetFrame();
            field0008 = 0x109;
            break;
        }
        ++field000c;
        if ((unsigned short)field000c >= frameDuration) {
            field000c = 0;
            ++field000a;
            if (0 < remainingHitCount) {
                field0168 = 0;
            }
            if (field000a >= frameCount) {
                field000a = field000a + -2;
            }
        }
        break;
    case 287:
        if ((field000a == 0) && ((unsigned short)field000c == 0)) {
            ResetFrame();
        }
        if ((field000a == 3) && ((unsigned short)field000c == 0)) {
            velocityX = 4.0;
            velocityY = 1.5;
            remainingHitCount = 1;
            pendingContextSoundSlot = 0x23;
            meter = meter + 0x23;
        }
        if (field0168 > 0) {
            ResetPose();
            ResetFrame();
            field0008 = 0x120;
            break;
        }
        if (positionY + velocityY > 0.0 && field000a > 2) {
            field000c = 0;
            field000a = 0;
            positionY = 0.0;
            ResetFrame();
            field0008 = 0x109;
            break;
        }
        ++field000c;
        if ((unsigned short)field000c >= frameDuration) {
            field000c = 0;
            ++field000a;
            if (0 < remainingHitCount) {
                field0168 = 0;
            }
            if (field000a >= frameCount) {
                field000a = field000a + -2;
            }
        }
        break;
    case 288:
        if ((field000a == 0) && ((unsigned short)field000c == 0)) {
            velocityX = -0.4;
            velocityY = -0.9;
            gravity = 0.045;
        }
        velocityY = velocityY + gravity;
        if (positionY + velocityY > 0.0 && field000a < 8) {
            field000c = 0;
            field000a = 8;
            positionY = 0.0;
            ResetFrame();
            break;
        }
        ++field000c;
        if ((unsigned short)field000c >= frameDuration) {
            field000c = 0;
            ++field000a;
            if (0 < remainingHitCount) {
                field0168 = 0;
            }
            if (field000a == 8) {
                field000a = field000a + -4;
            }
            if (field000a >= frameCount) {
                ResetPose();
                FaceOpponent();
                field0008 = 3;
            }
        }
        break;
    case 289:
        if ((field000a == 0) && ((unsigned short)field000c == 0)) {
            ResetFrame();
        }
        if ((field000a == 4) && ((unsigned short)field000c == 0)) {
            gravity = 0.03;
            velocityY = -1.5;
            velocityX = -3.0;
        }
        if ((field000a == 0x12) &&
            ((*opponentSlot)->positionY == 0.0)) {
            remainingHitCount = 1;
        }
        else {
            remainingHitCount = 0;
        }
        if (((4 < field000a) && (field000a < 0xc)) ||
            ((0xf < field000a && (field000a < 0x13)))) {
            velocityY = velocityY + gravity;
        }
        if ((0xb < field000a) && (field000a < 0x10)) {
            if (facing == '\x01') {
                positionX = (double)(contextOwner->cameraBounds.left + 0xf);
            }
            if (facing == -1) {
                positionX = (double)(contextOwner->cameraBounds.right + -0xf);
            }
        }
        if (positionY + velocityY >= 0.0 && field000a > 15 && field000a < 19) {
            positionY = 0.0;
            ResetFrame();
            field000a = 0x14;
            field000c = 0;
            break;
        }
        if (CollisionSide() != 0 && field000a > 4 && field000a < 12) {
            velocityX = 0.0;
            velocityY = 0.0;
            field000a = 0xc;
            field000c = 0;
            pendingContextSoundSlot = 0x1a;
            break;
        }
        ++field000c;
        if ((unsigned short)field000c >= frameDuration) {
            field000c = 0;
            ++field000a;
            if (field000a == 0xc) {
                field000a = field000a + -4;
            }
            if (field000a == 0x10) {
                ResetPose();
                ResetFrame();
                field0008 = 0x11f;
                if ((positionX - (*opponentSlot)->positionX < 140.0) &&
                    (-140.0 < positionX - (*opponentSlot)->positionX)) {
                    field0008 = 0x11e;
                }
                if ((positionX - (*opponentSlot)->positionX < 70.0) &&
                    (-70.0 < positionX - (*opponentSlot)->positionX)) {
                    field0008 = 0x11d;
                }
                break;
            }
            if (field000a == 0x13) {
                --field000a;
            }
            if (field000a >= frameCount) {
                field0008 = 3;
                ResetPose();
                FaceOpponent();
            }
        }
        break;
    case 290:
        velocityX = velocityX - 0.035;
        if (velocityX < 0.0) {
            velocityX = 0.0;
        }
        if (positionY < 0.0) {
            gravity = 0.055;
            velocityY = velocityY + gravity;
        }
        if (field000a > 4 && field000a < 15 && positionY + velocityY > 0.0) {
            field000c = 0;
            field000a = 0xf;
            positionY = 0.0;
            ResetFrame();
            break;
        }
        ++field000c;
        if ((unsigned short)field000c >= frameDuration) {
            field000c = 0;
            ++field000a;
            if (field000a < 7) {
                field0168 = 0;
            }
            if (field000a == 4) {
                velocityY = -3.3;
                remainingHitCount = 3;
            }
            if (field000a == 0xf) {
                field000a = field000a + -4;
            }
            if (field000a >= frameCount) {
                ResetPose();
                field0008 = 3;
            }
        }
        break;
    case 291:
        if ((field000a == 0) && ((unsigned short)field000c == 0)) {
            FaceOpponent();
            ResetFrame();
            remainingHitCount = 5;
        }
        if (field000a > 14 && (velocityY = velocityY + gravity, positionY + velocityY > 0.0)) {
            field000c = 0;
            field000a = 0x16;
            positionY = 0.0;
            ResetFrame();
            break;
        }
        ++field000c;
        if ((unsigned short)field000c >= frameDuration) {
            field000c = 0;
            ++field000a;
            field0168 = 0;
            if (field000a == 0xe) {
                velocityX = 0.5;
                velocityY = 0.0;
                gravity = 0.045;
            }
            if (field000a == 0x16) {
                field000a = field000a + -4;
            }
            if (field000a >= frameCount) {
                ResetPose();
                FaceOpponent();
                field0008 = 3;
            }
        }
        break;
    case 300:
        if ((field000a == 0) && ((unsigned short)field000c == 0)) {
            velocityX = 0.0;
            velocityY = 0.0;
            gravity = 0.0;
        }
        if ((field000a == 1) && ((unsigned short)field000c == 0)) {
            hitstunFrames = 0x78;
            meter = meter + -1000;
            SetTint(0xb0,3);
            effect.type = 0x44;
            effect.palette = 0x13;
            effect.x = (double)(int(positionX));
            effect.y = (double)((int(positionY)) + -0x28);
            effect.group = 2;
            effect.owner = 1;
            effect.layer = 1;
            contextOwner->EmitEffect(&effect);
            field013c = 0x7e;
            SetHorizontalShake(0x32,0x78);
        }
        if (field000a >= 1) {
            reinterpret_cast<short&>(unknown_00df[0x13]) = 10;
        }
        if (((field000a == 2) || (field000a == 7)) &&
            ((unsigned short)field000c == 0)) {
            pendingContextSoundSlot = 0x15;
            remainingHitCount = 1;
        }
        if ((field000a == 0x10) && ((unsigned short)field000c == 0)) {
            pendingContextSoundSlot = 0x14;
            remainingHitCount = 1;
        }
        ++field000c;
        if ((unsigned short)field000c >= frameDuration) {
            field000c = 0;
            ++field000a;
            if (0 < remainingHitCount) {
                field0168 = 0;
            }
            if (field000a == 2) {
                field013c = 9;
            }
            if (field000a == 6) {
                positionX = (double)(facing * 0xf) + positionX;
            }
            if (field000a == 7) {
                positionX = (double)(facing * 0xf) + positionX;
            }
            if (field000a == 9) {
                positionX = (double)(facing * 0xf) + positionX;
            }
            if (field000a == 10) {
                if (1 < field3138) {
                    field000a = 0xc;
                    return;
                }
                positionX = (double)(facing * 0xf) + positionX;
            }
            if ((field000a == 0xc) && (field3138 < 1)) {
                field000a = 2;
                ++field3138;
            }
            if (field000a >= frameCount) {
                field0008 = 3;
                ResetPose();
            }
        }
        break;
    case 301:
        if ((field000a == 0) && ((unsigned short)field000c == 0)) {
            velocityX = 0.0;
            velocityY = 0.0;
            gravity = 0.0;
        }
        if ((field000a == 1) && ((unsigned short)field000c == 0)) {
            hitstunFrames = 0x78;
            meter = meter + -2000;
            SetTint(0xb0,3);
            effect.type = 0x45;
            effect.palette = 5;
            effect.x = (double)(int(positionX));
            effect.y = (double)((int(positionY)) + -0x28);
            effect.group = 2;
            effect.owner = 1;
            effect.layer = 1;
            contextOwner->EmitEffect(&effect);
            field013c = 0x84;
            SetHorizontalShake(0x32,0x78);
        }
        if (field000a >= 1) {
            reinterpret_cast<short&>(unknown_00df[0x13]) = 10;
        }
        if (((field000a == 2) || (field000a == 7)) &&
            ((unsigned short)field000c == 0)) {
            pendingContextSoundSlot = 0x15;
            remainingHitCount = 1;
        }
        if ((field000a == 0xe) && ((unsigned short)field000c == 0)) {
            pendingContextSoundSlot = 0x14;
            remainingHitCount = 1;
        }
        if ((field000a == 0x15) && ((unsigned short)field000c == 0)) {
            pendingContextSoundSlot = 0x15;
            remainingHitCount = 1;
        }
        if ((0x14 < field000a) && (field000a < 0x1c)) {
            velocityY = velocityY + gravity;
            velocityX = velocityX - 0.04;
            if (velocityX < 0.0) {
                velocityX = 0.0;
            }
        }
        if (field000a > 20 && field000a < 28 && positionY + velocityY > 0.0) {
            field000a = 0x1c;
            field000c = 0;
            positionY = 0.0;
            ResetFrame();
            break;
        }
        ++field000c;
        if ((unsigned short)field000c >= frameDuration) {
            field000c = 0;
            ++field000a;
            if (0 < remainingHitCount) {
                field0168 = 0;
            }
            if (field000a == 2) {
                field013c = 0x1e;
            }
            if (field000a == 6) {
                positionX = (double)(facing * 0xf) + positionX;
            }
            if (field000a == 7) {
                positionX = (double)(facing * 0xf) + positionX;
            }
            if (field000a == 9) {
                positionX = (double)(facing * 0xf) + positionX;
            }
            if (field000a == 10) {
                if (2 < field3138) {
                    field000a = 0xc;
                    return;
                }
                positionX = (double)(facing * 0xf) + positionX;
            }
            if ((field000a == 0xc) && (field3138 < 2)) {
                field000a = 2;
                ++field3138;
            }
            if (field000a == 0x14) {
                gravity = 0.06;
                velocityY = -3.0;
                velocityX = 2.0;
            }
            if (field000a == 0x1c) {
                field000a = field000a + -4;
            }
            if (field000a >= frameCount) {
                field0008 = 10;
                ResetPose();
            }
        }
        break;
    case 302:
        if ((field000a == 0) && ((unsigned short)field000c == 0)) {
            velocityX = 0.0;
            velocityY = 0.0;
            gravity = 0.0;
        }
        if ((field000a == 1) && ((unsigned short)field000c == 0)) {
            hitstunFrames = 0x78;
            meter = meter + -3000;
            SetTint(0xb0,3);
            effect.type = 0x46;
            effect.palette = 0x40;
            effect.x = (double)(int(positionX));
            effect.y = (double)((int(positionY)) + -0x28);
            effect.group = 2;
            effect.owner = 1;
            effect.layer = 1;
            contextOwner->EmitEffect(&effect);
            field013c = 0x84;
            SetHorizontalShake(0x32,0x78);
            pendingContextSoundSlot = 0x25;
        }
        if (1 < field000a) {
            contextOwner->SetSceneTimer(0xf);
        }
        if (((field000a == 2) || (field000a == 7)) &&
            ((unsigned short)field000c == 0)) {
            pendingContextSoundSlot = 0x15;
            remainingHitCount = 1;
        }
        if ((field000a == 0xe) && ((unsigned short)field000c == 0)) {
            pendingContextSoundSlot = 0x14;
            remainingHitCount = 1;
        }
        if ((field000a == 0x12) && ((unsigned short)field000c == 0)) {
            pendingContextSoundSlot = 0x15;
            remainingHitCount = 1;
            velocityX = 3.0;
        }
        if (((0x12 < field000a) && (field000a < 0x17)) &&
            (velocityX = velocityX - 0.04,
            velocityX < 0.0)) {
            velocityX = 0.0;
        }
        if (((0x14 < field000a) && (field000a < 0x17)) ||
            (0x1c < field000a)) {
            velocityY = velocityY + gravity;
            velocityX = velocityX - 0.04;
            if (velocityX < 0.0) {
                velocityX = 0.0;
            }
        }
        if ((field000a == 0x18) && ((unsigned short)field000c == 0)) {
            velocityX = 1.8;
            remainingHitCount = 99;
        }
        if ((field000a == 0x20) && ((unsigned short)field000c == 0)) {
            pendingContextSoundSlot = 0x14;
            remainingHitCount = 1;
        }
        ++field000c;
        if ((unsigned short)field000c >= frameDuration) {
            field000c = 0;
            ++field000a;
            if ((0 < remainingHitCount) ||
                ((field000a < 0x22 && (0x1b < field000a)))) {
                field0168 = 0;
            }
            if (field000a == 2) {
                field013c = 0x3c;
            }
            if (field000a == 6) {
                positionX = (double)(facing * 0xf) + positionX;
            }
            if (field000a == 7) {
                positionX = (double)(facing * 0xf) + positionX;
            }
            if (field000a == 9) {
                positionX = (double)(facing * 0xf) + positionX;
            }
            if (field000a == 10) {
                if (3 < field3138) {
                    field000a = 0xc;
                    return;
                }
                positionX = (double)(facing * 0xf) + positionX;
            }
            if ((field000a == 0xc) && (field3138 < 3)) {
                field000a = 2;
                ++field3138;
            }
            if ((field000a == 0x1c) && (field3138 < 8)) {
                field000a = field000a + -4;
                ++field3138;
            }
            if (field000a >= frameCount) {
                field0008 = 3;
                ResetPose();
            }
        }
        break;
    case 303:
        if ((field000a == 0) && ((unsigned short)field000c == 0)) {
            ResetFrame();
            hitstunFrames = 0x78;
            meter = meter + -3000;
            SetTint(0xb0,3);
            effect.type = 0x46;
            effect.palette = 0x40;
            effect.x = (double)(int(positionX));
            effect.y = (double)((int(positionY)) + -0x28);
            effect.group = 2;
            effect.owner = 1;
            effect.layer = 1;
            contextOwner->EmitEffect(&effect);
            pendingContextSoundSlot = 0x25;
            effect.type = 0x47;
            contextOwner->EmitEffect(&effect);
        }
        if (1 < field000a) {
            contextOwner->SetSceneTimer(0xf);
        }
        if ((int)field000a >= 0 && field000a < 3) {
            SetHorizontalShake(0x32,3);
        }
        if ((field000a == 6) && (field0168 == 3)) {
            (*opponentSlot)->ResetPose();
            (*opponentSlot)->ResetFrame();
            (*opponentSlot)->field0008 = 0x6b;
            ResetPose();
            ResetFrame();
            field0008 = 0x131;
            positionY = (double)(field2af8[0] + 0x32);
            positionX =
            (*opponentSlot)->positionX + (-field2ad0[0] - 0x14) * facing;
            effect.type = 0;
            effect.x = (double)((int((*opponentSlot)->positionX)) + field2ad0[0]);
            effect.y = (double)((int((*opponentSlot)->positionY)) + field2af8[0]);
            effect.group = 2;
            effect.layer = 1;
            contextOwner->EmitEffect(&effect);
            break;
        }
        if ((2 < field000a) && (field000a < 7)) {
            velocityY = velocityY + gravity;
        }
        if (field000a == 6 && positionY + velocityY > 0.0) {
            ResetFrame();
            positionY = 0.0;
            field000c = 0;
            field000a = 7;
            break;
        }
        if (field000a == 6 && (*opponentSlot)->positionY >= 0.0) {
            remainingHitCount = 1;
        } else {
            remainingHitCount = 0;
        }
        ++field000c;
        if ((unsigned short)field000c >= frameDuration) {
            field000c = 0;
            ++field000a;
            field0168 = 0;
            if (field000a == 3) {
                velocityX = 1.5;
                velocityY = -2.0;
                gravity = 0.045;
            }
            if (field000a >= frameCount) {
                field0008 = 0;
                FaceOpponent();
                ResetPose();
            }
        }
        break;
    case 304:
        if ((field000a == 0) && ((unsigned short)field000c == 0)) {
            ResetFrame();
            hitstunFrames = 0x78;
            meter = meter + -3000;
            SetTint(0xb0,3);
            effect.type = 0x46;
            effect.palette = 0x40;
            effect.x = (double)(int(positionX));
            effect.y = (double)((int(positionY)) + -0x28);
            effect.group = 2;
            effect.owner = 1;
            effect.layer = 1;
            contextOwner->EmitEffect(&effect);
            pendingContextSoundSlot = 0x25;
            effect.type = 0x47;
            contextOwner->EmitEffect(&effect);
        }
        contextOwner->SetSceneTimer(0xf);
        if ((int)field000a >= 0 && field000a < 3) {
            SetHorizontalShake(0x32,3);
        }
        if ((field000a == 4) && (field0168 == 3)) {
            (*opponentSlot)->ResetPose();
            (*opponentSlot)->ResetFrame();
            (*opponentSlot)->field0008 = 0x6b;
            ResetPose();
            ResetFrame();
            field0008 = 0x132;
            (*opponentSlot)->hitstopFrames = 0x78;
            (*opponentSlot)->positionX =
            (double)(facing * 0x1e) + positionX;
            effect.type = 0;
            effect.x = (double)((int(positionX)) + facing * 0x2c);
            effect.y = (double)((int(positionY)) + -7);
            effect.group = 2;
            effect.layer = 1;
            contextOwner->EmitEffect(&effect);
            break;
        }
        ++field000c;
        if ((unsigned short)field000c >= frameDuration) {
            field000c = 0;
            ++field000a;
            field0168 = 0;
            if (field000a == 4 && (*opponentSlot)->positionY >= 0.0) {
                remainingHitCount = 1;
            } else {
                remainingHitCount = 0;
            }
            if (field000a >= frameCount) {
                field0008 = 0;
                FaceOpponent();
                ResetPose();
            }
        }
        break;
    case 305:
        SetHorizontalOffset(0x32,3);
        SetHorizontalShake(0x32,3);
        contextOwner->SetSceneTimer(0xf);
        if (3 < field000a) {
            velocityY = velocityY + gravity;
        }
        if (field000a == 4) {
            (*opponentSlot)->field0140 = 30000;
            (*opponentSlot)->field0008 = 0x67;
            (*opponentSlot)->positionX =
            (23.0 + velocityX) * facing +
            positionX;
            (*opponentSlot)->positionY =
            -52.0 + velocityY + positionY;
        }
        if (field000a == 5) {
            (*opponentSlot)->field0008 = 0x67;
            (*opponentSlot)->positionX =
            (15.0 + velocityX) * facing +
            positionX;
            (*opponentSlot)->positionY =
            -70.0 + velocityY + positionY;
        }
        if (field000a == 6) {
            (*opponentSlot)->field0008 = 0x76;
            (*opponentSlot)->positionX =
            (-31.0 + velocityX) * facing +
            positionX;
            (*opponentSlot)->positionY =
            -65.0 + velocityY + positionY;
            (*opponentSlot)->facing = facing;
        }
        if (field000a == 7) {
            (*opponentSlot)->field0008 = 0x75;
            (*opponentSlot)->positionX =
            (-36.0 + velocityX) * facing +
            positionX;
            (*opponentSlot)->positionY =
            -32.0 + velocityY + positionY;
            (*opponentSlot)->facing = facing;
        }
        if (field000a == 8) {
            (*opponentSlot)->field0008 = 0x68;
            (*opponentSlot)->positionX =
            (-7.0 + velocityX) * facing +
            positionX;
            (*opponentSlot)->positionY =
            -8.0 + velocityY + positionY;
            (*opponentSlot)->facing = -facing;
        }
        if ((field000a == 9) || (field000a == 10)) {
            (*opponentSlot)->field0008 = 0x68;
            (*opponentSlot)->positionX =
            (-4.0 + velocityX) * facing +
            positionX;
            (*opponentSlot)->positionY =
            -6.0 + velocityY + positionY;
            (*opponentSlot)->facing = -facing;
        }
        if (field000a > 8 && velocityY + positionY > 0.0) {
            ResetFrame();
            ResetPose();
            (*opponentSlot)->ResetFrame();
            (*opponentSlot)->ResetPose();
            (*opponentSlot)->field0008 = 0x62;
            (*opponentSlot)->positionY = 0;
            (*opponentSlot)->positionX = positionX;
            positionY = 0.0;
            field0008 = 0x133;
            ApplyDamage(1000,960.0);
            effect.type = 0;
            effect.x = (double)(int(positionX));
            effect.y = (double)(int(positionY));
            effect.palette = 2;
            effect.group = 2;
            effect.layer = 1;
            contextOwner->EmitEffect(&effect);
            break;
        }
        ++field000c;
        if ((unsigned short)field000c >= frameDuration) {
            field000c = 0;
            ++field000a;
            field0168 = 0;
            if (field000a == 4) {
                velocityX =
                (double)(1 - 2 * (positionX > 320.0)) * 0.6 * (double)(int)facing;
                velocityY = -5.0;
                gravity = 0.06;
            }
            if (field000a >= frameCount) {
                field000a = field000a + -2;
            }
        }
        break;
    case 306:
        SetHorizontalOffset(0x32,3);
        SetHorizontalShake(0x32,3);
        contextOwner->SetSceneTimer(0xf);
        ++field000c;
        if ((unsigned short)field000c >= frameDuration) {
            field000c = 0;
            ++field000a;
            field0168 = 0;
            if (field000a >= frameCount) {
                ResetPose();
                field0008 = 0x131;
                field000a = 4;
                (*opponentSlot)->hitstopFrames = 0;
                velocityX =
                (double)(1 - 2 * (positionX > 320.0)) * 0.6 * (double)(int)facing;
                velocityY = -5.0;
                gravity = 0.06;
            }
        }
        break;
    case 307:
        (*opponentSlot)->SetHorizontalShake(0x32,3);
        contextOwner->SetSceneTimer(0xf);
        field013e = 2;
        if ((*opponentSlot)->field0008 == 99) {
            (*opponentSlot)->field000c = 0;
        }
        if (((0x78 < field3138) && (field3138 < 0x2d0)) &&
            ((5 < field000a &&
            ((field000a < 0xc && (unsigned short)RandomRange(0, 100) < 5))
            ))) {
            effect.type = 0x195;
            effect.x = (positionX + 80.0) - (double)((unsigned short)RandomRange(0, 0xa0));
            effect.y = (double)-(int)(unsigned short)RandomRange(0, 0x32);
            effect.group = 0;
            effect.layer = 1;
            effect.flag0018 = (unsigned char)facing;
            EmitLocalEffect(&effect);
        }
        if (3 < field000a) {
            velocityY = velocityY + gravity;
        }
        if (5 < field000a) {
            ++field3138;
        }
        if (field3138 == 0x50) {
            effect.type = 0x191;
            effect.x = (double)((int(positionX)) + facing * 0x1e);
            effect.y = -320.0;
            effect.group = 0;
            effect.layer = 1;
            effect.owner = 1;
            effect.field0028 = 1;
            effect.flag0018 = (unsigned char)facing;
            EmitLocalEffect(&effect);
        }
        if (field3138 == 0x78) {
            effect.type = 0x192;
            effect.x = (double)((int(positionX)) - facing * 0x14);
            effect.y = -320.0;
            effect.group = 0;
            effect.layer = 1;
            effect.field0028 = 1;
            effect.flag0018 = (unsigned char)facing;
            effect.owner = 1;
            EmitLocalEffect(&effect);
        }
        if (field000a == 9 && velocityY + positionY > 0.0) {
            ResetFrame();
            field000c = 0;
            field000a = 10;
            (*opponentSlot)->ResetFrame();
            (*opponentSlot)->ResetPose();
            (*opponentSlot)->field0008 = 0x62;
            positionY = 0.0;
            (*opponentSlot)->field0140 = 30000;
            ApplyDamage(300,960.0);
            effect.type = 0;
            effect.x = (double)(int(positionX));
            effect.y = (double)(int(positionY));
            effect.palette = 2;
            effect.group = 2;
            effect.layer = 1;
            contextOwner->EmitEffect(&effect);
            break;
        }
        if (field000a == 15 && velocityY + positionY > 0.0) {
            ResetFrame();
            field000c = 0;
            field000a = 0x10;
            (*opponentSlot)->ResetFrame();
            (*opponentSlot)->ResetPose();
            (*opponentSlot)->field0008 = 0x62;
            positionY = 0.0;
            ApplyDamage(0x578,960.0);
            (*opponentSlot)->field0140 = 0;
            SetVerticalShake(10,10);
            (*opponentSlot)->hitstopFrames = 0x78;
            effect.type = 0;
            effect.x = (double)(int(positionX));
            effect.y = (double)(int(positionY));
            effect.palette = 0x16;
            effect.group = 2;
            effect.layer = 1;
            contextOwner->EmitEffect(&effect);
            break;
        }
        if (field000a == 20 && velocityY + positionY > 0.0) {
            ResetFrame();
            field000c = 0;
            field000a = 0x15;
            (*opponentSlot)->ResetFrame();
            (*opponentSlot)->ResetPose();
            positionY = 0.0;
            break;
        }
        if ((field000a == 0xb) && (0x334 < field3138)) {
            field000a = 0xc;
            field000c = 0;
            velocityY = -5.0;
            gravity = 0.06;
            break;
        }
        ++field000c;
        if ((unsigned short)field000c >= frameDuration) {
            field000c = 0;
            ++field000a;
            field0168 = 0;
            if (field000a == 6) {
                velocityX = 0.0;
                velocityY = -3.9;
                gravity = 0.08;
            }
            if (field000a == 0xc) {
                if (field3138 <= 730) {
                    field000a = 6;
                    velocityX = 0.0;
                    velocityY = -3.9;
                    gravity = 0.08;
                }
                else {
                    field000a = 0xb;
                }
            }
            if (field000a == 0x12) {
                velocityX = -0.6;
                velocityY = -1.5;
                gravity = 0.038;
            }
            if ((field000a == 0x1f) && (field313c < 4)) {
                field000a = field000a + -2;
                ++field313c;
            }
            if (field000a >= frameCount) {
                ResetPose();
                field0008 = 0;
                FaceOpponent();
            }
        }
        break;
    case 308:
        if ((field000a == 0) && ((unsigned short)field000c == 0)) {
            ResetFrame();
            hitstunFrames = 0x78;
            meter = meter + -1000;
            SetTint(0xb0,3);
            effect.type = 0x44;
            effect.palette = 0x13;
            effect.x = (double)(int(positionX));
            effect.y = (double)((int(positionY)) + -0x28);
            effect.group = 2;
            effect.owner = 1;
            effect.layer = 1;
            contextOwner->EmitEffect(&effect);
        }
        if ((int)field000a >= 0 && field000a < 3) {
            SetHorizontalShake(0x32,3);
        }
        if (((field000a == 3) || (field000a == 4)) &&
            (field0168 == 3)) {
            if (positionX > 580.0) {
                positionX = 580.0;
                velocityX = 0.0;
            }
            if (positionX < 60.0) {
                positionX = 60.0;
                velocityX = 0.0;
            }
            (*opponentSlot)->ResetPose();
            (*opponentSlot)->ResetFrame();
            (*opponentSlot)->field0008 = 0x67;
            (*opponentSlot)->positionX =
            (double)(facing * 0x16) + positionX;
            (*opponentSlot)->positionY = positionY - 52.0;
            ResetPose();
            gravity = 0.025;
            field0008 = 0x137;
            effect.type = 0;
            effect.x = (double)((int(positionX)) + facing * 0x2c);
            effect.y = (double)((int(positionY)) + -0x2c);
            effect.group = 2;
            effect.layer = 1;
            contextOwner->EmitEffect(&effect);
            break;
        }
        if ((4 < field000a) && (field000a < 0x70)) {
            velocityY = velocityY + gravity;
        }
        if (field000a < 12 && positionY + velocityY > 0.0) {
            ResetFrame();
            positionY = 0.0;
            field000c = 0;
            field000a = 0xc;
            break;
        }
        if (6 < field000a) {
            velocityX = velocityX - 0.025;
        }
        if (velocityX < 0.0) {
            velocityX = 0.0;
        }
        if ((field000a == 3 || field000a == 4) && (*opponentSlot)->positionY < 0.0) {
            remainingHitCount = 1;
        } else {
            remainingHitCount = 0;
        }
        ++field000c;
        if ((unsigned short)field000c >= frameDuration) {
            field000c = 0;
            ++field000a;
            field0168 = 0;
            if (field000a == 3) {
                velocityX = 2.0;
                velocityY = -3.2;
                gravity = 0.035;
                field013c = 6;
            }
            if ((field000a == 5) && (field3138 < 1)) {
                field000a = field000a + -2;
                ++field3138;
            }
            if (field000a == 6) {
                velocityY = velocityY * 0.5;
            }
            if (field000a == 0xc) {
                field000a = field000a + -4;
            }
            if (field000a >= frameCount) {
                field0008 = 3;
                FaceOpponent();
                ResetPose();
            }
        }
        break;
    case 309:
        if ((field000a == 0) && ((unsigned short)field000c == 0)) {
            ResetFrame();
            hitstunFrames = 0x78;
            meter = meter + -2000;
            SetTint(0xb0,3);
            effect.type = 0x45;
            effect.palette = 5;
            effect.x = (double)(int(positionX));
            effect.y = (double)((int(positionY)) + -0x28);
            effect.group = 2;
            effect.owner = 1;
            effect.layer = 1;
            contextOwner->EmitEffect(&effect);
        }
        if ((int)field000a >= 0 && field000a < 3) {
            SetHorizontalShake(0x32,3);
        }
        if (((field000a == 3) || (field000a == 4)) &&
            (field0168 == 3)) {
            if (positionX > 580.0) {
                positionX = 580.0;
                velocityX = 0.0;
            }
            if (positionX < 60.0) {
                positionX = 60.0;
                velocityX = 0.0;
            }
            (*opponentSlot)->ResetPose();
            (*opponentSlot)->ResetFrame();
            (*opponentSlot)->field0008 = 0x67;
            (*opponentSlot)->positionX =
            (double)(facing * 0x16) + positionX;
            (*opponentSlot)->positionY = positionY - 52.0;
            ResetPose();
            gravity = 0.025;
            field0008 = 0x138;
            effect.type = 0;
            effect.x = (double)((int(positionX)) + facing * 0x2c);
            effect.y = (double)((int(positionY)) + -0x2c);
            effect.group = 2;
            effect.layer = 1;
            contextOwner->EmitEffect(&effect);
            break;
        }
        if ((4 < field000a) && (field000a < 0x70)) {
            velocityY = velocityY + gravity;
        }
        if (field000a < 12 && positionY + velocityY > 0.0) {
            ResetFrame();
            positionY = 0.0;
            field000c = 0;
            field000a = 0xc;
            break;
        }
        if (6 < field000a) {
            velocityX = velocityX - 0.025;
        }
        if (velocityX < 0.0) {
            velocityX = 0.0;
        }
        if ((field000a == 3 || field000a == 4) && (*opponentSlot)->positionY < 0.0) {
            remainingHitCount = 1;
        } else {
            remainingHitCount = 0;
        }
        ++field000c;
        if ((unsigned short)field000c >= frameDuration) {
            field000c = 0;
            ++field000a;
            field0168 = 0;
            if (field000a == 3) {
                velocityX = 2.0;
                velocityY = -3.2;
                gravity = 0.035;
                field013c = 0xc;
            }
            if ((field000a == 5) && (field3138 < 3)) {
                field000a = field000a + -2;
                ++field3138;
            }
            if (field000a == 6) {
                velocityY = velocityY * 0.5;
            }
            if (field000a == 0xc) {
                field000a = field000a + -4;
            }
            if (field000a >= frameCount) {
                field0008 = 3;
                FaceOpponent();
                ResetPose();
            }
        }
        break;
    case 310:
        if ((field000a == 0) && ((unsigned short)field000c == 0)) {
            ResetFrame();
            hitstunFrames = 0x78;
            meter = meter + -3000;
            SetTint(0xb0,3);
            effect.type = 0x46;
            effect.palette = 0x40;
            effect.x = (double)(int(positionX));
            effect.y = (double)((int(positionY)) + -0x28);
            effect.group = 2;
            effect.owner = 1;
            effect.layer = 1;
            contextOwner->EmitEffect(&effect);
            pendingContextSoundSlot = 0x25;
        }
        contextOwner->SetSceneTimer(0xf);
        if ((int)field000a >= 0 && field000a < 3) {
            SetHorizontalShake(0x32,3);
        }
        if (((field000a == 3) || (field000a == 4)) &&
            (field0168 == 3)) {
            if (positionX > 580.0) {
                positionX = 580.0;
                velocityX = 0.0;
            }
            if (positionX < 60.0) {
                positionX = 60.0;
                velocityX = 0.0;
            }
            (*opponentSlot)->ResetPose();
            (*opponentSlot)->ResetFrame();
            (*opponentSlot)->field0008 = 0x67;
            (*opponentSlot)->positionX =
            (double)(facing * 0x16) + positionX;
            (*opponentSlot)->positionY = positionY - 52.0;
            ResetPose();
            gravity = 0.025;
            field0008 = 0x139;
            effect.type = 0;
            effect.x = (double)((int(positionX)) + facing * 0x2c);
            effect.y = (double)((int(positionY)) + -0x2c);
            effect.group = 2;
            effect.layer = 1;
            contextOwner->EmitEffect(&effect);
            break;
        }
        if (6 < field000a) {
            velocityX = velocityX - 0.025;
        }
        if (velocityX < 0.0) {
            velocityX = 0.0;
        }
        if ((4 < field000a) && (field000a < 0x70)) {
            velocityY = velocityY + gravity;
        }
        if (field000a < 12 && positionY + velocityY > 0.0) {
            ResetFrame();
            positionY = 0.0;
            field000c = 0;
            field000a = 0xc;
            break;
        }
        if ((field000a == 3 || field000a == 4) && (*opponentSlot)->positionY < 0.0) {
            remainingHitCount = 1;
        } else {
            remainingHitCount = 0;
        }
        ++field000c;
        if ((unsigned short)field000c >= frameDuration) {
            field000c = 0;
            ++field000a;
            field0168 = 0;
            if (field000a == 3) {
                velocityX = 2.0;
                velocityY = -3.2;
                gravity = 0.035;
                field013c = 0x12;
            }
            if ((field000a == 5) && (field3138 < 5)) {
                field000a = field000a + -2;
                ++field3138;
            }
            if (field000a == 6) {
                velocityY = velocityY * 0.5;
            }
            if (field000a == 0xc) {
                field000a = field000a + -4;
            }
            if (field000a >= frameCount) {
                field0008 = 3;
                FaceOpponent();
                ResetPose();
            }
        }
        break;
    case 311:
        field013e = 2;
        if (field000a < 0xe) {
            if (positionX > 580.0) {
                positionX = 580.0;
                velocityX = 0.0;
            }
            if (positionX < 60.0) {
                positionX = 60.0;
                velocityX = 0.0;
            }
            SetHorizontalOffset(0x32,3);
            SetHorizontalShake(0x32,3);
        }
        if (((field000a < 0xd) ||
            ((0xe < field000a && (field000a < 0x12)))) &&
            (velocityY = velocityY + gravity,
            0.0 < velocityY + positionY)) {
            if (field000a < 0xd) {
                positionY = 0.0;
                ResetFrame();
                (*opponentSlot)->ResetPose();
                (*opponentSlot)->field0008 = 0x62;
                (*opponentSlot)->positionY = 0;
                (*opponentSlot)->positionX =
                (double)(int)facing + positionX;
                (*opponentSlot)->facing = -facing;
                (*opponentSlot)->ResetFrame();
                (*opponentSlot)->hitstopFrames = 0x7e;
                ApplyDamage(0x92e,750.0);
                SetVerticalShake(10,0);
                field000c = 0;
                field000a = 0xd;
                pendingContextSoundSlot = 0x16;
                return;
            }
            if (field000a == 0x11) {
                positionY = 0.0;
                ResetFrame();
                field000c = 0;
                field000a = 0x12;
                return;
            }
        }
        if ((field000a < 0xd) &&
            (velocityX = velocityX - 0.025,
            velocityX < 0.0)) {
            velocityX = 0.0;
        }
        if (field000a < 4) {
            (*opponentSlot)->field0008 = 0x67;
            (*opponentSlot)->positionX =
            (double)(facing * 0x16) + positionX;
            (*opponentSlot)->positionY = positionY - 52.0;
        }
        if (field000a == 4) {
            (*opponentSlot)->field0008 = 0x67;
            (*opponentSlot)->positionX =
            (15.0 + velocityX) * facing +
            positionX;
            (*opponentSlot)->positionY =
            -70.0 + velocityY + positionY;
        }
        if (field000a == 5) {
            (*opponentSlot)->field0008 = 0x76;
            (*opponentSlot)->positionX =
            (-25.0 + velocityX) * facing +
            positionX;
            (*opponentSlot)->positionY =
            -65.0 + velocityY + positionY;
            (*opponentSlot)->facing = facing;
        }
        if (field000a == 6) {
            (*opponentSlot)->field0008 = 0x75;
            (*opponentSlot)->positionX =
            (-28.0 + velocityX) * facing +
            positionX;
            (*opponentSlot)->positionY =
            -43.0 + velocityY + positionY;
            (*opponentSlot)->facing = facing;
        }
        if (field000a == 7) {
            (*opponentSlot)->field0008 = 0x75;
            (*opponentSlot)->positionX =
            (-12.0 + velocityX) * facing +
            positionX;
            (*opponentSlot)->positionY =
            -29.0 + velocityY + positionY;
            (*opponentSlot)->facing = facing;
        }
        if (field000a == 8) {
            (*opponentSlot)->field0008 = 0x68;
            (*opponentSlot)->positionX =
            (12.0 + velocityX) * facing +
            positionX;
            (*opponentSlot)->positionY =
            -23.0 + velocityY + positionY;
            (*opponentSlot)->facing = -facing;
        }
        if (field000a == 9) {
            (*opponentSlot)->field0008 = 0x68;
            (*opponentSlot)->positionX =
            (23.0 + velocityX) * facing +
            positionX;
            (*opponentSlot)->positionY =
            -36.0 + velocityY + positionY;
            (*opponentSlot)->facing = -facing;
        }
        if (field000a == 10) {
            (*opponentSlot)->field0008 = 0x67;
            (*opponentSlot)->positionX =
            (28.0 + velocityX) * facing +
            positionX;
            (*opponentSlot)->positionY =
            -58.0 + velocityY + positionY;
            (*opponentSlot)->facing = -facing;
        }
        if (field000a == 0xb) {
            (*opponentSlot)->field0008 = 0x67;
            (*opponentSlot)->positionX =
            (14.0 + velocityX) * facing +
            positionX;
            (*opponentSlot)->positionY =
            -73.0 + velocityY + positionY;
            (*opponentSlot)->facing = -facing;
        }
        if (field000a == 0xc) {
            (*opponentSlot)->field0008 = 0x76;
            (*opponentSlot)->positionX =
            (-12.0 + velocityX) * facing +
            positionX;
            (*opponentSlot)->positionY =
            -78.0 + velocityY + positionY;
            (*opponentSlot)->facing = facing;
        }
        ++field000c;
        if ((unsigned short)field000c >= frameDuration) {
            field000c = 0;
            ++field000a;
            field0168 = 0;
            if (field000a == 0xd) {
                field000a = field000a + -8;
            }
            if (field000a == 0xf) {
                (*opponentSlot)->hitstopFrames = 3;
                velocityX = -1.2;
                velocityY = -2.0;
                gravity = 0.035;
                (*opponentSlot)->positionY = -1.0;
                (*opponentSlot)->ResetPose();
                (*opponentSlot)->ResetFrame();
                (*opponentSlot)->knockbackVelocityX = -1.2;
                (*opponentSlot)->knockbackVelocityY = -2.0;
                (*opponentSlot)->field0008 = 0x3b;
            }
            if (field000a >= frameCount) {
                ResetPose();
                FaceOpponent();
                field0008 = 3;
            }
        }
        break;
    case 312:
        field013e = 2;
        if (field000a < 0x19) {
            if (positionX > 580.0) {
                positionX = 580.0;
                velocityX = 0.0;
            }
            if (positionX < 60.0) {
                positionX = 60.0;
                velocityX = 0.0;
            }
            SetHorizontalOffset(0x32,3);
            SetHorizontalShake(0x32,3);
        }
        if ((((field000a < 0xd) ||
            ((0xe < field000a && (field000a < 0x19)))) ||
            ((0x1a < field000a && (field000a < 0x1e)))) &&
            (velocityY = velocityY + gravity,
            0.0 < velocityY + positionY)) {
            if (field000a < 0xd) {
                positionY = 0.0;
                ResetFrame();
                (*opponentSlot)->ResetPose();
                (*opponentSlot)->field0008 = 0x62;
                (*opponentSlot)->positionY = 0;
                (*opponentSlot)->ResetFrame();
                (*opponentSlot)->hitstopFrames = 0x96;
                (*opponentSlot)->positionX =
                (double)(int)facing + positionX;
                (*opponentSlot)->facing = -facing;
                ApplyDamage(1000,980.0);
                SetVerticalShake(10,0);
                (*opponentSlot)->field0140 = 30000;
                field000c = 0;
                field000a = 0xd;
                pendingContextSoundSlot = 0x16;
                return;
            }
            if ((0xe < field000a) && (field000a < 0x19)) {
                positionY = 0.0;
                ResetFrame();
                (*opponentSlot)->ResetPose();
                (*opponentSlot)->field0008 = 0x62;
                (*opponentSlot)->positionY = 0;
                (*opponentSlot)->positionX =
                (double)(int)facing + positionX;
                (*opponentSlot)->facing = -facing;
                (*opponentSlot)->ResetFrame();
                (*opponentSlot)->hitstopFrames = 0x7e;
                SetVerticalShake(0xf,0);
                ApplyDamage(0x834,980.0);
                (*opponentSlot)->field0140 = 0;
                field000c = 0;
                field000a = 0x19;
                pendingContextSoundSlot = 0x16;
                return;
            }
            if (field000a == 0x1d) {
                positionY = 0.0;
                ResetFrame();
                field000c = 0;
                field000a = 0x1e;
                return;
            }
        }
        if ((field000a < 0xd) &&
            (velocityX = velocityX - 0.025,
            velocityX < 0.0)) {
            velocityX = 0.0;
        }
        if (((0xe < field000a) && (field000a < 0x19)) &&
            (velocityX = velocityX + 0.025,
            velocityX > 0.0)) {
            velocityX = 0.0;
        }
        if (field000a < 4) {
            (*opponentSlot)->field0008 = 0x67;
            (*opponentSlot)->positionX =
            (double)(facing * 0x16) + positionX;
            (*opponentSlot)->positionY = positionY - 52.0;
        }
        if (((field000a == 4) || (field000a == 0xf)) ||
            (field000a == 0x10)) {
            (*opponentSlot)->field0008 = 0x67;
            (*opponentSlot)->positionX =
            (15.0 + velocityX) * facing +
            positionX;
            (*opponentSlot)->positionY =
            -70.0 + velocityY + positionY;
        }
        if ((field000a == 5) || (field000a == 0x11)) {
            (*opponentSlot)->field0008 = 0x76;
            (*opponentSlot)->positionX =
            (-25.0 + velocityX) * facing +
            positionX;
            (*opponentSlot)->positionY =
            -65.0 + velocityY + positionY;
            (*opponentSlot)->facing = facing;
        }
        if ((field000a == 6) || (field000a == 0x12)) {
            (*opponentSlot)->field0008 = 0x75;
            (*opponentSlot)->positionX =
            (-28.0 + velocityX) * facing +
            positionX;
            (*opponentSlot)->positionY =
            -43.0 + velocityY + positionY;
            (*opponentSlot)->facing = facing;
        }
        if ((field000a == 7) || (field000a == 0x13)) {
            (*opponentSlot)->field0008 = 0x75;
            (*opponentSlot)->positionX =
            (-12.0 + velocityX) * facing +
            positionX;
            (*opponentSlot)->positionY =
            -29.0 + velocityY + positionY;
            (*opponentSlot)->facing = facing;
        }
        if ((field000a == 8) || (field000a == 0x14)) {
            (*opponentSlot)->field0008 = 0x68;
            (*opponentSlot)->positionX =
            (12.0 + velocityX) * facing +
            positionX;
            (*opponentSlot)->positionY =
            -23.0 + velocityY + positionY;
            (*opponentSlot)->facing = -facing;
        }
        if ((field000a == 9) || (field000a == 0x15)) {
            (*opponentSlot)->field0008 = 0x68;
            (*opponentSlot)->positionX =
            (23.0 + velocityX) * facing +
            positionX;
            (*opponentSlot)->positionY =
            -36.0 + velocityY + positionY;
            (*opponentSlot)->facing = -facing;
        }
        if ((field000a == 10) || (field000a == 0x16)) {
            (*opponentSlot)->field0008 = 0x67;
            (*opponentSlot)->positionX =
            (28.0 + velocityX) * facing +
            positionX;
            (*opponentSlot)->positionY =
            -58.0 + velocityY + positionY;
            (*opponentSlot)->facing = -facing;
        }
        if ((field000a == 0xb) || (field000a == 0x17)) {
            (*opponentSlot)->field0008 = 0x67;
            (*opponentSlot)->positionX =
            (14.0 + velocityX) * facing +
            positionX;
            (*opponentSlot)->positionY =
            -73.0 + velocityY + positionY;
            (*opponentSlot)->facing = -facing;
        }
        if ((field000a == 0xc) || (field000a == 0x18)) {
            (*opponentSlot)->field0008 = 0x76;
            (*opponentSlot)->positionX =
            (-12.0 + velocityX) * facing +
            positionX;
            (*opponentSlot)->positionY =
            -78.0 + velocityY + positionY;
            (*opponentSlot)->facing = facing;
        }
        ++field000c;
        if ((unsigned short)field000c >= frameDuration) {
            field000c = 0;
            ++field000a;
            field0168 = 0;
            if ((field000a == 0xd) || (field000a == 0x19)) {
                field000a = field000a + -8;
            }
            if (field000a == 0xf) {
                velocityX = -4.0;
                velocityY = -4.0;
                gravity = 0.025;
                (*opponentSlot)->hitstopFrames = 3;
            }
            if (field000a == 0x1b) {
                velocityX = -1.8;
                velocityY = -2.3;
                gravity = 0.035;
                (*opponentSlot)->ResetPose();
                (*opponentSlot)->ResetFrame();
                (*opponentSlot)->knockbackVelocityX = -1.8;
                (*opponentSlot)->knockbackVelocityY = -2.3;
                (*opponentSlot)->field0008 = 0x3b;
            }
            if (field000a >= frameCount) {
                ResetPose();
                FaceOpponent();
                field0008 = 3;
            }
        }
        break;
    case 313:
        field013e = 2;
        contextOwner->SetSceneTimer(0xf);
        if (field000a < 0x19) {
            if (positionX > 580.0) {
                positionX = 580.0;
                velocityX = 0.0;
            }
            if (positionX < 60.0) {
                positionX = 60.0;
                velocityX = 0.0;
            }
            SetHorizontalOffset(0x32,3);
            SetHorizontalShake(0x32,3);
        }
        if ((((field000a < 0xd) ||
            ((0xe < field000a && (field000a < 0x19)))) ||
            ((0x1a < field000a && (field000a < 0x1e)))) &&
            (velocityY = velocityY + gravity,
            0.0 < velocityY + positionY)) {
            if (field000a < 0xd) {
                positionY = 0.0;
                ResetFrame();
                (*opponentSlot)->ResetPose();
                (*opponentSlot)->field0008 = 0x62;
                (*opponentSlot)->positionY = 0;
                (*opponentSlot)->ResetFrame();
                (*opponentSlot)->hitstopFrames = 0x96;
                (*opponentSlot)->positionX =
                (double)(int)facing + positionX;
                (*opponentSlot)->facing = -facing;
                ApplyDamage(1000,980.0);
                SetVerticalShake(10,0);
                (*opponentSlot)->field0140 = 30000;
                field000c = 0;
                field000a = 0xd;
                pendingContextSoundSlot = 0x16;
                return;
            }
            if ((0xe < field000a) && (field000a < 0x19)) {
                positionY = 0.0;
                ResetFrame();
                (*opponentSlot)->ResetPose();
                (*opponentSlot)->field0008 = 0x62;
                (*opponentSlot)->positionY = 0;
                (*opponentSlot)->positionX =
                (double)(int)facing + positionX;
                (*opponentSlot)->facing = -facing;
                (*opponentSlot)->ResetFrame();
                (*opponentSlot)->hitstopFrames = 0xba;
                ApplyDamage(0xed8,980.0);
                (*opponentSlot)->field0140 = 0;
                SetVerticalShake(0x14,0x1e);
                field000c = 0;
                field000a = 0x19;
                pendingContextSoundSlot = 0x16;
                return;
            }
            if (field000a == 0x1d) {
                positionY = 0.0;
                ResetFrame();
                field000c = 0;
                field000a = 0x1e;
                return;
            }
        }
        if ((field000a < 0xd) &&
            (velocityX = velocityX - 0.025,
            velocityX < 0.0)) {
            velocityX = 0.0;
        }
        if (((0xe < field000a) && (field000a < 0x19)) &&
            (velocityX = velocityX + 0.025,
            velocityX > 0.0)) {
            velocityX = 0.0;
        }
        if (field000a < 4) {
            (*opponentSlot)->field0008 = 0x67;
            (*opponentSlot)->positionX =
            (double)(facing * 0x16) + positionX;
            (*opponentSlot)->positionY = positionY - 52.0;
        }
        if (((field000a == 4) || (field000a == 0xf)) ||
            (field000a == 0x10)) {
            (*opponentSlot)->field0008 = 0x67;
            (*opponentSlot)->positionX =
            (15.0 + velocityX) * facing +
            positionX;
            (*opponentSlot)->positionY =
            -70.0 + velocityY + positionY;
        }
        if ((field000a == 5) || (field000a == 0x11)) {
            (*opponentSlot)->field0008 = 0x76;
            (*opponentSlot)->positionX =
            (-25.0 + velocityX) * facing +
            positionX;
            (*opponentSlot)->positionY =
            -65.0 + velocityY + positionY;
            (*opponentSlot)->facing = facing;
        }
        if ((field000a == 6) || (field000a == 0x12)) {
            (*opponentSlot)->field0008 = 0x75;
            (*opponentSlot)->positionX =
            (-28.0 + velocityX) * facing +
            positionX;
            (*opponentSlot)->positionY =
            -43.0 + velocityY + positionY;
            (*opponentSlot)->facing = facing;
        }
        if ((field000a == 7) || (field000a == 0x13)) {
            (*opponentSlot)->field0008 = 0x75;
            (*opponentSlot)->positionX =
            (-12.0 + velocityX) * facing +
            positionX;
            (*opponentSlot)->positionY =
            -29.0 + velocityY + positionY;
            (*opponentSlot)->facing = facing;
        }
        if ((field000a == 8) || (field000a == 0x14)) {
            (*opponentSlot)->field0008 = 0x68;
            (*opponentSlot)->positionX =
            (12.0 + velocityX) * facing +
            positionX;
            (*opponentSlot)->positionY =
            -23.0 + velocityY + positionY;
            (*opponentSlot)->facing = -facing;
        }
        if ((field000a == 9) || (field000a == 0x15)) {
            (*opponentSlot)->field0008 = 0x68;
            (*opponentSlot)->positionX =
            (23.0 + velocityX) * facing +
            positionX;
            (*opponentSlot)->positionY =
            -36.0 + velocityY + positionY;
            (*opponentSlot)->facing = -facing;
        }
        if ((field000a == 10) || (field000a == 0x16)) {
            (*opponentSlot)->field0008 = 0x67;
            (*opponentSlot)->positionX =
            (28.0 + velocityX) * facing +
            positionX;
            (*opponentSlot)->positionY =
            -58.0 + velocityY + positionY;
            (*opponentSlot)->facing = -facing;
        }
        if ((field000a == 0xb) || (field000a == 0x17)) {
            (*opponentSlot)->field0008 = 0x67;
            (*opponentSlot)->positionX =
            (14.0 + velocityX) * facing +
            positionX;
            (*opponentSlot)->positionY =
            -73.0 + velocityY + positionY;
            (*opponentSlot)->facing = -facing;
        }
        if ((field000a == 0xc) || (field000a == 0x18)) {
            (*opponentSlot)->field0008 = 0x76;
            (*opponentSlot)->positionX =
            (-12.0 + velocityX) * facing +
            positionX;
            (*opponentSlot)->positionY =
            -78.0 + velocityY + positionY;
            (*opponentSlot)->facing = facing;
        }
        ++field000c;
        if ((unsigned short)field000c >= frameDuration) {
            field000c = 0;
            ++field000a;
            field0168 = 0;
            if ((field000a == 0xd) || (field000a == 0x19)) {
                field000a = field000a + -8;
            }
            if (field000a == 0xf) {
                velocityX = -4.0;
                velocityY = -7.0;
                gravity = 0.025;
                (*opponentSlot)->hitstopFrames = 3;
            }
            if (field000a == 0x1b) {
                velocityX = -1.8;
                velocityY = -2.3;
                gravity = 0.035;
                (*opponentSlot)->ResetPose();
                (*opponentSlot)->ResetFrame();
                (*opponentSlot)->knockbackVelocityX = -1.8;
                (*opponentSlot)->knockbackVelocityY = -2.3;
                (*opponentSlot)->field0008 = 0x3b;
            }
            if (field000a >= frameCount) {
                ResetPose();
                FaceOpponent();
                field0008 = 3;
            }
        }
        break;
    case 314:
        if ((field000a == 0) && ((unsigned short)field000c == 0)) {
            velocityX = 0.0;
            velocityY = 0.0;
            gravity = 0.0;
        }
        if ((field000a == 1) && ((unsigned short)field000c == 0)) {
            hitstunFrames = 0x78;
            meter = meter + -1000;
            SetTint(0xb0,3);
            effect.type = 0x44;
            effect.palette = 0x13;
            effect.x = (double)((int(positionX)) + facing * 0xf);
            effect.y = (double)((int(positionY)) + -0x22);
            effect.group = 2;
            effect.owner = 1;
            effect.layer = 1;
            contextOwner->EmitEffect(&effect);
            SetHorizontalShake(0x32,0x78);
            remainingHitCount = 0xc;
        }
        if (((unsigned short)field000c == 0) &&
            ((((field000a == 9 || (field000a == 0xb)) ||
            (field000a == 0xd)) || (field000a == 0xf)))) {
            pendingContextSoundSlot = 0x15;
        }
        if ((7 < field000a) && (field000a < 0x10)) {
            if (inputX == facing) {
                velocityX = velocityX + 0.012;
            }
            if ((int)inputX == -(int)facing) {
                velocityX = velocityX - 0.012;
            }
            if (velocityX < -1.2) { velocityX = -1.2; } else if (velocityX > 1.2) { velocityX = 1.2; }
        }
        if (0xf < field000a) {
            if ((velocityX > 0.0) &&
                (velocityX = velocityX - 0.01,
                velocityX < 0.0)) {
                velocityX = 0.0;
            }
            if ((velocityX < 0.0) &&
                (velocityX = velocityX + 0.01,
                velocityX > 0.0)) {
                velocityX = 0.0;
            }
        }
        ++field000c;
        if ((unsigned short)field000c >= frameDuration) {
            field000c = 0;
            ++field000a;
            if ((field000a == 0x10) && (field3138 < 3)) {
                field000a = field000a + -4;
                ++field3138;
            }
            if ((((field000a == 1) || (field000a == 9)) ||
                (field000a == 0xb)) ||
                (((field000a == 0xd || (field000a == 0xf)) ||
                (field000a == 0x10)))) {
                field0168 = 0;
            }
            if (field000a >= frameCount) {
                field0008 = 0;
                ResetPose();
            }
        }
        break;
    case 315:
        if ((field000a == 0) && ((unsigned short)field000c == 0)) {
            velocityX = 0.0;
            velocityY = 0.0;
            gravity = 0.0;
        }
        if ((field000a == 1) && ((unsigned short)field000c == 0)) {
            hitstunFrames = 0x78;
            meter = meter + -2000;
            SetTint(0xb0,3);
            effect.type = 0x45;
            effect.palette = 5;
            effect.x = (double)((int(positionX)) + facing * 0xf);
            effect.y = (double)((int(positionY)) + -0x22);
            effect.group = 2;
            effect.owner = 1;
            effect.layer = 1;
            contextOwner->EmitEffect(&effect);
            SetHorizontalShake(0x32,0x78);
            remainingHitCount = 99;
        }
        if (((unsigned short)field000c == 0) &&
            ((((field000a == 9 || (field000a == 0xb)) ||
            (field000a == 0xd)) || (field000a == 0xf)))) {
            pendingContextSoundSlot = 0x15;
        }
        if ((7 < field000a) && (field000a < 0x10)) {
            if (inputX == facing) {
                velocityX = velocityX + 0.012;
            }
            if ((int)inputX == -(int)facing) {
                velocityX = velocityX - 0.012;
            }
            if (velocityX < -1.3) { velocityX = -1.3; } else if (velocityX > 1.3) { velocityX = 1.3; }
        }
        if (0xf < field000a) {
            if ((velocityX > 0.0) &&
                (velocityX = velocityX - 0.01,
                velocityX < 0.0)) {
                velocityX = 0.0;
            }
            if ((velocityX < 0.0) &&
                (velocityX = velocityX + 0.01,
                velocityX > 0.0)) {
                velocityX = 0.0;
            }
        }
        ++field000c;
        if ((unsigned short)field000c >= frameDuration) {
            field000c = 0;
            ++field000a;
            if ((field000a == 0x10) && (field3138 < 5)) {
                field000a = field000a + -4;
                ++field3138;
            }
            if (((((field000a == 1) || (field000a == 9)) ||
                (field000a == 0xb)) ||
                ((field000a == 0xd || (field000a == 0xf)))) ||
                (field000a == 0x10)) {
                field0168 = 0;
            }
            if (field000a >= frameCount) {
                field0008 = 0;
                ResetPose();
            }
        }
        break;
    case 316:
        if ((field000a == 0) && ((unsigned short)field000c == 0)) {
            velocityX = 0.0;
            velocityY = 0.0;
            gravity = 0.0;
        }
        if (field000a > 0) {
            contextOwner->SetSceneTimer(0xf);
        }
        if ((field000a == 1) && ((unsigned short)field000c == 0)) {
            hitstunFrames = 0x78;
            meter = meter + -3000;
            SetTint(0xb0,3);
            effect.type = 0x46;
            effect.palette = 0x40;
            effect.x = (double)((int(positionX)) + facing * 0xf);
            effect.y = (double)((int(positionY)) + -0x22);
            effect.group = 2;
            effect.owner = 1;
            effect.layer = 1;
            contextOwner->EmitEffect(&effect);
            SetHorizontalShake(0x32,0x78);
            remainingHitCount = 99;
            pendingContextSoundSlot = 0x25;
        }
        if (((unsigned short)field000c == 0) &&
            ((((field000a == 9 || (field000a == 0xb)) ||
            (field000a == 0xd)) || (field000a == 0xf)))) {
            pendingContextSoundSlot = 0x15;
        }
        if ((7 < field000a) && (field000a < 0x10)) {
            if (inputX == facing) {
                velocityX = velocityX + 0.012;
            }
            if ((int)inputX == -(int)facing) {
                velocityX = velocityX - 0.012;
            }
            if (velocityX < -1.4) { velocityX = -1.4; } else if (velocityX > 1.4) { velocityX = 1.4; }
        }
        if (0xf < field000a) {
            if ((velocityX > 0.0) &&
                (velocityX = velocityX - 0.01,
                velocityX < 0.0)) {
                velocityX = 0.0;
            }
            if ((velocityX < 0.0) &&
                (velocityX = velocityX + 0.01,
                velocityX > 0.0)) {
                velocityX = 0.0;
            }
        }
        ++field000c;
        if ((unsigned short)field000c >= frameDuration) {
            field000c = 0;
            ++field000a;
            if ((field000a == 0x10) && (field3138 < 10)) {
                field000a = field000a + -4;
                ++field3138;
            }
            if ((((field000a == 1) || (field000a == 9)) ||
                (field000a == 0xb)) ||
                (((field000a == 0xd || (field000a == 0xf)) ||
                (field000a == 0x10)))) {
                field0168 = 0;
            }
            if (field000a >= frameCount) {
                field0008 = 0;
                ResetPose();
            }
        }
        break;
    case 317:
        if ((field000a == 0) && ((unsigned short)field000c == 0)) {
            velocityX = 0.0;
            velocityY = 0.0;
            gravity = 0.0;
        }
        if ((field000a == 0) && ((unsigned short)field000c == 0)) {
            hitstunFrames = 0x78;
            meter = meter + -1000;
            SetTint(0xb0,3);
            effect.type = 0x44;
            effect.palette = 0x13;
            effect.x = (double)(int(positionX));
            effect.y = (double)((int(positionY)) + -0x28);
            effect.group = 2;
            effect.owner = 1;
            effect.layer = 1;
            contextOwner->EmitEffect(&effect);
            remainingHitCount = 1;
            SetHorizontalShake(0x32,0x78);
        }
        if (field000a > 13 && field000a < 18 && field0168 == 3) {
            ResetPose();
            ResetFrame();
            (*opponentSlot)->ResetFrame();
            (*opponentSlot)->hitstopFrames = 0xb4;
            (*opponentSlot)->positionY = 0;
            (*opponentSlot)->field0008 = 0x49;
            (*opponentSlot)->positionX =
            (double)(facing * 0x1e) + positionX;
            field0008 = 0x13e;
            (*opponentSlot)->facing = -facing;
            break;
        }
        if (velocityX > 0.0) {
            velocityX = velocityX - 0.035;
        }
        if (velocityX < 0.0) {
            velocityX = 0.0;
        }
        if (field0168 > 0 && field000a < 18 && field000a > 13) {
            field000c = 0;
            field000a = 0x12;
            break;
        }
        ++field000c;
        if ((unsigned short)field000c >= frameDuration) {
            field000c = 0;
            ++field000a;
            if (field000a == 0xe) {
                velocityX = 3.2;
            }
            if ((field000a == 0x12) && (field3138 < 2)) {
                ++field3138;
                field000a = field000a + -4;
            }
            if (field000a >= frameCount) {
                field0008 = 3;
                ResetPose();
            }
        }
        break;
    case 318:
        if ((field000a == 0) && ((unsigned short)field000c == 0)) {
            remainingHitCount = 99;
        }
        if (((field000a == 5) || (field000a == 10)) &&
            ((unsigned short)field000c == 0)) {
            pendingContextSoundSlot = 0x15;
        }
        if (velocityX > 0.0) {
            velocityX = velocityX - 0.035;
        }
        if (velocityX < 0.0) {
            velocityX = 0.0;
        }
        if (positionY < 0.0) {
            gravity = 0.055;
            velocityY = velocityY + gravity;
        }
        if (field000a > 18 && field000a < 31 && positionY + velocityY > 0.0) {
            field000c = 0;
            field000a = 0x1f;
            positionY = 0.0;
            ResetFrame();
            break;
        }
        ++field000c;
        if ((unsigned short)field000c >= frameDuration) {
            field000c = 0;
            ++field000a;
            field0168 = 0;
            if (field000a == 9) {
                positionX = (double)(facing * 0xf) + positionX;
            }
            if (field000a == 10) {
                positionX = (double)(facing * 0xf) + positionX;
            }
            if (field000a == 0xc) {
                positionX = (double)(facing * 0xf) + positionX;
            }
            if (field000a == 0xd) {
                if (1 < field3138) {
                    field000a = 0xf;
                    return;
                }
                positionX = (double)(facing * 0xf) + positionX;
            }
            if ((field000a == 0xf) && (field3138 < 1)) {
                field000a = 5;
                ++field3138;
            }
            if (field000a == 0x13) {
                velocityY = -3.3;
                velocityX = 1.5;
                remainingHitCount = 3;
            }
            if (field000a == 0x1f) {
                field000a = field000a + -4;
            }
            if (field000a >= frameCount) {
                field0008 = 3;
                ResetPose();
            }
        }
        break;
    case 319:
        if ((field000a == 0) && ((unsigned short)field000c == 0)) {
            velocityX = 0.0;
            velocityY = 0.0;
            gravity = 0.0;
        }
        if ((field000a == 0) && ((unsigned short)field000c == 0)) {
            hitstunFrames = 0x78;
            meter = meter + -2000;
            SetTint(0xb0,3);
            effect.type = 0x45;
            effect.palette = 5;
            effect.x = (double)(int(positionX));
            effect.y = (double)((int(positionY)) + -0x28);
            effect.group = 2;
            effect.owner = 1;
            effect.layer = 1;
            contextOwner->EmitEffect(&effect);
            remainingHitCount = 1;
            SetHorizontalShake(0x32,0x78);
        }
        if (field000a > 13 && field000a < 18 && field0168 == 3) {
            ResetPose();
            ResetFrame();
            (*opponentSlot)->ResetFrame();
            (*opponentSlot)->hitstopFrames = 0xb4;
            (*opponentSlot)->positionY = 0;
            (*opponentSlot)->field0008 = 0x49;
            (*opponentSlot)->positionX =
            (double)(facing * 0x1e) + positionX;
            field0008 = 0x140;
            (*opponentSlot)->facing = -facing;
            break;
        }
        if (velocityX > 0.0) {
            velocityX = velocityX - 0.035;
        }
        if (velocityX < 0.0) {
            velocityX = 0.0;
        }
        if (field0168 > 0 && field000a < 18 && field000a > 13) {
            field000c = 0;
            field000a = 0x12;
            break;
        }
        ++field000c;
        if ((unsigned short)field000c >= frameDuration) {
            field000c = 0;
            ++field000a;
            if (field000a == 0xe) {
                velocityX = 4.0;
            }
            if ((field000a == 0x12) && (field3138 < 3)) {
                ++field3138;
                field000a = field000a + -4;
            }
            if (field000a >= frameCount) {
                field0008 = 3;
                ResetPose();
            }
        }
        break;
    case 320:
        if ((field000a == 0) && ((unsigned short)field000c == 0)) {
            remainingHitCount = 99;
        }
        if (((field000a == 5) || (field000a == 10)) &&
            ((unsigned short)field000c == 0)) {
            pendingContextSoundSlot = 0x15;
        }
        if (velocityX > 0.0) {
            velocityX = velocityX - 0.035;
        }
        if (velocityX < 0.0) {
            velocityX = 0.0;
        }
        if (positionY < 0.0) {
            gravity = 0.055;
            velocityY = velocityY + gravity;
        }
        if (field000a > 25 && field000a < 38 && positionY + velocityY > 0.0) {
            field000c = 0;
            field000a = 0x26;
            positionY = 0.0;
            ResetFrame();
            break;
        }
        ++field000c;
        if ((unsigned short)field000c >= frameDuration) {
            field000c = 0;
            ++field000a;
            field0168 = 0;
            if (field000a == 9) {
                positionX = (double)(facing * 0xf) + positionX;
            }
            if (field000a == 10) {
                positionX = (double)(facing * 0xf) + positionX;
            }
            if (field000a == 0xc) {
                positionX = (double)(facing * 0xf) + positionX;
            }
            if (field000a == 0xd) {
                if (1 < field3138) {
                    field000a = 0xf;
                    return;
                }
                positionX = (double)(facing * 0xf) + positionX;
            }
            if ((field000a == 0xf) && (field3138 < 2)) {
                field000a = 5;
                ++field3138;
            }
            if (field000a == 0x19) {
                velocityY = -4.0;
                velocityX = 1.6;
                remainingHitCount = 4;
            }
            if (field000a == 0x26) {
                field000a = field000a + -4;
            }
            if (field000a >= frameCount) {
                field0008 = 3;
                ResetPose();
            }
        }
        break;
    case 321:
        if ((field000a == 0) && ((unsigned short)field000c == 0)) {
            velocityX = 0.0;
            velocityY = 0.0;
            gravity = 0.0;
        }
        contextOwner->SetSceneTimer(0xf);
        if ((field000a == 0) && ((unsigned short)field000c == 0)) {
            hitstunFrames = 0x78;
            meter = meter + -3000;
            SetTint(0xb0,3);
            effect.type = 0x46;
            effect.palette = 0x40;
            effect.x = (double)(int(positionX));
            effect.y = (double)((int(positionY)) + -0x28);
            effect.group = 2;
            effect.owner = 1;
            effect.layer = 1;
            contextOwner->EmitEffect(&effect);
            remainingHitCount = 1;
            SetHorizontalShake(0x32,0x78);
            pendingContextSoundSlot = 0x25;
        }
        if (field000a > 13 && field000a < 18 && field0168 == 3) {
            ResetPose();
            ResetFrame();
            (*opponentSlot)->ResetFrame();
            (*opponentSlot)->hitstopFrames = 0xb4;
            (*opponentSlot)->positionY = 0;
            (*opponentSlot)->field0008 = 0x49;
            (*opponentSlot)->positionX =
            (double)(facing * 0x1e) + positionX;
            field0008 = 0x142;
            (*opponentSlot)->facing = -facing;
            break;
        }
        if (velocityX > 0.0) {
            velocityX = velocityX - 0.035;
        }
        if (velocityX < 0.0) {
            velocityX = 0.0;
        }
        if (field0168 > 0 && field000a < 18 && field000a > 13) {
            field000c = 0;
            field000a = 0x12;
            break;
        }
        ++field000c;
        if ((unsigned short)field000c >= frameDuration) {
            field000c = 0;
            ++field000a;
            if (field000a == 0xe) {
                velocityX = 4.5;
            }
            if ((field000a == 0x12) && (field3138 < 3)) {
                ++field3138;
                field000a = field000a + -4;
            }
            if (field000a >= frameCount) {
                field0008 = 3;
                ResetPose();
            }
        }
        break;
    case 322:
        if ((field000a == 0) && ((unsigned short)field000c == 0)) {
            remainingHitCount = 99;
        }
        if (((field000a == 5) || (field000a == 10)) &&
            ((unsigned short)field000c == 0)) {
            pendingContextSoundSlot = 0x15;
        }
        if (velocityX > 0.0) {
            velocityX = velocityX - 0.025;
        }
        if (velocityX < 0.0) {
            velocityX = 0.0;
        }
        if (positionY < 0.0) {
            gravity = 0.045;
            velocityY = velocityY + gravity;
        }
        if (field000a > 27 && field000a < 33 && positionY + velocityY > 0.0) {
            field000c = 0;
            field000a = 0x21;
            positionY = 0.0;
            ResetFrame();
            break;
        }
        if (field000a > 37 && field000a < 42 && positionY + velocityY > 0.0) {
            field000c = 0;
            field000a = 0x2a;
            positionY = 0.0;
            ResetFrame();
            break;
        }
        if (field000a > 44 && field000a < 67 && positionY + velocityY > 0.0) {
            field000c = 0;
            field000a = 0x43;
            positionY = 0.0;
            ResetFrame();
            break;
        }
        ++field000c;
        if ((unsigned short)field000c >= frameDuration) {
            field000c = 0;
            ++field000a;
            field0168 = 0;
            if (field000a == 9) {
                positionX =
                (double)(facing * 0xf) + positionX;
            }
            if (field000a == 10) {
                positionX =
                (double)(facing * 0xf) + positionX;
            }
            if (field000a == 0xc) {
                positionX =
                (double)(facing * 0xf) + positionX;
            }
            if (field000a == 0xd) {
                positionX =
                (double)(facing * 0xf) + positionX;
            }
            if ((field000a == 0xf) && (field3138 < 10)) {
                ++field3138;
                field000a = 5;
            }
            if (field000a == 0x13) {
                positionX =
                (double)(facing * 0xf) + positionX;
            }
            if (field000a == 0x14) {
                positionX =
                (double)(facing * 0xf) + positionX;
            }
            if (field000a == 0x16) {
                positionX =
                (double)(facing * 0xf) + positionX;
            }
            if ((field000a == 0xf) && (field3138 < 8)) {
                field000a = 5;
                ++field3138;
            }
            if (field000a == 0x1c) {
                velocityY = -1.8;
                velocityX = 1.5;
                remainingHitCount = 1;
            }
            if (field000a == 0x25) {
                velocityY = -2.6;
                velocityX = 1.5;
                remainingHitCount = 1;
            }
            if (field000a == 0x2d) {
                velocityY = -4.5;
                velocityX = 2.2;
                remainingHitCount = 8;
            }
            if (field000a == 0x43) {
                field000a = field000a + -4;
            }
            if (field000a >= frameCount) {
                field0008 = 3;
                ResetPose();
            }
        }
        break;
    }
}
