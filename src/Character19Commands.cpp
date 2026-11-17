// Kanna's ordered command recognition over the circular input history.
// Native virtual owner: Character19::Slot02, 0x00677E60.
// The scan state and the release-edge flag occupy mutually exclusive phases.
// Their real local union preserves the original single-byte stack lifetime.
#include "CharacterViews.h"

void Character19::Slot02()
{
    int index;
    unsigned char buttons;
    union {
        unsigned char stage;
        bool released;
    } scan;
    recognizedCommand = 99;
    scan.stage = 0;
    for (index = inputHistoryWriteIndex + 0x6e; index < inputHistoryWriteIndex + 0xb4;
         index = index + 1) {
        buttons = history[index - (index >= 180) * 180];
        if (((buttons & 0xf0) != 0) && (scan.stage == 6)) {
            recognizedCommand = ((buttons & 0xe0) > 0) + 100 +
                ((buttons & 0xc0) > 0) + ((buttons & 0x80) > 0);
            return;
        }
        if (((buttons & 0xf) == 2 + (facing == -1 ? 0 : -1)) && (scan.stage == 5)) {
            if ((buttons & 0xf0) != 0) {
                recognizedCommand = ((buttons & 0xe0) > 0) + 100 +
                    ((buttons & 0xc0) > 0) + ((buttons & 0x80) > 0);
                return;
            }
            scan.stage = 6;
        }
        if (((buttons & 0xf) == 6 + (facing == -1 ? 0 : -1)) && (scan.stage == 4)) scan.stage = 5;
        if (((buttons & 0xf) == 4) && (scan.stage == 3)) scan.stage = 4;
        if (((buttons & 0xf) == 2 + (facing == -1 ? 0 : -1)) && (scan.stage == 2)) scan.stage = 3;
        if (((buttons & 0xf) == 6 + (facing == -1 ? 0 : -1)) && (scan.stage == 1)) scan.stage = 2;
        if (((buttons & 0xf) == 4) && (scan.stage == 0) && (meter >= 1000)) scan.stage = 1;
    }
    scan.stage = 0;
    for (index = inputHistoryWriteIndex + 0x7d; index < inputHistoryWriteIndex + 0xb4;
         index = index + 1) {
        buttons = history[index - (index >= 180) * 180];
        if (((buttons & 0xf0) != 0) && (scan.stage == 3)) {
            recognizedCommand = ((buttons & 0xe0) > 0) + 0x46 +
                ((buttons & 0xc0) > 0) + ((buttons & 0x80) > 0);
            return;
        }
        if (((buttons & 0xf) == 6 + (facing == -1 ? 0 : -1)) && (scan.stage == 2)) {
            if ((buttons & 0xf0) != 0) {
                recognizedCommand = ((buttons & 0xe0) > 0) + 0x46 +
                    ((buttons & 0xc0) > 0) + ((buttons & 0x80) > 0);
                return;
            }
            scan.stage = 3;
        }
        if (((buttons & 0xf) == 6 - (facing == -1)) && (scan.stage == 1)) scan.stage = 2;
        if (((buttons & 0xf) == 2 - (facing == -1)) && (scan.stage == 0)) scan.stage = 1;
    }
    scan.stage = 0;
    for (index = inputHistoryWriteIndex + 0x7d; index < inputHistoryWriteIndex + 0xb4;
         index = index + 1) {
        buttons = history[index - (index >= 180) * 180];
        if (((buttons & 0xf0) != 0) && (scan.stage == 3)) {
            recognizedCommand = ((buttons & 0xe0) > 0) + 0x14 +
                ((buttons & 0xc0) > 0) + ((buttons & 0x80) > 0);
            return;
        }
        if (((buttons & 0xf) == 6 + (facing == -1 ? 0 : -1)) && (scan.stage == 2)) {
            if ((buttons & 0xf0) != 0) {
                recognizedCommand = ((buttons & 0xe0) > 0) + 0x14 +
                    ((buttons & 0xc0) > 0) + ((buttons & 0x80) > 0);
                return;
            }
            scan.stage = 3;
        }
        if (((buttons & 0xf) == 4) && (scan.stage == 1)) scan.stage = 2;
        if (((buttons & 0xf) == 2 + (facing == -1 ? 0 : -1)) && (scan.stage == 0)) scan.stage = 1;
    }
    scan.stage = 0;
    for (index = inputHistoryWriteIndex + 0x7d; index < inputHistoryWriteIndex + 0xb4;
         index = index + 1) {
        buttons = history[index - (index >= 180) * 180];
        if (((buttons & 0xf0) != 0) && (scan.stage == 3)) {
            recognizedCommand = ((buttons & 0xe0) > 0) + 10 +
                ((buttons & 0xc0) > 0) + ((buttons & 0x80) > 0);
            return;
        }
        if (((buttons & 0xf) == 2 + (facing == -1 ? 0 : -1)) && (scan.stage == 2)) {
            if ((buttons & 0xf0) != 0) {
                recognizedCommand = ((buttons & 0xe0) > 0) + 10 +
                    ((buttons & 0xc0) > 0) + ((buttons & 0x80) > 0);
                return;
            }
            scan.stage = 3;
        }
        if (((buttons & 0xf) == 6 + (facing == -1 ? 0 : -1)) && (scan.stage == 1)) scan.stage = 2;
        if (((buttons & 0xf) == 4) && (scan.stage == 0)) scan.stage = 1;
    }
    scan.stage = 0;
    for (index = inputHistoryWriteIndex + 0x7d; index < inputHistoryWriteIndex + 0xb4;
         index = index + 1) {
        buttons = history[index - (index >= 180) * 180];
        if (((buttons & 0xf0) != 0) && (scan.stage == 3)) {
            recognizedCommand = ((buttons & 0xe0) > 0) + 0x1e +
                ((buttons & 0xc0) > 0) + ((buttons & 0x80) > 0);
            return;
        }
        if (((buttons & 0xf) == 2 - (facing == -1)) && (scan.stage == 2)) {
            if ((buttons & 0xf0) != 0) {
                recognizedCommand = ((buttons & 0xe0) > 0) + 0x1e +
                    ((buttons & 0xc0) > 0) + ((buttons & 0x80) > 0);
                return;
            }
            scan.stage = 3;
        }
        if (((buttons & 0xf) == 6 - (facing == -1)) && (scan.stage == 1)) scan.stage = 2;
        if (((buttons & 0xf) == 4) && (scan.stage == 0)) scan.stage = 1;
    }
    scan.released = false;
    for (index = inputHistoryWriteIndex + 0xaf; index < inputHistoryWriteIndex + 0xb4;
         index = index + 1) {
        buttons = history[index - (index >= 180) * 180];
        if (((buttons & 8) != 0) && (scan.released == true)) { recognizedCommand = 6; return; }
        if (((buttons & 8) == 0) && !scan.released) scan.released = true;
    }
    scan.stage = 0;
    for (index = inputHistoryWriteIndex + 0x5a; index < inputHistoryWriteIndex + 0xb4;
         index = index + 1) {
        buttons = history[index - (index >= 180) * 180];
        if (((buttons & 0x80) != 0) && (scan.stage == 4)) { recognizedCommand = 0x35; return; }
        if (((buttons & 0xf) == 4) && (scan.stage == 3)) scan.stage = 4;
        if (((buttons & 0xf) == 0) && (scan.stage == 2)) scan.stage = 3;
        if (((buttons & 0xf) == 4) && (scan.stage == 1)) scan.stage = 2;
        if (((buttons & 0xf) == 0) && (scan.stage == 0)) scan.stage = 1;
    }
    scan.stage = 0;
    for (index = inputHistoryWriteIndex + 0x5a; index < inputHistoryWriteIndex + 0xb4;
         index = index + 1) {
        buttons = history[index - (index >= 180) * 180];
        if (((buttons & 0x40) != 0) && (scan.stage == 4)) { recognizedCommand = 0x34; return; }
        if (((buttons & 0xf) == 4) && (scan.stage == 3)) scan.stage = 4;
        if (((buttons & 0xf) == 0) && (scan.stage == 2)) scan.stage = 3;
        if (((buttons & 0xf) == 4) && (scan.stage == 1)) scan.stage = 2;
        if (((buttons & 0xf) == 0) && (scan.stage == 0)) scan.stage = 1;
    }
    scan.stage = 0;
    for (index = inputHistoryWriteIndex + 0x5a; index < inputHistoryWriteIndex + 0xb4;
         index = index + 1) {
        buttons = history[index - (index >= 180) * 180];
        if (((buttons & 0x20) != 0) && (scan.stage == 4)) { recognizedCommand = 0x33; return; }
        if (((buttons & 0xf) == 4) && (scan.stage == 3)) scan.stage = 4;
        if (((buttons & 0xf) == 0) && (scan.stage == 2)) scan.stage = 3;
        if (((buttons & 0xf) == 4) && (scan.stage == 1)) scan.stage = 2;
        if (((buttons & 0xf) == 0) && (scan.stage == 0)) scan.stage = 1;
    }
    scan.stage = 0;
    for (index = inputHistoryWriteIndex + 0x5a; index < inputHistoryWriteIndex + 0xb4;
         index = index + 1) {
        buttons = history[index - (index >= 180) * 180];
        if (((buttons & 0x10) != 0) && (scan.stage == 4)) { recognizedCommand = 0x32; return; }
        if (((buttons & 0xf) == 4) && (scan.stage == 3)) scan.stage = 4;
        if (((buttons & 0xf) == 0) && (scan.stage == 2)) scan.stage = 3;
        if (((buttons & 0xf) == 4) && (scan.stage == 1)) scan.stage = 2;
        if (((buttons & 0xf) == 0) && (scan.stage == 0)) scan.stage = 1;
    }
    scan.stage = 0;
    for (index = inputHistoryWriteIndex + 0x87; index < inputHistoryWriteIndex + 0xb4;
         index = index + 1) {
        buttons = history[index - (index >= 180) * 180];
        if (((buttons & 0xf) == 1) && (scan.stage == 3)) { recognizedCommand = 1; return; }
        if (((buttons & 0xf) == 0) && (scan.stage == 2)) scan.stage = 3;
        if (((buttons & 0xf) == 1) && (scan.stage == 1)) scan.stage = 2;
        if (((buttons & 0xf) == 0) && (scan.stage == 0)) scan.stage = 1;
    }
    scan.stage = 0;
    for (index = inputHistoryWriteIndex + 0x87; index < inputHistoryWriteIndex + 0xb4;
         index = index + 1) {
        buttons = history[index - (index >= 180) * 180];
        if (((buttons & 0xf) == 2) && (scan.stage == 3)) { recognizedCommand = 0; return; }
        if (((buttons & 0xf) == 0) && (scan.stage == 2)) scan.stage = 3;
        if (((buttons & 0xf) == 2) && (scan.stage == 1)) scan.stage = 2;
        if (((buttons & 0xf) == 0) && (scan.stage == 0)) scan.stage = 1;
    }
}
