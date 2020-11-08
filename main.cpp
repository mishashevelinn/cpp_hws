#include <iostream>
#include<string>
#include "Calculator.h"

using namespace std;

int main() {
    int i = 0;
    Calculator *calc = new Calculator();
    while(true) {
        calc->add_set();
        i++;
        if( i == 4 )
            break;
    }
    calc->print_calc();
    if(!calc->remove_set("MISHA"))
        cout << "MISHA's NOT THERE BRO" << endl;
    calc->print_calc();
    Set *s = new Set("hi");
    return 0;
}