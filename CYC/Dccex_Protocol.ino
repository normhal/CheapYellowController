/*
**************************************************************************************
* DCCEXProtocol goodies
**************************************************************************************
*/
//DCCEXProtocol dccexProtocol;
//MyDelegate myDelegate;
//Throttle *throttles[numLocoSlots+1];

uint8_t lastEntry;
uint16_t rosterList[NUM_LOCOS];

void listRoster()
{
  Serial.println("Calling DCCEX");
  uint8_t i = 0;
  for (Loco *dccexLoco = dccexProtocol.roster->getFirst(); dccexLoco; dccexLoco = dccexLoco->getNext()) 
  {
    rosterList[i] = dccexLoco->getAddress();
    i++;
    Serial.printf("Entry: %d has the Address: %d\n", i, dccexLoco->getAddress());  //    Serial.print("Address: ");
    if(i>50) return;
    lastEntry = i;
  }
//  Serial.println("DCCEX Roster Received");
}

void receivedRosterList() 
{
  listRoster();
}

