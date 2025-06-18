#ifndef ESP32_JC4827W535C_H
#define ESP32_JC4827W535C_H

/*******************************************************************************
 * Settings specific to this Display Model
 ******************************************************************************/
 
#define TFT_BACKLIGHT 64

#define GFX_BL 1

#define SCREEN_WIDTH 272          //Using EEZ Orientation
#define SCREEN_HEIGHT 480

#define ROTATION 1

#define NAME_COL0_WIDTH 200
#define NAME_COL1_WIDTH 50

/*******************************************************************************
 * Display Driver for GFX Library for Arduino by "moononournation"
 ******************************************************************************/

#define GFX_DEV_DEVICE JC4827W535

#define TFT_CS   45
#define TFT_SCK  47
#define TFT_SDA0 21
#define TFT_SDA1 48
#define TFT_SDA2 40
#define TFT_SDA3 39
#define TFT_RST GFX_NOT_DEFINED
#define IPS true

//#define DIRECT_MODE // Uncomment to enable full frame buffer

Arduino_DataBus *bus = new Arduino_ESP32QSPI(TFT_CS, TFT_SCK, TFT_SDA0, TFT_SDA1, TFT_SDA2, TFT_SDA3);

Arduino_NV3041A *panel = new Arduino_NV3041A(bus, TFT_RST, ROTATION, IPS);

Arduino_GFX *gfx = new Arduino_Canvas(SCREEN_WIDTH, SCREEN_HEIGHT, panel);

#define CANVAS

/*******************************************************************************
 * Rotary Encoder Specifics
 ******************************************************************************/
 
 #define I2C_SDA          17
 #define I2C_SCL          18
 #define SS_SWITCH        24
 #define SEESAW_ADDR    0x36


 TwoWire RE_Bus = TwoWire(1);      //For Capacitive Displays
 Adafruit_seesaw ss(&Wire1);       //For Capacitive Displays

 void initRE()
 {
   //Serial1.setPins(RX_1, TX_1);
   Wire1.setPins(I2C_SDA, I2C_SCL);
   Wire1.begin(I2C_SDA, I2C_SCL);
 }
 /*******************************************************************************
 * Capacitive Touch
 ******************************************************************************/

#include <TAMC_GT911.h>

#define TOUCH_GT911_SDA  8
#define TOUCH_GT911_SCL  4
#define TOUCH_GT911_INT  3
#define TOUCH_GT911_RST 38

#define TOUCH_GT911_ROTATION ROTATION_NORMAL
#define TOUCH_MAP_X1 0
#define TOUCH_MAP_X2 272
#define TOUCH_MAP_Y1 480
#define TOUCH_MAP_Y2 0

int touch_last_x = 0, touch_last_y = 0;

TAMC_GT911 ts = TAMC_GT911(TOUCH_GT911_SDA, TOUCH_GT911_SCL, TOUCH_GT911_INT, TOUCH_GT911_RST, max(TOUCH_MAP_X1, TOUCH_MAP_X2), max(TOUCH_MAP_Y1, TOUCH_MAP_Y2));

void initTouch()
{
  ts.begin();
  ts.setRotation(ROTATION);
}

void my_touchpad_read(lv_indev_drv_t * indev_driver, lv_indev_data_t * data)
{
  ts.read();
  if (ts.isTouched) 
  {
    data->state = LV_INDEV_STATE_PR;
    touch_last_x = map(ts.points[0].y, TOUCH_MAP_X1, TOUCH_MAP_X2, 0, SCREEN_WIDTH - 1);
    touch_last_y = map(ts.points[0].x, TOUCH_MAP_Y1, TOUCH_MAP_Y2, 0, SCREEN_HEIGHT - 1);
    data->point.x = touch_last_x;
    data->point.y = touch_last_y;
    delay(100);
  }  
}

#endif
