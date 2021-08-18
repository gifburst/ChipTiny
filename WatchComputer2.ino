#include <avr/pgmspace.h>

const byte displayResetPin = 5;
const byte displayDataPin = 2;
const byte displayClockPin = 1;
const byte displayModePin = 4;
// EEPROM DATA PIN SHOULD BE TIED TO SOURCE WITH A RESISTOR!!!
const byte eepromDataPin = 0;
const byte eepromClockPin = 3;
const byte key1Pin = 6;
const byte key2Pin = 7;
const byte key3Pin = 9;
const byte key4Pin = 10;
const byte arduinoClockPin = 8;
const byte arduinoOutputPin = 7;
// This pin should be the same as that of key 3!
const byte arduinoInputPin = 9;
const int signalDelay = 3;
const byte initialPromptTextCharacterCursorDelay = 20;
const byte INITIALIZE_DATA_LIST[] PROGMEM = {0x40, 0xA0, 0xC8, 0xA4, 0xA6, 0xA2, 0x2F, 0x27, 0x81, 0x10, 0xFA, 0x90, 0xAF};
const byte FONT_DATA_LIST[] PROGMEM = {

B00000000,
B00000000,
B00000000,
B00000000,
B00000000,

B01111110,
B00001001,
B00001001,
B00001001,
B01111110,

B01111111,
B01001001,
B01001001,
B01001001,
B00110110,

B00111110,
B01000001,
B01000001,
B01000001,
B00100010,

B01111111,
B01000001,
B01000001,
B01000001,
B00111110,

B01111111,
B01001001,
B01001001,
B01001001,
B01000001,

B01111111,
B00001001,
B00001001,
B00001001,
B00000001,

B00111110,
B01000001,
B01001001,
B01001001,
B00111001,

B01111111,
B00001000,
B00001000,
B00001000,
B01111111,

B01000001,
B01000001,
B01111111,
B01000001,
B01000001,

B00100000,
B01000001,
B01000001,
B01000001,
B00111111,

B01111111,
B00001000,
B00001000,
B00010100,
B01100011,

B01111111,
B01000000,
B01000000,
B01000000,
B01000000,

B01111111,
B00000010,
B00001100,
B00000010,
B01111111,

B01111111,
B00000010,
B00000100,
B00001000,
B01111111,

B00111110,
B01000001,
B01000001,
B01000001,
B00111110,

B01111111,
B00001001,
B00001001,
B00001001,
B00000110,

B00111110,
B01000001,
B01010001,
B01100001,
B01111110,

B01111111,
B00001001,
B00001001,
B00001001,
B01110110,

B01000110,
B01001001,
B01001001,
B01001001,
B00110001,

B00000001,
B00000001,
B01111111,
B00000001,
B00000001,

B00111111,
B01000000,
B01000000,
B01000000,
B00111111,

B00000111,
B00001000,
B00010000,
B00100000,
B01111111,

B01111111,
B00100000,
B00011000,
B00100000,
B01111111,

B01100011,
B00010100,
B00001000,
B00010100,
B01100011,

B00000011,
B00000100,
B01111000,
B00000100,
B00000011,

B01100001,
B01010001,
B01001001,
B01000101,
B01000011,

B00000000,
B00000000,
B01000000,
B00000000,
B00000000,

B00000001,
B00000001,
B01011001,
B00001001,
B00000110,

B00000000,
B00000000,
B01011111,
B00000000,
B00000000,

B00111110,
B01010001,
B01001001,
B01000101,
B00111110,

B01000100,
B01000010,
B01111111,
B01000000,
B01000000,

B01110001,
B01001001,
B01001001,
B01001001,
B01000110,

B01000001,
B01001001,
B01001001,
B01001001,
B00110110,

B00001111,
B00001000,
B00001000,
B00001000,
B01111111,

B01001111,
B01001001,
B01001001,
B01001001,
B00110001,

B00111110,
B01001001,
B01001001,
B01001001,
B00110001,

B00000001,
B00000001,
B01110001,
B00001001,
B00000111,

B00110110,
B01001001,
B01001001,
B01001001,
B00110110,

B01000110,
B01001001,
B01001001,
B01001001,
B00111110,

B00000000,
B00100000,
B01100000,
B00000000,
B00000000,

B00000000,
B00000001,
B00000011,
B00000000,
B00000000,

B00000001,
B00000011,
B00000000,
B00000001,
B00000011,

B00000000,
B00000000,
B00100100,
B00000000,
B00000000,

B01000000,
B01000000,
B01000000,
B01000000,
B01000000,

B00001000,
B00001000,
B00111110,
B00001000,
B00001000,

B00001000,
B00001000,
B00001000,
B00001000,
B00001000,

B00010101,
B00001110,
B00011111,
B00001110,
B00010101,

B01100000,
B00010000,
B00001000,
B00000100,
B00000011,

B00100100,
B00100100,
B00100100,
B00100100,
B00100100,

B00000000,
B00001000,
B00010100,
B00100010,
B01000001,

B01000001,
B00100010,
B00010100,
B00001000,
B00000000,

B00000000,
B01000001,
B01000001,
B00111110,
B00000000,

B00000000,
B00111110,
B01000001,
B01000001,
B00000000,

};

const byte BIG_FONT_DATA_LIST[] PROGMEM = {

B00001111, B11111100,
B00011111, B11111110,
B00111111, B00000111,
B00110011, B10000011,
B00110001, B11000011,
B00110000, B11100011,
B00110000, B01110011,
B00111000, B00111111,
B00011111, B11111110,
B00001111, B11111100,

B00110000, B00110000,
B00110000, B00111000,
B00110000, B00011100,
B00110000, B00001110,
B00111111, B11111111,
B00111111, B11111111,
B00110000, B00000000,
B00110000, B00000000,
B00110000, B00000000,
B00110000, B00000000,

B00111111, B00000011,
B00111111, B10000011,
B00110001, B11000011,
B00110000, B11000011,
B00110000, B11000011,
B00110000, B11000011,
B00110000, B11000011,
B00110000, B11100111,
B00110000, B01111110,
B00110000, B00111100,

B00110000, B00000011,
B00110000, B00000011,
B00110000, B11000011,
B00110000, B11000011,
B00110000, B11000011,
B00110000, B11000011,
B00110000, B11000011,
B00111001, B11100111,
B00011111, B11111110,
B00001111, B00111100,

B00000000, B11111111,
B00000000, B11111111,
B00000000, B11000000,
B00000000, B11000000,
B00000000, B11000000,
B00000000, B11000000,
B00000000, B11000000,
B00000000, B11000000,
B00111111, B11111111,
B00111111, B11111111,

B00110000, B11111111,
B00110000, B11111111,
B00110000, B11000011,
B00110000, B11000011,
B00110000, B11000011,
B00110000, B11000011,
B00110000, B11000011,
B00111001, B11000011,
B00011111, B10000011,
B00001111, B00000011,

B00001111, B11111100,
B00011111, B11111110,
B00111000, B11000111,
B00110000, B11000011,
B00110000, B11000011,
B00110000, B11000011,
B00110000, B11000011,
B00111001, B11000011,
B00011111, B10000011,
B00001111, B00000011,

B00000000, B00000011,
B00000000, B00000011,
B00000000, B00000011,
B00000000, B00000011,
B00111100, B00000011,
B00111111, B00000011,
B00000111, B11000011,
B00000001, B11110011,
B00000000, B01111111,
B00000000, B00011111,

B00001111, B00111100,
B00011111, B11111110,
B00111001, B11100111,
B00110000, B11000011,
B00110000, B11000011,
B00110000, B11000011,
B00110000, B11000011,
B00111001, B11100111,
B00011111, B11111110,
B00001111, B00111100,

B00110000, B00111100,
B00110000, B01111110,
B00110000, B11100111,
B00110000, B11000011,
B00110000, B11000011,
B00110000, B11000011,
B00110000, B11000011,
B00111000, B11000111,
B00011111, B11111110,
B00001111, B11111100
};

