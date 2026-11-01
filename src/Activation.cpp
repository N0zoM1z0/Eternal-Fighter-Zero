// Complete packed/raw effect initialization, including the original inactive branch.
#include "Engine.h"
#include <cstdlib>
#include <cstring>
extern const char effectDataPath[], objectDataPath[], objectPalettePath[];
extern const char effectPrefix[], effectPrefix0[], effectPrefix00[], bitmapExtension[];
extern const char objectBitmapPath[], objectBitmapPalettePath[];

void Context::Activate()
{
    char path[32];
    char number[8];
    // Preserve the original integer guard and its complete inactive BMP branch.
    if (1) {
        HANDLE hFile;
        {
            int length;
            int offset = 0;
            hFile = CreateFileA(effectDataPath, GENERIC_READ, 0, 0, OPEN_EXISTING,
                FILE_ATTRIBUTE_NORMAL, 0);
            {
                DWORD size = GetFileSize(hFile, 0);
                DWORD bytesRead;
                {
                    unsigned char *buffer = new unsigned char[size];
                    ReadFile(hFile, buffer, size, &bytesRead, 0);
                    offset = buffer[0] * 3 + 1;
                    {
                        char error[100];
                        for (int i = 0; i <= 0x397; ++i) {
                            length = videoOwner->DecodeSurface(&textures[i], buffer + offset, 0x51, 0xaf);
                            if (!length) {
                                _itoa(i, error, 10);
                                MessageBoxA(0, error, 0, 0);
                            } else offset += length;
                        }
                    }
                    CloseHandle(hFile);
                    delete[] buffer;
                }
            }
        }
        LoadObjectFile(&extraC, objectDataPath, 0, 0xaf);
        videoOwner->LoadPalette(reinterpret_cast<unsigned char *>(this) + 0xf35,
            objectPalettePath, 0, 0xaf, 0x50);
    } else {
        for (int j = 0; j <= 0x397; ++j) {
            if (j >= 100) std::strcpy(path, effectPrefix);
            else if (j >= 10) std::strcpy(path, effectPrefix0);
            else std::strcpy(path, effectPrefix00);
            _itoa(j, number, 10);
            std::strcat(path, number);
            std::strcat(path, bitmapExtension);
            videoOwner->LoadSurface(&textures[j], path, 0xaf);
        }
        videoOwner->LoadSurface(&extraC, objectBitmapPath, 0xaf);
        videoOwner->LoadBitmapPalette(reinterpret_cast<unsigned char *>(this) + 0xf35,
            objectBitmapPalettePath, 0, 0xaf, 0x50);
    }
    *(reinterpret_cast<unsigned char *>(this) + 0xf34) = videoOwner->SurfaceProperty(extraC);
}

void Context::LoadObjectFile(IUnknown **surface, const char *path,
    unsigned char first, unsigned char second)
{
    HANDLE file = CreateFileA(path, GENERIC_READ, 0, 0, OPEN_EXISTING,
        FILE_ATTRIBUTE_NORMAL, 0);
    DWORD size = GetFileSize(file, 0);
    DWORD bytesRead;
    {
        unsigned char *buffer = new unsigned char[size];
        ReadFile(file, buffer, size, &bytesRead, 0);
        videoOwner->DecodeSurface(surface, buffer + buffer[0] * 3 + 1, first, second);
        CloseHandle(file);
        delete[] buffer;
    }
}
