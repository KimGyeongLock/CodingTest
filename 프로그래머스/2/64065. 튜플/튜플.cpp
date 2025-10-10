#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

vector<int> solution(string s) {
    vector<int> vec[501];
    int num = 0;
    vector<int> tmp;
    for (char c : s) {
        if (c == ',' || c == '}') {
            if(num != 0) tmp.push_back(num); 
            num = 0;
        } else if (c >= '0' && c <= '9') {
            num = num * 10 + (c - '0');
        } else if (c == '{') {
            if (!tmp.empty()) {
                vec[tmp.size()] = tmp;
                tmp.clear();
            }
        }
    }
    if (!tmp.empty()) vec[tmp.size()] = tmp;
    
    vector<int> answer;
    for (int i = 0; i < 501; i++) {
        if (!vec[i].empty()) {
            for (int i : vec[i]) {
                if (find(answer.begin(), answer.end(), i) == answer.end()) {
                    answer.push_back(i);
                }
            }
        }
    }

    return answer;
}