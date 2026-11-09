// Mayu CPU input generation and command selection.
#include "CharacterViews.h"
#include <math.h>

void Character05::Slot05()
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
    guardInputFrames = 0;
    if ((float)(unsigned short)RandomRange(0, 1000) <
        25.0f * field00a8 + (positionY < 0.0 ? 1 : 0) * 30 * field00a8 +
        (float)((field3114 == 3) * 400) + (float)((field0008 == 0xaa ? 1 : 0) * 300))
    {
        guardInputFrames = 0x3c;
    }
    if ((double)(unsigned short)RandomRange(0, 2000) <
        ((double)(field0130 > 0) * 4.0 + 1.0) * 8.0 * field00a8 *
        ((field0008 > 149 && field0008 < 157 ? 1 : 0) * 2 + 1)) {
        guardInputFrames = 0x3c;
    }
    if (((float)(unsigned short)RandomRange(0, 1000) < 40.0f * field00a8) && (199 < field0008)) {
        guardInputFrames = 0x3c;
    }
    if ((attackWasGuarded == 1) && (field3114 == 2)) {
        guardInputFrames = 0x1e;
        if (field0008 < 200) {
            field3114 = 0;
        }
        return;
    }
    if ((*opponentSlot)->field0008 == 0x60) { return; }
    distance.forward = ((*opponentSlot)->positionX - positionX) * facing;
    distance.vertical = fabs(positionY - (*opponentSlot)->positionY);
    if (!( ((field0008 < 0x32) || (0x96 < field0008)) ||
        ((unsigned short)field000c != 0) )) {
        if ((float)(unsigned short)RandomRange(0, 100) < 8.0f * field00a8) {
            field3114 = 3;
        } else { field3114 = 0; }
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
        (field0008 >= 10 && field0008 <= 12)) && positionY == 0.0) { return; }
    if ((*opponentSlot)->field0008 >= 50 && (*opponentSlot)->field0008 < 150 &&
        field0008 == 264 && field016c > 1) { return; }
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
                (float)(unsigned short)RandomRange(0, 100) < field00a8 * 3.0f)) {
                buttonPulse[0] = 1;
                inputY = 0;
                return;
            }
        }
        if ((((((*opponentSlot)->field0008 == 0xc9) ||
            ((*opponentSlot)->field0008 == 0xca)) ||
            ((*opponentSlot)->field0008 == 0xcd)) &&
            ((((*opponentSlot)->field0008 < 0xfa &&
            ((*opponentSlot)->positionY == 0.0)) &&
            (((*opponentSlot)->field016c == 0 &&
            ((distance.forward > 60.0 && (distance.forward < 70.0)))))))) &&
            (
            (float)(unsigned short)RandomRange(0, 100) < field00a8 * 3.0f)) {
            buttonPulse[1] = 1;
            inputY = 0;
            return;
        }
    }
    if ((field0008 == 0xa8) || (field0008 == 0xa9)) {
        if (distance.forward < 80.0) {
            if (((float)(unsigned short)RandomRange(0, 100) < field00a8 * 3.0f) &&
                (field0118 > 500.0)) {
                field0262 = 0x16;
                return;
            }
            if ((float)(unsigned short)RandomRange(0, 100) < field00a8 * 3.0f + (float)((field0118 > 500.0 ? 1 : 0) << 1)) {
                field0262 = 0xc;
                return;
            }
            if ((((float)(unsigned short)RandomRange(0, 100) < field00a8 * 4.0f) &&
                (meter >= 1000)) &&
                ((*opponentSlot)->positionY == 0.0)) {
                field0262 = (unsigned short)RandomRange(0, 3) + 100;
                return;
            }
            if ((((float)(unsigned short)RandomRange(0, 100) < field00a8 * 3.0f) &&
                (meter == 3000)) &&
                ((*opponentSlot)->positionY < -30.0)) {
                field0262 = 0x7a;
                return;
            }
        }
        if (((distance.forward < 120.0) &&
            (
            (float)(unsigned short)RandomRange(0, 100) < field00a8 * 3.0f)) &&
            (field0118 > 500.0)) {
            field0262 = 0xc;
            return;
        }
        if (distance.forward > 120.0) {
            if (((float)(unsigned short)RandomRange(0, 100) < field00a8 * 1.0f) &&
                (field0118 > 500.0)) {
                field0262 = 0xc;
                return;
            }
            if ((float)(unsigned short)RandomRange(0, 100) < field00a8 * 1.0f) {
                field0262 = (unsigned short)RandomRange(0, 0) * 2 + 0x1e;
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
            (-40.0 < positionY - (*opponentSlot)->positionY
            )) && ((distance.forward < 60.0 &&
            (
            (float)(unsigned short)RandomRange(0, 100) < field00a8 * 5.0f)))) {
            buttonPulse[0] = 1;
            return;
        }
        if (((-40.0 <
            positionY - (*opponentSlot)->positionY) &&
            (positionY - (*opponentSlot)->positionY < 0.0
            )) && ((distance.forward < 70.0 &&
            (
            (float)(unsigned short)RandomRange(0, 100) < field00a8 * 5.0f)))) {
            buttonPulse[1] = 1;
            return;
        }
        if ((((-60.0 <
            positionY - (*opponentSlot)->positionY) &&
            (positionY - (*opponentSlot)->positionY <
            30.0)) && (distance.vertical > 80.0)) &&
            ((distance.forward < 80.0 &&
            (
            (float)(unsigned short)RandomRange(0, 100) < field00a8 * 5.0f)))) {
            buttonPulse[2] = 1;
            inputY = 0;
            return;
        }
        if (((distance.vertical < 50.0) && (distance.forward < 100.0)) &&
            (
            (float)(unsigned short)RandomRange(0, 100) < field00a8 * 1.0f)) {
            field0262 = 0x1e;
            return;
        }
    }
    if ((((((*opponentSlot)->field0008 == 0xa8) ||
        ((*opponentSlot)->field0008 == 0xa9)) ||
        ((*opponentSlot)->field0008 == 0xaa)) &&
        ((positionY == 0.0 &&
        (
        (float)(unsigned short)RandomRange(0, 100) < 15.0f * field00a8)))) &&
        ((field3114 != 2 && ((*opponentSlot)->hitstunFrames == 0)))) {
        field3110 = (unsigned short)RandomRange(0, 100);
        if ((field3110 < 4) && (field0118 > 500.0)) {
            field0262 = 0x16;
            return;
        }
        if ((field3110 < 10) && (field0118 > 500.0)) {
            field0262 = 0xc;
            return;
        }
        if ((field3110 < 0xd) && (distance.forward > 100.0)) {
            field0262 = 0x1e;
            return;
        }
        if ((field3110 < 0xd) && (distance.forward < 90.0)) {
            field0262 = 0x20;
            return;
        }
        if ((((field3110 < 0x11) && (0xc < field3110)) && (meter >= 1000))
            && (distance.forward < 80.0)) {
            field0262 = (unsigned short)RandomRange(0, 2) * 100;
            return;
        }
    }
    if ((((((*opponentSlot)->field0008 == 0xa8) ||
        ((*opponentSlot)->field0008 == 0xa9)) ||
        ((*opponentSlot)->field0008 == 0xaa)) &&
        ((positionY < 0.0 &&
        (
        (float)(unsigned short)RandomRange(0, 100) < 15.0f * field00a8)))) &&
        ((field3114 != 2 && ((*opponentSlot)->hitstunFrames == 0)))) {
        field3110 = (unsigned short)RandomRange(0, 100);
        if (field3110 < 0x14) {
            field3114 = 2;
            return;
        }
        if ((distance.forward < 100.0) && (field3110 < 0x16)) {
            field0262 = 0x1e;
            return;
        }
    }
    if ((field0118 > 500.0 || field0120 > 0) &&
        (float)(unsigned short)RandomRange(0, 100) < 8.0f * field00a8 &&
        (*opponentSlot)->field0008 > 149 && (*opponentSlot)->field0008 < 157 &&
        (field0008 == 259 || field0008 == 260 || field0008 == 266 || field0008 == 267 ||
        field0008 == 301 || field0008 == 302)) {
        field0262 = 52; return;
    }
    if ((0 < field3114) &&
        ((0x31 < field0008 && (field0008 < 0x9e)))) {
        field3114 = 0;
    }
    if ((field3114 == 1) && (field0008 < 200)) {
        field3114 = 0;
    }
    if ((field3114 == 2) && (attackWasGuarded != 1)) {
        field3114 = 0;
        return;
    }
    if (field3114 == 4) {
        inputY = 0xff;
        inputX = (unsigned short)RandomRange(0, 2) + -1;
        if (((field0008 == 4) || (field0008 == 5)) || (field0008 == 6)
            ) {
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
        field3114 = 0;
        field0262 = (unsigned short)(facing == '\x01');
    }
    else if ((field3114 == 6) && (field0008 < 0x32)) {
        field3114 = 7;
        field0262 = (unsigned short)(facing == '\x01');
    }
    else if ((field3114 == 7) && (field0008 == 0xa3)) {
        inputX = -facing;
        buttonPulse[1] = 1;
        if (field0008 == 0xe7) {
            field3114 = 0;
        }
    }
    else if ((field3114 == 8) && (field0008 < 0x32)) {
        field0262 = (unsigned short)(facing == '\x01');
        field3114 = 9;
    }
    else if ((field3114 == 9) && (field0008 == 0xa3)) {
        inputX = -facing;
        buttonPulse[0] = 1;
        if (field0008 == 0xe6) {
            field3114 = 0;
        }
    }
    else if ((field3114 == 10) && (field0008 < 0x32)) {
        inputY = 0;
        buttonPulse[0] = 1;
        if (field0008 == 200) {
            field3114 = 0;
        }
    }
    else {
        if ((((1 < field0168) && (hitstopFrames == 0)) &&
            (
            (float)(unsigned short)RandomRange(0, 100) < field00a8 * 25.0f)) &&
            ((field3114 != 0 && (field3114 != 2)))) {
            field3110 = (unsigned short)RandomRange(0, 1000);
            if (field0008 == 200) {
                if (((*opponentSlot)->positionY < 0.0) &&
                    (field3110 < 0x96)) {
                    buttonPulse[1] = 1;
                    inputY = 1;
                    return;
                }
                if ((distance.forward < 40.0) && (field3110 < 400)) {
                    buttonPulse[0] = 1;
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
                if (((distance.forward < 100.0) && (0x96 < field3110)) && (field3110 < 600)
                    ) {
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
                if (600 < field3110) {
                    field3114 = 1;
                    if ((unsigned short)RandomRange(0, 4) == 0) {
                        field3114 = 5;
                    }
                    if ((unsigned short)RandomRange(0, 3) == 0) {
                        field3114 = 6;
                    }
                    return;
                }
            }
            if (field0008 == 0xc9) {
                if ((((*opponentSlot)->positionY < 0.0) &&
                    (field3110 < 400)) && (field0168 == 3)) {
                    field0262 = 0x14;
                    return;
                }
                if ((((*opponentSlot)->positionY < 0.0) &&
                    (400 < field3110)) &&
                    ((field3110 < 500 && (meter >= 1000)))) {
                    field0262 = (unsigned short)RandomRange(0, 3) + 0x78;
                    return;
                }
                if (((((*opponentSlot)->positionY < 0.0) &&
                    (400 < field3110)) && (field3110 < 700)) && (distance.forward < 90.0)
                    ) {
                    inputY = 0xff;
                    inputX = facing;
                    return;
                }
                if (field3110 < 0x96) {
                    buttonPulse[2] = 1;
                    inputY = 1;
                    return;
                }
                if ((0x96 < field3110) && (field3110 < 400)) {
                    buttonPulse[1] = 1;
                    inputY = 0;
                    return;
                }
                if ((400 < field3110) && (field3110 < 0x226)) {
                    buttonPulse[2] = 1;
                    inputY = 0;
                    return;
                }
                if ((0x226 < field3110) && (field3110 < 600)) {
                    field0262 = (unsigned short)RandomRange(0, 3) + 0x1e;
                    return;
                }
                if (((600 < field3110) && (field3110 < 0x26c)) &&
                    (distance.forward > 80.0)) {
                    field0262 = (unsigned short)RandomRange(0, 3) + 0x46;
                    return;
                }
                if (0x398 < field3110) {
                    field3114 = 4;
                    inputY = 0xff;
                    inputX = (unsigned short)RandomRange(0, 2) + -1;
                    return;
                }
                if (499 < field3110) {
                    field3114 = 1;
                    if ((unsigned short)RandomRange(0, 2) == 0) {
                        field3114 = 5;
                    }
                    if ((unsigned short)RandomRange(0, 2) == 0) {
                        field3114 = 6;
                    }
                    if ((unsigned short)RandomRange(0, 3) == 0) {
                        field3114 = 8;
                    }
                    if (distance.forward < 45.0) {
                        if ((unsigned short)RandomRange(0, 2) == 0) {
                            field3114 = 10;
                        }
                    }
                    return;
                }
            }
            if (field0008 == 0xca) {
                if (((((*opponentSlot)->positionY < 0.0) &&
                    ((*opponentSlot)->positionY < -50.0)) &&
                    ((distance.forward < 70.0 && ((field3110 < 200 && (field0168 == 3))))))
                    && (meter == 3000)) {
                    field0262 = 0x7a;
                    return;
                }
                if ((((*opponentSlot)->positionY < 0.0) &&
                    (199 < field3110)) && (field3110 < 400)) {
                    buttonPulse[2] = 1;
                    inputY = 0;
                    return;
                }
                if ((((*opponentSlot)->positionY < 0.0) &&
                    (400 < field3110)) && (field3110 < 500)) {
                    field0262 = 0xb;
                    return;
                }
                if ((((*opponentSlot)->positionY < 0.0) &&
                    (399 < field3110)) && ((field3110 < 500 && (field0168 == 3)))) {
                    field0262 = (unsigned short)RandomRange(0, 2) + 100;
                    return;
                }
                if (((0 < field3110) && (field3110 < 400)) && (distance.forward < 90.0)) {
                    buttonPulse[2] = 1;
                    inputY = 0;
                    if ((unsigned short)RandomRange(0, 10) < 7) {
                        inputY = 1;
                    }
                    return;
                }
                if (((0x1e0 < field3110) && (field3110 < 0x226)) &&
                    ((field0168 == 3 && (meter >= 1000)))) {
                    field0262 = (unsigned short)RandomRange(0, 3) + 0xaa;
                    return;
                }
                if ((0x226 < field3110) && (field3110 < 600)) {
                    field0262 = (unsigned short)RandomRange(0, 3) + 0x1e;
                    return;
                }
                if (((600 < field3110) && (field3110 < 0x26c)) &&
                    (distance.forward > 80.0)) {
                    field0262 = (unsigned short)RandomRange(0, 3) + 0x46;
                    return;
                }
                if (0x26c < field3110) {
                    field3114 = 1;
                    if ((unsigned short)RandomRange(0, 2) == 0) {
                        field3114 = 5;
                    }
                    if ((unsigned short)RandomRange(0, 2) == 0) {
                        field3114 = 6;
                    }
                    if ((unsigned short)RandomRange(0, 3) == 0) {
                        field3114 = 8;
                    }
                    if (distance.forward < 45.0) {
                        if ((unsigned short)RandomRange(0, 2) == 0) {
                            field3114 = 10;
                        }
                    }
                    return;
                }
            }
            if (field0008 == 0xcb) {
                if ((((*opponentSlot)->positionY < 0.0) &&
                    (field3110 < 200)) &&
                    ((field0168 == 3 &&
                    ((distance.vertical < 70.0 && (field0118 > 500.0))))))
                {
                    field0262 = 0xc;
                    return;
                }
                if ((((0 < field3110) && (field3110 < 100)) && (field0168 != 3)) &&
                    (field0118 > 500.0)) {
                    field0262 = 10;
                    if ((unsigned short)RandomRange(0, 2) == 0) {
                        field0262 = 0xb;
                    }
                    return;
                }
                if ((0xfa < field3110) && (field3110 < 0x226)) {
                    field0262 = (unsigned short)RandomRange(0, 3) + 0x1e;
                    return;
                }
                if (((0x226 < field3110) && (field3110 < 600)) &&
                    ((field0168 == 3 &&
                    ((meter >= 1000 && (distance.forward < 90.0)))))) {
                    field0262 = (unsigned short)RandomRange(0, 3) + 0xaa;
                    return;
                }
                if (((600 < field3110) && (field3110 < 0x2a8)) &&
                    (distance.forward > 80.0)) {
                    field0262 = (unsigned short)RandomRange(0, 3) + 0x46;
                    return;
                }
                if (799 < field3110) {
                    field3114 = 1;
                    return;
                }
            }
            if (field0008 == 0xcc) {
                if (((*opponentSlot)->positionY < 0.0) &&
                    (field3110 < 0x96)) {
                    buttonPulse[1] = 1;
                    inputY = 1;
                    return;
                }
                if ((distance.forward < 40.0) && (field3110 < 400)) {
                    buttonPulse[0] = 1;
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
                if (((distance.forward < 100.0) && (0x96 < field3110)) && (field3110 < 600)
                    ) {
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
                if (500 < field3110) {
                    field3114 = 1;
                    if ((unsigned short)RandomRange(0, 4) == 0) {
                        field3114 = 5;
                    }
                    if ((unsigned short)RandomRange(0, 3) == 0) {
                        field3114 = 6;
                    }
                    if ((unsigned short)RandomRange(0, 2) == 0) {
                        field3114 = 8;
                    }
                    if (distance.forward < 45.0) {
                        if ((unsigned short)RandomRange(0, 3) == 0) {
                            field3114 = 10;
                        }
                    }
                    return;
                }
            }
            if (field0008 == 0xcd) {
                if ((((*opponentSlot)->positionY < 0.0) &&
                    (field3110 < 400)) && (field0168 == 3)) {
                    field0262 = 0x14;
                    return;
                }
                if ((((*opponentSlot)->positionY < 0.0) &&
                    (400 < field3110)) && ((field3110 < 700 && (distance.forward < 90.0)))
                    ) {
                    inputY = 0xff;
                    inputX = facing;
                    return;
                }
                if (field3110 < 200) {
                    buttonPulse[2] = 1;
                    inputY = 1;
                    return;
                }
                if ((200 < field3110) && (field3110 < 0x15e)) {
                    buttonPulse[1] = 1;
                    inputY = 0;
                    return;
                }
                if ((0x15e < field3110) && (field3110 < 0x226)) {
                    buttonPulse[2] = 1;
                    inputY = 0;
                    return;
                }
                if ((0x226 < field3110) && (field3110 < 600)) {
                    field0262 = (unsigned short)RandomRange(0, 3) + 0x1e;
                    return;
                }
                if (((600 < field3110) && (field3110 < 0x26c)) &&
                    (distance.forward > 80.0)) {
                    field0262 = (unsigned short)RandomRange(0, 3) + 0x46;
                    return;
                }
                if (0x398 < field3110) {
                    field3114 = 4;
                    inputY = 0xff;
                    inputX = (unsigned short)RandomRange(0, 2) + -1;
                    return;
                }
                if (0x28a < field3110) {
                    field3114 = 1;
                    if ((unsigned short)RandomRange(0, 4) == 0) {
                        field3114 = 5;
                    }
                    if ((unsigned short)RandomRange(0, 2) == 0) {
                        field3114 = 6;
                    }
                    if ((unsigned short)RandomRange(0, 2) == 0) {
                        field3114 = 8;
                    }
                    if (distance.forward < 45.0) {
                        if ((unsigned short)RandomRange(0, 4) == 0) {
                            field3114 = 10;
                        }
                    }
                    return;
                }
            }
            if (field0008 == 0xce) {
                if (((field3110 < 200) && (field0168 == 3)) &&
                    (field0118 > 500.0)) {
                    field0262 = 0xc;
                    return;
                }
                if (((0 < field3110) && (field3110 < 100)) &&
                    ((field0168 != 3 && (field0118 > 500.0)))) {
                    field0262 = 10;
                    if ((unsigned short)RandomRange(0, 2) == 0) {
                        field0262 = 0xb;
                    }
                    return;
                }
                if ((0xfa < field3110) && (field3110 < 0x226)) {
                    field0262 = (unsigned short)RandomRange(0, 3) + 0x1e;
                    return;
                }
                if ((((0x226 < field3110) && (field3110 < 600)) && (field0168 == 3))
                    && ((meter >= 1000 && (distance.forward < 70.0)))) {
                    field0262 = (unsigned short)RandomRange(0, 3) + 0x78;
                    return;
                }
                if (((600 < field3110) && (field3110 < 0x2a8)) &&
                    (distance.forward > 80.0)) {
                    field0262 = (unsigned short)RandomRange(0, 3) + 0x46;
                    return;
                }
                if (799 < field3110) {
                    field3114 = 1;
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
                if (((distance.forward < 125.0) && (399 < field3110)) && (field3110 < 700))
                {
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
                if (((0x14 < field3110) &&
                    (field3110 < (int)((unsigned int)(field0168 != 3) * 0x32 + 0x32))) &&
                    ((*opponentSlot)->positionY < 0.0)) {
                    field0262 = 0x1e;
                    if ((unsigned short)RandomRange(0, 2) == 0) {
                        field0262 = 0x20;
                    }
                    return;
                }
                if ((0x3c < field3110) && (field3110 < 300)) {
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
                if (((0x14 < field3110) &&
                    (field3110 < (int)((unsigned int)(field0168 != 3) * 0x32 + 0x32))) &&
                    ((*opponentSlot)->positionY < 0.0)) {
                    field0262 = 0x1e;
                    if ((unsigned short)RandomRange(0, 2) == 0) {
                        field0262 = 0x20;
                    }
                    return;
                }
                if (0x289 < field3110) {
                    field3114 = 3;
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
                    if (distance.forward < 35.0) {
                        if (field3110 <
                            (int)(((*opponentSlot)->field0008 > 49 && (*opponentSlot)->field0008 < 156 ? 1 : 0) * 0x1e + 0x19 +
                            (unsigned int)((*opponentSlot)->field0008 < 0x31) * 0x14)) {
                            buttonPulse[0] = 1;
                            inputY = 1;
                            return;
                        }
                    }
                    if ((distance.forward < 50.0) && (0x3c < field3110)) {
                        if (field3110 <
                            (int)(((*opponentSlot)->field0008 > 49 && (*opponentSlot)->field0008 < 156 ? 1 : 0) * 0x1e + 0x50 +
                            (unsigned int)((*opponentSlot)->field0008 < 0x31) * 0x14)) {
                            buttonPulse[0] = 1;
                            inputY = 0;
                            return;
                        }
                    }
                    if ((distance.forward < 70.0) && (0x82 < field3110)) {
                        if (field3110 <
                            (int)(((*opponentSlot)->field0008 > 49 && (*opponentSlot)->field0008 < 156 ? 1 : 0) * 0x1e + 0x91 +
                            (unsigned int)((*opponentSlot)->field0008 < 0x31) * 0x14)) {
                            buttonPulse[1] = 1;
                            inputY = 1;
                            return;
                        }
                    }
                    if ((distance.forward < 100.0) && (200 < field3110)) {
                        if (field3110 <
                            (int)(((*opponentSlot)->field0008 > 49 && (*opponentSlot)->field0008 < 156 ? 1 : 0) * 0x1e + 0xeb +
                            (unsigned int)((*opponentSlot)->field0008 < 0x31) * 0x14)) {
                            buttonPulse[1] = 1;
                            inputY = 0;
                            return;
                        }
                    }
                    if ((((distance.forward < 120.0) && (distance.forward > 100.0)) &&
                        (300 < field3110)) && (field3110 < 0x136)) {
                        buttonPulse[2] = 1;
                        return;
                    }
                    if (((distance.forward > 80.0) && (field3110 < 0x154)) &&
                        (0x140 < field3110)) {
                        field0262 = 0x1e;
                        return;
                    }
                    if (((distance.forward > 150.0) && (field3110 < 0x172)) &&
                        (0x15e < field3110)) {
                        field0262 = 0x20;
                        return;
                    }
                    if (((field3110 < 400) && (0x1a4 < field3110)) &&
                        (distance.forward > 150.0)) {
                        field0262 = (short)facing;
                        field3114 = 5;
                        return;
                    }
                    if (((field3110 <
                        (int)(((*opponentSlot)->field0008 > 49 && (*opponentSlot)->field0008 < 156 ? 1 : 0) * 100 + 0x1e0 +
                        (unsigned int)((*opponentSlot)->field0008 < 0x31) * 0x14)) &&
                        (0x1c2 < field3110)) && (distance.forward < 100.0)) {
                        field3114 = 6;
                        return;
                    }
                    if (((field3110 <
                        (int)(((*opponentSlot)->field0008 > 49 && (*opponentSlot)->field0008 < 156 ? 1 : 0) * 100 + 0x276 +
                        (unsigned int)((*opponentSlot)->field0008 < 0x31) * 0x14)) &&
                        (600 < field3110)) && (distance.forward < 100.0)) {
                        field3114 = 6;
                        return;
                    }
                    if (((distance.forward < 220.0) && (field3110 < 700)) &&
                        ((0x2c6 < field3110 && (field0118 > 500.0))))
                    {
                        field0262 = 0xc;
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
                        if (((((distance.forward < distance.vertical * 0.5) && (distance.vertical > 50.0)) &&
                            (distance.vertical < 180.0)) &&
                            ((0x28 < field3110 && (field3110 < 0x46)))) &&
                            (meter >= 1000)) {
                            field0262 = (unsigned short)RandomRange(0, 3) + 0x78;
                            return;
                        }
                    }
                    if ((*opponentSlot)->velocityY > 0.0) {
                        if (((distance.forward < 140.0) && (distance.vertical < 110.0)) &&
                            ((distance.vertical > 80.0 && (field3110 < 0x28)))) {
                            buttonPulse[1] = 1;
                            inputY = 0;
                            return;
                        }
                        if (((((distance.forward < distance.vertical * 0.5) && (distance.vertical > 50.0)) &&
                            (distance.vertical < 180.0)) &&
                            ((0x28 < field3110 && (field3110 < 0x46)))) &&
                            (meter >= 1000)) {
                            field0262 = (unsigned short)RandomRange(0, 3) + 0x78;
                            return;
                        }
                        if (((distance.forward < 80.0) && (distance.vertical > 130.0)) &&
                            ((distance.vertical < 160.0 &&
                            ((0x46 < field3110 && (field3110 < 0x50)))))) {
                            field0262 = (unsigned short)RandomRange(0, 3) + 0x14;
                            return;
                        }
                    }
                }
            }
            if ((positionY < 0.0) && (field3114 != 3)) {
                if ((*opponentSlot)->positionY == 0.0) {
                    if ((((distance.forward < 70.0) && (distance.vertical < 60.0)) &&
                        (positionY < (*opponentSlot)->positionY)) &&
                        (field3110 < 200)) {
                        buttonPulse[0] = 1;
                        return;
                    }
                    if (((distance.forward < 50.0) && (distance.vertical < 100.0)) &&
                        (field3110 < 400)) {
                        buttonPulse[1] = 1;
                        return;
                    }
                    if (((distance.forward < 80.0) && (distance.vertical > 40.0)) &&
                        ((distance.vertical < 60.0 &&
                        ((((*opponentSlot)->positionY > positionY &&
                        (400 < field3110)) && (field3110 < 0x26c)))))) {
                        buttonPulse[2] = 1;
                        return;
                    }
                    if ((0x28a < field3110) && (field3110 < 0x294)) {
                        field0262 = (unsigned short)RandomRange(0, 3) + 0x1e;
                        return;
                    }
                }
                if ((*opponentSlot)->positionY < 0.0) {
                    if (((distance.forward < 70.0) && (distance.vertical < 60.0)) &&
                        ((positionY < (*opponentSlot)->positionY &&
                        (field3110 < 200)))) {
                        buttonPulse[0] = 1;
                        return;
                    }
                    if (((distance.forward < 50.0) && (distance.vertical < 100.0)) &&
                        (field3110 < 400)) {
                        buttonPulse[1] = 1;
                        return;
                    }
                    if (((distance.forward < 80.0) && (distance.vertical > 40.0)) &&
                        (((distance.vertical < 60.0 &&
                        (((*opponentSlot)->positionY > positionY &&
                        (400 < field3110)))) && (field3110 < 0x26c)))) {
                        buttonPulse[2] = 1;
                        return;
                    }
                    if ((0x28a < field3110) && (field3110 < 700)) {
                        field0262 = (unsigned short)RandomRange(0, 3) + 0x1e;
                        return;
                    }
                }
            }
        }
        if (field0008 < 50 &&
            (((*opponentSlot)->field0008 > 149 && (*opponentSlot)->field0008 < 156) ||
            ((*opponentSlot)->field0008 > 49 && (*opponentSlot)->field0008 < 59)) &&
            positionY == 0.0 && (float)(unsigned short)RandomRange(0, 100) < 1.0f * field00a8) {
            if (distance.forward < 100.0) { field0262 = (unsigned short)(facing == 1); }
            return;
        }
        if ((unsigned short)RandomRange(0, 1000) < 2) {
            field3114 = 4;
            return;
        }
        if ((unsigned short)RandomRange(0, 100) < 2) {
            if ((float)(unsigned short)RandomRange(0, 100) < 8.0f * field00a8) {
                field3114 = 3;
            } else { field3114 = 0; }
            if (((distance.forward > 240.0) && (positionY == 0.0)) &&
                ( (unsigned short)RandomRange(0, 100) < 2)) {
                inputX = 0;
                inputY = 0xff;
                return;
            }
            if (((distance.forward < 80.0) && (positionY == 0.0)) &&
                ( (unsigned short)RandomRange(0, 100) < 2)) {
                inputX = 0;
                inputY = 0xff;
                return;
            }
            if ((distance.forward < 140.0) && (positionY == 0.0)) {
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
        if (((unsigned short)RandomRange(0, 100) < 0x28) && (distance.forward < 60.0)) {
            if (facing == '\x01') {
                field01a4 = ((unsigned short)RandomRange(0, 200)) + 0x1e;
            }
            else {
                field01a0 = ((unsigned short)RandomRange(0, 200)) + 0x1e;
            }
        }
        if ((unsigned short)RandomRange(0, 100) < 0x50) {
            if (facing == '\x01') {
                field01a0 = ((unsigned short)RandomRange(0, 200)) + 0x1e;
            }
            else {
                field01a4 = ((unsigned short)RandomRange(0, 200)) + 0x1e;
            }
        }
        else if (facing == -1) {
            field01a0 = ((unsigned short)RandomRange(0, 200)) + 0x1e;
        }
        else {
            field01a4 = ((unsigned short)RandomRange(0, 200)) + 0x1e;
        }
    }
    return;
}
