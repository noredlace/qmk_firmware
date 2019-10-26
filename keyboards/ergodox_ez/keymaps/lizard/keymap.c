#include QMK_KEYBOARD_H
#include "version.h"

/*
#define _QWERTY 0 // default layer
#define _RAISE 1 // symbols
#define _LOWER 2 // media keys
#define _FUNCTION 3 // media keys
#define _ADJUST 4 // media keys
*/

#define KC_CTLTB CTL_T(KC_TAB)
#define MODS_CTRL_MASK  (MOD_BIT(KC_LSHIFT)|MOD_BIT(KC_RSHIFT))

enum ergo_layers {
  _QWERTY,
  _LOWER,
  _RAISE,
  _FUNCTION,
  _ADJUST
};

enum ergo_keycodes {
  QWERTY = SAFE_RANGE,
  LOWER,
  RAISE,
  FUNCTION,
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
/* Keymap 0: Basic layer
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |   =    |   1  |   2  |   3  |   4  |   5  | LEFT |           | RIGHT|   6  |   7  |   8  |   9  |   0  |   -    |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * | Del    |   Q  |   W  |   E  |   R  |   T  |  L1  |           |  L1  |   Y  |   U  |   I  |   O  |   P  |   \    |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * | BkSp   |   A  |   S  |   D  |   F  |   G  |------|           |------|   H  |   J  |   K  |   L  |; / L2|' / Cmd |
 * |--------+------+------+------+------+------| Hyper|           | Meh  |------+------+------+------+------+--------|
 * | LShift |Z/Ctrl|   X  |   C  |   V  |   B  |      |           |      |   N  |   M  |   ,  |   .  |//Ctrl| RShift |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |Grv/L1|  '"  |AltShf| Left | Right|                                       |  Up  | Down |   [  |   ]  | ~L1  |
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        | App  | LGui |       | Alt  |Ctrl/Esc|
 *                                 ,------|------|------|       |------+--------+------.
 *                                 |      |      | Home |       | PgUp |        |      |
 *                                 | Space|Backsp|------|       |------|  Tab   |Enter |
 *                                 |      |ace   | End  |       | PgDn |        |      |
 *                                 `--------------------'       `----------------------'
 */
[_QWERTY] = LAYOUT_ergodox(
  // left hand
  KC_ESC,   KC_1,     KC_2,    KC_3,    KC_4,    KC_5,    KC_TRNS,
  KC_TAB,   KC_Q,     KC_W,    KC_E,    KC_R,    KC_T,    KC_TRNS,
  KC_LCTL,  KC_A,     KC_S,    KC_D,    KC_F,    KC_G,
  KC_LSFT,  KC_Z,     KC_X,    KC_C,    KC_V,    KC_B,    KC_TRNS,
  FUNCTION, KC_LCTL,  KC_LGUI, KC_LALT, LOWER,
                                                         KC_TRNS, KC_LGUI,
                                                                  KC_HOME,
                                                  KC_SPC,KC_SPC,  KC_END,
  // right hand
  KC_TRNS,      KC_6,    KC_7,    KC_8,    KC_9,              KC_0,           KC_BSPC,
  KC_TRNS,     KC_Y,    KC_U,    KC_I,    KC_O,              KC_P,           KC_PIPE,
  KC_H,         KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,
  KC_TRNS, KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, RSFT_T(KC_ENT),
  RAISE,   KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT,
  KC_TRNS, CTL_T(KC_ESC),
  KC_PGUP,
  KC_PGDN, KC_ENT, KC_ENT
),
/* Keymap 1: Symbol Layer
 *
 * ,---------------------------------------------------.           ,--------------------------------------------------.
 * |Version  |  F1  |  F2  |  F3  |  F4  |  F5  |      |           |      |  F6  |  F7  |  F8  |  F9  |  F10 |   F11  |
 * |---------+------+------+------+------+------+------|           |------+------+------+------+------+------+--------|
 * |         |   !  |   @  |   {  |   }  |   |  |      |           |      |   Up |   7  |   8  |   9  |   *  |   F12  |
 * |---------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |         |   #  |   $  |   (  |   )  |   `  |------|           |------| Down |   4  |   5  |   6  |   +  |        |
 * |---------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |         |   %  |   ^  |   [  |   ]  |   ~  |      |           |      |   &  |   1  |   2  |   3  |   \  |        |
 * `---------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   | EPRM  |      |      |      |      |                                       |      |    . |   0  |   =  |      |
 *   `-----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        |Animat|      |       |Toggle|Solid |
 *                                 ,------|------|------|       |------+------+------.
 *                                 |Bright|Bright|      |       |      |Hue-  |Hue+  |
 *                                 |ness- |ness+ |------|       |------|      |      |
 *                                 |      |      |      |       |      |      |      |
 *                                 `--------------------'       `--------------------'
 */
[_RAISE] = LAYOUT_ergodox(
  // left hand
  KC_ESC,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_TRNS,
  KC_TAB,  KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC, KC_TRNS,
  KC_LCTL, KC_TRNS, KC_MINS, KC_EQL,  KC_LCBR, KC_RCBR,
  KC_LSFT, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
		   KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, LOWER,
                                               KC_TRNS, KC_TRNS,
                                                        KC_TRNS,
                                      KC_SPC, KC_SPC, KC_TRNS,
  // right hand
  KC_TRNS, KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_BSPC,
  KC_TRNS, KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, KC_PIPE,
  KC_LEFT, KC_DOWN, KC_UP,   KC_RIGHT,KC_PIPE, KC_GRV,
  KC_TRNS, KC_UNDS, KC_PLUS, KC_LBRC, KC_RBRC, KC_BSLS, KC_TILD,
  RAISE,   KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT,
  KC_TRNS, KC_TRNS,
  KC_TRNS,
  KC_TRNS, KC_ENT, KC_ENT
),
/* Keymap 2: Media and mouse keys
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |        |      |      |      |      |      |      |           |      |      |      |      |      |      |        |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * |        |      |      | MsUp |      |      |      |           |      |      |      |      |      |      |        |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |      |MsLeft|MsDown|MsRght|      |------|           |------|      |      |      |      |      |  Play  |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |      |      |      |      |      |      |           |      |      |      | Prev | Next |      |        |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |      |      |      | Lclk | Rclk |                                       |VolUp |VolDn | Mute |      |      |
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        |      |      |       |      |      |
 *                                 ,------|------|------|       |------+------+------.
 *                                 |      |      |      |       |      |      |Brwser|
 *                                 |      |      |------|       |------|      |Back  |
 *                                 |      |      |      |       |      |      |      |
 *                                 `--------------------'       `--------------------'
 */
[_LOWER] = LAYOUT_ergodox(
  // left hand
  KC_ESC,  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,KC_TRNS,
  KC_TAB,  KC_1 ,   KC_2,    KC_3,    KC_4,    KC_5,   KC_TRNS,
  KC_LCTL, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,
  KC_LSFT, KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11, KC_TRNS,
  KC_PSCR, KC_TRNS, KC_TRNS, KC_BTN1, KC_BTN2,
                                               KC_TRNS,KC_TRNS,
                                                       KC_TRNS,
                                      KC_SPC, KC_SPC, KC_TRNS,
  // right hand
  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_BSPC,
  KC_TRNS, KC_6,    KC_7,    KC_8,    KC_9,    KC_0, KC_PIPE,
           KC_F6,  KC_4,  KC_5,   KC_6,    KC_SCLN,  KC_QUOT,
  KC_TRNS, KC_F12, KC_1,  KC_2,   KC_3,    KC_SLSH,  KC_RSFT,
                    RAISE, KC_MNXT, KC_PGDN, KC_PGUP, KC_MPLY,
  KC_TRNS, KC_TRNS,
  KC_TRNS,
  KC_TRNS, KC_ENT, KC_ENT
  ),
  
