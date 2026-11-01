// Word-oriented file access with the original handle and read-count behavior.
#include "Engine.h"

extern const char wordReadTitle[], wordReadError[];
extern const char wordWriteTitle[], wordWriteError[];

WordFile::WordFile() { exhausted = 0; file = 0; }
WordFile::~WordFile() { if (file) CloseHandle(file); }

unsigned int WordFile::OpenRead(const char *path)
{
    file = CreateFileA(path, GENERIC_READ, 0, 0, OPEN_ALWAYS, FILE_ATTRIBUTE_NORMAL, 0);
    if (file == INVALID_HANDLE_VALUE) return 0;
    remaining = GetFileSize(file, 0);
    transferred = 0;
    exhausted = 0;
    return remaining;
}

void WordFile::OpenWrite(const char *path)
{
    file = CreateFileA(path, GENERIC_WRITE, 0, 0, CREATE_ALWAYS, FILE_ATTRIBUTE_NORMAL, 0);
    if (file == INVALID_HANDLE_VALUE) return;
    exhausted = 0;
}

void WordFile::Close()
{
    if (file) { CloseHandle(file); file = 0; }
}

unsigned short WordFile::ReadWord()
{
    unsigned short value;
    if (remaining <= 0) { exhausted = 1; return 0; }
    if (!ReadFile(file, &value, 2, &transferred, 0)) {
        MessageBoxA(0, wordReadError, wordReadTitle, 0);
        return 0;
    }
    remaining -= 2;
    return value;
}

void WordFile::WriteWord(unsigned short value)
{
    DWORD written;
    {
        unsigned short copy = value;
        if (!WriteFile(file, &copy, 2, &written, 0)) {
            MessageBoxA(0, wordWriteError, wordWriteTitle, 0);
        }
    }
}
