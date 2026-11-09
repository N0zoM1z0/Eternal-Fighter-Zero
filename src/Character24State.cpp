// Mizuka complete animation and state update dispatch.
#include "Character24.h"
void Character24::Slot06()
{
    if (field014a > 0 || (*opponentSlot)->field014c > 0) {
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
        field0058 = 0;
        field0158 = 0;
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
        field0158 = 0;
        field0058 = 0;
        velocityX = 0.8;
        velocityY = 0.0;
        ++field000c;
        if ((unsigned short)field000c >= frameDuration) {
            field000c = 0;
            ++field000a;
            if (field000a >= frameCount) {
                field000a = 2;
            }
        }
        break;
    case 2:
        field0158 = 0;
        field0058 = 0;
        velocityX = -0.8;
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
        field0058 = 0;
        field0158 = 0;
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
        field0058 = 0;
        if ((field000a == 0) && ((unsigned short)field000c == 0)) {
            if ((unsigned char)field0158 == '\0') {
                FaceOpponent();
            }
            velocityX = 0.0;
        }
        if ((field000a == 2) && ((unsigned short)field000c == 0)) {
            gravity = 0.043;
            velocityY = -3.0;
            if ((unsigned char)field0158 == '\x01') {
                velocityX = 0.4;
                field0158 = 0;
            }
        }
        if (2 < field000a) {
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
        if ((0.0 <= positionY + velocityY) &&
            (3 < field000a)) {
            positionY = 0.0;
            field02c9 = 9;
            FaceOpponent();
            field0008 = 0xd;
            ResetPose();
        }
        break;
    case 5:
        field0058 = 0;
        if ((field000a == 0) && ((unsigned short)field000c == 0)) {
            if ((unsigned char)field0158 == '\0') {
                FaceOpponent();
            }
            velocityX = 0.0;
        }
        if ((field000a == 2) && ((unsigned short)field000c == 0)) {
            gravity = 0.043;
            velocityY = -3.0;
            velocityX = 1.0;
            if ((unsigned char)field0158 == '\x01') {
                velocityX = 1.1;
                field0158 = 0;
            }
        }
        if (2 < field000a) {
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
        if ((0.0 <= positionY + velocityY) &&
            (3 < field000a)) {
            positionY = 0.0;
            field02c9 = 9;
            FaceOpponent();
            field0008 = 0xd;
            ResetPose();
        }
        break;
    case 6:
        field0058 = 0;
        if ((field000a == 0) && ((unsigned short)field000c == 0)) {
            if ((unsigned char)field0158 == '\0') {
                FaceOpponent();
            }
            velocityX = 0.0;
        }
        if ((field000a == 2) && ((unsigned short)field000c == 0)) {
            gravity = 0.043;
            velocityY = -3.0;
            velocityX = -1.0;
        }
        if (2 < field000a) {
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
        if ((0.0 <= positionY + velocityY) &&
            (3 < field000a)) {
            positionY = 0.0;
            field02c9 = 9;
            FaceOpponent();
            field0008 = 0xd;
            ResetPose();
        }
        break;
    case 7:
        field0058 = 0;
        velocityX = 0.0;
        velocityY = 0.0;
        field0158 = 0;
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
        field0058 = 0;
        velocityX = 0.0;
        velocityY = 0.0;
        field0158 = 0;
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
        field0058 = 0;
        velocityY = velocityY + gravity;
        field0158 = 0;
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
            field02c9 = 9;
            field0008 = 0xd;
            ResetPose();
        }
        break;
    case 13:
        field0058 = 0;
        velocityX = 0.0;
        velocityY = 0.0;
        field0158 = 0;
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
        gravity = 0.043;
        field0058 = 0;
        if ((field000a == 0) && ((unsigned short)field000c == 0)) {
            velocityY = -3.0;
            velocityX = 0.0;
            field0158 = 0;
        }
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
        if ((0.0 <= positionY + velocityY) &&
            (3 < field000a)) {
            positionY = 0.0;
            field02c9 = 9;
            FaceOpponent();
            field0008 = 0xd;
            ResetPose();
        }
        break;
    case 15:
        gravity = 0.043;
        field0058 = 0;
        if ((field000a == 0) && ((unsigned short)field000c == 0)) {
            velocityY = -3.0;
            velocityX = 1.0;
            field0158 = 0;
        }
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
        if ((0.0 <= positionY + velocityY) &&
            (3 < field000a)) {
            positionY = 0.0;
            field02c9 = 9;
            FaceOpponent();
            field0008 = 0xd;
            ResetPose();
        }
        break;
    case 16:
        gravity = 0.043;
        field0058 = 0;
        if ((field000a == 0) && ((unsigned short)field000c == 0)) {
            velocityY = -3.0;
            velocityX = -1.0;
            field0158 = 0;
        }
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
        if ((0.0 <= positionY + velocityY) &&
            (3 < field000a)) {
            positionY = 0.0;
            field02c9 = 9;
            FaceOpponent();
            field0008 = 0xd;
            ResetPose();
        }
        break;
    case 47:
        if ((field000a == 0) && ((unsigned short)field000c == 0)) {
            velocityX = 0.6;
            gravity = 0.035;
        }
        velocityY = velocityY + gravity;
        if ((0.0 < positionY + velocityY) &&
            (field000a < 2)) {
            field000c = 0;
            field000a = 2;
            field02c9 = 7;
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
        field0058 = 0;
        if (field0120 != '\0') {
            field0118 = field0118 - 0.6;
        }
        field0158 = 0;
        if ((field000a == 0) && ((unsigned short)field000c == 0)) {
            field0148 = field0148 + 10;
            velocityX =
            (2.0 - (*opponentSlot)->field0178 / 10000.0) *
            -1.1;
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
            outgoingPushbackVelocityX =
            (1.0 - (double)((positionY < 0.0)) * 0.2) * velocityX;
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
        field0058 = 0;
        if (field0120 != '\0') {
            field0118 = field0118 - 0.6;
        }
        field0158 = 0;
        if ((field000a == 0) && ((unsigned short)field000c == 0)) {
            field0148 = field0148 + 0xf;
            velocityX =
            (2.0 - (*opponentSlot)->field0178 / 10000.0) *
            -1.5;
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
            outgoingPushbackVelocityX =
            (1.0 - (double)((positionY < 0.0)) * 0.2) * velocityX;
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
        field0058 = 0;
        if (field0120 != '\0') {
            field0118 = field0118 - 0.6;
        }
        field0158 = 0;
        if ((field000a == 0) && ((unsigned short)field000c == 0)) {
            field0148 = field0148 + 0x14;
            velocityX =
            (2.0 - (*opponentSlot)->field0178 / 10000.0) *
            -1.8;
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
            outgoingPushbackVelocityX =
            (1.0 - (double)((positionY < 0.0)) * 0.2) * velocityX;
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
        field0058 = 0;
        if (field0120 != '\0') {
            field0118 = field0118 - 0.6;
        }
        field0158 = 0;
        if ((field000a == 0) && ((unsigned short)field000c == 0)) {
            field0148 = field0148 + 10;
            velocityX =
            (2.0 - (*opponentSlot)->field0178 / 10000.0) *
            -1.1;
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
            outgoingPushbackVelocityX =
            (1.0 - (double)((positionY < 0.0)) * 0.2) * velocityX;
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
        field0058 = 0;
        if (field0120 != '\0') {
            field0118 = field0118 - 0.6;
        }
        field0158 = 0;
        if ((field000a == 0) && ((unsigned short)field000c == 0)) {
            field0148 = field0148 + 0xf;
            velocityX =
            (2.0 - (*opponentSlot)->field0178 / 10000.0) *
            -1.5;
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
            outgoingPushbackVelocityX =
            (1.0 - (double)((positionY < 0.0)) * 0.2) * velocityX;
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
        field0058 = 0;
        if (field0120 != '\0') {
            field0118 = field0118 - 0.6;
        }
        field0158 = 0;
        if ((field000a == 0) && ((unsigned short)field000c == 0)) {
            field0148 = field0148 + 0x14;
            velocityX =
            (2.0 - (*opponentSlot)->field0178 / 10000.0) *
            -1.8;
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
            outgoingPushbackVelocityX =
            (1.0 - (double)((positionY < 0.0)) * 0.2) * velocityX;
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
        field0058 = 0;
        if (field0120 != '\0') {
            field0118 = field0118 - 0.6;
        }
        field0158 = 0;
        if ((field000a == 0) && ((unsigned short)field000c == 0)) {
            field0148 = field0148 + 10;
            velocityX =
            (2.0 - (*opponentSlot)->field0178 / 10000.0) *
            -1.1;
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
            outgoingPushbackVelocityX =
            (1.0 - (double)((positionY < 0.0)) * 0.2) * velocityX;
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
        field0058 = 0;
        if (field0120 != '\0') {
            field0118 = field0118 - 0.6;
        }
        field0158 = 0;
        if ((field000a == 0) && ((unsigned short)field000c == 0)) {
            field0148 = field0148 + 0xf;
            velocityX =
            (2.0 - (*opponentSlot)->field0178 / 10000.0) *
            -1.5;
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
            outgoingPushbackVelocityX =
            (1.0 - (double)((positionY < 0.0)) * 0.2) * velocityX;
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
        field0058 = 0;
        if (field0120 != '\0') {
            field0118 = field0118 - 0.6;
        }
        field0158 = 0;
        if ((field000a == 0) && ((unsigned short)field000c == 0)) {
            field0148 = field0148 + 0x14;
            velocityX =
            (2.0 - (*opponentSlot)->field0178 / 10000.0) *
            -1.8;
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
            outgoingPushbackVelocityX =
            (1.0 - (double)((positionY < 0.0)) * 0.2) * velocityX;
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
        field0058 = 0;
        if (field0120 != '\0') {
            field0118 = field0118 - 0.8;
        }
        if ((field000a == 0) && ((unsigned short)field000c == 0)) {
            field0148 = field0148 + 0x1e;
            velocityX = field00c0;
            velocityY =
            velocityY * 0.75 + field00c8;
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
        field0058 = 0;
        if (field0120 != '\0') {
            field0118 = field0118 - 0.8;
        }
        if ((field000a == 0) && ((unsigned short)field000c == 0)) {
            field0148 = field0148 + 0x1e;
            velocityX = field00c0;
            velocityY =
            velocityY * 0.75 + field00c8;
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
        field0058 = 0;
        if (field0120 != '\0') {
            field0118 = field0118 - 0.8;
        }
        if ((field000a == 0) && ((unsigned short)field000c == 0)) {
            field0148 = field0148 + 0x1e;
            velocityX = field00c0;
            velocityY =
            velocityY * 0.75 + field00c8;
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
        field0058 = 0;
        if (field0120 != '\0') {
            field0118 = field0118 - 0.8;
        }
        if ((field000a == 0) && ((unsigned short)field000c == 0)) {
            field0148 = field0148 + 0x1e;
            velocityX = field00c0;
            velocityY =
            velocityY * 0.75 + field00c8;
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
        field0058 = 0;
        if (field0120 != '\0') {
            field0118 = field0118 - 0.8;
        }
        if ((field000a == 0) && ((unsigned short)field000c == 0)) {
            field0148 = field0148 + 0x1e;
            velocityX = field00c0;
            velocityY = field00c8;
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
        field0058 = 0;
        if (field0120 != '\0') {
            field0118 = field0118 - 0.8;
        }
        if (field000a > 0 && CollisionSide() != 0) {
            field0008 = 0x46;
            ResetPose();
            break;
        }
        if ((field000a == 0) && ((unsigned short)field000c == 0)) {
            field0148 = field0148 + 0x1e;
            velocityX = field00c0;
            velocityY =
            velocityY * 0.75 + field00c8;
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
        field0058 = 0;
        if (field0120 != '\0') {
            field0118 = field0118 - 0.8;
        }
        if (field000a > 0 && CollisionSide() != 0) {
            field0008 = 0x46;
            ResetPose();
            break;
        }
        if ((field000a == 0) && ((unsigned short)field000c == 0)) {
            field0148 = field0148 + 0x1e;
            velocityX = field00c0;
            velocityY =
            velocityY * 0.75 + field00c8;
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
        field0058 = 0;
        if (field0120 != '\0') {
            field0118 = field0118 - 0.8;
        }
        if (field000a > 0 && CollisionSide() != 0) {
            field0008 = 0x46;
            ResetPose();
            break;
        }
        if ((field000a == 0) && ((unsigned short)field000c == 0)) {
            field0148 = field0148 + 0x1e;
            velocityX = field00c0;
            velocityY =
            velocityY * 0.75 + field00c8;
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
        field0058 = 0;
        if (field0120 != '\0') {
            field0118 = field0118 - 0.8;
        }
        if (field000a > 0 && CollisionSide() != 0) {
            field0008 = 0x46;
            ResetPose();
            break;
        }
        if ((field000a == 0) && ((unsigned short)field000c == 0)) {
            field0148 = field0148 + 0x1e;
            velocityX = field00c0;
            velocityY = field00c8;
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
        field0058 = 0;
        if (field0120 != '\0') {
            field0118 = field0118 - 1.5;
        }
        field0148 = field0148 + 3;
        velocityX = field00c0;
        velocityY = field00c8;
        if ((velocityX * velocityX <
            velocityY * velocityY) &&
            (field000a == 0)) {
            field000a = 1;
        }
        ++field000c;
        if (CollisionSide() != 0) {
            field0008 = 0x46;
            ResetPose();
            break;
        }
        if ((unsigned short)field000c >= frameDuration) {
            field000c = 0;
            ++field000a;
            if (field000a == 1) {
                field000a = 0;
            }
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
        field0058 = 0;
        if (field0120 != '\0') {
            field0118 = field0118 - 1.5;
        }
        field0148 = field0148 + 3;
        velocityX = field00c0;
        velocityY = field00c8;
        if ((velocityX * velocityX <
            velocityY * velocityY) &&
            (field000a == 0)) {
            field000a = 1;
        }
        ++field000c;
        if ((unsigned short)field000c >= frameDuration) {
            field000c = 0;
            ++field000a;
            if (field000a == 1) {
                field000a = 0;
            }
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
        field0058 = 0;
        if (field0120 != '\0') {
            field0118 = field0118 - 0.8;
        }
        if (((field000a == 0) && ((unsigned short)field000c == 0)) &&
            (field3138 == 0)) {
            field0148 = field0148 + 0x1e;
            ++field3138;
            field0124 = field0124 + 0x78;
            velocityX = 0.5;
            velocityY = -2.5;
            gravity = 0.025;
            field02c9 = 0x1f;
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
        field0058 = 0;
        if (field0120 != '\0') {
            field0118 = field0118 - 0.8;
        }
        if ((field000a == 0) && ((unsigned short)field000c == 0)) {
            field0148 = field0148 + 0x1e;
            velocityX = field00c0;
            velocityY = field00c8;
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
        field0058 = 0;
        if (field0120 != '\0') {
            field0118 = field0118 - 0.8;
        }
        field0158 = 0;
        velocityX = 0.0;
        velocityY = 0.0;
        if ((positionX - 20.0 <= 0.0) ||
            (639.0 <= positionX + 20.0)) {
            outgoingPushbackVelocityX =
            (1.0 - (double)(((*opponentSlot)->positionY < 0.0)) * 0.25) * velocityX;
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
        field0058 = 0;
        if (field0120 != '\0') {
            field0118 = field0118 - 0.8;
        }
        field0158 = 0;
        velocityX = 0.0;
        velocityY = 0.0;
        if ((positionX - 20.0 <= 0.0) ||
            (639.0 <= positionX + 20.0)) {
            outgoingPushbackVelocityX =
            (1.0 - (double)(((*opponentSlot)->positionY < 0.0)) * 0.25) * velocityX;
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
        field0058 = 0;
        if (field0120 != '\0') {
            field0118 = field0118 - 0.8;
        }
        field0158 = 0;
        velocityX = 0.0;
        velocityY = 0.0;
        if ((positionX - 20.0 <= 0.0) ||
            (639.0 <= positionX + 20.0)) {
            outgoingPushbackVelocityX =
            (1.0 - (double)(((*opponentSlot)->positionY < 0.0)) * 0.25) * velocityX;
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
        field0058 = 0;
        if (field0120 != '\0') {
            field0118 = field0118 - 0.6;
        }
        field0158 = 0;
        if ((field000a == 0) && ((unsigned short)field000c == 0)) {
            field0148 = field0148 + 0x1e;
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
            outgoingPushbackVelocityX =
            (1.0 - (double)(((*opponentSlot)->positionY < 0.0)) * 0.25) * velocityX;
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
        field0058 = 0;
        if (field0120 != '\0') {
            field0118 = field0118 - 0.6;
        }
        field0158 = 0;
        if ((field000a == 0) && ((unsigned short)field000c == 0)) {
            field0148 = field0148 + 0x1e;
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
            outgoingPushbackVelocityX =
            (1.0 - (double)(((*opponentSlot)->positionY < 0.0)) * 0.25) * velocityX;
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
        field0058 = 0;
        if (field0120 != '\0') {
            field0118 = field0118 - 0.6;
        }
        field0158 = 0;
        if ((field000a == 0) && ((unsigned short)field000c == 0)) {
            field0148 = field0148 + 0x1e;
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
            outgoingPushbackVelocityX =
            (1.0 - (double)(((*opponentSlot)->positionY < 0.0)) * 0.25) * velocityX;
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
        field0058 = 0;
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
            field0148 = field0148 + 0x1e;
            velocityX = field00c0;
            velocityY = field00c8;
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
        field0058 = 0;
        if (field0120 != '\0') {
            field0118 = field0118 - 0.8;
        }
        if (((field000a == 0) && ((unsigned short)field000c == 0)) &&
            (field3138 == 0)) {
            field02c9 = 0x1e;
            velocityY = -0.45;
            velocityX = -0.1;
            ++field3138;
            field0148 = field0148 + 0x1e;
        }
        if ((field000a == 4) && ((unsigned short)field000c == 0)) {
            velocityX = field00c0;
            velocityY = field00c8;
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
        field0058 = 0;
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
            field02c9 = 0x21;
            velocityY = -1.5;
            velocityX = -0.8;
            field0148 = field0148 + 0x1e;
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
        field0058 = 0;
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
            field02c9 = 0x21;
            velocityY = -1.5;
            velocityX = -0.8;
            field0148 = field0148 + 0x1e;
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
        field0058 = 0;
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
            field02c9 = 0x21;
            velocityX = field00c0;
            velocityY = field00c8;
            field0148 = field0148 + 0x1e;
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
        field0058 = 0;
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
                field02c9 = 0x21;
                velocityX = field00c0;
                velocityY = field00c8;
                field0148 = field0148 + 0x1e;
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
        ++field000c;
        if ((unsigned short)field000c >= frameDuration) {
            field000c = 0;
            ++field000a;
            if (field000a == frameCount) {
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
        field0058 = 0;
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
            field02c9 = 7;
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
        field0058 = 0;
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
            field02c9 = 7;
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
        field0058 = 0;
        if (((0 < field0108) && (99 < (unsigned short)field000c)) &&
            (field000a == 0)) {
            field0008 = 0x60;
            ResetPose();
            field0158 = 0;
        }
        ++field000c;
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
        if ((field000a == 0) && ((unsigned short)field000c == 0)) {
            field0158 = 0;
            field0148 = field0148 + 10;
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
        if ((field000a == 0) && ((unsigned short)field000c == 0)) {
            field0158 = 0;
            field0148 = field0148 + 0xf;
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
        if ((field000a == 0) && ((unsigned short)field000c == 0)) {
            field0158 = 0;
            field0148 = field0148 + 0x14;
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
        if ((field000a == 0) && ((unsigned short)field000c == 0)) {
            field0158 = 0;
            field0148 = field0148 + 10;
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
        if ((field000a == 0) && ((unsigned short)field000c == 0)) {
            field0158 = 0;
            field0148 = field0148 + 0xf;
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
        if ((field000a == 0) && ((unsigned short)field000c == 0)) {
            field0158 = 0;
            field0148 = field0148 + 0x14;
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
            field0148 = field0148 + 0xf;
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
            field02c9 = 9;
            FaceOpponent();
            field0008 = 0xd;
            ResetPose();
        }
        break;
    case 157:
        velocityX = 1.0;
        gravity = 0.045;
        field0158 = 0;
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
            field02c9 = 9;
            FaceOpponent();
            field0008 = 0xd;
            if (0 < field3458) {
                field0008 = 0xb3;
            }
            ResetPose();
        }
        break;
    case 158:
        velocityX = -1.0;
        gravity = 0.045;
        field0158 = 0;
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
            field02c9 = 9;
            FaceOpponent();
            field0008 = 0xd;
            if (0 < field3458) {
                field0008 = 0xb3;
            }
            ResetPose();
        }
        break;
    case 163:
        if ((field000a == 0) && ((unsigned short)field000c == 0)) {
            ResetFrame();
        }
        if (9 < field000a) {
            ++field313c;
        }
        if ((field000a == 2) && ((unsigned short)field000c == 0)) {
            velocityX = 1.5;
        }
        if ((field000a == 5) && ((unsigned short)field000c == 0)) {
            field0058 = 1;
        }
        if ((field000a == 6) && ((unsigned short)field000c == 0)) {
            field0058 = 3;
        }
        field0158 = 1;
        ++field000c;
        if ((unsigned short)field000c >= frameDuration) {
            field000c = 0;
            ++field000a;
            if (field000a >= frameCount) {
                field000a = field000a + -8;
                return;
            }
        }
        if ((inputX == facing) && (field313c >= 42)) {
            field0008 = 0xb2;
            field0058 = 1;
            ResetPose();
        }
        if ((inputX != facing) && (field313c >= 24)) {
            field0008 = 0xb2;
            field0058 = 1;
            ResetPose();
        }
        break;
    case 164:
        if ((field000a == 0) && ((unsigned short)field000c == 0)) {
            ResetFrame();
        }
        field0158 = 0;
        if (((field000a == 0) && ((unsigned short)field000c == 0)) &&
            (field3138 == 0)) {
            velocityX = -2.5;
            velocityY = -1.3;
        }
        velocityY = velocityY + 0.045;
        if ((0.0 < velocityY + positionY) &&
            (field000a < 0xc)) {
            ResetFrame();
            field000c = 0;
            field000a = 0xc;
            positionY = 0.0;
        }
        ++field000c;
        if ((unsigned short)field000c >= frameDuration) {
            field000c = 0;
            ++field000a;
            if (field000a == 4) {
                field0058 = 1;
            }
            if (field000a == 5) {
                field0058 = 3;
            }
            if (field000a == 7) {
                field0058 = 1;
            }
            if (field000a == 8) {
                field0058 = 0;
            }
            if (field000a == 0xc) {
                field000a = field000a + -2;
            }
            if (field000a >= frameCount) {
                ResetPose();
                field0008 = 7;
            }
        }
        break;
    case 165:
        if (((field000a == 0) && ((unsigned short)field000c == 0)) &&
            (field3138 == 0)) {
            velocityX = 2.0;
            StartTrail(3);
            velocityY = 0.0;
            gravity = 0.0;
            field02c9 = 0x11;
        }
        if (0 < field3458) {
            --field3458;
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
        if ((inputX != facing) && (field3138 >= 40)) {
            field0008 = 9;
            ResetPose();
            velocityX = 1.3;
            gravity = 0.03;
            if (0 < field3458) {
                field0008 = 0xb3;
                field000a = 7;
            }
            if ((FaceOpponent()) != 0) {
                velocityX = -velocityX;
            }
        }
        break;
    case 166:
        if (((field000a == 0) && ((unsigned short)field000c == 0)) &&
            (field3138 == 0)) {
            velocityX = -2.0;
            velocityY = 0.0;
            gravity = 0.0;
            StartTrail(3);
            field02c9 = 0x11;
        }
        if (0 < field3458) {
            --field3458;
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
        if (((int)inputX != -(int)facing) && (field3138 >= 40)) {
            field0008 = 9;
            ResetPose();
            velocityX = -0.9;
            gravity = 0.03;
            if (0 < field3458) {
                field0008 = 0xb3;
                field000a = 7;
            }
            if ((FaceOpponent()) != 0) {
                velocityX = -velocityX;
            }
        }
        break;
    case 167:
        field0058 = 0;
        if ((field000a == 0) && ((unsigned short)field000c == 0)) {
            velocityX = 0.0;
            velocityY = 0.0;
            if (field0120 == '\x01') {
                field0178 =
                5.0 * field0118 + field0178;
            }
            field0118 = 0.0;
            field014c = 0x5a;
            SetTint(0xb0,3);
        }
        if ((field000a == 1) && ((unsigned short)field000c == 0)) {
            field02c9 = 0x12;
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
        field0058 = 0;
        if ((field000a == 0) && ((unsigned short)field000c == 0)) {
            field0158 = 0;
            velocityX = 0.0;
            velocityY = 0.0;
            positionY = 0.0;
            gravity = 0.0;
            field014e = 0;
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
        field0058 = 0;
        if ((field000a == 0) && ((unsigned short)field000c == 0)) {
            field0158 = 0;
            velocityX = 0.0;
            velocityY = 0.0;
            positionY = 0.0;
            gravity = 0.0;
            field014e = 0;
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
        field0058 = 0;
        if ((field000a == 0) && ((unsigned short)field000c == 0)) {
            field3138 = (int(velocityX * 100.0));
            field313c = (int(velocityY * 100.0));
            velocityX = 0.0;
            velocityY = 0.0;
            if (gravity == 0.0) {
                gravity = 0.035;
            }
            field014e = 0;
            outgoingPushbackVelocityX = 0.0;
            field014c = 0x3c;
        }
        if ((field014c == 0) && (field3140 == 0)) {
            ++field3140;
            velocityX = (double)field3138 * 0.01;
            velocityY = (double)field313c * 0.01;
        }
        if (field014c == 0) {
            velocityY = velocityY + gravity;
        }
        if (velocityY + positionY > 0.0) {
            ResetFrame();
            positionY = 0.0;
            field3458 = 0;
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
                if (0 < field3458) {
                    field0008 = 0xb3;
                    field000a = 7;
                }
            }
        }
        break;
    case 171:
        if ((field000a == 0) && ((unsigned short)field000c == 0)) {
            field3138 = (int(velocityX * 100.0));
            field313c = (int(velocityY * 100.0));
            velocityX = 0.0;
            velocityY = 0.0;
            if (field0120 == '\x01') {
                field0178 =
                5.0 * field0118 + field0178;
            }
            field0118 = 0.0;
            field014c = 0x5a;
            SetTint(0xb0,3);
        }
        if ((field000a == 1) && ((unsigned short)field000c == 0)) {
            field02c9 = 0x12;
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
                field0008 = 9;
                velocityX = (double)field3138 * 0.01;
                velocityY = (double)field313c * 0.01;
                gravity = 0.035;
                ResetPose();
                if (0 < field3458) {
                    field0008 = 0xb3;
                    field000a = 7;
                }
            }
        }
        break;
    case 178:
        velocityX = velocityX - 0.03;
        if (velocityX < 0.0) {
            velocityX = 0.0;
            field0158 = 0;
        }
        if ((inputY == -1) && (field000a > 0)) {
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
        ++field000c;
        if ((unsigned short)field000c >= frameDuration) {
            field000c = 0;
            ++field000a;
            if (field000a == 1) {
                field0058 = 0;
            }
            if (field000a >= frameCount) {
                field0008 = 0;
                ResetPose();
                break;
            }
        }
        break;
    case 179:
        field0159 = 0;
        if ((*opponentSlot)->field0108 <= 0) {
            field3458 = 0;
        }
        if ((field000a == 0) && ((unsigned short)field000c == 0)) {
            field015a = 1;
            field3458 = 1000;
            velocityY = -2.5;
            velocityX = 0.0;
        }
        if ((field000a < 7) &&
            (velocityY = velocityY + 0.035,
            velocityY > 0.0)) {
            velocityY = 0.0;
        }
        FaceOpponent();
        if (6 < field000a) {
            --field3458;
            if (field3458 < 0) {
                gravity = 0.035;
                ResetPose();
                field0008 = 9;
                return;
            }
            velocityX = 0.0;
            velocityY = 0.0;
            if (inputY == '\x01') {
                velocityY = 1.0;
            }
            if (inputY == -1) {
                velocityY = -1.0;
            }
            if (inputX == facing) {
                ResetPose();
                field0008 = 0xb4;
                return;
            }
            if ((int)inputX == -(int)facing) {
                ResetPose();
                field0008 = 0xb5;
                return;
            }
            if (buttonPulse[3] == '\x01') {
                field3458 = 0;
            }
        }
        field0058 = 0;
        ++field000c;
        if ((unsigned short)field000c >= frameDuration) {
            field000c = 0;
            ++field000a;
            if (field000a >= frameCount) {
                field000a = field000a + -4;
            }
        }
        break;
    case 180:
        field0159 = 0;
        if ((*opponentSlot)->field0108 <= 0) {
            field3458 = 0;
        }
        if ((field000a == 0) && ((unsigned short)field000c == 0)) {
            velocityX = 1.5;
        }
        field0058 = 0;
        --field3458;
        if (field3458 < 0) {
            gravity = 0.035;
            ResetPose();
            field0008 = 9;
            break;
        }
        if (inputY == '\x01') {
            velocityY = 1.0;
        }
        if (inputY == '\0') {
            velocityY = 0.0;
        }
        if (inputY == -1) {
            velocityY = -1.0;
        }
        if (inputX == '\0') {
            ResetPose();
            field000a = 7;
            field0008 = 0xb3;
            break;
        }
        if ((int)inputX == -(int)facing) {
            ResetPose();
            field0008 = 0xb5;
            break;
        }
        if (buttonPulse[3] == '\x01') {
            field3458 = 0;
        }
        if (field3458 < 0) {
            gravity = 0.035;
            ResetPose();
            field0008 = 9;
            break;
        }
        ++field000c;
        if ((unsigned short)field000c >= frameDuration) {
            field000c = 0;
            ++field000a;
            if (field000a >= frameCount) {
                field000a = field000a + -2;
            }
        }
        break;
    case 181:
        field0159 = 0;
        if ((*opponentSlot)->field0108 <= 0) {
            field3458 = 0;
        }
        if ((field000a == 0) && ((unsigned short)field000c == 0)) {
            velocityX = -1.5;
        }
        field0058 = 0;
        --field3458;
        if (field3458 < 0) {
            gravity = 0.035;
            ResetPose();
            field0008 = 9;
            break;
        }
        if (inputY == '\x01') {
            velocityY = 1.0;
        }
        if (inputY == -1) {
            velocityY = -1.0;
        }
        if (inputY == '\0') {
            velocityY = 0.0;
        }
        if (inputX == '\0') {
            ResetPose();
            field000a = 7;
            field0008 = 0xb3;
            break;
        }
        if (inputX == facing) {
            ResetPose();
            field0008 = 0xb4;
            break;
        }
        if (buttonPulse[3] == '\x01') {
            field3458 = 0;
        }
        if (field3458 < 0) {
            gravity = 0.035;
            ResetPose();
            field0008 = 9;
            break;
        }
        ++field000c;
        if ((unsigned short)field000c >= frameDuration) {
            field000c = 0;
            ++field000a;
            if (field000a >= frameCount) {
                field000a = field000a + -2;
            }
        }
        break;
    case 200:
        field0058 = 0;
        if ((unsigned char)field0158 == '\0') {
            velocityX = 0.0;
            velocityY = 0.0;
        }
        if (velocityX > 0.0 && (unsigned char)field0158 == 1) {
            velocityX = velocityX - 0.06;
        } else {
            velocityX = 0.0;
            field0158 = 0;
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
            field0148 = field0148 + 5;
            field02c9 = 0x15;
            field016c = 1;
        }
        ++field000c;
        if ((unsigned short)field000c >= frameDuration) {
            field000c = 0;
            ++field000a;
            field0168 = 0;
            if (field000a == 1) {
                effect.type = 0x1b9;
                effect.x = (double)((int(positionX)) - facing * 0x28);
                effect.y = (double)((int(positionY)) + -0x21);
                effect.group = 2;
                effect.layer = 1;
                effect.flag0018 = (unsigned char)facing;
                EmitLocalEffect(&effect);
            }
            if (field000a >= frameCount) {
                field0008 = 0;
                FaceOpponent();
                ResetPose();
            }
        }
        break;
    case 201:
        field0058 = 0;
        if ((unsigned char)field0158 == '\0') {
            velocityX = 0.0;
            velocityY = 0.0;
        }
        if (velocityX > 0.0 && (unsigned char)field0158 == 1) {
            velocityX = velocityX - 0.03;
        } else {
            velocityX = 0.0;
            field0158 = 0;
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
        if ((field000a == 1) && ((unsigned short)field000c == 0)) {
            effect.type = 400;
            effect.x = (double)((int(positionX)) - facing * 0x15);
            effect.y = (double)((int(positionY)) + -0x1f);
            effect.group = 2;
            effect.layer = 1;
            effect.flag0018 = (unsigned char)facing;
            EmitLocalEffect(&effect);
        }
        if ((field000a == 2) && ((unsigned short)field000c == 0)) {
            field0148 = field0148 + 0xf;
            field02c9 = 0x14;
            field016c = 1;
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
                FaceOpponent();
                ResetPose();
            }
        }
        break;
    case 202:
        field0058 = 0;
        if ((unsigned char)field0158 == '\0') {
            velocityX = 0.0;
            velocityY = 0.0;
        }
        if (velocityX > 0.0 && (unsigned char)field0158 == 1) {
            velocityX = velocityX - 0.06;
        } else {
            velocityX = 0.0;
            field0158 = 0;
        }
        if ((field000a == 2) && ((unsigned short)field000c == 0)) {
            field0148 = field0148 + 0xf;
            field02c9 = 0x14;
            field016c = 1;
            effect.type = 0x191;
            effect.x = (double)((int(positionX)) - facing * 0x24);
            effect.y = (double)((int(positionY)) + -0x35);
            effect.group = 2;
            effect.layer = 1;
            effect.flag0018 = (unsigned char)facing;
            EmitLocalEffect(&effect);
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
                FaceOpponent();
                ResetPose();
            }
        }
        break;
    case 203:
        field0058 = 0;
        if ((field000a == 0) && ((unsigned short)field000c == 0)) {
            ResetFrame();
        }
        if ((field000a == 5) && ((unsigned short)field000c == 0)) {
            effect.type = 3;
            effect.x = (double)((int(positionX)) + facing * 0x37);
            effect.y = (double)(int(positionY));
            effect.group = 2;
            effect.layer = 1;
            contextOwner->EmitEffect(&effect);
            field02c8 = 10;
        }
        if ((field000a == 4) && ((unsigned short)field000c == 0)) {
            field0148 = field0148 + 0x23;
            field016c = 1;
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
                FaceOpponent();
                ResetPose();
            }
        }
        break;
    case 204:
        field0058 = 0;
        if ((unsigned char)field0158 == '\0') {
            velocityX = 0.0;
            velocityY = 0.0;
        }
        if (velocityX > 0.0 && (unsigned char)field0158 == 1) {
            velocityX = velocityX - 0.03;
        } else {
            velocityX = 0.0;
            field0158 = 0;
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
        if ((field000a == 1) && ((unsigned short)field000c == 0)) {
            field0148 = field0148 + 5;
            field02c9 = 0x15;
            field016c = 1;
            effect.type = 0x1ba;
            effect.x = (double)((int(positionX)) - facing * 0x28);
            effect.y = (double)((int(positionY)) + -10);
            effect.group = 2;
            effect.layer = 1;
            effect.flag0018 = (unsigned char)facing;
            EmitLocalEffect(&effect);
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
    case 205:
        field0058 = 0;
        if ((unsigned char)field0158 == '\0') {
            velocityX = 0.0;
            velocityY = 0.0;
        }
        if (velocityX > 0.0 && (unsigned char)field0158 == 1) {
            velocityX = velocityX - 0.03;
        } else {
            velocityX = 0.0;
            field0158 = 0;
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
            field0148 = field0148 + 0xd;
            field02c9 = 0x14;
            field016c = 1;
            effect.type = 0x192;
            effect.x = (double)((int(positionX)) - facing * 0x1a);
            effect.y = (double)((int(positionY)) + -0x10);
            effect.group = 2;
            effect.layer = 1;
            effect.flag0018 = (unsigned char)facing;
            EmitLocalEffect(&effect);
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
    case 206:
        field0058 = 0;
        if ((((unsigned char)field0158 == '\0') && (field000a == 0)) &&
            ((unsigned short)field000c == 0)) {
            velocityX = 0.0;
            velocityY = 0.0;
        }
        if (velocityX > 0.0 && (unsigned char)field0158 == 1 && field000a < 3) {
            velocityX = velocityX - 0.03;
        } else {
            field0158 = 0;
        }
        if (velocityX < 0.0) {
            velocityX = 0.0;
        }
        if ((field000a == 1) && ((unsigned short)field000c == 0)) {
            field016c = 1;
        }
        if (((field000a == 3) && ((unsigned short)field000c == 0)) &&
            (field3138 == 0)) {
            field0148 = field0148 + 0x19;
            field02c9 = 0x14;
            velocityX = 3.5;
            ++field3138;
        }
        if (velocityX > 0.0) {
            velocityX = velocityX - 0.036;
        }
        ++field000c;
        if ((unsigned short)field000c >= frameDuration) {
            field000c = 0;
            ++field000a;
            field0168 = 0;
            if ((field000a == 4) && (velocityX > 0.6)) {
                field000a = 2;
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
        field0058 = 0;
        if (field3458 == 0) {
            velocityY = velocityY + gravity;
        }
        if (0 < field3458) {
            if (velocityX > 0.1) {
                velocityX = velocityX - 0.025;
            }
            if (velocityX < -0.1) {
                velocityX = velocityX + 0.025;
            }
            if ((velocityX < 0.1) &&
                (velocityX > -0.1)) {
                velocityX = 0.0;
            }
            if (velocityY > 0.1) {
                velocityY = velocityY - 0.025;
            }
            if (velocityY < -0.1) {
                velocityY = velocityY + 0.025;
            }
            if ((velocityY < 0.1) &&
                (velocityY > -0.1)) {
                velocityY = 0.0;
            }
        }
        if ((((inputY == -1) && (field000a > 0)) &&
            (field0168 >= 2)) && ((field015a == '\0' && (field015c < 3)))
            ) {
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
        if ((field000a == 2) && ((unsigned short)field000c == 0)) {
            field0148 = field0148 + 5;
            field02c9 = 0x15;
            field016c = 1;
            effect.type = 0x1bb;
            effect.x = (double)((int(positionX)) - facing * 7);
            effect.y = (double)((int(positionY)) + -0x2f);
            effect.group = 2;
            effect.layer = 1;
            effect.flag0018 = (unsigned char)facing;
            EmitLocalEffect(&effect);
        }
        if (positionY + velocityY >= 0.0) {
            positionY = 0.0;
            field0008 = 0xd;
            field3458 = 0;
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
                if (0 < field3458) {
                    field0008 = 0xb3;
                    field000a = 7;
                }
            }
        }
        break;
    case 208:
        field0058 = 0;
        if (field3458 == 0) {
            velocityY = velocityY + gravity;
        }
        if (0 < field3458) {
            if (velocityX > 0.1) {
                velocityX = velocityX - 0.025;
            }
            if (velocityX < -0.1) {
                velocityX = velocityX + 0.025;
            }
            if ((velocityX < 0.1) &&
                (velocityX > -0.1)) {
                velocityX = 0.0;
            }
            if (velocityY > 0.1) {
                velocityY = velocityY - 0.025;
            }
            if (velocityY < -0.1) {
                velocityY = velocityY + 0.025;
            }
            if ((velocityY < 0.1) &&
                (velocityY > -0.1)) {
                velocityY = 0.0;
            }
        }
        if ((((inputY == -1) && (field000a > 0)) &&
            (field0168 >= 2)) && ((field015a == '\0' && (field015c < 3)))
            ) {
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
        if ((field000a == 2) && ((unsigned short)field000c == 0)) {
            field0148 = field0148 + 0xd;
            field02c9 = 0x14;
            field016c = 2;
            effect.type = 0x194;
            effect.x = (double)((int(positionX)) + facing * 0x25);
            effect.y = (double)((int(positionY)) + -0x48);
            effect.group = 2;
            effect.layer = 1;
            effect.flag0018 = (unsigned char)facing;
            EmitLocalEffect(&effect);
        }
        if (positionY + velocityY >= 0.0) {
            positionY = 0.0;
            field0008 = 0xd;
            field3458 = 0;
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
                if (0 < field3458) {
                    field0008 = 0xb3;
                    field000a = 7;
                }
            }
        }
        break;
    case 209:
        field0058 = 0;
        if (field3458 == 0) {
            velocityY = velocityY + gravity;
        }
        if (0 < field3458) {
            if (velocityX > 0.1) {
                velocityX = velocityX - 0.025;
            }
            if (velocityX < -0.1) {
                velocityX = velocityX + 0.025;
            }
            if ((velocityX < 0.1) &&
                (velocityX > -0.1)) {
                velocityX = 0.0;
            }
            if (velocityY > 0.1) {
                velocityY = velocityY - 0.025;
            }
            if (velocityY < -0.1) {
                velocityY = velocityY + 0.025;
            }
            if ((velocityY < 0.1) &&
                (velocityY > -0.1)) {
                velocityY = 0.0;
            }
        }
        if ((((inputY == -1) && (field000a > 0)) &&
            (field0168 >= 2)) && ((field015a == '\0' && (field015c < 3)))
            ) {
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
        if ((field000a == 1) && ((unsigned short)field000c == 0)) {
            field0148 = field0148 + 0x1e;
            field02c9 = 0x14;
            field016c = 3;
        }
        if (positionY + velocityY >= 0.0) {
            positionY = 0.0;
            field0008 = 0xd;
            field3458 = 0;
            ResetPose();
            break;
        }
        ++field000c;
        if ((unsigned short)field000c >= frameDuration) {
            field000c = 0;
            ++field000a;
            if (field000a < 5) {
                field0168 = 0;
            }
            if (field000a == 5) {
                effect.type = 0x195;
                effect.x = (double)((int(positionX)) + facing * 4);
                effect.y = (double)((int(positionY)) + 5);
                effect.group = 2;
                effect.layer = 1;
                effect.flag0018 = (unsigned char)facing;
                EmitLocalEffect(&effect);
            }
            if ((field000a == 8) && (field3138 < 2)) {
                field000a = field000a + -3;
                ++field3138;
                field0168 = 0;
            }
            if (field000a >= frameCount) {
                field0008 = 9;
                ResetPose();
                if (0 < field3458) {
                    field0008 = 0xb3;
                    field000a = 7;
                }
            }
        }
        break;
    case 210:
        field0058 = 0;
        if (field3458 == 0) {
            velocityY = velocityY + gravity;
        }
        if (0 < field3458) {
            if (velocityX > 0.1) {
                velocityX = velocityX - 0.025;
            }
            if (velocityX < -0.1) {
                velocityX = velocityX + 0.025;
            }
            if ((velocityX < 0.1) &&
                (velocityX > -0.1)) {
                velocityX = 0.0;
            }
            if (velocityY > 0.1) {
                velocityY = velocityY - 0.025;
            }
            if (velocityY < -0.1) {
                velocityY = velocityY + 0.025;
            }
            if ((velocityY < 0.1) &&
                (velocityY > -0.1)) {
                velocityY = 0.0;
            }
        }
        if ((((inputY == -1) && (field000a > 0)) &&
            (field015c < 3)) && ((field0168 >= 2 && (field015a == '\0')))
            ) {
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
        if ((field000a == 1) && ((unsigned short)field000c == 0)) {
            field0148 = field0148 + 0x1e;
            field02c9 = 0x14;
            field016c = 1;
        }
        if (positionY + velocityY >= 0.0) {
            positionY = 0.0;
            field0008 = 0xd;
            field3458 = 0;
            ResetPose();
            break;
        }
        ++field000c;
        if ((unsigned short)field000c >= frameDuration) {
            field000c = 0;
            ++field000a;
            if (field000a < 5) {
                field0168 = 0;
            }
            if (field000a == 5) {
                effect.type = 0x1cc;
                effect.x = (double)((int(positionX)) + facing * 0x37);
                effect.y = (double)((int(positionY)) + -0x2c);
                effect.group = 2;
                effect.layer = 1;
                effect.flag0018 = (unsigned char)facing;
                EmitLocalEffect(&effect);
            }
            if (field000a >= frameCount) {
                field0008 = 9;
                ResetPose();
                if (0 < field3458) {
                    field0008 = 0xb3;
                    field000a = 7;
                }
            }
        }
        break;
    case 211:
        if (((inputY == -1) && (field000a > 0)) &&
            (field0168 >= 2)) {
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
        if ((field000a == 3) && ((unsigned short)field000c == 0)) {
            field0148 = field0148 + 0x1e;
            field02c9 = 0x14;
            field016c = 1;
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
    case 212:
        velocityY = velocityY + gravity;
        if ((field000a == 0) && ((unsigned short)field000c == 0)) {
            field0148 = field0148 + 0x1e;
            field02c9 = 0x14;
            field016c = 1;
            velocityX = velocityX / 2.0;
            gravity = 0.07;
        }
        if (field0168 > 1) {
            field0008 = 0xd5;
            ResetPose();
            ResetFrame();
            break;
        }
        if (positionY + velocityY >= 0.0) {
            positionY = 0.0;
            velocityY = 0.0;
            SetVerticalShake(3,0);
            effect.type = 3;
            effect.x = (double)(int(positionX));
            effect.y = (double)(int(positionY));
            effect.group = 2;
            effect.layer = 0;
            effect.palette = 7;
            contextOwner->EmitEffect(&effect);
            field0008 = 0xd6;
            ResetPose();
            break;
        }
        ++field000c;
        if ((unsigned short)field000c >= frameDuration) {
            field000c = 0;
            ++field000a;
            field0168 = 0;
            if (field000a >= frameCount) {
                field000a = field000a + -2;
            }
        }
        break;
    case 213:
        gravity = 0.042;
        velocityY = velocityY + gravity;
        if ((field000a == 0) && ((unsigned short)field000c == 0)) {
            velocityX = -1.0;
            velocityY = -2.4;
        }
        ++field000c;
        if ((unsigned short)field000c >= frameDuration) {
            field000c = 0;
            ++field000a;
            field0168 = 0;
            if (field000a >= frameCount) {
                field0008 = 9;
                ResetPose();
            }
        }
        break;
    case 214:
        velocityX = 0.0;
        velocityY = 0.0;
        if ((field000a == 0) && ((unsigned short)field000c == 0)) {
            SetVerticalShake(3,0);
            effect.type = 3;
            effect.x = (double)(int(positionX));
            effect.y = (double)(int(positionY));
            effect.group = 2;
            effect.layer = 0;
            effect.palette = 7;
            contextOwner->EmitEffect(&effect);
        }
        ++field000c;
        if ((unsigned short)field000c >= frameDuration) {
            field000c = 0;
            ++field000a;
            field0168 = 0;
            if (field000a >= frameCount) {
                field0008 = 7;
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
        field0058 = 0;
        field0158 = 0;
        if (((field000a == 1) && ((unsigned short)field000c == 0)) &&
            ((*opponentSlot)->positionY == 0.0)) {
            field016c = 1;
        }
        else {
            field016c = 0;
        }
        if ((field000a == 1) && (field0168 == 3)) {
            velocityX = 0.0;
            velocityY = 0.0;
            ResetPose();
            ResetFrame();
            (*opponentSlot)->ResetFrame();
            field0008 = 0xdd;
            effect.type = 0;
            effect.x = (double)((int(positionX)) + facing * 0x25);
            effect.y = (double)((int(positionY)) + -0x2a);
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
    case 221:
        if ((field000a == 0) && ((unsigned short)field000c == 0)) {
            (*opponentSlot)->field000a = 0;
            (*opponentSlot)->field000c = 0;
            (*opponentSlot)->ResetFrame();
            (*opponentSlot)->field00c0 = 0.0;
            (*opponentSlot)->field00c8 = -2.5;
            (*opponentSlot)->field0008 = 0x3b;
        }
        if ((field000a == 1) && ((unsigned short)field000c == 0)) {
            effect.type = 0x1c8;
            effect.x = (double)((int((*opponentSlot)->positionX)) - facing * 0x50);
            effect.y = 0.0;
            effect.group = 0;
            effect.layer = 0;
            effect.field0028 = 1;
            effect.flag0018 = (unsigned char)facing;
            EmitLocalEffect(&effect);
            effect.type = 0x1c9;
            effect.x = (double)(int((*opponentSlot)->positionX));
            effect.y = 0.0;
            effect.group = 0;
            effect.layer = 0;
            effect.field0028 = 1;
            effect.flag0018 = (unsigned char)facing;
            EmitLocalEffect(&effect);
            effect.type = 0x1ca;
            effect.x = (double)((int((*opponentSlot)->positionX)) + facing * 0x50);
            effect.y = 0.0;
            effect.group = 0;
            effect.layer = 0;
            effect.field0028 = 1;
            effect.flag0018 = (unsigned char)facing;
            EmitLocalEffect(&effect);
        }
        if (field000a == 3) {
            FaceOpponent();
        }
        if (((*opponentSlot)->field0008 == 0x40) && (field000a == 3)) {
            field000c = 0;
            ++field000a;
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
    case 230:
        StartTrail(3);
        velocityX = velocityX - 0.03;
        if (velocityX < 0.0) {
            velocityX = 0.0;
        }
        field0158 = 0;
        if ((field000a == 0) && ((unsigned short)field000c == 0)) {
            velocityX = 2.0;
            velocityY = 0.0;
        }
        if ((field000a == 1) && ((unsigned short)field000c == 0)) {
            field0148 = field0148 + 0xf;
            field02c9 = 0x15;
            field016c = 1;
        }
        if ((field0058 == '\x03') || (field0058 == '\x01')) {
            field013c = 2;
        }
        ++field000c;
        if ((unsigned short)field000c >= frameDuration) {
            field000c = 0;
            ++field000a;
            if (field000a == 1) {
                field0168 = 0;
            }
            if (field000a == 1) {
                effect.type = 0x1b9;
                effect.x = (double)((int(positionX)) - facing * 0x28);
                effect.y = (double)((int(positionY)) + -0x21);
                effect.group = 2;
                effect.layer = 1;
                effect.flag0018 = (unsigned char)facing;
                EmitLocalEffect(&effect);
            }
            if (field0058 == '\x01') {
                field0058 = 0;
            }
            if (field0058 == '\x03') {
                field0058 = 1;
            }
            if (field000a >= frameCount) {
                field0058 = 0;
                field0008 = 0;
                ResetPose();
            }
        }
        break;
    case 231:
        StartTrail(3);
        field0158 = 0;
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
        velocityX = velocityX - 0.03;
        if (velocityX < 0.0) {
            velocityX = 0.0;
        }
        if ((field000a == 0) && ((unsigned short)field000c == 0)) {
            velocityX = 2.0;
            velocityY = 0.0;
        }
        if (velocityX < 0.0) {
            velocityX = 0.0;
        }
        if ((field000a == 1) && ((unsigned short)field000c == 0)) {
            effect.type = 400;
            effect.x = (double)((int(positionX)) - facing * 0x15);
            effect.y = (double)((int(positionY)) + -0x1f);
            effect.group = 2;
            effect.layer = 1;
            effect.flag0018 = (unsigned char)facing;
            EmitLocalEffect(&effect);
        }
        if ((field000a == 3) && ((unsigned short)field000c == 0)) {
            field0148 = field0148 + 0xf;
            field02c9 = 0x14;
            field016c = 1;
        }
        if ((field0058 == '\x03') || (field0058 == '\x01')) {
            field013c = 2;
        }
        ++field000c;
        if ((unsigned short)field000c >= frameDuration) {
            field000c = 0;
            ++field000a;
            if (field000a == 1) {
                field0168 = 0;
            }
            if (field0058 == '\x01') {
                field0058 = 0;
            }
            if (field0058 == '\x03') {
                field0058 = 1;
            }
            if (field000a >= frameCount) {
                field0008 = 0;
                ResetPose();
            }
        }
        break;
    case 232:
        StartTrail(3);
        velocityX = velocityX - 0.03;
        if (velocityX < 0.0) {
            velocityX = 0.0;
        }
        field0158 = 0;
        if ((field000a == 0) && ((unsigned short)field000c == 0)) {
            velocityX = 2.0;
            velocityY = 0.0;
        }
        if ((field000a == 5) && ((unsigned short)field000c == 0)) {
            effect.type = 3;
            effect.x = (double)((int(positionX)) + facing * 0x37);
            effect.y = (double)(int(positionY));
            effect.group = 2;
            effect.layer = 1;
            contextOwner->EmitEffect(&effect);
            field02c8 = 10;
        }
        if ((field000a == 4) && ((unsigned short)field000c == 0)) {
            field0148 = field0148 + 0x23;
            field02c9 = 0x14;
            field016c = 1;
        }
        if ((field0058 == '\x03') || (field0058 == '\x01')) {
            field013c = 2;
        }
        ++field000c;
        if ((unsigned short)field000c >= frameDuration) {
            field000c = 0;
            ++field000a;
            if (field000a == 1) {
                field0168 = 0;
            }
            if (field0058 == '\x01') {
                field0058 = 0;
            }
            if (field0058 == '\x03') {
                field0058 = 1;
            }
            if (field000a >= frameCount) {
                field0008 = 0;
                ResetPose();
            }
        }
        break;
    case 249:
        if ((field000a == 0) && ((unsigned short)field000c == 0)) {
            field00dc = 4;
            field00de = 0xec;
            velocityX = 0.0;
            field016c = 1;
            field014e = 0;
            field014c = 0x3c;
            effect.type = 0x28;
            effect.x = (double)((int(positionX)) + facing * 10);
            effect.y = (double)((int(positionY)) + -0x28);
            effect.group = 2;
            effect.layer = 1;
            effect.palette = 0x13;
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
    case 250:
        field0058 = 0;
        field0158 = 0;
        if ((field000a == 0) && ((unsigned short)field000c == 0)) {
            ResetFrame();
        }
        if ((field000a == 9) && ((unsigned short)field000c == 0)) {
            effect.type = 0x1f;
            effect.x = (double)(int(positionX));
            effect.y = (double)(int(positionY));
            effect.group = 0;
            effect.layer = 0;
            effect.facing = (facing == -1);
            contextOwner->EmitEffect(&effect);
        }
        if ((field000a == 9) && ((unsigned short)field000c == 0)) {
            effect.type = 0x1a1;
            effect.x = (double)((int(positionX)) + facing * 0x19);
            effect.y = (double)((int(positionY)) + -0x26);
            effect.group = 2;
            effect.layer = 1;
            effect.owner = 1;
            field02c8 = 0xb;
            effect.flag0018 = (unsigned char)facing;
            EmitLocalEffect(&effect);
            field0148 = field0148 + 0x2d;
        }
        ++field000c;
        if ((unsigned short)field000c >= frameDuration) {
            field000c = 0;
            ++field000a;
            field0168 = 0;
            if (field000a >= frameCount) {
                field0008 = 0;
                ResetPose();
            }
        }
        break;
    case 251:
        field0058 = 0;
        field0158 = 0;
        if ((field000a == 0) && ((unsigned short)field000c == 0)) {
            ResetFrame();
        }
        if ((field000a == 9) && ((unsigned short)field000c == 0)) {
            effect.type = 0x1f;
            effect.x = (double)(int(positionX));
            effect.y = (double)(int(positionY));
            effect.group = 0;
            effect.layer = 0;
            effect.facing = (facing == -1);
            contextOwner->EmitEffect(&effect);
        }
        if ((field000a == 9) && ((unsigned short)field000c == 0)) {
            effect.type = 0x1a2;
            effect.x = (double)((int(positionX)) + facing * 0x19);
            effect.y = (double)((int(positionY)) + -0x21);
            effect.group = 2;
            field02c8 = 0xb;
            effect.flag0018 = (unsigned char)facing;
            effect.layer = 1;
            EmitLocalEffect(&effect);
            field0148 = field0148 + 0x2d;
        }
        ++field000c;
        if ((unsigned short)field000c >= frameDuration) {
            field000c = 0;
            ++field000a;
            field0168 = 0;
            if (field000a >= frameCount) {
                field0008 = 0;
                ResetPose();
            }
        }
        break;
    case 252:
        field0058 = 0;
        field0158 = 0;
        if ((field000a == 0) && ((unsigned short)field000c == 0)) {
            StartTrail(3);
            ResetFrame();
            if (field0120 == '\0') {
                field0118 = field0118 - 500.0;
            }
            else {
                field0118 = field0118 - 250.0;
            }
            effect.type = 0x21;
            effect.palette = 0xb;
            effect.x = (double)(int(positionX));
            effect.y = (double)((int(positionY)) + -0x32);
            effect.group = 2;
            effect.layer = 1;
            contextOwner->EmitEffect(&effect);
            field3454 = 0;
        }
        if ((field000a == 5) && ((unsigned short)field000c == 0)) {
            effect.type = 0x1f;
            effect.flag0018 = (unsigned char)facing;
            effect.x = (double)(int(positionX));
            effect.y = (double)(int(positionY));
            effect.group = 0;
            effect.layer = 0;
            effect.facing = 1;
            contextOwner->EmitEffect(&effect);
            effect.type = 0x1f;
            effect.x = (double)(int(positionX));
            effect.y = (double)(int(positionY));
            effect.group = 0;
            effect.layer = 0;
            effect.facing = 0;
            contextOwner->EmitEffect(&effect);
        }
        if ((field000a == 5) && ((unsigned short)field000c == 0)) {
            effect.type = 0x1a3;
            effect.x = (double)((int(positionX)) + facing * 0x3c);
            effect.y = (double)((int(positionY)) + -100);
            effect.flag0018 = (unsigned char)facing;
            effect.group = 2;
            effect.layer = 1;
            EmitLocalEffect(&effect);
            effect.x = (double)((int(positionX)) - facing * 0x3c);
            effect.y = (double)((int(positionY)) + -100);
            EmitLocalEffect(&effect);
            effect.x = (double)((int(positionX)) + facing * 100);
            effect.y = (double)((int(positionY)) + -0x28);
            EmitLocalEffect(&effect);
            effect.x = (double)((int(positionX)) - facing * 100);
            effect.y = (double)((int(positionY)) + -0x28);
            field02c8 = 0xb;
            EmitLocalEffect(&effect);
            field0148 = field0148 + 0x2d;
        }
        ++field000c;
        if ((unsigned short)field000c >= frameDuration) {
            field000c = 0;
            ++field000a;
            field0168 = 0;
            if ((field000a == 9) && (field3138 < 5)) {
                field000a = field000a + -3;
                ++field3138;
            }
            if (field000a >= frameCount) {
                field0008 = 0;
                ResetPose();
            }
        }
        break;
    case 253:
        field0058 = 0;
        field0158 = 0;
        if ((field000a == 0) && ((unsigned short)field000c == 0)) {
            ResetFrame();
        }
        if ((field000a == 6) && ((unsigned short)field000c == 0)) {
            effect.type = 0x196;
            effect.x = (double)((int(positionX)) + facing * 0x3c);
            effect.y = 0.0;
            effect.group = 0;
            effect.flag0018 = (unsigned char)facing;
            effect.layer = 1;
            EmitLocalEffect(&effect);
            field0148 = field0148 + 0x2d;
        }
        ++field000c;
        if ((unsigned short)field000c >= frameDuration) {
            field000c = 0;
            ++field000a;
            field0168 = 0;
            if (field000a >= frameCount) {
                field0008 = 0;
                ResetPose();
            }
        }
        break;
    case 254:
        field0058 = 0;
        field0158 = 0;
        if ((field000a == 0) && ((unsigned short)field000c == 0)) {
            ResetFrame();
        }
        if ((field000a == 6) && ((unsigned short)field000c == 0)) {
            effect.type = 0x196;
            effect.x = (double)((int(positionX)) + facing * 0xa0);
            effect.y = 0.0;
            effect.group = 0;
            effect.flag0018 = (unsigned char)facing;
            effect.layer = 1;
            EmitLocalEffect(&effect);
            field0148 = field0148 + 0x2d;
        }
        ++field000c;
        if ((unsigned short)field000c >= frameDuration) {
            field000c = 0;
            ++field000a;
            field0168 = 0;
            if (field000a >= frameCount) {
                field0008 = 0;
                ResetPose();
            }
        }
        break;
    case 255:
        field0058 = 0;
        field0158 = 0;
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
            effect.x = (double)(int(positionX));
            effect.y = (double)((int(positionY)) + -0x32);
            effect.group = 2;
            effect.layer = 1;
            contextOwner->EmitEffect(&effect);
        }
        if ((field000a == 6) && ((unsigned short)field000c == 0)) {
            effect.type = 0x198;
            effect.x = (double)((int(positionX)) + facing * 0x3c);
            effect.y = 0.0;
            effect.group = 0;
            effect.layer = 1;
            effect.flag0018 = (unsigned char)facing;
            EmitLocalEffect(&effect);
            field0148 = field0148 + 0x2d;
        }
        ++field000c;
        if ((unsigned short)field000c >= frameDuration) {
            field000c = 0;
            ++field000a;
            field0168 = 0;
            if (field000a >= frameCount) {
                field0008 = 0;
                ResetPose();
            }
        }
        break;
    case 256:
        field0058 = 0;
        field0158 = 0;
        if ((field000a == 0) && ((unsigned short)field000c == 0)) {
            ResetFrame();
        }
        if ((field000a == 4) && ((unsigned short)field000c == 0)) {
            field02c8 = 2;
        }
        if ((field000a == 9) && ((unsigned short)field000c == 0)) {
            effect.type = 0x1bc;
            effect.x = (double)((int(positionX)) + facing * 0x1f);
            effect.y = (double)((int(positionY)) + -0x33);
            effect.group = 0;
            effect.layer = 1;
            effect.flag0018 = (unsigned char)facing;
            EmitLocalEffect(&effect);
            effect.type = 0x1bf;
            effect.x = (double)((int(positionX)) + facing * 0x1a);
            effect.y = (double)((int(positionY)) + -0x1f);
            EmitLocalEffect(&effect);
            effect.type = 0x1be;
            effect.x = (double)((int(positionX)) + facing * 0x15);
            effect.y = (double)((int(positionY)) + -0xb);
            EmitLocalEffect(&effect);
            field02c8 = 3;
            field0148 = field0148 + 0xf;
        }
        if ((field000a == 0xe) && ((unsigned short)field000c == 0)) {
            effect.type = 0x1bd;
            effect.x = (double)((int(positionX)) + facing * 0xd);
            effect.y = (double)((int(positionY)) + -0x3a);
            effect.group = 0;
            effect.layer = 1;
            effect.flag0018 = (unsigned char)facing;
            EmitLocalEffect(&effect);
            effect.type = 0x1bf;
            effect.x = (double)((int(positionX)) + facing * 0x12);
            effect.y = (double)((int(positionY)) + -0x26);
            EmitLocalEffect(&effect);
            effect.type = 0x1be;
            effect.x = (double)((int(positionX)) + facing * 0x15);
            effect.y = (double)((int(positionY)) + -0x12);
            EmitLocalEffect(&effect);
            field02c8 = 3;
            field0148 = field0148 + 0xf;
        }
        ++field000c;
        if ((unsigned short)field000c >= frameDuration) {
            field000c = 0;
            ++field000a;
            field0168 = 0;
            if (field000a >= frameCount) {
                field0008 = 0;
                ResetPose();
                FaceOpponent();
            }
        }
        break;
    case 257:
        field0058 = 0;
        field0158 = 0;
        if ((field000a == 0) && ((unsigned short)field000c == 0)) {
            ResetFrame();
        }
        if ((field000a == 4) && ((unsigned short)field000c == 0)) {
            field02c8 = 2;
        }
        if ((field000a == 9) && ((unsigned short)field000c == 0)) {
            effect.type = 0x1bc;
            effect.x = (double)((int(positionX)) + facing * 0x1f);
            effect.y = (double)((int(positionY)) + -0x33);
            effect.group = 0;
            effect.layer = 1;
            effect.flag0018 = (unsigned char)facing;
            EmitLocalEffect(&effect);
            effect.type = 0x1bf;
            effect.x = (double)((int(positionX)) + facing * 0x1a);
            effect.y = (double)((int(positionY)) + -0x1f);
            EmitLocalEffect(&effect);
            effect.type = 0x1be;
            effect.x = (double)((int(positionX)) + facing * 0x15);
            effect.y = (double)((int(positionY)) + -0xb);
            EmitLocalEffect(&effect);
            field02c8 = 3;
            field0148 = field0148 + 0xf;
        }
        if ((field000a == 0xe) && ((unsigned short)field000c == 0)) {
            effect.type = 0x1c3;
            effect.x = (double)((int(positionX)) + facing * 6);
            effect.y = (double)((int(positionY)) + -0x47);
            effect.group = 0;
            effect.layer = 1;
            effect.flag0018 = (unsigned char)facing;
            EmitLocalEffect(&effect);
            effect.type = 0x1c1;
            effect.x = (double)((int(positionX)) + facing * 0x10);
            effect.y = (double)((int(positionY)) + -0x3d);
            EmitLocalEffect(&effect);
            effect.type = 0x1c0;
            effect.x = (double)((int(positionX)) + facing * 0x1a);
            effect.y = (double)((int(positionY)) + -0x33);
            EmitLocalEffect(&effect);
            field02c8 = 3;
            field0148 = field0148 + 0xf;
        }
        ++field000c;
        if ((unsigned short)field000c >= frameDuration) {
            field000c = 0;
            ++field000a;
            field0168 = 0;
            if (field000a >= frameCount) {
                field0008 = 0;
                ResetPose();
                FaceOpponent();
            }
        }
        break;
    case 258:
        field0058 = 0;
        field0158 = 0;
        if ((field000a == 0) && ((unsigned short)field000c == 0)) {
            ResetFrame();
        }
        if ((field000a == 4) && ((unsigned short)field000c == 0)) {
            field02c8 = 2;
        }
        if ((field000a == 9) && ((unsigned short)field000c == 0)) {
            effect.type = 0x1c3;
            effect.x = (double)((int(positionX)) + facing * 6);
            effect.y = (double)((int(positionY)) + -0x47);
            effect.group = 0;
            effect.layer = 1;
            effect.flag0018 = (unsigned char)facing;
            EmitLocalEffect(&effect);
            effect.type = 0x1c2;
            effect.x = (double)((int(positionX)) + facing * 0x10);
            effect.y = (double)((int(positionY)) + -0x3d);
            EmitLocalEffect(&effect);
            effect.type = 0x1c0;
            effect.x = (double)((int(positionX)) + facing * 0x1a);
            effect.y = (double)((int(positionY)) + -0x33);
            EmitLocalEffect(&effect);
            field02c8 = 3;
            field0148 = field0148 + 0xf;
        }
        if ((field000a == 0xe) && ((unsigned short)field000c == 0)) {
            effect.type = 0x1c3;
            effect.x = (double)((int(positionX)) + facing * 6);
            effect.y = (double)((int(positionY)) + -0x47);
            effect.group = 0;
            effect.layer = 1;
            effect.flag0018 = (unsigned char)facing;
            EmitLocalEffect(&effect);
            effect.type = 0x1c1;
            effect.x = (double)((int(positionX)) + facing * 0x10);
            effect.y = (double)((int(positionY)) + -0x3d);
            EmitLocalEffect(&effect);
            effect.type = 0x1c0;
            effect.x = (double)((int(positionX)) + facing * 0x1a);
            effect.y = (double)((int(positionY)) + -0x33);
            EmitLocalEffect(&effect);
            field02c8 = 3;
            field0148 = field0148 + 0xf;
        }
        ++field000c;
        if ((unsigned short)field000c >= frameDuration) {
            field000c = 0;
            ++field000a;
            field0168 = 0;
            if (field000a >= frameCount) {
                field0008 = 0;
                ResetPose();
                FaceOpponent();
            }
        }
        break;
    case 259:
        field0058 = 0;
        field0158 = 0;
        if ((field000a == 0) && ((unsigned short)field000c == 0)) {
            ResetFrame();
            field016c = 1;
        }
        ++field000c;
        if ((unsigned short)field000c >= frameDuration) {
            field000c = 0;
            ++field000a;
            if (field000a == 1) {
                field0168 = 0;
            }
            if ((field000a == 4) && ((unsigned short)field000c == 0)) {
                effect.type = 0x1b5;
                effect.x = (double)(int(positionX));
                effect.y = 0.0;
                effect.group = 2;
                effect.layer = 1;
                effect.flag0018 = (unsigned char)facing;
                EmitLocalEffect(&effect);
                field0148 = field0148 + 0x2d;
            }
            if ((field000a == 7) && (field3138 < 4)) {
                field000a = field000a + -3;
                ++field3138;
            }
            if (field000a >= frameCount) {
                field0008 = 0;
                ResetPose();
            }
        }
        break;
    case 260:
        field0058 = 0;
        field0158 = 0;
        if ((field000a == 0) && ((unsigned short)field000c == 0)) {
            ResetFrame();
            field016c = 1;
        }
        ++field000c;
        if ((unsigned short)field000c >= frameDuration) {
            field000c = 0;
            ++field000a;
            if (field000a == 1) {
                field0168 = 0;
            }
            if ((field000a == 4) && ((unsigned short)field000c == 0)) {
                effect.type = 0x1b5;
                effect.x = (double)(int(positionX));
                effect.y = 0.0;
                effect.group = 2;
                effect.layer = 1;
                effect.flag0018 = (unsigned char)facing;
                EmitLocalEffect(&effect);
                field0148 = field0148 + 0x2d;
            }
            if ((field000a == 7) && (field3138 < 4)) {
                field000a = field000a + -3;
                ++field3138;
            }
            if (field000a >= frameCount) {
                field0008 = 0;
                ResetPose();
            }
        }
        break;
    case 261:
        field0058 = 0;
        field0158 = 0;
        if ((field000a == 0) && ((unsigned short)field000c == 0)) {
            ResetFrame();
            field016c = 1;
            if (field0120 == '\0') {
                field0118 = field0118 - 500.0;
            }
            else {
                field0118 = field0118 - 250.0;
            }
            effect.type = 0x21;
            effect.palette = 0xb;
            effect.x = (double)(int(positionX));
            effect.y = (double)((int(positionY)) + -0x32);
            effect.group = 2;
            effect.layer = 1;
            contextOwner->EmitEffect(&effect);
        }
        if ((field000a == 0) && ((unsigned short)field000c == 0)) {
            ResetFrame();
            field016c = 3;
        }
        if (((field000a == 5) && ((unsigned short)field000c == 0)) && (field3138 < 2)
            ) {
            effect.type = 0x1b5;
            effect.x = (double)(int)((int(positionX)) + -0x23 + (((unsigned short)RandomRange(0, 0x46))));
            effect.y = 0.0;
            effect.group = 2;
            effect.layer = 1;
            effect.flag0018 = (unsigned char)facing;
            EmitLocalEffect(&effect);
            field0148 = field0148 + 0x14;
        }
        ++field000c;
        if ((unsigned short)field000c >= frameDuration) {
            field000c = 0;
            ++field000a;
            if ((field000a == 7) && (field3138 < 4)) {
                field000a = field000a + -3;
                ++field3138;
            }
            if ((field000a == 4) && (field3138 < 2)) {
                field0168 = 0;
            }
            if (field000a >= frameCount) {
                field0008 = 0;
                ResetPose();
            }
        }
        break;
    case 262:
        field0058 = 0;
        if ((field000a == 0) && ((unsigned short)field000c == 0)) {
            velocityX = 0.0;
            velocityY = 0.0;
        }
        if ((field000a == 7) && ((unsigned short)field000c == 0)) {
            effect.type = 0x1a1;
            effect.x = (double)((int(positionX)) + facing * 0x19);
            effect.y = (double)((int(positionY)) + -0x26);
            effect.group = 2;
            effect.layer = 1;
            effect.owner = 1;
            field02c8 = 0xb;
            effect.flag0018 = (unsigned char)facing;
            EmitLocalEffect(&effect);
            field0148 = field0148 + 0x2d;
        }
        ++field000c;
        if ((unsigned short)field000c >= frameDuration) {
            field000c = 0;
            ++field000a;
            field0168 = 0;
            if (field000a >= frameCount) {
                field0008 = 9;
                ResetPose();
                if (0 < field3458) {
                    field000a = 7;
                    field0008 = 0xb3;
                }
            }
        }
        break;
    case 263:
        field0058 = 0;
        if ((field000a == 0) && ((unsigned short)field000c == 0)) {
            velocityX = 0.0;
            velocityY = 0.0;
        }
        if ((field000a == 7) && ((unsigned short)field000c == 0)) {
            effect.type = 0x1a4;
            effect.x = (double)((int(positionX)) + facing * 0x19);
            effect.y = (double)((int(positionY)) + -0x26);
            effect.group = 2;
            effect.layer = 1;
            effect.owner = 1;
            field02c8 = 0xb;
            effect.flag0018 = (unsigned char)facing;
            EmitLocalEffect(&effect);
            field0148 = field0148 + 0x2d;
        }
        ++field000c;
        if ((unsigned short)field000c >= frameDuration) {
            field000c = 0;
            ++field000a;
            field0168 = 0;
            if (field000a >= frameCount) {
                field0008 = 9;
                ResetPose();
                if (0 < field3458) {
                    field000a = 7;
                    field0008 = 0xb3;
                }
            }
        }
        break;
    case 264:
        field0058 = 0;
        if ((field000a == 0) && ((unsigned short)field000c == 0)) {
            StartTrail(3);
            velocityX = 0.0;
            velocityY = 0.0;
            if (field0120 == '\0') {
                field0118 = field0118 - 500.0;
            }
            else {
                field0118 = field0118 - 250.0;
            }
            effect.type = 0x21;
            effect.palette = 0xb;
            effect.x = (double)(int(positionX));
            effect.y = (double)((int(positionY)) + -0x32);
            effect.group = 2;
            effect.layer = 1;
            contextOwner->EmitEffect(&effect);
            field3454 = 0;
        }
        if ((field000a == 5) && ((unsigned short)field000c == 0)) {
            effect.type = 0x1a3;
            effect.x = (double)((int(positionX)) + facing * 0x3c);
            effect.y = (double)((int(positionY)) + -100);
            effect.flag0018 = (unsigned char)facing;
            effect.group = 2;
            effect.layer = 1;
            EmitLocalEffect(&effect);
            effect.x = (double)((int(positionX)) - facing * 0x3c);
            effect.y = (double)((int(positionY)) + -100);
            EmitLocalEffect(&effect);
            effect.x = (double)((int(positionX)) + facing * 100);
            effect.y = (double)((int(positionY)) + -0x28);
            EmitLocalEffect(&effect);
            effect.x = (double)((int(positionX)) - facing * 100);
            effect.y = (double)((int(positionY)) + -0x28);
            field02c8 = 0xb;
            EmitLocalEffect(&effect);
            field0148 = field0148 + 0x2d;
        }
        ++field000c;
        if ((unsigned short)field000c >= frameDuration) {
            field000c = 0;
            ++field000a;
            field0168 = 0;
            if ((field000a == 0xb) && (field3138 < 2)) {
                field000a = field000a + -3;
                ++field3138;
            }
            if (field000a >= frameCount) {
                field0008 = 9;
                ResetPose();
                if (0 < field3458) {
                    field0008 = 0xb3;
                    field000a = 7;
                }
            }
        }
        break;
    case 265:
        field0058 = 0;
        if ((field000a == 0) && ((unsigned short)field000c == 0)) {
            velocityX = 0.0;
            velocityY = 0.0;
        }
        if ((field000a == 7) && ((unsigned short)field000c == 0)) {
            effect.type = 0x1cb;
            effect.x = (double)((int(positionX)) + facing * 0x26);
            effect.y = (double)((int(positionY)) + -0x37);
            effect.group = 2;
            effect.layer = 1;
            effect.owner = 1;
            field02c8 = 0xb;
            effect.flag0018 = (unsigned char)facing;
            EmitLocalEffect(&effect);
            field0148 = field0148 + 0x2d;
        }
        ++field000c;
        if ((unsigned short)field000c >= frameDuration) {
            field000c = 0;
            ++field000a;
            field0168 = 0;
            if (field000a >= frameCount) {
                field0008 = 9;
                ResetPose();
                if (0 < field3458) {
                    field000a = 7;
                    field0008 = 0xb3;
                }
            }
        }
        break;
    case 300:
        field0058 = 0;
        field0158 = 0;
        if ((field000a == 0) && ((unsigned short)field000c == 0)) {
            ResetFrame();
        }
        if ((field000a == 3) && ((unsigned short)field000c == 0)) {
            ResetFrame();
            field014c = 0x78;
            field0148 = field0148 + -1000;
            SetTint(0xb0,3);
            effect.type = 0x44;
            effect.palette = 0x13;
            effect.x = (double)((int(positionX)) - facing * 0xe);
            effect.y = (double)((int(positionY)) + -0x32);
            effect.group = 2;
            effect.layer = 1;
            contextOwner->EmitEffect(&effect);
        }
        if (2 < field000a) {
            SetHorizontalShake(0x32,3);
        }
        if (((field000a == 5) && ((unsigned short)field000c == 0)) && (field313c < 7)
            ) {
            effect.owner = 1;
            effect.type = field3138 + 0x19b;
            effect.x = (double)(int)((int(positionX)) - ((((unsigned short)RandomRange(0, 0x14))) + 0x154 + field313c * 8) *
                (int)facing);
            effect.y = (double)(int)(4 - (((unsigned short)RandomRange(0, 4))));
            effect.field0028 = 1;
            effect.flag0018 = (unsigned char)facing;
            effect.group = 0;
            effect.layer = 1;
            ++field3138;
            if (5 < field3138) {
                field3138 = 0;
            }
            EmitLocalEffect(&effect);
        }
        ++field000c;
        if ((unsigned short)field000c >= frameDuration) {
            field000c = 0;
            ++field000a;
            field0168 = 0;
            if ((field000a == 7) && (field313c < 10)) {
                field000a = field000a + -2;
                ++field313c;
            }
            if (field000a >= frameCount) {
                field0008 = 0;
                FaceOpponent();
                ResetPose();
            }
        }
        break;
    case 301:
        field0058 = 0;
        field0158 = 0;
        if ((field000a == 0) && ((unsigned short)field000c == 0)) {
            ResetFrame();
        }
        if ((field000a == 3) && ((unsigned short)field000c == 0)) {
            ResetFrame();
            field014c = 0x78;
            field0148 = field0148 + -2000;
            SetTint(0xb0,3);
            effect.type = 0x45;
            effect.palette = 5;
            effect.x = (double)((int(positionX)) - facing * 0xe);
            effect.y = (double)((int(positionY)) + -0x32);
            effect.group = 2;
            effect.layer = 1;
            contextOwner->EmitEffect(&effect);
        }
        if (2 < field000a) {
            SetHorizontalShake(0x32,3);
        }
        if (((field000a == 5) && ((unsigned short)field000c == 0)) &&
            (field313c < 0x11)) {
            effect.owner = 1;
            effect.type = field3138 + 0x19b;
            effect.x = (double)(int)((int(positionX)) - ((((unsigned short)RandomRange(0, 0x14))) + 0x154 + field313c * 8) *
                (int)facing);
            effect.y = (double)(int)(4 - (((unsigned short)RandomRange(0, 4))));
            effect.field0028 = 1;
            effect.flag0018 = (unsigned char)facing;
            effect.group = 0;
            effect.layer = 1;
            ++field3138;
            if (5 < field3138) {
                field3138 = 0;
            }
            EmitLocalEffect(&effect);
        }
        ++field000c;
        if ((unsigned short)field000c >= frameDuration) {
            field000c = 0;
            ++field000a;
            field0168 = 0;
            if ((field000a == 7) && (field313c < 0x14)) {
                field000a = field000a + -2;
                ++field313c;
            }
            if (field000a >= frameCount) {
                field0008 = 0;
                FaceOpponent();
                ResetPose();
            }
        }
        break;
    case 302:
        field0058 = 0;
        field0158 = 0;
        if ((field000a == 0) && ((unsigned short)field000c == 0)) {
            ResetFrame();
        }
        if ((field000a == 3) && ((unsigned short)field000c == 0)) {
            ResetFrame();
            field014c = 0x78;
            field0148 = field0148 + -3000;
            SetTint(0xb0,3);
            effect.type = 0x46;
            effect.palette = 0x40;
            effect.x = (double)((int(positionX)) - facing * 0xe);
            effect.y = (double)((int(positionY)) + -0x32);
            effect.group = 2;
            effect.layer = 1;
            contextOwner->EmitEffect(&effect);
            field02c9 = 0x25;
        }
        if (2 < field000a) {
            contextOwner->SetSceneTimer(0xf);
        }
        if (2 < field000a) {
            SetHorizontalShake(0x32,3);
        }
        if (((field000a == 5) && ((unsigned short)field000c == 0)) &&
            (field313c < 0x23)) {
            effect.owner = 1;
            effect.type = field3138 + 0x19b;
            effect.x = (double)(int)((int(positionX)) - ((((unsigned short)RandomRange(0, 0x14))) + 0x154 + field313c * 8) *
                (int)facing);
            effect.y = (double)(int)(4 - (((unsigned short)RandomRange(0, 4))));
            effect.field0028 = 1;
            effect.flag0018 = (unsigned char)facing;
            effect.group = 0;
            effect.layer = 1;
            ++field3138;
            if (5 < field3138) {
                field3138 = 0;
            }
            EmitLocalEffect(&effect);
        }
        ++field000c;
        if ((unsigned short)field000c >= frameDuration) {
            field000c = 0;
            ++field000a;
            field0168 = 0;
            if ((field000a == 7) && (field313c < 0x23)) {
                field000a = field000a + -2;
                ++field313c;
            }
            if (field000a >= frameCount) {
                field0008 = 0;
                FaceOpponent();
                ResetPose();
            }
        }
        break;
    case 303:
        field0058 = 0;
        field0158 = 0;
        if ((field000a == 0) && ((unsigned short)field000c == 0)) {
            velocityX = 0.0;
            velocityY = 0.0;
            gravity = 0.0;
        }
        if ((field000a == 7) && ((unsigned short)field000c == 0)) {
            field014c = 0x78;
            field0148 = field0148 + -1000;
            SetTint(0xb0,3);
            effect.type = 0x44;
            effect.palette = 0x13;
            effect.x = (double)(int(positionX));
            effect.y = (double)((int(positionY)) + -0x28);
            effect.group = 2;
            effect.owner = 1;
            effect.layer = 1;
            contextOwner->EmitEffect(&effect);
            SetHorizontalShake(0x32,0x2d);
        }
        if ((field000a == 8) && ((unsigned short)field000c == 0)) {
            effect.type = 0x1b8;
            effect.field0028 = 1;
            effect.x = (double)(int((*opponentSlot)->positionX));
            effect.y = -480.0;
            effect.flag0018 = (unsigned char)facing;
            effect.group = 0;
            effect.layer = 1;
            EmitLocalEffect(&effect);
        }
        if (field000a > 7 && field3448 == 1) {
            contextOwner->StartFade(9,0x50,9);
            ResetPose();
            field0008 = 0x132;
            break;
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
    case 304:
        field0058 = 0;
        field0158 = 0;
        if ((field000a == 0) && ((unsigned short)field000c == 0)) {
            velocityX = 0.0;
            velocityY = 0.0;
            gravity = 0.0;
        }
        if ((field000a == 7) && ((unsigned short)field000c == 0)) {
            field014c = 0x78;
            field0148 = field0148 + -2000;
            SetTint(0xb0,3);
            effect.type = 0x45;
            effect.palette = 5;
            effect.x = (double)(int(positionX));
            effect.y = (double)((int(positionY)) + -0x28);
            effect.group = 2;
            effect.owner = 1;
            effect.layer = 1;
            contextOwner->EmitEffect(&effect);
            SetHorizontalShake(0x32,0x2d);
        }
        if ((field000a == 8) && ((unsigned short)field000c == 0)) {
            effect.type = 0x1b8;
            effect.field0028 = 1;
            effect.x = (double)(int((*opponentSlot)->positionX));
            effect.y = -480.0;
            effect.flag0018 = (unsigned char)facing;
            effect.group = 0;
            effect.layer = 1;
            EmitLocalEffect(&effect);
        }
        if (field000a > 7 && field3448 == 1) {
            contextOwner->StartFade(9,0x50,9);
            ResetPose();
            field0008 = 0x133;
            break;
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
    case 305:
        field0058 = 0;
        field0158 = 0;
        if ((field000a == 0) && ((unsigned short)field000c == 0)) {
            velocityX = 0.0;
            velocityY = 0.0;
            gravity = 0.0;
        }
        if ((field000a == 7) && ((unsigned short)field000c == 0)) {
            field014c = 0x78;
            field0148 = field0148 + -3000;
            SetTint(0xb0,3);
            effect.type = 0x46;
            effect.palette = 0x40;
            effect.x = (double)(int(positionX));
            effect.y = (double)((int(positionY)) + -0x28);
            effect.group = 2;
            effect.owner = 1;
            effect.layer = 1;
            contextOwner->EmitEffect(&effect);
            SetHorizontalShake(0x32,0x2d);
            field02c9 = 0x25;
        }
        if (6 < field000a) {
            contextOwner->SetSceneTimer(0xf);
        }
        if ((field000a == 8) && ((unsigned short)field000c == 0)) {
            effect.type = 0x1b8;
            effect.field0028 = 1;
            effect.x = (double)(int((*opponentSlot)->positionX));
            effect.y = -480.0;
            effect.flag0018 = (unsigned char)facing;
            effect.group = 0;
            effect.layer = 1;
            EmitLocalEffect(&effect);
        }
        if (field000a > 7 && field3448 == 1) {
            contextOwner->StartFade(9,0x50,9);
            ResetPose();
            field0008 = 0x134;
            break;
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
    case 306:
        SetHorizontalShake(0x32,0xf);
        if ((field000a == 1) && ((unsigned short)field000c == 0)) {
            field3448 = 2;
            positionX = 230.0;
            facing = 1;
            (*opponentSlot)->field0008 = 0x7a;
            (*opponentSlot)->facing = 1;
            (*opponentSlot)->ResetPose();
            (*opponentSlot)->ResetFrame();
            (*opponentSlot)->positionX = 420.0;
            (*opponentSlot)->positionY = -17.0;
        }
        if ((field000a == 6) && ((unsigned short)field000c == 0)) {
            field02c8 = 2;
        }
        if ((field000a == 10) && ((unsigned short)field000c == 0)) {
            field02c8 = 3;
            effect.type = 0x1c6;
            effect.group = 0;
            effect.x = positionX + 20.0;
            effect.y = -50.0;
            effect.owner = 1;
            effect.layer = 0;
            effect.flag0018 = (unsigned char)facing;
            EmitLocalEffect(&effect);
        }
        ++field000c;
        if ((unsigned short)field000c >= frameDuration) {
            field000c = 0;
            ++field000a;
            field0168 = 0;
            if ((field000a == 0x11) &&
                (((field3448 == 2 || (field3448 == 4)) || (0 < field313c)))) {
                field000a = field000a + -3;
                --field313c;
            }
            if ((field000a == 0x11) && (field3448 == 5)) {
                field000a = 0x15;
            }
            if (field000a >= frameCount) {
                field0008 = 0;
                field3448 = 0;
                FaceOpponent();
                ResetPose();
            }
        }
        break;
    case 307:
        SetHorizontalShake(0x32,0xf);
        if ((field000a == 1) && ((unsigned short)field000c == 0)) {
            field3448 = 2;
            positionX = 230.0;
            facing = 1;
            (*opponentSlot)->field0008 = 0x7a;
            (*opponentSlot)->facing = 1;
            (*opponentSlot)->ResetPose();
            (*opponentSlot)->ResetFrame();
            (*opponentSlot)->positionX = 420.0;
            (*opponentSlot)->positionY = -17.0;
        }
        if ((field000a == 1) && ((unsigned short)field000c == 0)) {
            effect.type = 0x1b7;
            effect.x = (double)((int(positionX)) + facing * 0x10);
            effect.y = 0.0;
            effect.group = 0;
            effect.owner = 1;
            effect.field0028 = 1;
            effect.layer = 0;
            effect.flag0018 = (unsigned char)facing;
            EmitLocalEffect(&effect);
        }
        if ((field000a == 6) && ((unsigned short)field000c == 0)) {
            field02c8 = 2;
        }
        if ((field000a == 0x10) && ((unsigned short)field000c == 0)) {
            field02c8 = 3;
            effect.type = 0x1c6;
            if (field3138 == 1) {
                effect.type = 0x1c7;
            }
            if (field3138 == 2) {
                effect.type = 0x1c5;
            }
            effect.group = 0;
            effect.x = positionX + 20.0;
            effect.y = -50.0;
            effect.owner = 1;
            effect.layer = 0;
            effect.flag0018 = (unsigned char)facing;
            EmitLocalEffect(&effect);
        }
        ++field000c;
        if ((unsigned short)field000c >= frameDuration) {
            field000c = 0;
            ++field000a;
            field0168 = 0;
            if (field000a == 10) {
                field000a = 0x10;
            }
            if (field000a == 0xd) {
                field000a = 0x10;
            }
            if (field000a == 7) {
                if (field3138 == 1) {
                    field000a = 10;
                }
                if (field3138 == 2) {
                    field000a = 0xd;
                }
            }
            if ((field000a == 0x17) &&
                (((field3448 == 2 || (field3448 == 4)) || (0 < field313c)))) {
                field000a = field000a + -3;
                --field313c;
            }
            if (field000a == 0x1e) {
                field000a = 2;
                field3448 = 2;
                ++field3138;
            }
            if ((field000a == 0x1b) && (field3138 == 1)) {
                field000a = 0x1e;
            }
            if ((field000a == 0x17) && (field3448 == 5)) {
                field000a = 0x1e;
            }
            if (field000a >= frameCount) {
                field0008 = 0;
                field3448 = 0;
                FaceOpponent();
                ResetPose();
            }
        }
        break;
    case 308:
        SetHorizontalShake(0x32,0xf);
        contextOwner->SetSceneTimer(0xf);
        if ((field000a == 1) && ((unsigned short)field000c == 0)) {
            field3448 = 2;
            positionX = 230.0;
            facing = 1;
            (*opponentSlot)->field0008 = 0x7a;
            (*opponentSlot)->facing = 1;
            (*opponentSlot)->ResetPose();
            (*opponentSlot)->ResetFrame();
            (*opponentSlot)->positionX = 420.0;
            (*opponentSlot)->positionY = -17.0;
        }
        if ((field000a == 1) && ((unsigned short)field000c == 0)) {
            effect.type = 0x1b7;
            effect.x = (double)((int(positionX)) + facing * 0x10);
            effect.y = 0.0;
            effect.group = 0;
            effect.owner = 1;
            effect.field0028 = 1;
            effect.layer = 0;
            effect.flag0018 = (unsigned char)facing;
            EmitLocalEffect(&effect);
        }
        if ((field000a == 6) && ((unsigned short)field000c == 0)) {
            field02c8 = 2;
        }
        if ((field000a == 0x10) && ((unsigned short)field000c == 0)) {
            field02c8 = 3;
            effect.type = 0x1c6;
            if (field3138 == 1) {
                effect.type = 0x1c7;
            }
            if (field3138 == 2) {
                effect.type = 0x1c5;
            }
            effect.group = 0;
            effect.x = positionX + 20.0;
            effect.y = -50.0;
            effect.owner = 1;
            effect.layer = 0;
            effect.flag0018 = (unsigned char)facing;
            EmitLocalEffect(&effect);
        }
        ++field000c;
        if ((unsigned short)field000c >= frameDuration) {
            field000c = 0;
            ++field000a;
            field0168 = 0;
            if (field000a == 10) {
                field000a = 0x10;
            }
            if (field000a == 0xd) {
                field000a = 0x10;
            }
            if (field000a == 7) {
                if (field3138 == 1) {
                    field000a = 10;
                }
                if (field3138 == 2) {
                    field000a = 0xd;
                }
            }
            if ((field000a == 0x17) &&
                (((field3448 == 2 || (field3448 == 4)) || (0 < field313c)))) {
                field000a = field000a + -3;
                --field313c;
            }
            if (field000a == 0x1e) {
                field000a = 2;
                field3448 = 2;
                ++field3138;
            }
            if ((field000a == 0x1b) && (field3138 == 2)) {
                field000a = 0x1e;
            }
            if ((field000a == 0x17) && (field3448 == 5)) {
                field000a = 0x1e;
            }
            if (field000a >= frameCount) {
                field0008 = 0;
                field3448 = 0;
                FaceOpponent();
                ResetPose();
            }
        }
        break;
    case 309:
        StartTrail(2);
        if (field000a < 6) {
            SetHorizontalShake(0x32,3);
        }
        if ((field000a < 0xe) && ((*opponentSlot)->field0008 == 99)) {
            (*opponentSlot)->ResetPose();
        }
        if (8 < field000a) {
            if ((0.0 < velocityY + positionY) &&
                (field000a < 0xe)) {
                positionY = 0.0;
                field000a = 0xe;
                field000c = 0;
                ResetFrame();
                SetVerticalShake(0xf,10);
                field02c9 = 0x16;
                ApplyDamage(800,900.0);
                (*opponentSlot)->ResetPose();
                (*opponentSlot)->field0008 = 0x62;
                effect.type = 400;
                effect.x = (double)(int(positionX));
                effect.y = (double)(int(positionY));
                effect.group = 2;
                effect.layer = 1;
                effect.flag0018 = (unsigned char)facing;
                EmitLocalEffect(&effect);
                effect.type = 0;
                contextOwner->EmitEffect(&effect);
                (*opponentSlot)->field014a = 0xb4;
                return;
            }
            velocityY = velocityY + gravity;
        }
        ++field000c;
        if ((unsigned short)field000c >= frameDuration) {
            field000c = 0;
            ++field000a;
            if (field000a == 1) {
                (*opponentSlot)->ResetPose();
                (*opponentSlot)->field0008 = 0x67;
                (*opponentSlot)->positionY = -98.0;
                (*opponentSlot)->positionX =
                (double)(facing * 0x23) + positionX;
            }
            if (field000a == 2) {
                (*opponentSlot)->positionY = -98.0;
                (*opponentSlot)->positionX =
                (double)(facing * 0x21) + positionX;
                if (0 < field3138) {
                    field000c = 0x96;
                }
            }
            if (field000a == 3) {
                (*opponentSlot)->positionY = 0.0;
                (*opponentSlot)->positionX =
                (double)(facing * 0x21) + positionX;
                (*opponentSlot)->facing = -facing;
                (*opponentSlot)->ResetPose();
                (*opponentSlot)->field0008 = 0x61;
                (*opponentSlot)->field012c = 1;
                ApplyDamage(300,980.0);
                if ((*opponentSlot)->field0108 <= 0) {
                    (*opponentSlot)->field0108 = 1;
                }
            }
            if ((field000a == 6) && (field3138 < 3)) {
                ++field3138;
                field000a = 0;
            }
            if (field000a == 9) {
                velocityY = -7.0;
                velocityX = 0.3;
                gravity = 0.15;
            }
            field0168 = 0;
            if (field000a >= frameCount) {
                field0008 = 0;
                FaceOpponent();
                ResetPose();
            }
        }
        break;
    case 310:
        if ((field000a == 0) && ((unsigned short)field000c == 0)) {
            (*opponentSlot)->ResetPose();
        }
        if ((field000a == 1) && ((unsigned short)field000c == 0)) {
            ResetFrame();
            field014c = 0x78;
            field0148 = field0148 + -3000;
            SetTint(0xb0,3);
            effect.type = 9;
            effect.palette = 5;
            effect.x = (double)((int(positionX)) + facing * 0x17);
            effect.y = (double)((int(positionY)) + -0x1e);
            effect.group = 2;
            effect.owner = 1;
            effect.layer = 1;
            contextOwner->EmitEffect(&effect);
            SetHorizontalShake(0x32,0x2d);
        }
        if (field000a < 7) {
            SetHorizontalShake(0x32,0x2d);
            (*opponentSlot)->field014a = 3;
        }
        if (field000a == 7) {
            SetHorizontalShake(0,0);
        }
        ++field000c;
        if ((unsigned short)field000c >= frameDuration) {
            field000c = 0;
            ++field000a;
            field0168 = 0;
            if ((field000a == 3) || (field000a == 6)) {
                effect.type = 0;
                effect.palette = 2;
                effect.x = (double)((int(positionX)) + facing * 0x1d);
                effect.y = (double)((int(positionY)) + -0x53);
                effect.group = 2;
                effect.owner = 1;
                effect.layer = 1;
                contextOwner->EmitEffect(&effect);
            }
            if (field000a == 1) {
                (*opponentSlot)->field0008 = 0x67;
                (*opponentSlot)->ResetPose();
                (*opponentSlot)->positionY = -101.0;
                (*opponentSlot)->positionX =
                (double)(facing * 0x15) + positionX;
            }
            if (field000a == 2) {
                (*opponentSlot)->positionY = -99.0;
                (*opponentSlot)->positionX =
                (double)(facing * 0xf) + positionX;
                field02c9 = 0x16;
                effect.type = 0x193;
                effect.x = (double)(int(positionX));
                effect.y = (double)((int(positionY)) + -0xfa);
                effect.group = 2;
                effect.owner = 1;
                effect.flag0018 = (unsigned char)facing;
                effect.layer = 1;
                EmitLocalEffect(&effect);
            }
            if (field000a == 3) {
                (*opponentSlot)->field0008 = 100;
                (*opponentSlot)->positionY = -99.0;
                (*opponentSlot)->positionX =
                (double)(facing * 0xf) + positionX;
            }
            if (field000a == 4) {
                (*opponentSlot)->field0008 = 0x67;
                (*opponentSlot)->positionY = -99.0;
                (*opponentSlot)->positionX =
                (double)(facing * 0xf) + positionX;
            }
            if (field000a == 5) {
                (*opponentSlot)->field0008 = 100;
                (*opponentSlot)->positionY = -99.0;
                (*opponentSlot)->positionX =
                (double)(facing * 0xf) + positionX;
            }
            if (field000a == 6) {
                (*opponentSlot)->field0008 = 0x67;
                (*opponentSlot)->positionY = -99.0;
                (*opponentSlot)->positionX =
                (double)(facing * 0xf) + positionX;
            }
            if ((field000a == 7) && (10 < field3138)) {
                (*opponentSlot)->field0008 = 0x3e;
                (*opponentSlot)->field00c0 = 0.0;
                (*opponentSlot)->field00c8 = -5.0;
                (*opponentSlot)->gravity = 0.035;
                ApplyDamage(0xdac,700.0);
                (*opponentSlot)->field0124 = 0xb4;
            }
            if ((field000a == 7) && (field3138 < 0xb)) {
                ++field3138;
                field000a = 2;
            }
            if (field000a >= frameCount) {
                field0008 = 0;
                ResetPose();
                FaceOpponent();
            }
        }
        break;
    case 311:
        if ((field000a == 0) && ((unsigned short)field000c == 0)) {
            (*opponentSlot)->ResetPose();
        }
        if (field000a < 7) {
            SetHorizontalShake(0x32,0x2d);
            (*opponentSlot)->field014a = 3;
        }
        if (field000a == 7) {
            SetHorizontalShake(0,0);
        }
        ++field000c;
        if ((unsigned short)field000c >= frameDuration) {
            field000c = 0;
            ++field000a;
            field0168 = 0;
            if ((field000a == 3) || (field000a == 6)) {
                effect.type = 0;
                effect.palette = 2;
                effect.x = (double)((int(positionX)) + facing * 0x1d);
                effect.y = (double)((int(positionY)) + -0x53);
                effect.group = 2;
                effect.owner = 1;
                effect.layer = 1;
                contextOwner->EmitEffect(&effect);
            }
            if (field000a == 1) {
                (*opponentSlot)->field0008 = 0x67;
                (*opponentSlot)->ResetPose();
                (*opponentSlot)->positionY = -101.0;
                (*opponentSlot)->positionX =
                (double)(facing * 0x15) + positionX;
            }
            if (field000a == 2) {
                (*opponentSlot)->positionY = -99.0;
                (*opponentSlot)->positionX =
                (double)(facing * 0xf) + positionX;
                field02c9 = 0x16;
                effect.type = 0x193;
                effect.x = (double)(int(positionX));
                effect.y = (double)((int(positionY)) + -0xfa);
                effect.group = 2;
                effect.owner = 1;
                effect.flag0018 = (unsigned char)facing;
                effect.layer = 1;
                EmitLocalEffect(&effect);
            }
            if (field000a == 3) {
                (*opponentSlot)->field0008 = 100;
                (*opponentSlot)->positionY = -99.0;
                (*opponentSlot)->positionX =
                (double)(facing * 0xf) + positionX;
            }
            if (field000a == 4) {
                (*opponentSlot)->field0008 = 0x67;
                (*opponentSlot)->positionY = -99.0;
                (*opponentSlot)->positionX =
                (double)(facing * 0xf) + positionX;
            }
            if (field000a == 5) {
                (*opponentSlot)->field0008 = 100;
                (*opponentSlot)->positionY = -99.0;
                (*opponentSlot)->positionX =
                (double)(facing * 0xf) + positionX;
            }
            if (field000a == 6) {
                (*opponentSlot)->field0008 = 0x67;
                (*opponentSlot)->positionY = -99.0;
                (*opponentSlot)->positionX =
                (double)(facing * 0xf) + positionX;
            }
            if ((field000a == 7) && (8 < field3138)) {
                (*opponentSlot)->ResetPose();
                (*opponentSlot)->field0008 = 0x3f;
                (*opponentSlot)->field00c0 = 0.2;
                (*opponentSlot)->field00c8 = -1.9;
                ApplyDamage(1000,1000.0);
                field016c = 1;
            }
            if ((field000a == 7) && (field3138 < 9)) {
                ++field3138;
                field000a = 2;
            }
            if (field000a == 0x10) {
                effect.type = 0x1f;
                effect.x = (double)(int(positionX));
                effect.y = (double)((int(positionY)) + 4);
                effect.group = 0;
                effect.owner = 1;
                effect.flag0018 = (unsigned char)facing;
                effect.layer = 1;
                contextOwner->EmitEffect(&effect);
                effect.type = 0x191;
                effect.x = (double)((int(positionX)) + facing * 0x28);
                effect.y = (double)(int(positionY));
                effect.group = 2;
                effect.flag0018 = (unsigned char)facing;
                effect.owner = 1;
                effect.layer = 1;
                EmitLocalEffect(&effect);
                SetVerticalShake(10,0x3c);
            }
            if (field000a >= frameCount) {
                field0008 = 0;
                ResetPose();
                FaceOpponent();
            }
        }
        break;
    case 312:
        if ((field000a == 0) && ((unsigned short)field000c == 0)) {
            velocityX = 0.0;
            velocityY = 0.0;
            gravity = 0.0;
            field016c = 2;
        }
        if ((field000a == 6) && ((unsigned short)field000c == 0)) {
            SetHorizontalShake(0x32,0x2d);
            field014c = 0x78;
            SetTint(0xb0,3);
            effect.type = 9;
            effect.palette = 5;
            effect.x = (double)((int(positionX)) + facing * 0x17);
            effect.y = (double)((int(positionY)) + -0x1e);
            effect.group = 2;
            effect.owner = 1;
            effect.layer = 1;
            contextOwner->EmitEffect(&effect);
        }
        if ((field000a == 2) && ((unsigned short)field000c == 0)) {
            effect.type = 0x1f;
            effect.x = (double)(int(positionX));
            effect.y = (double)((int(positionY)) + 4);
            effect.group = 0;
            effect.owner = 1;
            effect.flag0018 = (unsigned char)facing;
            effect.layer = 1;
            contextOwner->EmitEffect(&effect);
            effect.type = 0x192;
            effect.x = (double)((int(positionX)) + facing * 0x2d);
            effect.y = (double)(int(positionY));
            effect.group = 2;
            effect.flag0018 = (unsigned char)facing;
            effect.owner = 1;
            effect.layer = 1;
            EmitLocalEffect(&effect);
        }
        if ((field000a == 8) && ((unsigned short)field000c == 0)) {
            effect.type = 0x1f;
            effect.x = (double)(int(positionX));
            effect.y = (double)((int(positionY)) + 4);
            effect.group = 0;
            effect.owner = 1;
            effect.flag0018 = (unsigned char)facing;
            effect.layer = 1;
            contextOwner->EmitEffect(&effect);
            effect.type = 0x191;
            effect.x = (double)((int(positionX)) + facing * 0x28);
            effect.y = (double)(int(positionY));
            effect.group = 2;
            effect.flag0018 = (unsigned char)facing;
            effect.owner = 1;
            effect.layer = 1;
            EmitLocalEffect(&effect);
        }
        if ((field000a == 2) && (field0168 == 3)) {
            SetVerticalShake(6,0x3c);
            (*opponentSlot)->field014a = 500;
        }
        if ((field000a == 10) && ((unsigned short)field000c == 0)) {
            SetVerticalShake(10,0x3c);
        }
        ++field000c;
        if ((unsigned short)field000c >= frameDuration) {
            field000c = 0;
            ++field000a;
            if ((field0168 != 3) && (field000a == 6)) {
                field000a = 0xc;
            }
            if ((field000a == 9) || (field000a == 1)) {
                field0168 = 0;
            }
            if (field000a >= frameCount) {
                field0008 = 0;
                ResetPose();
            }
        }
        break;
    case 313:
        if ((field000a == 0) && ((unsigned short)field000c == 0)) {
            ResetFrame();
            if ((field000a == 1) && ((unsigned short)field000c == 0)) {
                field0148 = field0148 + -3000;
            }
            SetHorizontalShake(0x32,0x2d);
            field014c = 0x78;
            SetTint(0xb0,3);
            effect.type = 9;
            effect.palette = 5;
            effect.x = (double)((int(positionX)) + facing * 0x17);
            effect.y = (double)((int(positionY)) + -0x1e);
            effect.group = 2;
            effect.owner = 1;
            effect.layer = 1;
            contextOwner->EmitEffect(&effect);
        }
        if (field0168 == 6) {
            ResetPose();
            field000a = 2;
            field0168 = 0;
            field014c = 0x78;
            break;
        }
        ++field000c;
        if ((unsigned short)field000c >= frameDuration) {
            field000c = 0;
            ++field000a;
            field0168 = 0;
            if (field000a == 2) {
                field000a = 3;
                break;
            }
            if (field000a == 3) {
                ResetPose();
                field0008 = 0x138;
                break;
            }
            if (field000a >= frameCount) {
                field0008 = 0;
                FaceOpponent();
                ResetPose();
            }
        }
        break;
    case 314:
        field0058 = 0;
        field0158 = 0;
        if ((field000a == 0) && ((unsigned short)field000c == 0)) {
            ResetFrame();
        }
        if ((field000a == 1) && ((unsigned short)field000c == 0)) {
            ResetFrame();
            field014c = 0x78;
            field0148 = field0148 + -3000;
            SetTint(0xb0,3);
            effect.type = 0x46;
            effect.palette = 0x40;
            effect.x = (double)((int(positionX)) - facing * 0x17);
            effect.y = (double)((int(positionY)) + -0x33);
            effect.group = 2;
            effect.layer = 1;
            effect.flag0018 = (unsigned char)facing;
            contextOwner->EmitEffect(&effect);
            effect.type = 0x47;
            contextOwner->EmitEffect(&effect);
            ++field3138;
            field02c9 = 0x25;
            field016c = 1;
        }
        if (field000a > 0) {
            contextOwner->SetSceneTimer(0xf);
        }
        if (field000a > 0) {
            SetHorizontalShake(0x32,3);
        }
        if (field000a > 2 && field000a < 8) {
            velocityY = velocityY + gravity;
            if (field000a == 7 && velocityY + positionY > 0.0) {
                field000c = 0;
                field000a = 9;
                positionY = 0.0;
                ResetFrame();
                break;
            }
        }
        if (((field000a == 0xc) && ((unsigned short)field000c == 0)) &&
            (field0168 == 3)) {
            contextOwner->StartFade(9,0xf,9);
        }
        if (((field000a == 0xd) && ((unsigned short)field000c == 0)) &&
            (field0168 == 3)) {
            ResetPose();
            field0008 = 0x13b;
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
                velocityX = 2.0;
                velocityY = -2.0;
                gravity = 0.08;
            }
            if (field000a >= frameCount) {
                field0008 = 0;
                FaceOpponent();
                ResetPose();
            }
        }
        break;
    case 315:
        field013e = 3;
        if ((*opponentSlot)->field0008 == 99) {
            (*opponentSlot)->field000c = 0;
        }
        if (field000a < 2) {
            SetTint(0xb0,3);
        }
        if (field000a < 2) {
            SetHorizontalShake(0x32,3);
        }
        if (field000a < 2) {
            SetHorizontalOffset(0x32,3);
        }
        if ((field000a == 0) && ((unsigned short)field000c == 0)) {
            positionX = 320.0;
            ResetFrame();
            effect.type = 0x1b2;
            effect.payload = 1;
            effect.x = 0.0;
            effect.y = 0.0;
            effect.group = 0;
            effect.layer = 0;
            effect.flag0018 = 1;
            EmitLocalEffect(&effect);
            effect.type = 0x1a5;
            effect.payload = 0;
            effect.x = 320.0;
            effect.y = 200.0;
            effect.group = 0;
            effect.layer = 1;
            effect.flag0018 = (unsigned char)facing;
            EmitLocalEffect(&effect);
            (*opponentSlot)->positionX = 320.0;
            (*opponentSlot)->positionY = -160.0;
            (*opponentSlot)->ResetPose();
            (*opponentSlot)->ResetFrame();
            (*opponentSlot)->field0008 = 0x3b;
        }
        if (field000a == 0) {
            ++field3138;
            if (field3138 == 0x50) {
                effect.type = 0x1a6;
                effect.x = 320.0;
                effect.y = 200.0;
                effect.group = 0;
                effect.layer = 1;
                effect.flag0018 = (unsigned char)facing;
                EmitLocalEffect(&effect);
            }
            if (field3138 == 0xa0) {
                effect.type = 0x1a7;
                effect.x = 320.0;
                effect.y = 200.0;
                effect.group = 0;
                effect.layer = 1;
                effect.flag0018 = (unsigned char)facing;
                EmitLocalEffect(&effect);
            }
            if (field3138 == 0xf0) {
                effect.type = 0x1a8;
                effect.x = 320.0;
                effect.y = 200.0;
                effect.group = 0;
                effect.layer = 1;
                effect.flag0018 = (unsigned char)facing;
                EmitLocalEffect(&effect);
            }
            if (field3138 == 0x140) {
                effect.type = 0x1a9;
                effect.x = 320.0;
                effect.y = 200.0;
                effect.group = 0;
                effect.layer = 1;
                effect.flag0018 = (unsigned char)facing;
                EmitLocalEffect(&effect);
            }
            if (field3138 == 400) {
                effect.type = 0x1aa;
                effect.x = 320.0;
                effect.y = 200.0;
                effect.group = 0;
                effect.layer = 1;
                effect.flag0018 = (unsigned char)facing;
                EmitLocalEffect(&effect);
            }
        }
        if ((field000a == 0) && ((unsigned short)field000c == frameDuration - 0x1e)
            ) {
            contextOwner->StartReverseFade(9,0x1e,9);
            field3138 = 0;
            (*opponentSlot)->positionX = 320.0;
            (*opponentSlot)->positionY = 0.0;
            (*opponentSlot)->field0008 = 0x79;
            (*opponentSlot)->ResetPose();
            (*opponentSlot)->ResetFrame();
        }
        if (field000a == 1) {
            ++field3138;
            if (0 < field313c) {
                field000a = 2;
                field000c = 0;
                facing = -(*opponentSlot)->facing;
                positionX = (double)field313c;
                positionY = (double)field3140;
                velocityX = -0.9;
                velocityY = -1.5;
            }
            if (field3138 == 0x96) {
                effect.type = 0x1b6;
                effect.x = positionX - (double)(facing * 0xf0);
                effect.y = -20.0;
                effect.group = 0;
                effect.layer = 1;
                effect.flag0018 = (unsigned char)facing;
                EmitLocalEffect(&effect);
            }
            if (field3138 == 0xae) {
                effect.type = 0x1ac;
                effect.x = positionX - (double)(facing * 0xf0);
                effect.y = -20.0;
                effect.group = 0;
                effect.layer = 1;
                effect.flag0018 = (unsigned char)facing;
                EmitLocalEffect(&effect);
            }
            if (field3138 == 0xc6) {
                effect.type = 0x1ad;
                effect.x = positionX - (double)(facing * 0xf0);
                effect.y = -20.0;
                effect.group = 0;
                effect.layer = 1;
                effect.flag0018 = (unsigned char)facing;
                EmitLocalEffect(&effect);
            }
            if (field3138 == 0xde) {
                effect.type = 0x1ae;
                effect.x = positionX - (double)(facing * 0xf0);
                effect.y = -20.0;
                effect.group = 0;
                effect.layer = 1;
                effect.flag0018 = (unsigned char)facing;
                EmitLocalEffect(&effect);
            }
            if (field3138 == 0xf6) {
                effect.type = 0x1af;
                effect.x = positionX - (double)(facing * 0xf0);
                effect.y = -20.0;
                effect.group = 0;
                effect.layer = 1;
                effect.flag0018 = (unsigned char)facing;
                EmitLocalEffect(&effect);
            }
            if (field3138 == 0x10e) {
                effect.type = 0x1b0;
                effect.x = positionX - (double)(facing * 0xf0);
                effect.y = -20.0;
                effect.group = 0;
                effect.layer = 1;
                effect.flag0018 = (unsigned char)facing;
                EmitLocalEffect(&effect);
            }
        }
        if (field000a > 1) {
            velocityY = velocityY + 0.035;
            if (velocityY + positionY > 0.0) {
                ResetPose();
                ResetFrame();
                field0008 = 0xd;
                positionY = 0.0;
                break;
            }
        }
        ++field000c;
        if ((unsigned short)field000c >= frameDuration) {
            field000c = 0;
            ++field000a;
            field0168 = 0;
            if (field000a >= frameCount) {
                field000a = field000a + -2;
            }
        }
        break;
    case 316:
        field0058 = 0;
        field0158 = 0;
        if ((field000a == 0) && ((unsigned short)field000c == 0)) {
            ResetFrame();
        }
        if (((field000a == 4) && ((unsigned short)field000c == 0)) &&
            (field3138 == 0)) {
            ResetFrame();
            field014c = 0x78;
            field0148 = field0148 + -3000;
            SetTint(0xb0,3);
            effect.type = 0x46;
            effect.palette = 0x40;
            effect.x = (double)((int(positionX)) - facing * 0xe);
            effect.y = (double)((int(positionY)) + -0x32);
            effect.group = 2;
            effect.layer = 1;
            effect.flag0018 = (unsigned char)facing;
            contextOwner->EmitEffect(&effect);
            effect.type = 0x47;
            contextOwner->EmitEffect(&effect);
            ++field3138;
            field02c9 = 0x25;
        }
        if (3 < field000a) {
            contextOwner->SetSceneTimer(0xf);
        }
        SetHorizontalShake(0x32,3);
        if ((field000a == 9) && ((unsigned short)field000c == 0)) {
            effect.owner = 1;
            effect.type = 0x1c4;
            effect.x = (double)((int(positionX)) + facing * 0x50);
            effect.y = 15.0;
            effect.flag0018 = (unsigned char)facing;
            effect.group = 2;
            effect.layer = 1;
            EmitLocalEffect(&effect);
        }
        ++field000c;
        if ((unsigned short)field000c >= frameDuration) {
            field000c = 0;
            ++field000a;
            field0168 = 0;
            if ((field000a == 7) && (field3138 < 6)) {
                field000a = field000a + -3;
                ++field3138;
            }
            if (field000a >= frameCount) {
                field0008 = 0;
                FaceOpponent();
                ResetPose();
            }
        }
        break;
    }
}
