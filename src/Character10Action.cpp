// Complete natural C++ reconstruction of Nayuki Character10::Slot04.
// Original code [0x00461460,0x00463DCD): 10,605 x86 instruction bytes.
#include "CharacterViews.h"

void Character10::Slot04()
{
    if (field0008 < 200)
        actionBufferedInput = 0;
    if (stateGroupCBufferFrames <= 0)
        stateGroupCBufferedInput = 0;
    else
        --stateGroupCBufferFrames;
    if (stateGroupCBufferedInput == '\0')
        stateGroupCBufferFrames = 0;

    if (recognizedCommand == 0x34 &&
        (field0118 >= 500.0 || field0120 > 0) &&
        attackCollisionResult > 1 && attackCollisionResult != 6 &&
        (sequences[field0008].data[field000a].frameFlags & 8) > 0 &&
        sequences[field0008].field0002 <= sequences[167].field0000) {
        ResetPose();
        ClearBufferedButtons();
        field0008 = 0xa7;
        if (positionY < 0.0)
            field0008 = 0xab;
        return;
    }
    if (field015c < 2) {
        if (health < 0xd05 && recognizedCommand == 0x61 && meter >= 3000 &&
            positionY == 0.0 &&
            attackCollisionResult != 6 &&
            (sequences[field0008].data[field000a].frameFlags & 8) > 0 &&
            sequences[field0008].field0002 <= sequences[306].field0000) {
            ResetPose();
            ClearBufferedButtons();
            field0008 = 0x132;
            return;
        }
        if (recognizedCommand == 0x66 && meter >= 3000 &&
            positionY == 0.0 &&
            (sequences[field0008].data[field000a].frameFlags & 8) > 0 &&
            ((field0008 >= 200 && attackCollisionResult >= 2 &&
              attackCollisionResult != 6) || field0008 < 200) &&
            sequences[field0008].field0002 <= sequences[302].field0000) {
            ResetPose();
            ClearBufferedButtons();
            field0008 = 0x12e;
            return;
        }
        if ((recognizedCommand == 0x65 || recognizedCommand == 0x66) &&
            meter >= 2000 && positionY == 0.0 &&
            (sequences[field0008].data[field000a].frameFlags & 8) > 0 &&
            ((field0008 >= 200 && attackCollisionResult >= 2 &&
              attackCollisionResult != 6) || field0008 < 200) &&
            sequences[field0008].field0002 <= sequences[301].field0000) {
            ResetPose();
            ClearBufferedButtons();
            field0008 = 0x12d;
            return;
        }
        if ((recognizedCommand == 0x64 || recognizedCommand == 0x65 ||
             recognizedCommand == 0x66) &&
            meter >= 1000 && positionY == 0.0 &&
            (sequences[field0008].data[field000a].frameFlags & 8) > 0 &&
            ((field0008 >= 200 && attackCollisionResult >= 2 &&
              attackCollisionResult != 6) || field0008 < 200) &&
            sequences[field0008].field0002 <= sequences[300].field0000) {
            ResetPose();
            ClearBufferedButtons();
            field0008 = 0x12c;
            return;
        }
        if (recognizedCommand == 0x70 &&
            meter >= 3000 && positionY == 0.0 &&
            (sequences[field0008].data[field000a].frameFlags & 8) > 0 &&
            ((field0008 >= 200 && attackCollisionResult >= 2 &&
              attackCollisionResult != 6) || field0008 < 200) &&
            sequences[field0008].field0002 <= sequences[305].field0000) {
            ResetPose();
            ClearBufferedButtons();
            field0008 = 0x131;
            return;
        }
        if ((recognizedCommand == 0x6f || recognizedCommand == 0x70) &&
            meter >= 2000 && positionY == 0.0 &&
            (sequences[field0008].data[field000a].frameFlags & 8) > 0 &&
            ((field0008 >= 200 && attackCollisionResult >= 2 &&
              attackCollisionResult != 6) || field0008 < 200) &&
            sequences[field0008].field0002 <= sequences[304].field0000) {
            ResetPose();
            ClearBufferedButtons();
            field0008 = 0x130;
            return;
        }
        if ((recognizedCommand == 0x6e || recognizedCommand == 0x6f ||
             recognizedCommand == 0x70) &&
            meter >= 1000 && positionY == 0.0 &&
            (sequences[field0008].data[field000a].frameFlags & 8) > 0 &&
            ((field0008 >= 200 && attackCollisionResult >= 2 &&
              attackCollisionResult != 6) || field0008 < 200) &&
            sequences[field0008].field0002 <= sequences[303].field0000) {
            ResetPose();
            ClearBufferedButtons();
            field0008 = 0x12f;
            return;
        }
        if (field3148 > 0) {
        if (recognizedCommand == 0x48 &&
            (field0118 >= 500.0 || field0120 > 0) &&
            (sequences[field0008].data[field000a].frameFlags & 8) > 0 &&
            positionY == 0.0 &&
            ((field0008 >= 200 && attackCollisionResult >= 2 &&
              attackCollisionResult != 6) || field0008 < 200) &&
            sequences[field0008].field0002 <= sequences[266].field0000) {
            ResetPose();
            ClearBufferedButtons();
            field0008 = 0x10a;
            return;
        }
        if ((recognizedCommand == 0x47 || recognizedCommand == 0x48) &&
            (sequences[field0008].data[field000a].frameFlags & 8) > 0 &&
            positionY == 0.0 &&
            ((field0008 >= 200 && attackCollisionResult >= 2 &&
              attackCollisionResult != 6) || field0008 < 200) &&
            sequences[field0008].field0002 <= sequences[265].field0000) {
            ResetPose();
            ClearBufferedButtons();
            field0008 = 0x109;
            return;
        }
        if (recognizedCommand == 0x46 &&
            (sequences[field0008].data[field000a].frameFlags & 8) > 0 &&
            positionY == 0.0 &&
            ((field0008 >= 200 && attackCollisionResult >= 2 &&
              attackCollisionResult != 6) || field0008 < 200) &&
            sequences[field0008].field0002 <= sequences[264].field0000) {
            ResetPose();
            ClearBufferedButtons();
            field0008 = 0x108;
            return;
        }
        }
        if ((recognizedCommand == 0x1e || recognizedCommand == 0x1f ||
             recognizedCommand == 0x20) &&
            (sequences[field0008].data[field000a].frameFlags & 8) > 0 &&
            positionY == 0.0 &&
            ((field0008 >= 200 && attackCollisionResult >= 2 &&
              attackCollisionResult != 6) || field0008 < 200) &&
            (sequences[field0008].field0002 <=
                 sequences[268].field0000 + (field3148 > 6) * 10 ||
             field0008 == 0x108 || field0008 == 0x109)) {
            ResetPose();
            ClearBufferedButtons();
            field0008 = 0x10c;
            return;
        }
        // Command-16 meter permission and three grounded follow-up tiers.
        if (field3148 > 1) {
        if (recognizedCommand == 0x16 &&
            (field0118 >= 500.0 || field0120 > 0) &&
            (sequences[field0008].data[field000a].frameFlags & 8) > 0 &&
            positionY == 0.0 &&
            ((field0008 >= 200 && attackCollisionResult >= 2 &&
              attackCollisionResult != 6) || field0008 < 200) &&
            sequences[field0008].field0002 <= sequences[262].field0000) {
            ResetPose();
            ClearBufferedButtons();
            field0008 = 0x106;
            return;
        }
        if ((recognizedCommand == 0x15 || recognizedCommand == 0x16) &&
            (sequences[field0008].data[field000a].frameFlags & 8) > 0 &&
            positionY == 0.0 &&
            ((field0008 >= 200 && attackCollisionResult >= 2 &&
              attackCollisionResult != 6) || field0008 < 200) &&
            sequences[field0008].field0002 <= sequences[261].field0000) {
            ResetPose();
            ClearBufferedButtons();
            field0008 = 0x105;
            return;
        }
        if (recognizedCommand == 0x14 &&
            (sequences[field0008].data[field000a].frameFlags & 8) > 0 &&
            positionY == 0.0 &&
            ((field0008 >= 200 && attackCollisionResult >= 2 &&
              attackCollisionResult != 6) || field0008 < 200) &&
            sequences[field0008].field0002 <= sequences[260].field0000) {
            ResetPose();
            ClearBufferedButtons();
            field0008 = 0x104;
            return;
        }
        }
        // Nayuki unique 0x0D move and grounded 0x0C/0x0B/0x0A tiers.
        if (recognizedCommand == 0x0d &&
            (sequences[field0008].data[field000a].frameFlags & 8) > 0 &&
            positionY == 0.0 &&
            ((field0008 >= 200 && attackCollisionResult >= 2 &&
              attackCollisionResult != 6) || field0008 < 200) &&
            sequences[field0008].field0002 <= sequences[279].field0000) {
            ResetPose();
            ClearBufferedButtons();
            field0008 = 0x117;
            return;
        }
        if (recognizedCommand == 0x0c &&
            (field0118 >= 500.0 || field0120 > 0) &&
            (sequences[field0008].data[field000a].frameFlags & 8) > 0 &&
            positionY == 0.0 &&
            ((field0008 >= 200 && attackCollisionResult >= 2 &&
              attackCollisionResult != 6) || field0008 < 200) &&
            sequences[field0008].field0002 <= sequences[252].field0000) {
            ResetPose();
            ClearBufferedButtons();
            field0008 = 0xfc;
            return;
        }
        if ((recognizedCommand == 0x0b || recognizedCommand == 0x0c) &&
            (sequences[field0008].data[field000a].frameFlags & 8) > 0 &&
            positionY == 0.0 &&
            ((field0008 >= 200 && attackCollisionResult >= 2 &&
              attackCollisionResult != 6) || field0008 < 200) &&
            sequences[field0008].field0002 <= sequences[251].field0000) {
            ResetPose();
            ClearBufferedButtons();
            field0008 = 0xfb;
            return;
        }
        if (recognizedCommand == 0x0a &&
            (sequences[field0008].data[field000a].frameFlags & 8) > 0 &&
            positionY == 0.0 &&
            ((field0008 >= 200 && attackCollisionResult >= 2 &&
              attackCollisionResult != 6) || field0008 < 200) &&
            sequences[field0008].field0002 <= sequences[250].field0000) {
            ResetPose();
            ClearBufferedButtons();
            field0008 = 0xfa;
            return;
        }
    }
    // Air dash when the opponent lies on the command's chosen side.
    if (field015c < 1 && (recognizedCommand == 0 || recognizedCommand == 1)) {
        if (positionY < 0.0 &&
            airDashCount < 1 + (field3148 > 2) + (field3148 > 7)) {
            if ((((*opponentSlot)->positionX - positionX) *
                     (double)(1 - recognizedCommand * 2) < 0.0 ||
                 (((*opponentSlot)->positionX - positionX == 0.0) &&
                  facing == (1 - recognizedCommand * 2) * -1)) &&
                sequences[field0008].field0002 <= sequences[165].field0000 &&
                field0008 != 0xaa && positionY < -40.0 &&
                (sequences[field0008].data[field000a].frameFlags & 8) > 0 &&
                ((field0008 >= 200 && attackCollisionResult >= 2 &&
                  attackCollisionResult != 6) || field0008 < 200)) {
                ResetPose();
                field0008 = 0xa5;
                FaceOpponent();
                ++airDashCount;
                ++airActionCount;
                actionBufferedInput = 0;
                return;
            }
            // Mirrored air dash: the opposite horizontal side and the
            // matching facing condition choose the A6 movement state.
            if ((((*opponentSlot)->positionX - positionX) *
                     (double)(1 - recognizedCommand * 2) > 0.0 ||
                 (((*opponentSlot)->positionX - positionX == 0.0) &&
                  facing == (1 - recognizedCommand * 2))) &&
                sequences[field0008].field0002 <= sequences[166].field0000 &&
                field0008 != 0xaa &&
                (sequences[field0008].data[field000a].frameFlags & 8) > 0 &&
                ((field0008 >= 200 && attackCollisionResult >= 2 &&
                  attackCollisionResult != 6) || field0008 < 200)) {
                ResetPose();
                field0008 = 0xa6;
                FaceOpponent();
                ++airDashCount;
                ++airActionCount;
                actionBufferedInput = 0;
                return;
            }
        }
        // Grounded direction changes use the same command orientation but
        // distinct ground action priorities and air-dash flags.
        if (positionY == 0.0 &&
            (sequences[field0008].data[field000a].frameFlags & 8) > 0) {
            if ((((*opponentSlot)->positionX - positionX) *
                     (double)(1 - recognizedCommand * 2) < 0.0 ||
                 (((*opponentSlot)->positionX - positionX == 0.0) &&
                  facing == (1 - recognizedCommand * 2) * -1)) &&
                sequences[field0008].field0002 <= sequences[163].field0000 &&
                ((field0008 >= 200 && attackCollisionResult >= 2 &&
                  attackCollisionResult != 6) || field0008 < 200)) {
                if (field0008 != 0xa3)
                    ResetPose();
                field0008 = 0xa3;
                FaceOpponent();
                actionBufferedInput = 0;
                return;
            }
            if ((((*opponentSlot)->positionX - positionX) *
                     (double)(1 - recognizedCommand * 2) > 0.0 ||
                 (((*opponentSlot)->positionX - positionX == 0.0) &&
                  facing == (1 - recognizedCommand * 2))) &&
                sequences[field0008].field0002 <= sequences[164].field0000 &&
                ((field0008 >= 200 && attackCollisionResult >= 2 &&
                  attackCollisionResult != 6) || field0008 < 200)) {
                if (field0008 != 0xa4)
                    ResetPose();
                field0008 = 0xa4;
                FaceOpponent();
                actionBufferedInput = 0;
                return;
            }
        }
    }
    // Aerial command 6: one action-count slot selects neutral/forward/back
    // from the buffered horizontal input, after the original frame guard.
    if (field015c < 3 && recognizedCommand == 6 &&
        (sequences[field0008].data[field000a].frameFlags & 8) > 0 &&
        positionY < 0.0 && airActionCount < 1 &&
        sequences[field0008].field0002 <= sequences[14].field0000 &&
        ((field0008 >= 200 && attackCollisionResult >= 2 &&
          attackCollisionResult != 6) || field0008 < 200)) {
        ResetPose();
        ClearBufferedButtons();
        ++airActionCount;
        field0008 = 0x0e;
        if (inputX == facing)
            field0008 = 0x0f;
        if (inputX == -facing)
            field0008 = 0x10;
        return;
    }
    // Attack button 0 also recognizes the two independent held-input masks.
    // Air and ground attacks choose distinct original action/state owners.
    if (buttonPulse[0] == 1 ||
        (actionBufferedInput & 0x10) != 0 ||
        (stateGroupCBufferedInput & 0x10) != 0) {
        if (positionY < 0.0) {
            if (sequences[field0008].field0002 <=
                    sequences[207].field0000 &&
                (sequences[field0008].data[field000a].frameFlags & 8) > 0 &&
                ((field0008 >= 200 && attackCollisionResult >= 2 &&
                  attackCollisionResult != 6) || field0008 < 200)) {
                ResetPose();
                ClearBufferedButtons();
                if (field0008 == 0xa3) {
                    field0008 = 0xe6;
                    return;
                } else {
                    field0008 = 0xcf;
                }
            }
            return;
        }
        if (inputY == 1 || (actionBufferedInput & 4) != 0 ||
            (stateGroupCBufferedInput & 4) != 0) {
            if (sequences[field0008].field0002 <=
                    sequences[204].field0000 &&
                (sequences[field0008].data[field000a].frameFlags & 8) > 0 &&
                ((field0008 >= 200 && attackCollisionResult >= 2 &&
                  attackCollisionResult != 6) || field0008 < 200)) {
                ResetPose();
                ClearBufferedButtons();
                field0008 = 0xcc;
                return;
            }
        }
        if (inputY == 0 || (actionBufferedInput & 4) == 0 ||
            (stateGroupCBufferedInput & 4) == 0) {
            if (sequences[field0008].field0002 <=
                    sequences[200].field0000 &&
                (sequences[field0008].data[field000a].frameFlags & 8) > 0 &&
                ((field0008 >= 200 && attackCollisionResult >= 2 &&
                  attackCollisionResult != 6) || field0008 < 200)) {
                ResetPose();
                ClearBufferedButtons();
                field0008 = 0xc8;
                return;
            }
        }
    }
    // Attack button 1 or the independent 0x20 held-input bits. Airborne
    // attempts exit this priority group even when its action is disallowed.
    if (buttonPulse[1] == 1 ||
        (actionBufferedInput & 0x20) != 0 ||
        (stateGroupCBufferedInput & 0x20) != 0) {
        if (positionY < 0.0) {
            if (sequences[field0008].field0002 <=
                    sequences[208].field0000 &&
                (sequences[field0008].data[field000a].frameFlags & 8) > 0 &&
                ((field0008 >= 200 && attackCollisionResult >= 2 &&
                  attackCollisionResult != 6) || field0008 < 200)) {
                ResetPose();
                ClearBufferedButtons();
                if (field0008 == 0xa3) {
                    field0008 = 0xe7;
                    return;
                } else {
                    field0008 = 0xd0;
                }
            }
            return;
        }
        if (inputY == 1 || (actionBufferedInput & 4) != 0 ||
            (stateGroupCBufferedInput & 4) != 0) {
            if (((sequences[field0008].field0002 <= sequences[205].field0000 &&
                  (sequences[field0008].data[field000a].frameFlags & 8) > 0 &&
                  field0008 != 0xc9) ||
                 (sequences[field0008].field0002 <= sequences[205].field0000 &&
                  (sequences[field0008].data[field000a].frameFlags & 8) > 0 &&
                  field3148 > 0)) &&
                ((field0008 >= 200 && attackCollisionResult >= 2 &&
                  attackCollisionResult != 6) || field0008 < 200)) {
                ResetPose();
                ClearBufferedButtons();
                field0008 = 0xcd;
                return;
            }
        }
        if (inputY == 0 || (actionBufferedInput & 4) == 0 ||
            (stateGroupCBufferedInput & 4) == 0) {
            if (sequences[field0008].field0002 <=
                    sequences[210].field0000 &&
                (sequences[field0008].data[field000a].frameFlags & 8) > 0 &&
                inputX == facing && field3148 > 1 &&
                ((field0008 >= 200 && attackCollisionResult >= 2 &&
                  attackCollisionResult != 6) || field0008 < 200)) {
                ResetPose();
                ClearBufferedButtons();
                field0008 = 0xd2;
                return;
            }
            if (sequences[field0008].field0002 <=
                    sequences[201].field0000 &&
                (sequences[field0008].data[field000a].frameFlags & 8) > 0 &&
                positionX - (*opponentSlot)->positionX > -80.0 &&
                positionX - (*opponentSlot)->positionX < 80.0 &&
                ((field0008 >= 200 && attackCollisionResult >= 2 &&
                  attackCollisionResult != 6) || field0008 < 200)) {
                ResetPose();
                ClearBufferedButtons();
                field0008 = 0xc9;
                return;
            }
            if ((field0008 == 0xcd && field3148 > 1) ||
                (sequences[field0008].field0002 <=
                    sequences[202].field0000 &&
                 (sequences[field0008].data[field000a].frameFlags & 8) > 0 &&
                 ((field0008 >= 200 && attackCollisionResult >= 2 &&
                   attackCollisionResult != 6) || field0008 < 200))) {
                ResetPose();
                ClearBufferedButtons();
                field0008 = 0xca;
                return;
            }
        }
    }
    // Third attack button: aerial priority and grounded follow-up actions.
    if (buttonPulse[2] == 1 ||
        (actionBufferedInput & 0x40) != 0 ||
        (stateGroupCBufferedInput & 0x40) != 0) {
        if (positionY < 0.0) {
            if (inputX == facing && inputY == 0 &&
                positionX - (*opponentSlot)->positionX > -100.0 &&
                positionX - (*opponentSlot)->positionX < 100.0 &&
                (*opponentSlot)->positionY < 0.0 &&
                sequences[field0008].field0002 <=
                    sequences[248].field0000 &&
                ((*opponentSlot)->field0008 < 50 ||
                 (*opponentSlot)->field0008 > 156) &&
                (sequences[field0008].data[field000a].frameFlags & 8) > 0 &&
                ((field0008 >= 200 && attackCollisionResult >= 2 &&
                  attackCollisionResult != 6) || field0008 < 200)) {
                ResetPose();
                ClearBufferedButtons();
                if (field0008 == 0xa3) {
                    field0008 = 0xe8;
                    return;
                } else {
                    field0008 = 0xf8;
                    return;
                }
            }
            if (((sequences[field0008].field0002 <= sequences[209].field0000 &&
                  (sequences[field0008].data[field000a].frameFlags & 8) > 0 &&
                  field0008 != 0xca) ||
                 (sequences[field0008].field0002 <= sequences[209].field0000 &&
                  (sequences[field0008].data[field000a].frameFlags & 8) > 0 &&
                  field3148 > 4)) &&
                ((field0008 >= 200 && attackCollisionResult >= 2 &&
                  attackCollisionResult != 6) || field0008 < 200)) {
                ResetPose();
                ClearBufferedButtons();
                if (field0008 == 0xa3) {
                    field0008 = 0xe8;
                    return;
                } else if (field0008 == 0xca) {
                    field0008 = 0xd6;
                    return;
                } else {
                    field0008 = 0xd1;
                }
            }
            return;
        }
        if (inputY == 1 || (actionBufferedInput & 4) != 0 ||
            (stateGroupCBufferedInput & 4) != 0) {
            if (sequences[field0008].field0002 <=
                    sequences[206].field0000 &&
                (sequences[field0008].data[field000a].frameFlags & 8) > 0 &&
                ((field0008 >= 200 && attackCollisionResult >= 2 &&
                  attackCollisionResult != 6) || field0008 < 200)) {
                ResetPose();
                ClearBufferedButtons();
                field0008 = 0xce;
                return;
            }
        }
        if (inputY == 0 || (actionBufferedInput & 4) == 0 ||
            (stateGroupCBufferedInput & 4) == 0) {
            if (inputX != 0 && (*opponentSlot)->positionY == 0.0 &&
                positionX - (*opponentSlot)->positionX > -30.0 &&
                positionX - (*opponentSlot)->positionX < 30.0 &&
                sequences[field0008].field0002 <=
                    sequences[220].field0000 &&
                ((*opponentSlot)->field0008 < 50 ||
                 (*opponentSlot)->field0008 > 156) &&
                (sequences[field0008].data[field000a].frameFlags & 8) > 0 &&
                ((field0008 >= 200 && attackCollisionResult >= 2 &&
                  attackCollisionResult != 6) || field0008 < 200) &&
                (*opponentSlot)->positionY == 0.0) {
                ResetPose();
                ClearBufferedButtons();
                field0008 = 0xdc;
                return;
            }
            if (sequences[field0008].field0002 <=
                    sequences[203].field0000 &&
                (sequences[field0008].data[field000a].frameFlags & 8) > 0 &&
                ((field0008 >= 200 && attackCollisionResult >= 2 &&
                  attackCollisionResult != 6) || field0008 < 200)) {
                ResetPose();
                ClearBufferedButtons();
                field0008 = 0xcb;
                return;
            }
        }
    }
    // Nayuki's independent fourth button and 0x80 held input family.
    if (field015c < 2 &&
        (buttonPulse[3] == 1 || (actionBufferedInput & 0x80) != 0 ||
         (stateGroupCBufferedInput & 0x80) != 0)) {
        if (sequences[field0008].field0002 <= sequences[259].field0000 &&
            (sequences[field0008].data[field000a].frameFlags & 8) > 0 &&
            field3148 < 9 && positionY == 0.0 &&
            ((field0008 >= 200 && attackCollisionResult >= 2 &&
              attackCollisionResult != 6) || field0008 < 200)) {
            ResetPose();
            ClearBufferedButtons();
            field0008 = 0x103;
            if (inputY == 1)
                field0008 = 0x118;
        }
    }
}