byte shouldReset;

byte readByteFromProgMem(const byte list[], unsigned int index) {
  return pgm_read_byte((unsigned int)list + index);
}

void resetDisplay()
{
  digitalWrite(displayResetPin, LOW);
  delayMicroseconds(signalDelay);
  digitalWrite(displayResetPin, HIGH);
  delayMicroseconds(signalDelay);
  byte index = 0;
  while (index < 13)
  {
    byte tempCommand = readByteFromProgMem(INITIALIZE_DATA_LIST, index);
    sendCommandToDisplay(tempCommand);
    index += 1;
  }
}

void sendSequenceToDisplay(byte sequence)
{
  byte mask = 128;
  byte count = 0;
  while (count < 8)
  {
    digitalWrite(displayClockPin, LOW);
    byte tempResult = sequence & mask;
    if (tempResult > 0)
    {
      digitalWrite(displayDataPin, HIGH);
    } else {
      digitalWrite(displayDataPin, LOW);
    }
    delayMicroseconds(signalDelay);
    digitalWrite(displayClockPin, HIGH);
    delayMicroseconds(signalDelay);
    mask /= 2;
    count += 1;
  }
}

void sendCommandToDisplay(byte command)
{
  digitalWrite(displayModePin, LOW);
  sendSequenceToDisplay(command);
}

void sendDataToDisplay(byte data)
{
  digitalWrite(displayModePin, HIGH);
  sendSequenceToDisplay(data);
}

void setCurrentDisplayPos(byte posX, byte posY)
{
    byte column = posX + 30;
    sendCommandToDisplay(0x10 | (column / 16));
    sendCommandToDisplay(0x00 | (column % 16));
    sendCommandToDisplay(0xB0 | posY);
}

void clearDisplay()
{
  byte posY = 0;
  while (posY < 8)
  {
    byte posX = 0;
    setCurrentDisplayPos(posX, posY);
    while (posX < 102)
    {
      sendDataToDisplay(0x00);
      posX += 1;
    }
    posY += 1;
  }
}

void writeCharacterToDisplay(byte which)
{
  unsigned int index = which * 5;
  byte count = 0;
  while (count < 5)
  {
    byte tempData = readByteFromProgMem(FONT_DATA_LIST, index);
    sendDataToDisplay(tempData);
    index += 1;
    count += 1;
  }
  sendDataToDisplay(0x00);
}

void writeCharactersToDisplay(byte *sequence)
{
  byte count = 0;
  while (count < 250)
  {
    byte which = *sequence;
    if (which == 255)
    {
      break;
    }
    writeCharacterToDisplay(which);
    sequence += 1;
    count += 1;
  }
}

void writeCharactersToDisplayAtPos(byte *sequence, byte startPosX, byte startPosY)
{
  byte posX = startPosX;
  byte posY = startPosY;
  setCurrentDisplayPos(posX, posY);
  byte count = 0;
  while (count < 250)
  {
    byte which = *sequence;
    if (which == 255)
    {
      break;
    }
    byte isNewlineCharacter = false;
    if (which == 254)
    {
      isNewlineCharacter = true;
    }
    if (!isNewlineCharacter)
    {
      writeCharacterToDisplay(which);
    }
    sequence += 1;
    posX += 6;
    if (posX > 95 || isNewlineCharacter)
    {
      posX = startPosX;
      posY += 1;
      setCurrentDisplayPos(posX, posY);
    }
    count += 1;
  }
}

byte promptTextText[34];
byte promptTextTextCursorIndex;
byte promptTextTextCursorPosX;
byte promptTextTextCursorPosY;
byte promptTextCharacterCursorIndex;
byte promptTextCharacterCursorPosX;
byte promptTextCharacterCursorPosY;

void drawPromptTextCharacterCursor()
{
  promptTextCharacterCursorPosX = (promptTextCharacterCursorIndex % 10) * 10;
  promptTextCharacterCursorPosY = (promptTextCharacterCursorIndex / 10) + 2;
  setCurrentDisplayPos(promptTextCharacterCursorPosX, promptTextCharacterCursorPosY);
  sendDataToDisplay(B00011100);
  sendDataToDisplay(B00011100);
}

void erasePromptTextCharacterCursor()
{
  setCurrentDisplayPos(promptTextCharacterCursorPosX, promptTextCharacterCursorPosY);
  sendDataToDisplay(0x00);
  sendDataToDisplay(0x00);
}

void drawPromptTextTextCursor()
{
  promptTextTextCursorPosX = (promptTextTextCursorIndex % 17) * 6;
  promptTextTextCursorPosY = promptTextTextCursorIndex / 17;
  setCurrentDisplayPos(promptTextTextCursorPosX, promptTextTextCursorPosY);
  writeCharacterToDisplay(44);
}

