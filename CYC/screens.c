#include <string.h>

#include "screens.h"
#include "images.h"
#include "fonts.h"
#include "actions.h"
#include "vars.h"
#include "styles.h"
#include "ui.h"

#include <string.h>

objects_t objects;
lv_obj_t *tick_value_change_obj;
uint32_t active_theme_index = 0;

static void event_handler_checked_cb_main_btn_stop(lv_event_t *e) {
    lv_obj_t *ta = lv_event_get_target(e);
    if (lv_obj_has_state(ta, LV_STATE_CHECKED)) {
        action_general_button(e);
    }
}

static void event_handler_unchecked_cb_main_btn_stop(lv_event_t *e) {
    lv_obj_t *ta = lv_event_get_target(e);
    if (!lv_obj_has_state(ta, LV_STATE_CHECKED)) {
        action_general_button(e);
    }
}

static void event_handler_checked_cb_main_btn_power(lv_event_t *e) {
    lv_obj_t *ta = lv_event_get_target(e);
    if (lv_obj_has_state(ta, LV_STATE_CHECKED)) {
        action_general_button(e);
    }
}

static void event_handler_unchecked_cb_main_btn_power(lv_event_t *e) {
    lv_obj_t *ta = lv_event_get_target(e);
    if (!lv_obj_has_state(ta, LV_STATE_CHECKED)) {
        action_general_button(e);
    }
}

static void event_handler_checked_cb_throttle_sw_dir(lv_event_t *e) {
    lv_obj_t *ta = lv_event_get_target(e);
    if (lv_obj_has_state(ta, LV_STATE_CHECKED)) {
        action_throttle_button(e);
    }
}

static void event_handler_unchecked_cb_throttle_sw_dir(lv_event_t *e) {
    lv_obj_t *ta = lv_event_get_target(e);
    if (!lv_obj_has_state(ta, LV_STATE_CHECKED)) {
        action_throttle_button(e);
    }
}

static void event_handler_checked_cb_throttle_ta_guest_address(lv_event_t *e) {
    lv_obj_t *ta = lv_event_get_target(e);
    if (lv_obj_has_state(ta, LV_STATE_CHECKED)) {
        action_throttle_button(e);
    }
}

static void event_handler_unchecked_cb_throttle_ta_guest_address(lv_event_t *e) {
    lv_obj_t *ta = lv_event_get_target(e);
    if (!lv_obj_has_state(ta, LV_STATE_CHECKED)) {
        action_throttle_button(e);
    }
}

static void event_handler_checked_cb_roster_btn_select_loco(lv_event_t *e) {
    lv_obj_t *ta = lv_event_get_target(e);
    if (lv_obj_has_state(ta, LV_STATE_CHECKED)) {
        action_roster_button(e);
    }
}

static void event_handler_unchecked_cb_roster_btn_select_loco(lv_event_t *e) {
    lv_obj_t *ta = lv_event_get_target(e);
    if (!lv_obj_has_state(ta, LV_STATE_CHECKED)) {
        action_roster_button(e);
    }
}

static void event_handler_checked_cb_roster_btn_edit_loco(lv_event_t *e) {
    lv_obj_t *ta = lv_event_get_target(e);
    if (lv_obj_has_state(ta, LV_STATE_CHECKED)) {
        action_roster_button(e);
    }
}

static void event_handler_unchecked_cb_roster_btn_edit_loco(lv_event_t *e) {
    lv_obj_t *ta = lv_event_get_target(e);
    if (!lv_obj_has_state(ta, LV_STATE_CHECKED)) {
        action_roster_button(e);
    }
}

static void event_handler_checked_cb_roster_obj0(lv_event_t *e) {
    lv_obj_t *ta = lv_event_get_target(e);
    if (lv_obj_has_state(ta, LV_STATE_CHECKED)) {
        action_roster_button(e);
    }
}

static void event_handler_checked_cb_roster_obj1(lv_event_t *e) {
    lv_obj_t *ta = lv_event_get_target(e);
    if (lv_obj_has_state(ta, LV_STATE_CHECKED)) {
        action_roster_button(e);
    }
}

static void event_handler_checked_cb_roster_obj2(lv_event_t *e) {
    lv_obj_t *ta = lv_event_get_target(e);
    if (lv_obj_has_state(ta, LV_STATE_CHECKED)) {
        action_roster_button(e);
    }
}

static void event_handler_checked_cb_roster_obj3(lv_event_t *e) {
    lv_obj_t *ta = lv_event_get_target(e);
    if (lv_obj_has_state(ta, LV_STATE_CHECKED)) {
        action_roster_button(e);
    }
}

static void event_handler_checked_cb_roster_obj4(lv_event_t *e) {
    lv_obj_t *ta = lv_event_get_target(e);
    if (lv_obj_has_state(ta, LV_STATE_CHECKED)) {
        action_roster_button(e);
    }
}

static void event_handler_checked_cb_roster_obj5(lv_event_t *e) {
    lv_obj_t *ta = lv_event_get_target(e);
    if (lv_obj_has_state(ta, LV_STATE_CHECKED)) {
        action_roster_button(e);
    }
}

static void event_handler_checked_cb_roster_obj6(lv_event_t *e) {
    lv_obj_t *ta = lv_event_get_target(e);
    if (lv_obj_has_state(ta, LV_STATE_CHECKED)) {
        action_roster_button(e);
    }
}

static void event_handler_checked_cb_roster_obj7(lv_event_t *e) {
    lv_obj_t *ta = lv_event_get_target(e);
    if (lv_obj_has_state(ta, LV_STATE_CHECKED)) {
        action_roster_button(e);
    }
}

static void event_handler_checked_cb_edit_loco_btn_s0(lv_event_t *e) {
    lv_obj_t *ta = lv_event_get_target(e);
    if (lv_obj_has_state(ta, LV_STATE_CHECKED)) {
        action_fedit_slot(e);
    }
}

static void event_handler_unchecked_cb_edit_loco_btn_s0(lv_event_t *e) {
    lv_obj_t *ta = lv_event_get_target(e);
    if (!lv_obj_has_state(ta, LV_STATE_CHECKED)) {
        action_fclear_slot(e);
    }
}

static void event_handler_checked_cb_edit_loco_btn_s1(lv_event_t *e) {
    lv_obj_t *ta = lv_event_get_target(e);
    if (lv_obj_has_state(ta, LV_STATE_CHECKED)) {
        action_fedit_slot(e);
    }
}

static void event_handler_unchecked_cb_edit_loco_btn_s1(lv_event_t *e) {
    lv_obj_t *ta = lv_event_get_target(e);
    if (!lv_obj_has_state(ta, LV_STATE_CHECKED)) {
        action_fclear_slot(e);
    }
}

static void event_handler_checked_cb_edit_loco_btn_s2(lv_event_t *e) {
    lv_obj_t *ta = lv_event_get_target(e);
    if (lv_obj_has_state(ta, LV_STATE_CHECKED)) {
        action_fedit_slot(e);
    }
}

static void event_handler_unchecked_cb_edit_loco_btn_s2(lv_event_t *e) {
    lv_obj_t *ta = lv_event_get_target(e);
    if (!lv_obj_has_state(ta, LV_STATE_CHECKED)) {
        action_fclear_slot(e);
    }
}

static void event_handler_checked_cb_edit_loco_btn_s3(lv_event_t *e) {
    lv_obj_t *ta = lv_event_get_target(e);
    if (lv_obj_has_state(ta, LV_STATE_CHECKED)) {
        action_fedit_slot(e);
    }
}

static void event_handler_unchecked_cb_edit_loco_btn_s3(lv_event_t *e) {
    lv_obj_t *ta = lv_event_get_target(e);
    if (!lv_obj_has_state(ta, LV_STATE_CHECKED)) {
        action_fclear_slot(e);
    }
}

static void event_handler_checked_cb_edit_loco_btn_s4(lv_event_t *e) {
    lv_obj_t *ta = lv_event_get_target(e);
    if (lv_obj_has_state(ta, LV_STATE_CHECKED)) {
        action_fedit_slot(e);
    }
}

static void event_handler_unchecked_cb_edit_loco_btn_s4(lv_event_t *e) {
    lv_obj_t *ta = lv_event_get_target(e);
    if (!lv_obj_has_state(ta, LV_STATE_CHECKED)) {
        action_fclear_slot(e);
    }
}

static void event_handler_checked_cb_edit_loco_btn_s5(lv_event_t *e) {
    lv_obj_t *ta = lv_event_get_target(e);
    if (lv_obj_has_state(ta, LV_STATE_CHECKED)) {
        action_fedit_slot(e);
    }
}

static void event_handler_unchecked_cb_edit_loco_btn_s5(lv_event_t *e) {
    lv_obj_t *ta = lv_event_get_target(e);
    if (!lv_obj_has_state(ta, LV_STATE_CHECKED)) {
        action_fclear_slot(e);
    }
}

static void event_handler_checked_cb_edit_loco_btn_s6(lv_event_t *e) {
    lv_obj_t *ta = lv_event_get_target(e);
    if (lv_obj_has_state(ta, LV_STATE_CHECKED)) {
        action_fedit_slot(e);
    }
}

static void event_handler_unchecked_cb_edit_loco_btn_s6(lv_event_t *e) {
    lv_obj_t *ta = lv_event_get_target(e);
    if (!lv_obj_has_state(ta, LV_STATE_CHECKED)) {
        action_fclear_slot(e);
    }
}

static void event_handler_checked_cb_edit_loco_btn_s7(lv_event_t *e) {
    lv_obj_t *ta = lv_event_get_target(e);
    if (lv_obj_has_state(ta, LV_STATE_CHECKED)) {
        action_fedit_slot(e);
    }
}

static void event_handler_unchecked_cb_edit_loco_btn_s7(lv_event_t *e) {
    lv_obj_t *ta = lv_event_get_target(e);
    if (!lv_obj_has_state(ta, LV_STATE_CHECKED)) {
        action_fclear_slot(e);
    }
}

static void event_handler_checked_cb_edit_loco_btn_s8(lv_event_t *e) {
    lv_obj_t *ta = lv_event_get_target(e);
    if (lv_obj_has_state(ta, LV_STATE_CHECKED)) {
        action_fedit_slot(e);
    }
}

static void event_handler_unchecked_cb_edit_loco_btn_s8(lv_event_t *e) {
    lv_obj_t *ta = lv_event_get_target(e);
    if (!lv_obj_has_state(ta, LV_STATE_CHECKED)) {
        action_fclear_slot(e);
    }
}

static void event_handler_checked_cb_edit_loco_btn_s9(lv_event_t *e) {
    lv_obj_t *ta = lv_event_get_target(e);
    if (lv_obj_has_state(ta, LV_STATE_CHECKED)) {
        action_fedit_slot(e);
    }
}

static void event_handler_unchecked_cb_edit_loco_btn_s9(lv_event_t *e) {
    lv_obj_t *ta = lv_event_get_target(e);
    if (!lv_obj_has_state(ta, LV_STATE_CHECKED)) {
        action_fclear_slot(e);
    }
}

static void event_handler_checked_cb_program_btn_read(lv_event_t *e) {
    lv_obj_t *ta = lv_event_get_target(e);
    if (lv_obj_has_state(ta, LV_STATE_CHECKED)) {
        action_program_button(e);
    }
}

static void event_handler_checked_cb_program_btn_write(lv_event_t *e) {
    lv_obj_t *ta = lv_event_get_target(e);
    if (lv_obj_has_state(ta, LV_STATE_CHECKED)) {
        action_program_button(e);
    }
}

