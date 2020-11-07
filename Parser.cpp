//
// Created by misha on 06/11/2020.
//
#include <iostream>
#include <sstream>
#include<string>
#include <cstdlib>
#include "Parser.h"


using namespace std;

int *Parser::parse_set() {


    string str = get_input();
    string temp;
    stringstream s(str);

    int i;
    int j = 0;
    int len = str.length();
    int *arr = new int(len*2);
    char *cshit = NULL;
    char left_curly = '{';
    char right_curly = '}';


    while (s >> temp) {
        const char *check = (temp.c_str());
        i = (int) strtol(check, &cshit, 10);
        if (check && *cshit != 0) {
            if ((check[0] == left_curly && j == 0)) {
                check++;
                int k = (int) strtol(check, &cshit, 10);
                if (check && *cshit == 0)
                    i = k;
                else {
                    cout << "error" << endl;
                    break;
                }
            } else if (check[temp.length() - 1] == right_curly)
                i = (int) strtol(check, &cshit, 10);

            else {
                cout << "ERROR" << endl;
                break;
            }
        }
        arr[j] = i;
        j++;

    }
    size = j;
    currently_parsed++;
    int *ret = new int(size);
    for (int k = 0; k < size; k++) {
        ret[k] = arr[k];
    }
    //delete [] arr;
    return ret;

}

string Parser::get_input() {
    string str;
    getline(cin, str);
    return str;
}





