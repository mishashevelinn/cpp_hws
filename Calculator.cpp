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
    save_set(set_to_add, false);
    return true;
}

bool Calculator::remove_set() {
    cin.ignore();
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
    string uni_name;
    string test;
    cin.ignore();
    getline(cin, test);
    stringstream s(test);
    s >> A;
    s >> B;
    if (!param_check(A, B)) {
        return false;
    }

    getline(cin, uni_name);
    if (!parser->valid_name(uni_name)) {
        cerr << IN_ERROR<< endl;
        return false;
    }

    Set *united = calc_arr[A_index]->unite(calc_arr[B_index], uni_name);
    save_set(united, false);
    return true;
}

bool Calculator::intersect() {
    string A;
    string B;
    string inte_name;
    string test;
    cin.ignore();
    getline(cin, test);
    stringstream s(test);
    s >> A;
    s >> B;
    if (!param_check(A, B)) return false;

    getline(cin, inte_name);
    if (!parser->valid_name(inte_name)) {
        cerr << IN_ERROR << endl;
        return false;
    }


    Set *intersection = calc_arr[A_index]->intersect(calc_arr[B_index], inte_name);
    save_set(intersection, false);
    return true;
}

bool Calculator::power_set() {
    string A;
    string test;
    cin.ignore();
    getline(cin, test);
    stringstream s(test);
    s >> A;

    if (!param_check(A)) {
        return false;
    }

    Calculator *storage = new Calculator();
    Set *subset = new Set();

    generate_subsets(calc_arr[A_index], subset, storage, 0);
    storage->print_calc(calc_arr[A_index]->get_name());

    delete storage;
    return true;
}

void Calculator::generate_subsets(Set *set, Set *subset, Calculator *storage, int i) {
    if (i == set->get_ord()) {
        storage->save_set(subset, true);
        return;
    }
    generate_subsets(set, new Set(subset), storage, i + 1);
    subset->add(set->get(i));
    generate_subsets(set, new Set(subset), storage, i + 1);
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
    save_set(set_to_add, true);
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
        cout << "{}" << endl;
        return;
    }
    if (size == 1) {
        cout << '{';
        calc_arr[0]->print_set(true);
        cout << "}";
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
    cout << "}\n" << endl;
}

void Calculator::nested_sort(Set **array, int size) {
    int j;
    Set *key;
    for (int i = 1; i < size; i++) {
        key = array[i];
        j = i;
        while (j > 0 && array[j - 1]->is_bigger(key)) {
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
    cin.ignore();
    getline(cin, A);

    if (!param_check(A)) {
        return false;
    }
    calc_arr[A_index]->print_set(false);
    return true;
}


void Calculator::main_loop() {
    bool ex = false;
    menu();
    char opt;
    while (!ex && (cin >> opt)) {
        switch (opt) {
            case '1':
                add_set();
                //print_calc();
                break;
            case '2' :
                remove_set();
                //print_calc();
                break;
            case '3':
                set_unite();
                //print_calc();
                break;
            case '4':
                intersect();
                //print_calc();
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
                cerr << "ERROR: invalid command; type 0 for exit" << endl;
                break;
        }
        if(!ex){menu();}

    }
}

void Calculator::menu() {
    cout << "[1] add set\n[2] remove set\n[3] union\n[4] intersection\n[5] power set\n[6] print\n[0] exit\n";
}

void Calculator::name_error(string param) {
    cerr << "ERROR: " << param << " does not exist" << endl;
}
