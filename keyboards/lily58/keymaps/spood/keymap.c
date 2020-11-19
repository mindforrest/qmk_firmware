#include QMK_KEYBOARD_H

#ifdef PROTOCOL_LUFA
  #include "lufa.h"
  #include "split_util.h"
#endif
#ifdef SSD1306OLED
  #include "ssd1306.h"
#endif

extern uint8_t is_master;

enum custom_keycodes {
  HEART = SAFE_RANGE,
  SHRUG,
  GHEART,
  WHEART,
  BOTTOM,
  EYEROLL,
};


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
	[0] = LAYOUT(KC_ESC, KC_1, KC_2, KC_3, KC_4, KC_5, KC_6, KC_7, KC_8, KC_9, KC_0, KC_GRV, KC_TAB, KC_Z, KC_W, KC_F, KC_P, KC_COMM, KC_DOT, KC_L, KC_U, KC_Y, KC_SCLN, KC_MINS, KC_LSFT, KC_A, KC_R, KC_S, KC_T, KC_G, KC_K, KC_N, KC_E, KC_I, KC_O, KC_QUOT, KC_LCTL, KC_Q, KC_X, KC_C, KC_D, KC_B, KC_LBRC, KC_RBRC, KC_M, KC_H, KC_J, KC_V, KC_SLSH, KC_EXLM, KC_LALT, KC_LGUI, MO(5), KC_SPC, LT(6,KC_ENT), KC_BSPC, OSL(4), KC_DEL),
	[1] = LAYOUT(KC_ESC, KC_1, KC_2, KC_3, KC_4, KC_5, KC_6, KC_7, KC_8, KC_9, KC_0, KC_GRV, KC_TAB, KC_Q, KC_W, KC_E, KC_R, KC_T, KC_Y, KC_U, KC_I, KC_O, KC_P, KC_MINS, KC_LSFT, KC_A, KC_S, KC_D, KC_F, KC_G, KC_H, KC_J, KC_K, KC_L, KC_SCLN, KC_QUOT, KC_LCTL, KC_Z, KC_X, KC_C, KC_V, KC_B, KC_LBRC, KC_RBRC, KC_N, KC_M, KC_COMM, KC_DOT, KC_SLSH, KC_EXLM, KC_LALT, KC_LGUI, MO(5), KC_SPC, LT(6,KC_ENT), KC_BSPC, KC_RSFT, KC_DEL),
	[2] = LAYOUT(KC_ESC, KC_1, KC_2, KC_3, KC_4, KC_5, KC_6, KC_7, KC_8, KC_9, KC_0, KC_GRV, KC_TAB, KC_QUES, KC_W, KC_F, KC_P, KC_B, KC_J, KC_L, KC_U, KC_Y, KC_SCLN, KC_MINS, KC_LCTL, KC_A, KC_R, KC_S, KC_T, KC_G, KC_K, KC_N, KC_E, KC_I, KC_O, KC_QUOT, KC_LSFT, KC_EXLM, KC_X, KC_C, KC_D, KC_V, KC_LBRC, KC_RBRC, KC_M, KC_H, KC_Z, KC_Q, KC_LALT, KC_RSFT, KC_LGUI, LT(6,KC_ENT), MO(5), KC_SPC, KC_BSPC, KC_DOT, KC_COMM, KC_DEL),
	[3] = LAYOUT(KC_ESC, KC_1, KC_2, KC_3, KC_4, KC_5, KC_6, KC_7, KC_8, KC_9, KC_0, KC_GRV, KC_GRV, KC_Y, KC_Q, KC_W, KC_E, KC_R, KC_Y, KC_U, KC_UP, KC_O, KC_P, KC_MINS, KC_TAB, KC_G, KC_A, KC_S, KC_D, KC_F, KC_RCTL, KC_LEFT, KC_DOWN, KC_RGHT, KC_RSFT, KC_QUOT, KC_RSFT, KC_Z, KC_X, KC_C, KC_V, KC_B, KC_T, KC_M, KC_RALT, KC_K, KC_DOT, KC_SLSH, KC_SCLN, KC_EXLM, KC_N, KC_H, KC_LCTL, KC_SPC, KC_TRNS, KC_BSPC, KC_TRNS, TG(3)),
	[4] = LAYOUT(KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, BOTTOM, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, WHEART, GHEART, HEART, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, SHRUG, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_TRNS, KC_F20),
	[5] = LAYOUT(KC_PWR, KC_SLEP, KC_WAKE, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_LEFT, KC_DOWN, KC_UP, KC_RGHT, KC_TRNS, KC_F1, KC_F2, KC_F3, KC_F4, KC_F5, KC_F6, KC_F7, KC_F8, KC_F9, KC_F10, KC_F11, KC_F12, KC_F13, KC_F14, KC_F15, KC_F16, KC_F17, KC_F18, KC_F19, KC_F20, KC_F21, KC_F22, KC_F23, KC_F24, KC_LCTL, KC_UNDO, KC_CUT, KC_COPY, KC_PSTE, KC_AGIN, DF(1), DF(2), KC_APP, KC_UNDS, KC_PLUS, KC_LCBR, KC_RCBR, KC_PIPE, KC_TRNS, KC_TRNS, KC_TRNS, TG(3), KC_TRNS, DF(0), KC_TRNS, KC_TRNS),
	[6] = LAYOUT(KC_PAUS, KC_NO, KC_P7, KC_P8, KC_P9, KC_PAST, KC_BTN1, KC_BTN1, KC_BTN2, KC_BTN3, KC_WH_D, KC_WH_U, KC_CAPS, KC_NO, KC_P4, KC_P5, KC_P6, KC_PSLS, KC_MUTE, KC_VOLD, KC_VOLU, KC_MRWD, KC_MFFD, KC_MPLY, KC_LSFT, KC_NO, KC_P1, KC_P2, KC_P3, KC_PPLS, KC_HOME, KC_LEFT, KC_DOWN, KC_UP, KC_RGHT, KC_END, KC_LCTL, KC_PSCR, KC_P0, KC_P0, KC_PDOT, KC_PMNS, KC_LOCK, OSL(7), KC_APP, KC_ENT, KC_PGDN, KC_PGUP, KC_BSLS, KC_EQL, KC_LALT, KC_LGUI, OSM(MOD_LCTL|MOD_LALT), KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS),
	[7] = LAYOUT(RESET, DEBUG, EEP_RST, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_SLCK, KC_NLCK, KC_NO, KC_NO, KC_NO, KC_NO, GE_SWAP, GUI_ON, NK_ON, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, GE_NORM, GUI_OFF, NK_OFF, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_TRNS, NK_TOGG, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, OSM(MOD_HYPR), KC_NO, KC_NO, KC_NO, KC_NO, KC_NO)
};



