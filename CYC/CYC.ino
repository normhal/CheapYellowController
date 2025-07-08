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
// Note: "t..." - not ready, "tick" = tested on physical device, "tock" = Batch file created and tested

//#define ESP2432S028R           // Sunton ESP32-2432S028R Classic CYD  ESP32     ticked 16 June
//#define ESP2432THMIR           //LilyGo T-HMI                         ESP32-S3  t...
//#define ESP2432S032R           // Sunton ESP32-2432S032R              ESP32     ticked 16 June
//#define ESP2432S032C           // Sunton ESP32-2432S032C  Planned     ESP32
//#define ESP3248S035C           // Sunton ESP32-3248S035C              ESP32     ticked 16 June
//#define ESP3248S035R           // Sunton ESP32-3248S035R              ESP32     ticked 16 June  
//#define ESP3248W535C            //Guition JC3248W535C                 ESP32-S3  ticked 16 June
#define ESP4827S043C           // Sunton ESP32-4827S043C              ESP32-S3  ticked 16 June
//#define ESP4827S043R           // Sunton ESP32-4827S043R              ESP32-S3  ticked 16 June

//#define ESP32DIS06043H         // Elcrow ESP32-DIS06043H              ESP32-S3  t...   by RKS
//#define ESP32DIS08070H         // Elcrow ESP32-DIS08070H              ESP32-S3  t...   by RKS

//#define ESP4827W543C           //Guition JC4827W543C                  ESP32-S3  ticked 16 June
//#define ESP4827W543R           //Guition JC4827W543R                  ESP32-S3  ticked 16 June
//#define ESP4848S040C           //Guition JC4848W440C - in development
//#define ESP8048S043C           // Sunton ESP32-8048S043C              ESP32-S3  ticked 16 June
//#define ESP8048S050C           // Sunton ESP32-8048S050C              ESP32-S3  ticked 16 June
//#define ESP8048W550C           //Guition JC8048W550C                  ESP32-S3  ticked 16 June

//*****************************************************************************************************************************
// Rotary Encoder Compile Inclusion
//*****************************************************************************************************************************
// IMPORTANT NOTES REGARDING ROTARY ENCODER CONNECTIONS
//
//#define ROTARY_ENCODER                //Un-Comment to include Rotary Encoder Support

//*****************************************************************************************************************************
// Don't modify anything below the above two sections
//*****************************************************************************************************************************

#include <DCCEXProtocol.h>
#include <WiFi.h>

#include "credentials.h"

void printRoster();
void printTurnouts();
void printRoutes();
void printTurntables();

//static void ex_functions_cb(lv_event_t * e);
//static void functions_cb(lv_event_t * e);

#include "CYC.h"


DCCEXProtocol dccexProtocol;

// Delegate class
class MyDelegate : public DCCEXProtocolDelegate {

public:
  void receivedServerVersion(int major, int minor, int patch) override {
    Serial.print("\n\nReceived version: ");
    Serial.print(major);
    Serial.print(".");
    Serial.print(minor);
    Serial.print(".");
    Serial.println(patch);
  }

  void receivedTrackPower(TrackPower state) override {
    Serial.print("\n\nReceived Track Power: ");
    Serial.println(state);
    Serial.println("\n\n");
  }

  void receivedRosterList() override 
  {
    Serial.println("\n\nReceived Roster");
    uint16_t lId = 0;
    for (Loco *loco = dccexProtocol.roster->getFirst(); loco; loco = loco->getNext()) 
    {
      //First the Loco Name
      const char *lName = loco->getName();
      strcpy(locoNames[lId], lName);
      Serial.println();
      Serial.printf("Name: %s ", lName);
    
      //Then the Loco Address
      std::string s = std::to_string(loco->getAddress());
      const char* lAddr = s.c_str();
      strcpy(locoAddress[lId], lAddr);
      Serial.printf("Address: %s\n", lAddr);
      lv_table_set_cell_value(objects.tbl_roster, lId, 0, locoNames[lId]);
      lv_table_set_cell_value(objects.tbl_roster, lId, 1, locoAddress[lId]);

      //Now for the Functions
      uint8_t sN = 0;                      //Function Slot Number
      for (int fN = 0; fN < 28; fN++) 
      {
        funcSlots[lId][fN] = 255;
        const char *fName = loco->getFunctionName(fN);
        if(fName != NULL) 
        {
          if(fName[0] != '\0')          //This is to block an unused function
          {
            Serial.printf("Function Name: %s Number: %d Slot: %d\n", fName, fN, sN);
            strcpy(funcNames[lId][fN], fName);
            funcSlots[lId][fN] = sN;                                                                          //Check this
            if(sN < NUM_FUNCS) sN++;
          }
//          else funcSlots[lId][fN] = 255;
        }
      }
      lId++;
    }
    lv_label_set_text(objects.lbl_roster, "EX-Rail Roster Received");
  }


