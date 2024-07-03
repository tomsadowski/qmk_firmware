#include QMK_KEYBOARD_H
#include "process_combo.h"
#include "keycodes.h"
#include "quantum_keycodes.h"

// constants
#define SHORT_COMBO_TERM 6

enum custom_keycodes {
    LAYOUT_HOME,
    CAPS_ON
};

// layers
enum layers {
    ALPHA_LAYER,
    NUMBER_LAYER,
    MOUSE_LAYER,
    LEFT_NUMBER_LAYER,
    LEFT_MOUSE_LAYER,
    GAME2D_LAYER,
    GAME3D_LAYER,
    MOMENTARY_ALPHA_LAYER,
    MOMENTARY_MOUSEALPHA_LAYER,
    MOMENTARY_NUMBER_LAYER,
    MOMENTARY_MOUSE_LAYER
};

static bool in_momentary_layer = false;

enum combos {
  /*   |___|   |XXX|   |XXX|   |___|   |___|      |___|   |___|   |XXX|   |XXX|   |___|   */
                    FOUR_SPACE_COMBO_L,                        TAB_COMBO_R,
                    SHIFT_COMBO_L,                             SHIFT_COMBO_R,
                    CAPS_COMBO_L,                              HOME_COMBO_R,

  /*   |XXX|   |___|   |___|   |XXX|   |___|      |___|   |XXX|   |___|   |___|   |XXX|   */
                    ALT_COMBO_L,                               ALT_COMBO_R,
                    CONTROL_COMBO_L,                           CONTROL_COMBO_R,
                    LEFT_MOUSE_COMBO_L,                        MOUSE_COMBO_R,

  /*   |XXX|   |___|   |___|   |___|   |XXX|      |XXX|   |___|   |___|   |___|   |XXX|   */
                    LEFT_NUMBER_COMBO_L,                       NUMBER_COMBO_R,
                    GAME3D_COMBO_L,                            GAME2D_COMBO_R,

  /*   |111|   |___|   |___|   |222|   |___|      |___|   |222|   |___|   |___|   |111|   */
                    GUI_COMBO_L,                               GUI_COMBO_R,

  /*   |___|   |___|   |___|   |111|   |222|      |222|   |111|   |___|   |___|   |___|   */
                    ESCAPE_COMBO_L,                            ENTER_COMBO_R,
};

const uint16_t PROGMEM   four_space_combo_l[] = {KC_W,     KC_E,    COMBO_END};
const uint16_t PROGMEM        shift_combo_l[] = {KC_S,     KC_D,    COMBO_END};
const uint16_t PROGMEM         caps_combo_l[] = {KC_X,     KC_C,    COMBO_END};
const uint16_t PROGMEM          alt_combo_l[] = {KC_Q,     KC_R,    COMBO_END};
const uint16_t PROGMEM      control_combo_l[] = {KC_A,     KC_F,    COMBO_END};
const uint16_t PROGMEM   left_mouse_combo_l[] = {KC_Z,     KC_V,    COMBO_END};
const uint16_t PROGMEM          gui_combo_l[] = {KC_Q,     KC_D,    COMBO_END};
const uint16_t PROGMEM       escape_combo_l[] = {KC_R,     KC_G,    COMBO_END};
const uint16_t PROGMEM release_gate_combo_l[] = {KC_Q,     KC_T,    COMBO_END};
const uint16_t PROGMEM  left_number_combo_l[] = {KC_A,     KC_G,    COMBO_END};
const uint16_t PROGMEM       game3d_combo_l[] = {KC_Z,     KC_B,    COMBO_END};
const uint16_t PROGMEM          tab_combo_r[] = {KC_I,     KC_O,    COMBO_END};
const uint16_t PROGMEM        shift_combo_r[] = {KC_K,     KC_L,    COMBO_END};
const uint16_t PROGMEM         home_combo_r[] = {KC_COMMA, KC_DOT,  COMBO_END};
const uint16_t PROGMEM          alt_combo_r[] = {KC_U,     KC_P,    COMBO_END};
const uint16_t PROGMEM      control_combo_r[] = {KC_J,     KC_SCLN, COMBO_END};
const uint16_t PROGMEM        mouse_combo_r[] = {KC_M,     KC_SLSH, COMBO_END};
const uint16_t PROGMEM          gui_combo_r[] = {KC_J,     KC_P,    COMBO_END};
const uint16_t PROGMEM        enter_combo_r[] = {KC_H,     KC_U,    COMBO_END};
const uint16_t PROGMEM release_gate_combo_r[] = {KC_Y,     KC_J,    COMBO_END};
const uint16_t PROGMEM       number_combo_r[] = {KC_H,     KC_SCLN, COMBO_END};
const uint16_t PROGMEM       game2d_combo_r[] = {KC_N,     KC_SLSH, COMBO_END};

