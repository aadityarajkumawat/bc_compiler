//
// Created by aditya on 19/12/21.
//

#ifndef BC_COMPILER_BC_STATE_H
#define BC_COMPILER_BC_STATE_H

#include <string>
#include <vector>
#include <utility>

class BC_State {

    /*
     * List of transitions from the current
     * state, stored in a vector of pairs having
     * memory address of state and the transition
     * type to that state
     */
    // [{state, }]
    std::vector<std::pair<BC_State *, std::string>> transitions;

public:
    /*
     * Give name to a state to uniquely
     * identify a particular state.
     */
    std::string state_name;
    explicit BC_State(std::string *state_name);
    void add_transition(BC_State *state, std::string *transition_type);
    std::vector<std::pair<BC_State *, std::string>> get_transitions();
};

#endif // BC_COMPILER_BC_STATE_H
