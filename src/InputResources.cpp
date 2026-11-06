// Original DirectInput device setup, state translation and binding file reads.
#include "Input.h"
extern Input *enumeratingInput;
extern unsigned char enumeratedJoysticks;
extern const char inputErrorTitle[], inputErrorMessage[], inputDefaultPath[], inputProfilePath[];

Input::Input()
{
    bindings[0][0] = 0x24;
    bindings[0][1] = 0x22;
    bindings[0][2] = 0x31;
    bindings[0][3] = 0x15;
    bindings[0][4] = 0x10;
    bindings[0][5] = 0x11;
    bindings[0][6] = 0x12;
    bindings[0][7] = 0x20;
    bindings[1][3] = 0xc8;
    bindings[1][2] = 0xd0;
    bindings[1][1] = 0xcb;
    bindings[1][0] = 0xcd;
    bindings[1][4] = 0x19;
    bindings[1][5] = 0x91;
    bindings[1][6] = 0x1a;
    bindings[1][7] = 0x1b;
    directInput = 0;
    keyboard = 0;
    joysticks[0] = 0;
    joysticks[1] = 0;
}

int Input::Initialize(HWND handle)
{
    HRESULT result;
    window = handle;
    result = DirectInputCreateEx(reinterpret_cast<HINSTANCE>(GetWindowLongA(window, GWL_HINSTANCE)), 0x700, IID_IDirectInput7A, reinterpret_cast<void **>(&directInput), 0);
    if (result < 0) return 0;
    directInput->CreateDeviceEx(GUID_SysKeyboard, IID_IDirectInputDevice7A, reinterpret_cast<void **>(&keyboard), 0);
    if (result < 0) { ReportFailure(); return 0; }
    result = keyboard->SetDataFormat(&c_dfDIKeyboard);
    if (result < 0) { ReportFailure(); return 0; }
    result = keyboard->SetCooperativeLevel(window, 0x15);
    if (result < 0) { ReportFailure(); return 0; }
    result = keyboard->Acquire();
    if (result < 0) { ReportFailure(); return 0; }
    enumeratingInput = this;
    result = directInput->EnumDevices(4, EnumerateInputDevice, directInput, 1);
    if (result < 0) { ReportFailure(); return 0; }
    return 1;
}

void Input::Shutdown()
{
    if (directInput) {
        if (keyboard) { keyboard->Unacquire(); keyboard->Release(); keyboard = 0; }
        for (int i = 0; i < 2; ++i) {
            if (joysticks[i]) { joysticks[i]->Unacquire(); joysticks[i]->Release(); joysticks[i] = 0; }
        }
        directInput->Release();
        directInput = 0;
    }
}

Input::~Input()
{
    if (directInput) {
        if (keyboard) { keyboard->Unacquire(); keyboard->Release(); keyboard = 0; }
        for (int i = 0; i < 2; ++i) {
            if (joysticks[i]) { joysticks[i]->Unacquire(); joysticks[i]->Release(); joysticks[i] = 0; }
        }
        directInput->Release();
        directInput = 0;
    }
}

void Input::ReportFailure()
{
    MessageBoxA(0, inputErrorMessage, inputErrorTitle, 0);
    PostMessageA(window, WM_CLOSE, 0, 0);
}

extern "C" BOOL CALLBACK EnumerateInputDevice(const DIDEVICEINSTANCEA *instance, void *)
{
    DIPROPRANGE range;
    HRESULT result;
    result = enumeratingInput->directInput->CreateDeviceEx(instance->guidInstance, IID_IDirectInputDevice7A, reinterpret_cast<void **>(&enumeratingInput->joysticks[enumeratedJoysticks]), 0);
    if (result < 0) return 1;
    result = enumeratingInput->joysticks[enumeratedJoysticks]->SetDataFormat(&c_dfDIJoystick);
    if (result < 0) return 1;
    result = enumeratingInput->joysticks[enumeratedJoysticks]->SetCooperativeLevel(enumeratingInput->window, 0x16);
    if (result < 0) return 1;
    range.diph.dwSize = sizeof(range);
    range.diph.dwHeaderSize = sizeof(range.diph);
    range.diph.dwObj = 0;
    range.diph.dwHow = DIPH_BYOFFSET;
    range.lMin = -1000;
    range.lMax = 1000;
    result = enumeratingInput->joysticks[enumeratedJoysticks]->SetProperty(DIPROP_RANGE, &range.diph);
    if (result < 0) return 1;
    range.diph.dwObj = 4;
    result = enumeratingInput->joysticks[enumeratedJoysticks]->SetProperty(DIPROP_RANGE, &range.diph);
    if (result < 0) return 1;
    result = enumeratingInput->joysticks[enumeratedJoysticks]->Acquire();
    if (result < 0) return 1;
    ++enumeratedJoysticks;
    if (enumeratedJoysticks < 2) return 1;
    return 0;
}

