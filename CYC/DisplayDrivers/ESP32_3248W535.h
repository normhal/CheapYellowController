#ifndef ESP32_JC3248W535C_H
#define ESP32_JC3248W535C_H

/*******************************************************************************
 * Settings specific to this Display Model
 ******************************************************************************/
 
#define TFT_BACKLIGHT 250

#define GFX_BL 1

#define SCREEN_WIDTH 320          //Using EEZ Orientation
#define SCREEN_HEIGHT 480
//#define DISPLAY_WIDTH 480         //Physical Display Properties ex rotation
//#define DISPLAY_HEIGHT 320

#define ROTATION 0

#define NAME_COL_WIDTH 240

/*******************************************************************************
 * Display Driver for GFX Library for Arduino by "moononournation"
 ******************************************************************************/

#define GFX_DEV_DEVICE JC3248W535

#define TFT_CS   45
#define TFT_SCK  47
#define TFT_SDA0 21
#define TFT_SDA1 48
#define TFT_SDA2 40
#define TFT_SDA3 39

#define DIRECT_MODE // Uncomment to enable full frame buffer

Arduino_DataBus *bus = new Arduino_ESP32QSPI(TFT_CS, TFT_SCK, TFT_SDA0, TFT_SDA1, TFT_SDA2, TFT_SDA3);

Arduino_GFX *g = new Arduino_AXS15231B(bus, GFX_NOT_DEFINED, 0, false, SCREEN_WIDTH, SCREEN_HEIGHT);

Arduino_Canvas *gfx = new Arduino_Canvas(SCREEN_WIDTH, SCREEN_HEIGHT, g, 0, 0, ROTATION);

#define CANVAS

/*******************************************************************************
 * Rotary Encoder Specifics
 ******************************************************************************/
 
 #define I2C_SDA          17
 #define I2C_SCL          18
 #define SS_SWITCH        24
 #define SEESAW_ADDR    0x36

 TwoWire RE_Bus = TwoWire(1);      //For Capacitive Displays
 Adafruit_seesaw ss(&RE_Bus);       //For Capacitive Displays
 
 void initRE()
 {
   RE_Bus.setPins(I2C_SDA, I2C_SCL);
 }
 
/*******************************************************************************
 * Capacitive Touch
 ******************************************************************************/

#include "AXS15231B_touch.h"

#define Touch_SDA  4
#define Touch_SCL  8
#define Touch_INT  3
#define Touch_ADDR 0x3B

// Touch offsets

#define Touch_X_min 1
#define Touch_X_max 320
#define Touch_Y_min 1
#define Touch_Y_max 480

AXS15231B_Touch ts(Touch_SCL, Touch_SDA, Touch_INT, Touch_ADDR, ROTATION);

void initTouch()
{
  ts.begin();
  ts.enOffsetCorrection(true);
  ts.setOffsets(Touch_X_min, Touch_X_max, SCREEN_WIDTH-1, Touch_Y_min, Touch_Y_max, SCREEN_HEIGHT-1);
  ts.setRotation(ROTATION);
}

void my_touchpad_read(lv_indev_drv_t * indev_driver, lv_indev_data_t * data)
{
  uint16_t x = 0, y = 0;
  if (ts.touched()) 
  {
    ts.readData(&x, &y);
    data->state = LV_INDEV_STATE_PRESSED;
    data->point.x = x;
    data->point.y = y;
    delay(10);
  } 
}

#endif
