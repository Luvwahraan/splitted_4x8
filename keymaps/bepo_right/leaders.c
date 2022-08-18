#include QMK_KEYBOARD_H
#include "keymap_bepo.h"
#include "keymap_french.h"
#include "utils.h"
#include "leaders.h"
#include "layouts.h"

LEADER_EXTERNS();

void matrix_scan_user(void) {
  static bool locked = false;

  LEADER_DICTIONARY() {
    leading = false;
    leader_end();


    /* $
     * ESC key */
    SEQ_ONE_KEY(BP_DOLLAR)
    {
      send_keystrokes(KC_ESC, KC_NO);
    }

    /* P O W A
     * System power OFF */
    SEQ_FOUR_KEYS(BP_P, BP_O, BP_W, BP_A)
    {
      send_keystrokes(KC_PWR, KC_NO);
    }
  }
}
