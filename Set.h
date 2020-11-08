//
// Created by misha on 05/11/2020.
//
#include "string"
using namespace std;
#ifndef CPP_HWS_SET_H
#define CPP_HWS_SET_H
#define ARR_SIZE_INIT 12;
class Set
{
public:
    Set(string name);

    bool is_empty(){return ord == 0;}
    bool contains(int element);
    bool add(int element);



    int get_size(){return arr_size;}
    int get_ord(){return ord;}
    string get_name(){return name;}
    void sort(int* array, int size_of_array);
    void print_set();

    virtual ~Set();


private:
    int arr_size;
    int ord;
    int* arr;
    string name;



};



#endif //CPP_HWS_SET_H
