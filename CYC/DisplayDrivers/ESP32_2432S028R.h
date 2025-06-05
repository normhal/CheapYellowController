#ifndef ESP32_2432S028R_H
#define ESP32_2432S028R_H

/*******************************************************************************
 * Settings specific to this Display Model
 ******************************************************************************/
 
#define TFT_BACKLIGHT 64                        //Default Backlight Brightness

#define GFX_BL 21                               //Backlight Control Pin

#define SCREEN_WIDTH 240
#define SCREEN_HEIGHT 320

#define ROTATION 0

#define NAME_COL_WIDTH 180

/*******************************************************************************
 * Display Driver for GFX Library for Arduino by "moononournation"
 ******************************************************************************/
 
#define GFX_DEV_DEVICE ESP32_2432S028

#define TFT_DC 2
#define TFT_CS 15
#define TFT_SCK 14
#define TFT_MOSI 13
#define TFT_MISO 12
#define TFT_RST GFX_NOT_DEFINED

Arduino_DataBus *bus = new Arduino_ESP32SPI(TFT_DC, TFT_CS, TFT_SCK, TFT_MOSI, TFT_MISO);
Arduino_GFX *gfx = new Arduino_ILI9341(bus, TFT_MISO, ROTATION);

/*******************************************************************************
 * Rotary Encoder Specifics
 ******************************************************************************/
 
 #define RX_1 12
 #define TX_1 13
 #define I2C_SDA 27
 #define I2C_SCL 22
 
 Adafruit_seesaw ss;
 
 void initRE()
 {
//   Serial1.setPins(RX_1, TX_1);
   Wire.setPins(I2C_SDA, I2C_SCL);
   Wire.begin(I2C_SDA, I2C_SCL);
 }
 
/*******************************************************************************
 * Resistive Touch
 ******************************************************************************/

#include <SPI.h>
#include <XPT2046_Touchscreen.h>

#define TOUCH_IRQ 36
#define TOUCH_MOSI 32
#define TOUCH_MISO 39
#define TOUCH_CLK 25
#define TOUCH_CS 33

class TouchConfig 
{
  public:
    XPT2046_Touchscreen* ts;
    SPIClass* touchSPI;

    const int minX = 4000;
    const int maxX = 100;
    const int minY = 100;
    const int maxY = 3650;
    
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

/*
bool touch_swap_xy = false;
int16_t touch_map_x1 = 280;
int16_t touch_map_x2 = 3890;
int16_t touch_map_y1 = 172;
int16_t touch_map_y2 = 3727;

SPIClass touchscreenSPI = SPIClass(HSPI);
XPT2046_Touchscreen ts(XPT2046_CS, XPT2046_IRQ);

void initTouch()
{
    if(!ts.begin()) Serial.println("Touch Init Failed");
    else Serial.println("Touch Init Completed");
}

//create a touch object
void my_touchpad_read(lv_indev_drv_t * indev_driver, lv_indev_data_t * data)
{
  int x = 0;
  int y = 0;
  if (ts.tirqTouched() && ts.touched()) 
  {
    data->state = LV_INDEV_STATE_PR;
    TS_Point p = ts.getPoint();
    data->point.x = map(p.x, 200, 3700, 1, SCREEN_WIDTH);
    data->point.y = map(p.y, 240, 3800, 1, SCREEN_HEIGHT);

  }
  else
  {
    data->state = LV_INDEV_STATE_REL;
  }
}
*/
/*
#include <SPI.h>
#include <xpt2046.h>

int16_t touch_map_x2 = 120; //180;
int16_t touch_map_x1 = 1863;  //1870;
int16_t touch_map_y1 = 90;
int16_t touch_map_y2 = 1900;

#define TOUCHSCREEN_SCLK_PIN (25)
#define TOUCHSCREEN_MISO_PIN (39)
#define TOUCHSCREEN_MOSI_PIN (32)
#define TOUCHSCREEN_CS_PIN   (33)
#define TOUCHSCREEN_IRQ_PIN  (36)

XPT2046 ts = XPT2046(SPI, TOUCHSCREEN_CS_PIN, TOUCHSCREEN_IRQ_PIN);

//Initialize the Touch Controller
void initTouch()
{
  SPI.begin(TOUCHSCREEN_SCLK_PIN, TOUCHSCREEN_MISO_PIN, TOUCHSCREEN_MOSI_PIN);
  ts.begin(SCREEN_WIDTH, SCREEN_HEIGHT);
  ts.setCal(touch_map_x1, touch_map_x2, touch_map_y1, touch_map_y2, SCREEN_WIDTH, SCREEN_HEIGHT); // Raw xmin, xmax, ymin, ymax, width, height
  ts.setRotation(ROTATION);
}

//create a touch object
void my_touchpad_read(lv_indev_drv_t * indev_driver, lv_indev_data_t * data)
{
  if (ts.pressed()) 
  {
    data->state = LV_INDEV_STATE_PR;
    data->point.x = ts.X(); //map(p.x, touch_map_x1, touch_map_x2, 1, SCREEN_WIDTH);
    data->point.y = ts.Y(); //map(p.y, touch_map_y1, touch_map_y2, 1, SCREEN_HEIGHT);
//    Serial.printf("RawX: %d X: %d - RawY: %d Y: %d\n", ts.RawX(), ts.X(), ts.RawY(), ts.Y());
  }
  else
  {
    data->state = LV_INDEV_STATE_REL;
  }
}
*/

#endif
