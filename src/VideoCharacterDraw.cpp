// Natural C++ reconstruction of the character tint pixel kernel.
// The target uses hand-written register loops; this owner remains byte-open.
#include "Engine.h"

int Video::DrawCharacterTint(SurfaceRect destination, IUnknown *surface,
    SurfaceRect source, unsigned char colorKey, int flip, char tint)
{
    int originalSourceRight = source.right;
    if (destination.top >= destination.bottom || destination.left >= destination.right) return 1;
    if (source.top >= source.bottom || source.left >= source.right) return 1;

    if (destination.top < 0) {
        source.top -= destination.top;
        destination.top = 0;
    }
    if (destination.left < 0) {
        source.left -= destination.left;
        destination.left = 0;
    }
    if (destination.bottom > 240) {
        source.bottom -= destination.bottom - 240;
        destination.bottom = 240;
    }
    if (destination.right > 320) {
        source.right -= destination.right - 320;
        destination.right = 320;
    }
    // The original mirrors the source rectangle around its original right edge.
    if (flip != 0) {
        int sourceWidth = originalSourceRight - source.left;
        source.left = originalSourceRight - source.right;
        source.right = sourceWidth;
    }

    if (destination.top >= destination.bottom || destination.left >= destination.right) return 1;
    if (source.top >= source.bottom || source.left >= source.right) return 1;

    DDSURFACEDESC sourceDescription;
    DDSURFACEDESC destinationDescription;
    HRESULT result;
    sourceDescription.dwSize = sizeof(DDSURFACEDESC);
    destinationDescription.dwSize = sizeof(DDSURFACEDESC);

    result = reinterpret_cast<IDirectDrawSurface *>(surface)->Lock(
        reinterpret_cast<RECT *>(&source), &sourceDescription, DDLOCK_WAIT | DDLOCK_READONLY, 0);
    if (result != DD_OK) {
        if (result == DDERR_SURFACELOST) return 0;
        return 1;
    }
    result = backSurface->Lock(reinterpret_cast<RECT *>(&destination),
        &destinationDescription, DDLOCK_WAIT, 0);
    if (result != DD_OK) {
        if (result == DDERR_SURFACELOST) return 0;
        return 1;
    }

    unsigned char *sourcePixels = static_cast<unsigned char *>(sourceDescription.lpSurface);
    unsigned char *destinationPixels = static_cast<unsigned char *>(destinationDescription.lpSurface);
    int sourcePitch = sourceDescription.lPitch;
    int destinationPitch = destinationDescription.lPitch;
    int width = destination.right - destination.left;
    int height = destination.bottom - destination.top;
    unsigned char tintIndex = static_cast<unsigned char>(tint);

    // The original no-key path does not enter either keyed flip loop.
    if (colorKey > 0) {
        if (flip != 0) {
            for (int y = 0; y < height; ++y) {
                for (int x = width - 1; x >= 0; --x) {
                    unsigned char pixel = sourcePixels[y * sourcePitch + (width - 1 - x)];
                    if (pixel != colorKey) destinationPixels[y * destinationPitch + x] = sumBlend[pixel][tintIndex];
                }
            }
        } else {
            for (int y = 0; y < height; ++y) {
                for (int x = width - 1; x >= 0; --x) {
                    unsigned char pixel = sourcePixels[y * sourcePitch + x];
                    if (pixel != colorKey) destinationPixels[y * destinationPitch + x] = sumBlend[pixel][tintIndex];
                }
            }
        }
    } else {
        for (int y = 0; y < height; ++y) {
            for (int x = width - 1; x >= 0; --x) {
                unsigned char pixel = sourcePixels[y * sourcePitch + x];
                destinationPixels[y * destinationPitch + x] = sumBlend[pixel][tintIndex];
            }
        }
    }

    backSurface->Unlock(destinationDescription.lpSurface);
    reinterpret_cast<IDirectDrawSurface *>(surface)->Unlock(sourceDescription.lpSurface);
    return 1;
}

