#ifndef EEZ_LVGL_UI_IMAGES_H
#define EEZ_LVGL_UI_IMAGES_H

#include <lvgl.h>

#ifdef __cplusplus
extern "C" {
#endif

extern const lv_img_dsc_t img_dcc_ex;
extern const lv_img_dsc_t img_6;
extern const lv_img_dsc_t img_x;
extern const lv_img_dsc_t img_lht;
extern const lv_img_dsc_t img_rht;
extern const lv_img_dsc_t img_lhc;
extern const lv_img_dsc_t img_rhc;
extern const lv_img_dsc_t img_34x34_lh_curve_0;
extern const lv_img_dsc_t img_34x34_rh_curve_0;
extern const lv_img_dsc_t img_34x34_straight_h;
extern const lv_img_dsc_t img_34x34_corner;
extern const lv_img_dsc_t img_68x68_kato_x_closed_0;
extern const lv_img_dsc_t img_68x68_kato_x_thrown_0;
extern const lv_img_dsc_t img_34x34_rh_closed_180;
extern const lv_img_dsc_t img_34x34_rh_thrown_180;
extern const lv_img_dsc_t img_34x34_rh_closed_90;
extern const lv_img_dsc_t img_34x34_rh_closed_181;
extern const lv_img_dsc_t img_34x34_rh_closed_270;
extern const lv_img_dsc_t img_34x34_rh_curve_1;
extern const lv_img_dsc_t img_34x34_rh_curve_90;
extern const lv_img_dsc_t img_34x34_rh_curve_180;
extern const lv_img_dsc_t img_34x34_rh_curve_270;
extern const lv_img_dsc_t img_34x34_rh_thrown_0;
extern const lv_img_dsc_t img_34x34_rh_thrown_90;
extern const lv_img_dsc_t img_34x34_rh_thrown_181;
extern const lv_img_dsc_t img_34x34_rh_thrown_270;
extern const lv_img_dsc_t img_34x34_lh_closed_0;
extern const lv_img_dsc_t img_34x34_lh_closed_90;
extern const lv_img_dsc_t img_34x34_lh_closed_180;
extern const lv_img_dsc_t img_34x34_lh_closed_270;
extern const lv_img_dsc_t img_34x34_lh_thrown_0;
extern const lv_img_dsc_t img_34x34_lh_thrown_90;
extern const lv_img_dsc_t img_34x34_lh_thrown_180;
extern const lv_img_dsc_t img_34x34_lh_thrown_270;
extern const lv_img_dsc_t img_34x34_straight_v;
extern const lv_img_dsc_t img_34x34_corner_0;
extern const lv_img_dsc_t img_34x34_corner_90;
extern const lv_img_dsc_t img_34x34_corner_180;
extern const lv_img_dsc_t img_34x34_corner_270;
extern const lv_img_dsc_t img_34x34_lh_yellow_closed_0;
extern const lv_img_dsc_t img_34x34_lh_yellow_closed_90;
extern const lv_img_dsc_t img_34x34_lh_yellow_closed_180;
extern const lv_img_dsc_t img_34x34_lh_yellow_closed_270;
extern const lv_img_dsc_t img_34x34_lh_yellow_thrown_0;
extern const lv_img_dsc_t img_34x34_lh_yellow_thrown_90;
extern const lv_img_dsc_t img_34x34_lh_yellow_thrown_180;
extern const lv_img_dsc_t img_34x34_lh_yellow_thrown_270;
extern const lv_img_dsc_t img_34x34_lh_yellow_turn_0;
extern const lv_img_dsc_t img_34x34_lh_yellow_turn_90;
extern const lv_img_dsc_t img_34x34_lh_yellow_turn_180;
extern const lv_img_dsc_t img_34x34_lh_yellow_turn_270;
extern const lv_img_dsc_t img_34x34_rh_yellow_closed_0;
extern const lv_img_dsc_t img_34x34_rh_yellow_closed_90;
extern const lv_img_dsc_t img_34x34_rh_yellow_closed_180;
extern const lv_img_dsc_t img_34x34_rh_yellow_closed_270;
extern const lv_img_dsc_t img_34x34_rh_yellow_thrown_0;
extern const lv_img_dsc_t img_34x34_rh_yellow_thrown_90;
extern const lv_img_dsc_t img_34x34_rh_yellow_thrown_180;
extern const lv_img_dsc_t img_34x34_rh_yellow_thrown_270;
extern const lv_img_dsc_t img_34x34_rh_yellow_turn_0;
extern const lv_img_dsc_t img_34x34_rh_yellow_turn_90;
extern const lv_img_dsc_t img_34x34_rh_yellow_turn_180;
extern const lv_img_dsc_t img_34x34_rh_yellow_turn_270;
extern const lv_img_dsc_t img_68x68_kato_x_yellow_closed_0;
extern const lv_img_dsc_t img_68x68_kato_x_yellow_closed_90;
extern const lv_img_dsc_t img_68x68_kato_x_yellow_thrown_0;
extern const lv_img_dsc_t img_68x68_kato_x_yellow_thrown_90;
extern const lv_img_dsc_t img_34x34_turn_0;
extern const lv_img_dsc_t img_34x34_turn_90;
extern const lv_img_dsc_t img_34x34_turn_180;
extern const lv_img_dsc_t img_34x34_turn_270;

#ifndef EXT_IMG_DESC_T
#define EXT_IMG_DESC_T
typedef struct _ext_img_desc_t {
    const char *name;
    const lv_img_dsc_t *img_dsc;
} ext_img_desc_t;
#endif

extern const ext_img_desc_t images[71];


#ifdef __cplusplus
}
#endif

#endif /*EEZ_LVGL_UI_IMAGES_H*/