// Reviewed animated background object views.
#ifndef EFZ_BACKGROUNDS_H
#define EFZ_BACKGROUNDS_H
#include "Engine.h"
class BattleBackground {
public:
    virtual void Update() = 0;
    virtual void Render(int, int, char) = 0;
protected:
    short stage, lastSurface;
    Video *videoOwner;
    IUnknown **surfaces;
    EffectSlot *effects;
    PatternSequence *patterns;
    unsigned char colorKey;
public:
    void LoadImages();
    void LoadPatterns();
};
#define DECLARE_BACKGROUND(Name) \
class Name : public BattleBackground { \
public: Name(Video *); ~Name(); \
    virtual void Update(); virtual void Render(int, int, char); \
};
DECLARE_BACKGROUND(Background01)
DECLARE_BACKGROUND(Background10)
DECLARE_BACKGROUND(Background12)
DECLARE_BACKGROUND(Background16)
#undef DECLARE_BACKGROUND
#endif