combo_t key_combos[] = {
                        //    |___|   |XXX|   |XXX|   |___|   |___|    ------------
                         [FOUR_SPACE_COMBO_L] = COMBO( four_space_combo_l, KC_SPACE              ),
                              [SHIFT_COMBO_L] = COMBO(      shift_combo_l, KC_LEFT_SHIFT         ),
                               [CAPS_COMBO_L] = COMBO(       caps_combo_l, CAPS_ON               ),

                       //    |XXX|   |___|   |___|   |XXX|   |___|    ------------
                                [ALT_COMBO_L] = COMBO(        alt_combo_l, KC_LEFT_ALT           ),
                            [CONTROL_COMBO_L] = COMBO(    control_combo_l, KC_LEFT_CTRL          ),
                         [LEFT_MOUSE_COMBO_L] = COMBO( left_mouse_combo_l, TO(LEFT_MOUSE_LAYER)  ),

                       //    |XXX|   |___|   |___|   |___|   |XXX|    ------------
                        [LEFT_NUMBER_COMBO_L] = COMBO( left_number_combo_l, TO(LEFT_NUMBER_LAYER)),
                             [GAME3D_COMBO_L] = COMBO(      game3d_combo_l, TO(GAME3D_LAYER)     ),


                       //    |111|   |___|   |___|   |222|   |___|    ------------
                                [GUI_COMBO_L] = COMBO(         gui_combo_l, KC_LEFT_GUI          ),


                       //    |___|   |___|   |___|   |111|   |222|    -------------
                             [ESCAPE_COMBO_L] = COMBO(      escape_combo_l, KC_ESCAPE            ),


                       //------------    |___|   |___|   |XXX|   |XXX|   |___|
                                [TAB_COMBO_R] = COMBO(        tab_combo_r, KC_TAB                ),
                              [SHIFT_COMBO_R] = COMBO(      shift_combo_r, KC_RIGHT_SHIFT        ),
                               [HOME_COMBO_R] = COMBO(       home_combo_r, LAYOUT_HOME           ),

                       //------------    |___|   |XXX|   |___|   |___|   |XXX|
                                [ALT_COMBO_R] = COMBO(        alt_combo_r, KC_RIGHT_ALT          ),
                            [CONTROL_COMBO_R] = COMBO(    control_combo_r, KC_RIGHT_CTRL         ),
                              [MOUSE_COMBO_R] = COMBO(      mouse_combo_r, TO(MOUSE_LAYER)       ),

                       //------------    |XXX|   |___|   |___|   |___|   |XXX|
                             [NUMBER_COMBO_R] = COMBO(      number_combo_r, TO(NUMBER_LAYER)     ),
                             [GAME2D_COMBO_R] = COMBO(      game2d_combo_r, TO(GAME2D_LAYER)     ),


                       //------------    |___|   |222|   |___|   |___|   |111|
                                [GUI_COMBO_R] = COMBO(         gui_combo_r, KC_RIGHT_GUI         ),


                       //------------    |222|   |111|   |___|   |___|   |___|
                              [ENTER_COMBO_R] = COMBO(       enter_combo_r, KC_ENTER             ),
};

