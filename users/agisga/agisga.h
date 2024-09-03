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
#define _MOUSE 5

#define WIN_PST C(KC_V)
#define WIN_CPY C(KC_C)
#define WIN_CUT C(KC_X)
#define WIN_UND C(KC_Z)


#define _______BASE_LT_2U_______ OSL(_NUM), LT(_NAV,KC_SPC)
#define _______BASE_RT_2U_______ LT(_NAV,KC_QUOT), OSM(MOD_LSFT)
#define _______BASE_LT_______ KC_BTN1, _______BASE_LT_2U_______
#define _______BASE_RT_______ _______BASE_RT_2U_______, QK_REPEAT_KEY
#define _______BASE_REVIUNG_T_______ KC_BTN1, OSL(_NUM), LT(_NAV,KC_SPC), OSM(MOD_LSFT), QK_REPEAT_KEY


#define _____________________COLEMAK_L1_5U_____________________ KC_Q, KC_W, KC_F, KC_P, KC_G
#define _____________________COLEMAK_L2_5U_____________________ LGUI_T(KC_A), LALT_T(KC_R), LCTL_T(KC_S), LSFT_T(KC_T), KC_D
#define _____________________COLEMAK_L3_5U_____________________ KC_Z, KC_X, KC_C, KC_V, KC_B
#define _____________________COLEMAK_L1_____________________ KC_TAB, _____________________COLEMAK_L1_5U_____________________
#define _____________________COLEMAK_L2_____________________ KC_ESC, _____________________COLEMAK_L2_5U_____________________
#define _____________________COLEMAK_L3_____________________ KC_DEL, _____________________COLEMAK_L3_5U_____________________

#define _____________________COLEMAK_R1_5U____________________ KC_J, KC_L, KC_U, KC_Y, KC_BSPC
#define _____________________COLEMAK_R2_5U____________________ KC_H, LSFT_T(KC_N), LCTL_T(KC_E), LALT_T(KC_I), LGUI_T(KC_O)
#define _____________________COLEMAK_R3_5U____________________ KC_K, KC_M, KC_COMM, KC_DOT, KC_SLSH
#define _____________________COLEMAK_R1_____________________ _____________________COLEMAK_R1_5U____________________, KC_BSPC
#define _____________________COLEMAK_R2_____________________ _____________________COLEMAK_R2_5U____________________, KC_QUOT
#define _____________________COLEMAK_R3_____________________ _____________________COLEMAK_R3_5U____________________, KC_ENT


#define _____________________QWERTY_L1_5U______________________ KC_Q, KC_W, KC_E, KC_R, KC_T
#define _____________________QWERTY_L2_5U______________________ LGUI_T(KC_A), LALT_T(KC_S), LCTL_T(KC_D), LSFT_T(KC_F), KC_G
#define _____________________QWERTY_L3_5U______________________ KC_Z, KC_X, KC_C, KC_V, KC_B
#define _____________________QWERTY_L1______________________ KC_TAB, _____________________QWERTY_L1_5U______________________
#define _____________________QWERTY_L2______________________ KC_ESC, _____________________QWERTY_L2_5U______________________
#define _____________________QWERTY_L3______________________ KC_DEL, _____________________QWERTY_L3_5U______________________

#define _____________________QWERTY_R1_5U______________________ KC_Y, KC_U, KC_I, KC_O, KC_P
#define _____________________QWERTY_R2_5U______________________ KC_H, LSFT_T(KC_J), LCTL_T(KC_K), LALT_T(KC_L), LGUI_T(KC_SCLN)
#define _____________________QWERTY_R3_5U______________________ KC_N, KC_M, KC_COMM, KC_DOT, KC_SLSH
#define _____________________QWERTY_R1______________________ _____________________QWERTY_R1_5U______________________, KC_BSPC
#define _____________________QWERTY_R2______________________ _____________________QWERTY_R2_5U______________________, KC_QUOT
#define _____________________QWERTY_R3______________________ _____________________QWERTY_R3_5U______________________, KC_ENT


