#include "styles.h"
#include "images.h"
#include "fonts.h"

#include "ui.h"
#include "screens.h"

//
// Style: Turnout
//

void init_style_turnout_MAIN_DEFAULT(lv_style_t *style) {
    lv_style_set_bg_color(style, lv_color_hex(0xffc89600));
    lv_style_set_bg_opa(style, 255);
    lv_style_set_border_color(style, lv_color_hex(0xffc89600));
    lv_style_set_outline_color(style, lv_color_hex(0xffc89600));
    lv_style_set_shadow_width(style, 0);
    lv_style_set_shadow_ofs_y(style, 0);
    lv_style_set_shadow_color(style, lv_color_hex(0xffc89600));
    lv_style_set_text_color(style, lv_color_hex(0xff000000));
};

lv_style_t *get_style_turnout_MAIN_DEFAULT() {
    static lv_style_t *style;
    if (!style) {
        style = lv_mem_alloc(sizeof(lv_style_t));
        lv_style_init(style);
        init_style_turnout_MAIN_DEFAULT(style);
    }
    return style;
};

void add_style_turnout(lv_obj_t *obj) {
    (void)obj;
    lv_obj_add_style(obj, get_style_turnout_MAIN_DEFAULT(), LV_PART_MAIN | LV_STATE_DEFAULT);
};

void remove_style_turnout(lv_obj_t *obj) {
    (void)obj;
    lv_obj_remove_style(obj, get_style_turnout_MAIN_DEFAULT(), LV_PART_MAIN | LV_STATE_DEFAULT);
};

//
//
//

void add_style(lv_obj_t *obj, int32_t styleIndex) {
    typedef void (*AddStyleFunc)(lv_obj_t *obj);
    static const AddStyleFunc add_style_funcs[] = {
        add_style_turnout,
    };
    add_style_funcs[styleIndex](obj);
}

void remove_style(lv_obj_t *obj, int32_t styleIndex) {
    typedef void (*RemoveStyleFunc)(lv_obj_t *obj);
    static const RemoveStyleFunc remove_style_funcs[] = {
        remove_style_turnout,
    };
    remove_style_funcs[styleIndex](obj);
}

