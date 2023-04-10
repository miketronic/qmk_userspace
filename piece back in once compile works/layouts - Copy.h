// Copyright 2023 Mike Barnoski mikebarnoski@gmail.com (@miketronic)
// SPDX-License-Identifier: GPL-2.0+


// https://www.reddit.com/r/olkb/comments/fpm7ev/qmk_user_space_help/

#pragma once

#include "quantum/keycodes.h"



// Define layer names and order
#ifdef KEYBOARD_1upkeyboards_pi40_mit_v1_0
enum userspace_layers {
  _WM,       // Workman
  _QW,       // QWERTY
  _FN,
  _EX,
  _LOWER,
  _RAISE,
  _SYMBOLS
};
#elif KEYBOARD_jasonhazel_satpad
enum userspace_layers {
  _WM,                //Workman
  _QW,                //Qwerty
  _FN,                //Function
  _EX,                //Extras
  _LOWER,             //Lower
  _RAISE,             //Raise
  _ADJUST,            //Adjust
  _SYMBOLS
};
#else 
enum userspace_layers {
  _WM,                //Workman
  _QW,                //Qwerty
  _FN,                //Function
  _EX,                //Extras
  _LOWER,             //Lower
  _RAISE,             //Raise
  _ADJUST,            //Adjust
  _SYMBOLS
};
#endif

enum userspace_custom_keycodes {
  WM = QK_USER,
  QW,
  M01,
  M02,
  M03,
  M04,
  M05,
  M06, 
  M07,
  M08,
  M09,
  M10,
  M11, 
  M12,
  RGB1,
  RGB2,	
  RGB3,
  RGB4,
  RGB5
};

//Tap Dance Declarations (list of my tap dance configurations)
#ifdef TAP_DANCE_ENABLE
enum {
  TD_BRC = 0,
  TD_MIN,
  UMIN,
  TD_GV_ESC,
  TD_BS,
  TD_SPENTR,     // space, enter
  TD_MULTDIV,    // multiply, divide
  UR,          // up, right
  DL,       // down, left
  CPYPST,     // copy, paste
  DOTENT,     // dot, enter
  IENT,       // I, enter 
  CSPC,       // space, comma
  DSPC,        // space, dot
  QEXC,        // Tap once for ?, twice for !
  QESC,        // Tap once for "q", twice for escape
  TE,         // Tap once for tab, twice for esc
  T20,         // Tap once for 2, twice for 0
  SL,         // slash, backslash
  XX,	 
  YY,	 
  ATH,        // Tap once for @, twice for # 
  PRAM,	     // Tap once for %, twice for & 
  SBAK,    // Tap once for semicolon, twice for backspace
};
#endif


/* ==========================================================================
    CUSTOM KEYS
   ========================================================================== */

// Tap dances
#define TD_ESCP TD(TD_GV_ESC)           // Tap for grave, twice for escape
#define TD_MINS TD(TD_MIN)              // Tap for minus, twice for equal
#define T_UMIN  TD(UMIN)           // Tap for underscore, twice for minus
#define TD_BRAC TD(TD_BRC)              // Tap for open brace, twice for close
#define T_SE    TD(TD_SPENTR)           // Tap once for space, twice for enter
#define TD_MD   TD(TD_MULTDIV)          // Tap once for Multiply, twice for Divide
#define T_UR	TD(UR)		        // Tap once for Up, twice for Right
#define T_DL	TD(DL)		        // Tap once for Down, twice for Left
#define T_CP    TD(CPYPST)           // Tap once for Copy, twice for Paste
#define T_DENT  TD(DOTENT)           // Tap once for Dot, twice for Enter
#define T_DSPC  TD(DSPC)           // Tap once for Space, twice for Dot
#define T_QEXC  TD(QEXC)             // Tap once for ?, twice for !
#define T_QESC  TD(QESC)             // Tap once for "q", twice for escape
#define T_TE    TD(TE)               // Tap once for tab, twice for esc
#define T_XX    TD(XX)		// Tap once for open paren, twice for closed paren
#define T_YY    TD(YY)		// Tap once for open brace, twice for closed brace
#define T_CSPC  TD(CSPC)		// Tap once for space, twice for comm
#define T_IENT  TD(IENT)		// Tap once for i, twice for enter
#define T_SL    TD(SL)		// Tap once for slash, twice for backslash
#define T_20    TD(T20)		// Tap once for 2, twice for 0
#define T_ATH   TD(ATH)	        // Tap once for @, twice for # 
#define T_PRAM  TD(PRAM)	        // Tap once for %, twice for & 
#define T_SBAK  TD(SBAK)             // Tap once for semicolon, twice for backspace



