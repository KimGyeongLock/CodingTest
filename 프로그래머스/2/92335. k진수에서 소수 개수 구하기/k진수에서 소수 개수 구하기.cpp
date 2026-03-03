#include <string>
#include <vector>
#include <algorithm>
#include <sstream>
#include <cmath>
#include <iostream>

using namespace std;

string jinsu(int n, int k) {
    if (k == 10) return to_string(n);
    string res = "";
    while(n > 0) {
        res.push_back((n % k) + '0');
        n /= k;
    }
    reverse(res.begin(), res.end());
    return res;
}

vector<string> split(string s, char del) {
    vector<string> res;
    istringstream iss(s);
    string word;
    
    while(getline(iss, word, del)) {
        res.push_back(word);
    }
    return res;
} 

bool isPrime(string s) {
    if (s.empty()) return false;
    long long n = stoll(s);
    if (n < 2) return false;
    
    for (long long i = 2; i * i <= n; i++) {
        if (n % i == 0) return false;
    }
    return true;
}

int solution(int n, int k) {
    int answer = 0;
    string s = jinsu(n, k);
    
    vector<string> q = split(s, '0');
    
    for (string c : q) {
        if (isPrime(c)) {
            answer++;
        }
    }
    return answer;
}