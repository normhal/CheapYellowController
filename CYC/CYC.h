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
#ifndef CYC_H
  #define CYC_H

#include <Arduino.h>
#include <lvgl.h>
#include <WiFi.h>
#include <Arduino_GFX_Library.h>
#include <DCCEXProtocol.h>
#include <LittleFS.h>
#include <CSV_Parser.h>
#include <Adafruit_seesaw.h>
#include <Preferences.h>

#include "ui.h"
#include "screens.h"
#include "actions.h"
#include "images.h"
#if defined USE_VECTORS
  #include <vector>
#endif

// other includes for platformio RKS 27/05/2025
#ifdef PLATFORMIO_BUILD
#include "Menu_Page.h"
#include "Program_Page.h"
#include "Edit_Loco_Page.h"
#include "Little_FS.h"
#include "CSInterface.h"
#include "Throttle_Page.h"
#endif

//WiFiClient client;

Preferences eeProm;
/*
 ************************************************************************************************************************
 * Display Panel Selection
 ************************************************************************************************************************
*/
#if defined ESP2432S028C
  #include "DisplayDrivers/ESP32_2432S028C.h"
#elif defined ESP2432S028R
  #include "DisplayDrivers/ESP32_2432S028R.h"
#elif defined JC2432W328C
  #include "DisplayDrivers/JC2432W328C.h"
#elif defined ESP2432THMIR
  #include "DisplayDrivers/ESP32_2432THMIR.h"
#elif defined ESP2432S032C
  #include "DisplayDrivers/ESP32_2432S032C.h"
#elif defined ESP2432S032R
  #include "DisplayDrivers/ESP32_2432S032R.h"
#elif defined ESP3248S035C
  #include "DisplayDrivers/ESP32_3248S035C.h"
#elif defined ESP3248S035R
  #include "DisplayDrivers/ESP32_3248S035R.h"
#elif defined ESP3248W535C
  #include "DisplayDrivers/ESP32_3248W535.h"
#elif defined ESP4827S043R
  #include "DisplayDrivers/ESP32_4827S043R.h"
#elif defined ESP4827S043C
  #include "DisplayDrivers/ESP32_4827S043C.h"
#elif defined ESP4827W543R
  #include "DisplayDrivers/ESP32_4827W543R.h"
#elif defined ESP4827W543C
  #include "DisplayDrivers/ESP32_4827W543C.h"
#elif defined ESP8048S043C     
  #include "DisplayDrivers/ESP32_8048S043C.h"
#elif defined ESP8048S050C     
  #include "DisplayDrivers/ESP32_8048S050C.h"
#elif defined ESP8048W550C
  #include "DisplayDrivers/ESP32_8048W550.h"
#elif defined ESP8048S070C
  #include "DisplayDrivers/ESP32_8048S070C.h"
//#elif defined ESP4848S040C     //TODO
//  #include "DisplayDrivers/ESP32_4848S040C.h"
#endif

using namespace std;

/*
 ****************************************************************************************************************
 * Prototypes
 ****************************************************************************************************************
*/
static void ta_event_cb(lv_event_t * e);
static void dd_cb(lv_event_t * e);
static void functions_cb(lv_event_t * e);
static void tbl_roster_cb(lv_event_t * e);
static void ssid_selected(lv_event_t * e);
static void dd_locos_cb(lv_event_t * e);
static void throttle_selection_handler_cb(lv_event_t * e);

void populateSelected(String);
void populateSlots(uint8_t);
void populateLocoArray(String);
void populateLocoFunctions(String);

void saveDCCExAcc(fs::FS &fs, const char * path, const char * message);
void saveDCCExLocos(fs::FS &fs, const char * path, const char * message);
void receiveDCCEXLocos(fs::FS &fs, const char * path);
void receiveDCCEXAccs(fs::FS &fs, const char * path);

/*
 ************************************************************************************************************************
 * Rotary Encoder Values
 ************************************************************************************************************************
*/

int32_t encoder_position = 0;
uint8_t RE_button_active = 0;
uint8_t encoder_present = 0;
unsigned long re_timer = 0;

/*
 ************************************************************************************************************************
 * Display Panel configuration and definitions
 ************************************************************************************************************************
*/
// Configurable values
uint8_t lcdBL;
uint8_t reAccel = 10;
uint8_t timeout = 20;
uint8_t funcCol = FUNCCOL;
uint8_t threshold = 15;
bool def_roster = false;       //false = local, true = DCC-EX
bool def_acc = false;        //false = local, true = DCC-EX
bool reboot_req = false;
bool re_enabled = true;
bool wifi_enabled = false;

uint8_t trackSel = 99; 
uint8_t replyExpected = 0;
  
int long interruptTime = 0;
int long elapsedTime = 0;
int long lastTime = 0;

#define MAX_COMMAND_LENGTH 10

char commandString[MAX_COMMAND_LENGTH+1];

unsigned long previousMillis = 0;        // will store last time LED was updated
unsigned long currentMillis = millis();

bool lastA = false;
unsigned long number = 0;
unsigned int lowest = 0;
unsigned int highest = 126; //126;

uint8_t directionFlag = 0;

const uint8_t tCount = 4;

enum ScreensEnum callingPage;

static int foundNetworks = 0;
unsigned long networkTimeout = 10 * 1000;

String ssidList;

struct NwCred
{
  uint16_t id;
  String ssid;
  String password;
  String ipAddress;
  uint16_t nwPort;
};

//typedef struct NwCred nwk;

#define NUM_NWKS 10

NwCred netwks[NUM_NWKS];

TaskHandle_t ntScanTaskHandler, ntConnectTaskHandler;

String foundWiFiList[NUM_NWKS];

