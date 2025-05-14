#ifndef ESP32_8048S070C_H
#define ESP32_8048S070C_H

/*******************************************************************************
 * Start of Arduino_GFX setting
 ******************************************************************************/

#define GFX_BL 2 // default backlight pin, you may replace DF_GFX_BL to actual backlight pin
#define ROTATION 1
#define SCREEN_WIDTH 272          //Using EEZ Orientation
#define SCREEN_HEIGHT 480
#define DISPLAY_WIDTH 480         //Physical Display Properties ex rotation
#define DISPLAY_HEIGHT 272
#define AUTO_FLUSH true

#define NAME_COL_WIDTH 360

#define TFT_BACKLIGHT 246

#define GFX_DEV_DEVICE ESP32_8048S070
#define GFX_BL 2
#define RGB_PANEL

Arduino_ESP32RGBPanel *rgbpanel = new Arduino_ESP32RGBPanel(
    41 /* DE */, 40 /* VSYNC */, 39 /* HSYNC */, 42 /* PCLK */,
    14 /* R0 */, 21 /* R1 */, 47 /* R2 */, 48 /* R3 */, 45 /* R4 */,
    9 /* G0 */, 46 /* G1 */, 3 /* G2 */, 8 /* G3 */, 16 /* G4 */, 1 /* G5 */,
    15 /* B0 */, 7 /* B1 */, 6 /* B2 */, 5 /* B3 */, 4 /* B4 */,
    0 /* hsync_polarity */, 180 /* hsync_front_porch */, 30 /* hsync_pulse_width */, 16 /* hsync_back_porch */,
    0 /* vsync_polarity */, 12 /* vsync_front_porch */, 13 /* vsync_pulse_width */, 10 /* vsync_back_porch */,
    1 /* pclk_active_neg */);
Arduino_RGB_Display *gfx = new Arduino_RGB_Display(
    800 /* width */, 480 /* height */, rgbpanel, 0 /* rotation */, true /* auto_flush */);

Arduino_DataBus *bus = create_default_Arduino_DataBus();

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

//create a touch object   TO BE COMPLETED!
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
