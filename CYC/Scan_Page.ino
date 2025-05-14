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
void action_scan_button(lv_event_t * e)
{
  void *user_data = lv_event_get_user_data(e);
  int pressedButton = *((int*)(&user_data));
  switch(pressedButton)
  {
    case 1:
    {
//        Serial.println("Clearing Last List");
        for(int i = 0; i< NUM_NWKS; i++) foundWiFiList[i]  = "";
//        Serial.println("Scanning for Networks...");
        int n = WiFi.scanNetworks();
//        Serial.print("Networks Found: ");
//        Serial.println(n);
        lv_label_set_text(objects.txt_scan_status, "Select Desired SSID");
        delay(10);
        for (int i = 0; i < n; ++i) 
        {
            String item = WiFi.SSID(i) + " (" + WiFi.RSSI(i) + ") " + ((WiFi.encryptionType(i) == WIFI_AUTH_OPEN) ? " " : "*");
            foundWiFiList[i] = item;
//            Serial.println(item);
            lv_obj_t * btn;
            btn = lv_list_add_btn(objects.list_scan_pg_ssids, LV_SYMBOL_WIFI, WiFi.SSID(i).c_str());
            lv_obj_add_event_cb(btn, ssid_selected, LV_EVENT_CLICKED, NULL);
        }
      break;
    }
    case 2:
      lv_label_set_text(objects.txt_scan_status, "Scanning...");
      break;
    case 30:       //Cancel
      loadScreen(SCREEN_ID_WI_FI);
      break;
    case 32:       //Done
    {
      loadScreen(SCREEN_ID_WI_FI);
      break;
    }
    default:
      break;
  }
}
/*
#ifdef __cplusplus
}
#endif
*/