  void receivedTurnoutList() override 
  {
    Serial.print("\n\nReceived Turnouts/Points list");
//    printTurnouts();
    Serial.println("\n\n");
  }
  void receivedRouteList() override {
    Serial.print("\n\nReceived Routes List");
//    printRoutes();
    Serial.println("\n\n");
  }
  void receivedTurntableList() override {
    Serial.print("\n\nReceived Turntables list");
//   printTurntables();
    Serial.println("\n\n");
  }
};

WiFiClient client;
MyDelegate myDelegate;

void printRoster() 
{
  uint16_t lId = 1;      //Start at 1
  for (Loco *loco = dccexProtocol.roster->getFirst(); loco; loco = loco->getNext()) 
  {
    uint16_t lAd = loco->getAddress();
    const char *lName = loco->getName();
    Serial.printf("\nLoco ID: %d Address: %d Name: %s\n", lId, lAd, lName);
    uint8_t sN = 0;                      //Function Slot Number
    for (uint8_t fN = 0; fN < 32; fN++) 
    {
      const char *fName = loco->getFunctionName(fN);
      if(fName != NULL) 
      {
        if(fName[0] != '\0')          //This is to block an unused function
        {
          Serial.printf("Button Enabled: %d ", fN);
          if(loco->isFunctionOn(fN)) Serial.println("Set to CHECKED");
          else Serial.println("Left UNCHECKED");
//          lv_btnmatrix_clear_btn_ctrl(objects.ex_functions_mtx, fN, LV_BTNMATRIX_CTRL_DISABLED);
//          if(loco->isFunctionOn(fN)) lv_btnmatrix_set_btn_ctrl(objects.ex_functions_mtx, fN, LV_BTNMATRIX_CTRL_CHECKED);
          if(sN < NUM_FUNCS)
          {
            Serial.printf("Function Name: %s Number: %d\n", fName, fN);
            strcpy(funcNames[lId][sN], fName);
//            funcNumber[lId][sN] = fN;
            sN++;
          }
          Serial.println(loco->isFunctionOn(fN));
          Serial.println(loco->isFunctionMomentary(fN));
          Serial.println(loco->getFunctionStates());
        }
      }
    }
    lId++;
    Serial.println();
  }
}

void printTurnouts() {
  for (Turnout *turnout = dccexProtocol.turnouts->getFirst(); turnout; turnout = turnout->getNext()) {
    int id = turnout->getId();
    const char *name = turnout->getName();
    Serial.print(id);
    Serial.print(" ~");
    Serial.print(name);
    Serial.println("~");
  }
  Serial.println("\n");
}

void printRoutes() {
  for (Route *route = dccexProtocol.routes->getFirst(); route; route = route->getNext()) {
    int id = route->getId();
    const char *name = route->getName();
    Serial.print(id);
    Serial.print(" ~");
    Serial.print(name);
    Serial.println("~");
  }
  Serial.println("\n");
}

void printTurntables() {
  for (Turntable *turntable = dccexProtocol.turntables->getFirst(); turntable; turntable = turntable->getNext()) {
    int id = turntable->getId();
    const char *name = turntable->getName();
    Serial.print(id);
    Serial.print(" ~");
    Serial.print(name);
    Serial.println("~");

    int j = 0;
    for (TurntableIndex *turntableIndex = turntable->getFirstIndex(); turntableIndex;
         turntableIndex = turntableIndex->getNextIndex()) {
      const char *indexName = turntableIndex->getName();
      Serial.print("  index");
      Serial.print(j);
      Serial.print(" ~");
      Serial.print(indexName);
      Serial.println("~");
      j++;
    }
  }
  Serial.println("\n");
}

File file;

uint32_t bufSize;

lv_disp_draw_buf_t draw_buf;
lv_color_t *disp_draw_buf;
lv_disp_drv_t disp_drv;

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
  while (!Serial) delay(10);

  #if defined ESP2432THMIR
    pinMode(10 /* PWD */, OUTPUT);
    digitalWrite(10 /* PWD */, HIGH);
  #endif

