#include "Parser.h"

bool Parser::parse_set(Set *set) {
    string name = parse_name();
    if (!name.compare("error") ) {
        cerr << IN_ERROR << endl;
        return false;
    }
    set->set_name(name);

    string str;
    getline(cin, str);
    string temp;
    if (str[0] != '{' || str[str.length() - 1] != '}') {
        cerr << IN_ERROR << endl;
        return false;
    }

    str.erase(str.length() - 1, 1);
    str.erase(0, 1);

    stringstream s(str);
    while (s >> temp) {
        if (!isnumeric(temp)) {
            cerr << IN_ERROR << endl;
            return false;
        }
        set->add(strtoi(temp));
    }
    return true;
}

string Parser::get_input() {
    string str;
    getline(cin, str);
    return str;
}

bool Parser::isnumeric(string s) {
    if (!isdigit(s[0]) && s[0] != '-')
        return false;
    for (int i = 1; i < s.length(); i++) {
        if (!isdigit(s[i]))
            return false;
    }
    return true;
}

int Parser::strtoi(const string& str) {
    char *p;
    return (int) strtol(str.c_str(), &p, 10);
}

string Parser::parse_name() {
    string name = get_input();
    if (name.empty()) return "error";
    if (valid_name(name))
        return name;
    return "error";
}

bool Parser::valid_name(string candidate) {
    if(candidate.length() > 8 || candidate.empty()) { return false;}

    for (char i : candidate) {
        if (!((int) i >= 65 && (int) i <= 90))
            return false;
    }
    return true;
}

bool Parser::parse_names(string &A, string &B) {
    int counter = 0;
    string test;
    string temp;
    getline(cin, test);
    stringstream s(test);
    while(s >> temp) counter++;
    if (counter != 2) return false;
    stringstream ss(test);
    ss >> A;
    ss >> B;

    if (!valid_name(A)) return false;
    if (!valid_name(B)) return false;
    return true;
}

bool Parser :: check_opt(char &opt){
    string test;
    getline(cin, test);
    if(test.length() != 1 || !((int) test[0] >= 48 && (int) test[0] <= 57)) {
        cerr << OPT_ERROR << endl;
        return false;
    }
    opt = test[0];
    return true;
 }

