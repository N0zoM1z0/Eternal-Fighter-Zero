// Provisional EFZ layouts; unknown storage is data, never code padding.
#ifndef EFZ_ENGINE_H
#define EFZ_ENGINE_H
#include <windows.h>
#include <unknwn.h>
#include <ddraw.h>
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
};
class Input {
public:
    void Initialize(HWND);
    void Configure(unsigned int);
    void Defaults();
    void Shutdown();
};
class Audio {
public:
    void Initialize(HWND);
    void SetMode(short);
    void ReleaseSound(unsigned short);
    void Shutdown();
};
class Secondary { public: ~Secondary(); };
class ContextTail {
    unsigned char unknown_0000[0x10];
public:
    int effectPhase, effectAngleStart, effectAngleEnd;
    unsigned int copiedEffectFrame, copiedEffectTick;
private:
    unsigned char unknown_0024[0x48];
public:
    ContextTail();
    ~ContextTail();
};
struct PatternFrame { unsigned short duration, y, u, v, width, height; };
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
    char group, layer;
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
    char group, layer;
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
private:
    unsigned char unknown_000c[0x2c];
public:
    IUnknown *textures[0x398];
    IUnknown *extraA, *extraB, *extraC;
    unsigned short soundSlots[0x41];
    unsigned short audioMode;
private:
    unsigned char unknown_0f28[0xa];
public:
    unsigned char flag0f32;
private:
    unsigned char unknown_0f33[0x412];
public:
    unsigned char flag1345;
private:
    unsigned char unknown_1346[7];
public:
    char effectSelector;
private:
    unsigned char unknown_134e;
public:
    unsigned char setting134f;
    char effectFlag1350;
private:
    unsigned char unknown_1351[0x14];
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
private:
    unsigned char unknown_1420c[0x78];
    ContextTail tail;
public:
    Context(Video *, Input *, Audio *);
    ~Context();
    void Initialize();
    void Load();
    void Activate();
    void LoadObjectFile(IUnknown **, const char *, unsigned char, unsigned char);
    void UpdateEffect(short);
    void EmitEffect(EffectSpawn *);
    void RemoveEffect(short);
    void AdvanceEffectWrite();
    void InitializeState();
    void ResetState();
};
class Scene {
public:
    virtual void Slot0();
    virtual unsigned char Step();
    unsigned message;
};
#define DECLARE_SCENE(Name, Size) \
class Name : public Scene { \
    unsigned char unknown_0008[Size - 8]; \
public: Name(HWND, Secondary **, Secondary **, Context *, Video *, Input *, Audio *); \
};
DECLARE_SCENE(Scene0, 0x44c)
DECLARE_SCENE(Scene1, 0x560)
DECLARE_SCENE(Scene2, 0x438)
DECLARE_SCENE(Scene3, 0x598)
DECLARE_SCENE(Scene5, 0x474)
DECLARE_SCENE(Scene6, 0x760)
DECLARE_SCENE(Scene7, 0x448)
DECLARE_SCENE(Scene8, 0x758)
#undef DECLARE_SCENE

#endif
