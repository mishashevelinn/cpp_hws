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

    void generate_subsets(Set* set, Set* subset, Calculator* storage, int i = 0);

    void power_set(string name);

    void nested_sort(Set **array, int size);

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


    bool save_set(Set *set_to_add, bool is_subset = false);

    bool valid_names(const string &A, const string &B, const string &res_name);

};


#endif //CPP_HWS_CALCULATOR_H
