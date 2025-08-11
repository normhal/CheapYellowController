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
void populateThrottle()                   //Build the Loco DropDown List
{
  Serial.println("Populating Throttle");
  lv_dropdown_clear_options(objects.dd_locos);                          //Clear the previous list
  lv_label_set_text(objects.lbl_throttle_page, throttleName[activeThrottle]);        //Update the page heading
  activeLocoID = selectedIDs[activeThrottle][activeSlot[activeThrottle]];
//  Serial.printf("Locos to Add: %d\n", Locomotives.size());
  for(int i = 0; i < NUM_LOCO_SLOTS; i++)
  {
    if(i < Locomotives.size())
    {
//    Serial.printf("LocoID being loaded: %d\n", selectedIDs[activeThrottle][i]);
      if(selectedIDs[activeThrottle][i] != 255)                           //ignore unused Loco IDs
      {
//      Serial.printf("Adding LocoID: %d\n", selectedIDs[activeThrottle][i]);
//      Serial.println(Locomotives[selectedIDs[activeThrottle][i]].LocoName);
        lv_dropdown_add_option(objects.dd_locos,Locomotives[selectedIDs[activeThrottle][i]].LocoName.c_str(), i); //Add all valid Locos to the list
      }else
      {
        lv_dropdown_add_option(objects.dd_locos,"",i); //Blank out unused Loco IDs in the list
      }
    }
    populateLocoDetails();                  //Fill the page with Active Loco's details
  }
  lv_dropdown_set_selected(objects.dd_locos, activeSlot[activeThrottle]); //Set the previously active Loco as selected
}

void clearGuest()
{
  //UNCHECK Guest_address TextArea 
}

void populateLocoDetails()                //Fill the page with Active Loco's details
{
  Serial.println("Populating Loco Details");
//  if(activeLocoID != 255)
//  {
//    Serial.printf("activeLocoID: %d\n", activeLocoID);
    lv_slider_set_value(objects.slider, Locomotives[activeLocoID].LocoSpeed, LV_ANIM_OFF);
    char speedString[10] = "";
    itoa(Locomotives[activeLocoID].LocoSpeed, speedString, 10);
    lv_label_set_text(objects.lbl_slider,speedString);                    //Update the speed label to the previously set speed value
    lv_label_set_text(objects.lbl_address, Locomotives[activeLocoID].LocoAddress.c_str());    //Update the address label to the previously set address

    #if defined ROTARY_ENCODER    
      ss.setEncoderPosition(Locomotives[activeLocoID].LocoSpeed);
    #endif

    //Setup the Direction
    if(Locomotives[activeLocoID].LocoDir == 1)
    { lv_obj_add_state(objects.sw_dir, LV_STATE_CHECKED);
    }else lv_obj_clear_state(objects.sw_dir, LV_STATE_CHECKED);

    lv_obj_set_style_pad_column(objects.functions_mtx, funcCol, LV_PART_MAIN | LV_STATE_DEFAULT); //   lv_obj_set_style_pad_column(objects.functions_mtx, 40, LV_STYLE_MAIN);

    //Clear the mtxSlots
    for(uint8_t mtxSlot = 0; mtxSlot < NUM_FUNC_SLOTS; mtxSlot++)
    {
      lv_btnmatrix_set_btn_ctrl(objects.functions_mtx, mtxSlot, LV_BTNMATRIX_CTRL_HIDDEN | LV_BTNMATRIX_CTRL_DISABLED);
//      lv_btnmatrix_set_btn_ctrl(objects.functions_mtx, mtxSlot, LV_BTNMATRIX_CTRL_DISABLED);
    }
    uint8_t funcSlot = 255;
    for(int funcNum = 0; funcNum < NUM_FUNC_SLOTS; funcNum++)           //process ALL (28)possible functions
    {
      funcSlot = Locomotives[activeLocoID].FuncSlot[funcNum];            //Retrieve the 28 Function's designated Slot (0 - 9)
//      Serial.printf("funcNum: %d funcSlot: %d\n", funcNum, funcSlot);
//      uint8_t funcSlot = funcNum;            //Retrieve the 28 Function's designated Slot (0 - 9)
      if(funcSlot >= 0 && funcSlot < NUM_FUNC_SLOTS)
      {
        if(funcSlot != 255)
        {
          uint8_t mtxSlot = slotXlate[funcSlot];                      //Convert the functions slot to the Matrix slot
          btnMap_functions[map_xlate[funcSlot]] = Locomotives[activeLocoID].FuncName[funcNum].c_str();
          lv_btnmatrix_clear_btn_ctrl(objects.functions_mtx, mtxSlot, LV_BTNMATRIX_CTRL_HIDDEN | LV_BTNMATRIX_CTRL_DISABLED);
          slot2Func[funcSlot] = funcNum;                              //record which slot contains which function
          if(Locomotives[activeLocoID].FuncState[funcNum] == 1)
          { 
            lv_btnmatrix_set_btn_ctrl(objects.functions_mtx, mtxSlot, LV_BTNMATRIX_CTRL_CHECKED);
          }else
          {
            lv_btnmatrix_clear_btn_ctrl(objects.functions_mtx, mtxSlot, LV_BTNMATRIX_CTRL_CHECKED);
          }
        }
      }
    }
    lv_btnmatrix_set_map(objects.functions_mtx, btnMap_functions);      //Display the Updated Map
//  }
}

