#include "release_gate.h"

void reset_release_gate(release_gate_t* release_gate) {
    release_gate->state = NONE;
    release_gate->last_pressed = KC_NO;
    clear_keyboard();
}

bool press_release_gate(release_gate_t* release_gate) {
    release_gate->state = DECIDE;
    release_gate->last_pressed = RELEASE_GATE;
    return false;
}

bool release_release_gate(release_gate_t* release_gate) {
    if (release_gate->state != BLOCK)
        reset_release_gate(release_gate);
    else if (release_gate->last_pressed == KC_NO)
        release_gate->state = DECIDE;
    else
        release_gate->state = PASS;
    return false;
}

bool press_key_with_release_gate(release_gate_t* release_gate, uint16_t keycode) {
    switch (release_gate->state) {
        case DECIDE:
            if (release_gate->last_pressed == RELEASE_GATE)
                release_gate->state = BLOCK;
            else
                release_gate->state = PASS;
            release_gate->last_pressed = keycode;
            break;
        case BLOCK:
            release_gate->last_pressed = keycode;
            break;
        default: break;
    }
    return true;
}

bool release_key_with_release_gate(release_gate_t* release_gate, uint16_t keycode) {
    switch (release_gate->state) {
        case PASS:
            if (release_gate->last_pressed == keycode)
                reset_release_gate(release_gate);
            break;
        case DECIDE:
            if (release_gate->last_pressed != RELEASE_GATE)
                reset_release_gate(release_gate);
            else
                release_gate->state = PASS;
            return false;
        case BLOCK:
            if (release_gate->last_pressed != keycode)
                reset_release_gate(release_gate);
            else
                release_gate->last_pressed = KC_NO;
            return false;
        default: break;
    }
    return true;
}

