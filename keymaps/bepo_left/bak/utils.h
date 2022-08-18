#ifndef SPLIT_REDUCED_UTILS
#define SPLIT_REDUCED_UTILS

#define U32(x)  (1UL << x)

enum next_key_down_up
{
    NK_DOWN_UP,
    NK_DOWN,
    NK_UP // a bit of a hack, this works as long as NK_UP < KC_A
};

void send_keystrokes(uint8_t key, ...);

#endif
