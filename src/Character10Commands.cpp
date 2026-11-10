// Complete natural C++ Nayuki Character10::Slot02 command interpreter.
// Original complete owner [0x004641C0, 0x0046549B): 4,827 bytes.
#include "CharacterViews.h"

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
    // Command 6 scans only the last five samples for a released-to-held
    // transition of the dedicated 0x08 input bit.
    for (i = inputHistoryWriteIndex + 0xaf; i < inputHistoryWriteIndex + 0xb4; ++i) {
        buttons = history[i - (i >= 180) * 180];
        if ((buttons & 8) != 0 && stage == 1) {
            recognizedCommand = 6;
            return;
        }
        if ((buttons & 8) == 0 && stage == 0)
            stage = 1;
    }
    stage = 0;
    // The final six priority scans use unmodified input nibbles: a
    // five-stage 0x35 command, three mirrored four-stage attacks,
    // then two alternating-direction movement commands.
    for (i = inputHistoryWriteIndex + 0x5a; i < inputHistoryWriteIndex + 0xb4; ++i) {
        buttons = history[i - (i >= 180) * 180];
        if ((buttons & 0x80) != 0 && stage == 4) {
            recognizedCommand = 0x35;
            return;
        }
        if ((buttons & 0xf) == 4 && stage == 3)
            stage = 4;
        if ((buttons & 0xf) == 0 && stage == 2)
            stage = 3;
        if ((buttons & 0xf) == 4 && stage == 1)
            stage = 2;
        if ((buttons & 0xf) == 0 && stage == 0 && field0008 == 0x60)
            stage = 1;
    }
    stage = 0;

    for (i = inputHistoryWriteIndex + 0x5a; i < inputHistoryWriteIndex + 0xb4; ++i) {
        buttons = history[i - (i >= 180) * 180];
        if ((buttons & 0x40) != 0 && stage == 4) {
            recognizedCommand = 0x34;
            return;
        }
        if ((buttons & 0xf) == 4 && stage == 3)
            stage = 4;
        if ((buttons & 0xf) == 0 && stage == 2)
            stage = 3;
        if ((buttons & 0xf) == 4 && stage == 1)
            stage = 2;
        if ((buttons & 0xf) == 0 && stage == 0)
            stage = 1;
    }
    stage = 0;

    for (i = inputHistoryWriteIndex + 0x87; i < inputHistoryWriteIndex + 0xb4; ++i) {
        buttons = history[i - (i >= 180) * 180];
        if ((buttons & 0x20) != 0 && stage == 4) {
            recognizedCommand = 0x33;
            return;
        }
        if ((buttons & 0xf) == 4 && stage == 3)
            stage = 4;
        if ((buttons & 0xf) == 0 && stage == 2)
            stage = 3;
        if ((buttons & 0xf) == 4 && stage == 1)
            stage = 2;
        if ((buttons & 0xf) == 0 && stage == 0)
            stage = 1;
    }
    stage = 0;

    for (i = inputHistoryWriteIndex + 0x87; i < inputHistoryWriteIndex + 0xb4; ++i) {
        buttons = history[i - (i >= 180) * 180];
        if ((buttons & 0x10) != 0 && stage == 4) {
            recognizedCommand = 0x32;
            return;
        }
        if ((buttons & 0xf) == 4 && stage == 3)
            stage = 4;
        if ((buttons & 0xf) == 0 && stage == 2)
            stage = 3;
        if ((buttons & 0xf) == 4 && stage == 1)
            stage = 2;
        if ((buttons & 0xf) == 0 && stage == 0)
            stage = 1;
    }
    stage = 0;

    for (i = inputHistoryWriteIndex + 0x87; i < inputHistoryWriteIndex + 0xb4; ++i) {
        buttons = history[i - (i >= 180) * 180];
        if ((buttons & 0xf) == 1 && stage == 3) {
            recognizedCommand = 1;
            return;
        }
        if ((buttons & 0xf) == 0 && stage == 2)
            stage = 3;
        if ((buttons & 0xf) == 1 && stage == 1)
            stage = 2;
        if ((buttons & 0xf) == 0 && stage == 0)
            stage = 1;
    }
    stage = 0;

    for (i = inputHistoryWriteIndex + 0x87; i < inputHistoryWriteIndex + 0xb4; ++i) {
        buttons = history[i - (i >= 180) * 180];
        if ((buttons & 0xf) == 2 && stage == 3) {
            recognizedCommand = 0;
            return;
        }
        if ((buttons & 0xf) == 0 && stage == 2)
            stage = 3;
        if ((buttons & 0xf) == 2 && stage == 1)
            stage = 2;
        if ((buttons & 0xf) == 0 && stage == 0)
            stage = 1;
    }
}
