// Natural C++ prototype of Video::ConvertBackBuffer, native 0x0040B440.
// The original 8-bit back buffer is expanded in place from 320x240 to 640x480.
// Visit pixels bottom-right first so the four destination bytes cannot
// overwrite any source pixels that have not yet been read.
// This is NOT an Exact function until the full native PE body matches.
#include "../../src/Engine.h"

extern SurfaceRect __cdecl MakeSurfaceRect(int, int, int, int);

int Video::ConvertBackBuffer()
{
    SurfaceRect bounds = MakeSurfaceRect(0, 0, 640, 480);
    DDSURFACEDESC surface;
    surface.dwSize = sizeof(surface);

    HRESULT result = backSurface->Lock(
        reinterpret_cast<RECT *>(&bounds), &surface, 1, 0);
    if (result != DD_OK) {
        if (result == DDERR_SURFACELOST) return 0;
        return 1;
    }

    unsigned char *base = static_cast<unsigned char *>(surface.lpSurface);
    int pitch = surface.lPitch;
    unsigned char *sourceRow = base + pitch * 239;
    unsigned char *destinationRow = base + pitch * 478;
    for (int y = 239; y >= 0; --y) {
        for (int x = 319; x >= 0; --x) {
            unsigned char pixel = sourceRow[x];
            destinationRow[x * 2] = pixel;
            destinationRow[x * 2 + 1] = pixel;
            destinationRow[x * 2 + pitch] = pixel;
            destinationRow[x * 2 + pitch + 1] = pixel;
        }
        sourceRow -= pitch;
        destinationRow -= pitch * 2;
    }
    backSurface->Unlock(surface.lpSurface);
    return 1;
}
