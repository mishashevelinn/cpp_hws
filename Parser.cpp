#include "Parser.h"


bool Parser::parse_set(Set *set) {
    cin.ignore();
    string name = parse_name();
    if (!name.compare("error")) {
        cerr << IN_ERROR << endl;
        return false;
    }
    set->set_name(name);

    string str;
    getline(cin, str);
    string temp;
    if (str[0] != '{' || str[str.length() - 1 ] != '}') {
        cerr << IN_ERROR << endl;
        return false;
    }
    str.erase(str.length()-1, 1);
        str.erase(0,1);

    stringstream s(str);
    while (s >> temp) {
        if (!isnumeric(temp)) {
            cerr << IN_ERROR;
            return false;
        }
        set->add(strtoi(temp));
    }
    return true;
}

string Parser::get_input() {
    string str;
    getline(cin, str);
    char c;
    return str;
}

bool Parser::isnumeric(string s) {
    if(!isdigit(s[0]) && s[0] != '-')
        return false;
    for (int i = 1; i < s.length(); i++) {
        if (!isdigit(s[i]))
            return false;
    }
    return true;
}

int Parser::strtoi(string str) {
    char *p;
    return (int) strtol(str.c_str(), &p, 10);

}

string Parser::parse_name() {
    string name = get_input();
    if (valid_name(name))
        return name;
    return "error";
}

bool Parser::valid_name(string candidate) {
    for (int i = 0; i < candidate.length(); i++) {
        if (!((int) candidate[i] >= 65 && (int) candidate[i] <= 90))
            return false;
    }
    return true;
}

bool is_proper_set(string test){
    if (test[0] != '{' || test[test.length() - 1 ] != '}')
        return false;
    test.erase(0);
    test.erase(test.length() - 1);

}








