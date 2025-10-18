#include QMK_KEYBOARD_H
#include "agisga.h"

// Wrapper macro to properly expand macros from agisga.h
#define LAYOUT_plexus_wrapper(...) LAYOUT(__VA_ARGS__)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  [_QWERTY] = LAYOUT_plexus_wrapper(
  //,-------------------------------------------------------------------------------------------------------------------------------.
     KC_ESC,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                 KC_7,    KC_8,   KC_9,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS, KC_EQL,
     KC_DEL,   _____________________QWERTY_L1_5U______________________, KC_4,    KC_5,   KC_6,    _____________________QWERTY_R1_5U______________________, KC_LBRC, KC_RBRC,
     CW_TOGG,  _____________________QWERTY_L2_5U______________________, KC_1,    KC_2,   KC_3,    _____________________QWERTY_R2_5U______________________, KC_SCLN,   KC_HOME,
     KC_GRV,   _____________________QWERTY_L3_5U______________________, KC_VOLD, KC_0,   KC_VOLU, _____________________QWERTY_R3_5U______________________, KC_UP,   KC_END,
     KC_ENT,   KC_NO,   KC_NO, KC_TAB,  _______QWERTY_LT_2U_______,     KC_NO,   KC_BTN1, KC_NO,  _______QWERTY_RT_2U_______,   KC_BSLS,  KC_NO,  KC_LEFT, KC_DOWN,   KC_RIGHT
  ),

  [_NAV] = LAYOUT_plexus_wrapper(
  //,-------------------------------------------------------------------------------------------------------------------------------.
     KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,
     KC_NO,   _____________________NAV_L1_5U______________________,   KC_NO,   KC_NO,   KC_NO,   _____________________NAV_R1_5U______________________, KC_NO,   KC_NO,
     KC_NO,   _____________________NAV_L2_5U______________________,   KC_NO,   KC_NO,   KC_NO,   _____________________NAV_R2_5U______________________, KC_NO,   KC_NO,
     KC_NO,   _____________________NAV_L3_5U______________________,   KC_NO,   KC_NO,   KC_NO,   _____________________NAV_R3_5U______________________, KC_NO,   KC_NO,
     KC_NO,   KC_NO,   KC_NO,   _______NAV_LT_______,                 KC_NO,   KC_NO,   KC_NO,   _______NAV_RT_______,               KC_NO,   KC_NO,   KC_NO,   KC_NO
  ),

  [_NUM] = LAYOUT_plexus_wrapper(
  //,-------------------------------------------------------------------------------------------------------------------------------.
     KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,
     KC_NO,   _____________________NUM_L1_5U______________________,    KC_NO,   KC_NO,   KC_NO,   _____________________NUM_R1_5U______________________, KC_NO,   KC_NO,
     KC_NO,   _____________________NUM_L2_5U______________________,    KC_NO,   KC_NO,   KC_NO,   _____________________NUM_R2_5U______________________, KC_NO,   KC_NO,
     KC_NO,   _____________________NUM_L3_5U______________________,    KC_NO,   KC_NO,   KC_NO,   _____________________NUM_R3_5U______________________, KC_NO,   KC_NO,
     KC_NO,   KC_NO,   KC_NO,   _______NUM_LT_______,                  KC_NO,   KC_NO,   KC_NO,   _______NUM_RT_______,               KC_NO,   KC_NO,   KC_NO,   KC_NO
  ),

  [_FUN] = LAYOUT_plexus_wrapper(
  //,-------------------------------------------------------------------------------------------------------------------------------.
     KC_NO,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_NO, KC_NO, KC_NO, KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,
     KC_NO,   _____________________FUN_L1_5U______________________,    KC_NO,   KC_NO,   KC_NO,   _____________________FUN_R1_5U______________________, KC_NO,   KC_NO,
     KC_NO,   _____________________FUN_L2_5U______________________,    KC_NO,   KC_NO,   KC_NO,   _____________________FUN_R2_5U______________________, KC_NO,   KC_NO,
     KC_NO,   _____________________FUN_L3_5U______________________,    KC_NO,   KC_NO,   KC_NO,   _____________________FUN_R3_5U______________________, KC_NO,   KC_NO,
     KC_NO,   KC_NO,   KC_NO,   _______FUN_LT_______,                  KC_NO,   KC_NO,   KC_NO,   _______FUN_RT_______,               KC_NO,   KC_NO,   KC_NO,   KC_NO
  ),

  [_MACRO] = LAYOUT_plexus_wrapper(
  //,-------------------------------------------------------------------------------------------------------------------------------.
     KC_NO,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_NO, KC_NO, KC_NO, KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,
     KC_NO,   _____________________MACRO_L1_5U______________________,  KC_NO,   KC_NO,   KC_NO,   _____________________MACRO_R1_5U______________________, KC_NO,   KC_NO,
     KC_NO,   _____________________MACRO_L2_5U______________________,  KC_NO,   KC_NO,   KC_NO,   _____________________MACRO_R2_5U______________________, KC_NO,   KC_NO,
     KC_NO,   _____________________MACRO_L3_5U______________________,  KC_NO,   KC_NO,   KC_NO,   _____________________MACRO_R3_5U______________________, KC_NO,   KC_NO,
     KC_NO,   KC_NO,   KC_NO,   _______MACRO_LT_______,                KC_NO,   KC_NO,   KC_NO,   _______MACRO_RT_______,               KC_NO,   KC_NO,   KC_NO,   KC_NO
  )
};