void promptText()
{
  byte posX = 3;
  byte posY = 2;
  byte which = 0;
  while (which < 54)
  {
    setCurrentDisplayPos(posX, posY);
    writeCharacterToDisplay(which);
    posX += 10;
    if (posX > 95)
    {
      posX = 3;
      posY += 1;
    }
    which += 1;
  }
  setCurrentDisplayPos(posX, posY);
  byte tempList[] = {4, 15, 14, 5, 255};
  writeCharactersToDisplay(tempList);
  promptTextCharacterCursorIndex = 0;
  drawPromptTextCharacterCursor();
  promptTextTextCursorIndex = 0;
  drawPromptTextTextCursor();
  byte moveDelay = 0;
  byte moveSpeed = initialPromptTextCharacterCursorDelay;
  byte moveDirection = 0;
  byte actionKeyIsPressed = 0;
  while (shouldReset == 0)
  {
    byte data = readDataFromKeys();
    if ((data & 0x06) == 0)
    {
      moveSpeed = initialPromptTextCharacterCursorDelay;
      moveDelay = 1;
      moveDirection = 0;
    }
    if ((data & 0x09) == 0)
    {
      actionKeyIsPressed = 0;
    }
    if ((data & 0x02) > 0)
    {
      moveDirection = 1;
    }
    if ((data & 0x04) > 0)
    {
      moveDirection = 2;
    }
    if (actionKeyIsPressed == 0)
    {
      if ((data & 0x01) > 0 && promptTextTextCursorIndex > 0)
      {
        setCurrentDisplayPos(promptTextTextCursorPosX, promptTextTextCursorPosY);
        writeCharacterToDisplay(0);
        promptTextTextCursorIndex -= 1;
        drawPromptTextTextCursor();
        actionKeyIsPressed = 1;
      }
      if ((data & 0x08) > 0)
      {
        // Done button.
        if (promptTextCharacterCursorIndex == 54)
        {
          promptTextText[promptTextTextCursorIndex] = 255;
          break;
        }
        if (promptTextTextCursorIndex < 33)
        {
          setCurrentDisplayPos(promptTextTextCursorPosX, promptTextTextCursorPosY);
          writeCharacterToDisplay(promptTextCharacterCursorIndex);
          promptTextText[promptTextTextCursorIndex] = promptTextCharacterCursorIndex;
          promptTextTextCursorIndex += 1;
          drawPromptTextTextCursor();
          actionKeyIsPressed = 1;
        }
      }
    }
    if (moveDirection > 0)
    {
      moveDelay -= 1;
      if (moveDelay > 200)
      {
        erasePromptTextCharacterCursor();
        if (moveDirection == 1)
        {
          promptTextCharacterCursorIndex -= 1;
          if (promptTextCharacterCursorIndex > 200)
          {
            promptTextCharacterCursorIndex = 54;
          }
        }
        if (moveDirection == 2)
        {
          promptTextCharacterCursorIndex += 1;
          if (promptTextCharacterCursorIndex > 54)
          {
            promptTextCharacterCursorIndex = 0;
          }
        }
        drawPromptTextCharacterCursor();
        moveDelay = moveSpeed;
        if (moveSpeed > initialPromptTextCharacterCursorDelay - 1)
        {
          moveSpeed = 10;
        } else {
          if (moveSpeed > 1)
          {
            moveSpeed -= 1;
          }
        }
      }
    }
    unsigned long tempStartTime = millis();
    while (1 == 1)
    {
      processExternalSignals();
      unsigned long tempEndTime = millis();
      if (tempEndTime - tempStartTime > 9)
      {
        break;
      }
    }
  }
  while (1 == 1)
  {
    byte data = readDataFromKeys();
    if (data == 0x00)
    {
      break;
    }
    processExternalSignals();
  }
}

byte promptSelectionIndex;

void drawSelectionCursor()
{
  setCurrentDisplayPos(0, promptSelectionIndex);
  writeCharacterToDisplay(46);
  writeCharacterToDisplay(51);
}

void eraseSelectionCursor()
{
  setCurrentDisplayPos(0, promptSelectionIndex);
  writeCharacterToDisplay(0);
  writeCharacterToDisplay(0);
}

void promptSelection(byte *sequence)
{
  byte posY = 0;
  setCurrentDisplayPos(12, posY);
  byte optionAmount = 1;
  byte count = 0;
  while (count < 250)
  {
    byte which = *sequence;
    if (which == 255)
    {
      break;
    }
    // Comma.
    if (which == 40)
    {
      posY += 1;
      setCurrentDisplayPos(12, posY);
      optionAmount += 1;
    } else {
      writeCharacterToDisplay(which);
    }
    sequence += 1;
    count += 1;
  }
  promptSelectionIndex = 0;
  drawSelectionCursor();
  byte actionKeyIsPressed = 0;
  while (shouldReset == 0)
  {
    byte data = readDataFromKeys();
    if ((data & 0x0F) == 0)
    {
      actionKeyIsPressed = 0;
    }
    if (actionKeyIsPressed == 0)
    {
      if ((data & 0x02) > 0)
      {
        eraseSelectionCursor();
        promptSelectionIndex -= 1;
        if (promptSelectionIndex > 200)
        {
          promptSelectionIndex = optionAmount - 1;
        }
        drawSelectionCursor();
        actionKeyIsPressed = 1;
      }
      if ((data & 0x04) > 0)
      {
        eraseSelectionCursor();
        promptSelectionIndex += 1;
        if (promptSelectionIndex > optionAmount - 1)
        {
          promptSelectionIndex = 0;
        }
        drawSelectionCursor();
        actionKeyIsPressed = 1;
      }
      if ((data & 0x01) > 0)
      {
        promptSelectionIndex = 255;
        break;
      }
      if ((data & 0x08) > 0)
      {
        break;
      }
    }
    processExternalSignals();
  }
  while (1 == 1)
  {
    byte data = readDataFromKeys();
    if (data == 0x00)
    {
      break;
    }
    processExternalSignals();
  }
}

byte promptKey()
{
  byte output;
  while (1 == 1)
  {
    output = readDataFromKeys();
    if (output > 0x00)
    {
      break;
    }
    processExternalSignals();
  }
  while (1 == 1)
  {
    byte data = readDataFromKeys();
    if (data == 0x00)
    {
      break;
    }
    processExternalSignals();
  }
  return output;
}

