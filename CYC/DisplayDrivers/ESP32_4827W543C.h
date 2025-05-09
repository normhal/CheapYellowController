#ifndef ESP32_JC3248W535C_H
#define ESP32_JC3248W535C_H

/*******************************************************************************
 * Start of Arduino_GFX setting
 ******************************************************************************/

#include "AXS15231B_touch.h"

#define DIRECT_MODE // Uncomment to enable full frame buffer

// Display module
#define GFX_BL 1
#define TFT_CS   45
#define TFT_SCK  47
#define TFT_SDA0 21
#define TFT_SDA1 48
#define TFT_SDA2 40
#define TFT_SDA3 39

#define ROTATION 0

// Display
#define TFT_rot   0
#define TFT_res_W 320
#define TFT_res_H 480

#define SCREEN_WIDTH 320          //Using EEZ Orientation
#define SCREEN_HEIGHT 480
#define DISPLAY_WIDTH 480         //Physical Display Properties ex rotation
#define DISPLAY_HEIGHT 320

#define NAME_COL_WIDTH 240

#define TFT_BACKLIGHT 64

#define GFX_DEV_DEVICE JC3248W535

Arduino_DataBus *bus = new Arduino_ESP32QSPI(TFT_CS, TFT_SCK, TFT_SDA0, TFT_SDA1, TFT_SDA2, TFT_SDA3);
Arduino_GFX *g = new Arduino_AXS15231B(bus, GFX_NOT_DEFINED, 0, false, TFT_res_W, TFT_res_H);
#define CANVAS
Arduino_Canvas *gfx = new Arduino_Canvas(TFT_res_W, TFT_res_H, g, 0, 0, TFT_rot);

/*******************************************************************************
 * Capacitive Touch
 ******************************************************************************/

#define Touch_SDA  4
#define Touch_SCL  8
#define Touch_INT  3
#define Touch_ADDR 0x3B

// Touch offsets

#define Touch_X_min 12
#define Touch_X_max 310
#define Touch_Y_min 14
#define Touch_Y_max 461
/*
#define Touch_X_min 0
#define Touch_X_max 320
#define Touch_Y_min 
#define Touch_Y_max 480
*/
AXS15231B_Touch ts(Touch_SCL, Touch_SDA, Touch_INT, Touch_ADDR, TFT_rot);

//Initialize the Touch Controller
void initTouch()
{
  ts.begin();
  ts.setRotation(ROTATION);
}

void my_touchpad_read(lv_indev_drv_t * indev_driver, lv_indev_data_t * data)
{
  uint16_t x, y;
  if (ts.touched()) 
  {
    // Read touched point from touch module
    ts.readData(&x, &y);

    // Set the coordinates
    data->point.x = x;
    data->point.y = y;
    Serial.printf("X Value: %d  Y Value: %d\n", x, y);
    data->state = LV_INDEV_STATE_PRESSED;
  } 
  else 
  {
    data->state = LV_INDEV_STATE_RELEASED;
  }
}

#endif
