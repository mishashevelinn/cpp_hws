#include <iostream>
#include "Calculator.h"

using namespace std;

int main() {
    Calculator *calc = new Calculator();
    calc->main_loop();

    return 0;
}