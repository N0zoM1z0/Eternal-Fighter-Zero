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
    int field3138, field313c, field3140, field3144, field3148;
    int field314c[64], field324c[64], field334c[64];
    unsigned char unknown_344c[12];
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
typedef char Character02ExtentMustMatchNativeAllocation[(sizeof(Character02) == 0x3458) ? 1 : -1];
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
    int field3138, field313c, field3140, field3144, field3148;
    int field314c, field3150, field3154, field3158, field315c;
    int field3160, field3164, field3168;
    unsigned char field316c[64];
    int field31ac[64], field32ac[64], field33ac[64];
    unsigned char unknown_34ac[4];
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
    int field3138, field313c, field3140, field3144, field3148, field314c, field3150;
    int field3154[64], field3254[64], field3354[64];
    unsigned char unknown_3454[4];
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
    int field3138, field313c, field3140, field3144, field3148;
    int field314c, field3150, field3154, field3158;
    int field315c[64], field325c[64], field335c[64];
    unsigned char unknown_345c[4];
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
    int field3138;
    unsigned char unknown_313c[4];
    double field3140, field3148;
    int field3150, field3154;
    int field3158[64], field3258[64], field3358[64];
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
    int field3138, field313c, field3140, field3144, field3148;
    int field314c, field3150, field3154, field3158, field315c;
    int field3160[64], field3260[64], field3360[64];
    unsigned char alternateMode;
    unsigned char unknown_3461[3];
    PatternSequence *alternatePatterns;
    SecondarySequence *alternateSequences;
    PatternSequence *savedPatterns;
    SecondarySequence *savedSequences;
    unsigned char unknown_3474[4];
public:
    Character14(Secondary **, Context *, Video *, Input *, Audio *, char);
    ~Character14();
    void SetAlternateMode(char);
    void LoadAlternatePatterns();
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
    int field314c, field3150;
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
    void UpdateLocomotionState();
    int Slot06TryAirAction();
    void Slot06UpdateAirMovement(unsigned short, unsigned short, unsigned short, double, double, unsigned short, int);
    void Slot06UpdateCounterMove(unsigned short, unsigned short, short, double, double, int);
    int Slot06OpponentWithinKnockbackRange();
    void Slot06UpdateKnockbackLanding(unsigned short, unsigned short, int);
    void Slot06UpdateGroundRecovery(unsigned short, unsigned short, int);
    void Slot06UpdateGroundSkid(unsigned short, unsigned short, int);
    void Slot06UpdateAirKnockback(unsigned short, unsigned short, SecondaryEffectSpawn *);
    void Slot06UpdateRepeatedAirKnockback(unsigned short, unsigned short);
    void Slot06UpdateAirborneRebound(unsigned short, unsigned short, SecondaryEffectSpawn *);
    void Slot06UpdateAirborneKnockbackLanding(unsigned short, unsigned short, SecondaryEffectSpawn *, unsigned short, double, int, int);
    void Slot06UpdateLocalEffectRecovery(unsigned short, unsigned short, SecondaryEffectSpawn *);
    void Slot06UpdateFaceRecovery(unsigned short, unsigned short);
    void Slot06UpdateDefeatImpact(unsigned short, unsigned short, EffectSpawn *);
    void Slot06UpdateDefeatWait(unsigned short, unsigned short);
    void Slot06UpdateHorizontalRecovery(unsigned short, unsigned short, short, double, int);
    void Slot06UpdateAirborneKnockdown(unsigned short, unsigned short, EffectSpawn *, double, double, double, short, int, int, int, int);
    void Slot06UpdateAirborneBounce(unsigned short, unsigned short, unsigned char, unsigned short, double, double, double, double, int, int);
    void Slot06UpdateAirborneFollowup(unsigned short, unsigned short, unsigned short, double);
    void Slot06UpdateDefeatImpactEffect(unsigned short, unsigned short, EffectSpawn *);
    void Slot06UpdateKnockbackImpactFinish(unsigned short, unsigned short, EffectSpawn *, unsigned short);
    void Slot06UpdateAirborneHitstunRestore(unsigned short, unsigned short);
    void Slot06UpdateDefeatImpactVelocityRestore(unsigned short, unsigned short, EffectSpawn *);
    void Slot06UpdateDashRecovery(unsigned short, unsigned short);
    void Slot06UpdateDashAttack(unsigned short, unsigned short, EffectSpawn *, double, int, unsigned short, short, unsigned short, unsigned short, unsigned short, int, int);
    void Slot06UpdateDashAttackSustain(unsigned short, unsigned short);
    void Slot06UpdateAirborneDashFollowup(unsigned short, unsigned short, EffectSpawn *, unsigned short, short, unsigned short, unsigned short, unsigned short, unsigned short, unsigned short, unsigned short, unsigned short);
    void Slot06UpdateKnockbackFall(unsigned short, unsigned short, double, int, double, double, int);
    void Slot06Case03();
    void Slot06Case04();
    void Slot06Case05();
    void Slot06Case08();
    void Slot06Case09();
    void Slot06Case70();
    void Slot06Case71();
    void Slot06Case72();
    void Slot06Case73();
    void Slot06Case74();
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
