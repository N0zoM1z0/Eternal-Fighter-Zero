// Minagi Character21::Slot04 complete native-priority action dispatcher.
// Native vtable 0x00788950, complete function 0x005AA3F0-0x005AD4F8.
// Ordinary C++ with all 105 COFF relocations resolved by the original PE.
#include "CharacterViews.h"

void Character21::Slot04()
{
  if (field0008 < 200) {
    actionBufferedInput = 0;
  }
  if ((int)stateGroupCBufferFrames <= 0) {
    stateGroupCBufferedInput = 0;
  }
  else {
    --stateGroupCBufferFrames;
  }
  if (stateGroupCBufferedInput == '\0') {
    stateGroupCBufferFrames = 0;
  }
  if (((recognizedCommand == 0x34) &&
      (((field0118 >= 500.0 || ('\0' < field0120)) &&
       (1 < (int)attackCollisionResult)))) &&
     (((attackCollisionResult != 6 &&
       ((sequences[field0008].data[field000a].frameFlags & 8) > 0)) &&
      (sequences[field0008].field0002 <=
       sequences[167].field0000)))) {
    ResetPose();
    ClearBufferedButtons();
    field0008 = 0xa7;
    if (positionY < 0.0) {
      field0008 = 0xab;
    }
    return;
  }
  if ((int)field015c < 2) {
    if (((((int)health < 0xd05) && (field3148 != 4)) &&
        ((recognizedCommand == 0x5c &&
         (((meter >= 3000 &&
           ((sequences[field0008].data[field000a].frameFlags & 8) > 0)) &&
          (positionY == 0.0)))))) &&
       (((((field0008 >= 200 && (attackCollisionResult >= 2)) && (attackCollisionResult != 6)) ||
         (field0008 < 200)) &&
        (sequences[field0008].field0002 <=
         sequences[313].field0000)))) {
      ResetPose();
      ClearBufferedButtons();
      field0008 = 0x13b;
      return;
    }
    if ((((recognizedCommand == 0xac) && (positionY == 0.0)
         ) && ((meter >= 3000 &&
               ((sequences[field0008].data[field000a].frameFlags & 8) > 0)))) &&
       (((((field0008 >= 200 && (attackCollisionResult >= 2)) && (attackCollisionResult != 6)) ||
         (field0008 < 200)) &&
        (sequences[field0008].field0002 <=
         sequences[314].field0000)))) {
      ResetPose();
      ClearBufferedButtons();
      field0008 = 0x13a;
      return;
    }
    if (((((positionY == 0.0) &&
          ((recognizedCommand == 0xab || (recognizedCommand == 0xac)))
          ) && (meter >= 2000)) &&
        ((sequences[field0008].data[field000a].frameFlags & 8) > 0)) &&
       (((((field0008 >= 200 && (attackCollisionResult >= 2)) && (attackCollisionResult != 6)) ||
         (field0008 < 200)) &&
        (sequences[field0008].field0002 <=
         sequences[313].field0000)))) {
      ResetPose();
      ClearBufferedButtons();
      field0008 = 0x139;
      return;
    }
    if (((((positionY == 0.0) &&
          (((recognizedCommand == 0xaa || (recognizedCommand == 0xab))
           || (recognizedCommand == 0xac)))) &&
         ((meter >= 1000 &&
          ((sequences[field0008].data[field000a].frameFlags & 8) > 0)))) &&
        (((field0008 >= 200 && ((attackCollisionResult >= 2 && (attackCollisionResult != 6)))) ||
         (field0008 < 200)))) &&
       (sequences[field0008].field0002 <=
        sequences[312].field0000)) {
      ResetPose();
      ClearBufferedButtons();
      field0008 = 0x138;
      return;
    }
    if (((((field3148 != 4) && (recognizedCommand == 0x70)) &&
         (meter >= 3000)) &&
        ((sequences[field0008].data[field000a].frameFlags & 8) > 0)) &&
       (((((field0008 >= 200 && (attackCollisionResult >= 2)) && (attackCollisionResult != 6)) ||
         (field0008 < 200)) &&
        (sequences[field0008].field0002 <=
         sequences[305].field0000)))) {
      ResetPose();
      ClearBufferedButtons();
      field0008 = 0x131;
      if (positionY < 0.0) {
        field0008 = 0x137;
      }
      return;
    }
    if (((field3148 != 4) &&
        ((recognizedCommand == 0x6f || (recognizedCommand == 0x70))))
       && ((meter >= 2000 &&
           ((((sequences[field0008].data[field000a].frameFlags & 8) > 0 &&
             ((((field0008 >= 200 && (attackCollisionResult >= 2)) && (attackCollisionResult != 6)
               ) || (field0008 < 200)))) &&
            (sequences[field0008].field0002 <=
             sequences[304].field0000)))))) {
      ResetPose();
      ClearBufferedButtons();
      field0008 = 0x130;
      if (positionY < 0.0) {
        field0008 = 0x136;
      }
      return;
    }
    if ((((field3148 != 4) &&
         ((((recognizedCommand == 0x6e || (recognizedCommand == 0x6f))
           || (recognizedCommand == 0x70)) &&
          ((meter >= 1000 &&
           ((sequences[field0008].data[field000a].frameFlags & 8) > 0)))))) &&
        (((field0008 >= 200 && ((attackCollisionResult >= 2 && (attackCollisionResult != 6)))) ||
         (field0008 < 200)))) &&
       (sequences[field0008].field0002 <=
        sequences[303].field0000)) {
      ResetPose();
      ClearBufferedButtons();
      field0008 = 0x12f;
      if (positionY < 0.0) {
        field0008 = 0x135;
      }
      return;
    }
    if ((((((field3148 != 4) && (recognizedCommand == 0x66)) &&
          (meter >= 3000)) &&
         ((sequences[field0008].data[field000a].frameFlags & 8) > 0)) &&
        ((((field0008 >= 200 && (attackCollisionResult >= 2)) && (attackCollisionResult != 6)) ||
         (field0008 < 200)))) &&
       (sequences[field0008].field0002 <=
        sequences[302].field0000)) {
      ResetPose();
      ClearBufferedButtons();
      field0008 = 0x12e;
      if (positionY < 0.0) {
        field0008 = 0x134;
      }
      return;
    }
    if (((((field3148 != 4) &&
          ((recognizedCommand == 0x65 || (recognizedCommand == 0x66)))
          ) && ((meter >= 2000 &&
                ((sequences[field0008].data[field000a].frameFlags & 8) > 0)))) &&
        ((((field0008 >= 200 && (attackCollisionResult >= 2)) && (attackCollisionResult != 6)) ||
         (field0008 < 200)))) &&
       (sequences[field0008].field0002 <=
        sequences[301].field0000)) {
      ResetPose();
      ClearBufferedButtons();
      field0008 = 0x12d;
      if (positionY < 0.0) {
        field0008 = 0x133;
      }
      return;
    }
    if (((field3148 != 4) &&
        (((recognizedCommand == 100 || (recognizedCommand == 0x65)) ||
         (recognizedCommand == 0x66)))) &&
       (((meter >= 1000 &&
         ((sequences[field0008].data[field000a].frameFlags & 8) > 0)) &&
        ((((field0008 >= 200 && ((attackCollisionResult >= 2 && (attackCollisionResult != 6)))) ||
          (field0008 < 200)) &&
         (sequences[field0008].field0002 <=
          sequences[300].field0000)))))) {
      ResetPose();
      ClearBufferedButtons();
      field0008 = 300;
      if (positionY < 0.0) {
        field0008 = 0x132;
      }
      return;
    }
    if (((recognizedCommand == 0x52) &&
        ((((field0118 >= 500.0 || ('\0' < field0120)) &&
          ((sequences[field0008].data[field000a].frameFlags & 8) > 0)) &&
         (positionY == 0.0)))) &&
       (((((field0008 >= 200 && (attackCollisionResult >= 2)) && (attackCollisionResult != 6)) ||
         (field0008 < 200)) &&
        ((sequences[field0008].field0002 <=
          sequences[264].field0000 && (field314c == 0)))))) {
      ResetPose();
      ClearBufferedButtons();
      field0008 = 0x108;
      return;
    }
    if (((((recognizedCommand == 0x51) || (recognizedCommand == 0x52))
         && ((sequences[field0008].data[field000a].frameFlags & 8) > 0)) &&
        (positionY == 0.0)) &&
       (((((field0008 >= 200 && (attackCollisionResult >= 2)) && (attackCollisionResult != 6)) ||
         (field0008 < 200)) &&
        ((sequences[field0008].field0002 <=
          sequences[263].field0000 && (field314c == 0)))))) {
      ResetPose();
      ClearBufferedButtons();
      field0008 = 0x107;
      return;
    }
    if ((((recognizedCommand == 0x50) &&
         ((sequences[field0008].data[field000a].frameFlags & 8) > 0)) &&
        (positionY == 0.0)) &&
       (((((field0008 >= 200 && (attackCollisionResult >= 2)) && (attackCollisionResult != 6)) ||
         (field0008 < 200)) &&
        ((sequences[field0008].field0002 <=
          sequences[262].field0000 && (field314c == 0)))))) {
      ResetPose();
      ClearBufferedButtons();
      field0008 = 0x106;
      return;
    }
    if ((((field3148 != 4) && (recognizedCommand == 0x20)) &&
        ((field0118 >= 500.0 || ('\0' < field0120)))) &&
       (((sequences[field0008].data[field000a].frameFlags & 8) > 0 &&
        (((((field0008 >= 200 && (attackCollisionResult >= 2)) && (attackCollisionResult != 6)) ||
          (field0008 < 200)) &&
         (sequences[field0008].field0002 <=
          sequences[261].field0000)))))) {
      ResetPose();
      ClearBufferedButtons();
      field0008 = 0x105;
      if (positionY < 0.0) {
        field0008 = 0x112;
      }
      return;
    }
    if ((((field3148 != 4) &&
         ((recognizedCommand == 0x1f || (recognizedCommand == 0x20))))
        && ((sequences[field0008].data[field000a].frameFlags & 8) > 0)) &&
       (((((field0008 >= 200 && (attackCollisionResult >= 2)) && (attackCollisionResult != 6)) ||
         (field0008 < 200)) &&
        (sequences[field0008].field0002 <=
         sequences[260].field0000)))) {
      ResetPose();
      ClearBufferedButtons();
      field0008 = 0x104;
      if (positionY < 0.0) {
        field0008 = 0x111;
      }
      return;
    }
    if ((((field3148 != 4) && (recognizedCommand == 0x1e)) &&
        ((sequences[field0008].data[field000a].frameFlags & 8) > 0)) &&
       (((((field0008 >= 200 && (attackCollisionResult >= 2)) && (attackCollisionResult != 6)) ||
         (field0008 < 200)) &&
        (sequences[field0008].field0002 <=
         sequences[259].field0000)))) {
      ResetPose();
      ClearBufferedButtons();
      field0008 = 0x103;
      if (positionY < 0.0) {
        field0008 = 0x110;
      }
      return;
    }
    if ((((field3148 != 4) && (positionY == 0.0)) &&
        ((recognizedCommand == 0x16 &&
         (((field0118 >= 500.0 || ('\0' < field0120)) &&
          ((sequences[field0008].data[field000a].frameFlags & 8) > 0)))))) &&
       (((((field0008 >= 200 && (attackCollisionResult >= 2)) && (attackCollisionResult != 6)) ||
         (field0008 < 200)) &&
        (sequences[field0008].field0002 <=
         sequences[277].field0000)))) {
      ResetPose();
      ClearBufferedButtons();
      field0008 = 0x115;
      return;
    }
    if (((field3148 != 4) && (positionY == 0.0)) &&
       (((recognizedCommand == 0x15 || (recognizedCommand == 0x16)) &&
        (((sequences[field0008].data[field000a].frameFlags & 8) > 0 &&
         (((((field0008 >= 200 && (attackCollisionResult >= 2)) && (attackCollisionResult != 6))
           || (field0008 < 200)) &&
          (sequences[field0008].field0002 <=
           sequences[276].field0000)))))))) {
      ResetPose();
      ClearBufferedButtons();
      field0008 = 0x114;
      return;
    }
    if (((((field3148 != 4) && (positionY == 0.0)) &&
         ((recognizedCommand == 0x14 &&
          ((sequences[field0008].data[field000a].frameFlags & 8) > 0)))) &&
        ((((field0008 >= 200 && (attackCollisionResult >= 2)) && (attackCollisionResult != 6)) ||
         (field0008 < 200)))) &&
       (sequences[field0008].field0002 <=
        sequences[275].field0000)) {
      ResetPose();
      ClearBufferedButtons();
      field0008 = 0x113;
      return;
    }
    if (((field3148 != 4) && (recognizedCommand == 0x48)) &&
       ((((field0118 >= 500.0 || ('\0' < field0120)) &&
         ((sequences[field0008].data[field000a].frameFlags & 8) > 0)) &&
        (((((field0008 >= 200 && (attackCollisionResult >= 2)) && (attackCollisionResult != 6)) ||
          (field0008 < 200)) &&
         (sequences[field0008].field0002 <=
          sequences[258].field0000)))))) {
      ResetPose();
      ClearBufferedButtons();
      field0008 = 0x102;
      if (positionY < 0.0) {
        field0008 = 0x10f;
      }
      return;
    }
    if ((((field3148 != 4) &&
         ((recognizedCommand == 0x47 || (recognizedCommand == 0x48))))
        && (((sequences[field0008].data[field000a].frameFlags & 8) > 0 &&
            ((((field0008 >= 200 && (attackCollisionResult >= 2)) && (attackCollisionResult != 6))
             || (field0008 < 200)))))) &&
       (sequences[field0008].field0002 <=
        sequences[257].field0000)) {
      ResetPose();
      ClearBufferedButtons();
      field0008 = 0x101;
      if (positionY < 0.0) {
        field0008 = 0x10e;
      }
      return;
    }
    if ((((field3148 != 4) && (recognizedCommand == 0x46)) &&
        ((sequences[field0008].data[field000a].frameFlags & 8) > 0)) &&
       (((((field0008 >= 200 && (attackCollisionResult >= 2)) && (attackCollisionResult != 6)) ||
         (field0008 < 200)) &&
        (sequences[field0008].field0002 <=
         sequences[256].field0000)))) {
      ResetPose();
      ClearBufferedButtons();
      field0008 = 0x100;
      if (positionY < 0.0) {
        field0008 = 0x10d;
      }
      return;
    }
    if (((field3148 != 4) && (recognizedCommand == 0xc)) &&
       ((((field0118 >= 500.0 || ('\0' < field0120)) &&
         (((sequences[field0008].data[field000a].frameFlags & 8) > 0 &&
          ((((field0008 >= 200 && (attackCollisionResult >= 2)) && (attackCollisionResult != 6))
           || (field0008 < 200)))))) &&
        (sequences[field0008].field0002 <=
         sequences[255].field0000)))) {
      ResetPose();
      ClearBufferedButtons();
      field0008 = 0xff;
      if (positionY < 0.0) {
        field0008 = 0x10b;
      }
      return;
    }
    if ((((field3148 != 4) &&
         ((recognizedCommand == 0xb || (recognizedCommand == 0xc))))
        && ((sequences[field0008].data[field000a].frameFlags & 8) > 0)) &&
       (((((field0008 >= 200 && (attackCollisionResult >= 2)) && (attackCollisionResult != 6)) ||
         (field0008 < 200)) &&
        (sequences[field0008].field0002 <=
         sequences[254].field0000)))) {
      ResetPose();
      ClearBufferedButtons();
      field0008 = 0xfe;
      if (positionY < 0.0) {
        field0008 = 0x10a;
      }
      return;
    }
    if (((((field3148 != 4) && (recognizedCommand == 10)) &&
         ((sequences[field0008].data[field000a].frameFlags & 8) > 0)) &&
        ((((field0008 >= 200 && (attackCollisionResult >= 2)) && (attackCollisionResult != 6)) ||
         (field0008 < 200)))) &&
       (sequences[field0008].field0002 <=
        sequences[253].field0000)) {
      ResetPose();
      ClearBufferedButtons();
      field0008 = 0xfd;
      if (positionY < 0.0) {
        field0008 = 0x109;
      }
      return;
    }
  }
  if (((int)field015c < 1) &&
     ((recognizedCommand == 0 || (recognizedCommand == 1)))) {
    if ((positionY < 0.0) && (airDashCount < 1)) {
      if ((((((((*opponentSlot)->positionX - positionX) * (double)(1 - recognizedCommand * 2) <
               0.0) ||
             ((0.0 == (*opponentSlot)->positionX - positionX
              && ((int)facing == ((1 - recognizedCommand * 2) * -1)))))
            && (sequences[field0008].field0002 <=
                sequences[165].field0000)) &&
           (((field0008 != 0xaa && (positionY < -30.0)) &&
            ((sequences[field0008].data[field000a].frameFlags & 8) > 0)))) &&
          ((((field0008 >= 200 && (attackCollisionResult >= 2)) && (attackCollisionResult != 6))
           || (field0008 < 200)))) && (field0008 != 0xfd)) {
        if (field0008 != 0xa5) {
          ResetPose();
        }
        field0008 = 0xa5;
        FaceOpponent();
        ++airDashCount;
        ++airActionCount;
        actionBufferedInput = 0;
        return;
      }
      if (((((0.0 <
              ((*opponentSlot)->positionX - positionX) * (double)(1 - recognizedCommand * 2)) ||
            ((0.0 == (*opponentSlot)->positionX - positionX
             && ((int)facing == 1 - recognizedCommand * 2)))) &&
           (field0008 != 0xaa)) &&
          ((sequences[field0008].field0002 <=
            sequences[166].field0000 &&
           ((sequences[field0008].data[field000a].frameFlags & 8) > 0)))) &&
         (((field0008 >= 200 && ((attackCollisionResult >= 2 && (attackCollisionResult != 6)))) ||
          (field0008 < 200)))) {
        if (field0008 != 0xa6) {
          ResetPose();
        }
        field0008 = 0xa6;
        FaceOpponent();
        ++airDashCount;
        ++airActionCount;
        actionBufferedInput = 0;
        return;
      }
    }
    if ((positionY == 0.0) &&
       ((sequences[field0008].data[field000a].frameFlags & 8) > 0)) {
      if (((((*opponentSlot)->positionX - positionX) * (double)(1 - recognizedCommand * 2) < 0.0)
          || ((0.0 == (*opponentSlot)->positionX - positionX
              && ((int)facing == ((1 - recognizedCommand * 2) * -1)))))
         && ((sequences[field0008].field0002 <=
              sequences[163].field0000 &&
             ((((field0008 >= 200 && (attackCollisionResult >= 2)) && (attackCollisionResult != 6)
               ) || (field0008 < 200)))))) {
        if (field0008 != 0xa3) {
          ResetPose();
        }
        field0008 = 0xa3;
        FaceOpponent();
        ++dashMomentumFlag;
        actionBufferedInput = 0;
        return;
      }
      if ((((0.0 <
             ((*opponentSlot)->positionX - positionX) * (double)(1 - recognizedCommand * 2)) ||
           ((0.0 == (*opponentSlot)->positionX - positionX
            && ((int)facing == 1 - recognizedCommand * 2)))) &&
          (sequences[field0008].field0002 <=
           sequences[164].field0000)) &&
         ((((field0008 >= 200 && (attackCollisionResult >= 2)) && (attackCollisionResult != 6)) ||
          (field0008 < 200)))) {
        if (field0008 != 0xa4) {
          ResetPose();
        }
        field0008 = 0xa4;
        FaceOpponent();
        ++dashMomentumFlag;
        actionBufferedInput = 0;
        return;
      }
    }
  }
  if (((((((int)field015c < 3) && (recognizedCommand == 6)) &&
        ((sequences[field0008].data[field000a].frameFlags & 8) > 0)) &&
       ((positionY < 0.0 && (airActionCount < 1))))
      && (sequences[field0008].field0002 <=
          sequences[14].field0000)) &&
     ((((field0008 >= 200 && (attackCollisionResult >= 2)) && (attackCollisionResult != 6)) ||
      (field0008 < 200)))) {
    ResetPose();
    ClearBufferedButtons();
    ++airActionCount;
    field0008 = 0xe;
    if (inputX == facing) {
      field0008 = 0xf;
    }
    if ((int)inputX == -(int)facing) {
      field0008 = 0x10;
    }
    return;
  }
  if (((buttonPulse[0] == '\x01') || ((actionBufferedInput & 0x10) != 0)) ||
     ((stateGroupCBufferedInput & 0x10) != 0)) {
    if ((field0008 == 0xa3) &&
       ((int)inputX != -(int)facing)) {
      ResetPose();
      ClearBufferedButtons();
      field0008 = 0xe6;
      if (inputY == 1) {
        field0008 = 0xe9;
      }
      return;
    }
    if (positionY < 0.0) {
      if (sequences[field0008].field0002 <= sequences[207].field0000 &&
          (sequences[field0008].data[field000a].frameFlags & 8) > 0 &&
          ((field0008 >= 200 && attackCollisionResult >= 2 &&
            attackCollisionResult != 6) || field0008 < 200)) {
        ResetPose();
        ClearBufferedButtons();
        field0008 = 0xcf;
      }
      return;
    }
    if (((((inputY == '\x01') || ((actionBufferedInput & 4) != 0)) ||
         ((stateGroupCBufferedInput & 4) != 0)) &&
        ((sequences[field0008].field0002 <=
          sequences[204].field0000 &&
         ((sequences[field0008].data[field000a].frameFlags & 8) > 0)))) &&
       (((field0008 >= 200 && ((attackCollisionResult >= 2 && (attackCollisionResult != 6)))) ||
        (field0008 < 200)))) {
      ResetPose();
      ClearBufferedButtons();
      field0008 = 0xcc;
      return;
    }
    if (((((inputY == '\0') || ((actionBufferedInput & 4) == 0)) ||
         ((stateGroupCBufferedInput & 4) == 0)) &&
        ((sequences[field0008].field0002 <=
          sequences[200].field0000 &&
         ((sequences[field0008].data[field000a].frameFlags & 8) > 0)))) &&
       (((field0008 >= 200 && ((attackCollisionResult >= 2 && (attackCollisionResult != 6)))) ||
        (field0008 < 200)))) {
      ResetPose();
      ClearBufferedButtons();
      field0008 = 200;
      return;
    }
  }
  if (((buttonPulse[1] == '\x01') || ((actionBufferedInput & 0x20) != 0)) ||
     ((stateGroupCBufferedInput & 0x20) != 0)) {
    if ((field0008 == 0xa3) &&
       ((int)inputX != -(int)facing)) {
      ResetPose();
      ClearBufferedButtons();
      field0008 = 0xe7;
      if (inputY == 1) {
        field0008 = 0xea;
      }
      return;
    }
    if (positionY < 0.0) {
      if (sequences[field0008].field0002 <= sequences[208].field0000 &&
          (sequences[field0008].data[field000a].frameFlags & 8) > 0 &&
          ((field0008 >= 200 && attackCollisionResult >= 2 &&
            attackCollisionResult != 6) || field0008 < 200)) {
        ResetPose();
        ClearBufferedButtons();
        field0008 = 0xd0;
      }
      return;
    }
    if (((((inputY == '\x01') || ((actionBufferedInput & 4) != 0)) ||
         ((stateGroupCBufferedInput & 4) != 0)) &&
        ((sequences[field0008].field0002 <=
          sequences[205].field0000 &&
         ((sequences[field0008].data[field000a].frameFlags & 8) > 0)))) &&
       (((field0008 >= 200 && ((attackCollisionResult >= 2 && (attackCollisionResult != 6)))) ||
        (field0008 < 200)))) {
      ResetPose();
      ClearBufferedButtons();
      field0008 = 0xcd;
      return;
    }
    if (((inputY == '\0') || ((actionBufferedInput & 4) == 0)) ||
       ((stateGroupCBufferedInput & 4) == 0)) {
      if ((((sequences[field0008].field0002 <=
             sequences[201].field0000) &&
           ((sequences[field0008].data[field000a].frameFlags & 8) > 0)) &&
          ((-50.0 < positionX - (*opponentSlot)->positionX &&
           (positionX - (*opponentSlot)->positionX < 50.0))))
         && ((((field0008 >= 200 && (attackCollisionResult >= 2)) && (attackCollisionResult != 6))
             || (field0008 < 200)))) {
        ResetPose();
        ClearBufferedButtons();
        field0008 = 0xc9;
        return;
      }
      if (((sequences[field0008].field0002 <=
            sequences[202].field0000) &&
          ((sequences[field0008].data[field000a].frameFlags & 8) > 0)) &&
         (((field0008 >= 200 && ((attackCollisionResult >= 2 && (attackCollisionResult != 6)))) ||
          (field0008 < 200)))) {
        ResetPose();
        ClearBufferedButtons();
        field0008 = 0xca;
        return;
      }
    }
  }
  if (((buttonPulse[2] == '\x01') || ((actionBufferedInput & 0x40) != 0)) ||
     ((stateGroupCBufferedInput & 0x40) != 0)) {
    if ((field0008 == 0xa3) &&
       ((int)inputX != -(int)facing)) {
      ResetPose();
      ClearBufferedButtons();
      field0008 = 0xe8;
      if (inputY == 1) {
        field0008 = 0xeb;
      }
      return;
    }
    if (positionY < 0.0) {
      if ((((inputX == facing) &&
           (inputY == '\0')) &&
          ((-100.0 < positionX - (*opponentSlot)->positionX &&
           (((((positionX - (*opponentSlot)->positionX < 100.0
               && ((*opponentSlot)->positionY < 0.0)) &&
              (sequences[field0008].field0002 <=
               sequences[248].field0000)) &&
             (((*opponentSlot)->field0008 < 0x32 ||
              (0x9c < (*opponentSlot)->field0008)))) &&
            ((sequences[field0008].data[field000a].frameFlags & 8) > 0)))))) &&
         ((((field0008 >= 200 && (attackCollisionResult >= 2)) && (attackCollisionResult != 6)) ||
          (field0008 < 200)))) {
        ResetPose();
        ClearBufferedButtons();
        field0008 = 0xf8;
        return;
      }
      if (sequences[field0008].field0002 <= sequences[209].field0000 &&
          (sequences[field0008].data[field000a].frameFlags & 8) > 0 &&
          ((field0008 >= 200 && attackCollisionResult >= 2 &&
            attackCollisionResult != 6) || field0008 < 200)) {
        ResetPose();
        ClearBufferedButtons();
        field0008 = 0xd1;
      }
      return;
    }
    if (((((inputY == '\x01') || ((actionBufferedInput & 4) != 0)) ||
         ((stateGroupCBufferedInput & 4) != 0)) &&
        ((sequences[field0008].field0002 <=
          sequences[206].field0000 &&
         ((sequences[field0008].data[field000a].frameFlags & 8) > 0)))) &&
       (((field0008 >= 200 && ((attackCollisionResult >= 2 && (attackCollisionResult != 6)))) ||
        (field0008 < 200)))) {
      ResetPose();
      ClearBufferedButtons();
      field0008 = 0xce;
      return;
    }
    if (((inputY == '\0') || ((actionBufferedInput & 4) == 0)) ||
       ((stateGroupCBufferedInput & 4) == 0)) {
      if ((((*opponentSlot)->positionY == 0.0) &&
          (inputX != '\0')) &&
         ((((-30.0 < positionX - (*opponentSlot)->positionX &&
            ((positionX - (*opponentSlot)->positionX < 30.0
             && (sequences[field0008].field0002 <=
                 sequences[220].field0000)))) &&
           (((*opponentSlot)->field0008 < 0x32 ||
            (0x9c < (*opponentSlot)->field0008)))) &&
          (((sequences[field0008].data[field000a].frameFlags & 8) > 0 &&
           ((((field0008 >= 200 && (attackCollisionResult >= 2)) && (attackCollisionResult != 6))
            || (field0008 < 200)))))))) {
        ResetPose();
        ClearBufferedButtons();
        field0008 = 0xdc;
        return;
      }
      if (((sequences[field0008].field0002 <=
            sequences[203].field0000) &&
          ((sequences[field0008].data[field000a].frameFlags & 8) > 0)) &&
         (((field0008 >= 200 && ((attackCollisionResult >= 2 && (attackCollisionResult != 6)))) ||
          (field0008 < 200)))) {
        ResetPose();
        ClearBufferedButtons();
        field0008 = 0xcb;
        return;
      }
    }
  }
  if (((((int)field015c < 2) &&
       (((buttonPulse[3] == '\x01' || ((actionBufferedInput & 0x80) != 0)) ||
        ((stateGroupCBufferedInput & 0x80) != 0)))) &&
      (((sequences[field0008].field0002 <=
         sequences[250].field0000 &&
        ((sequences[field0008].data[field000a].frameFlags & 8) > 0)) &&
       (positionY == 0.0)))) &&
     ((((field0008 >= 200 && (attackCollisionResult >= 2)) && (attackCollisionResult != 6)) ||
      (field0008 < 200)))) {
    if ((((field3148 == 0) || (field3148 == 2)) || (field3148 == 3)) &&
       (inputX == '\0')) {
      ResetPose();
      ClearBufferedButtons();
      field0008 = 0xfa;
    }
    else if ((field3148 == 0) && (inputX == '\x01')) {
      ResetPose();
      ClearBufferedButtons();
      field0008 = 0xfb;
    }
    else if ((field3148 == 0) && (inputX == -1)) {
      ResetPose();
      ClearBufferedButtons();
      field0008 = 0xfc;
    }
  }
  return;
}
