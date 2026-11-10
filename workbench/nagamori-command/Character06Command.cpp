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
    // Second priority: 100..179 ticks, a four-stage direction/button
    // motion. Finish either from state 4 or simultaneously with state 3.
    stage = 0;
    i = inputHistoryWriteIndex + 100;
    for (; i < inputHistoryWriteIndex + 0xb4; ++i) {
        buttons = history[i - (i >= 180) * 180];
        if (((buttons & 0xf0) != 0) && stage == 4) {
            recognizedCommand = ((buttons & 0xe0) > 0) + 0x78 +
                                ((buttons & 0xc0) > 0) + ((buttons & 0x80) > 0);
            return;
        }
        if (((buttons & 0xf) == 6 + (facing == -1 ? 0 : -1)) && stage == 3) {
            if ((buttons & 0xf0) != 0) {
                recognizedCommand = ((buttons & 0xe0) > 0) + 0x78 +
                                    ((buttons & 0xc0) > 0) + ((buttons & 0x80) > 0);
                return;
            }
            stage = 4;
        }
        if (((buttons & 0xf) == 6 - (facing == -1 ? 1 : 0)) && stage == 2) {
            stage = 3;
        }
        if (((buttons & 0xf) == 2 - (facing == -1 ? 1 : 0)) && stage == 1) {
            stage = 2;
        }
        if (((buttons & 0xf) == 2 + (facing == -1 ? 0 : -1)) && stage == 0) {
            stage = 1;
        }
    }
    // Nagamori third priority scan: 90-frame motion, meter >= 1000 required.
    stage = 0;
    i = inputHistoryWriteIndex + 0x5a;
    for (; i < inputHistoryWriteIndex + 0xb4; ++i) {
        buttons = history[i - (i >= 180) * 180];
        if (((buttons & 0xf0) != 0) && (stage == 6)) {
            recognizedCommand = ((buttons & 0xe0) > 0) + 0x6e +
                                ((buttons & 0xc0) > 0) + ((buttons & 0x80) > 0);
            return;
        }
        if (((buttons & 0xf) == 2 - (facing == -1)) && (stage == 5)) {
            if ((buttons & 0xf0) != 0) {
                recognizedCommand = ((buttons & 0xe0) > 0) + 0x6e +
                                    ((buttons & 0xc0) > 0) + ((buttons & 0x80) > 0);
                return;
            }
            stage = 6;
        }
        if (((buttons & 0xf) == 6 - (facing == -1)) && (stage == 4)) {
            stage = 5;
        }
        if (((buttons & 0xf) == 4) && (stage == 3)) {
            stage = 4;
        }
        if (((buttons & 0xf) == 2 - (facing == -1)) && (stage == 2)) {
            stage = 3;
        }
        if (((buttons & 0xf) == 6 - (facing == -1)) && (stage == 1)) {
            stage = 2;
        }
        if (((buttons & 0xf) == 4) && (stage == 0) && (meter >= 1000)) {
            stage = 1;
        }
    }
    // Fourth Nagamori scan: 1000-meter grounded base-100 motion.
    stage = '\0';
    i = inputHistoryWriteIndex + 0x5a;
    for (; i < inputHistoryWriteIndex + 0xb4; ++i) {
        buttons = history[i - (i >= 180) * 180];
        if (((buttons & 0xf0) != 0) && (stage == '\x06')) {
            recognizedCommand = ((buttons & 0xe0) > 0) + 100 + ((buttons & 0xc0) > 0) + ((buttons & 0x80) > 0);
            return;
        }
        if (((buttons & 0xf) == 2 + (facing == -1 ? 0 : -1)) && (stage == '\x05')) {
            if ((buttons & 0xf0) != 0) {
                recognizedCommand = ((buttons & 0xe0) > 0) + 100 + ((buttons & 0xc0) > 0) + ((buttons & 0x80) > 0);
                return;
            }
            stage = '\x06';
        }
        if (((buttons & 0xf) == (facing == -1 ? 6 : 5)) && (stage == '\x04')) {
            stage = '\x05';
        }
        if (((buttons & 0xf) == 4) && (stage == '\x03')) {
            stage = '\x04';
        }
        if (((buttons & 0xf) == 2 + (facing == -1 ? 0 : -1)) && (stage == '\x02')) {
            stage = '\x03';
        }
        if (((buttons & 0xf) == (facing == -1 ? 6 : 5)) && (stage == '\x01')) {
            stage = '\x02';
        }
        if ((((buttons & 0xf) == 4) && (stage == '\0')) && (meter >= 1000) && (positionY == 0.0)) {
            stage = '\x01';
        }
    }
    // Lower-priority Nagamori scans remain unimplemented.
}
