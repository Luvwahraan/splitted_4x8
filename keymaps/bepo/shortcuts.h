#pragma once

#include "keymap_bepo.h"
#include "keymap_french.h"
 
#ifdef TAP_DANCE_ENABLE
#   include "tap_dance.h"
#endif


#undef KC_COPY
#undef KC_PASTE
#undef BP_COPY
#undef BP_PASTE
#define BP_COPY     (BP_LCTL|BP_C)
#define BP_PASTE    (BP_LCTL|BP_V)
#define BP_CUT      (BP_LCTL|BP_X)
#define KC_COPY     BP_COPY
#define KC_PASTE    BP_PASTE

#define BP_UNDO     (BP_LCTL|BP_Z)
#define BP_NEW      (BP_LCTL|BP_N)
#define BP_SAVE     (BP_LCTL|BP_S)
#define BP_QUIT     (BP_LCTL|BP_Q)
#define BP_FIND     (BP_LCTL|BP_F)
#define BP_REPL     (BP_LCTL|BP_R)

#define BP_LSUPER   KC_LGUI
#define BP_RSUPER   KC_RGUI
#define BP_LCTL     KC_LCTL
#define BP_RCTL     KC_RCTL

#define BP_EMOJI    (KC_LGUI|BP_DOT)

// Workspaces
#define WSADD       ( KC_LALT | KC_INS )    // add workspace
#define WSDEL       ( KC_LALT | KC_DEL )    // delete workspace
#define LWS         (KC_LCTL|KC_LALT|KC_LEFT)            // go to left workspace
#define RWS         (KC_LCTL|KC_LALT|KC_RIGHT)           // go to right workspace
#define UWS         (KC_LCTL|KC_LALT|KC_UP)              // go to top workspace
#define DWS         (KC_LCTL|KC_LALT|KC_DOWN)            // go to bottom workspace
// Win10 workspaces
#define MOVW        ( KC_LALT|KC_F7 )     // move window
#define RESW        ( KC_LALT|KC_F8 )     // resize window
#define WLWS        (KC_LCTL|KC_LGUI|KC_LEFT)// go to left workspace
#define WRWS        (KC_LCTL|KC_LGUI|KC_RIGHT)// go to right workspace

#define APPMENU     ( KC_LALT|KC_F1 )     // App menu
#define APPFINDER   ( KC_LALT|KC_F2 )     // App finder
#define BP_XLOCK    (KC_LCTL|KC_LALT|BP_L)


// Keys
#define XXXXXXX     KC_NO
#define BP_COMPOSE  KC_RGUI
#define BP_CMP      BP_COMPOSE
#define BP_SLASH    BP_SLSH
#define BP_EQUAL    BP_EQL
#define BP_MINUS    BP_MINS
#define BP_COMMA    BP_COMM
#define BP_DOLLAR   BP_DLR


// Tap dance
enum {
  TCOPY,
  TPASTE,
  TRF1,
  TRF2,
  TRF3,
  TRF4,
  TRF5,
  TRF6,
  TRF7,
  TRF8,
  TRF9,
  TRF10,
  TRF11,
  TRF12,
  TDGUI,
  TDLCTRL,
  TDRCTRL,
  TDLALT,
  TDRALT,
  TDBPESC,
  TDFRESC,
  TDUNDOEMOJI,
  TDMUTERCTL,
  TDCOPYPASTE,
  TDTABLCTL,
  TDLSCMP,
  TDRSCMP,
  TDAGRVSUPER,
  TDYLALT,
  TDFRALT,
  TDWAPP,
  TDEGRVUP,
  TDCOMMADN,
  TDLDESKMAJWIN,
  TDLDESKMAJLINUX,
  TDRDESKMAJWIN,
  TDRDESKMAJLINUX
};

// Tap dance keys
#define TD_COPY     TD(TCOPY)
#define TD_PASTE    TD(TPASTE)

#define TD_F1       TD(TRF1)
#define TD_F2       TD(TRF2)
#define TD_F3       TD(TRF3)
#define TD_F4       TD(TRF4)
#define TD_F5       TD(TRF5)
#define TD_F6       TD(TRF6)
#define TD_F7       TD(TRF7)
#define TD_F8       TD(TRF8)
#define TD_F9       TD(TRF9)
#define TD_F10      TD(TRF10)
#define TD_F11      TD(TRF11)
#define TD_F12      TD(TRF12)

#define TD_RALT     TD(TDRALT)
#define TD_LALT     TD(TDLALT)
#define TD_BPESC    TD(TDBPESC)
#define TD_FRESC    TD(TDFRESC)

#define TD_UNDO     TD(TDUNDOEMOJI)
#define TD_MUTE     TD(TDMUTERCTL)
#define TD_CPP      TD(TDCOPYPASTE)

// Mod on keys: left keyboard
#define TD_AGRV     TD(TDAGRVSUPER)
#define TD_Y        TD(TDYLALT)

// Mod on keys: right keyboard
#define TD_F        TD(TDFRALT)
#define TD_W        TD(TDWAPP)
#define TD_EGRV     TD(TDEGRVUP)
#define TD_COMMA    TD(TDCOMMADN)

// Workspaces
#define TD_LWSPC    TD(TDLDESKMAJWIN)
#define TD_LLSPC    TD(TDLDESKMAJLINUX)
#define TD_RWSPC    TD(TDRDESKMAJWIN)
#define TD_RLSPC    TD(TDRDESKMAJLINUX)

// Shift compose
#define TD_LSHIFT   TD(TDLSCMP)
#define TD_RSHIFT   TD(TDRSCMP)

// Tap: LCTL, Hold: TAB, Double tap hold:
#define TD_TAB      TD(TDTABLCTL)