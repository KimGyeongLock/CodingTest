#include <string>
#include <vector>
#include <unordered_set>
#include <unordered_map>
#include <iostream>
#include <climits>

using namespace std;

vector<int> solution(vector<string> gems) {
    vector<int> answer;
    unordered_set<string> set;
    for (string s : gems) {
        set.insert(s);
    }
    int n = gems.size();
    
    unordered_map<string, int> tmp;
    int left, right;
    left = right = 0;
    int best = INT_MAX;
    tmp[gems[0]]++;
    
    while (left <= right && right < n) {
        if (tmp.size() < set.size()) {
            if (right + 1 >= n) break;
            tmp[gems[++right]]++;
        } else {
            if (best > (right - left + 1)) {
                best = (right - left + 1);
                answer = {left + 1, right + 1};
            }
            tmp[gems[left]]--;
            if (tmp[gems[left]] == 0) tmp.erase(gems[left]);
            left++;
        }
    }
    return answer;
}