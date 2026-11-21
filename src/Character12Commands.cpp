// EX Nanase's ordered command recognition over the 180-frame input ring.
// Native owner: Character12::Slot02 at 0x006D2770.
#include "CharacterViews.h"

void Character12::Slot02()
{
    int i;
    unsigned char buttons;
    unsigned char stage;

    recognizedCommand = 99;
    stage = 0;
    for (i = inputHistoryWriteIndex + 0x5a; i < inputHistoryWriteIndex + 0xb4; ++i) {
        buttons = history[i - (i >= 180) * 180];
        if (((buttons & 0xf0) != 0) && (stage == 6)) {
            recognizedCommand = ((buttons & 0xe0) > 0) + 0x6e +
                ((buttons & 0xc0) > 0) + ((buttons & 0x80) > 0);
            return;
        }
        if (((buttons & 0x0f) == 2 - (facing == -1 ? 1 : 0)) && (stage == 5)) {
            if ((buttons & 0xf0) != 0) {
                recognizedCommand = ((buttons & 0xe0) > 0) + 0x6e +
                    ((buttons & 0xc0) > 0) + ((buttons & 0x80) > 0);
                return;
            }
            stage = 6;
        }
        if (((buttons & 0x0f) == 6 - (facing == -1 ? 1 : 0)) && (stage == 4)) stage = 5;
        if (((buttons & 0x0f) == 4) && (stage == 3)) stage = 4;
        if (((buttons & 0x0f) == 2 - (facing == -1 ? 1 : 0)) && (stage == 2)) stage = 3;
        if (((buttons & 0x0f) == 6 - (facing == -1 ? 1 : 0)) && (stage == 1)) stage = 2;
        if (((buttons & 0x0f) == 4) && (stage == 0) && (meter >= 1000)) stage = 1;
    }

    stage = 0;
    for (i = inputHistoryWriteIndex + 0x5a; i < inputHistoryWriteIndex + 0xb4; ++i) {
        buttons = history[i - (i >= 180) * 180];
        if (((buttons & 0xf0) != 0) && (stage == 6)) {
            recognizedCommand = ((buttons & 0xe0) > 0) + 100 +
                ((buttons & 0xc0) > 0) + ((buttons & 0x80) > 0);
            return;
        }
        if (((buttons & 0x0f) == 2 + (facing == -1 ? 0 : -1)) && (stage == 5)) {
            if ((buttons & 0xf0) != 0) {
                recognizedCommand = ((buttons & 0xe0) > 0) + 100 +
                    ((buttons & 0xc0) > 0) + ((buttons & 0x80) > 0);
                return;
            }
            stage = 6;
        }
        if (((buttons & 0x0f) == 6 + (facing == -1 ? 0 : -1)) && (stage == 4)) stage = 5;
        if (((buttons & 0x0f) == 4) && (stage == 3)) stage = 4;
        if (((buttons & 0x0f) == 2 + (facing == -1 ? 0 : -1)) && (stage == 2)) stage = 3;
        if (((buttons & 0x0f) == 6 + (facing == -1 ? 0 : -1)) && (stage == 1)) stage = 2;
        if (((buttons & 0x0f) == 4) && (stage == 0) && (meter >= 1000)) stage = 1;
    }

    stage = 0;
    for (i = inputHistoryWriteIndex + 0x69; i < inputHistoryWriteIndex + 0xb4; ++i) {
        buttons = history[i - (i >= 180) * 180];
        if (((buttons & 0xf0) != 0) && (stage == 3)) {
            recognizedCommand = ((buttons & 0xe0) > 0) + 0x46 +
                ((buttons & 0xc0) > 0) + ((buttons & 0x80) > 0);
            return;
        }
        if (((buttons & 0x0f) == 6 + (facing == -1 ? 0 : -1)) && (stage == 2)) {
            if ((buttons & 0xf0) != 0) {
                recognizedCommand = ((buttons & 0xe0) > 0) + 0x46 +
                    ((buttons & 0xc0) > 0) + ((buttons & 0x80) > 0);
                return;
            }
            stage = 3;
        }
        if (((buttons & 0x0f) == 6 - (facing == -1 ? 1 : 0)) && (stage == 1)) stage = 2;
        if (((buttons & 0x0f) == 2 - (facing == -1 ? 1 : 0)) && (stage == 0)) stage = 1;
    }

    stage = 0;
    for (i = inputHistoryWriteIndex + 0x78; i < inputHistoryWriteIndex + 0xb4; ++i) {
        buttons = history[i - (i >= 180) * 180];
        if (((buttons & 0xf0) != 0) && (stage == 3)) {
            recognizedCommand = ((buttons & 0xe0) > 0) + 0x14 +
                ((buttons & 0xc0) > 0) + ((buttons & 0x80) > 0);
            return;
        }
        if (((buttons & 0x0f) == 6 + (facing == -1 ? 0 : -1)) && (stage == 2)) {
            if ((buttons & 0xf0) != 0) {
                recognizedCommand = ((buttons & 0xe0) > 0) + 0x14 +
                    ((buttons & 0xc0) > 0) + ((buttons & 0x80) > 0);
                return;
            }
            stage = 3;
        }
        if (((buttons & 0x0f) == 4) && (stage == 1)) stage = 2;
        if (((buttons & 0x0f) == 2 + (facing == -1 ? 0 : -1)) && (stage == 0)) stage = 1;
    }

    stage = 0;
    for (i = inputHistoryWriteIndex + 0x87; i < inputHistoryWriteIndex + 0xb4; ++i) {
        buttons = history[i - (i >= 180) * 180];
        if (((buttons & 0xf0) != 0) && (stage == 3)) {
            recognizedCommand = ((buttons & 0xe0) > 0) + 10 +
                ((buttons & 0xc0) > 0) + ((buttons & 0x80) > 0);
            return;
        }
        if (((buttons & 0x0f) == 2 + (facing == -1 ? 0 : -1)) && (stage == 2)) {
            if ((buttons & 0xf0) != 0) {
                recognizedCommand = ((buttons & 0xe0) > 0) + 10 +
                    ((buttons & 0xc0) > 0) + ((buttons & 0x80) > 0);
                return;
            }
            stage = 3;
        }
        if (((buttons & 0x0f) == 6 + (facing == -1 ? 0 : -1)) && (stage == 1)) stage = 2;
        if (((buttons & 0x0f) == 4) && (stage == 0)) stage = 1;
    }

    stage = 0;
    for (i = inputHistoryWriteIndex + 0x87; i < inputHistoryWriteIndex + 0xb4; ++i) {
        buttons = history[i - (i >= 180) * 180];
        if (((buttons & 0xf0) != 0) && (stage == 3)) {
            recognizedCommand = ((buttons & 0xe0) > 0) + 0x28 +
                ((buttons & 0xc0) > 0) + ((buttons & 0x80) > 0);
            return;
        }
        if (((buttons & 0x0f) == 4) && (stage == 2)) {
            if ((buttons & 0xf0) != 0) {
                recognizedCommand = ((buttons & 0xe0) > 0) + 0x28 +
                    ((buttons & 0xc0) > 0) + ((buttons & 0x80) > 0);
                return;
            }
            stage = 3;
        }
        if (((buttons & 0x0f) == 6 - (facing == -1 ? 1 : 0)) && (stage == 1)) stage = 2;
        if (((buttons & 0x0f) == 2 - (facing == -1 ? 1 : 0)) && (stage == 0)) stage = 1;
    }

    stage = 0;
    for (i = inputHistoryWriteIndex + 0x87; i < inputHistoryWriteIndex + 0xb4; ++i) {
        buttons = history[i - (i >= 180) * 180];
        if (((buttons & 0xf0) != 0) && (stage == 3)) {
            recognizedCommand = ((buttons & 0xe0) > 0) + 0x1e +
                ((buttons & 0xc0) > 0) + ((buttons & 0x80) > 0);
            return;
        }
        if (((buttons & 0x0f) == 2 - (facing == -1 ? 1 : 0)) && (stage == 2)) {
            if ((buttons & 0xf0) != 0) {
                recognizedCommand = ((buttons & 0xe0) > 0) + 0x1e +
                    ((buttons & 0xc0) > 0) + ((buttons & 0x80) > 0);
                return;
            }
            stage = 3;
        }
        if (((buttons & 0x0f) == 6 - (facing == -1 ? 1 : 0)) && (stage == 1)) stage = 2;
        if (((buttons & 0x0f) == 4) && (stage == 0)) stage = 1;
    }

    stage = 0;
    for (i = inputHistoryWriteIndex + 0xaf; i < inputHistoryWriteIndex + 0xb4; ++i) {
        buttons = history[i - (i >= 180) * 180];
        if (((buttons & 0x08) != 0) && (stage == 1)) {
            recognizedCommand = 6;
            return;
        }
        if (((buttons & 0x08) == 0) && (stage == 0)) stage = 1;
    }

    stage = 0;
    for (i = inputHistoryWriteIndex + 0x5a; i < inputHistoryWriteIndex + 0xb4; ++i) {
        buttons = history[i - (i >= 180) * 180];
        if (((buttons & 0x80) != 0) && (stage == 4)) {
            recognizedCommand = 0x35;
            return;
        }
        if (((buttons & 0x0f) == 4) && (stage == 3)) stage = 4;
        if (((buttons & 0x0f) == 0) && (stage == 2)) stage = 3;
        if (((buttons & 0x0f) == 4) && (stage == 1)) stage = 2;
        if (((buttons & 0x0f) == 0) && (stage == 0) && (field0008 == 0x60)) stage = 1;
    }

    stage = 0;
    for (i = inputHistoryWriteIndex + 0x5a; i < inputHistoryWriteIndex + 0xb4; ++i) {
        buttons = history[i - (i >= 180) * 180];
        if (((buttons & 0x40) != 0) && (stage == 4)) {
            recognizedCommand = 0x34;
            return;
        }
        if (((buttons & 0x0f) == 4) && (stage == 3)) stage = 4;
        if (((buttons & 0x0f) == 0) && (stage == 2)) stage = 3;
        if (((buttons & 0x0f) == 4) && (stage == 1)) stage = 2;
        if (((buttons & 0x0f) == 0) && (stage == 0)) stage = 1;
    }

    stage = 0;
    for (i = inputHistoryWriteIndex + 0x87; i < inputHistoryWriteIndex + 0xb4; ++i) {
        buttons = history[i - (i >= 180) * 180];
        if (((buttons & 0x20) != 0) && (stage == 4)) {
            recognizedCommand = 0x33;
            return;
        }
        if (((buttons & 0x0f) == 4) && (stage == 3)) stage = 4;
        if (((buttons & 0x0f) == 0) && (stage == 2)) stage = 3;
        if (((buttons & 0x0f) == 4) && (stage == 1)) stage = 2;
        if (((buttons & 0x0f) == 0) && (stage == 0)) stage = 1;
    }

    stage = 0;
    for (i = inputHistoryWriteIndex + 0x87; i < inputHistoryWriteIndex + 0xb4; ++i) {
        buttons = history[i - (i >= 180) * 180];
        if (((buttons & 0x10) != 0) && (stage == 4)) {
            recognizedCommand = 0x32;
            return;
        }
        if (((buttons & 0x0f) == 4) && (stage == 3)) stage = 4;
        if (((buttons & 0x0f) == 0) && (stage == 2)) stage = 3;
        if (((buttons & 0x0f) == 4) && (stage == 1)) stage = 2;
        if (((buttons & 0x0f) == 0) && (stage == 0)) stage = 1;
    }

    stage = 0;
    for (i = inputHistoryWriteIndex + 0x87; i < inputHistoryWriteIndex + 0xb4; ++i) {
        buttons = history[i - (i >= 180) * 180];
        if (((buttons & 0x0f) == 1) && (stage == 3)) {
            recognizedCommand = 1;
            return;
        }
        if (((buttons & 0x0f) == 0) && (stage == 2)) stage = 3;
        if (((buttons & 0x0f) == 1) && (stage == 1)) stage = 2;
        if (((buttons & 0x0f) == 0) && (stage == 0)) stage = 1;
    }

    stage = 0;
    for (i = inputHistoryWriteIndex + 0x87; i < inputHistoryWriteIndex + 0xb4; ++i) {
        buttons = history[i - (i >= 180) * 180];
        if (((buttons & 0x0f) == 2) && (stage == 3)) {
            recognizedCommand = 0;
            return;
        }
        if (((buttons & 0x0f) == 0) && (stage == 2)) stage = 3;
        if (((buttons & 0x0f) == 2) && (stage == 1)) stage = 2;
        if (((buttons & 0x0f) == 0) && (stage == 0)) stage = 1;
    }
}
