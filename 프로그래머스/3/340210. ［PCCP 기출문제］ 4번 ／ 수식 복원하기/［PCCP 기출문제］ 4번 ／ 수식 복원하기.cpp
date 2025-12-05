#include <string>
#include <vector>
#include <sstream>
#include <set>
#include <algorithm>
#include <iostream>

using namespace std;

vector<string> split(string s, char del) {
    vector<string> res;
    stringstream ss(s);
    string word;
    while (getline(ss, word, del)) {
        res.push_back(word);
    }
    return res;
}

int getMaxDigit(const string& s) {
    int mx = 0;
    for (char ch : s) {
        if ('0' <= ch && ch <= '9') {
            mx = max(mx, ch-'0');
        }
    }
    return mx;
}

int toDecimal(const string& s, int base) {
    int val = 0;
    for (char ch : s) {
        int d = ch - '0';
        val = val * base + d;
    }
    return val;
}

string fromDecimal(int num, int base) {
    if (num == 0) return "0";
    string res;
    while (num > 0) {
        int d = num % base;
        res.push_back('0' + d);
        num /= base;
    }
    reverse(res.begin(), res.end());
    return res;
}

struct Expr {
    string A, B, C;
    char op;
    bool unknown;
};

vector<string> solution(vector<string> expressions) {
    vector<string> answer;
    vector<Expr> exprs;
    
    int globalMaxDigit = 0;
    for (const string& s : expressions) {
        for (char ch : s) {
            if ('0' <= ch && ch <= '9') {
                globalMaxDigit = max(globalMaxDigit, ch - '0');
            }
        }
    }
    int minBase = max(2, globalMaxDigit + 1);
    
    for (string s : expressions) {
        vector<string> sp = split(s, ' ');
        Expr e;
        e.A = sp[0];
        e.op = sp[1][0];
        e.B = sp[2];
        e.C = sp[4];
        e.unknown = (e.C == "X");
        exprs.push_back(e);
    }
    
    vector<int> bases;
    for (int b = minBase; b <= 9; b++) bases.push_back(b);
    
    for (auto& e : exprs) {
        if (e.unknown) continue;

        vector<int> nextBases;
        for (int base : bases) {            
            int a = toDecimal(e.A, base);
            int b = toDecimal(e.B, base);
            int c = toDecimal(e.C, base);
            int calc = (e.op == '+') ? (a + b) : (a - b);
            if (calc == c) {
                nextBases.push_back(base);
            }
        }
        if (!nextBases.empty()) {
            bases = nextBases;
        }
    }
    
    for (const auto& e : exprs) {
        if (!e.unknown) continue;
        
        set<string> possible;
        
        for (int base : bases) {
            int a = toDecimal(e.A, base);
            int b = toDecimal(e.B, base);
            
            int calc = (e.op == '+') ? (a + b) : (a - b);
            if (calc < 0) continue;
            
            string cStr = fromDecimal(calc, base);
            possible.insert(cStr);
        }
        
        string filledC;
        if (possible.size() == 1) {
            filledC = *possible.begin();
        } else {
            filledC = "?";
        }
        
        string out = e.A + " " + e.op + " " + e.B + " = " + filledC;
        answer.push_back(out);
    }
    return answer;
}