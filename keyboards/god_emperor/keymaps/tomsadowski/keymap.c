// tomsadowski
// keymap for split_3x5_2 keyboards

#include "keymap.h"

// Exclude some combos from game layers
bool combo_should_trigger(uint16_t combo_index, combo_t* combo, uint16_t keycode, keyrecord_t* record) {
    if (layer_state_is(GAME2D_LAYER) || layer_state_is(GAME3D_LAYER)) {
        switch (combo_index) {
            case HOME_COMBO_R:
            case LEFT_MOUSE_COMBO_L:
            case MOUSE_COMBO_R:
            case LEFT_NUMBER_COMBO_L:
            case NUMBER_COMBO_R:
            case ESCAPE_COMBO_L:
            case ENTER_COMBO_R:
                return true;
            default: return false;
        }
    }
    return true;
}

// Shorten combo term when in game layers
uint16_t get_combo_term(uint16_t index, combo_t* combo) {
    if (layer_state_is(GAME2D_LAYER) || layer_state_is(GAME3D_LAYER))
        return SHORT_COMBO_TERM;
    else
        return COMBO_TERM;
}

// Switching to non-alpha layers breaks capsword
layer_state_t layer_state_set_user(layer_state_t state) {
    switch (get_highest_layer(state)) {
        case ALPHA_LAYER:
            in_momentary_layer = false;
            break;
        case MOUSE_LAYER ... GAME3D_LAYER:
            in_momentary_layer = false;
            caps_word_off();
            break;
        case MOMENTARY_ALPHA_LAYER ... MOMENTARY_MOUSE_LAYER:
            in_momentary_layer = true;
            break;
        default: break;
    }
    return state;
}

// Space does not break capsword
bool caps_word_press_user(uint16_t keycode) {
    switch (keycode) {
        case KC_A ... KC_Z:
            add_weak_mods(MOD_BIT(KC_LEFT_SHIFT));
            return true;
        // Escape, and modifiers break capsword
        case KC_ESCAPE:
        case KC_LEFT_CTRL:
        case KC_LEFT_ALT:
        case KC_LEFT_GUI:
        case KC_RIGHT_CTRL:
        case KC_RIGHT_ALT:
        case KC_RIGHT_GUI: return false;
        // Everything else lets capsword continue.
        default: return true;
    }
}
// lower risk of accidentally triggering keys in the momentary mouse layer
bool get_permissive_hold(uint16_t keycode, keyrecord_t* record) {
    if (LT(MOMENTARY_MOUSE_LAYER, KC_SPC))
        return true;
    else
        return false;
}
// common symbols can be accessed without breaking flow
bool get_hold_on_other_key_press(uint16_t keycode, keyrecord_t* record) {
    if (LT(MOMENTARY_NUMBER_LAYER, KC_SPC))
        return true;
    else
        return false;
}
// Handle all the custom keys
bool process_record_user(uint16_t keycode, keyrecord_t* record) {
    switch (keycode) {
        case KC_A ... KC_RGUI:
            if (release_gate.state == NONE)
                return true;
            else if (record->event.pressed)
                return press_key_with_release_gate(&release_gate, keycode);
            else
                return release_key_with_release_gate(&release_gate, keycode);

        case LAYOUT_HOME:
            if (record->event.pressed)
                return press_home();
            else
                return false;

        case RELEASE_GATE:
            if (record->event.pressed)
                return press_release_gate(&release_gate);
            else
                return release_release_gate(&release_gate);

        case CAPS_ON:
            if (record->event.pressed)
                return press_caps_on();
            else
                return false;

        case FOUR_SPACE:
            if (record->event.pressed) {
                SEND_STRING("    ");
            }
            return true;

        default: return true;
    }
}

bool press_caps_on() {
    caps_word_on();
    return false;
}

bool press_home() {
    caps_word_off();
    reset_release_gate(&release_gate);
    if (!in_momentary_layer)
        layer_move(ALPHA_LAYER);
    return false;
}
