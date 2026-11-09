// Partial original object views with allocation extents and observed virtual overrides.
#ifndef EFZ_CHARACTER_VIEWS_H
#define EFZ_CHARACTER_VIEWS_H
#include "Engine.h"
class Character00 : public Secondary {
    unsigned char unknown_body[0x3470 - sizeof(Secondary)];
public:
    Character00(Secondary **, Context *, Video *, Input *, Audio *, char);
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
    virtual void LoadResources();
    virtual void InitializeState();
};
class Character01 : public Secondary {
    unsigned char unknown_body[0x3450 - sizeof(Secondary)];
public:
    Character01(Secondary **, Context *, Video *, Input *, Audio *, char);
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
class Character02 : public Secondary {
    unsigned char unknown_body[0x3458 - sizeof(Secondary)];
public:
    Character02(Secondary **, Context *, Video *, Input *, Audio *, char);
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
class Character03 : public Secondary {
    int field3138;
    int field313c;
    int field3140;
    int field3144;
    int field3148;
    int field314c[64];
    int field324c[64];
    int field334c[64];
    unsigned char unknown_344c[4];
public:
    Character03(Secondary **, Context *, Video *, Input *, Audio *, char);
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
class Character04 : public Secondary {
    unsigned char unknown_body[0x3450 - sizeof(Secondary)];
public:
    Character04(Secondary **, Context *, Video *, Input *, Audio *, char);
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
class Character05 : public Secondary {
public:
    int field3138;
    int field313c;
    int field3140;
    int field3144;
    int field3148[64];
    int field3248[64];
    int field3348[64];
    Character05(Secondary **, Context *, Video *, Input *, Audio *, char);
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
class Character06 : public Secondary {
    unsigned char unknown_body[0x34b0 - sizeof(Secondary)];
public:
    Character06(Secondary **, Context *, Video *, Input *, Audio *, char);
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
class Character07 : public Secondary {
    int field3138, field313c, field3140, field3144;
    int field3148[64], field3248[64], field3348[64];
public:
    Character07(Secondary **, Context *, Video *, Input *, Audio *, char);
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
class Character08 : public Secondary {
    int field3138, field313c, field3140, field3144, field3148, field314c, field3150, field3154;
    int field3158[64], field3258[64], field3358[64];
public:
    Character08(Secondary **, Context *, Video *, Input *, Audio *, char);
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
class Character09 : public Secondary {
    unsigned char unknown_body[0x3458 - sizeof(Secondary)];
public:
    Character09(Secondary **, Context *, Video *, Input *, Audio *, char);
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
class Character10 : public Secondary {
    unsigned char unknown_body[0x3460 - sizeof(Secondary)];
public:
    Character10(Secondary **, Context *, Video *, Input *, Audio *, char);
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
class Character11 : public Secondary {
    unsigned char unknown_body[0x3458 - sizeof(Secondary)];
public:
    Character11(Secondary **, Context *, Video *, Input *, Audio *, char);
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
class Character12 : public Secondary {
    int field3138, field313c, field3140, field3144, field3148, field314c, field3150;
    int field3154[64], field3254[64], field3354[64];
    int field3454;
    unsigned char unknown_3458[8];
    unsigned char field3460;
    unsigned char unknown_3461[7];
public:
    Character12(Secondary **, Context *, Video *, Input *, Audio *, char);
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
class Character13 : public Secondary {
    int field3138, field313c, field3140, field3144, field3148;
    int field314c[64], field324c[64], field334c[64];
    unsigned char unknown_344c[4];
public:
    Character13(Secondary **, Context *, Video *, Input *, Audio *, char);
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
class Character14 : public Secondary {
    unsigned char unknown_body[0x3478 - sizeof(Secondary)];
public:
    Character14(Secondary **, Context *, Video *, Input *, Audio *, char);
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
    virtual void LoadResources();
    virtual void InitializeState();
};
class Character15 : public Secondary {
    int field3138, field313c, field3140, field3144, field3148, field314c;
    int field3150, field3154, field3158, field315c, field3160, field3164;
    int field3168, field316c, field3170;
    int field3174[64], field3274[64], field3374[64];
public:
    Character15(Secondary **, Context *, Video *, Input *, Audio *, char);
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
class Character16 : public Secondary {
    int field3138, field313c, field3140, field3144, field3148;
    int field314c, field3150, field3154, field3158, field315c, field3160;
    int field3164[64], field3264[64], field3364[64];
    unsigned char unknown_3464[4];
public:
    Character16(Secondary **, Context *, Video *, Input *, Audio *, char);
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
class Character17 : public Secondary {
    int field3138, field313c, field3140, field3144;
    int field3148, field314c, field3150, field3154;
    int field3158[64], field3258[64], field3358[64];
public:
    Character17(Secondary **, Context *, Video *, Input *, Audio *, char);
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
class Character18 : public Secondary {
    int field3138, field313c, field3140, field3144;
    int field3148[64], field3248[64], field3348[64];
    int field3448, field344c, field3450, field3454, field3458, field345c;
public:
    Character18(Secondary **, Context *, Video *, Input *, Audio *, char);
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
class Character19 : public Secondary {
    int field3138, field313c, field3140, field3144, field3148;
    unsigned char unknown_314c[8];
    int field3154[64], field3254[64], field3354[64];
    unsigned char unknown_3454[4];
public:
    Character19(Secondary **, Context *, Video *, Input *, Audio *, char);
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
class Character20 : public Secondary {
    int field3138, field313c, field3140, field3144, field3148;
    int field314c, field3150, field3154, field3158, field315c;
    int field3160, field3164, field3168, field316c, field3170;
    int field3174[64], field3274[64], field3374[64];
    unsigned char unknown_3474[4];
public:
    Character20(Secondary **, Context *, Video *, Input *, Audio *, char);
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
class Character21 : public Secondary {
    int field3138, field313c, field3140, field3144;
    int field3148, field314c, field3150;
    int field3154[64], field3254[64], field3354[64];
    unsigned char unknown_3454[4];
public:
    Character21(Secondary **, Context *, Video *, Input *, Audio *, char);
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
class Character23 : public Secondary {
    int field3138, field313c, field3140, field3144, field3148, field314c, field3150, field3154;
    int field3158[64], field3258[64], field3358[64];
    int field3458, field345c, field3460, field3464, field3468, field346c;
    int field3470, field3474, field3478, field347c, field3480;
public:
    Character23(Secondary **, Context *, Video *, Input *, Audio *, char);
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
