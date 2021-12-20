#include <bits/stdc++.h>

#include "Evaluator.h"
#include "Node.h"
#include "BC_FSM.h"

int main(int argc, char **argv) {

    for (int i = 0; i < argc; i++) {
        std::string cmd = argv[i];

        if (i == 0) continue;

        if (i == 1 && cmd != "run") {
            std::cout << "Invalid Command!" << std::endl;
            return 0;
        } else if (i == 2 && cmd.substr(cmd.length() - 3, cmd.length()) != ".bc") {
            std::cout << "Only .bc files are compiled" << std::endl;
            return 0;
        }
    }

    std::string file_loc = argv[2];

    std::ifstream file;

    file.open(file_loc);

    std::string file_data;

    if (file.is_open()) {
        char mychar;
        while (file) {
            mychar = file.get();
            file_data += BCUtils::parse_string(mychar);
        }
    }

    std::string s = file_data;

    auto *state_machine = new BC_FSM();

    state_machine->build_state_machine();
    auto *response = state_machine->validate_expression(&s);

    if (response->status == 1) {
        Evaluator::sanitizeExpression(&s);
        auto *root = Evaluator::buildExpressionTree(&s);
        int val = Evaluator::evaluateTree(root);
        std::cout << val << std::endl;
    } else {
        std::cout << "Incorrect Syntax!" << std::endl;
        std::cout << "Error: " << response->error << std::endl;
    }

    return 0;
}
