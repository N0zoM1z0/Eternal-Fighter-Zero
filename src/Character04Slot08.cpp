// Native state-based passive countdown and effect behavior for Character04.
// This local typed view preserves the original base character layout while
// the still-unreviewed Character04 class-specific fields are mapped.
#include "CharacterViews.h"

struct Character04Fields {
    unsigned char base[0x3138];
    int field3138, field313c, field3140, field3144;
    int field3148, field314c, field3150, field3154;
};

void Character04::Slot08()
{
    EffectSpawn effect;
    ResetLocalEffectSpawn(&effect);
    if (reinterpret_cast<Character04Fields *>(this)->field3148 > 0) {
        --reinterpret_cast<Character04Fields *>(this)->field3148;
        if (reinterpret_cast<Character04Fields *>(this)->field3144 == 3)
            --reinterpret_cast<Character04Fields *>(this)->field3148;
        if (reinterpret_cast<Character04Fields *>(this)->field3150 == 1)
            reinterpret_cast<Character04Fields *>(this)->field3148 -= 4;
        if (reinterpret_cast<Character04Fields *>(this)->field3150 == 2)
            ++reinterpret_cast<Character04Fields *>(this)->field3148;
        if (reinterpret_cast<Character04Fields *>(this)->field3150 == 3)
            --reinterpret_cast<Character04Fields *>(this)->field3148;
        if (reinterpret_cast<Character04Fields *>(this)->field3150 == 4)
            --reinterpret_cast<Character04Fields *>(this)->field3148;
    }
    if (reinterpret_cast<Character04Fields *>(this)->field3144 == 4) {
        meter = 0;
        contextOwner->SetSceneTimer(3);
    }
    if (reinterpret_cast<Character04Fields *>(this)->field3148 <= 0) {
        if (reinterpret_cast<Character04Fields *>(this)->field3144 == 3) {
            effect.type = 1;
            effect.palette = 11;
            effect.x = (double)(int)positionX;
            effect.y = (double)(int)(positionY - 40.0);
            effect.group = 2;
            effect.layer = 1;
            contextOwner->EmitEffect(&effect);
            reinterpret_cast<Character04Fields *>(this)->field3144 = 0;
            reinterpret_cast<Character04Fields *>(this)->field3148 = 0;
            reinterpret_cast<Character04Fields *>(this)->field314c = 0;
            reinterpret_cast<Character04Fields *>(this)->field3150 = 0;
        }
        if (reinterpret_cast<Character04Fields *>(this)->field3144 == 4 && field0008 != 324 && field0008 != 325) {
            reinterpret_cast<Character04Fields *>(this)->field3148 = 1200;
            reinterpret_cast<Character04Fields *>(this)->field3144 = 3;
            reinterpret_cast<Character04Fields *>(this)->field314c = 0;
            reinterpret_cast<Character04Fields *>(this)->field3150 = 2;
        }
    }
}
