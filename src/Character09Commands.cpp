// Sayuri's complete ordered virtual Slot02 command interpreter.
 // Original owner 0x004493C0, 5995 bytes and its shared return.
#include "CharacterViews.h"

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
        if ((buttons & 0xf) == 2 + (facing == -1 ? 0 : -1) && stage == 0 &&
            positionY == 0.0)
            stage = 1;
    }
    stage = 0;
    // Higher-priority short motion: 0x0A series.
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

    // Aerial 0x28 family: quarter-circle stage with an airborne permission.
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
        if ((buttons & 0xf) == 2 - (facing == -1 ? 1 : 0) && stage == 0 &&
            positionY < 0.0)
            stage = 1;
    }
    stage = 0;
    // The tenth priority scan recognizes the ground 0x1E-series command.
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
