#include <string>
#include <vector>
#include <climits>

using namespace std;

int n, answer = INT_MAX;

void dfs(int stage, vector<int> havHint, int total, const vector<vector<int>> cost, const vector<vector<int>> hint) {
    if (stage == n) {
        answer = min(answer, total);
        return;
    }
    
    // 힌트를 사지 않는 경우
    dfs(stage + 1, havHint, total + cost[stage][min(havHint[stage], n - 1)], cost, hint);
        
    // 힌트를 사는 경우
    if (stage < n - 1) {
        for (int i = 1; i < hint[stage].size(); i++) {
            havHint[hint[stage][i] - 1]++;
        }
        dfs(stage + 1, havHint, total + cost[stage][min(havHint[stage], n - 1)] + hint[stage][0], cost, hint);
    }
}

int solution(vector<vector<int>> cost, vector<vector<int>> hint) {
    n = cost.size();
    vector<int> havHint(n, 0);
    dfs(0, havHint, 0, cost, hint);
    return answer;
}