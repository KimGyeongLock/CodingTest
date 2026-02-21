#include <string>
#include <vector>

using namespace std;

int solution(int alp, int cop, vector<vector<int>> problems) {
    int targetAlp = 0, targetCop = 0;
    for (auto p : problems) {
        targetAlp = max(targetAlp, p[0]);    
        targetCop = max(targetCop, p[1]);
    }
    
    const int INF = 1e9;
    vector<vector<int>> dp(targetAlp + 1, vector<int>(targetCop + 1, INF));
    alp = min(alp, targetAlp);
    cop = min(cop, targetCop);
    dp[alp][cop] = 0;
    
    for (int i = alp; i <= targetAlp; i++) {
        for (int j = cop; j <= targetCop; j++) {
            int cur = dp[i][j];
            if (cur == INF) continue;
            
            if (i + 1 <= targetAlp) {
                dp[i + 1][j] = min(dp[i + 1][j], cur + 1);
            }
            
            if (j + 1 <= targetCop) {
                dp[i][j + 1] = min(dp[i][j + 1], cur + 1);
            }
            
            for (auto &p : problems) {
                if (i < p[0] || j < p[1]) continue;
                
                int ni = min(targetAlp, i + p[2]);
                int nj = min(targetCop, j + p[3]);
                
                dp[ni][nj] = min(dp[ni][nj], cur + p[4]);
            }
        }
    }
    return dp[targetAlp][targetCop];
}