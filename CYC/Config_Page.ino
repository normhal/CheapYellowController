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
void action_config_button(lv_event_t * e)
{
  void *user_data = lv_event_get_user_data(e);
//  lv_event_code_t code = lv_event_get_code(e);
//  if(lv_obj_get_state(objects.btn_roster) == LV_STATE_CHECKED)
//  {
  int pressedButton = *((int*)(&user_data));
//  Serial.printf("Pressed Button: %d\n", pressedButton);
  switch(pressedButton)
  {
    case (22):        //Rotary Encoder UNChecked
      re_enabled = false;
      eeProm.begin("configs", false);
      eeProm.putBool("rEncoder", re_enabled);
      eeProm.end();
      break;
    case (23):        //Rotary Encoder Checked
      re_enabled = true;
      eeProm.begin("configs", false);
      eeProm.putBool("rEncoder", re_enabled);
      eeProm.end();
      break;
    case (24):        //Startup with Local Roster
    {
      lv_label_set_text(objects.lbl_btn_roster, "Local");
      def_roster = false;
      eeProm.begin("configs", false);
      eeProm.putBool("roster", def_roster);
      eeProm.end();
//      populateLocoArray("/locos.txt");
      lv_label_set_text(objects.lbl_list_status, "Start with Local Roster");
      Serial.printf("Roster set to: %d\n", def_roster);
      reboot_req = true;
      break;
    }
    case (25):        //Startup with DCC-EX Roster
    {
      lv_label_set_text(objects.lbl_btn_roster, "DCC-EX");
      def_roster = true;
      eeProm.begin("configs", false);
      eeProm.putBool("roster", def_roster);
      eeProm.end();
//      populateLocoArray("/exlocos.txt");
      lv_label_set_text(objects.lbl_list_status, "Start with DCC-EX Roster");
      Serial.printf("Roster set to: %d\n", def_roster);
      reboot_req = true;
      break;
    }
    case (26):        //Startup with Local Accessories
    {
      lv_label_set_text(objects.lbl_btn_acc, "Local");
      def_acc = false;
      eeProm.begin("configs", false);
      eeProm.putBool("accList", def_acc);
      eeProm.end();
//      populateAccArray("/accessories.txt");
      lv_label_set_text(objects.lbl_list_status, "Start with Local Accessories");
      Serial.printf("Acc set to: %d\n", def_acc);
      reboot_req = true;
      break;
    }
    case (27):        //Startup with DCC-EX Accessories
    {
      lv_label_set_text(objects.lbl_btn_acc, "DCC-EX");
      def_acc = true;
      eeProm.begin("configs", false);
      eeProm.putBool("accList", def_acc);
      eeProm.end();
//      populateAccArray("/locos.txt");
      lv_label_set_text(objects.lbl_list_status, "Start with DCC-EX Accessories");
      Serial.printf("Acc set to: %d\n", def_acc);
      reboot_req = true;
      break;
    }
    case (28):        
    {
      Serial.println("Now Populating Local Lists");
      lv_label_set_text(objects.lbl_list_status, "Loading Local Roster");
      delay(500);
      setupLocalRoster();
      delay(500);
      lv_label_set_text(objects.lbl_list_status, "Roster Loaded, now Loading Accessories");
      delay(500);
      setupLocalAcc();
      delay(500);
      lv_label_set_text(objects.lbl_list_status, "Local Roster and Accessories Loaded");
      lv_obj_clear_state(objects.btn_load_local, LV_STATE_CHECKED);
      break;
    }
    case (29):        //Acc in use UN-Checked
    {
      break;
    }
    case (30):       //WiFi
    {
      reboot_req = false;
      if(wifi_enabled == true) lv_obj_add_state(objects.btn_wifi_enable, LV_STATE_CHECKED);
      loadScreen(SCREEN_ID_WI_FI);
      break;
    }
    case (31):       //Update
    {
      lcdBL = atoi(lv_textarea_get_text(objects.ta_tft_backlight));
      setBacklight(lcdBL);
      eeProm.begin("configs", false);
      if(lcdBL < MIN_BL) lcdBL = MIN_BL;
      eeProm.putUInt("lcdBL", lcdBL);
      timeout = atoi(lv_textarea_get_text(objects.ta_wifi_timeout));
      eeProm.putUInt("timeout", timeout);
      reAccel = atoi(lv_textarea_get_text(objects.ta_re_accel));
      eeProm.putUInt("reAccel", reAccel);
      funcCol = atoi(lv_textarea_get_text(objects.ta_func_col));
      eeProm.putUInt("funcCol", funcCol);
      threshold = atoi(lv_textarea_get_text(objects.ta_threshold));
      eeProm.putUInt("threshold", threshold);
//      if(lv_obj_get_state(objects.btn_roster) == LV_STATE_CHECKED) def_roster = true;
//      else def_roster = false;
//      eeProm.putBool("roster", def_roster);
      eeProm.end();
      break;
    }
    case (32):       //Done
    {
      if(reboot_req == true) ESP.restart();
      loadScreen(SCREEN_ID_MAIN);
      break;
    }
    default:
      break;
  }
//  }
}
