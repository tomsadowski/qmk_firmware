// tomsadowski
// keymap for split_3x5_2 keyboards

#include QMK_KEYBOARD_H
#include "action.h"
#include "keycodes.h"
#include "quantum_keycodes.h"
#include "process_combo.h"

//                           . 3 3 . .          . . 3 3 .
const uint16_t PROGMEM    tab_cmb_l[] = {KC_C,    KC_H,    COMBO_END};
const uint16_t PROGMEM    tab_cmb_r[] = {KC_W,    KC_P,    COMBO_END};
//                           . 2 2 . .          . . 2 2 .
const uint16_t PROGMEM  shift_cmb_l[] = {KC_S,    KC_R,    COMBO_END};
const uint16_t PROGMEM  shift_cmb_r[] = {KC_I,    KC_O,    COMBO_END};
//                           . 1 1 . .          . . 1 1 .
const uint16_t PROGMEM   caps_cmb_l[] = {KC_F,    KC_L,    COMBO_END};
const uint16_t PROGMEM   home_cmb_r[] = {KC_M,    KC_G,    COMBO_END};
//                           3 . . 3 .          . 3 . . 3
const uint16_t PROGMEM    alt_cmb_l[] = {KC_K,    KC_B,    COMBO_END};
const uint16_t PROGMEM    alt_cmb_r[] = {KC_Y,    KC_V,    COMBO_END};
//                           2 . . 2 .          . 2 . . 2
const uint16_t PROGMEM   ctrl_cmb_l[] = {KC_A,    KC_T,    COMBO_END};
const uint16_t PROGMEM   ctrl_cmb_r[] = {KC_E,    KC_N,    COMBO_END};
//                           1 . . 1 .          . 1 . . 1
const uint16_t PROGMEM  lnav2_cmb_l[] = {KC_J,    KC_D,    COMBO_END};
const uint16_t PROGMEM  mouse_cmb_r[] = {KC_U,    KC_Q,    COMBO_END};
//                           3 . . . 3          3 . . . 3
const uint16_t PROGMEM  game2_cmb_l[] = {KC_K,    KC_X,    COMBO_END};
const uint16_t PROGMEM  game3_cmb_r[] = {KC_Z,    KC_V,    COMBO_END};
//                           3 . . 2 .          . 2 . . 3
const uint16_t PROGMEM    gui_cmb_l[] = {KC_T,    KC_K,    COMBO_END};
const uint16_t PROGMEM    gui_cmb_r[] = {KC_E,    KC_V,    COMBO_END};
//                           2 . . 1 .          . 1 . . 2
const uint16_t PROGMEM  lnav1_cmb_l[] = {KC_A,    KC_D,    COMBO_END};
const uint16_t PROGMEM  numbe_cmb_r[] = {KC_U,    KC_N,    COMBO_END};
//                           . . . 3 2          2 3 . . .
const uint16_t PROGMEM    esc_cmb_l[] = {KC_B,    KC_COMM, COMBO_END};
const uint16_t PROGMEM  enter_cmb_r[] = {KC_DOT,  KC_Y,    COMBO_END};

enum combos
{
    // . 3 3 . .     . . 3 3 .
    TAB_CMB_L,     TAB_CMB_R,
    // . 2 2 . .     . . 2 2 .
    SHIFT_CMB_L,   SHIFT_CMB_R,
    // . 1 1 . .     . . 1 1 .
    CAPS_CMB_L,    HOME_CMB_R,
    // 3 . . 3 .     . 3 . . 3
    ALT_CMB_L,     ALT_CMB_R,
    // 2 . . 2 .     . 2 . . 2
    CTRL_CMB_L,    CTRL_CMB_R,
    // 1 . . 1 .     . 1 . . 1
    LNAV2_CMB_L,   MOUSE_CMB_R,
    // 3 . . . 3     3 . . . 3
    GAME2_CMB_L,   GAME3_CMB_R,
    // 3 . . 2 .     . 2 . . 3
    GUI_CMB_L,     GUI_CMB_R,
    // 2 . . 1 .     . 1 . . 2
    LNAV1_CMB_L,   NUMBE_CMB_R,
    // . . . 3 2     2 3 . . .
    ESC_CMB_L,     ENTER_CMB_R,
};

