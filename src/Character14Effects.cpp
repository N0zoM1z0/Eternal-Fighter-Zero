// Ikumi's independent animation-300 and EX-mode effect owner.
// Complete natural C++ owner, restored from all original state/effect branches.
#include "CharacterViews.h"
#include <cstdlib>

void Character14::Slot08()
{
    EffectSpawn effect;
    ResetLocalEffectSpawn(&effect);

    if (field314c == 8 && positionY == 0.0 && field0008 < 8 && field0008 != 300) {
        ResetPose();
        ResetFrame();
        field0008 = 300;
    }
    if (field314c == 10) {
        ++field3158;
        if (field3158 > 185) {
            field3158 = 0;
        }
        --field3150;
        field0138 = 2;
        field013a = 2;
        StartTrail(2);
        if (field3158 == 6) SetCharacterTint(0xd5, 9);
        if (field3158 == 12) SetCharacterTint(0xd6, 9);
        if (field3158 == 18) SetCharacterTint(0xea, 9);
        if (field3158 == 24) SetCharacterTint(0xe9, 9);
        if (field3158 == 30) SetCharacterTint(0xe8, 9);
        if (field3158 == 36) SetCharacterTint(0xe7, 9);
        if (field3158 == 42) SetCharacterTint(0xe6, 9);
        if (field3158 == 48) SetCharacterTint(0xe5, 9);
        if (field3158 == 54) SetCharacterTint(0xe4, 9);
        if (field3158 == 60) SetCharacterTint(0xe5, 9);
        if (field3158 == 66) SetCharacterTint(0xe6, 9);
        if (field3158 == 72) SetCharacterTint(0xe7, 9);
        if (field3158 == 78) SetCharacterTint(0xe8, 9);
        if (field3158 == 84) SetCharacterTint(0xe9, 9);
        if (field3158 == 90) SetCharacterTint(0xea, 9);
        if (field3158 == 96) SetCharacterTint(0xd6, 9);
        if (field3158 == 102) SetCharacterTint(0xd5, 9);
        if (field3150 <= 0) {
            field314c = 0;
            field3148 = 0;
            SetAlternateMode(0);
        }
    }
    if (attackCollisionResult == 3 && field3154 == 0) {
        if (field0008 == 201 || field0008 == 202 ||
            field0008 == 205 || field0008 == 208) {
            effect.type = 0x1d6;
            effect.x = (double)(int)(*opponentSlot)->positionX;
            effect.y = (*opponentSlot)->positionY - 40.0;
            effect.group = 0;
            effect.layer = 1;
            effect.flag0018 = facing;
            EmitLocalEffect(&effect);
            ++field3154;
        }
        if (field0008 == 231 || field0008 == 234) {
            effect.type = 0x1de;
            effect.x = (double)(int)(*opponentSlot)->positionX;
            effect.y = (*opponentSlot)->positionY - 40.0;
            effect.group = 0;
            effect.layer = 1;
            effect.flag0018 = facing;
            EmitLocalEffect(&effect);
            ++field3154;
        }
        if (field0008 == 253 || field0008 == 254 ||
            field0008 == 256 || field0008 == 257) {
            effect.type = 0x1d7;
            effect.x = (double)(int)(*opponentSlot)->positionX;
            effect.y = (*opponentSlot)->positionY - 40.0;
            effect.group = 0;
            effect.layer = 1;
            effect.flag0018 = facing;
            EmitLocalEffect(&effect);
            ++field3154;
        }
        if (field0008 == 266 || field0008 == 255 || field0008 == 267 ||
            field0008 == 258 || field0008 == 272 || field0008 == 273) {
            effect.type = 0x1df;
            effect.x = (double)(int)(*opponentSlot)->positionX;
            effect.y = (*opponentSlot)->positionY - 40.0;
            effect.group = 0;
            effect.layer = 1;
            effect.flag0018 = facing;
            EmitLocalEffect(&effect);
            ++field3154;
        }
        if (field0008 == 269 || field0008 == 270 ||
            field0008 == 276 || field0008 == 277) {
            effect.type = 0x1e0;
            effect.x = (double)(int)(*opponentSlot)->positionX;
            effect.y = (*opponentSlot)->positionY - 40.0;
            effect.group = 0;
            effect.layer = 1;
            effect.flag0018 = facing;
            EmitLocalEffect(&effect);
            ++field3154;
        }
    }
}
