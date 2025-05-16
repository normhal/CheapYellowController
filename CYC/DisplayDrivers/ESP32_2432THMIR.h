#ifndef ESP32_2432THMIR_H
#define ESP32_2432THMIR_H

/*******************************************************************************
 * Start of Arduino_GFX setting
 ******************************************************************************/
#define GFX_DEV_DEVICE ESP32_2432THMI

#define ROTATION 0

#define GFX_BL 38

#define DISPLAY_WIDTH 240
#define DISPLAY_HEIGHT 320

#define SCREEN_WIDTH 240
#define SCREEN_HEIGHT 320

#define NAME_COL_WIDTH 180

#define TFT_BACKLIGHT 64

Arduino_DataBus *bus = new Arduino_ESP32PAR8(
    7 /* DC */, 6 /* CS */, 8 /* WR */, -1 /* RD */,
    48 /* D0 */, 47 /* D1 */, 39 /* D2 */, 40/* D3 */, 41 /* D4 */, 42 /* D5 */, 45 /* D6 */, 46 /* D7 */);
Arduino_GFX *gfx = new Arduino_ST7789(bus, 7 /* RST */, ROTATION, false /* IPS */, SCREEN_WIDTH, SCREEN_HEIGHT, 0 /* col offset 1 */, 0 /* row offset 1 */, 0 /* col offset 2 */, 0 /* row offset 2 */);

/*******************************************************************************
 * Resistive Touch
 ******************************************************************************/

#include <SPI.h>
#include <xpt2046.h>

int16_t touch_map_x1 = 180;
int16_t touch_map_x2 = 1870;
int16_t touch_map_y1 = 140;
int16_t touch_map_y2 = 1877;

#define TOUCHSCREEN_SCLK_PIN (1)
#define TOUCHSCREEN_MISO_PIN (4)
#define TOUCHSCREEN_MOSI_PIN (3)
#define TOUCHSCREEN_CS_PIN   (2)
#define TOUCHSCREEN_IRQ_PIN  (9)

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
