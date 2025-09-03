/* 
 *****************************************************************************************************************************
 *  COPYRIGHT (c) 2025 Norman Halland (NormHal@gmail.com) unless otherwise noted.
 *
 *  This program and all its associated modules is free software:
 *  you can redistribute it and/or modify it under the terms of the
 *  GNU General Public License as published by the Free Software
 *  Foundation, either version 3 of the License, or (at your option)
 *  any later version.
 *  This program is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU General Public License for more details.
 *  You should have received a copy of the GNU General Public License
 *  along with this program.  If not, see http://www.gnu.org/licenses
 *
 *****************************************************************************************************************************
*/
static void tbl_roster_cb(lv_event_t * e)
{
  lv_obj_t * obj = lv_event_get_target(e);
  uint16_t col;
  uint16_t row;
  lv_table_get_selected_cell(obj, &row, &col);
//  Serial.printf("Selected Roster Row = %d, Col = %d\n", row, col);
  if(rosterMode == EDIT_MODE)
  {
    editingID = row;
    lv_textarea_set_text(objects.ta_name, Locomotives[editingID].LocoName.c_str());
    lv_textarea_set_text(objects.ta_address, Locomotives[editingID].LocoAddress.c_str());

    //Now set the functions
    setupFuncEditSlots();
    rosterMode = NORMAL_MODE;
    callingPage = SCREEN_ID_ROSTER;
    lv_obj_clear_state(objects.btn_edit_loco, LV_STATE_CHECKED);
    loadScreen(SCREEN_ID_EDIT_LOCO);
  }
  if(rosterMode == SELECT_MODE)
  {
    selectedIDs[activeThrottle][activeSlot[activeThrottle]] = row;
    populateThrottle();
    rosterMode = NORMAL_MODE;
    lv_obj_clear_state(objects.btn_select_loco, LV_STATE_CHECKED);
    loadScreen(SCREEN_ID_THROTTLE);
  }
}

void action_roster_button(lv_event_t * e)
{
  void *user_data = lv_event_get_user_data(e);
  int pressedButton = *((int*)(&user_data));
  switch(pressedButton)
  {
    case 28:
      rosterMode = NORMAL_MODE;
      break;
    case 29:
      rosterMode = NORMAL_MODE;
      break;
    case 30:       //Cancel
      loadScreen(callingPage);
      break;
    case 31:       //Edit Loco
      callingPage = SCREEN_ID_ROSTER;
      rosterMode = EDIT_MODE;
      lv_obj_clear_state(objects.btn_select_loco, LV_STATE_CHECKED);
      break;
    case 32:       //Select Loco
      rosterMode = SELECT_MODE;
      lv_obj_clear_state(objects.btn_edit_loco, LV_STATE_CHECKED);
     break;
    default:
      break;
  }
}
/*
 **********************************************************************************************************
 * Initialize Local Roster
 **********************************************************************************************************
*/
void setupLocalRoster()
{
  lv_obj_clear_state(objects.btn_roster, LV_STATE_CHECKED);                 //Slot 0 is used
  lv_label_set_text(objects.lbl_btn_roster, "Local");
  Serial.println("Now populating Local Locos...");
  populateLocoArray("/locos.txt");

  // Set all function numbers to 255
  for(int i = 0; i < NUM_LOCOS; i++)
  {
    for(int j = 0; j < NUM_FUNCS; j++) Locomotives[i].FuncSlot[j] = 255;
  }
  
  Serial.println("Now populating Local Functions");
  populateLocoFunctions("/functions.txt");

  Serial.println("Now Populating the Roster...");
  for(int i = 0; i < locoCount; i++)                    //Using the count from LittleFS
  {
    lv_table_set_cell_value(objects.tbl_roster, i, 0, Locomotives[i].LocoName.c_str());
    lv_table_set_cell_value(objects.tbl_roster, i, 1, Locomotives[i].LocoAddress.c_str());
  }
  Serial.println("Roster Populated with Local details");
}
/*
 **********************************************************************************************************
 * Initialize EX-Rail Roster
 **********************************************************************************************************
*/
void setupDCCEXRoster()
{
  //Serial.printf_P(PSTR ("Records to Clear: %d\n"), NUM_LOCOS);
  Serial.println("Requesting DCC-EX Roster...");
  for(int i = 0; i < NUM_LOCOS; i++)
  {
    lv_obj_add_state(objects.btn_roster, LV_STATE_CHECKED);                 //Slot 0 is used
    Locomotives[i].LocoName = "";
    Locomotives[i].LocoAddress = "";
    //And clear the Functions
    for(uint8_t f = 0; f < NUM_FUNC_SLOTS; f++) 
    {
      Locomotives[i].FuncName[f] = " ";
      Locomotives[i].FuncSlot[f] = 255;
//      Serial.printf_P(PSTR ("LocoID: %d FuncSlot: %d\n"), i, f);
    }
  }
//  receivePending = true;
  dccexProtocol.getLists(true, false, false, false);
}

//
//****************************************************************************************************************
// Receive DCC-EX Locos
//****************************************************************************************************************
//
void receiveDCCEXLocos(fs::FS &fs, const char * path)
{
  Serial.println("Receiving DCC-EX Roster");
  lv_label_set_text(objects.lbl_list_status, "Receiving DCC-EX Roster...");
  uint16_t lId = 0;
  for (Loco *loco = dccexProtocol.roster->getFirst(); loco; loco = loco->getNext()) 
  {
    #if defined USE_VECTORS
      Locomotives.push_back(locomotive());
    #endif
    
    Locomotives[lId].LocoName = loco->getName();
    Locomotives[lId].LocoAddress = loco->getAddress();
//    Serial.printf("Loco ID: %d Name: %s and Address: %s\n", lId, Locomotives[lId].LocoName, Locomotives[lId].LocoAddress);
    uint8_t slotNum = 0;
    for(uint8_t funcNum = 0; funcNum < NUM_FUNCS; funcNum++)
    {
      Locomotives[lId].FuncSlot[funcNum] = 255;
      if(loco->getFunctionName(funcNum) != NULL)
      {
        Locomotives[lId].FuncName[funcNum] = loco->getFunctionName(funcNum);
//      if()  Serial.println(Locomotives[lId].FuncName[funcNum]);
        Locomotives[lId].FuncSlot[funcNum] = slotNum;
        if(loco->isFunctionMomentary(funcNum)) Locomotives[lId].FuncOption[funcNum] = 1;
        else Locomotives[lId].FuncOption[funcNum] = 0;
//        Locomotives[lId].FuncOption[funcNum] = loco->isFunctionMomentary(funcNum);
        if(slotNum < NUM_FUNC_SLOTS) slotNum++;
        else slotNum = 255;
      }
    }
//      Locomotives[lId].FuncOption[funcNum] = loco>isFunctionMomentary(funcNum);   //wrong
//    Serial.println("Adding Loco to the Roster...");
    lv_table_set_cell_value(objects.tbl_roster, lId, 0, Locomotives[lId].LocoName.c_str());
    lv_table_set_cell_value(objects.tbl_roster, lId, 1, Locomotives[lId].LocoAddress.c_str());
    lId++;
  }  
//  receivePending = false;
  Serial.println("DCC-EX Roster Received and Populated");
}
