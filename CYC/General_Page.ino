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
void action_general_button(lv_event_t * e)
{
  void *user_data = lv_event_get_user_data(e);
  int pressedButton = *((int*)(&user_data));
  switch(pressedButton)
  {
    case 1: 
      Serial.println("Stop Pressed");
      lv_label_set_text(objects.lbl_stop, "Go");
      break;
    case 2: 
      Serial.println("Go Pressed");
      lv_label_set_text(objects.lbl_stop, "Stop");
      break;
    case 3: 
      Serial.println("Power Off Pressed");
      lv_label_set_text(objects.lbl_power, "Power On");
      powerState = 0;
      client.print("<0>");
      break;
    case 4:
      Serial.println("Power On Pressed");
      lv_label_set_text(objects.lbl_power, "Power Off");
      powerState = 1;
      client.print("<1 JOIN>");
      break;
    case 5:
      Serial.println("DCC++EX Pressed");
      loadScreen(SCREEN_ID_MAIN);
      break;
    case 6:
      loadScreen(SCREEN_ID_CREDITS);
      break;
    case 8:
      loadScreen(SCREEN_ID_INFO);
      break;
    default:
      break;
  }
}
