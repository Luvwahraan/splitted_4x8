#include QMK_KEYBOARD_H
#include "keymap_bepo.h"
#include "keymap_french.h"
#include "utils.h"

void send_keystrokes(uint8_t key, ...)
{
    va_list vl;
    va_start(vl, key);
    enum next_key_down_up nkdu = NK_DOWN_UP;
    while (key != KC_NO)
    {
        if (key < KC_A)
        {
            nkdu = key;
        } else {
            switch (nkdu) {
            case NK_DOWN_UP:
                register_code(key);
            case NK_UP:
                unregister_code(key);
                break;
            case NK_DOWN:
                register_code(key);
            }
            nkdu = NK_DOWN_UP;
        }
        key = va_arg(vl, int);
    }
    va_end(vl);
}
