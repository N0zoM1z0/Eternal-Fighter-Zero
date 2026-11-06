// Mizuka partial object view and reviewed virtual contracts.
#ifndef EFZ_CHARACTER24_H
#define EFZ_CHARACTER24_H
#include "CharacterViews.h"
class Character24 : public Secondary {
    int field3138, field313c, field3140, field3144;
    int field3148[64], field3248[64], field3348[64];
    int field3448, field344c, field3450, field3454, field3458;
public:
    Character24(Secondary **, Context *, Video *, Input *, Audio *, char);
    virtual void ResetPose();
    virtual void Slot01();
    virtual void Slot02();
    virtual void Slot03();
    virtual void Slot04();
    virtual void Slot05();
    virtual void Slot06();
    virtual void Slot07();
    virtual void Slot08();
    virtual void EmitLocalEffect(SecondaryEffectSpawn *);
    virtual void RemoveLocalEffect(short);
    virtual void InitializeState();
};
#endif
