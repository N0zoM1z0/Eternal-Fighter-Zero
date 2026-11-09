// Original character input/replay branches and visual trail capture.
#include "Engine.h"

void Secondary::UpdateInput()
{
    unsigned char state;
    if (cpuControlled != 0) {
        if (contextOwner->mode1364 == 1) {
            buttonPulse[0] = 0;
            buttonPulse[1] = 0;
            buttonPulse[2] = 0;
            buttonPulse[3] = 0;
            inputX = 0;
            if ((char)contextOwner->flag1346 == 1) inputY = -1;
            else if ((char)contextOwner->flag1346 == 2) inputY = 1;
            else inputY = 0;
            return;
        }
        Slot05();
        if (contextOwner->effectFlag1350 != 0 || contextOwner->counter1354 != 0) {
            buttonPulse[0] = 0;
            buttonPulse[1] = 0;
            buttonPulse[2] = 0;
            buttonPulse[3] = 0;
            field0262 = 99;
        }
    } else {
        state = inputOwner->ReadState(player);
        if (contextOwner->flag14283 == 1) state = contextOwner->replayFile.ReadWord();
        else if (contextOwner->flag14283 == 2) contextOwner->replayFile.WriteWord(state);
        inputX = 0;
        inputY = 0;
        buttonPulse[0] = 0;
        buttonPulse[1] = 0;
        buttonPulse[2] = 0;
        buttonPulse[3] = 0;
        if ((state & 8) > 0) inputY = -1;
        else if ((state & 4) > 0) inputY = 1;
        if (facing > 0) {
            if ((state & 2) > 0) inputX = -1;
            else if ((state & 1) > 0) inputX = 1;
        } else {
            if ((state & 1) > 0) inputX = 1;
            else if ((state & 2) > 0) inputX = -1;
        }
        if ((state & 16) > 0) { buttonPulse[0] = buttonHeld[0] == 0; buttonHeld[0] = 1; }
        else buttonHeld[0] = 0;
        if ((state & 32) > 0) { buttonPulse[1] = buttonHeld[1] == 0; buttonHeld[1] = 1; }
        else buttonHeld[1] = 0;
        if ((state & 64) > 0) { buttonPulse[2] = buttonHeld[2] == 0; buttonHeld[2] = 1; }
        else buttonHeld[2] = 0;
        if ((state & 128) > 0) { buttonPulse[3] = buttonHeld[3] == 0; buttonHeld[3] = 1; }
        else buttonHeld[3] = 0;
        if (contextOwner->effectFlag1350 != 0 || contextOwner->counter1354 != 0) {
            buttonPulse[0] = 0;
            buttonPulse[1] = 0;
            buttonPulse[2] = 0;
            buttonPulse[3] = 0;
            field0262 = 99;
        }
        history[field0260] = (inputX == 1) + (inputX == -1) * 2
        + (inputY == 1) * 4 + (inputY == -1) * 8
        + buttonPulse[0] * 16 + buttonPulse[1] * 32 + buttonPulse[2] * 64 + buttonPulse[3] * 128;
        if (history[field0260] >= 16) {
            if (field0008 >= 200) field01a8 = history[field0260];
            if (field0008 >= 163 && field0008 <= 166) {
                field01a9 = history[field0260];
                field01aa = 15;
            }
        }
        ++field0260;
        if (field0260 >= 180) field0260 = 0;
        if (inputX == 1 - 2 * ((*opponentSlot)->positionX - positionX > 0.0)
        && field014e == 0 && field0150 == 0) field014e = 60;
        if ((*opponentSlot)->hitstopFrames == 0 && field014e > 0) --field014e;
        if (inputX == 0) field0150 = 0;
        else field0150 = 1;
        Slot02();
    }
}

void SecondaryTrail::Capture(const SecondaryPose *pose)
{
    stride = pending;
    held = 0;
    x[position] = pose->positionX;
    y[position] = pose->positionY;
    facing[position] = pose->facing;
    type[position] = pose->field0008;
    frame[position] = pose->field000a;
    ++position;
    if (position >= 60) position = 0;
}

void SecondaryTrail::Begin(const SecondaryPose *pose, unsigned char spacing)
{
    if (pending == 0 && held == 0) {
        for (int i = 0; i < 60; ++i) {
            x[i] = pose->positionX;
            y[i] = pose->positionY;
            facing[i] = pose->facing;
            type[i] = pose->field0008;
            frame[i] = pose->field000a;
        }
    }
    pending = spacing;
    stride = spacing;
}

void Secondary::AdvanceTrail()
{
    if ((*opponentSlot)->hitstunFrames == 0) {
        if (trail.pending > 0) {
            trail.Capture(this);
            trail.held = 0;
        } else if (trail.held > 0) --trail.held;
    }
}

void Secondary::StartTrail(unsigned char spacing)
{
    trail.Begin(this, spacing);
}
