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
    if (index == -1) return false;

    for (int j = index; j < size - 1; j++) {
        calc_arr[j] = calc_arr[j + 1];
    }
    size--;
    cout << "removing " << set_name << endl;
    return true;
}


bool Calculator::save_set(Set *set_to_add) {
    int index = find_set(set_to_add->get_name());
    if (index != -1) {
        calc_arr[index] = set_to_add;
        cout << calc_arr[index]->get_name() << " was replaced by" << set_to_add->get_name() << endl;
        return true;
    }
    if (size < capacity) {
        calc_arr[size] = set_to_add;
        size++;
        return true;
    }
    resize_arr();
    save_set(set_to_add);
    return true;
}


bool Calculator::add_set() {
    Set *set_to_add;
    set_to_add = parser->parse_set();
    save_set(set_to_add);
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
        cout << endl;
    }
    cout << "CALCULATOR CAPACITY, SIZE = " << capacity << ", " << size << endl;

}

bool Calculator::set_unite(string A, string B, string uni_name) {
    if (!valid_names(A, B, uni_name)) return false;

    Set *united = calc_arr[A_index]->unite(calc_arr[B_index], uni_name);
    save_set(united);
    return true;
}

bool Calculator::intersec(string A, string B, string int_name) {
    if (!valid_names(A, B, int_name))  return false;

    Set *intersection = calc_arr[A_index]->intersect(calc_arr[B_index], int_name);
    save_set(intersection);
    return false;
}

bool Calculator::valid_names(string A, string B, string uni_name) {
    A_index = find_set(A);
    B_index = find_set(B);
    if (A_index == -1 || B_index == -1 || !parser->isValid(A) || !parser->isValid(B) || !parser->isValid(uni_name))
        return false;
    return true;
}
