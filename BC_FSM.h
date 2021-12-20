//
// Created by aditya on 19/12/21.
//

#ifndef BC_COMPILER_BC_FSM_H
#define BC_COMPILER_BC_FSM_H

#include "BC_State.h"
#include "Node.h"
#include "BC_FSM_ParsingResponse.h"
#include <string>
#include <vector>

class BC_FSM {
    std::vector<BC_State *> states;
    std::vector<std::string> state_names;
    std::vector<std::string> transition_types;
    int builder_state_count;
    BC_State **global_current_state{};


private:
    std::string *get_state_name();

    std::string *get_transition_type(int i);

public:
    BC_FSM();

    void build_state_machine();

    BC_FSM_ParsingResponse *validate_expression(std::string *syntax);
};

#endif // BC_COMPILER_BC_FSM_H
