#include <iostream>
#include<string>
#include "Parser.h"
#include "Set.h"

using namespace std;

int main() {
    Parser parser;
    int* res = parser.parse_set();
    cout <<"Size is " << parser.get_size() << endl;
    Set *test = new Set(res, parser.get_size(), parser.get_size(), "test");
    test->add(4);
    cout << test->get_size() << endl;
    cout << test->get_ord() << endl;
    for (int i = 0; i < test->get_ord(); i++) {
        cout << test->arr[i] << " ";


    }



    return 0;
}
