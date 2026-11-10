// Nayuki Character10::Slot05 complete naturally reconstructed CPU AI owner.
// Original [0x004654A0,0x0046886B): 13,259 bytes, original shared return.
#include "CharacterViews.h"
#include <math.h>

void Character10::Slot05()
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
            if ((distance.forward < 60.0) &&
                (
                (float)(unsigned short)RandomRange(0, 100) < field00a8 * 3.0f)) {
                buttonPulse[0] = 1;
                inputY = 1;
                return;
            }
        }
        // Shared opponent collision-result follow-up. Only the
        // Nayuki's original 40..80 hit-confirm window follows the
        // independent grounded A8 reaction; keep the call order.
        if (((*opponentSlot)->field0008 == 0xc9 ||
              (*opponentSlot)->field0008 == 0xca ||
              (*opponentSlot)->field0008 == 0xcd) &&
            (*opponentSlot)->field0008 < 0xfa &&
            (*opponentSlot)->positionY == 0.0 &&
            (*opponentSlot)->remainingHitCount == 0) {
            if (distance.forward > 40.0 && distance.forward < 80.0 &&
                (float)(unsigned short)RandomRange(0, 100) < field00a8 * 2.0f) {
                buttonPulse[1] = 1;
                inputY = 0;
                return;
            }
        }
    }
    // Nayuki-specific A8/A9 graded meter and special-command decisions.
    if (field0008 == 0xa8 || field0008 == 0xa9) {
        if (distance.forward < 100.0) {
            if ((float)(unsigned short)RandomRange(0, 100) < field00a8 * 3.0f &&
                field0118 > 500.0) {
                recognizedCommand = 0x48;
                return;
            }
            if ((float)(unsigned short)RandomRange(0, 100) < field00a8 * 3.0f &&
                field0118 > 500.0) {
                recognizedCommand = 0x16;
                return;
            }
            if ((float)(unsigned short)RandomRange(0, 100) < field00a8 * 2.0f &&
                field0118 > 500.0) {
                recognizedCommand = 0x0c;
                return;
            }
            if ((float)(unsigned short)RandomRange(0, 100) < field00a8 * 1.0f &&
                meter == 3000) {
                recognizedCommand = 0x61;
                return;
            }
        }
        if (distance.forward < 220.0) {
            if ((float)(unsigned short)RandomRange(0, 100) < field00a8 * 2.0f &&
                field0118 > 500.0) {
                recognizedCommand = 0x48;
                return;
            }
            if ((float)(unsigned short)RandomRange(0, 100) < field00a8 * 2.0f &&
                field0118 > 500.0) {
                recognizedCommand = 0x0c;
                return;
            }
        }
    }
    // Nayuki AA aerial state: two distance-limited follow-up buttons.
    if (field0008 == 0xaa && (unsigned short)field000a == 1 &&
        (unsigned short)field000c == 0) {
        if ((float)(unsigned short)RandomRange(0, 100) < field00a8 * 5.0f) {
            field3114 = 3;
            return;
        }
        if (positionY - (*opponentSlot)->positionY > -40.0 &&
            positionY - (*opponentSlot)->positionY < 40.0 &&
            distance.forward < 60.0 &&
            (float)(unsigned short)RandomRange(0, 100) < field00a8 * 5.0f) {
            buttonPulse[0] = 1;
            return;
        }
        if (distance.vertical < 50.0 && distance.forward < 50.0 &&
            (float)(unsigned short)RandomRange(0, 100) < field00a8 * 5.0f) {
            buttonPulse[1] = 1;
            return;
        }
        if (distance.vertical < 50.0 && distance.forward < 130.0 &&
            (float)(unsigned short)RandomRange(0, 100) < field00a8 * 5.0f) {
            buttonPulse[2] = 1;
            inputY = 0;
            return;
        }
    }
    // Grounded reaction to an opponent entering a long attack action.
    if (((*opponentSlot)->field0008 == 0xa8 ||
         (*opponentSlot)->field0008 == 0xa9 ||
         (*opponentSlot)->field0008 == 0xaa) &&
        positionY == 0.0 &&
        (float)(unsigned short)RandomRange(0, 100) < 15.0f * field00a8 &&
        field3114 != 2 && (*opponentSlot)->hitstunFrames == 0) {
        field3110 = (unsigned short)RandomRange(0, 100);
        if (field3110 < 4 && field0118 > 500.0) {
            recognizedCommand = 0x48;
            return;
        }
        if (field3110 < 10 && field0118 > 500.0) {
            recognizedCommand = 0x16;
            return;
        }
        if (field3110 < 13 && field0118 > 500.0) {
            recognizedCommand = 0x0c;
            return;
        }
        if (field3110 < 17 && field3110 > 12 && meter >= 1000) {
            recognizedCommand = (unsigned short)RandomRange(0, 2) * 0x6e;
            return;
        }
        // This contradictory window is present in the original native tree.
        if (field3110 < 16 && field3110 > 18 && meter == 3000) {
            recognizedCommand = 0x61;
            return;
        }
    }
    // Nayuki aerial reaction to opponent A8/A9/AA state.
    if (((*opponentSlot)->field0008 == 0xa8 ||
         (*opponentSlot)->field0008 == 0xa9 ||
         (*opponentSlot)->field0008 == 0xaa) &&
        positionY < 0.0 &&
        (float)(unsigned short)RandomRange(0, 100) < 15.0f * field00a8 &&
        field3114 != 2 && (*opponentSlot)->hitstunFrames == 0) {
        field3110 = (unsigned short)RandomRange(0, 100);
        if (field3110 < 60) {
            field3114 = 2;
            return;
        }
    }
    // Special response when an opponent begins a 150-156 airborne sequence.
    if ((field0118 > 500.0 || field0120 > 0) &&
        (float)(unsigned short)RandomRange(0, 100) < 8.0f * field00a8 &&
        (*opponentSlot)->field0008 > 0x95 &&
        (*opponentSlot)->field0008 < 0x9d &&
        (field0008 == 0x104 || field0008 == 0x105 ||
         field0008 == 0x106 || field0008 == 0x105 ||
         field0008 == 0x108 || field0008 == 0x109)) {
        recognizedCommand = 0x34;
        return;
    }
    // Nayuki dash follow-up pulse when A5/A6 movement is active.
    if (field0008 == 0xa5 || field0008 == 0xa6)
        buttonPulse[0] = 1;
    // CPU state recovery, state 4 steering and state 5/6/7 transitions.
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
        if ((field0008 == 4 || field0008 == 5 || field0008 == 6) &&
            (positionY < -60.0 || field3148 > 6)) {
            recognizedCommand = facing == 1;
            if (field0008 == 0xa5)
                field3114 = 0;
            inputY = 0;
            inputX = 0;
            return;
        }
    }
    if (field3114 == 5 && field0008 < 50) {
        field3114 = 6;
        return;
    }
    if (field3114 == 6 && field0008 == 9) {
        if (field0008 == 0xd0)
            field3114 = 0;
        buttonPulse[1] = 1;
        return;
    }
    if (field3114 == 7 && field0008 < 50) {
        field3114 = 8;
        return;
    }
    if (field3114 == 8 && field0008 == 9) {
        if (field0008 == 0xcf)
            field3114 = 0;
        buttonPulse[0] = 1;
        return;
    }
    if (field3114 == 9 && field0008 < 50) {
        inputY = 1;
        buttonPulse[2] = 1;
        if (field0008 == 0xce)
            field3114 = 0;
        return;
    }
    if (field3114 == 10 && field0008 < 50) {
        inputY = 0;
        buttonPulse[2] = 1;
        if (field0008 == 0xcb)
            field3114 = 0;
        return;
    }
    // Nayuki FA/FC counterattack: grounded opponent first, aerial opponent later.
    if (field0008 == 0xfa || field0008 == 0xfc) {
        if ((*opponentSlot)->field0008 > 49 &&
            (*opponentSlot)->field0008 < 157) {
            if (field3110 < 300 && (*opponentSlot)->positionY == 0.0) {
                field3114 = 7;
                return;
            }
            if (field3110 > 300 && field3110 < 450 &&
                (*opponentSlot)->positionY == 0.0) {
                field3114 = 4;
                return;
            }
            if (field3110 > 450 && field3110 < 550 &&
                (*opponentSlot)->positionY < 0.0 &&
                distance.forward < 60.0) {
                field3114 = 9;
                return;
            }
            if (field3110 > 550 && field3110 < 650 &&
                (*opponentSlot)->positionY < 0.0 &&
                distance.forward < 100.0) {
                field3114 = 10;
                return;
            }
        }
    }
    // Action 0x10C has four distinct timed button follow-ups.
    if (field0008 == 0x10c) {
        if (field3110 < 300 && distance.forward < 120.0 &&
            ((*opponentSlot)->field0008 > 199 ||
             (*opponentSlot)->positionY < 0.0)) {
            buttonPulse[0] = 1;
            return;
        }
        if (field3110 < 450 && field3110 > 300 &&
            (*opponentSlot)->positionY == 0.0 &&
            distance.forward < 160.0) {
            buttonPulse[1] = 1;
            return;
        }
        if (field3110 < 600 && field3110 > 450 &&
            (*opponentSlot)->positionY == 0.0 &&
            distance.forward < 100.0) {
            buttonPulse[2] = 1;
            return;
        }
        if (field3110 < 650 && field3110 > 600 &&
            (*opponentSlot)->positionY == 0.0 && field3148 < 9) {
            buttonPulse[3] = 1;
            return;
        }
    }
    // Randomized collision-confirm AI, original C8 follow-up tier.
    if (attackCollisionResult > 1 && hitstopFrames == 0 &&
        (float)(unsigned short)RandomRange(0, 100) < field00a8 * 25.0f &&
        field3114 == 0 && field3114 != 2) {
        field3110 = (unsigned short)RandomRange(0, 1000);
        if (field0008 == 0xc8) {
            if ((*opponentSlot)->positionY < 0.0 && field3110 < 300) {
                buttonPulse[1] = 1;
                inputY = 0;
                return;
            }
            if (distance.forward < 80.0 && field3110 < 400) {
                buttonPulse[0] = 1;
                inputY = 1;
                return;
            }
            if (distance.forward < 50.0 && field3110 < 400) {
                buttonPulse[0] = 1;
                inputY = 0;
                return;
            }
            if (distance.forward < 125.0 &&
                field3110 > 399 && field3110 < 700) {
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
                if ((unsigned short)RandomRange(0, 3) == 0)
                    field3114 = 7;
                return;
            }
        }
        if (field0008 == 0xc9) {
            if ((*opponentSlot)->positionY < 0.0 &&
                field3110 < 300 && attackCollisionResult == 3) {
                recognizedCommand = 0x14;
                return;
            }
            if ((*opponentSlot)->positionY < 0.0 &&
                field3110 > 299 && field3110 < 600) {
                buttonPulse[3] = 1;
                return;
            }
            if ((*opponentSlot)->positionY < 0.0 &&
                field3110 > 599 && field3110 < 700) {
                inputY = -1;
                inputX = facing;
                return;
            }
            if (field3110 < 350 && attackCollisionResult == 3) {
                buttonPulse[2] = 1;
                inputY = 1;
                return;
            }
            if (field3110 > 350 && field3110 < 500 &&
                attackCollisionResult == 3) {
                buttonPulse[2] = 1;
                inputY = 0;
                return;
            }
            if (field3110 > 500 && field3110 < 550 && field3148 > 2) {
                buttonPulse[1] = 1;
                inputY = 0;
                inputX = facing;
                return;
            }
            if (field3110 > 0 && field3110 < 500) {
                buttonPulse[1] = 1;
                inputY = 0;
                return;
            }
            if (field3110 > 900) {
                field3114 = 4;
                inputY = -1;
                inputX = (unsigned short)RandomRange(0, 2) - 1;
                return;
            }
            if (field3110 > 599) {
                field3114 = 1;
                if ((unsigned short)RandomRange(0, 2) == 0)
                    field3114 = 7;
                return;
            }
        }
        if (field0008 == 0xca) {
            if ((*opponentSlot)->positionY < 0.0 &&
                field3110 < 300 && attackCollisionResult == 3) {
                buttonPulse[2] = 1;
                return;
            }
            if ((*opponentSlot)->positionY < 0.0 &&
                field3110 > 300 && field3110 < 320 && meter >= 1000) {
                recognizedCommand = (unsigned short)RandomRange(0, 3) + 0x6e;
                return;
            }
            if (field3110 < 150 && distance.forward < 80.0) {
                buttonPulse[2] = 1;
                inputY = 1;
                return;
            }
            if (field3110 > 150 &&
                field3110 < (positionY < 0.0) * 150 + 350) {
                buttonPulse[2] = 1;
                inputY = 0;
                return;
            }
            if (field3110 > 350 && field3110 < 400) {
                recognizedCommand = 0x0a;
                return;
            }
            if (field3110 > 400 &&
                field3110 < field3148 * 10 + 450) {
                recognizedCommand = 0x1e;
                return;
            }
            if (field3110 > 600 && field3110 < 610 &&
                positionY < 0.0) {
                recognizedCommand = 0x34;
                return;
            }
        }
        if (field0008 == 0xcb) {
            if (field3110 > 0 && field3110 < 150) {
                recognizedCommand = 0x0a;
                return;
            }
            if (field3110 > 150 && field3110 < 300) {
                recognizedCommand = 0x1e;
                return;
            }
            if (field3110 > 300 && field3110 < 450) {
                recognizedCommand = 0x46;
                return;
            }
            if (field3110 > 450 && field3110 < 500 &&
                field0118 > 500.0) {
                recognizedCommand = 0x34;
                return;
            }
            if (field3110 > 500 && field3110 < 550 &&
                attackCollisionResult == 3 && meter >= 1000) {
                recognizedCommand = (unsigned short)RandomRange(0, 2) + 0x6e;
                return;
            }
            if (field3110 > 550 && field3110 < 560 && meter >= 1000) {
                recognizedCommand = (unsigned short)RandomRange(0, 2) + 0x64;
                return;
            }
            if (field3110 > 910) {
                field3114 = 4;
                inputY = -1;
                inputX = (unsigned short)RandomRange(0, 2) - 1;
                return;
            }
        }
        if (field0008 == 0xcc) {
            if ((*opponentSlot)->positionY < 0.0 && field3110 < 300) {
                buttonPulse[1] = 1;
                inputY = 0;
                return;
            }
            if (distance.forward < 80.0 && field3110 < 400) {
                buttonPulse[0] = 1;
                inputY = 1;
                return;
            }
            if (distance.forward < 50.0 && field3110 < 400) {
                buttonPulse[0] = 1;
                inputY = 0;
                return;
            }
            if (distance.forward < 125.0 &&
                field3110 > 399 && field3110 < 700) {
                buttonPulse[1] = 1;
                inputY = (unsigned short)RandomRange(0, 2) ? 0 : 1;
                return;
            }
            if (field3110 > 900) {
                field3114 = 4;
                inputY = -1;
                inputX = (unsigned short)RandomRange(0, 2) - 1;
                return;
            }
            if (field3110 > 699) {
                field3114 = 1;
                if ((unsigned short)RandomRange(0, 3) == 0)
                    field3114 = 7;
                return;
            }
        }
        if (field0008 == 0xcd) {
            if (field3110 < 350 && attackCollisionResult == 3) {
                buttonPulse[2] = 1;
                inputY = 1;
                return;
            }
            if (field3110 > 350 && field3110 < 500 &&
                attackCollisionResult == 3) {
                buttonPulse[2] = 1;
                inputY = 0;
                return;
            }
            if (field3110 > 500 && field3110 < 550 && field3148 > 2) {
                buttonPulse[1] = 1;
                inputY = 0;
                inputX = facing;
                return;
            }
            if (field3110 > 0 && field3110 < 500) {
                buttonPulse[1] = 1;
                inputY = 0;
                return;
            }
            if (field3110 > 900) {
                field3114 = 4;
                inputY = -1;
                inputX = (unsigned short)RandomRange(0, 2) - 1;
                return;
            }
            if (field3110 > 599) {
                field3114 = 1;
                if ((unsigned short)RandomRange(0, 2) == 0)
                    field3114 = 7;
                return;
            }
        }
        if (field0008 == 0xce) {
            if (field3110 > 0 && field3110 < 400 &&
                attackCollisionResult == 3) {
                inputX = facing;
                inputY = -1;
                return;
            }
            if (field3110 > 400 && field3110 < 800 &&
                attackCollisionResult == 3 && field3148 < 9) {
                buttonPulse[3] = 1;
                return;
            }
            if (field3110 > 0 && field3110 < 150) {
                recognizedCommand = 0x0a;
                if ((*opponentSlot)->positionY < 0.0)
                    recognizedCommand = 0x0b;
                return;
            }
            if (field3110 > 150 && field3110 < 300) {
                recognizedCommand = 0x1e;
                return;
            }
            if (field3110 > 300 && field3110 < 450 &&
                (*opponentSlot)->positionY == 0.0) {
                recognizedCommand = 0x46;
                return;
            }
            if (field3110 > 450 && field3110 < 600 &&
                field0118 > 500.0) {
                recognizedCommand = 0x34;
                return;
            }
            if (field3110 > 600 && field3110 < 1610 &&
                meter >= 1000) {
                recognizedCommand = (unsigned short)RandomRange(0, 2) + 0x64;
                return;
            }
        }
        if (field0008 == 0xcf) {
            if (distance.forward < 60.0 && distance.vertical < 30.0 &&
                field3110 < 400) {
                buttonPulse[0] = 1;
                return;
            }
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
            if (field3110 > 800) {
                field3114 = 1;
                if ((unsigned short)RandomRange(0, 4) == 0)
                    field3114 = 3;
                return;
            }
        }
        if (field0008 == 0xd0) {
            if (field3110 > 0 && field3110 < 400) {
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
        if (field0008 == 0xd1) {
            if (field3110 > 950) {
                inputX = (unsigned short)RandomRange(0, 2) - 1;
                return;
            }
            if (field3110 > 600) {
                field3114 = 3;
                return;
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
                if (distance.forward < 35.0 && field3110 < 15) {
                    buttonPulse[0] = 1;
                    inputY = 0;
                    return;
                }
                if (distance.forward < 50.0 && field3110 < 30) {
                    buttonPulse[0] = 1;
                    inputY = 1;
                    return;
                }
                if (distance.forward < 90.0 && distance.forward > 60.0 &&
                    field3110 < 75 && field3110 < 30) {
                    buttonPulse[1] = 1;
                    inputY = 1;
                    return;
                }
                if (distance.forward < 150.0 &&
                    distance.forward > 70 - (field3148 > 6) * 20 &&
                    field3110 < 135 && field3110 < 75) {
                    buttonPulse[1] = 1;
                    inputY = 0;
                    return;
                }
                if (distance.forward < 150.0 &&
                    distance.forward > 70 - (field3148 > 6) * 20 &&
                    field3110 < 135 && field3110 < 160 && field3148 > 2) {
                    buttonPulse[1] = 1;
                    inputY = 0;
                    return;
                }
                if (distance.forward < 150.0 && distance.forward > 90.0 &&
                    field3110 < 240 && field3110 > 160) {
                    buttonPulse[2] = 1;
                    inputY = 1;
                    return;
                }
                if (distance.forward < 260.0 && distance.forward > 100.0 &&
                    field3110 < 340 && field3110 > 300) {
                    recognizedCommand = (unsigned short)RandomRange(0, 3) + 0x0a;
                    return;
                }
                if (distance.forward < 200.0 && distance.forward > 70.0 &&
                    field3110 < field3148 * 5 + 360 && field3110 > 350) {
                    recognizedCommand = (unsigned short)RandomRange(0, 3) + 0x46;
                    return;
                }
                if (distance.forward < 200.0 && distance.forward > 70.0 &&
                    field3110 < field3148 * 5 + 420 && field3110 > 410 &&
                    field3148 > 3 && field0118 > 500.0) {
                    recognizedCommand = 0x15;
                    return;
                }
                if (distance.forward < 200.0 && distance.forward < 100.0 &&
                    field3110 < field3148 * 2 + 480 && field3110 > 470 &&
                    field0118 > 500.0 && (*opponentSlot)->field0008 > 199) {
                    recognizedCommand = 0x48;
                    return;
                }
                if (distance.forward < 200.0 && distance.forward < 70.0 &&
                    field3110 < field3148 * 2 + 510 && field3110 > 500 &&
                    field0118 > 500.0 && (*opponentSlot)->field0008 > 199) {
                    recognizedCommand = 0x16;
                    return;
                }
                // Delay-dependent D-button follow-up, opponent action windows.
                if (field3110 > 530 &&
                    field3110 < (
                        530 +
                        ((*opponentSlot)->field0008 > 58 &&
                          (*opponentSlot)->field0008 < 100 &&
                          (*opponentSlot)->field0008 != 96) * 150 +
                        ((*opponentSlot)->field0008 > 95 &&
                          (*opponentSlot)->field0008 < 100 &&
                          (*opponentSlot)->field0008 != 96) * 300 +
                        (distance.forward > 180.0) * 20) &&
                    field3148 < 9) {
                    buttonPulse[3] = 1;
                    return;
                }
                // Canonical contradictory timer test is intentionally retained.
                if (field3110 < 42 && field3110 > 47) {
                    recognizedCommand = (short)facing;
                    field3114 = 5;
                    return;
                }
            }
            // Opponent-airborne priorities: rising and falling Nayuki responses.
            if ((*opponentSlot)->positionY < 0.0) {
                if ((*opponentSlot)->velocityY < 0.0) {
                    if (distance.forward < 80.0 && distance.vertical < 120.0 &&
                        field3110 < 10) {
                        inputY = -1;
                        inputX = -facing;
                        return;
                    }
                    if (distance.forward < 80.0 && distance.vertical < 70.0 &&
                        field3110 < 20) {
                        buttonPulse[2] = 1;
                        inputY = 1;
                        return;
                    }
                }
                if ((*opponentSlot)->velocityY > 0.0) {
                    if (distance.forward < 70.0 && distance.vertical > 40.0 &&
                        distance.vertical < 90.0 && field3110 < 50 &&
                        (field0118 > 500.0 || field0120 > 0)) {
                        recognizedCommand = 0x14;
                        return;
                    }
                    if (distance.forward < 80.0 && distance.vertical < 150.0 &&
                        distance.vertical > 80.0 && field3110 < 90) {
                        buttonPulse[2] = 1;
                        inputY = 1;
                        return;
                    }
                    if (distance.forward < 150.0 && distance.forward > 100.0 &&
                        distance.vertical < 120.0 && distance.vertical > 90.0 &&
                        field3110 < 110 && field3110 > 90) {
                        buttonPulse[1] = 1;
                        inputY = 0;
                        return;
                    }
                }
            }
        }
        // Nayuki self-airborne follow-up: grounded and airborne opponents.
        if (positionY < 0.0 && field3114 != 3) {
            if ((*opponentSlot)->positionY == 0.0) {
                if (distance.forward < 70.0 && distance.vertical < 50.0 &&
                    field3110 < 200) {
                    buttonPulse[1] = 1;
                    return;
                }
                if (distance.forward < 70.0 && distance.vertical < 100.0 &&
                    field3110 < ((*opponentSlot)->positionY == 0.0) * 100 + 250) {
                    buttonPulse[1] = 1;
                    return;
                }
                if (distance.forward < 110.0 &&
                    distance.vertical > 60.0 && distance.vertical < 80.0 &&
                    velocityY > 0.0 && (*opponentSlot)->positionY > positionY &&
                    field3110 > 500 && field3110 < 620) {
                    buttonPulse[2] = 1;
                    return;
                }
            }
            if ((*opponentSlot)->positionY < 0.0) {
                if (distance.forward < 60.0 && distance.vertical > 60.0 &&
                    field3110 < 110) {
                    buttonPulse[1] = 1;
                    return;
                }
                if (distance.forward < 150.0 && distance.forward > 100.0 &&
                    distance.vertical < 80.0 &&
                    (*opponentSlot)->positionY < positionY &&
                    field3110 < 250 && field3110 > 110) {
                    buttonPulse[2] = 1;
                    return;
                }
            }
        }
    }
    // This common continuation is reached both when the 25x generic AI
    // probability fails and after all its candidate decisions fall through.
    if (field0008 < 50 &&
        (((*opponentSlot)->field0008 > 149 &&
          (*opponentSlot)->field0008 < 156) ||
         ((*opponentSlot)->field0008 > 49 &&
          (*opponentSlot)->field0008 < 59)) &&
        positionY == 0.0 &&
        (float)(unsigned short)RandomRange(0, 100) < 3.0f * field00a8) {
        if (distance.forward < 150.0)
            recognizedCommand = facing == 1;
        return;
    }

    // Nayuki second low-probability grounded spacing response.
    if (field0008 < 50 && positionY == 0.0 &&
        (float)(unsigned short)RandomRange(0, 100) < 1.0f * field00a8 &&
        distance.forward > 80.0 && distance.forward < 160.0) {
        if (distance.forward < 150.0)
            recognizedCommand = facing == 1;
        return;
    }

    if ((unsigned short)RandomRange(0, 1000) < 2) {
        field3114 = 4;
        return;
    }
    if ((unsigned short)RandomRange(0, 100) < 2) {
        if ((float)(unsigned short)RandomRange(0, 100) < 4.0f * field00a8)
            field3114 = 3;
        else
            field3114 = 0;
        if (distance.forward > 240.0 && positionY == 0.0 &&
            (unsigned short)RandomRange(0, 100) < 2) {
            inputX = 0;
            inputY = -1;
            return;
        }
        if (distance.forward < 80.0 && positionY == 0.0 &&
            (unsigned short)RandomRange(0, 100) < 2) {
            inputX = 0;
            inputY = -1;
            return;
        }
        if (distance.forward < 140.0 && distance.forward > 100.0 &&
            positionY == 0.0) {
            inputX = facing;
            inputY = -1;
            return;
        }
    }
    if (cpuMoveRightFrames > 0) {
        if (CollisionSide() != 0 && cpuMoveRightFrames > 15)
            cpuMoveRightFrames = 15;
        inputX = 1;
        return;
    }
    if (cpuMoveLeftFrames > 0) {
        if (CollisionSide() != 0 && cpuMoveLeftFrames > 15)
            cpuMoveLeftFrames = 15;
        inputX = -1;
        return;
    }
    if ((unsigned short)RandomRange(0, 100) < 40 &&
        distance.forward < 100.0) {
        if (facing == 1)
            cpuMoveLeftFrames = (unsigned short)RandomRange(0, 200) + 90;
        else
            cpuMoveRightFrames = (unsigned short)RandomRange(0, 200) + 90;
    }
    if ((unsigned short)RandomRange(0, 100) < 80) {
        if (facing == 1)
            cpuMoveRightFrames = (unsigned short)RandomRange(0, 200) + 90;
        else
            cpuMoveLeftFrames = (unsigned short)RandomRange(0, 200) + 90;
    }
    else if (facing == -1) {
        cpuMoveRightFrames = (unsigned short)RandomRange(0, 200) + 90;
    }
    else {
        cpuMoveLeftFrames = (unsigned short)RandomRange(0, 200) + 90;
    }
}
