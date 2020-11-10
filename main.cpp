#include <iostream>
#include "Calculator.h"

using namespace std;

int main() {
    Calculator *calc = new Calculator();
    Set misha = new Set("MISHA");
    calc->main_loop();
//    calc->add_set();
//    calc->add_set();
//    if(calc->set_unite())
//        cout << "united sed added";
//    else
//        cout << "falid to unite";
//    calc->print_calc();
//    return 0;
}