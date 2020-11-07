//
// Created by misha on 05/11/2020.
//
#include "string"
using namespace std;
#ifndef CPP_HWS_SET_H
#define CPP_HWS_SET_H
class Set
{
public:
    Set(int* arr, int set_size, int arr_len, string name);
    bool is_empty(){return ord == 0;}
    bool contains(int element);
    bool add(int element);
    Set unite(Set, Set);
    Set intersec(string, string);
    Set power_set_of(Set);
    Set substract(Set);
    int get_size(){return arr_size;}
    int get_ord(){return ord;}
    void remove_duplicates();
    void sort(int* array, int size_of_array);

    int* arr;



private:
    int arr_size;
    string name;
    int ord;


};



#endif //CPP_HWS_SET_H
