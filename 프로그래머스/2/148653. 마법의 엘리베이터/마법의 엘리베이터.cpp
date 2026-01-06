#include <string>
#include <vector>
#include <climits>

using namespace std;

int answer;

void dfs(const vector<int>& digits, int idx, int carry, int cost) {
    if (cost >= answer) return;
    
    if (idx == digits.size()) {
        answer = min(answer, cost + carry);
        return;
    }
    
    int d = digits[idx] + carry;
    // 내림
    dfs(digits, idx + 1, 0, cost + d);
    // 올림
    dfs(digits, idx + 1, 1, cost + (10 - d));
}

int solution(int storey) {
    vector<int> digits;
    while (storey > 0) {
        digits.push_back(storey % 10);
        storey /= 10;
    }
    answer = INT_MAX;
    dfs(digits, 0, 0, 0);
    return answer;
}