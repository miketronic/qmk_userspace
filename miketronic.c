// Copyright 2023 @miketronic -- Mike B <mxb540@gmail.com>
// SPDX-License-Identifier: GPL-2.0+

#include QMK_KEYBOARD_H
#include "miketronic.h"


// Add reconfigurable functions here, for keymap customization
// This allows for a global, userspace functions, and continued
// customization of the keymap.  Use _keymap instead of _user
// functions in the keymaps


/*

__attribute__ ((weak))
layer_state_t layer_state_set_keymap(layer_state_t state) {
  return state;
}

layer_state_t layer_state_set_user(layer_state_t state) {
    state = update_tri_layer_state(state, _LOWER, _RAISE, _ADJUST);
#ifdef CONSOLE_ENABLE
    uprintf("LAYER: %u\n", state);
#endif
    return state;
}

*/

__attribute__ ((weak))
bool process_record_keymap(uint16_t keycode, keyrecord_t *record) {
  return true;
}

__attribute__ ((weak))
bool process_record_secrets(uint16_t keycode, keyrecord_t *record) {
  return true;
}

// Init effect for RGB boards only
#ifdef RGB_MATRIX_ENABLE
void matrix_init_user(void) {
    rgb_matrix_mode_noeeprom(RGB_MATRIX_SOLID_COLOR);
}
#endif


// /////////////////
//
// Macro Definitions
//
// /////////////////

// Defines actions for my global custom keycodes. Defined in wanleg.h file
// Then runs the _keymap's record handier if not processed here

bool process_record_user(uint16_t keycode, keyrecord_t *record) {

  switch(keycode) {
    case WM:
      if (record->event.pressed) {
           set_single_persistent_default_layer(_WM);
               #if defined(RGBLIGHT_ENABLE)
	         rgblight_sethsv_noeeprom(HSV_WHITE);
               #endif
        } 
        return false;
        break;

     case QW:
       if (record->event.pressed) {
           set_single_persistent_default_layer(_QW);
               #if defined(RGBLIGHT_ENABLE)
	         rgblight_sethsv_noeeprom(HSV_MAGENTA);
               #endif
        }
        return false;
        break;

   case M01: 
        if (record->event.pressed) {
            SEND_STRING("//a11");
        }
	      break;
    
   case M02: 
        if (record->event.pressed) {
            SEND_STRING("//a12");
        }
	      break;

    case M03: 
        if (record->event.pressed) {
            SEND_STRING("//a08");
        }         
	      break;

    case M04: 
        if (record->event.pressed) {
            SEND_STRING("//a09");
        }
	      break;
    
    case M05: 
        if (record->event.pressed) {
            SEND_STRING("//th");
       }
	     break;
  
    case M06: 
        if (record->event.pressed) {
            SEND_STRING("//re");
      }
	    break;
    
    case M07: 
        if (record->event.pressed) {
	          SEND_STRING("//yw");
        }
	      break;
    
    case M08: 
        if (record->event.pressed) {
            tap_random_base64();
        }
	      break;

     #if defined(RGBLIGHT_ENABLE)
     case RGB1:
       if (record->event.pressed) {
	         rgblight_sethsv_noeeprom(HSV_BLUE);
      }
      break;

     case RGB2:
       if (record->event.pressed) {
	         rgblight_sethsv_noeeprom(HSV_RED);
      }
      break;

     case RGB3:
       if (record->event.pressed) {
	         rgblight_sethsv_noeeprom(HSV_ORANGE);
      }
      break; 

     case RGB4:
       if (record->event.pressed) {
	         rgblight_sethsv_noeeprom(HSV_YELLOW);
      }
      break;

     case RGB5:
       if (record->event.pressed) {
	         rgblight_sethsv_noeeprom(HSV_GREEN);
      }
      break;
      #endif
   }
   return true;
}




//#if defined(KEYBOARD_1upkeyboards_pi40_mit_v1_0) && defined(OLED_ENABLE)
#if defined(KEYBOARD_1k) && defined(OLED_ENABLE)


