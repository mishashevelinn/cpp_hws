#ifndef CPP_HWS_CALCULATOR_H
#define CPP_HWS_CALCULATOR_H

#include "Parser.h"
#include <stdio.h>

#define NAME_ERROR(x) #x

class Calculator {
public:
    Calculator();

    void main_loop();


private:
    Set **calc_arr;

    int size;

    int capacity;

    Parser *parser;


    int A_index = 0;
    int B_index = 0;

    bool add_set();

    bool remove_set();

    bool set_unite();

    bool intersect();

    bool power_set();

    void print_calc();


    void resize_arr();

    int find_set(const string &name);

    static void nested_sort(Set **array, int size);

    bool save_set(Set *set_to_add, bool is_subset = false);

    bool calc_print_set();

    bool param_check(const string &A, const string &B, const string &res_name);

    bool param_check(const string &A);

    void print_calc(string name);

    void menu();

    void name_error(string param);
};


#endif //CPP_HWS_CALCULATOR_H
