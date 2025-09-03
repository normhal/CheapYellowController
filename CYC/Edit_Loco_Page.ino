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
static void function_name_cb(lv_event_t * e)
{
  lv_event_code_t code = lv_event_get_code(e);
  lv_obj_t * obj = lv_event_get_target(e);
}

static void fname_cb(lv_event_t * e)
{
  lv_event_code_t code = lv_event_get_code(e);
  lv_obj_t * obj = lv_event_get_target(e);
  uint32_t fSlot = lv_btnmatrix_get_selected_btn(obj); 
  functionsDirty = 1;
  if(code == LV_EVENT_VALUE_CHANGED)
  {
//    if(lv_obj_get_state(objects.f_option) == LV_STATE_CHECKED) Locomotives.FuncOption[activeLocoID][fSlot] = 1;
    if(lv_obj_get_state(objects.f_option) == LV_STATE_CHECKED) Locomotives[activeLocoID].FuncOption[fSlot] = 1;
    else Locomotives[activeLocoID].FuncOption[functionEditSlot] = 0;
    lv_textarea_set_text(objects.ta_fname, " ");
    lv_textarea_set_text(objects.ta_fnum, " ");
    lv_obj_clear_state(objects.f_option, LV_STATE_CHECKED);
  }
}

static void chkbox_event_cb(lv_event_t * e)
{
  lv_event_code_t code = lv_event_get_code(e);
  lv_obj_t * obj = lv_event_get_target(e);
  uint8_t fNum = atoi(lv_textarea_get_text(objects.ta_fnum));
  if(code == LV_EVENT_VALUE_CHANGED) 
  {
    uint8_t state = lv_obj_get_state(obj) & LV_STATE_CHECKED ? 1:0;
//    Serial.printf("State Now: %d\n", state);
    if(state == 0) Locomotives[activeLocoID].FuncOption[fNum] = 0; //States are 1 for Checked, 0 for UnChecked
    else Locomotives[activeLocoID].FuncOption[fNum] = 1;
//    Serial.printf("Option for Function: %d set to: %d\n", fNum, Locomotives.FuncOption[activeLocoID][fNum]);
  }
}

