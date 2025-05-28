#ifndef ESP32_4827S043R_H
#define ESP32_4827S043R_H

/*******************************************************************************
 * Start of Arduino_GFX setting
 ******************************************************************************/

#define GFX_BL 2 // default backlight pin, you may replace DF_GFX_BL to actual backlight pin
#define ROTATION 1

const uint16_t SCREEN_WIDTH = 272;          //Using EEZ Orientation
const uint16_t SCREEN_HEIGHT = 480;

#define AUTO_FLUSH true

#define NAME_COL_WIDTH 210

const uint8_t TFT_BACKLIGHT = 246;

Arduino_ESP32RGBPanel *rgbpanel = new Arduino_ESP32RGBPanel(
    40 /* DE */, 41 /* VSYNC */, 39 /* HSYNC */, 42 /* PCLK */,
    45 /* R0 */, 48 /* R1 */, 47 /* R2 */, 21 /* R3 */, 14 /* R4 */,
    5 /* G0 */, 6 /* G1 */, 7 /* G2 */, 15 /* G3 */, 16 /* G4 */, 4 /* G5 */,
    8 /* B0 */, 3 /* B1 */, 46 /* B2 */, 9 /* B3 */, 1 /* B4 */,
    0 /* hsync_polarity */, 1 /* hsync_front_porch */, 1 /* hsync_pulse_width */, 43 /* hsync_back_porch */,
    0 /* vsync_polarity */, 3 /* vsync_front_porch */, 1 /* vsync_pulse_width */, 12 /* vsync_back_porch */,
    1 /* pclk_active_neg */, 9000000 /* prefer_speed */);

Arduino_RGB_Display *gfx = new Arduino_RGB_Display(SCREEN_HEIGHT, SCREEN_WIDTH, rgbpanel, ROTATION , AUTO_FLUSH);

Arduino_DataBus *bus = create_default_Arduino_DataBus();

/*******************************************************************************
 * End of Arduino_GFX setting
 ******************************************************************************/

#include <XPT2046_Touchscreen.h>
#include <SPI.h>

#define TOUCH_CS 38   
#define TOUCH_IRQ 18   
#define TOUCH_MOSI 11 
#define TOUCH_MISO 13 
#define TOUCH_CLK 12  

class TouchConfig {
  public:
    XPT2046_Touchscreen* ts;
    SPIClass* touchSPI;

    // MAP TOUCH COORDINATES TO SCREEN DIMENSIONS
    const int minX = 300;
    const int maxX = 3800;
    const int minY = 3800;
    const int maxY = 300;

    TouchConfig() {
      touchSPI = new SPIClass(HSPI);
      ts = new XPT2046_Touchscreen(TOUCH_CS, TOUCH_IRQ);
    }

    bool begin() {
      touchSPI->begin(TOUCH_CLK, TOUCH_MISO, TOUCH_MOSI, TOUCH_CS);
        if (!ts->begin(*touchSPI)) {
        return false;
      }
      ts->setRotation(1); // CHOOSE ROTATION HERE
      return true;
    }

    void getScaledPoint(int& x, int& y, int& z) {
      if (ts->touched()) {
        TS_Point p = ts->getPoint();
        // Scale the point to the screen dimensions
        x = constrain(map(p.x, minX, maxX, 0, SCREEN_WIDTH), 0, SCREEN_WIDTH);
        y = constrain(map(p.y, minY, maxY, 0, SCREEN_HEIGHT), 0, SCREEN_HEIGHT);
        z = p.z;
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
    Serial.printf("X: %d, Y: %d\n", x, y);
  }
  else
  {
    data->state = LV_INDEV_STATE_RELEASED;
  }
}

#endif
