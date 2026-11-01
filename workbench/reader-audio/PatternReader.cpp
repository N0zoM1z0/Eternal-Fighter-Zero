// Original raw file primitives, ownership and scalar/line access.
#include "PatternReader.h"
#include <cstdarg>
#include <cstdio>
#include <cstring>

PatternReader::PatternReader(const char *path, int mode) { Reset(); Open(path, mode); }
PatternReader::~PatternReader() { Close(); }

int PatternReader::Open(const char *path, int mode)
{
    SECURITY_ATTRIBUTES attributes;
    Close();
    {
    DWORD access = 0;
    DWORD creation = 0;
    if (mode & 1) access |= GENERIC_READ;
    if (mode & 2) access |= GENERIC_WRITE;
    if (mode & 16) creation = TRUNCATE_EXISTING;
    if (mode & 32) creation = OPEN_ALWAYS;
    if ((mode & 16) && (mode & 32)) creation = CREATE_ALWAYS;
    if (!(mode & 16) && !(mode & 32)) creation = OPEN_EXISTING;
    attributes.nLength = sizeof(attributes);
    attributes.lpSecurityDescriptor = 0;
    attributes.bInheritHandle = TRUE;
    file = CreateFileA(path, access, 3, &attributes, creation, FILE_ATTRIBUTE_NORMAL, 0);
    if (file == INVALID_HANDLE_VALUE) { file = 0; return 0; }
    return 1;
    }
}

int PatternReader::Close()
{
    if (file) { CloseHandle(file); file = 0; }
    if (buffer) { delete[] buffer; buffer = 0; }
    Reset();
    return 1;
}

int PatternReader::Read(void *destination, int size)
{
    DWORD transferred;
    if (!IsOpen()) return 0;
    ReadFile(file, destination, size, &transferred, 0);
    return transferred;
}

int PatternReader::ReadLine(char *destination, int size)
{
    unsigned char line[1000];
    {
    int i;
    for (i = 0; i < size - 1; ++i) {
        if (!Read(&line[i], 1)) break;
        if (line[i] == 10) break;
    }
    line[i] = 0;
    if (destination) std::strcpy(destination, reinterpret_cast<const char *>(line));
    return i - 1;
    }
}

int PatternReader::ReadInt() { int value; Read(&value, 4); return value; }
short PatternReader::ReadShort() { short value; Read(&value, 2); return value; }
float PatternReader::ReadFloat() { float value; Read(&value, 4); return value; }

int PatternReader::Write(const void *source, int size)
{
    DWORD transferred;
    if (!IsOpen()) return 0;
    WriteFile(file, source, size, &transferred, 0);
    return transferred;
}

void PatternReader::WriteInt(int value) { Write(&value, 4); }
void PatternReader::WriteFloat(float value) { Write(&value, 4); }

int PatternReader::Printf(const char *format, ...)
{
    char text[256];
    va_list arguments;
    va_start(arguments, format);
    std::vsprintf(text, format, arguments);
    Write(text, std::strlen(text));
    va_end(arguments);
    return 1;
}

DWORD PatternReader::Seek(int offset, int origin)
{
    DWORD method;
    if (!IsOpen()) return 0;
    if (origin == 0) method = FILE_CURRENT;
    if (origin == 1) method = FILE_CURRENT;
    if (origin == 0) method = FILE_BEGIN;
    if (origin == 2) method = FILE_END;
    return SetFilePointer(file, offset, 0, method);
}

DWORD PatternReader::SeekStart() { if (!IsOpen()) return 0; return SetFilePointer(file, 0, 0, FILE_BEGIN); }
DWORD PatternReader::SeekEnd() { if (!IsOpen()) return 0; return SetFilePointer(file, 0, 0, FILE_END); }
DWORD PatternReader::Size() { if (!IsOpen()) return 0; return GetFileSize(file, 0); }
int PatternReader::IsOpen() { if (file) return 1; return 0; }
int PatternReader::Reset() { file = 0; buffer = 0; return 1; }

unsigned char *PatternReader::LoadBuffer(const char *path)
{
    Close();
    if (!Open(path, 1)) return 0;
    buffer = new unsigned char[Size() + 1];
    buffer[Size()] = 0;
    Read(buffer, Size());
    return buffer;
}
