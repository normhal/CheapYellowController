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
void action_edit_acc_button(lv_event_t * e)
{
  void *user_data = lv_event_get_user_data(e);
  int pressedButton = *((int*)(&user_data));
  switch(pressedButton)
  {
    case 30:       //Cancel - ignore any changes
      loadScreen(callingPage);
      break;
    case 32:       //Done - apply any changes and set the Dirty flag
      Turnouts[editingID].AccName = lv_textarea_get_text(objects.ta_acc_name);
      Turnouts[editingID].AccAddress = lv_textarea_get_text(objects.ta_acc_address);;
      accessoriesDirty = 1;
      loadScreen(callingPage);
     break;
    default:
      break;
  }
}
