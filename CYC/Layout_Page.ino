
void action_turnout_button(lv_event_t * e)
{
  void *user_data = lv_event_get_user_data(e);
  lv_event_code_t code = lv_event_get_code(e);
  lv_obj_t * btn = lv_event_get_target(e);
  lv_obj_t * label = lv_obj_get_child(btn, 0);
  int turnoutButton = *((int*)(&user_data));

  if(lv_obj_get_state(objects.edit_button) == LV_STATE_CHECKED && turnoutButton != 31)    //Check if EDIT button is CHECKED AND a Turnout pressed
  {
    callingPage = SCREEN_ID_LAYOUT;
    editingID = atoi(lv_label_get_text(label));
    lv_textarea_set_text(objects.ta_acc_id,lv_label_get_text(label));
    lv_textarea_set_text(objects.ta_acc_address, Turnouts[editingID].AccAddress.c_str());
    lv_textarea_set_text(objects.ta_acc_name, Turnouts[editingID].AccName.c_str());
    lv_obj_clear_state(btn, LV_STATE_CHECKED);    //Clear the state of the Turnout button
    loadScreen(SCREEN_ID_EDIT_ACC);
  }else
  {
    switch(turnoutButton)
    {
      case 0:       //Un-Checked
      case 1:       //Checked
      {
        String accCMD = ("<a " + String(Turnouts[atoi(lv_label_get_text(label))].AccAddress) + " " + String(turnoutButton) + "> ");
        Serial.println(accCMD);
        if(!client.print(accCMD)) Serial.println("Transmit Failed:-(");
        int accID = atoi(lv_label_get_text(label));
        Turnouts[accID].AccState = turnoutButton;
        break;
      }
      case 30:       //Cancel
        loadScreen(SCREEN_ID_MAIN);  
        break;
      case 31:        //Edit Button
        break;
      case 32:       //Done
        loadScreen(SCREEN_ID_MAIN);  
        break;
      default:      
        break;
    }
  }
}
