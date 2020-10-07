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
  SEALS,
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
	
	[0] = LAYOUT(KC_ESC, KC_1, KC_2, KC_3, KC_4, KC_5, KC_6, KC_7, KC_8, KC_9, KC_0, KC_GRV, KC_TAB, KC_LCTL, KC_W, KC_F, KC_P, KC_COMM, KC_DOT, KC_L, KC_U, KC_Y, KC_SCLN, KC_MINS, KC_LSFT, KC_A, KC_R, KC_S, KC_T, KC_G, KC_K, KC_N, KC_E, KC_I, KC_O, KC_QUOT, KC_Z, KC_Q, KC_X, KC_C, KC_D, KC_B, KC_LBRC, KC_RBRC, KC_M, KC_H, KC_J, KC_V, KC_SLSH, KC_EXLM, KC_LALT, KC_LGUI, MO(4), KC_SPC, LT(5,KC_ENT), KC_BSPC, KC_RSFT, KC_DEL),
	
	[1] = LAYOUT(KC_ESC, KC_1, KC_2, KC_3, KC_4, KC_5, KC_6, KC_7, KC_8, KC_9, KC_0, KC_GRV, KC_TAB, KC_Q, KC_W, KC_E, KC_R, KC_T, KC_Y, KC_U, KC_I, KC_O, KC_P, KC_MINS, KC_LSFT, KC_A, KC_S, KC_D, KC_F, KC_G, KC_H, KC_J, KC_K, KC_L, KC_SCLN, KC_QUOT, KC_LCTL, KC_Z, KC_X, KC_C, KC_V, KC_B, KC_LBRC, KC_RBRC, KC_N, KC_M, KC_DOT, KC_SLSH, KC_RSFT, KC_EXLM, KC_LALT, KC_LGUI, MO(4), KC_SPC, LT(5,KC_ENT), KC_BSPC, KC_COMM, KC_DEL),
	
	[2] = LAYOUT(KC_ESC, KC_1, KC_2, KC_3, KC_4, KC_5, KC_6, KC_7, KC_8, KC_9, KC_0, KC_GRV, KC_TAB, KC_Q, KC_W, KC_F, KC_P, KC_G, KC_J, KC_L, KC_U, KC_Y, KC_SCLN, KC_MINS, KC_LSFT, KC_A, KC_R, KC_S, KC_T, KC_D, KC_H, KC_N, KC_E, KC_I, KC_O, KC_QUOT, KC_LCTL, KC_Z, KC_X, KC_C, KC_V, KC_B, KC_LBRC, KC_RBRC, KC_K, KC_M, KC_DOT, KC_SLSH, KC_RSFT, KC_EXLM, KC_LALT, KC_LGUI, MO(4), KC_SPC, LT(5,KC_ENT), KC_BSPC, KC_COMM, KC_DEL),

	[3] = LAYOUT(KC_ESC, KC_1, KC_2, KC_3, KC_4, KC_5, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, SEALS, KC_GRV, KC_Y, KC_Q, KC_W, KC_E, KC_R, WHEART, GHEART, HEART, KC_TRNS, KC_TRNS, KC_TRNS, KC_TAB, KC_G, KC_A, KC_S, KC_D, KC_F, DM_REC1, DM_REC2, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_LSFT, KC_Z, KC_X, KC_B, KC_C, KC_V, KC_T, DM_RSTP, DM_PLY1, DM_PLY2, SHRUG, KC_TRNS, KC_TRNS, KC_TRNS, KC_B, KC_H, KC_LCTL, KC_SPC, TG(3), KC_TRNS, KC_TRNS, KC_TRNS),



	[4] = LAYOUT(KC_PWR, KC_SLEP, KC_WAKE, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_LEFT, KC_DOWN, KC_UP, KC_RGHT, KC_TRNS, KC_F1, KC_F2, KC_F3, KC_F4, KC_F5, KC_F6, KC_F7, KC_F8, KC_F9, KC_F10, KC_F11, KC_F12, KC_F13, KC_F14, KC_F15, KC_F16, KC_F17, KC_F18, KC_F19, KC_F20, KC_F21, KC_F22, KC_F23, KC_F24, KC_LCTL, KC_UNDO, KC_CUT, KC_COPY, KC_PSTE, KC_AGIN, DF(1), DF(2), KC_APP, KC_UNDS, KC_PLUS, KC_LCBR, KC_RCBR, KC_PIPE, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, TG(3), DF(0), KC_TRNS, KC_TRNS),

	[5] = LAYOUT(KC_P7, KC_P8, KC_P9, KC_PSCR, KC_CAPS, KC_PAUS, KC_BTN1, KC_BTN1, KC_BTN2, KC_BTN3, KC_WH_D, KC_WH_U, KC_P4, KC_P5, KC_P6, KC_INS, KC_HOME, KC_PGUP, KC_MUTE, KC_VOLD, KC_VOLU, KC_MRWD, KC_MFFD, KC_MPLY, KC_P1, KC_P2, KC_P3, KC_DEL, KC_END, KC_PGDN, KC_HOME, KC_LEFT, KC_DOWN, KC_UP, KC_RGHT, KC_END, KC_TRNS, KC_P0, KC_PSLS, KC_PAST, KC_PMNS, KC_PPLS, KC_LOCK, OSL(6), KC_APP, KC_INS, KC_PGDN, KC_PGUP, KC_EQL, KC_BSLS, KC_TRNS, KC_TRNS, KC_TRNS, TG(3), KC_TRNS, KC_TRNS, KC_ENT, KC_TRNS),
	
	[6] = LAYOUT(RESET, DEBUG, EEP_RST, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_SLCK, KC_NLCK, KC_NO, KC_NO, KC_NO, KC_NO, GE_SWAP, GUI_ON, NK_ON, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, GE_NORM, GUI_OFF, NK_OFF, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_TRNS, NK_TOGG, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, OSM(MOD_HYPR), KC_NO, KC_NO, KC_NO, KC_NO, KC_NO)
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

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  if (record->event.pressed) {
#ifdef OLED_DRIVER_ENABLE
    set_keylog(keycode, record);
#endif
    // set_timelog();
    switch (keycode) {

  case HEART:
        if (record->event.pressed) {
            SEND_STRING(":heart:");
        } else {
        }
        break;
  
   case GHEART:
        if (record->event.pressed) {
            SEND_STRING(":green_heart:");
        } else {
        }
        break;
        
   case WHEART:
        if (record->event.pressed) {
            SEND_STRING(":white_heart:");
        } else {
        }
        break;
  
  case SHRUG:
        if (record->event.pressed) {
            SEND_STRING("/shrug");
        } else {
        }
        break;
    
    case SEALS:
        if (record->event.pressed) {
            SEND_STRING("What the fuck did you just fucking say about me, you little bitch? I'll have you know I graduated top of my class in the Navy Seals, and I've been involved in numerous secret raids on Al-Quaeda, and I have over 300 confirmed kills.\n I am trained in gorilla warfare and I'm the top sniper in the entire US armed forces.\n You are nothing to me but just another target.\n I will wipe you the fuck out with precision the likes of which has never been seen before on this Earth, mark my fucking words.\n You think you can get away with saying that shit to me over the Internet? Think again, fucker.\n As we speak I am contacting my secret network of spies across the USA and your IP is being traced right now so you better prepare for the storm, maggot.\n The storm that wipes out the pathetic little thing you call your life.\n You're fucking dead, kid.\n I can be anywhere, anytime, and I can kill you in over seven hundred ways, and that's just with my bare hands.\n Not only am I extensively trained in unarmed combat, but I have access to the entire arsenal of the United States Marine Corps and I will use it to its full extent to wipe your miserable ass off the face of the continent, you little shit.\n If only you could have known what unholy retribution your little \"clever\" comment was about to bring down upon you, maybe you would have held your fucking tongue.\n But you couldn't, you didn't, and now you're paying the price, you goddamn idiot.\n I will shit fury all over you and you will drown in it.\n You're fucking dead, kiddo.\n");
        } else {
        }
        break;

  }
  }
  return true;
}
