// Nagamori Slot02 input command recognizer, original large owner 0x4B1780.
// Partial natural C++: high-priority command 0x5B scan only, NOT whole Exact.
#include "../../src/CharacterViews.h"

void Character06::Slot02()
{
    int i;
    unsigned char buttons, stage;
    recognizedCommand = 99;

    stage = 0;
    i = inputHistoryWriteIndex + 0x2d;
    for (; i < inputHistoryWriteIndex + 0xb4; ++i) {
        buttons = history[i - (i >= 180) * 180];
        if (((buttons & 0xe0) != 0) && stage == 5) {
            break;
        }
        if (((buttons & 0x10) != 0) && stage == 5) {
            recognizedCommand = 0x5b;
            return;
        }
        if (buttons == 0 && stage == 4) {
            stage = 5;
        }
        if ((buttons & 0xf) == 2 + (facing == -1 ? 0 : -1) && stage == 3) {
            stage = 4;
        }
        if (((buttons & 0xe0) != 0) && stage == 2) {
            break;
        }
        if (((buttons & 0x10) != 0) && stage == 2) {
            stage = 3;
        }
        if (((buttons & 0xd0) != 0) && stage == 1) {
            break;
        }
        if (((buttons & 0x20) != 0) && stage == 1) {
            stage = 2;
        }
        if ((buttons & 0xf) == 2 + (facing == -1 ? 0 : -1) &&
            stage == 0 && meter == 3000 && positionY == 0.0) {
            stage = 1;
        }
    }
    // Further original priority scans are not implemented.
}
