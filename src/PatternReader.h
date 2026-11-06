// Raw binary file access; names are provisional reconstruction identifiers.
#ifndef EFZ_PATTERN_READER_H
#define EFZ_PATTERN_READER_H
#include <windows.h>

class PatternReader {
    HANDLE file;
    unsigned char *buffer;
    unsigned char unknown_0008[4]; // Complete original type/alignment remains unresolved.
public:
    PatternReader(const char *, int);
    ~PatternReader();
    int Open(const char *, int);
    int Close();
    int Read(void *, int);
    int ReadLine(char *, int);
    int ReadInt();
    short ReadShort();
    float ReadFloat();
    int Write(const void *, int);
    void WriteInt(int);
    void WriteFloat(float);
    int Printf(const char *, ...);
    DWORD Seek(int, int);
    DWORD SeekStart();
    DWORD SeekEnd();
    DWORD Size();
    int IsOpen();
    int Reset();
    unsigned char *LoadBuffer(const char *);
};
#endif
