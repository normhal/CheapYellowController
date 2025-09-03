#ifndef ESP32_JC4827W543R_H
#define ESP32_JC4827W543R_H

/*******************************************************************************
 * Start of Arduino_GFX setting
 ******************************************************************************/

#define TFT_BACKLIGHT 240
#define MIN_BL 10
#define FUNCCOL 100
#define ACC_PER_PAGE 10

#define GFX_BL 1 // backlight pin

#define SCREEN_WIDTH 272
#define SCREEN_HEIGHT 480

#define ROTATION 1

#define NAME_COL0_WIDTH 200
#define NAME_COL1_WIDTH 50

/*******************************************************************************
 * Display Driver for GFX Library for Arduino by "moononournation"
 ******************************************************************************/

#define AUTO_FLUSH true

#define GFX_DEV_DEVICE ESP32_4827W543

#define TFT_CS   45
#define TFT_SCK  47
#define TFT_SDA0 21
#define TFT_SDA1 48
#define TFT_SDA2 40
#define TFT_SDA3 39
#define TFT_RST GFX_NOT_DEFINED
#define IPS true

//#define DIRECT_MODE // Uncomment to enable full frame buffer - not supported by Arduino_GFX
/*
Arduino_DataBus *bus = new Arduino_ESP32QSPI(TFT_CS, TFT_SCK, TFT_SDA0, TFT_SDA1, TFT_SDA2, TFT_SDA3);

//Arduino_NV3041A *panel = new Arduino_NV3041A(bus, TFT_RST, ROTATION, IPS);

Arduino_GFX *gfx = new Arduino_NV3041A(bus, GFX_NOT_DEFINED, ROTATION, IPS);

//#define CANVAS
*/

Arduino_DataBus *bus = new Arduino_ESP32QSPI(TFT_CS, TFT_SCK, TFT_SDA0, TFT_SDA1, TFT_SDA2, TFT_SDA3);
Arduino_GFX *g = new Arduino_NV3041A(bus, GFX_NOT_DEFINED /* RST */, 1 /* rotation */, true /* IPS */);
Arduino_GFX *gfx = new Arduino_Canvas(SCREEN_WIDTH /* width */, SCREEN_HEIGHT /* height */, g);

#define CANVAS

/*******************************************************************************
 * Rotary Encoder Specifics
 ******************************************************************************/
 
 #define I2C_SDA          17
 #define I2C_SCL          18
 #define SS_SWITCH        24
 #define SEESAW_ADDR    0x36


 TwoWire RE_Bus = TwoWire(1);      //For Capacitive Displays
 Adafruit_seesaw ss(&Wire1);       //For Capacitive Displays

 void initRE()
 {
   //Serial1.setPins(RX_1, TX_1);
   Wire1.setPins(I2C_SDA, I2C_SCL);
   Wire1.begin(I2C_SDA, I2C_SCL);
 }

/*******************************************************************************
 * Resistive Touch
 ******************************************************************************/

#include <XPT2046_Touchscreen.h>
#include <SPI.h>

#define TOUCH_CS 38   
#define TOUCH_IRQ 3   
#define TOUCH_MOSI 11 
#define TOUCH_MISO 13 
#define TOUCH_CLK 12  

class TouchConfig 
{
  public:
    XPT2046_Touchscreen* ts;
    SPIClass* touchSPI;

    const int minX = 300;
    const int maxX = 3800;
    const int minY = 300;
    const int maxY = 3800;

    TouchConfig() 
    {
      touchSPI = new SPIClass(HSPI);
      ts = new XPT2046_Touchscreen(TOUCH_CS, TOUCH_IRQ);
    }

    bool begin() 
    {
      touchSPI->begin(TOUCH_CLK, TOUCH_MISO, TOUCH_MOSI, TOUCH_CS);
      if (!ts->begin(*touchSPI)) return false;
      ts->setRotation(1); // TOUCH ROTATION
      return true;
    }

    void getScaledPoint(int& x, int& y, int& z) 
    {
      if (ts->touched()) 
      {
        TS_Point p = ts->getPoint();
        // Scale the point to the screen dimensions
        x = constrain(map(p.x, maxX, minX, 0, SCREEN_WIDTH), 0, SCREEN_WIDTH);
        y = constrain(map(p.y, minY, maxY, 0, SCREEN_HEIGHT), 0, SCREEN_HEIGHT);
        //z = p.z;
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
}

#endif
