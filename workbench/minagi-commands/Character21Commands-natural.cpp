// Minagi Character21::Slot02 circular input-history command recognizer.
// Original 0x005AD550 (5314 bytes), provisional complete natural C++ candidate.
#include "../../src/CharacterViews.h"

void Character21::Slot02()
{
    unsigned char buttons;
    bool heldRelease;
    unsigned char stage;
    int index;

  recognizedCommand = 99;
  stage = '\0';
  for (index = inputHistoryWriteIndex + 0x5a; index < inputHistoryWriteIndex + 0xb4;
      index = index + 1) {
    buttons = history[index - (index >= 180) * 180];
    if (((buttons & 0x80) > 0) && (stage == '\x06')) {
      recognizedCommand = 0x5c;
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
  for (index = inputHistoryWriteIndex + 100; index < inputHistoryWriteIndex + 0xb4;
      index = index + 1) {
    buttons = history[index - (index >= 180) * 180];
    if (((buttons & 0xf0) != 0) && (stage == '\x05')) {
      recognizedCommand =
           ((buttons & 0xe0) > 0) + 0xaa + ((buttons & 0xc0) > 0) +
           ((buttons & 0x80) > 0);
      return;
    }
    if (((buttons & 0xf) == 2 - (facing != -1)) && (stage == '\x04')) {
      if ((buttons & 0xf0) != 0) {
        recognizedCommand =
             ((buttons & 0xe0) > 0) + 0xa0 + ((buttons & 0xc0) > 0) +
             ((buttons & 0x80) > 0);
        return;
      }
      stage = '\x05';
    }
    if (((buttons & 0xf) == 6 - (facing != -1)) && (stage == '\x03')) {
      stage = '\x04';
    }
    if (((buttons & 0xf) == 2 - (facing == -1)) && (stage == '\x02')) {
      stage = '\x03';
    }
    if (((buttons & 0xf) == 6 - (facing == -1)) && (stage == '\x01')) {
      stage = '\x02';
    }
    if (((buttons & 0xf) == 4) && (stage == '\0')) {
      stage = '\x01';
    }
  }
  stage = '\0';
  for (index = inputHistoryWriteIndex + 0x5a; index < inputHistoryWriteIndex + 0xb4;
      index = index + 1) {
    buttons = history[index - (index >= 180) * 180];
    if (((buttons & 0xf0) != 0) && (stage == '\x06')) {
      recognizedCommand =
           ((buttons & 0xe0) > 0) + 0x6e + ((buttons & 0xc0) > 0) +
           ((buttons & 0x80) > 0);
      return;
    }
    if (((buttons & 0xf) == 2 - (facing == -1)) && (stage == '\x05')) {
      if ((buttons & 0xf0) != 0) {
        recognizedCommand =
             ((buttons & 0xe0) > 0) + 0x6e + ((buttons & 0xc0) > 0) +
             ((buttons & 0x80) > 0);
        return;
      }
      stage = '\x06';
    }
    if (((buttons & 0xf) == 6 - (facing == -1)) && (stage == '\x04')) {
      stage = '\x05';
    }
    if (((buttons & 0xf) == 4) && (stage == '\x03')) {
      stage = '\x04';
    }
    if (((buttons & 0xf) == 2 - (facing == -1)) && (stage == '\x02')) {
      stage = '\x03';
    }
    if (((buttons & 0xf) == 6 - (facing == -1)) && (stage == '\x01')) {
      stage = '\x02';
    }
    if ((((buttons & 0xf) == 4) && (stage == '\0')) && (999 < meter)) {
      stage = '\x01';
    }
  }
  stage = '\0';
  for (index = inputHistoryWriteIndex + 0x5a; index < inputHistoryWriteIndex + 0xb4;
      index = index + 1) {
    buttons = history[index - (index >= 180) * 180];
    if (((buttons & 0xf0) != 0) && (stage == '\x06')) {
      recognizedCommand =
           ((buttons & 0xe0) > 0) + 100 + ((buttons & 0xc0) > 0) +
           ((buttons & 0x80) > 0);
      return;
    }
    if (((buttons & 0xf) == 2 - (facing != -1)) && (stage == '\x05')) {
      if ((buttons & 0xf0) != 0) {
        recognizedCommand =
             ((buttons & 0xe0) > 0) + 100 + ((buttons & 0xc0) > 0) +
             ((buttons & 0x80) > 0);
        return;
      }
      stage = '\x06';
    }
    if (((buttons & 0xf) == 6 - (facing != -1)) && (stage == '\x04')) {
      stage = '\x05';
    }
    if (((buttons & 0xf) == 4) && (stage == '\x03')) {
      stage = '\x04';
    }
    if (((buttons & 0xf) == 2 - (facing != -1)) && (stage == '\x02')) {
      stage = '\x03';
    }
    if (((buttons & 0xf) == 6 - (facing != -1)) && (stage == '\x01')) {
      stage = '\x02';
    }
    if ((((buttons & 0xf) == 4) && (stage == '\0')) && (999 < meter)) {
      stage = '\x01';
    }
  }
  // Native-priority ground 0x50 recognizer.
  stage = 0;
  for (index = inputHistoryWriteIndex + 0x6e; index < inputHistoryWriteIndex + 0xb4; ++index) {
    buttons = history[index - (index >= 180) * 180];
    if (((buttons & 0xf0) != 0) && stage == 4 && positionY == 0.0) {
      recognizedCommand = ((buttons & 0xe0) > 0) + 0x50 + ((buttons & 0xc0) > 0) + ((buttons & 0x80) > 0);
      return;
    }
    if (((buttons & 0xf) == 2 - (facing != -1)) && stage == 3) {
      if (((buttons & 0xf0) != 0) && positionY == 0.0) {
        recognizedCommand = ((buttons & 0xe0) > 0) + 0x50 + ((buttons & 0xc0) > 0) + ((buttons & 0x80) > 0);
        return;
      }
      stage = 4;
    }
    if (((buttons & 0xf) == 6 - (facing != -1)) && stage == 2) {
      stage = 3;
    }
    if (((buttons & 0xf) == 6 - (facing == -1)) && stage == 1) {
      stage = 2;
    }
    if (((buttons & 0xf) == 2 - (facing == -1)) && stage == 0) {
      stage = 1;
    }
  }
  // Native-priority 0x46 recognizer.
  stage = 0;
  for (index = inputHistoryWriteIndex + 0x87; index < inputHistoryWriteIndex + 0xb4; ++index) {
    buttons = history[index - (index >= 180) * 180];
    if (((buttons & 0xf0) != 0) && stage == 3) {
      recognizedCommand = ((buttons & 0xe0) > 0) + 0x46 + ((buttons & 0xc0) > 0) + ((buttons & 0x80) > 0);
      return;
    }
    if (((buttons & 0xf) == 6 - (facing == -1)) && stage == 2) {
      if (((buttons & 0xf0) != 0)) {
        recognizedCommand = ((buttons & 0xe0) > 0) + 0x46 + ((buttons & 0xc0) > 0) + ((buttons & 0x80) > 0);
        return;
      }
      stage = 3;
    }
    if (((buttons & 0xf) == 4) && stage == 1) {
      stage = 2;
    }
    if (((buttons & 0xf) == 2 - (facing == -1)) && stage == 0) {
      stage = 1;
    }
  }
  // Native-priority 0x14 recognizer.
  stage = 0;
  for (index = inputHistoryWriteIndex + 0x78; index < inputHistoryWriteIndex + 0xb4; ++index) {
    buttons = history[index - (index >= 180) * 180];
    if (((buttons & 0xf0) != 0) && stage == 3) {
      recognizedCommand = ((buttons & 0xe0) > 0) + 0x14 + ((buttons & 0xc0) > 0) + ((buttons & 0x80) > 0);
      return;
    }
    if (((buttons & 0xf) == 6 - (facing != -1)) && stage == 2) {
      if (((buttons & 0xf0) != 0)) {
        recognizedCommand = ((buttons & 0xe0) > 0) + 0x14 + ((buttons & 0xc0) > 0) + ((buttons & 0x80) > 0);
        return;
      }
      stage = 3;
    }
    if (((buttons & 0xf) == 4) && stage == 1) {
      stage = 2;
    }
    if (((buttons & 0xf) == 2 - (facing != -1)) && stage == 0) {
      stage = 1;
    }
  }
  // Native-priority 0x0a recognizer.
  stage = 0;
  for (index = inputHistoryWriteIndex + 0x87; index < inputHistoryWriteIndex + 0xb4; ++index) {
    buttons = history[index - (index >= 180) * 180];
    if (((buttons & 0xf0) != 0) && stage == 3) {
      recognizedCommand = ((buttons & 0xe0) > 0) + 10 + ((buttons & 0xc0) > 0) + ((buttons & 0x80) > 0);
      return;
    }
    if (((buttons & 0xf) == 2 - (facing != -1)) && stage == 2) {
      if (((buttons & 0xf0) != 0)) {
        recognizedCommand = ((buttons & 0xe0) > 0) + 10 + ((buttons & 0xc0) > 0) + ((buttons & 0x80) > 0);
        return;
      }
      stage = 3;
    }
    if (((buttons & 0xf) == 6 - (facing != -1)) && stage == 1) {
      stage = 2;
    }
    if (((buttons & 0xf) == 4) && stage == 0) {
      stage = 1;
    }
  }
  // Native-priority 0x1e recognizer.
  stage = 0;
  for (index = inputHistoryWriteIndex + 0x87; index < inputHistoryWriteIndex + 0xb4; ++index) {
    buttons = history[index - (index >= 180) * 180];
    if (((buttons & 0xf0) != 0) && stage == 3) {
      recognizedCommand = ((buttons & 0xe0) > 0) + 0x1e + ((buttons & 0xc0) > 0) + ((buttons & 0x80) > 0);
      return;
    }
    if (((buttons & 0xf) == 2 - (facing == -1)) && stage == 2) {
      if (((buttons & 0xf0) != 0)) {
        recognizedCommand = ((buttons & 0xe0) > 0) + 0x1e + ((buttons & 0xc0) > 0) + ((buttons & 0x80) > 0);
        return;
      }
      stage = 3;
    }
    if (((buttons & 0xf) == 6 - (facing == -1)) && stage == 1) {
      stage = 2;
    }
    if (((buttons & 0xf) == 4) && stage == 0) {
      stage = 1;
    }
  }
  // Distinguish D-button release from a continuously held D input.
  heldRelease = false;
  for (index = inputHistoryWriteIndex + 0xaf; index < inputHistoryWriteIndex + 0xb4; ++index) {
    buttons = history[index - (index >= 180) * 180];
    if (((buttons & 8) != 0) && heldRelease) {
      recognizedCommand = 6;
      return;
    }
    if (((buttons & 8) == 0) && !heldRelease) heldRelease = true;
  }
  // Native-priority button 0x80 history recognition.
  stage = 0;
  for (index = inputHistoryWriteIndex + 0x5a; index < inputHistoryWriteIndex + 0xb4; ++index) {
    buttons = history[index - (index >= 180) * 180];
    if (((buttons & 0x80) > 0) && stage == 4) {
      recognizedCommand = 0x35;
      return;
    }
    if (((buttons & 0xf) == 4) && stage == 3) stage = 4;
    if (((buttons & 0xf) == 0) && stage == 2) stage = 3;
    if (((buttons & 0xf) == 4) && stage == 1) stage = 2;
    if (((buttons & 0xf) == 0) && stage == 0 && (field0008 == 0x60)) stage = 1;
  }
  // Native-priority button 0x40 history recognition.
  stage = 0;
  for (index = inputHistoryWriteIndex + 0x5a; index < inputHistoryWriteIndex + 0xb4; ++index) {
    buttons = history[index - (index >= 180) * 180];
    if (((buttons & 0x40) != 0) && stage == 4) {
      recognizedCommand = 0x34;
      return;
    }
    if (((buttons & 0xf) == 4) && stage == 3) stage = 4;
    if (((buttons & 0xf) == 0) && stage == 2) stage = 3;
    if (((buttons & 0xf) == 4) && stage == 1) stage = 2;
    if (((buttons & 0xf) == 0) && stage == 0) stage = 1;
  }
  // Native-priority button 0x20 history recognition.
  stage = 0;
  for (index = inputHistoryWriteIndex + 0x87; index < inputHistoryWriteIndex + 0xb4; ++index) {
    buttons = history[index - (index >= 180) * 180];
    if (((buttons & 0x20) != 0) && stage == 4) {
      recognizedCommand = 0x33;
      return;
    }
    if (((buttons & 0xf) == 4) && stage == 3) stage = 4;
    if (((buttons & 0xf) == 0) && stage == 2) stage = 3;
    if (((buttons & 0xf) == 4) && stage == 1) stage = 2;
    if (((buttons & 0xf) == 0) && stage == 0) stage = 1;
  }
  // Native-priority button 0x10 history recognition.
  stage = 0;
  for (index = inputHistoryWriteIndex + 0x87; index < inputHistoryWriteIndex + 0xb4; ++index) {
    buttons = history[index - (index >= 180) * 180];
    if (((buttons & 0x10) != 0) && stage == 4) {
      recognizedCommand = 0x32;
      return;
    }
    if (((buttons & 0xf) == 4) && stage == 3) stage = 4;
    if (((buttons & 0xf) == 0) && stage == 2) stage = 3;
    if (((buttons & 0xf) == 4) && stage == 1) stage = 2;
    if (((buttons & 0xf) == 0) && stage == 0) stage = 1;
  }
  stage = 0;
  for (index = inputHistoryWriteIndex + 0x87; index < inputHistoryWriteIndex + 0xb4; ++index) {
    buttons = history[index - (index >= 180) * 180];
    if (((buttons & 0xf) == 1) && stage == 3) {
      recognizedCommand = 1;
      return;
    }
    if (((buttons & 0xf) == 0) && stage == 2) stage = 3;
    if (((buttons & 0xf) == 1) && stage == 1) stage = 2;
    if (((buttons & 0xf) == 0) && stage == 0) stage = 1;
  }
  stage = 0;
  for (index = inputHistoryWriteIndex + 0x87; index < inputHistoryWriteIndex + 0xb4; ++index) {
    buttons = history[index - (index >= 180) * 180];
    if (((buttons & 0xf) == 2) && stage == 3) {
      recognizedCommand = 0;
      return;
    }
    if (((buttons & 0xf) == 0) && stage == 2) stage = 3;
    if (((buttons & 0xf) == 2) && stage == 1) stage = 2;
    if (((buttons & 0xf) == 0) && stage == 0) stage = 1;
  }
  return;
}
