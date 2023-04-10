#pragma once
#include "miketronic.h"
#include "process_tap_dance.h"
#include "action.h"


// Tap Dances from Pi40

enum {
  TD_BRC = 0,
  TD_MIN,
  T_UMIN,
  TD_GV_ESC,
  TD_BS,
  TD_SPENTR,     // space, enter
  TD_MULTDIV,    // multiply, divide
  T_UR,          // up, right
  T_DL,       // down, left
  TD_CPYPST,     // copy, paste
  TD_DOTENT,     // dot, enter
  TD_IENT,       // I, enter 
  TD_CSPC,       // space, comma
  T_DSPC,        // space, dot
  T_QEXC,        // Tap once for ?, twice for !
  T_QESC,        // Tap once for "q", twice for escape
  TD_TE,         // Tap once for tab, twice for esc
  TD_20,         // Tap once for 2, twice for 0
  T_SL,         // slash, backslash
  T_XX,	 
  T_YY,	 
  T_ATH,        // Tap once for @, twice for # 
  T_PRAM,	     // Tap once for %, twice for & 
  T_SBAK,    // Tap once for semicolon, twice for backspace
};







