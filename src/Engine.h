// Provisional EFZ layouts; unknown storage is data, never code padding.
#ifndef EFZ_ENGINE_H
#define EFZ_ENGINE_H
#include <windows.h>
#include <unknwn.h>
#include <ddraw.h>
#include <dsound.h>
#include <mmsystem.h>
struct SurfaceRect { int left, top, right, bottom; };
class Video {
    HWND window;
    unsigned char flag0004;
    PALETTEENTRY paletteEntries[256];
    unsigned char meanBlend[256][256];
    unsigned char sumBlend[256][256];
    unsigned char unknown_20405;
    unsigned short squaredDifference[512];
    unsigned char unknown_20806[2];
    IDirectDraw *directDraw;
    IDirectDrawSurface *primarySurface, *backSurface;
    IDirectDrawPalette *paletteInterface;
public:
    Video();
    ~Video();
    int Initialize(HWND, unsigned char);
    int Recreate8Bit();
    int Recreate16Bit();
    int RequestClose();
    void ReleaseSurface(IUnknown **);
    int RestorePrimarySurface();
    int RestoreSurface(IUnknown **);
    void Shutdown();
    int DecodeSurface(IUnknown **, const unsigned char *, unsigned char, unsigned char);
    int DecodeCharacterSurface(IUnknown **, const unsigned char *, unsigned char, unsigned char);
    SurfaceRect LoadBitmapSurface(IUnknown **, const char *, unsigned char);
    SurfaceRect LoadSurface(IUnknown **, const char *, unsigned char);
    int LoadPalette(unsigned char *, const char *, int, int, int);
    int LoadBitmapPalette(unsigned char *, const char *, int, int, int);
    unsigned char SurfaceProperty(IUnknown *);
    void BuildBlendTables(unsigned char *);
    void DarkenPalette(const unsigned char *, unsigned char, unsigned char, unsigned char);
    void LightenPalette(const unsigned char *, unsigned char, unsigned char, unsigned char);
    int ApplyPalette(unsigned char *);
    int ApplyPaletteRange(unsigned char *, unsigned char, unsigned char);
    int ClearPaletteRGB(unsigned char *);
    int Present();
    void SaveScreenshot(int, const unsigned char *);
    int FillRectangle(SurfaceRect, unsigned char);
    int ConvertBackBuffer();
    int DrawSurface(SurfaceRect, IUnknown *, SurfaceRect, unsigned char, int);
    int DrawShadowSurface(SurfaceRect, IUnknown *, SurfaceRect, unsigned char, int, unsigned char);
    int DrawBlendedSurface(SurfaceRect, IUnknown *, SurfaceRect, unsigned char, int, int);
    int DrawCharacterTint(SurfaceRect, IUnknown *, SurfaceRect, unsigned char, int, char);
    int DrawCharacterSpecial(SurfaceRect, IUnknown *, SurfaceRect, unsigned char, int);
};
#include "Input.h"
class Audio {
    DWORD loopStart, loopEnd;
    HWND window;
    IDirectSound *directSound;
    unsigned char *samples[150];
    DWORD sampleSizes[150];
    IDirectSoundBuffer *buffers[150];
public:
    void Initialize(HWND);
    Audio();
    ~Audio();
    void MaintainLoop(unsigned short);
    void FillBuffer(unsigned short);
    void ReleaseBuffer(unsigned short);
    void CreateBuffer(unsigned short, const WAVEFORMATEX *);
    unsigned short FindFreeSlot();
    unsigned short LoadWave(const char *);
    void ReadLoopMarkers(const char *);
    void ReleaseSound(unsigned short);
    void StopSound(unsigned short);
    void StartSound(unsigned short, int);
    void SetSoundVolume(unsigned short, int);
    void Shutdown();
};
class Context;
class PatternSequence;
struct SecondaryEffectSpawn;
struct SecondaryFrame {
    SurfaceRect hurtBoxes[5], attackBoxes[4], bodyBox;
    short damage;
    unsigned char unknown_00a2[2];
    float comboDamageScale;
    short guardDamage;
    unsigned short attackFlags;
    short airHitState, groundHitState;
    unsigned short frameFlags;
    short airActionLockFrames, hitMeterGain, guardMeterGain;
    float outgoingPushbackVelocityX, outgoingPushbackVelocityY;
    char hitEffectType, hitEffectPalette;
    short attackerHitstopFrames, defenderHitstopFrames;
    unsigned char unknown_00c6[2];
};
class SecondarySequence {
public:
    short field0000, field0002;
    SecondaryFrame *data;
    SecondarySequence();
    ~SecondarySequence();
    void Allocate(int);
};
class SecondaryPose;
class SecondaryTrail {
public:
    unsigned char pending;
    unsigned char stride;
    unsigned char held;
    unsigned char unknown_0003[5];
    double x[60], y[60];
    char facing[60];
    unsigned short type[60], frame[60];
    short position;
    unsigned char unknown_04f6[2];
    SecondaryTrail();
    void FinishSample();
    void Capture(const SecondaryPose *);
    void Begin(const SecondaryPose *, unsigned char);
};
struct SecondaryEffectSlot {
    unsigned short type, frame, tick;
    unsigned char unknown_0006[2];
    PatternSequence *patterns;
    unsigned char unknown_000c[0xc];
    double x, y, vx, vy, ax, ay;
    char flag0048;
    unsigned char unknown_0049[3];
    int facing;
    char group;
    unsigned char layer;
    unsigned char unknown_0052[2];
    int payload, field0058;
    SurfaceRect bounds;
    unsigned char palette;
    unsigned char unknown_006d[3];
    double field0070, field0078;
    int field0080;
    short field0084, field0086;
    int field0088, field008c;
    unsigned char unknown_0090[8];
    void SetVelocityPolar(double, double);
};
struct SecondaryEffectSpawn {
    int owner;
    unsigned short type;
    unsigned char unknown_0006[2];
    double x, y;
    char flag0018;
    unsigned char unknown_0019[3];
    int facing;
    char group;
    unsigned char layer;
    unsigned char unknown_0022[2];
    int payload, field0028;
    unsigned char palette;
    unsigned char unknown_002d[3];
    int field0030;
    SurfaceRect bounds;
};
class CharacterStatistics {
public:
    int values[8];
    void Read(const char *);
    void Write(const char *);
};
// Shared nonpolymorphic pose base; field names use Secondary-relative offsets.
class SecondaryPose {
public:
    unsigned short field0008;
    unsigned short field000a;
    unsigned short field000c; // target reads this frame counter with MOVZX

