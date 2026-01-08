#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

/*
    2 2 6
    1 5 10
    4 2 9
    3 8 3
*/

int solution(vector<vector<int>> data, int col, int row_begin, int row_end) {
    int answer = 0;
    
    sort(data.begin(), data.end(), [&](const auto& a, const auto& b) {
        if (a[col-1] == b[col-1]) return a[0] > b[0];
        return a[col-1] < b[col-1];
    });
    
    for (int i = row_begin; i <= row_end; i++) {
        int value = 0;
        for (auto d : data[i-1]) {
            value += (d % i);
        }
        if (answer == 0) answer = value;
        else answer = answer ^ value;
    }
    
    return answer;
}