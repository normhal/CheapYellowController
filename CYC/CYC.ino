/*
 *****************************************************************************************************************************
 * Cheap Yellow Controller (CYC) DCC-EX Controller
 *
 *  Project written and developed by Norman Halland (normhal@gmail.com) 2025
 *
 *  Members of the Development and Testing team with their TrainBoard member IDs:-
 *  Steve   - esfeld
 *  Erik    - Erik84750
 *  Lee     - mtncityman
 *  Michele - michele2796
 *  Ideas, Input and Testing by all team members is Greatly appreciated!
 *
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
 *
 * This version is for a NON-DCCEXProtocol Throttle based on a selection of Cheap Yellow Display (CYD)
 * Variants. Supported ESP32 models are:
 *  2.8in Capacitive Touch 240x320 resolution   - Sunton ESP32-2432S028C - The original CYD:-)
 *  2.8in Resistive Touch 240x320 resolution   :- Sunton ESP32-2432S028R - The original CYD:-)
 *  3.2in Capacitive Touch 240x320 resolution  :- Sunton ESP32-2432S032C
 *  3.2in Resistive Touch 240x320 resolution   :- Sunton ESP32-2432S032R
 *  3.5in Capacitive Touch 320x480 resolution  :- Sunton ESP32-3248S035C
 *  3.5in Resistive Touch 320x480 resolution   :- Sunton ESP32-3248S035R
 *
 * Variant in use must be enabled by uncommenting its definition below beforeand then "Building" the correct resolution
 * EEZ Studio project. The "Build" will place the necessary source and header files in the folder of this Arduino sketch.
 *
 * Refer to the instructions in the ReadMe file of my GitHub repository for configuration and build options!
 *
 * https://github.com/normhal/CheapYellowController
 *
 * This first version is limited to Throttle functions only - no support for accessories and routes
 * A Fully featured Controller which includes Throttle and Accessory support is in development and planned as an upgrade
 *****************************************************************************************************************************

 30 April - Version 1.0.0 made publicly available
 12 May - Version 1.0.2 made available 
        - bug fixes 
        - correction of "strcpy" use
        - added "Stop" button functionality
        - Heading changed to "DCC-EX"
 6 June - Version 1.0.4 Started
 16 June - Version 1.0.5 Started
        - Code tested on ESP32 3.5 EEZ only
        -
        - Rotary Encoder Done with Accel
        - Function Button Width adjusted - not -able
        - WiFi initial connection bad, 2nd good
 14 July - Version 1.0.6 Started
        - WiFi Connection fixed - known quirk
        - "Preferences" library added

EEZ Studio Notes:
 Version 1.3.1
 - "WiFi Enable" Button changed to "Checked 10, Unchecked 9"
 - Config Page added "Rotary Encoder Enable" - "Checked 23, Unchecked 22"

Sketch Notes:
 Version 1.3.1
 - Suffix to Version indicates "Arrays" or "Vectors"
 - Included WiFi Enabled state to EEPROM
 - Included Rotary Enable Option in Config - saved to EEPROM
*******************************************************************************************************************************/
// Note: "t..." - not ready, "tick" = tested on physical device, "tock" = Batch file created and tested

//#define ESP2432S028C           //Sunton ESP32-2432S028C   Not Tested  ESP32     ticked 21 July
//#define ESP2432S028R           //Sunton ESP32-2432S028R               ESP32     Good - 14 August
//#define JC2432W328C             //Guition CYD                                   Good - 14 August
//#define ESP2432S032C           //Sunton ESP32-2432S032C               ESP32     Good - 14 August
//#define ESP2432S032R           //Sunton ESP32-2432S032R               ESP32     ticked 21 July
//#define ESP3248S035C           //Sunton ESP32-3248S035C               ESP32     ticked 21 July
//#define ESP3248S035R           //Sunton ESP32-3248S035R               ESP32     ticked 21 July  

//#define ESP2432THMIR           //LilyGo T-HMI                         ESP32-S3  ticked 21 July - No RE support yet
//#define ESP3248W535C           //Guition JC3248W535C                  ESP32-S3  ticked 16 June
//#define ESP4827S043C           //Sunton ESP32-4827S043C               ESP32-S3  ticked 21 July
//#define ESP4827S043R           //Sunton ESP32-4827S043R               ESP32-S3  ticked 21 July

