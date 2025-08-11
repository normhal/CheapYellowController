#include "config.h"

void initEEPROM()
{
  eeProm.begin("configs", false);
  if(!eeProm.isKey("lcdBL")) eeProm.putUInt("lcdBL", TFT_BACKLIGHT);
  if(!eeProm.isKey("timeout")) eeProm.putUInt("timeout", TIMEOUT);
  if(!eeProm.isKey("reAccel")) eeProm.putUInt("reAccel", REACCEL);
  if(!eeProm.isKey("funcCol")) eeProm.putUInt("funcCol", FUNCCOL);
  if(!eeProm.isKey("threshold")) eeProm.putUInt("threshold", THRESHOLD);
  if(!eeProm.isKey("roster")) eeProm.putBool("roster", DEFAULT_ROSTER);

  lcdBL = eeProm.getUInt("lcdBL",0);
  if(lcdBL < MIN_BL)
  {
    lcdBL = TFT_BACKLIGHT;
    eeProm.putUInt("lcdBL", lcdBL);
  }
  timeout   = eeProm.getUInt("timeout", 10);
  reAccel   = eeProm.getUInt("reAccel", 10);
  funcCol   = eeProm.getUInt("funcCol", FUNCCOL);
  threshold = eeProm.getUInt("threshold", 15);
  def_roster = eeProm.getBool("roster", false);
  
  eeProm.end();
}