#define _____________________NAV_L1_5U______________________ KC_PGUP, KC_HOME, KC_UP, KC_END, KC_INS
#define _____________________NAV_L2_5U______________________ KC_PGDN, KC_LEFT, KC_DOWN, KC_RGHT, KC_TAB
#define _____________________NAV_L3_5U______________________ KC_ESC, KC_APP, LCTL(KC_BSPC), KC_BSPC, KC_DEL
#define _____________________NAV_L1______________________ KC_TAB, _____________________NAV_L1_5U______________________
#define _____________________NAV_L2______________________ KC_ESC, _____________________NAV_L2_5U______________________
#define _____________________NAV_L3______________________ KC_ESC, _____________________NAV_L3_5U______________________

#define _____________________NAV_R1_5U______________________ KC_FIFTEENSTARS, RALT(KC_Q), RALT(KC_Y), RALT(KC_S), RALT(KC_P)
#define _____________________NAV_R2_5U______________________ KC_TODO, KC_LSFT, KC_LCTL, KC_LALT, KC_LGUI
#define _____________________NAV_R3_5U______________________ KC_DQT, KC_AUTOCLOS_QUOTE, KC_AUTOCLOS_PAREN, KC_AUTOCLOS_SQBRA, KC_AUTOCLOS_CURLYBRA
#define _____________________NAV_R1______________________ _____________________NAV_R1_5U______________________, KC_NO
#define _____________________NAV_R2______________________ _____________________NAV_R2_5U______________________, KC_NO
#define _____________________NAV_R3______________________ _____________________NAV_R3_5U______________________, KC_NO

#define _______NAV_LT_2U_______ KC_ENT, KC_TRNS
#define _______NAV_RT_2U_______ KC_TRNS, MO(_FUN)
#define _______NAV_LT_______ KC_TRNS, _______NAV_LT_2U_______
#define _______NAV_RT_______ _______NAV_RT_2U_______, QK_REPEAT_KEY
#define _______NAV_REVIUNG_T_______ KC_TRNS, KC_ENT, KC_TRNS, MO(_FUN), QK_REPEAT_KEY


#define _____________________NUM_L1_5U______________________ C(G(KC_LEFT)), C(G(KC_RIGHT)), KC_VOLD, KC_VOLU, KC_MUTE
#define _____________________NUM_L2_5U______________________ KC_LGUI, KC_LALT, KC_LCTL, KC_LSFT, KC_CAPS
#define _____________________NUM_L3_5U______________________ WIN_UND, WIN_CUT, WIN_CPY, WIN_PST, KC_DEL
#define _____________________NUM_L1______________________ KC_NO, _____________________NUM_L1_5U______________________
#define _____________________NUM_L2______________________ KC_NO, _____________________NUM_L2_5U______________________
#define _____________________NUM_L3______________________ KC_NO, _____________________NUM_L3_5U______________________

#define _____________________NUM_R1_5U______________________ KC_LBRC, KC_7, KC_8, KC_9, KC_RBRC
#define _____________________NUM_R2_5U______________________ KC_EQL, KC_4, KC_5, KC_6, KC_MINS
#define _____________________NUM_R3_5U______________________ KC_BSLS, KC_1, KC_2, KC_3, KC_GRV
#define _____________________NUM_R1______________________ _____________________NUM_R1_5U______________________, KC_NO
#define _____________________NUM_R2______________________ _____________________NUM_R2_5U______________________, KC_NO
#define _____________________NUM_R3______________________ _____________________NUM_R3_5U______________________, KC_NO

#define _______NUM_LT_2U_______ KC_TRNS, KC_SPC
#define _______NUM_RT_2U_______ KC_UNDS, KC_0
#define _______NUM_LT_______ KC_TRNS, _______NUM_LT_2U_______
#define _______NUM_RT_______ _______NUM_RT_2U_______, KC_SCLN
#define _______NUM_REVIUNG_T_______ KC_TRNS, KC_TRNS, KC_UNDS, KC_0, KC_SCLN


