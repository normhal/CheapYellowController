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
void action_wifi_button(lv_event_t * e)
{
  void *user_data = lv_event_get_user_data(e);
  int pressedButton = *((int*)(&user_data));
  switch(pressedButton)
  {
    case 1:     //Select
      break;
    case 2:     //Scan
      loadScreen(SCREEN_ID_SCAN);
      lv_label_set_text(objects.txt_scan_status, "Press Scan to Search");
      break;
    case 7:     //Connect
    {
      lv_label_set_text(objects.lbl_wifi_status, "Connecting to WiFi...");
      WiFi.begin(lv_textarea_get_text(objects.ta_ssid), lv_textarea_get_text(objects.ta_password));
      int timeOut = timeout;
      while (WiFi.status() != WL_CONNECTED)
      {
//        Serial.print(".");
        delay(200);
        timeOut = timeOut -1;
        if(timeOut <0)
        {
          lv_label_set_text(objects.lbl_wifi_status, "Timeout trying to Connect...");
          lv_img_set_src(objects.img_wifi, &img_x);
          lv_label_set_text(objects.lbl_ps2,"");
          break;
        }
      }
      if(WiFi.status() == WL_CONNECTED)
      {
        lv_label_set_text(objects.lbl_wifi_status, "Connected to WiFi!");
        lv_label_set_text(objects.lbl_wifi_status2, "Now connecting to DCCEX");
        lv_img_set_src(objects.img_wifi, &img_6);
        if(!client.connect(lv_textarea_get_text(objects.ta_ip_address), atoi(lv_textarea_get_text(objects.ta_port))))
        {
          lv_label_set_text(objects.lbl_wifi_status2, "Unable to Connect to DCCEX");
        }else 
        {
          lv_label_set_text(objects.lbl_wifi_status2, "Connected to DCCEX!");
          break;
        }
      }
      break;
    }
    case 8:     //Save
    {
      String ssidList = netwks[0].ssid;
      for(int i = 1; i < NUM_NWKS; i++)
      {
        if(netwks[i].ssid == "") break;
        ssidList += "\n" + netwks[i].ssid;
      }
//      Serial.println(ssidList);
      lv_dropdown_set_options(objects.dd_ssids, ssidList.c_str());
      lv_obj_add_event_cb(objects.dd_ssids, dd_cb, LV_EVENT_ALL, NULL);
      netwks[activeIndex].ssid = lv_textarea_get_text(objects.ta_ssid);
      netwks[activeIndex].password = lv_textarea_get_text(objects.ta_password);
      netwks[activeIndex].ipAddress = lv_textarea_get_text(objects.ta_ip_address);
      netwks[activeIndex].nwPort = lv_textarea_get_text(objects.ta_port);
      saveCredentials(LittleFS, "/credentials.new", "ID,SSID,Password,IPAddress,Port\n");
      break;
    }
    case 9:     //Enable
      LV_LOG_USER("Enable Button Pressed");
      break;
    case 30:       //Config
      char  str[4];
      itoa(brightness, str, 10);
      lv_textarea_set_text(objects.ta_tft_backlight, str);
      itoa(timeout, str, 10);
      lv_textarea_set_text(objects.ta_wifi_timeout, str);
      loadScreen(SCREEN_ID_CONFIG);
      break;
    case 31:       //Retry
        // Perform WiFi Retry
      break;
    case 32:       //Done
      loadScreen(SCREEN_ID_MAIN);
     break;
    default:
      break;
  }
}
/*
 ********************************************************************************************************
 * Call-Back routine for WiFi Dropdown
 ********************************************************************************************************
*/
void dd_cb(lv_event_t * e)
{
  lv_event_code_t code = lv_event_get_code(e);
  lv_obj_t * obj = lv_event_get_target(e);
  if(code == LV_EVENT_VALUE_CHANGED) 
  {
    int index = lv_dropdown_get_selected(objects.dd_ssids);
    lv_textarea_set_text(objects.ta_ssid, netwks[index].ssid.c_str());
    lv_textarea_set_text(objects.ta_password, netwks[index].password.c_str());
    lv_textarea_set_text(objects.ta_ip_address, netwks[index].ipAddress.c_str());
    lv_textarea_set_text(objects.ta_port, netwks[index].nwPort.c_str());
    activeIndex = index;
//    Serial.printf("Active Index = %d\n", activeIndex);
  }
}
/*
 ********************************************************************************************************
 * Handler for a Selected SSID from the list
 ********************************************************************************************************
*/
static void ssid_selected(lv_event_t * e)
{
  lv_event_code_t code = lv_event_get_code(e);
  lv_obj_t * obj = lv_event_get_target(e);
  if(code == LV_EVENT_CLICKED) 
  {
    LV_UNUSED(obj);
    //LV_LOG_USER("Clicked: %s", lv_list_get_btn_text(objects.list_scan_pg_ssids, obj));
//    Serial.print(lv_list_get_btn_text(objects.list_scan_pg_ssids, obj));
//    Serial.println(" selected");
    int i = 0;
    for(i = 0; i<= NUM_NWKS; i++)
    {
      if(netwks[i].ssid == "") break;
    }
    netwks[i].ssid = lv_list_get_btn_text(objects.list_scan_pg_ssids, obj);
    credentialsDirty = 1;
//    Serial.printf("Added to Index: %d\n", i);

    activeIndex = i;
//    lv_dropdown_set_text(objects.dd_ssids, netwks[ActiveIndex].ssid.c_str());
    lv_dropdown_set_text(objects.dd_ssids, "");
    lv_textarea_set_text(objects.ta_ssid, netwks[activeIndex].ssid.c_str());
    lv_textarea_set_text(objects.ta_password, netwks[activeIndex].password.c_str());
    lv_textarea_set_text(objects.ta_ip_address, netwks[activeIndex].ipAddress.c_str());
    lv_textarea_set_text(objects.ta_port, netwks[activeIndex].nwPort.c_str());

    loadScreen(SCREEN_ID_WI_FI);
  }
}
