//
// Created by aditya on 18/12/21.
//

#ifndef BC_COMPILER_BCUTILS_H
#define BC_COMPILER_BCUTILS_H

#include <string>

class BCUtils {
  public:
    static bool is_digit(std::string *x);
    static bool is_number(std::string *numberI);
    static int parseInt(std::string *s);
    static std::string get_char_at(std::string *s, int i);
    static bool is_alpha(std::string *s);
    static bool is_operator(std::string *s);
    static std::string parse_string(char x);
    static bool is_space(std::string *s);
};

#endif // BC_COMPILER_BCUTILS_H
