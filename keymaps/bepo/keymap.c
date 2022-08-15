#include QMK_KEYBOARD_H
#include "quantum.h"
#include "keymap_bepo.h"
#include "keymap_french.h"

/*                  *
 *                  *
 * Not tested yet!  *
 *                  *
 *                  */

#ifdef KEYLOGGER_ENABLE
bool log_enable = true;
#endif

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
# ifdef KEYLOGGER_ENABLE
  if (log_enable)
  {
    printf(
      "{\"keylog\": true, \"col\": %d, \"row\": %d, \"pressed\": %d, \"layer\": \"%s\"}\n",
      record->event.key.row,
      record->event.key.col,
      record->event.pressed,
      getLayerName(default_layer_state) );
  }
# endif
  return true;

}


#include "shortcuts.h"
#ifdef TAP_DANCE_ENABLE
#   include "tap_dance.h"
#endif

enum layers {
    _BASE_LEFT,
    _BASE_RIGHT,
    _WINDOWS_LEFT,
    _WINDOWS_RIGHT
};


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    /* _BASE_LEFT: default left layer for Linux                                       *
     * QK BOOT is hidden inside the case.                                           *
     * ┌───────┬───────┬───────┬───────┬───────┬───────┬───────┬───────┐            *
     * │$     #│"     1│«     2│»     3│(     4│)     5│DEL    │BKSP   │            *
     * │       │       │       │       │       │       │       │       │            *
     * │ESC    │F1     │F2     │F3     │F4     │F5     │       │       │            *
     * ├───────┼───────┼───────┼───────┼───────┼───────┼───────┤       │ ┌───────┐  *
     * │COPY   │TAB    │b      │é      │p      │o      │è      │       │ │       │  *
     * │       │       │       │       │       │       │       ├───────┤ │QK_BOOT│  *
     * │CUT    │ LCTL  │       │       │       │       │       │ENTER  │ │       │  *
     * ├───────┼───────┼───────┼───────┼───────┼───────┼───────┤       │ └───────┘  *
     * │PAST   │TAB    │a      │u      │i      │e      │,      │       │            *
     * │       │       │       │       │       │       │       │       │            *
     * │       │ LCTL  │       │       │       │       │PGDW   │       │            *
     * ├───────┼───────┼───────┼───────┼───────┼───────┼───────┼───────┤            *
     * │LSHIFT │LSHIFT │ à     │ y     │ x     │ .     │ k     │SPC    │            *
     * │       │       │       │       │       │       │       │       │            *
     * │CMP    │       │  LCTL │ LALT  │       │       │       │LWS    │            *
     * └───────┴───────┴───────┴───────┴───────┴───────┴───────┴───────┘            */
    [_BASE_LEFT] = LAYOUT_left(
            TD_BPESC,   TD_F1,      TD_F2,      TD_F3,      TD_F4,      TD_F5,      KC_DEL,     KC_BSPC,  
            TD_CPP,     TD_TAB,     BP_B,       BP_EACU,    BP_P,       BP_O,       TD_EGRV,    QK_BOOT,
            KC_PASTE,   TD_TAB,     BP_A,       BP_U,       BP_I,       BP_E,       TD_COMMA,   KC_ENTER, 
            TD_LSHIFT,  TD_LSHIFT,  TD_AGRV,    TD_Y,       BP_X,       BP_DOT,     BP_K,       TD_LLSPC
    ),
    /* _WINDOWS: right on left layer for windows                         *
     * ┌───────┬───────┬───────┬───────┬───────┬───────┬───────┬───────┐ *
     * │       │       │       │       │       │       │       │       │ *
     * │       │       │       │       │       │       │       │       │ *
     * │       │       │       │       │       │       │       │       │ *
     * ├───────┼───────┼───────┼───────┼───────┼───────┼───────┤       │ *
     * │       │       │       │       │       │       │       │       │ *
     * │       │       │       │       │       │       │       ├───────┤ *
     * │       │       │       │       │       │       │       │       │ *
     * ├───────┼───────┼───────┼───────┼───────┼───────┼───────┤       │ *
     * │       │       │       │       │       │       │       │       │ *
     * │       │       │       │       │       │       │       │       │ *
     * │       │       │       │       │       │       │       │       │ *
     * ├───────┼───────┼───────┼───────┼───────┼───────┼───────┼───────┤ *
     * │       │       │       │       │       │       │       │SPC    │ *
     * │       │       │       │       │       │       │       │       │ *
     * │       │       │       │       │       │       │       │LWS    │ *
     * └───────┴───────┴───────┴───────┴───────┴───────┴───────┴───────┘ */
    [_WINDOWS_LEFT] = LAYOUT_left(
            _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,
            _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,
            _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,
            _______,    _______,    _______,    _______,    _______,    _______,    _______,    TD_LWSPC
    )
};


