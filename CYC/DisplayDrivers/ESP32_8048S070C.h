#ifndef ESP32_8048S070C_H
#define ESP32_8048S070C_H

/*******************************************************************************
 * Start of Arduino_GFX setting
 ******************************************************************************/

#define AUTO_FLUSH true

#define TFT_BACKLIGHT 246
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

#define GFX_DEV_DEVICE ESP32_8048S070

#define RGB_PANEL

Arduino_ESP32RGBPanel *rgbpanel = new Arduino_ESP32RGBPanel(
    41 /* DE */, 40 /* VSYNC */, 39 /* HSYNC */, 42 /* PCLK */,
    14 /* R0 */, 21 /* R1 */, 47 /* R2 */, 48 /* R3 */, 45 /* R4 */,
    9 /* G0 */, 46 /* G1 */, 3 /* G2 */, 8 /* G3 */, 16 /* G4 */, 1 /* G5 */,
    15 /* B0 */, 7 /* B1 */, 6 /* B2 */, 5 /* B3 */, 4 /* B4 */,
    0 /* hsync_polarity */, 180 /* hsync_front_porch */, 30 /* hsync_pulse_width */, 16 /* hsync_back_porch */,
    0 /* vsync_polarity */, 12 /* vsync_front_porch */, 13 /* vsync_pulse_width */, 10 /* vsync_back_porch */,
    1 /* pclk_active_neg */);
    
Arduino_RGB_Display *gfx = new Arduino_RGB_Display(
    SCREEN_HEIGHT, SCREEN_WIDTH , rgbpanel, ROTATION, AUTO_FLUSH);

Arduino_DataBus *bus = create_default_Arduino_DataBus();

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


/*
//Initialize the Touch Controller
void initTouch()
{
  ts.begin();
  ts.setRotation(ROTATION);
}

//create a touch object   TO BE COMPLETED!
void my_touchpad_read(lv_indev_drv_t * indev_driver, lv_indev_data_t * data)
{
  if (ts.tirqTouched())
  {
    if (ts.touched())
    {
      TS_Point p = ts.getPoint();
      data->state = LV_INDEV_STATE_PR;
      data->point.x = map(p.x, 400, 3800, 0, 271);
      if (data->point.x < 0) data->point.x = 0;
      data->point.y = map(p.y, 200, 3850, 479, 0);
      if (data->point.y < 0) data->point.y = 0;
      delay(100);
    }
  }
}
*/
#endif