#if  defined ROTARY_ENCODER
  initRE();                         //Initialize Rotary Encoder if Enabled in Display Driver
#endif

  if (!gfx->begin())
  {
    Serial.println("gfx->begin() failed!");
  }
  gfx->fillScreen(RGB565_BLACK);

  initTouch();

  lv_init();

  #ifdef DIRECT_MODE
    bufSize = SCREEN_WIDTH * SCREEN_HEIGHT;
  #else
    bufSize = SCREEN_WIDTH * 40;
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

    // Callback definitions - Menu, Throttle, Functions, Roster
    lv_obj_add_event_cb(objects.menu_mtx, menu_cb, LV_EVENT_ALL, NULL);
    lv_obj_add_event_cb(objects.throttle_mtx, throttle_selection_handler_cb, LV_EVENT_ALL, NULL);
    lv_obj_add_event_cb(objects.functions_mtx, functions_cb, LV_EVENT_PRESSED, NULL);
    lv_obj_add_event_cb(objects.functions_mtx, functions_cb, LV_EVENT_RELEASED, NULL);
    lv_obj_add_event_cb(objects.ex_functions_mtx, ex_functions_cb, LV_EVENT_PRESSED, NULL);
    lv_obj_add_event_cb(objects.ex_functions_mtx, ex_functions_cb, LV_EVENT_RELEASED, NULL);
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
    delay(1000);

  Serial.println("Connecting to WiFi..");
  WiFi.begin(ssid, password);
  delay(1000);
  if(WiFi.status() != WL_CONNECTED) Serial.println("WiFi NOT Connected"); 
  else Serial.print("Connected with IP: ");
  Serial.println(WiFi.localIP());
  lv_img_set_src(objects.img_wifi, &img_6);
  Serial.println("Connecting to the server...");
  if (!client.connect(serverAddress, serverPort)) 
  {
    Serial.println("connection failed");
    lv_img_set_src(objects.img_wifi, &img_x);//    while (1)
//      delay(1000);
  }
  Serial.println("Connected to the server");

    LittleFS.begin();

    delay(100);

    Serial.println("Now loading Selected Loco IDs");
    populateSelected("/throttleids.txt");

    delay(100);

    Serial.println("Now loading List of Credentials");
    populateCredentials("/credentials.txt");
    
    delay(100);

    setupLocalRoster();

    rosterMode = GUEST_INACTIVE;

    lv_table_set_col_width(objects.tbl_roster, 0, NAME_COL0_WIDTH);
    lv_table_set_col_width(objects.tbl_roster, 1, NAME_COL1_WIDTH);
/*
******************************************************************************************************************
* Set TFT Backlight Brightness - can be changed in the Relevant Display Driver
******************************************************************************************************************
*/
    setBacklight(TFT_BACKLIGHT);
  }
/*
******************************************************************************************************************
* Setup Rotary Encoder
******************************************************************************************************************
*/
#if defined ROTARY_ENCODER
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
#endif
  Serial.println("Setup Done!");

//  dccexProtocol.setLogStream(&Serial);
  dccexProtocol.setDelegate(&myDelegate);
  dccexProtocol.connect(&client);
  Serial.println("DCC-EX connected");
}
/*
 ********************************************************************************************************
 * Main Loop
 ********************************************************************************************************
*/
void loop() 
{
  dccexProtocol.check();

  lv_timer_handler();

//  ui_t...();

  gfx->flush();

//  receiveCMD();

#if defined ROTARY_ENCODER
  if(encoder_present)                       //Sample Rotary Encoder if it's been found:-)
  {
    if(!ss.digitalRead(SS_SWITCH))          //First check if the Direction Button has been pressed
    {
      if(RE_button_active != 1)             //Check if it's already been processed
      {
        RE_button_active = 1;
        if(locoDirs[activeLocoID] == 1)      //Currently Forward?
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
        int32_t rate = (200-elapsed_time)/10;
        new_position = new_position + (re_change * rate);
        if(new_position > 127) new_position = 127;
        if(new_position < 0) new_position = 0;
        ss.setEncoderPosition(new_position);
      } 
      locoSpeeds[activeLocoID] = new_position; //update the Active loco
//      setSpeed(atoi(locoAddress[activeLocoID]), locoSpeeds[activeLocoID], locoDirs[activeLocoID]); //and tell DCC-EX
      encoder_position = new_position;      // and save for next round
      re_timer = millis();
    }
  }
#endif
}
