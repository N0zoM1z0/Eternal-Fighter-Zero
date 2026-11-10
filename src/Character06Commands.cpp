// Nagamori's complete fifteen-stage prioritized input command recognizer.
// Original Character06::Slot02 at 0x004B1780 owns 4,917 code bytes.
#include "CharacterViews.h"

void Character06::Slot02()
{
    int i;
    unsigned char buttons, stage;
    recognizedCommand = 99;

    stage = 0;
    i = inputHistoryWriteIndex + 0x2d;
    for (; i < inputHistoryWriteIndex + 0xb4; ++i) {
        buttons = history[i - (i >= 180) * 180];
        if (((buttons & 0xe0) != 0) && stage == 5) {
            break;
        }
        if (((buttons & 0x10) != 0) && stage == 5) {
            recognizedCommand = 0x5b;
            return;
        }
        if (buttons == 0 && stage == 4) {
            stage = 5;
        }
        if ((buttons & 0xf) == 2 + (facing == -1 ? 0 : -1) && stage == 3) {
            stage = 4;
        }
        if (((buttons & 0xe0) != 0) && stage == 2) {
            break;
        }
        if (((buttons & 0x10) != 0) && stage == 2) {
            stage = 3;
        }
        if (((buttons & 0xd0) != 0) && stage == 1) {
            break;
        }
        if (((buttons & 0x20) != 0) && stage == 1) {
            stage = 2;
        }
        if ((buttons & 0xf) == 2 + (facing == -1 ? 0 : -1) &&
            stage == 0 && meter == 3000 && positionY == 0.0) {
            stage = 1;
        }
    }
    // Second priority: 100..179 ticks, a four-stage direction/button
    // motion. Finish either from state 4 or simultaneously with state 3.
    stage = 0;
    i = inputHistoryWriteIndex + 100;
    for (; i < inputHistoryWriteIndex + 0xb4; ++i) {
        buttons = history[i - (i >= 180) * 180];
        if (((buttons & 0xf0) != 0) && stage == 4) {
            recognizedCommand = ((buttons & 0xe0) > 0) + 0x78 +
                                ((buttons & 0xc0) > 0) + ((buttons & 0x80) > 0);
            return;
        }
        if (((buttons & 0xf) == 6 + (facing == -1 ? 0 : -1)) && stage == 3) {
            if ((buttons & 0xf0) != 0) {
                recognizedCommand = ((buttons & 0xe0) > 0) + 0x78 +
                                    ((buttons & 0xc0) > 0) + ((buttons & 0x80) > 0);
                return;
            }
            stage = 4;
        }
        if (((buttons & 0xf) == 6 - (facing == -1 ? 1 : 0)) && stage == 2) {
            stage = 3;
        }
        if (((buttons & 0xf) == 2 - (facing == -1 ? 1 : 0)) && stage == 1) {
            stage = 2;
        }
        if (((buttons & 0xf) == 2 + (facing == -1 ? 0 : -1)) && stage == 0) {
            stage = 1;
        }
    }
    // Nagamori third priority scan: 90-frame motion, meter >= 1000 required.
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
        if (((buttons & 0xf) == 4) && (stage == 0) && (meter >= 1000)) {
            stage = 1;
        }
    }
    // Fourth Nagamori scan: 1000-meter grounded base-100 motion.
    stage = '\0';
    i = inputHistoryWriteIndex + 0x5a;
    for (; i < inputHistoryWriteIndex + 0xb4; ++i) {
        buttons = history[i - (i >= 180) * 180];
        if (((buttons & 0xf0) != 0) && (stage == '\x06')) {
            recognizedCommand = ((buttons & 0xe0) > 0) + 100 + ((buttons & 0xc0) > 0) + ((buttons & 0x80) > 0);
            return;
        }
        if (((buttons & 0xf) == 2 + (facing == -1 ? 0 : -1)) && (stage == '\x05')) {
            if ((buttons & 0xf0) != 0) {
                recognizedCommand = ((buttons & 0xe0) > 0) + 100 + ((buttons & 0xc0) > 0) + ((buttons & 0x80) > 0);
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
        if ((((buttons & 0xf) == 4) && (stage == '\0')) && (meter >= 1000) && (positionY == 0.0)) {
            stage = '\x01';
        }
    }
    // Fifth Nagamori priority scan: 45-tick mirrored 2/6/4 input motion.
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
    // Sixth priority scan: 125–179-frame diagonal-neutral-finish motion.
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
    // Nagamori seventh scan: 4, then forward diagonal, then backward diagonal.
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
    // Nagamori eighth scan: the mirrored 4 -> 6 -> 2 motion.
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
    // Ninth priority scan: a five-tick release-to-button-8 pulse.
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
    // Tenth priority scan: neutral/4/neutral/4 then button 0x80.
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
        if (((buttons & 0xf) == 0) && (stage == 0) && field0008 == 0x60) {
            stage = 1;
        }
    }
    // Eleventh priority scan mirrors the tenth but finishes with 0x40.
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
    // Twelfth priority scan: neutral/4/neutral/4 finished by button 0x20.
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
    // Thirteenth priority scan: same neutral/4 prefix, button 0x10.
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
    // Fourteenth priority scan: neutral, direction 1, neutral, direction 1.
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
    // Fifteenth priority scan: neutral, direction 2, neutral, direction 2.
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
    }
}