byte promptNumber()
{
  byte output = 0;
  byte posX = 3;
  byte posY = 2;
  byte which = 30;
  while (which < 40)
  {
    setCurrentDisplayPos(posX, posY);
    writeCharacterToDisplay(which);
    posX += 10;
    if (posX > 95)
    {
      posX = 3;
      posY += 1;
    }
    which += 1;
  }
  setCurrentDisplayPos(posX, posY);
  byte tempList[] = {4, 15, 14, 5, 255};
  writeCharactersToDisplay(tempList);
  promptTextCharacterCursorIndex = 0;
  drawPromptTextCharacterCursor();
  promptTextTextCursorIndex = 0;
  drawPromptTextTextCursor();
  byte moveDelay = 0;
  byte moveSpeed = initialPromptTextCharacterCursorDelay;
  byte moveDirection = 0;
  byte actionKeyIsPressed = 0;
  while (shouldReset == 0)
  {
    byte data = readDataFromKeys();
    if ((data & 0x06) == 0)
    {
      moveSpeed = initialPromptTextCharacterCursorDelay;
      moveDelay = 1;
      moveDirection = 0;
    }
    if ((data & 0x09) == 0)
    {
      actionKeyIsPressed = 0;
    }
    if ((data & 0x02) > 0)
    {
      moveDirection = 1;
    }
    if ((data & 0x04) > 0)
    {
      moveDirection = 2;
    }
    if (actionKeyIsPressed == 0)
    {
      if ((data & 0x01) > 0 && promptTextTextCursorIndex > 0)
      {
        setCurrentDisplayPos(promptTextTextCursorPosX, promptTextTextCursorPosY);
        writeCharacterToDisplay(0);
        promptTextTextCursorIndex -= 1;
        drawPromptTextTextCursor();
        actionKeyIsPressed = 1;
      }
      if ((data & 0x08) > 0)
      {
        // Done button.
        if (promptTextCharacterCursorIndex == 10)
        {
          promptTextText[promptTextTextCursorIndex] = 255;
          output = convertPartialNumberTextToByte(promptTextText);
          break;
        }
        if (promptTextTextCursorIndex < 3)
        {
          setCurrentDisplayPos(promptTextTextCursorPosX, promptTextTextCursorPosY);
          byte tempCharacter = promptTextCharacterCursorIndex + 30;
          writeCharacterToDisplay(tempCharacter);
          promptTextText[promptTextTextCursorIndex] = tempCharacter;
          promptTextTextCursorIndex += 1;
          drawPromptTextTextCursor();
          actionKeyIsPressed = 1;
        }
      }
    }
    if (moveDirection > 0)
    {
      moveDelay -= 1;
      if (moveDelay > 200)
      {
        erasePromptTextCharacterCursor();
        if (moveDirection == 1)
        {
          promptTextCharacterCursorIndex -= 1;
          if (promptTextCharacterCursorIndex > 200)
          {
            promptTextCharacterCursorIndex = 10;
          }
        }
        if (moveDirection == 2)
        {
          promptTextCharacterCursorIndex += 1;
          if (promptTextCharacterCursorIndex > 10)
          {
            promptTextCharacterCursorIndex = 0;
          }
        }
        drawPromptTextCharacterCursor();
        moveDelay = moveSpeed;
        if (moveSpeed > initialPromptTextCharacterCursorDelay - 1)
        {
          moveSpeed = 10;
        } else {
          if (moveSpeed > 1)
          {
            moveSpeed -= 1;
          }
        }
      }
    }
    unsigned long tempStartTime = millis();
    while (1 == 1)
    {
      processExternalSignals();
      unsigned long tempEndTime = millis();
      if (tempEndTime - tempStartTime > 9)
      {
        break;
      }
    }
  }
  while (1 == 1)
  {
    byte data = readDataFromKeys();
    if (data == 0x00)
    {
      break;
    }
    processExternalSignals();
  }
  return output;
}

void writeBigCharacterToDisplay(byte which, byte posX, byte posY)
{
  which -= 30;
  setCurrentDisplayPos(posX, posY);
  unsigned int index = which * 20 + 1;
  byte count = 0;
  while (count < 10)
  {
    byte tempData = readByteFromProgMem(BIG_FONT_DATA_LIST, index);
    sendDataToDisplay(tempData);
    index += 2;
    count += 1;
  }
  setCurrentDisplayPos(posX, posY + 1);
  index = which * 20;
  count = 0;
  while (count < 10)
  {
    byte tempData = readByteFromProgMem(BIG_FONT_DATA_LIST, index);
    sendDataToDisplay(tempData);
    index += 2;
    count += 1;
  }
}

void writeBigCharactersToDisplay(byte *sequence, byte posX, byte posY)
{
  byte count = 0;
  while (count < 250)
  {
    byte which = *sequence;
    if (which == 255)
    {
      break;
    }
    writeBigCharacterToDisplay(which, posX, posY);
    sequence += 1;
    posX += 12;
    count += 1;
  }
}

void sendStartConditionToEeprom()
{
  digitalWrite(eepromDataPin, HIGH);
  digitalWrite(eepromClockPin, HIGH);
  digitalWrite(eepromDataPin, LOW);
  digitalWrite(eepromClockPin, LOW);
}

void sendStopConditionToEeprom()
{
  digitalWrite(eepromDataPin, LOW);
  digitalWrite(eepromClockPin, HIGH);
  digitalWrite(eepromDataPin, HIGH);
  digitalWrite(eepromClockPin, LOW);
}

void resetEeprom()
{
  sendStartConditionToEeprom();
  digitalWrite(eepromDataPin, HIGH);
  byte count = 0;
  while (count < 9)
  {
    digitalWrite(eepromClockPin, HIGH);
    digitalWrite(eepromClockPin, LOW);
    count += 1;
  }
  sendStartConditionToEeprom();
  sendStopConditionToEeprom();
}

void sendSequenceToEeprom(byte sequence)
{
  byte mask = 128;
  byte count = 0;
  while (count < 8)
  {
    byte tempResult = sequence & mask;
    if (tempResult > 0)
    {
      digitalWrite(eepromDataPin, HIGH);
    } else {
      digitalWrite(eepromDataPin, LOW);
    }
    digitalWrite(eepromClockPin, HIGH);
    digitalWrite(eepromClockPin, LOW);
    mask /= 2;
    count += 1;
  }
  pinMode(eepromDataPin, INPUT);
  digitalWrite(eepromClockPin, HIGH);
  digitalWrite(eepromClockPin, LOW);
  pinMode(eepromDataPin, OUTPUT);
}

byte receiveSequenceFromEeprom()
{
  pinMode(eepromDataPin, INPUT);
  byte output = 0;
  byte mask = 128;
  byte count = 0;
  while (count < 8)
  {
    if (digitalRead(eepromDataPin) == HIGH)
    {
      output = output | mask;
    }
    digitalWrite(eepromClockPin, HIGH);
    digitalWrite(eepromClockPin, LOW);
    mask /= 2;
    count += 1;
  }
  return output;
}

void sendAck()
{
  pinMode(eepromDataPin, OUTPUT);
  digitalWrite(eepromDataPin, LOW);
  digitalWrite(eepromClockPin, HIGH);
  digitalWrite(eepromClockPin, LOW);
}

void sendNoAck()
{
  digitalWrite(eepromClockPin, HIGH);
  digitalWrite(eepromClockPin, LOW);
  pinMode(eepromDataPin, OUTPUT);
}

void writeDataToEeprom(byte data, unsigned int address)
{
  sendStartConditionToEeprom();
  sendSequenceToEeprom(0xA0);
  sendSequenceToEeprom(address / 256);
  sendSequenceToEeprom(address % 256);
  sendSequenceToEeprom(data);
  sendStopConditionToEeprom();
  delay(10);
}

byte readDataFromEeprom(unsigned int address)
{
  byte output;
  sendStartConditionToEeprom();
  sendSequenceToEeprom(0xA0);
  sendSequenceToEeprom(address / 256);
  sendSequenceToEeprom(address % 256);
  sendStartConditionToEeprom();
  sendSequenceToEeprom(0xA1);
  output = receiveSequenceFromEeprom();
  sendNoAck();
  sendStopConditionToEeprom();
  return output;
}

// Returns the number of bytes read and writes
// the data to the pointer.
byte readCommandFromEeprom(unsigned int address, byte *destination)
{
  sendStartConditionToEeprom();
  sendSequenceToEeprom(0xA0);
  sendSequenceToEeprom(address / 256);
  sendSequenceToEeprom(address % 256);
  sendStartConditionToEeprom();
  sendSequenceToEeprom(0xA1);
  byte count = 0;
  while (count < 50)
  {
    byte data = receiveSequenceFromEeprom();
    if (count > 2 | (data != 0 && data != 254))
    {
      *destination = data;
      destination += 1;
      count += 1;
      if (data == 27)
      {
        break;
      }
    }
    sendAck();
  }
  sendNoAck();
  sendStopConditionToEeprom();
  return count;
}

