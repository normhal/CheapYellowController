#ifndef ESP32_2432S028R_H
#define ESP32_2432S028R_H

/*******************************************************************************
 * Start of Arduino_GFX setting
 ******************************************************************************/
#define GFX_DEV_DEVICE ESP32_2432S028

#define ROTATION 0

#define GFX_BL 21

#define DISPLAY_WIDTH 240
#define DISPLAY_HEIGHT 320

#define SCREEN_WIDTH 240
#define SCREEN_HEIGHT 320

#define NAME_COL_WIDTH 180

#define TFT_BACKLIGHT 64

Arduino_DataBus *bus = new Arduino_ESP32SPI(2 /* DC */, 15 /* CS */, 14 /* SCK */, 13 /* MOSI */, 12 /* MISO */);
Arduino_GFX *gfx = new Arduino_ILI9341(bus, GFX_NOT_DEFINED /* RST */, 0 /* rotation */);

/*******************************************************************************
 * Resistive Touch
 ******************************************************************************/

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


/*
#include <SPI.h>
#include <XPT2046_Touchscreen.h>

#define XPT2046_IRQ 36
#define XPT2046_MOSI 32
#define XPT2046_MISO 39
#define XPT2046_CLK 25
#define XPT2046_CS 33

bool touch_swap_xy = false;
int16_t touch_map_x1 = 280;
int16_t touch_map_x2 = 3890;
int16_t touch_map_y1 = 172;
int16_t touch_map_y2 = 3727;

SPIClass touchscreenSPI = SPIClass(VSPI);
XPT2046_Touchscreen ts(XPT2046_CS, XPT2046_IRQ);

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
#endif
