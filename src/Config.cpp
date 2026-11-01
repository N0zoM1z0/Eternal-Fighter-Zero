// Provisional source reconstruction from EFZ.exe SHA-256 3a1616d6...dd66481.
// Complete function at 0x00405A20. Names and original TU partition are unknown.
#include <windows.h>

extern "C" const char efz_key_ini[];
extern "C" const char efz_key_ini_update_read[];
extern "C" const char efz_key_ini_update_write[];

extern "C" unsigned char __cdecl ReadConfigByte(unsigned char index)
{
    DWORD bytesRead;
    DWORD size;
    unsigned char value;
    HANDLE file = 0;
    value = 0;
    file = CreateFileA(efz_key_ini, GENERIC_READ | GENERIC_WRITE, 0, 0,
                       OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, 0);
    if (file != INVALID_HANDLE_VALUE && GetFileSize(file, 0) >= 32) {
        size = GetFileSize(file, 0);
        unsigned char *buffer = new unsigned char[size];
        ReadFile(file, buffer, size, &bytesRead, 0);
        value = buffer[index];
        delete[] buffer;
    }
    CloseHandle(file);
    return value;
}

// Complete function at 0x00405AE0. The original returns a zero byte.
extern "C" unsigned char __cdecl WriteConfigByte(unsigned char index, unsigned char newValue)
{
    DWORD bytesRead;
    DWORD size;
    unsigned char value;
    HANDLE file = 0;
    value = 0;
    file = CreateFileA(efz_key_ini_update_read, GENERIC_READ | GENERIC_WRITE, 0, 0,
                       OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, 0);
    if (file != INVALID_HANDLE_VALUE && GetFileSize(file, 0) >= 32) {
        size = GetFileSize(file, 0);
        unsigned char *buffer = new unsigned char[size];
        ReadFile(file, buffer, size, &bytesRead, 0);
        CloseHandle(file);
        buffer[index] = newValue;
        file = CreateFileA(efz_key_ini_update_write, GENERIC_READ | GENERIC_WRITE, 0, 0,
                           CREATE_ALWAYS, FILE_ATTRIBUTE_NORMAL, 0);
        WriteFile(file, buffer, size, &bytesRead, 0);
        delete[] buffer;
    }
    CloseHandle(file);
    return value;
}
