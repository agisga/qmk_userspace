#pragma once

#ifdef CONVERT_TO_BLOK
    // boardsource BLOK code

    #define EE_HANDS

    // RGB stuff
    #define RGBLIGHT_SPLIT
    //#define RGB_MATRIX_ENABLE  // FIXME: for some reason RGB_MATRIX_ENABLE doesn't work when enabled from here, but only works when enabled from rules.mk
#else
    // Pro Micro code, no RGB

    // For some reason this is needed to make the keyboard halves communicate when WS-C controllers are used (Elite-C clones?)
    #define SPLIT_USB_DETECT

    // #define MASTER_LEFT
    // #define MASTER_RIGHT
    #define EE_HANDS
#endif

//--- per-key RGB settings ---
// based on davidrambo/config.h

#ifdef RGB_MATRIX_ENABLE
    #define RGB_MATRIX_STARTUP_HUE 231
    #define RGB_MATRIX_KEYPRESSES // reacts to keypresses
    #define RGB_MATRIX_TYPING_HEATMAP_DECREASE_DELAY_MS 175
    #define RGB_MATRIX_TYPING_HEATMAP_SPREAD 20
    // #   define RGB_MATRIX_KEYRELEASES // reacts to keyreleases (instead of keypresses)
    // #   define RGB_DISABLE_AFTER_TIMEOUT 0 // number of ticks to wait until disabling effects
    #define RGB_DISABLE_WHEN_USB_SUSPENDED  // turn off effects when suspended
    #define RGB_MATRIX_FRAMEBUFFER_EFFECTS
    // #   define RGB_MATRIX_LED_PROCESS_LIMIT (DRIVER_LED_TOTAL + 4) / 5 // limits the number of LEDs to process in an animation per task run (increases keyboard responsiveness)
    // #   define RGB_MATRIX_LED_FLUSH_LIMIT 16 // limits in milliseconds how frequently an animation will update the LEDs. 16 (16ms) is equivalent to limiting to 60fps (increases keyboard responsiveness)
    #define RGB_MATRIX_MAXIMUM_BRIGHTNESS 100 // limits maximum brightness of LEDs to 150 out of 255. Higher may cause the controller to crash.
    #define RGB_MATRIX_HUE_STEP 8
    #define RGB_MATRIX_SAT_STEP 8
    #define RGB_MATRIX_VAL_STEP 8
    #define RGB_MATRIX_SPD_STEP 10

    /* Disable the animations you don't want/need.  You will need to disable a good number of these    *
     * because they take up a lot of space.  Disable until you can successfully compile your firmware. */
    //#define DISABLE_RGB_MATRIX_ALPHAS_MODS
    //#define DISABLE_RGB_MATRIX_GRADIENT_UP_DOWN
    ////#define DISABLE_RGB_MATRIX_BREATHING
    //#define DISABLE_RGB_MATRIX_CYCLE_ALL
    //#define DISABLE_RGB_MATRIX_CYCLE_LEFT_RIGHT
    //#define DISABLE_RGB_MATRIX_CYCLE_UP_DOWN
    //#define DISABLE_RGB_MATRIX_CYCLE_OUT_IN
    //#define DISABLE_RGB_MATRIX_CYCLE_OUT_IN_DUAL
    //#define DISABLE_RGB_MATRIX_RAINBOW_MOVING_CHEVRON
    //#define DISABLE_RGB_MATRIX_DUAL_BEACON
    ////#define DISABLE_RGB_MATRIX_RAINBOW_BEACON
    //#define DISABLE_RGB_MATRIX_RAINBOW_PINWHEELS
    ////#define DISABLE_RGB_MATRIX_RAINDROPS
    //#define DISABLE_RGB_MATRIX_JELLYBEAN_RAINDROPS
    ////#define DISABLE_RGB_MATRIX_TYPING_HEATMAP
    //#define DISABLE_RGB_MATRIX_DIGITAL_RAIN
    //#define DISABLE_RGB_MATRIX_SOLID_REACTIVE
    //#define DISABLE_RGB_MATRIX_SOLID_REACTIVE_SIMPLE
    //#define DISABLE_RGB_MATRIX_SOLID_REACTIVE_WIDE
    //#define DISABLE_RGB_MATRIX_SOLID_REACTIVE_MULTIWIDE
    //#define DISABLE_RGB_MATRIX_SOLID_REACTIVE_CROSS
    //#define DISABLE_RGB_MATRIX_SOLID_REACTIVE_MULTICROSS
    //#define DISABLE_RGB_MATRIX_SOLID_REACTIVE_NEXUS
    //#define DISABLE_RGB_MATRIX_SOLID_REACTIVE_MULTINEXUS
    //#define DISABLE_RGB_MATRIX_SPLASH
    //#define DISABLE_RGB_MATRIX_MULTISPLASH
    //#define DISABLE_RGB_MATRIX_SOLID_SPLASH
    //#define DISABLE_RGB_MATRIX_SOLID_MULTISPLASH