void setupFuncEditSlots()
{
//  Serial.println("Setting up Functions for Edit");
  lv_label_set_text(objects.lbl_s0, "");
  lv_label_set_text(objects.fn_0, "");
  for(uint8_t fNum = 0; fNum < NUM_FUNCS; fNum++)                           //0 to 28
  {  
    std::string s = std::to_string(fNum);
    uint8_t fSlot = Locomotives[activeLocoID].FuncSlot[fNum];
//    Serial.printf_P(PSTR ("Working on Function: %d in Slot: %d\n"), fNum, fSlot);
    if(fSlot != 255)
    {
      slot2Func[fSlot] = fNum;
      if(Locomotives[activeLocoID].FuncName[fNum] != "")          // && (fSlot != 255))
      {
//        Serial.printf_P(PSTR ("fSlot: %d fNum: %d Name: %s\n"), fSlot, fNum, Locomotives[activeLocoID].FuncName[fNum]);
        switch (fSlot)
        {
          case (0):
          {
            lv_obj_add_state(objects.btn_s0, LV_STATE_CHECKED);                 //Slot 0 is used
          lv_label_set_text(objects.lbl_s0, Locomotives[activeLocoID].FuncName[fNum].c_str());      //by funcName of func
          lv_obj_clear_flag(objects.fn_0, LV_OBJ_FLAG_HIDDEN);
          lv_label_set_text(objects.fn_0, s.c_str());
          break;
          }
          case (1):
          {
            lv_obj_add_state(objects.btn_s1, LV_STATE_CHECKED);                 //Slot 0 is used
            lv_label_set_text(objects.lbl_s1, Locomotives[activeLocoID].FuncName[fNum].c_str());      //fetch Name of func
            lv_obj_clear_flag(objects.fn_1, LV_OBJ_FLAG_HIDDEN);
            lv_label_set_text(objects.fn_1, s.c_str());                         //Display the function number
            break;
          }
          case (2):
          {
            lv_obj_add_state(objects.btn_s2, LV_STATE_CHECKED);                 //Slot 0 is used
            lv_label_set_text(objects.lbl_s2, Locomotives[activeLocoID].FuncName[fNum].c_str());      //by funcName of func
            lv_obj_clear_flag(objects.fn_2, LV_OBJ_FLAG_HIDDEN);
            lv_label_set_text(objects.fn_2, s.c_str());
            break;
          }
          case (3):
          {
            lv_obj_add_state(objects.btn_s3, LV_STATE_CHECKED);                 //Slot 0 is used
            lv_label_set_text(objects.lbl_s3, Locomotives[activeLocoID].FuncName[fNum].c_str());      //by funcName of func
            lv_obj_clear_flag(objects.fn_3, LV_OBJ_FLAG_HIDDEN);
            lv_label_set_text(objects.fn_3, s.c_str());
            break;
          }
          case (4):
          {
            lv_obj_add_state(objects.btn_s4, LV_STATE_CHECKED);                 //Slot 0 is used
            lv_label_set_text(objects.lbl_s4, Locomotives[activeLocoID].FuncName[fNum].c_str());      //by funcName of func
            lv_obj_clear_flag(objects.fn_4, LV_OBJ_FLAG_HIDDEN);
            lv_label_set_text(objects.fn_4, s.c_str());
            break;
          }
          case (5):
          {
            lv_obj_add_state(objects.btn_s5, LV_STATE_CHECKED);                 //Slot 0 is used
            lv_label_set_text(objects.lbl_s5, Locomotives[activeLocoID].FuncName[fNum].c_str());      //by funcName of func
            lv_obj_clear_flag(objects.fn_5, LV_OBJ_FLAG_HIDDEN);
            lv_label_set_text(objects.fn_5, s.c_str());
            break;
          }
          case (6):
          {
            lv_obj_add_state(objects.btn_s6, LV_STATE_CHECKED);                 //Slot 0 is used
            lv_label_set_text(objects.lbl_s6, Locomotives[activeLocoID].FuncName[fNum].c_str());      //by funcName of func
            lv_obj_clear_flag(objects.fn_6, LV_OBJ_FLAG_HIDDEN);
            lv_label_set_text(objects.fn_6, s.c_str());
            break;
          }
          case (7):
          {
            lv_obj_add_state(objects.btn_s7, LV_STATE_CHECKED);                 //Slot 0 is used
            lv_label_set_text(objects.lbl_s7, Locomotives[activeLocoID].FuncName[fNum].c_str());      //by funcName of func
            lv_obj_clear_flag(objects.fn_7, LV_OBJ_FLAG_HIDDEN);
            lv_label_set_text(objects.fn_7, s.c_str());
            break;
          }
          case (8):
          {
            lv_obj_add_state(objects.btn_s8, LV_STATE_CHECKED);                 //Slot 0 is used
            lv_label_set_text(objects.lbl_s8, Locomotives[activeLocoID].FuncName[fNum].c_str());      //by funcName of func
            lv_obj_clear_flag(objects.fn_8, LV_OBJ_FLAG_HIDDEN);
            lv_label_set_text(objects.fn_8, s.c_str());
            break;
          }
          case (9):
          {
            lv_obj_add_state(objects.btn_s9, LV_STATE_CHECKED);                 //Slot 0 is used
            lv_label_set_text(objects.lbl_s9, Locomotives[activeLocoID].FuncName[fNum].c_str());      //by funcName of func
            lv_obj_clear_flag(objects.fn_9, LV_OBJ_FLAG_HIDDEN);
            lv_label_set_text(objects.fn_9, s.c_str());
            break;
          }
          default:
            break;
        }
      }
    }
  }
}

