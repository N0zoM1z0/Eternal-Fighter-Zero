// DirectDraw device lifetime and original display-mode transitions.
// Error exits post WM_CLOSE and retain the original integer return value of one.
#include "Engine.h"

extern const char initCreateTitle[];
extern const char initCreateError[];
extern const char initCooperativeTitle[];
extern const char initCooperativeError[];
extern const char initLargeTitle[];
extern const char initLargeError[];
extern const char initSmallTitle[];
extern const char initSmallError[];
extern const char initPrimaryTitle[];
extern const char initPrimaryError[];
extern const char initBackTitle[];
extern const char initBackError[];
extern const char reset8LargeTitle[];
extern const char reset8LargeError[];
extern const char reset8SmallTitle[];
extern const char reset8SmallError[];
extern const char reset8PrimaryTitle[];
extern const char reset8PrimaryError[];
extern const char reset8BackTitle[];
extern const char reset8BackError[];
extern const char reset16LargeTitle[];
extern const char reset16LargeError[];
extern const char reset16SmallTitle[];
extern const char reset16SmallError[];
extern const char reset16PrimaryTitle[];
extern const char reset16PrimaryError[];
extern const char reset16BackTitle[];
extern const char reset16BackError[];

int Video::Initialize(HWND handle, unsigned char mode)
{
    HRESULT result;
    DDSCAPS caps;
    {
        DDSURFACEDESC description; // Only the observed fields are assigned.
        flag0004 = mode;
        window = handle;
        result = DirectDrawCreate(0, &directDraw, 0);
        if (result != DD_OK) {
            MessageBoxA(0, initCreateError, initCreateTitle, 0);
            return RequestClose();
        }
        result = directDraw->SetCooperativeLevel(window, 0x13);
        if (result != DD_OK) {
            MessageBoxA(0, initCooperativeError, initCooperativeTitle, 0);
            return RequestClose();
        }
        if (mode == 1) {
            result = directDraw->SetDisplayMode(640, 480, 8);
            if (result != DD_OK) {
                MessageBoxA(0, initLargeError, initLargeTitle, 0);
                return RequestClose();
            }
        } else {
            result = directDraw->SetDisplayMode(320, 240, 8);
            if (result != DD_OK) {
                MessageBoxA(0, initSmallError, initSmallTitle, 0);
                return RequestClose();
            }
        }
        description.dwSize = sizeof(DDSURFACEDESC);
        description.dwFlags = 0x21;
        description.dwWidth = flag0004 * 320 + 320;
        description.dwHeight = flag0004 * 240 + 240;
        description.ddsCaps.dwCaps = 0xa18;
        description.dwBackBufferCount = 1;
        result = directDraw->CreateSurface(&description, &primarySurface, 0);
        if (result != DD_OK) {
            MessageBoxA(0, initPrimaryError, initPrimaryTitle, 0);
            return RequestClose();
        }
        caps.dwCaps = 4;
        result = primarySurface->GetAttachedSurface(&caps, &backSurface);
        if (result != DD_OK) {
            MessageBoxA(0, initBackError, initBackTitle, 0);
            return RequestClose();
        }
        directDraw->CreatePalette(4, paletteEntries, &paletteInterface, 0);
        primarySurface->SetPalette(paletteInterface);
        return 1;
    }
}

