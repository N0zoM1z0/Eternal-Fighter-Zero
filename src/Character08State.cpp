// Shiori state priority, command cancellation and grounded/airborne action selection.
#include "CharacterViews.h"

void Character08::Slot04()
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
    if ((((field0262 == 0x34) &&
        ((field0118 >= 500.0 && (1 < attackCollisionResult)) ||
        ('\0' < field0120 && (1 < attackCollisionResult && (attackCollisionResult != 6))))
        ) && ((sequences[field0008].data[field000a].frameFlags & 8) > 0)) &&
        (sequences[field0008].field0002 <=
        sequences[167].field0000)) {
        ResetPose();
        ClearBufferedButtons();
        field0008 = 0xa7;
        if (positionY < 0.0) {
            field0008 = 0xab;
        }
        return;
    }
    if (field015c < 2) {
        if (((((health < 0xd05) && (field0262 == 0x5f)) &&
            (meter >= 3000)) &&
            ((sequences[field0008].data[field000a].frameFlags & 8) > 0 &&
            (positionY == 0.0))) &&
            (attackCollisionResult != 6 &&
            (sequences[field0008].field0002 <=
            sequences[318].field0000))) {
            ResetPose();
            ClearBufferedButtons();
            field0008 = 0x13e;
            return;
        }
        if (((((field0262 == 0xac) && (meter >= 3000)) &&
            ((sequences[field0008].data[field000a].frameFlags & 8) > 0)) &&
            (((field0008 >= 200 && (attackCollisionResult >= 2)) && (attackCollisionResult != 6)) ||
            (field0008 < 200))) &&
            (sequences[field0008].field0002 <=
            sequences[317].field0000)) {
            ResetPose();
            ClearBufferedButtons();
            field0008 = 0x13d;
            if (positionY < 0.0) {
                field0008 = 0x13a;
            }
            return;
        }
        if (((((field0262 == 0xab) || (field0262 == 0xac))
            && (meter >= 2000 &&
            ((sequences[field0008].data[field000a].frameFlags & 8) > 0))) &&
            (((field0008 >= 200 && (attackCollisionResult >= 2)) && (attackCollisionResult != 6)) ||
            (field0008 < 200))) &&
            (sequences[field0008].field0002 <=
            sequences[316].field0000)) {
            ResetPose();
            ClearBufferedButtons();
            field0008 = 0x13c;
            if (positionY < 0.0) {
                field0008 = 0x139;
            }
            return;
        }
        if (((((field0262 == 0xaa) || (field0262 == 0xab))
            || (field0262 == 0xac)) &&
            (meter >= 1000 &&
            ((sequences[field0008].data[field000a].frameFlags & 8) > 0))) &&
            (((field0008 >= 200 && (attackCollisionResult >= 2 && (attackCollisionResult != 6))) ||
            (field0008 < 200)) &&
            (sequences[field0008].field0002 <=
            sequences[315].field0000))) {
            ResetPose();
            ClearBufferedButtons();
            field0008 = 0x13b;
            if (positionY < 0.0) {
                field0008 = 0x138;
            }
            return;
        }
        if (((((field0262 == 0x7a) && (meter >= 3000)) &&
            (positionY == 0.0)) &&
            ((sequences[field0008].data[field000a].frameFlags & 8) > 0)) &&
            ((((field0008 >= 200 && (attackCollisionResult >= 2)) && (attackCollisionResult != 6)) ||
            (field0008 < 200)) &&
            (sequences[field0008].field0002 <=
            sequences[305].field0000))) {
            ResetPose();
            ClearBufferedButtons();
            field0008 = 0x131;
            return;
        }
        if ((((field0262 == 0x7a) || (field0262 == 0x79))
            && (meter >= 2000 &&
            (positionY == 0.0 &&
            ((sequences[field0008].data[field000a].frameFlags & 8) > 0)))) &&
            (((field0008 >= 200 && (attackCollisionResult >= 2 && (attackCollisionResult != 6))) ||
            (field0008 < 200)) &&
            (sequences[field0008].field0002 <=
            sequences[304].field0000))) {
            ResetPose();
            ClearBufferedButtons();
            field0008 = 0x130;
            return;
        }
        if (((((field0262 == 0x78) || (field0262 == 0x79))
            || (field0262 == 0x7a)) &&
            ((meter >= 1000 && (positionY == 0.0)) &&
            ((sequences[field0008].data[field000a].frameFlags & 8) > 0))) &&
            ((((field0008 >= 200 && (attackCollisionResult >= 2)) && (attackCollisionResult != 6)) ||
            (field0008 < 200)) &&
            (sequences[field0008].field0002 <=
            sequences[303].field0000))) {
            ResetPose();
            ClearBufferedButtons();
            field0008 = 0x12f;
            return;
        }
        if (((((field0262 == 0x70) && (meter >= 3000)) &&
            (positionY == 0.0)) &&
            ((sequences[field0008].data[field000a].frameFlags & 8) > 0)) &&
            ((((field0008 >= 200 && (attackCollisionResult >= 2)) && (attackCollisionResult != 6)) ||
            (field0008 < 200)) &&
            (sequences[field0008].field0002 <=
            sequences[308].field0000))) {
            ResetPose();
            ClearBufferedButtons();
            field0008 = 0x134;
            return;
        }
        if ((((field0262 == 0x70) || (field0262 == 0x6f))
            && (meter >= 2000 &&
            (positionY == 0.0 &&
            ((sequences[field0008].data[field000a].frameFlags & 8) > 0)))) &&
            (((field0008 >= 200 && (attackCollisionResult >= 2 && (attackCollisionResult != 6))) ||
            (field0008 < 200)) &&
            (sequences[field0008].field0002 <=
            sequences[307].field0000))) {
            ResetPose();
            ClearBufferedButtons();
            field0008 = 0x133;
            return;
        }
        if (((((((field0262 == 0x6e) ||
            (field0262 == 0x6f)) ||
            (field0262 == 0x70)) &&
            (meter >= 1000 && (positionY == 0.0))) &&
            ((sequences[field0008].data[field000a].frameFlags & 8) > 0)) &&
            (((field0008 >= 200 && (attackCollisionResult >= 2)) && (attackCollisionResult != 6)) ||
            (field0008 < 200))) &&
            (sequences[field0008].field0002 <=
            sequences[306].field0000)) {
            ResetPose();
            ClearBufferedButtons();
            field0008 = 0x132;
            return;
        }
        if ((((field0262 == 0x2a) &&
            ((field0118 >= 500.0 || ('\0' < field0120)) ||
            (positionY == 0.0))) &&
            ((sequences[field0008].data[field000a].frameFlags & 8) > 0)) &&
            ((((field0008 >= 200 && (attackCollisionResult >= 2)) && (attackCollisionResult != 6)) ||
            (field0008 < 200)) &&
            (sequences[field0008].field0002 <=
            sequences[258].field0000))) {
            ResetPose();
            ClearBufferedButtons();
            field0008 = 0x102;
            if (positionY == 0.0) {
                field0008 = 0x10b;
            }
            return;
        }
        if ((((field0262 == 0x29) || (field0262 == 0x2a))
            && ((sequences[field0008].data[field000a].frameFlags & 8) > 0 &&
            (((field0008 >= 200 && (attackCollisionResult >= 2)) && (attackCollisionResult != 6))
            || (field0008 < 200)))) &&
            (sequences[field0008].field0002 <=
            sequences[257].field0000)) {
            ResetPose();
            ClearBufferedButtons();
            field0008 = 0x101;
            if (positionY == 0.0) {
                field0008 = 0x10a;
            }
            return;
        }
        if (((field0262 == 0x28) &&
            ((sequences[field0008].data[field000a].frameFlags & 8) > 0)) &&
            (((field0008 >= 200 && (attackCollisionResult >= 2 && (attackCollisionResult != 6))) ||
            (field0008 < 200)) &&
            (sequences[field0008].field0002 <=
            sequences[256].field0000))) {
            ResetPose();
            ClearBufferedButtons();
            field0008 = 0x100;
            if (positionY == 0.0) {
                field0008 = 0x109;
            }
            return;
        }
        if ((((field0262 == 0x16) &&
            (((field0118 >= 500.0 || ('\0' < field0120)) &&
            ((sequences[field0008].data[field000a].frameFlags & 8) > 0)) &&
            (positionY == 0.0))) &&
            (((field0008 >= 200 && (attackCollisionResult >= 2)) && (attackCollisionResult != 6)) ||
            (field0008 < 200))) &&
            (sequences[field0008].field0002 <=
            sequences[255].field0000)) {
            ResetPose();
            ClearBufferedButtons();
            field0008 = 0xff;
            return;
        }
        if ((((field0262 == 0x15) || (field0262 == 0x16))
            && ((sequences[field0008].data[field000a].frameFlags & 8) > 0 &&
            (positionY == 0.0))) &&
            ((((field0008 >= 200 && (attackCollisionResult >= 2)) && (attackCollisionResult != 6)) ||
            (field0008 < 200)) &&
            (sequences[field0008].field0002 <=
            sequences[254].field0000))) {
            ResetPose();
            ClearBufferedButtons();
            field0008 = 0xfe;
            return;
        }
        if (((field0262 == 0x14) &&
            ((sequences[field0008].data[field000a].frameFlags & 8) > 0)) &&
            (positionY == 0.0 &&
            ((((field0008 >= 200 && (attackCollisionResult >= 2)) && (attackCollisionResult != 6)) ||
            (field0008 < 200)) &&
            (sequences[field0008].field0002 <=
            sequences[253].field0000)))) {
            ResetPose();
            ClearBufferedButtons();
            field0008 = 0xfd;
            return;
        }
        if ((((field0262 == 0x20) &&
            ((field0118 >= 500.0 || ('\0' < field0120)) &&
            ((sequences[field0008].data[field000a].frameFlags & 8) > 0))) &&
            (((field0008 >= 200 && (attackCollisionResult >= 2)) && (attackCollisionResult != 6)) ||
            (field0008 < 200))) &&
            (field3148 == 0 &&
            (sequences[field0008].field0002 <=
            sequences[261].field0000))) {
            ResetPose();
            ClearBufferedButtons();
            field0008 = 0x105;
            if (positionY < 0.0) {
                field0008 = 0x10e;
            }
            return;
        }
        if ((((field0262 == 0x1f) || (field0262 == 0x20))
            && ((sequences[field0008].data[field000a].frameFlags & 8) > 0)) &&
            ((((field0008 >= 200 && (attackCollisionResult >= 2)) && (attackCollisionResult != 6)) ||
            (field0008 < 200)) &&
            (field3148 == 0 &&
            (sequences[field0008].field0002 <=
            sequences[259].field0000)))) {
            ResetPose();
            ClearBufferedButtons();
            field0008 = 0x104;
            if (positionY < 0.0) {
                field0008 = 0x10d;
            }
            return;
        }
        if ((((field0262 == 0x1e) &&
            ((sequences[field0008].data[field000a].frameFlags & 8) > 0)) &&
            ((field0008 >= 200 && (attackCollisionResult >= 2 && (attackCollisionResult != 6))) ||
            (field0008 < 200))) &&
            (field3148 == 0 &&
            (sequences[field0008].field0002 <=
            sequences[259].field0000))) {
            ResetPose();
            ClearBufferedButtons();
            field0008 = 0x103;
            if (positionY < 0.0) {
                field0008 = 0x10c;
            }
            return;
        }
        if (((field0262 == 0xc) &&
            ((field0118 >= 500.0 || ('\0' < field0120)) &&
            ((sequences[field0008].data[field000a].frameFlags & 8) > 0))) &&
            ((((field0008 >= 200 && (attackCollisionResult >= 2)) && (attackCollisionResult != 6)) ||
            (field0008 < 200)) &&
            (sequences[field0008].field0002 <=
            sequences[252].field0000))) {
            ResetPose();
            ClearBufferedButtons();
            field0008 = 0xfc;
            if (positionY < 0.0) {
                field0008 = 0x108;
            }
            return;
        }
        if ((((field0262 == 0xb) || (field0262 == 0xc)) &&
            ((sequences[field0008].data[field000a].frameFlags & 8) > 0 &&
            (((field0008 >= 200 && (attackCollisionResult >= 2)) && (attackCollisionResult != 6)) ||
            (field0008 < 200)))) &&
            (sequences[field0008].field0002 <=
            sequences[251].field0000)) {
            ResetPose();
            ClearBufferedButtons();
            field0008 = 0xfb;
            if (positionY < 0.0) {
                field0008 = 0x107;
            }
            return;
        }
        if (((field0262 == 10) &&
            ((sequences[field0008].data[field000a].frameFlags & 8) > 0)) &&
            (((field0008 >= 200 && (attackCollisionResult >= 2 && (attackCollisionResult != 6))) ||
            (field0008 < 200)) &&
            (sequences[field0008].field0002 <=
            sequences[250].field0000))) {
            ResetPose();
            ClearBufferedButtons();
            field0008 = 0xfa;
            if (positionY < 0.0) {
                field0008 = 0x106;
            }
            return;
        }
    }
    if ((field015c == 0) &&
        (field0262 == 0 || (field0262 == 1))) {
        if ((positionY < 0.0) && (airDashCount < 2)) {
            if (((((((*opponentSlot)->positionX - positionX) * (1 - field0262 * 2) < 0.0
                ) || (0.0 ==
                (*opponentSlot)->positionX - positionX &&
                ((int)facing == (1 - field0262 * 2) * -1)
                )) &&
                (sequences[field0008].field0002 <=
                sequences[165].field0000)) &&
                ((field0008 != 0xaa && (positionY < -40.0)) &&
                ((sequences[field0008].data[field000a].frameFlags & 8) > 0))) &&
                (((field0008 >= 200 && (attackCollisionResult >= 2)) && (attackCollisionResult != 6)) ||
                (field0008 < 200))) {
                if (field0008 != 0xa5) {
                    ResetPose();
                }
                field0008 = 0xa5;
                FaceOpponent();
                ++airDashCount;
                ++airActionCount;
                field01a8 = 0;
                return;
            }
            if (((((0.0 <
                ((*opponentSlot)->positionX - positionX) * (1 - field0262 * 2)) ||
                (0.0 == (*opponentSlot)->positionX - positionX
                && ((int)facing == 1 - field0262 * 2))) &&
                (sequences[field0008].field0002 <=
                sequences[166].field0000)) &&
                (field0008 != 0xaa &&
                ((sequences[field0008].data[field000a].frameFlags & 8) > 0))) &&
                ((field0008 >= 200 && (attackCollisionResult >= 2 && (attackCollisionResult != 6))) ||
                (field0008 < 200))) {
                if (field0008 != 0xa6) {
                    ResetPose();
                }
                field0008 = 0xa6;
                FaceOpponent();
                ++airDashCount;
                ++airActionCount;
                field01a8 = 0;
                return;
            }
        }
        if ((positionY == 0.0) &&
            ((sequences[field0008].data[field000a].frameFlags & 8) > 0)) {
            if (((((*opponentSlot)->positionX - positionX) * (1 - field0262 * 2) < 0.0)
                || (0.0 == (*opponentSlot)->positionX - positionX
                && ((int)facing == (1 - field0262 * 2) * -1)))
                && (sequences[field0008].field0002 <=
                sequences[163].field0000 &&
                (((field0008 >= 200 && (attackCollisionResult >= 2)) && (attackCollisionResult != 6)
                ) || (field0008 < 200)))) {
                if (field0008 != 0xa3) {
                    ResetPose();
                }
                field0008 = 0xa3;
                FaceOpponent();
                ++dashMomentumFlag;
                field01a8 = 0;
                return;
            }
            if ((((0.0 <
                ((*opponentSlot)->positionX - positionX) * (1 - field0262 * 2)) ||
                (0.0 == (*opponentSlot)->positionX - positionX
                && ((int)facing == 1 - field0262 * 2))) &&
                (sequences[field0008].field0002 <=
                sequences[164].field0000)) &&
                (((field0008 >= 200 && (attackCollisionResult >= 2)) && (attackCollisionResult != 6)) ||
                (field0008 < 200))) {
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
    if ((((((field015c < 3) && (field0262 == 6)) &&
        ((sequences[field0008].data[field000a].frameFlags & 8) > 0)) &&
        (positionY < 0.0 && (airActionCount < 1)))
        && (sequences[field0008].field0002 <=
        sequences[14].field0000)) &&
        (((field0008 >= 200 && (attackCollisionResult >= 2)) && (attackCollisionResult != 6)) ||
        (field0008 < 200))) {
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
    if (((buttonPulse[0] == '\x01') || ((field01a8 & 0x10) != 0)) ||
        ((field01a9 & 0x10) != 0)) {
        if ((field0008 == 0xa3) &&
            ((int)inputX != -(int)facing)) {
            ResetPose();
            ClearBufferedButtons();
            field0008 = 0xe6;
            if (inputY == '\x01') {
                field0008 = 0xe9;
            }
            return;
        }
        if (positionY < 0.0) {
            if (sequences[field0008].field0002 <= sequences[207].field0000
                && (sequences[field0008].data[field000a].frameFlags & 8) > 0
                && ((field0008 >= 200 && attackCollisionResult >= 2 && attackCollisionResult != 6) || field0008 < 200)) {
                ResetPose();
                ClearBufferedButtons();
                field0008 = 0xcf;
            }
            return;
        }
        if (((((inputY == '\x01') || ((field01a8 & 4) != 0)) ||
            ((field01a9 & 4) != 0)) &&
            (sequences[field0008].field0002 <=
            sequences[204].field0000 &&
            ((sequences[field0008].data[field000a].frameFlags & 8) > 0))) &&
            ((field0008 >= 200 && (attackCollisionResult >= 2 && (attackCollisionResult != 6))) ||
            (field0008 < 200))) {
            ResetPose();
            ClearBufferedButtons();
            field0008 = 0xcc;
            return;
        }
        if (((((inputY == '\0') || ((field01a8 & 4) == 0)) ||
            ((field01a9 & 4) == 0)) &&
            (sequences[field0008].field0002 <=
            sequences[200].field0000 &&
            ((sequences[field0008].data[field000a].frameFlags & 8) > 0))) &&
            ((field0008 >= 200 && (attackCollisionResult >= 2 && (attackCollisionResult != 6))) ||
            (field0008 < 200))) {
            ResetPose();
            ClearBufferedButtons();
            field0008 = 200;
            return;
        }
    }
    if (((buttonPulse[1] == '\x01') || ((field01a8 & 0x20) != 0)) ||
        ((field01a9 & 0x20) != 0)) {
        if ((field0008 == 0xa3) &&
            ((int)inputX != -(int)facing)) {
            ResetPose();
            ClearBufferedButtons();
            field0008 = 0xe7;
            if (inputY == '\x01') {
                field0008 = 0xea;
            }
            return;
        }
        if (positionY < 0.0) {
            if (sequences[field0008].field0002 <= sequences[208].field0000
                && (sequences[field0008].data[field000a].frameFlags & 8) > 0
                && ((field0008 >= 200 && attackCollisionResult >= 2 && attackCollisionResult != 6) || field0008 < 200)) {
                ResetPose();
                ClearBufferedButtons();
                field0008 = 0xd0;
            }
            return;
        }
        if (((((inputY == '\x01') || ((field01a8 & 4) != 0)) ||
            ((field01a9 & 4) != 0)) &&
            (sequences[field0008].field0002 <=
            sequences[205].field0000 &&
            ((sequences[field0008].data[field000a].frameFlags & 8) > 0))) &&
            ((field0008 >= 200 && (attackCollisionResult >= 2 && (attackCollisionResult != 6))) ||
            (field0008 < 200))) {
            ResetPose();
            ClearBufferedButtons();
            field0008 = 0xcd;
            return;
        }
        if (((inputY == '\0') || ((field01a8 & 4) == 0)) ||
            ((field01a9 & 4) == 0)) {
            if ((((sequences[field0008].field0002 <=
                sequences[201].field0000) &&
                ((sequences[field0008].data[field000a].frameFlags & 8) > 0)) &&
                (-70.0 < positionX - (*opponentSlot)->positionX &&
                (positionX - (*opponentSlot)->positionX < 70.0)))
                && (((field0008 >= 200 && (attackCollisionResult >= 2)) && (attackCollisionResult != 6))
                || (field0008 < 200))) {
                ResetPose();
                ClearBufferedButtons();
                field0008 = 0xc9;
                return;
            }
            if (((sequences[field0008].field0002 <=
                sequences[202].field0000) &&
                ((sequences[field0008].data[field000a].frameFlags & 8) > 0)) &&
                ((field0008 >= 200 && (attackCollisionResult >= 2 && (attackCollisionResult != 6))) ||
                (field0008 < 200))) {
                ResetPose();
                ClearBufferedButtons();
                field0008 = 0xca;
                return;
            }
        }
    }
    if (((buttonPulse[2] == '\x01') || ((field01a8 & 0x40) != 0)) ||
        ((field01a9 & 0x40) != 0)) {
        if ((field0008 == 0xa3) &&
            ((int)inputX != -(int)facing)) {
            ResetPose();
            ClearBufferedButtons();
            field0008 = 0xe8;
            if (inputY == '\x01') {
                field0008 = 0xeb;
            }
            return;
        }
        if (positionY < 0.0) {
            if (((((inputX == facing) &&
                (inputY == '\0')) &&
                (-100.0 < positionX - (*opponentSlot)->positionX &&
                (((positionX - (*opponentSlot)->positionX < 100.0
                && ((*opponentSlot)->positionY < 0.0)) &&
                (sequences[field0008].field0002 <=
                sequences[248].field0000)) &&
                ((*opponentSlot)->field0008 < 0x32 ||
                (0x9c < (*opponentSlot)->field0008))))) &&
                ((sequences[field0008].data[field000a].frameFlags & 8) > 0)) &&
                (((field0008 >= 200 && (attackCollisionResult >= 2)) && (attackCollisionResult != 6)) ||
                (field0008 < 200))) {
                ResetPose();
                ClearBufferedButtons();
                field0008 = 0xf8;
                return;
            }
            if (sequences[field0008].field0002 <= sequences[209].field0000
                && (sequences[field0008].data[field000a].frameFlags & 8) > 0
                && ((field0008 >= 200 && attackCollisionResult >= 2 && attackCollisionResult != 6) || field0008 < 200)) {
                ResetPose();
                ClearBufferedButtons();
                field0008 = 0xd1;
            }
            return;
        }
        if ((((inputY == '\x01') || ((field01a8 & 4) != 0)) ||
            ((field01a9 & 4) != 0)) &&
            ((sequences[field0008].field0002 <=
            sequences[206].field0000 &&
            ((sequences[field0008].data[field000a].frameFlags & 8) > 0)) &&
            ((field0008 >= 200 && (attackCollisionResult >= 2 && (attackCollisionResult != 6))) ||
            (field0008 < 200)))) {
            ResetPose();
            ClearBufferedButtons();
            field0008 = 0xce;
            return;
        }
        if (((inputY == '\0') || ((field01a8 & 4) == 0)) ||
            ((field01a9 & 4) == 0)) {
            if (((inputX != '\0') &&
                ((*opponentSlot)->positionY == 0.0)) &&
                (((-30.0 < positionX - (*opponentSlot)->positionX &&
                (positionX - (*opponentSlot)->positionX < 30.0
                && (sequences[field0008].field0002 <=
                sequences[220].field0000))) &&
                ((*opponentSlot)->field0008 < 0x32 ||
                (0x9c < (*opponentSlot)->field0008))) &&
                ((sequences[field0008].data[field000a].frameFlags & 8) > 0 &&
                (((field0008 >= 200 && (attackCollisionResult >= 2)) && (attackCollisionResult != 6))
                || (field0008 < 200))))) {
                ResetPose();
                ClearBufferedButtons();
                field0008 = 0xdc;
                return;
            }
            if (((sequences[field0008].field0002 <=
                sequences[203].field0000) &&
                ((sequences[field0008].data[field000a].frameFlags & 8) > 0)) &&
                ((field0008 >= 200 && (attackCollisionResult >= 2 && (attackCollisionResult != 6))) ||
                (field0008 < 200))) {
                ResetPose();
                ClearBufferedButtons();
                field0008 = 0xcb;
                return;
            }
        }
    }
    if ((((field015c < 2) &&
        ((buttonPulse[3] == '\x01' || ((field01a8 & 0x80) != 0)) ||
        ((field01a9 & 0x80) != 0))) &&
        (((sequences[field0008].field0002 <=
        sequences[309].field0000 &&
        ((sequences[field0008].data[field000a].frameFlags & 8) > 0)) && (field314c == 0)) &&
        (positionY == 0.0))) &&
        (((field0008 >= 200 && (attackCollisionResult >= 2)) && (attackCollisionResult != 6)) ||
        (field0008 < 200))) {
        ResetPose();
        ClearBufferedButtons();
        field0008 = 0x135;
    }
    return;
}
