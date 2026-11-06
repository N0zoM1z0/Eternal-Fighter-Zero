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
    int ConvertBackBuffer();
    int DrawSurface(SurfaceRect, IUnknown *, SurfaceRect, unsigned char, int);
    int DrawBlendedSurface(SurfaceRect, IUnknown *, SurfaceRect, unsigned char, int, int);
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
class Secondary { public: ~Secondary(); };
// Word-oriented file state; the remaining Context fields are separate members.
class WordFile {
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
struct EffectSpawn {
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
    int payload;
    unsigned char unknown_0028[4];
    unsigned char palette;
    unsigned char unknown_002d[0x1b];
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
    unsigned char buttonB[2], buttonC[2], buttonD[2];
    int heldA[2], heldB[2], heldC[2], heldD[2];
    IUnknown *textures[0x398];
    IUnknown *extraA, *extraB, *extraC;
    unsigned short soundSlots[0x41];
    unsigned short audioMode;
public:
    int targetVolume, currentVolume;
    short volumeStep;
public:
    unsigned char flag0f32;
private:
    unsigned char unknown_0f33;
public:
    unsigned char colorKey;
private:
    unsigned char unknown_0f35[0x40c];
public:
    char characterDataMode;
private:
public:
    unsigned char selectedPlayer;
    char cpuPlayer[2];
public:
    unsigned char flag1345;
public:
    unsigned char flag1346;
private:
    unsigned char unknown_1347;
public:
    int counter1348;
private:
    unsigned char unknown_134c;
public:
    char effectSelector;
private:
public:
    unsigned char selection134e;
public:
    unsigned char setting134f;
    char effectFlag1350;
private:
    unsigned char unknown_1351[3];
public:
    int counter1354;
private:
    unsigned char unknown_1358[0xc];
public:
    unsigned char mode1364;
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
private:
    unsigned char unknown_1378[4];
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
private:
    unsigned char unknown_14238[0x28];
public:
    double fadeLevel;
    int fadeHold;
    char fadeDirection;
private:
    unsigned char unknown_1426d[3];
public:
    int fadeAttack, fadeRelease, state14278, state1427c;
private:
    unsigned char unknown_14280[4];
    WordFile replayFile;
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
    Secondary *secondaryA, *secondaryB;
    Secondary **secondarySlotA, **secondarySlotB;
    Context *contextOwner;
    Video *videoOwner;
    Input *inputOwner;
    Audio *audioOwner;
    char phase;
    unsigned char flag002d;
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
DECLARE_SCENE(Scene1, 0x560)
DECLARE_SCENE(Scene2, 0x438)
DECLARE_SCENE(Scene3, 0x598)
DECLARE_SCENE(Scene5, 0x474)
DECLARE_SCENE(Scene6, 0x760)
DECLARE_SCENE(Scene7, 0x448)
DECLARE_SCENE(Scene8, 0x758)
#undef DECLARE_SCENE

#endif