/*const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {*/
    /* keymap 0: default right layer                                     *
     * QK BOOT is hidden inside the case.                                *
     * ┌───────┬───────┬───────┬───────┬───────┬───────┬───────┬───────┐ *
     * │ KSP   │@     6│+     7│-     8│/     9│*     0│=     °│%     `│ *
     * │       │       │       │       │       │       │       │       │ *
     * │       │F6     │F7     │F8     │F9     │F10    │F11    │F12    │ *
     * │       ├───────┼───────┼───────┼───────┼───────┼───────┼───────┤ *
     * │       │^      │v      │d      │l      │j      │z      │UNDO   │ *
     * ├───────┤       │       │       │       │       │       │       │ *
     * │ENTER  │       │       │       │       │       │       │EMOJI  │ *
     * │       ├───────┼───────┼───────┼───────┼───────┼───────┼───────┤ *
     * │       │c      │t      │s      │r      │n      │m      │MUTE   │ *
     * │       │       │       │       │       │       │       │       │ *
     * │       │      ç│       │       │       │       │       │  RCTL │ *
     * ├───────┼───────┼───────┼───────┼───────┼───────┼───────┼───────┤ *
     * │SPC    │’      │q      │g      │h      │f      │w      │ RSHIFT│ *
     * │       │       │       │       │       │       │       │       │ *
     * │LWS    │       │       │       │       │  RALT │  APP  │  CMP  │ *
     * └───────┴───────┴───────┴───────┴───────┴───────┴───────┴───────┘ */

    /*[_BASE_RIGHT] = LAYOUT_left_ortho(
            KC_BSPC,    TD_F6,      TD_F7,      TD_F8,      TD_F9,      TD_F10,     TD_F11,     TD_F12,
            QK_BOOT,    BP_DCRC,    BP_V,       BP_D,       BP_L,       BP_J,       BP_Z,       TD_UNDO,
            KC_ENTER,   BP_C,       BP_T,       BP_S,       BP_R,       BP_N,       BP_M,       TD_MUTE,
            TD_RLSPC,   BP_APOS,    BP_Q,       BP_G,       BP_H,       TD_F,       TD_W,       TD_RSHIFT
    ),*/
    /* keymap 0: default right layer for windows                         *
     * QK BOOT is hidden inside the case.                                *
     * ┌───────┬───────┬───────┬───────┬───────┬───────┬───────┬───────┐ *
     * │       │       │       │       │       │       │       │       │ *
     * │       │       │       │       │       │       │       │       │ *
     * │       │       │       │       │       │       │       │       │ *
     * │       ├───────┼───────┼───────┼───────┼───────┼───────┼───────┤ *
     * │       │       │       │       │       │       │       │       │ *
     * ├───────┤       │       │       │       │       │       │       │ *
     * │       │       │       │       │       │       │       │       │ *
     * │       ├───────┼───────┼───────┼───────┼───────┼───────┼───────┤ *
     * │       │       │       │       │       │       │       │       │ *
     * │       │       │       │       │       │       │       │       │ *
     * │       │       │       │       │       │       │       │       │ *
     * ├───────┼───────┼───────┼───────┼───────┼───────┼───────┼───────┤ *
     * │SPC    │       │       │       │       │       │       │       │ *
     * │       │       │       │       │       │       │       │       │ *
     * │RWS    │       │       │       │       │       │       │       │ *
     * └───────┴───────┴───────┴───────┴───────┴───────┴───────┴───────┘ */
    /*[_WINDOWS_RIGHT] = LAYOUT_left_ortho(
            _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,
            _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,
            _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,
            TD_RWSPC,   _______,    _______,    _______,    _______,    _______,    _______,    _______
    )
};*/
