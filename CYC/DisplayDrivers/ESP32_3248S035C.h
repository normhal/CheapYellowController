#ifndef ESP32_3248S035C_H
#define ESP32_3248S035C_H

/*******************************************************************************
 * Settings specific to this Display Model
 ******************************************************************************/

#define TFT_BACKLIGHT 200
#define MIN_BL 10
#define FUNCCOL 100

#define GFX_BL 27

#define SCREEN_WIDTH 320
#define SCREEN_HEIGHT 480

#define ROTATION 0

#define NAME_COL0_WIDTH 240
#define NAME_COL1_WIDTH 60

/*******************************************************************************
 * Display Driver for GFX Library for Arduino by "moononournation"
 ******************************************************************************/

#define GFX_DEV_DEVICE ESP32_3248S035

#define TFT_DC 2
#define TFT_CS 15
#define TFT_SCK 14
#define TFT_MOSI 13
#define TFT_MISO 12
#define TFT_RST GFX_NOT_DEFINED
#define SPI_NUM VSPI

Arduino_DataBus *bus = new Arduino_ESP32SPI(TFT_DC, TFT_CS, TFT_SCK, TFT_MOSI, TFT_MISO, SPI_NUM);
Arduino_GFX *gfx = new Arduino_ST7796(bus, TFT_RST, ROTATION);

/*******************************************************************************
 * Rotary Encoder Specifics
 ******************************************************************************/
 
#define SS_SWITCH        24
#define SEESAW_ADDR    0x36

#define I2C_SDA 21
#define I2C_SCL 22
 
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

#define TOUCH_GT911_SCL 32
#define TOUCH_GT911_SDA 33
#define TOUCH_GT911_INT -1
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
    data->state = LV_INDEV_STATE_PRESSED;
    data->point.x = ts.points[0].y;
    data->point.y = SCREEN_HEIGHT - ts.points[0].x;
  } else data->state = LV_INDEV_STATE_RELEASED;
}

#endif