void create_screen_main() {
    lv_obj_t *obj = lv_obj_create(0);
    objects.main = obj;
    lv_obj_set_pos(obj, 0, 0);
    lv_obj_set_size(obj, 320, 480);
    lv_obj_clear_flag(obj, LV_OBJ_FLAG_PRESS_LOCK|LV_OBJ_FLAG_CLICK_FOCUSABLE|LV_OBJ_FLAG_GESTURE_BUBBLE|LV_OBJ_FLAG_SNAPPABLE|LV_OBJ_FLAG_SCROLLABLE|LV_OBJ_FLAG_SCROLL_ELASTIC|LV_OBJ_FLAG_SCROLL_MOMENTUM|LV_OBJ_FLAG_SCROLL_CHAIN_HOR|LV_OBJ_FLAG_SCROLL_CHAIN_VER);
    lv_obj_set_style_bg_color(obj, lv_color_hex(0xffc89600), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(obj, 10, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_ofs_x(obj, 5, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_ofs_y(obj, 5, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_opa(obj, 192, LV_PART_MAIN | LV_STATE_DEFAULT);
    {
        lv_obj_t *parent_obj = obj;
        {
            // btnHome
            lv_obj_t *obj = lv_btn_create(parent_obj);
            objects.btn_home = obj;
            lv_obj_set_pos(obj, 82, 2);
            lv_obj_set_size(obj, 156, 36);
            lv_obj_add_event_cb(obj, action_general_button, LV_EVENT_RELEASED, (void *)5);
            lv_obj_set_style_bg_img_src(obj, &img_dcc_ex, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_bg_color(obj, lv_color_hex(0xffc89600), LV_PART_MAIN | LV_STATE_DEFAULT);
        }
        {
            lv_obj_t *obj = lv_label_create(parent_obj);
            objects.obj8 = obj;
            lv_obj_set_pos(obj, 105, 36);
            lv_obj_set_size(obj, 110, 20);
            lv_obj_clear_flag(obj, LV_OBJ_FLAG_CLICK_FOCUSABLE|LV_OBJ_FLAG_GESTURE_BUBBLE|LV_OBJ_FLAG_PRESS_LOCK|LV_OBJ_FLAG_SCROLLABLE|LV_OBJ_FLAG_SCROLL_CHAIN_HOR|LV_OBJ_FLAG_SCROLL_CHAIN_VER|LV_OBJ_FLAG_SCROLL_ELASTIC|LV_OBJ_FLAG_SCROLL_MOMENTUM|LV_OBJ_FLAG_SNAPPABLE);
            lv_obj_set_style_text_align(obj, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_font(obj, &lv_font_montserrat_18, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_color(obj, lv_color_hex(0xffffffff), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_label_set_text(obj, "Controller");
        }
        {
            // btnStop
            lv_obj_t *obj = lv_btn_create(parent_obj);
            objects.btn_stop = obj;
            lv_obj_set_pos(obj, 6, 6);
            lv_obj_set_size(obj, 60, 48);
            lv_obj_add_event_cb(obj, event_handler_checked_cb_main_btn_stop, LV_EVENT_VALUE_CHANGED, (void *)1);
            lv_obj_add_event_cb(obj, event_handler_unchecked_cb_main_btn_stop, LV_EVENT_VALUE_CHANGED, (void *)2);
            lv_obj_add_flag(obj, LV_OBJ_FLAG_CHECKABLE);
            lv_obj_clear_flag(obj, LV_OBJ_FLAG_CLICK_FOCUSABLE|LV_OBJ_FLAG_GESTURE_BUBBLE|LV_OBJ_FLAG_SCROLL_CHAIN_HOR|LV_OBJ_FLAG_SCROLL_CHAIN_VER|LV_OBJ_FLAG_SCROLL_ELASTIC|LV_OBJ_FLAG_SCROLL_MOMENTUM|LV_OBJ_FLAG_SNAPPABLE);
            lv_obj_set_style_bg_color(obj, lv_color_hex(0xffff0000), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_bg_grad_dir(obj, LV_GRAD_DIR_VER, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_bg_grad_color(obj, lv_color_hex(0xff000000), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_outline_width(obj, 1, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_shadow_width(obj, 5, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_shadow_ofs_y(obj, 3, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_shadow_ofs_x(obj, 3, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_shadow_spread(obj, 2, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_shadow_opa(obj, 128, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_font(obj, &lv_font_montserrat_18, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_shadow_color(obj, lv_color_hex(0xff000000), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_bg_color(obj, lv_color_hex(0xff000000), LV_PART_MAIN | LV_STATE_PRESSED);
            lv_obj_set_style_bg_grad_color(obj, lv_color_hex(0xffffff00), LV_PART_MAIN | LV_STATE_PRESSED);
            lv_obj_set_style_bg_grad_dir(obj, LV_GRAD_DIR_VER, LV_PART_MAIN | LV_STATE_PRESSED);
            lv_obj_set_style_text_color(obj, lv_color_hex(0xff000000), LV_PART_MAIN | LV_STATE_PRESSED);
            lv_obj_set_style_shadow_width(obj, 0, LV_PART_MAIN | LV_STATE_PRESSED);
            lv_obj_set_style_shadow_ofs_x(obj, 0, LV_PART_MAIN | LV_STATE_PRESSED);
            lv_obj_set_style_shadow_ofs_y(obj, 0, LV_PART_MAIN | LV_STATE_PRESSED);
            lv_obj_set_style_shadow_spread(obj, 0, LV_PART_MAIN | LV_STATE_PRESSED);
            lv_obj_set_style_transform_width(obj, -2, LV_PART_MAIN | LV_STATE_PRESSED);
            lv_obj_set_style_transform_height(obj, -2, LV_PART_MAIN | LV_STATE_PRESSED);
            lv_obj_set_style_shadow_opa(obj, 128, LV_PART_MAIN | LV_STATE_PRESSED);
            lv_obj_set_style_bg_color(obj, lv_color_hex(0xff000000), LV_PART_MAIN | LV_STATE_CHECKED);
            lv_obj_set_style_bg_grad_color(obj, lv_color_hex(0xff00ff00), LV_PART_MAIN | LV_STATE_CHECKED);
            lv_obj_set_style_bg_grad_dir(obj, LV_GRAD_DIR_VER, LV_PART_MAIN | LV_STATE_CHECKED);
            lv_obj_set_style_shadow_width(obj, 5, LV_PART_MAIN | LV_STATE_CHECKED);
            lv_obj_set_style_shadow_ofs_x(obj, 3, LV_PART_MAIN | LV_STATE_CHECKED);
            lv_obj_set_style_shadow_ofs_y(obj, 3, LV_PART_MAIN | LV_STATE_CHECKED);
            lv_obj_set_style_shadow_spread(obj, 2, LV_PART_MAIN | LV_STATE_CHECKED);
            lv_obj_set_style_shadow_opa(obj, 192, LV_PART_MAIN | LV_STATE_CHECKED);
            {
                lv_obj_t *parent_obj = obj;
                {
                    // lblStop
                    lv_obj_t *obj = lv_label_create(parent_obj);
                    objects.lbl_stop = obj;
                    lv_obj_set_pos(obj, 0, 0);
                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                    lv_obj_clear_flag(obj, LV_OBJ_FLAG_CLICK_FOCUSABLE|LV_OBJ_FLAG_GESTURE_BUBBLE|LV_OBJ_FLAG_PRESS_LOCK|LV_OBJ_FLAG_SCROLLABLE|LV_OBJ_FLAG_SCROLL_CHAIN_HOR|LV_OBJ_FLAG_SCROLL_CHAIN_VER|LV_OBJ_FLAG_SCROLL_ELASTIC|LV_OBJ_FLAG_SCROLL_MOMENTUM|LV_OBJ_FLAG_SNAPPABLE);
                    lv_obj_set_style_align(obj, LV_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_text_font(obj, &lv_font_montserrat_16, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_text_font(obj, &lv_font_montserrat_14, LV_PART_MAIN | LV_STATE_CHECKED);
                    lv_label_set_text(obj, "Stop");
                }
            }
        }
        {
            // btnPower
            lv_obj_t *obj = lv_btn_create(parent_obj);
            objects.btn_power = obj;
            lv_obj_set_pos(obj, 254, 6);
            lv_obj_set_size(obj, 60, 48);
            lv_obj_add_event_cb(obj, event_handler_checked_cb_main_btn_power, LV_EVENT_VALUE_CHANGED, (void *)3);
            lv_obj_add_event_cb(obj, event_handler_unchecked_cb_main_btn_power, LV_EVENT_VALUE_CHANGED, (void *)4);
            lv_obj_add_flag(obj, LV_OBJ_FLAG_CHECKABLE);
            lv_obj_clear_flag(obj, LV_OBJ_FLAG_CLICK_FOCUSABLE|LV_OBJ_FLAG_GESTURE_BUBBLE|LV_OBJ_FLAG_SCROLL_CHAIN_HOR|LV_OBJ_FLAG_SCROLL_CHAIN_VER|LV_OBJ_FLAG_SCROLL_ELASTIC|LV_OBJ_FLAG_SCROLL_MOMENTUM|LV_OBJ_FLAG_SNAPPABLE);
            lv_obj_set_style_bg_color(obj, lv_color_hex(0xffff0000), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_bg_grad_dir(obj, LV_GRAD_DIR_VER, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_bg_grad_color(obj, lv_color_hex(0xff000000), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_shadow_width(obj, 5, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_shadow_ofs_x(obj, 3, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_shadow_ofs_y(obj, 3, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_shadow_spread(obj, 2, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_shadow_opa(obj, 128, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_shadow_color(obj, lv_color_hex(0xff000000), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_border_color(obj, lv_color_hex(0xff000000), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_border_width(obj, 1, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_bg_color(obj, lv_color_hex(0xff000000), LV_PART_MAIN | LV_STATE_PRESSED);
            lv_obj_set_style_bg_grad_color(obj, lv_color_hex(0xff00ff00), LV_PART_MAIN | LV_STATE_PRESSED);
            lv_obj_set_style_bg_grad_dir(obj, LV_GRAD_DIR_VER, LV_PART_MAIN | LV_STATE_PRESSED);
            lv_obj_set_style_shadow_width(obj, 0, LV_PART_MAIN | LV_STATE_PRESSED);
            lv_obj_set_style_shadow_ofs_x(obj, 0, LV_PART_MAIN | LV_STATE_PRESSED);
            lv_obj_set_style_shadow_ofs_y(obj, 0, LV_PART_MAIN | LV_STATE_PRESSED);
            lv_obj_set_style_shadow_spread(obj, 0, LV_PART_MAIN | LV_STATE_PRESSED);
            lv_obj_set_style_transform_width(obj, -2, LV_PART_MAIN | LV_STATE_PRESSED);
            lv_obj_set_style_transform_height(obj, -2, LV_PART_MAIN | LV_STATE_PRESSED);
            lv_obj_set_style_shadow_opa(obj, 128, LV_PART_MAIN | LV_STATE_PRESSED);
            lv_obj_set_style_bg_color(obj, lv_color_hex(0xff000000), LV_PART_MAIN | LV_STATE_CHECKED);
            lv_obj_set_style_bg_grad_color(obj, lv_color_hex(0xff00ff00), LV_PART_MAIN | LV_STATE_CHECKED);
            lv_obj_set_style_shadow_width(obj, 5, LV_PART_MAIN | LV_STATE_CHECKED);
            lv_obj_set_style_shadow_ofs_x(obj, 3, LV_PART_MAIN | LV_STATE_CHECKED);
            lv_obj_set_style_shadow_ofs_y(obj, 3, LV_PART_MAIN | LV_STATE_CHECKED);
            lv_obj_set_style_shadow_spread(obj, 2, LV_PART_MAIN | LV_STATE_CHECKED);
            lv_obj_set_style_shadow_color(obj, lv_color_hex(0xff000000), LV_PART_MAIN | LV_STATE_CHECKED);
            lv_obj_set_style_shadow_opa(obj, 192, LV_PART_MAIN | LV_STATE_CHECKED);
            {
                lv_obj_t *parent_obj = obj;
                {
                    // lblPower
                    lv_obj_t *obj = lv_label_create(parent_obj);
                    objects.lbl_power = obj;
                    lv_obj_set_pos(obj, 0, 0);
                    lv_obj_set_size(obj, 60, LV_SIZE_CONTENT);
                    lv_obj_set_style_align(obj, LV_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_text_font(obj, &lv_font_montserrat_16, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_text_align(obj, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_text_font(obj, &lv_font_montserrat_18, LV_PART_MAIN | LV_STATE_CHECKED);
                    lv_obj_set_style_shadow_width(obj, 0, LV_PART_MAIN | LV_STATE_PRESSED);
                    lv_label_set_text(obj, "Power Off");
                }
            }
        }
        {
            // hLine
            lv_obj_t *obj = lv_line_create(parent_obj);
            objects.h_line = obj;
            lv_obj_set_pos(obj, 0, 60);
            lv_obj_set_size(obj, 320, 1);
            static lv_point_t line_points[] = {
                { 0, 60 },
                { 320, 60 }
            };
            lv_line_set_points(obj, line_points, 2);
            lv_obj_clear_flag(obj, LV_OBJ_FLAG_CLICK_FOCUSABLE|LV_OBJ_FLAG_GESTURE_BUBBLE|LV_OBJ_FLAG_PRESS_LOCK|LV_OBJ_FLAG_SCROLLABLE|LV_OBJ_FLAG_SCROLL_CHAIN_HOR|LV_OBJ_FLAG_SCROLL_CHAIN_VER|LV_OBJ_FLAG_SCROLL_ELASTIC|LV_OBJ_FLAG_SCROLL_MOMENTUM|LV_OBJ_FLAG_SCROLL_WITH_ARROW|LV_OBJ_FLAG_SNAPPABLE);
            lv_obj_set_style_shadow_width(obj, 10, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_shadow_ofs_x(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_shadow_ofs_y(obj, 2, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_shadow_opa(obj, 127, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_shadow_spread(obj, 4, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_shadow_color(obj, lv_color_hex(0xff000000), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_border_color(obj, lv_color_hex(0xff000000), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_border_width(obj, 1, LV_PART_MAIN | LV_STATE_DEFAULT);
        }
        {
            lv_obj_t *obj = lv_label_create(parent_obj);
            objects.obj9 = obj;
            lv_obj_set_pos(obj, 41, 74);
            lv_obj_set_size(obj, 229, 24);
            lv_obj_clear_flag(obj, LV_OBJ_FLAG_CLICK_FOCUSABLE|LV_OBJ_FLAG_GESTURE_BUBBLE|LV_OBJ_FLAG_PRESS_LOCK|LV_OBJ_FLAG_SCROLLABLE|LV_OBJ_FLAG_SCROLL_CHAIN_HOR|LV_OBJ_FLAG_SCROLL_CHAIN_VER|LV_OBJ_FLAG_SCROLL_ELASTIC|LV_OBJ_FLAG_SCROLL_MOMENTUM|LV_OBJ_FLAG_SNAPPABLE);
            lv_obj_set_style_text_font(obj, &lv_font_montserrat_18, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_align(obj, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_color(obj, lv_color_hex(0xffffffff), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_outline_width(obj, 1, LV_PART_MAIN | LV_STATE_PRESSED);
            lv_label_set_text(obj, "Throttle in Use");
        }
        {
            lv_obj_t *obj = lv_label_create(parent_obj);
            objects.obj10 = obj;
            lv_obj_set_pos(obj, 41, 164);
            lv_obj_set_size(obj, 231, 24);
            lv_obj_clear_flag(obj, LV_OBJ_FLAG_CLICK_FOCUSABLE|LV_OBJ_FLAG_GESTURE_BUBBLE|LV_OBJ_FLAG_PRESS_LOCK|LV_OBJ_FLAG_SCROLLABLE|LV_OBJ_FLAG_SCROLL_CHAIN_HOR|LV_OBJ_FLAG_SCROLL_CHAIN_VER|LV_OBJ_FLAG_SCROLL_ELASTIC|LV_OBJ_FLAG_SCROLL_MOMENTUM|LV_OBJ_FLAG_SNAPPABLE);
            lv_obj_set_style_text_font(obj, &lv_font_montserrat_18, LV_PART_MAIN | LV_STATE_PRESSED);
            lv_obj_set_style_text_font(obj, &lv_font_montserrat_18, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_align(obj, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_color(obj, lv_color_hex(0xffffffff), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_label_set_text(obj, "Available Sections");
        }
        {
            // CreditsButton
            lv_obj_t *obj = lv_btn_create(parent_obj);
            objects.credits_button = obj;
            lv_obj_set_pos(obj, 4, 426);
            lv_obj_set_size(obj, 85, 50);
            lv_obj_add_event_cb(obj, action_menu_button, LV_EVENT_CLICKED, (void *)30);
            lv_obj_clear_flag(obj, LV_OBJ_FLAG_CLICK_FOCUSABLE|LV_OBJ_FLAG_GESTURE_BUBBLE|LV_OBJ_FLAG_PRESS_LOCK|LV_OBJ_FLAG_SCROLL_CHAIN_HOR|LV_OBJ_FLAG_SCROLL_CHAIN_VER|LV_OBJ_FLAG_SCROLL_ELASTIC|LV_OBJ_FLAG_SCROLL_MOMENTUM|LV_OBJ_FLAG_SNAPPABLE);
            lv_obj_set_style_bg_color(obj, lv_color_hex(0xffffffff), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_bg_grad_dir(obj, LV_GRAD_DIR_VER, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_bg_grad_color(obj, lv_color_hex(0xff000000), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_outline_width(obj, 1, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_font(obj, &lv_font_montserrat_24, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_shadow_width(obj, 10, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_shadow_ofs_x(obj, 5, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_shadow_ofs_y(obj, 5, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_shadow_spread(obj, 2, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_shadow_opa(obj, 128, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_shadow_color(obj, lv_color_hex(0xff000000), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_bg_color(obj, lv_color_hex(0xff000000), LV_PART_MAIN | LV_STATE_PRESSED);
            lv_obj_set_style_bg_grad_dir(obj, LV_GRAD_DIR_VER, LV_PART_MAIN | LV_STATE_PRESSED);
            lv_obj_set_style_bg_grad_color(obj, lv_color_hex(0xfffff200), LV_PART_MAIN | LV_STATE_PRESSED);
            lv_obj_set_style_text_color(obj, lv_color_hex(0xff000000), LV_PART_MAIN | LV_STATE_PRESSED);
            lv_obj_set_style_transform_width(obj, -2, LV_PART_MAIN | LV_STATE_PRESSED);
            lv_obj_set_style_transform_height(obj, -2, LV_PART_MAIN | LV_STATE_PRESSED);
            lv_obj_set_style_shadow_width(obj, 0, LV_PART_MAIN | LV_STATE_PRESSED);
            lv_obj_set_style_shadow_ofs_x(obj, 0, LV_PART_MAIN | LV_STATE_PRESSED);
            lv_obj_set_style_shadow_ofs_y(obj, 0, LV_PART_MAIN | LV_STATE_PRESSED);
            lv_obj_set_style_shadow_spread(obj, 2, LV_PART_MAIN | LV_STATE_PRESSED);
            lv_obj_set_style_text_font(obj, &lv_font_montserrat_20, LV_PART_MAIN | LV_STATE_CHECKED);
            {
                lv_obj_t *parent_obj = obj;
                {
                    lv_obj_t *obj = lv_label_create(parent_obj);
                    objects.obj11 = obj;
                    lv_obj_set_pos(obj, 0, 0);
                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                    lv_obj_clear_flag(obj, LV_OBJ_FLAG_CLICK_FOCUSABLE|LV_OBJ_FLAG_GESTURE_BUBBLE|LV_OBJ_FLAG_PRESS_LOCK|LV_OBJ_FLAG_SCROLLABLE|LV_OBJ_FLAG_SCROLL_CHAIN_HOR|LV_OBJ_FLAG_SCROLL_CHAIN_VER|LV_OBJ_FLAG_SCROLL_ELASTIC|LV_OBJ_FLAG_SCROLL_MOMENTUM|LV_OBJ_FLAG_SNAPPABLE);
                    lv_obj_set_style_align(obj, LV_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_bg_color(obj, lv_color_hex(0xffffffff), LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_bg_grad_dir(obj, LV_GRAD_DIR_VER, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_bg_grad_color(obj, lv_color_hex(0xff000000), LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_bg_grad_stop(obj, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_text_font(obj, &lv_font_montserrat_20, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_text_font(obj, &lv_font_montserrat_20, LV_PART_MAIN | LV_STATE_CHECKED);
                    lv_label_set_text(obj, "Credits");
                }
            }
        }
        {
            // InfoButton
            lv_obj_t *obj = lv_btn_create(parent_obj);
            objects.info_button = obj;
            lv_obj_set_pos(obj, 232, 426);
            lv_obj_set_size(obj, 85, 50);
            lv_obj_add_event_cb(obj, action_menu_button, LV_EVENT_CLICKED, (void *)32);
            lv_obj_clear_flag(obj, LV_OBJ_FLAG_CLICK_FOCUSABLE|LV_OBJ_FLAG_GESTURE_BUBBLE|LV_OBJ_FLAG_PRESS_LOCK|LV_OBJ_FLAG_SCROLL_CHAIN_HOR|LV_OBJ_FLAG_SCROLL_CHAIN_VER|LV_OBJ_FLAG_SCROLL_ELASTIC|LV_OBJ_FLAG_SCROLL_MOMENTUM|LV_OBJ_FLAG_SNAPPABLE);
            lv_obj_set_style_bg_color(obj, lv_color_hex(0xffffffff), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_bg_grad_dir(obj, LV_GRAD_DIR_VER, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_bg_grad_color(obj, lv_color_hex(0xff000000), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_outline_width(obj, 1, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_font(obj, &lv_font_montserrat_24, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_shadow_width(obj, 10, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_shadow_ofs_x(obj, 5, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_shadow_ofs_y(obj, 5, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_shadow_spread(obj, 2, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_shadow_opa(obj, 128, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_shadow_color(obj, lv_color_hex(0xff000000), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_bg_color(obj, lv_color_hex(0xff000000), LV_PART_MAIN | LV_STATE_PRESSED);
            lv_obj_set_style_bg_grad_dir(obj, LV_GRAD_DIR_VER, LV_PART_MAIN | LV_STATE_PRESSED);
            lv_obj_set_style_bg_grad_color(obj, lv_color_hex(0xfffff200), LV_PART_MAIN | LV_STATE_PRESSED);
            lv_obj_set_style_text_color(obj, lv_color_hex(0xff000000), LV_PART_MAIN | LV_STATE_PRESSED);
            lv_obj_set_style_transform_width(obj, -2, LV_PART_MAIN | LV_STATE_PRESSED);
            lv_obj_set_style_transform_height(obj, -2, LV_PART_MAIN | LV_STATE_PRESSED);
            lv_obj_set_style_shadow_width(obj, 0, LV_PART_MAIN | LV_STATE_PRESSED);
            lv_obj_set_style_shadow_ofs_x(obj, 0, LV_PART_MAIN | LV_STATE_PRESSED);
            lv_obj_set_style_shadow_ofs_y(obj, 0, LV_PART_MAIN | LV_STATE_PRESSED);
            lv_obj_set_style_shadow_spread(obj, 2, LV_PART_MAIN | LV_STATE_PRESSED);
            lv_obj_set_style_text_font(obj, &lv_font_montserrat_20, LV_PART_MAIN | LV_STATE_CHECKED);
            {
                lv_obj_t *parent_obj = obj;
                {
                    lv_obj_t *obj = lv_label_create(parent_obj);
                    objects.obj12 = obj;
                    lv_obj_set_pos(obj, 0, 0);
                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                    lv_obj_clear_flag(obj, LV_OBJ_FLAG_CLICK_FOCUSABLE|LV_OBJ_FLAG_GESTURE_BUBBLE|LV_OBJ_FLAG_PRESS_LOCK|LV_OBJ_FLAG_SCROLLABLE|LV_OBJ_FLAG_SCROLL_CHAIN_HOR|LV_OBJ_FLAG_SCROLL_CHAIN_VER|LV_OBJ_FLAG_SCROLL_ELASTIC|LV_OBJ_FLAG_SCROLL_MOMENTUM|LV_OBJ_FLAG_SNAPPABLE);
                    lv_obj_set_style_align(obj, LV_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_bg_color(obj, lv_color_hex(0xffffffff), LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_bg_grad_dir(obj, LV_GRAD_DIR_VER, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_bg_grad_color(obj, lv_color_hex(0xff000000), LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_bg_grad_stop(obj, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_text_font(obj, &lv_font_montserrat_20, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_text_font(obj, &lv_font_montserrat_20, LV_PART_MAIN | LV_STATE_CHECKED);
                    lv_label_set_text(obj, "Info");
                }
            }
        }
        {
            // ThrottleMtx
            lv_obj_t *obj = lv_btnmatrix_create(parent_obj);
            objects.throttle_mtx = obj;
            lv_obj_set_pos(obj, 13, 102);
            lv_obj_set_size(obj, 297, 55);
            static const char *map[5] = {
                "A",
                "B",
                "C",
                "D",
                NULL,
            };
            static lv_btnmatrix_ctrl_t ctrl_map[4] = {
                1 | LV_BTNMATRIX_CTRL_CHECKABLE,
                1 | LV_BTNMATRIX_CTRL_CHECKABLE,
                1 | LV_BTNMATRIX_CTRL_CHECKABLE,
                1 | LV_BTNMATRIX_CTRL_CHECKABLE,
            };
            lv_btnmatrix_set_map(obj, map);
            lv_btnmatrix_set_ctrl_map(obj, ctrl_map);
            lv_btnmatrix_set_one_checked(obj, true);
            lv_obj_set_style_pad_top(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_bottom(obj, 5, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_left(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_right(obj, 5, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_bg_color(obj, lv_color_hex(0xffc89600), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_column(obj, 15, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_border_color(obj, lv_color_hex(0xffe0e0e0), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_border_width(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_bg_color(obj, lv_color_hex(0xffffffff), LV_PART_ITEMS | LV_STATE_DEFAULT);
            lv_obj_set_style_bg_grad_dir(obj, LV_GRAD_DIR_VER, LV_PART_ITEMS | LV_STATE_DEFAULT);
            lv_obj_set_style_shadow_width(obj, 5, LV_PART_ITEMS | LV_STATE_DEFAULT);
            lv_obj_set_style_shadow_ofs_x(obj, 3, LV_PART_ITEMS | LV_STATE_DEFAULT);
            lv_obj_set_style_shadow_ofs_y(obj, 3, LV_PART_ITEMS | LV_STATE_DEFAULT);
            lv_obj_set_style_shadow_spread(obj, 2, LV_PART_ITEMS | LV_STATE_DEFAULT);
            lv_obj_set_style_shadow_color(obj, lv_color_hex(0xff000000), LV_PART_ITEMS | LV_STATE_DEFAULT);
            lv_obj_set_style_shadow_opa(obj, 127, LV_PART_ITEMS | LV_STATE_DEFAULT);
            lv_obj_set_style_text_font(obj, &lv_font_montserrat_30, LV_PART_ITEMS | LV_STATE_DEFAULT);
            lv_obj_set_style_text_color(obj, lv_color_hex(0xffffffff), LV_PART_ITEMS | LV_STATE_DEFAULT);
            lv_obj_set_style_text_letter_space(obj, 0, LV_PART_ITEMS | LV_STATE_DEFAULT);
            lv_obj_set_style_border_color(obj, lv_color_hex(0xff000000), LV_PART_ITEMS | LV_STATE_DEFAULT);
            lv_obj_set_style_border_width(obj, 1, LV_PART_ITEMS | LV_STATE_DEFAULT);
            lv_obj_set_style_bg_color(obj, lv_color_hex(0xff000000), LV_PART_ITEMS | LV_STATE_CHECKED);
            lv_obj_set_style_bg_grad_dir(obj, LV_GRAD_DIR_VER, LV_PART_ITEMS | LV_STATE_CHECKED);
            lv_obj_set_style_bg_grad_color(obj, lv_color_hex(0xffff0000), LV_PART_ITEMS | LV_STATE_CHECKED);
            lv_obj_set_style_border_color(obj, lv_color_hex(0xff000000), LV_PART_ITEMS | LV_STATE_CHECKED);
            lv_obj_set_style_text_color(obj, lv_color_hex(0xffffffff), LV_PART_ITEMS | LV_STATE_CHECKED);
            lv_obj_set_style_border_post(obj, false, LV_PART_ITEMS | LV_STATE_CHECKED);
            lv_obj_set_style_shadow_width(obj, 0, LV_PART_ITEMS | LV_STATE_CHECKED);
            lv_obj_set_style_shadow_ofs_x(obj, 0, LV_PART_ITEMS | LV_STATE_CHECKED);
            lv_obj_set_style_shadow_ofs_y(obj, 0, LV_PART_ITEMS | LV_STATE_CHECKED);
            lv_obj_set_style_shadow_spread(obj, 0, LV_PART_ITEMS | LV_STATE_CHECKED);
        }
        {
            // MenuMtx
            lv_obj_t *obj = lv_btnmatrix_create(parent_obj);
            objects.menu_mtx = obj;
            lv_obj_set_pos(obj, 9, 188);
            lv_obj_set_size(obj, 305, 238);
            static const char *map[12] = {
                "Config",
                "Roster",
                "\n",
                "Acc",
                "Program",
                "\n",
                "WiFi",
                "Routes",
                "\n",
                "Save",
                "Restore",
                NULL,
            };
            static lv_btnmatrix_ctrl_t ctrl_map[8] = {
                1 | LV_BTNMATRIX_CTRL_CHECKABLE,
                1 | LV_BTNMATRIX_CTRL_CHECKABLE,
                1 | LV_BTNMATRIX_CTRL_DISABLED | LV_BTNMATRIX_CTRL_CHECKABLE,
                1 | LV_BTNMATRIX_CTRL_CHECKABLE,
                1 | LV_BTNMATRIX_CTRL_CHECKABLE,
                1 | LV_BTNMATRIX_CTRL_DISABLED | LV_BTNMATRIX_CTRL_CHECKABLE,
                1 | LV_BTNMATRIX_CTRL_CHECKABLE,
                1 | LV_BTNMATRIX_CTRL_CHECKABLE,
            };
            lv_btnmatrix_set_map(obj, map);
            lv_btnmatrix_set_ctrl_map(obj, ctrl_map);
            lv_btnmatrix_set_one_checked(obj, true);
            lv_obj_add_flag(obj, LV_OBJ_FLAG_CHECKABLE);
            lv_obj_set_style_bg_color(obj, lv_color_hex(0xffffffff), LV_PART_ITEMS | LV_STATE_DEFAULT);
            lv_obj_set_style_bg_grad_dir(obj, LV_GRAD_DIR_VER, LV_PART_ITEMS | LV_STATE_DEFAULT);
            lv_obj_set_style_border_width(obj, 1, LV_PART_ITEMS | LV_STATE_DEFAULT);
            lv_obj_set_style_shadow_ofs_x(obj, 4, LV_PART_ITEMS | LV_STATE_DEFAULT);
            lv_obj_set_style_shadow_ofs_y(obj, 4, LV_PART_ITEMS | LV_STATE_DEFAULT);
            lv_obj_set_style_shadow_spread(obj, 3, LV_PART_ITEMS | LV_STATE_DEFAULT);
            lv_obj_set_style_shadow_color(obj, lv_color_hex(0xff000000), LV_PART_ITEMS | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_top(obj, 0, LV_PART_ITEMS | LV_STATE_DEFAULT);
            lv_obj_set_style_text_font(obj, &lv_font_montserrat_20, LV_PART_ITEMS | LV_STATE_DEFAULT);
            lv_obj_set_style_text_color(obj, lv_color_hex(0xffffffff), LV_PART_ITEMS | LV_STATE_DEFAULT);
            lv_obj_set_style_shadow_width(obj, 5, LV_PART_ITEMS | LV_STATE_DEFAULT);
            lv_obj_set_style_bg_color(obj, lv_color_hex(0xffc89600), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_border_width(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_top(obj, 4, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_left(obj, 4, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_right(obj, 15, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_row(obj, 10, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_column(obj, 50, LV_PART_MAIN | LV_STATE_DEFAULT);
        }
        {
            // imgWifi
            lv_obj_t *obj = lv_img_create(parent_obj);
            objects.img_wifi = obj;
            lv_obj_set_pos(obj, 76, 36);
            lv_obj_set_size(obj, 27, 18);
        }
    }
    
    tick_screen_main();
}

void tick_screen_main() {
}

void create_screen_throttle() {
    lv_obj_t *obj = lv_obj_create(0);
    objects.throttle = obj;
    lv_obj_set_pos(obj, 0, 0);
    lv_obj_set_size(obj, 320, 480);
    lv_obj_add_flag(obj, LV_OBJ_FLAG_CHECKABLE);
    lv_obj_clear_flag(obj, LV_OBJ_FLAG_CLICK_FOCUSABLE);
    lv_obj_set_style_bg_color(obj, lv_color_hex(0xffc89600), LV_PART_MAIN | LV_STATE_DEFAULT);
    {
        lv_obj_t *parent_obj = obj;
        {
            // lbl_Throttle_Page
            lv_obj_t *obj = lv_label_create(parent_obj);
            objects.lbl_throttle_page = obj;
            lv_obj_set_pos(obj, 89, 34);
            lv_obj_set_size(obj, 140, 20);
            lv_obj_clear_flag(obj, LV_OBJ_FLAG_CLICK_FOCUSABLE|LV_OBJ_FLAG_GESTURE_BUBBLE|LV_OBJ_FLAG_PRESS_LOCK|LV_OBJ_FLAG_SCROLLABLE|LV_OBJ_FLAG_SCROLL_CHAIN_HOR|LV_OBJ_FLAG_SCROLL_CHAIN_VER|LV_OBJ_FLAG_SCROLL_ELASTIC|LV_OBJ_FLAG_SCROLL_MOMENTUM|LV_OBJ_FLAG_SNAPPABLE);
            lv_obj_set_style_text_align(obj, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_font(obj, &lv_font_montserrat_18, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_bg_color(obj, lv_color_hex(0xff003200), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_color(obj, lv_color_hex(0xffffffff), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_label_set_text(obj, "Throttle");
        }
        {
            // swDir
            lv_obj_t *obj = lv_switch_create(parent_obj);
            objects.sw_dir = obj;
            lv_obj_set_pos(obj, 135, 386);
            lv_obj_set_size(obj, 50, 30);
            lv_obj_add_event_cb(obj, event_handler_checked_cb_throttle_sw_dir, LV_EVENT_VALUE_CHANGED, (void *)4);
            lv_obj_add_event_cb(obj, event_handler_unchecked_cb_throttle_sw_dir, LV_EVENT_VALUE_CHANGED, (void *)5);
            lv_obj_add_state(obj, LV_STATE_CHECKED);
            lv_obj_set_style_bg_color(obj, lv_color_hex(0xff000000), LV_PART_KNOB | LV_STATE_DEFAULT);
            lv_obj_set_style_outline_color(obj, lv_color_hex(0xffffffff), LV_PART_KNOB | LV_STATE_DEFAULT);
            lv_obj_set_style_outline_width(obj, 2, LV_PART_KNOB | LV_STATE_DEFAULT);
            lv_obj_set_style_bg_img_recolor_opa(obj, 50, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_bg_color(obj, lv_color_hex(0xffff0000), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_outline_color(obj, lv_color_hex(0xff000000), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_outline_width(obj, 2, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_shadow_width(obj, 5, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_shadow_ofs_x(obj, 3, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_shadow_ofs_y(obj, 3, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_shadow_spread(obj, 2, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_shadow_opa(obj, 127, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_bg_img_recolor(obj, lv_color_hex(0xffff0000), LV_PART_MAIN | LV_STATE_CHECKED | LV_STATE_PRESSED);
            lv_obj_set_style_bg_img_recolor(obj, lv_color_hex(0xff00ff00), LV_PART_MAIN | LV_STATE_PRESSED);
            lv_obj_set_style_bg_color(obj, lv_color_hex(0xffff0000), LV_PART_MAIN | LV_STATE_CHECKED);
            lv_obj_set_style_shadow_width(obj, 10, LV_PART_MAIN | LV_STATE_CHECKED);
            lv_obj_set_style_shadow_ofs_x(obj, 5, LV_PART_MAIN | LV_STATE_CHECKED);
            lv_obj_set_style_shadow_ofs_y(obj, 5, LV_PART_MAIN | LV_STATE_CHECKED);
            lv_obj_set_style_shadow_spread(obj, 2, LV_PART_MAIN | LV_STATE_CHECKED);
            lv_obj_set_style_shadow_opa(obj, 192, LV_PART_MAIN | LV_STATE_CHECKED);
            lv_obj_set_style_bg_color(obj, lv_color_hex(0xffff0000), LV_PART_INDICATOR | LV_STATE_DEFAULT);
            lv_obj_set_style_bg_color(obj, lv_color_hex(0xffff0000), LV_PART_INDICATOR | LV_STATE_PRESSED);
            lv_obj_set_style_bg_color(obj, lv_color_hex(0xff00ff00), LV_PART_INDICATOR | LV_STATE_CHECKED);
            lv_obj_set_style_bg_color(obj, lv_color_hex(0xffff0000), LV_PART_INDICATOR | LV_STATE_CHECKED | LV_STATE_PRESSED);
        }
        {
            // Prog_Button2_1
            lv_obj_t *obj = lv_btn_create(parent_obj);
            objects.prog_button2_1 = obj;
            lv_obj_set_pos(obj, 4, 426);
            lv_obj_set_size(obj, 85, 50);
            lv_obj_add_event_cb(obj, action_throttle_button, LV_EVENT_RELEASED, (void *)30);
            lv_obj_clear_flag(obj, LV_OBJ_FLAG_CLICK_FOCUSABLE|LV_OBJ_FLAG_GESTURE_BUBBLE|LV_OBJ_FLAG_PRESS_LOCK|LV_OBJ_FLAG_SCROLL_CHAIN_HOR|LV_OBJ_FLAG_SCROLL_CHAIN_VER|LV_OBJ_FLAG_SCROLL_ELASTIC|LV_OBJ_FLAG_SCROLL_MOMENTUM|LV_OBJ_FLAG_SNAPPABLE);
            lv_obj_set_style_bg_color(obj, lv_color_hex(0xffffffff), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_bg_grad_dir(obj, LV_GRAD_DIR_VER, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_bg_grad_color(obj, lv_color_hex(0xff000000), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_outline_width(obj, 1, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_font(obj, &lv_font_montserrat_24, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_shadow_width(obj, 10, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_shadow_ofs_x(obj, 5, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_shadow_ofs_y(obj, 5, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_shadow_spread(obj, 2, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_shadow_opa(obj, 127, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_shadow_color(obj, lv_color_hex(0xff000000), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_bg_color(obj, lv_color_hex(0xff000000), LV_PART_MAIN | LV_STATE_PRESSED);
            lv_obj_set_style_bg_grad_dir(obj, LV_GRAD_DIR_VER, LV_PART_MAIN | LV_STATE_PRESSED);
            lv_obj_set_style_bg_grad_color(obj, lv_color_hex(0xfffff200), LV_PART_MAIN | LV_STATE_PRESSED);
            lv_obj_set_style_text_color(obj, lv_color_hex(0xff000000), LV_PART_MAIN | LV_STATE_PRESSED);
            lv_obj_set_style_shadow_width(obj, 0, LV_PART_MAIN | LV_STATE_PRESSED);
            lv_obj_set_style_shadow_ofs_x(obj, 0, LV_PART_MAIN | LV_STATE_PRESSED);
            lv_obj_set_style_shadow_ofs_y(obj, 0, LV_PART_MAIN | LV_STATE_PRESSED);
            lv_obj_set_style_shadow_spread(obj, 0, LV_PART_MAIN | LV_STATE_PRESSED);
            lv_obj_set_style_transform_width(obj, -2, LV_PART_MAIN | LV_STATE_PRESSED);
            lv_obj_set_style_transform_height(obj, -2, LV_PART_MAIN | LV_STATE_PRESSED);
            {
                lv_obj_t *parent_obj = obj;
                {
                    lv_obj_t *obj = lv_label_create(parent_obj);
                    objects.obj13 = obj;
                    lv_obj_set_pos(obj, 0, 0);
                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                    lv_obj_clear_flag(obj, LV_OBJ_FLAG_CLICK_FOCUSABLE|LV_OBJ_FLAG_GESTURE_BUBBLE|LV_OBJ_FLAG_PRESS_LOCK|LV_OBJ_FLAG_SCROLLABLE|LV_OBJ_FLAG_SCROLL_CHAIN_HOR|LV_OBJ_FLAG_SCROLL_CHAIN_VER|LV_OBJ_FLAG_SCROLL_ELASTIC|LV_OBJ_FLAG_SCROLL_MOMENTUM|LV_OBJ_FLAG_SNAPPABLE);
                    lv_obj_set_style_align(obj, LV_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_bg_color(obj, lv_color_hex(0xffffffff), LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_bg_grad_dir(obj, LV_GRAD_DIR_VER, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_bg_grad_color(obj, lv_color_hex(0xff000000), LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_bg_grad_stop(obj, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_text_font(obj, &lv_font_montserrat_20, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_label_set_text(obj, "Prog");
                }
            }
        }
        {
            // Acc_Button2_1
            lv_obj_t *obj = lv_btn_create(parent_obj);
            objects.acc_button2_1 = obj;
            lv_obj_set_pos(obj, 232, 425);
            lv_obj_set_size(obj, 85, 50);
            lv_obj_add_event_cb(obj, action_throttle_button, LV_EVENT_RELEASED, (void *)32);
            lv_obj_clear_flag(obj, LV_OBJ_FLAG_CLICK_FOCUSABLE|LV_OBJ_FLAG_GESTURE_BUBBLE|LV_OBJ_FLAG_PRESS_LOCK|LV_OBJ_FLAG_SCROLL_CHAIN_HOR|LV_OBJ_FLAG_SCROLL_CHAIN_VER|LV_OBJ_FLAG_SCROLL_ELASTIC|LV_OBJ_FLAG_SCROLL_MOMENTUM|LV_OBJ_FLAG_SNAPPABLE);
            lv_obj_add_state(obj, LV_STATE_DISABLED);
            lv_obj_set_style_bg_color(obj, lv_color_hex(0xffffffff), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_bg_grad_dir(obj, LV_GRAD_DIR_VER, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_bg_grad_color(obj, lv_color_hex(0xff000000), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_outline_width(obj, 1, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_font(obj, &lv_font_montserrat_24, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_shadow_width(obj, 10, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_shadow_ofs_x(obj, 5, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_shadow_ofs_y(obj, 5, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_shadow_spread(obj, 2, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_shadow_opa(obj, 127, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_shadow_color(obj, lv_color_hex(0xff000000), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_bg_color(obj, lv_color_hex(0xff000000), LV_PART_MAIN | LV_STATE_PRESSED);
            lv_obj_set_style_bg_grad_dir(obj, LV_GRAD_DIR_VER, LV_PART_MAIN | LV_STATE_PRESSED);
            lv_obj_set_style_bg_grad_color(obj, lv_color_hex(0xfffff200), LV_PART_MAIN | LV_STATE_PRESSED);
            lv_obj_set_style_text_color(obj, lv_color_hex(0xff000000), LV_PART_MAIN | LV_STATE_PRESSED);
            lv_obj_set_style_shadow_width(obj, 0, LV_PART_MAIN | LV_STATE_PRESSED);
            lv_obj_set_style_shadow_ofs_x(obj, 0, LV_PART_MAIN | LV_STATE_PRESSED);
            lv_obj_set_style_shadow_ofs_y(obj, 0, LV_PART_MAIN | LV_STATE_PRESSED);
            lv_obj_set_style_shadow_spread(obj, 0, LV_PART_MAIN | LV_STATE_PRESSED);
            lv_obj_set_style_transform_width(obj, -2, LV_PART_MAIN | LV_STATE_PRESSED);
            lv_obj_set_style_transform_height(obj, -2, LV_PART_MAIN | LV_STATE_PRESSED);
            {
                lv_obj_t *parent_obj = obj;
                {
                    lv_obj_t *obj = lv_label_create(parent_obj);
                    objects.obj14 = obj;
                    lv_obj_set_pos(obj, 0, 0);
                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                    lv_obj_clear_flag(obj, LV_OBJ_FLAG_CLICK_FOCUSABLE|LV_OBJ_FLAG_GESTURE_BUBBLE|LV_OBJ_FLAG_PRESS_LOCK|LV_OBJ_FLAG_SCROLLABLE|LV_OBJ_FLAG_SCROLL_CHAIN_HOR|LV_OBJ_FLAG_SCROLL_CHAIN_VER|LV_OBJ_FLAG_SCROLL_ELASTIC|LV_OBJ_FLAG_SCROLL_MOMENTUM|LV_OBJ_FLAG_SNAPPABLE);
                    lv_obj_set_style_align(obj, LV_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_bg_color(obj, lv_color_hex(0xffffffff), LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_bg_grad_dir(obj, LV_GRAD_DIR_VER, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_bg_grad_color(obj, lv_color_hex(0xff000000), LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_bg_grad_stop(obj, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_text_font(obj, &lv_font_montserrat_20, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_label_set_text(obj, "Acc");
                }
            }
        }
        {
            // Roster_Button2_1
            lv_obj_t *obj = lv_btn_create(parent_obj);
            objects.roster_button2_1 = obj;
            lv_obj_set_pos(obj, 117, 426);
            lv_obj_set_size(obj, 84, 50);
            lv_obj_add_event_cb(obj, action_throttle_button, LV_EVENT_RELEASED, (void *)31);
            lv_obj_clear_flag(obj, LV_OBJ_FLAG_CLICK_FOCUSABLE|LV_OBJ_FLAG_GESTURE_BUBBLE|LV_OBJ_FLAG_PRESS_LOCK|LV_OBJ_FLAG_SCROLL_CHAIN_HOR|LV_OBJ_FLAG_SCROLL_CHAIN_VER|LV_OBJ_FLAG_SCROLL_ELASTIC|LV_OBJ_FLAG_SCROLL_MOMENTUM|LV_OBJ_FLAG_SNAPPABLE);
            lv_obj_set_style_bg_color(obj, lv_color_hex(0xffffffff), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_bg_grad_dir(obj, LV_GRAD_DIR_VER, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_bg_grad_color(obj, lv_color_hex(0xff000000), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_outline_width(obj, 1, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_font(obj, &lv_font_montserrat_24, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_shadow_width(obj, 10, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_shadow_ofs_x(obj, 5, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_shadow_ofs_y(obj, 5, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_shadow_spread(obj, 2, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_shadow_opa(obj, 127, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_shadow_color(obj, lv_color_hex(0xff000000), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_bg_color(obj, lv_color_hex(0xff000000), LV_PART_MAIN | LV_STATE_PRESSED);
            lv_obj_set_style_bg_grad_dir(obj, LV_GRAD_DIR_VER, LV_PART_MAIN | LV_STATE_PRESSED);
            lv_obj_set_style_bg_grad_color(obj, lv_color_hex(0xfffff200), LV_PART_MAIN | LV_STATE_PRESSED);
            lv_obj_set_style_text_color(obj, lv_color_hex(0xff000000), LV_PART_MAIN | LV_STATE_PRESSED);
            lv_obj_set_style_shadow_width(obj, 0, LV_PART_MAIN | LV_STATE_PRESSED);
            lv_obj_set_style_shadow_ofs_x(obj, 0, LV_PART_MAIN | LV_STATE_PRESSED);
            lv_obj_set_style_shadow_ofs_y(obj, 0, LV_PART_MAIN | LV_STATE_PRESSED);
            lv_obj_set_style_shadow_spread(obj, 0, LV_PART_MAIN | LV_STATE_PRESSED);
            lv_obj_set_style_transform_width(obj, -2, LV_PART_MAIN | LV_STATE_PRESSED);
            lv_obj_set_style_transform_height(obj, -2, LV_PART_MAIN | LV_STATE_PRESSED);
            {
                lv_obj_t *parent_obj = obj;
                {
                    lv_obj_t *obj = lv_label_create(parent_obj);
                    objects.obj15 = obj;
                    lv_obj_set_pos(obj, 0, 0);
                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                    lv_obj_clear_flag(obj, LV_OBJ_FLAG_CLICK_FOCUSABLE|LV_OBJ_FLAG_GESTURE_BUBBLE|LV_OBJ_FLAG_PRESS_LOCK|LV_OBJ_FLAG_SCROLLABLE|LV_OBJ_FLAG_SCROLL_CHAIN_HOR|LV_OBJ_FLAG_SCROLL_CHAIN_VER|LV_OBJ_FLAG_SCROLL_ELASTIC|LV_OBJ_FLAG_SCROLL_MOMENTUM|LV_OBJ_FLAG_SNAPPABLE);
                    lv_obj_set_style_align(obj, LV_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_bg_color(obj, lv_color_hex(0xffffffff), LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_bg_grad_dir(obj, LV_GRAD_DIR_VER, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_bg_grad_color(obj, lv_color_hex(0xff000000), LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_bg_grad_stop(obj, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_text_font(obj, &lv_font_montserrat_20, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_label_set_text(obj, "Roster");
                }
            }
        }
        {
            // ddLocos
            lv_obj_t *obj = lv_dropdown_create(parent_obj);
            objects.dd_locos = obj;
            lv_obj_set_pos(obj, 6, 78);
            lv_obj_set_size(obj, 308, 30);
            lv_dropdown_set_options(obj, "\n\n\n");
            lv_dropdown_set_selected(obj, 0);
            lv_obj_set_style_bg_color(obj, lv_color_hex(0xffc89600), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_shadow_width(obj, 10, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_shadow_ofs_x(obj, 5, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_shadow_ofs_y(obj, 5, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_shadow_spread(obj, 2, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_shadow_opa(obj, 127, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_border_width(obj, 1, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_border_color(obj, lv_color_hex(0xff000000), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_font(obj, &lv_font_montserrat_18, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_color(obj, lv_color_hex(0xff000000), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_align(obj, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_row(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_right(obj, 4, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_left(obj, 4, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_top(obj, 3, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_bottom(obj, 4, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_column(obj, 4, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_line_space(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_align(obj, LV_TEXT_ALIGN_CENTER, LV_PART_SELECTED | LV_STATE_DEFAULT);
            lv_obj_set_style_text_font(obj, &lv_font_montserrat_18, LV_PART_SELECTED | LV_STATE_DEFAULT);
            {
                lv_obj_t *parent_obj = obj;
                {
                    lv_obj_t *obj = lv_dropdown_get_list(parent_obj);
                    lv_obj_set_style_max_height(obj, 380, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_pad_top(obj, 3, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_pad_bottom(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_pad_row(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_text_font(obj, &lv_font_montserrat_16, LV_PART_MAIN | LV_STATE_DEFAULT);
                }
            }
        }
        {
            // btnEdit
            lv_obj_t *obj = lv_btn_create(parent_obj);
            objects.btn_edit = obj;
            lv_obj_set_pos(obj, 244, 385);
            lv_obj_set_size(obj, 70, 30);
            lv_obj_add_event_cb(obj, action_throttle_button, LV_EVENT_RELEASED, (void *)29);
            lv_obj_set_style_bg_color(obj, lv_color_hex(0xffffffff), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_bg_grad_dir(obj, LV_GRAD_DIR_VER, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_border_width(obj, 1, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_shadow_width(obj, 5, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_shadow_ofs_x(obj, 3, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_shadow_ofs_y(obj, 3, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_shadow_spread(obj, 2, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_shadow_color(obj, lv_color_hex(0xff000000), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_bg_color(obj, lv_color_hex(0xff000000), LV_PART_MAIN | LV_STATE_PRESSED);
            lv_obj_set_style_bg_grad_dir(obj, LV_GRAD_DIR_VER, LV_PART_MAIN | LV_STATE_PRESSED);
            lv_obj_set_style_bg_grad_color(obj, lv_color_hex(0xffff0000), LV_PART_MAIN | LV_STATE_PRESSED);
            {
                lv_obj_t *parent_obj = obj;
                {
                    lv_obj_t *obj = lv_label_create(parent_obj);
                    lv_obj_set_pos(obj, 0, 0);
                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                    lv_obj_set_style_align(obj, LV_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_label_set_text(obj, "Edit");
                }
            }
        }
        {
            lv_obj_t *obj = lv_label_create(parent_obj);
            objects.obj16 = obj;
            lv_obj_set_pos(obj, 9, 119);
            lv_obj_set_size(obj, LV_SIZE_CONTENT, 24);
            lv_obj_set_style_text_font(obj, &lv_font_montserrat_16, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_color(obj, lv_color_hex(0xffffffff), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_label_set_text(obj, "Address:");
        }
        {
            // lblAddress
            lv_obj_t *obj = lv_label_create(parent_obj);
            objects.lbl_address = obj;
            lv_obj_set_pos(obj, 86, 119);
            lv_obj_set_size(obj, 72, 24);
            lv_obj_set_style_text_font(obj, &lv_font_montserrat_18, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_color(obj, lv_color_hex(0xff000000), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_align(obj, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_label_set_text(obj, "");
        }
        {
            // Function_Mtx
            lv_obj_t *obj = lv_btnmatrix_create(parent_obj);
            objects.function_mtx = obj;
            lv_obj_set_pos(obj, 1, 142);
            lv_obj_set_size(obj, 318, 240);
            static const char *map[15] = {
                " ",
                " ",
                "\n",
                " ",
                " ",
                "\n",
                " ",
                " ",
                "\n",
                " ",
                " ",
                "\n",
                " ",
                " ",
                NULL,
            };
            static lv_btnmatrix_ctrl_t ctrl_map[10] = {
                1 | LV_BTNMATRIX_CTRL_HIDDEN | LV_BTNMATRIX_CTRL_CHECKABLE,
                1 | LV_BTNMATRIX_CTRL_HIDDEN | LV_BTNMATRIX_CTRL_CHECKABLE,
                1 | LV_BTNMATRIX_CTRL_HIDDEN | LV_BTNMATRIX_CTRL_CHECKABLE,
                1 | LV_BTNMATRIX_CTRL_HIDDEN | LV_BTNMATRIX_CTRL_CHECKABLE,
                1 | LV_BTNMATRIX_CTRL_HIDDEN | LV_BTNMATRIX_CTRL_CHECKABLE,
                1 | LV_BTNMATRIX_CTRL_HIDDEN | LV_BTNMATRIX_CTRL_CHECKABLE,
                1 | LV_BTNMATRIX_CTRL_HIDDEN | LV_BTNMATRIX_CTRL_CHECKABLE,
                1 | LV_BTNMATRIX_CTRL_HIDDEN | LV_BTNMATRIX_CTRL_CHECKABLE,
                1 | LV_BTNMATRIX_CTRL_HIDDEN | LV_BTNMATRIX_CTRL_CHECKABLE,
                1 | LV_BTNMATRIX_CTRL_HIDDEN | LV_BTNMATRIX_CTRL_CHECKABLE,
            };
            lv_btnmatrix_set_map(obj, map);
            lv_btnmatrix_set_ctrl_map(obj, ctrl_map);
            lv_obj_set_style_pad_top(obj, 1, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_bottom(obj, 10, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_left(obj, 5, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_right(obj, 5, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_column(obj, 90, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_bg_color(obj, lv_color_hex(0xffc89600), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_border_width(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_bg_color(obj, lv_color_hex(0xffffffff), LV_PART_ITEMS | LV_STATE_DEFAULT);
            lv_obj_set_style_bg_grad_dir(obj, LV_GRAD_DIR_VER, LV_PART_ITEMS | LV_STATE_DEFAULT);
            lv_obj_set_style_bg_grad_color(obj, lv_color_hex(0xff000000), LV_PART_ITEMS | LV_STATE_DEFAULT);
            lv_obj_set_style_border_color(obj, lv_color_hex(0xff000000), LV_PART_ITEMS | LV_STATE_DEFAULT);
            lv_obj_set_style_border_width(obj, 1, LV_PART_ITEMS | LV_STATE_DEFAULT);
            lv_obj_set_style_text_color(obj, lv_color_hex(0xffffffff), LV_PART_ITEMS | LV_STATE_DEFAULT);
            lv_obj_set_style_shadow_width(obj, 10, LV_PART_ITEMS | LV_STATE_DEFAULT);
            lv_obj_set_style_shadow_ofs_x(obj, 5, LV_PART_ITEMS | LV_STATE_DEFAULT);
            lv_obj_set_style_shadow_ofs_y(obj, 5, LV_PART_ITEMS | LV_STATE_DEFAULT);
            lv_obj_set_style_shadow_spread(obj, 2, LV_PART_ITEMS | LV_STATE_DEFAULT);
            lv_obj_set_style_shadow_color(obj, lv_color_hex(0xff000000), LV_PART_ITEMS | LV_STATE_DEFAULT);
            lv_obj_set_style_shadow_opa(obj, 127, LV_PART_ITEMS | LV_STATE_DEFAULT);
            lv_obj_set_style_text_font(obj, &lv_font_montserrat_16, LV_PART_ITEMS | LV_STATE_DEFAULT);
            lv_obj_set_style_bg_color(obj, lv_color_hex(0xffffff00), LV_PART_ITEMS | LV_STATE_CHECKED);
            lv_obj_set_style_shadow_width(obj, 0, LV_PART_ITEMS | LV_STATE_CHECKED);
            lv_obj_set_style_shadow_ofs_x(obj, 0, LV_PART_ITEMS | LV_STATE_CHECKED);
            lv_obj_set_style_shadow_ofs_y(obj, 5, LV_PART_ITEMS | LV_STATE_CHECKED);
            lv_obj_set_style_shadow_spread(obj, 2, LV_PART_ITEMS | LV_STATE_CHECKED);
            lv_obj_set_style_text_color(obj, lv_color_hex(0xff000000), LV_PART_ITEMS | LV_STATE_CHECKED);
            lv_obj_set_style_bg_grad_dir(obj, LV_GRAD_DIR_NONE, LV_PART_ITEMS | LV_STATE_CHECKED);
            lv_obj_set_style_bg_grad_dir(obj, LV_GRAD_DIR_NONE, LV_PART_ITEMS | LV_STATE_PRESSED);
            lv_obj_set_style_bg_color(obj, lv_color_hex(0xffffff00), LV_PART_ITEMS | LV_STATE_PRESSED);
            lv_obj_set_style_text_color(obj, lv_color_hex(0xff000000), LV_PART_ITEMS | LV_STATE_PRESSED);
            lv_obj_set_style_shadow_width(obj, 0, LV_PART_ITEMS | LV_STATE_PRESSED);
            lv_obj_set_style_shadow_ofs_x(obj, 0, LV_PART_ITEMS | LV_STATE_PRESSED);
            lv_obj_set_style_shadow_ofs_y(obj, 0, LV_PART_ITEMS | LV_STATE_PRESSED);
            lv_obj_set_style_shadow_spread(obj, 0, LV_PART_ITEMS | LV_STATE_PRESSED);
        }
        {
            // Slider
            lv_obj_t *obj = lv_slider_create(parent_obj);
            objects.slider = obj;
            lv_obj_set_pos(obj, 148, 152);
            lv_obj_set_size(obj, 24, 199);
            lv_slider_set_range(obj, 0, 126);
            lv_obj_add_event_cb(obj, action_throttle_button, LV_EVENT_RELEASED, (void *)3);
            lv_obj_set_scroll_dir(obj, LV_DIR_NONE);
            lv_obj_set_style_align(obj, LV_ALIGN_CENTER, LV_PART_KNOB | LV_STATE_DEFAULT);
            lv_obj_set_style_transform_width(obj, 5, LV_PART_KNOB | LV_STATE_DEFAULT);
            lv_obj_set_style_transform_height(obj, 0, LV_PART_KNOB | LV_STATE_DEFAULT);
            lv_obj_set_style_translate_y(obj, 0, LV_PART_KNOB | LV_STATE_DEFAULT);
            lv_obj_set_style_bg_color(obj, lv_color_hex(0xff2196f3), LV_PART_KNOB | LV_STATE_DEFAULT);
            lv_obj_set_style_bg_grad_dir(obj, LV_GRAD_DIR_VER, LV_PART_KNOB | LV_STATE_DEFAULT);
            lv_obj_set_style_shadow_width(obj, 10, LV_PART_KNOB | LV_STATE_DEFAULT);
            lv_obj_set_style_shadow_ofs_x(obj, 5, LV_PART_KNOB | LV_STATE_DEFAULT);
            lv_obj_set_style_shadow_ofs_y(obj, 5, LV_PART_KNOB | LV_STATE_DEFAULT);
            lv_obj_set_style_shadow_spread(obj, 2, LV_PART_KNOB | LV_STATE_DEFAULT);
            lv_obj_set_style_shadow_opa(obj, 192, LV_PART_KNOB | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_top(obj, 3, LV_PART_KNOB | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_bottom(obj, 3, LV_PART_KNOB | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_left(obj, 3, LV_PART_KNOB | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_right(obj, 3, LV_PART_KNOB | LV_STATE_DEFAULT);
            lv_obj_set_style_bg_color(obj, lv_color_hex(0xffff0000), LV_PART_INDICATOR | LV_STATE_DEFAULT);
            lv_obj_set_style_bg_grad_dir(obj, LV_GRAD_DIR_VER, LV_PART_INDICATOR | LV_STATE_DEFAULT);
            lv_obj_set_style_bg_grad_color(obj, lv_color_hex(0xff300000), LV_PART_INDICATOR | LV_STATE_DEFAULT);
            lv_obj_set_style_bg_color(obj, lv_color_hex(0xffe8d776), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_outline_width(obj, 1, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_outline_color(obj, lv_color_hex(0xff000000), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_shadow_width(obj, 10, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_shadow_ofs_x(obj, 5, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_shadow_ofs_y(obj, 5, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_shadow_spread(obj, 2, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_shadow_opa(obj, 127, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_shadow_width(obj, 10, LV_PART_MAIN | LV_STATE_CHECKED);
            lv_obj_set_style_shadow_ofs_x(obj, 5, LV_PART_MAIN | LV_STATE_CHECKED);
            lv_obj_set_style_shadow_ofs_y(obj, 5, LV_PART_MAIN | LV_STATE_CHECKED);
            lv_obj_set_style_shadow_spread(obj, 2, LV_PART_MAIN | LV_STATE_CHECKED);
            lv_obj_set_style_shadow_opa(obj, 192, LV_PART_MAIN | LV_STATE_CHECKED);
        }
        {
            // lblSlider
            lv_obj_t *obj = lv_label_create(parent_obj);
            objects.lbl_slider = obj;
            lv_obj_set_pos(obj, 250, 119);
            lv_obj_set_size(obj, 60, 24);
            lv_obj_set_style_text_font(obj, &lv_font_montserrat_18, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_align(obj, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_color(obj, lv_color_hex(0xff000000), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_label_set_text(obj, "");
        }
        {
            lv_obj_t *obj = lv_label_create(parent_obj);
            objects.obj17 = obj;
            lv_obj_set_pos(obj, 192, 119);
            lv_obj_set_size(obj, LV_SIZE_CONTENT, 24);
            lv_obj_set_style_text_font(obj, &lv_font_montserrat_16, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_color(obj, lv_color_hex(0xffffffff), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_label_set_text(obj, "Speed:");
        }
        {
            // TAGuest_Address
            lv_obj_t *obj = lv_textarea_create(parent_obj);
            objects.ta_guest_address = obj;
            lv_obj_set_pos(obj, 7, 386);
            lv_obj_set_size(obj, 70, 30);
            lv_textarea_set_max_length(obj, 128);
            lv_textarea_set_placeholder_text(obj, "Guest");
            lv_textarea_set_one_line(obj, true);
            lv_textarea_set_password_mode(obj, false);
            lv_obj_add_event_cb(obj, event_handler_checked_cb_throttle_ta_guest_address, LV_EVENT_VALUE_CHANGED, (void *)1);
            lv_obj_add_event_cb(obj, event_handler_unchecked_cb_throttle_ta_guest_address, LV_EVENT_VALUE_CHANGED, (void *)2);
            lv_obj_add_flag(obj, LV_OBJ_FLAG_CHECKABLE);
            lv_obj_set_style_pad_top(obj, 4, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_bottom(obj, 4, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_bg_color(obj, lv_color_hex(0xffffffff), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_bg_grad_dir(obj, LV_GRAD_DIR_VER, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_bg_grad_color(obj, lv_color_hex(0xff000000), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_color(obj, lv_color_hex(0xff000000), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_font(obj, &lv_font_montserrat_18, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_border_width(obj, 1, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_border_color(obj, lv_color_hex(0xff000000), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_shadow_width(obj, 5, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_shadow_ofs_x(obj, 3, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_shadow_ofs_y(obj, 3, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_shadow_spread(obj, 2, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_shadow_opa(obj, 127, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_align(obj, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_left(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_bg_color(obj, lv_color_hex(0xffffff00), LV_PART_MAIN | LV_STATE_CHECKED);
            lv_obj_set_style_shadow_width(obj, 0, LV_PART_MAIN | LV_STATE_CHECKED);
            lv_obj_set_style_shadow_ofs_x(obj, 0, LV_PART_MAIN | LV_STATE_CHECKED);
            lv_obj_set_style_shadow_ofs_y(obj, 0, LV_PART_MAIN | LV_STATE_CHECKED);
            lv_obj_set_style_shadow_spread(obj, 0, LV_PART_MAIN | LV_STATE_CHECKED);
            lv_obj_set_style_shadow_opa(obj, 255, LV_PART_MAIN | LV_STATE_CHECKED);
            lv_obj_set_style_bg_grad_dir(obj, LV_GRAD_DIR_NONE, LV_PART_MAIN | LV_STATE_CHECKED);
            lv_obj_set_style_text_align(obj, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_CHECKED);
        }
        {
            // KbdGuest
            lv_obj_t *obj = lv_keyboard_create(parent_obj);
            objects.kbd_guest = obj;
            lv_obj_set_pos(obj, 0, 262);
            lv_obj_set_size(obj, 316, 120);
            lv_keyboard_set_mode(obj, LV_KEYBOARD_MODE_NUMBER);
            lv_obj_add_flag(obj, LV_OBJ_FLAG_HIDDEN);
            lv_obj_set_style_align(obj, LV_ALIGN_DEFAULT, LV_PART_MAIN | LV_STATE_DEFAULT);
        }
        {
            lv_obj_t *obj = lv_btn_create(parent_obj);
            objects.obj18 = obj;
            lv_obj_set_pos(obj, 88, 386);
            lv_obj_set_size(obj, 38, 30);
            lv_obj_add_event_cb(obj, action_throttle_button, LV_EVENT_CLICKED, (void *)7);
            lv_obj_set_style_bg_color(obj, lv_color_hex(0xffffffff), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_bg_grad_dir(obj, LV_GRAD_DIR_VER, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_outline_width(obj, 1, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_shadow_width(obj, 5, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_shadow_ofs_x(obj, 3, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_shadow_ofs_y(obj, 3, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_shadow_spread(obj, 2, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_shadow_color(obj, lv_color_hex(0xff000000), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_shadow_opa(obj, 127, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_font(obj, &lv_font_montserrat_24, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_bg_color(obj, lv_color_hex(0xffffff00), LV_PART_MAIN | LV_STATE_PRESSED);
            lv_obj_set_style_bg_grad_dir(obj, LV_GRAD_DIR_NONE, LV_PART_MAIN | LV_STATE_PRESSED);
            lv_obj_set_style_shadow_width(obj, 9, LV_PART_MAIN | LV_STATE_PRESSED);
            lv_obj_set_style_shadow_ofs_x(obj, 0, LV_PART_MAIN | LV_STATE_PRESSED);
            lv_obj_set_style_shadow_ofs_y(obj, 0, LV_PART_MAIN | LV_STATE_PRESSED);
            lv_obj_set_style_shadow_spread(obj, 0, LV_PART_MAIN | LV_STATE_PRESSED);
            lv_obj_set_style_text_color(obj, lv_color_hex(0xff000000), LV_PART_MAIN | LV_STATE_PRESSED);
            {
                lv_obj_t *parent_obj = obj;
                {
                    lv_obj_t *obj = lv_label_create(parent_obj);
                    lv_obj_set_pos(obj, 0, 0);
                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                    lv_obj_set_style_align(obj, LV_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_label_set_text(obj, "-");
                }
            }
        }
        {
            lv_obj_t *obj = lv_btn_create(parent_obj);
            objects.obj19 = obj;
            lv_obj_set_pos(obj, 196, 387);
            lv_obj_set_size(obj, 38, 30);
            lv_obj_add_event_cb(obj, action_throttle_button, LV_EVENT_CLICKED, (void *)6);
            lv_obj_set_style_bg_color(obj, lv_color_hex(0xffffffff), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_bg_grad_dir(obj, LV_GRAD_DIR_VER, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_outline_width(obj, 1, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_shadow_width(obj, 5, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_shadow_ofs_x(obj, 3, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_shadow_ofs_y(obj, 3, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_shadow_spread(obj, 2, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_shadow_color(obj, lv_color_hex(0xff000000), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_shadow_opa(obj, 127, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_font(obj, &lv_font_montserrat_24, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_bg_color(obj, lv_color_hex(0xffffff00), LV_PART_MAIN | LV_STATE_PRESSED);
            lv_obj_set_style_bg_grad_dir(obj, LV_GRAD_DIR_NONE, LV_PART_MAIN | LV_STATE_PRESSED);
            lv_obj_set_style_shadow_width(obj, 9, LV_PART_MAIN | LV_STATE_PRESSED);
            lv_obj_set_style_shadow_ofs_x(obj, 0, LV_PART_MAIN | LV_STATE_PRESSED);
            lv_obj_set_style_shadow_ofs_y(obj, 0, LV_PART_MAIN | LV_STATE_PRESSED);
            lv_obj_set_style_shadow_spread(obj, 0, LV_PART_MAIN | LV_STATE_PRESSED);
            lv_obj_set_style_text_color(obj, lv_color_hex(0xff000000), LV_PART_MAIN | LV_STATE_PRESSED);
            {
                lv_obj_t *parent_obj = obj;
                {
                    lv_obj_t *obj = lv_label_create(parent_obj);
                    lv_obj_set_pos(obj, 0, 0);
                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                    lv_obj_set_style_align(obj, LV_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_label_set_text(obj, "+");
                }
            }
        }
    }
    
    tick_screen_throttle();
}

void tick_screen_throttle() {
}

void create_screen_roster() {
    lv_obj_t *obj = lv_obj_create(0);
    objects.roster = obj;
    lv_obj_set_pos(obj, 0, 0);
    lv_obj_set_size(obj, 320, 480);
    lv_obj_set_style_bg_color(obj, lv_color_hex(0xffc89600), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(obj, &lv_font_montserrat_14, LV_PART_MAIN | LV_STATE_DEFAULT);
    {
        lv_obj_t *parent_obj = obj;
        {
            // roster_heading_1
            lv_obj_t *obj = lv_label_create(parent_obj);
            objects.roster_heading_1 = obj;
            lv_obj_set_pos(obj, 94, 36);
            lv_obj_set_size(obj, 140, 20);
            lv_obj_clear_flag(obj, LV_OBJ_FLAG_CLICK_FOCUSABLE|LV_OBJ_FLAG_GESTURE_BUBBLE|LV_OBJ_FLAG_PRESS_LOCK|LV_OBJ_FLAG_SCROLLABLE|LV_OBJ_FLAG_SCROLL_CHAIN_HOR|LV_OBJ_FLAG_SCROLL_CHAIN_VER|LV_OBJ_FLAG_SCROLL_ELASTIC|LV_OBJ_FLAG_SCROLL_MOMENTUM|LV_OBJ_FLAG_SNAPPABLE);
            lv_obj_set_style_text_align(obj, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_font(obj, &lv_font_montserrat_18, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_color(obj, lv_color_hex(0xffffffff), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_label_set_text(obj, "Roster");
        }
        {
            // btnCancelEditLoco
            lv_obj_t *obj = lv_btn_create(parent_obj);
            objects.btn_cancel_edit_loco = obj;
            lv_obj_set_pos(obj, 4, 427);
            lv_obj_set_size(obj, 85, 50);
            lv_obj_add_event_cb(obj, action_roster_button, LV_EVENT_RELEASED, (void *)30);
            lv_obj_clear_flag(obj, LV_OBJ_FLAG_CLICK_FOCUSABLE|LV_OBJ_FLAG_GESTURE_BUBBLE|LV_OBJ_FLAG_PRESS_LOCK|LV_OBJ_FLAG_SCROLL_CHAIN_HOR|LV_OBJ_FLAG_SCROLL_CHAIN_VER|LV_OBJ_FLAG_SCROLL_ELASTIC|LV_OBJ_FLAG_SCROLL_MOMENTUM|LV_OBJ_FLAG_SNAPPABLE);
            lv_obj_set_style_bg_color(obj, lv_color_hex(0xffffffff), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_bg_grad_dir(obj, LV_GRAD_DIR_VER, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_bg_grad_color(obj, lv_color_hex(0xff000000), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_outline_width(obj, 1, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_font(obj, &lv_font_montserrat_24, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_shadow_width(obj, 5, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_shadow_ofs_x(obj, 3, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_shadow_ofs_y(obj, 3, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_shadow_spread(obj, 2, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_shadow_color(obj, lv_color_hex(0xff000000), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_shadow_opa(obj, 127, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_bg_color(obj, lv_color_hex(0xff000000), LV_PART_MAIN | LV_STATE_PRESSED);
            lv_obj_set_style_bg_grad_dir(obj, LV_GRAD_DIR_VER, LV_PART_MAIN | LV_STATE_PRESSED);
            lv_obj_set_style_bg_grad_color(obj, lv_color_hex(0xfffff200), LV_PART_MAIN | LV_STATE_PRESSED);
            lv_obj_set_style_text_color(obj, lv_color_hex(0xff000000), LV_PART_MAIN | LV_STATE_PRESSED);
            {
                lv_obj_t *parent_obj = obj;
                {
                    lv_obj_t *obj = lv_label_create(parent_obj);
                    objects.obj20 = obj;
                    lv_obj_set_pos(obj, 0, 0);
                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                    lv_obj_clear_flag(obj, LV_OBJ_FLAG_CLICK_FOCUSABLE|LV_OBJ_FLAG_GESTURE_BUBBLE|LV_OBJ_FLAG_PRESS_LOCK|LV_OBJ_FLAG_SCROLLABLE|LV_OBJ_FLAG_SCROLL_CHAIN_HOR|LV_OBJ_FLAG_SCROLL_CHAIN_VER|LV_OBJ_FLAG_SCROLL_ELASTIC|LV_OBJ_FLAG_SCROLL_MOMENTUM|LV_OBJ_FLAG_SNAPPABLE);
                    lv_obj_set_style_align(obj, LV_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_bg_color(obj, lv_color_hex(0xffffffff), LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_bg_grad_dir(obj, LV_GRAD_DIR_VER, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_bg_grad_color(obj, lv_color_hex(0xff000000), LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_bg_grad_stop(obj, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_text_font(obj, &lv_font_montserrat_20, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_label_set_text(obj, "Cancel");
                }
            }
        }
        {
            // btnSelectLoco
            lv_obj_t *obj = lv_btn_create(parent_obj);
            objects.btn_select_loco = obj;
            lv_obj_set_pos(obj, 232, 426);
            lv_obj_set_size(obj, 85, 50);
            lv_obj_add_event_cb(obj, event_handler_checked_cb_roster_btn_select_loco, LV_EVENT_VALUE_CHANGED, (void *)32);
            lv_obj_add_event_cb(obj, event_handler_unchecked_cb_roster_btn_select_loco, LV_EVENT_VALUE_CHANGED, (void *)29);
            lv_obj_add_flag(obj, LV_OBJ_FLAG_CHECKABLE);
            lv_obj_clear_flag(obj, LV_OBJ_FLAG_CLICK_FOCUSABLE|LV_OBJ_FLAG_GESTURE_BUBBLE|LV_OBJ_FLAG_PRESS_LOCK|LV_OBJ_FLAG_SCROLL_CHAIN_HOR|LV_OBJ_FLAG_SCROLL_CHAIN_VER|LV_OBJ_FLAG_SCROLL_ELASTIC|LV_OBJ_FLAG_SCROLL_MOMENTUM|LV_OBJ_FLAG_SNAPPABLE);
            lv_obj_set_style_bg_color(obj, lv_color_hex(0xffffffff), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_bg_grad_dir(obj, LV_GRAD_DIR_VER, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_bg_grad_color(obj, lv_color_hex(0xff000000), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_outline_width(obj, 1, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_font(obj, &lv_font_montserrat_24, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_shadow_width(obj, 5, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_shadow_ofs_x(obj, 3, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_shadow_ofs_y(obj, 3, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_shadow_spread(obj, 2, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_shadow_color(obj, lv_color_hex(0xff000000), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_shadow_opa(obj, 127, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_bg_color(obj, lv_color_hex(0xff000000), LV_PART_MAIN | LV_STATE_PRESSED);
            lv_obj_set_style_bg_grad_dir(obj, LV_GRAD_DIR_VER, LV_PART_MAIN | LV_STATE_PRESSED);
            lv_obj_set_style_bg_grad_color(obj, lv_color_hex(0xfffff200), LV_PART_MAIN | LV_STATE_PRESSED);
            lv_obj_set_style_text_color(obj, lv_color_hex(0xff000000), LV_PART_MAIN | LV_STATE_PRESSED);
            {
                lv_obj_t *parent_obj = obj;
                {
                    lv_obj_t *obj = lv_label_create(parent_obj);
                    objects.obj21 = obj;
                    lv_obj_set_pos(obj, 0, 0);
                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                    lv_obj_clear_flag(obj, LV_OBJ_FLAG_CLICK_FOCUSABLE|LV_OBJ_FLAG_GESTURE_BUBBLE|LV_OBJ_FLAG_PRESS_LOCK|LV_OBJ_FLAG_SCROLLABLE|LV_OBJ_FLAG_SCROLL_CHAIN_HOR|LV_OBJ_FLAG_SCROLL_CHAIN_VER|LV_OBJ_FLAG_SCROLL_ELASTIC|LV_OBJ_FLAG_SCROLL_MOMENTUM|LV_OBJ_FLAG_SNAPPABLE);
                    lv_obj_set_style_align(obj, LV_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_bg_color(obj, lv_color_hex(0xffffffff), LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_bg_grad_dir(obj, LV_GRAD_DIR_VER, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_bg_grad_color(obj, lv_color_hex(0xff000000), LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_bg_grad_stop(obj, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_text_font(obj, &lv_font_montserrat_20, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_label_set_text(obj, "Select");
                }
            }
        }
        {
            // btnEditLoco
            lv_obj_t *obj = lv_btn_create(parent_obj);
            objects.btn_edit_loco = obj;
            lv_obj_set_pos(obj, 118, 427);
            lv_obj_set_size(obj, 85, 50);
            lv_obj_add_event_cb(obj, event_handler_checked_cb_roster_btn_edit_loco, LV_EVENT_VALUE_CHANGED, (void *)31);
            lv_obj_add_event_cb(obj, event_handler_unchecked_cb_roster_btn_edit_loco, LV_EVENT_VALUE_CHANGED, (void *)28);
            lv_obj_add_flag(obj, LV_OBJ_FLAG_CHECKABLE);
            lv_obj_clear_flag(obj, LV_OBJ_FLAG_CLICK_FOCUSABLE|LV_OBJ_FLAG_GESTURE_BUBBLE|LV_OBJ_FLAG_PRESS_LOCK|LV_OBJ_FLAG_SCROLL_CHAIN_HOR|LV_OBJ_FLAG_SCROLL_CHAIN_VER|LV_OBJ_FLAG_SCROLL_ELASTIC|LV_OBJ_FLAG_SCROLL_MOMENTUM|LV_OBJ_FLAG_SNAPPABLE);
            lv_obj_set_style_bg_color(obj, lv_color_hex(0xffffffff), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_bg_grad_dir(obj, LV_GRAD_DIR_VER, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_bg_grad_color(obj, lv_color_hex(0xff000000), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_outline_width(obj, 1, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_font(obj, &lv_font_montserrat_24, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_shadow_width(obj, 5, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_shadow_ofs_x(obj, 3, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_shadow_ofs_y(obj, 3, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_shadow_spread(obj, 2, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_shadow_color(obj, lv_color_hex(0xff000000), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_shadow_opa(obj, 127, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_bg_color(obj, lv_color_hex(0xff000000), LV_PART_MAIN | LV_STATE_PRESSED);
            lv_obj_set_style_bg_grad_dir(obj, LV_GRAD_DIR_VER, LV_PART_MAIN | LV_STATE_PRESSED);
            lv_obj_set_style_bg_grad_color(obj, lv_color_hex(0xfffff200), LV_PART_MAIN | LV_STATE_PRESSED);
            lv_obj_set_style_text_color(obj, lv_color_hex(0xff000000), LV_PART_MAIN | LV_STATE_PRESSED);
            {
                lv_obj_t *parent_obj = obj;
                {
                    lv_obj_t *obj = lv_label_create(parent_obj);
                    objects.obj22 = obj;
                    lv_obj_set_pos(obj, 0, 0);
                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                    lv_obj_clear_flag(obj, LV_OBJ_FLAG_CLICK_FOCUSABLE|LV_OBJ_FLAG_GESTURE_BUBBLE|LV_OBJ_FLAG_PRESS_LOCK|LV_OBJ_FLAG_SCROLLABLE|LV_OBJ_FLAG_SCROLL_CHAIN_HOR|LV_OBJ_FLAG_SCROLL_CHAIN_VER|LV_OBJ_FLAG_SCROLL_ELASTIC|LV_OBJ_FLAG_SCROLL_MOMENTUM|LV_OBJ_FLAG_SNAPPABLE);
                    lv_obj_set_style_align(obj, LV_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_bg_color(obj, lv_color_hex(0xffffffff), LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_bg_grad_dir(obj, LV_GRAD_DIR_VER, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_bg_grad_color(obj, lv_color_hex(0xff000000), LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_bg_grad_stop(obj, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_text_font(obj, &lv_font_montserrat_20, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_label_set_text(obj, "Edit");
                }
            }
        }
        {
            lv_obj_t *obj = lv_btn_create(parent_obj);
            objects.obj0 = obj;
            lv_obj_set_pos(obj, 2, 140);
            lv_obj_set_size(obj, 268, 24);
            lv_obj_add_event_cb(obj, event_handler_checked_cb_roster_obj0, LV_EVENT_VALUE_CHANGED, (void *)12);
            lv_obj_add_flag(obj, LV_OBJ_FLAG_CHECKABLE);
            lv_obj_set_style_bg_color(obj, lv_color_hex(0xffc89600), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_border_width(obj, 2, LV_PART_MAIN | LV_STATE_CHECKED);
            lv_obj_set_style_shadow_width(obj, 2, LV_PART_MAIN | LV_STATE_CHECKED);
            lv_obj_set_style_shadow_ofs_x(obj, 2, LV_PART_MAIN | LV_STATE_CHECKED);
            lv_obj_set_style_shadow_spread(obj, 2, LV_PART_MAIN | LV_STATE_CHECKED);
            lv_obj_set_style_shadow_color(obj, lv_color_hex(0xff000000), LV_PART_MAIN | LV_STATE_CHECKED);
            lv_obj_set_style_shadow_opa(obj, 127, LV_PART_MAIN | LV_STATE_CHECKED);
            lv_obj_set_style_shadow_ofs_y(obj, 2, LV_PART_MAIN | LV_STATE_CHECKED);
            lv_obj_set_style_bg_color(obj, lv_color_hex(0xffc89600), LV_PART_MAIN | LV_STATE_CHECKED);
            lv_obj_set_style_text_color(obj, lv_color_hex(0xff000000), LV_PART_MAIN | LV_STATE_CHECKED);
        }
        {
            lv_obj_t *obj = lv_btn_create(parent_obj);
            objects.obj1 = obj;
            lv_obj_set_pos(obj, 2, 170);
            lv_obj_set_size(obj, 268, 24);
            lv_obj_add_event_cb(obj, event_handler_checked_cb_roster_obj1, LV_EVENT_VALUE_CHANGED, (void *)13);
            lv_obj_add_flag(obj, LV_OBJ_FLAG_CHECKABLE);
            lv_obj_set_style_bg_color(obj, lv_color_hex(0xffc89600), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_border_width(obj, 2, LV_PART_MAIN | LV_STATE_CHECKED);
            lv_obj_set_style_shadow_width(obj, 2, LV_PART_MAIN | LV_STATE_CHECKED);
            lv_obj_set_style_shadow_ofs_x(obj, 2, LV_PART_MAIN | LV_STATE_CHECKED);
            lv_obj_set_style_shadow_spread(obj, 2, LV_PART_MAIN | LV_STATE_CHECKED);
            lv_obj_set_style_shadow_color(obj, lv_color_hex(0xff000000), LV_PART_MAIN | LV_STATE_CHECKED);
            lv_obj_set_style_shadow_opa(obj, 127, LV_PART_MAIN | LV_STATE_CHECKED);
            lv_obj_set_style_shadow_ofs_y(obj, 2, LV_PART_MAIN | LV_STATE_CHECKED);
            lv_obj_set_style_bg_color(obj, lv_color_hex(0xffc89600), LV_PART_MAIN | LV_STATE_CHECKED);
            lv_obj_set_style_text_color(obj, lv_color_hex(0xff000000), LV_PART_MAIN | LV_STATE_CHECKED);
        }
        {
            lv_obj_t *obj = lv_btn_create(parent_obj);
            objects.obj2 = obj;
            lv_obj_set_pos(obj, 2, 200);
            lv_obj_set_size(obj, 268, 24);
            lv_obj_add_event_cb(obj, event_handler_checked_cb_roster_obj2, LV_EVENT_VALUE_CHANGED, (void *)14);
            lv_obj_add_flag(obj, LV_OBJ_FLAG_CHECKABLE);
            lv_obj_set_style_bg_color(obj, lv_color_hex(0xffc89600), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_border_width(obj, 2, LV_PART_MAIN | LV_STATE_CHECKED);
            lv_obj_set_style_shadow_width(obj, 2, LV_PART_MAIN | LV_STATE_CHECKED);
            lv_obj_set_style_shadow_ofs_x(obj, 2, LV_PART_MAIN | LV_STATE_CHECKED);
            lv_obj_set_style_shadow_spread(obj, 2, LV_PART_MAIN | LV_STATE_CHECKED);
            lv_obj_set_style_shadow_color(obj, lv_color_hex(0xff000000), LV_PART_MAIN | LV_STATE_CHECKED);
            lv_obj_set_style_shadow_opa(obj, 127, LV_PART_MAIN | LV_STATE_CHECKED);
            lv_obj_set_style_shadow_ofs_y(obj, 2, LV_PART_MAIN | LV_STATE_CHECKED);
            lv_obj_set_style_bg_color(obj, lv_color_hex(0xffc89600), LV_PART_MAIN | LV_STATE_CHECKED);
            lv_obj_set_style_text_color(obj, lv_color_hex(0xff000000), LV_PART_MAIN | LV_STATE_CHECKED);
        }
        {
            lv_obj_t *obj = lv_btn_create(parent_obj);
            objects.obj3 = obj;
            lv_obj_set_pos(obj, 2, 230);
            lv_obj_set_size(obj, 268, 24);
            lv_obj_add_event_cb(obj, event_handler_checked_cb_roster_obj3, LV_EVENT_VALUE_CHANGED, (void *)15);
            lv_obj_add_flag(obj, LV_OBJ_FLAG_CHECKABLE);
            lv_obj_set_style_bg_color(obj, lv_color_hex(0xffc89600), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_border_width(obj, 2, LV_PART_MAIN | LV_STATE_CHECKED);
            lv_obj_set_style_shadow_width(obj, 2, LV_PART_MAIN | LV_STATE_CHECKED);
            lv_obj_set_style_shadow_ofs_x(obj, 2, LV_PART_MAIN | LV_STATE_CHECKED);
            lv_obj_set_style_shadow_spread(obj, 2, LV_PART_MAIN | LV_STATE_CHECKED);
            lv_obj_set_style_shadow_color(obj, lv_color_hex(0xff000000), LV_PART_MAIN | LV_STATE_CHECKED);
            lv_obj_set_style_shadow_opa(obj, 127, LV_PART_MAIN | LV_STATE_CHECKED);
            lv_obj_set_style_shadow_ofs_y(obj, 2, LV_PART_MAIN | LV_STATE_CHECKED);
            lv_obj_set_style_bg_color(obj, lv_color_hex(0xffc89600), LV_PART_MAIN | LV_STATE_CHECKED);
            lv_obj_set_style_text_color(obj, lv_color_hex(0xff000000), LV_PART_MAIN | LV_STATE_CHECKED);
        }
        {
            lv_obj_t *obj = lv_btn_create(parent_obj);
            objects.obj4 = obj;
            lv_obj_set_pos(obj, 2, 260);
            lv_obj_set_size(obj, 268, 24);
            lv_obj_add_event_cb(obj, event_handler_checked_cb_roster_obj4, LV_EVENT_VALUE_CHANGED, (void *)16);
            lv_obj_add_flag(obj, LV_OBJ_FLAG_CHECKABLE);
            lv_obj_set_style_bg_color(obj, lv_color_hex(0xffc89600), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_border_width(obj, 2, LV_PART_MAIN | LV_STATE_CHECKED);
            lv_obj_set_style_shadow_width(obj, 2, LV_PART_MAIN | LV_STATE_CHECKED);
            lv_obj_set_style_shadow_ofs_x(obj, 2, LV_PART_MAIN | LV_STATE_CHECKED);
            lv_obj_set_style_shadow_spread(obj, 2, LV_PART_MAIN | LV_STATE_CHECKED);
            lv_obj_set_style_shadow_color(obj, lv_color_hex(0xff000000), LV_PART_MAIN | LV_STATE_CHECKED);
            lv_obj_set_style_shadow_opa(obj, 127, LV_PART_MAIN | LV_STATE_CHECKED);
            lv_obj_set_style_shadow_ofs_y(obj, 2, LV_PART_MAIN | LV_STATE_CHECKED);
            lv_obj_set_style_bg_color(obj, lv_color_hex(0xffc89600), LV_PART_MAIN | LV_STATE_CHECKED);
            lv_obj_set_style_text_color(obj, lv_color_hex(0xff000000), LV_PART_MAIN | LV_STATE_CHECKED);
        }
        {
            lv_obj_t *obj = lv_btn_create(parent_obj);
            objects.obj5 = obj;
            lv_obj_set_pos(obj, 2, 290);
            lv_obj_set_size(obj, 268, 24);
            lv_obj_add_event_cb(obj, event_handler_checked_cb_roster_obj5, LV_EVENT_VALUE_CHANGED, (void *)17);
            lv_obj_add_flag(obj, LV_OBJ_FLAG_CHECKABLE);
            lv_obj_set_style_bg_color(obj, lv_color_hex(0xffc89600), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_border_width(obj, 2, LV_PART_MAIN | LV_STATE_CHECKED);
            lv_obj_set_style_shadow_width(obj, 2, LV_PART_MAIN | LV_STATE_CHECKED);
            lv_obj_set_style_shadow_ofs_x(obj, 2, LV_PART_MAIN | LV_STATE_CHECKED);
            lv_obj_set_style_shadow_spread(obj, 2, LV_PART_MAIN | LV_STATE_CHECKED);
            lv_obj_set_style_shadow_color(obj, lv_color_hex(0xff000000), LV_PART_MAIN | LV_STATE_CHECKED);
            lv_obj_set_style_shadow_opa(obj, 127, LV_PART_MAIN | LV_STATE_CHECKED);
            lv_obj_set_style_shadow_ofs_y(obj, 2, LV_PART_MAIN | LV_STATE_CHECKED);
            lv_obj_set_style_bg_color(obj, lv_color_hex(0xffc89600), LV_PART_MAIN | LV_STATE_CHECKED);
            lv_obj_set_style_text_color(obj, lv_color_hex(0xff000000), LV_PART_MAIN | LV_STATE_CHECKED);
        }
        {
            lv_obj_t *obj = lv_btn_create(parent_obj);
            objects.obj6 = obj;
            lv_obj_set_pos(obj, 2, 320);
            lv_obj_set_size(obj, 268, 24);
            lv_obj_add_event_cb(obj, event_handler_checked_cb_roster_obj6, LV_EVENT_VALUE_CHANGED, (void *)18);
            lv_obj_add_flag(obj, LV_OBJ_FLAG_CHECKABLE);
            lv_obj_set_style_bg_color(obj, lv_color_hex(0xffc89600), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_border_width(obj, 2, LV_PART_MAIN | LV_STATE_CHECKED);
            lv_obj_set_style_shadow_width(obj, 2, LV_PART_MAIN | LV_STATE_CHECKED);
            lv_obj_set_style_shadow_ofs_x(obj, 2, LV_PART_MAIN | LV_STATE_CHECKED);
            lv_obj_set_style_shadow_spread(obj, 2, LV_PART_MAIN | LV_STATE_CHECKED);
            lv_obj_set_style_shadow_color(obj, lv_color_hex(0xff000000), LV_PART_MAIN | LV_STATE_CHECKED);
            lv_obj_set_style_shadow_opa(obj, 127, LV_PART_MAIN | LV_STATE_CHECKED);
            lv_obj_set_style_shadow_ofs_y(obj, 2, LV_PART_MAIN | LV_STATE_CHECKED);
            lv_obj_set_style_bg_color(obj, lv_color_hex(0xffc89600), LV_PART_MAIN | LV_STATE_CHECKED);
            lv_obj_set_style_text_color(obj, lv_color_hex(0xff000000), LV_PART_MAIN | LV_STATE_CHECKED);
        }
        {
            lv_obj_t *obj = lv_btn_create(parent_obj);
            objects.obj7 = obj;
            lv_obj_set_pos(obj, 2, 350);
            lv_obj_set_size(obj, 268, 24);
            lv_obj_add_event_cb(obj, event_handler_checked_cb_roster_obj7, LV_EVENT_VALUE_CHANGED, (void *)19);
            lv_obj_add_flag(obj, LV_OBJ_FLAG_CHECKABLE);
            lv_obj_set_style_bg_color(obj, lv_color_hex(0xffc89600), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_border_width(obj, 2, LV_PART_MAIN | LV_STATE_CHECKED);
            lv_obj_set_style_shadow_width(obj, 2, LV_PART_MAIN | LV_STATE_CHECKED);
            lv_obj_set_style_shadow_ofs_x(obj, 2, LV_PART_MAIN | LV_STATE_CHECKED);
            lv_obj_set_style_shadow_spread(obj, 2, LV_PART_MAIN | LV_STATE_CHECKED);
            lv_obj_set_style_shadow_color(obj, lv_color_hex(0xff000000), LV_PART_MAIN | LV_STATE_CHECKED);
            lv_obj_set_style_shadow_opa(obj, 127, LV_PART_MAIN | LV_STATE_CHECKED);
            lv_obj_set_style_shadow_ofs_y(obj, 2, LV_PART_MAIN | LV_STATE_CHECKED);
            lv_obj_set_style_bg_color(obj, lv_color_hex(0xffc89600), LV_PART_MAIN | LV_STATE_CHECKED);
            lv_obj_set_style_text_color(obj, lv_color_hex(0xff000000), LV_PART_MAIN | LV_STATE_CHECKED);
        }
        {
            // tbl_roster
            lv_obj_t *obj = lv_table_create(parent_obj);
            objects.tbl_roster = obj;
            lv_obj_set_pos(obj, 6, 82);
            lv_obj_set_size(obj, 305, 337);
            lv_obj_set_style_bg_color(obj, lv_color_hex(0xff0404ff), LV_PART_ITEMS | LV_STATE_CHECKED);
            lv_obj_set_style_pad_top(obj, 5, LV_PART_ITEMS | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_bottom(obj, 5, LV_PART_ITEMS | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_left(obj, 5, LV_PART_ITEMS | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_right(obj, 5, LV_PART_ITEMS | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_row(obj, 5, LV_PART_ITEMS | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_column(obj, 5, LV_PART_ITEMS | LV_STATE_DEFAULT);
            lv_obj_set_style_text_font(obj, &lv_font_montserrat_14, LV_PART_ITEMS | LV_STATE_DEFAULT);
            lv_obj_set_style_text_font(obj, &lv_font_montserrat_14, LV_PART_MAIN | LV_STATE_DEFAULT);
        }
    }
    
    tick_screen_roster();
}

void tick_screen_roster() {
}

void create_screen_edit_loco() {
    lv_obj_t *obj = lv_obj_create(0);
    objects.edit_loco = obj;
    lv_obj_set_pos(obj, 0, 0);
    lv_obj_set_size(obj, 320, 480);
    lv_obj_set_style_bg_color(obj, lv_color_hex(0xffc89600), LV_PART_MAIN | LV_STATE_DEFAULT);
    {
        lv_obj_t *parent_obj = obj;
        {
            lv_obj_t *obj = lv_label_create(parent_obj);
            objects.obj23 = obj;
            lv_obj_set_pos(obj, 94, 36);
            lv_obj_set_size(obj, 140, 20);
            lv_obj_clear_flag(obj, LV_OBJ_FLAG_CLICK_FOCUSABLE|LV_OBJ_FLAG_GESTURE_BUBBLE|LV_OBJ_FLAG_PRESS_LOCK|LV_OBJ_FLAG_SCROLLABLE|LV_OBJ_FLAG_SCROLL_CHAIN_HOR|LV_OBJ_FLAG_SCROLL_CHAIN_VER|LV_OBJ_FLAG_SCROLL_ELASTIC|LV_OBJ_FLAG_SCROLL_MOMENTUM|LV_OBJ_FLAG_SNAPPABLE);
            lv_obj_set_style_text_align(obj, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_font(obj, &lv_font_montserrat_18, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_color(obj, lv_color_hex(0xffffffff), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_label_set_text(obj, "Edit Loco");
        }
        {
            // btnEditLocoCancel_1
            lv_obj_t *obj = lv_btn_create(parent_obj);
            objects.btn_edit_loco_cancel_1 = obj;
            lv_obj_set_pos(obj, 4, 426);
            lv_obj_set_size(obj, 85, 50);
            lv_obj_add_event_cb(obj, action_edit_loco_button, LV_EVENT_RELEASED, (void *)30);
            lv_obj_clear_flag(obj, LV_OBJ_FLAG_CLICK_FOCUSABLE|LV_OBJ_FLAG_GESTURE_BUBBLE|LV_OBJ_FLAG_PRESS_LOCK|LV_OBJ_FLAG_SCROLL_CHAIN_HOR|LV_OBJ_FLAG_SCROLL_CHAIN_VER|LV_OBJ_FLAG_SCROLL_ELASTIC|LV_OBJ_FLAG_SCROLL_MOMENTUM|LV_OBJ_FLAG_SNAPPABLE);
            lv_obj_set_style_bg_color(obj, lv_color_hex(0xffffffff), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_bg_grad_dir(obj, LV_GRAD_DIR_VER, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_bg_grad_color(obj, lv_color_hex(0xff000000), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_outline_width(obj, 1, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_font(obj, &lv_font_montserrat_24, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_shadow_width(obj, 10, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_shadow_ofs_x(obj, 5, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_shadow_ofs_y(obj, 5, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_shadow_spread(obj, 2, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_shadow_opa(obj, 128, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_shadow_color(obj, lv_color_hex(0xff000000), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_bg_color(obj, lv_color_hex(0xff000000), LV_PART_MAIN | LV_STATE_PRESSED);
            lv_obj_set_style_bg_grad_dir(obj, LV_GRAD_DIR_VER, LV_PART_MAIN | LV_STATE_PRESSED);
            lv_obj_set_style_bg_grad_color(obj, lv_color_hex(0xfffff200), LV_PART_MAIN | LV_STATE_PRESSED);
            lv_obj_set_style_text_color(obj, lv_color_hex(0xff000000), LV_PART_MAIN | LV_STATE_PRESSED);
            lv_obj_set_style_transform_width(obj, -2, LV_PART_MAIN | LV_STATE_PRESSED);
            lv_obj_set_style_transform_height(obj, -2, LV_PART_MAIN | LV_STATE_PRESSED);
            lv_obj_set_style_shadow_width(obj, 0, LV_PART_MAIN | LV_STATE_PRESSED);
            lv_obj_set_style_shadow_ofs_x(obj, 0, LV_PART_MAIN | LV_STATE_PRESSED);
            lv_obj_set_style_shadow_ofs_y(obj, 0, LV_PART_MAIN | LV_STATE_PRESSED);
            lv_obj_set_style_shadow_spread(obj, 2, LV_PART_MAIN | LV_STATE_PRESSED);
            lv_obj_set_style_text_font(obj, &lv_font_montserrat_20, LV_PART_MAIN | LV_STATE_CHECKED);
            {
                lv_obj_t *parent_obj = obj;
                {
                    lv_obj_t *obj = lv_label_create(parent_obj);
                    objects.obj24 = obj;
                    lv_obj_set_pos(obj, 0, 0);
                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                    lv_obj_clear_flag(obj, LV_OBJ_FLAG_CLICK_FOCUSABLE|LV_OBJ_FLAG_GESTURE_BUBBLE|LV_OBJ_FLAG_PRESS_LOCK|LV_OBJ_FLAG_SCROLLABLE|LV_OBJ_FLAG_SCROLL_CHAIN_HOR|LV_OBJ_FLAG_SCROLL_CHAIN_VER|LV_OBJ_FLAG_SCROLL_ELASTIC|LV_OBJ_FLAG_SCROLL_MOMENTUM|LV_OBJ_FLAG_SNAPPABLE);
                    lv_obj_set_style_align(obj, LV_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_bg_color(obj, lv_color_hex(0xffffffff), LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_bg_grad_dir(obj, LV_GRAD_DIR_VER, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_bg_grad_color(obj, lv_color_hex(0xff000000), LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_bg_grad_stop(obj, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_text_font(obj, &lv_font_montserrat_20, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_text_font(obj, &lv_font_montserrat_20, LV_PART_MAIN | LV_STATE_CHECKED);
                    lv_label_set_text(obj, "Cancel");
                }
            }
        }
        {
            // btnProgEditLoco_1
            lv_obj_t *obj = lv_btn_create(parent_obj);
            objects.btn_prog_edit_loco_1 = obj;
            lv_obj_set_pos(obj, 118, 426);
            lv_obj_set_size(obj, 85, 50);
            lv_obj_add_event_cb(obj, action_edit_loco_button, LV_EVENT_RELEASED, (void *)31);
            lv_obj_clear_flag(obj, LV_OBJ_FLAG_CLICK_FOCUSABLE|LV_OBJ_FLAG_GESTURE_BUBBLE|LV_OBJ_FLAG_PRESS_LOCK|LV_OBJ_FLAG_SCROLL_CHAIN_HOR|LV_OBJ_FLAG_SCROLL_CHAIN_VER|LV_OBJ_FLAG_SCROLL_ELASTIC|LV_OBJ_FLAG_SCROLL_MOMENTUM|LV_OBJ_FLAG_SNAPPABLE);
            lv_obj_set_style_bg_color(obj, lv_color_hex(0xffffffff), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_bg_grad_dir(obj, LV_GRAD_DIR_VER, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_bg_grad_color(obj, lv_color_hex(0xff000000), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_outline_width(obj, 1, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_font(obj, &lv_font_montserrat_24, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_shadow_width(obj, 10, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_shadow_ofs_x(obj, 5, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_shadow_ofs_y(obj, 5, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_shadow_spread(obj, 2, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_shadow_opa(obj, 128, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_shadow_color(obj, lv_color_hex(0xff000000), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_bg_color(obj, lv_color_hex(0xff000000), LV_PART_MAIN | LV_STATE_PRESSED);
            lv_obj_set_style_bg_grad_dir(obj, LV_GRAD_DIR_VER, LV_PART_MAIN | LV_STATE_PRESSED);
            lv_obj_set_style_bg_grad_color(obj, lv_color_hex(0xfffff200), LV_PART_MAIN | LV_STATE_PRESSED);
            lv_obj_set_style_text_color(obj, lv_color_hex(0xff000000), LV_PART_MAIN | LV_STATE_PRESSED);
            lv_obj_set_style_transform_width(obj, -2, LV_PART_MAIN | LV_STATE_PRESSED);
            lv_obj_set_style_transform_height(obj, -2, LV_PART_MAIN | LV_STATE_PRESSED);
            lv_obj_set_style_shadow_width(obj, 0, LV_PART_MAIN | LV_STATE_PRESSED);
            lv_obj_set_style_shadow_ofs_x(obj, 0, LV_PART_MAIN | LV_STATE_PRESSED);
            lv_obj_set_style_shadow_ofs_y(obj, 0, LV_PART_MAIN | LV_STATE_PRESSED);
            lv_obj_set_style_shadow_spread(obj, 2, LV_PART_MAIN | LV_STATE_PRESSED);
            lv_obj_set_style_text_font(obj, &lv_font_montserrat_20, LV_PART_MAIN | LV_STATE_CHECKED);
            {
                lv_obj_t *parent_obj = obj;
                {
                    lv_obj_t *obj = lv_label_create(parent_obj);
                    objects.obj25 = obj;
                    lv_obj_set_pos(obj, 0, 0);
                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                    lv_obj_clear_flag(obj, LV_OBJ_FLAG_CLICK_FOCUSABLE|LV_OBJ_FLAG_GESTURE_BUBBLE|LV_OBJ_FLAG_PRESS_LOCK|LV_OBJ_FLAG_SCROLLABLE|LV_OBJ_FLAG_SCROLL_CHAIN_HOR|LV_OBJ_FLAG_SCROLL_CHAIN_VER|LV_OBJ_FLAG_SCROLL_ELASTIC|LV_OBJ_FLAG_SCROLL_MOMENTUM|LV_OBJ_FLAG_SNAPPABLE);
                    lv_obj_set_style_align(obj, LV_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_bg_color(obj, lv_color_hex(0xffffffff), LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_bg_grad_dir(obj, LV_GRAD_DIR_VER, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_bg_grad_color(obj, lv_color_hex(0xff000000), LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_bg_grad_stop(obj, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_text_font(obj, &lv_font_montserrat_20, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_text_font(obj, &lv_font_montserrat_20, LV_PART_MAIN | LV_STATE_CHECKED);
                    lv_label_set_text(obj, "Prog");
                }
            }
        }
        {
            // btnEditLocoDone_1
            lv_obj_t *obj = lv_btn_create(parent_obj);
            objects.btn_edit_loco_done_1 = obj;
            lv_obj_set_pos(obj, 232, 426);
            lv_obj_set_size(obj, 85, 50);
            lv_obj_add_event_cb(obj, action_edit_loco_button, LV_EVENT_RELEASED, (void *)32);
            lv_obj_clear_flag(obj, LV_OBJ_FLAG_CLICK_FOCUSABLE|LV_OBJ_FLAG_GESTURE_BUBBLE|LV_OBJ_FLAG_PRESS_LOCK|LV_OBJ_FLAG_SCROLL_CHAIN_HOR|LV_OBJ_FLAG_SCROLL_CHAIN_VER|LV_OBJ_FLAG_SCROLL_ELASTIC|LV_OBJ_FLAG_SCROLL_MOMENTUM|LV_OBJ_FLAG_SNAPPABLE);
            lv_obj_set_style_bg_color(obj, lv_color_hex(0xffffffff), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_bg_grad_dir(obj, LV_GRAD_DIR_VER, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_bg_grad_color(obj, lv_color_hex(0xff000000), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_outline_width(obj, 1, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_font(obj, &lv_font_montserrat_24, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_shadow_width(obj, 10, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_shadow_ofs_x(obj, 5, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_shadow_ofs_y(obj, 5, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_shadow_spread(obj, 2, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_shadow_opa(obj, 128, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_shadow_color(obj, lv_color_hex(0xff000000), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_bg_color(obj, lv_color_hex(0xff000000), LV_PART_MAIN | LV_STATE_PRESSED);
            lv_obj_set_style_bg_grad_dir(obj, LV_GRAD_DIR_VER, LV_PART_MAIN | LV_STATE_PRESSED);
            lv_obj_set_style_bg_grad_color(obj, lv_color_hex(0xfffff200), LV_PART_MAIN | LV_STATE_PRESSED);
            lv_obj_set_style_text_color(obj, lv_color_hex(0xff000000), LV_PART_MAIN | LV_STATE_PRESSED);
            lv_obj_set_style_transform_width(obj, -2, LV_PART_MAIN | LV_STATE_PRESSED);
            lv_obj_set_style_transform_height(obj, -2, LV_PART_MAIN | LV_STATE_PRESSED);
            lv_obj_set_style_shadow_width(obj, 0, LV_PART_MAIN | LV_STATE_PRESSED);
            lv_obj_set_style_shadow_ofs_x(obj, 0, LV_PART_MAIN | LV_STATE_PRESSED);
            lv_obj_set_style_shadow_ofs_y(obj, 0, LV_PART_MAIN | LV_STATE_PRESSED);
            lv_obj_set_style_shadow_spread(obj, 2, LV_PART_MAIN | LV_STATE_PRESSED);
            lv_obj_set_style_text_font(obj, &lv_font_montserrat_20, LV_PART_MAIN | LV_STATE_CHECKED);
            {
                lv_obj_t *parent_obj = obj;
                {
                    lv_obj_t *obj = lv_label_create(parent_obj);
                    objects.obj26 = obj;
                    lv_obj_set_pos(obj, 0, 0);
                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                    lv_obj_clear_flag(obj, LV_OBJ_FLAG_CLICK_FOCUSABLE|LV_OBJ_FLAG_GESTURE_BUBBLE|LV_OBJ_FLAG_PRESS_LOCK|LV_OBJ_FLAG_SCROLLABLE|LV_OBJ_FLAG_SCROLL_CHAIN_HOR|LV_OBJ_FLAG_SCROLL_CHAIN_VER|LV_OBJ_FLAG_SCROLL_ELASTIC|LV_OBJ_FLAG_SCROLL_MOMENTUM|LV_OBJ_FLAG_SNAPPABLE);
                    lv_obj_set_style_align(obj, LV_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_bg_color(obj, lv_color_hex(0xffffffff), LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_bg_grad_dir(obj, LV_GRAD_DIR_VER, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_bg_grad_color(obj, lv_color_hex(0xff000000), LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_bg_grad_stop(obj, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_text_font(obj, &lv_font_montserrat_20, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_text_font(obj, &lv_font_montserrat_20, LV_PART_MAIN | LV_STATE_CHECKED);
                    lv_label_set_text(obj, "Done");
                }
            }
        }
        {
            // taName
            lv_obj_t *obj = lv_textarea_create(parent_obj);
            objects.ta_name = obj;
            lv_obj_set_pos(obj, 5, 76);
            lv_obj_set_size(obj, 312, 36);
            lv_textarea_set_max_length(obj, 30);
            lv_textarea_set_placeholder_text(obj, "Loco Name");
            lv_textarea_set_one_line(obj, true);
            lv_textarea_set_password_mode(obj, false);
            lv_obj_set_style_border_color(obj, lv_color_hex(0xff000000), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_border_width(obj, 1, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_shadow_width(obj, 10, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_shadow_ofs_x(obj, 5, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_shadow_ofs_y(obj, 5, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_shadow_spread(obj, 2, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_shadow_color(obj, lv_color_hex(0xff000000), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_shadow_opa(obj, 127, LV_PART_MAIN | LV_STATE_DEFAULT);
        }
        {
            lv_obj_t *obj = lv_label_create(parent_obj);
            objects.obj27 = obj;
            lv_obj_set_pos(obj, 60, 118);
            lv_obj_set_size(obj, LV_SIZE_CONTENT, 29);
            lv_obj_set_style_text_font(obj, &lv_font_montserrat_14, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_bg_color(obj, lv_color_hex(0xffc89600), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_top(obj, 6, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_left(obj, 8, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_radius(obj, 7, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_label_set_text(obj, "Loco Address:");
        }
        {
            // taAddress
            lv_obj_t *obj = lv_textarea_create(parent_obj);
            objects.ta_address = obj;
            lv_obj_set_pos(obj, 186, 118);
            lv_obj_set_size(obj, 50, 22);
            lv_textarea_set_max_length(obj, 4);
            lv_textarea_set_one_line(obj, true);
            lv_textarea_set_password_mode(obj, false);
            lv_obj_set_style_pad_top(obj, 4, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_bottom(obj, 4, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_left(obj, 1, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_right(obj, 1, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_align(obj, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_font(obj, &lv_font_montserrat_16, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_border_width(obj, 1, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_border_color(obj, lv_color_hex(0xff000000), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_shadow_width(obj, 5, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_shadow_ofs_x(obj, 3, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_shadow_ofs_y(obj, 3, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_shadow_spread(obj, 2, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_shadow_opa(obj, 127, LV_PART_MAIN | LV_STATE_DEFAULT);
        }
        {
            // taFName
            lv_obj_t *obj = lv_textarea_create(parent_obj);
            objects.ta_fname = obj;
            lv_obj_set_pos(obj, 60, 163);
            lv_obj_set_size(obj, 95, 34);
            lv_textarea_set_max_length(obj, 10);
            lv_textarea_set_one_line(obj, true);
            lv_textarea_set_password_mode(obj, false);
            lv_obj_add_flag(obj, LV_OBJ_FLAG_CHECKABLE);
            lv_obj_set_style_border_color(obj, lv_color_hex(0xff000000), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_border_width(obj, 1, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_shadow_width(obj, 10, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_shadow_ofs_x(obj, 5, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_shadow_ofs_y(obj, 5, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_shadow_spread(obj, 2, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_shadow_opa(obj, 127, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_left(obj, 4, LV_PART_MAIN | LV_STATE_CHECKED);
            lv_obj_set_style_pad_right(obj, 4, LV_PART_MAIN | LV_STATE_CHECKED);
        }
        {
            // taFNum
            lv_obj_t *obj = lv_textarea_create(parent_obj);
            objects.ta_fnum = obj;
            lv_obj_set_pos(obj, 20, 163);
            lv_obj_set_size(obj, 35, 34);
            lv_textarea_set_max_length(obj, 3);
            lv_textarea_set_one_line(obj, true);
            lv_textarea_set_password_mode(obj, false);
            lv_obj_set_style_border_color(obj, lv_color_hex(0xff000000), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_border_width(obj, 1, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_shadow_width(obj, 10, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_shadow_ofs_x(obj, 5, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_shadow_ofs_y(obj, 5, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_shadow_spread(obj, 2, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_shadow_opa(obj, 127, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_shadow_color(obj, lv_color_hex(0xff000000), LV_PART_MAIN | LV_STATE_DEFAULT);
        }
        {
            // fOption
            lv_obj_t *obj = lv_checkbox_create(parent_obj);
            objects.f_option = obj;
            lv_obj_set_pos(obj, 180, 170);
            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
            lv_checkbox_set_text(obj, "Momentary");
            lv_obj_set_style_shadow_width(obj, 10, LV_PART_INDICATOR | LV_STATE_DEFAULT);
            lv_obj_set_style_shadow_ofs_x(obj, 5, LV_PART_INDICATOR | LV_STATE_DEFAULT);
            lv_obj_set_style_shadow_ofs_y(obj, 5, LV_PART_INDICATOR | LV_STATE_DEFAULT);
            lv_obj_set_style_shadow_spread(obj, 2, LV_PART_INDICATOR | LV_STATE_DEFAULT);
            lv_obj_set_style_shadow_color(obj, lv_color_hex(0xff000000), LV_PART_INDICATOR | LV_STATE_DEFAULT);
            lv_obj_set_style_shadow_opa(obj, 127, LV_PART_INDICATOR | LV_STATE_DEFAULT);
        }
        {
            // btnS0
            lv_obj_t *obj = lv_btn_create(parent_obj);
            objects.btn_s0 = obj;
            lv_obj_set_pos(obj, 10, 220);
            lv_obj_set_size(obj, 140, 32);
            lv_obj_add_event_cb(obj, event_handler_checked_cb_edit_loco_btn_s0, LV_EVENT_VALUE_CHANGED, (void *)0);
            lv_obj_add_event_cb(obj, event_handler_unchecked_cb_edit_loco_btn_s0, LV_EVENT_VALUE_CHANGED, (void *)0);
            lv_obj_add_flag(obj, LV_OBJ_FLAG_CHECKABLE);
            lv_obj_set_style_border_width(obj, 1, LV_PART_MAIN | LV_STATE_CHECKED);
            lv_obj_set_style_border_color(obj, lv_color_hex(0xff000000), LV_PART_MAIN | LV_STATE_CHECKED);
            lv_obj_set_style_shadow_ofs_x(obj, 5, LV_PART_MAIN | LV_STATE_CHECKED);
            lv_obj_set_style_shadow_ofs_y(obj, 5, LV_PART_MAIN | LV_STATE_CHECKED);
            lv_obj_set_style_shadow_spread(obj, 2, LV_PART_MAIN | LV_STATE_CHECKED);
            lv_obj_set_style_shadow_width(obj, 10, LV_PART_MAIN | LV_STATE_CHECKED);
            lv_obj_set_style_bg_color(obj, lv_color_hex(0xffffff00), LV_PART_MAIN | LV_STATE_CHECKED);
            lv_obj_set_style_text_color(obj, lv_color_hex(0xff000000), LV_PART_MAIN | LV_STATE_CHECKED);
            lv_obj_set_style_shadow_color(obj, lv_color_hex(0xff000000), LV_PART_MAIN | LV_STATE_CHECKED);
            lv_obj_set_style_bg_color(obj, lv_color_hex(0xffc89600), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_border_color(obj, lv_color_hex(0xff000000), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_border_width(obj, 1, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_bg_grad_dir(obj, LV_GRAD_DIR_NONE, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_shadow_ofs_y(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_shadow_width(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_color(obj, lv_color_hex(0xffffffff), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_left(obj, 41, LV_PART_MAIN | LV_STATE_DEFAULT);
            {
                lv_obj_t *parent_obj = obj;
                {
                    // lblS0
                    lv_obj_t *obj = lv_label_create(parent_obj);
                    objects.lbl_s0 = obj;
                    lv_obj_set_pos(obj, 0, 0);
                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                    lv_obj_set_style_align(obj, LV_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_label_set_text(obj, "");
                }
                {
                    // fn_0
                    lv_obj_t *obj = lv_label_create(parent_obj);
                    objects.fn_0 = obj;
                    lv_obj_set_pos(obj, -41, -9);
                    lv_obj_set_size(obj, 32, 32);
                    lv_obj_set_style_pad_top(obj, 8, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_pad_left(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_align(obj, LV_ALIGN_DEFAULT, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_border_color(obj, lv_color_hex(0xff000000), LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_border_width(obj, 1, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_text_color(obj, lv_color_hex(0xff000000), LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_text_align(obj, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_radius(obj, 7, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_bg_color(obj, lv_color_hex(0xffffffff), LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_bg_opa(obj, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_shadow_width(obj, 10, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_shadow_ofs_x(obj, 5, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_shadow_ofs_y(obj, 5, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_shadow_spread(obj, 2, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_shadow_opa(obj, 127, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_label_set_text(obj, "");
                }
            }
        }
        {
            // btnS1
            lv_obj_t *obj = lv_btn_create(parent_obj);
            objects.btn_s1 = obj;
            lv_obj_set_pos(obj, 10, 260);
            lv_obj_set_size(obj, 140, 32);
            lv_obj_add_event_cb(obj, event_handler_checked_cb_edit_loco_btn_s1, LV_EVENT_VALUE_CHANGED, (void *)1);
            lv_obj_add_event_cb(obj, event_handler_unchecked_cb_edit_loco_btn_s1, LV_EVENT_VALUE_CHANGED, (void *)1);
            lv_obj_add_flag(obj, LV_OBJ_FLAG_CHECKABLE);
            lv_obj_set_style_border_width(obj, 1, LV_PART_MAIN | LV_STATE_CHECKED);
            lv_obj_set_style_border_color(obj, lv_color_hex(0xff000000), LV_PART_MAIN | LV_STATE_CHECKED);
            lv_obj_set_style_shadow_ofs_x(obj, 5, LV_PART_MAIN | LV_STATE_CHECKED);
            lv_obj_set_style_shadow_ofs_y(obj, 5, LV_PART_MAIN | LV_STATE_CHECKED);
            lv_obj_set_style_shadow_spread(obj, 2, LV_PART_MAIN | LV_STATE_CHECKED);
            lv_obj_set_style_shadow_width(obj, 10, LV_PART_MAIN | LV_STATE_CHECKED);
            lv_obj_set_style_bg_color(obj, lv_color_hex(0xffffff00), LV_PART_MAIN | LV_STATE_CHECKED);
            lv_obj_set_style_text_color(obj, lv_color_hex(0xff000000), LV_PART_MAIN | LV_STATE_CHECKED);
            lv_obj_set_style_shadow_color(obj, lv_color_hex(0xff000000), LV_PART_MAIN | LV_STATE_CHECKED);
            lv_obj_set_style_bg_color(obj, lv_color_hex(0xffc89600), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_border_color(obj, lv_color_hex(0xff000000), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_border_width(obj, 1, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_bg_grad_dir(obj, LV_GRAD_DIR_NONE, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_shadow_ofs_y(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_shadow_width(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_color(obj, lv_color_hex(0xffffffff), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_left(obj, 41, LV_PART_MAIN | LV_STATE_DEFAULT);
            {
                lv_obj_t *parent_obj = obj;
                {
                    // lblS1
                    lv_obj_t *obj = lv_label_create(parent_obj);
                    objects.lbl_s1 = obj;
                    lv_obj_set_pos(obj, 0, 0);
                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                    lv_obj_set_style_align(obj, LV_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_label_set_text(obj, "");
                }
                {
                    // fn_1
                    lv_obj_t *obj = lv_label_create(parent_obj);
                    objects.fn_1 = obj;
                    lv_obj_set_pos(obj, -41, -9);
                    lv_obj_set_size(obj, 32, 32);
                    lv_obj_set_style_pad_top(obj, 8, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_pad_left(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_align(obj, LV_ALIGN_DEFAULT, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_border_color(obj, lv_color_hex(0xff000000), LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_border_width(obj, 1, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_text_color(obj, lv_color_hex(0xff000000), LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_text_align(obj, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_radius(obj, 7, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_bg_color(obj, lv_color_hex(0xffffffff), LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_bg_opa(obj, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_shadow_width(obj, 10, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_shadow_ofs_x(obj, 5, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_shadow_ofs_y(obj, 5, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_shadow_spread(obj, 2, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_shadow_opa(obj, 127, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_label_set_text(obj, "");
                }
            }
        }
        {
            // btnS2
            lv_obj_t *obj = lv_btn_create(parent_obj);
            objects.btn_s2 = obj;
            lv_obj_set_pos(obj, 10, 300);
            lv_obj_set_size(obj, 140, 32);
            lv_obj_add_event_cb(obj, event_handler_checked_cb_edit_loco_btn_s2, LV_EVENT_VALUE_CHANGED, (void *)2);
            lv_obj_add_event_cb(obj, event_handler_unchecked_cb_edit_loco_btn_s2, LV_EVENT_VALUE_CHANGED, (void *)2);
            lv_obj_add_flag(obj, LV_OBJ_FLAG_CHECKABLE);
            lv_obj_set_style_border_width(obj, 1, LV_PART_MAIN | LV_STATE_CHECKED);
            lv_obj_set_style_border_color(obj, lv_color_hex(0xff000000), LV_PART_MAIN | LV_STATE_CHECKED);
            lv_obj_set_style_shadow_ofs_x(obj, 5, LV_PART_MAIN | LV_STATE_CHECKED);
            lv_obj_set_style_shadow_ofs_y(obj, 5, LV_PART_MAIN | LV_STATE_CHECKED);
            lv_obj_set_style_shadow_spread(obj, 2, LV_PART_MAIN | LV_STATE_CHECKED);
            lv_obj_set_style_shadow_width(obj, 10, LV_PART_MAIN | LV_STATE_CHECKED);
            lv_obj_set_style_bg_color(obj, lv_color_hex(0xffffff00), LV_PART_MAIN | LV_STATE_CHECKED);
            lv_obj_set_style_text_color(obj, lv_color_hex(0xff000000), LV_PART_MAIN | LV_STATE_CHECKED);
            lv_obj_set_style_shadow_color(obj, lv_color_hex(0xff000000), LV_PART_MAIN | LV_STATE_CHECKED);
            lv_obj_set_style_bg_color(obj, lv_color_hex(0xffc89600), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_border_color(obj, lv_color_hex(0xff000000), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_border_width(obj, 1, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_bg_grad_dir(obj, LV_GRAD_DIR_NONE, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_shadow_ofs_y(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_shadow_width(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_color(obj, lv_color_hex(0xffffffff), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_left(obj, 41, LV_PART_MAIN | LV_STATE_DEFAULT);
            {
                lv_obj_t *parent_obj = obj;
                {
                    // lblS2
                    lv_obj_t *obj = lv_label_create(parent_obj);
                    objects.lbl_s2 = obj;
                    lv_obj_set_pos(obj, 0, 0);
                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                    lv_obj_set_style_align(obj, LV_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_label_set_text(obj, "");
                }
                {
                    // fn_2
                    lv_obj_t *obj = lv_label_create(parent_obj);
                    objects.fn_2 = obj;
                    lv_obj_set_pos(obj, -41, -9);
                    lv_obj_set_size(obj, 32, 32);
                    lv_obj_set_style_pad_top(obj, 8, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_pad_left(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_align(obj, LV_ALIGN_DEFAULT, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_border_color(obj, lv_color_hex(0xff000000), LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_border_width(obj, 1, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_text_color(obj, lv_color_hex(0xff000000), LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_text_align(obj, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_radius(obj, 7, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_bg_color(obj, lv_color_hex(0xffffffff), LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_bg_opa(obj, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_shadow_width(obj, 10, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_shadow_ofs_x(obj, 5, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_shadow_ofs_y(obj, 5, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_shadow_spread(obj, 2, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_shadow_opa(obj, 127, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_label_set_text(obj, "");
                }
            }
        }
        {
            // btnS3
            lv_obj_t *obj = lv_btn_create(parent_obj);
            objects.btn_s3 = obj;
            lv_obj_set_pos(obj, 10, 340);
            lv_obj_set_size(obj, 140, 32);
            lv_obj_add_event_cb(obj, event_handler_checked_cb_edit_loco_btn_s3, LV_EVENT_VALUE_CHANGED, (void *)3);
            lv_obj_add_event_cb(obj, event_handler_unchecked_cb_edit_loco_btn_s3, LV_EVENT_VALUE_CHANGED, (void *)3);
            lv_obj_add_flag(obj, LV_OBJ_FLAG_CHECKABLE);
            lv_obj_set_style_border_width(obj, 1, LV_PART_MAIN | LV_STATE_CHECKED);
            lv_obj_set_style_border_color(obj, lv_color_hex(0xff000000), LV_PART_MAIN | LV_STATE_CHECKED);
            lv_obj_set_style_shadow_ofs_x(obj, 5, LV_PART_MAIN | LV_STATE_CHECKED);
            lv_obj_set_style_shadow_ofs_y(obj, 5, LV_PART_MAIN | LV_STATE_CHECKED);
            lv_obj_set_style_shadow_spread(obj, 2, LV_PART_MAIN | LV_STATE_CHECKED);
            lv_obj_set_style_shadow_width(obj, 10, LV_PART_MAIN | LV_STATE_CHECKED);
            lv_obj_set_style_bg_color(obj, lv_color_hex(0xffffff00), LV_PART_MAIN | LV_STATE_CHECKED);
            lv_obj_set_style_text_color(obj, lv_color_hex(0xff000000), LV_PART_MAIN | LV_STATE_CHECKED);
            lv_obj_set_style_shadow_color(obj, lv_color_hex(0xff000000), LV_PART_MAIN | LV_STATE_CHECKED);
            lv_obj_set_style_bg_color(obj, lv_color_hex(0xffc89600), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_border_color(obj, lv_color_hex(0xff000000), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_border_width(obj, 1, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_bg_grad_dir(obj, LV_GRAD_DIR_NONE, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_shadow_ofs_y(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_shadow_width(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_color(obj, lv_color_hex(0xffffffff), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_left(obj, 41, LV_PART_MAIN | LV_STATE_DEFAULT);
            {
                lv_obj_t *parent_obj = obj;
                {
                    // lblS3
                    lv_obj_t *obj = lv_label_create(parent_obj);
                    objects.lbl_s3 = obj;
                    lv_obj_set_pos(obj, 0, 0);
                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                    lv_obj_set_style_align(obj, LV_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_label_set_text(obj, "");
                }
                {
                    // fn_3
                    lv_obj_t *obj = lv_label_create(parent_obj);
                    objects.fn_3 = obj;
                    lv_obj_set_pos(obj, -41, -9);
                    lv_obj_set_size(obj, 32, 32);
                    lv_obj_set_style_pad_top(obj, 8, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_pad_left(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_align(obj, LV_ALIGN_DEFAULT, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_border_color(obj, lv_color_hex(0xff000000), LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_border_width(obj, 1, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_text_color(obj, lv_color_hex(0xff000000), LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_text_align(obj, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_radius(obj, 7, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_bg_color(obj, lv_color_hex(0xffffffff), LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_bg_opa(obj, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_shadow_width(obj, 10, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_shadow_ofs_x(obj, 5, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_shadow_ofs_y(obj, 5, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_shadow_spread(obj, 2, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_shadow_opa(obj, 127, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_label_set_text(obj, "");
                }
            }
        }
        {
            // btnS4
            lv_obj_t *obj = lv_btn_create(parent_obj);
            objects.btn_s4 = obj;
            lv_obj_set_pos(obj, 10, 380);
            lv_obj_set_size(obj, 140, 32);
            lv_obj_add_event_cb(obj, event_handler_checked_cb_edit_loco_btn_s4, LV_EVENT_VALUE_CHANGED, (void *)4);
            lv_obj_add_event_cb(obj, event_handler_unchecked_cb_edit_loco_btn_s4, LV_EVENT_VALUE_CHANGED, (void *)4);
            lv_obj_add_flag(obj, LV_OBJ_FLAG_CHECKABLE);
            lv_obj_set_style_border_width(obj, 1, LV_PART_MAIN | LV_STATE_CHECKED);
            lv_obj_set_style_border_color(obj, lv_color_hex(0xff000000), LV_PART_MAIN | LV_STATE_CHECKED);
            lv_obj_set_style_shadow_ofs_x(obj, 5, LV_PART_MAIN | LV_STATE_CHECKED);
            lv_obj_set_style_shadow_ofs_y(obj, 5, LV_PART_MAIN | LV_STATE_CHECKED);
            lv_obj_set_style_shadow_spread(obj, 2, LV_PART_MAIN | LV_STATE_CHECKED);
            lv_obj_set_style_shadow_width(obj, 10, LV_PART_MAIN | LV_STATE_CHECKED);
            lv_obj_set_style_bg_color(obj, lv_color_hex(0xffffff00), LV_PART_MAIN | LV_STATE_CHECKED);
            lv_obj_set_style_text_color(obj, lv_color_hex(0xff000000), LV_PART_MAIN | LV_STATE_CHECKED);
            lv_obj_set_style_shadow_color(obj, lv_color_hex(0xff000000), LV_PART_MAIN | LV_STATE_CHECKED);
            lv_obj_set_style_bg_color(obj, lv_color_hex(0xffc89600), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_border_color(obj, lv_color_hex(0xff000000), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_border_width(obj, 1, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_bg_grad_dir(obj, LV_GRAD_DIR_NONE, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_shadow_ofs_y(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_shadow_width(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_color(obj, lv_color_hex(0xffffffff), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_left(obj, 41, LV_PART_MAIN | LV_STATE_DEFAULT);
            {
                lv_obj_t *parent_obj = obj;
                {
                    // lbl_s4
                    lv_obj_t *obj = lv_label_create(parent_obj);
                    objects.lbl_s4 = obj;
                    lv_obj_set_pos(obj, 0, 0);
                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                    lv_obj_set_style_align(obj, LV_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_label_set_text(obj, "");
                }
                {
                    // fn_4
                    lv_obj_t *obj = lv_label_create(parent_obj);
                    objects.fn_4 = obj;
                    lv_obj_set_pos(obj, -41, -9);
                    lv_obj_set_size(obj, 32, 32);
                    lv_obj_set_style_pad_top(obj, 8, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_pad_left(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_align(obj, LV_ALIGN_DEFAULT, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_border_color(obj, lv_color_hex(0xff000000), LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_border_width(obj, 1, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_text_color(obj, lv_color_hex(0xff000000), LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_text_align(obj, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_radius(obj, 7, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_bg_color(obj, lv_color_hex(0xffffffff), LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_bg_opa(obj, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_shadow_width(obj, 10, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_shadow_ofs_x(obj, 5, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_shadow_ofs_y(obj, 5, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_shadow_spread(obj, 2, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_shadow_opa(obj, 127, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_label_set_text(obj, "");
                }
            }
        }
        {
            // btnS5
            lv_obj_t *obj = lv_btn_create(parent_obj);
            objects.btn_s5 = obj;
            lv_obj_set_pos(obj, 170, 220);
            lv_obj_set_size(obj, 140, 32);
            lv_obj_add_event_cb(obj, event_handler_checked_cb_edit_loco_btn_s5, LV_EVENT_VALUE_CHANGED, (void *)5);
            lv_obj_add_event_cb(obj, event_handler_unchecked_cb_edit_loco_btn_s5, LV_EVENT_VALUE_CHANGED, (void *)5);
            lv_obj_add_flag(obj, LV_OBJ_FLAG_CHECKABLE);
            lv_obj_set_style_border_width(obj, 1, LV_PART_MAIN | LV_STATE_CHECKED);
            lv_obj_set_style_border_color(obj, lv_color_hex(0xff000000), LV_PART_MAIN | LV_STATE_CHECKED);
            lv_obj_set_style_shadow_ofs_x(obj, 5, LV_PART_MAIN | LV_STATE_CHECKED);
            lv_obj_set_style_shadow_ofs_y(obj, 5, LV_PART_MAIN | LV_STATE_CHECKED);
            lv_obj_set_style_shadow_spread(obj, 2, LV_PART_MAIN | LV_STATE_CHECKED);
            lv_obj_set_style_shadow_width(obj, 10, LV_PART_MAIN | LV_STATE_CHECKED);
            lv_obj_set_style_bg_color(obj, lv_color_hex(0xffffff00), LV_PART_MAIN | LV_STATE_CHECKED);
            lv_obj_set_style_text_color(obj, lv_color_hex(0xff000000), LV_PART_MAIN | LV_STATE_CHECKED);
            lv_obj_set_style_shadow_color(obj, lv_color_hex(0xff000000), LV_PART_MAIN | LV_STATE_CHECKED);
            lv_obj_set_style_bg_color(obj, lv_color_hex(0xffc89600), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_border_color(obj, lv_color_hex(0xff000000), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_border_width(obj, 1, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_bg_grad_dir(obj, LV_GRAD_DIR_NONE, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_shadow_ofs_y(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_shadow_width(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_color(obj, lv_color_hex(0xffffffff), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_left(obj, 41, LV_PART_MAIN | LV_STATE_DEFAULT);
            {
                lv_obj_t *parent_obj = obj;
                {
                    // lblS5
                    lv_obj_t *obj = lv_label_create(parent_obj);
                    objects.lbl_s5 = obj;
                    lv_obj_set_pos(obj, 0, 0);
                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                    lv_obj_set_style_align(obj, LV_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_label_set_text(obj, "");
                }
                {
                    // fn_5
                    lv_obj_t *obj = lv_label_create(parent_obj);
                    objects.fn_5 = obj;
                    lv_obj_set_pos(obj, -41, -9);
                    lv_obj_set_size(obj, 32, 32);
                    lv_obj_set_style_pad_top(obj, 8, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_pad_left(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_align(obj, LV_ALIGN_DEFAULT, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_border_color(obj, lv_color_hex(0xff000000), LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_border_width(obj, 1, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_text_color(obj, lv_color_hex(0xff000000), LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_text_align(obj, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_radius(obj, 7, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_bg_color(obj, lv_color_hex(0xffffffff), LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_bg_opa(obj, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_shadow_width(obj, 10, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_shadow_ofs_x(obj, 5, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_shadow_ofs_y(obj, 5, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_shadow_spread(obj, 2, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_shadow_opa(obj, 127, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_label_set_text(obj, "");
                }
            }
        }
        {
            // btnS6
            lv_obj_t *obj = lv_btn_create(parent_obj);
            objects.btn_s6 = obj;
            lv_obj_set_pos(obj, 170, 260);
            lv_obj_set_size(obj, 140, 32);
            lv_obj_add_event_cb(obj, event_handler_checked_cb_edit_loco_btn_s6, LV_EVENT_VALUE_CHANGED, (void *)6);
            lv_obj_add_event_cb(obj, event_handler_unchecked_cb_edit_loco_btn_s6, LV_EVENT_VALUE_CHANGED, (void *)6);
            lv_obj_add_flag(obj, LV_OBJ_FLAG_CHECKABLE);
            lv_obj_set_style_border_width(obj, 1, LV_PART_MAIN | LV_STATE_CHECKED);
            lv_obj_set_style_border_color(obj, lv_color_hex(0xff000000), LV_PART_MAIN | LV_STATE_CHECKED);
            lv_obj_set_style_shadow_ofs_x(obj, 5, LV_PART_MAIN | LV_STATE_CHECKED);
            lv_obj_set_style_shadow_ofs_y(obj, 5, LV_PART_MAIN | LV_STATE_CHECKED);
            lv_obj_set_style_shadow_spread(obj, 2, LV_PART_MAIN | LV_STATE_CHECKED);
            lv_obj_set_style_shadow_width(obj, 10, LV_PART_MAIN | LV_STATE_CHECKED);
            lv_obj_set_style_bg_color(obj, lv_color_hex(0xffffff00), LV_PART_MAIN | LV_STATE_CHECKED);
            lv_obj_set_style_text_color(obj, lv_color_hex(0xff000000), LV_PART_MAIN | LV_STATE_CHECKED);
            lv_obj_set_style_shadow_color(obj, lv_color_hex(0xff000000), LV_PART_MAIN | LV_STATE_CHECKED);
            lv_obj_set_style_bg_color(obj, lv_color_hex(0xffc89600), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_border_color(obj, lv_color_hex(0xff000000), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_border_width(obj, 1, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_bg_grad_dir(obj, LV_GRAD_DIR_NONE, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_shadow_ofs_y(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_shadow_width(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_color(obj, lv_color_hex(0xffffffff), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_left(obj, 41, LV_PART_MAIN | LV_STATE_DEFAULT);
            {
                lv_obj_t *parent_obj = obj;
                {
                    // lblS6
                    lv_obj_t *obj = lv_label_create(parent_obj);
                    objects.lbl_s6 = obj;
                    lv_obj_set_pos(obj, 0, 0);
                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                    lv_obj_set_style_align(obj, LV_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_label_set_text(obj, "");
                }
                {
                    // fn_6
                    lv_obj_t *obj = lv_label_create(parent_obj);
                    objects.fn_6 = obj;
                    lv_obj_set_pos(obj, -41, -9);
                    lv_obj_set_size(obj, 32, 32);
                    lv_obj_set_style_pad_top(obj, 8, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_pad_left(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_align(obj, LV_ALIGN_DEFAULT, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_border_color(obj, lv_color_hex(0xff000000), LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_border_width(obj, 1, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_text_color(obj, lv_color_hex(0xff000000), LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_text_align(obj, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_radius(obj, 7, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_bg_color(obj, lv_color_hex(0xffffffff), LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_bg_opa(obj, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_shadow_width(obj, 10, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_shadow_ofs_x(obj, 5, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_shadow_ofs_y(obj, 5, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_shadow_spread(obj, 2, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_shadow_opa(obj, 127, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_label_set_text(obj, "");
                }
            }
        }
        {
            // btnS7
            lv_obj_t *obj = lv_btn_create(parent_obj);
            objects.btn_s7 = obj;
            lv_obj_set_pos(obj, 170, 301);
            lv_obj_set_size(obj, 140, 32);
            lv_obj_add_event_cb(obj, event_handler_checked_cb_edit_loco_btn_s7, LV_EVENT_VALUE_CHANGED, (void *)7);
            lv_obj_add_event_cb(obj, event_handler_unchecked_cb_edit_loco_btn_s7, LV_EVENT_VALUE_CHANGED, (void *)7);
            lv_obj_add_flag(obj, LV_OBJ_FLAG_CHECKABLE);
            lv_obj_set_style_border_width(obj, 1, LV_PART_MAIN | LV_STATE_CHECKED);
            lv_obj_set_style_border_color(obj, lv_color_hex(0xff000000), LV_PART_MAIN | LV_STATE_CHECKED);
            lv_obj_set_style_shadow_ofs_x(obj, 5, LV_PART_MAIN | LV_STATE_CHECKED);
            lv_obj_set_style_shadow_ofs_y(obj, 5, LV_PART_MAIN | LV_STATE_CHECKED);
            lv_obj_set_style_shadow_spread(obj, 2, LV_PART_MAIN | LV_STATE_CHECKED);
            lv_obj_set_style_shadow_width(obj, 10, LV_PART_MAIN | LV_STATE_CHECKED);
            lv_obj_set_style_bg_color(obj, lv_color_hex(0xffffff00), LV_PART_MAIN | LV_STATE_CHECKED);
            lv_obj_set_style_text_color(obj, lv_color_hex(0xff000000), LV_PART_MAIN | LV_STATE_CHECKED);
            lv_obj_set_style_shadow_color(obj, lv_color_hex(0xff000000), LV_PART_MAIN | LV_STATE_CHECKED);
            lv_obj_set_style_bg_color(obj, lv_color_hex(0xffc89600), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_border_color(obj, lv_color_hex(0xff000000), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_border_width(obj, 1, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_bg_grad_dir(obj, LV_GRAD_DIR_NONE, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_shadow_ofs_y(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_shadow_width(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_color(obj, lv_color_hex(0xffffffff), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_left(obj, 41, LV_PART_MAIN | LV_STATE_DEFAULT);
            {
                lv_obj_t *parent_obj = obj;
                {
                    // lblS7
                    lv_obj_t *obj = lv_label_create(parent_obj);
                    objects.lbl_s7 = obj;
                    lv_obj_set_pos(obj, 0, 0);
                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                    lv_obj_set_style_align(obj, LV_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_label_set_text(obj, "");
                }
                {
                    // fn_7
                    lv_obj_t *obj = lv_label_create(parent_obj);
                    objects.fn_7 = obj;
                    lv_obj_set_pos(obj, -41, -9);
                    lv_obj_set_size(obj, 32, 32);
                    lv_obj_set_style_pad_top(obj, 8, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_pad_left(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_align(obj, LV_ALIGN_DEFAULT, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_border_color(obj, lv_color_hex(0xff000000), LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_border_width(obj, 1, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_text_color(obj, lv_color_hex(0xff000000), LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_text_align(obj, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_radius(obj, 7, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_bg_color(obj, lv_color_hex(0xffffffff), LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_bg_opa(obj, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_shadow_width(obj, 10, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_shadow_ofs_x(obj, 5, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_shadow_ofs_y(obj, 5, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_shadow_spread(obj, 2, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_shadow_opa(obj, 127, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_label_set_text(obj, "");
                }
            }
        }
        {
            // btnS8
            lv_obj_t *obj = lv_btn_create(parent_obj);
            objects.btn_s8 = obj;
            lv_obj_set_pos(obj, 170, 341);
            lv_obj_set_size(obj, 140, 32);
            lv_obj_add_event_cb(obj, event_handler_checked_cb_edit_loco_btn_s8, LV_EVENT_VALUE_CHANGED, (void *)8);
            lv_obj_add_event_cb(obj, event_handler_unchecked_cb_edit_loco_btn_s8, LV_EVENT_VALUE_CHANGED, (void *)8);
            lv_obj_add_flag(obj, LV_OBJ_FLAG_CHECKABLE);
            lv_obj_set_style_border_width(obj, 1, LV_PART_MAIN | LV_STATE_CHECKED);
            lv_obj_set_style_border_color(obj, lv_color_hex(0xff000000), LV_PART_MAIN | LV_STATE_CHECKED);
            lv_obj_set_style_shadow_ofs_x(obj, 5, LV_PART_MAIN | LV_STATE_CHECKED);
            lv_obj_set_style_shadow_ofs_y(obj, 5, LV_PART_MAIN | LV_STATE_CHECKED);
            lv_obj_set_style_shadow_spread(obj, 2, LV_PART_MAIN | LV_STATE_CHECKED);
            lv_obj_set_style_shadow_width(obj, 10, LV_PART_MAIN | LV_STATE_CHECKED);
            lv_obj_set_style_bg_color(obj, lv_color_hex(0xffffff00), LV_PART_MAIN | LV_STATE_CHECKED);
            lv_obj_set_style_text_color(obj, lv_color_hex(0xff000000), LV_PART_MAIN | LV_STATE_CHECKED);
            lv_obj_set_style_shadow_color(obj, lv_color_hex(0xff000000), LV_PART_MAIN | LV_STATE_CHECKED);
            lv_obj_set_style_bg_color(obj, lv_color_hex(0xffc89600), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_border_color(obj, lv_color_hex(0xff000000), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_border_width(obj, 1, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_bg_grad_dir(obj, LV_GRAD_DIR_NONE, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_shadow_ofs_y(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_shadow_width(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_color(obj, lv_color_hex(0xffffffff), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_left(obj, 41, LV_PART_MAIN | LV_STATE_DEFAULT);
            {
                lv_obj_t *parent_obj = obj;
                {
                    // lblS8
                    lv_obj_t *obj = lv_label_create(parent_obj);
                    objects.lbl_s8 = obj;
                    lv_obj_set_pos(obj, 0, 0);
                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                    lv_obj_set_style_align(obj, LV_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_label_set_text(obj, "");
                }
                {
                    // fn_8
                    lv_obj_t *obj = lv_label_create(parent_obj);
                    objects.fn_8 = obj;
                    lv_obj_set_pos(obj, -41, -9);
                    lv_obj_set_size(obj, 32, 32);
                    lv_obj_set_style_pad_top(obj, 8, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_pad_left(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_align(obj, LV_ALIGN_DEFAULT, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_border_color(obj, lv_color_hex(0xff000000), LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_border_width(obj, 1, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_text_color(obj, lv_color_hex(0xff000000), LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_text_align(obj, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_radius(obj, 7, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_bg_color(obj, lv_color_hex(0xffffffff), LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_bg_opa(obj, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_shadow_width(obj, 10, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_shadow_ofs_x(obj, 5, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_shadow_ofs_y(obj, 5, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_shadow_spread(obj, 2, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_shadow_opa(obj, 127, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_label_set_text(obj, "");
                }
            }
        }
        {
            // btnS9
            lv_obj_t *obj = lv_btn_create(parent_obj);
            objects.btn_s9 = obj;
            lv_obj_set_pos(obj, 170, 381);
            lv_obj_set_size(obj, 140, 32);
            lv_obj_add_event_cb(obj, event_handler_checked_cb_edit_loco_btn_s9, LV_EVENT_VALUE_CHANGED, (void *)9);
            lv_obj_add_event_cb(obj, event_handler_unchecked_cb_edit_loco_btn_s9, LV_EVENT_VALUE_CHANGED, (void *)9);
            lv_obj_add_flag(obj, LV_OBJ_FLAG_CHECKABLE);
            lv_obj_set_style_border_width(obj, 1, LV_PART_MAIN | LV_STATE_CHECKED);
            lv_obj_set_style_border_color(obj, lv_color_hex(0xff000000), LV_PART_MAIN | LV_STATE_CHECKED);
            lv_obj_set_style_shadow_ofs_x(obj, 5, LV_PART_MAIN | LV_STATE_CHECKED);
            lv_obj_set_style_shadow_ofs_y(obj, 5, LV_PART_MAIN | LV_STATE_CHECKED);
            lv_obj_set_style_shadow_spread(obj, 2, LV_PART_MAIN | LV_STATE_CHECKED);
            lv_obj_set_style_shadow_width(obj, 10, LV_PART_MAIN | LV_STATE_CHECKED);
            lv_obj_set_style_bg_color(obj, lv_color_hex(0xffffff00), LV_PART_MAIN | LV_STATE_CHECKED);
            lv_obj_set_style_text_color(obj, lv_color_hex(0xff000000), LV_PART_MAIN | LV_STATE_CHECKED);
            lv_obj_set_style_shadow_color(obj, lv_color_hex(0xff000000), LV_PART_MAIN | LV_STATE_CHECKED);
            lv_obj_set_style_bg_color(obj, lv_color_hex(0xffc89600), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_border_color(obj, lv_color_hex(0xff000000), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_border_width(obj, 1, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_bg_grad_dir(obj, LV_GRAD_DIR_NONE, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_shadow_ofs_y(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_shadow_width(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_color(obj, lv_color_hex(0xffffffff), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_left(obj, 41, LV_PART_MAIN | LV_STATE_DEFAULT);
            {
                lv_obj_t *parent_obj = obj;
                {
                    // lblS9
                    lv_obj_t *obj = lv_label_create(parent_obj);
                    objects.lbl_s9 = obj;
                    lv_obj_set_pos(obj, 0, 0);
                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                    lv_obj_set_style_align(obj, LV_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_label_set_text(obj, "");
                }
                {
                    // fn_9
                    lv_obj_t *obj = lv_label_create(parent_obj);
                    objects.fn_9 = obj;
                    lv_obj_set_pos(obj, -41, -9);
                    lv_obj_set_size(obj, 32, 32);
                    lv_obj_set_style_pad_top(obj, 8, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_pad_left(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_align(obj, LV_ALIGN_DEFAULT, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_border_color(obj, lv_color_hex(0xff000000), LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_border_width(obj, 1, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_text_color(obj, lv_color_hex(0xff000000), LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_text_align(obj, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_radius(obj, 7, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_bg_color(obj, lv_color_hex(0xffffffff), LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_bg_opa(obj, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_shadow_width(obj, 10, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_shadow_ofs_x(obj, 5, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_shadow_ofs_y(obj, 5, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_shadow_spread(obj, 2, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_shadow_opa(obj, 127, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_label_set_text(obj, "");
                }
            }
        }
        {
            // nKbdEditLoco
            lv_obj_t *obj = lv_keyboard_create(parent_obj);
            objects.n_kbd_edit_loco = obj;
            lv_obj_set_pos(obj, 1, 280);
            lv_obj_set_size(obj, 319, 196);
            lv_keyboard_set_mode(obj, LV_KEYBOARD_MODE_NUMBER);
            lv_obj_add_flag(obj, LV_OBJ_FLAG_HIDDEN);
            lv_obj_set_style_align(obj, LV_ALIGN_DEFAULT, LV_PART_MAIN | LV_STATE_DEFAULT);
        }
        {
            // aKbdEditLoco
            lv_obj_t *obj = lv_keyboard_create(parent_obj);
            objects.a_kbd_edit_loco = obj;
            lv_obj_set_pos(obj, 1, 280);
            lv_obj_set_size(obj, 316, 196);
            lv_obj_add_flag(obj, LV_OBJ_FLAG_HIDDEN);
            lv_obj_set_style_align(obj, LV_ALIGN_DEFAULT, LV_PART_MAIN | LV_STATE_DEFAULT);
        }
    }
    
    tick_screen_edit_loco();
}

void tick_screen_edit_loco() {
}

void create_screen_program() {
    lv_obj_t *obj = lv_obj_create(0);
    objects.program = obj;
    lv_obj_set_pos(obj, 0, 0);
    lv_obj_set_size(obj, 320, 480);
    lv_obj_set_style_bg_color(obj, lv_color_hex(0xffc89600), LV_PART_MAIN | LV_STATE_DEFAULT);
    {
        lv_obj_t *parent_obj = obj;
        {
            // CreditsButton_5
            lv_obj_t *obj = lv_btn_create(parent_obj);
            objects.credits_button_5 = obj;
            lv_obj_set_pos(obj, 4, 426);
            lv_obj_set_size(obj, 85, 50);
            lv_obj_add_event_cb(obj, action_program_button, LV_EVENT_RELEASED, (void *)30);
            lv_obj_clear_flag(obj, LV_OBJ_FLAG_CLICK_FOCUSABLE|LV_OBJ_FLAG_GESTURE_BUBBLE|LV_OBJ_FLAG_PRESS_LOCK|LV_OBJ_FLAG_SCROLL_CHAIN_HOR|LV_OBJ_FLAG_SCROLL_CHAIN_VER|LV_OBJ_FLAG_SCROLL_ELASTIC|LV_OBJ_FLAG_SCROLL_MOMENTUM|LV_OBJ_FLAG_SNAPPABLE);
            lv_obj_set_style_bg_color(obj, lv_color_hex(0xffffffff), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_bg_grad_dir(obj, LV_GRAD_DIR_VER, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_bg_grad_color(obj, lv_color_hex(0xff000000), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_outline_width(obj, 1, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_font(obj, &lv_font_montserrat_24, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_shadow_width(obj, 10, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_shadow_ofs_x(obj, 5, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_shadow_ofs_y(obj, 5, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_shadow_spread(obj, 2, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_shadow_opa(obj, 128, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_shadow_color(obj, lv_color_hex(0xff000000), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_bg_color(obj, lv_color_hex(0xff000000), LV_PART_MAIN | LV_STATE_PRESSED);
            lv_obj_set_style_bg_grad_dir(obj, LV_GRAD_DIR_VER, LV_PART_MAIN | LV_STATE_PRESSED);
            lv_obj_set_style_bg_grad_color(obj, lv_color_hex(0xfffff200), LV_PART_MAIN | LV_STATE_PRESSED);
            lv_obj_set_style_text_color(obj, lv_color_hex(0xff000000), LV_PART_MAIN | LV_STATE_PRESSED);
            lv_obj_set_style_transform_width(obj, -2, LV_PART_MAIN | LV_STATE_PRESSED);
            lv_obj_set_style_transform_height(obj, -2, LV_PART_MAIN | LV_STATE_PRESSED);
            lv_obj_set_style_shadow_width(obj, 0, LV_PART_MAIN | LV_STATE_PRESSED);
            lv_obj_set_style_shadow_ofs_x(obj, 0, LV_PART_MAIN | LV_STATE_PRESSED);
            lv_obj_set_style_shadow_ofs_y(obj, 0, LV_PART_MAIN | LV_STATE_PRESSED);
            lv_obj_set_style_shadow_spread(obj, 2, LV_PART_MAIN | LV_STATE_PRESSED);
            lv_obj_set_style_text_font(obj, &lv_font_montserrat_20, LV_PART_MAIN | LV_STATE_CHECKED);
            {
                lv_obj_t *parent_obj = obj;
                {
                    lv_obj_t *obj = lv_label_create(parent_obj);
                    objects.obj28 = obj;
                    lv_obj_set_pos(obj, 0, 0);
                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                    lv_obj_clear_flag(obj, LV_OBJ_FLAG_CLICK_FOCUSABLE|LV_OBJ_FLAG_GESTURE_BUBBLE|LV_OBJ_FLAG_PRESS_LOCK|LV_OBJ_FLAG_SCROLLABLE|LV_OBJ_FLAG_SCROLL_CHAIN_HOR|LV_OBJ_FLAG_SCROLL_CHAIN_VER|LV_OBJ_FLAG_SCROLL_ELASTIC|LV_OBJ_FLAG_SCROLL_MOMENTUM|LV_OBJ_FLAG_SNAPPABLE);
                    lv_obj_set_style_align(obj, LV_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_bg_color(obj, lv_color_hex(0xffffffff), LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_bg_grad_dir(obj, LV_GRAD_DIR_VER, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_bg_grad_color(obj, lv_color_hex(0xff000000), LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_bg_grad_stop(obj, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_text_font(obj, &lv_font_montserrat_20, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_text_font(obj, &lv_font_montserrat_20, LV_PART_MAIN | LV_STATE_CHECKED);
                    lv_label_set_text(obj, "Cancel");
                }
            }
        }
        {
            // InfoButton_5
            lv_obj_t *obj = lv_btn_create(parent_obj);
            objects.info_button_5 = obj;
            lv_obj_set_pos(obj, 232, 426);
            lv_obj_set_size(obj, 85, 50);
            lv_obj_add_event_cb(obj, action_program_button, LV_EVENT_RELEASED, (void *)32);
            lv_obj_clear_flag(obj, LV_OBJ_FLAG_CLICK_FOCUSABLE|LV_OBJ_FLAG_GESTURE_BUBBLE|LV_OBJ_FLAG_PRESS_LOCK|LV_OBJ_FLAG_SCROLL_CHAIN_HOR|LV_OBJ_FLAG_SCROLL_CHAIN_VER|LV_OBJ_FLAG_SCROLL_ELASTIC|LV_OBJ_FLAG_SCROLL_MOMENTUM|LV_OBJ_FLAG_SNAPPABLE);
            lv_obj_set_style_bg_color(obj, lv_color_hex(0xffffffff), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_bg_grad_dir(obj, LV_GRAD_DIR_VER, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_bg_grad_color(obj, lv_color_hex(0xff000000), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_outline_width(obj, 1, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_font(obj, &lv_font_montserrat_24, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_shadow_width(obj, 10, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_shadow_ofs_x(obj, 5, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_shadow_ofs_y(obj, 5, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_shadow_spread(obj, 2, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_shadow_opa(obj, 128, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_shadow_color(obj, lv_color_hex(0xff000000), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_bg_color(obj, lv_color_hex(0xff000000), LV_PART_MAIN | LV_STATE_PRESSED);
            lv_obj_set_style_bg_grad_dir(obj, LV_GRAD_DIR_VER, LV_PART_MAIN | LV_STATE_PRESSED);
            lv_obj_set_style_bg_grad_color(obj, lv_color_hex(0xfffff200), LV_PART_MAIN | LV_STATE_PRESSED);
            lv_obj_set_style_text_color(obj, lv_color_hex(0xff000000), LV_PART_MAIN | LV_STATE_PRESSED);
            lv_obj_set_style_transform_width(obj, -2, LV_PART_MAIN | LV_STATE_PRESSED);
            lv_obj_set_style_transform_height(obj, -2, LV_PART_MAIN | LV_STATE_PRESSED);
            lv_obj_set_style_shadow_width(obj, 0, LV_PART_MAIN | LV_STATE_PRESSED);
            lv_obj_set_style_shadow_ofs_x(obj, 0, LV_PART_MAIN | LV_STATE_PRESSED);
            lv_obj_set_style_shadow_ofs_y(obj, 0, LV_PART_MAIN | LV_STATE_PRESSED);
            lv_obj_set_style_shadow_spread(obj, 2, LV_PART_MAIN | LV_STATE_PRESSED);
            lv_obj_set_style_text_font(obj, &lv_font_montserrat_20, LV_PART_MAIN | LV_STATE_CHECKED);
            {
                lv_obj_t *parent_obj = obj;
                {
                    lv_obj_t *obj = lv_label_create(parent_obj);
                    objects.obj29 = obj;
                    lv_obj_set_pos(obj, 0, 0);
                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                    lv_obj_clear_flag(obj, LV_OBJ_FLAG_CLICK_FOCUSABLE|LV_OBJ_FLAG_GESTURE_BUBBLE|LV_OBJ_FLAG_PRESS_LOCK|LV_OBJ_FLAG_SCROLLABLE|LV_OBJ_FLAG_SCROLL_CHAIN_HOR|LV_OBJ_FLAG_SCROLL_CHAIN_VER|LV_OBJ_FLAG_SCROLL_ELASTIC|LV_OBJ_FLAG_SCROLL_MOMENTUM|LV_OBJ_FLAG_SNAPPABLE);
                    lv_obj_set_style_align(obj, LV_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_bg_color(obj, lv_color_hex(0xffffffff), LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_bg_grad_dir(obj, LV_GRAD_DIR_VER, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_bg_grad_color(obj, lv_color_hex(0xff000000), LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_bg_grad_stop(obj, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_text_font(obj, &lv_font_montserrat_20, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_text_font(obj, &lv_font_montserrat_20, LV_PART_MAIN | LV_STATE_CHECKED);
                    lv_label_set_text(obj, "Done");
                }
            }
        }
        {
            lv_obj_t *obj = lv_label_create(parent_obj);
            objects.obj30 = obj;
            lv_obj_set_pos(obj, 94, 36);
            lv_obj_set_size(obj, 140, 20);
            lv_obj_clear_flag(obj, LV_OBJ_FLAG_CLICK_FOCUSABLE|LV_OBJ_FLAG_GESTURE_BUBBLE|LV_OBJ_FLAG_PRESS_LOCK|LV_OBJ_FLAG_SCROLLABLE|LV_OBJ_FLAG_SCROLL_CHAIN_HOR|LV_OBJ_FLAG_SCROLL_CHAIN_VER|LV_OBJ_FLAG_SCROLL_ELASTIC|LV_OBJ_FLAG_SCROLL_MOMENTUM|LV_OBJ_FLAG_SNAPPABLE);
            lv_obj_set_style_text_align(obj, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_font(obj, &lv_font_montserrat_18, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_color(obj, lv_color_hex(0xffffffff), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_label_set_text(obj, "Program");
        }
        {
            // trackMtx
            lv_obj_t *obj = lv_btnmatrix_create(parent_obj);
            objects.track_mtx = obj;
            lv_obj_set_pos(obj, 10, 78);
            lv_obj_set_size(obj, 305, 49);
            static const char *map[3] = {
                "Main",
                "Program",
                NULL,
            };
            static lv_btnmatrix_ctrl_t ctrl_map[2] = {
                1 | LV_BTNMATRIX_CTRL_CHECKABLE,
                1 | LV_BTNMATRIX_CTRL_CHECKABLE,
            };
            lv_btnmatrix_set_map(obj, map);
            lv_btnmatrix_set_ctrl_map(obj, ctrl_map);
            lv_btnmatrix_set_one_checked(obj, true);
            lv_obj_set_style_pad_top(obj, 2, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_left(obj, 2, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_right(obj, 6, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_bottom(obj, 6, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_column(obj, 110, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_bg_color(obj, lv_color_hex(0xffc89600), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_border_width(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_bg_color(obj, lv_color_hex(0xffffffff), LV_PART_ITEMS | LV_STATE_DEFAULT);
            lv_obj_set_style_bg_grad_dir(obj, LV_GRAD_DIR_VER, LV_PART_ITEMS | LV_STATE_DEFAULT);
            lv_obj_set_style_bg_grad_color(obj, lv_color_hex(0xff000000), LV_PART_ITEMS | LV_STATE_DEFAULT);
            lv_obj_set_style_text_color(obj, lv_color_hex(0xffffffff), LV_PART_ITEMS | LV_STATE_DEFAULT);
            lv_obj_set_style_outline_width(obj, 1, LV_PART_ITEMS | LV_STATE_DEFAULT);
            lv_obj_set_style_shadow_width(obj, 5, LV_PART_ITEMS | LV_STATE_DEFAULT);
            lv_obj_set_style_shadow_ofs_x(obj, 3, LV_PART_ITEMS | LV_STATE_DEFAULT);
            lv_obj_set_style_shadow_ofs_y(obj, 3, LV_PART_ITEMS | LV_STATE_DEFAULT);
            lv_obj_set_style_shadow_spread(obj, 2, LV_PART_ITEMS | LV_STATE_DEFAULT);
            lv_obj_set_style_shadow_color(obj, lv_color_hex(0xff000000), LV_PART_ITEMS | LV_STATE_DEFAULT);
            lv_obj_set_style_shadow_opa(obj, 127, LV_PART_ITEMS | LV_STATE_DEFAULT);
            lv_obj_set_style_text_font(obj, &lv_font_montserrat_16, LV_PART_ITEMS | LV_STATE_DEFAULT);
            lv_obj_set_style_bg_color(obj, lv_color_hex(0xffffff00), LV_PART_ITEMS | LV_STATE_CHECKED);
            lv_obj_set_style_bg_grad_dir(obj, LV_GRAD_DIR_NONE, LV_PART_ITEMS | LV_STATE_CHECKED);
            lv_obj_set_style_shadow_width(obj, 0, LV_PART_ITEMS | LV_STATE_CHECKED);
            lv_obj_set_style_shadow_ofs_x(obj, 0, LV_PART_ITEMS | LV_STATE_CHECKED);
            lv_obj_set_style_shadow_ofs_y(obj, 0, LV_PART_ITEMS | LV_STATE_CHECKED);
            lv_obj_set_style_shadow_spread(obj, 0, LV_PART_ITEMS | LV_STATE_CHECKED);
            lv_obj_set_style_text_color(obj, lv_color_hex(0xff000000), LV_PART_ITEMS | LV_STATE_CHECKED);
        }
        {
            lv_obj_t *obj = lv_label_create(parent_obj);
            objects.obj31 = obj;
            lv_obj_set_pos(obj, 130, 94);
            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
            lv_obj_set_style_text_font(obj, &lv_font_montserrat_16, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_align(obj, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_color(obj, lv_color_hex(0xffffffff), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_color(obj, lv_color_hex(0xffffffff), LV_PART_MAIN | LV_STATE_CHECKED);
            lv_label_set_text(obj, "<Track>");
        }
        {
            // kbdProgram
            lv_obj_t *obj = lv_keyboard_create(parent_obj);
            objects.kbd_program = obj;
            lv_obj_set_pos(obj, 8, 336);
            lv_obj_set_size(obj, 300, 140);
            lv_keyboard_set_mode(obj, LV_KEYBOARD_MODE_NUMBER);
            lv_obj_add_flag(obj, LV_OBJ_FLAG_HIDDEN);
            lv_obj_set_style_align(obj, LV_ALIGN_DEFAULT, LV_PART_MAIN | LV_STATE_DEFAULT);
        }
        {
            // lblPS1
            lv_obj_t *obj = lv_label_create(parent_obj);
            objects.lbl_ps1 = obj;
            lv_obj_set_pos(obj, 8, 336);
            lv_obj_set_size(obj, 306, 20);
            lv_obj_set_style_text_font(obj, &lv_font_montserrat_16, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_label_set_text(obj, "");
        }
        {
            // lblPS2
            lv_obj_t *obj = lv_label_create(parent_obj);
            objects.lbl_ps2 = obj;
            lv_obj_set_pos(obj, 9, 365);
            lv_obj_set_size(obj, 306, 20);
            lv_obj_set_style_text_font(obj, &lv_font_montserrat_16, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_label_set_text(obj, "");
        }
        {
            // btnRead
            lv_obj_t *obj = lv_btn_create(parent_obj);
            objects.btn_read = obj;
            lv_obj_set_pos(obj, 10, 130);
            lv_obj_set_size(obj, 80, 40);
            lv_obj_add_event_cb(obj, event_handler_checked_cb_program_btn_read, LV_EVENT_VALUE_CHANGED, (void *)1);
            lv_obj_add_flag(obj, LV_OBJ_FLAG_CHECKABLE);
            lv_obj_set_style_bg_color(obj, lv_color_hex(0xffffffff), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_bg_grad_dir(obj, LV_GRAD_DIR_VER, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_outline_width(obj, 1, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_shadow_width(obj, 5, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_shadow_ofs_x(obj, 3, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_shadow_ofs_y(obj, 3, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_shadow_spread(obj, 2, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_shadow_color(obj, lv_color_hex(0xff000000), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_font(obj, &lv_font_montserrat_16, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_bg_color(obj, lv_color_hex(0xffffff00), LV_PART_MAIN | LV_STATE_CHECKED);
            lv_obj_set_style_bg_grad_dir(obj, LV_GRAD_DIR_NONE, LV_PART_MAIN | LV_STATE_CHECKED);
            lv_obj_set_style_shadow_width(obj, 0, LV_PART_MAIN | LV_STATE_CHECKED);
            lv_obj_set_style_shadow_ofs_x(obj, 0, LV_PART_MAIN | LV_STATE_CHECKED);
            lv_obj_set_style_shadow_ofs_y(obj, 0, LV_PART_MAIN | LV_STATE_CHECKED);
            lv_obj_set_style_shadow_spread(obj, 0, LV_PART_MAIN | LV_STATE_CHECKED);
            lv_obj_set_style_text_color(obj, lv_color_hex(0xff000000), LV_PART_MAIN | LV_STATE_CHECKED);
            lv_obj_set_style_text_font(obj, &lv_font_montserrat_16, LV_PART_MAIN | LV_STATE_CHECKED);
            lv_obj_set_style_bg_color(obj, lv_color_hex(0xffffff00), LV_PART_MAIN | LV_STATE_PRESSED);
            lv_obj_set_style_bg_grad_dir(obj, LV_GRAD_DIR_NONE, LV_PART_MAIN | LV_STATE_PRESSED);
            lv_obj_set_style_text_color(obj, lv_color_hex(0xff000000), LV_PART_MAIN | LV_STATE_PRESSED);
            {
                lv_obj_t *parent_obj = obj;
                {
                    lv_obj_t *obj = lv_label_create(parent_obj);
                    lv_obj_set_pos(obj, 0, 0);
                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                    lv_obj_set_style_align(obj, LV_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_label_set_text(obj, "Read");
                }
            }
        }
        {
            // btnWrite
            lv_obj_t *obj = lv_btn_create(parent_obj);
            objects.btn_write = obj;
            lv_obj_set_pos(obj, 228, 130);
            lv_obj_set_size(obj, 80, 40);
            lv_obj_add_event_cb(obj, event_handler_checked_cb_program_btn_write, LV_EVENT_VALUE_CHANGED, (void *)2);
            lv_obj_add_flag(obj, LV_OBJ_FLAG_CHECKABLE);
            lv_obj_set_style_bg_color(obj, lv_color_hex(0xffffffff), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_bg_grad_dir(obj, LV_GRAD_DIR_VER, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_outline_width(obj, 1, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_shadow_width(obj, 5, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_shadow_ofs_x(obj, 3, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_shadow_ofs_y(obj, 3, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_shadow_spread(obj, 2, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_shadow_color(obj, lv_color_hex(0xff000000), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_shadow_opa(obj, 127, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_font(obj, &lv_font_montserrat_16, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_bg_color(obj, lv_color_hex(0xffffff00), LV_PART_MAIN | LV_STATE_CHECKED);
            lv_obj_set_style_bg_grad_dir(obj, LV_GRAD_DIR_NONE, LV_PART_MAIN | LV_STATE_CHECKED);
            lv_obj_set_style_shadow_width(obj, 0, LV_PART_MAIN | LV_STATE_CHECKED);
            lv_obj_set_style_shadow_ofs_x(obj, 0, LV_PART_MAIN | LV_STATE_CHECKED);
            lv_obj_set_style_shadow_ofs_y(obj, 0, LV_PART_MAIN | LV_STATE_CHECKED);
            lv_obj_set_style_shadow_spread(obj, 0, LV_PART_MAIN | LV_STATE_CHECKED);
            lv_obj_set_style_text_color(obj, lv_color_hex(0xff000000), LV_PART_MAIN | LV_STATE_CHECKED);
            lv_obj_set_style_text_font(obj, &lv_font_montserrat_16, LV_PART_MAIN | LV_STATE_CHECKED);
            lv_obj_set_style_bg_color(obj, lv_color_hex(0xffffff00), LV_PART_MAIN | LV_STATE_PRESSED);
            lv_obj_set_style_bg_grad_dir(obj, LV_GRAD_DIR_NONE, LV_PART_MAIN | LV_STATE_PRESSED);
            lv_obj_set_style_text_color(obj, lv_color_hex(0xff000000), LV_PART_MAIN | LV_STATE_PRESSED);
            {
                lv_obj_t *parent_obj = obj;
                {
                    lv_obj_t *obj = lv_label_create(parent_obj);
                    lv_obj_set_pos(obj, 0, 0);
                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                    lv_obj_set_style_align(obj, LV_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_label_set_text(obj, "Write");
                }
            }
        }
        {
            lv_obj_t *obj = lv_label_create(parent_obj);
            objects.obj32 = obj;
            lv_obj_set_pos(obj, 21, 304);
            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
            lv_obj_set_style_text_color(obj, lv_color_hex(0xffffffff), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_font(obj, &lv_font_montserrat_16, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_label_set_text(obj, "CV:");
        }
        {
            lv_obj_t *obj = lv_label_create(parent_obj);
            objects.obj33 = obj;
            lv_obj_set_pos(obj, 185, 303);
            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
            lv_obj_set_style_text_color(obj, lv_color_hex(0xffffffff), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_font(obj, &lv_font_montserrat_16, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_label_set_text(obj, "Value:");
        }
        {
            // taCvn
            lv_obj_t *obj = lv_textarea_create(parent_obj);
            objects.ta_cvn = obj;
            lv_obj_set_pos(obj, 56, 300);
            lv_obj_set_size(obj, 50, 26);
            lv_textarea_set_max_length(obj, 3);
            lv_textarea_set_placeholder_text(obj, "CV");
            lv_textarea_set_one_line(obj, true);
            lv_textarea_set_password_mode(obj, false);
            lv_obj_set_style_pad_top(obj, 2, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_bottom(obj, 2, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_font(obj, &lv_font_montserrat_16, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_left(obj, 1, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_align(obj, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_border_color(obj, lv_color_hex(0xff000000), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_border_width(obj, 1, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_border_color(obj, lv_color_hex(0xff000000), LV_PART_MAIN | LV_STATE_CHECKED);
            lv_obj_set_style_border_width(obj, 1, LV_PART_MAIN | LV_STATE_CHECKED);
        }
        {
            // taCvv
            lv_obj_t *obj = lv_textarea_create(parent_obj);
            objects.ta_cvv = obj;
            lv_obj_set_pos(obj, 249, 300);
            lv_obj_set_size(obj, 53, 24);
            lv_textarea_set_max_length(obj, 3);
            lv_textarea_set_placeholder_text(obj, "Value");
            lv_textarea_set_one_line(obj, true);
            lv_textarea_set_password_mode(obj, false);
            lv_obj_set_style_pad_top(obj, 2, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_bottom(obj, 2, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_font(obj, &lv_font_montserrat_16, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_left(obj, 1, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_align(obj, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_border_color(obj, lv_color_hex(0xff000000), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_border_width(obj, 1, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_border_color(obj, lv_color_hex(0xff000000), LV_PART_MAIN | LV_STATE_CHECKED);
            lv_obj_set_style_border_width(obj, 1, LV_PART_MAIN | LV_STATE_CHECKED);
        }
        {
            // cv_mtx
            lv_obj_t *obj = lv_btnmatrix_create(parent_obj);
            objects.cv_mtx = obj;
            lv_obj_set_pos(obj, 10, 180);
            lv_obj_set_size(obj, 304, 104);
            static const char *map[8] = {
                "Min",
                "Mid",
                "Max",
                "\n",
                "Accel",
                "Decel",
                "Other",
                NULL,
            };
            static lv_btnmatrix_ctrl_t ctrl_map[6] = {
                1 | LV_BTNMATRIX_CTRL_CHECKABLE,
                1 | LV_BTNMATRIX_CTRL_CHECKABLE,
                1 | LV_BTNMATRIX_CTRL_CHECKABLE,
                1 | LV_BTNMATRIX_CTRL_CHECKABLE,
                1 | LV_BTNMATRIX_CTRL_CHECKABLE,
                1 | LV_BTNMATRIX_CTRL_CHECKABLE,
            };
            lv_btnmatrix_set_map(obj, map);
            lv_btnmatrix_set_ctrl_map(obj, ctrl_map);
            lv_btnmatrix_set_one_checked(obj, true);
            lv_obj_set_style_pad_top(obj, 1, LV_PART_MAIN | LV_STATE_CHECKED);
            lv_obj_set_style_pad_bottom(obj, 6, LV_PART_MAIN | LV_STATE_CHECKED);
            lv_obj_set_style_pad_left(obj, 0, LV_PART_MAIN | LV_STATE_CHECKED);
            lv_obj_set_style_pad_right(obj, 6, LV_PART_MAIN | LV_STATE_CHECKED);
            lv_obj_set_style_pad_column(obj, 8, LV_PART_MAIN | LV_STATE_CHECKED);
            lv_obj_set_style_pad_row(obj, 2, LV_PART_MAIN | LV_STATE_CHECKED);
            lv_obj_set_style_pad_top(obj, 1, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_bottom(obj, 6, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_left(obj, 1, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_right(obj, 6, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_column(obj, 8, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_row(obj, 12, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_bg_color(obj, lv_color_hex(0xffc89600), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_border_width(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_bg_color(obj, lv_color_hex(0xfff0f0f0), LV_PART_ITEMS | LV_STATE_DEFAULT);
            lv_obj_set_style_bg_grad_dir(obj, LV_GRAD_DIR_VER, LV_PART_ITEMS | LV_STATE_DEFAULT);
            lv_obj_set_style_bg_grad_color(obj, lv_color_hex(0xff000000), LV_PART_ITEMS | LV_STATE_DEFAULT);
            lv_obj_set_style_outline_width(obj, 1, LV_PART_ITEMS | LV_STATE_DEFAULT);
            lv_obj_set_style_outline_color(obj, lv_color_hex(0xff000000), LV_PART_ITEMS | LV_STATE_DEFAULT);
            lv_obj_set_style_shadow_width(obj, 5, LV_PART_ITEMS | LV_STATE_DEFAULT);
            lv_obj_set_style_shadow_ofs_x(obj, 3, LV_PART_ITEMS | LV_STATE_DEFAULT);
            lv_obj_set_style_shadow_ofs_y(obj, 3, LV_PART_ITEMS | LV_STATE_DEFAULT);
            lv_obj_set_style_shadow_spread(obj, 2, LV_PART_ITEMS | LV_STATE_DEFAULT);
            lv_obj_set_style_shadow_color(obj, lv_color_hex(0xff000000), LV_PART_ITEMS | LV_STATE_DEFAULT);
            lv_obj_set_style_text_font(obj, &lv_font_montserrat_16, LV_PART_ITEMS | LV_STATE_DEFAULT);
            lv_obj_set_style_text_color(obj, lv_color_hex(0xfff0f0f0), LV_PART_ITEMS | LV_STATE_DEFAULT);
            lv_obj_set_style_bg_color(obj, lv_color_hex(0xfff0f000), LV_PART_ITEMS | LV_STATE_CHECKED);
            lv_obj_set_style_bg_grad_dir(obj, LV_GRAD_DIR_NONE, LV_PART_ITEMS | LV_STATE_CHECKED);
            lv_obj_set_style_shadow_width(obj, 0, LV_PART_ITEMS | LV_STATE_CHECKED);
            lv_obj_set_style_shadow_ofs_x(obj, 0, LV_PART_ITEMS | LV_STATE_CHECKED);
            lv_obj_set_style_shadow_ofs_y(obj, 0, LV_PART_ITEMS | LV_STATE_CHECKED);
            lv_obj_set_style_shadow_spread(obj, 0, LV_PART_ITEMS | LV_STATE_CHECKED);
            lv_obj_set_style_text_color(obj, lv_color_hex(0xff000000), LV_PART_ITEMS | LV_STATE_CHECKED);
        }
        {
            // taAdr
            lv_obj_t *obj = lv_textarea_create(parent_obj);
            objects.ta_adr = obj;
            lv_obj_set_pos(obj, 123, 138);
            lv_obj_set_size(obj, 76, 24);
            lv_textarea_set_max_length(obj, 4);
            lv_textarea_set_placeholder_text(obj, "Address");
            lv_textarea_set_one_line(obj, true);
            lv_textarea_set_password_mode(obj, false);
            lv_obj_add_flag(obj, LV_OBJ_FLAG_CHECKABLE|LV_OBJ_FLAG_HIDDEN);
            lv_obj_set_style_pad_top(obj, 2, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_bottom(obj, 2, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_font(obj, &lv_font_montserrat_16, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_left(obj, 2, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_border_color(obj, lv_color_hex(0xff000000), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_border_width(obj, 1, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_bg_color(obj, lv_color_hex(0xffffff00), LV_PART_MAIN | LV_STATE_CHECKED);
            lv_obj_set_style_border_color(obj, lv_color_hex(0xff000000), LV_PART_MAIN | LV_STATE_CHECKED);
            lv_obj_set_style_border_width(obj, 1, LV_PART_MAIN | LV_STATE_CHECKED);
            lv_obj_set_style_text_align(obj, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_PRESSED);
        }
    }
    
    tick_screen_program();
}

void tick_screen_program() {
}

void create_screen_wi_fi() {
    lv_obj_t *obj = lv_obj_create(0);
    objects.wi_fi = obj;
    lv_obj_set_pos(obj, 0, 0);
    lv_obj_set_size(obj, 320, 480);
    lv_obj_clear_flag(obj, LV_OBJ_FLAG_PRESS_LOCK|LV_OBJ_FLAG_CLICK_FOCUSABLE|LV_OBJ_FLAG_GESTURE_BUBBLE|LV_OBJ_FLAG_SNAPPABLE|LV_OBJ_FLAG_SCROLLABLE|LV_OBJ_FLAG_SCROLL_ELASTIC|LV_OBJ_FLAG_SCROLL_MOMENTUM|LV_OBJ_FLAG_SCROLL_CHAIN_HOR|LV_OBJ_FLAG_SCROLL_CHAIN_VER);
    lv_obj_set_style_bg_color(obj, lv_color_hex(0xffc89600), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(obj, lv_color_hex(0xffffffff), LV_PART_MAIN | LV_STATE_DEFAULT);
    {
        lv_obj_t *parent_obj = obj;
        {
            lv_obj_t *obj = lv_label_create(parent_obj);
            lv_obj_set_pos(obj, 107, 37);
            lv_obj_set_size(obj, 110, 20);
            lv_obj_clear_flag(obj, LV_OBJ_FLAG_CLICK_FOCUSABLE|LV_OBJ_FLAG_GESTURE_BUBBLE|LV_OBJ_FLAG_PRESS_LOCK|LV_OBJ_FLAG_SCROLLABLE|LV_OBJ_FLAG_SCROLL_CHAIN_HOR|LV_OBJ_FLAG_SCROLL_CHAIN_VER|LV_OBJ_FLAG_SCROLL_ELASTIC|LV_OBJ_FLAG_SCROLL_MOMENTUM|LV_OBJ_FLAG_SNAPPABLE);
            lv_obj_set_style_text_align(obj, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_font(obj, &lv_font_montserrat_16, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_shadow_opa(obj, 64, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_label_set_text(obj, "WiFi");
        }
        {
            // btnWifiSelect
            lv_obj_t *obj = lv_btn_create(parent_obj);
            objects.btn_wifi_select = obj;
            lv_obj_set_pos(obj, 15, 74);
            lv_obj_set_size(obj, 80, 36);
            lv_obj_add_event_cb(obj, action_wifi_button, LV_EVENT_RELEASED, (void *)1);
            lv_obj_clear_flag(obj, LV_OBJ_FLAG_CLICK_FOCUSABLE|LV_OBJ_FLAG_GESTURE_BUBBLE|LV_OBJ_FLAG_PRESS_LOCK|LV_OBJ_FLAG_SCROLL_CHAIN_HOR|LV_OBJ_FLAG_SCROLL_CHAIN_VER|LV_OBJ_FLAG_SCROLL_ELASTIC|LV_OBJ_FLAG_SCROLL_MOMENTUM|LV_OBJ_FLAG_SNAPPABLE);
            lv_obj_set_style_bg_color(obj, lv_color_hex(0xffffffff), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_bg_grad_dir(obj, LV_GRAD_DIR_VER, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_bg_grad_color(obj, lv_color_hex(0xff000000), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_outline_width(obj, 1, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_font(obj, &lv_font_montserrat_24, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_shadow_width(obj, 5, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_shadow_ofs_x(obj, 3, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_shadow_ofs_y(obj, 3, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_shadow_spread(obj, 2, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_shadow_color(obj, lv_color_hex(0xff000000), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_shadow_opa(obj, 127, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_bg_color(obj, lv_color_hex(0xff000000), LV_PART_MAIN | LV_STATE_PRESSED);
            lv_obj_set_style_bg_grad_dir(obj, LV_GRAD_DIR_VER, LV_PART_MAIN | LV_STATE_PRESSED);
            lv_obj_set_style_bg_grad_color(obj, lv_color_hex(0xfffff200), LV_PART_MAIN | LV_STATE_PRESSED);
            lv_obj_set_style_text_color(obj, lv_color_hex(0xff000000), LV_PART_MAIN | LV_STATE_PRESSED);
            {
                lv_obj_t *parent_obj = obj;
                {
                    lv_obj_t *obj = lv_label_create(parent_obj);
                    objects.obj34 = obj;
                    lv_obj_set_pos(obj, 0, 0);
                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                    lv_obj_clear_flag(obj, LV_OBJ_FLAG_CLICK_FOCUSABLE|LV_OBJ_FLAG_GESTURE_BUBBLE|LV_OBJ_FLAG_PRESS_LOCK|LV_OBJ_FLAG_SCROLLABLE|LV_OBJ_FLAG_SCROLL_CHAIN_HOR|LV_OBJ_FLAG_SCROLL_CHAIN_VER|LV_OBJ_FLAG_SCROLL_ELASTIC|LV_OBJ_FLAG_SCROLL_MOMENTUM|LV_OBJ_FLAG_SNAPPABLE);
                    lv_obj_set_style_align(obj, LV_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_bg_color(obj, lv_color_hex(0xffffffff), LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_bg_grad_dir(obj, LV_GRAD_DIR_VER, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_bg_grad_color(obj, lv_color_hex(0xff000000), LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_bg_grad_stop(obj, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_text_font(obj, &lv_font_montserrat_16, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_label_set_text(obj, "Select");
                }
            }
        }
        {
            // btnWifiScan
            lv_obj_t *obj = lv_btn_create(parent_obj);
            objects.btn_wifi_scan = obj;
            lv_obj_set_pos(obj, 230, 74);
            lv_obj_set_size(obj, 80, 36);
            lv_obj_add_event_cb(obj, action_wifi_button, LV_EVENT_RELEASED, (void *)2);
            lv_obj_clear_flag(obj, LV_OBJ_FLAG_CLICK_FOCUSABLE|LV_OBJ_FLAG_GESTURE_BUBBLE|LV_OBJ_FLAG_PRESS_LOCK|LV_OBJ_FLAG_SCROLL_CHAIN_HOR|LV_OBJ_FLAG_SCROLL_CHAIN_VER|LV_OBJ_FLAG_SCROLL_ELASTIC|LV_OBJ_FLAG_SCROLL_MOMENTUM|LV_OBJ_FLAG_SNAPPABLE);
            lv_obj_set_style_bg_color(obj, lv_color_hex(0xffffffff), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_bg_grad_dir(obj, LV_GRAD_DIR_VER, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_bg_grad_color(obj, lv_color_hex(0xff000000), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_outline_width(obj, 1, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_font(obj, &lv_font_montserrat_24, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_shadow_width(obj, 5, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_shadow_ofs_x(obj, 3, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_shadow_ofs_y(obj, 3, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_shadow_spread(obj, 2, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_shadow_color(obj, lv_color_hex(0xff000000), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_shadow_opa(obj, 127, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_bg_color(obj, lv_color_hex(0xff000000), LV_PART_MAIN | LV_STATE_PRESSED);
            lv_obj_set_style_bg_grad_dir(obj, LV_GRAD_DIR_VER, LV_PART_MAIN | LV_STATE_PRESSED);
            lv_obj_set_style_bg_grad_color(obj, lv_color_hex(0xfffff200), LV_PART_MAIN | LV_STATE_PRESSED);
            lv_obj_set_style_text_color(obj, lv_color_hex(0xff000000), LV_PART_MAIN | LV_STATE_PRESSED);
            {
                lv_obj_t *parent_obj = obj;
                {
                    lv_obj_t *obj = lv_label_create(parent_obj);
                    objects.obj35 = obj;
                    lv_obj_set_pos(obj, 0, 0);
                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                    lv_obj_clear_flag(obj, LV_OBJ_FLAG_CLICK_FOCUSABLE|LV_OBJ_FLAG_GESTURE_BUBBLE|LV_OBJ_FLAG_PRESS_LOCK|LV_OBJ_FLAG_SCROLLABLE|LV_OBJ_FLAG_SCROLL_CHAIN_HOR|LV_OBJ_FLAG_SCROLL_CHAIN_VER|LV_OBJ_FLAG_SCROLL_ELASTIC|LV_OBJ_FLAG_SCROLL_MOMENTUM|LV_OBJ_FLAG_SNAPPABLE);
                    lv_obj_set_style_align(obj, LV_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_bg_color(obj, lv_color_hex(0xffffffff), LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_bg_grad_dir(obj, LV_GRAD_DIR_VER, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_bg_grad_color(obj, lv_color_hex(0xff000000), LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_bg_grad_stop(obj, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_text_font(obj, &lv_font_montserrat_16, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_label_set_text(obj, "Scan");
                }
            }
        }
        {
            // ddSsids
            lv_obj_t *obj = lv_dropdown_create(parent_obj);
            objects.dd_ssids = obj;
            lv_obj_set_pos(obj, 15, 125);
            lv_obj_set_size(obj, 295, LV_SIZE_CONTENT);
            lv_dropdown_set_options(obj, "Select from List\n\n\n\n");
            lv_dropdown_set_selected(obj, 0);
            lv_obj_set_style_bg_color(obj, lv_color_hex(0xffffffff), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_color(obj, lv_color_hex(0xff000000), LV_PART_MAIN | LV_STATE_DEFAULT);
        }
        {
            // taSSID
            lv_obj_t *obj = lv_textarea_create(parent_obj);
            objects.ta_ssid = obj;
            lv_obj_set_pos(obj, 15, 170);
            lv_obj_set_size(obj, 295, 36);
            lv_textarea_set_max_length(obj, 128);
            lv_textarea_set_placeholder_text(obj, "SSID");
            lv_textarea_set_one_line(obj, true);
            lv_textarea_set_password_mode(obj, false);
            lv_obj_set_style_bg_color(obj, lv_color_hex(0xffffffff), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_color(obj, lv_color_hex(0xff000000), LV_PART_MAIN | LV_STATE_DEFAULT);
        }
        {
            // taPassword
            lv_obj_t *obj = lv_textarea_create(parent_obj);
            objects.ta_password = obj;
            lv_obj_set_pos(obj, 15, 210);
            lv_obj_set_size(obj, 295, 36);
            lv_textarea_set_max_length(obj, 128);
            lv_textarea_set_placeholder_text(obj, "Password");
            lv_textarea_set_one_line(obj, true);
            lv_textarea_set_password_mode(obj, false);
            lv_obj_set_style_bg_color(obj, lv_color_hex(0xffffffff), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_color(obj, lv_color_hex(0xff000000), LV_PART_MAIN | LV_STATE_DEFAULT);
        }
        {
            // taIpAddress
            lv_obj_t *obj = lv_textarea_create(parent_obj);
            objects.ta_ip_address = obj;
            lv_obj_set_pos(obj, 14, 250);
            lv_obj_set_size(obj, 295, 36);
            lv_textarea_set_max_length(obj, 128);
            lv_textarea_set_placeholder_text(obj, "IP Address");
            lv_textarea_set_one_line(obj, true);
            lv_textarea_set_password_mode(obj, false);
            lv_obj_set_style_bg_color(obj, lv_color_hex(0xffffffff), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_color(obj, lv_color_hex(0xff000000), LV_PART_MAIN | LV_STATE_DEFAULT);
        }
        {
            // taPort
            lv_obj_t *obj = lv_textarea_create(parent_obj);
            objects.ta_port = obj;
            lv_obj_set_pos(obj, 15, 290);
            lv_obj_set_size(obj, 295, 36);
            lv_textarea_set_max_length(obj, 128);
            lv_textarea_set_placeholder_text(obj, "DCC-EX Port");
            lv_textarea_set_one_line(obj, true);
            lv_textarea_set_password_mode(obj, false);
            lv_obj_set_style_bg_color(obj, lv_color_hex(0xffffffff), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_color(obj, lv_color_hex(0xff000000), LV_PART_MAIN | LV_STATE_DEFAULT);
        }
        {
            // btnWifiConnect
            lv_obj_t *obj = lv_btn_create(parent_obj);
            objects.btn_wifi_connect = obj;
            lv_obj_set_pos(obj, 6, 386);
            lv_obj_set_size(obj, 80, 36);
            lv_obj_add_event_cb(obj, action_wifi_button, LV_EVENT_CLICKED, (void *)7);
            lv_obj_clear_flag(obj, LV_OBJ_FLAG_CLICK_FOCUSABLE|LV_OBJ_FLAG_GESTURE_BUBBLE|LV_OBJ_FLAG_PRESS_LOCK|LV_OBJ_FLAG_SCROLL_CHAIN_HOR|LV_OBJ_FLAG_SCROLL_CHAIN_VER|LV_OBJ_FLAG_SCROLL_ELASTIC|LV_OBJ_FLAG_SCROLL_MOMENTUM|LV_OBJ_FLAG_SNAPPABLE);
            lv_obj_set_style_bg_color(obj, lv_color_hex(0xffffffff), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_bg_grad_dir(obj, LV_GRAD_DIR_VER, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_bg_grad_color(obj, lv_color_hex(0xff000000), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_outline_width(obj, 1, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_font(obj, &lv_font_montserrat_24, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_shadow_width(obj, 5, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_shadow_ofs_x(obj, 3, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_shadow_ofs_y(obj, 3, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_shadow_spread(obj, 2, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_shadow_color(obj, lv_color_hex(0xff000000), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_shadow_opa(obj, 127, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_bg_color(obj, lv_color_hex(0xff000000), LV_PART_MAIN | LV_STATE_PRESSED);
            lv_obj_set_style_bg_grad_dir(obj, LV_GRAD_DIR_VER, LV_PART_MAIN | LV_STATE_PRESSED);
            lv_obj_set_style_bg_grad_color(obj, lv_color_hex(0xfffff200), LV_PART_MAIN | LV_STATE_PRESSED);
            lv_obj_set_style_text_color(obj, lv_color_hex(0xff000000), LV_PART_MAIN | LV_STATE_PRESSED);
            {
                lv_obj_t *parent_obj = obj;
                {
                    lv_obj_t *obj = lv_label_create(parent_obj);
                    objects.obj36 = obj;
                    lv_obj_set_pos(obj, 0, 0);
                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                    lv_obj_clear_flag(obj, LV_OBJ_FLAG_CLICK_FOCUSABLE|LV_OBJ_FLAG_GESTURE_BUBBLE|LV_OBJ_FLAG_PRESS_LOCK|LV_OBJ_FLAG_SCROLLABLE|LV_OBJ_FLAG_SCROLL_CHAIN_HOR|LV_OBJ_FLAG_SCROLL_CHAIN_VER|LV_OBJ_FLAG_SCROLL_ELASTIC|LV_OBJ_FLAG_SCROLL_MOMENTUM|LV_OBJ_FLAG_SNAPPABLE);
                    lv_obj_set_style_align(obj, LV_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_bg_color(obj, lv_color_hex(0xffffffff), LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_bg_grad_dir(obj, LV_GRAD_DIR_VER, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_bg_grad_color(obj, lv_color_hex(0xff000000), LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_bg_grad_stop(obj, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_text_font(obj, &lv_font_montserrat_16, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_label_set_text(obj, "Connect");
                }
            }
        }
        {
            // btnWifiSave
            lv_obj_t *obj = lv_btn_create(parent_obj);
            objects.btn_wifi_save = obj;
            lv_obj_set_pos(obj, 121, 385);
            lv_obj_set_size(obj, 80, 36);
            lv_obj_add_event_cb(obj, action_wifi_button, LV_EVENT_RELEASED, (void *)8);
            lv_obj_clear_flag(obj, LV_OBJ_FLAG_CLICK_FOCUSABLE|LV_OBJ_FLAG_GESTURE_BUBBLE|LV_OBJ_FLAG_PRESS_LOCK|LV_OBJ_FLAG_SCROLL_CHAIN_HOR|LV_OBJ_FLAG_SCROLL_CHAIN_VER|LV_OBJ_FLAG_SCROLL_ELASTIC|LV_OBJ_FLAG_SCROLL_MOMENTUM|LV_OBJ_FLAG_SNAPPABLE);
            lv_obj_set_style_bg_color(obj, lv_color_hex(0xffffffff), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_bg_grad_dir(obj, LV_GRAD_DIR_VER, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_bg_grad_color(obj, lv_color_hex(0xff000000), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_outline_width(obj, 1, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_font(obj, &lv_font_montserrat_24, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_shadow_width(obj, 5, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_shadow_ofs_x(obj, 3, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_shadow_ofs_y(obj, 3, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_shadow_spread(obj, 2, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_shadow_color(obj, lv_color_hex(0xff000000), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_shadow_opa(obj, 127, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_bg_color(obj, lv_color_hex(0xff000000), LV_PART_MAIN | LV_STATE_PRESSED);
            lv_obj_set_style_bg_grad_dir(obj, LV_GRAD_DIR_VER, LV_PART_MAIN | LV_STATE_PRESSED);
            lv_obj_set_style_bg_grad_color(obj, lv_color_hex(0xfffff200), LV_PART_MAIN | LV_STATE_PRESSED);
            lv_obj_set_style_text_color(obj, lv_color_hex(0xff000000), LV_PART_MAIN | LV_STATE_PRESSED);
            {
                lv_obj_t *parent_obj = obj;
                {
                    lv_obj_t *obj = lv_label_create(parent_obj);
                    objects.obj37 = obj;
                    lv_obj_set_pos(obj, 0, 0);
                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                    lv_obj_clear_flag(obj, LV_OBJ_FLAG_CLICK_FOCUSABLE|LV_OBJ_FLAG_GESTURE_BUBBLE|LV_OBJ_FLAG_PRESS_LOCK|LV_OBJ_FLAG_SCROLLABLE|LV_OBJ_FLAG_SCROLL_CHAIN_HOR|LV_OBJ_FLAG_SCROLL_CHAIN_VER|LV_OBJ_FLAG_SCROLL_ELASTIC|LV_OBJ_FLAG_SCROLL_MOMENTUM|LV_OBJ_FLAG_SNAPPABLE);
                    lv_obj_set_style_align(obj, LV_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_bg_color(obj, lv_color_hex(0xffffffff), LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_bg_grad_dir(obj, LV_GRAD_DIR_VER, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_bg_grad_color(obj, lv_color_hex(0xff000000), LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_bg_grad_stop(obj, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_text_font(obj, &lv_font_montserrat_16, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_label_set_text(obj, "Save");
                }
            }
        }
        {
            // btnWifiEnable
            lv_obj_t *obj = lv_btn_create(parent_obj);
            objects.btn_wifi_enable = obj;
            lv_obj_set_pos(obj, 236, 385);
            lv_obj_set_size(obj, 80, 36);
            lv_obj_add_event_cb(obj, action_wifi_button, LV_EVENT_RELEASED, (void *)9);
            lv_obj_clear_flag(obj, LV_OBJ_FLAG_CLICK_FOCUSABLE|LV_OBJ_FLAG_GESTURE_BUBBLE|LV_OBJ_FLAG_PRESS_LOCK|LV_OBJ_FLAG_SCROLL_CHAIN_HOR|LV_OBJ_FLAG_SCROLL_CHAIN_VER|LV_OBJ_FLAG_SCROLL_ELASTIC|LV_OBJ_FLAG_SCROLL_MOMENTUM|LV_OBJ_FLAG_SNAPPABLE);
            lv_obj_add_state(obj, LV_STATE_DISABLED);
            lv_obj_set_style_bg_color(obj, lv_color_hex(0xffffffff), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_bg_grad_dir(obj, LV_GRAD_DIR_VER, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_bg_grad_color(obj, lv_color_hex(0xff000000), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_outline_width(obj, 1, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_font(obj, &lv_font_montserrat_24, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_shadow_width(obj, 5, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_shadow_ofs_x(obj, 3, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_shadow_ofs_y(obj, 3, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_shadow_spread(obj, 2, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_shadow_color(obj, lv_color_hex(0xff000000), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_shadow_opa(obj, 127, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_bg_color(obj, lv_color_hex(0xff000000), LV_PART_MAIN | LV_STATE_PRESSED);
            lv_obj_set_style_bg_grad_dir(obj, LV_GRAD_DIR_VER, LV_PART_MAIN | LV_STATE_PRESSED);
            lv_obj_set_style_bg_grad_color(obj, lv_color_hex(0xfffff200), LV_PART_MAIN | LV_STATE_PRESSED);
            lv_obj_set_style_text_color(obj, lv_color_hex(0xff000000), LV_PART_MAIN | LV_STATE_PRESSED);
            {
                lv_obj_t *parent_obj = obj;
                {
                    lv_obj_t *obj = lv_label_create(parent_obj);
                    objects.obj38 = obj;
                    lv_obj_set_pos(obj, 0, 0);
                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                    lv_obj_clear_flag(obj, LV_OBJ_FLAG_CLICK_FOCUSABLE|LV_OBJ_FLAG_GESTURE_BUBBLE|LV_OBJ_FLAG_PRESS_LOCK|LV_OBJ_FLAG_SCROLLABLE|LV_OBJ_FLAG_SCROLL_CHAIN_HOR|LV_OBJ_FLAG_SCROLL_CHAIN_VER|LV_OBJ_FLAG_SCROLL_ELASTIC|LV_OBJ_FLAG_SCROLL_MOMENTUM|LV_OBJ_FLAG_SNAPPABLE);
                    lv_obj_set_style_align(obj, LV_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_bg_color(obj, lv_color_hex(0xffffffff), LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_bg_grad_dir(obj, LV_GRAD_DIR_VER, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_bg_grad_color(obj, lv_color_hex(0xff000000), LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_bg_grad_stop(obj, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_text_font(obj, &lv_font_montserrat_16, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_label_set_text(obj, "Enable");
                }
            }
        }
        {
            // Config_Button9
            lv_obj_t *obj = lv_btn_create(parent_obj);
            objects.config_button9 = obj;
            lv_obj_set_pos(obj, 5, 427);
            lv_obj_set_size(obj, 85, 50);
            lv_obj_add_event_cb(obj, action_wifi_button, LV_EVENT_RELEASED, (void *)30);
            lv_obj_clear_flag(obj, LV_OBJ_FLAG_CLICK_FOCUSABLE|LV_OBJ_FLAG_GESTURE_BUBBLE|LV_OBJ_FLAG_PRESS_LOCK|LV_OBJ_FLAG_SCROLL_CHAIN_HOR|LV_OBJ_FLAG_SCROLL_CHAIN_VER|LV_OBJ_FLAG_SCROLL_ELASTIC|LV_OBJ_FLAG_SCROLL_MOMENTUM|LV_OBJ_FLAG_SNAPPABLE);
            lv_obj_set_style_bg_color(obj, lv_color_hex(0xffffffff), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_bg_grad_dir(obj, LV_GRAD_DIR_VER, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_bg_grad_color(obj, lv_color_hex(0xff000000), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_outline_width(obj, 1, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_font(obj, &lv_font_montserrat_24, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_shadow_width(obj, 5, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_shadow_ofs_x(obj, 3, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_shadow_ofs_y(obj, 3, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_shadow_spread(obj, 2, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_shadow_color(obj, lv_color_hex(0xff000000), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_shadow_opa(obj, 127, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_bg_color(obj, lv_color_hex(0xff000000), LV_PART_MAIN | LV_STATE_PRESSED);
            lv_obj_set_style_bg_grad_dir(obj, LV_GRAD_DIR_VER, LV_PART_MAIN | LV_STATE_PRESSED);
            lv_obj_set_style_bg_grad_color(obj, lv_color_hex(0xfffff200), LV_PART_MAIN | LV_STATE_PRESSED);
            lv_obj_set_style_text_color(obj, lv_color_hex(0xff000000), LV_PART_MAIN | LV_STATE_PRESSED);
            {
                lv_obj_t *parent_obj = obj;
                {
                    lv_obj_t *obj = lv_label_create(parent_obj);
                    objects.obj39 = obj;
                    lv_obj_set_pos(obj, 0, 0);
                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                    lv_obj_clear_flag(obj, LV_OBJ_FLAG_CLICK_FOCUSABLE|LV_OBJ_FLAG_GESTURE_BUBBLE|LV_OBJ_FLAG_PRESS_LOCK|LV_OBJ_FLAG_SCROLLABLE|LV_OBJ_FLAG_SCROLL_CHAIN_HOR|LV_OBJ_FLAG_SCROLL_CHAIN_VER|LV_OBJ_FLAG_SCROLL_ELASTIC|LV_OBJ_FLAG_SCROLL_MOMENTUM|LV_OBJ_FLAG_SNAPPABLE);
                    lv_obj_set_style_align(obj, LV_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_bg_color(obj, lv_color_hex(0xffffffff), LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_bg_grad_dir(obj, LV_GRAD_DIR_VER, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_bg_grad_color(obj, lv_color_hex(0xff000000), LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_bg_grad_stop(obj, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_text_font(obj, &lv_font_montserrat_20, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_label_set_text(obj, "Config");
                }
            }
        }
        {
            // Retry_Button9
            lv_obj_t *obj = lv_btn_create(parent_obj);
            objects.retry_button9 = obj;
            lv_obj_set_pos(obj, 118, 427);
            lv_obj_set_size(obj, 85, 50);
            lv_obj_add_event_cb(obj, action_wifi_button, LV_EVENT_RELEASED, (void *)31);
            lv_obj_clear_flag(obj, LV_OBJ_FLAG_CLICK_FOCUSABLE|LV_OBJ_FLAG_GESTURE_BUBBLE|LV_OBJ_FLAG_PRESS_LOCK|LV_OBJ_FLAG_SCROLL_CHAIN_HOR|LV_OBJ_FLAG_SCROLL_CHAIN_VER|LV_OBJ_FLAG_SCROLL_ELASTIC|LV_OBJ_FLAG_SCROLL_MOMENTUM|LV_OBJ_FLAG_SNAPPABLE);
            lv_obj_set_style_bg_color(obj, lv_color_hex(0xffffffff), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_bg_grad_dir(obj, LV_GRAD_DIR_VER, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_bg_grad_color(obj, lv_color_hex(0xff000000), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_outline_width(obj, 1, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_font(obj, &lv_font_montserrat_24, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_shadow_width(obj, 5, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_shadow_ofs_x(obj, 3, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_shadow_ofs_y(obj, 3, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_shadow_spread(obj, 2, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_shadow_color(obj, lv_color_hex(0xff000000), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_shadow_opa(obj, 127, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_bg_color(obj, lv_color_hex(0xff000000), LV_PART_MAIN | LV_STATE_PRESSED);
            lv_obj_set_style_bg_grad_dir(obj, LV_GRAD_DIR_VER, LV_PART_MAIN | LV_STATE_PRESSED);
            lv_obj_set_style_bg_grad_color(obj, lv_color_hex(0xfffff200), LV_PART_MAIN | LV_STATE_PRESSED);
            lv_obj_set_style_text_color(obj, lv_color_hex(0xff000000), LV_PART_MAIN | LV_STATE_PRESSED);
            {
                lv_obj_t *parent_obj = obj;
                {
                    lv_obj_t *obj = lv_label_create(parent_obj);
                    objects.obj40 = obj;
                    lv_obj_set_pos(obj, 0, 0);
                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                    lv_obj_clear_flag(obj, LV_OBJ_FLAG_CLICK_FOCUSABLE|LV_OBJ_FLAG_GESTURE_BUBBLE|LV_OBJ_FLAG_PRESS_LOCK|LV_OBJ_FLAG_SCROLLABLE|LV_OBJ_FLAG_SCROLL_CHAIN_HOR|LV_OBJ_FLAG_SCROLL_CHAIN_VER|LV_OBJ_FLAG_SCROLL_ELASTIC|LV_OBJ_FLAG_SCROLL_MOMENTUM|LV_OBJ_FLAG_SNAPPABLE);
                    lv_obj_set_style_align(obj, LV_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_bg_color(obj, lv_color_hex(0xffffffff), LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_bg_grad_dir(obj, LV_GRAD_DIR_VER, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_bg_grad_color(obj, lv_color_hex(0xff000000), LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_bg_grad_stop(obj, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_text_font(obj, &lv_font_montserrat_20, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_label_set_text(obj, "Retry");
                }
            }
        }
        {
            // Done_Button9
            lv_obj_t *obj = lv_btn_create(parent_obj);
            objects.done_button9 = obj;
            lv_obj_set_pos(obj, 232, 427);
            lv_obj_set_size(obj, 85, 50);
            lv_obj_add_event_cb(obj, action_wifi_button, LV_EVENT_RELEASED, (void *)32);
            lv_obj_clear_flag(obj, LV_OBJ_FLAG_CLICK_FOCUSABLE|LV_OBJ_FLAG_GESTURE_BUBBLE|LV_OBJ_FLAG_PRESS_LOCK|LV_OBJ_FLAG_SCROLL_CHAIN_HOR|LV_OBJ_FLAG_SCROLL_CHAIN_VER|LV_OBJ_FLAG_SCROLL_ELASTIC|LV_OBJ_FLAG_SCROLL_MOMENTUM|LV_OBJ_FLAG_SNAPPABLE);
            lv_obj_set_style_bg_color(obj, lv_color_hex(0xffffffff), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_bg_grad_dir(obj, LV_GRAD_DIR_VER, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_bg_grad_color(obj, lv_color_hex(0xff000000), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_outline_width(obj, 1, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_font(obj, &lv_font_montserrat_24, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_shadow_width(obj, 5, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_shadow_ofs_x(obj, 3, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_shadow_ofs_y(obj, 3, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_shadow_spread(obj, 2, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_shadow_color(obj, lv_color_hex(0xff000000), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_shadow_opa(obj, 127, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_bg_color(obj, lv_color_hex(0xff000000), LV_PART_MAIN | LV_STATE_PRESSED);
            lv_obj_set_style_bg_grad_dir(obj, LV_GRAD_DIR_VER, LV_PART_MAIN | LV_STATE_PRESSED);
            lv_obj_set_style_bg_grad_color(obj, lv_color_hex(0xfffff200), LV_PART_MAIN | LV_STATE_PRESSED);
            lv_obj_set_style_text_color(obj, lv_color_hex(0xff000000), LV_PART_MAIN | LV_STATE_PRESSED);
            {
                lv_obj_t *parent_obj = obj;
                {
                    lv_obj_t *obj = lv_label_create(parent_obj);
                    objects.obj41 = obj;
                    lv_obj_set_pos(obj, 0, 0);
                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                    lv_obj_clear_flag(obj, LV_OBJ_FLAG_CLICK_FOCUSABLE|LV_OBJ_FLAG_GESTURE_BUBBLE|LV_OBJ_FLAG_PRESS_LOCK|LV_OBJ_FLAG_SCROLLABLE|LV_OBJ_FLAG_SCROLL_CHAIN_HOR|LV_OBJ_FLAG_SCROLL_CHAIN_VER|LV_OBJ_FLAG_SCROLL_ELASTIC|LV_OBJ_FLAG_SCROLL_MOMENTUM|LV_OBJ_FLAG_SNAPPABLE);
                    lv_obj_set_style_align(obj, LV_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_bg_color(obj, lv_color_hex(0xffffffff), LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_bg_grad_dir(obj, LV_GRAD_DIR_VER, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_bg_grad_color(obj, lv_color_hex(0xff000000), LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_bg_grad_stop(obj, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_text_font(obj, &lv_font_montserrat_20, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_label_set_text(obj, "Done");
                }
            }
        }
        {
            // kbAlpha
            lv_obj_t *obj = lv_keyboard_create(parent_obj);
            objects.kb_alpha = obj;
            lv_obj_set_pos(obj, 0, 323);
            lv_obj_set_size(obj, 320, 157);
            lv_obj_add_flag(obj, LV_OBJ_FLAG_HIDDEN);
            lv_obj_set_style_align(obj, LV_ALIGN_DEFAULT, LV_PART_MAIN | LV_STATE_DEFAULT);
        }
        {
            // kbNumeric
            lv_obj_t *obj = lv_keyboard_create(parent_obj);
            objects.kb_numeric = obj;
            lv_obj_set_pos(obj, 1, 323);
            lv_obj_set_size(obj, 319, 157);
            lv_keyboard_set_mode(obj, LV_KEYBOARD_MODE_NUMBER);
            lv_obj_add_flag(obj, LV_OBJ_FLAG_HIDDEN);
            lv_obj_set_style_align(obj, LV_ALIGN_DEFAULT, LV_PART_MAIN | LV_STATE_DEFAULT);
        }
        {
            // lblWifiStatus
            lv_obj_t *obj = lv_label_create(parent_obj);
            objects.lbl_wifi_status = obj;
            lv_obj_set_pos(obj, 15, 335);
            lv_obj_set_size(obj, 290, LV_SIZE_CONTENT);
            lv_label_set_text(obj, "");
        }
        {
            // lblWifiStatus2
            lv_obj_t *obj = lv_label_create(parent_obj);
            objects.lbl_wifi_status2 = obj;
            lv_obj_set_pos(obj, 15, 360);
            lv_obj_set_size(obj, 290, LV_SIZE_CONTENT);
            lv_label_set_text(obj, "");
        }
    }
    lv_keyboard_set_textarea(objects.kb_alpha, objects.ta_password);
    lv_keyboard_set_textarea(objects.kb_numeric, objects.ta_port);
    
    tick_screen_wi_fi();
}

void tick_screen_wi_fi() {
}

void create_screen_scan() {
    lv_obj_t *obj = lv_obj_create(0);
    objects.scan = obj;
    lv_obj_set_pos(obj, 0, 0);
    lv_obj_set_size(obj, 320, 480);
    lv_obj_set_style_bg_color(obj, lv_color_hex(0xffc89600), LV_PART_MAIN | LV_STATE_DEFAULT);
    {
        lv_obj_t *parent_obj = obj;
        {
            // lblScan
            lv_obj_t *obj = lv_label_create(parent_obj);
            objects.lbl_scan = obj;
            lv_obj_set_pos(obj, 94, 37);
            lv_obj_set_size(obj, 140, 20);
            lv_obj_clear_flag(obj, LV_OBJ_FLAG_CLICK_FOCUSABLE|LV_OBJ_FLAG_GESTURE_BUBBLE|LV_OBJ_FLAG_PRESS_LOCK|LV_OBJ_FLAG_SCROLLABLE|LV_OBJ_FLAG_SCROLL_CHAIN_HOR|LV_OBJ_FLAG_SCROLL_CHAIN_VER|LV_OBJ_FLAG_SCROLL_ELASTIC|LV_OBJ_FLAG_SCROLL_MOMENTUM|LV_OBJ_FLAG_SNAPPABLE);
            lv_obj_set_style_text_align(obj, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_font(obj, &lv_font_montserrat_16, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_shadow_opa(obj, 64, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_color(obj, lv_color_hex(0xffffffff), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_label_set_text(obj, "Scan");
        }
        {
            // CancelButton_6
            lv_obj_t *obj = lv_btn_create(parent_obj);
            objects.cancel_button_6 = obj;
            lv_obj_set_pos(obj, 5, 427);
            lv_obj_set_size(obj, 85, 50);
            lv_obj_add_event_cb(obj, action_scan_button, LV_EVENT_RELEASED, (void *)30);
            lv_obj_clear_flag(obj, LV_OBJ_FLAG_CLICK_FOCUSABLE|LV_OBJ_FLAG_GESTURE_BUBBLE|LV_OBJ_FLAG_PRESS_LOCK|LV_OBJ_FLAG_SCROLL_CHAIN_HOR|LV_OBJ_FLAG_SCROLL_CHAIN_VER|LV_OBJ_FLAG_SCROLL_ELASTIC|LV_OBJ_FLAG_SCROLL_MOMENTUM|LV_OBJ_FLAG_SNAPPABLE);
            lv_obj_set_style_bg_color(obj, lv_color_hex(0xffffffff), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_bg_grad_dir(obj, LV_GRAD_DIR_VER, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_bg_grad_color(obj, lv_color_hex(0xff000000), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_outline_width(obj, 1, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_font(obj, &lv_font_montserrat_24, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_shadow_width(obj, 5, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_shadow_ofs_x(obj, 3, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_shadow_ofs_y(obj, 3, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_shadow_spread(obj, 2, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_shadow_color(obj, lv_color_hex(0xff000000), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_shadow_opa(obj, 127, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_bg_color(obj, lv_color_hex(0xff000000), LV_PART_MAIN | LV_STATE_PRESSED);
            lv_obj_set_style_bg_grad_dir(obj, LV_GRAD_DIR_VER, LV_PART_MAIN | LV_STATE_PRESSED);
            lv_obj_set_style_bg_grad_color(obj, lv_color_hex(0xfffff200), LV_PART_MAIN | LV_STATE_PRESSED);
            lv_obj_set_style_text_color(obj, lv_color_hex(0xff000000), LV_PART_MAIN | LV_STATE_PRESSED);
            {
                lv_obj_t *parent_obj = obj;
                {
                    lv_obj_t *obj = lv_label_create(parent_obj);
                    objects.obj42 = obj;
                    lv_obj_set_pos(obj, 0, 0);
                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                    lv_obj_clear_flag(obj, LV_OBJ_FLAG_CLICK_FOCUSABLE|LV_OBJ_FLAG_GESTURE_BUBBLE|LV_OBJ_FLAG_PRESS_LOCK|LV_OBJ_FLAG_SCROLLABLE|LV_OBJ_FLAG_SCROLL_CHAIN_HOR|LV_OBJ_FLAG_SCROLL_CHAIN_VER|LV_OBJ_FLAG_SCROLL_ELASTIC|LV_OBJ_FLAG_SCROLL_MOMENTUM|LV_OBJ_FLAG_SNAPPABLE);
                    lv_obj_set_style_align(obj, LV_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_bg_color(obj, lv_color_hex(0xffffffff), LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_bg_grad_dir(obj, LV_GRAD_DIR_VER, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_bg_grad_color(obj, lv_color_hex(0xff000000), LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_bg_grad_stop(obj, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_text_font(obj, &lv_font_montserrat_20, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_label_set_text(obj, "Cancel");
                }
            }
        }
        {
            // Done_Button_6
            lv_obj_t *obj = lv_btn_create(parent_obj);
            objects.done_button_6 = obj;
            lv_obj_set_pos(obj, 232, 427);
            lv_obj_set_size(obj, 85, 50);
            lv_obj_add_event_cb(obj, action_scan_button, LV_EVENT_RELEASED, (void *)32);
            lv_obj_clear_flag(obj, LV_OBJ_FLAG_CLICK_FOCUSABLE|LV_OBJ_FLAG_GESTURE_BUBBLE|LV_OBJ_FLAG_PRESS_LOCK|LV_OBJ_FLAG_SCROLL_CHAIN_HOR|LV_OBJ_FLAG_SCROLL_CHAIN_VER|LV_OBJ_FLAG_SCROLL_ELASTIC|LV_OBJ_FLAG_SCROLL_MOMENTUM|LV_OBJ_FLAG_SNAPPABLE);
            lv_obj_set_style_bg_color(obj, lv_color_hex(0xffffffff), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_bg_grad_dir(obj, LV_GRAD_DIR_VER, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_bg_grad_color(obj, lv_color_hex(0xff000000), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_outline_width(obj, 1, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_font(obj, &lv_font_montserrat_24, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_shadow_width(obj, 5, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_shadow_ofs_x(obj, 3, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_shadow_ofs_y(obj, 3, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_shadow_spread(obj, 2, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_shadow_color(obj, lv_color_hex(0xff000000), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_shadow_opa(obj, 127, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_bg_color(obj, lv_color_hex(0xff000000), LV_PART_MAIN | LV_STATE_PRESSED);
            lv_obj_set_style_bg_grad_dir(obj, LV_GRAD_DIR_VER, LV_PART_MAIN | LV_STATE_PRESSED);
            lv_obj_set_style_bg_grad_color(obj, lv_color_hex(0xfffff200), LV_PART_MAIN | LV_STATE_PRESSED);
            lv_obj_set_style_text_color(obj, lv_color_hex(0xff000000), LV_PART_MAIN | LV_STATE_PRESSED);
            {
                lv_obj_t *parent_obj = obj;
                {
                    lv_obj_t *obj = lv_label_create(parent_obj);
                    objects.obj43 = obj;
                    lv_obj_set_pos(obj, 0, 0);
                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                    lv_obj_clear_flag(obj, LV_OBJ_FLAG_CLICK_FOCUSABLE|LV_OBJ_FLAG_GESTURE_BUBBLE|LV_OBJ_FLAG_PRESS_LOCK|LV_OBJ_FLAG_SCROLLABLE|LV_OBJ_FLAG_SCROLL_CHAIN_HOR|LV_OBJ_FLAG_SCROLL_CHAIN_VER|LV_OBJ_FLAG_SCROLL_ELASTIC|LV_OBJ_FLAG_SCROLL_MOMENTUM|LV_OBJ_FLAG_SNAPPABLE);
                    lv_obj_set_style_align(obj, LV_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_bg_color(obj, lv_color_hex(0xffffffff), LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_bg_grad_dir(obj, LV_GRAD_DIR_VER, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_bg_grad_color(obj, lv_color_hex(0xff000000), LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_bg_grad_stop(obj, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_text_font(obj, &lv_font_montserrat_20, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_label_set_text(obj, "Done");
                }
            }
        }
        {
            lv_obj_t *obj = lv_btn_create(parent_obj);
            objects.obj44 = obj;
            lv_obj_set_pos(obj, 13, 76);
            lv_obj_set_size(obj, 80, 36);
            lv_obj_add_event_cb(obj, action_scan_button, LV_EVENT_RELEASED, (void *)1);
            lv_obj_add_event_cb(obj, action_scan_button, LV_EVENT_PRESSED, (void *)2);
            lv_obj_set_style_bg_color(obj, lv_color_hex(0xffffffff), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_bg_grad_dir(obj, LV_GRAD_DIR_VER, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_border_width(obj, 1, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_shadow_width(obj, 5, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_shadow_ofs_x(obj, 3, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_shadow_ofs_y(obj, 3, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_shadow_spread(obj, 2, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_shadow_color(obj, lv_color_hex(0xff000000), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_shadow_opa(obj, 128, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_border_width(obj, 1, LV_PART_MAIN | LV_STATE_PRESSED);
            lv_obj_set_style_transform_width(obj, -3, LV_PART_MAIN | LV_STATE_PRESSED);
            lv_obj_set_style_transform_height(obj, -3, LV_PART_MAIN | LV_STATE_PRESSED);
            lv_obj_set_style_bg_color(obj, lv_color_hex(0xff000000), LV_PART_MAIN | LV_STATE_PRESSED);
            lv_obj_set_style_bg_grad_dir(obj, LV_GRAD_DIR_VER, LV_PART_MAIN | LV_STATE_PRESSED);
            lv_obj_set_style_bg_grad_color(obj, lv_color_hex(0xffffffff), LV_PART_MAIN | LV_STATE_PRESSED);
            lv_obj_set_style_bg_opa(obj, 255, LV_PART_MAIN | LV_STATE_PRESSED);
            lv_obj_set_style_shadow_width(obj, 0, LV_PART_MAIN | LV_STATE_PRESSED);
            lv_obj_set_style_shadow_ofs_x(obj, 0, LV_PART_MAIN | LV_STATE_PRESSED);
            lv_obj_set_style_shadow_ofs_y(obj, 0, LV_PART_MAIN | LV_STATE_PRESSED);
            lv_obj_set_style_shadow_spread(obj, 0, LV_PART_MAIN | LV_STATE_PRESSED);
            lv_obj_set_style_shadow_opa(obj, 255, LV_PART_MAIN | LV_STATE_PRESSED);
            lv_obj_set_style_shadow_color(obj, lv_color_hex(0xff000000), LV_PART_MAIN | LV_STATE_PRESSED);
            {
                lv_obj_t *parent_obj = obj;
                {
                    lv_obj_t *obj = lv_label_create(parent_obj);
                    lv_obj_set_pos(obj, 0, 0);
                    lv_obj_set_size(obj, LV_SIZE_CONTENT, 16);
                    lv_obj_set_style_align(obj, LV_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_label_set_text(obj, "Scan");
                }
            }
        }
        {
            // listScanPgSsids
            lv_obj_t *obj = lv_list_create(parent_obj);
            objects.list_scan_pg_ssids = obj;
            lv_obj_set_pos(obj, 12, 122);
            lv_obj_set_size(obj, 298, 296);
            lv_obj_set_style_bg_color(obj, lv_color_hex(0xffffffff), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_color(obj, lv_color_hex(0xff000000), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_bg_color(obj, lv_color_hex(0xffffffff), LV_PART_MAIN | LV_STATE_CHECKED);
            lv_obj_set_style_text_color(obj, lv_color_hex(0xff000000), LV_PART_MAIN | LV_STATE_CHECKED);
        }
        {
            // txtScanStatus
            lv_obj_t *obj = lv_label_create(parent_obj);
            objects.txt_scan_status = obj;
            lv_obj_set_pos(obj, 100, 82);
            lv_obj_set_size(obj, 160, 24);
            lv_obj_set_style_text_align(obj, LV_TEXT_ALIGN_AUTO, LV_PART_MAIN | LV_STATE_PRESSED);
            lv_label_set_text(obj, "");
        }
    }
    
    tick_screen_scan();
}

void tick_screen_scan() {
}

void create_screen_config() {
    lv_obj_t *obj = lv_obj_create(0);
    objects.config = obj;
    lv_obj_set_pos(obj, 0, 0);
    lv_obj_set_size(obj, 320, 480);
    lv_obj_set_style_bg_color(obj, lv_color_hex(0xffc89600), LV_PART_MAIN | LV_STATE_DEFAULT);
    {
        lv_obj_t *parent_obj = obj;
        {
            // CreditsButton_4
            lv_obj_t *obj = lv_btn_create(parent_obj);
            objects.credits_button_4 = obj;
            lv_obj_set_pos(obj, 4, 426);
            lv_obj_set_size(obj, 85, 50);
            lv_obj_add_event_cb(obj, action_config_button, LV_EVENT_RELEASED, (void *)30);
            lv_obj_clear_flag(obj, LV_OBJ_FLAG_CLICK_FOCUSABLE|LV_OBJ_FLAG_GESTURE_BUBBLE|LV_OBJ_FLAG_PRESS_LOCK|LV_OBJ_FLAG_SCROLL_CHAIN_HOR|LV_OBJ_FLAG_SCROLL_CHAIN_VER|LV_OBJ_FLAG_SCROLL_ELASTIC|LV_OBJ_FLAG_SCROLL_MOMENTUM|LV_OBJ_FLAG_SNAPPABLE);
            lv_obj_set_style_bg_color(obj, lv_color_hex(0xffffffff), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_bg_grad_dir(obj, LV_GRAD_DIR_VER, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_bg_grad_color(obj, lv_color_hex(0xff000000), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_outline_width(obj, 1, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_font(obj, &lv_font_montserrat_24, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_shadow_width(obj, 10, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_shadow_ofs_x(obj, 5, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_shadow_ofs_y(obj, 5, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_shadow_spread(obj, 2, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_shadow_opa(obj, 128, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_shadow_color(obj, lv_color_hex(0xff000000), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_bg_color(obj, lv_color_hex(0xff000000), LV_PART_MAIN | LV_STATE_PRESSED);
            lv_obj_set_style_bg_grad_dir(obj, LV_GRAD_DIR_VER, LV_PART_MAIN | LV_STATE_PRESSED);
            lv_obj_set_style_bg_grad_color(obj, lv_color_hex(0xfffff200), LV_PART_MAIN | LV_STATE_PRESSED);
            lv_obj_set_style_text_color(obj, lv_color_hex(0xff000000), LV_PART_MAIN | LV_STATE_PRESSED);
            lv_obj_set_style_transform_width(obj, -2, LV_PART_MAIN | LV_STATE_PRESSED);
            lv_obj_set_style_transform_height(obj, -2, LV_PART_MAIN | LV_STATE_PRESSED);
            lv_obj_set_style_shadow_width(obj, 0, LV_PART_MAIN | LV_STATE_PRESSED);
            lv_obj_set_style_shadow_ofs_x(obj, 0, LV_PART_MAIN | LV_STATE_PRESSED);
            lv_obj_set_style_shadow_ofs_y(obj, 0, LV_PART_MAIN | LV_STATE_PRESSED);
            lv_obj_set_style_shadow_spread(obj, 2, LV_PART_MAIN | LV_STATE_PRESSED);
            lv_obj_set_style_text_font(obj, &lv_font_montserrat_20, LV_PART_MAIN | LV_STATE_CHECKED);
            {
                lv_obj_t *parent_obj = obj;
                {
                    lv_obj_t *obj = lv_label_create(parent_obj);
                    objects.obj45 = obj;
                    lv_obj_set_pos(obj, 0, 0);
                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                    lv_obj_clear_flag(obj, LV_OBJ_FLAG_CLICK_FOCUSABLE|LV_OBJ_FLAG_GESTURE_BUBBLE|LV_OBJ_FLAG_PRESS_LOCK|LV_OBJ_FLAG_SCROLLABLE|LV_OBJ_FLAG_SCROLL_CHAIN_HOR|LV_OBJ_FLAG_SCROLL_CHAIN_VER|LV_OBJ_FLAG_SCROLL_ELASTIC|LV_OBJ_FLAG_SCROLL_MOMENTUM|LV_OBJ_FLAG_SNAPPABLE);
                    lv_obj_set_style_align(obj, LV_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_bg_color(obj, lv_color_hex(0xffffffff), LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_bg_grad_dir(obj, LV_GRAD_DIR_VER, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_bg_grad_color(obj, lv_color_hex(0xff000000), LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_bg_grad_stop(obj, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_text_font(obj, &lv_font_montserrat_20, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_text_font(obj, &lv_font_montserrat_20, LV_PART_MAIN | LV_STATE_CHECKED);
                    lv_label_set_text(obj, "WiFi");
                }
            }
        }
        {
            // TipsButton_4
            lv_obj_t *obj = lv_btn_create(parent_obj);
            objects.tips_button_4 = obj;
            lv_obj_set_pos(obj, 118, 426);
            lv_obj_set_size(obj, 85, 50);
            lv_obj_add_event_cb(obj, action_config_button, LV_EVENT_RELEASED, (void *)31);
            lv_obj_clear_flag(obj, LV_OBJ_FLAG_CLICK_FOCUSABLE|LV_OBJ_FLAG_GESTURE_BUBBLE|LV_OBJ_FLAG_PRESS_LOCK|LV_OBJ_FLAG_SCROLL_CHAIN_HOR|LV_OBJ_FLAG_SCROLL_CHAIN_VER|LV_OBJ_FLAG_SCROLL_ELASTIC|LV_OBJ_FLAG_SCROLL_MOMENTUM|LV_OBJ_FLAG_SNAPPABLE);
            lv_obj_set_style_bg_color(obj, lv_color_hex(0xffffffff), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_bg_grad_dir(obj, LV_GRAD_DIR_VER, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_bg_grad_color(obj, lv_color_hex(0xff000000), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_outline_width(obj, 1, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_font(obj, &lv_font_montserrat_24, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_shadow_width(obj, 10, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_shadow_ofs_x(obj, 5, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_shadow_ofs_y(obj, 5, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_shadow_spread(obj, 2, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_shadow_opa(obj, 128, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_shadow_color(obj, lv_color_hex(0xff000000), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_bg_color(obj, lv_color_hex(0xff000000), LV_PART_MAIN | LV_STATE_PRESSED);
            lv_obj_set_style_bg_grad_dir(obj, LV_GRAD_DIR_VER, LV_PART_MAIN | LV_STATE_PRESSED);
            lv_obj_set_style_bg_grad_color(obj, lv_color_hex(0xfffff200), LV_PART_MAIN | LV_STATE_PRESSED);
            lv_obj_set_style_text_color(obj, lv_color_hex(0xff000000), LV_PART_MAIN | LV_STATE_PRESSED);
            lv_obj_set_style_transform_width(obj, -2, LV_PART_MAIN | LV_STATE_PRESSED);
            lv_obj_set_style_transform_height(obj, -2, LV_PART_MAIN | LV_STATE_PRESSED);
            lv_obj_set_style_shadow_width(obj, 0, LV_PART_MAIN | LV_STATE_PRESSED);
            lv_obj_set_style_shadow_ofs_x(obj, 0, LV_PART_MAIN | LV_STATE_PRESSED);
            lv_obj_set_style_shadow_ofs_y(obj, 0, LV_PART_MAIN | LV_STATE_PRESSED);
            lv_obj_set_style_shadow_spread(obj, 2, LV_PART_MAIN | LV_STATE_PRESSED);
            lv_obj_set_style_text_font(obj, &lv_font_montserrat_20, LV_PART_MAIN | LV_STATE_CHECKED);
            {
                lv_obj_t *parent_obj = obj;
                {
                    lv_obj_t *obj = lv_label_create(parent_obj);
                    objects.obj46 = obj;
                    lv_obj_set_pos(obj, 0, 0);
                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                    lv_obj_clear_flag(obj, LV_OBJ_FLAG_CLICK_FOCUSABLE|LV_OBJ_FLAG_GESTURE_BUBBLE|LV_OBJ_FLAG_PRESS_LOCK|LV_OBJ_FLAG_SCROLLABLE|LV_OBJ_FLAG_SCROLL_CHAIN_HOR|LV_OBJ_FLAG_SCROLL_CHAIN_VER|LV_OBJ_FLAG_SCROLL_ELASTIC|LV_OBJ_FLAG_SCROLL_MOMENTUM|LV_OBJ_FLAG_SNAPPABLE);
                    lv_obj_set_style_align(obj, LV_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_bg_color(obj, lv_color_hex(0xffffffff), LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_bg_grad_dir(obj, LV_GRAD_DIR_VER, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_bg_grad_color(obj, lv_color_hex(0xff000000), LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_bg_grad_stop(obj, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_text_font(obj, &lv_font_montserrat_20, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_text_font(obj, &lv_font_montserrat_20, LV_PART_MAIN | LV_STATE_CHECKED);
                    lv_label_set_text(obj, "Update");
                }
            }
        }
        {
            // InfoButton_4
            lv_obj_t *obj = lv_btn_create(parent_obj);
            objects.info_button_4 = obj;
            lv_obj_set_pos(obj, 232, 426);
            lv_obj_set_size(obj, 85, 50);
            lv_obj_add_event_cb(obj, action_config_button, LV_EVENT_RELEASED, (void *)32);
            lv_obj_clear_flag(obj, LV_OBJ_FLAG_CLICK_FOCUSABLE|LV_OBJ_FLAG_GESTURE_BUBBLE|LV_OBJ_FLAG_PRESS_LOCK|LV_OBJ_FLAG_SCROLL_CHAIN_HOR|LV_OBJ_FLAG_SCROLL_CHAIN_VER|LV_OBJ_FLAG_SCROLL_ELASTIC|LV_OBJ_FLAG_SCROLL_MOMENTUM|LV_OBJ_FLAG_SNAPPABLE);
            lv_obj_set_style_bg_color(obj, lv_color_hex(0xffffffff), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_bg_grad_dir(obj, LV_GRAD_DIR_VER, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_bg_grad_color(obj, lv_color_hex(0xff000000), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_outline_width(obj, 1, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_font(obj, &lv_font_montserrat_24, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_shadow_width(obj, 10, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_shadow_ofs_x(obj, 5, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_shadow_ofs_y(obj, 5, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_shadow_spread(obj, 2, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_shadow_opa(obj, 128, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_shadow_color(obj, lv_color_hex(0xff000000), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_bg_color(obj, lv_color_hex(0xff000000), LV_PART_MAIN | LV_STATE_PRESSED);
            lv_obj_set_style_bg_grad_dir(obj, LV_GRAD_DIR_VER, LV_PART_MAIN | LV_STATE_PRESSED);
            lv_obj_set_style_bg_grad_color(obj, lv_color_hex(0xfffff200), LV_PART_MAIN | LV_STATE_PRESSED);
            lv_obj_set_style_text_color(obj, lv_color_hex(0xff000000), LV_PART_MAIN | LV_STATE_PRESSED);
            lv_obj_set_style_transform_width(obj, -2, LV_PART_MAIN | LV_STATE_PRESSED);
            lv_obj_set_style_transform_height(obj, -2, LV_PART_MAIN | LV_STATE_PRESSED);
            lv_obj_set_style_shadow_width(obj, 0, LV_PART_MAIN | LV_STATE_PRESSED);
            lv_obj_set_style_shadow_ofs_x(obj, 0, LV_PART_MAIN | LV_STATE_PRESSED);
            lv_obj_set_style_shadow_ofs_y(obj, 0, LV_PART_MAIN | LV_STATE_PRESSED);
            lv_obj_set_style_shadow_spread(obj, 2, LV_PART_MAIN | LV_STATE_PRESSED);
            lv_obj_set_style_text_font(obj, &lv_font_montserrat_20, LV_PART_MAIN | LV_STATE_CHECKED);
            {
                lv_obj_t *parent_obj = obj;
                {
                    lv_obj_t *obj = lv_label_create(parent_obj);
                    objects.obj47 = obj;
                    lv_obj_set_pos(obj, 0, 0);
                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                    lv_obj_clear_flag(obj, LV_OBJ_FLAG_CLICK_FOCUSABLE|LV_OBJ_FLAG_GESTURE_BUBBLE|LV_OBJ_FLAG_PRESS_LOCK|LV_OBJ_FLAG_SCROLLABLE|LV_OBJ_FLAG_SCROLL_CHAIN_HOR|LV_OBJ_FLAG_SCROLL_CHAIN_VER|LV_OBJ_FLAG_SCROLL_ELASTIC|LV_OBJ_FLAG_SCROLL_MOMENTUM|LV_OBJ_FLAG_SNAPPABLE);
                    lv_obj_set_style_align(obj, LV_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_bg_color(obj, lv_color_hex(0xffffffff), LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_bg_grad_dir(obj, LV_GRAD_DIR_VER, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_bg_grad_color(obj, lv_color_hex(0xff000000), LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_bg_grad_stop(obj, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_text_font(obj, &lv_font_montserrat_20, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_text_font(obj, &lv_font_montserrat_20, LV_PART_MAIN | LV_STATE_CHECKED);
                    lv_label_set_text(obj, "Done");
                }
            }
        }
        {
            lv_obj_t *obj = lv_label_create(parent_obj);
            objects.obj48 = obj;
            lv_obj_set_pos(obj, 94, 36);
            lv_obj_set_size(obj, 140, 20);
            lv_obj_clear_flag(obj, LV_OBJ_FLAG_CLICK_FOCUSABLE|LV_OBJ_FLAG_GESTURE_BUBBLE|LV_OBJ_FLAG_PRESS_LOCK|LV_OBJ_FLAG_SCROLLABLE|LV_OBJ_FLAG_SCROLL_CHAIN_HOR|LV_OBJ_FLAG_SCROLL_CHAIN_VER|LV_OBJ_FLAG_SCROLL_ELASTIC|LV_OBJ_FLAG_SCROLL_MOMENTUM|LV_OBJ_FLAG_SNAPPABLE);
            lv_obj_set_style_text_align(obj, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_font(obj, &lv_font_montserrat_18, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_color(obj, lv_color_hex(0xffffffff), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_label_set_text(obj, "Config");
        }
        {
            lv_obj_t *obj = lv_label_create(parent_obj);
            objects.obj49 = obj;
            lv_obj_set_pos(obj, 20, 84);
            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
            lv_obj_set_style_text_color(obj, lv_color_hex(0xffffffff), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_label_set_text(obj, "Backlight Brightness");
        }
        {
            lv_obj_t *obj = lv_label_create(parent_obj);
            objects.obj50 = obj;
            lv_obj_set_pos(obj, 20, 114);
            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
            lv_obj_set_style_text_color(obj, lv_color_hex(0xffffffff), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_label_set_text(obj, "WiFi Timeout");
        }
        {
            // ta_tft_backlight
            lv_obj_t *obj = lv_textarea_create(parent_obj);
            objects.ta_tft_backlight = obj;
            lv_obj_set_pos(obj, 220, 80);
            lv_obj_set_size(obj, 50, 25);
            lv_textarea_set_max_length(obj, 3);
            lv_textarea_set_one_line(obj, true);
            lv_textarea_set_password_mode(obj, false);
            lv_obj_set_style_pad_top(obj, 2, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_bottom(obj, 3, LV_PART_MAIN | LV_STATE_DEFAULT);
        }
        {
            // ta_wifi_timeout
            lv_obj_t *obj = lv_textarea_create(parent_obj);
            objects.ta_wifi_timeout = obj;
            lv_obj_set_pos(obj, 220, 110);
            lv_obj_set_size(obj, 50, 25);
            lv_textarea_set_max_length(obj, 3);
            lv_textarea_set_one_line(obj, true);
            lv_textarea_set_password_mode(obj, false);
            lv_obj_set_style_pad_top(obj, 2, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_bottom(obj, 3, LV_PART_MAIN | LV_STATE_DEFAULT);
        }
        {
            // kbd_config
            lv_obj_t *obj = lv_keyboard_create(parent_obj);
            objects.kbd_config = obj;
            lv_obj_set_pos(obj, 4, 296);
            lv_obj_set_size(obj, 313, 120);
            lv_keyboard_set_mode(obj, LV_KEYBOARD_MODE_NUMBER);
            lv_obj_add_flag(obj, LV_OBJ_FLAG_HIDDEN);
            lv_obj_set_style_align(obj, LV_ALIGN_DEFAULT, LV_PART_MAIN | LV_STATE_DEFAULT);
        }
    }
    
    tick_screen_config();
}

void tick_screen_config() {
}

void create_screen_credits() {
    lv_obj_t *obj = lv_obj_create(0);
    objects.credits = obj;
    lv_obj_set_pos(obj, 0, 0);
    lv_obj_set_size(obj, 320, 480);
    lv_obj_set_style_bg_color(obj, lv_color_hex(0xffc89600), LV_PART_MAIN | LV_STATE_DEFAULT);
    {
        lv_obj_t *parent_obj = obj;
        {
            // CreditsButton_8
            lv_obj_t *obj = lv_btn_create(parent_obj);
            objects.credits_button_8 = obj;
            lv_obj_set_pos(obj, 4, 426);
            lv_obj_set_size(obj, 85, 50);
            lv_obj_add_event_cb(obj, action_general_button, LV_EVENT_RELEASED, (void *)7);
            lv_obj_clear_flag(obj, LV_OBJ_FLAG_CLICK_FOCUSABLE|LV_OBJ_FLAG_GESTURE_BUBBLE|LV_OBJ_FLAG_PRESS_LOCK|LV_OBJ_FLAG_SCROLL_CHAIN_HOR|LV_OBJ_FLAG_SCROLL_CHAIN_VER|LV_OBJ_FLAG_SCROLL_ELASTIC|LV_OBJ_FLAG_SCROLL_MOMENTUM|LV_OBJ_FLAG_SNAPPABLE);
            lv_obj_set_style_bg_color(obj, lv_color_hex(0xffffffff), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_bg_grad_dir(obj, LV_GRAD_DIR_VER, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_bg_grad_color(obj, lv_color_hex(0xff000000), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_outline_width(obj, 1, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_font(obj, &lv_font_montserrat_24, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_shadow_width(obj, 10, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_shadow_ofs_x(obj, 5, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_shadow_ofs_y(obj, 5, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_shadow_spread(obj, 2, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_shadow_opa(obj, 128, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_shadow_color(obj, lv_color_hex(0xff000000), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_bg_color(obj, lv_color_hex(0xff000000), LV_PART_MAIN | LV_STATE_PRESSED);
            lv_obj_set_style_bg_grad_dir(obj, LV_GRAD_DIR_VER, LV_PART_MAIN | LV_STATE_PRESSED);
            lv_obj_set_style_bg_grad_color(obj, lv_color_hex(0xfffff200), LV_PART_MAIN | LV_STATE_PRESSED);
            lv_obj_set_style_text_color(obj, lv_color_hex(0xff000000), LV_PART_MAIN | LV_STATE_PRESSED);
            lv_obj_set_style_transform_width(obj, -2, LV_PART_MAIN | LV_STATE_PRESSED);
            lv_obj_set_style_transform_height(obj, -2, LV_PART_MAIN | LV_STATE_PRESSED);
            lv_obj_set_style_shadow_width(obj, 0, LV_PART_MAIN | LV_STATE_PRESSED);
            lv_obj_set_style_shadow_ofs_x(obj, 0, LV_PART_MAIN | LV_STATE_PRESSED);
            lv_obj_set_style_shadow_ofs_y(obj, 0, LV_PART_MAIN | LV_STATE_PRESSED);
            lv_obj_set_style_shadow_spread(obj, 2, LV_PART_MAIN | LV_STATE_PRESSED);
            lv_obj_set_style_text_font(obj, &lv_font_montserrat_20, LV_PART_MAIN | LV_STATE_CHECKED);
            {
                lv_obj_t *parent_obj = obj;
                {
                    lv_obj_t *obj = lv_label_create(parent_obj);
                    objects.obj51 = obj;
                    lv_obj_set_pos(obj, 0, 0);
                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                    lv_obj_clear_flag(obj, LV_OBJ_FLAG_CLICK_FOCUSABLE|LV_OBJ_FLAG_GESTURE_BUBBLE|LV_OBJ_FLAG_PRESS_LOCK|LV_OBJ_FLAG_SCROLLABLE|LV_OBJ_FLAG_SCROLL_CHAIN_HOR|LV_OBJ_FLAG_SCROLL_CHAIN_VER|LV_OBJ_FLAG_SCROLL_ELASTIC|LV_OBJ_FLAG_SCROLL_MOMENTUM|LV_OBJ_FLAG_SNAPPABLE);
                    lv_obj_set_style_align(obj, LV_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_bg_color(obj, lv_color_hex(0xffffffff), LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_bg_grad_dir(obj, LV_GRAD_DIR_VER, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_bg_grad_color(obj, lv_color_hex(0xff000000), LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_bg_grad_stop(obj, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_text_font(obj, &lv_font_montserrat_20, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_text_font(obj, &lv_font_montserrat_20, LV_PART_MAIN | LV_STATE_CHECKED);
                    lv_label_set_text(obj, "Info");
                }
            }
        }
        {
            // InfoButton_8
            lv_obj_t *obj = lv_btn_create(parent_obj);
            objects.info_button_8 = obj;
            lv_obj_set_pos(obj, 232, 426);
            lv_obj_set_size(obj, 85, 50);
            lv_obj_add_event_cb(obj, action_general_button, LV_EVENT_RELEASED, (void *)5);
            lv_obj_clear_flag(obj, LV_OBJ_FLAG_CLICK_FOCUSABLE|LV_OBJ_FLAG_GESTURE_BUBBLE|LV_OBJ_FLAG_PRESS_LOCK|LV_OBJ_FLAG_SCROLL_CHAIN_HOR|LV_OBJ_FLAG_SCROLL_CHAIN_VER|LV_OBJ_FLAG_SCROLL_ELASTIC|LV_OBJ_FLAG_SCROLL_MOMENTUM|LV_OBJ_FLAG_SNAPPABLE);
            lv_obj_set_style_bg_color(obj, lv_color_hex(0xffffffff), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_bg_grad_dir(obj, LV_GRAD_DIR_VER, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_bg_grad_color(obj, lv_color_hex(0xff000000), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_outline_width(obj, 1, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_font(obj, &lv_font_montserrat_24, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_shadow_width(obj, 10, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_shadow_ofs_x(obj, 5, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_shadow_ofs_y(obj, 5, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_shadow_spread(obj, 2, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_shadow_opa(obj, 128, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_shadow_color(obj, lv_color_hex(0xff000000), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_bg_color(obj, lv_color_hex(0xff000000), LV_PART_MAIN | LV_STATE_PRESSED);
            lv_obj_set_style_bg_grad_dir(obj, LV_GRAD_DIR_VER, LV_PART_MAIN | LV_STATE_PRESSED);
            lv_obj_set_style_bg_grad_color(obj, lv_color_hex(0xfffff200), LV_PART_MAIN | LV_STATE_PRESSED);
            lv_obj_set_style_text_color(obj, lv_color_hex(0xff000000), LV_PART_MAIN | LV_STATE_PRESSED);
            lv_obj_set_style_transform_width(obj, -2, LV_PART_MAIN | LV_STATE_PRESSED);
            lv_obj_set_style_transform_height(obj, -2, LV_PART_MAIN | LV_STATE_PRESSED);
            lv_obj_set_style_shadow_width(obj, 0, LV_PART_MAIN | LV_STATE_PRESSED);
            lv_obj_set_style_shadow_ofs_x(obj, 0, LV_PART_MAIN | LV_STATE_PRESSED);
            lv_obj_set_style_shadow_ofs_y(obj, 0, LV_PART_MAIN | LV_STATE_PRESSED);
            lv_obj_set_style_shadow_spread(obj, 2, LV_PART_MAIN | LV_STATE_PRESSED);
            lv_obj_set_style_text_font(obj, &lv_font_montserrat_20, LV_PART_MAIN | LV_STATE_CHECKED);
            {
                lv_obj_t *parent_obj = obj;
                {
                    lv_obj_t *obj = lv_label_create(parent_obj);
                    objects.obj52 = obj;
                    lv_obj_set_pos(obj, 0, 0);
                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                    lv_obj_clear_flag(obj, LV_OBJ_FLAG_CLICK_FOCUSABLE|LV_OBJ_FLAG_GESTURE_BUBBLE|LV_OBJ_FLAG_PRESS_LOCK|LV_OBJ_FLAG_SCROLLABLE|LV_OBJ_FLAG_SCROLL_CHAIN_HOR|LV_OBJ_FLAG_SCROLL_CHAIN_VER|LV_OBJ_FLAG_SCROLL_ELASTIC|LV_OBJ_FLAG_SCROLL_MOMENTUM|LV_OBJ_FLAG_SNAPPABLE);
                    lv_obj_set_style_align(obj, LV_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_bg_color(obj, lv_color_hex(0xffffffff), LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_bg_grad_dir(obj, LV_GRAD_DIR_VER, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_bg_grad_color(obj, lv_color_hex(0xff000000), LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_bg_grad_stop(obj, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_text_font(obj, &lv_font_montserrat_20, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_text_font(obj, &lv_font_montserrat_20, LV_PART_MAIN | LV_STATE_CHECKED);
                    lv_label_set_text(obj, "Done");
                }
            }
        }
        {
            lv_obj_t *obj = lv_label_create(parent_obj);
            objects.obj53 = obj;
            lv_obj_set_pos(obj, 94, 36);
            lv_obj_set_size(obj, 140, 20);
            lv_obj_clear_flag(obj, LV_OBJ_FLAG_CLICK_FOCUSABLE|LV_OBJ_FLAG_GESTURE_BUBBLE|LV_OBJ_FLAG_PRESS_LOCK|LV_OBJ_FLAG_SCROLLABLE|LV_OBJ_FLAG_SCROLL_CHAIN_HOR|LV_OBJ_FLAG_SCROLL_CHAIN_VER|LV_OBJ_FLAG_SCROLL_ELASTIC|LV_OBJ_FLAG_SCROLL_MOMENTUM|LV_OBJ_FLAG_SNAPPABLE);
            lv_obj_set_style_text_align(obj, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_font(obj, &lv_font_montserrat_18, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_color(obj, lv_color_hex(0xffffffff), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_label_set_text(obj, "Credits");
        }
        {
            lv_obj_t *obj = lv_label_create(parent_obj);
            lv_obj_set_pos(obj, 10, 265);
            lv_obj_set_size(obj, 300, LV_SIZE_CONTENT);
            lv_obj_set_style_text_font(obj, &lv_font_montserrat_12, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_label_set_text(obj, "Those who helped with this first release:\n\nSteve (esfeld)\nErik (erik84750)\nLee (mtncityman)\nMichele (michele2796)\n\nMy sincere THANKS to ALL! \nNorm(normhal)");
        }
        {
            lv_obj_t *obj = lv_label_create(parent_obj);
            lv_obj_set_pos(obj, 10, 75);
            lv_obj_set_size(obj, 300, 32);
            lv_obj_set_style_text_font(obj, &lv_font_montserrat_12, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_label_set_text(obj, "Full credit goes to EEZ Studio without which this project would not have been possible!");
        }
        {
            lv_obj_t *obj = lv_label_create(parent_obj);
            lv_obj_set_pos(obj, 10, 155);
            lv_obj_set_size(obj, 300, LV_SIZE_CONTENT);
            lv_obj_set_style_text_font(obj, &lv_font_montserrat_12, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_label_set_text(obj, "The \"CYC\" acronym is a credit to the originator of the ubiquitous CYD (Cheap Yellow Display). ");
        }
        {
            lv_obj_t *obj = lv_label_create(parent_obj);
            lv_obj_set_pos(obj, 10, 115);
            lv_obj_set_size(obj, 300, LV_SIZE_CONTENT);
            lv_obj_set_style_text_font(obj, &lv_font_montserrat_12, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_label_set_text(obj, "It goes without saying that the entire DCC-EX team's work must be credited:-). ");
        }
    }
    
    tick_screen_credits();
}

void tick_screen_credits() {
}

void create_screen_info() {
    lv_obj_t *obj = lv_obj_create(0);
    objects.info = obj;
    lv_obj_set_pos(obj, 0, 0);
    lv_obj_set_size(obj, 320, 480);
    lv_obj_set_style_bg_color(obj, lv_color_hex(0xffc89600), LV_PART_MAIN | LV_STATE_DEFAULT);
    {
        lv_obj_t *parent_obj = obj;
        {
            // CreditsButton_10
            lv_obj_t *obj = lv_btn_create(parent_obj);
            objects.credits_button_10 = obj;
            lv_obj_set_pos(obj, 4, 426);
            lv_obj_set_size(obj, 85, 50);
            lv_obj_add_event_cb(obj, action_general_button, LV_EVENT_PRESSED, (void *)6);
            lv_obj_clear_flag(obj, LV_OBJ_FLAG_CLICK_FOCUSABLE|LV_OBJ_FLAG_GESTURE_BUBBLE|LV_OBJ_FLAG_PRESS_LOCK|LV_OBJ_FLAG_SCROLL_CHAIN_HOR|LV_OBJ_FLAG_SCROLL_CHAIN_VER|LV_OBJ_FLAG_SCROLL_ELASTIC|LV_OBJ_FLAG_SCROLL_MOMENTUM|LV_OBJ_FLAG_SNAPPABLE);
            lv_obj_set_style_bg_color(obj, lv_color_hex(0xffffffff), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_bg_grad_dir(obj, LV_GRAD_DIR_VER, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_bg_grad_color(obj, lv_color_hex(0xff000000), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_outline_width(obj, 1, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_font(obj, &lv_font_montserrat_24, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_shadow_width(obj, 10, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_shadow_ofs_x(obj, 5, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_shadow_ofs_y(obj, 5, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_shadow_spread(obj, 2, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_shadow_opa(obj, 128, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_shadow_color(obj, lv_color_hex(0xff000000), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_bg_color(obj, lv_color_hex(0xff000000), LV_PART_MAIN | LV_STATE_PRESSED);
            lv_obj_set_style_bg_grad_dir(obj, LV_GRAD_DIR_VER, LV_PART_MAIN | LV_STATE_PRESSED);
            lv_obj_set_style_bg_grad_color(obj, lv_color_hex(0xfffff200), LV_PART_MAIN | LV_STATE_PRESSED);
            lv_obj_set_style_text_color(obj, lv_color_hex(0xff000000), LV_PART_MAIN | LV_STATE_PRESSED);
            lv_obj_set_style_transform_width(obj, -2, LV_PART_MAIN | LV_STATE_PRESSED);
            lv_obj_set_style_transform_height(obj, -2, LV_PART_MAIN | LV_STATE_PRESSED);
            lv_obj_set_style_shadow_width(obj, 0, LV_PART_MAIN | LV_STATE_PRESSED);
            lv_obj_set_style_shadow_ofs_x(obj, 0, LV_PART_MAIN | LV_STATE_PRESSED);
            lv_obj_set_style_shadow_ofs_y(obj, 0, LV_PART_MAIN | LV_STATE_PRESSED);
            lv_obj_set_style_shadow_spread(obj, 2, LV_PART_MAIN | LV_STATE_PRESSED);
            lv_obj_set_style_text_font(obj, &lv_font_montserrat_20, LV_PART_MAIN | LV_STATE_CHECKED);
            {
                lv_obj_t *parent_obj = obj;
                {
                    lv_obj_t *obj = lv_label_create(parent_obj);
                    objects.obj54 = obj;
                    lv_obj_set_pos(obj, 0, 0);
                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                    lv_obj_clear_flag(obj, LV_OBJ_FLAG_CLICK_FOCUSABLE|LV_OBJ_FLAG_GESTURE_BUBBLE|LV_OBJ_FLAG_PRESS_LOCK|LV_OBJ_FLAG_SCROLLABLE|LV_OBJ_FLAG_SCROLL_CHAIN_HOR|LV_OBJ_FLAG_SCROLL_CHAIN_VER|LV_OBJ_FLAG_SCROLL_ELASTIC|LV_OBJ_FLAG_SCROLL_MOMENTUM|LV_OBJ_FLAG_SNAPPABLE);
                    lv_obj_set_style_align(obj, LV_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_bg_color(obj, lv_color_hex(0xffffffff), LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_bg_grad_dir(obj, LV_GRAD_DIR_VER, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_bg_grad_color(obj, lv_color_hex(0xff000000), LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_bg_grad_stop(obj, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_text_font(obj, &lv_font_montserrat_20, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_text_font(obj, &lv_font_montserrat_20, LV_PART_MAIN | LV_STATE_CHECKED);
                    lv_label_set_text(obj, "Credits");
                }
            }
        }
        {
            // InfoButton_10
            lv_obj_t *obj = lv_btn_create(parent_obj);
            objects.info_button_10 = obj;
            lv_obj_set_pos(obj, 232, 426);
            lv_obj_set_size(obj, 85, 50);
            lv_obj_add_event_cb(obj, action_general_button, LV_EVENT_RELEASED, (void *)5);
            lv_obj_clear_flag(obj, LV_OBJ_FLAG_CLICK_FOCUSABLE|LV_OBJ_FLAG_GESTURE_BUBBLE|LV_OBJ_FLAG_PRESS_LOCK|LV_OBJ_FLAG_SCROLL_CHAIN_HOR|LV_OBJ_FLAG_SCROLL_CHAIN_VER|LV_OBJ_FLAG_SCROLL_ELASTIC|LV_OBJ_FLAG_SCROLL_MOMENTUM|LV_OBJ_FLAG_SNAPPABLE);
            lv_obj_set_style_bg_color(obj, lv_color_hex(0xffffffff), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_bg_grad_dir(obj, LV_GRAD_DIR_VER, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_bg_grad_color(obj, lv_color_hex(0xff000000), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_outline_width(obj, 1, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_font(obj, &lv_font_montserrat_24, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_shadow_width(obj, 10, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_shadow_ofs_x(obj, 5, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_shadow_ofs_y(obj, 5, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_shadow_spread(obj, 2, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_shadow_opa(obj, 128, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_shadow_color(obj, lv_color_hex(0xff000000), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_bg_color(obj, lv_color_hex(0xff000000), LV_PART_MAIN | LV_STATE_PRESSED);
            lv_obj_set_style_bg_grad_dir(obj, LV_GRAD_DIR_VER, LV_PART_MAIN | LV_STATE_PRESSED);
            lv_obj_set_style_bg_grad_color(obj, lv_color_hex(0xfffff200), LV_PART_MAIN | LV_STATE_PRESSED);
            lv_obj_set_style_text_color(obj, lv_color_hex(0xff000000), LV_PART_MAIN | LV_STATE_PRESSED);
            lv_obj_set_style_transform_width(obj, -2, LV_PART_MAIN | LV_STATE_PRESSED);
            lv_obj_set_style_transform_height(obj, -2, LV_PART_MAIN | LV_STATE_PRESSED);
            lv_obj_set_style_shadow_width(obj, 0, LV_PART_MAIN | LV_STATE_PRESSED);
            lv_obj_set_style_shadow_ofs_x(obj, 0, LV_PART_MAIN | LV_STATE_PRESSED);
            lv_obj_set_style_shadow_ofs_y(obj, 0, LV_PART_MAIN | LV_STATE_PRESSED);
            lv_obj_set_style_shadow_spread(obj, 2, LV_PART_MAIN | LV_STATE_PRESSED);
            lv_obj_set_style_text_font(obj, &lv_font_montserrat_20, LV_PART_MAIN | LV_STATE_CHECKED);
            {
                lv_obj_t *parent_obj = obj;
                {
                    lv_obj_t *obj = lv_label_create(parent_obj);
                    objects.obj55 = obj;
                    lv_obj_set_pos(obj, 0, 0);
                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                    lv_obj_clear_flag(obj, LV_OBJ_FLAG_CLICK_FOCUSABLE|LV_OBJ_FLAG_GESTURE_BUBBLE|LV_OBJ_FLAG_PRESS_LOCK|LV_OBJ_FLAG_SCROLLABLE|LV_OBJ_FLAG_SCROLL_CHAIN_HOR|LV_OBJ_FLAG_SCROLL_CHAIN_VER|LV_OBJ_FLAG_SCROLL_ELASTIC|LV_OBJ_FLAG_SCROLL_MOMENTUM|LV_OBJ_FLAG_SNAPPABLE);
                    lv_obj_set_style_align(obj, LV_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_bg_color(obj, lv_color_hex(0xffffffff), LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_bg_grad_dir(obj, LV_GRAD_DIR_VER, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_bg_grad_color(obj, lv_color_hex(0xff000000), LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_bg_grad_stop(obj, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_text_font(obj, &lv_font_montserrat_20, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_text_font(obj, &lv_font_montserrat_20, LV_PART_MAIN | LV_STATE_CHECKED);
                    lv_label_set_text(obj, "Done");
                }
            }
        }
        {
            lv_obj_t *obj = lv_label_create(parent_obj);
            objects.obj56 = obj;
            lv_obj_set_pos(obj, 94, 36);
            lv_obj_set_size(obj, 140, 20);
            lv_obj_clear_flag(obj, LV_OBJ_FLAG_CLICK_FOCUSABLE|LV_OBJ_FLAG_GESTURE_BUBBLE|LV_OBJ_FLAG_PRESS_LOCK|LV_OBJ_FLAG_SCROLLABLE|LV_OBJ_FLAG_SCROLL_CHAIN_HOR|LV_OBJ_FLAG_SCROLL_CHAIN_VER|LV_OBJ_FLAG_SCROLL_ELASTIC|LV_OBJ_FLAG_SCROLL_MOMENTUM|LV_OBJ_FLAG_SNAPPABLE);
            lv_obj_set_style_text_align(obj, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_font(obj, &lv_font_montserrat_18, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_color(obj, lv_color_hex(0xffffffff), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_label_set_text(obj, "Information");
        }
        {
            lv_obj_t *obj = lv_label_create(parent_obj);
            lv_obj_set_pos(obj, 6, 78);
            lv_obj_set_size(obj, 311, LV_SIZE_CONTENT);
            lv_obj_set_style_text_font(obj, &lv_font_montserrat_12, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_label_set_text(obj, "Tools Used and References\nEEZ Studio Version 0.23.2\n(https://www.envox.eu)\n\nArduino IDEs and Libraries\nESP32 Boards Version 2.0.16\nlvgl Version 8.4\n\nWhilst everything here is \"Open Source\", I request you respect the originality of everyone's work and give credit where you think it's due:-)\n\n(c) Norman Halland (normhal)\nnormhal@gmail.com\nhttps://github.com/normhal/CYC\n\nVersion 1.0.2\n12 May 2025");
        }
    }
    
    tick_screen_info();
}

void tick_screen_info() {
}



typedef void (*tick_screen_func_t)();
tick_screen_func_t tick_screen_funcs[] = {
    tick_screen_main,
    tick_screen_throttle,
    tick_screen_roster,
    tick_screen_edit_loco,
    tick_screen_program,
    tick_screen_wi_fi,
    tick_screen_scan,
    tick_screen_config,
    tick_screen_credits,
    tick_screen_info,
};
void tick_screen(int screen_index) {
    tick_screen_funcs[screen_index]();
}
void tick_screen_by_id(enum ScreensEnum screenId) {
    tick_screen_funcs[screenId - 1]();
}

void create_screens() {
    lv_disp_t *dispp = lv_disp_get_default();
    lv_theme_t *theme = lv_theme_default_init(dispp, lv_palette_main(LV_PALETTE_BLUE), lv_palette_main(LV_PALETTE_RED), false, LV_FONT_DEFAULT);
    lv_disp_set_theme(dispp, theme);
    
    create_screen_main();
    create_screen_throttle();
    create_screen_roster();
    create_screen_edit_loco();
    create_screen_program();
    create_screen_wi_fi();
    create_screen_scan();
    create_screen_config();
    create_screen_credits();
    create_screen_info();
}
