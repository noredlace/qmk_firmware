#include "orthonautsp.h"

enum orthonautsp_layers {
  _QWERTY,
  _GAMING,
  _FUNCTION,
  _LOWER,
  _RAISE,
  _ADJUST
};




enum orthonautsp_keycodes {
  QWERTY = SAFE_RANGE,
  GAMING,
  FUNCTION,
  LOWER,
  RAISE,
  MACRO_1,
  MACRO_2
};

#define KC_RST   RESET
#define KC_CTLTB CTL_T(KC_TAB)
#define M2 MACRO_2

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
	
	
	[_QWERTY] = KEYMAP(
	 KC_7, KC_8, KC_9,    KC_ESC,    KC_Q,    KC_W,    KC_E,   KC_R,    KC_T,                  KC_Y,  KC_U,  KC_I,     KC_O,    KC_P,     KC_BSPC, KC_INS, KC_HOME,
   KC_4, KC_5, KC_6,    KC_CTLTB,  KC_A,    KC_S,    KC_D,   KC_F,    KC_G,                  KC_H,  KC_J,  KC_K,     KC_L,    KC_SCLN,  KC_QUOT, KC_DEL, KC_END,
   KC_1, KC_2, KC_3,    KC_LSFT,   KC_Z,    KC_X,    KC_C,   KC_V,    KC_B,                  KC_N,  KC_M,  KC_COMM,  KC_DOT,  KC_SLSH,  KC_RSFT, KC_UP,
   KC_DOT, KC_0, KC_P0, FUNCTION,  KC_LGUI, KC_LALT, LOWER,   LT(_LOWER, KC_SPC),    LT(_RAISE, KC_ENT),   RAISE,    KC_RALT, FUNCTION, KC_LEFT, KC_DOWN, KC_RGHT
  ),

  [_GAMING] = KEYMAP(
	 KC_7,   KC_8, KC_9,    KC_ESC,    KC_Q,    KC_W,    KC_E,   KC_R,  KC_T,   KC_Y,  KC_U,  KC_I,     KC_O,    KC_P,     KC_BSPC, KC_INS, KC_RST,
   KC_4,   KC_5, KC_6,    KC_CTLTB,  KC_A,    KC_S,    KC_D,   KC_F,  KC_G,   KC_H,  KC_J,  KC_K,     KC_L,    KC_SCLN,  KC_QUOT, KC_DEL, KC_G,
   KC_1,   KC_2, KC_3,    KC_LSFT,   KC_Z,    KC_X,    KC_C,   KC_V,  KC_B,   KC_N,  KC_M,  KC_COMM,  KC_DOT,  KC_SLSH,  KC_RSFT, KC_UP,
   KC_DOT, KC_0, KC_P0,   KC_TRNS,  KC_LGUI, KC_LALT, LOWER,    KC_SPC,          KC_ENT,   RAISE,    KC_RALT,  FUNCTION,  KC_LEFT, KC_DOWN, KC_RGHT
  ),

  [_FUNCTION] = KEYMAP(
	 KC_7,   KC_8, KC_9,     KC_ESC,    KC_Q,    KC_W,    KC_E,   KC_R,  KC_T,   KC_Y,  KC_U,  KC_I,     KC_O,    KC_P,     KC_BSPC, KC_TRNS, KC_TRNS,
   KC_4,   KC_5, KC_6,     KC_CTLTB,  KC_A,    KC_S,    KC_D,   KC_F,  KC_G,   KC_H,  KC_J,  KC_K,     KC_L,    KC_SCLN,  KC_QUOT, KC_TRNS, KC_F,
   KC_1,   KC_2, KC_3,     KC_LSFT,   KC_Z,    KC_X,    KC_C,   KC_V,  KC_B,   KC_N,  KC_M,  KC_COMM,  KC_DOT,  KC_SLSH,  KC_RSFT, KC_UP,
   KC_DOT, KC_0, KC_0,     KC_TRNS,   KC_LGUI, KC_LALT, LOWER,    KC_SPC,        KC_ENT,     RAISE,    KC_RALT, KC_TRNS,  KC_LEFT, KC_DOWN, KC_RGHT
  ),

	[_LOWER] = KEYMAP(
	 KC_7, KC_8, KC_9,   KC_ESC,   KC_1 ,   KC_2,    KC_3,   KC_4,   KC_5,   KC_6,   KC_7,  KC_8,   KC_9,    KC_0,     KC_BSPC, KC_NLCK, KC_PSCR,
   KC_4, KC_5, KC_6,   KC_CTLTB, KC_F1,   KC_F2,   KC_F3,  KC_F4,  KC_F5,  KC_F6,  KC_4,  KC_5,   KC_6,    KC_SCLN,  KC_QUOT, KC_TRNS, KC_L,
   KC_1, KC_2, KC_3,   KC_LSFT,  KC_F7,   KC_F8,   KC_F9,  KC_F10, KC_F11, KC_F12, KC_1,  KC_2,   KC_3,    KC_SLSH,  KC_RSFT, KC_UP,
   KC_DOT, KC_0, KC_0, KC_LCTL,  KC_TRNS, KC_TRNS, KC_TRNS,   KC_SPC,        KC_ENT,    RAISE,    KC_RALT, FUNCTION, KC_LEFT, KC_DOWN, KC_RGHT
  ),

	[_RAISE] = KEYMAP(
	 KC_7, KC_8, KC_9,   KC_ESC,    KC_EXLM, KC_AT,   KC_HASH, KC_DLR,   KC_PERC,   KC_CIRC,  KC_AMPR,  KC_ASTR,   KC_LPRN,   KC_RPRN,  KC_BSPC,  KC_TRNS,  KC_TRNS,
   KC_4, KC_5, KC_6,   KC_CTLTB,  KC_TRNS, KC_MINS, KC_EQL,  KC_LCBR,  KC_RCBR,   KC_LEFT,  KC_DOWN,  KC_UP,     KC_RIGHT,  KC_PIPE,  KC_GRV,   KC_TRNS,  KC_R,
   KC_1, KC_2, KC_3,   KC_LSFT,   KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,  KC_TRNS,   KC_UNDS,  KC_PLUS,  KC_LBRC,   KC_RBRC,   KC_BSLS,  KC_TILD,  KC_UP,
   KC_DOT, KC_0, KC_0, KC_LCTL,   KC_LGUI, KC_LALT, LOWER,     KC_SPC,                 KC_ENT,        KC_TRNS,   KC_RALT,   FUNCTION, KC_LEFT,  KC_DOWN, KC_RGHT
  ),

	[_ADJUST] = KEYMAP(
	 KC_TRNS, KC_TRNS, KC_TRNS,   KC_TRNS,  QWERTY,     KC_TRNS,    KC_TRNS,   KC_TRNS,  KC_TRNS,   KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_RST,
   KC_TRNS, KC_TRNS, KC_TRNS,   KC_TRNS,  KC_TRNS,    KC_TRNS,    KC_TRNS,   KC_TRNS,  GAMING,    KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_A,
   RGB_TOG, RGB_MOD, KC_TRNS,   KC_TRNS,  KC_TRNS,    KC_TRNS,    KC_TRNS,   KC_TRNS,  KC_TRNS,   KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
   M2,      KC_TRNS, KC_TRNS,   KC_TRNS,  KC_TRNS,    KC_TRNS,    KC_TRNS,        KC_TRNS,            KC_TRNS,        KC_TRNS,  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS
  )

};

//static uint16_t key_timer;

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
		SEND_STRING("cd /mnt/d/Users/Documents/Github/qmk_firmware" SS_TAP(X_ENTER) );

		
		//send command to compile
		SEND_STRING("make orthonautsp:lizard" SS_TAP(X_ENTER));

		
		return false; 
	  }
 

  case LOWER:
      if (record->event.pressed) {
        layer_on(_LOWER);
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

	  case QWERTY:
      if (record->event.pressed) {
        print("mode just switched to qwerty and this is a huge string\n");
        set_single_persistent_default_layer(_QWERTY);
      }
      return false;
      break;

    case GAMING:
      if (record->event.pressed) {
        //breathing_toggle();
        set_single_persistent_default_layer(_GAMING);
      }
      return false;
      break;
      
  
  }
  return true;

}


