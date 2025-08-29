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
        case LGUI_T(KC_QUOT):
            return 300;
        case LALT_T(KC_R):
            return 300;
        case LALT_T(KC_I):
            return 300;
        case LALT_T(KC_S):
            return 300;
        case LALT_T(KC_L):
            return 300;
        case LT(_NAV,KC_SPC):
            return 200;
        case LT(_FUN,KC_M):
            return 300;
        case LT(_NUM,KC_N):
            return 240;
        default:
            return TAPPING_TERM;
    }
}

uint16_t get_quick_tap_term(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case LT(_NUM,KC_N):
            return 0;
        case LT(_FUN,KC_M):
            return 0;
        case LT(_NAV,KC_SPC):
            return 0;
        default:
            return QUICK_TAP_TERM;
    }
}
//---


//-------------------------------
//--- combos
//-------------------------------

#ifdef COMBO_ENABLE
enum combos {
    FG_ATAB,
    JKL_ENT,
};
const uint16_t PROGMEM fg_combo[] = {LSFT_T(KC_F), KC_G, COMBO_END};
const uint16_t PROGMEM jkl_combo[] = {LSFT_T(KC_J), LCTL_T(KC_K), LALT_T(KC_L), COMBO_END};
combo_t key_combos[] = {
  [JKL_ENT] = COMBO(jkl_combo, KC_ENT),
  [FG_ATAB] = COMBO_ACTION(fg_combo),  // see process_combo_event and release functions below
};
#endif
//---

//--- OLED (for crkbd)
#if defined(OLED_ENABLE)

int r_thumb = 0;
int l_thumb = 0;
int r_reachy = 0;
int l_reachy = 0;
int r_tucky = 0;
int l_tucky = 0;
int r_extra = 0;
int l_extra = 0;
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
char lthumb_use_str[24] = {};
char rthumb_use_str[24] = {};
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
      if (record->event.key.col == 5){
          r_reachy++;
      }
      else if (record->event.key.col == 4){
          r_tucky++;
      }
      else {
          r_extra++;
      }
  }
  // Check if row is equal to 3 (left thumb was used) and increment counter
  else if (record->event.key.row == 3) {
      l_thumb++;
      if (record->event.key.col == 5){
          l_reachy++;
      }
      else if (record->event.key.col == 4){
          l_tucky++;
      }
      else {
          l_extra++;
      }
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
  snprintf(lthumb_use_str, sizeof(lthumb_use_str), "%d,%d,%d|",
           l_extra, l_tucky, l_reachy);
  snprintf(rthumb_use_str, sizeof(rthumb_use_str), "%d,%d,%d\n",
           r_reachy, r_tucky, r_extra);
  //snprintf(thumb_use_str, sizeof(thumb_use_str), "%d %d %d %d;\n%d %d",
  //         l_tucky, l_reachy, r_reachy, r_tucky, l_extra, r_extra);

  // update finger use log
  snprintf(finger_use_str, sizeof(finger_use_str), "%d|%d\n",
           l_fingers, r_fingers);
}

void oled_render_keylog(void) {
    oled_write(keylog_str, false);
}

void oled_render_finger_use_log(void) {
    oled_write(finger_use_str, false);
}

void oled_render_lthumb_use_log(void) {
    oled_write(lthumb_use_str, false);
}
void oled_render_rthumb_use_log(void) {
    oled_write(rthumb_use_str, false);
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
        oled_render_finger_use_log();
        oled_render_lthumb_use_log();
        oled_render_rthumb_use_log();
        //oled_render_keylog();
        // Layer Status
        oled_write_P(PSTR("Layer: "), false);
        switch (get_highest_layer(layer_state)) {
            case _QWERTY:
                oled_write_P(PSTR("QWERTY\n"), false);
                break;
            case _NUM:
                oled_write_P(PSTR("NUM\n"), false);
                break;
            case _NAV:
                oled_write_P(PSTR("NAV\n"), false);
                break;
            case _MACRO:
                oled_write_P(PSTR("MACRO\n"), false);
                break;
            case _FUN:
                oled_write_P(PSTR("FUN\n"), false);
                break;
            default:
                // Or use the write_ln shortcut over adding '\n' to the end of your string
                oled_write_ln_P(PSTR("Undefined"), false);
        }
        // Caps Status; FIXME: after the first time caps is pressed "CAPS LOCK" stays on and does not turn off
        //led_t led_state = host_keyboard_led_state();
        //oled_write_P(led_state.caps_lock ? PSTR("CAPS LOCK") : PSTR(""), false);
    } else {
        // note: keyloggers and counters don't work on non-master side due to qmk limitations
        oled_render_logo();
        oled_scroll_left();
    }
    return false;
}

