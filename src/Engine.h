// Provisional EFZ layouts; unknown storage is data, never code padding.
#ifndef EFZ_ENGINE_H
#define EFZ_ENGINE_H
#include <windows.h>
#include <unknwn.h>
#include <ddraw.h>
struct SurfaceRect { int left, top, right, bottom; };
class Video {
    unsigned char unknown_0000[4];
    unsigned char flag0004;
    unsigned char unknown_0005[0x20401];
    unsigned short squaredDifference[512];
    unsigned char unknown_20806[2];
    IDirectDraw *directDraw;
public:
    Video();
    void Initialize(HWND, unsigned char);
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
    unsigned char unknown_0000[0x6c];
public:
    ContextTail();
    ~ContextTail();
};
struct PatternFrame { unsigned short x, y, u, v, width, height; };
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
    unsigned char unknown_1346[9];
public:
    unsigned char setting134f;
private:
    unsigned char unknown_1350[0x15];
public:
    unsigned char setting1365, setting1366;
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
private:
    unsigned char unknown_1384[0x12e84];
public:
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
