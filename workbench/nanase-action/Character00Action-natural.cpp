// Nanase natural-C++ action selection workbench hypothesis. Not Exact.
#include "../../src/CharacterViews.h"

struct NanaseActionChild { unsigned char inherited[0x3138]; int field3138,field313c,field3140,field3144,field3148; int effectA[64],effectB[64],effectC[64]; int field344c; };
#define C00 (reinterpret_cast<NanaseActionChild *>(this))

void Character00::Slot04()
{
    if (field0008 < 200) {
        actionBufferedInput = 0;
    }
    if (stateGroupCBufferFrames <= 0) {
        stateGroupCBufferedInput = 0;
    }
    else {
        --stateGroupCBufferFrames;
    }
    if (stateGroupCBufferedInput == '\0') {
        stateGroupCBufferFrames = 0;
    }
    if ((recognizedCommand == 0x34) && (((((field0118 >= 500.0 || ('\0' < (char)field0120)) && (1 < attackCollisionResult)) && ((attackCollisionResult != 6 && ((sequences[field0008].data[field000a].frameFlags & 8) > 0)))) && (sequences[field0008].field0002 <= sequences[167].field0000)))) {
        ResetPose();
        ClearBufferedButtons();
        field0008 = 0xa7;
        if (positionY < 0.0) {
            field0008 = 0xab;
        }
        return;
    }
    if (field015c < 2) {
        if ((((health < 0xd05) && (recognizedCommand == 0x99)) && ((meter >= 3000 && (((sequences[field0008].data[field000a].frameFlags & 8) > 0 && (positionY == 0.0)))))) && ((((field0008 >= 200 && ((attackCollisionResult >= 2 && (attackCollisionResult != 6)))) || (field0008 < 200)) && (sequences[field0008].field0002 <= sequences[307].field0000))) && (C00->field344c == 0)) {
            ResetPose();
            ClearBufferedButtons();
            field0008 = 0x133;
            return;
        }
        if (((((recognizedCommand == 0x98) && (meter >= 3000)) && ((sequences[field0008].data[field000a].frameFlags & 8) > 0)) && (positionY == 0.0)) && (((((field0008 >= 200 && (attackCollisionResult >= 2)) && (attackCollisionResult != 6)) || (field0008 < 200)) && ((sequences[field0008].field0002 <= sequences[310].field0000 || ((field0008 > 0xfc && field0008 < 0x100) && attackCollisionResult == 3))))) && (C00->field344c == 0)) {
            ResetPose();
            ClearBufferedButtons();
            field0008 = 0x136;
            return;
        }
        if (((((recognizedCommand == 0x97) || (recognizedCommand == 0x98)) && ((meter >= 2000 && (((sequences[field0008].data[field000a].frameFlags & 8) > 0 && (positionY == 0.0)))))) && (((field0008 >= 200 && ((attackCollisionResult >= 2 && (attackCollisionResult != 6)))) || (field0008 < 200)))) && ((sequences[field0008].field0002 <= sequences[309].field0000 || ((field0008 > 0xfc && field0008 < 0x100) && attackCollisionResult == 3))) && (C00->field344c == 0)) {
            ResetPose();
            ClearBufferedButtons();
            field0008 = 0x135;
            return;
        }
        if ((((((recognizedCommand == 0x96) || (recognizedCommand == 0x97)) || (recognizedCommand == 0x98)) && (((meter >= 1000 && ((sequences[field0008].data[field000a].frameFlags & 8) > 0)) && (positionY == 0.0)))) && ((((field0008 >= 200 && (attackCollisionResult >= 2)) && (attackCollisionResult != 6)) || (field0008 < 200)))) && ((sequences[field0008].field0002 <= sequences[308].field0000 || ((field0008 > 0xfc && field0008 < 0x100) && attackCollisionResult == 3))) && (C00->field344c == 0)) {
            ResetPose();
            ClearBufferedButtons();
            field0008 = 0x134;
            return;
        }
        if (((((recognizedCommand == 0x66) && (meter >= 3000)) && ((sequences[field0008].data[field000a].frameFlags & 8) > 0)) && (positionY == 0.0)) && (((((field0008 >= 200 && (attackCollisionResult >= 2)) && (attackCollisionResult != 6)) || (field0008 < 200)) && (sequences[field0008].field0002 <= sequences[305].field0000))) && (C00->field344c == 1)) {
            ResetPose();
            ClearBufferedButtons();
            field0008 = 0x131;
            return;
        }
        if ((((((recognizedCommand == 0x65) || (recognizedCommand == 0x66))) && (meter >= 2000)) && (((sequences[field0008].data[field000a].frameFlags & 8) > 0 && (positionY == 0.0)))) && (((((field0008 >= 200 && (attackCollisionResult >= 2)) && (attackCollisionResult != 6)) || (field0008 < 200)) && (sequences[field0008].field0002 <= sequences[304].field0000))) && (C00->field344c == 1)) {
            ResetPose();
            ClearBufferedButtons();
            field0008 = 0x130;
            return;
        }
        if (((((recognizedCommand == 100) || (recognizedCommand == 0x65) || (recognizedCommand == 0x66))) && (meter >= 1000)) && ((((sequences[field0008].data[field000a].frameFlags & 8) > 0 && (positionY == 0.0)) && (((((field0008 >= 200 && (attackCollisionResult >= 2)) && (attackCollisionResult != 6)) || (field0008 < 200)) && (sequences[field0008].field0002 <= sequences[303].field0000))))) && (C00->field344c == 1)) {
            ResetPose();
            ClearBufferedButtons();
            field0008 = 0x12f;
            return;
        }
        if (((((recognizedCommand == 0x70) && (meter >= 3000)) && ((sequences[field0008].data[field000a].frameFlags & 8) > 0)) && ((((field0008 >= 200 && (attackCollisionResult >= 2)) && (attackCollisionResult != 6)) || (field0008 < 200)))) && (sequences[field0008].field0002 <= sequences[302].field0000) && (C00->field344c == 0) && (positionY == 0.0)) {
            ResetPose();
            ClearBufferedButtons();
            field0008 = 0x12e;
            return;
        }
        if (((recognizedCommand == 0x6f) || (recognizedCommand == 0x70)) && (((meter >= 2000 && ((sequences[field0008].data[field000a].frameFlags & 8) > 0)) && (((((field0008 >= 200 && (attackCollisionResult >= 2)) && (attackCollisionResult != 6)) || (field0008 < 200)) && (sequences[field0008].field0002 <= sequences[301].field0000))))) && (C00->field344c == 0) && (positionY == 0.0)) {
            ResetPose();
            ClearBufferedButtons();
            field0008 = 0x12d;
            return;
        }
        if ((((((recognizedCommand == 0x6e) || (recognizedCommand == 0x6f)) || (recognizedCommand == 0x70)) && ((meter >= 1000 && ((sequences[field0008].data[field000a].frameFlags & 8) > 0)))) && (((field0008 >= 200 && ((attackCollisionResult >= 2 && (attackCollisionResult != 6)))) || (field0008 < 200)))) && (sequences[field0008].field0002 <= sequences[300].field0000) && (C00->field344c == 0) && (positionY == 0.0)) {
            ResetPose();
            ClearBufferedButtons();
            field0008 = 300;
            return;
        }
        if ((((recognizedCommand == 0x16) && (((field0118 >= 500.0 || ('\0' < (char)field0120)) && ((sequences[field0008].data[field000a].frameFlags & 8) > 0)))) && (C00->field344c == 0)) && (((((field0008 >= 200 && (attackCollisionResult >= 2)) && (attackCollisionResult != 6)) || (field0008 < 200)) && (sequences[field0008].field0002 <= sequences[258].field0000)))) {
            ResetPose();
            ClearBufferedButtons();
            field0008 = 0x102;
            if (positionY >= 0.0) {
                return;
            }
            field000a = 9;
            C00->field3140 = 1;
            attackCollisionResult = 3;
            return;
        }
        if ((((recognizedCommand == 0x15) || (recognizedCommand == 0x16)) && (((sequences[field0008].data[field000a].frameFlags & 8) > 0 && (C00->field344c == 0)))) && (((((field0008 >= 200 && (attackCollisionResult >= 2)) && (attackCollisionResult != 6)) || (field0008 < 200)) && (sequences[field0008].field0002 <= sequences[257].field0000)))) {
            ResetPose();
            ClearBufferedButtons();
            field0008 = 0x101;
            if (positionY >= 0.0) {
                return;
            }
            field000a = 9;
            attackCollisionResult = 3;
            return;
        }
        if ((recognizedCommand == 0x14) && ((((sequences[field0008].data[field000a].frameFlags & 8) > 0 && (C00->field344c == 0)) && ((((field0008 >= 200 && ((attackCollisionResult >= 2 && (attackCollisionResult != 6)))) || (field0008 < 200)) && (sequences[field0008].field0002 <= sequences[256].field0000)))))) {
            ResetPose();
            ClearBufferedButtons();
            field0008 = 0x100;
            if (positionY >= 0.0) {
                return;
            }
            field000a = 9;
            attackCollisionResult = 3;
            return;
        }
        if (((recognizedCommand == 0x20) && ((((field0118 >= 500.0 || ('\0' < (char)field0120)) && ((sequences[field0008].data[field000a].frameFlags & 8) > 0)) && ((positionY == 0.0 && (C00->field344c == 0)))))) && ((((field0008 >= 200 && ((attackCollisionResult >= 2 && (attackCollisionResult != 6)))) || (field0008 < 200)) && (sequences[field0008].field0002 <= sequences[261].field0000)))) {
            ResetPose();
            ClearBufferedButtons();
            field0008 = 0x105;
            return;
        }
        if ((((recognizedCommand == 0x1f) || (recognizedCommand == 0x20)) && ((sequences[field0008].data[field000a].frameFlags & 8) > 0)) && (((positionY == 0.0 && (C00->field344c == 0)) && ((((field0008 >= 200 && ((attackCollisionResult >= 2 && (attackCollisionResult != 6)))) || (field0008 < 200)) && (sequences[field0008].field0002 <= sequences[260].field0000)))))) {
            ResetPose();
            ClearBufferedButtons();
            field0008 = 0x104;
            return;
        }
        if (((recognizedCommand == 0x1e) && ((((sequences[field0008].data[field000a].frameFlags & 8) > 0 && (positionY == 0.0)) && (C00->field344c == 0)))) && (((((field0008 >= 200 && (attackCollisionResult >= 2)) && (attackCollisionResult != 6)) || (field0008 < 200)) && (sequences[field0008].field0002 <= sequences[259].field0000)))) {
            ResetPose();
            ClearBufferedButtons();
            field0008 = 0x103;
            return;
        }
        if (((recognizedCommand == 0x48) && (sequences[field0008].data[field000a].frameFlags & 8) > 0 && (positionY == 0.0) && (((field0008 >= 200 && attackCollisionResult >= 2 && attackCollisionResult != 6)) || (field0008 < 200)) && (sequences[field0008].field0002 <= sequences[250].field0000))) {
            ResetPose();
            ClearBufferedButtons();
            field0008 = 0xfa;
            if (C00->field344c != 0) {
                return;
            }
            field0008 = 0x108;
            return;
        }
        if (((recognizedCommand == 0x47) && (sequences[field0008].data[field000a].frameFlags & 8) > 0 && (positionY == 0.0) && (((field0008 >= 200 && attackCollisionResult >= 2 && attackCollisionResult != 6)) || (field0008 < 200)) && (sequences[field0008].field0002 <= sequences[250].field0000))) {
            ResetPose();
            ClearBufferedButtons();
            field0008 = 0xfa;
            if (C00->field344c != 0) {
                return;
            }
            field0008 = 0x107;
            return;
        }
        if (((recognizedCommand == 0x46) && (sequences[field0008].data[field000a].frameFlags & 8) > 0 && (positionY == 0.0) && (((field0008 >= 200 && attackCollisionResult >= 2 && attackCollisionResult != 6)) || (field0008 < 200)) && (sequences[field0008].field0002 <= sequences[250].field0000))) {
            ResetPose();
            ClearBufferedButtons();
            field0008 = 0xfa;
            return;
        }
        if ((((recognizedCommand == 0xc) && (((field0118 >= 500.0 || ('\0' < (char)field0120)) && ((sequences[field0008].data[field000a].frameFlags & 8) > 0)))) && (positionY == 0.0)) && (((((field0008 >= 200 && (attackCollisionResult >= 2)) && (attackCollisionResult != 6)) || (field0008 < 200)) && (sequences[field0008].field0002 <= sequences[255].field0000))) && (C00->field344c == 0)) {
            ResetPose();
            ClearBufferedButtons();
            field0008 = 0xff;
            return;
        }
        if ((((recognizedCommand == 0xb) || (recognizedCommand == 0xc)) && (((sequences[field0008].data[field000a].frameFlags & 8) > 0 && (positionY == 0.0)))) && (((((field0008 >= 200 && (attackCollisionResult >= 2)) && (attackCollisionResult != 6)) || (field0008 < 200)) && (sequences[field0008].field0002 <= sequences[254].field0000))) && (C00->field344c == 0)) {
            ResetPose();
            ClearBufferedButtons();
            field0008 = 0xfe;
            return;
        }
        if (((recognizedCommand == 10) && ((sequences[field0008].data[field000a].frameFlags & 8) > 0)) && (((positionY == 0.0 && ((((field0008 >= 200 && (attackCollisionResult >= 2)) && (attackCollisionResult != 6)) || (field0008 < 200)))) && (sequences[field0008].field0002 <= sequences[253].field0000))) && (C00->field344c == 0)) {
            ResetPose();
            ClearBufferedButtons();
            field0008 = 0xfd;
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
    if ((((((field015c < 3) && (recognizedCommand == 6)) && ((sequences[field0008].data[field000a].frameFlags & 8) > 0)) && ((positionY < 0.0 && (airActionCount < 1)))) && (sequences[field0008].field0002 <= sequences[14].field0000)) && ((((field0008 >= 200 && (attackCollisionResult >= 2)) && (attackCollisionResult != 6)) || (field0008 < 200)))) {
        ResetPose();
        ClearBufferedButtons();
        ++airActionCount;
        field0008 = 0xe;
        if ((char)inputX == (char)facing) {
            field0008 = 0xf;
        }
        if ((int)inputX == -(int)facing) {
            field0008 = 0x10;
        }
        return;
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

#undef C00
