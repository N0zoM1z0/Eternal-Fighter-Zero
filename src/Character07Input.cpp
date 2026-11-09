// Misaki action selection over current command and animation state.
#include "CharacterViews.h"

void Character07::Slot04()
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
    if ((field0262 == 0x34) && ((((field0118 >= 500.0 || ('\0' < (char)field0120)) && (1 < attackCollisionResult)) &&
        (attackCollisionResult != 6 && ((sequences[field0008].data[field000a].frameFlags & 8) > 0))) &&
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
        if ((((field0108 < 0xd05) && (field0262 == 0x5c)) && (meter >= 3000 &&
            ((sequences[field0008].data[field000a].frameFlags & 8) > 0 && (positionY == 0.0)))) && (((field0008
            >= 200 && (attackCollisionResult >= 2 && (attackCollisionResult != 6))) || (field0008 < 200)) &&
            (sequences[field0008].field0002 <= sequences[313].field0000))) {
            ResetPose();
            ClearBufferedButtons();
            field0008 = 0x139;
            return;
        }
        if ((((((field0262 == 0x66) && (meter >= 3000)) && (positionY < 0.0)) &&
            ((sequences[field0008].data[field000a].frameFlags & 8) > 0)) && (((field0008 >= 200 && (attackCollisionResult
            >= 2)) && (attackCollisionResult != 6)) || (field0008 < 200))) && (sequences[field0008].field0002 <=
            sequences[302].field0000)) {
            ResetPose();
            ClearBufferedButtons();
            field0008 = 0x12e;
            return;
        }
        if (((((field0262 == 0x65) || (field0262 == 0x66)) && (meter >= 2000 && (positionY < 0.0 &&
            ((sequences[field0008].data[field000a].frameFlags & 8) > 0)))) && ((field0008 >= 200 && (attackCollisionResult
            >= 2 && (attackCollisionResult != 6))) || (field0008 < 200))) && (sequences[field0008].field0002 <=
            sequences[301].field0000)) {
            ResetPose();
            ClearBufferedButtons();
            field0008 = 0x12d;
            return;
        }
        if ((((((field0262 == 100) || (field0262 == 0x65)) || (field0262 == 0x66)) && ((meter >= 1000 &&
            (positionY < 0.0)) && ((sequences[field0008].data[field000a].frameFlags & 8) > 0))) && (((field0008
            >= 200 && (attackCollisionResult >= 2)) && (attackCollisionResult != 6)) || (field0008 < 200))) &&
            (sequences[field0008].field0002 <= sequences[300].field0000)) {
            ResetPose();
            ClearBufferedButtons();
            field0008 = 300;
            return;
        }
        if ((((((field0262 == 0x66) && (meter >= 3000)) && (positionY == 0.0)) &&
            ((sequences[field0008].data[field000a].frameFlags & 8) > 0)) && (((field0008 >= 200 && (attackCollisionResult
            >= 2)) && (attackCollisionResult != 6)) || (field0008 < 200))) && (sequences[field0008].field0002 <=
            sequences[305].field0000)) {
            ResetPose();
            ClearBufferedButtons();
            field0008 = 0x131;
            return;
        }
        if ((((field0262 == 0x65) || (field0262 == 0x66)) && (meter >= 2000 && (positionY == 0.0 &&
            ((sequences[field0008].data[field000a].frameFlags & 8) > 0)))) && (((field0008 >= 200 && (attackCollisionResult
            >= 2 && (attackCollisionResult != 6))) || (field0008 < 200)) && (sequences[field0008].field0002 <=
            sequences[304].field0000))) {
            ResetPose();
            ClearBufferedButtons();
            field0008 = 0x130;
            return;
        }
        if ((((((field0262 == 100) || (field0262 == 0x65)) || (field0262 == 0x66)) && ((meter >= 1000 &&
            (positionY == 0.0)) && ((sequences[field0008].data[field000a].frameFlags & 8) > 0))) &&
            (((field0008 >= 200 && (attackCollisionResult >= 2)) && (attackCollisionResult != 6)) || (field0008 < 200))) &&
            (sequences[field0008].field0002 <= sequences[303].field0000)) {
            ResetPose();
            ClearBufferedButtons();
            field0008 = 0x12f;
            return;
        }
        if (((((field0262 == 0xa2) && (meter >= 3000)) && (positionY == 0.0)) &&
            ((sequences[field0008].data[field000a].frameFlags & 8) > 0)) && ((((field0008 >= 200 && (attackCollisionResult
            >= 2)) && (attackCollisionResult != 6)) || (field0008 < 200)) && (sequences[field0008].field0002 <=
            sequences[308].field0000))) {
            ResetPose();
            ClearBufferedButtons();
            field0008 = 0x134;
            return;
        }
        if (((((field0262 == 0xa1) || (field0262 == 0xa2)) && (meter >= 2000 && (positionY == 0.0 &&
            ((sequences[field0008].data[field000a].frameFlags & 8) > 0)))) && ((field0008 >= 200 && (attackCollisionResult
            >= 2 && (attackCollisionResult != 6))) || (field0008 < 200))) && (sequences[field0008].field0002 <=
            sequences[307].field0000)) {
            ResetPose();
            ClearBufferedButtons();
            field0008 = 0x133;
            return;
        }
        if (((((((field0262 == 0xa0) || (field0262 == 0xa1)) || (field0262 == 0xa2)) && (meter >= 1000 &&
            (positionY == 0.0))) && ((sequences[field0008].data[field000a].frameFlags & 8) > 0)) &&
            (((field0008 >= 200 && (attackCollisionResult >= 2)) && (attackCollisionResult != 6)) || (field0008 < 200))) &&
            (sequences[field0008].field0002 <= sequences[306].field0000)) {
            ResetPose();
            ClearBufferedButtons();
            field0008 = 0x132;
            return;
        }
        if ((((field0262 == 0x33) && ((sequences[field0008].data[field000a].frameFlags & 8) > 0)) && (positionY
            == 0.0)) && ((((field0008 >= 200 && (attackCollisionResult >= 2)) && (attackCollisionResult != 6)) || (field0008 < 200))
            && (sequences[field0008].field0002 <= sequences[265].field0000))) {
            ResetPose();
            ClearBufferedButtons();
            field0008 = 0x109;
            return;
        }
        if (((field0262 == 0x32) && ((sequences[field0008].data[field000a].frameFlags & 8) > 0)) && (positionY
            == 0.0 && ((((field0008 >= 200 && (attackCollisionResult >= 2)) && (attackCollisionResult != 6)) || (field0008 < 200)) &&
            (sequences[field0008].field0002 <= sequences[261].field0000)))) {
            ResetPose();
            ClearBufferedButtons();
            field0008 = 0x105;
            return;
        }
        if ((((field0262 == 0x16) && (field0118 >= 500.0 || ('\0' < (char)field0120))) &&
            ((sequences[field0008].data[field000a].frameFlags & 8) > 0)) && (positionY == 0.0 && ((((field0008
            >= 200 && (attackCollisionResult >= 2)) && (attackCollisionResult != 6)) || (field0008 < 200)) &&
            (sequences[field0008].field0002 <= sequences[258].field0000)))) {
            ResetPose();
            ClearBufferedButtons();
            field0008 = 0x102;
            return;
        }
        if (((((field0262 == 0x15) || (field0262 == 0x16)) && ((sequences[field0008].data[field000a].frameFlags
            & 8) > 0)) && (positionY == 0.0)) && ((((field0008 >= 200 && (attackCollisionResult >= 2)) && (attackCollisionResult !=
            6)) || (field0008 < 200)) && (sequences[field0008].field0002 <= sequences[260].field0000))) {
            ResetPose();
            ClearBufferedButtons();
            field0008 = 0x104;
            return;
        }
        if (((field0262 == 0x14) && ((sequences[field0008].data[field000a].frameFlags & 8) > 0)) && (positionY
            == 0.0 && ((((field0008 >= 200 && (attackCollisionResult >= 2)) && (attackCollisionResult != 6)) || (field0008 < 200)) &&
            (sequences[field0008].field0002 <= sequences[257].field0000)))) {
            ResetPose();
            ClearBufferedButtons();
            field0008 = 0x101;
            return;
        }
        if (((((field0262 == 0x20) && (field0118 >= 500.0 || ('\0' < (char)field0120))) &&
            ((sequences[field0008].data[field000a].frameFlags & 8) > 0)) && (((field0008 >= 200 && (attackCollisionResult
            >= 2)) && (attackCollisionResult != 6)) || (field0008 < 200))) && (sequences[field0008].field0002 <=
            sequences[252].field0000)) {
            ResetPose();
            ClearBufferedButtons();
            field0008 = 0xfc;
            return;
        }
        if ((((field0262 == 0x1f) || (field0262 == 0x20)) && ((sequences[field0008].data[field000a].frameFlags
            & 8) > 0)) && ((((field0008 >= 200 && (attackCollisionResult >= 2)) && (attackCollisionResult != 6)) || (field0008 < 200))
            && (sequences[field0008].field0002 <= sequences[251].field0000))) {
            ResetPose();
            ClearBufferedButtons();
            field0008 = 0xfb;
            if (positionY < 0.0) {
                field0008 = 0x108;
            }
            return;
        }
        if ((((field0262 == 0x1e) && ((sequences[field0008].data[field000a].frameFlags & 8) > 0)) &&
            ((field0008 >= 200 && (attackCollisionResult >= 2 && (attackCollisionResult != 6))) || (field0008 < 200))) &&
            (sequences[field0008].field0002 <= sequences[250].field0000)) {
            ResetPose();
            ClearBufferedButtons();
            field0008 = 0xfa;
            if (positionY < 0.0) {
                field0008 = 0x107;
            }
            return;
        }
        if (((field0262 == 0xc) && (((field0118 >= 500.0 || ('\0' < (char)field0120)) &&
            ((sequences[field0008].data[field000a].frameFlags & 8) > 0)) && (positionY == 0.0))) &&
            ((((field0008 >= 200 && (attackCollisionResult >= 2)) && (attackCollisionResult != 6)) || (field0008 < 200)) &&
            (sequences[field0008].field0002 <= sequences[256].field0000))) {
            ResetPose();
            ClearBufferedButtons();
            field0008 = 0x100;
            return;
        }
        if (((((field0262 == 0xb) || (field0262 == 0xc)) && ((sequences[field0008].data[field000a].frameFlags &
            8) > 0 && (positionY == 0.0))) && (((field0008 >= 200 && (attackCollisionResult >= 2)) && (attackCollisionResult != 6)) ||
            (field0008 < 200))) && (sequences[field0008].field0002 <= sequences[255].field0000)) {
            ResetPose();
            ClearBufferedButtons();
            field0008 = 0xff;
            return;
        }
        if (((field0262 == 10) && ((sequences[field0008].data[field000a].frameFlags & 8) > 0)) && ((positionY
            == 0.0 && (((field0008 >= 200 && (attackCollisionResult >= 2)) && (attackCollisionResult != 6)) || (field0008 < 200))) &&
            (sequences[field0008].field0002 <= sequences[254].field0000))) {
            ResetPose();
            ClearBufferedButtons();
            field0008 = 0xfe;
            return;
        }
    }
    if ((field015c < 1) && (field0262 == 0 || (field0262 == 1))) {
        if ((positionY < 0.0) && (field0159 < 1)) {
            if (((((((*opponentSlot)->positionX - positionX) * (1 - field0262 * 2) < 0.0 ) || (0.0 ==
                (*opponentSlot)->positionX - positionX && ((int)(char)facing == ((1 - field0262 * 2) * -1))))
                && (sequences[field0008].field0002 <= sequences[165].field0000)) && ((field0008 != 0xaa &&
                (positionY < -30.0)) && ((sequences[field0008].data[field000a].frameFlags & 8) > 0))) &&
                ((((field0008 >= 200 && (attackCollisionResult >= 2)) && (attackCollisionResult != 6)) || (field0008 < 200)) &&
                (field0008 != 0xfd))) {
                if (field0008 != 0xa5) {
                    ResetPose();
                }
                field0008 = 0xa5;
                FaceOpponent();
                ++field0159;
                ++field015a;
                field01a8 = 0;
                return;
            }
            if ((((0.0 < ((*opponentSlot)->positionX - positionX) * (1 - field0262 * 2)) || (0.0 ==
                (*opponentSlot)->positionX - positionX && ((int)(char)facing == 1 - field0262 * 2))) &&
                (field0008 != 0xaa && (sequences[field0008].field0002 <= sequences[166].field0000 &&
                ((sequences[field0008].data[field000a].frameFlags & 8) > 0)))) && ((field0008 >= 200 &&
                (attackCollisionResult >= 2 && (attackCollisionResult != 6))) || (field0008 < 200))) {
                if (field0008 != 0xa6) {
                    ResetPose();
                }
                field0008 = 0xa6;
                FaceOpponent();
                ++field0159;
                ++field015a;
                field01a8 = 0;
                return;
            }
        }
        if ((positionY == 0.0) && ((sequences[field0008].data[field000a].frameFlags & 8) > 0)) {
            if ((((((*opponentSlot)->positionX - positionX) * (1 - field0262 * 2) < 0.0) || (0.0 ==
                (*opponentSlot)->positionX - positionX && ((int)(char)facing == ((1 - field0262 * 2) * -1))))
                && (sequences[field0008].field0002 <= sequences[163].field0000)) && (((field0008 >= 200 &&
                (attackCollisionResult >= 2)) && (attackCollisionResult != 6)) || (field0008 < 200))) {
                if (field0008 != 0xa3) {
                    ResetPose();
                }
                field0008 = 0xa3;
                FaceOpponent();
                ++field0158;
                field01a8 = 0;
                return;
            }
            if ((((0.0 < ((*opponentSlot)->positionX - positionX) * (1 - field0262 * 2)) || (0.0 ==
                (*opponentSlot)->positionX - positionX && ((int)(char)facing == 1 - field0262 * 2))) &&
                (sequences[field0008].field0002 <= sequences[164].field0000)) && (((field0008 >= 200 &&
                (attackCollisionResult >= 2)) && (attackCollisionResult != 6)) || (field0008 < 200))) {
                if (field0008 != 0xa4) {
                    ResetPose();
                }
                field0008 = 0xa4;
                FaceOpponent();
                ++field0158;
                field01a8 = 0;
                return;
            }
        }
    }
    if ((((((field015c < 3) && (field0262 == 6)) && ((sequences[field0008].data[field000a].frameFlags & 8) >
        0)) && (positionY < 0.0 && (field015a < 1))) && (sequences[field0008].field0002 <=
        sequences[14].field0000)) && (((field0008 >= 200 && (attackCollisionResult >= 2)) && (attackCollisionResult != 6)) ||
        (field0008 < 200))) {
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
        if (((((inputY == '\x01') || ((field01a8 & 4) != 0)) || ((field01a9 & 4) != 0)) &&
            (sequences[field0008].field0002 <= sequences[204].field0000 &&
            ((sequences[field0008].data[field000a].frameFlags & 8) > 0))) && ((field0008 >= 200 && (attackCollisionResult
            >= 2 && (attackCollisionResult != 6))) || (field0008 < 200))) {
            ResetPose();
            ClearBufferedButtons();
            field0008 = 0xcc;
            return;
        }
        if ((((inputY == '\0') || ((field01a8 & 4) == 0)) || ((field01a9 & 4) == 0)) &&
            ((sequences[field0008].field0002 <= sequences[200].field0000 &&
            ((sequences[field0008].data[field000a].frameFlags & 8) > 0)) && ((field0008 >= 200 && (attackCollisionResult >=
            2 && (attackCollisionResult != 6))) || (field0008 < 200)))) {
            ResetPose();
            ClearBufferedButtons();
            field0008 = 200;
            return;
        }
    }
    if (((buttonPulse[1] == '\x01') || ((field01a8 & 0x20) != 0)) || ((field01a9 & 0x20) != 0)) {
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
        if (((((inputY == '\x01') || ((field01a8 & 4) != 0)) || ((field01a9 & 4) != 0)) &&
            (sequences[field0008].field0002 <= sequences[205].field0000 &&
            ((sequences[field0008].data[field000a].frameFlags & 8) > 0))) && ((field0008 >= 200 && (attackCollisionResult
            >= 2 && (attackCollisionResult != 6))) || (field0008 < 200))) {
            ResetPose();
            ClearBufferedButtons();
            field0008 = 0xcd;
            return;
        }
        if (((inputY == '\0') || ((field01a8 & 4) == 0)) || ((field01a9 & 4) == 0)) {
            if ((((sequences[field0008].field0002 <= sequences[201].field0000) &&
                ((sequences[field0008].data[field000a].frameFlags & 8) > 0)) && (positionX -
                (*opponentSlot)->positionX > -70.0 && (positionX - (*opponentSlot)->positionX < 70.0))) &&
                (((field0008 >= 200 && (attackCollisionResult >= 2)) && (attackCollisionResult != 6)) || (field0008 < 200))) {
                ResetPose();
                ClearBufferedButtons();
                field0008 = 0xc9;
                return;
            }
            if (((sequences[field0008].field0002 <= sequences[202].field0000) &&
                ((sequences[field0008].data[field000a].frameFlags & 8) > 0)) && ((field0008 >= 200 &&
                (attackCollisionResult >= 2 && (attackCollisionResult != 6))) || (field0008 < 200))) {
                ResetPose();
                ClearBufferedButtons();
                field0008 = 0xca;
                return;
            }
        }
    }
    if (buttonPulse[2] == 1 || (field01a8 & 0x40) != 0 || (field01a9 & 0x40) != 0) {
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
        if ((inputY == 1 || (field01a8 & 4) != 0 || (field01a9 & 4) != 0) &&
            sequences[field0008].field0002 <= sequences[206].field0000 &&
            (sequences[field0008].data[field000a].frameFlags & 8) > 0 &&
            ((field0008 >= 200 && attackCollisionResult >= 2 && attackCollisionResult != 6) || field0008 < 200)) {
            ResetPose();
            ClearBufferedButtons();
            field0008 = 206;
            return;
        }
        if (inputY == 0 || (field01a8 & 4) == 0 || (field01a9 & 4) == 0) {
            if ((*opponentSlot)->positionY == 0.0 && inputX != 0 &&
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