// Modifiers
#define LG_ZMIN LGUI(KC_EQUAL)          // Command + plus (zoom in)
#define LG_ZMOT LGUI(KC_MINUS)          // Command + minus (zoom out)
#define MT_SHFT MT(MOD_RSFT, KC_ENT)    // Tap for enter, hold for shift
#define CALTDEL LCTL(LALT(KC_DEL))	    // Ctrl Alt Del
#define TSKMGR LCTL(LSFT(KC_ESC))	      // Task Manager
#define CLIP LCTL(LALT(KC_Q))		        // Clipboard
#define SS LCTL(LALT(KC_G))		          // Greenshot region

// MISC
#define NUM  LSFT(KC_3)
#define AT   LSFT(KC_2)


// Fillers to make layering more clear
#define LOWER MO(_LOWER)
#define RAISE MO(_RAISE) 
#define FN MO(_FN)
#define EX MO(_EX)
#define TEX     LT(_EX, KC_T)           // Tap for "T", hold for Extras layer
#define BSYM    LT(_SYMBOLS, KC_B)      // Tap for "B", hold for Symbols layer
#define JSYM    LT(_SYMBOLS, KC_J)      // Tap for "J", hold for Symbols layer
#define FNZ     LT(_FN, KC_Z)           // Tap for "Z", hold for FN layer
#define VLOWER  LT(_LOWER, KC_V)        // Tap for "V", hold for Lower layer
#define KRAISE  LT(_RAISE, KC_K)        // Tap for "K", hold for Raise layer[----]
#define ASFT    MT(MOD_LSFT, KC_A)      // Tap for "A", hold for Shift
#define GGUI    MT(MOD_LGUI, KC_G)      // Tap for "G", hold for OS Key
#define MGUI    MT(MOD_LGUI, KC_M)      // Tap for "M", hold for OS Key
#define CTRLX   MT(MOD_LCTL, KC_X)      // Tap for "X", hold for Ctrl
#define CALT    MT(MOD_LALT, KC_C)      // Tap for "C", hold for Alt
#define L_ALT   MT(MOD_RALT, KC_L)      // Tap for "L", hold for Alt
#define TBSHFT  MT(MOD_LSFT, KC_TAB)    // Tap for Tab, hold for Shift
#define SLSHFT  MT(MOD_RSFT, KC_SLSH)    // Tap for Slash, hold for Shift
#define COPY LCTL(KC_C)
#define PASTE LCTL(KC_V)
#define XXXXXXX KC_NO
#define XXXXXXXX KC_NO
#define ________ KC_TRNS


// Defines for task manager and such
#define CALTDEL LCTL(LALT(KC_DEL))
#define TSKMGR LCTL(LSFT(KC_ESC))
#define CLIP LCTL(LALT(KC_Q))		// Clipboard
#define SS LCTL(LALT(KC_G))		// Greenshot region




#define KEYMAP_w(...)                  LAYOUT(__VA_ARGS__)
#define LAYOUT_w(...)                  LAYOUT(__VA_ARGS__)
#define LAYOUT_ortho_3x10_w(...)       LAYOUT_ortho_3x10(__VA_ARGS__)
#define LAYOUT_ortho_4x4_w(...)        LAYOUT_ortho_4x4(__VA_ARGS__)
#define LAYOUT_ortho_4x12_w(...)       LAYOUT_ortho_4x12(__VA_ARGS__)
#define LAYOUT_ortho_5x5_w(...)        LAYOUT_ortho_5x5(__VA_ARGS__)
#define LAYOUT_ortho_5x10_w(...)       LAYOUT_ortho_5x10(__VA_ARGS__)
#define LAYOUT_ortho_5x15_w(...)       LAYOUT_ortho_5x15(__VA_ARGS__)


