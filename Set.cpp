#include "Set.h"

//
// Created by misha on 05/11/2020.
//
Set::Set(int *arr_init, int size, int arr_len, string name_init) {
    sort(arr_init, size);
    //remove_duplicates();
    arr = arr_init;
    ord = size;
    name = name_init;
    arr_size = arr_len;
}



bool Set::contains(int element) {
    if(is_empty())
        return false;
    for (int i = 0; i < ord; i++) {
        if (arr[i] == element)
            return true;
    }
    return false;
}

bool Set::add(int element) {
    if (!contains(element)) {
        if (ord == arr_size) {
            arr_size *= 2;
            int *new_arr = new int(arr_size);
            int i = 0;
            for (; i < ord; i++) {
                new_arr[i] = arr[i];
            }
            new_arr[i] = element;
            ord++;
            for (int j = i + 1; j < arr_size; j++) {
                new_arr[j] = 0;
            }
            delete [] arr;
            arr = new_arr;

            return true;
        } else {
            arr[ord - 1] = element;
            ord++;
            return true;
        }

    } else
        return false;
}

void Set::sort(int *array, int size) {
        int key, j;
        for(int i = 1; i<size; i++) {
            key = array[i];//take value
            j = i;
            while(j > 0 && array[j-1]>key) {
                array[j] = array[j-1];
                j--;
            }
            array[j] = key;   //insert in right place
        }
}



