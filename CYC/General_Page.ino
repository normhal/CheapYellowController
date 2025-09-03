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
      for(int i = 0; i < NUM_LOCOS; i++) 
      {
        if(Locomotives[i].LocoSpeed != 0)
        {
          Locomotives[i].LocoSpeed = 0;
          setSpeed(atoi(Locomotives[i].LocoAddress.c_str()), Locomotives[i].LocoSpeed, Locomotives[i].LocoDir);
        }
      }
      lv_label_set_text(objects.lbl_stop, "Go");
      lv_obj_add_state(objects.slider, LV_STATE_DISABLED);
      break;
    case 2: 
      lv_label_set_text(objects.lbl_stop, "Stop");
      lv_obj_clear_state(objects.slider, LV_STATE_DISABLED);
      break;
    case 3: 
      Serial.println("Power Off Pressed");
      if(lv_obj_get_state(objects.btn_power) == LV_STATE_CHECKED)
      {
        lv_label_set_text(objects.lbl_power, "Power On");
        if(!client.print("<0>")) lv_img_set_src(objects.img_wifi, &img_x);
        else lv_img_set_src(objects.img_wifi, &img_6);
      }
      break;
    case 4:
      Serial.println("Power On Pressed");
      if(lv_obj_get_state(objects.btn_power) != LV_STATE_CHECKED)
      {
        lv_label_set_text(objects.lbl_power, "Power Off");
        if(!client.print("<1>")) lv_img_set_src(objects.img_wifi, &img_x);
        else lv_img_set_src(objects.img_wifi, &img_6);
      }
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
