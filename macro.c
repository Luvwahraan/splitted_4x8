#include QMK_KEYBOARD_H
#include "keymap_bepo.h"
#include "keymap_french.h"
#include "macro.h"
#include "utils.h"
#include "shortcuts.h"


enum custom_keycodes {
    M_DAQ = SAFE_RANGE, // «  »
    M_PAR,              // ()
    M_CRO,              // []
    M_BRA,              // {}
};

bool process_record_user(uint16_t kc, keyrecord_t *record) {
    if (process_left_macro(kc, record)) { return true; }
    
    return true;
};

bool process_left_macro(uint16_t kc, keyrecord_t *record) {
    switch (kc) {
    case M_DAQ:
        if (record->event.pressed) {
            // pressed
        } else {
            //released
            tap_code(BP_LDAQ);
            tap_code(LSFT(BP_SPC)); 
            tap_code(LSFT(BP_SPC));
            tap_code(BP_RDAQ);
            tap_code(KC_LEFT);
            tap_code(KC_LEFT);
            return true;
        }
        break;
    case M_PAR:
        if (record->event.pressed) {
            // pressed
        } else {
            //released
            tap_code(BP_LPRN);
            tap_code(BP_RPRN);
            tap_code(KC_LEFT);
            return true;
        }
        break;
    case M_DAQ:
        if (record->event.pressed) {
            // pressed
        } else {
            //released
            tap_code(LART(BP_LPRN));
            tap_code(LART(BP_LPRN));
            tap_code(KC_LEFT);
            return true;
        }
        break;
    case M_DAQ:
        if (record->event.pressed) {
            // pressed
        } else {
            //released
            tap_code(LART(BP_AGRV));
            tap_code(LART(BP_AGRV));
            tap_code(KC_LEFT);
            return true;
        }
        break;
    }
    return false;
}