byte readDataFromKeys()
{
  byte output = 0x00;
  if (digitalRead(key1Pin) == HIGH)
  {
    output = output | 0x01;
  }
  if (digitalRead(key2Pin) == HIGH)
  {
    output = output | 0x02;
  }
  if (digitalRead(key3Pin) == HIGH)
  {
    output = output | 0x04;
  }
  if (digitalRead(key4Pin) == HIGH)
  {
    output = output | 0x08;
  }
  return output;
}

byte variableList[90];

byte convertVariableNameToVariableAddress(byte *sequence)
{
  byte character1 = *sequence;
  sequence += 1;
  byte character2 = *sequence;
  return (character1 - 1) * 26 + (character2 - 1);
}

byte convertNumberTextToByte(byte *sequence)
{
  byte character1 = *sequence;
  sequence += 1;
  byte character2 = *sequence;
  sequence += 1;
  byte character3 = *sequence;
  return (character1 - 30) * 100 + (character2 - 30) * 10 + (character3 - 30);
}

byte convertPartialNumberTextToByte(byte *sequence)
{
  byte *sequenceStart;
  sequenceStart = sequence;
  byte tempCount = 0;
  while (*sequence != 255 && tempCount < 250)
  {
    sequence += 1;
    tempCount += 1;
  }
  byte output = 0;
  sequence = sequenceStart;
  if (tempCount == 3)
  {
    output += (*sequence - 30) * 100;
    sequence += 1;
    tempCount -= 1;
  }
  if (tempCount == 2)
  {
    output += (*sequence - 30) * 10;
    sequence += 1;
    tempCount -= 1;
  }
  if (tempCount == 1)
  {
    output += *sequence - 30;
  }
  return output;
}

// Conditional branch types:
// 0 is bottom branch.
// 1 is active if branch.
// 2 is active while branch.
// 3 is ignored branch.
byte conditionalBranchTypeStack[15];
unsigned int conditionalBranchAddressStack[15];
byte conditionalBranchStackIndex;

unsigned int currentCommandAddress;

byte timeCalibrationFactor = 100;

