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
        // Both choices share the opponent-state/grounded/no-hit guard.
        // The original 0x004B3172 branch skips *both* attempts on failure.
        if (((*opponentSlot)->field0008 == 0xc9 ||
              (*opponentSlot)->field0008 == 0xca ||
              (*opponentSlot)->field0008 == 0xcd) &&
            (*opponentSlot)->field0008 < 0xfa &&
            (*opponentSlot)->positionY == 0.0 &&
            (*opponentSlot)->remainingHitCount == 0) {
            if (distance.forward > 40.0 && distance.forward < 80.0 &&
                (float)(unsigned short)RandomRange(0, 100) < field00a8 * 3.0f) {
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
    // Attack-collision follow-up: the original skips this entire randomized
    // decision group when permission, hitstop, or CPU-state gates fail.
    if (attackCollisionResult > 1 && hitstopFrames == 0 &&
        (float)(unsigned short)RandomRange(0, 100) < field00a8 * 25.0f &&
        field3114 != 1 && field3114 != 2) {
        field3110 = (unsigned short)RandomRange(0, 1000);
        if (field0008 == 0xc8) {
            if ((*opponentSlot)->positionY < 0.0 && field3110 < 300) {
                buttonPulse[1] = 1;
                inputY = 0;
                return;
            }
            if (distance.forward < 40.0 && field3110 < 400) {
                buttonPulse[0] = 1;
                inputY = 1;
                return;
            }
            if (distance.forward < 50.0 && field3110 < 400) {
                buttonPulse[0] = 1;
                inputY = 0;
                if (attackCollisionResult == 2 &&
                    (unsigned short)RandomRange(0, 100) < 30) {
                    buttonPulse[2] = 1;
                    inputY = 1;
                }
                return;
            }
            if (distance.forward < 125.0 && field3110 > 399 && field3110 < 700) {
                buttonPulse[1] = 1;
                inputY = 0;
                return;
            }
            if (field3110 > 400 && field3110 < 440 && attackCollisionResult == 2) {
                buttonPulse[1] = 1;
                inputY = 0;
                inputX = facing;
                return;
            }
            if (field3110 > 950) {
                field3114 = 4;
                inputY = -1;
                inputX = (unsigned short)RandomRange(0, 2) - 1;
                return;
            }
            if (field3110 > 699) {
                field3114 = 1;
                if ((unsigned short)RandomRange(0, 1) == 0) field3114 = 6;
                return;
            }
        }
        // Next action branch, 0xC9: preserve the original ordered
        // thresholds, one nested random button, and distinct exit sites.
        if (field0008 == 0xc9) {
            if ((*opponentSlot)->positionY < 0.0 && field3110 < 300 &&
                attackCollisionResult == 3) {
                recognizedCommand = (unsigned short)RandomRange(0, 2) + 0x14;
                return;
            }
            if ((*opponentSlot)->positionY < 0.0 &&
                field3110 > 299 && field3110 < 320) {
                recognizedCommand = 0x1f;
                return;
            }
            if ((*opponentSlot)->positionY < 0.0 &&
                field3110 > 320 && field3110 < 600 &&
                distance.forward < 100.0) {
                buttonPulse[2] = 1;
                return;
            }
            if (field3110 < 200) {
                buttonPulse[2] = 1;
                inputY = 1;
                return;
            }
            if (field3110 > 200 && field3110 < 450 && distance.forward < 90.0) {
                buttonPulse[1] = 1;
                inputY = 0;
                return;
            }
            if ((*opponentSlot)->positionY < 0.0 &&
                field3110 > 450 && field3110 < 700) {
                buttonPulse[2] = 1;
                return;
            }
            if (field3110 > 920) {
                field3114 = 4;
                inputY = -1;
                inputX = (unsigned short)RandomRange(0, 2) - 1;
                return;
            }
            if (field3110 > 700) {
                field3114 = 1;
                if ((unsigned short)RandomRange(0, 1) == 0) {
                    field3114 = 6;
                    if (distance.forward > 110.0) field3114 = 8;
                    return;
                }
            }
        }
        // Action 0xCA: additional input and command priorities.
        if (field0008 == 0xca) {
            if ((*opponentSlot)->positionY < 0.0 && field3110 < 300 &&
                attackCollisionResult == 3) {
                recognizedCommand = (unsigned short)RandomRange(0, 2) + 0x14;
                return;
            }
            if ((*opponentSlot)->positionY < 0.0 &&
                field3110 > 299 && field3110 < 320) {
                recognizedCommand = 0x1f;
                return;
            }
            if ((*opponentSlot)->positionY < 0.0 &&
                field3110 > 320 && field3110 < 600 &&
                distance.forward < 100.0) {
                buttonPulse[2] = 1;
                return;
            }
            if (field3110 < 500 && attackCollisionResult == 3 &&
                distance.forward < 80.0) {
                buttonPulse[2] = 1;
                inputY = 0;
                return;
            }
            if (field3110 > 499 && field3110 < 550) {
                recognizedCommand = ((unsigned short)RandomRange(0, 2) == 0) *
                    2 * (field0118 > 500.0) + 0x0a;
                return;
            }
            if (field3110 > 549 && field3110 < 680) {
                recognizedCommand = (unsigned short)RandomRange(0, 2) + 0x1e;
                return;
            }
            if (field3110 > 950) {
                field3114 = 4;
                inputY = -1;
                inputX = (unsigned short)RandomRange(0, 2) - 1;
                return;
            }
            if (field3110 > 700) {
                field3114 = 1;
                if ((unsigned short)RandomRange(0, 1) == 0) {
                    field3114 = 6;
                    if (distance.forward > 110.0) field3114 = 8;
                    return;
                }
            }
        }
        // Action 0xCB: wider random intervals and meter-based commands.
        if (field0008 == 0xcb) {
            if ((*opponentSlot)->positionY < 0.0 && field3110 < 300 &&
                attackCollisionResult == 3) {
                recognizedCommand = (unsigned short)RandomRange(0, 2) + 0x14;
                return;
            }
            if ((*opponentSlot)->positionY < 0.0 &&
                field3110 > 299 && field3110 < 320) {
                recognizedCommand = 0x1f;
                return;
            }
            if (field3110 > 0 && field3110 < 200) {
                recognizedCommand = ((unsigned short)RandomRange(0, 3) == 0) *
                    2 * (field0118 > 500.0) + 0x0a;
                return;
            }
            if (field3110 > 200 && field3110 < 250 &&
                distance.forward < 90.0 && attackCollisionResult == 3) {
                recognizedCommand = 0x14;
                return;
            }
            if (field3110 > 250 && field3110 < 350 &&
                distance.forward < 120.0 && field0118 > 500.0) {
                recognizedCommand = 0x48;
                return;
            }
            if (field3110 > 350 && field3110 < 400 && field0118 > 500.0) {
                recognizedCommand = 0x34;
                return;
            }
            if (field3110 > 400 && field3110 < 430 &&
                attackCollisionResult == 3 && meter >= 1000 &&
                distance.forward < 90.0) {
                recognizedCommand = (unsigned short)RandomRange(0, 2) + 0x64;
                return;
            }
            if (field3110 > 430 && field3110 < 540) {
                recognizedCommand = (unsigned short)RandomRange(0, 2) + 0x1e;
                return;
            }
            if (field3110 > 540 && field3110 < 570 && meter >= 1000) {
                recognizedCommand = (unsigned short)RandomRange(0, 2) + 0x6e;
                return;
            }
            if (field3110 > 910 && attackCollisionResult == 3) {
                field3114 = 4;
                inputY = -1;
                inputX = (unsigned short)RandomRange(0, 2) - 1;
                return;
            }
            if (field3110 > 649) {
                field3114 = 1;
                return;
            }
        }
        // Action 0xCC: prioritize air response before distance-tier attacks.
        if (field0008 == 0xcc) {
            if ((*opponentSlot)->positionY < 0.0 && field3110 < 300) {
                buttonPulse[1] = 1;
                inputY = 1;
                return;
            }
            if (distance.forward < 40.0 && field3110 < 400) {
                buttonPulse[0] = 1;
                inputY = 1;
                return;
            }
            if (distance.forward < 50.0 && field3110 < 400) {
                buttonPulse[0] = 1;
                inputY = 0;
                if (attackCollisionResult == 2 &&
                    (unsigned short)RandomRange(0, 100) < 20) {
                    buttonPulse[2] = 1;
                    inputY = 1;
                }
                return;
            }
            if (distance.forward < 135.0 && field3110 < 600) {
                buttonPulse[1] = 1;
                inputY = 0;
                return;
            }
            if (field3110 > 950) {
                field3114 = 4;
                inputY = -1;
                inputX = (unsigned short)RandomRange(0, 2) - 1;
                return;
            }
            if (field3110 > 699) {
                field3114 = 1;
                if ((unsigned short)RandomRange(0, 1) == 0) field3114 = 5;
                return;
            }
        }
        // Action 0xCD: a separate grounded/airborne follow-up priority.
        if (field0008 == 0xcd) {
            if ((*opponentSlot)->positionY < 0.0 && field3110 < 300 &&
                attackCollisionResult == 3) {
                recognizedCommand = (unsigned short)RandomRange(0, 2) + 0x14;
                return;
            }
            if ((*opponentSlot)->positionY < 0.0 &&
                field3110 > 299 && field3110 < 320) {
                recognizedCommand = 0x1f;
                return;
            }
            if ((*opponentSlot)->positionY < 0.0 &&
                field3110 > 320 && field3110 < 600 &&
                distance.forward < 100.0) {
                buttonPulse[2] = 1;
                return;
            }
            if (field3110 < 100) {
                buttonPulse[2] = 1;
                inputY = 1;
                return;
            }
            if (field3110 > 100 && field3110 < 300 &&
                distance.forward < 100.0) {
                buttonPulse[1] = 1;
                inputY = 0;
                return;
            }
            if ((*opponentSlot)->positionY < 0.0 &&
                field3110 > 300 && field3110 < 600) {
                buttonPulse[2] = 1;
                return;
            }
            if (field3110 > 900) {
                field3114 = 4;
                inputY = -1;
                inputX = (unsigned short)RandomRange(0, 2) - 1;
                return;
            }
            if (field3110 > 700) {
                field3114 = 1;
                if ((unsigned short)RandomRange(0, 1) == 0) {
                    field3114 = 6;
                    if (distance.forward > 110.0) field3114 = 8;
                }
                return;
            }
        }
        // Action 0xCE follow-up: the original random windows are deliberately
        // disjoint; preserve the Boolean meter factor before command selection.
        if (field0008 == 0xce) {
            if (field3110 > 0 && field3110 < 150) {
                recognizedCommand = ((unsigned short)RandomRange(0, 3) == 0) *
                    2 * (field0118 > 500.0) + 0x0a;
                return;
            }
            if (field3110 > 150 && field3110 < 350 &&
                distance.forward < 90.0 && attackCollisionResult == 3) {
                recognizedCommand = (unsigned short)RandomRange(0, 2) + 0x14;
                return;
            }
            if (field3110 > 350 && field3110 < 400 && field0118 > 500.0) {
                recognizedCommand = 0x34;
                return;
            }
            if (field3110 > 400 && field3110 < 450 &&
                attackCollisionResult == 3 && meter >= 1000 &&
                distance.forward < 90.0) {
                recognizedCommand = (unsigned short)RandomRange(0, 2) + 0x64;
                return;
            }
            if (field3110 > 450 && field3110 < 640) {
                recognizedCommand = (unsigned short)RandomRange(0, 2) + 0x1e;
                return;
            }
            if (field3110 > 640 && field3110 < 700 && meter >= 1000) {
                recognizedCommand = (unsigned short)RandomRange(0, 2) + 0x6e;
                return;
            }
            if (field3110 > 700) {
                field3114 = 1;
                if ((unsigned short)RandomRange(0, 1) == 0) {
                    field3114 = 6;
                    if (distance.forward > 110.0) field3114 = 8;
                }
                return;
            }
        }
        // Action 0xCF: close-range follow-ups without changing vertical
        // input on the first two choices.
        if (field0008 == 0xcf) {
            if ((*opponentSlot)->positionY < 0.0 && field3110 < 300) {
                buttonPulse[1] = 1;
                return;
            }
            if (distance.forward < 60.0 && field3110 < 400) {
                buttonPulse[0] = 1;
                return;
            }
            if (distance.forward < 125.0 &&
                field3110 > 399 && field3110 < 700) {
                buttonPulse[2] = 1;
                inputY = 0;
                return;
            }
            if (field3110 > 699) {
                field3114 = 1;
                if ((unsigned short)RandomRange(0, 4) == 0) field3114 = 3;
                return;
            }
        }
        // Action 0xD0: short hit-confirm windows, an optional meter special,
        // and later movement/CPU-state fallbacks.
        if (field0008 == 0xd0) {
            if (field3110 < 20 && attackCollisionResult == 3 &&
                (*opponentSlot)->positionY < 0.0) {
                recognizedCommand = 0x14;
                return;
            }
            if (field3110 > 20 && field3110 < 60 &&
                attackCollisionResult == 3 &&
                (*opponentSlot)->positionY < 0.0) {
                recognizedCommand = 0x1f;
                return;
            }
            if (field3110 > 60 && field3110 < 80 && meter >= 1000 &&
                (*opponentSlot)->positionY < 0.0) {
                recognizedCommand = (unsigned short)RandomRange(0, 2) + 0x6e;
                return;
            }
            if (field3110 > 80 && field3110 < 300) {
                buttonPulse[2] = 1;
                return;
            }
            if (field3110 > 950) {
                inputX = (unsigned short)RandomRange(0, 2) - 1;
                return;
            }
            if (field3110 > 649) {
                field3114 = 3;
                return;
            }
        }
        // Action 0xD1: related short windows, but no meter branch.
        if (field0008 == 0xd1) {
            if (field3110 < 20 && attackCollisionResult == 3 &&
                (*opponentSlot)->positionY < 0.0) {
                recognizedCommand = 0x14;
                return;
            }
            if (field3110 > 20 && field3110 < 90 &&
                attackCollisionResult == 3 &&
                (*opponentSlot)->positionY < 0.0) {
                recognizedCommand = 0x1f;
                return;
            }
            if (field3110 > 950) {
                inputX = (unsigned short)RandomRange(0, 2) - 1;
                return;
            }
            if (field3110 > 649) {
                field3114 = 3;
                return;
            }
        }
        // Action 0xE7 remains in the collision-confirm priority tree.
        // The last failed/random-miss path falls through into the generic AI.
        if (field0008 == 0xe7) {
            if ((*opponentSlot)->positionY < 0.0 && field3110 < 300 &&
                attackCollisionResult == 3) {
                recognizedCommand = (unsigned short)RandomRange(0, 2) + 0x14;
                return;
            }
            if ((*opponentSlot)->positionY < 0.0 &&
                field3110 > 299 && field3110 < 320) {
                recognizedCommand = 0x1f;
                return;
            }
            if (field3110 > 0 && field3110 < 200) {
                recognizedCommand = ((unsigned short)RandomRange(0, 3) == 0) *
                    2 * (field0118 > 500.0) + 0x0a;
                return;
            }
            if (field3110 > 200 && field3110 < 250 &&
                distance.forward < 90.0 && attackCollisionResult == 3) {
                recognizedCommand = 0x14;
                return;
            }
            if (field3110 > 250 && field3110 < 350 &&
                distance.forward < 120.0 && field0118 > 500.0) {
                recognizedCommand = 0x48;
                return;
            }
            if (field3110 > 350 && field3110 < 400 && field0118 > 500.0) {
                recognizedCommand = 0x34;
                return;
            }
            if (field3110 > 400 && field3110 < 700) {
                recognizedCommand = (unsigned short)RandomRange(0, 2) + 0x1e;
                return;
            }
            if (field3110 > 700 && field3110 < 730 && meter >= 1000) {
                recognizedCommand = (unsigned short)RandomRange(0, 2) + 0x6e;
                return;
            }
            if (field3110 > 649 && (unsigned short)RandomRange(0, 3) == 0) {
                field3114 = 6;
                if (distance.forward > 110.0) field3114 = 8;
            }
        }
    }
    // General-purpose randomized CPU logic after the action-specific trees.
    if ((float)(unsigned short)RandomRange(0, 100) < 25.0f * field00a8) {
        field3110 = (unsigned short)RandomRange(0, 1000);
        if (positionY == 0.0) {
            if ((*opponentSlot)->positionY == 0.0 &&
                (*opponentSlot)->field0008 != 99) {
                if (distance.forward < 40.0 &&
                    (*opponentSlot)->positionY == 0.0 &&
                    field3110 < 5) {
                    buttonPulse[2] = 1;
                    inputX = -facing;
                    inputY = 0;
                    return;
                }
                if (distance.forward < 55.0 && field3110 < 20) {
                    buttonPulse[0] = 1;
                    inputY = 1;
                    return;
                }
                if (distance.forward < 70.0 && field3110 < 30) {
                    buttonPulse[0] = 1;
                    inputY = 0;
                    return;
                }
                if (distance.forward < 100.0 && distance.forward > 70.0 &&
                    field3110 < 15) {
                    buttonPulse[1] = 1;
                    inputY = 1;
                    return;
                }
                if (distance.forward < 120.0 && field3110 < 20) {
                    buttonPulse[1] = 1;
                    inputY = 0;
                    return;
                }
                if (distance.forward > 120.0 && field3110 < 30) {
                    field3114 = 8;
                    return;
                }
                if (distance.forward < 80.0 && field3110 < 80 &&
                    field3110 > 37 &&
                    (*opponentSlot)->field0008 > 49 &&
                    (*opponentSlot)->field0008 < 157) {
                    buttonPulse[2] = 1;
                    inputY = 1;
                    return;
                }
                if (distance.forward < 90.0 && distance.forward > 60.0 &&
                    field3110 < 37) {
                    buttonPulse[2] = 1;
                    inputY = 1;
                    return;
                }
                if (distance.forward < 100.0 && distance.forward > 70.0 &&
                    field3110 < 40) {
                    buttonPulse[2] = 1;
                    inputY = 0;
                    return;
                }
                if (distance.forward < 80.0 && field3110 < 42 &&
                    field3110 > 40) {
                    recognizedCommand = 0x14;
                    return;
                }
                // Preserve the original, apparently unreachable roll window.
                if (field3110 < 42 && field3110 > 50) {
                    recognizedCommand = (short)facing;
                    field3114 = 5;
                    return;
                }
                if ((double)(unsigned short)RandomRange(0, 0x140) <
                        distance.forward - 70.0 &&
                    velocityY > 0.0 && (*opponentSlot)->positionY > positionY &&
                    field3110 > 235 && field3110 < 250) {
                    recognizedCommand = (unsigned short)RandomRange(0, 2) + 0x1e;
                    return;
                }
                if (distance.forward > 180.0 &&
                    field3110 > 250 && field3110 < 252 && meter >= 1000) {
                    recognizedCommand = (unsigned short)RandomRange(0, 2) + 0x6e;
                    return;
                }
            }
        }
    }
    // Remaining priority AI decisions are not reconstructed yet.
}
