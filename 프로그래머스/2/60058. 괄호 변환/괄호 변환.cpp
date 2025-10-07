#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

bool balanced(string p) {
    int a = 0, b = 0;
    for (char c : p) {
        if (c == '(') a++;
        else b++;
    }
    return a == b;
}

bool correct(string p) {
    int all = 0;
    for (char c : p) {
        if (c == '(') all++;
        else all--;
        if (all < 0) return false;
    }
    return all == 0;
}

string convert(string p) {
    if (p == "") return "";
    string u, v;
    for (int i = 1; i <= p.length(); i++) {
        if (balanced(p.substr(0, i))) {
            u = p.substr(0, i);
            v = p.substr(i);
            break;
        }
    }
    if (correct(u)) {
        return u + convert(v);
    }
    string n = "(";
    n += convert(v);
    n += ")";
    u.erase(u.begin());
    u.erase(u.begin() + u.length() - 1);
    for (char& c : u) {
        c = (c == '(') ? ')' : '(';
    }
    n += u;
    return n;
}

string solution(string p) {
    
    if (p.empty()) return "";
    if (correct(p)) return p;
    
    return convert(p);
}