unsigned char Input::ReadState(unsigned char player)
{
    int i;
    {
        short *binding;
        unsigned char key;
        {
            unsigned short device;
            HRESULT result;
            unsigned char state;
            if (player > 1) return 0;
            state = 0;
            binding = bindings[player];
            if (keyboard) {
                result = keyboard->GetDeviceState(256, keys);
                if (result < 0) { if (result == DIERR_INPUTLOST) keyboard->Acquire(); }
            }
            if (joysticks[0]) {
                result = joysticks[0]->Poll();
                if (result >= 0) {
                    result = joysticks[0]->GetDeviceState(80, &joystickState[0]);
                    if (result < 0) { if (result == DIERR_INPUTLOST) joysticks[0]->Acquire(); }
                }
            }
            if (joysticks[1]) {
                result = joysticks[1]->Poll();
                if (result >= 0) {
                    result = joysticks[1]->GetDeviceState(80, &joystickState[1]);
                    if (result < 0) { if (result == DIERR_INPUTLOST) joysticks[1]->Acquire(); }
                }
            }
            for (i = 0; i < 8; ++i) {
                key = *binding & 0xff;
                device = *binding & 0xf00;
                switch (device) {
                    case 0:
                    if (keyboard) { if (keys[key] & 0x80) state |= 1 << i; }
                    break;
                    case 0x100:
                    if (joysticks[0]) {
                        if (joystickState[0].lX < -500 && key == 0x12) { state |= 1 << i; break; }
                        if (joystickState[0].lX > 500 && key == 0x13) { state |= 1 << i; break; }
                        if (joystickState[0].lY < -500 && key == 0x10) { state |= 1 << i; break; }
                        if (joystickState[0].lY > 500 && key == 0x11) { state |= 1 << i; break; }
                        if ((joystickState[0].rgbButtons[key] & 0x80) && key < 0x10) { state |= 1 << i; break; }
                    }
                    break;
                    case 0x200:
                    if (joysticks[1]) {
                        if (joystickState[1].lX < -500 && key == 0x12) { state |= 1 << i; break; }
                        if (joystickState[1].lX > 500 && key == 0x13) { state |= 1 << i; break; }
                        if (joystickState[1].lY < -500 && key == 0x10) { state |= 1 << i; break; }
                        if (joystickState[1].lY > 500 && key == 0x11) { state |= 1 << i; break; }
                        if ((joystickState[1].rgbButtons[key] & 0x80) && key < 0x10) { state |= 1 << i; break; }
                    }
                    break;
                }
                ++binding;
            }
            return state;
        }
    }
}

void Input::Defaults()
{
    HANDLE file = 0;
    file = CreateFileA(inputDefaultPath, GENERIC_READ | GENERIC_WRITE, 0, 0, OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, 0);
    if (file != INVALID_HANDLE_VALUE && GetFileSize(file, 0) >= 32) {
        DWORD size = GetFileSize(file, 0);
        {
            unsigned char *data = new unsigned char[size];
            DWORD transferred;
            ReadFile(file, data, size, &transferred, 0);
            for (int i = 0; i < 2; ++i) {
                bindings[i][3] = data[i * 16 + 1] + (data[i * 16] << 8) - (data[i * 16] > 0);
                bindings[i][2] = data[i * 16 + 3] + (data[i * 16 + 2] << 8) - (data[i * 16 + 2] > 0);
                bindings[i][1] = data[i * 16 + 5] + (data[i * 16 + 4] << 8) - (data[i * 16 + 4] > 0);
                bindings[i][0] = data[i * 16 + 7] + (data[i * 16 + 6] << 8) - (data[i * 16 + 6] > 0);
                bindings[i][4] = data[i * 16 + 9] + (data[i * 16 + 8] << 8) - (data[i * 16 + 8] > 0);
                bindings[i][5] = data[i * 16 + 11] + (data[i * 16 + 10] << 8) - (data[i * 16 + 10] > 0);
                bindings[i][6] = data[i * 16 + 13] + (data[i * 16 + 12] << 8) - (data[i * 16 + 12] > 0);
                bindings[i][7] = data[i * 16 + 15] + (data[i * 16 + 14] << 8) - (data[i * 16 + 14] > 0);
            }
            delete[] data;
        }
    }
    CloseHandle(file);
}

void Input::Configure(unsigned int profile)
{
    HANDLE file = 0;
    file = CreateFileA(inputProfilePath, GENERIC_READ | GENERIC_WRITE, 0, 0, OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, 0);
    if (file != INVALID_HANDLE_VALUE && GetFileSize(file, 0) >= 32) {
        DWORD size = GetFileSize(file, 0);
        {
            unsigned char *data = new unsigned char[size];
            DWORD transferred;
            ReadFile(file, data, size, &transferred, 0);
            for (int i = 0; i < 2; ++i) {
                bindings[i][3] = data[profile * 39 + i * 16 + 1] + (data[profile * 39 + i * 16] << 8) - (data[profile * 39 + i * 16] > 0);
                bindings[i][2] = data[profile * 39 + i * 16 + 3] + (data[profile * 39 + i * 16 + 2] << 8) - (data[profile * 39 + i * 16 + 2] > 0);
                bindings[i][1] = data[profile * 39 + i * 16 + 5] + (data[profile * 39 + i * 16 + 4] << 8) - (data[profile * 39 + i * 16 + 4] > 0);
                bindings[i][0] = data[profile * 39 + i * 16 + 7] + (data[profile * 39 + i * 16 + 6] << 8) - (data[profile * 39 + i * 16 + 6] > 0);
                bindings[i][4] = data[profile * 39 + i * 16 + 9] + (data[profile * 39 + i * 16 + 8] << 8) - (data[profile * 39 + i * 16 + 8] > 0);
                bindings[i][5] = data[profile * 39 + i * 16 + 11] + (data[profile * 39 + i * 16 + 10] << 8) - (data[profile * 39 + i * 16 + 10] > 0);
                bindings[i][6] = data[profile * 39 + i * 16 + 13] + (data[profile * 39 + i * 16 + 12] << 8) - (data[profile * 39 + i * 16 + 12] > 0);
                bindings[i][7] = data[profile * 39 + i * 16 + 15] + (data[profile * 39 + i * 16 + 14] << 8) - (data[profile * 39 + i * 16 + 14] > 0);
            }
            delete[] data;
        }
    }
    CloseHandle(file);
}
