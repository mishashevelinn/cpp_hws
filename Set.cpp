#include "Set.h"

Set::Set(const string &init_name) {
    //remove_duplicates();
    arr_size = ARR_SIZE_INIT;
    arr = new int[arr_size];
    ord = 0;
    name.assign(init_name);
}

Set ::Set(Set *other) {
    arr_size=other->arr_size;
    ord = other->ord;
    name.assign(other->name);
    arr = new int[arr_size];
    for (int i = 0; i < ord; i++) {
        this->arr[i] = other->arr[i];
    }

}


Set::~Set() {
    delete[] arr;

}
Set ::Set() {arr_size = ARR_SIZE_INIT; arr = new int[arr_size]; ord = 0; name.assign("subset");}

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
    switch (ord) {
        case 0:
            cout << "{ }";
            break;
        case 1:
            cout << '{' << arr[0] << '}';
            break;
        default:for (int i = 0; i < ord; i++) {
                if (i == ord -1 ){
                    cout << arr[i] << '}';
                    continue;
                }
                if (i == 0){
                    cout << '{' << arr[i] << ',';
                    continue;
                }
                cout << arr[i] << ',';


            }
    }

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

int Set::get(int i) {
    return arr[i];      //TODO SAFELY OR NOT?
}


bool Set::has_larger_elements(Set *other) {
    for (int i = 0; i < ord; i++) {
        if (arr[i] > other->arr[i] )
            return true;
    }
    return false;
}

bool Set::compare(Set *other) {
    if(this->ord > other->ord)
        return true;
    else if(this->ord == other->ord)
        return this->has_larger_elements(other);
    return false;
}
