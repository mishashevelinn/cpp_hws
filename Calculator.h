#ifndef CPP_HWS_CALCULATOR_H
#define CPP_HWS_CALCULATOR_H

#include "Parser.h"

class Calculator {
public:
    Calculator();

    bool add_set();

    bool remove_set();

    void print_calc();

    bool set_unite(const string &A, const string &B, const string &set_name);

    bool intersec(const string &A, const string &B, const string &set_name);

    void main_loop();

private:
    Parser *parser;
    int capacity;
    Set **calc_arr;
    int size;

    void resize_arr();

    int find_set(const string &name);

    int A_index = 0;
    int B_index = 0;


    bool save_set(Set *);

    bool valid_names(const string &A, const string &B, const string &res_name);

    string A, B, C;


};


#endif //CPP_HWS_CALCULATOR_H