static uint32_t oled_logo_timer = 0;
static bool clear_logo = true;
static const char PROGMEM my_logo[] = {
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
        0xf0, 0xf0, 0xf0, 0xf0, 0xff, 0xff, 0xff, 0xff, 0x0f, 0x0f, 0x0f, 0x0f, 0x0f, 0x0f, 0x0f, 0x0f, 
        0xff, 0xff, 0xff, 0xff, 0x0f, 0x0f, 0x0f, 0x0f, 0xff, 0xff, 0xff, 0xff, 0x0f, 0x0f, 0x0f, 0x0f, 
        0x0f, 0x0f, 0x0f, 0x1f, 0xff, 0xff, 0xff, 0x1f, 0x0f, 0x0f, 0x0f, 0x0f, 0x0f, 0x0f, 0x0f, 0x0f, 
        0x0f, 0x0f, 0x0f, 0x0f, 0x0f, 0x0f, 0x0f, 0xf0, 0xf0, 0xf0, 0xf0, 0xf0, 0xf0, 0xf0, 0xf0, 0x00, 
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
        0xff, 0xff, 0xff, 0xff, 0xf0, 0xf0, 0xf0, 0xf0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
        0xff, 0xff, 0xff, 0xff, 0x00, 0x00, 0x00, 0x00, 0xff, 0xff, 0xff, 0xff, 0x00, 0x00, 0x00, 0x00, 
        0x00, 0x00, 0x00, 0x00, 0xff, 0xff, 0xff, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xff, 
        0xff, 0xff, 0xff, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xff, 0xff, 0xff, 0xff, 0x00, 
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
        0x00, 0x00, 0x00, 0x00, 0xff, 0xff, 0xff, 0xff, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
        0xff, 0xff, 0xff, 0xff, 0x00, 0x00, 0x00, 0x00, 0x0f, 0x0f, 0x0f, 0x0f, 0x00, 0x00, 0x00, 0x00, 
        0x00, 0x00, 0x00, 0x80, 0xff, 0xff, 0xff, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xf0, 
        0xf0, 0xf0, 0xf0, 0xf0, 0xf0, 0xf0, 0xf0, 0xff, 0xff, 0xff, 0xff, 0x0f, 0x0f, 0x0f, 0x0f, 0x00, 
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
        0x00, 0x00, 0x00, 0x00, 0xff, 0xff, 0xff, 0xff, 0xf0, 0xf0, 0xf0, 0xf0, 0xf0, 0xf0, 0xf0, 0xf0, 
        0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xf0, 0xf0, 0xf0, 0xf0, 0xf0, 0xf0, 0xf0, 0xfb, 
        0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xf8, 0xf0, 0xf0, 0xf0, 0xf0, 0xf0, 0xf0, 0xf0, 0xff, 
        0xff, 0xff, 0xff, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
    };

#endif

//#if defined(KEYBOARD_1upkeyboards_pi40_mit_v1_0) && defined(OLED_ENABLE)
#if defined(KEYBOARD_1k) && defined(OLED_ENABLE)

void init_timer(void){
   oled_logo_timer = timer_read32();
};

