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
void initAccMap()
{
  uint8_t mapNum;
  for(mapNum = 0; mapNum < (ACC_PER_PAGE * 2); mapNum++)
  {
    btnMap_acc_state[mapNum] = " ";
    btnMap_acc_name[mapNum] = " ";
    mapNum++;
    btnMap_acc_state[mapNum] = "\n";
    btnMap_acc_name[mapNum] = "\n";
  }
  btnMap_acc_state[mapNum-1] = NULL;
  btnMap_acc_name[mapNum-1] = NULL;
}
/*
 ********************************************************************************************************
 * Retrieve and Load the List of Accessories from DCC-EX
 ********************************************************************************************************
*/
void setupDCCEXAcc()
{
  lv_obj_add_state(objects.btn_acc, LV_STATE_CHECKED);                 //Slot 0 is used
  lv_label_set_text(objects.lbl_btn_acc, "DCC-EX");
  Serial.println("Now populating DCC-EX Turnouts...");
////  populateAccArray("/exacc.txt");
  dccexProtocol.getLists(false, true, false,false);
}
/*
 ********************************************************************************************************
 * Load the Accessories Array from Local LittleFS
 ********************************************************************************************************
*/
void setupLocalAcc()
{
  lv_obj_clear_state(objects.btn_acc, LV_STATE_CHECKED);                 //Slot 0 is used
  lv_label_set_text(objects.lbl_btn_acc, "Local");
  Serial.println("Now populating Local Turnouts...");
  populateAccArray("/accessories.txt");
}
/*
 ********************************************************************************************************
 * Accessory button call-back
 ********************************************************************************************************
*/
static void acc_cb(lv_event_t * e)
{
  lv_event_code_t code = lv_event_get_code(e);
  lv_obj_t * obj = lv_event_get_target(e);
  if(code == LV_EVENT_VALUE_CHANGED) 
  {
    uint8_t id = lv_btnmatrix_get_selected_btn(obj);      //(objects.acc_name_mtx);    //Retrieve the Selected matrix button (ID)
    uint16_t accID = atoi(lv_btnmatrix_get_btn_text(objects.acc_state_mtx, id));       //The Turnout Actual ID (accID) is stored in the Turnout State "Button" 
    if(lv_obj_get_state(objects.acc_edit_button) != LV_STATE_CHECKED)     
    { 
      if(lv_btnmatrix_has_btn_ctrl(obj, id, LV_BTNMATRIX_CTRL_CHECKED))  
      {
        lv_btnmatrix_clear_btn_ctrl(objects.acc_state_mtx, id, LV_BTNMATRIX_CTRL_CHECKED);
        Turnouts[accID].AccState = 0;
      }
      else 
      {
        lv_btnmatrix_set_btn_ctrl(objects.acc_state_mtx, id, LV_BTNMATRIX_CTRL_CHECKED);
        Turnouts[accID].AccState = 1;
      }
      String accCMD = ("<a " + String(Turnouts[accID].AccAddress) + " " + String(Turnouts[accID].AccState) + "> ");
      Serial.print(accCMD);
      if(!client.print(accCMD)) Serial.println("Transmit Failed");
    }else                                                             //EDIT is Button CHECKED
    {
      editingID = accID;
      lv_textarea_set_text(objects.ta_acc_name, Turnouts[editingID].AccName.c_str());
      lv_textarea_set_text(objects.ta_acc_id, Turnouts[editingID].AccRow.c_str());
      lv_textarea_set_text(objects.ta_acc_address, Turnouts[editingID].AccAddress.c_str());
      callingPage = SCREEN_ID_ACCESSORIES;
      loadScreen(SCREEN_ID_EDIT_ACC);
    }
  }
}
/*
 ********************************************************************************************************
 * Populate a Page of up to 12 Accessories
 ********************************************************************************************************
*/
void accDrawPage()                                                        //Page starts from a Specific ID (Multiples of ACC_PER_PAGE)
{ 
  uint8_t slotNum = 0; 
  for(uint16_t accID = accStartID; accID < (accStartID + ACC_PER_PAGE); accID++)
  {
    if((accID < NUM_ACCS) && (Turnouts[accID].AccName != ""))
    {
      lv_btnmatrix_clear_btn_ctrl(objects.acc_name_mtx, slotNum, LV_BTNMATRIX_CTRL_HIDDEN | LV_BTNMATRIX_CTRL_DISABLED);
      lv_btnmatrix_clear_btn_ctrl(objects.acc_state_mtx, slotNum, LV_BTNMATRIX_CTRL_HIDDEN | LV_BTNMATRIX_CTRL_DISABLED);
      if(Turnouts[accID].AccState == 1)
      {
        lv_btnmatrix_set_btn_ctrl(objects.acc_state_mtx, slotNum, LV_BTNMATRIX_CTRL_CHECKED);
        lv_btnmatrix_set_btn_ctrl(objects.acc_name_mtx, slotNum, LV_BTNMATRIX_CTRL_CHECKED);
      }
      else 
      {
        lv_btnmatrix_clear_btn_ctrl(objects.acc_state_mtx, slotNum, LV_BTNMATRIX_CTRL_CHECKED);
        lv_btnmatrix_clear_btn_ctrl(objects.acc_name_mtx, slotNum, LV_BTNMATRIX_CTRL_CHECKED);
      }
      btnMap_acc_name[acc_map_xlate[slotNum]] = Turnouts[accID].AccName.c_str();
      btnMap_acc_state[acc_map_xlate[slotNum]] = Turnouts[accID].AccRow.c_str();
    }else
    {
      lv_btnmatrix_set_btn_ctrl(objects.acc_name_mtx, slotNum, LV_BTNMATRIX_CTRL_HIDDEN | LV_BTNMATRIX_CTRL_DISABLED);
      lv_btnmatrix_set_btn_ctrl(objects.acc_state_mtx, slotNum, LV_BTNMATRIX_CTRL_HIDDEN | LV_BTNMATRIX_CTRL_DISABLED);
      btnMap_acc_state[acc_map_xlate[slotNum]] = " ";
      btnMap_acc_name[acc_map_xlate[slotNum]] = " ";
    }
    slotNum++;
  }
  lv_btnmatrix_set_map(objects.acc_state_mtx, btnMap_acc_state);      //Display the Updated Maps
  lv_btnmatrix_set_map(objects.acc_name_mtx, btnMap_acc_name);        
  if(accStartID == 0) lv_obj_add_state(objects.btn_page_up, LV_STATE_DISABLED);
  if(accStartID > NUM_ACCS - ACC_PER_PAGE) lv_obj_add_state(objects.btn_page_down, LV_STATE_DISABLED);
}
/* 
 ********************************************************************************************************
 * General Page Button Handling
 ********************************************************************************************************
*/
void action_accessories_button(lv_event_t * e)
{
  void *user_data = lv_event_get_user_data(e);
  int pressedButton = *((int*)(&user_data));
  switch(pressedButton)
  {
    case 28:       //Page Up
      accStartID = accStartID - ACC_PER_PAGE;
      if(accStartID < 0)
      {
        accStartID = 0;
      }
      if(accStartID == 0) lv_obj_add_state(objects.btn_page_up, LV_STATE_DISABLED);
      lv_obj_clear_state(objects.btn_page_down, LV_STATE_DISABLED);
      accDrawPage();
      break;
    case 29:       //Page Down
      accStartID = accStartID + ACC_PER_PAGE;
      if(accStartID == NUM_ACCS - ACC_PER_PAGE) lv_obj_add_state(objects.btn_page_down, LV_STATE_DISABLED);
      if(accStartID > NUM_ACCS) 
      {
        accStartID = NUM_ACCS - ACC_PER_PAGE;
      }
      if(accStartID == NUM_ACCS - ACC_PER_PAGE) lv_obj_add_state(objects.btn_page_down, LV_STATE_DISABLED);
      lv_obj_clear_state(objects.btn_page_up, LV_STATE_DISABLED);
      accDrawPage();
      break;
    case 30:       //Edit Button
//      callingPage = SCREEN_ID_ACCESSORIES;
//      loadScreen(SCREEN_ID_EDIT_ACC);
      break;
     case 31:       //Group Button
//      callingPage = SCREEN_ID_ACCESSORIES;
//      loadScreen(SCREEN_ID_EDIT_ACC);
      break;
    case 32:       //Done
      loadScreen(callingPage);
     break;
    default:
      break;
  }
}
//
//****************************************************************************************************************
// Receive DCC-EX Turnouts/Accessories And populate Local Array
//****************************************************************************************************************
//
void receiveDCCEXAccs(fs::FS &fs, const char * path)      //, const char * message)
{
  //First reset Array to "Empty"
  for(int row = 0; row < NUM_ACCS; row++) Turnouts[row].AccName = "";

  uint16_t row = 0;
  for (Turnout *turnout = dccexProtocol.turnouts->getFirst(); turnout; turnout = turnout->getNext()) 
  {
    #if defined USE_VECTORS
      Turnouts.push_back(accessory());
    #endif
    Turnouts[row].AccRow = String(row);
    Turnouts[row].AccName = turnout->getName();
    Turnouts[row].AccAddress = turnout->getId();
    Turnouts[row].AccImage = 0;
    Turnouts[row].AccType = 0;
    row++;
  }
  Serial.printf("%d DCC-EX Turnouts Populated!\n", row);
}
