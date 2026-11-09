// Complete guard, damage/combo factors, score carry and replay-aware random range.
#include "Engine.h"
#include <cstdlib>

int Secondary::CanGuard(const SecondaryFrame *attack, const SecondaryFrame *defense)
{
    if (field013a > 0) return 0;
    if ((attack->field00aa & 0x80) > 0) return 0;
    if ((defense->field00b0 & 0x10) == 0) return 0;
    if ((attack->field00aa & 4) == 0 && positionY < 0.0 && field014e < 30) return 0;
    if (GuardInput(attack) == 0) return 0;
    return 1;
}

int Secondary::GuardInput(const SecondaryFrame *attack)
{
    if (cpuControlled != 0) {
        if (contextOwner->mode1364 == 1) {
            if (contextOwner->counter1348 == 0) return 0;
        } else {
            if (float(std::rand()) > field00a8 * 10000.0f) return 0;
            if ((attack->field00aa & 1) == 0) inputY = 1;
            else if ((attack->field00aa & 2) == 0) inputY = 0;
        }
        if (((attack->field00aa & 2) == 0 && inputY == 1 && positionY == 0.0)
        || ((attack->field00aa & 1) == 0 && inputY != 1 && positionY == 0.0)) return 0;
    } else {
        if (inputX != 1 - 2 * ((*opponentSlot)->positionX - positionX > 0.0)
        && (IsStateGroupA() == 0 || inputX == 0)) return 0;
        if (((attack->field00aa & 2) == 0 && inputY == 1 && positionY == 0.0)
        || ((attack->field00aa & 1) == 0 && inputY != 1 && positionY == 0.0)) return 0;
    }
    return 1;
}

int Secondary::AirActionReady()
{
    return (field0124 <= 0 && positionY < 0.0 && field0128 == 0 && IsStateGroupB() != 0) ? 1 : 0;
}

int Secondary::IsStateGroupC()
{
    return (field0008 == 163 || field0008 == 164 || field0008 == 165 || field0008 == 166) ? 1 : 0;
}

double Secondary::DamageFactor()
{
    if (contextOwner->mode1364 == 2) return field0118 / 10000.0 + 1.0;
    else if ((char)contextOwner->setting1370 == 1) return (field0118 / 10000.0 + 1.0) / 2.0;
    else if ((char)contextOwner->setting1370 == 2) return field0118 / 10000.0 + 1.0;
    else return (field0118 / 10000.0 + 1.0) * 2.0;
}

double Secondary::HealthFactor()
{
    return (field0108 * 0.5 / 10000.0 + 0.5) * field0180;
}

double Secondary::ComboFactor()
{
    if (field0178 / 10000.0 > 1.0) return 1.0;
    return field0178 / 10000.0;
}

void Secondary::ApplyDamage(int damage, double scaling)
{
    if (field0174 == 0) (*opponentSlot)->field010c = (*opponentSlot)->field0108;
    (*opponentSlot)->field0108 -= int(damage * DamageFactor() * (*opponentSlot)->HealthFactor() * ComboFactor());
    field00f8 = field0178 / 100.0;
    field0178 = (scaling / 1000.0) * field0178;
    if (field0178 > 10000.0) field0178 = (scaling / 1000.0) * field0178;
    ++field0174;
    field00f4 = field0174;
    field0104 = 180;
    field0100 = (*opponentSlot)->field010c - (*opponentSlot)->field0108;
    if (field0174 > field30d4) field30d4 = field0174;
    if (field0100 > field30d8) field30d8 = field0100;
    ++field30d0;
    AddScore((damage / 100) * field30d0 * field30d4 * field0174);
}

void Secondary::AwardComboScore(const SecondaryFrame *attack)
{
    if (field0174 > field30d4) field30d4 = field0174;
    if (field0100 > field30d8) field30d8 = field0100;
    ++field30d0;
    AddScore((attack->field00a0 / 100) * field30d0 * field30d4 * field0174);
}

void Secondary::AddScore(unsigned int amount)
{
    field30c8 += amount;
    while (field30c8 >= 100000000) {
        field30c8 -= 100000000;
        ++field30cc;
    }
}

short Secondary::RandomRange(short low, short high)
{
    short result;
    {
        unsigned short value = std::rand();
        if (contextOwner->flag14283 == 1) value = contextOwner->replayFile.ReadWord();
        else if (contextOwner->flag14283 == 2) contextOwner->replayFile.WriteWord(value);
        result = low + (high - low) * value / 32768;
    }
    return result;
}
