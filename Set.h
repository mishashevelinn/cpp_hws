
#include <iostream>

using namespace std;

#ifndef CPP_HWS_SET_H
#define CPP_HWS_SET_H


#define INITIAL_ARRAY_SIZE 12;

class Set {
public:
    explicit Set(const string &name);

    Set();

    explicit Set(Set *other);

    bool is_empty() const { return ord == 0; }

    bool contains(int element);

    bool add(int element);

   // int get_size() const { return arr_size; }

    int get_ord() const { return ord; }

    string get_name() { return name; }

    void sort();

    void print_set(bool for_P);

    Set *unite(Set *other, const string &result_name);

    Set *intersect(Set *other, const string &result_name);

    int get(int i);

    void set_name(string name);

    virtual ~Set();

    bool is_bigger(Set& other);

    bool has_larger_elements(Set &other);


private:
    int arr_size;
    int ord;
    int *arr;
    string name;


};


#endif //CPP_HWS_SET_H