void action_fedit_slot(lv_event_t * e)
{
  void *user_data = lv_event_get_user_data(e);
  functionEditSlot = *((int*)(&user_data));                 //Actual User Slot Number Supplied by Button Event
  uint8_t fNum = atoi(lv_textarea_get_text(objects.ta_fnum));
  Locomotives[activeLocoID].FuncName[fNum] = lv_textarea_get_text(objects.ta_fname);
  Locomotives[activeLocoID].FuncSlot[fNum] = functionEditSlot;
  if(lv_obj_get_state(objects.f_option) == LV_STATE_CHECKED) Locomotives[activeLocoID].FuncOption[fNum] = 1;
  else Locomotives[activeLocoID].FuncOption[fNum] = 0;
  functionsDirty = 1;
  switch (functionEditSlot)
  {
    case 0:
      lv_label_set_text(objects.lbl_s0, lv_textarea_get_text(objects.ta_fname));
      lv_label_set_text(objects.fn_0, lv_textarea_get_text(objects.ta_fnum));
      lv_obj_clear_flag(objects.fn_0, LV_OBJ_FLAG_HIDDEN);
      break;
    case 1:
      lv_label_set_text(objects.lbl_s1, lv_textarea_get_text(objects.ta_fname));
      lv_label_set_text(objects.fn_1, lv_textarea_get_text(objects.ta_fnum));
      lv_obj_clear_flag(objects.fn_1, LV_OBJ_FLAG_HIDDEN);
      break;
    case 2:
      lv_label_set_text(objects.lbl_s2, lv_textarea_get_text(objects.ta_fname));
      lv_label_set_text(objects.fn_2, lv_textarea_get_text(objects.ta_fnum));
      lv_obj_clear_flag(objects.fn_2, LV_OBJ_FLAG_HIDDEN);
      break;
    case 3:
      lv_label_set_text(objects.lbl_s3, lv_textarea_get_text(objects.ta_fname));
      lv_label_set_text(objects.fn_3, lv_textarea_get_text(objects.ta_fnum));
      lv_obj_clear_flag(objects.fn_3, LV_OBJ_FLAG_HIDDEN);
     break;
    case 4:
      lv_label_set_text(objects.lbl_s4, lv_textarea_get_text(objects.ta_fname));
      lv_label_set_text(objects.fn_4, lv_textarea_get_text(objects.ta_fnum));
      lv_obj_clear_flag(objects.fn_4, LV_OBJ_FLAG_HIDDEN);
      break;
    case 5:
      lv_label_set_text(objects.lbl_s5, lv_textarea_get_text(objects.ta_fname));
      lv_label_set_text(objects.fn_5, lv_textarea_get_text(objects.ta_fnum));
      lv_obj_clear_flag(objects.fn_5, LV_OBJ_FLAG_HIDDEN);
      break;
    case 6:
      lv_label_set_text(objects.lbl_s6, lv_textarea_get_text(objects.ta_fname));
      lv_label_set_text(objects.fn_6, lv_textarea_get_text(objects.ta_fnum));
      lv_obj_clear_flag(objects.fn_6, LV_OBJ_FLAG_HIDDEN);
      break;
    case 7:
      lv_label_set_text(objects.lbl_s7, lv_textarea_get_text(objects.ta_fname));
      lv_label_set_text(objects.fn_7, lv_textarea_get_text(objects.ta_fnum));
      lv_obj_clear_flag(objects.fn_7, LV_OBJ_FLAG_HIDDEN);
      break;
    case 8:
      lv_label_set_text(objects.lbl_s8, lv_textarea_get_text(objects.ta_fname));
      lv_label_set_text(objects.fn_8, lv_textarea_get_text(objects.ta_fnum));
      lv_obj_clear_flag(objects.fn_8, LV_OBJ_FLAG_HIDDEN);
      break;
    case 9:
      lv_label_set_text(objects.lbl_s9, lv_textarea_get_text(objects.ta_fname));
      lv_label_set_text(objects.fn_9, lv_textarea_get_text(objects.ta_fnum));
      lv_obj_clear_flag(objects.fn_9, LV_OBJ_FLAG_HIDDEN);
      break;
    default:
      break;
  }  
//  Serial.printf("Function: %d LocoID: %d assigned Slot: %d\n", fNum, activeLocoID, functionEditSlot);
  if(lv_obj_get_state(objects.f_option) == LV_STATE_CHECKED) Locomotives[activeLocoID].FuncOption[fNum] = 1;
  else Locomotives[activeLocoID].FuncOption[fNum] = 0;
  lv_textarea_set_text(objects.ta_fname, "");
  lv_textarea_set_text(objects.ta_fnum, "");
  lv_obj_clear_state(objects.f_option, LV_STATE_CHECKED);
}