int Video::DrawSurface(SurfaceRect destination, IUnknown *surface,
    SurfaceRect source, unsigned char colorKey, int flip)
{
    int originalSourceRight = source.right;
    if (destination.top >= destination.bottom || destination.left >= destination.right) return 1;
    if (source.top >= source.bottom || source.left >= source.right) return 1;

    if (destination.top < 0) {
        source.top -= destination.top;
        destination.top = 0;
    }
    if (destination.left < 0) {
        source.left -= destination.left;
        destination.left = 0;
    }
    if (destination.bottom > 240) {
        source.bottom -= destination.bottom - 240;
        destination.bottom = 240;
    }
    if (destination.right > 320) {
        source.right -= destination.right - 320;
        destination.right = 320;
    }
    if (flip != 0) {
        int sourceWidth = originalSourceRight - source.left;
        source.left = originalSourceRight - source.right;
        source.right = sourceWidth;
    }

    if (destination.top >= destination.bottom || destination.left >= destination.right) return 1;
    if (source.top >= source.bottom || source.left >= source.right) return 1;

    DDSURFACEDESC sourceDescription;
    DDSURFACEDESC destinationDescription;
    HRESULT result;
    sourceDescription.dwSize = sizeof(DDSURFACEDESC);
    destinationDescription.dwSize = sizeof(DDSURFACEDESC);

    result = reinterpret_cast<IDirectDrawSurface *>(surface)->Lock(
        reinterpret_cast<RECT *>(&source), &sourceDescription, DDLOCK_WAIT | DDLOCK_READONLY, 0);
    if (result != DD_OK) {
        if (result == DDERR_SURFACELOST) return 0;
        return 1;
    }
    result = backSurface->Lock(reinterpret_cast<RECT *>(&destination),
        &destinationDescription, DDLOCK_WAIT, 0);
    if (result != DD_OK) {
        if (result == DDERR_SURFACELOST) return 0;
        return 1;
    }

    unsigned char *sourcePixels = static_cast<unsigned char *>(sourceDescription.lpSurface);
    unsigned char *destinationPixels = static_cast<unsigned char *>(destinationDescription.lpSurface);
    int sourcePitch = sourceDescription.lPitch;
    int destinationPitch = destinationDescription.lPitch;
    int width = destination.right - destination.left;
    int height = destination.bottom - destination.top;

    // Advance the locked pixel pointers one pitch per scanline, as in the
    // original's backwards-indexed pixel loops.
    if (colorKey == 0) {
        int rows = height - 1;
        do {
            int x = width - 1;
            do {
                destinationPixels[x] = sourcePixels[x];
            } while (--x >= 0);
            sourcePixels += sourcePitch;
            destinationPixels += destinationPitch;
        } while (--rows >= 0);
    } else if (flip == 0) {
        int rows = height - 1;
        do {
            int x = width - 1;
            do {
                unsigned char pixel = sourcePixels[x];
                if (pixel != colorKey) destinationPixels[x] = pixel;
            } while (--x >= 0);
            sourcePixels += sourcePitch;
            destinationPixels += destinationPitch;
        } while (--rows >= 0);
    } else {
        int rows = height - 1;
        do {
            int x = width - 1;
            do {
                unsigned char pixel = sourcePixels[width - 1 - x];
                if (pixel != colorKey) destinationPixels[x] = pixel;
            } while (--x >= 0);
            sourcePixels += sourcePitch;
            destinationPixels += destinationPitch;
        } while (--rows >= 0);
    }

    backSurface->Unlock(destinationDescription.lpSurface);
    reinterpret_cast<IDirectDrawSurface *>(surface)->Unlock(sourceDescription.lpSurface);
    return 1;
}

