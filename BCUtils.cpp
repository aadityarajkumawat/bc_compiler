//
// Created by aditya on 18/12/21.
//

#include "BCUtils.h"

#include <string>

bool BCUtils::is_digit(std::string *x) {
    std::string digit = *x;

    bool result = digit == "0" || digit == "1" || digit == "2" ||
                  digit == "3" || digit == "4" || digit == "5" ||
                  digit == "6" || digit == "7" || digit == "8" || digit == "9";

    return result;
}

bool BCUtils::is_number(std::string *numberI) {
    std::string number = *numberI;
    for (int i = 0; i < number.length(); i++) {
        std::string digit = number.substr(i, 1);
        if (!is_digit(&digit))
            return false;
    }
    return true;
}

int BCUtils::parseInt(std::string *s) {
    int num = 0;
    std::string str = *s;

    if (str[0] != '-') {
        for (char i: str) {
            num = num * 10 + (int(i) - 48);
        }
    } else {
        for (char i: str) {
            num = num * 10 + (int(i) - 48);
            num = num * -1;
        }
    }

    return num;
}

std::string BCUtils::get_char_at(std::string *s, int i) {
    return (*s).substr(i, 1);
}

bool BCUtils::is_alpha(std::string *s) {
    return std::isalpha((*s)[0]);
}

bool BCUtils::is_operator(std::string *s) {
    char op = (*s)[0];
    return (
            op == '+' || op == '-' || op == '*' || op == '/' || op == '^'
    );
}

std::string BCUtils::parse_string(char x) {
    std::string s(1, x);
    return s;
}

bool BCUtils::is_space(std::string *s) {
    return (*s) == " ";
}
