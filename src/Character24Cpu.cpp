// Mizuka CPU input generation and command selection.
#include "Character24.h"
#include <math.h>

void Character24::Slot05()
{
    // Both distances are used throughout the original decision owner.
    struct { double forward, vertical; } distance;
    field0262 = 99;
    if (0 < field01a0) {
        --field01a0;
    }
    if (0 < field01a4) {
        --field01a4;
    }
    inputX = 0;
    inputY = 0;
    buttonPulse[0] = 0;
    buttonPulse[1] = 0;
    buttonPulse[2] = 0;
    buttonPulse[3] = 0;
    field014e = 0;
    if ((float)(unsigned short)RandomRange(0, 1000) <
        25.0f * field00a8 +
        (positionY < 0.0 ? 1 : 0) * 30 * field00a8 +
        (float)((field3114 == 3) * 400) +
        (float)((field0008 == 0xaa ? 1 : 0) * 300)) {
        field014e = 0x3c;
    }
    if ((double)(unsigned short)RandomRange(0, 2000) <
        ((double)(field0130 > 0) * 4.0 + 1.0) * 8.0 * field00a8 *
        ((field0008 > 149 && field0008 < 157 ? 1 : 0) * 2 + 1)) {
        field014e = 0x3c;
    }
    if (((float)(unsigned short)RandomRange(0, 1000) < 40.0f * field00a8) &&
        (199 < field0008)) {
        field014e = 0x3c;
    }
    if ((field0170 == 1) && (field3114 == 2)) {
        field014e = 0x1e;
        if (field0008 < 200) {
            field3114 = 0;
        }
        return;
    }
    if ((*opponentSlot)->field0008 == 0x60) {
        return;
    }
    distance.forward = ((*opponentSlot)->positionX - positionX) * facing;
    distance.vertical = fabs(positionY - (*opponentSlot)->positionY);
    if (!( ((field0008 < 0x32) || (0x96 < field0008)) ||
        ((unsigned short)field000c != 0) )) {
        if ((float)(unsigned short)RandomRange(0, 100) < 8.0f * field00a8) {
            field3114 = 3;
        }
        else {
            field3114 = 0;
        }
        inputX = 1 - ((unsigned short)RandomRange(0, 100) < 50) * 2;
        buttonPulse[3] = (double)(unsigned short)RandomRange(0, 0xf0) < distance.vertical;
        buttonPulse[3] = (double)(unsigned short)RandomRange(0, 0x140) < distance.forward;
        if ((((199 < (*opponentSlot)->field0008) &&
            ((*opponentSlot)->field0008 < 0xfa)) &&
            ((*opponentSlot)->field000a < 3)) &&
            ((distance.vertical < 100.0 && (distance.forward < 150.0)))) {
            buttonPulse[3] = 0;
        }
        return;
    }
    if (((field0008 >= 4 && field0008 <= 6) ||
        (field0008 >= 10 && field0008 <= 12)) && positionY == 0.0) {
        return;
    }
    if ((*opponentSlot)->field0008 >= 50 && (*opponentSlot)->field0008 < 150 &&
        field0008 == 264 && field016c > 1) {
        return;
    }
    if ((field0008 == 0xa8) && ((unsigned short)field000c < 6)) {
        if (((*opponentSlot)->field0008 != 200) &&
            (((((*opponentSlot)->field0008 != 0xcc &&
            ((*opponentSlot)->field0008 < 0xfa)) &&
            ((*opponentSlot)->positionY == 0.0)) &&
            ((*opponentSlot)->field016c == 0)))) {
            if ((distance.forward < 40.0) &&
                (
                (float)(unsigned short)RandomRange(0, 100) < field00a8 * 3.0f)) {
                buttonPulse[0] = 1;
                inputY = 1;
                return;
            }
            if ((distance.forward < 60.0) &&
                (
                (float)(unsigned short)RandomRange(0, 100) < field00a8 * 2)) {
                buttonPulse[0] = 1;
                inputY = 0;
                return;
            }
        }
        if (((((*opponentSlot)->field0008 == 0xc9) ||
            ((*opponentSlot)->field0008 == 0xca)) ||
            ((*opponentSlot)->field0008 == 0xcd)) &&
            ((((*opponentSlot)->field0008 < 0xfa &&
            ((*opponentSlot)->positionY == 0.0)) &&
            ((*opponentSlot)->field016c == 0)))) {
            if (((distance.forward > 20.0) && (distance.forward < 60.0)) &&
                (
                (float)(unsigned short)RandomRange(0, 100) < field00a8 * 2)) {
                buttonPulse[1] = 1;
                inputY = 1;
                inputX = 0;
                return;
            }
            if (((distance.forward > 60.0) && (distance.forward < 80.0)) &&
                (
                (float)(unsigned short)RandomRange(0, 100) < field00a8 * 2)) {
                buttonPulse[0] = 3;
                inputY = 1;
                return;
            }
        }
    }
    if ((field0008 == 0xa8) || (field0008 == 0xa9)) {
        if (distance.forward < 100.0) {
            if ((float)(unsigned short)RandomRange(0, 100) < field00a8 * 3.0f) {
                field0262 = 0x14;
                return;
            }
            if (((float)(unsigned short)RandomRange(0, 100) < field00a8 * 1.0f) &&
                (field0118 > 500.0)) {
                field0262 = 0x16;
                return;
            }
            if (((float)(unsigned short)RandomRange(0, 100) < field00a8 * 1.0f) &&
                (field0118 > 500.0)) {
                field0262 = 0xc;
                return;
            }
            if ((((float)(unsigned short)RandomRange(0, 100) < field00a8 * 2) &&
                (distance.forward < 80.0)) && (meter >= 3000)) {
                field0262 = 0x70;
                return;
            }
            if ((((float)(unsigned short)RandomRange(0, 100) < field00a8 * 1.0f) &&
                (distance.forward < 150.0)) && (meter == 3000)) {
                field0262 = 0x84;
                return;
            }
        }
        if (distance.forward < 320.0) {
            if (((float)(unsigned short)RandomRange(0, 100) < field00a8 * 3.0f) &&
                (field0118 > 500.0)) {
                field0262 = 0x20;
                return;
            }
            if (((float)(unsigned short)RandomRange(0, 100) < field00a8 * 1.0f) &&
                (meter == 3000)) {
                field0262 = 0x84;
                return;
            }
        }
    }
    if (((field0008 == 0xaa) && (field000a == 1)) &&
        ((unsigned short)field000c == 0)) {
        if ((float)(unsigned short)RandomRange(0, 100) < field00a8 * 5.0f) {
            field3114 = 3;
            return;
        }
        if (((positionY - (*opponentSlot)->positionY <
            0.0) &&
            (-40.0 <
            positionY - (*opponentSlot)->positionY)) &&
            ((distance.forward < 80.0 &&
            (
            (float)(unsigned short)RandomRange(0, 100) < field00a8 * 5.0f)))) {
            buttonPulse[0] = 1;
            return;
        }
        if (((-100.0 <
            positionY - (*opponentSlot)->positionY) &&
            (positionY - (*opponentSlot)->positionY <
            -50.0)) &&
            ((distance.forward < 100.0 &&
            (
            (float)(unsigned short)RandomRange(0, 100) < field00a8 * 5.0f)))) {
            buttonPulse[1] = 1;
            return;
        }
        if ((((-100.0 <
            positionY - (*opponentSlot)->positionY) &&
            (positionY - (*opponentSlot)->positionY <
            -50.0)) && (distance.forward < 120.0)) &&
            ( (float)(unsigned short)RandomRange(0, 100) < field00a8 * 5.0f
            )) {
            buttonPulse[2] = 1;
            inputY = 0;
            inputX = facing;
            return;
        }
        if ((float)(unsigned short)RandomRange(0, 100) < field00a8 * 2) {
            field0262 = 0xc;
            return;
        }
    }
    if ((((((*opponentSlot)->field0008 == 0xa8) ||
        ((*opponentSlot)->field0008 == 0xa9)) ||
        ((*opponentSlot)->field0008 == 0xaa)) &&
        ((positionY == 0.0 &&
        ( (float)(unsigned short)RandomRange(0, 100) < 15.0f * field00a8
        )))) && ((field3114 != 2 &&
        ((*opponentSlot)->hitstunFrames == 0)))) {
        field3110 = (unsigned short)RandomRange(0, 100);
        if ((field3110 < 3) && (field0118 > 500.0)) {
            field0262 = 0x14;
            return;
        }
        if ((field3110 < 4) && (field0118 > 500.0)) {
            field0262 = 0xc;
            return;
        }
        if (((field3110 < 0x11) && (0xc < field3110)) &&
            (meter >= 3000)) {
            field0262 = 0x70;
            return;
        }
        if (((field3110 < 0x1e) && (0x11 < field3110)) &&
            (meter >= 3000)) {
            field0262 = 0x84;
            return;
        }
        if (0x32 < field3110) {
            field3114 = 2;
            return;
        }
    }
    if (((((*opponentSlot)->field0008 == 0xa8) ||
        ((*opponentSlot)->field0008 == 0xa9)) ||
        ((*opponentSlot)->field0008 == 0xaa)) &&
        ((((positionY < 0.0 &&
        (
        (float)(unsigned short)RandomRange(0, 100) < 15.0f * field00a8)) &&
        (field3114 != 2)) &&
        ((*opponentSlot)->hitstunFrames == 0)))) {
        field3110 = (unsigned short)RandomRange(0, 100);
        if ((field3110 < 3) && (field0118 > 500.0)) {
            field0262 = 0x16;
            return;
        }
        if (((field3110 < 0x11) && (0xc < field3110)) &&
            (meter >= 1000)) {
            field0262 = (unsigned short)RandomRange(0, 3) + 0x78;
            return;
        }
        if (0x55 < field3110) {
            field3114 = 2;
            return;
        }
    }
    if ((field0118 > 500.0 || field0120 > 0) &&
        (float)(unsigned short)RandomRange(0, 100) < 8.0f * field00a8 &&
        (*opponentSlot)->field0008 > 149 && (*opponentSlot)->field0008 < 157 &&
        (field0008 == 259 || field0008 == 260 || field0008 == 261 || field0008 == 314)) {
        field0262 = 52;
        return;
    }
    // Active special-state timer owns its independent decision path.
    if (field3458 > 0) {
        field3110 = (unsigned short)RandomRange(0, 1000);
        if ((*opponentSlot)->positionY == 0.0) {
            if (((distance.forward < 110.0) && (distance.vertical < 60.0)) &&
                (field3110 < 0x32)) {
                buttonPulse[0] = 1;
                return;
            }
            if (((distance.forward > 50.0) && (distance.forward < 100.0)) &&
                ((distance.vertical < 80.0 &&
                ((0x32 < field3110 && (field3110 < 0x78)))))) {
                buttonPulse[1] = 1;
                return;
            }
            if ((((distance.forward < 70.0) && (distance.vertical > 60.0)) && (distance.vertical < 90.0))
                && ((0x78 < field3110 && (field3110 < 0xaa)))) {
                buttonPulse[2] = 1;
                return;
            }
            if ((((double)(unsigned short)RandomRange(0, 0x140) < distance.forward - 100.0) && (0xaa < field3110))
                && (field3110 < 0xdc)) {
                field0262 = (unsigned short)RandomRange(0, 3) + 10;
                return;
            }
            if ((((distance.forward > 100.0) && (0xf0 < field3110)) &&
                (field3110 < 0x14a)) && (distance.vertical < 40.0)) {
                field0262 = (unsigned short)RandomRange(0, 3) + 0x1e;
                return;
            }
        }
        if ((*opponentSlot)->positionY < 0.0) {
            if (((distance.forward < 110.0) && (distance.vertical < 100.0)) &&
                (field3110 < 0x32)) {
                buttonPulse[0] = 1;
                return;
            }
            if (((distance.forward > 50.0) && (distance.forward < 100.0)) &&
                ((distance.vertical < 100.0 &&
                ((0x32 < field3110 && (field3110 < 0x78)))))) {
                buttonPulse[1] = 1;
                return;
            }
            if ((((distance.forward < 90.0) && (distance.vertical > 100.0)) && (distance.vertical < 180.0))
                && ((0x78 < field3110 && (field3110 < 0xaa)))) {
                buttonPulse[2] = 1;
                return;
            }
            if ((((double)(unsigned short)RandomRange(0, 0x140) < distance.forward - 100.0) && (0xaa < field3110))
                && (field3110 < 0xdc)) {
                field0262 = (unsigned short)RandomRange(0, 3) + 10;
                return;
            }
            if ((((distance.forward > 100.0) && (0xf0 < field3110)) &&
                (field3110 < 0x14a)) && (distance.vertical < 60.0)) {
                field0262 = (unsigned short)RandomRange(0, 3) + 0x1e;
                return;
            }
        }
        if (field0008 < 50 &&
            (((*opponentSlot)->field0008 > 149 && (*opponentSlot)->field0008 < 156) ||
            ((*opponentSlot)->field0008 > 49 && (*opponentSlot)->field0008 < 59)) &&
            positionY == 0.0 &&
            (float)(unsigned short)RandomRange(0, 100) < 3.0f * field00a8) {
            field0262 = (unsigned short)(facing == 1);
            return;
        }
        if (field0008 < 50 && (*opponentSlot)->field0008 < 50 &&
            distance.forward > 60.0 && distance.forward < 140.0 &&
            (float)(unsigned short)RandomRange(0, 100) < 2.0f * field00a8 &&
            positionX > 120.0 && positionX < 520.0) {
            field0262 = (unsigned short)(facing != 1);
            return;
        }
        if ((unsigned short)RandomRange(0, 1000) < 1) {
            field3114 = 4;
            return;
        }
        inputY = 1;
        if ((unsigned short)RandomRange(0, 100) < 0x32) {
            inputY = 0xff;
        }
        if (distance.vertical > 200.0) {
            inputY = 1;
        }
        if (field01a0 > 0) {
            if ((CollisionSide() != '\0') && (0xf < field01a0)) {
                field01a0 = 0xf;
            }
            inputX = 1;
            return;
        }
        if (field01a4 > 0) {
            if ((CollisionSide() != '\0') && (0xf < field01a4)) {
                field01a4 = 0xf;
            }
            inputX = 0xff;
            return;
        }
        if (((unsigned short)RandomRange(0, 100) < 0x32) && (distance.forward < 120.0)) {
            if (facing == '\x01') {
                field01a4 = ((unsigned short)RandomRange(0, 200)) + 0x2d;
            }
            else {
                field01a0 = ((unsigned short)RandomRange(0, 200)) + 0x2d;
            }
        }
        if ((unsigned short)RandomRange(0, 100) < 0x32) {
            if (facing == '\x01') {
                field01a0 = ((unsigned short)RandomRange(0, 200)) + 0x2d;
            }
            else {
                field01a4 = ((unsigned short)RandomRange(0, 200)) + 0x2d;
            }
        }
        else if (facing == -1) {
            field01a0 = ((unsigned short)RandomRange(0, 200)) + 0x2d;
        }
        else {
            field01a4 = ((unsigned short)RandomRange(0, 200)) + 0x2d;
        }
        return;
    }
    if (((field3114 == 0) &&
        ( (float)(unsigned short)RandomRange(0, 100) < field00a8)) &&
        (((0x95 < field0008 && (field0008 < 0x9d)) ||
        (field0008 == 0x60)))) {
        field3114 = 0xd;
    }
    if (((0 < field3114) && (0x31 < field0008)) &&
        (field0008 < 0x9e)) {
        field3114 = 0;
    }
    if ((field3114 == 1) && (field0008 < 200)) {
        field3114 = 0;
    }
    if ((field3114 == 2) && (field0170 != 1)) {
        field3114 = 0;
        return;
    }
    if (field3114 == 4) {
        inputY = 0xff;
        inputX = (unsigned short)RandomRange(0, 2) + -1;
        if (((field0008 == 4) || (field0008 == 5)) ||
            (field0008 == 6)) {
            field0262 = (unsigned short)(facing == '\x01');
            if (field0008 == 0xa5) {
                field3114 = 0;
            }
            inputY = 0;
            inputX = 0;
            return;
        }
    }
    if ((field3114 == 5) && (field0008 < 0x32)) {
        field0262 = (unsigned short)(facing == '\x01');
        if (field0008 == 0xa3) {
            field3114 = 0;
        }
    }
    else if ((field3114 == 6) && (field0008 < 0x32)) {
        field0262 = (unsigned short)(facing == '\x01');
        if (field0008 == 0xa3) {
            field3114 = 7;
        }
    }
    else if ((field3114 == 7) && (field0008 == 0xa3)) {
        buttonPulse[0] = 1;
        if (field0008 == 0xe6) {
            field3114 = 0;
        }
    }
    else if ((field3114 == 8) && (field0008 < 0x32)) {
        field0262 = (unsigned short)(facing == '\x01');
        if (field0008 == 0xa3) {
            field3114 = 9;
        }
    }
    else if ((field3114 == 9) && (field0008 == 0xa3)) {
        buttonPulse[1] = 1;
        if (field0008 == 0xe7) {
            field3114 = 0;
        }
    }
    else if ((field3114 == 10) && (field0008 < 0x32)) {
        field0262 = (unsigned short)(facing == '\x01');
        if (field0008 == 0xa3) {
            field3114 = 0xb;
        }
    }
    else if ((field3114 == 0xb) && (field0008 == 0xa3)) {
        buttonPulse[2] = 1;
        if (field0008 == 0xe8) {
            field3114 = 0;
        }
    }
    else if ((field3114 == 0xc) && (field0008 < 0x32)) {
        buttonPulse[0] = 1;
        inputY = 1;
        if (field0008 == 0xcc) {
            field3114 = 0;
        }
    }
    else {
        if ((field3114 == 0xd) &&
            (field0262 = 0x14, field0008 == 0x103)) {
            field3114 = 0;
        }
        if ((((1 < field0168) && (hitstopFrames == 0)) &&
            (
            (float)(unsigned short)RandomRange(0, 100) < field00a8 * 25.0f)) &&
            ((field3114 != 1 && (field3114 != 2)))) {
            field3110 = (unsigned short)RandomRange(0, 1000);
            if (field0008 == 200) {
                if (((*opponentSlot)->positionY < 0.0) &&
                    (field3110 < 300)) {
                    buttonPulse[1] = 1;
                    inputY = 0;
                    return;
                }
                if ((distance.forward < 50.0) && (field3110 < 400)) {
                    buttonPulse[0] = 1;
                    inputY = 0;
                    if (field0168 == 2) {
                        if ((unsigned short)RandomRange(0, 100) < 30) {
                            buttonPulse[2] = 1;
                            inputY = 1;
                        }
                    }
                    return;
                }
                if (((distance.forward < 125.0) && (399 < field3110)) &&
                    (field3110 < 700)) {
                    buttonPulse[1] = 1;
                    inputY = 0;
                    return;
                }
                if (0x3ca < field3110) {
                    field3114 = 4;
                    inputY = 0xff;
                    inputX = (unsigned short)RandomRange(0, 2) + -1;
                    return;
                }
                if (699 < field3110) {
                    field3114 = 1;
                    if ((unsigned short)RandomRange(0, 2) == 0) {
                        field3114 = 6;
                    }
                    if ((unsigned short)RandomRange(0, 2) == 0) {
                        field3114 = 8;
                    }
                    return;
                }
            }
            if (field0008 == 0xc9) {
                if ((((*opponentSlot)->positionY < 0.0) &&
                    (field3110 < 300)) && (field0168 == 3)) {
                    field0262 = (unsigned short)RandomRange(0, 2) + 0x14;
                    return;
                }
                if ((((*opponentSlot)->positionY < 0.0) &&
                    (299 < field3110)) &&
                    ((field3110 < 0x140 && (meter >= 1000)))
                    ) {
                    field0262 = (unsigned short)RandomRange(0, 3) + 0x78;
                    return;
                }
                if (((((*opponentSlot)->positionY < 0.0) &&
                    (0x140 < field3110)) && (field3110 < 600)
                    ) && (field0168 == 3)) {
                    inputX = facing;
                    inputY = 0xff;
                    return;
                }
                if (field3110 < 200) {
                    buttonPulse[2] = 1;
                    inputY = 1;
                    return;
                }
                if (((200 < field3110) && (field3110 < 0x1c2))
                    && (distance.forward < 90.0)) {
                    buttonPulse[1] = 1;
                    inputY = 0;
                    return;
                }
                if ((((*opponentSlot)->positionY < 0.0) &&
                    (0x1c2 < field3110)) && (field3110 < 700))
                {
                    buttonPulse[2] = 1;
                    return;
                }
                if (900 < field3110) {
                    field3114 = 4;
                    inputY = 0xff;
                    inputX = (unsigned short)RandomRange(0, 2) + -1;
                    return;
                }
                if (700 < field3110) {
                    field3114 = 1;
                    if ((unsigned short)RandomRange(0, 1) == 0) {
                        field3114 = 6;
                        if (distance.forward > 80.0) {
                            field3114 = 8;
                        }
                        return;
                        return;
                    }
                }
            }
            if (field0008 == 0xca) {
                if ((((*opponentSlot)->positionY < 0.0) &&
                    (299 < field3110)) && (field3110 < 0x140))
                {
                    field0262 = 10;
                    return;
                }
                if ((((*opponentSlot)->positionY < 0.0) &&
                    (0x140 < field3110)) &&
                    ((field3110 < 600 && (distance.forward < 100.0)))) {
                    buttonPulse[2] = 1;
                    return;
                }
                if (((field3110 < 500) && (field0168 == 3)) &&
                    (distance.forward < 80.0)) {
                    buttonPulse[2] = 1;
                    inputY = 0;
                    return;
                }
                if (700 < field3110) {
                    field3114 = 1;
                    if ((unsigned short)RandomRange(0, 1) == 0) {
                        field3114 = 6;
                        if (distance.forward > 110.0) {
                            field3114 = 8;
                        }
                        return;
                    }
                }
            }
            if (field0008 == 0xcb) {
                if ((((*opponentSlot)->positionY < 0.0) &&
                    (field3110 < 300)) && (field0168 == 3)) {
                    field0262 = 0x14;
                    return;
                }
                if (((((*opponentSlot)->positionY < 0.0) &&
                    (299 < field3110)) &&
                    ((field3110 < 0x131 &&
                    ((meter >= 3000 && (distance.forward < 90.0)))))) &&
                    (field0168 == 3)) {
                    field0262 = 0x84;
                    return;
                }
                if ((200 < field3110) && (field3110 < 0x15e))
                {
                    field0262 = 0x1e;
                    return;
                }
                if ((0x15e < field3110) && (field3110 < 500))
                {
                    field0262 = (unsigned short)RandomRange(0, 3) + 10;
                    return;
                }
                if ((500 < field3110) && (field3110 < 600)) {
                    field0262 = (unsigned short)RandomRange(0, 3) + 0x46;
                    return;
                }
                if ((0x29e < field3110) && (field3110 < 700))
                {
                    buttonPulse[3] = 1;
                    return;
                }
            }
            if (field0008 == 0xcc) {
                if (((*opponentSlot)->positionY < 0.0) &&
                    (field3110 < 300)) {
                    buttonPulse[1] = 1;
                    inputY = 1;
                    return;
                }
                if ((distance.forward < 50.0) && (field3110 < 400)) {
                    buttonPulse[0] = 1;
                    inputY = 0;
                    if (field0168 == 2) {
                        if ((unsigned short)RandomRange(0, 100) < 20) {
                            buttonPulse[2] = 1;
                            inputY = 1;
                        }
                    }
                    return;
                }
                if ((distance.forward < 135.0) && (field3110 < 600)) {
                    buttonPulse[1] = 1;
                    inputY = 0;
                    return;
                }
                if (0x3b6 < field3110) {
                    field3114 = 4;
                    inputY = 0xff;
                    inputX = (unsigned short)RandomRange(0, 2) + -1;
                    return;
                }
                if (699 < field3110) {
                    field3114 = 1;
                    if ((unsigned short)RandomRange(0, 1) == 0) {
                        field3114 = 6;
                        if (distance.forward > 110.0) {
                            field3114 = 8;
                        }
                        return;
                    }
                    return;
                }
            }
            if (field0008 == 0xcd) {
                if (((((*opponentSlot)->positionY < 0.0) &&
                    (0x140 < field3110)) && (field3110 < 600)
                    ) && (distance.forward < 100.0)) {
                    buttonPulse[2] = 1;
                    return;
                }
                if (field3110 < 100) {
                    buttonPulse[2] = 1;
                    inputY = 1;
                    return;
                }
                if (((100 < field3110) && (field3110 < 300))
                    && (distance.forward < 100.0)) {
                    buttonPulse[1] = 1;
                    inputY = 0;
                    return;
                }
                if ((((*opponentSlot)->positionY < 0.0) &&
                    (300 < field3110)) && (field3110 < 600)) {
                    buttonPulse[2] = 1;
                    return;
                }
                if (900 < field3110) {
                    field3114 = 4;
                    inputY = 0xff;
                    inputX = (unsigned short)RandomRange(0, 2) + -1;
                    return;
                }
                if (700 < field3110) {
                    field3114 = 1;
                    if ((unsigned short)RandomRange(0, 1) == 0) {
                        field3114 = 6;
                        if (distance.forward > 110.0) {
                            field3114 = 8;
                        }
                    }
                    return;
                }
            }
            if (field0008 == 0xce) {
                if ((((*opponentSlot)->positionY < 0.0) &&
                    (field3110 < 300)) && (field0168 == 3)) {
                    field0262 = 0x14;
                    return;
                }
                if ((((*opponentSlot)->positionY < 0.0) &&
                    (299 < field3110)) &&
                    (((field3110 < 0x131 &&
                    ((meter >= 3000 && (distance.forward < 90.0)))) &&
                    (field0168 == 3)))) {
                    field0262 = 0x84;
                    return;
                }
                if (((((*opponentSlot)->positionY < 0.0) &&
                    (0x131 < field3110)) &&
                    (field3110 < 0x15e)) &&
                    ((meter >= 1000 && (field0168 == 3)))) {
                    field0262 = (unsigned short)RandomRange(0, 3) + 100;
                    return;
                }
                if ((200 < field3110) && (field3110 < 0x15e))
                {
                    field0262 = 0x1e;
                    return;
                }
                if ((0x15e < field3110) && (field3110 < 500))
                {
                    field0262 = (unsigned short)RandomRange(0, 3) + 10;
                    return;
                }
                if ((500 < field3110) && (field3110 < 600)) {
                    field0262 = (unsigned short)RandomRange(0, 3) + 0x46;
                    return;
                }
                if ((0x29e < field3110) && (field3110 < 700))
                {
                    buttonPulse[3] = 1;
                    return;
                }
            }
            if (field0008 == 0xcf) {
                if (((*opponentSlot)->positionY < 0.0) &&
                    (field3110 < 300)) {
                    buttonPulse[1] = 1;
                    return;
                }
                if ((distance.forward < 60.0) && (field3110 < 400)) {
                    buttonPulse[0] = 1;
                    return;
                }
                if (((distance.forward < 125.0) && (399 < field3110)) &&
                    (field3110 < 700)) {
                    buttonPulse[2] = 1;
                    inputY = 0;
                    return;
                }
                if (699 < field3110) {
                    field3114 = 1;
                    if ((unsigned short)RandomRange(0, 4) == 0) {
                        field3114 = 3;
                    }
                    return;
                }
            }
            if (field0008 == 0xd0) {
                if (((0x14 < field3110) && (field3110 < 0x3c))
                    && ((field0168 == 3 &&
                    ((*opponentSlot)->positionY < 0.0)))) {
                    field0262 = 10;
                    return;
                }
                if ((0x50 < field3110) && (field3110 < 300)) {
                    buttonPulse[2] = 1;
                    return;
                }
                if (0x3b6 < field3110) {
                    inputX = (unsigned short)RandomRange(0, 2) + -1;
                    return;
                }
                if (0x289 < field3110) {
                    field3114 = 3;
                    return;
                }
            }
            if (field0008 == 0xd1) {
                if (0x3b6 < field3110) {
                    inputX = (unsigned short)RandomRange(0, 2) + -1;
                    return;
                }
                if (0x289 < field3110) {
                    field3114 = 3;
                    return;
                }
            }
            if (field0008 == 0xe7) {
                if ((((*opponentSlot)->positionY < 0.0) &&
                    (field3110 < 300)) && (field0168 == 3)) {
                    field0262 = (unsigned short)RandomRange(0, 2) + 0x14;
                    return;
                }
                if (((200 < field3110) && (field3110 < 0xdc))
                    && ((distance.forward < 90.0 &&
                    ((field0168 == 3 && (meter >= 1000)))
                    ))) {
                    field0262 = (unsigned short)RandomRange(0, 3) + 0x78;
                    return;
                }
                if (((0x15e < field3110) && (field3110 < 400))
                    && (field0118 > 500.0)) {
                    field0262 = 0x34;
                    return;
                }
                if (((0x289 < field3110) &&
                    ( (unsigned short)RandomRange(0, 2) == 0)) &&
                    (field3114 = 0xc, distance.forward > 110.0)) {
                    field3114 = 8;
                }
            }
            if (field0008 == 0xe8) {
                if ((((*opponentSlot)->positionY < 0.0) &&
                    (field3110 < 300)) && (field0168 == 3)) {
                    field0262 = 10;
                    return;
                }
                if (((((*opponentSlot)->positionY < 0.0) &&
                    (299 < field3110)) && (field3110 < 0x140)
                    ) && ((meter >= 1000 && (distance.forward < 90.0)))) {
                    field0262 = (unsigned short)RandomRange(0, 3) + 0x78;
                    return;
                }
                if (((0 < field3110) && (field3110 < 200)) &&
                    (field0168 == 3)) {
                    field0262 = 10;
                    return;
                }
                if ((200 < field3110) && (field3110 < 0xfa)) {
                    field0262 = (unsigned short)RandomRange(0, 3) + 0x1e;
                    return;
                }
                if (((0x15e < field3110) && (field3110 < 400))
                    && (field0118 > 500.0)) {
                    field0262 = 0x34;
                    return;
                }
                if (((400 < field3110) && (field3110 < 0x1ae))
                    && ((field0168 == 3 && (meter == 3000))
                    )) {
                    field0262 = 0x5f;
                    return;
                }
                if (((0x1ae < field3110) &&
                    (field3110 < 0x21c)) && (field0168 != 3)) {
                    field0262 = 0x28;
                    if (distance.forward > 120.0) {
                        field0262 = 0x29;
                    }
                    return;
                }
                if ((0x38e < field3110) && (field0168 == 3)) {
                    field3114 = 4;
                    inputY = 0xff;
                    inputX = (unsigned short)RandomRange(0, 2) + -1;
                    return;
                }
                if (0x289 < field3110) {
                    field3114 = 1;
                    return;
                }
            }
        }
        if ((float)(unsigned short)RandomRange(0, 100) < 25.0f * field00a8) {
            field3110 = (unsigned short)RandomRange(0, 1000);
            if (positionY == 0.0) {
                if (((*opponentSlot)->positionY == 0.0) &&
                    ((*opponentSlot)->field0008 != 99)) {
                    if ((distance.forward < 40.0) &&
                        (((*opponentSlot)->positionY == 0.0 &&
                        (field3110 < 5)))) {
                        buttonPulse[2] = 1;
                        inputX = -facing;
                        inputY = 0;
                        return;
                    }
                    if ((distance.forward < 50.0) && (field3110 < 0x14)) {
                        buttonPulse[0] = 1;
                        inputY = 1;
                        return;
                    }
                    if ((distance.forward < 75.0) && (field3110 < 0x19)) {
                        buttonPulse[0] = 1;
                        inputY = 0;
                        return;
                    }
                    if (((distance.forward < 120.0) && (field3110 < 0x3c)) &&
                        (0x1e < field3110)) {
                        buttonPulse[1] = 1;
                        inputY = 1;
                        return;
                    }
                    if ((((distance.forward < 80.0) && (field3110 < 0x34)) &&
                        (0x28 < field3110)) ||
                        (((distance.forward > 90.0 && (distance.forward < 150.0)) &&
                        ((field3110 < 0x50 && (0x34 < field3110)
                        ))))) {
                        buttonPulse[1] = 1;
                        inputY = 0;
                        return;
                    }
                    if ((((distance.forward > 80.0) && (distance.forward < 120.0)) &&
                        (field3110 < 0x55)) &&
                        (0x50 < field3110)) {
                        field3114 = 8;
                        return;
                    }
                    if (((distance.forward > 70.0) && (distance.forward < 120.0)) &&
                        ((field3110 < 0x78 && (0x5a < field3110))
                        )) {
                        field3114 = 8;
                        return;
                    }
                    if (((distance.forward < 160.0) && (distance.forward > 70.0)) &&
                        ((field3110 < 0x82 && (0x78 < field3110))
                        )) {
                        buttonPulse[2] = 1;
                        inputY = 1;
                        return;
                    }
                    if ((((distance.forward < 100.0) && (distance.forward > 70.0)) &&
                        (field3110 < 0x91)) &&
                        (0x82 < field3110)) {
                        buttonPulse[2] = 1;
                        inputY = 0;
                        return;
                    }
                    if (((distance.forward > 100.0) && (distance.forward < 140.0)) &&
                        ((field3110 < 0x98 && (0x91 < field3110))
                        )) {
                        field3114 = 10;
                        return;
                    }
                    if (((distance.forward < 70.0) && (field3110 < 0xb9)) &&
                        ((0x91 < field3110 &&
                        ((field0118 > 500.0 &&
                        (199 < (*opponentSlot)->field0008)))))) {
                        field0262 = 0x14;
                        return;
                    }
                    if (((((distance.forward < 100.0) && (distance.forward > 40.0)) &&
                        (field3110 < 0xbe)) &&
                        ((0xb9 < field3110 &&
                        (meter >= 3000)))) &&
                        (199 < (*opponentSlot)->field0008)) {
                        field0262 = 0x84;
                        return;
                    }
                    if (((distance.forward > 120.0) && (field3110 < 200)) &&
                        ((0xbe < field3110 &&
                        ((meter >= 3000 &&
                        (199 < (*opponentSlot)->field0008)))))) {
                        field0262 = 0x70;
                        return;
                    }
                    if (((distance.forward > 200.0) && (field3110 < 0xbe)) &&
                        (0xaa < field3110)) {
                        field0262 = (unsigned short)RandomRange(0, 3) + 10;
                        return;
                    }
                    if (((distance.forward > 180.0) && (field3110 < 200)) &&
                        (0xbe < field3110)) {
                        field0262 = 0x46;
                        return;
                    }
                    if (((distance.forward > 180.0) && (field3110 < 0xd2)) &&
                        (200 < field3110)) {
                        field0262 = 0x47;
                        return;
                    }
                    if ((((distance.forward > 80.0) && (distance.forward < 120.0)) &&
                        (field3110 < 0xdc)) &&
                        (0xd2 < field3110)) {
                        field0262 = 0x1e;
                        return;
                    }
                    if (((distance.forward > 140.0) && (distance.forward < 180.0)) &&
                        ((field3110 < 0xf0 && (0xe6 < field3110))
                        )) {
                        field0262 = 0x1f;
                        return;
                    }
                    if (((field0118 > 500.0) ||
                        (field0120 == '\x01')) &&
                        ((field3110 < 0xf5 && (0xf0 < field3110))
                        )) {
                        field0262 = 0x20;
                        return;
                    }
                    if ((((distance.forward > 140.0) && (field3110 < 0x104)) &&
                        (0xfa < field3110)) &&
                        (meter >= 1000)) {
                        field0262 = (unsigned short)RandomRange(0, 3) + 0x78;
                        return;
                    }
                }
                if ((*opponentSlot)->positionY < 0.0) {
                    if ((*opponentSlot)->velocityY < 0.0) {
                        if (((distance.forward < 80.0) && (distance.vertical < 120.0)) &&
                            (field3110 < 10)) {
                            inputY = 0xff;
                            inputX = -facing;
                            return;
                        }
                        if (((distance.forward < 150.0) && (distance.forward > 50.0)) &&
                            ((field3110 < 0x28 &&
                            (meter >= 3000)))) {
                            field0262 = 0x84;
                            return;
                        }
                    }
                    if ((*opponentSlot)->velocityY > 0.0) {
                        if ((((distance.forward < 90.0) && (distance.vertical < 140.0)) &&
                            (field3110 < 6)) &&
                            ((field0118 > 500.0 ||
                            ('\0' < field0120)))) {
                            field0262 = 0x16;
                            return;
                        }
                        if (((distance.forward < 90.0) && (distance.vertical < 140.0)) &&
                            (field3110 < 0x1e)) {
                            field0262 = 0x16;
                            return;
                        }
                        if (((((distance.forward < 80.0) && (distance.forward > 30.0)) &&
                            (distance.vertical < 140.0)) &&
                            ((distance.vertical > 100.0 && (field3110 < 0x41)))) &&
                            (0x1e < field3110)) {
                            buttonPulse[1] = 1;
                            inputY = 0;
                            return;
                        }
                        if (((distance.forward > 100.0) && (distance.forward < 140.0)) &&
                            ((distance.vertical < 140.0 &&
                            (((distance.vertical > 100.0 && (field3110 < 0x50)) &&
                            (0x3c < field3110)))))) {
                            buttonPulse[1] = 1;
                            inputY = 0;
                            return;
                        }
                        if (((distance.forward < 160.0) && (distance.forward > 30.0)) &&
                            (((field3110 < 0x6e &&
                            ((0x50 < field3110 &&
                            ((*opponentSlot)->positionY < -50.0)))) &&
                            (meter >= 3000)))) {
                            field0262 = 0x84;
                            return;
                        }
                    }
                }
            }
            if ((positionY < 0.0) &&
                (field3114 != 3)) {
                if ((*opponentSlot)->positionY == 0.0) {
                    if (((distance.forward < 110.0) && (distance.vertical < 100.0)) &&
                        (field3110 < 0x32)) {
                        buttonPulse[0] = 1;
                        return;
                    }
                    if (((distance.forward > 50.0) && (distance.forward < 100.0)) &&
                        ((distance.vertical < 100.0 &&
                        ((0x32 < field3110 && (field3110 < 0x78)
                        ))))) {
                        buttonPulse[1] = 1;
                        return;
                    }
                    if ((((distance.forward < 90.0) && (distance.vertical > 100.0)) &&
                        (distance.vertical < 180.0)) &&
                        ((0x78 < field3110 && (field3110 < 0xaa))
                        )) {
                        buttonPulse[2] = 1;
                        return;
                    }
                    if ((((double)(unsigned short)RandomRange(0, 0x140) < distance.forward - 100.0) && (distance.vertical < 90.0)) &&
                        ((0xaa < field3110 && (field3110 < 0xdc))
                        )) {
                        field0262 = (unsigned short)RandomRange(0, 3) + 10;
                        return;
                    }
                    if ((((distance.forward > 100.0) && (0xf0 < field3110)) &&
                        (field3110 < 0x14a)) &&
                        ((distance.forward < distance.vertical + 40.0 && (distance.vertical - 40.0 < distance.forward)))) {
                        field0262 = (unsigned short)RandomRange(0, 3) + 0x1e;
                        return;
                    }
                }
                if ((*opponentSlot)->positionY < 0.0) {
                    if (((distance.forward < 110.0) && (distance.vertical < 100.0)) &&
                        (field3110 < 0x32)) {
                        buttonPulse[0] = 1;
                        return;
                    }
                    if ((((distance.forward > 50.0) && (distance.forward < 100.0)) &&
                        (distance.vertical < 100.0)) &&
                        ((0x32 < field3110 && (field3110 < 0x78))
                        )) {
                        buttonPulse[1] = 1;
                        return;
                    }
                    if (((distance.forward < 90.0) && (distance.vertical > 100.0)) &&
                        ((distance.vertical < 180.0 &&
                        ((0x78 < field3110 && (field3110 < 0xaa)
                        ))))) {
                        buttonPulse[2] = 1;
                        return;
                    }
                    if (((((double)(unsigned short)RandomRange(0, 0x140) < distance.forward - 100.0) && (distance.vertical < 90.0)) &&
                        (0xaa < field3110)) &&
                        (field3110 < 0xdc)) {
                        field0262 = (unsigned short)RandomRange(0, 3) + 10;
                        return;
                    }
                    if (((distance.forward > 100.0) && (0xf0 < field3110)) &&
                        ((field3110 < 0x14a &&
                        ((distance.forward < distance.vertical + 40.0 && (distance.vertical - 40.0 < distance.forward)))))) {
                        field0262 = (unsigned short)RandomRange(0, 3) + 0x1e;
                        return;
                    }
                }
            }
        }
        if (field0008 < 50 &&
            (((*opponentSlot)->field0008 > 149 && (*opponentSlot)->field0008 < 156) ||
            ((*opponentSlot)->field0008 > 49 && (*opponentSlot)->field0008 < 59)) &&
            positionY == 0.0 &&
            (float)(unsigned short)RandomRange(0, 100) < 3.0f * field00a8) {
            field0262 = (unsigned short)(facing == 1);
            return;
        }
        if (field0008 < 50 && (*opponentSlot)->field0008 < 50 &&
            distance.forward > 60.0 && distance.forward < 140.0 &&
            (float)(unsigned short)RandomRange(0, 100) < 2.0f * field00a8 &&
            positionX > 120.0 && positionX < 520.0) {
            field0262 = (unsigned short)(facing != 1);
            return;
        }
        if ((unsigned short)RandomRange(0, 1000) < 1) {
            field3114 = 4;
            return;
        }
        if ((unsigned short)RandomRange(0, 100) < 2) {
            if ((float)(unsigned short)RandomRange(0, 100) < 8.0f * field00a8) {
                field3114 = 3;
            } else {
                field3114 = 0;
            }
            if (((distance.forward > 180.0) &&
                (positionY == 0.0)) &&
                ( (unsigned short)RandomRange(0, 100) < 2)) {
                inputX = 0;
                inputY = 0xff;
                return;
            }
            if ((((distance.forward < 170.0) && (distance.forward > 140.0)) &&
                (positionY == 0.0)) &&
                ((*opponentSlot)->field0008 < 0x32)) {
                inputX = facing;
                inputY = 0xff;
                return;
            }
        }
        if (field01a0 > 0) {
            if ((CollisionSide() != '\0') && (0xf < field01a0)) {
                field01a0 = 0xf;
            }
            inputX = 1;
            return;
        }
        if (field01a4 > 0) {
            if ((CollisionSide() != '\0') && (0xf < field01a4)) {
                field01a4 = 0xf;
            }
            inputX = 0xff;
            return;
        }
        if (((unsigned short)RandomRange(0, 100) < 0x32) && (distance.forward < 120.0)) {
            if (facing == '\x01') {
                field01a4 = ((unsigned short)RandomRange(0, 200)) + 0x2d;
            }
            else {
                field01a0 = ((unsigned short)RandomRange(0, 200)) + 0x2d;
            }
        }
        if ((unsigned short)RandomRange(0, 100) < 0x32) {
            if (facing == '\x01') {
                field01a0 = ((unsigned short)RandomRange(0, 200)) + 0x2d;
            }
            else {
                field01a4 = ((unsigned short)RandomRange(0, 200)) + 0x2d;
            }
        }
        else if (facing == -1) {
            field01a0 = ((unsigned short)RandomRange(0, 200)) + 0x2d;
        }
        else {
            field01a4 = ((unsigned short)RandomRange(0, 200)) + 0x2d;
        }
    }
    return;
}
