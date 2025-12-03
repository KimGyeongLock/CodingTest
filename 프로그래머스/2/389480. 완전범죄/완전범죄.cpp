#include <string>
#include <vector>

using namespace std;

int solution(vector<vector<int>> info, int n, int m) {
    int answer = -1;
    int s = info.size();
    vector<vector<vector<bool>>> dp(s+1, vector<vector<bool>>(n, vector<bool>(m, false)));
    
    dp[0][0][0] = true;
    for (int i = 0; i < s; i++) {
        int addA = info[i][0];
        int addB = info[i][1];
        
        for (int a = 0; a < n; a++) {
            for (int b = 0; b < m; b++) {
                if (!dp[i][a][b]) continue;
                
                int na = a + addA;
                if (na < n) {
                    dp[i + 1][na][b] = true;
                }
                
                int nb = b + addB;
                if (nb < m) {
                    dp[i + 1][a][nb] = true;
                }
            }
        }
    }
    
    for (int a = 0; a < n; a++) {
        for (int b = 0; b < m; b++) {
            if (dp[s][a][b]) {
                answer = a;
                break;
            }
        }
        if (answer != -1) break;
    }
    return answer;
}