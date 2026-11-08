// Original timer worker and its byte-sized adaptive wait interval.
#include <windows.h>
#include <mmsystem.h>

extern DWORD lastTick;
extern HANDLE tickEvent;
extern HANDLE frameEvent;

// The original .data byte is initialized to 10 and is adjusted by FrameThread.
unsigned char tickTimeout = 10;

extern "C" DWORD WINAPI FrameThread(void *parameter)
{
    int frameCount = 0;
    {
        // Both initialized stack slots are present in the original body but are
        // not subsequently read. Their original source-level names are unknown.
        int unusedCountA = 0;
        int unusedCountB = 0;
        lastTick = timeGetTime();
        while (true) {
            WaitForSingleObject(tickEvent, tickTimeout);
            SetEvent(frameEvent);
            ++frameCount;
            if (timeGetTime() - lastTick >= 1000) {
                if (frameCount > 64) ++tickTimeout;
                frameCount = 0;
                lastTick = timeGetTime();
            }
        }
    }
    return 0;
}
