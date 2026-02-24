#include <string>
#include <vector>

using namespace std;

int bestDiff = 0;
vector<int> best;

bool better(const vector<int>& cand, const vector<int>& cur) {
    for (int i = 10; i >= 0; i--) {
        if (cand[i] != cur[i]) return cand[i] > cur[i];
    }
    return false;
}

void dfs(int idx, int left, vector<int>& info, int diff, vector<int>& res) {
    if (idx == 11) {
        if (diff <= 0) return;

        if (bestDiff < diff) {
            bestDiff = diff;
            best = res;
        } else if (diff == bestDiff) {
            if (better(res, best)) {
                best = res;
            }
        }
        return;
    }
    if (idx == 10) {
        res[idx] = left;
        dfs(11, 0, info, diff, res);
        // res[idx] = 0;
        return;
    }
    
    int score = 10 - idx;
    
    //라이언이 질 경우
    if (info[idx] > 0) dfs(idx+1, left, info, diff - score, res);
    else dfs(idx+1, left, info, diff, res);
    
    //라이언이 이길 경우
    int need = info[idx] + 1;
    if (left >= need) {
        res[idx] = need;
        dfs(idx+1, left - need, info, diff + score, res);
        res[idx] = 0;
    }    
}

vector<int> solution(int n, vector<int> info) {
    vector<int> res(11, 0);
    dfs(0, n, info, 0, res);
    
    if (bestDiff == 0) return {-1};
    return best;
}