static void buildFunctionsPage(uint8_t locoID)
{
  for(uint8_t i = 0; i < NUM_FUNCS; i++)
  {
    uint16_t fSlot = Locomotives[locoID].FuncSlot[i];
    lv_btnmatrix_clear_btn_ctrl(objects.ex_functions_mtx, i, LV_BTNMATRIX_CTRL_CHECKED);
    if(fSlot != 255)
    {
      lv_btnmatrix_clear_btn_ctrl(objects.ex_functions_mtx, i, LV_BTNMATRIX_CTRL_DISABLED);
      if(Locomotives[locoID].FuncState[i] == 1) lv_btnmatrix_set_btn_ctrl(objects.ex_functions_mtx, i, LV_BTNMATRIX_CTRL_CHECKED);
    }
  }
}

static void throttle_selection_handler_cb(lv_event_t * e)
{
  lv_event_code_t code = lv_event_get_code(e);
  lv_obj_t * obj = lv_event_get_target(e);
  if(code == LV_EVENT_VALUE_CHANGED) 
  {
    uint8_t id = lv_btnmatrix_get_selected_btn(objects.throttle_mtx);    //Retrieve the Selected Throttle number
    activeThrottle = id;                                                  //Make this the new Active Throttle
    populateThrottle();
    loadScreen(SCREEN_ID_THROTTLE);
  }
}

static void functions_cb(lv_event_t * e)
{
  if(rosterMode != GUEST_ACTIVE)
  {
    lv_event_code_t code = lv_event_get_code(e);
    lv_obj_t * obj = lv_event_get_target(e);
    uint32_t mapSlot = lv_btnmatrix_get_selected_btn(obj); 
//    Serial.printf("MapSlot: %d\n", mapSlot);
    uint32_t fSlot = abs_xlate[mapSlot];
//    Serial.printf("fSlot: %d\n", fSlot);
    uint8_t funcNum = slot2Func[fSlot];     //check
//    Serial.printf("Function Number: %d\n", funcNum);
    if(Locomotives[activeLocoID].FuncName[funcNum] != "")    //check
    {
      if(code == LV_EVENT_PRESSED)
      {
//        Serial.printf("Function Pressed: %d\n", Locomotives[activeLocoID].FuncOption[fslot]);
        if(Locomotives[activeLocoID].FuncState[funcNum] == 1) Locomotives[activeLocoID].FuncState[funcNum] = 0;
        else Locomotives[activeLocoID].FuncState[funcNum] = 1;
        //Send the DCCEX Command...
        String functionCMD = ("<F " + String(Locomotives[activeLocoID].LocoAddress) + " " + String(funcNum) + " " + String(Locomotives[activeLocoID].FuncState[funcNum]) + ">");
        Serial.println(functionCMD);
//        client.print(functionCMD);
        if(!client.print(functionCMD)) Serial.println("Transmit Failed");
      }
      if(code == LV_EVENT_RELEASED)
      {
//        Serial.printf("Function %d in Slot: %d has Option state: %d\n", funcNum, fSlot, Locomotives[activeLocoID].FuncOption[funcNum]);
        if(Locomotives[activeLocoID].FuncOption[funcNum] == 1)
        {
          lv_btnmatrix_clear_btn_ctrl(obj, mapSlot, LV_BTNMATRIX_CTRL_CHECKED);
          Locomotives[activeLocoID].FuncState[funcNum] = 0;
          //Send the DCCEX Command...
          String functionCMD = ("<F " + String(Locomotives[activeLocoID].LocoAddress) + " " + String(funcNum) + " " + String(Locomotives[activeLocoID].FuncState[funcNum]) + ">");
          Serial.println(functionCMD);
          if(!client.print(functionCMD)) Serial.println("Transmit Failed");
//          client.print(functionCMD);
        }
      }
    }
  }
}

