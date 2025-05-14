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
<<<<<<< HEAD
=======
      Serial.println("Stop Pressed");
>>>>>>> cf153c9fca4e59e98ebfc40db48edce251c7a667
      for(int i = 0; i < NUM_LOCOS; i++) 
      {
        if(locoSpeed[i] != 0)
        {
          locoSpeed[i] = 0;
          setSpeed(atoi(locoAddress[i]), locoSpeed[i], locoDir[i]);
        }
<<<<<<< HEAD
      lv_label_set_text(objects.lbl_stop, "Go");
=======
>>>>>>> cf153c9fca4e59e98ebfc40db48edce251c7a667
      lv_obj_add_state(objects.slider, LV_STATE_DISABLED);
      }
      break;
    case 2: 
      lv_label_set_text(objects.lbl_stop, "Stop");
      lv_obj_clear_state(objects.slider, LV_STATE_DISABLED);
      break;
    case 3: 
      lv_label_set_text(objects.lbl_power, "Power On");
<<<<<<< HEAD
      if(!client.print("<0>")) lv_img_set_src(objects.img_wifi, &img_x);
=======
//      powerState = 0;
      client.print("<0>");
>>>>>>> cf153c9fca4e59e98ebfc40db48edce251c7a667
      break;
    case 4:
      Serial.println("Power On Pressed");
      lv_label_set_text(objects.lbl_power, "Power Off");
<<<<<<< HEAD
      if(!client.print("<1 JOIN>")) lv_img_set_src(objects.img_wifi, &img_x);
=======
//      powerState = 1;
      client.print("<1 JOIN>");
>>>>>>> cf153c9fca4e59e98ebfc40db48edce251c7a667
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
