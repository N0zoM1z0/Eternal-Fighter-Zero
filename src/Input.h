// Provisional DirectInput 7 state and ownership recovered from target accesses.
#ifndef EFZ_INPUT_H
#define EFZ_INPUT_H
#include <windows.h>
#define DIRECTINPUT_VERSION 0x0700
#include <dinput.h>
extern "C" BOOL CALLBACK EnumerateInputDevice(const DIDEVICEINSTANCEA *, void *);
class Input {
    char keys[256];
    unsigned char unknown_0100[32];
    DIJOYSTATE joystickState[2];
    short bindings[2][8];
    HWND window;
    IDirectInput7A *directInput;
    IDirectInputDevice7A *keyboard;
    IDirectInputDevice7A *joysticks[2];
    friend class Scene0;
    friend BOOL CALLBACK EnumerateInputDevice(const DIDEVICEINSTANCEA *, void *);
public:
    Input();
    ~Input();
    int Initialize(HWND);
    void Configure(unsigned int);
    void Defaults();
    void Shutdown();
    void ReportFailure();
    unsigned char ReadState(unsigned char);
};
#endif
