#pragma once
#include "quantum.h"
#include "version.h"
#include "eeprom.h"
#include "custom_keycodes.h"

#define _QWERTY 0
#define _NUM 1
#define _NAV 2
#define _FUN 3

#define WIN_PST C(KC_V)
#define WIN_CPY C(KC_C)
#define WIN_CUT C(KC_X)
#define WIN_UND C(KC_Z)

#define KC_Q_EXCL LT(0,KC_Q)
#define KC_Z_LPRN LT(0,KC_Z)
#define KC_V_RPRN LT(0,KC_V)


#define _____________________QWERTY_L1_5U______________________ KC_Q, KC_W, KC_E, KC_R, KC_T
#define _____________________QWERTY_L2_5U______________________ LGUI_T(KC_A), LALT_T(KC_S), LCTL_T(KC_D), LSFT_T(KC_F), KC_G
#define _____________________QWERTY_L3_5U______________________ OSM(MOD_LSFT), KC_Z, KC_X, KC_C, KC_V
#define _____________________QWERTY_L1______________________ KC_TAB, _____________________QWERTY_L1_5U______________________
#define _____________________QWERTY_L2______________________ KC_ESC, _____________________QWERTY_L2_5U______________________
#define _____________________QWERTY_L3______________________ KC_AT_SPECIAL, _____________________QWERTY_L3_5U______________________

#define _____________________QWERTY_R1_5U______________________ KC_Y, KC_U, KC_I, KC_O, KC_P
#define _____________________QWERTY_R2_5U______________________ KC_H, LSFT_T(KC_J), LCTL_T(KC_K), LALT_T(KC_L), LGUI_T(KC_SCLN)
#define _____________________QWERTY_R3_5U______________________ KC_B, KC_COMM, KC_BSPC, KC_DOT, OSL(_NUM)
#define _____________________QWERTY_R1______________________ _____________________QWERTY_R1_5U______________________, KC_BSPC
#define _____________________QWERTY_R2______________________ _____________________QWERTY_R2_5U______________________, KC_QUOT
#define _____________________QWERTY_R3______________________ _____________________QWERTY_R3_5U______________________, KC_ENT

#define _______QWERTY_RT_2U_______ LT(_NUM,KC_N), LT(_FUN,KC_M)
#define _______QWERTY_RT_______ _______QWERTY_RT_2U_______, QK_REPEAT_KEY
#define _______QWERTY_LT_2U_______ LT(_NAV,KC_QUOT), LT(_NAV,KC_SPC)
#define _______QWERTY_LT_______ KC_BTN1, _______QWERTY_LT_2U_______


#define _____________________NUM_L1_5U______________________ KC_LBRC, KC_7, KC_8, KC_9, KC_RBRC
#define _____________________NUM_L2_5U______________________ KC_MINS, KC_4, KC_5, KC_6, KC_EQL
#define _____________________NUM_L3_5U______________________ KC_GRV, KC_1, KC_2, KC_3, KC_BSLS
#define _____________________NUM_L1______________________ KC_NO, _____________________NUM_L1_5U______________________
#define _____________________NUM_L2______________________ KC_NO, _____________________NUM_L2_5U______________________
#define _____________________NUM_L3______________________ KC_NO, _____________________NUM_L3_5U______________________

#define _____________________NUM_R1_5U______________________ S(KC_LBRC), S(KC_7), S(KC_8), S(KC_BSLS), S(KC_RBRC)
#define _____________________NUM_R2_5U______________________ S(KC_EQL), LSFT_T(KC_4), LCTL_T(KC_5), LALT_T(KC_6), LGUI_T(KC_GRV)
#define _____________________NUM_R3_5U______________________ S(KC_SLSH), S(KC_1), S(KC_2), S(KC_3), KC_TRNS
#define _____________________NUM_R1______________________ _____________________NUM_R1_5U______________________, KC_NO
#define _____________________NUM_R2______________________ _____________________NUM_R2_5U______________________, KC_NO
#define _____________________NUM_R3______________________ _____________________NUM_R3_5U______________________, KC_NO

#define _______NUM_LT_2U_______ KC_0, S(KC_MINS)
#define _______NUM_RT_2U_______ KC_SLSH, S(KC_9)
#define _______NUM_LT_______ KC_DOT, _______NUM_LT_2U_______
#define _______NUM_RT_______ _______NUM_RT_2U_______, S(KC_0)

