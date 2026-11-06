// DirectSound resource ownership, native PCM loading and loop maintenance.
#include "Engine.h"
#include <cstring>

extern const char audioinitializeTitle[], audioinitializeError[];
extern const char audiocooperativeTitle[], audiocooperativeError[];
extern const char audiolockTitle[], audiolockError[];
extern const char audiounlockTitle[], audiounlockError[];
extern const char audioreleaseTitle[], audioreleaseError[];
extern const char audiocreateTitle[], audiocreateError[];
extern const char audiofullTitle[], audiofullError[];
extern const char audioriffTitle[], audioriffError[];
extern const char audioformatTitle[], audioformatError[];
extern const char audioreadFormatTitle[], audioreadFormatError[];
extern const char audiopcmTitle[], audiopcmError[];
extern const char audioascendTitle[], audioascendError[];
extern const char audiodataTitle[], audiodataError[];
extern const char audioallocateTitle[], audioallocateError[];
extern const char audioreadDataTitle[], audioreadDataError[];

Audio::Audio()
{
    loopEnd = 0;
    loopStart = 0;
    for (int i = 0; i < 150; ++i) { samples[i] = 0; buffers[i] = 0; }
}

Audio::~Audio()
{
    for (unsigned short i = 0; i < 150; ++i) {
        if (buffers[i]) {
            ReleaseBuffer(i);
            if (samples[i]) { delete[] samples[i]; samples[i] = 0; }
            buffers[i] = 0;
        }
    }
    if (directSound) { directSound->Release(); directSound = 0; }
}

void Audio::Shutdown()
{
    for (unsigned short i = 0; i < 150; ++i) {
        if (buffers[i]) {
            ReleaseBuffer(i);
            if (samples[i]) { delete[] samples[i]; samples[i] = 0; }
            buffers[i] = 0;
        }
    }
    if (directSound) { directSound->Release(); directSound = 0; }
}

void Audio::Initialize(HWND handle)
{
    unsigned short i;
    HRESULT result;
    window = handle;
    for (i = 0; i < 150; ++i) buffers[i] = 0;
    result = DirectSoundCreate(0, &directSound, 0);
    if (result != DS_OK) { MessageBoxA(window, audioinitializeError, audioinitializeTitle, 0); return; }
    result = directSound->SetCooperativeLevel(window, 3);
    if (result != DS_OK) MessageBoxA(window, audiocooperativeError, audiocooperativeTitle, 0);
}

void Audio::FillBuffer(unsigned short id)
{
    void *first;
    DWORD firstSize, secondSize;
    {
        void *second;
        HRESULT result;
        if (buffers[id]) {
            result = buffers[id]->Lock(0, sampleSizes[id], &first, &firstSize, &second, &secondSize, 0);
            if (result == DSERR_BUFFERLOST) {
                buffers[id]->Restore();
                result = buffers[id]->Lock(0, sampleSizes[id], &first, &firstSize, &second, &secondSize, 0);
            }
            if (result != DS_OK) MessageBoxA(window, audiolockError, audiolockTitle, 0);
            std::memcpy(first, samples[id], firstSize);
            if (second) std::memcpy(second, samples[id] + firstSize, secondSize);
            result = buffers[id]->Unlock(first, firstSize, second, secondSize);
            if (result != DS_OK) MessageBoxA(window, audiounlockError, audiounlockTitle, 0);
        }
    }
}

void Audio::ReleaseBuffer(unsigned short id)
{
    HRESULT result;
    if (buffers[id]) {
        result = buffers[id]->Release();
        if (result != 0) MessageBoxA(window, audioreleaseError, audioreleaseTitle, 0);
        buffers[id] = 0;
    }
}

void Audio::CreateBuffer(unsigned short id, const WAVEFORMATEX *format)
{
    DSBUFFERDESC description;
    {
        PCMWAVEFORMAT pcm;
        HRESULT result;
        std::memset(&pcm, 0, sizeof(pcm));
        pcm.wf.wFormatTag = WAVE_FORMAT_PCM;
        pcm.wf.nChannels = format->nChannels;
        pcm.wf.nSamplesPerSec = format->nSamplesPerSec;
        pcm.wf.nBlockAlign = format->nBlockAlign;
        pcm.wf.nAvgBytesPerSec = pcm.wf.nBlockAlign * pcm.wf.nSamplesPerSec;
        pcm.wBitsPerSample = (format->nBlockAlign << 3) / format->nChannels;
        std::memset(&description, 0, sizeof(description));
        description.dwSize = sizeof(description);
        description.dwFlags = 0x80;
        description.dwBufferBytes = sampleSizes[id];
        description.lpwfxFormat = reinterpret_cast<WAVEFORMATEX *>(&pcm);
        result = directSound->CreateSoundBuffer(&description, &buffers[id], 0);
        if (result != DS_OK) MessageBoxA(window, audiocreateError, audiocreateTitle, 0);
    }
}

