#include "string"
#include <iostream>

using namespace std;
#ifndef CPP_HWS_SET_H
#define CPP_HWS_SET_H
#define INITIAL_ARRAY_SIZE 12;

class Set {
public:
    Set(const string &name);

    Set();

    Set(Set *other);

    bool is_empty() { return ord == 0; }

    bool contains(int element);

    bool add(int element);

    int get_size() { return arr_size; }

    int get_ord() { return ord; }

    string get_name() { return name; }

    static void sort(int *array, int size_of_array);

    void print_set(bool for_P);

    Set *unite(Set *other, const string &result_name);

    Set *intersect(Set *other, const string &result_name);

    int get(int i);

    void set_name(string name);

    virtual ~Set();

    bool is_bigger(Set *other);

    bool has_larger_elements(Set *other);

    bool is_of_bigger_size_then(Set *other) const;


private:
    int arr_size;
    int ord;
    int *arr;
    string name;

    void arr_copy(int *source, int *dest, int len);


};


#endif //CPP_HWS_SET_H
