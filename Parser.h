//
// Created by misha on 06/11/2020.
//

#ifndef CPP_HWS_PARSER_H
#define CPP_HWS_PARSER_H

#include <iostream>
#include <sstream>
#include<string>
#include <cstdlib>
#include "Set.h"

using namespace std;

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

    bool isValid(string candidate);

    bool valid_names(string A, string B, string uni_name);
};

#endif //CPP_HWS_PARSER_H
