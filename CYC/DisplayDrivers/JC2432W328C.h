#ifndef JC2432W328C_H
#define JC2432W328C_H

/*******************************************************************************
 * Settings specific to this Display Model
 ******************************************************************************/
 
#define TFT_BACKLIGHT 200
#define MIN_BL 10
#define FUNCCOL 80
#define ACC_PER_PAGE 6

#define GFX_BL 27                              //Backlight Control Pin

#define SCREEN_WIDTH 240
#define SCREEN_HEIGHT 320

#define ROTATION 1

#define NAME_COL0_WIDTH 175
#define NAME_COL1_WIDTH 50

/*******************************************************************************
 * Display Driver for GFX Library for Arduino by "moononournation"
 ******************************************************************************/
 
#define GFX_DEV_DEVICE JC2432W328

#define TFT_DC 2
#define TFT_CS 15
#define TFT_SCK 14
#define TFT_MOSI 13
#define TFT_MISO 12
#define TFT_RST -1
#define IPS false
#define TFT_ROTATION 8

Arduino_DataBus *bus = new Arduino_ESP32SPI(TFT_DC, TFT_CS, TFT_SCK, TFT_MOSI, TFT_MISO);
Arduino_GFX *gfx = new Arduino_ST7789(bus, TFT_RST, TFT_ROTATION, IPS, SCREEN_WIDTH, SCREEN_HEIGHT,0,0,0,0);

/*******************************************************************************
 * Rotary Encoder Specifics
 ******************************************************************************/
 
 #define SS_SWITCH        24
 #define SEESAW_ADDR    0x36

 #define RX_1 17
 #define TX_1 16
 #define I2C_SDA 21
 #define I2C_SCL 22
 
 Adafruit_seesaw ss;
 
 void initRE()
 {
   Wire.setPins(I2C_SDA, I2C_SCL);
   Wire.begin(I2C_SDA, I2C_SCL);
 }
 
/*******************************************************************************
 * Capacitive Touch
 ******************************************************************************/

#define TOUCH_MODULES_CST_SELF

#include <TouchLib.h>
#include <Wire.h>

#define TOUCH_SCL 32
#define TOUCH_SDA 33
#define TOUCH_INT -1
#define TOUCH_RST 25

TouchLib ts(Wire, TOUCH_SDA, TOUCH_SCL);

//Initialize the Touch Controller
void initTouch()
{
    Wire.begin(TOUCH_SDA, TOUCH_SCL);
    ts.init();
}

//Create the Touch Object
void my_touchpad_read(lv_indev_drv_t * indev_driver, lv_indev_data_t * data)
{
  if (ts.read()) 
  {
    uint8_t n = ts.getPointNum();
//    Serial.printf("getPointNum: %d  ", n);
    for (uint8_t i = 0; i < n; i++)
    {
        TP_Point t = ts.getPoint(i);
//      Serial.printf("[%d] point x: %d  point y: %d \r\n", i, t.x, t.y);
        data->point.x = t.x;
        data->point.y = t.y;
    }
    data->state = LV_INDEV_STATE_PRESSED;
  } else data->state = LV_INDEV_STATE_RELEASED;
}


#endif
