#include <iostream>
#include "Calculator.h"

using namespace std;

int main() {
    Calculator *calc = new Calculator();
    calc->add_set();
    cout << "set added";
    calc->power_set("MISHA");


    return 0;
}