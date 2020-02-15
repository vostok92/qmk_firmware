#include QMK_KEYBOARD_H
#include "version.h"
#include "keymap_jp.h" // keymap for JP106-layout (Japanese Standard)

#define BASE 0 // default layer
#define SYMB 1 // symbols
#define MDIA 2 // media keys
#define BASEJP 3// default layer for US ASCII
#define SYMBJP 4// symbols for US ASCII
#define MDIAJP 5// media keys for US ASCII

enum custom_keycodes {
  EPRM = SAFE_RANGE,
  VRSN,
  RGB_SLD
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
/* Keymap 0: Basic layer for US ASCII - Mac
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * | ESC    |   1  |   2  |   3  |   4  |   5  |  6   |           |   5  |   6  |   7  |   8  |   9  |   0  |   -    |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * | Tab    |   Q  |   W  |   E  |   R  |   T  |  `   |           |  \   |   Y  |   U  |   I  |   O  |   P  |   =    |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * | LCTL   |   A  |   S  |   D  |   F  |   G  |------|           |------|   H  |   J  |   K  |   L  |; / L2|' / Cmd |
 * |--------+------+------+------+------+------|  [   |           |   ]  |------+------+------+------+------+--------|
 * | LShift |   Z  |   X  |   C  |   V  |   B  |      |           |      |   N  |   M  |   ,  |   .  |   /  | RShift |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |DFL3  |      |      | LAlt | LGui |                                       | RGui | RAlt |      |      |      |
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        | LAlt |      |       |      | RAlt   |
 *                                 ,------|------|------|       |------+--------+------.
 *                                 |      |      |      |       |      |        |      |
 *                                 |Space/| del/ |------|       |------|  Enter |Space/|
 *                                 | Shift| Ctl  | LGui |       | RGui |        | L1   |
 *                                 `--------------------'       `----------------------'
 */
[BASE] = LAYOUT_ergodox(
  // left hand
  KC_ESC,          KC_1,         KC_2,         KC_3,    KC_4,    KC_5,    KC_6,
  KC_TAB,          KC_Q,         KC_W,         KC_E,    KC_R,    KC_T,    KC_GRV,
  KC_LCTL,         KC_A,         KC_S,         KC_D,    KC_F,    KC_G,
  KC_LSFT,         KC_Z,         KC_X,         KC_C,    KC_V,    KC_B,    KC_LBRC,
  DF(BASEJP),      KC_NO,        KC_NO,        KC_LALT, KC_LGUI,
                                                           KC_LALT,       KC_NO,
                                                                          KC_NO,
                                                          SFT_T(KC_SPC),  CTL_T(KC_BSPC), KC_LGUI,
  // right hand
  KC_5,         KC_6,    KC_7,    KC_8,    KC_9,              KC_0,           KC_MINS,
  KC_BSLS,      KC_Y,    KC_U,    KC_I,    KC_O,              KC_P,           KC_EQL,
  KC_H,         KC_J,    KC_K,    KC_L,    LT(MDIA, KC_SCLN), GUI_T(KC_QUOT),
  KC_RBRC,      KC_N,    KC_M,    KC_COMM, KC_DOT,            KC_SLSH,        KC_RSFT,
  KC_RGUI,      KC_RALT, KC_NO,   KC_NO,   KC_NO,
  KC_NO,   KC_RALT,
  KC_NO,
  KC_RGUI, KC_ENT, LT(SYMB,KC_SPC)
),
/* Keymap 1: Symbol Layer for US ASCII
 *
 * ,---------------------------------------------------.           ,--------------------------------------------------.
 * |         |  F1  |  F2  |  F3  |  F4  |  F5  | Vrsn |           |RESET |  F6  |  F7  |  F8  |  F9  |  F10 |   F11  |
 * |---------+------+------+------+------+------+------|           |------+------+------+------+------+------+--------|
 * |         |   1  |   2  |   3  |   4  |   5  |      |           |      |   6  |   7  |   8  |   9  |   0  |   F12  |
 * |---------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |         |   #  |   $  |   (  |  ESC |  TAB |------|           |------|  <-  |  Dn  |  Up  |  ->  |   =  |   -    |
 * |---------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |         |   %  |   ^  |   [  |   `  |   [  |      |           |      |   ]  |   \  |   2  |   3  |   \  |        |
 * `---------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   | EPRM  |      |      |      |      |                                       |      |    . |   0  |   =  |      |
 *   `-----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        |      |      |       |      |      |
 *                                 ,------|------|------|       |------+------+------.
 *                                 |      |      |      |       |      |      |      |
 *                                 |      |      |------|       |------|      |      |
 *                                 |      |      |      |       |      |      |      |
 *                                 `--------------------'       `--------------------'
 */
[SYMB] = LAYOUT_ergodox(
  // left hand
  KC_TRNS, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   VRSN,
  KC_TRNS, KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_TRNS,
  KC_TRNS, KC_HASH, KC_DLR,  KC_LPRN, KC_ESC,  KC_TAB,
  KC_TRNS, KC_PERC, KC_CIRC, KC_LBRC, KC_GRV,  KC_LBRC, KC_TRNS,
  EPRM,    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
                                               KC_TRNS, KC_TRNS,
                                                        KC_TRNS,
                                      KC_TRNS, KC_TRNS, KC_TRNS,
  // right hand
  RESET,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,
  KC_TRNS, KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_F12,
  KC_LEFT, KC_DOWN, KC_UP,   KC_RIGHT,KC_EQL,  KC_MINS,
  KC_TRNS, KC_RBRC, KC_BSLS, KC_2,    KC_3,    KC_BSLS, KC_TRNS,
  KC_TRNS, KC_DOT,  KC_0,    KC_EQL,  KC_TRNS,
  KC_TRNS, KC_TRNS,
  KC_TRNS,
  KC_TRNS, KC_TRNS, KC_TRNS
),
/* Keymap 2: Media and mouse keys for US ASCII
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |        |      |      |      |      |      |      |           |      |      |      |      |      |      |        |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * |        |      |      | MsUp |MsWhUp|      |      |           |      |      |      |      |      |      |        |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |MsWhL |MsLeft|MsDown|MsRght|MsWhR |------|           |------|      |      |      |      |      |  Play  |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |      |      |      |MsWhDn|      |      |           |      |      |      | Prev | Next |      |        |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |      |      |      |      |      |                                       |VolUp |VolDn | Mute |      |      |
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        |      |      |       |      |      |
 *                                 ,------|------|------|       |------+------+------.
 *                                 |      |      |      |       |      |      |Brwser|
 *                                 | Lclk | Rclk |------|       |------|      |Back  |
 *                                 |      |      |      |       |      |      |      |
 *                                 `--------------------'       `--------------------'
 */
[MDIA] = LAYOUT_ergodox(
  // left hand
  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
  KC_TRNS, KC_TRNS, KC_TRNS, KC_MS_U, KC_WH_U, KC_TRNS, KC_TRNS,
  KC_TRNS, KC_WH_L, KC_MS_L, KC_MS_D, KC_MS_R, KC_WH_R,
  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_WH_D, KC_TRNS, KC_TRNS,
  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
                                               KC_TRNS, KC_TRNS,
                                                        KC_TRNS,
                                      KC_BTN1, KC_BTN2, KC_TRNS,
  // right hand
  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
           KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_MPLY,
  KC_TRNS, KC_TRNS, KC_TRNS, KC_MPRV, KC_MNXT, KC_TRNS, KC_TRNS,
                    KC_VOLU, KC_VOLD, KC_MUTE, KC_TRNS, KC_TRNS,
  KC_TRNS, KC_TRNS,
  KC_TRNS,
  KC_TRNS, KC_TRNS, KC_WBAK
),
/* Keymap 3: Basic layer for Japanese Windows
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * | ESC    |   1  |   2  |   3  |   4  |   5  | PSCR |           | Pause|   6  |   7  |   8  |   9  |   0  |   -    |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * | Tab    |   Q  |   W  |   E  |   R  |   T  |  ^   |           | Yen  |   Y  |   U  |   I  |   O  |   P  |   @    |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * | LCTL   |   A  |   S  |   D  |   F  |   G  |------|           |------|   H  |   J  |   K  |   L  |; / L5|: / Cmd |
 * |--------+------+------+------+------+------|  [   |           |   ]  |------+------+------+------+------+--------|
 * | LShift |   Z  |   X  |   C  |   V  |   B  |      |           |      |   N  |   M  |   ,  |   .  |   /  |   \    |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   | DFL0 | LAlt | KANA |  [   | MHEN |                                       | HENK |   ]  |   ^  |  Yen | ~L1  |
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        | LGui | PUp  |       | Home | End  |
 *                                 ,------|------|------|       |------+--------+------.
 *                                 |      |      | PDn  |       | Ins  |        |      |
 *                                 |Space/| BS/  |------|       |------|  Enter |Space/|
 *                                 | Shift| Ctl  |ZH/Alt|       | Del  |        | L4   |
 *                                 `--------------------'       `----------------------'
 */
[BASEJP] = LAYOUT_ergodox(
  // left hand
  KC_ESC,            KC_1,      KC_2,          KC_3,    KC_4,    KC_5,    KC_PSCR,
  KC_TAB,            KC_Q,      KC_W,          KC_E,    KC_R,    KC_T,    JP_CIRC,
  KC_LCTL,           KC_A,      KC_S,          KC_D,    KC_F,    KC_G,
  KC_LSFT,           KC_Z,      KC_X,          KC_C,    KC_V,    KC_B,    JP_LBRC,
  DF(BASE),          KC_LALT,   JP_KANA,       JP_LBRC, JP_MHEN,
                                                           KC_LGUI,       KC_PGUP,
                                                                          KC_PGDN,
                                               SFT_T(KC_SPC),  CTL_T(KC_BSPC), ALT_T(JP_ZHTG),
  // right hand
  KC_PAUS,      KC_6,    KC_7,    KC_8,    KC_9,              KC_0,           JP_MINS,
  JP_YEN,       KC_Y,    KC_U,    KC_I,    KC_O,              KC_P,           JP_AT,
  KC_H,         KC_J,    KC_K,    KC_L,    LT(MDIAJP, JP_SCLN),GUI_T(JP_COLN),
  JP_RBRC,      KC_N,    KC_M,    KC_COMM, KC_DOT,            JP_SLSH,        JP_BSLS,
  JP_HENK,      JP_RBRC, JP_CIRC, JP_YEN,  TT(SYMBJP),
  KC_HOME, KC_END,
  KC_INS,
  KC_DEL,  KC_ENT, LT(SYMBJP,KC_SPC)
),
/* Keymap 4: Symbol Layer for Japanese Windows
 *
 * ,---------------------------------------------------.           ,--------------------------------------------------.
 * |         |  F1  |  F2  |  F3  |  F4  |  F5  | Vrsn |           |RESET |  F6  |  F7  |  F8  |  F9  |  F10 |   F11  |
 * |---------+------+------+------+------+------+------|           |------+------+------+------+------+------+--------|
 * |         |   1  |   2  |   3  |   4  |   5  |      |           |      |   6  |   7  |   8  |   9  |   0  |   F12  |
 * |---------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |         |   #  |   $  |   (  |   )  |   `  |------|           |------|  <-  |  Dn  |  Up  |  ->  |   +  |        |
 * |---------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |         |   %  |   ^  |   [  |   ^  |   [  |      |           |      |   ]  |  Yen |   2  |   3  |   \  |        |
 * `---------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   | EPRM  |      |      |      |      |                                       |      |    . |   0  |   =  |      |
 *   `-----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        |      |      |       |      |      |
 *                                 ,------|------|------|       |------+------+------.
 *                                 |      |      |      |       |      |      |      |
 *                                 |      |      |------|       |------|      |      |
 *                                 |      |      |      |       |      |      |      |
 *                                 `--------------------'       `--------------------'
 */
[SYMBJP] = LAYOUT_ergodox(
  // left hand
  KC_TRNS, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   VRSN,
  KC_TRNS, KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_TRNS,
  KC_TRNS, JP_HASH, JP_DLR,  JP_LPRN, JP_RPRN, JP_GRV,
  KC_TRNS, JP_PERC, JP_CIRC, JP_LBRC, JP_CIRC, JP_LBRC, KC_TRNS,
  EPRM,    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
                                               KC_TRNS, KC_TRNS,
                                                        KC_TRNS,
                                      KC_TRNS, KC_TRNS, KC_TRNS,
  // right hand
  RESET,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,   KC_F11,
  KC_TRNS, KC_6,    KC_7,    KC_8,    KC_9,    KC_0,     KC_F12,
  KC_LEFT, KC_DOWN, KC_UP,   KC_RIGHT,JP_PLUS, KC_TRNS,
  KC_TRNS, JP_RBRC, JP_YEN,  KC_2,    KC_3,    JP_BSLS, KC_TRNS,
  KC_TRNS, KC_DOT,  KC_0,    JP_EQL,  KC_TRNS,
  KC_TRNS, KC_TRNS,
  KC_TRNS,
  KC_TRNS, KC_TRNS, KC_TRNS
),
/* Keymap 5: Media and mouse keys for Japanese Windows
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |        |      |      |      |      |      |      |           |      |      |      |      |      |      |        |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * |        |      |      | MsUp |MsWhUp|      |      |           |      |      |      |      |      |      |        |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |MsWhL |MsLeft|MsDown|MsRght|MsWhR |------|           |------|      |      |      |      |      |  Play  |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |      |      |      |MsWhDn|      |      |           |      |      |      | Prev | Next |      |        |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |      |      |      |      |      |                                       |VolUp |VolDn | Mute |      |      |
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        |      |      |       |      |      |
 *                                 ,------|------|------|       |------+------+------.
 *                                 |      |      |      |       |      |      |Brwser|
 *                                 | Lclk | Rclk |------|       |------|      |Back  |
 *                                 |      |      |      |       |      |      |      |
 *                                 `--------------------'       `--------------------'
 */
[MDIAJP] = LAYOUT_ergodox(
  // left hand
  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
  KC_TRNS, KC_TRNS, KC_TRNS, KC_MS_U, KC_WH_U, KC_TRNS, KC_TRNS,
  KC_TRNS, KC_WH_L, KC_MS_L, KC_MS_D, KC_MS_R, KC_WH_R,
  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_WH_D, KC_TRNS, KC_TRNS,
  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
                                               KC_TRNS, KC_TRNS,
                                                        KC_TRNS,
                                      KC_BTN1, KC_BTN2, KC_TRNS,
  // right hand
  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
           KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_MPLY,
  KC_TRNS, KC_TRNS, KC_TRNS, KC_MPRV, KC_MNXT, KC_TRNS, KC_TRNS,
                    KC_VOLU, KC_VOLD, KC_MUTE, KC_TRNS, KC_TRNS,
  KC_TRNS, KC_TRNS,
  KC_TRNS,
  KC_TRNS, KC_TRNS, KC_WBAK
),
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  if (record->event.pressed) {
    switch (keycode) {
      case EPRM:
        eeconfig_init();
        return false;
      case VRSN:
        SEND_STRING (QMK_KEYBOARD "/" QMK_KEYMAP " @ " QMK_VERSION);
        return false;
      #ifdef RGBLIGHT_ENABLE
      case RGB_SLD:
        rgblight_mode(1);
        return false;
      #endif
    }
  }
  return true;
}

