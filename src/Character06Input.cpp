// Nagamori's complete 12,277-byte, priority-ordered action selector.
// All original command, cancellation, attack and air/ground motion paths.
#include "CharacterViews.h"

void Character06::Slot04()
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
        (((field0118 >= 500.0 && attackCollisionResult > 1 && attackCollisionResult != 6) ||
          (field0120 > 0 && attackCollisionResult > 1)) &&
         ((sequences[field0008].data[field000a].frameFlags & 8) > 0)) &&
        field3150 == 0 &&
        sequences[field0008].field0002 <= sequences[167].field0000) {
        ResetPose();
        ClearBufferedButtons();
        field0008 = 0xa7;
        if (positionY < 0.0) {
            field0008 = 0xab;
        }
        return;
    }
    if (field015c < 2) {
        if (health < 0xd05 && recognizedCommand == 0x5b &&
            meter >= 3000 &&
            (sequences[field0008].data[field000a].frameFlags & 8) > 0 &&
            positionY == 0.0 && attackCollisionResult != 6 &&
            sequences[field0008].field0002 <= sequences[312].field0000) {
            ResetPose();
            ClearBufferedButtons();
            field0008 = 0x138;
            return;
        }
        if (recognizedCommand == 0x7a && meter >= 3000 && field3148 == 0 &&
            positionY == 0.0 &&
            (sequences[field0008].data[field000a].frameFlags & 8) > 0 &&
            sequences[field0008].field0002 <= sequences[315].field0000 &&
            (((field0008 >= 200 && attackCollisionResult >= 2 &&
               attackCollisionResult != 6)) || field0008 < 200)) {
            ResetPose();
            ClearBufferedButtons();
            field0008 = 0x13b;
            return;
        }
        if ((recognizedCommand == 0x79 || recognizedCommand == 0x7a) &&
            field3148 == 0 && meter >= 2000 && positionY == 0.0 &&
            (sequences[field0008].data[field000a].frameFlags & 8) > 0 &&
            sequences[field0008].field0002 <= sequences[314].field0000 &&
            (((field0008 >= 200 && attackCollisionResult >= 2 &&
               attackCollisionResult != 6)) || field0008 < 200)) {
            ResetPose();
            ClearBufferedButtons();
            field0008 = 0x13a;
            return;
        }
        if ((recognizedCommand == 0x78 || recognizedCommand == 0x79 ||
             recognizedCommand == 0x7a) && field3148 == 0 &&
            meter >= 1000 && positionY == 0.0 &&
            (sequences[field0008].data[field000a].frameFlags & 8) > 0 &&
            sequences[field0008].field0002 <= sequences[313].field0000 &&
            (((field0008 >= 200 && attackCollisionResult >= 2 &&
               attackCollisionResult != 6)) || field0008 < 200)) {
            ResetPose();
            ClearBufferedButtons();
            field0008 = 0x139;
            return;
        }
        if (recognizedCommand == 0x70 && meter >= 1000 &&
            (sequences[field0008].data[field000a].frameFlags & 8) > 0 &&
            field3148 == 0 && field3168 == 0 && positionY == 0.0 &&
            sequences[field0008].field0002 <= sequences[308].field0000 &&
            (((field0008 >= 200 && attackCollisionResult >= 2 &&
               attackCollisionResult != 6)) || field0008 < 200)) {
            ResetPose();
            ClearBufferedButtons();
            field0008 = 0x134;
            if (positionY < 0.0) {
                field0008 = 0x137;
            }
            return;
        }
        if (recognizedCommand == 0x6f && meter >= 1000 &&
            (sequences[field0008].data[field000a].frameFlags & 8) > 0 &&
            field3148 == 0 &&
            sequences[field0008].field0002 <= sequences[306].field0000 &&
            (((field0008 >= 200 && attackCollisionResult >= 2 &&
               attackCollisionResult != 6)) || field0008 < 200)) {
            ResetPose();
            ClearBufferedButtons();
            field0008 = 0x132;
            if (positionY < 0.0) {
                field0008 = 0x135;
            }
            return;
        }
        if (recognizedCommand == 0x6e && meter >= 1000 &&
            (sequences[field0008].data[field000a].frameFlags & 8) > 0 &&
            field3148 == 0 &&
            sequences[field0008].field0002 <= sequences[307].field0000 &&
            (((field0008 >= 200 && attackCollisionResult >= 2 &&
               attackCollisionResult != 6)) || field0008 < 200)) {
            ResetPose();
            ClearBufferedButtons();
            field0008 = 0x133;
            if (positionY < 0.0) {
                field0008 = 0x136;
            }
            return;
        }
        if (recognizedCommand == 0x66 && meter >= 3000 &&
            positionY == 0.0 &&
            (sequences[field0008].data[field000a].frameFlags & 8) > 0 &&
            sequences[field0008].field0002 <= sequences[302].field0000 &&
            (((field0008 >= 200 && attackCollisionResult >= 2 &&
               attackCollisionResult != 6)) || field0008 < 200)) {
            ResetPose();
            ClearBufferedButtons();
            field0008 = 0x12e;
            return;
        }
        if ((recognizedCommand == 0x65 || recognizedCommand == 0x66) &&
            meter >= 2000 && positionY == 0.0 &&
            (sequences[field0008].data[field000a].frameFlags & 8) > 0 &&
            sequences[field0008].field0002 <= sequences[301].field0000 &&
            (((field0008 >= 200 && attackCollisionResult >= 2 &&
               attackCollisionResult != 6)) || field0008 < 200)) {
            ResetPose();
            ClearBufferedButtons();
            field0008 = 0x12d;
            return;
        }
        if ((recognizedCommand == 100 || recognizedCommand == 0x65 ||
             recognizedCommand == 0x66) && meter >= 1000 &&
            positionY == 0.0 &&
            (sequences[field0008].data[field000a].frameFlags & 8) > 0 &&
            sequences[field0008].field0002 <= sequences[300].field0000 &&
            (((field0008 >= 200 && attackCollisionResult >= 2 &&
               attackCollisionResult != 6)) || field0008 < 200)) {
            ResetPose();
            ClearBufferedButtons();
            field0008 = 300;
            return;
        }
        if (recognizedCommand == 0x2a &&
            (field0118 >= 500.0 || field0120 > 0) &&
            (sequences[field0008].data[field000a].frameFlags & 8) > 0 &&
            positionY == 0.0 && field3148 == 0 &&
            sequences[field0008].field0002 <= sequences[272].field0000 &&
            (((field0008 >= 200 && attackCollisionResult >= 2 &&
               attackCollisionResult != 6)) || field0008 < 200)) {
            ResetPose();
            ClearBufferedButtons();
            field0008 = 0x110;
            return;
        }
        if ((recognizedCommand == 0x29 || recognizedCommand == 0x2a) &&
            (sequences[field0008].data[field000a].frameFlags & 8) > 0 &&
            positionY == 0.0 && field3148 == 0 &&
            sequences[field0008].field0002 <= sequences[271].field0000 &&
            (((field0008 >= 200 && attackCollisionResult >= 2 &&
               attackCollisionResult != 6)) || field0008 < 200)) {
            ResetPose();
            ClearBufferedButtons();
            field0008 = 0x10f;
            return;
        }
        if (recognizedCommand == 0x28 &&
            (sequences[field0008].data[field000a].frameFlags & 8) > 0 &&
            positionY == 0.0 && field3148 == 0 &&
            sequences[field0008].field0002 <= sequences[270].field0000 &&
            (((field0008 >= 200 && attackCollisionResult >= 2 &&
               attackCollisionResult != 6)) || field0008 < 200)) {
            ResetPose();
            ClearBufferedButtons();
            field0008 = 0x10e;
            return;
        }
        if (recognizedCommand == 0x16 &&
            (field0118 >= 500.0 || field0120 > 0) &&
            (sequences[field0008].data[field000a].frameFlags & 8) > 0 &&
            field3148 == 0 &&
            sequences[field0008].field0002 <= sequences[252].field0000 &&
            (((field0008 >= 200 && attackCollisionResult >= 2 &&
               attackCollisionResult != 6)) || field0008 < 200)) {
            ResetPose();
            ClearBufferedButtons();
            field0008 = 0xfc;
            return;
        }
        if ((recognizedCommand == 0x15 || recognizedCommand == 0x16) &&
            (sequences[field0008].data[field000a].frameFlags & 8) > 0 &&
            field3148 == 0 &&
            sequences[field0008].field0002 <= sequences[251].field0000 &&
            (((field0008 >= 200 && attackCollisionResult >= 2 &&
               attackCollisionResult != 6)) || field0008 < 200)) {
            ResetPose();
            ClearBufferedButtons();
            field0008 = 0xfb;
            return;
        }
        if (recognizedCommand == 0x14 &&
            (sequences[field0008].data[field000a].frameFlags & 8) > 0 &&
            field3148 == 0 &&
            sequences[field0008].field0002 <= sequences[250].field0000 &&
            (((field0008 >= 200 && attackCollisionResult >= 2 &&
               attackCollisionResult != 6)) || field0008 < 200)) {
            ResetPose();
            ClearBufferedButtons();
            field0008 = 0xfa;
            return;
        }
        if (recognizedCommand == 0x20 &&
            (sequences[field0008].data[field000a].frameFlags & 8) > 0 &&
            field3148 == 0 && meter > 50 &&
            sequences[field0008].field0002 <= sequences[257].field0000 &&
            (((field0008 >= 200 && attackCollisionResult >= 2 &&
               attackCollisionResult != 6)) || field0008 < 200)) {
            ResetPose();
            ClearBufferedButtons();
            field0008 = 0x101;
            if (positionY < 0.0) {
                field0008 = 0x115;
            }
            return;
        }
        if (recognizedCommand == 0x1f &&
            (sequences[field0008].data[field000a].frameFlags & 8) > 0 &&
            field3148 == 0 && meter > 50 &&
            sequences[field0008].field0002 <= sequences[256].field0000 &&
            (((field0008 >= 200 && attackCollisionResult >= 2 &&
               attackCollisionResult != 6)) || field0008 < 200)) {
            ResetPose();
            ClearBufferedButtons();
            field0008 = 0x100;
            if (positionY < 0.0) {
                field0008 = 0x114;
            }
            return;
        }
        if (recognizedCommand == 0x1e &&
            (sequences[field0008].data[field000a].frameFlags & 8) > 0 &&
            field3148 == 0 && meter > 50 &&
            sequences[field0008].field0002 <= sequences[255].field0000 &&
            (((field0008 >= 200 && attackCollisionResult >= 2 &&
               attackCollisionResult != 6)) || field0008 < 200)) {
            ResetPose();
            ClearBufferedButtons();
            field0008 = 0xff;
            if (positionY < 0.0) {
                field0008 = 0x113;
            }
            return;
        }
        if (recognizedCommand == 0x0c &&
            (sequences[field0008].data[field000a].frameFlags & 8) > 0 &&
            positionY < 0.0 && field3148 == 0 && meter > 50 &&
            sequences[field0008].field0002 <= sequences[262].field0000 &&
            (((field0008 >= 200 && attackCollisionResult >= 2 &&
               attackCollisionResult != 6)) || field0008 < 200)) {
            ResetPose();
            ClearBufferedButtons();
            field0008 = 0x106;
            return;
        }
        if (recognizedCommand == 0x0b &&
            (sequences[field0008].data[field000a].frameFlags & 8) > 0 &&
            positionY < 0.0 && field3148 == 0 && meter > 50 &&
            sequences[field0008].field0002 <= sequences[261].field0000 &&
            (((field0008 >= 200 && attackCollisionResult >= 2 &&
               attackCollisionResult != 6)) || field0008 < 200)) {
            ResetPose();
            ClearBufferedButtons();
            field0008 = 0x105;
            return;
        }
        if (recognizedCommand == 0x0a &&
            (sequences[field0008].data[field000a].frameFlags & 8) > 0 &&
            positionY < 0.0 && field3148 == 0 && meter > 50 &&
            sequences[field0008].field0002 <= sequences[260].field0000 &&
            (((field0008 >= 200 && attackCollisionResult >= 2 &&
               attackCollisionResult != 6)) || field0008 < 200)) {
            ResetPose();
            ClearBufferedButtons();
            field0008 = 0x104;
            return;
        }
        if (recognizedCommand == 0x0c && field3148 == 0 &&
            (field0118 >= 500.0 || field0120 > 0) &&
            (sequences[field0008].data[field000a].frameFlags & 8) > 0 &&
            positionY == 0.0 &&
            sequences[field0008].field0002 <= sequences[269].field0000 &&
            (((field0008 >= 200 && attackCollisionResult >= 2 &&
               attackCollisionResult != 6)) || field0008 < 200)) {
            ResetPose();
            ClearBufferedButtons();
            field0008 = 0x10d;
            return;
        }
        if (recognizedCommand == 0x0c && field3148 != 0 &&
            (sequences[field0008].data[field000a].frameFlags & 8) > 0 &&
            positionY == 0.0 &&
            sequences[field0008].field0002 <= sequences[280].field0000 &&
            (((field0008 >= 200 && attackCollisionResult >= 2 &&
               attackCollisionResult != 6)) || field0008 < 200)) {
            ResetPose();
            ClearBufferedButtons();
            field0008 = 0x118;
            return;
        }
        if ((recognizedCommand == 0x0b || recognizedCommand == 0x0c) &&
            (sequences[field0008].data[field000a].frameFlags & 8) > 0 &&
            positionY == 0.0 &&
            sequences[field0008].field0002 <= sequences[268].field0000 &&
            (((field0008 >= 200 && attackCollisionResult >= 2 &&
               attackCollisionResult != 6)) || field0008 < 200)) {
            ResetPose();
            ClearBufferedButtons();
            field0008 = 0x10c;
            if (field3148 != 0) {
                field0008 = 0x117;
            }
            return;
        }
        if (recognizedCommand == 0x0a &&
            (sequences[field0008].data[field000a].frameFlags & 8) > 0 &&
            positionY == 0.0 &&
            sequences[field0008].field0002 <= sequences[267].field0000 &&
            (((field0008 >= 200 && attackCollisionResult >= 2 &&
               attackCollisionResult != 6)) || field0008 < 200)) {
            ResetPose();
            ClearBufferedButtons();
            field0008 = 0x10b;
            if (field3148 != 0) {
                field0008 = 0x116;
            }
            return;
        }
    }
    if (field015c < 3) {
        if (recognizedCommand == 0x06 &&
            (sequences[field0008].data[field000a].frameFlags & 8) > 0 &&
            positionY < 0.0 && airActionCount < 1 &&
            sequences[field0008].field0002 <= sequences[14].field0000 &&
            (((field0008 >= 200 && attackCollisionResult >= 2 &&
               attackCollisionResult != 6)) || field0008 < 200)) {
            ResetPose();
            ClearBufferedButtons();
            ++airActionCount;
            field0008 = 0x0e;
            if (inputX == facing) {
                field0008 = 0x0f;
            }
            if ((int)inputX == -(int)facing) {
                field0008 = 0x10;
            }
            return;
        }
    }
    if ((field015c < 1) && ((recognizedCommand == 0 || (recognizedCommand == 1)))) {
        if ((positionY < 0.0) && (airDashCount < 1)) {
            if (((((((*opponentSlot)->positionX - positionX) * (1 - recognizedCommand * 2) < 0.0) || (((*opponentSlot)->positionX - positionX == 0.0 && ((int)(char)facing == ((1 - recognizedCommand * 2) * -1))))) && (sequences[field0008].field0002 <= sequences[165].field0000)) && (((field0008 != 0xaa && (positionY < -40.0)) && ((sequences[field0008].data[field000a].frameFlags & 8) > 0)))) && ((((field0008 >= 200 && (attackCollisionResult >= 2)) && (attackCollisionResult != 6)) || (field0008 < 200)))) {
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
            if ((((0.0 < ((*opponentSlot)->positionX - positionX) * (1 - recognizedCommand * 2)) || (((*opponentSlot)->positionX - positionX == 0.0 && ((int)(char)facing == 1 - recognizedCommand * 2)))) && ((sequences[field0008].field0002 <= sequences[166].field0000 && ((field0008 != 0xaa && ((sequences[field0008].data[field000a].frameFlags & 8) > 0)))))) && (((field0008 >= 200 && ((attackCollisionResult >= 2 && (attackCollisionResult != 6)))) || (field0008 < 200)))) {
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
        if ((positionY == 0.0) && ((sequences[field0008].data[field000a].frameFlags & 8) > 0)) {
            if ((((((*opponentSlot)->positionX - positionX) * (1 - recognizedCommand * 2) < 0.0) || (((*opponentSlot)->positionX - positionX == 0.0 && ((int)(char)facing == ((1 - recognizedCommand * 2) * -1))))) && (sequences[field0008].field0002 <= sequences[163].field0000)) && ((((field0008 >= 200 && (attackCollisionResult >= 2)) && (attackCollisionResult != 6)) || (field0008 < 200)))) {
                if (field0008 != 0xa3) {
                    ResetPose();
                }
                field0008 = 0xa3;
                FaceOpponent();
                ++dashMomentumFlag;
                actionBufferedInput = 0;
                return;
            }
            if (((0.0 < ((*opponentSlot)->positionX - positionX) * (1 - recognizedCommand * 2)) || (((*opponentSlot)->positionX - positionX == 0.0 && ((int)(char)facing == 1 - recognizedCommand * 2)))) && ((sequences[field0008].field0002 <= sequences[164].field0000 && ((((field0008 >= 200 && (attackCollisionResult >= 2)) && (attackCollisionResult != 6)) || (field0008 < 200)))))) {
                if (field0008 != 0xa4) {
                    ResetPose();
                }
                field0008 = 0xa4;
                FaceOpponent();
                actionBufferedInput = 0;
                return;
            }
        }
    }
    if (((buttonPulse[0] == '\x01') || ((actionBufferedInput & 0x10) != 0)) || ((stateGroupCBufferedInput & 0x10) != 0)) {
        if ((field0008 == 0xa3) && ((int)(char)inputX != -(int)(char)facing)) {
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
                ((field0008 >= 200 && attackCollisionResult >= 2 && attackCollisionResult != 6) || field0008 < 200)) {
                ResetPose();
                ClearBufferedButtons();
                field0008 = 207;
            }
            return;
        }
        if (((((inputY == '\x01') || ((actionBufferedInput & 4) != 0)) || ((stateGroupCBufferedInput & 4) != 0)) && ((sequences[field0008].field0002 <= sequences[204].field0000 && ((sequences[field0008].data[field000a].frameFlags & 8) > 0)))) && (((field0008 >= 200 && ((attackCollisionResult >= 2 && (attackCollisionResult != 6)))) || (field0008 < 200)))) {
            ResetPose();
            ClearBufferedButtons();
            field0008 = 0xcc;
            return;
        }
        if (((((inputY == '\0') || ((actionBufferedInput & 4) == 0)) || ((stateGroupCBufferedInput & 4) == 0)) && ((sequences[field0008].field0002 <= sequences[200].field0000 && ((sequences[field0008].data[field000a].frameFlags & 8) > 0)))) && (((field0008 >= 200 && ((attackCollisionResult >= 2 && (attackCollisionResult != 6)))) || (field0008 < 200)))) {
            ResetPose();
            ClearBufferedButtons();
            field0008 = 200;
            return;
        }
    }
    if (((buttonPulse[1] == '\x01') || ((actionBufferedInput & 0x20) != 0)) || ((stateGroupCBufferedInput & 0x20) != 0)) {
        if ((field0008 == 0xa3) && ((int)(char)inputX != -(int)(char)facing)) {
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
                ((field0008 >= 200 && attackCollisionResult >= 2 && attackCollisionResult != 6) || field0008 < 200)) {
                ResetPose();
                ClearBufferedButtons();
                field0008 = 208;
            }
            return;
        }
        if (((((inputY == '\x01') || ((actionBufferedInput & 4) != 0)) || ((stateGroupCBufferedInput & 4) != 0)) && ((sequences[field0008].field0002 <= sequences[205].field0000 && ((sequences[field0008].data[field000a].frameFlags & 8) > 0)))) && (((field0008 >= 200 && ((attackCollisionResult >= 2 && (attackCollisionResult != 6)))) || (field0008 < 200)))) {
            ResetPose();
            ClearBufferedButtons();
            field0008 = 0xcd;
            return;
        }
        if (((inputY == '\0') || ((actionBufferedInput & 4) == 0)) || ((stateGroupCBufferedInput & 4) == 0)) {
            if (sequences[field0008].field0002 <= sequences[216].field0000 &&
                (sequences[field0008].data[field000a].frameFlags & 8) > 0 &&
                inputX == facing) {
                ResetPose();
                ClearBufferedButtons();
                field0008 = 0xd8;
                return;
            }
            if ((((sequences[field0008].field0002 <= sequences[201].field0000) && ((sequences[field0008].data[field000a].frameFlags & 8) > 0)) && ((positionX - (*opponentSlot)->positionX > -70.0 && (positionX - (*opponentSlot)->positionX < 70.0)))) && ((((field0008 >= 200 && (attackCollisionResult >= 2)) && (attackCollisionResult != 6)) || (field0008 < 200)))) {
                ResetPose();
                ClearBufferedButtons();
                field0008 = 0xc9;
                return;
            }
            if (((sequences[field0008].field0002 <= sequences[202].field0000) && ((sequences[field0008].data[field000a].frameFlags & 8) > 0)) && (((field0008 >= 200 && ((attackCollisionResult >= 2 && (attackCollisionResult != 6)))) || (field0008 < 200)))) {
                ResetPose();
                ClearBufferedButtons();
                field0008 = 0xca;
                return;
            }
        }
    }
    if (buttonPulse[2] == 1 || (actionBufferedInput & 0x40) != 0 || (stateGroupCBufferedInput & 0x40) != 0) {
        if (field0008 == 163 && (int)inputX != -(int)facing) {
            ResetPose();
            ClearBufferedButtons();
            field0008 = 232;
            if (inputY == 1) {
                field0008 = 235;
            }
            return;
        }
        if (positionY < 0.0) {
            if (inputX == facing && inputY == 0 &&
                positionX - (*opponentSlot)->positionX > -100.0 &&
                positionX - (*opponentSlot)->positionX < 100.0 &&
                (*opponentSlot)->positionY < 0.0 &&
                sequences[field0008].field0002 <= sequences[248].field0000 &&
                ((*opponentSlot)->field0008 < 50 || (*opponentSlot)->field0008 > 156) &&
                (sequences[field0008].data[field000a].frameFlags & 8) > 0 &&
                ((field0008 >= 200 && attackCollisionResult >= 2 && attackCollisionResult != 6) || field0008 < 200)) {
                ResetPose();
                ClearBufferedButtons();
                field0008 = 248;
                return;
            }
            if (sequences[field0008].field0002 <= sequences[209].field0000 &&
                (sequences[field0008].data[field000a].frameFlags & 8) > 0 &&
                ((field0008 >= 200 && attackCollisionResult >= 2 && attackCollisionResult != 6) || field0008 < 200)) {
                ResetPose();
                ClearBufferedButtons();
                field0008 = 209;
            }
            return;
        }
        if ((inputY == 1 || (actionBufferedInput & 4) != 0 || (stateGroupCBufferedInput & 4) != 0) &&
            sequences[field0008].field0002 <= sequences[206].field0000 &&
            (sequences[field0008].data[field000a].frameFlags & 8) > 0 &&
            ((field0008 >= 200 && attackCollisionResult >= 2 && attackCollisionResult != 6) || field0008 < 200)) {
            ResetPose();
            ClearBufferedButtons();
            field0008 = 206;
            if (field3148 > 0) {
                field0008 = 215;
            }
            return;
        }
        if (inputY == 0 || (actionBufferedInput & 4) == 0 || (stateGroupCBufferedInput & 4) == 0) {
            if (inputX != 0 && (*opponentSlot)->positionY == 0.0 &&
                positionX - (*opponentSlot)->positionX > -30.0 &&
                positionX - (*opponentSlot)->positionX < 30.0 &&
                sequences[field0008].field0002 <= sequences[220].field0000 &&
                ((*opponentSlot)->field0008 < 50 || (*opponentSlot)->field0008 > 156) &&
                (sequences[field0008].data[field000a].frameFlags & 8) > 0 &&
                ((field0008 >= 200 && attackCollisionResult >= 2 && attackCollisionResult != 6) || field0008 < 200)) {
                ResetPose();
                ClearBufferedButtons();
                field0008 = 220;
                return;
            }
            if (sequences[field0008].field0002 <= sequences[203].field0000 &&
                (sequences[field0008].data[field000a].frameFlags & 8) > 0 &&
                ((field0008 >= 200 && attackCollisionResult >= 2 && attackCollisionResult != 6) || field0008 < 200)) {
                ResetPose();
                ClearBufferedButtons();
                field0008 = 203;
            }
        }
    }
    return;
}