    unsigned char unknown_000e[0x2];
    PatternSequence * patterns;
    IUnknown ** surfaces;
    unsigned short surfaceCount;
    unsigned char colorKey;
    unsigned char unknown_001b[5];
    double positionX;
    double positionY;
    double velocityX, velocityY, horizontalDeceleration, gravity;
    char facing;
    unsigned char unknown_0051[0x7];
    char field0058;
    unsigned char unknown_0059[0x7];
    double VectorAngle(double, double);
    int field0060;
    unsigned char unknown_0064[0x14];
};
class Secondary : public SecondaryPose {
public:
    virtual void ResetPose();
    virtual void Slot01() = 0;
    virtual void Slot02() = 0;
    virtual void Slot03() = 0;
    virtual void Slot04() = 0;
    virtual void Slot05() = 0;
    virtual void Slot06() = 0;
    virtual void Slot07() = 0;
    virtual void Slot08() = 0;
    virtual void EmitLocalEffect(SecondaryEffectSpawn *);
    virtual void RemoveLocalEffect(short);
    virtual void LoadResources();
    virtual void InitializeState();
public:
    Secondary ** opponentSlot;
    Context * contextOwner;
    Video * videoOwner;
    Input * inputOwner;
    Audio * audioOwner;
    char player;
    char characterId;
    char paletteIndex;
    unsigned char unknown_008f[0x5];
    char resourceName[16];
    int cpuControlled;
    float field00a8;
    char field00ac;
    unsigned char unknown_00ad[0x3];
    double velocityXCorrection;
    double outgoingPushbackVelocityX;
    double knockbackVelocityX, knockbackVelocityY;
    int outgoingPushbackActive;
    unsigned char unknown_00d4[8];
    short field00dc;
    unsigned char field00de;
    unsigned char unknown_00df[0x15];
    short field00f4;
    unsigned char unknown_00f6[0x2];
    double field00f8;
    unsigned int field0100;
    short field0104;
    unsigned char unknown_0106[0x2];
    int field0108;
    int field010c;
    int field0110;
    unsigned char unknown_0114[0x4];
    double field0118;
    char field0120;
    unsigned char unknown_0121[3];
    short field0124;
    unsigned char unknown_0126[2];
    int field0128, field012c;
    char field0130;
    unsigned char unknown_0131[3];
    float field0134;
    short field0138;
    short field013a;
    short field013c;
    short field013e;
    short field0140;
    unsigned char unknown_0142[2];
    int field0144;
    short field0148;
    short field014a;
    short field014c;
    short field014e;
    int field0150;
    int field0154;
    char field0158;
    unsigned char field0159;
    unsigned char field015a;
    unsigned char unknown_015b[0x1];
    int field015c;
    int field0160;
    SecondarySequence * sequences;
    int field0168;
    short field016c;
    unsigned char unknown_016e[2];
    int field0170;
    short field0174;
    unsigned char unknown_0176[0x2];
    double field0178;
    double field0180;
    char inputX, inputY, buttonPulse[4];
    unsigned char unknown_018e[2];
    int buttonHeld[4];
    int field01a0, field01a4;
    unsigned char field01a8;
    unsigned char field01a9;
    unsigned char field01aa;
    unsigned char history[180];
    unsigned char unknown_025f[0x1];
    short field0260;
    short field0262;
    unsigned short soundSlots[50];
    char field02c8;
    char field02c9;
    short effectWrite;
    short effectRead;
    unsigned char unknown_02ce[0x2];
    int effectOwner[64];
    int effectActive[64];
    SecondaryEffectSlot effects[64];
    short field2ad0[5];
    unsigned char unknown_2ada[0x1e];
    short field2af8[5];
    unsigned char unknown_2b02[0xbe];
    SecondaryTrail trail;
    char tint30b8;
    unsigned char unknown_30b9[3];
    int field30bc;
    unsigned char field30c0;
    unsigned char unknown_30c1[3];
    int field30c4;
    unsigned int field30c8;
    unsigned int field30cc;
    unsigned int field30d0;
    unsigned int field30d4;
    unsigned int field30d8;
    int field30dc;
    unsigned int field30e0;
    unsigned int field30e4;
    int field30e8;
    short field30ec;
    short field30ee;
    int field30f0;
    char commandCount;
    char commands[20];
    unsigned char unknown_3109[7];
    int field3110, field3114;
    CharacterStatistics statistics;
    Secondary(Secondary **, Context *, Video *, Input *, Audio *, char);
    ~Secondary();
    void ResetFrame();
    void ClearLocalEffects();
    void AdvanceEffectWrite();
    void ResetLocalEffectSpawn(SecondaryEffectSpawn *);
    void RenderLocalEffects(int, int, unsigned char);
    void LoadImages();
    void LoadSounds();
    void LoadPatterns();
    void UpdateInput();
    void Render(int, int);
    void AdvanceTrail();
    void StartTrail(unsigned char);
    void DispatchState();
    void CheckAirAction();
    void UpdateMovement();
    void UpdateTimers();
    char CollisionSide();
    int IsStateGroupA();
    int IsStateGroupB();
    void ClearBufferedButtons();
    void ClearInputHistory();
    int CanGuard(const SecondaryFrame *, const SecondaryFrame *);
    int GuardInput(const SecondaryFrame *);
    int AirActionReady();
    int IsStateGroupC();
    double DamageFactor();
    double HealthFactor();
    double ComboFactor();
    void ApplyDamage(int, double);
    void AwardComboScore(const SecondaryFrame *);
    void AddScore(unsigned int);
    short RandomRange(short, short);
    void SetTint(unsigned char, int);
    void SetCharacterTint(unsigned char, int);
    void SetVerticalShake(int, int);
    void SetHorizontalShake(int, int);
    void SetHorizontalOffset(int, int);
    int FaceOpponent();
    void UpdateLocomotionState();
};
// Word-oriented file state; the remaining Context fields are separate members.
class WordFile {
    friend class Scene3;
    int exhausted;
    HANDLE file;
    DWORD remaining, transferred;
public:
    WordFile();
    ~WordFile();
    unsigned int OpenRead(const char *);
    void OpenWrite(const char *);
    void Close();
    unsigned short ReadWord();
    void WriteWord(unsigned short);
};
struct PatternFrame { unsigned short duration, texture; short u, v, width, height; };
class PatternSequence {
public:
    unsigned char count;
private:
    unsigned char unknown_0001[3];
public:
    PatternFrame *frames;
    PatternSequence();
    ~PatternSequence();
    void Allocate(int);
};
// Provisional effect records recovered from their producers and consumers.
struct EffectSpawn : public SecondaryEffectSpawn {
    EffectSpawn();
};
struct EffectSlot {
    unsigned short type, frame, tick;
    unsigned char unknown_0006[0x12];
    double x, y, vx, vy;
    unsigned char unknown_0038[0x10];
    char flag0048;
    unsigned char unknown_0049[3];
    int facing;
    char group;
    unsigned char layer;
    unsigned char unknown_0052[2];
    int payload;
    unsigned char unknown_0058[0x14];
    unsigned char palette;
    unsigned char unknown_006d[3];
};
class Context {
public:
    Video *videoOwner;
    Input *inputOwner;
    Audio *audioOwner;
public:
    char directionX[2], directionY[2];
    char buttonA[2];
    char buttonB[2], buttonC[2], buttonD[2];
    int heldA[2], heldB[2], heldC[2], heldD[2];
    IUnknown *textures[0x398];
    IUnknown *extraA, *extraB, *extraC;
    unsigned short soundSlots[0x41];
    unsigned short audioMode;
public:
    int targetVolume, currentVolume;
    short volumeStep;
public:
    char flag0f32;
private:
public:
    char field0f33;
private:
public:
    unsigned char colorKey;
private:
public:
    unsigned char characterPalette[1024];
private:
    unsigned char unknown_1335[3];
public:
    int alternateStyle[2];
public:
    char flag1340;
public:
    char characterDataMode;
public:
    unsigned char selectedPlayer;
    unsigned char cpuPlayer[2];
public:
    unsigned char flag1345;
public:
    unsigned char flag1346;
private:
    unsigned char unknown_1347;
public:
    int counter1348;
public:
    char winner134c;
public:
    char effectSelector;
public:
    unsigned char selection134e;
public:
    unsigned char setting134f;
    char effectFlag1350;
private:
    unsigned char unknown_1351;
public:
    short state1352;
public:
    int counter1354;
public:
    char flag1358;
private:
    unsigned char unknown_1359[3];
public:
    int field135c, field1360;
public:
    char mode1364;
public:
    unsigned char setting1365;
    char setting1366;
private:
    unsigned char unknown_1367;
public:
    int framePhase;
    int setting136c;
    unsigned char setting1370;
private:
    unsigned char unknown_1371[3];
public:
    int configured;
public:
    char playerFlag1378[2];
private:
    unsigned char unknown_137a[2];
public:
    unsigned char *blob;
    short field1380, field1382;
    int effectActive[640], effectOwner[640];
    char effectFlags[640];
    EffectSlot effects[640];
    PatternSequence *patterns;
public:
    short state1420c, state1420e;
    double state14210;
    int state14218, state1421c, state14220;
private:
    unsigned char unknown_14224[4];
public:
    double state14228, state14230;
public:
    int state14238;
public:
    int state1423c;
public:
    int state14240;
public:
    int state14244;
public:
    SurfaceRect cameraBounds;
    double backgroundScale;
public:
    double fadeLevel;
    int fadeHold;
    char fadeDirection;
private:
    unsigned char unknown_1426d[3];
public:
    int fadeAttack, fadeRelease, state14278, state1427c;
private:
public:
    char state14280;
public:
    char field14281, field14282;
public:
    char flag14283;
private:
public:
    WordFile replayFile;
private:
    int effectPhase, effectAngleStart, effectAngleEnd;
    unsigned int copiedEffectFrame, copiedEffectTick;
    unsigned char unknown_142a8[0x48];
public:
    Context(Video *, Input *, Audio *);
    ~Context();
    void Initialize();
    void PollInput();
    void PlayEffectSound(unsigned short);
    void LoadMusic(unsigned short);
    void ReleaseMusic();
    void FadeMusic(int, short);
    void Load();
    void Activate();
    void LoadObjectFile(IUnknown **, const char *, unsigned char, unsigned char);
    void UpdateEffect(short);
    void EmitEffect(EffectSpawn *);
    void RequestTransition(char);
    void StartFade(int, int, int);
    void StartReverseFade(int, int, int);
    void SetSceneTimer(int);
    void RemoveEffect(short);
    void AdvanceEffectWrite();
    void ProbeCharacterData();
    void ClearEffects();
    void UpdateEffects();
    void RemoveEffectsOfType(int);
    void RenderEffects(int, int, unsigned char);
    void ResetState();
    void UpdateFrameControls();
    void UpdateCameraShake();
    void UpdatePaletteFade();
};
class Scene {
public:
    virtual void Slot0() = 0;
    virtual unsigned char Step() = 0;
    virtual void PollKeyboard() = 0;
    unsigned message;
protected:
    HWND window;
    Secondary *secondary[2];
    Secondary **secondarySlotA, **secondarySlotB;
    Context *contextOwner;
    Video *videoOwner;
    Input *inputOwner;
    Audio *audioOwner;
    char phase;
    char flag002d;
    unsigned char palette[1024];
    unsigned char colorKey;
public:
    Scene(HWND, Secondary **, Secondary **, Context *, Video *, Input *, Audio *);
    void FadeOut(unsigned char *, unsigned char, int, int);
    void FadeIn(unsigned char *, unsigned char);
};
class Scene0 : public Scene {
    unsigned char unknown_0430[4];
    IUnknown *titleSurface, *objectSurface;
    char selection;
    unsigned char unknown_043d;
    short animationTick;
    unsigned char directionHeld[2];
    char flag0442;
    unsigned char unknown_0443;
    unsigned int idleTicks;
    int field0448;
public:
    Scene0(HWND, Secondary **, Secondary **, Context *, Video *, Input *, Audio *);
    ~Scene0();
    virtual void Slot0();
    virtual unsigned char Step();
    virtual void PollKeyboard();
};
#define DECLARE_SCENE(Name, Size) \
class Name : public Scene { \
    unsigned char unknown_0430[Size - sizeof(Scene)]; \
public: Name(HWND, Secondary **, Secondary **, Context *, Video *, Input *, Audio *); \
    virtual void Slot0(); virtual unsigned char Step(); virtual void PollKeyboard(); \
};
class Scene1 : public Scene {
    unsigned char unknown_0430[4];
    IUnknown *backgroundSurface, *objectSurface, *portraitSurface, *stageSurface;
    IUnknown *playerSurfaces[2];
    unsigned char playerColorKey[2], stageColorKey, portraitColorKey;
    double field0450, field0458, field0460, field0468, field0470;
    int field0478, playerDelta[2], field0484, field0488, field048c, field0490;
    short field0494[2], field0498[2];
    unsigned char field049c[2];
    char field049e[2];
    char characterOrder[25], gridCharacters[24];
    unsigned char unknown_04d1[3];
    int portraitOffsets[24];
    unsigned char unknown_0534[4];
    char field0538[2], field053a[2], field053c[2], field053e[2];
    short field0540[2];
    unsigned char stageUnavailable[23];
    unsigned char unknown_055b[5];
public:
    Scene1(HWND, Secondary **, Secondary **, Context *, Video *, Input *, Audio *);
    ~Scene1();
    virtual void Slot0();
    virtual unsigned char Step();
    virtual void PollKeyboard();
    void Enter();
    void LoadCharacter(Secondary **, Secondary **, char);
    void LoadStage();
    void LoadPlayerPalette(char);
};
class Scene2 : public Scene {
    unsigned char unknown_0430[4];
    IUnknown *loadingSurface;
public:
    Scene2(HWND, Secondary **, Secondary **, Context *, Video *, Input *, Audio *);
    ~Scene2();
    virtual void Slot0();
    virtual unsigned char Step();
    virtual void PollKeyboard();
    void PrepareBattle();
    void LoadCharacter(Secondary **, Secondary **, char, char);
};
class Scene3;
DECLARE_SCENE(Scene5, 0x474)
DECLARE_SCENE(Scene6, 0x760)
DECLARE_SCENE(Scene7, 0x448)
DECLARE_SCENE(Scene8, 0x758)
#undef DECLARE_SCENE

#endif
