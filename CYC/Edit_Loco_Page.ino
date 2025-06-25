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
  uint32_t fslot = lv_btnmatrix_get_selected_btn(obj); 
  functionsDirty = 1;
  if(code == LV_EVENT_VALUE_CHANGED)
  {
    if(lv_obj_get_state(objects.f_option) == LV_STATE_CHECKED) funcOption[editingID][fslot] = 1;
    else funcOption[editingID][functionEditSlot] = 0;
    lv_textarea_set_text(objects.ta_fname, " ");
    lv_textarea_set_text(objects.ta_fnum, " ");
    lv_obj_clear_state(objects.f_option, LV_STATE_CHECKED);
  }
}

void setupFuncEditSlots()
{
    int i = 0;
    int val = atoi(funcNumber[editingID][i]);
    if(val != 255)
    {
      lv_obj_add_state(objects.btn_s0, LV_STATE_CHECKED);
      lv_label_set_text(objects.lbl_s0, funcName[editingID][i]); 
      lv_obj_clear_flag(objects.fn_0, LV_OBJ_FLAG_HIDDEN);
      lv_label_set_text(objects.fn_0,funcNumber[editingID][i]);
    }else
    {
      lv_obj_clear_state(objects.btn_s0, LV_STATE_CHECKED);
      lv_label_set_text(objects.lbl_s0, ""); 
      lv_obj_add_flag(objects.fn_0, LV_OBJ_FLAG_HIDDEN);
      lv_label_set_text(objects.fn_0,"");
    }
    i = 1;
    val = atoi(funcNumber[editingID][i]);
    if(val != 255)
    {
      lv_obj_add_state(objects.btn_s1, LV_STATE_CHECKED);
      lv_label_set_text(objects.lbl_s1, funcName[editingID][i]); 
      lv_obj_clear_flag(objects.fn_1, LV_OBJ_FLAG_HIDDEN);
      lv_label_set_text(objects.fn_1,funcNumber[editingID][i]);
    }else
    {
      lv_obj_clear_state(objects.btn_s1, LV_STATE_CHECKED);
      lv_label_set_text(objects.lbl_s1, ""); 
      lv_obj_add_flag(objects.fn_1, LV_OBJ_FLAG_HIDDEN);
      lv_label_set_text(objects.fn_1,"");
    }

    i = 2;
    val = atoi(funcNumber[editingID][i]);
    if(val != 255)
    {
      lv_obj_add_state(objects.btn_s2, LV_STATE_CHECKED);
      lv_label_set_text(objects.lbl_s2, funcName[editingID][i]); 
      lv_obj_clear_flag(objects.fn_2, LV_OBJ_FLAG_HIDDEN);
      lv_label_set_text(objects.fn_2,funcNumber[editingID][i]);
    }else
    {
      lv_obj_clear_state(objects.btn_s2, LV_STATE_CHECKED);
      lv_label_set_text(objects.lbl_s2, ""); 
      lv_obj_add_flag(objects.fn_2, LV_OBJ_FLAG_HIDDEN);
      lv_label_set_text(objects.fn_2,"");
    }

    i = 3;
    val = atoi(funcNumber[editingID][i]);
    if(val != 255)
    {
      lv_obj_add_state(objects.btn_s3, LV_STATE_CHECKED);
      lv_label_set_text(objects.lbl_s3, funcName[editingID][i]); 
      lv_obj_clear_flag(objects.fn_3, LV_OBJ_FLAG_HIDDEN);
      lv_label_set_text(objects.fn_3,funcNumber[editingID][i]);
    }else
    {
      lv_obj_clear_state(objects.btn_s3, LV_STATE_CHECKED);
      lv_label_set_text(objects.lbl_s3, ""); 
      lv_obj_add_flag(objects.fn_3, LV_OBJ_FLAG_HIDDEN);
      lv_label_set_text(objects.fn_3,"");
    }

    i = 4;
    val = atoi(funcNumber[editingID][i]);
    if(val != 255)
    {
      lv_obj_add_state(objects.btn_s4, LV_STATE_CHECKED);
      lv_label_set_text(objects.lbl_s4, funcName[editingID][i]); 
      lv_obj_clear_flag(objects.fn_4, LV_OBJ_FLAG_HIDDEN);
      lv_label_set_text(objects.fn_4,funcNumber[editingID][i]);
    }else
    {
      lv_obj_clear_state(objects.btn_s4, LV_STATE_CHECKED);
      lv_label_set_text(objects.lbl_s4, ""); 
      lv_obj_add_flag(objects.fn_4, LV_OBJ_FLAG_HIDDEN);
      lv_label_set_text(objects.fn_4,"");
    }

    i = 5;
    val = atoi(funcNumber[editingID][i]);
    if(val != 255)
    {
      lv_obj_add_state(objects.btn_s5, LV_STATE_CHECKED);
      lv_label_set_text(objects.lbl_s5, funcName[editingID][i]); 
      lv_obj_clear_flag(objects.fn_5, LV_OBJ_FLAG_HIDDEN);
      lv_label_set_text(objects.fn_5,funcNumber[editingID][i]);
    }else
    {
      lv_obj_clear_state(objects.btn_s5, LV_STATE_CHECKED);
      lv_label_set_text(objects.lbl_s5, ""); 
      lv_obj_add_flag(objects.fn_5, LV_OBJ_FLAG_HIDDEN);
      lv_label_set_text(objects.fn_5,"");
    }

    i = 6;
    val = atoi(funcNumber[editingID][i]);
    if(val != 255)
    {
      lv_obj_add_state(objects.btn_s6, LV_STATE_CHECKED);
      lv_label_set_text(objects.lbl_s6, funcName[editingID][i]); 
      lv_obj_clear_flag(objects.fn_6, LV_OBJ_FLAG_HIDDEN);
      lv_label_set_text(objects.fn_6,funcNumber[editingID][i]);
    }else
    {
      lv_obj_clear_state(objects.btn_s6, LV_STATE_CHECKED);
      lv_label_set_text(objects.lbl_s6, ""); 
      lv_obj_add_flag(objects.fn_6, LV_OBJ_FLAG_HIDDEN);
      lv_label_set_text(objects.fn_6,"");
    }

    i = 7;
    val = atoi(funcNumber[editingID][i]);
    if(val != 255)
    {
      lv_obj_add_state(objects.btn_s7, LV_STATE_CHECKED);
      lv_label_set_text(objects.lbl_s7, funcName[editingID][i]); 
      lv_obj_clear_flag(objects.fn_7, LV_OBJ_FLAG_HIDDEN);
      lv_label_set_text(objects.fn_7,funcNumber[editingID][i]);
    }else
    {
      lv_obj_clear_state(objects.btn_s7, LV_STATE_CHECKED);
      lv_label_set_text(objects.lbl_s7, ""); 
      lv_obj_add_flag(objects.fn_7, LV_OBJ_FLAG_HIDDEN);
      lv_label_set_text(objects.fn_7,"");
    }

    i = 8;
    val = atoi(funcNumber[editingID][i]);
    if(val != 255)
    {
      lv_obj_add_state(objects.btn_s8, LV_STATE_CHECKED);
      lv_label_set_text(objects.lbl_s8, funcName[editingID][i]); 
      lv_obj_clear_flag(objects.fn_8, LV_OBJ_FLAG_HIDDEN);
      lv_label_set_text(objects.fn_8,funcNumber[editingID][i]);
    }else
    {
      lv_obj_clear_state(objects.btn_s8, LV_STATE_CHECKED);
      lv_label_set_text(objects.lbl_s8, ""); 
      lv_obj_add_flag(objects.fn_8, LV_OBJ_FLAG_HIDDEN);
      lv_label_set_text(objects.fn_8,"");
    }

    i = 9;
    val = atoi(funcNumber[editingID][i]);
    if(val != 255)
    {
      lv_obj_add_state(objects.btn_s9, LV_STATE_CHECKED);
      lv_label_set_text(objects.lbl_s9, funcName[editingID][i]); 
      lv_obj_clear_flag(objects.fn_9, LV_OBJ_FLAG_HIDDEN);
      lv_label_set_text(objects.fn_9,funcNumber[editingID][i]);
    }else
    {
      lv_obj_clear_state(objects.btn_s9, LV_STATE_CHECKED);
      lv_label_set_text(objects.lbl_s9, ""); 
      lv_obj_add_flag(objects.fn_9, LV_OBJ_FLAG_HIDDEN);
      lv_label_set_text(objects.fn_9,"");
    }
}

