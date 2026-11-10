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
        // Both choices share the opponent-state/grounded/no-hit guard.
        // The original 0x004B3172 branch skips *both* attempts on failure.
        if (((*opponentSlot)->field0008 == 0xc9 ||
              (*opponentSlot)->field0008 == 0xca ||
              (*opponentSlot)->field0008 == 0xcd) &&
            (*opponentSlot)->field0008 < 0xfa &&
            (*opponentSlot)->positionY == 0.0 &&
            (*opponentSlot)->remainingHitCount == 0) {
            if (distance.forward > 60.0 && distance.forward < 80.0 &&
                (float)(unsigned short)RandomRange(0, 100) < field00a8 * 1.0f) {
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
        if (distance.forward < 160.0) {
            if ((float)(unsigned short)RandomRange(0, 100) < field00a8 * 3.0f &&
                field0118 > 500.0) {
                recognizedCommand = 0x0c;
                return;
            }
        }
        if (distance.forward < 220.0 && distance.forward > 160.0) {
            if ((float)(unsigned short)RandomRange(0, 100) < field00a8 * 1.0f) {
                recognizedCommand = (unsigned short)RandomRange(0, 2) + 0x46;
                return;
            }
        }
        if (distance.forward > 220.0) {
            if ((float)(unsigned short)RandomRange(0, 100) < field00a8 * 1.0f &&
                field0118 > 500.0) {
                recognizedCommand = (unsigned short)RandomRange(0, 2) + 0x0a;
                return;
            }
        }
    }
    // Opening aerial-state priority logic (original 0x004B35F2 onward).
    // Preserve repeated signed height differences, float multiplications and
    // individual random checks rather than precomputing a shared comparison.
    if (field0008 == 0xaa && (unsigned short)field000a == 1 &&
        (unsigned short)field000c == 0) {
        if ((float)(unsigned short)RandomRange(0, 100) < field00a8 * 5.0f) {
            field3114 = 3;
            return;
        }
        if (positionY - (*opponentSlot)->positionY < 0.0 &&
            positionY - (*opponentSlot)->positionY > -40.0 &&
            distance.forward < 80.0 &&
            (float)(unsigned short)RandomRange(0, 100) < field00a8 * 5.0f) {
            buttonPulse[0] = 1;
            return;
        }
        if (positionY - (*opponentSlot)->positionY > -30.0 &&
            positionY - (*opponentSlot)->positionY < 0.0 &&
            distance.forward < 100.0 &&
            (float)(unsigned short)RandomRange(0, 100) < field00a8 * 5.0f) {
            buttonPulse[1] = 1;
            return;
        }
        if (positionY - (*opponentSlot)->positionY > -50.0 &&
            positionY - (*opponentSlot)->positionY < 50.0 &&
            distance.vertical < 60.0 && distance.forward < 120.0 &&
            (float)(unsigned short)RandomRange(0, 100) < field00a8 * 5.0f) {
            buttonPulse[2] = 1;
            inputY = 0;
            return;
        }
        if (distance.vertical < 50.0 && distance.forward < 100.0 &&
            (float)(unsigned short)RandomRange(0, 100) < field00a8 * 2.0f) {
            recognizedCommand = 0x16;
            return;
        }
    }
    // Opponent aerial-state command selection, original 0x004B3891 onward.
    if (((*opponentSlot)->field0008 == 0xa8 ||
         (*opponentSlot)->field0008 == 0xa9 ||
         (*opponentSlot)->field0008 == 0xaa) &&
        positionY == 0.0 &&
        (float)(unsigned short)RandomRange(0, 100) < 15.0f * field00a8 &&
        field3114 != 2 && (*opponentSlot)->hitstunFrames == 0) {
        field3110 = (unsigned short)RandomRange(0, 100);
        if (field3110 < 3 && field0118 > 500.0) {
            recognizedCommand = 0x48;
            return;
        }
        if (field3110 < 7 && field0118 > 500.0) {
            recognizedCommand = 0x0c;
            return;
        }
        if (field3110 < 10 && field0118 > 500.0) {
            recognizedCommand = 0x14;
            return;
        }
        if (field3110 < 13 && field0118 > 500.0) {
            recognizedCommand = 0x16;
            return;
        }
        if (field3110 < 17 && field3110 > 12 && meter >= 2000) {
            recognizedCommand = (unsigned short)RandomRange(0, 1) + 0x65;
            return;
        }
    }
    // While airborne, the same opponent action states can prompt a change
    // of CPU state or a close-range 0x16 command (0x004B3A75 onward).
    if (((*opponentSlot)->field0008 == 0xa8 ||
         (*opponentSlot)->field0008 == 0xa9 ||
         (*opponentSlot)->field0008 == 0xaa) &&
        positionY < 0.0 &&
        (float)(unsigned short)RandomRange(0, 100) < 15.0f * field00a8 &&
        field3114 != 2 && (*opponentSlot)->hitstunFrames == 0) {
        field3110 = (unsigned short)RandomRange(0, 100);
        if (field3110 < 20) {
            field3114 = 2;
            return;
        }
        if (distance.forward < 100.0 && field3110 < 22) {
            recognizedCommand = 0x16;
            return;
        }
    }
    // Meter/air-combo special command when the opponent is in 150..156.
    if ((field0118 > 500.0 || field0120 > 0) &&
        (float)(unsigned short)RandomRange(0, 100) < 8.0f * field00a8 &&
        (*opponentSlot)->field0008 > 0x95 &&
        (*opponentSlot)->field0008 < 0x9d &&
        (field0008 == 0xfa || field0008 == 0xfb || field0008 == 0xfc ||
         field0008 == 0x10e || field0008 == 0x10f || field0008 == 0x110)) {
        recognizedCommand = 0x34;
        return;
    }
    // CPU state recovery and state-4 steering (0x004B3C74 onward).
    if (field3114 > 0 && field0008 > 49 && field0008 < 158)
        field3114 = 0;
    if (field3114 == 1 && field0008 < 200)
        field3114 = 0;
    if (field3114 == 2 && attackWasGuarded != 1) {
        field3114 = 0;
        return;
    }
    if (field3114 == 4) {
        inputY = -1;
        inputX = (unsigned short)RandomRange(0, 2) - 1;
        if (field0008 == 4 || field0008 == 5 || field0008 == 6) {
            recognizedCommand = facing == 1;
            if (field0008 == 0xa5) field3114 = 0;
            inputY = 0;
            inputX = 0;
            return;
        }
    }
    // State 5..11 direction commands and attack pulses.  These state
    // tests are intentionally kept separate, matching the original priority.
    if (field3114 == 5 && field0008 < 50) {
        recognizedCommand = facing == 1;
        if (field0008 == 0xa3) field3114 = 0;
        return;
    }
    if (field3114 == 6 && field0008 < 50) {
        recognizedCommand = facing == 1;
        if (field0008 == 0xa3) field3114 = 7;
        return;
    }
    if (field3114 == 7 && field0008 == 0xa3) {
        buttonPulse[0] = 1;
        if (field0008 == 0xe6) field3114 = 0;
        return;
    }
    if (field3114 == 8 && field0008 < 50) {
        recognizedCommand = facing == 1;
        if (field0008 == 0xa3) field3114 = 9;
        return;
    }
    if (field3114 == 9 && field0008 == 0xa3) {
        buttonPulse[1] = 1;
        if (field0008 == 0xe7) field3114 = 0;
        return;
    }
    if (field3114 == 10 && field0008 < 50) {
        recognizedCommand = facing == 1;
        if (field0008 == 0xa3) field3114 = 11;
        return;
    }
    if (field3114 == 11 && field0008 == 0xa3) {
        buttonPulse[2] = 1;
        if (field0008 == 0xe8) field3114 = 0;
        return;
    }
    // Remaining priority AI decisions are not reconstructed yet.
}