int Video::DrawBlendedSurface(SurfaceRect destination, IUnknown *surface,
    SurfaceRect source, unsigned char colorKey, int flip, int alpha)
{
    // The original dispatches on the low signed byte and accepts only 0 or 1.
    signed char blendMode = static_cast<signed char>(alpha);
    if (blendMode != 0 && blendMode != 1) return 0;

    int originalSourceRight = source.right;
    if (destination.top >= destination.bottom || destination.left >= destination.right) return 1;
    if (source.top >= source.bottom || source.left >= source.right) return 1;

    if (destination.top < 0) {
        source.top -= destination.top;
        destination.top = 0;
    }
    if (destination.left < 0) {
        source.left -= destination.left;
        destination.left = 0;
    }
    if (destination.bottom > 240) {
        source.bottom -= destination.bottom - 240;
        destination.bottom = 240;
    }
    if (destination.right > 320) {
        source.right -= destination.right - 320;
        destination.right = 320;
    }
    if (flip != 0) {
        int sourceWidth = originalSourceRight - source.left;
        source.left = originalSourceRight - source.right;
        source.right = sourceWidth;
    }

    if (destination.top >= destination.bottom || destination.left >= destination.right) return 1;
    if (source.top >= source.bottom || source.left >= source.right) return 1;

    DDSURFACEDESC sourceDescription;
    DDSURFACEDESC destinationDescription;
    HRESULT result;
    sourceDescription.dwSize = sizeof(DDSURFACEDESC);
    destinationDescription.dwSize = sizeof(DDSURFACEDESC);

    result = reinterpret_cast<IDirectDrawSurface *>(surface)->Lock(
        reinterpret_cast<RECT *>(&source), &sourceDescription, DDLOCK_WAIT | DDLOCK_READONLY, 0);
    if (result != DD_OK) {
        if (result == DDERR_SURFACELOST) return 0;
        return 1;
    }
    result = backSurface->Lock(reinterpret_cast<RECT *>(&destination),
        &destinationDescription, DDLOCK_WAIT, 0);
    if (result != DD_OK) {
        if (result == DDERR_SURFACELOST) return 0;
        return 1;
    }

    unsigned char *sourcePixels = static_cast<unsigned char *>(sourceDescription.lpSurface);
    unsigned char *destinationPixels = static_cast<unsigned char *>(destinationDescription.lpSurface);
    // meanBlend and sumBlend are adjacent 64 KiB tables; mode 1 selects sumBlend.
    unsigned char *blendTable = reinterpret_cast<unsigned char *>(&meanBlend[0][0]) +
        (static_cast<int>(blendMode) << 16);
    int sourcePitch = sourceDescription.lPitch;
    int destinationPitch = destinationDescription.lPitch;
    int width = destination.right - destination.left;
    int height = destination.bottom - destination.top;

    if (colorKey > 0) {
        if (flip != 0) {
            for (int y = 0; y < height; ++y) {
                for (int x = width - 1; x >= 0; --x) {
                    unsigned char pixel = sourcePixels[y * sourcePitch + (width - 1 - x)];
                    if (pixel != colorKey) {
                        unsigned char destinationPixel = destinationPixels[y * destinationPitch + x];
                        destinationPixels[y * destinationPitch + x] =
                            blendTable[(static_cast<unsigned int>(pixel) << 8) | destinationPixel];
                    }
                }
            }
        } else {
            for (int y = 0; y < height; ++y) {
                for (int x = width - 1; x >= 0; --x) {
                    unsigned char pixel = sourcePixels[y * sourcePitch + x];
                    if (pixel != colorKey) {
                        unsigned char destinationPixel = destinationPixels[y * destinationPitch + x];
                        destinationPixels[y * destinationPitch + x] =
                            blendTable[(static_cast<unsigned int>(pixel) << 8) | destinationPixel];
                    }
                }
            }
        }
    } else {
        for (int y = 0; y < height; ++y) {
            for (int x = width - 1; x >= 0; --x) {
                unsigned char pixel = sourcePixels[y * sourcePitch + x];
                unsigned char destinationPixel = destinationPixels[y * destinationPitch + x];
                destinationPixels[y * destinationPitch + x] =
                    blendTable[(static_cast<unsigned int>(pixel) << 8) | destinationPixel];
            }
        }
    }

    backSurface->Unlock(destinationDescription.lpSurface);
    reinterpret_cast<IDirectDrawSurface *>(surface)->Unlock(sourceDescription.lpSurface);
    return 1;
}

