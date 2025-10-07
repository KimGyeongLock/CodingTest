#include <string>
#include <vector>
#include <iostream>

using namespace std;

int calc(string s, int k) {
    string new_s = "";
    int i = 0;
    int n = s.length();
    while(i < n) {
        string subs = s.substr(i, k);
        if (subs.length() < k) {
            new_s += subs;
            break;
        }
        i += k;
        int cnt = 1;
        while(i + k <= n && s.substr(i, k) == subs) {
            cnt++;
            i += k;
        }
        if (cnt > 1) {
            new_s = new_s + to_string(cnt) + subs;
        } else {
            new_s += subs;
        }
    }
    return new_s.length();
}

int solution(string s) {
    int half = s.length() / 2;
    if (s.length() == 1) return 1;
    int min_v = 10000;
    for (int i = 1; i <= half; i++) {
        min_v = min(min_v, calc(s, i));
    }
    
    return min_v;
}