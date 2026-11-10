// Nagamori Slot05: verified opening CPU-decision sequence, partial original C++.
// Target 0x004B2AC0; remaining original AI branches are still open.
#include "../../src/CharacterViews.h"
#include <math.h>

void Character06::Slot05()
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
                (float)(unsigned short)RandomRange(0, 100) < field00a8 * 3.0f)) {
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
        if (distance.forward > 60.0 && distance.forward < 120.0 &&
            (float)(unsigned short)RandomRange(0, 100) < field00a8 * 3.0f) {
            buttonPulse[0] = 3;
            inputY = 1;
            return;
        }
    }
    if (field0008 == 0xa8 || field0008 == 0xa9) {
        if (distance.forward < 100.0) {
            if ((float)(unsigned short)RandomRange(0, 100) < field00a8 * 3.0f &&
                field0118 > 500.0) {
                recognizedCommand = 0x0c;
                return;
            }
            if ((float)(unsigned short)RandomRange(0, 100) <
                field00a8 * 3.0f + (float)((field0118 > 500.0 ? 1 : 0) << 1)) {
                recognizedCommand = 0x48;
                return;
            }
            if ((float)(unsigned short)RandomRange(0, 100) <
                field00a8 * 3.0f + (float)((field0118 > 500.0 ? 1 : 0) << 1)) {
                recognizedCommand = ((unsigned short)RandomRange(0, 1) == 1) * 2 + 0x14;
                return;
            }
            if ((float)(unsigned short)RandomRange(0, 100) < field00a8 * 3.0f &&
                distance.forward < 60.0 && meter >= 2000) {
                recognizedCommand = 0x65;
                return;
            }
            if ((float)(unsigned short)RandomRange(0, 100) < field00a8 * 3.0f &&
                distance.forward < 150.0 && meter == 3000) {
                recognizedCommand = 0x66;
                return;
            }
        }
    }
    // Remaining priority AI decisions are not reconstructed yet.
}
