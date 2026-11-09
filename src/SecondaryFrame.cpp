// Complete shared character state dispatch, movement and timed-state updates.
#include "Engine.h"

void Secondary::DispatchState()
{
    if (field014a == 0 && (*opponentSlot)->field014c == 0) {
        if (field0008 < 50 || field0008 > 150 || field0008 == 96) {
            field0124 = 0;
            field012c = 0;
            (*opponentSlot)->field0174 = 0;
            if ((*opponentSlot)->field0178 > 10000.0) (*opponentSlot)->field0178 -= 20.0;
            else (*opponentSlot)->field0178 = 10000.0;
        }
        if (field0008 < 50) {
            Slot03();
            field00b8 = 0.0;
            (*opponentSlot)->field00b8 = 0.0;
            if (field30ec != 0 && (*opponentSlot)->field0008 < 50) {
                field0148 = 3000;
                field0108 = field30ee;
                if (field30ec > 0) {
                    if (field30ec < 1000) {
                        field0118 = field30ec;
                        field0120 = 0;
                    } else {
                        field0118 = 2000 - field30ec;
                        field0120 = 1;
                    }
                }
            }
        }
        if (field0008 >= 50 && field0008 < 150 && field0134 <= 0.0f
        && (sequences[field0008].data[field000a].field00aa & 0x400) == 0) CheckAirAction();
        Slot04();
    }
}

void Secondary::CheckAirAction()
{
    if (field0124 > 0) --field0124;
    else if (positionY < 0.0 && field0128 == 0
    && (buttonPulse[0] != 0 || buttonPulse[1] != 0 || buttonPulse[2] != 0 || buttonPulse[3] != 0)) {
        if (inputX == facing) {
            if (field0008 != 157) ResetPose();
            field0008 = 157;
        } else if (inputX == -facing) {
            if (field0008 != 158) ResetPose();
            field0008 = 158;
        }
    }
}

void Secondary::UpdateMovement()
{
    int i = effectRead;
    if (field014a == 0 && (*opponentSlot)->field014c == 0) {
        if ((CollisionSide() * facing) * (velocityX + velocityXCorrection + (*opponentSlot)->field00b8
        * ((*opponentSlot)->field00d0 != 0 && field014c == 0)) >= 0.0) {
            positionX = (velocityX + velocityXCorrection + (*opponentSlot)->field00b8
            * ((*opponentSlot)->field00d0 != 0 && field014c == 0)) * facing + positionX;
        }
        if (positionX < 20 + ((*opponentSlot)->CollisionSide() == 1 && (*opponentSlot)->positionX <= 20.0)) {
            positionX = 20 + ((*opponentSlot)->CollisionSide() == 1 && (*opponentSlot)->positionX <= 20.0);
        } else {
            if (positionX > 619 - ((*opponentSlot)->CollisionSide() == -1 && (*opponentSlot)->positionX >= 619.0)) {
                positionX = 619 - ((*opponentSlot)->CollisionSide() == -1 && (*opponentSlot)->positionX >= 619.0);
            }
        }
        positionY = positionY + velocityY;
        if (positionY > 0.0) positionY = 0.0;
    }
    while (i != effectWrite) {
        if (effectActive[i] != 0 && (field014c <= 0 || effects[i].field0088 != 0)
        && effects[i].field0086 == 0 && (*opponentSlot)->field014c == 0) {
            effects[i].x += (effects[i].vx + 0.0 * effects[i].field0070) * effects[i].flag0048;
            effects[i].y = effects[i].y + effects[i].vy;
        }
        ++i;
        if (i >= 64) i = 0;
    }
}

void Secondary::UpdateTimers()
{
    int i;
    if ((*opponentSlot)->field014c > 0) goto ClampState;
    {
        if (field014a > 0) --field014a;
        else field014a = 0;
        if (IsStateGroupA() == 0) {
            if (IsStateGroupB() != 0) field0134 -= float(1.0 / ((positionY == 0.0) * 4 + 1));
            else field0134 -= 0.075f;
            if (field0134 < 0.0f) field0134 = 0.0f;
        }
        if (field0130 > 0) --field0130;
        else field0130 = 0;
        if ((sequences[field0008].data[field000a].field00b0 & 0x40) > 0) field0130 = 27;
        if (field0138 > 0) --field0138;
        else field0138 = 0;
        if (field013a > 0) --field013a;
        else field013a = 0;
        if (field013c > 0) --field013c;
        else field013c = 0;
        if (field013e > 0) --field013e;
        else field013e = 0;
        if (field0140 > 0) --field0140;
        else field0140 = 0;
        field0118 = double((IsStateGroupA() + 1) * (IsStateGroupB() == 0 && field0120 == 0)
        * ((field0118 < 500.0) * 2 + 1)) / 10.0 + field0118;
        if (field0118 >= 1000.0 && field0120 == 0) {
            field0120 = 1;
            field0118 = 1000.0;
        } else if (field0118 <= 0.0) {
            field0120 = 0;
            field0118 = 0.0;
        }
        i = effectRead;
        while (i != effectWrite) {
            if (effectActive[i] != 0) {
                if (effects[i].field0086 > 0) --effects[i].field0086;
                else effects[i].field0086 = 0;
            }
            ++i;
            if (i >= 64) i = 0;
        }
        if ((*opponentSlot)->IsStateGroupB() != 0) {
            field30e4 = 900;
            field30e0 = 12;
        }
        if (((*opponentSlot)->field0008 < 50 || (*opponentSlot)->field0008 >= 200)
        && contextOwner->effectFlag1350 == 0 && contextOwner->counter1354 == 0) {
            if (field30e4 > 0) --field30e4;
            else {
                if (field30e0 > 1) --field30e0;
                if (field30d0 > 0) --field30d0;
                field30e4 = field30e0 * 5 * 3;
            }
        }
    }
    ClampState:
    if (field0148 < 0) field0148 = 0;
    else if (field0148 > 3000) field0148 = 3000;
    if (field0118 < 0.0) field0118 = 0.0;
    else if (field0118 > 1000.0) field0118 = 1000.0;
    --field30f0;
    if (field30f0 <= 0) field30f0 = 12600;
    if (field0104 > 0 && field0174 == 0) --field0104;
}

char Secondary::CollisionSide()
{
    if (positionX - 20.0 <= ((*opponentSlot)->positionX <= 20.0)
    || (*opponentSlot)->positionX - positionX > 280.0) return 1;
    if (positionX + 20.0 >= 639 - ((*opponentSlot)->positionX >= 619.0)
    || positionX - (*opponentSlot)->positionX > 280.0) return -1;
    return 0;
}

int Secondary::IsStateGroupA()
{
    return ((field0008 < 150 || field0008 > 156) && (field0008 < 168 || field0008 > 171)) ? 0 : 1;
}

int Secondary::IsStateGroupB()
{
    return (field0008 >= 50 && field0008 < 150 && (*opponentSlot)->field0008 != 97
    && (*opponentSlot)->field0008 != 98 && (*opponentSlot)->field0008 != 99
    && (*opponentSlot)->field0008 != 96) ? 1 : 0;
}

void Secondary::ClearBufferedButtons() { field01a8 = 0; field01a9 = 0; }
void Secondary::ClearInputHistory()
{
    for (int i = 0; i < 180; ++i) history[i] = 0;
    field0262 = 99;
}
