// Battle scene fields follow complete target constructor accesses.
#include "SceneBattle.h"
extern SurfaceRect __cdecl MakeSurfaceRect(int, int, int, int);
Scene3::Scene3(HWND handle, Secondary **first, Secondary **second, Context *context, Video *video, Input *input, Audio *audio)
: Scene(handle, first, second, context, video, input, audio)
{
    field0440 = 0;
    field0444 = -50;
    field0448 = field0440;
    field044c = field0444;
    field0450 = 5;
    field0454 = -160;
    field0458 = 0;
    phase = 1;
    flag002d = 0;
    field0574 = 0;
    field0576 = 9999;
    field0578 = 3;
    field0588 = 0;
    field0580 = 0.0;
    field058c = 0;
    field0590 = 0;
    field0434 = 0;
    field0438 = 0;
    field043c = 0;
    contextOwner->counter1354 = 0;
    contextOwner->effectFlag1350 = 1;
    numberStyles[0] = MakeSurfaceRect(0,0xea,8,10);
    numberStyles[1] = MakeSurfaceRect(0,0xd2,0x10,0xf);
    numberStyles[2] = MakeSurfaceRect(0,0xe1,7,9);
    numberStyles[3] = MakeSurfaceRect(0,0x11a,0xe,0x16);
    numberStyles[4] = MakeSurfaceRect(0,0x160,8,0xc);
    numberStyles[5] = MakeSurfaceRect(0,0x154,8,0xc);
    numberStyles[6] = MakeSurfaceRect(0,0x148,8,0xc);
    numberStyles[7] = MakeSurfaceRect(0,0x13c,8,0xc);
    numberStyles[8] = MakeSurfaceRect(0,0x130,8,0xc);
    numberStyles[9] = MakeSurfaceRect(0,0x16c,7,10);
    numberStyles[10] = MakeSurfaceRect(0,0x176,7,10);
    numberStyles[11] = MakeSurfaceRect(0,0x180,7,10);
    numberStyles[12] = MakeSurfaceRect(0,0x18a,7,10);
    numberStyles[13] = MakeSurfaceRect(0,0x194,7,10);
    numberStyles[14] = MakeSurfaceRect(0,0x19e,7,10);
    numberStyles[15] = MakeSurfaceRect(0,0x1a8,7,10);
    numberStyles[16] = MakeSurfaceRect(0,0x1b2,7,10);
}

void Scene3::UpdateCamera()
{
    int y;
    int x;
    field0448 = field0440;
    if (contextOwner->state14240 > 0) {
        field0448 = contextOwner->state14238;
        if (secondary[0]->field014a == 0 && secondary[1]->field014a == 0 &&
            secondary[0]->field014c == 0 && secondary[1]->field014c == 0) {
            --contextOwner->state14240;
        }
    }
    x = 160 - (int)((secondary[0]->positionX * (field0448 + 50) + secondary[1]->positionX * (50 - field0448)) / 100.0);
    if (x < -319) x = -319;
    else if (x > 0) x = 0;
    if (field0454 < x) {
        field0454 -= (field0454 - x) / 15 - 1;
        if (field0454 > x) field0454 = x;
    } else {
        field0454 -= (field0454 - x) / 15 + 1;
        if (field0454 < x) field0454 = x;
    }
    if (field044c < field0444) {
        field044c += field0450;
        if (field044c > field0444) field044c = field0444;
    } else {
        field044c += field0450;
        if (field044c > field0444) field044c = field0444;
    }
    if (secondary[0]->positionY < -240.0 || secondary[1]->positionY < -240.0) {
        field044c = field0444;
    } else {
        field044c = 20;
    }
    if (contextOwner->state14244 > 0) {
        field044c = contextOwner->state1423c * (1 - (secondary[0]->positionY < secondary[1]->positionY) * 2);
        if (secondary[0]->field014a == 0 && secondary[1]->field014a == 0 &&
            secondary[0]->field014c == 0 && secondary[1]->field014c == 0) {
            --contextOwner->state14244;
        }
    }
    y = -(((int)secondary[0]->positionY - (secondary[0]->positionY < 0.0) + (int)secondary[1]->positionY - (secondary[1]->positionY < 0.0)) / 2)
        + (((int)secondary[0]->positionY - (secondary[0]->positionY < 0.0) - (int)secondary[1]->positionY + (secondary[1]->positionY < 0.0)) * field044c / 100)
          * ((secondary[0]->positionY - secondary[1]->positionY < 0.0) * 2 - 1);
    if (y < 0) y = 0;
    else if (y > 240) y = 240;
    if (field0458 < y) {
        field0458 -= (field0458 - y) / 10 - 1;
        if (field0458 > y) field0458 = y;
    } else {
        field0458 -= (field0458 - y) / 10 + 1;
        if (field0458 < y) field0458 = y;
    }
    contextOwner->UpdateCameraShake();
    contextOwner->cameraBounds = MakeSurfaceRect(-field0454, -field0458 - 210, 320, 240);
    field045c = field0454 + contextOwner->state1421c;
    field0460 = field0458 + contextOwner->state14220;
}