void interpretCurrentCommand()
{
  byte tempCommand[35];
  byte argAddresses[3];
  byte argValues[32];
  byte tempLength = readCommandFromEeprom(currentCommandAddress, tempCommand);
  unsigned int lastCommandAddress = currentCommandAddress;
  currentCommandAddress += tempLength;
  byte commandCharacter1 = tempCommand[0];
  byte commandCharacter2 = tempCommand[1];
  byte tempBranchType = conditionalBranchTypeStack[conditionalBranchStackIndex];
  if (tempBranchType == 3)
  {
    // FI.
    if (commandCharacter1 == 6 && commandCharacter2 == 9)
    {
      conditionalBranchStackIndex += 1;
      conditionalBranchTypeStack[conditionalBranchStackIndex] = 3;
    }
    // FW.
    if (commandCharacter1 == 6 && commandCharacter2 == 23)
    {
      conditionalBranchStackIndex += 1;
      conditionalBranchTypeStack[conditionalBranchStackIndex] = 3;
    }
    // FE.
    if (commandCharacter1 == 6 && commandCharacter2 == 5)
    {
      conditionalBranchStackIndex -= 1;
    }
  } else {
    byte argIndex = 0;
    byte characterIndex = 2;
    while (characterIndex < tempLength - 1)
    {
      byte tempData = tempCommand[characterIndex];
      if (tempData == 42)
      {
        characterIndex += 1;
        while (1 == 1)
        {
          tempData = tempCommand[characterIndex];
          characterIndex += 1;
          if (tempData == 42)
          {
            break;
          }
          argValues[argIndex] = tempData;
          argIndex += 1;
        }
      } else {
        if (tempData < 27)
        {
          byte tempAddress = convertVariableNameToVariableAddress(tempCommand + characterIndex);
          argAddresses[argIndex] = tempAddress;
          argValues[argIndex] = variableList[tempAddress];
          characterIndex += 2;
        } else {
          byte tempValue = convertNumberTextToByte(tempCommand + characterIndex);
          argValues[argIndex] = tempValue;
          characterIndex += 3;
        }
        argIndex += 1;
      }
    }
    byte argAmount = argIndex;
    // NW.
    if (commandCharacter1 == 14 && commandCharacter2 == 23)
    {
      variableList[argAddresses[0]] = argValues[1];
    }
    // NS.
    if (commandCharacter1 == 14 && commandCharacter2 == 19)
    {
      byte tempAddress = argAddresses[0];
      byte tempValue = argValues[1];
      variableList[tempAddress] = tempValue / 100 + 30;
      variableList[tempAddress + 1] = (tempValue % 100) / 10 + 30;
      variableList[tempAddress + 2] = tempValue % 10 + 30;
      variableList[tempAddress + 3] = 255;
    }
    // AL.
    if (commandCharacter1 == 1 && commandCharacter2 == 12)
    {
      byte tempAddress = argAddresses[0];
      byte index = 1;
      while (index < argAmount)
      {
        variableList[tempAddress] = argValues[index];
        tempAddress += 1;
        index += 1;
      }
    }
    // AR.
    if (commandCharacter1 == 1 && commandCharacter2 == 18)
    {
      byte tempAddress = argAddresses[1] + argValues[2];
      variableList[argAddresses[0]] = variableList[tempAddress];
    }
    // AW.
    if (commandCharacter1 == 1 && commandCharacter2 == 23)
    {
      byte tempAddress = argAddresses[0] + argValues[1];
      variableList[tempAddress] = argValues[2];
    }
    // AD.
    if (commandCharacter1 == 1 && commandCharacter2 == 4)
    {
      byte tempIndex = argValues[1];
      byte tempDestinationAddress = argAddresses[0] + tempIndex;
      byte tempSourceAddress = argAddresses[2];
      byte tempCount = 0;
      byte tempAmount = argValues[3];
      while (tempCount < tempAmount)
      {
        byte tempValue = variableList[tempSourceAddress];
        variableList[tempDestinationAddress] = tempValue;
        tempDestinationAddress += 1;
        tempSourceAddress += 1;
        tempCount += 1;
      }
    }
    // AE.
    if (commandCharacter1 == 1 && commandCharacter2 == 5)
    {
      byte tempSourceAddress1 = argAddresses[0];
      unsigned int tempEepromAddress = (variableList[tempSourceAddress1]) * 256 + (variableList[tempSourceAddress1 + 1]);
      byte tempSourceAddress2 = argAddresses[1];
      byte tempCount = 0;
      byte tempAmount = argValues[2];
      while (tempCount < tempAmount)
      {
        byte tempValue = variableList[tempSourceAddress2];
        writeDataToEeprom(tempValue, tempEepromAddress);
        tempEepromAddress += 1;
        tempSourceAddress2 += 1;
        tempCount += 1;
      }
    }
    // SL.
    if (commandCharacter1 == 19 && commandCharacter2 == 12)
    {
      byte tempAddress = argAddresses[1];
      byte tempCount = 0;
      while (variableList[tempAddress] != 255 && tempCount < 250)
      {
        tempAddress += 1;
        tempCount += 1;
      }
      variableList[argAddresses[0]] = tempCount;
    }
    // SD.
    if (commandCharacter1 == 19 && commandCharacter2 == 4)
    {
      byte tempIndex = argValues[1];
      byte tempSourceAddress = argAddresses[2] ;
      byte tempDestinationAddress = argAddresses[0] + tempIndex;
      while (tempIndex < 230)
      {
        byte tempData = variableList[tempSourceAddress];
        variableList[tempDestinationAddress] = tempData;
        if (tempData == 255)
        {
          return;
        }
        tempIndex += 1;
        tempSourceAddress += 1;
        tempDestinationAddress += 1;
      }
      variableList[tempDestinationAddress] = 255;
    }
    // SS.
    if (commandCharacter1 == 19 && commandCharacter2 == 19)
    {
      byte tempIndex = argValues[2];
      byte tempSourceAddress = argAddresses[1] + tempIndex;
      byte tempDestinationAddress = argAddresses[0];
      byte tempEndIndex = argValues[3];
      while (tempIndex < tempEndIndex)
      {
        variableList[tempDestinationAddress] = variableList[tempSourceAddress];
        tempIndex += 1;
        tempSourceAddress += 1;
        tempDestinationAddress += 1;
      }
      variableList[tempDestinationAddress] = 255;
    }
    // SC.
    if (commandCharacter1 == 19 && commandCharacter2 == 3)
    {
      byte tempDestinationAddress = argAddresses[0];
      byte tempCount = 0;
      while (variableList[tempDestinationAddress] != 255 && tempCount < 250)
      {
        tempDestinationAddress += 1;
        tempCount += 1;
      }
      byte tempSourceAddress = argAddresses[1];
      tempCount = 0;
      while (tempCount < 250)
      {
        byte tempData = variableList[tempSourceAddress];
        variableList[tempDestinationAddress] = tempData;
        if (tempData == 255)
        {
          break;
        }
        tempSourceAddress += 1;
        tempDestinationAddress += 1;
        tempCount += 1;
      }
    }
    // SN.
    if (commandCharacter1 == 19 && commandCharacter2 == 14)
    {
      byte tempAddress = argAddresses[1];
      byte tempResult = convertPartialNumberTextToByte(variableList + tempAddress);
      variableList[argAddresses[0]] = tempResult;
    }
    // SE.
    if (commandCharacter1 == 19 && commandCharacter2 == 5)
    {
      byte tempSourceAddress1 = argAddresses[0];
      unsigned int tempEepromAddress = (variableList[tempSourceAddress1]) * 256 + (variableList[tempSourceAddress1 + 1]);
      byte tempSourceAddress2 = argAddresses[1];
      byte tempCount = 0;
      while (tempCount < 230)
      {
        byte tempValue = variableList[tempSourceAddress2];
        writeDataToEeprom(tempValue, tempEepromAddress);
        if (tempValue == 255)
        {
          return;
        }
        tempEepromAddress += 1;
        tempSourceAddress2 += 1;
        tempCount += 1;
      }
    }
    
    // MA.
    if (commandCharacter1 == 13 && commandCharacter2 == 1)
    {
      variableList[argAddresses[0]] = argValues[1] + argValues[2];
    }
    // MS.
    if (commandCharacter1 == 13 && commandCharacter2 == 19)
    {
      variableList[argAddresses[0]] = argValues[1] - argValues[2];
    }
    // MM.
    if (commandCharacter1 == 13 && commandCharacter2 == 13)
    {
      variableList[argAddresses[0]] = argValues[1] * argValues[2];
    }
    // MD.
    if (commandCharacter1 == 13 && commandCharacter2 == 4)
    {
      variableList[argAddresses[0]] = argValues[1] / argValues[2];
    }
    // MR.
    if (commandCharacter1 == 13 && commandCharacter2 == 18)
    {
      variableList[argAddresses[0]] = argValues[1] % argValues[2];
    }
    // CE.
    if (commandCharacter1 == 3 && commandCharacter2 == 5)
    {
      variableList[argAddresses[0]] = (argValues[1] == argValues[2]);
    }
    // CG.
    if (commandCharacter1 == 3 && commandCharacter2 == 7)
    {
      variableList[argAddresses[0]] = (argValues[1] > argValues[2]);
    }
    // BN.
    if (commandCharacter1 == 2 && commandCharacter2 == 14)
    {
      variableList[argAddresses[0]] = ~argValues[1];
    }
    // BO.
    if (commandCharacter1 == 2 && commandCharacter2 == 15)
    {
      variableList[argAddresses[0]] = (argValues[1] | argValues[2]);
    }
    // BA.
    if (commandCharacter1 == 2 && commandCharacter2 == 1)
    {
      variableList[argAddresses[0]] = (argValues[1] & argValues[2]);
    }
    // BI.
    if (commandCharacter1 == 2 && commandCharacter2 == 9)
    {
      variableList[argAddresses[0]] = !argValues[1];
    }
    // FR.
    if (commandCharacter1 == 6 && commandCharacter2 == 18)
    {
      byte tempAddress = argAddresses[0];
      variableList[tempAddress] = currentCommandAddress / 256;
      variableList[tempAddress + 1] = currentCommandAddress % 256;
    }
    // FJ.
    if (commandCharacter1 == 6 && commandCharacter2 == 10)
    {
      byte tempAddress = argAddresses[0];
      currentCommandAddress = variableList[tempAddress] * 256 + variableList[tempAddress + 1];
    }
    // FI.
    if (commandCharacter1 == 6 && commandCharacter2 == 9)
    {
      conditionalBranchStackIndex += 1;
      if (argValues[0] > 0)
      {
        conditionalBranchTypeStack[conditionalBranchStackIndex] = 1;
      } else {
        conditionalBranchTypeStack[conditionalBranchStackIndex] = 3;
      }
    }
    // FW.
    if (commandCharacter1 == 6 && commandCharacter2 == 23)
    {
      conditionalBranchStackIndex += 1;
      if (argValues[0] > 0)
      {
        conditionalBranchTypeStack[conditionalBranchStackIndex] = 2;
        conditionalBranchAddressStack[conditionalBranchStackIndex] = lastCommandAddress;
      } else {
        conditionalBranchTypeStack[conditionalBranchStackIndex] = 3;
      }
    }
    // FE.
    if (commandCharacter1 == 6 && commandCharacter2 == 5)
    {
      byte tempType = conditionalBranchTypeStack[conditionalBranchStackIndex];
      if (tempType == 2)
      {
        currentCommandAddress = conditionalBranchAddressStack[conditionalBranchStackIndex];
      }
      conditionalBranchStackIndex -= 1;
    }
    // FB.
    if (commandCharacter1 == 6 && commandCharacter2 == 2)
    {
      conditionalBranchStackIndex = 0;
      conditionalBranchTypeStack[0] = 0;
    }
    // ER.
    if (commandCharacter1 == 5 && commandCharacter2 == 18)
    {
      byte tempSourceAddress = argAddresses[1];
      unsigned int tempEepromAddress = (unsigned int)(variableList[tempSourceAddress]) * 256 + (unsigned int)(variableList[tempSourceAddress + 1]);
      variableList[argAddresses[0]] = readDataFromEeprom(tempEepromAddress);
    }
    // EA.
    if (commandCharacter1 == 5 && commandCharacter2 == 1)
    {
      byte tempSourceAddress = argAddresses[1];
      unsigned int tempEepromAddress = (variableList[tempSourceAddress]) * 256 + (variableList[tempSourceAddress + 1]);
      byte tempDestinationAddress = argAddresses[0];
      byte tempCount = 0;
      byte tempAmount = argValues[2];
      while (tempCount < tempAmount)
      {
        byte tempData = readDataFromEeprom(tempEepromAddress);
        variableList[tempDestinationAddress] = tempData;
        tempEepromAddress += 1;
        tempDestinationAddress += 1;
        tempCount += 1;
      }
    }
    // ES.
    if (commandCharacter1 == 5 && commandCharacter2 == 19)
    {
      byte tempSourceAddress = argAddresses[1];
      unsigned int tempEepromAddress = (variableList[tempSourceAddress]) * 256 + (variableList[tempSourceAddress + 1]);
      byte tempDestinationAddress = argAddresses[0];
      byte tempCount = 0;
      while (tempCount < 230)
      {
        byte tempData = readDataFromEeprom(tempEepromAddress);
        variableList[tempDestinationAddress] = tempData;
        if (tempData == 255)
        {
          break;
        }
        tempEepromAddress += 1;
        tempDestinationAddress += 1;
        tempCount += 1;
      }
    }
    // EW.
    if (commandCharacter1 == 5 && commandCharacter2 == 23)
    {
      byte tempSourceAddress = argAddresses[0];
      unsigned int tempEepromAddress = (unsigned int)(variableList[tempSourceAddress]) * 256 + (unsigned int)(variableList[tempSourceAddress + 1]);
      writeDataToEeprom(argValues[1], tempEepromAddress);
    }
    // KR.
    if (commandCharacter1 == 11 && commandCharacter2 == 18)
    {
      variableList[argAddresses[0]] = readDataFromKeys();
    }
    // TR.
    if (commandCharacter1 == 20 && commandCharacter2 == 18)
    {
      unsigned long tempTime;
      // The division factor below is from
      // callibrating the timer.
      tempTime = millis() / (881 + timeCalibrationFactor);
      byte tempAddress = argAddresses[0];
      variableList[tempAddress] = tempTime >> 16;
      variableList[tempAddress + 1] = (tempTime >> 8) & 0xFF;
      variableList[tempAddress + 2] = tempTime & 0xFF;
    }
    // TC.
    if (commandCharacter1 == 20 && commandCharacter2 == 3)
    {
      timeCalibrationFactor = argValues[0];
    }
    // T.
    if (commandCharacter1 == 20 && commandCharacter2 != 3 && commandCharacter2 != 18)
    {
      unsigned int tempTime1Lower;
      unsigned int tempTime1Upper;
      unsigned int tempTime2Lower;
      unsigned int tempTime2Upper;
      byte tempSourceAddress1 = argAddresses[1];
      byte tempSourceAddress2 = argAddresses[2];
      tempTime1Upper = (unsigned int)(variableList[tempSourceAddress1]);
      tempTime1Lower = (unsigned int)((unsigned int)(variableList[tempSourceAddress1 + 1]) * (unsigned int)256);
      tempTime1Lower += (unsigned int)(variableList[tempSourceAddress1 + 2]);
      tempTime2Upper = (unsigned int)(variableList[tempSourceAddress2]);
      tempTime2Lower = (unsigned int)((unsigned int)(variableList[tempSourceAddress2 + 1]) * (unsigned int)256);
      tempTime2Lower += (unsigned int)(variableList[tempSourceAddress2 + 2]);
      unsigned int tempNumber = (unsigned int)(argValues[2]);
      unsigned int tempTimeLower;
      unsigned int tempTimeUpper;
      byte tempDestinationAddress = argAddresses[0];
      // TA.
      if (commandCharacter2 == 1)
      {
        tempTimeUpper = tempTime1Upper + tempTime2Upper;
        tempTimeLower = tempTime1Lower + tempTime2Lower;
        if (tempTimeLower < tempTime1Lower || tempTimeLower < tempTime2Lower)
        {
          tempTimeUpper += 1;
        }
      }
      // TS.
      if (commandCharacter2 == 19)
      {
        tempTimeUpper = tempTime1Upper - tempTime2Upper;
        tempTimeLower = tempTime1Lower - tempTime2Lower;
        if (tempTime2Lower > tempTime1Lower)
        {
          tempTimeUpper -= 1;
        }
      }
      // TD.
      if (commandCharacter2 == 4)
      {
        unsigned int tempInput1 = tempTime1Upper * (unsigned int)256 + tempTime1Lower / (unsigned int)256;
        unsigned int tempOutput1 = tempInput1 / tempNumber;
        unsigned int tempCarry = (tempInput1 % tempNumber) * (unsigned int)256 + tempTime1Lower % (unsigned int)256;
        unsigned int tempOutput2 = tempCarry / tempNumber;
        tempTimeUpper = tempOutput1 / (unsigned int)256;
        tempTimeLower = (tempOutput1 % (unsigned int)256) * (unsigned int)256 + tempOutput2;
      }
      // TT.
      if (commandCharacter2 == 20)
      {
        unsigned int tempOutput1 = tempTime1Upper * tempNumber;
        unsigned int tempOutput2 = (tempTime1Lower / (unsigned int)256) * tempNumber;
        unsigned int tempOutput3 = (tempTime1Lower % (unsigned int)256) * tempNumber;
        tempTimeUpper = tempOutput1 + tempOutput2 / (unsigned int)256;
        unsigned int tempCarry = (tempOutput2 % (unsigned int)256) * (unsigned int)256;
        tempTimeLower = tempOutput3 + tempCarry;
        if (tempTimeLower < tempOutput3 || tempTimeLower < tempCarry)
        {
          tempTimeUpper += 1;
        }
      }
      // TM.
      if (commandCharacter2 == 13)
      {
        unsigned int tempInput1 = tempTime1Upper * (unsigned int)256 + tempTime1Lower / (unsigned int)256;
        unsigned int tempOutput1 = tempInput1 / tempNumber;
        unsigned int tempCarry = (tempInput1 % tempNumber) * (unsigned int)256 + tempTime1Lower % (unsigned int)256;
        unsigned int tempRemainder = tempCarry % tempNumber;
        variableList[tempDestinationAddress] = (byte)(tempRemainder);
      } else {
        variableList[tempDestinationAddress] = (byte)(tempTimeUpper);
        variableList[tempDestinationAddress + 1] = (byte)(tempTimeLower / (unsigned long)256);
        variableList[tempDestinationAddress + 2] = (byte)(tempTimeLower);
      }
    }
    // DC.
    if (commandCharacter1 == 4 && commandCharacter2 == 3)
    {
      clearDisplay();
    }
    // DP.
    if (commandCharacter1 == 4 && commandCharacter2 == 16)
    {
      setCurrentDisplayPos(argValues[0], argValues[1]);
      sendDataToDisplay(argValues[2]);
    }
    // DA.
    if (commandCharacter1 == 4 && commandCharacter2 == 1)
    {
      setCurrentDisplayPos(argValues[0], argValues[1]);
      byte tempSourceAddress = argAddresses[2];
      byte tempCount = 0;
      byte tempAmount = argValues[3];
      while (tempCount < tempAmount)
      {
        byte tempData = variableList[tempSourceAddress];
        sendDataToDisplay(tempData);
        tempSourceAddress += 1;
        tempCount += 1;
      }
    }
    // DT.
    if (commandCharacter1 == 4 && commandCharacter2 == 20)
    {
      writeCharactersToDisplayAtPos(variableList + argAddresses[2], argValues[0], argValues[1]);
    }
    // DB.
    if (commandCharacter1 == 4 && commandCharacter2 == 2)
    {
      writeBigCharactersToDisplay(variableList + argAddresses[2], argValues[0], argValues[1]);
    }
    // PT.
    if (commandCharacter1 == 16 && commandCharacter2 == 20)
    {
      promptText();
      byte tempAddress = argAddresses[0];
      byte index = 0;
      while (index < 255)
      {
        byte tempData = promptTextText[index];
        variableList[tempAddress] = tempData;
        if (tempData == 255)
        {
          break;
        }
        tempAddress += 1;
        index += 1;
      }
    }
    // PS.
    if (commandCharacter1 == 16 && commandCharacter2 == 19)
    {
      promptSelection(variableList + argAddresses[1]);
      variableList[argAddresses[0]] = promptSelectionIndex;
    }
    // PK.
    if (commandCharacter1 == 16 && commandCharacter2 == 11)
    {
      variableList[argAddresses[0]] = promptKey();
    }
    // PN.
    if (commandCharacter1 == 16 && commandCharacter2 == 14)
    {
      byte tempAddress = argAddresses[0];
      variableList[argAddresses[0]] = promptNumber();
    }
  }
}

