#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

bool compare(unordered_map<string, int> a, unordered_map<string, int> b) {
    for (auto c : a) {
        if (c.second > b[c.first]) return false;
    }
    return true;
}

int solution(vector<string> want, vector<int> number, vector<string> discount) {
    int answer = 0;
    
    int n = want.size();
    unordered_map<string, int> mp;
    for (int i = 0; i < n; i++) mp[want[i]] = number[i];
    
    unordered_map<string, int> cmp;
    for (int i = 0; i < 10; i++) {
        cmp[discount[i]]++;
    }
    if (compare(mp, cmp)) answer++;
    
    int m = discount.size();
    for (int i = 10; i < m; i++) {
        cmp[discount[i]]++;
        cmp[discount[i - 10]]--;
        if (compare(mp, cmp)) answer++;
    }
    
    return answer;
}