// Runs just one time when the keyboard initializes.
void matrix_init_user(void) {
#ifdef RGBLIGHT_COLOR_LAYER_0
  rgblight_setrgb(RGBLIGHT_COLOR_LAYER_0);
#endif
};

// Runs whenever there is a layer state change.
uint32_t layer_state_set_user(uint32_t state) {
  ergodox_board_led_off();
  ergodox_right_led_1_off();
  ergodox_right_led_2_off();
  ergodox_right_led_3_off();

  uint8_t layer = biton32(state);
  switch (layer) {
      case 0:
        #ifdef RGBLIGHT_COLOR_LAYER_0
          rgblight_setrgb(RGBLIGHT_COLOR_LAYER_0);
        #else
        #ifdef RGBLIGHT_ENABLE
          rgblight_init();
        #endif
        #endif
        break;
      case 1:
        ergodox_right_led_1_on();
        #ifdef RGBLIGHT_COLOR_LAYER_1
          rgblight_setrgb(RGBLIGHT_COLOR_LAYER_1);
        #endif
        break;
      case 2:
        ergodox_right_led_2_on();
        #ifdef RGBLIGHT_COLOR_LAYER_2
          rgblight_setrgb(RGBLIGHT_COLOR_LAYER_2);
        #endif
        break;
      case 3:
        ergodox_right_led_3_on();
        #ifdef RGBLIGHT_COLOR_LAYER_3
          rgblight_setrgb(RGBLIGHT_COLOR_LAYER_3);
        #endif
        break;
      case 4:
        ergodox_right_led_1_on();
        ergodox_right_led_2_on();
        #ifdef RGBLIGHT_COLOR_LAYER_4
          rgblight_setrgb(RGBLIGHT_COLOR_LAYER_4);
        #endif
        break;
      case 5:
        ergodox_right_led_1_on();
        ergodox_right_led_3_on();
        #ifdef RGBLIGHT_COLOR_LAYER_5
          rgblight_setrgb(RGBLIGHT_COLOR_LAYER_5);
        #endif
        break;
      case 6:
        ergodox_right_led_2_on();
        ergodox_right_led_3_on();
        #ifdef RGBLIGHT_COLOR_LAYER_6
          rgblight_setrgb(RGBLIGHT_COLOR_LAYER_6);
        #endif
        break;
      case 7:
        ergodox_right_led_1_on();
        ergodox_right_led_2_on();
        ergodox_right_led_3_on();
        #ifdef RGBLIGHT_COLOR_LAYER_7
          rgblight_setrgb(RGBLIGHT_COLOR_LAYER_7);
        #endif
        break;
      default:
        break;
    }

  return state;
};
