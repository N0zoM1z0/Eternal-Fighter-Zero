// Integer exponentiation used by the Scene9 results digit display.
// Native owners: IntegerPowerAsDouble 0x00775810 and IntegerPower 0x00775830.

int __cdecl IntegerPower(int base, int exponent)
{
    unsigned int remainingExponent;
    int result;

    if (exponent >= 0) remainingExponent = exponent;
    else remainingExponent = -exponent;

    // The first exponent bit uses base as-is; later bits square it first.
    result = 1;
    goto multiplyBit;

squareBase:
    base = base * base;

multiplyBit:
    if ((remainingExponent & 1) != 0) result = result * base;
    remainingExponent = remainingExponent >> 1;
    {
        int finalResult;
        if (remainingExponent == 0) {
            if (exponent < 0) finalResult = 1 / result;
            else finalResult = result;
            return finalResult;
        } else {
            goto continueLoop;
        }
    }

// A nonzero remaining exponent returns through the square step.
continueLoop:
    goto squareBase;
}

double __cdecl IntegerPowerAsDouble(int base, int exponent)
{
    int result = IntegerPower(base, exponent);
    return (double)result;
}
