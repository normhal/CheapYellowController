#ifndef ESP32_JC8048W550C_H
#define ESP32_JC8048W550C_H

/*******************************************************************************
 * Start of Arduino_GFX setting
 ******************************************************************************/

#define GFX_BL 2 // default backlight pin, you may replace DF_GFX_BL to actual backlight pin
#define ROTATION 1
#define SCREEN_WIDTH 480          //Using EEZ Orientation
#define SCREEN_HEIGHT 800
#define DISPLAY_WIDTH 800         //Physical Display Properties ex rotation
#define DISPLAY_HEIGHT 480
#define AUTO_FLUSH true

#define NAME_COL_WIDTH 360

#define TFT_BACKLIGHT 230

//#define GFX_DEV_DEVICE ESP32_8048W550
#define RGB_PANEL

// Uncomment for ST7262 IPS LCD 800x480
 Arduino_ESP32RGBPanel *rgbpanel = new Arduino_ESP32RGBPanel(
     40 /* DE */, 41 /* VSYNC */, 39 /* HSYNC */, 42 /* PCLK */,
     45 /* R0 */, 48 /* R1 */, 47 /* R2 */, 21 /* R3 */, 14 /* R4 */,
     5 /* G0 */, 6 /* G1 */, 7 /* G2 */, 15 /* G3 */, 16 /* G4 */, 4 /* G5 */,
     8 /* B0 */, 3 /* B1 */, 46 /* B2 */, 9 /* B3 */, 1 /* B4 */,
     0 /* hsync_polarity */, 8 /* hsync_front_porch */, 4 /* hsync_pulse_width */, 8 /* hsync_back_porch */,
     0 /* vsync_polarity */, 8 /* vsync_front_porch */, 4 /* vsync_pulse_width */, 8 /* vsync_back_porch */,
     1 /* pclk_active_neg */, 16000000 /* prefer_speed */);

 Arduino_RGB_Display *gfx = new Arduino_RGB_Display(DISPLAY_WIDTH, DISPLAY_HEIGHT, rgbpanel, ROTATION, AUTO_FLUSH);

Arduino_DataBus *bus = create_default_Arduino_DataBus();

/*******************************************************************************
 * Capacitive Touch
 ******************************************************************************/

#include <TAMC_GT911.h>

#define TOUCH_GT911_SCL 20
#define TOUCH_GT911_SDA 19
#define TOUCH_GT911_INT -1
#define TOUCH_GT911_RST 38

#define TOUCH_GT911_ROTATION ROTATION_NORMAL
#define TOUCH_MAP_X1 0
#define TOUCH_MAP_X2 480
#define TOUCH_MAP_Y1 800
#define TOUCH_MAP_Y2 0

int touch_last_x = 0, touch_last_y = 0;

TAMC_GT911 ts = TAMC_GT911(TOUCH_GT911_SDA, TOUCH_GT911_SCL, TOUCH_GT911_INT, TOUCH_GT911_RST, max(TOUCH_MAP_X1, TOUCH_MAP_X2), max(TOUCH_MAP_Y1, TOUCH_MAP_Y2));

//Initialize the Touch Controller
void initTouch()
{
  ts.begin();
  ts.setRotation(ROTATION);
}

//Create the Touch object
void my_touchpad_read(lv_indev_drv_t * indev_driver, lv_indev_data_t * data)
{
  ts.read();
  if (ts.isTouched) 
  {
  //  TP_Point p = ts.getPoint();
    data->state = LV_INDEV_STATE_PR;
//    #if defined(TOUCH_SWAP_XY)
      touch_last_x = map(ts.points[0].y, TOUCH_MAP_X1, TOUCH_MAP_X2, 0, DISPLAY_HEIGHT - 1);
      touch_last_y = map(ts.points[0].x, TOUCH_MAP_Y1, TOUCH_MAP_Y2, 0, DISPLAY_WIDTH - 1);
//    #else
//      touch_last_x = map(ts.points[0].x, TOUCH_MAP_X1, TOUCH_MAP_X2, DISPLAY_HEIGHT - 1, 0);
//      touch_last_y = map(ts.points[0].y, TOUCH_MAP_Y1, TOUCH_MAP_Y2, DISPLAY_WIDTH - 1, 0);
//    #endif
    data->point.x = touch_last_x;
    data->point.y = touch_last_y;
    Serial.println(data->point.x);
    Serial.println(data->point.y);
    Serial.println();

    delay(100);
  }  
}

#endif
