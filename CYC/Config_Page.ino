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
  int pressedButton = *((int*)(&user_data));
  switch(pressedButton)
  {
    case (28):        //Load EX-Rail Roster
    {
      lv_label_set_text(objects.lbl_roster, "EX-Rail Roster Requested");
      def_roster = true;
      eeProm.begin("configs", false);
      setupEXRailRoster();
      eeProm.putBool("roster", def_roster);
      Serial.printf("Roster set to: %d\n", def_roster);
      eeProm.end();
      lv_label_set_text(objects.lbl_roster, "EX-Rail Roster Loaded");
      break;
    }
    case (29):        //Retrieve EX-Rail Roster
    {
      lv_label_set_text(objects.lbl_roster, "Loading Local Roster");
      def_roster = false;
      eeProm.begin("configs", false);
      setupLocalRoster();
      eeProm.putBool("roster", def_roster);
      Serial.printf("Roster set to: %d\n", def_roster);
      eeProm.end();
      lv_label_set_text(objects.lbl_roster, "Local Roster Loaded");
      break;
    }
     case (30):       //WiFi
    {
      enum ScreensEnum callingPage = SCREEN_ID_CONFIG;
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
      loadScreen(SCREEN_ID_MAIN);
      break;
    }
    default:
      break;
  }
}
