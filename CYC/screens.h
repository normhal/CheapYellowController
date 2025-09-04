#ifndef EEZ_LVGL_UI_SCREENS_H
#define EEZ_LVGL_UI_SCREENS_H

#include <lvgl.h>

#ifdef __cplusplus
extern "C" {
#endif

typedef struct _objects_t {
    lv_obj_t *main;
    lv_obj_t *throttle;
    lv_obj_t *roster;
    lv_obj_t *edit_loco;
    lv_obj_t *functions;
    lv_obj_t *program;
    lv_obj_t *accessories;
    lv_obj_t *edit_acc;
    lv_obj_t *wi_fi;
    lv_obj_t *scan;
    lv_obj_t *config;
    lv_obj_t *credits;
    lv_obj_t *info;
    lv_obj_t *layout;
    lv_obj_t *btn_stop;
    lv_obj_t *btn_power;
    lv_obj_t *sw_dir;
    lv_obj_t *ta_guest_address;
    lv_obj_t *btn_edit_loco;
    lv_obj_t *btn_select_loco;
    lv_obj_t *btn_s0;
    lv_obj_t *btn_s1;
    lv_obj_t *btn_s2;
    lv_obj_t *btn_s3;
    lv_obj_t *btn_s4;
    lv_obj_t *btn_s5;
    lv_obj_t *btn_s6;
    lv_obj_t *btn_s7;
    lv_obj_t *btn_s8;
    lv_obj_t *btn_s9;
    lv_obj_t *btn_read;
    lv_obj_t *btn_write;
    lv_obj_t *btn_wifi_enable;
    lv_obj_t *btn_roster;
    lv_obj_t *btn_acc;
    lv_obj_t *btn_load_local;
    lv_obj_t *btn_re_enable;
    lv_obj_t *btn_dc;
    lv_obj_t *btn_fa;
    lv_obj_t *btn_fg;
    lv_obj_t *btn_ec;
    lv_obj_t *edit_button;
    lv_obj_t *btn_home;
    lv_obj_t *obj0;
    lv_obj_t *lbl_stop;
    lv_obj_t *lbl_power;
    lv_obj_t *h_line;
    lv_obj_t *credits_button;
    lv_obj_t *obj1;
    lv_obj_t *info_button;
    lv_obj_t *obj2;
    lv_obj_t *obj3;
    lv_obj_t *throttle_mtx;
    lv_obj_t *menu_mtx;
    lv_obj_t *img_wifi;
    lv_obj_t *credits_button_1;
    lv_obj_t *obj4;
    lv_obj_t *tips_button_1;
    lv_obj_t *obj5;
    lv_obj_t *info_button_1;
    lv_obj_t *obj6;
    lv_obj_t *lbl_throttle_page;
    lv_obj_t *dd_locos;
    lv_obj_t *btn_edit;
    lv_obj_t *obj7;
    lv_obj_t *lbl_address;
    lv_obj_t *functions_mtx;
    lv_obj_t *slider;
    lv_obj_t *lbl_slider;
    lv_obj_t *kbd_guest;
    lv_obj_t *obj8;
    lv_obj_t *obj9;
    lv_obj_t *obj10;
    lv_obj_t *btn_cancel_edit_loco;
    lv_obj_t *obj11;
    lv_obj_t *obj12;
    lv_obj_t *obj13;
    lv_obj_t *obj14;
    lv_obj_t *tbl_roster;
    lv_obj_t *cancel_button_3;
    lv_obj_t *obj15;
    lv_obj_t *prog_button_3;
    lv_obj_t *obj16;
    lv_obj_t *done_button_3;
    lv_obj_t *obj17;
    lv_obj_t *obj18;
    lv_obj_t *obj19;
    lv_obj_t *ta_address;
    lv_obj_t *ta_name;
    lv_obj_t *ta_fname;
    lv_obj_t *f_option;
    lv_obj_t *ta_fnum;
    lv_obj_t *lbl_s0;
    lv_obj_t *fn_0;
    lv_obj_t *lbl_s1;
    lv_obj_t *fn_1;
    lv_obj_t *lbl_s2;
    lv_obj_t *fn_2;
    lv_obj_t *lbl_s3;
    lv_obj_t *fn_3;
    lv_obj_t *lbl_s4;
    lv_obj_t *fn_4;
    lv_obj_t *lbl_s5;
    lv_obj_t *fn_5;
    lv_obj_t *lbl_s6;
    lv_obj_t *fn_6;
    lv_obj_t *lbl_s7;
    lv_obj_t *fn_7;
    lv_obj_t *lbl_s8;
    lv_obj_t *fn_8;
    lv_obj_t *lbl_s9;
    lv_obj_t *fn_9;
    lv_obj_t *a_kbd_edit_loco;
    lv_obj_t *n_kbd_edit_loco;
    lv_obj_t *ex_functions_mtx;
    lv_obj_t *func_description;
    lv_obj_t *obj20;
    lv_obj_t *done_button_4;
    lv_obj_t *obj21;
    lv_obj_t *cancel_button_5;
    lv_obj_t *obj22;
    lv_obj_t *btn_fedit;
    lv_obj_t *obj23;
    lv_obj_t *cancel_button_6;
    lv_obj_t *obj24;
    lv_obj_t *done_button_6;
    lv_obj_t *obj25;
    lv_obj_t *obj26;
    lv_obj_t *track_mtx;
    lv_obj_t *obj27;
    lv_obj_t *obj28;
    lv_obj_t *obj29;
    lv_obj_t *ta_cvn;
    lv_obj_t *ta_cvv;
    lv_obj_t *ta_adr;
    lv_obj_t *cv_mtx;
    lv_obj_t *lbl_ps1;
    lv_obj_t *lbl_ps2;
    lv_obj_t *kbd_program;
    lv_obj_t *acc_edit_button;
    lv_obj_t *obj30;
    lv_obj_t *done_button_8;
    lv_obj_t *obj31;
    lv_obj_t *obj32;
    lv_obj_t *btn_page_up;
    lv_obj_t *obj33;
    lv_obj_t *btn_page_down;
    lv_obj_t *obj34;
    lv_obj_t *acc_state_mtx;
    lv_obj_t *acc_name_mtx;
    lv_obj_t *group_btn;
    lv_obj_t *cancel_button_9;
    lv_obj_t *obj35;
    lv_obj_t *done_button_9;
    lv_obj_t *obj36;
    lv_obj_t *obj37;
    lv_obj_t *obj38;
    lv_obj_t *ta_acc_id;
    lv_obj_t *ta_acc_name;
    lv_obj_t *obj39;
    lv_obj_t *ta_acc_option;
    lv_obj_t *ta_acc_address;
    lv_obj_t *obj40;
    lv_obj_t *a_kbd_acc;
    lv_obj_t *n_kbd_acc;
    lv_obj_t *btn_wifi_scan;
    lv_obj_t *obj41;
    lv_obj_t *config_button_wi_fi;
    lv_obj_t *obj42;
    lv_obj_t *done_button_wi_fi;
    lv_obj_t *obj43;
    lv_obj_t *obj44;
    lv_obj_t *ta_password;
    lv_obj_t *ta_ip_address;
    lv_obj_t *ta_port;
    lv_obj_t *dd_ssids;
    lv_obj_t *obj45;
    lv_obj_t *btn_connect;
    lv_obj_t *obj46;
    lv_obj_t *btn_wifi_pg_save;
    lv_obj_t *obj47;
    lv_obj_t *obj48;
    lv_obj_t *ta_ssid;
    lv_obj_t *lbl_wifi_status;
    lv_obj_t *lbl_wifi_status2;
    lv_obj_t *kb_alpha;
    lv_obj_t *kb_numeric;
    lv_obj_t *obj49;
    lv_obj_t *list_scan_pg_ssids;
    lv_obj_t *credits_button_16;
    lv_obj_t *obj50;
    lv_obj_t *info_button_16;
    lv_obj_t *obj51;
    lv_obj_t *txt_scan_status;
    lv_obj_t *credits_button_7;
    lv_obj_t *obj52;
    lv_obj_t *tips_button_7;
    lv_obj_t *obj53;
    lv_obj_t *info_button_7;
    lv_obj_t *obj54;
    lv_obj_t *obj55;
    lv_obj_t *obj56;
    lv_obj_t *obj57;
    lv_obj_t *ta_tft_backlight;
    lv_obj_t *ta_wifi_timeout;
    lv_obj_t *obj58;
    lv_obj_t *ta_re_accel;
    lv_obj_t *obj59;
    lv_obj_t *ta_func_col;
    lv_obj_t *obj60;
    lv_obj_t *ta_threshold;
    lv_obj_t *lbl_list_status;
    lv_obj_t *obj61;
    lv_obj_t *lbl_btn_roster;
    lv_obj_t *obj62;
    lv_obj_t *lbl_btn_acc;
    lv_obj_t *current_roster;
    lv_obj_t *kbd_config;
    lv_obj_t *current_roster_1;
    lv_obj_t *credits_button_13;
    lv_obj_t *obj63;
    lv_obj_t *info_button_13;
    lv_obj_t *obj64;
    lv_obj_t *obj65;
    lv_obj_t *credits_button_14;
    lv_obj_t *obj66;
    lv_obj_t *info_button_14;
    lv_obj_t *obj67;
    lv_obj_t *obj68;
    lv_obj_t *lbl_sketch_build;
    lv_obj_t *lbl_eez_build;
    lv_obj_t *obj69;
    lv_obj_t *cancel_button_7;
    lv_obj_t *obj70;
    lv_obj_t *done_button_7;
    lv_obj_t *obj71;
    lv_obj_t *lbl_dc;
    lv_obj_t *lbl_fa;
    lv_obj_t *lbl_fg;
    lv_obj_t *lbl_fc;
    lv_obj_t *obj72;
} objects_t;

extern objects_t objects;

enum ScreensEnum {
    SCREEN_ID_MAIN = 1,
    SCREEN_ID_THROTTLE = 2,
    SCREEN_ID_ROSTER = 3,
    SCREEN_ID_EDIT_LOCO = 4,
    SCREEN_ID_FUNCTIONS = 5,
    SCREEN_ID_PROGRAM = 6,
    SCREEN_ID_ACCESSORIES = 7,
    SCREEN_ID_EDIT_ACC = 8,
    SCREEN_ID_WI_FI = 9,
    SCREEN_ID_SCAN = 10,
    SCREEN_ID_CONFIG = 11,
    SCREEN_ID_CREDITS = 12,
    SCREEN_ID_INFO = 13,
    SCREEN_ID_LAYOUT = 14,
};

void create_screen_main();
void tick_screen_main();

void create_screen_throttle();
void tick_screen_throttle();

void create_screen_roster();
void tick_screen_roster();

void create_screen_edit_loco();
void tick_screen_edit_loco();

void create_screen_functions();
void tick_screen_functions();

void create_screen_program();
void tick_screen_program();

void create_screen_accessories();
void tick_screen_accessories();

void create_screen_edit_acc();
void tick_screen_edit_acc();

void create_screen_wi_fi();
void tick_screen_wi_fi();

void create_screen_scan();
void tick_screen_scan();

void create_screen_config();
void tick_screen_config();

void create_screen_credits();
void tick_screen_credits();

void create_screen_info();
void tick_screen_info();

void create_screen_layout();
void tick_screen_layout();

void tick_screen_by_id(enum ScreensEnum screenId);
void tick_screen(int screen_index);

void create_screens();


#ifdef __cplusplus
}
#endif

#endif /*EEZ_LVGL_UI_SCREENS_H*/