#define _____________________FUN_L1_5U______________________ QK_DYNAMIC_MACRO_RECORD_START_1, QK_DYNAMIC_MACRO_PLAY_1, QK_DYNAMIC_MACRO_RECORD_START_2, QK_DYNAMIC_MACRO_PLAY_2, QK_DYNAMIC_MACRO_RECORD_STOP
#define _____________________FUN_L1______________________ KC_NO, _____________________FUN_L1_5U______________________
#if defined(RGB_MATRIX_ENABLE) || defined(RGBLIGHT_ENABLE)
  #define _____________________FUN_L2_5U______________________ KC_NO, KC_NO, RGB_RMOD, RGB_MOD, RGB_TOG
  #define _____________________FUN_L2______________________ KC_NO, _____________________FUN_L2_5U______________________
#else
  #define _____________________FUN_L2_5U______________________ KC_NO, KC_NO, KC_NO, KC_NO, KC_NO
  #define _____________________FUN_L2______________________ KC_NO, _____________________FUN_L2_5U______________________
#endif
#define _____________________FUN_L3_5U______________________ KC_NO, KC_NO, KC_NO, KC_NO, KC_NO
#define _____________________FUN_L3______________________ KC_NO, _____________________FUN_L3_5U______________________

#define _____________________FUN_R1_5U______________________ KC_PSCR, KC_F7, KC_F8, KC_F9, KC_F12
#define _____________________FUN_R2_5U______________________ A(KC_F4), KC_F4, KC_F5, KC_F6, KC_F11
#define _____________________FUN_R3_5U______________________ KC_NO, KC_F1, KC_F2, KC_F3, KC_F10
#define _____________________FUN_R1______________________ _____________________FUN_R1_5U______________________, KC_NO
#define _____________________FUN_R2______________________ _____________________FUN_R2_5U______________________, KC_NO
#define _____________________FUN_R3______________________ _____________________FUN_R3_5U______________________, KC_NO

#define _______FUN_LT_2U_______ KC_NO, KC_TRNS
#define _______FUN_RT_2U_______ KC_TRNS, KC_TRNS
#define _______FUN_LT_______ KC_NO, _______FUN_LT_2U_______
#define _______FUN_RT_______ _______FUN_RT_2U_______, KC_NO
#define _______FUN_REVIUNG_T_______ KC_NO, KC_NO, KC_TRNS, KC_TRNS, KC_NO


#define _____________________MOUSE_L1_5U______________________ KC_WH_U, KC_WH_L, KC_MS_U, KC_WH_R, TO(_COLEMAK)
#define _____________________MOUSE_L2_5U______________________ KC_WH_D, KC_MS_L, KC_MS_D, KC_MS_R, KC_NO
#define _____________________MOUSE_L3_5U______________________ KC_ENT, WIN_CUT, WIN_CPY, WIN_PST, KC_DEL
#define _____________________MOUSE_L1______________________ KC_NO, _____________________MOUSE_L1_5U______________________
#define _____________________MOUSE_L2______________________ KC_NO, _____________________MOUSE_L2_5U______________________
#define _____________________MOUSE_L3______________________ KC_NO, _____________________MOUSE_L3_5U______________________

#define _____________________MOUSE_R1_5U______________________ _____________________NUM_R1_5U______________________
#define _____________________MOUSE_R2_5U______________________ _____________________NUM_R2_5U______________________
#define _____________________MOUSE_R3_5U______________________ _____________________NUM_R3_5U______________________
#define _____________________MOUSE_R1______________________ _____________________NUM_R1______________________
#define _____________________MOUSE_R2______________________ _____________________NUM_R2______________________
#define _____________________MOUSE_R3______________________ _____________________NUM_R3______________________

#define _______MOUSE_LT_2U_______ KC_BTN1, KC_BTN2
#define _______MOUSE_LT_______ KC_BTN3, _______MOUSE_LT_2U_______
#define _______MOUSE_RT_2U_______ _______NUM_RT_2U_______
#define _______MOUSE_RT_______ _______NUM_RT_______
#define _______MOUSE_REVIUNG_T_______ KC_BTN3, KC_BTN1, KC_BTN2, KC_0, QK_REPEAT_KEY



// Layout wrappers
#define LAYOUT_wrapper(...) LAYOUT(__VA_ARGS__)
#define LAYOUT_split_3x5_2_wrapper(...) LAYOUT_split_3x5_2(__VA_ARGS__)

