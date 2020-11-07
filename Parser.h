//
// Created by misha on 06/11/2020.
//

#ifndef CPP_HWS_PARSER_H
#define CPP_HWS_PARSER_H
#include <iostream>
#include <sstream>
#include<string>
#include <cstdlib>
using namespace std;
class Parser {
private:
    int currently_parsed;
    string get_input();
    int size;


public:
    int *parse_set();
    int get_size(){return size;}

    int get_count() {return currently_parsed;}
};

#endif //CPP_HWS_PARSER_H
