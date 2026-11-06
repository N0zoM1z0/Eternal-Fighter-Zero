// Battle keyboard controls and replay recording reset.
#include "SceneBattle.h"
#include <cstring>
#include <cstdlib>
extern int battleKeyHeld;

void Scene3::PollKeyboard()
{
    char state[256];
    {
        HRESULT result;
        result = inputOwner->keyboard->GetDeviceState(256, state);
        if (result < 0) { if (result == DIERR_INPUTLOST) inputOwner->keyboard->Acquire(); }
        if (contextOwner->flag14283 == 1 && contextOwner->replayFile.exhausted != 0) {
            contextOwner->replayFile.exhausted = 0;
            flag002d = 1;
        }
        if (flag002d == 0 && contextOwner->mode1364 == 6) {
            contextOwner->PollInput();
            if (contextOwner->buttonA[0] != 0 || contextOwner->buttonA[1] != 0 || contextOwner->buttonB[0] != 0 || contextOwner->buttonB[1] != 0 || (state[DIK_ESCAPE] & 0x80)) {
                flag002d = 1;
                contextOwner->ReleaseMusic();
                field0588 = 0;
            }
        }
        if (flag002d == 0 && (state[DIK_ESCAPE] & 0x80)) {
            flag002d = 1;
            field0588 = 0;
        }
        if ((state[DIK_F4] & 0x80) && contextOwner->effectFlag1350 == 0 && contextOwner->counter1354 == 0 &&
            contextOwner->mode1364 != 0 && contextOwner->mode1364 != 2 && contextOwner->mode1364 != 6) {
            field0574 += 5;
            if (field0574 > 2000) field0574 = 0;
            field0576 = 9999;
            secondary[0]->field30ec = field0574;
            secondary[1]->field30ec = field0574;
            secondary[0]->field30ee = field0576;
            secondary[1]->field30ee = field0576;
        } else if ((state[DIK_F5] & 0x80) && battleKeyHeld == 0 && contextOwner->mode1364 != 0 && contextOwner->mode1364 != 2 && contextOwner->mode1364 != 6) {
            if (field0574 == 1000) {
                if (field0576 == 3332) field0574 = 2000;
                else field0576 = 3332;
            } else field0574 = 1000;
            secondary[0]->field30ec = field0574;
            secondary[1]->field30ec = field0574;
            secondary[0]->field30ee = field0576;
            secondary[1]->field30ee = field0576;
            battleKeyHeld = 1;
        }
        if (contextOwner->mode1364 == 1) {
            if ((state[DIK_F6] & 0x80) && battleKeyHeld == 0) {
                ++contextOwner->flag1346;
                if ((char)contextOwner->flag1346 > 2) contextOwner->flag1346 = 0;
                battleKeyHeld = 1;
            } else if ((state[DIK_F7] & 0x80) && battleKeyHeld == 0) {
                contextOwner->counter1348 = contextOwner->counter1348 == 0;
                battleKeyHeld = 1;
            }
        } else if (contextOwner->mode1364 == 5 && contextOwner->flag14283 == 2 && (state[DIK_F6] & 0x80)) {
            ResetReplay();
        }
        if ((state[DIK_F8] & 0x80) && battleKeyHeld == 0) {
            field0588 = field0588 == 0;
            battleKeyHeld = 1;
        }
        if (field0574 == 2000) {
            field0574 = 0;
            field0576 = 9999;
            secondary[0]->field30ec = field0574;
            secondary[1]->field30ec = field0574;
            secondary[0]->field30ee = field0576;
            secondary[1]->field30ee = field0576;
            secondary[0]->field0108 = 9999;
            secondary[1]->field0108 = 9999;
        }
        if ((state[DIK_F5] & 0x80) || (state[DIK_F6] & 0x80) || (state[DIK_F7] & 0x80) || (state[DIK_F8] & 0x80)) battleKeyHeld = 1;
        else battleKeyHeld = 0;
        // The retail target retains this constant-true skip and full disabled controls.
        if (true) {
        } else {
            if (state[DIK_F1] & 0x80) field0578 = 1;
            if (state[DIK_F2] & 0x80) field0578 = 2;
            if (state[DIK_F3] & 0x80) field0578 = 3;
            if (state[DIK_F9] & 0x80) field058c = 1;
            if (state[DIK_F10] & 0x80) field058c = 0;
            if (state[DIK_F11] & 0x80) field0590 = 0;
            if (state[DIK_F12] & 0x80) {
                secondary[0]->field0108 = 1;
                secondary[1]->field0108 = 1;
            }
        }
        if (contextOwner->flag14283 == 1 && field0588 == 0) {
            if (contextOwner->flag1340 > 0) {
                field0574 = contextOwner->replayFile.ReadWord();
                field0576 = contextOwner->replayFile.ReadWord();
            } else {
                field0574 = 1000;
                field0576 = 9999;
            }
            secondary[0]->field30ec = field0574;
            secondary[1]->field30ec = field0574;
            secondary[0]->field30ee = field0576;
            secondary[1]->field30ee = field0576;
        } else if (contextOwner->flag14283 == 2 && field0588 == 0) {
            contextOwner->replayFile.WriteWord(field0574);
            contextOwner->replayFile.WriteWord(field0576);
        }
    }
}

void Scene3::ResetReplay()
{
    char path[40];
    char number[8];
    if (contextOwner->mode1364 == 5 && contextOwner->flag14283 == 2) {
        FadeOut(contextOwner->characterPalette, 0, 0, 0);
        contextOwner->replayFile.Close();
        std::strcpy(path, "replay\\data");
        _itoa(contextOwner->field14282 + 1, number, 10);
        std::strcat(path, number);
        std::strcat(path, "-");
        _itoa(contextOwner->field14281 + 1, number, 10);
        std::strcat(path, number);
        std::strcat(path, ".rep");
        contextOwner->replayFile.OpenWrite(path);
        contextOwner->replayFile.WriteWord((short)(*secondarySlotA)->characterId);
        contextOwner->replayFile.WriteWord((short)(*secondarySlotB)->characterId);
        contextOwner->replayFile.WriteWord(104);
        contextOwner->replayFile.WriteWord((short)contextOwner->flag0f32);
        contextOwner->replayFile.WriteWord((short)(*secondarySlotA)->paletteIndex);
        contextOwner->replayFile.WriteWord((short)(*secondarySlotB)->paletteIndex);
        contextOwner->ResetState();
        (*secondarySlotA)->LoadResources();
        (*secondarySlotB)->LoadResources();
        secondary[0]->field30ec = field0574;
        secondary[1]->field30ec = field0574;
        contextOwner->effectFlag1350 = 1;
        field0440 = 0;
        field0444 = -50;
        field0448 = field0440;
        field044c = field0444;
        field0450 = 5;
        field0454 = -160;
        field0458 = 0;
        field0578 = 3;
        UpdateCamera();
        Slot0();
        FadeIn(contextOwner->characterPalette, 0);
    }
}
