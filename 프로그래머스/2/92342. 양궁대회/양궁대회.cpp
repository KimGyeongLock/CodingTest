#include <string>
#include <vector>
#include <climits>

using namespace std;

int N;
vector<int> A;
int bestDiff;
vector<int> bestAns;

void updateBest(int score, vector<int>& cur) {
    if (score > bestDiff) {
        bestDiff = score;
        bestAns = cur;
    } else if (score == bestDiff) {
        for (int i = 10; i >= 0; i--) {
            if (cur[i] != bestAns[i]) {
                if (cur[i] > bestAns[i]) {
                    bestAns = cur;
                }
                break;
            }
        }
    }
}

void dfs(int idx, int arrowsLeft, int score, vector<int>& cur) {
    if (idx == 10) {
        cur[idx] = arrowsLeft;
        updateBest(score, cur);
        return;
    }
    
    int need = A[idx] + 1;
    if (arrowsLeft >= need) {
        cur[idx] = need;
        dfs(idx + 1, arrowsLeft - need, score + 10 - idx, cur);
        cur[idx] = 0;
    }
    
    int delta = (A[idx] > 0) ? 10 - idx : 0;
    dfs(idx + 1, arrowsLeft, score - delta, cur);
}

vector<int> solution(int n, vector<int> info) {
    N = n;
    A = info;
    bestDiff = INT_MIN;
    
    bestAns.assign(11, 0);
    vector<int> cur(11, 0);
    dfs(0, N, 0, cur);
    
    if (bestDiff <= 0) return {-1};
    return bestAns;
}