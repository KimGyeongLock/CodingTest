#include <string>
#include <vector>
#include <iostream>

using namespace std;

vector<int> solution(int n, long long left, long long right) {
    vector<int> answer;
    
    for (long long k = left; k <= right; k++) {
        int r = k / n + 1;
        int c = k % n + 1;
        answer.push_back(max(r, c));
    }
    
    return answer;
}