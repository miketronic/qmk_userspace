//   https://docs.qmk.fm/#/feature_tap_dance

#include "miketronic.h"

tap_dance_action_t tap_dance_actions[] = {
  [TD_BRC]     = ACTION_TAP_DANCE_DOUBLE(KC_LBRC, KC_RBRC), 		            // Tap once for Left Brace, twice for Right Brace
  [TD_MIN]     = ACTION_TAP_DANCE_DOUBLE(KC_MINUS, KC_EQUAL),		    // Tap once for Minus, twice for Equal
  [UMIN]  = ACTION_TAP_DANCE_DOUBLE(KC_UNDS, KC_MINS),	       // Tap once for Underscore, twice for Minus
  [TD_GV_ESC]  = ACTION_TAP_DANCE_DOUBLE(KC_GRAVE, KC_ESCAPE),	        // Tap once for Grave, tap twice for Escape
  [TD_SPENTR]  = ACTION_TAP_DANCE_DOUBLE(KC_SPC, KC_ENT), 		            // Tap once for space, twice for enter
  [TD_MULTDIV] = ACTION_TAP_DANCE_DOUBLE(KC_PAST, KC_PSLS),  		        // Tap once for Multiply, twice for Divide
  [UR]       = ACTION_TAP_DANCE_DOUBLE(KC_UP, KC_RGHT),			            // Tap once for Up, twice for Right
  [DL]    = ACTION_TAP_DANCE_DOUBLE(KC_DOWN, KC_LEFT),		            // Tap once for Down, twice for Left
  [CPYPST]  = ACTION_TAP_DANCE_DOUBLE(LCTL(KC_C), LCTL(KC_V)),        // Tap once for Copy, twice for Paste
  [DOTENT]  = ACTION_TAP_DANCE_DOUBLE(KC_DOT, KC_ENT),                // Tap once for dot, twice for enter
  [IENT]    = ACTION_TAP_DANCE_DOUBLE(KC_I, KC_ENT),                    // Tap once for I, twice for enter
  [CSPC]    = ACTION_TAP_DANCE_DOUBLE(KC_SPC, KC_COMM),              // Tap once for space, twice for comm
  [DSPC]    = ACTION_TAP_DANCE_DOUBLE(KC_SPC, KC_DOT),                // Tap once for space, twice for dot
  [QEXC]    = ACTION_TAP_DANCE_DOUBLE(KC_QUES, KC_EXLM),                // Tap once for ?, twice for !  
  [QESC]     = ACTION_TAP_DANCE_DOUBLE(KC_Q, KC_ESC),               // Tap once for "q", twice for escape 
  [TE]      = ACTION_TAP_DANCE_DOUBLE(KC_TAB, KC_ESC),                    // Tap once for tab, twice for esc
  [T20]      = ACTION_TAP_DANCE_DOUBLE(KC_2, KC_0),                        // Tap once for 2, twice for 0
  [SL]      = ACTION_TAP_DANCE_DOUBLE(KC_SLSH, KC_BSLS),
  [XX]      = ACTION_TAP_DANCE_DOUBLE(KC_LPRN, KC_RPRN),		
  [YY]      = ACTION_TAP_DANCE_DOUBLE(KC_LBRC, KC_RBRC),		
  [ATH]     = ACTION_TAP_DANCE_DOUBLE(KC_AT, KC_HASH),	
  [PRAM]    = ACTION_TAP_DANCE_DOUBLE(KC_PERC, KC_AMPR),
  [SBAK]     = ACTION_TAP_DANCE_DOUBLE(KC_BSPC, KC_SCLN),	             // Tap once for backspace, twice for semicolon
};

//In Layer declaration, add tap dance item in place of a key code
//TD(TD_SFT_CAPS)
