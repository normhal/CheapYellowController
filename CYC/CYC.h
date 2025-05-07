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
#include <EEPROM.h>
//#include <DCCEXProtocol.h>
#include <LittleFS.h>
#include <CSV_Parser.h>

#include "ui.h"
#include "screens.h"
#include "actions.h"
#include "images.h"

WiFiClient client;

/*
 ************************************************************************************************************************
 * Display Panel Selection
 ************************************************************************************************************************
*/
#if defined ESP2432S028R
  #include "DisplayDrivers/ESP32_2432S028R.h"
#elif defined ESP2432THMIR
  #include "DisplayDrivers/ESP32_2432THMIR.h"
#elif defined ESP3248S035R
  #include "DisplayDrivers/ESP32_3248S035R.h"
#elif defined ESP3248S035C
  #include "DisplayDrivers/ESP32_3248S035C.h"
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
//#elif defined ESP8048S070C     //TODO
//  #include "DisplayDrivers/ESP32_8048S070C.h"
//#elif defined ESP4848S040C     //TODO
//  #include "DisplayDrivers/ESP32_4848S040C.h"
#endif

void dd_locos_cb(lv_event_t * e);
static void throttle_selection_handler_cb(lv_event_t * e);
/*
 ************************************************************************************************************************
 * Display Panel configuration and definitions
 ************************************************************************************************************************
*/

uint8_t thresholdSpeed = 15;
uint8_t REAccAmount = 1;
//uint8_t REpinA;
//uint8_t lastREpinA;
uint8_t powerState = 1;
uint8_t brightness = 250;
uint8_t timeout = 20;

unsigned long lastButtonPress = 0;
uint8_t aFlag = 0;
uint8_t bFlag = 0;
int encoderPos = 0;
uint8_t oldEncPos = 0;
uint8_t oldSpeed = 0;
uint8_t reading = 0;
uint8_t old_pos = 0;  //encoderPos;
boolean buttonState = 0;

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
  String nwPort;
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
  ROUTES,
  SAVE,
  RESTORE
 }Menu_Items;

/*
 ****************************************************************************************************************
 * Callback Prototypes
 ****************************************************************************************************************
*/

static void ta_event_cb(lv_event_t * e);
static void dd_cb(lv_event_t * e);
static void functions_cb(lv_event_t * e);
static void tbl_roster_cb(lv_event_t * e);
static void ssid_selected(lv_event_t * e);

void populateSelected(String);
void populateSlots(uint8_t);
void populateLocoArray(String);
void populateLocoFunctions(String);
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
#define NUM_LOCOS 100
//#define LOCOS_PER_ROSTER_PAGE 10

#define NUM_ACCS 252

#define NUM_ROUTES 48
/*
 ****************************************************************************************************************
 * Structures
 ****************************************************************************************************************
*/
//  char* dd_locos;
const char * throttleName[4] = {
  "Throttle A",
  "Throttle B",
  "Throttle C",
  "Throttle D"
};
#define NAME_LEN 36
#define ADDR_LEN 5
#define SPEED_LEN 3
//#define DIR_LEN 1
#define FNUM_LEN 3
#define FNAME_LEN 10

char locoName[NUM_LOCOS][NAME_LEN +1];
char locoAddress[NUM_LOCOS][ADDR_LEN +1];
uint32_t locoSpeed[NUM_LOCOS];
uint8_t locoDir[NUM_LOCOS];
char funcName[NUM_LOCOS][NUM_FUNC_SLOTS][FNAME_LEN +1];
char funcNumber[NUM_LOCOS][NUM_FUNC_SLOTS][FNUM_LEN+1];          // 4 characters to store "255"
uint8_t funcState[NUM_LOCOS][NUM_FUNC_SLOTS];
uint8_t funcOption[NUM_LOCOS][NUM_FUNC_SLOTS];


  struct HCAcc
  {
    uint16_t AccId;
    const char *AccName;
    uint16_t AccAddress;
    uint16_t AccImage;
    uint16_t AccType;
  };
  //list_of_accs[NUM_ACCS];
 
HCAcc hcAcc[NUM_ACCS];

/*
  struct HCRoute
  {
    uint16_t AccIDs[6][2];
  };
  //list_of_routes[NUM_ROUTES]; 

HCRoute hcRoute[NUM_ROUTES];
*/
/*
 ****************************************************************************************************************
 * Global Variables
 ****************************************************************************************************************
*/
uint16_t map_xlate[] = {0, 3, 6, 9, 12, 1, 4, 7, 10, 13};
uint16_t func_xlate[] = {0, 2, 4, 6, 8, 1, 3, 5, 7, 9};
uint16_t abs_xlate[] = {0, 5, 1, 6, 2, 7, 3, 8, 4, 9};

const char * btnMap_functions[] = {
                          " ", " ", "\n",
                          " ", " ", "\n",
                          " ", " ", "\n",
                          " ", " ", "\n",
                          " ", " ", NULL
                          };

/*
const char * funcMap_functions[] = {
                          " ", " ", "\n",
                          " ", " ", "\n",
                          " ", " ", "\n",
                          " ", " ", "\n",
                          " ", " ", NULL
                          };
*/

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
