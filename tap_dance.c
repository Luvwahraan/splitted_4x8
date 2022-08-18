#include QMK_KEYBOARD_H
#include "keymap_bepo.h"
#include "keymap_french.h"
#include "tap_dance.h"
#include "utils.h"
#include "shortcuts.h"



static uint8_t tdState = 0;

uint8_t check_tap_state(qk_tap_dance_state_t *_state) {
  uint8_t danceState = UNKNOWN_TD;
  switch (_state->count) {
    case 1:
      if (_state->interrupted || _state->pressed==0) danceState = SINGLE_TAP_TD;
      else danceState = SINGLE_HOLD_TD;
      break;
    case 2:
      if (_state->interrupted) danceState = DOUBLE_SINGLE_TAP_TD;
      else if (_state->pressed) danceState = DOUBLE_HOLD_TD;
      else danceState = DOUBLE_TAP_TD;
      break;
    case 3:
      if (_state->interrupted) danceState = TRIPLE_SINGLE_TAP_TD;
      else if (_state->pressed) danceState = TRIPLE_HOLD_TD;
      else danceState = TRIPLE_TAP_TD;
      break;
    case 4:
      if (_state->interrupted) danceState = QUADRU_SINGLE_TAP_TD;
      else if (_state->pressed) danceState = QUADRU_HOLD_TD;
      else danceState = QUADRU_TAP_TD;
      break;
    case 5:
      if (_state->interrupted) danceState = FIVEFOLD_SINGLE_TAP_TD;
      else if (_state->pressed) danceState = FIVEFOLD_HOLD_TD;
      else danceState = FIVEFOLD_TAP_TD;
      break;
    case 6:
      if (_state->interrupted) danceState = SIXFOLD_SINGLE_TAP_TD;
      else if (_state->pressed) danceState = SIXFOLD_HOLD_TD;
      else danceState = SIXFOLD_TAP_TD;
      break;
  }

  return danceState;
}

// Functions
void td_function_finished(qk_tap_dance_state_t *_state, void *user_data) {
  qk_tap_dance_pair_t *pair = (qk_tap_dance_pair_t *)user_data;
  switch (_state->count) {
    case 1: register_code(pair->kc1); break;
    case 2: register_code(pair->kc2); break;
    case 3: register_code(KC_LALT); register_code(pair->kc2); break;
    case 4: register_code(KC_LCTRL); register_code(pair->kc2); break;
    default: register_code(pair->kc1); break;
  }
}
void td_function_reset(qk_tap_dance_state_t *_state, void *user_data) {
  qk_tap_dance_pair_t *pair = (qk_tap_dance_pair_t *)user_data;
  switch (_state->count) {
    case 1: unregister_code(pair->kc1); break;
    case 2: unregister_code(pair->kc2); break;
    case 3: unregister_code(KC_LALT); unregister_code(pair->kc2); break;
    case 4: unregister_code(KC_LCTRL); unregister_code(pair->kc2); break;
    default: unregister_code(pair->kc1); break;
  }
}
// end Function



// Hold tap
void td_holdtap_finished(qk_tap_dance_state_t *_state, void *user_data) {
  qk_tap_dance_pair_t *pair = (qk_tap_dance_pair_t *)user_data;
  tdState = check_tap_state(_state);
  switch (tdState) {
  case SINGLE_TAP_TD:
    register_code(pair->kc1);
    break;
  case SINGLE_HOLD_TD:
    register_code(pair->kc2);
    break;
  case UNKNOWN_TD:
  default:
    register_code(pair->kc2);
    break;
  }
}
void td_holdtap_reset(qk_tap_dance_state_t *_state, void *user_data) {
  qk_tap_dance_pair_t *pair = (qk_tap_dance_pair_t *)user_data;
  tdState = check_tap_state(_state);
  switch (tdState) {
  case SINGLE_TAP_TD:
    unregister_code(pair->kc1);
    break;
  case SINGLE_HOLD_TD:
    unregister_code(pair->kc2);
    break;
  case UNKNOWN_TD:
  default:
    unregister_code(pair->kc2);
    break;
  }
  tdState = 0;
}

