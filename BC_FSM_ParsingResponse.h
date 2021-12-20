//
// Created by aditya on 19/12/21.
//

#ifndef BC_COMPILER_BC_FSM_PARSINGRESPONSE_H
#define BC_COMPILER_BC_FSM_PARSINGRESPONSE_H


#include <string>

class BC_FSM_ParsingResponse {

public:
    // status -> 1: OK
    // status -> 2: ERROR

    int status;
    std::string error;

    BC_FSM_ParsingResponse(int status, std::string *error);
};


#endif //BC_COMPILER_BC_FSM_PARSINGRESPONSE_H
