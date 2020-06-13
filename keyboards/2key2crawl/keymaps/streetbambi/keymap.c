#include QMK_KEYBOARD_H

#define STAR 0x2605

//potential layers for tri state
enum crawl_layers {
  _QWERTY,
  _LOWER,
  _RAISE,
  _FUNCTION,
  _ADJUST
};

//keycodes and macros
enum crawl_keycodes {
  QWERTY = SAFE_RANGE,
  LOWER,
  RAISE,
  TEST,
  FUNCTION,
  SCREENCAP,
  TOGGLEAPP,
  NEWTAB,
  UNDO,
  QUITAPP,
  CTRLALTDEL,
  OPENAPP,
  COPY,
  NEWWIN,
  PASTE,
  NEWPWIN,
  SELECT,
  REFRESH
};


//keymap layout in a similar position to the physical position
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

	[_QWERTY] = KEYMAP(
    KC_ESC, NEWTAB, KC_UP, UNDO, KC_DEL,
    SCREENCAP, KC_LEFT, KC_DOWN, KC_RGHT, LOWER, KC_ENT),

	[_LOWER] = KEYMAP(
    RESET, SELECT, COPY, PASTE, CTRLALTDEL,
    QUITAPP, REFRESH, NEWWIN, NEWPWIN, KC_TRNS, KC_ENT)

	/*
	//no need for raise/adjust layers yet
	[_RAISE] = KEYMAP(
    KC_1, KC_2, KC_3, KC_4, KC_5,
    KC_R, KC_TRNS, KC_BSPC, KC_TRNS, KC_0, KC_ENT),

	[_ADJUST] = KEYMAP(
    KC_1, KC_2, KC_3, KC_4, KC_5,
    KC_A, KC_TRNS, KC_BSPC, KC_TRNS, KC_0, RESET)
	*/
};


void matrix_init_user(void) {
  debug_config.matrix = 1;
  debug_config.keyboard = 1;
  debug_config.enable = 1;
  
  //set aside for emoticon implementation later
  //set_unicode_input_mode(UC_WINC);
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
	switch(keycode){
		case SCREENCAP:
			if(record->event.pressed){
				register_code(KC_LGUI);
				register_code(KC_LSFT);
				register_code(KC_4);
				unregister_code(KC_4);
				unregister_code(KC_LSFT);
				unregister_code(KC_LGUI);
			}
			return false;
			break;
		case TOGGLEAPP:
			if(record->event.pressed){
				register_code(KC_LGUI);
				register_code(KC_TAB);
				unregister_code(KC_TAB);
				unregister_code(KC_LGUI);
			}
			return false;
			break;
		case NEWTAB:
			if(record->event.pressed){
				register_code(KC_LGUI);
				register_code(KC_T);
				unregister_code(KC_T);
				unregister_code(KC_LGUI);
			}
			return false;
			break;
		case UNDO:
			if(record->event.pressed){
				register_code(KC_LGUI);
				register_code(KC_Z);
				unregister_code(KC_Z);
				unregister_code(KC_LGUI);
			}
			return false;
			break;
		case QUITAPP:
			if(record->event.pressed){
				register_code(KC_LGUI);
				register_code(KC_Q);
				unregister_code(KC_Q);
				unregister_code(KC_LGUI);
			}
			return false;
			break;
		case CTRLALTDEL:
			if(record->event.pressed){
				register_code(KC_LGUI);
				register_code(KC_LALT);
				register_code(KC_ESC);
				unregister_code(KC_ESC);
				unregister_code(KC_LALT);
				unregister_code(KC_LGUI);
			}
			return false;
			break;
		case OPENAPP:
			if(record->event.pressed){
				register_code(KC_LSFT);
				register_code(KC_LGUI);
				register_code(KC_A);
				unregister_code(KC_A);
				unregister_code(KC_LGUI);
				unregister_code(KC_LSFT);
			}
			return false;
			break;
		case COPY:
			if(record->event.pressed){
				register_code(KC_LGUI);
				register_code(KC_C);
				unregister_code(KC_C);
				unregister_code(KC_LGUI);
			}
			return false;
			break;
		case NEWWIN:
			if(record->event.pressed){
				register_code(KC_LGUI);
				register_code(KC_N);
				unregister_code(KC_N);
				unregister_code(KC_LGUI);
			}
			return false;
			break;
		case PASTE:
			if(record->event.pressed){
				register_code(KC_LGUI);
				register_code(KC_V);
				unregister_code(KC_V);
				unregister_code(KC_LGUI);
			}
			return false;
			break;
		case NEWPWIN:
			if(record->event.pressed){
				register_code(KC_LSFT);
				register_code(KC_LGUI);
				register_code(KC_N);
				unregister_code(KC_N);
				unregister_code(KC_LGUI);
				unregister_code(KC_LSFT);
			}
			return false;
			break;
		case SELECT:
			if(record->event.pressed){
				register_code(KC_LGUI);
				register_code(KC_A);
				unregister_code(KC_A);
				unregister_code(KC_LGUI);
			}
			return false;
			break;
		case REFRESH:
			if(record->event.pressed){
				register_code(KC_LGUI);
				register_code(KC_LSFT);
				register_code(KC_R);
				unregister_code(KC_R);
				unregister_code(KC_LSFT);
				unregister_code(KC_LGUI);
			}
			return false;
			break;
		case LOWER:
			if (record->event.pressed){
				layer_on(_LOWER);
				//update_tri_layer(_LOWER, _RAISE, _ADJUST);
			} else {
				layer_off(_LOWER);
				//update_quad_layer(_LOWER, _RAISE, _FUNCTION, _ADJUST);
				//update_tri_layer(_LOWER, _RAISE, _ADJUST);
			}
			return false;
			break;


	}
	return true;
}

void encoder_update_user(int8_t index, bool clockwise) {
  if (index == 0) {
    if (clockwise) {
      register_code(KC_PGUP);
      unregister_code(KC_PGUP);
    } else {
      register_code(KC_PGDOWN);
      unregister_code(KC_PGDOWN);
    }
  }
  
  
}



