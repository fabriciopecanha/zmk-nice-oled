#include "layer.h"
#include <fonts.h>
#include <zephyr/kernel.h>

void draw_layer_status(lv_obj_t *canvas, const struct status_state *state) {
    lv_draw_label_dsc_t label_title_dsc;
    init_label_dsc(&label_title_dsc, LVGL_FOREGROUND, &pixel_operator_mono_8, LV_TEXT_ALIGN_CENTER);

    lv_draw_label_dsc_t label_num_dsc;
    init_label_dsc(&label_num_dsc, LVGL_FOREGROUND, &pixel_operator_mono_22, LV_TEXT_ALIGN_CENTER);

    // Title / Header: "LAYER"
    lv_canvas_draw_text(canvas, 0, CONFIG_NICE_OLED_WIDGET_LAYER_CUSTOM_Y, CANVAS_WIDTH, &label_title_dsc, "LAYER");

    // Big Layer Numeral (e.g. "0", "1", "2")
    char num_text[8] = {};
    snprintf(num_text, sizeof(num_text), "%d", state->layer_index);
    lv_canvas_draw_text(canvas, 0, CONFIG_NICE_OLED_WIDGET_LAYER_CUSTOM_Y + 9, CANVAS_WIDTH, &label_num_dsc, num_text);

    // Layer Name / Subtitle if custom label is defined
    if (state->layer_label != NULL) {
        char name_text[10] = {};
        snprintf(name_text, sizeof(name_text), "%.6s", state->layer_label);
        to_uppercase(name_text);
        lv_canvas_draw_text(canvas, 0, CONFIG_NICE_OLED_WIDGET_LAYER_CUSTOM_Y + 28, CANVAS_WIDTH, &label_title_dsc, name_text);
    }
}
