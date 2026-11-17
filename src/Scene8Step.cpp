// Replay browser state machine, original 0x0076F060 (code + five-entry switch table).
// Natural VC7.1 C++ implements file selection, overwrite confirmation and palette transitions.
#include "Engine.h"

typedef char Scene8StepOwnerLayout[(sizeof(Scene8) == 0x758) ? 1 : -1];

unsigned char Scene8::Step()
{
    if (phase > 0) {
        contextOwner->LoadMusic(6);
        PrepareReplayList();
    }
    if (flag002d > 0) {
        FadeOut(palette, 1, 0, 0);
        if (flag002d == 2) {
            phase = 2;
            contextOwner->flag0f32 = 0;
            flag002d = 0;
            contextOwner->ReleaseMusic();
            return 1;
        } else {
            phase = 1;
            contextOwner->flag0f32 = 0;
            flag002d = 0;
            contextOwner->ReleaseMusic();
            return 0;
        }
    }
    PollKeyboard();
    contextOwner->PollInput();
    for (int player = 0; player < 2; ++player) {
        switch (replayMenuPhase) {
        case 0:
            if (heldDirection[player] == 0 && contextOwner->directionY[player] != 0) {
                contextOwner->PlayEffectSound(8);
                replayColumn += contextOwner->directionY[player];
                if (replayColumn > 8) replayColumn = 0;
                else if (replayColumn < 0) replayColumn = 8;
            }
            if (heldDirection[player] == 0 && contextOwner->directionX[player] != 0) {
                contextOwner->PlayEffectSound(8);
                replayRow += contextOwner->directionX[player];
                if (replayRow > 9) replayRow = 0;
                else if (replayRow < 0) replayRow = 9;
            }
            if (contextOwner->buttonA[player] != 0) {
                if (replayRow == 9) flag002d = 1;
                else {
                    contextOwner->PlayEffectSound(6);
                    replayMenuPhase = 1;
                }
            }
            if (replayMenuPhase == 0 && (contextOwner->buttonB[0] != 0 || contextOwner->buttonB[1] != 0)) {
                flag002d = 1;
            }
            break;
        case 1:
            replayScrollX = replayScrollX + 2.0;
            replayScrollY = ((double)(int)replayColumn * 16.0) / 90.0 + replayScrollY;
            if (replayScrollX > 180.0) {
                replayScrollX = 180.0;
                replayMenuPhase = 2;
            }
            break;
        case 2:
            if (heldDirection[player] == 0 && contextOwner->directionY[player] != 0) {
                contextOwner->PlayEffectSound(8);
                replayMenuSubchoice += contextOwner->directionY[player];
                if (replayMenuSubchoice >= 3) replayMenuSubchoice = 0;
                else if (replayMenuSubchoice < 0) replayMenuSubchoice = 2;
            }
            if (contextOwner->buttonA[player] != 0) {
                contextOwner->PlayEffectSound(6);
                if (replayAvailable[(int)replayRow][(int)replayColumn] != 0 && replayMenuSubchoice == 0) {
                    contextOwner->field14281 = replayColumn;
                    contextOwner->field14282 = replayRow;
                    contextOwner->flag14283 = 1;
                    FadeOut(palette, 0, 0, 50);
                    phase = 2;
                    return 2;
                }
                if (replayMenuSubchoice == 1) {
                    if (replayAvailable[(int)replayRow][(int)replayColumn] != 0) {
                        replayMenuPhase = 4;
                    } else {
                        contextOwner->field14281 = replayColumn;
                        contextOwner->field14282 = replayRow;
                        contextOwner->flag14283 = 2;
                        flag002d = 2;
                    }
                } else {
                    replayMenuPhase = 3;
                }
            }
            if (contextOwner->buttonB[player] != 0 && heldDirection[player] == 0) {
                replayMenuPhase = 3;
                heldDirection[player] = 1;
            }
            break;
        case 3:
            replayScrollX = replayScrollX - 2.0;
            replayScrollY = replayScrollY - ((double)(int)replayColumn * 16.0) / 90.0;
            if (replayScrollX < 0.0) {
                replayScrollX = 0.0;
                replayMenuPhase = 0;
            }
            break;
        case 4:
            if (heldDirection[player] == 0 && contextOwner->directionX[player] != 0) {
                contextOwner->PlayEffectSound(8);
                replayOverwriteChoice += contextOwner->directionX[player];
                if (replayOverwriteChoice > 1) replayOverwriteChoice = 0;
                else if (replayOverwriteChoice < 0) replayOverwriteChoice = 1;
            }
            if (contextOwner->buttonA[player] != 0) {
                contextOwner->PlayEffectSound(6);
                replayMenuPhase = 2;
                if (replayOverwriteChoice == 0) {
                    contextOwner->field14281 = replayColumn;
                    contextOwner->field14282 = replayRow;
                    contextOwner->flag14283 = 2;
                    flag002d = 2;
                }
            }
            if (contextOwner->buttonB[player] != 0) {
                replayMenuPhase = 2;
                heldDirection[player] = 1;
            }
            break;
        }
        heldDirection[player] = (contextOwner->directionX[player] != 0 ||
                                 contextOwner->directionY[player] != 0 ||
                                 contextOwner->buttonB[player] != 0);
    }
    Slot0();
    return 8;
}
