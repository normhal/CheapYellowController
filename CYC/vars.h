#ifndef EEZ_LVGL_UI_VARS_H
#define EEZ_LVGL_UI_VARS_H

#include <stdint.h>
#include <stdbool.h>

#ifdef __cplusplus
extern "C" {
#endif

// enum declarations



// Flow global variables

enum FlowGlobalVariables {
    FLOW_GLOBAL_VARIABLE_AKBD_DATA = 0,
    FLOW_GLOBAL_VARIABLE_SELECTED_SSID = 1,
    FLOW_GLOBAL_VARIABLE_IP_ADDRESS = 2,
    FLOW_GLOBAL_VARIABLE_NKBD_DATA = 3,
    FLOW_GLOBAL_VARIABLE_SSID1 = 4,
    FLOW_GLOBAL_VARIABLE_SSID2 = 5,
    FLOW_GLOBAL_VARIABLE_SSID3 = 6,
    FLOW_GLOBAL_VARIABLE_SSID4 = 7,
    FLOW_GLOBAL_VARIABLE_SSID5 = 8,
    FLOW_GLOBAL_VARIABLE_SSI_DS = 9
};

// Native global variables

extern const char *get_var_akbd_data();
extern void set_var_akbd_data(const char *value);
extern const char *get_var_selected_ssid();
extern void set_var_selected_ssid(const char *value);
extern const char *get_var_ip_address();
extern void set_var_ip_address(const char *value);
extern const char *get_var_nkbd_data();
extern void set_var_nkbd_data(const char *value);
extern const char *get_var_ssid1();
extern void set_var_ssid1(const char *value);
extern const char *get_var_ssid2();
extern void set_var_ssid2(const char *value);
extern const char *get_var_ssid3();
extern void set_var_ssid3(const char *value);
extern const char *get_var_ssid4();
extern void set_var_ssid4(const char *value);
extern const char *get_var_ssid5();
extern void set_var_ssid5(const char *value);
extern const char *get_var_ssi_ds();
extern void set_var_ssi_ds(const char *value);


#ifdef __cplusplus
}
#endif

#endif /*EEZ_LVGL_UI_VARS_H*/