//
// Created by misha on 07/11/2020.
//

#ifndef CPP_HWS_CALCULATOR_H
#define CPP_HWS_CALCULATOR_H


#include "Set.h"
#include "Parser.h"
class Calculator {
public:
    Calculator();
    bool add_set();
    bool remove_set(string set_name);
    void print_calc();
    Set * unite(Set*, Set*);

private:
    Parser *parser;
    int capacity;
    Set ** calc_arr;
    int size;
    void resize_arr();

    int find_set(string name);

    bool set_unite(string A, string B, string set_name);

    static bool save_set(Set*);
};


#endif //CPP_HWS_CALCULATOR_H
