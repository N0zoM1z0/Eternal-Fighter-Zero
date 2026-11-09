// Mishio action selection over current command and animation state.
#include "CharacterViews.h"

void Character15::Slot04()
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
    if ((field0262 == 0x34) && ((((field0118 >= 500.0 && (1 < attackCollisionResult)) || ('\0' < (char)field0120 && (1 <
        attackCollisionResult && (attackCollisionResult != 6)))) && ((sequences[field0008].data[field000a].frameFlags & 8) > 0)) &&
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
        if ((((((health < 0xd05) && (field0262 == 0x62)) && (meter >= 3000)) &&
            ((sequences[field0008].data[field000a].frameFlags & 8) > 0 && (positionY == 0.0))) && (attackCollisionResult !=
            6)) && (sequences[field0008].field0002 <= sequences[318].field0000)) {
            ResetPose();
            ClearBufferedButtons();
            field0008 = 0x13e;
            return;
        }
        if (((((field3158 == 2) || (field3158 == 3)) && (field0262 == 0x7a && ((meter >= 3000 &&
            (positionY == 0.0)) && ((sequences[field0008].data[field000a].frameFlags & 8) > 0)))) &&
            (((field0008 >= 200 && (attackCollisionResult >= 2)) && (attackCollisionResult != 6)) || (field0008 < 200))) &&
            (sequences[field0008].field0002 <= sequences[314].field0000)) {
            ResetPose();
            ClearBufferedButtons();
            field0008 = 0x13a;
            return;
        }
        if (((((field3158 == 2) || (field3158 == 3)) && ((field0262 == 0x7a || (field0262 == 0x79)) &&
            ((meter >= 2000 && (positionY == 0.0)) && ((sequences[field0008].data[field000a].frameFlags &
            8) > 0)))) && (((field0008 >= 200 && (attackCollisionResult >= 2)) && (attackCollisionResult != 6)) || (field0008 < 200)))
            && (sequences[field0008].field0002 <= sequences[313].field0000)) {
            ResetPose();
            ClearBufferedButtons();
            field0008 = 0x139;
            return;
        }
        if ((((field3158 == 2) || (field3158 == 3)) && (field0262 == 0x78 || (field0262 == 0x79 || (field0262
            == 0x7a)) )) && (((meter >= 1000 && (positionY == 0.0 &&
            ((sequences[field0008].data[field000a].frameFlags & 8) > 0))) && ((field0008 >= 200 && (attackCollisionResult
            >= 2 && (attackCollisionResult != 6))) || (field0008 < 200))) && (sequences[field0008].field0002 <=
            sequences[312].field0000))) {
            ResetPose();
            ClearBufferedButtons();
            field0008 = 0x138;
            return;
        }
        if (((((((field3158 == 1) || (field3158 == 3)) && (field0262 == 0x70)) && (meter >= 3000 &&
            (positionY == 0.0))) && ((sequences[field0008].data[field000a].frameFlags & 8) > 0)) &&
            (((field0008 >= 200 && (attackCollisionResult >= 2)) && (attackCollisionResult != 6)) || (field0008 < 200))) &&
            (sequences[field0008].field0002 <= sequences[305].field0000)) {
            ResetPose();
            ClearBufferedButtons();
            field0008 = 0x131;
            return;
        }
        if ((((field3158 == 1) || (field3158 == 3)) && ((field0262 == 0x70 || (field0262 == 0x6f)) &&
            ((meter >= 2000 && (positionY == 0.0)) && ((sequences[field0008].data[field000a].frameFlags &
            8) > 0)))) && ((((field0008 >= 200 && (attackCollisionResult >= 2)) && (attackCollisionResult != 6)) || (field0008 < 200))
            && (sequences[field0008].field0002 <= sequences[304].field0000))) {
            ResetPose();
            ClearBufferedButtons();
            field0008 = 0x130;
            return;
        }
        if (((((field3158 == 1) || (field3158 == 3)) && (field0262 == 0x6e || (field0262 == 0x6f || (field0262
            == 0x70)) )) && (meter >= 1000 && (positionY == 0.0 &&
            ((sequences[field0008].data[field000a].frameFlags & 8) > 0)))) && (((field0008 >= 200 && (attackCollisionResult
            >= 2 && (attackCollisionResult != 6))) || (field0008 < 200)) && (sequences[field0008].field0002 <=
            sequences[303].field0000))) {
            ResetPose();
            ClearBufferedButtons();
            field0008 = 0x12f;
            return;
        }
        if (((((field3158 == 2) || (field3158 == 3)) && (field0262 == 0x66)) && ((meter >= 3000 &&
            (positionY < 0.0)) && ((sequences[field0008].data[field000a].frameFlags & 8) > 0))) &&
            ((((field0008 >= 200 && (attackCollisionResult >= 2)) && (attackCollisionResult != 6)) || (field0008 < 200)) &&
            (sequences[field0008].field0002 <= sequences[302].field0000))) {
            ResetPose();
            ClearBufferedButtons();
            field0008 = 0x13d;
            return;
        }
        if ((((field3158 == 2) || (field3158 == 3)) && ((field0262 == 0x66 || (field0262 == 0x65)) &&
            ((meter >= 2000 && (positionY < 0.0)) && ((sequences[field0008].data[field000a].frameFlags & 8)
            > 0)))) && ((((field0008 >= 200 && (attackCollisionResult >= 2)) && (attackCollisionResult != 6)) || (field0008 < 200)) &&
            (sequences[field0008].field0002 <= sequences[301].field0000))) {
            ResetPose();
            ClearBufferedButtons();
            field0008 = 0x13c;
            return;
        }
        if (((field3158 == 2) || (field3158 == 3)) && (((field0262 == 100 || (field0262 == 0x65 || (field0262
            == 0x66)) ) && (meter >= 1000 && (positionY < 0.0 &&
            ((sequences[field0008].data[field000a].frameFlags & 8) > 0)))) && (((field0008 >= 200 && (attackCollisionResult
            >= 2 && (attackCollisionResult != 6))) || (field0008 < 200)) && (sequences[field0008].field0002 <=
            sequences[300].field0000)))) {
            ResetPose();
            ClearBufferedButtons();
            field0008 = 0x13b;
            return;
        }
        if ((((((field3158 == 1) || (field3158 == 3)) && (field0262 == 0x66)) && (meter >= 3000 &&
            (positionY == 0.0))) && ((sequences[field0008].data[field000a].frameFlags & 8) > 0 && (((field0008
            >= 200 && (attackCollisionResult >= 2)) && (attackCollisionResult != 6)) || (field0008 < 200)))) &&
            (sequences[field0008].field0002 <= sequences[302].field0000)) {
            ResetPose();
            ClearBufferedButtons();
            field0008 = 0x12e;
            return;
        }
        if (((((field3158 == 1) || (field3158 == 3)) && (field0262 == 0x66 || (field0262 == 0x65))) &&
            ((meter >= 2000 && (positionY == 0.0)) && ((sequences[field0008].data[field000a].frameFlags &
            8) > 0))) && ((((field0008 >= 200 && (attackCollisionResult >= 2)) && (attackCollisionResult != 6)) || (field0008 < 200))
            && (sequences[field0008].field0002 <= sequences[301].field0000))) {
            ResetPose();
            ClearBufferedButtons();
            field0008 = 0x12d;
            return;
        }
        if ((((((field3158 == 1) || (field3158 == 3)) && (field0262 == 100 || (field0262 == 0x65 || (field0262
            == 0x66) ))) && (meter >= 1000 && (positionY == 0.0 &&
            ((sequences[field0008].data[field000a].frameFlags & 8) > 0)))) && ((field0008 >= 200 && (attackCollisionResult
            >= 2 && (attackCollisionResult != 6))) || (field0008 < 200))) && (sequences[field0008].field0002 <=
            sequences[300].field0000)) {
            ResetPose();
            ClearBufferedButtons();
            field0008 = 300;
            return;
        }
        if (((((field3158 == 2) || (field3158 == 3)) && (field314c == 0)) && ((field0262 == 0x33 && (positionY
            == 0.0)) && ((sequences[field0008].data[field000a].frameFlags & 8) > 0))) && ((((field0008 >= 200
            && (attackCollisionResult >= 2)) && (attackCollisionResult != 6)) || (field0008 < 200)) && (sequences[field0008].field0002
            <= sequences[272].field0000))) {
            ResetPose();
            ClearBufferedButtons();
            field0008 = 0x110;
            return;
        }
        if ((((((field3158 == 2) || (field3158 == 3)) && (field314c == 0)) && (field0262 == 0x32 && (positionY
            == 0.0) )) && ((sequences[field0008].data[field000a].frameFlags & 8) > 0)) && ((((field0008 >= 200
            && (attackCollisionResult >= 2)) && (attackCollisionResult != 6)) || (field0008 < 200)) && (sequences[field0008].field0002
            <= sequences[271].field0000))) {
            ResetPose();
            ClearBufferedButtons();
            field0008 = 0x10f;
            return;
        }
        if ((((((field3158 == 2) || (field3158 == 3)) && (field3148 == 0)) && ((field0118 >= 500.0 || ('\0' <
            (char)field0120)) && (field0262 == 0x2a && (positionY == 0.0) ))) && ((field0118 >= 500.0 || ('\0'
            < (char)field0120)) || (positionY == 0.0))) && ((sequences[field0008].data[field000a].frameFlags &
            8) > 0 && ((((field0008 >= 200 && (attackCollisionResult >= 2)) && (attackCollisionResult != 6)) || (field0008 < 200)) &&
            (sequences[field0008].field0002 <= sequences[270].field0000)))) {
            ResetPose();
            ClearBufferedButtons();
            field0008 = 0x10e;
            return;
        }
        if (((((field3158 == 2) || (field3158 == 3)) && (field3148 == 0 && (field0262 == 0x29 || (field0262 ==
            0x2a)) )) && (positionY == 0.0)) && (((sequences[field0008].data[field000a].frameFlags & 8) > 0 &&
            (((field0008 >= 200 && (attackCollisionResult >= 2)) && (attackCollisionResult != 6)) || (field0008 < 200))) &&
            (sequences[field0008].field0002 <= sequences[269].field0000))) {
            ResetPose();
            ClearBufferedButtons();
            field0008 = 0x10d;
            return;
        }
        if (((((field3158 == 2) || (field3158 == 3)) && (field3148 == 0 && (field0262 == 0x28 && (positionY ==
            0.0) ))) && ((sequences[field0008].data[field000a].frameFlags & 8) > 0)) && ((((field0008 >= 200 &&
            (attackCollisionResult >= 2)) && (attackCollisionResult != 6)) || (field0008 < 200)) && (sequences[field0008].field0002 <=
            sequences[256].field0000))) {
            ResetPose();
            ClearBufferedButtons();
            field0008 = 0x10c;
            return;
        }
        if (((((field0262 == 0x16) && (field0118 >= 500.0 || ('\0' < (char)field0120))) &&
            ((sequences[field0008].data[field000a].frameFlags & 8) > 0 && (positionY == 0.0))) && (((field0008
            >= 200 && (attackCollisionResult >= 2)) && (attackCollisionResult != 6)) || (field0008 < 200))) &&
            (sequences[field0008].field0002 <= sequences[252].field0000)) {
            ResetPose();
            ClearBufferedButtons();
            if (field3158 == 0) {
                field0008 = 0xfc;
            }
            if (field3158 == 1) {
                field0008 = 0x113;
            }
            if (field3158 == 2) {
                field0008 = 0x116;
            }
            if (field3158 == 3) {
                field0008 = 0x119;
            }
            return;
        }
        if (((((field0262 == 0x15) || (field0262 == 0x16)) && ((sequences[field0008].data[field000a].frameFlags
            & 8) > 0)) && (positionY == 0.0)) && ((((field0008 >= 200 && (attackCollisionResult >= 2)) && (attackCollisionResult !=
            6)) || (field0008 < 200)) && (sequences[field0008].field0002 <= sequences[251].field0000))) {
            ResetPose();
            ClearBufferedButtons();
            if (field3158 == 0) {
                field0008 = 0xfb;
            }
            if (field3158 == 1) {
                field0008 = 0x112;
            }
            if (field3158 == 2) {
                field0008 = 0x115;
            }
            if (field3158 == 3) {
                field0008 = 0x117;
            }
            return;
        }
        if (((field0262 == 0x14) && ((sequences[field0008].data[field000a].frameFlags & 8) > 0)) && ((positionY
            == 0.0 && (((field0008 >= 200 && (attackCollisionResult >= 2)) && (attackCollisionResult != 6)) || (field0008 < 200))) &&
            (sequences[field0008].field0002 <= sequences[250].field0000))) {
            ResetPose();
            ClearBufferedButtons();
            if (field3158 == 0) {
                field0008 = 0xfa;
            }
            if (field3158 == 1) {
                field0008 = 0x111;
            }
            if (field3158 == 2) {
                field0008 = 0x114;
            }
            if (field3158 == 3) {
                field0008 = 0x117;
            }
            return;
        }
        if ((((field3158 == 1) || (field3158 == 3)) && (field0262 == 0x20 &&
            ((sequences[field0008].data[field000a].frameFlags & 8) > 0))) && ((((field0008 >= 200 && (attackCollisionResult
            >= 2)) && (attackCollisionResult != 6)) || (field0008 < 200)) && (sequences[field0008].field0002 <=
            sequences[258].field0000))) {
            ResetPose();
            ClearBufferedButtons();
            field0008 = 0x100;
            if (positionY < 0.0) {
                field0008 = 0x105;
            }
            return;
        }
        if (((((field3158 == 1) || (field3158 == 3)) && (field0262 == 0x1f || (field0262 == 0x20))) &&
            ((sequences[field0008].data[field000a].frameFlags & 8) > 0)) && ((((field0008 >= 200 && (attackCollisionResult
            >= 2)) && (attackCollisionResult != 6)) || (field0008 < 200)) && (sequences[field0008].field0002 <=
            sequences[257].field0000))) {
            ResetPose();
            ClearBufferedButtons();
            field0008 = 0x102;
            if (positionY < 0.0) {
                field0008 = 0x104;
            }
            return;
        }
        if (((((field3158 == 1) || (field3158 == 3)) && (field0262 == 0x1e &&
            ((sequences[field0008].data[field000a].frameFlags & 8) > 0))) && (((field0008 >= 200 && (attackCollisionResult
            >= 2)) && (attackCollisionResult != 6)) || (field0008 < 200))) && (sequences[field0008].field0002 <=
            sequences[257].field0000)) {
            ResetPose();
            ClearBufferedButtons();
            field0008 = 0x101;
            if (positionY < 0.0) {
                field0008 = 0x103;
            }
            return;
        }
        if (((((field3158 == 1) || (field3158 == 3)) && (field0262 == 0xc)) && (field0118 >= 500.0 || ('\0' <
            (char)field0120))) && ((positionY == 0.0 && ((sequences[field0008].data[field000a].frameFlags & 8)
            > 0)) && ((((field0008 >= 200 && (attackCollisionResult >= 2)) && (attackCollisionResult != 6)) || (field0008 < 200)) &&
            (sequences[field0008].field0002 <= sequences[255].field0000)))) {
            ResetPose();
            ClearBufferedButtons();
            field0008 = 0xff;
            return;
        }
        if (((((field3158 == 1) || (field3158 == 3)) && (field0262 == 0xb || (field0262 == 0xc))) &&
            ((positionY == 0.0 && ((sequences[field0008].data[field000a].frameFlags & 8) > 0)) && ((field0008
            >= 200 && (attackCollisionResult >= 2 && (attackCollisionResult != 6))) || (field0008 < 200)))) &&
            (sequences[field0008].field0002 <= sequences[253].field0000)) {
            ResetPose();
            ClearBufferedButtons();
            field0008 = 0xfd;
            return;
        }
        if (((((((field3158 == 1) || (field3158 == 3)) && (field0008 != 0xfe)) && (field0262 == 10 &&
            (positionY == 0.0)) ) && ((sequences[field0008].data[field000a].frameFlags & 8) > 0)) &&
            (((field0008 >= 200 && (attackCollisionResult >= 2)) && (attackCollisionResult != 6)) || (field0008 < 200))) &&
            (sequences[field0008].field0002 <= sequences[254].field0000)) {
            ResetPose();
            ClearBufferedButtons();
            field0008 = 0xfe;
            return;
        }
    }
    if ((field015c < 1) && (field0262 == 0 || (field0262 == 1))) {
        if ((positionY < 0.0) && (airDashCount < 1)) {
            if (((((((*opponentSlot)->positionX - positionX) * (1 - field0262 * 2) < 0.0 ) || (0.0 ==
                (*opponentSlot)->positionX - positionX && ((int)(char)facing == ((1 - field0262 * 2) * -1))))
                && (sequences[field0008].field0002 <= sequences[165].field0000)) && ((field0008 != 0xaa &&
                (positionY < -40.0)) && ((sequences[field0008].data[field000a].frameFlags & 8) > 0))) &&
                (((field0008 >= 200 && (attackCollisionResult >= 2)) && (attackCollisionResult != 6)) || (field0008 < 200))) {
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
            if ((((0.0 < ((*opponentSlot)->positionX - positionX) * (1 - field0262 * 2)) || (0.0 ==
                (*opponentSlot)->positionX - positionX && ((int)(char)facing == 1 - field0262 * 2))) &&
                (sequences[field0008].field0002 <= sequences[166].field0000 && (field0008 != 0xaa &&
                ((sequences[field0008].data[field000a].frameFlags & 8) > 0)))) && ((field0008 >= 200 &&
                (attackCollisionResult >= 2 && (attackCollisionResult != 6))) || (field0008 < 200))) {
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
            if ((((((*opponentSlot)->positionX - positionX) * (1 - field0262 * 2) < 0.0) || (0.0 ==
                (*opponentSlot)->positionX - positionX && ((int)(char)facing == ((1 - field0262 * 2) * -1))))
                && (sequences[field0008].field0002 <= sequences[163].field0000)) && (((field0008 >= 200 &&
                (attackCollisionResult >= 2)) && (attackCollisionResult != 6)) || (field0008 < 200))) {
                if (field0008 != 0xa3) {
                    ResetPose();
                }
                field0008 = 0xa3;
                FaceOpponent();
                ++dashMomentumFlag;
                actionBufferedInput = 0;
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
                actionBufferedInput = 0;
                return;
            }
        }
    }
    if ((((((field015c < 3) && (field0262 == 6)) && ((sequences[field0008].data[field000a].frameFlags & 8) >
        0)) && (positionY < 0.0 && (airActionCount < 1))) && (sequences[field0008].field0002 <=
        sequences[14].field0000)) && (((field0008 >= 200 && (attackCollisionResult >= 2)) && (attackCollisionResult != 6)) ||
        (field0008 < 200))) {
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
        if (((((inputY == '\x01') || ((actionBufferedInput & 4) != 0)) || ((stateGroupCBufferedInput & 4) != 0)) &&
            (sequences[field0008].field0002 <= sequences[204].field0000 &&
            ((sequences[field0008].data[field000a].frameFlags & 8) > 0))) && ((field0008 >= 200 && (attackCollisionResult
            >= 2 && (attackCollisionResult != 6))) || (field0008 < 200))) {
            ResetPose();
            ClearBufferedButtons();
            field0008 = 0xcc;
            return;
        }
        if (((((inputY == '\0') || ((actionBufferedInput & 4) == 0)) || ((stateGroupCBufferedInput & 4) == 0)) &&
            (sequences[field0008].field0002 <= sequences[200].field0000 &&
            ((sequences[field0008].data[field000a].frameFlags & 8) > 0))) && ((field0008 >= 200 && (attackCollisionResult
            >= 2 && (attackCollisionResult != 6))) || (field0008 < 200))) {
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
        if (((((inputY == '\x01') || ((actionBufferedInput & 4) != 0)) || ((stateGroupCBufferedInput & 4) != 0)) &&
            (sequences[field0008].field0002 <= sequences[205].field0000 &&
            ((sequences[field0008].data[field000a].frameFlags & 8) > 0))) && ((field0008 >= 200 && (attackCollisionResult
            >= 2 && (attackCollisionResult != 6))) || (field0008 < 200))) {
            ResetPose();
            ClearBufferedButtons();
            field0008 = 0xcd;
            return;
        }
        if (((inputY == '\0') || ((actionBufferedInput & 4) == 0)) || ((stateGroupCBufferedInput & 4) == 0)) {
            if ((((field3158 == 2) || (field3158 == 3)) && ((char)inputX == (char)facing &&
                (sequences[field0008].field0002 <= sequences[210].field0000 &&
                ((sequences[field0008].data[field000a].frameFlags & 8) > 0)))) && ((field0008 >= 200 &&
                (attackCollisionResult >= 2 && (attackCollisionResult != 6))) || (field0008 < 200))) {
                ResetPose();
                ClearBufferedButtons();
                field0008 = 0xd2;
                return;
            }
            if (((((sequences[field0008].field0002 <= sequences[201].field0000) &&
                ((sequences[field0008].data[field000a].frameFlags & 8) > 0)) && (positionX -
                (*opponentSlot)->positionX > -90.0)) && (positionX - (*opponentSlot)->positionX < 90.0)) &&
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
            if ((field3158 == 1 || field3158 == 3) &&
                sequences[field0008].field0002 <= sequences[211].field0000 &&
                (sequences[field0008].data[field000a].frameFlags & 8) > 0 && inputX == facing &&
                ((field0008 >= 200 && attackCollisionResult >= 2 && attackCollisionResult != 6) || field0008 < 200)) {
                ResetPose();
                ClearBufferedButtons();
                field0008 = 211;
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