void user_oled_magic(void) {
    // Host Keyboard Layer Status
    oled_write_P(PSTR("Layer: "), false);

    switch (get_highest_layer(layer_state)) {
        case 0:
            oled_write_P(PSTR("One\n"), false);
            break;
        case 1:
            oled_write_P(PSTR("Two\n"), false);
            break;
        case 2:
            oled_write_P(PSTR("Three\n"), false);
            break;
        case 3:
            oled_write_P(PSTR("Four\n"), false);
            break;
        case 4:
            oled_write_P(PSTR("Five\n"), false);
            break;
        case 5:
            oled_write_P(PSTR("Six\n"), false);
            break;
        case 6:
            oled_write_P(PSTR("Seven\n"), false);
            break;
        case 7:
            oled_write_P(PSTR("Eight\n"), false);
            break;
        case 8:
            oled_write_P(PSTR("Nine\n"), false);
            break;
        case 9:
            oled_write_P(PSTR("Ten\n"), false);
            break;
        default:
            // Or use the write_ln shortcut over adding '\n' to the end of your string
            oled_write_ln_P(PSTR("Undefined"), false);
    }

    // Host Keyboard LED Status
    led_t led_state = host_keyboard_led_state();
    oled_write_P(led_state.caps_lock ? PSTR("Cap(x) ") : PSTR("Cap( ) "), false);
    oled_write_P(led_state.num_lock ? PSTR("Num(x) ") : PSTR("Num( ) "), false);
    oled_write_P(led_state.scroll_lock ? PSTR("Scrl(x)") : PSTR("Scrl( )"), false);


    switch (rgb_matrix_get_mode()) {
        case 1:
            oled_write_P(PSTR("Solid Color\n                  "), false);
            break;
        case 2:
            oled_write_P(PSTR("Alphas Mods\n                  "), false);
            break;
        case 3:
            oled_write_P(PSTR("Gradient Up Down\n                  "), false);
            break;
        case 4:
            oled_write_P(PSTR("Gradient Left Right\n                  "), false);
            break;
        case 5:
            oled_write_P(PSTR("Breathing\n                  "), false);
            break;
        case 6:
            oled_write_P(PSTR("Band Sat\n                  "), false);
            break;
        case 7:
            oled_write_P(PSTR("Band Val\n                  "), false);
            break;
        case 8:
            oled_write_P(PSTR("Band Pinwheel Sat\n                  "), false);
            break;
        case 9:
            oled_write_P(PSTR("Band Pinwheel Val\n                  "), false);
            break;
        case 10:
            oled_write_P(PSTR("Band Spiral Sat\n                  "), false);
            break;
        case 11:
            oled_write_P(PSTR("Band Spiral Val\n                  "), false);
            break;
        case 12:
            oled_write_P(PSTR("Cycle All\n                  "), false);
            break;
        case 13:
            oled_write_P(PSTR("Cycle Left Right\n                  "), false);
            break;
        case 14:
            oled_write_P(PSTR("Cycle Up Down\n                  "), false);
            break;
        case 15:
            oled_write_P(PSTR("Rainbow\nMoving Chevron    "), false);
            break;
        case 16:
            oled_write_P(PSTR("Cycle Out In\n                  "), false);
            break;
        case 17:
            oled_write_P(PSTR("Cycle Out In Dual\n                  "), false);
            break;
        case 18:
            oled_write_P(PSTR("Cycle Pinwheel\n                  "), false);
            break;
        case 19:
            oled_write_P(PSTR("Cycle Spiral\n                  "), false);
            break;
        case 20:
            oled_write_P(PSTR("Dual Beacon\n                  "), false);
            break;
        case 21:
            oled_write_P(PSTR("Rainbow Beacon\n                  "), false);
            break;
        case 22:
            oled_write_P(PSTR("Rainbow Pinwheels\n                  "), false);
            break;
        case 23:
            oled_write_P(PSTR("Raindrops\n                  "), false);
            break;
        case 24:
            oled_write_P(PSTR("Jellybean Raindrops\n                  "), false);
            break;
        case 25:
            oled_write_P(PSTR("Hue Breathing\n                  "), false);
            break;
        case 26:
            oled_write_P(PSTR("Hue Pendulum\n                  "), false);
            break;
        case 27:
            oled_write_P(PSTR("Hue Wave\n                  "), false);
            break;
        case 28:
            oled_write_P(PSTR("Pixel Rain\n                  "), false);
            break;
        case 29:
            oled_write_P(PSTR("Pixel Flow\n                  "), false);
            break;
        case 30:
            oled_write_P(PSTR("Pixel Fractal\n                  "), false);
            break;
        case 31:
            oled_write_P(PSTR("Typing Heatmap\n                  "), false);
            break;
        case 32:
            oled_write_P(PSTR("Digital Rain\n                  "), false);
            break;
        case 33:
            oled_write_P(PSTR("Solid Reactive\nSimple            "), false);
            break;
        case 34:
            oled_write_P(PSTR("Solid Reactive\n                  "), false);
            break;
        case 35:
            oled_write_P(PSTR("Solid Reactive\nWide              "), false);
            break;
        case 36:
            oled_write_P(PSTR("Solid Reactive\nMultiwide         "), false);
            break;
        case 37:
            oled_write_P(PSTR("Solid Reactive\nCross             "), false);
            break;
        case 38:
            oled_write_P(PSTR("Solid Reactive\nMulticross        "), false);
            break;
        case 39:
            oled_write_P(PSTR("Solid Reactive\nNexus             "), false);
            break;
        case 40:
            oled_write_P(PSTR("Solid Reactive\nMultinexus        "), false);
            break;
        case 41:
            oled_write_P(PSTR("Splash\n                  "), false);
            break;
        case 42:
            oled_write_P(PSTR("Multisplash\n                  "), false);
            break;
        case 43:
            oled_write_P(PSTR("Solid Splash\n                  "), false);
            break;
        case 44:
            oled_write_P(PSTR("Solid Multisplash\n                  "), false);
            break;
        default:
            // Or use the write_ln shortcut over adding '\n' to the end of your string
            oled_write_ln_P(PSTR("Undefined\n                  "), false);
    }

}

void render_logo(void) {
    oled_write_raw_P(my_logo, sizeof(my_logo));
}

void clear_screen(void) {
    if (clear_logo){
      for (uint8_t i = 0; i < OLED_DISPLAY_HEIGHT; ++i) {
        for (uint8_t j = 0; j < OLED_DISPLAY_WIDTH; ++j) {
          oled_write_raw_byte(0x0, i*OLED_DISPLAY_WIDTH + j);
        }
      }
      clear_logo = false;
    }
}

oled_rotation_t oled_init_kb(oled_rotation_t rotation) {
    return OLED_ROTATION_180;
}

void keyboard_post_init_kb(void) {
    init_timer();

    keyboard_post_init_user();
}

#    define SHOW_LOGO 5000
bool oled_task_kb(void) {
    if (!oled_task_user()) { return false; }
    if ((timer_elapsed32(oled_logo_timer) < SHOW_LOGO)){
        render_logo();
    }else{
      clear_screen();
      user_oled_magic();
    }
    return false;
}

#endif



