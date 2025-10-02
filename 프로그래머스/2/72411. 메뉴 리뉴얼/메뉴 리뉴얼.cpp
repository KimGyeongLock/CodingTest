#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <iostream>

using namespace std;

unordered_map<string, int> mp;

void dfs(string str, string t, int depth, int k, int idx) {
    if (depth == k) {
        mp[t]++;
        return;
    }
    
    for (int i = idx; i < str.length(); i++) {
        dfs(str, t + str[i], depth + 1, k, i + 1);
    }
}

vector<string> solution(vector<string> orders, vector<int> course) {
    vector<string> answer;
    
    for (int k : course) {
        mp.clear();

        for(string o : orders) {
            sort(o.begin(), o.end());
            dfs(o, "", 0, k, 0);
        }
        
        int bestInt = 2;
        for (auto& m : mp) {
            if (bestInt <= m.second) {
                bestInt = m.second;
            }
        }
        for (auto& m : mp) {
            if (m.second == bestInt) {
                answer.push_back(m.first);
            }
        }
    }
    
    sort(answer.begin(), answer.end());
    return answer;
}