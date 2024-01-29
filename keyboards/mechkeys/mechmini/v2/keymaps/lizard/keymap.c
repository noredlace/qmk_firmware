#include QMK_KEYBOARD_H



enum mm2_layers {
  _QWERTY,
  _LOWER,
  _RAISE,
  _FUNCTION,
  _ADJUST
};

enum mm2_keycodes {
  QWERTY = SAFE_RANGE,
  LOWER,
  RAISE,
  FUNCTION,
};

#define KC_CTLTB CTL_T(KC_TAB)
#define MODS_CTRL_MASK  (MOD_BIT(KC_LSFT)|MOD_BIT(KC_RSFT))
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

[_QWERTY] = LAYOUT_ortho(
  KC_ESC,   KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_BSPC,
  KC_CTLTB,   KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,
	KC_LSFT,  KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, RSFT_T(KC_ENT),
  FUNCTION, KC_LCTL, KC_LGUI, KC_LALT,LOWER,   KC_SPC,  KC_ENT,   RAISE,   KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT),

[_RAISE] = LAYOUT_ortho(
  KC_ESC,    KC_EXLM, KC_AT,   KC_HASH, KC_DLR,   KC_PERC,   KC_CIRC,  KC_AMPR,  KC_ASTR,   KC_LPRN,   KC_RPRN,  KC_BSPC,
  KC_CTLTB,  KC_HOME, KC_MINS, KC_EQL,  KC_LCBR,  KC_RCBR,   KC_LEFT,  KC_DOWN,  KC_UP,     KC_RIGHT,  KC_PIPE,  KC_GRV,
  KC_LSFT,   KC_END, KC_TRNS, KC_TRNS, KC_TRNS,  KC_TRNS,   KC_UNDS,  KC_PLUS,  KC_LBRC,   KC_RBRC,   KC_BSLS,  KC_TILD,
  KC_TRNS,   KC_TRNS, KC_TRNS, KC_TRNS, LOWER,    KC_SPC,    KC_ENT,   KC_TRNS,  KC_MNXT,   KC_AUDIO_VOL_DOWN,   KC_AUDIO_VOL_UP,  KC_MPLY),

[_LOWER] = LAYOUT_ortho(
  KC_ESC,   KC_1 ,   KC_2,    KC_3,   KC_4,   KC_5,   KC_6,   KC_7,  KC_8,   KC_9,    KC_0,     KC_BSPC,
  KC_CTLTB, KC_F1,   KC_F2,   KC_F3,  KC_F4,  KC_F5,  KC_F6,  KC_4,  KC_5,   KC_6,    KC_SCLN,  KC_QUOT,
  KC_LSFT,  KC_F7,   KC_F8,   KC_F9,  KC_F10, KC_F11, KC_F12, KC_1,  KC_2,   KC_3,    KC_SLSH,  KC_RSFT,
  KC_PSCR, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_SPC, KC_ENT, RAISE, KC_MNXT, KC_PGDN, KC_PGUP, KC_MPLY),

[_FUNCTION] = LAYOUT_ortho(
  KC_F21,  KC_F23,  KC_F19,  KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,
  KC_F22,  KC_F24,  KC_F20,  KC_TRNS,   KC_TRNS,   KC_TRNS,   KC_TRNS,   KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS, KC_TRNS,
  KC_F15,  KC_F16,  KC_TRNS, KC_TRNS,   KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_F, KC_TRNS,
  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS),

[_ADJUST] = LAYOUT_ortho(
  KC_TRNS, QK_BOOT,   KC_TRNS,   KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,KC_TRNS, KC_TRNS, KC_DEL ,
  RGB_TOG, RGB_HUI, RGB_SAI,  RGB_VAI,   KC_TRNS,  KC_TRNS, KC_TRNS, KC_TRNS,  KC_TRNS, KC_TRNS,  KC_TRNS,  KC_TRNS,
  RGB_MOD, RGB_HUD,  RGB_SAD,  RGB_VAD,   KC_TRNS,  KC_TRNS,   KC_TRNS,  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_A,
  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_SPC, KC_ENT, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS),


};

void matrix_init_user(void) {
}

void matrix_scan_user(void) {
}

/*
void led_set_user(uint8_t usb_led) {

	if (usb_led & (1 << USB_LED_NUM_LOCK)) {

	} else {

	}

	if (usb_led & (1 << USB_LED_CAPS_LOCK)) {

	} else {

	}

	if (usb_led & (1 << USB_LED_SCROLL_LOCK)) {

	} else {

	}

	if (usb_led & (1 << USB_LED_COMPOSE)) {

	} else {

	}

	if (usb_led & (1 << USB_LED_KANA)) {

	} else {

	}


}
*/

enum function_id {
    SHIFT_ESC,
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
          //breathing_period_set(2);
          //breathing_pulse();
        #endif
        //update_quad_layer(_LOWER, _RAISE, _FUNCTION, _ADJUST);
        update_tri_layer(_LOWER, _RAISE, _ADJUST);
      } else {
        layer_off(_LOWER);
        //update_quad_layer(_LOWER, _RAISE, _FUNCTION, _ADJUST);
        update_tri_layer(_LOWER, _RAISE, _ADJUST);
      }
      return false;
      break;
    case RAISE:
      if (record->event.pressed) {
        layer_on(_RAISE);
        //breathing_period_set(2);
        //breathing_pulse();
		//update_quad_layer(_LOWER, _RAISE, _FUNCTION, _ADJUST);
        update_tri_layer(_LOWER, _RAISE, _ADJUST);
      } else {
        layer_off(_RAISE);
        //update_quad_layer(_LOWER, _RAISE, _FUNCTION, _ADJUST);
        update_tri_layer(_LOWER, _RAISE, _ADJUST);
      }
      return false;
      break;

	case FUNCTION:
      if (record->event.pressed) {
        layer_on(_FUNCTION);
        //breathing_period_set(2);
        //breathing_pulse();
        //update_tri_layer(_LOWER, _RAISE, _ADJUST);
		//update_quad_layer(_LOWER, _RAISE, _FUNCTION, _ADJUST);
        //update_tri_layer(_LOWER, _RAISE, _ADJUST);
      } else {
        layer_off(_FUNCTION);
        //update_tri_layer(_LOWER, _RAISE, _ADJUST);
		//update_quad_layer(_LOWER, _RAISE, _FUNCTION, _ADJUST);
        //update_tri_layer(_LOWER, _RAISE, _ADJUST);
      }
      return false;
      break;

  }
  return true;
}
