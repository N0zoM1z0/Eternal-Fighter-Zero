// Nayuki Character10::Slot02 original 4,827-byte input command owner.
// Current native-source workbench is a reviewed partial only.
#include "../../src/CharacterViews.h"

void Character10::Slot02()
{
    int i;
    unsigned char buttons, stage;
    recognizedCommand = 99;
    stage = 0;
    for (i = inputHistoryWriteIndex + 0x5a; i < inputHistoryWriteIndex + 0xb4; ++i) {
        buttons = history[i - (i >= 180) * 180];
        if ((buttons & 0xf0) != 0 && stage == 6) {
            recognizedCommand =
                ((buttons & 0xe0) > 0) + 0x6e + ((buttons & 0xc0) > 0) +
                ((buttons & 0x80) > 0);
            return;
        }
        if ((buttons & 0xf) == 2 - (facing == -1 ? 1 : 0) && stage == 5) {
            if ((buttons & 0xf0) != 0) {
                recognizedCommand =
                    ((buttons & 0xe0) > 0) + 0x6e + ((buttons & 0xc0) > 0) +
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
        if ((buttons & 0xf) == 4 && stage == 0 && meter >= 1000)
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
        if ((buttons & 0xf) == 2 + (facing == -1 ? 0 : -1) && stage == 5) {
            if ((buttons & 0xf0) != 0) {
                recognizedCommand =
                    ((buttons & 0xe0) > 0) + 0x64 + ((buttons & 0xc0) > 0) +
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
        if ((buttons & 0xf) == 4 && stage == 0 && meter >= 1000)
            stage = 1;
    }
    stage = 0;
    // Six-stage meter-3000 command with a dedicated 0x40-button prefix.
    for (i = inputHistoryWriteIndex + 0x5a; i < inputHistoryWriteIndex + 0xb4; ++i) {
        buttons = history[i - (i >= 180) * 180];
        if ((buttons & 0xf) == 2 + (facing == -1 ? 0 : -1) && stage == 6) {
            recognizedCommand = 0x61;
            return;
        }
        if ((buttons & 0xf) == (facing == -1 ? 6 : 5) && stage == 5)
            stage = 6;
        if ((buttons & 0xf) == 4 && stage == 4)
            stage = 5;
        if ((buttons & 0xf) == 2 + (facing == -1 ? 0 : -1) && stage == 3)
            stage = 4;
        if ((buttons & 0xf) == (facing == -1 ? 6 : 5) && stage == 2)
            stage = 3;
        if ((buttons & 0xf) == 4 && stage == 1)
            stage = 2;
        if ((buttons & 0x40) != 0 && stage == 0 && meter == 3000)
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
        if ((buttons & 0xf) == 2 - (facing == -1 ? 1 : 0) && stage == 0)
            stage = 1;
    }
    stage = 0;
    for (i = inputHistoryWriteIndex + 0x78; i < inputHistoryWriteIndex + 0xb4; ++i) {
        buttons = history[i - (i >= 180) * 180];
        if ((buttons & 0xf0) != 0 && stage == 3) {
            recognizedCommand =
                ((buttons & 0xe0) > 0) + 0x14 + ((buttons & 0xc0) > 0) +
                ((buttons & 0x80) > 0);
            return;
        }
        if ((buttons & 0xf) == (facing == -1 ? 6 : 5) && stage == 2) {
            if ((buttons & 0xf0) != 0) {
                recognizedCommand =
                    ((buttons & 0xe0) > 0) + 0x14 + ((buttons & 0xc0) > 0) +
                    ((buttons & 0x80) > 0);
                return;
            }
            stage = 3;
        }
        if ((buttons & 0xf) == 4 && stage == 1)
            stage = 2;
        if ((buttons & 0xf) == 2 + (facing == -1 ? 0 : -1) && stage == 0)
            stage = 1;
    }
    stage = 0;
    for (i = inputHistoryWriteIndex + 0x87; i < inputHistoryWriteIndex + 0xb4; ++i) {
        buttons = history[i - (i >= 180) * 180];
        if ((buttons & 0xf0) != 0 && stage == 3) {
            recognizedCommand =
                ((buttons & 0xe0) > 0) + 0x0a + ((buttons & 0xc0) > 0) +
                ((buttons & 0x80) > 0);
            return;
        }
        if ((buttons & 0xf) == 2 + (facing == -1 ? 0 : -1) && stage == 2) {
            if ((buttons & 0xf0) != 0) {
                recognizedCommand =
                    ((buttons & 0xe0) > 0) + 0x0a + ((buttons & 0xc0) > 0) +
                    ((buttons & 0x80) > 0);
                return;
            }
            stage = 3;
        }
        if ((buttons & 0xf) == (facing == -1 ? 6 : 5) && stage == 1)
            stage = 2;
        if ((buttons & 0xf) == 4 && stage == 0)
            stage = 1;
    }
    stage = 0;
    for (i = inputHistoryWriteIndex + 0x87; i < inputHistoryWriteIndex + 0xb4; ++i) {
        buttons = history[i - (i >= 180) * 180];
        if ((buttons & 0xf0) != 0 && stage == 3) {
            recognizedCommand =
                ((buttons & 0xe0) > 0) + 0x28 + ((buttons & 0xc0) > 0) +
                ((buttons & 0x80) > 0);
            return;
        }
        if ((buttons & 0xf) == 4 && stage == 2) {
            if ((buttons & 0xf0) != 0) {
                recognizedCommand =
                    ((buttons & 0xe0) > 0) + 0x28 + ((buttons & 0xc0) > 0) +
                    ((buttons & 0x80) > 0);
                return;
            }
            stage = 3;
        }
        if ((buttons & 0xf) == 6 - (facing == -1 ? 1 : 0) && stage == 1)
            stage = 2;
        if ((buttons & 0xf) == 2 - (facing == -1 ? 1 : 0) && stage == 0)
            stage = 1;
    }
    stage = 0;
    for (i = inputHistoryWriteIndex + 0x87; i < inputHistoryWriteIndex + 0xb4; ++i) {
        buttons = history[i - (i >= 180) * 180];
        if ((buttons & 0xf0) != 0 && stage == 3) {
            recognizedCommand =
                ((buttons & 0xe0) > 0) + 0x1e + ((buttons & 0xc0) > 0) +
                ((buttons & 0x80) > 0);
            return;
        }
        if ((buttons & 0xf) == 2 - (facing == -1 ? 1 : 0) && stage == 2) {
            if ((buttons & 0xf0) != 0) {
                recognizedCommand =
                    ((buttons & 0xe0) > 0) + 0x1e + ((buttons & 0xc0) > 0) +
                    ((buttons & 0x80) > 0);
                return;
            }
            stage = 3;
        }
        if ((buttons & 0xf) == 6 - (facing == -1 ? 1 : 0) && stage == 1)
            stage = 2;
        if ((buttons & 0xf) == 4 && stage == 0)
            stage = 1;
    }
    stage = 0;
    // Remaining Nayuki-specific command priorities are open.
}
