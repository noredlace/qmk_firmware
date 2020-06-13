#include QMK_KEYBOARD_H
#include <print.h>

enum crawl_layers {
  _QWERTY,
  _VOICEMEETERA1,
  _VOICEMEETERA2,
  _VOICEMEETERAAUX,
  _LOWER,
  _RAISE,
  _FUNCTION,
  _ADJUST
};

enum crawl_keycodes {
  QWERTY = SAFE_RANGE,
  VOICEMEETERA1,
  VOICEMEETERA2,
  VOICEMEETERAAUX,
  LOWER,
  RAISE,
  TEST,
  FUNCTION,
  MACRO_1,
  MACRO_2,
  MACRO_PREV,
  MACRO_PLAY,
  MACRO_NEXT
};


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

	[_QWERTY] = LAYOUT(
    VOICEMEETERA1, VOICEMEETERA2, VOICEMEETERAAUX, KC_F14, RAISE,
    KC_F15, KC_F16, KC_F17, KC_F18, LOWER, KC_ENT),

//state for voice meeter volume adjust
   	[_VOICEMEETERA1] = LAYOUT(
    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_ENT),

    [_VOICEMEETERA2] = LAYOUT(
    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_ENT),

	[_VOICEMEETERAAUX] = LAYOUT(
    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_ENT),

	[_LOWER] = LAYOUT(
    KC_1, KC_2, KC_3, KC_4, KC_TRNS,
    KC_L, KC_TRNS, KC_0, KC_TRNS, KC_TRNS, KC_ENT),

	[_RAISE] = LAYOUT(
    MACRO_PREV, MACRO_PLAY, MACRO_NEXT, KC_4, KC_TRNS,
    KC_R, LOWER, KC_BSPC, KC_TRNS, KC_TRNS, KC_ENT),

	[_ADJUST] = LAYOUT(
    KC_1, KC_2, KC_3, KC_4, KC_TRNS,
    KC_A, KC_TRNS, KC_BSPC, KC_TRNS, KC_TRNS, RESET)
	
};

void matrix_init_user(void) {
  debug_config.matrix = 1;
  debug_config.keyboard = 1;
  debug_config.enable = 1;
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
	switch(keycode){

		case LOWER:
			if (record->event.pressed){
				layer_on(_LOWER);
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
				update_tri_layer(_LOWER, _RAISE, _ADJUST);
			} else {
				layer_off(_RAISE);
				//update_quad_layer(_LOWER, _RAISE, _FUNCTION, _ADJUST);
				update_tri_layer(_LOWER, _RAISE, _ADJUST);
			}
			return false;
			break;

		case VOICEMEETERA1:
			if (record->event.pressed) {
				layer_on(_VOICEMEETERA1);
				//update_tri_layer(_LOWER, _RAISE, _ADJUST);
			} else {
				layer_off(_VOICEMEETERA1);
				//update_quad_layer(_LOWER, _RAISE, _FUNCTION, _ADJUST);
				//update_tri_layer(_LOWER, _RAISE, _ADJUST);
			}
			return false;
			break;

		case VOICEMEETERA2:
			if (record->event.pressed) {
				layer_on(_VOICEMEETERA2);
				//update_tri_layer(_LOWER, _RAISE, _ADJUST);
			} else {
				layer_off(_VOICEMEETERA2);
				//update_quad_layer(_LOWER, _RAISE, _FUNCTION, _ADJUST);
				//update_tri_layer(_LOWER, _RAISE, _ADJUST);
			}
			return false;
			break;

		case VOICEMEETERAAUX:
			if (record->event.pressed) {
				layer_on(_VOICEMEETERAAUX);
				//update_tri_layer(_LOWER, _RAISE, _ADJUST);
			} else {
				layer_off(_VOICEMEETERAAUX);
				//update_quad_layer(_LOWER, _RAISE, _FUNCTION, _ADJUST);
				//update_tri_layer(_LOWER, _RAISE, _ADJUST);
			}
			return false;
			break;
		case MACRO_NEXT:
			if (record->event.pressed){
				SEND_STRING(SS_DOWN(X_LCTRL)SS_DOWN(X_LSHIFT)"3"SS_UP(X_LCTRL)SS_UP(X_LSHIFT));
			}
			return false;
			break;
		case MACRO_PLAY:
			if (record->event.pressed){
				SEND_STRING(SS_DOWN(X_LCTRL)SS_DOWN(X_LSHIFT)"2"SS_UP(X_LCTRL)SS_UP(X_LSHIFT));
			}
			return false;
			break;

		case MACRO_PREV:
			if (record->event.pressed){
				SEND_STRING(SS_DOWN(X_LCTRL)SS_DOWN(X_LSHIFT)"1"SS_UP(X_LCTRL)SS_UP(X_LSHIFT));
			}
			return false;
			break;


	}
	return true;
}

void encoder_update_user(int8_t index, bool clockwise) {


	if (IS_LAYER_ON(_QWERTY)){
		if (index == 0) {
			if (clockwise) {
			register_code(KC_PGUP);
			unregister_code(KC_PGUP);
			} 
			else {
			register_code(KC_PGDN);
			unregister_code(KC_PGDN);
			}
		}
	}

	//adjust voice meeter output volume
	if (IS_LAYER_ON(_VOICEMEETERA1)){
		if (index == 0) {
			if (clockwise) {
			register_code(KC_F21);
			unregister_code(KC_F21);
		} 
		else {
			register_code(KC_F22);
			unregister_code(KC_F22);
		}
		}
	}
	if (IS_LAYER_ON(_VOICEMEETERA2)){
		if (index == 0) {
			if (clockwise) {
			register_code(KC_F23);
			unregister_code(KC_F23);
		} 
		else {
			register_code(KC_F24);
			unregister_code(KC_F24);
		}
		}
	}
	if (IS_LAYER_ON(_VOICEMEETERAAUX)){
		if (index == 0) {
			if (clockwise) {
			register_code(KC_F19);
			unregister_code(KC_F19);
		} 
		else {
			register_code(KC_F20);
			unregister_code(KC_F20);
		}
		}
	}
}


