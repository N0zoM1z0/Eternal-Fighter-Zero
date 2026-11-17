// VC7.1 standard-library floating-point load adapters.
// Canonical native functions 0x00405450 (wrapper) and 0x00405470 (core).
// The runtime load helper at 0x00778204 uses 0x00779AC5 for x87 loading;
// it is a separate native CRT owner and not reconstructed by this file.
extern "C" double __cdecl RuntimeLoadDouble(double value);
extern "C" float __cdecl FloatLoadCore(float value);

extern "C" float __cdecl FloatLoad(float value)
{
    return FloatLoadCore(value);
}

extern "C" float __cdecl FloatLoadCore(float value)
{
    return (float)RuntimeLoadDouble((double)value);
}
