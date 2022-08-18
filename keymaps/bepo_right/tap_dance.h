#pragma once
#include "utils.h"
#include "shortcuts.h"
#include "process_tap_dance.h"


/* Easy Tap Dance states
 * bit      desc
 * 8        key state: 0 hold 1 tapped
 * 7        single tap
 * 6        double tap
 * 5        ...
 */
enum {
  UNKNOWN_TD = 0x00,
  SINGLE_HOLD_TD,
  SINGLE_TAP_TD,
  DOUBLE_HOLD_TD,
  DOUBLE_TAP_TD,
  DOUBLE_SINGLE_TAP_TD,
  TRIPLE_HOLD_TD,
  TRIPLE_TAP_TD,
  TRIPLE_SINGLE_TAP_TD,
  QUADRU_HOLD_TD,
  QUADRU_TAP_TD,
  QUADRU_SINGLE_TAP_TD,
  FIVEFOLD_HOLD_TD,
  FIVEFOLD_TAP_TD,
  FIVEFOLD_SINGLE_TAP_TD,
  SIXFOLD_HOLD_TD,
  SIXFOLD_TAP_TD,
  SIXFOLD_SINGLE_TAP_TD
};



 typedef struct {
    uint16_t hold;
    uint16_t tap;
    uint16_t dtap;
} qk_tap_dance_hold_dtap_t;

uint8_t check_tap_state(qk_tap_dance_state_t *_state);



/**************************************************************************
 * Add predefined action like quantum/process_keycode/process_tap_dance.h *
 **************************************************************************/
 

// Functions (F1, F2, …)
#define FUNCTION_TAP(kc, kcF) \
    { .fn = {NULL, td_function_finished, td_function_reset}, .user_data = (void *)&((qk_tap_dance_pair_t){kc, kcF}), }
void td_function_finished(qk_tap_dance_state_t *_state , void *user_data);
void td_function_reset(qk_tap_dance_state_t *_state , void *user_data);

// Tap hold shift
void td_LShift_finished(qk_tap_dance_state_t *_state , void *user_data);
void td_LShift_reset(qk_tap_dance_state_t *_state , void *user_data);
void td_RShift_finished(qk_tap_dance_state_t *_state , void *user_data);
void td_RShift_reset(qk_tap_dance_state_t *_state , void *user_data);



// LShift
void td_WinLeftShift_finished(qk_tap_dance_state_t *_state, void *user_data);
void td_WinLeftShift_reset(qk_tap_dance_state_t *_state, void *user_data);

// RShift
void td_RightShift_finished(qk_tap_dance_state_t *_state, void *user_data);
void td_RightShift_reset(qk_tap_dance_state_t *_state, void *user_data);

// Enter
void td_Enter_finished(qk_tap_dance_state_t *_state, void *user_data);
void td_Enter_reset(qk_tap_dance_state_t *_state, void *user_data);




// Generic hold tap macros
// hold tap
#define ACTION_HOLD_TAP(tap, hold) \
    { .fn = {NULL, td_holdtap_finished, td_holdtap_reset}, .user_data = (void *)&((qk_tap_dance_pair_t){tap, hold}), }
void td_holdtap_finished(qk_tap_dance_state_t *_state , void *user_data);
void td_holdtap_reset(qk_tap_dance_state_t *_state , void *user_data);
// hold tap doubletap
#define ACTION_HOLD_DTAP(hold, tap, dtap) \
    { .fn = {NULL, td_holddtap_finished, td_holddtap_reset}, .user_data = (void *)&((qk_tap_dance_hold_dtap_t){hold, tap, dtap}), }
void td_holddtap_finished(qk_tap_dance_state_t *_state , void *user_data);
void td_holddtap_reset(qk_tap_dance_state_t *_state , void *user_data);

// ACTION_HOLD_TAP(tap, hold);