/*
 * Default 4x12 Layout (in halves for easier indexing)
 *
 * ┌─────┬─────┬─────┬─────┬─────┬─────┐   ┌─────┬─────┬─────┬─────┬─────┬─────┐
 * │ TAB │ Q   │ D   │ R   │ W   │ B   │   │ J   │ F   │ U   │ P   │ BSPC│ BSPC│
 * │ ESC │ ESC │     │     │     │ SYM │   │ SYM │     │     │     │ ;   │ ;   │
 * ├─────┼─────┼─────┼─────╆━━━━━╅─────┤   ├─────╆━━━━━╅─────┼─────┼─────┼─────┤
 * │ TAB │ A   │ S   │ H   ┃ T   ┃ G   │   │ Y   ┃ N   ┃ E   │ O   │ I   │     │
 * │SHIFT│     │     │     ┃ EX  ┃     │   │     ┃     ┃     │     │ENTER│ENTER│
 * ├─────┼─────┼─────┼─────╄━━━━━╃─────┤   ├─────╄━━━━━╃─────┼─────┼─────┼─────┤
 * │SHIFT│ Z   │ X   │ M   │ C   │ V   │   │ K   │ L   │ SPC │ SPC │ /   │ UP  │
 * │     │     │     │     │     │     │   │     │     │ ,   │ .   │     │RIGHT│
 * ├─────┼─────┼─────┼─────┼─────┼─────┤   ├─────┼─────┼─────┼─────┼─────┼─────┤
 * │ FN  │CTRL │ OS  │ ALT │LOWER│     │   │     │RAISE│ SS  │CLIP │COPY │ DN  │
 * │     │     │     │     │     │     │   │     │     │     │     │PASTE│LEFT │
 * └─────┴─────┴─────┴─────┴─────┴─────┘   └─────┴─────┴─────┴─────┴─────┴─────┘
 */

#define _WM \
T_TE,     T_QESC,  KC_D,    KC_R,    KC_W,    BSYM,    JSYM,     KC_F,    KC_U,    KC_P,    T_SBAK,  KC_BSPC, \
TBSHFT,   KC_A,    KC_S,    KC_H,    TEX,     KC_G,    KC_Y,     KC_N,    KC_E,    KC_O,    T_IENT,  KC_ENT,  \
KC_LSFT,  KC_Z,    KC_X,    KC_M,    KC_C,    KC_V,    KC_K,     KC_L,    T_CSPC,  T_DSPC,  KC_SLSH, T_UR,    \
FN,       KC_LCTL, KC_LGUI, KC_LALT, LOWER,   T_SE,    T_SE,     RAISE,   SS,      CLIP,    T_CP,    T_DL     \


#define _QW \
T_TE,     KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,     KC_U,    KC_I,    KC_O,    KC_P,   KC_BSPC,  \
TBSHFT,   KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,     KC_J,    KC_K,    KC_L,    KC_SCLN,KC_ENT,   \
KC_LSFT,  KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,     KC_M,    KC_COMM, KC_DOT,  KC_SLASH,T_UR,    \
FN,       KC_LCTL, KC_LGUI, KC_LALT, LOWER,   T_SE,    T_SE,     RAISE,   SS,      CLIP,    T_CP,    T_DL     \


  /* LOWER 
  * ┌─────┬─────┬─────┬─────┬─────┬─────┐   ┌─────┬─────┬─────┬─────┬─────┬─────┐
  * │ ()  │ []  │ /\  │     │     │     │   │     │     │ 7   │ 8   │ 9   │ 0   │
  * │     │     │     │     │     │     │   │     │     │     │     │     │     │
  * ├─────┼─────┼─────┼─────╆━━━━━╅─────┤   ├─────╆━━━━━╅─────┼─────┼─────┼─────┤
  * │ @ # │ & % │     │     ┃     ┃     │   │     ┃     ┃ 4   │ 5   │ 6   │     │
  * │     │     │     │     ┃     ┃     │   │     ┃     ┃     │     │     │     │
  * ├─────┼─────┼─────┼─────╄━━━━━╃─────┤   ├─────╄━━━━━╃─────┼─────┼─────┼─────┤
  * │     │     │     │     │     │     │   │     │     │ 1   │ 2   │ 3   │ UP  │
  * │     │     │     │     │     │     │   │     │     │     │     │     │RIGHT│
  * ├─────┼─────┼─────┼─────┼─────┼─────┤   ├─────┼─────┼─────┼─────┼─────┼─────┤
  * │     │     │     │     │LOWER│     │   │     │     │BPSC │ SPC │  .  │ DN  │
  * │     │     │     │     │     │     │   │     │     │     │     │ ENT │LEFT │
  * └─────┴─────┴─────┴─────┴─────┴─────┘   └─────┴─────┴─────┴─────┴─────┴─────┘
  */
