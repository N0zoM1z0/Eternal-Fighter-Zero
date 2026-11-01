// Complete context lifetime and pattern ownership reconstructed from original code.
#include "Engine.h"
extern "C" unsigned char __cdecl ReadConfigByte(unsigned char);
extern const char patternPath[];

Context::Context(Video *video, Input *input, Audio *audio)
{
    int i;
    videoOwner = video;
    inputOwner = input;
    audioOwner = audio;
    flag0f32 = 0;
    field1382 = 0;
    field1380 = 0;
    for (i = 0; i < 0x41; ++i) soundSlots[i] = 150;
    audioMode = 150;
    extraC = 0;
    extraA = 0;
    extraB = 0;
    for (i = 0; i < 0x398; ++i) textures[i] = 0;
    blob = 0;
    patterns = 0;
    configured = ReadConfigByte(0x21) > 0;
    if (configured) {
        setting1365 = ReadConfigByte(0x21);
        setting136c = ReadConfigByte(0x22) - 1;
        setting1366 = ReadConfigByte(0x23) - 1;
        setting1370 = ReadConfigByte(0x24);
        setting134f = ReadConfigByte(0x26);
        flag1345 = 0;
    } else {
        setting1365 = 2;
        setting136c = 1;
        setting1366 = 1;
        setting1370 = 2;
        setting134f = 2;
        flag1345 = 0;
    }
    InitializeState();
    ResetState();
}

Context::~Context()
{
    int i;
    for (i = 0; i < 0x398; ++i) {
        if (textures[i]) {
            textures[i]->Release();
            textures[i] = 0;
        }
    }
    if (extraA) { extraA->Release(); extraA = 0; }
    if (extraB) { extraB->Release(); extraB = 0; }
    if (extraC) { extraC->Release(); extraC = 0; }
    for (i = 0; i < 0x41; ++i) {
        if (soundSlots[i] != 150) audioOwner->ReleaseSound(soundSlots[i]);
    }
    if (audioMode != 150) audioOwner->ReleaseSound(audioMode);
    if (patterns) delete[] patterns;
    if (blob) { delete[] blob; blob = 0; }
}

PatternSequence::PatternSequence() { frames = 0; }
PatternSequence::~PatternSequence() { if (frames) delete[] frames; }
void PatternSequence::Allocate(int size)
{
    count = size;
    if (size > 0) frames = new PatternFrame[size];
}

class PatternReader {
    unsigned char unknown_0000[12];
public:
    PatternReader(const char *, int);
    ~PatternReader();
    int ReadInt();
    void Read(void *, int);
};

void Context::Load()
{
    int block[4];
    {
        int count;
        PatternReader reader(patternPath, 1);
        count = reader.ReadInt();
        patterns = new PatternSequence[count];
        {
            int type, size;
            for (int i = 0; i < count; ++i) {
                type = reader.ReadInt();
                reader.ReadInt();
                reader.ReadInt();
                patterns[i].count = reader.ReadInt();
                size = patterns[i].count;
                patterns[i].Allocate(size);
                for (int j = 0; j < size; ++j) {
                    patterns[i].frames[j].x = reader.ReadInt();
                    patterns[i].frames[j].y = reader.ReadInt();
                    patterns[i].frames[j].width = reader.ReadInt();
                    patterns[i].frames[j].height = reader.ReadInt();
                    patterns[i].frames[j].u = reader.ReadInt();
                    patterns[i].frames[j].v = reader.ReadInt();
                    reader.ReadInt(); reader.ReadInt(); reader.ReadInt(); reader.ReadInt();
                    reader.ReadInt(); reader.ReadInt(); reader.ReadInt(); reader.ReadInt();
                    reader.ReadInt(); reader.ReadInt(); reader.ReadInt(); reader.ReadInt();
                    reader.ReadInt(); reader.ReadInt();
                    for (int k = 0; k < 10; ++k) {
                        reader.Read(block, 16);
                    }
                }
            }
        }
    }
}
