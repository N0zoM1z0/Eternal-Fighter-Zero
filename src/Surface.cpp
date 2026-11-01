// Original surface creation, bitmap transfer and packed run decoding.
#include "Engine.h"
extern const char bitmapFailure[], packedFailure[];

SurfaceRect MakeSurfaceRect(int x, int y, int width, int height)
{
    SurfaceRect rect;
    rect.left = x;
    rect.right = x + width;
    rect.top = y;
    rect.bottom = y + height;
    return rect;
}

SurfaceRect Video::LoadSurface(IUnknown **surface, const char *path, unsigned char paletteOffset)
{
    HANDLE file = CreateFileA(path, GENERIC_READ, 0, 0, OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, 0);
    {
        DDSURFACEDESC lock;
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
                                    MessageBoxA(0, bitmapFailure, path, 0);
                                    return MakeSurfaceRect(0, 0, 0, 0);
                                }
                                lock.dwSize = sizeof(DDSURFACEDESC);
                                offset = buffer[10] + (buffer[11] << 8);
                                result = reinterpret_cast<IDirectDrawSurface *>(*surface)->Lock(0, &lock, DDLOCK_WAIT, 0);
                                pixels = static_cast<unsigned char *>(lock.lpSurface);
                                for (int y = 0; y < dimensions.height; ++y) {
                                    for (int x = 0; x < dimensions.width; ++x) {
                                        pixels[(dimensions.height - 1 - y) * lock.lPitch + x] = buffer[y * dimensions.width + x + offset] + paletteOffset;
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

int Video::DecodeSurface(IUnknown **surface, const unsigned char *buffer,
    unsigned char marker, unsigned char paletteOffset)
{
    DDSURFACEDESC lock;
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
                        MessageBoxA(0, packedFailure, 0, 0);
                        return 0;
                    }
                    lock.dwSize = sizeof(DDSURFACEDESC);
                    result = reinterpret_cast<IDirectDrawSurface *>(*surface)->Lock(0, &lock, DDLOCK_WAIT, 0);
                    pixels = static_cast<unsigned char *>(lock.lpSurface);
                    if (!marker) {
                        for (int y = 0; y < height; ++y) {
                            for (int x = 0; x < width; ++x) {
                                pixels[(height - 1 - y) * lock.lPitch + x] = buffer[y * width + x + 4] + paletteOffset;
                                ++position;
                            }
                        }
                    } else {
                        for (int y = 0; y < height; ++y) {
                            for (int x = 0; x < width; ++x) {
                                if (!repeat) {
                                    if (buffer[position] <= marker) {
                                        value = buffer[position] + paletteOffset;
                                        ++position;
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
