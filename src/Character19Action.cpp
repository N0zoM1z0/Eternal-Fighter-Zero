// Kanna's command-, animation- and buffered-action dispatch.
// Native virtual owner: Character19::Slot04, 0x006763C0.
#include "CharacterViews.h"

void Character19::Slot04()
{
    if (field0008 < 200) {
        actionBufferedInput = 0;
    }
    if (stateGroupCBufferFrames <= 0) {
        stateGroupCBufferedInput = 0;
    } else {
        --stateGroupCBufferFrames;
    }
    if (stateGroupCBufferedInput == 0) {
        stateGroupCBufferFrames = 0;
    }

    if ((recognizedCommand == 0x34) &&
        (((field0118 >= 500.0 || field0120 > 0) &&
          (attackCollisionResult > 1 && attackCollisionResult != 6) &&
          ((sequences[field0008].data[field000a].frameFlags & 8) > 0)) &&
         (sequences[field0008].field0002 <= sequences[167].field0000))) {
        ResetPose();
        ClearBufferedButtons();
        field0008 = 0xa7;
        if (positionY < 0.0) {
            field0008 = 0xab;
        }
        return;
    }

    if (field015c < 2) {
        if (((((recognizedCommand == 0x66) && (meter >= 3000)) && (health < 0xd05)) &&
             (((sequences[field0008].data[field000a].frameFlags & 8) > 0) &&
              (positionY == 0.0))) &&
            ((((field0008 >= 200 && (attackCollisionResult >= 2 && attackCollisionResult != 6)) ||
               (field0008 < 200)) &&
              (sequences[field0008].field0002 <= sequences[309].field0000)))) {
            ResetPose();
            ClearBufferedButtons();
            field0008 = 0x135;
            return;
        }
        if (((((recognizedCommand == 0x65) && (meter >= 3000)) && (positionY < 0.0)) &&
             ((sequences[field0008].data[field000a].frameFlags & 8) > 0)) &&
            ((((field0008 >= 200 && (attackCollisionResult >= 2 && attackCollisionResult != 6)) ||
               (field0008 < 200)) &&
              (sequences[field0008].field0002 <= sequences[306].field0000)))) {
            ResetPose();
            ClearBufferedButtons();
            field0008 = 0x132;
            return;
        }
        if (((((recognizedCommand == 100) && (meter >= 3000)) &&
              ((sequences[field0008].data[field000a].frameFlags & 8) > 0)) &&
             (((field0008 >= 200 && (attackCollisionResult >= 2 && attackCollisionResult != 6)) ||
               (field0008 < 200)) &&
              (sequences[field0008].field0002 <= sequences[300].field0000)))) {
            ResetPose();
            ClearBufferedButtons();
            field0008 = 300;
            return;
        }
        if (((((recognizedCommand == 0x65) && (meter >= 3000)) &&
              (positionY == 0.0)) &&
             ((sequences[field0008].data[field000a].frameFlags & 8) > 0)) &&
            (((field0008 >= 200 && (attackCollisionResult >= 2 && attackCollisionResult != 6)) ||
              (field0008 < 200)) &&
             (sequences[field0008].field0002 <= sequences[303].field0000))) {
            ResetPose();
            ClearBufferedButtons();
            field0008 = 0x12f;
            return;
        }
        if (((recognizedCommand == 0x48) &&
             (((field0118 >= 500.0 || field0120 > 0) &&
               ((sequences[field0008].data[field000a].frameFlags & 8) > 0)) &&
              (positionY == 0.0))) &&
            (((field0008 >= 200 && (attackCollisionResult >= 2 && attackCollisionResult != 6)) ||
              (field0008 < 200)) &&
             (sequences[field0008].field0002 <= sequences[267].field0000))) {
            ResetPose();
            ClearBufferedButtons();
            field0008 = 0x10b;
            return;
        }
        if (((((recognizedCommand == 0x47) || (recognizedCommand == 0x48)) &&
              ((sequences[field0008].data[field000a].frameFlags & 8) > 0)) &&
             (positionY == 0.0)) &&
            (((field0008 >= 200 && (attackCollisionResult >= 2 && attackCollisionResult != 6)) ||
              (field0008 < 200)) &&
             (sequences[field0008].field0002 <= sequences[266].field0000))) {
            ResetPose();
            ClearBufferedButtons();
            field0008 = 0x10a;
            return;
        }
        if (((recognizedCommand == 0x46) &&
             ((sequences[field0008].data[field000a].frameFlags & 8) > 0)) &&
            (positionY == 0.0) &&
            (((field0008 >= 200 && (attackCollisionResult >= 2 && attackCollisionResult != 6)) ||
              (field0008 < 200)) &&
             (sequences[field0008].field0002 <= sequences[266].field0000))) {
            ResetPose();
            ClearBufferedButtons();
            field0008 = 0x10a;
            return;
        }
        if (((((recognizedCommand == 0x16) &&
               (field0118 >= 500.0 || field0120 > 0)) &&
              ((sequences[field0008].data[field000a].frameFlags & 8) > 0)) &&
             (positionY == 0.0)) &&
            (((field0008 >= 200 && (attackCollisionResult >= 2 && attackCollisionResult != 6)) ||
              (field0008 < 200)) &&
             (sequences[field0008].field0002 <= sequences[257].field0000))) {
            ResetPose();
            ClearBufferedButtons();
            field0008 = 0x101;
            return;
        }
        if (((((recognizedCommand == 0x14) || (recognizedCommand == 0x15)) ||
              (recognizedCommand == 0x16)) &&
             (((sequences[field0008].data[field000a].frameFlags & 8) > 0) &&
              (positionY == 0.0))) &&
            (((field0008 >= 200 && (attackCollisionResult >= 2 && attackCollisionResult != 6)) ||
              (field0008 < 200)) &&
             (sequences[field0008].field0002 <= sequences[256].field0000))) {
            ResetPose();
            ClearBufferedButtons();
            field0008 = 0x100;
            return;
        }
        if (((((recognizedCommand == 0x20) && (positionY == 0.0)) &&
              ((sequences[field0008].data[field000a].frameFlags & 8) > 0)) &&
             (((field0008 >= 200 && (attackCollisionResult >= 2 && attackCollisionResult != 6)) ||
               (field0008 < 200)) &&
              (sequences[field0008].field0002 <= sequences[265].field0000)))) {
            ResetPose();
            ClearBufferedButtons();
            field0008 = 0x109;
            return;
        }
        if (((((recognizedCommand == 0x1f) &&
               (positionY == 0.0)) &&
              ((sequences[field0008].data[field000a].frameFlags & 8) > 0)) &&
             (((field0008 >= 200 && (attackCollisionResult >= 2 && attackCollisionResult != 6)) ||
               (field0008 < 200)) &&
              (sequences[field0008].field0002 <= sequences[264].field0000)))) {
            ResetPose();
            ClearBufferedButtons();
            field0008 = 0x108;
            return;
        }
        if (((((recognizedCommand == 0x1e) &&
               (positionY == 0.0)) &&
              ((sequences[field0008].data[field000a].frameFlags & 8) > 0)) &&
             (((field0008 >= 200 && (attackCollisionResult >= 2 && attackCollisionResult != 6)) ||
               (field0008 < 200)) &&
              (sequences[field0008].field0002 <= sequences[263].field0000)))) {
            ResetPose();
            ClearBufferedButtons();
            field0008 = 0x107;
            return;
        }
        if (((((recognizedCommand == 0xc) &&
               (field0118 >= 500.0 || field0120 > 0)) &&
              ((sequences[field0008].data[field000a].frameFlags & 8) > 0)) &&
             (positionY == 0.0)) &&
            (((field0008 >= 200 && (attackCollisionResult >= 2 && attackCollisionResult != 6)) ||
              (field0008 < 200)) &&
             (sequences[field0008].field0002 <= sequences[251].field0000))) {
            ResetPose();
            ClearBufferedButtons();
            field0008 = 0xfb;
            return;
        }
        if (((((recognizedCommand == 10) || (recognizedCommand == 11)) ||
              (recognizedCommand == 12)) &&
             ((sequences[field0008].data[field000a].frameFlags & 8) > 0)) &&
            (((field0008 >= 200 && (attackCollisionResult >= 2 && attackCollisionResult != 6)) ||
              (field0008 < 200)) &&
             (sequences[field0008].field0002 <= sequences[250].field0000))) {
            ResetPose();
            ClearBufferedButtons();
            field0008 = 0xfa;
            if (positionY < 0.0) {
                field0008 = 0xfd;
            }
            return;
        }
    }

    if (field015c < 1 && (recognizedCommand == 0 || recognizedCommand == 1) &&
        positionY == 0.0 && (sequences[field0008].data[field000a].frameFlags & 8) > 0) {
        if ((((*opponentSlot)->positionX - positionX) *
             (1 - recognizedCommand * 2) < 0.0 ||
             ((*opponentSlot)->positionX - positionX == 0.0 &&
              (int)(char)facing == ((1 - recognizedCommand * 2) * -1))) &&
            sequences[field0008].field0002 <= sequences[163].field0000 &&
            ((field0008 >= 200 && attackCollisionResult >= 2 && attackCollisionResult != 6) ||
             field0008 < 200)) {
            if (field0008 != 0xa3) ResetPose();
            field0008 = 0xa3;
            FaceOpponent();
            ++dashMomentumFlag;
            actionBufferedInput = 0;
            return;
        }
        if ((0.0 < ((*opponentSlot)->positionX - positionX) *
             (1 - recognizedCommand * 2) ||
             ((*opponentSlot)->positionX - positionX == 0.0 &&
              (int)(char)facing == 1 - recognizedCommand * 2)) &&
            sequences[field0008].field0002 <= sequences[164].field0000 &&
            ((field0008 >= 200 && attackCollisionResult >= 2 && attackCollisionResult != 6) ||
             field0008 < 200)) {
            if (field0008 != 0xa4) ResetPose();
            field0008 = 0xa4;
            FaceOpponent();
            ++dashMomentumFlag;
            actionBufferedInput = 0;
            return;
        }
    }

    if (buttonPulse[0] == 1 || (actionBufferedInput & 0x10) != 0 ||
        (stateGroupCBufferedInput & 0x10) != 0) {
        if (positionY < 0.0) {
            if (sequences[field0008].field0002 <= sequences[207].field0000 &&
                (sequences[field0008].data[field000a].frameFlags & 8) > 0 &&
                ((field0008 >= 200 && attackCollisionResult >= 2 && attackCollisionResult != 6) ||
                 field0008 < 200)) {
                ResetPose();
                ClearBufferedButtons();
                field0008 = 0xcf;
            }
            return;
        }
        if ((inputY == 1 || (actionBufferedInput & 4) != 0 ||
             (stateGroupCBufferedInput & 4) != 0) &&
            sequences[field0008].field0002 <= sequences[204].field0000 &&
            (sequences[field0008].data[field000a].frameFlags & 8) > 0 &&
            ((field0008 >= 200 && attackCollisionResult >= 2 && attackCollisionResult != 6) ||
             field0008 < 200)) {
            ResetPose();
            ClearBufferedButtons();
            field0008 = 0xcc;
            return;
        }
        if ((inputY == 0 || (actionBufferedInput & 4) == 0 ||
             (stateGroupCBufferedInput & 4) == 0) &&
            sequences[field0008].field0002 <= sequences[200].field0000 &&
            (sequences[field0008].data[field000a].frameFlags & 8) > 0 &&
            ((field0008 >= 200 && attackCollisionResult >= 2 && attackCollisionResult != 6) ||
             field0008 < 200)) {
            ResetPose();
            ClearBufferedButtons();
            field0008 = 200;
            return;
        }
    }

    if (buttonPulse[1] == 1 || (actionBufferedInput & 0x20) != 0 ||
        (stateGroupCBufferedInput & 0x20) != 0) {
        if (positionY < 0.0) {
            if (sequences[field0008].field0002 <= sequences[208].field0000 &&
                (sequences[field0008].data[field000a].frameFlags & 8) > 0 &&
                ((field0008 >= 200 && attackCollisionResult >= 2 && attackCollisionResult != 6) ||
                 field0008 < 200)) {
                ResetPose();
                ClearBufferedButtons();
                field0008 = 0xd0;
            }
            return;
        }
        if ((inputY == 1 || (actionBufferedInput & 4) != 0 ||
             (stateGroupCBufferedInput & 4) != 0) &&
            sequences[field0008].field0002 <= sequences[205].field0000 &&
            (sequences[field0008].data[field000a].frameFlags & 8) > 0 &&
            ((field0008 >= 200 && attackCollisionResult >= 2 && attackCollisionResult != 6) ||
             field0008 < 200)) {
            ResetPose();
            ClearBufferedButtons();
            field0008 = 0xcd;
            return;
        }
        if (inputY == 0 || (actionBufferedInput & 4) == 0 ||
            (stateGroupCBufferedInput & 4) == 0) {
            if (sequences[field0008].field0002 <= sequences[201].field0000 &&
                (sequences[field0008].data[field000a].frameFlags & 8) > 0 &&
                positionX - (*opponentSlot)->positionX > -110.0 &&
                positionX - (*opponentSlot)->positionX < 110.0 &&
                ((field0008 >= 200 && attackCollisionResult >= 2 && attackCollisionResult != 6) ||
                 field0008 < 200)) {
                ResetPose();
                ClearBufferedButtons();
                field0008 = 0xc9;
                return;
            }
            if (sequences[field0008].field0002 <= sequences[202].field0000 &&
                (sequences[field0008].data[field000a].frameFlags & 8) > 0 &&
                ((field0008 >= 200 && attackCollisionResult >= 2 && attackCollisionResult != 6) ||
                 field0008 < 200)) {
                ResetPose();
                ClearBufferedButtons();
                field0008 = 0xca;
                return;
            }
        }
    }

    if (buttonPulse[2] == 1 || (actionBufferedInput & 0x40) != 0 ||
        (stateGroupCBufferedInput & 0x40) != 0) {
        if (positionY < 0.0) {
            if (sequences[field0008].field0002 <= sequences[209].field0000 &&
                (sequences[field0008].data[field000a].frameFlags & 8) > 0 &&
                ((field0008 >= 200 && attackCollisionResult >= 2 && attackCollisionResult != 6) ||
                 field0008 < 200)) {
                ResetPose();
                ClearBufferedButtons();
                field0008 = 0xd1;
            }
        } else {
            if ((inputY == 1 || (actionBufferedInput & 4) != 0 ||
                 (stateGroupCBufferedInput & 4) != 0) &&
                sequences[field0008].field0002 <= sequences[206].field0000 &&
                (sequences[field0008].data[field000a].frameFlags & 8) > 0 &&
                ((field0008 >= 200 && attackCollisionResult >= 2 && attackCollisionResult != 6) ||
                 field0008 < 200)) {
                ResetPose();
                ClearBufferedButtons();
                field0008 = 0xce;
            } else if ((inputY == 0 || (actionBufferedInput & 4) == 0 ||
                        (stateGroupCBufferedInput & 4) == 0) &&
                       sequences[field0008].field0002 <= sequences[203].field0000 &&
                       (sequences[field0008].data[field000a].frameFlags & 8) > 0 &&
                       ((field0008 >= 200 && attackCollisionResult >= 2 && attackCollisionResult != 6) ||
                        field0008 < 200)) {
                ResetPose();
                ClearBufferedButtons();
                field0008 = 0xcb;
            }
        }
    }
}
