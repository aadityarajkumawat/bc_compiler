//
// Created by aditya on 19/12/21.
//

#include "BC_FSM_ParsingResponse.h"

BC_FSM_ParsingResponse::BC_FSM_ParsingResponse(int status, std::string *error) {
    this->status = status;
    this->error = *error;
}
