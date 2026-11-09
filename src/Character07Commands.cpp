// Misaki ordered command recognition over the circular input history.
#include "CharacterViews.h"

void Character07::Slot02()
{
    int i;
    unsigned char buttons, stage;
    field0262 = 99;
    stage = '\0';
    i = field0260 + 0x5a;
    for (;  i < field0260 + 0xb4;  ++i) {
        buttons = history[i - (i >= 180) * 180];
        if (((buttons & 0x80) != 0) && (stage == '\x06')) {
            field0262 = 0x5c;
            return;
        }
        if (((buttons & 0xf) == 4) && (stage == '\x05')) {
            stage = '\x06';
        }
        if (((buttons & 0xf) == 0) && (stage == '\x04')) {
            stage = '\x05';
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
        if ((((buttons & 0xf) == 0) && (stage == '\0')) && (meter == 3000)) {
            stage = '\x01';
        }
    }
    stage = '\0';
    i = field0260 + 0x2d;
    for (;  i < field0260 + 0xb4;  ++i) {
        buttons = history[i - (i >= 180) * 180];
        if (((buttons & 0xf0) != 0) && (stage == '\b')) {
            field0262 = ((buttons & 0xe0) > 0) + 0xa0 + ((buttons & 0xc0) > 0) + ((buttons & 0x80) > 0);
            return;
        }
        if (((buttons & 0xf) == 2 - (facing == -1 ? 1 : 0)) && (stage == '\a')) {
            if ((buttons & 0xf0) != 0) {
                field0262 = ((buttons & 0xe0) > 0) + 0xa0 + ((buttons & 0xc0) > 0) + ((buttons & 0x80) > 0);
                return;
            }
            stage = '\b';
        }
        if (((buttons & 0xf) == 6 - (facing == -1 ? 1 : 0)) && (stage == '\x06')) {
            stage = '\a';
        }
        if (((buttons & 0xf) == (facing == -1 ? 6 : 5)) && (stage == '\x05')) {
            stage = '\x06';
        }
        if (((buttons & 0xf) == 2 + (facing == -1 ? 0 : -1)) && (stage == '\x04')) {
            stage = '\x05';
        }
        if (((buttons & 0xf) == 2 - (facing == -1 ? 1 : 0)) && (stage == '\x03')) {
            stage = '\x04';
        }
        if (((buttons & 0xf) == 6 - (facing == -1 ? 1 : 0)) && (stage == '\x02')) {
            stage = '\x03';
        }
        if (((buttons & 0xf) == (facing == -1 ? 6 : 5)) && (stage == '\x01')) {
            stage = '\x02';
        }
        if ((((buttons & 0xf) == 2 + (facing == -1 ? 0 : -1)) && (stage == '\0')) && (positionY == 0.0)) {
            stage = '\x01';
        }
    }
    stage = '\0';
    i = field0260 + 0x5a;
    for (;  i < field0260 + 0xb4;  ++i) {
        buttons = history[i - (i >= 180) * 180];
        if (((buttons & 0xf0) != 0) && (stage == '\x06')) {
            field0262 = ((buttons & 0xe0) > 0) + 100 + ((buttons & 0xc0) > 0) + ((buttons & 0x80) > 0);
            return;
        }
        if (((buttons & 0xf) == 2 + (facing == -1 ? 0 : -1)) && (stage == '\x05')) {
            if ((buttons & 0xf0) != 0) {
                field0262 = ((buttons & 0xe0) > 0) + 100 + ((buttons & 0xc0) > 0) + ((buttons & 0x80) > 0);
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
        if ((((buttons & 0xf) == 4) && (stage == '\0')) && (meter >= 1000)) {
            stage = '\x01';
        }
    }
    stage = '\0';
    i = field0260 + 0x78;
    for (;  i < field0260 + 0xb4;  ++i) {
        buttons = history[i - (i >= 180) * 180];
        if (((buttons & 0xf0) != 0) && (stage == '\x03')) {
            field0262 = ((buttons & 0xe0) > 0) + 0x14 + ((buttons & 0xc0) > 0) + ((buttons & 0x80) > 0);
            return;
        }
        if (((buttons & 0xf) == (facing == -1 ? 6 : 5)) && (stage == '\x02')) {
            if ((buttons & 0xf0) != 0) {
                field0262 = ((buttons & 0xe0) > 0) + 0x14 + ((buttons & 0xc0) > 0) + ((buttons & 0x80) > 0);
                return;
            }
            stage = '\x03';
        }
        if (((buttons & 0xf) == 4) && (stage == '\x01')) {
            stage = '\x02';
        }
        if (((buttons & 0xf) == 2 + (facing == -1 ? 0 : -1)) && (stage == '\0')) {
            stage = '\x01';
        }
    }
    stage = '\0';
    i = field0260 + 0x87;
    for (;  i < field0260 + 0xb4;  ++i) {
        buttons = history[i - (i >= 180) * 180];
        if (((buttons & 0xf0) != 0) && (stage == '\x03')) {
            field0262 = ((buttons & 0xe0) > 0) + 10 + ((buttons & 0xc0) > 0) + ((buttons & 0x80) > 0);
            return;
        }
        if (((buttons & 0xf) == 2 + (facing == -1 ? 0 : -1)) && (stage == '\x02')) {
            if ((buttons & 0xf0) != 0) {
                field0262 = ((buttons & 0xe0) > 0) + 10 + ((buttons & 0xc0) > 0) + ((buttons & 0x80) > 0);
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
    i = field0260 + 0x87;
    for (;  i < field0260 + 0xb4;  ++i) {
        buttons = history[i - (i >= 180) * 180];
        if (((buttons & 0xf0) != 0) && (stage == '\x03')) {
            field0262 = ((buttons & 0xe0) > 0) + 0x1e + ((buttons & 0xc0) > 0) + ((buttons & 0x80) > 0);
            return;
        }
        if (((buttons & 0xf) == 2 - (facing == -1 ? 1 : 0)) && (stage == '\x02')) {
            if ((buttons & 0xf0) != 0) {
                field0262 = ((buttons & 0xe0) > 0) + 0x1e + ((buttons & 0xc0) > 0) + ((buttons & 0x80) > 0);
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
    i = field0260 + 0xaf;
    for (;  i < field0260 + 0xb4;  ++i) {
        buttons = history[i - (i >= 180) * 180];
        if (((buttons & 8) != 0) && (stage == 1)) {
            field0262 = 6;
            return;
        }
        if (((buttons & 8) == 0) && (stage == 0)) {
            stage = 1;
        }
    }
    stage = '\0';
    i = field0260 + 0x5a;
    for (;  i < field0260 + 0xb4;  ++i) {
        buttons = history[i - (i >= 180) * 180];
        if (((buttons & 0x80) != 0) && (stage == '\x04')) {
            field0262 = 0x35;
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
    i = field0260 + 0x5a;
    for (;  i < field0260 + 0xb4;  ++i) {
        buttons = history[i - (i >= 180) * 180];
        if (((buttons & 0x40) != 0) && (stage == '\x04')) {
            field0262 = 0x34;
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
    i = field0260 + 0x87;
    for (;  i < field0260 + 0xb4;  ++i) {
        buttons = history[i - (i >= 180) * 180];
        if (((buttons & 0x20) != 0) && (stage == '\x04')) {
            field0262 = 0x33;
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
    i = field0260 + 0x87;
    for (;  i < field0260 + 0xb4;  ++i) {
        buttons = history[i - (i >= 180) * 180];
        if (((buttons & 0x10) != 0) && (stage == '\x04')) {
            field0262 = 0x32;
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
    i = field0260 + 0x87;
    for (;  i < field0260 + 0xb4;  ++i) {
        buttons = history[i - (i >= 180) * 180];
        if (((buttons & 0xf) == 1) && (stage == '\x03')) {
            field0262 = 1;
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
    i = field0260 + 0x87;
    for (;  i < field0260 + 0xb4;  ++i) {
        buttons = history[i - (i >= 180) * 180];
        if (((buttons & 0xf) == 2) && (stage == '\x03')) {
            field0262 = 0;
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
