// tomsadowski
// keymap for split_3x5_2 keyboards

#include QMK_KEYBOARD_H
#include "action.h"
#include "keycodes.h"
#include "quantum_keycodes.h"
#include "process_combo.h"

//    |___|   |XXX|   |XXX|   |___|   |___|    ------------
const uint16_t PROGMEM          tab_combo_l[] = {KC_C,    KC_H,     COMBO_END};
const uint16_t PROGMEM        shift_combo_l[] = {KC_S,    KC_R,     COMBO_END};
const uint16_t PROGMEM      caps_on_combo_l[] = {KC_F,    KC_L,     COMBO_END};

//    |XXX|   |___|   |___|   |XXX|   |___|    ------------
const uint16_t PROGMEM          alt_combo_l[] = {KC_X,    KC_B,     COMBO_END};
const uint16_t PROGMEM      control_combo_l[] = {KC_A,    KC_T,     COMBO_END};
const uint16_t PROGMEM   left_mouse_combo_l[] = {KC_V,    KC_D,     COMBO_END};

//    |XXX|   |___|   |___|   |___|   |XXX|    ------------
const uint16_t PROGMEM  left_number_combo_l[] = {KC_A,    KC_COMM,  COMBO_END};

//    |111|   |___|   |___|   |222|   |___|    ------------
const uint16_t PROGMEM          gui_combo_l[] = {KC_T,    KC_X,     COMBO_END};

//    |___|   |___|   |___|   |111|   |222|    -------------
const uint16_t PROGMEM       escape_combo_l[] = {KC_B,    KC_COMMA, COMBO_END};

//------------    |___|   |___|   |XXX|   |XXX|   |___|
const uint16_t PROGMEM          tab_combo_r[] = {KC_W,    KC_P,     COMBO_END};
const uint16_t PROGMEM        shift_combo_r[] = {KC_I,    KC_O,     COMBO_END};
const uint16_t PROGMEM         home_combo_r[] = {KC_M,    KC_G,     COMBO_END};

//------------    |___|   |XXX|   |___|   |___|   |XXX|
const uint16_t PROGMEM          alt_combo_r[] = {KC_Y,    KC_J,     COMBO_END};
const uint16_t PROGMEM      control_combo_r[] = {KC_E,    KC_N,     COMBO_END};
const uint16_t PROGMEM        mouse_combo_r[] = {KC_U,    KC_K,     COMBO_END};

//------------    |XXX|   |___|   |___|   |___|   |XXX|
const uint16_t PROGMEM       number_combo_r[] = {KC_DOT,  KC_N,     COMBO_END};

//------------    |___|   |222|   |___|   |___|   |111|
const uint16_t PROGMEM          gui_combo_r[] = {KC_E,    KC_J,     COMBO_END};

//------------    |222|   |111|   |___|   |___|   |___|
const uint16_t PROGMEM        enter_combo_r[] = {KC_DOT,  KC_Y,     COMBO_END};

