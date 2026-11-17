// Draw a one-pixel rectangular border on the locked 8-bit DirectDraw back
// buffer, with the native independent endpoint clipping (0..320, 0..240).
// Original engine owner: 0x0040B110, complete 485-byte function.
// Complete original native function reconstructed in typed, ordinary C++.
// Strict complete body identity: VC7.1 normal COFF, 485/485 bytes.
#include "Engine.h"

int Video::FrameRectangle(SurfaceRect rectangle, unsigned char color)
{
    HRESULT result;
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

    // The original uses a contiguous local pixel span for the clip bounds
    // and the locked pitch-based 8-bit pixel surface.
    struct PixelSpan {
        int width;
        int height;
        unsigned char *pixels;
    } span;
    span.width = rectangle.right - rectangle.left;
    span.height = rectangle.bottom - rectangle.top;
    description.dwSize = sizeof(description);
    result = backSurface->Lock(
        reinterpret_cast<RECT *>(&rectangle), &description, 1, 0);
    if (result != DD_OK) {
        if (result == DDERR_SURFACELOST) return 0;
        return 1;
    }

    {
        int rowOrColumn;
        span.pixels = static_cast<unsigned char *>(description.lpSurface);
        for (rowOrColumn = 0; rowOrColumn < span.width; ++rowOrColumn) {
            span.pixels[rowOrColumn] = color;
            span.pixels[(span.height - 1) * description.lPitch + rowOrColumn] = color;
        }
        for (rowOrColumn = 0; rowOrColumn < span.height; ++rowOrColumn) {
            span.pixels[rowOrColumn * description.lPitch] = color;
            span.pixels[rowOrColumn * description.lPitch + span.width - 1] = color;
        }
        result = backSurface->Unlock(description.lpSurface);
    }
    return 1;
}
