//
// Created by misha on 07/11/2020.
//

#include "Calculator.h"
#include "Set.h"
#include "Parser.h"

Calculator::Calculator() {
    size = 0;
    capacity = ARR_SIZE_INIT;
    calc_arr = new Set *[capacity];
    parser = new Parser();

}

int Calculator::find_set(string name) {
    for (int i = 0; i < size; i++) {
        if (!(calc_arr[i]->get_name().compare(name))) {
            return i;
        }

    }
    return -1;
}


bool Calculator::remove_set(string set_name) {
    int i = 0;
    int index = find_set(set_name);
    if(index == -1)
        return false;
    for (int j = index; j < size-1; j++) {
        calc_arr[j] = calc_arr[j + 1];
    }
    size--;
    cout << "removing " << set_name << endl;
    return true;
}




bool Calculator::add_set() {
    Set *set_to_add;
    set_to_add = parser->parse_set();
    for (int i = 0; i < size; i++) {
        if (!calc_arr[i]->get_name().compare(set_to_add->get_name())) {
            calc_arr[i] = set_to_add;
            cout << calc_arr[i]->get_name() << " was replaced by" << set_to_add->get_name() << endl;
            return true;
        }

    }

    if (size < capacity) {
        calc_arr[size] = set_to_add;
        size++;
        return true;
    }
    resize_arr();
    add_set();
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
    for (int i = 0; i < size; i++) {
        cout << "Set no " << i + 1 << ": " << calc_arr[i]->get_name() << endl;
        cout << "Elements of " << calc_arr[i]->get_name() << ':' << endl;
        calc_arr[i]->print_set();
        cout << "Capacity is " << calc_arr[i]->get_size() << endl;
        cout << "Order is " << calc_arr[i]->get_ord() << endl;
    }
    cout << "CALCULATOR CAPACITY, SIZE = " << capacity << ", " << size << endl;

}
