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
void populateThrottle()
{
  lv_dropdown_clear_options(objects.dd_locos);                          //Clear the previous list
  lv_label_set_text(objects.lbl_throttle_page,throttleName[activeThrottle]);        //Update the page heading
  activeLocoID = selectedIDs[activeThrottle][activeSlot[activeThrottle]];
  for(int i = 0; i < NUM_LOCO_SLOTS; i++)
  {
    if(selectedIDs[activeThrottle][i] != 255)                           //ignore unused Loco IDs
    {
      lv_dropdown_add_option(objects.dd_locos,locoName[selectedIDs[activeThrottle][i]],i); //Add all valid Locos to the list
    }else
    {
      lv_dropdown_add_option(objects.dd_locos,"",i); //Blank out unused Loco IDs in the list
    }
  }
  lv_dropdown_set_selected(objects.dd_locos, activeSlot[activeThrottle]); //Set the previously active Loco as selected
  populateLocoDetails();
}

void clearGuest()
{
  rosterMode = GUEST_INACTIVE;
  //UNCHECK Guest_address TextArea 
}

void populateLocoDetails()
{
//  Serial.printf("LocoID being Populated: %d\n", activeLocoID);
  if(activeLocoID != 255)
  {
    lv_slider_set_value(objects.slider, locoSpeed[activeLocoID], LV_ANIM_OFF);
    char speedString[10] = "";
    sprintf(speedString, "%d", (long)locoSpeed[activeLocoID]);
    lv_label_set_text(objects.lbl_slider,speedString);                    //Update the speed label to the previously set speed value
    lv_label_set_text(objects.lbl_address, locoAddress[activeLocoID]);                    //Update the address label to the previously set address

    //Setup the Direction
    if(locoDir[activeLocoID] == 1)
    { lv_obj_add_state(objects.sw_dir, LV_STATE_CHECKED);
    }else lv_obj_clear_state(objects.sw_dir, LV_STATE_CHECKED);
    //Setup the Function Buttons
    for(int i = 0; i < NUM_FUNC_SLOTS; i++)
    {
      int val = atoi(funcNumber[activeLocoID][i]);
      if(val != 255)
      {
        btnMap_functions[map_xlate[i]] = funcName[activeLocoID][i];
        lv_btnmatrix_clear_btn_ctrl(objects.function_mtx, func_xlate[i], LV_BTNMATRIX_CTRL_HIDDEN);
        if(funcState[activeLocoID][i] == 1)
        { 
          lv_btnmatrix_set_btn_ctrl(objects.function_mtx, func_xlate[i], LV_BTNMATRIX_CTRL_CHECKED);
        }else
        {
          lv_btnmatrix_clear_btn_ctrl(objects.function_mtx, func_xlate[i], LV_BTNMATRIX_CTRL_CHECKED);
        }
      }else
      {
        btnMap_functions[map_xlate[i]] = " ";
        lv_btnmatrix_set_btn_ctrl(objects.function_mtx, func_xlate[i], LV_BTNMATRIX_CTRL_HIDDEN);
      }
    }
    lv_btnmatrix_set_map(objects.function_mtx, btnMap_functions);
  }else
  {
    loadScreen(SCREEN_ID_ROSTER);
  }
}

static void throttle_selection_handler_cb(lv_event_t * e)
{
  lv_event_code_t code = lv_event_get_code(e);
  lv_obj_t * obj = lv_event_get_target(e);
  if(code == LV_EVENT_VALUE_CHANGED) 
  {
    uint32_t id = lv_btnmatrix_get_selected_btn(objects.throttle_mtx);    //Retrieve the Selected Throttle number
    activeThrottle = id;                                                  //Make this the new Active Throttle
    populateThrottle();
    loadScreen(SCREEN_ID_THROTTLE);
  }
}

static void functions_cb(lv_event_t * e)
{
  if(rosterMode == GUEST_INACTIVE)
  {
    lv_event_code_t code = lv_event_get_code(e);
    lv_obj_t * obj = lv_event_get_target(e);
    uint32_t mapslot = lv_btnmatrix_get_selected_btn(obj); 
    if(mapslot >9) return;
    uint32_t fslot = abs_xlate[mapslot];
    if(funcName[activeLocoID][fslot] != "")
    {
      if(code == LV_EVENT_PRESSED)
      {
//        Serial.printf("Function Pressed: %d\n", funcOption[activeLocoID][fslot]);
        if(funcState[activeLocoID][fslot] == 1) funcState[activeLocoID][fslot] = 0;
        else funcState[activeLocoID][fslot] = 1;
        //Send the DCCEX Command...
        String functionCMD = ("<F " + String(locoAddress[activeLocoID]) + " " + String(atoi(funcNumber[activeLocoID][fslot])) + " " + String(funcState[activeLocoID][fslot]) + ">");
//        Serial.println(functionCMD);
        client.print(functionCMD);
      }else if(code == LV_EVENT_RELEASED)
      {
 //       Serial.printf("Function Released: %d\n", funcOption[activeLocoID][fslot]);
        if(funcOption[activeLocoID][fslot] == 1)
        {
          lv_btnmatrix_clear_btn_ctrl(obj, func_xlate[fslot], LV_BTNMATRIX_CTRL_CHECKED);
          funcState[activeLocoID][fslot] = 0;
          //Send the DCCEX Command...
          String functionCMD = ("<F " + String(locoAddress[activeLocoID]) + " " + String(atoi(funcNumber[activeLocoID][fslot])) + " " + String(funcState[activeLocoID][fslot]) + ">");
//          Serial.println(functionCMD);
          client.print(functionCMD);
        }
      }
    }
  }
}