//#define ESP32DIS06043H         // Elcrow ESP32-DIS06043H              ESP32-S3  t...   by RKS
//#define ESP32DIS08070H         // Elcrow ESP32-DIS08070H              ESP32-S3  t...   by RKS

//#define ESP4827W543C           //Guition JC4827W543C                  ESP32-S3  ticked 21 July
//#define ESP4827W543R           //Guition JC4827W543R                  ESP32-S3  ticked 21 July
//#define ESP4848S040C           //Guition JC4848W440C - in development
//#define ESP8048S043C           //Sunton ESP32-8048S043C               ESP32-S3  ticked 21 July
//#define ESP8048S050C           //Sunton ESP32-8048S050C               ESP32-S3  ticked 21 July
#define ESP8048W550C           //Guition JC8048W550C                  ESP32-S3  ticked 21 July
//#define ESP8048S070C           //Sunton ESP32-8048S050C               ESP32-S3  ticked 21 July

const char* build = "1.3.1V";

#define USE_VECTORS

//*****************************************************************************************************************************
// Don't modify anything below the above two sections
//*****************************************************************************************************************************

#include "CYC.h"
#include "credentials.h"

#if defined USE_VECTORS
  vector<accessory> Turnouts;
  vector<locomotive> Locomotives;
  #define NUM_ACCS Turnouts.size()
  #define NUM_LOCOS Locomotives.size()
#endif

uint32_t bufSize;

lv_disp_draw_buf_t draw_buf;
lv_color_t *disp_draw_buf;
lv_disp_drv_t disp_drv;

File file;
WiFiClient client;
DCCEXProtocol dccexProtocol;

class MyDelegate : public DCCEXProtocolDelegate 
{
public:
  void receivedServerVersion(int major, int minor, int patch) override 
  {
/*
    Serial.print("\n\nReceived version: ");
    Serial.print(major);
    Serial.print(".");
    Serial.print(minor);
    Serial.print(".");
    Serial.println(patch);
*/
  }

  void receivedTrackPower(TrackPower state) override 
  {
//    Serial.printf_P(PSTR ("Received Track Power: %d\n"), state);    //Nothing done with this yet:-()
  }

  void receivedRosterList() override 
  {
//    Serial.printf_P(PSTR ("Receiving DCC-EX Locos\n"));
    receiveDCCEXLocos(LittleFS, "/exlocos");     //, "ID,Name,Address\n");
//    Serial.println("DCC-EX Roster Received");
  }

  void receivedTurnoutList() override 
  {
//    Serial.printf_P(PSTR ("Receiving DCC-EX Turnouts\n"));
    receiveDCCEXAccs(LittleFS, "/exacc");
//    Serial.println("DCC-EX Turnouts Received");
  }

  void receivedRouteList() override 
  {
//    Serial.printf_P(PSTR ("\n\nReceived Routes List\n"));
//    printRoutes();
//    Serial.println("\n\n");
  }

  void receivedTurntableList() override 
  {
//    Serial.print("\n\nReceived Turntables list");
//    printTurntables();
//    Serial.println("\n\n");
  }
};

MyDelegate myDelegate;

