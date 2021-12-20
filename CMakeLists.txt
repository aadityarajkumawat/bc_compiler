cmake_minimum_required(VERSION 3.20)
project(bc_compiler)

set(CMAKE_CXX_STANDARD 14)

add_executable(bc_compiler main.cpp Node.cpp Node.h Evaluator.cpp Evaluator.h BCUtils.cpp BCUtils.h BC_FSM.cpp BC_FSM.h BC_State.cpp BC_State.h BC_FSM_ParsingResponse.cpp BC_FSM_ParsingResponse.h)