void td_holddtap_finished(qk_tap_dance_state_t *_state, void *user_data) {
  qk_tap_dance_hold_dtap_t *hdtap = (qk_tap_dance_hold_dtap_t *)user_data;
  tdState = check_tap_state(_state);
  switch (tdState) {
  case SINGLE_TAP_TD:
    register_code(hdtap->tap);
    break;
  case SINGLE_HOLD_TD:
    register_code(hdtap->hold);
    break;
  case DOUBLE_TAP_TD:
    register_code(hdtap->dtap);
    unregister_code(hdtap->dtap);
    register_code(hdtap->dtap);
    break;
  case DOUBLE_HOLD_TD:
    register_code(hdtap->dhold);
    break;
  case UNKNOWN_TD:
  default:
    register_code(hdtap->hold);
    break;
  }
}
void td_holddtap_reset(qk_tap_dance_state_t *_state, void *user_data) {
  qk_tap_dance_hold_dtap_t *hdtap = (qk_tap_dance_hold_dtap_t *)user_data;
  tdState = check_tap_state(_state);
  switch (tdState) {
  case SINGLE_TAP_TD:
    unregister_code(hdtap->tap);
    break;
  case SINGLE_HOLD_TD:
    unregister_code(hdtap->hold);
    break;
  case DOUBLE_TAP_TD:
    unregister_code(hdtap->dtap);
    break;
  case DOUBLE_HOLD_TD:
    unregister_code(hdtap->dhold);
    break;
  case UNKNOWN_TD:
  default:
    unregister_code(hdtap->hold);
    break;
  }
  tdState = 0;
}
// End hold tap



// Hold: shift, Tap: compose, Double tap: compose compose
void td_LShift_finished(qk_tap_dance_state_t *_state, void *user_data) {
  tdState = check_tap_state(_state);
  switch (tdState) {
  case SINGLE_TAP_TD:
      register_code(BP_COMPOSE);
      break;
  case SINGLE_HOLD_TD:
      register_code(KC_LSHIFT);
      break;
  case DOUBLE_TAP_TD:
      register_code(BP_COMPOSE);
      unregister_code(BP_COMPOSE);
      register_code(BP_COMPOSE);
      break;
  case UNKNOWN_TD:
  default:
      register_code(BP_COMPOSE);
      break;
    }
}
void td_LShift_reset(qk_tap_dance_state_t *_state, void *user_data) {
  tdState = check_tap_state(_state);
  switch (tdState) {
    case SINGLE_TAP_TD:
      unregister_code(BP_COMPOSE);
      break;
    case SINGLE_HOLD_TD:
      unregister_code(KC_LSHIFT);
      break;
    case UNKNOWN_TD:
    case DOUBLE_TAP_TD:
      unregister_code(BP_COMPOSE);
    default:
      unregister_code(BP_COMPOSE);
      break;
  }
  tdState = 0;
}
void td_RShift_finished(qk_tap_dance_state_t *_state, void *user_data) {
  tdState = check_tap_state(_state);
  switch (tdState) {
  case SINGLE_TAP_TD:
      register_code(BP_COMPOSE);
      break;
  case SINGLE_HOLD_TD:
      register_code(KC_RSHIFT);
      break;
  case DOUBLE_TAP_TD:
      register_code(BP_COMPOSE);
      unregister_code(BP_COMPOSE);
      register_code(BP_COMPOSE);
      break;
  case UNKNOWN_TD:
  default:
      register_code(BP_COMPOSE);
      break;
  }
}
void td_RShift_reset(qk_tap_dance_state_t *_state, void *user_data) {
  tdState = check_tap_state(_state);
  switch (tdState) {
    case SINGLE_TAP_TD:
      unregister_code(BP_COMPOSE);
      break;
    case SINGLE_HOLD_TD:
      unregister_code(KC_RSHIFT);
      break;
    case UNKNOWN_TD:
    case DOUBLE_TAP_TD:
      unregister_code(BP_COMPOSE);
    default:
      unregister_code(BP_COMPOSE);
      break;
  }
  tdState = 0;
}
// End generic hold shift



