#include QMK_KEYBOARD_H

enum layers {
    _BASE = 0,
    _SYM,
    _INT,
    _TEMPLATE,
};

enum custom_keycodes {
    MC_QUOT = SAFE_RANGE,
    MC_GRV,
    MC_TILD,
    MC_CIRC,
};

// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_BASE] = LAYOUT(
     KC_TAB,          KC_Q,    KC_W,    KC_F,    KC_P,    KC_B,                                                                 KC_J,     KC_L,      KC_U,    KC_Y,    KC_SCLN, KC_MINS,
     LCTL_T(KC_ESC),  KC_A,    KC_R,    KC_S,    KC_T,    KC_G,                                                                 KC_M,     KC_N,      KC_E,    KC_I,    KC_O,    MC_QUOT,
     KC_LSFT,         KC_Z,    KC_X,    KC_C,    KC_D,    KC_V,    XXXXXXX,                                   XXXXXXX,          KC_K,     KC_H,      KC_COMM, KC_DOT,  KC_SLSH, KC_END,
                                                 XXXXXXX, KC_LALT, KC_SPC, KC_LGUI,        LT(_SYM, KC_ENT),  LSFT_T(KC_BSPC),  MO(_INT), XXXXXXX
    ),
    [_SYM] = LAYOUT(
     MC_GRV,  KC_EXLM, KC_AMPR, KC_LCBR, KC_RCBR, MC_CIRC,                                             G(S(KC_S)),   KC_7,   KC_8, KC_9, KC_COLN, KC_MINS,
     KC_HASH, KC_EQL,  KC_DLR,  KC_LPRN, KC_RPRN, MC_TILD,                                             KC_NO,        KC_4,   KC_5, KC_6, KC_PLUS, KC_ASTR,
     KC_PIPE, KC_AT,   KC_PERC, KC_LBRC, KC_RBRC, KC_UP,   XXXXXXX,                           XXXXXXX, KC_0,         KC_1,   KC_2, KC_3, KC_BSLS, KC_HOME,
                                         XXXXXXX, KC_LEFT, KC_DOWN,   KC_RGHT,      KC_NO,    KC_NO,   KC_NO,        XXXXXXX
    ),
    [_INT] = LAYOUT(
     KC_NO, KC_NO,      KC_NO, KC_NO,      KC_NO, KC_NO,                                            KC_NO,   KC_NO,   RALT(KC_Y), KC_NO, KC_NO,      KC_NO,
     KC_NO, RALT(KC_Q), KC_NO, RALT(KC_S), KC_NO, KC_NO,                                            KC_NO,   KC_NO,   RALT(KC_5), KC_NO, RALT(KC_P), KC_NO,
     KC_NO, KC_NO,      KC_NO, KC_NO,      KC_NO, KC_NO, KC_NO,                            KC_NO,   KC_NO,   KC_NO,   KC_F2,      KC_NO, KC_NO,      KC_NO,
                                                  KC_NO, KC_NO, KC_NO,   KC_NO,    KC_NO , KC_LSFT, KC_NO,   KC_NO
    ),
    [_TEMPLATE] = LAYOUT(
     KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,                                         KC_NO,   KC_NO,   KC_NO, KC_NO, KC_NO, KC_NO,
     KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,                                         KC_NO,   KC_NO,   KC_NO, KC_NO, KC_NO, KC_NO,
     KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,                           KC_NO, KC_NO,   KC_NO,   KC_NO, KC_NO, KC_NO, KC_NO,
                                KC_NO, KC_NO, KC_NO, KC_NO,              KC_NO, KC_NO, KC_NO,   KC_NO
    ),
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case MC_QUOT:
            if (record->event.pressed) {
                SEND_STRING(SS_TAP(X_QUOT) SS_TAP(X_SPC));
            }
            return false;
        case MC_GRV:
            if (record->event.pressed) {
                SEND_STRING(SS_TAP(X_GRV) SS_TAP(X_SPC));
            }
            return false;
        case MC_CIRC:
            if (record->event.pressed) {
                SEND_STRING("^" SS_TAP(X_SPC));
            }
            return false;
        case MC_TILD:
            if (record->event.pressed) {
                SEND_STRING("~" SS_TAP(X_SPC));
            }
            return false;
    }

    return true;
}
