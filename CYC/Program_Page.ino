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
void action_program_button(lv_event_t * e)
{
  void *user_data = lv_event_get_user_data(e);
  int pressedButton = *((int*)(&user_data));
  switch(pressedButton)
  {
    case 1:         //Read Button
      if(trackSel != 1) 
      {
        trackSel = 1;
        lv_label_set_text(objects.lbl_ps1, "Program Track Forced!");
//        lv_obj_clear_state(objects.btn_read, LV_STATE_CHECKED);
//        break;
      }
      if(String(lv_textarea_get_text(objects.ta_cvn)) != "")
      {
//        Serial.printf("Reading CV: %s\n", lv_textarea_get_text(objects.ta_cvn));
//        Serial.println("<R " + String(lv_textarea_get_text(objects.ta_cvn)) + ">");
        lv_label_set_text(objects.lbl_ps1, "Reading CV...");
        if(!client.print("<R " + String(lv_textarea_get_text(objects.ta_cvn)) + ">"))
        {
          lv_label_set_text(objects.lbl_ps2, "Not connected to DCC-EX!");
          lv_obj_clear_state(objects.btn_read, LV_STATE_CHECKED);
        }else
        {
          lv_label_set_text(objects.lbl_ps2, "Waiting for DCC-EX");
          replyExpected = 1;
        }
      }else
      {
//        Serial.println("Reading CV 1");
//        lv_textarea_set_text(objects.ta_cvn, "1");
        lv_obj_clear_flag(objects.ta_adr, LV_OBJ_FLAG_HIDDEN);
        lv_label_set_text(objects.lbl_ps1, "Reading Address");
        if(!client.print("<R>"))
        {
          lv_label_set_text(objects.lbl_ps2, "Not connected to DCC-EX!");
          lv_img_set_src(objects.img_wifi, &img_x);
          lv_obj_clear_state(objects.btn_read, LV_STATE_CHECKED);
          replyExpected = 0;
          break;
        }
        lv_label_set_text(objects.lbl_ps2, "Waiting for DCC-EX");
        replyExpected = 1;
      }
      break;
    case 2:         //Write Button
      if(String(lv_textarea_get_text(objects.ta_cvn)) != "" && String(lv_textarea_get_text(objects.ta_cvv)) != "")
      {
        if(trackSel == 0)
        {
          if(String(lv_textarea_get_text(objects.ta_adr)) != "")
          {
            lv_label_set_text(objects.lbl_ps1, "Value Sent to Main Track");
//            Serial.println("<w " + String(lv_textarea_get_text(objects.ta_adr)) + " " + String(lv_textarea_get_text(objects.ta_cvn)) + " " + String(lv_textarea_get_text(objects.ta_cvv)) + ">");
            client.print("<w " + String(lv_textarea_get_text(objects.ta_adr)) + " " + String(lv_textarea_get_text(objects.ta_cvn)) + " " + String(lv_textarea_get_text(objects.ta_cvv)) + ">");
          }else
          {
            lv_label_set_text(objects.lbl_ps1, "Address needed for Main Track");
            lv_obj_clear_state(objects.btn_write, LV_STATE_CHECKED);
            break;
          }
        }else if(trackSel == 1)
        {
          lv_label_set_text(objects.lbl_ps1, "Value Sent to Prog Track");
          lv_label_set_text(objects.lbl_ps2, "");
//          Serial.println("<W " + String(lv_textarea_get_text(objects.ta_cvn)) + " " + String(lv_textarea_get_text(objects.ta_cvv)) + ">");
          client.print("<W " + String(lv_textarea_get_text(objects.ta_cvn)) + " " + String(lv_textarea_get_text(objects.ta_cvv)) + ">");
        }else
        {
          lv_label_set_text(objects.lbl_ps1, "Main or Prog MUST be selected");
        }
      }else
      {
        lv_label_set_text(objects.lbl_ps1, "Both CV and Value required!");
        lv_label_set_text(objects.lbl_ps2, "");
      }
      lv_obj_clear_state(objects.btn_write, LV_STATE_CHECKED);
      break;
    case 30:        //Cancel - Return to Calling Page
      loadScreen(callingPage);
      break;
    case 32:       //Done - Return to Calling Page
      loadScreen(callingPage);
     break;
    default:
      break;
  }
}

static void track_cb(lv_event_t * e)
{
  lv_event_code_t code = lv_event_get_code(e);
  lv_obj_t * obj = lv_event_get_target(e);
  if(code == LV_EVENT_VALUE_CHANGED) 
  {
    trackSel = lv_btnmatrix_get_selected_btn(objects.track_mtx);    //Retrieve the Selected Throttle number
    lv_textarea_set_text(objects.ta_adr, "");
    if(trackSel == 1) lv_obj_add_flag(objects.ta_adr, LV_OBJ_FLAG_HIDDEN);
    if(trackSel == 0) lv_obj_clear_flag(objects.ta_adr, LV_OBJ_FLAG_HIDDEN);
//    Serial.printf("Selected Track: %d\n", trackSel);
  }
}

static void cv_cb(lv_event_t * e)
{
  lv_event_code_t code = lv_event_get_code(e);
  lv_obj_t * obj = lv_event_get_target(e);
  if(code == LV_EVENT_VALUE_CHANGED) 
  {
    lv_obj_add_state(objects.ta_cvn, LV_STATE_DISABLED);
    char *cvNum[6] = {"2", "6", "5", "3", "4", ""};
    uint32_t id = lv_btnmatrix_get_selected_btn(objects.cv_mtx);    //Retrieve the Selected Throttle number
    lv_textarea_set_text(objects.ta_cvn, cvNum[id]);
    if(cvNum[id] == "") lv_obj_clear_state(objects.ta_cvn, LV_STATE_DISABLED);
  }
}

