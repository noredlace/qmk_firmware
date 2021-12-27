/* Copyright 2020 Worldspawn <mcmancuso@gmail.com>
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#include QMK_KEYBOARD_H

enum cajal_layers {
  _QWERTY,
  _LOWER,
  _RAISE,
  _FUNCTION,
  _ADJUST
};

enum cajal_keycodes {
  QWERTY = SAFE_RANGE,
  LOWER,
  RAISE,
  FUNCTION,
};

#define KC_CTLTB CTL_T(KC_TAB)
#define MODS_CTRL_MASK  (MOD_BIT(KC_LSHIFT)|MOD_BIT(KC_RSHIFT))

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {


    [_QWERTY] = LAYOUT_ortho(
  KC_ESC,   KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_BSPC, KC_PGUP, KC_TRNS,
  KC_CTLTB,   KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT, KC_PGDN,
	KC_LSFT,  KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, RSFT_T(KC_ENT), KC_UP,
  FUNCTION, KC_LCTL, KC_LGUI, KC_LALT,LOWER,   KC_SPC,  KC_ENT,   RAISE, KC_RALT, KC_RCTL, KC_DEL,   KC_LEFT, KC_DOWN,  KC_RGHT),

	[_RAISE] = LAYOUT_ortho(
  KC_ESC,    KC_EXLM, KC_AT,   KC_HASH, KC_DLR,   KC_PERC,   KC_CIRC,  KC_AMPR,  KC_ASTR,   KC_LPRN,   KC_RPRN,  KC_BSPC, KC_PGUP, KC_TRNS,
  KC_CTLTB,  KC_TRNS, KC_MINS, KC_EQL,  KC_LCBR,  KC_RCBR,   KC_LEFT,  KC_DOWN,  KC_UP,     KC_RIGHT,  KC_PIPE,  KC_GRV, KC_TRNS,
  KC_LSFT,   KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,  KC_TRNS,   KC_UNDS,  KC_PLUS,  KC_LBRC,   KC_RBRC,   KC_BSLS,  KC_TILD, KC_AUDIO_VOL_UP,
  _______,   _______, _______, _______, LOWER,    KC_SPC,    KC_ENT,   _______,  _______,   _______,   _______,  KC_MNXT,   KC_AUDIO_VOL_DOWN,  KC_MPLY),

	[_LOWER] = LAYOUT_ortho(
  KC_ESC,   KC_1 ,   KC_2,    KC_3,   KC_4,   KC_5,   KC_6,   KC_7,  KC_8,   KC_9,    KC_0,     KC_BSPC, KC_PGUP, KC_TRNS,
  KC_CTLTB, KC_F1,   KC_F2,   KC_F3,  KC_F4,  KC_F5,  KC_F6,  KC_4,  KC_5,   KC_6,    KC_SCLN,  KC_QUOT, KC_TRNS,
  KC_LSFT,  KC_F7,   KC_F8,   KC_F9,  KC_F10, KC_F11, KC_F12, KC_1,  KC_2,   KC_3,    KC_SLSH,  KC_RSFT, KC_PGUP,
  KC_PSCR, _______, _______, _______, _______, KC_SPC, KC_ENT, RAISE, KC_RALT, KC_RCTL, KC_DEL, KC_MNXT, KC_PGDN, KC_MPLY),

	[_FUNCTION] = LAYOUT_ortho(
  KC_F21,  KC_F23,  KC_F19,  _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______, _______, _______,
  KC_F22,  KC_F24,  KC_F20,  _______,   _______,   _______,   _______,   _______,    _______,    _______,    _______, _______, _______,
  KC_F15,  KC_F16,  _______, _______,   _______,  _______,  _______,  _______,    _______,    _______,    _______, _______, _______,
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______),

	[_ADJUST] = LAYOUT_ortho(
  _______, RESET,   DEBUG,   _______, _______, _______, _______, TERM_ON, TERM_OFF,_______, _______, KC_DEL , _______, _______,
  RGB_TOG, RGB_MOD, MU_MOD,  AU_ON,   AU_OFF,  AG_NORM, AG_SWAP, _______,  _______, _______,  _______,  _______, _______,
  KC_CAPS, MUV_DE,  MUV_IN,  MU_ON,   MU_OFF,  MI_ON,   MI_OFF,  _______, _______, _______, _______, _______,  _______,
  _______, _______, _______, _______, _______, KC_SPC, KC_ENT, _______, _______, _______, _______, _______, _______, _______),
};


layer_state_t layer_state_set_user(layer_state_t state) {
    writePinLow(B7);
    writePinLow(B6);
    switch (get_highest_layer(state)) {
    case 1:
        writePinHigh(B7);
        break;
    case 2:
        writePinHigh(B6);
        break;
    case 3:
        writePinHigh(B7);
        writePinHigh(B6);
        break;
    }
    return state;
}

bool led_update_user(led_t led_state) {
    writePin(B5, led_state.caps_lock);
    return false;
}

bool encoder_update_user(uint8_t index, bool clockwise) {
    if (index == 0) {
        if (clockwise) {
            tap_code(KC_VOLD);
        } else {
            tap_code(KC_VOLU);
        }
    }
    return true;
}


bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case QWERTY:
      if (record->event.pressed) {
        print("mode just switched to qwerty and this is a huge string\n");
        set_single_persistent_default_layer(_QWERTY);
      }
      return false;
      break;
    case LOWER:
      if (record->event.pressed) {
        layer_on(_LOWER);
        #ifdef BACKLIGHT_ENABLE
        #endif
        update_tri_layer(_LOWER, _RAISE, _ADJUST);
      } else {
        layer_off(_LOWER);
        update_tri_layer(_LOWER, _RAISE, _ADJUST);
      }
      return false;
      break;
    case RAISE:
      if (record->event.pressed) {
        layer_on(_RAISE);
        update_tri_layer(_LOWER, _RAISE, _ADJUST);
      } else {
        layer_off(_RAISE);
        update_tri_layer(_LOWER, _RAISE, _ADJUST);
      }
      return false;
      break;

	case FUNCTION:
      if (record->event.pressed) {
        layer_on(_FUNCTION);
      } else {
        layer_off(_FUNCTION);
      }
      return false;
      break;

  }
  return true;
}
