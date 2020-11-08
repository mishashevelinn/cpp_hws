#include <iostream>
#include "Calculator.h"

using namespace std;

int main() {
    int i = 0;
    Calculator *calc = new Calculator();
    while (true) {
        calc->add_set();
        i++;
        if (i == 3)
            break;
    }
    calc->print_calc();
//    if (!calc->remove_set("MISHA"))
//        cout << "MISHA's NOT THERE BRO" << endl;
//    calc->print_calc();
    if (!calc->set_unite("MISHA", "MASHA", "UNITED"))
        cout << "NAME ERROR HERE" << endl;
    calc->print_calc();
    if (!calc->intersec("MISHA", "MASHA", "CHITUCH"))
        cout << "NAME ERROR THERE" << endl;
    calc->print_calc();

    return 0;
}