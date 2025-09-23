#include <string>
#include <vector>
#include <climits>

using namespace std;

int solution(int alp, int cop, vector<vector<int>> problems) {
    int maxAlp = 0, maxCop = 0;
    for (auto &p : problems) {
        maxAlp = max(maxAlp, p[0]);
        maxCop = max(maxCop, p[1]);
    }
    
    alp = min(alp, maxAlp);
    cop = min(cop, maxCop);
    
    vector<vector<int>> dp(maxAlp + 1, vector<int>(maxCop + 1, INT_MAX));
    dp[alp][cop] = 0;
    
    for (int a = alp; a <= maxAlp; a++) {
        for (int c = cop; c <= maxCop; c++) {
            int cur = dp[a][c];
            if (cur == INT_MAX) continue;
            
            if (a + 1 <= maxAlp) dp[a + 1][c] = min(dp[a + 1][c], cur + 1);
            if (c + 1 <= maxCop) dp[a][c + 1] = min(dp[a][c + 1], cur + 1);
            
            for (auto &p : problems) {
                int reqA = p[0], reqC = p[1], rewardA = p[2], rewardC = p[3], cost = p[4];
                if (a >= reqA && c >= reqC) {
                    int na = min(maxAlp, a + rewardA);
                    int nc = min(maxCop, c + rewardC);
                    dp[na][nc] = min(dp[na][nc], cur + cost);
                }
            }
        }
    }
    
    
    return dp[maxAlp][maxCop];
}