// Fill and clip an 8-bit surface rectangle using the original DirectDraw
// back-buffer lock. Native owner: Video::FillRectangle at 0x0040B300.
// Provisional typed C++ only: 308-byte original vs an unaccepted candidate.
// The original loop uses EDI-register addressing that VC7.1 /Od has not
// reproduced from this ordinary pointer/array loop. Do not claim Exact.
#include "../../src/Engine.h"

int Video::FillRectangle(SurfaceRect rectangle, unsigned char fillColor)
{
    if (rectangle.top >= rectangle.bottom ||
        rectangle.left >= rectangle.right)
        return 1;

    if (rectangle.top < 0) rectangle.top = 0;
    if (rectangle.left < 0) rectangle.left = 0;
    if (rectangle.bottom > 240) rectangle.bottom = 240;
    if (rectangle.right > 320) rectangle.right = 320;

    if (rectangle.top >= rectangle.bottom ||
        rectangle.left >= rectangle.right)
        return 1;

    DDSURFACEDESC description;
    description.dwSize = sizeof(description);
    HRESULT result = backSurface->Lock(
        reinterpret_cast<RECT *>(&rectangle), &description, 1, 0);
    if (result != DD_OK) {
        if (result == DDERR_SURFACELOST) return 0;
        return 1;
    }

    int rows = rectangle.bottom - rectangle.top - 1;
    unsigned char *pixels = static_cast<unsigned char *>(description.lpSurface);
    do {
        int columns = rectangle.right - rectangle.left - 1;
        do {
            pixels[columns] = fillColor;
            --columns;
        } while (columns >= 0);
        pixels += description.lPitch;
        --rows;
    } while (rows >= 0);

    backSurface->Unlock(description.lpSurface);
    return 1;
}
