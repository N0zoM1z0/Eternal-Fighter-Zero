// Private complete source draft; no acceptance credit.
#include "CharacterViews.h"

void Character08::Slot06()
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
    if (field000c >= frameDuration) {
      field000c = 0;
      ++field000a;
      if (field000a >= frameCount) {
        field000a = 0;
      }
    }
      break;
    case 1:
      field0158 = 0;
      field0030 = 0.7;
      field0038 = 0.0;
      ++field000c;
      if (field000c >= frameDuration) {
        field000c = 0;
        ++field000a;
        if (field000a >= frameCount) {
          field000a = 0;
        }
      }
      break;
    case 2:
      field0158 = 0;
      field0030 = -0.7;
      field0038 = 0.0;
      ++field000c;
      if (field000c >= frameDuration) {
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
      if (field000c >= frameDuration) {
        field000c = 0;
        ++field000a;
        if (field000a >= frameCount) {
          field000a = 0;
        }
      }
      break;
    case 4:
      if ((field000a == 0) && (field000c == 0)) {
        if (field0158 == '\0') {
          FaceOpponent();
        }
        field0030 = 0.0;
      }
      if ((field000a == 2) && (field000c == 0)) {
        field0048 = 0.035;
        field0038 = -2.35;
        if (field0158 == '\x01') {
          field0030 = 0.3;
          field0158 = 0;
        }
      }
      if (2 < field000a) {
        field0038 = field0038 + field0048;
      }
      ++field000c;
      if (field000c >= frameDuration) {
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
      if ((field000a == 0) && (field000c == 0)) {
        if (field0158 == '\0') {
          FaceOpponent();
        }
        field0030 = 0.0;
      }
      if ((field000a == 2) && (field000c == 0)) {
        field0048 = 0.035;
        field0038 = -2.35;
        field0030 = 0.7;
        if (field0158 == '\x01') {
          field0030 = 1.1;
          field0158 = 0;
        }
      }
      if (2 < field000a) {
        field0038 = field0038 + field0048;
      }
      ++field000c;
      if (field000c >= frameDuration) {
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
      if ((field000a == 0) && (field000c == 0)) {
        if (field0158 == '\0') {
          FaceOpponent();
        }
        field0030 = 0.0;
      }
      if ((field000a == 2) && (field000c == 0)) {
        field0048 = 0.035;
        field0038 = -2.35;
        field0030 = -0.7;
      }
      if (2 < field000a) {
        field0038 = field0038 + field0048;
      }
      ++field000c;
      if (field000c >= frameDuration) {
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
      if (field000c >= frameDuration) {
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
      if (field000c >= frameDuration) {
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
      if (field000c >= frameDuration) {
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
      if (field000c >= frameDuration) {
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
    case 14:
      field0048 = 0.035;
      field0158 = 0;
      if ((field000a == 0) && (field000c == 0)) {
        field0038 = -2.35;
        field0030 = 0.0;
        if (field0158 == '\x01') {
          field0030 = 0.4;
          field0158 = 0;
        }
      }
      field0038 = field0038 + field0048;
      ++field000c;
      if (field000c >= frameDuration) {
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
      field0048 = 0.035;
      field0158 = 0;
      if ((field000a == 0) && (field000c == 0)) {
        field0038 = -2.35;
        field0030 = 0.7;
        if (field0158 == '\x01') {
          field0030 = 1.1;
          field0158 = 0;
        }
      }
      field0038 = field0038 + field0048;
      ++field000c;
      if (field000c >= frameDuration) {
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
      field0048 = 0.035;
      field0158 = 0;
      if ((field000a == 0) && (field000c == 0)) {
        field0038 = -2.35;
        field0030 = -0.7;
        if (field0158 == '\x01') {
          field0158 = 0;
        }
      }
      field0038 = field0038 + field0048;
      ++field000c;
      if (field000c >= frameDuration) {
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
      if ((field000a == 0) && (field000c == 0)) {
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
      if (field000c >= frameDuration) {
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
      if ((field000a == 0) && (field000c == 0)) {
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
      if (field000c >= frameDuration) {
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
      if ((field000a == 0) && (field000c == 0)) {
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
      if (field000c >= frameDuration) {
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
      if ((field000a == 0) && (field000c == 0)) {
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
      if (field000c >= frameDuration) {
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
      if ((field000a == 0) && (field000c == 0)) {
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
      if (field000c >= frameDuration) {
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
      if ((field000a == 0) && (field000c == 0)) {
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
      if (field000c >= frameDuration) {
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
      if ((field000a == 0) && (field000c == 0)) {
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
      if (field000c >= frameDuration) {
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
      if ((field000a == 0) && (field000c == 0)) {
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
      if (field000c >= frameDuration) {
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
      if ((field000a == 0) && (field000c == 0)) {
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
      if (field000c >= frameDuration) {
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
      if ((field000a == 0) && (field000c == 0)) {
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
      if (field000c >= frameDuration) {
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
      if ((field000a == 0) && (field000c == 0)) {
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
      if (field000c >= frameDuration) {
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
      if ((field000a == 0) && (field000c == 0)) {
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
      if (field000c >= frameDuration) {
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
      if ((field000a == 0) && (field000c == 0)) {
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
      if (field000c >= frameDuration) {
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
      if ((field000a == 0) && (field000c == 0)) {
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
      if (field000c >= frameDuration) {
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
      if ((field000a == 0) && (field000c == 0)) {
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
      if (field000c >= frameDuration) {
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

        if ((field000a == 0) && (field000c == 0)) {
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
        if (field000c >= frameDuration) {
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

        if ((field000a == 0) && (field000c == 0)) {
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
        if (field000c >= frameDuration) {
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

        if ((field000a == 0) && (field000c == 0)) {
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
        if (field000c >= frameDuration) {
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

        if ((field000a == 0) && (field000c == 0)) {
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
        if (field000c >= frameDuration) {
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

        if (field000c >= frameDuration) {
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
      if (field000c >= frameDuration) {
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
      if (((field000a == 0) && (field000c == 0)) &&
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
      if (field000c >= frameDuration) {
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
      if ((field000a == 0) && (field000c == 0)) {
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
      if (field000c >= frameDuration) {
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
      if (field000c >= frameDuration) {
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
      if (field000c >= frameDuration) {
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
      if (field000c >= frameDuration) {
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
      if ((field000a == 0) && (field000c == 0)) {
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
      if (field000c >= frameDuration) {
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
      if ((field000a == 0) && (field000c == 0)) {
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
      if (field000c >= frameDuration) {
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
      if ((field000a == 0) && (field000c == 0)) {
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
      if (field000c >= frameDuration) {
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
      if ((field000a == 0) && (field000c == 0)) {
        effect.type = 499;
        effect.x = (double)(int(field0020));
        effect.y = (double)(int(field0028));
        effect.flag0018 = facing;
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
      if (field000c >= frameDuration) {
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
      if (((field000a == 0) && (field000c == 0)) &&
         (field3138 == 0)) {
        field02c9 = 0x1e;
        field0038 = -0.45;
        field0030 = -0.1;
        ++field3138;
        field0148 = field0148 + 0x1e;
      }
      if ((field000a == 4) && (field000c == 0)) {
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
      if (field000c >= frameDuration) {
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
      if ((field000a == 0) && (field000c == 0)) {
        if (field3144 == 0) {
          effect.type = 0x1f0;
          effect.x = (double)(int(field0020));
          effect.y = (double)(int(field0028));
          effect.group = 0;
          effect.layer = 0;
          effect.owner = 1;
          effect.flag0018 = facing;
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
        if ((field000a == 2) && (field000c == 0)) {
          field0030 = -2.0;
        }
        if (1 < field000a) {
          field0030 = field0030 + 0.06;
        }
        if (field0030 > 0.0) {
          field0030 = 0.0;
        }
        ++field000c;
        if (field000c >= frameDuration) {
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
      if ((field000a == 0) && (field000c == 0)) {
        if (field3144 == 0) {
          effect.type = 0x1f0;
          effect.x = (double)(int(field0020));
          effect.y = (double)(int(field0028));
          effect.group = 0;
          effect.layer = 0;
          effect.owner = 1;
          effect.flag0018 = facing;
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
        if ((field000a == 2) && (field000c == 0)) {
          field0030 = -2.0;
        }
        if (1 < field000a) {
          field0030 = field0030 + 0.06;
        }
        if (field0030 > 0.0) {
          field0030 = 0.0;
        }
        ++field000c;
        if (field000c >= frameDuration) {
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
      if ((field000a == 0) && (field000c == 0)) {
        if (field3144 == 0) {
          effect.type = 0x1f0;
          effect.x = (double)(int(field0020));
          effect.y = (double)(int(field0028));
          effect.group = 0;
          effect.layer = 0;
          effect.owner = 1;
          effect.flag0018 = facing;
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
      if (field000c >= frameDuration) {
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
      if ((field000a == 0) && (field000c == 0)) {
        if (field3144 == 0) {
          effect.type = 0x1f0;
          effect.x = (double)(int(field0020));
          effect.y = (double)(int(field0028));
          effect.group = 0;
          effect.layer = 0;
          effect.owner = 1;
          effect.flag0018 = facing;
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
      if (field000c >= frameDuration) {
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
      if ((field000a == 0) && (field000c == 0)) {
        effect.type = 0x1ef;
        effect.x = 60.0;
        effect.y = 40.0;
        effect.payload = 1;
        effect.flag0018 = '\x01';
        effect.group = 0;
        effect.layer = 1;
        EmitLocalEffect(&effect);
      }
      ++field000c;
      if (field000c >= frameDuration) {
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
      if (field000c >= frameDuration) {
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
      if ((field000a == 0) && (field000c == 0)) {
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
      if (field000c >= frameDuration) {
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
      if ((field000a == 0) && (field000c == 0)) {
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
      if (field000c >= frameDuration) {
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
      field0158 = 0;
      if (((0 < field0108) && (99 < field000c)) &&
         (field000a == 0)) {
        field0008 = 0x60;
        ResetPose();
      }
      if (field000c >= frameDuration) {
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
      if ((field000a == 0) && (field000c == 0)) {
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
      if (field000c >= frameDuration) {
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
      if ((field000a == 0) && (field000c == 0)) {
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
      if (field000c >= frameDuration) {
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
      if ((field000a == 0) && (field000c == 0)) {
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
      if (field000c >= frameDuration) {
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
      if ((field000a == 0) && (field000c == 0)) {
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
      if (field000c >= frameDuration) {
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
      if ((field000a == 0) && (field000c == 0)) {
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
      if (field000c >= frameDuration) {
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
      if ((field000a == 0) && (field000c == 0)) {
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
      if (field000c >= frameDuration) {
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
      if ((field000a == 0) && (field000c == 0)) {
        field0038 = -2.6;
        field0148 = field0148 + 0xf;
        field0048 = 0.06;
      }
      field0030 = -1.2;
      field0038 = field0038 + field0048;
      ++field000c;
      if (field000c >= frameDuration) {
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
      if ((field000a == 0) && (field000c == 0)) {
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
      if (field000c >= frameDuration) {
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
      if ((field000a == 0) && (field000c == 0)) {
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
      if (field000c >= frameDuration) {
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
      if ((field000a == 0) && (field000c == 0)) {
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
      if (field000c >= frameDuration) {
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
      if ((field000a == 0) && (field000c == 0)) {
        ResetFrame();
      }
      if ((field000a == 2) && (field000c == 0)) {
        field0038 = -1.5;
        field0048 = 0.025;
        field016c = 1;
      }
      if ((field000a == 6) && (field000c == 0)) {
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
        if (field000c >= frameDuration) {
          field000c = 0;
          ++field000a;
          if (field000a == 0xf) {
            field0048 = 0.035;
          }
          if (field000a >= frameCount) {
            field000a = field000a + -2;
          }
        }
      
      break;
    case 163:
      if ((field000a == 0) && (field000c == 0)) {
        StartTrail(3);
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

        if ((field000a == 0) && (field000c == 0)) {
          field0038 = 0.0;
          field0048 = 0.0;
        }
        field0030 = 1.5;
        field0158 = 1;
        ++field000c;
        ++field3138;
        ++field313c;
        if (field000c >= frameDuration) {
          field000c = 0;
          ++field000a;
          if (field000a == 4) {
            field000a = field000a + -2;
          }
          if (field000a >= frameCount) {
            field0008 = 0;
            ResetPose();
            return;
          }
        }
        if (((inputX == facing) && (field313c >= 80)) &&
           (field000a < 4)) {
          field0008 = 0xb2;
          ResetPose();
        }
        if (((inputX != facing) && (field3138 >= 60)) &&
           (field000a < 4)) {
          field0008 = 0xb2;
          ResetPose();
        }
      
      break;
    case 164:
      StartTrail(2);
      if ((field000a == 0) && (field000c == 0)) {
        field0030 = 0.0;
        field0038 = 0.0;
      }
      if ((field000a == 2) && (field000c == 0)) {
        field0030 = -1.6;
        field0038 = -1.0;
        field0048 = 0.04;
      }
      if ((1 < field000a) && (field000a < 5)) {
        field0038 = field0038 + field0048;
      }
      if (((2 < field000a) &&
          (0.0 <= field0038 + field0028)) &&
         (field3138 == 0)) {
        field0030 = 0.0;
        field0038 = 0.0;
        field0040 = 0.0;
        field0028 = 0.0;
        ++field3138;
        field02c9 = 9;
        field000a = 5;
        field000c = 0;
      }
      ++field000c;
      if (field000c >= frameDuration) {
        field000c = 0;
        ++field000a;
        if (field000a >= frameCount) {
          FaceOpponent();
          field0008 = 0;
          ResetPose();
        }
      }
      break;
    case 165:
      if (((field000a == 0) && (field000c == 0)) &&
         (field3138 == 0)) {
        field0030 = 1.3;
        StartTrail(3);
        field0038 = 0.0;
        field0048 = 0.0;
        field02c9 = 0x11;
      }
      ++field000c;
      ++field3138;
      ++field313c;
      if (field000c >= frameDuration) {
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
      if (((field000a == 0) && (field000c == 0)) &&
         (field3138 == 0)) {
        field0030 = -1.3;
        field0038 = 0.0;
        field0048 = 0.0;
        StartTrail(3);
        field02c9 = 0x11;
      }
      ++field000c;
      ++field3138;
      ++field313c;
      if (field000c >= frameDuration) {
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
      if ((field000a == 0) && (field000c == 0)) {
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
      if ((field000a == 1) && (field000c == 0)) {
        field02c9 = 0x12;
        effect.type = 1;
        effect.x = (double)(int(field0020));
        effect.y = (double)(int(field0028));
        effect.group = 2;
        effect.layer = 1;
        contextOwner->EmitEffect(&effect);
      }
      if ((field000a == 2) && (field000c == 0)) {
        effect.type = 4;
        effect.x = (double)(int(field0020));
        effect.y = (double)(int(field0028));
        effect.group = 2;
        effect.layer = 1;
        contextOwner->EmitEffect(&effect);
      }
      ++field000c;
      if (field000c >= frameDuration) {
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
      if ((field000a == 0) && (field000c == 0)) {
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
      if (field000c >= frameDuration) {
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
      if ((field000a == 0) && (field000c == 0)) {
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
      if (field000c >= frameDuration) {
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
      if ((field000a == 0) && (field000c == 0)) {
        field3138 = (int(field0030 * 100.0));
        field313c = (int(field0038 * 100.0));
        if (field0048 == 0.0) {
          field0048 = 0.035;
        }
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
        if (field000c >= frameDuration) {
          field000c = 0;
          ++field000a;
          if (field000a >= frameCount) {
            field0008 = 9;
            ResetPose();
          }
        }
      
      break;
    case 171:
      if ((field000a == 0) && (field000c == 0)) {
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
      if ((field000a == 0) && (field000c == 0)) {
        field02c9 = 0x12;
        effect.type = 1;
        effect.x = (double)(int(field0020));
        effect.y = (double)(int(field0028));
        effect.group = 2;
        effect.layer = 1;
        contextOwner->EmitEffect(&effect);
      }
      ++field000c;
      if (field000c >= frameDuration) {
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
        if (field000c >= frameDuration) {
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
      if ((field000a == 0) && (field000c == 0)) {
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
      if (field000c >= frameDuration) {
        field000c = 0;
        ++field000a;
        if (field000a == 2) {
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
      if (field0158 == '\0') {
        field0030 = 0.0;
        field0038 = 0.0;
      }
      if (field0030 > 0.0 && field0158 == 1) {
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

        if ((field000a == 2) && (field000c == 0)) {
          field0148 = field0148 + 5;
          field02c9 = 0x15;
          field016c = 1;
        }
        ++field000c;
        if (field000c >= frameDuration) {
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
      if (field0158 == '\0') {
        field0030 = 0.0;
        field0038 = 0.0;
      }
      if (field0030 > 0.0 && field0158 == 1) {
        field0030 = field0030 - 0.03;
      
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

        if ((field000a == 1) && (field000c == 0)) {
          field0148 = field0148 + 0xf;
          field02c9 = 0x14;
          field016c = 1;
        }
        ++field000c;
        if (field000c >= frameDuration) {
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
      if (field0158 == '\0') {
        field0030 = 0.0;
        field0038 = 0.0;
      }
      if (field0030 > 0.0 && field0158 == 1) {
        field0030 = field0030 - 0.03;
      
      } else {
        field0030 = 0.0;
        field0158 = 0;
      
      }
      if ((field000a == 4) && (field000c == 0)) {
        field0148 = field0148 + 0xf;
        field02c9 = 0x14;
        field016c = 1;
      }
      ++field000c;
      if (field000c >= frameDuration) {
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
    case 203:
      if (field0158 == '\0') {
        field0030 = 0.0;
        field0038 = 0.0;
      }
      if (((inputY == -1) && (field000a > 0)) &&
         ((field015c < 3 && (field0168 == 3)))) {
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

        if (field0030 > 0.0 && field0158 == 1) {
          field0030 = field0030 - 0.06;
        
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

          if ((field000a == 5) && (field000c == 0)) {
            field0148 = field0148 + 0x23;
            field02c9 = 0x14;
            field016c = 1;
            effect.type = 400;
            effect.x = (double)((int(field0020)) + facing * 0x1e);
            effect.y = (double)(int(field0028));
            effect.group = 2;
            effect.palette = 1;
            effect.layer = 1;
            effect.flag0018 = facing;
            EmitLocalEffect(&effect);
          }
          ++field000c;
          if (field000c >= frameDuration) {
            field000c = 0;
            ++field000a;
            if (field000a < 6) {
              field0168 = 0;
            }
            if ((field000a == 8) && (field313c < 5)) {
              ++field313c;
              field000a = field000a + -2;
              if (field313c == 3) {
                field016c = 0;
              }
            }
            if (field000a >= frameCount) {
              field0008 = 0;
              FaceOpponent();
              ResetPose();
            }
          }
        
      
      break;
    case 204:
      if (field0158 == '\0') {
        field0030 = 0.0;
        field0038 = 0.0;
      }
      if (field0030 > 0.0 && field0158 == 1) {
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

        if ((field000a == 1) && (field000c == 0)) {
          field0148 = field0148 + 5;
          field02c9 = 0x15;
          field016c = 1;
        }
        ++field000c;
        if (field000c >= frameDuration) {
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
      if (field0158 == '\0') {
        field0030 = 0.0;
        field0038 = 0.0;
      }
      if (field0030 > 0.0 && field0158 == 1) {
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

        if ((field000a == 2) && (field000c == 0)) {
          field0148 = field0148 + 0xd;
          field02c9 = 0x14;
          field016c = 1;
        }
        ++field000c;
        if (field000c >= frameDuration) {
          field000c = 0;
          ++field000a;
          if (field000a < 4) {
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
      if (field0158 == '\0') {
        field0030 = 0.0;
        field0038 = 0.0;
      }
      if (field0030 > 0.0 && field0158 == 1) {
        field0030 = field0030 - 0.03;
      
      } else {
        field0030 = 0.0;
        field0158 = 0;
      
      }
      if ((field000a == 3) && (field000c == 0)) {
        field0148 = field0148 + 0x19;
        field02c9 = 0x14;
        field016c = 1;
      }
      ++field000c;
      if (field000c >= frameDuration) {
        field000c = 0;
        ++field000a;
        if (field000a < 4) {
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

        if ((field000a == 2) && (field000c == 0)) {
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
          if (field000c >= frameDuration) {
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

        if ((field000a == 1) && (field000c == 0)) {
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
          if (field000c >= frameDuration) {
            field000c = 0;
            ++field000a;
            if ((field000a == 4) && (field3138 == 0)) {
              field000a = field000a + -2;
              ++field3138;
            }
            if (field000a < 3) {
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

        if ((field000a == 2) && (field000c == 0)) {
          field02c8 = 2;
          field0148 = field0148 + 0x1e;
          field02c9 = 0x14;
          field016c = 3;
        }
        if (field0028 + field0038 >= 0.0) {
          field0028 = 0.0;
          field0008 = 0xd;
          ResetPose();
        
        break;
      }

          ++field000c;
          if (field000c >= frameDuration) {
            field000c = 0;
            ++field000a;
            if ((field000a == 6) && (field3138 < 4)) {
              field000a = field000a + -2;
              ++field3138;
            }
            if (0 < field016c) {
              field0168 = 0;
            }
            if (field000a >= frameCount) {
              field0008 = 9;
              ResetPose();
            }
          }
        
      
      break;
    case 220:
      field0030 = 0.0;
      field0038 = 0.0;
      field0158 = 0;
      if (((field000a == 1) && (field000c == 0)) &&
         ((*opponentSlot)->field0028 == 0.0)) {
        field016c = 1;
      }
      else {
        field016c = 0;
      }
      if ((field000a == 1) && (field0168 == 3)) {
        field0030 = 0.0;
        field0038 = 0.0;
        field00b8 = 0.0;
        ResetPose();
        (*opponentSlot)->ResetPose();
        (*opponentSlot)->ResetFrame();
        field0008 = 0xdd;
        (*opponentSlot)->field0008 = 0x6b;
        effect.type = 0;
        effect.x = (double)((int(field0020)) + facing * 0x25);
        effect.y = (double)((int(field0028)) + -0x2a);
        effect.group = 2;
        effect.layer = 1;
        contextOwner->EmitEffect(&effect);
      }
      ++field000c;
      if (field000c >= frameDuration) {
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
    case 221:
      if (((field000a == 1) && (field000c == 0)) &&
         (field3140 == 8)) {
        ApplyDamage(1000,750.0);
        (*opponentSlot)->ResetPose();
        (*opponentSlot)->field0008 = 0x56;
        (*opponentSlot)->field00c0 = -1.0;
        (*opponentSlot)->field00c8 = -4.0;
      }
      if (field000a > 14 && (field0038 = field0038 + field0048, field0028 + field0038 > 0.0)) {
        field0028 = 0.0;
        field0008 = 0xd;
        ResetPose();
        ResetFrame();
      
        break;
      }

        ++field000c;
        if (field000c >= frameDuration) {
          field000c = 0;
          ++field000a;
          field0168 = 0;
          if ((field000a == 2) && (field3140 < 0xe)) {
            ++field3140;
            field000a = 0;
          }
          if (field000a >= frameCount) {
            field0008 = 0;
            ResetPose();
            FaceOpponent();
          }
        }
      
      break;
    case 230:
      StartTrail(3);
      field0158 = 0;
      if (field0030 < 0.0) {
        field0030 = 0.0;
      }
      if ((field000a == 0) && (field000c == 0)) {
        field0038 = 0.0;
      }
      if ((field000a == 1) && (field000c == 0)) {
        field0148 = field0148 + 5;
        field02c9 = 0x15;
        field016c = 1;
      }
      ++field000c;
      if (field000c >= frameDuration) {
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

        field0030 = field0030 - 0.03;
        if (field0030 < 0.0) {
          field0030 = 0.0;
        }
        if ((field000a == 0) && (field000c == 0)) {
          field0038 = 0.0;
        }
        if ((field000a == 2) && (field000c == 0)) {
          field0148 = field0148 + 10;
          field02c9 = 0x14;
          field016c = 1;
        }
        ++field000c;
        if (field000c >= frameDuration) {
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
      if ((field000a > 0) && (field000a < 2)) {
        field0030 = field0030 - 0.03;
      }
      if ((field000a == 6) && (field000c == 0)) {
        field0148 = field0148 + 0x19;
        field02c9 = 0x14;
      }
      if ((field0028 < 0.0) &&
         (field0038 = field0038 + field0048,
         0.0 < field0038 + field0028)) {
        field0028 = 0.0;
        ResetFrame();
        field000c = 0;
        field000a = 0xb;
      }
      ++field000c;
      if (field000c >= frameDuration) {
        field000c = 0;
        ++field000a;
        if (field000a == 2) {
          field0030 = 1.0;
          field0038 = -0.9;
          field0048 = 0.02;
          field016c = 1;
        }
        if (field000a < 2) {
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
      field0158 = 0;
      if (field0030 < 0.0) {
        field0030 = 0.0;
      }
      if ((field000a == 0) && (field000c == 0)) {
        field0038 = 0.0;
      }
      if ((field000a == 1) && (field000c == 0)) {
        field0148 = field0148 + 5;
        field02c9 = 0x15;
        field016c = 1;
      }
      ++field000c;
      if (field000c >= frameDuration) {
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
    case 234:
      StartTrail(3);
      field0158 = 0;
      if (field0030 < 0.0) {
        field0030 = 0.0;
      }
      if ((field000a == 0) && (field000c == 0)) {
        field0038 = 0.0;
      }
      if ((field000a == 2) && (field000c == 0)) {
        field0148 = field0148 + 5;
        field02c9 = 0x15;
        field016c = 1;
      }
      ++field000c;
      if (field000c >= frameDuration) {
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
      field0030 = field0030 - 0.03;
      if (field0030 < 0.0) {
        field0030 = 0.0;
      }
      if ((field000a == 0) && (field000c == 0)) {
        field0038 = 0.0;
      }
      if ((field000a == 2) && (field000c == 0)) {
        field0148 = field0148 + 5;
        field02c9 = 0x15;
        field016c = 1;
      }
      ++field000c;
      if (field000c >= frameDuration) {
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
    case 248:
      field0038 = field0038 + field0048;
      if ((field000a == 1) && (field0168 == 3)) {
        (*opponentSlot)->ResetFrame();
        (*opponentSlot)->ResetPose();
        (*opponentSlot)->field0128 = 1;
        ResetFrame();
        ResetPose();
        effect.type = 0;
        effect.x = (double)((int(field0020)) + facing * 0x20);
        effect.y = (double)((int(field0028)) + -0x39);
        effect.group = 2;
        effect.layer = 1;
        contextOwner->EmitEffect(&effect);
        field000a = 0;
        field000c = 0;
        field0008 = 0xf9;
        (*opponentSlot)->field0008 = 0x67;
        (*opponentSlot)->field0020 =
             (double)((int)facing << 5) + field0020;
        (*opponentSlot)->field0028 = field0028 - 57.0;
      
        break;
      }

        ++field000c;
        if (field000c >= frameDuration) {
          field000c = 0;
          ++field000a;
          if (field000a == 1 && (*opponentSlot)->field0028 < 0.0 && ((*opponentSlot)->field0008 < 50 || (*opponentSlot)->field0008 > 149)) {
            field016c = 1;
          
      } else {
            field016c = 0;
          
      }
          field0168 = 0;
          if (field000a >= frameCount) {
            field0008 = 0xd1;
            field000a = 2;
          }
        }
      
      break;
    case 249:
      field013e = 2;
      if (((field000a == 2) && (field000c == 0)) &&
         (field3138 == 8)) {
        ApplyDamage(0x44c,500.0);
        (*opponentSlot)->ResetPose();
        (*opponentSlot)->field0008 = 0x56;
        (*opponentSlot)->field00c0 = -1.0;
        (*opponentSlot)->field00c8 = -4.0;
      }
      if (field000a > 3 && (field0038 = field0038 + 0.035, field0028 + field0038 > 0.0)) {
        ResetFrame();
        field0028 = 0.0;
        ResetPose();
        field0008 = 0xd;
      
        break;
      }

        ++field000c;
        if (field000c >= frameDuration) {
          field000c = 0;
          ++field000a;
          field0168 = 0;
          if ((field000a == 3) && (field3138 < 0xf)) {
            field000a = field000a + -2;
            ++field3138;
          }
          if (field000a >= frameCount) {
            field000a = field000a + -2;
          }
        }
      
      break;
    case 250:
      if ((field000a == 0) && (field000c == 0)) {
        field0158 = 0;
        ResetFrame();
        field0148 = field0148 + 0x2d;
        field3138 = 5;
      }
      ++field000c;
      if (field000c >= frameDuration) {
        field000c = 0;
        ++field000a;
        field0168 = 3;
        if (field000a == 4) {
          effect.type = 0x191;
          effect.x = (double)((int(field0020)) + facing * 0x26);
          effect.y = (double)((int(field0028)) + -0x28);
          effect.group = 2;
          effect.layer = 1;
          effect.flag0018 = facing;
          EmitLocalEffect(&effect);
          field02c8 = 5;
        }
        if ((field000a == 7) && (0 < field3138)) {
          field000a = field000a + -2;
          --field3138;
        }
        if (field000a >= frameCount) {
          field0008 = 0;
          ResetPose();
        }
      }
      break;
    case 251:
      if ((field000a == 0) && (field000c == 0)) {
        field0158 = 0;
        ResetFrame();
        field0148 = field0148 + 0x2d;
        field3138 = 3;
      }
      ++field000c;
      if (field000c >= frameDuration) {
        field000c = 0;
        ++field000a;
        field0168 = 3;
        if (field000a == 4) {
          effect.type = 0x191;
          effect.x = (double)((int(field0020)) + facing * 0x26);
          effect.y = (double)((int(field0028)) + -0x28);
          effect.group = 2;
          effect.layer = 1;
          effect.flag0018 = facing;
          EmitLocalEffect(&effect);
          field02c8 = 5;
        }
        if ((field000a == 7) && (0 < field3138)) {
          field000a = field000a + -2;
          --field3138;
        }
        if (field000a >= frameCount) {
          field0008 = 0;
          ResetPose();
        }
      }
      break;
    case 252:
      field0030 = field0030 + field0040;
      field0158 = 0;
      if (field0030 < 0.0) {
        field0030 = 0.0;
      }
      if ((field000a == 0) && (field000c == 0)) {
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
        field0030 = 0.0;
        field0038 = 0.0;
        field0040 = 0.0;
        field0148 = field0148 + 0x2d;
        field3138 = 6;
      }
      if (field313c == 0x14) {
        effect.type = 0x1ab;
        effect.x = (double)((int(field0020)) + facing * 0x2d);
        effect.y = (double)((int(field0028)) + -0x14);
        effect.group = 2;
        effect.layer = 1;
        effect.flag0018 = facing;
        EmitLocalEffect(&effect);
        field02c8 = 5;
      }
      if (field313c == 0x28) {
        effect.type = 0x1ab;
        effect.x = (double)((int(field0020)) + facing * 0x2d);
        effect.y = (double)((int(field0028)) + -0x3c);
        effect.group = 2;
        effect.layer = 1;
        effect.flag0018 = facing;
        EmitLocalEffect(&effect);
        field02c8 = 5;
      }
      if (4 < field000a) {
        ++field313c;
      }
      ++field000c;
      if (field000c >= frameDuration) {
        field000c = 0;
        ++field000a;
        field0168 = 0;
        if (field000a == 5) {
          effect.type = 0x1ab;
          effect.x = (double)((int(field0020)) + facing * 0x26);
          effect.y = (double)((int(field0028)) + -0x28);
          effect.group = 2;
          effect.palette = 1;
          effect.layer = 1;
          effect.flag0018 = facing;
          EmitLocalEffect(&effect);
          field02c8 = 5;
        }
        if ((field000a == 7) && (0 < field3138)) {
          field000a = field000a + -2;
          --field3138;
        }
        if (field000a >= frameCount) {
          field0008 = 0;
          ResetPose();
        }
      }
      break;
    case 253:
      if ((field000a == 0) && (field000c == 0)) {
        field0158 = 0;
        field0030 = 0.0;
        field0038 = 0.0;
        field0040 = 0.0;
        field3138 = 6;
        field016c = 5;
      }
      if ((field000a == 4) && (field000c == 0)) {
        field02c9 = 0x14;
        field0148 += 1;
      }
      if ((field000a == 6) && (field000c == 0)) {
        field02c9 = 0x14;
        field0148 += 1;
      }
      ++field000c;
      if (field000c >= frameDuration) {
        field000c = 0;
        ++field000a;
        if (0 < field016c) {
          field0168 = 0;
        }
        if ((field000a == 7) && (0 < field3138)) {
          field000a = field000a + -4;
          --field3138;
        }
        if (field000a >= frameCount) {
          field0008 = 0;
          ResetPose();
        }
      }
      break;
    case 254:
      if ((field000a == 0) && (field000c == 0)) {
        field0158 = 0;
        field0030 = 0.0;
        field0038 = 0.0;
        field0040 = 0.0;
        field3138 = 8;
        field016c = 9;
      }
      if ((field000a == 4) && (field000c == 0)) {
        field02c9 = 0x14;
        field0148 += 1;
      }
      if ((field000a == 6) && (field000c == 0)) {
        field02c9 = 0x14;
        field0148 += 1;
      }
      ++field000c;
      if (field000c >= frameDuration) {
        field000c = 0;
        ++field000a;
        field0168 = 0;
        if ((field000a == 7) && (0 < field3138)) {
          field000a = field000a + -4;
          --field3138;
        }
        if (field000a >= frameCount) {
          field0008 = 0;
          ResetPose();
        }
      }
      break;
    case 255:
      if ((field000a == 0) && (field000c == 0)) {
        field0158 = 0;
        field0030 = 0.0;
        field0038 = 0.0;
        field0040 = 0.0;
        field016c = 0x12;
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
      if (((field000a == 3) && (field000c == 0)) &&
         (field3138 == 0)) {
        effect.type = 0x1a1;
        effect.flag0018 = facing;
        effect.x = (double)((int(field0020)) + facing * 0x17);
        effect.y = (double)((int(field0028)) + -0x30);
        effect.group = 2;
        effect.layer = 1;
        EmitLocalEffect(&effect);
      }
      if ((field000a == 4) && (field000c == 0)) {
        field02c9 = 0x14;
        field0148 += 1;
      }
      if ((field000a == 6) && (field000c == 0)) {
        field02c9 = 0x14;
        field0148 += 1;
      }
      ++field000c;
      if (field000c >= frameDuration) {
        field000c = 0;
        ++field000a;
        if (0 < field016c) {
          field0168 = 0;
        }
        if ((field000a == 7) && (field3138 < 0xc)) {
          field000a = field000a + -4;
          ++field3138;
        }
        if (field000a >= frameCount) {
          field0008 = 0;
          ResetPose();
        }
      }
      break;
    case 256:
      if ((field000a == 0) && (field000c == 0)) {
        field0030 = field0030 * 0.25;
        field0038 = field0038 * 0.25;
        field0048 = 0.01;
      }
      field0038 = field0038 + field0048;
      ++field000c;
      if (field0038 > 0.2) {
        field0038 = 0.2;
      }
      if ((field0028 == 0.0) &&
         (field0038 >= 0.0)) {
        field0038 = 0.0;
      }
      if (field000c >= frameDuration) {
        field000c = 0;
        ++field000a;
        field0168 = 3;
        if ((field000a == 4) && (field000c == 0)) {
          field0048 = 0.01;
          field02c8 = 1;
          effect.type = 0x192;
          effect.x = (double)((int(field0020)) + facing * 0xe);
          effect.y = (double)(int(field0028));
          effect.flag0018 = facing;
          effect.layer = 1;
          effect.group = 0;
          EmitLocalEffect(&effect);
          effect.type = 0x192;
          effect.x = (double)((int(field0020)) + facing * 0x3c);
          effect.y = (double)((int(field0028)) + -0x10);
          effect.flag0018 = facing;
          effect.layer = 1;
          effect.group = 0;
          EmitLocalEffect(&effect);
        }
        if ((field000a == 7) && (field3138 < 4)) {
          field000a = field000a + -2;
          ++field3138;
        }
        if (field000a >= frameCount) {
          field000a = 0;
          field0008 = 9;
          field0048 = 0.028;
          ResetPose();
        }
      }
      break;
    case 257:
      if ((field000a == 0) && (field000c == 0)) {
        field0030 = field0030 * 0.25;
        field0038 = field0038 * 0.25;
        field0048 = 0.01;
      }
      field0038 = field0038 + field0048;
      ++field000c;
      if (field0038 > 0.2) {
        field0038 = 0.2;
      }
      if ((field0028 == 0.0) &&
         (field0038 >= 0.0)) {
        field0038 = 0.0;
      }
      if (field000c >= frameDuration) {
        field000c = 0;
        ++field000a;
        field0168 = 3;
        if ((field000a == 4) && (field000c == 0)) {
          field0048 = 0.01;
          field02c8 = 1;
          effect.type = 0x192;
          effect.x = (double)((int(field0020)) + facing * 0xe);
          effect.y = (double)(int(field0028));
          effect.flag0018 = facing;
          effect.layer = 1;
          effect.group = 0;
          EmitLocalEffect(&effect);
          effect.type = 0x192;
          effect.x = (double)((int(field0020)) + facing * 0x3c);
          effect.y = (double)((int(field0028)) + -0x10);
          effect.flag0018 = facing;
          effect.layer = 1;
          effect.group = 0;
          EmitLocalEffect(&effect);
        }
        if ((field000a == 7) && (field3138 < 4)) {
          field000a = field000a + -2;
          ++field3138;
        }
        if (field000a >= frameCount) {
          field000a = 0;
          field0008 = 9;
          field0048 = 0.028;
          ResetPose();
        }
      }
      break;
    case 258:
      if ((field000a == 0) && (field000c == 0)) {
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
      if ((field000a == 0) && (field000c == 0)) {
        field0030 = field0030 * 0.25;
        field0038 = field0038 * 0.25;
        field0048 = 0.01;
      }
      field0038 = field0038 + field0048;
      if (field0038 > 0.2) {
        field0038 = 0.2;
      }
      ++field000c;
      if ((field0028 == 0.0) &&
         (field0038 >= 0.0)) {
        field0038 = 0.0;
      }
      if (field000c >= frameDuration) {
        field000c = 0;
        ++field000a;
        field0168 = 3;
        if ((field000a == 4) && (field000c == 0)) {
          field0048 = 0.01;
          field02c8 = 1;
          effect.type = 0x194;
          effect.x = (double)((int(field0020)) + facing * 0xe);
          effect.y = (double)(int(field0028));
          effect.flag0018 = facing;
          effect.layer = 1;
          effect.group = 0;
          EmitLocalEffect(&effect);
          effect.type = 0x194;
          effect.x = (double)((int(field0020)) + facing * 0x3c);
          effect.y = (double)((int(field0028)) + -0x10);
          effect.flag0018 = facing;
          effect.layer = 1;
          effect.group = 0;
          EmitLocalEffect(&effect);
        }
        if ((field000a == 7) && (field3138 < 3)) {
          field000a = field000a + -2;
          ++field3138;
        }
        if (field000a >= frameCount) {
          field000a = 0;
          field0008 = 9;
          field0048 = 0.028;
          ResetPose();
        }
      }
      break;
    case 259:
      if ((field000a == 0) && (field000c == 0)) {
        field0158 = 0;
        ResetFrame();
      }
      ++field000c;
      if (field000c >= frameDuration) {
        field000c = 0;
        ++field000a;
        field0168 = 3;
        if (field000a == 2) {
          effect.type = 0x197;
          effect.x = (double)(int(field0020) - facing * 0x1e);
          effect.y = (double)((int(field0028)) + -0x1e);
          effect.flag0018 = facing;
          effect.layer = 1;
          effect.group = 2;
          EmitLocalEffect(&effect);
        }
        if ((field000a == 7) && (field3138 < 1)) {
          ++field3138;
          field000a = field000a + -4;
          break;
        }
        if (field000a >= frameCount) {
          field0008 = 0;
          FaceOpponent();
          ResetPose();
        }
      }
      break;
    case 260:
      if ((field000a == 0) && (field000c == 0)) {
        field0158 = 0;
        ResetFrame();
      }
      ++field000c;
      if (field000c >= frameDuration) {
        field000c = 0;
        ++field000a;
        field0168 = 3;
        if ((field000a == 2) && (field000c == 0)) {
          effect.type = 0x19a;
          effect.x = (double)(int(field0020) - facing * 0x1e);
          effect.y = (double)((int(field0028)) + -0x1e);
          effect.flag0018 = facing;
          effect.layer = 1;
          effect.group = 2;
          EmitLocalEffect(&effect);
        }
        if ((field000a == 7) && (field3138 < 1)) {
          ++field3138;
          field000a = field000a + -4;
          break;
        }
        if (field000a >= frameCount) {
          field0008 = 0;
          FaceOpponent();
          ResetPose();
        }
      }
      break;
    case 261:
      if ((field000a == 0) && (field000c == 0)) {
        field0158 = 0;
        ResetFrame();
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
      ++field000c;
      if (field000c >= frameDuration) {
        field000c = 0;
        ++field000a;
        field0168 = 3;
        if ((field000a == 2) && (field000c == 0)) {
          effect.type = 0x1c4;
          effect.x = (double)(int(field0020) - facing * 0x1e);
          effect.y = (double)((int(field0028)) + -0x1e);
          effect.flag0018 = facing;
          effect.layer = 1;
          effect.group = 2;
          EmitLocalEffect(&effect);
        }
        if ((field000a == 7) && (field3138 < 3)) {
          ++field3138;
          field000a = field000a + -4;
          break;
        }
        if (field000a >= frameCount) {
          field0008 = 0;
          FaceOpponent();
          ResetPose();
        }
      }
      break;
    case 262:
      if ((field000a == 0) && (field000c == 0)) {
        field0030 = field0030 * 0.5;
        field0038 = field0038 * 0.5;
        field0048 = 0.01;
        field0148 = field0148 + 0x2d;
        field3138 = 4;
      }
      field0038 = field0038 + field0048;
      ++field000c;
      if (field000c >= frameDuration) {
        field000c = 0;
        ++field000a;
        field0168 = 3;
        if (field000a == 4) {
          effect.type = 0x198;
          effect.x = (double)((int(field0020)) + facing * 0x24);
          effect.y = (double)((int(field0028)) + -0x30);
          effect.group = 2;
          effect.layer = 1;
          effect.flag0018 = facing;
          EmitLocalEffect(&effect);
          field02c8 = 5;
        }
        if ((field000a == 7) && (0 < field3138)) {
          field000a = field000a + -2;
          --field3138;
        }
        if (field000a >= frameCount) {
          field0008 = 9;
          ResetPose();
        }
      }
      break;
    case 263:
      if ((field000a == 0) && (field000c == 0)) {
        field0030 = field0030 * 0.5;
        field0038 = field0038 * 0.5;
        field0048 = 0.01;
        field0148 = field0148 + 0x2d;
        field3138 = 3;
      }
      field0038 = field0038 + field0048;
      ++field000c;
      if (field000c >= frameDuration) {
        field000c = 0;
        ++field000a;
        field0168 = 3;
        if (field000a == 4) {
          effect.type = 0x198;
          effect.x = (double)((int(field0020)) + facing * 0x24);
          effect.y = (double)((int(field0028)) + -0x30);
          effect.group = 2;
          effect.layer = 1;
          effect.flag0018 = facing;
          EmitLocalEffect(&effect);
          field02c8 = 5;
        }
        if ((field000a == 7) && (0 < field3138)) {
          field000a = field000a + -2;
          --field3138;
        }
        if (field000a >= frameCount) {
          field0008 = 9;
          ResetPose();
        }
      }
      break;
    case 264:
      if ((field000a == 0) && (field000c == 0)) {
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
        field0148 = field0148 + 0x2d;
        field3138 = 6;
        field0030 = field0030 * 0.5;
        field0038 = field0038 * 0.5;
        field0048 = 0.01;
        field0148 = field0148 + 0x2d;
      }
      field0038 = field0038 + field0048;
      if (field313c == 0x14) {
        effect.type = 0x1ac;
        effect.x = (double)((int(field0020)) + facing * 0x24);
        effect.y = (double)((int(field0028)) + -0x26);
        effect.group = 2;
        effect.layer = 1;
        effect.flag0018 = facing;
        field3140 = 1;
        EmitLocalEffect(&effect);
        field02c8 = 5;
      }
      if (field313c == 0x28) {
        effect.type = 0x1ac;
        effect.x = (double)((int(field0020)) + facing * 0x24);
        effect.y = (double)((int(field0028)) + -0x48);
        effect.group = 2;
        effect.layer = 1;
        effect.flag0018 = facing;
        field3140 = 2;
        EmitLocalEffect(&effect);
        field02c8 = 5;
      }
      if (4 < field000a) {
        ++field313c;
      }
      ++field000c;
      if (field000c >= frameDuration) {
        field000c = 0;
        ++field000a;
        field0168 = 0;
        if (field000a == 5) {
          effect.type = 0x1ac;
          effect.x = (double)((int(field0020)) + facing * 0x1d);
          effect.y = (double)((int(field0028)) + -0x34);
          effect.group = 2;
          effect.palette = 1;
          effect.layer = 1;
          effect.flag0018 = facing;
          EmitLocalEffect(&effect);
          field02c8 = 5;
        }
        if ((field000a == 7) && (0 < field3138)) {
          field000a = field000a + -2;
          --field3138;
        }
        if (field000a >= frameCount) {
          field0008 = 9;
          ResetPose();
        }
      }
      break;
    case 265:
      if ((field000a == 0) && (field000c == 0)) {
        field0158 = 0;
        ResetFrame();
        field3138 = 2;
      }
      if ((field000a == 3) && (field000c == 0)) {
        field02c8 = 6;
        effect.type = 0x1a2;
        effect.x = (double)((int(field0020)) + facing * 100);
        effect.y = (double)((int(field0028)) + -0x1e0);
        effect.flag0018 = facing;
        effect.layer = 1;
        effect.group = 2;
        EmitLocalEffect(&effect);
        effect.x = (double)((int(field0020)) + facing * 0x50);
        effect.y = (double)((int(field0028)) + -0x208);
        EmitLocalEffect(&effect);
        effect.x = (double)((int(field0020)) + facing * 0x82);
        effect.y = (double)((int(field0028)) + -0x212);
        EmitLocalEffect(&effect);
      }
      ++field000c;
      if (field000c >= frameDuration) {
        field000c = 0;
        ++field000a;
        field0168 = 3;
        if (field000a >= frameCount) {
          field0008 = 0;
          ResetPose();
          FaceOpponent();
        }
      }
      break;
    case 266:
      if ((field000a == 0) && (field000c == 0)) {
        field0158 = 0;
        ResetFrame();
        field3138 = 2;
      }
      if ((field000a == 3) && (field000c == 0)) {
        field02c8 = 6;
        effect.type = 0x1a2;
        effect.x = (double)((int(field0020)) + facing * 0xb4);
        effect.y = (double)((int(field0028)) + -0x1e0);
        effect.flag0018 = facing;
        effect.layer = 1;
        effect.group = 2;
        EmitLocalEffect(&effect);
        effect.x = (double)((int(field0020)) + facing * 0xa0);
        effect.y = (double)((int(field0028)) + -0x208);
        EmitLocalEffect(&effect);
        effect.x = (double)((int(field0020)) + facing * 0xd2);
        effect.y = (double)((int(field0028)) + -0x212);
        EmitLocalEffect(&effect);
      }
      ++field000c;
      if (field000c >= frameDuration) {
        field000c = 0;
        ++field000a;
        field0168 = 3;
        if (field000a >= frameCount) {
          field0008 = 0;
          ResetPose();
          FaceOpponent();
        }
      }
      break;
    case 267:
      if ((field000a == 0) && (field000c == 0)) {
        field0158 = 0;
        ResetFrame();
        field3138 = 2;
      }
      if ((field000a == 3) && (field000c == 0)) {
        field02c8 = 6;
        effect.type = 0x1a2;
        effect.x = (double)((int(field0020)) + facing * 0x104);
        effect.y = (double)((int(field0028)) + -0x1e0);
        effect.flag0018 = facing;
        effect.layer = 1;
        effect.group = 2;
        EmitLocalEffect(&effect);
        effect.x = (double)((int(field0020)) + facing * 0xf0);
        effect.y = (double)((int(field0028)) + -0x208);
        EmitLocalEffect(&effect);
        effect.x = (double)((int(field0020)) + facing * 0x122);
        effect.y = (double)((int(field0028)) + -0x212);
        EmitLocalEffect(&effect);
      }
      ++field000c;
      if (field000c >= frameDuration) {
        field000c = 0;
        ++field000a;
        field0168 = 3;
        if (field000a >= frameCount) {
          field0008 = 0;
          ResetPose();
          FaceOpponent();
        }
      }
      break;
    case 268:
      if ((field000a == 0) && (field000c == 0)) {
        field0030 = field0030 * 0.5;
        field0038 = field0038 * 0.5;
        field0048 = 0.01;
        field0148 = field0148 + 0x2d;
        field3138 = 3;
      }
      field0038 = field0038 + field0048;
      ++field000c;
      if (field000c >= frameDuration) {
        field000c = 0;
        ++field000a;
        field0168 = 3;
        if ((field000a == 2) && (field000c == 0)) {
          effect.type = 0x197;
          effect.x = (double)(int(field0020) - facing * 0x1e);
          effect.y = (double)((int(field0028)) + -0x1e);
          effect.flag0018 = facing;
          effect.layer = 1;
          effect.group = 2;
          EmitLocalEffect(&effect);
        }
        if ((field000a == 7) && (field3138 < 3)) {
          ++field3138;
          field000a = field000a + -4;
          break;
        }
        if (field000a >= frameCount) {
          ResetPose();
          field0008 = 9;
          field0048 = 0.035;
        }
      }
      break;
    case 269:
      if ((field000a == 0) && (field000c == 0)) {
        field0030 = field0030 * 0.5;
        field0038 = field0038 * 0.5;
        field0048 = 0.01;
        field0148 = field0148 + 0x2d;
        field3138 = 3;
      }
      field0038 = field0038 + field0048;
      ++field000c;
      if (field000c >= frameDuration) {
        field000c = 0;
        ++field000a;
        field0168 = 3;
        if ((field000a == 2) && (field000c == 0)) {
          effect.type = 0x1c2;
          effect.x = (double)(int(field0020) - facing * 0x1e);
          effect.y = (double)((int(field0028)) + -0x1e);
          effect.flag0018 = facing;
          effect.layer = 1;
          effect.group = 2;
          EmitLocalEffect(&effect);
        }
        if ((field000a == 7) && (field3138 < 3)) {
          ++field3138;
          field000a = field000a + -4;
          break;
        }
        if (field000a >= frameCount) {
          ResetPose();
          field0008 = 9;
          field0048 = 0.035;
        }
      }
      break;
    case 270:
      if ((field000a == 0) && (field000c == 0)) {
        field0030 = field0030 * 0.5;
        field0038 = field0038 * 0.5;
        field0048 = 0.01;
        field0148 = field0148 + 0x2d;
        field3138 = 0;
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
      field0038 = field0038 + field0048;
      ++field000c;
      if (field000c >= frameDuration) {
        field000c = 0;
        ++field000a;
        field0168 = 3;
        if ((field000a == 2) && (field000c == 0)) {
          effect.type = 0x1c4;
          effect.x = (double)(int(field0020) - facing * 0x1e);
          effect.y = (double)((int(field0028)) + -0x1e);
          effect.flag0018 = facing;
          effect.layer = 1;
          effect.group = 2;
          EmitLocalEffect(&effect);
        }
        if ((field000a == 7) && (field3138 < 3)) {
          ++field3138;
          field000a = field000a + -4;
          break;
        }
        if (field000a >= frameCount) {
          ResetPose();
          field0008 = 9;
          field0048 = 0.035;
        }
      }
      break;
    case 300:
      if ((field000a == 0) && (field000c == 0)) {
        field0158 = 0;
        field0030 = 0.0;
        field0038 = 0.0;
        field0048 = 0.0;
      }
      if (1 < field000a) {
        contextOwner->SetSceneTimer(0xf);
      }
      if ((field000a == 2) && (field000c == 0)) {
        field014c = 0x78;
        field0148 = field0148 + -3000;
        SetTint(0xb0,3);
        effect.type = 0x46;
        effect.palette = 0x40;
        effect.x = (double)(int(field0020) - facing * 0x19);
        effect.y = (double)((int(field0028)) + -0x3b);
        effect.group = 2;
        effect.owner = 1;
        effect.layer = 1;
        contextOwner->EmitEffect(&effect);
        field02c9 = 0x25;
        effect.type = 0x47;
        contextOwner->EmitEffect(&effect);
        effect.type = 0x1a3;
        effect.x = (double)(int(field0020));
        effect.y = (double)((int(field0028)) + -0x5f);
        effect.group = 0;
        effect.owner = 1;
        effect.layer = 1;
        effect.flag0018 = facing;
        effect.field0030 = 1;
        EmitLocalEffect(&effect);
      }
      if ((field000a == 10) && (field000c == 0)) {
        effect.owner = 1;
        effect.type = 0x19a;
        effect.x = (double)((int(field0020)) + facing * 0x47);
        effect.y = (double)((int(field0028)) + -0x36);
        effect.flag0018 = facing;
        effect.group = 0;
        effect.layer = 1;
        EmitLocalEffect(&effect);
      }
      ++field000c;
      if (field000c >= frameDuration) {
        field000c = 0;
        ++field000a;
        field0168 = 0;
        if (field000a == 8) {
          field0020 = (double)(facing * 0x35) + field0020
          ;
        }
        if (field000a >= frameCount) {
          field0008 = 0;
          ResetPose();
        }
      }
      break;
    case 303:
      if ((field000a == 0) && (field000c == 0)) {
        field0158 = 0;
        field014c = 0x78;
        field0148 = field0148 + -1000;
        SetTint(0xb0,3);
        effect.type = 0x44;
        effect.palette = 0x13;
        effect.x = (double)(int(field0020));
        effect.y = (double)((int(field0028)) + -0x2a);
        effect.group = 2;
        effect.owner = 1;
        effect.layer = 1;
        contextOwner->EmitEffect(&effect);
        field016c = 5;
        ResetFrame();
      }
      if ((field000a == 2) && (field000c == 0)) {
        effect.owner = 1;
        effect.type = 0x1ad;
        effect.x = (double)(int(field0020) - facing * 0xf);
        effect.y = (double)(int(field0028));
        effect.flag0018 = facing;
        effect.group = 2;
        effect.layer = 1;
        EmitLocalEffect(&effect);
        effect.type = 0x1ae;
        EmitLocalEffect(&effect);
      }
      if ((field000a == 2) && (field000c == 0)) {
        field02c8 = 4;
      }
      if (field000a == 3) {
        if (field000c == 0) field02c8 = 3;
      }
      ++field000c;
      if (field000c >= frameDuration) {
        field000c = 0;
        ++field000a;
        if (((0xf0 < ((unsigned short)RandomRange(0,0x1e0))) || (field000a == 1)) && (0 < field016c))
        {
          field0168 = 0;
        }
        if (field000a >= frameCount) {
          field0008 = 3;
          FaceOpponent();
          ResetPose();
        }
      }
      break;
    case 304:
      if ((field000a == 0) && (field000c == 0)) {
        field0158 = 0;
        field014c = 0x78;
        field0148 = field0148 + -2000;
        SetTint(0xb0,3);
        effect.type = 0x45;
        effect.palette = 5;
        effect.x = (double)(int(field0020));
        effect.y = (double)((int(field0028)) + -0x2a);
        effect.group = 2;
        effect.owner = 1;
        effect.layer = 1;
        contextOwner->EmitEffect(&effect);
        field016c = 0xf;
        ResetFrame();
      }
      if (field3138 == 0) {
        if ((field000a == 2) && (field000c == 0)) {
          field02c8 = 4;
        }
        if ((field000a == 3) && (field000c == 0)) {
          field02c8 = 3;
        }
      }
      if (((1 < field000a) && (field313c <= 0)) && (field3140 < 5)) {
        effect.owner = 1;
        effect.x = (double)(int(field0020) - facing * 0xf);
        effect.y = (double)(int(field0028));
        effect.flag0018 = facing;
        effect.group = 2;
        effect.layer = 1;
        if (field3140 == 0) {
          effect.type = 0x1ae;
          EmitLocalEffect(&effect);
        }
        effect.y = (double)(field3140 * -0x50);
        effect.type = 0x1ad;
        field313c = 0xf;
        ++field3140;
        EmitLocalEffect(&effect);
      }
      --field313c;
      ++field000c;
      if (field000c >= frameDuration) {
        field000c = 0;
        ++field000a;
        if ((field3138 < 1) && (field000a == 10)) {
          field000a = field000a + -6;
          ++field3138;
        }
        if (((0xf0 < ((unsigned short)RandomRange(0,0x1e0))) || (field000a == 1)) && (0 < field016c))
        {
          field0168 = 0;
        }
        if (field000a >= frameCount) {
          field0008 = 3;
          FaceOpponent();
          ResetPose();
        }
      }
      break;
    case 305:
      if ((field000a == 0) && (field000c == 0)) {
        field0158 = 0;
        field014c = 0x78;
        field0148 = field0148 + -3000;
        SetTint(0xb0,3);
        effect.type = 0x46;
        effect.palette = 0x40;
        effect.x = (double)(int(field0020));
        effect.y = (double)((int(field0028)) + -0x2a);
        effect.group = 2;
        effect.owner = 1;
        effect.layer = 1;
        contextOwner->EmitEffect(&effect);
        field016c = 0x1e;
        field02c9 = 0x25;
        ResetFrame();
      }
      contextOwner->SetSceneTimer(0xf);
      if (field3138 == 0) {
        if ((field000a == 2) && (field000c == 0)) {
          field02c8 = 4;
        }
        if ((field000a == 3) && (field000c == 0)) {
          field02c8 = 3;
        }
      }
      if (((1 < field000a) && (field313c <= 0)) && (field3140 < 5)) {
        effect.owner = 1;
        effect.type = 0x1ad;
        effect.x = (double)(int(field0020) - facing * 0xf);
        effect.y = (double)(int(field0028));
        effect.flag0018 = facing;
        effect.group = 2;
        effect.layer = 1;
        if (field3140 == 0) {
          effect.type = 0x1ae;
          EmitLocalEffect(&effect);
          effect.type = 0x1af;
          EmitLocalEffect(&effect);
        }
        effect.y = (double)(field3140 * -0x50);
        effect.type = 0x1ad;
        field313c = 0xf;
        ++field3140;
        EmitLocalEffect(&effect);
      }
      --field313c;
      ++field000c;
      if (field000c >= frameDuration) {
        field000c = 0;
        ++field000a;
        if ((field3138 < 3) && (field000a == 10)) {
          field000a = field000a + -6;
          ++field3138;
        }
        if (((0xf0 < ((unsigned short)RandomRange(0,0x1e0))) || (field000a == 1)) && (0 < field016c))
        {
          field0168 = 0;
        }
        if (field000a >= frameCount) {
          field0008 = 3;
          FaceOpponent();
          ResetPose();
        }
      }
      break;
    case 306:
      if ((field000a == 0) && (field000c == 0)) {
        ResetFrame();
      }
      field0158 = 0;
      if ((field000a == 3) && (field000c == 0)) {
        field014c = 0x78;
        field0148 = field0148 + -1000;
        SetTint(0xb0,3);
        effect.type = 0x44;
        effect.palette = 0x13;
        effect.x = (double)(int(field0020) - facing * 2);
        effect.y = (double)((int(field0028)) + -0x43);
        effect.group = 2;
        effect.owner = 1;
        effect.layer = 1;
        contextOwner->EmitEffect(&effect);
      }
      if (((field000a == 6) && (field000c == 0)) &&
         (field3138 == 0)) {
        effect.owner = 1;
        effect.type = 0x1b5;
        effect.x = (double)((int(field0020)) + facing * 0x32);
        effect.y = 0.0;
        effect.flag0018 = facing;
        effect.group = 2;
        effect.layer = 1;
        EmitLocalEffect(&effect);
        ++field3138;
      }
      ++field000c;
      if (field000c >= frameDuration) {
        field000c = 0;
        ++field000a;
        field0168 = 0;
        if ((field000a == 9) && (field313c < 4)) {
          ++field313c;
          field000a = field000a + -3;
        }
        if (field000a >= frameCount) {
          field0008 = 0;
          FaceOpponent();
          ResetPose();
        }
      }
      break;
    case 307:
      if ((field000a == 0) && (field000c == 0)) {
        ResetFrame();
      }
      field0158 = 0;
      if ((field000a == 3) && (field000c == 0)) {
        field014c = 0x78;
        field0148 = field0148 + -2000;
        SetTint(0xb0,3);
        effect.type = 0x45;
        effect.palette = 5;
        effect.x = (double)(int(field0020) - facing * 2);
        effect.y = (double)((int(field0028)) + -0x43);
        effect.group = 2;
        effect.owner = 1;
        effect.layer = 1;
        contextOwner->EmitEffect(&effect);
      }
      if (((field000a == 6) && (field000c == 0)) &&
         (field313c == 0)) {
        effect.owner = 1;
        effect.type = 0x1b6;
        effect.x = (double)((int(field0020)) + facing * 0x32);
        effect.y = 0.0;
        effect.flag0018 = facing;
        effect.group = 2;
        effect.layer = 1;
        EmitLocalEffect(&effect);
      }
      ++field000c;
      if (field000c >= frameDuration) {
        field000c = 0;
        ++field000a;
        field0168 = 0;
        if ((field000a == 9) && (field313c < 4)) {
          ++field313c;
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
      if ((field000a == 0) && (field000c == 0)) {
        ResetFrame();
      }
      field0158 = 0;
      if ((field000a == 3) && (field000c == 0)) {
        field014c = 0x78;
        field0148 = field0148 + -3000;
        SetTint(0xb0,3);
        effect.type = 0x46;
        effect.palette = 0x40;
        effect.x = (double)(int(field0020) - facing * 2);
        effect.y = (double)((int(field0028)) + -0x43);
        effect.group = 2;
        effect.owner = 1;
        effect.layer = 1;
        contextOwner->EmitEffect(&effect);
        field02c9 = 0x25;
      }
      if (2 < field000a) {
        contextOwner->SetSceneTimer(0xf);
      }
      if (((field000a == 6) && (field000c == 0)) &&
         (field313c == 0)) {
        effect.owner = 1;
        effect.type = 0x1b7;
        effect.x = (double)((int(field0020)) + facing * 0x32);
        effect.y = 0.0;
        effect.flag0018 = facing;
        effect.group = 2;
        effect.layer = 1;
        EmitLocalEffect(&effect);
      }
      ++field000c;
      if (field000c >= frameDuration) {
        field000c = 0;
        ++field000a;
        field0168 = 0;
        if ((field000a == 9) && (field313c < 3)) {
          ++field313c;
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
      if ((field000a == 0) && (field000c == 0)) {
        ResetFrame();
      }
      field0158 = 0;
      if ((field000a == 5) && (field000c == 0)) {
        field314c = 0xe10;
        effect.owner = 1;
        effect.type = 0x1a7;
        effect.x = (double)(int(field0020));
        effect.y = (double)(int(field0028));
        effect.flag0018 = facing;
        effect.group = 2;
        effect.layer = 1;
        EmitLocalEffect(&effect);
      }
      ++field000c;
      if (field000c >= frameDuration) {
        field000c = 0;
        ++field000a;
        field0168 = 0;
        if (field000a >= frameCount) {
          field0008 = 3;
          FaceOpponent();
          ResetPose();
        }
      }
      break;
    case 310:
      if ((field000a == 0) && (field000c == 0)) {
        ResetFrame();
      }
      field0158 = 0;
      if ((field000a == 4) && (field000c == 0)) {
        field014c = 0x78;
        field0148 = field0148 + -2000;
        SetTint(0xb0,3);
        effect.type = 9;
        effect.palette = 5;
        effect.x = (double)((int(field0020)) + facing * 0x17);
        effect.y = (double)((int(field0028)) + -0x1e);
        effect.group = 2;
        effect.owner = 1;
        effect.layer = 1;
        contextOwner->EmitEffect(&effect);
      }
      if ((field000a == 5) && (field000c == 0)) {
        field314c = 0x12c0;
        effect.owner = 1;
        effect.type = 0x1a8;
        effect.x = (double)(int(field0020));
        effect.y = (double)(int(field0028));
        effect.flag0018 = facing;
        effect.group = 2;
        effect.layer = 1;
        EmitLocalEffect(&effect);
      }
      ++field000c;
      if (field000c >= frameDuration) {
        field000c = 0;
        ++field000a;
        field0168 = 0;
        if (field000a >= frameCount) {
          field0008 = 3;
          FaceOpponent();
          ResetPose();
        }
      }
      break;
    case 311:
      if ((field000a == 0) && (field000c == 0)) {
        ResetFrame();
      }
      field0158 = 0;
      if ((field000a == 4) && (field000c == 0)) {
        field014c = 0x78;
        field0148 = field0148 + -3000;
        SetTint(0xb0,3);
        effect.type = 9;
        effect.palette = 5;
        effect.x = (double)((int(field0020)) + facing * 0x17);
        effect.y = (double)((int(field0028)) + -0x1e);
        effect.group = 2;
        effect.owner = 1;
        effect.layer = 1;
        contextOwner->EmitEffect(&effect);
        field02c9 = 0x25;
      }
      if (3 < field000a) {
        contextOwner->SetSceneTimer(0xf);
      }
      if ((field000a == 5) && (field000c == 0)) {
        field314c = 0x12c0;
        effect.owner = 1;
        effect.type = 0x1a9;
        effect.x = (double)(int(field0020));
        effect.y = (double)(int(field0028));
        effect.flag0018 = facing;
        effect.group = 2;
        effect.layer = 1;
        EmitLocalEffect(&effect);
      }
      ++field000c;
      if (field000c >= frameDuration) {
        field000c = 0;
        ++field000a;
        field0168 = 0;
        if (field000a >= frameCount) {
          field0008 = 3;
          FaceOpponent();
          ResetPose();
        }
      }
      break;
    case 312:
      if ((field000a == 0) && (field000c == 0)) {
        field0030 = field0030 * 0.5;
        field0038 = field0038 * 0.5;
        field0048 = 0.01;
      }
      if (field000a != 1) {
        field0038 = field0038 + field0048;
      }
      if ((field000a < 8) && (field0038 > 0.2)) {
        field0038 = 0.2;
      }
      if ((field000a == 1) && (field000c == 0)) {
        field313c = (int(field0030 * 100.0));
        field0030 = 0.0;
        field3140 = (int(field0038 * 100.0));
        field0038 = 0.0;
        field014c = 0x78;
        field0148 = field0148 + -1000;
        SetTint(0xb0,3);
        effect.type = 0x44;
        effect.palette = 0x13;
        effect.x = (double)(int(field0020));
        effect.y = (double)((int(field0028)) + -0x2a);
        effect.group = 2;
        effect.owner = 1;
        effect.layer = 1;
        contextOwner->EmitEffect(&effect);
        ResetFrame();
      }
      if ((field000a == 2) && (field000c == 0)) {
        field0030 = (double)field313c * 0.01;
        field0038 = (double)field3140 * 0.01;
        field3138 = 0;
        field313c = 0;
        field3140 = 0;
      }
      if ((((4 < field000a) && (field000a < 8)) &&
          (field3138 <= 0)) && (field3140 < 0xf)) {
        effect.owner = 0;
        effect.type = 0x1b3;
        effect.x = (double)(int)(((int(field0020)) + (char)(facing) * 0x1e) -
                                (char)(facing) * 0x30 * (((unsigned short)RandomRange(0,2)) == 0));
        effect.y = (double)(int)((int(field0028)) + -0x20 + ((unsigned short)RandomRange(0,5)));
        effect.flag0018 = facing;
        effect.group = 0;
        effect.layer = 1;
        EmitLocalEffect(&effect);
        effect.type = 0x1b4;
        effect.flag0018 = facing;
        effect.group = 2;
        EmitLocalEffect(&effect);
        field3138 = 6;
        ++field3140;
      }
      if ((field000a == 8) && (field000c == 0)) {
        field0048 = 0.035;
      }
      if (field000a > 7 && field0028 + field0038 > 0.0) {
        ResetPose();
        field0008 = 0xd;
      
        break;
      }

        --field3138;
        ++field000c;
        if (field000c >= frameDuration) {
          field000c = 0;
          ++field000a;
          if ((field000a == 8) && (field313c < 5)) {
            ++field313c;
            field000a = field000a + -4;
          }
          if (field000a >= frameCount) {
            field000a = field000a + -2;
          }
        }
      
      break;
    case 313:
      if ((field000a == 0) && (field000c == 0)) {
        field0030 = field0030 * 0.5;
        field0038 = field0038 * 0.5;
        field0048 = 0.01;
      }
      if (field000a != 1) {
        field0038 = field0038 + field0048;
      }
      if ((field000a < 8) && (field0038 > 0.2)) {
        field0038 = 0.2;
      }
      if ((field000a == 1) && (field000c == 0)) {
        field313c = (int(field0030 * 100.0));
        field0030 = 0.0;
        field3140 = (int(field0038 * 100.0));
        field0038 = 0.0;
        field014c = 0x78;
        field0148 = field0148 + -2000;
        SetTint(0xb0,3);
        effect.type = 0x45;
        effect.palette = 5;
        effect.x = (double)(int(field0020));
        effect.y = (double)((int(field0028)) + -0x2a);
        effect.group = 2;
        effect.owner = 1;
        effect.layer = 1;
        contextOwner->EmitEffect(&effect);
        ResetFrame();
      }
      if ((field000a == 2) && (field000c == 0)) {
        field0030 = (double)field313c * 0.01;
        field0038 = (double)field3140 * 0.01;
        field3138 = 0;
        field313c = 0;
        field3140 = 0;
      }
      if ((((4 < field000a) && (field000a < 8)) &&
          (field3138 <= 0)) && (field3140 < 0x1b)) {
        effect.owner = 0;
        effect.type = 0x1b3;
        effect.x = (double)(int)(((int(field0020)) + (char)(facing) * 0x1e) -
                                (char)(facing) * 0x30 * (((unsigned short)RandomRange(0,2)) == 0));
        effect.y = (double)(int)((int(field0028)) + -0x20 + ((unsigned short)RandomRange(0,5)));
        effect.flag0018 = facing;
        effect.group = 0;
        effect.layer = 1;
        EmitLocalEffect(&effect);
        effect.type = 0x1b4;
        effect.flag0018 = facing;
        effect.group = 2;
        EmitLocalEffect(&effect);
        field3138 = 6;
        ++field3140;
      }
      if ((field000a == 8) && (field000c == 0)) {
        field0048 = 0.035;
      }
      if (field000a > 7 && field0028 + field0038 > 0.0) {
        ResetPose();
        field0008 = 0xd;
      
        break;
      }

        --field3138;
        ++field000c;
        if (field000c >= frameDuration) {
          field000c = 0;
          ++field000a;
          if ((field000a == 8) && (field313c < 8)) {
            ++field313c;
            field000a = field000a + -4;
          }
          if (field000a >= frameCount) {
            field000a = field000a + -2;
          }
        }
      
      break;
    case 314:
      if ((field000a == 0) && (field000c == 0)) {
        field0030 = field0030 * 0.5;
        field0038 = field0038 * 0.5;
        field0048 = 0.01;
      }
      if ((field000a == 1) && (field000c == 0)) {
        field313c = (int(field0030 * 100.0));
        field0030 = 0.0;
        field3140 = (int(field0038 * 100.0));
        field0038 = 0.0;
        field014c = 0x78;
        field0148 = field0148 + -3000;
        SetTint(0xb0,3);
        effect.type = 0x46;
        effect.palette = 0x40;
        effect.x = (double)(int(field0020));
        effect.y = (double)((int(field0028)) + -0x2a);
        effect.group = 2;
        effect.owner = 1;
        effect.layer = 1;
        contextOwner->EmitEffect(&effect);
        ResetFrame();
        field02c9 = 0x25;
      }
      if (field000a > 0) {
        contextOwner->SetSceneTimer(0xf);
      }
      if (field000a != 1) {
        field0038 = field0038 + field0048;
      }
      if ((field000a < 8) && (field0038 > 0.2)) {
        field0038 = 0.2;
      }
      if ((field000a == 2) && (field000c == 0)) {
        field0030 = (double)field313c * 0.01;
        field0038 = (double)field3140 * 0.01;
        field3138 = 0;
        field313c = 0;
        field3140 = 0;
      }
      if ((((4 < field000a) && (field000a < 8)) &&
          (field3138 <= 0)) && (field3140 < 0x32)) {
        effect.owner = 0;
        effect.type = 0x1b3;
        effect.x = (double)(int)(((int(field0020)) + (char)(facing) * 0x1e) -
                                (char)(facing) * 0x30 * (((unsigned short)RandomRange(0,2)) == 0));
        effect.y = (double)(int)((int(field0028)) + -0x20 + ((unsigned short)RandomRange(0,5)));
        effect.flag0018 = facing;
        effect.group = 0;
        effect.layer = 1;
        EmitLocalEffect(&effect);
        effect.type = 0x1b4;
        effect.flag0018 = facing;
        effect.group = 2;
        EmitLocalEffect(&effect);
        field3138 = 6;
        ++field3140;
      }
      if ((field000a == 8) && (field000c == 0)) {
        field0048 = 0.035;
      }
      if (field000a > 7 && field0028 + field0038 > 0.0) {
        ResetPose();
        field0008 = 0xd;
      
        break;
      }

        --field3138;
        ++field000c;
        if (field000c >= frameDuration) {
          field000c = 0;
          ++field000a;
          if ((field000a == 8) && (field313c < 0xd)) {
            ++field313c;
            field000a = field000a + -4;
          }
          if (field000a >= frameCount) {
            field000a = field000a + -2;
          }
        }
      
      break;
    case 315:
      if ((field000a == 1) && (field000c == 0)) {
        field0158 = 0;
        field014c = 0x78;
        field0148 = field0148 + -1000;
        SetTint(0xb0,3);
        effect.type = 0x44;
        effect.palette = 0x13;
        effect.x = (double)(int(field0020));
        effect.y = (double)((int(field0028)) + -0x2a);
        effect.group = 2;
        effect.owner = 1;
        effect.layer = 1;
        contextOwner->EmitEffect(&effect);
        ResetFrame();
      }
      if ((((4 < field000a) && (field000a < 8)) &&
          (field3138 <= 0)) && (field3140 < 0xf)) {
        effect.owner = 0;
        effect.type = 0x1b3;
        effect.x = (double)(int)(((int(field0020)) + (char)(facing) * 0x11) -
                                (char)(facing) * 0x30 * (((unsigned short)RandomRange(0,2)) == 0));
        effect.y = (double)((int(field0028)) + -0x16);
        effect.flag0018 = facing;
        effect.group = 0;
        effect.layer = 1;
        EmitLocalEffect(&effect);
        effect.type = 0x1b4;
        effect.flag0018 = facing;
        effect.group = 2;
        EmitLocalEffect(&effect);
        field3138 = 6;
        ++field3140;
      }
      --field3138;
      ++field000c;
      if (field000c >= frameDuration) {
        field000c = 0;
        ++field000a;
        if ((field000a == 8) && (field313c < 5)) {
          ++field313c;
          field000a = field000a + -4;
        }
        if (field000a >= frameCount) {
          field0008 = 0;
          FaceOpponent();
          ResetPose();
        }
      }
      break;
    case 316:
      if ((field000a == 1) && (field000c == 0)) {
        field0158 = 0;
        field014c = 0x78;
        field0148 = field0148 + -2000;
        SetTint(0xb0,3);
        effect.type = 0x45;
        effect.palette = 5;
        effect.x = (double)(int(field0020));
        effect.y = (double)((int(field0028)) + -0x2a);
        effect.group = 2;
        effect.owner = 1;
        effect.layer = 1;
        contextOwner->EmitEffect(&effect);
        ResetFrame();
      }
      if ((((4 < field000a) && (field000a < 8)) &&
          (field3138 <= 0)) && (field3140 < 0x1b)) {
        effect.owner = 0;
        effect.type = 0x1b3;
        effect.x = (double)(int)(((int(field0020)) + (char)(facing) * 0x11) -
                                (char)(facing) * 0x30 * (((unsigned short)RandomRange(0,2)) == 0));
        effect.y = (double)((int(field0028)) + -0x16);
        effect.flag0018 = facing;
        effect.group = 0;
        effect.layer = 1;
        EmitLocalEffect(&effect);
        effect.type = 0x1b4;
        effect.flag0018 = facing;
        effect.group = 2;
        EmitLocalEffect(&effect);
        field3138 = 6;
        ++field3140;
      }
      --field3138;
      ++field000c;
      if (field000c >= frameDuration) {
        field000c = 0;
        ++field000a;
        if ((field000a == 8) && (field313c < 8)) {
          ++field313c;
          field000a = field000a + -4;
        }
        if (field000a >= frameCount) {
          field0008 = 0;
          FaceOpponent();
          ResetPose();
        }
      }
      break;
    case 317:
      if ((field000a == 1) && (field000c == 0)) {
        field0158 = 0;
        field014c = 0x78;
        field0148 = field0148 + -3000;
        SetTint(0xb0,3);
        effect.type = 0x46;
        effect.palette = 0x40;
        effect.x = (double)(int(field0020));
        effect.y = (double)((int(field0028)) + -0x2a);
        effect.group = 2;
        effect.owner = 1;
        effect.layer = 1;
        contextOwner->EmitEffect(&effect);
        ResetFrame();
        field02c9 = 0x25;
      }
      if (field000a > 0) {
        contextOwner->SetSceneTimer(0xf);
      }
      if ((((4 < field000a) && (field000a < 8)) &&
          (field3138 <= 0)) && (field3140 < 0x32)) {
        effect.owner = 0;
        effect.type = 0x1b3;
        effect.x = (double)(int)(((int(field0020)) + (char)(facing) * 0x11) -
                                (char)(facing) * 0x30 * (((unsigned short)RandomRange(0,2)) == 0));
        effect.y = (double)((int(field0028)) + -0x16);
        effect.flag0018 = facing;
        effect.group = 0;
        effect.layer = 1;
        EmitLocalEffect(&effect);
        effect.type = 0x1b4;
        effect.flag0018 = facing;
        effect.group = 2;
        EmitLocalEffect(&effect);
        field3138 = 6;
        ++field3140;
      }
      --field3138;
      ++field000c;
      if (field000c >= frameDuration) {
        field000c = 0;
        ++field000a;
        if ((field000a == 8) && (field313c < 0xd)) {
          ++field313c;
          field000a = field000a + -4;
        }
        if (field000a >= frameCount) {
          field0008 = 0;
          FaceOpponent();
          ResetPose();
        }
      }
      break;
    case 318:
      if ((field000a == 0) && (field000c == 0)) {
        field0158 = 0;
        field0030 = 0.0;
        field0038 = 0.0;
        field0048 = 0.0;
      }
      if ((field000a == 3) && (field000c == 0)) {
        effect.type = 0x1a3;
        effect.x = (double)((int(field0020)) + facing * 6);
        effect.y = (double)((int(field0028)) + -0x34);
        effect.group = 0;
        effect.owner = 1;
        effect.layer = 1;
        effect.flag0018 = -facing;
        effect.field0030 = 1;
        EmitLocalEffect(&effect);
      }
      if (2 < field000a) {
        contextOwner->SetSceneTimer(3);
        SetTint(0xb0,6);
      }
      if ((field000a == 4) && (field000c == 0)) {
        field014c = 0x78;
        field0148 = field0148 + -3000;
        SetTint(0xb0,3);
        effect.type = 0x46;
        effect.palette = 0x40;
        effect.x = (double)((int(field0020)) + facing * 0x1c);
        effect.y = (double)((int(field0028)) + -0x33);
        effect.group = 2;
        effect.owner = 1;
        effect.layer = 1;
        contextOwner->EmitEffect(&effect);
        field02c9 = 0x25;
        effect.type = 0x47;
        contextOwner->EmitEffect(&effect);
      }
      if ((field000a == 0xb) && (field000c == 0)) {
        effect.owner = 1;
        effect.type = 0x1b8;
        effect.x = (double)((int(field0020)) + facing * 0x14);
        effect.y = (double)((int(field0028)) + -0x34);
        effect.flag0018 = facing;
        effect.group = 2;
        effect.layer = 1;
        EmitLocalEffect(&effect);
      }
      ++field000c;
      if (field000c >= frameDuration) {
        field000c = 0;
        ++field000a;
        field0168 = 0;
        if (field000a >= frameCount) {
          field0008 = 0;
          ResetPose();
        }
      }
      break;
    case 319:
      field013e = 3;
      if (field000a < 2) {
        SetTint(0xb0,3);
      }
      if ((field000a == 0) && (field000c == 0)) {
        field0158 = 0;
        field0030 = 0.0;
        field0038 = 0.0;
        field0048 = 0.0;
        field016c = 2;
      }
      if ((field000a == 1) && (field000c == 0)) {
        field0020 = (*opponentSlot)->field0020;
        field0038 = -6.5;
      }
      if ((field000a == 1) && (field0168 == 3)) {
        SetVerticalShake(5,0);
        (*opponentSlot)->field0020 =
             (double)(int)facing + field0020;
        ResetFrame();
        field000c = 0;
        field000a = 2;
        (*opponentSlot)->field000a = 0;
        (*opponentSlot)->field000c = 0;
        (*opponentSlot)->field0008 = 0x79;
        effect.owner = 1;
        effect.type = 0x1bd;
        effect.x = (*opponentSlot)->field0020;
        effect.y = (*opponentSlot)->field0028;
        effect.flag0018 = facing;
        effect.group = 0;
        effect.layer = 0;
        EmitLocalEffect(&effect);
      }
      if (field000a == 2) {
        --field3138;
        ++field313c;
        if (field3138 <= 0) {
          field3138 = 0x18;
          field0028 = field0028 - 1.0;
          (*opponentSlot)->field0028 =
               (*opponentSlot)->field0028 - 1.0;
        }
        if (field313c == 0x168) {
          field000c = 0;
          field000a = 3;
          field0168 = 0;
          field0038 = -3.5;
        }
      }
      if ((field000a == 3) && (field0038 > 0.0)) {
        field000c = 0;
        field000a = 4;
        contextOwner->RequestTransition('\x03');
      }
      if (field000a >= 3) {
        (*opponentSlot)->SetHorizontalShake(0x32,3);
        if ((*opponentSlot)->field0008 == 99) {
          (*opponentSlot)->field000c = 0;
        }
        field0038 = field0038 + 0.035;
        if (0.0 < field0028 + field0038) {
          ResetFrame();
          field0028 = 0.0;
          ResetPose();
          field0008 = 0xd;
          return;
        }
      }
      ++field000c;
      if (field000c >= frameDuration) {
        field000c = 0;
        ++field000a;
        field0168 = 0;
        if (field000a >= frameCount) {
          field000a = field000a + -2;
        }
      }
      break;
  }
}
