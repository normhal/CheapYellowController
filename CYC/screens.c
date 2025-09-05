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

static void event_handler_unchecked_cb_wi_fi_btn_wifi_enable(lv_event_t *e) {
    lv_obj_t *ta = lv_event_get_target(e);
    if (!lv_obj_has_state(ta, LV_STATE_CHECKED)) {
        action_wifi_button(e);
    }
}

static void event_handler_checked_cb_wi_fi_btn_wifi_enable(lv_event_t *e) {
    lv_obj_t *ta = lv_event_get_target(e);
    if (lv_obj_has_state(ta, LV_STATE_CHECKED)) {
        action_wifi_button(e);
    }
}

static void event_handler_unchecked_cb_config_btn_roster(lv_event_t *e) {
    lv_obj_t *ta = lv_event_get_target(e);
    if (!lv_obj_has_state(ta, LV_STATE_CHECKED)) {
        action_config_button(e);
    }
}

static void event_handler_checked_cb_config_btn_roster(lv_event_t *e) {
    lv_obj_t *ta = lv_event_get_target(e);
    if (lv_obj_has_state(ta, LV_STATE_CHECKED)) {
        action_config_button(e);
    }
}

static void event_handler_unchecked_cb_config_btn_acc(lv_event_t *e) {
    lv_obj_t *ta = lv_event_get_target(e);
    if (!lv_obj_has_state(ta, LV_STATE_CHECKED)) {
        action_config_button(e);
    }
}

static void event_handler_checked_cb_config_btn_acc(lv_event_t *e) {
    lv_obj_t *ta = lv_event_get_target(e);
    if (lv_obj_has_state(ta, LV_STATE_CHECKED)) {
        action_config_button(e);
    }
}

static void event_handler_checked_cb_config_btn_load_local(lv_event_t *e) {
    lv_obj_t *ta = lv_event_get_target(e);
    if (lv_obj_has_state(ta, LV_STATE_CHECKED)) {
        action_config_button(e);
    }
}

static void event_handler_unchecked_cb_config_btn_re_enable(lv_event_t *e) {
    lv_obj_t *ta = lv_event_get_target(e);
    if (!lv_obj_has_state(ta, LV_STATE_CHECKED)) {
        action_config_button(e);
    }
}

static void event_handler_checked_cb_config_btn_re_enable(lv_event_t *e) {
    lv_obj_t *ta = lv_event_get_target(e);
    if (lv_obj_has_state(ta, LV_STATE_CHECKED)) {
        action_config_button(e);
    }
}

static void event_handler_checked_cb_layout_btn_dc(lv_event_t *e) {
    lv_obj_t *ta = lv_event_get_target(e);
    if (lv_obj_has_state(ta, LV_STATE_CHECKED)) {
        action_turnout_button(e);
    }
}

static void event_handler_unchecked_cb_layout_btn_dc(lv_event_t *e) {
    lv_obj_t *ta = lv_event_get_target(e);
    if (!lv_obj_has_state(ta, LV_STATE_CHECKED)) {
        action_turnout_button(e);
    }
}

static void event_handler_checked_cb_layout_btn_fa(lv_event_t *e) {
    lv_obj_t *ta = lv_event_get_target(e);
    if (lv_obj_has_state(ta, LV_STATE_CHECKED)) {
        action_turnout_button(e);
    }
}

static void event_handler_unchecked_cb_layout_btn_fa(lv_event_t *e) {
    lv_obj_t *ta = lv_event_get_target(e);
    if (!lv_obj_has_state(ta, LV_STATE_CHECKED)) {
        action_turnout_button(e);
    }
}

static void event_handler_checked_cb_layout_btn_fg(lv_event_t *e) {
    lv_obj_t *ta = lv_event_get_target(e);
    if (lv_obj_has_state(ta, LV_STATE_CHECKED)) {
        action_turnout_button(e);
    }
}

static void event_handler_unchecked_cb_layout_btn_fg(lv_event_t *e) {
    lv_obj_t *ta = lv_event_get_target(e);
    if (!lv_obj_has_state(ta, LV_STATE_CHECKED)) {
        action_turnout_button(e);
    }
}

static void event_handler_checked_cb_layout_btn_ec(lv_event_t *e) {
    lv_obj_t *ta = lv_event_get_target(e);
    if (lv_obj_has_state(ta, LV_STATE_CHECKED)) {
        action_turnout_button(e);
    }
}

static void event_handler_unchecked_cb_layout_btn_ec(lv_event_t *e) {
    lv_obj_t *ta = lv_event_get_target(e);
    if (!lv_obj_has_state(ta, LV_STATE_CHECKED)) {
        action_turnout_button(e);
    }
}

static void event_handler_checked_cb_layout_edit_button(lv_event_t *e) {
    lv_obj_t *ta = lv_event_get_target(e);
    if (lv_obj_has_state(ta, LV_STATE_CHECKED)) {
        action_turnout_button(e);
    }
}

