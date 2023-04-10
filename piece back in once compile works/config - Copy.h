// Copyright 2023 Mike Barnoski mikebarnoski@gmail.com (@miketronic)
// SPDX-License-Identifier: GPL-2.0+

#include "layouts.h"

#pragma once

// specific defines example
// #if defined(TAP_DANCE_ENABLE) && defined(KEYBOARD_lets_split_rev2) || defined(KEYBOARD_keebio_iris_rev2)



// Common QMK settings
#define DEBOUNCE 10
#define TAP_CODE_DELAY 5
#define TAP_HOLD_CAPS_DELAY 25




//audio clicky
  //#define AUDIO_CLICKY
  // to enable clicky on startup
  //#define AUDIO_CLICKY_ON
  //#define AUDIO_CLICKY_FREQ_RANDOMNESS 1.0f

//ws2812 RGB LED
  //#define RGB_DI_PIN B5
  //#define RGBLED_NUM 8     // Number of LEDs
  //#define RGBLIGHT_HUE_STEP 10
  //#define RGBLIGHT_SAT_STEP 17



//rgb-reactive
//#define RGB_MATRIX_KEYPRESSES
//#define EECONFIG_RGB_MATRIX (uint32_t *)16

//skip usb startup check
//#define NO_USB_STARTUP_CHECK


// Most tactile encoders have detents every 4 stages
#define ENCODER_RESOLUTION 4




//////////////
// For Pi40 //
//////////////
#if defined(KEYBOARD_1upkeyboards_pi40_mit_v1_0)

// Tapping Config
// https://docs.qmk.fm/#/tap_hold?id=tapping_term
// https://docs.qmk.fm/#/ChangeLog/20230226?id=quick-tap-term

// Tap-hold settings
#define TAPPING_TERM 170
#define TAPPING_TERM_PER_KEY
#define QUICK_TAP_TERM TAPPING_TERM / 2
#define QUICK_TAP_TERM_PER_KEY
#define PERMISSIVE_HOLD_PER_KEY
#define HOLD_ON_OTHER_KEY_PRESS_PER_KEY




#endif





////////////////
// For SATPAD //
////////////////
#if defined(KEYBOARD_jasonhazel_satpad)

// bootloader (first top leftmost key)
#define BOOTMAGIC_LITE_ROW 0
#define BOOTMAGIC_LITE_COLUMN 1

#define MATRIX_ROWS 7
#define MATRIX_COLS 6

#define MATRIX_ROW_PINS { B3, B2, B6, D3, D2, D4, E6 }
#define MATRIX_COL_PINS { F4, F5, F6, F7, B1, D7 }

#define DIODE_DIRECTION COL2ROW

#define DEBOUNCE 5

#define ENCODERS_PAD_A {B4}
#define ENCODERS_PAD_B {B5}




// Behaviors That Can Be Configured


#define TAPPING_TERM 175
        // how long before a tap becomes a hold, if set above 500, a key tapped during the tapping term will turn it into a hold too

#undef PERMISSIVE_HOLD
       // makes tap and hold keys trigger the hold if another key is pressed before releasing, even if it hasn't hit the TAPPING_TERM

#define IGNORE_MOD_TAP_INTERRUPT
        // makes it possible to do rolling combos (zx) with keys that convert to other keys on hold, by enforcing the TAPPING_TERM for both keys.

#define TAPPING_FORCE_HOLD
        // makes it possible to use a dual role key as modifier shortly after having been tapped (see Hold after tap)
        // Breaks any Tap Toggle functionality (TT or the One Shot Tap Toggle)


/*
    #define TAPPING_TERM_PER_KEY
        // enables handling for per key TAPPING_TERM settings
    
    #define RETRO_TAPPING
        // tap anyway, even after TAPPING_TERM, if there was no other key interruption between press and release
    
    #define TAPPING_TOGGLE 2
        // how many taps before triggering the toggle
    
    #define LEADER_TIMEOUT 300
        // how long before the leader key times out
        // If you're having issues finishing the sequence before it times out, you may need to increase the timeout setting. Or you may want to enable the LEADER_PER_KEY_TIMING option, which resets the timeout after each key is tapped.
    
    #define LEADER_PER_KEY_TIMING
        // sets the timer for leader key chords to run on each key press rather than overall
    
    #define LEADER_KEY_STRICT_KEY_PROCESSING
        // Disables keycode filtering for Mod-Tap and Layer-Tap keycodes. Eg, if you enable this, you would need to specify MT(MOD_CTL, KC_A) if you want to use KC_A.
    
    #define ONESHOT_TIMEOUT 300
        // how long before oneshot times out
    
    #define ONESHOT_TAP_TOGGLE 2
        // how many taps before oneshot toggle is triggered
    
    #define COMBO_COUNT 2
        // Set this to the number of combos that you're using in the Combo feature.
    
    #define COMBO_TERM 200
        // how long for the Combo keys to be detected. Defaults to TAPPING_TERM if not defined.
    
    #define TAP_CODE_DELAY 100
        // Sets the delay between register_code and unregister_code, if you're having issues with it registering properly (common on VUSB boards). The value is in milliseconds.
    
    #define TAP_HOLD_CAPS_DELAY 80
        // Sets the delay for Tap Hold keys (LT, MT) when using KC_CAPS_LOCK keycode, as this has some special handling on MacOS. The value is in milliseconds, and defaults to 80 ms if not defined. For macOS, you may want to set this to 200 or higher.
*/
#endif



