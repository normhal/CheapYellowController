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
    case (30):       //WiFi
    {
      enum ScreensEnum callingPage = SCREEN_ID_CONFIG;
      loadScreen(SCREEN_ID_WI_FI);
      break;
    }
    case (31):       //Update
    {
      brightness = atoi(lv_textarea_get_text(objects.ta_tft_backlight));
      setBacklight(brightness);
      timeout = atoi(lv_textarea_get_text(objects.ta_wifi_timeout));
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
