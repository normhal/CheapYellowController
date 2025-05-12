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
 * This version is for a NON-DCCEX Protocol Throttle based on a selection of Cheap Yellow Display (CYD)
 * Variants. Supported models are:
 *  2.8in Resistive Touch 240x320 resolution   :- Sunton ESP32-2432S028R - The original CYD:-)
 *  2.8in Resistive Touch 240x320 resolution   :- LilyGo ESP32 T-HMI
 *  3.2in Resistive Touch 240x320 resolution   :- Sunton ESP32-2432S032R - Not tested
 *  3.2in Capacitive Touch 240x320 resolution  :- Sunton ESP32-2432S032C - Not tested
 *  3.5in Resistive Touch 320x480 resolution   :- Sunton ESP32-3248S035R
 *  3.5in Capacitive Touch 320x480 resolution  :- Sunton ESP32-3248S035C
 *  3.5in Capacitive Touch 320x480 resolution  :- Guition JC3248W535C - in development
 *  4.0in Capacitive Touch 480x480 resolution  :- Guition JC4848W040C - in development
 *  4.3in Resistive Touch 272x480 resolution   :- Sunton ESP32-2748S043R
 *  4.3in Capacitive Touch 272x480 resolution  :- Sunton ESP32-2748S043C
 *  4.3in Capacitive Touch 272x480 resolution  :- Guition JC2748W435C - in development
 *  4.3in Capacitive Touch 480x800 resolution  :- Sunton ESP32-8048S043C
 *  5.0in Capacitive Touch 480x800 resolution  :- Sunton ESP32-8048S050C
 *  5.0in Capacitive Touch 480x800 resolution  :- Guition JC8048W550C
 *  7.0in model is likely to function, but is not actively supported
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

*******************************************************************************************************************************/

//#define ESP2432S028R           // Sunton ESP32-2432S028R Classic CYD  tick
//#define ESP2432THMIR           //LilyGo T-HMI                         tick
//#define ESP3248S035R           // Sunton ESP32-3248S035R              tick
//#define ESP3248S035C           // Sunton ESP32-3248S035C              tick
//#define ESP3248W535C           //Guition JC3248W535C - in testing
//#define ESP4827S043R           // Sunton ESP32-4827S043R              tick
//#define ESP4827S043C           // Sunton ESP32-4827S043C              tick
//#define ESP4827W543R           //Guition JC4827W543R - in testing
//#define ESP4827W543C           //Guition JC4827W543C - in testing
//#define ESP4848S040C           //Guition JC4848W440C - in development
//#define ESP8048S043C           // Sunton ESP32-8048S043C              tick  
#define ESP8048S050C           // Sunton ESP32-8048S050C              tick
//#define ESP8048W550C           //Guition JC8048W550C                  tick         

/******************************************************************************************************************************/

#include "CYC.h"

uint32_t bufSize;

lv_disp_draw_buf_t draw_buf;
lv_color_t *disp_draw_buf;
lv_disp_drv_t disp_drv;

File file;

#if LV_USE_LOG != 0
/* Serial debugging */
void my_print(const char * buf)
{
  Serial.printf(buf);
  Serial.flush();
}
#endif
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
  ledcWrite(0, brightness);                       //If using ESP Boards 2.0.x LEDChannel, Brightness* 0-255

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

  #if defined ESP2432THMIR
    pinMode(10 /* PWD */, OUTPUT);
    digitalWrite(10 /* PWD */, HIGH);
  #endif

  // Init Display
  if (!gfx->begin())
  {
    Serial.println("gfx->begin() failed!");
  }
  gfx->fillScreen(RGB565_BLACK);

  //touch_init(SCREEN_WIDTH, SCREEN_HEIGHT, ROTATION);
  initTouch();

  lv_init();

  #ifdef DIRECT_MODE
    bufSize = DISPLAY_WIDTH * DISPLAY_HEIGHT;
  #else
    bufSize = DISPLAY_WIDTH * 40;
  #endif

  #ifdef ESP32
    #if defined(DIRECT_MODE) && (defined(CANVAS) || defined(RGB_PANEL) || defined(DSI_PANEL))
      disp_draw_buf = (lv_color_t *)gfx->getFramebuffer();
    #else  // !(defined(DIRECT_MODE) && (defined(CANVAS) || defined(RGB_PANEL) || defined(DSI_PANEL)))
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

    // Init EEZ-Studio UI
    ui_init();

    lv_obj_set_parent(objects.btn_stop, lv_layer_top());
    lv_obj_set_parent(objects.btn_power, lv_layer_top());
    lv_obj_set_parent(objects.btn_home, lv_layer_top());
    lv_obj_set_parent(objects.img_wifi, lv_layer_top());
    lv_obj_set_parent(objects.h_line, lv_layer_top());

    lv_textarea_add_text(objects.ta_password, netwks[0].password.c_str());
    lv_textarea_add_text(objects.ta_ip_address, netwks[0].ipAddress.c_str());
    lv_textarea_add_text(objects.ta_port, netwks[0].nwPort.c_str());

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
    lv_obj_add_event_cb(objects.function_mtx, functions_cb, LV_EVENT_PRESSED, NULL);
    lv_obj_add_event_cb(objects.function_mtx, functions_cb, LV_EVENT_RELEASED, NULL);
    lv_obj_add_event_cb(objects.track_mtx, track_cb, LV_EVENT_ALL, NULL);
    lv_obj_add_event_cb(objects.cv_mtx, cv_cb, LV_EVENT_ALL, NULL);

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

    activeIndex = 0;              //Initialize the Index to the first in the SSID list
    CallingPage = 0;

    // Set ALL Pre-Selected Loco IDs to unused (255)
    for(int i = 0; i < THROTTLE_COUNT; i++)
    {
      for(int j = 0; j < NUM_LOCO_SLOTS; j++)
      {
        selectedIDs[i][j] = 255;
      }
    }
    //
    //*****************************************************************************************************
    // Read all LittleFS data files and populate working arrays
    //*****************************************************************************************************
    //
    LittleFS.begin();

    delay(100);

    Serial.println("Now loading Selected Loco IDs");
    populateSelected("/throttleids.txt");

    delay(100);

    Serial.println("Now populating Locos...");
    populateLocoArray("/locos.txt");

    // Set all function numbers to 255
    for(int i = 0; i < NUM_LOCOS; i++)
    {
      for(int j = 0; j < NUM_FUNC_SLOTS; j++) strcpy(funcNumber[i][j], "255");
    }
  
    Serial.println("Now populating Functions");
    populateLocoFunctions("/functions.txt");

    Serial.println("Now loading List of Credentials");
    populateCredentials("/credentials.txt");
    
    Serial.println("Now Populating the Roster...");
    for(int i = 0; i < locoCount; i++)
    {
      lv_table_set_cell_value(objects.tbl_roster, i, 0, locoName[i]);
      lv_table_set_cell_value(objects.tbl_roster, i, 1, locoAddress[i]);
    }
    Serial.println("Roster Populated");

    rosterMode = GUEST_INACTIVE;

    lv_table_set_col_width(objects.tbl_roster, 0, NAME_COL_WIDTH);
/*
******************************************************************************************************************
* Set TFT Backlight Brightness - can be changed in the Relevant Display Driver
******************************************************************************************************************
*/
    setBacklight(brightness);
  }
  Serial.println("Setup Done!");
}
/*
 ********************************************************************************************************
 * Main Loop
 ********************************************************************************************************
*/
void loop() 
{
  lv_timer_handler();

  ui_tick();

  gfx->flush();

  receiveCMD();
}