#endif
//-------------------------------

// caps word config
bool caps_word_press_user(uint16_t keycode) {
    switch (keycode) {
        // Keycodes that continue Caps Word, with shift applied.
        case KC_A ... KC_Z:
            add_weak_mods(MOD_BIT(KC_LSFT));  // Apply shift to next key.
            return true;

        // Keycodes that continue Caps Word, without shifting.
        case KC_1 ... KC_0:
        case KC_BSPC:
        case KC_DEL:
        case KC_UNDS:
        case KC_MINS:
            return true;

        default:
            return false;  // Deactivate Caps Word.
    }
}


//-------------------------------
// custom keycodes and macros
// + process records
//-------------------------------

void process_combo_event(uint16_t combo_index, bool pressed) {
  switch(combo_index) {
    case FG_ATAB:
      if (pressed) {
        layer_on(_NAV);
        register_code(KC_LALT);
        tap_code(KC_TAB);
      }
      break;
  }
}

bool process_combo_key_release(uint16_t combo_index, combo_t *combo, uint8_t key_index, uint16_t keycode) {
    switch (combo_index) {
        case FG_ATAB:
            switch(keycode) {
                case LSFT_T(KC_F):
                    unregister_code(KC_LALT);
                    layer_off(_NAV);
                    break;
                case KC_G:
                    // do nothing so this finger can keep hitting TAB while ALT remains pressed
                    break;
            }
            return false; // do not release combo
    }
    return false;
}

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

    case KC_TH:
      if (record->event.pressed) {
          SEND_STRING("th");
      }
      break;

    case KC_QU:
      if (record->event.pressed) {
          SEND_STRING("qu");
      }
      break;

    case KC_R_ASSIGN:
      if (record->event.pressed) {
          SEND_STRING("<-");
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

    case KC_Q_EXCL:
      // intercepting hold-tap (see https://docs.qmk.fm/mod_tap#changing-tap-function and https://docs.qmk.fm/mod_tap#changing-hold-function)
      if (!record->tap.count && record->event.pressed) {
        tap_code16(S(KC_1));  // send ! on hold
        return false;      // Return false to ignore further processing of key
      }
      break;

    case KC_Z_LPRN:
      // intercepting hold-tap (see https://docs.qmk.fm/mod_tap#changing-tap-function and https://docs.qmk.fm/mod_tap#changing-hold-function)
      if (!record->tap.count && record->event.pressed) {
        tap_code16(S(KC_9));  // send ( on hold
        return false;      // Return false to ignore further processing of key
      }
      break;

    case KC_V_RPRN:
      // intercepting hold-tap (see https://docs.qmk.fm/mod_tap#changing-tap-function and https://docs.qmk.fm/mod_tap#changing-hold-function)
      if (!record->tap.count && record->event.pressed) {
        tap_code16(S(KC_0));  // send ) on hold
        return false;      // Return false to ignore further processing of key
      }
      break;

    case LSFT_T(KC_4):
        if (record->tap.count && record->event.pressed) {
            tap_code16(S(KC_4)); // Send $ on tap
            return false;        // Return false to ignore further processing of key
        }
        break;

    case LCTL_T(KC_5):
        if (record->tap.count && record->event.pressed) {
            tap_code16(S(KC_5)); // Send % on tap
            return false;        // Return false to ignore further processing of key
        }
        break;

    case LALT_T(KC_6):
        if (record->tap.count && record->event.pressed) {
            tap_code16(S(KC_6)); // Send ^ on tap
            return false;        // Return false to ignore further processing of key
        }
        break;

    case LGUI_T(KC_0):
        if (record->tap.count && record->event.pressed) {
            tap_code16(S(KC_0)); // Send ) on tap
            return false;        // Return false to ignore further processing of key
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
