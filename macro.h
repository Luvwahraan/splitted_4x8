#pragma once
#include "utils.h"
#include "shortcuts.h"


bool process_record_user(uint16_t kc, keyrecord_t *record);
//void post_process_record_user(uint16_t kc, keyrecord_t *record);

// return true if do something.
bool process_left_macro(uint16_t kc, keyrecord_t *record);