//
//    #define ENABLE_RGB_MATRIX_TYPING_HEATMAP
//    #define ENABLE_RGB_MATRIX_BREATHING
//    #define ENABLE_RGB_MATRIX_RAINBOW_BEACON
//    #define ENABLE_RGB_MATRIX_RAINDROPS

    #define ENABLE_RGB_MATRIX_ALPHAS_MODS
    #define ENABLE_RGB_MATRIX_GRADIENT_UP_DOWN
    #define ENABLE_RGB_MATRIX_BREATHING
    #define ENABLE_RGB_MATRIX_CYCLE_ALL
    #define ENABLE_RGB_MATRIX_CYCLE_LEFT_RIGHT
    #define ENABLE_RGB_MATRIX_CYCLE_UP_DOWN
    #define ENABLE_RGB_MATRIX_CYCLE_OUT_IN
    #define ENABLE_RGB_MATRIX_CYCLE_OUT_IN_DUAL
    #define ENABLE_RGB_MATRIX_RAINBOW_MOVING_CHEVRON
    #define ENABLE_RGB_MATRIX_DUAL_BEACON
    #define ENABLE_RGB_MATRIX_RAINBOW_BEACON
    #define ENABLE_RGB_MATRIX_RAINBOW_PINWHEELS
    #define ENABLE_RGB_MATRIX_RAINDROPS
    #define ENABLE_RGB_MATRIX_JELLYBEAN_RAINDROPS
    #define ENABLE_RGB_MATRIX_TYPING_HEATMAP
    #define ENABLE_RGB_MATRIX_DIGITAL_RAIN
    #define ENABLE_RGB_MATRIX_SOLID_REACTIVE
    #define ENABLE_RGB_MATRIX_SOLID_REACTIVE_SIMPLE
    #define ENABLE_RGB_MATRIX_SOLID_REACTIVE_WIDE
    #define ENABLE_RGB_MATRIX_SOLID_REACTIVE_MULTIWIDE
    #define ENABLE_RGB_MATRIX_SOLID_REACTIVE_CROSS
    #define ENABLE_RGB_MATRIX_SOLID_REACTIVE_MULTICROSS
    #define ENABLE_RGB_MATRIX_SOLID_REACTIVE_NEXUS
    #define ENABLE_RGB_MATRIX_SOLID_REACTIVE_MULTINEXUS
    #define ENABLE_RGB_MATRIX_SPLASH
    #define ENABLE_RGB_MATRIX_MULTISPLASH
    #define ENABLE_RGB_MATRIX_SOLID_SPLASH
    #define ENABLE_RGB_MATRIX_SOLID_MULTISPLASH
#endif

// OLED
#if defined(OLED_ENABLE)
  #define OLED_FONT_H "keyboards/crkbd/lib/glcdfont.c"
#endif
