#ifndef ESP32_3248S035C_H
#define ESP32_3248S035C_H

/*******************************************************************************
 * Start of Arduino_GFX setting
 ******************************************************************************/
#define ROTATION 0

#define GFX_BL 27

#define DISPLAY_WIDTH 320
#define DISPLAY_HEIGHT 480

#define SCREEN_WIDTH 320
#define SCREEN_HEIGHT 480

#define NAME_COL_WIDTH 240

#define TFT_BACKLIGHT 64

Arduino_DataBus *bus = new Arduino_ESP32SPI(2 /* DC */, 15 /* CS */, 14 /* SCK */, 13 /* MOSI */, 12 /* MISO */, VSPI /* spi_num */);
Arduino_GFX *gfx = new Arduino_ST7796(bus, GFX_NOT_DEFINED /* RST */, ROTATION);

/*******************************************************************************
 * Rotary Encoder Pins
 ******************************************************************************/

#define REButtonPin 35        // The GPIO Pin number for the encoder reverse button
static int pinA = 21;          // The first hardware interrupt pin is digital pin 21
static int pinB = 22;          // The second hardware interrupt pin is digital pin 22

/*******************************************************************************
 * Capacitive Touch
 ******************************************************************************/

#include <TAMC_GT911.h>

#define TOUCH_GT911_SCL 32
#define TOUCH_GT911_SDA 33
#define TOUCH_GT911_INT 21
#define TOUCH_GT911_RST 25

#define TOUCH_GT911_ROTATION ROTATION_NORMAL
#define TOUCH_MAP_X1 480
#define TOUCH_MAP_X2 0
#define TOUCH_MAP_Y1 320
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
    data->state = LV_INDEV_STATE_PR;
    data->point.x = ts.points[0].y;
    data->point.y = DISPLAY_HEIGHT - ts.points[0].x;
  } else data->state = LV_INDEV_STATE_REL;
}

#endif