// layout
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [ALPHA_LAYER] = LAYOUT_split_3x5_2( // ALPHA: Alphabet, punctuation, editing
        KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,            KC_Y,    KC_U,    KC_I,     KC_O,    KC_P,
        KC_A,    KC_S,    KC_D,    KC_F,    KC_G,            KC_H,    KC_J,    KC_K,     KC_L,    KC_SCLN,
        KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,            KC_N,    KC_M,    KC_COMMA, KC_DOT,  KC_SLSH,
        KC_BSPC, LT(MOMENTARY_MOUSE_LAYER, KC_SPC),          LT(MOMENTARY_NUMBER_LAYER, KC_SPC), KC_DEL),
    [NUMBER_LAYER] = LAYOUT_split_3x5_2( // NUMBER: digits, navigation keys, and symbols
        KC_1,    KC_2,    KC_3,    KC_4,    KC_5,            KC_6,    KC_7,    KC_8,    KC_9,    KC_0,
        KC_GRV,  KC_QUOT, KC_EQL,  KC_MINS, KC_COMMA,        KC_DOT,  KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT,
        _______, KC_BSLS, KC_LBRC, KC_RBRC, _______,         _______, KC_HOME, KC_PGDN, KC_PGUP, KC_END,
                                   _______, _______,         LT(MOMENTARY_ALPHA_LAYER, KC_SPC),  _______),
    [MOUSE_LAYER] = LAYOUT_split_3x5_2( // MOUSE: Mouse and function keys
        KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,           KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,
        KC_PSCR, KC_ACL2, KC_ACL1, KC_ACL0, KC_COMMA,        KC_DOT,  KC_MS_L, KC_MS_D, KC_MS_U, KC_MS_R,
        KC_F11,  KC_F12,  KC_F13,  KC_F14,  _______,         _______, KC_WH_L, KC_WH_D, KC_WH_U, KC_WH_R,
        _______, LT(MOMENTARY_MOUSEALPHA_LAYER, KC_SPC),     KC_BTN1, KC_BTN2),
    [LEFT_NUMBER_LAYER] = LAYOUT_split_3x5_2( // LEFT NUMBER
        KC_1,    KC_2,    KC_3,    KC_4,    KC_5,            KC_6,    KC_7,    KC_8,    KC_9,    KC_0,
        KC_LEFT, KC_UP,   KC_DOWN, KC_RGHT, KC_COMMA,        KC_DOT,  KC_4,    KC_5,    KC_6,    KC_GRV,
        KC_HOME, KC_PGUP, KC_PGDN, KC_END,  _______,         _______, KC_1,    KC_2,    KC_3, _______,
                                   _______, KC_SPC,          KC_SPC,  _______),
    [LEFT_MOUSE_LAYER] = LAYOUT_split_3x5_2( // LEFT MOUSE
        KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,           KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,
        KC_MS_L, KC_MS_U, KC_MS_D, KC_MS_R, KC_COMMA,        KC_DOT,  KC_ACL0, KC_ACL1, KC_ACL2, KC_PSCR,
        KC_WH_L, KC_WH_U, KC_WH_D, KC_WH_R, _______,         _______, KC_F11,  KC_F12,  KC_F13,  KC_F14,
                                   KC_BTN2, KC_BTN1,         KC_SPC,  _______),
    [GAME2D_LAYER] = LAYOUT_split_3x5_2( // GAME: Base sans combos and hold-tap features
        _______, _______, _______, _______, _______,         _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______,         _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______,         _______, _______, _______, _______, _______,
                                   _______, KC_SPC,          KC_0,    _______),
    [GAME3D_LAYER] = LAYOUT_split_3x5_2( // GAME: Base sans combos and hold-tap features
        _______, _______, _______, _______, _______,         _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______,         _______, KC_MS_L, KC_MS_D, KC_MS_U, KC_MS_R,
        _______, _______, _______, _______, _______,         _______, _______, KC_WH_D, KC_WH_U, _______,
                                   _______, KC_SPC,          KC_BTN1, KC_BTN2),
    [MOMENTARY_ALPHA_LAYER] = LAYOUT_split_3x5_2( // MOMENTARY ALPHA: Accessed from NUMBER
        KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,            KC_Y,    KC_U,    KC_I,     KC_O,    KC_P,
        KC_A,    KC_S,    KC_D,    KC_F,    KC_G,            KC_H,    KC_J,    KC_K,     KC_L,    KC_SCLN,
        KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,            KC_N,    KC_M,    KC_COMMA, KC_DOT,  KC_SLSH,
                                   _______, KC_SPC,          _______, _______),
    [MOMENTARY_MOUSEALPHA_LAYER] = LAYOUT_split_3x5_2( // MOMENTARY MOUSE ALPHA: accessed from MOUSE
        KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,            KC_Y,    KC_U,    KC_I,     KC_O,    KC_P,
        KC_A,    KC_S,    KC_D,    KC_F,    KC_G,            KC_H,    KC_J,    KC_K,     KC_L,    KC_SCLN,
        KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,            KC_N,    KC_M,    KC_COMMA, KC_DOT,  KC_SLSH,
                                   _______, _______,         LT(MOMENTARY_NUMBER_LAYER, KC_SPC),  KC_DEL),
    [MOMENTARY_NUMBER_LAYER] = LAYOUT_split_3x5_2( // MOMENTARY NUMBER: accessed from ALPHA
        KC_1,    KC_2,    KC_3,    KC_4,    KC_5,            KC_6,    KC_7,    KC_8,    KC_9,    KC_0,
        KC_GRV,  KC_QUOT, KC_EQL,  KC_MINS, _______,         _______, KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT,
        _______, KC_BSLS, KC_LBRC, KC_RBRC, _______,         _______, KC_HOME, KC_PGDN, KC_PGUP, KC_END,
                                   _______, KC_SPC,          _______, _______),
    [MOMENTARY_MOUSE_LAYER] = LAYOUT_split_3x5_2( // MOMENTARY MOUSE: accessed from ALPHA
        KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,           KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,
        KC_PSCR, KC_ACL2, KC_ACL1, KC_ACL0, _______,         _______, KC_MS_L, KC_MS_D, KC_MS_U, KC_MS_R,
        KC_F11,  KC_F12,  KC_F13,  KC_F14,  _______,         _______, KC_WH_L, KC_WH_D, KC_WH_U, KC_WH_R,
                                   _______, _______,         KC_BTN1, KC_BTN2),
};

bool press_caps_on(void);
bool press_home(void);