  /* Keymap 2: Media and mouse keys
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |        |      |      |      |      |      |      |           |      |      |      |      |      |      |        |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * |        |      |      | MsUp |      |      |      |           |      |      |      |      |      |      |        |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |      |MsLeft|MsDown|MsRght|      |------|           |------|      |      |      |      |      |  Play  |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |      |      |      |      |      |      |           |      |      |      | Prev | Next |      |        |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |      |      |      | Lclk | Rclk |                                       |VolUp |VolDn | Mute |      |      |
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        |      |      |       |      |      |
 *                                 ,------|------|------|       |------+------+------.
 *                                 |      |      |      |       |      |      |Brwser|
 *                                 |      |      |------|       |------|      |Back  |
 *                                 |      |      |      |       |      |      |      |
 *                                 `--------------------'       `--------------------'
 */
[_FUNCTION] = LAYOUT_ergodox(
  // left hand
  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
  KC_TRNS, KC_TRNS, KC_TRNS, KC_MS_U, KC_TRNS, KC_TRNS, KC_TRNS,
  KC_TRNS, KC_TRNS, KC_MS_L, KC_MS_D, KC_MS_R, KC_TRNS,
  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
  KC_TRNS, KC_TRNS, KC_TRNS, KC_BTN1, KC_BTN2,
                                               KC_TRNS, KC_TRNS,
                                                        KC_TRNS,
                                      KC_TRNS, KC_TRNS, KC_TRNS,
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
  
  /* Keymap 2: Media and mouse keys
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |        |      |      |      |      |      |      |           |      |      |      |      |      |      |        |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * |        |      |      | MsUp |      |      |      |           |      |      |      |      |      |      |        |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |      |MsLeft|MsDown|MsRght|      |------|           |------|      |      |      |      |      |  Play  |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |      |      |      |      |      |      |           |      |      |      | Prev | Next |      |        |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |      |      |      | Lclk | Rclk |                                       |VolUp |VolDn | Mute |      |      |
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        |      |      |       |      |      |
 *                                 ,------|------|------|       |------+------+------.
 *                                 |      |      |      |       |      |      |Brwser|
 *                                 |      |      |------|       |------|      |Back  |
 *                                 |      |      |      |       |      |      |      |
 *                                 `--------------------'       `--------------------'
 */
[_ADJUST] = LAYOUT_ergodox(
  // left hand
  RESET, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
  KC_TRNS, KC_TRNS, KC_TRNS, KC_MS_U, KC_TRNS, KC_TRNS, KC_TRNS,
  KC_TRNS, KC_TRNS, KC_MS_L, KC_MS_D, KC_MS_R, KC_TRNS,
  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
  KC_TRNS, KC_TRNS, KC_TRNS, KC_BTN1, KC_BTN2,
                                               KC_TRNS, KC_TRNS,
                                                        KC_TRNS,
                                      KC_TRNS, KC_TRNS, KC_TRNS,
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
      switch (keycode) {

        /*
    case MACRO_1:
    if (record->event.pressed) {
    SEND_STRING("cd /mnt/c/Users/EJ/Documents");
    register_code(KC_ENT);
    return false;
    }
    case MACRO_2:
    if (record->event.pressed) {
    //navigate to folder
    SEND_STRING("cd /mnt/c/Users/EJ/Documents/Github/qmk_lizard");
    register_code(KC_ENT);
    unregister_code(KC_ENT);

    //send command to compile
    SEND_STRING("make planck:lizard");
    register_code(KC_ENT);
    unregister_code(KC_ENT);

    return false;
    }
    */


        case QWERTY: if (record->event.pressed) {
            print("mode just switched to qwerty and this is a huge string\n");
            set_single_persistent_default_layer(_QWERTY);
        }

        return false;
        break;

        case LOWER: if (record->event.pressed) {
            layer_on(_LOWER);
            # ifdef BACKLIGHT_ENABLE //breathing_period_set(2);
            //breathing_pulse();
            # endif //update_quad_layer(_LOWER, _RAISE, _FUNCTION, _ADJUST);
            update_tri_layer(_LOWER, _RAISE, _ADJUST);
        }

        else {
            layer_off(_LOWER);
            //update_quad_layer(_LOWER, _RAISE, _FUNCTION, _ADJUST);
            update_tri_layer(_LOWER, _RAISE, _ADJUST);
        }

        return false;
        break;

        case RAISE: if (record->event.pressed) {
            layer_on(_RAISE);
            //breathing_period_set(2);
            //breathing_pulse();
            //update_quad_layer(_LOWER, _RAISE, _FUNCTION, _ADJUST);
            update_tri_layer(_LOWER, _RAISE, _ADJUST);
        }

        else {
            layer_off(_RAISE);
            //update_quad_layer(_LOWER, _RAISE, _FUNCTION, _ADJUST);
            update_tri_layer(_LOWER, _RAISE, _ADJUST);
        }

        return false;
        break;

        case FUNCTION: if (record->event.pressed) {
            layer_on(_FUNCTION);
            //breathing_period_set(2);
            //breathing_pulse();
            //update_tri_layer(_LOWER, _RAISE, _ADJUST);
            //update_quad_layer(_LOWER, _RAISE, _FUNCTION, _ADJUST);
            //update_tri_layer(_LOWER, _RAISE, _ADJUST);
        }

        else {
            layer_off(_FUNCTION);
            //update_tri_layer(_LOWER, _RAISE, _ADJUST);
            //update_quad_layer(_LOWER, _RAISE, _FUNCTION, _ADJUST);
            //update_tri_layer(_LOWER, _RAISE, _ADJUST);
        }

        return false;
        break;

    }

    return true;
  
  
  /*
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
  */
  
  
  
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