typedef enum {
  NO_NETWORK,
  NETWORK_SEARCHING,
  NETWORK_CONNECTED_POPUP,
  NETWORK_CONNECTED,
  NETWORK_CONNECT_FAILED
} Network_Status_t;

Network_Status_t networkStatus = NO_NETWORK;
 typedef enum {
  CONFIG,
  ROSTER,
  ACC,
  PROGRAM,
  WIFI,
  LAYOUT,
  SAVE,
  RESTORE
 }Menu_Items;

/*
 ****************************************************************************************************************
 * Defines
 ****************************************************************************************************************
*/
#define EEPROM_SIZE 128
#define EEPROM_ADDR_WIFI_FLAG 0
#define EEPROM_ADDR_WIFI_CREDENTIAL 4

#define FORMAT_LITTLEFS_IF_FAILED true

#define THROTTLE_COUNT 4
#define NUM_LOCO_SLOTS 10
#define NUM_FUNC_SLOTS 10

const char NUM_FUNCS = 28;

#ifndef USE_VECTORS
  #define NUM_LOCOS 50
  #define NUM_ACCS 100
#endif

#define NUM_ROUTES 48
/*
 ****************************************************************************************************************
 * Structures
 ****************************************************************************************************************
*/
const char * throttleName[4] = {
  "Throttle A",
  "Throttle B",
  "Throttle C",
  "Throttle D"
};

struct locomotive
{
  String LocoName;
  String LocoAddress;
  uint8_t SavedSpeed = 0;
  uint8_t LocoSpeed = 0;
  uint8_t LocoDir = 1;
  uint8_t FuncNum[NUM_FUNCS];
  String FuncName[NUM_FUNCS];
  uint8_t FuncState[NUM_FUNCS];
  uint8_t FuncOption[NUM_FUNCS];
  uint8_t FuncSlot[NUM_FUNCS];
};

#ifndef USE_VECTORS
 locomotive Locomotives[NUM_LOCOS];
#endif

#define NAME_LEN 36
#define ADDR_LEN 5
#define SPEED_LEN 3
//#define DIR_LEN 1
#define FNUM_LEN 3
#define FNAME_LEN 10

uint8_t func2Slot[NUM_FUNCS];                                     //Stores the Slot Number used by a Function;
uint8_t slot2Func[NUM_FUNC_SLOTS];                                //Stores the Function Number used by a Slot;

int16_t accStartID = 0;

struct accessory
{
  String AccRow;
  String AccName;      //char AccName[15];
  String AccAddress;
  uint16_t AccImage;
  uint16_t AccType;
  uint8_t AccState;
};

#ifndef USE_VECTORS
  accessory Turnouts[NUM_ACCS];
#endif 

/*
 ****************************************************************************************************************
 * Global Variables
 ****************************************************************************************************************
*/
const uint16_t map_xlate[] = {0, 3, 6, 9, 12, 1, 4, 7, 10, 13};
const uint16_t slotXlate[] = {0, 2, 4, 6, 8, 1, 3, 5, 7, 9};
const uint16_t abs_xlate[] = {0, 5, 1, 6, 2, 7, 3, 8, 4, 9};
const uint16_t acc_map_xlate[] = {0,2,4,6,8,10,12,14,16,18};

const char * btnMap_functions[] = {
                          " ", " ", "\n",
                          " ", " ", "\n",
                          " ", " ", "\n",
                          " ", " ", "\n",
                          " ", " ", NULL
                          };

/*
const char * btnMap_acc_state[] = {
                                    " ", "\n"," ", "\n"," ", "\n"," ", "\n"," ", "\n",
                                    " ", "\n"," ", "\n"," ", "\n"," ", "\n"," ", NULL
                                  };

const char * btnMap_acc_name[] =  {
                                    " ", "\n"," ", "\n"," ", "\n"," ", "\n"," ", "\n",
                                    " ", "\n"," ", "\n"," ", "\n"," ", "\n"," ", NULL
                                  };
*/

const char * btnMap_acc_state[ACC_PER_PAGE * 2];    //= {
//                                    " ", "\n"," ", "\n"," ", "\n"," ", "\n"," ", "\n", " ", NULL
//                                  };

const char * btnMap_acc_name[ACC_PER_PAGE * 2];   // =  {
//                                    " ", "\n"," ", "\n"," ", "\n"," ", "\n"," ", "\n", " ", NULL
//                                  };

uint32_t activeIndex = 0;
uint32_t activeSlot[THROTTLE_COUNT] = {0};
uint8_t activeThrottle = 0;
uint8_t activeLocoID = 255;
uint8_t CallingPage = 0;
uint32_t activeLoco[THROTTLE_COUNT][NUM_LOCO_SLOTS] = {{0},{0}};
uint8_t thNum = 0;
uint16_t locoCount = 0;
uint16_t accCount = 0;
uint16_t routeCount = 0;
uint8_t locosDirty = 0;
uint8_t functionsDirty = 0;
uint8_t throttlesDirty = 0;
uint8_t accessoriesDirty = 0;
uint8_t credentialsDirty = 0;
uint8_t routesDirty = 0;

uint8_t selectedIDs[THROTTLE_COUNT][NUM_LOCO_SLOTS];

#define NORMAL_MODE 0
#define EDIT_MODE 1
#define SELECT_MODE 2
#define GUEST_ACTIVE 3
#define GUEST_INACTIVE 4

//String savedActiveAddress;
//uint16_t savedActiveSpeed;
//uint8_t savedActiveDir;
uint16_t guestSpeed = 0;
uint8_t guestDir = 1;          // Default Guest Direction

uint8_t rosterMode = NORMAL_MODE;

uint16_t editingID = 0;
uint8_t functionEditSlot = 0;

#endif