int Video::Recreate8Bit()
{
    HRESULT result;
    DDSCAPS caps;
    {
        DDSURFACEDESC description; // Only the observed fields are assigned.
        if (backSurface) { backSurface->Release(); backSurface = 0; }
        if (primarySurface) { primarySurface->Release(); primarySurface = 0; }
        if (flag0004 == 1) {
            result = directDraw->SetDisplayMode(640, 480, 8);
            if (result != DD_OK) {
                MessageBoxA(0, reset8LargeError, reset8LargeTitle, 0);
                return RequestClose();
            }
        } else {
            result = directDraw->SetDisplayMode(320, 240, 8);
            if (result != DD_OK) {
                MessageBoxA(0, reset8SmallError, reset8SmallTitle, 0);
                return RequestClose();
            }
        }
        description.dwSize = sizeof(DDSURFACEDESC);
        description.dwFlags = 0x21;
        description.dwWidth = flag0004 * 320 + 320;
        description.dwHeight = flag0004 * 240 + 240;
        description.ddsCaps.dwCaps = 0xa18;
        description.dwBackBufferCount = 1;
        result = directDraw->CreateSurface(&description, &primarySurface, 0);
        if (result != DD_OK) {
            MessageBoxA(0, reset8PrimaryError, reset8PrimaryTitle, 0);
            return RequestClose();
        }
        caps.dwCaps = 4;
        result = primarySurface->GetAttachedSurface(&caps, &backSurface);
        if (result != DD_OK) {
            MessageBoxA(0, reset8BackError, reset8BackTitle, 0);
            return RequestClose();
        }
        return 1;
    }
}

int Video::Recreate16Bit()
{
    HRESULT result;
    DDSCAPS caps;
    {
        DDSURFACEDESC description; // Only the observed fields are assigned.
        if (backSurface) { backSurface->Release(); backSurface = 0; }
        if (primarySurface) { primarySurface->Release(); primarySurface = 0; }
        if (flag0004 == 1) {
            result = directDraw->SetDisplayMode(640, 480, 16);
            if (result != DD_OK) {
                MessageBoxA(0, reset16LargeError, reset16LargeTitle, 0);
                return RequestClose();
            }
        } else {
            result = directDraw->SetDisplayMode(320, 240, 16);
            if (result != DD_OK) {
                MessageBoxA(0, reset16SmallError, reset16SmallTitle, 0);
                return RequestClose();
            }
        }
        description.dwSize = sizeof(DDSURFACEDESC);
        description.dwFlags = 0x21;
        description.dwWidth = flag0004 * 320 + 320;
        description.dwHeight = flag0004 * 240 + 240;
        description.ddsCaps.dwCaps = 0xa18;
        description.dwBackBufferCount = 1;
        result = directDraw->CreateSurface(&description, &primarySurface, 0);
        if (result != DD_OK) {
            MessageBoxA(0, reset16PrimaryError, reset16PrimaryTitle, 0);
            return RequestClose();
        }
        caps.dwCaps = 4;
        result = primarySurface->GetAttachedSurface(&caps, &backSurface);
        if (result != DD_OK) {
            MessageBoxA(0, reset16BackError, reset16BackTitle, 0);
            return RequestClose();
        }
        return 1;
    }
}

void Video::Shutdown()
{
    if (paletteInterface) { paletteInterface->Release(); paletteInterface = 0; }
    if (backSurface) { backSurface->Release(); backSurface = 0; }
    if (primarySurface) { primarySurface->Release(); primarySurface = 0; }
    if (directDraw) {
        directDraw->RestoreDisplayMode();
        directDraw->Release();
        directDraw = 0;
    }
}

Video::~Video()
{
    if (paletteInterface) { paletteInterface->Release(); paletteInterface = 0; }
    if (backSurface) { backSurface->Release(); backSurface = 0; }
    if (primarySurface) { primarySurface->Release(); primarySurface = 0; }
    if (directDraw) {
        directDraw->RestoreDisplayMode();
        directDraw->Release();
        directDraw = 0;
    }
}

void Video::ReleaseSurface(IUnknown **surface)
{
    if (*surface) { (*surface)->Release(); *surface = 0; }
}

int Video::RequestClose()
{
    PostMessageA(window, WM_CLOSE, 0, 0);
    return 1;
}

int Video::RestorePrimarySurface()
{
    if (primarySurface->Restore()) return 0;
    return 1;
}

int Video::RestoreSurface(IUnknown **surface)
{
    if (reinterpret_cast<IDirectDrawSurface *>(*surface)->Restore()) return 0;
    return 1;
}