void dd_locos_cb(lv_event_t * e)
{
  lv_event_code_t code = lv_event_get_code(e);
//  lv_obj_t * obj = lv_event_get_target(e);
  if(code == LV_EVENT_VALUE_CHANGED) 
  {
    activeSlot[activeThrottle] = lv_dropdown_get_selected(objects.dd_locos);
    activeLocoID = selectedIDs[activeThrottle][activeSlot[activeThrottle]];       //update activeLocoID
    populateLocoDetails();
  }
}

void setSpeed(uint16_t locoAddr, uint16_t newSpeed, uint8_t newDir)
{
  char speedString[10] = "";
  itoa(newSpeed, speedString, 10);
  lv_slider_set_value(objects.slider, newSpeed, LV_ANIM_OFF);
  lv_label_set_text(objects.lbl_slider,speedString);
  String speedCMD = ("<t " + String(locoAddr) + " "
         + speedString + " " + String(newDir) + ">");
#if defined ROTARY_ENCODER    
  ss.setEncoderPosition(newSpeed);
#endif
  Serial.println(speedCMD);
  if(!client.print(speedCMD)) Serial.println("Transmit Failed");
}

void action_throttle_button(lv_event_t * e)
{
  void *user_data = lv_event_get_user_data(e);
  int pressedButton = *((int*)(&user_data));
  switch(pressedButton)
  {
    case 1:       
      rosterMode = GUEST_ACTIVE;
      lv_obj_clear_flag(objects.kbd_guest, LV_OBJ_FLAG_HIDDEN);
      lv_slider_set_value(objects.slider, 0, LV_ANIM_OFF);
      lv_label_set_text(objects.lbl_slider,"0");
      lv_label_set_text(objects.lbl_address, lv_textarea_get_text(objects.ta_guest_address));
      for(int i = 0; i < NUM_FUNC_SLOTS; i++)
      {
        lv_btnmatrix_set_btn_ctrl(objects.functions_mtx, slotXlate[i], LV_BTNMATRIX_CTRL_HIDDEN);        
      }
      gfx->flush(true);
      break;
    case 2:       //Guest Loco
//      Serial.println("Guest InActive");
      lv_obj_add_flag(objects.kbd_guest, LV_OBJ_FLAG_HIDDEN);
      rosterMode = GUEST_INACTIVE;
//      Serial.printf("Roster Mode: %d\n", rosterMode);
      populateLocoDetails();
      break;
    case 3:       //Slider 
    {
//      Serial.printf("Roster Mode: %d\n", rosterMode);
//      if(runState == 0) break;
      if(rosterMode != GUEST_ACTIVE)
      {
//        Serial.println("Setting Loco Speed");
        Locomotives[activeLocoID].LocoSpeed = lv_slider_get_value(objects.slider);
        setSpeed(atoi(Locomotives[activeLocoID].LocoAddress.c_str()), Locomotives[activeLocoID].LocoSpeed, Locomotives[activeLocoID].LocoDir);
      }else     //Guest Active
      {
//        Serial.println("Setting Guest Speed");
        guestSpeed = lv_slider_get_value(objects.slider);
        setSpeed(atoi(lv_textarea_get_text(objects.ta_guest_address)), guestSpeed, guestDir);
      }
      break;
    }
    case 4:       //Direction - Set to Forward
    {
      setLocoFwd();
      break;
    }
    case 5:       //Direction - Set to Reverse
    {
      setLocoRev();
      break;
    }
    case 6:
//      Serial.println("Clicked Up");
      if(Locomotives[activeLocoID].LocoSpeed < 126) Locomotives[activeLocoID].LocoSpeed = Locomotives[activeLocoID].LocoSpeed + 1;
      setSpeed(atoi(Locomotives[activeLocoID].LocoAddress.c_str()), Locomotives[activeLocoID].LocoSpeed, Locomotives[activeLocoID].LocoDir);
//      Serial.printf("New Speed: %d\n", Locomotives[activeLocoID].LocoSpeed);
      break;
    case 7:
//      Serial.println("Clicked Down");
      if(Locomotives[activeLocoID].LocoSpeed > 0) Locomotives[activeLocoID].LocoSpeed = Locomotives[activeLocoID].LocoSpeed - 1;
      setSpeed(atoi(Locomotives[activeLocoID].LocoAddress.c_str()), Locomotives[activeLocoID].LocoSpeed, Locomotives[activeLocoID].LocoDir);
//      Serial.printf("New Speed: %d\n", Locomotives[activeLocoID].LocoSpeed);
      break;
    case 29:    //Funcs Button
    {
      if(rosterMode != GUEST_ACTIVE)
      {
        buildFunctionsPage(activeLocoID);
        loadScreen(SCREEN_ID_FUNCTIONS);
      }
      break;
    }
    case 30:    //Prog Button
      rosterMode = GUEST_INACTIVE;
      callingPage = SCREEN_ID_THROTTLE;
      loadScreen(SCREEN_ID_PROGRAM);
      break;
    case 31:    //Roster
      rosterMode = GUEST_INACTIVE;
      callingPage = SCREEN_ID_THROTTLE;
      loadScreen(SCREEN_ID_ROSTER);
      break;
    case 32:    //Acc
      callingPage = SCREEN_ID_THROTTLE;
      loadScreen(SCREEN_ID_ACCESSORIES);
      break;
    default:
      break;
  }
}
void setLocoFwd()
{
//  Serial.println("Direction set Forward");
  if(rosterMode != GUEST_ACTIVE)
  {
    if(Locomotives[activeLocoID].LocoSpeed > threshold) Locomotives[activeLocoID].LocoSpeed = 0;
    Locomotives[activeLocoID].LocoDir = 1;
    setSpeed(atoi(Locomotives[activeLocoID].LocoAddress.c_str()), Locomotives[activeLocoID].LocoSpeed, Locomotives[activeLocoID].LocoDir);
  }else
  {
    if(guestSpeed > threshold) guestSpeed = 0;
    guestDir = 1;
    setSpeed(atoi(lv_textarea_get_text(objects.ta_guest_address)), guestSpeed, guestDir);
  }
}

