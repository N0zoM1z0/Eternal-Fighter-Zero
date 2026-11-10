// Unit-isolated original-size Nagamori view with one nonvirtual member.
// No global CharacterViews.h layout or other function dependencies are changed.
#ifndef EFZ_NAGAMORI_PROXIMITY_VIEW_H
#define EFZ_NAGAMORI_PROXIMITY_VIEW_H
#include "../../src/Engine.h"
class Character06 : public Secondary {
    int field3138, field313c, field3140, field3144, field3148;
    int field314c, field3150, field3154, field3158, field315c;
    int field3160, field3164, field3168;
    unsigned char field316c[64];
    int field31ac[64], field32ac[64], field33ac[64];
    unsigned char unknown_34ac[4];
public:
    Character06(Secondary **, Context *, Video *, Input *, Audio *, char);
    void MarkEffectCollision(short x, short y, short width, short height);
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
