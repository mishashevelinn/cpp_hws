#ifndef CPP_HWS_PARSER_H
#define CPP_HWS_PARSER_H

#include <sstream>
#include <cstdlib>
#include "Set.h"

class Parser {
private:
    int currently_parsed;

    string get_input();

    int size;


public:
    Set *parse_set();

    int get_size() { return size; }

    int get_count() { return currently_parsed; }

    bool isnumeric(string s);

    string parse_name();

    int strtoi(string str);

    bool valid_name(string candidate);




};

#endif //CPP_HWS_PARSER_H