#define _____________________NAV_L1_5U______________________ LCTL(LGUI(KC_LEFT)), LCTL(LGUI(KC_RGHT)), LCTL(LSFT(KC_TAB)), LCTL(KC_TAB), LCTL(LSFT(KC_M))
#define _____________________NAV_L2_5U______________________ KC_LGUI, KC_LALT, KC_LCTL, KC_LSFT, KC_TAB
#define _____________________NAV_L3_5U______________________ KC_ENT, WIN_UND, WIN_CUT, WIN_CPY, WIN_PST
#define _____________________NAV_L1______________________ KC_TRNS, _____________________NAV_L1_5U______________________
#define _____________________NAV_L2______________________ KC_TRNS, _____________________NAV_L2_5U______________________
#define _____________________NAV_L3______________________ KC_TRNS, _____________________NAV_L3_5U______________________

#define _____________________NAV_R1_5U______________________ KC_HOME, KC_PGDN, KC_PGUP, KC_END, KC_INS
#define _____________________NAV_R2_5U______________________ KC_LEFT, KC_DOWN, KC_UP, KC_RGHT, KC_APP
#define _____________________NAV_R3_5U______________________ KC_ESC, KC_DEL, KC_BSPC, LGUI(LALT(KC_SPC)), KC_ENT
#define _____________________NAV_R1______________________ _____________________NAV_R1_5U______________________, KC_NO
#define _____________________NAV_R2______________________ _____________________NAV_R2_5U______________________, KC_NO
#define _____________________NAV_R3______________________ _____________________NAV_R3_5U______________________, KC_NO

#define _______NAV_LT_2U_______ KC_NO, KC_TRNS
#define _______NAV_RT_2U_______ KC_TAB, CW_TOGG
#define _______NAV_LT_______ MO(_FUN), _______NAV_LT_2U_______
#define _______NAV_RT_______ _______NAV_RT_2U_______, MO(_FUN)


#define _____________________FUN_L1_5U______________________ RALT(KC_Q), RALT(KC_S), RALT(KC_Y), RALT(KC_P), KC_NO
#define _____________________FUN_L1______________________ KC_NO, _____________________FUN_L1_5U______________________
#if defined(RGB_MATRIX_ENABLE) || defined(RGBLIGHT_ENABLE)
  #define _____________________FUN_L2_5U______________________ RGB_TOG, RGB_RMOD, RGB_MOD, KC_NO, QK_REBOOT
  #define _____________________FUN_L2______________________ KC_NO, _____________________FUN_L2_5U______________________
#else
  #define _____________________FUN_L2_5U______________________ KC_NO, KC_NO, KC_NO, KC_NO, QK_REBOOT
  #define _____________________FUN_L2______________________ KC_NO, _____________________FUN_L2_5U______________________
#endif
#define _____________________FUN_L3_5U______________________ KC_NO, KC_NO, KC_NO, KC_NO, QK_BOOTLOADER
#define _____________________FUN_L3______________________ KC_NO, _____________________FUN_L3_5U______________________

#define _____________________FUN_R1_5U______________________ KC_MUTE, KC_F7, KC_F8, KC_F9, KC_F12
#define _____________________FUN_R2_5U______________________ QK_REBOOT, KC_F4, KC_F5, KC_F6, KC_F11
#define _____________________FUN_R3_5U______________________ QK_BOOTLOADER, KC_F1, KC_F2, KC_F3, KC_F10
#define _____________________FUN_R1______________________ _____________________FUN_R1_5U______________________, KC_NO
#define _____________________FUN_R2______________________ _____________________FUN_R2_5U______________________, KC_NO
#define _____________________FUN_R3______________________ _____________________FUN_R3_5U______________________, KC_NO

#define _______FUN_LT_2U_______ QK_DYNAMIC_MACRO_RECORD_START_1, QK_DYNAMIC_MACRO_PLAY_1
#define _______FUN_RT_2U_______ KC_VOLU, KC_TRNS
#define _______FUN_LT_______ QK_DYNAMIC_MACRO_RECORD_STOP, _______FUN_LT_2U_______
#define _______FUN_RT_______ _______FUN_RT_2U_______, KC_VOLD


// Layout wrappers
#define LAYOUT_wrapper(...) LAYOUT(__VA_ARGS__)
#define LAYOUT_split_3x5_2_wrapper(...) LAYOUT_split_3x5_2(__VA_ARGS__)