void action_fclear_slot(lv_event_t * e)           //Moving Button Function Details to Editing Fields clearing slot
{
  void *user_data = lv_event_get_user_data(e);
  int functionEditSlot = *((int*)(&user_data));
  uint8_t fNum = 255;
  functionsDirty = 1;
  Serial.println("Functions set to Dirty");
  switch (functionEditSlot)
  {
    case 0:
      lv_label_set_text(objects.lbl_s0, "");
      lv_textarea_set_text(objects.ta_fnum, lv_label_get_text(objects.fn_0));
      fNum = atoi(lv_label_get_text(objects.fn_0));
      lv_obj_add_flag(objects.fn_0, LV_OBJ_FLAG_HIDDEN);
      break;
    case 1:
      lv_label_set_text(objects.lbl_s1, "");
      lv_textarea_set_text(objects.ta_fnum, lv_label_get_text(objects.fn_1));
      fNum = atoi(lv_label_get_text(objects.fn_1));
      lv_obj_add_flag(objects.fn_1, LV_OBJ_FLAG_HIDDEN);
      break;
    case 2:
      lv_label_set_text(objects.lbl_s2, "");
      lv_textarea_set_text(objects.ta_fnum, lv_label_get_text(objects.fn_2));
      fNum = atoi(lv_label_get_text(objects.fn_2));
      lv_obj_add_flag(objects.fn_2, LV_OBJ_FLAG_HIDDEN);
      break;
    case 3:
      lv_label_set_text(objects.lbl_s3, "");
      lv_textarea_set_text(objects.ta_fnum, lv_label_get_text(objects.fn_3));
      fNum = atoi(lv_label_get_text(objects.fn_3));
      lv_obj_add_flag(objects.fn_3, LV_OBJ_FLAG_HIDDEN);
      break;
    case 4:
      lv_label_set_text(objects.lbl_s4, "");
      lv_textarea_set_text(objects.ta_fnum, lv_label_get_text(objects.fn_4));
      fNum = atoi(lv_label_get_text(objects.fn_4));
      lv_obj_add_flag(objects.fn_4, LV_OBJ_FLAG_HIDDEN);
      break;
    case 5:
      lv_label_set_text(objects.lbl_s5, "");
      lv_textarea_set_text(objects.ta_fnum, lv_label_get_text(objects.fn_5));
      fNum = atoi(lv_label_get_text(objects.fn_5));
      lv_obj_add_flag(objects.fn_5, LV_OBJ_FLAG_HIDDEN);
      break;
    case 6:
      lv_label_set_text(objects.lbl_s6, "");
      lv_textarea_set_text(objects.ta_fnum, lv_label_get_text(objects.fn_6));
      fNum = atoi(lv_label_get_text(objects.fn_6));
      lv_obj_add_flag(objects.fn_6, LV_OBJ_FLAG_HIDDEN);
      break;
    case 7:
      lv_label_set_text(objects.lbl_s7, "");
      lv_textarea_set_text(objects.ta_fnum, lv_label_get_text(objects.fn_7));
      fNum = atoi(lv_label_get_text(objects.fn_7));
      lv_obj_add_flag(objects.fn_7, LV_OBJ_FLAG_HIDDEN);
      break;
    case 8:
      lv_label_set_text(objects.lbl_s8, "");
      lv_textarea_set_text(objects.ta_fnum, lv_label_get_text(objects.fn_8));
      fNum = atoi(lv_label_get_text(objects.fn_8));
      lv_obj_add_flag(objects.fn_8, LV_OBJ_FLAG_HIDDEN);
      break;
    case 9:
      lv_label_set_text(objects.lbl_s9, "");
      lv_textarea_set_text(objects.ta_fnum, lv_label_get_text(objects.fn_9));
      fNum = atoi(lv_label_get_text(objects.fn_9));
      lv_obj_add_flag(objects.fn_9, LV_OBJ_FLAG_HIDDEN);
      break;
    default:
      break;
  }
  lv_textarea_set_text(objects.ta_fname, Locomotives[activeLocoID].FuncName[fNum].c_str());     
  if(Locomotives[activeLocoID].FuncOption[fNum] == 1)                              
  { 
    lv_obj_add_state(objects.f_option, LV_STATE_CHECKED);
  }
  else 
  {
    lv_obj_clear_state(objects.f_option, LV_STATE_CHECKED);
  }
  Locomotives[activeLocoID].FuncOption[fNum] = 0;
  Locomotives[activeLocoID].FuncName[fNum] = "";
  Locomotives[activeLocoID].FuncSlot[fNum] = 255;        
}

void action_edit_loco_button(lv_event_t * e)
{
  void *user_data = lv_event_get_user_data(e);
  int pressedButton = *((int*)(&user_data));
  switch(pressedButton)
  {
    case (30):       //Cancel
      loadScreen(callingPage);
      break;
    case (31):       //Prog
      callingPage = SCREEN_ID_EDIT_LOCO;
      loadScreen(SCREEN_ID_PROGRAM);
      break;
    case (32):       //Done
      Locomotives[activeLocoID].LocoName = lv_textarea_get_text(objects.ta_name);         //Checked - EEZ
      Locomotives[activeLocoID].LocoAddress = lv_textarea_get_text(objects.ta_address);   //Checked - EEZ
      lv_table_set_cell_value(objects.tbl_roster, activeLocoID, 0, Locomotives[activeLocoID].LocoName.c_str());
      lv_table_set_cell_value(objects.tbl_roster, activeLocoID, 1, Locomotives[activeLocoID].LocoAddress.c_str());
      locosDirty = 1;
      if(callingPage == SCREEN_ID_THROTTLE) populateThrottle();
      else buildFunctionsPage();
      loadScreen(callingPage);
      break;
    default:
      break;
  }
}
