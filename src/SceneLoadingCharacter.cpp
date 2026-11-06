// Loading scene character creation dispatcher.
#include "CharacterViews.h"
#include <cstring>
extern const char mizukaResourceName[];

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



void Scene2::LoadCharacter(Secondary **created, Secondary **opponent, char player, char character)
{
    switch (character) {
    case 0: *created = new Character00(opponent, contextOwner, videoOwner, inputOwner, audioOwner, player); break;
    case 1: *created = new Character01(opponent, contextOwner, videoOwner, inputOwner, audioOwner, player); break;
    case 2: *created = new Character02(opponent, contextOwner, videoOwner, inputOwner, audioOwner, player); break;
    case 3: *created = new Character03(opponent, contextOwner, videoOwner, inputOwner, audioOwner, player); break;
    case 4: *created = new Character04(opponent, contextOwner, videoOwner, inputOwner, audioOwner, player); break;
    case 5: *created = new Character05(opponent, contextOwner, videoOwner, inputOwner, audioOwner, player); break;
    case 6: *created = new Character06(opponent, contextOwner, videoOwner, inputOwner, audioOwner, player); break;
    case 7: *created = new Character07(opponent, contextOwner, videoOwner, inputOwner, audioOwner, player); break;
    case 8: *created = new Character08(opponent, contextOwner, videoOwner, inputOwner, audioOwner, player); break;
    case 9: *created = new Character09(opponent, contextOwner, videoOwner, inputOwner, audioOwner, player); break;
    case 10: *created = new Character10(opponent, contextOwner, videoOwner, inputOwner, audioOwner, player); break;
    case 11: *created = new Character11(opponent, contextOwner, videoOwner, inputOwner, audioOwner, player); break;
    case 12: *created = new Character12(opponent, contextOwner, videoOwner, inputOwner, audioOwner, player); break;
    case 13: *created = new Character13(opponent, contextOwner, videoOwner, inputOwner, audioOwner, player); break;
    case 14: *created = new Character14(opponent, contextOwner, videoOwner, inputOwner, audioOwner, player); break;
    case 15: *created = new Character15(opponent, contextOwner, videoOwner, inputOwner, audioOwner, player); break;
    case 16: *created = new Character16(opponent, contextOwner, videoOwner, inputOwner, audioOwner, player); break;
    case 17: *created = new Character17(opponent, contextOwner, videoOwner, inputOwner, audioOwner, player); break;
    case 18: *created = new Character18(opponent, contextOwner, videoOwner, inputOwner, audioOwner, player); break;
    case 19: *created = new Character19(opponent, contextOwner, videoOwner, inputOwner, audioOwner, player); break;
    case 20: *created = new Character20(opponent, contextOwner, videoOwner, inputOwner, audioOwner, player); break;
    case 21: *created = new Character21(opponent, contextOwner, videoOwner, inputOwner, audioOwner, player); break;
    case 22: *created = new Character10(opponent, contextOwner, videoOwner, inputOwner, audioOwner, player); break;
    case 23: *created = new Character23(opponent, contextOwner, videoOwner, inputOwner, audioOwner, player); break;
    case 24: *created = new Character24(opponent, contextOwner, videoOwner, inputOwner, audioOwner, player); break;
    }
    (*created)->characterId = character;
    secondary[player] = *created;
    (*created)->cpuControlled = contextOwner->cpuPlayer[player];
}

Character24::Character24(Secondary **opponent, Context *context, Video *video,
    Input *input, Audio *audio, char player)
    : Secondary(opponent, context, video, input, audio, player)
{
    std::strcpy(resourceName, mizukaResourceName);
    surfaceCount = 668;
    field3138 = 0;
    field313c = 0;
    field3140 = 0;
    field3144 = 0;
    field2ad0[0] = -13;
    field2af8[0] = -60;
    field2ad0[1] = 14;
    field2af8[1] = 0;
    field3448 = 0;
    field344c = 0;
    field3450 = 0;
    field3454 = 0;
    field3458 = 0;
    commandCount = 6;
    commands[0] = 6;
    commands[1] = 1;
    commands[2] = 7;
    commands[10] = 18;
    for (int i = 0; i < 64; ++i) {
        field3148[i] = 0;
        field3248[i] = 0;
        field3348[i] = 0;
    }
}
