// Result/round-transition owner at original 0x007714E0.
// Natural VC7.1 C++ recreation of the complete results transition/round state.
#include "Engine.h"
#include <cstdlib>

typedef char Scene9StepFullNativeLayout[(sizeof(Scene9) == 0x474) ? 1 : -1];

unsigned char Scene9::Step()
{
    if (phase == 1) {
        resultPhase = 0;
        resultTransitionState = 0;
        secondary[0] = *secondarySlotA;
        secondary[1] = *secondarySlotB;
        PrepareResults();
        contextOwner->ReleaseMusic();
        FadeIn(contextOwner->characterPalette, 1);
        phase = 0;
    } else if (flag002d == 1) {
        FadeOut(contextOwner->characterPalette, contextOwner->mode1364 != 0, 0, 100);
        contextOwner->field1360 |= 1 << contextOwner->flag0f32;
        if (contextOwner->blob) {
            void *releasedBackground = contextOwner->blob;
            std::free(releasedBackground);
            contextOwner->blob = 0;
        }
        if (contextOwner->flag14283 > 0)
            contextOwner->replayFile.Close();
        if (contextOwner->mode1364 == 0) {
            if (contextOwner->winner134c == (char)contextOwner->selectedPlayer) {
                if (contextOwner->flag1358 == 8) {
                    delete *secondarySlotA;
                    delete *secondarySlotB;
                    *secondarySlotA = 0;
                    *secondarySlotB = 0;
                    flag002d = 0;
                    phase = 1;
                    return 7;
                }
                if ((char)contextOwner->selectedPlayer == 1) {
                    contextOwner->field135c |= 1 << (*secondarySlotA)->characterId;
                    delete *secondarySlotA;
                    *secondarySlotA = 0;
                } else {
                    contextOwner->field135c |= 1 << (*secondarySlotB)->characterId;
                    delete *secondarySlotB;
                    *secondarySlotB = 0;
                }
                ++contextOwner->flag1358;
                contextOwner->playerFlag1378[0] = 0;
                flag002d = 0;
                phase = 1;
                return 2;
            }
            if ((unsigned char)contextOwner->playerFlag1378[0] > 0) {
                flag002d = 0;
                phase = 1;
                return 2;
            }
            delete *secondarySlotA;
            delete *secondarySlotB;
            *secondarySlotA = 0;
            *secondarySlotB = 0;
            flag002d = 0;
            phase = 1;
            return 1;
        }
        if (contextOwner->mode1364 == 2 &&
            contextOwner->winner134c == (char)contextOwner->selectedPlayer &&
            contextOwner->flag1358 < 8) {
            if ((char)contextOwner->selectedPlayer == 1) {
                contextOwner->field135c |= 1 << (*secondarySlotA)->characterId;
                delete *secondarySlotA;
                *secondarySlotA = 0;
            } else {
                contextOwner->field135c |= 1 << (*secondarySlotB)->characterId;
                delete *secondarySlotB;
                *secondarySlotB = 0;
            }
            ++contextOwner->flag1358;
            flag002d = 0;
            phase = 1;
            return 2;
        }
        if (contextOwner->mode1364 == 6) {
            delete *secondarySlotA;
            delete *secondarySlotB;
            *secondarySlotA = 0;
            *secondarySlotB = 0;
            flag002d = 0;
            phase = 1;
            return 0;
        }
        delete *secondarySlotA;
        delete *secondarySlotB;
        *secondarySlotA = 0;
        *secondarySlotB = 0;
        flag002d = 0;
        phase = 1;
        return 1;
    }

    PollKeyboard();
    if (resultIntroTimer < 60) {
        ++resultIntroTimer;
        if (contextOwner->winner134c == 1) {
            secondary[0]->Slot06();
            secondary[0]->UpdateMovement();
            secondary[0]->Slot06();
            secondary[0]->UpdateMovement();
            secondary[0]->Slot06();
            secondary[0]->UpdateMovement();
            if (secondary[0]->pendingContextSoundSlot >= 0 &&
                secondary[0]->pendingContextSoundSlot < 65) {
                audioOwner->StartSound(contextOwner->soundSlots[secondary[0]->pendingContextSoundSlot], 0);
                secondary[0]->pendingContextSoundSlot = -1;
            }
        } else {
            secondary[1]->Slot06();
            secondary[1]->UpdateMovement();
            secondary[1]->Slot06();
            secondary[1]->UpdateMovement();
            secondary[1]->Slot06();
            secondary[1]->UpdateMovement();
            if (secondary[1]->pendingContextSoundSlot >= 0 &&
                secondary[1]->pendingContextSoundSlot < 65) {
                audioOwner->StartSound(contextOwner->soundSlots[secondary[1]->pendingContextSoundSlot], 0);
                secondary[1]->pendingContextSoundSlot = -1;
            }
        }
        if (resultIntroTimer == 60) {
                        if (secondary[(char)contextOwner->winner134c]->characterId == 19 || secondary[(char)contextOwner->winner134c]->characterId == 20 ||
                secondary[(char)contextOwner->winner134c]->characterId == 21 || secondary[(char)contextOwner->winner134c]->characterId == 23)
                contextOwner->LoadMusic(4);
            else if (secondary[(char)contextOwner->winner134c]->characterId == 14)
                contextOwner->LoadMusic(9);
            else if (secondary[(char)contextOwner->winner134c]->characterId == 1 || secondary[(char)contextOwner->winner134c]->characterId == 16 ||
                     secondary[(char)contextOwner->winner134c]->characterId == 17 || secondary[(char)contextOwner->winner134c]->characterId == 13 ||
                     secondary[(char)contextOwner->winner134c]->characterId == 15 || secondary[(char)contextOwner->winner134c]->characterId == 2 ||
                     secondary[(char)contextOwner->winner134c]->characterId == 3 || secondary[(char)contextOwner->winner134c]->characterId == 8 ||
                     secondary[(char)contextOwner->winner134c]->characterId == 9 || secondary[(char)contextOwner->winner134c]->characterId == 10)
                contextOwner->LoadMusic(2);
            else
                contextOwner->LoadMusic(3);
            resultPhase = 1;
        }
    }
    if (resultPanelY > 40 && resultIntroTimer >= 60) {
        resultPanelY -= resultPanelSpeed / 3;
        if (resultPanelY < 120 && resultPanelSpeed > 1)
            --resultPanelSpeed;
    }
    contextOwner->PollInput();
    if (resultPhase == 2) {
        if (contextOwner->directionX[(char)contextOwner->selectedPlayer] && !confirmHeld) {
            ++resultTransitionState;
            contextOwner->PlayEffectSound(8);
            if (resultTransitionState > 1)
                resultTransitionState = 0;
            confirmHeld = 1;
        }
        if (!contextOwner->directionX[(char)contextOwner->selectedPlayer])
            confirmHeld = 0;
        if (contextOwner->buttonA[(char)contextOwner->selectedPlayer]) {
            contextOwner->PlayEffectSound(6);
            if (resultTransitionState == 0) {
                if (contextOwner->flag1358 < 8)
                    contextOwner->playerFlag1378[1] = contextOwner->flag1358;
                else
                    contextOwner->playerFlag1378[1] = 0;
                contextOwner->playerFlag1378[0] = 1;
                flag002d = 1;
            } else {
                contextOwner->playerFlag1378[0] = 0;
                flag002d = 1;
            }
        }
    } else if (contextOwner->buttonA[0] || contextOwner->buttonB[0] ||
               contextOwner->buttonC[0] || contextOwner->buttonD[0] ||
               contextOwner->buttonA[1] || contextOwner->buttonB[1] ||
               contextOwner->buttonC[1] || contextOwner->buttonD[1]) {
        if (contextOwner->mode1364 == 0 &&
            contextOwner->winner134c != (char)contextOwner->selectedPlayer &&
            resultPhase < 2) {
            if (resultPhase == 0) {
                                if (secondary[(char)contextOwner->winner134c]->characterId == 19 || secondary[(char)contextOwner->winner134c]->characterId == 20 ||
                    secondary[(char)contextOwner->winner134c]->characterId == 21 || secondary[(char)contextOwner->winner134c]->characterId == 23)
                    contextOwner->LoadMusic(4);
                else if (secondary[(char)contextOwner->winner134c]->characterId == 1 || secondary[(char)contextOwner->winner134c]->characterId == 2 ||
                         secondary[(char)contextOwner->winner134c]->characterId == 3 || secondary[(char)contextOwner->winner134c]->characterId == 8 ||
                         secondary[(char)contextOwner->winner134c]->characterId == 9 || secondary[(char)contextOwner->winner134c]->characterId == 10)
                    contextOwner->LoadMusic(2);
                else
                    contextOwner->LoadMusic(3);
            }
            resultPhase = 2;
            resultPanelX = -160;
            resultPanelYStart = 0;
            resultPanelY = 40;
            resultPanelAcceleration = 160;
            resultIntroTimer = 60;
        } else if (contextOwner->mode1364 == 2 && resultPhase < 2) {
            if (resultPhase == 0) {
                                if (secondary[(char)contextOwner->winner134c]->characterId == 19 || secondary[(char)contextOwner->winner134c]->characterId == 20 ||
                    secondary[(char)contextOwner->winner134c]->characterId == 21 || secondary[(char)contextOwner->winner134c]->characterId == 23)
                    contextOwner->LoadMusic(4);
                else if (secondary[(char)contextOwner->winner134c]->characterId == 1 || secondary[(char)contextOwner->winner134c]->characterId == 2 ||
                         secondary[(char)contextOwner->winner134c]->characterId == 3 || secondary[(char)contextOwner->winner134c]->characterId == 8 ||
                         secondary[(char)contextOwner->winner134c]->characterId == 9 || secondary[(char)contextOwner->winner134c]->characterId == 10)
                    contextOwner->LoadMusic(2);
                else
                    contextOwner->LoadMusic(3);
            }
            resultPhase = 3;
            resultPanelX = -160;
            resultPanelYStart = 0;
            resultPanelY = 40;
            resultPanelAcceleration = 160;
            resultIntroTimer = 60;
        } else {
            flag002d = 1;
        }
    }
    resultScrollA += 2;
    if (resultScrollA >= 320)
        resultScrollA = 0;
    resultScrollB = resultScrollB + 1;
    if (resultScrollB >= 240)
        resultScrollB = 0;
    resultScrollC -= 2;
    if (resultScrollC < 0)
        resultScrollC = 320;
    resultScrollD = resultScrollD - 1;
    if (resultScrollD < 0)
        resultScrollD = 240;
    if (resultPanelAcceleration < 160 && resultPanelX <= -80) {
        resultPanelAcceleration += resultPanelXDeceleration;
        if (resultPanelAcceleration > 115)
            --resultPanelXDeceleration;
    }
    if (resultPanelX > -160 && resultPanelY < 160) {
        resultPanelX -= resultPanelYDeceleration;
        if (resultPanelX < -40)
            --resultPanelYDeceleration;
    }
    if (resultPanelYStart < 0 && resultPanelAcceleration > 120) {
        resultPanelYStart += resultPanelYOffset;
        if (resultPanelYStart >= 0 && contextOwner->mode1364 == 6)
            flag002d = 1;
        if (resultPanelYStart > -120)
            --resultPanelYOffset;
    }
    Slot0();
    return 5;
}
