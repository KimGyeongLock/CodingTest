#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

int solution(vector<vector<int>> targets) {
    int answer = 0;
    
    sort(targets.begin(), targets.end(), [&](const auto& a, const auto& b) {
        if (a[1] == b[1]) return a[0] < b[0];
        return a[1] < b[1];
    });
    
    int max_v = 0;
    for (auto e : targets) {
        if (e[0] >= max_v) {
            max_v = e[1];
            answer++;
        }
    }
    return answer;
}