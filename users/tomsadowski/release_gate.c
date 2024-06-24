#include "release_gate.h"

bool press_release_gate(release_gate_t* release_gate) {

    release_gate->state = DECIDE;

    return false;
}

bool release_release_gate(release_gate_t* release_gate) {
    if (release_gate->state == SUSPEND)
        close_release_gate(release_gate);

    else if (release_gate->switch_code == KC_NO)
        release_gate->state = WATCH;

    else
        release_gate->state = LEND;

    return false;
}

bool press_key_with_release_gate(release_gate_t* release_gate, uint16_t keycode) {
    switch (release_gate->state) {
        case BLOCK:
            release_gate->switch_code = keycode;
            return true;

        case DECIDE:
            release_gate->switch_code = keycode;
            release_gate->state = BLOCK;
            return true;

        case WATCH:
            release_gate->switch_code = keycode;
            release_gate->state = SUSPEND;

        default: return true;
    }
}

bool release_key_with_release_gate(release_gate_t* release_gate, uint16_t keycode) {
    switch (release_gate->state) {
        case BLOCK:
            if (release_gate->switch_code == keycode)
                release_gate->switch_code = KC_NO;
            return false;

        case LEND:
            if (release_gate->switch_code == keycode) {
                release_gate->state = WATCH;
                release_gate->switch_code = KC_NO;
            }
            return false;

        case DECIDE:
            release_gate->state = SUSPEND;

        case WATCH:
            close_release_gate(release_gate);

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
    clear_keyboard();
}