int Video::DrawShadowSurface(SurfaceRect destination, IUnknown *surface,
    SurfaceRect source, unsigned char colorKey, int flip, unsigned char colorIndex)
{
    int originalSourceRight = source.right;
    if (destination.top >= destination.bottom || destination.left >= destination.right) return 1;
    if (source.top >= source.bottom || source.left >= source.right) return 1;

    if (destination.top < 0) destination.top = 0;
    if (destination.left < 0) {
        source.left -= destination.left;
        destination.left = 0;
    }
    if (destination.bottom >= 240) destination.bottom = 240;
    if (destination.right >= 320) {
        source.right -= destination.right - 320;
        destination.right = 320;
    }
    if (flip != 0) {
        int sourceWidth = originalSourceRight - source.left;
        source.left = originalSourceRight - source.right;
        source.right = sourceWidth;
    }

    if (destination.top > destination.bottom || destination.left > destination.right) return 1;
    if (source.top > source.bottom || source.left > source.right) return 1;

    DDSURFACEDESC sourceDescription;
    DDSURFACEDESC destinationDescription;
    HRESULT result;
    sourceDescription.dwSize = sizeof(DDSURFACEDESC);
    destinationDescription.dwSize = sizeof(DDSURFACEDESC);

    result = reinterpret_cast<IDirectDrawSurface *>(surface)->Lock(
        reinterpret_cast<RECT *>(&source), &sourceDescription, DDLOCK_WAIT | DDLOCK_READONLY, 0);
    if (result != DD_OK) {
        if (result == DDERR_SURFACELOST) return 0;
        return 1;
    }
    result = backSurface->Lock(reinterpret_cast<RECT *>(&destination),
        &destinationDescription, DDLOCK_WAIT, 0);
    if (result != DD_OK) {
        if (result == DDERR_SURFACELOST) return 0;
        return 1;
    }

    unsigned char *sourcePixels = static_cast<unsigned char *>(sourceDescription.lpSurface);
    unsigned char *destinationPixels = static_cast<unsigned char *>(destinationDescription.lpSurface);
    unsigned char *blendTable = reinterpret_cast<unsigned char *>(&meanBlend[0][0]);
    int sourcePitch = sourceDescription.lPitch;
    int destinationPitch = destinationDescription.lPitch;
    int width = destination.right - destination.left;
    int height = destination.bottom - destination.top;
    int sourceRowOffset = (source.bottom - source.top - 1) * sourcePitch;

    if (flip != 0) {
        for (int y = 0; y < height; ++y) {
            for (int x = width - 1; x >= 0; --x) {
                unsigned char mask = sourcePixels[sourceRowOffset + (width - 1 - x)];
                if (mask != colorKey) {
                    unsigned char destinationPixel = destinationPixels[y * destinationPitch + x];
                    destinationPixels[y * destinationPitch + x] =
                        blendTable[(static_cast<unsigned int>(destinationPixel) << 8) | colorIndex];
                }
            }
            sourceRowOffset -= sourcePitch * 3;
        }
    } else {
        for (int y = 0; y < height; ++y) {
            for (int x = width - 1; x >= 0; --x) {
                unsigned char mask = sourcePixels[sourceRowOffset + x];
                if (mask != colorKey) {
                    unsigned char destinationPixel = destinationPixels[y * destinationPitch + x];
                    destinationPixels[y * destinationPitch + x] =
                        blendTable[(static_cast<unsigned int>(destinationPixel) << 8) | colorIndex];
                }
            }
            sourceRowOffset -= sourcePitch * 3;
        }
    }

    backSurface->Unlock(destinationDescription.lpSurface);
    reinterpret_cast<IDirectDrawSurface *>(surface)->Unlock(sourceDescription.lpSurface);
    return 1;
}

