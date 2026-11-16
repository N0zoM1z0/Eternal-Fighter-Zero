// Character01's native reset, effects and locomotion leaf implementations.
#include "CharacterViews.h"

// One extra child word at 0x314C shifts the three effect arrays by +4 bytes.
struct Character01LifecycleFields {
    unsigned char inherited[0x3138];
    int field3138, field313c, field3140, field3144, field3148, field314c;
    int localEffectA[64], localEffectB[64], localEffectC[64];
};
#define C01 (reinterpret_cast<Character01LifecycleFields *>(this))

void Character01::ResetPose()
{
    C01->field3138 = 0;
    C01->field313c = 0;
    C01->field3140 = 0;
    Secondary::ResetPose();
}

void Character01::RemoveLocalEffect(short index)
{
    C01->localEffectA[index] = 0;
    C01->localEffectB[index] = 0;
    C01->localEffectC[index] = 0;
    Secondary::RemoveLocalEffect(index);
}

void Character01::Slot03()
{
    UpdateLocomotionState();
}

void Character01::EmitLocalEffect(SecondaryEffectSpawn *spawn)
{
    RemoveLocalEffect(effectWrite);
    Secondary::EmitLocalEffect(spawn);
}

void Character01::Slot01()
{
}

void Character01::Slot08()
{
}
#undef C01
