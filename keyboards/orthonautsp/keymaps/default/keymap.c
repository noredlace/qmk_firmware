#include "orthonautsp.h"

enum orthonautsp_layers {
  _QWERTY,
  _LOWER,
  _RAISE,
  _FUNCTION,
  _ADJUST
};

enum orthonautsp_keycodes {
  QWERTY = SAFE_RANGE,
  LOWER,
  RAISE,
  TEST,
  FUNCTION,
  MACRO_1,
  MACRO_2
};


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
	
	
	[_QWERTY] = KEYMAP(
	 KC_7, KC_8, KC_9,   KC_TAB,  KC_Q,    KC_W,    KC_E,   KC_R,  KC_T,   KC_Y,  KC_U,  KC_I,     KC_O,    KC_P,     KC_BSPC, KC_INS, KC_HOME,
   KC_4, KC_5, KC_8,   KC_ESC,  KC_A,    KC_S,    KC_D,   KC_F,  KC_G,   KC_H,  KC_J,  KC_K,     KC_L,    KC_SCLN,  KC_QUOT, KC_DEL, KC_END,
   KC_1, KC_2, KC_3,   KC_LSFT, KC_Z,    KC_X,    KC_C,   KC_V,  KC_B,   KC_N,  KC_M,  KC_COMM,  KC_DOT,  KC_SLSH,  KC_RSFT, KC_UP,
   KC_0, KC_0, KC_DOT, KC_LCTL, KC_LGUI, KC_LALT, LOWER,    KC_SPC,        KC_ENT,     RAISE,    KC_RALT, FUNCTION, KC_LEFT, KC_DOWN, KC_RGHT
   ),
	

	[_FUNCTION] = KEYMAP(
	 KC_7, KC_8, KC_9,   KC_TAB,  KC_Q,    KC_W,    KC_E,   KC_R,  KC_T,   KC_Y,  KC_U,  KC_I,     KC_O,    KC_P,     KC_BSPC, KC_INS, KC_HOME,
   KC_4, KC_5, KC_8,   KC_ESC,  KC_A,    KC_S,    KC_D,   KC_F,  KC_G,   KC_H,  KC_J,  KC_K,     KC_L,    KC_SCLN,  KC_QUOT, KC_DEL, KC_END,
   KC_1, KC_2, KC_3,   KC_LSFT, KC_Z,    KC_X,    KC_C,   KC_V,  KC_B,   KC_N,  KC_M,  KC_COMM,  KC_DOT,  KC_SLSH,  KC_RSFT, KC_UP,
   KC_0, KC_0, KC_DOT, KC_LCTL, KC_LGUI, KC_LALT, LOWER,    KC_SPC,        KC_ENT,     RAISE,    KC_RALT, KC_TRNS,  KC_LEFT, KC_DOWN, KC_RGHT
  ),


	[_LOWER] = KEYMAP(
	 KC_7, KC_8, KC_9,   KC_TAB,  KC_Q,    KC_W,    KC_E,   KC_R,  KC_T,   KC_Y,  KC_U,  KC_I,     KC_O,    KC_P,     KC_BSPC, KC_INS, KC_HOME,
   KC_4, KC_5, KC_8,   KC_ESC,  KC_A,    KC_S,    KC_D,   KC_F,  KC_G,   KC_H,  KC_J,  KC_K,     KC_L,    KC_SCLN,  KC_QUOT, KC_DEL, KC_END,
   KC_1, KC_2, KC_3,   KC_LSFT, KC_Z,    KC_X,    KC_C,   KC_V,  KC_B,   KC_N,  KC_M,  KC_COMM,  KC_DOT,  KC_SLSH,  KC_RSFT, KC_UP,
   KC_0, KC_0, KC_DOT, KC_LCTL, KC_LGUI, KC_LALT, KC_TRNS,   KC_SPC,        KC_ENT,    RAISE,    KC_RALT, FUNCTION, KC_LEFT, KC_DOWN, KC_RGHT
),

	[_RAISE] = KEYMAP(
	 KC_7, KC_8, KC_9,   KC_TAB,  KC_Q,    KC_W,    KC_E,   KC_R,  KC_T,   KC_Y,  KC_U,  KC_I,     KC_O,    KC_P,     KC_BSPC, KC_INS, KC_HOME,
   KC_4, KC_5, KC_8,   KC_ESC,  KC_A,    KC_S,    KC_D,   KC_F,  KC_G,   KC_H,  KC_J,  KC_K,     KC_L,    KC_SCLN,  KC_QUOT, KC_DEL, KC_END,
   KC_1, KC_2, KC_3,   KC_LSFT, KC_Z,    KC_X,    KC_C,   KC_V,  KC_B,   KC_N,  KC_M,  KC_COMM,  KC_DOT,  KC_SLSH,  KC_RSFT, KC_UP,
   KC_0, KC_0, KC_DOT, KC_LCTL, KC_LGUI, KC_LALT, LOWER,     KC_SPC,        KC_ENT,    KC_TRNS,  KC_RALT, FUNCTION, KC_LEFT, KC_DOWN, KC_RGHT
),

	[_ADJUST] = KEYMAP(
	 KC_7, KC_8, KC_9,   KC_TAB,  KC_Q,    KC_W,    KC_E,   KC_R,  KC_T,   KC_Y,  KC_U,  KC_I,     KC_O,    KC_P,     KC_BSPC, KC_INS, KC_HOME,
   KC_4, KC_5, KC_8,   KC_ESC,  KC_A,    KC_S,    KC_D,   KC_F,  KC_G,   KC_H,  KC_J,  KC_K,     KC_L,    KC_SCLN,  KC_QUOT, KC_DEL, KC_END,
   KC_1, KC_2, KC_3,   KC_LSFT, KC_Z,    KC_X,    KC_C,   KC_V,  KC_B,   KC_N,  KC_M,  KC_COMM,  KC_DOT,  KC_SLSH,  KC_RSFT, KC_UP,
   KC_0, KC_0, KC_DOT, KC_LCTL, KC_LGUI, KC_LALT, KC_TRNS,   KC_SPC,        KC_ENT,    KC_TRNS,  KC_RALT, FUNCTION, KC_LEFT, KC_DOWN, KC_RGHT
)

};


bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
	  
	  
	case MACRO_1:
	  if (record->event.pressed) {
		SEND_STRING("cd /mnt/c/Users/EJ/Documents"SS_TAP(X_ENTER));

		return false; 
	  }
	case MACRO_2:
	  if (record->event.pressed) {
		  //navigate to folder
		SEND_STRING("cd /mnt/c/Users/EJ/Documents/Github/qmk_lizard" SS_TAP(X_ENTER) );

		
		//send command to compile
		SEND_STRING("make orgonaut66:lizard" SS_TAP(X_ENTER));

		
		return false; 
	  }
 

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
