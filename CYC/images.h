#ifndef EEZ_LVGL_UI_IMAGES_H
#define EEZ_LVGL_UI_IMAGES_H

#include <lvgl.h>

#ifdef __cplusplus
extern "C" {
#endif

extern const lv_img_dsc_t img_dcc_ex;
extern const lv_img_dsc_t img_6;
extern const lv_img_dsc_t img_x;
extern const lv_img_dsc_t img_40x40_lh_closed_0;
extern const lv_img_dsc_t img_40x40_lh_closed_90;
extern const lv_img_dsc_t img_40x40_lh_closed_180;
extern const lv_img_dsc_t img_40x40_lh_closed_270;
extern const lv_img_dsc_t img_40x40_lh_thrown_0;
extern const lv_img_dsc_t img_40x40_lh_thrown_90;
extern const lv_img_dsc_t img_40x40_lh_thrown_180;
extern const lv_img_dsc_t img_40x40_lh_thrown_270;
extern const lv_img_dsc_t img_40x40_lh_turn_0;
extern const lv_img_dsc_t img_40x40_lh_turn_90;
extern const lv_img_dsc_t img_40x40_lh_turn_180;
extern const lv_img_dsc_t img_40x40_lh_turn_270;
extern const lv_img_dsc_t img_40x40_rh_closed_0;
extern const lv_img_dsc_t img_40x40_rh_closed_90;
extern const lv_img_dsc_t img_40x40_rh_closed_180;
extern const lv_img_dsc_t img_40x40_rh_closed_270;
extern const lv_img_dsc_t img_40x40_rh_thrown_0;
extern const lv_img_dsc_t img_40x40_rh_thrown_90;
extern const lv_img_dsc_t img_40x40_rh_thrown_180;
extern const lv_img_dsc_t img_40x40_rh_thrown_270;
extern const lv_img_dsc_t img_40x40_rh_turn_0;
extern const lv_img_dsc_t img_40x40_rh_turn_90;
extern const lv_img_dsc_t img_40x40_rh_turn_180;
extern const lv_img_dsc_t img_40x40_rh_turn_270;
extern const lv_img_dsc_t img_40x40_straight_h;
extern const lv_img_dsc_t img_40x40_straight_v;
extern const lv_img_dsc_t img_40x40_turn_0;
extern const lv_img_dsc_t img_40x40_turn_90;
extern const lv_img_dsc_t img_40x40_turn_180;
extern const lv_img_dsc_t img_40x40_turn_270;
extern const lv_img_dsc_t img_80x80_kato_x_closed_0;
extern const lv_img_dsc_t img_80x80_kato_x_closed_90;
extern const lv_img_dsc_t img_80x80_kato_x_thrown_0;
extern const lv_img_dsc_t img_80x80_kato_x_thrown_90;

#ifndef EXT_IMG_DESC_T
#define EXT_IMG_DESC_T
typedef struct _ext_img_desc_t {
    const char *name;
    const lv_img_dsc_t *img_dsc;
} ext_img_desc_t;
#endif

extern const ext_img_desc_t images[37];


#ifdef __cplusplus
}
#endif

#endif /*EEZ_LVGL_UI_IMAGES_H*/