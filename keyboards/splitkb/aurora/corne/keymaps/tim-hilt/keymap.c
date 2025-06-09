#include QMK_KEYBOARD_H

enum layers {
    _WIN = 0,
    _MAC,
    _WINSYM,
    _MACSYM,
    _INT,
    _NAV,
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
     KC_NO,  KC_Q,         KC_W,           KC_F,         KC_P,         KC_B,                                                 KC_J,            KC_L,         KC_U,         KC_Y,         MC_QUOT,      KC_NO,
     KC_NO,  LGUI_T(KC_A), LALT_T(KC_R),   LCTL_T(KC_S), LSFT_T(KC_T), KC_G,                                                 KC_M,            LSFT_T(KC_N), LCTL_T(KC_E), LALT_T(KC_I), LGUI_T(KC_O), KC_NO,
     KC_NO,  KC_Z,         KC_X,           KC_C,         KC_D,         KC_V,                                                 KC_K,            KC_H,         KC_COMM,      KC_DOT,       KC_SLSH,      KC_NO,
                                                         KC_ESC,       KC_SPC, LT(_NAV, KC_TAB),        LT(_WINSYM, KC_ENT), LSFT_T(KC_BSPC), LT(_INT, KC_DEL)
    ),
    [_WINSYM] = LAYOUT_split_3x6_3(
     KC_NO,   KC_EXLM, KC_AMPR, KC_LCBR, KC_RCBR, MC_CIRC,                              G(S(KC_S)), KC_7,   KC_8, KC_9, KC_ASTR, KC_NO,
     KC_NO,   KC_EQL,  KC_DLR,  KC_LPRN, KC_RPRN, MC_TILD,                              KC_HASH,    KC_4,   KC_5, KC_6, KC_PLUS, KC_NO,
     KC_NO,   KC_AT,   KC_PERC, KC_LBRC, KC_RBRC, KC_MINS,                              KC_0,       KC_1,   KC_2, KC_3, KC_BSLS, KC_NO,
                                         KC_UNDS, KC_COLN,   KC_SCLN,        KC_NO,     KC_PIPE,    MC_GRV
    ),
    [_MAC] = LAYOUT_split_3x6_3(
     KC_NO,  KC_Q,         KC_W,           KC_F,         KC_P,         KC_B,                                                 KC_J,            KC_L,         KC_U,         KC_Y,         KC_QUOT,      KC_NO,
     KC_NO,  LGUI_T(KC_A), LALT_T(KC_R),   LCTL_T(KC_S), LSFT_T(KC_T), KC_G,                                                 KC_M,            LSFT_T(KC_N), LCTL_T(KC_E), LALT_T(KC_I), LGUI_T(KC_O), KC_NO,
     KC_NO,  KC_Z,         KC_X,           KC_C,         KC_D,         KC_V,                                                 KC_K,            KC_H,         KC_COMM,      KC_DOT,       KC_SLSH,      KC_NO,
                                                         KC_ESC,       KC_SPC, LT(_NAV, KC_TAB),        LT(_WINSYM, KC_ENT), LSFT_T(KC_BSPC), KC_DEL
    ),
    [_MACSYM] = LAYOUT_split_3x6_3(
     KC_NO,   KC_EXLM, KC_AMPR, KC_LCBR, KC_RCBR, KC_CIRC,                              G(S(KC_4)), KC_7,   KC_8, KC_9, KC_ASTR, KC_NO,
     KC_NO,   KC_EQL,  KC_DLR,  KC_LPRN, KC_RPRN, KC_TILD,                              KC_HASH,    KC_4,   KC_5, KC_6, KC_PLUS, KC_NO,
     KC_NO,   KC_AT,   KC_PERC, KC_LBRC, KC_RBRC, KC_MINS,                              KC_0,       KC_1,   KC_2, KC_3, KC_BSLS, KC_NO,
                                         KC_UNDS, KC_COLN,   KC_SCLN,        KC_NO,     KC_PIPE,    KC_GRV
    ),
    [_INT] = LAYOUT_split_3x6_3(
     KC_NO, KC_NO,      KC_NO, KC_NO,      KC_NO, KC_NO,                                    KC_NO,   KC_NO,   RALT(KC_Y), KC_NO, KC_NO,      KC_NO,
     KC_NO, RALT(KC_Q), KC_NO, RALT(KC_S), KC_NO, KC_NO,                                    KC_NO,   KC_NO,   RALT(KC_5), KC_NO, RALT(KC_P), KC_NO,
     KC_NO, KC_NO,      KC_NO, KC_NO,      KC_NO, KC_NO,                                    KC_NO,   KC_NO,   KC_F2,      KC_NO, KC_NO,      KC_NO,
                                                  KC_NO, KC_NO, KC_NO,     KC_NO , KC_LSFT, KC_NO
    ),
    [_NAV] = LAYOUT_split_3x6_3(
     KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,                         KC_NO,   G(KC_LEFT), G(KC_DOWN), G(KC_UP), G(KC_RGHT), KC_NO,
     KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,                         KC_NO,   KC_LEFT,    KC_DOWN,    KC_UP,    KC_RGHT,    KC_NO,
     KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,                         KC_NO,   KC_HOME,    KC_PGDN,    KC_PGUP,  KC_END,     KC_NO,
                                 KC_NO, KC_NO, KC_NO,    KC_NO, KC_NO, KC_NO
    ),
    [_TEMPLATE] = LAYOUT_split_3x6_3(
     KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,                         KC_NO,   KC_NO,   KC_NO, KC_NO, KC_NO, KC_NO,
     KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,                         KC_NO,   KC_NO,   KC_NO, KC_NO, KC_NO, KC_NO,
     KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,                         KC_NO,   KC_NO,   KC_NO, KC_NO, KC_NO, KC_NO,
                                 KC_NO, KC_NO, KC_NO,    KC_NO, KC_NO, KC_NO
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
        case OS_LINUX:
        case OS_UNSURE:
        case OS_WINDOWS:
            default_layer_set(1 << _WIN);
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
