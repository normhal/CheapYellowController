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
//    if(lv_obj_get_state(objects.f_option) == LV_STATE_CHECKED) Locomotives.FuncOption[editingID][fSlot] = 1;
    if(lv_obj_get_state(objects.f_option) == LV_STATE_CHECKED) Locomotives[editingID].FuncOption[fSlot] = 1;
    else Locomotives[editingID].FuncOption[functionEditSlot] = 0;
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
    if(state == 0) Locomotives[editingID].FuncOption[fNum] = 0; //States are 1 for Checked, 0 for UnChecked
    else Locomotives[editingID].FuncOption[fNum] = 1;
//    Serial.printf("Option for Function: %d set to: %d\n", fNum, Locomotives.FuncOption[editingID][fNum]);
  }
}

void setupFuncEditSlots(uint8_t locoID)
{
  Serial.println("Setting up Functions for Edit");
  lv_label_set_text(objects.lbl_s0, "");
  lv_label_set_text(objects.fn_0, "");
  for(uint8_t fNum = 0; fNum < NUM_FUNCS; fNum++)                           //0 to 28
  {  
    std::string s = std::to_string(fNum);
    uint8_t fSlot = Locomotives[locoID].FuncSlot[fNum];
    Serial.printf("Working on Function: %d in Slot: %d\n", fNum, fSlot);
    if(fSlot != 255)
    {
    slot2Func[fSlot] = fNum;
    if((Locomotives[locoID].FuncName[fNum] != "")  && (fSlot != 255))
    {
      Serial.printf("fSlot: %d fNum: %d Name: %s\n", fSlot, fNum, Locomotives[locoID].FuncName[fNum]);
      switch (fSlot)
      {
        case (0):
        {
          lv_obj_add_state(objects.btn_s0, LV_STATE_CHECKED);                 //Slot 0 is used
          lv_label_set_text(objects.lbl_s0, Locomotives[locoID].FuncName[fNum].c_str());      //by funcName of func
          lv_obj_clear_flag(objects.fn_0, LV_OBJ_FLAG_HIDDEN);
          lv_label_set_text(objects.fn_0, s.c_str());
          break;
        }
        case (1):
        {
          lv_obj_add_state(objects.btn_s1, LV_STATE_CHECKED);                 //Slot 0 is used
          lv_label_set_text(objects.lbl_s1, Locomotives[locoID].FuncName[fNum].c_str());      //fetch Name of func
          lv_obj_clear_flag(objects.fn_1, LV_OBJ_FLAG_HIDDEN);
          lv_label_set_text(objects.fn_1, s.c_str());                         //Display the function number
          break;
        }
        case (2):
        {
          lv_obj_add_state(objects.btn_s2, LV_STATE_CHECKED);                 //Slot 0 is used
          lv_label_set_text(objects.lbl_s2, Locomotives[locoID].FuncName[fNum].c_str());      //by funcName of func
          lv_obj_clear_flag(objects.fn_2, LV_OBJ_FLAG_HIDDEN);
          lv_label_set_text(objects.fn_2, s.c_str());
          break;
        }
        case (3):
        {
          lv_obj_add_state(objects.btn_s3, LV_STATE_CHECKED);                 //Slot 0 is used
          lv_label_set_text(objects.lbl_s3, Locomotives[locoID].FuncName[fNum].c_str());      //by funcName of func
          lv_obj_clear_flag(objects.fn_3, LV_OBJ_FLAG_HIDDEN);
          lv_label_set_text(objects.fn_3, s.c_str());
          break;
        }
        case (4):
        {
          lv_obj_add_state(objects.btn_s4, LV_STATE_CHECKED);                 //Slot 0 is used
          lv_label_set_text(objects.lbl_s4, Locomotives[locoID].FuncName[fNum].c_str());      //by funcName of func
          lv_obj_clear_flag(objects.fn_4, LV_OBJ_FLAG_HIDDEN);
          lv_label_set_text(objects.fn_4, s.c_str());
          break;
        }
        case (5):
        {
          lv_obj_add_state(objects.btn_s5, LV_STATE_CHECKED);                 //Slot 0 is used
          lv_label_set_text(objects.lbl_s5, Locomotives[locoID].FuncName[fNum].c_str());      //by funcName of func
          lv_obj_clear_flag(objects.fn_5, LV_OBJ_FLAG_HIDDEN);
          lv_label_set_text(objects.fn_5, s.c_str());
          break;
        }
        case (6):
        {
          lv_obj_add_state(objects.btn_s6, LV_STATE_CHECKED);                 //Slot 0 is used
          lv_label_set_text(objects.lbl_s6, Locomotives[locoID].FuncName[fNum].c_str());      //by funcName of func
          lv_obj_clear_flag(objects.fn_6, LV_OBJ_FLAG_HIDDEN);
          lv_label_set_text(objects.fn_6, s.c_str());
          break;
        }
        case (7):
        {
          lv_obj_add_state(objects.btn_s7, LV_STATE_CHECKED);                 //Slot 0 is used
          lv_label_set_text(objects.lbl_s7, Locomotives[locoID].FuncName[fNum].c_str());      //by funcName of func
          lv_obj_clear_flag(objects.fn_7, LV_OBJ_FLAG_HIDDEN);
          lv_label_set_text(objects.fn_7, s.c_str());
          break;
        }
        case (8):
        {
          lv_obj_add_state(objects.btn_s8, LV_STATE_CHECKED);                 //Slot 0 is used
          lv_label_set_text(objects.lbl_s8, Locomotives[locoID].FuncName[fNum].c_str());      //by funcName of func
          lv_obj_clear_flag(objects.fn_8, LV_OBJ_FLAG_HIDDEN);
          lv_label_set_text(objects.fn_8, s.c_str());
          break;
        }
        case (9):
        {
          lv_obj_add_state(objects.btn_s9, LV_STATE_CHECKED);                 //Slot 0 is used
          lv_label_set_text(objects.lbl_s9, Locomotives[locoID].FuncName[fNum].c_str());      //by funcName of func
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
  //  slot2Func[functionEditSlot] = atoi(lv_textarea_get_text(objects.ta_fnum)); //Get the Edited Function Number and save the slot it occupies
  uint8_t fNum = atoi(lv_textarea_get_text(objects.ta_fnum));
//  strcpy(Locomotives.FuncName[editingID][slot2Func[functionEditSlot]], lv_textarea_get_text(objects.ta_fname));
  Locomotives[editingID].FuncName[fNum] = lv_textarea_get_text(objects.ta_fname);
//  Locomotives.FuncSlot[editingID][slot2Func[functionEditSlot]] = functionEditSlot;
  Locomotives[editingID].FuncSlot[fNum] = functionEditSlot;
  functionsDirty = 1;
  switch (functionEditSlot)
  {
    case 0:
      lv_label_set_text(objects.lbl_s0, lv_textarea_get_text(objects.ta_fname));
      lv_label_set_text(objects.fn_0, lv_textarea_get_text(objects.ta_fnum));
//      if(Locomotives.FuncOption[editingID][functionEditSlot] == 1) lv_obj_add_style(objects.fn_0, &option_style, 1);
      lv_obj_clear_flag(objects.fn_0, LV_OBJ_FLAG_HIDDEN);
      break;
    case 1:
      lv_label_set_text(objects.lbl_s1, lv_textarea_get_text(objects.ta_fname));
      lv_label_set_text(objects.fn_1, lv_textarea_get_text(objects.ta_fnum));
//      if(Locomotives.FuncOption[editingID][functionEditSlot] == 1) lv_obj_add_style(objects.fn_1, &option_style, LV_PART_MAIN | LV_STATE_DEFAULT);
      lv_obj_clear_flag(objects.fn_1, LV_OBJ_FLAG_HIDDEN);
      break;
    case 2:
      lv_label_set_text(objects.lbl_s2, lv_textarea_get_text(objects.ta_fname));
      lv_label_set_text(objects.fn_2, lv_textarea_get_text(objects.ta_fnum));
//      if(Locomotives.FuncOption[editingID][functionEditSlot] == 1) lv_obj_add_style(objects.fn_2, &option_style, 7);
      lv_obj_clear_flag(objects.fn_2, LV_OBJ_FLAG_HIDDEN);
      //ToDo update Option setting
      break;
    case 3:
      lv_label_set_text(objects.lbl_s3, lv_textarea_get_text(objects.ta_fname));
      lv_label_set_text(objects.fn_3, lv_textarea_get_text(objects.ta_fnum));
      lv_obj_clear_flag(objects.fn_3, LV_OBJ_FLAG_HIDDEN);
      //ToDo update Option setting
     break;
    case 4:
      lv_label_set_text(objects.lbl_s4, lv_textarea_get_text(objects.ta_fname));
      lv_label_set_text(objects.fn_4, lv_textarea_get_text(objects.ta_fnum));
      lv_obj_clear_flag(objects.fn_4, LV_OBJ_FLAG_HIDDEN);
      //ToDo update Option setting
      break;
    case 5:
      lv_label_set_text(objects.lbl_s5, lv_textarea_get_text(objects.ta_fname));
      lv_label_set_text(objects.fn_5, lv_textarea_get_text(objects.ta_fnum));
      lv_obj_clear_flag(objects.fn_5, LV_OBJ_FLAG_HIDDEN);
      //ToDo update Option setting
      break;
    case 6:
      lv_label_set_text(objects.lbl_s6, lv_textarea_get_text(objects.ta_fname));
      lv_label_set_text(objects.fn_6, lv_textarea_get_text(objects.ta_fnum));
      lv_obj_clear_flag(objects.fn_6, LV_OBJ_FLAG_HIDDEN);
      //ToDo update Option setting
      break;
    case 7:
      lv_label_set_text(objects.lbl_s7, lv_textarea_get_text(objects.ta_fname));
      lv_label_set_text(objects.fn_7, lv_textarea_get_text(objects.ta_fnum));
      lv_obj_clear_flag(objects.fn_7, LV_OBJ_FLAG_HIDDEN);
      //ToDo update Option setting
      break;
    case 8:
      lv_label_set_text(objects.lbl_s8, lv_textarea_get_text(objects.ta_fname));
      lv_label_set_text(objects.fn_8, lv_textarea_get_text(objects.ta_fnum));
      lv_obj_clear_flag(objects.fn_8, LV_OBJ_FLAG_HIDDEN);
      //ToDo update Option setting
      break;
    case 9:
      lv_label_set_text(objects.lbl_s9, lv_textarea_get_text(objects.ta_fname));
      lv_label_set_text(objects.fn_9, lv_textarea_get_text(objects.ta_fnum));
      lv_obj_clear_flag(objects.fn_9, LV_OBJ_FLAG_HIDDEN);
      //ToDo update Option setting
      break;
    default:
      break;
  }  
//  strcpy(Locomotives.FuncName[editingID][functionEditSlot], lv_textarea_get_text(objects.ta_fname));      //checked - EEZ
//  strcpy(funcNumber[editingID][functionEditSlot], lv_textarea_get_text(objects.ta_fnum));     //Checked - EEZ
//  if(lv_obj_get_state(objects.f_option) == LV_STATE_CHECKED) Locomotives.FuncOption[editingID][functionEditSlot] = 1;
//  else Locomotives.FuncOption[editingID][functionEditSlot] = 0;
  if(lv_obj_get_state(objects.f_option) == LV_STATE_CHECKED) Locomotives[editingID].FuncOption[fNum] = 1;
  else Locomotives[editingID].FuncOption[fNum] = 0;

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
  lv_textarea_set_text(objects.ta_fname, Locomotives[editingID].FuncName[fNum].c_str());     
  if(Locomotives[editingID].FuncOption[fNum] == 1)                              
  { 
    lv_obj_add_state(objects.f_option, LV_STATE_CHECKED);
  }
  else 
  {
    lv_obj_clear_state(objects.f_option, LV_STATE_CHECKED);
  }
  Locomotives[editingID].FuncOption[fNum] = 0;
  Locomotives[editingID].FuncName[fNum] = "";         
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
      Locomotives[editingID].LocoName = lv_textarea_get_text(objects.ta_name);         //Checked - EEZ
      Locomotives[editingID].LocoAddress = lv_textarea_get_text(objects.ta_address);   //Checked - EEZ
      lv_table_set_cell_value(objects.tbl_roster, editingID, 0, Locomotives[editingID].LocoName.c_str());
      lv_table_set_cell_value(objects.tbl_roster, editingID, 1, Locomotives[editingID].LocoAddress.c_str());
      locosDirty = 1;
      if(callingPage == SCREEN_ID_THROTTLE) populateThrottle();
      else buildFunctionsPage(editingID);
      loadScreen(callingPage);
      break;
    default:
      break;
  }
}
