// Misuzu complete animation and state update dispatch.
#include "CharacterViews.h"
void Character23::Slot06()
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
        velocityX = 0.8;
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
        if ((field000a == 2) && ((unsigned short)field000c == 0)) {
            gravity = 0.048;
            velocityY = -3.0;
        }
        if (1 < field000a) {
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
            (2 < field000a)) {
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
        if ((field000a == 2) && ((unsigned short)field000c == 0)) {
            gravity = 0.048;
            velocityY = -3.0;
            velocityX = 0.9;
        }
        if (1 < field000a) {
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
            (2 < field000a)) {
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
        if ((field000a == 2) && ((unsigned short)field000c == 0)) {
            gravity = 0.048;
            velocityY = -3.0;
            velocityX = -0.9;
        }
        if (1 < field000a) {
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
            (2 < field000a)) {
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
            ResetFrame();
            pendingContextSoundSlot = 9;
            field0008 = 0xd;
            ResetPose();
        }
        break;
    case 13:
        ResetFrame();
        positionY = 0.0;
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
        gravity = 0.048;
        if ((field000a == 0) && ((unsigned short)field000c == 0)) {
            velocityY = -3.0;
            velocityX = 0.0;
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
            pendingContextSoundSlot = 9;
            FaceOpponent();
            field0008 = 0xd;
            ResetPose();
        }
        break;
    case 15:
        gravity = 0.048;
        if ((field000a == 0) && ((unsigned short)field000c == 0)) {
            velocityY = -3.0;
            velocityX = 0.9;
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
            pendingContextSoundSlot = 9;
            FaceOpponent();
            field0008 = 0xd;
            ResetPose();
        }
        break;
    case 16:
        gravity = 0.048;
        if ((field000a == 0) && ((unsigned short)field000c == 0)) {
            velocityY = -3.0;
            velocityX = -0.9;
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
            pendingContextSoundSlot = 9;
            FaceOpponent();
            field0008 = 0xd;
            ResetPose();
        }
        break;
    case 47:
        if ((field000a == 0) && ((unsigned short)field000c == 0)) {
            velocityX = 0.3;
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
            (2.0 - (*opponentSlot)->comboDamageScale / 10000.0) *
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
        if (field0120 != '\0') {
            field0118 = field0118 - 0.6;
        }
        if ((field000a == 0) && ((unsigned short)field000c == 0)) {
            meter = meter + 0xf;
            velocityX =
            (2.0 - (*opponentSlot)->comboDamageScale / 10000.0) *
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
        if (field0120 != '\0') {
            field0118 = field0118 - 0.6;
        }
        if ((field000a == 0) && ((unsigned short)field000c == 0)) {
            meter = meter + 0x14;
            velocityX =
            (2.0 - (*opponentSlot)->comboDamageScale / 10000.0) *
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
        if (field0120 != '\0') {
            field0118 = field0118 - 0.6;
        }
        if ((field000a == 0) && ((unsigned short)field000c == 0)) {
            meter = meter + 10;
            velocityX =
            (2.0 - (*opponentSlot)->comboDamageScale / 10000.0) *
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
        if (field0120 != '\0') {
            field0118 = field0118 - 0.6;
        }
        if ((field000a == 0) && ((unsigned short)field000c == 0)) {
            meter = meter + 0xf;
            velocityX =
            (2.0 - (*opponentSlot)->comboDamageScale / 10000.0) *
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
        if (field0120 != '\0') {
            field0118 = field0118 - 0.6;
        }
        if ((field000a == 0) && ((unsigned short)field000c == 0)) {
            meter = meter + 0x14;
            velocityX =
            (2.0 - (*opponentSlot)->comboDamageScale / 10000.0) *
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
        if (field0120 != '\0') {
            field0118 = field0118 - 0.6;
        }
        if ((field000a == 0) && ((unsigned short)field000c == 0)) {
            meter = meter + 10;
            velocityX =
            (2.0 - (*opponentSlot)->comboDamageScale / 10000.0) *
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
        if (field0120 != '\0') {
            field0118 = field0118 - 0.6;
        }
        if ((field000a == 0) && ((unsigned short)field000c == 0)) {
            meter = meter + 0xf;
            velocityX =
            (2.0 - (*opponentSlot)->comboDamageScale / 10000.0) *
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
        if (field0120 != '\0') {
            field0118 = field0118 - 0.6;
        }
        if ((field000a == 0) && ((unsigned short)field000c == 0)) {
            meter = meter + 0x14;
            velocityX =
            (2.0 - (*opponentSlot)->comboDamageScale / 10000.0) *
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
        if (field0120 != '\0') {
            field0118 = field0118 - 0.8;
        }
        if ((field000a == 0) && ((unsigned short)field000c == 0)) {
            meter = meter + 0x1e;
            velocityX = knockbackVelocityX;
            velocityY =
            velocityY * 0.75 + knockbackVelocityY;
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
            if (knockdownOnLanding != 0) {
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
            velocityY =
            velocityY * 0.75 + knockbackVelocityY;
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
            if (knockdownOnLanding != 0) {
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
            velocityY =
            velocityY * 0.75 + knockbackVelocityY;
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
            if (knockdownOnLanding != 0) {
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
            velocityY =
            velocityY * 0.75 + knockbackVelocityY;
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
            if (knockdownOnLanding != 0) {
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
            if (knockdownOnLanding != 0) {
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
            velocityY =
            velocityY * 0.75 + knockbackVelocityY;
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
            if (knockdownOnLanding != 0) {
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
            velocityY =
            velocityY * 0.75 + knockbackVelocityY;
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
            if (knockdownOnLanding != 0) {
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
            velocityY =
            velocityY * 0.75 + knockbackVelocityY;
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
            if (knockdownOnLanding != 0) {
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
            if (knockdownOnLanding != 0) {
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
            if (knockdownOnLanding != 0) {
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
            if (knockdownOnLanding != 0) {
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
        if (((field000a == 0) && ((unsigned short)field000c == 0)) &&
            (field3138 == 0)) {
            meter = meter + 0x1e;
            ++field3138;
            airActionLockFrames = airActionLockFrames + 0x78;
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
            if (knockdownOnLanding != 0) {
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
            if (knockdownOnLanding != 0) {
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
        if (field0120 != '\0') {
            field0118 = field0118 - 0.8;
        }
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
        if (field0120 != '\0') {
            field0118 = field0118 - 0.8;
        }
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
            if (knockdownOnLanding != 0) {
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
        if (((field000a == 0) && ((unsigned short)field000c == 0)) &&
            (field3138 == 0)) {
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
            if (knockdownOnLanding != 0) {
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
            if (knockdownOnLanding != 0) {
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
            if (knockdownOnLanding != 0) {
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
            if (field000a == frameCount - 1) {
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
        if (((0 < health) && (99 < (unsigned short)field000c)) &&
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
    case 103:
        break;
    case 107:
        break;
    case 113:
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
            effect.y = (double)((int(positionY)) + -0x46);
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
        if ((field000a == 2) && ((unsigned short)field000c == 0)) {
            velocityY = -1.5;
            gravity = 0.025;
            remainingHitCount = 1;
        }
        if ((field000a == 7) && ((unsigned short)field000c == 0)) {
            ResetFrame();
            effect.type = 9;
            effect.x = (double)(int(positionX));
            effect.y = (double)((int(positionY)) + -0x46);
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
            if (field000a == 0xf) {
                gravity = 0.035;
            }
            if (field000a >= frameCount) {
                field000a = field000a + -2;
            }
        }
        break;
    case 163:
        if ((field000a == 0) && ((unsigned short)field000c == 0)) {
            StartTrail(3);
        }
        if ((field000a == 0) && ((unsigned short)field000c == 0)) {
            velocityX = 0.0;
            velocityY = 0.0;
            gravity = 0.0;
        }
        if (((field000a == 3) && ((unsigned short)field000c == 0)) &&
            (positionY >= 0.0)) {
            effect.type = 0x1f;
            effect.x = (double)(int(positionX));
            effect.y = (double)(int(positionY));
            effect.group = 0;
            effect.layer = 0;
            effect.facing = (facing == -1);
            contextOwner->EmitEffect(&effect);
            velocityX = 1.8;
            velocityY = -1.2;
            gravity = 0.01;
            pendingContextSoundSlot = 0x11;
        }
        velocityY = velocityY + gravity;
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
            velocityX = 0.5;
            gravity = 0.03;
        }
        if ((inputX != facing) && (field3138 >= 39)) {
            field0008 = 9;
            ResetPose();
            velocityX = 0.5;
            gravity = 0.03;
        }
        break;
    case 164:
        if ((field000a == 0) && ((unsigned short)field000c == 0)) {
            velocityX = 0.0;
            velocityY = 0.0;
            gravity = 0.0;
            StartTrail(2);
        }
        if (((field000a == 3) && ((unsigned short)field000c == 0)) &&
            (positionY == 0.0)) {
            velocityX = -1.8;
            velocityY = -1.3;
            gravity = 0.01;
            pendingContextSoundSlot = 0x11;
            effect.type = 0x1f;
            effect.x = (double)(int(positionX));
            effect.y = (double)(int(positionY));
            effect.group = 0;
            effect.layer = 0;
            effect.facing = (facing == '\x01');
            contextOwner->EmitEffect(&effect);
        }
        velocityY = velocityY + gravity;
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
        if ((int)inputX != -(int)facing) {
            field3138 = 0;
        }
        if (((0x27 < field313c) && ((int)inputX != -(int)facing)) ||
            (field313c >= 120)) {
            field0008 = 9;
            ResetPose();
            velocityX = -0.5;
            gravity = 0.03;
        }
        break;
    case 165:
        if (((field000a == 0) && ((unsigned short)field000c == 0)) &&
            (field3140 == 0)) {
            velocityX = 1.8;
            velocityY = -0.3;
            pendingContextSoundSlot = 0x11;
            ++field3140;
        }
        velocityY = velocityY + 0.01;
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
        if (((field000a == 0) && ((unsigned short)field000c == 0)) &&
            (field3140 == 0)) {
            velocityX = -1.8;
            velocityY = -0.3;
            pendingContextSoundSlot = 0x11;
            ++field3140;
        }
        velocityY = velocityY + 0.01;
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
                comboDamageScale =
                field0118 * 5.0 + comboDamageScale;
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
            attackCollisionResult = 0;
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
            if (gravity == 0.0) {
                gravity = 0.035;
            }
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
            if (field0120 == '\x01') {
                comboDamageScale =
                field0118 * 5.0 + comboDamageScale;
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
            attackCollisionResult = 0;
            if (field000a >= frameCount) {
                field0008 = 9;
                velocityX = (double)field3138 * 0.01;
                velocityY = (double)field313c * 0.01;
                gravity = 0.035;
                ResetPose();
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
            (field000a < 5)) {
            ResetFrame();
            positionY = 0.0;
            field000c = 0;
            field000a = 5;
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
            if (field000a == 5) {
                field000a = field000a + -2;
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
            (field015c < 3)) && (attackCollisionResult >= 2)) {
            field0008 = 4;
            if (inputX == facing) {
                field0008 = 5;
            }
            if ((int)inputX == -(int)facing) {
                field0008 = 6;
            }
            attackCollisionResult = 0;
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
                attackCollisionResult = 0;
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
            (field015c < 3)) && (attackCollisionResult >= 2)) {
            field0008 = 4;
            if (inputX == facing) {
                field0008 = 5;
            }
            if ((int)inputX == -(int)facing) {
                field0008 = 6;
            }
            attackCollisionResult = 0;
            ResetPose();
            break;
        }
        if ((field000a == 0) && ((unsigned short)field000c == 0)) {
            velocityX = 0.0;
            velocityY = 0.0;
        }
        if ((field000a == 1) && ((unsigned short)field000c == 0)) {
            velocityX = 0.5;
        }
        if ((field000a == 2) && ((unsigned short)field000c == 0)) {
            meter = meter + 0xf;
            pendingContextSoundSlot = 0x14;
            remainingHitCount = 1;
        }
        if ((1 < field000a) &&
            (velocityX = velocityX - 0.02,
            velocityX < 0.0)) {
            velocityX = 0.0;
        }
        ++field000c;
        if ((unsigned short)field000c >= frameDuration) {
            field000c = 0;
            ++field000a;
            if (field000a < 4) {
                attackCollisionResult = 0;
            }
            if (field000a >= frameCount) {
                field0008 = 0;
                FaceOpponent();
                ResetPose();
            }
        }
        break;
    case 202:
        if ((((inputY == -1) && (field000a > 0)) &&
            (field015c < 3)) && (attackCollisionResult == 3)) {
            field0008 = 4;
            if (inputX == facing) {
                field0008 = 5;
            }
            if ((int)inputX == -(int)facing) {
                field0008 = 6;
            }
            attackCollisionResult = 0;
            ResetPose();
            break;
        }
        if ((field000a == 0) && ((unsigned short)field000c == 0)) {
            velocityX = 0.0;
            velocityY = 0.0;
        }
        if ((field000a == 1) && ((unsigned short)field000c == 0)) {
            meter = meter + 0xf;
            pendingContextSoundSlot = 0x14;
            remainingHitCount = 1;
        }
        ++field000c;
        if ((unsigned short)field000c >= frameDuration) {
            field000c = 0;
            ++field000a;
            if (field000a < 4) {
                attackCollisionResult = 0;
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
        }
        if ((field000a == 4) && ((unsigned short)field000c == 0)) {
            meter = meter + 0x23;
            pendingContextSoundSlot = 0x14;
            remainingHitCount = 1;
        }
        ++field000c;
        if ((unsigned short)field000c >= frameDuration) {
            field000c = 0;
            ++field000a;
            if (field000a < 2) {
                attackCollisionResult = 0;
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
        if (((inputY == -1) && (field000a > 0)) &&
            ((field015c < 3 && (attackCollisionResult >= 2)))) {
            field0008 = 4;
            if (inputX == facing) {
                field0008 = 5;
            }
            if ((int)inputX == -(int)facing) {
                field0008 = 6;
            }
            attackCollisionResult = 0;
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
                attackCollisionResult = 0;
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
        velocityX = 0.0;
        velocityY = 0.0;
        if ((((inputY == -1) && (field000a > 0)) &&
            (field015c < 3)) && (attackCollisionResult == 3)) {
            field0008 = 4;
            if (inputX == facing) {
                field0008 = 5;
            }
            if ((int)inputX == -(int)facing) {
                field0008 = 6;
            }
            attackCollisionResult = 0;
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
                attackCollisionResult = 0;
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
        velocityX = 0.0;
        velocityY = 0.0;
        if ((field000a == 3) && ((unsigned short)field000c == 0)) {
            meter = meter + 0x19;
            pendingContextSoundSlot = 0x14;
            remainingHitCount = 1;
        }
        ++field000c;
        if ((unsigned short)field000c >= frameDuration) {
            field000c = 0;
            ++field000a;
            if (field000a == 3) {
                effect.type = 0;
                effect.x = (double)((int(positionX)) + facing * 0x25);
                effect.y = (double)((int(positionY)) + -2);
                effect.group = 2;
                pendingCharacterSoundSlot = 3;
                effect.layer = 1;
                contextOwner->EmitEffect(&effect);
            }
            if (field000a < 2) {
                attackCollisionResult = 0;
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
        if (((inputY == -1) && (field000a > 0)) &&
            ((field015c < 3 && ((attackCollisionResult >= 2 && (airActionCount == '\0')))))
            ) {
            field0008 = 0xe;
            ++airActionCount;
            if (inputX == facing) {
                field0008 = 0xf;
            }
            if ((int)inputX == -(int)facing) {
                field0008 = 0x10;
            }
            attackCollisionResult = 0;
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
                attackCollisionResult = 0;
            }
            if (field000a >= frameCount) {
                field0008 = 9;
                ResetPose();
            }
        }
        break;
    case 208:
        velocityY = velocityY + gravity;
        if ((((inputY == -1) && (field000a > 0)) &&
            (field015c < 3)) && ((attackCollisionResult >= 2 && (airActionCount == '\0')))
            ) {
            ++airActionCount;
            field0008 = 0xe;
            if (inputX == facing) {
                field0008 = 0xf;
            }
            if ((int)inputX == -(int)facing) {
                field0008 = 0x10;
            }
            attackCollisionResult = 0;
            ResetPose();
            break;
        }
        if ((field000a == 2) && ((unsigned short)field000c == 0)) {
            meter = meter + 0xd;
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
            if (field000a < 5) {
                attackCollisionResult = 0;
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
            (field015c < 3)) && ((attackCollisionResult >= 2 && (airActionCount == '\0')))
            ) {
            ++airActionCount;
            field0008 = 0xe;
            if (inputX == facing) {
                field0008 = 0xf;
            }
            if ((int)inputX == -(int)facing) {
                field0008 = 0x10;
            }
            attackCollisionResult = 0;
            ResetPose();
            break;
        }
        if ((field000a == 3) && ((unsigned short)field000c == 0)) {
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
            if (field000a < 8) {
                attackCollisionResult = 0;
            }
            if ((field000a == 7) && (field3138 < 1)) {
                field000a = field000a + -3;
                ++field3138;
            }
            if (field000a >= frameCount) {
                field0008 = 9;
                ResetPose();
            }
        }
        break;
    case 210:
        if ((field000a == 0) && ((unsigned short)field000c == 0)) {
            velocityX = 0.0;
            velocityY = 0.0;
        }
        if ((field000a == 1) && ((unsigned short)field000c == 0)) {
            velocityX = 1.4;
            velocityY = -1.5;
            gravity = 0.08;
        }
        if ((field000a == 2) && ((unsigned short)field000c == 0)) {
            meter = meter + 0xf;
            pendingContextSoundSlot = 0x14;
            remainingHitCount = 1;
        }
        if ((field000a == 5) && ((unsigned short)field000c == 0)) {
            velocityX = 0.0;
            velocityY = 0.0;
            gravity = 0.0;
        }
        if (field000a > 0) {
            velocityY = velocityY + gravity;
        }
        ++field000c;
        if ((unsigned short)field000c >= frameDuration) {
            field000c = 0;
            ++field000a;
            if (field000a < 6) {
                attackCollisionResult = 0;
            }
            if (field000a == 5) {
                if (positionY + velocityY < 0.0) {
                    --field000a;
                } else {
                    positionY = 0.0;
                }
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
            velocityX = 0.0;
            velocityY = 0.0;
        }
        if ((field000a == 8) && ((unsigned short)field000c == 0)) {
            meter = meter + 0x23;
            pendingContextSoundSlot = 0x14;
            remainingHitCount = 1;
        }
        if (positionY < 0.0) {
            velocityY = velocityY + 0.055;
            if (positionY + velocityY > 0.0) {
                ResetFrame();
                positionY = 0.0;
                field000c = 0;
                field000a = 8;
                break;
            }
        }
        ++field000c;
        if ((unsigned short)field000c >= frameDuration) {
            field000c = 0;
            ++field000a;
            if (field000a == 7) {
                velocityX = 0.5;
                velocityY = -1.2;
            }
            if (field000a < 5) {
                attackCollisionResult = 0;
            }
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
            meter = meter + 0x1e;
            pendingContextSoundSlot = 0x14;
            remainingHitCount = 1;
            velocityX = velocityX / 2.0;
            gravity = 0.07;
        }
        if (attackCollisionResult > 1) {
            field0008 = 0xd5;
            ResetPose();
            ResetFrame();
            break;
        }
        if (positionY + velocityY >= 0.0) {
            positionY = 0.0;
            ResetFrame();
            velocityY = 0.0;
            SetVerticalShake(3,0);
            effect.type = 3;
            effect.x = (double)(int(positionX));
            effect.y = (double)(int(positionY));
            effect.group = 2;
            effect.layer = 0;
            effect.palette = 7;
            contextOwner->EmitEffect(&effect);
            pendingContextSoundSlot = 7;
            field0008 = 0xd6;
            ResetPose();
            break;
        }
        ++field000c;
        if ((unsigned short)field000c >= frameDuration) {
            field000c = 0;
            ++field000a;
            attackCollisionResult = 0;
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
            attackCollisionResult = 0;
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
            attackCollisionResult = 0;
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
        if (((field000a == 1) && ((unsigned short)field000c == 0)) &&
            ((*opponentSlot)->positionY == 0.0)) {
            remainingHitCount = 1;
        }
        else {
            remainingHitCount = 0;
        }
        if ((field000a == 1) && (attackCollisionResult == 3)) {
            velocityX = 0.0;
            velocityY = 0.0;
            outgoingPushbackVelocityX = 0.0;
            ResetPose();
            (*opponentSlot)->ResetPose();
            (*opponentSlot)->ResetFrame();
            field0008 = 0xdd;
            (*opponentSlot)->field0008 = 0x6e;
            (*opponentSlot)->airActionDisabled = 1;
            effect.type = 0;
            effect.x = (double)((int(positionX)) + facing * 0x24);
            effect.y = (double)((int(positionY)) + -0x2c);
            effect.group = 2;
            effect.layer = 1;
            contextOwner->EmitEffect(&effect);
        }
        ++field000c;
        if ((unsigned short)field000c >= frameDuration) {
            field000c = 0;
            ++field000a;
            attackCollisionResult = 0;
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
    case 221:
        SetHorizontalShake(0x32,10);
        if ((field000a == 0) && ((unsigned short)field000c == 0)) {
            (*opponentSlot)->field0008 = 100;
            (*opponentSlot)->ResetFrame();
            (*opponentSlot)->positionY = 0.0;
            (*opponentSlot)->positionX =
            (double)(facing * 0x2a) + positionX;
            (*opponentSlot)->ResetPose();
        }
        if ((field000a == 5) && ((unsigned short)field000c == 0)) {
            (*opponentSlot)->ResetPose();
            (*opponentSlot)->field0008 = 0x3b;
            (*opponentSlot)->knockbackVelocityX = 2.0;
            (*opponentSlot)->knockbackVelocityY = -1.0;
            (*opponentSlot)->gravity = 0.035;
            (*opponentSlot)->positionY = -59.0;
            (*opponentSlot)->positionX =
            (double)(facing * 0xf) + positionX;
            (*opponentSlot)->airActionDisabled = 1;
            ApplyDamage(0x4b0,750.0);
            --comboHitCount;
            --comboDisplayHitCount;
            (*opponentSlot)->facing = -facing;
        }
        ++field000c;
        if ((unsigned short)field000c >= frameDuration) {
            field000c = 0;
            ++field000a;
            attackCollisionResult = 0;
            if (field000a == 1) {
                (*opponentSlot)->field0008 = 0x6c;
                (*opponentSlot)->positionY = 0.0;
                (*opponentSlot)->positionX =
                (double)(facing * 0x24) + positionX;
            }
            if (field000a == 2) {
                (*opponentSlot)->field0008 = 0x6c;
                (*opponentSlot)->positionY = 0.0;
                (*opponentSlot)->positionX =
                (double)(facing * 0x23) + positionX;
            }
            if (field000a == 3) {
                (*opponentSlot)->positionY = 0.0;
                (*opponentSlot)->positionX =
                (double)(facing * 0x22) + positionX;
            }
            if (field000a == 4) {
                (*opponentSlot)->field0008 = 0x68;
                (*opponentSlot)->positionY = -32.0;
                (*opponentSlot)->positionX =
                positionX - (double)((int)facing << 1);
                (*opponentSlot)->facing = facing;
            }
            if (field000a >= frameCount) {
                field0008 = 0;
                FaceOpponent();
                ResetPose();
            }
        }
        break;
    case 230:
        velocityY = velocityY + gravity;
        if ((field000a == 0) && ((unsigned short)field000c == 0)) {
            velocityX = 0.5;
            gravity = 0.03;
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
            attackCollisionResult = 0;
            if (field000a >= frameCount) {
                field0008 = 9;
                ResetPose();
            }
        }
        break;
    case 231:
        velocityY = velocityY + gravity;
        if ((field000a == 0) && ((unsigned short)field000c == 0)) {
            velocityX = 0.5;
            gravity = 0.03;
        }
        if ((field000a == 2) && ((unsigned short)field000c == 0)) {
            meter = meter + 10;
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
            attackCollisionResult = 0;
            if (field000a >= frameCount) {
                field0008 = 9;
                ResetPose();
            }
        }
        break;
    case 232:
        velocityY = velocityY + gravity;
        if ((field000a == 0) && ((unsigned short)field000c == 0)) {
            velocityX = 0.5;
            gravity = 0.03;
        }
        if ((field000a == 1) && ((unsigned short)field000c == 0)) {
            meter = meter + 10;
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
            attackCollisionResult = 0;
            if (field000a >= frameCount) {
                field0008 = 9;
                ResetPose();
            }
        }
        break;
    case 248:
        velocityY = velocityY + gravity;
        if ((field000a == 1) && (attackCollisionResult == 3)) {
            (*opponentSlot)->ResetFrame();
            (*opponentSlot)->ResetPose();
            ResetPose();
            ResetFrame();
            field0008 = 0xf9;
            (*opponentSlot)->field0008 = 100;
            effect.type = 0;
            effect.x = (double)((int(positionX)) + facing * 0x1f);
            effect.y = (double)((int(positionY)) + -0x40);
            effect.group = 2;
            effect.layer = 1;
            contextOwner->EmitEffect(&effect);
            (*opponentSlot)->positionX =
            (double)(facing * 0x1f) + positionX;
            (*opponentSlot)->positionY = positionY - 64.0;
        }
        ++field000c;
        if ((unsigned short)field000c >= frameDuration) {
            field000c = 0;
            ++field000a;
            if (field000a == 1 && (*opponentSlot)->positionY < 0.0 &&
                ((*opponentSlot)->field0008 < 50 || (*opponentSlot)->field0008 > 149)) {
                remainingHitCount = 1;
            } else { remainingHitCount = 0; }
            attackCollisionResult = 0;
            if (field000a >= frameCount) {
                field0008 = 0xd1;
                field000a = 2;
            }
        }
        break;
    case 249:
        if (field000a < 4) {
            SetHorizontalOffset(0x32,3);
        }
        if (field000a < 4) {
            SetHorizontalShake(0x32,3);
        }
        if ((field000a == 0) && ((unsigned short)field000c == 1)) {
            (*opponentSlot)->facing = -facing;
        }
        velocityY = velocityY + gravity;
        if (velocityY + positionY > 0.0 && field000a > 5) {
            ResetFrame();
            positionY = 0.0;
            ResetPose();
            field0008 = 0xd;
            break;
        }
        if (field000a == 1) {
            (*opponentSlot)->positionY = positionY - 64.0;
            (*opponentSlot)->positionX =
            (double)(facing * 0x1e) + positionX;
        }
        if (field000a == 2) {
            (*opponentSlot)->positionY = positionY - 64.0;
            (*opponentSlot)->positionX =
            (double)(facing * 0x1d) + positionX;
        }
        if (field000a == 3) {
            (*opponentSlot)->positionY = positionY - 96.0;
            (*opponentSlot)->positionX =
            (double)(facing * 0xb) + positionX;
            (*opponentSlot)->field0008 = 0x68;
            (*opponentSlot)->facing = facing;
        }
        if ((field000a == 4) && ((unsigned short)field000c == 0)) {
            (*opponentSlot)->positionY = positionY - 39.0;
            (*opponentSlot)->positionX =
            positionX - (double)(facing * 0x21);
            (*opponentSlot)->field0008 = 0x3f;
            ApplyDamage(0x4b0,500.0);
            (*opponentSlot)->ResetPose();
            (*opponentSlot)->knockbackVelocityX = -2.0;
            (*opponentSlot)->knockbackVelocityY = 0.0;
        }
        if ((field000a == 7) && ((unsigned short)field000c == 0)) {
            gravity = 0.035;
        }
        ++field000c;
        if ((unsigned short)field000c >= frameDuration) {
            field000c = 0;
            ++field000a;
            attackCollisionResult = 0;
            if (field000a == 8) {
                facing = -facing;
            }
            if (field000a >= frameCount) {
                field000a = field000a + -2;
            }
        }
        break;
    case 250:
        if ((field000a == 0) && ((unsigned short)field000c == 0)) {
            ResetFrame();
        }
        if ((field000a == 3) && ((unsigned short)field000c == 0)) {
            meter = meter + 0xf;
            effect.type = 0x193;
            effect.x = positionX;
            effect.y = positionY - 80.0;
            effect.flag0018 = (unsigned char)facing;
            effect.owner = 1;
            effect.layer = 1;
            pendingCharacterSoundSlot = 1;
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
    case 251:
        if ((field000a == 0) && ((unsigned short)field000c == 0)) {
            ResetFrame();
        }
        if ((field000a == 3) && ((unsigned short)field000c == 0)) {
            meter = meter + 0xf;
            effect.type = 0x194;
            effect.x = positionX;
            effect.y = positionY - 80.0;
            effect.owner = 1;
            effect.flag0018 = (unsigned char)facing;
            effect.layer = 1;
            pendingCharacterSoundSlot = 1;
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
    case 252:
        if ((field000a == 0) && ((unsigned short)field000c == 0)) {
            if (positionY == 0.0) {
                ResetFrame();
            }
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
        if ((field000a == 0) && ((unsigned short)field000c == 0)) {
            ResetFrame();
        }
        if ((field000a == 3) && ((unsigned short)field000c == 0)) {
            meter = meter + 0xf;
            effect.type = 0x195;
            effect.x = positionX;
            effect.y = positionY - 80.0;
            effect.flag0018 = (unsigned char)facing;
            effect.owner = 1;
            effect.layer = 1;
            pendingCharacterSoundSlot = 1;
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
    case 253:
        if ((field000a == 0) && ((unsigned short)field000c == 0)) {
            ResetFrame();
        }
        ++field000c;
        if ((unsigned short)field000c >= frameDuration) {
            field000c = 0;
            ++field000a;
            if ((field000a == 5) && (field3138 < 3)) {
                field000a = field000a + -2;
                ++field3138;
                if (field3138 == 1) {
                    meter = meter + 0xf;
                    effect.type = 0x196;
                    effect.x = (double)(facing * 0x1e) + positionX;
                    effect.y = positionY;
                    effect.flag0018 = (unsigned char)facing;
                    effect.owner = 1;
                    effect.layer = 1;
                    EmitLocalEffect(&effect);
                }
            }
            if (field000a >= frameCount) {
                field0008 = 0;
                ResetPose();
            }
        }
        break;
    case 254:
        if ((field000a == 0) && ((unsigned short)field000c == 0)) {
            ResetFrame();
        }
        ++field000c;
        if ((unsigned short)field000c >= frameDuration) {
            field000c = 0;
            ++field000a;
            if ((field000a == 5) && (field3138 < 3)) {
                field000a = field000a + -2;
                ++field3138;
                if (field3138 == 1) {
                    meter = meter + 0xf;
                    effect.type = 0x197;
                    effect.x = (double)(facing * 0x1e) + positionX;
                    effect.y = positionY;
                    effect.flag0018 = (unsigned char)facing;
                    effect.owner = 1;
                    effect.layer = 1;
                    EmitLocalEffect(&effect);
                }
            }
            if (field000a >= frameCount) {
                field0008 = 0;
                ResetPose();
            }
        }
        break;
    case 255:
        if ((field000a == 0) && ((unsigned short)field000c == 0)) {
            if (positionY == 0.0) {
                ResetFrame();
            }
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
        ++field000c;
        if ((unsigned short)field000c >= frameDuration) {
            field000c = 0;
            ++field000a;
            if ((field000a == 5) && (field3138 < 3)) {
                field000a = field000a + -2;
                ++field3138;
                if (field3138 == 1) {
                    meter = meter + 0xf;
                    effect.type = 0x198;
                    effect.x = (double)(facing * 0x1e) + positionX;
                    effect.y = positionY;
                    effect.flag0018 = (unsigned char)facing;
                    effect.owner = 1;
                    effect.layer = 1;
                    EmitLocalEffect(&effect);
                }
            }
            if (field000a >= frameCount) {
                field0008 = 0;
                ResetPose();
            }
        }
        break;
    case 256:
        if ((field000a == 0) && ((unsigned short)field000c == 0)) {
            ResetFrame();
        }
        if ((field000a == 5) && ((unsigned short)field000c == 0)) {
            meter = meter + 0xf;
        }
        ++field000c;
        if ((unsigned short)field000c >= frameDuration) {
            field000c = 0;
            ++field000a;
            attackCollisionResult = 3;
            if (field000a >= frameCount) {
                field0008 = 0;
                ResetPose();
            }
        }
        break;
    case 257:
        if ((field000a == 0) && ((unsigned short)field000c == 0)) {
            ResetFrame();
        }
        if ((field000a == 5) && ((unsigned short)field000c == 0)) {
            meter = meter + 0xf;
        }
        ++field000c;
        if ((unsigned short)field000c >= frameDuration) {
            field000c = 0;
            ++field000a;
            attackCollisionResult = 3;
            if (field000a >= frameCount) {
                field0008 = 0;
                ResetPose();
            }
        }
        break;
    case 258:
        if ((field000a == 0) && ((unsigned short)field000c == 0)) {
            if (positionY == 0.0) {
                ResetFrame();
            }
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
        if ((field000a == 5) && ((unsigned short)field000c == 0)) {
            meter = meter + 0xf;
        }
        ++field000c;
        if ((unsigned short)field000c >= frameDuration) {
            field000c = 0;
            ++field000a;
            attackCollisionResult = 3;
            if (field000a >= frameCount) {
                field0008 = 0;
                ResetPose();
            }
        }
        break;
    case 259:
        if (((field000a == 0) && ((unsigned short)field000c == 0)) &&
            (dashMomentumFlag = 0, positionY == 0.0)) {
            velocityX = 0.0;
            velocityY = 0.0;
        }
        if ((field000a == 8) && ((unsigned short)field000c == 0)) {
            effect.type = 0x1f;
            effect.x = (double)(int(positionX));
            effect.y = (double)(int(positionY));
            effect.group = 0;
            effect.layer = 1;
            contextOwner->EmitEffect(&effect);
            velocityX = 1.2;
            velocityY = -1.6;
            gravity = 0.035;
            remainingHitCount = 1;
        }
        if (positionY + velocityX < 0.0) {
            velocityY = velocityY + gravity;
        }
        ++field000c;
        if (field000a > 8 && positionY + velocityY > 0.0) {
            velocityY = 0.0;
            positionY = 0.0;
            velocityX = 0.0;
            field000a = 0x11;
            field000c = 0;
            break;
        }
        if ((unsigned short)field000c >= frameDuration) {
            field000c = 0;
            ++field000a;
            if (field000a == 10) {
                pendingCharacterSoundSlot = 9;
            }
            if (field000a == 0x11) {
                field000a = field000a + -2;
            }
            if (field000a >= frameCount) {
                field0008 = 0;
                ResetPose();
            }
        }
        break;
    case 260:
        if (((field000a == 0) && ((unsigned short)field000c == 0)) &&
            (dashMomentumFlag = 0, positionY == 0.0)) {
            velocityX = 0.0;
            velocityY = 0.0;
        }
        if ((field000a == 8) && ((unsigned short)field000c == 0)) {
            effect.type = 0x1f;
            effect.x = (double)(int(positionX));
            effect.y = (double)(int(positionY));
            effect.group = 0;
            effect.layer = 1;
            contextOwner->EmitEffect(&effect);
            velocityX = 1.4;
            velocityY = -1.5;
            gravity = 0.035;
            remainingHitCount = 1;
        }
        if (positionY + velocityX < 0.0) {
            velocityY = velocityY + gravity;
        }
        ++field000c;
        if (field000a > 8 && positionY + velocityY > 0.0) {
            velocityY = 0.0;
            positionY = 0.0;
            velocityX = 0.0;
            field000a = 0x11;
            field000c = 0;
            break;
        }
        if ((unsigned short)field000c >= frameDuration) {
            field000c = 0;
            ++field000a;
            if (field000a == 10) {
                pendingCharacterSoundSlot = 9;
            }
            if (field000a == 0x11) {
                field000a = field000a + -2;
            }
            if (field000a >= frameCount) {
                field0008 = 0;
                ResetPose();
            }
        }
        break;
    case 261:
        if (((field000a == 0) && ((unsigned short)field000c == 0)) &&
            (dashMomentumFlag = 0, positionY == 0.0)) {
            velocityX = 0.0;
            velocityY = 0.0;
        }
        if ((field000a == 0) && ((unsigned short)field000c == 0)) {
            ResetFrame();
            remainingHitCount = 1;
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
        if ((field000a == 8) && ((unsigned short)field000c == 0)) {
            effect.type = 0x1f;
            effect.x = (double)(int(positionX));
            effect.y = (double)(int(positionY));
            effect.group = 0;
            effect.layer = 1;
            contextOwner->EmitEffect(&effect);
            velocityX = 1.8;
            velocityY = -1.6;
            gravity = 0.035;
            remainingHitCount = 1;
        }
        if (positionY + velocityX < 0.0) {
            velocityY = velocityY + gravity;
        }
        ++field000c;
        if (field000a > 8 && positionY + velocityY > 0.0) {
            velocityY = 0.0;
            positionY = 0.0;
            velocityX = 0.0;
            field000a = 0x11;
            field000c = 0;
            break;
        }
        if ((unsigned short)field000c >= frameDuration) {
            field000c = 0;
            ++field000a;
            if (field000a == 10) {
                pendingCharacterSoundSlot = 10;
            }
            if (field000a == 0x11) {
                field000a = field000a + -2;
            }
            if (field000a >= frameCount) {
                field0008 = 0;
                ResetPose();
            }
        }
        break;
    case 262:
        if ((field000a == 0) && ((unsigned short)field000c == 0)) {
            dashMomentumFlag = 0;
            velocityX = 0.0;
            velocityY = 0.0;
        }
        if ((field000a == 0) && ((unsigned short)field000c == 0)) {
            velocityX = 1.2;
            velocityY = -1.3;
            gravity = 0.025;
            remainingHitCount = 1;
        }
        if (positionY + velocityX < 0.0) {
            velocityY = velocityY + gravity;
        }
        ++field000c;
        if (positionY + velocityY > 0.0) {
            velocityY = 0.0;
            positionY = 0.0;
            velocityX = 0.0;
            field000a = 9;
            field000c = 0;
            break;
        }
        if ((unsigned short)field000c >= frameDuration) {
            field000c = 0;
            ++field000a;
            if (field000a == 2) {
                pendingCharacterSoundSlot = 9;
            }
            if (field000a == 9) {
                field000a = field000a + -2;
            }
            if (field000a >= frameCount) {
                field0008 = 0;
                ResetPose();
            }
        }
        break;
    case 263:
        if ((field000a == 0) && ((unsigned short)field000c == 0)) {
            dashMomentumFlag = 0;
            velocityX = 0.0;
            velocityY = 0.0;
        }
        if ((field000a == 0) && ((unsigned short)field000c == 0)) {
            velocityX = 1.2;
            velocityY = -1.5;
            gravity = 0.025;
            remainingHitCount = 1;
        }
        if (positionY + velocityX < 0.0) {
            velocityY = velocityY + gravity;
        }
        ++field000c;
        if (positionY + velocityY > 0.0) {
            velocityY = 0.0;
            positionY = 0.0;
            velocityX = 0.0;
            field000a = 9;
            field000c = 0;
            break;
        }
        if ((unsigned short)field000c >= frameDuration) {
            field000c = 0;
            ++field000a;
            if (field000a == 2) {
                pendingCharacterSoundSlot = 9;
            }
            if (field000a == 9) {
                field000a = field000a + -2;
            }
            if (field000a >= frameCount) {
                field0008 = 0;
                ResetPose();
            }
        }
        break;
    case 264:
        if ((field000a == 0) && ((unsigned short)field000c == 0)) {
            dashMomentumFlag = 0;
            velocityX = 0.0;
            velocityY = 0.0;
        }
        if ((field000a == 0) && ((unsigned short)field000c == 0)) {
            ResetFrame();
            remainingHitCount = 1;
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
            velocityX = 1.8;
            velocityY = -1.3;
            gravity = 0.025;
            remainingHitCount = 1;
        }
        if (positionY + velocityX < 0.0) {
            velocityY = velocityY + gravity;
        }
        ++field000c;
        if (positionY + velocityY > 0.0) {
            velocityY = 0.0;
            positionY = 0.0;
            velocityX = 0.0;
            field000a = 9;
            field000c = 0;
            break;
        }
        if ((unsigned short)field000c >= frameDuration) {
            field000c = 0;
            ++field000a;
            if (field000a == 2) {
                pendingCharacterSoundSlot = 10;
            }
            if (field000a == 9) {
                field000a = field000a + -2;
            }
            if (field000a >= frameCount) {
                field0008 = 0;
                ResetPose();
            }
        }
        break;
    case 265:
        if ((field000a == 0) && ((unsigned short)field000c == 0)) {
            ResetFrame();
        }
        if ((field000a == 0xc) && ((unsigned short)field000c == 0)) {
            meter = meter + 0xf;
            effect.type = 0x19d;
            effect.x = positionX;
            effect.y = positionY;
            effect.flag0018 = (unsigned char)facing;
            effect.layer = 1;
            effect.group = 2;
            EmitLocalEffect(&effect);
            pendingCharacterSoundSlot = 6;
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
    case 266:
        if ((field000a == 0) && ((unsigned short)field000c == 0)) {
            ResetFrame();
        }
        if ((field000a == 0xc) && ((unsigned short)field000c == 0)) {
            meter = meter + 0xf;
            effect.type = 0x1a0;
            effect.x = positionX;
            effect.y = positionY;
            effect.flag0018 = (unsigned char)facing;
            effect.layer = 1;
            effect.group = 2;
            EmitLocalEffect(&effect);
            pendingCharacterSoundSlot = 6;
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
    case 267:
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
        if ((field000a == 0xc) && ((unsigned short)field000c == 0)) {
            meter = meter + 0xf;
            effect.type = 0x1a3;
            effect.x = positionX;
            effect.y = positionY;
            effect.flag0018 = (unsigned char)facing;
            effect.layer = 1;
            effect.group = 2;
            EmitLocalEffect(&effect);
            pendingCharacterSoundSlot = 6;
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
    case 300:
        dashMomentumFlag = 0;
        if ((field000a == 0) && ((unsigned short)field000c == 0)) {
            ResetFrame();
            meter = meter + -1000;
            SetHorizontalShake(0x32,0x2d);
            hitstunFrames = 0x78;
            SetTint(0xb0,3);
            effect.type = 0x44;
            effect.palette = 0x13;
            effect.x = (double)(int(positionX));
            effect.y = (double)((int(positionY)) + -0x2c);
            effect.group = 2;
            effect.owner = 1;
            effect.layer = 1;
            contextOwner->EmitEffect(&effect);
        }
        if ((attackCollisionResult == 6) && (field000a == 7)) {
            ResetPose();
            field000a = 8;
            attackCollisionResult = 0;
            hitstunFrames = 0x9f;
            pendingContextSoundSlot = 3;
            effect.type = 0;
            effect.x = (double)((int(positionX)) + facing * 10);
            effect.y = (double)((int(positionY)) + -0x28);
            effect.group = 2;
            effect.layer = 1;
            contextOwner->EmitEffect(&effect);
            break;
        }
        ++field000c;
        if ((unsigned short)field000c >= frameDuration) {
            field000c = 0;
            ++field000a;
            attackCollisionResult = 0;
            if (field000a == 8) {
                field000a = 9;
                break;
            }
            if (field000a == 9) {
                ResetPose();
                field0008 = 0x12f;
                effect.type = 0x1a9;
                effect.x = (double)((int(positionX)) - facing * 0xf);
                effect.y = (double)((int(positionY)) + -0x2c);
                effect.group = 0;
                effect.layer = 1;
                effect.flag0018 = (unsigned char)facing;
                EmitLocalEffect(&effect);
                break;
            }
            if (field000a >= frameCount) {
                field0008 = 0;
                FaceOpponent();
                ResetPose();
            }
        }
        break;
    case 301:
        dashMomentumFlag = 0;
        if ((field000a == 0) && ((unsigned short)field000c == 0)) {
            ResetFrame();
            meter = meter + -2000;
            SetHorizontalShake(0x32,0x2d);
            hitstunFrames = 0x78;
            SetTint(0xb0,3);
            effect.type = 0x45;
            effect.palette = 5;
            effect.x = (double)(int(positionX));
            effect.y = (double)((int(positionY)) + -0x2c);
            effect.group = 2;
            effect.owner = 1;
            effect.layer = 1;
            contextOwner->EmitEffect(&effect);
        }
        if ((attackCollisionResult == 6) && (field000a == 7)) {
            ResetPose();
            field000a = 8;
            attackCollisionResult = 0;
            hitstunFrames = 0x9f;
            pendingContextSoundSlot = 3;
            effect.type = 0;
            effect.x = (double)((int(positionX)) + facing * 10);
            effect.y = (double)((int(positionY)) + -0x28);
            effect.group = 2;
            effect.layer = 1;
            contextOwner->EmitEffect(&effect);
            break;
        }
        ++field000c;
        if ((unsigned short)field000c >= frameDuration) {
            field000c = 0;
            ++field000a;
            attackCollisionResult = 0;
            if (field000a == 8) {
                field000a = 9;
                break;
            }
            if (field000a == 9) {
                ResetPose();
                field0008 = 0x12f;
                effect.type = 0x1aa;
                effect.x = (double)((int(positionX)) - facing * 0xf);
                effect.y = (double)((int(positionY)) + -0x2c);
                effect.group = 0;
                effect.layer = 1;
                effect.flag0018 = (unsigned char)facing;
                EmitLocalEffect(&effect);
                break;
            }
            if (field000a >= frameCount) {
                field0008 = 0;
                FaceOpponent();
                ResetPose();
            }
        }
        break;
    case 302:
        contextOwner->SetSceneTimer(0xf);
        dashMomentumFlag = 0;
        if ((field000a == 0) && ((unsigned short)field000c == 0)) {
            ResetFrame();
            meter = meter + -3000;
            SetHorizontalShake(0x32,0x2d);
            hitstunFrames = 0x78;
            SetTint(0xb0,3);
            effect.type = 0x46;
            effect.palette = 0x40;
            effect.x = (double)(int(positionX));
            effect.y = (double)((int(positionY)) + -0x2c);
            effect.group = 2;
            effect.owner = 1;
            effect.layer = 1;
            contextOwner->EmitEffect(&effect);
            pendingContextSoundSlot = 0x25;
        }
        if ((attackCollisionResult == 6) && (field000a == 7)) {
            ResetPose();
            field000a = 8;
            attackCollisionResult = 0;
            hitstunFrames = 0x9f;
            pendingContextSoundSlot = 3;
            effect.type = 0;
            effect.x = (double)((int(positionX)) + facing * 10);
            effect.y = (double)((int(positionY)) + -0x28);
            effect.group = 2;
            effect.layer = 1;
            contextOwner->EmitEffect(&effect);
            break;
        }
        ++field000c;
        if ((unsigned short)field000c >= frameDuration) {
            field000c = 0;
            ++field000a;
            attackCollisionResult = 0;
            if (field000a == 8) {
                field000a = 9;
                break;
            }
            if (field000a == 9) {
                ResetPose();
                field0008 = 0x12f;
                effect.type = 0x1ab;
                effect.x = (double)((int(positionX)) - facing * 0xf);
                effect.y = (double)((int(positionY)) + -0x2c);
                effect.group = 0;
                effect.layer = 1;
                effect.flag0018 = (unsigned char)facing;
                EmitLocalEffect(&effect);
                break;
            }
            if (field000a >= frameCount) {
                field0008 = 0;
                FaceOpponent();
                ResetPose();
            }
        }
        break;
    case 303:
        if ((field000a == 0) && ((unsigned short)field000c == 0)) {
            ResetFrame();
        }
        if ((field000a == 1) && ((unsigned short)field000c == 0)) {
            effect.type = 0x1b3;
            effect.x = (double)(int(positionX));
            effect.y = (double)(int(positionY));
            effect.group = 0;
            effect.layer = 1;
            effect.flag0018 = (unsigned char)facing;
            EmitLocalEffect(&effect);
        }
        if (positionY < 0.0) {
            velocityY = velocityY + gravity;
        }
        ++field000c;
        if ((unsigned short)field000c >= frameDuration) {
            field000c = 0;
            ++field000a;
            if (field000a == 2) {
                positionY = 0.0;
                velocityY = -2.9;
                gravity = 0.035;
            }
            if (field000a == 10) {
                field000a = field000a + -2;
            }
            if (field000a >= frameCount) {
                ResetPose();
                field0008 = 0;
                return;
            }
        }
        if (((0.0 < positionY + velocityY) &&
            (3 < field000a)) && (field000a < 10)) {
            positionY = 0.0;
            field000a = 10;
            gravity = 0.0;
            ResetFrame();
        }
        break;
    case 304:
        if ((field000a == 0) && ((unsigned short)field000c == 0)) {
            field3138 = (int(velocityX * 100.0));
            field313c = (int(velocityY * 100.0));
            field3140 = (int(gravity * 1000.0));
            ResetFrame();
            meter = meter + -1000;
            SetHorizontalShake(0x32,0x2d);
            hitstunFrames = 0x78;
            SetTint(0xb0,3);
            effect.type = 0x44;
            effect.palette = 0x13;
            effect.x = (double)(int(positionX));
            effect.y = (double)((int(positionY)) + -0x2c);
            effect.group = 2;
            effect.owner = 1;
            effect.layer = 1;
            contextOwner->EmitEffect(&effect);
        }
        if ((field000a == 6) && ((unsigned short)field000c == 0)) {
            velocityX = (double)field3138 * 0.01;
            velocityY = (double)field313c * 0.01;
            gravity = (double)field3140 * 0.001;
            field3138 = 0;
        }
        if (((5 < field000a) && (field000a < 0xb)) &&
            (field000a != 8)) {
            velocityY = velocityY + gravity;
        }
        if ((0.0 < positionY + velocityY) &&
            (positionY < 0.0)) {
            ResetFrame();
            positionY = 0.0;
            field000c = 0;
            field000a = 0xb;
        }
        if ((attackCollisionResult == 6) &&
            ((field000a == 7 || (field000a == 6)))) {
            ResetFrame();
            ResetPose();
            field000a = 8;
            attackCollisionResult = 0;
            hitstunFrames = 0x9f;
            pendingContextSoundSlot = 3;
            effect.type = 0;
            effect.x = (double)((int(positionX)) + facing * 10);
            effect.y = (double)((int(positionY)) + -0x28);
            effect.group = 2;
            effect.layer = 1;
            contextOwner->EmitEffect(&effect);
            break;
        }
        ++field000c;
        if ((unsigned short)field000c >= frameDuration) {
            field000c = 0;
            ++field000a;
            attackCollisionResult = 0;
            if (field000a == 8) {
                if (field3138 < 1) {
                    field000a = 9;
                    return;
                }
                field000a = field000a + -2;
                ++field3138;
            }
            if (field000a == 9) {
                ResetPose();
                field0008 = 0x12f;
                effect.type = 0x1a9;
                effect.x = (double)((int(positionX)) - facing * 0xf);
                effect.y = (double)((int(positionY)) + -0x2c);
                effect.group = 0;
                effect.layer = 1;
                effect.flag0018 = (unsigned char)facing;
                EmitLocalEffect(&effect);
                break;
            }
            if (field000a >= frameCount) {
                field0008 = 3;
                FaceOpponent();
                ResetPose();
            }
        }
        break;
    case 307:
        dashMomentumFlag = 0;
        ResetFrame();
        if ((field000a == 4) && ((unsigned short)field000c == 0)) {
            meter = meter + -1000;
            SetHorizontalShake(0x32,0x2d);
            hitstunFrames = 0x78;
            SetTint(0xb0,3);
            effect.type = 0x44;
            effect.palette = 0x13;
            effect.x = (double)(int(positionX));
            effect.y = (double)((int(positionY)) + -0x2c);
            effect.group = 2;
            effect.owner = 1;
            effect.layer = 1;
            contextOwner->EmitEffect(&effect);
            effect.type = 0x1b4;
            effect.x = (double)((int(positionX)) + facing * 0x3c);
            effect.y = (double)(int(positionY));
            effect.group = 0;
            effect.layer = 1;
            effect.flag0018 = (unsigned char)facing;
            effect.field0030 = 1;
            effect.field0028 = 1;
            EmitLocalEffect(&effect);
        }
        ++field000c;
        if ((unsigned short)field000c >= frameDuration) {
            field000c = 0;
            ++field000a;
            attackCollisionResult = 0;
            if ((field000a == 9) && (field3138 < 6)) {
                ++field3138;
                field000a = field000a + -3;
            }
            if (field000a >= frameCount) {
                field0008 = 0;
                FaceOpponent();
                ResetPose();
            }
        }
        break;
    case 308:
        dashMomentumFlag = 0;
        ResetFrame();
        if ((field000a == 4) && ((unsigned short)field000c == 0)) {
            meter = meter + -2000;
            SetHorizontalShake(0x32,0x2d);
            hitstunFrames = 0x78;
            SetTint(0xb0,3);
            effect.type = 0x45;
            effect.palette = 5;
            effect.x = (double)(int(positionX));
            effect.y = (double)((int(positionY)) + -0x2c);
            effect.group = 2;
            effect.owner = 1;
            effect.layer = 1;
            contextOwner->EmitEffect(&effect);
            effect.type = 0x1b6;
            effect.x = (double)((int(positionX)) + facing * 0x3c);
            effect.y = (double)((int(positionY)) + -0x2d);
            effect.group = 0;
            effect.layer = 1;
            effect.flag0018 = (unsigned char)facing;
            effect.field0030 = 1;
            effect.field0028 = 1;
            EmitLocalEffect(&effect);
        }
        ++field000c;
        if ((unsigned short)field000c >= frameDuration) {
            field000c = 0;
            ++field000a;
            attackCollisionResult = 0;
            if ((field000a == 9) && (field3138 < 5)) {
                ++field3138;
                field000a = field000a + -3;
            }
            if (field000a >= frameCount) {
                field0008 = 0;
                FaceOpponent();
                ResetPose();
            }
        }
        break;
    case 309:
        dashMomentumFlag = 0;
        if (3 < field000a) {
            contextOwner->SetSceneTimer(0xf);
        }
        ResetFrame();
        if ((field000a == 4) && ((unsigned short)field000c == 0)) {
            meter = meter + -3000;
            SetHorizontalShake(0x32,0x2d);
            hitstunFrames = 0x78;
            SetTint(0xb0,3);
            effect.type = 0x46;
            effect.palette = 0x40;
            effect.x = (double)(int(positionX));
            effect.y = (double)((int(positionY)) + -0x2c);
            effect.group = 2;
            effect.owner = 1;
            effect.layer = 1;
            contextOwner->EmitEffect(&effect);
            pendingContextSoundSlot = 0x25;
            effect.type = 0x1b8;
            effect.x = (double)((int(positionX)) - facing * 0x32);
            effect.y = (double)((int(positionY)) + 200);
            effect.group = 0;
            effect.layer = 1;
            effect.owner = 1;
            effect.flag0018 = (unsigned char)facing;
            effect.field0030 = 1;
            effect.field0028 = 1;
            EmitLocalEffect(&effect);
        }
        ++field000c;
        if ((unsigned short)field000c >= frameDuration) {
            field000c = 0;
            ++field000a;
            attackCollisionResult = 0;
            if ((field000a == 9) && (field3138 < 10)) {
                ++field3138;
                field000a = field000a + -3;
            }
            if (field000a >= frameCount) {
                field0008 = 0;
                FaceOpponent();
                ResetPose();
            }
        }
        break;
    case 310:
        dashMomentumFlag = 0;
        if ((field000a == 0) && ((unsigned short)field000c == 0)) {
            ResetFrame();
            meter = meter + -1000;
            SetHorizontalShake(0x32,0x2d);
            hitstunFrames = 0x78;
            SetTint(0xb0,3);
            effect.type = 0x44;
            effect.palette = 0x13;
            effect.x = (double)(int(positionX));
            effect.y = (double)((int(positionY)) + -0x39);
            effect.group = 2;
            effect.owner = 1;
            effect.layer = 1;
            contextOwner->EmitEffect(&effect);
        }
        if (((field000a == 9) && ((unsigned short)field000c == 0)) &&
            (field3464 = field3464 + 1, 3 < field3464)) {
            field3464 = 3;
        }
        ++field000c;
        if ((unsigned short)field000c >= frameDuration) {
            field000c = 0;
            ++field000a;
            attackCollisionResult = 0;
            if ((field000a == 0xf) && (field3138 < 1)) {
                field000a = field000a + -4;
                ++field3138;
                break;
            }
            if (field000a >= frameCount) {
                field0008 = 0;
                FaceOpponent();
                ResetPose();
            }
        }
        break;
    case 311:
        dashMomentumFlag = 0;
        if ((field000a == 0) && ((unsigned short)field000c == 0)) {
            ResetFrame();
            meter = meter + -2000;
            SetHorizontalShake(0x32,0x2d);
            hitstunFrames = 0x78;
            SetTint(0xb0,3);
            effect.type = 0x45;
            effect.palette = 5;
            effect.x = (double)(int(positionX));
            effect.y = (double)((int(positionY)) + -0x39);
            effect.group = 2;
            effect.owner = 1;
            effect.layer = 1;
            contextOwner->EmitEffect(&effect);
        }
        if (((field000a == 9) && ((unsigned short)field000c == 0)) &&
            (field3464 = field3464 + 2, 3 < field3464)) {
            field3464 = 3;
        }
        ++field000c;
        if ((unsigned short)field000c >= frameDuration) {
            field000c = 0;
            ++field000a;
            attackCollisionResult = 0;
            if ((field000a == 0xf) && (field3138 < 1)) {
                field000a = field000a + -4;
                ++field3138;
                break;
            }
            if (field000a >= frameCount) {
                field0008 = 0;
                FaceOpponent();
                ResetPose();
            }
        }
        break;
    case 312:
        dashMomentumFlag = 0;
        if (3 < field000a) {
            contextOwner->SetSceneTimer(0xf);
        }
        if ((field000a == 0) && ((unsigned short)field000c == 0)) {
            ResetFrame();
            meter = meter + -3000;
            SetHorizontalShake(0x32,0x2d);
            hitstunFrames = 0x78;
            SetTint(0xb0,3);
            effect.type = 0x46;
            effect.palette = 0x40;
            effect.x = (double)(int(positionX));
            effect.y = (double)((int(positionY)) + -0x39);
            effect.group = 2;
            effect.owner = 1;
            effect.layer = 1;
            contextOwner->EmitEffect(&effect);
            pendingContextSoundSlot = 0x25;
        }
        if (((field000a == 9) && ((unsigned short)field000c == 0)) &&
            (field3464 = field3464 + 3, 3 < field3464)) {
            field3464 = 3;
        }
        ++field000c;
        if ((unsigned short)field000c >= frameDuration) {
            field000c = 0;
            ++field000a;
            attackCollisionResult = 0;
            if ((field000a == 0xf) && (field3138 < 1)) {
                field000a = field000a + -4;
                ++field3138;
                break;
            }
            if (field000a >= frameCount) {
                field0008 = 0;
                FaceOpponent();
                ResetPose();
            }
        }
        break;
    case 313:
        dashMomentumFlag = 0;
        if ((field000a == 2) && ((unsigned short)field000c == 0)) {
            ResetFrame();
            SetHorizontalShake(0x32,3);
            hitstunFrames = 0xb4;
            SetTint(0xb0,3);
            effect.type = 0x44;
            effect.palette = 0x13;
            effect.x = (double)(int(positionX));
            effect.y = (double)((int(positionY)) + -0x39);
            effect.group = 2;
            effect.owner = 1;
            effect.layer = 1;
            contextOwner->EmitEffect(&effect);
            --field3464;
        }
        ++field000c;
        if ((unsigned short)field000c >= frameDuration) {
            field000c = 0;
            ++field000a;
            attackCollisionResult = 0;
            if (field000a >= frameCount) {
                field0008 = 0;
                FaceOpponent();
                ResetPose();
            }
        }
        break;
    case 314:
        dashMomentumFlag = 0;
        if ((field000a == 2) && ((unsigned short)field000c == 0)) {
            ResetFrame();
            SetHorizontalShake(0x32,3);
            hitstunFrames = 0xb4;
            SetTint(0xb0,3);
            effect.type = 0x44;
            effect.palette = 0x13;
            effect.x = (double)(int(positionX));
            effect.y = (double)((int(positionY)) + -0x39);
            effect.group = 2;
            effect.owner = 1;
            effect.layer = 1;
            contextOwner->EmitEffect(&effect);
            --field3464;
        }
        ++field000c;
        if ((unsigned short)field000c >= frameDuration) {
            field000c = 0;
            ++field000a;
            attackCollisionResult = 3;
            if (field000a >= frameCount) {
                field0008 = 0;
                FaceOpponent();
                ResetPose();
            }
        }
        break;
    case 315:
        dashMomentumFlag = 0;
        if ((field000a == 1) && ((unsigned short)field000c == 0)) {
            ResetFrame();
            SetHorizontalShake(0x32,3);
            hitstunFrames = 0xb4;
            SetTint(0xb0,3);
            effect.type = 0x44;
            effect.palette = 0x13;
            effect.x = (double)(int(positionX));
            effect.y = (double)((int(positionY)) + -0x39);
            effect.group = 2;
            effect.owner = 1;
            effect.layer = 1;
            contextOwner->EmitEffect(&effect);
            --field3464;
        }
        ++field000c;
        if ((unsigned short)field000c >= frameDuration) {
            field000c = 0;
            ++field000a;
            attackCollisionResult = 0;
            if (field000a >= frameCount) {
                field0008 = 0;
                FaceOpponent();
                ResetPose();
            }
        }
        break;
    case 316:
        dashMomentumFlag = 0;
        ResetFrame();
        if ((field000a == 0) && ((unsigned short)field000c == 0)) {
            effect.type = 0x1c2;
            effect.x = (double)(facing * 7) + positionX;
            effect.y = -42.0;
            effect.group = 2;
            effect.layer = 1;
            effect.owner = 1;
            effect.flag0018 = 1;
            effect.field0030 = 1;
            EmitLocalEffect(&effect);
        }
        if ((6 < field000a) && (field000a < 0x2a)) {
            hitstunFrames = 2;
        }
        if ((field000a == 7) && ((unsigned short)field000c == 0)) {
            meter = meter + -3000;
            SetHorizontalShake(0x32,0x2d);
            SetTint(0xb0,3);
            effect.type = 0x46;
            effect.palette = 0x40;
            effect.x = (double)(int(positionX));
            effect.y = (double)((int(positionY)) + -0x2c);
            effect.group = 2;
            effect.owner = 1;
            effect.layer = 1;
            contextOwner->EmitEffect(&effect);
            pendingContextSoundSlot = 0x25;
            effect.type = 0x47;
            contextOwner->EmitEffect(&effect);
        }
        if ((field000a == 10) && ((unsigned short)field000c == 0)) {
            velocityY = -0.9;
        }
        if ((field000a == 0xc) && ((unsigned short)field000c == 0)) {
            velocityY = 0.7;
            SetTint(-0x4f,3);
            contextOwner->state1420e = 30000;
            (*opponentSlot)->contextOwner->state1420e = 30000;
            contextOwner->state1420c = 30000;
        }
        if (field000a == 0x26) {
            contextOwner->state1420e = 30000;
            (*opponentSlot)->contextOwner->state1420e = 30000;
            contextOwner->state1420c = 30000;
        }
        if (((0xb < field000a) && (field000a < 0xe)) &&
            (0.0 < velocityY + positionY)) {
            field000c = 0;
            field000a = 0xe;
            positionY = 0.0;
            velocityY = 0.0;
        }
        if ((field000a == 0x25) && (attackCollisionResult == 3)) {
            field000a = 0x26;
            field000c = 0;
            (*opponentSlot)->field0008 = 0x6b;
            (*opponentSlot)->field000a = 0;
            (*opponentSlot)->field000c = 0;
            (*opponentSlot)->ResetFrame();
        }
        if ((field000a == 0x26) && ((unsigned short)field000c == 0x3c)) {
            contextOwner->StartFade(0xf,0x78,0x78);
        }
        if ((field000a == 0x26) && ((unsigned short)field000c == 0x78)) {
            effect.type = 0x1c1;
            effect.x = 0.0;
            effect.y = 0.0;
            effect.group = 0;
            effect.layer = 1;
            effect.owner = 1;
            effect.flag0018 = 1;
            effect.payload = 1;
            effect.field0030 = 1;
            EmitLocalEffect(&effect);
        }
        if ((field000a == 0x29) && ((unsigned short)field000c == 0)) {
            contextOwner->state1420e = 0;
            (*opponentSlot)->contextOwner->state1420e = 0;
            contextOwner->state1420c = 0;
        }
        ++field000c;
        if ((unsigned short)field000c >= frameDuration) {
            field000c = 0;
            ++field000a;
            attackCollisionResult = 0;
            if ((field000a == 7) && (field3140 < 1)) {
                field000a = field000a + -4;
                ++field3140;
            }
            if (field000a == 0xc) {
                if (field3138 == 5) {
                    contextOwner->StartFade(0xf,0x2d,0xb4);
                    contextOwner->FadeMusic(0xffffd8f0,10);
                }
                if (field3138 < 10) {
                    ++field3138;
                    field000a = field000a + -2;
                }
            }
            if (field000a == 0xe) {
                field000a = field000a + -2;
            }
            if (field000a == 0x25) {
                if ((((*opponentSlot)->field0008 < 0x32) ||
                    (0x95 < (*opponentSlot)->field0008)) &&
                    ((*opponentSlot)->positionY == 0.0)) {
                    remainingHitCount = 1;
                }
                else {
                    remainingHitCount = 0;
                }
            }
            if (field000a == 0x26) {
                field000a = 0x27;
            }
            if (field000a == 0x29) {
                positionX = (double)(facing * 0x61) + positionX
                ;
                SetVerticalShake(3,0);
                effect.type = 3;
                effect.x = (double)(int(positionX));
                effect.y = (double)(int(positionY));
                effect.group = 2;
                effect.layer = 0;
                contextOwner->EmitEffect(&effect);
                pendingContextSoundSlot = 7;
                contextOwner->FadeMusic(0,1000);
            }
            if (field000a >= frameCount) {
                field0008 = 0x60;
                ResetPose();
            }
        }
        break;
    case 317:
        dashMomentumFlag = 0;
        if (field000a < 4) {
            (*opponentSlot)->field000c = 0;
        }
        if (((field000a == 0) && ((unsigned short)field000c == 0)) &&
            (field313c == 0)) {
            contextOwner->FadeMusic(0,0x14);
            ++field313c;
        }
        if ((field000a == 4) && ((unsigned short)field000c == 0)) {
            (*opponentSlot)->koDelayFrames = 0;
        }
        ++field000c;
        if ((unsigned short)field000c >= frameDuration) {
            field000c = 0;
            ++field000a;
            attackCollisionResult = 0;
            if ((field000a == 4) && (field313c < 0x13)) {
                field000a = 0;
                ++field313c;
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
