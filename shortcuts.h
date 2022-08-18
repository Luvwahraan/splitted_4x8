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
#define BP_COPY     LCTL(BP_C)
#define BP_PASTE    LCTL(BP_V)
#define BP_CUT      LCTL(BP_X)
#define KC_COPY     BP_COPY
#define KC_PASTE    BP_PASTE

#define BP_UNDO     LCTL(BP_Z)
#define BP_NEW      LCTL(BP_N)
#define BP_SAVE     LCTL(BP_S)
#define BP_QUIT     LCTL(BP_Q)
#define BP_FIND     LCTL(BP_F)
#define BP_REPL     LCTL(BP_R)

#define BP_LSUPER   KC_LGUI
#define BP_RSUPER   KC_RGUI
#define BP_LCTL     KC_LCTL
#define BP_RCTL     KC_RCTL

#define BP_EMOJI    (KC_LGUI|BP_DOT)

// Workspaces
#define WSADD       LALT(KC_INS)    // add workspace
#define WSDEL       LALT(KC_DEL)    // delete workspace
#define LWS         LCA(KC_LEFT)            // go to left workspace
#define RWS         LCA(KC_RIGHT)           // go to right workspace
#define UWS         LCA(KC_UP)              // go to top workspace
#define DWS         LCA(KC_DOWN)            // go to bottom workspace
// Win10 workspaces
#define MOVW        LALT(KC_F7)     // move window
#define RESW        LALT(KC_F8)     // resize window
#define WLWS        LAG(KC_LEFT)// go to left workspace
#define WRWS        LAG(KC_RIGHT)// go to right workspace

#define APPMENU     LALT(KC_F1)     // App menu
#define APPFINDER   LALT(KC_F2)     // App finder
#define BP_XLOCK    LCA(BP_L)


// Keys
#define XXXXXXX     KC_NO
#define BP_COMPOSE  KC_RGUI
#define BP_CMP      BP_COMPOSE
#define BP_SLASH    BP_SLSH
#define BP_EQUAL    BP_EQL
#define BP_MINUS    BP_MINS
#define BP_COMMA    BP_COMM
#define BP_DOLLAR   BP_DLR