unsigned long abortTimeStart;
byte lastArduinoOutput;
unsigned int arduinoCommandIndex;
byte arduinoCommandType;
unsigned int arduinoCommandAddress;
byte arduinoCommandData;
byte isWaitingForArduinoClock;

void processExternalSignals()
{
  byte data = readDataFromKeys();
  unsigned long tempTime = millis();
  if ((data & 0x01) > 0)
  {
    if (tempTime > abortTimeStart + 3000)
    {
      shouldReset = 1;
    }
  } else {
    abortTimeStart = tempTime;
  }
  byte arduinoClock = digitalRead(arduinoClockPin);
  byte arduinoOutput = digitalRead(arduinoOutputPin);
  if (arduinoClock == LOW)
  {
    if (isWaitingForArduinoClock > 0)
    {
      isWaitingForArduinoClock = 0;
      pinMode(key3Pin, INPUT);
      if (arduinoCommandIndex > 16)
      {
        if (arduinoCommandType == 0)
        {
          if ((arduinoCommandIndex - 17) % 8 == 0)
          {
            arduinoCommandData = readDataFromEeprom(arduinoCommandAddress);
            arduinoCommandAddress += 1;
          }
        }
        if (arduinoCommandType == 1)
        {
          if ((arduinoCommandIndex - 17) % 8 == 0)
          {
            if (arduinoCommandIndex > 19)
            {
              writeDataToEeprom(arduinoCommandData, arduinoCommandAddress);
              arduinoCommandAddress += 1;
            }
            arduinoCommandData = 0;
          }
        }
      }
    }
  } else {
    if (lastArduinoOutput == HIGH && arduinoOutput == LOW)
    {
      arduinoCommandIndex = 0;
      arduinoCommandAddress = 0;
      arduinoCommandData = 0;
      isWaitingForArduinoClock = 1;
    }
    if (isWaitingForArduinoClock == 0)
    {
      if (arduinoCommandIndex == 0)
      {
        if (arduinoOutput == HIGH)
        {
          arduinoCommandType = 1;
        } else {
          arduinoCommandType = 0;
        }
      }
      if (arduinoCommandIndex > 0 && arduinoCommandIndex < 17)
      {
        if (arduinoOutput == HIGH)
        {
          arduinoCommandAddress += (((unsigned int)1) << (arduinoCommandIndex - 1));
        }
      }
      if (arduinoCommandIndex > 16)
      {
        byte tempBit = (((byte)1) << ((arduinoCommandIndex - 17) % 8));
        if (arduinoCommandType == 0)
        {
          pinMode(arduinoInputPin, OUTPUT);
          byte tempOutput = arduinoCommandData & tempBit;
          if (tempOutput > 0)
          {
            digitalWrite(arduinoInputPin, HIGH);
          } else {
            digitalWrite(arduinoInputPin, LOW);
          }
        }
        if (arduinoCommandType == 1)
        {
          if (arduinoOutput == HIGH)
          {
            arduinoCommandData += tempBit;
          }
        }
      }
      arduinoCommandIndex += 1;
      isWaitingForArduinoClock = 1;
    }
  }
  lastArduinoOutput = arduinoOutput;
}

