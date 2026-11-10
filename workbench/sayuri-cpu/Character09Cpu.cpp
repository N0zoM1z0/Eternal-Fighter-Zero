// Sayuri Character09::Slot05 partial native CPU workbench.
// This opening is reviewed against original Sayuri x86.
// Unreviewed sibling-character logic is deliberately excluded.
#include "../../src/CharacterViews.h"
#include <math.h>

void Character09::Slot05()
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
            if (distance.forward < 140.0 &&
                (float)(unsigned short)RandomRange(0, 100) < field00a8 * 1.0f) {
                recognizedCommand = 0x14;
                return;
            }
        }
        // Shared opponent collision-result follow-up. Only the
        // first 40..90 window is present in Sayuri's original tree.
        // This Sayuri-specific collision gate precedes the 40..90 response.
        if (((*opponentSlot)->field0008 == 0xc9 ||
              (*opponentSlot)->field0008 == 0xca ||
              (*opponentSlot)->field0008 == 0xcd) &&
            (*opponentSlot)->field0008 < 0xfa &&
            (*opponentSlot)->positionY == 0.0 &&
            (*opponentSlot)->remainingHitCount == 0) {
            if (distance.forward > 40.0 && distance.forward < 90.0 &&
                (float)(unsigned short)RandomRange(0, 100) < field00a8 * 3.0f) {
                buttonPulse[1] = 1;
                inputY = 1;
                return;
            }
        }
    }
    // Sayuri's 0xA8/0xA9 state has its own graded special commands.
    if (field0008 == 0xa8 || field0008 == 0xa9) {
        if (distance.forward < 80.0) {
            if ((float)(unsigned short)RandomRange(0, 100) < field00a8 * 1.0f &&
                field0118 > 500.0) {
                recognizedCommand = 0x20;
                return;
            }
            if ((float)(unsigned short)RandomRange(0, 100) <
                field00a8 * 2.0f + (float)((field0118 > 500.0 ? 1 : 0) << 1)) {
                recognizedCommand = 0x0c;
                return;
            }
            if ((float)(unsigned short)RandomRange(0, 100) < field00a8 * 1.0f) {
                recognizedCommand = 0x14;
                return;
            }
            if ((float)(unsigned short)RandomRange(0, 100) < field00a8 * 4.0f &&
                meter >= 2000) {
                recognizedCommand = (unsigned short)RandomRange(0, 2) + 0xab;
                return;
            }
            if ((float)(unsigned short)RandomRange(0, 100) <
                field00a8 * 2.0f + (float)((field0118 > 500.0 ? 1 : 0) << 1)) {
                recognizedCommand = 0x0c;
                return;
            }
        }
        if (distance.forward < 135.0) {
            if ((float)(unsigned short)RandomRange(0, 100) <
                field00a8 * 2.0f + (float)((field0118 > 500.0 ? 1 : 0) << 1)) {
                recognizedCommand = 0x20;
                return;
            }
            if ((float)(unsigned short)RandomRange(0, 100) < field00a8 * 2.0f) {
                recognizedCommand = 0x14;
                return;
            }
        }
        if (distance.forward > 220.0) {
            if ((float)(unsigned short)RandomRange(0, 100) < field00a8 * 5.0f) {
                recognizedCommand = 0x0b;
                return;
            }
            if ((float)(unsigned short)RandomRange(0, 100) < field00a8 * 1.0f &&
                meter >= 1000) {
                recognizedCommand = (unsigned short)RandomRange(0, 3) + 0x6e;
                return;
            }
            if ((float)(unsigned short)RandomRange(0, 150) < field00a8 * 1.0f &&
                meter >= 3000) {
                recognizedCommand = (unsigned short)RandomRange(0, 3) + 0x6e;
                return;
            }
        }
    }
    // Sayuri's AA-state aerial hit confirms have five ordered outcomes.
    if (field0008 == 0xaa && (unsigned short)field000a == 1 &&
        (unsigned short)field000c == 0) {
        if ((float)(unsigned short)RandomRange(0, 100) < field00a8 * 5.0f) {
            field3114 = 3;
            return;
        }
        if (positionY - (*opponentSlot)->positionY > 0.0 &&
            positionY - (*opponentSlot)->positionY < 40.0 &&
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
        if (positionY - (*opponentSlot)->positionY > -80.0 &&
            positionY - (*opponentSlot)->positionY < 30.0 &&
            distance.vertical > 30.0 && distance.forward < 100.0 &&
            (float)(unsigned short)RandomRange(0, 100) < field00a8 * 5.0f) {
            buttonPulse[2] = 1;
            inputY = 0;
            return;
        }
        if (distance.vertical < 50.0 && distance.forward < 100.0 &&
            (float)(unsigned short)RandomRange(0, 100) < field00a8 * 2.0f &&
            field0118 > 500.0) {
            recognizedCommand = 0x2a;
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
            recognizedCommand = 0x20;
            return;
        }
        if (field3110 < 10 && field0118 > 500.0) {
            recognizedCommand = 0x14;
            return;
        }
        if (field3110 < 13 && field0118 > 500.0) {
            recognizedCommand = 0x0c;
            return;
        }
        if (field3110 < 17 && field3110 > 12 && meter >= 1000) {
            recognizedCommand = (unsigned short)RandomRange(0, 2) * 0xaa;
            return;
        }
        // This contradictory window is present in the original native tree.
        if (field3110 < 16 && field3110 > 18 && meter == 3000) {
            recognizedCommand = 0x5d;
            return;
        }
    }
    // Airborne reaction to the same opponent attack states.
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
        if (field0008 == 4 || field0008 == 5 || field0008 == 6) {
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
        field3114 = 0;
        buttonPulse[1] = 1;
        return;
    }
    if (field3114 == 7) {
        inputY = -1;
        inputX = facing;
        if (positionY < -30.0) {
            recognizedCommand = 0x28;
            field3114 = 0;
        }
        return;
    }
    // Randomized attack-collision follow-ups: first the 0xC8 decision tree.
    if (attackCollisionResult > 1 && hitstopFrames == 0 &&
        (float)(unsigned short)RandomRange(0, 100) < field00a8 * 25.0f &&
        field3114 != 1 && field3114 != 2) {
        field3110 = (unsigned short)RandomRange(0, 1000);
        if (field0008 == 0xc8) {
            if ((*opponentSlot)->positionY < 0.0 && field3110 < 300) {
                buttonPulse[1] = 1;
                inputY = 1;
                return;
            }
            if (distance.forward < 60.0 && field3110 < 400) {
                buttonPulse[0] = 1;
                inputY = 1;
                return;
            }
            if (distance.forward < 80.0 && field3110 < 400) {
                buttonPulse[0] = 1;
                inputY = 0;
            }
            if (distance.forward < 125.0 &&
                field3110 > 399 && field3110 < 550) {
                buttonPulse[1] = 1;
                inputY = 0;
                return;
            }
            if (distance.forward < 135.0 &&
                field3110 > 550 && field3110 < 700) {
                buttonPulse[1] = 1;
                inputY = 1;
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
                if ((unsigned short)RandomRange(0, 4) == 0)
                    field3114 = 5;
                return;
            }
        }
        if (field0008 == 0xc9) {
            if ((*opponentSlot)->positionY < 0.0 &&
                field3110 < 200 && attackCollisionResult == 3) {
                recognizedCommand = 0x1e;
                return;
            }
            if ((*opponentSlot)->positionY < 0.0 &&
                field3110 > 200 && field3110 < 450) {
                buttonPulse[2] = 1;
                inputY = 1;
                return;
            }
            if ((*opponentSlot)->positionY < 0.0 &&
                field3110 > 450 && field3110 < 500 && meter >= 1000) {
                recognizedCommand = (unsigned short)RandomRange(0, 3) + 0xaa;
                return;
            }
            if (field3110 < 200) {
                buttonPulse[2] = 1;
                inputY = 0;
                return;
            }
            if (field3110 > 299 && field3110 < 500) {
                buttonPulse[1] = 1;
                inputY = 0;
                return;
            }
            if (field3110 > 850) {
                if ((unsigned short)RandomRange(0, 2) == 0)
                    field3114 = 7;
                inputY = -1;
                return;
            }
            if (field3110 > 920) {
                field3114 = 4;
                inputY = -1;
                inputX = (unsigned short)RandomRange(0, 2) - 1;
                return;
            }
            if (field3110 > 499) {
                field3114 = 1;
                if ((unsigned short)RandomRange(0, 3) == 0)
                    field3114 = 5;
                return;
            }
        }
        if (field0008 == 0xca) {
            if ((*opponentSlot)->positionY < 0.0 &&
                field3110 < 200 && attackCollisionResult == 3) {
                recognizedCommand = 0x1e;
                return;
            }
            if ((*opponentSlot)->positionY < 0.0 &&
                field3110 > 199 && field3110 < 400) {
                recognizedCommand = 0x0b;
                return;
            }
            if ((*opponentSlot)->positionY < 0.0 &&
                field3110 > 399 && field3110 < 500 && meter >= 1000) {
                recognizedCommand = (unsigned short)RandomRange(0, 2) + 0xaa;
                return;
            }
            if (field3110 < 400 && distance.forward < 100.0) {
                buttonPulse[2] = 1;
                inputY = 0;
                return;
            }
            if (field3110 > 400 && field3110 < 700) {
                recognizedCommand = (unsigned short)RandomRange(0, 3) + 0x0a;
                return;
            }
            if (field3110 > 649) {
                field3114 = 1;
                return;
            }
        }
        if (field0008 == 0xcb) {
            if ((*opponentSlot)->positionY < 0.0 &&
                field3110 < 250 && attackCollisionResult == 3) {
                recognizedCommand = 0x0a;
                return;
            }
            if (field3110 > 250 && field3110 < 350 &&
                meter >= 1000 && attackCollisionResult == 3) {
                recognizedCommand = (unsigned short)RandomRange(0, 3) + 0xaa;
                return;
            }
            if (field3110 > 0 && field3110 < 650) {
                recognizedCommand = (unsigned short)RandomRange(0, 2) + 0x0a;
                return;
            }
            if (field3110 > 650 && field3110 < 700 && field0118 > 500.0) {
                recognizedCommand = 0x34;
                return;
            }
            if (field3110 > 700 &&
                field3110 < (attackCollisionResult == 3) * 0x14 + 0x2da &&
                meter >= 1000) {
                recognizedCommand = (unsigned short)RandomRange(0, 3) + 0x6e;
                return;
            }
            if (field3110 > 649) {
                field3114 = 1;
                return;
            }
        }
        if (field0008 == 0xcc) {
            if ((*opponentSlot)->positionY < 0.0 && field3110 < 300) {
                buttonPulse[1] = 1;
                inputY = 1;
                return;
            }
            if (distance.forward < 60.0 && field3110 < 400) {
                buttonPulse[0] = 1;
                inputY = 1;
                return;
            }
            if (distance.forward < 80.0 && field3110 < 400) {
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
                if ((unsigned short)RandomRange(0, 4) == 0)
                    field3114 = 5;
                return;
            }
        }
        if (field0008 == 0xcd) {
            if ((*opponentSlot)->positionY < 0.0 &&
                field3110 < 200 && attackCollisionResult == 3) {
                recognizedCommand = 0x1e;
                return;
            }
            if ((*opponentSlot)->positionY < 0.0 &&
                field3110 > 199 && field3110 < 400) {
                recognizedCommand = 0x0b;
                return;
            }
            if ((*opponentSlot)->positionY < 0.0 &&
                field3110 > 399 && field3110 < 500 && meter >= 1000) {
                recognizedCommand = (unsigned short)RandomRange(0, 2) + 0xaa;
                return;
            }
            if (field3110 < 400 && distance.forward < 100.0) {
                buttonPulse[2] = 1;
                inputY = 0;
                return;
            }
            if (field3110 > 400 && field3110 < 700) {
                recognizedCommand = (unsigned short)RandomRange(0, 3) + 0x0a;
                return;
            }
            if (field3110 > 850) {
                if ((unsigned short)RandomRange(0, 2) == 0)
                    field3114 = 7;
                inputY = -1;
                return;
            }
            if (field3110 > 920) {
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
    }
    // Later action-specific CPU decisions are still open.
}
