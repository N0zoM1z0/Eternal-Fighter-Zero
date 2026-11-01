#include <windows.h>

unsigned long efz_c_smoke(void)
{
    return sizeof(DWORD) == 4 && sizeof(void *) == 4 ? 71 : 0;
}