void dd_locos_cb(lv_event_t * e)
{
  //clearGuest();
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
  sprintf(speedString, "%d", newSpeed);
  lv_slider_set_value(objects.slider, newSpeed, LV_ANIM_OFF);
  lv_label_set_text(objects.lbl_slider,speedString);
  String speedCMD = ("<t " + String(locoAddr) + " "
         + speedString + " " + String(newDir) + ">");
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
        lv_btnmatrix_set_btn_ctrl(objects.function_mtx, func_xlate[i], LV_BTNMATRIX_CTRL_HIDDEN);        
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
      if(rosterMode != GUEST_ACTIVE)
      {
//        Serial.println("Setting Loco Speed");
        locoSpeed[activeLocoID] = lv_slider_get_value(objects.slider);
        setSpeed(atoi(locoAddress[activeLocoID]), locoSpeed[activeLocoID], locoDir[activeLocoID]);
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
//      Serial.println("Direction set Forward");
      if(rosterMode != GUEST_ACTIVE)
      {
        if(locoSpeed[activeLocoID] > thresholdSpeed) locoSpeed[activeLocoID] = 0;
        locoDir[activeLocoID] = 1;
        setSpeed(atoi(locoAddress[activeLocoID]), locoSpeed[activeLocoID], locoDir[activeLocoID]);
      }else
      {
        if(guestSpeed > thresholdSpeed) guestSpeed = 0;
        guestDir = 1;
        setSpeed(atoi(lv_textarea_get_text(objects.ta_guest_address)), guestSpeed, guestDir);
      }
      break;
    }
    case 5:       //Direction - Set to Reverse
    {
//      Serial.println("Direction set Reverse");
      if(rosterMode != GUEST_ACTIVE)
      {
        if(locoSpeed[activeLocoID] > thresholdSpeed) locoSpeed[activeLocoID] = 0;
        locoDir[activeLocoID] = 0;
        setSpeed(atoi(locoAddress[activeLocoID]), locoSpeed[activeLocoID], locoDir[activeLocoID]);
      }else
      {
        if(guestSpeed > thresholdSpeed) guestSpeed = 0;
        guestDir = 0;
        setSpeed(atoi(lv_textarea_get_text(objects.ta_guest_address)), guestSpeed, guestDir);
      }
      break;
    }
    case 6:
//      Serial.println("Clicked Up");
      if(locoSpeed[activeLocoID] < 126) locoSpeed[activeLocoID] = locoSpeed[activeLocoID] + 1;
      setSpeed(atoi(locoAddress[activeLocoID]), locoSpeed[activeLocoID], locoDir[activeLocoID]);
//      Serial.printf("New Speed: %d\n", locoSpeed[activeLocoID]);
      break;
    case 7:
//      Serial.println("Clicked Down");
      if(locoSpeed[activeLocoID] > 0) locoSpeed[activeLocoID] = locoSpeed[activeLocoID] - 1;
      setSpeed(atoi(locoAddress[activeLocoID]), locoSpeed[activeLocoID], locoDir[activeLocoID]);
//      Serial.printf("New Speed: %d\n", locoSpeed[activeLocoID]);
      break;
    case 29:    //Edit Button
    {
      clearGuest();
      editingID = activeLocoID;
      lv_textarea_set_text(objects.ta_name, locoName[editingID]);
      lv_textarea_set_text(objects.ta_address, locoAddress[editingID]);
      setupFuncEditSlots();
      callingPage = SCREEN_ID_THROTTLE;
      loadScreen(SCREEN_ID_EDIT_LOCO);
      break;
    }
    case 30:    //Prog Button
      clearGuest();
      callingPage = SCREEN_ID_THROTTLE;
      loadScreen(SCREEN_ID_PROGRAM);
      break;
    case 31:    //Roster
      clearGuest();
      callingPage = SCREEN_ID_THROTTLE;
      loadScreen(SCREEN_ID_ROSTER);
      break;
    case 32:    //Acc
//      callingPage = SCREEN_ID_THROTTLE;
//      loadScreen(SCREEN_ID_ACCESSORIES);
      break;
    default:
      break;
  }
}
