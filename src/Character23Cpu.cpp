// Misuzu CPU input generation and command selection.
#include "CharacterViews.h"
#include <math.h>

void Character23::Slot05()
{
    // Both distances are used throughout the original decision owner.
    struct { double forward, vertical; } distance;
    recognizedCommand = 99;
    if (0 < cpuMoveRightFrames) {
        --cpuMoveRightFrames;
    }
    if (0 < cpuMoveLeftFrames) {
        --cpuMoveLeftFrames;
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
        ((double)(throwInvulnerabilityFrames > 0) * 4.0 + 1.0) * 8.0 * field00a8 *
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
        field0008 == 264 && remainingHitCount > 1) { return; }
    if ((field0008 == 0xa8) && ((unsigned short)field000c < 6)) {
        if (((*opponentSlot)->field0008 != 200) &&
            (((((*opponentSlot)->field0008 != 0xcc &&
            ((*opponentSlot)->field0008 < 0xfa)) &&
            ((*opponentSlot)->positionY == 0.0)) &&
            ((*opponentSlot)->remainingHitCount == 0)))) {
            if ((distance.forward < 45.0) &&
                (
                (float)(unsigned short)RandomRange(0, 100) < field00a8 * 2)) {
                buttonPulse[0] = 1;
                inputY = 1;
                return;
            }
            if ((distance.forward < 60.0) &&
                (
                (float)(unsigned short)RandomRange(0, 100) < field00a8 * 1.0f)) {
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
            (((*opponentSlot)->remainingHitCount == 0 &&
            ((distance.forward > 60.0 && (distance.forward < 80.0)))))))) &&
            (
            (float)(unsigned short)RandomRange(0, 100) < field00a8 * 1.0f)) {
            buttonPulse[1] = 1;
            inputY = 1;
            inputX = 0;
            return;
        }
    }
    if ((field0008 == 0xa8) || (field0008 == 0xa9)) {
        if (distance.forward < 100.0) {
            if (((float)(unsigned short)RandomRange(0, 100) < field00a8 * 4.0f) &&
                (field0118 > 500.0)) {
                recognizedCommand = 0x20;
                return;
            }
            if (((float)(unsigned short)RandomRange(0, 100) < field00a8 * 2) &&
                (field0118 > 500.0)) {
                recognizedCommand = 0xc;
                return;
            }
            if ((distance.forward < 60.0) &&
                (
                (float)(unsigned short)RandomRange(0, 100) < field00a8 * 1.0f)) {
                buttonPulse[0] = 1;
                inputY = 0;
                return;
            }
            if (((float)(unsigned short)RandomRange(0, 100) < field00a8 * 1.0f) &&
                (meter == 3000)) {
                recognizedCommand = 0x5c;
                return;
            }
            if ((((float)(unsigned short)RandomRange(0, 100) < field00a8 * 3.0f) && (distance.forward < 80.0))
                && (meter >= 2000)) {
                recognizedCommand = (unsigned short)RandomRange(0, 2) + 0x65;
                return;
            }
        }
        if ((distance.forward < 150.0) && (distance.forward > 100.0)) {
            if (((float)(unsigned short)RandomRange(0, 100) < field00a8 * 3.0f) &&
                (field0118 > 500.0)) {
                recognizedCommand = 0xc;
                return;
            }
            if ((distance.forward < 120.0) &&
                (
                (float)(unsigned short)RandomRange(0, 100) < field00a8 * 1.0f)) {
                buttonPulse[0] = 2;
                inputY = 0;
                return;
            }
            if ((float)(unsigned short)RandomRange(0, 100) < field00a8 * 1.0f) {
                buttonPulse[2] = 1;
                inputY = 1;
                return;
            }
            if ((((float)(unsigned short)RandomRange(0, 100) < field00a8 * 1.0f) &&
                (meter == 3000)) && ((*opponentSlot)->field0008 < 0xdc))
            {
                recognizedCommand = 0x5c;
                return;
            }
        }
        if (distance.forward > 150.0) {
            if (((float)(unsigned short)RandomRange(0, 100) < field00a8 * 1.0f) &&
                (field0118 > 500.0)) {
                recognizedCommand = (unsigned short)RandomRange(0, 2) + 0x1e;
                return;
            }
            if ((float)(unsigned short)RandomRange(0, 100) < field00a8 * 1.0f) {
                recognizedCommand = (unsigned short)RandomRange(0, 2) + 0xb;
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
        if ((((positionY - (*opponentSlot)->positionY <
            0.0) &&
            (-40.0 <
            positionY - (*opponentSlot)->positionY)) &&
            (distance.forward < 80.0)) &&
            (
            (float)(unsigned short)RandomRange(0, 100) < field00a8 * 5.0f)) {
            buttonPulse[0] = 1;
            return;
        }
        if (((-100.0 <
            positionY - (*opponentSlot)->positionY) &&
            (positionY - (*opponentSlot)->positionY < -50.0
            )) && ((distance.forward < 80.0 &&
            (
            (float)(unsigned short)RandomRange(0, 100) < field00a8 * 5.0f)))) {
            buttonPulse[1] = 1;
            return;
        }
        if (((-50.0 <
            positionY - (*opponentSlot)->positionY) &&
            (positionY - (*opponentSlot)->positionY < -50.0
            )) && ((distance.forward < 120.0 &&
            (
            (float)(unsigned short)RandomRange(0, 100) < field00a8 * 5.0f)))) {
            buttonPulse[2] = 1;
            inputY = 0;
            return;
        }
        if (((distance.vertical < 50.0) && (distance.forward < 100.0)) &&
            (
            (float)(unsigned short)RandomRange(0, 100) < field00a8 * 2)) {
            recognizedCommand = (unsigned short)RandomRange(0, 2) + 0x1f;
            return;
        }
    }
    if (((((*opponentSlot)->field0008 == 0xa8) ||
        ((*opponentSlot)->field0008 == 0xa9)) ||
        ((*opponentSlot)->field0008 == 0xaa)) &&
        (((positionY == 0.0 &&
        (
        (float)(unsigned short)RandomRange(0, 100) < 15.0f * field00a8)) &&
        ((field3114 != 2 && ((*opponentSlot)->hitstunFrames == 0)))))) {
        field3110 = (unsigned short)RandomRange(0, 100);
        if ((field3110 < 3) && (field0118 > 500.0)) {
            recognizedCommand = 0x20;
            return;
        }
        if ((field3110 < 5) && (field0118 > 500.0)) {
            recognizedCommand = 0xc;
            return;
        }
        if (((field3110 < 0x11) && (0xc < field3110)) && (meter >= 1000)) {
            recognizedCommand = (unsigned short)RandomRange(0, 3) + 100;
            return;
        }
        if (((field3110 < 0x12) && (0x14 < field3110)) && (meter == 3000)
            ) {
            recognizedCommand = 0x5c;
            return;
        }
        if (0x41 < field3110) {
            field3114 = 2;
            return;
        }
    }
    if (((((*opponentSlot)->field0008 == 0xa8) ||
        ((*opponentSlot)->field0008 == 0xa9)) ||
        ((*opponentSlot)->field0008 == 0xaa)) &&
        ((((positionY < 0.0 &&
        (
        (float)(unsigned short)RandomRange(0, 100) < 15.0f * field00a8)) && (field3114 != 2)) &&
        ((*opponentSlot)->hitstunFrames == 0)))) {
        field3110 = (unsigned short)RandomRange(0, 100);
        if ((field3110 < 2) && (field0118 > 500.0)) {
            recognizedCommand = 0x20;
            return;
        }
        if (0x3a < field3110) {
            field3114 = 2;
            return;
        }
    }
    if ((field0118 > 500.0 || field0120 > 0) &&
        (float)(unsigned short)RandomRange(0, 100) < 8.0f * field00a8 &&
        (*opponentSlot)->field0008 > 149 && (*opponentSlot)->field0008 < 157 &&
        (field0008 == 251 || (field0008 == 232 && (unsigned short)RandomRange(0, 10) == 0) ||
        (field0008 == 250 && (unsigned short)RandomRange(0, 100) < 2) ||
        (field0008 == 235 && (unsigned short)RandomRange(0, 7) == 0))) {
        recognizedCommand = 52;
        return;
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
        inputY = -1;
        inputX = (unsigned short)RandomRange(0, 2) + -1;
        if (((field0008 == 4) || (field0008 == 5)) || (field0008 == 6)
            ) {
            recognizedCommand = (unsigned short)(facing == '\x01');
            if (field0008 == 0xa5) {
                field3114 = 0;
            }
            inputY = 0;
            inputX = 0;
            return;
        }
    }
    if ((field3114 == 5) && (field0008 < 0x32)) {
        recognizedCommand = (unsigned short)(facing == '\x01');
        if (field0008 == 0xa3) {
            field3114 = 0;
        }
    }
    else if ((field3114 == 6) && (field0008 < 0x32)) {
        recognizedCommand = (unsigned short)(facing == '\x01');
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
        recognizedCommand = (unsigned short)(facing == '\x01');
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
        recognizedCommand = (unsigned short)(facing == '\x01');
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
        recognizedCommand = (unsigned short)(facing == '\x01');
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
        recognizedCommand = (unsigned short)(facing == '\x01');
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
        recognizedCommand = (unsigned short)(facing == '\x01');
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
        if ((((1 < attackCollisionResult) && (hitstopFrames == 0)) &&
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
                if (((((*opponentSlot)->positionY < 0.0) &&
                    (distance.forward < 90.0)) && (field3110 < 600)) && (300 < field3110)
                    ) {
                    field3114 = 6;
                    return;
                }
                if (((distance.forward < 80.0) && (0 < field3110)) && (field3110 < 300)) {
                    buttonPulse[1] = 1;
                    inputY = 1;
                    return;
                }
                if (((distance.forward < 70.0) && (300 < field3110)) && (field3110 < 600))
                {
                    buttonPulse[1] = 1;
                    inputY = 0;
                    return;
                }
                if (0x3ca < field3110) {
                    field3114 = 4;
                    inputY = -1;
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
                if ((((*opponentSlot)->positionY < 0.0) &&
                    (field3110 < 300)) && (attackCollisionResult == 3)) {
                    recognizedCommand = (unsigned short)RandomRange(0, 2) + 0x14;
                    return;
                }
                if ((((*opponentSlot)->positionY < 0.0) &&
                    (300 < field3110)) && (field3110 < 0x226)) {
                    recognizedCommand = 0x1f;
                    return;
                }
                if ((((*opponentSlot)->positionY < 0.0) &&
                    (0x226 < field3110)) &&
                    ((field3110 < 600 && (meter >= 1000)))) {
                    recognizedCommand = (unsigned short)RandomRange(0, 3) + 100;
                    return;
                }
                if ((((*opponentSlot)->positionY < 0.0) &&
                    (600 < field3110)) && (field3110 < 0x2ee)) {
                    inputX = facing;
                    inputY = -1;
                    return;
                }
                if (field3110 < 100) {
                    buttonPulse[2] = 1;
                    inputY = 1;
                    return;
                }
                if (((100 < field3110) && (field3110 < 0x15e)) &&
                    (distance.forward < 110.0)) {
                    buttonPulse[1] = 1;
                    inputY = 0;
                    return;
                }
                if ((((*opponentSlot)->positionY < 0.0) &&
                    (0x1c2 < field3110)) &&
                    ((field3110 < 600 && (distance.forward < 80.0)))) {
                    buttonPulse[2] = 1;
                    return;
                }
                if (0x3b6 < field3110) {
                    field3114 = 4;
                    inputY = -1;
                    inputX = (unsigned short)RandomRange(0, 2) + -1;
                    return;
                }
                if (600 < field3110) {
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
                if ((((*opponentSlot)->positionY < 0.0) &&
                    (0 < field3110)) && (field3110 < 0x96)) {
                    recognizedCommand = 0x1f;
                    return;
                }
                if ((((*opponentSlot)->positionY < 0.0) &&
                    (0x96 < field3110)) &&
                    ((field3110 < 200 && (meter >= 1000)))) {
                    recognizedCommand = (unsigned short)RandomRange(0, 3) + 100;
                    return;
                }
                if ((200 < field3110) && (field3110 < 400)) {
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
                if ((((*opponentSlot)->positionY < 0.0) &&
                    (field3110 < 300)) && (attackCollisionResult == 3)) {
                    recognizedCommand = (unsigned short)RandomRange(0, 3) + 0x1e;
                    return;
                }
                if ((0 < field3110) && (field3110 < 300)) {
                    recognizedCommand = 10;
                    return;
                }
                if (((0x15e < field3110) && (field3110 < 300)) &&
                    (field0118 > 350.0)) {
                    recognizedCommand = 0x34;
                    return;
                }
                if ((0x15e < field3110) && (field3110 < 600)) {
                    recognizedCommand = 0x1e;
                    return;
                }
                if (((600 < field3110) && (field3110 < 0x28a)) &&
                    (field0118 > 500.0)) {
                    recognizedCommand = 0x1f;
                    return;
                }
                if (900 < field3110) {
                    field3114 = 1;
                    return;
                }
            }
            if (field0008 == 0xcc) {
                if (((*opponentSlot)->positionY < 0.0) &&
                    (field3110 < 300)) {
                    buttonPulse[1] = 1;
                    inputY = 0;
                    return;
                }
                if ((((*opponentSlot)->positionY < 0.0) &&
                    (distance.forward < 90.0)) && ((field3110 < 600 && (300 < field3110)))
                    ) {
                    field3114 = 6;
                    return;
                }
                if (((distance.forward < 70.0) && (0 < field3110)) && (field3110 < 200)) {
                    buttonPulse[1] = 1;
                    inputY = 0;
                    return;
                }
                if (((distance.forward < 80.0) && (200 < field3110)) && (field3110 < 600))
                {
                    buttonPulse[1] = 1;
                    inputY = 1;
                    return;
                }
                if (0x3ca < field3110) {
                    field3114 = 4;
                    inputY = -1;
                    inputX = (unsigned short)RandomRange(0, 2) + -1;
                    return;
                }
                if (800 < field3110) {
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
            if (field0008 == 0xcd) {
                if ((((*opponentSlot)->positionY < 0.0) &&
                    (300 < field3110)) && (field3110 < 0x226)) {
                    recognizedCommand = 0x1f;
                    return;
                }
                if (((((*opponentSlot)->positionY < 0.0) &&
                    (0x226 < field3110)) && (field3110 < 600)) &&
                    (meter >= 1000)) {
                    recognizedCommand = (unsigned short)RandomRange(0, 3) + 100;
                    return;
                }
                if (field3110 < 100) {
                    buttonPulse[2] = 1;
                    inputY = 1;
                    return;
                }
                if (((100 < field3110) && (field3110 < 0x15e)) &&
                    (distance.forward < 110.0)) {
                    buttonPulse[1] = 1;
                    inputY = 0;
                    return;
                }
                if ((((*opponentSlot)->positionY < 0.0) &&
                    (0x15e < field3110)) &&
                    ((field3110 < 0x226 && (distance.forward < 90.0)))) {
                    buttonPulse[2] = 1;
                    return;
                }
                if (((0x226 < field3110) && (field3110 < 0x276)) && (attackCollisionResult == 2)
                    ) {
                    recognizedCommand = 0x1e;
                    return;
                }
                if (0x3b6 < field3110) {
                    field3114 = 4;
                    inputY = -1;
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
            if (field0008 == 0xce) {
                if ((0 < field3110) && (field3110 < 600)) {
                    recognizedCommand = 10;
                    return;
                }
                if (((0x28a < field3110) && (field3110 < 600)) &&
                    (field0118 > 350.0)) {
                    recognizedCommand = 0x34;
                    return;
                }
                if ((0x28a < field3110) && (field3110 < 800)) {
                    recognizedCommand = 0x1e;
                    return;
                }
                if (((800 < field3110) && (field3110 < 0x352)) &&
                    (field0118 > 500.0)) {
                    recognizedCommand = 0x1f;
                    return;
                }
                if (900 < field3110) {
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
                if (((0x14 < field3110) && (field3110 < 0x3c)) &&
                    ((attackCollisionResult == 3 &&
                    ((*opponentSlot)->positionY < 0.0)))) {
                    recognizedCommand = 10;
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
                if ((field3110 < 200) && (attackCollisionResult == 3)) {
                    recognizedCommand = (unsigned short)RandomRange(0, 2) + 0x1f;
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
            if (field0008 == 0xe7) {
                if ((0 < field3110) && (field3110 < 400)) {
                    recognizedCommand = 10;
                    return;
                }
                if (((0x1c2 < field3110) && (field3110 < 400)) &&
                    (field0118 > 350.0)) {
                    recognizedCommand = 0x34;
                    return;
                }
                if ((0x1c2 < field3110) && (field3110 < 600)) {
                    recognizedCommand = 0x1e;
                    return;
                }
                if (((600 < field3110) && (field3110 < 0x28a)) &&
                    (field0118 > 500.0)) {
                    recognizedCommand = 0x1f;
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
            if (((field0008 == 0xfa) && (600 < field3110)) &&
                (positionY == 0.0)) {
                field3114 = 1;
                if (distance.forward < 50.0) {
                    field3114 = 0x14;
                }
                return;
            }
            if ((field0008 == 0xe9) && (500 < field3110)) {
                field3114 = 1;
                if (distance.forward < 50.0) {
                    field3114 = 0x14;
                }
                return;
            }
            if (field0008 == 0xea) {
                if (((0 < field3110) && (field3110 < 400)) && (attackCollisionResult == 3)) {
                    recognizedCommand = 0x14;
                    return;
                }
                if ((0 < field3110) && (field3110 < 400)) {
                    recognizedCommand = 10;
                    return;
                }
                if (((0x1c2 < field3110) && (field3110 < 400)) &&
                    (field0118 > 350.0)) {
                    recognizedCommand = 0x34;
                    return;
                }
                if ((0x1c2 < field3110) && (field3110 < 600)) {
                    recognizedCommand = 0x1e;
                    return;
                }
                if (((600 < field3110) && (field3110 < 0x28a)) &&
                    (field0118 > 500.0)) {
                    recognizedCommand = 0x1f;
                    return;
                }
                if (700 < field3110) {
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
            if (((field0008 == 0xeb) && (0x1c2 < field3110)) &&
                (field3110 < 600)) {
                recognizedCommand = 0x1e;
                return;
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
                    if (distance.forward < 50.0) {
                        if (field3110 < ((*opponentSlot)->field0008 > 49 && (*opponentSlot)->field0008 < 156 ? 1 : 0) * 0xf + 0xf) {
                            buttonPulse[0] = 1;
                            inputY = 1;
                            return;
                        }
                    }
                    if (distance.forward < 65.0) {
                        if (field3110 < ((*opponentSlot)->field0008 > 49 && (*opponentSlot)->field0008 < 156 ? 1 : 0) * 0xf + 0x14) {
                            buttonPulse[0] = 1;
                            inputY = 0;
                            return;
                        }
                    }
                    if ((distance.forward > 60.0) && (distance.forward < 90.0)) {
                        if ((field3110 < ((*opponentSlot)->field0008 > 49 && (*opponentSlot)->field0008 < 156 ? 1 : 0) * 0xf + 0x23) && (0x1e < field3110)) {
                            buttonPulse[1] = 1;
                            inputY = 1;
                            return;
                        }
                    }
                    if (((double)(0x46 - ((*opponentSlot)->field0008 > 49 && (*opponentSlot)->field0008 < 156 ? 1 : 0) * 0x46) < distance.forward) && (distance.forward < 100.0)) {
                        if ((field3110 < ((*opponentSlot)->field0008 > 49 && (*opponentSlot)->field0008 < 156 ? 1 : 0) * 2 + 0x54) && (0x50 < field3110)) {
                            field3114 = 0xc;
                            return;
                        }
                    }
                    if (((double)(0x46 - ((*opponentSlot)->field0008 > 49 && (*opponentSlot)->field0008 < 156 ? 1 : 0) * 0x46) < distance.forward) && (distance.forward < 120.0)) {
                        if ((field3110 < ((*opponentSlot)->field0008 > 49 && (*opponentSlot)->field0008 < 156 ? 1 : 0) * 0xf + 0x80) && (0x78 < field3110)) {
                            field3114 = 8;
                            return;
                        }
                    }
                    if ((((distance.forward < 150.0) && (distance.forward > 120.0)) &&
                        (field3110 < 0x7e)) && (0x78 < field3110)) {
                        buttonPulse[2] = 1;
                        inputY = 1;
                        return;
                    }
                    if (((distance.forward < 120.0) && (distance.forward > 70.0)) &&
                        ((field3110 < 0x91 && (0x82 < field3110)))) {
                        buttonPulse[2] = 1;
                        inputY = 0;
                        return;
                    }
                    if (((double)(0x50 - ((*opponentSlot)->field0008 > 49 && (*opponentSlot)->field0008 < 156 ? 1 : 0) * 0x50) < distance.forward) && (distance.forward < 130.0)) {
                        if ((field3110 < ((*opponentSlot)->field0008 > 49 && (*opponentSlot)->field0008 < 156 ? 1 : 0) * 0xf + 0x9b) && (0x91 < field3110)) {
                            field3114 = 0xe;
                            return;
                        }
                    }
                    if (((double)(0x5a - ((*opponentSlot)->field0008 > 49 && (*opponentSlot)->field0008 < 156 ? 1 : 0) * 0x5a) < distance.forward) && (distance.forward < 140.0)) {
                        if ((field3110 < ((*opponentSlot)->field0008 > 49 && (*opponentSlot)->field0008 < 156 ? 1 : 0) * 0xf + 0xb4) && (0xa5 < field3110)) {
                            field3114 = 10;
                            return;
                        }
                    }
                    if ((((distance.forward > 110.0) && (distance.forward < 160.0)) &&
                        (field3110 < 0xcd)) && (200 < field3110)) {
                        field3114 = 10;
                        return;
                    }
                    if (((distance.forward < 80.0) && (field3110 < 0xeb)) &&
                        ((0xdc < field3110 &&
                        ((field0118 > 500.0 &&
                        (199 < (*opponentSlot)->field0008)))))) {
                        recognizedCommand = 0x20;
                        return;
                    }
                    if ((((distance.forward < 80.0) && (field3110 < 0xf0)) &&
                        (0xeb < field3110)) &&
                        ((meter >= 2000 &&
                        (199 < (*opponentSlot)->field0008)))) {
                        recognizedCommand = (unsigned short)RandomRange(0, 3) + 0x65;
                        return;
                    }
                    if (((distance.forward < 100.0) && (field3110 < 0xf2)) &&
                        ((0xf0 < field3110 &&
                        ((meter == 3000 &&
                        (199 < (*opponentSlot)->field0008)))))) {
                        recognizedCommand = 0x5c;
                        return;
                    }
                    if ((((distance.forward > 100.0) && (distance.forward < 130.0)) &&
                        (field3110 < 0x136)) && (300 < field3110)) {
                        recognizedCommand = 10;
                        return;
                    }
                    if (((distance.forward > 130.0) && (distance.forward < 180.0)) &&
                        ((field3110 < 0x13b && (0x136 < field3110)))) {
                        recognizedCommand = 0xb;
                        return;
                    }
                    if (((distance.forward > 90.0) && (distance.forward < 140.0)) &&
                        ((field3110 < 0x14a && (0x140 < field3110)))) {
                        recognizedCommand = 0x1e;
                        return;
                    }
                    if ((((distance.forward > 90.0) && (distance.forward < 140.0)) &&
                        (field3110 < 0x154)) &&
                        ((0x14a < field3110 && (field0118 > 500.0))))
                    {
                        recognizedCommand = 0x1f;
                        return;
                    }
                    if (((field3110 < 0x2ee) && (700 < field3110)) &&
                        ((0x31 < (*opponentSlot)->field0008 &&
                        (((*opponentSlot)->field0008 < 0x9c && (distance.forward > 100.0)))
                        ))) {
                        field3114 = 5;
                        return;
                    }
                }
                if ((*opponentSlot)->positionY < 0.0) {
                    if (((((*opponentSlot)->velocityY < 0.0) &&
                        (distance.forward < 80.0)) && (distance.vertical < 120.0)) &&
                        (field3110 < 10)) {
                        inputY = -1;
                        inputX = -facing;
                        return;
                    }
                    if ((*opponentSlot)->velocityY > 0.0) {
                        if (((distance.forward < 90.0) && (distance.vertical < 140.0)) &&
                            (((distance.vertical > 80.0 && (field3110 < 6)) &&
                            ((field0118 > 500.0 ||
                            ('\0' < field0120)))))) {
                            recognizedCommand = 0x16;
                            return;
                        }
                        if ((((distance.forward < 80.0) && (distance.vertical < 140.0)) &&
                            (distance.vertical > 100.0)) &&
                            ((field3110 < 0x2d && (10 < field3110)))) {
                            buttonPulse[1] = 1;
                            inputY = 0;
                            return;
                        }
                        if (((distance.forward < 90.0) && (distance.vertical < 170.0)) &&
                            ((distance.vertical > 150.0 &&
                            ((field3110 < 0x50 && (0x2d < field3110)))))) {
                            buttonPulse[2] = 1;
                            inputY = 0;
                            return;
                        }
                        if ((((distance.forward > 120.0) && (distance.forward < 140.0)) &&
                            (distance.vertical < 150.0)) &&
                            (((distance.vertical > 120.0 && (field3110 < 0x6e)) &&
                            (0x50 < field3110)))) {
                            buttonPulse[1] = 1;
                            inputY = 0;
                            return;
                        }
                        if (((distance.forward < 70.0) && (field3110 < 0xd2)) &&
                            ((200 < field3110 &&
                            ((((*opponentSlot)->positionY < -50.0 &&
                            (distance.vertical < 90.0)) && (meter >= 2000)))))) {
                            recognizedCommand = (unsigned short)RandomRange(0, 2) + 0x65;
                            return;
                        }
                        if ((((distance.forward < 100.0) && (field3110 < 0x12e)) &&
                            ((300 < field3110 &&
                            (((*opponentSlot)->positionY < -50.0 &&
                            (distance.vertical < 100.0)))))) && (meter == 3000)) {
                            recognizedCommand = 0x5c;
                            return;
                        }
                    }
                }
            }
            if ((positionY < 0.0) && (field3114 != 3)) {
                if ((*opponentSlot)->positionY == 0.0) {
                    if (((distance.forward < 80.0) && (distance.vertical < 100.0)) &&
                        (field3110 < 100)) {
                        buttonPulse[0] = 1;
                        return;
                    }
                    if ((((distance.forward < 80.0) && (distance.vertical > 90.0)) &&
                        ((distance.vertical < 120.0 &&
                        (((*opponentSlot)->positionY < positionY &&
                        (100 < field3110)))))) && (field3110 < 0xb4)) {
                        buttonPulse[1] = 1;
                        return;
                    }
                    if (((((distance.forward > 80.0) && (distance.forward < 110.0)) &&
                        (distance.vertical > 0.0)) &&
                        ((distance.vertical < 70.0 && (0xb4 < field3110)))) &&
                        (field3110 < 0xf0)) {
                        buttonPulse[2] = 1;
                        return;
                    }
                    if (((distance.forward < 80.0) && (0xf0 < field3110)) &&
                        ((field3110 < 0xf2 && (distance.vertical > 80.0)))) {
                        recognizedCommand = (unsigned short)RandomRange(0, 3) + 0x6e;
                        return;
                    }
                }
                if ((*opponentSlot)->positionY < 0.0) {
                    if (((distance.forward < 80.0) && (distance.vertical < 100.0)) &&
                        (field3110 < 0x14)) {
                        buttonPulse[0] = 1;
                        return;
                    }
                    if ((((distance.forward > 20.0) && (distance.forward < 90.0)) &&
                        ((distance.vertical > 90.0 &&
                        ((distance.vertical < 120.0 &&
                        ((*opponentSlot)->positionY < positionY))))
                        )) && ((0x14 < field3110 && (field3110 < 0x28)))) {
                        buttonPulse[1] = 1;
                        return;
                    }
                    if (((((distance.forward > 80.0) && (distance.forward < 110.0)) &&
                        (distance.vertical > 0.0)) &&
                        ((distance.vertical < 50.0 && (0x28 < field3110)))) &&
                        (field3110 < 0x32)) {
                        buttonPulse[2] = 1;
                        return;
                    }
                }
            }
        }
        if (field0008 < 50 &&
            (((*opponentSlot)->field0008 > 149 && (*opponentSlot)->field0008 < 156) ||
            ((*opponentSlot)->field0008 > 49 && (*opponentSlot)->field0008 < 59)) &&
            positionY == 0.0 && (float)(unsigned short)RandomRange(0, 100) < 4.0f * field00a8 &&
            distance.forward > 120.0) {
            recognizedCommand = (unsigned short)(facing == 1);
            return;
        }
        if (field0008 < 50 && (*opponentSlot)->field0008 < 50 &&
            distance.forward > 800.0 && distance.forward < 120.0 &&
            (float)(unsigned short)RandomRange(0, 100) < 2.0f * field00a8 &&
            positionX > 150.0 && positionX < 490.0) {
            recognizedCommand = (unsigned short)(facing != 1);
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
            if (((distance.forward > 180.0) && (positionY == 0.0))
                && ( (unsigned short)RandomRange(0, 100) < 2)) {
                inputX = 0;
                inputY = -1;
                return;
            }
            if (((distance.forward < 170.0) && (distance.forward > 140.0)) &&
                ((positionY == 0.0 &&
                ((*opponentSlot)->field0008 < 0x32)))) {
                inputX = facing;
                inputY = -1;
                return;
            }
        }
        if (cpuMoveRightFrames > 0) {
            if ((CollisionSide() != '\0') && (0xf < cpuMoveRightFrames)) {
                cpuMoveRightFrames = 0xf;
            }
            inputX = 1;
            return;
        }
        if (cpuMoveLeftFrames > 0) {
            if ((CollisionSide() != '\0') && (0xf < cpuMoveLeftFrames)) {
                cpuMoveLeftFrames = 0xf;
            }
            inputX = -1;
            return;
        }
        if (((unsigned short)RandomRange(0, 100) < 0x32) && (distance.forward < 120.0)) {
            if (facing == '\x01') {
                cpuMoveLeftFrames = (unsigned short)RandomRange(0, 200) + 0x3c;
            }
            else {
                cpuMoveRightFrames = (unsigned short)RandomRange(0, 200) + 0x3c;
            }
        }
        if ((unsigned short)RandomRange(0, 100) < 0x32) {
            if (facing == '\x01') {
                cpuMoveRightFrames = (unsigned short)RandomRange(0, 200) + 0x3c;
            }
            else {
                cpuMoveLeftFrames = (unsigned short)RandomRange(0, 200) + 0x3c;
            }
        }
        else if (facing == -1) {
            cpuMoveRightFrames = (unsigned short)RandomRange(0, 200) + 0x3c;
        }
        else {
            cpuMoveLeftFrames = (unsigned short)RandomRange(0, 200) + 0x3c;
        }
    }
    return;
}
