#ifndef ESP32_JC4827W543R_H
#define ESP32_JC4827W543R_H

/*******************************************************************************
 * Start of Arduino_GFX setting
 ******************************************************************************/

//#define DIRECT_MODE // Uncomment to enable full frame buffer

// Display module
#define GFX_BL 1 // default backlight pin, you may replace DF_GFX_BL to actual backlight pin
#define SCREEN_WIDTH 272          //Using EEZ Orientation
#define SCREEN_HEIGHT 480
#define DISPLAY_WIDTH 480         //Physical Display Properties ex rotation
#define DISPLAY_HEIGHT 272
#define AUTO_FLUSH true

#define ROTATION 0

// Display
#define TFT_rot   0
#define TFT_res_W 272
#define TFT_res_H 480

#define SCREEN_WIDTH 272          //Using EEZ Orientation
#define SCREEN_HEIGHT 480
#define DISPLAY_WIDTH 480         //Physical Display Properties ex rotation
#define DISPLAY_HEIGHT 272

#define NAME_COL_WIDTH 210

#define TFT_BACKLIGHT 246

#define GFX_DEV_DEVICE ESP32_4827A043_QSPI

Arduino_DataBus *bus = new Arduino_ESP32QSPI(
    45 /* cs */, 47 /* sck */, 21 /* d0 */, 48 /* d1 */, 40 /* d2 */, 39 /* d3 */);

Arduino_GFX *g = new Arduino_NV3041A(bus, GFX_NOT_DEFINED /* RST */, ROTATION /* rotation */, true /* IPS */);

Arduino_GFX *gfx = new Arduino_Canvas(480 /* width */, 272 /* height */, g);

#define CANVAS

/*******************************************************************************
 * Resistive Touch
 ******************************************************************************/

#include <xpt2046.h>
/*
int16_t touch_map_x1 = 4000;      //90;
int16_t touch_map_x2 = 0;      //1900;
int16_t touch_map_y1 = 0;      //3800;    //1863;  //1870;
int16_t touch_map_y2 = 4000;      //400;     //120; //180;
*/
bool touch_swap_xy = false;
int16_t touch_map_x1 = 190;   //12;  //297;
int16_t touch_map_x2 = 1880;    //1850;  //3825;
int16_t touch_map_y1 = 1910;   //80;  //3860;
int16_t touch_map_y2 = 110;    //1800;  //171;

#define TOUCHSCREEN_SCLK_PIN (12)
#define TOUCHSCREEN_MISO_PIN (11)
#define TOUCHSCREEN_MOSI_PIN (13)
#define TOUCHSCREEN_CS_PIN   (38)
#define TOUCHSCREEN_IRQ_PIN  (3)

XPT2046 ts = XPT2046(SPI, TOUCHSCREEN_CS_PIN, TOUCHSCREEN_IRQ_PIN);

//Initialize the Touch Controller
void initTouch()
{
  SPI.begin(TOUCHSCREEN_SCLK_PIN, TOUCHSCREEN_MISO_PIN, TOUCHSCREEN_MOSI_PIN);
  ts.begin(SCREEN_WIDTH, SCREEN_HEIGHT);
//  ts.setCal(touch_map_x1, touch_map_x2, touch_map_y1, touch_map_y2, DISPLAY_WIDTH, DISPLAY_HEIGHT); // Raw xmin, xmax, ymin, ymax, width, height
  ts.setRotation(ROTATION);
}

//create a touch object
void my_touchpad_read(lv_indev_drv_t * indev_driver, lv_indev_data_t * data)
{
  if (ts.pressed()) 
  {
    data->state = LV_INDEV_STATE_PR;
//    data->point.x = ts.X(); //map(p.x, touch_map_x1, touch_map_x2, 1, SCREEN_WIDTH);
//    data->point.y = ts.Y(); //map(p.y, touch_map_y1, touch_map_y2, 1, SCREEN_HEIGHT);

    data->point.x = map(ts.RawY(), touch_map_x1, touch_map_x2, 1, SCREEN_WIDTH);
    data->point.y = map(ts.RawX(), touch_map_y1, touch_map_y2, 1, SCREEN_HEIGHT);
//    Serial.printf("RawX: %d X: %d - RawY: %d Y: %d\n", ts.RawX(), data->point.x, ts.RawY(), data->point.y );
  }
  else
  {
    data->state = LV_INDEV_STATE_REL;
  }
}


#endif
