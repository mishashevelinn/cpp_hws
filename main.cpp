#include <iostream>
#include "Calculator.h"

using namespace std;

int main() {
    Calculator *calc = new Calculator();
    Set misha = new Set("MISHA");
    for (int i = 0; i < 4; i++) {
        misha.add(i);
    }
    calc->add_set();
    calc->power_set("MISHA");

    return 0;
}