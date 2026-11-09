// Mayu action selection over current command and animation state.
#include "CharacterViews.h"

void Character05::Slot04()
{
    if (field0008 < 200) {
        field01a8 = 0;
    }
    if (field01aa <= 0) {
        field01a9 = 0;
    }
    else {
        --field01aa;
    }
    if (field01a9 == '\0') {
        field01aa = 0;
    }
    if ((field0262 == 0x34) && (((((field0118 >= 500.0 && (1 < field0168)) && (field0168 != 6)) || (('\0' < (char)field0120 && (1 < field0168)))) && (((sequences[field0008].data[field000a].frameFlags & 8) > 0 && (sequences[field0008].field0002 <= sequences[167].field0000)))))) {
        ResetPose();
        ClearBufferedButtons();
        field0008 = 0xa7;
        if (positionY < 0.0) {
            field0008 = 0xab;
        }
        return;
    }
    if (field015c < 2) {
        if ((((field0108 < 0xd05) && (field0262 == 0x62)) && ((field0148 >= 3000 && ((((sequences[field0008].data[field000a].frameFlags & 8) > 0 && (positionY == 0.0)) && (field0168 != 6)))))) && (sequences[field0008].field0002 <= sequences[303].field0000)) {
            ResetPose();
            ClearBufferedButtons();
            field0008 = 0x12f;
            if (positionX - (*opponentSlot)->positionX < 60.0 &&
                positionX - (*opponentSlot)->positionX > -60.0) {
                field0008 = 0x130;
            }
            return;
        }
        if (((((field0262 == 0x70) && (field0148 >= 3000)) && (((sequences[field0008].data[field000a].frameFlags & 8) > 0 && (positionY == 0.0)))) && ((((field0008 >= 200 && (field0168 >= 2)) && (field0168 != 6)) || (field0008 < 200)))) && (sequences[field0008].field0002 <= sequences[316].field0000)) {
            ResetPose();
            ClearBufferedButtons();
            field0008 = 0x13c;
            return;
        }
        if (((((field0262 == 0x6f) || (field0262 == 0x70)) && (field0148 >= 2000)) && (((sequences[field0008].data[field000a].frameFlags & 8) > 0 && (positionY == 0.0)))) && ((((field0008 >= 200 && ((field0168 >= 2 && (field0168 != 6)))) || (field0008 < 200)) && (sequences[field0008].field0002 <= sequences[315].field0000)))) {
            ResetPose();
            ClearBufferedButtons();
            field0008 = 0x13b;
            return;
        }
        if ((((((field0262 == 0x6e) || (field0262 == 0x6f) ) || (field0262 == 0x70)) && ((field0148 >= 1000 && ((sequences[field0008].data[field000a].frameFlags & 8) > 0)))) && ((positionY == 0.0 && ((((field0008 >= 200 && (field0168 >= 2)) && (field0168 != 6)) || (field0008 < 200)))))) && (sequences[field0008].field0002 <= sequences[314].field0000)) {
            ResetPose();
            ClearBufferedButtons();
            field0008 = 0x13a;
            return;
        }
        if ((((field0262 == 0x7a) && (field0148 >= 3000)) && ((sequences[field0008].data[field000a].frameFlags & 8) > 0)) && ((positionY == 0.0 && (((((field0008 >= 200 && (field0168 >= 2)) && (field0168 != 6)) || (field0008 < 200)) && (sequences[field0008].field0002 <= sequences[310].field0000)))))) {
            ResetPose();
            ClearBufferedButtons();
            field0008 = 0x136;
            return;
        }
        if ((((field0262 == 0x79) || (field0262 == 0x7a)) && ((field0148 >= 2000 && (((sequences[field0008].data[field000a].frameFlags & 8) > 0 && (positionY == 0.0)))))) && ((((field0008 >= 200 && ((field0168 >= 2 && (field0168 != 6)))) || (field0008 < 200)) && (sequences[field0008].field0002 <= sequences[309].field0000)))) {
            ResetPose();
            ClearBufferedButtons();
            field0008 = 0x135;
            return;
        }
        if ((((((field0262 == 0x78) || (field0262 == 0x79) ) || (field0262 == 0x7a)) && ((field0148 >= 1000 && ((sequences[field0008].data[field000a].frameFlags & 8) > 0)))) && (positionY == 0.0)) && (((((field0008 >= 200 && (field0168 >= 2)) && (field0168 != 6)) || (field0008 < 200)) && (sequences[field0008].field0002 <= sequences[308].field0000)))) {
            ResetPose();
            ClearBufferedButtons();
            field0008 = 0x134;
            return;
        }
        if (((((field0262 == 0xac) && (field0148 >= 3000)) && ((sequences[field0008].data[field000a].frameFlags & 8) > 0)) && (positionY == 0.0)) && (((((field0008 >= 200 && (field0168 >= 2)) && (field0168 != 6)) || (field0008 < 200)) && (sequences[field0008].field0002 <= sequences[321].field0000)))) {
            ResetPose();
            ClearBufferedButtons();
            field0008 = 0x141;
            return;
        }
        if ((((field0262 == 0xab) || (field0262 == 0xac)) && ((field0148 >= 2000 && (((sequences[field0008].data[field000a].frameFlags & 8) > 0 && (positionY == 0.0)))))) && ((((field0008 >= 200 && ((field0168 >= 2 && (field0168 != 6)))) || (field0008 < 200)) && (sequences[field0008].field0002 <= sequences[319].field0000)))) {
            ResetPose();
            ClearBufferedButtons();
            field0008 = 0x13f;
            return;
        }
        if ((((((field0262 == 0xaa) || (field0262 == 0xab) ) || (field0262 == 0xac)) && (((field0148 >= 1000 && ((sequences[field0008].data[field000a].frameFlags & 8) > 0)) && (positionY == 0.0)))) && ((((field0008 >= 200 && (field0168 >= 2)) && (field0168 != 6)) || (field0008 < 200)))) && (sequences[field0008].field0002 <= sequences[317].field0000)) {
            ResetPose();
            ClearBufferedButtons();
            field0008 = 0x13d;
            return;
        }
        if ((((field0262 == 0x48) && ((((field0118 >= 500.0 || ('\0' < (char)field0120)) && ((sequences[field0008].data[field000a].frameFlags & 8) > 0)) && (positionY == 0.0)))) && ((((field0008 >= 200 && (field0168 >= 2)) && (field0168 != 6)) || (field0008 < 200)))) && (sequences[field0008].field0002 <= sequences[252].field0000)) {
            ResetPose();
            ClearBufferedButtons();
            field0008 = 0xfc;
            return;
        }
        if ((((field0262 == 0x47) || (field0262 == 0x48)) && (((sequences[field0008].data[field000a].frameFlags & 8) > 0 && (positionY == 0.0)))) && (((((field0008 >= 200 && (field0168 >= 2)) && (field0168 != 6)) || (field0008 < 200)) && (sequences[field0008].field0002 <= sequences[251].field0000)))) {
            ResetPose();
            ClearBufferedButtons();
            field0008 = 0xfb;
            return;
        }
        if (((field0262 == 0x46) && ((sequences[field0008].data[field000a].frameFlags & 8) > 0)) && (((positionY == 0.0 && ((((field0008 >= 200 && (field0168 >= 2)) && (field0168 != 6)) || (field0008 < 200)))) && (sequences[field0008].field0002 <= sequences[250].field0000)))) {
            ResetPose();
            ClearBufferedButtons();
            field0008 = 0xfa;
            return;
        }
        if ((((field0262 == 0x49) && ((sequences[field0008].data[field000a].frameFlags & 8) > 0)) && (positionY == 0.0)) && (((((field0008 >= 200 && (field0168 >= 2)) && (field0168 != 6)) || (field0008 < 200)) && (sequences[field0008].field0002 <= sequences[283].field0000)))) {
            ResetPose();
            ClearBufferedButtons();
            field0008 = 0x11b;
            return;
        }
        if ((((field0262 == 0x16) && ((field0118 >= 500.0 || ('\0' < (char)field0120)))) && ((sequences[field0008].data[field000a].frameFlags & 8) > 0)) && ((positionY == 0.0 && (((((field0008 >= 200 && (field0168 >= 2)) && (field0168 != 6)) || (field0008 < 200)) && (sequences[field0008].field0002 <= sequences[268].field0000)))))) {
            ResetPose();
            ClearBufferedButtons();
            field0008 = 0x10c;
            return;
        }
        if (((((field0262 == 0x15) || (field0262 == 0x16)) && (((sequences[field0008].data[field000a].frameFlags & 8) > 0 && (positionY == 0.0)))) && ((((field0008 >= 200 && (field0168 >= 2)) && (field0168 != 6)) || (field0008 < 200)))) && (sequences[field0008].field0002 <= sequences[267].field0000)) {
            ResetPose();
            ClearBufferedButtons();
            field0008 = 0x10b;
            return;
        }
        if ((((field0262 == 0x14) && ((sequences[field0008].data[field000a].frameFlags & 8) > 0)) && (positionY == 0.0)) && (((((field0008 >= 200 && (field0168 >= 2)) && (field0168 != 6)) || (field0008 < 200)) && (sequences[field0008].field0002 <= sequences[266].field0000)))) {
            ResetPose();
            ClearBufferedButtons();
            field0008 = 0x10a;
            return;
        }
        if ((((field0262 == 0xc) && ((field0118 >= 500.0 || ('\0' < (char)field0120)))) && ((sequences[field0008].data[field000a].frameFlags & 8) > 0)) && (((((field0008 >= 200 && (field0168 >= 2)) && (field0168 != 6)) || (field0008 < 200)) && (sequences[field0008].field0002 <= sequences[261].field0000)))) {
            ResetPose();
            ClearBufferedButtons();
            field0008 = 0x105;
            if (positionY < 0.0) {
                field0008 = 0x11a;
            }
            return;
        }
        if (((((field0262 == 0xb) || (field0262 == 0xc)) && ((sequences[field0008].data[field000a].frameFlags & 8) > 0)) && ((((field0008 >= 200 && (field0168 >= 2)) && (field0168 != 6)) || (field0008 < 200)))) && (sequences[field0008].field0002 <= sequences[260].field0000)) {
            ResetPose();
            ClearBufferedButtons();
            field0008 = 0x104;
            if (positionY < 0.0) {
                field0008 = 0x119;
            }
            return;
        }
        if (((field0262 == 10) && ((sequences[field0008].data[field000a].frameFlags & 8) > 0)) && ((((field0008 >= 200 && ((field0168 >= 2 && (field0168 != 6)))) || (field0008 < 200)) && (sequences[field0008].field0002 <= sequences[259].field0000)))) {
            ResetPose();
            ClearBufferedButtons();
            field0008 = 0x103;
            if (positionY < 0.0) {
                field0008 = 0x118;
            }
            return;
        }
        if ((((field0262 == 0x21) && ((sequences[field0008].data[field000a].frameFlags & 8) > 0)) && (sequences[field0008].field0002 <= sequences[273].field0000)) && ((((field0008 >= 200 && (field0168 >= 2)) && (field0168 != 6)) || (field0008 < 200)))) {
            ResetPose();
            ClearBufferedButtons();
            field0008 = 0x111;
            if (positionY < 0.0) {
                field000a = 4;
            }
            return;
        }
        if (((field0262 == 0x20) && ((sequences[field0008].data[field000a].frameFlags & 8) > 0)) && ((sequences[field0008].field0002 <= sequences[274].field0000 && ((((field0008 >= 200 && (field0168 >= 2)) && (field0168 != 6)) || (field0008 < 200)))))) {
            ResetPose();
            ClearBufferedButtons();
            field0008 = 0x112;
            if (positionY < 0.0) {
                field000a = 4;
            }
            return;
        }
        if (((field0262 == 0x1f) && ((sequences[field0008].data[field000a].frameFlags & 8) > 0)) && ((sequences[field0008].field0002 <= sequences[289].field0000 && ((((field0008 >= 200 && (field0168 >= 2)) && (field0168 != 6)) || (field0008 < 200)))))) {
            ResetPose();
            ClearBufferedButtons();
            field0008 = 0x121;
            if (positionY < 0.0) {
                field000a = 4;
            }
            return;
        }
        if ((((field0262 == 0x1e) && ((sequences[field0008].data[field000a].frameFlags & 8) > 0)) && (sequences[field0008].field0002 <= sequences[272].field0000)) && ((((field0008 >= 200 && (field0168 >= 2)) && (field0168 != 6)) || (field0008 < 200)))) {
            ResetPose();
            ClearBufferedButtons();
            field0008 = 0x110;
            if (positionY < 0.0) {
                field000a = 4;
            }
            return;
        }
    }
    if ((field015c < 1) && ((field0262 == 0 || (field0262 == 1)))) {
        if ((positionY < 0.0) && (field0159 < 1)) {
            if (((((((*opponentSlot)->positionX - positionX) * (1 - field0262 * 2) < 0.0 ) || ((0.0 == (*opponentSlot)->positionX - positionX && ((int)(char)facing == ((1 - field0262 * 2) * -1))))) && (sequences[field0008].field0002 <= sequences[165].field0000)) && (((field0008 != 0xaa && (positionY < -40.0)) && ((sequences[field0008].data[field000a].frameFlags & 8) > 0)))) && ((((field0008 >= 200 && (field0168 >= 2)) && (field0168 != 6)) || (field0008 < 200)))) {
                if (field0008 != 0xa5) {
                    ResetPose();
                }
                field0008 = 0xa5;
                FaceOpponent();
                ++field0159;
                field01a8 = 0;
                return;
            }
            if (((0.0 < ((*opponentSlot)->positionX - positionX) * (1 - field0262 * 2)) || ((0.0 == (*opponentSlot)->positionX - positionX && ((int)(char)facing == 1 - field0262 * 2)))) && (((sequences[field0008].field0002 <= sequences[166].field0000 && ((field0008 != 0xaa && ((sequences[field0008].data[field000a].frameFlags & 8) > 0)))) && (((field0008 >= 200 && ((field0168 >= 2 && (field0168 != 6)))) || (field0008 < 200)))))) {
                if (field0008 != 0xa6) {
                    ResetPose();
                }
                field0008 = 0xa6;
                FaceOpponent();
                ++field0159;
                field01a8 = 0;
                return;
            }
        }
        if ((positionY == 0.0) && ((sequences[field0008].data[field000a].frameFlags & 8) > 0)) {
            if ((((((*opponentSlot)->positionX - positionX) * (1 - field0262 * 2) < 0.0) || ((0.0 == (*opponentSlot)->positionX - positionX && ((int)(char)facing == ((1 - field0262 * 2) * -1))))) && (sequences[field0008].field0002 <= sequences[163].field0000)) && ((((field0008 >= 200 && (field0168 >= 2)) && (field0168 != 6)) || (field0008 < 200)))) {
                if (field0008 != 0xa3) {
                    ResetPose();
                }
                field0008 = 0xa3;
                FaceOpponent();
                ++field0158;
                field01a8 = 0;
                return;
            }
            if (((0.0 < ((*opponentSlot)->positionX - positionX) * (1 - field0262 * 2)) || ((0.0 == (*opponentSlot)->positionX - positionX && ((int)(char)facing == 1 - field0262 * 2)))) && ((sequences[field0008].field0002 <= sequences[164].field0000 && ((((field0008 >= 200 && (field0168 >= 2)) && (field0168 != 6)) || (field0008 < 200)))))) {
                if (field0008 != 0xa4) {
                    ResetPose();
                }
                field0008 = 0xa4;
                FaceOpponent();
                field01a8 = 0;
                return;
            }
        }
    }
    if ((((((field015c < 3) && (field0262 == 6)) && ((sequences[field0008].data[field000a].frameFlags & 8) > 0)) && ((positionY < 0.0 && (field015a < 1)))) && (sequences[field0008].field0002 <= sequences[14].field0000)) && ((((field0008 >= 200 && (field0168 >= 2)) && (field0168 != 6)) || (field0008 < 200)))) {
        ResetPose();
        ClearBufferedButtons();
        ++field015a;
        field0008 = 0xe;
        if ((char)inputX == (char)facing) {
            field0008 = 0xf;
        }
        if ((int)inputX == -(int)facing) {
            field0008 = 0x10;
        }
        return;
    }
    if (((buttonPulse[0] == '\x01') || ((field01a8 & 0x10) != 0)) || ((field01a9 & 0x10) != 0)) {
        if (((positionY < 0.0) && (field0008 == 0xa3)) && (5 < field000a)) {
            if (sequences[field0008].field0002 <= sequences[230].field0000 &&
                ((field0008 >= 200 && field0168 >= 2 && field0168 != 6) || field0008 < 200)) {
                ResetPose();
                ClearBufferedButtons();
                field0008 = 230;
            }
            return;
        }
        if (positionY < 0.0) {if (sequences[field0008].field0002 <= sequences[207].field0000 &&
                (sequences[field0008].data[field000a].frameFlags & 8) > 0 &&
                ((field0008 >= 200 && field0168 >= 2 && field0168 != 6) || field0008 < 200)) {
                ResetPose();
                ClearBufferedButtons();
                field0008 = 207;
            }
            return;
        }
        if (((((inputY == '\x01') || ((field01a8 & 4) != 0)) || ((field01a9 & 4) != 0)) && ((sequences[field0008].field0002 <= sequences[204].field0000 && ((sequences[field0008].data[field000a].frameFlags & 8) > 0)))) && (((field0008 >= 200 && ((field0168 >= 2 && (field0168 != 6)))) || (field0008 < 200)))) {
            ResetPose();
            ClearBufferedButtons();
            field0008 = 0xcc;
            return;
        }
        if ((((inputY == '\0') || ((field01a8 & 4) == 0)) || ((field01a9 & 4) == 0)) && (((sequences[field0008].field0002 <= sequences[200].field0000 && ((sequences[field0008].data[field000a].frameFlags & 8) > 0)) && (((field0008 >= 200 && ((field0168 >= 2 && (field0168 != 6)))) || (field0008 < 200)))))) {
            ResetPose();
            ClearBufferedButtons();
            field0008 = 200;
            return;
        }
    }
    if (((buttonPulse[1] == '\x01') || ((field01a8 & 0x20) != 0)) || ((field01a9 & 0x20) != 0)) {
        if (((positionY < 0.0) && (field0008 == 0xa3)) && (5 < field000a)) {
            if (sequences[field0008].field0002 <= sequences[231].field0000 &&
                ((field0008 >= 200 && field0168 >= 2 && field0168 != 6) || field0008 < 200)) {
                ResetPose();
                ClearBufferedButtons();
                field0008 = 231;
            }
            return;
        }
        if (positionY < 0.0) {if (sequences[field0008].field0002 <= sequences[208].field0000 &&
                (sequences[field0008].data[field000a].frameFlags & 8) > 0 &&
                ((field0008 >= 200 && field0168 >= 2 && field0168 != 6) || field0008 < 200)) {
                ResetPose();
                ClearBufferedButtons();
                field0008 = 208;
            }
            return;
        }
        if ((((inputY == '\x01') || ((field01a8 & 4) != 0)) || ((field01a9 & 4) != 0)) && (((((int)(char)inputX == -(int)(char)facing && (sequences[field0008].field0002 <= sequences[211].field0000)) && ((sequences[field0008].data[field000a].frameFlags & 8) > 0)) && ((((field0008 >= 200 && (field0168 >= 2)) && (field0168 != 6)) || (field0008 < 200)))))) {
            ResetPose();
            ClearBufferedButtons();
            field0008 = 0xd3;
            return;
        }
        if (((((inputY == '\x01') || ((field01a8 & 4) != 0)) || ((field01a9 & 4) != 0)) && ((sequences[field0008].field0002 <= sequences[205].field0000 && ((sequences[field0008].data[field000a].frameFlags & 8) > 0)))) && (((field0008 >= 200 && ((field0168 >= 2 && (field0168 != 6)))) || (field0008 < 200)))) {
            ResetPose();
            ClearBufferedButtons();
            field0008 = 0xcd;
            return;
        }
        if (((inputY == '\0') || ((field01a8 & 4) == 0)) || ((field01a9 & 4) == 0)) {
            if (((((char)inputX == (char)facing) && (sequences[field0008].field0002 <= sequences[210].field0000)) && ((sequences[field0008].data[field000a].frameFlags & 8) > 0)) && ((((field0008 >= 200 && (field0168 >= 2)) && (field0168 != 6)) || (field0008 < 200)))) {
                ResetPose();
                ClearBufferedButtons();
                field0008 = 0xd2;
                return;
            }
            if (((((sequences[field0008].field0002 <= sequences[201].field0000) && ((sequences[field0008].data[field000a].frameFlags & 8) > 0)) && (positionX - (*opponentSlot)->positionX > -70.0)) && (positionX - (*opponentSlot)->positionX < 70.0)) && ((((field0008 >= 200 && (field0168 >= 2)) && (field0168 != 6)) || (field0008 < 200)))) {
                ResetPose();
                ClearBufferedButtons();
                field0008 = 0xc9;
                return;
            }
            if (((sequences[field0008].field0002 <= sequences[202].field0000) && ((sequences[field0008].data[field000a].frameFlags & 8) > 0)) && (((field0008 >= 200 && ((field0168 >= 2 && (field0168 != 6)))) || (field0008 < 200)))) {
                ResetPose();
                ClearBufferedButtons();
                field0008 = 0xca;
                return;
            }
        }
    }
    if (buttonPulse[2] == 1 || (field01a8 & 0x40) != 0 || (field01a9 & 0x40) != 0) {
        if (positionY < 0.0 && field0008 == 163 && field000a > 5) {
            if (sequences[field0008].field0002 <= sequences[232].field0000 &&
                ((field0008 >= 200 && field0168 >= 2 && field0168 != 6) || field0008 < 200)) {
                ResetPose();
                ClearBufferedButtons();
                field0008 = 232;
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
                ((field0008 >= 200 && field0168 >= 2 && field0168 != 6) || field0008 < 200)) {
                ResetPose();
                ClearBufferedButtons();
                field0008 = 248;
                return;
            }
            if (sequences[field0008].field0002 <= sequences[209].field0000 &&
                (sequences[field0008].data[field000a].frameFlags & 8) > 0 &&
                ((field0008 >= 200 && field0168 >= 2 && field0168 != 6) || field0008 < 200)) {
                ResetPose();
                ClearBufferedButtons();
                field0008 = 209;
            }
            return;
        }
        if ((inputY == 1 || (field01a8 & 4) != 0 || (field01a9 & 4) != 0) &&
            sequences[field0008].field0002 <= sequences[206].field0000 &&
            (sequences[field0008].data[field000a].frameFlags & 8) > 0 &&
            ((field0008 >= 200 && field0168 >= 2 && field0168 != 6) || field0008 < 200)) {
            ResetPose();
            ClearBufferedButtons();
            field0008 = 206;
            return;
        }
        if (inputY == 0 || (field01a8 & 4) == 0 || (field01a9 & 4) == 0) {
            if (inputX != 0 && (*opponentSlot)->positionY == 0.0 &&
                positionX - (*opponentSlot)->positionX > -30.0 &&
                positionX - (*opponentSlot)->positionX < 30.0 &&
                sequences[field0008].field0002 <= sequences[220].field0000 &&
                ((*opponentSlot)->field0008 < 50 || (*opponentSlot)->field0008 > 156) &&
                (sequences[field0008].data[field000a].frameFlags & 8) > 0 &&
                ((field0008 >= 200 && field0168 >= 2 && field0168 != 6) || field0008 < 200)) {
                ResetPose();
                ClearBufferedButtons();
                field0008 = 220;
                return;
            }
            if (sequences[field0008].field0002 <= sequences[203].field0000 &&
                (sequences[field0008].data[field000a].frameFlags & 8) > 0 &&
                ((field0008 >= 200 && field0168 >= 2 && field0168 != 6) || field0008 < 200)) {
                ResetPose();
                ClearBufferedButtons();
                field0008 = 203;
            }
        }
    }
    return;
}
