//
// Created by Ben Ho on 5/3/2023.
//

#include "States.h"

States::States() {
    for (int i = 0; i < LAST_STATE; ++i) {
        states[static_cast<states_enum>(i)] = false;
    }
}

void States::enable_state(states_enum state) {
    states[state] = true;
}

void States::disable_state(states_enum state) {
    states[state] = false;
}

bool States::check_state(states_enum state) {
    return states[state];
}

void States::toggle_state(states_enum state) {
    states[state] = !states[state];
}