//
// Created by aditya on 19/12/21.
//

#include "BC_FSM.h"
#include "BCUtils.h"

BC_FSM::BC_FSM() {
    // initialize starting of state machine
    builder_state_count = 0;

    // possible states in our syntax fsm
    state_names = {
            "q0",
            "q1",
            "q2",
            "q3",
            "q4",
            "q5",
            "q6",
            "q7",
            "q8",
            "q9",
            "q10",
            "ISE", // Invalid Syntax Error
            "IOE"  // Invalid Operation Error
    };

    transition_types = {
            "s",            // 0
            "o",            // 1
            "l",            // 2
            "v",            // 3
            "e",            // 4
            "<space>",      // 5
            "<number>",     // 6
            "<operator>",   // 7
            "<any>"         // 8
    };
}

std::string *BC_FSM::get_state_name() {
    return &(state_names[builder_state_count++]);
}

std::string *BC_FSM::get_transition_type(int i) {
    return &(transition_types[i]);
}

void BC_FSM::build_state_machine() {
    auto *q0 = new BC_State(get_state_name());
    auto *q1 = new BC_State(get_state_name());
    auto *q2 = new BC_State(get_state_name());
    auto *q3 = new BC_State(get_state_name());
    auto *q4 = new BC_State(get_state_name());
    auto *q5 = new BC_State(get_state_name());
    auto *q6 = new BC_State(get_state_name());
    auto *q7 = new BC_State(get_state_name());
    auto *q8 = new BC_State(get_state_name());
    auto *q9 = new BC_State(get_state_name());
    auto *q10 = new BC_State(get_state_name());
    auto *ise = new BC_State(get_state_name());
    auto *ioe = new BC_State(get_state_name());

    // connect these states according to the state diagram

    // for 'solve' part
    q0->add_transition(q1, get_transition_type(0));
    q0->add_transition(ise, get_transition_type(8));

    q1->add_transition(q2, get_transition_type(1));
    q1->add_transition(ise, get_transition_type(8));

    q2->add_transition(q3, get_transition_type(2));
    q2->add_transition(ise, get_transition_type(8));

    q3->add_transition(q4, get_transition_type(3));
    q3->add_transition(ise, get_transition_type(8));

    q4->add_transition(q5, get_transition_type(4));
    q4->add_transition(ise, get_transition_type(8));

    q5->add_transition(q6, get_transition_type(5));
    q5->add_transition(ise, get_transition_type(8));

    // post 'solve' part
    q6->add_transition(q6, get_transition_type(5));
    q6->add_transition(q7, get_transition_type(6));
    q6->add_transition(q8, get_transition_type(7));

    q7->add_transition(q7, get_transition_type(6));
    q7->add_transition(q8, get_transition_type(7));
    q7->add_transition(q10, get_transition_type(5));

    q8->add_transition(q7, get_transition_type(6));
    q8->add_transition(q9, get_transition_type(5));
    q8->add_transition(ioe, get_transition_type(7));

    q9->add_transition(q7, get_transition_type(6));
    q9->add_transition(ioe, get_transition_type(7));

    q10->add_transition(q8, get_transition_type(7));
    q10->add_transition(ioe, get_transition_type(6));

    states.push_back(q0);
    states.push_back(q1);
    states.push_back(q2);
    states.push_back(q3);
    states.push_back(q4);
    states.push_back(q5);
    states.push_back(q6);
    states.push_back(q7);
    states.push_back(q8);
    states.push_back(q9);
    states.push_back(q10);
    states.push_back(ise);
    states.push_back(ioe);
}

BC_FSM_ParsingResponse *BC_FSM::validate_expression(std::string *syntax) {
    // traversing the FSM state diagram like a directed weighted graph

    std::string error;

    if ((*syntax).substr(0, 5) != "solve") {
        error = "Invalid Syntax Error";
        return new BC_FSM_ParsingResponse(2, &error);
    }

    global_current_state = (&states[0]);

    // test case: "solve 4 + 11 * 2"
    for (int i = 0; i < (*syntax).length(); i++) {
        std::string current_value = BCUtils::get_char_at(syntax, i);

        if ((**global_current_state).state_name == "IOE") {
            error = "Invalid Operation Error";
            return new BC_FSM_ParsingResponse(2, &error);
        }

        std::vector<std::pair<BC_State *, std::string>> current_transitions = (**global_current_state).get_transitions();
        std::string state_name = (**global_current_state).state_name;

        for (int j = 0; j < current_transitions.size(); j++) {
            std::pair<BC_State *, std::string> current_transition = current_transitions[j];

            std::string transition = current_transition.second;

            bool is_alpha_and_equal = (BCUtils::is_alpha(&current_value) && current_value == transition);
            bool is_space_and_transition = (BCUtils::is_space(&current_value) && transition == "<space>");
            bool is_number_and_transition = (BCUtils::is_number(&current_value) && transition == "<number>");
            bool is_operator_and_transition = (BCUtils::is_operator(&current_value) && transition == "<operator>");

            if (is_alpha_and_equal || is_space_and_transition || is_number_and_transition ||
                is_operator_and_transition) {
                global_current_state = &(current_transition.first);
                j = current_transitions.size();
            }
        }
    }

    return new BC_FSM_ParsingResponse(1, &error);
}
