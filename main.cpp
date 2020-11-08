#include <iostream>
#include<string>
#include "Parser.h"
#include "Set.h"
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
    calc->remove_set("MISHA");
    calc->print_calc();
    return 0;
}