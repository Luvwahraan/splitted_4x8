#pragma once
#include "utils.h"
#include "shortcuts.h"
#include "process_tap_dance.h"



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
  
  TDCOPYPASTE,
  TDCOPYCUT,
  
  // Left hand tap dances
  LRETMODS,
  TDBTAB,
  TDLSHIFTAGRV,
  TDLSHIFTA,
  TDAGRVSUPER,
  TDYLGUI,
  TDFRALT,
  TDDOTUNDO,
  TDKFN,
  TDXCUT,
  TDEGRVHOME,
  TDCOMMAEND,
  
  // Right hand tap dances
  RRETMODS,
  TDRSHIFTW,
  TDRSHIFTM, 
  TDFAPP,
  TDCCEDEMOJI,
  QUOTFN,
  TDQUNDO,
  
  // Both hands tap dances
  TDSPCALT,
 
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

#define TD_MUTE     TD(TDMUTERCTL)
#define TD_CPP      TD(TDCOPYPASTE)
#define TD_CPC      TD(TDCOPYCUT)
#define TD_XCUT     TD(TDXCUT)

#define TD_CCED     TD(TDCCEDEMOJI)
#define TD_AGRV     TD(TDLSHIFTAGRV)
#define TD_EGRV     TD(TDEGRVHOME)
#define TD_Y        TD(TDYLGUI)
#define TD_B        TD(TDBTAB)
#define TD_F        TD(TDFAPP)
#define TD_DOT      TD(TDDOTUNDO)
#define TD_K        TD(TDKFN)
#define TD_QUOT     TD(QUOTFN)
#define TD_Q        TD(TDQUNDO)
#define TD_W        TD(TDRSHIFTW)
#define TD_M        TD(TDRSHIFTM)
#define TD_A        TD(TDLSHIFTA)
#define TD_COMM     TD(TDCOMMAEND)

#define TD_SPC      TD(TDSPCALT)
#define TD_LRET     TD(LRETMODS)
#define TD_RRET     TD(RRETMODS)

#define BP_FN       KC_NO

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
    uint16_t dhold;
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
#define ACTION_HOLD_DTAP(tap, hold, dtap, dhold) \
    { .fn = {NULL, td_holddtap_finished, td_holddtap_reset}, .user_data = (void *)&((qk_tap_dance_hold_dtap_t){tap, hold, dtap, dhold}), }
void td_holddtap_finished(qk_tap_dance_state_t *_state , void *user_data);
void td_holddtap_reset(qk_tap_dance_state_t *_state , void *user_data);

// ACTION_HOLD_TAP(tap, hold);



