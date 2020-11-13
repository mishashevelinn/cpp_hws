/*Array based set implementation. Main methods are 'add' and 'contains'.
 * Class fields are name of the class, dynamic array, size of array(capacity) and order of a class
 * - number of elements in array. */
#include "Set.h"


/*Constructor takes string and assigns is to a corresponding filed*
 * array size always gets its initial constant size defined in macro
 * zero order represents an empty set in the moment of creation
 * dynamically allocating an array of constant size which being
 * reallocated each time order reaches an array capacity - arr_size.
 * This constructor used when Set is to be built from user's input*/
Set::Set(const string &init_name) {
    arr_size = INITIAL_ARRAY_SIZE;
    arr = new int[arr_size];
    ord = 0;
    name.assign(init_name);
}

/*Copy constructor - gets a pointer to a set and copies its fields
 * to "this's" fields when copying an array element by element*/
Set::Set(Set *other) {
    arr_size = other->arr_size;
    ord = other->ord;
    name.assign(other->name);
    arr = new int[arr_size];
    for (int i = 0; i < ord; i++) {
        this->arr[i] = other->arr[i];
    }
}

/*A destructor clears a dynamically allocated array*/
Set::~Set() {
    delete[] arr;
}
/*An empty constructor - creates an empty set with default name
 * This constructor is used when generating subsets of some set
 * and there's no need to name it*/
Set::Set() {
    arr_size = INITIAL_ARRAY_SIZE;
    arr = new int[arr_size];
    ord = 0;
    name.assign("subset");
}

/*A getter to retrieve an element of set */
int Set::get(int i) {
    return arr[i];
}
/*A setter for set's name*/
void Set::set_name(string name) {
    this->name = name;
}
/*A monumental method of set - iterates over an inner array
 * and returns boolean value depending on whether an element
 * is in set or not*/
bool Set::contains(int element) {
    if (is_empty())
        return false;
    for (int i = 0; i < ord; i++) {
        if (arr[i] == element)
            return true;
    }
    return false;
}


/*adds an element to a set by storing it in inner array.
 * if an element already in set, returns false, so
 * a set will never contain duplicates.
 * reallocates and array if number of elements reaches
 * array's capacity*/
bool Set::add(int element) {
    if (contains(element))  //duplicates can't be stored;
        return false;
    if (ord < arr_size) {   //if there is enough room for an element, append to the end of array
        arr[ord] = element; //and return true;
        ord++;
        return true;
    }
    int new_arr_size = arr_size * 2;    //if the number of elements reaches an array capacity
    int *new_arr = new int[new_arr_size];//allocate new, doubled-old-size long array
    for (int i = 0; i < arr_size; i++) { //copy an old array to a new
        new_arr[i] = arr[i];
    }
    arr_size = new_arr_size;        //move a pointer to a new array
    add(element);                   //and finally add the element
    return true;


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


void Set::print_set(bool for_P) {
    sort();
    if (!for_P) {
        cout << name << '=';
    }
    switch (ord) {
        case 0:
            cout << "{}";
            break;
        case 1:
            cout << '{' << arr[0] << '}';
            break;
        default:
            for (int i = 0; i < ord; i++) {
                if (i == ord - 1) {
                    cout << arr[i] << '}';
                    continue;
                }
                if (i == 0) {
                    cout << '{' << arr[i] << ',';
                    continue;
                }
                cout << arr[i] << ',';
            }
    }
    if(!for_P) cout << endl;
}

void Set::sort() {
    int key, j;
    for (int i = 1; i < ord; i++) {
        key = arr[i];
        j = i;
        while (j > 0 && arr[j - 1] > key) {
            arr[j] = arr[j - 1];
            j--;
        }
        arr[j] = key;
    }
}

bool Set::is_bigger(Set &other) {
    if (this->ord > other.ord)
        return true;
    else if (this->ord == other.ord)
        return this->has_larger_elements(other);
    return false;
}


bool Set::has_larger_elements(Set &other) {
    for (int i = 0; i < ord; i++) {
        if (arr[i] > other.arr[i])
            return true;
    }
    return false;
}