#define _LOWER \
 T_XX,    T_YY,    T_SL,    _______, _______, _______, _______, _______, KC_7,    KC_8,    KC_9,   KC_0,    \
 T_ATH,   T_PRAM,  _______, _______, _______, _______, _______, _______, KC_4,    KC_5,    KC_6,   _______, \
 _______, _______, _______, _______, _______, _______, _______, _______, KC_1,    KC_2,    KC_3,   T_UR,    \
 _______, _______, _______, _______, _______, _______, _______, _______, KC_BSPC, KC_SPC,  T_DENT, T_DL     \


 /* RAISE
  * ┌─────┬─────┬─────┬─────┬─────┬─────┐   ┌─────┬─────┬─────┬─────┬─────┬─────┐
  * │BOOT │DEBUG│     │     │     │     │   │     │     │ F7  │ F8  │ F9  │ F10 │
  * │     │     │     │     │     │     │   │     │     │     │     │     │     │
  * ├─────┼─────┼─────┼─────╆━━━━━╅─────┤   ├─────╆━━━━━╅─────┼─────┼─────┼─────┤
  * │     │ RGB │ RGB │ RGB ┃ RGB ┃     │   │     ┃ / \ ┃ F4  │ F5  │ F6  │ F11 │
  * │     │ TOG │ MOD │ HUI ┃ HUD ┃     │   │     ┃     ┃     │     │     │     │
  * ├─────┼─────┼─────┼─────╄━━━━━╃─────┤   ├─────╄━━━━━╃─────┼─────┼─────┼─────┤
  * │     │ RGB │ RGB │ RGB │ RGB │     │   │     │  _  │ F1  │ F2  │ F3  │ F12 │
  * │     │ SAI │ SAD │ VAI │ VAD │     │   │     │  -  │     │     │     │     │
  * ├─────┼─────┼─────┼─────┼─────┼─────┤   ├─────┼─────┼─────┼─────┼─────┼─────┤
  * │     │     │     │     │     │     │   │     │RAISE│     │     │     │     │
  * │     │     │     │     │     │     │   │     │     │     │     │     │     │
  * └─────┴─────┴─────┴─────┴─────┴─────┘   └─────┴─────┴─────┴─────┴─────┴─────┘
  */
#define _RAISE \
 QK_BOOT, DB_TOGG, _______, _______, _______, _______, _______, _______, KC_F7,   KC_F8,   KC_F9,   KC_F10,  \
 _______, RGB_TOG, RGB_MOD, RGB_HUI, RGB_HUD, _______, _______, _______, KC_F4,   KC_F5,   KC_F6,   KC_F11,  \
 _______, RGB_SAI, RGB_SAD, RGB_VAI, RGB_VAD, _______, _______, T_UMIN,  KC_F1,   KC_F2,   KC_F3,   KC_F12,  \
 _______,      WM,      QW, _______, _______, _______, _______, _______, _______, _______, _______, _______  \


  /* EXTRAS
  * ┌─────┬─────┬─────┬─────┬─────┬─────┐   ┌─────┬─────┬─────┬─────┬─────┬─────┐
  * │ !   │     │     │     │     │     │   │     │ /\  │  [  │  ]  │  ;  │     │
  * │     │     │     │     │     │     │   │     │     │     │     │     │     │
  * ├─────┼─────┼─────┼─────╆━━━━━╅─────┤   ├─────╆━━━━━╅─────┼─────┼─────┼─────┤
  * │SHIFT│     │     │EXTRA┃     ┃     │   │     ┃     ┃  (  │  )  │  '  │     │
  * │     │     │     │     ┃     ┃     │   │     ┃     ┃     │     │     │     │
  * ├─────┼─────┼─────┼─────╄━━━━━╃─────┤   ├─────╄━━━━━╃─────┼─────┼─────┼─────┤
  * │     │     │     │     │     │     │   │     │     │  ,  │  .  │  ?  │     │
  * │     │     │     │     │     │     │   │     │     │     │     │     │     │
  * ├─────┼─────┼─────┼─────┼─────┼─────┤   ├─────┼─────┼─────┼─────┼─────┼─────┤
  * │ FN  │     │     │     │     │     │   │     │     │     │     │     │     │
  * │     │     │     │     │     │     │   │     │     │     │     │     │     │
  * └─────┴─────┴─────┴─────┴─────┴─────┘   └─────┴─────┴─────┴─────┴─────┴─────┘
  */
