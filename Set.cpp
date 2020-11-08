#include "Set.h"

Set::Set(const string &init_name) {
    //remove_duplicates();
    arr_size = ARR_SIZE_INIT;
    arr = new int[arr_size];
    ord = 0;
    name.assign(init_name);
}

Set::~Set() {
    delete[] arr;

}

bool Set::contains(int element) {
    if (is_empty())
        return false;
    for (int i = 0; i < ord; i++) {
        if (arr[i] == element)
            return true;
    }
    return false;
}

bool Set::add(int element) {
    if (contains(element))
        return false;
    if (ord < arr_size) {
        arr[ord] = element;
        ord++;
        sort(arr, ord);
        return true;
    }
    int new_arr_size = arr_size * 2;
    int *new_arr = new int[new_arr_size];
    for (int i = 0; i < arr_size; i++) {
        new_arr[i] = arr[i];
    }
    arr_size = new_arr_size;
    add(element);
    sort(arr, ord);
    return true;


}

void Set::sort(int *array, int size) {
    int key, j;
    for (int i = 1; i < size; i++) {
        key = array[i];
        j = i;
        while (j > 0 && array[j - 1] > key) {
            array[j] = array[j - 1];
            j--;
        }
        array[j] = key;
    }
}


void Set::print_set() {
    for (int i = 0; i < ord; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

Set *Set::unite(Set *other, const string &result_name) {
    Set *result = new Set(result_name);
    for (int i = 0; i < ord; i++) {
        result->add(arr[i]);
    }
    for (int i = 0; i < other->ord; i++) {
        result->add(other->arr[i]);
    }
    return result;
}

Set *Set::intersect(Set *other, const string &result_name) {
    Set *result = new Set(result_name);
    for (int i = 0; i < ord; i++) {
        if (other->contains(arr[i]))
            result->add(arr[i]);
    }
    return result;
}



