#include QMK_KEYBOARD_H

enum layers {
    _WIN = 0,
    _WINSYM,
    _MAC,
    _MACSYM,
    _LINUX,
    _LINUXSYM,
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
    [_WIN] = LAYOUT_split_3x6_3(
     KC_TAB,          KC_W,    KC_L,    KC_Y,    KC_P,    KC_B,                                                                 KC_Z,     KC_F,      KC_O,    KC_U,    KC_SCLN, KC_MINS,
     LCTL_T(KC_ESC),  KC_C,    KC_R,    KC_S,    KC_T,    KC_G,                                                                 KC_M,     KC_N,      KC_E,    KC_I,    KC_A,    MC_QUOT,
     KC_LSFT,         KC_Q,    KC_J,    KC_V,    KC_D,    KC_K,                                                                 KC_X,     KC_H,      KC_COMM, KC_DOT,  KC_SLSH, KC_END,
                                                 KC_LALT, KC_SPC, KC_LGUI,                        LT(_WINSYM, KC_ENT),  LSFT_T(KC_BSPC),  MO(_INT)
    ),
    [_WINSYM] = LAYOUT_split_3x6_3(
     MC_GRV,  KC_EXLM, KC_AMPR, KC_LCBR, KC_RCBR, MC_CIRC,                                                G(S(KC_S)),   KC_7,   KC_8, KC_9, KC_COLN, KC_DEL,
     KC_HASH, KC_EQL,  KC_DLR,  KC_LPRN, KC_RPRN, MC_TILD,                                                G(KC_UP),     KC_4,   KC_5, KC_6, KC_PLUS, KC_ASTR,
     KC_PIPE, KC_AT,   KC_PERC, KC_LBRC, KC_RBRC, KC_UP,                                                  KC_0,         KC_1,   KC_2, KC_3, KC_BSLS, KC_HOME,
                                         KC_LEFT, KC_DOWN,   KC_RGHT,                           KC_NO,    G(KC_LEFT), G(KC_RGHT)
    ),
    [_MAC] = LAYOUT_split_3x6_3(
     KC_TAB,          KC_W,    KC_L,    KC_Y,    KC_P,    KC_B,                                                                    KC_Z,     KC_F,      KC_O,    KC_U,    KC_SCLN, KC_MINS,
     LGUI_T(KC_ESC),  KC_C,    KC_R,    KC_S,    KC_T,    KC_G,                                                                    KC_M,     KC_N,      KC_E,    KC_I,    KC_A,    KC_QUOT,
     KC_LSFT,         KC_Q,    KC_J,    KC_V,    KC_D,    KC_K,                                                                    KC_X,     KC_H,      KC_COMM, KC_DOT,  KC_SLSH, KC_END,
                                                          KC_LALT, KC_SPC, KC_LCTL,        LT(_MACSYM, KC_ENT),  LSFT_T(KC_BSPC),  KC_LALT
    ),
    [_MACSYM] = LAYOUT_split_3x6_3(
     KC_GRV,  KC_EXLM, KC_AMPR, KC_LCBR, KC_RCBR, KC_CIRC,                                             G(S(KC_4)),   KC_7,   KC_8, KC_9, KC_COLN, KC_DEL,
     KC_HASH, KC_EQL,  KC_DLR,  KC_LPRN, KC_RPRN, KC_TILD,                                             C(KC_UP),     KC_4,   KC_5, KC_6, KC_PLUS, KC_ASTR,
     KC_PIPE, KC_AT,   KC_PERC, KC_LBRC, KC_RBRC, KC_UP,                                               KC_0,         KC_1,   KC_2, KC_3, KC_BSLS, KC_HOME,
                                                  KC_LEFT, KC_DOWN,   KC_RGHT,      KC_NO,    KC_NO,   KC_NO
    ),
    [_LINUX] = LAYOUT_split_3x6_3(
     KC_TAB,          KC_Q,    KC_W,    KC_F,    KC_P,    KC_B,                                                                    KC_J,     KC_L,      KC_U,    KC_Y,    KC_SCLN, KC_MINS,
     LCTL_T(KC_ESC),  KC_A,    KC_R,    KC_S,    KC_T,    KC_G,                                                                    KC_M,     KC_N,      KC_E,    KC_I,    KC_O,    KC_QUOT,
     KC_LSFT,         KC_Z,    KC_X,    KC_C,    KC_D,    KC_V,                                                                    KC_K,     KC_H,      KC_COMM, KC_DOT,  KC_SLSH, KC_END,
                                                          KC_LALT, KC_SPC, KC_LGUI,        LT(_LINUXSYM, KC_ENT),  LSFT_T(KC_BSPC),  KC_RALT
    ),
    [_LINUXSYM] = LAYOUT_split_3x6_3(
     KC_GRV,  KC_EXLM, KC_AMPR, KC_LCBR, KC_RCBR, KC_CIRC,                                             KC_PSCR,   KC_7,   KC_8, KC_9, KC_COLN, KC_DEL,
     KC_HASH, KC_EQL,  KC_DLR,  KC_LPRN, KC_RPRN, KC_TILD,                                             G(KC_UP),        KC_4,   KC_5, KC_6, KC_PLUS, KC_ASTR,
     KC_PIPE, KC_AT,   KC_PERC, KC_LBRC, KC_RBRC, KC_UP,                                               KC_0,         KC_1,   KC_2, KC_3, KC_BSLS, KC_HOME,
                                                  KC_LEFT, KC_DOWN,   KC_RGHT,      KC_NO,    G(KC_LEFT), G(KC_RGHT)
    ),
    [_INT] = LAYOUT_split_3x6_3(
     KC_NO,    KC_NO,      KC_NO, KC_NO,      KC_NO, KC_NO,                                            KC_NO,   KC_NO,   RALT(KC_P),      RALT(KC_Y), KC_NO,      KC_NO,
     KC_NO,    KC_NO,      KC_NO, RALT(KC_S), KC_NO, KC_NO,                                            KC_NO,   KC_NO,   RALT(KC_5),      KC_NO,      RALT(KC_Q), KC_NO,
     KC_LSFT,  KC_NO,      KC_NO, KC_NO,      KC_NO, KC_NO,                                            KC_NO,   KC_NO,   KC_F2,           KC_NO,      KC_NO,      KC_NO,
                                                     KC_NO, KC_NO, KC_NO,             KC_NO , KC_LSFT, KC_NO
    ),
    [_TEMPLATE] = LAYOUT_split_3x6_3(
     KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,                                         KC_NO,   KC_NO,   KC_NO, KC_NO, KC_NO, KC_NO,
     KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,                                         KC_NO,   KC_NO,   KC_NO, KC_NO, KC_NO, KC_NO,
     KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,                                         KC_NO,   KC_NO,   KC_NO, KC_NO, KC_NO, KC_NO,
                                 KC_NO, KC_NO, KC_NO,                    KC_NO, KC_NO, KC_NO
    ),
};

bool process_detected_host_os_kb(os_variant_t detected_os) {
    if (!process_detected_host_os_user(detected_os)) {
        return false;
    }

    switch (detected_os) {
        case OS_MACOS:
        case OS_IOS:
            default_layer_set(1 << _MAC);
            break;
        case OS_WINDOWS:
            default_layer_set(1 << _WIN);
            break;
        case OS_LINUX:
            default_layer_set(1 << _LINUX);
            break;
        case OS_UNSURE:
            break;
    }

    return true;
}

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
