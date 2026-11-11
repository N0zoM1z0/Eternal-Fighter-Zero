// Akiko's passive opponent interaction, music-fade, and timed effect cycle.
#include "CharacterViews.h"

void Character16::Slot08()
{
    if ((health <= 0 || (*opponentSlot)->health <= 0) && field3148 > 0) {
        field3148 = 0;
        (*opponentSlot)->field015c = 0;
    }
    if ((health <= 0 || (*opponentSlot)->health <= 0) && field0160 > 0) {
        if (field0008 != 319)
            contextOwner->FadeMusic(0,10000);
        field0160 = 0;
        field3160 = 0;
        field315c = 0;
        field3158 = 0;
        field3154 = 0;
    }
    if (field3148 > 0) {
        (*opponentSlot)->SetCharacterTint(0xcb,3);
        --field3148;
        if (field3148 <= 0)
            (*opponentSlot)->field015c = 0;
    }
    if (field0160 > 0) {
        field3154 += 4 - field0160;
        if (field3160 == 0) {
            if (field3154 > 9) {
                field3154 -= 10;
                ++field3158;
            }
            if (field3158 > 9) {
                field3158 -= 10;
                ++field315c;
            }
            if (field315c > 9) {
                field315c -= 10;
                ++field3160;
            }
            contextOwner->SetSceneTimer(3);
            if (field314c == 2 || field314c == 4 || field314c == 6 ||
                field314c == 8 || field314c == 10 || field314c == 12 ||
                field314c == 14 || field314c == 16 || field314c == 18 ||
                field314c == 20 || field314c == 22 || field314c == 24 ||
                field314c == 26 || field314c == 28 || field314c == 30 ||
                field314c == 32 || field314c == 34 || field314c == 36) {
                if (field314c >= 36) {
                    field314c = 0;
                    if ((*opponentSlot)->field0160 == 0 ||
                        (*opponentSlot)->field0160 == 4 ||
                        ((*opponentSlot)->field0160 != 0 && player == 0))
                        pendingCharacterSoundSlot = 15;
                }
                if ((*opponentSlot)->field0160 == 0 ||
                    (*opponentSlot)->field0160 == 4)
                    hitstunFrames = 1;
            }
            ++field314c;
        }
        if (field3160 > 0) {
            if (field3160 == 1) {
                field0160 = 4;
                if ((*opponentSlot)->field0160 == 0 ||
                    (*opponentSlot)->field0160 == 4)
                    contextOwner->FadeMusic(0,10000);
                pendingCharacterSoundSlot = 18;
            }
            ++field3160;
            if (field3160 > 180) {
                field3160 = 0;
                field315c = 0;
                field3158 = 0;
                field3154 = 0;
                field0160 = 0;
            }
        }
        if (field0008 > 49 && field0008 < 150) {
            if ((*opponentSlot)->field0160 == 0 ||
                (*opponentSlot)->field0160 == 4)
                contextOwner->FadeMusic(0,10000);
            field0160 = 0;
            field3160 = 0;
            field315c = 0;
            field3158 = 0;
            field3154 = 0;
        }
    }
}