void setLocoRev()
{
//  Serial.println("Direction set Reverse");
  if(rosterMode != GUEST_ACTIVE)
  {
    if(Locomotives[activeLocoID].LocoSpeed > threshold) Locomotives[activeLocoID].LocoSpeed = 0;
    Locomotives[activeLocoID].LocoDir = 0;
    setSpeed(atoi(Locomotives[activeLocoID].LocoAddress.c_str()), Locomotives[activeLocoID].LocoSpeed, Locomotives[activeLocoID].LocoDir);
  }else
  {
    if(guestSpeed > threshold) guestSpeed = 0;
    guestDir = 0;
    setSpeed(atoi(lv_textarea_get_text(objects.ta_guest_address)), guestSpeed, guestDir);
  }
}

void action_functions_button(lv_event_t * e)
{
  void *user_data = lv_event_get_user_data(e);
  int pressedButton = *((int*)(&user_data));
  switch(pressedButton)
  {
    case 30:    //Cancel Button
      lv_obj_clear_state(objects.btn_fedit, LV_STATE_CHECKED);
      populateLocoDetails();
      loadScreen(SCREEN_ID_THROTTLE);
      break;
    case 31:    //Description Button
      break;
    case 32:    //Done Button
      lv_obj_clear_state(objects.btn_fedit, LV_STATE_CHECKED);
      populateLocoDetails();
      loadScreen(SCREEN_ID_THROTTLE);
      break;
    default:
      break;
  }
}

