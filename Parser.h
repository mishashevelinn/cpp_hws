#ifndef CPP_HWS_PARSER_H
#define CPP_HWS_PARSER_H
#include "string"
#include <iostream>
#include <sstream>
#include <cstdlib>
#include "Set.h"

#define IN_ERROR "ERROR: invalid input"
#define OPT_ERROR "ERROR: invalid command; type 0 for exit"


class Parser {
private:

    string get_input();


    int strtoi(const string& str);

    bool isnumeric(string s);


public:
    bool parse_set(Set *set);

    string parse_name();

    bool valid_name(string candidate);

    string A;

    string B;

    string C;

    bool parse_names(string &A, string &B);

    bool check_opt(char &opt);
};

#endif //CPP_HWS_PARSER_H