/*
 ********************************************************************************************************
 * Call-Back routine for Textarea fields
 ********************************************************************************************************
*/
static void ta_event_cb(lv_event_t * e)
{
  lv_event_code_t code = lv_event_get_code(e);
  lv_obj_t * ta = lv_event_get_target(e);
  lv_obj_t * kb = (lv_obj_t *)lv_event_get_user_data(e);
  if(code == LV_EVENT_FOCUSED) 
  { 
    if(rosterMode != GUEST_ACTIVE)
    {
      lv_keyboard_set_textarea(kb, ta);
      lv_obj_clear_flag(kb, LV_OBJ_FLAG_HIDDEN);
    }
  }
  if(code == LV_EVENT_READY)
  {
    lv_keyboard_set_textarea(kb, NULL);
    lv_obj_add_flag(kb, LV_OBJ_FLAG_HIDDEN);
  }
}
/*
 ********************************************************************************************************
 * LVGL Display Flush
 ********************************************************************************************************
*/
void my_disp_flush( lv_disp_drv_t* disp_drv, const lv_area_t* area, lv_color_t* color_p ) 
{
//  #ifndef DIRECT_MODE
    uint32_t w = ( area->x2 - area->x1 + 1 );
    uint32_t h = ( area->y2 - area->y1 + 1 );

    #if ( LV_COLOR_16_SWAP != 0 ) 
      gfx->draw16bitBeRGBBitmap( area->x1, area->y1, ( uint16_t* )&color_p->full, w, h );
    #else
       gfx->draw16bitRGBBitmap( area->x1, area->y1, ( uint16_t* )&color_p->full, w, h );
    #endif
//  #endif
  lv_disp_flush_ready( disp_drv );
}
/*
 ********************************************************************************************************
 * Backlight Brightness Control
 ********************************************************************************************************
*/
void setBacklight(uint8_t brightness)
{
  ledcSetup(0, 5000, 8);                          //If using ESP Boards 2.0.x LEDChannel, frequency, resolution
  ledcAttachPin(GFX_BL, 0);                       //If using ESP Boards 2.0.x Pin, LEDChannel
  ledcWrite(0, lcdBL);                            //If using ESP Boards 2.0.x LEDChannel, Brightness* 0-255

//  ledcAttachChannel(GFX_BL, 5000, 8, 0);          //If using ESP Boards 3.x Pin, Frequency, Resolution, Channel
//  ledcWrite(GFX_BL, brightness);                  //If using ESP Boards 3.x Pin, Brightness
}
/*
 ********************************************************************************************************
 * Setup
 ********************************************************************************************************
*/
void setup()
{
  Serial.begin(115200);
  while (!Serial) delay(10);

  initEEPROM();

  #if defined ESP2432THMIR
    pinMode(10 /* PWD */, OUTPUT);
    digitalWrite(10 /* PWD */, HIGH);
  #endif

  if(re_enabled == true) initRE();                         //Initialize Rotary Encoder if Enabled in Display Driver

  //
  //*****************************************************************************************************
  // Read LittleFS data files and populate working arrays
  //*****************************************************************************************************
  //
  LittleFS.begin();

  // Set ALL Pre-Selected Loco IDs to unused (255)
  for(int i = 0; i < THROTTLE_COUNT; i++)
  {
    for(int j = 0; j < NUM_LOCO_SLOTS; j++)
    {
      selectedIDs[i][j] = 255;
    }
  }

  populateSelected("/throttleids.txt");
  populateCredentials("/credentials.txt");

  ssid = netwks[0].ssid;
  password = netwks[0].password;
  ipAddress = netwks[0].ipAddress;
  nwPort = netwks[0].nwPort;

  if (!gfx->begin())
  {
    Serial.println("gfx->begin() failed!");
  }
  gfx->fillScreen(RGB565_BLACK);

  initTouch();

  initAccMap();
  
  lv_init();

  #ifdef DIRECT_MODE
    bufSize = SCREEN_WIDTH * SCREEN_HEIGHT;
  #else
    bufSize = SCREEN_WIDTH * 40;
  #endif

/*
******************************************************************************************************************
* Set TFT Backlight Brightness - can be changed in the Relevant Display Driver
******************************************************************************************************************
*/
  #ifdef ESP32
    #if defined(DIRECT_MODE) && (defined(CANVAS) || defined(RGB_PANEL) || defined(DSI_PANEL))
      Serial.println("Using Frame Buffer");
      disp_draw_buf = (lv_color_t *)gfx->getFramebuffer();
    #else  // !(defined(DIRECT_MODE) && (defined(CANVAS) || defined(RGB_PANEL) || defined(DSI_PANEL)))
      Serial.println("NOT Using Frame Buffer");
      disp_draw_buf = (lv_color_t *)heap_caps_malloc(bufSize * 2, MALLOC_CAP_INTERNAL | MALLOC_CAP_8BIT);
      if (!disp_draw_buf)
      {
      // remove MALLOC_CAP_INTERNAL flag try again
       disp_draw_buf = (lv_color_t *)heap_caps_malloc(bufSize * 2, MALLOC_CAP_8BIT);
      }
    #endif // !(defined(DIRECT_MODE) && (defined(CANVAS) || defined(RGB_PANEL) || defined(DSI_PANEL)))
  #else // !ESP32
    Serial.println("LVGL disp_draw_buf heap_caps_malloc failed! malloc again...");
    disp_draw_buf = (lv_color_t *)malloc(bufSize * 2);
  #endif // !ESP32

  if (!disp_draw_buf)
  {
    Serial.println("LVGL disp_draw_buf allocate failed!");
  }
  else
  {
    lv_disp_draw_buf_init(&draw_buf, disp_draw_buf, NULL, bufSize);

    /* Initialize the display */
    lv_disp_drv_init(&disp_drv);
    disp_drv.hor_res = SCREEN_WIDTH;    //screenWidth;
    disp_drv.ver_res = SCREEN_HEIGHT;   //screenHeight;
    disp_drv.flush_cb = my_disp_flush;
    disp_drv.draw_buf = &draw_buf;
  #ifdef DIRECT_MODE
    disp_drv.direct_mode = true;
  #endif
    lv_disp_drv_register(&disp_drv);

    //Initialize the input device driver 
    static lv_indev_drv_t indev_drv;
    lv_indev_drv_init( &indev_drv );
    indev_drv.type = LV_INDEV_TYPE_POINTER;
    indev_drv.read_cb = my_touchpad_read;
    lv_indev_drv_register( &indev_drv );

//    gfx->flush();

    // Init EEZ-Studio UI
    ui_init();

    lv_obj_set_parent(objects.btn_stop, lv_layer_top());
    lv_obj_set_parent(objects.btn_power, lv_layer_top());
    lv_obj_set_parent(objects.btn_home, lv_layer_top());
    lv_obj_set_parent(objects.img_wifi, lv_layer_top());
    lv_obj_set_parent(objects.h_line, lv_layer_top());

    lv_textarea_add_text(objects.ta_password, netwks[0].password.c_str());
    lv_textarea_add_text(objects.ta_ip_address, netwks[0].ipAddress.c_str());
    char lvPort[5];
    itoa(netwks[0].nwPort, lvPort, 10);
    lv_textarea_add_text(objects.ta_port, lvPort);

    // Callback definitions - WiFi
    lv_obj_add_event_cb(objects.ta_ssid, ta_event_cb, LV_EVENT_ALL, objects.kb_alpha );
    lv_obj_add_event_cb(objects.ta_password, ta_event_cb, LV_EVENT_ALL, objects.kb_alpha );
    lv_obj_add_event_cb(objects.ta_ip_address, ta_event_cb, LV_EVENT_ALL, objects.kb_numeric );
    lv_obj_add_event_cb(objects.ta_port, ta_event_cb, LV_EVENT_ALL, objects.kb_numeric );
    lv_obj_add_event_cb(objects.dd_ssids, dd_cb, LV_EVENT_ALL, NULL);
    lv_obj_add_event_cb(objects.dd_locos, dd_locos_cb, LV_EVENT_ALL, NULL);

    // Callback definitions - Menu, Throttle, Roster
    lv_obj_add_event_cb(objects.menu_mtx, menu_cb, LV_EVENT_ALL, NULL);
    lv_obj_add_event_cb(objects.throttle_mtx, throttle_selection_handler_cb, LV_EVENT_ALL, NULL);
    lv_obj_add_event_cb(objects.functions_mtx, functions_cb, LV_EVENT_PRESSED, NULL);
    lv_obj_add_event_cb(objects.functions_mtx, functions_cb, LV_EVENT_RELEASED, NULL);
    lv_obj_add_event_cb(objects.ex_functions_mtx, ex_functions_cb, LV_EVENT_PRESSED, NULL);
    lv_obj_add_event_cb(objects.ex_functions_mtx, ex_functions_cb, LV_EVENT_RELEASED, NULL);
    lv_obj_add_event_cb(objects.track_mtx, track_cb, LV_EVENT_ALL, NULL);
    lv_obj_add_event_cb(objects.cv_mtx, cv_cb, LV_EVENT_ALL, NULL);
    lv_obj_add_event_cb(objects.acc_state_mtx, acc_cb, LV_EVENT_ALL, NULL);
    lv_obj_add_event_cb(objects.acc_name_mtx, acc_cb, LV_EVENT_ALL, NULL);

    // Callback definitions for Edit Loco  
    lv_obj_add_event_cb(objects.btn_s0,function_name_cb, LV_EVENT_ALL, NULL);
    lv_obj_add_event_cb(objects.btn_s1,function_name_cb, LV_EVENT_ALL, NULL);
    lv_obj_add_event_cb(objects.btn_s2,function_name_cb, LV_EVENT_ALL, NULL);
    lv_obj_add_event_cb(objects.btn_s3,function_name_cb, LV_EVENT_ALL, NULL);
    lv_obj_add_event_cb(objects.btn_s4,function_name_cb, LV_EVENT_ALL, NULL);
    lv_obj_add_event_cb(objects.btn_s5,function_name_cb, LV_EVENT_ALL, NULL);
    lv_obj_add_event_cb(objects.btn_s6,function_name_cb, LV_EVENT_ALL, NULL);
    lv_obj_add_event_cb(objects.btn_s7,function_name_cb, LV_EVENT_ALL, NULL);
    lv_obj_add_event_cb(objects.btn_s8,function_name_cb, LV_EVENT_ALL, NULL);
    lv_obj_add_event_cb(objects.btn_s9,function_name_cb, LV_EVENT_ALL, NULL);
    lv_obj_add_event_cb(objects.f_option,chkbox_event_cb, LV_EVENT_ALL, NULL);
    

    lv_obj_add_event_cb(objects.tbl_roster, tbl_roster_cb, LV_EVENT_VALUE_CHANGED, NULL);
    lv_obj_add_event_cb(objects.ta_name, ta_event_cb, LV_EVENT_ALL, objects.a_kbd_edit_loco );
    lv_obj_add_event_cb(objects.ta_address, ta_event_cb, LV_EVENT_ALL, objects.n_kbd_edit_loco );
    lv_obj_add_event_cb(objects.ta_fnum, ta_event_cb, LV_EVENT_ALL, objects.n_kbd_edit_loco );
    lv_obj_add_event_cb(objects.ta_fname, ta_event_cb, LV_EVENT_ALL, objects.a_kbd_edit_loco );
    lv_obj_add_event_cb(objects.ta_guest_address, ta_event_cb, LV_EVENT_ALL, objects.kbd_guest );

    lv_obj_add_event_cb(objects.ta_adr, ta_event_cb, LV_EVENT_ALL, objects.kbd_program );
    lv_obj_add_event_cb(objects.ta_cvn, ta_event_cb, LV_EVENT_ALL, objects.kbd_program );
    lv_obj_add_event_cb(objects.ta_cvv, ta_event_cb, LV_EVENT_ALL, objects.kbd_program );

    lv_obj_add_event_cb(objects.ta_tft_backlight, ta_event_cb, LV_EVENT_ALL, objects.kbd_config );
    lv_obj_add_event_cb(objects.ta_wifi_timeout, ta_event_cb, LV_EVENT_ALL, objects.kbd_config );
    lv_obj_add_event_cb(objects.ta_re_accel, ta_event_cb, LV_EVENT_ALL, objects.kbd_config );
    lv_obj_add_event_cb(objects.ta_func_col, ta_event_cb, LV_EVENT_ALL, objects.kbd_config );
    lv_obj_add_event_cb(objects.ta_threshold, ta_event_cb, LV_EVENT_ALL, objects.kbd_config );

    lv_obj_add_event_cb(objects.ta_acc_name, ta_event_cb, LV_EVENT_ALL, objects.a_kbd_acc );
    lv_obj_add_event_cb(objects.ta_acc_address, ta_event_cb, LV_EVENT_ALL, objects.n_kbd_acc );
    lv_obj_add_event_cb(objects.ta_acc_id, ta_event_cb, LV_EVENT_ALL, objects.n_kbd_acc );


    activeIndex = 0;              //Initialize the Index to the first in the SSID list
    CallingPage = 0;

  }
/*
******************************************************************************************************************
* Setup Rotary Encoder
******************************************************************************************************************
*/
/*
  eeProm.begin("configs", true);
  eeProm.getUInt("lcdBL",lcdBL);
  eeProm.getBool("roster", def_roster);
  eeProm.getBool("accList", def_acc); 
  eeProm.getBool("rEncoder", re_enabled); 
  eeProm.getBool("wiFiState", wifi_enabled); 
  eeProm.end();
*/
  Serial.printf("WiFi State from EEPROM: %d\n", wifi_enabled);

if(re_enabled == true)
{
  Serial.println("Looking for seesaw!");

  if (! ss.begin(SEESAW_ADDR)) Serial.println("Couldn't find seesaw on default address");
  else Serial.println("seesaw started");

  uint32_t version = ((ss.getVersion() >> 16) & 0xFFFF);
  if (version  != 4991)
  {
    Serial.print("Wrong firmware loaded? ");
    Serial.println(version);
  }
  else 
  {
    Serial.println("Found Product 4991");
    encoder_present = 1;
    ss.pinMode(SS_SWITCH, INPUT_PULLUP);
    encoder_position = 0;
    Serial.println("Turning on interrupts");
    delay(10);
    ss.setGPIOInterrupts((uint32_t)1 << SS_SWITCH, 1);
    ss.enableEncoderInterrupt();
  }
  re_timer = millis();
}

  if(wifi_enabled == true) connectWiFi();

  if(def_roster == true) 
  {
    setupDCCEXRoster();
    lv_label_set_text(objects.lbl_btn_roster, "DCC-EX");
  }
  else 
  {
    setupLocalRoster();
    lv_label_set_text(objects.lbl_btn_roster, "Local");
  }

  if(def_acc == true) 
  {
  //  Serial.println("Acc set to DCC-EX");
    setupDCCEXAcc();
    lv_label_set_text(objects.lbl_btn_acc, "DCC-EX");
  }
  else 
  {
  //  Serial.println("Acc set to Local");
    setupLocalAcc();
    lv_label_set_text(objects.lbl_btn_acc, "Local");
  }

  rosterMode = GUEST_INACTIVE;
  lv_table_set_col_width(objects.tbl_roster, 0, NAME_COL0_WIDTH);
  lv_table_set_col_width(objects.tbl_roster, 1, NAME_COL1_WIDTH);

  Serial.println("Setup Done!");
  lv_label_set_text(objects.lbl_sketch_build, build);

  setBacklight(lcdBL);
}
/*
 ********************************************************************************************************
 * Main Loop
 ********************************************************************************************************
*/
void loop() 
{
  lv_timer_handler();

//#if defined CANVAS
  gfx->flush();
//#endif

  dccexProtocol.check();

  if(re_enabled == true)
  {
  if(encoder_present)                       //Sample Rotary Encoder if it's been found:-)
  {
    if(!ss.digitalRead(SS_SWITCH))          //First check if the Direction Button has been pressed
    {
      if(RE_button_active != 1)             //Check if it's already been processed
      {
        RE_button_active = 1;
        if(Locomotives[activeLocoID].LocoDir == 1)      //Currently Forward?
        {
          lv_obj_clear_state(objects.sw_dir, LV_STATE_CHECKED);     // Do this because the TFT wasn't the source
          setLocoRev();                     //Change to Reverse
        }
        else
        { 
          lv_obj_add_state(objects.sw_dir, LV_STATE_CHECKED);
          setLocoFwd();
        }
      }
    }
    else RE_button_active = 0;              //Now clear the processed flag

    int32_t new_position = ss.getEncoderPosition();   //Now read the Encoder Position
    if (encoder_position != new_position)             //and see if it changed
    {
      if(new_position > 127)                          //make sure it's not greater than 127
      {
        ss.setEncoderPosition(127);                   //force the encoder to the max value
        new_position = 127;                           //and record the value
      }
      if(new_position < 0)                            //and make sure it hasn't gone beyond 0
      {
        ss.setEncoderPosition(0);
        new_position  = 0;
      }
      int32_t re_change = new_position - encoder_position;    //-ve = decrease
      unsigned long elapsed_time = millis() - re_timer;
      if(elapsed_time <= 200)
      {
        int32_t rate = (200-elapsed_time)/reAccel;
        new_position = new_position + (re_change * rate);
        if(new_position > 127) new_position = 127;
        if(new_position < 0) new_position = 0;
        ss.setEncoderPosition(new_position);
      } 
      Locomotives[activeLocoID].LocoSpeed = new_position; //update the Active loco
      setSpeed(atoi(Locomotives[activeLocoID].LocoAddress.c_str()), Locomotives[activeLocoID].LocoSpeed, Locomotives[activeLocoID].LocoDir); //and tell DCC-EX
      encoder_position = new_position;      // and save for next round
      re_timer = millis();
    }
  }
}
}