void action_fedit_slot(lv_event_t * e)
{
  void *user_data = lv_event_get_user_data(e);
  functionEditSlot = *((int*)(&user_data));
  functionsDirty = 1;
  static lv_style_t option_style;
  lv_style_init(&option_style);
  lv_style_set_bg_color(&option_style, lv_color_hex(0x07c0));
  switch (functionEditSlot)
  {
    case 0:
      lv_label_set_text(objects.lbl_s0, lv_textarea_get_text(objects.ta_fname));
      lv_label_set_text(objects.fn_0, lv_textarea_get_text(objects.ta_fnum));
      if(funcOption[editingID][functionEditSlot] == 1) lv_obj_add_style(objects.fn_0, &option_style, 1);
      lv_obj_clear_flag(objects.fn_0, LV_OBJ_FLAG_HIDDEN);
      break;
    case 1:
      lv_label_set_text(objects.lbl_s1, lv_textarea_get_text(objects.ta_fname));
      lv_label_set_text(objects.fn_1, lv_textarea_get_text(objects.ta_fnum));
      if(funcOption[editingID][functionEditSlot] == 1) lv_obj_add_style(objects.fn_1, &option_style, LV_PART_MAIN | LV_STATE_DEFAULT);
      lv_obj_clear_flag(objects.fn_1, LV_OBJ_FLAG_HIDDEN);
      break;
    case 2:
      lv_label_set_text(objects.lbl_s2, lv_textarea_get_text(objects.ta_fname));
      lv_label_set_text(objects.fn_2, lv_textarea_get_text(objects.ta_fnum));
      if(funcOption[editingID][functionEditSlot] == 1) lv_obj_add_style(objects.fn_2, &option_style, 7);
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
  strcpy(funcName[editingID][functionEditSlot], lv_textarea_get_text(objects.ta_fname));      //checked - EEZ
  strcpy(funcNumber[editingID][functionEditSlot], lv_textarea_get_text(objects.ta_fnum));     //Checked - EEZ
  if(lv_obj_get_state(objects.f_option) == LV_STATE_CHECKED) funcOption[editingID][functionEditSlot] = 1;
  else funcOption[editingID][functionEditSlot] = 0;
  lv_textarea_set_text(objects.ta_fname, "");
  lv_textarea_set_text(objects.ta_fnum, "");
  lv_obj_clear_state(objects.f_option, LV_STATE_CHECKED);
}

void action_fclear_slot(lv_event_t * e)
{
  void *user_data = lv_event_get_user_data(e);
  int functionEditSlot = *((int*)(&user_data));
  lv_textarea_set_text(objects.ta_fname, funcName[editingID][functionEditSlot]);
  lv_textarea_set_text(objects.ta_fnum, funcNumber[editingID][functionEditSlot]);
  functionsDirty = 1;
  if(funcOption[editingID][functionEditSlot] == 1) 
  { 
    lv_obj_add_state(objects.f_option, LV_STATE_CHECKED);
  }
  else 
  {
    lv_obj_clear_state(objects.f_option, LV_STATE_CHECKED);
  }
  switch (functionEditSlot)
  {
    case 0:
      lv_label_set_text(objects.lbl_s0, "");
      lv_obj_add_flag(objects.fn_0, LV_OBJ_FLAG_HIDDEN);
      break;
    case 1:
      lv_label_set_text(objects.lbl_s1, "");
      lv_obj_add_flag(objects.fn_1, LV_OBJ_FLAG_HIDDEN);
      break;
    case 2:
      lv_label_set_text(objects.lbl_s2, "");
      lv_obj_add_flag(objects.fn_2, LV_OBJ_FLAG_HIDDEN);
      break;
    case 3:
      lv_label_set_text(objects.lbl_s3, "");
      lv_obj_add_flag(objects.fn_3, LV_OBJ_FLAG_HIDDEN);
      break;
    case 4:
      lv_label_set_text(objects.lbl_s4, "");
      lv_obj_add_flag(objects.fn_4, LV_OBJ_FLAG_HIDDEN);
      break;
    case 5:
      lv_label_set_text(objects.lbl_s5, "");
      lv_obj_add_flag(objects.fn_5, LV_OBJ_FLAG_HIDDEN);
      break;
    case 6:
      lv_label_set_text(objects.lbl_s6, "");
      lv_obj_add_flag(objects.fn_6, LV_OBJ_FLAG_HIDDEN);
      break;
    case 7:
      lv_label_set_text(objects.lbl_s7, "");
      lv_obj_add_flag(objects.fn_7, LV_OBJ_FLAG_HIDDEN);
      break;
    case 8:
      lv_label_set_text(objects.lbl_s8, "");
      lv_obj_add_flag(objects.fn_8, LV_OBJ_FLAG_HIDDEN);
      break;
    case 9:
      lv_label_set_text(objects.lbl_s9, "");
      lv_obj_add_flag(objects.fn_9, LV_OBJ_FLAG_HIDDEN);
      break;
    default:
      break;
  }
  funcOption[editingID][functionEditSlot] = 0;
  strcpy(funcName[editingID][functionEditSlot], "");          //Checked
  strcpy(funcNumber[editingID][functionEditSlot], "255");     //Checked
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
      strcpy(locoName[editingID], lv_textarea_get_text(objects.ta_name));         //Checked - EEZ
      strcpy(locoAddress[editingID], lv_textarea_get_text(objects.ta_address));   //Checked - EEZ
      lv_table_set_cell_value(objects.tbl_roster, editingID, 0, locoName[editingID]);
      lv_table_set_cell_value(objects.tbl_roster, editingID, 1, locoAddress[editingID]);
      locosDirty = 1;
      if(callingPage == SCREEN_ID_THROTTLE) populateThrottle();
      loadScreen(callingPage);
      break;
    default:
      break;
  }
}

static void chkbox_event_cb(lv_event_t * e)
{
  lv_event_code_t code = lv_event_get_code(e);
  lv_obj_t * obj = lv_event_get_target(e);
  if(code == LV_EVENT_VALUE_CHANGED) 
  {
    if(lv_obj_get_state(obj) == LV_STATE_CHECKED) funcOption[editingID][functionEditSlot] = 0; //States are 3 for Checked, 2 for UnChecked
    else funcOption[editingID][functionEditSlot] = 1;
  }
}