static void ex_functions_cb(lv_event_t * e)
{
  if(rosterMode != GUEST_ACTIVE)
  {
    lv_event_code_t code = lv_event_get_code(e);
    lv_obj_t * obj = lv_event_get_target(e);
    uint32_t fNum = lv_btnmatrix_get_selected_btn(obj); 
    if(fNum == 65535) return;
    if(lv_obj_get_state(objects.btn_fedit) != LV_STATE_CHECKED)               //CHECKED = Edit Mode
    {
      if(lv_btnmatrix_has_btn_ctrl(obj, fNum, LV_BTNMATRIX_CTRL_DISABLED)) return;
      if(code == LV_EVENT_PRESSED)
      {
//      Serial.printf("Function Pressed: %d\n", fNum);
        lv_label_set_text(objects.func_description, Locomotives[activeLocoID].FuncName[fNum].c_str());
        if(Locomotives[activeLocoID].FuncState[fNum] == 1) Locomotives[activeLocoID].FuncState[fNum] = 0;
        else Locomotives[activeLocoID].FuncState[fNum] = 1;

      //Send the DCCEX Command...
        String functionCMD = ("<F " + String(Locomotives[activeLocoID].LocoAddress) + " " + String(fNum) + " " + String(Locomotives[activeLocoID].FuncState[fNum]) + ">");
        Serial.println(functionCMD);
        if(!client.print(functionCMD)) Serial.println("Transmit Failed");
      }else if(code == LV_EVENT_RELEASED)
      {
 //       Serial.printf("Function Released: %d\n", Locomotives[activeLocoID].FuncOption[fSlot]);
//        lv_label_set_text(objects.func_description, "");
        if(Locomotives[activeLocoID].FuncOption[fNum] == 1)              //Check if Momentary
        {
          lv_btnmatrix_clear_btn_ctrl(obj, fNum, LV_BTNMATRIX_CTRL_CHECKED);
          Locomotives[activeLocoID].FuncState[fNum] = 0;
          //Send the DCCEX Command...
          String functionCMD = ("<F " + String(Locomotives[activeLocoID].LocoAddress) + " " + String(fNum) + " " + String(Locomotives[activeLocoID].FuncState[fNum]) + ">");
          Serial.println(functionCMD);
          if(!client.print(functionCMD)) Serial.println("Transmit Failed");
        }
      }
    }else     //Now in Edit Mode
    {
      char str[2];
      if(lv_btnmatrix_has_btn_ctrl(obj, fNum, LV_BTNMATRIX_CTRL_DISABLED))
      {
        lv_textarea_set_text(objects.ta_fnum, itoa(fNum, str, 10));
      }
      else
      { 
        lv_textarea_set_text(objects.ta_fname, "");
        lv_textarea_set_text(objects.ta_fnum, "");
      }
      lv_textarea_set_text(objects.ta_name, Locomotives[activeLocoID].LocoName.c_str());
      lv_textarea_set_text(objects.ta_address, Locomotives[activeLocoID].LocoAddress.c_str());
      setupFuncEditSlots(activeLocoID);
      callingPage = SCREEN_ID_FUNCTIONS;
      loadScreen(SCREEN_ID_EDIT_LOCO);
    }
  }
}