enum custom_keycodes
{
    LAYOUT_HOME = SAFE_RANGE,
    CAPS_ON
};

enum layers
{
    // standard
    ALPHA_LYR, // alpha keys
    NUMBE_LYR, // number, arrow, misc keys
    MOUSE_LYR, // mouse, function keys

    // momentary
    ALPHA_FROM_NUMBE_LYR,   // Alpha From Number
    ALPHA_FROM_MOUSE_LYR,   // Alpha From Mouse
    NUMBE_FROM_ALPHA_LYR,   // Number From Alpha
    MOUSE_FROM_ALPHA_LYR,   // Mouse From Alpha

    // lefty
    LNAV1_LYR, // arrows under left hand
    LNAV2_LYR, // mouse under left hand

    // game (no combos / no outlet)
    GAME2_LYR,  // 2D game choices
    GAME21_LYR, // 2D game
    GAME22_LYR, // 2D game
    GAME23_LYR, // 2D game

    GAME3_LYR,  // 3D game choices
    GAME31_LYR, // 3D game
    GAME32_LYR, // 3D game
    GAME33_LYR, // 3D game

    ALPHA_FROM_GAME_LYR,    // Alpha From Game
};

combo_t key_combos[] =
{
    // . 3 3 . .     . . 3 3 .
    [TAB_CMB_L]   = COMBO(   tab_cmb_l, KC_TAB),
    [TAB_CMB_R]   = COMBO(   tab_cmb_r, KC_TAB),
    // . 2 2 . .    . . 2 2 .
    [SHIFT_CMB_L] = COMBO( shift_cmb_l, KC_LEFT_SHIFT),
    [SHIFT_CMB_R] = COMBO( shift_cmb_r, KC_RIGHT_SHIFT),
    // . 1 1 . .    . . 1 1 .
    [CAPS_CMB_L]  = COMBO(  caps_cmb_l, CAPS_ON),
    [HOME_CMB_R]  = COMBO(  home_cmb_r, LAYOUT_HOME),
    // 3 . . 3 .    . 3 . . 3
    [ALT_CMB_L]   = COMBO(   alt_cmb_l, KC_LEFT_ALT),
    [ALT_CMB_R]   = COMBO(   alt_cmb_r, KC_RIGHT_ALT),
    // 2 . . 2 .    . 2 . . 2
    [CTRL_CMB_L]  = COMBO(  ctrl_cmb_l, KC_LEFT_CTRL),
    [CTRL_CMB_R]  = COMBO(  ctrl_cmb_r, KC_RIGHT_CTRL),
    // 1 . . 1 .    . 1 . . 1
    [LNAV2_CMB_L] = COMBO( lnav2_cmb_l, TO(LNAV2_LYR)),
    [MOUSE_CMB_R] = COMBO( mouse_cmb_r, TO(MOUSE_LYR)),
    // 2 . . . 2    2 . . . 2
    [GAME2_CMB_L] = COMBO( game2_cmb_l, TO(GAME2_LYR)),
    [GAME3_CMB_R] = COMBO( game3_cmb_r, TO(GAME3_LYR)),
    // 3 . . 2 .    . 2 . . 3
    [GUI_CMB_L]   = COMBO(   gui_cmb_l, KC_LEFT_GUI),
    [GUI_CMB_R]   = COMBO(   gui_cmb_r, KC_RIGHT_GUI),
    // 2 . . 1 .    . 1 . . 2
    [LNAV1_CMB_L] = COMBO( lnav1_cmb_l, TO(LNAV1_LYR)),
    [NUMBE_CMB_R] = COMBO( numbe_cmb_r, TO(NUMBE_LYR)),
    // . . . 3 2    2 3 . . .
    [ESC_CMB_L]   = COMBO(   esc_cmb_l, KC_ESCAPE),
    [ENTER_CMB_R] = COMBO( enter_cmb_r, KC_ENTER),
};

