#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <cmath>

using namespace std;

long long num(string ban) {
    long long result = 0;
    for (char c : ban) {
        result = result * 26 + (c - 'a' + 1);
    }
    return result;
}

string str(long long num) {
    string result = "";
    
    while (num > 0) {
        num--;
        int d = num % 26;
        result.push_back('a' + d);
        num /= 26;
    }
    reverse(result.begin(), result.end());
    return result;
}

string solution(long long n, vector<string> bans) {
    string answer = "";
    int s = bans.size();
    vector<long long> bansNumber(s);
    for (int i = 0; i < s; i++) {
        bansNumber[i] = num(bans[i]);
    }
    sort(bansNumber.begin(), bansNumber.end());

    for (long long i : bansNumber) {
        if (i <= n) n++;
        else break;
    }
    
    return str(n);
}