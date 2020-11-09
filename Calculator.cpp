//
// Created by misha on 07/11/2020.
//

#include <cstdio>
#include "Calculator.h"

Calculator::Calculator() {
    size = 0;
    capacity = ARR_SIZE_INIT;
    calc_arr = new Set *[capacity];
    parser = new Parser();
}

int Calculator::find_set(const string &name) {
    for (int i = 0; i < size; i++) {
        if (!(calc_arr[i]->get_name().compare(name))) {
            return i;
        }
    }
    return -1;
}


bool Calculator::remove_set() {
    const string &set_name = parser->parse_name();
    int index = find_set(set_name);
    if ((set_name == "error") || index == -1) return false;

    for (int j = index; j < size - 1; j++) {
        calc_arr[j] = calc_arr[j + 1];
    }

    size--;
    return true;
}


bool Calculator::save_set(Set *set_to_add, bool is_subset) {
    if(!is_subset)
    {
        int index = find_set(set_to_add->get_name());
        if (index != -1) {
            calc_arr[index] = set_to_add;
            cout << calc_arr[index]->get_name() << " was replaced by" << set_to_add->get_name() << endl;
            return true;
        }
    }
    if (size < capacity) {
        calc_arr[size] = set_to_add;
        size++;
        return true;
    }
    resize_arr();
    save_set(set_to_add, true);
    return true;
}


bool Calculator::add_set() {
    Set *set_to_add;
    set_to_add = parser->parse_set();
    save_set(set_to_add, false);
    return true;

}

void Calculator::resize_arr() {
    int new_capacity = capacity * 2;
    Set **new_calc_arr = new Set *[new_capacity];

    for (int i = 0; i < size; i++) {
        new_calc_arr[i] = calc_arr[i];
    }

    delete[] calc_arr;

    calc_arr = new_calc_arr;
    capacity = new_capacity;
}

void Calculator::print_calc() {
    nested_sort(calc_arr, size);
    cout << "{ ";
    calc_arr[0]->print_set();
    cout << ", ";
    for (int i = 1; i < size-1; i++) {
        calc_arr[i]->print_set();
        cout << ", ";
    }
    calc_arr[size-1]->print_set();
    cout << '}';

}

bool Calculator::set_unite(const string &A, const string &B, const string &uni_name) {
    if (!valid_names(A, B, uni_name)) return false;

    Set *united = calc_arr[A_index]->unite(calc_arr[B_index], uni_name);
    save_set(united, false);
    return true;
}

bool Calculator::intersec(const string &A, const string &B, const string &int_name) {
    if (!valid_names(A, B, int_name)) return false;

    Set *intersection = calc_arr[A_index]->intersect(calc_arr[B_index], int_name);
    save_set(intersection, false);
    return true;
}

bool Calculator::valid_names(const string &A, const string &B, const string &res_name) {
    A_index = find_set(A);
    B_index = find_set(B);

    if (A_index == -1 || B_index == -1 || !parser->valid_name(A) || !parser->valid_name(B) ||
        !parser->valid_name(res_name))
        return false;
    return true;
}

void Calculator::main_loop() {
    char c;
    cout << "menu\nto add set press 1\nto remove set press 2\n";
    char opt;
    while ((opt = getchar()) != '0') {
        switch (opt) {
            case '1':
                if(add_set()){
                    cout << "set added successfully" << endl;
                    print_calc();
                    main_loop();
                }
                cout << "couldn't add the set" << endl;
                main_loop();
            case '2' :
                if(remove_set()){
                    cout << "set has been removed" << endl;
                    main_loop();
                }
                cout << "couldn't remove the set" << endl;
                main_loop();

        }


    }
}

void Calculator::generate_subsets(Set *set, Set *subset, Calculator *storage, int i) {
    if( i == set->get_ord()){
        storage->save_set(subset, true);
        return;
    }
    generate_subsets(set, new Set(subset), storage, i + 1);
    subset->add(set->get(i));
    generate_subsets(set, new Set(subset), storage, i + 1);
}

void Calculator::power_set(string name) {
    int index = find_set(name);
    if (!parser->valid_name(name) || index == -1){
        cout << "parse error" << endl;
    }
    Calculator* storage = new Calculator();
    Set* subset = new Set();
    generate_subsets(calc_arr[index], subset, storage, 0);
    storage->print_calc();

}

void Calculator::nested_sort(Set **array, int size) {
    int j;
    Set  *key;
    for (int i = 1; i < size; i++) {
        key = array[i];
        j = i;
        while (j > 0 && array[j - 1]->compare(key)) {
            array[j] = array[j - 1];
            j--;
        }
        array[j] = key;
    }
}
