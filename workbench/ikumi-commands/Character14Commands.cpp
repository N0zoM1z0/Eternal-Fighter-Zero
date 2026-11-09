// Ikumi command recognition: independently recovered highest-priority input scan.
// This is a workbench PARTIAL implementation of the original 5,153-byte Slot02,
// not accepted as a strict Exact whole function or production source.
#include "../../src/CharacterViews.h"

void Character14::Slot02()
{
    int i;
    unsigned char buttons, stage;
    recognizedCommand = 99;

    stage = 0;
    i = inputHistoryWriteIndex + 0x46;
    for (; i < inputHistoryWriteIndex + 0xb4; ++i) {
        buttons = history[i - (i >= 180) * 180];
        if (((buttons & 0x40) != 0) && (stage == 9)) {
            recognizedCommand = 0x5e;
            return;
        }
        if (((buttons & 0xf) == 2 + (facing == -1 ? 0 : -1)) && (stage == 8)) {
            if ((buttons & 0x40) != 0) {
                recognizedCommand = 0x5e;
                return;
            }
            stage = 9;
        }
        if (((buttons & 0xf) == 6 + (facing == -1 ? 0 : -1)) && (stage == 7)) {
            stage = 8;
        }
        if (((buttons & 0xf) == 4) && (stage == 6)) {
            stage = 7;
        }
        if (((buttons & 0xf) == 2 + (facing == -1 ? 0 : -1)) && (stage == 5)) {
            stage = 6;
        }
        if (((buttons & 0xf) == 6 + (facing == -1 ? 0 : -1)) && (stage == 4)) {
            stage = 5;
        }
        if (((buttons & 0xf) == 4) && (stage == 3)) {
            stage = 4;
        }
        if (((buttons & 0xf) == 2 + (facing == -1 ? 0 : -1)) && (stage == 2)) {
            stage = 3;
        }
        if (((buttons & 0xf) == 6 + (facing == -1 ? 0 : -1)) && (stage == 1)) {
            stage = 2;
        }
        if (((buttons & 0xf) == 4) && (stage == 0)) {
            stage = 1;
        }
    }
    // Second priority scan: original 45–179-frame history window.
    // This sequence includes both a high-nibble completed state and an
    // early high-nibble finish from stage 5, exactly as the target does.
    stage = 0;
    i = inputHistoryWriteIndex + 0x2d;
    for (; i < inputHistoryWriteIndex + 0xb4; ++i) {
        buttons = history[i - (i >= 180) * 180];
        if (((buttons & 0xf0) != 0) && (stage == 7)) {
            recognizedCommand = ((buttons & 0xe0) > 0) + 0x96 +
                                ((buttons & 0xc0) > 0) + ((buttons & 0x80) > 0);
            return;
        }
        if (((buttons & 0xf) == 2 + (facing == -1 ? 0 : -1)) &&
            (stage == 5)) {
            if ((buttons & 0xf0) != 0) {
                recognizedCommand = ((buttons & 0xe0) > 0) + 0x96 +
                                    ((buttons & 0xc0) > 0) + ((buttons & 0x80) > 0);
                return;
            }
            stage = 8;
        }
        if (((buttons & 0xf) == 6 + (facing == -1 ? 0 : -1)) &&
            (stage == 6)) {
            stage = 7;
        }
        if (((buttons & 0xf) == 6 - (facing == -1)) &&
            (stage == 5)) {
            stage = 6;
        }
        if (((buttons & 0xf) == 2 - (facing == -1)) &&
            (stage == 4)) {
            stage = 5;
        }
        if (((buttons & 0xf) == 2 + (facing == -1 ? 0 : -1)) &&
            (stage == 3)) {
            stage = 4;
        }
        if (((buttons & 0xf) == 6 + (facing == -1 ? 0 : -1)) &&
            (stage == 2)) {
            stage = 3;
        }
        if (((buttons & 0xf) == 6 - (facing == -1)) &&
            (stage == 1)) {
            stage = 2;
        }
        if (((buttons & 0xf) == 2 - (facing == -1)) &&
            (stage == 0)) {
            stage = 1;
        }
    }
    // Third priority scan: a charged motion whose start is also allowed
    // when Ikumi's field315c override is positive, even below 1000 meter.
    stage = 0;
    i = inputHistoryWriteIndex + 0x5a;
    for (; i < inputHistoryWriteIndex + 0xb4; ++i) {
        buttons = history[i - (i >= 180) * 180];
        if (((buttons & 0xf0) != 0) && (stage == 5)) {
            recognizedCommand = ((buttons & 0xe0) > 0) + 0xaa +
                                ((buttons & 0xc0) > 0) + ((buttons & 0x80) > 0);
            return;
        }
        if (((buttons & 0xf) == 2 + (facing == -1 ? 0 : -1)) &&
            (stage == 4)) {
            if ((buttons & 0xf0) != 0) {
                recognizedCommand = ((buttons & 0xe0) > 0) + 0xa0 +
                                    ((buttons & 0xc0) > 0) + ((buttons & 0x80) > 0);
                return;
            }
            stage = 5;
        }
        if (((buttons & 0xf) == 6 + (facing == -1 ? 0 : -1)) &&
            (stage == 3)) {
            stage = 4;
        }
        if (((buttons & 0xf) == 2 - (facing == -1)) &&
            (stage == 2)) {
            stage = 3;
        }
        if (((buttons & 0xf) == 6 - (facing == -1)) &&
            (stage == 1)) {
            stage = 2;
        }
        if (((buttons & 0xf) == 4) && (stage == 0) &&
            (meter >= 1000 || field315c > 0)) {
            stage = 1;
        }
    }
    // Further 12 original ordered scans remain to be recovered.
}