#define _EX \
  _______,  KC_EXLM, _______, _______, _______, _______, _______,     T_SL, KC_LBRC, KC_RBRC, KC_SCLN, _______, \
  KC_LSFT,  _______, _______, _______, _______, _______, _______,  _______, KC_LPRN, KC_RPRN, KC_QUOT, _______, \
  _______,  _______, _______, _______, _______, _______, _______,  _______, KC_COMM, KC_DOT,  KC_QUES, _______, \
  _______,  _______, _______, _______, _______, T_SE,    T_SE,     _______, _______, _______, _______, _______  \


  /* FUNCTION
  * ┌─────┬─────┬─────┬─────┬─────┬─────┐   ┌─────┬─────┬─────┬─────┬─────┬─────┐
  * │COPY │CLIP │ SS  │     │     │     │   │     │ /\  │     │ UP  │     │ DEL │
  * │PASTE│     │     │     │     │     │   │     │     │     │     │     │     │
  * ├─────┼─────┼─────┼─────╆━━━━━╅─────┤   ├─────╆━━━━━╅─────┼─────┼─────┼─────┤
  * │TAB  │ M05 │ M06 │ M07 ┃ M08 ┃     │   │     ┃     ┃LEFT │DOWN │RIGHT│UP   │
  * │SHIFT│     │     │     ┃     ┃     │   │     ┃     ┃     │     │     │RIGHT│
  * ├─────┼─────┼─────┼─────╄━━━━━╃─────┤   ├─────╄━━━━━╃─────┼─────┼─────┼─────┤
  * │     │ M01 │ M02 │ M03 │ M04 │     │   │     │     │ ,   │ .   │ ?   │DOWN │
  * │     │     │     │     │     │     │   │     │     │     │     │     │LEFT │
  * ├─────┼─────┼─────┼─────┼─────┼─────┤   ├─────┼─────┼─────┼─────┼─────┼─────┤
  * │ FN  │     │     │     │     │     │   │     │     │     │     │     │     │
  * │     │     │     │     │     │     │   │     │     │     │     │     │     │
  * └─────┴─────┴─────┴─────┴─────┴─────┘   └─────┴─────┴─────┴─────┴─────┴─────┘
  */
#define _FN \
  T_CP,     CLIP,     SS,       _______,  _______,  _______,  _______,  T_SL,     _______,  KC_UP,    _______,  KC_DEL, \
  TBSHFT,   M05,      M06,      M07,      M08,      _______,  _______,  _______,  KC_LEFT,  KC_DOWN,  KC_RGHT,  T_UR,   \
  _______,  M01,      M02,      M03,      M04,      _______,  _______,  _______,  T_QEXC,   KC_COMM,  KC_DOT,   T_DL,   \
  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______ \


  /* SYMBOLS
  * ┌─────┬─────┬─────┬─────┬─────┬─────┐   ┌─────┬─────┬─────┬─────┬─────┬─────┐
  * │  $  │  ^  │  <  │  >  │ SYMB│     │   │     │ SYMB│  │  │  [  │  ]  │  -  │
  * │     │     │     │     │     │     │   │     │     │     │     │     │     │
  * ├─────┼─────┼─────┼─────╆━━━━━╅─────┤   ├─────╆━━━━━╅─────┼─────┼─────┼─────┤
  * │  %  │  :  │  ;  │  +  ┃  =  ┃     │   │     ┃     ┃     │  (  │  )  │  _  │
  * │     │     │     │     ┃     ┃     │   │     ┃     ┃     │     │     │     │
  * ├─────┼─────┼─────┼─────╄━━━━━╃─────┤   ├─────╄━━━━━╃─────┼─────┼─────┼─────┤
  * │  &  │  '  │  "  │  *  │  #  │     │   │     │  !  │  ?  │  /  │  \  │  @  │ 
  * │     │     │     │     │     │     │   │     │     │     │     │     │     │
  * ├─────┼─────┼─────┼─────┼─────┼─────┤   ├─────┼─────┼─────┼─────┼─────┼─────┤
  * │ FN  │     │     │     │     │     │   │     │     │     │     │     │     │
  * │     │     │     │     │     │     │   │     │     │     │     │     │     │
  * └─────┴─────┴─────┴─────┴─────┴─────┘   └─────┴─────┴─────┴─────┴─────┴─────┘
  */

