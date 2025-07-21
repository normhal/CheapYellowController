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
static void menu_cb(lv_event_t * e)
{
  lv_event_code_t code = lv_event_get_code(e);
  lv_obj_t * obj = lv_event_get_target(e);
  if(code == LV_EVENT_VALUE_CHANGED) 
  {
    uint32_t menuItem = lv_btnmatrix_get_selected_btn(objects.menu_mtx);    //Retrieve the Selected Throttle number
    switch (menuItem)
    {
      case CONFIG:
        callingPage = SCREEN_ID_MAIN;
        char  str[2];
        eeProm.begin("configs");
        lcdBL = eeProm.getUInt("lcdBL", 20);
//        Serial.printf("LCD_BL Value: %d\n", lcdBL);
        itoa(lcdBL, str, 10);
        lv_textarea_set_text(objects.ta_tft_backlight, str);
        timeout = eeProm.getUInt("timeout", 10);
        itoa(timeout, str, 10);
        lv_textarea_set_text(objects.ta_wifi_timeout, str);
        reAccel = eeProm.getUInt("reAccel", 10);
        itoa(reAccel, str, 10);
        lv_textarea_set_text(objects.ta_re_accel, str);
        funcCol = eeProm.getUInt("funcCol", 90);
        itoa(funcCol, str, 10);
        lv_textarea_set_text(objects.ta_func_col, str);
        threshold = eeProm.getUInt("threshold", 15);
        itoa(threshold, str, 10);
        lv_textarea_set_text(objects.ta_threshold, str);
        def_roster = eeProm.getBool("roster", false);
        if(def_roster == false) lv_obj_clear_state(objects.btn_roster, LV_STATE_CHECKED);
        else lv_obj_add_state(objects.btn_roster, LV_STATE_CHECKED);
        loadScreen(SCREEN_ID_CONFIG);  
        eeProm.end();
        break;
      case ROSTER:
        callingPage = SCREEN_ID_MAIN;
        loadScreen(SCREEN_ID_ROSTER);  
        break;
      case ACC:
        callingPage = SCREEN_ID_MAIN;
        loadScreen(SCREEN_ID_ACCESSORIES);  
        break;
      case PROGRAM:
        callingPage = SCREEN_ID_MAIN;
        loadScreen(SCREEN_ID_PROGRAM);  
        break;
      case WIFI:
      {
        ssidList = netwks[0].ssid;
        for(int i = 1; i <= NUM_NWKS; i++)
        {
          if(netwks[i].ssid == "") break;
          ssidList += "\n" + netwks[i].ssid;
        }
        Serial.println(ssidList);
        lv_dropdown_set_options(objects.dd_ssids, ssidList.c_str());
        lv_textarea_set_text(objects.ta_ssid, netwks[activeIndex].ssid.c_str());
        lv_textarea_set_text(objects.ta_password, netwks[activeIndex].password.c_str());
        lv_textarea_set_text(objects.ta_ip_address , netwks[activeIndex].ipAddress.c_str());
        char lvPort[5];
        itoa(netwks[activeIndex].nwPort, lvPort, 10);
        lv_textarea_set_text(objects.ta_port, lvPort);
        loadScreen(SCREEN_ID_WI_FI);  
        break;
      }
      case ROUTES:
//        loadScreen(SCREEN_ID_ROUTES);  
        break;
      case SAVE:
        saveLittleFS();
        break;
      case RESTORE:
        restoreLittleFS();
        break;
      default:
        break;
    }
  }
}

void action_menu_button(lv_event_t * e)
{
//  callingPage = SCREEN_ID_MAIN;
  void *user_data = lv_event_get_user_data(e);
  lv_event_code_t code = lv_event_get_code(e);
  int pressedButton = *((int*)(&user_data));
  if(code == LV_EVENT_CLICKED)
  {
    switch(pressedButton)
    {
      case 30:       //Credits
        loadScreen(SCREEN_ID_CREDITS);  
        break;
      case 32:       //Info
        loadScreen(SCREEN_ID_INFO);  
        break;
      default:       //Stray
        break;
    }
  }
}
