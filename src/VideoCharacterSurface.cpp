// Character-specific bitmap and packed-surface palette mapping.
#include "Engine.h"
extern const char characterBitmapFailure[], characterPackedFailure[];
SurfaceRect MakeSurfaceRect(int, int, int, int);

SurfaceRect Video::LoadBitmapSurface(IUnknown **surface, const char *path, unsigned char paletteOffset)
{
    HANDLE file = CreateFileA(path, GENERIC_READ, 0, 0, OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, 0);
    {
        DDSURFACEDESC lock;
        {
            unsigned char pixel;
            {
                unsigned char *pixels;
                {
                    int offset;
                    {
                        DWORD size = GetFileSize(file, 0);
                        DWORD bytesRead;
                        {
                            struct Dimensions { int width, height; };
                            Dimensions dimensions;
                            {
                                HRESULT result;
                                unsigned char *buffer = new unsigned char[size];
                                ReadFile(file, buffer, size, &bytesRead, 0);
                                dimensions.width = buffer[18] + (buffer[19] << 8);
                                dimensions.width += (4 - dimensions.width % 4) * (dimensions.width % 4 > 0);
                                dimensions.height = buffer[22] + (buffer[23] << 8);
                                {
                                    DDSURFACEDESC create;
                                    create.dwSize = sizeof(DDSURFACEDESC);
                                    create.dwFlags = DDSD_CAPS | DDSD_WIDTH | DDSD_HEIGHT;
                                    create.ddsCaps.dwCaps = DDSCAPS_OFFSCREENPLAIN | DDSCAPS_SYSTEMMEMORY;
                                    create.dwWidth = dimensions.width;
                                    create.dwHeight = dimensions.height;
                                    result = directDraw->CreateSurface(&create, reinterpret_cast<IDirectDrawSurface **>(surface), 0);
                                    if (result != DD_OK) {
                                        MessageBoxA(0, characterBitmapFailure, path, 0);
                                        return MakeSurfaceRect(0, 0, 0, 0);
                                    }
                                    lock.dwSize = sizeof(DDSURFACEDESC);
                                    offset = buffer[10] + (buffer[11] << 8);
                                    result = reinterpret_cast<IDirectDrawSurface *>(*surface)->Lock(0, &lock, DDLOCK_WAIT, 0);
                                    pixels = static_cast<unsigned char *>(lock.lpSurface);
                                    for (int y = 0; y < dimensions.height; ++y) {
                                        for (int x = 0; x < dimensions.width; ++x) {
                                            pixel = buffer[y * dimensions.width + x + offset];
                                            if (pixel >= 40) pixels[(dimensions.height - 1 - y) * lock.lPitch + x] = pixel + 135;
                                            else pixels[(dimensions.height - 1 - y) * lock.lPitch + x] = pixel + paletteOffset;
                                        }
                                    }
                                    result = reinterpret_cast<IDirectDrawSurface *>(*surface)->Unlock(lock.lpSurface);
                                    CloseHandle(file);
                                    delete[] buffer;
                                    return MakeSurfaceRect(0, 0, dimensions.width, dimensions.height);
                                }
                            }
                        }
                    }
                }
            }
        }
    }
}

int Video::DecodeCharacterSurface(IUnknown **surface, const unsigned char *buffer,
unsigned char marker, unsigned char paletteOffset)
{
    DDSURFACEDESC lock;
    {
        unsigned char pixel;
        {
            unsigned char *pixels;
            {
                int width, height;
                HRESULT result;
                int position = 0;
                {
                    unsigned char repeat = 0;
                    unsigned char value = 0;
                    width = buffer[position] + (buffer[position + 1] << 8);
                    height = buffer[position + 2] + (buffer[position + 3] << 8);
                    position += 4;
                    {
                        DDSURFACEDESC create;
                        create.dwSize = sizeof(DDSURFACEDESC);
                        create.dwFlags = DDSD_CAPS | DDSD_WIDTH | DDSD_HEIGHT;
                        create.ddsCaps.dwCaps = DDSCAPS_OFFSCREENPLAIN | DDSCAPS_SYSTEMMEMORY;
                        create.dwWidth = width;
                        create.dwHeight = height;
                        result = directDraw->CreateSurface(&create, reinterpret_cast<IDirectDrawSurface **>(surface), 0);
                        if (result != DD_OK) {
                            MessageBoxA(0, characterPackedFailure, 0, 0);
                            return 0;
                        }
                        lock.dwSize = sizeof(DDSURFACEDESC);
                        result = reinterpret_cast<IDirectDrawSurface *>(*surface)->Lock(0, &lock, DDLOCK_WAIT, 0);
                        pixels = static_cast<unsigned char *>(lock.lpSurface);
                        if (!marker) {
                            for (int y = 0; y < height; ++y) {
                                for (int x = 0; x < width; ++x) {
                                    pixel = buffer[y * width + x + 4];
                                    if (pixel >= 40) pixels[(height - 1 - y) * lock.lPitch + x] = pixel + 135;
                                    else pixels[(height - 1 - y) * lock.lPitch + x] = pixel + paletteOffset;
                                    ++position;
                                }
                            }
                        } else {
                            for (int y = 0; y < height; ++y) {
                                for (int x = 0; x < width; ++x) {
                                    if (!repeat) {
                                        if (buffer[position] <= marker) {
                                            if (buffer[position] >= 40) {
                                                value = buffer[position] + 135;
                                                ++position;
                                            } else {
                                                value = buffer[position] + paletteOffset;
                                                ++position;
                                            }
                                        } else {
                                            repeat = buffer[position] - marker - 1;
                                            ++position;
                                        }
                                    } else --repeat;
                                    pixels[y * lock.lPitch + x] = value;
                                }
                            }
                        }
                        result = reinterpret_cast<IDirectDrawSurface *>(*surface)->Unlock(lock.lpSurface);
                        return position;
                    }
                }
            }
        }
    }
}
