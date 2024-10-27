#include QMK_KEYBOARD_H
#include <stdio.h>
#include "agisga.h"

//-------------------------------
//--- per key tapping terms
//-------------------------------

// shorter tapping terms for thumb keys and shift, longer for ring and pinky
uint16_t get_tapping_term(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case LGUI_T(KC_A):
            return 300;
        case LGUI_T(KC_O):
            return 300;
        case LALT_T(KC_R):
            return 300;
        case LALT_T(KC_I):
            return 300;
        case LT(_NAV,KC_SPC):
            return 240;
        case LT(_NAV,KC_QUOT):
            return 190;
        default:
            return TAPPING_TERM;
    }
}
//---


//-------------------------------
//--- combos
//-------------------------------

#ifdef COMBO_ENABLE
enum combos {
    ZXCV_QWERTY,
    QWFP_MOUSE,
    WF_ALTAB,
    COMMADOT_SCLN,
    UY_COLN,
    XC_ENT,
};
const uint16_t PROGMEM zxcv_combo[] = {KC_Z, KC_X, KC_C, KC_V, COMBO_END};
const uint16_t PROGMEM qwfp_combo[] = {KC_Q, KC_W, KC_F, KC_P, COMBO_END};
const uint16_t PROGMEM wf_combo[] = {KC_W, KC_F, COMBO_END};
const uint16_t PROGMEM commadot_combo[] = {KC_COMM, KC_DOT, COMBO_END};
const uint16_t PROGMEM uy_combo[] = {KC_U, KC_Y, COMBO_END};
const uint16_t PROGMEM xc_combo[] = {KC_X, KC_C, COMBO_END};
combo_t key_combos[] = {
  [ZXCV_QWERTY] = COMBO(zxcv_combo, TG(_QWERTY)),
  [QWFP_MOUSE] = COMBO(qwfp_combo, TO(_MOUSE)),
  [WF_ALTAB] = COMBO(wf_combo, KC_AT_SPECIAL),
  [COMMADOT_SCLN] = COMBO(commadot_combo, KC_SCLN),
  [UY_COLN] = COMBO(uy_combo, KC_COLN),
  [XC_ENT] = COMBO(xc_combo, KC_ENT),
};
#endif
//---

//--- OLED (for crkbd)
#if defined(OLED_ENABLE)

int r_thumb = 0;
int l_thumb = 0;
int r_fingers = 0;
int l_fingers = 0;

oled_rotation_t oled_init_user(oled_rotation_t rotation) {
  if (!is_keyboard_master()) {
    return OLED_ROTATION_180;  // flips the display 180 degrees if offhand
  }
  return rotation;
}

char keylog_str[24] = {};
char thumb_use_str[24] = {};
char finger_use_str[24] = {};

const char code_to_name[60] = {
    ' ', ' ', ' ', ' ', 'a', 'b', 'c', 'd', 'e', 'f',
    'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p',
    'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z',
    '1', '2', '3', '4', '5', '6', '7', '8', '9', '0',
    'R', 'E', 'B', 'T', '_', '-', '=', '[', ']', '\\',
    '#', ';', '\'', '`', ',', '.', '/', ' ', ' ', ' '};

void set_keylog(uint16_t keycode, keyrecord_t *record) {
  char name = ' ';
    if ((keycode >= QK_MOD_TAP && keycode <= QK_MOD_TAP_MAX) ||
        (keycode >= QK_LAYER_TAP && keycode <= QK_LAYER_TAP_MAX)) { keycode = keycode & 0xFF; }
  if (keycode < 60) {
    name = code_to_name[keycode];
  }

  // update keylog
  snprintf(keylog_str, sizeof(keylog_str), "%dx%d  k%2d  %c",
           record->event.key.row, record->event.key.col,
           keycode, name);

  // Check if row is equal to 7 (right thumb was used) and increment counter
  if (record->event.key.row == 7) {
      r_thumb++;
  }
  // Check if row is equal to 3 (left thumb was used) and increment counter
  else if (record->event.key.row == 3) {
      l_thumb++;
  }
  // Check if left hand fingers other than thumb
  else if (record->event.key.row == 0 || record->event.key.row == 1 || record->event.key.row == 2) {
      l_fingers++;
  }
  // Check if right hand fingers other than thumb
  else if (record->event.key.row == 4 || record->event.key.row == 5 || record->event.key.row == 6) {
      r_fingers++;
  }
  //else {
  //// could replace the above finger-else-ifs with other ifs within this else in order to have per finger counters based on the columns but excluding the thumbs...
  //    fingers++;
  //}

  // update thumb use log
  snprintf(thumb_use_str, sizeof(thumb_use_str), "LT: %d\nRT: %d\n",
           l_thumb, r_thumb);
  //snprintf(thumb_use_str, sizeof(thumb_use_str), "LT: %d\nRT: %d   %dx%d\n",
  //         l_thumb, r_thumb, record->event.key.row, record->event.key.col);

  // update finger use log
  snprintf(finger_use_str, sizeof(finger_use_str), "LF: %d\nRF: %d\n",
           l_fingers, r_fingers);
}

