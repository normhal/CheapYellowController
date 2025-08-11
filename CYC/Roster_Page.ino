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
    setupFuncEditSlots(editingID);
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
  Serial.println("Now populating Locos...");
  populateLocoArray("/locos.txt");

  // Set all function numbers to 255
  for(int i = 0; i < Locomotives.size(); i++)
  {
    for(int j = 0; j < NUM_FUNCS; j++) Locomotives[i].FuncSlot[j] = 255;
  }
  
  Serial.println("Now populating Functions");
  populateLocoFunctions("/functions.txt");

  Serial.println("Now Populating the Roster...");
  for(int i = 0; i < locoCount; i++)                    //Using the count from LittleFS
  {
    lv_table_set_cell_value(objects.tbl_roster, i, 0, Locomotives[i].LocoName.c_str());
    lv_table_set_cell_value(objects.tbl_roster, i, 1, Locomotives[i].LocoAddress.c_str());
  }
  Serial.println("Local Roster Populated");
}
/*
 **********************************************************************************************************
 * Initialize EX-Rail Roster
 **********************************************************************************************************
*/
void setupDCCEXRoster()
{
  Serial.printf("Records to Clear: %d\n", Locomotives.size());
  for(int i = 0; i < Locomotives.size(); i++)
  {
    lv_obj_add_state(objects.btn_roster, LV_STATE_CHECKED);                 //Slot 0 is used
//    lv_table_set_cell_value(objects.tbl_roster, i, 0, "");
//    lv_table_set_cell_value(objects.tbl_roster, i, 1, "");
    Locomotives[i].LocoName = "";
    Locomotives[i].LocoAddress = "";
    //Now clear the Functions
    for(uint8_t f = 0; f < NUM_FUNC_SLOTS; f++) 
    {
      Locomotives[i].FuncName[f] = " ";
      Locomotives[i].FuncSlot[f] = 255;
      Serial.printf("LocoID: %d FuncSlot: %d\n", i, f);
    }
  }
  Serial.println("DCC-EX Roster Requested - Boot");
//  Serial.println("<J R>");
//  if(!client.print("<J R>")) Serial.println("Transmit Failed");

  dccexProtocol.getLists(true, false, false, false);
}