qk_tap_dance_action_t tap_dance_actions[] = {
 
  // Change workspace
  [TDLDESKMAJWIN]   = ACTION_TAP_DANCE_DOUBLE(KC_SPACE, WLWS),
  [TDLDESKMAJLINUX] = ACTION_TAP_DANCE_DOUBLE(KC_SPACE, LWS),
  [TDRDESKMAJWIN]   = ACTION_TAP_DANCE_DOUBLE(KC_SPACE, WRWS),
  [TDRDESKMAJLINUX] = ACTION_TAP_DANCE_DOUBLE(KC_SPACE, RWS),

  // Double tap
  [TCOPY]       = ACTION_TAP_DANCE_DOUBLE(KC_LEFT,  KC_COPY),
  [TPASTE]      = ACTION_TAP_DANCE_DOUBLE(KC_UP,    KC_PASTE),
  [TDCOPYPASTE] = ACTION_TAP_DANCE_DOUBLE(BP_COPY,  BP_PASTE),
  [TDCOPYCUT]   = ACTION_TAP_DANCE_DOUBLE(BP_COPY,  BP_CUT),  
  [TDBPESC]     = ACTION_TAP_DANCE_DOUBLE(BP_DOLLAR,KC_ESC),
  [TDFRESC]     = ACTION_TAP_DANCE_DOUBLE(FR_DLR,   KC_ESC),
  [TDXCUT]      = ACTION_TAP_DANCE_DOUBLE(BP_X,     BP_CUT),
  [TDYLGUI]     = ACTION_TAP_DANCE_DOUBLE(BP_Y,     KC_LGUI),
  [TDBTAB]      = ACTION_TAP_DANCE_DOUBLE(BP_B,     KC_TAB),
  [TDDOTUNDO]   = ACTION_TAP_DANCE_DOUBLE(BP_DOT,   BP_UNDO),
  [TDQUNDO]     = ACTION_TAP_DANCE_DOUBLE(BP_Q,     BP_UNDO),
  [TDCCEDEMOJI] = ACTION_TAP_DANCE_DOUBLE(BP_CCED,  BP_EMOJI),
  [TDEGRVHOME]  = ACTION_TAP_DANCE_DOUBLE(BP_EGRV,  KC_HOME),
  [TDCOMMAEND]  = ACTION_TAP_DANCE_DOUBLE(BP_COMM,  KC_END),

  // Ex. → F1: tap=" doubde tap=F1 triple tap=alt+F1 four tap= lctrl+F1
  [TRF1]    = FUNCTION_TAP(BP_DQUO, KC_F1),
  [TRF2]    = FUNCTION_TAP(BP_LDAQ, KC_F2),
  [TRF3]    = FUNCTION_TAP(BP_RDAQ, KC_F3),
  [TRF4]    = FUNCTION_TAP(BP_LPRN, KC_F4),
  [TRF5]    = FUNCTION_TAP(BP_RPRN, KC_F5),
  [TRF6]    = FUNCTION_TAP(BP_AT,   KC_F6),
  [TRF7]    = FUNCTION_TAP(BP_PLUS, KC_F7),
  [TRF8]    = FUNCTION_TAP(BP_MINS, KC_F8),
  [TRF9]    = FUNCTION_TAP(BP_SLSH, KC_F9),
  [TRF10]   = FUNCTION_TAP(BP_ASTR, KC_F10),
  [TRF11]   = FUNCTION_TAP(BP_EQL,  KC_F11),
  [TRF12]   = FUNCTION_TAP(BP_PERC, KC_F12),
  
  
  // ACTION_HOLD_TAP(tap, hold)
  [TDFAPP]       = ACTION_HOLD_TAP(BP_F,    KC_APP),
  [TDRSHIFTW]    = ACTION_HOLD_TAP(BP_W,    KC_RSHIFT),
  [TDRSHIFTM]    = ACTION_HOLD_TAP(BP_M,    KC_RSHIFT),
  [TDLSHIFTAGRV] = ACTION_HOLD_TAP(BP_AGRV, KC_LSHIFT),
  [TDLSHIFTA]    = ACTION_HOLD_TAP(BP_A,    KC_LSHIFT),

  // ACTION_HOLD_DTAP(Hold, tap, double tap, double tap hold)
  [TDSPCALT]    = ACTION_HOLD_DTAP(KC_SPC,   KC_ALGR,   KC_SPC,     (KC_ALGR|KC_LSHIFT)),
  [TDKFN]       = ACTION_HOLD_DTAP(BP_K,     BP_FN,     BP_COMPOSE, BP_COMPOSE),
  [QUOTFN]      = ACTION_HOLD_DTAP(BP_QUOT,  BP_FN,     BP_COMPOSE, BP_COMPOSE),
  [LRETMODS]    = ACTION_HOLD_DTAP(KC_ENTER, KC_LALT,   KC_ENTER,   KC_LCTL),
  [RRETMODS]    = ACTION_HOLD_DTAP(KC_ENTER, KC_LALT,   KC_ENTER,   KC_RCTL),
};

