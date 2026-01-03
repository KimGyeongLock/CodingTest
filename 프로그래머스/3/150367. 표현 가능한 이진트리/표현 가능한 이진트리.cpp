#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
#include <iostream>

using namespace std;

string toBinary(long long num) {
    string res = "";
    while (num > 0) {
        res += (num % 2) + '0';
        num /= 2;
    }
    reverse(res.begin(), res.end());
    return res;
}

bool dfs(string str, int l, int r) {
    if (l == r) return true;
    
    int mid = (l + r) / 2;
    
    if (str[mid] == '0') {
        for (int i = l; i <= r; i++) {
            if (str[i] != '0') return false;
        }
        return true;
    }
    return dfs(str, l, mid - 1) && dfs(str, mid + 1, r);
}

vector<int> solution(vector<long long> numbers) {
    vector<int> answer;
    for (long long n : numbers) {
        string bin = toBinary(n);
        int k = 1;
        while(pow(2, k) - 1 < bin.length()) k++;
        int padding = pow(2, k) - 1 - bin.length();
        string nw = "";
        for (int i = 0; i < padding; i++) nw.push_back('0');
        for (char b : bin) nw.push_back(b);
        // cout << nw << "\n";
        
        if (dfs(nw, 0, nw.size() - 1)) answer.push_back(1);
        else answer.push_back(0);
    }
    return answer;
}