void oled_render_keylog(void) {
    oled_write(keylog_str, false);
}

void oled_render_thumb_use_log(void) {
    oled_write(thumb_use_str, false);
}

void oled_render_finger_use_log(void) {
    oled_write(finger_use_str, false);
}

void oled_render_logo(void) {
    static const char PROGMEM crkbd_logo[] = {
        0x80, 0x81, 0x82, 0x83, 0x84, 0x85, 0x86, 0x87, 0x88, 0x89, 0x8a, 0x8b, 0x8c, 0x8d, 0x8e, 0x8f, 0x90, 0x91, 0x92, 0x93, 0x94,
        0xa0, 0xa1, 0xa2, 0xa3, 0xa4, 0xa5, 0xa6, 0xa7, 0xa8, 0xa9, 0xaa, 0xab, 0xac, 0xad, 0xae, 0xaf, 0xb0, 0xb1, 0xb2, 0xb3, 0xb4,
        0xc0, 0xc1, 0xc2, 0xc3, 0xc4, 0xc5, 0xc6, 0xc7, 0xc8, 0xc9, 0xca, 0xcb, 0xcc, 0xcd, 0xce, 0xcf, 0xd0, 0xd1, 0xd2, 0xd3, 0xd4,
        0};
    oled_write_P(crkbd_logo, false);
}

bool oled_task_user(void) {
    if (is_keyboard_master()) {
        oled_render_thumb_use_log();
        oled_render_finger_use_log();
        //oled_render_keylog();
    } else {
        // note: keyloggers and counters don't work on non-master side due to qmk limitations
        oled_render_logo();
        oled_scroll_left();
    }
    return false;
}

#endif
//-------------------------------


//-------------------------------
// custom keycodes and macros
// + process records
//-------------------------------

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch(keycode) {
    case KC_AT_SPECIAL:
        if (record->event.pressed) {
            layer_on(_NAV);
            register_code(KC_LALT);
            tap_code(KC_TAB);
        } else {
            unregister_code(KC_LALT);
            layer_off(_NAV);
        }
        break;

    case KC_AUTOCLOS_PAREN:
      if (record->event.pressed) {
          SEND_STRING("()" SS_TAP(X_LEFT));
      }
      break;

    case KC_AUTOCLOS_SQBRA:
      if (record->event.pressed) {
          SEND_STRING("[]" SS_TAP(X_LEFT));
      }
      break;

    case KC_AUTOCLOS_CURLYBRA:
      if (record->event.pressed) {
          SEND_STRING("{}" SS_TAP(X_LEFT));
      }
      break;

    case KC_AUTOCLOS_QUOTE:
      if (record->event.pressed) {
          SEND_STRING("\"\"" SS_TAP(X_LEFT));
      }
      break;

    case KC_DOTSPC:
      if (record->event.pressed) {
          tap_code(KC_DOT);
          tap_code(KC_SPC);
          set_oneshot_mods(MOD_BIT(KC_LSFT)); break;     // emulate OSM for Shift
      }
      break;

    case KC_FIFTEENSTARS:
      if (record->event.pressed) {
          SEND_STRING("*************** ");
      }
      break;

    case KC_TODO:
      if (record->event.pressed) {
          SEND_STRING("TODO ");
      }
      break;

    case KC_Q_QUOT:
      // intercepting hold-tap (see https://docs.qmk.fm/mod_tap#changing-tap-function and https://docs.qmk.fm/mod_tap#changing-hold-function)
      if (!record->tap.count && record->event.pressed) {
        tap_code16(S(KC_QUOT));  // send " on hold
        return false;      // Return false to ignore further processing of key
      }
      break;
  }

  // for OLED
#if defined(OLED_ENABLE)
  if (record->event.pressed) {
    set_keylog(keycode, record);
  }
#endif

return true;
}
