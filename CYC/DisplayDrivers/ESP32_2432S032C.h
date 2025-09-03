#ifndef ESP32_2432S032C_H
#define ESP32_2432S032C_H

/*******************************************************************************
 * Settings specific to this Display Model
 ******************************************************************************/
 
#define TFT_BACKLIGHT 200
#define MIN_BL 10
#define FUNCCOL 80
#define ACC_PER_PAGE 6

#define MAX_LOCOS 100
#define MAX_ACCS 200

#define GFX_BL 27

const uint16_t SCREEN_WIDTH = 240;
const uint16_t SCREEN_HEIGHT = 320;

#define ROTATION 0

#define NAME_COL0_WIDTH 175
#define NAME_COL1_WIDTH 50

/*******************************************************************************
 * Display Driver for GFX Library for Arduino by "moononournation"
 ******************************************************************************/
 
#define GFX_DEV_DEVICE ESP32_2432S032

#define TFT_DC 2
#define TFT_CS 15
#define TFT_SCK 14
#define TFT_MOSI 13
#define TFT_MISO GFX_NOT_DEFINED
#define TFT_RST -1
#define IPS true

Arduino_DataBus *bus = new Arduino_ESP32SPI(TFT_DC, TFT_CS, TFT_SCK, TFT_MOSI, TFT_MISO);
Arduino_GFX *gfx = new Arduino_ST7789(bus, TFT_RST, ROTATION, IPS);

/*******************************************************************************
 * Rotary Encoder Specifics
 ******************************************************************************/
 
#define SS_SWITCH        24
#define SEESAW_ADDR    0x36

Adafruit_seesaw ss;
 
void initRE()
{

}
 
/*******************************************************************************
 * Capacitive Touch
 ******************************************************************************/

#include <TAMC_GT911.h>

#define TOUCH_GT911_SCL 32
#define TOUCH_GT911_SDA 33
#define TOUCH_GT911_INT -1
#define TOUCH_GT911_RST 25

#define TOUCH_GT911_ROTATION ROTATION_NORMAL
#define TOUCH_MAP_X1 320
#define TOUCH_MAP_X2 0
#define TOUCH_MAP_Y1 240
#define TOUCH_MAP_Y2 0

int touch_last_x = 0, touch_last_y = 0;

TAMC_GT911 ts = TAMC_GT911(TOUCH_GT911_SDA, TOUCH_GT911_SCL, TOUCH_GT911_INT, TOUCH_GT911_RST, max(TOUCH_MAP_X1, TOUCH_MAP_X2), max(TOUCH_MAP_Y1, TOUCH_MAP_Y2));

//Initialize the Touch Controller
void initTouch()
{
  ts.begin();
  ts.setRotation(ROTATION);
}

//Create the Touch Object
void my_touchpad_read(lv_indev_drv_t * indev_driver, lv_indev_data_t * data)
{
  ts.read();
  if (ts.isTouched) 
  {
    data->state = LV_INDEV_STATE_PRESSED;
    data->point.x = ts.points[0].y;
    data->point.y = SCREEN_HEIGHT - ts.points[0].x;
  } else data->state = LV_INDEV_STATE_RELEASED;
}

#endif