//SSD1306 OLED update loop, make sure to enable OLED_DRIVER_ENABLE=yes in rules.mk
#ifdef OLED_DRIVER_ENABLE

oled_rotation_t oled_init_user(oled_rotation_t rotation) {

    return OLED_ROTATION_0;  // flips the display 180 degrees if offhand

}

// When you add source files to SRC in rules.mk, you can use functions.
const char *read_layer_state(void);
const char *read_logo(void);
void set_keylog(uint16_t keycode, keyrecord_t *record);
const char *read_keylog(void);
const char *read_keylogs(void);

// const char *read_mode_icon(bool swap);
// const char *read_host_led_state(void);
// void set_timelog(void);
// const char *read_timelog(void);


void oled_task_user(void) {
    // If you want to change the display of OLED, you need to change here
    oled_write_ln(read_layer_state(), false);
    oled_write_ln(read_keylog(), false);
    oled_write_ln(read_keylogs(), false);
    //oled_write_ln(read_mode_icon(keymap_config.swap_lalt_lgui), false);
    //oled_write_ln(read_host_led_state(), false);
    //oled_write_ln(read_timelog(), false);

}

#endif // OLED_DRIVER_ENABLE





// macros

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  if (record->event.pressed) {
#ifdef OLED_DRIVER_ENABLE
    set_keylog(keycode, record);
#endif
    switch (keycode) {

  case HEART:
        if (record->event.pressed) {
            SEND_STRING(":heart:");
        } 
        else {
        }
        break;
  
   case GHEART:
        if (record->event.pressed) {
            SEND_STRING(":green_heart:");
        } 
        else {
        }
        break;
        
   case WHEART:
        if (record->event.pressed) {
            SEND_STRING(":white_heart:");
        } 
        else {
        }
        break;
   
   case EYEROLL:
   	if (record->event.pressed)
   	    SEND_STRING(":face_with_rolling_eyes:");
   	break;
/*        
   case KC_V:
        if (record->event.pressed) {
        
        } 
        else {
        	if (keycode == KC_V)
        		SEND_STRING("i");
        }
        break;
        
*/
  case SHRUG:
        if (record->event.pressed) {
            SEND_STRING("/shrug");
        } 
        else {
        }
        break;
    
    case BOTTOM:
    	if (record->event.pressed) {
    	    SEND_STRING(":point_right::point_left::pleading_face:");
    	break;
    	}

  }
  }
  return true;
}