void setup() {
  
}

void loop() {
  
  pinMode(displayResetPin, OUTPUT);
  pinMode(displayDataPin, OUTPUT);
  pinMode(displayClockPin, OUTPUT);
  pinMode(displayModePin, OUTPUT);
  pinMode(eepromDataPin, OUTPUT);
  pinMode(eepromClockPin, OUTPUT);
  pinMode(key1Pin, INPUT);
  pinMode(key2Pin, INPUT);
  pinMode(key3Pin, INPUT);
  pinMode(key4Pin, INPUT);
  pinMode(arduinoClockPin, INPUT);
  
  abortTimeStart = millis();
  shouldReset = 0;
  arduinoCommandIndex = 0;
  isWaitingForArduinoClock = 0;
  currentCommandAddress = 0;
  conditionalBranchStackIndex = 0;
  conditionalBranchTypeStack[0] = 0;
  resetEeprom();
  resetDisplay();
  
  clearDisplay();
  setCurrentDisplayPos(6, 1);
  byte tempList[] = {4, 21, 15, 0, 20, 9, 14, 25, 255};
  writeCharactersToDisplay(tempList);
  byte tempData = 0;
  while (tempData != 0x08 && shouldReset == 0)
  {
    tempData = promptKey();
  }
  clearDisplay();
  
  while (shouldReset == 0)
  {
    interpretCurrentCommand();
    processExternalSignals();
  }
  
}
