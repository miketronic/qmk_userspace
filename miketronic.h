// Copyright 2023 @miketronic -- Mike B <mxb540@gmail.com>
// SPDX-License-Identifier: GPL-2.0+

// https://www.reddit.com/r/olkb/comments/fpm7ev/qmk_user_space_help/


#pragma once
#include QMK_KEYBOARD_H


/* ==========================================================================
    CUSTOM KEYS
   ========================================================================== */

// Tap dances
#define TD_ESCP TD(TD_GV_ESC)           // Tap for grave, twice for escape
#define TD_MINS TD(TD_MIN)              // Tap for minus, twice for equal
#define T_UMIN  TD(UMIN)                // Tap for underscore, twice for minus
#define TD_BRAC TD(TD_BRC)              // Tap for open brace, twice for close
#define T_SE    TD(TD_SPENTR)           // Tap once for space, twice for enter
#define TD_MD   TD(TD_MULTDIV)          // Tap once for Multiply, twice for Divide
#define T_UR	TD(UR)		        // Tap once for Up, twice for Right
#define T_DL	TD(DL)		        // Tap once for Down, twice for Left
#define T_CP    TD(CPYPST)              // Tap once for Copy, twice for Paste
#define T_DENT  TD(DOTENT)              // Tap once for Dot, twice for Enter
#define T_DSPC  TD(DSPC)                // Tap once for Space, twice for Dot
#define T_QEXC  TD(QEXC)                // Tap once for ?, twice for !
#define T_QESC  TD(QESC)                // Tap once for "q", twice for escape
#define T_TE    TD(TE)                  // Tap once for tab, twice for esc
#define T_XX    TD(XX)		        // Tap once for open paren, twice for closed paren
#define T_YY    TD(YY)		        // Tap once for open brace, twice for closed brace
#define T_CSPC  TD(CSPC)		// Tap once for space, twice for comm
#define T_IENT  TD(IENT)		// Tap once for i, twice for enter
#define T_SL    TD(SL)		        // Tap once for slash, twice for backslash
#define T_20    TD(T20)		        // Tap once for 2, twice for 0
#define T_ATH   TD(ATH)	                // Tap once for @, twice for # 
#define T_PRAM  TD(PRAM)	        // Tap once for %, twice for & 
#define T_SBAK  TD(SBAK)                // Tap once for semicolon, twice for backspace








