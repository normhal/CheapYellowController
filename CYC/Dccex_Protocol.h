/*
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
*/
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