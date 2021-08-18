const byte tinyClockPin = 3;
const byte tinyInputPin = 2;
const byte tinyOutputPin = 4;
const byte signalDelay = 3;
const char characterSet[] = " ABCDEFGHIJKLMNOPQRSTUVWXYZ.?!0123456789,'\":_+-*/=<>()#";

byte textBuffer[500];

void sendStartConditionToTiny()
{
  digitalWrite(tinyInputPin, HIGH);
  delay(signalDelay);
  digitalWrite(tinyClockPin, HIGH);
  delay(signalDelay);
  digitalWrite(tinyInputPin, LOW);
  delay(signalDelay);
  digitalWrite(tinyClockPin, LOW);
  delay(signalDelay);
}

void sendBitToTiny(byte data)
{
  if (data > 0)
  {
    digitalWrite(tinyInputPin, HIGH);
  } else {
    digitalWrite(tinyInputPin, LOW);
  }
  delay(signalDelay);
  digitalWrite(tinyClockPin, HIGH);
  delay(signalDelay);
  digitalWrite(tinyClockPin, LOW);
  delay(signalDelay);
}

void sendSequenceToTiny(byte sequence)
{
  Serial.print(sequence);
  Serial.print(" ");
  byte mask = 1;
  byte count = 0;
  while (count < 8)
  {
    byte tempResult = sequence & mask;
    sendBitToTiny(tempResult);
    mask *= 2;
    count += 1;
  }
}

byte receiveSequenceFromTiny()
{
  byte output = 0;
  byte mask = 1;
  byte count = 0;
  while (count < 8)
  {
    digitalWrite(tinyClockPin, HIGH);
    delay(signalDelay);
    if (digitalRead(tinyOutputPin) == HIGH)
    {
      output = output | mask;
    }
    delay(signalDelay);
    digitalWrite(tinyClockPin, LOW);
    delay(signalDelay);
    mask *= 2;
    count += 1;
  }
  Serial.print(output);
  Serial.print(" ");
  return output;
}

void readDataFromTinyToTextBuffer(unsigned int address, unsigned int amount)
{
  pinMode(tinyInputPin, OUTPUT);
  sendStartConditionToTiny();
  sendBitToTiny(0);
  sendSequenceToTiny(address % 256);
  sendSequenceToTiny(address / 256);
  byte *destination = textBuffer;
  unsigned int count = 0;
  while (count < amount)
  {
    delay(signalDelay * 5);
    byte data = receiveSequenceFromTiny();
    *destination = data;
    destination += 1;
    count += 1;
  }
  pinMode(tinyInputPin, INPUT);
}

unsigned int lastWriteAddress;

void writeDataToTinyFromTextBuffer(unsigned int address, unsigned int amount)
{
  pinMode(tinyInputPin, OUTPUT);
  sendStartConditionToTiny();
  sendBitToTiny(1);
  sendSequenceToTiny(address % 256);
  sendSequenceToTiny(address / 256);
  unsigned int addressOffset = 0;
  byte *sequence = textBuffer;
  unsigned int count = 0;
  while (count < amount)
  {
    byte data = *sequence;
    // Number sign.
    if (data == 54)
    {
      data = 0;
      sequence += 1;
      data += ((*sequence) - 30) * 100;
      sequence += 1;
      data += ((*sequence) - 30) * 10;
      sequence += 1;
      data += (*sequence) - 30;
      count += 3;
    }
    sendSequenceToTiny(data);
    delay(signalDelay * 8);
    addressOffset += 1;
    sequence += 1;
    count += 1;
  }
  pinMode(tinyInputPin, INPUT);
  lastWriteAddress = address + addressOffset;
}

void waitForSerialInput()
{
  while (1 == 1)
  {
    if (Serial.available() > 0)
    {
      break;
    }
    delay(50);
  }
}

unsigned int getSerialInput()
{
  byte *destination = textBuffer;
  unsigned int count = 0;
  while (1 == 1)
  {
    *destination = Serial.read();
    destination += 1;
    count += 1;
    int abortDelay = 10;
    while (Serial.available() == 0)
    {
      delay(5);
      abortDelay -= 1;
      if (abortDelay < 1)
      {
        return count;
      }
    }
  }
}

