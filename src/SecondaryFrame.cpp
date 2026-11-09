// Complete shared character state dispatch, movement and timed-state updates.
#include "Engine.h"

void Secondary::DispatchState()
{
    if (hitstopFrames == 0 && (*opponentSlot)->hitstunFrames == 0) {
        if (field0008 < 50 || field0008 > 150 || field0008 == 96) {
            airActionLockFrames = 0;
            knockdownOnLanding = 0;
            (*opponentSlot)->comboHitCount = 0;
            if ((*opponentSlot)->comboDamageScale > 10000.0) (*opponentSlot)->comboDamageScale -= 20.0;
            else (*opponentSlot)->comboDamageScale = 10000.0;
        }
        if (field0008 < 50) {
            Slot03();
            outgoingPushbackVelocityX = 0.0;
            (*opponentSlot)->outgoingPushbackVelocityX = 0.0;
            if (field30ec != 0 && (*opponentSlot)->field0008 < 50) {
                meter = 3000;
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
        if (field0008 >= 50 && field0008 < 150 && airActionGauge <= 0.0f
        && (sequences[field0008].data[field000a].attackFlags & 0x400) == 0) CheckAirAction();
        Slot04();
    }
}

void Secondary::CheckAirAction()
{
    if (airActionLockFrames > 0) --airActionLockFrames;
    else if (positionY < 0.0 && airActionDisabled == 0
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
    if (hitstopFrames == 0 && (*opponentSlot)->hitstunFrames == 0) {
        if ((CollisionSide() * facing) * (velocityX + velocityXCorrection + (*opponentSlot)->outgoingPushbackVelocityX
        * ((*opponentSlot)->outgoingPushbackActive != 0 && hitstunFrames == 0)) >= 0.0) {
            positionX = (velocityX + velocityXCorrection + (*opponentSlot)->outgoingPushbackVelocityX
            * ((*opponentSlot)->outgoingPushbackActive != 0 && hitstunFrames == 0)) * facing + positionX;
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
        if (effectActive[i] != 0 && (hitstunFrames <= 0 || effects[i].field0088 != 0)
        && effects[i].field0086 == 0 && (*opponentSlot)->hitstunFrames == 0) {
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
    if ((*opponentSlot)->hitstunFrames > 0) goto ClampState;
    {
        if (hitstopFrames > 0) --hitstopFrames;
        else hitstopFrames = 0;
        if (IsStateGroupA() == 0) {
            if (IsStateGroupB() != 0) airActionGauge -= float(1.0 / ((positionY == 0.0) * 4 + 1));
            else airActionGauge -= 0.075f;
            if (airActionGauge < 0.0f) airActionGauge = 0.0f;
        }
        if (throwInvulnerabilityFrames > 0) --throwInvulnerabilityFrames;
        else throwInvulnerabilityFrames = 0;
        if ((sequences[field0008].data[field000a].frameFlags & 0x40) > 0) throwInvulnerabilityFrames = 27;
        if (field0138 > 0) --field0138;
        else field0138 = 0;
        if (field013a > 0) --field013a;
        else field013a = 0;
        if (hitInvulnerabilityFrames > 0) --hitInvulnerabilityFrames;
        else hitInvulnerabilityFrames = 0;
        if (field013e > 0) --field013e;
        else field013e = 0;
        if (koDelayFrames > 0) --koDelayFrames;
        else koDelayFrames = 0;
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
    if (meter < 0) meter = 0;
    else if (meter > 3000) meter = 3000;
    if (field0118 < 0.0) field0118 = 0.0;
    else if (field0118 > 1000.0) field0118 = 1000.0;
    --field30f0;
    if (field30f0 <= 0) field30f0 = 12600;
    if (comboDisplayTimer > 0 && comboHitCount == 0) --comboDisplayTimer;
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
