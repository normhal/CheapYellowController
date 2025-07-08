/*
*********************************************************************************************************
* EEPROM Routines
*********************************************************************************************************
*/
void initEEPROM()
{
  writeEEPROMByte(ROSTER_USE, ROSTER_MODE);
  writeEEPROMByte(RE_USE, ROTARY_ENCODER);
}

void writeEEPROMByte(uint16_t eeAddress, uint8_t eeData)
{
  EEPROM.write(eeAddress, eeData);
}

uint8_t readEEPROMByte(uint16_t eeAddress)
{
  uint8_t eeData = EEPROM.read(eeAddress);
  return eeData;
}
