#ifndef ESP32_3248S035R_H
#define ESP32_3248S035R_H

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
 * Resistive Touch
 ******************************************************************************/

#include <SPI.h>
#include <xpt2046.h>

bool touch_swap_xy = false;
int16_t touch_map_x1 = 1850;
int16_t touch_map_x2 = 70;
int16_t touch_map_y1 = 0;
int16_t touch_map_y2 = 2000;

#define TOUCHSCREEN_SCLK_PIN (14)
#define TOUCHSCREEN_MISO_PIN (12)
#define TOUCHSCREEN_MOSI_PIN (13)
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

#endif
