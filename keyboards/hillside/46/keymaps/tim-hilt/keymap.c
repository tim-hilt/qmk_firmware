#include QMK_KEYBOARD_H

enum layers {
    _WIN = 0,
    _MAC,
    _WINSYM,
    _MACSYM,
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
    [_WIN] = LAYOUT(
     KC_TAB,          KC_W,    KC_L,    KC_Y,    KC_P,    KC_B,                                                                 KC_Z,     KC_F,      KC_O,    KC_U,    KC_SCLN, KC_MINS,
     LCTL_T(KC_ESC),  KC_C,    KC_R,    KC_S,    KC_T,    KC_G,                                                                 KC_M,     KC_N,      KC_E,    KC_I,    KC_A,    MC_QUOT,
     KC_LSFT,         KC_Q,    KC_J,    KC_V,    KC_D,    KC_K,    XXXXXXX,                                      XXXXXXX,       KC_X,     KC_H,      KC_COMM, KC_DOT,  KC_SLSH, KC_END,
                                                 XXXXXXX, KC_LALT, KC_SPC, KC_LGUI,        LT(_WINSYM, KC_ENT),  LSFT_T(KC_BSPC),  MO(_INT), XXXXXXX
    ),
    [_WINSYM] = LAYOUT(
     MC_GRV,  KC_EXLM, KC_AMPR, KC_LCBR, KC_RCBR, MC_CIRC,                                                G(S(KC_S)),   KC_7,   KC_8, KC_9, KC_COLN, KC_DEL,
     KC_HASH, KC_EQL,  KC_DLR,  KC_LPRN, KC_RPRN, MC_TILD,                                                G(KC_UP),     KC_4,   KC_5, KC_6, KC_PLUS, KC_ASTR,
     KC_PIPE, KC_AT,   KC_PERC, KC_LBRC, KC_RBRC, KC_UP,   XXXXXXX,                           XXXXXXX,    KC_0,         KC_1,   KC_2, KC_3, KC_BSLS, KC_HOME,
                                         XXXXXXX, KC_LEFT, KC_DOWN,   KC_RGHT,      KC_NO,    G(KC_LEFT), G(KC_RGHT),   XXXXXXX
    ),
    [_MAC] = LAYOUT(
     KC_TAB,          KC_W,    KC_L,    KC_Y,    KC_P,    KC_B,                                                                    KC_Z,     KC_F,      KC_O,    KC_U,    KC_SCLN, KC_MINS,
     LGUI_T(KC_ESC),  KC_C,    KC_R,    KC_S,    KC_T,    KC_G,                                                                    KC_M,     KC_N,      KC_E,    KC_I,    KC_A,    KC_QUOT,
     KC_LSFT,         KC_Q,    KC_J,    KC_V,    KC_D,    KC_K,    XXXXXXX,                                      XXXXXXX,          KC_X,     KC_H,      KC_COMM, KC_DOT,  KC_SLSH, KC_END,
                                                 XXXXXXX, KC_LALT, KC_SPC, KC_LCTL,        LT(_MACSYM, KC_ENT),  LSFT_T(KC_BSPC),  KC_LALT, XXXXXXX
    ),
    [_MACSYM] = LAYOUT(
     KC_GRV,  KC_EXLM, KC_AMPR, KC_LCBR, KC_RCBR, KC_CIRC,                                             G(S(KC_4)),   KC_7,   KC_8, KC_9, KC_COLN, KC_DEL,
     KC_HASH, KC_EQL,  KC_DLR,  KC_LPRN, KC_RPRN, KC_TILD,                                             C(KC_UP),        KC_4,   KC_5, KC_6, KC_PLUS, KC_ASTR,
     KC_PIPE, KC_AT,   KC_PERC, KC_LBRC, KC_RBRC, KC_UP,   XXXXXXX,                           XXXXXXX, KC_0,         KC_1,   KC_2, KC_3, KC_BSLS, KC_HOME,
                                         XXXXXXX, KC_LEFT, KC_DOWN,   KC_RGHT,      KC_NO,    KC_NO,   KC_NO,        XXXXXXX
    ),
    [_INT] = LAYOUT(
     KC_NO, KC_NO,      KC_NO, KC_NO,      KC_NO, KC_NO,                                            KC_NO,   KC_NO,   RALT(KC_P), RALT(KC_Y), KC_NO,      KC_NO,
     KC_NO, KC_NO,      KC_NO, RALT(KC_S), KC_NO, KC_NO,                                            KC_NO,   KC_NO,   RALT(KC_5), KC_NO,      RALT(KC_Q), KC_NO,
     KC_NO, KC_NO,      KC_NO, KC_NO,      KC_NO, KC_NO, KC_NO,                            KC_NO,   KC_NO,   KC_NO,   KC_F2,      KC_NO,      KC_NO,      KC_NO,
                                                  KC_NO, KC_NO, KC_NO,   KC_NO,    KC_NO , KC_LSFT, KC_NO,   KC_NO
    ),
    [_TEMPLATE] = LAYOUT(
     KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,                                         KC_NO,   KC_NO,   KC_NO, KC_NO, KC_NO, KC_NO,
     KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,                                         KC_NO,   KC_NO,   KC_NO, KC_NO, KC_NO, KC_NO,
     KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,                           KC_NO, KC_NO,   KC_NO,   KC_NO, KC_NO, KC_NO, KC_NO,
                                KC_NO, KC_NO, KC_NO, KC_NO,              KC_NO, KC_NO, KC_NO,   KC_NO
    ),
};

void keyboard_pre_init_user(void) {
    setPinOutput(LED_PIN);
}

bool my_led_on(void) {
    return readPin(LED_PIN) > 0;
}

void my_activate_led(void) {
    if (!my_led_on()) {
        writePinHigh(LED_PIN);
    }
}

void my_deactivate_led(void) {
    if (my_led_on()) {
        writePinLow(LED_PIN);
    }
}

bool process_detected_host_os_kb(os_variant_t detected_os) {
    if (!process_detected_host_os_user(detected_os)) {
        return false;
    }

    switch (detected_os) {
        case OS_MACOS:
        case OS_IOS:
            default_layer_set(1 << _MAC);
            my_activate_led();
            break;
        case OS_LINUX:
        case OS_UNSURE:
        case OS_WINDOWS:
            default_layer_set(1 << _WIN);
            my_deactivate_led();
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
