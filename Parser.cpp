//
// Created by misha on 06/11/2020.
//
#include <iostream>
#include <sstream>
#include<string>
#include <cstdlib>
#include "Parser.h"
#include "Set.h"


using namespace std;

Set *Parser::parse_set() {
    string name = parse_name();
    if(!name.compare("error")) {
        cout << "name-error" << endl;
        exit(-1);
    }
    string str = get_input();
    string temp;
    stringstream s(str);
    Set *res = new Set(name);
    while (s >> temp) {
        if(isnumeric(temp))
            res->add(strtoi(temp));
    }
    return res;
}

string Parser::get_input() {
    string str;
    getline(cin, str);
    return str;
}

bool Parser::isnumeric(string s) {
    for (int i = 0; i < s.length(); i++) {
        if (!isdigit(s[i]))
            return false;
    }
    return true;
}

int Parser::strtoi(string str){
    char* p;
    return (int)strtol(str.c_str(), &p, 10);

}

string Parser :: parse_name() {
    string name = get_input();
    if(isValid(name))
        return name;
    return "error";


}
bool Parser :: isValid(string candidate){
    for (int i = 0; i < candidate.length(); i++) {
        if( !((int)candidate[i] >= 65 && (int)candidate[i] <= 90))
            return false;

    }
    return true;

}









