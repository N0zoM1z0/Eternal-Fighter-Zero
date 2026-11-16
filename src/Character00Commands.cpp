// Nanase priority input-history command recognizer: 15 original natural C++ scans.
// Native virtual Slot02 complete owner at 0x0048E290.
#include "CharacterViews.h"
struct Character00CommandFields {
    unsigned char inherited[0x344c];
    int field344c;
};
#define C00 (reinterpret_cast<Character00CommandFields *>(this))
void Character00::Slot02()
{
    int i;
    unsigned char buttons, stage;
    recognizedCommand = 99;
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
        if (((buttons & 0xf) == 4) && (stage == 0) && (meter >= 1000) && (C00->field344c == 0)) {
            stage = 1;
        }
    }
    stage = 0;
    i = inputHistoryWriteIndex + 0x5a;
    for (; i < inputHistoryWriteIndex + 0xb4; ++i) {
        buttons = history[i - (i >= 180) * 180];
        if (((buttons & 0xf0) != 0) && (stage == 6)) {
            recognizedCommand = ((buttons & 0xe0) > 0) + 0x64 +
                                ((buttons & 0xc0) > 0) + ((buttons & 0x80) > 0);
            return;
        }
        if (((buttons & 0xf) == 2 + (facing == -1 ? 0 : -1)) && (stage == 5)) {
            if ((buttons & 0xf0) != 0) {
                recognizedCommand = ((buttons & 0xe0) > 0) + 0x64 +
                                    ((buttons & 0xc0) > 0) + ((buttons & 0x80) > 0);
                return;
            }
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
        if (((buttons & 0xf) == 4) && (stage == 0) && (meter >= 1000) && (C00->field344c == 1)) {
            stage = 1;
        }
    }
    stage = 0;
    i = inputHistoryWriteIndex + 0x5a;
    for (; i < inputHistoryWriteIndex + 0xb4; ++i) {
        buttons = history[i - (i >= 180) * 180];
        if (((buttons & 0xf0) != 0) && (stage == 3)) {
            recognizedCommand = ((buttons & 0xe0) > 0) + 0x46 +
                                ((buttons & 0xc0) > 0) + ((buttons & 0x80) > 0);
            return;
        }
        if (((buttons & 0xf) == 6 + (facing == -1 ? 0 : -1)) &&
            (stage == 2)) {
            if ((buttons & 0xf0) != 0) {
                recognizedCommand = ((buttons & 0xe0) > 0) + 0x46 +
                                    ((buttons & 0xc0) > 0) + ((buttons & 0x80) > 0);
                return;
            }
            stage = 3;
        }
        if (((buttons & 0xf) == 6 - (facing == -1)) && (stage == 1)) {
            stage = 2;
        }
        if (((buttons & 0xf) == 2 - (facing == -1)) && (stage == 0)) {
            stage = 1;
        }
    }
    stage = 0;
    i = inputHistoryWriteIndex + 0x78;
    for (; i < inputHistoryWriteIndex + 0xb4; ++i) {
        buttons = history[i - (i >= 180) * 180];
        if (((buttons & 0xf0) != 0) && (stage == 3)) {
            recognizedCommand = ((buttons & 0xe0) > 0) + 0x14 +
                                ((buttons & 0xc0) > 0) + ((buttons & 0x80) > 0);
            return;
        }
        if (((buttons & 0xf) == 6 + (facing == -1 ? 0 : -1)) && (stage == 2)) {
            if ((buttons & 0xf0) != 0) {
                recognizedCommand = ((buttons & 0xe0) > 0) + 0x14 +
                                    ((buttons & 0xc0) > 0) + ((buttons & 0x80) > 0);
                return;
            }
            stage = 3;
        }
        if (((buttons & 0xf) == 4) && (stage == 1)) {
            stage = 2;
        }
        if (((buttons & 0xf) == 2 + (facing == -1 ? 0 : -1)) && (stage == 0)) {
            stage = 1;
        }
    }
    stage = 0;
    i = inputHistoryWriteIndex + 0x87;
    for (; i < inputHistoryWriteIndex + 0xb4; ++i) {
        buttons = history[i - (i >= 180) * 180];
        if (((buttons & 0xf0) != 0) && (stage == 3)) {
            recognizedCommand = ((buttons & 0xe0) > 0) + 0xa +
                                ((buttons & 0xc0) > 0) + ((buttons & 0x80) > 0);
            return;
        }
        if (((buttons & 0xf) == 2 + (facing == -1 ? 0 : -1)) && (stage == 2)) {
            if ((buttons & 0xf0) != 0) {
                recognizedCommand = ((buttons & 0xe0) > 0) + 0xa +
                                    ((buttons & 0xc0) > 0) + ((buttons & 0x80) > 0);
                return;
            }
            stage = 3;
        }
        if (((buttons & 0xf) == 6 + (facing == -1 ? 0 : -1)) && (stage == 1)) {
            stage = 2;
        }
        if (((buttons & 0xf) == 4) && (stage == 0)) {
            stage = 1;
        }
    }
    stage = 0;
    i = inputHistoryWriteIndex + 0x87;
    for (; i < inputHistoryWriteIndex + 0xb4; ++i) {
        buttons = history[i - (i >= 180) * 180];
        if (((buttons & 0xf0) != 0) && (stage == 3)) {
            recognizedCommand = ((buttons & 0xe0) > 0) + 0x28 +
                                ((buttons & 0xc0) > 0) + ((buttons & 0x80) > 0);
            return;
        }
        if (((buttons & 0xf) == 4) && (stage == 2)) {
            if ((buttons & 0xf0) != 0) {
                recognizedCommand = ((buttons & 0xe0) > 0) + 0x28 +
                                    ((buttons & 0xc0) > 0) + ((buttons & 0x80) > 0);
                return;
            }
            stage = 3;
        }
        if (((buttons & 0xf) == 6 - (facing == -1)) && (stage == 1)) {
            stage = 2;
        }
        if (((buttons & 0xf) == 2 - (facing == -1)) && (stage == 0)) {
            stage = 1;
        }
    }
    stage = 0;
    i = inputHistoryWriteIndex + 0x87;
    for (; i < inputHistoryWriteIndex + 0xb4; ++i) {
        buttons = history[i - (i >= 180) * 180];
        if (((buttons & 0xf0) != 0) && (stage == 3)) {
            recognizedCommand = ((buttons & 0xe0) > 0) + 0x1e +
                                ((buttons & 0xc0) > 0) + ((buttons & 0x80) > 0);
            return;
        }
        if (((buttons & 0xf) == 2 - (facing == -1)) && (stage == 2)) {
            if ((buttons & 0xf0) != 0) {
                recognizedCommand = ((buttons & 0xe0) > 0) + 0x1e +
                                    ((buttons & 0xc0) > 0) + ((buttons & 0x80) > 0);
                return;
            }
            stage = 3;
        }
        if (((buttons & 0xf) == 6 - (facing == -1)) && (stage == 1)) {
            stage = 2;
        }
        if (((buttons & 0xf) == 4) && (stage == 0)) {
            stage = 1;
        }
    }
    stage = 0;
    i = inputHistoryWriteIndex + 0xaf;
    for (; i < inputHistoryWriteIndex + 0xb4; ++i) {
        buttons = history[i - (i >= 180) * 180];
        if (((buttons & 8) != 0) && (stage == 1)) {
            recognizedCommand = 6;
            return;
        }
        if (((buttons & 8) == 0) && (stage == 0)) {
            stage = 1;
        }
    }
    stage = 0;
    i = inputHistoryWriteIndex + 0x5a;
    for (; i < inputHistoryWriteIndex + 0xb4; ++i) {
        buttons = history[i - (i >= 180) * 180];
        if (((buttons & 0x80) != 0) && (stage == 4)) {
            recognizedCommand = 0x35;
            return;
        }
        if (((buttons & 0xf) == 4) && (stage == 3)) {
            stage = 4;
        }
        if (((buttons & 0xf) == 0) && (stage == 2)) {
            stage = 3;
        }
        if (((buttons & 0xf) == 4) && (stage == 1)) {
            stage = 2;
        }
        if (((buttons & 0xf) == 0) && (stage == 0) && (field0008 == 0x60)) {
            stage = 1;
        }
    }
    stage = 0;
    i = inputHistoryWriteIndex + 0x5a;
    for (; i < inputHistoryWriteIndex + 0xb4; ++i) {
        buttons = history[i - (i >= 180) * 180];
        if (((buttons & 0x40) != 0) && (stage == 4)) {
            recognizedCommand = 0x34;
            return;
        }
        if (((buttons & 0xf) == 4) && (stage == 3)) {
            stage = 4;
        }
        if (((buttons & 0xf) == 0) && (stage == 2)) {
            stage = 3;
        }
        if (((buttons & 0xf) == 4) && (stage == 1)) {
            stage = 2;
        }
        if (((buttons & 0xf) == 0) && (stage == 0)) {
            stage = 1;
        }
    }
    stage = 0;
    i = inputHistoryWriteIndex + 0x87;
    for (; i < inputHistoryWriteIndex + 0xb4; ++i) {
        buttons = history[i - (i >= 180) * 180];
        if (((buttons & 0x20) != 0) && (stage == 4)) {
            recognizedCommand = 0x33;
            return;
        }
        if (((buttons & 0xf) == 4) && (stage == 3)) {
            stage = 4;
        }
        if (((buttons & 0xf) == 0) && (stage == 2)) {
            stage = 3;
        }
        if (((buttons & 0xf) == 4) && (stage == 1)) {
            stage = 2;
        }
        if (((buttons & 0xf) == 0) && (stage == 0)) {
            stage = 1;
        }
    }
    stage = 0;
    i = inputHistoryWriteIndex + 0x87;
    for (; i < inputHistoryWriteIndex + 0xb4; ++i) {
        buttons = history[i - (i >= 180) * 180];
        if (((buttons & 0x10) != 0) && (stage == 4)) {
            recognizedCommand = 0x32;
            return;
        }
        if (((buttons & 0xf) == 4) && (stage == 3)) {
            stage = 4;
        }
        if (((buttons & 0xf) == 0) && (stage == 2)) {
            stage = 3;
        }
        if (((buttons & 0xf) == 4) && (stage == 1)) {
            stage = 2;
        }
        if (((buttons & 0xf) == 0) && (stage == 0)) {
            stage = 1;
        }
    }
    stage = 0;
    i = inputHistoryWriteIndex + 0x87;
    for (; i < inputHistoryWriteIndex + 0xb4; ++i) {
        buttons = history[i - (i >= 180) * 180];
        if (((buttons & 0xf) == 1) && (stage == 3)) {
            recognizedCommand = 1;
            return;
        }
        if (((buttons & 0xf) == 0) && (stage == 2)) {
            stage = 3;
        }
        if (((buttons & 0xf) == 1) && (stage == 1)) {
            stage = 2;
        }
        if (((buttons & 0xf) == 0) && (stage == 0)) {
            stage = 1;
        }
    }
    stage = 0;
    i = inputHistoryWriteIndex + 0x87;
    for (; i < inputHistoryWriteIndex + 0xb4; ++i) {
        buttons = history[i - (i >= 180) * 180];
        if (((buttons & 0xf) == 2) && (stage == 3)) {
            recognizedCommand = 0;
            return;
        }
        if (((buttons & 0xf) == 0) && (stage == 2)) {
            stage = 3;
        }
        if (((buttons & 0xf) == 2) && (stage == 1)) {
            stage = 2;
        }
        if (((buttons & 0xf) == 0) && (stage == 0)) {
            stage = 1;
        }
    }}
#undef C00
