#ifndef ESP32_3248S035R_H
#define ESP32_3248S035R_H

/*******************************************************************************
 * Settings specific to this Display Model
 ******************************************************************************/

#define TFT_BACKLIGHT 250

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

Adafruit_seesaw ss;
 
 void initRE()
 {
 
 }
 
 /*******************************************************************************
 * Resistive Touch
 ******************************************************************************/

#include <SPI.h>
#include <XPT2046_Touchscreen.h>

#define TOUCH_IRQ 36
#define TOUCH_MOSI 13
#define TOUCH_MISO 12
#define TOUCH_CLK 14
#define TOUCH_CS 33

class TouchConfig 
{
  public:
    XPT2046_Touchscreen* ts;
    SPIClass* touchSPI;

    const int minX = 4000;
    const int maxX = 100;
    const int minY = 100;
    const int maxY = 4000;

    TouchConfig() 
    {
      touchSPI = new SPIClass(VSPI);
      ts = new XPT2046_Touchscreen(TOUCH_CS, TOUCH_IRQ);
    }

    bool begin() 
    {
      touchSPI->begin(TOUCH_CLK, TOUCH_MISO, TOUCH_MOSI, TOUCH_CS);
      if (!ts->begin(*touchSPI)) return false;
      ts->setRotation(0);
      return true;
    }

    void getScaledPoint(int& x, int& y, int& z) 
    {
      if (ts->touched()) 
      {
        TS_Point p = ts->getPoint();
        x = constrain(map(p.x, maxX, minX, 0, SCREEN_WIDTH), 0, SCREEN_WIDTH);
        y = constrain(map(p.y, minY, maxY, 0, SCREEN_HEIGHT), 0, SCREEN_HEIGHT);
      }
    }

    bool isTouched() {
      return ts->touched();
    }
};

TouchConfig ts;

void initTouch()
{
    if(!ts.begin()) Serial.println("Touch Init Failed");
    else Serial.println("Touch Init Completed");
}

//create a touch object
void my_touchpad_read(lv_indev_drv_t * indev_driver, lv_indev_data_t * data)
{
  if (ts.isTouched()) 
  {
    data->state = LV_INDEV_STATE_PRESSED;
    int x, y, z;
    ts.getScaledPoint(x, y, z);
    data->point.x = x;
    data->point.y = y;
//    Serial.printf("X: %d, Y: %d\n", x, y);
  }
  else
  {
    data->state = LV_INDEV_STATE_RELEASED;
  }
}

#endif