#define ATM_SPC LT(MOUSE_FROM_ALPHA_LYR, KC_SPC)
#define ATN_SPC LT(NUMBE_FROM_ALPHA_LYR, KC_SPC)
#define NTA_SPC LT(ALPHA_FROM_NUMBE_LYR, KC_SPC)
#define MTA_SPC LT(ALPHA_FROM_MOUSE_LYR, KC_SPC)
#define GTA     MO(ALPHA_FROM_GAME_LYR)
#define TO_G21  TO(GAME21_LYR)
#define TO_G22  TO(GAME22_LYR)
#define TO_G23  TO(GAME23_LYR)
#define TO_G31  TO(GAME31_LYR)
#define TO_G32  TO(GAME32_LYR)
#define TO_G33  TO(GAME33_LYR)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] =
{
[ALPHA_LYR] = LAYOUT_split_3x5_2(
KC_K   ,KC_C   ,KC_H   ,KC_B,   KC_X   ,KC_Z   ,KC_Y   ,KC_W   ,KC_P   ,KC_V   ,
KC_A   ,KC_S   ,KC_R   ,KC_T,   KC_COMM,KC_DOT ,KC_E   ,KC_I   ,KC_O   ,KC_N   ,
KC_J   ,KC_F   ,KC_L   ,KC_D,   KC_QUOT,KC_SCLN,KC_U   ,KC_M   ,KC_G   ,KC_Q   ,
                        KC_BSPC,ATM_SPC,ATN_SPC,KC_DEL
),
[NUMBE_LYR] = LAYOUT_split_3x5_2(
KC_1   ,KC_2   ,KC_3   ,KC_4   ,KC_5   ,KC_6   ,KC_7   ,KC_8   ,KC_9   ,KC_0   ,
KC_GRV ,KC_BSLS,KC_SLSH,KC_MINS,_______,_______,KC_LEFT,KC_DOWN,KC_UP  ,KC_RGHT,
KC_INS ,KC_LBRC,KC_RBRC,KC_EQL ,_______,_______,KC_HOME,KC_PGDN,KC_PGUP,KC_END ,
                        _______,_______,NTA_SPC,_______
),
[MOUSE_LYR] = LAYOUT_split_3x5_2(
KC_F1  ,KC_F2  ,KC_F3  ,KC_F4  ,KC_F5  ,KC_F6  ,KC_F7  ,KC_F8  ,KC_F9  ,KC_F10 ,
KC_PSCR,KC_BTN5,KC_BTN4,KC_BTN3,_______,_______,KC_MS_L,KC_MS_D,KC_MS_U,KC_MS_R,
KC_F11 ,KC_F12 ,KC_F13 ,KC_F14 ,_______,_______,KC_WH_L,KC_WH_D,KC_WH_U,KC_WH_R,
                        _______,MTA_SPC,KC_BTN1,KC_BTN2
),
[ALPHA_FROM_NUMBE_LYR] = LAYOUT_split_3x5_2(
KC_K   ,KC_C   ,KC_H   ,KC_B   ,KC_X   ,KC_Z   ,KC_Y   ,KC_W   ,KC_P   ,KC_V   ,
KC_A   ,KC_S   ,KC_R   ,KC_T   ,_______,_______,KC_E   ,KC_I   ,KC_O   ,KC_N   ,
KC_J   ,KC_F   ,KC_L   ,KC_D   ,_______,_______,KC_U   ,KC_M   ,KC_G   ,KC_Q   ,
                        _______,KC_SPC ,_______,_______
),
[ALPHA_FROM_MOUSE_LYR] = LAYOUT_split_3x5_2(
KC_K   ,KC_C   ,KC_H   ,KC_B   ,KC_X   ,KC_Z   ,KC_Y   ,KC_W   ,KC_P   ,KC_V   ,
KC_A   ,KC_S   ,KC_R   ,KC_T   ,_______,_______,KC_E   ,KC_I   ,KC_O   ,KC_N   ,
KC_J   ,KC_F   ,KC_L   ,KC_D   ,_______,_______,KC_U   ,KC_M   ,KC_G   ,KC_Q   ,
                        _______,_______,ATN_SPC,KC_DEL
),
[NUMBE_FROM_ALPHA_LYR] = LAYOUT_split_3x5_2(
KC_1   ,KC_2   ,KC_3   ,KC_4   ,KC_5   ,KC_6   ,KC_7   ,KC_8   ,KC_9   ,KC_0   ,
KC_GRV ,KC_BSLS,KC_SLSH,KC_MINS,_______,_______,KC_LEFT,KC_DOWN,KC_UP  ,KC_RGHT,
KC_INS ,KC_LBRC,KC_RBRC,KC_EQL ,_______,_______,KC_HOME,KC_PGDN,KC_PGUP,KC_END ,
                        _______,KC_SPC ,_______,_______
),
[MOUSE_FROM_ALPHA_LYR] = LAYOUT_split_3x5_2(
KC_F1  ,KC_F2  ,KC_F3  ,KC_F4  ,KC_F5  ,KC_F6  ,KC_F7  ,KC_F8  ,KC_F9  ,KC_F10 ,
KC_PSCR,KC_BTN5,KC_BTN4,KC_BTN3,_______,_______,KC_MS_L,KC_MS_D,KC_MS_U,KC_MS_R,
KC_F11 ,KC_F12 ,KC_F13 ,KC_F14 ,_______,_______,KC_WH_L,KC_WH_D,KC_WH_U,KC_WH_R,
                        _______,_______,KC_BTN1,KC_BTN2
),
// eat with right hand youtube with left
[LNAV1_LYR] = LAYOUT_split_3x5_2(
_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,
KC_LEFT,KC_UP,  KC_DOWN,KC_RGHT,_______,_______,_______,_______,_______,_______,
KC_HOME,KC_PGUP,KC_PGDN,KC_END ,_______,_______,_______,_______,_______,_______,
                        _______,KC_SPC ,KC_SPC ,_______
),
// eat with right hand youtube with left
[LNAV2_LYR] = LAYOUT_split_3x5_2(
_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,
KC_MS_L,KC_MS_U,KC_MS_D,KC_MS_R,_______,_______,_______,_______,_______,_______,
KC_WH_L,KC_WH_U,KC_WH_D,KC_WH_R,_______,_______,_______,_______,_______,_______,
                        KC_BTN2,KC_BTN1,KC_SPC ,_______
),
// choose your 2D game layer
[GAME2_LYR] = LAYOUT_split_3x5_2(
_______,_______,_______,_______,_______,_______,_______,TO_G23 ,TO_G22 ,TO_G21 ,
_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,
_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,
                        _______,_______,_______,_______
),
// silksong
[GAME21_LYR] = LAYOUT_split_3x5_2(
_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,
_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,
_______,_______,_______,_______,KC_ESC ,KC_ENT ,_______,_______,_______,_______,
                        KC_1   ,KC_2   ,KC_3   ,KC_4
),
// nine sols
[GAME22_LYR] = LAYOUT_split_3x5_2(
KC_A   ,KC_W   ,KC_S   ,KC_D   ,_______,_______,_______,KC_C   ,_______,_______,
KC_LEFT,KC_UP,  KC_DOWN,KC_RGHT,_______,_______,_______,_______,_______,_______,
_______,_______,_______,KC_B   ,KC_ESC ,KC_ENT ,_______,_______,_______,_______,
                        KC_K   ,KC_H   ,KC_R   ,KC_T
),
// kingdom
[GAME23_LYR] = LAYOUT_split_3x5_2(
_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,
KC_LEFT,KC_UP,  KC_DOWN,KC_RGHT,_______,_______,KC_LEFT,KC_DOWN,KC_UP  ,KC_RGHT,
_______,_______,_______,_______,KC_ESC ,KC_ENT ,_______,_______,_______,_______,
                        KC_1   ,KC_2   ,KC_3   ,KC_4
),
// choose your 3D game layer
[GAME3_LYR] = LAYOUT_split_3x5_2(
TO_G31 ,TO_G32 ,TO_G33 ,_______,_______,_______,_______,_______,_______,_______,
_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,
_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,
                        _______,_______,_______,_______
),
// quake
[GAME31_LYR] = LAYOUT_split_3x5_2(
_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,
_______,_______,_______,_______,_______,_______,KC_MS_L,KC_MS_D,KC_MS_U,KC_MS_R,
_______,_______,_______,_______,KC_ESC ,KC_ENT ,_______,_______,_______,_______,
                        _______,KC_SPC ,KC_BTN1,KC_BTN2
),
// project zomboid
[GAME32_LYR] = LAYOUT_split_3x5_2(
KC_1   ,KC_2   ,KC_3   ,KC_4   ,KC_5   ,KC_6   ,KC_7   ,KC_8   ,KC_9   ,KC_0   ,
KC_LEFT,KC_UP,  KC_DOWN,KC_RGHT,_______,_______,KC_MS_L,KC_MS_D,KC_MS_U,KC_MS_R,
KC_INS ,KC_LBRC,KC_RBRC,KC_EQL ,KC_ESC ,KC_ENT ,KC_HOME,KC_WH_D,KC_WH_U,KC_END ,
                        _______,GTA    ,KC_BTN1,KC_BTN2
),
// project zomboid
[GAME33_LYR] = LAYOUT_split_3x5_2(
KC_1   ,KC_2   ,KC_3   ,KC_4   ,KC_5   ,KC_6   ,KC_7   ,KC_8   ,KC_9   ,KC_0   ,
KC_LEFT,KC_UP,  KC_DOWN,KC_RGHT,_______,_______,KC_MS_L,KC_MS_D,KC_MS_U,KC_MS_R,
KC_INS ,KC_LBRC,KC_RBRC,KC_EQL ,KC_ESC ,KC_ENT ,KC_HOME,KC_WH_D,KC_WH_U,KC_END ,
                        _______,KC_SPC ,KC_BTN1,KC_BTN2
),
// project zomboid
[ALPHA_FROM_GAME_LYR] = LAYOUT_split_3x5_2(
KC_K   ,KC_C   ,KC_H   ,KC_B   ,KC_X   ,KC_Z   ,KC_Y   ,KC_W   ,KC_P   ,KC_V   ,
KC_A   ,KC_S   ,KC_R   ,KC_T   ,_______,_______,KC_E   ,KC_I   ,KC_O   ,KC_N   ,
KC_J   ,KC_F   ,KC_L   ,KC_D   ,_______,_______,KC_U   ,KC_M   ,KC_G   ,KC_Q   ,
                        _______,_______,KC_SPC ,KC_DEL
),
};

