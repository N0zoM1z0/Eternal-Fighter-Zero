// Character counters use the original nine-word file record, including its reserved zero word.
#include "Engine.h"
#include <cstring>
extern const char statisticsReadPrefix[], statisticsReadSeparator[], statisticsReadExtension[];
extern const char statisticsWritePrefix[], statisticsWriteSeparator[], statisticsWriteExtension[];

void CharacterStatistics::Write(const char *name)
{
    HANDLE file = 0;
    {
        DWORD transferred;
        {
            char path[32];
            {
                int record[9];
                std::strcpy(path, statisticsWritePrefix);
                std::strcat(path, name);
                std::strcat(path, statisticsWriteSeparator);
                std::strcat(path, name);
                std::strcat(path, statisticsWriteExtension);
                file = CreateFileA(path, GENERIC_WRITE, 0, 0, CREATE_ALWAYS, FILE_ATTRIBUTE_NORMAL, 0);
                if (file != INVALID_HANDLE_VALUE) {
                    record[0] = values[0];
                    record[1] = values[1];
                    record[2] = values[2];
                    record[3] = values[3];
                    record[4] = values[4];
                    record[5] = values[5];
                    record[6] = values[6];
                    record[7] = values[7];
                    record[8] = 0;
                    WriteFile(file, record, 36, &transferred, 0);
                }
                CloseHandle(file);
            }
        }
    }
}

void CharacterStatistics::Read(const char *name)
{
    HANDLE file = 0;
    {
        DWORD size;
        {
            DWORD transferred;
            {
                char path[32];
                {
                    int record[9];
                    std::strcpy(path, statisticsReadPrefix);
                    std::strcat(path, name);
                    std::strcat(path, statisticsReadSeparator);
                    std::strcat(path, name);
                    std::strcat(path, statisticsReadExtension);
                    values[0] = 0;
                    values[1] = 0;
                    values[2] = 0;
                    values[3] = 0;
                    values[4] = 0;
                    values[5] = 0;
                    values[6] = 0;
                    values[7] = 0;
                    file = CreateFileA(path, GENERIC_READ, 0, 0, OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, 0);
                    if (file != INVALID_HANDLE_VALUE) {
                        size = GetFileSize(file, 0);
                        ReadFile(file, record, size, &transferred, 0);
                        values[0] = record[0];
                        values[1] = record[1];
                        values[2] = record[2];
                        values[3] = record[3];
                        values[4] = record[4];
                        values[5] = record[5];
                        values[6] = record[6];
                        values[7] = record[7];
                    }
                    CloseHandle(file);
                }
            }
        }
    }
}
