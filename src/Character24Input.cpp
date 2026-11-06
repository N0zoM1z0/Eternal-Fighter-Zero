// Mizuka action selection over current command and animation state.
#include "Character24.h"

void Character24::Slot04()
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
    if (field0028 == 0.0) {
        field3458 = 0;
    }
    if (((field0262 == 0x34) && ((((field0118 >= 500.0 || ('\0' < field0120)) && (1 < (int)field0168)) &&
        ((field0168 != 6 && ((sequences[field0008].data[field000a].field00b0 & 8) > 0)))))) &&
        (sequences[field0008].field0002 <= sequences[167].field0000)) {
        ResetPose();
        ClearBufferedButtons();
        field0008 = 0xa7;
        if (field0028 < 0.0) field0008 = 0xab;
        return;
    }
    if ((int)field015c < 2) {
        if (((((field0262 == 0x84) && (field0148 >= 3000)) && (((sequences[field0008].data[field000a].field00b0 & 8)
            > 0 && (field0028 == 0.0)))) && ((((field0008 >= 200 && (field0168 >= 2)) && (field0168 != 6)) ||
            (field0008 < 200)))) && (sequences[field0008].field0002 <= sequences[316].field0000)) {
            ResetPose();
            ClearBufferedButtons();
            field0008 = 0x13c;
            return;
        }
        if ((((field0262 == 0x70) && (field0148 >= 3000)) && (((sequences[field0008].data[field000a].field00b0 & 8)
            > 0 && (field0028 == 0.0)))) && (((((field0008 >= 200 && (field0168 >= 2)) && (field0168 != 6)) ||
            (field0008 < 200)) && (sequences[field0008].field0002 <= sequences[314].field0000)))) {
            ResetPose();
            ClearBufferedButtons();
            field0008 = 0x13a;
            return;
        }
        if (((((field0262 == 0x66) && (field0148 >= 3000)) && (field0028 == 0.0)) &&
            ((sequences[field0008].data[field000a].field00b0 & 8) > 0)) && (((((field0008 >= 200 && (field0168 >=
            2)) && (field0168 != 6)) || (field0008 < 200)) && (sequences[field0008].field0002 <=
            sequences[300].field0000)))) {
            ResetPose();
            ClearBufferedButtons();
            field0008 = 0x12e;
            return;
        }
        if ((((field0262 == 0x65) || (field0262 == 0x66)) && ((field0148 >= 2000 && ((field0028 == 0.0 &&
            ((sequences[field0008].data[field000a].field00b0 & 8) > 0)))))) && ((((field0008 >= 200 && ((field0168
            >= 2 && (field0168 != 6)))) || (field0008 < 200)) && (sequences[field0008].field0002 <=
            sequences[301].field0000)))) {
            ResetPose();
            ClearBufferedButtons();
            field0008 = 0x12d;
            return;
        }
        if ((((((field0262 == 100) || (field0262 == 0x65)) || (field0262 == 0x66)) && ((field0148 >= 1000 &&
            (field0028 == 0.0)))) && (((sequences[field0008].data[field000a].field00b0 & 8) > 0 && ((((field0008 >=
            200 && (field0168 >= 2)) && (field0168 != 6)) || (field0008 < 200)))))) &&
            (sequences[field0008].field0002 <= sequences[300].field0000)) {
            ResetPose();
            ClearBufferedButtons();
            field0008 = 300;
            return;
        }
        if (((((field0262 == 0x7a) && (field0148 >= 3000)) && (field0028 == 0.0)) &&
            ((sequences[field0008].data[field000a].field00b0 & 8) > 0)) && (((((field0008 >= 200 && (field0168 >=
            2)) && (field0168 != 6)) || (field0008 < 200)) && (sequences[field0008].field0002 <=
            sequences[305].field0000)))) {
            ResetPose();
            ClearBufferedButtons();
            field0008 = 0x131;
            return;
        }
        if (((((field0262 == 0x79) || (field0262 == 0x7a)) && ((field0148 >= 2000 && ((field0028 == 0.0 &&
            ((sequences[field0008].data[field000a].field00b0 & 8) > 0)))))) && (((field0008 >= 200 && ((field0168 >=
            2 && (field0168 != 6)))) || (field0008 < 200)))) && (sequences[field0008].field0002 <=
            sequences[304].field0000)) {
            ResetPose();
            ClearBufferedButtons();
            field0008 = 0x130;
            return;
        }
        if ((((((field0262 == 0x78) || (field0262 == 0x79) ) || (field0262 == 0x7a)) && (((field0148 >= 1000 &&
            (field0028 == 0.0)) && ((sequences[field0008].data[field000a].field00b0 & 8) > 0)))) && ((((field0008 >=
            200 && (field0168 >= 2)) && (field0168 != 6)) || (field0008 < 200)))) && (sequences[field0008].field0002
            <= sequences[303].field0000)) {
            ResetPose();
            ClearBufferedButtons();
            field0008 = 0x12f;
            return;
        }
        if (((field0262 == 0x16) && ((((field0118 >= 500.0 || ('\0' < field0120)) &&
            ((sequences[field0008].data[field000a].field00b0 & 8) > 0)) && (field0028 == 0.0)))) && (((((field0008
            >= 200 && (field0168 >= 2)) && (field0168 != 6)) || (field0008 < 200)) &&
            (sequences[field0008].field0002 <= sequences[261].field0000)))) {
            ResetPose();
            ClearBufferedButtons();
            field0008 = 0x105;
            return;
        }
        if ((((field0262 == 0x14) || (field0262 == 0x15)) || (field0262 == 0x16)) &&
            ((((sequences[field0008].data[field000a].field00b0 & 8) > 0 && (field0028 == 0.0)) && ((((field0008 >=
            200 && ((field0168 >= 2 && (field0168 != 6)))) || (field0008 < 200)) && (sequences[field0008].field0002
            <= sequences[259].field0000)))))) {
            ResetPose();
            ClearBufferedButtons();
            field0008 = 0x103;
            return;
        }
        if (((((field0262 == 0x20) || (field0262 == 0x1f)) || (field0262 == 0x1e)) &&
            (((sequences[field0008].data[field000a].field00b0 & 8) > 0 && (field0028 < 0.0)))) && ((((field0008 >=
            200 && ((field0168 >= 2 && (field0168 != 6)))) || (field0008 < 200)) && (sequences[field0008].field0002
            <= sequences[265].field0000)))) {
            ResetPose();
            ClearBufferedButtons();
            field0008 = 0x109;
            return;
        }
        if (((field0262 == 0x20) && (((field0118 >= 500.0 || ('\0' < field0120)) &&
            ((sequences[field0008].data[field000a].field00b0 & 8) > 0)))) && (((field0028 == 0.0 && ((((field0008 >=
            200 && (field0168 >= 2)) && (field0168 != 6)) || (field0008 < 200)))) && (sequences[field0008].field0002
            <= sequences[255].field0000)))) {
            ResetPose();
            ClearBufferedButtons();
            field0008 = 0xff;
            return;
        }
        if (((field0262 == 0x1f) || (field0262 == 0x20)) && ((((sequences[field0008].data[field000a].field00b0 & 8)
            > 0 && (field0028 == 0.0)) && (((((field0008 >= 200 && (field0168 >= 2)) && (field0168 != 6)) ||
            (field0008 < 200)) && (sequences[field0008].field0002 <= sequences[254].field0000)))))) {
            ResetPose();
            ClearBufferedButtons();
            field0008 = 0xfe;
            return;
        }
        if ((((field0262 == 0x1e) && ((sequences[field0008].data[field000a].field00b0 & 8) > 0)) && ((field0028 ==
            0.0 && ((((field0008 >= 200 && (field0168 >= 2)) && (field0168 != 6)) || (field0008 < 200)))))) &&
            (sequences[field0008].field0002 <= sequences[253].field0000)) {
            ResetPose();
            ClearBufferedButtons();
            field0008 = 0xfd;
            return;
        }
        if ((((field0262 == 0x48) && ((sequences[field0008].data[field000a].field00b0 & 8) > 0)) && (field0028 ==
            0.0)) && (((((field0008 >= 200 && (field0168 >= 2)) && (field0168 != 6)) || (field0008 < 200)) &&
            (sequences[field0008].field0002 <= sequences[258].field0000)))) {
            ResetPose();
            ClearBufferedButtons();
            field0008 = 0x102;
            return;
        }
        if (((field0262 == 0x47) && ((sequences[field0008].data[field000a].field00b0 & 8) > 0)) && ((field0028 ==
            0.0 && (((((field0008 >= 200 && (field0168 >= 2)) && (field0168 != 6)) || (field0008 < 200)) &&
            (sequences[field0008].field0002 <= sequences[257].field0000)))))) {
            ResetPose();
            ClearBufferedButtons();
            field0008 = 0x101;
            return;
        }
        if (((((field0262 == 0x46) && ((sequences[field0008].data[field000a].field00b0 & 8) > 0)) && (field0028 ==
            0.0)) && ((((field0008 >= 200 && (field0168 >= 2)) && (field0168 != 6)) || (field0008 < 200)))) &&
            (sequences[field0008].field0002 <= sequences[256].field0000)) {
            ResetPose();
            ClearBufferedButtons();
            field0008 = 0x100;
            return;
        }
        if ((((field0262 == 0xc) && (((field0118 >= 500.0 || ('\0' < field0120)) &&
            ((sequences[field0008].data[field000a].field00b0 & 8) > 0)))) && ((((field0008 >= 200 && (field0168 >=
            2)) && (field0168 != 6)) || (field0008 < 200)))) && (sequences[field0008].field0002 <=
            sequences[252].field0000)) {
            ResetPose();
            ClearBufferedButtons();
            field0008 = 0xfc;
            if (field0028 < 0.0) field0008 = 0x108;
        return;
        }
        if ((((field0262 == 0xb) || (field0262 == 0xc)) && (((sequences[field0008].data[field000a].field00b0 & 8) >
            0 && ((((field0008 >= 200 && (field0168 >= 2)) && (field0168 != 6)) || (field0008 < 200)))))) &&
            (sequences[field0008].field0002 <= sequences[251].field0000)) {
            ResetPose();
            ClearBufferedButtons();
            field0008 = 0xfb;
            if (field0028 < 0.0) field0008 = 0x107;
        return;
        }
        if (((field0262 == 10) && ((sequences[field0008].data[field000a].field00b0 & 8) > 0)) && ((((field0008 >=
            200 && ((field0168 >= 2 && (field0168 != 6)))) || (field0008 < 200)) && (sequences[field0008].field0002
            <= sequences[250].field0000)))) {
            ResetPose();
            ClearBufferedButtons();
            field0008 = 0xfa;
            if (field0028 < 0.0) field0008 = 0x106;
        return;
        }
    }
    if (((int)field015c < 1) && ((field0262 == 0 || (field0262 == 1)))) {
        if ((field0028 < 0.0) && (field0159 < 1)) {
            if (((((((*opponentSlot)->field0020 - field0020) * (1 - field0262 * 2) < 0.0 ) ||
                (((*opponentSlot)->field0020 - field0020 == 0.0 && ((int)facing == ((1 - field0262 * 2) * -1))) ))
                && (sequences[field0008].field0002 <= sequences[165].field0000)) && ((field0008 != 0xaa &&
                (((field0028 < -40.0 || (0 < (int)field3458)) && ((sequences[field0008].data[field000a].field00b0 &
                8) > 0)))))) && ((((field0008 >= 200 && (field0168 >= 2)) && (field0168 != 6)) || (field0008 <
                200)))) {
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
            if ((((((*opponentSlot)->field0020 - field0020) * (1 - field0262 * 2) > 0.0) ||
                (((*opponentSlot)->field0020 - field0020 == 0.0 && ((int)facing == 1 - field0262 * 2)))) &&
                ((sequences[field0008].field0002 <= sequences[166].field0000 && ((field0008 != 0xaa &&
                ((sequences[field0008].data[field000a].field00b0 & 8) > 0)))))) && (((field0008 >= 200 &&
                ((field0168 >= 2 && (field0168 != 6)))) || (field0008 < 200)))) {
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
        if ((field0028 == 0.0) && ((sequences[field0008].data[field000a].field00b0 & 8) > 0)) {
            if (((((*opponentSlot)->field0020 - field0020) * (1 - field0262 * 2) < 0.0) ||
                (((*opponentSlot)->field0020 - field0020 == 0.0 && ((int)facing == ((1 - field0262 * 2) * -1))))) &&
                ((sequences[field0008].field0002 <= sequences[163].field0000 && ((((field0008 >= 200 && (field0168
                >= 2)) && (field0168 != 6) ) || (field0008 < 200)))))) {
                if (field0008 != 0xa3) {
                    ResetPose();
                }
                field0008 = 0xa3;
                FaceOpponent();
                ++field0158;
                field01a8 = 0;
                return;
            }
            if ((((((*opponentSlot)->field0020 - field0020) * (1 - field0262 * 2) > 0.0) ||
                (((*opponentSlot)->field0020 - field0020 == 0.0 && ((int)facing == 1 - field0262 * 2)))) &&
                (sequences[field0008].field0002 <= sequences[164].field0000)) && ((((field0008 >= 200 && (field0168
                >= 2)) && (field0168 != 6)) || (field0008 < 200)))) {
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
    if ((((((int)field015c < 3) && (field0262 == 6)) && ((sequences[field0008].data[field000a].field00b0 & 8) > 0))
        && ((field0028 < 0.0 && (field015a < 1)))) && ((((field0008 >= 200 && ((field0168 >= 2 && (field0168 !=
        6)))) || (field0008 < 200)) && (sequences[field0008].field0002 <= sequences[14].field0000)))) {
        ResetPose();
        ClearBufferedButtons();
        ++field015a;
        field0008 = 0xe;
        if (inputX == facing) {
            field0008 = 0xf;
        }
        if ((int)inputX == -(int)facing) field0008 = 0x10;
        return;
    }
    if (((buttonPulse[0] == '\x01') || ((field01a8 & 0x10) != 0)) || ((field01a9 & 0x10) != 0)) {
        if ((field0008 == 0xa3) && ((int)inputX != -(int)facing)) {
            ResetPose();
            ClearBufferedButtons();
            field0008 = 0xe6;
            return;
        }
        if (field0028 < 0.0) {
            if (sequences[field0008].field0002 <= sequences[207].field0000 &&
                (sequences[field0008].data[field000a].field00b0 & 8) > 0 &&
                ((field0008 >= 200 && field0168 >= 2 && field0168 != 6) || field0008 < 200)) {
                ResetPose();
                ClearBufferedButtons();
                field0008 = 0xcf;
            }
            return;
        }
        if (((((inputY == '\x01') || ((field01a8 & 4) != 0)) || ((field01a9 & 4) != 0)) &&
            ((sequences[field0008].field0002 <= sequences[204].field0000 &&
            ((sequences[field0008].data[field000a].field00b0 & 8) > 0)))) && (((field0008 >= 200 && ((field0168 >= 2
            && (field0168 != 6)))) || (field0008 < 200)))) {
            ResetPose();
            ClearBufferedButtons();
            field0008 = 0xcc;
            return;
        }
        if (((((inputY == '\0') || ((field01a8 & 4) == 0)) || ((field01a9 & 4) == 0)) &&
            ((sequences[field0008].field0002 <= sequences[200].field0000 &&
            ((sequences[field0008].data[field000a].field00b0 & 8) > 0)))) && (((field0008 >= 200 && ((field0168 >= 2
            && (field0168 != 6)))) || (field0008 < 200)))) {
            ResetPose();
            ClearBufferedButtons();
            field0008 = 200;
            return;
        }
    }
    if (((buttonPulse[1] == '\x01') || ((field01a8 & 0x20) != 0)) || ((field01a9 & 0x20) != 0)) {
        if ((field0008 == 0xa3) && ((int)inputX != -(int)facing)) {
            ResetPose();
            ClearBufferedButtons();
            field0008 = 0xe7;
            return;
        }
        if (field0028 < 0.0) {
            if (sequences[field0008].field0002 <= sequences[208].field0000 &&
                (sequences[field0008].data[field000a].field00b0 & 8) > 0 &&
                ((field0008 >= 200 && field0168 >= 2 && field0168 != 6) || field0008 < 200)) {
                ResetPose();
                ClearBufferedButtons();
                field0008 = 0xd0;
            }
            return;
        }
        if (((((inputY == '\x01') || ((field01a8 & 4) != 0)) || ((field01a9 & 4) != 0)) &&
            ((sequences[field0008].field0002 <= sequences[205].field0000 &&
            ((sequences[field0008].data[field000a].field00b0 & 8) > 0)))) && (((field0008 >= 200 && ((field0168 >= 2
            && (field0168 != 6)))) || (field0008 < 200)))) {
            ResetPose();
            ClearBufferedButtons();
            field0008 = 0xcd;
            return;
        }
        if (((inputY == '\0') || ((field01a8 & 4) == 0)) || ((field01a9 & 4) == 0)) {
            if ((((sequences[field0008].field0002 <= sequences[201].field0000) &&
                ((sequences[field0008].data[field000a].field00b0 & 8) > 0)) && ((field0020 -
                (*opponentSlot)->field0020 > -70.0 && (field0020 - (*opponentSlot)->field0020 < 70.0)))) &&
                ((((field0008 >= 200 && (field0168 >= 2)) && (field0168 != 6)) || (field0008 < 200)))) {
                ResetPose();
                ClearBufferedButtons();
                field0008 = 0xc9;
                return;
            }
            if (((sequences[field0008].field0002 <= sequences[202].field0000) &&
                ((sequences[field0008].data[field000a].field00b0 & 8) > 0)) && (((field0008 >= 200 && ((field0168 >=
                2 && (field0168 != 6)))) || (field0008 < 200)))) {
                ResetPose();
                ClearBufferedButtons();
                field0008 = 0xca;
                return;
            }
        }
    }
    if (((buttonPulse[2] == '\x01') || ((field01a8 & 0x40) != 0)) || ((field01a9 & 0x40) != 0)) {
        if ((field0008 == 0xa3) && ((int)inputX != -(int)facing)) {
            ResetPose();
            ClearBufferedButtons();
            field0008 = 0xe8;
            return;
        }
        if (field0028 < 0.0) {
            if ((((sequences[field0008].field0002 <= sequences[210].field0000) && (inputX == facing)) && ((inputY ==
                '\0' && ((sequences[field0008].data[field000a].field00b0 & 8) > 0)))) && ((((field0008 >= 200 &&
                (field0168 >= 2)) && (field0168 != 6)) || (field0008 < 200)))) {
                ResetPose();
                ClearBufferedButtons();
                field0008 = 0xd2;
                return;
            }
            if (sequences[field0008].field0002 <= sequences[209].field0000 &&
                (sequences[field0008].data[field000a].field00b0 & 8) > 0 &&
                ((field0008 >= 200 && field0168 >= 2 && field0168 != 6) || field0008 < 200)) {
                ResetPose();
                ClearBufferedButtons();
                field0008 = 0xd1;
            }
            return;
        }
        if ((((inputY == '\x01') || ((field01a8 & 4) != 0)) || ((field01a9 & 4) != 0)) &&
            (((sequences[field0008].field0002 <= sequences[206].field0000 &&
            ((sequences[field0008].data[field000a].field00b0 & 8) > 0)) && (((field0008 >= 200 && ((field0168 >= 2
            && (field0168 != 6)))) || (field0008 < 200)))))) {
            ResetPose();
            ClearBufferedButtons();
            field0008 = 0xce;
            return;
        }
        if (((inputY == '\0') || ((field01a8 & 4) == 0)) || ((field01a9 & 4) == 0)) {
            if ((((inputX != '\0') && (field0020 - (*opponentSlot)->field0020 > -40.0)) && ((field0020 -
                (*opponentSlot)->field0020 < 40.0 && (sequences[field0008].field0002 <= sequences[220].field0000))))
                && (((((*opponentSlot)->field0008 < 0x32 || ((*opponentSlot)->field0008 > 0x9c)) &&
                ((sequences[field0008].data[field000a].field00b0 & 8) > 0)) && ((((field0008 >= 200 && (field0168 >=
                2)) && (field0168 != 6)) || (field0008 < 200)))))) {
                ResetPose();
                ClearBufferedButtons();
                field0008 = 0xdc;
                return;
            }
            if (((sequences[field0008].field0002 <= sequences[203].field0000) &&
                ((sequences[field0008].data[field000a].field00b0 & 8) > 0)) && (((field0008 >= 200 && ((field0168 >=
                2 && (field0168 != 6)))) || (field0008 < 200)))) {
                ResetPose();
                ClearBufferedButtons();
                field0008 = 0xcb;
                return;
            }
        }
    }
    if (((((int)field015c < 2) && ((((buttonPulse[3] == '\x01' || ((field01a8 & 0x80) != 0)) || ((field01a9 & 0x80)
        != 0)) && ((sequences[field0008].field0002 <= sequences[179].field0000 &&
        ((sequences[field0008].data[field000a].field00b0 & 8) > 0)))))) && (((field0008 >= 200 && ((field0168 >= 2
        && (field0168 != 6)))) || (field0008 < 200)))) && (field3458 <= 0)) {
        ResetPose();
        ClearBufferedButtons();
        field0008 = 0xb3;
    }
    return;
}