void create_screen_main() {
    lv_obj_t *obj = lv_obj_create(0);
    objects.main = obj;
    lv_obj_set_pos(obj, 0, 0);
    lv_obj_set_size(obj, 480, 800);
    lv_obj_set_style_bg_color(obj, lv_color_hex(0xffc89600), LV_PART_MAIN | LV_STATE_DEFAULT);
    {
        lv_obj_t *parent_obj = obj;
        {
            // btnHome
            lv_obj_t *obj = lv_btn_create(parent_obj);
            objects.btn_home = obj;
            lv_obj_set_pos(obj, 140, 4);
            lv_obj_set_size(obj, 200, 50);
            lv_obj_add_event_cb(obj, action_general_button, LV_EVENT_RELEASED, (void *)5);
            lv_obj_set_style_bg_color(obj, lv_color_hex(0xffc89600), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_bg_img_src(obj, &img_dcc_ex, LV_PART_MAIN | LV_STATE_DEFAULT);
            {
                lv_obj_t *parent_obj = obj;
                {
                    lv_obj_t *obj = lv_label_create(parent_obj);
                    lv_obj_set_pos(obj, 0, 0);
                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                    lv_obj_set_style_align(obj, LV_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_label_set_text(obj, "");
                }
            }
        }
        {
            lv_obj_t *obj = lv_label_create(parent_obj);
            objects.obj0 = obj;
            lv_obj_set_pos(obj, 140, 54);
            lv_obj_set_size(obj, 205, 30);
            lv_obj_clear_flag(obj, LV_OBJ_FLAG_CLICK_FOCUSABLE|LV_OBJ_FLAG_GESTURE_BUBBLE|LV_OBJ_FLAG_PRESS_LOCK|LV_OBJ_FLAG_SCROLLABLE|LV_OBJ_FLAG_SCROLL_CHAIN_HOR|LV_OBJ_FLAG_SCROLL_CHAIN_VER|LV_OBJ_FLAG_SCROLL_ELASTIC|LV_OBJ_FLAG_SCROLL_MOMENTUM|LV_OBJ_FLAG_SNAPPABLE);
            lv_obj_set_style_text_align(obj, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_font(obj, &lv_font_montserrat_24, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_color(obj, lv_color_hex(0xffffffff), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_label_set_text(obj, "Controller");
        }
        {
            // btnStop
            lv_obj_t *obj = lv_btn_create(parent_obj);
            objects.btn_stop = obj;
            lv_obj_set_pos(obj, 8, 10);
            lv_obj_set_size(obj, 100, 70);
            lv_obj_add_event_cb(obj, event_handler_checked_cb_main_btn_stop, LV_EVENT_VALUE_CHANGED, (void *)1);
            lv_obj_add_event_cb(obj, event_handler_unchecked_cb_main_btn_stop, LV_EVENT_VALUE_CHANGED, (void *)2);
            lv_obj_add_flag(obj, LV_OBJ_FLAG_CHECKABLE);
            lv_obj_clear_flag(obj, LV_OBJ_FLAG_CLICK_FOCUSABLE|LV_OBJ_FLAG_GESTURE_BUBBLE|LV_OBJ_FLAG_SCROLL_CHAIN_HOR|LV_OBJ_FLAG_SCROLL_CHAIN_VER|LV_OBJ_FLAG_SCROLL_ELASTIC|LV_OBJ_FLAG_SCROLL_MOMENTUM|LV_OBJ_FLAG_SNAPPABLE);
            lv_obj_set_style_bg_color(obj, lv_color_hex(0xffff0000), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_bg_grad_dir(obj, LV_GRAD_DIR_VER, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_bg_grad_color(obj, lv_color_hex(0xff000000), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_outline_width(obj, 1, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_shadow_width(obj, 10, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_shadow_ofs_y(obj, 5, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_shadow_ofs_x(obj, 5, LV_PART_MAIN | LV_STATE_DEFAULT);
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
            lv_obj_set_style_bg_color(obj, lv_color_hex(0xff000000), LV_PART_MAIN | LV_STATE_CHECKED);
            lv_obj_set_style_bg_grad_color(obj, lv_color_hex(0xff00ff00), LV_PART_MAIN | LV_STATE_CHECKED);
            lv_obj_set_style_bg_grad_dir(obj, LV_GRAD_DIR_VER, LV_PART_MAIN | LV_STATE_CHECKED);
            lv_obj_set_style_shadow_width(obj, 10, LV_PART_MAIN | LV_STATE_CHECKED);
            lv_obj_set_style_shadow_ofs_x(obj, 5, LV_PART_MAIN | LV_STATE_CHECKED);
            lv_obj_set_style_shadow_ofs_y(obj, 5, LV_PART_MAIN | LV_STATE_CHECKED);
            lv_obj_set_style_shadow_spread(obj, 2, LV_PART_MAIN | LV_STATE_CHECKED);
            lv_obj_set_style_shadow_opa(obj, 128, LV_PART_MAIN | LV_STATE_CHECKED);
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
                    lv_obj_set_style_text_font(obj, &lv_font_montserrat_24, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_text_font(obj, &lv_font_montserrat_14, LV_PART_MAIN | LV_STATE_CHECKED);
                    lv_label_set_text(obj, "Stop");
                }
            }
        }
        {
            // btnPower
            lv_obj_t *obj = lv_btn_create(parent_obj);
            objects.btn_power = obj;
            lv_obj_set_pos(obj, 372, 10);
            lv_obj_set_size(obj, 100, 70);
            lv_obj_add_event_cb(obj, event_handler_checked_cb_main_btn_power, LV_EVENT_VALUE_CHANGED, (void *)3);
            lv_obj_add_event_cb(obj, event_handler_unchecked_cb_main_btn_power, LV_EVENT_VALUE_CHANGED, (void *)4);
            lv_obj_add_flag(obj, LV_OBJ_FLAG_CHECKABLE);
            lv_obj_clear_flag(obj, LV_OBJ_FLAG_CLICK_FOCUSABLE|LV_OBJ_FLAG_GESTURE_BUBBLE|LV_OBJ_FLAG_SCROLL_CHAIN_HOR|LV_OBJ_FLAG_SCROLL_CHAIN_VER|LV_OBJ_FLAG_SCROLL_ELASTIC|LV_OBJ_FLAG_SCROLL_MOMENTUM|LV_OBJ_FLAG_SNAPPABLE);
            lv_obj_set_style_bg_color(obj, lv_color_hex(0xffff0000), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_bg_grad_dir(obj, LV_GRAD_DIR_VER, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_bg_grad_color(obj, lv_color_hex(0xff000000), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_shadow_width(obj, 10, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_shadow_ofs_x(obj, 5, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_shadow_ofs_y(obj, 5, LV_PART_MAIN | LV_STATE_DEFAULT);
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
            lv_obj_set_style_bg_color(obj, lv_color_hex(0xff000000), LV_PART_MAIN | LV_STATE_CHECKED);
            lv_obj_set_style_bg_grad_color(obj, lv_color_hex(0xff00ff00), LV_PART_MAIN | LV_STATE_CHECKED);
            lv_obj_set_style_shadow_width(obj, 10, LV_PART_MAIN | LV_STATE_CHECKED);
            lv_obj_set_style_shadow_ofs_x(obj, 5, LV_PART_MAIN | LV_STATE_CHECKED);
            lv_obj_set_style_shadow_ofs_y(obj, 5, LV_PART_MAIN | LV_STATE_CHECKED);
            lv_obj_set_style_shadow_spread(obj, 2, LV_PART_MAIN | LV_STATE_CHECKED);
            lv_obj_set_style_shadow_opa(obj, 128, LV_PART_MAIN | LV_STATE_CHECKED);
            {
                lv_obj_t *parent_obj = obj;
                {
                    // lblPower
                    lv_obj_t *obj = lv_label_create(parent_obj);
                    objects.lbl_power = obj;
                    lv_obj_set_pos(obj, 0, 0);
                    lv_obj_set_size(obj, 80, LV_SIZE_CONTENT);
                    lv_obj_set_style_align(obj, LV_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_text_font(obj, &lv_font_montserrat_24, LV_PART_MAIN | LV_STATE_DEFAULT);
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
            lv_obj_set_pos(obj, 0, 90);
            lv_obj_set_size(obj, 480, 1);
            static lv_point_t line_points[] = {
                { 0, 90 },
                { 480, 90 }
            };
            lv_line_set_points(obj, line_points, 2);
            lv_obj_clear_flag(obj, LV_OBJ_FLAG_CLICK_FOCUSABLE|LV_OBJ_FLAG_GESTURE_BUBBLE|LV_OBJ_FLAG_PRESS_LOCK|LV_OBJ_FLAG_SCROLLABLE|LV_OBJ_FLAG_SCROLL_CHAIN_HOR|LV_OBJ_FLAG_SCROLL_CHAIN_VER|LV_OBJ_FLAG_SCROLL_ELASTIC|LV_OBJ_FLAG_SCROLL_MOMENTUM|LV_OBJ_FLAG_SCROLL_WITH_ARROW|LV_OBJ_FLAG_SNAPPABLE);
            lv_obj_set_style_shadow_width(obj, 10, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_shadow_ofs_x(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_shadow_ofs_y(obj, 2, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_shadow_opa(obj, 127, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_border_color(obj, lv_color_hex(0xff000000), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_border_width(obj, 1, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_shadow_spread(obj, 6, LV_PART_MAIN | LV_STATE_DEFAULT);
        }
        {
            // CreditsButton
            lv_obj_t *obj = lv_btn_create(parent_obj);
            objects.credits_button = obj;
            lv_obj_set_pos(obj, 10, 710);
            lv_obj_set_size(obj, 145, 80);
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
            lv_obj_set_style_text_font(obj, &lv_font_montserrat_20, LV_PART_MAIN | LV_STATE_CHECKED);
            {
                lv_obj_t *parent_obj = obj;
                {
                    lv_obj_t *obj = lv_label_create(parent_obj);
                    objects.obj1 = obj;
                    lv_obj_set_pos(obj, 0, 0);
                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                    lv_obj_clear_flag(obj, LV_OBJ_FLAG_CLICK_FOCUSABLE|LV_OBJ_FLAG_GESTURE_BUBBLE|LV_OBJ_FLAG_PRESS_LOCK|LV_OBJ_FLAG_SCROLLABLE|LV_OBJ_FLAG_SCROLL_CHAIN_HOR|LV_OBJ_FLAG_SCROLL_CHAIN_VER|LV_OBJ_FLAG_SCROLL_ELASTIC|LV_OBJ_FLAG_SCROLL_MOMENTUM|LV_OBJ_FLAG_SNAPPABLE);
                    lv_obj_set_style_align(obj, LV_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_bg_color(obj, lv_color_hex(0xffffffff), LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_bg_grad_dir(obj, LV_GRAD_DIR_VER, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_bg_grad_color(obj, lv_color_hex(0xff000000), LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_bg_grad_stop(obj, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_text_font(obj, &lv_font_montserrat_32, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_text_font(obj, &lv_font_montserrat_20, LV_PART_MAIN | LV_STATE_CHECKED);
                    lv_label_set_text(obj, "Credits");
                }
            }
        }
        {
            // InfoButton
            lv_obj_t *obj = lv_btn_create(parent_obj);
            objects.info_button = obj;
            lv_obj_set_pos(obj, 324, 710);
            lv_obj_set_size(obj, 145, 80);
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
            lv_obj_set_style_text_font(obj, &lv_font_montserrat_20, LV_PART_MAIN | LV_STATE_CHECKED);
            {
                lv_obj_t *parent_obj = obj;
                {
                    lv_obj_t *obj = lv_label_create(parent_obj);
                    objects.obj2 = obj;
                    lv_obj_set_pos(obj, 0, 0);
                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                    lv_obj_clear_flag(obj, LV_OBJ_FLAG_CLICK_FOCUSABLE|LV_OBJ_FLAG_GESTURE_BUBBLE|LV_OBJ_FLAG_PRESS_LOCK|LV_OBJ_FLAG_SCROLLABLE|LV_OBJ_FLAG_SCROLL_CHAIN_HOR|LV_OBJ_FLAG_SCROLL_CHAIN_VER|LV_OBJ_FLAG_SCROLL_ELASTIC|LV_OBJ_FLAG_SCROLL_MOMENTUM|LV_OBJ_FLAG_SNAPPABLE);
                    lv_obj_set_style_align(obj, LV_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_bg_color(obj, lv_color_hex(0xffffffff), LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_bg_grad_dir(obj, LV_GRAD_DIR_VER, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_bg_grad_color(obj, lv_color_hex(0xff000000), LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_bg_grad_stop(obj, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_text_font(obj, &lv_font_montserrat_32, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_text_font(obj, &lv_font_montserrat_20, LV_PART_MAIN | LV_STATE_CHECKED);
                    lv_label_set_text(obj, "Info");
                }
            }
        }
        {
            lv_obj_t *obj = lv_label_create(parent_obj);
            objects.obj3 = obj;
            lv_obj_set_pos(obj, 109, 107);
            lv_obj_set_size(obj, 263, 34);
            lv_obj_clear_flag(obj, LV_OBJ_FLAG_CLICK_FOCUSABLE|LV_OBJ_FLAG_GESTURE_BUBBLE|LV_OBJ_FLAG_PRESS_LOCK|LV_OBJ_FLAG_SCROLLABLE|LV_OBJ_FLAG_SCROLL_CHAIN_HOR|LV_OBJ_FLAG_SCROLL_CHAIN_VER|LV_OBJ_FLAG_SCROLL_ELASTIC|LV_OBJ_FLAG_SCROLL_MOMENTUM|LV_OBJ_FLAG_SNAPPABLE);
            lv_obj_set_style_text_font(obj, &lv_font_montserrat_28, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_align(obj, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_color(obj, lv_color_hex(0xffffffff), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_outline_width(obj, 1, LV_PART_MAIN | LV_STATE_PRESSED);
            lv_label_set_text(obj, "Throttle");
        }
        {
            // throttle_mtx
            lv_obj_t *obj = lv_btnmatrix_create(parent_obj);
            objects.throttle_mtx = obj;
            lv_obj_set_pos(obj, 17, 144);
            lv_obj_set_size(obj, 444, 90);
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
            lv_obj_add_flag(obj, LV_OBJ_FLAG_CHECKABLE);
            lv_obj_set_style_pad_top(obj, 4, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_bottom(obj, 8, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_left(obj, 4, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_right(obj, 8, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_column(obj, 30, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_bg_color(obj, lv_color_hex(0xffc89600), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_border_width(obj, 2, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_border_color(obj, lv_color_hex(0xffc89600), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_bg_color(obj, lv_color_hex(0xffffffff), LV_PART_ITEMS | LV_STATE_DEFAULT);
            lv_obj_set_style_bg_grad_dir(obj, LV_GRAD_DIR_VER, LV_PART_ITEMS | LV_STATE_DEFAULT);
            lv_obj_set_style_bg_grad_color(obj, lv_color_hex(0xff000000), LV_PART_ITEMS | LV_STATE_DEFAULT);
            lv_obj_set_style_border_width(obj, 1, LV_PART_ITEMS | LV_STATE_DEFAULT);
            lv_obj_set_style_shadow_width(obj, 10, LV_PART_ITEMS | LV_STATE_DEFAULT);
            lv_obj_set_style_shadow_ofs_x(obj, 5, LV_PART_ITEMS | LV_STATE_DEFAULT);
            lv_obj_set_style_shadow_ofs_y(obj, 5, LV_PART_ITEMS | LV_STATE_DEFAULT);
            lv_obj_set_style_shadow_spread(obj, 2, LV_PART_ITEMS | LV_STATE_DEFAULT);
            lv_obj_set_style_shadow_color(obj, lv_color_hex(0xff000000), LV_PART_ITEMS | LV_STATE_DEFAULT);
            lv_obj_set_style_shadow_opa(obj, 127, LV_PART_ITEMS | LV_STATE_DEFAULT);
            lv_obj_set_style_text_color(obj, lv_color_hex(0xffffffff), LV_PART_ITEMS | LV_STATE_DEFAULT);
            lv_obj_set_style_text_font(obj, &lv_font_montserrat_36, LV_PART_ITEMS | LV_STATE_DEFAULT);
            lv_obj_set_style_bg_color(obj, lv_color_hex(0xff000000), LV_PART_ITEMS | LV_STATE_CHECKED);
            lv_obj_set_style_bg_grad_dir(obj, LV_GRAD_DIR_VER, LV_PART_ITEMS | LV_STATE_CHECKED);
            lv_obj_set_style_bg_grad_color(obj, lv_color_hex(0xffff0000), LV_PART_ITEMS | LV_STATE_CHECKED);
            lv_obj_set_style_shadow_width(obj, 0, LV_PART_ITEMS | LV_STATE_CHECKED);
            lv_obj_set_style_shadow_ofs_x(obj, 0, LV_PART_ITEMS | LV_STATE_CHECKED);
            lv_obj_set_style_shadow_ofs_y(obj, 0, LV_PART_ITEMS | LV_STATE_CHECKED);
            lv_obj_set_style_shadow_spread(obj, 0, LV_PART_ITEMS | LV_STATE_CHECKED);
            lv_obj_set_style_text_color(obj, lv_color_hex(0xffffffff), LV_PART_ITEMS | LV_STATE_CHECKED);
            lv_obj_set_style_text_font(obj, &lv_font_montserrat_40, LV_PART_ITEMS | LV_STATE_CHECKED);
        }
        {
            // MenuMtx
            lv_obj_t *obj = lv_btnmatrix_create(parent_obj);
            objects.menu_mtx = obj;
            lv_obj_set_pos(obj, 24, 243);
            lv_obj_set_size(obj, 441, 449);
            static const char *map[12] = {
                "Config",
                "Roster",
                "\n",
                "Acc",
                "Program",
                "\n",
                "WiFi",
                "Layout",
                "\n",
                "Save",
                "Restore",
                NULL,
            };
            static lv_btnmatrix_ctrl_t ctrl_map[8] = {
                1 | LV_BTNMATRIX_CTRL_CHECKABLE,
                1 | LV_BTNMATRIX_CTRL_CHECKABLE,
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
            lv_obj_set_style_bg_color(obj, lv_color_hex(0xffffffff), LV_PART_ITEMS | LV_STATE_DEFAULT);
            lv_obj_set_style_bg_grad_dir(obj, LV_GRAD_DIR_VER, LV_PART_ITEMS | LV_STATE_DEFAULT);
            lv_obj_set_style_border_width(obj, 1, LV_PART_ITEMS | LV_STATE_DEFAULT);
            lv_obj_set_style_shadow_width(obj, 10, LV_PART_ITEMS | LV_STATE_DEFAULT);
            lv_obj_set_style_shadow_ofs_x(obj, 5, LV_PART_ITEMS | LV_STATE_DEFAULT);
            lv_obj_set_style_shadow_ofs_y(obj, 5, LV_PART_ITEMS | LV_STATE_DEFAULT);
            lv_obj_set_style_shadow_spread(obj, 6, LV_PART_ITEMS | LV_STATE_DEFAULT);
            lv_obj_set_style_shadow_color(obj, lv_color_hex(0xff000000), LV_PART_ITEMS | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_top(obj, 0, LV_PART_ITEMS | LV_STATE_DEFAULT);
            lv_obj_set_style_text_font(obj, &lv_font_montserrat_30, LV_PART_ITEMS | LV_STATE_DEFAULT);
            lv_obj_set_style_text_color(obj, lv_color_hex(0xffffffff), LV_PART_ITEMS | LV_STATE_DEFAULT);
            lv_obj_set_style_bg_color(obj, lv_color_hex(0xffc89600), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_border_width(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_top(obj, 4, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_left(obj, 4, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_right(obj, 15, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_row(obj, 30, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_column(obj, 50, LV_PART_MAIN | LV_STATE_DEFAULT);
        }
        {
            // img_Wifi
            lv_obj_t *obj = lv_img_create(parent_obj);
            objects.img_wifi = obj;
            lv_obj_set_pos(obj, 144, 60);
            lv_obj_set_size(obj, 27, 18);
            lv_obj_set_style_bg_color(obj, lv_color_hex(0xffc89600), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_bg_opa(obj, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
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
    lv_obj_set_size(obj, 480, 800);
    lv_obj_set_style_bg_color(obj, lv_color_hex(0xffc89600), LV_PART_MAIN | LV_STATE_DEFAULT);
    {
        lv_obj_t *parent_obj = obj;
        {
            // CreditsButton_1
            lv_obj_t *obj = lv_btn_create(parent_obj);
            objects.credits_button_1 = obj;
            lv_obj_set_pos(obj, 11, 711);
            lv_obj_set_size(obj, 145, 80);
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
            lv_obj_set_style_shadow_width(obj, 10, LV_PART_MAIN | LV_STATE_PRESSED);
            lv_obj_set_style_text_font(obj, &lv_font_montserrat_20, LV_PART_MAIN | LV_STATE_CHECKED);
            {
                lv_obj_t *parent_obj = obj;
                {
                    lv_obj_t *obj = lv_label_create(parent_obj);
                    objects.obj4 = obj;
                    lv_obj_set_pos(obj, 0, 0);
                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                    lv_obj_clear_flag(obj, LV_OBJ_FLAG_CLICK_FOCUSABLE|LV_OBJ_FLAG_GESTURE_BUBBLE|LV_OBJ_FLAG_PRESS_LOCK|LV_OBJ_FLAG_SCROLLABLE|LV_OBJ_FLAG_SCROLL_CHAIN_HOR|LV_OBJ_FLAG_SCROLL_CHAIN_VER|LV_OBJ_FLAG_SCROLL_ELASTIC|LV_OBJ_FLAG_SCROLL_MOMENTUM|LV_OBJ_FLAG_SNAPPABLE);
                    lv_obj_set_style_align(obj, LV_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_bg_color(obj, lv_color_hex(0xffffffff), LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_bg_grad_dir(obj, LV_GRAD_DIR_VER, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_bg_grad_color(obj, lv_color_hex(0xff000000), LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_bg_grad_stop(obj, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_text_font(obj, &lv_font_montserrat_32, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_text_font(obj, &lv_font_montserrat_20, LV_PART_MAIN | LV_STATE_CHECKED);
                    lv_label_set_text(obj, "Prog");
                }
            }
        }
        {
            // TipsButton_1
            lv_obj_t *obj = lv_btn_create(parent_obj);
            objects.tips_button_1 = obj;
            lv_obj_set_pos(obj, 168, 711);
            lv_obj_set_size(obj, 145, 80);
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
            lv_obj_set_style_shadow_width(obj, 10, LV_PART_MAIN | LV_STATE_PRESSED);
            lv_obj_set_style_text_font(obj, &lv_font_montserrat_20, LV_PART_MAIN | LV_STATE_CHECKED);
            {
                lv_obj_t *parent_obj = obj;
                {
                    lv_obj_t *obj = lv_label_create(parent_obj);
                    objects.obj5 = obj;
                    lv_obj_set_pos(obj, 0, 0);
                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                    lv_obj_clear_flag(obj, LV_OBJ_FLAG_CLICK_FOCUSABLE|LV_OBJ_FLAG_GESTURE_BUBBLE|LV_OBJ_FLAG_PRESS_LOCK|LV_OBJ_FLAG_SCROLLABLE|LV_OBJ_FLAG_SCROLL_CHAIN_HOR|LV_OBJ_FLAG_SCROLL_CHAIN_VER|LV_OBJ_FLAG_SCROLL_ELASTIC|LV_OBJ_FLAG_SCROLL_MOMENTUM|LV_OBJ_FLAG_SNAPPABLE);
                    lv_obj_set_style_align(obj, LV_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_bg_color(obj, lv_color_hex(0xffffffff), LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_bg_grad_dir(obj, LV_GRAD_DIR_VER, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_bg_grad_color(obj, lv_color_hex(0xff000000), LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_bg_grad_stop(obj, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_text_font(obj, &lv_font_montserrat_32, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_text_font(obj, &lv_font_montserrat_20, LV_PART_MAIN | LV_STATE_CHECKED);
                    lv_label_set_text(obj, "Roster");
                }
            }
        }
        {
            // InfoButton_1
            lv_obj_t *obj = lv_btn_create(parent_obj);
            objects.info_button_1 = obj;
            lv_obj_set_pos(obj, 325, 711);
            lv_obj_set_size(obj, 145, 80);
            lv_obj_add_event_cb(obj, action_throttle_button, LV_EVENT_RELEASED, (void *)32);
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
            lv_obj_set_style_shadow_width(obj, 10, LV_PART_MAIN | LV_STATE_PRESSED);
            lv_obj_set_style_text_font(obj, &lv_font_montserrat_20, LV_PART_MAIN | LV_STATE_CHECKED);
            {
                lv_obj_t *parent_obj = obj;
                {
                    lv_obj_t *obj = lv_label_create(parent_obj);
                    objects.obj6 = obj;
                    lv_obj_set_pos(obj, 0, 0);
                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                    lv_obj_clear_flag(obj, LV_OBJ_FLAG_CLICK_FOCUSABLE|LV_OBJ_FLAG_GESTURE_BUBBLE|LV_OBJ_FLAG_PRESS_LOCK|LV_OBJ_FLAG_SCROLLABLE|LV_OBJ_FLAG_SCROLL_CHAIN_HOR|LV_OBJ_FLAG_SCROLL_CHAIN_VER|LV_OBJ_FLAG_SCROLL_ELASTIC|LV_OBJ_FLAG_SCROLL_MOMENTUM|LV_OBJ_FLAG_SNAPPABLE);
                    lv_obj_set_style_align(obj, LV_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_bg_color(obj, lv_color_hex(0xffffffff), LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_bg_grad_dir(obj, LV_GRAD_DIR_VER, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_bg_grad_color(obj, lv_color_hex(0xff000000), LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_bg_grad_stop(obj, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_text_font(obj, &lv_font_montserrat_32, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_text_font(obj, &lv_font_montserrat_20, LV_PART_MAIN | LV_STATE_CHECKED);
                    lv_label_set_text(obj, "Acc");
                }
            }
        }
        {
            // lbl_Throttle_Page
            lv_obj_t *obj = lv_label_create(parent_obj);
            objects.lbl_throttle_page = obj;
            lv_obj_set_pos(obj, 140, 54);
            lv_obj_set_size(obj, 205, 30);
            lv_obj_clear_flag(obj, LV_OBJ_FLAG_CLICK_FOCUSABLE|LV_OBJ_FLAG_GESTURE_BUBBLE|LV_OBJ_FLAG_PRESS_LOCK|LV_OBJ_FLAG_SCROLLABLE|LV_OBJ_FLAG_SCROLL_CHAIN_HOR|LV_OBJ_FLAG_SCROLL_CHAIN_VER|LV_OBJ_FLAG_SCROLL_ELASTIC|LV_OBJ_FLAG_SCROLL_MOMENTUM|LV_OBJ_FLAG_SNAPPABLE);
            lv_obj_set_style_text_align(obj, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_font(obj, &lv_font_montserrat_24, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_color(obj, lv_color_hex(0xffffffff), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_label_set_text(obj, "Throttle");
        }
        {
            // swDir
            lv_obj_t *obj = lv_switch_create(parent_obj);
            objects.sw_dir = obj;
            lv_obj_set_pos(obj, 200, 640);
            lv_obj_set_size(obj, 80, 36);
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
            lv_obj_set_style_shadow_opa(obj, 128, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_shadow_width(obj, 10, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_shadow_ofs_x(obj, 5, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_shadow_ofs_y(obj, 5, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_shadow_spread(obj, 5, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_bg_img_recolor(obj, lv_color_hex(0xffff0000), LV_PART_MAIN | LV_STATE_CHECKED | LV_STATE_PRESSED);
            lv_obj_set_style_bg_img_recolor(obj, lv_color_hex(0xff00ff00), LV_PART_MAIN | LV_STATE_PRESSED);
            lv_obj_set_style_bg_color(obj, lv_color_hex(0xffff0000), LV_PART_MAIN | LV_STATE_CHECKED);
            lv_obj_set_style_shadow_width(obj, 10, LV_PART_MAIN | LV_STATE_CHECKED);
            lv_obj_set_style_shadow_ofs_x(obj, 5, LV_PART_MAIN | LV_STATE_CHECKED);
            lv_obj_set_style_shadow_ofs_y(obj, 5, LV_PART_MAIN | LV_STATE_CHECKED);
            lv_obj_set_style_shadow_spread(obj, 5, LV_PART_MAIN | LV_STATE_CHECKED);
            lv_obj_set_style_shadow_opa(obj, 127, LV_PART_MAIN | LV_STATE_CHECKED);
            lv_obj_set_style_bg_color(obj, lv_color_hex(0xffff0000), LV_PART_INDICATOR | LV_STATE_DEFAULT);
            lv_obj_set_style_bg_color(obj, lv_color_hex(0xffff0000), LV_PART_INDICATOR | LV_STATE_PRESSED);
            lv_obj_set_style_bg_color(obj, lv_color_hex(0xff00ff00), LV_PART_INDICATOR | LV_STATE_CHECKED);
            lv_obj_set_style_bg_color(obj, lv_color_hex(0xffff0000), LV_PART_INDICATOR | LV_STATE_CHECKED | LV_STATE_PRESSED);
        }
        {
            // ddLocos
            lv_obj_t *obj = lv_dropdown_create(parent_obj);
            objects.dd_locos = obj;
            lv_obj_set_pos(obj, 7, 120);
            lv_obj_set_size(obj, 460, 50);
            lv_dropdown_set_options(obj, "\n\n\n\n\n\n\n\n\n");
            lv_dropdown_set_selected(obj, 0);
            lv_obj_set_style_bg_color(obj, lv_color_hex(0xffc89600), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_shadow_width(obj, 10, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_shadow_ofs_x(obj, 5, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_shadow_ofs_y(obj, 5, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_shadow_spread(obj, 2, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_shadow_opa(obj, 192, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_arc_width(obj, 1, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_border_width(obj, 1, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_border_color(obj, lv_color_hex(0xff000000), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_font(obj, &lv_font_montserrat_24, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_color(obj, lv_color_hex(0xff000000), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_align(obj, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_top(obj, 10, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_bottom(obj, 4, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_left(obj, 4, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_right(obj, 4, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_row(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_column(obj, 4, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_font(obj, &lv_font_montserrat_24, LV_PART_SELECTED | LV_STATE_DEFAULT);
            lv_obj_set_style_text_line_space(obj, 0, LV_PART_SELECTED | LV_STATE_DEFAULT);
            {
                lv_obj_t *parent_obj = obj;
                {
                    lv_obj_t *obj = lv_dropdown_get_list(parent_obj);
                    lv_obj_set_style_text_font(obj, &lv_font_montserrat_24, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_max_height(obj, 400, LV_PART_MAIN | LV_STATE_DEFAULT);
                }
            }
        }
        {
            // btnEdit
            lv_obj_t *obj = lv_btn_create(parent_obj);
            objects.btn_edit = obj;
            lv_obj_set_pos(obj, 367, 630);
            lv_obj_set_size(obj, 100, 60);
            lv_obj_add_event_cb(obj, action_throttle_button, LV_EVENT_RELEASED, (void *)29);
            lv_obj_set_style_border_width(obj, 1, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_shadow_width(obj, 10, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_shadow_ofs_x(obj, 5, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_shadow_ofs_y(obj, 5, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_shadow_spread(obj, 2, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_shadow_color(obj, lv_color_hex(0xff000000), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_bg_color(obj, lv_color_hex(0xffffffff), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_bg_grad_dir(obj, LV_GRAD_DIR_VER, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_bg_grad_color(obj, lv_color_hex(0xff000000), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_bg_opa(obj, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_bg_color(obj, lv_color_hex(0xff000000), LV_PART_MAIN | LV_STATE_PRESSED);
            lv_obj_set_style_bg_grad_color(obj, lv_color_hex(0xffff0000), LV_PART_MAIN | LV_STATE_PRESSED);
            lv_obj_set_style_shadow_width(obj, 0, LV_PART_MAIN | LV_STATE_PRESSED);
            lv_obj_set_style_shadow_ofs_x(obj, 0, LV_PART_MAIN | LV_STATE_PRESSED);
            lv_obj_set_style_shadow_ofs_y(obj, 0, LV_PART_MAIN | LV_STATE_PRESSED);
            lv_obj_set_style_shadow_spread(obj, 0, LV_PART_MAIN | LV_STATE_PRESSED);
            {
                lv_obj_t *parent_obj = obj;
                {
                    lv_obj_t *obj = lv_label_create(parent_obj);
                    lv_obj_set_pos(obj, 0, 0);
                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                    lv_obj_set_style_align(obj, LV_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_text_font(obj, &lv_font_montserrat_24, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_text_font(obj, &lv_font_montserrat_24, LV_PART_MAIN | LV_STATE_CHECKED);
                    lv_label_set_text(obj, "Funcs");
                }
            }
        }
        {
            lv_obj_t *obj = lv_label_create(parent_obj);
            objects.obj7 = obj;
            lv_obj_set_pos(obj, 11, 192);
            lv_obj_set_size(obj, LV_SIZE_CONTENT, 32);
            lv_obj_set_style_text_color(obj, lv_color_hex(0xffffffff), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_font(obj, &lv_font_montserrat_24, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_label_set_text(obj, "Address:");
        }
        {
            // lblAddress
            lv_obj_t *obj = lv_label_create(parent_obj);
            objects.lbl_address = obj;
            lv_obj_set_pos(obj, 122, 188);
            lv_obj_set_size(obj, 100, LV_SIZE_CONTENT);
            lv_obj_set_style_text_font(obj, &lv_font_montserrat_36, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_color(obj, lv_color_hex(0xff000000), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_align(obj, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_label_set_text(obj, "");
        }
        {
            // Functions_Mtx
            lv_obj_t *obj = lv_btnmatrix_create(parent_obj);
            objects.functions_mtx = obj;
            lv_obj_set_pos(obj, -1, 223);
            lv_obj_set_size(obj, 480, 395);
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
            lv_obj_set_style_pad_top(obj, 9, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_bottom(obj, 9, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_left(obj, 5, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_right(obj, 5, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_column(obj, 160, LV_PART_MAIN | LV_STATE_DEFAULT);
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
            lv_obj_set_style_text_font(obj, &lv_font_montserrat_24, LV_PART_ITEMS | LV_STATE_DEFAULT);
            lv_obj_set_style_bg_color(obj, lv_color_hex(0xffffff00), LV_PART_ITEMS | LV_STATE_CHECKED);
            lv_obj_set_style_shadow_width(obj, 0, LV_PART_ITEMS | LV_STATE_CHECKED);
            lv_obj_set_style_shadow_ofs_x(obj, 0, LV_PART_ITEMS | LV_STATE_CHECKED);
            lv_obj_set_style_shadow_ofs_y(obj, 0, LV_PART_ITEMS | LV_STATE_CHECKED);
            lv_obj_set_style_shadow_spread(obj, 0, LV_PART_ITEMS | LV_STATE_CHECKED);
            lv_obj_set_style_bg_grad_dir(obj, LV_GRAD_DIR_NONE, LV_PART_ITEMS | LV_STATE_CHECKED);
            lv_obj_set_style_text_color(obj, lv_color_hex(0xff000000), LV_PART_ITEMS | LV_STATE_CHECKED);
            lv_obj_set_style_bg_color(obj, lv_color_hex(0xffffff00), LV_PART_ITEMS | LV_STATE_PRESSED);
            lv_obj_set_style_bg_grad_dir(obj, LV_GRAD_DIR_NONE, LV_PART_ITEMS | LV_STATE_PRESSED);
            lv_obj_set_style_shadow_width(obj, 0, LV_PART_ITEMS | LV_STATE_PRESSED);
            lv_obj_set_style_shadow_ofs_x(obj, 0, LV_PART_ITEMS | LV_STATE_PRESSED);
            lv_obj_set_style_shadow_ofs_y(obj, 0, LV_PART_ITEMS | LV_STATE_PRESSED);
            lv_obj_set_style_shadow_spread(obj, 0, LV_PART_ITEMS | LV_STATE_PRESSED);
            lv_obj_set_style_text_color(obj, lv_color_hex(0xff000000), LV_PART_ITEMS | LV_STATE_PRESSED);
        }
        {
            // Slider
            lv_obj_t *obj = lv_slider_create(parent_obj);
            objects.slider = obj;
            lv_obj_set_pos(obj, 222, 235);
            lv_obj_set_size(obj, 30, 333);
            lv_slider_set_range(obj, 0, 126);
            lv_obj_add_event_cb(obj, action_throttle_button, LV_EVENT_RELEASED, (void *)3);
            lv_obj_set_scroll_dir(obj, LV_DIR_NONE);
            lv_obj_set_style_align(obj, LV_ALIGN_CENTER, LV_PART_KNOB | LV_STATE_DEFAULT);
            lv_obj_set_style_transform_width(obj, 15, LV_PART_KNOB | LV_STATE_DEFAULT);
            lv_obj_set_style_transform_height(obj, 0, LV_PART_KNOB | LV_STATE_DEFAULT);
            lv_obj_set_style_translate_y(obj, 0, LV_PART_KNOB | LV_STATE_DEFAULT);
            lv_obj_set_style_bg_color(obj, lv_color_hex(0xff2196f3), LV_PART_KNOB | LV_STATE_DEFAULT);
            lv_obj_set_style_bg_grad_dir(obj, LV_GRAD_DIR_VER, LV_PART_KNOB | LV_STATE_DEFAULT);
            lv_obj_set_style_shadow_width(obj, 10, LV_PART_KNOB | LV_STATE_DEFAULT);
            lv_obj_set_style_shadow_ofs_x(obj, 5, LV_PART_KNOB | LV_STATE_DEFAULT);
            lv_obj_set_style_shadow_ofs_y(obj, 5, LV_PART_KNOB | LV_STATE_DEFAULT);
            lv_obj_set_style_shadow_spread(obj, 2, LV_PART_KNOB | LV_STATE_DEFAULT);
            lv_obj_set_style_shadow_opa(obj, 127, LV_PART_KNOB | LV_STATE_DEFAULT);
            lv_obj_set_style_transform_width(obj, 15, LV_PART_KNOB | LV_STATE_PRESSED);
            lv_obj_set_style_bg_color(obj, lv_color_hex(0xffff0000), LV_PART_INDICATOR | LV_STATE_DEFAULT);
            lv_obj_set_style_bg_grad_dir(obj, LV_GRAD_DIR_VER, LV_PART_INDICATOR | LV_STATE_DEFAULT);
            lv_obj_set_style_bg_grad_color(obj, lv_color_hex(0xff300000), LV_PART_INDICATOR | LV_STATE_DEFAULT);
            lv_obj_set_style_bg_color(obj, lv_color_hex(0xffe8d776), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_shadow_width(obj, 10, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_shadow_ofs_x(obj, 5, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_shadow_ofs_y(obj, 5, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_shadow_spread(obj, 5, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_shadow_opa(obj, 127, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_border_color(obj, lv_color_hex(0xff000000), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_border_width(obj, 1, LV_PART_MAIN | LV_STATE_DEFAULT);
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
            lv_obj_set_pos(obj, 368, 188);
            lv_obj_set_size(obj, 90, LV_SIZE_CONTENT);
            lv_obj_set_style_text_font(obj, &lv_font_montserrat_36, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_align(obj, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_color(obj, lv_color_hex(0xff000000), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_label_set_text(obj, "");
        }
        {
            // ta_guest_address
            lv_obj_t *obj = lv_textarea_create(parent_obj);
            objects.ta_guest_address = obj;
            lv_obj_set_pos(obj, 11, 630);
            lv_obj_set_size(obj, 100, 60);
            lv_textarea_set_max_length(obj, 128);
            lv_textarea_set_placeholder_text(obj, "Guest");
            lv_textarea_set_one_line(obj, true);
            lv_textarea_set_password_mode(obj, false);
            lv_obj_add_event_cb(obj, event_handler_checked_cb_throttle_ta_guest_address, LV_EVENT_VALUE_CHANGED, (void *)1);
            lv_obj_add_event_cb(obj, event_handler_unchecked_cb_throttle_ta_guest_address, LV_EVENT_VALUE_CHANGED, (void *)2);
            lv_obj_add_flag(obj, LV_OBJ_FLAG_CHECKABLE);
            lv_obj_set_style_text_font(obj, &lv_font_montserrat_24, LV_PART_MAIN | LV_STATE_CHECKED);
            lv_obj_set_style_text_align(obj, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_CHECKED);
            lv_obj_set_style_bg_color(obj, lv_color_hex(0xffffff00), LV_PART_MAIN | LV_STATE_CHECKED);
            lv_obj_set_style_bg_grad_dir(obj, LV_GRAD_DIR_NONE, LV_PART_MAIN | LV_STATE_CHECKED);
            lv_obj_set_style_shadow_width(obj, 0, LV_PART_MAIN | LV_STATE_CHECKED);
            lv_obj_set_style_shadow_ofs_x(obj, 0, LV_PART_MAIN | LV_STATE_CHECKED);
            lv_obj_set_style_shadow_ofs_y(obj, 0, LV_PART_MAIN | LV_STATE_CHECKED);
            lv_obj_set_style_shadow_spread(obj, 0, LV_PART_MAIN | LV_STATE_CHECKED);
            lv_obj_set_style_text_color(obj, lv_color_hex(0xff000000), LV_PART_MAIN | LV_STATE_CHECKED);
            lv_obj_set_style_text_font(obj, &lv_font_montserrat_24, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_align(obj, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_bg_color(obj, lv_color_hex(0xffffffff), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_bg_grad_dir(obj, LV_GRAD_DIR_VER, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_bg_grad_color(obj, lv_color_hex(0xff000000), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_border_width(obj, 1, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_border_color(obj, lv_color_hex(0xff000000), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_shadow_width(obj, 10, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_shadow_ofs_x(obj, 5, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_shadow_ofs_y(obj, 5, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_shadow_spread(obj, 3, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_shadow_opa(obj, 127, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_color(obj, lv_color_hex(0xffffffff), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_top(obj, 16, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_bottom(obj, 16, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_left(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
        }
        {
            // kbd_guest
            lv_obj_t *obj = lv_keyboard_create(parent_obj);
            objects.kbd_guest = obj;
            lv_obj_set_pos(obj, 8, 250);
            lv_obj_set_size(obj, 465, 189);
            lv_keyboard_set_mode(obj, LV_KEYBOARD_MODE_NUMBER);
            lv_obj_add_flag(obj, LV_OBJ_FLAG_HIDDEN);
            lv_obj_set_style_align(obj, LV_ALIGN_DEFAULT, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_font(obj, &lv_font_montserrat_24, LV_PART_MAIN | LV_STATE_DEFAULT);
        }
        {
            lv_obj_t *obj = lv_label_create(parent_obj);
            objects.obj8 = obj;
            lv_obj_set_pos(obj, 271, 192);
            lv_obj_set_size(obj, LV_SIZE_CONTENT, 32);
            lv_obj_set_style_text_color(obj, lv_color_hex(0xffffffff), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_font(obj, &lv_font_montserrat_24, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_label_set_text(obj, "Speed:");
        }
        {
            lv_obj_t *obj = lv_btn_create(parent_obj);
            objects.obj9 = obj;
            lv_obj_set_pos(obj, 126, 630);
            lv_obj_set_size(obj, 60, 60);
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
                    lv_obj_set_style_text_font(obj, &lv_font_montserrat_36, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_label_set_text(obj, "-");
                }
            }
        }
        {
            lv_obj_t *obj = lv_btn_create(parent_obj);
            objects.obj10 = obj;
            lv_obj_set_pos(obj, 296, 630);
            lv_obj_set_size(obj, 60, 60);
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
                    lv_obj_set_style_text_font(obj, &lv_font_montserrat_36, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_label_set_text(obj, "+");
                }
            }
        }
    }
    lv_keyboard_set_textarea(objects.kbd_guest, objects.ta_guest_address);
    
    tick_screen_throttle();
}

void tick_screen_throttle() {
}

void create_screen_roster() {
    lv_obj_t *obj = lv_obj_create(0);
    objects.roster = obj;
    lv_obj_set_pos(obj, 0, 0);
    lv_obj_set_size(obj, 480, 800);
    lv_obj_set_style_bg_color(obj, lv_color_hex(0xffc89600), LV_PART_MAIN | LV_STATE_DEFAULT);
    {
        lv_obj_t *parent_obj = obj;
        {
            // btnCancelEditLoco
            lv_obj_t *obj = lv_btn_create(parent_obj);
            objects.btn_cancel_edit_loco = obj;
            lv_obj_set_pos(obj, 11, 711);
            lv_obj_set_size(obj, 145, 80);
            lv_obj_add_event_cb(obj, action_roster_button, LV_EVENT_RELEASED, (void *)30);
            lv_obj_clear_flag(obj, LV_OBJ_FLAG_CLICK_FOCUSABLE|LV_OBJ_FLAG_GESTURE_BUBBLE|LV_OBJ_FLAG_PRESS_LOCK|LV_OBJ_FLAG_SCROLL_CHAIN_HOR|LV_OBJ_FLAG_SCROLL_CHAIN_VER|LV_OBJ_FLAG_SCROLL_ELASTIC|LV_OBJ_FLAG_SCROLL_MOMENTUM|LV_OBJ_FLAG_SNAPPABLE);
            lv_obj_set_style_bg_color(obj, lv_color_hex(0xffffffff), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_bg_grad_dir(obj, LV_GRAD_DIR_VER, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_bg_grad_color(obj, lv_color_hex(0xff000000), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_outline_width(obj, 1, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_font(obj, &lv_font_montserrat_24, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_shadow_width(obj, 10, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_shadow_ofs_x(obj, 5, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_shadow_ofs_y(obj, 5, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_shadow_spread(obj, 3, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_shadow_color(obj, lv_color_hex(0xff000000), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_shadow_opa(obj, 127, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_bg_color(obj, lv_color_hex(0xff000000), LV_PART_MAIN | LV_STATE_PRESSED);
            lv_obj_set_style_bg_grad_dir(obj, LV_GRAD_DIR_VER, LV_PART_MAIN | LV_STATE_PRESSED);
            lv_obj_set_style_bg_grad_color(obj, lv_color_hex(0xfffff200), LV_PART_MAIN | LV_STATE_PRESSED);
            lv_obj_set_style_text_color(obj, lv_color_hex(0xff000000), LV_PART_MAIN | LV_STATE_PRESSED);
            lv_obj_set_style_shadow_width(obj, 0, LV_PART_MAIN | LV_STATE_PRESSED);
            lv_obj_set_style_shadow_ofs_y(obj, 0, LV_PART_MAIN | LV_STATE_PRESSED);
            lv_obj_set_style_shadow_ofs_x(obj, 0, LV_PART_MAIN | LV_STATE_PRESSED);
            lv_obj_set_style_shadow_spread(obj, 0, LV_PART_MAIN | LV_STATE_PRESSED);
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
                    lv_obj_set_style_text_font(obj, &lv_font_montserrat_32, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_text_font(obj, &lv_font_montserrat_20, LV_PART_MAIN | LV_STATE_CHECKED);
                    lv_label_set_text(obj, "Cancel");
                }
            }
        }
        {
            // btnEditLoco
            lv_obj_t *obj = lv_btn_create(parent_obj);
            objects.btn_edit_loco = obj;
            lv_obj_set_pos(obj, 168, 711);
            lv_obj_set_size(obj, 145, 80);
            lv_obj_add_event_cb(obj, event_handler_checked_cb_roster_btn_edit_loco, LV_EVENT_VALUE_CHANGED, (void *)31);
            lv_obj_add_event_cb(obj, event_handler_unchecked_cb_roster_btn_edit_loco, LV_EVENT_VALUE_CHANGED, (void *)28);
            lv_obj_add_flag(obj, LV_OBJ_FLAG_CHECKABLE);
            lv_obj_clear_flag(obj, LV_OBJ_FLAG_CLICK_FOCUSABLE|LV_OBJ_FLAG_GESTURE_BUBBLE|LV_OBJ_FLAG_PRESS_LOCK|LV_OBJ_FLAG_SCROLL_CHAIN_HOR|LV_OBJ_FLAG_SCROLL_CHAIN_VER|LV_OBJ_FLAG_SCROLL_ELASTIC|LV_OBJ_FLAG_SCROLL_MOMENTUM|LV_OBJ_FLAG_SNAPPABLE);
            lv_obj_set_style_bg_color(obj, lv_color_hex(0xffffffff), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_bg_grad_dir(obj, LV_GRAD_DIR_VER, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_bg_grad_color(obj, lv_color_hex(0xff000000), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_outline_width(obj, 1, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_font(obj, &lv_font_montserrat_24, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_shadow_width(obj, 10, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_shadow_ofs_x(obj, 5, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_shadow_ofs_y(obj, 5, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_shadow_spread(obj, 3, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_shadow_color(obj, lv_color_hex(0xff000000), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_shadow_opa(obj, 127, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_bg_color(obj, lv_color_hex(0xff000000), LV_PART_MAIN | LV_STATE_PRESSED);
            lv_obj_set_style_bg_grad_dir(obj, LV_GRAD_DIR_VER, LV_PART_MAIN | LV_STATE_PRESSED);
            lv_obj_set_style_bg_grad_color(obj, lv_color_hex(0xfffff200), LV_PART_MAIN | LV_STATE_PRESSED);
            lv_obj_set_style_text_color(obj, lv_color_hex(0xff000000), LV_PART_MAIN | LV_STATE_PRESSED);
            lv_obj_set_style_shadow_width(obj, 0, LV_PART_MAIN | LV_STATE_PRESSED);
            lv_obj_set_style_shadow_ofs_y(obj, 0, LV_PART_MAIN | LV_STATE_PRESSED);
            lv_obj_set_style_shadow_ofs_x(obj, 0, LV_PART_MAIN | LV_STATE_PRESSED);
            lv_obj_set_style_shadow_spread(obj, 0, LV_PART_MAIN | LV_STATE_PRESSED);
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
                    lv_obj_set_style_text_font(obj, &lv_font_montserrat_32, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_text_font(obj, &lv_font_montserrat_20, LV_PART_MAIN | LV_STATE_CHECKED);
                    lv_label_set_text(obj, "Edit");
                }
            }
        }
        {
            // btnSelectLoco
            lv_obj_t *obj = lv_btn_create(parent_obj);
            objects.btn_select_loco = obj;
            lv_obj_set_pos(obj, 325, 711);
            lv_obj_set_size(obj, 145, 80);
            lv_obj_add_event_cb(obj, event_handler_checked_cb_roster_btn_select_loco, LV_EVENT_VALUE_CHANGED, (void *)32);
            lv_obj_add_event_cb(obj, event_handler_unchecked_cb_roster_btn_select_loco, LV_EVENT_VALUE_CHANGED, (void *)29);
            lv_obj_add_flag(obj, LV_OBJ_FLAG_CHECKABLE);
            lv_obj_clear_flag(obj, LV_OBJ_FLAG_CLICK_FOCUSABLE|LV_OBJ_FLAG_GESTURE_BUBBLE|LV_OBJ_FLAG_PRESS_LOCK|LV_OBJ_FLAG_SCROLL_CHAIN_HOR|LV_OBJ_FLAG_SCROLL_CHAIN_VER|LV_OBJ_FLAG_SCROLL_ELASTIC|LV_OBJ_FLAG_SCROLL_MOMENTUM|LV_OBJ_FLAG_SNAPPABLE);
            lv_obj_set_style_bg_color(obj, lv_color_hex(0xffffffff), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_bg_grad_dir(obj, LV_GRAD_DIR_VER, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_bg_grad_color(obj, lv_color_hex(0xff000000), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_outline_width(obj, 1, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_font(obj, &lv_font_montserrat_24, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_shadow_width(obj, 10, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_shadow_ofs_x(obj, 5, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_shadow_ofs_y(obj, 5, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_shadow_spread(obj, 3, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_shadow_color(obj, lv_color_hex(0xff000000), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_shadow_opa(obj, 127, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_bg_color(obj, lv_color_hex(0xff000000), LV_PART_MAIN | LV_STATE_PRESSED);
            lv_obj_set_style_bg_grad_dir(obj, LV_GRAD_DIR_VER, LV_PART_MAIN | LV_STATE_PRESSED);
            lv_obj_set_style_bg_grad_color(obj, lv_color_hex(0xfffff200), LV_PART_MAIN | LV_STATE_PRESSED);
            lv_obj_set_style_text_color(obj, lv_color_hex(0xff000000), LV_PART_MAIN | LV_STATE_PRESSED);
            lv_obj_set_style_shadow_width(obj, 0, LV_PART_MAIN | LV_STATE_PRESSED);
            lv_obj_set_style_shadow_ofs_y(obj, 0, LV_PART_MAIN | LV_STATE_PRESSED);
            lv_obj_set_style_shadow_ofs_x(obj, 0, LV_PART_MAIN | LV_STATE_PRESSED);
            lv_obj_set_style_shadow_spread(obj, 0, LV_PART_MAIN | LV_STATE_PRESSED);
            lv_obj_set_style_text_font(obj, &lv_font_montserrat_20, LV_PART_MAIN | LV_STATE_CHECKED);
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
                    lv_obj_set_style_text_font(obj, &lv_font_montserrat_32, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_text_font(obj, &lv_font_montserrat_20, LV_PART_MAIN | LV_STATE_CHECKED);
                    lv_label_set_text(obj, "Select");
                }
            }
        }
        {
            lv_obj_t *obj = lv_label_create(parent_obj);
            objects.obj14 = obj;
            lv_obj_set_pos(obj, 140, 54);
            lv_obj_set_size(obj, 205, 30);
            lv_obj_clear_flag(obj, LV_OBJ_FLAG_CLICK_FOCUSABLE|LV_OBJ_FLAG_GESTURE_BUBBLE|LV_OBJ_FLAG_PRESS_LOCK|LV_OBJ_FLAG_SCROLLABLE|LV_OBJ_FLAG_SCROLL_CHAIN_HOR|LV_OBJ_FLAG_SCROLL_CHAIN_VER|LV_OBJ_FLAG_SCROLL_ELASTIC|LV_OBJ_FLAG_SCROLL_MOMENTUM|LV_OBJ_FLAG_SNAPPABLE);
            lv_obj_set_style_text_align(obj, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_font(obj, &lv_font_montserrat_24, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_color(obj, lv_color_hex(0xffffffff), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_label_set_text(obj, "Roster");
        }
        {
            // tblRoster
            lv_obj_t *obj = lv_table_create(parent_obj);
            objects.tbl_roster = obj;
            lv_obj_set_pos(obj, 11, 106);
            lv_obj_set_size(obj, 460, 593);
            lv_obj_set_style_text_font(obj, &lv_font_montserrat_24, LV_PART_MAIN | LV_STATE_DEFAULT);
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
    lv_obj_set_size(obj, 480, 800);
    lv_obj_set_style_bg_color(obj, lv_color_hex(0xffc89600), LV_PART_MAIN | LV_STATE_DEFAULT);
    {
        lv_obj_t *parent_obj = obj;
        {
            // CancelButton_3
            lv_obj_t *obj = lv_btn_create(parent_obj);
            objects.cancel_button_3 = obj;
            lv_obj_set_pos(obj, 11, 710);
            lv_obj_set_size(obj, 145, 80);
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
            lv_obj_set_style_shadow_opa(obj, 127, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_shadow_color(obj, lv_color_hex(0xff000000), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_bg_color(obj, lv_color_hex(0xff000000), LV_PART_MAIN | LV_STATE_PRESSED);
            lv_obj_set_style_bg_grad_dir(obj, LV_GRAD_DIR_VER, LV_PART_MAIN | LV_STATE_PRESSED);
            lv_obj_set_style_bg_grad_color(obj, lv_color_hex(0xfffff200), LV_PART_MAIN | LV_STATE_PRESSED);
            lv_obj_set_style_text_color(obj, lv_color_hex(0xff000000), LV_PART_MAIN | LV_STATE_PRESSED);
            lv_obj_set_style_text_font(obj, &lv_font_montserrat_20, LV_PART_MAIN | LV_STATE_CHECKED);
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
                    lv_obj_set_style_text_font(obj, &lv_font_montserrat_32, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_text_font(obj, &lv_font_montserrat_20, LV_PART_MAIN | LV_STATE_CHECKED);
                    lv_label_set_text(obj, "Cancel");
                }
            }
        }
        {
            // ProgButton_3
            lv_obj_t *obj = lv_btn_create(parent_obj);
            objects.prog_button_3 = obj;
            lv_obj_set_pos(obj, 167, 710);
            lv_obj_set_size(obj, 145, 80);
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
            lv_obj_set_style_shadow_opa(obj, 127, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_shadow_color(obj, lv_color_hex(0xff000000), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_bg_color(obj, lv_color_hex(0xff000000), LV_PART_MAIN | LV_STATE_PRESSED);
            lv_obj_set_style_bg_grad_dir(obj, LV_GRAD_DIR_VER, LV_PART_MAIN | LV_STATE_PRESSED);
            lv_obj_set_style_bg_grad_color(obj, lv_color_hex(0xfffff200), LV_PART_MAIN | LV_STATE_PRESSED);
            lv_obj_set_style_text_color(obj, lv_color_hex(0xff000000), LV_PART_MAIN | LV_STATE_PRESSED);
            lv_obj_set_style_text_font(obj, &lv_font_montserrat_20, LV_PART_MAIN | LV_STATE_CHECKED);
            {
                lv_obj_t *parent_obj = obj;
                {
                    lv_obj_t *obj = lv_label_create(parent_obj);
                    objects.obj16 = obj;
                    lv_obj_set_pos(obj, 0, 0);
                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                    lv_obj_clear_flag(obj, LV_OBJ_FLAG_CLICK_FOCUSABLE|LV_OBJ_FLAG_GESTURE_BUBBLE|LV_OBJ_FLAG_PRESS_LOCK|LV_OBJ_FLAG_SCROLLABLE|LV_OBJ_FLAG_SCROLL_CHAIN_HOR|LV_OBJ_FLAG_SCROLL_CHAIN_VER|LV_OBJ_FLAG_SCROLL_ELASTIC|LV_OBJ_FLAG_SCROLL_MOMENTUM|LV_OBJ_FLAG_SNAPPABLE);
                    lv_obj_set_style_align(obj, LV_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_bg_color(obj, lv_color_hex(0xffffffff), LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_bg_grad_dir(obj, LV_GRAD_DIR_VER, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_bg_grad_color(obj, lv_color_hex(0xff000000), LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_bg_grad_stop(obj, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_text_font(obj, &lv_font_montserrat_32, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_text_font(obj, &lv_font_montserrat_20, LV_PART_MAIN | LV_STATE_CHECKED);
                    lv_label_set_text(obj, "Prog");
                }
            }
        }
        {
            // DoneButton_3
            lv_obj_t *obj = lv_btn_create(parent_obj);
            objects.done_button_3 = obj;
            lv_obj_set_pos(obj, 325, 710);
            lv_obj_set_size(obj, 145, 80);
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
            lv_obj_set_style_shadow_opa(obj, 127, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_shadow_color(obj, lv_color_hex(0xff000000), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_bg_color(obj, lv_color_hex(0xff000000), LV_PART_MAIN | LV_STATE_PRESSED);
            lv_obj_set_style_bg_grad_dir(obj, LV_GRAD_DIR_VER, LV_PART_MAIN | LV_STATE_PRESSED);
            lv_obj_set_style_bg_grad_color(obj, lv_color_hex(0xfffff200), LV_PART_MAIN | LV_STATE_PRESSED);
            lv_obj_set_style_text_color(obj, lv_color_hex(0xff000000), LV_PART_MAIN | LV_STATE_PRESSED);
            lv_obj_set_style_text_font(obj, &lv_font_montserrat_20, LV_PART_MAIN | LV_STATE_CHECKED);
            {
                lv_obj_t *parent_obj = obj;
                {
                    lv_obj_t *obj = lv_label_create(parent_obj);
                    objects.obj17 = obj;
                    lv_obj_set_pos(obj, 0, 0);
                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                    lv_obj_clear_flag(obj, LV_OBJ_FLAG_CLICK_FOCUSABLE|LV_OBJ_FLAG_GESTURE_BUBBLE|LV_OBJ_FLAG_PRESS_LOCK|LV_OBJ_FLAG_SCROLLABLE|LV_OBJ_FLAG_SCROLL_CHAIN_HOR|LV_OBJ_FLAG_SCROLL_CHAIN_VER|LV_OBJ_FLAG_SCROLL_ELASTIC|LV_OBJ_FLAG_SCROLL_MOMENTUM|LV_OBJ_FLAG_SNAPPABLE);
                    lv_obj_set_style_align(obj, LV_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_bg_color(obj, lv_color_hex(0xffffffff), LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_bg_grad_dir(obj, LV_GRAD_DIR_VER, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_bg_grad_color(obj, lv_color_hex(0xff000000), LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_bg_grad_stop(obj, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_text_font(obj, &lv_font_montserrat_32, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_text_font(obj, &lv_font_montserrat_20, LV_PART_MAIN | LV_STATE_CHECKED);
                    lv_label_set_text(obj, "Done");
                }
            }
        }
        {
            lv_obj_t *obj = lv_label_create(parent_obj);
            objects.obj18 = obj;
            lv_obj_set_pos(obj, 140, 54);
            lv_obj_set_size(obj, 205, 30);
            lv_obj_clear_flag(obj, LV_OBJ_FLAG_CLICK_FOCUSABLE|LV_OBJ_FLAG_GESTURE_BUBBLE|LV_OBJ_FLAG_PRESS_LOCK|LV_OBJ_FLAG_SCROLLABLE|LV_OBJ_FLAG_SCROLL_CHAIN_HOR|LV_OBJ_FLAG_SCROLL_CHAIN_VER|LV_OBJ_FLAG_SCROLL_ELASTIC|LV_OBJ_FLAG_SCROLL_MOMENTUM|LV_OBJ_FLAG_SNAPPABLE);
            lv_obj_set_style_text_align(obj, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_font(obj, &lv_font_montserrat_24, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_color(obj, lv_color_hex(0xffffffff), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_label_set_text(obj, "Edit Loco");
        }
        {
            lv_obj_t *obj = lv_label_create(parent_obj);
            objects.obj19 = obj;
            lv_obj_set_pos(obj, 65, 190);
            lv_obj_set_size(obj, LV_SIZE_CONTENT, 46);
            lv_obj_set_style_text_font(obj, &lv_font_montserrat_24, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_bg_color(obj, lv_color_hex(0xffc89600), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_top(obj, 10, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_left(obj, 8, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_radius(obj, 7, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_label_set_text(obj, "Loco Address:");
        }
        {
            // taAddress
            lv_obj_t *obj = lv_textarea_create(parent_obj);
            objects.ta_address = obj;
            lv_obj_set_pos(obj, 260, 190);
            lv_obj_set_size(obj, 100, 40);
            lv_textarea_set_max_length(obj, 4);
            lv_textarea_set_one_line(obj, true);
            lv_textarea_set_password_mode(obj, false);
            lv_obj_set_style_pad_top(obj, 8, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_bottom(obj, 8, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_left(obj, 1, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_right(obj, 1, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_align(obj, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_font(obj, &lv_font_montserrat_28, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_shadow_width(obj, 10, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_shadow_ofs_x(obj, 5, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_shadow_ofs_y(obj, 5, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_shadow_spread(obj, 4, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_shadow_opa(obj, 127, LV_PART_MAIN | LV_STATE_DEFAULT);
        }
        {
            // taName
            lv_obj_t *obj = lv_textarea_create(parent_obj);
            objects.ta_name = obj;
            lv_obj_set_pos(obj, 7, 120);
            lv_obj_set_size(obj, 460, 50);
            lv_textarea_set_max_length(obj, 30);
            lv_textarea_set_placeholder_text(obj, "Loco Name");
            lv_textarea_set_one_line(obj, true);
            lv_textarea_set_password_mode(obj, false);
            lv_obj_set_style_border_color(obj, lv_color_hex(0xff000000), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_border_width(obj, 1, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_font(obj, &lv_font_montserrat_24, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_shadow_width(obj, 10, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_shadow_ofs_x(obj, 5, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_shadow_ofs_y(obj, 5, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_shadow_spread(obj, 4, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_shadow_color(obj, lv_color_hex(0xff000000), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_shadow_opa(obj, 127, LV_PART_MAIN | LV_STATE_DEFAULT);
        }
        {
            // taFName
            lv_obj_t *obj = lv_textarea_create(parent_obj);
            objects.ta_fname = obj;
            lv_obj_set_pos(obj, 106, 280);
            lv_obj_set_size(obj, 203, 50);
            lv_textarea_set_max_length(obj, 10);
            lv_textarea_set_placeholder_text(obj, "Name");
            lv_textarea_set_one_line(obj, true);
            lv_textarea_set_password_mode(obj, false);
            lv_obj_add_flag(obj, LV_OBJ_FLAG_CHECKABLE);
            lv_obj_set_style_text_font(obj, &lv_font_montserrat_24, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_top(obj, 4, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_bottom(obj, 4, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_left(obj, 1, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_right(obj, 1, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_align(obj, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_border_color(obj, lv_color_hex(0xff000000), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_border_width(obj, 1, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_shadow_width(obj, 10, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_shadow_ofs_x(obj, 5, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_shadow_ofs_y(obj, 5, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_shadow_spread(obj, 4, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_shadow_color(obj, lv_color_hex(0xff000000), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_shadow_opa(obj, 127, LV_PART_MAIN | LV_STATE_DEFAULT);
        }
        {
            // fOption
            lv_obj_t *obj = lv_checkbox_create(parent_obj);
            objects.f_option = obj;
            lv_obj_set_pos(obj, 320, 288);
            lv_obj_set_size(obj, 22, 22);
            lv_checkbox_set_text(obj, "");
            lv_obj_set_style_border_width(obj, 1, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_shadow_width(obj, 10, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_shadow_ofs_x(obj, 5, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_shadow_ofs_y(obj, 5, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_shadow_spread(obj, 4, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_shadow_color(obj, lv_color_hex(0xff000000), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_shadow_opa(obj, 127, LV_PART_MAIN | LV_STATE_DEFAULT);
        }
        {
            // taFNum
            lv_obj_t *obj = lv_textarea_create(parent_obj);
            objects.ta_fnum = obj;
            lv_obj_set_pos(obj, 38, 281);
            lv_obj_set_size(obj, 50, 50);
            lv_textarea_set_accepted_chars(obj, "0,1,2,3,4,5,6,7,8,9");
            lv_textarea_set_max_length(obj, 3);
            lv_textarea_set_placeholder_text(obj, "F");
            lv_textarea_set_one_line(obj, true);
            lv_textarea_set_password_mode(obj, false);
            lv_obj_add_flag(obj, LV_OBJ_FLAG_CHECKABLE);
            lv_obj_set_style_text_font(obj, &lv_font_montserrat_24, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_top(obj, 4, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_bottom(obj, 4, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_align(obj, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_left(obj, 1, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_right(obj, 1, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_border_color(obj, lv_color_hex(0xff000000), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_border_width(obj, 1, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_shadow_width(obj, 10, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_shadow_ofs_x(obj, 5, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_shadow_ofs_y(obj, 5, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_shadow_spread(obj, 4, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_shadow_color(obj, lv_color_hex(0xff000000), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_shadow_opa(obj, 127, LV_PART_MAIN | LV_STATE_DEFAULT);
        }
        {
            lv_obj_t *obj = lv_label_create(parent_obj);
            lv_obj_set_pos(obj, 350, 288);
            lv_obj_set_size(obj, 124, 20);
            lv_obj_set_style_text_font(obj, &lv_font_montserrat_20, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_label_set_text(obj, "Momentary\n");
        }
        {
            // btnS0
            lv_obj_t *obj = lv_btn_create(parent_obj);
            objects.btn_s0 = obj;
            lv_obj_set_pos(obj, 20, 350);
            lv_obj_set_size(obj, 200, 60);
            lv_obj_add_event_cb(obj, event_handler_checked_cb_edit_loco_btn_s0, LV_EVENT_VALUE_CHANGED, (void *)0);
            lv_obj_add_event_cb(obj, event_handler_unchecked_cb_edit_loco_btn_s0, LV_EVENT_VALUE_CHANGED, (void *)0);
            lv_obj_add_flag(obj, LV_OBJ_FLAG_CHECKABLE);
            lv_obj_set_style_border_width(obj, 1, LV_PART_MAIN | LV_STATE_CHECKED);
            lv_obj_set_style_border_color(obj, lv_color_hex(0xff000000), LV_PART_MAIN | LV_STATE_CHECKED);
            lv_obj_set_style_bg_color(obj, lv_color_hex(0xffffff00), LV_PART_MAIN | LV_STATE_CHECKED);
            lv_obj_set_style_text_color(obj, lv_color_hex(0xff000000), LV_PART_MAIN | LV_STATE_CHECKED);
            lv_obj_set_style_bg_color(obj, lv_color_hex(0xffc89600), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_border_color(obj, lv_color_hex(0xff000000), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_border_width(obj, 1, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_bg_grad_dir(obj, LV_GRAD_DIR_NONE, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_shadow_ofs_y(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_shadow_width(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_color(obj, lv_color_hex(0xffffffff), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_font(obj, &lv_font_montserrat_24, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_left(obj, 70, LV_PART_MAIN | LV_STATE_DEFAULT);
            {
                lv_obj_t *parent_obj = obj;
                {
                    // lblS0
                    lv_obj_t *obj = lv_label_create(parent_obj);
                    objects.lbl_s0 = obj;
                    lv_obj_set_pos(obj, 0, 0);
                    lv_obj_set_size(obj, 140, LV_SIZE_CONTENT);
                    lv_obj_set_style_align(obj, LV_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_text_align(obj, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_text_color(obj, lv_color_hex(0xffffffff), LV_PART_MAIN | LV_STATE_CHECKED);
                    lv_label_set_text(obj, "");
                }
                {
                    // fn_0
                    lv_obj_t *obj = lv_label_create(parent_obj);
                    objects.fn_0 = obj;
                    lv_obj_set_pos(obj, -70, -11);
                    lv_obj_set_size(obj, 60, 60);
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
                    lv_obj_set_style_text_font(obj, &lv_font_montserrat_24, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_pad_top(obj, 16, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_label_set_text(obj, "");
                }
            }
        }
        {
            // btnS1
            lv_obj_t *obj = lv_btn_create(parent_obj);
            objects.btn_s1 = obj;
            lv_obj_set_pos(obj, 20, 420);
            lv_obj_set_size(obj, 200, 60);
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
            lv_obj_set_style_text_font(obj, &lv_font_montserrat_24, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_left(obj, 70, LV_PART_MAIN | LV_STATE_DEFAULT);
            {
                lv_obj_t *parent_obj = obj;
                {
                    // lblS1
                    lv_obj_t *obj = lv_label_create(parent_obj);
                    objects.lbl_s1 = obj;
                    lv_obj_set_pos(obj, 0, 0);
                    lv_obj_set_size(obj, 140, LV_SIZE_CONTENT);
                    lv_obj_set_style_align(obj, LV_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_text_align(obj, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_text_color(obj, lv_color_hex(0xffffffff), LV_PART_MAIN | LV_STATE_CHECKED);
                    lv_label_set_text(obj, "");
                }
                {
                    // fn_1
                    lv_obj_t *obj = lv_label_create(parent_obj);
                    objects.fn_1 = obj;
                    lv_obj_set_pos(obj, -70, -11);
                    lv_obj_set_size(obj, 60, 60);
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
                    lv_obj_set_style_text_font(obj, &lv_font_montserrat_24, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_pad_top(obj, 16, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_pad_top(obj, 16, LV_PART_MAIN | LV_STATE_PRESSED);
                    lv_label_set_text(obj, "");
                }
            }
        }
        {
            // btnS2
            lv_obj_t *obj = lv_btn_create(parent_obj);
            objects.btn_s2 = obj;
            lv_obj_set_pos(obj, 20, 490);
            lv_obj_set_size(obj, 200, 60);
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
            lv_obj_set_style_text_font(obj, &lv_font_montserrat_24, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_left(obj, 70, LV_PART_MAIN | LV_STATE_DEFAULT);
            {
                lv_obj_t *parent_obj = obj;
                {
                    // lblS2
                    lv_obj_t *obj = lv_label_create(parent_obj);
                    objects.lbl_s2 = obj;
                    lv_obj_set_pos(obj, 0, 0);
                    lv_obj_set_size(obj, 140, LV_SIZE_CONTENT);
                    lv_obj_set_style_align(obj, LV_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_text_align(obj, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_text_color(obj, lv_color_hex(0xffffffff), LV_PART_MAIN | LV_STATE_CHECKED);
                    lv_label_set_text(obj, "");
                }
                {
                    // fn_2
                    lv_obj_t *obj = lv_label_create(parent_obj);
                    objects.fn_2 = obj;
                    lv_obj_set_pos(obj, -70, -11);
                    lv_obj_set_size(obj, 60, 60);
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
                    lv_obj_set_style_text_font(obj, &lv_font_montserrat_24, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_pad_top(obj, 16, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_pad_top(obj, 16, LV_PART_MAIN | LV_STATE_PRESSED);
                    lv_label_set_text(obj, "");
                }
            }
        }
        {
            // btnS3
            lv_obj_t *obj = lv_btn_create(parent_obj);
            objects.btn_s3 = obj;
            lv_obj_set_pos(obj, 20, 560);
            lv_obj_set_size(obj, 200, 60);
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
            lv_obj_set_style_text_font(obj, &lv_font_montserrat_24, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_left(obj, 70, LV_PART_MAIN | LV_STATE_DEFAULT);
            {
                lv_obj_t *parent_obj = obj;
                {
                    // lblS3
                    lv_obj_t *obj = lv_label_create(parent_obj);
                    objects.lbl_s3 = obj;
                    lv_obj_set_pos(obj, 0, 0);
                    lv_obj_set_size(obj, 140, LV_SIZE_CONTENT);
                    lv_obj_set_style_align(obj, LV_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_text_align(obj, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_text_color(obj, lv_color_hex(0xffffffff), LV_PART_MAIN | LV_STATE_CHECKED);
                    lv_label_set_text(obj, "");
                }
                {
                    // fn_3
                    lv_obj_t *obj = lv_label_create(parent_obj);
                    objects.fn_3 = obj;
                    lv_obj_set_pos(obj, -70, -11);
                    lv_obj_set_size(obj, 60, 60);
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
                    lv_obj_set_style_text_font(obj, &lv_font_montserrat_24, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_pad_top(obj, 16, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_pad_top(obj, 16, LV_PART_MAIN | LV_STATE_PRESSED);
                    lv_label_set_text(obj, "");
                }
            }
        }
        {
            // btnS4
            lv_obj_t *obj = lv_btn_create(parent_obj);
            objects.btn_s4 = obj;
            lv_obj_set_pos(obj, 20, 630);
            lv_obj_set_size(obj, 200, 60);
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
            lv_obj_set_style_text_font(obj, &lv_font_montserrat_24, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_left(obj, 70, LV_PART_MAIN | LV_STATE_DEFAULT);
            {
                lv_obj_t *parent_obj = obj;
                {
                    // lbl_s4
                    lv_obj_t *obj = lv_label_create(parent_obj);
                    objects.lbl_s4 = obj;
                    lv_obj_set_pos(obj, 0, 0);
                    lv_obj_set_size(obj, 140, LV_SIZE_CONTENT);
                    lv_obj_set_style_align(obj, LV_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_text_align(obj, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_text_color(obj, lv_color_hex(0xffffffff), LV_PART_MAIN | LV_STATE_CHECKED);
                    lv_label_set_text(obj, "");
                }
                {
                    // fn_4
                    lv_obj_t *obj = lv_label_create(parent_obj);
                    objects.fn_4 = obj;
                    lv_obj_set_pos(obj, -70, -11);
                    lv_obj_set_size(obj, 60, 60);
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
                    lv_obj_set_style_text_font(obj, &lv_font_montserrat_24, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_pad_top(obj, 16, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_pad_top(obj, 16, LV_PART_MAIN | LV_STATE_PRESSED);
                    lv_label_set_text(obj, "");
                }
            }
        }
        {
            // btnS5
            lv_obj_t *obj = lv_btn_create(parent_obj);
            objects.btn_s5 = obj;
            lv_obj_set_pos(obj, 260, 350);
            lv_obj_set_size(obj, 200, 60);
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
            lv_obj_set_style_text_font(obj, &lv_font_montserrat_24, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_left(obj, 70, LV_PART_MAIN | LV_STATE_DEFAULT);
            {
                lv_obj_t *parent_obj = obj;
                {
                    // lblS5
                    lv_obj_t *obj = lv_label_create(parent_obj);
                    objects.lbl_s5 = obj;
                    lv_obj_set_pos(obj, 0, 0);
                    lv_obj_set_size(obj, 140, LV_SIZE_CONTENT);
                    lv_obj_set_style_align(obj, LV_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_text_align(obj, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_text_color(obj, lv_color_hex(0xffffffff), LV_PART_MAIN | LV_STATE_CHECKED);
                    lv_label_set_text(obj, "");
                }
                {
                    // fn_5
                    lv_obj_t *obj = lv_label_create(parent_obj);
                    objects.fn_5 = obj;
                    lv_obj_set_pos(obj, -70, -11);
                    lv_obj_set_size(obj, 60, 60);
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
                    lv_obj_set_style_text_font(obj, &lv_font_montserrat_24, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_pad_top(obj, 16, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_pad_top(obj, 16, LV_PART_MAIN | LV_STATE_PRESSED);
                    lv_label_set_text(obj, "");
                }
            }
        }
        {
            // btnS6
            lv_obj_t *obj = lv_btn_create(parent_obj);
            objects.btn_s6 = obj;
            lv_obj_set_pos(obj, 260, 420);
            lv_obj_set_size(obj, 200, 60);
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
            lv_obj_set_style_text_font(obj, &lv_font_montserrat_24, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_left(obj, 70, LV_PART_MAIN | LV_STATE_DEFAULT);
            {
                lv_obj_t *parent_obj = obj;
                {
                    // lblS6
                    lv_obj_t *obj = lv_label_create(parent_obj);
                    objects.lbl_s6 = obj;
                    lv_obj_set_pos(obj, 0, 0);
                    lv_obj_set_size(obj, 140, LV_SIZE_CONTENT);
                    lv_obj_set_style_align(obj, LV_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_text_align(obj, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_text_color(obj, lv_color_hex(0xffffffff), LV_PART_MAIN | LV_STATE_CHECKED);
                    lv_label_set_text(obj, "");
                }
                {
                    // fn_6
                    lv_obj_t *obj = lv_label_create(parent_obj);
                    objects.fn_6 = obj;
                    lv_obj_set_pos(obj, -70, -11);
                    lv_obj_set_size(obj, 60, 60);
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
                    lv_obj_set_style_text_font(obj, &lv_font_montserrat_24, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_pad_top(obj, 16, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_pad_top(obj, 16, LV_PART_MAIN | LV_STATE_PRESSED);
                    lv_label_set_text(obj, "");
                }
            }
        }
        {
            // btnS7
            lv_obj_t *obj = lv_btn_create(parent_obj);
            objects.btn_s7 = obj;
            lv_obj_set_pos(obj, 260, 490);
            lv_obj_set_size(obj, 200, 60);
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
            lv_obj_set_style_text_font(obj, &lv_font_montserrat_24, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_left(obj, 70, LV_PART_MAIN | LV_STATE_DEFAULT);
            {
                lv_obj_t *parent_obj = obj;
                {
                    // lblS7
                    lv_obj_t *obj = lv_label_create(parent_obj);
                    objects.lbl_s7 = obj;
                    lv_obj_set_pos(obj, 0, 0);
                    lv_obj_set_size(obj, 140, LV_SIZE_CONTENT);
                    lv_obj_set_style_align(obj, LV_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_text_align(obj, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_text_color(obj, lv_color_hex(0xffffffff), LV_PART_MAIN | LV_STATE_CHECKED);
                    lv_label_set_text(obj, "");
                }
                {
                    // fn_7
                    lv_obj_t *obj = lv_label_create(parent_obj);
                    objects.fn_7 = obj;
                    lv_obj_set_pos(obj, -70, -11);
                    lv_obj_set_size(obj, 60, 60);
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
                    lv_obj_set_style_text_font(obj, &lv_font_montserrat_24, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_pad_top(obj, 16, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_pad_top(obj, 16, LV_PART_MAIN | LV_STATE_PRESSED);
                    lv_label_set_text(obj, "");
                }
            }
        }
        {
            // btnS8
            lv_obj_t *obj = lv_btn_create(parent_obj);
            objects.btn_s8 = obj;
            lv_obj_set_pos(obj, 260, 560);
            lv_obj_set_size(obj, 200, 60);
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
            lv_obj_set_style_text_font(obj, &lv_font_montserrat_24, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_left(obj, 70, LV_PART_MAIN | LV_STATE_DEFAULT);
            {
                lv_obj_t *parent_obj = obj;
                {
                    // lblS8
                    lv_obj_t *obj = lv_label_create(parent_obj);
                    objects.lbl_s8 = obj;
                    lv_obj_set_pos(obj, 0, 0);
                    lv_obj_set_size(obj, 140, LV_SIZE_CONTENT);
                    lv_obj_set_style_align(obj, LV_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_text_align(obj, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_text_color(obj, lv_color_hex(0xffffffff), LV_PART_MAIN | LV_STATE_CHECKED);
                    lv_label_set_text(obj, "");
                }
                {
                    // fn_8
                    lv_obj_t *obj = lv_label_create(parent_obj);
                    objects.fn_8 = obj;
                    lv_obj_set_pos(obj, -70, -11);
                    lv_obj_set_size(obj, 60, 60);
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
                    lv_obj_set_style_text_font(obj, &lv_font_montserrat_24, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_pad_top(obj, 16, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_pad_top(obj, 16, LV_PART_MAIN | LV_STATE_PRESSED);
                    lv_label_set_text(obj, "");
                }
            }
        }
        {
            // btnS9
            lv_obj_t *obj = lv_btn_create(parent_obj);
            objects.btn_s9 = obj;
            lv_obj_set_pos(obj, 260, 630);
            lv_obj_set_size(obj, 200, 60);
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
            lv_obj_set_style_text_font(obj, &lv_font_montserrat_24, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_left(obj, 70, LV_PART_MAIN | LV_STATE_DEFAULT);
            {
                lv_obj_t *parent_obj = obj;
                {
                    // lblS9
                    lv_obj_t *obj = lv_label_create(parent_obj);
                    objects.lbl_s9 = obj;
                    lv_obj_set_pos(obj, 0, 0);
                    lv_obj_set_size(obj, 140, LV_SIZE_CONTENT);
                    lv_obj_set_style_align(obj, LV_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_text_align(obj, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_text_color(obj, lv_color_hex(0xffffffff), LV_PART_MAIN | LV_STATE_CHECKED);
                    lv_label_set_text(obj, "");
                }
                {
                    // fn_9
                    lv_obj_t *obj = lv_label_create(parent_obj);
                    objects.fn_9 = obj;
                    lv_obj_set_pos(obj, -70, -11);
                    lv_obj_set_size(obj, 60, 60);
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
                    lv_obj_set_style_text_font(obj, &lv_font_montserrat_24, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_pad_top(obj, 16, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_pad_top(obj, 16, LV_PART_MAIN | LV_STATE_PRESSED);
                    lv_label_set_text(obj, "");
                }
            }
        }
        {
            // aKbdEditLoco
            lv_obj_t *obj = lv_keyboard_create(parent_obj);
            objects.a_kbd_edit_loco = obj;
            lv_obj_set_pos(obj, 1, 480);
            lv_obj_set_size(obj, 478, 320);
            lv_obj_add_flag(obj, LV_OBJ_FLAG_HIDDEN);
            lv_obj_set_style_align(obj, LV_ALIGN_DEFAULT, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_font(obj, &lv_font_montserrat_24, LV_PART_MAIN | LV_STATE_DEFAULT);
        }
        {
            // nKbdEditLoco
            lv_obj_t *obj = lv_keyboard_create(parent_obj);
            objects.n_kbd_edit_loco = obj;
            lv_obj_set_pos(obj, 1, 480);
            lv_obj_set_size(obj, 478, 320);
            lv_keyboard_set_mode(obj, LV_KEYBOARD_MODE_NUMBER);
            lv_obj_add_flag(obj, LV_OBJ_FLAG_HIDDEN);
            lv_obj_set_style_align(obj, LV_ALIGN_DEFAULT, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_font(obj, &lv_font_montserrat_24, LV_PART_MAIN | LV_STATE_DEFAULT);
        }
    }
    lv_keyboard_set_textarea(objects.a_kbd_edit_loco, objects.ta_fname);
    lv_keyboard_set_textarea(objects.n_kbd_edit_loco, objects.ta_fnum);
    
    tick_screen_edit_loco();
}

void tick_screen_edit_loco() {
}

void create_screen_functions() {
    lv_obj_t *obj = lv_obj_create(0);
    objects.functions = obj;
    lv_obj_set_pos(obj, 0, 0);
    lv_obj_set_size(obj, 480, 800);
    lv_obj_set_style_bg_color(obj, lv_color_hex(0xffc89600), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(obj, lv_color_hex(0xffffff00), LV_PART_SCROLLBAR | LV_STATE_CHECKED);
    {
        lv_obj_t *parent_obj = obj;
        {
            // ExFunctionsMtx
            lv_obj_t *obj = lv_btnmatrix_create(parent_obj);
            objects.ex_functions_mtx = obj;
            lv_obj_set_pos(obj, 10, 170);
            lv_obj_set_size(obj, 460, 530);
            static const char *map[35] = {
                "F0",
                "F1",
                "F2",
                "F3",
                "\n",
                "F4",
                "F5",
                "F6",
                "F7",
                "\n",
                "F8",
                "F9",
                "F10",
                "F11",
                "\n",
                "F12",
                "F13",
                "F14",
                "F15",
                "\n",
                "F16",
                "F17",
                "F18",
                "F19",
                "\n",
                "F20",
                "F21",
                "F22",
                "F23",
                "\n",
                "F24",
                "F25",
                "F26",
                "F27",
                NULL,
            };
            static lv_btnmatrix_ctrl_t ctrl_map[28] = {
                1 | LV_BTNMATRIX_CTRL_DISABLED | LV_BTNMATRIX_CTRL_CHECKABLE,
                1 | LV_BTNMATRIX_CTRL_DISABLED | LV_BTNMATRIX_CTRL_CHECKABLE,
                1 | LV_BTNMATRIX_CTRL_DISABLED | LV_BTNMATRIX_CTRL_CHECKABLE,
                1 | LV_BTNMATRIX_CTRL_DISABLED | LV_BTNMATRIX_CTRL_CHECKABLE,
                1 | LV_BTNMATRIX_CTRL_DISABLED | LV_BTNMATRIX_CTRL_CHECKABLE,
                1 | LV_BTNMATRIX_CTRL_DISABLED | LV_BTNMATRIX_CTRL_CHECKABLE,
                1 | LV_BTNMATRIX_CTRL_DISABLED | LV_BTNMATRIX_CTRL_CHECKABLE,
                1 | LV_BTNMATRIX_CTRL_DISABLED | LV_BTNMATRIX_CTRL_CHECKABLE,
                1 | LV_BTNMATRIX_CTRL_DISABLED | LV_BTNMATRIX_CTRL_CHECKABLE,
                1 | LV_BTNMATRIX_CTRL_DISABLED | LV_BTNMATRIX_CTRL_CHECKABLE,
                1 | LV_BTNMATRIX_CTRL_DISABLED | LV_BTNMATRIX_CTRL_CHECKABLE,
                1 | LV_BTNMATRIX_CTRL_DISABLED | LV_BTNMATRIX_CTRL_CHECKABLE,
                1 | LV_BTNMATRIX_CTRL_DISABLED | LV_BTNMATRIX_CTRL_CHECKABLE,
                1 | LV_BTNMATRIX_CTRL_DISABLED | LV_BTNMATRIX_CTRL_CHECKABLE,
                1 | LV_BTNMATRIX_CTRL_DISABLED | LV_BTNMATRIX_CTRL_CHECKABLE,
                1 | LV_BTNMATRIX_CTRL_DISABLED | LV_BTNMATRIX_CTRL_CHECKABLE,
                1 | LV_BTNMATRIX_CTRL_DISABLED | LV_BTNMATRIX_CTRL_CHECKABLE,
                1 | LV_BTNMATRIX_CTRL_DISABLED | LV_BTNMATRIX_CTRL_CHECKABLE,
                1 | LV_BTNMATRIX_CTRL_DISABLED | LV_BTNMATRIX_CTRL_CHECKABLE,
                1 | LV_BTNMATRIX_CTRL_DISABLED | LV_BTNMATRIX_CTRL_CHECKABLE,
                1 | LV_BTNMATRIX_CTRL_DISABLED | LV_BTNMATRIX_CTRL_CHECKABLE,
                1 | LV_BTNMATRIX_CTRL_DISABLED | LV_BTNMATRIX_CTRL_CHECKABLE,
                1 | LV_BTNMATRIX_CTRL_DISABLED | LV_BTNMATRIX_CTRL_CHECKABLE,
                1 | LV_BTNMATRIX_CTRL_DISABLED | LV_BTNMATRIX_CTRL_CHECKABLE,
                1 | LV_BTNMATRIX_CTRL_DISABLED | LV_BTNMATRIX_CTRL_CHECKABLE,
                1 | LV_BTNMATRIX_CTRL_DISABLED | LV_BTNMATRIX_CTRL_CHECKABLE,
                1 | LV_BTNMATRIX_CTRL_DISABLED | LV_BTNMATRIX_CTRL_CHECKABLE,
                1 | LV_BTNMATRIX_CTRL_DISABLED | LV_BTNMATRIX_CTRL_CHECKABLE,
            };
            lv_btnmatrix_set_map(obj, map);
            lv_btnmatrix_set_ctrl_map(obj, ctrl_map);
            lv_obj_add_flag(obj, LV_OBJ_FLAG_CHECKABLE);
            lv_obj_set_style_bg_color(obj, lv_color_hex(0xffc89600), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_top(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_left(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_row(obj, 5, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_column(obj, 5, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_right(obj, 5, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_bottom(obj, 5, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_border_width(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_font(obj, &lv_font_montserrat_30, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_bg_color(obj, lv_color_hex(0xffffffff), LV_PART_ITEMS | LV_STATE_DEFAULT);
            lv_obj_set_style_bg_opa(obj, 255, LV_PART_ITEMS | LV_STATE_DEFAULT);
            lv_obj_set_style_bg_grad_dir(obj, LV_GRAD_DIR_VER, LV_PART_ITEMS | LV_STATE_DEFAULT);
            lv_obj_set_style_bg_grad_color(obj, lv_color_hex(0xff000000), LV_PART_ITEMS | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_top(obj, 0, LV_PART_ITEMS | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_bottom(obj, 8, LV_PART_ITEMS | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_left(obj, 13, LV_PART_ITEMS | LV_STATE_DEFAULT);
            lv_obj_set_style_border_color(obj, lv_color_hex(0xff000000), LV_PART_ITEMS | LV_STATE_DEFAULT);
            lv_obj_set_style_border_width(obj, 1, LV_PART_ITEMS | LV_STATE_DEFAULT);
            lv_obj_set_style_shadow_width(obj, 5, LV_PART_ITEMS | LV_STATE_DEFAULT);
            lv_obj_set_style_shadow_ofs_x(obj, 3, LV_PART_ITEMS | LV_STATE_DEFAULT);
            lv_obj_set_style_shadow_ofs_y(obj, 3, LV_PART_ITEMS | LV_STATE_DEFAULT);
            lv_obj_set_style_shadow_spread(obj, 2, LV_PART_ITEMS | LV_STATE_DEFAULT);
            lv_obj_set_style_shadow_color(obj, lv_color_hex(0xff000000), LV_PART_ITEMS | LV_STATE_DEFAULT);
            lv_obj_set_style_shadow_opa(obj, 127, LV_PART_ITEMS | LV_STATE_DEFAULT);
            lv_obj_set_style_bg_color(obj, lv_color_hex(0xff000000), LV_PART_ITEMS | LV_STATE_PRESSED);
            lv_obj_set_style_bg_grad_dir(obj, LV_GRAD_DIR_VER, LV_PART_ITEMS | LV_STATE_PRESSED);
            lv_obj_set_style_bg_grad_color(obj, lv_color_hex(0xffff0000), LV_PART_ITEMS | LV_STATE_PRESSED);
            lv_obj_set_style_bg_color(obj, lv_color_hex(0xffffff00), LV_PART_ITEMS | LV_STATE_CHECKED);
            lv_obj_set_style_shadow_width(obj, 0, LV_PART_ITEMS | LV_STATE_CHECKED);
            lv_obj_set_style_shadow_ofs_x(obj, 0, LV_PART_ITEMS | LV_STATE_CHECKED);
            lv_obj_set_style_shadow_ofs_y(obj, 0, LV_PART_ITEMS | LV_STATE_CHECKED);
            lv_obj_set_style_shadow_spread(obj, 0, LV_PART_ITEMS | LV_STATE_CHECKED);
            lv_obj_set_style_text_color(obj, lv_color_hex(0xff000000), LV_PART_ITEMS | LV_STATE_CHECKED);
            lv_obj_set_style_bg_grad_dir(obj, LV_GRAD_DIR_NONE, LV_PART_ITEMS | LV_STATE_CHECKED);
        }
        {
            // FuncDescription
            lv_obj_t *obj = lv_label_create(parent_obj);
            objects.func_description = obj;
            lv_obj_set_pos(obj, 10, 120);
            lv_obj_set_size(obj, 460, LV_SIZE_CONTENT);
            lv_obj_set_style_text_color(obj, lv_color_hex(0xff000000), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_font(obj, &lv_font_montserrat_30, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_align(obj, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_bg_color(obj, lv_color_hex(0xffffffff), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_label_set_text(obj, "");
        }
        {
            lv_obj_t *obj = lv_label_create(parent_obj);
            objects.obj20 = obj;
            lv_obj_set_pos(obj, 140, 54);
            lv_obj_set_size(obj, 205, 30);
            lv_obj_clear_flag(obj, LV_OBJ_FLAG_CLICK_FOCUSABLE|LV_OBJ_FLAG_GESTURE_BUBBLE|LV_OBJ_FLAG_PRESS_LOCK|LV_OBJ_FLAG_SCROLLABLE|LV_OBJ_FLAG_SCROLL_CHAIN_HOR|LV_OBJ_FLAG_SCROLL_CHAIN_VER|LV_OBJ_FLAG_SCROLL_ELASTIC|LV_OBJ_FLAG_SCROLL_MOMENTUM|LV_OBJ_FLAG_SNAPPABLE);
            lv_obj_set_style_text_align(obj, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_font(obj, &lv_font_montserrat_24, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_color(obj, lv_color_hex(0xffffffff), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_label_set_text(obj, "Functions");
        }
        {
            // DoneButton_4
            lv_obj_t *obj = lv_btn_create(parent_obj);
            objects.done_button_4 = obj;
            lv_obj_set_pos(obj, 325, 710);
            lv_obj_set_size(obj, 145, 80);
            lv_obj_add_event_cb(obj, action_functions_button, LV_EVENT_RELEASED, (void *)32);
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
            lv_obj_set_style_text_font(obj, &lv_font_montserrat_20, LV_PART_MAIN | LV_STATE_CHECKED);
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
                    lv_obj_set_style_text_font(obj, &lv_font_montserrat_32, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_text_font(obj, &lv_font_montserrat_20, LV_PART_MAIN | LV_STATE_CHECKED);
                    lv_label_set_text(obj, "Done");
                }
            }
        }
        {
            // CancelButton_5
            lv_obj_t *obj = lv_btn_create(parent_obj);
            objects.cancel_button_5 = obj;
            lv_obj_set_pos(obj, 12, 710);
            lv_obj_set_size(obj, 145, 80);
            lv_obj_add_event_cb(obj, action_functions_button, LV_EVENT_RELEASED, (void *)30);
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
            lv_obj_set_style_text_font(obj, &lv_font_montserrat_20, LV_PART_MAIN | LV_STATE_CHECKED);
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
                    lv_obj_set_style_text_font(obj, &lv_font_montserrat_32, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_text_font(obj, &lv_font_montserrat_20, LV_PART_MAIN | LV_STATE_CHECKED);
                    lv_label_set_text(obj, "Cancel");
                }
            }
        }
        {
            // btnFEdit
            lv_obj_t *obj = lv_btn_create(parent_obj);
            objects.btn_fedit = obj;
            lv_obj_set_pos(obj, 169, 710);
            lv_obj_set_size(obj, 145, 80);
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
            lv_obj_set_style_bg_color(obj, lv_color_hex(0xffffff00), LV_PART_MAIN | LV_STATE_CHECKED);
            lv_obj_set_style_bg_opa(obj, 255, LV_PART_MAIN | LV_STATE_CHECKED);
            lv_obj_set_style_shadow_width(obj, 0, LV_PART_MAIN | LV_STATE_CHECKED);
            lv_obj_set_style_shadow_ofs_x(obj, 0, LV_PART_MAIN | LV_STATE_CHECKED);
            lv_obj_set_style_shadow_ofs_y(obj, 0, LV_PART_MAIN | LV_STATE_CHECKED);
            lv_obj_set_style_shadow_spread(obj, 0, LV_PART_MAIN | LV_STATE_CHECKED);
            lv_obj_set_style_bg_grad_dir(obj, LV_GRAD_DIR_NONE, LV_PART_MAIN | LV_STATE_CHECKED);
            lv_obj_set_style_text_color(obj, lv_color_hex(0xff000000), LV_PART_MAIN | LV_STATE_CHECKED);
            {
                lv_obj_t *parent_obj = obj;
                {
                    lv_obj_t *obj = lv_label_create(parent_obj);
                    objects.obj23 = obj;
                    lv_obj_set_pos(obj, 0, 0);
                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                    lv_obj_clear_flag(obj, LV_OBJ_FLAG_CLICK_FOCUSABLE|LV_OBJ_FLAG_GESTURE_BUBBLE|LV_OBJ_FLAG_PRESS_LOCK|LV_OBJ_FLAG_SCROLLABLE|LV_OBJ_FLAG_SCROLL_CHAIN_HOR|LV_OBJ_FLAG_SCROLL_CHAIN_VER|LV_OBJ_FLAG_SCROLL_ELASTIC|LV_OBJ_FLAG_SCROLL_MOMENTUM|LV_OBJ_FLAG_SNAPPABLE);
                    lv_obj_set_style_align(obj, LV_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_bg_color(obj, lv_color_hex(0xffffffff), LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_bg_grad_dir(obj, LV_GRAD_DIR_VER, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_bg_grad_color(obj, lv_color_hex(0xff000000), LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_bg_grad_stop(obj, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_text_font(obj, &lv_font_montserrat_32, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_label_set_text(obj, "Edit");
                }
            }
        }
    }
    
    tick_screen_functions();
}

void tick_screen_functions() {
}

void create_screen_program() {
    lv_obj_t *obj = lv_obj_create(0);
    objects.program = obj;
    lv_obj_set_pos(obj, 0, 0);
    lv_obj_set_size(obj, 480, 800);
    lv_obj_set_style_bg_color(obj, lv_color_hex(0xffc89600), LV_PART_MAIN | LV_STATE_DEFAULT);
    {
        lv_obj_t *parent_obj = obj;
        {
            // CancelButton_6
            lv_obj_t *obj = lv_btn_create(parent_obj);
            objects.cancel_button_6 = obj;
            lv_obj_set_pos(obj, 11, 712);
            lv_obj_set_size(obj, 145, 80);
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
                    lv_obj_set_style_text_font(obj, &lv_font_montserrat_32, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_text_font(obj, &lv_font_montserrat_20, LV_PART_MAIN | LV_STATE_CHECKED);
                    lv_label_set_text(obj, "Cancel");
                }
            }
        }
        {
            // DoneButton_6
            lv_obj_t *obj = lv_btn_create(parent_obj);
            objects.done_button_6 = obj;
            lv_obj_set_pos(obj, 325, 712);
            lv_obj_set_size(obj, 145, 80);
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
                    lv_obj_set_style_text_font(obj, &lv_font_montserrat_32, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_text_font(obj, &lv_font_montserrat_20, LV_PART_MAIN | LV_STATE_CHECKED);
                    lv_label_set_text(obj, "Done");
                }
            }
        }
        {
            lv_obj_t *obj = lv_label_create(parent_obj);
            objects.obj26 = obj;
            lv_obj_set_pos(obj, 140, 54);
            lv_obj_set_size(obj, 205, 30);
            lv_obj_clear_flag(obj, LV_OBJ_FLAG_CLICK_FOCUSABLE|LV_OBJ_FLAG_GESTURE_BUBBLE|LV_OBJ_FLAG_PRESS_LOCK|LV_OBJ_FLAG_SCROLLABLE|LV_OBJ_FLAG_SCROLL_CHAIN_HOR|LV_OBJ_FLAG_SCROLL_CHAIN_VER|LV_OBJ_FLAG_SCROLL_ELASTIC|LV_OBJ_FLAG_SCROLL_MOMENTUM|LV_OBJ_FLAG_SNAPPABLE);
            lv_obj_set_style_text_align(obj, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_font(obj, &lv_font_montserrat_24, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_color(obj, lv_color_hex(0xffffffff), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_label_set_text(obj, "Program");
        }
        {
            // btnRead
            lv_obj_t *obj = lv_btn_create(parent_obj);
            objects.btn_read = obj;
            lv_obj_set_pos(obj, 24, 210);
            lv_obj_set_size(obj, 95, 64);
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
            lv_obj_set_style_text_font(obj, &lv_font_montserrat_30, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_bg_color(obj, lv_color_hex(0xffffff00), LV_PART_MAIN | LV_STATE_CHECKED);
            lv_obj_set_style_bg_grad_dir(obj, LV_GRAD_DIR_NONE, LV_PART_MAIN | LV_STATE_CHECKED);
            lv_obj_set_style_shadow_width(obj, 0, LV_PART_MAIN | LV_STATE_CHECKED);
            lv_obj_set_style_shadow_ofs_x(obj, 0, LV_PART_MAIN | LV_STATE_CHECKED);
            lv_obj_set_style_shadow_ofs_y(obj, 0, LV_PART_MAIN | LV_STATE_CHECKED);
            lv_obj_set_style_shadow_spread(obj, 0, LV_PART_MAIN | LV_STATE_CHECKED);
            lv_obj_set_style_text_color(obj, lv_color_hex(0xff000000), LV_PART_MAIN | LV_STATE_CHECKED);
            lv_obj_set_style_text_font(obj, &lv_font_montserrat_30, LV_PART_MAIN | LV_STATE_CHECKED);
            lv_obj_set_style_text_align(obj, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_CHECKED);
            {
                lv_obj_t *parent_obj = obj;
                {
                    lv_obj_t *obj = lv_label_create(parent_obj);
                    lv_obj_set_pos(obj, 0, 0);
                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                    lv_obj_set_style_align(obj, LV_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_text_align(obj, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_CHECKED);
                    lv_label_set_text(obj, "Read");
                }
            }
        }
        {
            // trackMtx
            lv_obj_t *obj = lv_btnmatrix_create(parent_obj);
            objects.track_mtx = obj;
            lv_obj_set_pos(obj, 17, 112);
            lv_obj_set_size(obj, 453, 74);
            static const char *map[3] = {
                "Main",
                "Prog",
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
            lv_obj_set_style_pad_column(obj, 160, LV_PART_MAIN | LV_STATE_DEFAULT);
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
            lv_obj_set_style_text_font(obj, &lv_font_montserrat_30, LV_PART_ITEMS | LV_STATE_DEFAULT);
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
            objects.obj27 = obj;
            lv_obj_set_pos(obj, 182, 133);
            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
            lv_obj_set_style_text_font(obj, &lv_font_montserrat_30, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_align(obj, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_color(obj, lv_color_hex(0xffffffff), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_color(obj, lv_color_hex(0xffffffff), LV_PART_MAIN | LV_STATE_CHECKED);
            lv_label_set_text(obj, "<Track>");
        }
        {
            lv_obj_t *obj = lv_label_create(parent_obj);
            objects.obj28 = obj;
            lv_obj_set_pos(obj, 38, 492);
            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
            lv_obj_set_style_text_color(obj, lv_color_hex(0xffffffff), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_font(obj, &lv_font_montserrat_30, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_label_set_text(obj, "CV:");
        }
        {
            lv_obj_t *obj = lv_label_create(parent_obj);
            objects.obj29 = obj;
            lv_obj_set_pos(obj, 262, 492);
            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
            lv_obj_set_style_text_color(obj, lv_color_hex(0xffffffff), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_font(obj, &lv_font_montserrat_30, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_label_set_text(obj, "Value:");
        }
        {
            // taCvn
            lv_obj_t *obj = lv_textarea_create(parent_obj);
            objects.ta_cvn = obj;
            lv_obj_set_pos(obj, 102, 488);
            lv_obj_set_size(obj, 71, 35);
            lv_textarea_set_max_length(obj, 4);
            lv_textarea_set_placeholder_text(obj, "CV");
            lv_textarea_set_one_line(obj, true);
            lv_textarea_set_password_mode(obj, false);
            lv_obj_set_style_pad_top(obj, 2, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_bottom(obj, 2, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_font(obj, &lv_font_montserrat_30, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_left(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_right(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_align(obj, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
        }
        {
            // taCvv
            lv_obj_t *obj = lv_textarea_create(parent_obj);
            objects.ta_cvv = obj;
            lv_obj_set_pos(obj, 364, 487);
            lv_obj_set_size(obj, 69, 35);
            lv_textarea_set_max_length(obj, 4);
            lv_textarea_set_placeholder_text(obj, "Val");
            lv_textarea_set_one_line(obj, true);
            lv_textarea_set_password_mode(obj, false);
            lv_obj_set_style_pad_top(obj, 2, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_bottom(obj, 2, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_font(obj, &lv_font_montserrat_30, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_left(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_right(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_align(obj, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
        }
        {
            // taAdr
            lv_obj_t *obj = lv_textarea_create(parent_obj);
            objects.ta_adr = obj;
            lv_obj_set_pos(obj, 185, 228);
            lv_obj_set_size(obj, 117, 35);
            lv_textarea_set_max_length(obj, 128);
            lv_textarea_set_placeholder_text(obj, "Address");
            lv_textarea_set_one_line(obj, true);
            lv_textarea_set_password_mode(obj, false);
            lv_obj_add_flag(obj, LV_OBJ_FLAG_HIDDEN);
            lv_obj_set_style_pad_top(obj, 2, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_bottom(obj, 2, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_font(obj, &lv_font_montserrat_30, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_align(obj, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
        }
        {
            // cv_mtx
            lv_obj_t *obj = lv_btnmatrix_create(parent_obj);
            objects.cv_mtx = obj;
            lv_obj_set_pos(obj, 24, 296);
            lv_obj_set_size(obj, 435, 163);
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
            lv_obj_set_style_text_font(obj, &lv_font_montserrat_18, LV_PART_MAIN | LV_STATE_DEFAULT);
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
            lv_obj_set_style_text_font(obj, &lv_font_montserrat_30, LV_PART_ITEMS | LV_STATE_DEFAULT);
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
            // btnWrite
            lv_obj_t *obj = lv_btn_create(parent_obj);
            objects.btn_write = obj;
            lv_obj_set_pos(obj, 353, 210);
            lv_obj_set_size(obj, 97, 64);
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
            lv_obj_set_style_text_font(obj, &lv_font_montserrat_30, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_bg_color(obj, lv_color_hex(0xffffff00), LV_PART_MAIN | LV_STATE_CHECKED);
            lv_obj_set_style_bg_grad_dir(obj, LV_GRAD_DIR_NONE, LV_PART_MAIN | LV_STATE_CHECKED);
            lv_obj_set_style_shadow_width(obj, 0, LV_PART_MAIN | LV_STATE_CHECKED);
            lv_obj_set_style_shadow_ofs_x(obj, 0, LV_PART_MAIN | LV_STATE_CHECKED);
            lv_obj_set_style_shadow_ofs_y(obj, 0, LV_PART_MAIN | LV_STATE_CHECKED);
            lv_obj_set_style_shadow_spread(obj, 0, LV_PART_MAIN | LV_STATE_CHECKED);
            lv_obj_set_style_text_color(obj, lv_color_hex(0xff000000), LV_PART_MAIN | LV_STATE_CHECKED);
            lv_obj_set_style_text_font(obj, &lv_font_montserrat_24, LV_PART_MAIN | LV_STATE_CHECKED);
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
            // lblPS1
            lv_obj_t *obj = lv_label_create(parent_obj);
            objects.lbl_ps1 = obj;
            lv_obj_set_pos(obj, 20, 542);
            lv_obj_set_size(obj, 440, 40);
            lv_obj_set_style_text_font(obj, &lv_font_montserrat_24, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_align(obj, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_label_set_text(obj, "");
        }
        {
            // lblPS2
            lv_obj_t *obj = lv_label_create(parent_obj);
            objects.lbl_ps2 = obj;
            lv_obj_set_pos(obj, 17, 597);
            lv_obj_set_size(obj, 440, 40);
            lv_obj_set_style_text_font(obj, &lv_font_montserrat_24, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_align(obj, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_label_set_text(obj, "");
        }
        {
            // kbdProgram
            lv_obj_t *obj = lv_keyboard_create(parent_obj);
            objects.kbd_program = obj;
            lv_obj_set_pos(obj, 1, 528);
            lv_obj_set_size(obj, 479, 272);
            lv_keyboard_set_mode(obj, LV_KEYBOARD_MODE_NUMBER);
            lv_obj_add_flag(obj, LV_OBJ_FLAG_HIDDEN);
            lv_obj_set_style_align(obj, LV_ALIGN_DEFAULT, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_font(obj, &lv_font_montserrat_24, LV_PART_MAIN | LV_STATE_CHECKED);
            lv_obj_set_style_text_font(obj, &lv_font_montserrat_30, LV_PART_ITEMS | LV_STATE_DEFAULT);
        }
    }
    
    tick_screen_program();
}

void tick_screen_program() {
}

void create_screen_accessories() {
    lv_obj_t *obj = lv_obj_create(0);
    objects.accessories = obj;
    lv_obj_set_pos(obj, 0, 0);
    lv_obj_set_size(obj, 480, 800);
    lv_obj_set_style_bg_color(obj, lv_color_hex(0xffc89600), LV_PART_MAIN | LV_STATE_DEFAULT);
    {
        lv_obj_t *parent_obj = obj;
        {
            // AccEditButton
            lv_obj_t *obj = lv_btn_create(parent_obj);
            objects.acc_edit_button = obj;
            lv_obj_set_pos(obj, 11, 711);
            lv_obj_set_size(obj, 145, 80);
            lv_obj_add_event_cb(obj, action_accessories_button, LV_EVENT_RELEASED, (void *)30);
            lv_obj_add_flag(obj, LV_OBJ_FLAG_CHECKABLE);
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
            lv_obj_set_style_text_font(obj, &lv_font_montserrat_20, LV_PART_MAIN | LV_STATE_CHECKED);
            lv_obj_set_style_shadow_width(obj, 10, LV_PART_MAIN | LV_STATE_CHECKED);
            lv_obj_set_style_shadow_ofs_x(obj, 0, LV_PART_MAIN | LV_STATE_CHECKED);
            lv_obj_set_style_shadow_ofs_y(obj, 0, LV_PART_MAIN | LV_STATE_CHECKED);
            lv_obj_set_style_shadow_spread(obj, 0, LV_PART_MAIN | LV_STATE_CHECKED);
            {
                lv_obj_t *parent_obj = obj;
                {
                    lv_obj_t *obj = lv_label_create(parent_obj);
                    objects.obj30 = obj;
                    lv_obj_set_pos(obj, 0, 0);
                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                    lv_obj_clear_flag(obj, LV_OBJ_FLAG_CLICK_FOCUSABLE|LV_OBJ_FLAG_GESTURE_BUBBLE|LV_OBJ_FLAG_PRESS_LOCK|LV_OBJ_FLAG_SCROLLABLE|LV_OBJ_FLAG_SCROLL_CHAIN_HOR|LV_OBJ_FLAG_SCROLL_CHAIN_VER|LV_OBJ_FLAG_SCROLL_ELASTIC|LV_OBJ_FLAG_SCROLL_MOMENTUM|LV_OBJ_FLAG_SNAPPABLE);
                    lv_obj_set_style_align(obj, LV_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_bg_color(obj, lv_color_hex(0xffffffff), LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_bg_grad_dir(obj, LV_GRAD_DIR_VER, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_bg_grad_color(obj, lv_color_hex(0xff000000), LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_bg_grad_stop(obj, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_text_font(obj, &lv_font_montserrat_32, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_text_font(obj, &lv_font_montserrat_20, LV_PART_MAIN | LV_STATE_CHECKED);
                    lv_label_set_text(obj, "Edit");
                }
            }
        }
        {
            // DoneButton_8
            lv_obj_t *obj = lv_btn_create(parent_obj);
            objects.done_button_8 = obj;
            lv_obj_set_pos(obj, 325, 711);
            lv_obj_set_size(obj, 145, 80);
            lv_obj_add_event_cb(obj, action_accessories_button, LV_EVENT_RELEASED, (void *)32);
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
            lv_obj_set_style_text_font(obj, &lv_font_montserrat_20, LV_PART_MAIN | LV_STATE_CHECKED);
            lv_obj_set_style_shadow_width(obj, 10, LV_PART_MAIN | LV_STATE_CHECKED);
            lv_obj_set_style_shadow_ofs_x(obj, 0, LV_PART_MAIN | LV_STATE_CHECKED);
            lv_obj_set_style_shadow_ofs_y(obj, 0, LV_PART_MAIN | LV_STATE_CHECKED);
            lv_obj_set_style_shadow_spread(obj, 0, LV_PART_MAIN | LV_STATE_CHECKED);
            {
                lv_obj_t *parent_obj = obj;
                {
                    lv_obj_t *obj = lv_label_create(parent_obj);
                    objects.obj31 = obj;
                    lv_obj_set_pos(obj, 0, 0);
                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                    lv_obj_clear_flag(obj, LV_OBJ_FLAG_CLICK_FOCUSABLE|LV_OBJ_FLAG_GESTURE_BUBBLE|LV_OBJ_FLAG_PRESS_LOCK|LV_OBJ_FLAG_SCROLLABLE|LV_OBJ_FLAG_SCROLL_CHAIN_HOR|LV_OBJ_FLAG_SCROLL_CHAIN_VER|LV_OBJ_FLAG_SCROLL_ELASTIC|LV_OBJ_FLAG_SCROLL_MOMENTUM|LV_OBJ_FLAG_SNAPPABLE);
                    lv_obj_set_style_align(obj, LV_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_bg_color(obj, lv_color_hex(0xffffffff), LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_bg_grad_dir(obj, LV_GRAD_DIR_VER, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_bg_grad_color(obj, lv_color_hex(0xff000000), LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_bg_grad_stop(obj, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_text_font(obj, &lv_font_montserrat_32, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_text_font(obj, &lv_font_montserrat_20, LV_PART_MAIN | LV_STATE_CHECKED);
                    lv_label_set_text(obj, "Done");
                }
            }
        }
        {
            lv_obj_t *obj = lv_label_create(parent_obj);
            objects.obj32 = obj;
            lv_obj_set_pos(obj, 140, 54);
            lv_obj_set_size(obj, 205, 30);
            lv_obj_clear_flag(obj, LV_OBJ_FLAG_CLICK_FOCUSABLE|LV_OBJ_FLAG_GESTURE_BUBBLE|LV_OBJ_FLAG_PRESS_LOCK|LV_OBJ_FLAG_SCROLLABLE|LV_OBJ_FLAG_SCROLL_CHAIN_HOR|LV_OBJ_FLAG_SCROLL_CHAIN_VER|LV_OBJ_FLAG_SCROLL_ELASTIC|LV_OBJ_FLAG_SCROLL_MOMENTUM|LV_OBJ_FLAG_SNAPPABLE);
            lv_obj_set_style_text_align(obj, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_font(obj, &lv_font_montserrat_24, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_color(obj, lv_color_hex(0xffffffff), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_label_set_text(obj, "Accessories");
        }
        {
            // btnPageUp
            lv_obj_t *obj = lv_btn_create(parent_obj);
            objects.btn_page_up = obj;
            lv_obj_set_pos(obj, 14, 643);
            lv_obj_set_size(obj, 120, 60);
            lv_obj_add_event_cb(obj, action_accessories_button, LV_EVENT_RELEASED, (void *)28);
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
            lv_obj_set_style_shadow_color(obj, lv_color_hex(0xff000000), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_shadow_opa(obj, 127, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_bg_color(obj, lv_color_hex(0xff000000), LV_PART_MAIN | LV_STATE_PRESSED);
            lv_obj_set_style_bg_grad_dir(obj, LV_GRAD_DIR_VER, LV_PART_MAIN | LV_STATE_PRESSED);
            lv_obj_set_style_bg_grad_color(obj, lv_color_hex(0xfffff200), LV_PART_MAIN | LV_STATE_PRESSED);
            lv_obj_set_style_text_color(obj, lv_color_hex(0xff000000), LV_PART_MAIN | LV_STATE_PRESSED);
            lv_obj_set_style_text_font(obj, &lv_font_montserrat_20, LV_PART_MAIN | LV_STATE_CHECKED);
            {
                lv_obj_t *parent_obj = obj;
                {
                    lv_obj_t *obj = lv_label_create(parent_obj);
                    objects.obj33 = obj;
                    lv_obj_set_pos(obj, 0, 0);
                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                    lv_obj_clear_flag(obj, LV_OBJ_FLAG_CLICK_FOCUSABLE|LV_OBJ_FLAG_GESTURE_BUBBLE|LV_OBJ_FLAG_PRESS_LOCK|LV_OBJ_FLAG_SCROLLABLE|LV_OBJ_FLAG_SCROLL_CHAIN_HOR|LV_OBJ_FLAG_SCROLL_CHAIN_VER|LV_OBJ_FLAG_SCROLL_ELASTIC|LV_OBJ_FLAG_SCROLL_MOMENTUM|LV_OBJ_FLAG_SNAPPABLE);
                    lv_obj_set_style_align(obj, LV_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_bg_color(obj, lv_color_hex(0xffffffff), LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_bg_grad_dir(obj, LV_GRAD_DIR_VER, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_bg_grad_color(obj, lv_color_hex(0xff000000), LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_bg_grad_stop(obj, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_text_font(obj, &lv_font_montserrat_24, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_text_font(obj, &lv_font_montserrat_20, LV_PART_MAIN | LV_STATE_CHECKED);
                    lv_label_set_text(obj, "PgUp");
                }
            }
        }
        {
            // btnPageDown
            lv_obj_t *obj = lv_btn_create(parent_obj);
            objects.btn_page_down = obj;
            lv_obj_set_pos(obj, 350, 643);
            lv_obj_set_size(obj, 120, 60);
            lv_obj_add_event_cb(obj, action_accessories_button, LV_EVENT_RELEASED, (void *)29);
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
            lv_obj_set_style_shadow_color(obj, lv_color_hex(0xff000000), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_shadow_opa(obj, 127, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_bg_color(obj, lv_color_hex(0xff000000), LV_PART_MAIN | LV_STATE_PRESSED);
            lv_obj_set_style_bg_grad_dir(obj, LV_GRAD_DIR_VER, LV_PART_MAIN | LV_STATE_PRESSED);
            lv_obj_set_style_bg_grad_color(obj, lv_color_hex(0xfffff200), LV_PART_MAIN | LV_STATE_PRESSED);
            lv_obj_set_style_text_color(obj, lv_color_hex(0xff000000), LV_PART_MAIN | LV_STATE_PRESSED);
            lv_obj_set_style_text_font(obj, &lv_font_montserrat_20, LV_PART_MAIN | LV_STATE_CHECKED);
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
                    lv_obj_set_style_text_font(obj, &lv_font_montserrat_24, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_text_font(obj, &lv_font_montserrat_20, LV_PART_MAIN | LV_STATE_CHECKED);
                    lv_label_set_text(obj, "PgDn");
                }
            }
        }
        {
            // AccStateMtx
            lv_obj_t *obj = lv_btnmatrix_create(parent_obj);
            objects.acc_state_mtx = obj;
            lv_obj_set_pos(obj, 14, 120);
            lv_obj_set_size(obj, 102, 508);
            static const char *map[20] = {
                "  ",
                "\n",
                " ",
                "\n",
                " ",
                "\n",
                " ",
                "\n",
                " ",
                "\n",
                " ",
                "\n",
                " ",
                "\n",
                " ",
                "\n",
                " ",
                "\n",
                " ",
                NULL,
            };
            static lv_btnmatrix_ctrl_t ctrl_map[10] = {
                1 | LV_BTNMATRIX_CTRL_CHECKABLE,
                1 | LV_BTNMATRIX_CTRL_CHECKABLE,
                1 | LV_BTNMATRIX_CTRL_CHECKABLE,
                1 | LV_BTNMATRIX_CTRL_CHECKABLE,
                1 | LV_BTNMATRIX_CTRL_CHECKABLE,
                1 | LV_BTNMATRIX_CTRL_CHECKABLE,
                1 | LV_BTNMATRIX_CTRL_CHECKABLE,
                1 | LV_BTNMATRIX_CTRL_CHECKABLE,
                1 | LV_BTNMATRIX_CTRL_CHECKABLE,
                1 | LV_BTNMATRIX_CTRL_CHECKABLE,
            };
            lv_btnmatrix_set_map(obj, map);
            lv_btnmatrix_set_ctrl_map(obj, ctrl_map);
            lv_obj_clear_flag(obj, LV_OBJ_FLAG_CLICKABLE);
            lv_obj_set_style_pad_left(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_right(obj, 5, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_top(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_bottom(obj, 5, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_row(obj, 4, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_bg_color(obj, lv_color_hex(0xffc89600), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_border_color(obj, lv_color_hex(0xffc89600), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_border_width(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_shadow_opa(obj, 255, LV_PART_MAIN | LV_STATE_CHECKED);
            lv_obj_set_style_bg_color(obj, lv_color_hex(0xff00ff00), LV_PART_ITEMS | LV_STATE_DEFAULT);
            lv_obj_set_style_bg_grad_dir(obj, LV_GRAD_DIR_VER, LV_PART_ITEMS | LV_STATE_DEFAULT);
            lv_obj_set_style_border_color(obj, lv_color_hex(0xff000000), LV_PART_ITEMS | LV_STATE_DEFAULT);
            lv_obj_set_style_border_width(obj, 1, LV_PART_ITEMS | LV_STATE_DEFAULT);
            lv_obj_set_style_shadow_width(obj, 5, LV_PART_ITEMS | LV_STATE_DEFAULT);
            lv_obj_set_style_shadow_ofs_x(obj, 3, LV_PART_ITEMS | LV_STATE_DEFAULT);
            lv_obj_set_style_shadow_ofs_y(obj, 3, LV_PART_ITEMS | LV_STATE_DEFAULT);
            lv_obj_set_style_shadow_spread(obj, 1, LV_PART_ITEMS | LV_STATE_DEFAULT);
            lv_obj_set_style_shadow_color(obj, lv_color_hex(0xff000000), LV_PART_ITEMS | LV_STATE_DEFAULT);
            lv_obj_set_style_text_font(obj, &lv_font_montserrat_24, LV_PART_ITEMS | LV_STATE_DEFAULT);
            lv_obj_set_style_shadow_opa(obj, 127, LV_PART_ITEMS | LV_STATE_DEFAULT);
            lv_obj_set_style_text_opa(obj, 0, LV_PART_ITEMS | LV_STATE_DEFAULT);
            lv_obj_set_style_bg_color(obj, lv_color_hex(0xff000000), LV_PART_ITEMS | LV_STATE_CHECKED);
            lv_obj_set_style_bg_grad_color(obj, lv_color_hex(0xffff0000), LV_PART_ITEMS | LV_STATE_CHECKED);
            lv_obj_set_style_border_color(obj, lv_color_hex(0xff000000), LV_PART_ITEMS | LV_STATE_CHECKED);
            lv_obj_set_style_border_width(obj, 1, LV_PART_ITEMS | LV_STATE_CHECKED);
            lv_obj_set_style_shadow_width(obj, 0, LV_PART_ITEMS | LV_STATE_CHECKED);
            lv_obj_set_style_shadow_ofs_x(obj, 0, LV_PART_ITEMS | LV_STATE_CHECKED);
            lv_obj_set_style_shadow_ofs_y(obj, 0, LV_PART_ITEMS | LV_STATE_CHECKED);
            lv_obj_set_style_shadow_spread(obj, 0, LV_PART_ITEMS | LV_STATE_CHECKED);
        }
        {
            // AccNameMtx
            lv_obj_t *obj = lv_btnmatrix_create(parent_obj);
            objects.acc_name_mtx = obj;
            lv_obj_set_pos(obj, 125, 120);
            lv_obj_set_size(obj, 345, 508);
            static const char *map[20] = {
                " ",
                "\n",
                " ",
                "\n",
                " ",
                "\n",
                " ",
                "\n",
                " ",
                "\n",
                " ",
                "\n",
                " ",
                "\n",
                " ",
                "\n",
                " ",
                "\n",
                " ",
                NULL,
            };
            static lv_btnmatrix_ctrl_t ctrl_map[10] = {
                1 | LV_BTNMATRIX_CTRL_CHECKABLE,
                1 | LV_BTNMATRIX_CTRL_CHECKABLE,
                1 | LV_BTNMATRIX_CTRL_CHECKABLE,
                1 | LV_BTNMATRIX_CTRL_CHECKABLE,
                1 | LV_BTNMATRIX_CTRL_CHECKABLE,
                1 | LV_BTNMATRIX_CTRL_CHECKABLE,
                1 | LV_BTNMATRIX_CTRL_CHECKABLE,
                1 | LV_BTNMATRIX_CTRL_CHECKABLE,
                1 | LV_BTNMATRIX_CTRL_CHECKABLE,
                1 | LV_BTNMATRIX_CTRL_CHECKABLE,
            };
            lv_btnmatrix_set_map(obj, map);
            lv_btnmatrix_set_ctrl_map(obj, ctrl_map);
            lv_obj_set_style_pad_left(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_right(obj, 5, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_top(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_bottom(obj, 5, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_row(obj, 4, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_bg_color(obj, lv_color_hex(0xffc89600), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_border_color(obj, lv_color_hex(0xffc89600), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_border_width(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_bg_color(obj, lv_color_hex(0xffc89600), LV_PART_ITEMS | LV_STATE_DEFAULT);
            lv_obj_set_style_border_color(obj, lv_color_hex(0xff000000), LV_PART_ITEMS | LV_STATE_DEFAULT);
            lv_obj_set_style_border_width(obj, 1, LV_PART_ITEMS | LV_STATE_DEFAULT);
            lv_obj_set_style_shadow_width(obj, 5, LV_PART_ITEMS | LV_STATE_DEFAULT);
            lv_obj_set_style_shadow_ofs_x(obj, 3, LV_PART_ITEMS | LV_STATE_DEFAULT);
            lv_obj_set_style_shadow_ofs_y(obj, 3, LV_PART_ITEMS | LV_STATE_DEFAULT);
            lv_obj_set_style_shadow_spread(obj, 1, LV_PART_ITEMS | LV_STATE_DEFAULT);
            lv_obj_set_style_shadow_color(obj, lv_color_hex(0xff000000), LV_PART_ITEMS | LV_STATE_DEFAULT);
            lv_obj_set_style_bg_grad_dir(obj, LV_GRAD_DIR_NONE, LV_PART_ITEMS | LV_STATE_DEFAULT);
            lv_obj_set_style_text_font(obj, &lv_font_montserrat_24, LV_PART_ITEMS | LV_STATE_DEFAULT);
            lv_obj_set_style_border_color(obj, lv_color_hex(0xff000000), LV_PART_ITEMS | LV_STATE_CHECKED);
            lv_obj_set_style_border_width(obj, 1, LV_PART_ITEMS | LV_STATE_CHECKED);
            lv_obj_set_style_shadow_ofs_x(obj, 0, LV_PART_ITEMS | LV_STATE_CHECKED);
            lv_obj_set_style_shadow_ofs_y(obj, 0, LV_PART_ITEMS | LV_STATE_CHECKED);
            lv_obj_set_style_shadow_spread(obj, 0, LV_PART_ITEMS | LV_STATE_CHECKED);
            lv_obj_set_style_bg_color(obj, lv_color_hex(0xffc89600), LV_PART_ITEMS | LV_STATE_CHECKED);
            lv_obj_set_style_shadow_width(obj, 0, LV_PART_ITEMS | LV_STATE_CHECKED);
        }
        {
            // GroupBtn
            lv_obj_t *obj = lv_btn_create(parent_obj);
            objects.group_btn = obj;
            lv_obj_set_pos(obj, 170, 712);
            lv_obj_set_size(obj, 145, 80);
            lv_obj_add_event_cb(obj, action_accessories_button, LV_EVENT_RELEASED, (void *)31);
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
                    lv_obj_set_pos(obj, 6, 13);
                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                    lv_obj_set_style_text_font(obj, &lv_font_montserrat_32, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_label_set_text(obj, "Group");
                }
            }
        }
    }
    
    tick_screen_accessories();
}

void tick_screen_accessories() {
}

void create_screen_edit_acc() {
    lv_obj_t *obj = lv_obj_create(0);
    objects.edit_acc = obj;
    lv_obj_set_pos(obj, 0, 0);
    lv_obj_set_size(obj, 480, 800);
    lv_obj_set_style_bg_color(obj, lv_color_hex(0xffc89600), LV_PART_MAIN | LV_STATE_DEFAULT);
    {
        lv_obj_t *parent_obj = obj;
        {
            // CancelButton_9
            lv_obj_t *obj = lv_btn_create(parent_obj);
            objects.cancel_button_9 = obj;
            lv_obj_set_pos(obj, 11, 711);
            lv_obj_set_size(obj, 145, 80);
            lv_obj_add_event_cb(obj, action_edit_acc_button, LV_EVENT_RELEASED, (void *)30);
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
            lv_obj_set_style_text_font(obj, &lv_font_montserrat_20, LV_PART_MAIN | LV_STATE_CHECKED);
            lv_obj_set_style_shadow_width(obj, 0, LV_PART_MAIN | LV_STATE_CHECKED);
            lv_obj_set_style_shadow_ofs_x(obj, 0, LV_PART_MAIN | LV_STATE_CHECKED);
            lv_obj_set_style_shadow_ofs_y(obj, 0, LV_PART_MAIN | LV_STATE_CHECKED);
            lv_obj_set_style_shadow_spread(obj, 0, LV_PART_MAIN | LV_STATE_CHECKED);
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
                    lv_obj_set_style_text_font(obj, &lv_font_montserrat_32, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_text_font(obj, &lv_font_montserrat_20, LV_PART_MAIN | LV_STATE_CHECKED);
                    lv_label_set_text(obj, "Cancel");
                }
            }
        }
        {
            // DoneButton_9
            lv_obj_t *obj = lv_btn_create(parent_obj);
            objects.done_button_9 = obj;
            lv_obj_set_pos(obj, 325, 711);
            lv_obj_set_size(obj, 145, 80);
            lv_obj_add_event_cb(obj, action_edit_acc_button, LV_EVENT_RELEASED, (void *)32);
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
            lv_obj_set_style_text_font(obj, &lv_font_montserrat_20, LV_PART_MAIN | LV_STATE_CHECKED);
            lv_obj_set_style_shadow_width(obj, 0, LV_PART_MAIN | LV_STATE_CHECKED);
            lv_obj_set_style_shadow_ofs_x(obj, 0, LV_PART_MAIN | LV_STATE_CHECKED);
            lv_obj_set_style_shadow_ofs_y(obj, 0, LV_PART_MAIN | LV_STATE_CHECKED);
            lv_obj_set_style_shadow_spread(obj, 0, LV_PART_MAIN | LV_STATE_CHECKED);
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
                    lv_obj_set_style_text_font(obj, &lv_font_montserrat_32, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_text_font(obj, &lv_font_montserrat_20, LV_PART_MAIN | LV_STATE_CHECKED);
                    lv_label_set_text(obj, "Done");
                }
            }
        }
        {
            lv_obj_t *obj = lv_label_create(parent_obj);
            objects.obj37 = obj;
            lv_obj_set_pos(obj, 190, 54);
            lv_obj_set_size(obj, LV_SIZE_CONTENT, 30);
            lv_obj_clear_flag(obj, LV_OBJ_FLAG_CLICK_FOCUSABLE|LV_OBJ_FLAG_GESTURE_BUBBLE|LV_OBJ_FLAG_PRESS_LOCK|LV_OBJ_FLAG_SCROLLABLE|LV_OBJ_FLAG_SCROLL_CHAIN_HOR|LV_OBJ_FLAG_SCROLL_CHAIN_VER|LV_OBJ_FLAG_SCROLL_ELASTIC|LV_OBJ_FLAG_SCROLL_MOMENTUM|LV_OBJ_FLAG_SNAPPABLE);
            lv_obj_set_style_text_align(obj, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_font(obj, &lv_font_montserrat_24, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_color(obj, lv_color_hex(0xffffffff), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_label_set_text(obj, "Edit Acc");
        }
        {
            lv_obj_t *obj = lv_label_create(parent_obj);
            objects.obj38 = obj;
            lv_obj_set_pos(obj, 139, 186);
            lv_obj_set_size(obj, LV_SIZE_CONTENT, 46);
            lv_obj_set_style_text_font(obj, &lv_font_montserrat_24, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_bg_color(obj, lv_color_hex(0xffc89600), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_top(obj, 10, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_left(obj, 8, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_radius(obj, 7, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_label_set_text(obj, "Accessory ID");
        }
        {
            // taAccID
            lv_obj_t *obj = lv_textarea_create(parent_obj);
            objects.ta_acc_id = obj;
            lv_obj_set_pos(obj, 7, 184);
            lv_obj_set_size(obj, 100, 50);
            lv_textarea_set_max_length(obj, 4);
            lv_textarea_set_one_line(obj, true);
            lv_textarea_set_password_mode(obj, false);
            lv_obj_add_state(obj, LV_STATE_DISABLED);
            lv_obj_set_style_pad_top(obj, 8, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_bottom(obj, 8, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_left(obj, 1, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_right(obj, 1, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_align(obj, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_font(obj, &lv_font_montserrat_28, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_shadow_width(obj, 10, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_shadow_ofs_x(obj, 5, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_shadow_ofs_y(obj, 5, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_shadow_spread(obj, 4, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_shadow_opa(obj, 127, LV_PART_MAIN | LV_STATE_DEFAULT);
        }
        {
            // taAccName
            lv_obj_t *obj = lv_textarea_create(parent_obj);
            objects.ta_acc_name = obj;
            lv_obj_set_pos(obj, 7, 120);
            lv_obj_set_size(obj, 460, 50);
            lv_textarea_set_max_length(obj, 30);
            lv_textarea_set_placeholder_text(obj, "Accessory Name");
            lv_textarea_set_one_line(obj, true);
            lv_textarea_set_password_mode(obj, false);
            lv_obj_set_style_border_color(obj, lv_color_hex(0xff000000), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_border_width(obj, 1, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_font(obj, &lv_font_montserrat_24, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_shadow_width(obj, 10, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_shadow_ofs_x(obj, 5, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_shadow_ofs_y(obj, 5, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_shadow_spread(obj, 4, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_shadow_color(obj, lv_color_hex(0xff000000), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_shadow_opa(obj, 127, LV_PART_MAIN | LV_STATE_DEFAULT);
        }
        {
            lv_obj_t *obj = lv_label_create(parent_obj);
            objects.obj39 = obj;
            lv_obj_set_pos(obj, 139, 311);
            lv_obj_set_size(obj, LV_SIZE_CONTENT, 46);
            lv_obj_set_style_text_font(obj, &lv_font_montserrat_24, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_bg_color(obj, lv_color_hex(0xffc89600), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_top(obj, 10, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_left(obj, 8, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_radius(obj, 7, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_label_set_text(obj, "Momentary:");
        }
        {
            // TaAccOption
            lv_obj_t *obj = lv_checkbox_create(parent_obj);
            objects.ta_acc_option = obj;
            lv_obj_set_pos(obj, 11, 319);
            lv_obj_set_size(obj, 30, 30);
            lv_checkbox_set_text(obj, "");
            lv_obj_set_style_text_font(obj, &lv_font_montserrat_24, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_shadow_width(obj, 10, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_shadow_ofs_x(obj, 5, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_shadow_ofs_y(obj, 5, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_shadow_spread(obj, 3, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_shadow_opa(obj, 127, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_font(obj, &lv_font_montserrat_36, LV_PART_MAIN | LV_STATE_CHECKED);
        }
        {
            // taAccAddress
            lv_obj_t *obj = lv_textarea_create(parent_obj);
            objects.ta_acc_address = obj;
            lv_obj_set_pos(obj, 8, 251);
            lv_obj_set_size(obj, 100, 50);
            lv_textarea_set_max_length(obj, 4);
            lv_textarea_set_one_line(obj, true);
            lv_textarea_set_password_mode(obj, false);
            lv_obj_set_style_pad_top(obj, 8, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_bottom(obj, 8, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_left(obj, 1, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_right(obj, 1, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_align(obj, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_font(obj, &lv_font_montserrat_28, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_shadow_width(obj, 10, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_shadow_ofs_x(obj, 5, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_shadow_ofs_y(obj, 5, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_shadow_spread(obj, 4, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_shadow_opa(obj, 127, LV_PART_MAIN | LV_STATE_DEFAULT);
        }
        {
            lv_obj_t *obj = lv_label_create(parent_obj);
            objects.obj40 = obj;
            lv_obj_set_pos(obj, 139, 254);
            lv_obj_set_size(obj, LV_SIZE_CONTENT, 46);
            lv_obj_set_style_text_font(obj, &lv_font_montserrat_24, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_bg_color(obj, lv_color_hex(0xffc89600), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_top(obj, 10, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_left(obj, 8, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_radius(obj, 7, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_label_set_text(obj, "Accessory Address:");
        }
        {
            // a_kbd_acc
            lv_obj_t *obj = lv_keyboard_create(parent_obj);
            objects.a_kbd_acc = obj;
            lv_obj_set_pos(obj, 0, 534);
            lv_obj_set_size(obj, 480, 266);
            lv_obj_add_flag(obj, LV_OBJ_FLAG_HIDDEN);
            lv_obj_set_style_align(obj, LV_ALIGN_DEFAULT, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_font(obj, &lv_font_montserrat_30, LV_PART_MAIN | LV_STATE_DEFAULT);
        }
        {
            // n_kbd_acc
            lv_obj_t *obj = lv_keyboard_create(parent_obj);
            objects.n_kbd_acc = obj;
            lv_obj_set_pos(obj, 0, 534);
            lv_obj_set_size(obj, 480, 266);
            lv_keyboard_set_mode(obj, LV_KEYBOARD_MODE_NUMBER);
            lv_obj_add_flag(obj, LV_OBJ_FLAG_HIDDEN);
            lv_obj_set_style_align(obj, LV_ALIGN_DEFAULT, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_font(obj, &lv_font_montserrat_30, LV_PART_MAIN | LV_STATE_DEFAULT);
        }
    }
    
    tick_screen_edit_acc();
}

void tick_screen_edit_acc() {
}

void create_screen_wi_fi() {
    lv_obj_t *obj = lv_obj_create(0);
    objects.wi_fi = obj;
    lv_obj_set_pos(obj, 0, 0);
    lv_obj_set_size(obj, 480, 800);
    lv_obj_set_style_bg_color(obj, lv_color_hex(0xffc89600), LV_PART_MAIN | LV_STATE_DEFAULT);
    {
        lv_obj_t *parent_obj = obj;
        {
            // btnWifiScan
            lv_obj_t *obj = lv_btn_create(parent_obj);
            objects.btn_wifi_scan = obj;
            lv_obj_set_pos(obj, 340, 120);
            lv_obj_set_size(obj, 120, 60);
            lv_obj_add_event_cb(obj, action_wifi_button, LV_EVENT_RELEASED, (void *)2);
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
            lv_obj_set_style_shadow_color(obj, lv_color_hex(0xff000000), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_shadow_opa(obj, 127, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_bg_color(obj, lv_color_hex(0xff000000), LV_PART_MAIN | LV_STATE_PRESSED);
            lv_obj_set_style_bg_grad_dir(obj, LV_GRAD_DIR_VER, LV_PART_MAIN | LV_STATE_PRESSED);
            lv_obj_set_style_bg_grad_color(obj, lv_color_hex(0xfffff200), LV_PART_MAIN | LV_STATE_PRESSED);
            lv_obj_set_style_text_color(obj, lv_color_hex(0xff000000), LV_PART_MAIN | LV_STATE_PRESSED);
            lv_obj_set_style_shadow_width(obj, 0, LV_PART_MAIN | LV_STATE_PRESSED);
            lv_obj_set_style_shadow_ofs_x(obj, 0, LV_PART_MAIN | LV_STATE_PRESSED);
            lv_obj_set_style_shadow_ofs_y(obj, 0, LV_PART_MAIN | LV_STATE_PRESSED);
            lv_obj_set_style_shadow_spread(obj, 0, LV_PART_MAIN | LV_STATE_PRESSED);
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
                    lv_obj_set_style_text_font(obj, &lv_font_montserrat_24, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_label_set_text(obj, "Scan");
                }
            }
        }
        {
            // ConfigButton_WiFi
            lv_obj_t *obj = lv_btn_create(parent_obj);
            objects.config_button_wi_fi = obj;
            lv_obj_set_pos(obj, 11, 711);
            lv_obj_set_size(obj, 145, 80);
            lv_obj_add_event_cb(obj, action_wifi_button, LV_EVENT_RELEASED, (void *)30);
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
                    lv_obj_set_style_text_font(obj, &lv_font_montserrat_32, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_text_font(obj, &lv_font_montserrat_20, LV_PART_MAIN | LV_STATE_CHECKED);
                    lv_label_set_text(obj, "Config");
                }
            }
        }
        {
            // DoneButton_WiFi
            lv_obj_t *obj = lv_btn_create(parent_obj);
            objects.done_button_wi_fi = obj;
            lv_obj_set_pos(obj, 325, 711);
            lv_obj_set_size(obj, 145, 80);
            lv_obj_add_event_cb(obj, action_wifi_button, LV_EVENT_RELEASED, (void *)32);
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
                    lv_obj_set_style_text_font(obj, &lv_font_montserrat_32, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_text_font(obj, &lv_font_montserrat_20, LV_PART_MAIN | LV_STATE_CHECKED);
                    lv_label_set_text(obj, "Done");
                }
            }
        }
        {
            lv_obj_t *obj = lv_label_create(parent_obj);
            objects.obj44 = obj;
            lv_obj_set_pos(obj, 140, 54);
            lv_obj_set_size(obj, 205, 30);
            lv_obj_clear_flag(obj, LV_OBJ_FLAG_CLICK_FOCUSABLE|LV_OBJ_FLAG_GESTURE_BUBBLE|LV_OBJ_FLAG_PRESS_LOCK|LV_OBJ_FLAG_SCROLLABLE|LV_OBJ_FLAG_SCROLL_CHAIN_HOR|LV_OBJ_FLAG_SCROLL_CHAIN_VER|LV_OBJ_FLAG_SCROLL_ELASTIC|LV_OBJ_FLAG_SCROLL_MOMENTUM|LV_OBJ_FLAG_SNAPPABLE);
            lv_obj_set_style_text_align(obj, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_font(obj, &lv_font_montserrat_24, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_color(obj, lv_color_hex(0xffffffff), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_label_set_text(obj, "WiFi");
        }
        {
            // taPassword
            lv_obj_t *obj = lv_textarea_create(parent_obj);
            objects.ta_password = obj;
            lv_obj_set_pos(obj, 20, 320);
            lv_obj_set_size(obj, 440, 50);
            lv_textarea_set_max_length(obj, 128);
            lv_textarea_set_placeholder_text(obj, "Password");
            lv_textarea_set_one_line(obj, true);
            lv_textarea_set_password_mode(obj, false);
            lv_obj_set_style_bg_color(obj, lv_color_hex(0xffffffff), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_color(obj, lv_color_hex(0xff000000), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_font(obj, &lv_font_montserrat_24, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_font(obj, &lv_font_montserrat_24, LV_PART_MAIN | LV_STATE_PRESSED);
            lv_obj_set_style_text_font(obj, &lv_font_montserrat_24, LV_PART_SELECTED | LV_STATE_PRESSED);
        }
        {
            // taIpAddress
            lv_obj_t *obj = lv_textarea_create(parent_obj);
            objects.ta_ip_address = obj;
            lv_obj_set_pos(obj, 21, 380);
            lv_obj_set_size(obj, 440, 50);
            lv_textarea_set_max_length(obj, 128);
            lv_textarea_set_placeholder_text(obj, "IP Address");
            lv_textarea_set_one_line(obj, true);
            lv_textarea_set_password_mode(obj, false);
            lv_obj_set_style_bg_color(obj, lv_color_hex(0xffffffff), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_color(obj, lv_color_hex(0xff000000), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_font(obj, &lv_font_montserrat_24, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_font(obj, &lv_font_montserrat_20, LV_PART_MAIN | LV_STATE_PRESSED);
            lv_obj_set_style_text_font(obj, &lv_font_montserrat_24, LV_PART_SELECTED | LV_STATE_PRESSED);
        }
        {
            // taPort
            lv_obj_t *obj = lv_textarea_create(parent_obj);
            objects.ta_port = obj;
            lv_obj_set_pos(obj, 20, 440);
            lv_obj_set_size(obj, 440, 50);
            lv_textarea_set_max_length(obj, 128);
            lv_textarea_set_placeholder_text(obj, "DCC-EX Port");
            lv_textarea_set_one_line(obj, true);
            lv_textarea_set_password_mode(obj, false);
            lv_obj_set_style_bg_color(obj, lv_color_hex(0xffffffff), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_color(obj, lv_color_hex(0xff000000), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_font(obj, &lv_font_montserrat_24, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_opa(obj, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_font(obj, &lv_font_montserrat_20, LV_PART_MAIN | LV_STATE_PRESSED);
            lv_obj_set_style_text_font(obj, &lv_font_montserrat_24, LV_PART_SELECTED | LV_STATE_PRESSED);
        }
        {
            // ddSsids
            lv_obj_t *obj = lv_dropdown_create(parent_obj);
            objects.dd_ssids = obj;
            lv_obj_set_pos(obj, 21, 200);
            lv_obj_set_size(obj, 440, 50);
            lv_dropdown_set_options(obj, "Select from List");
            lv_dropdown_set_selected(obj, 0);
            lv_obj_set_style_bg_color(obj, lv_color_hex(0xffffffff), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_color(obj, lv_color_hex(0xff000000), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_font(obj, &lv_font_montserrat_24, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_font(obj, &lv_font_montserrat_24, LV_PART_MAIN | LV_STATE_PRESSED);
            lv_obj_set_style_text_font(obj, &lv_font_montserrat_24, LV_PART_MAIN | LV_STATE_CHECKED);
            lv_obj_set_style_text_font(obj, &lv_font_montserrat_24, LV_PART_MAIN | LV_STATE_CHECKED | LV_STATE_PRESSED);
            lv_obj_set_style_text_font(obj, &lv_font_montserrat_24, LV_PART_SELECTED | LV_STATE_DEFAULT);
            lv_obj_set_style_text_font(obj, &lv_font_montserrat_24, LV_PART_SELECTED | LV_STATE_CHECKED | LV_STATE_PRESSED);
            lv_obj_set_style_text_font(obj, &lv_font_montserrat_24, LV_PART_SELECTED | LV_STATE_PRESSED);
            {
                lv_obj_t *parent_obj = obj;
                {
                    lv_obj_t *obj = lv_dropdown_get_list(parent_obj);
                    objects.obj45 = obj;
                    lv_obj_set_style_text_font(obj, &lv_font_montserrat_26, LV_PART_MAIN | LV_STATE_CHECKED);
                    lv_obj_set_style_text_color(obj, lv_color_hex(0xff000000), LV_PART_MAIN | LV_STATE_CHECKED);
                    lv_obj_set_style_text_font(obj, &lv_font_montserrat_26, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_text_font(obj, &lv_font_montserrat_26, LV_PART_ITEMS | LV_STATE_DEFAULT);
                }
            }
        }
        {
            // btnConnect
            lv_obj_t *obj = lv_btn_create(parent_obj);
            objects.btn_connect = obj;
            lv_obj_set_pos(obj, 11, 620);
            lv_obj_set_size(obj, 120, 60);
            lv_obj_add_event_cb(obj, action_wifi_button, LV_EVENT_CLICKED, (void *)7);
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
            lv_obj_set_style_shadow_color(obj, lv_color_hex(0xff000000), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_shadow_opa(obj, 127, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_bg_color(obj, lv_color_hex(0xff000000), LV_PART_MAIN | LV_STATE_PRESSED);
            lv_obj_set_style_bg_grad_dir(obj, LV_GRAD_DIR_VER, LV_PART_MAIN | LV_STATE_PRESSED);
            lv_obj_set_style_bg_grad_color(obj, lv_color_hex(0xfffff200), LV_PART_MAIN | LV_STATE_PRESSED);
            lv_obj_set_style_text_color(obj, lv_color_hex(0xff000000), LV_PART_MAIN | LV_STATE_PRESSED);
            lv_obj_set_style_shadow_width(obj, 0, LV_PART_MAIN | LV_STATE_PRESSED);
            lv_obj_set_style_shadow_ofs_x(obj, 0, LV_PART_MAIN | LV_STATE_PRESSED);
            lv_obj_set_style_shadow_ofs_y(obj, 0, LV_PART_MAIN | LV_STATE_PRESSED);
            lv_obj_set_style_shadow_spread(obj, 0, LV_PART_MAIN | LV_STATE_PRESSED);
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
                    lv_obj_set_style_text_font(obj, &lv_font_montserrat_24, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_label_set_text(obj, "Connect");
                }
            }
        }
        {
            // btnWifiPgSave
            lv_obj_t *obj = lv_btn_create(parent_obj);
            objects.btn_wifi_pg_save = obj;
            lv_obj_set_pos(obj, 180, 620);
            lv_obj_set_size(obj, 120, 60);
            lv_obj_add_event_cb(obj, action_wifi_button, LV_EVENT_RELEASED, (void *)8);
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
            lv_obj_set_style_shadow_color(obj, lv_color_hex(0xff000000), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_shadow_opa(obj, 127, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_bg_color(obj, lv_color_hex(0xff000000), LV_PART_MAIN | LV_STATE_PRESSED);
            lv_obj_set_style_bg_grad_dir(obj, LV_GRAD_DIR_VER, LV_PART_MAIN | LV_STATE_PRESSED);
            lv_obj_set_style_bg_grad_color(obj, lv_color_hex(0xfffff200), LV_PART_MAIN | LV_STATE_PRESSED);
            lv_obj_set_style_text_color(obj, lv_color_hex(0xff000000), LV_PART_MAIN | LV_STATE_PRESSED);
            lv_obj_set_style_shadow_width(obj, 0, LV_PART_MAIN | LV_STATE_PRESSED);
            lv_obj_set_style_shadow_ofs_x(obj, 0, LV_PART_MAIN | LV_STATE_PRESSED);
            lv_obj_set_style_shadow_ofs_y(obj, 0, LV_PART_MAIN | LV_STATE_PRESSED);
            lv_obj_set_style_shadow_spread(obj, 0, LV_PART_MAIN | LV_STATE_PRESSED);
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
                    lv_obj_set_style_text_font(obj, &lv_font_montserrat_24, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_label_set_text(obj, "Save");
                }
            }
        }
        {
            // btnWifiEnable
            lv_obj_t *obj = lv_btn_create(parent_obj);
            objects.btn_wifi_enable = obj;
            lv_obj_set_pos(obj, 342, 620);
            lv_obj_set_size(obj, 120, 60);
            lv_obj_add_event_cb(obj, event_handler_unchecked_cb_wi_fi_btn_wifi_enable, LV_EVENT_VALUE_CHANGED, (void *)9);
            lv_obj_add_event_cb(obj, event_handler_checked_cb_wi_fi_btn_wifi_enable, LV_EVENT_VALUE_CHANGED, (void *)10);
            lv_obj_add_flag(obj, LV_OBJ_FLAG_CHECKABLE);
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
            lv_obj_set_style_shadow_color(obj, lv_color_hex(0xff000000), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_shadow_opa(obj, 127, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_bg_color(obj, lv_color_hex(0xff000000), LV_PART_MAIN | LV_STATE_PRESSED);
            lv_obj_set_style_bg_grad_dir(obj, LV_GRAD_DIR_VER, LV_PART_MAIN | LV_STATE_PRESSED);
            lv_obj_set_style_bg_grad_color(obj, lv_color_hex(0xfffff200), LV_PART_MAIN | LV_STATE_PRESSED);
            lv_obj_set_style_text_color(obj, lv_color_hex(0xff000000), LV_PART_MAIN | LV_STATE_PRESSED);
            lv_obj_set_style_shadow_width(obj, 0, LV_PART_MAIN | LV_STATE_PRESSED);
            lv_obj_set_style_shadow_ofs_x(obj, 0, LV_PART_MAIN | LV_STATE_PRESSED);
            lv_obj_set_style_shadow_ofs_y(obj, 0, LV_PART_MAIN | LV_STATE_PRESSED);
            lv_obj_set_style_shadow_spread(obj, 0, LV_PART_MAIN | LV_STATE_PRESSED);
            lv_obj_set_style_bg_opa(obj, 255, LV_PART_MAIN | LV_STATE_CHECKED);
            lv_obj_set_style_bg_grad_dir(obj, LV_GRAD_DIR_NONE, LV_PART_MAIN | LV_STATE_CHECKED);
            lv_obj_set_style_bg_color(obj, lv_color_hex(0xffffff00), LV_PART_MAIN | LV_STATE_CHECKED);
            lv_obj_set_style_shadow_width(obj, 0, LV_PART_MAIN | LV_STATE_CHECKED);
            lv_obj_set_style_shadow_ofs_x(obj, 0, LV_PART_MAIN | LV_STATE_CHECKED);
            lv_obj_set_style_shadow_ofs_y(obj, 0, LV_PART_MAIN | LV_STATE_CHECKED);
            lv_obj_set_style_shadow_spread(obj, 0, LV_PART_MAIN | LV_STATE_CHECKED);
            lv_obj_set_style_text_color(obj, lv_color_hex(0xff000000), LV_PART_MAIN | LV_STATE_CHECKED);
            {
                lv_obj_t *parent_obj = obj;
                {
                    lv_obj_t *obj = lv_label_create(parent_obj);
                    objects.obj48 = obj;
                    lv_obj_set_pos(obj, 0, 0);
                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                    lv_obj_clear_flag(obj, LV_OBJ_FLAG_CLICK_FOCUSABLE|LV_OBJ_FLAG_GESTURE_BUBBLE|LV_OBJ_FLAG_PRESS_LOCK|LV_OBJ_FLAG_SCROLLABLE|LV_OBJ_FLAG_SCROLL_CHAIN_HOR|LV_OBJ_FLAG_SCROLL_CHAIN_VER|LV_OBJ_FLAG_SCROLL_ELASTIC|LV_OBJ_FLAG_SCROLL_MOMENTUM|LV_OBJ_FLAG_SNAPPABLE);
                    lv_obj_set_style_align(obj, LV_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_bg_color(obj, lv_color_hex(0xffffffff), LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_bg_grad_dir(obj, LV_GRAD_DIR_VER, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_bg_grad_color(obj, lv_color_hex(0xff000000), LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_bg_grad_stop(obj, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_text_font(obj, &lv_font_montserrat_24, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_label_set_text(obj, "Enable");
                }
            }
        }
        {
            // taSSID
            lv_obj_t *obj = lv_textarea_create(parent_obj);
            objects.ta_ssid = obj;
            lv_obj_set_pos(obj, 20, 260);
            lv_obj_set_size(obj, 440, 50);
            lv_textarea_set_max_length(obj, 128);
            lv_textarea_set_placeholder_text(obj, "SSID");
            lv_textarea_set_one_line(obj, true);
            lv_textarea_set_password_mode(obj, false);
            lv_obj_set_style_bg_color(obj, lv_color_hex(0xffffffff), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_color(obj, lv_color_hex(0xff000000), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_font(obj, &lv_font_montserrat_24, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_font(obj, &lv_font_montserrat_24, LV_PART_MAIN | LV_STATE_PRESSED);
            lv_obj_set_style_text_font(obj, &lv_font_montserrat_24, LV_PART_SELECTED | LV_STATE_PRESSED);
        }
        {
            // lblWifiStatus
            lv_obj_t *obj = lv_label_create(parent_obj);
            objects.lbl_wifi_status = obj;
            lv_obj_set_pos(obj, 20, 510);
            lv_obj_set_size(obj, 440, LV_SIZE_CONTENT);
            lv_obj_set_style_text_font(obj, &lv_font_montserrat_24, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_color(obj, lv_color_hex(0xffffffff), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_label_set_text(obj, "");
        }
        {
            // lblWifiStatus2
            lv_obj_t *obj = lv_label_create(parent_obj);
            objects.lbl_wifi_status2 = obj;
            lv_obj_set_pos(obj, 20, 550);
            lv_obj_set_size(obj, 440, LV_SIZE_CONTENT);
            lv_obj_set_style_text_font(obj, &lv_font_montserrat_24, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_color(obj, lv_color_hex(0xffffffff), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_label_set_text(obj, "");
        }
        {
            // kbAlpha
            lv_obj_t *obj = lv_keyboard_create(parent_obj);
            objects.kb_alpha = obj;
            lv_obj_set_pos(obj, 1, 491);
            lv_obj_set_size(obj, 479, 309);
            lv_obj_add_flag(obj, LV_OBJ_FLAG_HIDDEN);
            lv_obj_set_style_align(obj, LV_ALIGN_DEFAULT, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_font(obj, &lv_font_montserrat_24, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_font(obj, &lv_font_montserrat_24, LV_PART_MAIN | LV_STATE_PRESSED);
        }
        {
            // kbNumeric
            lv_obj_t *obj = lv_keyboard_create(parent_obj);
            objects.kb_numeric = obj;
            lv_obj_set_pos(obj, 0, 491);
            lv_obj_set_size(obj, 480, 309);
            lv_keyboard_set_mode(obj, LV_KEYBOARD_MODE_NUMBER);
            lv_obj_add_flag(obj, LV_OBJ_FLAG_HIDDEN);
            lv_obj_set_style_align(obj, LV_ALIGN_DEFAULT, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_font(obj, &lv_font_montserrat_24, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_font(obj, &lv_font_montserrat_24, LV_PART_MAIN | LV_STATE_PRESSED);
        }
    }
    lv_keyboard_set_textarea(objects.kb_numeric, objects.ta_port);
    
    tick_screen_wi_fi();
}

void tick_screen_wi_fi() {
}

void create_screen_scan() {
    lv_obj_t *obj = lv_obj_create(0);
    objects.scan = obj;
    lv_obj_set_pos(obj, 0, 0);
    lv_obj_set_size(obj, 480, 800);
    lv_obj_set_style_bg_color(obj, lv_color_hex(0xffc89600), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_transform_width(obj, -2, LV_PART_MAIN | LV_STATE_PRESSED);
    lv_obj_set_style_transform_height(obj, -2, LV_PART_MAIN | LV_STATE_PRESSED);
    {
        lv_obj_t *parent_obj = obj;
        {
            lv_obj_t *obj = lv_btn_create(parent_obj);
            objects.obj49 = obj;
            lv_obj_set_pos(obj, 19, 122);
            lv_obj_set_size(obj, 120, 60);
            lv_obj_add_event_cb(obj, action_scan_button, LV_EVENT_PRESSED, (void *)2);
            lv_obj_add_event_cb(obj, action_scan_button, LV_EVENT_RELEASED, (void *)1);
            lv_obj_set_style_bg_color(obj, lv_color_hex(0xffffffff), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_bg_grad_dir(obj, LV_GRAD_DIR_VER, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_font(obj, &lv_font_montserrat_24, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_border_color(obj, lv_color_hex(0xff000000), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_border_width(obj, 1, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_shadow_width(obj, 10, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_shadow_ofs_x(obj, 5, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_shadow_spread(obj, 2, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_shadow_ofs_y(obj, 5, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_shadow_color(obj, lv_color_hex(0xff000000), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_shadow_opa(obj, 128, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_transform_width(obj, -2, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_transform_height(obj, -2, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_bg_color(obj, lv_color_hex(0xff000000), LV_PART_MAIN | LV_STATE_PRESSED);
            lv_obj_set_style_bg_grad_dir(obj, LV_GRAD_DIR_VER, LV_PART_MAIN | LV_STATE_PRESSED);
            lv_obj_set_style_bg_grad_color(obj, lv_color_hex(0xffffffff), LV_PART_MAIN | LV_STATE_PRESSED);
            lv_obj_set_style_bg_opa(obj, 255, LV_PART_MAIN | LV_STATE_PRESSED);
            lv_obj_set_style_shadow_spread(obj, 0, LV_PART_MAIN | LV_STATE_PRESSED);
            lv_obj_set_style_shadow_color(obj, lv_color_hex(0xff000000), LV_PART_MAIN | LV_STATE_PRESSED);
            lv_obj_set_style_shadow_opa(obj, 128, LV_PART_MAIN | LV_STATE_PRESSED);
            lv_obj_set_style_shadow_width(obj, 0, LV_PART_MAIN | LV_STATE_PRESSED);
            lv_obj_set_style_shadow_ofs_y(obj, 0, LV_PART_MAIN | LV_STATE_PRESSED);
            lv_obj_set_style_transform_width(obj, -5, LV_PART_MAIN | LV_STATE_PRESSED);
            lv_obj_set_style_transform_height(obj, -5, LV_PART_MAIN | LV_STATE_PRESSED);
            lv_obj_set_style_shadow_ofs_x(obj, 0, LV_PART_MAIN | LV_STATE_PRESSED);
            {
                lv_obj_t *parent_obj = obj;
                {
                    lv_obj_t *obj = lv_label_create(parent_obj);
                    lv_obj_set_pos(obj, 0, 0);
                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                    lv_obj_set_style_align(obj, LV_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_label_set_text(obj, "Scan");
                }
            }
        }
        {
            // listScanPgSsids
            lv_obj_t *obj = lv_list_create(parent_obj);
            objects.list_scan_pg_ssids = obj;
            lv_obj_set_pos(obj, 19, 208);
            lv_obj_set_size(obj, 443, 480);
            lv_obj_set_style_text_font(obj, &lv_font_montserrat_24, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_bg_color(obj, lv_color_hex(0xffffffff), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_color(obj, lv_color_hex(0xff000000), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_line_space(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_bg_color(obj, lv_color_hex(0xffffffff), LV_PART_MAIN | LV_STATE_CHECKED);
            lv_obj_set_style_text_font(obj, &lv_font_montserrat_20, LV_PART_MAIN | LV_STATE_CHECKED);
            lv_obj_set_style_text_color(obj, lv_color_hex(0xff000000), LV_PART_MAIN | LV_STATE_CHECKED);
            lv_obj_set_style_bg_color(obj, lv_color_hex(0xffffffff), LV_PART_SCROLLBAR | LV_STATE_FOCUSED);
        }
        {
            // CreditsButton_16
            lv_obj_t *obj = lv_btn_create(parent_obj);
            objects.credits_button_16 = obj;
            lv_obj_set_pos(obj, 11, 711);
            lv_obj_set_size(obj, 145, 80);
            lv_obj_add_event_cb(obj, action_scan_button, LV_EVENT_RELEASED, (void *)30);
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
            {
                lv_obj_t *parent_obj = obj;
                {
                    lv_obj_t *obj = lv_label_create(parent_obj);
                    objects.obj50 = obj;
                    lv_obj_set_pos(obj, 0, 0);
                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                    lv_obj_clear_flag(obj, LV_OBJ_FLAG_CLICK_FOCUSABLE|LV_OBJ_FLAG_GESTURE_BUBBLE|LV_OBJ_FLAG_PRESS_LOCK|LV_OBJ_FLAG_SCROLLABLE|LV_OBJ_FLAG_SCROLL_CHAIN_HOR|LV_OBJ_FLAG_SCROLL_CHAIN_VER|LV_OBJ_FLAG_SCROLL_ELASTIC|LV_OBJ_FLAG_SCROLL_MOMENTUM|LV_OBJ_FLAG_SNAPPABLE);
                    lv_obj_set_style_align(obj, LV_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_bg_color(obj, lv_color_hex(0xffffffff), LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_bg_grad_dir(obj, LV_GRAD_DIR_VER, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_bg_grad_color(obj, lv_color_hex(0xff000000), LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_bg_grad_stop(obj, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_text_font(obj, &lv_font_montserrat_32, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_text_font(obj, &lv_font_montserrat_20, LV_PART_MAIN | LV_STATE_CHECKED);
                    lv_label_set_text(obj, "Config");
                }
            }
        }
        {
            // InfoButton_16
            lv_obj_t *obj = lv_btn_create(parent_obj);
            objects.info_button_16 = obj;
            lv_obj_set_pos(obj, 325, 711);
            lv_obj_set_size(obj, 145, 80);
            lv_obj_add_event_cb(obj, action_scan_button, LV_EVENT_RELEASED, (void *)32);
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
                    lv_obj_set_style_text_font(obj, &lv_font_montserrat_32, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_text_font(obj, &lv_font_montserrat_20, LV_PART_MAIN | LV_STATE_CHECKED);
                    lv_label_set_text(obj, "Done");
                }
            }
        }
        {
            // TxtScanStatus
            lv_obj_t *obj = lv_label_create(parent_obj);
            objects.txt_scan_status = obj;
            lv_obj_set_pos(obj, 160, 136);
            lv_obj_set_size(obj, 300, 36);
            lv_obj_add_event_cb(obj, action_scan_button, LV_EVENT_RELEASED, (void *)2);
            lv_obj_set_style_text_font(obj, &lv_font_montserrat_24, LV_PART_MAIN | LV_STATE_DEFAULT);
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
    lv_obj_set_size(obj, 480, 800);
    lv_obj_set_style_bg_color(obj, lv_color_hex(0xffc89600), LV_PART_MAIN | LV_STATE_DEFAULT);
    {
        lv_obj_t *parent_obj = obj;
        {
            // CreditsButton_7
            lv_obj_t *obj = lv_btn_create(parent_obj);
            objects.credits_button_7 = obj;
            lv_obj_set_pos(obj, 11, 711);
            lv_obj_set_size(obj, 145, 80);
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
                    lv_obj_set_style_text_font(obj, &lv_font_montserrat_32, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_text_font(obj, &lv_font_montserrat_20, LV_PART_MAIN | LV_STATE_CHECKED);
                    lv_label_set_text(obj, "WiFi");
                }
            }
        }
        {
            // TipsButton_7
            lv_obj_t *obj = lv_btn_create(parent_obj);
            objects.tips_button_7 = obj;
            lv_obj_set_pos(obj, 168, 711);
            lv_obj_set_size(obj, 145, 80);
            lv_obj_add_event_cb(obj, action_config_button, LV_EVENT_PRESSED, (void *)31);
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
            lv_obj_set_style_text_font(obj, &lv_font_montserrat_20, LV_PART_MAIN | LV_STATE_CHECKED);
            {
                lv_obj_t *parent_obj = obj;
                {
                    lv_obj_t *obj = lv_label_create(parent_obj);
                    objects.obj53 = obj;
                    lv_obj_set_pos(obj, 0, 0);
                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                    lv_obj_clear_flag(obj, LV_OBJ_FLAG_CLICK_FOCUSABLE|LV_OBJ_FLAG_GESTURE_BUBBLE|LV_OBJ_FLAG_PRESS_LOCK|LV_OBJ_FLAG_SCROLLABLE|LV_OBJ_FLAG_SCROLL_CHAIN_HOR|LV_OBJ_FLAG_SCROLL_CHAIN_VER|LV_OBJ_FLAG_SCROLL_ELASTIC|LV_OBJ_FLAG_SCROLL_MOMENTUM|LV_OBJ_FLAG_SNAPPABLE);
                    lv_obj_set_style_align(obj, LV_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_bg_color(obj, lv_color_hex(0xffffffff), LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_bg_grad_dir(obj, LV_GRAD_DIR_VER, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_bg_grad_color(obj, lv_color_hex(0xff000000), LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_bg_grad_stop(obj, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_text_font(obj, &lv_font_montserrat_32, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_text_font(obj, &lv_font_montserrat_20, LV_PART_MAIN | LV_STATE_CHECKED);
                    lv_label_set_text(obj, "Update");
                }
            }
        }
        {
            // InfoButton_7
            lv_obj_t *obj = lv_btn_create(parent_obj);
            objects.info_button_7 = obj;
            lv_obj_set_pos(obj, 325, 711);
            lv_obj_set_size(obj, 145, 80);
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
                    lv_obj_set_style_text_font(obj, &lv_font_montserrat_32, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_text_font(obj, &lv_font_montserrat_20, LV_PART_MAIN | LV_STATE_CHECKED);
                    lv_label_set_text(obj, "Done");
                }
            }
        }
        {
            lv_obj_t *obj = lv_label_create(parent_obj);
            objects.obj55 = obj;
            lv_obj_set_pos(obj, 140, 54);
            lv_obj_set_size(obj, 205, 30);
            lv_obj_clear_flag(obj, LV_OBJ_FLAG_CLICK_FOCUSABLE|LV_OBJ_FLAG_GESTURE_BUBBLE|LV_OBJ_FLAG_PRESS_LOCK|LV_OBJ_FLAG_SCROLLABLE|LV_OBJ_FLAG_SCROLL_CHAIN_HOR|LV_OBJ_FLAG_SCROLL_CHAIN_VER|LV_OBJ_FLAG_SCROLL_ELASTIC|LV_OBJ_FLAG_SCROLL_MOMENTUM|LV_OBJ_FLAG_SNAPPABLE);
            lv_obj_set_style_text_align(obj, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_font(obj, &lv_font_montserrat_24, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_color(obj, lv_color_hex(0xffffffff), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_label_set_text(obj, "Config");
        }
        {
            lv_obj_t *obj = lv_label_create(parent_obj);
            objects.obj56 = obj;
            lv_obj_set_pos(obj, 10, 139);
            lv_obj_set_size(obj, 340, LV_SIZE_CONTENT);
            lv_obj_set_style_text_color(obj, lv_color_hex(0xffffffff), LV_PART_MAIN | LV_STATE_CHECKED);
            lv_obj_set_style_text_font(obj, &lv_font_montserrat_14, LV_PART_MAIN | LV_STATE_CHECKED);
            lv_obj_set_style_text_color(obj, lv_color_hex(0xffffffff), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_font(obj, &lv_font_montserrat_24, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_label_set_text(obj, "Backlight Brightness");
        }
        {
            lv_obj_t *obj = lv_label_create(parent_obj);
            objects.obj57 = obj;
            lv_obj_set_pos(obj, 10, 185);
            lv_obj_set_size(obj, 360, LV_SIZE_CONTENT);
            lv_obj_set_style_text_color(obj, lv_color_hex(0xffffffff), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_font(obj, &lv_font_montserrat_24, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_label_set_text(obj, "WiFi Timeout");
        }
        {
            // ta_tft_backlight
            lv_obj_t *obj = lv_textarea_create(parent_obj);
            objects.ta_tft_backlight = obj;
            lv_obj_set_pos(obj, 400, 130);
            lv_obj_set_size(obj, 70, 36);
            lv_textarea_set_max_length(obj, 3);
            lv_textarea_set_one_line(obj, true);
            lv_textarea_set_password_mode(obj, false);
            lv_obj_set_style_pad_top(obj, 2, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_bottom(obj, 3, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_font(obj, &lv_font_montserrat_24, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_align(obj, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
        }
        {
            // ta_wifi_timeout
            lv_obj_t *obj = lv_textarea_create(parent_obj);
            objects.ta_wifi_timeout = obj;
            lv_obj_set_pos(obj, 400, 180);
            lv_obj_set_size(obj, 70, 36);
            lv_textarea_set_max_length(obj, 3);
            lv_textarea_set_one_line(obj, true);
            lv_textarea_set_password_mode(obj, false);
            lv_obj_set_style_pad_top(obj, 2, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_bottom(obj, 3, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_font(obj, &lv_font_montserrat_24, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_align(obj, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
        }
        {
            lv_obj_t *obj = lv_label_create(parent_obj);
            objects.obj58 = obj;
            lv_obj_set_pos(obj, 10, 235);
            lv_obj_set_size(obj, 360, LV_SIZE_CONTENT);
            lv_obj_set_style_text_color(obj, lv_color_hex(0xffffffff), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_font(obj, &lv_font_montserrat_24, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_label_set_text(obj, "Rotary Encoder Acceleration");
        }
        {
            // ta_re_accel
            lv_obj_t *obj = lv_textarea_create(parent_obj);
            objects.ta_re_accel = obj;
            lv_obj_set_pos(obj, 400, 230);
            lv_obj_set_size(obj, 70, 36);
            lv_textarea_set_max_length(obj, 3);
            lv_textarea_set_one_line(obj, true);
            lv_textarea_set_password_mode(obj, false);
            lv_obj_set_style_pad_top(obj, 2, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_bottom(obj, 3, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_font(obj, &lv_font_montserrat_24, LV_PART_MAIN | LV_STATE_DEFAULT);
        }
        {
            lv_obj_t *obj = lv_label_create(parent_obj);
            objects.obj59 = obj;
            lv_obj_set_pos(obj, 10, 285);
            lv_obj_set_size(obj, 360, LV_SIZE_CONTENT);
            lv_obj_set_style_text_color(obj, lv_color_hex(0xffffffff), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_font(obj, &lv_font_montserrat_24, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_label_set_text(obj, "Function Column Space");
        }
        {
            // ta_func_col
            lv_obj_t *obj = lv_textarea_create(parent_obj);
            objects.ta_func_col = obj;
            lv_obj_set_pos(obj, 400, 280);
            lv_obj_set_size(obj, 70, 36);
            lv_textarea_set_max_length(obj, 3);
            lv_textarea_set_one_line(obj, true);
            lv_textarea_set_password_mode(obj, false);
            lv_obj_set_style_pad_top(obj, 2, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_bottom(obj, 3, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_font(obj, &lv_font_montserrat_24, LV_PART_MAIN | LV_STATE_DEFAULT);
        }
        {
            lv_obj_t *obj = lv_label_create(parent_obj);
            objects.obj60 = obj;
            lv_obj_set_pos(obj, 10, 335);
            lv_obj_set_size(obj, 370, LV_SIZE_CONTENT);
            lv_obj_set_style_text_color(obj, lv_color_hex(0xffffffff), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_font(obj, &lv_font_montserrat_24, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_label_set_text(obj, "Max Speed for Instant Reverse");
        }
        {
            // ta_threshold
            lv_obj_t *obj = lv_textarea_create(parent_obj);
            objects.ta_threshold = obj;
            lv_obj_set_pos(obj, 400, 330);
            lv_obj_set_size(obj, 70, 36);
            lv_textarea_set_max_length(obj, 3);
            lv_textarea_set_one_line(obj, true);
            lv_textarea_set_password_mode(obj, false);
            lv_obj_set_style_pad_top(obj, 2, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_bottom(obj, 3, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_font(obj, &lv_font_montserrat_24, LV_PART_MAIN | LV_STATE_DEFAULT);
        }
        {
            // lbl_list_status
            lv_obj_t *obj = lv_label_create(parent_obj);
            objects.lbl_list_status = obj;
            lv_obj_set_pos(obj, 20, 647);
            lv_obj_set_size(obj, 450, LV_SIZE_CONTENT);
            lv_obj_set_style_text_font(obj, &lv_font_montserrat_24, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_label_set_text(obj, "");
        }
        {
            lv_obj_t *obj = lv_label_create(parent_obj);
            objects.obj61 = obj;
            lv_obj_set_pos(obj, 10, 394);
            lv_obj_set_size(obj, 249, LV_SIZE_CONTENT);
            lv_obj_set_style_text_color(obj, lv_color_hex(0xffffffff), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_font(obj, &lv_font_montserrat_24, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_label_set_text(obj, "Roster at Startup");
        }
        {
            // btn_Roster
            lv_obj_t *obj = lv_btn_create(parent_obj);
            objects.btn_roster = obj;
            lv_obj_set_pos(obj, 400, 388);
            lv_obj_set_size(obj, 36, 36);
            lv_obj_add_event_cb(obj, event_handler_unchecked_cb_config_btn_roster, LV_EVENT_VALUE_CHANGED, (void *)24);
            lv_obj_add_event_cb(obj, event_handler_checked_cb_config_btn_roster, LV_EVENT_VALUE_CHANGED, (void *)25);
            lv_obj_add_flag(obj, LV_OBJ_FLAG_CHECKABLE);
            lv_obj_set_style_bg_color(obj, lv_color_hex(0xffffffff), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_bg_grad_dir(obj, LV_GRAD_DIR_VER, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_bg_grad_color(obj, lv_color_hex(0xff000000), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_border_color(obj, lv_color_hex(0xff000000), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_border_width(obj, 1, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_shadow_width(obj, 5, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_shadow_ofs_x(obj, 3, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_shadow_ofs_y(obj, 3, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_shadow_spread(obj, 2, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_shadow_color(obj, lv_color_hex(0xff000000), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_shadow_opa(obj, 127, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_font(obj, &lv_font_montserrat_20, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_bg_color(obj, lv_color_hex(0xffffff00), LV_PART_MAIN | LV_STATE_CHECKED);
            lv_obj_set_style_bg_opa(obj, 255, LV_PART_MAIN | LV_STATE_CHECKED);
            lv_obj_set_style_bg_grad_dir(obj, LV_GRAD_DIR_NONE, LV_PART_MAIN | LV_STATE_CHECKED);
            lv_obj_set_style_bg_grad_color(obj, lv_color_hex(0xffffffff), LV_PART_MAIN | LV_STATE_CHECKED);
            lv_obj_set_style_shadow_width(obj, 0, LV_PART_MAIN | LV_STATE_CHECKED);
            lv_obj_set_style_shadow_ofs_x(obj, 0, LV_PART_MAIN | LV_STATE_CHECKED);
            lv_obj_set_style_shadow_ofs_y(obj, 0, LV_PART_MAIN | LV_STATE_CHECKED);
            lv_obj_set_style_shadow_spread(obj, 0, LV_PART_MAIN | LV_STATE_CHECKED);
            lv_obj_set_style_bg_color(obj, lv_color_hex(0xffffffff), LV_PART_MAIN | LV_STATE_PRESSED);
            lv_obj_set_style_bg_grad_dir(obj, LV_GRAD_DIR_VER, LV_PART_MAIN | LV_STATE_PRESSED);
            lv_obj_set_style_bg_grad_color(obj, lv_color_hex(0xff000000), LV_PART_MAIN | LV_STATE_PRESSED);
        }
        {
            // lbl_btn_Roster
            lv_obj_t *obj = lv_label_create(parent_obj);
            objects.lbl_btn_roster = obj;
            lv_obj_set_pos(obj, 90, 6);
            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
            lv_obj_set_style_align(obj, LV_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_font(obj, &lv_font_montserrat_24, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_label_set_text(obj, "Local");
        }
        {
            lv_obj_t *obj = lv_label_create(parent_obj);
            objects.obj62 = obj;
            lv_obj_set_pos(obj, 10, 444);
            lv_obj_set_size(obj, 270, LV_SIZE_CONTENT);
            lv_obj_set_style_text_color(obj, lv_color_hex(0xffffffff), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_font(obj, &lv_font_montserrat_24, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_label_set_text(obj, "Accessories at Startup");
        }
        {
            // btn_Acc
            lv_obj_t *obj = lv_btn_create(parent_obj);
            objects.btn_acc = obj;
            lv_obj_set_pos(obj, 400, 438);
            lv_obj_set_size(obj, 36, 36);
            lv_obj_add_event_cb(obj, event_handler_unchecked_cb_config_btn_acc, LV_EVENT_VALUE_CHANGED, (void *)26);
            lv_obj_add_event_cb(obj, event_handler_checked_cb_config_btn_acc, LV_EVENT_VALUE_CHANGED, (void *)27);
            lv_obj_add_flag(obj, LV_OBJ_FLAG_CHECKABLE);
            lv_obj_set_style_bg_color(obj, lv_color_hex(0xffffffff), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_bg_grad_dir(obj, LV_GRAD_DIR_VER, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_bg_grad_color(obj, lv_color_hex(0xff000000), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_border_color(obj, lv_color_hex(0xff000000), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_border_width(obj, 1, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_shadow_width(obj, 5, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_shadow_ofs_x(obj, 3, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_shadow_ofs_y(obj, 3, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_shadow_spread(obj, 2, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_shadow_color(obj, lv_color_hex(0xff000000), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_shadow_opa(obj, 127, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_font(obj, &lv_font_montserrat_20, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_bg_color(obj, lv_color_hex(0xffffff00), LV_PART_MAIN | LV_STATE_CHECKED);
            lv_obj_set_style_bg_opa(obj, 255, LV_PART_MAIN | LV_STATE_CHECKED);
            lv_obj_set_style_bg_grad_dir(obj, LV_GRAD_DIR_NONE, LV_PART_MAIN | LV_STATE_CHECKED);
            lv_obj_set_style_bg_grad_color(obj, lv_color_hex(0xffffffff), LV_PART_MAIN | LV_STATE_CHECKED);
            lv_obj_set_style_shadow_width(obj, 0, LV_PART_MAIN | LV_STATE_CHECKED);
            lv_obj_set_style_shadow_ofs_x(obj, 0, LV_PART_MAIN | LV_STATE_CHECKED);
            lv_obj_set_style_shadow_ofs_y(obj, 0, LV_PART_MAIN | LV_STATE_CHECKED);
            lv_obj_set_style_shadow_spread(obj, 0, LV_PART_MAIN | LV_STATE_CHECKED);
            lv_obj_set_style_bg_color(obj, lv_color_hex(0xffffffff), LV_PART_MAIN | LV_STATE_PRESSED);
            lv_obj_set_style_bg_grad_dir(obj, LV_GRAD_DIR_VER, LV_PART_MAIN | LV_STATE_PRESSED);
            lv_obj_set_style_bg_grad_color(obj, lv_color_hex(0xff000000), LV_PART_MAIN | LV_STATE_PRESSED);
        }
        {
            // lbl_btn_Acc
            lv_obj_t *obj = lv_label_create(parent_obj);
            objects.lbl_btn_acc = obj;
            lv_obj_set_pos(obj, 90, 58);
            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
            lv_obj_set_style_align(obj, LV_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_font(obj, &lv_font_montserrat_24, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_label_set_text(obj, "Local");
        }
        {
            // Current_Roster
            lv_obj_t *obj = lv_label_create(parent_obj);
            objects.current_roster = obj;
            lv_obj_set_pos(obj, 10, 494);
            lv_obj_set_size(obj, 240, LV_SIZE_CONTENT);
            lv_obj_set_style_text_color(obj, lv_color_hex(0xffffffff), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_font(obj, &lv_font_montserrat_24, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_label_set_text(obj, "Load Local Lists");
        }
        {
            // btnLoadLocal
            lv_obj_t *obj = lv_btn_create(parent_obj);
            objects.btn_load_local = obj;
            lv_obj_set_pos(obj, 400, 488);
            lv_obj_set_size(obj, 36, 36);
            lv_obj_add_event_cb(obj, event_handler_checked_cb_config_btn_load_local, LV_EVENT_VALUE_CHANGED, (void *)28);
            lv_obj_add_flag(obj, LV_OBJ_FLAG_CHECKABLE);
            lv_obj_set_style_bg_color(obj, lv_color_hex(0xffffffff), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_bg_grad_dir(obj, LV_GRAD_DIR_VER, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_bg_grad_color(obj, lv_color_hex(0xff000000), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_border_color(obj, lv_color_hex(0xff000000), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_border_width(obj, 1, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_shadow_width(obj, 5, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_shadow_ofs_x(obj, 3, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_shadow_ofs_y(obj, 3, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_shadow_spread(obj, 2, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_shadow_color(obj, lv_color_hex(0xff000000), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_shadow_opa(obj, 127, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_font(obj, &lv_font_montserrat_20, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_bg_color(obj, lv_color_hex(0xffffff00), LV_PART_MAIN | LV_STATE_CHECKED);
            lv_obj_set_style_bg_opa(obj, 255, LV_PART_MAIN | LV_STATE_CHECKED);
            lv_obj_set_style_bg_grad_dir(obj, LV_GRAD_DIR_NONE, LV_PART_MAIN | LV_STATE_CHECKED);
            lv_obj_set_style_bg_grad_color(obj, lv_color_hex(0xffffffff), LV_PART_MAIN | LV_STATE_CHECKED);
            lv_obj_set_style_shadow_width(obj, 0, LV_PART_MAIN | LV_STATE_CHECKED);
            lv_obj_set_style_shadow_ofs_x(obj, 0, LV_PART_MAIN | LV_STATE_CHECKED);
            lv_obj_set_style_shadow_ofs_y(obj, 0, LV_PART_MAIN | LV_STATE_CHECKED);
            lv_obj_set_style_shadow_spread(obj, 0, LV_PART_MAIN | LV_STATE_CHECKED);
            lv_obj_set_style_bg_color(obj, lv_color_hex(0xffffffff), LV_PART_MAIN | LV_STATE_PRESSED);
            lv_obj_set_style_bg_grad_dir(obj, LV_GRAD_DIR_VER, LV_PART_MAIN | LV_STATE_PRESSED);
            lv_obj_set_style_bg_grad_color(obj, lv_color_hex(0xff000000), LV_PART_MAIN | LV_STATE_PRESSED);
        }
        {
            // kbd_config
            lv_obj_t *obj = lv_keyboard_create(parent_obj);
            objects.kbd_config = obj;
            lv_obj_set_pos(obj, 16, 553);
            lv_obj_set_size(obj, 459, 243);
            lv_keyboard_set_mode(obj, LV_KEYBOARD_MODE_NUMBER);
            lv_obj_add_flag(obj, LV_OBJ_FLAG_HIDDEN);
            lv_obj_set_style_align(obj, LV_ALIGN_DEFAULT, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_font(obj, &lv_font_montserrat_24, LV_PART_MAIN | LV_STATE_DEFAULT);
        }
        {
            // Current_Roster_1
            lv_obj_t *obj = lv_label_create(parent_obj);
            objects.current_roster_1 = obj;
            lv_obj_set_pos(obj, 11, 544);
            lv_obj_set_size(obj, 240, LV_SIZE_CONTENT);
            lv_obj_set_style_text_color(obj, lv_color_hex(0xffffffff), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_font(obj, &lv_font_montserrat_24, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_label_set_text(obj, "Rotary Encoder");
        }
        {
            // btnReEnable
            lv_obj_t *obj = lv_btn_create(parent_obj);
            objects.btn_re_enable = obj;
            lv_obj_set_pos(obj, 400, 538);
            lv_obj_set_size(obj, 36, 36);
            lv_obj_add_event_cb(obj, event_handler_unchecked_cb_config_btn_re_enable, LV_EVENT_VALUE_CHANGED, (void *)22);
            lv_obj_add_event_cb(obj, event_handler_checked_cb_config_btn_re_enable, LV_EVENT_VALUE_CHANGED, (void *)23);
            lv_obj_add_flag(obj, LV_OBJ_FLAG_CHECKABLE);
            lv_obj_set_style_bg_color(obj, lv_color_hex(0xffffffff), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_bg_grad_dir(obj, LV_GRAD_DIR_VER, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_bg_grad_color(obj, lv_color_hex(0xff000000), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_border_color(obj, lv_color_hex(0xff000000), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_border_width(obj, 1, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_shadow_width(obj, 5, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_shadow_ofs_x(obj, 3, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_shadow_ofs_y(obj, 3, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_shadow_spread(obj, 2, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_shadow_color(obj, lv_color_hex(0xff000000), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_shadow_opa(obj, 127, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_font(obj, &lv_font_montserrat_20, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_bg_color(obj, lv_color_hex(0xffffff00), LV_PART_MAIN | LV_STATE_CHECKED);
            lv_obj_set_style_bg_opa(obj, 255, LV_PART_MAIN | LV_STATE_CHECKED);
            lv_obj_set_style_bg_grad_dir(obj, LV_GRAD_DIR_NONE, LV_PART_MAIN | LV_STATE_CHECKED);
            lv_obj_set_style_bg_grad_color(obj, lv_color_hex(0xffffffff), LV_PART_MAIN | LV_STATE_CHECKED);
            lv_obj_set_style_shadow_width(obj, 0, LV_PART_MAIN | LV_STATE_CHECKED);
            lv_obj_set_style_shadow_ofs_x(obj, 0, LV_PART_MAIN | LV_STATE_CHECKED);
            lv_obj_set_style_shadow_ofs_y(obj, 0, LV_PART_MAIN | LV_STATE_CHECKED);
            lv_obj_set_style_shadow_spread(obj, 0, LV_PART_MAIN | LV_STATE_CHECKED);
            lv_obj_set_style_bg_color(obj, lv_color_hex(0xffffffff), LV_PART_MAIN | LV_STATE_PRESSED);
            lv_obj_set_style_bg_grad_dir(obj, LV_GRAD_DIR_VER, LV_PART_MAIN | LV_STATE_PRESSED);
            lv_obj_set_style_bg_grad_color(obj, lv_color_hex(0xff000000), LV_PART_MAIN | LV_STATE_PRESSED);
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
    lv_obj_set_size(obj, 480, 800);
    lv_obj_set_style_bg_color(obj, lv_color_hex(0xffc89600), LV_PART_MAIN | LV_STATE_DEFAULT);
    {
        lv_obj_t *parent_obj = obj;
        {
            // CreditsButton_13
            lv_obj_t *obj = lv_btn_create(parent_obj);
            objects.credits_button_13 = obj;
            lv_obj_set_pos(obj, 11, 711);
            lv_obj_set_size(obj, 145, 80);
            lv_obj_add_event_cb(obj, action_general_button, LV_EVENT_CLICKED, (void *)8);
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
            lv_obj_set_style_text_font(obj, &lv_font_montserrat_20, LV_PART_MAIN | LV_STATE_CHECKED);
            {
                lv_obj_t *parent_obj = obj;
                {
                    lv_obj_t *obj = lv_label_create(parent_obj);
                    objects.obj63 = obj;
                    lv_obj_set_pos(obj, 0, 0);
                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                    lv_obj_clear_flag(obj, LV_OBJ_FLAG_CLICK_FOCUSABLE|LV_OBJ_FLAG_GESTURE_BUBBLE|LV_OBJ_FLAG_PRESS_LOCK|LV_OBJ_FLAG_SCROLLABLE|LV_OBJ_FLAG_SCROLL_CHAIN_HOR|LV_OBJ_FLAG_SCROLL_CHAIN_VER|LV_OBJ_FLAG_SCROLL_ELASTIC|LV_OBJ_FLAG_SCROLL_MOMENTUM|LV_OBJ_FLAG_SNAPPABLE);
                    lv_obj_set_style_align(obj, LV_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_bg_color(obj, lv_color_hex(0xffffffff), LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_bg_grad_dir(obj, LV_GRAD_DIR_VER, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_bg_grad_color(obj, lv_color_hex(0xff000000), LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_bg_grad_stop(obj, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_text_font(obj, &lv_font_montserrat_32, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_text_font(obj, &lv_font_montserrat_20, LV_PART_MAIN | LV_STATE_CHECKED);
                    lv_label_set_text(obj, "Info");
                }
            }
        }
        {
            // InfoButton_13
            lv_obj_t *obj = lv_btn_create(parent_obj);
            objects.info_button_13 = obj;
            lv_obj_set_pos(obj, 325, 711);
            lv_obj_set_size(obj, 145, 80);
            lv_obj_add_event_cb(obj, action_general_button, LV_EVENT_CLICKED, (void *)5);
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
            lv_obj_set_style_text_font(obj, &lv_font_montserrat_20, LV_PART_MAIN | LV_STATE_CHECKED);
            {
                lv_obj_t *parent_obj = obj;
                {
                    lv_obj_t *obj = lv_label_create(parent_obj);
                    objects.obj64 = obj;
                    lv_obj_set_pos(obj, 0, 0);
                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                    lv_obj_clear_flag(obj, LV_OBJ_FLAG_CLICK_FOCUSABLE|LV_OBJ_FLAG_GESTURE_BUBBLE|LV_OBJ_FLAG_PRESS_LOCK|LV_OBJ_FLAG_SCROLLABLE|LV_OBJ_FLAG_SCROLL_CHAIN_HOR|LV_OBJ_FLAG_SCROLL_CHAIN_VER|LV_OBJ_FLAG_SCROLL_ELASTIC|LV_OBJ_FLAG_SCROLL_MOMENTUM|LV_OBJ_FLAG_SNAPPABLE);
                    lv_obj_set_style_align(obj, LV_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_bg_color(obj, lv_color_hex(0xffffffff), LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_bg_grad_dir(obj, LV_GRAD_DIR_VER, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_bg_grad_color(obj, lv_color_hex(0xff000000), LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_bg_grad_stop(obj, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_text_font(obj, &lv_font_montserrat_32, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_text_font(obj, &lv_font_montserrat_20, LV_PART_MAIN | LV_STATE_CHECKED);
                    lv_label_set_text(obj, "Done");
                }
            }
        }
        {
            lv_obj_t *obj = lv_label_create(parent_obj);
            objects.obj65 = obj;
            lv_obj_set_pos(obj, 140, 54);
            lv_obj_set_size(obj, 205, 30);
            lv_obj_clear_flag(obj, LV_OBJ_FLAG_CLICK_FOCUSABLE|LV_OBJ_FLAG_GESTURE_BUBBLE|LV_OBJ_FLAG_PRESS_LOCK|LV_OBJ_FLAG_SCROLLABLE|LV_OBJ_FLAG_SCROLL_CHAIN_HOR|LV_OBJ_FLAG_SCROLL_CHAIN_VER|LV_OBJ_FLAG_SCROLL_ELASTIC|LV_OBJ_FLAG_SCROLL_MOMENTUM|LV_OBJ_FLAG_SNAPPABLE);
            lv_obj_set_style_text_align(obj, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_font(obj, &lv_font_montserrat_24, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_color(obj, lv_color_hex(0xffffffff), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_label_set_text(obj, "Credits");
        }
        {
            lv_obj_t *obj = lv_label_create(parent_obj);
            lv_obj_set_pos(obj, 11, 370);
            lv_obj_set_size(obj, 459, LV_SIZE_CONTENT);
            lv_obj_set_style_text_font(obj, &lv_font_montserrat_24, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_label_set_text(obj, "Those who helped with this updated release:\n\nSteve (esfeld)\nErik (erik84750)\nLee (mtncityman)\nMichele (michele2796)\nHardy (discord review)\nRosscoe (PlatformIO Integration)\n\nMy sincere thanks to ALL! Norm(normhal)");
        }
        {
            lv_obj_t *obj = lv_label_create(parent_obj);
            lv_obj_set_pos(obj, 11, 108);
            lv_obj_set_size(obj, 459, 87);
            lv_obj_set_style_text_font(obj, &lv_font_montserrat_24, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_label_set_text(obj, "Full credit goes to EEZ Studio without which this project would not have been possible!");
        }
        {
            lv_obj_t *obj = lv_label_create(parent_obj);
            lv_obj_set_pos(obj, 10, 210);
            lv_obj_set_size(obj, 460, LV_SIZE_CONTENT);
            lv_obj_set_style_text_font(obj, &lv_font_montserrat_24, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_label_set_text(obj, "The \"CYC\" acronym is a credit to the originator of the  CYD abbreviaation. ");
        }
        {
            lv_obj_t *obj = lv_label_create(parent_obj);
            lv_obj_set_pos(obj, 13, 274);
            lv_obj_set_size(obj, 460, LV_SIZE_CONTENT);
            lv_obj_set_style_text_font(obj, &lv_font_montserrat_24, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_font(obj, &lv_font_montserrat_12, LV_PART_MAIN | LV_STATE_PRESSED);
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
    lv_obj_set_size(obj, 480, 800);
    lv_obj_set_style_bg_color(obj, lv_color_hex(0xffc89600), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(obj, 10, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_ofs_x(obj, 5, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_ofs_y(obj, 2, LV_PART_MAIN | LV_STATE_DEFAULT);
    {
        lv_obj_t *parent_obj = obj;
        {
            // CreditsButton_14
            lv_obj_t *obj = lv_btn_create(parent_obj);
            objects.credits_button_14 = obj;
            lv_obj_set_pos(obj, 11, 711);
            lv_obj_set_size(obj, 145, 80);
            lv_obj_add_event_cb(obj, action_general_button, LV_EVENT_RELEASED, (void *)6);
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
            lv_obj_set_style_text_font(obj, &lv_font_montserrat_20, LV_PART_MAIN | LV_STATE_CHECKED);
            {
                lv_obj_t *parent_obj = obj;
                {
                    lv_obj_t *obj = lv_label_create(parent_obj);
                    objects.obj66 = obj;
                    lv_obj_set_pos(obj, 0, 0);
                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                    lv_obj_clear_flag(obj, LV_OBJ_FLAG_CLICK_FOCUSABLE|LV_OBJ_FLAG_GESTURE_BUBBLE|LV_OBJ_FLAG_PRESS_LOCK|LV_OBJ_FLAG_SCROLLABLE|LV_OBJ_FLAG_SCROLL_CHAIN_HOR|LV_OBJ_FLAG_SCROLL_CHAIN_VER|LV_OBJ_FLAG_SCROLL_ELASTIC|LV_OBJ_FLAG_SCROLL_MOMENTUM|LV_OBJ_FLAG_SNAPPABLE);
                    lv_obj_set_style_align(obj, LV_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_bg_color(obj, lv_color_hex(0xffffffff), LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_bg_grad_dir(obj, LV_GRAD_DIR_VER, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_bg_grad_color(obj, lv_color_hex(0xff000000), LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_bg_grad_stop(obj, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_text_font(obj, &lv_font_montserrat_32, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_text_font(obj, &lv_font_montserrat_20, LV_PART_MAIN | LV_STATE_CHECKED);
                    lv_label_set_text(obj, "Credits");
                }
            }
        }
        {
            // InfoButton_14
            lv_obj_t *obj = lv_btn_create(parent_obj);
            objects.info_button_14 = obj;
            lv_obj_set_pos(obj, 325, 711);
            lv_obj_set_size(obj, 145, 80);
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
            lv_obj_set_style_text_font(obj, &lv_font_montserrat_20, LV_PART_MAIN | LV_STATE_CHECKED);
            {
                lv_obj_t *parent_obj = obj;
                {
                    lv_obj_t *obj = lv_label_create(parent_obj);
                    objects.obj67 = obj;
                    lv_obj_set_pos(obj, 0, 0);
                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                    lv_obj_clear_flag(obj, LV_OBJ_FLAG_CLICK_FOCUSABLE|LV_OBJ_FLAG_GESTURE_BUBBLE|LV_OBJ_FLAG_PRESS_LOCK|LV_OBJ_FLAG_SCROLLABLE|LV_OBJ_FLAG_SCROLL_CHAIN_HOR|LV_OBJ_FLAG_SCROLL_CHAIN_VER|LV_OBJ_FLAG_SCROLL_ELASTIC|LV_OBJ_FLAG_SCROLL_MOMENTUM|LV_OBJ_FLAG_SNAPPABLE);
                    lv_obj_set_style_align(obj, LV_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_bg_color(obj, lv_color_hex(0xffffffff), LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_bg_grad_dir(obj, LV_GRAD_DIR_VER, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_bg_grad_color(obj, lv_color_hex(0xff000000), LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_bg_grad_stop(obj, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_text_font(obj, &lv_font_montserrat_32, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_text_font(obj, &lv_font_montserrat_20, LV_PART_MAIN | LV_STATE_CHECKED);
                    lv_label_set_text(obj, "Done");
                }
            }
        }
        {
            lv_obj_t *obj = lv_label_create(parent_obj);
            objects.obj68 = obj;
            lv_obj_set_pos(obj, 140, 54);
            lv_obj_set_size(obj, 205, 30);
            lv_obj_clear_flag(obj, LV_OBJ_FLAG_CLICK_FOCUSABLE|LV_OBJ_FLAG_GESTURE_BUBBLE|LV_OBJ_FLAG_PRESS_LOCK|LV_OBJ_FLAG_SCROLLABLE|LV_OBJ_FLAG_SCROLL_CHAIN_HOR|LV_OBJ_FLAG_SCROLL_CHAIN_VER|LV_OBJ_FLAG_SCROLL_ELASTIC|LV_OBJ_FLAG_SCROLL_MOMENTUM|LV_OBJ_FLAG_SNAPPABLE);
            lv_obj_set_style_text_align(obj, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_font(obj, &lv_font_montserrat_24, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_color(obj, lv_color_hex(0xffffffff), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_label_set_text(obj, "Information");
        }
        {
            lv_obj_t *obj = lv_label_create(parent_obj);
            lv_obj_set_pos(obj, 11, 108);
            lv_obj_set_size(obj, 459, LV_SIZE_CONTENT);
            lv_obj_set_style_text_font(obj, &lv_font_montserrat_24, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_label_set_text(obj, "Tools Used and References\nEEZ Studio Version 0.23.2\n(https://www.envox.eu)\n\nArduino IDEs and Libraries\nESP32 Boards Version 2.0.17\nlvgl Version 8.4\n\nWhilst everything here is \"Open Source\", I request you respect the originality of everyone's work.\n\n(c) Norm Halland (normhal)\nnormhal@gmail.com\nhttps://github.com/normhal/\nCheapYellowController\n\nAugust 2025");
        }
        {
            lv_obj_t *obj = lv_label_create(parent_obj);
            lv_obj_set_pos(obj, 194, 756);
            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
            lv_obj_set_style_text_align(obj, LV_TEXT_ALIGN_LEFT, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_font(obj, &lv_font_montserrat_20, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_label_set_text(obj, "Sketch:");
        }
        {
            // lblSketchBuild
            lv_obj_t *obj = lv_label_create(parent_obj);
            objects.lbl_sketch_build = obj;
            lv_obj_set_pos(obj, 276, 756);
            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
            lv_obj_set_style_text_font(obj, &lv_font_montserrat_20, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_label_set_text(obj, "");
        }
        {
            lv_obj_t *obj = lv_label_create(parent_obj);
            lv_obj_set_pos(obj, 164, 726);
            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
            lv_obj_set_style_text_align(obj, LV_TEXT_ALIGN_LEFT, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_font(obj, &lv_font_montserrat_20, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_label_set_text(obj, "EEZ Build:");
        }
        {
            // lblEEZBuild
            lv_obj_t *obj = lv_label_create(parent_obj);
            objects.lbl_eez_build = obj;
            lv_obj_set_pos(obj, 276, 726);
            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
            lv_obj_set_style_text_font(obj, &lv_font_montserrat_20, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_label_set_text(obj, "1.3.1");
        }
    }
    
    tick_screen_info();
}

void tick_screen_info() {
}

void create_screen_layout() {
    lv_obj_t *obj = lv_obj_create(0);
    objects.layout = obj;
    lv_obj_set_pos(obj, 0, 0);
    lv_obj_set_size(obj, 480, 800);
    lv_obj_add_flag(obj, LV_OBJ_FLAG_CHECKABLE);
    lv_obj_set_style_bg_color(obj, lv_color_hex(0xffc89600), LV_PART_MAIN | LV_STATE_DEFAULT);
    {
        lv_obj_t *parent_obj = obj;
        {
            lv_obj_t *obj = lv_label_create(parent_obj);
            objects.obj69 = obj;
            lv_obj_set_pos(obj, 180, 54);
            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
            lv_obj_set_style_text_color(obj, lv_color_hex(0xffffffff), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_font(obj, &lv_font_montserrat_24, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_label_set_text(obj, "Lee's Layout");
        }
        {
            lv_obj_t *obj = lv_img_create(parent_obj);
            lv_obj_set_pos(obj, 380, 130);
            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
        }
        {
            lv_obj_t *obj = lv_img_create(parent_obj);
            lv_obj_set_pos(obj, 420, 460);
            lv_obj_set_size(obj, 60, 60);
            lv_img_set_src(obj, &img_60x60_straight_v);
        }
        {
            lv_obj_t *obj = lv_img_create(parent_obj);
            lv_obj_set_pos(obj, 420, 160);
            lv_obj_set_size(obj, 60, 60);
            lv_img_set_src(obj, &img_60x60_lh_turn_0);
        }
        {
            lv_obj_t *obj = lv_img_create(parent_obj);
            lv_obj_set_pos(obj, 60, 100);
            lv_obj_set_size(obj, 60, 60);
            lv_img_set_src(obj, &img_60x60_lh_turn_270);
        }
        {
            lv_obj_t *obj = lv_img_create(parent_obj);
            lv_obj_set_pos(obj, 120, 100);
            lv_obj_set_size(obj, 60, 60);
            lv_img_set_src(obj, &img_60x60_straight_h);
        }
        {
            lv_obj_t *obj = lv_img_create(parent_obj);
            lv_obj_set_pos(obj, 180, 100);
            lv_obj_set_size(obj, 60, 60);
            lv_img_set_src(obj, &img_60x60_straight_h);
        }
        {
            lv_obj_t *obj = lv_img_create(parent_obj);
            lv_obj_set_pos(obj, 240, 100);
            lv_obj_set_size(obj, 60, 60);
            lv_img_set_src(obj, &img_60x60_straight_h);
        }
        {
            lv_obj_t *obj = lv_img_create(parent_obj);
            lv_obj_set_pos(obj, 300, 100);
            lv_obj_set_size(obj, 60, 60);
            lv_img_set_src(obj, &img_60x60_straight_h);
        }
        {
            lv_obj_t *obj = lv_img_create(parent_obj);
            lv_obj_set_pos(obj, 420, 220);
            lv_obj_set_size(obj, 60, 60);
            lv_img_set_src(obj, &img_60x60_straight_v);
        }
        {
            lv_obj_t *obj = lv_img_create(parent_obj);
            lv_obj_set_pos(obj, 420, 280);
            lv_obj_set_size(obj, 60, 60);
            lv_img_set_src(obj, &img_60x60_straight_v);
        }
        {
            lv_obj_t *obj = lv_img_create(parent_obj);
            lv_obj_set_pos(obj, 420, 340);
            lv_obj_set_size(obj, 60, 60);
            lv_img_set_src(obj, &img_60x60_straight_v);
        }
        {
            lv_obj_t *obj = lv_img_create(parent_obj);
            lv_obj_set_pos(obj, 420, 400);
            lv_obj_set_size(obj, 60, 60);
            lv_img_set_src(obj, &img_60x60_straight_v);
        }
        {
            lv_obj_t *obj = lv_img_create(parent_obj);
            lv_obj_set_pos(obj, 420, 520);
            lv_obj_set_size(obj, 60, 60);
            lv_img_set_src(obj, &img_60x60_straight_v);
        }
        {
            lv_obj_t *obj = lv_img_create(parent_obj);
            lv_obj_set_pos(obj, 420, 580);
            lv_obj_set_size(obj, 60, 60);
            lv_img_set_src(obj, &img_60x60_rh_turn_180);
        }
        {
            lv_obj_t *obj = lv_img_create(parent_obj);
            lv_obj_set_pos(obj, 0, 160);
            lv_obj_set_size(obj, 60, 60);
            lv_img_set_src(obj, &img_60x60_rh_turn_0);
        }
        {
            // CancelButton_7
            lv_obj_t *obj = lv_btn_create(parent_obj);
            objects.cancel_button_7 = obj;
            lv_obj_set_pos(obj, 11, 710);
            lv_obj_set_size(obj, 145, 80);
            lv_obj_add_event_cb(obj, action_turnout_button, LV_EVENT_RELEASED, (void *)30);
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
            lv_obj_set_style_text_font(obj, &lv_font_montserrat_20, LV_PART_MAIN | LV_STATE_CHECKED);
            {
                lv_obj_t *parent_obj = obj;
                {
                    lv_obj_t *obj = lv_label_create(parent_obj);
                    objects.obj70 = obj;
                    lv_obj_set_pos(obj, 0, 0);
                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                    lv_obj_clear_flag(obj, LV_OBJ_FLAG_CLICK_FOCUSABLE|LV_OBJ_FLAG_GESTURE_BUBBLE|LV_OBJ_FLAG_PRESS_LOCK|LV_OBJ_FLAG_SCROLLABLE|LV_OBJ_FLAG_SCROLL_CHAIN_HOR|LV_OBJ_FLAG_SCROLL_CHAIN_VER|LV_OBJ_FLAG_SCROLL_ELASTIC|LV_OBJ_FLAG_SCROLL_MOMENTUM|LV_OBJ_FLAG_SNAPPABLE);
                    lv_obj_set_style_align(obj, LV_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_bg_color(obj, lv_color_hex(0xffffffff), LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_bg_grad_dir(obj, LV_GRAD_DIR_VER, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_bg_grad_color(obj, lv_color_hex(0xff000000), LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_bg_grad_stop(obj, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_text_font(obj, &lv_font_montserrat_32, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_text_font(obj, &lv_font_montserrat_20, LV_PART_MAIN | LV_STATE_CHECKED);
                    lv_label_set_text(obj, "Cancel");
                }
            }
        }
        {
            // DoneButton_7
            lv_obj_t *obj = lv_btn_create(parent_obj);
            objects.done_button_7 = obj;
            lv_obj_set_pos(obj, 325, 710);
            lv_obj_set_size(obj, 145, 80);
            lv_obj_add_event_cb(obj, action_turnout_button, LV_EVENT_RELEASED, (void *)32);
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
            lv_obj_set_style_text_font(obj, &lv_font_montserrat_20, LV_PART_MAIN | LV_STATE_CHECKED);
            {
                lv_obj_t *parent_obj = obj;
                {
                    lv_obj_t *obj = lv_label_create(parent_obj);
                    objects.obj71 = obj;
                    lv_obj_set_pos(obj, 0, 0);
                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                    lv_obj_clear_flag(obj, LV_OBJ_FLAG_CLICK_FOCUSABLE|LV_OBJ_FLAG_GESTURE_BUBBLE|LV_OBJ_FLAG_PRESS_LOCK|LV_OBJ_FLAG_SCROLLABLE|LV_OBJ_FLAG_SCROLL_CHAIN_HOR|LV_OBJ_FLAG_SCROLL_CHAIN_VER|LV_OBJ_FLAG_SCROLL_ELASTIC|LV_OBJ_FLAG_SCROLL_MOMENTUM|LV_OBJ_FLAG_SNAPPABLE);
                    lv_obj_set_style_align(obj, LV_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_bg_color(obj, lv_color_hex(0xffffffff), LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_bg_grad_dir(obj, LV_GRAD_DIR_VER, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_bg_grad_color(obj, lv_color_hex(0xff000000), LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_bg_grad_stop(obj, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_text_font(obj, &lv_font_montserrat_32, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_text_font(obj, &lv_font_montserrat_20, LV_PART_MAIN | LV_STATE_CHECKED);
                    lv_label_set_text(obj, "Done");
                }
            }
        }
        {
            lv_obj_t *obj = lv_img_create(parent_obj);
            lv_obj_set_pos(obj, 360, 100);
            lv_obj_set_size(obj, 60, 60);
            lv_img_set_src(obj, &img_60x60_rh_turn_90);
        }
        {
            lv_obj_t *obj = lv_img_create(parent_obj);
            lv_obj_set_pos(obj, 360, 640);
            lv_obj_set_size(obj, 60, 60);
            lv_img_set_src(obj, &img_60x60_lh_turn_90);
        }
        {
            lv_obj_t *obj = lv_img_create(parent_obj);
            lv_obj_set_pos(obj, 120, 640);
            lv_obj_set_size(obj, 60, 60);
            lv_img_set_src(obj, &img_60x60_straight_h);
        }
        {
            lv_obj_t *obj = lv_img_create(parent_obj);
            lv_obj_set_pos(obj, 180, 640);
            lv_obj_set_size(obj, 60, 60);
            lv_img_set_src(obj, &img_60x60_straight_h);
        }
        {
            lv_obj_t *obj = lv_img_create(parent_obj);
            lv_obj_set_pos(obj, 240, 640);
            lv_obj_set_size(obj, 60, 60);
            lv_img_set_src(obj, &img_60x60_straight_h);
        }
        {
            lv_obj_t *obj = lv_img_create(parent_obj);
            lv_obj_set_pos(obj, 300, 640);
            lv_obj_set_size(obj, 60, 60);
            lv_img_set_src(obj, &img_60x60_straight_h);
        }
        {
            lv_obj_t *obj = lv_img_create(parent_obj);
            lv_obj_set_pos(obj, 60, 640);
            lv_obj_set_size(obj, 60, 60);
            lv_img_set_src(obj, &img_60x60_rh_turn_270);
        }
        {
            lv_obj_t *obj = lv_img_create(parent_obj);
            lv_obj_set_pos(obj, 0, 580);
            lv_obj_set_size(obj, 60, 60);
            lv_img_set_src(obj, &img_60x60_lh_turn_180);
        }
        {
            lv_obj_t *obj = lv_img_create(parent_obj);
            lv_obj_set_pos(obj, 0, 340);
            lv_obj_set_size(obj, 60, 60);
            lv_img_set_src(obj, &img_60x60_straight_v);
        }
        {
            lv_obj_t *obj = lv_img_create(parent_obj);
            lv_obj_set_pos(obj, 0, 280);
            lv_obj_set_size(obj, 60, 60);
            lv_img_set_src(obj, &img_60x60_straight_v);
        }
        {
            lv_obj_t *obj = lv_img_create(parent_obj);
            lv_obj_set_pos(obj, 0, 220);
            lv_obj_set_size(obj, 60, 60);
            lv_img_set_src(obj, &img_60x60_straight_v);
        }
        {
            lv_obj_t *obj = lv_img_create(parent_obj);
            lv_obj_set_pos(obj, 0, 520);
            lv_obj_set_size(obj, 60, 60);
            lv_img_set_src(obj, &img_60x60_straight_v);
        }
        {
            lv_obj_t *obj = lv_img_create(parent_obj);
            lv_obj_set_pos(obj, 360, 220);
            lv_obj_set_size(obj, 60, 60);
            lv_img_set_src(obj, &img_60x60_lh_turn_0);
        }
        {
            lv_obj_t *obj = lv_img_create(parent_obj);
            lv_obj_set_pos(obj, 360, 280);
            lv_obj_set_size(obj, 60, 60);
            lv_img_set_src(obj, &img_60x60_straight_v);
        }
        {
            lv_obj_t *obj = lv_img_create(parent_obj);
            lv_obj_set_pos(obj, 360, 460);
            lv_obj_set_size(obj, 60, 60);
            lv_img_set_src(obj, &img_60x60_straight_v);
            lv_img_set_angle(obj, 9000);
        }
        {
            lv_obj_t *obj = lv_img_create(parent_obj);
            lv_obj_set_pos(obj, 360, 520);
            lv_obj_set_size(obj, 60, 60);
            lv_img_set_src(obj, &img_60x60_rh_turn_180);
        }
        {
            lv_obj_t *obj = lv_img_create(parent_obj);
            lv_obj_set_pos(obj, 300, 160);
            lv_obj_set_size(obj, 60, 60);
            lv_img_set_src(obj, &img_60x60_rh_turn_90);
        }
        {
            lv_obj_t *obj = lv_img_create(parent_obj);
            lv_obj_set_pos(obj, 180, 160);
            lv_obj_set_size(obj, 60, 60);
            lv_img_set_src(obj, &img_60x60_lh_turn_270);
        }
        {
            lv_obj_t *obj = lv_img_create(parent_obj);
            lv_obj_set_pos(obj, 240, 160);
            lv_obj_set_size(obj, 60, 60);
            lv_img_set_src(obj, &img_60x60_straight_h);
        }
        {
            lv_obj_t *obj = lv_img_create(parent_obj);
            lv_obj_set_pos(obj, 300, 580);
            lv_obj_set_size(obj, 60, 60);
            lv_img_set_src(obj, &img_60x60_lh_turn_90);
        }
        {
            lv_obj_t *obj = lv_img_create(parent_obj);
            lv_obj_set_pos(obj, 240, 580);
            lv_obj_set_size(obj, 60, 60);
            lv_img_set_src(obj, &img_60x60_straight_h);
        }
        {
            lv_obj_t *obj = lv_img_create(parent_obj);
            lv_obj_set_pos(obj, 180, 580);
            lv_obj_set_size(obj, 60, 60);
            lv_img_set_src(obj, &img_60x60_straight_h);
        }
        {
            lv_obj_t *obj = lv_img_create(parent_obj);
            lv_obj_set_pos(obj, 120, 580);
            lv_obj_set_size(obj, 60, 60);
            lv_img_set_src(obj, &img_60x60_rh_turn_270);
        }
        {
            lv_obj_t *obj = lv_img_create(parent_obj);
            lv_obj_set_pos(obj, 60, 520);
            lv_obj_set_size(obj, 60, 60);
            lv_img_set_src(obj, &img_60x60_lh_turn_180);
        }
        {
            lv_obj_t *obj = lv_img_create(parent_obj);
            lv_obj_set_pos(obj, 120, 220);
            lv_obj_set_size(obj, 60, 60);
            lv_img_set_src(obj, &img_60x60_rh_turn_0);
        }
        {
            lv_obj_t *obj = lv_img_create(parent_obj);
            lv_obj_set_pos(obj, 60, 340);
            lv_obj_set_size(obj, 60, 60);
            lv_img_set_src(obj, &img_60x60_rh_curve_0);
        }
        {
            lv_obj_t *obj = lv_img_create(parent_obj);
            lv_obj_set_pos(obj, 120, 340);
            lv_obj_set_size(obj, 60, 60);
            lv_img_set_src(obj, &img_60x60_straight_v);
        }
        {
            lv_obj_t *obj = lv_img_create(parent_obj);
            lv_obj_set_pos(obj, 120, 460);
            lv_obj_set_size(obj, 60, 60);
            lv_img_set_src(obj, &img_60x60_lh_turn_180);
        }
        {
            lv_obj_t *obj = lv_img_create(parent_obj);
            lv_obj_set_pos(obj, 180, 520);
            lv_obj_set_size(obj, 60, 60);
            lv_img_set_src(obj, &img_60x60_rh_turn_270);
        }
        {
            lv_obj_t *obj = lv_img_create(parent_obj);
            lv_obj_set_pos(obj, 240, 520);
            lv_obj_set_size(obj, 60, 60);
            lv_img_set_src(obj, &img_60x60_lh_turn_90);
        }
        {
            lv_obj_t *obj = lv_img_create(parent_obj);
            lv_obj_set_pos(obj, 300, 460);
            lv_obj_set_size(obj, 60, 60);
            lv_img_set_src(obj, &img_60x60_rh_turn_180);
        }
        {
            lv_obj_t *obj = lv_img_create(parent_obj);
            lv_obj_set_pos(obj, 300, 280);
            lv_obj_set_size(obj, 60, 60);
            lv_img_set_src(obj, &img_60x60_lh_turn_0);
        }
        {
            lv_obj_t *obj = lv_img_create(parent_obj);
            lv_obj_set_pos(obj, 240, 220);
            lv_obj_set_size(obj, 60, 60);
            lv_img_set_src(obj, &img_60x60_straight_3);
        }
        {
            lv_obj_t *obj = lv_img_create(parent_obj);
            lv_obj_set_pos(obj, 240, 460);
            lv_obj_set_size(obj, 60, 60);
            lv_img_set_src(obj, &img_60x60_straight_h);
        }
        {
            // btnDC
            lv_obj_t *obj = lv_btn_create(parent_obj);
            objects.btn_dc = obj;
            lv_obj_set_pos(obj, 120, 280);
            lv_obj_set_size(obj, 60, 60);
            lv_obj_add_event_cb(obj, event_handler_checked_cb_layout_btn_dc, LV_EVENT_VALUE_CHANGED, (void *)1);
            lv_obj_add_event_cb(obj, event_handler_unchecked_cb_layout_btn_dc, LV_EVENT_VALUE_CHANGED, (void *)0);
            lv_obj_add_flag(obj, LV_OBJ_FLAG_CHECKABLE);
            lv_obj_set_style_bg_img_src(obj, &img_60x60_rh_yellow_closed_180, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_bg_color(obj, lv_color_hex(0xffc89600), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_bg_opa(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_border_color(obj, lv_color_hex(0xffc89600), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_outline_color(obj, lv_color_hex(0xffc89600), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_shadow_width(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_shadow_ofs_y(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_shadow_opa(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_bg_img_src(obj, &img_60x60_rh_yellow_thrown_180, LV_PART_MAIN | LV_STATE_CHECKED);
            lv_obj_set_style_bg_color(obj, lv_color_hex(0xffc89600), LV_PART_MAIN | LV_STATE_PRESSED);
            lv_obj_set_style_bg_opa(obj, 0, LV_PART_MAIN | LV_STATE_PRESSED);
            lv_obj_set_style_border_color(obj, lv_color_hex(0xffc89600), LV_PART_MAIN | LV_STATE_PRESSED);
            lv_obj_set_style_outline_color(obj, lv_color_hex(0xffc89600), LV_PART_MAIN | LV_STATE_PRESSED);
            {
                lv_obj_t *parent_obj = obj;
                {
                    // lbl_DC
                    lv_obj_t *obj = lv_label_create(parent_obj);
                    objects.lbl_dc = obj;
                    lv_obj_set_pos(obj, 0, 0);
                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                    lv_obj_add_flag(obj, LV_OBJ_FLAG_HIDDEN);
                    lv_obj_set_style_align(obj, LV_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_text_color(obj, lv_color_hex(0xff000000), LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_text_font(obj, &lv_font_montserrat_36, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_label_set_text(obj, "1");
                }
            }
        }
        {
            // btnFA
            lv_obj_t *obj = lv_btn_create(parent_obj);
            objects.btn_fa = obj;
            lv_obj_set_pos(obj, 0, 400);
            lv_obj_set_size(obj, 120, 120);
            lv_obj_add_event_cb(obj, event_handler_checked_cb_layout_btn_fa, LV_EVENT_VALUE_CHANGED, (void *)1);
            lv_obj_add_event_cb(obj, event_handler_unchecked_cb_layout_btn_fa, LV_EVENT_VALUE_CHANGED, (void *)0);
            lv_obj_add_flag(obj, LV_OBJ_FLAG_CHECKABLE);
            lv_obj_set_style_bg_img_src(obj, &img_120x120_kato_x_yellow_closed_0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_bg_color(obj, lv_color_hex(0xffc89600), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_bg_opa(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_shadow_width(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_shadow_ofs_y(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_bg_img_src(obj, &img_120x120_kato_x_yellow_0, LV_PART_MAIN | LV_STATE_CHECKED);
            {
                lv_obj_t *parent_obj = obj;
                {
                    // lblFA
                    lv_obj_t *obj = lv_label_create(parent_obj);
                    objects.lbl_fa = obj;
                    lv_obj_set_pos(obj, 0, 0);
                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                    lv_obj_add_flag(obj, LV_OBJ_FLAG_HIDDEN);
                    lv_obj_set_style_align(obj, LV_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_text_color(obj, lv_color_hex(0xff000000), LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_text_font(obj, &lv_font_montserrat_36, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_text_font(obj, &lv_font_montserrat_36, LV_PART_MAIN | LV_STATE_CHECKED);
                    lv_label_set_text(obj, "3");
                }
            }
        }
        {
            // btnFG
            lv_obj_t *obj = lv_btn_create(parent_obj);
            objects.btn_fg = obj;
            lv_obj_set_pos(obj, 300, 340);
            lv_obj_set_size(obj, 120, 120);
            lv_obj_add_event_cb(obj, event_handler_checked_cb_layout_btn_fg, LV_EVENT_VALUE_CHANGED, (void *)1);
            lv_obj_add_event_cb(obj, event_handler_unchecked_cb_layout_btn_fg, LV_EVENT_VALUE_CHANGED, (void *)0);
            lv_obj_add_flag(obj, LV_OBJ_FLAG_CHECKABLE);
            lv_obj_set_style_bg_img_src(obj, &img_120x120_kato_x_yellow_closed_0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_bg_color(obj, lv_color_hex(0xffc89600), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_bg_opa(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_shadow_width(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_shadow_ofs_y(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_color(obj, lv_color_hex(0xff000000), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_font(obj, &lv_font_montserrat_36, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_bg_img_src(obj, &img_120x120_kato_x_yellow_0, LV_PART_MAIN | LV_STATE_CHECKED);
            {
                lv_obj_t *parent_obj = obj;
                {
                    // lblFG
                    lv_obj_t *obj = lv_label_create(parent_obj);
                    objects.lbl_fg = obj;
                    lv_obj_set_pos(obj, 0, 0);
                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                    lv_obj_add_flag(obj, LV_OBJ_FLAG_HIDDEN);
                    lv_obj_set_style_align(obj, LV_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_text_color(obj, lv_color_hex(0xff000000), LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_text_font(obj, &lv_font_montserrat_36, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_label_set_text(obj, "0");
                }
            }
        }
        {
            // btnEC
            lv_obj_t *obj = lv_btn_create(parent_obj);
            objects.btn_ec = obj;
            lv_obj_set_pos(obj, 120, 400);
            lv_obj_set_size(obj, 60, 60);
            lv_obj_add_event_cb(obj, event_handler_checked_cb_layout_btn_ec, LV_EVENT_VALUE_CHANGED, (void *)1);
            lv_obj_add_event_cb(obj, event_handler_unchecked_cb_layout_btn_ec, LV_EVENT_VALUE_CHANGED, (void *)0);
            lv_obj_add_flag(obj, LV_OBJ_FLAG_CHECKABLE);
            lv_obj_set_style_bg_img_src(obj, &img_60x60_lh_yellow_closed_180, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_bg_color(obj, lv_color_hex(0xffc89600), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_shadow_width(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_shadow_ofs_y(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_border_color(obj, lv_color_hex(0xffc89600), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_outline_color(obj, lv_color_hex(0xffc89600), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_bg_opa(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_bg_img_src(obj, &img_60x60_lh_yellow_thrown_180, LV_PART_MAIN | LV_STATE_CHECKED);
            lv_obj_set_style_bg_opa(obj, 0, LV_PART_MAIN | LV_STATE_CHECKED);
            lv_obj_set_style_bg_color(obj, lv_color_hex(0xffc89600), LV_PART_MAIN | LV_STATE_CHECKED);
            lv_obj_set_style_bg_color(obj, lv_color_hex(0xffc89600), LV_PART_MAIN | LV_STATE_PRESSED);
            lv_obj_set_style_bg_opa(obj, 0, LV_PART_MAIN | LV_STATE_PRESSED);
            lv_obj_set_style_border_color(obj, lv_color_hex(0xffc89600), LV_PART_MAIN | LV_STATE_PRESSED);
            lv_obj_set_style_outline_color(obj, lv_color_hex(0xffc89600), LV_PART_MAIN | LV_STATE_PRESSED);
            lv_obj_set_style_bg_opa(obj, 0, LV_PART_MAIN | LV_STATE_CHECKED | LV_STATE_PRESSED);
            {
                lv_obj_t *parent_obj = obj;
                {
                    // lblFC
                    lv_obj_t *obj = lv_label_create(parent_obj);
                    objects.lbl_fc = obj;
                    lv_obj_set_pos(obj, 0, 0);
                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                    lv_obj_add_flag(obj, LV_OBJ_FLAG_HIDDEN);
                    lv_obj_set_style_align(obj, LV_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_text_color(obj, lv_color_hex(0xff000000), LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_text_font(obj, &lv_font_montserrat_36, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_label_set_text(obj, "2");
                }
            }
        }
        {
            // EditButton
            lv_obj_t *obj = lv_btn_create(parent_obj);
            objects.edit_button = obj;
            lv_obj_set_pos(obj, 169, 710);
            lv_obj_set_size(obj, 145, 80);
            lv_obj_add_event_cb(obj, event_handler_checked_cb_layout_edit_button, LV_EVENT_VALUE_CHANGED, (void *)31);
            lv_obj_add_flag(obj, LV_OBJ_FLAG_CHECKABLE);
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
            lv_obj_set_style_text_font(obj, &lv_font_montserrat_20, LV_PART_MAIN | LV_STATE_CHECKED);
            lv_obj_set_style_shadow_width(obj, 10, LV_PART_MAIN | LV_STATE_CHECKED);
            lv_obj_set_style_shadow_ofs_x(obj, 0, LV_PART_MAIN | LV_STATE_CHECKED);
            lv_obj_set_style_shadow_ofs_y(obj, 0, LV_PART_MAIN | LV_STATE_CHECKED);
            lv_obj_set_style_shadow_spread(obj, 0, LV_PART_MAIN | LV_STATE_CHECKED);
            {
                lv_obj_t *parent_obj = obj;
                {
                    lv_obj_t *obj = lv_label_create(parent_obj);
                    objects.obj72 = obj;
                    lv_obj_set_pos(obj, 0, 0);
                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                    lv_obj_clear_flag(obj, LV_OBJ_FLAG_CLICK_FOCUSABLE|LV_OBJ_FLAG_GESTURE_BUBBLE|LV_OBJ_FLAG_PRESS_LOCK|LV_OBJ_FLAG_SCROLLABLE|LV_OBJ_FLAG_SCROLL_CHAIN_HOR|LV_OBJ_FLAG_SCROLL_CHAIN_VER|LV_OBJ_FLAG_SCROLL_ELASTIC|LV_OBJ_FLAG_SCROLL_MOMENTUM|LV_OBJ_FLAG_SNAPPABLE);
                    lv_obj_set_style_align(obj, LV_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_bg_color(obj, lv_color_hex(0xffffffff), LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_bg_grad_dir(obj, LV_GRAD_DIR_VER, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_bg_grad_color(obj, lv_color_hex(0xff000000), LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_bg_grad_stop(obj, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_text_font(obj, &lv_font_montserrat_32, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_text_font(obj, &lv_font_montserrat_20, LV_PART_MAIN | LV_STATE_CHECKED);
                    lv_label_set_text(obj, "Edit");
                }
            }
        }
        {
            lv_obj_t *obj = lv_img_create(parent_obj);
            lv_obj_set_pos(obj, 180, 460);
            lv_obj_set_size(obj, 60, 60);
            lv_img_set_src(obj, &img_60x60_rh_turn_270);
        }
        {
            lv_obj_t *obj = lv_img_create(parent_obj);
            lv_obj_set_pos(obj, 60, 340);
            lv_obj_set_size(obj, 60, 60);
            lv_img_set_src(obj, &img_60x60_rh_turn_0);
        }
    }
    
    tick_screen_layout();
}

void tick_screen_layout() {
}



typedef void (*tick_screen_func_t)();
tick_screen_func_t tick_screen_funcs[] = {
    tick_screen_main,
    tick_screen_throttle,
    tick_screen_roster,
    tick_screen_edit_loco,
    tick_screen_functions,
    tick_screen_program,
    tick_screen_accessories,
    tick_screen_edit_acc,
    tick_screen_wi_fi,
    tick_screen_scan,
    tick_screen_config,
    tick_screen_credits,
    tick_screen_info,
    tick_screen_layout,
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
    create_screen_functions();
    create_screen_program();
    create_screen_accessories();
    create_screen_edit_acc();
    create_screen_wi_fi();
    create_screen_scan();
    create_screen_config();
    create_screen_credits();
    create_screen_info();
    create_screen_layout();
}
