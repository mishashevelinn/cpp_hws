#ifndef CPP_HWS_PARSER_H
#define CPP_HWS_PARSER_H

#include <sstream>
#include <cstdlib>
#include "Set.h"

#define IN_ERROR "ERROR: invalid input"


class Parser {
private:
    int currently_parsed;

    string get_input();

    int size;

    int strtoi(string str);

    bool isnumeric(string s);


public:
    bool parse_set(Set *set);

    string parse_name();

    bool valid_name(string candidate);
};

#endif //CPP_HWS_PARSER_H
