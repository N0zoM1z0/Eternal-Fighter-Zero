// Mayu ordered command recognition over the circular input history.
#include "CharacterViews.h"

void Character05::Slot02()
{
    int i;
    unsigned char buttons, stage;
    recognizedCommand = 99;
    stage = '\0';
    i = inputHistoryWriteIndex + 0x5a;
    for (;  i < inputHistoryWriteIndex + 0xb4;  ++i) {
        buttons = history[i - (i >= 180) * 180];
        if (((buttons & 0x80) != 0) && (stage == '\x05')) {
            recognizedCommand = 0x62;
            return;
        }
        if (((buttons & 0xf) == (facing == -1 ? 6 : 5)) && (stage == '\x04')) {
            if ((buttons & 0x80) != 0) {
                recognizedCommand = 0x62;
                return;
            }
            stage = '\x05';
        }
        if (((buttons & 0xf) == (facing == -1 ? 10 : 9)) && (stage == '\x03')) {
            stage = '\x04';
        }
        if (((buttons & 0xf) == 2 + (facing == -1 ? 0 : -1)) && (stage == '\x02')) {
            stage = '\x03';
        }
        if (((buttons & 0xf) == (facing == -1 ? 6 : 5)) && (stage == '\x01')) {
            stage = '\x02';
        }
        if (((((buttons & 0xf) == 4) && (stage == '\0')) && (meter == 3000)) && (positionY == 0.0)) {
            stage = '\x01';
        }
    }
    stage = '\0';
    i = inputHistoryWriteIndex + 0x5a;
    for (;  i < inputHistoryWriteIndex + 0xb4;  ++i) {
        buttons = history[i - (i >= 180) * 180];
        if (((buttons & 0xf0) != 0) && (stage == '\x05')) {
            recognizedCommand = ((buttons & 0xe0) > 0) + 0xaa + ((buttons & 0xc0) > 0) + ((buttons & 0x80) > 0);
            return;
        }
        if (((buttons & 0xf) == 2 + (facing == -1 ? 0 : -1)) && (stage == '\x04')) {
            if ((buttons & 0xf0) != 0) {
                recognizedCommand = ((buttons & 0xe0) > 0) + 0xaa + ((buttons & 0xc0) > 0) + ((buttons & 0x80) > 0);
                return;
            }
            stage = '\x05';
        }
        if (((buttons & 0xf) == (facing == -1 ? 6 : 5)) && (stage == '\x03')) {
            stage = '\x04';
        }
        if (((buttons & 0xf) == 2 - (facing == -1 ? 1 : 0)) && (stage == '\x02')) {
            stage = '\x03';
        }
        if (((buttons & 0xf) == 6 - (facing == -1 ? 1 : 0)) && (stage == '\x01')) {
            stage = '\x02';
        }
        if (((((buttons & 0xf) == 4) && (stage == '\0')) && (meter >= 1000)) && (positionY == 0.0)) {
            stage = '\x01';
        }
    }
    stage = '\0';
    i = inputHistoryWriteIndex + 0x69;
    for (;  i < inputHistoryWriteIndex + 0xb4;  ++i) {
        buttons = history[i - (i >= 180) * 180];
        if (((buttons & 0x70) != 0) && (stage == '\x04')) {
            recognizedCommand = ((buttons & 0xe0) > 0) + 0x78 + ((buttons & 0xc0) > 0) + ((buttons & 0x80) > 0);
            return;
        }
        if (((buttons & 0xf) == (facing == -1 ? 6 : 5)) && (stage == '\x03')) {
            if ((buttons & 0x70) != 0) {
                recognizedCommand = ((buttons & 0xe0) > 0) + 0x78 + ((buttons & 0xc0) > 0) + ((buttons & 0x80) > 0);
                return;
            }
            stage = '\x04';
        }
        if (((buttons & 0xf) == 6 - (facing == -1 ? 1 : 0)) && (stage == '\x02')) {
            stage = '\x03';
        }
        if (((buttons & 0xf) == 2 - (facing == -1 ? 1 : 0)) && (stage == '\x01')) {
            stage = '\x02';
        }
        if (((((buttons & 0xf) == 2 + (facing == -1 ? 0 : -1)) && (stage == '\0')) && (meter >= 1000)) && (positionY == 0.0)) {
            stage = '\x01';
        }
    }
    stage = '\0';
    i = inputHistoryWriteIndex + 100;
    for (;  i < inputHistoryWriteIndex + 0xb4;  ++i) {
        buttons = history[i - (i >= 180) * 180];
        if (((buttons & 0xf0) != 0) && (stage == '\x06')) {
            recognizedCommand = ((buttons & 0xe0) > 0) + 0x6e + ((buttons & 0xc0) > 0) + ((buttons & 0x80) > 0);
            return;
        }
        if (((buttons & 0xf) == 2 - (facing == -1 ? 1 : 0)) && (stage == '\x05')) {
            if ((buttons & 0xf0) != 0) {
                recognizedCommand = ((buttons & 0xe0) > 0) + 0x6e + ((buttons & 0xc0) > 0) + ((buttons & 0x80) > 0);
                return;
            }
            stage = '\x06';
        }
        if (((buttons & 0xf) == 6 - (facing == -1 ? 1 : 0)) && (stage == '\x04')) {
            stage = '\x05';
        }
        if (((buttons & 0xf) == 4) && (stage == '\x03')) {
            stage = '\x04';
        }
        if (((buttons & 0xf) == 2 - (facing == -1 ? 1 : 0)) && (stage == '\x02')) {
            stage = '\x03';
        }
        if (((buttons & 0xf) == 6 - (facing == -1 ? 1 : 0)) && (stage == '\x01')) {
            stage = '\x02';
        }
        if (((buttons & 0xf) == 4) && (stage == '\0')) {
            stage = '\x01';
        }
    }
    stage = '\0';
    i = inputHistoryWriteIndex + 0x78;
    for (;  i < inputHistoryWriteIndex + 0xb4;  ++i) {
        buttons = history[i - (i >= 180) * 180];
        if (((buttons & 0xf0) != 0) && (stage == '\x03')) {
            recognizedCommand = ((buttons & 0xe0) > 0) + 0x46 + ((buttons & 0xc0) > 0) + ((buttons & 0x80) > 0);
            return;
        }
        if (((buttons & 0xf) == (facing == -1 ? 6 : 5)) && (stage == '\x02')) {
            if ((buttons & 0xf0) != 0) {
                recognizedCommand = ((buttons & 0xe0) > 0) + 0x46 + ((buttons & 0xc0) > 0) + ((buttons & 0x80) > 0);
                return;
            }
            stage = '\x03';
        }
        if (((buttons & 0xf) == 6 - (facing == -1 ? 1 : 0)) && (stage == '\x01')) {
            stage = '\x02';
        }
        if (((((buttons & 0xf) == 2 - (facing == -1 ? 1 : 0)) && (stage == '\0')) && (positionY == 0.0)) && (positionY == 0.0)) {
            stage = '\x01';
        }
    }
    stage = '\0';
    i = inputHistoryWriteIndex + 0x78;
    for (;  i < inputHistoryWriteIndex + 0xb4;  ++i) {
        buttons = history[i - (i >= 180) * 180];
        if (((buttons & 0xf0) != 0) && (stage == '\x03')) {
            recognizedCommand = ((buttons & 0xe0) > 0) + 0x14 + ((buttons & 0xc0) > 0) + ((buttons & 0x80) > 0);
            return;
        }
        if (((buttons & 0xf) == (facing == -1 ? 6 : 5)) && (stage == '\x02')) {
            if ((buttons & 0xf0) != 0) {
                recognizedCommand = ((buttons & 0xe0) > 0) + 0x14 + ((buttons & 0xc0) > 0) + ((buttons & 0x80) > 0);
                return;
            }
            stage = '\x03';
        }
        if (((buttons & 0xf) == 4) && (stage == '\x01')) {
            stage = '\x02';
        }
        if ((((buttons & 0xf) == 2 + (facing == -1 ? 0 : -1)) && (stage == '\0')) && (positionY == 0.0)) {
            stage = '\x01';
        }
    }
    stage = '\0';
    i = inputHistoryWriteIndex + 0x87;
    for (;  i < inputHistoryWriteIndex + 0xb4;  ++i) {
        buttons = history[i - (i >= 180) * 180];
        if (((buttons & 0xf0) != 0) && (stage == '\x03')) {
            recognizedCommand = ((buttons & 0xe0) > 0) + 10 + ((buttons & 0xc0) > 0) + ((buttons & 0x80) > 0);
            return;
        }
        if (((buttons & 0xf) == 2 + (facing == -1 ? 0 : -1)) && (stage == '\x02')) {
            if ((buttons & 0xf0) != 0) {
                recognizedCommand = ((buttons & 0xe0) > 0) + 10 + ((buttons & 0xc0) > 0) + ((buttons & 0x80) > 0);
                return;
            }
            stage = '\x03';
        }
        if (((buttons & 0xf) == (facing == -1 ? 6 : 5)) && (stage == '\x01')) {
            stage = '\x02';
        }
        if (((buttons & 0xf) == 4) && (stage == '\0')) {
            stage = '\x01';
        }
    }
    stage = '\0';
    i = inputHistoryWriteIndex + 0x87;
    for (;  i < inputHistoryWriteIndex + 0xb4;  ++i) {
        buttons = history[i - (i >= 180) * 180];
        if (((buttons & 0xf0) != 0) && (stage == '\x03')) {
            recognizedCommand = ((buttons & 0xe0) > 0) + 0x1e + ((buttons & 0xc0) > 0) + ((buttons & 0x80) > 0);
            return;
        }
        if (((buttons & 0xf) == 2 - (facing == -1 ? 1 : 0)) && (stage == '\x02')) {
            if ((buttons & 0xf0) != 0) {
                recognizedCommand = ((buttons & 0xe0) > 0) + 0x1e + ((buttons & 0xc0) > 0) + ((buttons & 0x80) > 0);
                return;
            }
            stage = '\x03';
        }
        if (((buttons & 0xf) == 6 - (facing == -1 ? 1 : 0)) && (stage == '\x01')) {
            stage = '\x02';
        }
        if (((buttons & 0xf) == 4) && (stage == '\0')) {
            stage = '\x01';
        }
    }
    stage = 0;
    i = inputHistoryWriteIndex + 0xaf;
    for (;  i < inputHistoryWriteIndex + 0xb4;  ++i) {
        buttons = history[i - (i >= 180) * 180];
        if (((buttons & 8) != 0) && (stage == 1)) {
            recognizedCommand = 6;
            return;
        }
        if (((buttons & 8) == 0) && (stage == 0)) {
            stage = 1;
        }
    }
    stage = '\0';
    i = inputHistoryWriteIndex + 0x5a;
    for (;  i < inputHistoryWriteIndex + 0xb4;  ++i) {
        buttons = history[i - (i >= 180) * 180];
        if (((buttons & 0x80) != 0) && (stage == '\x04')) {
            recognizedCommand = 0x35;
            return;
        }
        if (((buttons & 0xf) == 4) && (stage == '\x03')) {
            stage = '\x04';
        }
        if (((buttons & 0xf) == 0) && (stage == '\x02')) {
            stage = '\x03';
        }
        if (((buttons & 0xf) == 4) && (stage == '\x01')) {
            stage = '\x02';
        }
        if ((((buttons & 0xf) == 0) && (stage == '\0')) && (field0008 == 0x60)) {
            stage = '\x01';
        }
    }
    stage = '\0';
    i = inputHistoryWriteIndex + 0x5a;
    for (;  i < inputHistoryWriteIndex + 0xb4;  ++i) {
        buttons = history[i - (i >= 180) * 180];
        if (((buttons & 0x40) != 0) && (stage == '\x04')) {
            recognizedCommand = 0x34;
            return;
        }
        if (((buttons & 0xf) == 4) && (stage == '\x03')) {
            stage = '\x04';
        }
        if (((buttons & 0xf) == 0) && (stage == '\x02')) {
            stage = '\x03';
        }
        if (((buttons & 0xf) == 4) && (stage == '\x01')) {
            stage = '\x02';
        }
        if (((buttons & 0xf) == 0) && (stage == '\0')) {
            stage = '\x01';
        }
    }
    stage = '\0';
    i = inputHistoryWriteIndex + 0x87;
    for (;  i < inputHistoryWriteIndex + 0xb4;  ++i) {
        buttons = history[i - (i >= 180) * 180];
        if (((buttons & 0x20) != 0) && (stage == '\x04')) {
            recognizedCommand = 0x33;
            return;
        }
        if (((buttons & 0xf) == 4) && (stage == '\x03')) {
            stage = '\x04';
        }
        if (((buttons & 0xf) == 0) && (stage == '\x02')) {
            stage = '\x03';
        }
        if (((buttons & 0xf) == 4) && (stage == '\x01')) {
            stage = '\x02';
        }
        if (((buttons & 0xf) == 0) && (stage == '\0')) {
            stage = '\x01';
        }
    }
    stage = '\0';
    i = inputHistoryWriteIndex + 0x87;
    for (;  i < inputHistoryWriteIndex + 0xb4;  ++i) {
        buttons = history[i - (i >= 180) * 180];
        if (((buttons & 0x10) != 0) && (stage == '\x04')) {
            recognizedCommand = 0x32;
            return;
        }
        if (((buttons & 0xf) == 4) && (stage == '\x03')) {
            stage = '\x04';
        }
        if (((buttons & 0xf) == 0) && (stage == '\x02')) {
            stage = '\x03';
        }
        if (((buttons & 0xf) == 4) && (stage == '\x01')) {
            stage = '\x02';
        }
        if (((buttons & 0xf) == 0) && (stage == '\0')) {
            stage = '\x01';
        }
    }
    stage = '\0';
    i = inputHistoryWriteIndex + 0x87;
    for (;  i < inputHistoryWriteIndex + 0xb4;  ++i) {
        buttons = history[i - (i >= 180) * 180];
        if (((buttons & 0xf) == 1) && (stage == '\x03')) {
            recognizedCommand = 1;
            return;
        }
        if (((buttons & 0xf) == 0) && (stage == '\x02')) {
            stage = '\x03';
        }
        if (((buttons & 0xf) == 1) && (stage == '\x01')) {
            stage = '\x02';
        }
        if (((buttons & 0xf) == 0) && (stage == '\0')) {
            stage = '\x01';
        }
    }
    stage = '\0';
    i = inputHistoryWriteIndex + 0x87;
    for (;  i < inputHistoryWriteIndex + 0xb4;  ++i) {
        buttons = history[i - (i >= 180) * 180];
        if (((buttons & 0xf) == 2) && (stage == '\x03')) {
            recognizedCommand = 0;
            return;
        }
        if (((buttons & 0xf) == 0) && (stage == '\x02')) {
            stage = '\x03';
        }
        if (((buttons & 0xf) == 2) && (stage == '\x01')) {
            stage = '\x02';
        }
        if (((buttons & 0xf) == 0) && (stage == '\0')) {
            stage = '\x01';
        }
    }
    return;
}
