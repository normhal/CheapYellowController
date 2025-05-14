#ifndef ESP32_4848S040C_H
#define ESP32_4848S040C_H

/*******************************************************************************
 * Start of Arduino_GFX setting
 ******************************************************************************/

#define ROTATION 1
#define SCREEN_WIDTH 480          //Using EEZ Orientation
#define SCREEN_HEIGHT 480
#define DISPLAY_WIDTH 480         //Physical Display Properties ex rotation
#define DISPLAY_HEIGHT 480
#define AUTO_FLUSH true

#define NAME_COL_WIDTH 360

#define TFT_BACKLIGHT 64

#define GFX_DEV_DEVICE ESP32_4848S040_86BOX_GUITION
#define GFX_BL 38

Arduino_DataBus *bus = new Arduino_SWSPI(
    GFX_NOT_DEFINED /* DC */, 39 /* CS */,
    48 /* SCK */, 47 /* MOSI */, GFX_NOT_DEFINED /* MISO */);
#define RGB_PANEL
Arduino_ESP32RGBPanel *rgbpanel = new Arduino_ESP32RGBPanel(
    18 /* DE */, 17 /* VSYNC */, 16 /* HSYNC */, 21 /* PCLK */,
    11 /* R0 */, 12 /* R1 */, 13 /* R2 */, 14 /* R3 */, 0 /* R4 */,
    8 /* G0 */, 20 /* G1 */, 3 /* G2 */, 46 /* G3 */, 9 /* G4 */, 10 /* G5 */,
    4 /* B0 */, 5 /* B1 */, 6 /* B2 */, 7 /* B3 */, 15 /* B4 */,
    1 /* hsync_polarity */, 10 /* hsync_front_porch */, 8 /* hsync_pulse_width */, 50 /* hsync_back_porch */,
    1 /* vsync_polarity */, 10 /* vsync_front_porch */, 8 /* vsync_pulse_width */, 20 /* vsync_back_porch */);
Arduino_RGB_Display *gfx = new Arduino_RGB_Display( DISPLAY_WIDTH, DISPLAY_HEIGHT, rgbpanel, ROTATION, AUTO_FLUSH,
    bus, GFX_NOT_DEFINED /* RST */, st7701_type9_init_operations, sizeof(st7701_type9_init_operations));

/*******************************************************************************
 * End of Arduino_GFX setting
 ******************************************************************************/

#include <TAMC_GT911.h>

//Initialize the Touch Controller
void initTouch()
{
  ts.begin();
  ts.setRotation(ROTATION);
}

//create a touch object   TO BE COMPLETED - REVIEWED! 
void my_touchpad_read(lv_indev_drv_t * indev_driver, lv_indev_data_t * data)
{
  if (ts.tirqTouched())
  {
    if (ts.touched())
    {
      TS_Point p = ts.getPoint();
      data->state = LV_INDEV_STATE_PR;
      data->point.x = map(p.x, 400, 3800, 0, 271);
      if (data->point.x < 0) data->point.x = 0;
      data->point.y = map(p.y, 200, 3850, 479, 0);
      if (data->point.y < 0) data->point.y = 0;
      delay(100);
    }
  }
}

#endif
