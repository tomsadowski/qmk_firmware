#include "action.h"
#include "my_keycodes.h"

typedef enum {
    DECIDE,
    BLOCK,
    PASS,
    NONE
} release_gate_state_t;

typedef struct {
    release_gate_state_t state;
    uint16_t last_pressed;
} release_gate_t;

void reset_release_gate(void);

bool press_release_gate(void);

bool release_release_gate(void);

bool press_key_with_release_gate(uint16_t);

bool release_key_with_release_gate(uint16_t);
