#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <iostream>

using namespace std;

int solution(int k, vector<int> tangerine) {
    int answer = 0;
    
    unordered_map<int, int> mp;
    for (int t : tangerine) {
        mp[t]++;
    }
    
    vector<pair<int, int>> vec;
    for (auto m : mp) {
        vec.push_back({m.first, m.second});
    }

    sort(vec.begin(), vec.end(), [&](const auto a, const auto b) {
        return a.second > b.second;
    });
    
    for (auto p : vec) {
        answer++;
        k -= p.second;
        if (k <= 0) break;
    }
     
    
    
    return answer;
}