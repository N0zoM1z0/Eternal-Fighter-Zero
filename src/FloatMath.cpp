// Reconstructed VC7.1 standard-library float absolute-value adapters.
// Canonical addresses 0x00405410 and 0x00405430; both float-returning cdecl.
// Their reviewed origin is standard-library, not game-authored code.
#include <math.h>

extern "C" float __cdecl FloatAbsoluteCore(float value);

extern "C" float __cdecl FloatAbsolute(float value)
{
    return FloatAbsoluteCore(value);
}

extern "C" float __cdecl FloatAbsoluteCore(float value)
{
    return (float)fabs((double)value);
}
