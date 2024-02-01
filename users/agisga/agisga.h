#pragma once
#include "quantum.h"
#include "version.h"
#include "eeprom.h"
#include "custom_keycodes.h"

#define _COLEMAK 0
#define _QWERTY 1
#define _NAV 2
#define _NUM 3
#define _FUN 4
//#define _MOUSE 5

#define WIN_PST C(KC_V)
#define WIN_CPY C(KC_C)
#define WIN_CUT C(KC_X)
#define WIN_UND C(KC_Z)


#define _______BASE_LT_______ KC_AT_SPECIAL, OSL(_NUM), LT(_NAV,KC_SPC)
#define _______BASE_RT_______ LT(_NAV,KC_QUOT), OSM(MOD_LSFT), OSL(_FUN)
#define _______REVIUNG_T_______ KC_AT_SPECIAL, OSL(_NUM), LT(_NAV,KC_SPC), OSM(MOD_LSFT), OSL(_FUN)


#define _____________________COLEMAK_L1_____________________ KC_TAB, KC_Q, KC_W, KC_F, KC_P, KC_G
#define _____________________COLEMAK_L2_____________________ KC_ESC, LGUI_T(KC_A), LALT_T(KC_R), LCTL_T(KC_S), LSFT_T(KC_T), KC_D
#define _____________________COLEMAK_L3_____________________ KC_DEL, KC_Z, KC_X, KC_C, KC_V, KC_B

#define _____________________COLEMAK_R1_____________________ KC_J, KC_L, KC_U, KC_Y, KC_SCLN, KC_BSPC
#define _____________________COLEMAK_R2_____________________ KC_H, LSFT_T(KC_N), LCTL_T(KC_E), LALT_T(KC_I), LGUI_T(KC_O), KC_QUOT
#define _____________________COLEMAK_R3_____________________ KC_K, KC_M, KC_COMM, KC_DOT, KC_SLSH, KC_ENT


#define _____________________QWERTY_L1______________________ KC_TAB, KC_Q, KC_W, KC_E, KC_R, KC_T
#define _____________________QWERTY_L2______________________ KC_ESC, KC_A, KC_S, KC_D, KC_F, KC_G
#define _____________________QWERTY_L3______________________ KC_DEL, KC_Z, KC_X, KC_C, KC_V, KC_B

#define _____________________QWERTY_R1______________________ KC_Y, KC_U, KC_I, KC_O, KC_P, KC_BSPC
#define _____________________QWERTY_R2______________________ KC_H, KC_J, KC_K, KC_L, KC_SCLN, KC_QUOT
#define _____________________QWERTY_R3______________________ KC_N, KC_M, KC_COMM, KC_DOT, KC_SLSH, KC_ENT


#define _____________________NAV_L1______________________ KC_NO, KC_PGUP, KC_HOME, KC_UP, KC_END, KC_INS
#define _____________________NAV_L2______________________ KC_NO, KC_PGDN, KC_LEFT, KC_DOWN, KC_RGHT, KC_TAB
#define _____________________NAV_L3______________________ KC_NO, KC_MUTE, KC_VOLD, KC_VOLU, KC_BSPC, KC_DEL

#define _____________________NAV_R1______________________ KC_FIFTEENSTARS, RALT(KC_Q), RALT(KC_Y), RALT(KC_S), RALT(KC_P), KC_NO
#define _____________________NAV_R2______________________ KC_TODO, KC_LSFT, KC_LCTL, KC_LALT, KC_LGUI, KC_NO
#define _____________________NAV_R3______________________ KC_ELLIPSIS, KC_AUTOCLOS_QUOTE, KC_AUTOCLOS_PAREN, KC_AUTOCLOS_SQBRA, KC_AUTOCLOS_CURLYBRA, KC_NO

#define _______NAV_LT_______ KC_APP, KC_ENT, KC_TRNS
#define _______NAV_RT_______ KC_TRNS, KC_ESC, QK_REPEAT_KEY
#define _______NAV_REVIUNG_T_______ KC_APP, KC_ENT, KC_TRNS, KC_ESC, QK_REPEAT_KEY