enum combos {
  /*   |___|   |XXX|   |XXX|   |___|   |___|      |___|   |___|   |XXX|   |XXX|   |___|   */
                    TAB_COMBO_L,                               TAB_COMBO_R,
                    SHIFT_COMBO_L,                             SHIFT_COMBO_R,
                    CAPS_ON_COMBO_L,                           HOME_COMBO_R,
  /*   |XXX|   |___|   |___|   |XXX|   |___|      |___|   |XXX|   |___|   |___|   |XXX|   */
                    ALT_COMBO_L,                               ALT_COMBO_R,
                    CONTROL_COMBO_L,                           CONTROL_COMBO_R,
                    LEFT_MOUSE_COMBO_L,                        MOUSE_COMBO_R,
  /*   |XXX|   |___|   |___|   |___|   |XXX|      |XXX|   |___|   |___|   |___|   |XXX|   */
                    RELEASE_GATE_COMBO_L,                      RELEASE_GATE_COMBO_R,
                    LEFT_NUMBER_COMBO_L,                       NUMBER_COMBO_R,
                    GAME2D_COMBO_L,                            GAME3D_COMBO_R,
  /*   |111|   |___|   |___|   |222|   |___|      |___|   |222|   |___|   |___|   |111|   */
                    GUI_COMBO_L,                               GUI_COMBO_R,
  /*   |___|   |___|   |___|   |111|   |222|      |222|   |111|   |___|   |___|   |___|   */
                    ESCAPE_COMBO_L,                            ENTER_COMBO_R,
};
enum custom_keycodes {
    LAYOUT_HOME = SAFE_RANGE,
    CAPS_ON,
    CAPS_OFF
};
enum layers {
    ALPHA_LAYER,
    NUMBER_LAYER,
    MOUSE_LAYER,
    LEFT_NUMBER_LAYER,
    LEFT_MOUSE_LAYER,
    MOMENTARY_ALPHA_LAYER,
    MOMENTARY_MOUSEALPHA_LAYER,
    MOMENTARY_NUMBER_LAYER,
    MOMENTARY_MOUSE_LAYER
};
combo_t key_combos[] = {
                       //    |___|   |XXX|   |XXX|   |___|   |___|    ------------
                        [TAB_COMBO_L]          = COMBO(         tab_combo_l,                KC_TAB),
                        [SHIFT_COMBO_L]        = COMBO(       shift_combo_l,         KC_LEFT_SHIFT),
                        [CAPS_ON_COMBO_L]      = COMBO(     caps_on_combo_l,               CAPS_ON),

                       //    |XXX|   |___|   |___|   |XXX|   |___|    ------------
                        [ALT_COMBO_L]          = COMBO(         alt_combo_l,           KC_LEFT_ALT),
                        [CONTROL_COMBO_L]      = COMBO(     control_combo_l,          KC_LEFT_CTRL),
                        [LEFT_MOUSE_COMBO_L]   = COMBO(  left_mouse_combo_l,  TO(LEFT_MOUSE_LAYER)),

                       //    |XXX|   |___|   |___|   |___|   |XXX|    ------------
                        [RELEASE_GATE_COMBO_L] = COMBO(release_gate_combo_l,          RELEASE_GATE),
                        [LEFT_NUMBER_COMBO_L]  = COMBO( left_number_combo_l, TO(LEFT_NUMBER_LAYER)),
                        [GAME2D_COMBO_L]       = COMBO(      game2d_combo_l,      TO(GAME2D_LAYER)),

                       //    |111|   |___|   |___|   |222|   |___|    ------------
                        [GUI_COMBO_L]          = COMBO(         gui_combo_l,           KC_LEFT_GUI),

                       //    |___|   |___|   |___|   |111|   |222|    -------------
                        [ESCAPE_COMBO_L]       = COMBO(      escape_combo_l,             KC_ESCAPE),

                       //------------    |___|   |___|   |XXX|   |XXX|   |___|
                        [TAB_COMBO_R]          = COMBO(         tab_combo_r,                KC_TAB),
                        [SHIFT_COMBO_R]        = COMBO(       shift_combo_r,        KC_RIGHT_SHIFT),
                        [HOME_COMBO_R]         = COMBO(        home_combo_r,           LAYOUT_HOME),

                       //------------    |___|   |XXX|   |___|   |___|   |XXX|
                        [ALT_COMBO_R]          = COMBO(         alt_combo_r,          KC_RIGHT_ALT),
                        [CONTROL_COMBO_R]      = COMBO(     control_combo_r,         KC_RIGHT_CTRL),
                        [MOUSE_COMBO_R]        = COMBO(       mouse_combo_r,       TO(MOUSE_LAYER)),

                       //------------    |XXX|   |___|   |___|   |___|   |XXX|
                        [RELEASE_GATE_COMBO_R] = COMBO(release_gate_combo_r,          RELEASE_GATE),
                        [NUMBER_COMBO_R]       = COMBO(      number_combo_r,      TO(NUMBER_LAYER)),
                        [GAME3D_COMBO_R]       = COMBO(      game3d_combo_r,      TO(GAME3D_LAYER)),

                       //------------    |___|   |222|   |___|   |___|   |111|
                        [GUI_COMBO_R]          = COMBO(         gui_combo_r,          KC_RIGHT_GUI),

                       //------------    |222|   |111|   |___|   |___|   |___|
                        [ENTER_COMBO_R]        = COMBO(       enter_combo_r,              KC_ENTER),
};

