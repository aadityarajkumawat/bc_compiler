//
// Created by aditya on 19/12/21.
//

#include "BC_State.h"

BC_State::BC_State(std::string *state_name) {
    this->state_name = *state_name;
}

void BC_State::add_transition(BC_State *state, std::string *transition_type) {
    std::pair<BC_State *, std::string> state_and_transition (state, *transition_type);
    transitions.push_back(state_and_transition);
}

std::vector<std::pair<BC_State *, std::string>> BC_State::get_transitions() {
    return transitions;
}