int Video::DrawCharacterSpecial(SurfaceRect destination, IUnknown *surface,
    SurfaceRect source, unsigned char colorKey, int flip)
{
    int originalSourceRight = source.right;
    if (destination.top >= destination.bottom || destination.left >= destination.right) return 1;
    if (source.top >= source.bottom || source.left >= source.right) return 1;

    if (destination.top < 0) {
        source.top -= destination.top;
        destination.top = 0;
    }
    if (destination.left < 3) {
        source.left -= destination.left - 3;
        destination.left = 3;
    }
    if (destination.bottom > 240) {
        source.bottom -= destination.bottom - 240;
        destination.bottom = 240;
    }
    if (destination.right > 320) {
        source.right -= destination.right - 320;
        destination.right = 320;
    }
    if (flip != 0) {
        int sourceWidth = originalSourceRight - source.left;
        source.left = originalSourceRight - source.right;
        source.right = sourceWidth;
    }

    if (destination.top >= destination.bottom || destination.left >= destination.right) return 1;
    if (source.top >= source.bottom || source.left >= source.right) return 1;

    DDSURFACEDESC sourceDescription;
    DDSURFACEDESC destinationDescription;
    HRESULT result;
    sourceDescription.dwSize = sizeof(DDSURFACEDESC);
    destinationDescription.dwSize = sizeof(DDSURFACEDESC);

    result = reinterpret_cast<IDirectDrawSurface *>(surface)->Lock(
        reinterpret_cast<RECT *>(&source), &sourceDescription, DDLOCK_WAIT | DDLOCK_READONLY, 0);
    if (result != DD_OK) {
        if (result == DDERR_SURFACELOST) return 0;
        return 1;
    }
    result = backSurface->Lock(reinterpret_cast<RECT *>(&destination),
        &destinationDescription, DDLOCK_WAIT, 0);
    if (result != DD_OK) {
        if (result == DDERR_SURFACELOST) return 0;
        return 1;
    }

    unsigned char *sourcePixels = static_cast<unsigned char *>(sourceDescription.lpSurface);
    unsigned char *destinationPixels = static_cast<unsigned char *>(destinationDescription.lpSurface);
    int sourcePitch = sourceDescription.lPitch;
    int destinationPitch = destinationDescription.lPitch;
    int width = destination.right - destination.left;
    int height = destination.bottom - destination.top;

    if (colorKey > 0) {
        if (flip != 0) {
            for (int y = 0; y < height; ++y) {
                for (int x = width - 1; x >= 0; --x) {
                    unsigned char mask = sourcePixels[y * sourcePitch + (width - 1 - x)];
                    if (mask != colorKey) {
                        destinationPixels[y * destinationPitch + x] =
                            destinationPixels[y * destinationPitch + x - 3];
                    }
                }
            }
        } else {
            for (int y = 0; y < height; ++y) {
                for (int x = width - 1; x >= 0; --x) {
                    unsigned char mask = sourcePixels[y * sourcePitch + x];
                    if (mask != colorKey) {
                        destinationPixels[y * destinationPitch + x] =
                            destinationPixels[y * destinationPitch + x - 3];
                    }
                }
            }
        }
    } else {
        for (int y = 0; y < height; ++y) {
            for (int x = width - 1; x >= 0; --x) {
                destinationPixels[y * destinationPitch + x] =
                    destinationPixels[y * destinationPitch + x - 3];
            }
        }
    }

    backSurface->Unlock(destinationDescription.lpSurface);
    reinterpret_cast<IDirectDrawSurface *>(surface)->Unlock(sourceDescription.lpSurface);
    return 1;
}
