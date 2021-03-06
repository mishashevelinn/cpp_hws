#ifndef CPP_HWS_CALCULATOR_H
#define CPP_HWS_CALCULATOR_H

#include "Parser.h"



#define IS_SUBSET true
#define NOT_SUBSET false

class Calculator {
public:
    Calculator();

    void main_loop();

    virtual ~Calculator();


private:
    Set **calc_arr;

    int size;

    int capacity;

    Parser *parser;




    bool add_set();

    bool remove_set();

    bool set_unite();

    bool intersect();

    bool power_set();


    void resize_arr();

    int find_set(const string &name);

    static void nested_sort(Set **array, int size);

    bool save_set(Set *set_to_add, bool is_subset = false);

    bool calc_print_set();

    void generate_subsets(Set *set, Set *subset, Calculator *storage, Calculator *tree, int i = 0);

    bool param_check(const string &A, const string &B);

    bool param_check(const string &A);

    void print_calc(string name);

    void menu();

    void name_error(string param);
};


#endif //CPP_HWS_CALCULATOR_H
