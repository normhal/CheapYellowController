#include <DCCEXProtocol.h>

class MyDelegate : public DCCEXProtocolDelegate 
{
  public:
    void receivedServerVersion(int major, int minor, int patch) 
    {     
      Serial.print("\nReceived version: ");
      Serial.print(major);
      Serial.print(".");
      Serial.print(minor);
      Serial.print(".");
      Serial.println(patch);
//      nextionCommand("P2.pic=258");                             //CS has replied
    }
    void receivedTrackPower(TrackPower state) 
    { 
      Serial.print("\nReceived Track Power: ");
      Serial.println(state);  
      Serial.println("\n"); 
//      if(state) nextionCommand("POWER.pic=4");    //Indicate Power ON
//      else nextionCommand("Power.pic=5");
//      nextionCommand("P2.pic=258");                             //CS has replied
    }

    void receivedLocoUpdate(Loco* activeLoco) 
    {
//      nextionCommand("P2.pic=258");                             //CS has replied
//      nextionSetText("AD", String(activeLoco->getAddress()));
//      char *name = activeLoco->getName();
//      nextionSetText("LName", String(name));
//      nextionSetValue("S", activeLoco->getSpeed());
//      wait(20);
//      nextionSetValue("T", activeLoco->getSpeed());
//      rotaryEncoderPos = activeLoco->getSpeed();
//      oldEncPos = activeLoco->getSpeed();
//      if(activeLoco->getDirection() == Forward)
//      {
//        nextionCommand("FR.pic=8");
//      }else
//      {
//        nextionCommand("FR.pic=9");
//      }
//     if(guestActive == false) loadFunctions(ThrottlePage, selectedIDs[thNum][activeSlot[thNum]]);
    }
};

class Throttle {
public:
  Throttle(DCCEXProtocol *dccexProtocol) { _dccexProtocol = dccexProtocol; }

  void setLoco(Loco *loco) { _loco = loco; }

  Loco *getLoco() { return _loco; }

  void setSpeed(int speed) {
    if (!_loco)
      return;
    _dccexProtocol->setThrottle(_loco, speed, _loco->getDirection());
  }

  void setDirection(Direction direction) {
    if (!_loco)
      return;
    _dccexProtocol->setThrottle(_loco, _loco->getSpeed(), direction);
  }

  void process() {
    // Routine calls here included in the loop to read encoder or other inputs
  }

private:
  DCCEXProtocol *_dccexProtocol;
  Loco *_loco;
};

// define our activeLoco object
// Loco* activeLoco = nullptr;

//WiFiClient client;
/*
**************************************************************************************
* DCCEXProtocol goodies
**************************************************************************************
*/
/*
DCCEXProtocol dccexProtocol;
MyDelegate myDelegate;
Throttle *throttles[numLocoSlots+1];

void listRoster()
{
  uint8_t i = 0;
  for (Loco *dccexLoco = dccexProtocol.roster->getFirst(); dccexLoco; dccexLoco = dccexLoco->getNext()) 
  {
    rosterList[i] = dccexLoco->getAddress();
    i++;
//    Serial.printf("Entry: %d has the Address: ", i);  //    Serial.print("Address: ");
//    Serial.println(dccexLoco->getAddress());
    if(i>50) return;
    lastEntry = i;
  }
//  Serial.println("DCCEX Roster Received");
}
*/