#define _SYMBOLS \
  KC_DLR,   KC_CIRC,  KC_LABK,  KC_RABK,  _______,  _______,  _______, _______, KC_PIPE,  KC_LBRC,  KC_RBRC,  KC_MINS,  \
  KC_PERC,  KC_COLN,  KC_SCLN,  KC_PLUS,  KC_EQL,   _______,  _______, _______, _______,  KC_LPRN,  KC_RPRN,  KC_UNDS,  \
  KC_AMPR,  KC_QUOT,  KC_DQUO,  KC_ASTR,  KC_HASH,  _______,  _______, KC_EXLM, KC_QUES,  KC_SLSH,  KC_BSLS,  KC_AT,    \
  _______,  WM,       _______,  _______,  _______,  _______,  _______, _______, _______,  _______,  _______,  _______   \




/* SATPAD Empty
 *
 * ┌─────┬─────┬─────┬─────┬─────┬─────┐     ┌─────┬─────┬─────┬─────┬─────┬─────┐
 * │     │     │     │     │     │     │     │     │     │     │     │     │     │
 * │     │     │     │     │     │     │     │     │     │     │     │     │     │
 * ├─────┼─────┼─────┼─────╆━━━━━╅─────┤     ├─────╆━━━━━╅─────┼─────┼─────┼─────┤
 * │     │     │     │     ┃     ┃     │     │     ┃     ┃     │     │     │     │
 * │     │     │     │     ┃     ┃     │     │     ┃     ┃     │     │     │     │
 * ├─────┼─────┼─────┼─────╄━━━━━╃─────┼─────┼─────╄━━━━━╃─────┼─────┼─────┼─────┤
 * │     │     │     │     │     │     │     │     │     │     │     │     │     │
 * │     │     │     │     │     │     │     │     │     │     │     │     │     │
 * └─────┴─────┴─────┴─────┴─────┴─────┴─────┴─────┴─────┴─────┴─────┴─────┴─────┘
 */




#define _________________QWERTY_L1_________________        KC_Q,    KC_W,    KC_E,    KC_R,    KC_T
#define _________________QWERTY_L2_________________        KC_A,    KC_S,    KC_D,    KC_F,    KC_G
#define _________________QWERTY_L3_________________        KC_Z,    KC_X,    KC_C,    KC_V,    KC_B

#define _________________QWERTY_R1_________________        KC_Y,    KC_U,    KC_I,    KC_O,    KC_P
#define _________________QWERTY_R2_________________        KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN
#define _________________QWERTY_R3_________________        KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLASH

#define _________________WORKMAN_1_________________       KC_Q,    KC_D,    KC_R,   KC_W,     KC_B,     KC_J,    KC_F,    KC_U,    KC_P,    KC_SCLN
#define _________________WORKMAN_2_________________       KC_A,    KC_S,    KC_H,   KC_T,     KC_G,     KC_Y,    KC_N,    KC_E,    KC_O,    LT_MC(KC_I)
#define _________________WORKMAN_3_________________       KC_Z,    KC_X,    KC_M,   KC_C,     KC_V,     KC_K,    KC_L,    KC_COMM, KC_DOT,  KC_SLASH

#define _________________WORKMAN_L1________________       KC_Q,    KC_D,    KC_R,   KC_W,     KC_B
#define _________________WORKMAN_L2________________       KC_A,    KC_S,    KC_H,   KC_T,     KC_G
#define _________________WORKMAN_L3________________       KC_Z,    KC_X,    KC_M,   KC_C,     KC_V

#define _________________WORKMAN_R1________________       KC_J,    KC_F,    KC_U,    KC_P,    KC_SCLN
#define _________________WORKMAN_R2________________       KC_Y,    KC_N,    KC_E,    KC_O,    LT_MC(KC_I)
#define _________________WORKMAN_R3________________       KC_K,    KC_L,    KC_COMM, KC_DOT,  KC_SLASH



#define ________________NUMBER_LEFT________________       KC_1,    KC_2,    KC_3,    KC_4,    KC_5
#define ________________NUMBER_RIGHT_______________       KC_6,    KC_7,    KC_8,    KC_9,    KC_0
#define _________________FUNC_LEFT_________________       KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5
#define _________________FUNC_RIGHT________________       KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10

