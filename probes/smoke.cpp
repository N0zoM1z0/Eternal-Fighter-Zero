#include <cstdio>
#include <windows.h>

extern "C" unsigned long efz_c_smoke(void);

int main()
{
    HRSRC resource = FindResourceA(GetModuleHandleA(0), "SMOKE", RT_RCDATA);
    if (efz_c_smoke() != 71 || !resource)
        return 1;
    std::puts("EFZ compiler smoke OK");
    return 0;
}
