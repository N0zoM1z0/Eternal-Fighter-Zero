// Misaki complete animation and state update dispatch.
#include "CharacterViews.h"
void Character07::Slot06()
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
        field0158 = 0;
        field0030 = 0.0;
        field0038 = 0.0;
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
        field0030 = 0.8;
        field0038 = 0.0;
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
        field0158 = 0;
        field0030 = -0.8;
        field0038 = 0.0;
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
        field0030 = 0.0;
        field0038 = 0.0;
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
        if ((field000a == 0) && ((unsigned short)field000c == 0)) {
            if ((unsigned char)field0158 == '\0') {
                FaceOpponent();
            }
            field0030 = 0.0;
        }
        if ((field000a == 3) && ((unsigned short)field000c == 0)) {
            field0048 = 0.042;
            field0038 = -2.7;
            if ((unsigned char)field0158 == '\x01') {
                field0030 = 0.4;
                field0158 = 0;
            }
        }
        if (2 < field000a) {
            field0038 = field0038 + field0048;
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
        if ((0.0 <= field0028 + field0038) &&
            (3 < field000a)) {
            field0028 = 0.0;
            field02c9 = 9;
            FaceOpponent();
            field0008 = 0xd;
            ResetPose();
        }
        break;
    case 5:
        if ((field000a == 0) && ((unsigned short)field000c == 0)) {
            if ((unsigned char)field0158 == '\0') {
                FaceOpponent();
            }
            field0030 = 0.0;
        }
        if ((field000a == 3) && ((unsigned short)field000c == 0)) {
            field0048 = 0.042;
            field0038 = -2.7;
            field0030 = 0.7;
            if ((unsigned char)field0158 == '\x01') {
                field0030 = 1.1;
                field0158 = 0;
            }
        }
        if (2 < field000a) {
            field0038 = field0038 + field0048;
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
        if ((0.0 <= field0028 + field0038) &&
            (3 < field000a)) {
            field0028 = 0.0;
            field02c9 = 9;
            FaceOpponent();
            field0008 = 0xd;
            ResetPose();
        }
        break;
    case 6:
        if ((field000a == 0) && ((unsigned short)field000c == 0)) {
            if ((unsigned char)field0158 == '\0') {
                FaceOpponent();
            }
            field0030 = 0.0;
        }
        if ((field000a == 2) && ((unsigned short)field000c == 0)) {
            field0048 = 0.042;
            field0038 = -2.7;
            field0030 = -0.7;
        }
        if (2 < field000a) {
            field0038 = field0038 + field0048;
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
        if ((0.0 <= field0028 + field0038) &&
            (3 < field000a)) {
            field0028 = 0.0;
            field02c9 = 9;
            FaceOpponent();
            field0008 = 0xd;
            ResetPose();
        }
        break;
    case 7:
        field0030 = 0.0;
        field0038 = 0.0;
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
        field0030 = 0.0;
        field0038 = 0.0;
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
        field0038 = field0038 + field0048;
        field0158 = 0;
        ++field000c;
        if ((unsigned short)field000c >= frameDuration) {
            field000c = 0;
            ++field000a;
            if (field000a >= frameCount) {
                field000a = 0;
            }
        }
        if (0.0 <= field0028 + field0038) {
            field0028 = 0.0;
            field02c9 = 9;
            field0008 = 0xd;
            ResetPose();
        }
        break;
    case 13:
        field0030 = 0.0;
        field0038 = 0.0;
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
        field0048 = 0.042;
        if ((field000a == 0) && ((unsigned short)field000c == 0)) {
            field0038 = -2.7;
            field0030 = 0.0;
        }
        field0038 = field0038 + field0048;
        ++field000c;
        if ((unsigned short)field000c >= frameDuration) {
            field000c = 0;
            ++field000a;
            if (field000a >= frameCount) {
                field0008 = 9;
                ResetPose();
            }
        }
        if ((0.0 <= field0028 + field0038) &&
            (3 < field000a)) {
            field0028 = 0.0;
            field02c9 = 9;
            FaceOpponent();
            field0008 = 0xd;
            ResetPose();
        }
        break;
    case 15:
        field0048 = 0.042;
        if ((field000a == 0) && ((unsigned short)field000c == 0)) {
            field0038 = -2.7;
            field0030 = 0.7;
        }
        field0038 = field0038 + field0048;
        ++field000c;
        if ((unsigned short)field000c >= frameDuration) {
            field000c = 0;
            ++field000a;
            if (field000a >= frameCount) {
                field0008 = 9;
                ResetPose();
            }
        }
        if ((0.0 <= field0028 + field0038) &&
            (3 < field000a)) {
            field0028 = 0.0;
            field02c9 = 9;
            FaceOpponent();
            field0008 = 0xd;
            ResetPose();
        }
        break;
    case 16:
        field0048 = 0.042;
        if ((field000a == 0) && ((unsigned short)field000c == 0)) {
            field0038 = -2.7;
            field0030 = -0.7;
        }
        field0038 = field0038 + field0048;
        ++field000c;
        if ((unsigned short)field000c >= frameDuration) {
            field000c = 0;
            ++field000a;
            if (field000a >= frameCount) {
                field0008 = 9;
                ResetPose();
            }
        }
        if ((0.0 <= field0028 + field0038) &&
            (3 < field000a)) {
            field0028 = 0.0;
            field02c9 = 9;
            FaceOpponent();
            field0008 = 0xd;
            ResetPose();
        }
        break;
    case 47:
        if ((field000a == 0) && ((unsigned short)field000c == 0)) {
            field0030 = 0.0;
            field0048 = 0.035;
        }
        field0038 = field0038 + field0048;
        if ((0.0 < field0028 + field0038) &&
            (field000a < 2)) {
            field000c = 0;
            field000a = 2;
            field02c9 = 7;
            field0028 = 0.0;
            field0038 = 0.0;
            field0048 = 0.0;
            field0030 = 0.0;
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
        field0158 = 0;
        if ((field000a == 0) && ((unsigned short)field000c == 0)) {
            field0148 = field0148 + 10;
            field0030 =
            (2.0 - (*opponentSlot)->field0178 / 10000.0) *
            -1.1;
            if (field0120 != '\0') {
                field0118 = field0118 - 10.0;
            }
        }
        field0038 = 0.0;
        field0028 = 0.0;
        field0030 = field0030 + 0.06;
        if (field0030 > 0.0) {
            field0030 = 0.0;
        }
        if ((field0020 - 20.0 <= 0.0) ||
            (639.0 <= field0020 + 20.0)) {
            field00b8 =
            (1.0 - (double)((field0028 < 0.0)) * 0.2) * field0030;
        }
        else {
            field00b8 = 0.0;
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
        field0158 = 0;
        if ((field000a == 0) && ((unsigned short)field000c == 0)) {
            field0148 = field0148 + 0xf;
            field0030 =
            (2.0 - (*opponentSlot)->field0178 / 10000.0) *
            -1.5;
            if (field0120 != '\0') {
                field0118 = field0118 - 20.0;
            }
        }
        field0038 = 0.0;
        field0028 = 0.0;
        field0030 = field0030 + 0.06;
        if (field0030 > 0.0) {
            field0030 = 0.0;
        }
        if ((field0020 - 20.0 <= 0.0) ||
            (639.0 <= field0020 + 20.0)) {
            field00b8 =
            (1.0 - (double)((field0028 < 0.0)) * 0.2) * field0030;
        }
        else {
            field00b8 = 0.0;
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
        field0158 = 0;
        if ((field000a == 0) && ((unsigned short)field000c == 0)) {
            field0148 = field0148 + 0x14;
            field0030 =
            (2.0 - (*opponentSlot)->field0178 / 10000.0) *
            -1.8;
            if (field0120 != '\0') {
                field0118 = field0118 - 30.0;
            }
        }
        field0038 = 0.0;
        field0028 = 0.0;
        field0030 = field0030 + 0.06;
        if (field0030 > 0.0) {
            field0030 = 0.0;
        }
        if ((field0020 - 20.0 <= 0.0) ||
            (639.0 <= field0020 + 20.0)) {
            field00b8 =
            (1.0 - (double)((field0028 < 0.0)) * 0.2) * field0030;
        }
        else {
            field00b8 = 0.0;
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
        field0158 = 0;
        if ((field000a == 0) && ((unsigned short)field000c == 0)) {
            field0148 = field0148 + 10;
            field0030 =
            (2.0 - (*opponentSlot)->field0178 / 10000.0) *
            -1.1;
            if (field0120 != '\0') {
                field0118 = field0118 - 10.0;
            }
        }
        field0038 = 0.0;
        field0028 = 0.0;
        field0030 = field0030 + 0.06;
        if (field0030 > 0.0) {
            field0030 = 0.0;
        }
        if ((field0020 - 20.0 <= 0.0) ||
            (639.0 <= field0020 + 20.0)) {
            field00b8 =
            (1.0 - (double)((field0028 < 0.0)) * 0.2) * field0030;
        }
        else {
            field00b8 = 0.0;
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
        field0158 = 0;
        if ((field000a == 0) && ((unsigned short)field000c == 0)) {
            field0148 = field0148 + 0xf;
            field0030 =
            (2.0 - (*opponentSlot)->field0178 / 10000.0) *
            -1.5;
            if (field0120 != '\0') {
                field0118 = field0118 - 20.0;
            }
        }
        field0038 = 0.0;
        field0028 = 0.0;
        field0030 = field0030 + 0.06;
        if (field0030 > 0.0) {
            field0030 = 0.0;
        }
        if ((field0020 - 20.0 <= 0.0) ||
            (639.0 <= field0020 + 20.0)) {
            field00b8 =
            (1.0 - (double)((field0028 < 0.0)) * 0.2) * field0030;
        }
        else {
            field00b8 = 0.0;
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
        field0158 = 0;
        if ((field000a == 0) && ((unsigned short)field000c == 0)) {
            field0148 = field0148 + 0x14;
            field0030 =
            (2.0 - (*opponentSlot)->field0178 / 10000.0) *
            -1.8;
            if (field0120 != '\0') {
                field0118 = field0118 - 30.0;
            }
        }
        field0038 = 0.0;
        field0028 = 0.0;
        field0030 = field0030 + 0.06;
        if (field0030 > 0.0) {
            field0030 = 0.0;
        }
        if ((field0020 - 20.0 <= 0.0) ||
            (639.0 <= field0020 + 20.0)) {
            field00b8 =
            (1.0 - (double)((field0028 < 0.0)) * 0.2) * field0030;
        }
        else {
            field00b8 = 0.0;
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
        field0158 = 0;
        if ((field000a == 0) && ((unsigned short)field000c == 0)) {
            field0148 = field0148 + 10;
            field0030 =
            (2.0 - (*opponentSlot)->field0178 / 10000.0) *
            -1.1;
            if (field0120 != '\0') {
                field0118 = field0118 - 10.0;
            }
        }
        field0038 = 0.0;
        field0028 = 0.0;
        field0030 = field0030 + 0.06;
        if (field0030 > 0.0) {
            field0030 = 0.0;
        }
        if ((field0020 - 20.0 <= 0.0) ||
            (639.0 <= field0020 + 20.0)) {
            field00b8 =
            (1.0 - (double)((field0028 < 0.0)) * 0.2) * field0030;
        }
        else {
            field00b8 = 0.0;
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
        field0158 = 0;
        if ((field000a == 0) && ((unsigned short)field000c == 0)) {
            field0148 = field0148 + 0xf;
            field0030 =
            (2.0 - (*opponentSlot)->field0178 / 10000.0) *
            -1.5;
            if (field0120 != '\0') {
                field0118 = field0118 - 20.0;
            }
        }
        field0038 = 0.0;
        field0028 = 0.0;
        field0030 = field0030 + 0.06;
        if (field0030 > 0.0) {
            field0030 = 0.0;
        }
        if ((field0020 - 20.0 <= 0.0) ||
            (639.0 <= field0020 + 20.0)) {
            field00b8 =
            (1.0 - (double)((field0028 < 0.0)) * 0.2) * field0030;
        }
        else {
            field00b8 = 0.0;
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
        field0158 = 0;
        if ((field000a == 0) && ((unsigned short)field000c == 0)) {
            field0148 = field0148 + 0x14;
            field0030 =
            (2.0 - (*opponentSlot)->field0178 / 10000.0) *
            -1.8;
            if (field0120 != '\0') {
                field0118 = field0118 - 30.0;
            }
        }
        field0038 = 0.0;
        field0028 = 0.0;
        field0030 = field0030 + 0.06;
        if (field0030 > 0.0) {
            field0030 = 0.0;
        }
        if ((field0020 - 20.0 <= 0.0) ||
            (639.0 <= field0020 + 20.0)) {
            field00b8 =
            (1.0 - (double)((field0028 < 0.0)) * 0.2) * field0030;
        }
        else {
            field00b8 = 0.0;
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
            field0148 = field0148 + 0x1e;
            field0030 = field00c0;
            field0038 =
            field0038 * 0.75 + field00c8;
            if (field0038 < -2.0) {
                field0038 = -2.0;
            } else if (field0038 > -0.5) {
                field0038 = -0.5;
            }
            field0048 = 0.032;
        }
        if (field0038 <= 0.0) {
            field000a = 1;
            field000c = 0;
        }
        if ((field0038 >= 0.0) && (field000a <= 1)) {
            field000a = 2;
            field000c = 0;
        }
        field0038 = field0038 + field0048;
        ++field000c;
        if ((unsigned short)field000c >= frameDuration) {
            field000c = 0;
            ++field000a;
            if (field000a >= frameCount) {
                field000a = field000a + -2;
            }
        }
        if ((0.0 <= field0028 + field0038) &&
            (1 < field000a)) {
            field0028 = 0.0;
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
            field0148 = field0148 + 0x1e;
            field0030 = field00c0;
            field0038 =
            field0038 * 0.75 + field00c8;
            if (field0038 < -4.0) {
                field0038 = -4.0;
            } else if (field0038 > -0.5) {
                field0038 = -0.5;
            }
            field0048 = 0.032;
        }
        if (field0038 <= 0.0) {
            field000a = 1;
            field000c = 0;
        }
        if ((field0038 >= 0.0) && (field000a <= 1)) {
            field000a = 2;
            field000c = 0;
        }
        field0038 = field0038 + field0048;
        ++field000c;
        if ((unsigned short)field000c >= frameDuration) {
            field000c = 0;
            ++field000a;
            if (field000a >= frameCount) {
                field000a = field000a + -2;
            }
        }
        if ((0.0 <= field0028 + field0038) &&
            (1 < field000a)) {
            field0028 = 0.0;
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
            field0148 = field0148 + 0x1e;
            field0030 = field00c0;
            field0038 =
            field0038 * 0.75 + field00c8;
            if (field0038 < -6.0) {
                field0038 = -6.0;
            } else if (field0038 > -0.5) {
                field0038 = -0.5;
            }
            field0048 = 0.032;
        }
        if (field0038 <= 0.0) {
            field000a = 1;
            field000c = 0;
        }
        if ((field0038 >= 0.0) && (field000a <= 1)) {
            field000a = 2;
            field000c = 0;
        }
        field0038 = field0038 + field0048;
        ++field000c;
        if ((unsigned short)field000c >= frameDuration) {
            field000c = 0;
            ++field000a;
            if (field000a >= frameCount) {
                field000a = field000a + -2;
            }
        }
        if ((0.0 <= field0028 + field0038) &&
            (1 < field000a)) {
            field0028 = 0.0;
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
            field0148 = field0148 + 0x1e;
            field0030 = field00c0;
            field0038 =
            field0038 * 0.75 + field00c8;
            field0048 = 0.032;
        }
        if (field0038 <= 0.0) {
            field000a = 1;
            field000c = 0;
        }
        if ((field0038 >= 0.0) && (field000a <= 1)) {
            field000a = 2;
            field000c = 0;
        }
        field0038 = field0038 + field0048;
        ++field000c;
        if ((unsigned short)field000c >= frameDuration) {
            field000c = 0;
            ++field000a;
            if (field000a >= frameCount) {
                field000a = field000a + -2;
            }
        }
        if ((0.0 <= field0028 + field0038) &&
            (1 < field000a)) {
            field0028 = 0.0;
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
            field0148 = field0148 + 0x1e;
            field0030 = field00c0;
            field0038 = field00c8;
            field0048 = 0.032;
        }
        if (field0038 <= 0.0) {
            field000a = 1;
            field000c = 0;
        }
        if ((field0038 >= 0.0) && (field000a <= 1)) {
            field000a = 2;
            field000c = 0;
        }
        field0038 = field0038 + field0048;
        ++field000c;
        if ((unsigned short)field000c >= frameDuration) {
            field000c = 0;
            ++field000a;
            if (field000a >= frameCount) {
                field000a = field000a + -2;
            }
        }
        if ((0.0 <= field0028 + field0038) &&
            (1 < field000a)) {
            field0028 = 0.0;
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
            field0148 = field0148 + 0x1e;
            field0030 = field00c0;
            field0038 =
            field0038 * 0.75 + field00c8;
            if (field0038 < -2.0) {
                field0038 = -2.0;
            } else if (field0038 > -0.5) {
                field0038 = -0.5;
            }
            field0048 = 0.032;
        }
        if (field0038 <= 0.0) {
            field000a = 1;
            field000c = 0;
        }
        if ((field0038 >= 0.0) && (field000a <= 1)) {
            field000a = 2;
            field000c = 0;
        }
        field0038 = field0038 + field0048;
        ++field000c;
        if ((unsigned short)field000c >= frameDuration) {
            field000c = 0;
            ++field000a;
            if (field000a >= frameCount) {
                field000a = field000a + -2;
            }
        }
        if ((0.0 <= field0028 + field0038) &&
            (1 < field000a)) {
            field0028 = 0.0;
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
            field0148 = field0148 + 0x1e;
            field0030 = field00c0;
            field0038 =
            field0038 * 0.75 + field00c8;
            if (field0038 < -4.0) {
                field0038 = -4.0;
            } else if (field0038 > -0.5) {
                field0038 = -0.5;
            }
            field0048 = 0.032;
        }
        if (field0038 <= 0.0) {
            field000a = 1;
            field000c = 0;
        }
        if ((field0038 >= 0.0) && (field000a <= 1)) {
            field000a = 2;
            field000c = 0;
        }
        field0038 = field0038 + field0048;
        ++field000c;
        if ((unsigned short)field000c >= frameDuration) {
            field000c = 0;
            ++field000a;
            if (field000a >= frameCount) {
                field000a = field000a + -2;
            }
        }
        if ((0.0 <= field0028 + field0038) &&
            (1 < field000a)) {
            field0028 = 0.0;
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
            field0148 = field0148 + 0x1e;
            field0030 = field00c0;
            field0038 =
            field0038 * 0.75 + field00c8;
            field0048 = 0.032;
        }
        if (field0038 <= 0.0) {
            field000a = 1;
            field000c = 0;
        }
        if ((field0038 >= 0.0) && (field000a <= 1)) {
            field000a = 2;
            field000c = 0;
        }
        field0038 = field0038 + field0048;
        ++field000c;
        if ((unsigned short)field000c >= frameDuration) {
            field000c = 0;
            ++field000a;
            if (field000a >= frameCount) {
                field000a = field000a + -2;
            }
        }
        if ((0.0 <= field0028 + field0038) &&
            (1 < field000a)) {
            field0028 = 0.0;
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
            field0148 = field0148 + 0x1e;
            field0030 = field00c0;
            field0038 = field00c8;
            field0048 = 0.032;
        }
        if (field0038 <= 0.0) {
            field000a = 1;
            field000c = 0;
        }
        if ((field0038 >= 0.0) && (field000a <= 1)) {
            field000a = 2;
            field000c = 0;
        }
        field0038 = field0038 + field0048;
        ++field000c;
        if ((unsigned short)field000c >= frameDuration) {
            field000c = 0;
            ++field000a;
            if (field000a >= frameCount) {
                field000a = field000a + -2;
            }
        }
        if ((0.0 <= field0028 + field0038) &&
            (1 < field000a)) {
            field0028 = 0.0;
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
        field0148 = field0148 + 3;
        field0030 = field00c0;
        field0038 = field00c8;
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
        if (0.0 <= field0028 + field0038) {
            field0028 = 0.0;
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
        field0148 = field0148 + 3;
        field0030 = field00c0;
        field0038 = field00c8;
        ++field000c;
        if ((unsigned short)field000c >= frameDuration) {
            field000c = 0;
            ++field000a;
            if (field000a >= frameCount) {
                field000a = field000a + -2;
            }
        }
        if (0.0 <= field0028 + field0038) {
            field0028 = 0.0;
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
        if (((field000a == 0) && ((unsigned short)field000c == 0)) &&
            (field3138 == 0)) {
            field0148 = field0148 + 0x1e;
            ++field3138;
            field0124 = field0124 + 0x78;
            field0030 = 0.5;
            field0038 = -2.5;
            field0048 = 0.025;
            field02c9 = 0x1f;
            effect.type = 0;
            effect.x = (double)(int(field0020));
            effect.y = (double)(int(field0028));
            effect.group = 2;
            effect.layer = 1;
            contextOwner->EmitEffect(&effect);
        }
        field0038 = field0038 + field0048;
        ++field000c;
        if ((unsigned short)field000c >= frameDuration) {
            field000c = 0;
            ++field000a;
            if (field000a >= frameCount) {
                field000a = 0;
            }
        }
        if ((0.0 <= field0028 + field0038) &&
            (1 < field000a)) {
            field0028 = 0.0;
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
            field0148 = field0148 + 0x1e;
            field0030 = field00c0;
            field0038 = field00c8;
            field0048 = 0.072;
        }
        if (field0038 <= 0.0) {
            field000a = 1;
            field000c = 0;
        }
        if ((field0038 >= 0.0) && (field000a <= 1)) {
            field000a = 2;
            field000c = 0;
        }
        field0038 = field0038 + field0048;
        ++field000c;
        if ((unsigned short)field000c >= frameDuration) {
            field000c = 0;
            ++field000a;
            if (field000a >= frameCount) {
                field000a = field000a + -2;
            }
        }
        if ((0.0 <= field0028 + field0038) &&
            (1 < field000a)) {
            field0028 = 0.0;
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
        field0158 = 0;
        field0030 = 0.0;
        field0038 = 0.0;
        if ((field0020 - 20.0 <= 0.0) ||
            (639.0 <= field0020 + 20.0)) {
            field00b8 =
            (1.0 - (double)(((*opponentSlot)->field0028 < 0.0)) * 0.25) * field0030;
        }
        else {
            field00b8 = 0.0;
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
        field0158 = 0;
        field0030 = 0.0;
        field0038 = 0.0;
        if ((field0020 - 20.0 <= 0.0) ||
            (639.0 <= field0020 + 20.0)) {
            field00b8 =
            (1.0 - (double)(((*opponentSlot)->field0028 < 0.0)) * 0.25) * field0030;
        }
        else {
            field00b8 = 0.0;
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
        field0158 = 0;
        field0030 = 0.0;
        field0038 = 0.0;
        if ((field0020 - 20.0 <= 0.0) ||
            (639.0 <= field0020 + 20.0)) {
            field00b8 =
            (1.0 - (double)(((*opponentSlot)->field0028 < 0.0)) * 0.25) * field0030;
        }
        else {
            field00b8 = 0.0;
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
        field0158 = 0;
        if ((field000a == 0) && ((unsigned short)field000c == 0)) {
            field0148 = field0148 + 0x1e;
            if (field0120 != '\0') {
                field0118 = field0118 - 30.0;
            }
            field0030 = 2.2;
        }
        field0038 = 0.0;
        field0028 = 0.0;
        field0048 = 0.0;
        field0040 = 0.06;
        field0030 = field0030 - field0040;
        if (field0030 < 0.0) {
            field0030 = 0.0;
        }
        if ((field0020 - 20.0 <= 0.0) ||
            (639.0 <= field0020 + 20.0)) {
            field00b8 =
            (1.0 - (double)(((*opponentSlot)->field0028 < 0.0)) * 0.25) * field0030;
        }
        else {
            field00b8 = 0.0;
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
        field0158 = 0;
        if ((field000a == 0) && ((unsigned short)field000c == 0)) {
            field0148 = field0148 + 0x1e;
            if (field0120 != '\0') {
                field0118 = field0118 - 30.0;
            }
            field0030 = 2.2;
        }
        field0038 = 0.0;
        field0028 = 0.0;
        field0048 = 0.0;
        field0040 = 0.06;
        field0030 = field0030 - field0040;
        if (field0030 < 0.0) {
            field0030 = 0.0;
        }
        if ((field0020 - 20.0 <= 0.0) ||
            (639.0 <= field0020 + 20.0)) {
            field00b8 =
            (1.0 - (double)(((*opponentSlot)->field0028 < 0.0)) * 0.25) * field0030;
        }
        else {
            field00b8 = 0.0;
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
        field0158 = 0;
        if ((field000a == 0) && ((unsigned short)field000c == 0)) {
            field0148 = field0148 + 0x1e;
            if (field0120 != '\0') {
                field0118 = field0118 - 30.0;
            }
            field0030 = 2.2;
        }
        field0038 = 0.0;
        field0028 = 0.0;
        field0048 = 0.0;
        field0040 = 0.06;
        field0030 = field0030 - field0040;
        if (field0030 < 0.0) {
            field0030 = 0.0;
        }
        if ((field0020 - 20.0 <= 0.0) ||
            (639.0 <= field0020 + 20.0)) {
            field00b8 =
            (1.0 - (double)(((*opponentSlot)->field0028 < 0.0)) * 0.25) * field0030;
        }
        else {
            field00b8 = 0.0;
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
            effect.x = (double)(int(field0020));
            effect.y = (double)(int(field0028));
            effect.flag0018 = (unsigned char)facing;
            effect.layer = 1;
            EmitLocalEffect(&effect);
            field0148 = field0148 + 0x1e;
            field0030 = field00c0;
            field0038 = field00c8;
            field0048 = 0.032;
        }
        field0030 = field0030 + 0.02;
        field0038 = field0038 + field0048;
        if (field0030 > 0.0) {
            field0030 = 0.0;
        }
        ++field000c;
        if ((unsigned short)field000c >= frameDuration) {
            field000c = 0;
            ++field000a;
            if (field000a >= frameCount) {
                --field000a;
            }
        }
        if ((0.0 <= field0028 + field0038) &&
            (field000a == 1)) {
            field0028 = 0.0;
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
        if (((field000a == 0) && ((unsigned short)field000c == 0)) &&
            (field3138 == 0)) {
            field02c9 = 0x1e;
            field0038 = -0.45;
            field0030 = -0.1;
            ++field3138;
            field0148 = field0148 + 0x1e;
        }
        if ((field000a == 4) && ((unsigned short)field000c == 0)) {
            field0030 = field00c0;
            field0038 = field00c8;
            field0048 = 0.032;
        }
        if ((field0038 > 0.0) && (field000a == 4)) {
            field000a = 5;
            field000c = 0;
        }
        if (3 < field000a) {
            field0038 = field0038 + field0048;
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
        if ((0.0 <= field0028 + field0038) &&
            (4 < field000a)) {
            field0028 = 0.0;
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
                effect.x = (double)(int(field0020));
                effect.y = (double)(int(field0028));
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
            field0038 = -1.5;
            field0030 = -0.8;
            field0148 = field0148 + 0x1e;
        }
        field0038 = field0038 + 0.04;
        if (field000a == 0 && field0038 + field0028 > 0.0) {
            field0028 = 0.0;
            field0038 = 0.0;
            field000c = 0;
            field000a = 1;
            break;
        }
        if (field000a == 1) {
            field0030 = field0030 + 0.01;
        }
        if ((field000a == 2) && ((unsigned short)field000c == 0)) {
            field0030 = -2.0;
        }
        if (1 < field000a) {
            field0030 = field0030 + 0.06;
        }
        if (field0030 > 0.0) {
            field0030 = 0.0;
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
                effect.x = (double)(int(field0020));
                effect.y = (double)(int(field0028));
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
            field0038 = -1.5;
            field0030 = -0.8;
            field0148 = field0148 + 0x1e;
        }
        field0038 = field0038 + 0.04;
        if (field000a == 0 && field0038 + field0028 > 0.0) {
            field0028 = 0.0;
            field0038 = 0.0;
            field000c = 0;
            field000a = 1;
            break;
        }
        if (field000a == 1) {
            field0030 = field0030 + 0.01;
        }
        if ((field000a == 2) && ((unsigned short)field000c == 0)) {
            field0030 = -2.0;
        }
        if (1 < field000a) {
            field0030 = field0030 + 0.06;
        }
        if (field0030 > 0.0) {
            field0030 = 0.0;
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
                effect.x = (double)(int(field0020));
                effect.y = (double)(int(field0028));
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
            field0030 = field00c0;
            field0038 = field00c8;
            field0148 = field0148 + 0x1e;
        }
        field0038 = field0038 + 0.04;
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
        if (0.0 <= field0028 + field0038) {
            field0028 = 0.0;
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
                effect.x = (double)(int(field0020));
                effect.y = (double)(int(field0028));
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
                field0030 = field00c0;
                field0038 = field00c8;
                field0148 = field0148 + 0x1e;
                ++field3138;
            }
        }
        field0038 = field0038 + 0.06;
        ++field000c;
        if ((unsigned short)field000c >= frameDuration) {
            field000c = 0;
            ++field000a;
            if (field000a >= frameCount) {
                field000a = 0;
            }
        }
        if (0.0 <= field0028 + field0038) {
            field0028 = 0.0;
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
        field0030 = 0.0;
        field0038 = 0.0;
        if ((field000a == 0) && ((unsigned short)field000c == 0)) {
            SetVerticalShake(3,0);
            effect.type = 3;
            effect.x = (double)(int(field0020));
            effect.y = (double)(int(field0028));
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
        field0030 = 0.0;
        field0038 = 0.0;
        if ((field000a == 0) && ((unsigned short)field000c == 0)) {
            SetVerticalShake(3,0);
            effect.type = 3;
            effect.x = (double)(int(field0020));
            effect.y = (double)(int(field0028));
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
        if (inputY == '\x01') {
            field0008 = 0x99;
        }
        if (inputY != '\x01') {
            field0008 = 0x96;
        }
        if ((field000a == 0) && ((unsigned short)field000c == 0)) {
            field0158 = 0;
            field0148 = field0148 + 10;
            field0030 = -1.5;
            field0038 = 0.0;
            field0028 = 0.0;
        }
        field0038 = 0.0;
        field0030 = field0030 + 0.06;
        if (field0030 > 0.0) {
            field0030 = 0.0;
        }
        if ((field0020 - 20.0 <= 0.0) ||
            (639.0 <= field0020 + 20.0)) {
            field00b8 = field0030;
        }
        else {
            field00b8 = 0.0;
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
            field0158 = 0;
            field0148 = field0148 + 0xf;
            field0030 = -1.8;
            field0038 = 0.0;
            field0028 = 0.0;
        }
        field0038 = 0.0;
        field0030 = field0030 + 0.06;
        if (field0030 > 0.0) {
            field0030 = 0.0;
        }
        if ((field0020 - 20.0 <= 0.0) ||
            (639.0 <= field0020 + 20.0)) {
            field00b8 = field0030;
        }
        else {
            field00b8 = 0.0;
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
            field0158 = 0;
            field0148 = field0148 + 0x14;
            field0030 = -2.3;
            field0038 = 0.0;
            field0028 = 0.0;
        }
        field0038 = 0.0;
        field0030 = field0030 + 0.06;
        if (field0030 > 0.0) {
            field0030 = 0.0;
        }
        if ((field0020 - 20.0 <= 0.0) ||
            (639.0 <= field0020 + 20.0)) {
            field00b8 = field0030;
        }
        else {
            field00b8 = 0.0;
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
            field0158 = 0;
            field0148 = field0148 + 10;
            field0030 = -1.5;
            field0038 = 0.0;
            field0028 = 0.0;
        }
        field0038 = 0.0;
        field0030 = field0030 + 0.06;
        if (field0030 > 0.0) {
            field0030 = 0.0;
        }
        if ((field0020 - 20.0 <= 0.0) ||
            (639.0 <= field0020 + 20.0)) {
            field00b8 = field0030;
        }
        else {
            field00b8 = 0.0;
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
            field0158 = 0;
            field0148 = field0148 + 0xf;
            field0030 = -1.8;
            field0038 = 0.0;
            field0028 = 0.0;
        }
        field0038 = 0.0;
        field0030 = field0030 + 0.06;
        if (field0030 > 0.0) {
            field0030 = 0.0;
        }
        if ((field0020 - 20.0 <= 0.0) ||
            (639.0 <= field0020 + 20.0)) {
            field00b8 = field0030;
        }
        else {
            field00b8 = 0.0;
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
            field0158 = 0;
            field0148 = field0148 + 0x14;
            field0030 = -2.3;
            field0038 = 0.0;
            field0028 = 0.0;
        }
        field0038 = 0.0;
        field0030 = field0030 + 0.06;
        if (field0030 > 0.0) {
            field0030 = 0.0;
        }
        if ((field0020 - 20.0 <= 0.0) ||
            (639.0 <= field0020 + 20.0)) {
            field00b8 = field0030;
        }
        else {
            field00b8 = 0.0;
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
            field0038 = -2.6;
            field0148 = field0148 + 0xf;
            field0048 = 0.06;
        }
        field0030 = -1.2;
        field0038 = field0038 + field0048;
        ++field000c;
        if ((unsigned short)field000c >= frameDuration) {
            field000c = 0;
            ++field000a;
            if (field000a >= frameCount) {
                field0008 = 9;
                ResetPose();
            }
        }
        if (0.0 <= field0028 + field0038) {
            field0028 = 0.0;
            field02c9 = 9;
            FaceOpponent();
            field0008 = 0xd;
            ResetPose();
        }
        break;
    case 157:
        field0030 = 1.0;
        field0048 = 0.045;
        field0158 = 0;
        if ((field000a == 0) && ((unsigned short)field000c == 0)) {
            field0038 = -2.3;
            effect.type = 8;
            effect.x = (double)(int(field0020));
            effect.y = (double)(int(field0028));
            effect.group = 2;
            effect.layer = 0;
            contextOwner->EmitEffect(&effect);
        }
        else {
            field0038 = field0038 + field0048;
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
        if (0.0 <= field0028 + field0038) {
            field0028 = 0.0;
            field02c9 = 9;
            FaceOpponent();
            field0008 = 0xd;
            ResetPose();
        }
        break;
    case 158:
        field0030 = -1.0;
        field0048 = 0.045;
        field0158 = 0;
        if ((field000a == 0) && ((unsigned short)field000c == 0)) {
            field0038 = -2.3;
            effect.type = 8;
            effect.x = (double)(int(field0020));
            effect.y = (double)(int(field0028));
            effect.group = 2;
            effect.layer = 0;
            contextOwner->EmitEffect(&effect);
        }
        else {
            field0038 = field0038 + field0048;
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
        if (0.0 <= field0028 + field0038) {
            field0028 = 0.0;
            field02c9 = 9;
            FaceOpponent();
            field0008 = 0xd;
            ResetPose();
        }
        break;
    case 161:
        if ((field000a == 0) && ((unsigned short)field000c == 0)) {
            ResetFrame();
            effect.type = 9;
            effect.x = (double)(int(field0020));
            effect.y = (double)((int(field0028)) + -0x3c);
            effect.group = 2;
            effect.layer = 1;
            contextOwner->EmitEffect(&effect);
            field016c = 1;
            field02c9 = 0x3e;
            ++field3138;
        }
        ++field000c;
        if ((unsigned short)field000c >= frameDuration) {
            field000c = 0;
            ++field000a;
            if (field000a >= frameCount) {
                field0008 = 9;
                ResetPose();
                field0048 = 0.035;
            }
        }
        break;
    case 162:
        if ((field000a == 0) && ((unsigned short)field000c == 0)) {
            ResetFrame();
        }
        if ((field000a == 3) && ((unsigned short)field000c == 0)) {
            field0038 = -1.5;
            field0048 = 0.025;
            field016c = 1;
        }
        if ((field000a == 6) && ((unsigned short)field000c == 0)) {
            ResetFrame();
            effect.type = 9;
            effect.x = (double)(int(field0020));
            effect.y = (double)((int(field0028)) + -0x3c);
            effect.group = 2;
            effect.layer = 1;
            contextOwner->EmitEffect(&effect);
            field016c = 1;
            field02c9 = 0x3e;
            field0148 = field0148 + -1000;
            ++field3138;
        }
        field0038 = field0038 + field0048;
        if (field0028 + field0038 > 0.0) {
            field0008 = 0xd;
            ResetPose();
            ResetPose();
            field0028 = 0.0;
            break;
        }
        ++field000c;
        if ((unsigned short)field000c >= frameDuration) {
            field000c = 0;
            ++field000a;
            if (field000a == 0x12) {
                field0048 = 0.035;
            }
            if (field000a >= frameCount) {
                field000a = field000a + -2;
            }
        }
        break;
    case 163:
        if ((field000a == 0) && ((unsigned short)field000c == 0)) {
            StartTrail(3);
            ResetFrame();
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
        if ((field000a < 5) &&
            ((2 < field000a &&
            (field0030 = 2.0, field3138 == 0)))) {
            field02c9 = 0x11;
        }
        field0158 = 1;
        ++field3138;
        ++field000c;
        if ((unsigned short)field000c >= frameDuration) {
            field000c = 0;
            ++field000a;
            if (field000a == 5) {
                field000a = field000a + -2;
            }
            if (field000a >= frameCount) {
                field0008 = 0;
                ResetPose();
                return;
            }
        }
        if (((inputX == facing) && (field3138 >= 120)) &&
            (field000a < 5)) {
            field0008 = 0xb2;
            ResetPose();
        }
        if (((inputX != facing) && (field3138 >= 60)) &&
            (field000a < 5)) {
            field0008 = 0xb2;
            ResetPose();
        }
        break;
    case 164:
        StartTrail(2);
        field0158 = 0;
        if (((field000a == 0) && ((unsigned short)field000c == 0)) &&
            (field3138 == 0)) {
            field0030 = -3.1;
            field0038 = 0.0;
            field0048 = 0.0;
            field3138 = 1;
            field02c9 = 0x11;
        }
        if (field000a > -1) { field0030 = field0030 + 0.04; }
        if (field0030 >= 0.0 && field000a > -1) {
            field0030 = 0.0;
            field0038 = 0.0;
            field0008 = 0;
            ResetPose();
            break;
        }
        ++field000c;
        if ((unsigned short)field000c >= frameDuration) {
            field000c = 0;
            ++field000a;
            if ((field000a == 2) && (field0030 < -2.2))
            {
                field000a = field000a + -2;
            }
            if (field000a >= frameCount) {
                field000a = 2;
            }
        }
        break;
    case 165:
        if (((field000a == 0) && ((unsigned short)field000c == 0)) &&
            (field3138 == 0)) {
            field0030 = 2.0;
            StartTrail(3);
            field0038 = 0.0;
            field0048 = 0.0;
            field02c9 = 0x11;
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
            field0030 = 1.3;
            field0048 = 0.03;
            if ((FaceOpponent()) != 0) {
                field0030 = -field0030;
            }
        }
        if ((inputX != facing) && (field3138 >= 39)) {
            field0008 = 9;
            ResetPose();
            field0030 = 1.3;
            field0048 = 0.03;
            if ((FaceOpponent()) != 0) {
                field0030 = -field0030;
            }
        }
        break;
    case 166:
        if (((field000a == 0) && ((unsigned short)field000c == 0)) &&
            (field3138 == 0)) {
            field0030 = -2.0;
            field0038 = 0.0;
            field0048 = 0.0;
            StartTrail(3);
            field02c9 = 0x11;
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
            field0030 = -0.9;
            field0048 = 0.03;
            if ((FaceOpponent()) != 0) {
                field0030 = -field0030;
            }
        }
        if (((int)inputX != -(int)facing) && (field3138 >= 48)) {
            field0008 = 9;
            ResetPose();
            field0030 = -0.9;
            field0048 = 0.03;
            if ((FaceOpponent()) != 0) {
                field0030 = -field0030;
            }
        }
        break;
    case 167:
        if ((field000a == 0) && ((unsigned short)field000c == 0)) {
            field0158 = 0;
            field0030 = 0.0;
            field0038 = 0.0;
            if (field0120 == '\x01') {
                field0178 =
                field0118 * 5.0 + field0178;
            }
            field0118 = 0.0;
            field014c = 0x5a;
            SetTint(0xb0,3);
        }
        if ((field000a == 1) && ((unsigned short)field000c == 0)) {
            field02c9 = 0x12;
            effect.type = 1;
            effect.x = (double)(int(field0020));
            effect.y = (double)(int(field0028));
            effect.group = 2;
            effect.layer = 1;
            contextOwner->EmitEffect(&effect);
        }
        if ((field000a == 2) && ((unsigned short)field000c == 0)) {
            effect.type = 4;
            effect.x = (double)(int(field0020));
            effect.y = (double)(int(field0028));
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
            field0158 = 0;
            field0030 = 0.0;
            field0038 = 0.0;
            field0028 = 0.0;
            field0048 = 0.0;
            field014e = 0;
            field00b8 = 0.0;
            field0040 = 0.0;
            effect.type = 8;
            effect.x = (double)(int(field0020));
            effect.y = (double)(int(field0028));
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
            field0158 = 0;
            field0030 = 0.0;
            field0038 = 0.0;
            field0028 = 0.0;
            field0048 = 0.0;
            field014e = 0;
            field00b8 = 0.0;
            field0040 = 0.0;
            effect.type = 8;
            effect.x = (double)(int(field0020));
            effect.y = (double)(int(field0028));
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
            field3138 = (int(field0030 * 100.0));
            field313c = (int(field0038 * 100.0));
            field0030 = 0.0;
            field0038 = 0.0;
            if (field0048 == 0.0) {
                field0048 = 0.035;
            }
            field014e = 0;
            field00b8 = 0.0;
            field014c = 0x3c;
        }
        if ((field014c == 0) && (field3140 == 0)) {
            ++field3140;
            field0030 = (double)field3138 * 0.01;
            field0038 = (double)field313c * 0.01;
        }
        if (field014c == 0) {
            field0038 = field0038 + field0048;
        }
        if (field0038 + field0028 > 0.0) {
            ResetFrame();
            field0028 = 0.0;
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
            field3138 = (int(field0030 * 100.0));
            field313c = (int(field0038 * 100.0));
            field0030 = 0.0;
            field0038 = 0.0;
            if (field0120 == '\x01') {
                field0178 =
                field0118 * 5.0 + field0178;
            }
            field0118 = 0.0;
            field014c = 0x5a;
            SetTint(0xb0,3);
        }
        if ((field000a == 1) && ((unsigned short)field000c == 0)) {
            field02c9 = 0x12;
            effect.type = 1;
            effect.x = (double)(int(field0020));
            effect.y = (double)(int(field0028));
            effect.group = 2;
            effect.layer = 1;
            contextOwner->EmitEffect(&effect);
        }
        if ((field000a == 2) && ((unsigned short)field000c == 0)) {
            effect.type = 4;
            effect.x = (double)(int(field0020));
            effect.y = (double)(int(field0028));
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
                field0030 = (double)field3138 * 0.01;
                field0038 = (double)field313c * 0.01;
                field0048 = 0.035;
                ResetPose();
            }
        }
        break;
    case 178:
        field0030 = field0030 - 0.03;
        field0030 = field0030;
        if (field0030 < 0.0) {
            field0030 = 0.0;
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
            if (field000a >= frameCount) {
                field0008 = 0;
                ResetPose();
                break;
            }
        }
        break;
    case 180:
        if ((field000a == 0) && ((unsigned short)field000c == 0)) {
            StartTrail(2);
            field0030 = 0.0;
            field0038 = 0.0;
            field0048 = 0.0;
        }
        if (field0028 < 0.0) {
            field0038 = field0038 + field0048;
        }
        if ((0.0 < field0028 + field0038) &&
            (field000a < 10)) {
            ResetFrame();
            field0028 = 0.0;
            field000c = 0;
            field000a = 10;
            field02c9 = 9;
        }
        ++field000c;
        if ((unsigned short)field000c >= frameDuration) {
            field000c = 0;
            ++field000a;
            if (field000a == 3) {
                field0030 = -0.5;
                field0038 = -1.0;
                field0048 = 0.028;
            }
            if (field000a == 10) {
                field000a = field000a + -2;
            }
            if (field000a >= frameCount) {
                ResetPose();
                field0008 = 0;
            }
        }
        break;
    case 200:
        if ((unsigned char)field0158 == '\0') {
            field0030 = 0.0;
            field0038 = 0.0;
        }
        if (field0030 > 0.0 && (unsigned char)field0158 == 1) {
            field0030 = field0030 - 0.06;
        } else {
            field0030 = 0.0;
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
        if ((unsigned char)field0158 == '\0') {
            field0030 = 0.0;
            field0038 = 0.0;
        }
        if (field0030 > 0.0 && (unsigned char)field0158 == 1) {
            field0030 = field0030 - 0.03;
        } else {
            field0030 = 0.0;
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
        if ((field000a == 3) && ((unsigned short)field000c == 0)) {
            field0148 = field0148 + 0xf;
            field02c9 = 0x14;
            field016c = 1;
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
    case 202:
        if ((unsigned char)field0158 == '\0') {
            field0030 = 0.0;
            field0038 = 0.0;
        }
        if (field0030 > 0.0 && (unsigned char)field0158 == 1) {
            field0030 = field0030 - 0.06;
        } else {
            field0030 = 0.0;
            field0158 = 0;
        }
        if ((field000a == 4) && ((unsigned short)field000c == 0)) {
            field0148 = field0148 + 0xf;
            field02c9 = 0x14;
            field016c = 1;
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
    case 203:
        if ((unsigned char)field0158 == '\0') {
            field0030 = 0.0;
            field0038 = 0.0;
        }
        if (field0030 > 0.0 && (unsigned char)field0158 == 1) {
            field0030 = field0030 - 0.06;
        } else {
            field0030 = 0.0;
            field0158 = 0;
        }
        if ((((inputY == -1) && (field000a > 0)) &&
            (field015c < 3)) && (field0168 == 3)) {
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
        if ((field000a == 4) && ((unsigned short)field000c == 0)) {
            field0148 = field0148 + 0x23;
            field02c9 = 0x12;
            field016c = 1;
            effect.type = 400;
            effect.x = (double)((int(field0020)) + facing * 0xf);
            effect.y = (double)(int(field0028));
            effect.group = 2;
            effect.palette = 1;
            effect.layer = 1;
            effect.flag0018 = (unsigned char)facing;
            EmitLocalEffect(&effect);
        }
        ++field000c;
        if ((unsigned short)field000c >= frameDuration) {
            field000c = 0;
            ++field000a;
            if (field000a < 3) {
                field0168 = 0;
            }
            if ((field000a == 8) && (field313c < 2)) {
                ++field313c;
                field000a = 5;
            }
            if (field000a >= frameCount) {
                field0008 = 0;
                FaceOpponent();
                ResetPose();
            }
        }
        break;
    case 204:
        if ((unsigned char)field0158 == '\0') {
            field0030 = 0.0;
            field0038 = 0.0;
        }
        if (field0030 > 0.0 && (unsigned char)field0158 == 1) {
            field0030 = field0030 - 0.03;
        } else {
            field0030 = 0.0;
            field0158 = 0;
        }
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
        if ((field000a == 1) && ((unsigned short)field000c == 0)) {
            field0148 = field0148 + 5;
            field02c9 = 0x15;
            field016c = 1;
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
        if ((unsigned char)field0158 == '\0') {
            field0030 = 0.0;
            field0038 = 0.0;
        }
        if (field0030 > 0.0 && (unsigned char)field0158 == 1) {
            field0030 = field0030 - 0.03;
        } else {
            field0030 = 0.0;
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
    case 206:
        if ((((unsigned char)field0158 == '\0') && (field000a == 0)) &&
            ((unsigned short)field000c == 0)) {
            field0030 = 0.0;
            field0038 = 0.0;
        }
        if (field0030 > 0.0 && (unsigned char)field0158 == 1 && field000a < 3) {
            field0030 = field0030 - 0.03;
        } else {
            field0158 = 0;
        }
        if (field0030 < 0.0) {
            field0030 = 0.0;
        }
        if ((field000a == 1) && ((unsigned short)field000c == 0)) {
            field016c = 1;
        }
        if (((field000a == 3) && ((unsigned short)field000c == 0)) &&
            (field3138 == 0)) {
            field0148 = field0148 + 0x19;
            field02c9 = 0x14;
            field0030 = 4.5;
            ++field3138;
        }
        if (field0030 > 0.0) {
            field0030 = field0030 - 0.08;
        }
        ++field000c;
        if ((unsigned short)field000c >= frameDuration) {
            field000c = 0;
            ++field000a;
            field0168 = 0;
            if ((field000a == 5) && (field0030 > 0.6)) {
                field000a = 3;
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
        field0038 = field0038 + field0048;
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
        if ((field000a == 2) && ((unsigned short)field000c == 0)) {
            field0148 = field0148 + 5;
            field02c9 = 0x15;
            field016c = 1;
        }
        if (field0028 + field0038 >= 0.0) {
            field0028 = 0.0;
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
                field0008 = 9;
                ResetPose();
            }
        }
        break;
    case 208:
        field0038 = field0038 + field0048;
        if (((inputY == -1) && (field000a > 0)) &&
            ((field015c < 3 && ((field0168 >= 2 && (field015a == '\0')))))
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
            field016c = 1;
        }
        if (field0028 + field0038 >= 0.0) {
            field0028 = 0.0;
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
    case 209:
        field0038 = field0038 + field0048;
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
        if ((field000a == 2) && ((unsigned short)field000c == 0)) {
            field0148 = field0148 + 0x1e;
            field02c9 = 0x14;
            field016c = 1;
        }
        if (field0028 + field0038 >= 0.0) {
            field0028 = 0.0;
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
                field0008 = 9;
                ResetPose();
            }
        }
        break;
    case 210:
        if ((field000a == 0) && ((unsigned short)field000c == 0)) {
            field0030 = 0.0;
            field0038 = 0.0;
        }
        if ((field000a == 1) && ((unsigned short)field000c == 0)) {
            field0030 = 1.4;
            field0038 = -1.5;
            field0048 = 0.08;
        }
        if ((field000a == 2) && ((unsigned short)field000c == 0)) {
            field0148 = field0148 + 0xf;
            field02c9 = 0x14;
            field016c = 1;
        }
        if ((field000a == 5) && ((unsigned short)field000c == 0)) {
            field0030 = 0.0;
            field0038 = 0.0;
            field0048 = 0.0;
        }
        if (field000a > 0) {
            field0038 = field0038 + field0048;
        }
        ++field000c;
        if ((unsigned short)field000c >= frameDuration) {
            field000c = 0;
            ++field000a;
            field0168 = 0;
            if (field000a == 5) {
                if (field0028 + field0038 < 0.0) {
                    --field000a;
                } else {
                    field0028 = 0.0;
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
            field0030 = 0.0;
            field0038 = 0.0;
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
        field0038 = field0038 + field0048;
        if ((field000a == 0) && ((unsigned short)field000c == 0)) {
            field0148 = field0148 + 0x1e;
            field02c9 = 0x14;
            field016c = 1;
            field0030 = field0030 / 2.0;
            field0048 = 0.07;
        }
        if (field0168 > 1) {
            field0008 = 0xd5;
            ResetPose();
            ResetFrame();
            break;
        }
        if (field0028 + field0038 >= 0.0) {
            field0028 = 0.0;
            field0038 = 0.0;
            SetVerticalShake(3,0);
            effect.type = 3;
            effect.x = (double)(int(field0020));
            effect.y = (double)(int(field0028));
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
        field0048 = 0.042;
        field0038 = field0038 + field0048;
        if ((field000a == 0) && ((unsigned short)field000c == 0)) {
            field0030 = -1.0;
            field0038 = -2.4;
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
        field0030 = 0.0;
        field0038 = 0.0;
        if ((field000a == 0) && ((unsigned short)field000c == 0)) {
            SetVerticalShake(3,0);
            effect.type = 3;
            effect.x = (double)(int(field0020));
            effect.y = (double)(int(field0028));
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
        field0030 = 0.0;
        field0038 = 0.0;
        if (((field000a == 1) && ((unsigned short)field000c == 0)) &&
            ((*opponentSlot)->field0028 == 0.0)) {
            field016c = 1;
        }
        else {
            field016c = 0;
        }
        if ((field000a == 1) && (field0168 == 3)) {
            field0030 = 0.0;
            field0038 = 0.0;
            ResetPose();
            ResetFrame();
            (*opponentSlot)->ResetFrame();
            (*opponentSlot)->ResetPose();
            field0008 = 0xdd;
            (*opponentSlot)->field0128 = 1;
            effect.type = 0;
            effect.x = (double)((int(field0020)) + facing * 0x25);
            effect.y = (double)((int(field0028)) + -0x2a);
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
        if ((field000a == 4) && ((unsigned short)field000c == 0)) {
            ApplyDamage(0x4e2,750.0);
        }
        ++field000c;
        if ((unsigned short)field000c >= frameDuration) {
            field000c = 0;
            ++field000a;
            field0168 = 0;
            if (field000a == 1) {
                (*opponentSlot)->field0008 = 0x67;
                (*opponentSlot)->ResetFrame();
                (*opponentSlot)->ResetPose();
                (*opponentSlot)->field0028 = -86.0;
                (*opponentSlot)->field0020 =
                (double)(facing * 0x29) + field0020;
            }
            if (field000a == 2) {
                (*opponentSlot)->field0028 = -97.0;
                (*opponentSlot)->field0020 =
                (double)(facing * 0x24) + field0020;
            }
            if (field000a == 3) {
                (*opponentSlot)->field0028 = -97.0;
                (*opponentSlot)->field0020 =
                (double)(facing * 0x22) + field0020;
                (*opponentSlot)->facing = -facing;
            }
            if (field000a == 4) {
                (*opponentSlot)->field0028 = 0.0;
                (*opponentSlot)->field0020 =
                (double)(facing * 0x24) + field0020;
                (*opponentSlot)->facing = -facing;
                SetVerticalShake(3,0);
                (*opponentSlot)->field0008 = 0x61;
                (*opponentSlot)->ResetFrame();
                (*opponentSlot)->ResetPose();
            }
            if (field000a >= frameCount) {
                field0008 = 0;
                FaceOpponent();
                ResetPose();
            }
        }
        break;
    case 230:
        StartTrail(3);
        field0158 = 0;
        field0030 = field0030 - 0.03;
        if (field0030 < 0.0) {
            field0030 = 0.0;
        }
        if ((field000a == 0) && ((unsigned short)field000c == 0)) {
            field0030 = 2.0;
            field0038 = 0.0;
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
            if (field000a < 3) {
                field0168 = 0;
            }
            if (field000a >= frameCount) {
                field0008 = 0;
                ResetPose();
            }
        }
        break;
    case 231:
        StartTrail(3);
        field0158 = 0;
        field0030 = field0030 - 0.03;
        if (field0030 < 0.0) {
            field0030 = 0.0;
        }
        if ((field000a == 0) && ((unsigned short)field000c == 0)) {
            field0038 = 0.0;
            field0030 = 2.0;
        }
        if ((field000a == 2) && ((unsigned short)field000c == 0)) {
            field0148 = field0148 + 10;
            field02c9 = 0x14;
            field016c = 1;
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
                ResetPose();
            }
        }
        break;
    case 232:
        StartTrail(3);
        field0158 = 0;
        if (field000a < 3) {
            if ((unsigned char)field0158 == '\0') {
                field0030 = 0.0;
            }
            if (field0030 > 0.0 && (unsigned char)field0158 == 1) {
                field0030 = field0030 - 0.06;
            } else {
                field0030 = 0.0;
                field0158 = 0;
            }
        }
        if ((field000a == 3) && ((unsigned short)field000c == 0)) {
            field02c9 = 0x14;
            field0030 = 3.0;
            field016c = 1;
            field0148 = field0148 + 0x23;
        }
        field0030 = field0030 - (double)((field0030 > 0.0)) * 0.07;
        if (field0030 < 0.0) {
            field0030 = 0.0;
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
                ResetPose();
            }
        }
        break;
    case 233:
        StartTrail(3);
        field0030 = field0030 - 0.03;
        field0158 = 0;
        if (field0030 < 0.0) {
            field0030 = 0.0;
        }
        if ((field000a == 0) && ((unsigned short)field000c == 0)) {
            field0030 = 2.0;
            field0038 = 0.0;
        }
        if ((field000a == 1) && ((unsigned short)field000c == 0)) {
            field0148 = field0148 + 5;
            field02c9 = 0x15;
            field016c = 1;
        }
        ++field000c;
        if ((unsigned short)field000c >= frameDuration) {
            field000c = 0;
            ++field000a;
            if (field000a < 5) {
                field0168 = 0;
            }
            if (field000a >= frameCount) {
                field0008 = 3;
                ResetPose();
            }
        }
        break;
    case 234:
        StartTrail(3);
        field0030 = field0030 - 0.03;
        field0158 = 0;
        if (field0030 < 0.0) {
            field0030 = 0.0;
        }
        if ((field000a == 0) && ((unsigned short)field000c == 0)) {
            field0038 = 0.0;
            field0030 = 2.0;
        }
        if ((field000a == 2) && ((unsigned short)field000c == 0)) {
            field0148 = field0148 + 10;
            field02c9 = 0x14;
            field016c = 1;
        }
        ++field000c;
        if ((unsigned short)field000c >= frameDuration) {
            field000c = 0;
            ++field000a;
            if (field000a < 3) {
                field0168 = 0;
            }
            if (field000a >= frameCount) {
                field0008 = 3;
                ResetPose();
            }
        }
        break;
    case 235:
        StartTrail(3);
        field0158 = 0;
        if (field000a < 3) {
            if ((unsigned char)field0158 == '\0') {
                field0030 = 0.0;
            }
            if (field0030 > 0.0 && (unsigned char)field0158 == 1) {
                field0030 = field0030 - 0.06;
            } else {
                field0030 = 0.0;
                field0158 = 0;
            }
        }
        if (((2 < field000a) && (field000a < 0xf)) &&
            (field0038 = field0038 + field0048,
            0.0 < field0038 + field0028)) {
            field000c = 0;
            ResetFrame();
            field0028 = 0.0;
            field000a = 0xf;
        }
        if ((field000a == 7) && ((unsigned short)field000c == 0)) {
            field02c9 = 0x14;
            field016c = 1;
            field0148 = field0148 + 0x23;
        }
        ++field000c;
        if ((unsigned short)field000c >= frameDuration) {
            field000c = 0;
            ++field000a;
            if (field000a < 3) {
                field0168 = 0;
            }
            if (field000a == 3) {
                field0030 = 1.5;
                field0038 = -1.5;
                field0048 = 0.032;
            }
            if (field000a >= frameCount) {
                field0008 = 0;
                ResetPose();
            }
        }
        break;
    case 236:
        StartTrail(3);
        field0158 = 0;
        if (field000a < 3) {
            if ((unsigned char)field0158 == '\0') {
                field0030 = 0.0;
            }
            if (field0030 > 0.0 && (unsigned char)field0158 == 1) {
                field0030 = field0030 - 0.06;
            } else {
                field0030 = 0.0;
                field0158 = 0;
            }
        }
        if (((2 < field000a) && (field000a < 0xf)) &&
            (field0038 = field0038 + field0048,
            0.0 < field0038 + field0028)) {
            field000c = 0;
            ResetFrame();
            field0028 = 0.0;
            field000a = 0xf;
        }
        if ((field000a == 7) && ((unsigned short)field000c == 0)) {
            field02c9 = 0x14;
            field016c = 1;
            field0148 = field0148 + 0x23;
        }
        ++field000c;
        if ((unsigned short)field000c >= frameDuration) {
            field000c = 0;
            ++field000a;
            if (field000a < 3) {
                field0168 = 0;
            }
            if (field000a == 3) {
                field0030 = 1.5;
                field0038 = -1.5;
                field0048 = 0.032;
            }
            if (field000a >= frameCount) {
                field0008 = 0;
                ResetPose();
            }
        }
        break;
    case 248:
        field0038 = field0038 + field0048;
        if ((field000a == 1) && (field0168 == 3)) {
            (*opponentSlot)->ResetFrame();
            (*opponentSlot)->ResetPose();
            ResetFrame();
            (*opponentSlot)->field0128 = 1;
            effect.type = 0;
            effect.x = (double)((int(field0020)) + facing * 0x36);
            effect.y = (double)((int(field0028)) + -0x54);
            effect.group = 2;
            effect.layer = 1;
            contextOwner->EmitEffect(&effect);
            field000a = 0;
            field000c = 0;
            field0008 = 0xf9;
            (*opponentSlot)->field0008 = 100;
            (*opponentSlot)->field0028 = field0028 - 61.0;
            (*opponentSlot)->field0020 =
            (double)(facing * 0x13) + field0020;
            break;
        }
        ++field000c;
        if ((unsigned short)field000c >= frameDuration) {
            field000c = 0;
            ++field000a;
            if (field000a == 1 && (*opponentSlot)->field0028 < 0.0 &&
                ((*opponentSlot)->field0008 < 50 || (*opponentSlot)->field0008 > 149)) {
                field016c = 1;
            } else { field016c = 0; }
            field0168 = 0;
            if (field000a >= frameCount) {
                field0008 = 0xd1;
                field000a = 2;
            }
        }
        break;
    case 249:
        field0158 = 0;
        ++field000c;
        if ((unsigned short)field000c >= frameDuration) {
            field000c = 0;
            ++field000a;
            field0168 = 0;
            if (field000a == 1) {
                (*opponentSlot)->field0008 = 100;
                (*opponentSlot)->field0028 = field0028 - 59.0;
                (*opponentSlot)->field0020 =
                (double)(facing * 0xf) + field0020;
            }
            if (field000a == 2) {
                (*opponentSlot)->field0028 = field0028 - 67.0;
                (*opponentSlot)->field0020 =
                (double)(facing * 0xb) + field0020;
            }
            if (field000a == 3) {
                (*opponentSlot)->field0028 = field0028 - 64.0;
                (*opponentSlot)->field0020 = field0020;
            }
            if (field000a == 4) {
                (*opponentSlot)->field0008 = 0x65;
                (*opponentSlot)->field0028 = field0028 - 66.0;
                (*opponentSlot)->field0020 =
                field0020 - (double)(facing * 0x16);
                (*opponentSlot)->facing = -facing;
            }
            if (field000a == 5) {
                (*opponentSlot)->field0028 = field0028 - 59.0;
                (*opponentSlot)->field0020 =
                field0020 - (double)((int)facing << 4);
            }
            if (field000a == 6) {
                (*opponentSlot)->ResetPose();
                (*opponentSlot)->field0008 = 0x3c;
                (*opponentSlot)->field00c0 = 2.2;
                (*opponentSlot)->field00c8 = -1.0;
                (*opponentSlot)->field0048 = 0.035;
                ApplyDamage(0x514,500.0);
                --field0174;
                --field00f4;
                (*opponentSlot)->field0128 = 1;
                (*opponentSlot)->field0028 = field0028 - 69.0;
                (*opponentSlot)->field0020 =
                field0020 - (double)(facing * 0x27);
            }
            if (field000a >= frameCount) {
                facing = -facing;
                field0048 = 0.035;
                field0008 = 0xfd;
                ResetPose();
            }
        }
        break;
    case 250:
        if ((field000a == 0) && ((unsigned short)field000c == 0)) {
            field0158 = 0;
            if (field0028 == 0.0) {
                field0030 = 0.0;
                field0038 = 0.0;
            }
            field0148 = field0148 + 0x2d;
            field016c = 0;
            if (field0028 < 0.0) {
                field000a = 2;
                field000c = 0;
            }
        }
        if ((field000a == 6) && ((unsigned short)field000c == 0)) {
            if (field0028 == 0.0) {
                effect.type = 0x1f;
                effect.x = (double)(int(field0020));
                effect.y = (double)(int(field0028));
                effect.group = 0;
                effect.layer = 1;
                effect.facing = (facing != '\x01');
                contextOwner->EmitEffect(&effect);
            }
            field016c = 0;
        }
        if ((field000a == 6) && ((unsigned short)field000c == 0)) {
            effect.type = 8;
            effect.x = (double)(int(field0020));
            effect.y = (double)(int(field0028));
            effect.group = 2;
            effect.layer = 1;
            contextOwner->EmitEffect(&effect);
            field0030 = 1.4;
            field0038 = -1.5;
            field0048 = 0.03;
        }
        if (((5 < field000a) && (field0038 > 0.2)) &&
            (field3138 == 0)) {
            field000a = 0xd;
            field016c = 1;
            field000c = 0;
            field3138 = 1;
        }
        if ((field000a == 0xe) && ((unsigned short)field000c == 0)) {
            field016c = 1;
        }
        field0038 = field0038 + field0048;
        ++field000c;
        if (field000a > 6 && field0028 + field0038 > 0.0) {
            field0038 = 0.0;
            field0028 = 0.0;
            field0008 = 0xfd;
            field000a = 0;
            field000c = 0;
            field3138 = 0;
            break;
        }
        if ((unsigned short)field000c >= frameDuration) {
            field000c = 0;
            ++field000a;
            if (field000a < 3) {
                field0168 = 0;
            }
            if (field000a == 0xd) {
                field000a = 7;
            }
            if ((field000a == 5) || (field000a == 0xe)) {
                field0168 = 0;
            }
            if (field000a >= frameCount) {
                field0008 = 0xfd;
                ResetPose();
            }
        }
        break;
    case 251:
        if ((field000a == 0) && ((unsigned short)field000c == 0)) {
            field0158 = 0;
            if (field0028 == 0.0) {
                field0030 = 0.0;
                field0038 = 0.0;
            }
            field0148 = field0148 + 0x2d;
            field016c = 0;
            if (field0028 < 0.0) {
                field000a = 2;
                field000c = 0;
            }
        }
        if ((field000a == 2) && ((unsigned short)field000c == 0)) {
            if (field0028 == 0.0) {
                effect.type = 0x1f;
                effect.x = (double)(int(field0020));
                effect.y = (double)(int(field0028));
                effect.group = 0;
                effect.layer = 1;
                effect.facing = (facing != '\x01');
                contextOwner->EmitEffect(&effect);
            }
            field016c = 1;
        }
        if ((field000a == 6) && ((unsigned short)field000c == 0)) {
            effect.type = 8;
            effect.x = (double)(int(field0020));
            effect.y = (double)(int(field0028));
            effect.group = 2;
            effect.layer = 1;
            contextOwner->EmitEffect(&effect);
            field0030 = 1.4;
            field0038 = -1.5;
            field0048 = 0.03;
        }
        if (((5 < field000a) && (field0038 > 0.8)) &&
            (field3138 == 0)) {
            field000a = 0xd;
            field016c = 1;
            field000c = 0;
            field3138 = 1;
        }
        if ((field000a == 0xe) && ((unsigned short)field000c == 0)) {
            field016c = 1;
        }
        field0038 = field0038 + field0048;
        ++field000c;
        if (field000a > 6 && field0028 + field0038 > 0.0) {
            field0038 = 0.0;
            field0028 = 0.0;
            field0008 = 0xfd;
            field000a = 0;
            field000c = 0;
            field3138 = 0;
            break;
        }
        if ((unsigned short)field000c >= frameDuration) {
            field000c = 0;
            ++field000a;
            if (field000a < 3) {
                field0168 = 0;
            }
            if ((field000a == 5) || (field000a == 0xe)) {
                field0168 = 0;
            }
            if (field000a >= frameCount) {
                field0008 = 0xfd;
                ResetPose();
            }
        }
        break;
    case 252:
        if ((field000a == 0) && ((unsigned short)field000c == 0)) {
            field0158 = 0;
            StartTrail(3);
            if (field0120 == '\0') {
                field0118 = field0118 - 500.0;
            }
            else {
                field0118 = field0118 - 250.0;
            }
            effect.type = 0x21;
            effect.palette = 0xb;
            effect.x = (double)(int(field0020));
            effect.y = (double)((int(field0028)) + -0x32);
            effect.group = 2;
            effect.layer = 1;
            contextOwner->EmitEffect(&effect);
            field016c = 1;
            field0030 = 0.0;
            field0038 = 0.0;
            field0040 = 0.0;
            field016c = 1;
            if (field0028 < 0.0) {
                field000a = 6;
            }
        }
        if ((field000a == 2) && ((unsigned short)field000c == 0)) {
            effect.type = 0x1f;
            effect.x = (double)(int(field0020));
            effect.y = (double)(int(field0028));
            effect.group = 0;
            effect.layer = 1;
            effect.facing = (facing == -1);
            contextOwner->EmitEffect(&effect);
        }
        if ((field000a == 6) && ((unsigned short)field000c == 0)) {
            effect.type = 8;
            effect.x = (double)(int(field0020));
            effect.y = (double)(int(field0028));
            effect.group = 2;
            effect.layer = 1;
            effect.flag0018 = (unsigned char)facing;
            contextOwner->EmitEffect(&effect);
            field0030 = 1.2;
            field0038 = -2.9;
            field0048 = 0.035;
        }
        if (((5 < field000a) && (field0038 > 0.2)) &&
            (field3138 == 0)) {
            if (field016c == 1) {
                field0008 = 0xfd;
                ResetPose();
                return;
            }
            field000a = 0xd;
            field000c = 0;
            field3138 = 1;
        }
        if ((field000a == 0x12) && ((unsigned short)field000c == 0)) {
            field0030 = 0.0;
            field0038 = -1.8;
            field02c9 = 0x12;
            effect.type = 0x199;
            effect.x = (double)(int(field0020));
            effect.y = (double)((int(field0028)) + -0x14);
            effect.group = 2;
            effect.layer = 1;
            effect.flag0018 = (unsigned char)facing;
            EmitLocalEffect(&effect);
            field016c = 1;
        }
        field0038 = field0038 + field0048;
        ++field000c;
        if ((unsigned short)field000c >= frameDuration) {
            field000c = 0;
            ++field000a;
            field0168 = 0;
            if (field000a == 0xd) {
                field000a = 7;
            }
            if (field000a == 6) {
                field013c = 0x3c;
            }
            if ((field000a == 5) || (field000a == 0x11)) {
                field0168 = 0;
            }
            if (field000a >= frameCount) {
                field0008 = 0xfd;
                field000a = 0;
                field000c = 0;
                field3138 = 0;
            }
        }
        break;
    case 253:
        field0038 = field0038 + field0048;
        if (((0.0 <= field0028 + field0038) &&
            (field000a < 2)) && (field3138 == 0)) {
            field0028 = 0.0;
            ++field3138;
            field02c9 = 9;
            field000a = 2;
            field000c = 0;
            field0048 = 0.0;
            field0030 = 0.0;
            field0038 = 0.0;
        }
        ++field000c;
        if ((unsigned short)field000c >= frameDuration) {
            field000c = 0;
            ++field000a;
            field0168 = 0;
            if (field000a == 2) {
                field000a = 0;
            }
            field0168 = 0;
            if (field000a >= frameCount) {
                field0008 = 0;
                ResetPose();
            }
        }
        break;
    case 254:
        field0030 = 0.0;
        field0038 = 0.0;
        field0158 = 0;
        if ((field000a == 3) && ((unsigned short)field000c == 0)) {
            effect.type = 0x196;
            effect.x = (double)(int(field0020));
            effect.y = (double)(int(field0028));
            effect.group = 2;
            effect.layer = 1;
            effect.flag0018 = (unsigned char)facing;
            EmitLocalEffect(&effect);
            field02c9 = 0x12;
            field0148 = field0148 + 0x19;
        }
        ++field000c;
        if ((unsigned short)field000c >= frameDuration) {
            field000c = 0;
            ++field000a;
            field0168 = 3;
            if ((field000a == 0xc) && (field3138 != 0)) {
                --field3138;
                field000a = field000a + -2;
            }
            if (field000a >= frameCount) {
                field0008 = 0;
                ResetPose();
                FaceOpponent();
            }
        }
        break;
    case 255:
        field0030 = 0.0;
        field0038 = 0.0;
        field0158 = 0;
        if ((field000a == 3) && ((unsigned short)field000c == 0)) {
            effect.type = 0x197;
            effect.x = (double)(int(field0020));
            effect.y = (double)(int(field0028));
            effect.group = 2;
            effect.layer = 1;
            effect.flag0018 = (unsigned char)facing;
            EmitLocalEffect(&effect);
            field02c9 = 0x12;
            field0148 = field0148 + 0x19;
        }
        ++field000c;
        if ((unsigned short)field000c >= frameDuration) {
            field000c = 0;
            ++field000a;
            field0168 = 3;
            if ((field000a == 0xc) && (field3138 != 0)) {
                --field3138;
                field000a = field000a + -2;
            }
            if (field000a >= frameCount) {
                field0008 = 0;
                ResetPose();
                FaceOpponent();
            }
        }
        break;
    case 256:
        field0030 = 0.0;
        field0038 = 0.0;
        field0158 = 0;
        if ((field000a == 0) && ((unsigned short)field000c == 0)) {
            StartTrail(3);
            if (field0120 == '\0') {
                field0118 = field0118 - 500.0;
            }
            else {
                field0118 = field0118 - 250.0;
            }
            effect.type = 0x21;
            effect.palette = 0xb;
            effect.x = (double)(int(field0020));
            effect.y = (double)((int(field0028)) + -0x32);
            effect.group = 2;
            effect.layer = 1;
            contextOwner->EmitEffect(&effect);
        }
        if ((field000a == 3) && ((unsigned short)field000c == 0)) {
            effect.type = 0x1a1;
            effect.x = (double)((int(field0020)) + facing * 0x14);
            effect.y = (double)(int(field0028));
            effect.group = 2;
            effect.layer = 1;
            effect.flag0018 = (unsigned char)facing;
            EmitLocalEffect(&effect);
            field0148 = field0148 + 0xf;
        }
        ++field000c;
        if ((unsigned short)field000c >= frameDuration) {
            field000c = 0;
            ++field000a;
            field0168 = 3;
            if ((field000a == 0xc) && (field3138 != 0)) {
                --field3138;
                field000a = field000a + -2;
            }
            if (field000a >= frameCount) {
                field0008 = 0;
                ResetPose();
                FaceOpponent();
            }
        }
        break;
    case 257:
        field0158 = 0;
        if (field0028 >= 0.0) {
            field016c = 0;
        }
        if (6 < field000a) {
            field0168 = 3;
        }
        if ((field000a == 0) && ((unsigned short)field000c == 0)) {
            field0030 = 0.0;
            field0038 = 0.0;
            field0148 = field0148 + 0x2d;
            if (field0028 < 0.0) {
                field000a = 5;
            }
        }
        if (field000a > 4 && field000a < 7 && field0168 == 3 && (*opponentSlot)->field0028 < 0.0) {
            (*opponentSlot)->ResetFrame();
            (*opponentSlot)->ResetPose();
            ResetFrame();
            (*opponentSlot)->field0128 = 1;
            effect.type = 0;
            effect.x = (double)((int(field0020)) + facing * 0x36);
            effect.y = (double)((int(field0028)) + -0x54);
            effect.group = 2;
            effect.layer = 1;
            contextOwner->EmitEffect(&effect);
            field000a = 7;
            field000c = 0;
            (*opponentSlot)->field0008 = 100;
            (*opponentSlot)->field0028 = field0028 - 61.0;
            (*opponentSlot)->field0020 =
            (double)(facing * 0x13) + field0020;
            break;
        }
        if (field000a > 4 && field000a < 7 && field0038 > 0.0 && field0028 < 0.0) {
            field0030 = 0.0;
            ResetPose();
            field0008 = 0xfd;
            break;
        }
        if (((field000a == 5) && ((unsigned short)field000c == 0)) &&
            (field3138 == 0)) {
            effect.type = 8;
            effect.x = (double)(int(field0020));
            effect.y = (double)(int(field0028));
            effect.group = 2;
            effect.layer = 1;
            contextOwner->EmitEffect(&effect);
            field0030 = 1.4;
            field0038 = -3.0;
            field0048 = 0.059;
        }
        field0038 = field0038 + field0048;
        ++field000c;
        if ((unsigned short)field000c >= frameDuration) {
            field000c = 0;
            ++field000a;
            field0168 = 0;
            if (field0028 < -40.0 && (*opponentSlot)->field0028 < 0.0) {
                field016c = 1;
            } else {
                field016c = 0;
            }
            if ((field000a == 7) && (field3138 < 10)) {
                field000a = 5;
                ++field3138;
            }
            if (field000a == 8) {
                (*opponentSlot)->field0008 = 100;
                (*opponentSlot)->field0028 = field0028 - 59.0;
                (*opponentSlot)->field0020 =
                (double)(facing * 0xf) + field0020;
            }
            if (field000a == 9) {
                (*opponentSlot)->field0028 = field0028 - 67.0;
                (*opponentSlot)->field0020 =
                (double)(facing * 0xb) + field0020;
            }
            if (field000a == 10) {
                (*opponentSlot)->field0028 = field0028 - 64.0;
                (*opponentSlot)->field0020 = field0020;
            }
            if (field000a == 0xb) {
                (*opponentSlot)->field0008 = 0x65;
                (*opponentSlot)->field0028 = field0028 - 66.0;
                (*opponentSlot)->field0020 =
                field0020 - (double)(facing * 0x16);
                (*opponentSlot)->facing = -facing;
            }
            if (field000a == 0xc) {
                (*opponentSlot)->field0028 = field0028 - 59.0;
                (*opponentSlot)->field0020 =
                field0020 - (double)((int)facing << 4);
            }
            if (field000a == 0xd) {
                (*opponentSlot)->ResetPose();
                (*opponentSlot)->field0008 = 0x3c;
                (*opponentSlot)->field00c0 = 2.5;
                (*opponentSlot)->field00c8 = -0.3;
                (*opponentSlot)->field0048 = 0.035;
                ApplyDamage(0x352,890.0);
                --field0174;
                --field00f4;
                (*opponentSlot)->field0128 = 1;
                (*opponentSlot)->field0028 = field0028 - 69.0;
                (*opponentSlot)->field0020 =
                field0020 - (double)(facing * 0x27);
            }
            if (field000a >= frameCount) {
                facing = -facing;
                field0048 = 0.035;
                field0008 = 0xfd;
                ResetPose();
            }
        }
        break;
    case 258:
        field0158 = 0;
        if ((field000a == 0) && ((unsigned short)field000c == 0)) {
            if (field0120 == '\0') {
                field0118 = field0118 - 500.0;
            }
            else {
                field0118 = field0118 - 250.0;
            }
            effect.type = 0x21;
            effect.palette = 0xb;
            effect.x = (double)(int(field0020));
            effect.y = (double)((int(field0028)) + -0x32);
            effect.group = 2;
            effect.layer = 1;
            contextOwner->EmitEffect(&effect);
            StartTrail(3);
            field016c = 0;
            field0030 = 0.0;
            field0038 = 0.0;
            field0040 = 0.0;
        }
        if ((field000a == 4) && (field0168 == 3)) {
            field3138 = 0;
            (*opponentSlot)->ResetFrame();
            (*opponentSlot)->ResetPose();
            ResetPose();
            (*opponentSlot)->field0128 = 1;
            (*opponentSlot)->field0028 = -85.0;
            (*opponentSlot)->field0020 =
            (double)(facing * 0x27) + field0020;
            effect.type = 0;
            effect.x = (double)((int(field0020)) + facing * 0x24);
            effect.y = (double)((int(field0028)) + -0x29);
            effect.group = 2;
            effect.layer = 1;
            contextOwner->EmitEffect(&effect);
            field0008 = 0x103;
            (*opponentSlot)->field0008 = 0x67;
            break;
        }
        ++field000c;
        if ((unsigned short)field000c >= frameDuration) {
            field000c = 0;
            ++field000a;
            if (field000a == 4 && (*opponentSlot)->field0028 < 0.0) {
                field016c = 1;
            } else {
                field016c = 0;
            }
            field0168 = 0;
            if (field000a >= frameCount) {
                field0008 = 0;
                FaceOpponent();
                ResetPose();
            }
        }
        break;
    case 259:
        if (field000a < 6) {
            SetHorizontalShake(0x32,3);
        }
        ++field000c;
        if ((unsigned short)field000c >= frameDuration) {
            field000c = 0;
            ++field000a;
            if (field000a == 1) {
                (*opponentSlot)->ResetPose();
                (*opponentSlot)->field0008 = 0x67;
                (*opponentSlot)->field0028 = -98.0;
                (*opponentSlot)->field0020 =
                (double)(facing * 0x23) + field0020;
            }
            if (field000a == 2) {
                (*opponentSlot)->ResetPose();
                (*opponentSlot)->field0028 = -98.0;
                (*opponentSlot)->field0020 =
                (double)(facing * 0x21) + field0020;
            }
            if (field000a == 3) {
                if (field3138 < 3) {
                    (*opponentSlot)->field0028 = 0.0;
                    (*opponentSlot)->field0020 =
                    (double)(facing * 0x21) + field0020;
                    (*opponentSlot)->facing = -facing;
                    (*opponentSlot)->ResetPose();
                    (*opponentSlot)->field0008 = 0x61;
                    (*opponentSlot)->field012c = 1;
                    ApplyDamage(0x15e,960.0);
                }
                else {
                    field000a = 6;
                    (*opponentSlot)->field0028 = -75.0;
                    (*opponentSlot)->field0008 = 0x3f;
                    (*opponentSlot)->ResetPose();
                    field016c = 1;
                    field0168 = 0;
                }
            }
            if ((field000a == 6) && (field3138 < 3)) {
                ++field3138;
                field000a = 0;
                (*opponentSlot)->field0028 = -85.0;
                (*opponentSlot)->field0020 =
                (double)(facing * 0x27) + field0020;
                (*opponentSlot)->field0008 = 0x67;
                (*opponentSlot)->ResetPose();
            }
            field0168 = 0;
            if (field000a >= frameCount) {
                field0008 = 0;
                FaceOpponent();
                ResetPose();
            }
        }
        break;
    case 260:
        field0158 = 0;
        if (field0028 >= 0.0) {
            field016c = 0;
        }
        if (6 < field000a) {
            field0168 = 3;
        }
        if ((field000a == 0) && ((unsigned short)field000c == 0)) {
            field0030 = 0.0;
            field0038 = 0.0;
            field0148 = field0148 + 0x2d;
            if (field0028 < 0.0) {
                field000a = 5;
            }
        }
        if (field000a > 4 && field000a < 7 && field0168 == 3 && (*opponentSlot)->field0028 < 0.0) {
            (*opponentSlot)->ResetFrame();
            (*opponentSlot)->ResetPose();
            ResetFrame();
            (*opponentSlot)->field0128 = 1;
            effect.type = 0;
            effect.x = (double)((int(field0020)) + facing * 0x36);
            effect.y = (double)((int(field0028)) + -0x54);
            effect.group = 2;
            effect.layer = 1;
            contextOwner->EmitEffect(&effect);
            field000a = 7;
            field000c = 0;
            (*opponentSlot)->field0008 = 100;
            (*opponentSlot)->field0028 = field0028 - 61.0;
            (*opponentSlot)->field0020 =
            (double)(facing * 0x13) + field0020;
            break;
        }
        if (field000a > 4 && field000a < 7 && field0038 > 0.0 && field0028 < 0.0) {
            field0030 = 0.0;
            ResetPose();
            field0008 = 0xfd;
            break;
        }
        if (((field000a == 5) && ((unsigned short)field000c == 0)) &&
            (field3138 == 0)) {
            effect.type = 8;
            effect.x = (double)(int(field0020));
            effect.y = (double)(int(field0028));
            effect.group = 2;
            effect.layer = 1;
            contextOwner->EmitEffect(&effect);
            field0030 = 1.4;
            field0038 = -4.0;
            field0048 = 0.059;
        }
        field0038 = field0038 + field0048;
        ++field000c;
        if ((unsigned short)field000c >= frameDuration) {
            field000c = 0;
            ++field000a;
            field0168 = 0;
            if (field0028 < -40.0 && (*opponentSlot)->field0028 < 0.0) {
                field016c = 1;
            } else {
                field016c = 0;
            }
            if ((field000a == 7) && (field3138 < 10)) {
                field000a = 5;
                ++field3138;
            }
            if (field000a == 8) {
                (*opponentSlot)->field0008 = 100;
                (*opponentSlot)->field0028 = field0028 - 59.0;
                (*opponentSlot)->field0020 =
                (double)(facing * 0xf) + field0020;
            }
            if (field000a == 9) {
                (*opponentSlot)->field0028 = field0028 - 67.0;
                (*opponentSlot)->field0020 =
                (double)(facing * 0xb) + field0020;
            }
            if (field000a == 10) {
                (*opponentSlot)->field0028 = field0028 - 64.0;
                (*opponentSlot)->field0020 = field0020;
            }
            if (field000a == 0xb) {
                (*opponentSlot)->field0008 = 0x65;
                (*opponentSlot)->field0028 = field0028 - 66.0;
                (*opponentSlot)->field0020 =
                field0020 - (double)(facing * 0x16);
                (*opponentSlot)->facing = -facing;
            }
            if (field000a == 0xc) {
                (*opponentSlot)->field0028 = field0028 - 59.0;
                (*opponentSlot)->field0020 =
                field0020 - (double)((int)facing << 4);
            }
            if (field000a == 0xd) {
                (*opponentSlot)->ResetPose();
                (*opponentSlot)->field0008 = 0x3c;
                (*opponentSlot)->field00c0 = 0.8;
                (*opponentSlot)->field00c8 =
                (-5.0 * field0178) / 10000.0;
                (*opponentSlot)->field0048 = 0.035;
                ApplyDamage(0x28a,890.0);
                --field0174;
                --field00f4;
                (*opponentSlot)->field0128 = 1;
                (*opponentSlot)->field0028 = field0028 - 69.0;
                (*opponentSlot)->field0020 =
                field0020 - (double)(facing * 0x27);
            }
            if (field000a >= frameCount) {
                facing = -facing;
                field0048 = 0.035;
                field0008 = 0xfd;
                ResetPose();
            }
        }
        break;
    case 261:
        if ((field000a == 0) && ((unsigned short)field000c == 0)) {
            ResetFrame();
        }
        if ((field000a == 3) && ((unsigned short)field000c == 0)) {
            field0148 = field0148 + 0x14;
        }
        if ((field0168 == 6) && (field000a == 3)) {
            ResetPose();
            field0168 = 0;
            field014c = 0x5a;
            field02c9 = 3;
            field0008 = 0x106;
            effect.type = 0;
            effect.x = (double)((int(field0020)) - facing * 8);
            effect.y = (double)((int(field0028)) + -0x35);
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
                FaceOpponent();
                ResetPose();
            }
        }
        break;
    case 262:
        if ((field000a == 0) && ((unsigned short)field000c == 0)) {
            ResetFrame();
        }
        if ((field000a == 3) && ((unsigned short)field000c == 0)) {
            field0148 = field0148 + 0xf;
            field02c9 = 0x14;
            field016c = 1;
            effect.type = 0x191;
            effect.x = (double)((int(field0020)) + facing * 0x28);
            effect.y = (double)(int(field0028));
            effect.group = 2;
            effect.flag0018 = (unsigned char)facing;
            effect.owner = 1;
            effect.layer = 1;
            EmitLocalEffect(&effect);
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
    case 263:
        if ((field000a == 0) && ((unsigned short)field000c == 0)) {
            ResetFrame();
        }
        if ((field000a == 2) && ((unsigned short)field000c == 0)) {
            field016c = 0;
        }
        field0038 = field0038 + field0048;
        ++field000c;
        if (field000a > 3 && field0028 + field0038 > 0.0) {
            ResetFrame();
            field0028 = 0.0;
            field000a = 0x13;
            field000c = 0;
            field3138 = 0;
            break;
        }
        if ((unsigned short)field000c >= frameDuration) {
            field000c = 0;
            ++field000a;
            if (field000a < 3) {
                field0168 = 0;
            }
            if ((field000a == 4) && ((unsigned short)field000c == 0)) {
                effect.type = 8;
                effect.x = (double)(int(field0020));
                effect.y = (double)(int(field0028));
                effect.group = 2;
                effect.layer = 1;
                contextOwner->EmitEffect(&effect);
                field0030 = 1.4;
                field0038 = -1.5;
                field0048 = 0.03;
            }
            if ((field000a == 0xb) && (field3138 < 1)) {
                field000a = 4;
                ++field3138;
            }
            if (field000a == 0xd) {
                field016c = 1;
                field0168 = 0;
            }
            if (field000a == 0x13) {
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
            ResetFrame();
        }
        if ((field000a == 2) && ((unsigned short)field000c == 0)) {
            field016c = 1;
        }
        field0038 = field0038 + field0048;
        ++field000c;
        if (field000a > 3 && field0028 + field0038 > 0.0) {
            ResetFrame();
            field0028 = 0.0;
            field000a = 0xf;
            field000c = 0;
            field3138 = 0;
            break;
        }
        if ((unsigned short)field000c >= frameDuration) {
            field000c = 0;
            ++field000a;
            if (field000a < 3) {
                field0168 = 0;
            }
            if ((field000a == 4) && ((unsigned short)field000c == 0)) {
                effect.type = 8;
                effect.x = (double)(int(field0020));
                effect.y = (double)(int(field0028));
                effect.group = 2;
                effect.layer = 1;
                contextOwner->EmitEffect(&effect);
                field0030 = 1.4;
                field0038 = -1.5;
                field0048 = 0.03;
            }
            if ((field000a == 0xb) && (field3138 < 1)) {
                field000a = 4;
                ++field3138;
            }
            if (field000a == 0xf) {
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
        if ((field000a == 3) && ((unsigned short)field000c == 0)) {
            field0148 = field0148 + 0x14;
        }
        if ((field0168 == 6) && (field000a == 3)) {
            ResetPose();
            field0168 = 0;
            field014c = 0x5a;
            field02c9 = 3;
            field0008 = 0x106;
            effect.type = 0;
            effect.x = (double)((int(field0020)) - facing * 8);
            effect.y = (double)((int(field0028)) + -0x35);
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
                FaceOpponent();
                ResetPose();
            }
        }
        break;
    case 300:
        if ((field000a == 0) && ((unsigned short)field000c == 0)) {
            field0030 = 0.0;
            field0038 = -1.0;
            field0048 = 0.002;
            field016c = 1;
        }
        if ((field000a == 7) && ((unsigned short)field000c == 0)) {
            ResetFrame();
            field014c = 0x78;
            field0148 = field0148 + -1000;
            SetTint(0xb0,3);
            effect.type = 0x44;
            effect.palette = 0x13;
            effect.x = (double)(int(field0020));
            effect.y = (double)((int(field0028)) + -0x28);
            effect.group = 2;
            effect.owner = 1;
            effect.layer = 1;
            contextOwner->EmitEffect(&effect);
        }
        if (field000a == 7) {
            SetHorizontalShake(0x32,3);
        }
        if (7 < field000a) {
            SetHorizontalShake(-0x2d,3);
        }
        if ((field000a == 9) && ((unsigned short)field000c == 0)) {
            field0038 = -1.45;
            field0048 = 0.02;
            field02c9 = 0x16;
            effect.owner = 1;
            effect.type = 0x1a3;
            effect.x = (double)(int(field0020));
            effect.y = (double)(int(field0028));
            effect.flag0018 = (unsigned char)facing;
            effect.group = 2;
            effect.layer = 1;
            EmitLocalEffect(&effect);
        }
        if (field0030 + field0028 >= 0.0) {
            field0008 = 0xd;
            ResetPose();
            break;
        }
        field0038 = field0038 + field0048;
        ++field000c;
        if ((unsigned short)field000c >= frameDuration) {
            field000c = 0;
            ++field000a;
            field0168 = 0;
            if ((field000a == 0xd) && (field0038 < 0.0)
                ) {
                field000a = 10;
            }
            if (field000a >= frameCount) {
                field0008 = 0;
                FaceOpponent();
                ResetPose();
            }
        }
        break;
    case 301:
        if ((field000a == 0) && ((unsigned short)field000c == 0)) {
            field0030 = 0.0;
            field0038 = -1.0;
            field0048 = 0.002;
            field016c = 1;
        }
        if ((field000a == 7) && ((unsigned short)field000c == 0)) {
            ResetFrame();
            field014c = 0x78;
            field0148 = field0148 + -2000;
            SetTint(0xb0,3);
            effect.type = 0x45;
            effect.palette = 5;
            effect.x = (double)(int(field0020));
            effect.y = (double)((int(field0028)) + -0x28);
            effect.group = 2;
            effect.owner = 1;
            effect.layer = 1;
            contextOwner->EmitEffect(&effect);
        }
        if (field000a == 7) {
            SetHorizontalShake(0x32,3);
        }
        if (7 < field000a) {
            SetHorizontalShake(-0x2d,3);
        }
        if ((field000a == 9) && ((unsigned short)field000c == 0)) {
            field0038 = -1.8;
            field0048 = 0.013;
            field02c9 = 0x16;
            effect.owner = 1;
            effect.type = 0x193;
            effect.x = (double)(int(field0020));
            effect.y = (double)(int(field0028));
            effect.flag0018 = (unsigned char)facing;
            effect.group = 2;
            effect.layer = 1;
            EmitLocalEffect(&effect);
        }
        if (field0030 + field0028 >= 0.0) {
            field0008 = 0xd;
            ResetPose();
            break;
        }
        field0038 = field0038 + field0048;
        ++field000c;
        if ((unsigned short)field000c >= frameDuration) {
            field000c = 0;
            ++field000a;
            field0168 = 0;
            if ((field000a == 0xd) && (field0038 < 0.0)
                ) {
                field000a = 10;
            }
            if (field000a >= frameCount) {
                field0008 = 0;
                FaceOpponent();
                ResetPose();
            }
        }
        break;
    case 302:
        if ((field000a == 0) && ((unsigned short)field000c == 0)) {
            field0030 = 0.0;
            field0038 = -1.0;
            field0048 = 0.002;
            field016c = 1;
        }
        if ((field000a == 7) && ((unsigned short)field000c == 0)) {
            ResetFrame();
            field014c = 0x78;
            field0148 = field0148 + -3000;
            SetTint(0xb0,3);
            effect.type = 0x46;
            effect.palette = 0x40;
            effect.x = (double)(int(field0020));
            effect.y = (double)((int(field0028)) + -0x28);
            effect.group = 2;
            effect.owner = 1;
            effect.layer = 1;
            contextOwner->EmitEffect(&effect);
            field02c9 = 0x25;
        }
        if (6 < field000a) {
            contextOwner->SetSceneTimer(0xf);
        }
        if (field000a == 7) {
            SetHorizontalShake(0x32,3);
        }
        if (7 < field000a) {
            SetHorizontalShake(-0x2d,3);
        }
        if ((field000a == 9) && ((unsigned short)field000c == 0)) {
            field0038 = -2.5;
            field0048 = 0.013;
            field02c9 = 0x16;
            effect.owner = 1;
            effect.type = 0x1a7;
            effect.x = (double)(int(field0020));
            effect.y = (double)(int(field0028));
            effect.flag0018 = (unsigned char)facing;
            effect.group = 2;
            effect.layer = 1;
            EmitLocalEffect(&effect);
        }
        if (field0030 + field0028 >= 0.0) {
            field0008 = 0xd;
            ResetPose();
            break;
        }
        field0038 = field0038 + field0048;
        ++field000c;
        if ((unsigned short)field000c >= frameDuration) {
            field000c = 0;
            ++field000a;
            field0168 = 0;
            if ((field000a == 0xd) && (field0038 < 0.0)
                ) {
                field000a = 10;
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
            field0158 = 0;
            field0030 = 0.0;
            field0038 = 0.0;
            field0048 = 0.0;
        }
        if ((field000a == 3) && ((unsigned short)field000c == 0)) {
            field014c = 0x78;
            field0148 = field0148 + -1000;
            SetTint(0xb0,3);
            effect.type = 0x44;
            effect.palette = 0x13;
            effect.x = (double)(int(field0020));
            effect.y = (double)((int(field0028)) + -0x28);
            effect.group = 2;
            effect.owner = 1;
            effect.layer = 1;
            contextOwner->EmitEffect(&effect);
            SetHorizontalShake(0x32,0x2d);
        }
        if ((field000a == 9) && ((unsigned short)field000c == 0)) {
            field3138 = 0;
            if (((unsigned short)RandomRange(0, 100)) < 0x32) {
                effect.type = 0x19b;
                effect.x = (double)((int(field0020)) + facing * 0x14);
                effect.y = (double)((int(field0028)) + -0x4a);
                effect.flag0018 = (unsigned char)facing;
                effect.group = 0;
                effect.layer = 1;
                ++field3138;
                EmitLocalEffect(&effect);
            }
            if ((((unsigned short)RandomRange(0, 100)) < 0x32) && (field3138 == 0)) {
                effect.type = 0x19d;
                effect.x = (double)((int(field0020)) + facing * 0x14);
                effect.y = (double)((int(field0028)) + -0x4a);
                effect.flag0018 = (unsigned char)facing;
                effect.group = 0;
                effect.layer = 1;
                ++field3138;
                EmitLocalEffect(&effect);
            }
            if (field3138 == 0) {
                effect.type = 0x19f;
                effect.x = (double)((int(field0020)) + facing * 0x14);
                effect.y = (double)((int(field0028)) + -0x4a);
                effect.flag0018 = (unsigned char)facing;
                effect.group = 0;
                effect.layer = 1;
                EmitLocalEffect(&effect);
            }
        }
        ++field000c;
        if ((unsigned short)field000c >= frameDuration) {
            field000c = 0;
            ++field000a;
            field0168 = 0;
            if ((field000a == 0xb) && (field313c < 0x1b)) {
                field000a = 4;
                field313c = field313c + 2;
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
            field0158 = 0;
            field0030 = 0.0;
            field0038 = 0.0;
            field0048 = 0.0;
        }
        if ((field000a == 3) && ((unsigned short)field000c == 0)) {
            field014c = 0x78;
            field0148 = field0148 + -2000;
            SetTint(0xb0,3);
            effect.type = 0x45;
            effect.palette = 5;
            effect.x = (double)(int(field0020));
            effect.y = (double)((int(field0028)) + -0x28);
            effect.group = 2;
            effect.owner = 1;
            effect.layer = 1;
            contextOwner->EmitEffect(&effect);
            SetHorizontalShake(0x32,0x2d);
            field013c = 0x87;
        }
        if ((field000a == 9) && ((unsigned short)field000c == 0)) {
            field3138 = 0;
            if (((unsigned short)RandomRange(0, 100)) < 0x32) {
                effect.type = 0x19b;
                effect.x = (double)((int(field0020)) + facing * 0x14);
                effect.y = (double)((int(field0028)) + -0x4a);
                effect.flag0018 = (unsigned char)facing;
                effect.group = 0;
                effect.layer = 1;
                ++field3138;
                EmitLocalEffect(&effect);
            }
            if ((((unsigned short)RandomRange(0, 100)) < 0x32) && (field3138 == 0)) {
                effect.type = 0x19d;
                effect.x = (double)((int(field0020)) + facing * 0x14);
                effect.y = (double)((int(field0028)) + -0x4a);
                effect.flag0018 = (unsigned char)facing;
                effect.group = 0;
                effect.layer = 1;
                ++field3138;
                EmitLocalEffect(&effect);
            }
            if (field3138 == 0) {
                effect.type = 0x19f;
                effect.x = (double)((int(field0020)) + facing * 0x14);
                effect.y = (double)((int(field0028)) + -0x4a);
                effect.flag0018 = (unsigned char)facing;
                effect.group = 0;
                effect.layer = 1;
                EmitLocalEffect(&effect);
            }
        }
        ++field000c;
        if ((unsigned short)field000c >= frameDuration) {
            field000c = 0;
            ++field000a;
            field0168 = 0;
            if ((field000a == 0xb) && (field313c < 0x27)) {
                field000a = 4;
                field313c = field313c + 2;
            }
            if (field000a >= frameCount) {
                field0008 = 0;
                FaceOpponent();
                ResetPose();
            }
        }
        break;
    case 305:
        if ((field000a == 0) && ((unsigned short)field000c == 0)) {
            field0158 = 0;
            field0030 = 0.0;
            field0038 = 0.0;
            field0048 = 0.0;
        }
        if ((field000a == 3) && ((unsigned short)field000c == 0)) {
            field014c = 0x78;
            field0148 = field0148 + -3000;
            SetTint(0xb0,3);
            effect.type = 0x46;
            effect.palette = 0x40;
            effect.x = (double)(int(field0020));
            effect.y = (double)((int(field0028)) + -0x28);
            effect.group = 2;
            effect.owner = 1;
            effect.layer = 1;
            contextOwner->EmitEffect(&effect);
            SetHorizontalShake(0x32,0x2d);
            field02c9 = 0x25;
            field013c = 0x99;
        }
        if (2 < field000a) {
            contextOwner->SetSceneTimer(0xf);
        }
        if ((field000a == 9) && ((unsigned short)field000c == 0)) {
            field3138 = 0;
            if (((unsigned short)RandomRange(0, 100)) < 0x32) {
                effect.type = 0x19b;
                effect.x = (double)((int(field0020)) + facing * 0x14);
                effect.y = (double)((int(field0028)) + -0x4a);
                effect.flag0018 = (unsigned char)facing;
                effect.group = 0;
                effect.layer = 1;
                ++field3138;
                EmitLocalEffect(&effect);
            }
            if ((((unsigned short)RandomRange(0, 100)) < 0x32) && (field3138 == 0)) {
                effect.type = 0x19d;
                effect.x = (double)((int(field0020)) + facing * 0x14);
                effect.y = (double)((int(field0028)) + -0x4a);
                effect.flag0018 = (unsigned char)facing;
                effect.group = 0;
                effect.layer = 1;
                ++field3138;
                EmitLocalEffect(&effect);
            }
            if (field3138 == 0) {
                effect.type = 0x19f;
                effect.x = (double)((int(field0020)) + facing * 0x14);
                effect.y = (double)((int(field0028)) + -0x4a);
                effect.flag0018 = (unsigned char)facing;
                effect.group = 0;
                effect.layer = 1;
                EmitLocalEffect(&effect);
            }
        }
        ++field000c;
        if ((unsigned short)field000c >= frameDuration) {
            field000c = 0;
            ++field000a;
            field0168 = 0;
            if ((field000a == 0xb) && (field313c < 0x39)) {
                field000a = 4;
                field313c = field313c + 2;
            }
            if (field000a >= frameCount) {
                field0008 = 0;
                FaceOpponent();
                ResetPose();
            }
        }
        break;
    case 306:
        if ((field000a == 3) && ((unsigned short)field000c == 0)) {
            field0158 = 0;
            ResetFrame();
            field014c = 0x78;
            field0148 = field0148 + -1000;
            SetTint(0xb0,3);
            effect.type = 0x44;
            effect.palette = 0x13;
            effect.x = (double)(int(field0020));
            effect.y = (double)((int(field0028)) + -0x28);
            effect.group = 2;
            effect.owner = 1;
            effect.layer = 1;
            contextOwner->EmitEffect(&effect);
            SetHorizontalShake(0x32,0x2d);
        }
        if (field000a > 4 && (*opponentSlot)->field0028 == 0.0) {
            field016c = 1;
        } else {
            field016c = 0;
        }
        if ((field000a == 1) && ((unsigned short)field000c == 0)) {
            field3140 = 0xf;
        }
        if (((field000a == 5) && ((unsigned short)field000c == 0)) &&
            (((field313c == 0 ||
            (((field313c == 3 || (field313c == 6)) || (field313c == 9)))) ||
            ((field313c == 0xc || (field313c == 0xf)))))) {
            effect.type = 0x1a2;
            effect.x = (double)((int(field0020)) + facing * 0xf);
            effect.y = (double)(int(field0028));
            effect.group = 2;
            effect.layer = 1;
            effect.flag0018 = (unsigned char)facing;
            EmitLocalEffect(&effect);
        }
        if ((4 < field000a) && (field000a < 8)) {
            ++field3138;
            if (0x97 < field3138) {
                field3138 = 0x96;
            }
            field00d0 = 1;
            if ((*opponentSlot)->field0020 > field0020) {
                field00b8 =
                (double)field3138 * 0.01 * (double)-(int)(*opponentSlot)->facing;
            }
            if ((*opponentSlot)->field0020 < field0020) {
                field00b8 =
                (double)field3138 * 0.01 * (double)(int)(*opponentSlot)->facing;
            }
        }
        if (field000a > 4 && field0168 == 3) {
            (*opponentSlot)->ResetFrame();
            (*opponentSlot)->ResetPose();
            ResetPose();
            (*opponentSlot)->field0128 = 1;
            effect.type = 0;
            effect.x = (double)((int(field0020)) + facing * 0x1d);
            effect.y = (double)((int(field0028)) + -0x53);
            effect.group = 2;
            effect.owner = 1;
            effect.layer = 1;
            contextOwner->EmitEffect(&effect);
            field0008 = 0x135;
            (*opponentSlot)->field0008 = 0x67;
            (*opponentSlot)->field0028 = -100.0;
            (*opponentSlot)->field0020 =
            (double)(facing * 0x16) + field0020;
            (*opponentSlot)->facing = facing;
            break;
        }
        ++field000c;
        if ((unsigned short)field000c >= frameDuration) {
            field000c = 0;
            ++field000a;
            field0168 = 0;
            if (field000a == 5) {
                field02c9 = 0x12;
            }
            if ((field000a == 8) && (field313c < 0xf)) {
                field000a = field000a + -3;
                ++field313c;
            }
            if (field000a >= frameCount) {
                field0008 = 0;
                FaceOpponent();
                ResetPose();
            }
        }
        break;
    case 307:
        if ((field000a == 3) && ((unsigned short)field000c == 0)) {
            field0158 = 0;
            ResetFrame();
            field014c = 0x78;
            field0148 = field0148 + -2000;
            SetTint(0xb0,3);
            effect.type = 0x45;
            effect.palette = 5;
            effect.x = (double)(int(field0020));
            effect.y = (double)((int(field0028)) + -0x28);
            effect.group = 2;
            effect.owner = 1;
            effect.layer = 1;
            contextOwner->EmitEffect(&effect);
            SetHorizontalShake(0x32,0x2d);
        }
        if (field000a > 4 && (*opponentSlot)->field0028 == 0.0) {
            field016c = 1;
        } else {
            field016c = 0;
        }
        if ((field000a == 1) && ((unsigned short)field000c == 0)) {
            field3140 = 0xf;
        }
        if (((field000a == 5) && ((unsigned short)field000c == 0)) &&
            (((field313c == 0 ||
            (((field313c == 3 || (field313c == 6)) || (field313c == 9)))) ||
            ((field313c == 0xc || (field313c == 0xf)))))) {
            effect.type = 0x1a2;
            effect.x = (double)((int(field0020)) + facing * 0xf);
            effect.y = (double)(int(field0028));
            effect.group = 2;
            effect.layer = 1;
            effect.flag0018 = (unsigned char)facing;
            EmitLocalEffect(&effect);
        }
        if ((4 < field000a) && (field000a < 8)) {
            ++field3138;
            if (0xc9 < field3138) {
                field3138 = 200;
            }
            field00d0 = 1;
            if ((*opponentSlot)->field0020 > field0020) {
                field00b8 =
                (double)field3138 * 0.01 * (double)-(int)(*opponentSlot)->facing;
            }
            if ((*opponentSlot)->field0020 < field0020) {
                field00b8 =
                (double)field3138 * 0.01 * (double)(int)(*opponentSlot)->facing;
            }
        }
        if (field000a > 4 && field0168 == 3) {
            (*opponentSlot)->ResetFrame();
            (*opponentSlot)->ResetPose();
            ResetPose();
            (*opponentSlot)->field0128 = 1;
            effect.type = 0;
            effect.x = (double)((int(field0020)) + facing * 0x1d);
            effect.y = (double)((int(field0028)) + -0x53);
            effect.group = 2;
            effect.owner = 1;
            effect.layer = 1;
            contextOwner->EmitEffect(&effect);
            field0008 = 0x136;
            (*opponentSlot)->field0008 = 0x67;
            (*opponentSlot)->field0028 = -100.0;
            (*opponentSlot)->field0020 =
            (double)(facing * 0x16) + field0020;
            (*opponentSlot)->facing = facing;
            break;
        }
        ++field000c;
        if ((unsigned short)field000c >= frameDuration) {
            field000c = 0;
            ++field000a;
            field0168 = 0;
            if (field000a == 5) {
                field02c9 = 0x12;
            }
            if ((field000a == 8) && (field313c < 0xf)) {
                field000a = field000a + -3;
                ++field313c;
            }
            if (field000a >= frameCount) {
                field0008 = 0;
                FaceOpponent();
                ResetPose();
            }
        }
        break;
    case 308:
        if ((field000a == 0) && ((unsigned short)field000c == 0)) {
            field0158 = 0;
            ResetFrame();
            field014c = 0x78;
            field0148 = field0148 + -3000;
            SetTint(0xb0,3);
            effect.type = 0x46;
            effect.palette = 0x40;
            effect.x = (double)(int(field0020));
            effect.y = (double)((int(field0028)) + -0x28);
            effect.group = 2;
            effect.owner = 1;
            effect.layer = 1;
            contextOwner->EmitEffect(&effect);
            SetHorizontalShake(0x32,0x2d);
            field02c9 = 0x25;
        }
        contextOwner->SetSceneTimer(0xf);
        if (4 < field000a) {
            field016c = 1;
        }
        if ((field000a == 1) && ((unsigned short)field000c == 0)) {
            field3140 = 0xf;
        }
        if (((field000a == 5) && ((unsigned short)field000c == 0)) &&
            ((field313c == 0 ||
            ((((field313c == 3 || (field313c == 6)) || (field313c == 9)) ||
            ((field313c == 0xc || (field313c == 0xf)))))))) {
            effect.type = 0x1a2;
            effect.x = (double)((int(field0020)) + facing * 0xf);
            effect.y = (double)(int(field0028));
            effect.group = 2;
            effect.layer = 1;
            effect.flag0018 = (unsigned char)facing;
            EmitLocalEffect(&effect);
        }
        if ((4 < field000a) && (field000a < 8)) {
            field3138 = field3138 + 2;
            if (0xc9 < field3138) {
                field3138 = 200;
            }
            field00d0 = 1;
            if ((*opponentSlot)->field0020 > field0020) {
                field00b8 =
                (double)field3138 * 0.01 * (double)-(int)(*opponentSlot)->facing;
            }
            if ((*opponentSlot)->field0020 < field0020) {
                field00b8 =
                (double)field3138 * 0.01 * (double)(int)(*opponentSlot)->facing;
            }
        }
        if (field000a > 4 && field0168 == 3) {
            (*opponentSlot)->ResetFrame();
            (*opponentSlot)->ResetPose();
            ResetPose();
            (*opponentSlot)->field0128 = 1;
            effect.type = 0;
            effect.x = (double)((int(field0020)) + facing * 0x1d);
            effect.y = (double)((int(field0028)) + -0x53);
            effect.group = 2;
            effect.owner = 1;
            effect.layer = 1;
            contextOwner->EmitEffect(&effect);
            field0008 = 0x137;
            (*opponentSlot)->field0008 = 0x67;
            (*opponentSlot)->field0028 = -100.0;
            (*opponentSlot)->field0020 =
            (double)(facing * 0x16) + field0020;
            (*opponentSlot)->facing = facing;
            break;
        }
        ++field000c;
        if ((unsigned short)field000c >= frameDuration) {
            field000c = 0;
            ++field000a;
            field0168 = 0;
            if (field000a == 5) {
                field02c9 = 0x12;
            }
            if ((field000a == 8) && (field313c < 0xf)) {
                field000a = field000a + -3;
                ++field313c;
            }
            if (field000a >= frameCount) {
                field0008 = 0;
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
            if ((0.0 < field0038 + field0028) &&
                (field000a < 0xe)) {
                field0028 = 0.0;
                field000a = 0xe;
                field000c = 0;
                ResetFrame();
                SetVerticalShake(0xf,10);
                field02c9 = 0x16;
                ApplyDamage(0x578,900.0);
                (*opponentSlot)->field0140 = 0;
                (*opponentSlot)->ResetPose();
                (*opponentSlot)->field0008 = 0x62;
                effect.type = 400;
                effect.x = (double)(int(field0020));
                effect.y = (double)(int(field0028));
                effect.group = 2;
                effect.layer = 1;
                effect.flag0018 = (unsigned char)facing;
                EmitLocalEffect(&effect);
                effect.type = 0;
                contextOwner->EmitEffect(&effect);
                (*opponentSlot)->field014a = 0xb4;
                return;
            }
            field0038 = field0038 + field0048;
        }
        ++field000c;
        if ((unsigned short)field000c >= frameDuration) {
            field000c = 0;
            ++field000a;
            if (field000a == 1) {
                (*opponentSlot)->ResetPose();
                (*opponentSlot)->field0008 = 0x67;
                (*opponentSlot)->field0028 = -98.0;
                (*opponentSlot)->field0020 =
                (double)(facing * 0x23) + field0020;
            }
            if (field000a == 2) {
                (*opponentSlot)->field0028 = -98.0;
                (*opponentSlot)->field0020 =
                (double)(facing * 0x21) + field0020;
                if (0 < field3138) {
                    field000c = 0x96;
                }
            }
            if (field000a == 3) {
                (*opponentSlot)->field0028 = 0.0;
                (*opponentSlot)->field0020 =
                (double)(facing * 0x21) + field0020;
                (*opponentSlot)->facing = -facing;
                (*opponentSlot)->ResetPose();
                (*opponentSlot)->field0008 = 0x61;
                (*opponentSlot)->field012c = 1;
                ApplyDamage(300,980.0);
            }
            if ((field000a == 6) && (field3138 < 3)) {
                ++field3138;
                field000a = 0;
            }
            if (field000a == 9) {
                field0038 = -7.0;
                field0030 = 0.3;
                field0048 = 0.15;
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
        StartTrail(2);
        if (field000a < 6) {
            SetHorizontalShake(0x32,3);
        }
        if (0x10 < field000a) {
            field0038 = field0038 + field0048;
        }
        ++field000c;
        if ((unsigned short)field000c >= frameDuration) {
            field000c = 0;
            ++field000a;
            if (field000a == 1) {
                (*opponentSlot)->ResetPose();
                (*opponentSlot)->field0008 = 0x67;
                (*opponentSlot)->field0028 = -98.0;
                (*opponentSlot)->field0020 =
                (double)(facing * 0x23) + field0020;
            }
            if (field000a == 2) {
                (*opponentSlot)->field0028 = -98.0;
                (*opponentSlot)->field0020 =
                (double)(facing * 0x21) + field0020;
                if (0 < field3138) {
                    field000c = 0xa5;
                }
            }
            if (field000a == 3) {
                (*opponentSlot)->field0028 = 0.0;
                (*opponentSlot)->field0020 =
                (double)(facing * 0x21) + field0020;
                (*opponentSlot)->facing = -facing;
                (*opponentSlot)->ResetPose();
                (*opponentSlot)->field0008 = 0x61;
                (*opponentSlot)->field012c = 1;
                ApplyDamage(300,920.0);
            }
            if ((field000a == 6) && (field3138 < 6)) {
                ++field3138;
                field000a = 0;
            }
            if (field000a == 10) {
                (*opponentSlot)->ResetFrame();
                (*opponentSlot)->ResetPose();
                (*opponentSlot)->field0128 = 1;
                effect.type = 0;
                effect.x = (double)((int(field0020)) + facing * 0xf);
                effect.y = (double)((int(field0028)) + -5);
                effect.group = 2;
                effect.owner = 1;
                effect.layer = 1;
                contextOwner->EmitEffect(&effect);
                (*opponentSlot)->field0008 = 0x3f;
                (*opponentSlot)->field0028 = 0.0;
                (*opponentSlot)->field0020 =
                (double)(facing * 0x11) + field0020;
                (*opponentSlot)->facing = -facing;
                (*opponentSlot)->field00c0 = 0.0;
                (*opponentSlot)->field00c8 = -3.5;
                field02c9 = 0x1a;
            }
            if (field000a == 0x10) {
                field0038 = -3.0;
                field0048 = 0.035;
            }
            if (field000a == 0x1b) {
                field0038 = -2.0;
                field0048 = 0.013;
                field02c9 = 0x16;
                effect.owner = 1;
                effect.type = 0x193;
                effect.x = (double)(int(field0020));
                effect.y = (double)(int(field0028));
                effect.flag0018 = (unsigned char)facing;
                effect.group = 2;
                effect.layer = 1;
                EmitLocalEffect(&effect);
            }
            if ((field000a == 0x20) && (field3140 < 0xb)) {
                field000a = field000a + -3;
                ++field3140;
            }
            field0168 = 0;
            if (field000a >= frameCount) {
                field0008 = 0xfd;
                FaceOpponent();
                ResetPose();
            }
        }
        break;
    case 311:
        if ((field000a == 0) && ((unsigned short)field000c == 0)) {
            (*opponentSlot)->ResetPose();
        }
        contextOwner->SetSceneTimer(0xf);
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
                effect.x = (double)(int)((int(field0020)) + (char)(facing) * 0xe + ((unsigned short)RandomRange(0, 0x1e)));
                effect.y = (double)(int)((int(field0028)) + -0x62 + ((unsigned short)RandomRange(0, 0x1e)));
                effect.group = 2;
                effect.owner = 1;
                effect.layer = 1;
                contextOwner->EmitEffect(&effect);
            }
            if (field000a == 1) {
                (*opponentSlot)->field0008 = 0x67;
                (*opponentSlot)->ResetPose();
                (*opponentSlot)->field0028 = -101.0;
                (*opponentSlot)->field0020 =
                (double)(facing * 0x15) + field0020;
            }
            if (field000a == 2) {
                (*opponentSlot)->field0028 = -99.0;
                (*opponentSlot)->field0020 =
                (double)(facing * 0xf) + field0020;
                field02c9 = 0x16;
                effect.type = 0x193;
                effect.x = (double)(int(field0020));
                effect.y = (double)((int(field0028)) + -0xfa);
                effect.group = 2;
                effect.owner = 1;
                effect.flag0018 = (unsigned char)facing;
                effect.layer = 1;
                EmitLocalEffect(&effect);
            }
            if (field000a == 3) {
                SetVerticalShake(4,0);
                (*opponentSlot)->field0008 = 100;
                (*opponentSlot)->field0028 = -99.0;
                (*opponentSlot)->field0020 =
                (double)(facing * 0xf) + field0020;
            }
            if (field000a == 4) {
                (*opponentSlot)->field0008 = 0x67;
                (*opponentSlot)->field0028 = -99.0;
                (*opponentSlot)->field0020 =
                (double)(facing * 0xf) + field0020;
            }
            if (field000a == 5) {
                (*opponentSlot)->field0008 = 100;
                (*opponentSlot)->field0028 = -99.0;
                (*opponentSlot)->field0020 =
                (double)(facing * 0xf) + field0020;
            }
            if (field000a == 6) {
                (*opponentSlot)->field0008 = 0x67;
                (*opponentSlot)->field0028 = -99.0;
                (*opponentSlot)->field0020 =
                (double)(facing * 0xf) + field0020;
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
                effect.x = (double)(int(field0020));
                effect.y = (double)((int(field0028)) + 4);
                effect.group = 0;
                effect.owner = 1;
                effect.flag0018 = (unsigned char)facing;
                effect.layer = 1;
                contextOwner->EmitEffect(&effect);
                effect.type = 0x191;
                effect.x = (double)((int(field0020)) + facing * 0x28);
                effect.y = (double)(int(field0028));
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
        contextOwner->SetSceneTimer(0xf);
        if ((field000a == 0) && ((unsigned short)field000c == 0)) {
            field0030 = 0.0;
            field0038 = 0.0;
            field0048 = 0.0;
            field016c = 2;
        }
        if ((field000a == 6) && ((unsigned short)field000c == 0)) {
            SetHorizontalShake(0x32,0x2d);
            field014c = 0x78;
            SetTint(0xb0,3);
            effect.type = 0x46;
            effect.palette = 0x40;
            effect.x = (double)((int(field0020)) + facing * 0x17);
            effect.y = (double)((int(field0028)) + -0x1e);
            effect.group = 2;
            effect.owner = 1;
            effect.layer = 1;
            contextOwner->EmitEffect(&effect);
            effect.type = 0x47;
            contextOwner->EmitEffect(&effect);
        }
        if ((field000a == 2) && ((unsigned short)field000c == 0)) {
            field014c = 0;
            effect.type = 0x1f;
            effect.x = (double)(int(field0020));
            effect.y = (double)((int(field0028)) + 4);
            effect.group = 0;
            effect.owner = 1;
            effect.flag0018 = (unsigned char)facing;
            effect.layer = 1;
            contextOwner->EmitEffect(&effect);
            effect.type = 0x192;
            effect.x = (double)((int(field0020)) + facing * 0x2d);
            effect.y = (double)(int(field0028));
            effect.group = 2;
            effect.flag0018 = (unsigned char)facing;
            effect.owner = 1;
            effect.layer = 1;
            EmitLocalEffect(&effect);
        }
        if ((field000a == 8) && ((unsigned short)field000c == 0)) {
            effect.type = 0x1f;
            effect.x = (double)(int(field0020));
            effect.y = (double)((int(field0028)) + 4);
            effect.group = 0;
            effect.owner = 1;
            effect.flag0018 = (unsigned char)facing;
            effect.layer = 1;
            contextOwner->EmitEffect(&effect);
            effect.type = 0x191;
            effect.x = (double)((int(field0020)) + facing * 0x28);
            effect.y = (double)(int(field0028));
            effect.group = 2;
            effect.flag0018 = (unsigned char)facing;
            effect.owner = 1;
            effect.layer = 1;
            EmitLocalEffect(&effect);
        }
        if ((field000a == 2) && (field0168 == 3)) {
            SetVerticalShake(6,0x3c);
            (*opponentSlot)->field014a = 500;
            contextOwner->SetSceneTimer(0xf);
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
        contextOwner->SetSceneTimer(0xf);
        field0158 = 0;
        if ((field000a == 0) && ((unsigned short)field000c == 0)) {
            ResetFrame();
            if ((field000a == 1) && ((unsigned short)field000c == 0)) {
                field0148 = field0148 + -3000;
            }
            SetHorizontalShake(0x32,0x2d);
            field014c = 0x78;
            SetTint(0xb0,3);
            field0148 = field0148 + -3000;
            effect.type = 0x46;
            effect.palette = 0x40;
            effect.x = (double)((int(field0020)) + facing * 0x17);
            effect.y = (double)((int(field0028)) + -0x1e);
            effect.group = 2;
            effect.owner = 1;
            effect.layer = 1;
            contextOwner->EmitEffect(&effect);
            field02c9 = 0x25;
            effect.type = 0x47;
            contextOwner->EmitEffect(&effect);
        }
        if ((field0168 == 6) && (field000a == 2)) {
            ResetPose();
            field000a = 3;
            field0168 = 0;
            field014c = 0xa0;
            field02c9 = 3;
            effect.type = 0;
            effect.x = (double)((int(field0020)) + facing * 10);
            effect.y = (double)((int(field0028)) + -0x28);
            effect.group = 2;
            effect.layer = 1;
            contextOwner->EmitEffect(&effect);
        }
        else {
            ++field000c;
            if ((unsigned short)field000c >= frameDuration) {
                field000c = 0;
                ++field000a;
                field0168 = 0;
                if (field000a == 3) {
                    field000a = 4;
                }
                else if (field000a == 4) {
                    ResetPose();
                    field0008 = 0x138;
                }
                else if (field000a >= frameCount) {
                    field0008 = 0;
                    FaceOpponent();
                    ResetPose();
                }
            }
        }
        break;
    }
}
