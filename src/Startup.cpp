// Startup ownership recovered from the complete original entry and window callback.
// Names and opaque storage layouts are provisional; no linked product is claimed.
#include <windows.h>
#include <mmsystem.h>
#include <cstring>
#include <cstdlib>
#include <ctime>

#include "Engine.h"

extern Video video;
extern Input input;
extern Audio audio;
extern Context *context;
extern Secondary *secondaryA, *secondaryB;
extern Scene *scenes[9];
extern unsigned char sceneIndex;
extern int ready;
extern WPARAM active;
extern HANDLE frameEvent, tickEvent, threadHandle;
extern DWORD threadId, lastTick;
extern const char classNameFirst[], classNameSecond[], windowClass[], windowTitle[];
extern "C" unsigned char __cdecl ReadConfigByte(unsigned char);
extern "C" DWORD WINAPI FrameThread(void *);
extern "C" LRESULT CALLBACK WindowProcedure(HWND, UINT, WPARAM, LPARAM);

extern "C" int WINAPI GameMain(HINSTANCE instance, HINSTANCE previous, LPSTR commandLine, int show)
{
    MSG msg;
    WNDCLASSA wc;
    std::memset(&wc, 0, sizeof(wc));
    wc.hInstance = instance;
    wc.lpszClassName = classNameFirst;
    wc.lpfnWndProc = WindowProcedure;
    wc.style = 0;
    wc.hIcon = LoadIconA(0, IDI_APPLICATION);
    wc.hCursor = LoadCursorA(0, IDC_ARROW);
    wc.lpszMenuName = 0;
    wc.cbClsExtra = 0;
    wc.cbWndExtra = 0;
    wc.hbrBackground = (HBRUSH)GetStockObject(BLACK_BRUSH);
    wc.lpszClassName = classNameSecond;
    if (!RegisterClassA(&wc)) return 0;
    {
        HWND hWnd = CreateWindowExA(0, windowClass, windowTitle, WS_POPUP, 0, 0,
                                      GetSystemMetrics(SM_CXSCREEN), GetSystemMetrics(SM_CYSCREEN),
                                      0, 0, instance, 0);
        if (!hWnd) return 0;
        ShowWindow(hWnd, show);
        UpdateWindow(hWnd);
        std::srand((unsigned)std::time(0));
        timeBeginPeriod(1);
        lastTick = timeGetTime();
        tickEvent = CreateEventA(0, FALSE, FALSE, 0);
        frameEvent = CreateEventA(0, FALSE, FALSE, 0);
        SetEvent(tickEvent);
        SetEvent(frameEvent);
        threadHandle = CreateThread(0, 0, FrameThread, 0, 0, &threadId);
        SetThreadPriority(threadHandle, THREAD_PRIORITY_TIME_CRITICAL);
        ShowCursor(FALSE);
        video.Initialize(hWnd, ReadConfigByte(0x20));
        input.Initialize(hWnd);
        audio.Initialize(hWnd);
        if (ReadConfigByte(0x9c) > 0) input.Configure(ReadConfigByte(0x9c));
        else input.Defaults();
        context = new Context(&video, &input, &audio);
        context->Initialize();
        context->Load();
        context->Activate();
        secondaryA = 0;
        secondaryB = 0;
        scenes[0] = new Scene0(hWnd, &secondaryA, &secondaryB, context, &video, &input, &audio);
        scenes[1] = new Scene1(hWnd, &secondaryA, &secondaryB, context, &video, &input, &audio);
        scenes[2] = new Scene2(hWnd, &secondaryA, &secondaryB, context, &video, &input, &audio);
        scenes[3] = new Scene3(hWnd, &secondaryA, &secondaryB, context, &video, &input, &audio);
        scenes[4] = 0;
        scenes[5] = new Scene5(hWnd, &secondaryA, &secondaryB, context, &video, &input, &audio);
        if (true) {
            scenes[6] = new Scene6(hWnd, &secondaryA, &secondaryB, context, &video, &input, &audio);
            scenes[7] = new Scene7(hWnd, &secondaryA, &secondaryB, context, &video, &input, &audio);
            scenes[8] = new Scene8(hWnd, &secondaryA, &secondaryB, context, &video, &input, &audio);
        } else {
            scenes[6] = 0;
            scenes[7] = 0;
            scenes[8] = 0;
        }
        ready = 1;
        while (true) {
            if (PeekMessageA(&msg, 0, 0, 0, PM_NOREMOVE)) {
                if (!GetMessageA(&msg, 0, 0, 0)) break;
                TranslateMessage(&msg);
                DispatchMessageA(&msg);
            } else {
                context->framePhase = !context->framePhase;
                if (scenes[sceneIndex]) {
                    audio.MaintainLoop(context->audioMode);
                    sceneIndex = scenes[sceneIndex]->Step();
                }
                WaitForSingleObject(frameEvent, INFINITE);
            }
        }
        return msg.wParam;
    }
}

extern "C" LRESULT CALLBACK WindowProcedure(HWND window, UINT message, WPARAM wparam, LPARAM lparam)
{
    if (ready && scenes[sceneIndex]) scenes[sceneIndex]->message = message;
    switch (message) {
    case WM_ACTIVATEAPP:
        active = wparam;
        break;
    case WM_DESTROY:
        ready = 0;
        for (int i = 0; i < 9; ++i) {
            if (scenes[i]) {
                delete scenes[i];
                scenes[i] = 0;
            }
        }
        delete context;
        context = 0;
        if (secondaryA) delete secondaryA;
        if (secondaryB) delete secondaryB;
        audio.Shutdown();
        input.Shutdown();
        video.Shutdown();
        TerminateThread(threadHandle, 0);
        CloseHandle(frameEvent);
        CloseHandle(tickEvent);
        CloseHandle(threadHandle);
        timeEndPeriod(1);
        PostQuitMessage(1000);
        break;
    default:
        return DefWindowProcA(window, message, wparam, lparam);
    }
    return 0;
}
