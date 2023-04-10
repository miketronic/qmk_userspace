// Copyright 2023 @miketronic -- Mike B <mxb540@gmail.com>
// SPDX-License-Identifier: GPL-2.0+

// https://www.reddit.com/r/olkb/comments/fpm7ev/qmk_user_space_help/

#include QMK_KEYBOARD_H
#include "quantum/keycodes.h"


// Tap hold macros
#define TEX     LT(_EX, KC_T)           // Tap for "T", hold for Extras layer
#define BSYM    LT(_SYMBOLS, KC_B)      // Tap for "B", hold for Symbols layer
#define JSYM    LT(_SYMBOLS, KC_J)      // Tap for "J", hold for Symbols layer
#define FNZ     LT(_FN, KC_Z)           // Tap for "Z", hold for FN layer
#define VLOWER  LT(_LOWER, KC_V)        // Tap for "V", hold for Lower layer
#define KRAISE  LT(_RAISE, KC_K)        // Tap for "K", hold for Raise layer

// Mod tap macros
#define ASFT    MT(MOD_LSFT, KC_A)      // Tap for "A", hold for Shift
#define GGUI    MT(MOD_LGUI, KC_G)      // Tap for "G", hold for OS Key
#define MGUI    MT(MOD_LGUI, KC_M)      // Tap for "M", hold for OS Key
#define CTRLX   MT(MOD_LCTL, KC_X)      // Tap for "X", hold for Ctrl
#define CALT    MT(MOD_LALT, KC_C)      // Tap for "C", hold for Alt
#define L_ALT   MT(MOD_RALT, KC_L)      // Tap for "L", hold for Alt
#define TBSHFT  MT(MOD_LSFT, KC_TAB)    // Tap for Tab, hold for Shift
#define SLSHFT  MT(MOD_RSFT, KC_SLSH)    // Tap for Slash, hold for Shift

// Momentary layers
#define LOWER MO(_LOWER)
#define RAISE MO(_RAISE) 
#define FN MO(_FN)
#define EX MO(_EX)

// MISC
#define CALTDEL LCTL(LALT(KC_DEL))	// Ctrl Alt Del
#define TSKMGR LCTL(LSFT(KC_ESC))       // Task Manager
#define CLIP LCTL(LALT(KC_Q))		// Clipboard
#define SS LCTL(LALT(KC_G))	        // Greenshot region
#define NUM  LSFT(KC_3)
#define AT   LSFT(KC_2)
#define COPY LCTL(KC_C)
#define PASTE LCTL(KC_V)
#define XXXXXXX KC_NO
#define XXXXXXXX KC_NO
#define ________ KC_TRNS

#if (!defined(LAYOUT) && defined(KEYMAP))
#define LAYOUT KEYMAP
#endif

#define KEYMAP_wrapper(...)                  LAYOUT(__VA_ARGS__)
#define LAYOUT_wrapper(...)                  LAYOUT(__VA_ARGS__)
#define LAYOUT_ortho_3x10_wrapper(...)       LAYOUT_ortho_3x10(__VA_ARGS__)
#define LAYOUT_ortho_4x4_wrapper(...)        LAYOUT_ortho_4x4(__VA_ARGS__)
#define LAYOUT_ortho_4x12_wrapper(...)       LAYOUT_ortho_4x12(__VA_ARGS__)
#define LAYOUT_ortho_5x5_wrapper(...)        LAYOUT_ortho_5x5(__VA_ARGS__)
#define LAYOUT_ortho_5x10_wrapper(...)       LAYOUT_ortho_5x10(__VA_ARGS__)
#define LAYOUT_ortho_5x15_wrapper(...)       LAYOUT_ortho_5x15(__VA_ARGS__)

// Layers
enum layers { WM };



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

#define _WORKMAN \
KC_MUTE, \
KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_BSPC, \
KC_GESC, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT, \
KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_ENT, \
KC_DEL,  KC_LALT, KC_LCTL, KC_LGUI, MO(1),   KC_SPC,  KC_SPC,  MO(2),   KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT



#if defined(ENCODER_ENABLE) && defined(ENCODER_MAP_ENABLE)
const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][2] = {

};
#endif // defined(ENCODER_ENABLE) && defined(ENCODER_MAP_ENABLE)

