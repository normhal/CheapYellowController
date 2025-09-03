#ifndef ESP32_8048S050C_H
  #define ESP32_8048S050C_H

/*******************************************************************************
 * Start of Arduino_GFX setting
 ******************************************************************************/

#define TFT_BACKLIGHT 250
#define MIN_BL 242
#define FUNCCOL 140
#define ACC_PER_PAGE 10

#define GFX_BL 2 // default backlight pin, you may replace DF_GFX_BL to actual backlight pin

#define SCREEN_WIDTH 480          //Using EEZ Orientation
#define SCREEN_HEIGHT 800

#define ROTATION 1

#define NAME_COL0_WIDTH 350
#define NAME_COL1_WIDTH 100

/*******************************************************************************
 * Display Driver details for GFX Library for Arduino
 ******************************************************************************/

#define GFX_DEV_DEVICE ESP32_8048S043

//#define RGB_PANEL

#define AUTO_FLUSH true

 Arduino_ESP32RGBPanel *rgbpanel = new Arduino_ESP32RGBPanel(
     40 /* DE */, 41 /* VSYNC */, 39 /* HSYNC */, 42 /* PCLK */,
     45 /* R0 */, 48 /* R1 */, 47 /* R2 */, 21 /* R3 */, 14 /* R4 */,
     5 /* G0 */, 6 /* G1 */, 7 /* G2 */, 15 /* G3 */, 16 /* G4 */, 4 /* G5 */,
     8 /* B0 */, 3 /* B1 */, 46 /* B2 */, 9 /* B3 */, 1 /* B4 */,
     0 /* hsync_polarity */, 8 /* hsync_front_porch */, 4 /* hsync_pulse_width */, 8 /* hsync_back_porch */,
     0 /* vsync_polarity */, 8 /* vsync_front_porch */, 4 /* vsync_pulse_width */, 8 /* vsync_back_porch */,
     1 /* pclk_active_neg */, 16000000 /* prefer_speed */, false /* useBigEndian */,
     0 /* de_idle_high */, 0 /* pclk_idle_high */, 0 /* bounce_buffer_size_px */);

 Arduino_RGB_Display *g = new Arduino_RGB_Display(
     SCREEN_HEIGHT, SCREEN_WIDTH, rgbpanel, ROTATION, AUTO_FLUSH);
 Arduino_GFX *gfx = new Arduino_Canvas(SCREEN_WIDTH, SCREEN_HEIGHT, g);
 Arduino_DataBus *bus = create_default_Arduino_DataBus();
 
#define CANVAS

/*******************************************************************************
 * Rotary Encoder Specifics
 * Encoder shares I2C bus with Touch on 19 and 20
 ******************************************************************************/
 
 //#define I2C_SDA 19
 //#define I2C_SCL 20

 #define SS_SWITCH        24
 #define SEESAW_ADDR    0x36

 Adafruit_seesaw ss;       //For Capacitive Displays

 void initRE()
 {
    // Initialization done by "ss.begin(SEESAW_ADDR)" in main sketch
 }

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
//    Serial.println(data->point.x);
//    Serial.println(data->point.y);
//    Serial.println();
    delay(100);
  }  
}

#endif
