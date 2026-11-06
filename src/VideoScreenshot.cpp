// Original 320x240 indexed BMP screenshot writer.
#include "Engine.h"
#include <string.h>
#include <stdlib.h>
extern const char screenshotPrefix[], screenshotZeroThousands[], screenshotZeroHundreds[];
extern const char screenshotZeroTens[], screenshotExtension[];

void Video::SaveScreenshot(int index, const unsigned char *colors)
{
    char filename[32];
    {
        DDSURFACEDESC desc;
        {
            unsigned char *bitmap;
            {
                char number[12];
                {
                    struct CaptureWork {
                        int column, row;
                        HRESULT lockResult;
                        int stride;
                        DWORD bytesWritten;
                        HANDLE handle;
                        unsigned char *source;
                    } work;
                    _strnset(filename, 0, 30);
                    strcat(filename, screenshotPrefix);
                    if (index < 1000) strcat(filename, screenshotZeroThousands);
                    if (index < 100) strcat(filename, screenshotZeroHundreds);
                    if (index < 10) strcat(filename, screenshotZeroTens);
                    _itoa(index, number, 10);
                    strcat(filename, number);
                    strcat(filename, screenshotExtension);
                    work.handle = CreateFileA(filename, GENERIC_READ | GENERIC_WRITE, 0, 0, OPEN_ALWAYS, FILE_ATTRIBUTE_NORMAL, 0);
                    bitmap = new unsigned char[0x13036];
                    desc.dwSize = sizeof(desc);
                    work.lockResult = backSurface->Lock(0, &desc, DDLOCK_WAIT, 0);
                    work.source = static_cast<unsigned char *>(desc.lpSurface);
                    work.stride = (flag0004 + 1) * 320;
                    for (work.row = 0; work.row < 240; ++work.row) {
                        for (work.column = 0; work.column < 320; ++work.column) {
                            bitmap[0x12ef6 - work.row * 320 + work.column] = work.source[work.row * work.stride + work.column];
                        }
                    }
                    work.lockResult = backSurface->Unlock(desc.lpSurface);
                    for (work.row = 0; work.row < 256; ++work.row) {
                        bitmap[work.row * 4 + 0x36] = colors[work.row * 4 + 2];
                        bitmap[work.row * 4 + 0x37] = colors[work.row * 4 + 1];
                        bitmap[work.row * 4 + 0x38] = colors[work.row * 4];
                        bitmap[work.row * 4 + 0x39] = 0;
                    }
                    for (work.row = 0; work.row < 0x3a; ++work.row) bitmap[work.row] = 0;
                    bitmap[0] = 0x42;
                    bitmap[1] = 0x4d;
                    bitmap[2] = 0x36;
                    bitmap[3] = 0x30;
                    bitmap[4] = 1;
                    bitmap[10] = 0x36;
                    bitmap[11] = 4;
                    bitmap[14] = 0x28;
                    bitmap[18] = 0x40;
                    bitmap[19] = 1;
                    bitmap[22] = 0xf0;
                    bitmap[26] = 1;
                    bitmap[28] = 8;
                    bitmap[47] = 1;
                    WriteFile(work.handle, bitmap, 0x13036, &work.bytesWritten, 0);
                    CloseHandle(work.handle);
                    delete[] bitmap;
                }
            }
        }
    }
}
