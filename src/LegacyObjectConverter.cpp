// Original single-pass bitmap-to-object conversion helper (no known callers).
// The original opens fixed filenames even after constructing numbered paths.
#include <windows.h>
#include <cstring>
#include <cstdlib>

void ConvertLegacyObjectData()
{
    // Keep the two related filename buffers together, in their native order.
    struct FileNames { char digits[12]; char path[32]; } names;
    {
        HANDLE bitmap;
        HANDLE object;
        for (int index = 0; index <= 0; ++index) {
            // Preserve the original local-field lifetimes and WriteFile size copy.
            struct LoopVariables {
                int cursor;
                DWORD writeSize;
                unsigned char *input;
                DWORD transferred;
                DWORD size;
                unsigned char *output;
                BOOL result;
            } local;
            _strnset(names.path, 0, 30);
            std::strcat(names.path, "ayu0\\");
            if (index < 100) std::strcat(names.path, "0");
            if (index < 10) std::strcat(names.path, "0");
            _itoa(index, names.digits, 10);
            std::strcat(names.path, names.digits);
            std::strcat(names.path, ".bmp");
            bitmap = CreateFileA("system0\\object.bmp", GENERIC_READ, 0, 0, OPEN_ALWAYS, FILE_ATTRIBUTE_NORMAL, 0);
            _strnset(names.path, 0, 30);
            std::strcat(names.path, "ayu\\");
            if (index < 100) std::strcat(names.path, "0");
            if (index < 10) std::strcat(names.path, "0");
            _itoa(index, names.digits, 10);
            std::strcat(names.path, names.digits);
            std::strcat(names.path, ".dat");
            object = CreateFileA("system\\object.dat", GENERIC_READ | GENERIC_WRITE, 0, 0, OPEN_ALWAYS, FILE_ATTRIBUTE_NORMAL, 0);
            local.size = GetFileSize(bitmap, 0);
            local.input = new unsigned char[local.size];
            local.result = ReadFile(bitmap, local.input, local.size, &local.transferred, 0);
            local.output = new unsigned char[local.size - 10];
            for (local.cursor = 0; local.cursor < (int)(local.size - 10); ++local.cursor) {
                local.output[local.cursor] = local.input[local.cursor + 10] ^ 100;
            }
            local.writeSize = local.size - 10;
            local.result = WriteFile(object, local.output, local.writeSize, &local.transferred, 0);
            CloseHandle(bitmap);
            CloseHandle(object);
            delete[] local.input;
            delete[] local.output;
        }
    }
}
