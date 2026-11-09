// Makoto CPU input generation and command selection.
#include "CharacterViews.h"
#include <math.h>

void Character03::Slot05()
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
        25.0f * field00a8 + (positionY < 0.0 ? 1 : 0) * 30 * field00a8 +
        (float)((field3114 == 3) * 400) + (float)((field0008 == 0xaa ? 1 : 0) * 300)) {
        field014e = 0x3c;
    }
    if ((double)(unsigned short)RandomRange(0, 2000) <
        ((double)(field0130 > 0) * 4.0 + 1.0) * 8.0 * field00a8 *
        ((field0008 > 149 && field0008 < 157 ? 1 : 0) * 2 + 1)) {
        field014e = 0x3c;
    }
    if (((float)(unsigned short)RandomRange(0, 1000) < 40.0f * field00a8) && (199 < field0008)) {
        field014e = 0x3c;
    }
    if ((field0170 == 1) && (field3114 == 2)) {
        field014e = 0x1e;
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
            ((*opponentSlot)->field000a < 3)) && ((distance.vertical < 100.0 && (distance.forward < 150.0)))) {
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
            if ((distance.forward < 45.0) &&
                (
                (float)(unsigned short)RandomRange(0, 100) < field00a8 * 2)) {
                buttonPulse[0] = 1;
                inputY = 0;
                return;
            }
            if ((distance.forward < 60.0) &&
                (
                (float)(unsigned short)RandomRange(0, 100) < field00a8 * 2)) {
                buttonPulse[0] = 1;
                inputY = 1;
                return;
            }
        }
        if ((((((*opponentSlot)->field0008 == 0xc9) ||
            ((*opponentSlot)->field0008 == 0xca)) ||
            ((*opponentSlot)->field0008 == 0xcd)) &&
            ((((*opponentSlot)->field0008 < 0xfa &&
            ((*opponentSlot)->positionY == 0.0)) &&
            (((*opponentSlot)->field016c == 0 && ((distance.forward > 60.0 && (distance.forward < 70.0)))
            ))))) &&
            ( (float)(unsigned short)RandomRange(0, 100) < field00a8 * 1.0f)) {
            buttonPulse[1] = 1;
            inputY = 1;
            inputX = 0;
            return;
        }
    }
    if ((field0008 == 0xa8) || (field0008 == 0xa9)) {
        if (distance.forward < 100.0) {
            if (((float)(unsigned short)RandomRange(0, 100) < field00a8 * 5.0f) && (field0118 > 500.0))
            {
                field0262 = 0x14;
                return;
            }
            if (((float)(unsigned short)RandomRange(0, 100) < field00a8 * 3.0f) && (field0118 > 500.0))
            {
                field0262 = 0x16;
                return;
            }
            if (((float)(unsigned short)RandomRange(0, 100) < field00a8 * 2) &&
                (field0118 > 500.0)) {
                field0262 = 0x2a;
                return;
            }
            if ((distance.forward < 60.0) &&
                ( (float)(unsigned short)RandomRange(0, 100) < field00a8 * 1.0f)) {
                buttonPulse[0] = 1;
                inputY = 0;
                return;
            }
            if (((float)(unsigned short)RandomRange(0, 100) < field00a8 * 1.0f) && (field0148 >= 1000)) {
                field0262 = (unsigned short)RandomRange(0, 3) + 0x6e;
                return;
            }
            if (((float)(unsigned short)RandomRange(0, 100) < field00a8 * 3.0f) && (field0148 >= 2000)) {
                field0262 = (unsigned short)RandomRange(0, 2) + 0x79;
                return;
            }
        }
        if ((distance.forward < 150.0) && (distance.forward > 100.0)) {
            if (((float)(unsigned short)RandomRange(0, 100) < field00a8 * 3.0f) && (field0118 > 500.0))
            {
                field0262 = 0x2a;
                return;
            }
            if ((distance.forward < 120.0) &&
                ( (float)(unsigned short)RandomRange(0, 100) < field00a8 * 1.0f)) {
                buttonPulse[0] = 2;
                inputY = 0;
                return;
            }
            if (((float)(unsigned short)RandomRange(0, 100) < field00a8 * 2) &&
                (field0148 >= 2000)) {
                field0262 = (unsigned short)RandomRange(0, 2) + 0x79;
                return;
            }
        }
        if (distance.forward > 150.0) {
            if (((float)(unsigned short)RandomRange(0, 100) < field00a8 * 1.0f) && (field0118 > 500.0))
            {
                field0262 = (unsigned short)RandomRange(0, 2) + 0x28;
                return;
            }
            if ((float)(unsigned short)RandomRange(0, 100) < field00a8 * 1.0f) {
                field0262 = (unsigned short)RandomRange(0, 2) + 0xb;
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
        if (((positionY - (*opponentSlot)->positionY < 0.0) &&
            (-40.0 < positionY - (*opponentSlot)->positionY)) &&
            ((distance.forward < 80.0 &&
            ( (float)(unsigned short)RandomRange(0, 100) < field00a8 * 5.0f)))) {
            buttonPulse[0] = 1;
            return;
        }
        if (((0.0 < positionY - (*opponentSlot)->positionY) &&
            (positionY - (*opponentSlot)->positionY < 50.0)) &&
            ((distance.forward < 100.0 &&
            ( (float)(unsigned short)RandomRange(0, 100) < field00a8 * 5.0f)))) {
            buttonPulse[1] = 1;
            return;
        }
        if ((((positionY - (*opponentSlot)->positionY < -20.0) &&
            (-90.0 < positionY - (*opponentSlot)->positionY)) &&
            (distance.forward < 110.0)) &&
            ( (float)(unsigned short)RandomRange(0, 100) < field00a8 * 5.0f)) {
            buttonPulse[2] = 1;
            inputY = 0;
            return;
        }
        if ((distance.vertical < 100.0) &&
            ( (float)(unsigned short)RandomRange(0, 100) < field00a8 * 1.0f)) {
            field0262 = (unsigned short)RandomRange(0, 2) + 0x6e;
            return;
        }
    }
    if (((((*opponentSlot)->field0008 == 0xa8) ||
        ((*opponentSlot)->field0008 == 0xa9)) ||
        ((*opponentSlot)->field0008 == 0xaa)) &&
        ((((positionY == 0.0 &&
        ( (float)(unsigned short)RandomRange(0, 100) < 15.0f * field00a8)) &&
        (field3114 != 2)) && ((*opponentSlot)->field014c == 0)))) {
        field3110 = (unsigned short)RandomRange(0, 100);
        if (((field3110 < 3) && (field0118 > 500.0)) && (distance.forward < 80.0)) {
            field0262 = 0x14;
            return;
        }
        if (((field3110 < 5) && (field0118 > 500.0)) && (distance.forward < 80.0)) {
            field0262 = 0x16;
            return;
        }
        if ((((field3110 < 10) && (5 < field3110)) && (field0118 > 500.0)
            ) && (distance.forward < 150.0)) {
            field0262 = 0x2a;
            return;
        }
        if (((field3110 < 0x11) && (0xc < field3110)) &&
            ((field0148 >= 1000 && (distance.forward < 100.0)))) {
            field0262 = (unsigned short)RandomRange(0, 3) + 0x78;
            return;
        }
        if (((field3110 < 0x11) && (0xc < field3110)) &&
            ((field0148 >= 1000 && (distance.forward > 90.0)))) {
            field0262 = (unsigned short)RandomRange(0, 3) + 0x6e;
            return;
        }
        if (0x41 < field3110) {
            field3114 = 2;
            return;
        }
    }
    if (((((((*opponentSlot)->field0008 == 0xa8) ||
        ((*opponentSlot)->field0008 == 0xa9)) ||
        ((*opponentSlot)->field0008 == 0xaa)) &&
        ((positionY < 0.0 &&
        ( (float)(unsigned short)RandomRange(0, 100) < 15.0f * field00a8)))) &&
        (field3114 != 2)) && ((*opponentSlot)->field014c == 0)) {
        field3110 = (unsigned short)RandomRange(0, 100);
        if (((field3110 < 0x11) && (0xc < field3110)) &&
            ((field0148 >= 1000 && (distance.forward > 50.0)))) {
            field0262 = (unsigned short)RandomRange(0, 3) + 0x6e;
            return;
        }
        if (0x3c < field3110) {
            field3114 = 2;
            return;
        }
    }
    if ((field0118 > 500.0 || field0120 > 0) &&
        (float)(unsigned short)RandomRange(0, 100) < 8.0f * field00a8 &&
        (*opponentSlot)->field0008 > 149 && (*opponentSlot)->field0008 < 157 &&
        (field0008 == 256 || (field0008 == 232 && (unsigned short)RandomRange(0, 10) == 0) ||
        field0008 == 257 || field0008 == 238)) {
        field0262 = 52; return;
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
        if (((field0008 == 4) || (field0008 == 5)) || (field0008 == 6)) {
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
        field0262 = (unsigned short)(facing == '\x01');
        if (field0008 == 0xa3) {
            field3114 = 0xd;
        }
    }
    else if ((field3114 == 0xd) && (field0008 == 0xa3)) {
        buttonPulse[0] = 1;
        inputY = 1;
        if (field0008 == 0xe6) {
            field3114 = 0;
        }
    }
    else if ((field3114 == 0xe) && (field0008 < 0x32)) {
        field0262 = (unsigned short)(facing == '\x01');
        if (field0008 == 0xa3) {
            field3114 = 0xf;
        }
    }
    else if ((field3114 == 0xf) && (field0008 == 0xa3)) {
        buttonPulse[1] = 1;
        inputY = 1;
        if (field0008 == 0xe7) {
            field3114 = 0;
        }
    }
    else if ((field3114 == 0x10) && (field0008 < 0x32)) {
        field0262 = (unsigned short)(facing == '\x01');
        if (field0008 == 0xa3) {
            field3114 = 0x11;
        }
    }
    else if ((field3114 == 0x11) && (field0008 == 0xa3)) {
        buttonPulse[2] = 1;
        inputY = 1;
        if (field0008 == 0xe8) {
            field3114 = 0;
        }
    }
    else if ((field3114 == 0x14) && (field0008 < 0x32)) {
        buttonPulse[0] = 1;
        inputY = 1;
        if (field0008 == 0xcc) {
            field3114 = 0;
        }
    }
    else {
        if ((((1 < field0168) && (field014a == 0)) &&
            ( (float)(unsigned short)RandomRange(0, 100) < field00a8 * 25.0f))
            && ((field3114 != 1 && (field3114 != 2)))) {
            field3110 = (unsigned short)RandomRange(0, 1000);
            if (field0008 == 200) {
                if (((*opponentSlot)->positionY < 0.0) && (field3110 < 300)) {
                    buttonPulse[1] = 1;
                    inputY = 0;
                    return;
                }
                if (((distance.forward < 45.0) && (0 < field3110)) && (field3110 < 300)) {
                    buttonPulse[0] = 1;
                    inputY = (unsigned short)RandomRange(0, 2);
                    return;
                }
                if (((distance.forward < 80.0) && (0 < field3110)) && (field3110 < 300)) {
                    buttonPulse[1] = 1;
                    inputY = 1;
                    return;
                }
                if (((distance.forward < 70.0) && (300 < field3110)) && (field3110 < 600)) {
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
                if (600 < field3110) {
                    field3114 = 1;
                    if ((unsigned short)RandomRange(0, 3) == 0) {
                        field3114 = 6;
                    }
                    if ((unsigned short)RandomRange(0, 3) == 0) {
                        field3114 = 8;
                    }
                    if ((unsigned short)RandomRange(0, 3) == 0) {
                        field3114 = 0xc;
                    }
                    if ((unsigned short)RandomRange(0, 3) == 0) {
                        field3114 = 0xe;
                    }
                    if (distance.forward < 50.0) {
                        if ((unsigned short)RandomRange(0, 2) == 0) {
                            field3114 = 0x14;
                        }
                    }
                    return;
                }
            }
            if (field0008 == 0xc9) {
                if ((((*opponentSlot)->positionY < 0.0) && (field3110 < 300)) &&
                    (field0168 == 3)) {
                    field0262 = (unsigned short)RandomRange(0, 2) + 0x15;
                    return;
                }
                if ((((*opponentSlot)->positionY < 0.0) && (300 < field3110)) &&
                    (field3110 < 0x226)) {
                    field0262 = (unsigned short)RandomRange(0, 3) + 0x28;
                    return;
                }
                if ((((*opponentSlot)->positionY < 0.0) && (0x226 < field3110))
                    && ((field3110 < 600 && (field0148 >= 1000)))) {
                    field0262 = (unsigned short)RandomRange(0, 3) + 0x78;
                    return;
                }
                if ((((*opponentSlot)->positionY < 0.0) && (600 < field3110)) &&
                    (field3110 < 0x2ee)) {
                    inputX = facing;
                    inputY = 0xff;
                    return;
                }
                if (field3110 < 100) {
                    buttonPulse[2] = 1;
                    inputY = 1;
                    return;
                }
                if (((100 < field3110) && (field3110 < 0x15e)) && (distance.forward < 130.0)) {
                    buttonPulse[1] = 1;
                    inputY = 0;
                    return;
                }
                if ((((*opponentSlot)->positionY < 0.0) && (0x1c2 < field3110))
                    && ((field3110 < 600 && (distance.forward < 70.0)))) {
                    buttonPulse[2] = 1;
                    return;
                }
                if ((600 < field3110) && (field3110 < 0x2ee)) {
                    inputX = facing;
                    inputY = 0xff;
                    return;
                }
                if (0x3d4 < field3110) {
                    field3114 = 4;
                    inputY = 0xff;
                    inputX = (unsigned short)RandomRange(0, 2) + -1;
                    return;
                }
                if (500 < field3110) {
                    field3114 = 1;
                    if ((unsigned short)RandomRange(0, 2) == 0) {
                        field3114 = 6;
                    }
                    if ((unsigned short)RandomRange(0, 2) == 0) {
                        field3114 = 8;
                    }
                    if ((unsigned short)RandomRange(0, 3) == 0) {
                        field3114 = 0xc;
                    }
                    if ((unsigned short)RandomRange(0, 3) == 0) {
                        field3114 = 0xe;
                    }
                    if (distance.forward < 50.0) {
                        if ((unsigned short)RandomRange(0, 2) == 0) {
                            field3114 = 0x14;
                        }
                    }
                    return;
                }
            }
            if (field0008 == 0xca) {
                if (((((*opponentSlot)->positionY < 0.0) && (0x96 < field3110))
                    && (field3110 < 200)) && ((field0148 >= 1000 && (distance.forward < 120.0))))
                {
                    field0262 = (unsigned short)RandomRange(0, 3) + 0x78;
                    return;
                }
                if ((0 < field3110) && (field3110 < 200)) {
                    buttonPulse[2] = 1;
                    inputY = 0;
                    return;
                }
                if ((200 < field3110) && (field3110 < 500)) {
                    buttonPulse[2] = 1;
                    inputY = 1;
                    return;
                }
                if (500 < field3110) {
                    field3114 = 1;
                    if ((unsigned short)RandomRange(0, 2) == 0) {
                        field3114 = 6;
                    }
                    if ((unsigned short)RandomRange(0, 2) == 0) {
                        field3114 = 8;
                    }
                    if ((unsigned short)RandomRange(0, 3) == 0) {
                        field3114 = 0xc;
                    }
                    if ((unsigned short)RandomRange(0, 3) == 0) {
                        field3114 = 0xe;
                    }
                    return;
                }
            }
            if (field0008 == 0xcb) {
                if ((0 < field3110) && (field3110 < 300)) {
                    field0262 = (unsigned short)RandomRange(0, 2) + 0x28;
                    return;
                }
                if ((300 < field3110) && (field3110 < 600)) {
                    field0262 = 10;
                    if (distance.forward > 160.0) {
                        field0262 = 0xb;
                        if ((unsigned short)RandomRange(0, 3) == 0) {
                            field0262 = 0xc;
                        }
                    }
                    return;
                }
                if ((600 < field3110) && (field3110 < 0x28a)) {
                    field0262 = 0x1e;
                    return;
                }
                if (((0x28a < field3110) && (field3110 < 0x29e)) &&
                    (field0148 >= 1000)) {
                    field0262 = 0x65;
                    return;
                }
                if (900 < field3110) {
                    field3114 = 1;
                    return;
                }
            }
            if (field0008 == 0xcc) {
                if (((*opponentSlot)->positionY < 0.0) && (field3110 < 300)) {
                    buttonPulse[1] = 1;
                    inputY = 0;
                    return;
                }
                if (((distance.forward < 45.0) && (0 < field3110)) && (field3110 < 300)) {
                    buttonPulse[0] = 1;
                    inputY = (unsigned short)RandomRange(0, 2);
                    return;
                }
                if (((distance.forward < 90.0) && (0 < field3110)) && (field3110 < 400)) {
                    buttonPulse[1] = 1;
                    inputY = 1;
                    return;
                }
                if (((distance.forward < 100.0) && (300 < field3110)) && (field3110 < 600)) {
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
                if (600 < field3110) {
                    field3114 = 1;
                    if ((unsigned short)RandomRange(0, 3) == 0) {
                        field3114 = 6;
                    }
                    if ((unsigned short)RandomRange(0, 3) == 0) {
                        field3114 = 8;
                    }
                    if ((unsigned short)RandomRange(0, 3) == 0) {
                        field3114 = 0xc;
                    }
                    if ((unsigned short)RandomRange(0, 3) == 0) {
                        field3114 = 0xe;
                    }
                    if (distance.forward < 50.0) {
                        if ((unsigned short)RandomRange(0, 2) == 0) {
                            field3114 = 0x14;
                        }
                    }
                    return;
                }
            }
            if (field0008 == 0xcd) {
                if ((((*opponentSlot)->positionY < 0.0) && (field3110 < 300)) &&
                    (field0168 == 3)) {
                    field0262 = (unsigned short)RandomRange(0, 2) + 0x15;
                    return;
                }
                if ((((*opponentSlot)->positionY < 0.0) && (300 < field3110)) &&
                    (field3110 < 0x226)) {
                    field0262 = (unsigned short)RandomRange(0, 3) + 0x28;
                    return;
                }
                if ((((*opponentSlot)->positionY < 0.0) && (0x226 < field3110))
                    && ((field3110 < 600 && (field0148 >= 1000)))) {
                    field0262 = (unsigned short)RandomRange(0, 3) + 0x78;
                    return;
                }
                if ((((*opponentSlot)->positionY < 0.0) && (600 < field3110)) &&
                    (field3110 < 0x2ee)) {
                    inputX = facing;
                    inputY = 0xff;
                    return;
                }
                if (field3110 < 100) {
                    buttonPulse[2] = 1;
                    inputY = 1;
                    return;
                }
                if (((100 < field3110) && (field3110 < 0x15e)) && (distance.forward < 130.0)) {
                    buttonPulse[1] = 1;
                    inputY = 0;
                    return;
                }
                if ((((*opponentSlot)->positionY < 0.0) && (0x1c2 < field3110))
                    && ((field3110 < 600 && (distance.forward < 70.0)))) {
                    buttonPulse[2] = 1;
                    return;
                }
                if ((600 < field3110) && (field3110 < 0x2ee)) {
                    inputX = facing;
                    inputY = 0xff;
                    return;
                }
                if (0x3d4 < field3110) {
                    field3114 = 4;
                    inputY = 0xff;
                    inputX = (unsigned short)RandomRange(0, 2) + -1;
                    return;
                }
                if (500 < field3110) {
                    field3114 = 1;
                    if ((unsigned short)RandomRange(0, 2) == 0) {
                        field3114 = 6;
                    }
                    if ((unsigned short)RandomRange(0, 2) == 0) {
                        field3114 = 8;
                    }
                    if ((unsigned short)RandomRange(0, 3) == 0) {
                        field3114 = 0xc;
                    }
                    if ((unsigned short)RandomRange(0, 3) == 0) {
                        field3114 = 0xe;
                    }
                    if (distance.forward < 50.0) {
                        if ((unsigned short)RandomRange(0, 2) == 0) {
                            field3114 = 0x14;
                        }
                    }
                    return;
                }
            }
            if (field0008 == 0xce) {
                if ((field3110 > 600 - (field0168 == 3) * 400) &&
                    (field3110 < 0x28a)) {
                    field0262 = 0x1e;
                    return;
                }
                if ((0 < field3110) && (field3110 < 300)) {
                    field0262 = (unsigned short)RandomRange(0, 2) + 0x28;
                    if ((unsigned short)RandomRange(0, 2) == 0) {
                        field3114 = 8;
                    }
                    return;
                }
                if ((300 < field3110) && (field3110 < 600)) {
                    field0262 = 10;
                    if ((unsigned short)RandomRange(0, 2) == 0) {
                        field3114 = 8;
                    }
                    if (distance.forward > 160.0) {
                        field0262 = 0xb;
                        if ((unsigned short)RandomRange(0, 3) == 0) {
                            field0262 = 0xc;
                        }
                    }
                    return;
                }
                if (((0x28a < field3110) && (field3110 < 0x29e)) &&
                    (field0148 >= 1000)) {
                    field0262 = 0x65;
                    return;
                }
                if (900 < field3110) {
                    field3114 = 1;
                    return;
                }
            }
            if (field0008 == 0xcf) {
                if (((*opponentSlot)->positionY < 0.0) && (field3110 < 300)) {
                    buttonPulse[1] = 1;
                    return;
                }
                if ((distance.forward < 60.0) && (field3110 < 400)) {
                    buttonPulse[0] = 1;
                    return;
                }
                if (((distance.forward < 125.0) && (399 < field3110)) && (field3110 < 700)) {
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
                if (((0x14 < field3110) && (field3110 < 0x3c)) &&
                    ((field0168 == 3 && ((*opponentSlot)->positionY < 0.0)))) {
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
                if ((0 < field3110) && (field3110 < 200)) {
                    field0262 = 10;
                    return;
                }
                if (((200 < field3110) && (field3110 < 0xd2)) &&
                    (field0118 > 350.0)) {
                    field0262 = 0x34;
                    return;
                }
                if ((0xdc < field3110) && (field3110 < 300)) {
                    field0262 = 0x1e;
                    return;
                }
                if ((300 < field3110) && (field3110 < 0x154)) {
                    field0262 = 0x29;
                    return;
                }
                if (400 < field3110) {
                    field3114 = 1;
                    if ((unsigned short)RandomRange(0, 2) == 0) {
                        field3114 = 6;
                    }
                    if ((unsigned short)RandomRange(0, 2) == 0) {
                        field3114 = 8;
                    }
                    if ((unsigned short)RandomRange(0, 4) == 0) {
                        field3114 = 0xc;
                    }
                    if ((unsigned short)RandomRange(0, 4) == 0) {
                        field3114 = 0xe;
                    }
                    if (distance.forward < 50.0) {
                        if ((unsigned short)RandomRange(0, 2) == 0) {
                            field3114 = 0x14;
                        }
                    }
                    return;
                }
            }
            if (field0008 == 0xea) {
                if ((0 < field3110) && (field3110 < 200)) {
                    field0262 = 10;
                    return;
                }
                if (((200 < field3110) && (field3110 < 0xd2)) &&
                    (field0118 > 350.0)) {
                    field0262 = 0x34;
                    return;
                }
                if ((0xdc < field3110) && (field3110 < 300)) {
                    field0262 = 0x1e;
                    return;
                }
                if ((300 < field3110) && (field3110 < 0x154)) {
                    field0262 = 0x29;
                    return;
                }
                if (400 < field3110) {
                    field3114 = 1;
                    if ((unsigned short)RandomRange(0, 2) == 0) {
                        field3114 = 6;
                    }
                    if ((unsigned short)RandomRange(0, 2) == 0) {
                        field3114 = 8;
                    }
                    if ((unsigned short)RandomRange(0, 4) == 0) {
                        field3114 = 0xc;
                    }
                    if ((unsigned short)RandomRange(0, 4) == 0) {
                        field3114 = 0xe;
                    }
                    if (distance.forward < 50.0) {
                        if ((unsigned short)RandomRange(0, 2) == 0) {
                            field3114 = 0x14;
                        }
                    }
                    return;
                }
            }
            if (field0008 == 0xeb) {
                if ((0 < field3110) && (field3110 < 200)) {
                    field0262 = 10;
                    return;
                }
                if (((200 < field3110) && (field3110 < 0xd2)) &&
                    (field0118 > 350.0)) {
                    field0262 = 0x34;
                    return;
                }
                if ((0xdc < field3110) && (field3110 < 300)) {
                    field0262 = 0x1e;
                    if ((unsigned short)RandomRange(0, 2) == 0) {
                        field3114 = 8;
                    }
                    return;
                }
                if ((300 < field3110) && (field3110 < 0x154)) {
                    field0262 = 0x29;
                    if ((unsigned short)RandomRange(0, 2) == 0) {
                        field3114 = 8;
                    }
                    return;
                }
                if (900 < field3110) {
                    field3114 = 1;
                }
            }
            if ((field0008 == 0xe9) && (500 < field3110)) {
                field3114 = 1;
                if (distance.forward < 50.0) {
                    field3114 = 0x14;
                }
                return;
            }
        }
        if ((float)(unsigned short)RandomRange(0, 100) < 25.0f * field00a8) {
            field3110 = (unsigned short)RandomRange(0, 1000);
            if (positionY == 0.0) {
                if (((*opponentSlot)->positionY == 0.0) &&
                    ((*opponentSlot)->field0008 != 99)) {
                    if ((distance.forward < 40.0) &&
                        (((*opponentSlot)->positionY == 0.0 && (field3110 < 5)))) {
                        buttonPulse[2] = 1;
                        inputX = -facing;
                        inputY = 0;
                        return;
                    }
                    if (distance.forward < 60.0) {
                        if (field3110 < ((*opponentSlot)->field0008 > 49 && (*opponentSlot)->field0008 < 156 ? 1 : 0) * 0xf + 0x14) {
                            buttonPulse[0] = 1;
                            inputY = 1;
                            return;
                        }
                    }
                    if (distance.forward < 45.0) {
                        if (field3110 < ((*opponentSlot)->field0008 > 49 && (*opponentSlot)->field0008 < 156 ? 1 : 0) * 0xf + 0x14) {
                            buttonPulse[0] = 1;
                            inputY = 0;
                            return;
                        }
                    }
                    if ((distance.forward > 50.0) && (distance.forward < 80.0)) {
                        if ((field3110 < ((*opponentSlot)->field0008 > 49 && (*opponentSlot)->field0008 < 156 ? 1 : 0) * 0xf + 0x41) && (0x28 < field3110)) {
                            buttonPulse[1] = 1;
                            inputY = 1;
                            return;
                        }
                    }
                    if (((double)(0x46 - ((*opponentSlot)->field0008 > 49 && (*opponentSlot)->field0008 < 156 ? 1 : 0) * 0x46) < distance.forward) && (distance.forward < 95.0)) {
                        if ((field3110 < ((*opponentSlot)->field0008 > 49 && (*opponentSlot)->field0008 < 156 ? 1 : 0) * 0x14 + 0x50) && (0x46 < field3110)) {
                            field3114 = 0xc;
                            return;
                        }
                    }
                    if (((double)(0x50 - ((*opponentSlot)->field0008 > 49 && (*opponentSlot)->field0008 < 156 ? 1 : 0) * 0x46) < distance.forward) && (distance.forward < 110.0)) {
                        if ((field3110 < ((*opponentSlot)->field0008 > 49 && (*opponentSlot)->field0008 < 156 ? 1 : 0) * 0xf + 0x80) && (0x78 < field3110)) {
                            field3114 = 8;
                            return;
                        }
                    }
                    if ((((distance.forward < 180.0) && (distance.forward > 150.0)) && (field3110 < 0xaa)) &&
                        (0x96 < field3110)) {
                        field3114 = 0x10;
                        return;
                    }
                    if (((distance.forward < 130.0) && (distance.forward > 100.0)) &&
                        ((field3110 < 0xc3 && (0xaa < field3110)))) {
                        buttonPulse[1] = 1;
                        inputY = 0;
                        return;
                    }
                    if (((double)(0x50 - ((*opponentSlot)->field0008 > 49 && (*opponentSlot)->field0008 < 156 ? 1 : 0) * 0x50) < distance.forward) && (distance.forward < 120.0)) {
                        if ((field3110 < ((*opponentSlot)->field0008 > 49 && (*opponentSlot)->field0008 < 156 ? 1 : 0) * 0x19 + 0xb9) && (0xaa < field3110)) {
                            field3114 = 0xe;
                            return;
                        }
                    }
                    if (((double)(0x5a - ((*opponentSlot)->field0008 > 49 && (*opponentSlot)->field0008 < 156 ? 1 : 0) * 0x5a) < distance.forward) && (distance.forward < 120.0)) {
                        if ((field3110 < ((*opponentSlot)->field0008 > 49 && (*opponentSlot)->field0008 < 156 ? 1 : 0) * 0x19 + 0xe1) && (0xd2 < field3110)) {
                            field3114 = 10;
                            return;
                        }
                    }
                    if ((((distance.forward > 130.0) && (distance.forward < 170.0)) && (field3110 < 0x104)) &&
                        (0xfa < field3110)) {
                        field3114 = 10;
                        return;
                    }
                    if (((distance.forward < 80.0) && (field3110 < 0x113)) &&
                        ((0x104 < field3110 &&
                        ((field0118 > 500.0 &&
                        (199 < (*opponentSlot)->field0008)))))) {
                        field0262 = 0x16;
                        return;
                    }
                    if ((((distance.forward < 80.0) && (field3110 < 0x118)) && (0x113 < field3110)) &&
                        ((field0148 >= 1000 && (199 < (*opponentSlot)->field0008))
                        )) {
                        field0262 = (unsigned short)RandomRange(0, 3) + 0x65;
                        return;
                    }
                    if (((distance.forward > 160.0) && (field3110 < 0x136)) && (300 < field3110)) {
                        field0262 = 0x28;
                        return;
                    }
                    if ((((distance.forward > 100.0) && (distance.forward < 160.0)) && (field3110 < 0x140)) &&
                        (0x136 < field3110)) {
                        field0262 = 0x29;
                        return;
                    }
                    if (((distance.forward > 100.0) && (distance.forward < 160.0)) &&
                        ((field3110 < 0x145 && (0x140 < field3110)))) {
                        field0262 = 0x2a;
                        return;
                    }
                    if (((distance.forward > 100.0) && (distance.forward < 160.0)) &&
                        ((field3110 < 0x154 && (0x14a < field3110)))) {
                        field0262 = 10;
                        return;
                    }
                    if (((distance.forward > 160.0) && (field3110 < 0x168)) && (0x154 < field3110)) {
                        field0262 = 0xb;
                        return;
                    }
                    if (((distance.forward > 160.0) && (field3110 < 0x168)) && (0x154 < field3110)) {
                        field0262 = (unsigned short)RandomRange(0, 2) + 0x1e;
                        return;
                    }
                    if (((field3110 < 800) && (700 < field3110)) &&
                        ((0x31 < (*opponentSlot)->field0008 &&
                        (((*opponentSlot)->field0008 < 0x9c && (distance.forward > 100.0)))))) {
                        field3114 = 5;
                        return;
                    }
                }
                if ((*opponentSlot)->positionY < 0.0) {
                    if ((*opponentSlot)->velocityY < 0.0) {
                        if (((distance.forward < 80.0) && (distance.vertical < 120.0)) && (field3110 < 10)) {
                            inputY = 0xff;
                            inputX = -facing;
                            return;
                        }
                        if (((distance.forward < 90.0) && (distance.vertical < 140.0)) &&
                            (((distance.vertical > 80.0 && (field3110 < 6)) &&
                            ((field0118 > 500.0 || ('\0' < field0120)))))) {
                            field0262 = 0x15;
                            return;
                        }
                    }
                    if ((*opponentSlot)->velocityY > 0.0) {
                        if (((((distance.forward < 90.0) && (distance.vertical < 140.0)) && (distance.vertical > 80.0)) &&
                            (field3110 < 6)) &&
                            ((field0118 > 500.0 || ('\0' < field0120)))) {
                            field0262 = 0x16;
                            return;
                        }
                        if (((distance.forward < 90.0) && (distance.vertical < 140.0)) &&
                            ((distance.vertical > 80.0 && (field3110 < 0xf)))) {
                            field0262 = 0x15;
                            return;
                        }
                        if (((((distance.forward < 120.0) && (distance.forward > 80.0)) && (distance.vertical < 140.0)) &&
                            ((distance.vertical > 80.0 && (field3110 < 0x19)))) &&
                            ((0xf < field3110 &&
                            ((field0118 > 500.0 || ('\0' < field0120)))))) {
                            field0262 = 0x2a;
                            return;
                        }
                        if ((((distance.forward < 160.0) && (distance.forward > 120.0)) && (distance.vertical < 300.0)) &&
                            (((distance.vertical > 160.0 && (field3110 < 0x28)) && (0x1e < field3110)))) {
                            field0262 = 0x28;
                            return;
                        }
                        if (((distance.forward > 130.0) && (distance.forward < 150.0)) &&
                            ((distance.vertical < 150.0 &&
                            (((distance.vertical > 120.0 && (field3110 < 0x6e)) && (0x50 < field3110))))))
                        {
                            buttonPulse[1] = 1;
                            inputY = 0;
                            return;
                        }
                        if (((distance.forward < 70.0) && (field3110 < 0xdc)) &&
                            (((200 < field3110 &&
                            (((*opponentSlot)->positionY < -50.0 && (distance.vertical < 90.0))))
                            && (field0148 >= 2000)))) {
                            field0262 = (unsigned short)RandomRange(0, 2) + 0x79;
                            return;
                        }
                    }
                }
            }
            if ((positionY < 0.0) && (field3114 != 3)) {
                if ((*opponentSlot)->positionY == 0.0) {
                    if (((distance.forward < 80.0) && (distance.vertical < 100.0)) && (field3110 < 100)) {
                        buttonPulse[0] = 1;
                        return;
                    }
                    if ((((distance.forward > 60.0) && (distance.forward < 100.0)) &&
                        ((distance.vertical > 60.0 && ((distance.vertical < 120.0 && (0xb4 < field3110)))))) &&
                        (field3110 < 0xf0)) {
                        buttonPulse[2] = 1;
                        return;
                    }
                    if ((((distance.forward > 150.0) && (0xf0 < field3110)) && (field3110 < 0xf5)) &&
                        (distance.vertical > 80.0)) {
                        field0262 = (unsigned short)RandomRange(0, 3) + 0x6e;
                        return;
                    }
                }
                if ((*opponentSlot)->positionY < 0.0) {
                    if (((distance.forward < 80.0) && (distance.vertical < 100.0)) && (field3110 < 0x14)) {
                        buttonPulse[0] = 1;
                        return;
                    }
                    if ((((distance.forward > 20.0) && (distance.forward < 100.0)) &&
                        ((distance.vertical > 0.0 &&
                        (((distance.vertical < 90.0 &&
                        ((*opponentSlot)->positionY < positionY)) &&
                        (0x14 < field3110)))))) && (field3110 < 0x3c)) {
                        buttonPulse[1] = 1;
                        return;
                    }
                }
            }
        }
        if (field0008 < 50 &&
            (((*opponentSlot)->field0008 > 149 && (*opponentSlot)->field0008 < 156) ||
            ((*opponentSlot)->field0008 > 49 && (*opponentSlot)->field0008 < 59)) &&
            positionY == 0.0 && (float)(unsigned short)RandomRange(0, 100) < 5.0f * field00a8 &&
            distance.forward > 120.0) {
            field0262 = (unsigned short)(facing == 1); return;
        }
        if (field0008 < 50 && (*opponentSlot)->field0008 < 50 &&
            distance.forward > 800.0 && distance.forward < 80.0 &&
            (float)(unsigned short)RandomRange(0, 100) < 3.0f * field00a8 &&
            positionX > 150.0 && positionX < 490.0) {
            field0262 = (unsigned short)(facing != 1); return;
        }
        if ((unsigned short)RandomRange(0, 1000) < 2) {
            field3114 = 4;
            return;
        }
        if ((unsigned short)RandomRange(0, 100) < 2) {
            if ((float)(unsigned short)RandomRange(0, 100) < 8.0f * field00a8) {
                field3114 = 3;
            } else { field3114 = 0; }
            if (((distance.forward > 180.0) && (positionY == 0.0)) &&
                ( (unsigned short)RandomRange(0, 100) < 2)) {
                inputX = 0;
                inputY = 0xff;
                return;
            }
            if ((((distance.forward < 170.0) && (distance.forward > 140.0)) && (positionY == 0.0)
                ) && ((*opponentSlot)->field0008 < 0x32)) {
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
                field01a4 = ((unsigned short)RandomRange(0, 200)) + 0x3c;
            }
            else {
                field01a0 = ((unsigned short)RandomRange(0, 200)) + 0x3c;
            }
        }
        if ((unsigned short)RandomRange(0, 100) < 0x32) {
            if (facing == '\x01') {
                field01a0 = ((unsigned short)RandomRange(0, 200)) + 0x3c;
            }
            else {
                field01a4 = ((unsigned short)RandomRange(0, 200)) + 0x3c;
            }
        }
        else if (facing == -1) {
            field01a0 = ((unsigned short)RandomRange(0, 200)) + 0x3c;
        }
        else {
            field01a4 = ((unsigned short)RandomRange(0, 200)) + 0x3c;
        }
    }
    return;
}