void Scene3::PlayCharacterSounds()
{
    if (flag002d == 2) {
        for (int i = 0; i < 2; ++i) {
            secondary[i]->field02c9 = -1;
            secondary[i]->field02c8 = -1;
        }
    } else {
        for (int i = 0; i < 2; ++i) {
            if (secondary[i]->field02c9 >= 0 && secondary[i]->field02c9 < 65) {
                audioOwner->StartSound(contextOwner->soundSlots[secondary[i]->field02c9], 0);
                secondary[i]->field02c9 = -1;
            }
            if (secondary[i]->field02c8 >= 0 && secondary[i]->field02c8 < 50) {
                audioOwner->StartSound(secondary[i]->soundSlots[secondary[i]->field02c8], 0);
                secondary[i]->field02c8 = -1;
            }
        }
    }
}

void Scene3::PlayEffectSounds()
{
    int clearIndex;
    int soundIndex;
    if (flag002d == 2) {
        clearIndex = contextOwner->field1382;
        while (clearIndex != contextOwner->field1380) {
            contextOwner->effects[clearIndex].palette = 255;
            ++clearIndex;
            if (clearIndex >= 640) clearIndex = 0;
        }
    } else {
        soundIndex = contextOwner->field1382;
        while (soundIndex != contextOwner->field1380) {
            if ((char)contextOwner->effects[soundIndex].palette >= 0 && (char)contextOwner->effects[soundIndex].palette < 65) {
                audioOwner->StartSound(contextOwner->soundSlots[(char)contextOwner->effects[soundIndex].palette], 0);
                contextOwner->effects[soundIndex].palette = 255;
            }
            ++soundIndex;
            if (soundIndex >= 640) soundIndex = 0;
        }
    }
}

void Scene3::UpdateIntro()
{
    if (contextOwner->effectFlag1350 == 0) return;
    EffectSpawn effect;
    switch (contextOwner->effectFlag1350) {
    case 1:
        effect.owner = 0;
        effect.x = 160.0;
        effect.y = 120.0;
        effect.facing = 0;
        effect.group = 2;
        effect.layer = 2;
        effect.payload = 1;
        effect.type = 27;
        effect.palette = 255;
        contextOwner->EmitEffect(&effect);
        contextOwner->effectFlag1350 = 99;
        contextOwner->state1352 = 300;
        break;
    case 2:
        effect.owner = 0;
        effect.x = 160.0;
        effect.y = 120.0;
        effect.facing = 0;
        effect.group = 2;
        effect.layer = 2;
        effect.payload = 1;
        effect.type = 5;
        effect.palette = contextOwner->effectSelector + 11;
        contextOwner->EmitEffect(&effect);
        contextOwner->effectFlag1350 = 99;
        contextOwner->state1352 = 270;
        break;
    }
}