// functions

// Switching to non-alpha layers breaks capsword
layer_state_t layer_state_set_user(layer_state_t state) {
    switch (get_highest_layer(state)) {
        case MOUSE_LAYER ... GAME3D_LAYER:
            caps_word_off();
            break;
        default: break;
    }
    return state;
}
// "escape" breaks capsword, "space" does not
bool caps_word_press_user(uint16_t keycode) {
    switch (keycode) {
        case KC_A ... KC_Z:
            add_weak_mods(MOD_BIT(KC_LEFT_SHIFT));
            return true;
        case KC_ESCAPE: return false;
        default: return true;
    }
}
// MOMENTARY_MOUSE_LAYER will activate before TAPPING_TERM if another key is pressed then released
bool get_permissive_hold(uint16_t keycode, keyrecord_t* record) {
    if (LT(MOMENTARY_MOUSE_LAYER, KC_SPC)) return true;
    return false;
}
// MOMENTARY_NUMBER_LAYER will activate before TAPPING_TERM if another key is pressed
bool get_hold_on_other_key_press(uint16_t keycode, keyrecord_t* record) {
    if (LT(MOMENTARY_NUMBER_LAYER, KC_SPC)) return true;
    return false;
}


// Handle all the custom keys
bool process_record_user(uint16_t keycode, keyrecord_t* record) {
    switch (keycode) {

        case LAYOUT_HOME:
            if (record->event.pressed) {
                caps_word_off();
                reset_release_gate(release_gate);
                layer_move(ALPHA_LAYER);
            }
            return false;

        case CAPS_OFF:
            if (record->event.pressed) caps_word_off();
            return false;

        case CAPS_ON:
            if (record->event.pressed) caps_word_on();
            return false;

        default: return true;
    }
}
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [ALPHA_LAYER] = LAYOUT_split_3x5_2( // ALPHA: Alphabet, punctuation, editing
        KC_X,    KC_C,    KC_H,    KC_B,    KC_Q,            KC_Z,    KC_Y,    KC_W,    KC_P,    KC_J,
        KC_A,    KC_S,    KC_R,    KC_T,    KC_COMMA,        KC_DOT,  KC_E,    KC_I,    KC_O,    KC_N,
        KC_V,    KC_F,    KC_L,    KC_D,    KC_QUOT,         KC_SCLN, KC_U,    KC_M,    KC_G,    KC_K,
        KC_BSPC, LT(MOMENTARY_MOUSE_LAYER,  KC_SPC),         LT(MOMENTARY_NUMBER_LAYER, KC_SPC), KC_DEL),
    [NUMBER_LAYER] = LAYOUT_split_3x5_2( // NUMBER: digits, navigation keys, and symbols
        KC_1,    KC_2,    KC_3,    KC_4,    KC_5,            KC_6,    KC_7,    KC_8,    KC_9,    KC_0,
        KC_GRV,  KC_BSLS, KC_SLSH, KC_MINS, _______,         _______, KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT,
        _______, KC_LBRC, KC_RBRC, KC_EQL,  _______,         _______, KC_HOME, KC_PGDN, KC_PGUP, KC_END,
                                   _______, _______,         LT(MOMENTARY_ALPHA_LAYER, KC_SPC),  _______),
    [MOUSE_LAYER] = LAYOUT_split_3x5_2( // MOUSE: Mouse and function keys
        KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,           KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,
        KC_PSCR, KC_ACL2, KC_ACL1, KC_ACL0, _______,         _______, KC_MS_L, KC_MS_D, KC_MS_U, KC_MS_R,
        KC_F11,  KC_F12,  KC_F13,  KC_F14,  _______,         _______, KC_WH_L, KC_WH_D, KC_WH_U, KC_WH_R,
        _______, LT(MOMENTARY_MOUSEALPHA_LAYER, KC_SPC),     KC_BTN1, KC_BTN2),
    [LEFT_NUMBER_LAYER] = LAYOUT_split_3x5_2( // LEFT NUMBER
        KC_1,    KC_2,    KC_3,    KC_4,    KC_5,            KC_6,    KC_7,    KC_8,    KC_9,    KC_0,
        KC_LEFT, KC_UP,   KC_DOWN, KC_RGHT, _______,         _______, KC_MINS, KC_SLSH, KC_BSLS, KC_GRV,
        KC_HOME, KC_PGUP, KC_PGDN, KC_END,  _______,         _______, KC_EQL,  KC_LBRC, KC_RBRC, _______,
                                   _______, KC_SPC,          KC_SPC,  _______),
    [LEFT_MOUSE_LAYER] = LAYOUT_split_3x5_2( // LEFT MOUSE
        KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,           KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,
        KC_MS_L, KC_MS_U, KC_MS_D, KC_MS_R, _______,         _______, KC_ACL0, KC_ACL1, KC_ACL2, KC_PSCR,
        KC_WH_L, KC_WH_U, KC_WH_D, KC_WH_R, _______,         _______, KC_F11,  KC_F12,  KC_F13,  KC_F14,
                                   KC_BTN2, KC_BTN1,         KC_SPC,  _______),
    [MOMENTARY_ALPHA_LAYER] = LAYOUT_split_3x5_2( // MOMENTARY ALPHA: Accessed from NUMBER
        KC_X,   KC_C,     KC_H,    KC_B,    KC_Q,            KC_Z,    KC_Y,    KC_W,    KC_P,    KC_J,
        KC_A,   KC_S,     KC_R,    KC_T,    _______,         _______, KC_E,    KC_I,    KC_O,    KC_N,
        KC_V,   KC_F,     KC_L,    KC_D,    _______,         _______, KC_U,    KC_M,    KC_G,    KC_K,
                                   _______, KC_SPC,          _______, _______),
    [MOMENTARY_MOUSEALPHA_LAYER] = LAYOUT_split_3x5_2( // MOMENTARY MOUSE ALPHA: accessed from MOUSE
        KC_X,   KC_C,     KC_H,    KC_B,    KC_Q,            KC_Z,    KC_Y,    KC_W,    KC_P,     KC_J,
        KC_A,   KC_S,     KC_R,    KC_T,    _______,         _______, KC_E,    KC_I,    KC_O,     KC_N,
        KC_V,   KC_F,     KC_L,    KC_D,    _______,         _______, KC_U,    KC_M,    KC_G,     KC_K,
                                   _______, _______,         LT(MOMENTARY_NUMBER_LAYER, KC_SPC),  KC_DEL),
    [MOMENTARY_NUMBER_LAYER] = LAYOUT_split_3x5_2( // MOMENTARY NUMBER: accessed from ALPHA
        KC_1,    KC_2,    KC_3,    KC_4,    KC_5,            KC_6,    KC_7,    KC_8,    KC_9,    KC_0,
        KC_GRV,  KC_BSLS, KC_SLSH, KC_MINS, _______,         _______, KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT,
        _______, KC_LBRC, KC_RBRC, KC_EQL,  _______,         _______, KC_HOME, KC_PGDN, KC_PGUP, KC_END,
                                   _______, KC_SPC,          _______, _______),
    [MOMENTARY_MOUSE_LAYER] = LAYOUT_split_3x5_2( // MOMENTARY MOUSE: accessed from ALPHA
        KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,           KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,
        KC_PSCR, KC_ACL2, KC_ACL1, KC_ACL0, _______,         _______, KC_MS_L, KC_MS_D, KC_MS_U, KC_MS_R,
        KC_F11,  KC_F12,  KC_F13,  KC_F14,  _______,         _______, KC_WH_L, KC_WH_D, KC_WH_U, KC_WH_R,
                                   _______, _______,         KC_BTN1, KC_BTN2),
};