#define _____________________NUM_L1______________________ KC_NO, C(G(KC_LEFT)), C(G(KC_RIGHT)), KC_TAB, KC_APP, KC_ESC
#define _____________________NUM_L2______________________ KC_NO, KC_LGUI, KC_LALT, KC_LCTL, KC_LSFT, KC_CAPS
#define _____________________NUM_L3______________________ KC_NO, WIN_UND, WIN_CUT, WIN_CPY, WIN_PST, KC_DEL

#define _____________________NUM_R1______________________ KC_LBRC, KC_7, KC_8, KC_9, KC_RBRC, KC_NO
#define _____________________NUM_R2______________________ KC_EQL, KC_4, KC_5, KC_6, KC_MINS, KC_NO
#define _____________________NUM_R3______________________ KC_BSLS, KC_1, KC_2, KC_3, KC_GRV, KC_NO

#define _______NUM_LT_______ KC_NO, KC_TRNS, KC_SPC
#define _______NUM_RT_______ KC_UNDS, KC_0, QK_REPEAT_KEY
#define _______NUM_REVIUNG_T_______ KC_NO, KC_TRNS, KC_UNDS, KC_0, QK_REPEAT_KEY


#define _____________________FUN_L1______________________ KC_NO, KC_COLONQ, KC_COLONW, KC_COLONWQ, KC_COLONQEX, KC_TABEDIT
#if defined(RGB_MATRIX_ENABLE) || defined(RGBLIGHT_ENABLE)
  #define _____________________FUN_L2______________________ KC_NO, KC_NO, KC_NO, RGB_RMOD, RGB_MOD, RGB_TOG
#else
  #define _____________________FUN_L2______________________ KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO
#endif
#define _____________________FUN_L3______________________ KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO

#define _____________________FUN_R1______________________ KC_PSCR, KC_F7, KC_F8, KC_F9, KC_F12, KC_NO
#define _____________________FUN_R2______________________ KC_NO, KC_F4, KC_F5, KC_F6, KC_F11, KC_NO
#define _____________________FUN_R3______________________ KC_NO, KC_F1, KC_F2, KC_F3, KC_F10, KC_NO

#define _______FUN_LT_______ QK_DYNAMIC_MACRO_RECORD_STOP, QK_DYNAMIC_MACRO_PLAY_1, QK_DYNAMIC_MACRO_RECORD_START_1
#define _______FUN_RT_______ QK_DYNAMIC_MACRO_RECORD_START_2, QK_DYNAMIC_MACRO_PLAY_2, KC_TRNS
#define _______FUN_REVIUNG_T_______ QK_DYNAMIC_MACRO_RECORD_STOP, QK_DYNAMIC_MACRO_PLAY_1, QK_DYNAMIC_MACRO_RECORD_START_1, KC_NO, KC_TRNS


// TODO: enable mouse layer later --> use tap-dance to make the app switches thumb key to enable the mouse layer on hold and win-tab on double tap
//#define _____________________MOUSE_L1______________________ KC_WH_U, KC_WH_L, KC_MS_U, KC_WH_R, KC_NO
//#define _____________________MOUSE_L2______________________ KC_WH_D, KC_MS_L, KC_MS_D, KC_MS_R, KC_NO
//#define _____________________MOUSE_L3______________________ WIN_UND, WIN_CUT, WIN_CPY, WIN_PST, KC_DEL
//#define _____________________MOUSE_LT______________________ KC_BTN3, KC_BTN1, KC_BTN2
//
//#define _____________________MOUSE_R1______________________ KC_NO, KC_NO, KC_NO, KC_NO, KC_NO
//#define _____________________MOUSE_R2______________________ KC_NO, KC_LSFT, KC_LCTL, KC_LALT, KC_LGUI
//#define _____________________MOUSE_R3______________________ KC_NO, KC_NO, KC_NO, KC_NO, KC_NO
//#define _____________________MOUSE_RT______________________ KC_NO, KC_NO, KC_NO
//
//#define _____________________MOUSE_REVIUNG_T______________________ KC_BTN3, KC_BTN1, KC_BTN2, KC_NO, KC_NO


// Layout wrappers
#define LAYOUT_wrapper(...) LAYOUT(__VA_ARGS__)
