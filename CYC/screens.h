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
    lv_obj_t *program;
    lv_obj_t *wi_fi;
    lv_obj_t *scan;
    lv_obj_t *config;
    lv_obj_t *credits;
    lv_obj_t *info;
    lv_obj_t *btn_stop;
    lv_obj_t *btn_power;
    lv_obj_t *sw_dir;
    lv_obj_t *ta_guest_address;
    lv_obj_t *btn_select_loco;
    lv_obj_t *btn_edit_loco;
    lv_obj_t *obj0;
    lv_obj_t *obj1;
    lv_obj_t *obj2;
    lv_obj_t *obj3;
    lv_obj_t *obj4;
    lv_obj_t *obj5;
    lv_obj_t *obj6;
    lv_obj_t *obj7;
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
    lv_obj_t *lbl_stop;
    lv_obj_t *lbl_power;
    lv_obj_t *obj8;
    lv_obj_t *btn_home;
    lv_obj_t *h_line;
    lv_obj_t *obj9;
    lv_obj_t *obj10;
    lv_obj_t *credits_button;
    lv_obj_t *obj11;
    lv_obj_t *info_button;
    lv_obj_t *obj12;
    lv_obj_t *throttle_mtx;
    lv_obj_t *menu_mtx;
    lv_obj_t *img_wifi;
    lv_obj_t *lbl_throttle_page;
    lv_obj_t *prog_button2_1;
    lv_obj_t *obj13;
    lv_obj_t *acc_button2_1;
    lv_obj_t *obj14;
    lv_obj_t *roster_button2_1;
    lv_obj_t *obj15;
    lv_obj_t *dd_locos;
    lv_obj_t *btn_edit;
    lv_obj_t *obj16;
    lv_obj_t *lbl_address;
    lv_obj_t *function_mtx;
    lv_obj_t *slider;
    lv_obj_t *lbl_slider;
    lv_obj_t *obj17;
    lv_obj_t *kbd_guest;
    lv_obj_t *obj18;
    lv_obj_t *obj19;
    lv_obj_t *roster_heading_1;
    lv_obj_t *btn_cancel_edit_loco;
    lv_obj_t *obj20;
    lv_obj_t *obj21;
    lv_obj_t *obj22;
    lv_obj_t *tbl_roster;
    lv_obj_t *obj23;
    lv_obj_t *btn_edit_loco_cancel_1;
    lv_obj_t *obj24;
    lv_obj_t *btn_prog_edit_loco_1;
    lv_obj_t *obj25;
    lv_obj_t *btn_edit_loco_done_1;
    lv_obj_t *obj26;
    lv_obj_t *ta_name;
    lv_obj_t *obj27;
    lv_obj_t *ta_address;
    lv_obj_t *ta_fname;
    lv_obj_t *ta_fnum;
    lv_obj_t *f_option;
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
    lv_obj_t *n_kbd_edit_loco;
    lv_obj_t *a_kbd_edit_loco;
    lv_obj_t *credits_button_5;
    lv_obj_t *obj28;
    lv_obj_t *info_button_5;
    lv_obj_t *obj29;
    lv_obj_t *obj30;
    lv_obj_t *track_mtx;
    lv_obj_t *obj31;
    lv_obj_t *obj32;
    lv_obj_t *obj33;
    lv_obj_t *ta_cvn;
    lv_obj_t *ta_cvv;
    lv_obj_t *ta_adr;
    lv_obj_t *cv_mtx;
    lv_obj_t *lbl_ps1;
    lv_obj_t *lbl_ps2;
    lv_obj_t *kbd_program;
    lv_obj_t *btn_wifi_select;
    lv_obj_t *obj34;
    lv_obj_t *btn_wifi_scan;
    lv_obj_t *obj35;
    lv_obj_t *dd_ssids;
    lv_obj_t *ta_ssid;
    lv_obj_t *ta_password;
    lv_obj_t *ta_ip_address;
    lv_obj_t *ta_port;
    lv_obj_t *btn_wifi_connect;
    lv_obj_t *obj36;
    lv_obj_t *btn_wifi_save;
    lv_obj_t *obj37;
    lv_obj_t *btn_wifi_enable;
    lv_obj_t *obj38;
    lv_obj_t *config_button9;
    lv_obj_t *obj39;
    lv_obj_t *retry_button9;
    lv_obj_t *obj40;
    lv_obj_t *done_button9;
    lv_obj_t *obj41;
    lv_obj_t *lbl_wifi_status;
    lv_obj_t *lbl_wifi_status2;
    lv_obj_t *kb_numeric;
    lv_obj_t *kb_alpha;
    lv_obj_t *lbl_scan;
    lv_obj_t *config_button9_3;
    lv_obj_t *obj42;
    lv_obj_t *done_button9_3;
    lv_obj_t *obj43;
    lv_obj_t *obj44;
    lv_obj_t *list_scan_pg_ssids;
    lv_obj_t *txt_scan_status;
    lv_obj_t *wifi_button;
    lv_obj_t *obj45;
    lv_obj_t *uodate_button;
    lv_obj_t *obj46;
    lv_obj_t *done_button_7;
    lv_obj_t *obj47;
    lv_obj_t *obj48;
    lv_obj_t *obj49;
    lv_obj_t *obj50;
    lv_obj_t *ta_tft_backlight;
    lv_obj_t *ta_wifi_timeout;
    lv_obj_t *kbd_config;
    lv_obj_t *info_button_9;
    lv_obj_t *obj51;
    lv_obj_t *done_button_9;
    lv_obj_t *obj52;
    lv_obj_t *obj53;
    lv_obj_t *credits_button_10;
    lv_obj_t *obj54;
    lv_obj_t *done_button_10;
    lv_obj_t *obj55;
    lv_obj_t *obj56;
} objects_t;

extern objects_t objects;

enum ScreensEnum {
    SCREEN_ID_MAIN = 1,
    SCREEN_ID_THROTTLE = 2,
    SCREEN_ID_ROSTER = 3,
    SCREEN_ID_EDIT_LOCO = 4,
    SCREEN_ID_PROGRAM = 5,
    SCREEN_ID_WI_FI = 6,
    SCREEN_ID_SCAN = 7,
    SCREEN_ID_CONFIG = 8,
    SCREEN_ID_CREDITS = 9,
    SCREEN_ID_INFO = 10,
};

void create_screen_main();
void tick_screen_main();

void create_screen_throttle();
void tick_screen_throttle();

void create_screen_roster();
void tick_screen_roster();

void create_screen_edit_loco();
void tick_screen_edit_loco();

void create_screen_program();
void tick_screen_program();

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

void tick_screen_by_id(enum ScreensEnum screenId);
void tick_screen(int screen_index);

void create_screens();


#ifdef __cplusplus
}
#endif

#endif /*EEZ_LVGL_UI_SCREENS_H*/