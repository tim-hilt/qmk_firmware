#include QMK_KEYBOARD_H

enum layers {
    _BASE = 0,
    _SYM,
    _MACRO,
};

// TODO: Leader key?
// TODO: record / replay macros?

// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_BASE] = LAYOUT(
     KC_TAB,          KC_Q,    KC_W,    KC_F,    KC_P,    KC_B,                                                               KC_J,    KC_L,      KC_U,    KC_Y,    KC_SCLN, KC_MINS,
     LGUI_T(KC_ESC),  KC_A,    KC_R,    KC_S,    KC_T,    KC_G,                                                               KC_M,    KC_N,      KC_E,    KC_I,    KC_O,    KC_QUOT,
     KC_LSFT,         KC_Z,    KC_X,    KC_C,    KC_D,    KC_V,    KC_MUTE,                                  KC_MPLY,         KC_K,    KC_H,      KC_COMM, KC_DOT,  KC_SLSH, KC_END,
                                                 KC_LCTL, KC_LALT, KC_SPC, MO(_MACRO),    LT(_SYM, KC_ENT),  LSFT_T(KC_BSPC), KC_LALT, G(S(KC_4))
    ),
    [_SYM] = LAYOUT(
     KC_GRV,  KC_EXLM, KC_AMPR, KC_LCBR, KC_RCBR, KC_CIRC,                                         KC_NO,   KC_7,   KC_8, KC_9, KC_COLN, KC_TRNS,
     KC_HASH, KC_EQL,  KC_DLR,  KC_LPRN, KC_RPRN, KC_TILD,                                         KC_NO,   KC_4,   KC_5, KC_6, KC_PLUS, KC_ASTR,
     KC_TRNS, KC_AT,   KC_PERC, KC_LBRC, KC_RBRC, KC_PIPE, KC_TRNS,                       KC_TRNS, KC_0,    KC_1,   KC_2, KC_3, KC_BSLS, KC_HOME,
                                         KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT,    KC_TRNS , KC_TRNS, KC_TRNS, KC_TRNS
    ),
    [_MACRO] = LAYOUT(
     KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,                                          KC_NO,   KC_NO,   KC_NO, KC_NO, KC_NO, KC_NO,
     KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,                                          KC_NO,   KC_NO,   KC_NO, KC_NO, KC_NO, KC_NO,
     KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,                            KC_NO, KC_NO,   KC_NO,   KC_NO, KC_NO, KC_NO, KC_NO,
                                        KC_NO, KC_NO, KC_NO,   KC_NO,    KC_NO , KC_NO, KC_NO,   KC_NO
    ),
};