#define __________________LONG_FUNC_LEFT___________________       KC_F1,  KC_F2,  KC_F3, KC_F4,  KC_F5,  KC_F6
#define __________________LONG_FUNC_RIGHT__________________       KC_F7,  KC_F8,  KC_F9, KC_F10, KC_F11, KC_F12

#define _________________BLANK_5___________________        _______, _______, _______, _______, _______
#define _________________BLANK_6___________________        _______, _______, _______, _______, _______, _______

#define _________________LOWER_L1__________________        KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC
#define _________________LOWER_L2__________________        _________________FUNC_LEFT_________________
#define _________________LOWER_L3__________________        _________________FUNC_RIGHT________________

#define _________________LOWER_R1__________________        KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN
#define _________________LOWER_R2__________________        _______, KC_UNDS, KC_PLUS, KC_LCBR, KC_RCBR
#define _________________LOWER_R3__________________        _______, KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT

#define _______________LOWER_412_L1________________        T_XX,    T_YY,    T_SL,    _______, _______, _______
#define _______________LOWER_412_L2________________        T_ATH,   T_PRAM,  _______, _______, _______, _______
#define _______________LOWER_412_L3________________        _______, _______, _______, _______, _______, _______
#define _______________LOWER_412_L4________________        _______, _______, _______, _______, _______, _______

#define _______________LOWER_412_R1________________        _______, _______, KC_7,    KC_8,    KC_9,   KC_0   
#define _______________LOWER_412_R2________________        _______, _______, KC_4,    KC_5,    KC_6,   _______
#define _______________LOWER_412_R3________________        _______, _______, KC_1,    KC_2,    KC_3,   T_UR
#define _______________LOWER_412_R4________________        _______, _______, KC_BSPC, KC_SPC,  T_DENT, T_DL



#define _________________RAISE_L1__________________        ________________NUMBER_LEFT________________
#define _________________RAISE_L2__________________        ___________________BLANK___________________
#define _________________RAISE_L3__________________        ___________________BLANK___________________

#define _________________RAISE_R1__________________        ________________NUMBER_RIGHT_______________
#define _________________RAISE_R2__________________        _______, KC_MINS, KC_EQL,  KC_LBRC, KC_RBRC
#define _________________RAISE_R3__________________        _______, KC_HOME, KC_PGDN, KC_PGUP, KC_END

#define _______________RAISE_412_L1________________        QK_BOOT, DB_TOGG, _______, _______, _______, _______
#define _______________RAISE_412_L2________________        _______, RGB_TOG, RGB_MOD, RGB_HUI, RGB_HUD, _______
#define _______________RAISE_412_L3________________        _______, RGB_SAI, RGB_SAD, RGB_VAI, RGB_VAD, _______

#define _______________RAISE_412_R1________________        _______, _______, KC_F7,   KC_F8,   KC_F9,   KC_F10
#define _______________RAISE_412_R2________________        _______, _______, KC_F4,   KC_F5,   KC_F6,   KC_F11
#define _______________RAISE_412_R3________________        _______, T_UMIN,  KC_F1,   KC_F2,   KC_F3,   KC_F12

#define _________________ADJUST_L1_________________        RGB_MOD, RGB_HUI, RGB_SAI, RGB_VAI, RGB_TOG
#define _________________ADJUST_L2_________________        MU_TOGG, CK_TOGG, AU_ON,   AU_OFF,  AG_NORM
#define _________________ADJUST_L3_________________        RGB_RMOD,RGB_HUD,RGB_SAD, RGB_VAD, KC_RGB_T

#define _________________ADJUST_R1_________________        KC_SEC1, KC_SEC2, KC_SEC3, KC_SEC4, KC_SEC5
#define _________________ADJUST_R2_________________        AG_SWAP, QWERTY,  COLEMAK, DVORAK,  WORKMAN
#define _________________ADJUST_R3_________________        MG_NKRO, KC_MUTE, KC_VOLD, KC_VOLU, KC_MNXT

