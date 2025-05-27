#ifndef ESP32_4827S043R_H
#define ESP32_4827S043R_H

/*******************************************************************************
 * Start of Arduino_GFX setting
 ******************************************************************************/

#define GFX_BL 2 // default backlight pin, you may replace DF_GFX_BL to actual backlight pin
#define ROTATION 1
#define SCREEN_WIDTH 272          //Using EEZ Orientation
#define SCREEN_HEIGHT 480
#define DISPLAY_WIDTH 480         //Physical Display Properties ex rotation
#define DISPLAY_HEIGHT 272
#define AUTO_FLUSH true

#define NAME_COL_WIDTH 210

const uint8_t TFT_BACKLIGHT = 246;

Arduino_ESP32RGBPanel *rgbpanel = new Arduino_ESP32RGBPanel(
    40 /* DE */, 41 /* VSYNC */, 39 /* HSYNC */, 42 /* PCLK */,
    45 /* R0 */, 48 /* R1 */, 47 /* R2 */, 21 /* R3 */, 14 /* R4 */,
    5 /* G0 */, 6 /* G1 */, 7 /* G2 */, 15 /* G3 */, 16 /* G4 */, 4 /* G5 */,
    8 /* B0 */, 3 /* B1 */, 46 /* B2 */, 9 /* B3 */, 1 /* B4 */,
    0 /* hsync_polarity */, 1 /* hsync_front_porch */, 1 /* hsync_pulse_width */, 43 /* hsync_back_porch */,
    0 /* vsync_polarity */, 3 /* vsync_front_porch */, 1 /* vsync_pulse_width */, 12 /* vsync_back_porch */,
    1 /* pclk_active_neg */, 9000000 /* prefer_speed */);

Arduino_RGB_Display *gfx = new Arduino_RGB_Display(DISPLAY_WIDTH, DISPLAY_HEIGHT, rgbpanel, ROTATION , AUTO_FLUSH);

Arduino_DataBus *bus = create_default_Arduino_DataBus();

/*******************************************************************************
 * End of Arduino_GFX setting
 ******************************************************************************/

#include <xpt2046.h>
//#include <XPT2046.h>
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
#define TOUCHSCREEN_MISO_PIN (13)
#define TOUCHSCREEN_MOSI_PIN (11)
#define TOUCHSCREEN_CS_PIN   (38)
#define TOUCHSCREEN_IRQ_PIN  (18)

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
 //   Serial.printf("RawX: %d X: %d - RawY: %d Y: %d\n", ts.RawX(), data->point.x, ts.RawY(), data->point.y );
  }
  else
  {
    data->state = LV_INDEV_STATE_REL;
  }
}

#endif
