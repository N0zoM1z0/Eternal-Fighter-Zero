// Draw a one-pixel rectangular border on the locked 8-bit DirectDraw back
// buffer, with the native independent endpoint clipping (0..320, 0..240).
// Original engine owner: 0x0040B110, complete 485-byte function.
// Typed natural C++ candidate only. Byte identity remains unproven:
// VC7.1 /Od still assigns local stack slots differently from the original.
#include "../../src/Engine.h"

int Video::FrameRectangle(SurfaceRect rectangle, unsigned char color)
{
    int i;
    HRESULT result;
    int width;
    int height;
    unsigned char *pixels;
    DDSURFACEDESC description;

    if (rectangle.top < 0) rectangle.top = 0;
    else if (rectangle.top > 240) rectangle.top = 240;
    if (rectangle.bottom < 0) rectangle.bottom = 0;
    else if (rectangle.bottom > 240) rectangle.bottom = 240;
    if (rectangle.left < 0) rectangle.left = 0;
    else if (rectangle.left > 320) rectangle.left = 320;
    if (rectangle.right < 0) rectangle.right = 0;
    else if (rectangle.right > 320) rectangle.right = 320;

    if (rectangle.top >= rectangle.bottom ||
        rectangle.left >= rectangle.right)
        return 1;

    width = rectangle.right - rectangle.left;
    height = rectangle.bottom - rectangle.top;
    description.dwSize = sizeof(description);
    result = backSurface->Lock(
        reinterpret_cast<RECT *>(&rectangle), &description, 1, 0);
    if (result != DD_OK) {
        if (result == DDERR_SURFACELOST) return 0;
        return 1;
    }

    pixels = static_cast<unsigned char *>(description.lpSurface);
    for (i = 0; i < width; ++i) {
        pixels[i] = color;
        pixels[(height - 1) * description.lPitch + i] = color;
    }
    for (i = 0; i < height; ++i) {
        pixels[i * description.lPitch] = color;
        pixels[(width - 1) + i * description.lPitch] = color;
    }
    result = backSurface->Unlock(description.lpSurface);
    return 1;
}
