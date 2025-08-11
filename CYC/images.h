#ifndef EEZ_LVGL_UI_IMAGES_H
#define EEZ_LVGL_UI_IMAGES_H

#include <lvgl.h>

#ifdef __cplusplus
extern "C" {
#endif

extern const lv_img_dsc_t img_dcc_ex;
extern const lv_img_dsc_t img_6;
extern const lv_img_dsc_t img_x;
extern const lv_img_dsc_t img_60x60_lh_yellow_closed_0;
extern const lv_img_dsc_t img_60x60_lh_yellow_closed_90;
extern const lv_img_dsc_t img_60x60_lh_yellow_closed_180;
extern const lv_img_dsc_t img_60x60_lh_yellow_closed_270;
extern const lv_img_dsc_t img_60x60_lh_yellow_thrown_0;
extern const lv_img_dsc_t img_60x60_lh_yellow_thrown_90;
extern const lv_img_dsc_t img_60x60_lh_yellow_thrown_180;
extern const lv_img_dsc_t img_60x60_lh_yellow_thrown_270;
extern const lv_img_dsc_t img_60x60_rh_yellow_closed_0;
extern const lv_img_dsc_t img_60x60_rh_yellow_closed_90;
extern const lv_img_dsc_t img_60x60_rh_yellow_closed_180;
extern const lv_img_dsc_t img_60x60_rh_yellow_closed_270;
extern const lv_img_dsc_t img_60x60_rh_yellow_thrown_0;
extern const lv_img_dsc_t img_60x60_rh_yellow_thrown_90;
extern const lv_img_dsc_t img_60x60_rh_yellow_thrown_180;
extern const lv_img_dsc_t img_60x60_rh_yellow_thrown_270;
extern const lv_img_dsc_t img_120x120_kato_x_yellow_0;
extern const lv_img_dsc_t img_120x120_kato_x_yellow_90;
extern const lv_img_dsc_t img_120x120_kato_x_yellow_closed_0;
extern const lv_img_dsc_t img_120x120_kato_x_yellow_closed_90;
extern const lv_img_dsc_t img_60x60_straight_h;
extern const lv_img_dsc_t img_60x60_straight_v;
extern const lv_img_dsc_t img_60x60_corner_0;
extern const lv_img_dsc_t img_60x60_corner_90;
extern const lv_img_dsc_t img_60x60_corner_180;
extern const lv_img_dsc_t img_60x60_corner_270;
extern const lv_img_dsc_t img_60x60_lh_curve_0;
extern const lv_img_dsc_t img_60x60_lh_curve_90;
extern const lv_img_dsc_t img_60x60_lh_curve_180;
extern const lv_img_dsc_t img_60x60_lh_curve_270;
extern const lv_img_dsc_t img_60x60_rh_curve_0;
extern const lv_img_dsc_t img_60x60_rh_curve_90;
extern const lv_img_dsc_t img_60x60_rh_curve_180;
extern const lv_img_dsc_t img_60x60_rh_curve_270;
extern const lv_img_dsc_t img_60x60_lh_turn_0;
extern const lv_img_dsc_t img_60x60_lh_turn_90;
extern const lv_img_dsc_t img_60x60_lh_turn_180;
extern const lv_img_dsc_t img_60x60_lh_turn_270;
extern const lv_img_dsc_t img_60x60_rh_turn_0;
extern const lv_img_dsc_t img_60x60_rh_turn_90;
extern const lv_img_dsc_t img_60x60_rh_turn_180;
extern const lv_img_dsc_t img_60x60_rh_turn_270;
extern const lv_img_dsc_t img_60x60_straight_0;
extern const lv_img_dsc_t img_60x60_straight_1;
extern const lv_img_dsc_t img_60x60_straight_2;
extern const lv_img_dsc_t img_60x60_straight_3;

#ifndef EXT_IMG_DESC_T
#define EXT_IMG_DESC_T
typedef struct _ext_img_desc_t {
    const char *name;
    const lv_img_dsc_t *img_dsc;
} ext_img_desc_t;
#endif

extern const ext_img_desc_t images[49];


#ifdef __cplusplus
}
#endif

#endif /*EEZ_LVGL_UI_IMAGES_H*/