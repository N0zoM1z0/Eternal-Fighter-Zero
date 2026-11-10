// Sayuri's ordered virtual Slot02 input-history command interpreter.
// Original owner 0x004493C0, 5995 bytes; current source is a partial draft.
#include "../../src/CharacterViews.h"

void Character09::Slot02()
{
    int i;
    unsigned char buttons, stage;
    recognizedCommand = 99;

    stage = 0;
    for (i = inputHistoryWriteIndex + 0x5a; i < inputHistoryWriteIndex + 0xb4; ++i) {
        buttons = history[i - (i >= 180) * 180];
        if ((buttons & 0x80) != 0 && stage == 5) {
            recognizedCommand = 0x62;
            return;
        }
        if (buttons == 0 && stage == 4)
            stage = 5;
        if ((buttons & 0xf) == 4 && stage == 3)
            stage = 4;
        if ((buttons & 0xe0) != 0 && stage == 3)
            break;
        if ((buttons & 0x10) != 0 && stage == 2)
            stage = 3;
        if (buttons == 0 && stage == 1)
            stage = 2;
        if ((buttons & 0xf) == 4 && stage == 0 &&
            meter == 3000 && positionY == 0.0)
            stage = 1;
    }
    stage = 0;
    for (i = inputHistoryWriteIndex + 0x5a; i < inputHistoryWriteIndex + 0xb4; ++i) {
        buttons = history[i - (i >= 180) * 180];
        if ((buttons & 0xf0) != 0 && stage == 5) {
            recognizedCommand =
                ((buttons & 0xe0) > 0) + 0xaa + ((buttons & 0xc0) > 0) +
                ((buttons & 0x80) > 0);
            return;
        }
        if ((buttons & 0xf) == 2 + (facing == -1 ? 0 : -1) && stage == 4) {
            if ((buttons & 0xf0) != 0) {
                recognizedCommand =
                    ((buttons & 0xe0) > 0) + 0xaa + ((buttons & 0xc0) > 0) +
                    ((buttons & 0x80) > 0);
                return;
            }
            stage = 5;
        }
        if ((buttons & 0xf) == (facing == -1 ? 6 : 5) && stage == 3)
            stage = 4;
        if ((buttons & 0xf) == 2 - (facing == -1 ? 1 : 0) && stage == 2)
            stage = 3;
        if ((buttons & 0xf) == 6 - (facing == -1 ? 1 : 0) && stage == 1)
            stage = 2;
        if ((buttons & 0xf) == 4 && stage == 0 &&
            meter >= 1000 && positionY == 0.0)
            stage = 1;
    }
    stage = 0;
    for (i = inputHistoryWriteIndex + 0x2d; i < inputHistoryWriteIndex + 0xb4; ++i) {
        buttons = history[i - (i >= 180) * 180];
        if ((buttons & 0xf0) != 0 && stage == 8) {
            recognizedCommand =
                ((buttons & 0xe0) > 0) + 0xa0 + ((buttons & 0xc0) > 0) +
                ((buttons & 0x80) > 0);
            return;
        }
        if ((buttons & 0xf) == 2 - (facing == -1 ? 1 : 0) && stage == 7) {
            if ((buttons & 0xf0) != 0) {
                recognizedCommand =
                    ((buttons & 0xe0) > 0) + 0xa0 + ((buttons & 0xc0) > 0) +
                    ((buttons & 0x80) > 0);
                return;
            }
            stage = 8;
        }
        if ((buttons & 0xf) == 6 - (facing == -1 ? 1 : 0) && stage == 6)
            stage = 7;
        if ((buttons & 0xf) == (facing == -1 ? 6 : 5) && stage == 5)
            stage = 6;
        if ((buttons & 0xf) == 2 + (facing == -1 ? 0 : -1) && stage == 4)
            stage = 5;
        if ((buttons & 0xf) == 2 - (facing == -1 ? 1 : 0) && stage == 3)
            stage = 4;
        if ((buttons & 0xf) == 6 - (facing == -1 ? 1 : 0) && stage == 2)
            stage = 3;
        if ((buttons & 0xf) == (facing == -1 ? 6 : 5) && stage == 1)
            stage = 2;
        if ((buttons & 0xf) == 2 + (facing == -1 ? 0 : -1) && stage == 0 &&
            positionY == 0.0)
            stage = 1;
    }
    stage = 0;
    for (i = inputHistoryWriteIndex + 0x5a; i < inputHistoryWriteIndex + 0xb4; ++i) {
        buttons = history[i - (i >= 180) * 180];
        if ((buttons & 0xf0) != 0 && stage == 6) {
            recognizedCommand =
                ((buttons & 0xe0) > 0) + 0x64 + ((buttons & 0xc0) > 0) +
                ((buttons & 0x80) > 0);
            return;
        }
        if ((buttons & 0xf) == 2 - (facing == -1 ? 1 : 0) && stage == 5) {
            if ((buttons & 0xf0) != 0) {
                recognizedCommand =
                    ((buttons & 0xe0) > 0) + 0x64 + ((buttons & 0xc0) > 0) +
                    ((buttons & 0x80) > 0);
                return;
            }
            stage = 6;
        }
        if ((buttons & 0xf) == 6 - (facing == -1 ? 1 : 0) && stage == 4)
            stage = 5;
        if ((buttons & 0xf) == 4 && stage == 3)
            stage = 4;
        if ((buttons & 0xf) == 2 - (facing == -1 ? 1 : 0) && stage == 2)
            stage = 3;
        if ((buttons & 0xf) == 6 - (facing == -1 ? 1 : 0) && stage == 1)
            stage = 2;
        if ((buttons & 0xf) == 4 && stage == 0 && positionY == 0.0)
            stage = 1;
    }
    stage = 0;
    for (i = inputHistoryWriteIndex + 0x5a; i < inputHistoryWriteIndex + 0xb4; ++i) {
        buttons = history[i - (i >= 180) * 180];
        if ((buttons & 0xf0) != 0 && stage == 6) {
            recognizedCommand =
                ((buttons & 0xe0) > 0) + 0x6e + ((buttons & 0xc0) > 0) +
                ((buttons & 0x80) > 0);
            return;
        }
        if ((buttons & 0xf) == 2 + (facing == -1 ? 0 : -1) && stage == 5) {
            if ((buttons & 0xf0) != 0) {
                recognizedCommand =
                    ((buttons & 0xe0) > 0) + 0x6e + ((buttons & 0xc0) > 0) +
                    ((buttons & 0x80) > 0);
                return;
            }
            stage = 6;
        }
        if ((buttons & 0xf) == (facing == -1 ? 6 : 5) && stage == 4)
            stage = 5;
        if ((buttons & 0xf) == 4 && stage == 3)
            stage = 4;
        if ((buttons & 0xf) == 2 + (facing == -1 ? 0 : -1) && stage == 2)
            stage = 3;
        if ((buttons & 0xf) == (facing == -1 ? 6 : 5) && stage == 1)
            stage = 2;
        if ((buttons & 0xf) == 4 && stage == 0 && positionY == 0.0)
            stage = 1;
    }
    stage = 0;
    for (i = inputHistoryWriteIndex + 0x78; i < inputHistoryWriteIndex + 0xb4; ++i) {
        buttons = history[i - (i >= 180) * 180];
        if ((buttons & 0xf0) != 0 && stage == 3) {
            recognizedCommand =
                ((buttons & 0xe0) > 0) + 0x46 + ((buttons & 0xc0) > 0) +
                ((buttons & 0x80) > 0);
            return;
        }
        if ((buttons & 0xf) == (facing == -1 ? 6 : 5) && stage == 2) {
            if ((buttons & 0xf0) != 0) {
                recognizedCommand =
                    ((buttons & 0xe0) > 0) + 0x46 + ((buttons & 0xc0) > 0) +
                    ((buttons & 0x80) > 0);
                return;
            }
            stage = 3;
        }
        if ((buttons & 0xf) == 6 - (facing == -1 ? 1 : 0) && stage == 1)
            stage = 2;
        if ((buttons & 0xf) == 2 - (facing == -1 ? 1 : 0) && stage == 0 &&
            positionY == 0.0)
            stage = 1;
    }
    stage = 0;
    // Remaining high/low priority patterns are not yet reconstructed.
}