// KC_ESCAPE breaks capsword, KC_SPACE does not
bool caps_word_press_user(uint16_t keycode)
{
    switch (keycode)
    {
        case KC_A ... KC_Z:
            add_weak_mods(MOD_BIT(KC_LEFT_SHIFT));
            return true;
        case KC_ESCAPE:
            return false;
        default:
            return true;
    }
}

// process custom keys
bool process_record_user(uint16_t keycode,
                         keyrecord_t* record)
{
    switch (keycode)
    {
        case LAYOUT_HOME:
            if (record->event.pressed)
            {
                caps_word_off();
                layer_move(ALPHA_LYR);
            }
            return false;

        case CAPS_ON:
            if (record->event.pressed)
                caps_word_on();
            return false;

        default:
            return true;
    }
}

// ATM_SPC will go to mouse layer before TAPPING_TERM elapses
// if another key is pressed then released
bool get_permissive_hold(uint16_t keycode,
                         keyrecord_t* record)
{
    switch (keycode)
    {
        case ATM_SPC:
            return true;
        default:
            return false;
    }
}

// ATN_SPC will go to number layer before TAPPING_TERM
// elapses if another key is pressed
bool get_hold_on_other_key_press(uint16_t keycode,
                                 keyrecord_t* record)
{
    switch (keycode)
    {
        case ATN_SPC:
            return true;
        default:
            return false;
    }
}

// switching to non-alpha layers breaks capsword
layer_state_t layer_state_set_user(layer_state_t state)
{
    switch (get_highest_layer(state))
    {
        case NUMBE_LYR ... LNAV2_LYR:
            caps_word_off();
            break;
        case GAME21_LYR:
            caps_word_off();
            combo_disable();
            break;
        case GAME22_LYR:
            caps_word_off();
            combo_disable();
            break;
        case GAME23_LYR:
            caps_word_off();
            combo_disable();
            break;
        case GAME31_LYR:
            caps_word_off();
            combo_disable();
            break;
        case GAME32_LYR:
            caps_word_off();
            combo_disable();
            break;
        case GAME33_LYR:
            caps_word_off();
            combo_disable();
            break;
        default:
            break;
    }
    return state;
}
