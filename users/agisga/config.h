// For homerow mods
#undef TAPPING_TERM
#define TAPPING_TERM 250
#define TAPPING_TERM_PER_KEY  /* Use per key tapping term */

// Combos
#define COMBO_ONLY_FROM_LAYER 0
#ifdef COMBO_ENABLE
  #undef COMBO_TERM
  #define COMBO_TERM 20
  #define EXTRA_SHORT_COMBOS
#endif
#define COMBO_PROCESS_KEY_RELEASE

// Enable rapid switch from tap to hold, disables double tap hold auto-repeat
#define QUICK_TAP_TERM 0

// Auto Shift
#define NO_AUTO_SHIFT_ALPHA
#define AUTO_SHIFT_TIMEOUT 200
#define AUTO_SHIFT_NO_SETUP

// Mouse key speed and acceleration
#undef MOUSEKEY_DELAY
#define MOUSEKEY_DELAY          0
#undef MOUSEKEY_INTERVAL
#define MOUSEKEY_INTERVAL       16
#undef MOUSEKEY_WHEEL_DELAY
#define MOUSEKEY_WHEEL_DELAY    0
#undef MOUSEKEY_MAX_SPEED
#define MOUSEKEY_MAX_SPEED      6
#undef MOUSEKEY_TIME_TO_MAX
#define MOUSEKEY_TIME_TO_MAX    64

// One-shot keys
#define ONESHOT_TIMEOUT 1500  /* Time (in ms) before the one shot key is released */
