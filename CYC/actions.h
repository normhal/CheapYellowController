#ifndef EEZ_LVGL_UI_EVENTS_H
#define EEZ_LVGL_UI_EVENTS_H

#include <lvgl.h>

#ifdef __cplusplus
extern "C" {
#endif

extern void action_present_button(lv_event_t * e);
extern void action_activate_keyboard(lv_event_t * e);
extern void action_scan_for_ssi_ds(lv_event_t * e);
extern void action_activate_akeyboard(lv_event_t * e);
extern void action_activate_nkeyboard(lv_event_t * e);
extern void action_general_button(lv_event_t * e);
extern void action_menu_button(lv_event_t * e);
extern void action_throttle_button(lv_event_t * e);
extern void action_program_button(lv_event_t * e);
extern void action_accessories_button(lv_event_t * e);
extern void action_routes_button(lv_event_t * e);
extern void action_edit_acc_button(lv_event_t * e);
extern void action_edit_loco_button(lv_event_t * e);
extern void action_updates_button(lv_event_t * e);
extern void action_selection_button(lv_event_t * e);
extern void action_config_button(lv_event_t * e);
extern void action_wifi_button(lv_event_t * e);
extern void action_credits_button(lv_event_t * e);
extern void action_info_button(lv_event_t * e);
extern void action_tips_button(lv_event_t * e);
extern void action_page_up(lv_event_t * e);
extern void action_page_down(lv_event_t * e);
extern void action_main_button(lv_event_t * e);
extern void action_roster_button(lv_event_t * e);
extern void action_goto_scan(lv_event_t * e);
extern void action_do_scan(lv_event_t * e);
extern void action_scan_button(lv_event_t * e);
extern void action_fedit_slot(lv_event_t * e);
extern void action_fclear_slot(lv_event_t * e);
extern void action_functions_button(lv_event_t * e);
extern void action_turnout_button(lv_event_t * e);


#ifdef __cplusplus
}
#endif

#endif /*EEZ_LVGL_UI_EVENTS_H*/