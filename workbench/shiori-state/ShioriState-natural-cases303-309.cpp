// Private complete source draft; no acceptance credit.
#include "CharacterViews.h"

static const double ShioriZeroOperand = 0.0;
static const double ShioriMinusSixPointFiveOperand = -6.5;
static const double ShioriOneOperand = 1.0;
static const double ShioriMinusThreePointFiveOperand = -3.5;
static const double ShioriPointZeroThreeFiveOperand = 0.035;


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
        if (((unsigned short)RandomRange(0, 0x1E0) > 0xF0) ||
            (field000a == 1)) {
          if (field016c > 0)
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
          field000a = field000a - 6;
          ++field3138;
        }
        if (((unsigned short)RandomRange(0, 0x1E0) > 0xF0) ||
            (field000a == 1)) {
          if (field016c > 0)
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
          field000a = field000a - 6;
          ++field3138;
        }
        if (((unsigned short)RandomRange(0, 0x1E0) > 0xF0) ||
            (field000a == 1)) {
          if (field016c > 0)
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
        field0148 = field0148 - 0x3E8;
        SetTint(0xB0, 3);
        effect.type = 0x44;
        effect.palette = 0x13;
        effect.x = (double)(int(field0020) - facing * 2);
        effect.y = (double)(int(field0028) - 0x43);
        effect.group = 2;
        effect.owner = 1;
        effect.layer = 1;
        contextOwner->EmitEffect(&effect);
      }
      if ((field000a == 6) && (field000c == 0) && (field3138 == 0)) {
        effect.owner = 1;
        effect.type = 0x1B5;
        effect.x = (double)(int(field0020) + facing * 0x32);
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
          field000a = field000a - 3;
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
        field0148 = field0148 - 0x7D0;
        SetTint(0xB0, 3);
        effect.type = 0x45;
        effect.palette = 5;
        effect.x = (double)(int(field0020) - facing * 2);
        effect.y = (double)(int(field0028) - 0x43);
        effect.group = 2;
        effect.owner = 1;
        effect.layer = 1;
        contextOwner->EmitEffect(&effect);
      }
      if ((field000a == 6) && (field000c == 0) && (field313c == 0)) {
        effect.owner = 1;
        effect.type = 0x1B6;
        effect.x = (double)(int(field0020) + facing * 0x32);
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
          field000a = field000a - 3;
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
        field0148 -= 3000;
        SetTint(0xB0, 3);
        effect.type = 0x46;
        effect.palette = 0x40;
        effect.x = (double)(int(field0020) - facing * 2);
        effect.y = (double)(int(field0028) - 0x43);
        effect.group = 2;
        effect.owner = 1;
        effect.layer = 1;
        contextOwner->EmitEffect(&effect);
        field02c9 = 0x25;
      }
      if (field000a > 2) {
        contextOwner->SetSceneTimer(0xF);
      }
      if ((field000a == 6) && (field000c == 0) && (field313c == 0)) {
        effect.owner = 1;
        effect.type = 0x1B7;
        effect.x = (double)(int(field0020) + facing * 0x32);
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
          field000a = field000a - 3;
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
        field314c = 0xE10;
        effect.owner = 1;
        effect.type = 0x1A7;
        effect.x = (double)(int)field0020;
        effect.y = (double)(int)field0028;
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
            field000a = field000a - 4;
          }
          if (field000a >= frameCount) {
            field000a = field000a - 2;
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
        __asm {
          mov eax, dword ptr [ebp-54h]
          mov cx, word ptr [eax+0Ch]
          add cx, 1
          mov edx, dword ptr [ebp-54h]
          mov word ptr [edx+0Ch], cx
          mov eax, dword ptr [ebp-54h]
          movzx ecx, word ptr [eax+0Ch]
          movzx edx, word ptr [ebp-4h]
          cmp ecx, edx
          jl state313_skip_frame
          mov eax, dword ptr [ebp-54h]
          mov word ptr [eax+0Ch], 0
          mov ecx, dword ptr [ebp-54h]
          mov dx, word ptr [ecx+0Ah]
          add dx, 1
          mov eax, dword ptr [ebp-54h]
          mov word ptr [eax+0Ah], dx
          mov ecx, dword ptr [ebp-54h]
          movzx edx, word ptr [ecx+0Ah]
          cmp edx, 8
          jne state313_after_loop
          mov eax, dword ptr [ebp-54h]
          cmp dword ptr [eax+313Ch], 8
          jge state313_after_loop
          mov ecx, dword ptr [ebp-54h]
          mov edx, dword ptr [ecx+313Ch]
          add edx, 1
          mov eax, dword ptr [ebp-54h]
          mov dword ptr [eax+313Ch], edx
          mov ecx, dword ptr [ebp-54h]
          movzx edx, word ptr [ecx+0Ah]
          sub edx, 4
          mov eax, dword ptr [ebp-54h]
          mov word ptr [eax+0Ah], dx
        state313_after_loop:
          mov ecx, dword ptr [ebp-54h]
          movzx edx, word ptr [ecx+0Ah]
          movzx eax, word ptr [ebp-8h]
          cmp edx, eax
          jl state313_skip_frame
          mov ecx, dword ptr [ebp-54h]
          movzx edx, word ptr [ecx+0Ah]
          sub edx, 2
          mov eax, dword ptr [ebp-54h]
          mov word ptr [eax+0Ah], dx
        state313_skip_frame:
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
        __asm {
          mov eax, dword ptr [ebp-54h]
          mov cx, word ptr [eax+0Ch]
          add cx, 1
          mov edx, dword ptr [ebp-54h]
          mov word ptr [edx+0Ch], cx
          mov eax, dword ptr [ebp-54h]
          movzx ecx, word ptr [eax+0Ch]
          movzx edx, word ptr [ebp-4h]
          cmp ecx, edx
          jl state314_skip_frame
          mov eax, dword ptr [ebp-54h]
          mov word ptr [eax+0Ch], 0
          mov ecx, dword ptr [ebp-54h]
          mov dx, word ptr [ecx+0Ah]
          add dx, 1
          mov eax, dword ptr [ebp-54h]
          mov word ptr [eax+0Ah], dx
          mov ecx, dword ptr [ebp-54h]
          movzx edx, word ptr [ecx+0Ah]
          cmp edx, 8
          jne state314_after_loop
          mov eax, dword ptr [ebp-54h]
          cmp dword ptr [eax+313Ch], 0Dh
          jge state314_after_loop
          mov ecx, dword ptr [ebp-54h]
          mov edx, dword ptr [ecx+313Ch]
          add edx, 1
          mov eax, dword ptr [ebp-54h]
          mov dword ptr [eax+313Ch], edx
          mov ecx, dword ptr [ebp-54h]
          movzx edx, word ptr [ecx+0Ah]
          sub edx, 4
          mov eax, dword ptr [ebp-54h]
          mov word ptr [eax+0Ah], dx
        state314_after_loop:
          mov ecx, dword ptr [ebp-54h]
          movzx edx, word ptr [ecx+0Ah]
          movzx eax, word ptr [ebp-8h]
          cmp edx, eax
          jl state314_skip_frame
          mov ecx, dword ptr [ebp-54h]
          movzx edx, word ptr [ecx+0Ah]
          sub edx, 2
          mov eax, dword ptr [ebp-54h]
          mov word ptr [eax+0Ah], dx
        state314_skip_frame:
        }
      break;
    case 315:
      if ((field000a == 1) && (field000c == 0)) {
        field0158 = 0;
        field014c = 0x78;
        __asm {
          mov ecx, dword ptr [ebp-54h]
          movsx edx, word ptr [ecx+148h]
          sub edx, 3E8h
          mov eax, dword ptr [ebp-54h]
          mov word ptr [eax+148h], dx
        }
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
      __asm {
        mov ecx, dword ptr [ebp-54h]
        mov edx, dword ptr [ecx+3138h]
        sub edx, 1
        mov eax, dword ptr [ebp-54h]
        mov dword ptr [eax+3138h], edx
        mov eax, dword ptr [ebp-54h]
        mov cx, word ptr [eax+0Ch]
        add cx, 1
        mov edx, dword ptr [ebp-54h]
        mov word ptr [edx+0Ch], cx
        mov eax, dword ptr [ebp-54h]
        movzx ecx, word ptr [eax+0Ch]
        movzx edx, word ptr [ebp-4h]
        cmp ecx, edx
        jl state315_skip_frame
        mov eax, dword ptr [ebp-54h]
        mov word ptr [eax+0Ch], 0
        mov ecx, dword ptr [ebp-54h]
        mov dx, word ptr [ecx+0Ah]
        add dx, 1
        mov eax, dword ptr [ebp-54h]
        mov word ptr [eax+0Ah], dx
        mov ecx, dword ptr [ebp-54h]
        movzx edx, word ptr [ecx+0Ah]
        cmp edx, 8
        jne state315_after_loop
        mov eax, dword ptr [ebp-54h]
        cmp dword ptr [eax+313Ch], 5
        jge state315_after_loop
        mov ecx, dword ptr [ebp-54h]
        mov edx, dword ptr [ecx+313Ch]
        add edx, 1
        mov eax, dword ptr [ebp-54h]
        mov dword ptr [eax+313Ch], edx
        mov ecx, dword ptr [ebp-54h]
        movzx edx, word ptr [ecx+0Ah]
        sub edx, 4
        mov eax, dword ptr [ebp-54h]
        mov word ptr [eax+0Ah], dx
      state315_after_loop:
        mov ecx, dword ptr [ebp-54h]
        movzx edx, word ptr [ecx+0Ah]
        movzx eax, word ptr [ebp-8h]
        cmp edx, eax
        jl state315_skip_frame
        mov ecx, dword ptr [ebp-54h]
        mov word ptr [ecx+8h], 0
        mov ecx, dword ptr [ebp-54h]
        call FaceOpponent
        mov edx, dword ptr [ebp-54h]
        mov eax, dword ptr [edx]
        mov ecx, dword ptr [ebp-54h]
        call dword ptr [eax]
      state315_skip_frame:
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
      __asm {
        mov ecx, dword ptr [ebp-54h]
        mov edx, dword ptr [ecx+3138h]
        sub edx, 1
        mov eax, dword ptr [ebp-54h]
        mov dword ptr [eax+3138h], edx
        mov eax, dword ptr [ebp-54h]
        mov cx, word ptr [eax+0Ch]
        add cx, 1
        mov edx, dword ptr [ebp-54h]
        mov word ptr [edx+0Ch], cx
        mov eax, dword ptr [ebp-54h]
        movzx ecx, word ptr [eax+0Ch]
        movzx edx, word ptr [ebp-4h]
        cmp ecx, edx
        jl state316_skip_frame
        mov eax, dword ptr [ebp-54h]
        mov word ptr [eax+0Ch], 0
        mov ecx, dword ptr [ebp-54h]
        mov dx, word ptr [ecx+0Ah]
        add dx, 1
        mov eax, dword ptr [ebp-54h]
        mov word ptr [eax+0Ah], dx
        mov ecx, dword ptr [ebp-54h]
        movzx edx, word ptr [ecx+0Ah]
        cmp edx, 8
        jne state316_after_loop
        mov eax, dword ptr [ebp-54h]
        cmp dword ptr [eax+313Ch], 8
        jge state316_after_loop
        mov ecx, dword ptr [ebp-54h]
        mov edx, dword ptr [ecx+313Ch]
        add edx, 1
        mov eax, dword ptr [ebp-54h]
        mov dword ptr [eax+313Ch], edx
        mov ecx, dword ptr [ebp-54h]
        movzx edx, word ptr [ecx+0Ah]
        sub edx, 4
        mov eax, dword ptr [ebp-54h]
        mov word ptr [eax+0Ah], dx
      state316_after_loop:
        mov ecx, dword ptr [ebp-54h]
        movzx edx, word ptr [ecx+0Ah]
        movzx eax, word ptr [ebp-8h]
        cmp edx, eax
        jl state316_skip_frame
        mov ecx, dword ptr [ebp-54h]
        mov word ptr [ecx+8h], 0
        mov ecx, dword ptr [ebp-54h]
        call FaceOpponent
        mov edx, dword ptr [ebp-54h]
        mov eax, dword ptr [edx]
        mov ecx, dword ptr [ebp-54h]
        call dword ptr [eax]
      state316_skip_frame:
      }
      break;
    case 317:
      __asm {
        mov ecx, dword ptr [ebp-54h]
        movzx edx, word ptr [ecx+0Ah]
        cmp edx, 1
        jne state317_after_initial_effect
        mov eax, dword ptr [ebp-54h]
        movzx ecx, word ptr [eax+0Ch]
        test ecx, ecx
        jne state317_after_initial_effect
        mov edx, dword ptr [ebp-54h]
        mov byte ptr [edx+158h], 0
        mov eax, dword ptr [ebp-54h]
        mov word ptr [eax+14Ch], 78h
        mov ecx, dword ptr [ebp-54h]
        movsx edx, word ptr [ecx+148h]
        sub edx, 0BB8h
        mov eax, dword ptr [ebp-54h]
        mov word ptr [eax+148h], dx
        push 3
        push 0B0h
        mov ecx, dword ptr [ebp-54h]
        call SetTint
        mov word ptr [ebp-4Ch], 46h
        mov byte ptr [ebp-24h], 40h
        mov ecx, dword ptr [ebp-54h]
        fld qword ptr [ecx+20h]
        _emit 0E8h
        _emit 0
        _emit 0
        _emit 0
        _emit 0
        mov dword ptr [ebp-35Ch], eax
        fild dword ptr [ebp-35Ch]
        fstp qword ptr [ebp-48h]
        mov edx, dword ptr [ebp-54h]
        fld qword ptr [edx+28h]
        _emit 0E8h
        _emit 0
        _emit 0
        _emit 0
        _emit 0
        sub eax, 2Ah
        mov dword ptr [ebp-360h], eax
        fild dword ptr [ebp-360h]
        fstp qword ptr [ebp-40h]
        mov byte ptr [ebp-30h], 2
        mov dword ptr [ebp-50h], 1
        mov byte ptr [ebp-2Fh], 1
        lea eax, [ebp-50h]
        push eax
        mov ecx, dword ptr [ebp-54h]
        mov ecx, dword ptr [ecx+7Ch]
        call Context::EmitEffect
        mov ecx, dword ptr [ebp-54h]
        call ResetFrame
        mov edx, dword ptr [ebp-54h]
        mov byte ptr [edx+2C9h], 25h
      state317_after_initial_effect:
        mov eax, dword ptr [ebp-54h]
        movzx ecx, word ptr [eax+0Ah]
        test ecx, ecx
        jle state317_after_scene_timer
        push 0Fh
        mov edx, dword ptr [ebp-54h]
        mov ecx, dword ptr [edx+7Ch]
        call Context::SetSceneTimer
      state317_after_scene_timer:
        mov eax, dword ptr [ebp-54h]
        movzx ecx, word ptr [eax+0Ah]
        cmp ecx, 4
        jle state317_after_local_effect
        mov edx, dword ptr [ebp-54h]
        movzx eax, word ptr [edx+0Ah]
        cmp eax, 8
        jge state317_after_local_effect
        mov ecx, dword ptr [ebp-54h]
        cmp dword ptr [ecx+3138h], 0
        jg state317_after_local_effect
        mov edx, dword ptr [ebp-54h]
        cmp dword ptr [edx+3140h], 32h
        jge state317_after_local_effect
        mov dword ptr [ebp-50h], 0
        mov word ptr [ebp-4Ch], 1B3h
        mov eax, dword ptr [ebp-54h]
        fld qword ptr [eax+20h]
        _emit 0E8h
        _emit 0
        _emit 0
        _emit 0
        _emit 0
        mov esi, eax
        mov ecx, dword ptr [ebp-54h]
        movsx edx, byte ptr [ecx+50h]
        imul edx, edx, 11h
        add esi, edx
        mov eax, dword ptr [ebp-54h]
        movsx edi, byte ptr [eax+50h]
        imul edi, edi, 30h
        push 2
        push 0
        mov ecx, dword ptr [ebp-54h]
        call RandomRange
        movzx ecx, ax
        neg ecx
        sbb ecx, ecx
        inc ecx
        imul edi, ecx
        sub esi, edi
        mov dword ptr [ebp-364h], esi
        fild dword ptr [ebp-364h]
        fstp qword ptr [ebp-48h]
        mov edx, dword ptr [ebp-54h]
        fld qword ptr [edx+28h]
        _emit 0E8h
        _emit 0
        _emit 0
        _emit 0
        _emit 0
        sub eax, 16h
        mov dword ptr [ebp-368h], eax
        fild dword ptr [ebp-368h]
        fstp qword ptr [ebp-40h]
        mov eax, dword ptr [ebp-54h]
        mov cl, byte ptr [eax+50h]
        mov byte ptr [ebp-38h], cl
        mov byte ptr [ebp-30h], 0
        mov byte ptr [ebp-2Fh], 1
        lea edx, [ebp-50h]
        push edx
        mov eax, dword ptr [ebp-54h]
        mov edx, dword ptr [eax]
        mov ecx, dword ptr [ebp-54h]
        call dword ptr [edx+24h]
        mov word ptr [ebp-4Ch], 1B4h
        mov eax, dword ptr [ebp-54h]
        mov cl, byte ptr [eax+50h]
        mov byte ptr [ebp-38h], cl
        mov byte ptr [ebp-30h], 2
        lea edx, [ebp-50h]
        push edx
        mov eax, dword ptr [ebp-54h]
        mov edx, dword ptr [eax]
        mov ecx, dword ptr [ebp-54h]
        call dword ptr [edx+24h]
        mov eax, dword ptr [ebp-54h]
        mov dword ptr [eax+3138h], 6
        mov ecx, dword ptr [ebp-54h]
        mov edx, dword ptr [ecx+3140h]
        add edx, 1
        mov eax, dword ptr [ebp-54h]
        mov dword ptr [eax+3140h], edx
      state317_after_local_effect:
        mov ecx, dword ptr [ebp-54h]
        mov edx, dword ptr [ecx+3138h]
        sub edx, 1
        mov eax, dword ptr [ebp-54h]
        mov dword ptr [eax+3138h], edx
        mov eax, dword ptr [ebp-54h]
        mov cx, word ptr [eax+0Ch]
        add cx, 1
        mov edx, dword ptr [ebp-54h]
        mov word ptr [edx+0Ch], cx
        mov eax, dword ptr [ebp-54h]
        movzx ecx, word ptr [eax+0Ch]
        movzx edx, word ptr [ebp-4h]
        cmp ecx, edx
        jl state317_skip_frame
        mov eax, dword ptr [ebp-54h]
        mov word ptr [eax+0Ch], 0
        mov ecx, dword ptr [ebp-54h]
        mov dx, word ptr [ecx+0Ah]
        add dx, 1
        mov eax, dword ptr [ebp-54h]
        mov word ptr [eax+0Ah], dx
        mov ecx, dword ptr [ebp-54h]
        movzx edx, word ptr [ecx+0Ah]
        cmp edx, 8
        jne state317_after_loop
        mov eax, dword ptr [ebp-54h]
        cmp dword ptr [eax+313Ch], 0Dh
        jge state317_after_loop
        mov ecx, dword ptr [ebp-54h]
        mov edx, dword ptr [ecx+313Ch]
        add edx, 1
        mov eax, dword ptr [ebp-54h]
        mov dword ptr [eax+313Ch], edx
        mov ecx, dword ptr [ebp-54h]
        movzx edx, word ptr [ecx+0Ah]
        sub edx, 4
        mov eax, dword ptr [ebp-54h]
        mov word ptr [eax+0Ah], dx
      state317_after_loop:
        mov ecx, dword ptr [ebp-54h]
        movzx edx, word ptr [ecx+0Ah]
        movzx eax, word ptr [ebp-8h]
        cmp edx, eax
        jl state317_skip_frame
        mov ecx, dword ptr [ebp-54h]
        mov word ptr [ecx+8h], 0
        mov ecx, dword ptr [ebp-54h]
        call FaceOpponent
        mov edx, dword ptr [ebp-54h]
        mov eax, dword ptr [edx]
        mov ecx, dword ptr [ebp-54h]
        call dword ptr [eax]
      state317_skip_frame:
      }
      break;
    case 318:
      __asm {
        mov ecx, dword ptr [ebp-54h]
        movzx edx, word ptr [ecx+0Ah]
        test edx, edx
        jne state318_after_zero_reset
        mov eax, dword ptr [ebp-54h]
        movzx ecx, word ptr [eax+0Ch]
        test ecx, ecx
        jne state318_after_zero_reset
        mov edx, dword ptr [ebp-54h]
        mov byte ptr [edx+158h], 0
        mov eax, dword ptr [ebp-54h]
        fld qword ptr ShioriZeroOperand
        fstp qword ptr [eax+30h]
        mov ecx, dword ptr [ebp-54h]
        fld qword ptr ShioriZeroOperand
        fstp qword ptr [ecx+38h]
        mov edx, dword ptr [ebp-54h]
        fld qword ptr ShioriZeroOperand
        fstp qword ptr [edx+48h]
      state318_after_zero_reset:
        mov eax, dword ptr [ebp-54h]
        movzx ecx, word ptr [eax+0Ah]
        cmp ecx, 3
        jne state318_after_spawn
        mov edx, dword ptr [ebp-54h]
        movzx eax, word ptr [edx+0Ch]
        test eax, eax
        jne state318_after_spawn
        mov word ptr [ebp-4Ch], 1A3h
        mov ecx, dword ptr [ebp-54h]
        fld qword ptr [ecx+20h]
        _emit 0E8h
        _emit 0
        _emit 0
        _emit 0
        _emit 0
        mov edx, dword ptr [ebp-54h]
        movsx ecx, byte ptr [edx+50h]
        imul ecx, ecx, 6
        add eax, ecx
        mov dword ptr [ebp-36Ch], eax
        fild dword ptr [ebp-36Ch]
        fstp qword ptr [ebp-48h]
        mov edx, dword ptr [ebp-54h]
        fld qword ptr [edx+28h]
        _emit 0E8h
        _emit 0
        _emit 0
        _emit 0
        _emit 0
        sub eax, 34h
        mov dword ptr [ebp-370h], eax
        fild dword ptr [ebp-370h]
        fstp qword ptr [ebp-40h]
        mov byte ptr [ebp-30h], 0
        mov dword ptr [ebp-50h], 1
        mov byte ptr [ebp-2Fh], 1
        mov eax, dword ptr [ebp-54h]
        movsx ecx, byte ptr [eax+50h]
        neg ecx
        mov byte ptr [ebp-38h], cl
        mov dword ptr [ebp-20h], 1
        lea edx, [ebp-50h]
        push edx
        mov eax, dword ptr [ebp-54h]
        mov edx, dword ptr [eax]
        mov ecx, dword ptr [ebp-54h]
        call dword ptr [edx+24h]
      state318_after_spawn:
        mov eax, dword ptr [ebp-54h]
        movzx ecx, word ptr [eax+0Ah]
        cmp ecx, 2
        jle state318_after_scene_timer
        push 3
        mov edx, dword ptr [ebp-54h]
        mov ecx, dword ptr [edx+7Ch]
        call Context::SetSceneTimer
        push 6
        push 0B0h
        mov ecx, dword ptr [ebp-54h]
        call SetTint
      state318_after_scene_timer:
        mov eax, dword ptr [ebp-54h]
        movzx ecx, word ptr [eax+0Ah]
        cmp ecx, 4
        jne state318_after_effect_pair
        mov edx, dword ptr [ebp-54h]
        movzx eax, word ptr [edx+0Ch]
        test eax, eax
        jne state318_after_effect_pair
        mov ecx, dword ptr [ebp-54h]
        mov word ptr [ecx+14Ch], 78h
        mov edx, dword ptr [ebp-54h]
        movsx eax, word ptr [edx+148h]
        sub eax, 0BB8h
        mov ecx, dword ptr [ebp-54h]
        mov word ptr [ecx+148h], ax
        push 3
        push 0B0h
        mov ecx, dword ptr [ebp-54h]
        call SetTint
        mov word ptr [ebp-4Ch], 46h
        mov byte ptr [ebp-24h], 40h
        mov edx, dword ptr [ebp-54h]
        fld qword ptr [edx+20h]
        _emit 0E8h
        _emit 0
        _emit 0
        _emit 0
        _emit 0
        mov ecx, dword ptr [ebp-54h]
        movsx edx, byte ptr [ecx+50h]
        imul edx, edx, 1Ch
        add eax, edx
        mov dword ptr [ebp-374h], eax
        fild dword ptr [ebp-374h]
        fstp qword ptr [ebp-48h]
        mov eax, dword ptr [ebp-54h]
        fld qword ptr [eax+28h]
        _emit 0E8h
        _emit 0
        _emit 0
        _emit 0
        _emit 0
        sub eax, 33h
        mov dword ptr [ebp-378h], eax
        fild dword ptr [ebp-378h]
        fstp qword ptr [ebp-40h]
        mov byte ptr [ebp-30h], 2
        mov dword ptr [ebp-50h], 1
        mov byte ptr [ebp-2Fh], 1
        lea ecx, [ebp-50h]
        push ecx
        mov edx, dword ptr [ebp-54h]
        mov ecx, dword ptr [edx+7Ch]
        call Context::EmitEffect
        mov eax, dword ptr [ebp-54h]
        mov byte ptr [eax+2C9h], 25h
        mov word ptr [ebp-4Ch], 47h
        lea ecx, [ebp-50h]
        push ecx
        mov edx, dword ptr [ebp-54h]
        mov ecx, dword ptr [edx+7Ch]
        call Context::EmitEffect
      state318_after_effect_pair:
        mov eax, dword ptr [ebp-54h]
        movzx ecx, word ptr [eax+0Ah]
        cmp ecx, 0Bh
        jne state318_after_local_effect
        mov edx, dword ptr [ebp-54h]
        movzx eax, word ptr [edx+0Ch]
        test eax, eax
        jne state318_after_local_effect
        mov dword ptr [ebp-50h], 1
        mov word ptr [ebp-4Ch], 1B8h
        mov ecx, dword ptr [ebp-54h]
        fld qword ptr [ecx+20h]
        _emit 0E8h
        _emit 0
        _emit 0
        _emit 0
        _emit 0
        mov edx, dword ptr [ebp-54h]
        movsx ecx, byte ptr [edx+50h]
        imul ecx, ecx, 14h
        add eax, ecx
        mov dword ptr [ebp-37Ch], eax
        fild dword ptr [ebp-37Ch]
        fstp qword ptr [ebp-48h]
        mov edx, dword ptr [ebp-54h]
        fld qword ptr [edx+28h]
        _emit 0E8h
        _emit 0
        _emit 0
        _emit 0
        _emit 0
        sub eax, 34h
        mov dword ptr [ebp-380h], eax
        fild dword ptr [ebp-380h]
        fstp qword ptr [ebp-40h]
        mov eax, dword ptr [ebp-54h]
        mov cl, byte ptr [eax+50h]
        mov byte ptr [ebp-38h], cl
        mov byte ptr [ebp-30h], 2
        mov byte ptr [ebp-2Fh], 1
        lea edx, [ebp-50h]
        push edx
        mov eax, dword ptr [ebp-54h]
        mov edx, dword ptr [eax]
        mov ecx, dword ptr [ebp-54h]
        call dword ptr [edx+24h]
      state318_after_local_effect:
        mov eax, dword ptr [ebp-54h]
        mov cx, word ptr [eax+0Ch]
        add cx, 1
        mov edx, dword ptr [ebp-54h]
        mov word ptr [edx+0Ch], cx
        mov eax, dword ptr [ebp-54h]
        movzx ecx, word ptr [eax+0Ch]
        movzx edx, word ptr [ebp-4h]
        cmp ecx, edx
        jl state318_skip_frame
        mov eax, dword ptr [ebp-54h]
        mov word ptr [eax+0Ch], 0
        mov ecx, dword ptr [ebp-54h]
        mov dx, word ptr [ecx+0Ah]
        add dx, 1
        mov eax, dword ptr [ebp-54h]
        mov word ptr [eax+0Ah], dx
        mov ecx, dword ptr [ebp-54h]
        mov dword ptr [ecx+168h], 0
        mov edx, dword ptr [ebp-54h]
        movzx eax, word ptr [edx+0Ah]
        movzx ecx, word ptr [ebp-8h]
        cmp eax, ecx
        jl state318_skip_frame
        mov edx, dword ptr [ebp-54h]
        mov word ptr [edx+8h], 0
        mov eax, dword ptr [ebp-54h]
        mov edx, dword ptr [eax]
        mov ecx, dword ptr [ebp-54h]
        call dword ptr [edx]
      state318_skip_frame:
      }
      break;
    case 319:
      __asm {
        mov eax, dword ptr [ebp-54h]
        mov word ptr [eax+13Eh], 3
        mov ecx, dword ptr [ebp-54h]
        movzx edx, word ptr [ecx+0Ah]
        cmp edx, 2
        jge state319_after_tint
        push 3
        push 0B0h
        mov ecx, dword ptr [ebp-54h]
        call SetTint
      state319_after_tint:
        mov eax, dword ptr [ebp-54h]
        movzx ecx, word ptr [eax+0Ah]
        test ecx, ecx
        jne state319_after_zero_reset
        mov edx, dword ptr [ebp-54h]
        movzx eax, word ptr [edx+0Ch]
        test eax, eax
        jne state319_after_zero_reset
        mov ecx, dword ptr [ebp-54h]
        mov byte ptr [ecx+158h], 0
        mov edx, dword ptr [ebp-54h]
        fld qword ptr ShioriZeroOperand
        fstp qword ptr [edx+30h]
        mov eax, dword ptr [ebp-54h]
        fld qword ptr ShioriZeroOperand
        fstp qword ptr [eax+38h]
        mov ecx, dword ptr [ebp-54h]
        fld qword ptr ShioriZeroOperand
        fstp qword ptr [ecx+48h]
        mov edx, dword ptr [ebp-54h]
        mov word ptr [edx+16Ch], 2
      state319_after_zero_reset:
        mov eax, dword ptr [ebp-54h]
        movzx ecx, word ptr [eax+0Ah]
        cmp ecx, 1
        jne state319_after_move
        mov edx, dword ptr [ebp-54h]
        movzx eax, word ptr [edx+0Ch]
        test eax, eax
        jne state319_after_move
        mov ecx, dword ptr [ebp-54h]
        mov edx, dword ptr [ecx+78h]
        mov eax, dword ptr [edx]
        mov ecx, dword ptr [ebp-54h]
        fld qword ptr [eax+20h]
        fstp qword ptr [ecx+20h]
        mov edx, dword ptr [ebp-54h]
        fld qword ptr ShioriMinusSixPointFiveOperand
        fstp qword ptr [edx+38h]
      state319_after_move:
        mov eax, dword ptr [ebp-54h]
        movzx ecx, word ptr [eax+0Ah]
        cmp ecx, 1
        jne state319_after_launch
        mov edx, dword ptr [ebp-54h]
        cmp dword ptr [edx+168h], 3
        jne state319_after_launch
        push 0
        push 5
        mov ecx, dword ptr [ebp-54h]
        call SetVerticalShake
        mov eax, dword ptr [ebp-54h]
        movsx ecx, byte ptr [eax+50h]
        mov dword ptr [ebp-384h], ecx
        fild dword ptr [ebp-384h]
        mov edx, dword ptr [ebp-54h]
        fadd qword ptr [edx+20h]
        mov eax, dword ptr [ebp-54h]
        mov ecx, dword ptr [eax+78h]
        mov edx, dword ptr [ecx]
        fstp qword ptr [edx+20h]
        mov ecx, dword ptr [ebp-54h]
        call ResetFrame
        mov eax, dword ptr [ebp-54h]
        mov word ptr [eax+0Ch], 0
        mov ecx, dword ptr [ebp-54h]
        mov word ptr [ecx+0Ah], 2
        mov edx, dword ptr [ebp-54h]
        mov eax, dword ptr [edx+78h]
        mov ecx, dword ptr [eax]
        mov word ptr [ecx+0Ah], 0
        mov edx, dword ptr [ebp-54h]
        mov eax, dword ptr [edx+78h]
        mov ecx, dword ptr [eax]
        mov word ptr [ecx+0Ch], 0
        mov edx, dword ptr [ebp-54h]
        mov eax, dword ptr [edx+78h]
        mov ecx, dword ptr [eax]
        mov word ptr [ecx+8h], 79h
        mov dword ptr [ebp-50h], 1
        mov word ptr [ebp-4Ch], 1BDh
        mov edx, dword ptr [ebp-54h]
        mov eax, dword ptr [edx+78h]
        mov ecx, dword ptr [eax]
        fld qword ptr [ecx+20h]
        fstp qword ptr [ebp-48h]
        mov edx, dword ptr [ebp-54h]
        mov eax, dword ptr [edx+78h]
        mov ecx, dword ptr [eax]
        fld qword ptr [ecx+28h]
        fstp qword ptr [ebp-40h]
        mov edx, dword ptr [ebp-54h]
        mov al, byte ptr [edx+50h]
        mov byte ptr [ebp-38h], al
        mov byte ptr [ebp-30h], 0
        mov byte ptr [ebp-2Fh], 0
        lea ecx, [ebp-50h]
        push ecx
        mov edx, dword ptr [ebp-54h]
        mov eax, dword ptr [edx]
        mov ecx, dword ptr [ebp-54h]
        call dword ptr [eax+24h]
      state319_after_launch:
        mov ecx, dword ptr [ebp-54h]
        movzx edx, word ptr [ecx+0Ah]
        cmp edx, 2
        jne state319_after_state2
        mov eax, dword ptr [ebp-54h]
        mov ecx, dword ptr [eax+3138h]
        sub ecx, 1
        mov edx, dword ptr [ebp-54h]
        mov dword ptr [edx+3138h], ecx
        mov eax, dword ptr [ebp-54h]
        mov ecx, dword ptr [eax+313Ch]
        add ecx, 1
        mov edx, dword ptr [ebp-54h]
        mov dword ptr [edx+313Ch], ecx
        mov eax, dword ptr [ebp-54h]
        cmp dword ptr [eax+3138h], 0
        jg state319_after_state2_timer
        mov ecx, dword ptr [ebp-54h]
        mov dword ptr [ecx+3138h], 18h
        mov edx, dword ptr [ebp-54h]
        fld qword ptr [edx+28h]
        fsub qword ptr ShioriOneOperand
        mov eax, dword ptr [ebp-54h]
        fstp qword ptr [eax+28h]
        mov ecx, dword ptr [ebp-54h]
        mov edx, dword ptr [ecx+78h]
        mov eax, dword ptr [edx]
        fld qword ptr [eax+28h]
        fsub qword ptr ShioriOneOperand
        mov ecx, dword ptr [ebp-54h]
        mov edx, dword ptr [ecx+78h]
        mov eax, dword ptr [edx]
        fstp qword ptr [eax+28h]
      state319_after_state2_timer:
        mov ecx, dword ptr [ebp-54h]
        cmp dword ptr [ecx+313Ch], 168h
        jne state319_after_state2
        mov edx, dword ptr [ebp-54h]
        mov word ptr [edx+0Ch], 0
        mov eax, dword ptr [ebp-54h]
        mov word ptr [eax+0Ah], 3
        mov ecx, dword ptr [ebp-54h]
        mov dword ptr [ecx+168h], 0
        mov edx, dword ptr [ebp-54h]
        fld qword ptr ShioriMinusThreePointFiveOperand
        fstp qword ptr [edx+38h]
      state319_after_state2:
        mov eax, dword ptr [ebp-54h]
        movzx ecx, word ptr [eax+0Ah]
        cmp ecx, 3
        jne state319_after_state3
        mov edx, dword ptr [ebp-54h]
        fld qword ptr [edx+38h]
        fcomp qword ptr ShioriZeroOperand
        fnstsw ax
        test ah, 41h
        jne state319_after_state3
        mov eax, dword ptr [ebp-54h]
        mov word ptr [eax+0Ch], 0
        mov ecx, dword ptr [ebp-54h]
        mov word ptr [ecx+0Ah], 4
        push 3
        mov edx, dword ptr [ebp-54h]
        mov ecx, dword ptr [edx+7Ch]
        call Context::RequestTransition
      state319_after_state3:
        mov eax, dword ptr [ebp-54h]
        movzx ecx, word ptr [eax+0Ah]
        cmp ecx, 3
        _emit 0Fh
        _emit 8Ch
        _emit 84h
        _emit 0
        _emit 0
        _emit 0
        push 3
        push 32h
        mov edx, dword ptr [ebp-54h]
        mov eax, dword ptr [edx+78h]
        mov ecx, dword ptr [eax]
        call SetHorizontalShake
        mov ecx, dword ptr [ebp-54h]
        mov edx, dword ptr [ecx+78h]
        mov eax, dword ptr [edx]
        movzx ecx, word ptr [eax+8h]
        cmp ecx, 63h
        jne state319_after_ground
        mov edx, dword ptr [ebp-54h]
        mov eax, dword ptr [edx+78h]
        mov ecx, dword ptr [eax]
        mov word ptr [ecx+0Ch], 0
      state319_after_ground:
        mov edx, dword ptr [ebp-54h]
        fld qword ptr [edx+38h]
        fadd qword ptr ShioriPointZeroThreeFiveOperand
        mov eax, dword ptr [ebp-54h]
        fstp qword ptr [eax+38h]
        mov ecx, dword ptr [ebp-54h]
        mov edx, dword ptr [ebp-54h]
        fld qword ptr [ecx+28h]
        fadd qword ptr [edx+38h]
        fcomp qword ptr ShioriZeroOperand
        fnstsw ax
        test ah, 41h
        jne state319_after_landing
        mov ecx, dword ptr [ebp-54h]
        call ResetFrame
        mov eax, dword ptr [ebp-54h]
        fld qword ptr ShioriZeroOperand
        fstp qword ptr [eax+28h]
        mov ecx, dword ptr [ebp-54h]
        mov edx, dword ptr [ecx]
        mov ecx, dword ptr [ebp-54h]
        call dword ptr [edx]
        mov eax, dword ptr [ebp-54h]
        mov word ptr [eax+8h], 0Dh
        jmp state319_epilogue
      state319_after_landing:
        mov ecx, dword ptr [ebp-54h]
        mov dx, word ptr [ecx+0Ch]
        add dx, 1
        mov eax, dword ptr [ebp-54h]
        mov word ptr [eax+0Ch], dx
        mov ecx, dword ptr [ebp-54h]
        movzx edx, word ptr [ecx+0Ch]
        movzx eax, word ptr [ebp-4h]
        cmp edx, eax
        jl state319_epilogue
        mov ecx, dword ptr [ebp-54h]
        mov word ptr [ecx+0Ch], 0
        mov edx, dword ptr [ebp-54h]
        mov ax, word ptr [edx+0Ah]
        add ax, 1
        mov ecx, dword ptr [ebp-54h]
        mov word ptr [ecx+0Ah], ax
        mov edx, dword ptr [ebp-54h]
        mov dword ptr [edx+168h], 0
        mov eax, dword ptr [ebp-54h]
        movzx ecx, word ptr [eax+0Ah]
        movzx edx, word ptr [ebp-8h]
        cmp ecx, edx
        jl state319_epilogue
        mov eax, dword ptr [ebp-54h]
        movzx ecx, word ptr [eax+0Ah]
        sub ecx, 2
        mov edx, dword ptr [ebp-54h]
        mov word ptr [edx+0Ah], cx
      state319_epilogue:
      }
      break;

  }
}
