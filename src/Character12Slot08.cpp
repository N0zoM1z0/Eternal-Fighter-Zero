// EX Nanase original guarded transformation, effect pulse, and countdown.
#include "CharacterViews.h"

void Character12::Slot08()
{
    EffectSpawn effect;
    ResetLocalEffectSpawn(&effect);

    if (field3454 == 0 && meter == 3000 && health < 1666 &&
        health > 0 && (*opponentSlot)->health > 0 &&
        (int)(*opponentSlot)->field00ac + 1 == (int)(char)contextOwner->selection134e &&
        (int)field00ac + 1 == (int)(char)contextOwner->selection134e &&
        positionY == 0.0 && field0008 < 8 && field0008 != 0x140) {
        ResetPose();
        ResetFrame();
        field0008 = 0x140;
    }

    if (field3454 == 1) {
        meter = (short)(meter + 1);
        StartTrail(1);
        --field3150;
        ++field314c;
        if (field314c > 144)
            field314c = 0;
        if (field314c == 18)
            SetCharacterTint(0xd1, 27);
        if (field314c == 36)
            SetCharacterTint(0xd0, 27);
        if (field314c == 54)
            SetCharacterTint(0xcf, 27);
        if (field314c == 72)
            SetCharacterTint(0xb1, 27);
        if (field314c == 90)
            SetCharacterTint(0xcf, 27);
        if (field314c == 108)
            SetCharacterTint(0xd0, 27);
        if (field314c == 126)
            SetCharacterTint(0xd1, 27);
        if (field314c == 144)
            SetCharacterTint(0xd2, 27);
        if (field3150 <= 0) {
            if (field0008 < 50 || field0008 > 149) {
                effect.type = 0x22;
                effect.x = (double)((int)positionX +
                   (20 - (unsigned short)RandomRange(0,40)) * (int)facing);
                effect.y = (double)((int)positionY -
                   (unsigned short)RandomRange(0,90));
                effect.group = 2;
                effect.layer = 1;
                contextOwner->EmitEffect(&effect);
                field3150 = 2;
            }
        }
    }
}
