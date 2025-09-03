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
void receiveCMD()
{
  char c;
  while(client.available()>0)
  {                                                      // while there is data on the serial line
    c=client.read();
    if(c=='<') sprintf(commandString,"");                //Don't store the "<"
    else if(c=='>') parse(commandString);                //Also strip off the ">" and parse the received String
    else if(strlen(commandString)<MAX_COMMAND_LENGTH)    // if commandString still has space, append character just read from serial line
      sprintf(commandString,"%s%c",commandString,c);     // otherwise, character is ignored (but continue to look for '<' or '>')
  }
}
/*
 ***************************************************
 * Parse Data received from the Command Station
 * This code is intended to grow as more integration 
 * with the Command Station is included
 ***************************************************
*/
void parse(char *com)
{
  switch(com[0])
  {
    case 'p':       //Power Command Received from Command Station
    {
      String msg = com;
      if(msg == "p1") lv_obj_clear_state(objects.btn_power, LV_STATE_CHECKED);
      if(msg == "p0") lv_obj_add_state(objects.btn_power, LV_STATE_CHECKED);
      break;
    }
    case 'r':       //Response to Programming Track "Read" command
    {
      if(replyExpected == 1)
      {
        char * token = strtok(com, " ");                //First Token = r
        while(token != NULL)
        {
          if(String(token).startsWith("-1"))
          {
            Serial.printf_P(PSTR ("Bad Message: %s\n"), token);
            lv_label_set_text(objects.lbl_ps2, "Read Unsuccessful");
            token = "";
            lv_obj_clear_state(objects.btn_read, LV_STATE_CHECKED);
            break;
          }
          Serial.printf_P(PSTR ("Token: %s\n"), token);
          lv_label_set_text(objects.lbl_ps2, "Read Successful");
          lv_textarea_set_text(objects.ta_adr, token);
          lv_obj_clear_state(objects.btn_read, LV_STATE_CHECKED);
          token = strtok(NULL," ");                       //Second Token = cvv
        }  
        replyExpected = 0;
      }
      break;
    }
    case 'v':       //Response to Programming Track "Read" command
    {
      if(replyExpected == 1)
      {
        char * token = strtok(com, " ");                            //First Token = v
//        Serial.printf("Received v Message: %s\n", token);
        token = strtok(NULL, " ");                                  //Second Token = cvn
//        Serial.printf("Received cvn Message: %s\n", token);           
        token = strtok(NULL, " ");                                  //Third Token = cvv
//        Serial.printf("Received cvv Message: %s\n", token);           
        if(String(token).startsWith("-1"))
        {
//          Serial.printf("Bad Read: %s\n", token);
          lv_label_set_text(objects.lbl_ps2, "Read Unsuccessful");
          lv_obj_clear_state(objects.btn_read, LV_STATE_CHECKED);
          break;
        }
        lv_label_set_text(objects.lbl_ps2, "Read Successful");
        lv_textarea_set_text(objects.ta_cvv, token);
        lv_obj_clear_state(objects.btn_read, LV_STATE_CHECKED);
        replyExpected = 0;
      }
      break;
    }
    case 'w':
    {
      char * token = strtok(com, " ");
      Serial.printf_P(PSTR ("Received w message: %s\n"), token);
      token = strtok(NULL, " ");
      if(String(token).startsWith("-1"))
      {
        Serial.printf_P(PSTR ("Received Nack Message: %s\n"), token);
        lv_label_set_text(objects.lbl_ps2, "Write Unsuccessful");
        lv_obj_clear_state(objects.btn_write, LV_STATE_CHECKED);
      }
      break;
    }
    default:
      break;
  }
}