#include <cstdio>
#include "Calculator.h"

Calculator::Calculator() {
    size = 0;
    capacity = INITIAL_ARRAY_SIZE;
    calc_arr = new Set *[capacity];
    parser = new Parser();
}

bool Calculator::add_set() {
    Set *set_to_add = new Set();
    if (!parser->parse_set(set_to_add))
        return false;
    save_set(set_to_add, NOT_SUBSET);
    return true;
}

Calculator::~Calculator() {
    delete [] calc_arr;
}

bool Calculator::remove_set() {
    const string &set_name = parser->parse_name();

    if (!param_check(set_name))
        return false;

    for (int j = A_index; j < size - 1; j++) {
        calc_arr[j] = calc_arr[j + 1];
    }
    size--;
    return true;
}

bool Calculator::set_unite() {
      string A;
      string B;
      string res_name;

    if(!parser->parse_names(A, B)){
        cerr << IN_ERROR << endl;
        return false;
    }
    if (!param_check(A, B)) {
        return false;
    }

    getline(cin, res_name);
    if (!parser->valid_name(res_name)) {
        cerr << IN_ERROR << endl;
        return false;
    }

    Set *united = calc_arr[A_index]->unite(calc_arr[B_index], res_name);
    save_set(united, NOT_SUBSET);
    return true;
}

bool Calculator::intersect() {
    string A;
    string B;
    string res_name;

    if(!parser->parse_names(A, B)) {
        cerr << IN_ERROR << endl;
        return false;
    }
    if (!param_check(A, B)) return false;

    getline(cin, res_name);
    if (!parser->valid_name(res_name)) {   //TODO parser's job - parse name
        cerr << IN_ERROR << endl;
        return false;
    }

    Set *intersection = calc_arr[A_index]->intersect(calc_arr[B_index], res_name);
    save_set(intersection, false);
    return true;
}

bool Calculator::power_set() {
    string test;
    getline(cin, test);
    if( !parser->valid_name(test)) {
        cerr << IN_ERROR << endl;
        return false;
    }
    if (!param_check(test)) {
        return false;
    }

    Calculator *storage = new Calculator();
    Set *subset = new Set();

    generate_subsets(calc_arr[A_index], subset, storage, 0);

    for (int i = 0; i < storage->size; i++) {
        storage->calc_arr[i]->sort();

    }
    storage->print_calc(calc_arr[A_index]->get_name());

    delete storage;
    return true;
}

void Calculator::generate_subsets(Set *set, Set *subset, Calculator *storage, int i) {
    Calculator *temp = new Calculator();
    temp->save_set(subset, true);
    if (i == set->get_ord()) {
        storage->save_set(subset, true);
        return;
    }
    generate_subsets(set, new Set(subset), storage, i + 1);
    subset->add(set->get(i));
    generate_subsets(set, new Set(subset), storage, i + 1);
    delete temp;

}


int Calculator::find_set(const string &name) {
    for (int i = 0; i < size; i++) {
        if (!(calc_arr[i]->get_name().compare(name))) {
            return i;
        }
    }
    return -1;
}


bool Calculator::save_set(Set *set_to_add, bool is_subset) {
    if (!is_subset) {
        int index = find_set(set_to_add->get_name());
        if (index != -1) {
            calc_arr[index] = set_to_add;
            return true;
        }
    }
    if (size < capacity) {
        calc_arr[size] = set_to_add;
        size++;
        return true;
    }
    resize_arr();
    save_set(set_to_add, IS_SUBSET);
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

void Calculator::print_calc(string name) {
    cout << "P(" << name << ')' << "=";
    if (size == 0) {
        cout << "{{}}\n" << endl;
        return;
    }
    if (size == 1) {
        cout << '{';
        calc_arr[0]->print_set(true);
        cout << "}\n";
        return;
    }
    nested_sort(calc_arr, size);
    cout << "{";
    calc_arr[0]->print_set(true);
    cout << ",";
    for (int i = 1; i < size - 1; i++) {
        calc_arr[i]->print_set(true);
        cout << ",";
    }
    calc_arr[size - 1]->print_set(true);
    cout << "}" << endl;
}

void Calculator::nested_sort(Set **array, int size) {
    int j;
    Set *key;
    for (int i = 1; i < size; i++) {
        key = array[i];
        j = i;
        while (j > 0 && array[j - 1]->is_bigger(*key)) {
            array[j] = array[j - 1];
            j--;
        }
        array[j] = key;
    }
}


bool Calculator::param_check(const string &A, const string &B) {
    A_index = find_set(A);
    B_index = find_set(B);

    if (!parser->valid_name(A)) {
        cerr << IN_ERROR << endl;
        return false;
    }
    if (A_index == -1) {
        name_error(A);
        return false;
    }
    if (!parser->valid_name(B)){
        cerr << IN_ERROR << endl;
        return false;
    }
    if (B_index == -1) {
        name_error(B);
        return false;
    }
    return true;
}

bool Calculator::param_check(const string &A) {
    A_index = find_set(A);
    if (!parser->valid_name(A)) {
        cerr << IN_ERROR << endl;
        return false;
    }
    if (A_index == -1) {
        name_error(A);
        return false;
    }
    return true;
}


bool Calculator::calc_print_set() {
    string A;
    getline(cin, A);

    if (!param_check(A)) {
        return false;
    }
    calc_arr[A_index]->print_set(false);
    return true;
}


void Calculator::main_loop() {
    bool ex = false;
    char opt;
    while (!ex) {
        menu();
        if(!parser->check_opt(opt)) continue;
        switch (opt) {
            case '1':
                add_set();
                break;
            case '2' :
                remove_set();
                break;
            case '3':
                set_unite();
                break;
            case '4':
                intersect();
                break;
            case '5' :
                power_set();
                break;
            case '6':
                calc_print_set();
                break;
            case '0':
                ex = true;
                break;
            default:
                cerr << OPT_ERROR << endl;
                break;
        }
    }
}

void Calculator::menu() {
    cout << "[1] add set\n[2] remove set\n[3] union\n[4] intersection\n[5] power set\n[6] print\n[0] exit\n";

}

void Calculator::name_error(string param) {
    cerr << "ERROR: " << param << " does not exist" << endl;
}
