#include <string>
#include <vector>

using namespace std;

int solution(int temperature, int t1, int t2, int a, int b, vector<int> onboard) {
    const int OFFSET = 10;
    const int MIN_T = -10;
    const int MAX_T = 40;
    const int TSIZE = MAX_T - MIN_T + 1;
    const int INF = 1e9;
    
    int n = onboard.size();
    vector<vector<int>> dp(n, vector<int>(TSIZE, INF));
    dp[0][temperature - MIN_T] = 0;
    
    for (int i = 0; i < n - 1; i++) {
        for (int curT = MIN_T; curT <= MAX_T; curT++) {
            int curIdx = curT - MIN_T;
            int curCost = dp[i][curIdx];
            if (curCost == INF) continue;
            
            // 에어컨 끌 때
            int nextT = curT;
            if (curT < temperature) nextT++;
            else if (curT > temperature) nextT--;
            
            if (MIN_T <= nextT && nextT <= MAX_T) {
                if (onboard[i+1] == 0 || (t1 <= nextT && nextT <= t2)) {
                    int nextIdx = nextT - MIN_T;
                    dp[i+1][nextIdx] = min(dp[i+1][nextIdx], curCost);
                }
            }
            
            // 에어컨 킬 때
            for (int d = -1; d <= 1; d++) {
                int t2next = curT + d;
                if (t2next < MIN_T || t2next > MAX_T) continue;
                
                if (onboard[i+1] == 1 && !(t1 <= t2next && t2next <= t2)) continue;
                
                int addCost = (d == 0) ? b : a;
                int nextIdx = t2next - MIN_T;
                dp[i+1][nextIdx] = min(dp[i+1][nextIdx], curCost + addCost);
            }
        }
    }
    
    int answer = INF;
    for (int i = MIN_T; i <= MAX_T; i++) {
        answer = min(dp[n-1][i - MIN_T], answer);
    }
    return answer;
}