unsigned short Audio::FindFreeSlot()
{
    unsigned short i;
    for (i = 0; i < 150; ++i) { if (!buffers[i]) break; }
    if (i == 150) MessageBoxA(window, audiofullError, audiofullTitle, 0);
    return i;
}

void Audio::ReleaseSound(unsigned short id)
{
    ReleaseBuffer(id);
    if (samples[id]) { delete[] samples[id]; samples[id] = 0; }
}

unsigned short Audio::LoadWave(const char *path)
{
    WAVEFORMATEX format;
    {
        MMCKINFO chunk;
        {
            MMCKINFO riff;
            riff.ckid = 0;
            riff.cksize = 0;
            riff.fccType = 0;
            riff.dwDataOffset = 0;
            riff.dwFlags = 0;
            chunk = riff;
            HMMIO file = mmioOpenA(const_cast<char *>(path), 0, MMIO_ALLOCBUF);
            if (!file) return 150;
            riff.fccType = mmioFOURCC('W', 'A', 'V', 'E');
            if (mmioDescend(file, &riff, 0, MMIO_FINDRIFF)) {
                mmioClose(file, 0);
                MessageBoxA(window, audioriffError, audioriffTitle, 0);
                return 150;
            }
            chunk.ckid = mmioFOURCC('f', 'm', 't', ' ');
            if (mmioDescend(file, &chunk, &riff, 0)) {
                mmioClose(file, 0);
                MessageBoxA(window, audioformatError, audioformatTitle, 0);
                return 150;
            }
            if (mmioRead(file, reinterpret_cast<char *>(&format), 18) != 18) {
                mmioClose(file, 0);
                MessageBoxA(window, audioreadFormatError, audioreadFormatTitle, 0);
                return 150;
            }
            if (format.wFormatTag != WAVE_FORMAT_PCM) {
                mmioClose(file, 0);
                MessageBoxA(window, audiopcmError, audiopcmTitle, 0);
                return 150;
            }
            if (mmioAscend(file, &chunk, 0)) {
                mmioClose(file, 0);
                MessageBoxA(window, audioascendError, audioascendTitle, 0);
                return 150;
            }
            chunk.ckid = mmioFOURCC('d', 'a', 't', 'a');
            if (mmioDescend(file, &chunk, &riff, MMIO_FINDCHUNK)) {
                mmioClose(file, 0);
                MessageBoxA(window, audiodataError, audiodataTitle, 0);
                return 150;
            }
            {
                unsigned short id = FindFreeSlot();
                samples[id] = new unsigned char[chunk.cksize];
                sampleSizes[id] = chunk.cksize;
                if (!samples[id]) { MessageBoxA(window, audioallocateError, audioallocateTitle, 0); return 150; }
                if (mmioRead(file, reinterpret_cast<char *>(samples[id]), chunk.cksize) != chunk.cksize) {
                    mmioClose(file, 0);
                    MessageBoxA(window, audioreadDataError, audioreadDataTitle, 0);
                    return 150;
                }
                mmioClose(file, 0);
                CreateBuffer(id, &format);
                FillBuffer(id);
                return id;
            }
        }
    }
}

void Audio::ReadLoopMarkers(const char *path)
{
    HANDLE file;
    {
        int cue;
        {
            DWORD size;
            {
                unsigned char *data = new unsigned char[320];
                int annotation;
                DWORD transferred;
                cue = 0;
                annotation = 0;
                file = CreateFileA(path, GENERIC_READ, 0, 0, OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, 0);
                size = GetFileSize(file, 0);
                if (file == INVALID_HANDLE_VALUE || GetFileSize(file, 0) == 0) { loopEnd = 0; loopStart = 0; return; }
                SetFilePointer(file, -320, 0, FILE_END);
                ReadFile(file, data, 320, &transferred, 0);
                CloseHandle(file);
                for (int i = 0; i < 320; ++i) {
                    if (data[i] == 'c' && data[i + 1] == 'u' && data[i + 2] == 'e') {
                        cue = data[i + 16] + (data[i + 17] << 8) + ((data[i + 18] << 8) << 8) + (((data[i + 19] << 8) << 8) << 8);
                    } else if (data[i] == 'a' && data[i + 1] == 'd' && data[i + 2] == 't' && data[i + 3] == 'l') {
                        annotation = data[i + 16] + (data[i + 17] << 8) + ((data[i + 18] << 8) << 8) + (((data[i + 19] << 8) << 8) << 8);
                    }
                }
                if (cue == 0 || annotation == 0) return;
                {
                    loopEnd = (cue + annotation) * 4;
                    loopStart = annotation * 4;
                    delete[] data;
                }
            }
        }
    }
}

void Audio::MaintainLoop(unsigned short id)
{
    DWORD position;
    if (!loopEnd) return;
    if (id == 150) return;
    if (!buffers[id]) return;
    if (!samples[id]) return;
    {
        buffers[id]->GetCurrentPosition(&position, 0);
        if (position > loopEnd) {
            buffers[id]->Stop();
            buffers[id]->SetCurrentPosition(position - loopStart);
            buffers[id]->Play(0, 0, 1);
        }
    }
}