#define _____________WORKMAN_310_001_L_____________        T_QESC,   KC_D,    KC_R,    KC_W,    BSYM
#define _____________WORKMAN_310_001_R_____________        JSYM,     KC_F,    KC_U,    KC_P,    KC_BSPC
#define _____________WORKMAN_310_002_L_____________        ASFT,     KC_S,    KC_H,    TEX,    KC_G
#define _____________WORKMAN_310_002_R_____________        KC_Y,     KC_N,    KC_E,    KC_O,    T_IENT
#define _____________WORKMAN_310_003_L_____________        FNZ,      CTRLX,   MGUI,    CALT,    VLOWER
#define _____________WORKMAN_310_003_R_____________        KRAISE,   L_ALT,    T_CSPC,  T_DSPC,  KC_SLSH
#define _____________WORKMAN_310_004_L_____________        FN,       KC_LCTL, KC_LGUI, KC_LALT, LOWER
#define _____________WORKMAN_310_004_R_____________        RAISE,    SS,      CLIP,    T_CP,    FN

#define _____________WORKMAN_410_003_L_____________        FNZ,      KC_X,    KC_M,    KC_C,    KC_V
#define _____________WORKMAN_410_003_R_____________        KC_K,     KC_L,    T_CSPC,  T_DSPC,  SLSHFT

#define _____________WORKMAN_311_001_L_____________        T_QESC,   KC_D,    KC_R,    KC_W,    BSYM,  XXXXXXXX
#define _____________WORKMAN_311_001_R_____________        JSYM,     KC_F,    KC_U,    KC_P,    T_SBAK
#define _____________WORKMAN_311_002_L_____________        ASFT,     KC_S,    KC_H,    TEX,     GGUI,  XXXXXXXX
#define _____________WORKMAN_311_002_R_____________        KC_Y,     KC_N,    KC_E,    KC_O,    T_IENT
#define _____________WORKMAN_311_003_L_____________        FNZ,      CTRLX,   MGUI,    CALT,    VLOWER,XXXXXXXX
#define _____________WORKMAN_311_003_R_____________        KRAISE,   L_ALT,    T_CSPC,  T_DSPC,  KC_SLSH


#define _____________WORKMAN_412_001_L_____________        T_TE,     T_QESC,  KC_D,    KC_R,    KC_W,    BSYM
#define _____________WORKMAN_412_001_R_____________        JSYM,     KC_F,    KC_U,    KC_P,    T_SBAK,  KC_BSPC
#define _____________WORKMAN_412_002_L_____________        TBSHFT,   KC_A,    KC_S,    KC_H,    TEX,     KC_G
#define _____________WORKMAN_412_002_R_____________        KC_Y,     KC_N,    KC_E,    KC_O,    T_IENT,  KC_ENT
#define _____________WORKMAN_412_003_L_____________        KC_LSFT,  KC_Z,    KC_X,    KC_M,    KC_C,    KC_V
#define _____________WORKMAN_412_003_R_____________        KC_K,     KC_L,    T_CSPC,  T_DSPC,  KC_SLSH, T_UR
#define _____________WORKMAN_412_004_L_____________        FN,       KC_LCTL, KC_LGUI, KC_LALT, LOWER,   T_SE
#define _____________WORKMAN_412_004_R_____________        T_SE,     RAISE,   SS,      CLIP,    T_CP,    T_DL 


/*
*#ifdef ENCODER_MAP_ENABLE
*const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][2] = {
*    [_WM]   =  { ENCODER_CCW_CW(RGB_RMOD, RGB_MOD) },
*    [_LOWER]   =  { ENCODER_CCW_CW(KC_VOLD,  KC_VOLU) },
*    [_RAISE] =  { ENCODER_CCW_CW(KC_VOLD,  KC_VOLU) },
*    [_QW] =  { ENCODER_CCW_CW(KC_VOLD,  KC_VOLU) },
*    [_EX] =  { ENCODER_CCW_CW(KC_VOLD,  KC_VOLU) },
*    [_FN]  =  { ENCODER_CCW_CW(KC_VOLD,  KC_VOLU) },
*    [_SYMBOLS]  =  { ENCODER_CCW_CW(KC_VOLD,  KC_VOLU) }
*};
*#endif
*/

// Default layer effects for BM40 only
#ifdef KEYBOARD_bm40hsrgb
layer_state_t layer_state_set_user(layer_state_t state) {

    // Default layer keypress effects
    switch (get_highest_layer(default_layer_state)) {
    case 1:
        rgb_matrix_mode_noeeprom(RGB_MATRIX_BREATHING);
        break;
    case 0:
        rgb_matrix_mode_noeeprom(RGB_MATRIX_RAINDROPS);
        break;
    }
    return state;
}
#endif // KEYBOARD_bm40hsrgb

