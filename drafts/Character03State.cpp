// PROVISIONAL RECONSTRUCTION DRAFT — NOT INCLUDED IN THE BUILD.
// Target: Character03::Slot06 at 0x005E85F0; 124 explicit animation cases.
// Direct x87 conversions now preserve per-expression VC7.1 temporaries.
// Exactness is not claimed; the original PE remains the authority.
#include <CharacterViews.h>

void Character03::Slot06()
{
  unsigned short frameDuration, frameCount;
  if (0 < field014a) {
    return;
  }
  if (0 < (*opponentSlot)->field014c) {
    return;
  }
  EffectSpawn effect;
  frameDuration = patterns[field0008].frames[field000a].duration;
  frameCount = patterns[field0008].count;
  ResetLocalEffectSpawn(&effect);
  switch (field0008) {
    default:
    field0030 = 0.0;
        field0038 = 0.0;
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
      field0030 = 0.7;
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
      field0030 = -0.7;
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
      if ((field000a == 0) && (field000c == 0)) {
        if ((char)field0158 == '\0') {
          FaceOpponent();
        }
        field0030 = 0.0;
      }
      if ((field000a == 3) && (field000c == 0)) {
        field0048 = 0.042;
        field0038 = -2.9;
        if ((char)field0158 == '\x01') {
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
      if ((field000a == 0) && (field000c == 0)) {
        if ((char)field0158 == '\0') {
          FaceOpponent();
        }
        field0030 = 0.0;
      }
      if ((field000a == 3) && (field000c == 0)) {
        field0048 = 0.042;
        field0038 = -2.9;
        field0030 = 0.7;
        if ((char)field0158 == '\x01') {
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
          field000a = field000a + -2;
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
        if ((char)field0158 == '\0') {
          FaceOpponent();
        }
        field0030 = 0.0;
      }
      if ((field000a == 3) && (field000c == 0)) {
        field0048 = 0.042;
        field0038 = -2.9;
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
          field000a = field000a + -2;
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
          field0008 = 0;
          if (inputY == '\x01') {
            field0008 = 3;
          }
          ResetPose();
        }
      }
      break;
    case 14:
      field0048 = 0.042;
      if ((field000a == 0) && (field000c == 0)) {
        field0038 = -2.9;
        field0030 = 0.0;
        field0158 = 0;
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
      if ((field000a == 0) && (field000c == 0)) {
        field0038 = -2.9;
        field0030 = 0.7;
        field0158 = 0;
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
      if ((field000a == 0) && (field000c == 0)) {
        field0038 = -2.9;
        field0030 = -0.7;
        field0158 = 0;
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
        field0030 = 0.6;
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
          field000a = field000a + -1;
        }
      }
      break;
    case 50:
      if ((char)field0120 != '\0') {
        field0118 = field0118 - 0.6;
      }
      field0158 = 0;
      if ((field000a == 0) && (field000c == 0)) {
        field0148 = (short)field0148 + 10;
        field0030 =
             (2.0 - (*opponentSlot)->field0178 / 10000.0) *
             -1.1;
        if ((char)field0120 != '\0') {
          field0118 = field0118 - 10.0;
        }
      }
      field0038 = 0.0;
      field0028 = 0.0;
      field0030 = field0030 + 0.06;
      if (0.0 < field0030) {
        field0030 = 0.0;
      }
      if ((field0020 - 20.0 <= 0.0) ||
         (639.0 <= field0020 + 20.0)) {
        field00b8 = (1.0 - (double)(field0028 < 0.0) * 0.2) * field0030;
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
      if ((char)field0120 != '\0') {
        field0118 = field0118 - 0.6;
      }
      field0158 = 0;
      if ((field000a == 0) && (field000c == 0)) {
        field0148 = (short)field0148 + 0xf;
        field0030 =
             (2.0 - (*opponentSlot)->field0178 / 10000.0) *
             -1.5;
        if ((char)field0120 != '\0') {
          field0118 = field0118 - 20.0;
        }
      }
      field0038 = 0.0;
      field0028 = 0.0;
      field0030 = field0030 + 0.06;
      if (0.0 < field0030) {
        field0030 = 0.0;
      }
      if ((field0020 - 20.0 <= 0.0) ||
         (639.0 <= field0020 + 20.0)) {
        field00b8 = (1.0 - (double)(field0028 < 0.0) * 0.2) * field0030;
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
      if ((char)field0120 != '\0') {
        field0118 = field0118 - 0.6;
      }
      field0158 = 0;
      if ((field000a == 0) && (field000c == 0)) {
        field0148 = (short)field0148 + 0x14;
        field0030 =
             (2.0 - (*opponentSlot)->field0178 / 10000.0) *
             -1.8;
        if ((char)field0120 != '\0') {
          field0118 = field0118 - 30.0;
        }
      }
      field0038 = 0.0;
      field0028 = 0.0;
      field0030 = field0030 + 0.06;
      if (0.0 < field0030) {
        field0030 = 0.0;
      }
      if ((field0020 - 20.0 <= 0.0) ||
         (639.0 <= field0020 + 20.0)) {
        field00b8 = (1.0 - (double)(field0028 < 0.0) * 0.2) * field0030;
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
      if ((char)field0120 != '\0') {
        field0118 = field0118 - 0.6;
      }
      field0158 = 0;
      if ((field000a == 0) && (field000c == 0)) {
        field0148 = (short)field0148 + 10;
        field0030 =
             (2.0 - (*opponentSlot)->field0178 / 10000.0) *
             -1.1;
        if ((char)field0120 != '\0') {
          field0118 = field0118 - 10.0;
        }
      }
      field0038 = 0.0;
      field0028 = 0.0;
      field0030 = field0030 + 0.06;
      if (0.0 < field0030) {
        field0030 = 0.0;
      }
      if ((field0020 - 20.0 <= 0.0) ||
         (639.0 <= field0020 + 20.0)) {
        field00b8 = (1.0 - (double)(field0028 < 0.0) * 0.2) * field0030;
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
      if ((char)field0120 != '\0') {
        field0118 = field0118 - 0.6;
      }
      field0158 = 0;
      if ((field000a == 0) && (field000c == 0)) {
        field0148 = (short)field0148 + 0xf;
        field0030 =
             (2.0 - (*opponentSlot)->field0178 / 10000.0) *
             -1.5;
        if ((char)field0120 != '\0') {
          field0118 = field0118 - 20.0;
        }
      }
      field0038 = 0.0;
      field0028 = 0.0;
      field0030 = field0030 + 0.06;
      if (0.0 < field0030) {
        field0030 = 0.0;
      }
      if ((field0020 - 20.0 <= 0.0) ||
         (639.0 <= field0020 + 20.0)) {
        field00b8 = (1.0 - (double)(field0028 < 0.0) * 0.2) * field0030;
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
      if ((char)field0120 != '\0') {
        field0118 = field0118 - 0.6;
      }
      field0158 = 0;
      if ((field000a == 0) && (field000c == 0)) {
        field0148 = (short)field0148 + 0x14;
        field0030 =
             (2.0 - (*opponentSlot)->field0178 / 10000.0) *
             -1.8;
        if ((char)field0120 != '\0') {
          field0118 = field0118 - 30.0;
        }
      }
      field0038 = 0.0;
      field0028 = 0.0;
      field0030 = field0030 + 0.06;
      if (0.0 < field0030) {
        field0030 = 0.0;
      }
      if ((field0020 - 20.0 <= 0.0) ||
         (639.0 <= field0020 + 20.0)) {
        field00b8 = (1.0 - (double)(field0028 < 0.0) * 0.2) * field0030;
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
      if ((char)field0120 != '\0') {
        field0118 = field0118 - 0.6;
      }
      field0158 = 0;
      if ((field000a == 0) && (field000c == 0)) {
        field0148 = (short)field0148 + 10;
        field0030 =
             (2.0 - (*opponentSlot)->field0178 / 10000.0) *
             -1.1;
        if ((char)field0120 != '\0') {
          field0118 = field0118 - 10.0;
        }
      }
      field0038 = 0.0;
      field0028 = 0.0;
      field0030 = field0030 + 0.06;
      if (0.0 < field0030) {
        field0030 = 0.0;
      }
      if ((field0020 - 20.0 <= 0.0) ||
         (639.0 <= field0020 + 20.0)) {
        field00b8 = (1.0 - (double)(field0028 < 0.0) * 0.2) * field0030;
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
      if ((char)field0120 != '\0') {
        field0118 = field0118 - 0.6;
      }
      field0158 = 0;
      if ((field000a == 0) && (field000c == 0)) {
        field0148 = (short)field0148 + 0xf;
        field0030 =
             (2.0 - (*opponentSlot)->field0178 / 10000.0) *
             -1.5;
        if ((char)field0120 != '\0') {
          field0118 = field0118 - 20.0;
        }
      }
      field0038 = 0.0;
      field0028 = 0.0;
      field0030 = field0030 + 0.06;
      if (0.0 < field0030) {
        field0030 = 0.0;
      }
      if ((field0020 - 20.0 <= 0.0) ||
         (639.0 <= field0020 + 20.0)) {
        field00b8 = (1.0 - (double)(field0028 < 0.0) * 0.2) * field0030;
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
      if ((char)field0120 != '\0') {
        field0118 = field0118 - 0.6;
      }
      field0158 = 0;
      if ((field000a == 0) && (field000c == 0)) {
        field0148 = (short)field0148 + 0x14;
        field0030 =
             (2.0 - (*opponentSlot)->field0178 / 10000.0) *
             -1.8;
        if ((char)field0120 != '\0') {
          field0118 = field0118 - 30.0;
        }
      }
      field0038 = 0.0;
      field0028 = 0.0;
      field0030 = field0030 + 0.06;
      if (0.0 < field0030) {
        field0030 = 0.0;
      }
      if ((field0020 - 20.0 <= 0.0) ||
         (639.0 <= field0020 + 20.0)) {
        field00b8 = (1.0 - (double)(field0028 < 0.0) * 0.2) * field0030;
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
      if ((char)field0120 != '\0') {
        field0118 = field0118 - 0.8;
      }
      if ((field000a == 0) && (field000c == 0)) {
        field0148 = (short)field0148 + 0x1e;
        field0030 = field00c0;
        field0038 =
             field0038 * 0.75 + field00c8;
        if (-2.0 <= field0038) {
          if (-0.5 < field0038) {
            field0038 = -0.5;
          }
        }
        else {
          field0038 = -2.0;
        }
        field0048 = 0.032;
      }
      if (field0038 <= 0.0) {
        field000a = 1;
        field000c = 0;
      }
      if ((0.0 <= field0038) && (field000a < 2)) {
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
        if (field012c == 0) {
          field0008 = 0x62;
          ResetPose();
        }
        else {
          field0008 = 0x61;
          ResetPose();
        }
      }
      break;
    case 60:
      if ((char)field0120 != '\0') {
        field0118 = field0118 - 0.8;
      }
      if ((field000a == 0) && (field000c == 0)) {
        field0148 = (short)field0148 + 0x1e;
        field0030 = field00c0;
        field0038 =
             field0038 * 0.75 + field00c8;
        if (-4.0 <= field0038) {
          if (-0.5 < field0038) {
            field0038 = -0.5;
          }
        }
        else {
          field0038 = -4.0;
        }
        field0048 = 0.032;
      }
      if (field0038 <= 0.0) {
        field000a = 1;
        field000c = 0;
      }
      if ((0.0 <= field0038) && (field000a < 2)) {
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
        if (field012c == 0) {
          field0008 = 0x62;
          ResetPose();
        }
        else {
          field0008 = 0x61;
          ResetPose();
        }
      }
      break;
    case 61:
      if ((char)field0120 != '\0') {
        field0118 = field0118 - 0.8;
      }
      if ((field000a == 0) && (field000c == 0)) {
        field0148 = (short)field0148 + 0x1e;
        field0030 = field00c0;
        field0038 =
             field0038 * 0.75 + field00c8;
        if (-6.0 <= field0038) {
          if (-0.5 < field0038) {
            field0038 = -0.5;
          }
        }
        else {
          field0038 = -6.0;
        }
        field0048 = 0.032;
      }
      if (field0038 <= 0.0) {
        field000a = 1;
        field000c = 0;
      }
      if ((0.0 <= field0038) && (field000a < 2)) {
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
        if (field012c == 0) {
          field0008 = 0x62;
          ResetPose();
        }
        else {
          field0008 = 0x61;
          ResetPose();
        }
      }
      break;
    case 62:
      if ((char)field0120 != '\0') {
        field0118 = field0118 - 0.8;
      }
      if ((field000a == 0) && (field000c == 0)) {
        field0148 = (short)field0148 + 0x1e;
        field0030 = field00c0;
        field0038 =
             field0038 * 0.75 + field00c8;
        field0048 = 0.032;
      }
      if (field0038 <= 0.0) {
        field000a = 1;
        field000c = 0;
      }
      if ((0.0 <= field0038) && (field000a < 2)) {
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
        if (field012c == 0) {
          field0008 = 0x62;
          ResetPose();
        }
        else {
          field0008 = 0x61;
          ResetPose();
        }
      }
      break;
    case 63:
      if ((char)field0120 != '\0') {
        field0118 = field0118 - 0.8;
      }
      if ((field000a == 0) && (field000c == 0)) {
        field0148 = (short)field0148 + 0x1e;
        field0030 = field00c0;
        field0038 = field00c8;
        field0048 = 0.032;
      }
      if (field0038 <= 0.0) {
        field000a = 1;
        field000c = 0;
      }
      if ((0.0 <= field0038) && (field000a < 2)) {
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
        if (field012c == 0) {
          field0008 = 0x62;
          ResetPose();
        }
        else {
          field0008 = 0x61;
          ResetPose();
        }
      }
      break;
    case 64:
      if ((char)field0120 != '\0') {
        field0118 = field0118 - 0.8;
      }
      if ((field000a == 0) || (CollisionSide() == '\0')) {
        if ((field000a == 0) && (field000c == 0)) {
          field0148 = (short)field0148 + 0x1e;
          field0030 = field00c0;
          field0038 =
               field0038 * 0.75 + field00c8;
          if (-2.0 <= field0038) {
            if (-0.5 < field0038) {
              field0038 = -0.5;
            }
          }
          else {
            field0038 = -2.0;
          }
          field0048 = 0.032;
        }
        if (field0038 <= 0.0) {
          field000a = 1;
          field000c = 0;
        }
        if ((0.0 <= field0038) && (field000a < 2)) {
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
          if (field012c == 0) {
            field0008 = 0x62;
            ResetPose();
          }
          else {
            field0008 = 0x61;
            ResetPose();
          }
        }
      }
      else {
        field0008 = 0x46;
        ResetPose();
      }
      break;
    case 65:
      if ((char)field0120 != '\0') {
        field0118 = field0118 - 0.8;
      }
      if ((field000a == 0) || (CollisionSide() == '\0')) {
        if ((field000a == 0) && (field000c == 0)) {
          field0148 = (short)field0148 + 0x1e;
          field0030 = field00c0;
          field0038 =
               field0038 * 0.75 + field00c8;
          if (-4.0 <= field0038) {
            if (-0.5 < field0038) {
              field0038 = -0.5;
            }
          }
          else {
            field0038 = -4.0;
          }
          field0048 = 0.032;
        }
        if (field0038 <= 0.0) {
          field000a = 1;
          field000c = 0;
        }
        if ((0.0 <= field0038) && (field000a < 2)) {
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
          if (field012c == 0) {
            field0008 = 0x62;
            ResetPose();
          }
          else {
            field0008 = 0x61;
            ResetPose();
          }
        }
      }
      else {
        field0008 = 0x46;
        ResetPose();
      }
      break;
    case 66:
      if ((char)field0120 != '\0') {
        field0118 = field0118 - 0.8;
      }
      if ((field000a == 0) || (CollisionSide() == '\0')) {
        if ((field000a == 0) && (field000c == 0)) {
          field0148 = (short)field0148 + 0x1e;
          field0030 = field00c0;
          field0038 =
               field0038 * 0.75 + field00c8;
          field0048 = 0.032;
        }
        if (field0038 <= 0.0) {
          field000a = 1;
          field000c = 0;
        }
        if ((0.0 <= field0038) && (field000a < 2)) {
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
          if (field012c == 0) {
            field0008 = 0x62;
            ResetPose();
          }
          else {
            field0008 = 0x61;
            ResetPose();
          }
        }
      }
      else {
        field0008 = 0x46;
        ResetPose();
      }
      break;
    case 67:
      if ((char)field0120 != '\0') {
        field0118 = field0118 - 0.8;
      }
      if ((field000a == 0) || (CollisionSide() == '\0')) {
        if ((field000a == 0) && (field000c == 0)) {
          field0148 = (short)field0148 + 0x1e;
          field0030 = field00c0;
          field0038 = field00c8;
          field0048 = 0.032;
        }
        if (field0038 <= 0.0) {
          field000a = 1;
          field000c = 0;
        }
        if ((0.0 <= field0038) && (field000a < 2)) {
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
          if (field012c == 0) {
            field0008 = 0x62;
            ResetPose();
          }
          else {
            field0008 = 0x61;
            ResetPose();
          }
        }
      }
      else {
        field0008 = 0x46;
        ResetPose();
      }
      break;
    case 68:
      if ((char)field0120 != '\0') {
        field0118 = field0118 - 1.5;
      }
      field0148 = (short)field0148 + 3;
      field0030 = field00c0;
      field0038 = field00c8;
      ++field000c;
      if (CollisionSide() == '\0') {
        if ((unsigned short)field000c >= frameDuration) {
          field000c = 0;
          ++field000a;
          if (field000a >= frameCount) {
            field000a = field000a + -2;
          }
        }
        if (0.0 <= field0028 + field0038) {
          field0028 = 0.0;
          if (field012c == 0) {
            field0008 = 0x62;
            ResetPose();
          }
          else {
            field0008 = 0x61;
            ResetPose();
          }
        }
      }
      else {
        field0008 = 0x46;
        ResetPose();
      }
      break;
    case 69:
      if ((char)field0120 != '\0') {
        field0118 = field0118 - 1.5;
      }
      field0148 = (short)field0148 + 3;
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
        if (field012c == 0) {
          field0008 = 0x62;
          ResetPose();
        }
        else {
          field0008 = 0x61;
          ResetPose();
        }
      }
      break;
    case 70:
      if ((char)field0120 != '\0') {
        field0118 = field0118 - 0.8;
      }
      if (((field000a == 0) && (field000c == 0)) &&
         (field3138 == 0)) {
        field0148 = (short)field0148 + 0x1e;
        field3138 = field3138 + 1;
        field0124 = (short)field0124 + 0x78;
        field0030 = 0.5;
        field0038 = -2.5;
        field0048 = 0.025;
        field02c9 = 0x1f;
        effect.type = 0;
        effect.x = (double)(int)field0020;
        effect.y = (double)(int)field0028;
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
        if (field012c == 0) {
          field0008 = 0x62;
          ResetPose();
        }
        else {
          field0008 = 0x61;
          ResetPose();
        }
      }
      break;
    case 71:
      if ((char)field0120 != '\0') {
        field0118 = field0118 - 0.8;
      }
      if ((field000a == 0) && (field000c == 0)) {
        field0148 = (short)field0148 + 0x1e;
        field0030 = field00c0;
        field0038 = field00c8;
        field0048 = 0.072;
      }
      if (field0038 <= 0.0) {
        field000a = 1;
        field000c = 0;
      }
      if ((0.0 <= field0038) && (field000a < 2)) {
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
        if (field012c == 0) {
          field0008 = 0x62;
          ResetPose();
        }
        else {
          field0008 = 0x61;
          ResetPose();
        }
      }
      break;
    case 72:
      if ((char)field0120 != '\0') {
        field0118 = field0118 - 0.8;
      }
      field0158 = 0;
      field0030 = 0.0;
      field0038 = 0.0;
      if ((field0020 - 20.0 <= 0.0) ||
         (639.0 <= field0020 + 20.0)) {
        field00b8 = (1.0 - (double)((*opponentSlot)->field0028 < 0.0) * 0.25) * field0030;
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
      if ((char)field0120 != '\0') {
        field0118 = field0118 - 0.8;
      }
      field0158 = 0;
      field0030 = 0.0;
      field0038 = 0.0;
      if ((field0020 - 20.0 <= 0.0) ||
         (639.0 <= field0020 + 20.0)) {
        field00b8 = (1.0 - (double)((*opponentSlot)->field0028 < 0.0) * 0.25) * field0030;
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
      if ((char)field0120 != '\0') {
        field0118 = field0118 - 0.8;
      }
      field0158 = 0;
      field0030 = 0.0;
      field0038 = 0.0;
      if ((field0020 - 20.0 <= 0.0) ||
         (639.0 <= field0020 + 20.0)) {
        field00b8 = (1.0 - (double)((*opponentSlot)->field0028 < 0.0) * 0.25) * field0030;
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
      if ((char)field0120 != '\0') {
        field0118 = field0118 - 0.6;
      }
      field0158 = 0;
      if ((field000a == 0) && (field000c == 0)) {
        field0148 = (short)field0148 + 0x1e;
        if ((char)field0120 != '\0') {
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
        field00b8 = (1.0 - (double)((*opponentSlot)->field0028 < 0.0) * 0.25) * field0030;
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
      if ((char)field0120 != '\0') {
        field0118 = field0118 - 0.6;
      }
      field0158 = 0;
      if ((field000a == 0) && (field000c == 0)) {
        field0148 = (short)field0148 + 0x1e;
        if ((char)field0120 != '\0') {
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
        field00b8 = (1.0 - (double)((*opponentSlot)->field0028 < 0.0) * 0.25) * field0030;
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
      if ((char)field0120 != '\0') {
        field0118 = field0118 - 0.6;
      }
      field0158 = 0;
      if ((field000a == 0) && (field000c == 0)) {
        field0148 = (short)field0148 + 0x1e;
        if ((char)field0120 != '\0') {
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
        field00b8 = (1.0 - (double)((*opponentSlot)->field0028 < 0.0) * 0.25) * field0030;
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
      if ((char)field0120 != '\0') {
        field0118 = field0118 - 0.8;
      }
      if ((field000a == 0) && (field000c == 0)) {
        effect.type = 499;
        effect.x = (double)(int)field0020;
        effect.y = (double)(int)field0028;
        effect.flag0018 = (char)facing;
        effect.layer = 1;
        EmitLocalEffect(&effect);
        field0148 = (short)field0148 + 0x1e;
        field0030 = field00c0;
        field0038 = field00c8;
        field0048 = 0.032;
      }
      field0030 = field0030 + 0.02;
      field0038 = field0038 + field0048;
      if (0.0 < field0030) {
        field0030 = 0.0;
      }
      ++field000c;
      if ((unsigned short)field000c >= frameDuration) {
        field000c = 0;
        ++field000a;
        if (field000a >= frameCount) {
          field000a = field000a + -1;
        }
      }
      if ((0.0 <= field0028 + field0038) &&
         (field000a == 1)) {
        field0028 = 0.0;
        if (field012c == 0) {
          field0008 = 0x62;
          ResetPose();
        }
        else {
          field0008 = 0x61;
          ResetPose();
        }
      }
      break;
    case 82:
      if ((char)field0120 != '\0') {
        field0118 = field0118 - 0.8;
      }
      if (((field000a == 0) && (field000c == 0)) &&
         (field3138 == 0)) {
        field02c9 = 0x1e;
        field0038 = -0.45;
        field0030 = -0.1;
        field3138 = field3138 + 1;
        field0148 = (short)field0148 + 0x1e;
      }
      if ((field000a == 4) && (field000c == 0)) {
        field0030 = field00c0;
        field0038 = field00c8;
        field0048 = 0.032;
      }
      if ((0.0 < field0038) && (field000a == 4)) {
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
          field3138 = field3138 + 1;
        }
        if (field000a >= frameCount) {
          field000a = field000a + -2;
        }
      }
      if ((0.0 <= field0028 + field0038) &&
         (4 < field000a)) {
        field0028 = 0.0;
        if (field012c == 0) {
          field0008 = 0x62;
          ResetPose();
        }
        else {
          field0008 = 0x61;
          ResetPose();
        }
      }
      break;
    case 83:
      if ((field000a == 0) && (field000c == 0)) {
        if (field3144 == 0) {
          effect.type = 0x1f0;
          effect.x = (double)(int)field0020;
          effect.y = (double)(int)field0028;
          effect.group = 0;
          effect.layer = 0;
          effect.owner = 1;
          effect.flag0018 = (char)facing;
          EmitLocalEffect(&effect);
          field3144 = 1;
        }
        if ((char)field0120 != '\0') {
          field0118 = field0118 - 30.0;
        }
        field02c9 = 0x21;
        field0038 = -1.5;
        field0030 = -0.8;
        field0148 = (short)field0148 + 0x1e;
      }
      field0038 = field0038 + 0.04;
      if ((field000a > 0) ||
         (field0038 + field0028 <= 0.0)) {
        if (field000a == 1) {
          field0030 = field0030 + 0.01;
        }
        if ((field000a == 2) && (field000c == 0)) {
          field0030 = -2.0;
        }
        if (1 < field000a) {
          field0030 = field0030 + 0.06;
        }
        if (0.0 < field0030) {
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
      }
      else {
        field0028 = 0.0;
        field0038 = 0.0;
        field000c = 0;
        field000a = 1;
      }
      break;
    case 84:
      if ((field000a == 0) && (field000c == 0)) {
        if (field3144 == 0) {
          effect.type = 0x1f0;
          effect.x = (double)(int)field0020;
          effect.y = (double)(int)field0028;
          effect.group = 0;
          effect.layer = 0;
          effect.owner = 1;
          effect.flag0018 = (char)facing;
          EmitLocalEffect(&effect);
          field3144 = 1;
        }
        if ((char)field0120 != '\0') {
          field0118 = field0118 - 30.0;
        }
        field02c9 = 0x21;
        field0038 = -1.5;
        field0030 = -0.8;
        field0148 = (short)field0148 + 0x1e;
      }
      field0038 = field0038 + 0.04;
      if ((field000a > 0) ||
         (field0038 + field0028 <= 0.0)) {
        if (field000a == 1) {
          field0030 = field0030 + 0.01;
        }
        if ((field000a == 2) && (field000c == 0)) {
          field0030 = -2.0;
        }
        if (1 < field000a) {
          field0030 = field0030 + 0.06;
        }
        if (0.0 < field0030) {
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
      }
      else {
        field0028 = 0.0;
        field0038 = 0.0;
        field000c = 0;
        field000a = 1;
      }
      break;
    case 85:
      if ((field000a == 0) && (field000c == 0)) {
        if (field3144 == 0) {
          effect.type = 0x1f0;
          effect.x = (double)(int)field0020;
          effect.y = (double)(int)field0028;
          effect.group = 0;
          effect.layer = 0;
          effect.owner = 1;
          effect.flag0018 = (char)facing;
          EmitLocalEffect(&effect);
          field3144 = 1;
        }
        if ((char)field0120 != '\0') {
          field0118 = field0118 - 30.0;
        }
        field02c9 = 0x21;
        field0030 = field00c0;
        field0038 = field00c8;
        field0148 = (short)field0148 + 0x1e;
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
        if (field012c == 0) {
          field0008 = 0x62;
          ResetPose();
        }
        else {
          field0008 = 0x61;
          ResetPose();
        }
      }
      break;
    case 86:
      if ((field000a == 0) && (field000c == 0)) {
        if (field3144 == 0) {
          effect.type = 0x1f0;
          effect.x = (double)(int)field0020;
          effect.y = (double)(int)field0028;
          effect.group = 0;
          effect.layer = 0;
          effect.owner = 1;
          effect.flag0018 = (char)facing;
          EmitLocalEffect(&effect);
          field3144 = 1;
        }
        if (field3138 == 0) {
          if ((char)field0120 != '\0') {
            field0118 = field0118 - 30.0;
          }
          field02c9 = 0x21;
          field0030 = field00c0;
          field0038 = field00c8;
          field0148 = (short)field0148 + 0x1e;
          field3138 = field3138 + 1;
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
        if (field012c == 0) {
          field0008 = 0x62;
          ResetPose();
        }
        else {
          field0008 = 0x61;
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
        if ((unsigned int)field000a == frameCount - 1) {
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
        effect.x = (double)(int)field0020;
        effect.y = (double)(int)field0028;
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
      if ((field000a == 0) && (field000c == 0)) {
        SetVerticalShake(3,0);
        effect.type = 3;
        effect.x = (double)(int)field0020;
        effect.y = (double)(int)field0028;
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
      field0158 = 0;
      if ((0 < field0108) && (99 < (unsigned short)field000c)) {
        field0008 = 0x60;
        ResetPose();
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
      if ((field000a == 0) && (field000c == 0)) {
        field0158 = 0;
        field0148 = (short)field0148 + 10;
        field0030 = -1.5;
        field0038 = 0.0;
        field0028 = 0.0;
      }
      field0038 = 0.0;
      field0030 = field0030 + 0.06;
      if (0.0 < field0030) {
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
      if ((field000a == 0) && (field000c == 0)) {
        field0158 = 0;
        field0148 = (short)field0148 + 0xf;
        field0030 = -1.8;
        field0038 = 0.0;
        field0028 = 0.0;
      }
      field0038 = 0.0;
      field0030 = field0030 + 0.06;
      if (0.0 < field0030) {
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
      if ((field000a == 0) && (field000c == 0)) {
        field0158 = 0;
        field0148 = (short)field0148 + 0x14;
        field0030 = -2.3;
        field0038 = 0.0;
        field0028 = 0.0;
      }
      field0038 = 0.0;
      field0030 = field0030 + 0.06;
      if (0.0 < field0030) {
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
      if ((field000a == 0) && (field000c == 0)) {
        field0158 = 0;
        field0148 = (short)field0148 + 10;
        field0030 = -1.5;
        field0038 = 0.0;
        field0028 = 0.0;
      }
      field0038 = 0.0;
      field0030 = field0030 + 0.06;
      if (0.0 < field0030) {
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
      if ((field000a == 0) && (field000c == 0)) {
        field0158 = 0;
        field0148 = (short)field0148 + 0xf;
        field0030 = -1.8;
        field0038 = 0.0;
        field0028 = 0.0;
      }
      field0038 = 0.0;
      field0030 = field0030 + 0.06;
      if (0.0 < field0030) {
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
      if ((field000a == 0) && (field000c == 0)) {
        field0158 = 0;
        field0148 = (short)field0148 + 0x14;
        field0030 = -2.3;
        field0038 = 0.0;
        field0028 = 0.0;
      }
      field0038 = 0.0;
      field0030 = field0030 + 0.06;
      if (0.0 < field0030) {
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
      if ((field000a == 0) && (field000c == 0)) {
        field0038 = -2.6;
        field0148 = (short)field0148 + 0xf;
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
      if ((field000a == 0) && (field000c == 0)) {
        field0038 = -2.3;
        effect.type = 8;
        effect.x = (double)(int)field0020;
        effect.y = (double)(int)field0028;
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
          field000a = field000a + -2;
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
      if ((field000a == 0) && (field000c == 0)) {
        field0038 = -2.3;
        effect.type = 8;
        effect.x = (double)(int)field0020;
        effect.y = (double)(int)field0028;
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
          field000a = field000a + -2;
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
        effect.x = (double)(int)field0020;
        effect.y = (double)((int)field0028 + -0x3c);
        effect.group = 2;
        effect.layer = 1;
        contextOwner->EmitEffect(&effect);
        field016c = 1;
        field02c9 = 0x3e;
        field3138 = field3138 + 1;
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
      if ((field000a == 0) && (field000c == 0)) {
        ResetFrame();
      }
      if ((field000a == 3) && (field000c == 0)) {
        field0038 = -1.5;
        field0048 = 0.025;
        field016c = 1;
      }
      if ((field000a == 7) && (field000c == 0)) {
        ResetFrame();
        effect.type = 9;
        effect.x = (double)(int)field0020;
        effect.y = (double)((int)field0028 + -0x3c);
        effect.group = 2;
        effect.layer = 1;
        contextOwner->EmitEffect(&effect);
        field016c = 1;
        field02c9 = 0x3e;
        field0148 = (short)field0148 + -1000;
        field3138 = field3138 + 1;
      }
      field0038 = field0038 + field0048;
      if (field0028 + field0038 <= 0.0) {
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
      }
      else {
        field0008 = 0xd;
        ResetPose();
        ResetPose();
        field0028 = 0.0;
      }
      break;
    case 163:
      if ((field000a == 0) && (field000c == 0)) {
        StartTrail(3);
      }
      if ((inputY == -1) && (field000a > 0)) {
        field0008 = 4;
        if ((char)inputX == (char)facing) {
          field0008 = 5;
        }
        if ((int)(char)inputX == -(int)(char)facing) {
          field0008 = 6;
        }
        field0168 = 0;
        ResetPose();
      }
      else {
        if ((field000a == 0) && (field000c == 0)) {
          field0038 = 0.0;
          field0048 = 0.0;
        }
        field0030 = 2.2;
        field0158 = 1;
        ++field000c;
        field3138 = field3138 + 1;
        field313c = field313c + 1;
        if ((unsigned short)field000c >= frameDuration) {
          field000c = 0;
          ++field000a;
          if (field000a >= frameCount) {
            field000a = field000a + -6;
            return;
          }
        }
        if ((((char)inputX == (char)facing) && (0x4f < field313c)) &&
           (field000a < 4)) {
          field0008 = 0xb2;
          ResetPose();
        }
        if ((((char)inputX != (char)facing) && (0x3b < field3138)) &&
           (field000a < 4)) {
          field0008 = 0xb2;
          ResetPose();
        }
      }
      break;
    case 164:
      StartTrail(3);
      field0158 = 0;
      if ((field000a == 0) && (field000c == 0)) {
        field0030 = 0.0;
        field0038 = 0.0;
      }
      if ((field000a == 1) && (field000c == 0)) {
        field0030 = -2.2;
      }
      field0030 = field0030 + 0.02;
      if (0.0 < field0030) {
        field0030 = 0.0;
      }
      ++field000c;
      if ((unsigned short)field000c >= frameDuration) {
        field000c = 0;
        ++field000a;
        if ((field000a == 4) && (field3138 < 2)) {
          field000a = field000a + -2;
          field3138 = field3138 + 1;
        }
        if (field000a >= frameCount) {
          FaceOpponent();
          field0008 = 0;
          ResetPose();
          ResetFrame();
        }
      }
      break;
    case 165:
      if (((field000a == 0) && (field000c == 0)) &&
         (field3138 == 0)) {
        field0030 = 1.9;
        field0038 = 1.3;
        StartTrail(3);
        field0040 = -0.015;
        field0048 = -0.038;
        field02c9 = 0x11;
      }
      field0038 = field0038 + field0048;
      field0030 = field0030 + field0040;
      if (field0030 < 0.5) {
        field0030 = 0.5;
      }
      if (field0038 < -1.5) {
        field0038 = -1.5;
      }
      ++field000c;
      field3138 = field3138 + 1;
      field313c = field313c + 1;
      if ((unsigned short)field000c >= frameDuration) {
        field000c = 0;
        ++field000a;
        if (field000a >= frameCount) {
          field000a = field000a + -2;
        }
      }
      if (((char)inputX == (char)facing) && (0x77 < field313c)) {
        field0008 = 9;
        ResetPose();
        field0048 = 0.03;
        if (FaceOpponent() != 0) {
          field0030 = -field0030;
        }
      }
      if (((char)inputX != (char)facing) && (0x2f < field3138)) {
        field0008 = 9;
        ResetPose();
        field0048 = 0.03;
        if (FaceOpponent() != 0) {
          field0030 = -field0030;
        }
      }
      break;
    case 166:
      if (((field000a == 0) && (field000c == 0)) &&
         (field3138 == 0)) {
        field0030 = -1.9;
        field0038 = 1.3;
        StartTrail(3);
        field0040 = 0.015;
        field0048 = -0.038;
        field02c9 = 0x11;
      }
      field0038 = field0038 + field0048;
      field0030 = field0030 + field0040;
      if (-0.5 < field0030) {
        field0030 = -0.5;
      }
      if (field0038 < -1.5) {
        field0038 = -1.5;
      }
      ++field000c;
      field3138 = field3138 + 1;
      field313c = field313c + 1;
      if ((unsigned short)field000c >= frameDuration) {
        field000c = 0;
        ++field000a;
        if (field000a >= frameCount) {
          field000a = field000a + -2;
        }
      }
      if (((int)(char)inputX == -(int)(char)facing) && (0x77 < field313c)) {
        field0008 = 9;
        ResetPose();
        field0048 = 0.03;
        if (FaceOpponent() != 0) {
          field0030 = -field0030;
        }
      }
      if (((int)(char)inputX != -(int)(char)facing) && (0x2f < field3138)) {
        field0008 = 9;
        ResetPose();
        field0048 = 0.03;
        if (FaceOpponent() != 0) {
          field0030 = -field0030;
        }
      }
      break;
    case 167:
      if ((field000a == 0) && (field000c == 0)) {
        field0158 = 0;
        field0030 = 0.0;
        field0038 = 0.0;
        if ((char)field0120 == '\x01') {
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
        effect.x = (double)(int)field0020;
        effect.y = (double)(int)field0028;
        effect.group = 2;
        effect.layer = 1;
        contextOwner->EmitEffect(&effect);
      }
      if ((field000a == 2) && (field000c == 0)) {
        effect.type = 4;
        effect.x = (double)(int)field0020;
        effect.y = (double)(int)field0028;
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
        effect.x = (double)(int)field0020;
        effect.y = (double)(int)field0028;
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
        effect.x = (double)(int)field0020;
        effect.y = (double)(int)field0028;
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
      if ((field000a == 0) && (field000c == 0)) {
        field3138 = (int)(field0030 * 100.0);
        field313c = (int)(field0038 * 100.0);
        field0030 = 0.0;
        field0038 = 0.0;
        if (field0048 == 0.0) {
          field0048 = 0.035;
        }
        field014e = 0;
        field00b8 = 0.0;
        field014c = 0x3c;
      }
      if (((short)field014c == 0) && (field3140 == 0)) {
        field3140 = field3140 + 1;
        field0030 = (double)field3138 * 0.01;
        field0038 = (double)field313c * 0.01;
      }
      if ((short)field014c == 0) {
        field0038 = field0038 + field0048;
      }
      if (field0038 + field0028 <= 0.0) {
        ++field000c;
        if ((unsigned short)field000c >= frameDuration) {
          field000c = 0;
          ++field000a;
          if (field000a >= frameCount) {
            field0008 = 9;
            ResetPose();
          }
        }
      }
      else {
        ResetFrame();
        field0028 = 0.0;
        field0008 = 0xa9;
      }
      break;
    case 171:
      if ((field000a == 0) && (field000c == 0)) {
        field3138 = (int)(field0030 * 100.0);
        field313c = (int)(field0038 * 100.0);
        field0030 = 0.0;
        field0038 = 0.0;
        if ((char)field0120 == '\x01') {
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
        effect.x = (double)(int)field0020;
        effect.y = (double)(int)field0028;
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
      }
      if ((inputY == -1) && (field000a > 0)) {
        field0008 = 4;
        if ((char)inputX == (char)facing) {
          field0008 = 5;
        }
        if ((int)(char)inputX == -(int)(char)facing) {
          field0008 = 6;
        }
        field0168 = 0;
        ResetPose();
        return;
      }
      else {
        ++field000c;
        if ((unsigned short)field000c >= frameDuration) {
          field000c = 0;
          ++field000a;
          if (field000a >= frameCount) {
            field0008 = 7;
            ResetPose();
            return;
          }
        }
        return;
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
      if ((unsigned short)field000c >= frameDuration) {
        field000c = 0;
        ++field000a;
        if (field000a == 1) {
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
      if ((char)field0158 == '\0') {
        field0030 = 0.0;
        field0038 = 0.0;
      }
      if ((field0030 <= 0.0) || ((char)field0158 != '\x01')) {
        field0030 = 0.0;
        field0158 = 0;
      }
      else {
        field0030 = field0030 - 0.03;
      }
      if ((((inputY == -1) && (field000a > 0)) &&
          (field015c < 3)) && (1 < field0168)) {
        field0008 = 4;
        if ((char)inputX == (char)facing) {
          field0008 = 5;
        }
        if ((int)(char)inputX == -(int)(char)facing) {
          field0008 = 6;
        }
        field0168 = 0;
        ResetPose();
      }
      else {
        if ((field000a == 2) && (field000c == 0)) {
          field0148 = (short)field0148 + 5;
          field02c9 = 0x15;
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
      }
      break;
    case 201:
      if ((char)field0158 == '\0') {
        field0030 = 0.0;
        field0038 = 0.0;
      }
      if ((field0030 <= 0.0) || ((char)field0158 != '\x01')) {
        field0030 = 0.0;
        field0158 = 0;
      }
      else {
        field0030 = field0030 - 0.03;
      }
      if ((((inputY == -1) && (field000a > 0)) &&
          (field015c < 3)) && (1 < field0168)) {
        field0008 = 4;
        if ((char)inputX == (char)facing) {
          field0008 = 5;
        }
        if ((int)(char)inputX == -(int)(char)facing) {
          field0008 = 6;
        }
        field0168 = 0;
        ResetPose();
      }
      else {
        if ((field000a == 1) && (field000c == 0)) {
          field0148 = (short)field0148 + 0xf;
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
      }
      break;
    case 202:
      if ((char)field0158 == '\0') {
        field0030 = 0.0;
        field0038 = 0.0;
      }
      if ((field0030 <= 0.0) || ((char)field0158 != '\x01')) {
        field0030 = 0.0;
        field0158 = 0;
      }
      else {
        field0030 = field0030 - 0.03;
      }
      if ((field000a == 3) && (field000c == 0)) {
        field0148 = (short)field0148 + 0xf;
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
        if (field000a == 4) {
          field02c8 = 0;
          effect.type = 0x19d;
          effect.x = (double)((int)field0020 + (char)facing * 0x22);
          effect.y = (double)((int)field0028 + -0x1f);
          effect.flag0018 = (char)facing;
          effect.layer = 1;
          effect.group = 2;
          EmitLocalEffect(&effect);
        }
        if (field000a >= frameCount) {
          field0008 = 0;
          FaceOpponent();
          ResetPose();
        }
      }
      break;
    case 203:
      if ((char)field0158 == '\0') {
        field0030 = 0.0;
        field0038 = 0.0;
      }
      if ((field0030 <= 0.0) || ((char)field0158 != '\x01')) {
        field0030 = 0.0;
        field0158 = 0;
      }
      else {
        field0030 = field0030 - 0.06;
      }
      if ((field000a == 0) && (field000c == 0)) {
        field016c = 1;
      }
      if (((field000a == 10) && ((char)buttonPulse[2] == '\x01')) &&
         (field3138 < 2)) {
        field02c8 = 0;
        field000c = 0;
        field000a = 6;
        field02c8 = 0;
        field0168 = 0;
        field016c = 1;
        field0148 = (short)field0148 + 0xf;
        field3138 = field3138 + 1;
        effect.type = 400;
        effect.x = (double)((int)field0020 + (char)facing * 0x5a);
        effect.y = (double)((int)field0028 + -0x32);
        effect.flag0018 = (char)facing;
        effect.layer = 1;
        effect.group = 2;
        EmitLocalEffect(&effect);
      }
      ++field000c;
      if ((unsigned short)field000c >= frameDuration) {
        field000c = 0;
        ++field000a;
        if (field000a < 7) {
          field0168 = 0;
        }
        if (field000a == 6) {
          field016c = 1;
          field02c8 = 0;
          effect.type = 400;
          effect.x = (double)((int)field0020 + (char)facing * 0x5a);
          effect.y = (double)((int)field0028 + -0x32);
          effect.flag0018 = (char)facing;
          effect.layer = 1;
          effect.group = 2;
          EmitLocalEffect(&effect);
        }
        if (field000a >= frameCount) {
          field0008 = 0;
          FaceOpponent();
          ResetPose();
        }
      }
      break;
    case 204:
      if ((char)field0158 == '\0') {
        field0030 = 0.0;
        field0038 = 0.0;
      }
      if ((field0030 <= 0.0) || ((char)field0158 != '\x01')) {
        field0030 = 0.0;
        field0158 = 0;
      }
      else {
        field0030 = field0030 - 0.03;
      }
      if ((((inputY == -1) && (field000a > 0)) &&
          (field015c < 3)) && (1 < field0168)) {
        field0008 = 4;
        if ((char)inputX == (char)facing) {
          field0008 = 5;
        }
        if ((int)(char)inputX == -(int)(char)facing) {
          field0008 = 6;
        }
        field0168 = 0;
        ResetPose();
      }
      else {
        if ((field000a == 1) && (field000c == 0)) {
          field0148 = (short)field0148 + 5;
          field02c9 = 0x15;
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
      }
      break;
    case 205:
      if ((char)field0158 == '\0') {
        field0030 = 0.0;
        field0038 = 0.0;
      }
      if ((field0030 <= 0.0) || ((char)field0158 != '\x01')) {
        field0030 = 0.0;
        field0158 = 0;
      }
      else {
        field0030 = field0030 - 0.03;
      }
      if ((((inputY == -1) && (field000a > 0)) &&
          (field015c < 3)) && (1 < field0168)) {
        field0008 = 4;
        if ((char)inputX == (char)facing) {
          field0008 = 5;
        }
        if ((int)(char)inputX == -(int)(char)facing) {
          field0008 = 6;
        }
        field0168 = 0;
        ResetPose();
      }
      else {
        if ((field000a == 2) && (field000c == 0)) {
          field0148 = (short)field0148 + 0xd;
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
      }
      break;
    case 206:
      if (field000a < 2) {
        if ((char)field0158 == '\0') {
          field0030 = 0.0;
          field0038 = 0.0;
        }
        if ((field0030 <= 0.0) || ((char)field0158 != '\x01')) {
          field0030 = 0.0;
          field0158 = 0;
        }
        else {
          field0030 = field0030 - 0.03;
        }
      }
      if (0.0 < field0030) {
        field0158 = 0;
        field0030 = field0030 - 0.02;
        if (field0030 < 0.0) {
          field0030 = 0.0;
        }
      }
      if ((field000a == 2) && (field000c == 0)) {
        field0148 = (short)field0148 + 0x19;
        field02c9 = 0x14;
        field016c = 1;
      }
      ++field000c;
      if ((unsigned short)field000c >= frameDuration) {
        field000c = 0;
        ++field000a;
        if (field000a == 1) {
          field0168 = 0;
        }
        if (field000a == 2) {
          field0030 = 1.9;
        }
        if ((field000a == 6) && (field3138 < 4)) {
          field000a = field000a + -3;
          field3138 = field3138 + 1;
          if (2 < field3138) {
            field016c = 0;
          }
        }
        if (field000a >= frameCount) {
          field0008 = 3;
          FaceOpponent();
          ResetPose();
        }
      }
      break;
    case 207:
      field0038 = field0038 + field0048;
      if (((inputY == -1) && (field000a > 0)) &&
         ((field015c < 3 && ((field0168 >= 2 && (field015a == '\0')))))
         ) {
        ++field015a;
        field0008 = 0xe;
        if ((char)inputX == (char)facing) {
          field0008 = 0xf;
        }
        if ((int)(char)inputX == -(int)(char)facing) {
          field0008 = 0x10;
        }
        field0168 = 0;
        ResetPose();
      }
      else {
        if ((field000a == 2) && (field000c == 0)) {
          field0148 = (short)field0148 + 5;
          field02c9 = 0x15;
          field016c = 1;
        }
        if (field0028 + field0038 >= 0.0) {
          field0028 = 0.0;
          field0008 = 0xd;
          ResetPose();
          break;
        } else {
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
        if ((char)inputX == (char)facing) {
          field0008 = 0xf;
        }
        if ((int)(char)inputX == -(int)(char)facing) {
          field0008 = 0x10;
        }
        field0168 = 0;
        ResetPose();
      }
      else {
        if ((field000a == 3) && (field000c == 0)) {
          field0148 = (short)field0148 + 0xd;
          field02c9 = 0x14;
          field016c = 1;
        }
        if (field0028 + field0038 >= 0.0) {
          field0028 = 0.0;
          field0008 = 0xd;
          ResetPose();
          break;
        } else {
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
        if ((char)inputX == (char)facing) {
          field0008 = 0xf;
        }
        if ((int)(char)inputX == -(int)(char)facing) {
          field0008 = 0x10;
        }
        field0168 = 0;
        ResetPose();
      }
      else {
        if ((4 < field000a) &&
           (((char)buttonPulse[2] == '\x01' && (field3138 < 2)))) {
          field000c = 0;
          field000a = 3;
          field3138 = field3138 + 1;
          field0168 = 0;
        }
        if (field0028 + field0038 >= 0.0) {
          field0028 = 0.0;
          field0008 = 0xd;
          ResetPose();
        } else {
          ++field000c;
          if ((unsigned short)field000c >= frameDuration) {
            field000c = 0;
            ++field000a;
            if (field000a == 4) {
              field0148 = (short)field0148 + 0xf;
              field02c9 = 0x14;
              field016c = 1;
              field02c8 = 0;
              effect.type = 0x191;
              effect.x = (double)((int)field0020 + (char)facing * 0x1b);
              effect.y = (double)((int)field0028 + -0x1c);
              effect.flag0018 = (char)facing;
              effect.layer = 1;
              effect.group = 2;
              EmitLocalEffect(&effect);
            }
            if (field000a < 2) {
              field0168 = 0;
            }
            if (field000a >= frameCount) {
              field000a = field000a + -2;
            }
          }
        }
      }
      break;
    case 210:
      if ((field000a == 0) && (field000c == 0)) {
        field0158 = 0;
        ResetFrame();
      }
      if ((field000a == 3) && (field000c == 0)) {
        field0030 = 0.6;
        field0038 = -1.4;
        field0048 = 0.036;
      }
      if ((field000a == 6) && (field000c == 0)) {
        field0148 = (short)field0148 + 0x14;
        field02c9 = 0x14;
        field016c = 1;
      }
      if (2 < field000a) {
        field0038 = field0038 + field0048;
      }
      if (((field0028 + field0038 > 0.0) && (field000a < 9)) && (field000a > 3)) {
        field0028 = 0.0;
        ResetFrame();
        field000c = 0;
        field000a = 9;
        break;
      } else {
        ++field000c;
        if ((unsigned short)field000c >= frameDuration) {
          field000c = 0;
          ++field000a;
          if (field000a < 2) {
            field0168 = 0;
          }
          if (field000a >= frameCount) {
            field0008 = 3;
            FaceOpponent();
            ResetPose();
          }
          break;
        }
      }
    case 211:
      field0038 = field0038 + field0048;
      if ((((inputY == -1) && (field000a > 0)) &&
          (field015c < 3)) && ((field0168 >= 2 && (field015a == '\0')))
         ) {
        ++field015a;
        field0008 = 0xe;
        if ((char)inputX == (char)facing) {
          field0008 = 0xf;
        }
        if ((int)(char)inputX == -(int)(char)facing) {
          field0008 = 0x10;
        }
        field0168 = 0;
        ResetPose();
      }
      else if (field0028 + field0038 >= 0.0) {
        field0028 = 0.0;
        field0008 = 0xd;
        ResetPose();
      } else {
        ++field000c;
        if ((unsigned short)field000c >= frameDuration) {
          field000c = 0;
          ++field000a;
          if (field000a == 5) {
            field0148 = (short)field0148 + 0xf;
            field02c9 = 0x14;
            field016c = 1;
            field02c8 = 0;
            effect.type = 400;
            effect.x = (double)((int)field0020 + (char)facing * 0x2d);
            effect.y = (double)((int)field0028 + -0x3e);
            effect.flag0018 = (char)facing;
            effect.layer = 1;
            effect.group = 2;
            EmitLocalEffect(&effect);
          }
          if (field000a < 2) {
            field0168 = 0;
          }
          if (field000a >= frameCount) {
            field000a = field000a + -2;
          }
        }
      }
      break;
    case 212:
      field0038 = field0038 + field0048;
      if ((field000a == 0) && (field000c == 0)) {
        field0148 = (short)field0148 + 0x1e;
        field02c9 = 0x14;
        field016c = 1;
        field0030 = field0030 / 2.0;
        field0048 = 0.07;
      }
      if (field0168 < 2) {
        if (field0028 + field0038 < 0.0) {
          field0028 = 0.0;
          field0038 = 0.0;
          SetVerticalShake(3,0);
          effect.type = 3;
          effect.x = (double)(int)field0020;
          effect.y = (double)(int)field0028;
          effect.group = 2;
          effect.layer = 0;
          effect.palette = 7;
          contextOwner->EmitEffect(&effect);
          field02c9 = 7;
          field0008 = 0xd6;
          ResetPose();
        } else {
          ++field000c;
          if ((unsigned short)field000c >= frameDuration) {
            field000c = 0;
            ++field000a;
            field0168 = 0;
            if (field000a >= frameCount) {
              field000a = field000a + -2;
            }
          }
        }
      } else {
        field0008 = 0xd5;
        ResetPose();
        ResetFrame();
      }
      break;
    case 213:
      field0048 = 0.042;
      field0038 = field0038 + field0048;
      if ((field000a == 0) && (field000c == 0)) {
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
      if ((field000a == 0) && (field000c == 0)) {
        SetVerticalShake(3,0);
        effect.type = 3;
        effect.x = (double)(int)field0020;
        effect.y = (double)(int)field0028;
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
        effect.x = (double)((int)field0020 + (char)facing * 0x19);
        effect.y = (double)((int)field0028 + -0x33);
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
    case 221:
      if ((field000a == 1) && (field000c == 0)) {
        (*opponentSlot)->ResetPose();
        ResetFrame();
        (*opponentSlot)->field0008 = 0x32;
      }
      if (2 < field000a) {
        field0038 = field0038 + field0048;
        field0030 = field0030 - 0.045;
        if (field0030 < 0.0) {
          field0030 = 0.0;
        }
      }
      if (((field000a <= 8) && (field000a >= 3)) && (field0038 + field0028 > 0.0)) {
        field000a = 9;
        field000c = 0;
        field0028 = 0.0;
        (*opponentSlot)->ResetFrame();
      } else {
        ++field000c;
        if ((unsigned short)field000c >= frameDuration) {
          field000c = 0;
          ++field000a;
          field0168 = 0;
          if (field000a == 2) {
            field0030 = 1.5;
            field0038 = -1.6;
            field0048 = 0.05;
            effect.type = 0x1f;
            effect.x = (double)(int)field0020;
            effect.y = 0.0;
            effect.group = 0;
            effect.layer = 0;
            effect.facing = (unsigned int)((char)facing != '\x01');
            contextOwner->EmitEffect(&effect);
          }
          if (field000a == 4) {
            field02c9 = 0x15;
            field016c = 1;
            field0148 = (short)field0148 + 0x1e;
          }
          if (field000a >= frameCount) {
            field0008 = 0;
            ResetPose();
          }
        }
      }
      break;
    case 230:
      StartTrail(3);
      field0158 = 0;
      if (field0030 <= 0.0) {
        field0030 = 0.0;
        field0158 = 0;
      }
      else {
        field0030 = field0030 - 0.03;
      }
      if (field0030 < 0.0) {
        field0030 = 0.0;
      }
      if ((field000a == 0) && (field000c == 0)) {
        field0038 = 0.0;
      }
      if ((field000a == 1) && (field000c == 0)) {
        field0148 = (short)field0148 + 5;
        field02c9 = 0x15;
        field016c = 1;
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
    case 231:
      StartTrail(3);
      field0158 = 0;
      if (field0030 <= 0.0) {
        field0030 = 0.0;
        field0158 = 0;
      }
      else {
        field0030 = field0030 - 0.03;
      }
      if (field0030 < 0.0) {
        field0030 = 0.0;
      }
      if ((field000a == 0) && (field000c == 0)) {
        field0038 = 0.0;
      }
      if ((field000a == 2) && (field000c == 0)) {
        field0148 = (short)field0148 + 10;
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
          ResetPose();
        }
      }
      break;
    case 232:
      field0158 = 0;
      StartTrail(3);
      if ((field000a == 0) && (field000c == 0)) {
        field0040 = 0.0;
        field016c = 1;
      }
      if ((field000a < 3) &&
         (field0030 = field0030 - 0.035,
         field0030 < 0.0)) {
        field0030 = 0.0;
      }
      if ((field000a == 3) && (field000c == 0)) {
        field0148 = (short)field0148 + 0x19;
        field02c9 = 0x14;
      }
      if ((field000a == 3) && (field0038 = field0038 + field0048, field0028 + field0038 > 0.0)) {
        field0028 = 0.0;
        ResetFrame();
        field000c = 0;
        field000a = 4;
      } else {
        ++field000c;
        if ((unsigned short)field000c >= frameDuration) {
          field000c = 0;
          ++field000a;
          if (field000a == 3) {
            field0030 = 1.8;
            field0038 = -1.5;
            field0048 = 0.045;
          }
          if (field000a >= frameCount) {
            field0008 = 0;
            FaceOpponent();
            ResetPose();
          }
        }
      }
      break;
    case 233:
      field0158 = 0;
      StartTrail(3);
      if (field0030 <= 0.0) {
        field0030 = 0.0;
        field0158 = 0;
      }
      else {
        field0030 = field0030 - 0.03;
      }
      if (field0030 < 0.0) {
        field0030 = 0.0;
      }
      if ((field000a == 0) && (field000c == 0)) {
        field0038 = 0.0;
      }
      if ((field000a == 1) && (field000c == 0)) {
        field0148 = (short)field0148 + 5;
        field02c9 = 0x15;
        field016c = 1;
      }
      ++field000c;
      if ((unsigned short)field000c >= frameDuration) {
        field000c = 0;
        ++field000a;
        field0168 = 0;
        if (field000a >= frameCount) {
          field0008 = 3;
          ResetPose();
        }
      }
      break;
    case 234:
      StartTrail(3);
      field0158 = 0;
      if (field0030 <= 0.0) {
        field0030 = 0.0;
        field0158 = 0;
      }
      else {
        field0030 = field0030 - 0.03;
      }
      if (field0030 < 0.0) {
        field0030 = 0.0;
      }
      if ((field000a == 0) && (field000c == 0)) {
        field0038 = 0.0;
      }
      if ((field000a == 2) && (field000c == 0)) {
        field0148 = (short)field0148 + 10;
        field02c9 = 0x14;
        field016c = 1;
      }
      ++field000c;
      if ((unsigned short)field000c >= frameDuration) {
        field000c = 0;
        ++field000a;
        field0168 = 0;
        if (field000a >= frameCount) {
          field0008 = 3;
          ResetPose();
        }
      }
      break;
    case 235:
      field0158 = 0;
      StartTrail(3);
      if ((field000a == 0) && (field000c == 0)) {
        field0040 = 0.0;
        field016c = 1;
      }
      if (field0030 <= 0.0) {
        field0030 = 0.0;
        field0158 = 0;
      }
      else {
        field0030 = field0030 - 0.01;
      }
      if ((field000a == 2) && (field000c == 0)) {
        field0148 = (short)field0148 + 0x19;
        field02c9 = 0x14;
      }
      ++field000c;
      if ((unsigned short)field000c >= frameDuration) {
        field000c = 0;
        ++field000a;
        if (field000a == 1) {
          field0168 = 0;
        }
        if ((field000a == 6) && (field3138 < 4)) {
          field000a = field000a + -3;
          field3138 = field3138 + 1;
          if (2 < field3138) {
            field016c = 0;
          }
        }
        if (field000a >= frameCount) {
          field0008 = 3;
          FaceOpponent();
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
        field000a = 0;
        field000c = 0;
        field0008 = 0xf9;
        (*opponentSlot)->field0008 = 0x6e;
        (*opponentSlot)->field0028 = field0028;
        (*opponentSlot)->field0020 =
             (double)((char)facing * 0x13) + field0020;
      }
      else {
        ++field000c;
        if ((unsigned short)field000c >= frameDuration) {
          field000c = 0;
          ++field000a;
          if (((field000a != 1) ||
              (0.0 <= (*opponentSlot)->field0028)) ||
             ((0x31 < (*opponentSlot)->field0008 &&
              ((*opponentSlot)->field0008 < 0x96)))) {
            field016c = 0;
          }
          else {
            field016c = 1;
          }
          field0168 = 0;
          if (field000a >= frameCount) {
            field0008 = 0xd3;
            field000a = 1;
          }
        }
      }
      break;
    case 249:
      field013e = 0x1e;
      (*opponentSlot)->field013e = 0x1e;
      field0158 = 0;
      if ((field000a == 0) && (field000c == 0)) {
        field0030 = -2.5;
        field0038 = -4.5;
        field0048 = 0.045;
      }
      field0038 = field0038 + field0048;
      if (field000a < 8) {
        field0030 = field0030 + 0.035;
        if (0.0 < field0030) {
          field0030 = 0.0;
        }
        (*opponentSlot)->field0028 = field0028;
        (*opponentSlot)->field0020 =
             (double)((char)facing * 0x13) + field0020;
        if (0.0 < field0038 + field0028) {
          field0028 = 0.0;
          (*opponentSlot)->field0028 = 0.0;
          (*opponentSlot)->field0020 = field0020;
          field000c = 0;
          field000a = 8;
          effect.type = 0;
          effect.palette = 2;
          effect.x = (double)(int)field0020;
          effect.y = (double)(int)field0028;
          effect.group = 2;
          effect.layer = 1;
          contextOwner->EmitEffect(&effect);
          (*opponentSlot)->ResetPose();
          (*opponentSlot)->field0008 = 0x62;
          return;
        }
      }
      if ((field000a == 8) && (field000c == 0)) {
        field014a = 0x3c;
        (*opponentSlot)->field014a = 0x3c;
        ApplyDamage(0x44c, 500.0);
      }
      if ((field000a == 9) && (field000c == 0)) {
        field0038 = -1.5;
        field0030 = -1.3;
        field0048 = 0.035;
      }
      if ((field000a < 10) ||
         (field0028 + field0038 <= 0.0)) {
        ++field000c;
        if ((unsigned short)field000c >= frameDuration) {
          field000c = 0;
          ++field000a;
          field0168 = 0;
          if (field000a == 3) {
            (*opponentSlot)->field0008 = 0x79;
          }
          if (field000a >= frameCount) {
            field000a = field000a + -2;
          }
        }
      }
      else {
        ResetPose();
        ResetFrame();
        field0028 = 0.0;
        field0008 = 0xd;
      }
      break;
    case 250:
      if ((field000a == 0) && (field000c == 0)) {
        field0158 = 0;
        ResetFrame();
        field0148 = (short)field0148 + 0x2d;
      }
      ++field000c;
      if ((unsigned short)field000c >= frameDuration) {
        field000c = 0;
        ++field000a;
        field0168 = 3;
        if (field000a == 3) {
          effect.type = 0x193;
          effect.x = (double)((int)field0020 + (char)facing * 0x17);
          effect.y = (double)((int)field0028 + -0x4c);
          effect.group = 0;
          effect.owner = 1;
          effect.layer = 1;
          effect.flag0018 = (char)facing;
          EmitLocalEffect(&effect);
          field02c9 = 0x15;
          field02c8 = 5;
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
        field0148 = (short)field0148 + 0x2d;
      }
      ++field000c;
      if ((unsigned short)field000c >= frameDuration) {
        field000c = 0;
        ++field000a;
        field0168 = 3;
        if (field000a == 3) {
          effect.type = 0x194;
          effect.x = (double)((int)field0020 + (char)facing * 0x17);
          effect.y = (double)((int)field0028 + -0x4c);
          effect.group = 0;
          effect.owner = 1;
          effect.layer = 1;
          effect.flag0018 = (char)facing;
          EmitLocalEffect(&effect);
          field02c9 = 0x15;
          field02c8 = 5;
        }
        if (field000a >= frameCount) {
          field0008 = 0;
          ResetPose();
        }
      }
      break;
    case 252:
      if ((field000a == 0) && (field000c == 0)) {
        field0158 = 0;
        ResetFrame();
        field0148 = (short)field0148 + 0x2d;
        if ((char)field0120 == '\0') {
          field0118 = field0118 - 500.0;
        }
        else {
          field0118 = field0118 - 250.0;
        }
        effect.type = 0x21;
        effect.palette = 0xb;
        effect.x = (double)(int)field0020;
        effect.y = (double)((int)field0028 + -0x32);
        effect.group = 2;
        effect.layer = 1;
        contextOwner->EmitEffect(&effect);
      }
      if (field000a == 3) {
        effect.type = 0x195;
        effect.x = (double)((int)field0020 + (char)facing * 0x17);
        effect.y = (double)((int)field0028 + -0x4c);
        effect.group = 0;
        effect.owner = 1;
        effect.layer = 1;
        effect.flag0018 = (char)facing;
        EmitLocalEffect(&effect);
        field02c9 = 0x15;
        field02c8 = 5;
      }
      ++field000c;
      if ((unsigned short)field000c >= frameDuration) {
        field000c = 0;
        ++field000a;
        field0168 = 3;
        if (field000a == 3) {
          effect.type = 0x195;
          effect.x = (double)((int)field0020 + (char)facing * 0x17);
          effect.y = (double)((int)field0028 + -0x4c);
          effect.group = 0;
          effect.owner = 1;
          effect.layer = 1;
          effect.flag0018 = (char)facing;
          EmitLocalEffect(&effect);
          field02c9 = 0x15;
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
        ResetFrame();
        field0148 = (short)field0148 + 0x2d;
      }
      ++field000c;
      if ((unsigned short)field000c >= frameDuration) {
        field000c = 0;
        ++field000a;
        field0168 = 3;
        if (field000a == 4) {
          effect.type = 0x196;
          effect.x = (double)((int)field0020 + (char)facing * 0x11);
          effect.y = (double)((int)field0028 + -0x1a);
          effect.group = 0;
          effect.owner = 1;
          effect.layer = 1;
          effect.flag0018 = (char)facing;
          effect.field0028 = 1;
          EmitLocalEffect(&effect);
          field02c9 = 0x15;
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
        ResetFrame();
        field0148 = (short)field0148 + 0x2d;
      }
      ++field000c;
      if ((unsigned short)field000c >= frameDuration) {
        field000c = 0;
        ++field000a;
        field0168 = 3;
        if (field000a == 4) {
          effect.type = 0x197;
          effect.x = (double)((int)field0020 + (char)facing * 0x11);
          effect.y = (double)((int)field0028 + -0x1a);
          effect.group = 0;
          effect.owner = 1;
          effect.layer = 1;
          effect.flag0018 = (char)facing;
          effect.field0028 = 1;
          EmitLocalEffect(&effect);
          field02c9 = 0x15;
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
        ResetFrame();
        field0148 = (short)field0148 + 0x2d;
        if ((char)field0120 == '\0') {
          field0118 = field0118 - 500.0;
        }
        else {
          field0118 = field0118 - 250.0;
        }
        effect.type = 0x21;
        effect.palette = 0xb;
        effect.x = (double)(int)field0020;
        effect.y = (double)((int)field0028 + -0x32);
        effect.group = 2;
        effect.layer = 1;
        contextOwner->EmitEffect(&effect);
      }
      ++field000c;
      if ((unsigned short)field000c >= frameDuration) {
        field000c = 0;
        ++field000a;
        field0168 = 3;
        if (field000a == 4) {
          effect.type = 0x198;
          effect.x = (double)((int)field0020 + (char)facing * 0x11);
          effect.y = (double)((int)field0028 + -0x1a);
          effect.group = 0;
          effect.owner = 1;
          effect.layer = 1;
          effect.flag0018 = (char)facing;
          effect.field0028 = 1;
          EmitLocalEffect(&effect);
          field02c9 = 0x15;
        }
        if (field000a >= frameCount) {
          field0008 = 0;
          ResetPose();
        }
      }
      break;
    case 256:
      if ((field000a == 0) && (field000c == 0)) {
        field0158 = 0;
        ResetFrame();
      }
      if (1 < field000a) {
        field0038 = field0038 + field0048;
        field0030 = field0030 - 0.045;
        if (field0030 < 0.0) {
          field0030 = 0.0;
        }
      }
      if (((field000a <= 7) && (field000a >= 2)) && (field0038 + field0028 > 0.0)) {
        field000a = 8;
        field000c = 0;
        field0028 = 0.0;
        ResetFrame();
      } else {
        ++field000c;
        if ((unsigned short)field000c >= frameDuration) {
          field000c = 0;
          ++field000a;
          if (field000a < 2) {
            field0168 = 0;
          }
          if (field000a == 1) {
            field0030 = 1.5;
            field0038 = -1.5;
            field0048 = 0.05;
            effect.type = 0x1f;
            effect.x = (double)(int)field0020;
            effect.y = 0.0;
            effect.group = 0;
            effect.layer = 0;
            effect.facing = (unsigned int)((char)facing != '\x01');
            contextOwner->EmitEffect(&effect);
          }
          if (field000a == 3) {
            field02c9 = 0x15;
            field016c = 1;
            field0148 = (short)field0148 + 0x1e;
          }
          if (field000a >= frameCount) {
            field0008 = 0;
            ResetPose();
          }
        }
      }
      break;
    case 257:
      if ((field000a == 0) && (field000c == 0)) {
        field0158 = 0;
        ResetFrame();
      }
      if (1 < field000a) {
        field0038 = field0038 + field0048;
        field0030 = field0030 - 0.045;
        if (field0030 < 0.0) {
          field0030 = 0.0;
        }
      }
      if (((field000a <= 7) && (field000a >= 2)) && (field0038 + field0028 > 0.0)) {
        field000a = 8;
        field000c = 0;
        field0028 = 0.0;
        ResetFrame();
      } else {
        ++field000c;
        if ((unsigned short)field000c >= frameDuration) {
          field000c = 0;
          ++field000a;
          if (field000a < 2) {
            field0168 = 0;
          }
          if (field000a == 1) {
            field0030 = 1.5;
            field0038 = -1.8;
            field0048 = 0.05;
            effect.type = 0x1f;
            effect.x = (double)(int)field0020;
            effect.y = 0.0;
            effect.group = 0;
            effect.layer = 0;
            effect.facing = (unsigned int)((char)facing != '\x01');
            contextOwner->EmitEffect(&effect);
          }
          if (field000a == 3) {
            field02c9 = 0x15;
            field016c = 1;
            field0148 = (short)field0148 + 0x1e;
          }
          if (field000a >= frameCount) {
            field0008 = 0;
            ResetPose();
          }
        }
      }
      break;
    case 258:
      if ((field000a == 0) && (field000c == 0)) {
        field0158 = 0;
        ResetFrame();
        if ((char)field0120 == '\0') {
          field0118 = field0118 - 500.0;
        }
        else {
          field0118 = field0118 - 250.0;
        }
        effect.type = 0x21;
        effect.palette = 0xb;
        effect.x = (double)(int)field0020;
        effect.y = (double)((int)field0028 + -0x32);
        effect.group = 2;
        effect.layer = 1;
        contextOwner->EmitEffect(&effect);
      }
      if (1 < field000a) {
        field0038 = field0038 + field0048;
        field0030 = field0030 - 0.045;
        if (field0030 < 0.0) {
          field0030 = 0.0;
        }
      }
      if (((field000a <= 7) && (field000a >= 2)) && (field0038 + field0028 > 0.0)) {
        field000a = 8;
        field000c = 0;
        field0028 = 0.0;
        ResetFrame();
      } else {
        if (((field000a <= 0x12) && (field000a >= 0xd)) && (field0038 + field0028 > 0.0)) {
          field000a = 0x13;
          field000c = 0;
          field0028 = 0.0;
          ResetFrame();
        } else {
          ++field000c;
          if ((unsigned short)field000c >= frameDuration) {
            field000c = 0;
            ++field000a;
            if (field000a < 2) {
              field0168 = 0;
            }
            if (field000a == 1) {
              field0030 = 0.9;
              field0038 = -1.0;
              field0048 = 0.05;
              effect.type = 0x1f;
              effect.x = (double)(int)field0020;
              effect.y = 0.0;
              effect.group = 0;
              effect.layer = 0;
              effect.facing = (unsigned int)((char)facing != '\x01');
              contextOwner->EmitEffect(&effect);
            }
            if (field000a == 3) {
              field02c9 = 0x15;
              field016c = 1;
              field0148 = (short)field0148 + 0x1e;
            }
            if (field000a == 0xc) {
              field0030 = 1.4;
              field0038 = -2.9;
              field0048 = 0.05;
              field0168 = 0;
              effect.type = 0x1f;
              effect.x = (double)(int)field0020;
              effect.y = 0.0;
              effect.group = 0;
              effect.layer = 0;
              effect.facing = (unsigned int)((char)facing != '\x01');
              contextOwner->EmitEffect(&effect);
            }
            if (field000a == 0xd) {
              field02c9 = 0x15;
              field016c = 1;
              field0148 = (short)field0148 + 0x1e;
            }
            if (field000a >= frameCount) {
              field0008 = 0;
              ResetPose();
            }
          }
        }
      }
      break;
    case 259:
      if ((field000a == 0) && (field000c == 0)) {
        field0158 = 0;
        ResetFrame();
      }
      if ((field000a == 4) && (field000c == 0)) {
        effect.type = 0x19a;
        effect.x = (double)((int)field0020 + (char)facing * 0x24);
        effect.y = (double)((int)field0028 + -0x4e);
        effect.flag0018 = (char)facing;
        effect.layer = 1;
        effect.owner = 1;
        effect.group = 2;
        EmitLocalEffect(&effect);
        effect.type = 0x192;
        effect.x = (double)((int)field0020 + (char)facing * 0x24);
        effect.y = (double)((int)field0028 + -0x4e);
        effect.flag0018 = (char)facing;
        effect.layer = 1;
        effect.group = 2;
        EmitLocalEffect(&effect);
        field02c8 = 0;
        field3148 = 1;
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
    case 260:
      if ((field000a == 0) && (field000c == 0)) {
        field0158 = 0;
        ResetFrame();
      }
      if ((field000a == 4) && (field000c == 0)) {
        effect.type = 0x19b;
        effect.x = (double)((int)field0020 + (char)facing * -0x24);
        effect.y = (double)((int)field0028 + -0x4e);
        effect.flag0018 = (char)facing;
        effect.layer = 1;
        effect.owner = 1;
        effect.group = 2;
        EmitLocalEffect(&effect);
        effect.type = 0x192;
        effect.x = (double)((int)field0020 + (char)facing * -0x24);
        effect.y = (double)((int)field0028 + -0x4e);
        effect.flag0018 = -(char)facing;
        effect.layer = 1;
        effect.group = 2;
        EmitLocalEffect(&effect);
        field02c8 = 0;
        field3148 = 1;
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
    case 261:
      if ((field000a == 0) && (field000c == 0)) {
        field0158 = 0;
        ResetFrame();
        if ((char)field0120 == '\0') {
          field0118 = field0118 - 500.0;
        }
        else {
          field0118 = field0118 - 250.0;
        }
        effect.type = 0x21;
        effect.palette = 0xb;
        effect.x = (double)(int)field0020;
        effect.y = (double)((int)field0028 + -0x32);
        effect.group = 2;
        effect.layer = 1;
        contextOwner->EmitEffect(&effect);
      }
      if ((field000a == 4) && (field000c == 0)) {
        effect.type = 0x19c;
        effect.x = (double)((int)field0020 + (char)facing * 0x24);
        effect.y = (double)((int)field0028 + -0x4e);
        effect.owner = 1;
        effect.flag0018 = (char)facing;
        effect.layer = 1;
        effect.group = 2;
        EmitLocalEffect(&effect);
        effect.type = 0x192;
        effect.x = (double)((int)field0020 + (char)facing * 0x24);
        effect.y = (double)((int)field0028 + -0x4e);
        effect.flag0018 = (char)facing;
        effect.layer = 1;
        effect.group = 2;
        EmitLocalEffect(&effect);
        field02c8 = 0;
        field3148 = 1;
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
      if ((field000a == 0) && (field000c == 0)) {
        field0030 = field0030 * 0.25;
        field0038 = field0038 * 0.25;
      }
      ++field000c;
      if ((unsigned short)field000c >= frameDuration) {
        field000c = 0;
        ++field000a;
        field0168 = 3;
        if (field000a == 4) {
          field0148 = (short)field0148 + 0x2d;
          effect.type = 0x196;
          effect.x = (double)((int)field0020 + (char)facing * 0xe);
          effect.y = (double)((int)field0028 + -0x23);
          effect.group = 0;
          effect.owner = 1;
          effect.layer = 1;
          effect.flag0018 = (char)facing;
          effect.field0028 = 1;
          EmitLocalEffect(&effect);
          field02c9 = 0x15;
        }
        if (field000a >= frameCount) {
          field0008 = 9;
          ResetPose();
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
      if (field000a < 5) {
        SetHorizontalShake(0x32,3);
      }
      if (field000a > 0) {
        *reinterpret_cast<short *>(reinterpret_cast<char *>(this) + 0xf2) = 10;
      }
      if (((field000a == 5) && (field000c == 0)) &&
         (field3138 == 0)) {
        effect.type = 0x1a2;
        effect.x = (double)((int)field0020 + (char)facing * 0x4d);
        effect.y = (double)((int)field0028 + -0x2b);
        effect.group = 2;
        effect.owner = 1;
        effect.layer = 1;
        effect.flag0018 = (char)facing;
        EmitLocalEffect(&effect);
      }
      ++field000c;
      if ((unsigned short)field000c >= frameDuration) {
        field000c = 0;
        ++field000a;
        if (field000a == 2) {
          field014c = 0x78;
          field0148 = (short)field0148 + -1000;
          SetTint(0xb0,3);
          effect.type = 0x44;
          effect.palette = 0x13;
          effect.x = (double)((int)field0020 + (char)facing * 0x2f);
          effect.y = (double)((int)field0028 + -0x2b);
          effect.group = 2;
          effect.owner = 1;
          effect.layer = 1;
          contextOwner->EmitEffect(&effect);
        }
        if ((field000a == 5) && (0 < (short)field014c)) {
          field000a = field000a + -3;
        }
        if ((field000a == 8) && (field3138 < 3)) {
          field000a = field000a + -3;
          field3138 = field3138 + 1;
        }
        field0168 = 0;
        if (field000a >= frameCount) {
          field0008 = 0;
          ResetPose();
        }
      }
      break;
    case 301:
      if ((field000a == 0) && (field000c == 0)) {
        field0158 = 0;
        field0030 = 0.0;
        field0038 = 0.0;
        field0048 = 0.0;
      }
      if (field000a < 5) {
        SetHorizontalShake(0x32,3);
      }
      if (field000a > 0) {
        *reinterpret_cast<short *>(reinterpret_cast<char *>(this) + 0xf2) = 10;
      }
      if (((field000a == 5) && (field000c == 0)) &&
         (field3138 == 0)) {
        effect.type = 0x1a3;
        effect.x = (double)((int)field0020 + (char)facing * 0x4d);
        effect.y = (double)((int)field0028 + -0x2b);
        effect.group = 2;
        effect.owner = 1;
        effect.layer = 1;
        effect.flag0018 = (char)facing;
        EmitLocalEffect(&effect);
      }
      ++field000c;
      if ((unsigned short)field000c >= frameDuration) {
        field000c = 0;
        ++field000a;
        if (field000a == 2) {
          field014c = 0x78;
          field0148 = (short)field0148 + -1000;
          SetTint(0xb0,3);
          effect.type = 0x44;
          effect.palette = 0x13;
          effect.x = (double)((int)field0020 + (char)facing * 0x2f);
          effect.y = (double)((int)field0028 + -0x2b);
          effect.group = 2;
          effect.owner = 1;
          effect.layer = 1;
          contextOwner->EmitEffect(&effect);
        }
        if ((field000a == 5) && (0 < (short)field014c)) {
          field000a = field000a + -3;
        }
        if ((field000a == 8) && (field3138 < 3)) {
          field000a = field000a + -3;
          field3138 = field3138 + 1;
        }
        field0168 = 0;
        if (field000a >= frameCount) {
          field0008 = 0;
          ResetPose();
        }
      }
      break;
    case 302:
      if ((field000a == 0) && (field000c == 0)) {
        field0158 = 0;
        field0030 = 0.0;
        field0038 = 0.0;
        field0048 = 0.0;
      }
      if (field000a < 5) {
        SetHorizontalShake(0x32,3);
      }
      if (field000a > 0) {
        *reinterpret_cast<short *>(reinterpret_cast<char *>(this) + 0xf2) = 10;
      }
      if (((field000a == 5) && (field000c == 0)) &&
         (field3138 == 0)) {
        effect.type = 0x1a4;
        effect.x = (double)((int)field0020 + (char)facing * 0x4d);
        effect.y = (double)((int)field0028 + -0x2b);
        effect.group = 2;
        effect.owner = 1;
        effect.layer = 1;
        effect.flag0018 = (char)facing;
        EmitLocalEffect(&effect);
      }
      ++field000c;
      if ((unsigned short)field000c >= frameDuration) {
        field000c = 0;
        ++field000a;
        if (field000a == 2) {
          field014c = 0x78;
          field0148 = (short)field0148 + -1000;
          SetTint(0xb0,3);
          effect.type = 0x44;
          effect.palette = 0x13;
          effect.x = (double)((int)field0020 + (char)facing * 0x2f);
          effect.y = (double)((int)field0028 + -0x2b);
          effect.group = 2;
          effect.owner = 1;
          effect.layer = 1;
          contextOwner->EmitEffect(&effect);
        }
        if ((field000a == 5) && (0 < (short)field014c)) {
          field000a = field000a + -3;
        }
        if ((field000a == 8) && (field3138 < 3)) {
          field000a = field000a + -3;
          field3138 = field3138 + 1;
        }
        field0168 = 0;
        if (field000a >= frameCount) {
          field0008 = 0;
          ResetPose();
        }
      }
      break;
    case 303:
      if ((field000a == 0) && (field000c == 0)) {
        field0158 = 0;
        ResetFrame();
        field016c = 99;
      }
      if ((field000a == 3) && (field000c == 0)) {
        field0038 = -2.4;
        field0030 = -0.4;
        field0048 = 0.029;
        field016c = 99;
      }
      if (field000a == 3) {
        SetHorizontalShake(0x32,3);
      }
      if (0xb < field000a) {
        (*opponentSlot)->SetHorizontalShake(0x32,3);
      }
      if ((field000a == 3) && (field000c == 0)) {
        field014c = 0x78;
        field0148 = (short)field0148 + -1000;
        SetTint(0xb0,3);
        effect.type = 0x44;
        effect.palette = 0x13;
        effect.x = (double)(int)field0020;
        effect.y = (double)((int)field0028 + -0x28);
        effect.group = 2;
        effect.owner = 1;
        effect.layer = 1;
        contextOwner->EmitEffect(&effect);
      }
      if ((field000a == 0xb) && (field000c == 0)) {
        ResetFrame();
      }
      if ((field000a == 0xc) && (field000c == 0)) {
        field0030 = -0.2;
        field0038 = -0.8;
        field0048 = 0.015;
      }
      if ((field000a == 0xe) && (field000c == 0)) {
        effect.type = 3;
        effect.x = (double)(int)(field0020 + facing * (unsigned short)RandomRange(0,0xb4));
        effect.y = 0.0;
        effect.group = 2;
        effect.layer = 1;
        contextOwner->EmitEffect(&effect);
        effect.owner = 1;
        effect.type = 0x19f;
        effect.x = (double)(int)field0020;
        effect.y = 0.0;
        effect.flag0018 = (char)facing;
        effect.group = 2;
        effect.layer = 1;
        EmitLocalEffect(&effect);
        effect.type = 0x191;
        effect.x = (double)((int)field0020 + (char)facing * 0x1b);
        effect.y = (double)((int)field0028 + -0x1c);
        effect.flag0018 = (char)facing;
        effect.layer = 1;
        effect.group = 2;
        EmitLocalEffect(&effect);
        effect.type = 0x1a5;
        effect.x = (double)((int)field0020 + (char)facing * 0x10);
        effect.y = (double)((int)field0028 + -0x2b);
        effect.layer = 1;
        effect.group = 0;
        EmitLocalEffect(&effect);
        effect.x = (double)((int)field0020 + (char)facing * 0x15);
        effect.y = (double)((int)field0028 + -0x33);
        effect.layer = 0;
        EmitLocalEffect(&effect);
        field02c8 = 0;
      }
      if ((field000a == 0x12) && (field000c == 0)) {
        effect.owner = 0;
        effect.type = 3;
        effect.x = (double)(int)(field0020 + facing * (unsigned short)RandomRange(0,0xb4));
        effect.y = 0.0;
        effect.group = 2;
        effect.layer = 1;
        contextOwner->EmitEffect(&effect);
        effect.type = 0x191;
        effect.x = (double)((int)field0020 + (char)facing * 0x1b);
        effect.y = (double)((int)field0028 + -0x1c);
        effect.flag0018 = (char)facing;
        effect.layer = 1;
        effect.group = 2;
        EmitLocalEffect(&effect);
        effect.type = 0x1a5;
        effect.x = (double)((int)field0020 + (char)facing * 0x10);
        effect.y = (double)((int)field0028 + -0x2b);
        effect.layer = 1;
        effect.group = 0;
        EmitLocalEffect(&effect);
        effect.x = (double)((int)field0020 + (char)facing * 0x15);
        effect.y = (double)((int)field0028 + -0x33);
        effect.layer = 0;
        EmitLocalEffect(&effect);
        field02c8 = 0;
      }
      field0038 = field0038 + field0048;
      if ((field000a < 0x14) && (0.15 < field0038)) {
        field0038 = 0.15;
      }
      if (((0xe < field000a) && (field000a < 0x16)) &&
         (field0038 + field0028 > 0.0)) {
        field0028 = 0.0;
        ResetFrame();
        field000a = 0x16;
        field000c = 0;
      }
      ++field000c;
      if ((unsigned short)field000c >= frameDuration) {
        field000c = 0;
        ++field000a;
        field0168 = 0;
        if ((field000a == 0x14) && (field3138 < 8)) {
          field3138 = field3138 + 1;
          field000a = field000a + -3;
        }
        if (field000a == 0x16) {
          field000a = field000a + -2;
        }
        if (field000a >= frameCount) {
          field0008 = 7;
          ResetPose();
        }
      }
      break;
    case 304:
      if ((field000a == 0) && (field000c == 0)) {
        field0158 = 0;
        ResetFrame();
        field016c = 99;
      }
      if ((field000a == 3) && (field000c == 0)) {
        field0038 = -2.4;
        field0030 = -0.4;
        field0048 = 0.029;
        field016c = 99;
      }
      if (field000a == 3) {
        SetHorizontalShake(0x32,3);
      }
      if (0xb < field000a) {
        (*opponentSlot)->SetHorizontalShake(0x32,3);
      }
      if ((field000a == 3) && (field000c == 0)) {
        field014c = 0x78;
        field0148 = (short)field0148 + -2000;
        SetTint(0xb0,3);
        effect.type = 0x45;
        effect.palette = 5;
        effect.x = (double)(int)field0020;
        effect.y = (double)((int)field0028 + -0x28);
        effect.group = 2;
        effect.owner = 1;
        effect.layer = 1;
        contextOwner->EmitEffect(&effect);
      }
      if ((field000a == 0xb) && (field000c == 0)) {
        ResetFrame();
      }
      if ((field000a == 0xc) && (field000c == 0)) {
        field0030 = -0.2;
        field0038 = -0.8;
        field0048 = 0.015;
      }
      if ((field000a == 0xe) && (field000c == 0)) {
        effect.owner = 0;
        effect.type = 3;
        effect.x = (double)(int)(field0020 + facing * (unsigned short)RandomRange(0,0xf0));
        effect.y = 0.0;
        effect.group = 2;
        effect.layer = 1;
        contextOwner->EmitEffect(&effect);
        effect.owner = 1;
        effect.type = 0x1a0;
        effect.x = (double)(int)field0020;
        effect.y = 0.0;
        effect.flag0018 = (char)facing;
        effect.group = 2;
        effect.layer = 1;
        EmitLocalEffect(&effect);
        effect.type = 0x191;
        effect.x = (double)((int)field0020 + (char)facing * 0x1b);
        effect.y = (double)((int)field0028 + -0x1c);
        effect.flag0018 = (char)facing;
        effect.layer = 1;
        effect.group = 2;
        EmitLocalEffect(&effect);
        effect.type = 0x1a5;
        effect.x = (double)((int)field0020 + (char)facing * 0x10);
        effect.y = (double)((int)field0028 + -0x2b);
        effect.layer = 1;
        effect.group = 0;
        EmitLocalEffect(&effect);
        effect.x = (double)((int)field0020 + (char)facing * 0x15);
        effect.y = (double)((int)field0028 + -0x33);
        effect.layer = 0;
        EmitLocalEffect(&effect);
        field02c8 = 0;
      }
      if ((field000a == 0x12) && (field000c == 0)) {
        effect.owner = 0;
        effect.type = 3;
        effect.x = (double)(int)(field0020 + facing * (unsigned short)RandomRange(0,0xf0));
        effect.y = 0.0;
        effect.group = 2;
        effect.layer = 1;
        contextOwner->EmitEffect(&effect);
        effect.type = 0x191;
        effect.x = (double)((int)field0020 + (char)facing * 0x1b);
        effect.y = (double)((int)field0028 + -0x1c);
        effect.flag0018 = (char)facing;
        effect.layer = 1;
        effect.group = 2;
        EmitLocalEffect(&effect);
        effect.type = 0x1a5;
        effect.x = (double)((int)field0020 + (char)facing * 0x10);
        effect.y = (double)((int)field0028 + -0x2b);
        effect.layer = 1;
        effect.group = 0;
        EmitLocalEffect(&effect);
        effect.x = (double)((int)field0020 + (char)facing * 0x15);
        effect.y = (double)((int)field0028 + -0x33);
        effect.layer = 0;
        EmitLocalEffect(&effect);
        field02c8 = 0;
      }
      field0038 = field0038 + field0048;
      if ((field000a < 0x14) && (0.15 < field0038)) {
        field0038 = 0.15;
      }
      if (((0xe < field000a) && (field000a < 0x16)) &&
         (field0038 + field0028 > 0.0)) {
        field0028 = 0.0;
        ResetFrame();
        field000a = 0x16;
        field000c = 0;
      }
      ++field000c;
      if ((unsigned short)field000c >= frameDuration) {
        field000c = 0;
        ++field000a;
        field0168 = 0;
        if ((field000a == 0x14) && (field3138 < 0xf)) {
          field3138 = field3138 + 1;
          field000a = field000a + -3;
        }
        if (field000a == 0x16) {
          field000a = field000a + -2;
        }
        if (field000a >= frameCount) {
          field0008 = 7;
          ResetPose();
        }
      }
      break;
    case 305:
      if ((field000a == 0) && (field000c == 0)) {
        field0158 = 0;
        ResetFrame();
        field016c = 99;
      }
      if ((field000a == 3) && (field000c == 0)) {
        field0038 = -2.4;
        field0030 = -0.4;
        field0048 = 0.029;
        field016c = 99;
      }
      if (field000a == 3) {
        SetHorizontalShake(0x32,3);
      }
      if (0xb < field000a) {
        (*opponentSlot)->SetHorizontalShake(0x32,3);
      }
      if ((field000a == 3) && (field000c == 0)) {
        field014c = 0x78;
        field0148 = (short)field0148 + -3000;
        SetTint(0xb0,3);
        effect.type = 0x46;
        effect.palette = 0x40;
        effect.x = (double)(int)field0020;
        effect.y = (double)((int)field0028 + -0x28);
        effect.group = 2;
        effect.owner = 1;
        effect.layer = 1;
        contextOwner->EmitEffect(&effect);
        field02c9 = 0x25;
      }
      if ((field000a == 0xb) && (field000c == 0)) {
        ResetFrame();
      }
      if (10 < field000a) {
        contextOwner->SetSceneTimer(0xf);
      }
      if ((field000a == 0xc) && (field000c == 0)) {
        field0030 = -0.2;
        field0038 = -0.8;
        field0048 = 0.015;
      }
      if ((field000a == 0xe) && (field000c == 0)) {
        effect.owner = 0;
        effect.type = 3;
        effect.x = (double)(int)(field0020 + facing * (unsigned short)RandomRange(0,0x140));
        effect.y = 0.0;
        effect.group = 2;
        effect.layer = 1;
        contextOwner->EmitEffect(&effect);
        effect.owner = 1;
        effect.type = 0x1a1;
        effect.x = (double)(int)field0020;
        effect.y = 0.0;
        effect.flag0018 = (char)facing;
        effect.group = 2;
        effect.layer = 1;
        EmitLocalEffect(&effect);
        effect.type = 0x191;
        effect.x = (double)((int)field0020 + (char)facing * 0x1b);
        effect.y = (double)((int)field0028 + -0x1c);
        effect.flag0018 = (char)facing;
        effect.layer = 1;
        effect.group = 2;
        EmitLocalEffect(&effect);
        effect.type = 0x1a5;
        effect.x = (double)((int)field0020 + (char)facing * 0x10);
        effect.y = (double)((int)field0028 + -0x2b);
        effect.layer = 1;
        effect.group = 0;
        EmitLocalEffect(&effect);
        effect.x = (double)((int)field0020 + (char)facing * 0x15);
        effect.y = (double)((int)field0028 + -0x33);
        effect.layer = 0;
        EmitLocalEffect(&effect);
        field02c8 = 0;
      }
      if ((field000a == 0x12) && (field000c == 0)) {
        effect.owner = 0;
        effect.type = 3;
        effect.x = (double)(int)(field0020 + facing * (unsigned short)RandomRange(0,0x140));
        effect.y = 0.0;
        effect.group = 2;
        effect.layer = 1;
        contextOwner->EmitEffect(&effect);
        effect.type = 0x191;
        effect.x = (double)((int)field0020 + (char)facing * 0x1b);
        effect.y = (double)((int)field0028 + -0x1c);
        effect.flag0018 = (char)facing;
        effect.layer = 1;
        effect.group = 2;
        EmitLocalEffect(&effect);
        effect.type = 0x1a5;
        effect.x = (double)((int)field0020 + (char)facing * 0x10);
        effect.y = (double)((int)field0028 + -0x2b);
        effect.layer = 1;
        effect.group = 0;
        EmitLocalEffect(&effect);
        effect.x = (double)((int)field0020 + (char)facing * 0x15);
        effect.y = (double)((int)field0028 + -0x33);
        effect.layer = 0;
        EmitLocalEffect(&effect);
        field02c8 = 0;
      }
      field0038 = field0038 + field0048;
      if ((field000a < 0x14) && (0.15 < field0038)) {
        field0038 = 0.15;
      }
      if (((0xe < field000a) && (field000a < 0x16)) &&
         (field0038 + field0028 > 0.0)) {
        field0028 = 0.0;
        ResetFrame();
        field000a = 0x16;
        field000c = 0;
      }
      ++field000c;
      if ((unsigned short)field000c >= frameDuration) {
        field000c = 0;
        ++field000a;
        field0168 = 0;
        if ((field000a == 0x14) && (field3138 < 0x19)) {
          field3138 = field3138 + 1;
          field000a = field000a + -3;
        }
        if (field000a == 0x16) {
          field000a = field000a + -2;
        }
        if (field000a >= frameCount) {
          field0008 = 7;
          ResetPose();
        }
      }
      break;
    case 306:
      field0158 = 0;
      if ((field000a == 0) && (field000c == 0)) {
        if (field3138 == 0) {
          field014c = 0x78;
          field0148 = (short)field0148 + -1000;
          SetTint(0xb0,3);
          effect.type = 0x44;
          effect.palette = 0x13;
          effect.x = (double)((int)field0020 + (char)facing * 5);
          effect.y = (double)((int)field0028 + -0x2b);
          effect.group = 2;
          effect.owner = 1;
          effect.layer = 1;
          contextOwner->EmitEffect(&effect);
          field3138 = field3138 + 1;
          field016c = 5;
        }
        field0030 = 0.0;
        field0038 = 0.0;
        field0048 = 0.0;
      }
      if ((field000a == 4) && (field000c == 0)) {
        effect.type = 0x1a7;
        effect.x = (double)((int)field0020 + (char)facing * 0x2d);
        effect.y = (double)((int)field0028 + -0x2b);
        effect.group = 2;
        effect.owner = 1;
        effect.layer = 0;
        effect.flag0018 = -(char)facing;
        EmitLocalEffect(&effect);
      }
      if (field000a < 5) {
        SetHorizontalShake(0x32,3);
      }
      if (field000a == 5) {
        field0038 = field0038 + 0.01;
      }
      if ((field000a == 5) &&
         (0.0 < field0028 + field0038)) {
        field000a = 6;
        field000c = 0;
        field0028 = 0.0;
        field0038 = 0.0;
      }
      if ((5 < field000a) &&
         (field0030 = field0030 - 0.025,
         field0030 < 0.0)) {
        field0030 = 0.0;
      }
      if (field000a >= 1) {
        *reinterpret_cast<short *>(reinterpret_cast<char *>(this) + 0xf2) = 10;
      }
      ++field000c;
      if ((unsigned short)field000c >= frameDuration) {
        field000c = 0;
        ++field000a;
        if ((field000a == 2) && (field313c < 9)) {
          field000a = field000a - 2;
          field313c = field313c + 1;
        }
        if (field000a == 5) {
          field0030 = 1.9;
          field0038 = -0.4;
          field0020 = (double)((char)facing * 0x1e) + field0020
          ;
          field02c8 = 4;
        }
        if (field000a == 6) {
          --field000a;
        }
        field0168 = 0;
        if (field000a >= frameCount) {
          field0008 = 0;
          ResetPose();
        }
      }
      break;
    case 307:
      field0158 = 0;
      if ((field000a == 0) && (field000c == 0)) {
        if (field3138 == 0) {
          field014c = 0x78;
          field0148 = (short)field0148 + -2000;
          SetTint(0xb0,3);
          effect.type = 0x45;
          effect.palette = 5;
          effect.x = (double)((int)field0020 + (char)facing * 5);
          effect.y = (double)((int)field0028 + -0x2b);
          effect.group = 2;
          effect.owner = 1;
          effect.layer = 1;
          contextOwner->EmitEffect(&effect);
          field3138 = field3138 + 1;
          field016c = 0xc;
        }
        field0030 = 0.0;
        field0038 = 0.0;
        field0048 = 0.0;
      }
      if ((field000a == 4) && (field000c == 0)) {
        effect.type = 0x1a7;
        effect.x = (double)((int)field0020 + (char)facing * 0x2d);
        effect.y = (double)((int)field0028 + -0x2b);
        effect.group = 2;
        effect.owner = 1;
        effect.layer = 0;
        effect.flag0018 = -(char)facing;
        EmitLocalEffect(&effect);
      }
      if (field000a < 5) {
        SetHorizontalShake(0x32,3);
      }
      if (field000a == 5) {
        field0038 = field0038 + 0.01;
      }
      if ((field000a == 5) &&
         (0.0 < field0028 + field0038)) {
        field000a = 6;
        field000c = 0;
        field0028 = 0.0;
        field0038 = 0.0;
      }
      if ((5 < field000a) &&
         (field0030 = field0030 - 0.025,
         field0030 < 0.0)) {
        field0030 = 0.0;
      }
      if (field000a >= 1) {
        *reinterpret_cast<short *>(reinterpret_cast<char *>(this) + 0xf2) = 10;
      }
      ++field000c;
      if ((unsigned short)field000c >= frameDuration) {
        field000c = 0;
        ++field000a;
        if ((field000a == 2) && (field313c < 9)) {
          field000a = field000a - 2;
          field313c = field313c + 1;
        }
        if (field000a == 5) {
          field013c = 3;
          field0030 = 2.3;
          field0038 = -0.65;
          field0020 = (double)((char)facing * 0x1e) + field0020
          ;
          field02c8 = 4;
          effect.type = 0x1f;
          effect.x = (double)(int)field0020;
          effect.y = 0.0;
          effect.group = 0;
          effect.layer = 0;
          effect.facing = (unsigned int)((char)facing != '\x01');
          contextOwner->EmitEffect(&effect);
        }
        if (field000a == 6) {
          --field000a;
        }
        field0168 = 0;
        if (field000a >= frameCount) {
          field0008 = 0;
          ResetPose();
        }
      }
      break;
    case 308:
      field0158 = 0;
      if ((field000a == 0) && (field000c == 0)) {
        if (field3138 == 0) {
          field014c = 0x78;
          field0148 = (short)field0148 + -3000;
          SetTint(0xb0,3);
          effect.type = 0x46;
          effect.palette = 0x40;
          effect.x = (double)((int)field0020 + (char)facing * 5);
          effect.y = (double)((int)field0028 + -0x2b);
          effect.group = 2;
          effect.owner = 1;
          effect.layer = 1;
          contextOwner->EmitEffect(&effect);
          field3138 = field3138 + 1;
          field016c = 0x13;
          field02c9 = 0x25;
        }
        field0030 = 0.0;
        field0038 = 0.0;
        field0048 = 0.0;
      }
      contextOwner->SetSceneTimer(0xf);
      if ((field000a == 5) && (field3140 < 0)) {
        effect.type = 0x1f;
        effect.x = (double)(int)field0020;
        effect.y = 0.0;
        effect.group = 0;
        effect.layer = 0;
        effect.facing = (unsigned int)((char)facing != '\x01');
        contextOwner->EmitEffect(&effect);
        field3140 = 0xc;
      }
      field3140 = field3140 + -1;
      if ((field000a == 4) && (field000c == 0)) {
        effect.type = 0x1a7;
        effect.x = (double)((int)field0020 + (char)facing * 0x2d);
        effect.y = (double)((int)field0028 + -0x2b);
        effect.group = 2;
        effect.owner = 1;
        effect.layer = 0;
        effect.flag0018 = -(char)facing;
        EmitLocalEffect(&effect);
      }
      if (field000a < 5) {
        SetHorizontalShake(0x32,3);
      }
      if (field000a == 5) {
        field0038 = field0038 + 0.01;
      }
      if ((field000a == 5) &&
         (0.0 < field0028 + field0038)) {
        field000a = 6;
        field000c = 0;
        field0028 = 0.0;
        field0038 = 0.0;
      }
      if ((5 < field000a) &&
         (field0030 = field0030 - 0.025,
         field0030 < 0.0)) {
        field0030 = 0.0;
      }
      if (field000a >= 1) {
        *reinterpret_cast<short *>(reinterpret_cast<char *>(this) + 0xf2) = 10;
      }
      ++field000c;
      if ((unsigned short)field000c >= frameDuration) {
        field000c = 0;
        ++field000a;
        if ((field000a == 2) && (field313c < 9)) {
          field000a = field000a - 2;
          field313c = field313c + 1;
        }
        if (field000a == 5) {
          field0030 = 2.5;
          field0038 = -0.8;
          field0020 = (double)((char)facing * 0x1e) + field0020
          ;
          field02c8 = 4;
        }
        if (field000a == 6) {
          --field000a;
        }
        field0168 = 0;
        if (field000a >= frameCount) {
          field0008 = 0;
          ResetPose();
        }
      }
      break;
    case 309:
      field0158 = 0;
      if ((field000a == 0) && (field000c == 0)) {
        field016c = 1;
        field02c9 = 0x25;
        field014c = 0x78;
        field0148 = (short)field0148 + -3000;
        SetTint(0xb0,3);
        effect.type = 0x46;
        effect.palette = 0x40;
        effect.x = (double)((int)field0020 + (char)facing * 5);
        effect.y = (double)((int)field0028 + -0x38);
        effect.group = 2;
        effect.owner = 1;
        effect.layer = 1;
        contextOwner->EmitEffect(&effect);
        field3138 = field3138 + 1;
        field016c = 0x13;
        effect.type = 0x47;
        contextOwner->EmitEffect(&effect);
      }
      contextOwner->SetSceneTimer(0xf);
      field0030 = 0.0;
      field0038 = 0.0;
      field0048 = 0.0;
      (*opponentSlot)->field00d0 = 0;
      field00d0 = 0;
      if ((field313c == 1) && (field000a == 5)) {
        field000a = 6;
        field02c8 = 3;
        field000c = 0;
      }
      else if ((field313c == 2) && (field000a == 5)) {
        ResetPose();
        field0008 = 0x136;
      }
      else {
        if ((8 < field000a) && (field000a < 0xd)) {
          field0108 = field0108 + 0x14;
        }
        if (10000 < field0108) {
          field0108 = 10000;
        }
        ++field000c;
        if ((unsigned short)field000c >= frameDuration) {
          field000c = 0;
          ++field000a;
          if (field000a == 3) {
            effect.type = 0x1a6;
            effect.x = (double)((int)field0020 + (char)facing * 6);
            effect.y = (double)((int)field0028 + -0x50);
            effect.group = 0;
            effect.owner = 1;
            effect.layer = 1;
            effect.flag0018 = (char)facing;
            EmitLocalEffect(&effect);
          }
          if (field000a == 6) {
            field000a = field000a + -1;
          }
          if ((field000a == 0xd) && (field3138 < 2)) {
            field3138 = field3138 + 1;
            field000a = field000a + -2;
          }
          field0168 = 0;
          if (field000a >= frameCount) {
            field0008 = 0;
            ResetPose();
          }
        }
      }
      break;
    case 310:
      field0030 = 0.0;
      field0038 = 0.0;
      field0048 = 0.0;
      ++field000c;
      if ((unsigned short)field000c >= frameDuration) {
        field000c = 0;
        ++field000a;
        if ((field000a == 2) && (field3138 < 8)) {
          field3138 = field3138 + 1;
          field000a = field000a + -2;
        }
        field0168 = 0;
        if (field000a >= frameCount) {
          field0008 = 0;
          ResetPose();
        }
      }
      break;

  }
  return;

}
