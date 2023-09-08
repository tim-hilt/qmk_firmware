#include QMK_KEYBOARD_H
#include "os_detection.h"

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
     KC_TAB,          KC_Q,    KC_W,    KC_F,    KC_P,    KC_B,                                                                 KC_J,     KC_L,      KC_U,    KC_Y,    KC_SCLN, KC_MINS,
     LCTL_T(KC_ESC),  KC_A,    KC_R,    KC_S,    KC_T,    KC_G,                                                                 KC_M,     KC_N,      KC_E,    KC_I,    KC_O,    MC_QUOT,
     KC_LSFT,         KC_Z,    KC_X,    KC_C,    KC_D,    KC_V,    XXXXXXX,                                      XXXXXXX,       KC_K,     KC_H,      KC_COMM, KC_DOT,  KC_SLSH, KC_END,
                                                 XXXXXXX, KC_LALT, KC_SPC, KC_LGUI,        LT(_WINSYM, KC_ENT),  LSFT_T(KC_BSPC),  MO(_INT), XXXXXXX
    ),
    // More info about persisting the default layer (as opposed to DF) can be found at
    // https://docs.qmk.fm/#/feature_layers?id=switching-and-toggling-layers
    [_WINSYM] = LAYOUT(
     MC_GRV,  KC_EXLM, KC_AMPR, KC_LCBR, KC_RCBR, MC_CIRC,                                             G(S(KC_S)),   KC_7,   KC_8, KC_9, KC_COLN, KC_MINS,
     KC_HASH, KC_EQL,  KC_DLR,  KC_LPRN, KC_RPRN, MC_TILD,                                             DF(_MAC),     KC_4,   KC_5, KC_6, KC_PLUS, KC_ASTR,
     KC_PIPE, KC_AT,   KC_PERC, KC_LBRC, KC_RBRC, KC_UP,   XXXXXXX,                           XXXXXXX, KC_0,         KC_1,   KC_2, KC_3, KC_BSLS, KC_HOME,
                                         XXXXXXX, KC_LEFT, KC_DOWN,   KC_RGHT,      KC_NO,    KC_NO,   KC_NO,        XXXXXXX
    ),
    [_MAC] = LAYOUT(
     KC_TAB,          KC_Q,    KC_W,    KC_F,    KC_P,    KC_B,                                                                    KC_J,     KC_L,      KC_U,    KC_Y,    KC_SCLN, KC_MINS,
     LGUI_T(KC_ESC),  KC_A,    KC_R,    KC_S,    KC_T,    KC_G,                                                                    KC_M,     KC_N,      KC_E,    KC_I,    KC_O,    KC_QUOT,
     KC_LSFT,         KC_Z,    KC_X,    KC_C,    KC_D,    KC_V,    XXXXXXX,                                      XXXXXXX,          KC_K,     KC_H,      KC_COMM, KC_DOT,  KC_SLSH, KC_END,
                                                 XXXXXXX, KC_LALT, KC_SPC, KC_LCTL,        LT(_MACSYM, KC_ENT),  LSFT_T(KC_BSPC),  KC_LALT, XXXXXXX
    ),
    [_MACSYM] = LAYOUT(
     KC_GRV,  KC_EXLM, KC_AMPR, KC_LCBR, KC_RCBR, KC_CIRC,                                             G(S(KC_4)),   KC_7,   KC_8, KC_9, KC_COLN, KC_MINS,
     KC_HASH, KC_EQL,  KC_DLR,  KC_LPRN, KC_RPRN, KC_TILD,                                             DF(_WIN),     KC_4,   KC_5, KC_6, KC_PLUS, KC_ASTR,
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

uint32_t set_default_layer(uint32_t trigger_time, void *cb_arg) {
    os_variant_t host = detected_host_os();

    if (!host) {
        return 500;
    }
    
    if (host == OS_MACOS) {
        default_layer_set(_MAC);
    }

    return 0;
}

void keyboard_post_init_user(void) {
    defer_exec(100, set_default_layer, NULL);
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

void keyboard_pre_init_user(void) {
    setPinOutput(D5);
}

layer_state_t layer_state_set_user(layer_state_t state) {
    pin_t val = readPin(D5);
    switch (get_highest_layer(state | default_layer_state)) {
    case _MAC:
    case _MACSYM:
        if (val <= 1) {
            writePinHigh(D5);
        }
        break;
    default:
        if (val > 0) {
            writePinLow(D5);
        }
        break;
    }
  return state;
}