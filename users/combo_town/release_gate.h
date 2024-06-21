#include "action.h"

#define MAX_BLOCK 8

typedef enum {
    BLOCK,
    WATCH,
    LEND,
    SUSPEND,
    NONE
} release_gate_state_t;

typedef struct {
    release_gate_state_t state;
    uint16_t switch_code;
    uint16_t blocked_codes[MAX_BLOCK];
    unsigned short size;
} release_gate_t;


bool press_release_gate(release_gate_t*);

bool release_release_gate(release_gate_t*);

bool press_key_with_release_gate(release_gate_t*, uint16_t);

bool release_key_with_release_gate(release_gate_t*, uint16_t);
