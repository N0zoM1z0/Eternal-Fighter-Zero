// Mayu complete animation and state update dispatch.
#include "CharacterViews.h"
void Character05::Slot06()
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
        field0030 = 0.9;
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
        field0030 = -0.9;
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
            field0030 = 0.0;
        }
        if ((field000a == 3) && ((unsigned short)field000c == 0)) {
            field0048 = 0.055;
            field0038 = -2.8;
            field02c8 = 1;
        }
        if (4 < field000a) {
            field0038 = field0038 + field0048;
        }
        ++field000c;
        if ((unsigned short)field000c >= frameDuration) {
            field000c = 0;
            ++field000a;
            if (field000a >= frameCount) {
                field000a = field000a + -4;
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
            FaceOpponent();
            field0030 = 0.0;
        }
        if ((field000a == 3) && ((unsigned short)field000c == 0)) {
            field0048 = 0.055;
            field0038 = -2.8;
            field0030 = 1.0;
            field02c8 = 1;
        }
        if (4 < field000a) {
            field0038 = field0038 + field0048;
        }
        ++field000c;
        if ((unsigned short)field000c >= frameDuration) {
            field000c = 0;
            ++field000a;
            if (field000a >= frameCount) {
                field000a = field000a + -4;
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
            FaceOpponent();
            field0030 = 0.0;
        }
        if ((field000a == 3) && ((unsigned short)field000c == 0)) {
            field0048 = 0.055;
            field0038 = -2.8;
            field0030 = -1.0;
            field02c8 = 1;
        }
        if (4 < field000a) {
            field0038 = field0038 + field0048;
        }
        ++field000c;
        if ((unsigned short)field000c >= frameDuration) {
            field000c = 0;
            ++field000a;
            if (field000a >= frameCount) {
                field000a = field000a + -4;
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
    case 10:
        field0038 = field0038 + field0048;
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
        field0048 = 0.055;
        if ((field000a == 0) && ((unsigned short)field000c == 0)) {
            field0038 = -3.2;
            field0030 = 0.0;
        }
        field0038 = field0038 + field0048;
        ++field000c;
        if ((unsigned short)field000c >= frameDuration) {
            field000c = 0;
            ++field000a;
            if (field000a >= frameCount) {
                field000a = field000a + -4;
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
        field0048 = 0.055;
        if ((field000a == 0) && ((unsigned short)field000c == 0)) {
            field0038 = -3.2;
            field0030 = 1.0;
        }
        field0038 = field0038 + field0048;
        ++field000c;
        if ((unsigned short)field000c >= frameDuration) {
            field000c = 0;
            ++field000a;
            if (field000a >= frameCount) {
                field000a = field000a + -4;
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
        field0048 = 0.055;
        if ((field000a == 0) && ((unsigned short)field000c == 0)) {
            field0038 = -3.2;
            field0030 = -1.0;
        }
        field0038 = field0038 + field0048;
        ++field000c;
        if ((unsigned short)field000c >= frameDuration) {
            field000c = 0;
            ++field000a;
            if (field000a >= frameCount) {
                field000a = field000a + -4;
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
        if ((field000a == 0) && ((unsigned short)field000c == 0)) {
            field0148 = field0148 + 10;
            field0030 =
            (2.0 - (*opponentSlot)->field0178 / 10000.0) * -1.1;
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
            field00b8 = (1.0 - (double)((field0028 < 0.0)) * 0.2) * field0030;
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
        if ((field000a == 0) && ((unsigned short)field000c == 0)) {
            field0148 = field0148 + 0xf;
            field0030 =
            (2.0 - (*opponentSlot)->field0178 / 10000.0) * -1.5;
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
            field00b8 = (1.0 - (double)((field0028 < 0.0)) * 0.2) * field0030;
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
        if ((field000a == 0) && ((unsigned short)field000c == 0)) {
            field0148 = field0148 + 0x14;
            field0030 =
            (2.0 - (*opponentSlot)->field0178 / 10000.0) * -1.8;
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
            field00b8 = (1.0 - (double)((field0028 < 0.0)) * 0.2) * field0030;
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
        if ((field000a == 0) && ((unsigned short)field000c == 0)) {
            field0148 = field0148 + 10;
            field0030 =
            (2.0 - (*opponentSlot)->field0178 / 10000.0) * -1.1;
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
            field00b8 = (1.0 - (double)((field0028 < 0.0)) * 0.2) * field0030;
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
        if ((field000a == 0) && ((unsigned short)field000c == 0)) {
            field0148 = field0148 + 0xf;
            field0030 =
            (2.0 - (*opponentSlot)->field0178 / 10000.0) * -1.5;
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
            field00b8 = (1.0 - (double)((field0028 < 0.0)) * 0.2) * field0030;
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
        if ((field000a == 0) && ((unsigned short)field000c == 0)) {
            field0148 = field0148 + 0x14;
            field0030 =
            (2.0 - (*opponentSlot)->field0178 / 10000.0) * -1.8;
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
            field00b8 = (1.0 - (double)((field0028 < 0.0)) * 0.2) * field0030;
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
        if ((field000a == 0) && ((unsigned short)field000c == 0)) {
            field0148 = field0148 + 10;
            field0030 =
            (2.0 - (*opponentSlot)->field0178 / 10000.0) * -1.1;
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
            field00b8 = (1.0 - (double)((field0028 < 0.0)) * 0.2) * field0030;
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
        if ((field000a == 0) && ((unsigned short)field000c == 0)) {
            field0148 = field0148 + 0xf;
            field0030 =
            (2.0 - (*opponentSlot)->field0178 / 10000.0) * -1.5;
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
            field00b8 = (1.0 - (double)((field0028 < 0.0)) * 0.2) * field0030;
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
        if ((field000a == 0) && ((unsigned short)field000c == 0)) {
            field0148 = field0148 + 0x14;
            field0030 =
            (2.0 - (*opponentSlot)->field0178 / 10000.0) * -1.8;
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
            field00b8 = (1.0 - (double)((field0028 < 0.0)) * 0.2) * field0030;
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
            field0038 = field0038 * 0.75 + field00c8;
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
            field0038 = field0038 * 0.75 + field00c8;
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
            field0038 = field0038 * 0.75 + field00c8;
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
            field0038 = field0038 * 0.75 + field00c8;
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
            field0038 = field0038 * 0.75 + field00c8;
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
            field0038 = field0038 * 0.75 + field00c8;
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
            field0038 = field0038 * 0.75 + field00c8;
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
        if (((field000a == 0) && ((unsigned short)field000c == 0)) && (field3138 == 0))
        {
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
        field0030 = 0.0;
        field0038 = 0.0;
        if ((field0020 - 20.0 <= 0.0) ||
            (639.0 <= field0020 + 20.0)) {
            field00b8 = (1.0 - (double)(((*opponentSlot)->field0028 < 0.0)) * 0.25) * field0030;
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
        field0030 = 0.0;
        field0038 = 0.0;
        if ((field0020 - 20.0 <= 0.0) ||
            (639.0 <= field0020 + 20.0)) {
            field00b8 = (1.0 - (double)(((*opponentSlot)->field0028 < 0.0)) * 0.25) * field0030;
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
        field0030 = 0.0;
        field0038 = 0.0;
        if ((field0020 - 20.0 <= 0.0) ||
            (639.0 <= field0020 + 20.0)) {
            field00b8 = (1.0 - (double)(((*opponentSlot)->field0028 < 0.0)) * 0.25) * field0030;
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
            field00b8 = (1.0 - (double)(((*opponentSlot)->field0028 < 0.0)) * 0.25) * field0030;
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
            field00b8 = (1.0 - (double)(((*opponentSlot)->field0028 < 0.0)) * 0.25) * field0030;
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
            field00b8 = (1.0 - (double)(((*opponentSlot)->field0028 < 0.0)) * 0.25) * field0030;
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
        if (((field000a == 0) && ((unsigned short)field000c == 0)) && (field3138 == 0))
        {
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
        if (field000a < 9) {
            field0038 = field0038 + field0048;
        }
        ++field000c;
        if ((unsigned short)field000c >= frameDuration) {
            field000c = 0;
            ++field000a;
            if (field000a == 3) {
                field0038 = -1.8;
                field0048 = 0.05;
            }
            if (field000a == 9) {
                field000a = field000a + -4;
            }
            if (((field000a < 9) && (4 < field000a)) &&
                (0.0 < field0028 + field0038)) {
                field0028 = 0.0;
                field0038 = 0.0;
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
            if (field000a == 0xc) {
                field0048 = 0.035;
            }
            if (field000a >= frameCount) {
                field000a = field000a + -4;
            }
        }
        break;
    case 163:
        if ((field000a == 0) && ((unsigned short)field000c == 0)) {
            field0038 = 0.0;
            field0048 = 0.0;
        }
        field0038 = field0038 + field0048;
        if ((field000a == 6) &&
            (field0030 = field0030 - 0.05,
            field0030 < 0.5)) {
            field0030 = 0.5;
        }
        if ((field000a == 2) && ((unsigned short)field000c == 0)) {
            field0030 = 2.5;
            field0038 = -1.6;
            field0048 = 0.05;
        }
        if ((field000a == 6) && ((unsigned short)field000c == 0)) {
            field0048 = 0.08;
        }
        if (field0028 + field0038 > 0.0) {
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
                    field0048 = 0.08;
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
            field0030 = 0.0;
            field0038 = 0.0;
        }
        if (field000a > 0) {
            field0030 = field0030 + 0.055;
        }
        if (field0030 > 0.0) {
            field0030 = 0.0;
        }
        if (field0028 + field0038 > 0.0) {
            ResetFrame();
            field0028 = 0.0;
            ResetPose();
            field0008 = 0xd;
            break;
        }
        field0038 = field0038 + field0048;
        ++field000c;
        if ((unsigned short)field000c >= frameDuration) {
            field000c = 0;
            ++field000a;
            if (field000a == 3) {
                field0030 = -3.5;
                field0038 = -1.5;
                field0048 = 0.05;
            }
            if (field000a >= frameCount) {
                field000a = field000a + -4;
            }
        }
        break;
    case 165:
        if ((field000a == 0) && ((unsigned short)field000c == 0)) {
            field0030 = 1.8;
            StartTrail(3);
            field0038 = 0.0;
            field0048 = 0.0;
            if (field3138 == 0) {
                field02c9 = 0x11;
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
            field0030 = 1.3;
            field0048 = 0.03;
            if ((FaceOpponent()) != 0) {
                field0030 = -field0030;
            }
        }
        if ((inputX != facing) && (field3138 >= 48)) {
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
        if ((field000a == 0) && ((unsigned short)field000c == 0)) {
            field0030 = -1.8;
            field0038 = 0.0;
            field0048 = 0.0;
            StartTrail(3);
            if (field3138 == 0) {
                field02c9 = 0x11;
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
            field0030 = 0.0;
            field0038 = 0.0;
            if (field0120 == '\x01') {
                field0178 = field0118 * 5.0 + field0178
                ;
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
            if (field0048 == 0.0) {
                field0048 = 0.035;
            }
            if (field0120 == '\x01') {
                field0178 = field0118 * 5.0 + field0178
                ;
            }
            field0118 = 0.0;
            field014c = 0x5a;
            SetTint(0xb0,3);
        }
        if ((field000a == 0) && ((unsigned short)field000c == 0)) {
            field02c9 = 0x12;
            effect.type = 1;
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
                if (field0048 == 0.0) {
                    field0048 = 0.035;
                }
                ResetPose();
            }
        }
        break;
    case 178:
        field0030 = field0030 - 0.08;
        if (field0030 < 0.0) {
            field0030 = 0.0;
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
            field0030 = 0.0;
            field0038 = 0.0;
            field0048 = 0.0;
        }
        if (field0028 < 0.0) {
            field0038 = field0038 + field0048;
        }
        if ((0.0 < field0028 + field0038) &&
            (field000a < 0xc)) {
            ResetFrame();
            field0028 = 0.0;
            field000c = 0;
            field000a = 0xc;
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
        field0030 = 0.0;
        field0038 = 0.0;
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
            field0030 = 0.0;
            field0038 = 0.0;
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
        field0030 = field0030 - 0.02;
        if (field0030 <= 0.0) {
            field0030 = 0.0;
        }
        if ((field000a == 0) && ((unsigned short)field000c == 0)) {
            field0030 = 0.0;
            field0038 = 0.0;
        }
        if ((field000a == 2) && ((unsigned short)field000c == 0)) {
            field0148 = field0148 + 0xf;
            field02c9 = 0x14;
            field016c = 1;
            field0030 = 1.2;
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
            field0030 = 0.0;
            field0038 = 0.0;
            field016c = 2;
        }
        if ((field000a == 1) && ((unsigned short)field000c == 0)) {
            field0148 = field0148 + 0x23;
            field02c9 = 0x14;
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
        field0030 = 0.0;
        field0038 = 0.0;
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
            field0148 = field0148 + 0xd;
            field02c9 = 0x14;
            field016c = 1;
        }
        if ((field0030 > 0.0) &&
            (field0030 = field0030 - 0.025,
            field0030 < 0.0)) {
            field0030 = 0.0;
        }
        ++field000c;
        if ((unsigned short)field000c >= frameDuration) {
            field000c = 0;
            ++field000a;
            if (field000a == 3) {
                field0030 = 1.5;
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
            field0148 = field0148 + 0x19;
            field0030 = 3.0;
        }
        if (1 < field000a) {
            field0030 = field0030 - 0.07;
            if (field0030 < 0.0) {
                field0030 = 0.0;
            }
            if (field0030 == 0.0) {
                field016c = 0;
            }
        }
        ++field000c;
        if ((unsigned short)field000c >= frameDuration) {
            field000c = 0;
            ++field000a;
            field0168 = 0;
            if (field000a == 3) {
                field02c9 = 0x14;
                field016c = 1;
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
                ResetPose();
                field0008 = 9;
            }
        }
        break;
    case 208:
        field0038 = field0038 + field0048;
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
            field0148 = field0148 + 0xd;
            field016c = 1;
            field02c9 = 0x14;
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
        field0038 = field0038 + field0048;
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
        if (field0030 <= 0.0) {
            field0030 = 0.0;
        }
        if ((field000a == 0) && ((unsigned short)field000c == 0)) {
            field0030 = 0.0;
            field0038 = 0.0;
        }
        if (field0028 < 0.0 && (field0038 = field0038 + field0048, field0028 + field0038 > 0.0)) {
            field0028 = 0.0;
            field0038 = 0.0;
            field000c = 0;
            field000a = 5;
            break;
        }
        if ((4 < field000a) &&
            (field0030 = field0030 - 0.036,
            field0030 < 0.0)) {
            field0030 = 0.0;
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
            if (field000a == 1) {
                field0030 = 1.0;
                field0038 = -2.6;
                field0048 = 0.065;
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
            field0148 = field0148 + 0xd;
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
        if ((field000a == 1) && (field0168 == 3)) {
            ResetFrame();
            ResetPose();
            (*opponentSlot)->ResetFrame();
            (*opponentSlot)->ResetPose();
            field0008 = 0xdd;
            (*opponentSlot)->field0008 = 0x6b;
            effect.type = 0;
            effect.x = (double)((int(field0020)) + facing * 0x25);
            effect.y = (double)((int(field0028)) + -0x30);
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
                ((*opponentSlot)->field0028 == 0.0)) {
                field016c = 1;
            }
            else {
                field016c = 0;
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
            field0020 =
            (*opponentSlot)->field0020 -
            (double)((int)(*opponentSlot)->field2ad0[0] * (int)facing);
            field0028 = (double)((*opponentSlot)->field2af8[0] + 0x1e);
        }
        if ((field000a == 3) && ((unsigned short)field000c == 0)) {
            (*opponentSlot)->field0008 = 0x3b;
            (*opponentSlot)->ResetPose();
            (*opponentSlot)->field00c0 = -2.5;
            (*opponentSlot)->field00c8 = -1.0;
            (*opponentSlot)->field0048 = 0.035;
            field0030 = -1.8;
            field0038 = -1.9;
            field0048 = 0.04;
            effect.type = 0;
            effect.palette = 2;
            effect.x = (double)(int(field0020));
            effect.y = (double)((int(field0028)) + -0x2d);
            effect.group = 2;
            effect.layer = 1;
            contextOwner->EmitEffect(&effect);
            ApplyDamage(1000,750.0);
        }
        if (2 < field000a) {
            field0038 = field0038 + field0048;
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
        field0038 = field0038 + field0048;
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
            field0030 = 0.5;
        }
        if ((field000a == 1) && ((unsigned short)field000c == 0)) {
            field0148 = field0148 + 5;
            field02c9 = 0x15;
            field016c = 1;
        }
        if (field0028 + field0038 >= 0.0) {
            field0028 = 0.0;
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
        field0038 = field0038 + field0048;
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
            field0030 = 0.5;
        }
        if ((field000a == 1) && ((unsigned short)field000c == 0)) {
            field0148 = field0148 + 0xd;
            field016c = 2;
            field02c9 = 0x14;
        }
        if (field0028 + field0038 >= 0.0) {
            field0028 = 0.0;
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
        field0038 = field0038 + field0048;
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
            field0030 = 0.5;
        }
        if ((field000a == 1) && ((unsigned short)field000c == 0)) {
            field0148 = field0148 + 10;
            field02c9 = 0x14;
            field016c = 1;
        }
        if (field0028 + field0038 >= 0.0) {
            field0028 = 0.0;
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
        field0030 = 0.0;
        field0038 = 0.0;
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
        field0038 = field0038 + field0048;
        if ((field000a == 2) && (field0168 == 3)) {
            (*opponentSlot)->ResetFrame();
            (*opponentSlot)->ResetPose();
            (*opponentSlot)->field0128 = 1;
            effect.type = 0;
            effect.x = (double)((int(field0020)) + facing * 0x16);
            effect.y = (double)((int(field0028)) + -0x36);
            effect.group = 2;
            effect.layer = 1;
            contextOwner->EmitEffect(&effect);
            field000a = 0;
            field000c = 0;
            field0008 = 0xf9;
            (*opponentSlot)->field0008 = 0x67;
            (*opponentSlot)->field0020 =
            (double)(facing * 0x16) + field0020;
            (*opponentSlot)->field0028 = field0028 - 52.0;
            break;
        }
        ++field000c;
        if ((unsigned short)field000c >= frameDuration) {
            field000c = 0;
            ++field000a;
            if (field000a == 2 && (*opponentSlot)->field0028 < 0.0 &&
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
        field013e = 2;
        if (field000a < 0xb) {
            if ((field0020 > 6100.0) && (facing == '\x01')) {
                field0020 = 6100.0;
                field0030 = 0.0;
            }
            if ((field0020 < 30.0) && (facing == -1)) {
                field0020 = 30.0;
                field0030 = 0.0;
            }
            SetHorizontalOffset(0x32,3);
            SetHorizontalShake(0x32,3);
        }
        if (((field000a < 10) ||
            ((0xb < field000a && (field000a < 0xf)))) &&
            (field0038 = field0038 + field0048,
            0.0 < field0038 + field0028)) {
            if (field000a < 10) {
                field0028 = 0.0;
                ResetFrame();
                (*opponentSlot)->ResetPose();
                (*opponentSlot)->field0008 = 0x62;
                (*opponentSlot)->field0028 = 0;
                (*opponentSlot)->field0020 =
                (double)(int)facing + field0020;
                (*opponentSlot)->facing = -facing;
                (*opponentSlot)->ResetFrame();
                ApplyDamage(1000,500.0);
                effect.type = 0;
                effect.x = (double)(int(field0020));
                effect.y = (double)(int(field0028));
                effect.group = 2;
                effect.layer = 1;
                contextOwner->EmitEffect(&effect);
                field000c = 0;
                field000a = 10;
                field02c9 = 2;
                return;
            }
            if (field000a == 0xe) {
                field0028 = 0.0;
                ResetFrame();
                field000c = 0;
                field000a = 0xf;
                return;
            }
        }
        if (field000a < 1) {
            (*opponentSlot)->field0008 = 0x67;
            (*opponentSlot)->field0020 =
            (double)(facing * 0x16) + field0020;
            (*opponentSlot)->field0028 = field0028 - 52.0;
        }
        if (field000a == 1) {
            (*opponentSlot)->field0008 = 0x67;
            (*opponentSlot)->field0020 =
            (15.0 + field0030) * facing +
            field0020;
            (*opponentSlot)->field0028 =
            -70.0 + field0038 + field0028;
        }
        if (field000a == 2) {
            (*opponentSlot)->field0008 = 0x76;
            (*opponentSlot)->field0020 =
            (-25.0 + field0030) * facing +
            field0020;
            (*opponentSlot)->field0028 =
            -65.0 + field0038 + field0028;
            (*opponentSlot)->facing = facing;
        }
        if (field000a == 3) {
            (*opponentSlot)->field0008 = 0x75;
            (*opponentSlot)->field0020 =
            (-28.0 + field0030) * facing +
            field0020;
            (*opponentSlot)->field0028 =
            -43.0 + field0038 + field0028;
            (*opponentSlot)->facing = facing;
        }
        if (field000a == 4) {
            (*opponentSlot)->field0008 = 0x75;
            (*opponentSlot)->field0020 =
            (-12.0 + field0030) * facing +
            field0020;
            (*opponentSlot)->field0028 =
            -29.0 + field0038 + field0028;
            (*opponentSlot)->facing = facing;
        }
        if (field000a == 5) {
            (*opponentSlot)->field0008 = 0x68;
            (*opponentSlot)->field0020 =
            (12.0 + field0030) * facing +
            field0020;
            (*opponentSlot)->field0028 =
            -23.0 + field0038 + field0028;
            (*opponentSlot)->facing = -facing;
        }
        if (field000a == 6) {
            (*opponentSlot)->field0008 = 0x68;
            (*opponentSlot)->field0020 =
            (23.0 + field0030) * facing +
            field0020;
            (*opponentSlot)->field0028 =
            -36.0 + field0038 + field0028;
            (*opponentSlot)->facing = -facing;
        }
        if (field000a == 7) {
            (*opponentSlot)->field0008 = 0x67;
            (*opponentSlot)->field0020 =
            (28.0 + field0030) * facing +
            field0020;
            (*opponentSlot)->field0028 =
            -58.0 + field0038 + field0028;
            (*opponentSlot)->facing = -facing;
        }
        if (field000a == 8) {
            (*opponentSlot)->field0008 = 0x67;
            (*opponentSlot)->field0020 =
            (14.0 + field0030) * facing +
            field0020;
            (*opponentSlot)->field0028 =
            -73.0 + field0038 + field0028;
            (*opponentSlot)->facing = -facing;
        }
        if (field000a == 9) {
            (*opponentSlot)->field0008 = 0x76;
            (*opponentSlot)->field0020 =
            (-12.0 + field0030) * facing +
            field0020;
            (*opponentSlot)->field0028 =
            -78.0 + field0038 + field0028;
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
                field0030 = -0.8;
                field0038 = -1.0;
                field0048 = 0.035;
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
            field016c = 0;
        }
        if (field000a > 2 && field000a < 8 && field0168 == 3) {
            (*opponentSlot)->ResetPose();
            (*opponentSlot)->ResetFrame();
            (*opponentSlot)->field0008 = 0x6b;
            ResetPose();
            field0008 = 0xfd;
            field0028 = (double)(field2af8[0] + 0x32);
            field0020 =
            (*opponentSlot)->field0020 + (-field2ad0[0] - 0x14) * facing;
            effect.type = 0;
            effect.x = (double)((int(field0020)) + facing * 7);
            effect.y = (double)((int(field0028)) + -0x2c);
            effect.group = 2;
            effect.layer = 1;
            contextOwner->EmitEffect(&effect);
            break;
        }
        if ((2 < field000a) && (field000a < 8)) {
            if ((*opponentSlot)->field0028 == 0.0) {
                field016c = 1;
            }
            else {
                field016c = 0;
            }
        }
        if (field000a == 6) {
            field3140 = 1;
        }
        if ((7 < field000a) &&
            (field0030 = field0030 - 0.035,
            field0030 < 0.0)) {
            field0030 = 0.0;
        }
        ++field000c;
        if ((unsigned short)field000c >= frameDuration) {
            field000c = 0;
            ++field000a;
            field0168 = 0;
            if (field000a == 1) {
                field016c = 0;
            }
            if (field000a == 3) {
                field0030 = 1.8;
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
            field016c = 0;
        }
        if (field000a > 2 && field000a < 8 && field0168 == 3) {
            (*opponentSlot)->ResetPose();
            (*opponentSlot)->ResetFrame();
            (*opponentSlot)->field0008 = 0x6b;
            ResetPose();
            field0008 = 0xfd;
            field0028 = (double)(field2af8[0] + 0x32);
            field0020 =
            (*opponentSlot)->field0020 + (-field2ad0[0] - 0x14) * facing;
            effect.type = 0;
            effect.x = (double)((int(field0020)) + facing * 7);
            effect.y = (double)((int(field0028)) + -0x2c);
            effect.group = 2;
            effect.layer = 1;
            contextOwner->EmitEffect(&effect);
            break;
        }
        if (((2 < field000a) && (field000a < 8)) &&
            (0 < field3140)) {
            if ((*opponentSlot)->field0028 == 0.0) {
                field016c = 1;
            }
            else {
                field016c = 0;
            }
        }
        if (field000a == 6) {
            field3140 = 1;
        }
        if ((7 < field000a) &&
            (field0030 = field0030 - 0.035,
            field0030 < 0.0)) {
            field0030 = 0.0;
        }
        ++field000c;
        if ((unsigned short)field000c >= frameDuration) {
            field000c = 0;
            ++field000a;
            field0168 = 0;
            if (field000a == 1) {
                field016c = 0;
            }
            if (field000a == 3) {
                field0030 = 2.4;
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
            field016c = 0;
            ResetFrame();
            if (field0120 == '\0') {
                field0118 = field0118 - 500.0;
            }
            else {
                field0118 = field0118 - 250.0;
            }
            effect.type = 0x21;
            effect.palette = 0xb;
            effect.x = (double)((int(field0020)) + facing * 0x14);
            effect.y = (double)((int(field0028)) + -0x32);
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
            field0028 = (double)(field2af8[0] + 0x32);
            field0020 =
            (*opponentSlot)->field0020 + (-field2ad0[0] - 0x14) * facing;
            effect.type = 0;
            effect.x = (double)((int(field0020)) + facing * 7);
            effect.y = (double)((int(field0028)) + -0x2c);
            effect.group = 2;
            effect.layer = 1;
            contextOwner->EmitEffect(&effect);
            break;
        }
        if ((2 < field000a) && (field000a < 8)) {
            if ((*opponentSlot)->field0028 == 0.0) {
                field016c = 1;
            }
            else {
                field016c = 0;
            }
        }
        if (field000a == 6) {
            field3140 = 1;
        }
        if ((7 < field000a) &&
            (field0030 = field0030 - 0.035,
            field0030 < 0.0)) {
            field0030 = 0.0;
        }
        ++field000c;
        if ((unsigned short)field000c >= frameDuration) {
            field000c = 0;
            ++field000a;
            field0168 = 0;
            if (field000a == 1) {
                field016c = 0;
            }
            if (field000a == 3) {
                field0030 = 1.8;
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
            field0030 = field0030 - 0.035;
            if (field0030 < 0.0) {
                field0030 = 0.0;
            }
            if (((*opponentSlot)->CollisionSide()) != '\0') {
                ResetFrame();
                (*opponentSlot)->ResetFrame();
            }
            if (((*opponentSlot)->CollisionSide()) == '\0') {
                (*opponentSlot)->field0020 =
                (double)((field2ad0[0] + 0x14) * (int)facing) +
                field0020;
            }
        }
        if (field000a == 3) {
            (*opponentSlot)->field0008 = 0x76;
            (*opponentSlot)->field0020 =
            (15.0 + field0030) * facing +
            field0020;
            (*opponentSlot)->field0028 =
            -69.0 + field0038 + field0028;
        }
        if (2 < field000a) {
            field0038 = field0038 + field0048;
        }
        if (field000a > 3 && field0038 + field0028 > 0.0) {
            ResetPose();
            ResetFrame();
            field0008 = 3;
            field0028 = 0.0;
            break;
        }
        if ((field000a == 4) && ((unsigned short)field000c == 0)) {
            (*opponentSlot)->ResetPose();
            (*opponentSlot)->field0008 = 0x3f;
            (*opponentSlot)->field0020 =
            (-31.0 + field0030) * facing +
            field0020;
            (*opponentSlot)->field0028 =
            -33.0 + field0038 + field0028;
            ApplyDamage(500,750.0);
            --field0174;
            --field00f4;
            (*opponentSlot)->field00c0 = 0.8;
            (*opponentSlot)->field00c8 = -3.2;
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
                field0030 = -1.0;
                field0038 = -1.3;
                field0048 = 0.03;
            }
            if (field000a >= frameCount) {
                field0008 = 0;
                ResetPose();
            }
        }
        break;
    case 254:
        if (field000a < 3) {
            field0030 = field0030 - 0.035;
            if (field0030 < 0.0) {
                field0030 = 0.0;
            }
            if (((*opponentSlot)->CollisionSide()) != '\0') {
                ResetFrame();
                (*opponentSlot)->ResetFrame();
            }
            if (((*opponentSlot)->CollisionSide()) == '\0') {
                (*opponentSlot)->field0020 =
                (double)((field2ad0[0] + 0x14) * (int)facing) +
                field0020;
            }
        }
        if (field000a == 3) {
            (*opponentSlot)->field0008 = 0x76;
            (*opponentSlot)->field0020 =
            (15.0 + field0030) * facing +
            field0020;
            (*opponentSlot)->field0028 =
            -69.0 + field0038 + field0028;
        }
        if (2 < field000a) {
            field0038 = field0038 + field0048;
        }
        if (field000a > 3 && field0038 + field0028 > 0.0) {
            ResetPose();
            ResetFrame();
            field0008 = 3;
            field0028 = 0.0;
            break;
        }
        if ((field000a == 4) && ((unsigned short)field000c == 0)) {
            (*opponentSlot)->ResetPose();
            (*opponentSlot)->field0008 = 0x43;
            (*opponentSlot)->field0020 =
            (-41.0 + field0030) * facing +
            field0020;
            (*opponentSlot)->field0028 =
            -43.0 + field0038 + field0028;
            ApplyDamage(1000,800.0);
            --field0174;
            --field00f4;
            (*opponentSlot)->facing = facing;
            (*opponentSlot)->field00c0 = -4.0;
            (*opponentSlot)->field00c8 = -0.8;
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
                field0030 = -1.0;
                field0038 = -2.1;
                field0048 = 0.025;
            }
            if (field000a >= frameCount) {
                field0008 = 0;
                ResetPose();
            }
        }
        break;
    case 255:
        if ((field000a == 0) && ((unsigned short)field000c == 0)) {
            field0030 = field0030 * 0.3;
            field0038 = field0038 * 0.5;
            field0048 = 0.035;
            field016c = 9;
        }
        if ((((field000a == 1) || (field000a == 3)) ||
            (field000a == 7)) && ((unsigned short)field000c == 0)) {
            field02c9 = 0x15;
        }
        if (10 < field000a) {
            field0038 = field0038 + field0048;
        }
        if (field0028 + field0038 > 0.0) {
            ResetPose();
            ResetFrame();
            field0008 = 0x102;
            field0028 = 0.0;
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
            field0030 = 0.5;
            field0038 = 3.0;
            field016c = 1;
            field02c9 = 0x23;
            field0148 = field0148 + 0x23;
        }
        if (field0028 + field0038 > 0.0 && field000a > 2) {
            field000c = 0;
            field000a = 0;
            field0028 = 0.0;
            ResetFrame();
            field0008 = 0x101;
            break;
        }
        ++field000c;
        if ((unsigned short)field000c >= frameDuration) {
            field000c = 0;
            ++field000a;
            if (0 < field016c) {
                field0168 = 0;
            }
            if (field000a >= frameCount) {
                field000a = field000a + -2;
            }
        }
        break;
    case 257:
        field0030 = field0030 - 0.04;
        if (field0030 < 0.0) {
            field0030 = 0.0;
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
        field0030 = field0030 - 0.04;
        if (field0030 < 0.0) {
            field0030 = 0.0;
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
            (field0030 = field0030 - 0.02,
            field0030 < 0.0)) {
            field0030 = 0.0;
        }
        if ((field000a == 7) && ((unsigned short)field000c == 0)) {
            field016c = 1;
            field0030 = 3.0;
        }
        ++field000c;
        if ((unsigned short)field000c >= frameDuration) {
            field000c = 0;
            ++field000a;
            if (0 < field016c) {
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
        field0038 = field0038 + field0048;
        if ((0xd < field000a) &&
            (field0030 = field0030 - 0.03,
            field0030 < 0.0)) {
            field0030 = 0.0;
        }
        if ((field0262 == 10) && (0xd < field000a)) {
            ResetPose();
            field0008 = 0x122;
            break;
        }
        if (field0028 < 0.0 && field0038 > 0.0 && buttonPulse[0] == 1) {
            ResetPose();
            ResetFrame();
            field0008 = 0x100;
            break;
        }
        if (field0038 + field0028 > 0.0 && field000a > 5 && field000a < 10) {
            field000a = 0xe;
            field000c = 0;
            field0028 = 0.0;
            field0038 = 0.0;
            field0048 = 0.0;
            break;
        }
        if (field0038 + field0028 > 0.0 && field000a > 9 && field000a < 14) {
            field000a = 0xe;
            field000c = 0;
            field0028 = 0.0;
            field0038 = 0.0;
            field0048 = 0.0;
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
                field0030 = 1.2;
                field0038 = -3.3;
                field0048 = 0.055;
                field016c = 1;
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
            effect.x = (double)((int(field0020)) + facing * 0x14);
            effect.y = (double)((int(field0028)) + -0x32);
            effect.group = 2;
            effect.layer = 1;
            contextOwner->EmitEffect(&effect);
            field0028 = field0028 - 25.0;
            field0030 = 3.0;
            field016c = 1;
        }
        field0038 = field0038 + field0048;
        if ((9 < field000a) &&
            (field0030 = field0030 - 0.03,
            field0030 < 0.0)) {
            field0030 = 0.0;
        }
        if (field0168 > 1 && field000a > 1 && field000a < 6) {
            field000a = 6;
            field000c = 0;
            field0030 = -field0030 * 0.1;
            field0038 = -1.5;
            field0048 = 0.036;
            break;
        }
        if (field0038 + field0028 > 0.0 && field000a > 5 && field000a < 10) {
            field000a = 10;
            field000c = 0;
            field0028 = 0.0;
            field0038 = 0.0;
            field0048 = 0.0;
            break;
        }
        ++field000c;
        if ((unsigned short)field000c >= frameDuration) {
            field000c = 0;
            ++field000a;
            if (0 < field016c) {
                field0168 = 0;
            }
            if (field000a == 6) {
                if (field3138 < 4) {
                    field000a = field000a + -4;
                    ++field3138;
                } else {
                    field000a = 10;
                    field0028 = 0.0;
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
        field0030 = field0030 - 0.035;
        if (field0030 < 0.0) {
            field0030 = 0.0;
        }
        if (field0028 < 0.0) {
            field0048 = 0.055;
            field0038 = field0038 + field0048;
        }
        if (field000a > 4 && field000a < 15 && field0028 + field0038 > 0.0) {
            field000c = 0;
            field000a = 0xf;
            field0028 = 0.0;
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
                field0038 = -3.3;
                field016c = 3;
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
        field0038 = field0038 + field0048;
        if ((10 < field000a) &&
            (field0030 = field0030 - 0.03,
            field0030 < 0.0)) {
            field0030 = 0.0;
        }
        if (field0028 < 0.0 && field0038 > 0.0 && buttonPulse[0] == 1) {
            ResetPose();
            ResetFrame();
            field0008 = 0x100;
            break;
        }
        if (field0038 + field0028 > 0.0 && field000a > 2 && field000a < 10) {
            ResetPose();
            ResetFrame();
            field0028 = 0.0;
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
                field0030 = 0.8;
                field0038 = -3.1;
                field0048 = 0.055;
                field016c = 1;
            }
            if (field000a >= frameCount) {
                field000a = field000a + -4;
            }
        }
        break;
    case 264:
        field0030 = field0030 - 0.05;
        if (field0030 < 0.0) {
            field0030 = 0.0;
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
        field0030 = field0030 - 0.05;
        if (field0030 < 0.0) {
            field0030 = 0.0;
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
            field0030 = 0.0;
            field0038 = 0.0;
            field016c = 1;
        }
        if ((field000a == 2) && ((unsigned short)field000c == 0)) {
            field02c9 = 0x15;
            field0148 = field0148 + 0x23;
            field016c = 1;
        }
        if (1 < field000a) {
            field0038 = field0038 + field0048;
            field0030 = field0030 - 0.06;
            if (field0030 < 0.0) {
                field0030 = 0.0;
            }
        }
        if ((0.0 < field0028 + field0038) &&
            (field000a == 7)) {
            field000a = 8;
            field000c = 0;
            field0028 = 0.0;
            ResetFrame();
        }
        ++field000c;
        if ((unsigned short)field000c >= frameDuration) {
            field000c = 0;
            ++field000a;
            field0168 = 0;
            if (field000a == 2) {
                field0048 = 0.09;
                field0038 = -3.0;
                field0030 = 3.0;
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
            field0030 = 0.0;
            field0038 = 0.0;
            field016c = 1;
        }
        if ((field000a == 2) && ((unsigned short)field000c == 0)) {
            field02c9 = 0x15;
            field0148 = field0148 + 0x23;
            field016c = 1;
        }
        if (1 < field000a) {
            field0038 = field0038 + field0048;
            field0030 = field0030 - 0.06;
            if (field0030 < 0.0) {
                field0030 = 0.0;
            }
        }
        if ((0.0 < field0028 + field0038) &&
            (field000a == 7)) {
            field000a = 8;
            field000c = 0;
            field0028 = 0.0;
            ResetFrame();
        }
        ++field000c;
        if ((unsigned short)field000c >= frameDuration) {
            field000c = 0;
            ++field000a;
            field0168 = 0;
            if (field000a == 2) {
                field0048 = 0.11;
                field0038 = -4.5;
                field0030 = 4.0;
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
            field0030 = 0.0;
            field0038 = 0.0;
            field016c = 1;
            if (field0120 == '\0') {
                field0118 = field0118 - 500.0;
            }
            else {
                field0118 = field0118 - 250.0;
            }
            effect.type = 0x21;
            effect.palette = 0xb;
            effect.x = (double)((int(field0020)) + facing * 0x14);
            effect.y = (double)((int(field0028)) + -0x32);
            effect.group = 2;
            effect.layer = 1;
            contextOwner->EmitEffect(&effect);
        }
        if ((field000a == 2) && ((unsigned short)field000c == 0)) {
            field02c9 = 0x15;
            field0148 = field0148 + 0x23;
            field016c = 1;
        }
        if (1 < field000a) {
            field0038 = field0038 + field0048;
            field0030 = field0030 - 0.04;
            if (field0030 < 0.0) {
                field0030 = 0.0;
            }
        }
        if (((0.0 < field0028 + field0038) &&
            (8 < field000a)) && (field000a < 0xd)) {
            field000a = 0xd;
            field000c = 0;
            field0028 = 0.0;
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
                field0048 = 0.09;
                field0038 = -4.0;
                field0030 = 2.0;
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
            field0030 = 0.5;
            field0038 = 3.0;
            field016c = 1;
            field02c9 = 0x23;
            field0148 = field0148 + 0x23;
        }
        if (field0028 + field0038 > 0.0 && field000a > 2) {
            field000c = 0;
            field000a = 0;
            field0028 = 0.0;
            ResetFrame();
            field0008 = 0x108;
            break;
        }
        ++field000c;
        if ((unsigned short)field000c >= frameDuration) {
            field000c = 0;
            ++field000a;
            if (0 < field016c) {
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
            field0030 = 2.2;
            field0038 = 2.2;
            field016c = 1;
            field02c9 = 0x23;
            field0148 = field0148 + 0x23;
        }
        if (field0028 + field0038 > 0.0 && field000a > 2) {
            field000c = 0;
            field000a = 0;
            field0028 = 0.0;
            ResetFrame();
            field0008 = 0x108;
            break;
        }
        ++field000c;
        if ((unsigned short)field000c >= frameDuration) {
            field000c = 0;
            ++field000a;
            if (0 < field016c) {
                field0168 = 0;
            }
            if (field000a >= frameCount) {
                field000a = field000a + -2;
            }
        }
        break;
    case 271:
        if ((field000a == 0) && ((unsigned short)field000c == 0)) {
            field0148 = field0148 + 0x28;
            field016c = 4;
        }
        if (field000a > 9 && field000a < 14 && (field0038 = field0038 + field0048, field0038 + field0028 > 0.0)) {
            field0028 = 0.0;
            ResetFrame();
            ResetPose();
            field000a = 0xe;
            break;
        }
        if (field000a < 7 && (field0038 = field0038 + field0048, field0038 + field0028 > 0.0)) {
            field0028 = 0.0;
            field0038 = 0.0;
            ResetPose();
            field3138 = (int(field0030 * 100.0));
            field0030 = 0.0;
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
                field0030 = (double)field3138 * 0.005;
                field0038 = -0.8;
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
            field0048 = 0.03;
            field0038 = -2.0;
            field0030 = -3.0;
        }
        if ((0xf < field000a) && (field000a < 0x14)) {
            if (inputX == facing) {
                field0030 = field0030 + 0.015;
            }
            if ((int)inputX == -(int)facing) {
                field0030 = field0030 - 0.015;
            }
            if (field0030 < -2.5) { field0030 = -2.5; } else if (field0030 > 2.5) { field0030 = 2.5; }
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
            field0038 = field0038 + field0048;
        }
        if ((0xb < field000a) && (field000a < 0x10)) {
            if (facing == '\x01') {
                field0020 = (double)(contextOwner->cameraBounds.left + 0xf);
            }
            if (facing == -1) {
                field0020 = (double)(contextOwner->cameraBounds.right + -0xf);
            }
        }
        if (field0028 + field0038 >= 0.0 && field000a > 4 && field000a < 20) {
            field0028 = 0.0;
            ResetFrame();
            field000a = 0x14;
            field000c = 0;
            break;
        }
        if (CollisionSide() != 0 && field000a > 4 && field000a < 12) {
            field0030 = 0.0;
            field0038 = 0.0;
            field000a = 0xc;
            field000c = 0;
            field02c9 = 0x1a;
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
                field0030 = 1.5;
                field0038 = -2.5;
                field0048 = 0.035;
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
            field0048 = 0.03;
            field0038 = -1.5;
            field0030 = -3.0;
        }
        if ((field000a == 0x12) &&
            ((*opponentSlot)->field0028 == 0.0)) {
            field016c = 1;
        }
        else {
            field016c = 0;
        }
        if ((field000a == 0x12) && (field0168 == 3)) {
            (*opponentSlot)->ResetPose();
            (*opponentSlot)->ResetFrame();
            (*opponentSlot)->field0008 = 0x6b;
            ResetPose();
            ResetFrame();
            field0008 = 0x113;
            field0028 = (double)(field2af8[0] + 0x32);
            field0020 =
            (*opponentSlot)->field0020 + (-field2ad0[0] - 0x14) * facing;
            effect.type = 0;
            effect.x = (double)((int(field0020)) + facing * 7);
            effect.y = (double)((int(field0028)) + -0x2c);
            effect.group = 2;
            effect.layer = 1;
            contextOwner->EmitEffect(&effect);
            break;
        }
        if (((4 < field000a) && (field000a < 0xc)) ||
            ((0xf < field000a && (field000a < 0x13)))) {
            field0038 = field0038 + field0048;
        }
        if ((0xb < field000a) && (field000a < 0x10)) {
            if (facing == '\x01') {
                field0020 = (double)(contextOwner->cameraBounds.left + 0xf);
            }
            if (facing == -1) {
                field0020 = (double)(contextOwner->cameraBounds.right + -0xf);
            }
        }
        if (field0028 + field0038 >= 0.0 && field000a > 15 && field000a < 19) {
            field0028 = 0.0;
            ResetFrame();
            field000a = 0x14;
            field000c = 0;
            break;
        }
        if (CollisionSide() != 0 && field000a > 4 && field000a < 12) {
            field0030 = 0.0;
            field0038 = 0.0;
            field000a = 0xc;
            field000c = 0;
            field02c9 = 0x1a;
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
                field0030 = 2.2;
                field0038 = -0.5;
                field0048 = 0.035;
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
            field0048 = 0.03;
            field0038 = -2.0;
            field0030 = 3.0;
        }
        if ((0xf < field000a) && (field000a < 0x14)) {
            if (inputX == facing) {
                field0030 = field0030 + 0.015;
            }
            if ((int)inputX == -(int)facing) {
                field0030 = field0030 - 0.015;
            }
            if (field0030 < -2.5) { field0030 = -2.5; } else if (field0030 > 2.5) { field0030 = 2.5; }
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
            field0038 = field0038 + field0048;
        }
        if ((0xb < field000a) && (field000a < 0x10)) {
            if (facing == '\x01') {
                field0020 = (double)(contextOwner->cameraBounds.left + 0xf);
            }
            if (facing == -1) {
                field0020 = (double)(contextOwner->cameraBounds.right + -0xf);
            }
        }
        if (field0028 + field0038 >= 0.0 && field000a > 4 && field000a < 20) {
            field0028 = 0.0;
            ResetFrame();
            field000a = 0x14;
            field000c = 0;
            break;
        }
        if (CollisionSide() != 0 && field000a > 4 && field000a < 12) {
            field0030 = 0.0;
            field0038 = 0.0;
            facing = -facing;
            field000a = 0xc;
            field000c = 0;
            field02c9 = 0x1a;
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
                field0030 = 1.5;
                field0038 = -2.5;
                field0048 = 0.035;
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
            (*opponentSlot)->field0020 =
            (23.0 + field0030) * facing +
            field0020;
            (*opponentSlot)->field0028 =
            -54.0 + field0038 + field0028;
        }
        if (field000a == 5) {
            (*opponentSlot)->field0008 = 0x67;
            (*opponentSlot)->field0020 =
            (15.0 + field0030) * facing +
            field0020;
            (*opponentSlot)->field0028 =
            -70.0 + field0038 + field0028;
        }
        if (field000a == 6) {
            (*opponentSlot)->field0008 = 0x76;
            (*opponentSlot)->field0020 =
            (-31.0 + field0030) * facing +
            field0020;
            (*opponentSlot)->field0028 =
            -62.0 + field0038 + field0028;
            (*opponentSlot)->facing = facing;
        }
        if (field000a == 7) {
            (*opponentSlot)->field0008 = 0x75;
            (*opponentSlot)->field0020 =
            (-34.0 + field0030) * facing +
            field0020;
            (*opponentSlot)->field0028 =
            -34.0 + field0038 + field0028;
            (*opponentSlot)->facing = facing;
        }
        if (field000a == 8) {
            (*opponentSlot)->field0008 = 0x68;
            (*opponentSlot)->field0020 =
            (-6.0 + field0030) * facing +
            field0020;
            (*opponentSlot)->field0028 =
            -3.0 + field0038 + field0028;
            (*opponentSlot)->facing = -facing;
        }
        if (field000a == 9) {
            (*opponentSlot)->field0008 = 0x68;
            (*opponentSlot)->field0020 =
            (-4.0 + field0030) * facing +
            field0020;
            (*opponentSlot)->field0028 =
            -2.0 + field0038 + field0028;
            (*opponentSlot)->facing = -facing;
        }
        if ((field000a == 10) && ((unsigned short)field000c == 0)) {
            (*opponentSlot)->ResetFrame();
            (*opponentSlot)->ResetPose();
            (*opponentSlot)->field0008 = 0x62;
            (*opponentSlot)->field0028 = 0;
            (*opponentSlot)->field0020 = field0020;
            ApplyDamage(0x4b0,960.0);
            effect.type = 0;
            effect.x = (double)(int(field0020));
            effect.y = (double)(int(field0028));
            effect.palette = 2;
            effect.group = 2;
            effect.layer = 1;
            contextOwner->EmitEffect(&effect);
        }
        if (field000a == 19 && field0028 + field0038 > 0.0) {
            ResetPose();
            ResetFrame();
            field0028 = 0.0;
            field0008 = 0xd;
            break;
        }
        if (0xf < field000a) {
            field0038 = field0038 + field0048;
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
                field0030 = -0.5;
                field0038 = -1.3;
                field0048 = 0.05;
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
            field016c = 1;
        }
        if (field0028 + field0038 > 0.0 && field000a > 4) {
            field000c = 0;
            field000a = 0xc;
            field0028 = 0.0;
            ResetFrame();
            break;
        }
        if ((field000a == 5) && (field0168 == 3)) {
            field0030 = field0030 * 0.15;
            field0038 = field0038 * 0.15;
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
                field0030 = 0.7;
                field0038 = 2.0;
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
            field016c = 1;
        }
        if (field0028 + field0038 > 0.0 && field000a > 4) {
            field000c = 0;
            field000a = 0xc;
            field0028 = 0.0;
            ResetFrame();
            break;
        }
        if ((field000a == 5) && (field0168 == 3)) {
            field0030 = field0030 * 0.15;
            field0038 = field0038 * 0.15;
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
                field0030 = 2.0;
                field0038 = 2.0;
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
            effect.x = (double)((int(field0020)) + facing * 0x14);
            effect.y = (double)((int(field0028)) + -0x32);
            effect.group = 2;
            effect.layer = 1;
            contextOwner->EmitEffect(&effect);
            ++field3138;
        }
        if ((field000a == 0) && ((unsigned short)field000c == 0)) {
            ResetFrame();
            field016c = 1;
        }
        if (field0028 + field0038 > 0.0 && field000a > 4) {
            field000c = 0;
            field000a = 0xc;
            field0028 = 0.0;
            ResetFrame();
            break;
        }
        if ((field000a == 5) && (field0168 == 3)) {
            field000c = 0;
            field000a = 8;
            field016c = 99;
            break;
        }
        ++field000c;
        if ((unsigned short)field000c >= frameDuration) {
            field000c = 0;
            ++field000a;
            field0168 = 0;
            if (field000a == 5) {
                field0030 = 2.0;
                field0038 = 2.0;
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
        field0030 = 0.0;
        field0038 = 0.0;
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
                ((*opponentSlot)->field0028 == 0.0)) &&
                (((*opponentSlot)->field0008 < 0x32 ||
                (0x95 < (*opponentSlot)->field0008)))) {
                field016c = 1;
            }
            else {
                field016c = 0;
            }
            if (field000a == 2) {
                field0148 = field0148 + 0x19;
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
        (*opponentSlot)->field014a = 3;
        ++field000c;
        if (3 < field000a) {
            field0030 = 1.0;
            field0038 = field0038 + 0.025;
        }
        if (field000a > 3 && field0038 + field0028 > 0.0) {
            ResetFrame();
            field0028 = 0.0;
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
                field0020 =
                (*opponentSlot)->field0020 -
                (double)((int)(*opponentSlot)->field2ad0[0] * (int)facing);
                field0028 =
                ((*opponentSlot)->field0028 + (double)(int)(*opponentSlot)->field2af8[0]) - 20.0;
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
            field0030 = 0.5;
            field0038 = 3.0;
            field016c = 1;
            field02c9 = 0x23;
            field0148 = field0148 + 0x23;
        }
        if (field0168 > 0) {
            ResetPose();
            ResetFrame();
            field0008 = 0x120;
            break;
        }
        if (field0028 + field0038 > 0.0 && field000a > 2) {
            field000c = 0;
            field000a = 0;
            field0028 = 0.0;
            ResetFrame();
            field0008 = 0x109;
            break;
        }
        ++field000c;
        if ((unsigned short)field000c >= frameDuration) {
            field000c = 0;
            ++field000a;
            if (0 < field016c) {
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
            field0030 = 2.2;
            field0038 = 2.2;
            field016c = 1;
            field02c9 = 0x23;
            field0148 = field0148 + 0x23;
        }
        if (field0168 > 0) {
            ResetPose();
            ResetFrame();
            field0008 = 0x120;
            break;
        }
        if (field0028 + field0038 > 0.0 && field000a > 2) {
            field000c = 0;
            field000a = 0;
            field0028 = 0.0;
            ResetFrame();
            field0008 = 0x109;
            break;
        }
        ++field000c;
        if ((unsigned short)field000c >= frameDuration) {
            field000c = 0;
            ++field000a;
            if (0 < field016c) {
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
            field0030 = 4.0;
            field0038 = 1.5;
            field016c = 1;
            field02c9 = 0x23;
            field0148 = field0148 + 0x23;
        }
        if (field0168 > 0) {
            ResetPose();
            ResetFrame();
            field0008 = 0x120;
            break;
        }
        if (field0028 + field0038 > 0.0 && field000a > 2) {
            field000c = 0;
            field000a = 0;
            field0028 = 0.0;
            ResetFrame();
            field0008 = 0x109;
            break;
        }
        ++field000c;
        if ((unsigned short)field000c >= frameDuration) {
            field000c = 0;
            ++field000a;
            if (0 < field016c) {
                field0168 = 0;
            }
            if (field000a >= frameCount) {
                field000a = field000a + -2;
            }
        }
        break;
    case 288:
        if ((field000a == 0) && ((unsigned short)field000c == 0)) {
            field0030 = -0.4;
            field0038 = -0.9;
            field0048 = 0.045;
        }
        field0038 = field0038 + field0048;
        if (field0028 + field0038 > 0.0 && field000a < 8) {
            field000c = 0;
            field000a = 8;
            field0028 = 0.0;
            ResetFrame();
            break;
        }
        ++field000c;
        if ((unsigned short)field000c >= frameDuration) {
            field000c = 0;
            ++field000a;
            if (0 < field016c) {
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
            field0048 = 0.03;
            field0038 = -1.5;
            field0030 = -3.0;
        }
        if ((field000a == 0x12) &&
            ((*opponentSlot)->field0028 == 0.0)) {
            field016c = 1;
        }
        else {
            field016c = 0;
        }
        if (((4 < field000a) && (field000a < 0xc)) ||
            ((0xf < field000a && (field000a < 0x13)))) {
            field0038 = field0038 + field0048;
        }
        if ((0xb < field000a) && (field000a < 0x10)) {
            if (facing == '\x01') {
                field0020 = (double)(contextOwner->cameraBounds.left + 0xf);
            }
            if (facing == -1) {
                field0020 = (double)(contextOwner->cameraBounds.right + -0xf);
            }
        }
        if (field0028 + field0038 >= 0.0 && field000a > 15 && field000a < 19) {
            field0028 = 0.0;
            ResetFrame();
            field000a = 0x14;
            field000c = 0;
            break;
        }
        if (CollisionSide() != 0 && field000a > 4 && field000a < 12) {
            field0030 = 0.0;
            field0038 = 0.0;
            field000a = 0xc;
            field000c = 0;
            field02c9 = 0x1a;
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
                if ((field0020 - (*opponentSlot)->field0020 < 140.0) &&
                    (-140.0 < field0020 - (*opponentSlot)->field0020)) {
                    field0008 = 0x11e;
                }
                if ((field0020 - (*opponentSlot)->field0020 < 70.0) &&
                    (-70.0 < field0020 - (*opponentSlot)->field0020)) {
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
        field0030 = field0030 - 0.035;
        if (field0030 < 0.0) {
            field0030 = 0.0;
        }
        if (field0028 < 0.0) {
            field0048 = 0.055;
            field0038 = field0038 + field0048;
        }
        if (field000a > 4 && field000a < 15 && field0028 + field0038 > 0.0) {
            field000c = 0;
            field000a = 0xf;
            field0028 = 0.0;
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
                field0038 = -3.3;
                field016c = 3;
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
            field016c = 5;
        }
        if (field000a > 14 && (field0038 = field0038 + field0048, field0028 + field0038 > 0.0)) {
            field000c = 0;
            field000a = 0x16;
            field0028 = 0.0;
            ResetFrame();
            break;
        }
        ++field000c;
        if ((unsigned short)field000c >= frameDuration) {
            field000c = 0;
            ++field000a;
            field0168 = 0;
            if (field000a == 0xe) {
                field0030 = 0.5;
                field0038 = 0.0;
                field0048 = 0.045;
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
            field0030 = 0.0;
            field0038 = 0.0;
            field0048 = 0.0;
        }
        if ((field000a == 1) && ((unsigned short)field000c == 0)) {
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
            field013c = 0x7e;
            SetHorizontalShake(0x32,0x78);
        }
        if (field000a >= 1) {
            reinterpret_cast<short&>(unknown_00df[0x13]) = 10;
        }
        if (((field000a == 2) || (field000a == 7)) &&
            ((unsigned short)field000c == 0)) {
            field02c9 = 0x15;
            field016c = 1;
        }
        if ((field000a == 0x10) && ((unsigned short)field000c == 0)) {
            field02c9 = 0x14;
            field016c = 1;
        }
        ++field000c;
        if ((unsigned short)field000c >= frameDuration) {
            field000c = 0;
            ++field000a;
            if (0 < field016c) {
                field0168 = 0;
            }
            if (field000a == 2) {
                field013c = 9;
            }
            if (field000a == 6) {
                field0020 = (double)(facing * 0xf) + field0020;
            }
            if (field000a == 7) {
                field0020 = (double)(facing * 0xf) + field0020;
            }
            if (field000a == 9) {
                field0020 = (double)(facing * 0xf) + field0020;
            }
            if (field000a == 10) {
                if (1 < field3138) {
                    field000a = 0xc;
                    return;
                }
                field0020 = (double)(facing * 0xf) + field0020;
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
            field0030 = 0.0;
            field0038 = 0.0;
            field0048 = 0.0;
        }
        if ((field000a == 1) && ((unsigned short)field000c == 0)) {
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
            field013c = 0x84;
            SetHorizontalShake(0x32,0x78);
        }
        if (field000a >= 1) {
            reinterpret_cast<short&>(unknown_00df[0x13]) = 10;
        }
        if (((field000a == 2) || (field000a == 7)) &&
            ((unsigned short)field000c == 0)) {
            field02c9 = 0x15;
            field016c = 1;
        }
        if ((field000a == 0xe) && ((unsigned short)field000c == 0)) {
            field02c9 = 0x14;
            field016c = 1;
        }
        if ((field000a == 0x15) && ((unsigned short)field000c == 0)) {
            field02c9 = 0x15;
            field016c = 1;
        }
        if ((0x14 < field000a) && (field000a < 0x1c)) {
            field0038 = field0038 + field0048;
            field0030 = field0030 - 0.04;
            if (field0030 < 0.0) {
                field0030 = 0.0;
            }
        }
        if (field000a > 20 && field000a < 28 && field0028 + field0038 > 0.0) {
            field000a = 0x1c;
            field000c = 0;
            field0028 = 0.0;
            ResetFrame();
            break;
        }
        ++field000c;
        if ((unsigned short)field000c >= frameDuration) {
            field000c = 0;
            ++field000a;
            if (0 < field016c) {
                field0168 = 0;
            }
            if (field000a == 2) {
                field013c = 0x1e;
            }
            if (field000a == 6) {
                field0020 = (double)(facing * 0xf) + field0020;
            }
            if (field000a == 7) {
                field0020 = (double)(facing * 0xf) + field0020;
            }
            if (field000a == 9) {
                field0020 = (double)(facing * 0xf) + field0020;
            }
            if (field000a == 10) {
                if (2 < field3138) {
                    field000a = 0xc;
                    return;
                }
                field0020 = (double)(facing * 0xf) + field0020;
            }
            if ((field000a == 0xc) && (field3138 < 2)) {
                field000a = 2;
                ++field3138;
            }
            if (field000a == 0x14) {
                field0048 = 0.06;
                field0038 = -3.0;
                field0030 = 2.0;
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
            field0030 = 0.0;
            field0038 = 0.0;
            field0048 = 0.0;
        }
        if ((field000a == 1) && ((unsigned short)field000c == 0)) {
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
            field013c = 0x84;
            SetHorizontalShake(0x32,0x78);
            field02c9 = 0x25;
        }
        if (1 < field000a) {
            contextOwner->SetSceneTimer(0xf);
        }
        if (((field000a == 2) || (field000a == 7)) &&
            ((unsigned short)field000c == 0)) {
            field02c9 = 0x15;
            field016c = 1;
        }
        if ((field000a == 0xe) && ((unsigned short)field000c == 0)) {
            field02c9 = 0x14;
            field016c = 1;
        }
        if ((field000a == 0x12) && ((unsigned short)field000c == 0)) {
            field02c9 = 0x15;
            field016c = 1;
            field0030 = 3.0;
        }
        if (((0x12 < field000a) && (field000a < 0x17)) &&
            (field0030 = field0030 - 0.04,
            field0030 < 0.0)) {
            field0030 = 0.0;
        }
        if (((0x14 < field000a) && (field000a < 0x17)) ||
            (0x1c < field000a)) {
            field0038 = field0038 + field0048;
            field0030 = field0030 - 0.04;
            if (field0030 < 0.0) {
                field0030 = 0.0;
            }
        }
        if ((field000a == 0x18) && ((unsigned short)field000c == 0)) {
            field0030 = 1.8;
            field016c = 99;
        }
        if ((field000a == 0x20) && ((unsigned short)field000c == 0)) {
            field02c9 = 0x14;
            field016c = 1;
        }
        ++field000c;
        if ((unsigned short)field000c >= frameDuration) {
            field000c = 0;
            ++field000a;
            if ((0 < field016c) ||
                ((field000a < 0x22 && (0x1b < field000a)))) {
                field0168 = 0;
            }
            if (field000a == 2) {
                field013c = 0x3c;
            }
            if (field000a == 6) {
                field0020 = (double)(facing * 0xf) + field0020;
            }
            if (field000a == 7) {
                field0020 = (double)(facing * 0xf) + field0020;
            }
            if (field000a == 9) {
                field0020 = (double)(facing * 0xf) + field0020;
            }
            if (field000a == 10) {
                if (3 < field3138) {
                    field000a = 0xc;
                    return;
                }
                field0020 = (double)(facing * 0xf) + field0020;
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
            field0028 = (double)(field2af8[0] + 0x32);
            field0020 =
            (*opponentSlot)->field0020 + (-field2ad0[0] - 0x14) * facing;
            effect.type = 0;
            effect.x = (double)((int((*opponentSlot)->field0020)) + field2ad0[0]);
            effect.y = (double)((int((*opponentSlot)->field0028)) + field2af8[0]);
            effect.group = 2;
            effect.layer = 1;
            contextOwner->EmitEffect(&effect);
            break;
        }
        if ((2 < field000a) && (field000a < 7)) {
            field0038 = field0038 + field0048;
        }
        if (field000a == 6 && field0028 + field0038 > 0.0) {
            ResetFrame();
            field0028 = 0.0;
            field000c = 0;
            field000a = 7;
            break;
        }
        if (field000a == 6 && (*opponentSlot)->field0028 >= 0.0) {
            field016c = 1;
        } else {
            field016c = 0;
        }
        ++field000c;
        if ((unsigned short)field000c >= frameDuration) {
            field000c = 0;
            ++field000a;
            field0168 = 0;
            if (field000a == 3) {
                field0030 = 1.5;
                field0038 = -2.0;
                field0048 = 0.045;
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
            (*opponentSlot)->field014a = 0x78;
            (*opponentSlot)->field0020 =
            (double)(facing * 0x1e) + field0020;
            effect.type = 0;
            effect.x = (double)((int(field0020)) + facing * 0x2c);
            effect.y = (double)((int(field0028)) + -7);
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
            if (field000a == 4 && (*opponentSlot)->field0028 >= 0.0) {
                field016c = 1;
            } else {
                field016c = 0;
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
            field0038 = field0038 + field0048;
        }
        if (field000a == 4) {
            (*opponentSlot)->field0140 = 30000;
            (*opponentSlot)->field0008 = 0x67;
            (*opponentSlot)->field0020 =
            (23.0 + field0030) * facing +
            field0020;
            (*opponentSlot)->field0028 =
            -52.0 + field0038 + field0028;
        }
        if (field000a == 5) {
            (*opponentSlot)->field0008 = 0x67;
            (*opponentSlot)->field0020 =
            (15.0 + field0030) * facing +
            field0020;
            (*opponentSlot)->field0028 =
            -70.0 + field0038 + field0028;
        }
        if (field000a == 6) {
            (*opponentSlot)->field0008 = 0x76;
            (*opponentSlot)->field0020 =
            (-31.0 + field0030) * facing +
            field0020;
            (*opponentSlot)->field0028 =
            -65.0 + field0038 + field0028;
            (*opponentSlot)->facing = facing;
        }
        if (field000a == 7) {
            (*opponentSlot)->field0008 = 0x75;
            (*opponentSlot)->field0020 =
            (-36.0 + field0030) * facing +
            field0020;
            (*opponentSlot)->field0028 =
            -32.0 + field0038 + field0028;
            (*opponentSlot)->facing = facing;
        }
        if (field000a == 8) {
            (*opponentSlot)->field0008 = 0x68;
            (*opponentSlot)->field0020 =
            (-7.0 + field0030) * facing +
            field0020;
            (*opponentSlot)->field0028 =
            -8.0 + field0038 + field0028;
            (*opponentSlot)->facing = -facing;
        }
        if ((field000a == 9) || (field000a == 10)) {
            (*opponentSlot)->field0008 = 0x68;
            (*opponentSlot)->field0020 =
            (-4.0 + field0030) * facing +
            field0020;
            (*opponentSlot)->field0028 =
            -6.0 + field0038 + field0028;
            (*opponentSlot)->facing = -facing;
        }
        if (field000a > 8 && field0038 + field0028 > 0.0) {
            ResetFrame();
            ResetPose();
            (*opponentSlot)->ResetFrame();
            (*opponentSlot)->ResetPose();
            (*opponentSlot)->field0008 = 0x62;
            (*opponentSlot)->field0028 = 0;
            (*opponentSlot)->field0020 = field0020;
            field0028 = 0.0;
            field0008 = 0x133;
            ApplyDamage(1000,960.0);
            effect.type = 0;
            effect.x = (double)(int(field0020));
            effect.y = (double)(int(field0028));
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
                field0030 =
                (double)(1 - 2 * (field0020 > 320.0)) * 0.6 * (double)(int)facing;
                field0038 = -5.0;
                field0048 = 0.06;
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
                (*opponentSlot)->field014a = 0;
                field0030 =
                (double)(1 - 2 * (field0020 > 320.0)) * 0.6 * (double)(int)facing;
                field0038 = -5.0;
                field0048 = 0.06;
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
            effect.x = (field0020 + 80.0) - (double)((unsigned short)RandomRange(0, 0xa0));
            effect.y = (double)-(int)(unsigned short)RandomRange(0, 0x32);
            effect.group = 0;
            effect.layer = 1;
            effect.flag0018 = (unsigned char)facing;
            EmitLocalEffect(&effect);
        }
        if (3 < field000a) {
            field0038 = field0038 + field0048;
        }
        if (5 < field000a) {
            ++field3138;
        }
        if (field3138 == 0x50) {
            effect.type = 0x191;
            effect.x = (double)((int(field0020)) + facing * 0x1e);
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
            effect.x = (double)((int(field0020)) - facing * 0x14);
            effect.y = -320.0;
            effect.group = 0;
            effect.layer = 1;
            effect.field0028 = 1;
            effect.flag0018 = (unsigned char)facing;
            effect.owner = 1;
            EmitLocalEffect(&effect);
        }
        if (field000a == 9 && field0038 + field0028 > 0.0) {
            ResetFrame();
            field000c = 0;
            field000a = 10;
            (*opponentSlot)->ResetFrame();
            (*opponentSlot)->ResetPose();
            (*opponentSlot)->field0008 = 0x62;
            field0028 = 0.0;
            (*opponentSlot)->field0140 = 30000;
            ApplyDamage(300,960.0);
            effect.type = 0;
            effect.x = (double)(int(field0020));
            effect.y = (double)(int(field0028));
            effect.palette = 2;
            effect.group = 2;
            effect.layer = 1;
            contextOwner->EmitEffect(&effect);
            break;
        }
        if (field000a == 15 && field0038 + field0028 > 0.0) {
            ResetFrame();
            field000c = 0;
            field000a = 0x10;
            (*opponentSlot)->ResetFrame();
            (*opponentSlot)->ResetPose();
            (*opponentSlot)->field0008 = 0x62;
            field0028 = 0.0;
            ApplyDamage(0x578,960.0);
            (*opponentSlot)->field0140 = 0;
            SetVerticalShake(10,10);
            (*opponentSlot)->field014a = 0x78;
            effect.type = 0;
            effect.x = (double)(int(field0020));
            effect.y = (double)(int(field0028));
            effect.palette = 0x16;
            effect.group = 2;
            effect.layer = 1;
            contextOwner->EmitEffect(&effect);
            break;
        }
        if (field000a == 20 && field0038 + field0028 > 0.0) {
            ResetFrame();
            field000c = 0;
            field000a = 0x15;
            (*opponentSlot)->ResetFrame();
            (*opponentSlot)->ResetPose();
            field0028 = 0.0;
            break;
        }
        if ((field000a == 0xb) && (0x334 < field3138)) {
            field000a = 0xc;
            field000c = 0;
            field0038 = -5.0;
            field0048 = 0.06;
            break;
        }
        ++field000c;
        if ((unsigned short)field000c >= frameDuration) {
            field000c = 0;
            ++field000a;
            field0168 = 0;
            if (field000a == 6) {
                field0030 = 0.0;
                field0038 = -3.9;
                field0048 = 0.08;
            }
            if (field000a == 0xc) {
                if (field3138 <= 730) {
                    field000a = 6;
                    field0030 = 0.0;
                    field0038 = -3.9;
                    field0048 = 0.08;
                }
                else {
                    field000a = 0xb;
                }
            }
            if (field000a == 0x12) {
                field0030 = -0.6;
                field0038 = -1.5;
                field0048 = 0.038;
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
        if ((int)field000a >= 0 && field000a < 3) {
            SetHorizontalShake(0x32,3);
        }
        if (((field000a == 3) || (field000a == 4)) &&
            (field0168 == 3)) {
            if (field0020 > 580.0) {
                field0020 = 580.0;
                field0030 = 0.0;
            }
            if (field0020 < 60.0) {
                field0020 = 60.0;
                field0030 = 0.0;
            }
            (*opponentSlot)->ResetPose();
            (*opponentSlot)->ResetFrame();
            (*opponentSlot)->field0008 = 0x67;
            (*opponentSlot)->field0020 =
            (double)(facing * 0x16) + field0020;
            (*opponentSlot)->field0028 = field0028 - 52.0;
            ResetPose();
            field0048 = 0.025;
            field0008 = 0x137;
            effect.type = 0;
            effect.x = (double)((int(field0020)) + facing * 0x2c);
            effect.y = (double)((int(field0028)) + -0x2c);
            effect.group = 2;
            effect.layer = 1;
            contextOwner->EmitEffect(&effect);
            break;
        }
        if ((4 < field000a) && (field000a < 0x70)) {
            field0038 = field0038 + field0048;
        }
        if (field000a < 12 && field0028 + field0038 > 0.0) {
            ResetFrame();
            field0028 = 0.0;
            field000c = 0;
            field000a = 0xc;
            break;
        }
        if (6 < field000a) {
            field0030 = field0030 - 0.025;
        }
        if (field0030 < 0.0) {
            field0030 = 0.0;
        }
        if ((field000a == 3 || field000a == 4) && (*opponentSlot)->field0028 < 0.0) {
            field016c = 1;
        } else {
            field016c = 0;
        }
        ++field000c;
        if ((unsigned short)field000c >= frameDuration) {
            field000c = 0;
            ++field000a;
            field0168 = 0;
            if (field000a == 3) {
                field0030 = 2.0;
                field0038 = -3.2;
                field0048 = 0.035;
                field013c = 6;
            }
            if ((field000a == 5) && (field3138 < 1)) {
                field000a = field000a + -2;
                ++field3138;
            }
            if (field000a == 6) {
                field0038 = field0038 * 0.5;
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
        if ((int)field000a >= 0 && field000a < 3) {
            SetHorizontalShake(0x32,3);
        }
        if (((field000a == 3) || (field000a == 4)) &&
            (field0168 == 3)) {
            if (field0020 > 580.0) {
                field0020 = 580.0;
                field0030 = 0.0;
            }
            if (field0020 < 60.0) {
                field0020 = 60.0;
                field0030 = 0.0;
            }
            (*opponentSlot)->ResetPose();
            (*opponentSlot)->ResetFrame();
            (*opponentSlot)->field0008 = 0x67;
            (*opponentSlot)->field0020 =
            (double)(facing * 0x16) + field0020;
            (*opponentSlot)->field0028 = field0028 - 52.0;
            ResetPose();
            field0048 = 0.025;
            field0008 = 0x138;
            effect.type = 0;
            effect.x = (double)((int(field0020)) + facing * 0x2c);
            effect.y = (double)((int(field0028)) + -0x2c);
            effect.group = 2;
            effect.layer = 1;
            contextOwner->EmitEffect(&effect);
            break;
        }
        if ((4 < field000a) && (field000a < 0x70)) {
            field0038 = field0038 + field0048;
        }
        if (field000a < 12 && field0028 + field0038 > 0.0) {
            ResetFrame();
            field0028 = 0.0;
            field000c = 0;
            field000a = 0xc;
            break;
        }
        if (6 < field000a) {
            field0030 = field0030 - 0.025;
        }
        if (field0030 < 0.0) {
            field0030 = 0.0;
        }
        if ((field000a == 3 || field000a == 4) && (*opponentSlot)->field0028 < 0.0) {
            field016c = 1;
        } else {
            field016c = 0;
        }
        ++field000c;
        if ((unsigned short)field000c >= frameDuration) {
            field000c = 0;
            ++field000a;
            field0168 = 0;
            if (field000a == 3) {
                field0030 = 2.0;
                field0038 = -3.2;
                field0048 = 0.035;
                field013c = 0xc;
            }
            if ((field000a == 5) && (field3138 < 3)) {
                field000a = field000a + -2;
                ++field3138;
            }
            if (field000a == 6) {
                field0038 = field0038 * 0.5;
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
        contextOwner->SetSceneTimer(0xf);
        if ((int)field000a >= 0 && field000a < 3) {
            SetHorizontalShake(0x32,3);
        }
        if (((field000a == 3) || (field000a == 4)) &&
            (field0168 == 3)) {
            if (field0020 > 580.0) {
                field0020 = 580.0;
                field0030 = 0.0;
            }
            if (field0020 < 60.0) {
                field0020 = 60.0;
                field0030 = 0.0;
            }
            (*opponentSlot)->ResetPose();
            (*opponentSlot)->ResetFrame();
            (*opponentSlot)->field0008 = 0x67;
            (*opponentSlot)->field0020 =
            (double)(facing * 0x16) + field0020;
            (*opponentSlot)->field0028 = field0028 - 52.0;
            ResetPose();
            field0048 = 0.025;
            field0008 = 0x139;
            effect.type = 0;
            effect.x = (double)((int(field0020)) + facing * 0x2c);
            effect.y = (double)((int(field0028)) + -0x2c);
            effect.group = 2;
            effect.layer = 1;
            contextOwner->EmitEffect(&effect);
            break;
        }
        if (6 < field000a) {
            field0030 = field0030 - 0.025;
        }
        if (field0030 < 0.0) {
            field0030 = 0.0;
        }
        if ((4 < field000a) && (field000a < 0x70)) {
            field0038 = field0038 + field0048;
        }
        if (field000a < 12 && field0028 + field0038 > 0.0) {
            ResetFrame();
            field0028 = 0.0;
            field000c = 0;
            field000a = 0xc;
            break;
        }
        if ((field000a == 3 || field000a == 4) && (*opponentSlot)->field0028 < 0.0) {
            field016c = 1;
        } else {
            field016c = 0;
        }
        ++field000c;
        if ((unsigned short)field000c >= frameDuration) {
            field000c = 0;
            ++field000a;
            field0168 = 0;
            if (field000a == 3) {
                field0030 = 2.0;
                field0038 = -3.2;
                field0048 = 0.035;
                field013c = 0x12;
            }
            if ((field000a == 5) && (field3138 < 5)) {
                field000a = field000a + -2;
                ++field3138;
            }
            if (field000a == 6) {
                field0038 = field0038 * 0.5;
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
            if (field0020 > 580.0) {
                field0020 = 580.0;
                field0030 = 0.0;
            }
            if (field0020 < 60.0) {
                field0020 = 60.0;
                field0030 = 0.0;
            }
            SetHorizontalOffset(0x32,3);
            SetHorizontalShake(0x32,3);
        }
        if (((field000a < 0xd) ||
            ((0xe < field000a && (field000a < 0x12)))) &&
            (field0038 = field0038 + field0048,
            0.0 < field0038 + field0028)) {
            if (field000a < 0xd) {
                field0028 = 0.0;
                ResetFrame();
                (*opponentSlot)->ResetPose();
                (*opponentSlot)->field0008 = 0x62;
                (*opponentSlot)->field0028 = 0;
                (*opponentSlot)->field0020 =
                (double)(int)facing + field0020;
                (*opponentSlot)->facing = -facing;
                (*opponentSlot)->ResetFrame();
                (*opponentSlot)->field014a = 0x7e;
                ApplyDamage(0x92e,750.0);
                SetVerticalShake(10,0);
                field000c = 0;
                field000a = 0xd;
                field02c9 = 0x16;
                return;
            }
            if (field000a == 0x11) {
                field0028 = 0.0;
                ResetFrame();
                field000c = 0;
                field000a = 0x12;
                return;
            }
        }
        if ((field000a < 0xd) &&
            (field0030 = field0030 - 0.025,
            field0030 < 0.0)) {
            field0030 = 0.0;
        }
        if (field000a < 4) {
            (*opponentSlot)->field0008 = 0x67;
            (*opponentSlot)->field0020 =
            (double)(facing * 0x16) + field0020;
            (*opponentSlot)->field0028 = field0028 - 52.0;
        }
        if (field000a == 4) {
            (*opponentSlot)->field0008 = 0x67;
            (*opponentSlot)->field0020 =
            (15.0 + field0030) * facing +
            field0020;
            (*opponentSlot)->field0028 =
            -70.0 + field0038 + field0028;
        }
        if (field000a == 5) {
            (*opponentSlot)->field0008 = 0x76;
            (*opponentSlot)->field0020 =
            (-25.0 + field0030) * facing +
            field0020;
            (*opponentSlot)->field0028 =
            -65.0 + field0038 + field0028;
            (*opponentSlot)->facing = facing;
        }
        if (field000a == 6) {
            (*opponentSlot)->field0008 = 0x75;
            (*opponentSlot)->field0020 =
            (-28.0 + field0030) * facing +
            field0020;
            (*opponentSlot)->field0028 =
            -43.0 + field0038 + field0028;
            (*opponentSlot)->facing = facing;
        }
        if (field000a == 7) {
            (*opponentSlot)->field0008 = 0x75;
            (*opponentSlot)->field0020 =
            (-12.0 + field0030) * facing +
            field0020;
            (*opponentSlot)->field0028 =
            -29.0 + field0038 + field0028;
            (*opponentSlot)->facing = facing;
        }
        if (field000a == 8) {
            (*opponentSlot)->field0008 = 0x68;
            (*opponentSlot)->field0020 =
            (12.0 + field0030) * facing +
            field0020;
            (*opponentSlot)->field0028 =
            -23.0 + field0038 + field0028;
            (*opponentSlot)->facing = -facing;
        }
        if (field000a == 9) {
            (*opponentSlot)->field0008 = 0x68;
            (*opponentSlot)->field0020 =
            (23.0 + field0030) * facing +
            field0020;
            (*opponentSlot)->field0028 =
            -36.0 + field0038 + field0028;
            (*opponentSlot)->facing = -facing;
        }
        if (field000a == 10) {
            (*opponentSlot)->field0008 = 0x67;
            (*opponentSlot)->field0020 =
            (28.0 + field0030) * facing +
            field0020;
            (*opponentSlot)->field0028 =
            -58.0 + field0038 + field0028;
            (*opponentSlot)->facing = -facing;
        }
        if (field000a == 0xb) {
            (*opponentSlot)->field0008 = 0x67;
            (*opponentSlot)->field0020 =
            (14.0 + field0030) * facing +
            field0020;
            (*opponentSlot)->field0028 =
            -73.0 + field0038 + field0028;
            (*opponentSlot)->facing = -facing;
        }
        if (field000a == 0xc) {
            (*opponentSlot)->field0008 = 0x76;
            (*opponentSlot)->field0020 =
            (-12.0 + field0030) * facing +
            field0020;
            (*opponentSlot)->field0028 =
            -78.0 + field0038 + field0028;
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
                (*opponentSlot)->field014a = 3;
                field0030 = -1.2;
                field0038 = -2.0;
                field0048 = 0.035;
                (*opponentSlot)->field0028 = -1.0;
                (*opponentSlot)->ResetPose();
                (*opponentSlot)->ResetFrame();
                (*opponentSlot)->field00c0 = -1.2;
                (*opponentSlot)->field00c8 = -2.0;
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
            if (field0020 > 580.0) {
                field0020 = 580.0;
                field0030 = 0.0;
            }
            if (field0020 < 60.0) {
                field0020 = 60.0;
                field0030 = 0.0;
            }
            SetHorizontalOffset(0x32,3);
            SetHorizontalShake(0x32,3);
        }
        if ((((field000a < 0xd) ||
            ((0xe < field000a && (field000a < 0x19)))) ||
            ((0x1a < field000a && (field000a < 0x1e)))) &&
            (field0038 = field0038 + field0048,
            0.0 < field0038 + field0028)) {
            if (field000a < 0xd) {
                field0028 = 0.0;
                ResetFrame();
                (*opponentSlot)->ResetPose();
                (*opponentSlot)->field0008 = 0x62;
                (*opponentSlot)->field0028 = 0;
                (*opponentSlot)->ResetFrame();
                (*opponentSlot)->field014a = 0x96;
                (*opponentSlot)->field0020 =
                (double)(int)facing + field0020;
                (*opponentSlot)->facing = -facing;
                ApplyDamage(1000,980.0);
                SetVerticalShake(10,0);
                (*opponentSlot)->field0140 = 30000;
                field000c = 0;
                field000a = 0xd;
                field02c9 = 0x16;
                return;
            }
            if ((0xe < field000a) && (field000a < 0x19)) {
                field0028 = 0.0;
                ResetFrame();
                (*opponentSlot)->ResetPose();
                (*opponentSlot)->field0008 = 0x62;
                (*opponentSlot)->field0028 = 0;
                (*opponentSlot)->field0020 =
                (double)(int)facing + field0020;
                (*opponentSlot)->facing = -facing;
                (*opponentSlot)->ResetFrame();
                (*opponentSlot)->field014a = 0x7e;
                SetVerticalShake(0xf,0);
                ApplyDamage(0x834,980.0);
                (*opponentSlot)->field0140 = 0;
                field000c = 0;
                field000a = 0x19;
                field02c9 = 0x16;
                return;
            }
            if (field000a == 0x1d) {
                field0028 = 0.0;
                ResetFrame();
                field000c = 0;
                field000a = 0x1e;
                return;
            }
        }
        if ((field000a < 0xd) &&
            (field0030 = field0030 - 0.025,
            field0030 < 0.0)) {
            field0030 = 0.0;
        }
        if (((0xe < field000a) && (field000a < 0x19)) &&
            (field0030 = field0030 + 0.025,
            field0030 > 0.0)) {
            field0030 = 0.0;
        }
        if (field000a < 4) {
            (*opponentSlot)->field0008 = 0x67;
            (*opponentSlot)->field0020 =
            (double)(facing * 0x16) + field0020;
            (*opponentSlot)->field0028 = field0028 - 52.0;
        }
        if (((field000a == 4) || (field000a == 0xf)) ||
            (field000a == 0x10)) {
            (*opponentSlot)->field0008 = 0x67;
            (*opponentSlot)->field0020 =
            (15.0 + field0030) * facing +
            field0020;
            (*opponentSlot)->field0028 =
            -70.0 + field0038 + field0028;
        }
        if ((field000a == 5) || (field000a == 0x11)) {
            (*opponentSlot)->field0008 = 0x76;
            (*opponentSlot)->field0020 =
            (-25.0 + field0030) * facing +
            field0020;
            (*opponentSlot)->field0028 =
            -65.0 + field0038 + field0028;
            (*opponentSlot)->facing = facing;
        }
        if ((field000a == 6) || (field000a == 0x12)) {
            (*opponentSlot)->field0008 = 0x75;
            (*opponentSlot)->field0020 =
            (-28.0 + field0030) * facing +
            field0020;
            (*opponentSlot)->field0028 =
            -43.0 + field0038 + field0028;
            (*opponentSlot)->facing = facing;
        }
        if ((field000a == 7) || (field000a == 0x13)) {
            (*opponentSlot)->field0008 = 0x75;
            (*opponentSlot)->field0020 =
            (-12.0 + field0030) * facing +
            field0020;
            (*opponentSlot)->field0028 =
            -29.0 + field0038 + field0028;
            (*opponentSlot)->facing = facing;
        }
        if ((field000a == 8) || (field000a == 0x14)) {
            (*opponentSlot)->field0008 = 0x68;
            (*opponentSlot)->field0020 =
            (12.0 + field0030) * facing +
            field0020;
            (*opponentSlot)->field0028 =
            -23.0 + field0038 + field0028;
            (*opponentSlot)->facing = -facing;
        }
        if ((field000a == 9) || (field000a == 0x15)) {
            (*opponentSlot)->field0008 = 0x68;
            (*opponentSlot)->field0020 =
            (23.0 + field0030) * facing +
            field0020;
            (*opponentSlot)->field0028 =
            -36.0 + field0038 + field0028;
            (*opponentSlot)->facing = -facing;
        }
        if ((field000a == 10) || (field000a == 0x16)) {
            (*opponentSlot)->field0008 = 0x67;
            (*opponentSlot)->field0020 =
            (28.0 + field0030) * facing +
            field0020;
            (*opponentSlot)->field0028 =
            -58.0 + field0038 + field0028;
            (*opponentSlot)->facing = -facing;
        }
        if ((field000a == 0xb) || (field000a == 0x17)) {
            (*opponentSlot)->field0008 = 0x67;
            (*opponentSlot)->field0020 =
            (14.0 + field0030) * facing +
            field0020;
            (*opponentSlot)->field0028 =
            -73.0 + field0038 + field0028;
            (*opponentSlot)->facing = -facing;
        }
        if ((field000a == 0xc) || (field000a == 0x18)) {
            (*opponentSlot)->field0008 = 0x76;
            (*opponentSlot)->field0020 =
            (-12.0 + field0030) * facing +
            field0020;
            (*opponentSlot)->field0028 =
            -78.0 + field0038 + field0028;
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
                field0030 = -4.0;
                field0038 = -4.0;
                field0048 = 0.025;
                (*opponentSlot)->field014a = 3;
            }
            if (field000a == 0x1b) {
                field0030 = -1.8;
                field0038 = -2.3;
                field0048 = 0.035;
                (*opponentSlot)->ResetPose();
                (*opponentSlot)->ResetFrame();
                (*opponentSlot)->field00c0 = -1.8;
                (*opponentSlot)->field00c8 = -2.3;
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
            if (field0020 > 580.0) {
                field0020 = 580.0;
                field0030 = 0.0;
            }
            if (field0020 < 60.0) {
                field0020 = 60.0;
                field0030 = 0.0;
            }
            SetHorizontalOffset(0x32,3);
            SetHorizontalShake(0x32,3);
        }
        if ((((field000a < 0xd) ||
            ((0xe < field000a && (field000a < 0x19)))) ||
            ((0x1a < field000a && (field000a < 0x1e)))) &&
            (field0038 = field0038 + field0048,
            0.0 < field0038 + field0028)) {
            if (field000a < 0xd) {
                field0028 = 0.0;
                ResetFrame();
                (*opponentSlot)->ResetPose();
                (*opponentSlot)->field0008 = 0x62;
                (*opponentSlot)->field0028 = 0;
                (*opponentSlot)->ResetFrame();
                (*opponentSlot)->field014a = 0x96;
                (*opponentSlot)->field0020 =
                (double)(int)facing + field0020;
                (*opponentSlot)->facing = -facing;
                ApplyDamage(1000,980.0);
                SetVerticalShake(10,0);
                (*opponentSlot)->field0140 = 30000;
                field000c = 0;
                field000a = 0xd;
                field02c9 = 0x16;
                return;
            }
            if ((0xe < field000a) && (field000a < 0x19)) {
                field0028 = 0.0;
                ResetFrame();
                (*opponentSlot)->ResetPose();
                (*opponentSlot)->field0008 = 0x62;
                (*opponentSlot)->field0028 = 0;
                (*opponentSlot)->field0020 =
                (double)(int)facing + field0020;
                (*opponentSlot)->facing = -facing;
                (*opponentSlot)->ResetFrame();
                (*opponentSlot)->field014a = 0xba;
                ApplyDamage(0xed8,980.0);
                (*opponentSlot)->field0140 = 0;
                SetVerticalShake(0x14,0x1e);
                field000c = 0;
                field000a = 0x19;
                field02c9 = 0x16;
                return;
            }
            if (field000a == 0x1d) {
                field0028 = 0.0;
                ResetFrame();
                field000c = 0;
                field000a = 0x1e;
                return;
            }
        }
        if ((field000a < 0xd) &&
            (field0030 = field0030 - 0.025,
            field0030 < 0.0)) {
            field0030 = 0.0;
        }
        if (((0xe < field000a) && (field000a < 0x19)) &&
            (field0030 = field0030 + 0.025,
            field0030 > 0.0)) {
            field0030 = 0.0;
        }
        if (field000a < 4) {
            (*opponentSlot)->field0008 = 0x67;
            (*opponentSlot)->field0020 =
            (double)(facing * 0x16) + field0020;
            (*opponentSlot)->field0028 = field0028 - 52.0;
        }
        if (((field000a == 4) || (field000a == 0xf)) ||
            (field000a == 0x10)) {
            (*opponentSlot)->field0008 = 0x67;
            (*opponentSlot)->field0020 =
            (15.0 + field0030) * facing +
            field0020;
            (*opponentSlot)->field0028 =
            -70.0 + field0038 + field0028;
        }
        if ((field000a == 5) || (field000a == 0x11)) {
            (*opponentSlot)->field0008 = 0x76;
            (*opponentSlot)->field0020 =
            (-25.0 + field0030) * facing +
            field0020;
            (*opponentSlot)->field0028 =
            -65.0 + field0038 + field0028;
            (*opponentSlot)->facing = facing;
        }
        if ((field000a == 6) || (field000a == 0x12)) {
            (*opponentSlot)->field0008 = 0x75;
            (*opponentSlot)->field0020 =
            (-28.0 + field0030) * facing +
            field0020;
            (*opponentSlot)->field0028 =
            -43.0 + field0038 + field0028;
            (*opponentSlot)->facing = facing;
        }
        if ((field000a == 7) || (field000a == 0x13)) {
            (*opponentSlot)->field0008 = 0x75;
            (*opponentSlot)->field0020 =
            (-12.0 + field0030) * facing +
            field0020;
            (*opponentSlot)->field0028 =
            -29.0 + field0038 + field0028;
            (*opponentSlot)->facing = facing;
        }
        if ((field000a == 8) || (field000a == 0x14)) {
            (*opponentSlot)->field0008 = 0x68;
            (*opponentSlot)->field0020 =
            (12.0 + field0030) * facing +
            field0020;
            (*opponentSlot)->field0028 =
            -23.0 + field0038 + field0028;
            (*opponentSlot)->facing = -facing;
        }
        if ((field000a == 9) || (field000a == 0x15)) {
            (*opponentSlot)->field0008 = 0x68;
            (*opponentSlot)->field0020 =
            (23.0 + field0030) * facing +
            field0020;
            (*opponentSlot)->field0028 =
            -36.0 + field0038 + field0028;
            (*opponentSlot)->facing = -facing;
        }
        if ((field000a == 10) || (field000a == 0x16)) {
            (*opponentSlot)->field0008 = 0x67;
            (*opponentSlot)->field0020 =
            (28.0 + field0030) * facing +
            field0020;
            (*opponentSlot)->field0028 =
            -58.0 + field0038 + field0028;
            (*opponentSlot)->facing = -facing;
        }
        if ((field000a == 0xb) || (field000a == 0x17)) {
            (*opponentSlot)->field0008 = 0x67;
            (*opponentSlot)->field0020 =
            (14.0 + field0030) * facing +
            field0020;
            (*opponentSlot)->field0028 =
            -73.0 + field0038 + field0028;
            (*opponentSlot)->facing = -facing;
        }
        if ((field000a == 0xc) || (field000a == 0x18)) {
            (*opponentSlot)->field0008 = 0x76;
            (*opponentSlot)->field0020 =
            (-12.0 + field0030) * facing +
            field0020;
            (*opponentSlot)->field0028 =
            -78.0 + field0038 + field0028;
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
                field0030 = -4.0;
                field0038 = -7.0;
                field0048 = 0.025;
                (*opponentSlot)->field014a = 3;
            }
            if (field000a == 0x1b) {
                field0030 = -1.8;
                field0038 = -2.3;
                field0048 = 0.035;
                (*opponentSlot)->ResetPose();
                (*opponentSlot)->ResetFrame();
                (*opponentSlot)->field00c0 = -1.8;
                (*opponentSlot)->field00c8 = -2.3;
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
            field0030 = 0.0;
            field0038 = 0.0;
            field0048 = 0.0;
        }
        if ((field000a == 1) && ((unsigned short)field000c == 0)) {
            field014c = 0x78;
            field0148 = field0148 + -1000;
            SetTint(0xb0,3);
            effect.type = 0x44;
            effect.palette = 0x13;
            effect.x = (double)((int(field0020)) + facing * 0xf);
            effect.y = (double)((int(field0028)) + -0x22);
            effect.group = 2;
            effect.owner = 1;
            effect.layer = 1;
            contextOwner->EmitEffect(&effect);
            SetHorizontalShake(0x32,0x78);
            field016c = 0xc;
        }
        if (((unsigned short)field000c == 0) &&
            ((((field000a == 9 || (field000a == 0xb)) ||
            (field000a == 0xd)) || (field000a == 0xf)))) {
            field02c9 = 0x15;
        }
        if ((7 < field000a) && (field000a < 0x10)) {
            if (inputX == facing) {
                field0030 = field0030 + 0.012;
            }
            if ((int)inputX == -(int)facing) {
                field0030 = field0030 - 0.012;
            }
            if (field0030 < -1.2) { field0030 = -1.2; } else if (field0030 > 1.2) { field0030 = 1.2; }
        }
        if (0xf < field000a) {
            if ((field0030 > 0.0) &&
                (field0030 = field0030 - 0.01,
                field0030 < 0.0)) {
                field0030 = 0.0;
            }
            if ((field0030 < 0.0) &&
                (field0030 = field0030 + 0.01,
                field0030 > 0.0)) {
                field0030 = 0.0;
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
            field0030 = 0.0;
            field0038 = 0.0;
            field0048 = 0.0;
        }
        if ((field000a == 1) && ((unsigned short)field000c == 0)) {
            field014c = 0x78;
            field0148 = field0148 + -2000;
            SetTint(0xb0,3);
            effect.type = 0x45;
            effect.palette = 5;
            effect.x = (double)((int(field0020)) + facing * 0xf);
            effect.y = (double)((int(field0028)) + -0x22);
            effect.group = 2;
            effect.owner = 1;
            effect.layer = 1;
            contextOwner->EmitEffect(&effect);
            SetHorizontalShake(0x32,0x78);
            field016c = 99;
        }
        if (((unsigned short)field000c == 0) &&
            ((((field000a == 9 || (field000a == 0xb)) ||
            (field000a == 0xd)) || (field000a == 0xf)))) {
            field02c9 = 0x15;
        }
        if ((7 < field000a) && (field000a < 0x10)) {
            if (inputX == facing) {
                field0030 = field0030 + 0.012;
            }
            if ((int)inputX == -(int)facing) {
                field0030 = field0030 - 0.012;
            }
            if (field0030 < -1.3) { field0030 = -1.3; } else if (field0030 > 1.3) { field0030 = 1.3; }
        }
        if (0xf < field000a) {
            if ((field0030 > 0.0) &&
                (field0030 = field0030 - 0.01,
                field0030 < 0.0)) {
                field0030 = 0.0;
            }
            if ((field0030 < 0.0) &&
                (field0030 = field0030 + 0.01,
                field0030 > 0.0)) {
                field0030 = 0.0;
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
            field0030 = 0.0;
            field0038 = 0.0;
            field0048 = 0.0;
        }
        if (field000a > 0) {
            contextOwner->SetSceneTimer(0xf);
        }
        if ((field000a == 1) && ((unsigned short)field000c == 0)) {
            field014c = 0x78;
            field0148 = field0148 + -3000;
            SetTint(0xb0,3);
            effect.type = 0x46;
            effect.palette = 0x40;
            effect.x = (double)((int(field0020)) + facing * 0xf);
            effect.y = (double)((int(field0028)) + -0x22);
            effect.group = 2;
            effect.owner = 1;
            effect.layer = 1;
            contextOwner->EmitEffect(&effect);
            SetHorizontalShake(0x32,0x78);
            field016c = 99;
            field02c9 = 0x25;
        }
        if (((unsigned short)field000c == 0) &&
            ((((field000a == 9 || (field000a == 0xb)) ||
            (field000a == 0xd)) || (field000a == 0xf)))) {
            field02c9 = 0x15;
        }
        if ((7 < field000a) && (field000a < 0x10)) {
            if (inputX == facing) {
                field0030 = field0030 + 0.012;
            }
            if ((int)inputX == -(int)facing) {
                field0030 = field0030 - 0.012;
            }
            if (field0030 < -1.4) { field0030 = -1.4; } else if (field0030 > 1.4) { field0030 = 1.4; }
        }
        if (0xf < field000a) {
            if ((field0030 > 0.0) &&
                (field0030 = field0030 - 0.01,
                field0030 < 0.0)) {
                field0030 = 0.0;
            }
            if ((field0030 < 0.0) &&
                (field0030 = field0030 + 0.01,
                field0030 > 0.0)) {
                field0030 = 0.0;
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
            field0030 = 0.0;
            field0038 = 0.0;
            field0048 = 0.0;
        }
        if ((field000a == 0) && ((unsigned short)field000c == 0)) {
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
            field016c = 1;
            SetHorizontalShake(0x32,0x78);
        }
        if (field000a > 13 && field000a < 18 && field0168 == 3) {
            ResetPose();
            ResetFrame();
            (*opponentSlot)->ResetFrame();
            (*opponentSlot)->field014a = 0xb4;
            (*opponentSlot)->field0028 = 0;
            (*opponentSlot)->field0008 = 0x49;
            (*opponentSlot)->field0020 =
            (double)(facing * 0x1e) + field0020;
            field0008 = 0x13e;
            (*opponentSlot)->facing = -facing;
            break;
        }
        if (field0030 > 0.0) {
            field0030 = field0030 - 0.035;
        }
        if (field0030 < 0.0) {
            field0030 = 0.0;
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
                field0030 = 3.2;
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
            field016c = 99;
        }
        if (((field000a == 5) || (field000a == 10)) &&
            ((unsigned short)field000c == 0)) {
            field02c9 = 0x15;
        }
        if (field0030 > 0.0) {
            field0030 = field0030 - 0.035;
        }
        if (field0030 < 0.0) {
            field0030 = 0.0;
        }
        if (field0028 < 0.0) {
            field0048 = 0.055;
            field0038 = field0038 + field0048;
        }
        if (field000a > 18 && field000a < 31 && field0028 + field0038 > 0.0) {
            field000c = 0;
            field000a = 0x1f;
            field0028 = 0.0;
            ResetFrame();
            break;
        }
        ++field000c;
        if ((unsigned short)field000c >= frameDuration) {
            field000c = 0;
            ++field000a;
            field0168 = 0;
            if (field000a == 9) {
                field0020 = (double)(facing * 0xf) + field0020;
            }
            if (field000a == 10) {
                field0020 = (double)(facing * 0xf) + field0020;
            }
            if (field000a == 0xc) {
                field0020 = (double)(facing * 0xf) + field0020;
            }
            if (field000a == 0xd) {
                if (1 < field3138) {
                    field000a = 0xf;
                    return;
                }
                field0020 = (double)(facing * 0xf) + field0020;
            }
            if ((field000a == 0xf) && (field3138 < 1)) {
                field000a = 5;
                ++field3138;
            }
            if (field000a == 0x13) {
                field0038 = -3.3;
                field0030 = 1.5;
                field016c = 3;
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
            field0030 = 0.0;
            field0038 = 0.0;
            field0048 = 0.0;
        }
        if ((field000a == 0) && ((unsigned short)field000c == 0)) {
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
            field016c = 1;
            SetHorizontalShake(0x32,0x78);
        }
        if (field000a > 13 && field000a < 18 && field0168 == 3) {
            ResetPose();
            ResetFrame();
            (*opponentSlot)->ResetFrame();
            (*opponentSlot)->field014a = 0xb4;
            (*opponentSlot)->field0028 = 0;
            (*opponentSlot)->field0008 = 0x49;
            (*opponentSlot)->field0020 =
            (double)(facing * 0x1e) + field0020;
            field0008 = 0x140;
            (*opponentSlot)->facing = -facing;
            break;
        }
        if (field0030 > 0.0) {
            field0030 = field0030 - 0.035;
        }
        if (field0030 < 0.0) {
            field0030 = 0.0;
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
                field0030 = 4.0;
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
            field016c = 99;
        }
        if (((field000a == 5) || (field000a == 10)) &&
            ((unsigned short)field000c == 0)) {
            field02c9 = 0x15;
        }
        if (field0030 > 0.0) {
            field0030 = field0030 - 0.035;
        }
        if (field0030 < 0.0) {
            field0030 = 0.0;
        }
        if (field0028 < 0.0) {
            field0048 = 0.055;
            field0038 = field0038 + field0048;
        }
        if (field000a > 25 && field000a < 38 && field0028 + field0038 > 0.0) {
            field000c = 0;
            field000a = 0x26;
            field0028 = 0.0;
            ResetFrame();
            break;
        }
        ++field000c;
        if ((unsigned short)field000c >= frameDuration) {
            field000c = 0;
            ++field000a;
            field0168 = 0;
            if (field000a == 9) {
                field0020 = (double)(facing * 0xf) + field0020;
            }
            if (field000a == 10) {
                field0020 = (double)(facing * 0xf) + field0020;
            }
            if (field000a == 0xc) {
                field0020 = (double)(facing * 0xf) + field0020;
            }
            if (field000a == 0xd) {
                if (1 < field3138) {
                    field000a = 0xf;
                    return;
                }
                field0020 = (double)(facing * 0xf) + field0020;
            }
            if ((field000a == 0xf) && (field3138 < 2)) {
                field000a = 5;
                ++field3138;
            }
            if (field000a == 0x19) {
                field0038 = -4.0;
                field0030 = 1.6;
                field016c = 4;
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
            field0030 = 0.0;
            field0038 = 0.0;
            field0048 = 0.0;
        }
        contextOwner->SetSceneTimer(0xf);
        if ((field000a == 0) && ((unsigned short)field000c == 0)) {
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
            field016c = 1;
            SetHorizontalShake(0x32,0x78);
            field02c9 = 0x25;
        }
        if (field000a > 13 && field000a < 18 && field0168 == 3) {
            ResetPose();
            ResetFrame();
            (*opponentSlot)->ResetFrame();
            (*opponentSlot)->field014a = 0xb4;
            (*opponentSlot)->field0028 = 0;
            (*opponentSlot)->field0008 = 0x49;
            (*opponentSlot)->field0020 =
            (double)(facing * 0x1e) + field0020;
            field0008 = 0x142;
            (*opponentSlot)->facing = -facing;
            break;
        }
        if (field0030 > 0.0) {
            field0030 = field0030 - 0.035;
        }
        if (field0030 < 0.0) {
            field0030 = 0.0;
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
                field0030 = 4.5;
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
            field016c = 99;
        }
        if (((field000a == 5) || (field000a == 10)) &&
            ((unsigned short)field000c == 0)) {
            field02c9 = 0x15;
        }
        if (field0030 > 0.0) {
            field0030 = field0030 - 0.025;
        }
        if (field0030 < 0.0) {
            field0030 = 0.0;
        }
        if (field0028 < 0.0) {
            field0048 = 0.045;
            field0038 = field0038 + field0048;
        }
        if (field000a > 27 && field000a < 33 && field0028 + field0038 > 0.0) {
            field000c = 0;
            field000a = 0x21;
            field0028 = 0.0;
            ResetFrame();
            break;
        }
        if (field000a > 37 && field000a < 42 && field0028 + field0038 > 0.0) {
            field000c = 0;
            field000a = 0x2a;
            field0028 = 0.0;
            ResetFrame();
            break;
        }
        if (field000a > 44 && field000a < 67 && field0028 + field0038 > 0.0) {
            field000c = 0;
            field000a = 0x43;
            field0028 = 0.0;
            ResetFrame();
            break;
        }
        ++field000c;
        if ((unsigned short)field000c >= frameDuration) {
            field000c = 0;
            ++field000a;
            field0168 = 0;
            if (field000a == 9) {
                field0020 =
                (double)(facing * 0xf) + field0020;
            }
            if (field000a == 10) {
                field0020 =
                (double)(facing * 0xf) + field0020;
            }
            if (field000a == 0xc) {
                field0020 =
                (double)(facing * 0xf) + field0020;
            }
            if (field000a == 0xd) {
                field0020 =
                (double)(facing * 0xf) + field0020;
            }
            if ((field000a == 0xf) && (field3138 < 10)) {
                ++field3138;
                field000a = 5;
            }
            if (field000a == 0x13) {
                field0020 =
                (double)(facing * 0xf) + field0020;
            }
            if (field000a == 0x14) {
                field0020 =
                (double)(facing * 0xf) + field0020;
            }
            if (field000a == 0x16) {
                field0020 =
                (double)(facing * 0xf) + field0020;
            }
            if ((field000a == 0xf) && (field3138 < 8)) {
                field000a = 5;
                ++field3138;
            }
            if (field000a == 0x1c) {
                field0038 = -1.8;
                field0030 = 1.5;
                field016c = 1;
            }
            if (field000a == 0x25) {
                field0038 = -2.6;
                field0030 = 1.5;
                field016c = 1;
            }
            if (field000a == 0x2d) {
                field0038 = -4.5;
                field0030 = 2.2;
                field016c = 8;
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