unsigned int convertTextBufferToAddress(unsigned int amount)
{
  unsigned int output = 0;
  unsigned int digitValue = 1;
  unsigned int count = 1;
  while (count < amount)
  {
    digitValue *= 10;
    count += 1;
  }
  byte *sequence = textBuffer;
  count = 0;
  while (count < amount)
  {
    output += digitValue * (*sequence - '0');
    digitValue /= 10;
    sequence += 1;
    count += 1;
  }
  return output;
}

byte convertAsciiToDuoEncoding(byte character)
{
  byte index = 0;
  while (index < 150)
  {
    if (character == characterSet[index])
    {
      return index;
    }
    index += 1;
  }
  return 255;
}

void readDataFromTinyAndDisplay(unsigned int commandAddress, unsigned int readAmount)
{
  Serial.println("Attempting to read...");
  readDataFromTinyToTextBuffer(commandAddress, readAmount);
  Serial.println();
  unsigned int index = 0;
  while (index < readAmount)
  {
    byte tempData = textBuffer[index];
    Serial.print(characterSet[tempData]);
    index += 1;
  }
  Serial.println();
}

void setup() 
{
  Serial.begin(9600);
  pinMode(tinyClockPin, OUTPUT);
  pinMode(tinyInputPin, INPUT);
  pinMode(tinyOutputPin, INPUT);
  digitalWrite(tinyClockPin, LOW);
  
  byte index = 10;
  while (index < 14)
  {
    pinMode(index, INPUT);
    index += 1;
  }
  
}

void loop()
{
  while (1 == 1)
  {
    Serial.println("Please enter a command: R or W.");
    waitForSerialInput();
    
    unsigned int tempAmount = getSerialInput();
    if (tempAmount != 1)
    {
      Serial.println("You entered too many characters.");
      break;
    }
    byte commandType = 255;
    if (textBuffer[0] == 'R')
    {
      commandType = 0;
    }
    if (textBuffer[0] == 'W')
    {
      commandType = 1;
    }
    if (commandType == 255)
    {
      Serial.println("You did not enter a valid command.");
      break;
    }
    Serial.println("Please enter an address (or L for last write address).");
    waitForSerialInput();
    tempAmount = getSerialInput();
    unsigned int commandAddress;
    byte hasSetAddress = false;
    if (tempAmount == 1)
    {
      if (textBuffer[0] == 'L')
      {
        commandAddress = lastWriteAddress;
        hasSetAddress = true;
      }
    }
    if (!hasSetAddress)
    {
      commandAddress = convertTextBufferToAddress(tempAmount);
    }
    Serial.println(commandAddress);
    if (commandType == 0)
    {
      Serial.println("Please enter a number of characters.");
      waitForSerialInput();
      tempAmount = getSerialInput();
      unsigned int readAmount = convertTextBufferToAddress(tempAmount);
      readDataFromTinyAndDisplay(commandAddress, readAmount);
    }
    if (commandType == 1)
    {
      Serial.println("Please enter some text.");
      waitForSerialInput();
      unsigned int writeAmount = getSerialInput();
      unsigned int index = 0;
      while (index < writeAmount)
      {
        char tempCharacter = textBuffer[index];
        Serial.print(tempCharacter);
        index += 1;
      }
      Serial.println();
      Serial.println("Attempting to write text...");
      index = 0;
      while (index < writeAmount)
      {
        char tempCharacter = textBuffer[index];
        textBuffer[index] = convertAsciiToDuoEncoding(tempCharacter);
        index += 1;
      }
      writeDataToTinyFromTextBuffer(commandAddress, writeAmount);
      Serial.println();
      Serial.println("Read back data? Y or N");
      waitForSerialInput();
      tempAmount = getSerialInput();
      if (textBuffer[0] == 'Y')
      {
        readDataFromTinyAndDisplay(commandAddress, writeAmount);
      }
    }
  }
}

