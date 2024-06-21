#include "release_gate.h"

bool press_release_gate(release_gate_t* release_gate) {

    release_gate->state = BLOCK;

    return false;
}

bool release_release_gate(release_gate_t* release_gate) {

    if (release_gate->switch_code == KC_NO)
        release_gate->state = WATCH;
    else
        release_gate->state = LEND;
    return false;
}

bool press_key_with_release_gate(release_gate_t* release_gate, uint16_t keycode) {

    if (release_gate->state == BLOCK)
        release_gate->switch_code = keycode;
    else if (release_gate->state == WATCH) {
        release_gate->switch_code = keycode;
        release_gate->state = SUSPEND;
    }
    return true;
}

bool release_key_with_release_gate(release_gate_t* release_gate, uint16_t keycode) {

    switch (release_gate->state) {
        case BLOCK:
            if (release_gate->switch_code == keycode)
                release_gate->switch_code = KC_NO;
            if (release_gate->size < MAX_BLOCK) {
                release_gate->blocked_codes[release_gate->size] = keycode;
                release_gate->size++;
            }
            return false;

        case LEND:
            if (release_gate->switch_code == keycode) {
                release_gate->state = WATCH;
                release_gate->switch_code = KC_NO;
            }
            if (release_gate->size < MAX_BLOCK) {
                release_gate->blocked_codes[release_gate->size] = keycode;
                release_gate->size++;
            }
            return false;

        case SUSPEND:
            if (release_gate->switch_code == keycode)
                close_release_gate(release_gate);
            return true;

        default: return true; // shouldn't get here
    }
}

void close_release_gate(release_gate_t* release_gate) {
    release_gate->state = NONE;
    release_gate->switch_code = KC_NO;
    for (int i = 0; i < release_gate->size; i++) {
        unregister_code(release_gate->blocked_codes[i]);
        release_gate->blocked_codes[i] = KC_NO;
    }
    release_gate->size = 0;
}
